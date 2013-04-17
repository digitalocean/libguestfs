/* libguestfs
 * Copyright (C) 2009-2013 Red Hat Inc.
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
 */

#include <config.h>

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <stdbool.h>
#include <unistd.h>
#include <fcntl.h>
#include <limits.h>
#include <grp.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <assert.h>

#ifdef HAVE_LIBVIRT
#include <libvirt/libvirt.h>
#include <libvirt/virterror.h>
#endif

#ifdef HAVE_LIBXML2
#include <libxml/xmlIO.h>
#include <libxml/xmlwriter.h>
#include <libxml/xpath.h>
#include <libxml/parser.h>
#include <libxml/tree.h>
#include <libxml/xmlsave.h>
#endif

#if HAVE_LIBSELINUX
#include <selinux/selinux.h>
#include <selinux/context.h>
#endif

#include "glthread/lock.h"

#include "guestfs.h"
#include "guestfs-internal.h"
#include "guestfs-internal-actions.h"
#include "guestfs_protocol.h"

/* Check minimum required version of libvirt.  The libvirt backend
 * is new and not the default, so we can get away with forcing
 * people who want to try it to have a reasonably new version of
 * libvirt, so we don't have to work around any bugs in libvirt.
 *
 * This is also checked at runtime because you can dynamically link
 * with a different version from what you were compiled with.
 */
#define MIN_LIBVIRT_MAJOR 0
#define MIN_LIBVIRT_MINOR 10
#define MIN_LIBVIRT_MICRO 2 /* XXX patches in > 2 already */
#define MIN_LIBVIRT_VERSION (MIN_LIBVIRT_MAJOR * 1000000 + \
                             MIN_LIBVIRT_MINOR * 1000 + \
                             MIN_LIBVIRT_MICRO)

#if defined(HAVE_LIBVIRT) && \
  LIBVIR_VERSION_NUMBER >= MIN_LIBVIRT_VERSION && \
  defined(HAVE_LIBXML2)

#ifndef HAVE_XMLBUFFERDETACH
/* Added in libxml2 2.8.0.  This is mostly a copy of the function from
 * upstream libxml2, which is under a more permissive license.
 */
static xmlChar *
xmlBufferDetach (xmlBufferPtr buf)
{
  xmlChar *ret;

  if (buf == NULL)
    return NULL;
  if (buf->alloc == XML_BUFFER_ALLOC_IMMUTABLE)
    return NULL;

  ret = buf->content;
  buf->content = NULL;
  buf->size = 0;
  buf->use = 0;

  return ret;
}
#endif

/* Pointed to by 'struct drive *' -> priv field. */
struct drive_libvirt {
  /* The drive that we actually add.  If using an overlay, then this
   * might be different from drive->src.  Call it 'real_src' so we
   * don't confuse accesses to this with accesses to 'drive->src'.
   */
  struct drive_source real_src;

  /* The format of the drive we add. */
  char *format;
};

/* Parameters passed to construct_libvirt_xml and subfunctions.  We
 * keep them all in a structure for convenience!
 */
struct libvirt_xml_params {
  char *kernel;                 /* paths to kernel and initrd */
  char *initrd;
  char *appliance_overlay;      /* path to qcow2 overlay backed by appliance */
  char appliance_dev[64];       /* appliance device name */
  size_t appliance_index;       /* index of appliance */
  char guestfsd_path[UNIX_PATH_MAX]; /* paths to sockets */
  char console_path[UNIX_PATH_MAX];
  bool enable_svirt;            /* false if we decided to disable sVirt */
  bool is_kvm;                  /* false = qemu, true = kvm */
  bool current_proc_is_root;    /* true = euid is root */
};

static int parse_capabilities (guestfs_h *g, const char *capabilities_xml, struct libvirt_xml_params *params);
static xmlChar *construct_libvirt_xml (guestfs_h *g, const struct libvirt_xml_params *params);
static void debug_appliance_permissions (guestfs_h *g);
static void debug_socket_permissions (guestfs_h *g);
static void libvirt_error (guestfs_h *g, const char *fs, ...) __attribute__((format (printf,2,3)));
static int is_custom_qemu (guestfs_h *g);
static int is_blk (const char *path);
static int random_chars (char *ret, size_t len);
static void ignore_errors (void *ignore, virErrorPtr ignore2);
static char *make_qcow2_overlay (guestfs_h *g, const char *backing_device, const char *format, const char *selinux_imagelabel);
static int make_drive_priv (guestfs_h *g, struct drive *drv, const char *selinux_imagelabel);
static void drive_free_priv (void *);
static void set_socket_create_context (guestfs_h *g);
static void clear_socket_create_context (guestfs_h *g);
static void selinux_warning (guestfs_h *g, const char *func, const char *selinux_op, const char *data);

static int
launch_libvirt (guestfs_h *g, const char *libvirt_uri)
{
  int daemon_accept_sock = -1, console_sock = -1;
  unsigned long version;
  virConnectPtr conn = NULL;
  virDomainPtr dom = NULL;
  CLEANUP_FREE char *capabilities_xml = NULL;
  struct libvirt_xml_params params = {
    .kernel = NULL,
    .initrd = NULL,
    .appliance_overlay = NULL,
  };
  CLEANUP_FREE xmlChar *xml = NULL;
  CLEANUP_FREE char *appliance = NULL;
  struct sockaddr_un addr;
  int r;
  uint32_t size;
  CLEANUP_FREE void *buf = NULL;
  struct drive *drv;
  size_t i;

  params.current_proc_is_root = geteuid () == 0;

  /* XXX: It should be possible to make this work. */
  if (g->direct_mode) {
    error (g, _("direct mode flag is not supported yet for libvirt backend"));
    return -1;
  }

  virGetVersion (&version, NULL, NULL);
  debug (g, "libvirt version = %lu (%lu.%lu.%lu)",
         version,
         version / 1000000UL, version / 1000UL % 1000UL, version % 1000UL);
  if (version < MIN_LIBVIRT_VERSION) {
    error (g, _("you must have libvirt >= %d.%d.%d "
                "to use the 'libvirt' backend"),
           MIN_LIBVIRT_MAJOR, MIN_LIBVIRT_MINOR, MIN_LIBVIRT_MICRO);
    return -1;
  }

  guestfs___launch_send_progress (g, 0);
  TRACE0 (launch_libvirt_start);

  if (g->verbose)
    guestfs___print_timestamped_message (g, "connect to libvirt");

  /* Connect to libvirt, get capabilities. */
  conn = guestfs___open_libvirt_connection (g, libvirt_uri, 0);
  if (!conn) {
    libvirt_error (g, _("could not connect to libvirt (URI = %s)"),
           libvirt_uri ? : "NULL");
    goto cleanup;
  }

  /* Suppress default behaviour of printing errors to stderr.  Note
   * you can't set this to NULL to ignore errors; setting it to NULL
   * restores the default error handler ...
   */
  virConnSetErrorFunc (conn, NULL, ignore_errors);

  if (g->verbose)
    guestfs___print_timestamped_message (g, "get libvirt capabilities");

  capabilities_xml = virConnectGetCapabilities (conn);
  if (!capabilities_xml) {
    libvirt_error (g, _("could not get libvirt capabilities"));
    goto cleanup;
  }

  /* Parse capabilities XML.  This fills in various fields in 'params'
   * struct, and can also fail if we detect that the hypervisor cannot
   * run qemu guests (RHBZ#886915).
   */
  if (g->verbose)
    guestfs___print_timestamped_message (g, "parsing capabilities XML");

  if (parse_capabilities (g, capabilities_xml, &params) == -1)
    goto cleanup;

  /* Locate and/or build the appliance. */
  TRACE0 (launch_build_libvirt_appliance_start);

  if (g->verbose)
    guestfs___print_timestamped_message (g, "build appliance");

  if (guestfs___build_appliance (g, &params.kernel, &params.initrd,
                                 &appliance) == -1)
    goto cleanup;

  guestfs___launch_send_progress (g, 3);
  TRACE0 (launch_build_libvirt_appliance_end);

  /* Note that appliance can be NULL if using the old-style appliance. */
  if (appliance) {
    params.appliance_overlay = make_qcow2_overlay (g, appliance, "raw", NULL);
    if (!params.appliance_overlay)
      goto cleanup;
  }

  /* Set up the drv->priv part of the struct.  A side-effect of this
   * may be that we create qcow2 overlays for drives.
   */
  ITER_DRIVES (g, i, drv) {
    if (make_drive_priv (g, drv, g->virt_selinux_imagelabel) == -1)
      goto cleanup;
  }

  TRACE0 (launch_build_libvirt_qcow2_overlay_end);

  /* Using virtio-serial, we need to create a local Unix domain socket
   * for qemu to connect to.
   */
  snprintf (params.guestfsd_path, sizeof params.guestfsd_path,
            "%s/guestfsd.sock", g->tmpdir);
  unlink (params.guestfsd_path);

  set_socket_create_context (g);

  daemon_accept_sock = socket (AF_UNIX, SOCK_STREAM|SOCK_CLOEXEC, 0);
  if (daemon_accept_sock == -1) {
    perrorf (g, "socket");
    goto cleanup;
  }

  addr.sun_family = AF_UNIX;
  memcpy (addr.sun_path, params.guestfsd_path, UNIX_PATH_MAX);

  if (bind (daemon_accept_sock, &addr, sizeof addr) == -1) {
    perrorf (g, "bind");
    goto cleanup;
  }

  if (listen (daemon_accept_sock, 1) == -1) {
    perrorf (g, "listen");
    goto cleanup;
  }

  /* For the serial console. */
  snprintf (params.console_path, sizeof params.console_path,
            "%s/console.sock", g->tmpdir);
  unlink (params.console_path);

  console_sock = socket (AF_UNIX, SOCK_STREAM|SOCK_CLOEXEC, 0);
  if (console_sock == -1) {
    perrorf (g, "socket");
    goto cleanup;
  }

  addr.sun_family = AF_UNIX;
  memcpy (addr.sun_path, params.console_path, UNIX_PATH_MAX);

  if (bind (console_sock, &addr, sizeof addr) == -1) {
    perrorf (g, "bind");
    goto cleanup;
  }

  if (listen (console_sock, 1) == -1) {
    perrorf (g, "listen");
    goto cleanup;
  }

  clear_socket_create_context (g);

  /* libvirt, if running as root, will run the qemu process as
   * qemu.qemu, which means it won't be able to access the socket.
   * There are roughly three things that get in the way:
   *
   * (1) Permissions of the socket.
   *
   * (2) Permissions of the parent directory(-ies).  Remember this if
   *     $TMPDIR is located in your home directory.
   *
   * (3) SELinux/sVirt will prevent access.  libvirt ought to label
   *     the socket.
   *
   * Note that the 'current_proc_is_root' flag here just means that we
   * are root.  It's also possible for non-root user to try to use the
   * system libvirtd by specifying a qemu:///system URI (RHBZ#913774)
   * but there's no sane way to test for that.
   */
  if (params.current_proc_is_root) {
    /* Current process is root, so try to create sockets that are
     * owned by root.qemu with mode 0660 and hence accessible to qemu.
     */
    struct group *grp;

    if (chmod (params.guestfsd_path, 0660) == -1) {
      perrorf (g, "chmod: %s", params.guestfsd_path);
      goto cleanup;
    }

    if (chmod (params.console_path, 0660) == -1) {
      perrorf (g, "chmod: %s", params.console_path);
      goto cleanup;
    }

    grp = getgrnam ("qemu");
    if (grp != NULL) {
      if (chown (params.guestfsd_path, 0, grp->gr_gid) == -1) {
        perrorf (g, "chown: %s", params.guestfsd_path);
        goto cleanup;
      }
      if (chown (params.console_path, 0, grp->gr_gid) == -1) {
        perrorf (g, "chown: %s", params.console_path);
        goto cleanup;
      }
    } else
      debug (g, "cannot find group 'qemu'");
  }

  /* Construct the libvirt XML. */
  if (g->verbose)
    guestfs___print_timestamped_message (g, "create libvirt XML");

  params.appliance_index = g->nr_drives;
  strcpy (params.appliance_dev, "/dev/sd");
  guestfs___drive_name (params.appliance_index, &params.appliance_dev[7]);
  params.enable_svirt = ! is_custom_qemu (g);

  xml = construct_libvirt_xml (g, &params);
  if (!xml)
    goto cleanup;

  /* Debug permissions and SELinux contexts on appliance and sockets. */
  if (g->verbose) {
    debug_appliance_permissions (g);
    debug_socket_permissions (g);
  }

  /* Launch the libvirt guest. */
  if (g->verbose)
    guestfs___print_timestamped_message (g, "launch libvirt guest");

  dom = virDomainCreateXML (conn, (char *) xml, VIR_DOMAIN_START_AUTODESTROY);
  if (!dom) {
    libvirt_error (g, _("could not create appliance through libvirt"));
    goto cleanup;
  }

  g->state = LAUNCHING;

  /* Wait for console socket to open. */
  r = accept4 (console_sock, NULL, NULL, SOCK_NONBLOCK|SOCK_CLOEXEC);
  if (r == -1) {
    perrorf (g, "accept");
    goto cleanup;
  }
  if (close (console_sock) == -1) {
    perrorf (g, "close: console socket");
    console_sock = -1;
    close (r);
    goto cleanup;
  }
  console_sock = r;         /* This is the accepted console socket. */

  /* Wait for libvirt domain to start and to connect back to us via
   * virtio-serial and send the GUESTFS_LAUNCH_FLAG message.
   */
  g->conn =
    guestfs___new_conn_socket_listening (g, daemon_accept_sock, console_sock);
  if (!g->conn)
    goto cleanup;

  /* g->conn now owns these sockets. */
  daemon_accept_sock = console_sock = -1;

  r = g->conn->ops->accept_connection (g, g->conn);
  if (r == -1)
    goto cleanup;
  if (r == 0) {
    guestfs___launch_failed_error (g);
    goto cleanup;
  }

  /* NB: We reach here just because qemu has opened the socket.  It
   * does not mean the daemon is up until we read the
   * GUESTFS_LAUNCH_FLAG below.  Failures in qemu startup can still
   * happen even if we reach here, even early failures like not being
   * able to open a drive.
   */

  r = guestfs___recv_from_daemon (g, &size, &buf);

  if (r == -1) {
    guestfs___launch_failed_error (g);
    goto cleanup;
  }

  if (size != GUESTFS_LAUNCH_FLAG) {
    guestfs___launch_failed_error (g);
    goto cleanup;
  }

  if (g->verbose)
    guestfs___print_timestamped_message (g, "appliance is up");

  /* This is possible in some really strange situations, such as
   * guestfsd starts up OK but then qemu immediately exits.  Check for
   * it because the caller is probably expecting to be able to send
   * commands after this function returns.
   */
  if (g->state != READY) {
    error (g, _("qemu launched and contacted daemon, but state != READY"));
    goto cleanup;
  }

  if (appliance)
    guestfs___add_dummy_appliance_drive (g);

  TRACE0 (launch_libvirt_end);

  guestfs___launch_send_progress (g, 12);

  g->virt.conn = conn;
  g->virt.dom = dom;

  free (params.kernel);
  free (params.initrd);
  free (params.appliance_overlay);

  return 0;

 cleanup:
  clear_socket_create_context (g);

  if (console_sock >= 0)
    close (console_sock);
  if (daemon_accept_sock >= 0)
    close (daemon_accept_sock);
  if (g->conn) {
    g->conn->ops->free_connection (g, g->conn);
    g->conn = NULL;
  }

  if (dom) {
    virDomainDestroy (dom);
    virDomainFree (dom);
  }
  if (conn)
    virConnectClose (conn);

  free (params.kernel);
  free (params.initrd);
  free (params.appliance_overlay);

  g->state = CONFIG;

  return -1;
}

static int
parse_capabilities (guestfs_h *g, const char *capabilities_xml,
                    struct libvirt_xml_params *params)
{
  CLEANUP_XMLFREEDOC xmlDocPtr doc = NULL;
  CLEANUP_XMLXPATHFREECONTEXT xmlXPathContextPtr xpathCtx = NULL;
  CLEANUP_XMLXPATHFREEOBJECT xmlXPathObjectPtr xpathObj = NULL;
  size_t i;
  xmlNodeSetPtr nodes;
  xmlAttrPtr attr;
  size_t seen_qemu, seen_kvm;

  doc = xmlParseMemory (capabilities_xml, strlen (capabilities_xml));
  if (doc == NULL) {
    error (g, _("unable to parse capabilities XML returned by libvirt"));
    return -1;
  }

  xpathCtx = xmlXPathNewContext (doc);
  if (xpathCtx == NULL) {
    error (g, _("unable to create new XPath context"));
    return -1;
  }

  /* This gives us a set of all the supported domain types.
   * XXX It ignores architecture, but let's not worry about that.
   */
#define XPATH_EXPR "/capabilities/guest/arch/domain/@type"
  xpathObj = xmlXPathEvalExpression (BAD_CAST XPATH_EXPR, xpathCtx);
  if (xpathObj == NULL) {
    error (g, _("unable to evaluate XPath expression: %s"), XPATH_EXPR);
    return -1;
  }
#undef XPATH_EXPR

  nodes = xpathObj->nodesetval;
  seen_qemu = seen_kvm = 0;

  if (nodes != NULL) {
    for (i = 0; i < (size_t) nodes->nodeNr; ++i) {
      CLEANUP_FREE char *type = NULL;

      if (seen_qemu && seen_kvm)
        break;

      assert (nodes->nodeTab[i]);
      assert (nodes->nodeTab[i]->type == XML_ATTRIBUTE_NODE);
      attr = (xmlAttrPtr) nodes->nodeTab[i];
      type = (char *) xmlNodeListGetString (doc, attr->children, 1);

      if (STREQ (type, "qemu"))
        seen_qemu++;
      else if (STREQ (type, "kvm"))
        seen_kvm++;
    }
  }

  /* This was RHBZ#886915: in that case the default libvirt URI
   * pointed to a Xen hypervisor, and so could not create the
   * appliance VM.
   */
  if (!seen_qemu && !seen_kvm) {
    error (g,
           _("libvirt hypervisor doesn't support qemu or KVM,\n"
             "so we cannot create the libguestfs appliance.\n"
             "The current backend is '%s'.\n"
             "Check that the PATH environment variable is set and contains\n"
             "the path to the qemu ('qemu-system-*') or KVM ('qemu-kvm', 'kvm' etc).\n"
             "Or: try setting:\n"
             "  export LIBGUESTFS_BACKEND=libvirt:qemu:///session\n"
             "Or: if you want to have libguestfs run qemu directly, try:\n"
             "  export LIBGUESTFS_BACKEND=direct\n"
             "For further help, read the guestfs(3) man page and libguestfs FAQ."),
           guestfs__get_backend (g));
    return -1;
  }

  params->is_kvm = seen_kvm;
  return 0;
}

static int
is_custom_qemu (guestfs_h *g)
{
  return g->qemu && STRNEQ (g->qemu, QEMU);
}

#if HAVE_LIBSELINUX

/* Set sVirt (SELinux) socket create context.  For details see:
 * https://bugzilla.redhat.com/show_bug.cgi?id=853393#c14
 */

#define SOCKET_CONTEXT "svirt_socket_t"

static void
set_socket_create_context (guestfs_h *g)
{
  security_context_t scon; /* this is actually a 'char *' */
  context_t con;

  if (getcon (&scon) == -1) {
    selinux_warning (g, __func__, "getcon", NULL);
    return;
  }

  con = context_new (scon);
  if (!con) {
    selinux_warning (g, __func__, "context_new", scon);
    goto out1;
  }

  if (context_type_set (con, SOCKET_CONTEXT) == -1) {
    selinux_warning (g, __func__, "context_type_set", scon);
    goto out2;
  }

  /* Note that setsockcreatecon sets the per-thread socket creation
   * context (/proc/self/task/<tid>/attr/sockcreate) so this is
   * thread-safe.
   */
  if (setsockcreatecon (context_str (con)) == -1) {
    selinux_warning (g, __func__, "setsockcreatecon", context_str (con));
    goto out2;
  }

 out2:
  context_free (con);
 out1:
  freecon (scon);
}

static void
clear_socket_create_context (guestfs_h *g)
{
  if (setsockcreatecon (NULL) == -1)
    selinux_warning (g, __func__, "setsockcreatecon", "NULL");
}

#else /* !HAVE_LIBSELINUX */

static void
set_socket_create_context (guestfs_h *g)
{
  /* nothing */
}

static void
clear_socket_create_context (guestfs_h *g)
{
  /* nothing */
}

#endif /* !HAVE_LIBSELINUX */

static void
debug_permissions_cb (guestfs_h *g, void *data, const char *line, size_t len)
{
  debug (g, "%s", line);
}

static void
debug_appliance_permissions (guestfs_h *g)
{
  CLEANUP_CMD_CLOSE struct command *cmd = guestfs___new_command (g);
  CLEANUP_FREE char *cachedir = guestfs_get_cachedir (g);
  CLEANUP_FREE char *appliance = NULL;

  appliance = safe_asprintf (g, "%s/.guestfs-%d", cachedir, geteuid ());

  guestfs___cmd_add_arg (cmd, "ls");
  guestfs___cmd_add_arg (cmd, "-a");
  guestfs___cmd_add_arg (cmd, "-l");
  guestfs___cmd_add_arg (cmd, "-Z");
  guestfs___cmd_add_arg (cmd, appliance);
  guestfs___cmd_set_stdout_callback (cmd, debug_permissions_cb, NULL, 0);
  guestfs___cmd_run (cmd);
}

static void
debug_socket_permissions (guestfs_h *g)
{
  if (g->tmpdir) {
    CLEANUP_CMD_CLOSE struct command *cmd = guestfs___new_command (g);

    guestfs___cmd_add_arg (cmd, "ls");
    guestfs___cmd_add_arg (cmd, "-a");
    guestfs___cmd_add_arg (cmd, "-l");
    guestfs___cmd_add_arg (cmd, "-Z");
    guestfs___cmd_add_arg (cmd, g->tmpdir);
    guestfs___cmd_set_stdout_callback (cmd, debug_permissions_cb, NULL, 0);
    guestfs___cmd_run (cmd);
  }
}

static int construct_libvirt_xml_domain (guestfs_h *g, const struct libvirt_xml_params *params, xmlTextWriterPtr xo);
static int construct_libvirt_xml_name (guestfs_h *g, const struct libvirt_xml_params *params, xmlTextWriterPtr xo);
static int construct_libvirt_xml_cpu (guestfs_h *g, const struct libvirt_xml_params *params, xmlTextWriterPtr xo);
static int construct_libvirt_xml_boot (guestfs_h *g, const struct libvirt_xml_params *params, xmlTextWriterPtr xo);
static int construct_libvirt_xml_seclabel (guestfs_h *g, const struct libvirt_xml_params *params, xmlTextWriterPtr xo);
static int construct_libvirt_xml_lifecycle (guestfs_h *g, const struct libvirt_xml_params *params, xmlTextWriterPtr xo);
static int construct_libvirt_xml_devices (guestfs_h *g, const struct libvirt_xml_params *params, xmlTextWriterPtr xo);
static int construct_libvirt_xml_qemu_cmdline (guestfs_h *g, const struct libvirt_xml_params *params, xmlTextWriterPtr xo);
static int construct_libvirt_xml_disk (guestfs_h *g, xmlTextWriterPtr xo, struct drive *drv, size_t drv_index);
static int construct_libvirt_xml_disk_source_hosts (guestfs_h *g, xmlTextWriterPtr xo, const struct drive_source *src);
static int construct_libvirt_xml_disk_source_seclabel (guestfs_h *g, xmlTextWriterPtr xo);
static int construct_libvirt_xml_appliance (guestfs_h *g, const struct libvirt_xml_params *params, xmlTextWriterPtr xo);

/* Note this macro is rather specialized: It assumes that any local
 * variables are protected by CLEANUP_* macros, so that simply
 * returning will not cause any memory leaks.
 */
#define XMLERROR_RET(code,e,ret) do {                                   \
    if ((e) == (code)) {                                                \
      perrorf (g, _("error constructing libvirt XML at \"%s\""),        \
               #e);                                                     \
      return (ret);                                                     \
    }                                                                   \
  } while (0)

#define XMLERROR(code,e) XMLERROR_RET((code),(e),-1)

static xmlChar *
construct_libvirt_xml (guestfs_h *g, const struct libvirt_xml_params *params)
{
  xmlChar *ret = NULL;
  CLEANUP_XMLBUFFERFREE xmlBufferPtr xb = NULL;
  xmlOutputBufferPtr ob;
  CLEANUP_XMLFREETEXTWRITER xmlTextWriterPtr xo = NULL;

  XMLERROR_RET (NULL, xb = xmlBufferCreate (), NULL);
  XMLERROR_RET (NULL, ob = xmlOutputBufferCreateBuffer (xb, NULL), NULL);
  XMLERROR_RET (NULL, xo = xmlNewTextWriter (ob), NULL);

  if (construct_libvirt_xml_domain (g, params, xo) == -1)
    return NULL;

  XMLERROR_RET (-1, xmlTextWriterEndDocument (xo), NULL);
  XMLERROR_RET (NULL, ret = xmlBufferDetach (xb), NULL); /* caller frees ret */

  debug (g, "libvirt XML:\n%s", ret);

  return ret;
}

static int
construct_libvirt_xml_domain (guestfs_h *g,
                              const struct libvirt_xml_params *params,
                              xmlTextWriterPtr xo)
{
  XMLERROR (-1, xmlTextWriterSetIndent (xo, 1));
  XMLERROR (-1, xmlTextWriterSetIndentString (xo, BAD_CAST "  "));
  XMLERROR (-1, xmlTextWriterStartDocument (xo, NULL, NULL, NULL));

  XMLERROR (-1, xmlTextWriterStartElement (xo, BAD_CAST "domain"));
  XMLERROR (-1,
            xmlTextWriterWriteAttribute (xo, BAD_CAST "type",
                         params->is_kvm ? BAD_CAST "kvm" : BAD_CAST "qemu"));
  XMLERROR (-1,
            xmlTextWriterWriteAttributeNS (xo,
                                           BAD_CAST "xmlns",
                                           BAD_CAST "qemu",
                                           NULL,
                                           BAD_CAST "http://libvirt.org/schemas/domain/qemu/1.0"));

  if (construct_libvirt_xml_name (g, params, xo) == -1)
    return -1;
  if (construct_libvirt_xml_cpu (g, params, xo) == -1)
    return -1;
  if (construct_libvirt_xml_boot (g, params, xo) == -1)
    return -1;
  if (construct_libvirt_xml_seclabel (g, params, xo) == -1)
    return -1;
  if (construct_libvirt_xml_lifecycle (g, params, xo) == -1)
    return -1;
  if (construct_libvirt_xml_devices (g, params, xo) == -1)
    return -1;
  if (construct_libvirt_xml_qemu_cmdline (g, params, xo) == -1)
    return -1;

  XMLERROR (-1, xmlTextWriterEndElement (xo));

  return 0;
}

/* Construct a securely random name.  We don't need to save the name
 * because if we ever needed it, it's available from libvirt.
 */
#define DOMAIN_NAME_LEN 16

static int
construct_libvirt_xml_name (guestfs_h *g,
                            const struct libvirt_xml_params *params,
                            xmlTextWriterPtr xo)
{
  char name[DOMAIN_NAME_LEN+1];

  if (random_chars (name, DOMAIN_NAME_LEN) == -1) {
    perrorf (g, "/dev/urandom");
    return -1;
  }

  XMLERROR (-1, xmlTextWriterStartElement (xo, BAD_CAST "name"));
  XMLERROR (-1, xmlTextWriterWriteFormatString (xo, "guestfs-%s", name));
  XMLERROR (-1, xmlTextWriterEndElement (xo));

  return 0;
}

/* CPU and memory features. */
static int
construct_libvirt_xml_cpu (guestfs_h *g,
                           const struct libvirt_xml_params *params,
                           xmlTextWriterPtr xo)
{
  XMLERROR (-1, xmlTextWriterStartElement (xo, BAD_CAST "memory"));
  XMLERROR (-1,
            xmlTextWriterWriteAttribute (xo, BAD_CAST "unit", BAD_CAST "MiB"));
  XMLERROR (-1, xmlTextWriterWriteFormatString (xo, "%d", g->memsize));
  XMLERROR (-1, xmlTextWriterEndElement (xo));

  XMLERROR (-1, xmlTextWriterStartElement (xo, BAD_CAST "currentMemory"));
  XMLERROR (-1,
            xmlTextWriterWriteAttribute (xo, BAD_CAST "unit", BAD_CAST "MiB"));
  XMLERROR (-1, xmlTextWriterWriteFormatString (xo, "%d", g->memsize));
  XMLERROR (-1, xmlTextWriterEndElement (xo));

  /* It would be faster to pass the CPU host model to the appliance,
   * allowing maximum speed for things like checksums, encryption.
   * However this doesn't work because KVM doesn't emulate all of the
   * required guest insns (RHBZ#870071).  This is why the following
   * section is commented out.
   */
#if 0
  XMLERROR (-1, xmlTextWriterStartElement (xo, BAD_CAST "cpu"));
  XMLERROR (-1,
            xmlTextWriterWriteAttribute (xo, BAD_CAST "mode",
                                         BAD_CAST "host-model"));
  XMLERROR (-1, xmlTextWriterStartElement (xo, BAD_CAST "model"));
  XMLERROR (-1,
            xmlTextWriterWriteAttribute (xo, BAD_CAST "fallback",
                                         BAD_CAST "allow"));
  XMLERROR (-1, xmlTextWriterEndElement (xo));
  XMLERROR (-1, xmlTextWriterEndElement (xo));
#endif

  XMLERROR (-1, xmlTextWriterStartElement (xo, BAD_CAST "vcpu"));
  XMLERROR (-1, xmlTextWriterWriteFormatString (xo, "%d", g->smp));
  XMLERROR (-1, xmlTextWriterEndElement (xo));

  XMLERROR (-1, xmlTextWriterStartElement (xo, BAD_CAST "clock"));
  XMLERROR (-1,
            xmlTextWriterWriteAttribute (xo, BAD_CAST "offset",
                                         BAD_CAST "utc"));
  XMLERROR (-1, xmlTextWriterEndElement (xo));

  return 0;
}

/* Boot parameters. */
static int
construct_libvirt_xml_boot (guestfs_h *g,
                            const struct libvirt_xml_params *params,
                            xmlTextWriterPtr xo)
{
  CLEANUP_FREE char *cmdline = NULL;
  int flags;

  /* Linux kernel command line. */
  flags = 0;
  if (!params->is_kvm)
    flags |= APPLIANCE_COMMAND_LINE_IS_TCG;
  cmdline = guestfs___appliance_command_line (g, params->appliance_dev, flags);

  XMLERROR (-1, xmlTextWriterStartElement (xo, BAD_CAST "os"));

  XMLERROR (-1, xmlTextWriterStartElement (xo, BAD_CAST "type"));
  XMLERROR (-1, xmlTextWriterWriteString (xo, BAD_CAST "hvm"));
  XMLERROR (-1, xmlTextWriterEndElement (xo));

  XMLERROR (-1, xmlTextWriterStartElement (xo, BAD_CAST "kernel"));
  XMLERROR (-1, xmlTextWriterWriteString (xo, BAD_CAST params->kernel));
  XMLERROR (-1, xmlTextWriterEndElement (xo));

  XMLERROR (-1, xmlTextWriterStartElement (xo, BAD_CAST "initrd"));
  XMLERROR (-1, xmlTextWriterWriteString (xo, BAD_CAST params->initrd));
  XMLERROR (-1, xmlTextWriterEndElement (xo));

  XMLERROR (-1, xmlTextWriterStartElement (xo, BAD_CAST "cmdline"));
  XMLERROR (-1, xmlTextWriterWriteString (xo, BAD_CAST cmdline));
  XMLERROR (-1, xmlTextWriterEndElement (xo));

  XMLERROR (-1, xmlTextWriterEndElement (xo));

  return 0;
}

static int
construct_libvirt_xml_seclabel (guestfs_h *g,
                                const struct libvirt_xml_params *params,
                                xmlTextWriterPtr xo)
{
  if (!params->enable_svirt) {
    /* This disables SELinux/sVirt confinement. */
    XMLERROR (-1, xmlTextWriterStartElement (xo, BAD_CAST "seclabel"));
    XMLERROR (-1,
              xmlTextWriterWriteAttribute (xo, BAD_CAST "type",
                                           BAD_CAST "none"));
    XMLERROR (-1, xmlTextWriterEndElement (xo));
  }
  else if (g->virt_selinux_label && g->virt_selinux_imagelabel) {
    /* Enable sVirt and pass a custom <seclabel/> inherited from the
     * original libvirt domain (when guestfs_add_domain was called).
     * https://bugzilla.redhat.com/show_bug.cgi?id=912499#c7
     */
    XMLERROR (-1, xmlTextWriterStartElement (xo, BAD_CAST "seclabel"));
    XMLERROR (-1,
              xmlTextWriterWriteAttribute (xo, BAD_CAST "type",
                                           BAD_CAST "static"));
    XMLERROR (-1,
              xmlTextWriterWriteAttribute (xo, BAD_CAST "model",
                                           BAD_CAST "selinux"));
    XMLERROR (-1,
              xmlTextWriterWriteAttribute (xo, BAD_CAST "relabel",
                                           BAD_CAST "yes"));
    XMLERROR (-1, xmlTextWriterStartElement (xo, BAD_CAST "label"));
    XMLERROR (-1, xmlTextWriterWriteString (xo,
                                            BAD_CAST g->virt_selinux_label));
    XMLERROR (-1, xmlTextWriterEndElement (xo));
    XMLERROR (-1, xmlTextWriterStartElement (xo, BAD_CAST "imagelabel"));
    XMLERROR (-1, xmlTextWriterWriteString (xo,
                                            BAD_CAST g->virt_selinux_imagelabel));
    XMLERROR (-1, xmlTextWriterEndElement (xo));
    XMLERROR (-1, xmlTextWriterEndElement (xo));
  }

  return 0;
}

/* qemu -no-reboot */
static int
construct_libvirt_xml_lifecycle (guestfs_h *g,
                                 const struct libvirt_xml_params *params,
                                 xmlTextWriterPtr xo)
{
  XMLERROR (-1, xmlTextWriterStartElement (xo, BAD_CAST "on_reboot"));
  XMLERROR (-1, xmlTextWriterWriteString (xo, BAD_CAST "destroy"));
  XMLERROR (-1, xmlTextWriterEndElement (xo));

  return 0;
}

/* Devices. */
static int
construct_libvirt_xml_devices (guestfs_h *g,
                               const struct libvirt_xml_params *params,
                               xmlTextWriterPtr xo)
{
  struct drive *drv;
  size_t i;

  XMLERROR (-1, xmlTextWriterStartElement (xo, BAD_CAST "devices"));

  /* Path to qemu.  Only write this if the user has changed the
   * default, otherwise allow libvirt to choose the best one.
   */
  if (is_custom_qemu (g)) {
    XMLERROR (-1, xmlTextWriterStartElement (xo, BAD_CAST "emulator"));
    XMLERROR (-1, xmlTextWriterWriteString (xo, BAD_CAST g->qemu));
    XMLERROR (-1, xmlTextWriterEndElement (xo));
  }

  /* virtio-scsi controller. */
  XMLERROR (-1, xmlTextWriterStartElement (xo, BAD_CAST "controller"));
  XMLERROR (-1,
            xmlTextWriterWriteAttribute (xo, BAD_CAST "type",
                                         BAD_CAST "scsi"));
  XMLERROR (-1,
            xmlTextWriterWriteAttribute (xo, BAD_CAST "index",
                                         BAD_CAST "0"));
  XMLERROR (-1,
            xmlTextWriterWriteAttribute (xo, BAD_CAST "model",
                                         BAD_CAST "virtio-scsi"));
  XMLERROR (-1, xmlTextWriterEndElement (xo));

  /* Disks. */
  ITER_DRIVES (g, i, drv) {
    if (construct_libvirt_xml_disk (g, xo, drv, i) == -1)
      return -1;
  }

  if (params->appliance_overlay) {
    /* Appliance disk. */
    if (construct_libvirt_xml_appliance (g, params, xo) == -1)
      return -1;
  }

  /* Console. */
  XMLERROR (-1, xmlTextWriterStartElement (xo, BAD_CAST "serial"));
  XMLERROR (-1,
            xmlTextWriterWriteAttribute (xo, BAD_CAST "type",
                                         BAD_CAST "unix"));
  XMLERROR (-1, xmlTextWriterStartElement (xo, BAD_CAST "source"));
  XMLERROR (-1,
            xmlTextWriterWriteAttribute (xo, BAD_CAST "mode",
                                         BAD_CAST "connect"));
  XMLERROR (-1,
            xmlTextWriterWriteAttribute (xo, BAD_CAST "path",
                                         BAD_CAST params->console_path));
  XMLERROR (-1, xmlTextWriterEndElement (xo));
  XMLERROR (-1, xmlTextWriterStartElement (xo, BAD_CAST "target"));
  XMLERROR (-1,
            xmlTextWriterWriteAttribute (xo, BAD_CAST "port",
                                         BAD_CAST "0"));
  XMLERROR (-1, xmlTextWriterEndElement (xo));
  XMLERROR (-1, xmlTextWriterEndElement (xo));

  /* Virtio-serial for guestfsd communication. */
  XMLERROR (-1, xmlTextWriterStartElement (xo, BAD_CAST "channel"));
  XMLERROR (-1,
            xmlTextWriterWriteAttribute (xo, BAD_CAST "type",
                                         BAD_CAST "unix"));
  XMLERROR (-1, xmlTextWriterStartElement (xo, BAD_CAST "source"));
  XMLERROR (-1,
            xmlTextWriterWriteAttribute (xo, BAD_CAST "mode",
                                         BAD_CAST "connect"));
  XMLERROR (-1,
            xmlTextWriterWriteAttribute (xo, BAD_CAST "path",
                                         BAD_CAST params->guestfsd_path));
  XMLERROR (-1, xmlTextWriterEndElement (xo));
  XMLERROR (-1, xmlTextWriterStartElement (xo, BAD_CAST "target"));
  XMLERROR (-1,
            xmlTextWriterWriteAttribute (xo, BAD_CAST "type",
                                         BAD_CAST "virtio"));
  XMLERROR (-1,
            xmlTextWriterWriteAttribute (xo, BAD_CAST "name",
                                         BAD_CAST "org.libguestfs.channel.0"));
  XMLERROR (-1, xmlTextWriterEndElement (xo));
  XMLERROR (-1, xmlTextWriterEndElement (xo));

  XMLERROR (-1, xmlTextWriterEndElement (xo));

  return 0;
}

static int
construct_libvirt_xml_disk (guestfs_h *g,
                            xmlTextWriterPtr xo,
                            struct drive *drv, size_t drv_index)
{
  char drive_name[64] = "sd";
  const char *protocol_str;
  char scsi_target[64];
  struct drive_libvirt *drv_priv = (struct drive_libvirt *) drv->priv;
  CLEANUP_FREE char *format = NULL;
  int is_host_device;

  /* XXX We probably could support this if we thought about it some more. */
  if (drv->iface) {
    error (g, _("'iface' parameter is not supported by the libvirt backend"));
    return -1;
  }

  guestfs___drive_name (drv_index, &drive_name[2]);
  snprintf (scsi_target, sizeof scsi_target, "%zu", drv_index);

  XMLERROR (-1, xmlTextWriterStartElement (xo, BAD_CAST "disk"));
  XMLERROR (-1,
            xmlTextWriterWriteAttribute (xo, BAD_CAST "device",
                                         BAD_CAST "disk"));

  switch (drv_priv->real_src.protocol) {
  case drive_protocol_file:
    /* Change the libvirt XML according to whether the host path is
     * a device or a file.  For devices, use:
     *   <disk type=block device=disk>
     *     <source dev=[path]>
     * For files, use:
     *   <disk type=file device=disk>
     *     <source file=[path]>
     */
    is_host_device = is_blk (drv_priv->real_src.u.path);

    if (!is_host_device) {
      XMLERROR (-1,
                xmlTextWriterWriteAttribute (xo, BAD_CAST "type",
                                             BAD_CAST "file"));

      XMLERROR (-1, xmlTextWriterStartElement (xo, BAD_CAST "source"));
      XMLERROR (-1,
                xmlTextWriterWriteAttribute (xo, BAD_CAST "file",
                                             BAD_CAST drv_priv->real_src.u.path));
      if (construct_libvirt_xml_disk_source_seclabel (g, xo) == -1)
        return -1;
      XMLERROR (-1, xmlTextWriterEndElement (xo));
    }
    else {
      XMLERROR (-1,
                xmlTextWriterWriteAttribute (xo, BAD_CAST "type",
                                             BAD_CAST "block"));

      XMLERROR (-1, xmlTextWriterStartElement (xo, BAD_CAST "source"));
      XMLERROR (-1,
                xmlTextWriterWriteAttribute (xo, BAD_CAST "dev",
                                             BAD_CAST drv_priv->real_src.u.path));
      if (construct_libvirt_xml_disk_source_seclabel (g, xo) == -1)
        return -1;
      XMLERROR (-1, xmlTextWriterEndElement (xo));
    }
    break;

    /* For network protocols:
     *   <disk type=network device=disk>
     *     <source protocol=[protocol] [name=exportname]>
     * and then zero or more of:
     *       <host name='example.com' port='10809'/>
     * or:
     *       <host transport='unix' socket='/path/to/socket'/>
     */
  case drive_protocol_gluster:
    protocol_str = "gluster"; goto network_protocols;
  case drive_protocol_nbd:
    protocol_str = "nbd"; goto network_protocols;
  case drive_protocol_rbd:
    protocol_str = "rbd"; goto network_protocols;
  case drive_protocol_sheepdog:
    protocol_str = "sheepdog";
    /*FALLTHROUGH*/
  network_protocols:
    XMLERROR (-1,
              xmlTextWriterWriteAttribute (xo, BAD_CAST "type",
                                           BAD_CAST "network"));
    XMLERROR (-1, xmlTextWriterStartElement (xo, BAD_CAST "source"));
    XMLERROR (-1,
              xmlTextWriterWriteAttribute (xo, BAD_CAST "protocol",
                                           BAD_CAST protocol_str));
    if (STRNEQ (drv_priv->real_src.u.exportname, ""))
      XMLERROR (-1,
                xmlTextWriterWriteAttribute (xo, BAD_CAST "name",
                                             BAD_CAST drv_priv->real_src.u.exportname));
    if (construct_libvirt_xml_disk_source_hosts (g, xo,
                                                 &drv_priv->real_src) == -1)
      return -1;
    if (construct_libvirt_xml_disk_source_seclabel (g, xo) == -1)
      return -1;
    XMLERROR (-1, xmlTextWriterEndElement (xo));
  }

  XMLERROR (-1, xmlTextWriterStartElement (xo, BAD_CAST "target"));
  XMLERROR (-1,
            xmlTextWriterWriteAttribute (xo, BAD_CAST "dev",
                                         BAD_CAST drive_name));
  XMLERROR (-1,
            xmlTextWriterWriteAttribute (xo, BAD_CAST "bus",
                                         BAD_CAST "scsi"));
  XMLERROR (-1, xmlTextWriterEndElement (xo));

  XMLERROR (-1, xmlTextWriterStartElement (xo, BAD_CAST "driver"));
  XMLERROR (-1,
            xmlTextWriterWriteAttribute (xo, BAD_CAST "name",
                                         BAD_CAST "qemu"));
  if (drv_priv->format) {
    XMLERROR (-1,
              xmlTextWriterWriteAttribute (xo, BAD_CAST "type",
                                           BAD_CAST drv_priv->format));
  }
  else if (drv_priv->real_src.protocol == drive_protocol_file) {
    /* libvirt has disabled the feature of detecting the disk format,
     * unless the administrator sets allow_disk_format_probing=1 in
     * qemu.conf.  There is no way to detect if this option is set, so we
     * have to do format detection here using qemu-img and pass that to
     * libvirt.
     *
     * This is still a security issue, so in most cases it is recommended
     * the users pass the format to libguestfs which will faithfully pass
     * that to libvirt and this function won't be used.
     */
    format = guestfs_disk_format (g, drv_priv->real_src.u.path);
    if (!format)
      return -1;

    if (STREQ (format, "unknown")) {
      error (g, _("could not auto-detect the format.\n"
                  "If the format is known, pass the format to libguestfs, eg. using the\n"
                  "'--format' option, or via the optional 'format' argument to 'add-drive'."));
      return -1;
    }

    XMLERROR (-1,
              xmlTextWriterWriteAttribute (xo, BAD_CAST "type",
                                           BAD_CAST format));
  }
  else {
    error (g, _("could not auto-detect the format when using a non-file protocol.\n"
                "If the format is known, pass the format to libguestfs, eg. using the\n"
                "'--format' option, or via the optional 'format' argument to 'add-drive'."));
    return -1;
  }

  if (drv->use_cache_none) {
    XMLERROR (-1,
              xmlTextWriterWriteAttribute (xo, BAD_CAST "cache",
                                           BAD_CAST "none"));
  }
  XMLERROR (-1, xmlTextWriterEndElement (xo));

  if (drv->disk_label) {
    XMLERROR (-1, xmlTextWriterStartElement (xo, BAD_CAST "serial"));
    XMLERROR (-1, xmlTextWriterWriteString (xo, BAD_CAST drv->disk_label));
    XMLERROR (-1, xmlTextWriterEndElement (xo));
  }

  XMLERROR (-1, xmlTextWriterStartElement (xo, BAD_CAST "address"));
  XMLERROR (-1,
            xmlTextWriterWriteAttribute (xo, BAD_CAST "type",
                                         BAD_CAST "drive"));
  XMLERROR (-1,
            xmlTextWriterWriteAttribute (xo, BAD_CAST "controller",
                                         BAD_CAST "0"));
  XMLERROR (-1,
            xmlTextWriterWriteAttribute (xo, BAD_CAST "bus",
                                         BAD_CAST "0"));
  XMLERROR (-1,
            xmlTextWriterWriteAttribute (xo, BAD_CAST "target",
                                         BAD_CAST scsi_target));
  XMLERROR (-1,
            xmlTextWriterWriteAttribute (xo, BAD_CAST "unit",
                                         BAD_CAST "0"));
  XMLERROR (-1, xmlTextWriterEndElement (xo));

  XMLERROR (-1, xmlTextWriterEndElement (xo));

  return 0;
}

static int
construct_libvirt_xml_disk_source_hosts (guestfs_h *g,
                                         xmlTextWriterPtr xo,
                                         const struct drive_source *src)
{
  size_t i;

  for (i = 0; i < src->nr_servers; ++i) {
    XMLERROR (-1, xmlTextWriterStartElement (xo, BAD_CAST "host"));

    switch (src->servers[i].transport) {
    case drive_transport_none:
    case drive_transport_tcp: {
      const char *hostname;
      int port;
      char port_str[64];

      hostname = src->servers[i].u.hostname;
      port = src->servers[i].port;
      snprintf (port_str, sizeof port_str, "%d", port);

      XMLERROR (-1,
                xmlTextWriterWriteAttribute (xo, BAD_CAST "name",
                                             BAD_CAST hostname));
      XMLERROR (-1,
                xmlTextWriterWriteAttribute (xo, BAD_CAST "port",
                                             BAD_CAST port_str));
      break;
    }

    case drive_transport_unix: {
      const char *socket = src->servers[i].u.socket;

      XMLERROR (-1,
                xmlTextWriterWriteAttribute (xo, BAD_CAST "transport",
                                             BAD_CAST "unix"));
      XMLERROR (-1,
                xmlTextWriterWriteAttribute (xo, BAD_CAST "socket",
                                             BAD_CAST socket));
      break;
    }
    }

    XMLERROR (-1, xmlTextWriterEndElement (xo));
  }

  return 0;
}

static int
construct_libvirt_xml_disk_source_seclabel (guestfs_h *g,
                                            xmlTextWriterPtr xo)
{
  if (g->virt_selinux_norelabel_disks) {
    XMLERROR (-1, xmlTextWriterStartElement (xo, BAD_CAST "seclabel"));
    XMLERROR (-1,
              xmlTextWriterWriteAttribute (xo, BAD_CAST "model",
                                           BAD_CAST "selinux"));
    XMLERROR (-1,
              xmlTextWriterWriteAttribute (xo, BAD_CAST "relabel",
                                           BAD_CAST "no"));
    XMLERROR (-1, xmlTextWriterEndElement (xo));
  }

  return 0;
}

static int
construct_libvirt_xml_appliance (guestfs_h *g,
                                 const struct libvirt_xml_params *params,
                                 xmlTextWriterPtr xo)
{
  char scsi_target[64];

  snprintf (scsi_target, sizeof scsi_target, "%zu", params->appliance_index);

  XMLERROR (-1, xmlTextWriterStartElement (xo, BAD_CAST "disk"));
  XMLERROR (-1,
            xmlTextWriterWriteAttribute (xo, BAD_CAST "type",
                                         BAD_CAST "file"));
  XMLERROR (-1,
            xmlTextWriterWriteAttribute (xo, BAD_CAST "device",
                                         BAD_CAST "disk"));

  XMLERROR (-1, xmlTextWriterStartElement (xo, BAD_CAST "source"));
  XMLERROR (-1,
            xmlTextWriterWriteAttribute (xo, BAD_CAST "file",
                                         BAD_CAST params->appliance_overlay));
  XMLERROR (-1, xmlTextWriterEndElement (xo));

  XMLERROR (-1, xmlTextWriterStartElement (xo, BAD_CAST "target"));
  XMLERROR (-1,
            xmlTextWriterWriteAttribute (xo, BAD_CAST "dev",
                                         BAD_CAST &params->appliance_dev[5]));
  XMLERROR (-1,
            xmlTextWriterWriteAttribute (xo, BAD_CAST "bus",
                                         BAD_CAST "scsi"));
  XMLERROR (-1, xmlTextWriterEndElement (xo));

  XMLERROR (-1, xmlTextWriterStartElement (xo, BAD_CAST "driver"));
  XMLERROR (-1,
            xmlTextWriterWriteAttribute (xo, BAD_CAST "name",
                                         BAD_CAST "qemu"));
  XMLERROR (-1,
            xmlTextWriterWriteAttribute (xo, BAD_CAST "type",
                                         BAD_CAST "qcow2"));
  XMLERROR (-1,
            xmlTextWriterWriteAttribute (xo, BAD_CAST "cache",
                                         BAD_CAST "unsafe"));
  XMLERROR (-1, xmlTextWriterEndElement (xo));

  XMLERROR (-1, xmlTextWriterStartElement (xo, BAD_CAST "address"));
  XMLERROR (-1,
            xmlTextWriterWriteAttribute (xo, BAD_CAST "type",
                                         BAD_CAST "drive"));
  XMLERROR (-1,
            xmlTextWriterWriteAttribute (xo, BAD_CAST "controller",
                                         BAD_CAST "0"));
  XMLERROR (-1,
            xmlTextWriterWriteAttribute (xo, BAD_CAST "bus",
                                         BAD_CAST "0"));
  XMLERROR (-1,
            xmlTextWriterWriteAttribute (xo, BAD_CAST "target",
                                         BAD_CAST scsi_target));
  XMLERROR (-1,
            xmlTextWriterWriteAttribute (xo, BAD_CAST "unit",
                                         BAD_CAST "0"));
  XMLERROR (-1, xmlTextWriterEndElement (xo));

  XMLERROR (-1, xmlTextWriterStartElement (xo, BAD_CAST "shareable"));
  XMLERROR (-1, xmlTextWriterEndElement (xo));

  /* We'd like to do this, but it's not supported by libvirt.
   * See make_drive_priv for the workaround.
   *
   * XMLERROR (-1, xmlTextWriterStartElement (xo, BAD_CAST "transient"));
   * XMLERROR (-1, xmlTextWriterEndElement (xo));
   */

  XMLERROR (-1, xmlTextWriterEndElement (xo));

  return 0;
}

static int
construct_libvirt_xml_qemu_cmdline (guestfs_h *g,
                                    const struct libvirt_xml_params *params,
                                    xmlTextWriterPtr xo)
{
  struct qemu_param *qp;
  CLEANUP_FREE char *tmpdir = NULL;

  XMLERROR (-1, xmlTextWriterStartElement (xo, BAD_CAST "qemu:commandline"));

  /* We need to ensure the snapshots are created in the persistent
   * temporary directory (RHBZ#856619).  We must set one, because
   * otherwise libvirt will use a random TMPDIR (RHBZ#865464).
   */
  tmpdir = guestfs_get_cachedir (g);

  XMLERROR (-1, xmlTextWriterStartElement (xo, BAD_CAST "qemu:env"));
  XMLERROR (-1,
            xmlTextWriterWriteAttribute (xo, BAD_CAST "name",
                                         BAD_CAST "TMPDIR"));
  XMLERROR (-1,
            xmlTextWriterWriteAttribute (xo, BAD_CAST "value",
                                         BAD_CAST tmpdir));
  XMLERROR (-1, xmlTextWriterEndElement (xo));

  /* Workaround because libvirt user networking cannot specify "net="
   * parameter.
   */
  if (g->enable_network) {
    XMLERROR (-1, xmlTextWriterStartElement (xo, BAD_CAST "qemu:arg"));
    XMLERROR (-1,
              xmlTextWriterWriteAttribute (xo, BAD_CAST "value",
                                           BAD_CAST "-netdev"));
    XMLERROR (-1, xmlTextWriterEndElement (xo));

    XMLERROR (-1, xmlTextWriterStartElement (xo, BAD_CAST "qemu:arg"));
    XMLERROR (-1,
              xmlTextWriterWriteAttribute (xo, BAD_CAST "value",
                                           BAD_CAST "user,id=usernet,net=169.254.0.0/16"));
    XMLERROR (-1, xmlTextWriterEndElement (xo));

    XMLERROR (-1, xmlTextWriterStartElement (xo, BAD_CAST "qemu:arg"));
    XMLERROR (-1,
              xmlTextWriterWriteAttribute (xo, BAD_CAST "value",
                                           BAD_CAST "-device"));
    XMLERROR (-1, xmlTextWriterEndElement (xo));

    XMLERROR (-1, xmlTextWriterStartElement (xo, BAD_CAST "qemu:arg"));
    XMLERROR (-1,
              xmlTextWriterWriteAttribute (xo, BAD_CAST "value",
                                           BAD_CAST "virtio-net-pci,netdev=usernet"));
    XMLERROR (-1, xmlTextWriterEndElement (xo));
  }

  /* The qemu command line arguments requested by the caller. */
  for (qp = g->qemu_params; qp; qp = qp->next) {
    XMLERROR (-1, xmlTextWriterStartElement (xo, BAD_CAST "qemu:arg"));
    XMLERROR (-1,
              xmlTextWriterWriteAttribute (xo, BAD_CAST "value",
                                           BAD_CAST qp->qemu_param));
    XMLERROR (-1, xmlTextWriterEndElement (xo));

    if (qp->qemu_value) {
      XMLERROR (-1, xmlTextWriterStartElement (xo, BAD_CAST "qemu:arg"));
      XMLERROR (-1,
                xmlTextWriterWriteAttribute (xo, BAD_CAST "value",
                                             BAD_CAST qp->qemu_value));
      XMLERROR (-1, xmlTextWriterEndElement (xo));
    }
  }

  XMLERROR (-1, xmlTextWriterEndElement (xo));

  return 0;
}

static int
is_blk (const char *path)
{
  struct stat statbuf;

  if (stat (path, &statbuf) == -1)
    return 0;
  return S_ISBLK (statbuf.st_mode);
}

static int
random_chars (char *ret, size_t len)
{
  int fd;
  size_t i;
  unsigned char c;
  int saved_errno;

  fd = open ("/dev/urandom", O_RDONLY|O_CLOEXEC);
  if (fd == -1)
    return -1;

  for (i = 0; i < len; ++i) {
    if (read (fd, &c, 1) != 1) {
      saved_errno = errno;
      close (fd);
      errno = saved_errno;
      return -1;
    }
    ret[i] = "0123456789abcdefghijklmnopqrstuvwxyz"[c % 36];
  }
  ret[len] = '\0';

  if (close (fd) == -1)
    return -1;

  return 0;
}

static void
ignore_errors (void *ignore, virErrorPtr ignore2)
{
  /* empty */
}

/* Create a temporary qcow2 overlay on top of 'backing_device', which is
 * either an absolute path or a qemu device name.
 */
static char *
make_qcow2_overlay (guestfs_h *g, const char *backing_device,
                    const char *format, const char *selinux_imagelabel)
{
  char *tmpfile = NULL;
  CLEANUP_CMD_CLOSE struct command *cmd = guestfs___new_command (g);
  int r;

  tmpfile = safe_asprintf (g, "%s/snapshot%d", g->tmpdir, ++g->unique);

  guestfs___cmd_add_arg (cmd, "qemu-img");
  guestfs___cmd_add_arg (cmd, "create");
  guestfs___cmd_add_arg (cmd, "-f");
  guestfs___cmd_add_arg (cmd, "qcow2");
  guestfs___cmd_add_arg (cmd, "-b");
  guestfs___cmd_add_arg (cmd, backing_device);
  if (format) {
    guestfs___cmd_add_arg (cmd, "-o");
    guestfs___cmd_add_arg_format (cmd, "backing_fmt=%s", format);
  }
  guestfs___cmd_add_arg (cmd, tmpfile);
  r = guestfs___cmd_run (cmd);
  if (r == -1)
    goto error;
  if (!WIFEXITED (r) || WEXITSTATUS (r) != 0) {
    guestfs___external_command_failed (g, r, "qemu-img create", backing_device);
    goto error;
  }

#if HAVE_LIBSELINUX
  if (selinux_imagelabel) {
    debug (g, "setting SELinux label on %s to %s",
           tmpfile, selinux_imagelabel);
    if (setfilecon (tmpfile, (security_context_t) selinux_imagelabel) == -1)
      selinux_warning (g, __func__, "setfilecon", tmpfile);
  }
#endif

  return tmpfile;               /* caller frees */

 error:
  free (tmpfile);

  return NULL;
}

/* This sets up the drv->priv structure, which contains the drive
 * that we're actually going to add.  If asked to make a drive readonly
 * then because libvirt doesn't support <transient/> we have to add
 * a qcow2 overlay here.
 */
static int
make_drive_priv (guestfs_h *g, struct drive *drv,
                 const char *selinux_imagelabel)
{
  char *path;
  struct drive_libvirt *drv_priv;

  if (drv->priv && drv->free_priv)
    drv->free_priv (drv->priv);

  drv->priv = drv_priv = safe_calloc (g, 1, sizeof (struct drive_libvirt));
  drv->free_priv = drive_free_priv;

  switch (drv->src.protocol) {
  case drive_protocol_file:

    /* Even for non-readonly paths, we need to make the paths absolute here. */
    path = realpath (drv->src.u.path, NULL);
    if (path == NULL) {
      perrorf (g, _("realpath: could not convert '%s' to absolute path"),
               drv->src.u.path);
      return -1;
    }

    drv_priv->real_src.protocol = drive_protocol_file;

    if (!drv->readonly) {
      drv_priv->real_src.u.path = path;
      drv_priv->format = drv->format ? safe_strdup (g, drv->format) : NULL;
    }
    else {
      drv_priv->real_src.u.path = make_qcow2_overlay (g, path, drv->format,
                                                      selinux_imagelabel);
      free (path);
      if (!drv_priv->real_src.u.path)
        return -1;
      drv_priv->format = safe_strdup (g, "qcow2");
    }
    break;

  case drive_protocol_gluster:
  case drive_protocol_nbd:
  case drive_protocol_rbd:
  case drive_protocol_sheepdog:
    if (!drv->readonly) {
      guestfs___copy_drive_source (g, &drv->src, &drv_priv->real_src);
      drv_priv->format = drv->format ? safe_strdup (g, drv->format) : NULL;
    }
    else {
      CLEANUP_FREE char *qemu_device;

      drv_priv->real_src.protocol = drive_protocol_file;
      qemu_device = guestfs___drive_source_qemu_param (g, &drv->src);
      drv_priv->real_src.u.path = make_qcow2_overlay (g, qemu_device,
                                                      drv->format,
                                                      selinux_imagelabel);
      if (!drv_priv->real_src.u.path)
        return -1;
      drv_priv->format = safe_strdup (g, "qcow2");
    }
  }

  return 0;
}

static void
drive_free_priv (void *priv)
{
  struct drive_libvirt *drv_priv = priv;

  guestfs___free_drive_source (&drv_priv->real_src);
  free (drv_priv->format);
  free (drv_priv);
}

static int
shutdown_libvirt (guestfs_h *g, int check_for_errors)
{
  virConnectPtr conn = g->virt.conn;
  virDomainPtr dom = g->virt.dom;
  int ret = 0;
  int flags;

  /* Note that we can be called back very early in launch (specifically
   * from launch_libvirt itself), when conn and dom might be NULL.
   */

  if (dom != NULL) {
    flags = check_for_errors ? VIR_DOMAIN_DESTROY_GRACEFUL : 0;
    if (virDomainDestroyFlags (dom, flags) == -1) {
      libvirt_error (g, _("could not destroy libvirt domain"));
      ret = -1;
    }
    virDomainFree (dom);
  }

  if (conn != NULL)
    virConnectClose (conn);

  g->virt.conn = NULL;
  g->virt.dom = NULL;

  return ret;
}

/* Wrapper around error() which produces better errors for
 * libvirt functions.
 */
static void
libvirt_error (guestfs_h *g, const char *fs, ...)
{
  va_list args;
  char *msg;
  int len;
  virErrorPtr err;

  va_start (args, fs);
  len = vasprintf (&msg, fs, args);
  va_end (args);

  if (len < 0)
    msg = safe_asprintf (g,
                         _("%s: internal error forming error message"),
                         __func__);

  /* In all recent libvirt, this retrieves the thread-local error. */
  err = virGetLastError ();
  if (err)
    error (g, "%s: %s [code=%d domain=%d]",
           msg, err->message, err->code, err->domain);
  else
    error (g, "%s", msg);

  /* NB. 'err' must not be freed! */
  free (msg);
}

static void
selinux_warning (guestfs_h *g, const char *func,
                 const char *selinux_op, const char *data)
{
  debug (g, "%s: %s failed: %s: %m"
         " [you can ignore this UNLESS using SELinux + sVirt]",
         func, selinux_op, data ? data : "(none)");
}

/* This backend assumes virtio-scsi is available. */
static int
max_disks_libvirt (guestfs_h *g)
{
  return 255;
}

static xmlChar *construct_libvirt_xml_hot_add_disk (guestfs_h *g, struct drive *drv, size_t drv_index);

/* Hot-add a drive.  Note the appliance is up when this is called. */
static int
hot_add_drive_libvirt (guestfs_h *g, struct drive *drv, size_t drv_index)
{
  virConnectPtr conn = g->virt.conn;
  virDomainPtr dom = g->virt.dom;
  CLEANUP_FREE xmlChar *xml = NULL;

  if (!conn || !dom) {
    /* This is essentially an internal error if it happens. */
    error (g, "%s: conn == NULL or dom == NULL", __func__);
    return -1;
  }

  if (make_drive_priv (g, drv, g->virt_selinux_imagelabel) == -1)
    return -1;

  /* Create the XML for the new disk. */
  xml = construct_libvirt_xml_hot_add_disk (g, drv, drv_index);
  if (xml == NULL)
    return -1;

  /* Attach it. */
  if (virDomainAttachDeviceFlags (dom, (char *) xml,
                                  VIR_DOMAIN_DEVICE_MODIFY_LIVE) == -1) {
    libvirt_error (g, _("could not attach disk to libvirt domain"));
    return -1;
  }

  return 0;
}

/* Hot-remove a drive.  Note the appliance is up when this is called. */
static int
hot_remove_drive_libvirt (guestfs_h *g, struct drive *drv, size_t drv_index)
{
  virConnectPtr conn = g->virt.conn;
  virDomainPtr dom = g->virt.dom;
  CLEANUP_FREE xmlChar *xml = NULL;

  if (!conn || !dom) {
    /* This is essentially an internal error if it happens. */
    error (g, "%s: conn == NULL or dom == NULL", __func__);
    return -1;
  }

  /* Re-create the XML for the disk. */
  xml = construct_libvirt_xml_hot_add_disk (g, drv, drv_index);
  if (xml == NULL)
    return -1;

  /* Detach it. */
  if (virDomainDetachDeviceFlags (dom, (char *) xml,
                                  VIR_DOMAIN_DEVICE_MODIFY_LIVE) == -1) {
    libvirt_error (g, _("could not detach disk from libvirt domain"));
    return -1;
  }

  return 0;
}

static xmlChar *
construct_libvirt_xml_hot_add_disk (guestfs_h *g, struct drive *drv,
                                    size_t drv_index)
{
  xmlChar *ret = NULL;
  CLEANUP_XMLBUFFERFREE xmlBufferPtr xb = NULL;
  xmlOutputBufferPtr ob;
  CLEANUP_XMLFREETEXTWRITER xmlTextWriterPtr xo = NULL;

  XMLERROR_RET (NULL, xb = xmlBufferCreate (), NULL);
  XMLERROR_RET (NULL, ob = xmlOutputBufferCreateBuffer (xb, NULL), NULL);
  XMLERROR_RET (NULL, xo = xmlNewTextWriter (ob), NULL);

  XMLERROR_RET (-1, xmlTextWriterSetIndent (xo, 1), NULL);
  XMLERROR_RET (-1, xmlTextWriterSetIndentString (xo, BAD_CAST "  "), NULL);
  XMLERROR_RET (-1, xmlTextWriterStartDocument (xo, NULL, NULL, NULL), NULL);

  if (construct_libvirt_xml_disk (g, xo, drv, drv_index) == -1)
    return NULL;

  XMLERROR_RET (-1, xmlTextWriterEndDocument (xo), NULL);
  XMLERROR_RET (NULL, ret = xmlBufferDetach (xb), NULL); /* caller frees ret */

  debug (g, "hot-add disk XML:\n%s", ret);

  return ret;
}

struct backend_ops backend_ops_libvirt = {
  .launch = launch_libvirt,
  .shutdown = shutdown_libvirt,
  .max_disks = max_disks_libvirt,
  .hot_add_drive = hot_add_drive_libvirt,
  .hot_remove_drive = hot_remove_drive_libvirt,
};

#else /* no libvirt or libxml2 at compile time */

#define NOT_IMPL(r)                                                     \
  error (g, _("libvirt backend is not available because "         \
              "this version of libguestfs was compiled "                \
              "without libvirt or libvirt < %d.%d.%d or without libxml2"), \
         MIN_LIBVIRT_MAJOR, MIN_LIBVIRT_MINOR, MIN_LIBVIRT_MICRO);      \
  return r

static int
launch_libvirt (guestfs_h *g, const char *arg)
{
  NOT_IMPL (-1);
}

static int
shutdown_libvirt (guestfs_h *g, int check_for_errors)
{
  NOT_IMPL (-1);
}

static int
max_disks_libvirt (guestfs_h *g)
{
  NOT_IMPL (-1);
}

struct backend_ops backend_ops_libvirt = {
  .launch = launch_libvirt,
  .shutdown = shutdown_libvirt,
  .max_disks = max_disks_libvirt,
};

#endif /* no libvirt or libxml2 at compile time */

int
guestfs__internal_set_libvirt_selinux_label (guestfs_h *g, const char *label,
                                             const char *imagelabel)
{
  free (g->virt_selinux_label);
  g->virt_selinux_label = safe_strdup (g, label);
  free (g->virt_selinux_imagelabel);
  g->virt_selinux_imagelabel = safe_strdup (g, imagelabel);
  return 0;
}

int
guestfs__internal_set_libvirt_selinux_norelabel_disks (guestfs_h *g, int flag)
{
  g->virt_selinux_norelabel_disks = flag;
  return 0;
}
