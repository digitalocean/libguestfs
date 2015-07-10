/* libguestfs generated file
 * WARNING: THIS FILE IS GENERATED FROM:
 *   generator/ *.ml
 * ANY CHANGES YOU MAKE TO THIS FILE WILL BE LOST.
 *
 * Copyright (C) 2009-2015 Red Hat Inc.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 */

#include <config.h>

#include "guestfs-gobject.h"

/**
 * SECTION:session
 * @short_description: A libguestfs session
 * @include: guestfs-gobject.h
 */

  #include <glib.h>
  #include <glib-object.h>
  #include <guestfs.h>
  #include <stdint.h>
  #include <stdio.h>
  #include <string.h>
  #include <inttypes.h>

/* Error quark */

#define GUESTFS_ERROR guestfs_error_quark ()

static GQuark
guestfs_error_quark (void)
{
  return g_quark_from_static_string ("guestfs");
}

/* Cancellation handler */
static void
cancelled_handler (gpointer data)
{
  guestfs_h *g = (guestfs_h *)data;
  guestfs_user_cancel (g);
}

/* GuestfsSessionEventParams */
static GuestfsSessionEventParams *
guestfs_session_event_params_copy (GuestfsSessionEventParams *src)
{
  return g_slice_dup (GuestfsSessionEventParams, src);
}

static void
guestfs_session_event_params_free (GuestfsSessionEventParams *src)
{
  g_slice_free (GuestfsSessionEventParams, src);
}

G_DEFINE_BOXED_TYPE (GuestfsSessionEventParams,
                    guestfs_session_event_params,
                    guestfs_session_event_params_copy,
                    guestfs_session_event_params_free)

/* Event callback */
static guint signals[10] = { 0 };

static GuestfsSessionEvent
guestfs_session_event_from_guestfs_event (uint64_t event)
{
  switch (event) {
    case GUESTFS_EVENT_CLOSE: return GUESTFS_SESSION_EVENT_CLOSE;
    case GUESTFS_EVENT_SUBPROCESS_QUIT: return GUESTFS_SESSION_EVENT_SUBPROCESS_QUIT;
    case GUESTFS_EVENT_LAUNCH_DONE: return GUESTFS_SESSION_EVENT_LAUNCH_DONE;
    case GUESTFS_EVENT_PROGRESS: return GUESTFS_SESSION_EVENT_PROGRESS;
    case GUESTFS_EVENT_APPLIANCE: return GUESTFS_SESSION_EVENT_APPLIANCE;
    case GUESTFS_EVENT_LIBRARY: return GUESTFS_SESSION_EVENT_LIBRARY;
    case GUESTFS_EVENT_TRACE: return GUESTFS_SESSION_EVENT_TRACE;
    case GUESTFS_EVENT_ENTER: return GUESTFS_SESSION_EVENT_ENTER;
    case GUESTFS_EVENT_LIBVIRT_AUTH: return GUESTFS_SESSION_EVENT_LIBVIRT_AUTH;
    case GUESTFS_EVENT_WARNING: return GUESTFS_SESSION_EVENT_WARNING;
  }

  g_warning ("guestfs_session_event_from_guestfs_event: invalid event %" PRIu64,
            event);
  return UINT32_MAX;
}

static void
event_callback (guestfs_h *g, void *opaque,
               uint64_t event, int event_handle,
               int flags,
               const char *buf, size_t buf_len,
               const uint64_t *array, size_t array_len)
{
  GuestfsSessionEventParams *params = g_slice_new0 (GuestfsSessionEventParams);

  params->event = guestfs_session_event_from_guestfs_event (event);
  params->flags = flags;

  params->buf = g_byte_array_sized_new (buf_len);
  g_byte_array_append (params->buf, (const guint8 *) buf, buf_len);

  for (size_t i = 0; i < array_len && i < 4; i++) {
    if (array_len > 4) {
      array_len = 4;
    }
    memcpy (params->array, array, sizeof (array[0]) * array_len);
  }
  params->array_len = array_len;

  GuestfsSession *session = (GuestfsSession *) opaque;

  g_signal_emit (session, signals[params->event], 0, params);

  guestfs_session_event_params_free (params);
}

/* GuestfsSessionEvent */

GType
guestfs_session_event_get_type (void)
{
  static GType etype = 0;
  if (etype == 0) {
    static const GEnumValue values[] = {
      { GUESTFS_SESSION_EVENT_CLOSE, "GUESTFS_SESSION_EVENT_CLOSE", "close" },
      { GUESTFS_SESSION_EVENT_SUBPROCESS_QUIT, "GUESTFS_SESSION_EVENT_SUBPROCESS_QUIT", "subprocess_quit" },
      { GUESTFS_SESSION_EVENT_LAUNCH_DONE, "GUESTFS_SESSION_EVENT_LAUNCH_DONE", "launch_done" },
      { GUESTFS_SESSION_EVENT_PROGRESS, "GUESTFS_SESSION_EVENT_PROGRESS", "progress" },
      { GUESTFS_SESSION_EVENT_APPLIANCE, "GUESTFS_SESSION_EVENT_APPLIANCE", "appliance" },
      { GUESTFS_SESSION_EVENT_LIBRARY, "GUESTFS_SESSION_EVENT_LIBRARY", "library" },
      { GUESTFS_SESSION_EVENT_TRACE, "GUESTFS_SESSION_EVENT_TRACE", "trace" },
      { GUESTFS_SESSION_EVENT_ENTER, "GUESTFS_SESSION_EVENT_ENTER", "enter" },
      { GUESTFS_SESSION_EVENT_LIBVIRT_AUTH, "GUESTFS_SESSION_EVENT_LIBVIRT_AUTH", "libvirt_auth" },
      { GUESTFS_SESSION_EVENT_WARNING, "GUESTFS_SESSION_EVENT_WARNING", "warning" },
    };
    etype = g_enum_register_static ("GuestfsSessionEvent", values);
  }
  return etype;
}

/* GuestfsSession */

#define GUESTFS_SESSION_GET_PRIVATE(obj) (G_TYPE_INSTANCE_GET_PRIVATE ( (obj), GUESTFS_TYPE_SESSION, GuestfsSessionPrivate))

struct _GuestfsSessionPrivate
{
  guestfs_h *g;
  int event_handle;
};

G_DEFINE_TYPE (GuestfsSession, guestfs_session, G_TYPE_OBJECT);

static void
guestfs_session_finalize (GObject *object)
{
  GuestfsSession *session = GUESTFS_SESSION (object);
  GuestfsSessionPrivate *priv = session->priv;

  if (priv->g) guestfs_close (priv->g);

  G_OBJECT_CLASS (guestfs_session_parent_class)->finalize (object);
}

static void
guestfs_session_class_init (GuestfsSessionClass *klass)
{
  GObjectClass *object_class = G_OBJECT_CLASS (klass);

  object_class->finalize = guestfs_session_finalize;

  g_type_class_add_private (klass, sizeof (GuestfsSessionPrivate));

  /**
   * GuestfsSession::close:
   * @session: The session which emitted the signal
   * @params: An object containing event parameters
   *
   * See "SETTING CALLBACKS TO HANDLE EVENTS" in guestfs(3) for
   * more details about this event.
   */
  signals[GUESTFS_SESSION_EVENT_CLOSE] =
    g_signal_new (g_intern_static_string ("close"),
                 G_OBJECT_CLASS_TYPE (object_class),
                 G_SIGNAL_RUN_LAST,
                 0,
                 NULL, NULL,
                 NULL,
                 G_TYPE_NONE,
                 1, guestfs_session_event_params_get_type ());

  /**
   * GuestfsSession::subprocess_quit:
   * @session: The session which emitted the signal
   * @params: An object containing event parameters
   *
   * See "SETTING CALLBACKS TO HANDLE EVENTS" in guestfs(3) for
   * more details about this event.
   */
  signals[GUESTFS_SESSION_EVENT_SUBPROCESS_QUIT] =
    g_signal_new (g_intern_static_string ("subprocess_quit"),
                 G_OBJECT_CLASS_TYPE (object_class),
                 G_SIGNAL_RUN_LAST,
                 0,
                 NULL, NULL,
                 NULL,
                 G_TYPE_NONE,
                 1, guestfs_session_event_params_get_type ());

  /**
   * GuestfsSession::launch_done:
   * @session: The session which emitted the signal
   * @params: An object containing event parameters
   *
   * See "SETTING CALLBACKS TO HANDLE EVENTS" in guestfs(3) for
   * more details about this event.
   */
  signals[GUESTFS_SESSION_EVENT_LAUNCH_DONE] =
    g_signal_new (g_intern_static_string ("launch_done"),
                 G_OBJECT_CLASS_TYPE (object_class),
                 G_SIGNAL_RUN_LAST,
                 0,
                 NULL, NULL,
                 NULL,
                 G_TYPE_NONE,
                 1, guestfs_session_event_params_get_type ());

  /**
   * GuestfsSession::progress:
   * @session: The session which emitted the signal
   * @params: An object containing event parameters
   *
   * See "SETTING CALLBACKS TO HANDLE EVENTS" in guestfs(3) for
   * more details about this event.
   */
  signals[GUESTFS_SESSION_EVENT_PROGRESS] =
    g_signal_new (g_intern_static_string ("progress"),
                 G_OBJECT_CLASS_TYPE (object_class),
                 G_SIGNAL_RUN_LAST,
                 0,
                 NULL, NULL,
                 NULL,
                 G_TYPE_NONE,
                 1, guestfs_session_event_params_get_type ());

  /**
   * GuestfsSession::appliance:
   * @session: The session which emitted the signal
   * @params: An object containing event parameters
   *
   * See "SETTING CALLBACKS TO HANDLE EVENTS" in guestfs(3) for
   * more details about this event.
   */
  signals[GUESTFS_SESSION_EVENT_APPLIANCE] =
    g_signal_new (g_intern_static_string ("appliance"),
                 G_OBJECT_CLASS_TYPE (object_class),
                 G_SIGNAL_RUN_LAST,
                 0,
                 NULL, NULL,
                 NULL,
                 G_TYPE_NONE,
                 1, guestfs_session_event_params_get_type ());

  /**
   * GuestfsSession::library:
   * @session: The session which emitted the signal
   * @params: An object containing event parameters
   *
   * See "SETTING CALLBACKS TO HANDLE EVENTS" in guestfs(3) for
   * more details about this event.
   */
  signals[GUESTFS_SESSION_EVENT_LIBRARY] =
    g_signal_new (g_intern_static_string ("library"),
                 G_OBJECT_CLASS_TYPE (object_class),
                 G_SIGNAL_RUN_LAST,
                 0,
                 NULL, NULL,
                 NULL,
                 G_TYPE_NONE,
                 1, guestfs_session_event_params_get_type ());

  /**
   * GuestfsSession::trace:
   * @session: The session which emitted the signal
   * @params: An object containing event parameters
   *
   * See "SETTING CALLBACKS TO HANDLE EVENTS" in guestfs(3) for
   * more details about this event.
   */
  signals[GUESTFS_SESSION_EVENT_TRACE] =
    g_signal_new (g_intern_static_string ("trace"),
                 G_OBJECT_CLASS_TYPE (object_class),
                 G_SIGNAL_RUN_LAST,
                 0,
                 NULL, NULL,
                 NULL,
                 G_TYPE_NONE,
                 1, guestfs_session_event_params_get_type ());

  /**
   * GuestfsSession::enter:
   * @session: The session which emitted the signal
   * @params: An object containing event parameters
   *
   * See "SETTING CALLBACKS TO HANDLE EVENTS" in guestfs(3) for
   * more details about this event.
   */
  signals[GUESTFS_SESSION_EVENT_ENTER] =
    g_signal_new (g_intern_static_string ("enter"),
                 G_OBJECT_CLASS_TYPE (object_class),
                 G_SIGNAL_RUN_LAST,
                 0,
                 NULL, NULL,
                 NULL,
                 G_TYPE_NONE,
                 1, guestfs_session_event_params_get_type ());

  /**
   * GuestfsSession::libvirt_auth:
   * @session: The session which emitted the signal
   * @params: An object containing event parameters
   *
   * See "SETTING CALLBACKS TO HANDLE EVENTS" in guestfs(3) for
   * more details about this event.
   */
  signals[GUESTFS_SESSION_EVENT_LIBVIRT_AUTH] =
    g_signal_new (g_intern_static_string ("libvirt_auth"),
                 G_OBJECT_CLASS_TYPE (object_class),
                 G_SIGNAL_RUN_LAST,
                 0,
                 NULL, NULL,
                 NULL,
                 G_TYPE_NONE,
                 1, guestfs_session_event_params_get_type ());

  /**
   * GuestfsSession::warning:
   * @session: The session which emitted the signal
   * @params: An object containing event parameters
   *
   * See "SETTING CALLBACKS TO HANDLE EVENTS" in guestfs(3) for
   * more details about this event.
   */
  signals[GUESTFS_SESSION_EVENT_WARNING] =
    g_signal_new (g_intern_static_string ("warning"),
                 G_OBJECT_CLASS_TYPE (object_class),
                 G_SIGNAL_RUN_LAST,
                 0,
                 NULL, NULL,
                 NULL,
                 G_TYPE_NONE,
                 1, guestfs_session_event_params_get_type ());
}

static void
guestfs_session_init (GuestfsSession *session)
{
  session->priv = GUESTFS_SESSION_GET_PRIVATE (session);
  session->priv->g = guestfs_create ();

  guestfs_h *g = session->priv->g;

  session->priv->event_handle =
    guestfs_set_event_callback (g, event_callback, GUESTFS_EVENT_ALL,
                               0, session);
}

/**
 * guestfs_session_new:
 *
 * Create a new libguestfs session.
 *
 * Returns: (transfer full): a new guestfs session object
 */
GuestfsSession *
guestfs_session_new (void)
{
  return GUESTFS_SESSION (g_object_new (GUESTFS_TYPE_SESSION, NULL));
}

/**
 * guestfs_session_close:
 * @session: (transfer none): A GuestfsSession object
 * @err: A GError object to receive any generated errors
 *
 * Close a libguestfs session.
 *
 * Returns: true on success, false on error
 */
gboolean
guestfs_session_close (GuestfsSession *session, GError **err)
{
  guestfs_h *g = session->priv->g;

  if (g == NULL) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, "session is already closed");
    return FALSE;
  }

  guestfs_close (g);
  session->priv->g = NULL;

  return TRUE;
}
/**
 * guestfs_session_acl_delete_def_file:
 * @session: (transfer none): A GuestfsSession object
 * @dir: (transfer none) (type filename):
 * @err: A GError object to receive any generated errors
 *
 * delete the default POSIX ACL of a directory
 *
 * This function deletes the default POSIX Access Control List (ACL)
 * attached to directory @dir.
 * 
 * Returns: true on success, false on error
 * Since: 1.19.63
 */
gboolean
guestfs_session_acl_delete_def_file (GuestfsSession *session, const gchar *dir, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "acl_delete_def_file");
    return FALSE;
  }

  int ret = guestfs_acl_delete_def_file (g, dir);
  if (ret == -1) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return FALSE;
  }

  return TRUE;
}

/**
 * guestfs_session_acl_get_file:
 * @session: (transfer none): A GuestfsSession object
 * @path: (transfer none) (type filename):
 * @acltype: (transfer none) (type utf8):
 * @err: A GError object to receive any generated errors
 *
 * get the POSIX ACL attached to a file
 *
 * This function returns the POSIX Access Control List (ACL) attached to
 * @path. The ACL is returned in "long text form" (see acl(5)).
 * 
 * The @acltype parameter may be:
 * 
 * @access
 * Return the ordinary (access) ACL for any file, directory or other
 * filesystem object.
 * 
 * @default
 * Return the default ACL. Normally this only makes sense if @path is a
 * directory.
 * 
 * Returns: (transfer full): the returned string, or NULL on error
 * Since: 1.19.63
 */
gchar *
guestfs_session_acl_get_file (GuestfsSession *session, const gchar *path, const gchar *acltype, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "acl_get_file");
    return NULL;
  }

  char *ret = guestfs_acl_get_file (g, path, acltype);
  if (ret == NULL) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return NULL;
  }

  return ret;
}

/**
 * guestfs_session_acl_set_file:
 * @session: (transfer none): A GuestfsSession object
 * @path: (transfer none) (type filename):
 * @acltype: (transfer none) (type utf8):
 * @acl: (transfer none) (type utf8):
 * @err: A GError object to receive any generated errors
 *
 * set the POSIX ACL attached to a file
 *
 * This function sets the POSIX Access Control List (ACL) attached to
 * @path.
 * 
 * The @acltype parameter may be:
 * 
 * @access
 * Set the ordinary (access) ACL for any file, directory or other
 * filesystem object.
 * 
 * @default
 * Set the default ACL. Normally this only makes sense if @path is a
 * directory.
 * 
 * The @acl parameter is the new ACL in either "long text form" or "short
 * text form" (see acl(5)). The new ACL completely replaces any previous
 * ACL on the file. The ACL must contain the full Unix permissions (eg.
 * "u::rwx,g::rx,o::rx").
 * 
 * If you are specifying individual users or groups, then the mask field is
 * also required (eg. "m::rwx"), followed by the "u:*ID*:..." and/or
 * "g:*ID*:..." field(s). A full ACL string might therefore look like this:
 * 
 * <![CDATA[u::rwx,g::rwx,o::rwx,m::rwx,u:500:rwx,g:500:rwx]]>
 * 
 * <![CDATA[\ Unix permissions / \mask/ \      ACL        /]]>
 * 
 * You should use numeric UIDs and GIDs. To map usernames and groupnames to
 * the correct numeric ID in the context of the guest, use the Augeas
 * functions (see guestfs_session_aug_init()).
 * 
 * Returns: true on success, false on error
 * Since: 1.19.63
 */
gboolean
guestfs_session_acl_set_file (GuestfsSession *session, const gchar *path, const gchar *acltype, const gchar *acl, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "acl_set_file");
    return FALSE;
  }

  int ret = guestfs_acl_set_file (g, path, acltype, acl);
  if (ret == -1) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return FALSE;
  }

  return TRUE;
}

/**
 * guestfs_session_add_cdrom:
 * @session: (transfer none): A GuestfsSession object
 * @filename: (transfer none) (type utf8):
 * @err: A GError object to receive any generated errors
 *
 * add a CD-ROM disk image to examine
 *
 * This function adds a virtual CD-ROM disk image to the guest.
 * 
 * The image is added as read-only drive, so this function is equivalent of
 * guestfs_session_add_drive_ro().
 * 
 * Returns: true on success, false on error
 * Deprecated: In new code, use guestfs_session_add_drive_ro() instead
 * Since: 0.3
 */
gboolean
guestfs_session_add_cdrom (GuestfsSession *session, const gchar *filename, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "add_cdrom");
    return FALSE;
  }

  int ret = guestfs_add_cdrom (g, filename);
  if (ret == -1) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return FALSE;
  }

  return TRUE;
}

/**
 * guestfs_session_add_domain:
 * @session: (transfer none): A GuestfsSession object
 * @dom: (transfer none) (type utf8):
 * @optargs: (transfer none) (allow-none): a GuestfsAddDomain containing optional arguments
 * @err: A GError object to receive any generated errors
 *
 * add the disk(s) from a named libvirt domain
 *
 * This function adds the disk(s) attached to the named libvirt domain
 * @dom. It works by connecting to libvirt, requesting the domain and
 * domain XML from libvirt, parsing it for disks, and calling
 * guestfs_session_add_drive_opts() on each one.
 * 
 * The number of disks added is returned. This operation is atomic: if an
 * error is returned, then no disks are added.
 * 
 * This function does some minimal checks to make sure the libvirt domain
 * is not running (unless @readonly is true). In a future version we will
 * try to acquire the libvirt lock on each disk.
 * 
 * Disks must be accessible locally. This often means that adding disks
 * from a remote libvirt connection (see <ulink
 * url='http://libvirt.org/remote.html'> http://libvirt.org/remote.html
 * </ulink>) will fail unless those disks are accessible via the same
 * device path locally too.
 * 
 * The optional @libvirturi parameter sets the libvirt URI (see <ulink
 * url='http://libvirt.org/uri.html'> http://libvirt.org/uri.html
 * </ulink>). If this is not set then we connect to the default libvirt URI
 * (or one set through an environment variable, see the libvirt
 * documentation for full details).
 * 
 * The optional @live flag controls whether this call will try to connect
 * to a running virtual machine @guestfsd process if it sees a suitable
 * &lt;channel&gt; element in the libvirt XML definition. The default (if
 * the flag is omitted) is never to try. See "ATTACHING TO RUNNING DAEMONS"
 * in guestfs(3) for more information.
 * 
 * If the @allowuuid flag is true (default is false) then a UUID *may* be
 * passed instead of the domain name. The @dom string is treated as a UUID
 * first and looked up, and if that lookup fails then we treat @dom as a
 * name as usual.
 * 
 * The optional @readonlydisk parameter controls what we do for disks which
 * are marked &lt;readonly/&gt; in the libvirt XML. Possible values are:
 * 
 * readonlydisk = "error"
 * If @readonly is false:
 * 
 * The whole call is aborted with an error if any disk with the
 * &lt;readonly/&gt; flag is found.
 * 
 * If @readonly is true:
 * 
 * Disks with the &lt;readonly/&gt; flag are added read-only.
 * 
 * readonlydisk = "read"
 * If @readonly is false:
 * 
 * Disks with the &lt;readonly/&gt; flag are added read-only. Other
 * disks are added read/write.
 * 
 * If @readonly is true:
 * 
 * Disks with the &lt;readonly/&gt; flag are added read-only.
 * 
 * readonlydisk = "write" (default)
 * If @readonly is false:
 * 
 * Disks with the &lt;readonly/&gt; flag are added read/write.
 * 
 * If @readonly is true:
 * 
 * Disks with the &lt;readonly/&gt; flag are added read-only.
 * 
 * readonlydisk = "ignore"
 * If @readonly is true or false:
 * 
 * Disks with the &lt;readonly/&gt; flag are skipped.
 * 
 * The other optional parameters are passed directly through to
 * guestfs_session_add_drive_opts().
 * 
 * Returns: the returned value, or -1 on error
 * Since: 1.7.4
 */
gint32
guestfs_session_add_domain (GuestfsSession *session, const gchar *dom, GuestfsAddDomain *optargs, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "add_domain");
    return -1;
  }

  struct guestfs_add_domain_argv argv;
  struct guestfs_add_domain_argv *argvp = NULL;

  if (optargs) {
    argv.bitmask = 0;

    GValue libvirturi_v = {0, };
    g_value_init (&libvirturi_v, G_TYPE_STRING);
    g_object_get_property (G_OBJECT (optargs), "libvirturi", &libvirturi_v);
    const gchar *libvirturi = g_value_get_string (&libvirturi_v);
    if (libvirturi != NULL) {
      argv.bitmask |= GUESTFS_ADD_DOMAIN_LIBVIRTURI_BITMASK;
      argv.libvirturi = libvirturi;
    }
    GValue readonly_v = {0, };
    g_value_init (&readonly_v, GUESTFS_TYPE_TRISTATE);
    g_object_get_property (G_OBJECT (optargs), "readonly", &readonly_v);
    GuestfsTristate readonly = g_value_get_enum (&readonly_v);
    if (readonly != GUESTFS_TRISTATE_NONE) {
      argv.bitmask |= GUESTFS_ADD_DOMAIN_READONLY_BITMASK;
      argv.readonly = readonly;
    }
    GValue iface_v = {0, };
    g_value_init (&iface_v, G_TYPE_STRING);
    g_object_get_property (G_OBJECT (optargs), "iface", &iface_v);
    const gchar *iface = g_value_get_string (&iface_v);
    if (iface != NULL) {
      argv.bitmask |= GUESTFS_ADD_DOMAIN_IFACE_BITMASK;
      argv.iface = iface;
    }
    GValue live_v = {0, };
    g_value_init (&live_v, GUESTFS_TYPE_TRISTATE);
    g_object_get_property (G_OBJECT (optargs), "live", &live_v);
    GuestfsTristate live = g_value_get_enum (&live_v);
    if (live != GUESTFS_TRISTATE_NONE) {
      argv.bitmask |= GUESTFS_ADD_DOMAIN_LIVE_BITMASK;
      argv.live = live;
    }
    GValue allowuuid_v = {0, };
    g_value_init (&allowuuid_v, GUESTFS_TYPE_TRISTATE);
    g_object_get_property (G_OBJECT (optargs), "allowuuid", &allowuuid_v);
    GuestfsTristate allowuuid = g_value_get_enum (&allowuuid_v);
    if (allowuuid != GUESTFS_TRISTATE_NONE) {
      argv.bitmask |= GUESTFS_ADD_DOMAIN_ALLOWUUID_BITMASK;
      argv.allowuuid = allowuuid;
    }
    GValue readonlydisk_v = {0, };
    g_value_init (&readonlydisk_v, G_TYPE_STRING);
    g_object_get_property (G_OBJECT (optargs), "readonlydisk", &readonlydisk_v);
    const gchar *readonlydisk = g_value_get_string (&readonlydisk_v);
    if (readonlydisk != NULL) {
      argv.bitmask |= GUESTFS_ADD_DOMAIN_READONLYDISK_BITMASK;
      argv.readonlydisk = readonlydisk;
    }
    GValue cachemode_v = {0, };
    g_value_init (&cachemode_v, G_TYPE_STRING);
    g_object_get_property (G_OBJECT (optargs), "cachemode", &cachemode_v);
    const gchar *cachemode = g_value_get_string (&cachemode_v);
    if (cachemode != NULL) {
      argv.bitmask |= GUESTFS_ADD_DOMAIN_CACHEMODE_BITMASK;
      argv.cachemode = cachemode;
    }
    GValue discard_v = {0, };
    g_value_init (&discard_v, G_TYPE_STRING);
    g_object_get_property (G_OBJECT (optargs), "discard", &discard_v);
    const gchar *discard = g_value_get_string (&discard_v);
    if (discard != NULL) {
      argv.bitmask |= GUESTFS_ADD_DOMAIN_DISCARD_BITMASK;
      argv.discard = discard;
    }
    GValue copyonread_v = {0, };
    g_value_init (&copyonread_v, GUESTFS_TYPE_TRISTATE);
    g_object_get_property (G_OBJECT (optargs), "copyonread", &copyonread_v);
    GuestfsTristate copyonread = g_value_get_enum (&copyonread_v);
    if (copyonread != GUESTFS_TRISTATE_NONE) {
      argv.bitmask |= GUESTFS_ADD_DOMAIN_COPYONREAD_BITMASK;
      argv.copyonread = copyonread;
    }
    argvp = &argv;
  }
  int ret = guestfs_add_domain_argv (g, dom, argvp);
  if (ret == -1) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return -1;
  }

  return ret;
}

/**
 * guestfs_session_add_drive:
 * @session: (transfer none): A GuestfsSession object
 * @filename: (transfer none) (type utf8):
 * @optargs: (transfer none) (allow-none): a GuestfsAddDrive containing optional arguments
 * @err: A GError object to receive any generated errors
 *
 * add an image to examine or modify
 *
 * This function adds a disk image called filename to the handle. filename
 * may be a regular host file or a host device.
 * 
 * When this function is called before guestfs_session_launch() (the usual
 * case) then the first time you call this function, the disk appears in
 * the API as /dev/sda, the second time as /dev/sdb, and so on.
 * 
 * In libguestfs &ge; 1.20 you can also call this function after launch
 * (with some restrictions). This is called "hotplugging". When
 * hotplugging, you must specify a @label so that the new disk gets a
 * predictable name. For more information see "HOTPLUGGING" in guestfs(3).
 * 
 * You don't necessarily need to be root when using libguestfs. However you
 * obviously do need sufficient permissions to access the filename for
 * whatever operations you want to perform (ie. read access if you just
 * want to read the image or write access if you want to modify the image).
 * 
 * This call checks that filename exists.
 * 
 * filename may be the special string "/dev/null". See "NULL DISKS" in
 * guestfs(3).
 * 
 * The optional arguments are:
 * 
 * @readonly
 * If true then the image is treated as read-only. Writes are still
 * allowed, but they are stored in a temporary snapshot overlay which
 * is discarded at the end. The disk that you add is not modified.
 * 
 * @format
 * This forces the image format. If you omit this (or use
 * guestfs_session_add_drive() or guestfs_session_add_drive_ro()) then
 * the format is automatically detected. Possible formats include @raw
 * and @qcow2.
 * 
 * Automatic detection of the format opens you up to a potential
 * security hole when dealing with untrusted raw-format images. See
 * CVE-2010-3851 and <ulink
 * url='https://bugzilla.redhat.com/show_bug.cgi?id=642934'>
 * RHBZ&num;642934 </ulink>. Specifying the format closes this security
 * hole.
 * 
 * @iface
 * This rarely-used option lets you emulate the behaviour of the
 * deprecated guestfs_session_add_drive_with_if() call (q.v.)
 * 
 * @name
 * The name the drive had in the original guest, e.g. /dev/sdb. This is
 * used as a hint to the guest inspection process if it is available.
 * 
 * @label
 * Give the disk a label. The label should be a unique, short string
 * using *only* ASCII characters "[a-zA-Z]". As well as its usual name
 * in the API (such as /dev/sda), the drive will also be named
 * /dev/disk/guestfs/*label*.
 * 
 * See "DISK LABELS" in guestfs(3).
 * 
 * @protocol
 * The optional protocol argument can be used to select an alternate
 * source protocol.
 * 
 * See also: "REMOTE STORAGE" in guestfs(3).
 * 
 * "protocol = "file""
 * filename is interpreted as a local file or device. This is the
 * default if the optional protocol parameter is omitted.
 * 
 * "protocol = "ftp"|"ftps"|"http"|"https"|"tftp""
 * Connect to a remote FTP, HTTP or TFTP server. The @server
 * parameter must also be supplied - see below.
 * 
 * See also: "FTP, HTTP AND TFTP" in guestfs(3)
 * 
 * "protocol = "gluster""
 * Connect to the GlusterFS server. The @server parameter must also
 * be supplied - see below.
 * 
 * See also: "GLUSTER" in guestfs(3)
 * 
 * "protocol = "iscsi""
 * Connect to the iSCSI server. The @server parameter must also be
 * supplied - see below.
 * 
 * See also: "ISCSI" in guestfs(3).
 * 
 * "protocol = "nbd""
 * Connect to the Network Block Device server. The @server
 * parameter must also be supplied - see below.
 * 
 * See also: "NETWORK BLOCK DEVICE" in guestfs(3).
 * 
 * "protocol = "rbd""
 * Connect to the Ceph (librbd/RBD) server. The @server parameter
 * must also be supplied - see below. The @username parameter may
 * be supplied. See below. The @secret parameter may be supplied.
 * See below.
 * 
 * See also: "CEPH" in guestfs(3).
 * 
 * "protocol = "sheepdog""
 * Connect to the Sheepdog server. The @server parameter may also
 * be supplied - see below.
 * 
 * See also: "SHEEPDOG" in guestfs(3).
 * 
 * "protocol = "ssh""
 * Connect to the Secure Shell (ssh) server.
 * 
 * The @server parameter must be supplied. The @username parameter
 * may be supplied. See below.
 * 
 * See also: "SSH" in guestfs(3).
 * 
 * @server
 * For protocols which require access to a remote server, this is a
 * list of server(s).
 * 
 * <![CDATA[Protocol       Number of servers required]]>
 * 
 * <![CDATA[--------       --------------------------]]>
 * 
 * <![CDATA[file           List must be empty or param not used at all]]>
 * 
 * <![CDATA[ftp|ftps|http|https|tftp  Exactly one]]>
 * 
 * <![CDATA[gluster        Exactly one]]>
 * 
 * <![CDATA[iscsi          Exactly one]]>
 * 
 * <![CDATA[nbd            Exactly one]]>
 * 
 * <![CDATA[rbd            Zero or more]]>
 * 
 * <![CDATA[sheepdog       Zero or more]]>
 * 
 * <![CDATA[ssh            Exactly one]]>
 * 
 * Each list element is a string specifying a server. The string must
 * be in one of the following formats:
 * 
 * <![CDATA[hostname]]>
 * 
 * <![CDATA[hostname:port]]>
 * 
 * <![CDATA[tcp:hostname]]>
 * 
 * <![CDATA[tcp:hostname:port]]>
 * 
 * <![CDATA[unix:/path/to/socket]]>
 * 
 * If the port number is omitted, then the standard port number for the
 * protocol is used (see /etc/services).
 * 
 * @username
 * For the @ftp, @ftps, @http, @https, @iscsi, @rbd, @ssh and @tftp
 * protocols, this specifies the remote username.
 * 
 * If not given, then the local username is used for @ssh, and no
 * authentication is attempted for ceph. But note this sometimes may
 * give unexpected results, for example if using the libvirt backend
 * and if the libvirt backend is configured to start the qemu appliance
 * as a special user such as "qemu.qemu". If in doubt, specify the
 * remote username you want.
 * 
 * @secret
 * For the @rbd protocol only, this specifies the 'secret' to use when
 * connecting to the remote device. It must be base64 encoded.
 * 
 * If not given, then a secret matching the given username will be
 * looked up in the default keychain locations, or if no username is
 * given, then no authentication will be used.
 * 
 * @cachemode
 * Choose whether or not libguestfs will obey sync operations (safe but
 * slow) or not (unsafe but fast). The possible values for this string
 * are:
 * 
 * "cachemode = "writeback""
 * This is the default.
 * 
 * Write operations in the API do not return until a write(2) call
 * has completed in the host [but note this does not imply that
 * anything gets written to disk].
 * 
 * Sync operations in the API, including implicit syncs caused by
 * filesystem journalling, will not return until an fdatasync(2)
 * call has completed in the host, indicating that data has been
 * committed to disk.
 * 
 * "cachemode = "unsafe""
 * In this mode, there are no guarantees. Libguestfs may cache
 * anything and ignore sync requests. This is suitable only for
 * scratch or temporary disks.
 * 
 * @discard
 * Enable or disable discard (a.k.a. trim or unmap) support on this
 * drive. If enabled, operations such as guestfs_session_fstrim() will
 * be able to discard / make thin / punch holes in the underlying host
 * file or device.
 * 
 * Possible discard settings are:
 * 
 * "discard = "disable""
 * Disable discard support. This is the default.
 * 
 * "discard = "enable""
 * Enable discard support. Fail if discard is not possible.
 * 
 * "discard = "besteffort""
 * Enable discard support if possible, but don't fail if it is not
 * supported.
 * 
 * Since not all backends and not all underlying systems support
 * discard, this is a good choice if you want to use discard if
 * possible, but don't mind if it doesn't work.
 * 
 * @copyonread
 * The boolean parameter @copyonread enables copy-on-read support. This
 * only affects disk formats which have backing files, and causes reads
 * to be stored in the overlay layer, speeding up multiple reads of the
 * same area of disk.
 * 
 * The default is false.
 * 
 * Returns: true on success, false on error
 * Since: 0.3
 */
gboolean
guestfs_session_add_drive (GuestfsSession *session, const gchar *filename, GuestfsAddDrive *optargs, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "add_drive");
    return FALSE;
  }

  struct guestfs_add_drive_opts_argv argv;
  struct guestfs_add_drive_opts_argv *argvp = NULL;

  if (optargs) {
    argv.bitmask = 0;

    GValue readonly_v = {0, };
    g_value_init (&readonly_v, GUESTFS_TYPE_TRISTATE);
    g_object_get_property (G_OBJECT (optargs), "readonly", &readonly_v);
    GuestfsTristate readonly = g_value_get_enum (&readonly_v);
    if (readonly != GUESTFS_TRISTATE_NONE) {
      argv.bitmask |= GUESTFS_ADD_DRIVE_OPTS_READONLY_BITMASK;
      argv.readonly = readonly;
    }
    GValue format_v = {0, };
    g_value_init (&format_v, G_TYPE_STRING);
    g_object_get_property (G_OBJECT (optargs), "format", &format_v);
    const gchar *format = g_value_get_string (&format_v);
    if (format != NULL) {
      argv.bitmask |= GUESTFS_ADD_DRIVE_OPTS_FORMAT_BITMASK;
      argv.format = format;
    }
    GValue iface_v = {0, };
    g_value_init (&iface_v, G_TYPE_STRING);
    g_object_get_property (G_OBJECT (optargs), "iface", &iface_v);
    const gchar *iface = g_value_get_string (&iface_v);
    if (iface != NULL) {
      argv.bitmask |= GUESTFS_ADD_DRIVE_OPTS_IFACE_BITMASK;
      argv.iface = iface;
    }
    GValue name_v = {0, };
    g_value_init (&name_v, G_TYPE_STRING);
    g_object_get_property (G_OBJECT (optargs), "name", &name_v);
    const gchar *name = g_value_get_string (&name_v);
    if (name != NULL) {
      argv.bitmask |= GUESTFS_ADD_DRIVE_OPTS_NAME_BITMASK;
      argv.name = name;
    }
    GValue label_v = {0, };
    g_value_init (&label_v, G_TYPE_STRING);
    g_object_get_property (G_OBJECT (optargs), "label", &label_v);
    const gchar *label = g_value_get_string (&label_v);
    if (label != NULL) {
      argv.bitmask |= GUESTFS_ADD_DRIVE_OPTS_LABEL_BITMASK;
      argv.label = label;
    }
    GValue protocol_v = {0, };
    g_value_init (&protocol_v, G_TYPE_STRING);
    g_object_get_property (G_OBJECT (optargs), "protocol", &protocol_v);
    const gchar *protocol = g_value_get_string (&protocol_v);
    if (protocol != NULL) {
      argv.bitmask |= GUESTFS_ADD_DRIVE_OPTS_PROTOCOL_BITMASK;
      argv.protocol = protocol;
    }
    GValue username_v = {0, };
    g_value_init (&username_v, G_TYPE_STRING);
    g_object_get_property (G_OBJECT (optargs), "username", &username_v);
    const gchar *username = g_value_get_string (&username_v);
    if (username != NULL) {
      argv.bitmask |= GUESTFS_ADD_DRIVE_OPTS_USERNAME_BITMASK;
      argv.username = username;
    }
    GValue secret_v = {0, };
    g_value_init (&secret_v, G_TYPE_STRING);
    g_object_get_property (G_OBJECT (optargs), "secret", &secret_v);
    const gchar *secret = g_value_get_string (&secret_v);
    if (secret != NULL) {
      argv.bitmask |= GUESTFS_ADD_DRIVE_OPTS_SECRET_BITMASK;
      argv.secret = secret;
    }
    GValue cachemode_v = {0, };
    g_value_init (&cachemode_v, G_TYPE_STRING);
    g_object_get_property (G_OBJECT (optargs), "cachemode", &cachemode_v);
    const gchar *cachemode = g_value_get_string (&cachemode_v);
    if (cachemode != NULL) {
      argv.bitmask |= GUESTFS_ADD_DRIVE_OPTS_CACHEMODE_BITMASK;
      argv.cachemode = cachemode;
    }
    GValue discard_v = {0, };
    g_value_init (&discard_v, G_TYPE_STRING);
    g_object_get_property (G_OBJECT (optargs), "discard", &discard_v);
    const gchar *discard = g_value_get_string (&discard_v);
    if (discard != NULL) {
      argv.bitmask |= GUESTFS_ADD_DRIVE_OPTS_DISCARD_BITMASK;
      argv.discard = discard;
    }
    GValue copyonread_v = {0, };
    g_value_init (&copyonread_v, GUESTFS_TYPE_TRISTATE);
    g_object_get_property (G_OBJECT (optargs), "copyonread", &copyonread_v);
    GuestfsTristate copyonread = g_value_get_enum (&copyonread_v);
    if (copyonread != GUESTFS_TRISTATE_NONE) {
      argv.bitmask |= GUESTFS_ADD_DRIVE_OPTS_COPYONREAD_BITMASK;
      argv.copyonread = copyonread;
    }
    argvp = &argv;
  }
  int ret = guestfs_add_drive_opts_argv (g, filename, argvp);
  if (ret == -1) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return FALSE;
  }

  return TRUE;
}

/**
 * guestfs_session_add_drive_ro:
 * @session: (transfer none): A GuestfsSession object
 * @filename: (transfer none) (type utf8):
 * @err: A GError object to receive any generated errors
 *
 * add a drive in snapshot mode (read-only)
 *
 * This function is the equivalent of calling
 * guestfs_session_add_drive_opts() with the optional parameter
 * @GUESTFS_ADD_DRIVE_OPTS_READONLY set to 1, so the disk is added
 * read-only, with the format being detected automatically.
 * 
 * Returns: true on success, false on error
 * Since: 1.0.38
 */
gboolean
guestfs_session_add_drive_ro (GuestfsSession *session, const gchar *filename, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "add_drive_ro");
    return FALSE;
  }

  int ret = guestfs_add_drive_ro (g, filename);
  if (ret == -1) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return FALSE;
  }

  return TRUE;
}

/**
 * guestfs_session_add_drive_ro_with_if:
 * @session: (transfer none): A GuestfsSession object
 * @filename: (transfer none) (type utf8):
 * @iface: (transfer none) (type utf8):
 * @err: A GError object to receive any generated errors
 *
 * add a drive read-only specifying the QEMU block emulation to use
 *
 * This is the same as guestfs_session_add_drive_ro() but it allows you to
 * specify the QEMU interface emulation to use at run time.
 * 
 * Returns: true on success, false on error
 * Deprecated: In new code, use guestfs_session_add_drive() instead
 * Since: 1.0.84
 */
gboolean
guestfs_session_add_drive_ro_with_if (GuestfsSession *session, const gchar *filename, const gchar *iface, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "add_drive_ro_with_if");
    return FALSE;
  }

  int ret = guestfs_add_drive_ro_with_if (g, filename, iface);
  if (ret == -1) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return FALSE;
  }

  return TRUE;
}

/**
 * guestfs_session_add_drive_scratch:
 * @session: (transfer none): A GuestfsSession object
 * @size: (type gint64):
 * @optargs: (transfer none) (allow-none): a GuestfsAddDriveScratch containing optional arguments
 * @err: A GError object to receive any generated errors
 *
 * add a temporary scratch drive
 *
 * This command adds a temporary scratch drive to the handle. The @size
 * parameter is the virtual size (in bytes). The scratch drive is blank
 * initially (all reads return zeroes until you start writing to it). The
 * drive is deleted when the handle is closed.
 * 
 * The optional arguments @name and @label are passed through to
 * guestfs_session_add_drive().
 * 
 * Returns: true on success, false on error
 * Since: 1.23.10
 */
gboolean
guestfs_session_add_drive_scratch (GuestfsSession *session, gint64 size, GuestfsAddDriveScratch *optargs, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "add_drive_scratch");
    return FALSE;
  }

  struct guestfs_add_drive_scratch_argv argv;
  struct guestfs_add_drive_scratch_argv *argvp = NULL;

  if (optargs) {
    argv.bitmask = 0;

    GValue name_v = {0, };
    g_value_init (&name_v, G_TYPE_STRING);
    g_object_get_property (G_OBJECT (optargs), "name", &name_v);
    const gchar *name = g_value_get_string (&name_v);
    if (name != NULL) {
      argv.bitmask |= GUESTFS_ADD_DRIVE_SCRATCH_NAME_BITMASK;
      argv.name = name;
    }
    GValue label_v = {0, };
    g_value_init (&label_v, G_TYPE_STRING);
    g_object_get_property (G_OBJECT (optargs), "label", &label_v);
    const gchar *label = g_value_get_string (&label_v);
    if (label != NULL) {
      argv.bitmask |= GUESTFS_ADD_DRIVE_SCRATCH_LABEL_BITMASK;
      argv.label = label;
    }
    argvp = &argv;
  }
  int ret = guestfs_add_drive_scratch_argv (g, size, argvp);
  if (ret == -1) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return FALSE;
  }

  return TRUE;
}

/**
 * guestfs_session_add_drive_with_if:
 * @session: (transfer none): A GuestfsSession object
 * @filename: (transfer none) (type utf8):
 * @iface: (transfer none) (type utf8):
 * @err: A GError object to receive any generated errors
 *
 * add a drive specifying the QEMU block emulation to use
 *
 * This is the same as guestfs_session_add_drive() but it allows you to
 * specify the QEMU interface emulation to use at run time.
 * 
 * Returns: true on success, false on error
 * Deprecated: In new code, use guestfs_session_add_drive() instead
 * Since: 1.0.84
 */
gboolean
guestfs_session_add_drive_with_if (GuestfsSession *session, const gchar *filename, const gchar *iface, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "add_drive_with_if");
    return FALSE;
  }

  int ret = guestfs_add_drive_with_if (g, filename, iface);
  if (ret == -1) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return FALSE;
  }

  return TRUE;
}

/**
 * guestfs_session_add_libvirt_dom:
 * @session: (transfer none): A GuestfsSession object
 * @dom:pointer (not implemented in gobject bindings)
 * @optargs: (transfer none) (allow-none): a GuestfsAddLibvirtDom containing optional arguments
 * @err: A GError object to receive any generated errors
 *
 * add the disk(s) from a libvirt domain
 *
 * This function adds the disk(s) attached to the libvirt domain @dom. It
 * works by requesting the domain XML from libvirt, parsing it for disks,
 * and calling guestfs_session_add_drive_opts() on each one.
 * 
 * In the C API we declare "void *dom", but really it has type
 * "virDomainPtr dom". This is so we don't need &lt;libvirt.h&gt;.
 * 
 * The number of disks added is returned. This operation is atomic: if an
 * error is returned, then no disks are added.
 * 
 * This function does some minimal checks to make sure the libvirt domain
 * is not running (unless @readonly is true). In a future version we will
 * try to acquire the libvirt lock on each disk.
 * 
 * Disks must be accessible locally. This often means that adding disks
 * from a remote libvirt connection (see <ulink
 * url='http://libvirt.org/remote.html'> http://libvirt.org/remote.html
 * </ulink>) will fail unless those disks are accessible via the same
 * device path locally too.
 * 
 * The optional @live flag controls whether this call will try to connect
 * to a running virtual machine @guestfsd process if it sees a suitable
 * &lt;channel&gt; element in the libvirt XML definition. The default (if
 * the flag is omitted) is never to try. See "ATTACHING TO RUNNING DAEMONS"
 * in guestfs(3) for more information.
 * 
 * The optional @readonlydisk parameter controls what we do for disks which
 * are marked &lt;readonly/&gt; in the libvirt XML. See
 * guestfs_session_add_domain() for possible values.
 * 
 * The other optional parameters are passed directly through to
 * guestfs_session_add_drive_opts().
 * 
 * Returns: the returned value, or -1 on error
 * Since: 1.29.14
 */
gint32
guestfs_session_add_libvirt_dom (GuestfsSession *session, void * /* virDomainPtr */ dom, GuestfsAddLibvirtDom *optargs, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "add_libvirt_dom");
    return -1;
  }

  struct guestfs_add_libvirt_dom_argv argv;
  struct guestfs_add_libvirt_dom_argv *argvp = NULL;

  if (optargs) {
    argv.bitmask = 0;

    GValue readonly_v = {0, };
    g_value_init (&readonly_v, GUESTFS_TYPE_TRISTATE);
    g_object_get_property (G_OBJECT (optargs), "readonly", &readonly_v);
    GuestfsTristate readonly = g_value_get_enum (&readonly_v);
    if (readonly != GUESTFS_TRISTATE_NONE) {
      argv.bitmask |= GUESTFS_ADD_LIBVIRT_DOM_READONLY_BITMASK;
      argv.readonly = readonly;
    }
    GValue iface_v = {0, };
    g_value_init (&iface_v, G_TYPE_STRING);
    g_object_get_property (G_OBJECT (optargs), "iface", &iface_v);
    const gchar *iface = g_value_get_string (&iface_v);
    if (iface != NULL) {
      argv.bitmask |= GUESTFS_ADD_LIBVIRT_DOM_IFACE_BITMASK;
      argv.iface = iface;
    }
    GValue live_v = {0, };
    g_value_init (&live_v, GUESTFS_TYPE_TRISTATE);
    g_object_get_property (G_OBJECT (optargs), "live", &live_v);
    GuestfsTristate live = g_value_get_enum (&live_v);
    if (live != GUESTFS_TRISTATE_NONE) {
      argv.bitmask |= GUESTFS_ADD_LIBVIRT_DOM_LIVE_BITMASK;
      argv.live = live;
    }
    GValue readonlydisk_v = {0, };
    g_value_init (&readonlydisk_v, G_TYPE_STRING);
    g_object_get_property (G_OBJECT (optargs), "readonlydisk", &readonlydisk_v);
    const gchar *readonlydisk = g_value_get_string (&readonlydisk_v);
    if (readonlydisk != NULL) {
      argv.bitmask |= GUESTFS_ADD_LIBVIRT_DOM_READONLYDISK_BITMASK;
      argv.readonlydisk = readonlydisk;
    }
    GValue cachemode_v = {0, };
    g_value_init (&cachemode_v, G_TYPE_STRING);
    g_object_get_property (G_OBJECT (optargs), "cachemode", &cachemode_v);
    const gchar *cachemode = g_value_get_string (&cachemode_v);
    if (cachemode != NULL) {
      argv.bitmask |= GUESTFS_ADD_LIBVIRT_DOM_CACHEMODE_BITMASK;
      argv.cachemode = cachemode;
    }
    GValue discard_v = {0, };
    g_value_init (&discard_v, G_TYPE_STRING);
    g_object_get_property (G_OBJECT (optargs), "discard", &discard_v);
    const gchar *discard = g_value_get_string (&discard_v);
    if (discard != NULL) {
      argv.bitmask |= GUESTFS_ADD_LIBVIRT_DOM_DISCARD_BITMASK;
      argv.discard = discard;
    }
    GValue copyonread_v = {0, };
    g_value_init (&copyonread_v, GUESTFS_TYPE_TRISTATE);
    g_object_get_property (G_OBJECT (optargs), "copyonread", &copyonread_v);
    GuestfsTristate copyonread = g_value_get_enum (&copyonread_v);
    if (copyonread != GUESTFS_TRISTATE_NONE) {
      argv.bitmask |= GUESTFS_ADD_LIBVIRT_DOM_COPYONREAD_BITMASK;
      argv.copyonread = copyonread;
    }
    argvp = &argv;
  }
  int ret = guestfs_add_libvirt_dom_argv (g, dom, argvp);
  if (ret == -1) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return -1;
  }

  return ret;
}

/**
 * guestfs_session_aug_clear:
 * @session: (transfer none): A GuestfsSession object
 * @augpath: (transfer none) (type utf8):
 * @err: A GError object to receive any generated errors
 *
 * clear Augeas path
 *
 * Set the value associated with @path to @NULL. This is the same as the
 * augtool(1) @clear command.
 * 
 * Returns: true on success, false on error
 * Since: 1.3.4
 */
gboolean
guestfs_session_aug_clear (GuestfsSession *session, const gchar *augpath, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "aug_clear");
    return FALSE;
  }

  int ret = guestfs_aug_clear (g, augpath);
  if (ret == -1) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return FALSE;
  }

  return TRUE;
}

/**
 * guestfs_session_aug_close:
 * @session: (transfer none): A GuestfsSession object
 * @err: A GError object to receive any generated errors
 *
 * close the current Augeas handle
 *
 * Close the current Augeas handle and free up any resources used by it.
 * After calling this, you have to call guestfs_session_aug_init() again
 * before you can use any other Augeas functions.
 * 
 * Returns: true on success, false on error
 * Since: 0.7
 */
gboolean
guestfs_session_aug_close (GuestfsSession *session, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "aug_close");
    return FALSE;
  }

  int ret = guestfs_aug_close (g);
  if (ret == -1) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return FALSE;
  }

  return TRUE;
}

/**
 * guestfs_session_aug_defnode:
 * @session: (transfer none): A GuestfsSession object
 * @name: (transfer none) (type utf8):
 * @expr: (transfer none) (type utf8):
 * @val: (transfer none) (type utf8):
 * @err: A GError object to receive any generated errors
 *
 * define an Augeas node
 *
 * Defines a variable @name whose value is the result of evaluating @expr.
 * 
 * If @expr evaluates to an empty nodeset, a node is created, equivalent to
 * calling guestfs_session_aug_set() @expr, @value. @name will be the
 * nodeset containing that single node.
 * 
 * On success this returns a pair containing the number of nodes in the
 * nodeset, and a boolean flag if a node was created.
 * 
 * Returns: (transfer full): a IntBool object, or NULL on error
 * Since: 0.7
 */
GuestfsIntBool *
guestfs_session_aug_defnode (GuestfsSession *session, const gchar *name, const gchar *expr, const gchar *val, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "aug_defnode");
    return NULL;
  }

  struct guestfs_int_bool *ret = guestfs_aug_defnode (g, name, expr, val);
  if (ret == NULL) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return NULL;
  }

  GuestfsIntBool *s = g_slice_new0 (GuestfsIntBool);
  s->i = ret->i;
  s->b = ret->b;
  guestfs_free_int_bool (ret);
  return s;
}

/**
 * guestfs_session_aug_defvar:
 * @session: (transfer none): A GuestfsSession object
 * @name: (transfer none) (type utf8):
 * @expr: (transfer none) (type utf8) (allow-none):
 * @err: A GError object to receive any generated errors
 *
 * define an Augeas variable
 *
 * Defines an Augeas variable @name whose value is the result of evaluating
 * @expr. If @expr is NULL, then @name is undefined.
 * 
 * On success this returns the number of nodes in @expr, or @0 if @expr
 * evaluates to something which is not a nodeset.
 * 
 * Returns: the returned value, or -1 on error
 * Since: 0.7
 */
gint32
guestfs_session_aug_defvar (GuestfsSession *session, const gchar *name, const gchar *expr, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "aug_defvar");
    return -1;
  }

  int ret = guestfs_aug_defvar (g, name, expr);
  if (ret == -1) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return -1;
  }

  return ret;
}

/**
 * guestfs_session_aug_get:
 * @session: (transfer none): A GuestfsSession object
 * @augpath: (transfer none) (type utf8):
 * @err: A GError object to receive any generated errors
 *
 * look up the value of an Augeas path
 *
 * Look up the value associated with @path. If @path matches exactly one
 * node, the @value is returned.
 * 
 * Returns: (transfer full): the returned string, or NULL on error
 * Since: 0.7
 */
gchar *
guestfs_session_aug_get (GuestfsSession *session, const gchar *augpath, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "aug_get");
    return NULL;
  }

  char *ret = guestfs_aug_get (g, augpath);
  if (ret == NULL) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return NULL;
  }

  return ret;
}

/**
 * guestfs_session_aug_init:
 * @session: (transfer none): A GuestfsSession object
 * @root: (transfer none) (type filename):
 * @flags: (type gint32):
 * @err: A GError object to receive any generated errors
 *
 * create a new Augeas handle
 *
 * Create a new Augeas handle for editing configuration files. If there was
 * any previous Augeas handle associated with this guestfs session, then it
 * is closed.
 * 
 * You must call this before using any other "guestfs_aug_*" commands.
 * 
 * @root is the filesystem root. @root must not be NULL, use / instead.
 * 
 * The flags are the same as the flags defined in &lt;augeas.h&gt;, the
 * logical *or* of the following integers:
 * 
 * @AUG_SAVE_BACKUP = 1
 * Keep the original file with a ".augsave" extension.
 * 
 * @AUG_SAVE_NEWFILE = 2
 * Save changes into a file with extension ".augnew", and do not
 * overwrite original. Overrides @AUG_SAVE_BACKUP.
 * 
 * @AUG_TYPE_CHECK = 4
 * Typecheck lenses.
 * 
 * This option is only useful when debugging Augeas lenses. Use of this
 * option may require additional memory for the libguestfs appliance.
 * You may need to set the @LIBGUESTFS_MEMSIZE environment variable or
 * call guestfs_session_set_memsize().
 * 
 * @AUG_NO_STDINC = 8
 * Do not use standard load path for modules.
 * 
 * @AUG_SAVE_NOOP = 16
 * Make save a no-op, just record what would have been changed.
 * 
 * @AUG_NO_LOAD = 32
 * Do not load the tree in guestfs_session_aug_init().
 * 
 * To close the handle, you can call guestfs_session_aug_close().
 * 
 * To find out more about Augeas, see <ulink url='http://augeas.net/'>
 * http://augeas.net/ </ulink>.
 * 
 * Returns: true on success, false on error
 * Since: 0.7
 */
gboolean
guestfs_session_aug_init (GuestfsSession *session, const gchar *root, gint32 flags, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "aug_init");
    return FALSE;
  }

  int ret = guestfs_aug_init (g, root, flags);
  if (ret == -1) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return FALSE;
  }

  return TRUE;
}

/**
 * guestfs_session_aug_insert:
 * @session: (transfer none): A GuestfsSession object
 * @augpath: (transfer none) (type utf8):
 * @label: (transfer none) (type utf8):
 * @before: (type gboolean):
 * @err: A GError object to receive any generated errors
 *
 * insert a sibling Augeas node
 *
 * Create a new sibling @label for @path, inserting it into the tree before
 * or after @path (depending on the boolean flag @before).
 * 
 * @path must match exactly one existing node in the tree, and @label must
 * be a label, ie. not contain /, "*" or end with a bracketed index "[N]".
 * 
 * Returns: true on success, false on error
 * Since: 0.7
 */
gboolean
guestfs_session_aug_insert (GuestfsSession *session, const gchar *augpath, const gchar *label, gboolean before, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "aug_insert");
    return FALSE;
  }

  int ret = guestfs_aug_insert (g, augpath, label, before);
  if (ret == -1) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return FALSE;
  }

  return TRUE;
}

/**
 * guestfs_session_aug_label:
 * @session: (transfer none): A GuestfsSession object
 * @augpath: (transfer none) (type utf8):
 * @err: A GError object to receive any generated errors
 *
 * return the label from an Augeas path expression
 *
 * The label (name of the last element) of the Augeas path expression
 * @augpath is returned. @augpath must match exactly one node, else this
 * function returns an error.
 * 
 * Returns: (transfer full): the returned string, or NULL on error
 * Since: 1.23.14
 */
gchar *
guestfs_session_aug_label (GuestfsSession *session, const gchar *augpath, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "aug_label");
    return NULL;
  }

  char *ret = guestfs_aug_label (g, augpath);
  if (ret == NULL) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return NULL;
  }

  return ret;
}

/**
 * guestfs_session_aug_load:
 * @session: (transfer none): A GuestfsSession object
 * @err: A GError object to receive any generated errors
 *
 * load files into the tree
 *
 * Load files into the tree.
 * 
 * See @aug_load in the Augeas documentation for the full gory details.
 * 
 * Returns: true on success, false on error
 * Since: 0.7
 */
gboolean
guestfs_session_aug_load (GuestfsSession *session, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "aug_load");
    return FALSE;
  }

  int ret = guestfs_aug_load (g);
  if (ret == -1) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return FALSE;
  }

  return TRUE;
}

/**
 * guestfs_session_aug_ls:
 * @session: (transfer none): A GuestfsSession object
 * @augpath: (transfer none) (type utf8):
 * @err: A GError object to receive any generated errors
 *
 * list Augeas nodes under augpath
 *
 * This is just a shortcut for listing guestfs_session_aug_match() "path/*"
 * and sorting the resulting nodes into alphabetical order.
 * 
 * Returns: (transfer full) (array zero-terminated=1) (element-type utf8): an array of returned strings, or NULL on error
 * Since: 0.8
 */
gchar **
guestfs_session_aug_ls (GuestfsSession *session, const gchar *augpath, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "aug_ls");
    return NULL;
  }

  char **ret = guestfs_aug_ls (g, augpath);
  if (ret == NULL) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return NULL;
  }

  return ret;
}

/**
 * guestfs_session_aug_match:
 * @session: (transfer none): A GuestfsSession object
 * @augpath: (transfer none) (type utf8):
 * @err: A GError object to receive any generated errors
 *
 * return Augeas nodes which match augpath
 *
 * Returns a list of paths which match the path expression @path. The
 * returned paths are sufficiently qualified so that they match exactly one
 * node in the current tree.
 * 
 * Returns: (transfer full) (array zero-terminated=1) (element-type utf8): an array of returned strings, or NULL on error
 * Since: 0.7
 */
gchar **
guestfs_session_aug_match (GuestfsSession *session, const gchar *augpath, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "aug_match");
    return NULL;
  }

  char **ret = guestfs_aug_match (g, augpath);
  if (ret == NULL) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return NULL;
  }

  return ret;
}

/**
 * guestfs_session_aug_mv:
 * @session: (transfer none): A GuestfsSession object
 * @src: (transfer none) (type utf8):
 * @dest: (transfer none) (type utf8):
 * @err: A GError object to receive any generated errors
 *
 * move Augeas node
 *
 * Move the node @src to @dest. @src must match exactly one node. @dest is
 * overwritten if it exists.
 * 
 * Returns: true on success, false on error
 * Since: 0.7
 */
gboolean
guestfs_session_aug_mv (GuestfsSession *session, const gchar *src, const gchar *dest, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "aug_mv");
    return FALSE;
  }

  int ret = guestfs_aug_mv (g, src, dest);
  if (ret == -1) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return FALSE;
  }

  return TRUE;
}

/**
 * guestfs_session_aug_rm:
 * @session: (transfer none): A GuestfsSession object
 * @augpath: (transfer none) (type utf8):
 * @err: A GError object to receive any generated errors
 *
 * remove an Augeas path
 *
 * Remove @path and all of its children.
 * 
 * On success this returns the number of entries which were removed.
 * 
 * Returns: the returned value, or -1 on error
 * Since: 0.7
 */
gint32
guestfs_session_aug_rm (GuestfsSession *session, const gchar *augpath, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "aug_rm");
    return -1;
  }

  int ret = guestfs_aug_rm (g, augpath);
  if (ret == -1) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return -1;
  }

  return ret;
}

/**
 * guestfs_session_aug_save:
 * @session: (transfer none): A GuestfsSession object
 * @err: A GError object to receive any generated errors
 *
 * write all pending Augeas changes to disk
 *
 * This writes all pending changes to disk.
 * 
 * The flags which were passed to guestfs_session_aug_init() affect exactly
 * how files are saved.
 * 
 * Returns: true on success, false on error
 * Since: 0.7
 */
gboolean
guestfs_session_aug_save (GuestfsSession *session, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "aug_save");
    return FALSE;
  }

  int ret = guestfs_aug_save (g);
  if (ret == -1) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return FALSE;
  }

  return TRUE;
}

/**
 * guestfs_session_aug_set:
 * @session: (transfer none): A GuestfsSession object
 * @augpath: (transfer none) (type utf8):
 * @val: (transfer none) (type utf8):
 * @err: A GError object to receive any generated errors
 *
 * set Augeas path to value
 *
 * Set the value associated with @path to @val.
 * 
 * In the Augeas API, it is possible to clear a node by setting the value
 * to NULL. Due to an oversight in the libguestfs API you cannot do that
 * with this call. Instead you must use the guestfs_session_aug_clear()
 * call.
 * 
 * Returns: true on success, false on error
 * Since: 0.7
 */
gboolean
guestfs_session_aug_set (GuestfsSession *session, const gchar *augpath, const gchar *val, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "aug_set");
    return FALSE;
  }

  int ret = guestfs_aug_set (g, augpath, val);
  if (ret == -1) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return FALSE;
  }

  return TRUE;
}

/**
 * guestfs_session_aug_setm:
 * @session: (transfer none): A GuestfsSession object
 * @base: (transfer none) (type utf8):
 * @sub: (transfer none) (type utf8) (allow-none):
 * @val: (transfer none) (type utf8):
 * @err: A GError object to receive any generated errors
 *
 * set multiple Augeas nodes
 *
 * Change multiple Augeas nodes in a single operation. @base is an
 * expression matching multiple nodes. @sub is a path expression relative
 * to @base. All nodes matching @base are found, and then for each node,
 * @sub is changed to @val. @sub may also be @NULL in which case the @base
 * nodes are modified.
 * 
 * This returns the number of nodes modified.
 * 
 * Returns: the returned value, or -1 on error
 * Since: 1.23.14
 */
gint32
guestfs_session_aug_setm (GuestfsSession *session, const gchar *base, const gchar *sub, const gchar *val, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "aug_setm");
    return -1;
  }

  int ret = guestfs_aug_setm (g, base, sub, val);
  if (ret == -1) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return -1;
  }

  return ret;
}

/**
 * guestfs_session_available:
 * @session: (transfer none): A GuestfsSession object
 * @groups: (transfer none) (array zero-terminated=1) (element-type utf8): an array of strings
 * @err: A GError object to receive any generated errors
 *
 * test availability of some parts of the API
 *
 * This command is used to check the availability of some groups of
 * functionality in the appliance, which not all builds of the libguestfs
 * appliance will be able to provide.
 * 
 * The libguestfs groups, and the functions that those groups correspond
 * to, are listed in "AVAILABILITY" in guestfs(3). You can also fetch this
 * list at runtime by calling guestfs_session_available_all_groups().
 * 
 * The argument @groups is a list of group names, eg: "["inotify",
 * "augeas"]" would check for the availability of the Linux inotify
 * functions and Augeas (configuration file editing) functions.
 * 
 * The command returns no error if *all* requested groups are available.
 * 
 * It fails with an error if one or more of the requested groups is
 * unavailable in the appliance.
 * 
 * If an unknown group name is included in the list of groups then an error
 * is always returned.
 * 
 * *Notes:*
 * 
 * *   guestfs_session_feature_available() is the same as this call, but
 * with a slightly simpler to use API: that call returns a boolean
 * true/false instead of throwing an error.
 * 
 * *   You must call guestfs_session_launch() before calling this function.
 * 
 * The reason is because we don't know what groups are supported by the
 * appliance/daemon until it is running and can be queried.
 * 
 * *   If a group of functions is available, this does not necessarily mean
 * that they will work. You still have to check for errors when calling
 * individual API functions even if they are available.
 * 
 * *   It is usually the job of distro packagers to build complete
 * functionality into the libguestfs appliance. Upstream libguestfs, if
 * built from source with all requirements satisfied, will support
 * everything.
 * 
 * *   This call was added in version 1.0.80. In previous versions of
 * libguestfs all you could do would be to speculatively execute a
 * command to find out if the daemon implemented it. See also
 * guestfs_session_version().
 * 
 * See also guestfs_session_filesystem_available().
 * 
 * Returns: true on success, false on error
 * Since: 1.0.80
 */
gboolean
guestfs_session_available (GuestfsSession *session, gchar *const *groups, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "available");
    return FALSE;
  }

  int ret = guestfs_available (g, groups);
  if (ret == -1) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return FALSE;
  }

  return TRUE;
}

/**
 * guestfs_session_available_all_groups:
 * @session: (transfer none): A GuestfsSession object
 * @err: A GError object to receive any generated errors
 *
 * return a list of all optional groups
 *
 * This command returns a list of all optional groups that this daemon
 * knows about. Note this returns both supported and unsupported groups. To
 * find out which ones the daemon can actually support you have to call
 * guestfs_session_available() / guestfs_session_feature_available() on
 * each member of the returned list.
 * 
 * See also guestfs_session_available(),
 * guestfs_session_feature_available() and "AVAILABILITY" in guestfs(3).
 * 
 * Returns: (transfer full) (array zero-terminated=1) (element-type utf8): an array of returned strings, or NULL on error
 * Since: 1.3.15
 */
gchar **
guestfs_session_available_all_groups (GuestfsSession *session, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "available_all_groups");
    return NULL;
  }

  char **ret = guestfs_available_all_groups (g);
  if (ret == NULL) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return NULL;
  }

  return ret;
}

/**
 * guestfs_session_base64_in:
 * @session: (transfer none): A GuestfsSession object
 * @base64file: (transfer none) (type filename):
 * @filename: (transfer none) (type filename):
 * @cancellable: A GCancellable object
 * @err: A GError object to receive any generated errors
 *
 * upload base64-encoded data to file
 *
 * This command uploads base64-encoded data from @base64file to filename.
 * 
 * Returns: true on success, false on error
 * Since: 1.3.5
 */
gboolean
guestfs_session_base64_in (GuestfsSession *session, const gchar *base64file, const gchar *filename, GCancellable *cancellable, GError **err)
{
  /* Check we haven't already been cancelled */
  if (g_cancellable_set_error_if_cancelled (cancellable, err))
    return FALSE;

  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "base64_in");
    return FALSE;
  }

  gulong id = 0;
  if (cancellable) {
    id = g_cancellable_connect (cancellable,
                               G_CALLBACK (cancelled_handler),
                               g, NULL);
  }

  int ret = guestfs_base64_in (g, base64file, filename);
  g_cancellable_disconnect (cancellable, id);
  if (ret == -1) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return FALSE;
  }

  return TRUE;
}

/**
 * guestfs_session_base64_out:
 * @session: (transfer none): A GuestfsSession object
 * @filename: (transfer none) (type filename):
 * @base64file: (transfer none) (type filename):
 * @cancellable: A GCancellable object
 * @err: A GError object to receive any generated errors
 *
 * download file and encode as base64
 *
 * This command downloads the contents of filename, writing it out to local
 * file @base64file encoded as base64.
 * 
 * Returns: true on success, false on error
 * Since: 1.3.5
 */
gboolean
guestfs_session_base64_out (GuestfsSession *session, const gchar *filename, const gchar *base64file, GCancellable *cancellable, GError **err)
{
  /* Check we haven't already been cancelled */
  if (g_cancellable_set_error_if_cancelled (cancellable, err))
    return FALSE;

  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "base64_out");
    return FALSE;
  }

  gulong id = 0;
  if (cancellable) {
    id = g_cancellable_connect (cancellable,
                               G_CALLBACK (cancelled_handler),
                               g, NULL);
  }

  int ret = guestfs_base64_out (g, filename, base64file);
  g_cancellable_disconnect (cancellable, id);
  if (ret == -1) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return FALSE;
  }

  return TRUE;
}

/**
 * guestfs_session_blkdiscard:
 * @session: (transfer none): A GuestfsSession object
 * @device: (transfer none) (type filename):
 * @err: A GError object to receive any generated errors
 *
 * discard all blocks on a device
 *
 * This discards all blocks on the block device @device, giving the free
 * space back to the host.
 * 
 * This operation requires support in libguestfs, the host filesystem, qemu
 * and the host kernel. If this support isn't present it may give an error
 * or even appear to run but do nothing. You must also set the @discard
 * attribute on the underlying drive (see
 * guestfs_session_add_drive_opts()).
 * 
 * Returns: true on success, false on error
 * Since: 1.25.44
 */
gboolean
guestfs_session_blkdiscard (GuestfsSession *session, const gchar *device, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "blkdiscard");
    return FALSE;
  }

  int ret = guestfs_blkdiscard (g, device);
  if (ret == -1) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return FALSE;
  }

  return TRUE;
}

/**
 * guestfs_session_blkdiscardzeroes:
 * @session: (transfer none): A GuestfsSession object
 * @device: (transfer none) (type filename):
 * @err: A GError object to receive any generated errors
 *
 * return true if discarded blocks are read as zeroes
 *
 * This call returns true if blocks on @device that have been discarded by
 * a call to guestfs_session_blkdiscard() are returned as blocks of zero
 * bytes when read the next time.
 * 
 * If it returns false, then it may be that discarded blocks are read as
 * stale or random data.
 * 
 * Returns: the returned value, or -1 on error
 * Since: 1.25.44
 */
gint8
guestfs_session_blkdiscardzeroes (GuestfsSession *session, const gchar *device, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "blkdiscardzeroes");
    return -1;
  }

  int ret = guestfs_blkdiscardzeroes (g, device);
  if (ret == -1) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return -1;
  }

  return ret;
}

/**
 * guestfs_session_blkid:
 * @session: (transfer none): A GuestfsSession object
 * @device: (transfer none) (type filename):
 * @err: A GError object to receive any generated errors
 *
 * print block device attributes
 *
 * This command returns block device attributes for @device. The following
 * fields are usually present in the returned hash. Other fields may also
 * be present.
 * 
 * @UUID
 * The uuid of this device.
 * 
 * @LABEL
 * The label of this device.
 * 
 * @VERSION
 * The version of blkid command.
 * 
 * @TYPE
 * The filesystem type or RAID of this device.
 * 
 * @USAGE
 * The usage of this device, for example @filesystem or @raid.
 * 
 * Returns: (transfer full) (element-type utf8 utf8): a GHashTable of results, or NULL on error
 * Since: 1.15.9
 */
GHashTable *
guestfs_session_blkid (GuestfsSession *session, const gchar *device, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "blkid");
    return NULL;
  }

  char **ret = guestfs_blkid (g, device);
  if (ret == NULL) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return NULL;
  }

  GHashTable *h = g_hash_table_new_full (g_str_hash, g_str_equal, g_free, g_free);
  char **i = ret;
  while (*i) {
    char *key = *i; i++;
    char *value = *i; i++;
    g_hash_table_insert (h, key, value);
  };
  g_free (ret);
  return h;
}

/**
 * guestfs_session_blockdev_flushbufs:
 * @session: (transfer none): A GuestfsSession object
 * @device: (transfer none) (type filename):
 * @err: A GError object to receive any generated errors
 *
 * flush device buffers
 *
 * This tells the kernel to flush internal buffers associated with @device.
 * 
 * This uses the blockdev(8) command.
 * 
 * Returns: true on success, false on error
 * Since: 1.9.3
 */
gboolean
guestfs_session_blockdev_flushbufs (GuestfsSession *session, const gchar *device, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "blockdev_flushbufs");
    return FALSE;
  }

  int ret = guestfs_blockdev_flushbufs (g, device);
  if (ret == -1) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return FALSE;
  }

  return TRUE;
}

/**
 * guestfs_session_blockdev_getbsz:
 * @session: (transfer none): A GuestfsSession object
 * @device: (transfer none) (type filename):
 * @err: A GError object to receive any generated errors
 *
 * get blocksize of block device
 *
 * This returns the block size of a device.
 * 
 * Note: this is different from both *size in blocks* and *filesystem block
 * size*. Also this setting is not really used by anything. You should
 * probably not use it for anything. Filesystems have their own idea about
 * what block size to choose.
 * 
 * This uses the blockdev(8) command.
 * 
 * Returns: the returned value, or -1 on error
 * Since: 1.9.3
 */
gint32
guestfs_session_blockdev_getbsz (GuestfsSession *session, const gchar *device, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "blockdev_getbsz");
    return -1;
  }

  int ret = guestfs_blockdev_getbsz (g, device);
  if (ret == -1) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return -1;
  }

  return ret;
}

/**
 * guestfs_session_blockdev_getro:
 * @session: (transfer none): A GuestfsSession object
 * @device: (transfer none) (type filename):
 * @err: A GError object to receive any generated errors
 *
 * is block device set to read-only
 *
 * Returns a boolean indicating if the block device is read-only (true if
 * read-only, false if not).
 * 
 * This uses the blockdev(8) command.
 * 
 * Returns: the returned value, or -1 on error
 * Since: 1.9.3
 */
gint8
guestfs_session_blockdev_getro (GuestfsSession *session, const gchar *device, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "blockdev_getro");
    return -1;
  }

  int ret = guestfs_blockdev_getro (g, device);
  if (ret == -1) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return -1;
  }

  return ret;
}

/**
 * guestfs_session_blockdev_getsize64:
 * @session: (transfer none): A GuestfsSession object
 * @device: (transfer none) (type filename):
 * @err: A GError object to receive any generated errors
 *
 * get total size of device in bytes
 *
 * This returns the size of the device in bytes.
 * 
 * See also guestfs_session_blockdev_getsz().
 * 
 * This uses the blockdev(8) command.
 * 
 * Returns: the returned value, or -1 on error
 * Since: 1.9.3
 */
gint64
guestfs_session_blockdev_getsize64 (GuestfsSession *session, const gchar *device, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "blockdev_getsize64");
    return -1;
  }

  int64_t ret = guestfs_blockdev_getsize64 (g, device);
  if (ret == -1) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return -1;
  }

  return ret;
}

/**
 * guestfs_session_blockdev_getss:
 * @session: (transfer none): A GuestfsSession object
 * @device: (transfer none) (type filename):
 * @err: A GError object to receive any generated errors
 *
 * get sectorsize of block device
 *
 * This returns the size of sectors on a block device. Usually 512, but can
 * be larger for modern devices.
 * 
 * (Note, this is not the size in sectors, use
 * guestfs_session_blockdev_getsz() for that).
 * 
 * This uses the blockdev(8) command.
 * 
 * Returns: the returned value, or -1 on error
 * Since: 1.9.3
 */
gint32
guestfs_session_blockdev_getss (GuestfsSession *session, const gchar *device, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "blockdev_getss");
    return -1;
  }

  int ret = guestfs_blockdev_getss (g, device);
  if (ret == -1) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return -1;
  }

  return ret;
}

/**
 * guestfs_session_blockdev_getsz:
 * @session: (transfer none): A GuestfsSession object
 * @device: (transfer none) (type filename):
 * @err: A GError object to receive any generated errors
 *
 * get total size of device in 512-byte sectors
 *
 * This returns the size of the device in units of 512-byte sectors (even
 * if the sectorsize isn't 512 bytes ... weird).
 * 
 * See also guestfs_session_blockdev_getss() for the real sector size of
 * the device, and guestfs_session_blockdev_getsize64() for the more useful
 * *size in bytes*.
 * 
 * This uses the blockdev(8) command.
 * 
 * Returns: the returned value, or -1 on error
 * Since: 1.9.3
 */
gint64
guestfs_session_blockdev_getsz (GuestfsSession *session, const gchar *device, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "blockdev_getsz");
    return -1;
  }

  int64_t ret = guestfs_blockdev_getsz (g, device);
  if (ret == -1) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return -1;
  }

  return ret;
}

/**
 * guestfs_session_blockdev_rereadpt:
 * @session: (transfer none): A GuestfsSession object
 * @device: (transfer none) (type filename):
 * @err: A GError object to receive any generated errors
 *
 * reread partition table
 *
 * Reread the partition table on @device.
 * 
 * This uses the blockdev(8) command.
 * 
 * Returns: true on success, false on error
 * Since: 1.9.3
 */
gboolean
guestfs_session_blockdev_rereadpt (GuestfsSession *session, const gchar *device, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "blockdev_rereadpt");
    return FALSE;
  }

  int ret = guestfs_blockdev_rereadpt (g, device);
  if (ret == -1) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return FALSE;
  }

  return TRUE;
}

/**
 * guestfs_session_blockdev_setbsz:
 * @session: (transfer none): A GuestfsSession object
 * @device: (transfer none) (type filename):
 * @blocksize: (type gint32):
 * @err: A GError object to receive any generated errors
 *
 * set blocksize of block device
 *
 * This call does nothing and has never done anything because of a bug in
 * blockdev. Do not use it.
 * 
 * If you need to set the filesystem block size, use the @blocksize option
 * of guestfs_session_mkfs().
 * 
 * Returns: true on success, false on error
 * Deprecated: In new code, use guestfs_session_mkfs() instead
 * Since: 1.9.3
 */
gboolean
guestfs_session_blockdev_setbsz (GuestfsSession *session, const gchar *device, gint32 blocksize, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "blockdev_setbsz");
    return FALSE;
  }

  int ret = guestfs_blockdev_setbsz (g, device, blocksize);
  if (ret == -1) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return FALSE;
  }

  return TRUE;
}

/**
 * guestfs_session_blockdev_setra:
 * @session: (transfer none): A GuestfsSession object
 * @device: (transfer none) (type filename):
 * @sectors: (type gint32):
 * @err: A GError object to receive any generated errors
 *
 * set readahead
 *
 * Set readahead (in 512-byte sectors) for the device.
 * 
 * This uses the blockdev(8) command.
 * 
 * Returns: true on success, false on error
 * Since: 1.29.10
 */
gboolean
guestfs_session_blockdev_setra (GuestfsSession *session, const gchar *device, gint32 sectors, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "blockdev_setra");
    return FALSE;
  }

  int ret = guestfs_blockdev_setra (g, device, sectors);
  if (ret == -1) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return FALSE;
  }

  return TRUE;
}

/**
 * guestfs_session_blockdev_setro:
 * @session: (transfer none): A GuestfsSession object
 * @device: (transfer none) (type filename):
 * @err: A GError object to receive any generated errors
 *
 * set block device to read-only
 *
 * Sets the block device named @device to read-only.
 * 
 * This uses the blockdev(8) command.
 * 
 * Returns: true on success, false on error
 * Since: 1.9.3
 */
gboolean
guestfs_session_blockdev_setro (GuestfsSession *session, const gchar *device, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "blockdev_setro");
    return FALSE;
  }

  int ret = guestfs_blockdev_setro (g, device);
  if (ret == -1) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return FALSE;
  }

  return TRUE;
}

/**
 * guestfs_session_blockdev_setrw:
 * @session: (transfer none): A GuestfsSession object
 * @device: (transfer none) (type filename):
 * @err: A GError object to receive any generated errors
 *
 * set block device to read-write
 *
 * Sets the block device named @device to read-write.
 * 
 * This uses the blockdev(8) command.
 * 
 * Returns: true on success, false on error
 * Since: 1.9.3
 */
gboolean
guestfs_session_blockdev_setrw (GuestfsSession *session, const gchar *device, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "blockdev_setrw");
    return FALSE;
  }

  int ret = guestfs_blockdev_setrw (g, device);
  if (ret == -1) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return FALSE;
  }

  return TRUE;
}

/**
 * guestfs_session_btrfs_balance_cancel:
 * @session: (transfer none): A GuestfsSession object
 * @path: (transfer none) (type filename):
 * @err: A GError object to receive any generated errors
 *
 * cancel a running or paused balance
 *
 * Cancel a running balance on a btrfs filesystem.
 * 
 * Returns: true on success, false on error
 * Since: 1.29.22
 */
gboolean
guestfs_session_btrfs_balance_cancel (GuestfsSession *session, const gchar *path, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "btrfs_balance_cancel");
    return FALSE;
  }

  int ret = guestfs_btrfs_balance_cancel (g, path);
  if (ret == -1) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return FALSE;
  }

  return TRUE;
}

/**
 * guestfs_session_btrfs_balance_pause:
 * @session: (transfer none): A GuestfsSession object
 * @path: (transfer none) (type filename):
 * @err: A GError object to receive any generated errors
 *
 * pause a running balance
 *
 * Pause a running balance on a btrfs filesystem.
 * 
 * Returns: true on success, false on error
 * Since: 1.29.22
 */
gboolean
guestfs_session_btrfs_balance_pause (GuestfsSession *session, const gchar *path, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "btrfs_balance_pause");
    return FALSE;
  }

  int ret = guestfs_btrfs_balance_pause (g, path);
  if (ret == -1) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return FALSE;
  }

  return TRUE;
}

/**
 * guestfs_session_btrfs_balance_resume:
 * @session: (transfer none): A GuestfsSession object
 * @path: (transfer none) (type filename):
 * @err: A GError object to receive any generated errors
 *
 * resume a paused balance
 *
 * Resume a paused balance on a btrfs filesystem.
 * 
 * Returns: true on success, false on error
 * Since: 1.29.22
 */
gboolean
guestfs_session_btrfs_balance_resume (GuestfsSession *session, const gchar *path, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "btrfs_balance_resume");
    return FALSE;
  }

  int ret = guestfs_btrfs_balance_resume (g, path);
  if (ret == -1) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return FALSE;
  }

  return TRUE;
}

/**
 * guestfs_session_btrfs_balance_status:
 * @session: (transfer none): A GuestfsSession object
 * @path: (transfer none) (type filename):
 * @err: A GError object to receive any generated errors
 *
 * show the status of a running or paused balance
 *
 * Show the status of a running or paused balance on a btrfs filesystem.
 * 
 * Returns: (transfer full): a BTRFSBalance object, or NULL on error
 * Since: 1.29.26
 */
GuestfsBTRFSBalance *
guestfs_session_btrfs_balance_status (GuestfsSession *session, const gchar *path, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "btrfs_balance_status");
    return NULL;
  }

  struct guestfs_btrfsbalance *ret = guestfs_btrfs_balance_status (g, path);
  if (ret == NULL) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return NULL;
  }

  GuestfsBTRFSBalance *s = g_slice_new0 (GuestfsBTRFSBalance);
  if (ret->btrfsbalance_status) s->btrfsbalance_status = g_strdup (ret->btrfsbalance_status);
  s->btrfsbalance_total = ret->btrfsbalance_total;
  s->btrfsbalance_balanced = ret->btrfsbalance_balanced;
  s->btrfsbalance_considered = ret->btrfsbalance_considered;
  s->btrfsbalance_left = ret->btrfsbalance_left;
  guestfs_free_btrfsbalance (ret);
  return s;
}

/**
 * guestfs_session_btrfs_device_add:
 * @session: (transfer none): A GuestfsSession object
 * @devices: (transfer none) (array zero-terminated=1) (element-type filename): an array of strings
 * @fs: (transfer none) (type filename):
 * @err: A GError object to receive any generated errors
 *
 * add devices to a btrfs filesystem
 *
 * Add the list of device(s) in @devices to the btrfs filesystem mounted at
 * @fs. If @devices is an empty list, this does nothing.
 * 
 * Returns: true on success, false on error
 * Since: 1.17.35
 */
gboolean
guestfs_session_btrfs_device_add (GuestfsSession *session, gchar *const *devices, const gchar *fs, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "btrfs_device_add");
    return FALSE;
  }

  int ret = guestfs_btrfs_device_add (g, devices, fs);
  if (ret == -1) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return FALSE;
  }

  return TRUE;
}

/**
 * guestfs_session_btrfs_device_delete:
 * @session: (transfer none): A GuestfsSession object
 * @devices: (transfer none) (array zero-terminated=1) (element-type filename): an array of strings
 * @fs: (transfer none) (type filename):
 * @err: A GError object to receive any generated errors
 *
 * remove devices from a btrfs filesystem
 *
 * Remove the @devices from the btrfs filesystem mounted at @fs. If
 * @devices is an empty list, this does nothing.
 * 
 * Returns: true on success, false on error
 * Since: 1.17.35
 */
gboolean
guestfs_session_btrfs_device_delete (GuestfsSession *session, gchar *const *devices, const gchar *fs, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "btrfs_device_delete");
    return FALSE;
  }

  int ret = guestfs_btrfs_device_delete (g, devices, fs);
  if (ret == -1) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return FALSE;
  }

  return TRUE;
}

/**
 * guestfs_session_btrfs_filesystem_balance:
 * @session: (transfer none): A GuestfsSession object
 * @fs: (transfer none) (type filename):
 * @err: A GError object to receive any generated errors
 *
 * balance a btrfs filesystem
 *
 * Balance the chunks in the btrfs filesystem mounted at @fs across the
 * underlying devices.
 * 
 * Returns: true on success, false on error
 * Since: 1.17.35
 */
gboolean
guestfs_session_btrfs_filesystem_balance (GuestfsSession *session, const gchar *fs, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "btrfs_filesystem_balance");
    return FALSE;
  }

  int ret = guestfs_btrfs_filesystem_balance (g, fs);
  if (ret == -1) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return FALSE;
  }

  return TRUE;
}

/**
 * guestfs_session_btrfs_filesystem_defragment:
 * @session: (transfer none): A GuestfsSession object
 * @path: (transfer none) (type filename):
 * @optargs: (transfer none) (allow-none): a GuestfsBTRFSFilesystemDefragment containing optional arguments
 * @err: A GError object to receive any generated errors
 *
 * defragment a file or directory
 *
 * Defragment a file or directory on a btrfs filesystem. compress is one of
 * zlib or lzo.
 * 
 * Returns: true on success, false on error
 * Since: 1.29.22
 */
gboolean
guestfs_session_btrfs_filesystem_defragment (GuestfsSession *session, const gchar *path, GuestfsBTRFSFilesystemDefragment *optargs, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "btrfs_filesystem_defragment");
    return FALSE;
  }

  struct guestfs_btrfs_filesystem_defragment_argv argv;
  struct guestfs_btrfs_filesystem_defragment_argv *argvp = NULL;

  if (optargs) {
    argv.bitmask = 0;

    GValue flush_v = {0, };
    g_value_init (&flush_v, GUESTFS_TYPE_TRISTATE);
    g_object_get_property (G_OBJECT (optargs), "flush", &flush_v);
    GuestfsTristate flush = g_value_get_enum (&flush_v);
    if (flush != GUESTFS_TRISTATE_NONE) {
      argv.bitmask |= GUESTFS_BTRFS_FILESYSTEM_DEFRAGMENT_FLUSH_BITMASK;
      argv.flush = flush;
    }
    GValue compress_v = {0, };
    g_value_init (&compress_v, G_TYPE_STRING);
    g_object_get_property (G_OBJECT (optargs), "compress", &compress_v);
    const gchar *compress = g_value_get_string (&compress_v);
    if (compress != NULL) {
      argv.bitmask |= GUESTFS_BTRFS_FILESYSTEM_DEFRAGMENT_COMPRESS_BITMASK;
      argv.compress = compress;
    }
    argvp = &argv;
  }
  int ret = guestfs_btrfs_filesystem_defragment_argv (g, path, argvp);
  if (ret == -1) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return FALSE;
  }

  return TRUE;
}

/**
 * guestfs_session_btrfs_filesystem_resize:
 * @session: (transfer none): A GuestfsSession object
 * @mountpoint: (transfer none) (type filename):
 * @optargs: (transfer none) (allow-none): a GuestfsBTRFSFilesystemResize containing optional arguments
 * @err: A GError object to receive any generated errors
 *
 * resize a btrfs filesystem
 *
 * This command resizes a btrfs filesystem.
 * 
 * Note that unlike other resize calls, the filesystem has to be mounted
 * and the parameter is the mountpoint not the device (this is a
 * requirement of btrfs itself).
 * 
 * The optional parameters are:
 * 
 * @size
 * The new size (in bytes) of the filesystem. If omitted, the
 * filesystem is resized to the maximum size.
 * 
 * See also btrfs(8).
 * 
 * Returns: true on success, false on error
 * Since: 1.11.17
 */
gboolean
guestfs_session_btrfs_filesystem_resize (GuestfsSession *session, const gchar *mountpoint, GuestfsBTRFSFilesystemResize *optargs, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "btrfs_filesystem_resize");
    return FALSE;
  }

  struct guestfs_btrfs_filesystem_resize_argv argv;
  struct guestfs_btrfs_filesystem_resize_argv *argvp = NULL;

  if (optargs) {
    argv.bitmask = 0;

    GValue size_v = {0, };
    g_value_init (&size_v, G_TYPE_INT64);
    g_object_get_property (G_OBJECT (optargs), "size", &size_v);
    gint64 size = g_value_get_int64 (&size_v);
    if (size != -1) {
      argv.bitmask |= GUESTFS_BTRFS_FILESYSTEM_RESIZE_SIZE_BITMASK;
      argv.size = size;
    }
    argvp = &argv;
  }
  int ret = guestfs_btrfs_filesystem_resize_argv (g, mountpoint, argvp);
  if (ret == -1) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return FALSE;
  }

  return TRUE;
}

/**
 * guestfs_session_btrfs_filesystem_sync:
 * @session: (transfer none): A GuestfsSession object
 * @fs: (transfer none) (type filename):
 * @err: A GError object to receive any generated errors
 *
 * sync a btrfs filesystem
 *
 * Force sync on the btrfs filesystem mounted at @fs.
 * 
 * Returns: true on success, false on error
 * Since: 1.17.35
 */
gboolean
guestfs_session_btrfs_filesystem_sync (GuestfsSession *session, const gchar *fs, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "btrfs_filesystem_sync");
    return FALSE;
  }

  int ret = guestfs_btrfs_filesystem_sync (g, fs);
  if (ret == -1) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return FALSE;
  }

  return TRUE;
}

/**
 * guestfs_session_btrfs_fsck:
 * @session: (transfer none): A GuestfsSession object
 * @device: (transfer none) (type filename):
 * @optargs: (transfer none) (allow-none): a GuestfsBtrfsFsck containing optional arguments
 * @err: A GError object to receive any generated errors
 *
 * check a btrfs filesystem
 *
 * Used to check a btrfs filesystem, @device is the device file where the
 * filesystem is stored.
 * 
 * Returns: true on success, false on error
 * Since: 1.17.43
 */
gboolean
guestfs_session_btrfs_fsck (GuestfsSession *session, const gchar *device, GuestfsBtrfsFsck *optargs, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "btrfs_fsck");
    return FALSE;
  }

  struct guestfs_btrfs_fsck_argv argv;
  struct guestfs_btrfs_fsck_argv *argvp = NULL;

  if (optargs) {
    argv.bitmask = 0;

    GValue superblock_v = {0, };
    g_value_init (&superblock_v, G_TYPE_INT64);
    g_object_get_property (G_OBJECT (optargs), "superblock", &superblock_v);
    gint64 superblock = g_value_get_int64 (&superblock_v);
    if (superblock != -1) {
      argv.bitmask |= GUESTFS_BTRFS_FSCK_SUPERBLOCK_BITMASK;
      argv.superblock = superblock;
    }
    GValue repair_v = {0, };
    g_value_init (&repair_v, GUESTFS_TYPE_TRISTATE);
    g_object_get_property (G_OBJECT (optargs), "repair", &repair_v);
    GuestfsTristate repair = g_value_get_enum (&repair_v);
    if (repair != GUESTFS_TRISTATE_NONE) {
      argv.bitmask |= GUESTFS_BTRFS_FSCK_REPAIR_BITMASK;
      argv.repair = repair;
    }
    argvp = &argv;
  }
  int ret = guestfs_btrfs_fsck_argv (g, device, argvp);
  if (ret == -1) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return FALSE;
  }

  return TRUE;
}

/**
 * guestfs_session_btrfs_image:
 * @session: (transfer none): A GuestfsSession object
 * @source: (transfer none) (array zero-terminated=1) (element-type filename): an array of strings
 * @image: (transfer none) (type filename):
 * @optargs: (transfer none) (allow-none): a GuestfsBTRFSImage containing optional arguments
 * @err: A GError object to receive any generated errors
 *
 * create an image of a btrfs filesystem
 *
 * This is used to create an image of a btrfs filesystem. All data will be
 * zeroed, but metadata and the like is preserved.
 * 
 * Returns: true on success, false on error
 * Since: 1.29.32
 */
gboolean
guestfs_session_btrfs_image (GuestfsSession *session, gchar *const *source, const gchar *image, GuestfsBTRFSImage *optargs, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "btrfs_image");
    return FALSE;
  }

  struct guestfs_btrfs_image_argv argv;
  struct guestfs_btrfs_image_argv *argvp = NULL;

  if (optargs) {
    argv.bitmask = 0;

    GValue compresslevel_v = {0, };
    g_value_init (&compresslevel_v, G_TYPE_INT);
    g_object_get_property (G_OBJECT (optargs), "compresslevel", &compresslevel_v);
    gint32 compresslevel = g_value_get_int (&compresslevel_v);
    if (compresslevel != -1) {
      argv.bitmask |= GUESTFS_BTRFS_IMAGE_COMPRESSLEVEL_BITMASK;
      argv.compresslevel = compresslevel;
    }
    argvp = &argv;
  }
  int ret = guestfs_btrfs_image_argv (g, source, image, argvp);
  if (ret == -1) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return FALSE;
  }

  return TRUE;
}

/**
 * guestfs_session_btrfs_qgroup_assign:
 * @session: (transfer none): A GuestfsSession object
 * @src: (transfer none) (type utf8):
 * @dst: (transfer none) (type utf8):
 * @path: (transfer none) (type filename):
 * @err: A GError object to receive any generated errors
 *
 * add a qgroup to a parent qgroup
 *
 * Add qgroup @src to parent qgroup @dst. This command can group several
 * qgroups into a parent qgroup to share common limit.
 * 
 * Returns: true on success, false on error
 * Since: 1.29.17
 */
gboolean
guestfs_session_btrfs_qgroup_assign (GuestfsSession *session, const gchar *src, const gchar *dst, const gchar *path, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "btrfs_qgroup_assign");
    return FALSE;
  }

  int ret = guestfs_btrfs_qgroup_assign (g, src, dst, path);
  if (ret == -1) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return FALSE;
  }

  return TRUE;
}

/**
 * guestfs_session_btrfs_qgroup_create:
 * @session: (transfer none): A GuestfsSession object
 * @qgroupid: (transfer none) (type utf8):
 * @subvolume: (transfer none) (type filename):
 * @err: A GError object to receive any generated errors
 *
 * create a subvolume quota group
 *
 * Create a quota group (qgroup) for subvolume at @subvolume.
 * 
 * Returns: true on success, false on error
 * Since: 1.29.17
 */
gboolean
guestfs_session_btrfs_qgroup_create (GuestfsSession *session, const gchar *qgroupid, const gchar *subvolume, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "btrfs_qgroup_create");
    return FALSE;
  }

  int ret = guestfs_btrfs_qgroup_create (g, qgroupid, subvolume);
  if (ret == -1) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return FALSE;
  }

  return TRUE;
}

/**
 * guestfs_session_btrfs_qgroup_destroy:
 * @session: (transfer none): A GuestfsSession object
 * @qgroupid: (transfer none) (type utf8):
 * @subvolume: (transfer none) (type filename):
 * @err: A GError object to receive any generated errors
 *
 * destroy a subvolume quota group
 *
 * Destroy a quota group.
 * 
 * Returns: true on success, false on error
 * Since: 1.29.17
 */
gboolean
guestfs_session_btrfs_qgroup_destroy (GuestfsSession *session, const gchar *qgroupid, const gchar *subvolume, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "btrfs_qgroup_destroy");
    return FALSE;
  }

  int ret = guestfs_btrfs_qgroup_destroy (g, qgroupid, subvolume);
  if (ret == -1) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return FALSE;
  }

  return TRUE;
}

/**
 * guestfs_session_btrfs_qgroup_limit:
 * @session: (transfer none): A GuestfsSession object
 * @subvolume: (transfer none) (type filename):
 * @size: (type gint64):
 * @err: A GError object to receive any generated errors
 *
 * limit the size of a subvolume
 *
 * Limit the size of a subvolume which's path is @subvolume. @size can have
 * suffix of G, M, or K.
 * 
 * Returns: true on success, false on error
 * Since: 1.29.17
 */
gboolean
guestfs_session_btrfs_qgroup_limit (GuestfsSession *session, const gchar *subvolume, gint64 size, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "btrfs_qgroup_limit");
    return FALSE;
  }

  int ret = guestfs_btrfs_qgroup_limit (g, subvolume, size);
  if (ret == -1) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return FALSE;
  }

  return TRUE;
}

/**
 * guestfs_session_btrfs_qgroup_remove:
 * @session: (transfer none): A GuestfsSession object
 * @src: (transfer none) (type utf8):
 * @dst: (transfer none) (type utf8):
 * @path: (transfer none) (type filename):
 * @err: A GError object to receive any generated errors
 *
 * remove a qgroup from its parent qgroup
 *
 * Remove qgroup @src from the parent qgroup @dst.
 * 
 * Returns: true on success, false on error
 * Since: 1.29.17
 */
gboolean
guestfs_session_btrfs_qgroup_remove (GuestfsSession *session, const gchar *src, const gchar *dst, const gchar *path, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "btrfs_qgroup_remove");
    return FALSE;
  }

  int ret = guestfs_btrfs_qgroup_remove (g, src, dst, path);
  if (ret == -1) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return FALSE;
  }

  return TRUE;
}

/**
 * guestfs_session_btrfs_qgroup_show:
 * @session: (transfer none): A GuestfsSession object
 * @path: (transfer none) (type filename):
 * @err: A GError object to receive any generated errors
 *
 * show subvolume quota groups
 *
 * Show all subvolume quota groups in a btrfs filesystem, including their
 * usages.
 * 
 * Returns: (transfer full) (array zero-terminated=1) (element-type GuestfsBTRFSQgroup): an array of BTRFSQgroup objects, or NULL on error
 * Since: 1.29.17
 */
GuestfsBTRFSQgroup **
guestfs_session_btrfs_qgroup_show (GuestfsSession *session, const gchar *path, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "btrfs_qgroup_show");
    return NULL;
  }

  struct guestfs_btrfsqgroup_list *ret = guestfs_btrfs_qgroup_show (g, path);
  if (ret == NULL) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return NULL;
  }

  GuestfsBTRFSQgroup **l = g_malloc (sizeof (GuestfsBTRFSQgroup*) * (ret->len + 1));
  gsize i;
  for (i = 0; i < ret->len; i++) {
    l[i] = g_slice_new0 (GuestfsBTRFSQgroup);
    if (ret->val[i].btrfsqgroup_id) l[i]->btrfsqgroup_id = g_strdup (ret->val[i].btrfsqgroup_id);
    l[i]->btrfsqgroup_rfer = ret->val[i].btrfsqgroup_rfer;
    l[i]->btrfsqgroup_excl = ret->val[i].btrfsqgroup_excl;
  }
  guestfs_free_btrfsqgroup_list (ret);
  l[i] = NULL;
  return l;
}

/**
 * guestfs_session_btrfs_quota_enable:
 * @session: (transfer none): A GuestfsSession object
 * @fs: (transfer none) (type filename):
 * @enable: (type gboolean):
 * @err: A GError object to receive any generated errors
 *
 * enable or disable subvolume quota support
 *
 * Enable or disable subvolume quota support for filesystem which contains
 * @path.
 * 
 * Returns: true on success, false on error
 * Since: 1.29.17
 */
gboolean
guestfs_session_btrfs_quota_enable (GuestfsSession *session, const gchar *fs, gboolean enable, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "btrfs_quota_enable");
    return FALSE;
  }

  int ret = guestfs_btrfs_quota_enable (g, fs, enable);
  if (ret == -1) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return FALSE;
  }

  return TRUE;
}

/**
 * guestfs_session_btrfs_quota_rescan:
 * @session: (transfer none): A GuestfsSession object
 * @fs: (transfer none) (type filename):
 * @err: A GError object to receive any generated errors
 *
 * trash all qgroup numbers and scan the metadata again with the current config
 *
 * Trash all qgroup numbers and scan the metadata again with the current
 * config.
 * 
 * Returns: true on success, false on error
 * Since: 1.29.17
 */
gboolean
guestfs_session_btrfs_quota_rescan (GuestfsSession *session, const gchar *fs, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "btrfs_quota_rescan");
    return FALSE;
  }

  int ret = guestfs_btrfs_quota_rescan (g, fs);
  if (ret == -1) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return FALSE;
  }

  return TRUE;
}

/**
 * guestfs_session_btrfs_replace:
 * @session: (transfer none): A GuestfsSession object
 * @srcdev: (transfer none) (type filename):
 * @targetdev: (transfer none) (type filename):
 * @mntpoint: (transfer none) (type filename):
 * @err: A GError object to receive any generated errors
 *
 * replace a btrfs managed device with another device
 *
 * Replace device of a btrfs filesystem. On a live filesystem, duplicate
 * the data to the target device which is currently stored on the source
 * device. After completion of the operation, the source device is wiped
 * out and removed from the filesystem.
 * 
 * The @targetdev needs to be same size or larger than the @srcdev. Devices
 * which are currently mounted are never allowed to be used as the
 * @targetdev.
 * 
 * Returns: true on success, false on error
 * Since: 1.29.48
 */
gboolean
guestfs_session_btrfs_replace (GuestfsSession *session, const gchar *srcdev, const gchar *targetdev, const gchar *mntpoint, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "btrfs_replace");
    return FALSE;
  }

  int ret = guestfs_btrfs_replace (g, srcdev, targetdev, mntpoint);
  if (ret == -1) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return FALSE;
  }

  return TRUE;
}

/**
 * guestfs_session_btrfs_rescue_chunk_recover:
 * @session: (transfer none): A GuestfsSession object
 * @device: (transfer none) (type filename):
 * @err: A GError object to receive any generated errors
 *
 * recover the chunk tree of btrfs filesystem
 *
 * Recover the chunk tree of btrfs filesystem by scanning the devices one
 * by one.
 * 
 * Returns: true on success, false on error
 * Since: 1.29.22
 */
gboolean
guestfs_session_btrfs_rescue_chunk_recover (GuestfsSession *session, const gchar *device, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "btrfs_rescue_chunk_recover");
    return FALSE;
  }

  int ret = guestfs_btrfs_rescue_chunk_recover (g, device);
  if (ret == -1) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return FALSE;
  }

  return TRUE;
}

/**
 * guestfs_session_btrfs_rescue_super_recover:
 * @session: (transfer none): A GuestfsSession object
 * @device: (transfer none) (type filename):
 * @err: A GError object to receive any generated errors
 *
 * recover bad superblocks from good copies
 *
 * Recover bad superblocks from good copies.
 * 
 * Returns: true on success, false on error
 * Since: 1.29.22
 */
gboolean
guestfs_session_btrfs_rescue_super_recover (GuestfsSession *session, const gchar *device, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "btrfs_rescue_super_recover");
    return FALSE;
  }

  int ret = guestfs_btrfs_rescue_super_recover (g, device);
  if (ret == -1) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return FALSE;
  }

  return TRUE;
}

/**
 * guestfs_session_btrfs_scrub_cancel:
 * @session: (transfer none): A GuestfsSession object
 * @path: (transfer none) (type filename):
 * @err: A GError object to receive any generated errors
 *
 * cancel a running scrub
 *
 * Cancel a running scrub on a btrfs filesystem.
 * 
 * Returns: true on success, false on error
 * Since: 1.29.22
 */
gboolean
guestfs_session_btrfs_scrub_cancel (GuestfsSession *session, const gchar *path, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "btrfs_scrub_cancel");
    return FALSE;
  }

  int ret = guestfs_btrfs_scrub_cancel (g, path);
  if (ret == -1) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return FALSE;
  }

  return TRUE;
}

/**
 * guestfs_session_btrfs_scrub_resume:
 * @session: (transfer none): A GuestfsSession object
 * @path: (transfer none) (type filename):
 * @err: A GError object to receive any generated errors
 *
 * resume a previously canceled or interrupted scrub
 *
 * Resume a previously canceled or interrupted scrub on a btrfs filesystem.
 * 
 * Returns: true on success, false on error
 * Since: 1.29.22
 */
gboolean
guestfs_session_btrfs_scrub_resume (GuestfsSession *session, const gchar *path, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "btrfs_scrub_resume");
    return FALSE;
  }

  int ret = guestfs_btrfs_scrub_resume (g, path);
  if (ret == -1) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return FALSE;
  }

  return TRUE;
}

/**
 * guestfs_session_btrfs_scrub_start:
 * @session: (transfer none): A GuestfsSession object
 * @path: (transfer none) (type filename):
 * @err: A GError object to receive any generated errors
 *
 * read all data from all disks and verify checksums
 *
 * Reads all the data and metadata on the filesystem, and uses checksums
 * and the duplicate copies from RAID storage to identify and repair any
 * corrupt data.
 * 
 * Returns: true on success, false on error
 * Since: 1.29.22
 */
gboolean
guestfs_session_btrfs_scrub_start (GuestfsSession *session, const gchar *path, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "btrfs_scrub_start");
    return FALSE;
  }

  int ret = guestfs_btrfs_scrub_start (g, path);
  if (ret == -1) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return FALSE;
  }

  return TRUE;
}

/**
 * guestfs_session_btrfs_scrub_status:
 * @session: (transfer none): A GuestfsSession object
 * @path: (transfer none) (type filename):
 * @err: A GError object to receive any generated errors
 *
 * show status of running or finished scrub
 *
 * Show status of running or finished scrub on a btrfs filesystem.
 * 
 * Returns: (transfer full): a BTRFSScrub object, or NULL on error
 * Since: 1.29.26
 */
GuestfsBTRFSScrub *
guestfs_session_btrfs_scrub_status (GuestfsSession *session, const gchar *path, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "btrfs_scrub_status");
    return NULL;
  }

  struct guestfs_btrfsscrub *ret = guestfs_btrfs_scrub_status (g, path);
  if (ret == NULL) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return NULL;
  }

  GuestfsBTRFSScrub *s = g_slice_new0 (GuestfsBTRFSScrub);
  s->btrfsscrub_data_extents_scrubbed = ret->btrfsscrub_data_extents_scrubbed;
  s->btrfsscrub_tree_extents_scrubbed = ret->btrfsscrub_tree_extents_scrubbed;
  s->btrfsscrub_data_bytes_scrubbed = ret->btrfsscrub_data_bytes_scrubbed;
  s->btrfsscrub_tree_bytes_scrubbed = ret->btrfsscrub_tree_bytes_scrubbed;
  s->btrfsscrub_read_errors = ret->btrfsscrub_read_errors;
  s->btrfsscrub_csum_errors = ret->btrfsscrub_csum_errors;
  s->btrfsscrub_verify_errors = ret->btrfsscrub_verify_errors;
  s->btrfsscrub_no_csum = ret->btrfsscrub_no_csum;
  s->btrfsscrub_csum_discards = ret->btrfsscrub_csum_discards;
  s->btrfsscrub_super_errors = ret->btrfsscrub_super_errors;
  s->btrfsscrub_malloc_errors = ret->btrfsscrub_malloc_errors;
  s->btrfsscrub_uncorrectable_errors = ret->btrfsscrub_uncorrectable_errors;
  s->btrfsscrub_unverified_errors = ret->btrfsscrub_unverified_errors;
  s->btrfsscrub_corrected_errors = ret->btrfsscrub_corrected_errors;
  s->btrfsscrub_last_physical = ret->btrfsscrub_last_physical;
  guestfs_free_btrfsscrub (ret);
  return s;
}

/**
 * guestfs_session_btrfs_set_seeding:
 * @session: (transfer none): A GuestfsSession object
 * @device: (transfer none) (type filename):
 * @seeding: (type gboolean):
 * @err: A GError object to receive any generated errors
 *
 * enable or disable the seeding feature of device
 *
 * Enable or disable the seeding feature of a device that contains a btrfs
 * filesystem.
 * 
 * Returns: true on success, false on error
 * Since: 1.17.43
 */
gboolean
guestfs_session_btrfs_set_seeding (GuestfsSession *session, const gchar *device, gboolean seeding, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "btrfs_set_seeding");
    return FALSE;
  }

  int ret = guestfs_btrfs_set_seeding (g, device, seeding);
  if (ret == -1) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return FALSE;
  }

  return TRUE;
}

/**
 * guestfs_session_btrfs_subvolume_create:
 * @session: (transfer none): A GuestfsSession object
 * @dest: (transfer none) (type filename):
 * @optargs: (transfer none) (allow-none): a GuestfsBTRFSSubvolumeCreate containing optional arguments
 * @err: A GError object to receive any generated errors
 *
 * create a btrfs subvolume
 *
 * Create a btrfs subvolume. The @dest argument is the destination
 * directory and the name of the subvolume, in the form /path/to/dest/name.
 * The optional parameter @qgroupid represents the qgroup which the newly
 * created subvolume will be added to.
 * 
 * Returns: true on success, false on error
 * Since: 1.17.35
 */
gboolean
guestfs_session_btrfs_subvolume_create (GuestfsSession *session, const gchar *dest, GuestfsBTRFSSubvolumeCreate *optargs, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "btrfs_subvolume_create");
    return FALSE;
  }

  struct guestfs_btrfs_subvolume_create_opts_argv argv;
  struct guestfs_btrfs_subvolume_create_opts_argv *argvp = NULL;

  if (optargs) {
    argv.bitmask = 0;

    GValue qgroupid_v = {0, };
    g_value_init (&qgroupid_v, G_TYPE_STRING);
    g_object_get_property (G_OBJECT (optargs), "qgroupid", &qgroupid_v);
    const gchar *qgroupid = g_value_get_string (&qgroupid_v);
    if (qgroupid != NULL) {
      argv.bitmask |= GUESTFS_BTRFS_SUBVOLUME_CREATE_OPTS_QGROUPID_BITMASK;
      argv.qgroupid = qgroupid;
    }
    argvp = &argv;
  }
  int ret = guestfs_btrfs_subvolume_create_opts_argv (g, dest, argvp);
  if (ret == -1) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return FALSE;
  }

  return TRUE;
}

/**
 * guestfs_session_btrfs_subvolume_delete:
 * @session: (transfer none): A GuestfsSession object
 * @subvolume: (transfer none) (type filename):
 * @err: A GError object to receive any generated errors
 *
 * delete a btrfs subvolume or snapshot
 *
 * Delete the named btrfs subvolume or snapshot.
 * 
 * Returns: true on success, false on error
 * Since: 1.17.35
 */
gboolean
guestfs_session_btrfs_subvolume_delete (GuestfsSession *session, const gchar *subvolume, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "btrfs_subvolume_delete");
    return FALSE;
  }

  int ret = guestfs_btrfs_subvolume_delete (g, subvolume);
  if (ret == -1) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return FALSE;
  }

  return TRUE;
}

/**
 * guestfs_session_btrfs_subvolume_get_default:
 * @session: (transfer none): A GuestfsSession object
 * @fs: (transfer none) (type filename):
 * @err: A GError object to receive any generated errors
 *
 * get the default subvolume or snapshot of a filesystem
 *
 * Get the default subvolume or snapshot of a filesystem mounted at
 * @mountpoint.
 * 
 * Returns: the returned value, or -1 on error
 * Since: 1.29.17
 */
gint64
guestfs_session_btrfs_subvolume_get_default (GuestfsSession *session, const gchar *fs, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "btrfs_subvolume_get_default");
    return -1;
  }

  int64_t ret = guestfs_btrfs_subvolume_get_default (g, fs);
  if (ret == -1) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return -1;
  }

  return ret;
}

/**
 * guestfs_session_btrfs_subvolume_list:
 * @session: (transfer none): A GuestfsSession object
 * @fs: (transfer none) (type filename):
 * @err: A GError object to receive any generated errors
 *
 * list btrfs snapshots and subvolumes
 *
 * List the btrfs snapshots and subvolumes of the btrfs filesystem which is
 * mounted at @fs.
 * 
 * Returns: (transfer full) (array zero-terminated=1) (element-type GuestfsBTRFSSubvolume): an array of BTRFSSubvolume objects, or NULL on error
 * Since: 1.17.35
 */
GuestfsBTRFSSubvolume **
guestfs_session_btrfs_subvolume_list (GuestfsSession *session, const gchar *fs, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "btrfs_subvolume_list");
    return NULL;
  }

  struct guestfs_btrfssubvolume_list *ret = guestfs_btrfs_subvolume_list (g, fs);
  if (ret == NULL) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return NULL;
  }

  GuestfsBTRFSSubvolume **l = g_malloc (sizeof (GuestfsBTRFSSubvolume*) * (ret->len + 1));
  gsize i;
  for (i = 0; i < ret->len; i++) {
    l[i] = g_slice_new0 (GuestfsBTRFSSubvolume);
    l[i]->btrfssubvolume_id = ret->val[i].btrfssubvolume_id;
    l[i]->btrfssubvolume_top_level_id = ret->val[i].btrfssubvolume_top_level_id;
    if (ret->val[i].btrfssubvolume_path) l[i]->btrfssubvolume_path = g_strdup (ret->val[i].btrfssubvolume_path);
  }
  guestfs_free_btrfssubvolume_list (ret);
  l[i] = NULL;
  return l;
}

/**
 * guestfs_session_btrfs_subvolume_set_default:
 * @session: (transfer none): A GuestfsSession object
 * @id: (type gint64):
 * @fs: (transfer none) (type filename):
 * @err: A GError object to receive any generated errors
 *
 * set default btrfs subvolume
 *
 * Set the subvolume of the btrfs filesystem @fs which will be mounted by
 * default. See guestfs_session_btrfs_subvolume_list() to get a list of
 * subvolumes.
 * 
 * Returns: true on success, false on error
 * Since: 1.17.35
 */
gboolean
guestfs_session_btrfs_subvolume_set_default (GuestfsSession *session, gint64 id, const gchar *fs, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "btrfs_subvolume_set_default");
    return FALSE;
  }

  int ret = guestfs_btrfs_subvolume_set_default (g, id, fs);
  if (ret == -1) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return FALSE;
  }

  return TRUE;
}

/**
 * guestfs_session_btrfs_subvolume_show:
 * @session: (transfer none): A GuestfsSession object
 * @subvolume: (transfer none) (type filename):
 * @err: A GError object to receive any generated errors
 *
 * return detailed information of the subvolume
 *
 * Return detailed information of the subvolume.
 * 
 * Returns: (transfer full) (element-type utf8 utf8): a GHashTable of results, or NULL on error
 * Since: 1.29.17
 */
GHashTable *
guestfs_session_btrfs_subvolume_show (GuestfsSession *session, const gchar *subvolume, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "btrfs_subvolume_show");
    return NULL;
  }

  char **ret = guestfs_btrfs_subvolume_show (g, subvolume);
  if (ret == NULL) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return NULL;
  }

  GHashTable *h = g_hash_table_new_full (g_str_hash, g_str_equal, g_free, g_free);
  char **i = ret;
  while (*i) {
    char *key = *i; i++;
    char *value = *i; i++;
    g_hash_table_insert (h, key, value);
  };
  g_free (ret);
  return h;
}

/**
 * guestfs_session_btrfs_subvolume_snapshot:
 * @session: (transfer none): A GuestfsSession object
 * @source: (transfer none) (type filename):
 * @dest: (transfer none) (type filename):
 * @optargs: (transfer none) (allow-none): a GuestfsBTRFSSubvolumeSnapshot containing optional arguments
 * @err: A GError object to receive any generated errors
 *
 * create a btrfs snapshot
 *
 * Create a snapshot of the btrfs subvolume @source. The @dest argument is
 * the destination directory and the name of the snapshot, in the form
 * /path/to/dest/name. By default the newly created snapshot is writable,
 * if the value of optional parameter @ro is true, then a readonly snapshot
 * is created. The optional parameter @qgroupid represents the qgroup which
 * the newly created snapshot will be added to.
 * 
 * Returns: true on success, false on error
 * Since: 1.17.35
 */
gboolean
guestfs_session_btrfs_subvolume_snapshot (GuestfsSession *session, const gchar *source, const gchar *dest, GuestfsBTRFSSubvolumeSnapshot *optargs, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "btrfs_subvolume_snapshot");
    return FALSE;
  }

  struct guestfs_btrfs_subvolume_snapshot_opts_argv argv;
  struct guestfs_btrfs_subvolume_snapshot_opts_argv *argvp = NULL;

  if (optargs) {
    argv.bitmask = 0;

    GValue ro_v = {0, };
    g_value_init (&ro_v, GUESTFS_TYPE_TRISTATE);
    g_object_get_property (G_OBJECT (optargs), "ro", &ro_v);
    GuestfsTristate ro = g_value_get_enum (&ro_v);
    if (ro != GUESTFS_TRISTATE_NONE) {
      argv.bitmask |= GUESTFS_BTRFS_SUBVOLUME_SNAPSHOT_OPTS_RO_BITMASK;
      argv.ro = ro;
    }
    GValue qgroupid_v = {0, };
    g_value_init (&qgroupid_v, G_TYPE_STRING);
    g_object_get_property (G_OBJECT (optargs), "qgroupid", &qgroupid_v);
    const gchar *qgroupid = g_value_get_string (&qgroupid_v);
    if (qgroupid != NULL) {
      argv.bitmask |= GUESTFS_BTRFS_SUBVOLUME_SNAPSHOT_OPTS_QGROUPID_BITMASK;
      argv.qgroupid = qgroupid;
    }
    argvp = &argv;
  }
  int ret = guestfs_btrfs_subvolume_snapshot_opts_argv (g, source, dest, argvp);
  if (ret == -1) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return FALSE;
  }

  return TRUE;
}

/**
 * guestfs_session_btrfstune_enable_extended_inode_refs:
 * @session: (transfer none): A GuestfsSession object
 * @device: (transfer none) (type filename):
 * @err: A GError object to receive any generated errors
 *
 * enable extended inode refs
 *
 * This will Enable extended inode refs.
 * 
 * Returns: true on success, false on error
 * Since: 1.29.29
 */
gboolean
guestfs_session_btrfstune_enable_extended_inode_refs (GuestfsSession *session, const gchar *device, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "btrfstune_enable_extended_inode_refs");
    return FALSE;
  }

  int ret = guestfs_btrfstune_enable_extended_inode_refs (g, device);
  if (ret == -1) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return FALSE;
  }

  return TRUE;
}

/**
 * guestfs_session_btrfstune_enable_skinny_metadata_extent_refs:
 * @session: (transfer none): A GuestfsSession object
 * @device: (transfer none) (type filename):
 * @err: A GError object to receive any generated errors
 *
 * enable skinny metadata extent refs
 *
 * This enable skinny metadata extent refs.
 * 
 * Returns: true on success, false on error
 * Since: 1.29.29
 */
gboolean
guestfs_session_btrfstune_enable_skinny_metadata_extent_refs (GuestfsSession *session, const gchar *device, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "btrfstune_enable_skinny_metadata_extent_refs");
    return FALSE;
  }

  int ret = guestfs_btrfstune_enable_skinny_metadata_extent_refs (g, device);
  if (ret == -1) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return FALSE;
  }

  return TRUE;
}

/**
 * guestfs_session_btrfstune_seeding:
 * @session: (transfer none): A GuestfsSession object
 * @device: (transfer none) (type filename):
 * @seeding: (type gboolean):
 * @err: A GError object to receive any generated errors
 *
 * enable or disable seeding of a btrfs device
 *
 * Enable seeding of a btrfs device, this will force a fs readonly so that
 * you can use it to build other filesystems.
 * 
 * Returns: true on success, false on error
 * Since: 1.29.29
 */
gboolean
guestfs_session_btrfstune_seeding (GuestfsSession *session, const gchar *device, gboolean seeding, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "btrfstune_seeding");
    return FALSE;
  }

  int ret = guestfs_btrfstune_seeding (g, device, seeding);
  if (ret == -1) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return FALSE;
  }

  return TRUE;
}

/**
 * guestfs_session_c_pointer:
 * @session: (transfer none): A GuestfsSession object
 * @err: A GError object to receive any generated errors
 *
 * return the C pointer to the guestfs_h handle
 *
 * In non-C language bindings, this allows you to retrieve the underlying C
 * pointer to the handle (ie. "guestfs_h *"). The purpose of this is to
 * allow other libraries to interwork with libguestfs.
 * 
 * Returns: the returned value, or -1 on error
 * Since: 1.29.17
 */
gint64
guestfs_session_c_pointer (GuestfsSession *session, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "c_pointer");
    return -1;
  }

  int64_t ret = guestfs_c_pointer (g);
  if (ret == -1) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return -1;
  }

  return ret;
}

/**
 * guestfs_session_canonical_device_name:
 * @session: (transfer none): A GuestfsSession object
 * @device: (transfer none) (type utf8):
 * @err: A GError object to receive any generated errors
 *
 * return canonical device name
 *
 * This utility function is useful when displaying device names to the
 * user. It takes a number of irregular device names and returns them in a
 * consistent format:
 * 
 * /dev/hdX
 * /dev/vdX
 * These are returned as /dev/sdX. Note this works for device names and
 * partition names. This is approximately the reverse of the algorithm
 * described in "BLOCK DEVICE NAMING" in guestfs(3).
 * 
 * /dev/mapper/VG-LV
 * /dev/dm-N
 * Converted to /dev/VG/LV form using
 * guestfs_session_lvm_canonical_lv_name().
 * 
 * Other strings are returned unmodified.
 * 
 * Returns: (transfer full): the returned string, or NULL on error
 * Since: 1.19.7
 */
gchar *
guestfs_session_canonical_device_name (GuestfsSession *session, const gchar *device, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "canonical_device_name");
    return NULL;
  }

  char *ret = guestfs_canonical_device_name (g, device);
  if (ret == NULL) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return NULL;
  }

  return ret;
}

/**
 * guestfs_session_cap_get_file:
 * @session: (transfer none): A GuestfsSession object
 * @path: (transfer none) (type filename):
 * @err: A GError object to receive any generated errors
 *
 * get the Linux capabilities attached to a file
 *
 * This function returns the Linux capabilities attached to @path. The
 * capabilities set is returned in text form (see cap_to_text(3)).
 * 
 * If no capabilities are attached to a file, an empty string is returned.
 * 
 * Returns: (transfer full): the returned string, or NULL on error
 * Since: 1.19.63
 */
gchar *
guestfs_session_cap_get_file (GuestfsSession *session, const gchar *path, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "cap_get_file");
    return NULL;
  }

  char *ret = guestfs_cap_get_file (g, path);
  if (ret == NULL) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return NULL;
  }

  return ret;
}

/**
 * guestfs_session_cap_set_file:
 * @session: (transfer none): A GuestfsSession object
 * @path: (transfer none) (type filename):
 * @cap: (transfer none) (type utf8):
 * @err: A GError object to receive any generated errors
 *
 * set the Linux capabilities attached to a file
 *
 * This function sets the Linux capabilities attached to @path. The
 * capabilities set @cap should be passed in text form (see
 * cap_from_text(3)).
 * 
 * Returns: true on success, false on error
 * Since: 1.19.63
 */
gboolean
guestfs_session_cap_set_file (GuestfsSession *session, const gchar *path, const gchar *cap, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "cap_set_file");
    return FALSE;
  }

  int ret = guestfs_cap_set_file (g, path, cap);
  if (ret == -1) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return FALSE;
  }

  return TRUE;
}

/**
 * guestfs_session_case_sensitive_path:
 * @session: (transfer none): A GuestfsSession object
 * @path: (transfer none) (type filename):
 * @err: A GError object to receive any generated errors
 *
 * return true path on case-insensitive filesystem
 *
 * This can be used to resolve case insensitive paths on a filesystem which
 * is case sensitive. The use case is to resolve paths which you have read
 * from Windows configuration files or the Windows Registry, to the true
 * path.
 * 
 * The command handles a peculiarity of the Linux ntfs-3g filesystem driver
 * (and probably others), which is that although the underlying filesystem
 * is case-insensitive, the driver exports the filesystem to Linux as
 * case-sensitive.
 * 
 * One consequence of this is that special directories such as C:\windows
 * may appear as /WINDOWS or /windows (or other things) depending on the
 * precise details of how they were created. In Windows itself this would
 * not be a problem.
 * 
 * Bug or feature? You decide: <ulink
 * url='http://www.tuxera.com/community/ntfs-3g-faq/#posixfilenames1'>
 * http://www.tuxera.com/community/ntfs-3g-faq/#posixfilenames1 </ulink>
 * 
 * guestfs_session_case_sensitive_path() attempts to resolve the true case
 * of each element in the path. It will return a resolved path if either
 * the full path or its parent directory exists. If the parent directory
 * exists but the full path does not, the case of the parent directory will
 * be correctly resolved, and the remainder appended unmodified. For
 * example, if the file "/Windows/System32/netkvm.sys" exists:
 * 
 * guestfs_session_case_sensitive_path() ("/windows/system32/netkvm.sys")
 * "Windows/System32/netkvm.sys"
 * 
 * guestfs_session_case_sensitive_path() ("/windows/system32/NoSuchFile")
 * "Windows/System32/NoSuchFile"
 * 
 * guestfs_session_case_sensitive_path() ("/windows/system33/netkvm.sys")
 * *ERROR*
 * 
 * *Note*: Because of the above behaviour,
 * guestfs_session_case_sensitive_path() cannot be used to check for the
 * existence of a file.
 * 
 * *Note*: This function does not handle drive names, backslashes etc.
 * 
 * See also guestfs_session_realpath().
 * 
 * Returns: (transfer full): the returned string, or NULL on error
 * Since: 1.0.75
 */
gchar *
guestfs_session_case_sensitive_path (GuestfsSession *session, const gchar *path, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "case_sensitive_path");
    return NULL;
  }

  char *ret = guestfs_case_sensitive_path (g, path);
  if (ret == NULL) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return NULL;
  }

  return ret;
}

/**
 * guestfs_session_cat:
 * @session: (transfer none): A GuestfsSession object
 * @path: (transfer none) (type filename):
 * @err: A GError object to receive any generated errors
 *
 * list the contents of a file
 *
 * Return the contents of the file named @path.
 * 
 * Because, in C, this function returns a "char *", there is no way to
 * differentiate between a "\0" character in a file and end of string. To
 * handle binary files, use the guestfs_session_read_file() or
 * guestfs_session_download() functions.
 * 
 * Returns: (transfer full): the returned string, or NULL on error
 * Since: 0.4
 */
gchar *
guestfs_session_cat (GuestfsSession *session, const gchar *path, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "cat");
    return NULL;
  }

  char *ret = guestfs_cat (g, path);
  if (ret == NULL) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return NULL;
  }

  return ret;
}

/**
 * guestfs_session_checksum:
 * @session: (transfer none): A GuestfsSession object
 * @csumtype: (transfer none) (type utf8):
 * @path: (transfer none) (type filename):
 * @err: A GError object to receive any generated errors
 *
 * compute MD5, SHAx or CRC checksum of file
 *
 * This call computes the MD5, SHAx or CRC checksum of the file named
 * @path.
 * 
 * The type of checksum to compute is given by the @csumtype parameter
 * which must have one of the following values:
 * 
 * @crc
 * Compute the cyclic redundancy check (CRC) specified by POSIX for the
 * @cksum command.
 * 
 * @md5
 * Compute the MD5 hash (using the @md5sum program).
 * 
 * @sha1
 * Compute the SHA1 hash (using the @sha1sum program).
 * 
 * @sha224
 * Compute the SHA224 hash (using the @sha224sum program).
 * 
 * @sha256
 * Compute the SHA256 hash (using the @sha256sum program).
 * 
 * @sha384
 * Compute the SHA384 hash (using the @sha384sum program).
 * 
 * @sha512
 * Compute the SHA512 hash (using the @sha512sum program).
 * 
 * The checksum is returned as a printable string.
 * 
 * To get the checksum for a device, use guestfs_session_checksum_device().
 * 
 * To get the checksums for many files, use
 * guestfs_session_checksums_out().
 * 
 * Returns: (transfer full): the returned string, or NULL on error
 * Since: 1.0.2
 */
gchar *
guestfs_session_checksum (GuestfsSession *session, const gchar *csumtype, const gchar *path, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "checksum");
    return NULL;
  }

  char *ret = guestfs_checksum (g, csumtype, path);
  if (ret == NULL) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return NULL;
  }

  return ret;
}

/**
 * guestfs_session_checksum_device:
 * @session: (transfer none): A GuestfsSession object
 * @csumtype: (transfer none) (type utf8):
 * @device: (transfer none) (type filename):
 * @err: A GError object to receive any generated errors
 *
 * compute MD5, SHAx or CRC checksum of the contents of a device
 *
 * This call computes the MD5, SHAx or CRC checksum of the contents of the
 * device named @device. For the types of checksums supported see the
 * guestfs_session_checksum() command.
 * 
 * Returns: (transfer full): the returned string, or NULL on error
 * Since: 1.3.2
 */
gchar *
guestfs_session_checksum_device (GuestfsSession *session, const gchar *csumtype, const gchar *device, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "checksum_device");
    return NULL;
  }

  char *ret = guestfs_checksum_device (g, csumtype, device);
  if (ret == NULL) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return NULL;
  }

  return ret;
}

/**
 * guestfs_session_checksums_out:
 * @session: (transfer none): A GuestfsSession object
 * @csumtype: (transfer none) (type utf8):
 * @directory: (transfer none) (type filename):
 * @sumsfile: (transfer none) (type filename):
 * @cancellable: A GCancellable object
 * @err: A GError object to receive any generated errors
 *
 * compute MD5, SHAx or CRC checksum of files in a directory
 *
 * This command computes the checksums of all regular files in directory
 * and then emits a list of those checksums to the local output file
 * @sumsfile.
 * 
 * This can be used for verifying the integrity of a virtual machine.
 * However to be properly secure you should pay attention to the output of
 * the checksum command (it uses the ones from GNU coreutils). In
 * particular when the filename is not printable, coreutils uses a special
 * backslash syntax. For more information, see the GNU coreutils info file.
 * 
 * Returns: true on success, false on error
 * Since: 1.3.7
 */
gboolean
guestfs_session_checksums_out (GuestfsSession *session, const gchar *csumtype, const gchar *directory, const gchar *sumsfile, GCancellable *cancellable, GError **err)
{
  /* Check we haven't already been cancelled */
  if (g_cancellable_set_error_if_cancelled (cancellable, err))
    return FALSE;

  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "checksums_out");
    return FALSE;
  }

  gulong id = 0;
  if (cancellable) {
    id = g_cancellable_connect (cancellable,
                               G_CALLBACK (cancelled_handler),
                               g, NULL);
  }

  int ret = guestfs_checksums_out (g, csumtype, directory, sumsfile);
  g_cancellable_disconnect (cancellable, id);
  if (ret == -1) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return FALSE;
  }

  return TRUE;
}

/**
 * guestfs_session_chmod:
 * @session: (transfer none): A GuestfsSession object
 * @mode: (type gint32):
 * @path: (transfer none) (type filename):
 * @err: A GError object to receive any generated errors
 *
 * change file mode
 *
 * Change the mode (permissions) of @path to @mode. Only numeric modes are
 * supported.
 * 
 * *Note*: When using this command from guestfish, @mode by default would
 * be decimal, unless you prefix it with @0 to get octal, ie. use @0700 not
 * @700.
 * 
 * The mode actually set is affected by the umask.
 * 
 * Returns: true on success, false on error
 * Since: 0.8
 */
gboolean
guestfs_session_chmod (GuestfsSession *session, gint32 mode, const gchar *path, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "chmod");
    return FALSE;
  }

  int ret = guestfs_chmod (g, mode, path);
  if (ret == -1) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return FALSE;
  }

  return TRUE;
}

/**
 * guestfs_session_chown:
 * @session: (transfer none): A GuestfsSession object
 * @owner: (type gint32):
 * @group: (type gint32):
 * @path: (transfer none) (type filename):
 * @err: A GError object to receive any generated errors
 *
 * change file owner and group
 *
 * Change the file owner to @owner and group to @group.
 * 
 * Only numeric uid and gid are supported. If you want to use names, you
 * will need to locate and parse the password file yourself (Augeas support
 * makes this relatively easy).
 * 
 * Returns: true on success, false on error
 * Since: 0.8
 */
gboolean
guestfs_session_chown (GuestfsSession *session, gint32 owner, gint32 group, const gchar *path, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "chown");
    return FALSE;
  }

  int ret = guestfs_chown (g, owner, group, path);
  if (ret == -1) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return FALSE;
  }

  return TRUE;
}

/**
 * guestfs_session_clear_backend_setting:
 * @session: (transfer none): A GuestfsSession object
 * @name: (transfer none) (type utf8):
 * @err: A GError object to receive any generated errors
 *
 * remove a single per-backend settings string
 *
 * If there is a backend setting string matching "name" or beginning with
 * "name=", then that string is removed from the backend settings.
 * 
 * This call returns the number of strings which were removed (which may be
 * 0, 1 or greater than 1).
 * 
 * See "BACKEND" in guestfs(3), "BACKEND SETTINGS" in guestfs(3).
 * 
 * Returns: the returned value, or -1 on error
 * Since: 1.27.2
 */
gint32
guestfs_session_clear_backend_setting (GuestfsSession *session, const gchar *name, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "clear_backend_setting");
    return -1;
  }

  int ret = guestfs_clear_backend_setting (g, name);
  if (ret == -1) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return -1;
  }

  return ret;
}

/**
 * guestfs_session_command:
 * @session: (transfer none): A GuestfsSession object
 * @arguments: (transfer none) (array zero-terminated=1) (element-type utf8): an array of strings
 * @err: A GError object to receive any generated errors
 *
 * run a command from the guest filesystem
 *
 * This call runs a command from the guest filesystem. The filesystem must
 * be mounted, and must contain a compatible operating system (ie.
 * something Linux, with the same or compatible processor architecture).
 * 
 * The single parameter is an argv-style list of arguments. The first
 * element is the name of the program to run. Subsequent elements are
 * parameters. The list must be non-empty (ie. must contain a program
 * name). Note that the command runs directly, and is *not* invoked via the
 * shell (see guestfs_session_sh()).
 * 
 * The return value is anything printed to *stdout* by the command.
 * 
 * If the command returns a non-zero exit status, then this function
 * returns an error message. The error message string is the content of
 * *stderr* from the command.
 * 
 * The $PATH environment variable will contain at least /usr/bin and /bin.
 * If you require a program from another location, you should provide the
 * full path in the first parameter.
 * 
 * Shared libraries and data files required by the program must be
 * available on filesystems which are mounted in the correct places. It is
 * the caller's responsibility to ensure all filesystems that are needed
 * are mounted at the right locations.
 * 
 * Returns: (transfer full): the returned string, or NULL on error
 * Since: 1.9.1
 */
gchar *
guestfs_session_command (GuestfsSession *session, gchar *const *arguments, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "command");
    return NULL;
  }

  char *ret = guestfs_command (g, arguments);
  if (ret == NULL) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return NULL;
  }

  return ret;
}

/**
 * guestfs_session_command_lines:
 * @session: (transfer none): A GuestfsSession object
 * @arguments: (transfer none) (array zero-terminated=1) (element-type utf8): an array of strings
 * @err: A GError object to receive any generated errors
 *
 * run a command, returning lines
 *
 * This is the same as guestfs_session_command(), but splits the result
 * into a list of lines.
 * 
 * See also: guestfs_session_sh_lines()
 * 
 * Returns: (transfer full) (array zero-terminated=1) (element-type utf8): an array of returned strings, or NULL on error
 * Since: 1.9.1
 */
gchar **
guestfs_session_command_lines (GuestfsSession *session, gchar *const *arguments, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "command_lines");
    return NULL;
  }

  char **ret = guestfs_command_lines (g, arguments);
  if (ret == NULL) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return NULL;
  }

  return ret;
}

/**
 * guestfs_session_compress_device_out:
 * @session: (transfer none): A GuestfsSession object
 * @ctype: (transfer none) (type utf8):
 * @device: (transfer none) (type filename):
 * @zdevice: (transfer none) (type filename):
 * @optargs: (transfer none) (allow-none): a GuestfsCompressDeviceOut containing optional arguments
 * @cancellable: A GCancellable object
 * @err: A GError object to receive any generated errors
 *
 * output compressed device
 *
 * This command compresses @device and writes it out to the local file
 * @zdevice.
 * 
 * The @ctype and optional @level parameters have the same meaning as in
 * guestfs_session_compress_out().
 * 
 * Returns: true on success, false on error
 * Since: 1.13.15
 */
gboolean
guestfs_session_compress_device_out (GuestfsSession *session, const gchar *ctype, const gchar *device, const gchar *zdevice, GuestfsCompressDeviceOut *optargs, GCancellable *cancellable, GError **err)
{
  /* Check we haven't already been cancelled */
  if (g_cancellable_set_error_if_cancelled (cancellable, err))
    return FALSE;

  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "compress_device_out");
    return FALSE;
  }

  struct guestfs_compress_device_out_argv argv;
  struct guestfs_compress_device_out_argv *argvp = NULL;

  if (optargs) {
    argv.bitmask = 0;

    GValue level_v = {0, };
    g_value_init (&level_v, G_TYPE_INT);
    g_object_get_property (G_OBJECT (optargs), "level", &level_v);
    gint32 level = g_value_get_int (&level_v);
    if (level != -1) {
      argv.bitmask |= GUESTFS_COMPRESS_DEVICE_OUT_LEVEL_BITMASK;
      argv.level = level;
    }
    argvp = &argv;
  }
  gulong id = 0;
  if (cancellable) {
    id = g_cancellable_connect (cancellable,
                               G_CALLBACK (cancelled_handler),
                               g, NULL);
  }

  int ret = guestfs_compress_device_out_argv (g, ctype, device, zdevice, argvp);
  g_cancellable_disconnect (cancellable, id);
  if (ret == -1) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return FALSE;
  }

  return TRUE;
}

/**
 * guestfs_session_compress_out:
 * @session: (transfer none): A GuestfsSession object
 * @ctype: (transfer none) (type utf8):
 * @file: (transfer none) (type filename):
 * @zfile: (transfer none) (type filename):
 * @optargs: (transfer none) (allow-none): a GuestfsCompressOut containing optional arguments
 * @cancellable: A GCancellable object
 * @err: A GError object to receive any generated errors
 *
 * output compressed file
 *
 * This command compresses file and writes it out to the local file zfile.
 * 
 * The compression program used is controlled by the @ctype parameter.
 * Currently this includes: @compress, @gzip, @bzip2, @xz or @lzop. Some
 * compression types may not be supported by particular builds of
 * libguestfs, in which case you will get an error containing the substring
 * "not supported".
 * 
 * The optional @level parameter controls compression level. The meaning
 * and default for this parameter depends on the compression program being
 * used.
 * 
 * Returns: true on success, false on error
 * Since: 1.13.15
 */
gboolean
guestfs_session_compress_out (GuestfsSession *session, const gchar *ctype, const gchar *file, const gchar *zfile, GuestfsCompressOut *optargs, GCancellable *cancellable, GError **err)
{
  /* Check we haven't already been cancelled */
  if (g_cancellable_set_error_if_cancelled (cancellable, err))
    return FALSE;

  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "compress_out");
    return FALSE;
  }

  struct guestfs_compress_out_argv argv;
  struct guestfs_compress_out_argv *argvp = NULL;

  if (optargs) {
    argv.bitmask = 0;

    GValue level_v = {0, };
    g_value_init (&level_v, G_TYPE_INT);
    g_object_get_property (G_OBJECT (optargs), "level", &level_v);
    gint32 level = g_value_get_int (&level_v);
    if (level != -1) {
      argv.bitmask |= GUESTFS_COMPRESS_OUT_LEVEL_BITMASK;
      argv.level = level;
    }
    argvp = &argv;
  }
  gulong id = 0;
  if (cancellable) {
    id = g_cancellable_connect (cancellable,
                               G_CALLBACK (cancelled_handler),
                               g, NULL);
  }

  int ret = guestfs_compress_out_argv (g, ctype, file, zfile, argvp);
  g_cancellable_disconnect (cancellable, id);
  if (ret == -1) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return FALSE;
  }

  return TRUE;
}

/**
 * guestfs_session_config:
 * @session: (transfer none): A GuestfsSession object
 * @hvparam: (transfer none) (type utf8):
 * @hvvalue: (transfer none) (type utf8) (allow-none):
 * @err: A GError object to receive any generated errors
 *
 * add hypervisor parameters
 *
 * This can be used to add arbitrary hypervisor parameters of the form
 * *-param value*. Actually it's not quite arbitrary - we prevent you from
 * setting some parameters which would interfere with parameters that we
 * use.
 * 
 * The first character of @hvparam string must be a @- (dash).
 * 
 * @hvvalue can be NULL.
 * 
 * Returns: true on success, false on error
 * Since: 0.3
 */
gboolean
guestfs_session_config (GuestfsSession *session, const gchar *hvparam, const gchar *hvvalue, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "config");
    return FALSE;
  }

  int ret = guestfs_config (g, hvparam, hvvalue);
  if (ret == -1) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return FALSE;
  }

  return TRUE;
}

/**
 * guestfs_session_copy_attributes:
 * @session: (transfer none): A GuestfsSession object
 * @src: (transfer none) (type filename):
 * @dest: (transfer none) (type filename):
 * @optargs: (transfer none) (allow-none): a GuestfsCopyAttributes containing optional arguments
 * @err: A GError object to receive any generated errors
 *
 * copy the attributes of a path (file/directory) to another
 *
 * Copy the attributes of a path (which can be a file or a directory) to
 * another path.
 * 
 * By default @no attribute is copied, so make sure to specify any (or @all
 * to copy everything).
 * 
 * The optional arguments specify which attributes can be copied:
 * 
 * @mode
 * Copy part of the file mode from @source to @destination. Only the
 * UNIX permissions and the sticky/setuid/setgid bits can be copied.
 * 
 * @xattributes
 * Copy the Linux extended attributes (xattrs) from @source to
 * @destination. This flag does nothing if the *linuxxattrs* feature is
 * not available (see guestfs_session_feature_available()).
 * 
 * @ownership
 * Copy the owner uid and the group gid of @source to @destination.
 * 
 * @all
 * Copy all the attributes from @source to @destination. Enabling it
 * enables all the other flags, if they are not specified already.
 * 
 * Returns: true on success, false on error
 * Since: 1.25.21
 */
gboolean
guestfs_session_copy_attributes (GuestfsSession *session, const gchar *src, const gchar *dest, GuestfsCopyAttributes *optargs, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "copy_attributes");
    return FALSE;
  }

  struct guestfs_copy_attributes_argv argv;
  struct guestfs_copy_attributes_argv *argvp = NULL;

  if (optargs) {
    argv.bitmask = 0;

    GValue all_v = {0, };
    g_value_init (&all_v, GUESTFS_TYPE_TRISTATE);
    g_object_get_property (G_OBJECT (optargs), "all", &all_v);
    GuestfsTristate all = g_value_get_enum (&all_v);
    if (all != GUESTFS_TRISTATE_NONE) {
      argv.bitmask |= GUESTFS_COPY_ATTRIBUTES_ALL_BITMASK;
      argv.all = all;
    }
    GValue mode_v = {0, };
    g_value_init (&mode_v, GUESTFS_TYPE_TRISTATE);
    g_object_get_property (G_OBJECT (optargs), "mode", &mode_v);
    GuestfsTristate mode = g_value_get_enum (&mode_v);
    if (mode != GUESTFS_TRISTATE_NONE) {
      argv.bitmask |= GUESTFS_COPY_ATTRIBUTES_MODE_BITMASK;
      argv.mode = mode;
    }
    GValue xattributes_v = {0, };
    g_value_init (&xattributes_v, GUESTFS_TYPE_TRISTATE);
    g_object_get_property (G_OBJECT (optargs), "xattributes", &xattributes_v);
    GuestfsTristate xattributes = g_value_get_enum (&xattributes_v);
    if (xattributes != GUESTFS_TRISTATE_NONE) {
      argv.bitmask |= GUESTFS_COPY_ATTRIBUTES_XATTRIBUTES_BITMASK;
      argv.xattributes = xattributes;
    }
    GValue ownership_v = {0, };
    g_value_init (&ownership_v, GUESTFS_TYPE_TRISTATE);
    g_object_get_property (G_OBJECT (optargs), "ownership", &ownership_v);
    GuestfsTristate ownership = g_value_get_enum (&ownership_v);
    if (ownership != GUESTFS_TRISTATE_NONE) {
      argv.bitmask |= GUESTFS_COPY_ATTRIBUTES_OWNERSHIP_BITMASK;
      argv.ownership = ownership;
    }
    argvp = &argv;
  }
  int ret = guestfs_copy_attributes_argv (g, src, dest, argvp);
  if (ret == -1) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return FALSE;
  }

  return TRUE;
}

/**
 * guestfs_session_copy_device_to_device:
 * @session: (transfer none): A GuestfsSession object
 * @src: (transfer none) (type filename):
 * @dest: (transfer none) (type filename):
 * @optargs: (transfer none) (allow-none): a GuestfsCopyDeviceToDevice containing optional arguments
 * @err: A GError object to receive any generated errors
 *
 * copy from source device to destination device
 *
 * The four calls guestfs_session_copy_device_to_device(),
 * guestfs_session_copy_device_to_file(),
 * guestfs_session_copy_file_to_device(), and
 * guestfs_session_copy_file_to_file() let you copy from a source
 * (device|file) to a destination (device|file).
 * 
 * Partial copies can be made since you can specify optionally the source
 * offset, destination offset and size to copy. These values are all
 * specified in bytes. If not given, the offsets both default to zero, and
 * the size defaults to copying as much as possible until we hit the end of
 * the source.
 * 
 * The source and destination may be the same object. However overlapping
 * regions may not be copied correctly.
 * 
 * If the destination is a file, it is created if required. If the
 * destination file is not large enough, it is extended.
 * 
 * If the destination is a file and the @append flag is not set, then the
 * destination file is truncated. If the @append flag is set, then the copy
 * appends to the destination file. The @append flag currently cannot be
 * set for devices.
 * 
 * If the @sparse flag is true then the call avoids writing blocks that
 * contain only zeroes, which can help in some situations where the backing
 * disk is thin-provisioned. Note that unless the target is already zeroed,
 * using this option will result in incorrect copying.
 * 
 * Returns: true on success, false on error
 * Since: 1.13.25
 */
gboolean
guestfs_session_copy_device_to_device (GuestfsSession *session, const gchar *src, const gchar *dest, GuestfsCopyDeviceToDevice *optargs, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "copy_device_to_device");
    return FALSE;
  }

  struct guestfs_copy_device_to_device_argv argv;
  struct guestfs_copy_device_to_device_argv *argvp = NULL;

  if (optargs) {
    argv.bitmask = 0;

    GValue srcoffset_v = {0, };
    g_value_init (&srcoffset_v, G_TYPE_INT64);
    g_object_get_property (G_OBJECT (optargs), "srcoffset", &srcoffset_v);
    gint64 srcoffset = g_value_get_int64 (&srcoffset_v);
    if (srcoffset != -1) {
      argv.bitmask |= GUESTFS_COPY_DEVICE_TO_DEVICE_SRCOFFSET_BITMASK;
      argv.srcoffset = srcoffset;
    }
    GValue destoffset_v = {0, };
    g_value_init (&destoffset_v, G_TYPE_INT64);
    g_object_get_property (G_OBJECT (optargs), "destoffset", &destoffset_v);
    gint64 destoffset = g_value_get_int64 (&destoffset_v);
    if (destoffset != -1) {
      argv.bitmask |= GUESTFS_COPY_DEVICE_TO_DEVICE_DESTOFFSET_BITMASK;
      argv.destoffset = destoffset;
    }
    GValue size_v = {0, };
    g_value_init (&size_v, G_TYPE_INT64);
    g_object_get_property (G_OBJECT (optargs), "size", &size_v);
    gint64 size = g_value_get_int64 (&size_v);
    if (size != -1) {
      argv.bitmask |= GUESTFS_COPY_DEVICE_TO_DEVICE_SIZE_BITMASK;
      argv.size = size;
    }
    GValue sparse_v = {0, };
    g_value_init (&sparse_v, GUESTFS_TYPE_TRISTATE);
    g_object_get_property (G_OBJECT (optargs), "sparse", &sparse_v);
    GuestfsTristate sparse = g_value_get_enum (&sparse_v);
    if (sparse != GUESTFS_TRISTATE_NONE) {
      argv.bitmask |= GUESTFS_COPY_DEVICE_TO_DEVICE_SPARSE_BITMASK;
      argv.sparse = sparse;
    }
    GValue append_v = {0, };
    g_value_init (&append_v, GUESTFS_TYPE_TRISTATE);
    g_object_get_property (G_OBJECT (optargs), "append", &append_v);
    GuestfsTristate append = g_value_get_enum (&append_v);
    if (append != GUESTFS_TRISTATE_NONE) {
      argv.bitmask |= GUESTFS_COPY_DEVICE_TO_DEVICE_APPEND_BITMASK;
      argv.append = append;
    }
    argvp = &argv;
  }
  int ret = guestfs_copy_device_to_device_argv (g, src, dest, argvp);
  if (ret == -1) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return FALSE;
  }

  return TRUE;
}

/**
 * guestfs_session_copy_device_to_file:
 * @session: (transfer none): A GuestfsSession object
 * @src: (transfer none) (type filename):
 * @dest: (transfer none) (type filename):
 * @optargs: (transfer none) (allow-none): a GuestfsCopyDeviceToFile containing optional arguments
 * @err: A GError object to receive any generated errors
 *
 * copy from source device to destination file
 *
 * See guestfs_session_copy_device_to_device() for a general overview of
 * this call.
 * 
 * Returns: true on success, false on error
 * Since: 1.13.25
 */
gboolean
guestfs_session_copy_device_to_file (GuestfsSession *session, const gchar *src, const gchar *dest, GuestfsCopyDeviceToFile *optargs, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "copy_device_to_file");
    return FALSE;
  }

  struct guestfs_copy_device_to_file_argv argv;
  struct guestfs_copy_device_to_file_argv *argvp = NULL;

  if (optargs) {
    argv.bitmask = 0;

    GValue srcoffset_v = {0, };
    g_value_init (&srcoffset_v, G_TYPE_INT64);
    g_object_get_property (G_OBJECT (optargs), "srcoffset", &srcoffset_v);
    gint64 srcoffset = g_value_get_int64 (&srcoffset_v);
    if (srcoffset != -1) {
      argv.bitmask |= GUESTFS_COPY_DEVICE_TO_FILE_SRCOFFSET_BITMASK;
      argv.srcoffset = srcoffset;
    }
    GValue destoffset_v = {0, };
    g_value_init (&destoffset_v, G_TYPE_INT64);
    g_object_get_property (G_OBJECT (optargs), "destoffset", &destoffset_v);
    gint64 destoffset = g_value_get_int64 (&destoffset_v);
    if (destoffset != -1) {
      argv.bitmask |= GUESTFS_COPY_DEVICE_TO_FILE_DESTOFFSET_BITMASK;
      argv.destoffset = destoffset;
    }
    GValue size_v = {0, };
    g_value_init (&size_v, G_TYPE_INT64);
    g_object_get_property (G_OBJECT (optargs), "size", &size_v);
    gint64 size = g_value_get_int64 (&size_v);
    if (size != -1) {
      argv.bitmask |= GUESTFS_COPY_DEVICE_TO_FILE_SIZE_BITMASK;
      argv.size = size;
    }
    GValue sparse_v = {0, };
    g_value_init (&sparse_v, GUESTFS_TYPE_TRISTATE);
    g_object_get_property (G_OBJECT (optargs), "sparse", &sparse_v);
    GuestfsTristate sparse = g_value_get_enum (&sparse_v);
    if (sparse != GUESTFS_TRISTATE_NONE) {
      argv.bitmask |= GUESTFS_COPY_DEVICE_TO_FILE_SPARSE_BITMASK;
      argv.sparse = sparse;
    }
    GValue append_v = {0, };
    g_value_init (&append_v, GUESTFS_TYPE_TRISTATE);
    g_object_get_property (G_OBJECT (optargs), "append", &append_v);
    GuestfsTristate append = g_value_get_enum (&append_v);
    if (append != GUESTFS_TRISTATE_NONE) {
      argv.bitmask |= GUESTFS_COPY_DEVICE_TO_FILE_APPEND_BITMASK;
      argv.append = append;
    }
    argvp = &argv;
  }
  int ret = guestfs_copy_device_to_file_argv (g, src, dest, argvp);
  if (ret == -1) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return FALSE;
  }

  return TRUE;
}

/**
 * guestfs_session_copy_file_to_device:
 * @session: (transfer none): A GuestfsSession object
 * @src: (transfer none) (type filename):
 * @dest: (transfer none) (type filename):
 * @optargs: (transfer none) (allow-none): a GuestfsCopyFileToDevice containing optional arguments
 * @err: A GError object to receive any generated errors
 *
 * copy from source file to destination device
 *
 * See guestfs_session_copy_device_to_device() for a general overview of
 * this call.
 * 
 * Returns: true on success, false on error
 * Since: 1.13.25
 */
gboolean
guestfs_session_copy_file_to_device (GuestfsSession *session, const gchar *src, const gchar *dest, GuestfsCopyFileToDevice *optargs, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "copy_file_to_device");
    return FALSE;
  }

  struct guestfs_copy_file_to_device_argv argv;
  struct guestfs_copy_file_to_device_argv *argvp = NULL;

  if (optargs) {
    argv.bitmask = 0;

    GValue srcoffset_v = {0, };
    g_value_init (&srcoffset_v, G_TYPE_INT64);
    g_object_get_property (G_OBJECT (optargs), "srcoffset", &srcoffset_v);
    gint64 srcoffset = g_value_get_int64 (&srcoffset_v);
    if (srcoffset != -1) {
      argv.bitmask |= GUESTFS_COPY_FILE_TO_DEVICE_SRCOFFSET_BITMASK;
      argv.srcoffset = srcoffset;
    }
    GValue destoffset_v = {0, };
    g_value_init (&destoffset_v, G_TYPE_INT64);
    g_object_get_property (G_OBJECT (optargs), "destoffset", &destoffset_v);
    gint64 destoffset = g_value_get_int64 (&destoffset_v);
    if (destoffset != -1) {
      argv.bitmask |= GUESTFS_COPY_FILE_TO_DEVICE_DESTOFFSET_BITMASK;
      argv.destoffset = destoffset;
    }
    GValue size_v = {0, };
    g_value_init (&size_v, G_TYPE_INT64);
    g_object_get_property (G_OBJECT (optargs), "size", &size_v);
    gint64 size = g_value_get_int64 (&size_v);
    if (size != -1) {
      argv.bitmask |= GUESTFS_COPY_FILE_TO_DEVICE_SIZE_BITMASK;
      argv.size = size;
    }
    GValue sparse_v = {0, };
    g_value_init (&sparse_v, GUESTFS_TYPE_TRISTATE);
    g_object_get_property (G_OBJECT (optargs), "sparse", &sparse_v);
    GuestfsTristate sparse = g_value_get_enum (&sparse_v);
    if (sparse != GUESTFS_TRISTATE_NONE) {
      argv.bitmask |= GUESTFS_COPY_FILE_TO_DEVICE_SPARSE_BITMASK;
      argv.sparse = sparse;
    }
    GValue append_v = {0, };
    g_value_init (&append_v, GUESTFS_TYPE_TRISTATE);
    g_object_get_property (G_OBJECT (optargs), "append", &append_v);
    GuestfsTristate append = g_value_get_enum (&append_v);
    if (append != GUESTFS_TRISTATE_NONE) {
      argv.bitmask |= GUESTFS_COPY_FILE_TO_DEVICE_APPEND_BITMASK;
      argv.append = append;
    }
    argvp = &argv;
  }
  int ret = guestfs_copy_file_to_device_argv (g, src, dest, argvp);
  if (ret == -1) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return FALSE;
  }

  return TRUE;
}

/**
 * guestfs_session_copy_file_to_file:
 * @session: (transfer none): A GuestfsSession object
 * @src: (transfer none) (type filename):
 * @dest: (transfer none) (type filename):
 * @optargs: (transfer none) (allow-none): a GuestfsCopyFileToFile containing optional arguments
 * @err: A GError object to receive any generated errors
 *
 * copy from source file to destination file
 *
 * See guestfs_session_copy_device_to_device() for a general overview of
 * this call.
 * 
 * This is not the function you want for copying files. This is for copying
 * blocks within existing files. See guestfs_session_cp(),
 * guestfs_session_cp_a() and guestfs_session_mv() for general file copying
 * and moving functions.
 * 
 * Returns: true on success, false on error
 * Since: 1.13.25
 */
gboolean
guestfs_session_copy_file_to_file (GuestfsSession *session, const gchar *src, const gchar *dest, GuestfsCopyFileToFile *optargs, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "copy_file_to_file");
    return FALSE;
  }

  struct guestfs_copy_file_to_file_argv argv;
  struct guestfs_copy_file_to_file_argv *argvp = NULL;

  if (optargs) {
    argv.bitmask = 0;

    GValue srcoffset_v = {0, };
    g_value_init (&srcoffset_v, G_TYPE_INT64);
    g_object_get_property (G_OBJECT (optargs), "srcoffset", &srcoffset_v);
    gint64 srcoffset = g_value_get_int64 (&srcoffset_v);
    if (srcoffset != -1) {
      argv.bitmask |= GUESTFS_COPY_FILE_TO_FILE_SRCOFFSET_BITMASK;
      argv.srcoffset = srcoffset;
    }
    GValue destoffset_v = {0, };
    g_value_init (&destoffset_v, G_TYPE_INT64);
    g_object_get_property (G_OBJECT (optargs), "destoffset", &destoffset_v);
    gint64 destoffset = g_value_get_int64 (&destoffset_v);
    if (destoffset != -1) {
      argv.bitmask |= GUESTFS_COPY_FILE_TO_FILE_DESTOFFSET_BITMASK;
      argv.destoffset = destoffset;
    }
    GValue size_v = {0, };
    g_value_init (&size_v, G_TYPE_INT64);
    g_object_get_property (G_OBJECT (optargs), "size", &size_v);
    gint64 size = g_value_get_int64 (&size_v);
    if (size != -1) {
      argv.bitmask |= GUESTFS_COPY_FILE_TO_FILE_SIZE_BITMASK;
      argv.size = size;
    }
    GValue sparse_v = {0, };
    g_value_init (&sparse_v, GUESTFS_TYPE_TRISTATE);
    g_object_get_property (G_OBJECT (optargs), "sparse", &sparse_v);
    GuestfsTristate sparse = g_value_get_enum (&sparse_v);
    if (sparse != GUESTFS_TRISTATE_NONE) {
      argv.bitmask |= GUESTFS_COPY_FILE_TO_FILE_SPARSE_BITMASK;
      argv.sparse = sparse;
    }
    GValue append_v = {0, };
    g_value_init (&append_v, GUESTFS_TYPE_TRISTATE);
    g_object_get_property (G_OBJECT (optargs), "append", &append_v);
    GuestfsTristate append = g_value_get_enum (&append_v);
    if (append != GUESTFS_TRISTATE_NONE) {
      argv.bitmask |= GUESTFS_COPY_FILE_TO_FILE_APPEND_BITMASK;
      argv.append = append;
    }
    argvp = &argv;
  }
  int ret = guestfs_copy_file_to_file_argv (g, src, dest, argvp);
  if (ret == -1) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return FALSE;
  }

  return TRUE;
}

/**
 * guestfs_session_copy_in:
 * @session: (transfer none): A GuestfsSession object
 * @localpath: (transfer none) (type utf8):
 * @remotedir: (transfer none) (type filename):
 * @err: A GError object to receive any generated errors
 *
 * copy local files or directories into an image
 *
 * guestfs_session_copy_in() copies local files or directories recursively
 * into the disk image, placing them in the directory called @remotedir
 * (which must exist).
 * 
 * Wildcards cannot be used.
 * 
 * Returns: true on success, false on error
 * Since: 1.29.24
 */
gboolean
guestfs_session_copy_in (GuestfsSession *session, const gchar *localpath, const gchar *remotedir, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "copy_in");
    return FALSE;
  }

  int ret = guestfs_copy_in (g, localpath, remotedir);
  if (ret == -1) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return FALSE;
  }

  return TRUE;
}

/**
 * guestfs_session_copy_out:
 * @session: (transfer none): A GuestfsSession object
 * @remotepath: (transfer none) (type filename):
 * @localdir: (transfer none) (type utf8):
 * @err: A GError object to receive any generated errors
 *
 * copy remote files or directories out of an image
 *
 * guestfs_session_copy_out() copies remote files or directories
 * recursively out of the disk image, placing them on the host disk in a
 * local directory called @localdir (which must exist).
 * 
 * To download to the current directory, use "." as in:
 * 
 * <![CDATA[guestfs_session_copy_out() /home .]]>
 * 
 * Wildcards cannot be used.
 * 
 * Returns: true on success, false on error
 * Since: 1.29.24
 */
gboolean
guestfs_session_copy_out (GuestfsSession *session, const gchar *remotepath, const gchar *localdir, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "copy_out");
    return FALSE;
  }

  int ret = guestfs_copy_out (g, remotepath, localdir);
  if (ret == -1) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return FALSE;
  }

  return TRUE;
}

/**
 * guestfs_session_copy_size:
 * @session: (transfer none): A GuestfsSession object
 * @src: (transfer none) (type filename):
 * @dest: (transfer none) (type filename):
 * @size: (type gint64):
 * @err: A GError object to receive any generated errors
 *
 * copy size bytes from source to destination using dd
 *
 * This command copies exactly @size bytes from one source device or file
 * @src to another destination device or file @dest.
 * 
 * Note this will fail if the source is too short or if the destination is
 * not large enough.
 * 
 * Returns: true on success, false on error
 * Deprecated: In new code, use guestfs_session_copy_device_to_device() instead
 * Since: 1.0.87
 */
gboolean
guestfs_session_copy_size (GuestfsSession *session, const gchar *src, const gchar *dest, gint64 size, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "copy_size");
    return FALSE;
  }

  int ret = guestfs_copy_size (g, src, dest, size);
  if (ret == -1) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return FALSE;
  }

  return TRUE;
}

/**
 * guestfs_session_cp:
 * @session: (transfer none): A GuestfsSession object
 * @src: (transfer none) (type filename):
 * @dest: (transfer none) (type filename):
 * @err: A GError object to receive any generated errors
 *
 * copy a file
 *
 * This copies a file from @src to @dest where @dest is either a
 * destination filename or destination directory.
 * 
 * Returns: true on success, false on error
 * Since: 1.0.18
 */
gboolean
guestfs_session_cp (GuestfsSession *session, const gchar *src, const gchar *dest, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "cp");
    return FALSE;
  }

  int ret = guestfs_cp (g, src, dest);
  if (ret == -1) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return FALSE;
  }

  return TRUE;
}

/**
 * guestfs_session_cp_a:
 * @session: (transfer none): A GuestfsSession object
 * @src: (transfer none) (type filename):
 * @dest: (transfer none) (type filename):
 * @err: A GError object to receive any generated errors
 *
 * copy a file or directory recursively
 *
 * This copies a file or directory from @src to @dest recursively using the
 * "cp -a" command.
 * 
 * Returns: true on success, false on error
 * Since: 1.0.18
 */
gboolean
guestfs_session_cp_a (GuestfsSession *session, const gchar *src, const gchar *dest, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "cp_a");
    return FALSE;
  }

  int ret = guestfs_cp_a (g, src, dest);
  if (ret == -1) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return FALSE;
  }

  return TRUE;
}

/**
 * guestfs_session_cp_r:
 * @session: (transfer none): A GuestfsSession object
 * @src: (transfer none) (type filename):
 * @dest: (transfer none) (type filename):
 * @err: A GError object to receive any generated errors
 *
 * copy a file or directory recursively
 *
 * This copies a file or directory from @src to @dest recursively using the
 * "cp -rP" command.
 * 
 * Most users should use guestfs_session_cp_a() instead. This command is
 * useful when you don't want to preserve permissions, because the target
 * filesystem does not support it (primarily when writing to DOS FAT
 * filesystems).
 * 
 * Returns: true on success, false on error
 * Since: 1.21.38
 */
gboolean
guestfs_session_cp_r (GuestfsSession *session, const gchar *src, const gchar *dest, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "cp_r");
    return FALSE;
  }

  int ret = guestfs_cp_r (g, src, dest);
  if (ret == -1) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return FALSE;
  }

  return TRUE;
}

/**
 * guestfs_session_cpio_out:
 * @session: (transfer none): A GuestfsSession object
 * @directory: (transfer none) (type utf8):
 * @cpiofile: (transfer none) (type filename):
 * @optargs: (transfer none) (allow-none): a GuestfsCpioOut containing optional arguments
 * @cancellable: A GCancellable object
 * @err: A GError object to receive any generated errors
 *
 * pack directory into cpio file
 *
 * This command packs the contents of directory and downloads it to local
 * file @cpiofile.
 * 
 * The optional @format parameter can be used to select the format. Only
 * the following formats are currently permitted:
 * 
 * @newc
 * New (SVR4) portable format. This format happens to be compatible
 * with the cpio-like format used by the Linux kernel for initramfs.
 * 
 * This is the default format.
 * 
 * @crc
 * New (SVR4) portable format with a checksum.
 * 
 * Returns: true on success, false on error
 * Since: 1.27.9
 */
gboolean
guestfs_session_cpio_out (GuestfsSession *session, const gchar *directory, const gchar *cpiofile, GuestfsCpioOut *optargs, GCancellable *cancellable, GError **err)
{
  /* Check we haven't already been cancelled */
  if (g_cancellable_set_error_if_cancelled (cancellable, err))
    return FALSE;

  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "cpio_out");
    return FALSE;
  }

  struct guestfs_cpio_out_argv argv;
  struct guestfs_cpio_out_argv *argvp = NULL;

  if (optargs) {
    argv.bitmask = 0;

    GValue format_v = {0, };
    g_value_init (&format_v, G_TYPE_STRING);
    g_object_get_property (G_OBJECT (optargs), "format", &format_v);
    const gchar *format = g_value_get_string (&format_v);
    if (format != NULL) {
      argv.bitmask |= GUESTFS_CPIO_OUT_FORMAT_BITMASK;
      argv.format = format;
    }
    argvp = &argv;
  }
  gulong id = 0;
  if (cancellable) {
    id = g_cancellable_connect (cancellable,
                               G_CALLBACK (cancelled_handler),
                               g, NULL);
  }

  int ret = guestfs_cpio_out_argv (g, directory, cpiofile, argvp);
  g_cancellable_disconnect (cancellable, id);
  if (ret == -1) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return FALSE;
  }

  return TRUE;
}

/**
 * guestfs_session_dd:
 * @session: (transfer none): A GuestfsSession object
 * @src: (transfer none) (type filename):
 * @dest: (transfer none) (type filename):
 * @err: A GError object to receive any generated errors
 *
 * copy from source to destination using dd
 *
 * This command copies from one source device or file @src to another
 * destination device or file @dest. Normally you would use this to copy to
 * or from a device or partition, for example to duplicate a filesystem.
 * 
 * If the destination is a device, it must be as large or larger than the
 * source file or device, otherwise the copy will fail. This command cannot
 * do partial copies (see guestfs_session_copy_device_to_device()).
 * 
 * Returns: true on success, false on error
 * Deprecated: In new code, use guestfs_session_copy_device_to_device() instead
 * Since: 1.0.80
 */
gboolean
guestfs_session_dd (GuestfsSession *session, const gchar *src, const gchar *dest, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "dd");
    return FALSE;
  }

  int ret = guestfs_dd (g, src, dest);
  if (ret == -1) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return FALSE;
  }

  return TRUE;
}

/**
 * guestfs_session_debug:
 * @session: (transfer none): A GuestfsSession object
 * @subcmd: (transfer none) (type utf8):
 * @extraargs: (transfer none) (array zero-terminated=1) (element-type utf8): an array of strings
 * @err: A GError object to receive any generated errors
 *
 * debugging and internals
 *
 * The guestfs_session_debug() command exposes some internals of @guestfsd
 * (the guestfs daemon) that runs inside the hypervisor.
 * 
 * There is no comprehensive help for this command. You have to look at the
 * file daemon/debug.c in the libguestfs source to find out what you can
 * do.
 * 
 * Returns: (transfer full): the returned string, or NULL on error
 * Since: 1.0.11
 */
gchar *
guestfs_session_debug (GuestfsSession *session, const gchar *subcmd, gchar *const *extraargs, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "debug");
    return NULL;
  }

  char *ret = guestfs_debug (g, subcmd, extraargs);
  if (ret == NULL) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return NULL;
  }

  return ret;
}

/**
 * guestfs_session_debug_drives:
 * @session: (transfer none): A GuestfsSession object
 * @err: A GError object to receive any generated errors
 *
 * debug the drives (internal use only)
 *
 * This returns the internal list of drives. 'debug' commands are not part
 * of the formal API and can be removed or changed at any time.
 * 
 * Returns: (transfer full) (array zero-terminated=1) (element-type utf8): an array of returned strings, or NULL on error
 * Since: 1.13.22
 */
gchar **
guestfs_session_debug_drives (GuestfsSession *session, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "debug_drives");
    return NULL;
  }

  char **ret = guestfs_debug_drives (g);
  if (ret == NULL) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return NULL;
  }

  return ret;
}

/**
 * guestfs_session_debug_upload:
 * @session: (transfer none): A GuestfsSession object
 * @filename: (transfer none) (type filename):
 * @tmpname: (transfer none) (type utf8):
 * @mode: (type gint32):
 * @cancellable: A GCancellable object
 * @err: A GError object to receive any generated errors
 *
 * upload a file to the appliance (internal use only)
 *
 * The guestfs_session_debug_upload() command uploads a file to the
 * libguestfs appliance.
 * 
 * There is no comprehensive help for this command. You have to look at the
 * file daemon/debug.c in the libguestfs source to find out what it is for.
 * 
 * Returns: true on success, false on error
 * Since: 1.3.5
 */
gboolean
guestfs_session_debug_upload (GuestfsSession *session, const gchar *filename, const gchar *tmpname, gint32 mode, GCancellable *cancellable, GError **err)
{
  /* Check we haven't already been cancelled */
  if (g_cancellable_set_error_if_cancelled (cancellable, err))
    return FALSE;

  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "debug_upload");
    return FALSE;
  }

  gulong id = 0;
  if (cancellable) {
    id = g_cancellable_connect (cancellable,
                               G_CALLBACK (cancelled_handler),
                               g, NULL);
  }

  int ret = guestfs_debug_upload (g, filename, tmpname, mode);
  g_cancellable_disconnect (cancellable, id);
  if (ret == -1) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return FALSE;
  }

  return TRUE;
}

/**
 * guestfs_session_device_index:
 * @session: (transfer none): A GuestfsSession object
 * @device: (transfer none) (type filename):
 * @err: A GError object to receive any generated errors
 *
 * convert device to index
 *
 * This function takes a device name (eg. "/dev/sdb") and returns the index
 * of the device in the list of devices.
 * 
 * Index numbers start from 0. The named device must exist, for example as
 * a string returned from guestfs_session_list_devices().
 * 
 * See also guestfs_session_list_devices(), guestfs_session_part_to_dev().
 * 
 * Returns: the returned value, or -1 on error
 * Since: 1.19.7
 */
gint32
guestfs_session_device_index (GuestfsSession *session, const gchar *device, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "device_index");
    return -1;
  }

  int ret = guestfs_device_index (g, device);
  if (ret == -1) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return -1;
  }

  return ret;
}

/**
 * guestfs_session_df:
 * @session: (transfer none): A GuestfsSession object
 * @err: A GError object to receive any generated errors
 *
 * report file system disk space usage
 *
 * This command runs the @df command to report disk space used.
 * 
 * This command is mostly useful for interactive sessions. It is *not*
 * intended that you try to parse the output string. Use
 * guestfs_session_statvfs() from programs.
 * 
 * Returns: (transfer full): the returned string, or NULL on error
 * Since: 1.0.54
 */
gchar *
guestfs_session_df (GuestfsSession *session, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "df");
    return NULL;
  }

  char *ret = guestfs_df (g);
  if (ret == NULL) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return NULL;
  }

  return ret;
}

/**
 * guestfs_session_df_h:
 * @session: (transfer none): A GuestfsSession object
 * @err: A GError object to receive any generated errors
 *
 * report file system disk space usage (human readable)
 *
 * This command runs the "df -h" command to report disk space used in
 * human-readable format.
 * 
 * This command is mostly useful for interactive sessions. It is *not*
 * intended that you try to parse the output string. Use
 * guestfs_session_statvfs() from programs.
 * 
 * Returns: (transfer full): the returned string, or NULL on error
 * Since: 1.0.54
 */
gchar *
guestfs_session_df_h (GuestfsSession *session, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "df_h");
    return NULL;
  }

  char *ret = guestfs_df_h (g);
  if (ret == NULL) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return NULL;
  }

  return ret;
}

/**
 * guestfs_session_disk_create:
 * @session: (transfer none): A GuestfsSession object
 * @filename: (transfer none) (type utf8):
 * @format: (transfer none) (type utf8):
 * @size: (type gint64):
 * @optargs: (transfer none) (allow-none): a GuestfsDiskCreate containing optional arguments
 * @err: A GError object to receive any generated errors
 *
 * create a blank disk image
 *
 * Create a blank disk image called filename (a host file) with format
 * @format (usually @raw or @qcow2). The size is @size bytes.
 * 
 * If used with the optional @backingfile parameter, then a snapshot is
 * created on top of the backing file. In this case, @size must be passed
 * as @-1. The size of the snapshot is the same as the size of the backing
 * file, which is discovered automatically. You are encouraged to also pass
 * @backingformat to describe the format of @backingfile.
 * 
 * If filename refers to a block device, then the device is formatted. The
 * @size is ignored since block devices have an intrinsic size.
 * 
 * The other optional parameters are:
 * 
 * @preallocation
 * If format is @raw, then this can be either @sparse or @full to
 * create a sparse or fully allocated file respectively. The default is
 * @sparse.
 * 
 * If format is @qcow2, then this can be either @off or @metadata.
 * Preallocating metadata can be faster when doing lots of writes, but
 * uses more space. The default is @off.
 * 
 * @compat
 * @qcow2 only: Pass the string 1.1 to use the advanced qcow2 format
 * supported by qemu &ge; 1.1.
 * 
 * @clustersize
 * @qcow2 only: Change the qcow2 cluster size. The default is 65536
 * (bytes) and this setting may be any power of two between 512 and
 * 2097152.
 * 
 * Note that this call does not add the new disk to the handle. You may
 * need to call guestfs_session_add_drive_opts() separately.
 * 
 * Returns: true on success, false on error
 * Since: 1.25.31
 */
gboolean
guestfs_session_disk_create (GuestfsSession *session, const gchar *filename, const gchar *format, gint64 size, GuestfsDiskCreate *optargs, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "disk_create");
    return FALSE;
  }

  struct guestfs_disk_create_argv argv;
  struct guestfs_disk_create_argv *argvp = NULL;

  if (optargs) {
    argv.bitmask = 0;

    GValue backingfile_v = {0, };
    g_value_init (&backingfile_v, G_TYPE_STRING);
    g_object_get_property (G_OBJECT (optargs), "backingfile", &backingfile_v);
    const gchar *backingfile = g_value_get_string (&backingfile_v);
    if (backingfile != NULL) {
      argv.bitmask |= GUESTFS_DISK_CREATE_BACKINGFILE_BITMASK;
      argv.backingfile = backingfile;
    }
    GValue backingformat_v = {0, };
    g_value_init (&backingformat_v, G_TYPE_STRING);
    g_object_get_property (G_OBJECT (optargs), "backingformat", &backingformat_v);
    const gchar *backingformat = g_value_get_string (&backingformat_v);
    if (backingformat != NULL) {
      argv.bitmask |= GUESTFS_DISK_CREATE_BACKINGFORMAT_BITMASK;
      argv.backingformat = backingformat;
    }
    GValue preallocation_v = {0, };
    g_value_init (&preallocation_v, G_TYPE_STRING);
    g_object_get_property (G_OBJECT (optargs), "preallocation", &preallocation_v);
    const gchar *preallocation = g_value_get_string (&preallocation_v);
    if (preallocation != NULL) {
      argv.bitmask |= GUESTFS_DISK_CREATE_PREALLOCATION_BITMASK;
      argv.preallocation = preallocation;
    }
    GValue compat_v = {0, };
    g_value_init (&compat_v, G_TYPE_STRING);
    g_object_get_property (G_OBJECT (optargs), "compat", &compat_v);
    const gchar *compat = g_value_get_string (&compat_v);
    if (compat != NULL) {
      argv.bitmask |= GUESTFS_DISK_CREATE_COMPAT_BITMASK;
      argv.compat = compat;
    }
    GValue clustersize_v = {0, };
    g_value_init (&clustersize_v, G_TYPE_INT);
    g_object_get_property (G_OBJECT (optargs), "clustersize", &clustersize_v);
    gint32 clustersize = g_value_get_int (&clustersize_v);
    if (clustersize != -1) {
      argv.bitmask |= GUESTFS_DISK_CREATE_CLUSTERSIZE_BITMASK;
      argv.clustersize = clustersize;
    }
    argvp = &argv;
  }
  int ret = guestfs_disk_create_argv (g, filename, format, size, argvp);
  if (ret == -1) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return FALSE;
  }

  return TRUE;
}

/**
 * guestfs_session_disk_format:
 * @session: (transfer none): A GuestfsSession object
 * @filename: (transfer none) (type utf8):
 * @err: A GError object to receive any generated errors
 *
 * detect the disk format of a disk image
 *
 * Detect and return the format of the disk image called filename. filename
 * can also be a host device, etc. If the format of the image could not be
 * detected, then "unknown" is returned.
 * 
 * Note that detecting the disk format can be insecure under some
 * circumstances. See "CVE-2010-3851" in guestfs(3).
 * 
 * See also: "DISK IMAGE FORMATS" in guestfs(3)
 * 
 * Returns: (transfer full): the returned string, or NULL on error
 * Since: 1.19.38
 */
gchar *
guestfs_session_disk_format (GuestfsSession *session, const gchar *filename, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "disk_format");
    return NULL;
  }

  char *ret = guestfs_disk_format (g, filename);
  if (ret == NULL) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return NULL;
  }

  return ret;
}

/**
 * guestfs_session_disk_has_backing_file:
 * @session: (transfer none): A GuestfsSession object
 * @filename: (transfer none) (type utf8):
 * @err: A GError object to receive any generated errors
 *
 * return whether disk has a backing file
 *
 * Detect and return whether the disk image filename has a backing file.
 * 
 * Note that detecting disk features can be insecure under some
 * circumstances. See "CVE-2010-3851" in guestfs(3).
 * 
 * Returns: the returned value, or -1 on error
 * Since: 1.19.39
 */
gint8
guestfs_session_disk_has_backing_file (GuestfsSession *session, const gchar *filename, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "disk_has_backing_file");
    return -1;
  }

  int ret = guestfs_disk_has_backing_file (g, filename);
  if (ret == -1) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return -1;
  }

  return ret;
}

/**
 * guestfs_session_disk_virtual_size:
 * @session: (transfer none): A GuestfsSession object
 * @filename: (transfer none) (type utf8):
 * @err: A GError object to receive any generated errors
 *
 * return virtual size of a disk
 *
 * Detect and return the virtual size in bytes of the disk image called
 * filename.
 * 
 * Note that detecting disk features can be insecure under some
 * circumstances. See "CVE-2010-3851" in guestfs(3).
 * 
 * Returns: the returned value, or -1 on error
 * Since: 1.19.39
 */
gint64
guestfs_session_disk_virtual_size (GuestfsSession *session, const gchar *filename, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "disk_virtual_size");
    return -1;
  }

  int64_t ret = guestfs_disk_virtual_size (g, filename);
  if (ret == -1) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return -1;
  }

  return ret;
}

/**
 * guestfs_session_dmesg:
 * @session: (transfer none): A GuestfsSession object
 * @err: A GError object to receive any generated errors
 *
 * return kernel messages
 *
 * This returns the kernel messages (@dmesg output) from the guest kernel.
 * This is sometimes useful for extended debugging of problems.
 * 
 * Another way to get the same information is to enable verbose messages
 * with guestfs_session_set_verbose() or by setting the environment
 * variable "LIBGUESTFS_DEBUG=1" before running the program.
 * 
 * Returns: (transfer full): the returned string, or NULL on error
 * Since: 1.0.18
 */
gchar *
guestfs_session_dmesg (GuestfsSession *session, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "dmesg");
    return NULL;
  }

  char *ret = guestfs_dmesg (g);
  if (ret == NULL) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return NULL;
  }

  return ret;
}

/**
 * guestfs_session_download:
 * @session: (transfer none): A GuestfsSession object
 * @remotefilename: (transfer none) (type filename):
 * @filename: (transfer none) (type filename):
 * @cancellable: A GCancellable object
 * @err: A GError object to receive any generated errors
 *
 * download a file to the local machine
 *
 * Download file remotefilename and save it as filename on the local
 * machine.
 * 
 * filename can also be a named pipe.
 * 
 * See also guestfs_session_upload(), guestfs_session_cat().
 * 
 * Returns: true on success, false on error
 * Since: 1.0.2
 */
gboolean
guestfs_session_download (GuestfsSession *session, const gchar *remotefilename, const gchar *filename, GCancellable *cancellable, GError **err)
{
  /* Check we haven't already been cancelled */
  if (g_cancellable_set_error_if_cancelled (cancellable, err))
    return FALSE;

  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "download");
    return FALSE;
  }

  gulong id = 0;
  if (cancellable) {
    id = g_cancellable_connect (cancellable,
                               G_CALLBACK (cancelled_handler),
                               g, NULL);
  }

  int ret = guestfs_download (g, remotefilename, filename);
  g_cancellable_disconnect (cancellable, id);
  if (ret == -1) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return FALSE;
  }

  return TRUE;
}

/**
 * guestfs_session_download_offset:
 * @session: (transfer none): A GuestfsSession object
 * @remotefilename: (transfer none) (type filename):
 * @filename: (transfer none) (type filename):
 * @offset: (type gint64):
 * @size: (type gint64):
 * @cancellable: A GCancellable object
 * @err: A GError object to receive any generated errors
 *
 * download a file to the local machine with offset and size
 *
 * Download file remotefilename and save it as filename on the local
 * machine.
 * 
 * remotefilename is read for @size bytes starting at @offset (this region
 * must be within the file or device).
 * 
 * Note that there is no limit on the amount of data that can be downloaded
 * with this call, unlike with guestfs_session_pread(), and this call
 * always reads the full amount unless an error occurs.
 * 
 * See also guestfs_session_download(), guestfs_session_pread().
 * 
 * Returns: true on success, false on error
 * Since: 1.5.17
 */
gboolean
guestfs_session_download_offset (GuestfsSession *session, const gchar *remotefilename, const gchar *filename, gint64 offset, gint64 size, GCancellable *cancellable, GError **err)
{
  /* Check we haven't already been cancelled */
  if (g_cancellable_set_error_if_cancelled (cancellable, err))
    return FALSE;

  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "download_offset");
    return FALSE;
  }

  gulong id = 0;
  if (cancellable) {
    id = g_cancellable_connect (cancellable,
                               G_CALLBACK (cancelled_handler),
                               g, NULL);
  }

  int ret = guestfs_download_offset (g, remotefilename, filename, offset, size);
  g_cancellable_disconnect (cancellable, id);
  if (ret == -1) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return FALSE;
  }

  return TRUE;
}

/**
 * guestfs_session_drop_caches:
 * @session: (transfer none): A GuestfsSession object
 * @whattodrop: (type gint32):
 * @err: A GError object to receive any generated errors
 *
 * drop kernel page cache, dentries and inodes
 *
 * This instructs the guest kernel to drop its page cache, and/or dentries
 * and inode caches. The parameter @whattodrop tells the kernel what
 * precisely to drop, see <ulink url='http://linux-mm.org/Drop_Caches'>
 * http://linux-mm.org/Drop_Caches </ulink>
 * 
 * Setting @whattodrop to 3 should drop everything.
 * 
 * This automatically calls sync(2) before the operation, so that the
 * maximum guest memory is freed.
 * 
 * Returns: true on success, false on error
 * Since: 1.0.18
 */
gboolean
guestfs_session_drop_caches (GuestfsSession *session, gint32 whattodrop, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "drop_caches");
    return FALSE;
  }

  int ret = guestfs_drop_caches (g, whattodrop);
  if (ret == -1) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return FALSE;
  }

  return TRUE;
}

/**
 * guestfs_session_du:
 * @session: (transfer none): A GuestfsSession object
 * @path: (transfer none) (type filename):
 * @err: A GError object to receive any generated errors
 *
 * estimate file space usage
 *
 * This command runs the "du -s" command to estimate file space usage for
 * @path.
 * 
 * @path can be a file or a directory. If @path is a directory then the
 * estimate includes the contents of the directory and all subdirectories
 * (recursively).
 * 
 * The result is the estimated size in *kilobytes* (ie. units of 1024
 * bytes).
 * 
 * Returns: the returned value, or -1 on error
 * Since: 1.0.54
 */
gint64
guestfs_session_du (GuestfsSession *session, const gchar *path, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "du");
    return -1;
  }

  int64_t ret = guestfs_du (g, path);
  if (ret == -1) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return -1;
  }

  return ret;
}

/**
 * guestfs_session_e2fsck:
 * @session: (transfer none): A GuestfsSession object
 * @device: (transfer none) (type filename):
 * @optargs: (transfer none) (allow-none): a GuestfsE2fsck containing optional arguments
 * @err: A GError object to receive any generated errors
 *
 * check an ext2/ext3 filesystem
 *
 * This runs the ext2/ext3 filesystem checker on @device. It can take the
 * following optional arguments:
 * 
 * @correct
 * Automatically repair the file system. This option will cause e2fsck
 * to automatically fix any filesystem problems that can be safely
 * fixed without human intervention.
 * 
 * This option may not be specified at the same time as the @forceall
 * option.
 * 
 * @forceall
 * Assume an answer of 'yes' to all questions; allows e2fsck to be used
 * non-interactively.
 * 
 * This option may not be specified at the same time as the @correct
 * option.
 * 
 * Returns: true on success, false on error
 * Since: 1.15.17
 */
gboolean
guestfs_session_e2fsck (GuestfsSession *session, const gchar *device, GuestfsE2fsck *optargs, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "e2fsck");
    return FALSE;
  }

  struct guestfs_e2fsck_argv argv;
  struct guestfs_e2fsck_argv *argvp = NULL;

  if (optargs) {
    argv.bitmask = 0;

    GValue correct_v = {0, };
    g_value_init (&correct_v, GUESTFS_TYPE_TRISTATE);
    g_object_get_property (G_OBJECT (optargs), "correct", &correct_v);
    GuestfsTristate correct = g_value_get_enum (&correct_v);
    if (correct != GUESTFS_TRISTATE_NONE) {
      argv.bitmask |= GUESTFS_E2FSCK_CORRECT_BITMASK;
      argv.correct = correct;
    }
    GValue forceall_v = {0, };
    g_value_init (&forceall_v, GUESTFS_TYPE_TRISTATE);
    g_object_get_property (G_OBJECT (optargs), "forceall", &forceall_v);
    GuestfsTristate forceall = g_value_get_enum (&forceall_v);
    if (forceall != GUESTFS_TRISTATE_NONE) {
      argv.bitmask |= GUESTFS_E2FSCK_FORCEALL_BITMASK;
      argv.forceall = forceall;
    }
    argvp = &argv;
  }
  int ret = guestfs_e2fsck_argv (g, device, argvp);
  if (ret == -1) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return FALSE;
  }

  return TRUE;
}

/**
 * guestfs_session_e2fsck_f:
 * @session: (transfer none): A GuestfsSession object
 * @device: (transfer none) (type filename):
 * @err: A GError object to receive any generated errors
 *
 * check an ext2/ext3 filesystem
 *
 * This runs "e2fsck -p -f device", ie. runs the ext2/ext3 filesystem
 * checker on @device, noninteractively (*-p*), even if the filesystem
 * appears to be clean (*-f*).
 * 
 * Returns: true on success, false on error
 * Deprecated: In new code, use guestfs_session_e2fsck() instead
 * Since: 1.0.29
 */
gboolean
guestfs_session_e2fsck_f (GuestfsSession *session, const gchar *device, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "e2fsck_f");
    return FALSE;
  }

  int ret = guestfs_e2fsck_f (g, device);
  if (ret == -1) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return FALSE;
  }

  return TRUE;
}

/**
 * guestfs_session_echo_daemon:
 * @session: (transfer none): A GuestfsSession object
 * @words: (transfer none) (array zero-terminated=1) (element-type utf8): an array of strings
 * @err: A GError object to receive any generated errors
 *
 * echo arguments back to the client
 *
 * This command concatenates the list of @words passed with single spaces
 * between them and returns the resulting string.
 * 
 * You can use this command to test the connection through to the daemon.
 * 
 * See also guestfs_session_ping_daemon().
 * 
 * Returns: (transfer full): the returned string, or NULL on error
 * Since: 1.0.69
 */
gchar *
guestfs_session_echo_daemon (GuestfsSession *session, gchar *const *words, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "echo_daemon");
    return NULL;
  }

  char *ret = guestfs_echo_daemon (g, words);
  if (ret == NULL) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return NULL;
  }

  return ret;
}

/**
 * guestfs_session_egrep:
 * @session: (transfer none): A GuestfsSession object
 * @regex: (transfer none) (type utf8):
 * @path: (transfer none) (type filename):
 * @err: A GError object to receive any generated errors
 *
 * return lines matching a pattern
 *
 * This calls the external @egrep program and returns the matching lines.
 * 
 * Returns: (transfer full) (array zero-terminated=1) (element-type utf8): an array of returned strings, or NULL on error
 * Deprecated: In new code, use guestfs_session_grep() instead
 * Since: 1.0.66
 */
gchar **
guestfs_session_egrep (GuestfsSession *session, const gchar *regex, const gchar *path, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "egrep");
    return NULL;
  }

  char **ret = guestfs_egrep (g, regex, path);
  if (ret == NULL) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return NULL;
  }

  return ret;
}

/**
 * guestfs_session_egrepi:
 * @session: (transfer none): A GuestfsSession object
 * @regex: (transfer none) (type utf8):
 * @path: (transfer none) (type filename):
 * @err: A GError object to receive any generated errors
 *
 * return lines matching a pattern
 *
 * This calls the external "egrep -i" program and returns the matching
 * lines.
 * 
 * Returns: (transfer full) (array zero-terminated=1) (element-type utf8): an array of returned strings, or NULL on error
 * Deprecated: In new code, use guestfs_session_grep() instead
 * Since: 1.0.66
 */
gchar **
guestfs_session_egrepi (GuestfsSession *session, const gchar *regex, const gchar *path, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "egrepi");
    return NULL;
  }

  char **ret = guestfs_egrepi (g, regex, path);
  if (ret == NULL) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return NULL;
  }

  return ret;
}

/**
 * guestfs_session_equal:
 * @session: (transfer none): A GuestfsSession object
 * @file1: (transfer none) (type filename):
 * @file2: (transfer none) (type filename):
 * @err: A GError object to receive any generated errors
 *
 * test if two files have equal contents
 *
 * This compares the two files file1 and file2 and returns true if their
 * content is exactly equal, or false otherwise.
 * 
 * The external cmp(1) program is used for the comparison.
 * 
 * Returns: the returned value, or -1 on error
 * Since: 1.0.18
 */
gint8
guestfs_session_equal (GuestfsSession *session, const gchar *file1, const gchar *file2, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "equal");
    return -1;
  }

  int ret = guestfs_equal (g, file1, file2);
  if (ret == -1) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return -1;
  }

  return ret;
}

/**
 * guestfs_session_exists:
 * @session: (transfer none): A GuestfsSession object
 * @path: (transfer none) (type filename):
 * @err: A GError object to receive any generated errors
 *
 * test if file or directory exists
 *
 * This returns @true if and only if there is a file, directory (or
 * anything) with the given @path name.
 * 
 * See also guestfs_session_is_file(), guestfs_session_is_dir(),
 * guestfs_session_stat().
 * 
 * Returns: the returned value, or -1 on error
 * Since: 0.8
 */
gint8
guestfs_session_exists (GuestfsSession *session, const gchar *path, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "exists");
    return -1;
  }

  int ret = guestfs_exists (g, path);
  if (ret == -1) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return -1;
  }

  return ret;
}

/**
 * guestfs_session_extlinux:
 * @session: (transfer none): A GuestfsSession object
 * @directory: (transfer none) (type filename):
 * @err: A GError object to receive any generated errors
 *
 * install the SYSLINUX bootloader on an ext2/3/4 or btrfs filesystem
 *
 * Install the SYSLINUX bootloader on the device mounted at directory.
 * Unlike guestfs_session_syslinux() which requires a FAT filesystem, this
 * can be used on an ext2/3/4 or btrfs filesystem.
 * 
 * The directory parameter can be either a mountpoint, or a directory
 * within the mountpoint.
 * 
 * You also have to mark the partition as "active"
 * (guestfs_session_part_set_bootable()) and a Master Boot Record must be
 * installed (eg. using guestfs_session_pwrite_device()) on the first
 * sector of the whole disk. The SYSLINUX package comes with some suitable
 * Master Boot Records. See the extlinux(1) man page for further
 * information.
 * 
 * Additional configuration can be supplied to SYSLINUX by placing a file
 * called extlinux.conf on the filesystem under directory. For further
 * information about the contents of this file, see extlinux(1).
 * 
 * See also guestfs_session_syslinux().
 * 
 * Returns: true on success, false on error
 * Since: 1.21.27
 */
gboolean
guestfs_session_extlinux (GuestfsSession *session, const gchar *directory, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "extlinux");
    return FALSE;
  }

  int ret = guestfs_extlinux (g, directory);
  if (ret == -1) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return FALSE;
  }

  return TRUE;
}

/**
 * guestfs_session_fallocate:
 * @session: (transfer none): A GuestfsSession object
 * @path: (transfer none) (type filename):
 * @len: (type gint32):
 * @err: A GError object to receive any generated errors
 *
 * preallocate a file in the guest filesystem
 *
 * This command preallocates a file (containing zero bytes) named @path of
 * size @len bytes. If the file exists already, it is overwritten.
 * 
 * Do not confuse this with the guestfish-specific @alloc command which
 * allocates a file in the host and attaches it as a device.
 * 
 * Returns: true on success, false on error
 * Deprecated: In new code, use guestfs_session_fallocate64() instead
 * Since: 1.0.66
 */
gboolean
guestfs_session_fallocate (GuestfsSession *session, const gchar *path, gint32 len, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "fallocate");
    return FALSE;
  }

  int ret = guestfs_fallocate (g, path, len);
  if (ret == -1) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return FALSE;
  }

  return TRUE;
}

/**
 * guestfs_session_fallocate64:
 * @session: (transfer none): A GuestfsSession object
 * @path: (transfer none) (type filename):
 * @len: (type gint64):
 * @err: A GError object to receive any generated errors
 *
 * preallocate a file in the guest filesystem
 *
 * This command preallocates a file (containing zero bytes) named @path of
 * size @len bytes. If the file exists already, it is overwritten.
 * 
 * Note that this call allocates disk blocks for the file. To create a
 * sparse file use guestfs_session_truncate_size() instead.
 * 
 * The deprecated call guestfs_session_fallocate() does the same, but owing
 * to an oversight it only allowed 30 bit lengths to be specified,
 * effectively limiting the maximum size of files created through that call
 * to 1GB.
 * 
 * Do not confuse this with the guestfish-specific @alloc and @sparse
 * commands which create a file in the host and attach it as a device.
 * 
 * Returns: true on success, false on error
 * Since: 1.3.17
 */
gboolean
guestfs_session_fallocate64 (GuestfsSession *session, const gchar *path, gint64 len, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "fallocate64");
    return FALSE;
  }

  int ret = guestfs_fallocate64 (g, path, len);
  if (ret == -1) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return FALSE;
  }

  return TRUE;
}

/**
 * guestfs_session_feature_available:
 * @session: (transfer none): A GuestfsSession object
 * @groups: (transfer none) (array zero-terminated=1) (element-type utf8): an array of strings
 * @err: A GError object to receive any generated errors
 *
 * test availability of some parts of the API
 *
 * This is the same as guestfs_session_available(), but unlike that call it
 * returns a simple true/false boolean result, instead of throwing an
 * exception if a feature is not found. For other documentation see
 * guestfs_session_available().
 * 
 * Returns: the returned value, or -1 on error
 * Since: 1.21.26
 */
gint8
guestfs_session_feature_available (GuestfsSession *session, gchar *const *groups, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "feature_available");
    return -1;
  }

  int ret = guestfs_feature_available (g, groups);
  if (ret == -1) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return -1;
  }

  return ret;
}

/**
 * guestfs_session_fgrep:
 * @session: (transfer none): A GuestfsSession object
 * @pattern: (transfer none) (type utf8):
 * @path: (transfer none) (type filename):
 * @err: A GError object to receive any generated errors
 *
 * return lines matching a pattern
 *
 * This calls the external @fgrep program and returns the matching lines.
 * 
 * Returns: (transfer full) (array zero-terminated=1) (element-type utf8): an array of returned strings, or NULL on error
 * Deprecated: In new code, use guestfs_session_grep() instead
 * Since: 1.0.66
 */
gchar **
guestfs_session_fgrep (GuestfsSession *session, const gchar *pattern, const gchar *path, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "fgrep");
    return NULL;
  }

  char **ret = guestfs_fgrep (g, pattern, path);
  if (ret == NULL) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return NULL;
  }

  return ret;
}

/**
 * guestfs_session_fgrepi:
 * @session: (transfer none): A GuestfsSession object
 * @pattern: (transfer none) (type utf8):
 * @path: (transfer none) (type filename):
 * @err: A GError object to receive any generated errors
 *
 * return lines matching a pattern
 *
 * This calls the external "fgrep -i" program and returns the matching
 * lines.
 * 
 * Returns: (transfer full) (array zero-terminated=1) (element-type utf8): an array of returned strings, or NULL on error
 * Deprecated: In new code, use guestfs_session_grep() instead
 * Since: 1.0.66
 */
gchar **
guestfs_session_fgrepi (GuestfsSession *session, const gchar *pattern, const gchar *path, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "fgrepi");
    return NULL;
  }

  char **ret = guestfs_fgrepi (g, pattern, path);
  if (ret == NULL) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return NULL;
  }

  return ret;
}

/**
 * guestfs_session_file:
 * @session: (transfer none): A GuestfsSession object
 * @path: (transfer none) (type filename):
 * @err: A GError object to receive any generated errors
 *
 * determine file type
 *
 * This call uses the standard file(1) command to determine the type or
 * contents of the file.
 * 
 * This call will also transparently look inside various types of
 * compressed file.
 * 
 * The exact command which runs is "file -zb path". Note in particular that
 * the filename is not prepended to the output (the *-b* option).
 * 
 * The output depends on the output of the underlying file(1) command and
 * it can change in future in ways beyond our control. In other words, the
 * output is not guaranteed by the ABI.
 * 
 * See also: file(1), guestfs_session_vfs_type(), guestfs_session_lstat(),
 * guestfs_session_is_file(), guestfs_session_is_blockdev() (etc),
 * guestfs_session_is_zero().
 * 
 * Returns: (transfer full): the returned string, or NULL on error
 * Since: 1.9.1
 */
gchar *
guestfs_session_file (GuestfsSession *session, const gchar *path, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "file");
    return NULL;
  }

  char *ret = guestfs_file (g, path);
  if (ret == NULL) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return NULL;
  }

  return ret;
}

/**
 * guestfs_session_file_architecture:
 * @session: (transfer none): A GuestfsSession object
 * @filename: (transfer none) (type filename):
 * @err: A GError object to receive any generated errors
 *
 * detect the architecture of a binary file
 *
 * This detects the architecture of the binary filename, and returns it if
 * known.
 * 
 * Currently defined architectures are:
 * 
 * "i386"
 * This string is returned for all 32 bit i386, i486, i586, i686
 * binaries irrespective of the precise processor requirements of the
 * binary.
 * 
 * "x86_64"
 * 64 bit x86-64.
 * 
 * "sparc"
 * 32 bit SPARC.
 * 
 * "sparc64"
 * 64 bit SPARC V9 and above.
 * 
 * "ia64"
 * Intel Itanium.
 * 
 * "ppc"
 * 32 bit Power PC.
 * 
 * "ppc64"
 * 64 bit Power PC.
 * 
 * "arm"
 * 32 bit ARM.
 * 
 * "aarch64"
 * 64 bit ARM.
 * 
 * Libguestfs may return other architecture strings in future.
 * 
 * The function works on at least the following types of files:
 * 
 * *   many types of Un*x and Linux binary
 * 
 * *   many types of Un*x and Linux shared library
 * 
 * *   Windows Win32 and Win64 binaries
 * 
 * *   Windows Win32 and Win64 DLLs
 * 
 * Win32 binaries and DLLs return @i386.
 * 
 * Win64 binaries and DLLs return @x86_64.
 * 
 * *   Linux kernel modules
 * 
 * *   Linux new-style initrd images
 * 
 * *   some non-x86 Linux vmlinuz kernels
 * 
 * What it can't do currently:
 * 
 * *   static libraries (libfoo.a)
 * 
 * *   Linux old-style initrd as compressed ext2 filesystem (RHEL 3)
 * 
 * *   x86 Linux vmlinuz kernels
 * 
 * x86 vmlinuz images (bzImage format) consist of a mix of 16-, 32- and
 * compressed code, and are horribly hard to unpack. If you want to
 * find the architecture of a kernel, use the architecture of the
 * associated initrd or kernel module(s) instead.
 * 
 * Returns: (transfer full): the returned string, or NULL on error
 * Since: 1.5.3
 */
gchar *
guestfs_session_file_architecture (GuestfsSession *session, const gchar *filename, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "file_architecture");
    return NULL;
  }

  char *ret = guestfs_file_architecture (g, filename);
  if (ret == NULL) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return NULL;
  }

  return ret;
}

/**
 * guestfs_session_filesize:
 * @session: (transfer none): A GuestfsSession object
 * @file: (transfer none) (type filename):
 * @err: A GError object to receive any generated errors
 *
 * return the size of the file in bytes
 *
 * This command returns the size of file in bytes.
 * 
 * To get other stats about a file, use guestfs_session_stat(),
 * guestfs_session_lstat(), guestfs_session_is_dir(),
 * guestfs_session_is_file() etc. To get the size of block devices, use
 * guestfs_session_blockdev_getsize64().
 * 
 * Returns: the returned value, or -1 on error
 * Since: 1.0.82
 */
gint64
guestfs_session_filesize (GuestfsSession *session, const gchar *file, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "filesize");
    return -1;
  }

  int64_t ret = guestfs_filesize (g, file);
  if (ret == -1) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return -1;
  }

  return ret;
}

/**
 * guestfs_session_filesystem_available:
 * @session: (transfer none): A GuestfsSession object
 * @filesystem: (transfer none) (type utf8):
 * @err: A GError object to receive any generated errors
 *
 * check if filesystem is available
 *
 * Check whether libguestfs supports the named filesystem. The argument
 * @filesystem is a filesystem name, such as @ext3.
 * 
 * You must call guestfs_session_launch() before using this command.
 * 
 * This is mainly useful as a negative test. If this returns true, it
 * doesn't mean that a particular filesystem can be created or mounted,
 * since filesystems can fail for other reasons such as it being a later
 * version of the filesystem, or having incompatible features, or lacking
 * the right mkfs.&lt;*fs*&gt; tool.
 * 
 * See also guestfs_session_available(),
 * guestfs_session_feature_available(), "AVAILABILITY" in guestfs(3).
 * 
 * Returns: the returned value, or -1 on error
 * Since: 1.19.5
 */
gint8
guestfs_session_filesystem_available (GuestfsSession *session, const gchar *filesystem, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "filesystem_available");
    return -1;
  }

  int ret = guestfs_filesystem_available (g, filesystem);
  if (ret == -1) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return -1;
  }

  return ret;
}

/**
 * guestfs_session_fill:
 * @session: (transfer none): A GuestfsSession object
 * @c: (type gint32):
 * @len: (type gint32):
 * @path: (transfer none) (type filename):
 * @err: A GError object to receive any generated errors
 *
 * fill a file with octets
 *
 * This command creates a new file called @path. The initial content of the
 * file is @len octets of @c, where @c must be a number in the range
 * "[0..255]".
 * 
 * To fill a file with zero bytes (sparsely), it is much more efficient to
 * use guestfs_session_truncate_size(). To create a file with a pattern of
 * repeating bytes use guestfs_session_fill_pattern().
 * 
 * Returns: true on success, false on error
 * Since: 1.0.79
 */
gboolean
guestfs_session_fill (GuestfsSession *session, gint32 c, gint32 len, const gchar *path, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "fill");
    return FALSE;
  }

  int ret = guestfs_fill (g, c, len, path);
  if (ret == -1) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return FALSE;
  }

  return TRUE;
}

/**
 * guestfs_session_fill_dir:
 * @session: (transfer none): A GuestfsSession object
 * @dir: (transfer none) (type filename):
 * @nr: (type gint32):
 * @err: A GError object to receive any generated errors
 *
 * fill a directory with empty files
 *
 * This function, useful for testing filesystems, creates @nr empty files
 * in the directory @dir with names @00000000 through @nr-1 (ie. each file
 * name is 8 digits long padded with zeroes).
 * 
 * Returns: true on success, false on error
 * Since: 1.19.32
 */
gboolean
guestfs_session_fill_dir (GuestfsSession *session, const gchar *dir, gint32 nr, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "fill_dir");
    return FALSE;
  }

  int ret = guestfs_fill_dir (g, dir, nr);
  if (ret == -1) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return FALSE;
  }

  return TRUE;
}

/**
 * guestfs_session_fill_pattern:
 * @session: (transfer none): A GuestfsSession object
 * @pattern: (transfer none) (type utf8):
 * @len: (type gint32):
 * @path: (transfer none) (type filename):
 * @err: A GError object to receive any generated errors
 *
 * fill a file with a repeating pattern of bytes
 *
 * This function is like guestfs_session_fill() except that it creates a
 * new file of length @len containing the repeating pattern of bytes in
 * @pattern. The pattern is truncated if necessary to ensure the length of
 * the file is exactly @len bytes.
 * 
 * Returns: true on success, false on error
 * Since: 1.3.12
 */
gboolean
guestfs_session_fill_pattern (GuestfsSession *session, const gchar *pattern, gint32 len, const gchar *path, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "fill_pattern");
    return FALSE;
  }

  int ret = guestfs_fill_pattern (g, pattern, len, path);
  if (ret == -1) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return FALSE;
  }

  return TRUE;
}

/**
 * guestfs_session_find:
 * @session: (transfer none): A GuestfsSession object
 * @directory: (transfer none) (type filename):
 * @err: A GError object to receive any generated errors
 *
 * find all files and directories
 *
 * This command lists out all files and directories, recursively, starting
 * at directory. It is essentially equivalent to running the shell command
 * "find directory -print" but some post-processing happens on the output,
 * described below.
 * 
 * This returns a list of strings *without any prefix*. Thus if the
 * directory structure was:
 * 
 * <![CDATA[/tmp/a]]>
 * 
 * <![CDATA[/tmp/b]]>
 * 
 * <![CDATA[/tmp/c/d]]>
 * 
 * then the returned list from guestfs_session_find() /tmp would be 4
 * elements:
 * 
 * <![CDATA[a]]>
 * 
 * <![CDATA[b]]>
 * 
 * <![CDATA[c]]>
 * 
 * <![CDATA[c/d]]>
 * 
 * If directory is not a directory, then this command returns an error.
 * 
 * The returned list is sorted.
 * 
 * Returns: (transfer full) (array zero-terminated=1) (element-type utf8): an array of returned strings, or NULL on error
 * Since: 1.0.27
 */
gchar **
guestfs_session_find (GuestfsSession *session, const gchar *directory, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "find");
    return NULL;
  }

  char **ret = guestfs_find (g, directory);
  if (ret == NULL) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return NULL;
  }

  return ret;
}

/**
 * guestfs_session_find0:
 * @session: (transfer none): A GuestfsSession object
 * @directory: (transfer none) (type filename):
 * @files: (transfer none) (type filename):
 * @cancellable: A GCancellable object
 * @err: A GError object to receive any generated errors
 *
 * find all files and directories, returning NUL-separated list
 *
 * This command lists out all files and directories, recursively, starting
 * at directory, placing the resulting list in the external file called
 * files.
 * 
 * This command works the same way as guestfs_session_find() with the
 * following exceptions:
 * 
 * *   The resulting list is written to an external file.
 * 
 * *   Items (filenames) in the result are separated by "\0" characters.
 * See find(1) option *-print0*.
 * 
 * *   The result list is not sorted.
 * 
 * Returns: true on success, false on error
 * Since: 1.0.74
 */
gboolean
guestfs_session_find0 (GuestfsSession *session, const gchar *directory, const gchar *files, GCancellable *cancellable, GError **err)
{
  /* Check we haven't already been cancelled */
  if (g_cancellable_set_error_if_cancelled (cancellable, err))
    return FALSE;

  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "find0");
    return FALSE;
  }

  gulong id = 0;
  if (cancellable) {
    id = g_cancellable_connect (cancellable,
                               G_CALLBACK (cancelled_handler),
                               g, NULL);
  }

  int ret = guestfs_find0 (g, directory, files);
  g_cancellable_disconnect (cancellable, id);
  if (ret == -1) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return FALSE;
  }

  return TRUE;
}

/**
 * guestfs_session_findfs_label:
 * @session: (transfer none): A GuestfsSession object
 * @label: (transfer none) (type utf8):
 * @err: A GError object to receive any generated errors
 *
 * find a filesystem by label
 *
 * This command searches the filesystems and returns the one which has the
 * given label. An error is returned if no such filesystem can be found.
 * 
 * To find the label of a filesystem, use guestfs_session_vfs_label().
 * 
 * Returns: (transfer full): the returned string, or NULL on error
 * Since: 1.5.3
 */
gchar *
guestfs_session_findfs_label (GuestfsSession *session, const gchar *label, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "findfs_label");
    return NULL;
  }

  char *ret = guestfs_findfs_label (g, label);
  if (ret == NULL) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return NULL;
  }

  return ret;
}

/**
 * guestfs_session_findfs_uuid:
 * @session: (transfer none): A GuestfsSession object
 * @uuid: (transfer none) (type utf8):
 * @err: A GError object to receive any generated errors
 *
 * find a filesystem by UUID
 *
 * This command searches the filesystems and returns the one which has the
 * given UUID. An error is returned if no such filesystem can be found.
 * 
 * To find the UUID of a filesystem, use guestfs_session_vfs_uuid().
 * 
 * Returns: (transfer full): the returned string, or NULL on error
 * Since: 1.5.3
 */
gchar *
guestfs_session_findfs_uuid (GuestfsSession *session, const gchar *uuid, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "findfs_uuid");
    return NULL;
  }

  char *ret = guestfs_findfs_uuid (g, uuid);
  if (ret == NULL) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return NULL;
  }

  return ret;
}

/**
 * guestfs_session_fsck:
 * @session: (transfer none): A GuestfsSession object
 * @fstype: (transfer none) (type utf8):
 * @device: (transfer none) (type filename):
 * @err: A GError object to receive any generated errors
 *
 * run the filesystem checker
 *
 * This runs the filesystem checker (fsck) on @device which should have
 * filesystem type @fstype.
 * 
 * The returned integer is the status. See fsck(8) for the list of status
 * codes from @fsck.
 * 
 * Notes:
 * 
 * *   Multiple status codes can be summed together.
 * 
 * *   A non-zero return code can mean "success", for example if errors
 * have been corrected on the filesystem.
 * 
 * *   Checking or repairing NTFS volumes is not supported (by linux-ntfs).
 * 
 * This command is entirely equivalent to running "fsck -a -t fstype
 * device".
 * 
 * Returns: the returned value, or -1 on error
 * Since: 1.0.16
 */
gint32
guestfs_session_fsck (GuestfsSession *session, const gchar *fstype, const gchar *device, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "fsck");
    return -1;
  }

  int ret = guestfs_fsck (g, fstype, device);
  if (ret == -1) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return -1;
  }

  return ret;
}

/**
 * guestfs_session_fstrim:
 * @session: (transfer none): A GuestfsSession object
 * @mountpoint: (transfer none) (type filename):
 * @optargs: (transfer none) (allow-none): a GuestfsFstrim containing optional arguments
 * @err: A GError object to receive any generated errors
 *
 * trim free space in a filesystem
 *
 * Trim the free space in the filesystem mounted on @mountpoint. The
 * filesystem must be mounted read-write.
 * 
 * The filesystem contents are not affected, but any free space in the
 * filesystem is "trimmed", that is, given back to the host device, thus
 * making disk images more sparse, allowing unused space in qcow2 files to
 * be reused, etc.
 * 
 * This operation requires support in libguestfs, the mounted filesystem,
 * the host filesystem, qemu and the host kernel. If this support isn't
 * present it may give an error or even appear to run but do nothing.
 * 
 * See also guestfs_session_zero_free_space(). That is a slightly different
 * operation that turns free space in the filesystem into zeroes. It is
 * valid to call guestfs_session_fstrim() either instead of, or after
 * calling guestfs_session_zero_free_space().
 * 
 * Returns: true on success, false on error
 * Since: 1.19.6
 */
gboolean
guestfs_session_fstrim (GuestfsSession *session, const gchar *mountpoint, GuestfsFstrim *optargs, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "fstrim");
    return FALSE;
  }

  struct guestfs_fstrim_argv argv;
  struct guestfs_fstrim_argv *argvp = NULL;

  if (optargs) {
    argv.bitmask = 0;

    GValue offset_v = {0, };
    g_value_init (&offset_v, G_TYPE_INT64);
    g_object_get_property (G_OBJECT (optargs), "offset", &offset_v);
    gint64 offset = g_value_get_int64 (&offset_v);
    if (offset != -1) {
      argv.bitmask |= GUESTFS_FSTRIM_OFFSET_BITMASK;
      argv.offset = offset;
    }
    GValue length_v = {0, };
    g_value_init (&length_v, G_TYPE_INT64);
    g_object_get_property (G_OBJECT (optargs), "length", &length_v);
    gint64 length = g_value_get_int64 (&length_v);
    if (length != -1) {
      argv.bitmask |= GUESTFS_FSTRIM_LENGTH_BITMASK;
      argv.length = length;
    }
    GValue minimumfreeextent_v = {0, };
    g_value_init (&minimumfreeextent_v, G_TYPE_INT64);
    g_object_get_property (G_OBJECT (optargs), "minimumfreeextent", &minimumfreeextent_v);
    gint64 minimumfreeextent = g_value_get_int64 (&minimumfreeextent_v);
    if (minimumfreeextent != -1) {
      argv.bitmask |= GUESTFS_FSTRIM_MINIMUMFREEEXTENT_BITMASK;
      argv.minimumfreeextent = minimumfreeextent;
    }
    argvp = &argv;
  }
  int ret = guestfs_fstrim_argv (g, mountpoint, argvp);
  if (ret == -1) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return FALSE;
  }

  return TRUE;
}

/**
 * guestfs_session_get_append:
 * @session: (transfer none): A GuestfsSession object
 * @err: A GError object to receive any generated errors
 *
 * get the additional kernel options
 *
 * Return the additional kernel options which are added to the libguestfs
 * appliance kernel command line.
 * 
 * If @NULL then no options are added.
 * 
 * Returns: (transfer none): the returned string. Note that NULL does not indicate error
 * Since: 1.0.26
 */
const gchar *
guestfs_session_get_append (GuestfsSession *session, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "get_append");
    return NULL;
  }

  const char *ret = guestfs_get_append (g);

  return ret;
}

/**
 * guestfs_session_get_attach_method:
 * @session: (transfer none): A GuestfsSession object
 * @err: A GError object to receive any generated errors
 *
 * get the backend
 *
 * Return the current backend.
 * 
 * See guestfs_session_set_backend() and "BACKEND" in guestfs(3).
 * 
 * Returns: (transfer full): the returned string, or NULL on error
 * Deprecated: In new code, use guestfs_session_get_backend() instead
 * Since: 1.9.8
 */
gchar *
guestfs_session_get_attach_method (GuestfsSession *session, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "get_attach_method");
    return NULL;
  }

  char *ret = guestfs_get_attach_method (g);
  if (ret == NULL) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return NULL;
  }

  return ret;
}

/**
 * guestfs_session_get_autosync:
 * @session: (transfer none): A GuestfsSession object
 * @err: A GError object to receive any generated errors
 *
 * get autosync mode
 *
 * Get the autosync flag.
 * 
 * Returns: the returned value, or -1 on error
 * Since: 0.3
 */
gint8
guestfs_session_get_autosync (GuestfsSession *session, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "get_autosync");
    return -1;
  }

  int ret = guestfs_get_autosync (g);
  if (ret == -1) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return -1;
  }

  return ret;
}

/**
 * guestfs_session_get_backend:
 * @session: (transfer none): A GuestfsSession object
 * @err: A GError object to receive any generated errors
 *
 * get the backend
 *
 * Return the current backend.
 * 
 * This handle property was previously called the "attach method".
 * 
 * See guestfs_session_set_backend() and "BACKEND" in guestfs(3).
 * 
 * Returns: (transfer full): the returned string, or NULL on error
 * Since: 1.21.26
 */
gchar *
guestfs_session_get_backend (GuestfsSession *session, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "get_backend");
    return NULL;
  }

  char *ret = guestfs_get_backend (g);
  if (ret == NULL) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return NULL;
  }

  return ret;
}

/**
 * guestfs_session_get_backend_setting:
 * @session: (transfer none): A GuestfsSession object
 * @name: (transfer none) (type utf8):
 * @err: A GError object to receive any generated errors
 *
 * get a single per-backend settings string
 *
 * Find a backend setting string which is either "name" or begins with
 * "name=". If "name", this returns the string "1". If "name=", this
 * returns the part after the equals sign (which may be an empty string).
 * 
 * If no such setting is found, this function throws an error. The errno
 * (see guestfs_session_last_errno()) will be @ESRCH in this case.
 * 
 * See "BACKEND" in guestfs(3), "BACKEND SETTINGS" in guestfs(3).
 * 
 * Returns: (transfer full): the returned string, or NULL on error
 * Since: 1.27.2
 */
gchar *
guestfs_session_get_backend_setting (GuestfsSession *session, const gchar *name, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "get_backend_setting");
    return NULL;
  }

  char *ret = guestfs_get_backend_setting (g, name);
  if (ret == NULL) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return NULL;
  }

  return ret;
}

/**
 * guestfs_session_get_backend_settings:
 * @session: (transfer none): A GuestfsSession object
 * @err: A GError object to receive any generated errors
 *
 * get per-backend settings
 *
 * Return the current backend settings.
 * 
 * This call returns all backend settings strings. If you want to find a
 * single backend setting, see guestfs_session_get_backend_setting().
 * 
 * See "BACKEND" in guestfs(3), "BACKEND SETTINGS" in guestfs(3).
 * 
 * Returns: (transfer full) (array zero-terminated=1) (element-type utf8): an array of returned strings, or NULL on error
 * Since: 1.25.24
 */
gchar **
guestfs_session_get_backend_settings (GuestfsSession *session, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "get_backend_settings");
    return NULL;
  }

  char **ret = guestfs_get_backend_settings (g);
  if (ret == NULL) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return NULL;
  }

  return ret;
}

/**
 * guestfs_session_get_cachedir:
 * @session: (transfer none): A GuestfsSession object
 * @err: A GError object to receive any generated errors
 *
 * get the appliance cache directory
 *
 * Get the directory used by the handle to store the appliance cache.
 * 
 * Returns: (transfer full): the returned string, or NULL on error
 * Since: 1.19.58
 */
gchar *
guestfs_session_get_cachedir (GuestfsSession *session, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "get_cachedir");
    return NULL;
  }

  char *ret = guestfs_get_cachedir (g);
  if (ret == NULL) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return NULL;
  }

  return ret;
}

/**
 * guestfs_session_get_direct:
 * @session: (transfer none): A GuestfsSession object
 * @err: A GError object to receive any generated errors
 *
 * get direct appliance mode flag
 *
 * Return the direct appliance mode flag.
 * 
 * Returns: the returned value, or -1 on error
 * Since: 1.0.72
 */
gint8
guestfs_session_get_direct (GuestfsSession *session, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "get_direct");
    return -1;
  }

  int ret = guestfs_get_direct (g);
  if (ret == -1) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return -1;
  }

  return ret;
}

/**
 * guestfs_session_get_e2attrs:
 * @session: (transfer none): A GuestfsSession object
 * @file: (transfer none) (type filename):
 * @err: A GError object to receive any generated errors
 *
 * get ext2 file attributes of a file
 *
 * This returns the file attributes associated with file.
 * 
 * The attributes are a set of bits associated with each inode which affect
 * the behaviour of the file. The attributes are returned as a string of
 * letters (described below). The string may be empty, indicating that no
 * file attributes are set for this file.
 * 
 * These attributes are only present when the file is located on an
 * ext2/3/4 filesystem. Using this call on other filesystem types will
 * result in an error.
 * 
 * The characters (file attributes) in the returned string are currently:
 * 
 * 'A' When the file is accessed, its atime is not modified.
 * 
 * 'a' The file is append-only.
 * 
 * 'c' The file is compressed on-disk.
 * 
 * 'D' (Directories only.) Changes to this directory are written
 * synchronously to disk.
 * 
 * 'd' The file is not a candidate for backup (see dump(8)).
 * 
 * 'E' The file has compression errors.
 * 
 * 'e' The file is using extents.
 * 
 * 'h' The file is storing its blocks in units of the filesystem blocksize
 * instead of sectors.
 * 
 * 'I' (Directories only.) The directory is using hashed trees.
 * 
 * 'i' The file is immutable. It cannot be modified, deleted or renamed. No
 * link can be created to this file.
 * 
 * 'j' The file is data-journaled.
 * 
 * 's' When the file is deleted, all its blocks will be zeroed.
 * 
 * 'S' Changes to this file are written synchronously to disk.
 * 
 * 'T' (Directories only.) This is a hint to the block allocator that
 * subdirectories contained in this directory should be spread across
 * blocks. If not present, the block allocator will try to group
 * subdirectories together.
 * 
 * 't' For a file, this disables tail-merging. (Not used by upstream
 * implementations of ext2.)
 * 
 * 'u' When the file is deleted, its blocks will be saved, allowing the
 * file to be undeleted.
 * 
 * 'X' The raw contents of the compressed file may be accessed.
 * 
 * 'Z' The compressed file is dirty.
 * 
 * More file attributes may be added to this list later. Not all file
 * attributes may be set for all kinds of files. For detailed information,
 * consult the chattr(1) man page.
 * 
 * See also guestfs_session_set_e2attrs().
 * 
 * Don't confuse these attributes with extended attributes (see
 * guestfs_session_getxattr()).
 * 
 * Returns: (transfer full): the returned string, or NULL on error
 * Since: 1.17.31
 */
gchar *
guestfs_session_get_e2attrs (GuestfsSession *session, const gchar *file, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "get_e2attrs");
    return NULL;
  }

  char *ret = guestfs_get_e2attrs (g, file);
  if (ret == NULL) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return NULL;
  }

  return ret;
}

/**
 * guestfs_session_get_e2generation:
 * @session: (transfer none): A GuestfsSession object
 * @file: (transfer none) (type filename):
 * @err: A GError object to receive any generated errors
 *
 * get ext2 file generation of a file
 *
 * This returns the ext2 file generation of a file. The generation (which
 * used to be called the "version") is a number associated with an inode.
 * This is most commonly used by NFS servers.
 * 
 * The generation is only present when the file is located on an ext2/3/4
 * filesystem. Using this call on other filesystem types will result in an
 * error.
 * 
 * See guestfs_session_set_e2generation().
 * 
 * Returns: the returned value, or -1 on error
 * Since: 1.17.31
 */
gint64
guestfs_session_get_e2generation (GuestfsSession *session, const gchar *file, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "get_e2generation");
    return -1;
  }

  int64_t ret = guestfs_get_e2generation (g, file);
  if (ret == -1) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return -1;
  }

  return ret;
}

/**
 * guestfs_session_get_e2label:
 * @session: (transfer none): A GuestfsSession object
 * @device: (transfer none) (type filename):
 * @err: A GError object to receive any generated errors
 *
 * get the ext2/3/4 filesystem label
 *
 * This returns the ext2/3/4 filesystem label of the filesystem on @device.
 * 
 * Returns: (transfer full): the returned string, or NULL on error
 * Deprecated: In new code, use guestfs_session_vfs_label() instead
 * Since: 1.0.15
 */
gchar *
guestfs_session_get_e2label (GuestfsSession *session, const gchar *device, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "get_e2label");
    return NULL;
  }

  char *ret = guestfs_get_e2label (g, device);
  if (ret == NULL) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return NULL;
  }

  return ret;
}

/**
 * guestfs_session_get_e2uuid:
 * @session: (transfer none): A GuestfsSession object
 * @device: (transfer none) (type filename):
 * @err: A GError object to receive any generated errors
 *
 * get the ext2/3/4 filesystem UUID
 *
 * This returns the ext2/3/4 filesystem UUID of the filesystem on @device.
 * 
 * Returns: (transfer full): the returned string, or NULL on error
 * Deprecated: In new code, use guestfs_session_vfs_uuid() instead
 * Since: 1.0.15
 */
gchar *
guestfs_session_get_e2uuid (GuestfsSession *session, const gchar *device, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "get_e2uuid");
    return NULL;
  }

  char *ret = guestfs_get_e2uuid (g, device);
  if (ret == NULL) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return NULL;
  }

  return ret;
}

/**
 * guestfs_session_get_hv:
 * @session: (transfer none): A GuestfsSession object
 * @err: A GError object to receive any generated errors
 *
 * get the hypervisor binary
 *
 * Return the current hypervisor binary.
 * 
 * This is always non-NULL. If it wasn't set already, then this will return
 * the default qemu binary name.
 * 
 * Returns: (transfer full): the returned string, or NULL on error
 * Since: 1.23.17
 */
gchar *
guestfs_session_get_hv (GuestfsSession *session, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "get_hv");
    return NULL;
  }

  char *ret = guestfs_get_hv (g);
  if (ret == NULL) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return NULL;
  }

  return ret;
}

/**
 * guestfs_session_get_libvirt_requested_credential_challenge:
 * @session: (transfer none): A GuestfsSession object
 * @index: (type gint32):
 * @err: A GError object to receive any generated errors
 *
 * challenge of i'th requested credential
 *
 * Get the challenge (provided by libvirt) for the @index'th requested
 * credential. If libvirt did not provide a challenge, this returns the
 * empty string "".
 * 
 * See "LIBVIRT AUTHENTICATION" in guestfs(3) for documentation and example
 * code.
 * 
 * Returns: (transfer full): the returned string, or NULL on error
 * Since: 1.19.52
 */
gchar *
guestfs_session_get_libvirt_requested_credential_challenge (GuestfsSession *session, gint32 index, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "get_libvirt_requested_credential_challenge");
    return NULL;
  }

  char *ret = guestfs_get_libvirt_requested_credential_challenge (g, index);
  if (ret == NULL) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return NULL;
  }

  return ret;
}

/**
 * guestfs_session_get_libvirt_requested_credential_defresult:
 * @session: (transfer none): A GuestfsSession object
 * @index: (type gint32):
 * @err: A GError object to receive any generated errors
 *
 * default result of i'th requested credential
 *
 * Get the default result (provided by libvirt) for the @index'th requested
 * credential. If libvirt did not provide a default result, this returns
 * the empty string "".
 * 
 * See "LIBVIRT AUTHENTICATION" in guestfs(3) for documentation and example
 * code.
 * 
 * Returns: (transfer full): the returned string, or NULL on error
 * Since: 1.19.52
 */
gchar *
guestfs_session_get_libvirt_requested_credential_defresult (GuestfsSession *session, gint32 index, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "get_libvirt_requested_credential_defresult");
    return NULL;
  }

  char *ret = guestfs_get_libvirt_requested_credential_defresult (g, index);
  if (ret == NULL) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return NULL;
  }

  return ret;
}

/**
 * guestfs_session_get_libvirt_requested_credential_prompt:
 * @session: (transfer none): A GuestfsSession object
 * @index: (type gint32):
 * @err: A GError object to receive any generated errors
 *
 * prompt of i'th requested credential
 *
 * Get the prompt (provided by libvirt) for the @index'th requested
 * credential. If libvirt did not provide a prompt, this returns the empty
 * string "".
 * 
 * See "LIBVIRT AUTHENTICATION" in guestfs(3) for documentation and example
 * code.
 * 
 * Returns: (transfer full): the returned string, or NULL on error
 * Since: 1.19.52
 */
gchar *
guestfs_session_get_libvirt_requested_credential_prompt (GuestfsSession *session, gint32 index, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "get_libvirt_requested_credential_prompt");
    return NULL;
  }

  char *ret = guestfs_get_libvirt_requested_credential_prompt (g, index);
  if (ret == NULL) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return NULL;
  }

  return ret;
}

/**
 * guestfs_session_get_libvirt_requested_credentials:
 * @session: (transfer none): A GuestfsSession object
 * @err: A GError object to receive any generated errors
 *
 * get list of credentials requested by libvirt
 *
 * This should only be called during the event callback for events of type
 * @GUESTFS_EVENT_LIBVIRT_AUTH.
 * 
 * Return the list of credentials requested by libvirt. Possible values are
 * a subset of the strings provided when you called
 * guestfs_session_set_libvirt_supported_credentials().
 * 
 * See "LIBVIRT AUTHENTICATION" in guestfs(3) for documentation and example
 * code.
 * 
 * Returns: (transfer full) (array zero-terminated=1) (element-type utf8): an array of returned strings, or NULL on error
 * Since: 1.19.52
 */
gchar **
guestfs_session_get_libvirt_requested_credentials (GuestfsSession *session, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "get_libvirt_requested_credentials");
    return NULL;
  }

  char **ret = guestfs_get_libvirt_requested_credentials (g);
  if (ret == NULL) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return NULL;
  }

  return ret;
}

/**
 * guestfs_session_get_memsize:
 * @session: (transfer none): A GuestfsSession object
 * @err: A GError object to receive any generated errors
 *
 * get memory allocated to the hypervisor
 *
 * This gets the memory size in megabytes allocated to the hypervisor.
 * 
 * If guestfs_session_set_memsize() was not called on this handle, and if
 * @LIBGUESTFS_MEMSIZE was not set, then this returns the compiled-in
 * default value for memsize.
 * 
 * For more information on the architecture of libguestfs, see guestfs(3).
 * 
 * Returns: the returned value, or -1 on error
 * Since: 1.0.55
 */
gint32
guestfs_session_get_memsize (GuestfsSession *session, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "get_memsize");
    return -1;
  }

  int ret = guestfs_get_memsize (g);
  if (ret == -1) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return -1;
  }

  return ret;
}

/**
 * guestfs_session_get_network:
 * @session: (transfer none): A GuestfsSession object
 * @err: A GError object to receive any generated errors
 *
 * get enable network flag
 *
 * This returns the enable network flag.
 * 
 * Returns: the returned value, or -1 on error
 * Since: 1.5.4
 */
gint8
guestfs_session_get_network (GuestfsSession *session, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "get_network");
    return -1;
  }

  int ret = guestfs_get_network (g);
  if (ret == -1) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return -1;
  }

  return ret;
}

/**
 * guestfs_session_get_path:
 * @session: (transfer none): A GuestfsSession object
 * @err: A GError object to receive any generated errors
 *
 * get the search path
 *
 * Return the current search path.
 * 
 * This is always non-NULL. If it wasn't set already, then this will return
 * the default path.
 * 
 * Returns: (transfer none): the returned string, or NULL on error
 * Since: 0.3
 */
const gchar *
guestfs_session_get_path (GuestfsSession *session, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "get_path");
    return NULL;
  }

  const char *ret = guestfs_get_path (g);
  if (ret == NULL) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return NULL;
  }

  return ret;
}

/**
 * guestfs_session_get_pgroup:
 * @session: (transfer none): A GuestfsSession object
 * @err: A GError object to receive any generated errors
 *
 * get process group flag
 *
 * This returns the process group flag.
 * 
 * Returns: the returned value, or -1 on error
 * Since: 1.11.18
 */
gint8
guestfs_session_get_pgroup (GuestfsSession *session, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "get_pgroup");
    return -1;
  }

  int ret = guestfs_get_pgroup (g);
  if (ret == -1) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return -1;
  }

  return ret;
}

/**
 * guestfs_session_get_pid:
 * @session: (transfer none): A GuestfsSession object
 * @err: A GError object to receive any generated errors
 *
 * get PID of hypervisor
 *
 * Return the process ID of the hypervisor. If there is no hypervisor
 * running, then this will return an error.
 * 
 * This is an internal call used for debugging and testing.
 * 
 * Returns: the returned value, or -1 on error
 * Since: 1.0.56
 */
gint32
guestfs_session_get_pid (GuestfsSession *session, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "get_pid");
    return -1;
  }

  int ret = guestfs_get_pid (g);
  if (ret == -1) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return -1;
  }

  return ret;
}

/**
 * guestfs_session_get_program:
 * @session: (transfer none): A GuestfsSession object
 * @err: A GError object to receive any generated errors
 *
 * get the program name
 *
 * Get the program name. See guestfs_session_set_program().
 * 
 * Returns: (transfer none): the returned string, or NULL on error
 * Since: 1.21.29
 */
const gchar *
guestfs_session_get_program (GuestfsSession *session, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "get_program");
    return NULL;
  }

  const char *ret = guestfs_get_program (g);
  if (ret == NULL) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return NULL;
  }

  return ret;
}

/**
 * guestfs_session_get_qemu:
 * @session: (transfer none): A GuestfsSession object
 * @err: A GError object to receive any generated errors
 *
 * get the hypervisor binary (usually qemu)
 *
 * Return the current hypervisor binary (usually qemu).
 * 
 * This is always non-NULL. If it wasn't set already, then this will return
 * the default qemu binary name.
 * 
 * Returns: (transfer none): the returned string, or NULL on error
 * Deprecated: In new code, use guestfs_session_get_hv() instead
 * Since: 1.0.6
 */
const gchar *
guestfs_session_get_qemu (GuestfsSession *session, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "get_qemu");
    return NULL;
  }

  const char *ret = guestfs_get_qemu (g);
  if (ret == NULL) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return NULL;
  }

  return ret;
}

/**
 * guestfs_session_get_recovery_proc:
 * @session: (transfer none): A GuestfsSession object
 * @err: A GError object to receive any generated errors
 *
 * get recovery process enabled flag
 *
 * Return the recovery process enabled flag.
 * 
 * Returns: the returned value, or -1 on error
 * Since: 1.0.77
 */
gint8
guestfs_session_get_recovery_proc (GuestfsSession *session, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "get_recovery_proc");
    return -1;
  }

  int ret = guestfs_get_recovery_proc (g);
  if (ret == -1) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return -1;
  }

  return ret;
}

/**
 * guestfs_session_get_selinux:
 * @session: (transfer none): A GuestfsSession object
 * @err: A GError object to receive any generated errors
 *
 * get SELinux enabled flag
 *
 * This returns the current setting of the selinux flag which is passed to
 * the appliance at boot time. See guestfs_session_set_selinux().
 * 
 * For more information on the architecture of libguestfs, see guestfs(3).
 * 
 * Returns: the returned value, or -1 on error
 * Since: 1.0.67
 */
gint8
guestfs_session_get_selinux (GuestfsSession *session, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "get_selinux");
    return -1;
  }

  int ret = guestfs_get_selinux (g);
  if (ret == -1) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return -1;
  }

  return ret;
}

/**
 * guestfs_session_get_smp:
 * @session: (transfer none): A GuestfsSession object
 * @err: A GError object to receive any generated errors
 *
 * get number of virtual CPUs in appliance
 *
 * This returns the number of virtual CPUs assigned to the appliance.
 * 
 * Returns: the returned value, or -1 on error
 * Since: 1.13.15
 */
gint32
guestfs_session_get_smp (GuestfsSession *session, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "get_smp");
    return -1;
  }

  int ret = guestfs_get_smp (g);
  if (ret == -1) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return -1;
  }

  return ret;
}

/**
 * guestfs_session_get_state:
 * @session: (transfer none): A GuestfsSession object
 * @err: A GError object to receive any generated errors
 *
 * get the current state
 *
 * This returns the current state as an opaque integer. This is only useful
 * for printing debug and internal error messages.
 * 
 * For more information on states, see guestfs(3).
 * 
 * Returns: the returned value, or -1 on error
 * Since: 1.0.2
 */
gint32
guestfs_session_get_state (GuestfsSession *session, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "get_state");
    return -1;
  }

  int ret = guestfs_get_state (g);
  if (ret == -1) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return -1;
  }

  return ret;
}

/**
 * guestfs_session_get_tmpdir:
 * @session: (transfer none): A GuestfsSession object
 * @err: A GError object to receive any generated errors
 *
 * get the temporary directory
 *
 * Get the directory used by the handle to store temporary files.
 * 
 * Returns: (transfer full): the returned string, or NULL on error
 * Since: 1.19.58
 */
gchar *
guestfs_session_get_tmpdir (GuestfsSession *session, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "get_tmpdir");
    return NULL;
  }

  char *ret = guestfs_get_tmpdir (g);
  if (ret == NULL) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return NULL;
  }

  return ret;
}

/**
 * guestfs_session_get_trace:
 * @session: (transfer none): A GuestfsSession object
 * @err: A GError object to receive any generated errors
 *
 * get command trace enabled flag
 *
 * Return the command trace flag.
 * 
 * Returns: the returned value, or -1 on error
 * Since: 1.0.69
 */
gint8
guestfs_session_get_trace (GuestfsSession *session, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "get_trace");
    return -1;
  }

  int ret = guestfs_get_trace (g);
  if (ret == -1) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return -1;
  }

  return ret;
}

/**
 * guestfs_session_get_umask:
 * @session: (transfer none): A GuestfsSession object
 * @err: A GError object to receive any generated errors
 *
 * get the current umask
 *
 * Return the current umask. By default the umask is @022 unless it has
 * been set by calling guestfs_session_umask().
 * 
 * Returns: the returned value, or -1 on error
 * Since: 1.3.4
 */
gint32
guestfs_session_get_umask (GuestfsSession *session, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "get_umask");
    return -1;
  }

  int ret = guestfs_get_umask (g);
  if (ret == -1) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return -1;
  }

  return ret;
}

/**
 * guestfs_session_get_verbose:
 * @session: (transfer none): A GuestfsSession object
 * @err: A GError object to receive any generated errors
 *
 * get verbose mode
 *
 * This returns the verbose messages flag.
 * 
 * Returns: the returned value, or -1 on error
 * Since: 0.3
 */
gint8
guestfs_session_get_verbose (GuestfsSession *session, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "get_verbose");
    return -1;
  }

  int ret = guestfs_get_verbose (g);
  if (ret == -1) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return -1;
  }

  return ret;
}

/**
 * guestfs_session_getcon:
 * @session: (transfer none): A GuestfsSession object
 * @err: A GError object to receive any generated errors
 *
 * get SELinux security context
 *
 * This gets the SELinux security context of the daemon.
 * 
 * See the documentation about SELINUX in guestfs(3), and
 * guestfs_session_setcon()
 * 
 * Returns: (transfer full): the returned string, or NULL on error
 * Since: 1.0.67
 */
gchar *
guestfs_session_getcon (GuestfsSession *session, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "getcon");
    return NULL;
  }

  char *ret = guestfs_getcon (g);
  if (ret == NULL) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return NULL;
  }

  return ret;
}

/**
 * guestfs_session_getxattr:
 * @session: (transfer none): A GuestfsSession object
 * @path: (transfer none) (type filename):
 * @name: (transfer none) (type utf8):
 * @size_r: The size of the returned buffer, in bytes
 * @err: A GError object to receive any generated errors
 *
 * get a single extended attribute
 *
 * Get a single extended attribute from file @path named @name. This call
 * follows symlinks. If you want to lookup an extended attribute for the
 * symlink itself, use guestfs_session_lgetxattr().
 * 
 * Normally it is better to get all extended attributes from a file in one
 * go by calling guestfs_session_getxattrs(). However some Linux filesystem
 * implementations are buggy and do not provide a way to list out
 * attributes. For these filesystems (notably ntfs-3g) you have to know the
 * names of the extended attributes you want in advance and call this
 * function.
 * 
 * Extended attribute values are blobs of binary data. If there is no
 * extended attribute named @name, this returns an error.
 * 
 * See also: guestfs_session_getxattrs(), guestfs_session_lgetxattr(),
 * attr(5).
 * 
 * Returns: (transfer full) (array length=size_r) (element-type guint8): an array of binary data, or NULL on error
 * Since: 1.7.24
 */
guint8 *
guestfs_session_getxattr (GuestfsSession *session, const gchar *path, const gchar *name, gsize *size_r, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "getxattr");
    return NULL;
  }

  char *ret = guestfs_getxattr (g, path, name, size_r);
  if (ret == NULL) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return NULL;
  }

  return (guint8 *) ret;
}

/**
 * guestfs_session_getxattrs:
 * @session: (transfer none): A GuestfsSession object
 * @path: (transfer none) (type filename):
 * @err: A GError object to receive any generated errors
 *
 * list extended attributes of a file or directory
 *
 * This call lists the extended attributes of the file or directory @path.
 * 
 * At the system call level, this is a combination of the listxattr(2) and
 * getxattr(2) calls.
 * 
 * See also: guestfs_session_lgetxattrs(), attr(5).
 * 
 * Returns: (transfer full) (array zero-terminated=1) (element-type GuestfsXAttr): an array of XAttr objects, or NULL on error
 * Since: 1.0.59
 */
GuestfsXAttr **
guestfs_session_getxattrs (GuestfsSession *session, const gchar *path, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "getxattrs");
    return NULL;
  }

  struct guestfs_xattr_list *ret = guestfs_getxattrs (g, path);
  if (ret == NULL) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return NULL;
  }

  GuestfsXAttr **l = g_malloc (sizeof (GuestfsXAttr*) * (ret->len + 1));
  gsize i;
  for (i = 0; i < ret->len; i++) {
    l[i] = g_slice_new0 (GuestfsXAttr);
    if (ret->val[i].attrname) l[i]->attrname = g_strdup (ret->val[i].attrname);
    if (ret->val[i].attrval) {
      l[i]->attrval = g_byte_array_sized_new (ret->val[i].attrval_len);
      g_byte_array_append (l[i]->attrval, (const guint8 *) ret->val[i].attrval, ret->val[i].attrval_len);
    }
  }
  guestfs_free_xattr_list (ret);
  l[i] = NULL;
  return l;
}

/**
 * guestfs_session_glob_expand:
 * @session: (transfer none): A GuestfsSession object
 * @pattern: (transfer none) (type filename):
 * @err: A GError object to receive any generated errors
 *
 * expand a wildcard path
 *
 * This command searches for all the pathnames matching @pattern according
 * to the wildcard expansion rules used by the shell.
 * 
 * If no paths match, then this returns an empty list (note: not an error).
 * 
 * It is just a wrapper around the C glob(3) function with flags
 * "GLOB_MARK|GLOB_BRACE". See that manual page for more details.
 * 
 * Notice that there is no equivalent command for expanding a device name
 * (eg. /dev/sd*). Use guestfs_session_list_devices(),
 * guestfs_session_list_partitions() etc functions instead.
 * 
 * Returns: (transfer full) (array zero-terminated=1) (element-type utf8): an array of returned strings, or NULL on error
 * Since: 1.0.50
 */
gchar **
guestfs_session_glob_expand (GuestfsSession *session, const gchar *pattern, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "glob_expand");
    return NULL;
  }

  char **ret = guestfs_glob_expand (g, pattern);
  if (ret == NULL) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return NULL;
  }

  return ret;
}

/**
 * guestfs_session_grep:
 * @session: (transfer none): A GuestfsSession object
 * @regex: (transfer none) (type utf8):
 * @path: (transfer none) (type filename):
 * @optargs: (transfer none) (allow-none): a GuestfsGrep containing optional arguments
 * @err: A GError object to receive any generated errors
 *
 * return lines matching a pattern
 *
 * This calls the external @grep program and returns the matching lines.
 * 
 * The optional flags are:
 * 
 * @extended
 * Use extended regular expressions. This is the same as using the *-E*
 * flag.
 * 
 * @fixed
 * Match fixed (don't use regular expressions). This is the same as
 * using the *-F* flag.
 * 
 * @insensitive
 * Match case-insensitive. This is the same as using the *-i* flag.
 * 
 * @compressed
 * Use @zgrep instead of @grep. This allows the input to be compress-
 * or gzip-compressed.
 * 
 * Returns: (transfer full) (array zero-terminated=1) (element-type utf8): an array of returned strings, or NULL on error
 * Since: 1.0.66
 */
gchar **
guestfs_session_grep (GuestfsSession *session, const gchar *regex, const gchar *path, GuestfsGrep *optargs, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "grep");
    return NULL;
  }

  struct guestfs_grep_opts_argv argv;
  struct guestfs_grep_opts_argv *argvp = NULL;

  if (optargs) {
    argv.bitmask = 0;

    GValue extended_v = {0, };
    g_value_init (&extended_v, GUESTFS_TYPE_TRISTATE);
    g_object_get_property (G_OBJECT (optargs), "extended", &extended_v);
    GuestfsTristate extended = g_value_get_enum (&extended_v);
    if (extended != GUESTFS_TRISTATE_NONE) {
      argv.bitmask |= GUESTFS_GREP_OPTS_EXTENDED_BITMASK;
      argv.extended = extended;
    }
    GValue fixed_v = {0, };
    g_value_init (&fixed_v, GUESTFS_TYPE_TRISTATE);
    g_object_get_property (G_OBJECT (optargs), "fixed", &fixed_v);
    GuestfsTristate fixed = g_value_get_enum (&fixed_v);
    if (fixed != GUESTFS_TRISTATE_NONE) {
      argv.bitmask |= GUESTFS_GREP_OPTS_FIXED_BITMASK;
      argv.fixed = fixed;
    }
    GValue insensitive_v = {0, };
    g_value_init (&insensitive_v, GUESTFS_TYPE_TRISTATE);
    g_object_get_property (G_OBJECT (optargs), "insensitive", &insensitive_v);
    GuestfsTristate insensitive = g_value_get_enum (&insensitive_v);
    if (insensitive != GUESTFS_TRISTATE_NONE) {
      argv.bitmask |= GUESTFS_GREP_OPTS_INSENSITIVE_BITMASK;
      argv.insensitive = insensitive;
    }
    GValue compressed_v = {0, };
    g_value_init (&compressed_v, GUESTFS_TYPE_TRISTATE);
    g_object_get_property (G_OBJECT (optargs), "compressed", &compressed_v);
    GuestfsTristate compressed = g_value_get_enum (&compressed_v);
    if (compressed != GUESTFS_TRISTATE_NONE) {
      argv.bitmask |= GUESTFS_GREP_OPTS_COMPRESSED_BITMASK;
      argv.compressed = compressed;
    }
    argvp = &argv;
  }
  char **ret = guestfs_grep_opts_argv (g, regex, path, argvp);
  if (ret == NULL) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return NULL;
  }

  return ret;
}

/**
 * guestfs_session_grepi:
 * @session: (transfer none): A GuestfsSession object
 * @regex: (transfer none) (type utf8):
 * @path: (transfer none) (type filename):
 * @err: A GError object to receive any generated errors
 *
 * return lines matching a pattern
 *
 * This calls the external "grep -i" program and returns the matching
 * lines.
 * 
 * Returns: (transfer full) (array zero-terminated=1) (element-type utf8): an array of returned strings, or NULL on error
 * Deprecated: In new code, use guestfs_session_grep() instead
 * Since: 1.0.66
 */
gchar **
guestfs_session_grepi (GuestfsSession *session, const gchar *regex, const gchar *path, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "grepi");
    return NULL;
  }

  char **ret = guestfs_grepi (g, regex, path);
  if (ret == NULL) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return NULL;
  }

  return ret;
}

/**
 * guestfs_session_grub_install:
 * @session: (transfer none): A GuestfsSession object
 * @root: (transfer none) (type filename):
 * @device: (transfer none) (type filename):
 * @err: A GError object to receive any generated errors
 *
 * install GRUB 1
 *
 * This command installs GRUB 1 (the Grand Unified Bootloader) on @device,
 * with the root directory being @root.
 * 
 * Notes:
 * 
 * *   There is currently no way in the API to install grub2, which is used
 * by most modern Linux guests. It is possible to run the grub2 command
 * from the guest, although see the caveats in "RUNNING COMMANDS" in
 * guestfs(3).
 * 
 * *   This uses @grub-install from the host. Unfortunately grub is not
 * always compatible with itself, so this only works in rather narrow
 * circumstances. Careful testing with each guest version is advisable.
 * 
 * *   If grub-install reports the error "No suitable drive was found in
 * the generated device map." it may be that you need to create a
 * /boot/grub/device.map file first that contains the mapping between
 * grub device names and Linux device names. It is usually sufficient
 * to create a file containing:
 * 
 * <![CDATA[(hd0) /dev/vda]]>
 * 
 * replacing /dev/vda with the name of the installation device.
 * 
 * Returns: true on success, false on error
 * Since: 1.0.17
 */
gboolean
guestfs_session_grub_install (GuestfsSession *session, const gchar *root, const gchar *device, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "grub_install");
    return FALSE;
  }

  int ret = guestfs_grub_install (g, root, device);
  if (ret == -1) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return FALSE;
  }

  return TRUE;
}

/**
 * guestfs_session_head:
 * @session: (transfer none): A GuestfsSession object
 * @path: (transfer none) (type filename):
 * @err: A GError object to receive any generated errors
 *
 * return first 10 lines of a file
 *
 * This command returns up to the first 10 lines of a file as a list of
 * strings.
 * 
 * Returns: (transfer full) (array zero-terminated=1) (element-type utf8): an array of returned strings, or NULL on error
 * Since: 1.0.54
 */
gchar **
guestfs_session_head (GuestfsSession *session, const gchar *path, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "head");
    return NULL;
  }

  char **ret = guestfs_head (g, path);
  if (ret == NULL) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return NULL;
  }

  return ret;
}

/**
 * guestfs_session_head_n:
 * @session: (transfer none): A GuestfsSession object
 * @nrlines: (type gint32):
 * @path: (transfer none) (type filename):
 * @err: A GError object to receive any generated errors
 *
 * return first N lines of a file
 *
 * If the parameter @nrlines is a positive number, this returns the first
 * @nrlines lines of the file @path.
 * 
 * If the parameter @nrlines is a negative number, this returns lines from
 * the file @path, excluding the last @nrlines lines.
 * 
 * If the parameter @nrlines is zero, this returns an empty list.
 * 
 * Returns: (transfer full) (array zero-terminated=1) (element-type utf8): an array of returned strings, or NULL on error
 * Since: 1.0.54
 */
gchar **
guestfs_session_head_n (GuestfsSession *session, gint32 nrlines, const gchar *path, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "head_n");
    return NULL;
  }

  char **ret = guestfs_head_n (g, nrlines, path);
  if (ret == NULL) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return NULL;
  }

  return ret;
}

/**
 * guestfs_session_hexdump:
 * @session: (transfer none): A GuestfsSession object
 * @path: (transfer none) (type filename):
 * @err: A GError object to receive any generated errors
 *
 * dump a file in hexadecimal
 *
 * This runs "hexdump -C" on the given @path. The result is the
 * human-readable, canonical hex dump of the file.
 * 
 * Returns: (transfer full): the returned string, or NULL on error
 * Since: 1.0.22
 */
gchar *
guestfs_session_hexdump (GuestfsSession *session, const gchar *path, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "hexdump");
    return NULL;
  }

  char *ret = guestfs_hexdump (g, path);
  if (ret == NULL) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return NULL;
  }

  return ret;
}

/**
 * guestfs_session_hivex_close:
 * @session: (transfer none): A GuestfsSession object
 * @err: A GError object to receive any generated errors
 *
 * close the current hivex handle
 *
 * Close the current hivex handle.
 * 
 * This is a wrapper around the hivex(3) call of the same name.
 * 
 * Returns: true on success, false on error
 * Since: 1.19.35
 */
gboolean
guestfs_session_hivex_close (GuestfsSession *session, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "hivex_close");
    return FALSE;
  }

  int ret = guestfs_hivex_close (g);
  if (ret == -1) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return FALSE;
  }

  return TRUE;
}

/**
 * guestfs_session_hivex_commit:
 * @session: (transfer none): A GuestfsSession object
 * @filename: (transfer none) (type utf8) (allow-none):
 * @err: A GError object to receive any generated errors
 *
 * commit (write) changes back to the hive
 *
 * Commit (write) changes to the hive.
 * 
 * If the optional filename parameter is null, then the changes are written
 * back to the same hive that was opened. If this is not null then they are
 * written to the alternate filename given and the original hive is left
 * untouched.
 * 
 * This is a wrapper around the hivex(3) call of the same name.
 * 
 * Returns: true on success, false on error
 * Since: 1.19.35
 */
gboolean
guestfs_session_hivex_commit (GuestfsSession *session, const gchar *filename, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "hivex_commit");
    return FALSE;
  }

  int ret = guestfs_hivex_commit (g, filename);
  if (ret == -1) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return FALSE;
  }

  return TRUE;
}

/**
 * guestfs_session_hivex_node_add_child:
 * @session: (transfer none): A GuestfsSession object
 * @parent: (type gint64):
 * @name: (transfer none) (type utf8):
 * @err: A GError object to receive any generated errors
 *
 * add a child node
 *
 * Add a child node to @parent named @name.
 * 
 * This is a wrapper around the hivex(3) call of the same name.
 * 
 * Returns: the returned value, or -1 on error
 * Since: 1.19.35
 */
gint64
guestfs_session_hivex_node_add_child (GuestfsSession *session, gint64 parent, const gchar *name, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "hivex_node_add_child");
    return -1;
  }

  int64_t ret = guestfs_hivex_node_add_child (g, parent, name);
  if (ret == -1) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return -1;
  }

  return ret;
}

/**
 * guestfs_session_hivex_node_children:
 * @session: (transfer none): A GuestfsSession object
 * @nodeh: (type gint64):
 * @err: A GError object to receive any generated errors
 *
 * return list of nodes which are subkeys of node
 *
 * Return the list of nodes which are subkeys of @nodeh.
 * 
 * This is a wrapper around the hivex(3) call of the same name.
 * 
 * Returns: (transfer full) (array zero-terminated=1) (element-type GuestfsHivexNode): an array of HivexNode objects, or NULL on error
 * Since: 1.19.35
 */
GuestfsHivexNode **
guestfs_session_hivex_node_children (GuestfsSession *session, gint64 nodeh, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "hivex_node_children");
    return NULL;
  }

  struct guestfs_hivex_node_list *ret = guestfs_hivex_node_children (g, nodeh);
  if (ret == NULL) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return NULL;
  }

  GuestfsHivexNode **l = g_malloc (sizeof (GuestfsHivexNode*) * (ret->len + 1));
  gsize i;
  for (i = 0; i < ret->len; i++) {
    l[i] = g_slice_new0 (GuestfsHivexNode);
    l[i]->hivex_node_h = ret->val[i].hivex_node_h;
  }
  guestfs_free_hivex_node_list (ret);
  l[i] = NULL;
  return l;
}

/**
 * guestfs_session_hivex_node_delete_child:
 * @session: (transfer none): A GuestfsSession object
 * @nodeh: (type gint64):
 * @err: A GError object to receive any generated errors
 *
 * delete a node (recursively)
 *
 * Delete @nodeh, recursively if necessary.
 * 
 * This is a wrapper around the hivex(3) call of the same name.
 * 
 * Returns: true on success, false on error
 * Since: 1.19.35
 */
gboolean
guestfs_session_hivex_node_delete_child (GuestfsSession *session, gint64 nodeh, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "hivex_node_delete_child");
    return FALSE;
  }

  int ret = guestfs_hivex_node_delete_child (g, nodeh);
  if (ret == -1) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return FALSE;
  }

  return TRUE;
}

/**
 * guestfs_session_hivex_node_get_child:
 * @session: (transfer none): A GuestfsSession object
 * @nodeh: (type gint64):
 * @name: (transfer none) (type utf8):
 * @err: A GError object to receive any generated errors
 *
 * return the named child of node
 *
 * Return the child of @nodeh with the name @name, if it exists. This can
 * return @0 meaning the name was not found.
 * 
 * This is a wrapper around the hivex(3) call of the same name.
 * 
 * Returns: the returned value, or -1 on error
 * Since: 1.19.35
 */
gint64
guestfs_session_hivex_node_get_child (GuestfsSession *session, gint64 nodeh, const gchar *name, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "hivex_node_get_child");
    return -1;
  }

  int64_t ret = guestfs_hivex_node_get_child (g, nodeh, name);
  if (ret == -1) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return -1;
  }

  return ret;
}

/**
 * guestfs_session_hivex_node_get_value:
 * @session: (transfer none): A GuestfsSession object
 * @nodeh: (type gint64):
 * @key: (transfer none) (type utf8):
 * @err: A GError object to receive any generated errors
 *
 * return the named value
 *
 * Return the value attached to @nodeh which has the name @key, if it
 * exists. This can return @0 meaning the key was not found.
 * 
 * This is a wrapper around the hivex(3) call of the same name.
 * 
 * Returns: the returned value, or -1 on error
 * Since: 1.19.35
 */
gint64
guestfs_session_hivex_node_get_value (GuestfsSession *session, gint64 nodeh, const gchar *key, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "hivex_node_get_value");
    return -1;
  }

  int64_t ret = guestfs_hivex_node_get_value (g, nodeh, key);
  if (ret == -1) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return -1;
  }

  return ret;
}

/**
 * guestfs_session_hivex_node_name:
 * @session: (transfer none): A GuestfsSession object
 * @nodeh: (type gint64):
 * @err: A GError object to receive any generated errors
 *
 * return the name of the node
 *
 * Return the name of @nodeh.
 * 
 * This is a wrapper around the hivex(3) call of the same name.
 * 
 * Returns: (transfer full): the returned string, or NULL on error
 * Since: 1.19.35
 */
gchar *
guestfs_session_hivex_node_name (GuestfsSession *session, gint64 nodeh, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "hivex_node_name");
    return NULL;
  }

  char *ret = guestfs_hivex_node_name (g, nodeh);
  if (ret == NULL) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return NULL;
  }

  return ret;
}

/**
 * guestfs_session_hivex_node_parent:
 * @session: (transfer none): A GuestfsSession object
 * @nodeh: (type gint64):
 * @err: A GError object to receive any generated errors
 *
 * return the parent of node
 *
 * Return the parent node of @nodeh.
 * 
 * This is a wrapper around the hivex(3) call of the same name.
 * 
 * Returns: the returned value, or -1 on error
 * Since: 1.19.35
 */
gint64
guestfs_session_hivex_node_parent (GuestfsSession *session, gint64 nodeh, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "hivex_node_parent");
    return -1;
  }

  int64_t ret = guestfs_hivex_node_parent (g, nodeh);
  if (ret == -1) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return -1;
  }

  return ret;
}

/**
 * guestfs_session_hivex_node_set_value:
 * @session: (transfer none): A GuestfsSession object
 * @nodeh: (type gint64):
 * @key: (transfer none) (type utf8):
 * @t: (type gint64):
 * @val: (transfer none) (array length=val_size) (element-type guint8): an array of binary data
 * @val_size: The size of val, in bytes
 * @err: A GError object to receive any generated errors
 *
 * set or replace a single value in a node
 *
 * Set or replace a single value under the node @nodeh. The @key is the
 * name, @t is the type, and @val is the data.
 * 
 * This is a wrapper around the hivex(3) call of the same name.
 * 
 * Returns: true on success, false on error
 * Since: 1.19.35
 */
gboolean
guestfs_session_hivex_node_set_value (GuestfsSession *session, gint64 nodeh, const gchar *key, gint64 t, const guint8 *val, gsize val_size, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "hivex_node_set_value");
    return FALSE;
  }

  int ret = guestfs_hivex_node_set_value (g, nodeh, key, t, (const char *) val, val_size);
  if (ret == -1) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return FALSE;
  }

  return TRUE;
}

/**
 * guestfs_session_hivex_node_values:
 * @session: (transfer none): A GuestfsSession object
 * @nodeh: (type gint64):
 * @err: A GError object to receive any generated errors
 *
 * return list of values attached to node
 *
 * Return the array of (key, datatype, data) tuples attached to @nodeh.
 * 
 * This is a wrapper around the hivex(3) call of the same name.
 * 
 * Returns: (transfer full) (array zero-terminated=1) (element-type GuestfsHivexValue): an array of HivexValue objects, or NULL on error
 * Since: 1.19.35
 */
GuestfsHivexValue **
guestfs_session_hivex_node_values (GuestfsSession *session, gint64 nodeh, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "hivex_node_values");
    return NULL;
  }

  struct guestfs_hivex_value_list *ret = guestfs_hivex_node_values (g, nodeh);
  if (ret == NULL) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return NULL;
  }

  GuestfsHivexValue **l = g_malloc (sizeof (GuestfsHivexValue*) * (ret->len + 1));
  gsize i;
  for (i = 0; i < ret->len; i++) {
    l[i] = g_slice_new0 (GuestfsHivexValue);
    l[i]->hivex_value_h = ret->val[i].hivex_value_h;
  }
  guestfs_free_hivex_value_list (ret);
  l[i] = NULL;
  return l;
}

/**
 * guestfs_session_hivex_open:
 * @session: (transfer none): A GuestfsSession object
 * @filename: (transfer none) (type filename):
 * @optargs: (transfer none) (allow-none): a GuestfsHivexOpen containing optional arguments
 * @err: A GError object to receive any generated errors
 *
 * open a Windows Registry hive file
 *
 * Open the Windows Registry hive file named filename. If there was any
 * previous hivex handle associated with this guestfs session, then it is
 * closed.
 * 
 * This is a wrapper around the hivex(3) call of the same name.
 * 
 * Returns: true on success, false on error
 * Since: 1.19.35
 */
gboolean
guestfs_session_hivex_open (GuestfsSession *session, const gchar *filename, GuestfsHivexOpen *optargs, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "hivex_open");
    return FALSE;
  }

  struct guestfs_hivex_open_argv argv;
  struct guestfs_hivex_open_argv *argvp = NULL;

  if (optargs) {
    argv.bitmask = 0;

    GValue verbose_v = {0, };
    g_value_init (&verbose_v, GUESTFS_TYPE_TRISTATE);
    g_object_get_property (G_OBJECT (optargs), "verbose", &verbose_v);
    GuestfsTristate verbose = g_value_get_enum (&verbose_v);
    if (verbose != GUESTFS_TRISTATE_NONE) {
      argv.bitmask |= GUESTFS_HIVEX_OPEN_VERBOSE_BITMASK;
      argv.verbose = verbose;
    }
    GValue debug_v = {0, };
    g_value_init (&debug_v, GUESTFS_TYPE_TRISTATE);
    g_object_get_property (G_OBJECT (optargs), "debug", &debug_v);
    GuestfsTristate debug = g_value_get_enum (&debug_v);
    if (debug != GUESTFS_TRISTATE_NONE) {
      argv.bitmask |= GUESTFS_HIVEX_OPEN_DEBUG_BITMASK;
      argv.debug = debug;
    }
    GValue write_v = {0, };
    g_value_init (&write_v, GUESTFS_TYPE_TRISTATE);
    g_object_get_property (G_OBJECT (optargs), "write", &write_v);
    GuestfsTristate write = g_value_get_enum (&write_v);
    if (write != GUESTFS_TRISTATE_NONE) {
      argv.bitmask |= GUESTFS_HIVEX_OPEN_WRITE_BITMASK;
      argv.write = write;
    }
    argvp = &argv;
  }
  int ret = guestfs_hivex_open_argv (g, filename, argvp);
  if (ret == -1) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return FALSE;
  }

  return TRUE;
}

/**
 * guestfs_session_hivex_root:
 * @session: (transfer none): A GuestfsSession object
 * @err: A GError object to receive any generated errors
 *
 * return the root node of the hive
 *
 * Return the root node of the hive.
 * 
 * This is a wrapper around the hivex(3) call of the same name.
 * 
 * Returns: the returned value, or -1 on error
 * Since: 1.19.35
 */
gint64
guestfs_session_hivex_root (GuestfsSession *session, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "hivex_root");
    return -1;
  }

  int64_t ret = guestfs_hivex_root (g);
  if (ret == -1) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return -1;
  }

  return ret;
}

/**
 * guestfs_session_hivex_value_key:
 * @session: (transfer none): A GuestfsSession object
 * @valueh: (type gint64):
 * @err: A GError object to receive any generated errors
 *
 * return the key field from the (key, datatype, data) tuple
 *
 * Return the key (name) field of a (key, datatype, data) tuple.
 * 
 * This is a wrapper around the hivex(3) call of the same name.
 * 
 * Returns: (transfer full): the returned string, or NULL on error
 * Since: 1.19.35
 */
gchar *
guestfs_session_hivex_value_key (GuestfsSession *session, gint64 valueh, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "hivex_value_key");
    return NULL;
  }

  char *ret = guestfs_hivex_value_key (g, valueh);
  if (ret == NULL) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return NULL;
  }

  return ret;
}

/**
 * guestfs_session_hivex_value_type:
 * @session: (transfer none): A GuestfsSession object
 * @valueh: (type gint64):
 * @err: A GError object to receive any generated errors
 *
 * return the data type from the (key, datatype, data) tuple
 *
 * Return the data type field from a (key, datatype, data) tuple.
 * 
 * This is a wrapper around the hivex(3) call of the same name.
 * 
 * Returns: the returned value, or -1 on error
 * Since: 1.19.35
 */
gint64
guestfs_session_hivex_value_type (GuestfsSession *session, gint64 valueh, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "hivex_value_type");
    return -1;
  }

  int64_t ret = guestfs_hivex_value_type (g, valueh);
  if (ret == -1) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return -1;
  }

  return ret;
}

/**
 * guestfs_session_hivex_value_utf8:
 * @session: (transfer none): A GuestfsSession object
 * @valueh: (type gint64):
 * @err: A GError object to receive any generated errors
 *
 * return the data field from the (key, datatype, data) tuple
 *
 * This calls guestfs_session_hivex_value_value() (which returns the data
 * field from a hivex value tuple). It then assumes that the field is a
 * UTF-16LE string and converts the result to UTF-8 (or if this is not
 * possible, it returns an error).
 * 
 * This is useful for reading strings out of the Windows registry. However
 * it is not foolproof because the registry is not strongly-typed and
 * fields can contain arbitrary or unexpected data.
 * 
 * Returns: (transfer full): the returned string, or NULL on error
 * Since: 1.19.35
 */
gchar *
guestfs_session_hivex_value_utf8 (GuestfsSession *session, gint64 valueh, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "hivex_value_utf8");
    return NULL;
  }

  char *ret = guestfs_hivex_value_utf8 (g, valueh);
  if (ret == NULL) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return NULL;
  }

  return ret;
}

/**
 * guestfs_session_hivex_value_value:
 * @session: (transfer none): A GuestfsSession object
 * @valueh: (type gint64):
 * @size_r: The size of the returned buffer, in bytes
 * @err: A GError object to receive any generated errors
 *
 * return the data field from the (key, datatype, data) tuple
 *
 * Return the data field of a (key, datatype, data) tuple.
 * 
 * This is a wrapper around the hivex(3) call of the same name.
 * 
 * See also: guestfs_session_hivex_value_utf8().
 * 
 * Returns: (transfer full) (array length=size_r) (element-type guint8): an array of binary data, or NULL on error
 * Since: 1.19.35
 */
guint8 *
guestfs_session_hivex_value_value (GuestfsSession *session, gint64 valueh, gsize *size_r, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "hivex_value_value");
    return NULL;
  }

  char *ret = guestfs_hivex_value_value (g, valueh, size_r);
  if (ret == NULL) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return NULL;
  }

  return (guint8 *) ret;
}

/**
 * guestfs_session_initrd_cat:
 * @session: (transfer none): A GuestfsSession object
 * @initrdpath: (transfer none) (type filename):
 * @filename: (transfer none) (type utf8):
 * @size_r: The size of the returned buffer, in bytes
 * @err: A GError object to receive any generated errors
 *
 * list the contents of a single file in an initrd
 *
 * This command unpacks the file filename from the initrd file called
 * initrdpath. The filename must be given *without* the initial /
 * character.
 * 
 * For example, in guestfish you could use the following command to examine
 * the boot script (usually called /init) contained in a Linux initrd or
 * initramfs image:
 * 
 * <![CDATA[initrd-cat /boot/initrd-<version>.img init]]>
 * 
 * See also guestfs_session_initrd_list().
 * 
 * Returns: (transfer full) (array length=size_r) (element-type guint8): an array of binary data, or NULL on error
 * Since: 1.0.84
 */
guint8 *
guestfs_session_initrd_cat (GuestfsSession *session, const gchar *initrdpath, const gchar *filename, gsize *size_r, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "initrd_cat");
    return NULL;
  }

  char *ret = guestfs_initrd_cat (g, initrdpath, filename, size_r);
  if (ret == NULL) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return NULL;
  }

  return (guint8 *) ret;
}

/**
 * guestfs_session_initrd_list:
 * @session: (transfer none): A GuestfsSession object
 * @path: (transfer none) (type filename):
 * @err: A GError object to receive any generated errors
 *
 * list files in an initrd
 *
 * This command lists out files contained in an initrd.
 * 
 * The files are listed without any initial / character. The files are
 * listed in the order they appear (not necessarily alphabetical).
 * Directory names are listed as separate items.
 * 
 * Old Linux kernels (2.4 and earlier) used a compressed ext2 filesystem as
 * initrd. We *only* support the newer initramfs format (compressed cpio
 * files).
 * 
 * Returns: (transfer full) (array zero-terminated=1) (element-type utf8): an array of returned strings, or NULL on error
 * Since: 1.0.54
 */
gchar **
guestfs_session_initrd_list (GuestfsSession *session, const gchar *path, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "initrd_list");
    return NULL;
  }

  char **ret = guestfs_initrd_list (g, path);
  if (ret == NULL) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return NULL;
  }

  return ret;
}

/**
 * guestfs_session_inotify_add_watch:
 * @session: (transfer none): A GuestfsSession object
 * @path: (transfer none) (type filename):
 * @mask: (type gint32):
 * @err: A GError object to receive any generated errors
 *
 * add an inotify watch
 *
 * Watch @path for the events listed in @mask.
 * 
 * Note that if @path is a directory then events within that directory are
 * watched, but this does *not* happen recursively (in subdirectories).
 * 
 * Note for non-C or non-Linux callers: the inotify events are defined by
 * the Linux kernel ABI and are listed in /usr/include/sys/inotify.h.
 * 
 * Returns: the returned value, or -1 on error
 * Since: 1.0.66
 */
gint64
guestfs_session_inotify_add_watch (GuestfsSession *session, const gchar *path, gint32 mask, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "inotify_add_watch");
    return -1;
  }

  int64_t ret = guestfs_inotify_add_watch (g, path, mask);
  if (ret == -1) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return -1;
  }

  return ret;
}

/**
 * guestfs_session_inotify_close:
 * @session: (transfer none): A GuestfsSession object
 * @err: A GError object to receive any generated errors
 *
 * close the inotify handle
 *
 * This closes the inotify handle which was previously opened by
 * inotify_init. It removes all watches, throws away any pending events,
 * and deallocates all resources.
 * 
 * Returns: true on success, false on error
 * Since: 1.0.66
 */
gboolean
guestfs_session_inotify_close (GuestfsSession *session, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "inotify_close");
    return FALSE;
  }

  int ret = guestfs_inotify_close (g);
  if (ret == -1) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return FALSE;
  }

  return TRUE;
}

/**
 * guestfs_session_inotify_files:
 * @session: (transfer none): A GuestfsSession object
 * @err: A GError object to receive any generated errors
 *
 * return list of watched files that had events
 *
 * This function is a helpful wrapper around guestfs_session_inotify_read()
 * which just returns a list of pathnames of objects that were touched. The
 * returned pathnames are sorted and deduplicated.
 * 
 * Returns: (transfer full) (array zero-terminated=1) (element-type utf8): an array of returned strings, or NULL on error
 * Since: 1.0.66
 */
gchar **
guestfs_session_inotify_files (GuestfsSession *session, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "inotify_files");
    return NULL;
  }

  char **ret = guestfs_inotify_files (g);
  if (ret == NULL) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return NULL;
  }

  return ret;
}

/**
 * guestfs_session_inotify_init:
 * @session: (transfer none): A GuestfsSession object
 * @maxevents: (type gint32):
 * @err: A GError object to receive any generated errors
 *
 * create an inotify handle
 *
 * This command creates a new inotify handle. The inotify subsystem can be
 * used to notify events which happen to objects in the guest filesystem.
 * 
 * @maxevents is the maximum number of events which will be queued up
 * between calls to guestfs_session_inotify_read() or
 * guestfs_session_inotify_files(). If this is passed as @0, then the
 * kernel (or previously set) default is used. For Linux 2.6.29 the default
 * was 16384 events. Beyond this limit, the kernel throws away events, but
 * records the fact that it threw them away by setting a flag
 * @IN_Q_OVERFLOW in the returned structure list (see
 * guestfs_session_inotify_read()).
 * 
 * Before any events are generated, you have to add some watches to the
 * internal watch list. See: guestfs_session_inotify_add_watch() and
 * guestfs_session_inotify_rm_watch().
 * 
 * Queued up events should be read periodically by calling
 * guestfs_session_inotify_read() (or guestfs_session_inotify_files() which
 * is just a helpful wrapper around guestfs_session_inotify_read()). If you
 * don't read the events out often enough then you risk the internal queue
 * overflowing.
 * 
 * The handle should be closed after use by calling
 * guestfs_session_inotify_close(). This also removes any watches
 * automatically.
 * 
 * See also inotify(7) for an overview of the inotify interface as exposed
 * by the Linux kernel, which is roughly what we expose via libguestfs.
 * Note that there is one global inotify handle per libguestfs instance.
 * 
 * Returns: true on success, false on error
 * Since: 1.0.66
 */
gboolean
guestfs_session_inotify_init (GuestfsSession *session, gint32 maxevents, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "inotify_init");
    return FALSE;
  }

  int ret = guestfs_inotify_init (g, maxevents);
  if (ret == -1) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return FALSE;
  }

  return TRUE;
}

/**
 * guestfs_session_inotify_read:
 * @session: (transfer none): A GuestfsSession object
 * @err: A GError object to receive any generated errors
 *
 * return list of inotify events
 *
 * Return the complete queue of events that have happened since the
 * previous read call.
 * 
 * If no events have happened, this returns an empty list.
 * 
 * *Note*: In order to make sure that all events have been read, you must
 * call this function repeatedly until it returns an empty list. The reason
 * is that the call will read events up to the maximum appliance-to-host
 * message size and leave remaining events in the queue.
 * 
 * Returns: (transfer full) (array zero-terminated=1) (element-type GuestfsINotifyEvent): an array of INotifyEvent objects, or NULL on error
 * Since: 1.0.66
 */
GuestfsINotifyEvent **
guestfs_session_inotify_read (GuestfsSession *session, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "inotify_read");
    return NULL;
  }

  struct guestfs_inotify_event_list *ret = guestfs_inotify_read (g);
  if (ret == NULL) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return NULL;
  }

  GuestfsINotifyEvent **l = g_malloc (sizeof (GuestfsINotifyEvent*) * (ret->len + 1));
  gsize i;
  for (i = 0; i < ret->len; i++) {
    l[i] = g_slice_new0 (GuestfsINotifyEvent);
    l[i]->in_wd = ret->val[i].in_wd;
    l[i]->in_mask = ret->val[i].in_mask;
    l[i]->in_cookie = ret->val[i].in_cookie;
    if (ret->val[i].in_name) l[i]->in_name = g_strdup (ret->val[i].in_name);
  }
  guestfs_free_inotify_event_list (ret);
  l[i] = NULL;
  return l;
}

/**
 * guestfs_session_inotify_rm_watch:
 * @session: (transfer none): A GuestfsSession object
 * @wd: (type gint32):
 * @err: A GError object to receive any generated errors
 *
 * remove an inotify watch
 *
 * Remove a previously defined inotify watch. See
 * guestfs_session_inotify_add_watch().
 * 
 * Returns: true on success, false on error
 * Since: 1.0.66
 */
gboolean
guestfs_session_inotify_rm_watch (GuestfsSession *session, gint32 wd, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "inotify_rm_watch");
    return FALSE;
  }

  int ret = guestfs_inotify_rm_watch (g, wd);
  if (ret == -1) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return FALSE;
  }

  return TRUE;
}

/**
 * guestfs_session_inspect_get_arch:
 * @session: (transfer none): A GuestfsSession object
 * @root: (transfer none) (type filename):
 * @err: A GError object to receive any generated errors
 *
 * get architecture of inspected operating system
 *
 * This returns the architecture of the inspected operating system. The
 * possible return values are listed under
 * guestfs_session_file_architecture().
 * 
 * If the architecture could not be determined, then the string @unknown is
 * returned.
 * 
 * Please read "INSPECTION" in guestfs(3) for more details.
 * 
 * Returns: (transfer full): the returned string, or NULL on error
 * Since: 1.5.3
 */
gchar *
guestfs_session_inspect_get_arch (GuestfsSession *session, const gchar *root, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "inspect_get_arch");
    return NULL;
  }

  char *ret = guestfs_inspect_get_arch (g, root);
  if (ret == NULL) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return NULL;
  }

  return ret;
}

/**
 * guestfs_session_inspect_get_distro:
 * @session: (transfer none): A GuestfsSession object
 * @root: (transfer none) (type filename):
 * @err: A GError object to receive any generated errors
 *
 * get distro of inspected operating system
 *
 * This returns the distro (distribution) of the inspected operating
 * system.
 * 
 * Currently defined distros are:
 * 
 * "archlinux"
 * Arch Linux.
 * 
 * "buildroot"
 * Buildroot-derived distro, but not one we specifically recognize.
 * 
 * "centos"
 * CentOS.
 * 
 * "cirros"
 * Cirros.
 * 
 * "coreos"
 * CoreOS.
 * 
 * "debian"
 * Debian.
 * 
 * "fedora"
 * Fedora.
 * 
 * "freebsd"
 * FreeBSD.
 * 
 * "freedos"
 * FreeDOS.
 * 
 * "gentoo"
 * Gentoo.
 * 
 * "linuxmint"
 * Linux Mint.
 * 
 * "mageia"
 * Mageia.
 * 
 * "mandriva"
 * Mandriva.
 * 
 * "meego"
 * MeeGo.
 * 
 * "netbsd"
 * NetBSD.
 * 
 * "openbsd"
 * OpenBSD.
 * 
 * "opensuse"
 * OpenSUSE.
 * 
 * "oraclelinux"
 * Oracle Linux.
 * 
 * "pardus"
 * Pardus.
 * 
 * "redhat-based"
 * Some Red Hat-derived distro.
 * 
 * "rhel"
 * Red Hat Enterprise Linux.
 * 
 * "scientificlinux"
 * Scientific Linux.
 * 
 * "slackware"
 * Slackware.
 * 
 * "sles"
 * SuSE Linux Enterprise Server or Desktop.
 * 
 * "suse-based"
 * Some openSuSE-derived distro.
 * 
 * "ttylinux"
 * ttylinux.
 * 
 * "ubuntu"
 * Ubuntu.
 * 
 * "unknown"
 * The distro could not be determined.
 * 
 * "windows"
 * Windows does not have distributions. This string is returned if the
 * OS type is Windows.
 * 
 * Future versions of libguestfs may return other strings here. The caller
 * should be prepared to handle any string.
 * 
 * Please read "INSPECTION" in guestfs(3) for more details.
 * 
 * Returns: (transfer full): the returned string, or NULL on error
 * Since: 1.5.3
 */
gchar *
guestfs_session_inspect_get_distro (GuestfsSession *session, const gchar *root, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "inspect_get_distro");
    return NULL;
  }

  char *ret = guestfs_inspect_get_distro (g, root);
  if (ret == NULL) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return NULL;
  }

  return ret;
}

/**
 * guestfs_session_inspect_get_drive_mappings:
 * @session: (transfer none): A GuestfsSession object
 * @root: (transfer none) (type filename):
 * @err: A GError object to receive any generated errors
 *
 * get drive letter mappings
 *
 * This call is useful for Windows which uses a primitive system of
 * assigning drive letters (like C:\) to partitions. This inspection API
 * examines the Windows Registry to find out how disks/partitions are
 * mapped to drive letters, and returns a hash table as in the example
 * below:
 * 
 * <![CDATA[C      =>     /dev/vda2]]>
 * 
 * <![CDATA[E      =>     /dev/vdb1]]>
 * 
 * <![CDATA[F      =>     /dev/vdc1]]>
 * 
 * Note that keys are drive letters. For Windows, the key is case
 * insensitive and just contains the drive letter, without the customary
 * colon separator character.
 * 
 * In future we may support other operating systems that also used drive
 * letters, but the keys for those might not be case insensitive and might
 * be longer than 1 character. For example in OS-9, hard drives were named
 * @h0, @h1 etc.
 * 
 * For Windows guests, currently only hard drive mappings are returned.
 * Removable disks (eg. DVD-ROMs) are ignored.
 * 
 * For guests that do not use drive mappings, or if the drive mappings
 * could not be determined, this returns an empty hash table.
 * 
 * Please read "INSPECTION" in guestfs(3) for more details. See also
 * guestfs_session_inspect_get_mountpoints(),
 * guestfs_session_inspect_get_filesystems().
 * 
 * Returns: (transfer full) (element-type utf8 utf8): a GHashTable of results, or NULL on error
 * Since: 1.9.17
 */
GHashTable *
guestfs_session_inspect_get_drive_mappings (GuestfsSession *session, const gchar *root, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "inspect_get_drive_mappings");
    return NULL;
  }

  char **ret = guestfs_inspect_get_drive_mappings (g, root);
  if (ret == NULL) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return NULL;
  }

  GHashTable *h = g_hash_table_new_full (g_str_hash, g_str_equal, g_free, g_free);
  char **i = ret;
  while (*i) {
    char *key = *i; i++;
    char *value = *i; i++;
    g_hash_table_insert (h, key, value);
  };
  g_free (ret);
  return h;
}

/**
 * guestfs_session_inspect_get_filesystems:
 * @session: (transfer none): A GuestfsSession object
 * @root: (transfer none) (type filename):
 * @err: A GError object to receive any generated errors
 *
 * get filesystems associated with inspected operating system
 *
 * This returns a list of all the filesystems that we think are associated
 * with this operating system. This includes the root filesystem, other
 * ordinary filesystems, and non-mounted devices like swap partitions.
 * 
 * In the case of a multi-boot virtual machine, it is possible for a
 * filesystem to be shared between operating systems.
 * 
 * Please read "INSPECTION" in guestfs(3) for more details. See also
 * guestfs_session_inspect_get_mountpoints().
 * 
 * Returns: (transfer full) (array zero-terminated=1) (element-type utf8): an array of returned strings, or NULL on error
 * Since: 1.5.3
 */
gchar **
guestfs_session_inspect_get_filesystems (GuestfsSession *session, const gchar *root, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "inspect_get_filesystems");
    return NULL;
  }

  char **ret = guestfs_inspect_get_filesystems (g, root);
  if (ret == NULL) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return NULL;
  }

  return ret;
}

/**
 * guestfs_session_inspect_get_format:
 * @session: (transfer none): A GuestfsSession object
 * @root: (transfer none) (type filename):
 * @err: A GError object to receive any generated errors
 *
 * get format of inspected operating system
 *
 * This returns the format of the inspected operating system. You can use
 * it to detect install images, live CDs and similar.
 * 
 * Currently defined formats are:
 * 
 * "installed"
 * This is an installed operating system.
 * 
 * "installer"
 * The disk image being inspected is not an installed operating system,
 * but a *bootable* install disk, live CD, or similar.
 * 
 * "unknown"
 * The format of this disk image is not known.
 * 
 * Future versions of libguestfs may return other strings here. The caller
 * should be prepared to handle any string.
 * 
 * Please read "INSPECTION" in guestfs(3) for more details.
 * 
 * Returns: (transfer full): the returned string, or NULL on error
 * Since: 1.9.4
 */
gchar *
guestfs_session_inspect_get_format (GuestfsSession *session, const gchar *root, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "inspect_get_format");
    return NULL;
  }

  char *ret = guestfs_inspect_get_format (g, root);
  if (ret == NULL) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return NULL;
  }

  return ret;
}

/**
 * guestfs_session_inspect_get_hostname:
 * @session: (transfer none): A GuestfsSession object
 * @root: (transfer none) (type filename):
 * @err: A GError object to receive any generated errors
 *
 * get hostname of the operating system
 *
 * This function returns the hostname of the operating system as found by
 * inspection of the guest's configuration files.
 * 
 * If the hostname could not be determined, then the string @unknown is
 * returned.
 * 
 * Please read "INSPECTION" in guestfs(3) for more details.
 * 
 * Returns: (transfer full): the returned string, or NULL on error
 * Since: 1.7.9
 */
gchar *
guestfs_session_inspect_get_hostname (GuestfsSession *session, const gchar *root, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "inspect_get_hostname");
    return NULL;
  }

  char *ret = guestfs_inspect_get_hostname (g, root);
  if (ret == NULL) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return NULL;
  }

  return ret;
}

/**
 * guestfs_session_inspect_get_icon:
 * @session: (transfer none): A GuestfsSession object
 * @root: (transfer none) (type filename):
 * @optargs: (transfer none) (allow-none): a GuestfsInspectGetIcon containing optional arguments
 * @size_r: The size of the returned buffer, in bytes
 * @err: A GError object to receive any generated errors
 *
 * get the icon corresponding to this operating system
 *
 * This function returns an icon corresponding to the inspected operating
 * system. The icon is returned as a buffer containing a PNG image
 * (re-encoded to PNG if necessary).
 * 
 * If it was not possible to get an icon this function returns a
 * zero-length (non-NULL) buffer. *Callers must check for this case*.
 * 
 * Libguestfs will start by looking for a file called /etc/favicon.png or
 * C:\etc\favicon.png and if it has the correct format, the contents of
 * this file will be returned. You can disable favicons by passing the
 * optional @favicon boolean as false (default is true).
 * 
 * If finding the favicon fails, then we look in other places in the guest
 * for a suitable icon.
 * 
 * If the optional @highquality boolean is true then only high quality
 * icons are returned, which means only icons of high resolution with an
 * alpha channel. The default (false) is to return any icon we can, even if
 * it is of substandard quality.
 * 
 * Notes:
 * 
 * *   Unlike most other inspection API calls, the guest's disks must be
 * mounted up before you call this, since it needs to read information
 * from the guest filesystem during the call.
 * 
 * *   Security: The icon data comes from the untrusted guest, and should
 * be treated with caution. PNG files have been known to contain
 * exploits. Ensure that libpng (or other relevant libraries) are fully
 * up to date before trying to process or display the icon.
 * 
 * *   The PNG image returned can be any size. It might not be square.
 * Libguestfs tries to return the largest, highest quality icon
 * available. The application must scale the icon to the required size.
 * 
 * *   Extracting icons from Windows guests requires the external @wrestool
 * program from the @icoutils package, and several programs (@bmptopnm,
 * @pnmtopng, @pamcut) from the @netpbm package. These must be
 * installed separately.
 * 
 * *   Operating system icons are usually trademarks. Seek legal advice
 * before using trademarks in applications.
 * 
 * Returns: (transfer full) (array length=size_r) (element-type guint8): an array of binary data, or NULL on error
 * Since: 1.11.12
 */
guint8 *
guestfs_session_inspect_get_icon (GuestfsSession *session, const gchar *root, GuestfsInspectGetIcon *optargs, gsize *size_r, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "inspect_get_icon");
    return NULL;
  }

  struct guestfs_inspect_get_icon_argv argv;
  struct guestfs_inspect_get_icon_argv *argvp = NULL;

  if (optargs) {
    argv.bitmask = 0;

    GValue favicon_v = {0, };
    g_value_init (&favicon_v, GUESTFS_TYPE_TRISTATE);
    g_object_get_property (G_OBJECT (optargs), "favicon", &favicon_v);
    GuestfsTristate favicon = g_value_get_enum (&favicon_v);
    if (favicon != GUESTFS_TRISTATE_NONE) {
      argv.bitmask |= GUESTFS_INSPECT_GET_ICON_FAVICON_BITMASK;
      argv.favicon = favicon;
    }
    GValue highquality_v = {0, };
    g_value_init (&highquality_v, GUESTFS_TYPE_TRISTATE);
    g_object_get_property (G_OBJECT (optargs), "highquality", &highquality_v);
    GuestfsTristate highquality = g_value_get_enum (&highquality_v);
    if (highquality != GUESTFS_TRISTATE_NONE) {
      argv.bitmask |= GUESTFS_INSPECT_GET_ICON_HIGHQUALITY_BITMASK;
      argv.highquality = highquality;
    }
    argvp = &argv;
  }
  char *ret = guestfs_inspect_get_icon_argv (g, root, size_r, argvp);
  if (ret == NULL) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return NULL;
  }

  return (guint8 *) ret;
}

/**
 * guestfs_session_inspect_get_major_version:
 * @session: (transfer none): A GuestfsSession object
 * @root: (transfer none) (type filename):
 * @err: A GError object to receive any generated errors
 *
 * get major version of inspected operating system
 *
 * This returns the major version number of the inspected operating system.
 * 
 * Windows uses a consistent versioning scheme which is *not* reflected in
 * the popular public names used by the operating system. Notably the
 * operating system known as "Windows 7" is really version 6.1 (ie. major =
 * 6, minor = 1). You can find out the real versions corresponding to
 * releases of Windows by consulting Wikipedia or MSDN.
 * 
 * If the version could not be determined, then @0 is returned.
 * 
 * Please read "INSPECTION" in guestfs(3) for more details.
 * 
 * Returns: the returned value, or -1 on error
 * Since: 1.5.3
 */
gint32
guestfs_session_inspect_get_major_version (GuestfsSession *session, const gchar *root, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "inspect_get_major_version");
    return -1;
  }

  int ret = guestfs_inspect_get_major_version (g, root);
  if (ret == -1) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return -1;
  }

  return ret;
}

/**
 * guestfs_session_inspect_get_minor_version:
 * @session: (transfer none): A GuestfsSession object
 * @root: (transfer none) (type filename):
 * @err: A GError object to receive any generated errors
 *
 * get minor version of inspected operating system
 *
 * This returns the minor version number of the inspected operating system.
 * 
 * If the version could not be determined, then @0 is returned.
 * 
 * Please read "INSPECTION" in guestfs(3) for more details. See also
 * guestfs_session_inspect_get_major_version().
 * 
 * Returns: the returned value, or -1 on error
 * Since: 1.5.3
 */
gint32
guestfs_session_inspect_get_minor_version (GuestfsSession *session, const gchar *root, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "inspect_get_minor_version");
    return -1;
  }

  int ret = guestfs_inspect_get_minor_version (g, root);
  if (ret == -1) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return -1;
  }

  return ret;
}

/**
 * guestfs_session_inspect_get_mountpoints:
 * @session: (transfer none): A GuestfsSession object
 * @root: (transfer none) (type filename):
 * @err: A GError object to receive any generated errors
 *
 * get mountpoints of inspected operating system
 *
 * This returns a hash of where we think the filesystems associated with
 * this operating system should be mounted. Callers should note that this
 * is at best an educated guess made by reading configuration files such as
 * /etc/fstab. *In particular note* that this may return filesystems which
 * are non-existent or not mountable and callers should be prepared to
 * handle or ignore failures if they try to mount them.
 * 
 * Each element in the returned hashtable has a key which is the path of
 * the mountpoint (eg. /boot) and a value which is the filesystem that
 * would be mounted there (eg. /dev/sda1).
 * 
 * Non-mounted devices such as swap devices are *not* returned in this
 * list.
 * 
 * For operating systems like Windows which still use drive letters, this
 * call will only return an entry for the first drive "mounted on" /. For
 * information about the mapping of drive letters to partitions, see
 * guestfs_session_inspect_get_drive_mappings().
 * 
 * Please read "INSPECTION" in guestfs(3) for more details. See also
 * guestfs_session_inspect_get_filesystems().
 * 
 * Returns: (transfer full) (element-type utf8 utf8): a GHashTable of results, or NULL on error
 * Since: 1.5.3
 */
GHashTable *
guestfs_session_inspect_get_mountpoints (GuestfsSession *session, const gchar *root, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "inspect_get_mountpoints");
    return NULL;
  }

  char **ret = guestfs_inspect_get_mountpoints (g, root);
  if (ret == NULL) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return NULL;
  }

  GHashTable *h = g_hash_table_new_full (g_str_hash, g_str_equal, g_free, g_free);
  char **i = ret;
  while (*i) {
    char *key = *i; i++;
    char *value = *i; i++;
    g_hash_table_insert (h, key, value);
  };
  g_free (ret);
  return h;
}

/**
 * guestfs_session_inspect_get_package_format:
 * @session: (transfer none): A GuestfsSession object
 * @root: (transfer none) (type filename):
 * @err: A GError object to receive any generated errors
 *
 * get package format used by the operating system
 *
 * This function and guestfs_session_inspect_get_package_management()
 * return the package format and package management tool used by the
 * inspected operating system. For example for Fedora these functions would
 * return @rpm (package format), and @yum or @dnf (package management).
 * 
 * This returns the string @unknown if we could not determine the package
 * format *or* if the operating system does not have a real packaging
 * system (eg. Windows).
 * 
 * Possible strings include: @rpm, @deb, @ebuild, @pisi, @pacman, @pkgsrc.
 * Future versions of libguestfs may return other strings.
 * 
 * Please read "INSPECTION" in guestfs(3) for more details.
 * 
 * Returns: (transfer full): the returned string, or NULL on error
 * Since: 1.7.5
 */
gchar *
guestfs_session_inspect_get_package_format (GuestfsSession *session, const gchar *root, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "inspect_get_package_format");
    return NULL;
  }

  char *ret = guestfs_inspect_get_package_format (g, root);
  if (ret == NULL) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return NULL;
  }

  return ret;
}

/**
 * guestfs_session_inspect_get_package_management:
 * @session: (transfer none): A GuestfsSession object
 * @root: (transfer none) (type filename):
 * @err: A GError object to receive any generated errors
 *
 * get package management tool used by the operating system
 *
 * guestfs_session_inspect_get_package_format() and this function return
 * the package format and package management tool used by the inspected
 * operating system. For example for Fedora these functions would return
 * @rpm (package format), and @yum or @dnf (package management).
 * 
 * This returns the string @unknown if we could not determine the package
 * management tool *or* if the operating system does not have a real
 * packaging system (eg. Windows).
 * 
 * Possible strings include: @yum, @dnf, @up2date, @apt (for all Debian
 * derivatives), @portage, @pisi, @pacman, @urpmi, @zypper. Future versions
 * of libguestfs may return other strings.
 * 
 * Please read "INSPECTION" in guestfs(3) for more details.
 * 
 * Returns: (transfer full): the returned string, or NULL on error
 * Since: 1.7.5
 */
gchar *
guestfs_session_inspect_get_package_management (GuestfsSession *session, const gchar *root, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "inspect_get_package_management");
    return NULL;
  }

  char *ret = guestfs_inspect_get_package_management (g, root);
  if (ret == NULL) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return NULL;
  }

  return ret;
}

/**
 * guestfs_session_inspect_get_product_name:
 * @session: (transfer none): A GuestfsSession object
 * @root: (transfer none) (type filename):
 * @err: A GError object to receive any generated errors
 *
 * get product name of inspected operating system
 *
 * This returns the product name of the inspected operating system. The
 * product name is generally some freeform string which can be displayed to
 * the user, but should not be parsed by programs.
 * 
 * If the product name could not be determined, then the string @unknown is
 * returned.
 * 
 * Please read "INSPECTION" in guestfs(3) for more details.
 * 
 * Returns: (transfer full): the returned string, or NULL on error
 * Since: 1.5.3
 */
gchar *
guestfs_session_inspect_get_product_name (GuestfsSession *session, const gchar *root, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "inspect_get_product_name");
    return NULL;
  }

  char *ret = guestfs_inspect_get_product_name (g, root);
  if (ret == NULL) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return NULL;
  }

  return ret;
}

/**
 * guestfs_session_inspect_get_product_variant:
 * @session: (transfer none): A GuestfsSession object
 * @root: (transfer none) (type filename):
 * @err: A GError object to receive any generated errors
 *
 * get product variant of inspected operating system
 *
 * This returns the product variant of the inspected operating system.
 * 
 * For Windows guests, this returns the contents of the Registry key
 * "HKLM\Software\Microsoft\Windows NT\CurrentVersion" @InstallationType
 * which is usually a string such as @Client or @Server (other values are
 * possible). This can be used to distinguish consumer and enterprise
 * versions of Windows that have the same version number (for example,
 * Windows 7 and Windows 2008 Server are both version 6.1, but the former
 * is @Client and the latter is @Server).
 * 
 * For enterprise Linux guests, in future we intend this to return the
 * product variant such as @Desktop, @Server and so on. But this is not
 * implemented at present.
 * 
 * If the product variant could not be determined, then the string @unknown
 * is returned.
 * 
 * Please read "INSPECTION" in guestfs(3) for more details. See also
 * guestfs_session_inspect_get_product_name(),
 * guestfs_session_inspect_get_major_version().
 * 
 * Returns: (transfer full): the returned string, or NULL on error
 * Since: 1.9.13
 */
gchar *
guestfs_session_inspect_get_product_variant (GuestfsSession *session, const gchar *root, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "inspect_get_product_variant");
    return NULL;
  }

  char *ret = guestfs_inspect_get_product_variant (g, root);
  if (ret == NULL) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return NULL;
  }

  return ret;
}

/**
 * guestfs_session_inspect_get_roots:
 * @session: (transfer none): A GuestfsSession object
 * @err: A GError object to receive any generated errors
 *
 * return list of operating systems found by last inspection
 *
 * This function is a convenient way to get the list of root devices, as
 * returned from a previous call to guestfs_session_inspect_os(), but
 * without redoing the whole inspection process.
 * 
 * This returns an empty list if either no root devices were found or the
 * caller has not called guestfs_session_inspect_os().
 * 
 * Please read "INSPECTION" in guestfs(3) for more details.
 * 
 * Returns: (transfer full) (array zero-terminated=1) (element-type utf8): an array of returned strings, or NULL on error
 * Since: 1.7.3
 */
gchar **
guestfs_session_inspect_get_roots (GuestfsSession *session, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "inspect_get_roots");
    return NULL;
  }

  char **ret = guestfs_inspect_get_roots (g);
  if (ret == NULL) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return NULL;
  }

  return ret;
}

/**
 * guestfs_session_inspect_get_type:
 * @session: (transfer none): A GuestfsSession object
 * @root: (transfer none) (type filename):
 * @err: A GError object to receive any generated errors
 *
 * get type of inspected operating system
 *
 * This returns the type of the inspected operating system. Currently
 * defined types are:
 * 
 * "linux"
 * Any Linux-based operating system.
 * 
 * "windows"
 * Any Microsoft Windows operating system.
 * 
 * "freebsd"
 * FreeBSD.
 * 
 * "netbsd"
 * NetBSD.
 * 
 * "openbsd"
 * OpenBSD.
 * 
 * "hurd"
 * GNU/Hurd.
 * 
 * "dos"
 * MS-DOS, FreeDOS and others.
 * 
 * "minix"
 * MINIX.
 * 
 * "unknown"
 * The operating system type could not be determined.
 * 
 * Future versions of libguestfs may return other strings here. The caller
 * should be prepared to handle any string.
 * 
 * Please read "INSPECTION" in guestfs(3) for more details.
 * 
 * Returns: (transfer full): the returned string, or NULL on error
 * Since: 1.5.3
 */
gchar *
guestfs_session_inspect_get_type (GuestfsSession *session, const gchar *root, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "inspect_get_type");
    return NULL;
  }

  char *ret = guestfs_inspect_get_type (g, root);
  if (ret == NULL) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return NULL;
  }

  return ret;
}

/**
 * guestfs_session_inspect_get_windows_current_control_set:
 * @session: (transfer none): A GuestfsSession object
 * @root: (transfer none) (type filename):
 * @err: A GError object to receive any generated errors
 *
 * get Windows CurrentControlSet of inspected operating system
 *
 * This returns the Windows CurrentControlSet of the inspected guest. The
 * CurrentControlSet is a registry key name such as @ControlSet001.
 * 
 * This call assumes that the guest is Windows and that the Registry could
 * be examined by inspection. If this is not the case then an error is
 * returned.
 * 
 * Please read "INSPECTION" in guestfs(3) for more details.
 * 
 * Returns: (transfer full): the returned string, or NULL on error
 * Since: 1.9.17
 */
gchar *
guestfs_session_inspect_get_windows_current_control_set (GuestfsSession *session, const gchar *root, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "inspect_get_windows_current_control_set");
    return NULL;
  }

  char *ret = guestfs_inspect_get_windows_current_control_set (g, root);
  if (ret == NULL) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return NULL;
  }

  return ret;
}

/**
 * guestfs_session_inspect_get_windows_systemroot:
 * @session: (transfer none): A GuestfsSession object
 * @root: (transfer none) (type filename):
 * @err: A GError object to receive any generated errors
 *
 * get Windows systemroot of inspected operating system
 *
 * This returns the Windows systemroot of the inspected guest. The
 * systemroot is a directory path such as /WINDOWS.
 * 
 * This call assumes that the guest is Windows and that the systemroot
 * could be determined by inspection. If this is not the case then an error
 * is returned.
 * 
 * Please read "INSPECTION" in guestfs(3) for more details.
 * 
 * Returns: (transfer full): the returned string, or NULL on error
 * Since: 1.5.25
 */
gchar *
guestfs_session_inspect_get_windows_systemroot (GuestfsSession *session, const gchar *root, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "inspect_get_windows_systemroot");
    return NULL;
  }

  char *ret = guestfs_inspect_get_windows_systemroot (g, root);
  if (ret == NULL) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return NULL;
  }

  return ret;
}

/**
 * guestfs_session_inspect_is_live:
 * @session: (transfer none): A GuestfsSession object
 * @root: (transfer none) (type filename):
 * @err: A GError object to receive any generated errors
 *
 * get live flag for install disk
 *
 * If guestfs_session_inspect_get_format() returns @installer (this is an
 * install disk), then this returns true if a live image was detected on
 * the disk.
 * 
 * Please read "INSPECTION" in guestfs(3) for more details.
 * 
 * Returns: the returned value, or -1 on error
 * Since: 1.9.4
 */
gint8
guestfs_session_inspect_is_live (GuestfsSession *session, const gchar *root, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "inspect_is_live");
    return -1;
  }

  int ret = guestfs_inspect_is_live (g, root);
  if (ret == -1) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return -1;
  }

  return ret;
}

/**
 * guestfs_session_inspect_is_multipart:
 * @session: (transfer none): A GuestfsSession object
 * @root: (transfer none) (type filename):
 * @err: A GError object to receive any generated errors
 *
 * get multipart flag for install disk
 *
 * If guestfs_session_inspect_get_format() returns @installer (this is an
 * install disk), then this returns true if the disk is part of a set.
 * 
 * Please read "INSPECTION" in guestfs(3) for more details.
 * 
 * Returns: the returned value, or -1 on error
 * Since: 1.9.4
 */
gint8
guestfs_session_inspect_is_multipart (GuestfsSession *session, const gchar *root, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "inspect_is_multipart");
    return -1;
  }

  int ret = guestfs_inspect_is_multipart (g, root);
  if (ret == -1) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return -1;
  }

  return ret;
}

/**
 * guestfs_session_inspect_is_netinst:
 * @session: (transfer none): A GuestfsSession object
 * @root: (transfer none) (type filename):
 * @err: A GError object to receive any generated errors
 *
 * get netinst (network installer) flag for install disk
 *
 * If guestfs_session_inspect_get_format() returns @installer (this is an
 * install disk), then this returns true if the disk is a network
 * installer, ie. not a self-contained install CD but one which is likely
 * to require network access to complete the install.
 * 
 * Please read "INSPECTION" in guestfs(3) for more details.
 * 
 * Returns: the returned value, or -1 on error
 * Since: 1.9.4
 */
gint8
guestfs_session_inspect_is_netinst (GuestfsSession *session, const gchar *root, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "inspect_is_netinst");
    return -1;
  }

  int ret = guestfs_inspect_is_netinst (g, root);
  if (ret == -1) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return -1;
  }

  return ret;
}

/**
 * guestfs_session_inspect_list_applications:
 * @session: (transfer none): A GuestfsSession object
 * @root: (transfer none) (type filename):
 * @err: A GError object to receive any generated errors
 *
 * get list of applications installed in the operating system
 *
 * Return the list of applications installed in the operating system.
 * 
 * *Note:* This call works differently from other parts of the inspection
 * API. You have to call guestfs_session_inspect_os(), then
 * guestfs_session_inspect_get_mountpoints(), then mount up the disks,
 * before calling this. Listing applications is a significantly more
 * difficult operation which requires access to the full filesystem. Also
 * note that unlike the other "guestfs_inspect_get_*" calls which are just
 * returning data cached in the libguestfs handle, this call actually reads
 * parts of the mounted filesystems during the call.
 * 
 * This returns an empty list if the inspection code was not able to
 * determine the list of applications.
 * 
 * The application structure contains the following fields:
 * 
 * @app_name
 * The name of the application. For Red Hat-derived and Debian-derived
 * Linux guests, this is the package name.
 * 
 * @app_display_name
 * The display name of the application, sometimes localized to the
 * install language of the guest operating system.
 * 
 * If unavailable this is returned as an empty string "". Callers
 * needing to display something can use @app_name instead.
 * 
 * @app_epoch
 * For package managers which use epochs, this contains the epoch of
 * the package (an integer). If unavailable, this is returned as @0.
 * 
 * @app_version
 * The version string of the application or package. If unavailable
 * this is returned as an empty string "".
 * 
 * @app_release
 * The release string of the application or package, for package
 * managers that use this. If unavailable this is returned as an empty
 * string "".
 * 
 * @app_install_path
 * The installation path of the application (on operating systems such
 * as Windows which use installation paths). This path is in the format
 * used by the guest operating system, it is not a libguestfs path.
 * 
 * If unavailable this is returned as an empty string "".
 * 
 * @app_trans_path
 * The install path translated into a libguestfs path. If unavailable
 * this is returned as an empty string "".
 * 
 * @app_publisher
 * The name of the publisher of the application, for package managers
 * that use this. If unavailable this is returned as an empty string
 * "".
 * 
 * @app_url
 * The URL (eg. upstream URL) of the application. If unavailable this
 * is returned as an empty string "".
 * 
 * @app_source_package
 * For packaging systems which support this, the name of the source
 * package. If unavailable this is returned as an empty string "".
 * 
 * @app_summary
 * A short (usually one line) description of the application or
 * package. If unavailable this is returned as an empty string "".
 * 
 * @app_description
 * A longer description of the application or package. If unavailable
 * this is returned as an empty string "".
 * 
 * Please read "INSPECTION" in guestfs(3) for more details.
 * 
 * Returns: (transfer full) (array zero-terminated=1) (element-type GuestfsApplication): an array of Application objects, or NULL on error
 * Deprecated: In new code, use guestfs_session_inspect_list_applications2() instead
 * Since: 1.7.8
 */
GuestfsApplication **
guestfs_session_inspect_list_applications (GuestfsSession *session, const gchar *root, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "inspect_list_applications");
    return NULL;
  }

  struct guestfs_application_list *ret = guestfs_inspect_list_applications (g, root);
  if (ret == NULL) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return NULL;
  }

  GuestfsApplication **l = g_malloc (sizeof (GuestfsApplication*) * (ret->len + 1));
  gsize i;
  for (i = 0; i < ret->len; i++) {
    l[i] = g_slice_new0 (GuestfsApplication);
    if (ret->val[i].app_name) l[i]->app_name = g_strdup (ret->val[i].app_name);
    if (ret->val[i].app_display_name) l[i]->app_display_name = g_strdup (ret->val[i].app_display_name);
    l[i]->app_epoch = ret->val[i].app_epoch;
    if (ret->val[i].app_version) l[i]->app_version = g_strdup (ret->val[i].app_version);
    if (ret->val[i].app_release) l[i]->app_release = g_strdup (ret->val[i].app_release);
    if (ret->val[i].app_install_path) l[i]->app_install_path = g_strdup (ret->val[i].app_install_path);
    if (ret->val[i].app_trans_path) l[i]->app_trans_path = g_strdup (ret->val[i].app_trans_path);
    if (ret->val[i].app_publisher) l[i]->app_publisher = g_strdup (ret->val[i].app_publisher);
    if (ret->val[i].app_url) l[i]->app_url = g_strdup (ret->val[i].app_url);
    if (ret->val[i].app_source_package) l[i]->app_source_package = g_strdup (ret->val[i].app_source_package);
    if (ret->val[i].app_summary) l[i]->app_summary = g_strdup (ret->val[i].app_summary);
    if (ret->val[i].app_description) l[i]->app_description = g_strdup (ret->val[i].app_description);
  }
  guestfs_free_application_list (ret);
  l[i] = NULL;
  return l;
}

/**
 * guestfs_session_inspect_list_applications2:
 * @session: (transfer none): A GuestfsSession object
 * @root: (transfer none) (type filename):
 * @err: A GError object to receive any generated errors
 *
 * get list of applications installed in the operating system
 *
 * Return the list of applications installed in the operating system.
 * 
 * *Note:* This call works differently from other parts of the inspection
 * API. You have to call guestfs_session_inspect_os(), then
 * guestfs_session_inspect_get_mountpoints(), then mount up the disks,
 * before calling this. Listing applications is a significantly more
 * difficult operation which requires access to the full filesystem. Also
 * note that unlike the other "guestfs_inspect_get_*" calls which are just
 * returning data cached in the libguestfs handle, this call actually reads
 * parts of the mounted filesystems during the call.
 * 
 * This returns an empty list if the inspection code was not able to
 * determine the list of applications.
 * 
 * The application structure contains the following fields:
 * 
 * @app2_name
 * The name of the application. For Red Hat-derived and Debian-derived
 * Linux guests, this is the package name.
 * 
 * @app2_display_name
 * The display name of the application, sometimes localized to the
 * install language of the guest operating system.
 * 
 * If unavailable this is returned as an empty string "". Callers
 * needing to display something can use @app2_name instead.
 * 
 * @app2_epoch
 * For package managers which use epochs, this contains the epoch of
 * the package (an integer). If unavailable, this is returned as @0.
 * 
 * @app2_version
 * The version string of the application or package. If unavailable
 * this is returned as an empty string "".
 * 
 * @app2_release
 * The release string of the application or package, for package
 * managers that use this. If unavailable this is returned as an empty
 * string "".
 * 
 * @app2_arch
 * The architecture string of the application or package, for package
 * managers that use this. If unavailable this is returned as an empty
 * string "".
 * 
 * @app2_install_path
 * The installation path of the application (on operating systems such
 * as Windows which use installation paths). This path is in the format
 * used by the guest operating system, it is not a libguestfs path.
 * 
 * If unavailable this is returned as an empty string "".
 * 
 * @app2_trans_path
 * The install path translated into a libguestfs path. If unavailable
 * this is returned as an empty string "".
 * 
 * @app2_publisher
 * The name of the publisher of the application, for package managers
 * that use this. If unavailable this is returned as an empty string
 * "".
 * 
 * @app2_url
 * The URL (eg. upstream URL) of the application. If unavailable this
 * is returned as an empty string "".
 * 
 * @app2_source_package
 * For packaging systems which support this, the name of the source
 * package. If unavailable this is returned as an empty string "".
 * 
 * @app2_summary
 * A short (usually one line) description of the application or
 * package. If unavailable this is returned as an empty string "".
 * 
 * @app2_description
 * A longer description of the application or package. If unavailable
 * this is returned as an empty string "".
 * 
 * Please read "INSPECTION" in guestfs(3) for more details.
 * 
 * Returns: (transfer full) (array zero-terminated=1) (element-type GuestfsApplication2): an array of Application2 objects, or NULL on error
 * Since: 1.19.56
 */
GuestfsApplication2 **
guestfs_session_inspect_list_applications2 (GuestfsSession *session, const gchar *root, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "inspect_list_applications2");
    return NULL;
  }

  struct guestfs_application2_list *ret = guestfs_inspect_list_applications2 (g, root);
  if (ret == NULL) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return NULL;
  }

  GuestfsApplication2 **l = g_malloc (sizeof (GuestfsApplication2*) * (ret->len + 1));
  gsize i;
  for (i = 0; i < ret->len; i++) {
    l[i] = g_slice_new0 (GuestfsApplication2);
    if (ret->val[i].app2_name) l[i]->app2_name = g_strdup (ret->val[i].app2_name);
    if (ret->val[i].app2_display_name) l[i]->app2_display_name = g_strdup (ret->val[i].app2_display_name);
    l[i]->app2_epoch = ret->val[i].app2_epoch;
    if (ret->val[i].app2_version) l[i]->app2_version = g_strdup (ret->val[i].app2_version);
    if (ret->val[i].app2_release) l[i]->app2_release = g_strdup (ret->val[i].app2_release);
    if (ret->val[i].app2_arch) l[i]->app2_arch = g_strdup (ret->val[i].app2_arch);
    if (ret->val[i].app2_install_path) l[i]->app2_install_path = g_strdup (ret->val[i].app2_install_path);
    if (ret->val[i].app2_trans_path) l[i]->app2_trans_path = g_strdup (ret->val[i].app2_trans_path);
    if (ret->val[i].app2_publisher) l[i]->app2_publisher = g_strdup (ret->val[i].app2_publisher);
    if (ret->val[i].app2_url) l[i]->app2_url = g_strdup (ret->val[i].app2_url);
    if (ret->val[i].app2_source_package) l[i]->app2_source_package = g_strdup (ret->val[i].app2_source_package);
    if (ret->val[i].app2_summary) l[i]->app2_summary = g_strdup (ret->val[i].app2_summary);
    if (ret->val[i].app2_description) l[i]->app2_description = g_strdup (ret->val[i].app2_description);
    if (ret->val[i].app2_spare1) l[i]->app2_spare1 = g_strdup (ret->val[i].app2_spare1);
    if (ret->val[i].app2_spare2) l[i]->app2_spare2 = g_strdup (ret->val[i].app2_spare2);
    if (ret->val[i].app2_spare3) l[i]->app2_spare3 = g_strdup (ret->val[i].app2_spare3);
    if (ret->val[i].app2_spare4) l[i]->app2_spare4 = g_strdup (ret->val[i].app2_spare4);
  }
  guestfs_free_application2_list (ret);
  l[i] = NULL;
  return l;
}

/**
 * guestfs_session_inspect_os:
 * @session: (transfer none): A GuestfsSession object
 * @err: A GError object to receive any generated errors
 *
 * inspect disk and return list of operating systems found
 *
 * This function uses other libguestfs functions and certain heuristics to
 * inspect the disk(s) (usually disks belonging to a virtual machine),
 * looking for operating systems.
 * 
 * The list returned is empty if no operating systems were found.
 * 
 * If one operating system was found, then this returns a list with a
 * single element, which is the name of the root filesystem of this
 * operating system. It is also possible for this function to return a list
 * containing more than one element, indicating a dual-boot or multi-boot
 * virtual machine, with each element being the root filesystem of one of
 * the operating systems.
 * 
 * You can pass the root string(s) returned to other
 * "guestfs_inspect_get_*" functions in order to query further information
 * about each operating system, such as the name and version.
 * 
 * This function uses other libguestfs features such as
 * guestfs_session_mount_ro() and guestfs_session_umount_all() in order to
 * mount and unmount filesystems and look at the contents. This should be
 * called with no disks currently mounted. The function may also use
 * Augeas, so any existing Augeas handle will be closed.
 * 
 * This function cannot decrypt encrypted disks. The caller must do that
 * first (supplying the necessary keys) if the disk is encrypted.
 * 
 * Please read "INSPECTION" in guestfs(3) for more details.
 * 
 * See also guestfs_session_list_filesystems().
 * 
 * Returns: (transfer full) (array zero-terminated=1) (element-type utf8): an array of returned strings, or NULL on error
 * Since: 1.5.3
 */
gchar **
guestfs_session_inspect_os (GuestfsSession *session, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "inspect_os");
    return NULL;
  }

  char **ret = guestfs_inspect_os (g);
  if (ret == NULL) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return NULL;
  }

  return ret;
}

/**
 * guestfs_session_internal_exit:
 * @session: (transfer none): A GuestfsSession object
 * @cancellable: A GCancellable object
 * @err: A GError object to receive any generated errors
 *
 * cause the daemon to exit (internal use only)
 *
 * This function is used internally when closing the appliance. Note it's
 * only called when ./configure --enable-valgrind-daemon is used.
 * 
 * Returns: true on success, false on error
 * Since: 1.23.30
 */
gboolean
guestfs_session_internal_exit (GuestfsSession *session, GCancellable *cancellable, GError **err)
{
  /* Check we haven't already been cancelled */
  if (g_cancellable_set_error_if_cancelled (cancellable, err))
    return FALSE;

  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "internal_exit");
    return FALSE;
  }

  gulong id = 0;
  if (cancellable) {
    id = g_cancellable_connect (cancellable,
                               G_CALLBACK (cancelled_handler),
                               g, NULL);
  }

  int ret = guestfs_internal_exit (g);
  g_cancellable_disconnect (cancellable, id);
  if (ret == -1) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return FALSE;
  }

  return TRUE;
}

/**
 * guestfs_session_internal_test:
 * @session: (transfer none): A GuestfsSession object
 * @str: (transfer none) (type utf8):
 * @optstr: (transfer none) (type utf8) (allow-none):
 * @strlist: (transfer none) (array zero-terminated=1) (element-type utf8): an array of strings
 * @b: (type gboolean):
 * @integer: (type gint32):
 * @integer64: (type gint64):
 * @filein: (transfer none) (type filename):
 * @fileout: (transfer none) (type filename):
 * @bufferin: (transfer none) (array length=bufferin_size) (element-type guint8): an array of binary data
 * @bufferin_size: The size of bufferin, in bytes
 * @optargs: (transfer none) (allow-none): a GuestfsInternalTest containing optional arguments
 * @cancellable: A GCancellable object
 * @err: A GError object to receive any generated errors
 *
 * internal test function - do not use
 *
 * This is an internal test function which is used to test whether the
 * automatically generated bindings can handle every possible parameter
 * type correctly.
 * 
 * It echos the contents of each parameter to stdout (by default) or to a
 * file (if guestfs_session_internal_test_set_output() was called).
 * 
 * You probably don't want to call this function.
 * 
 * Returns: true on success, false on error
 */
gboolean
guestfs_session_internal_test (GuestfsSession *session, const gchar *str, const gchar *optstr, gchar *const *strlist, gboolean b, gint32 integer, gint64 integer64, const gchar *filein, const gchar *fileout, const guint8 *bufferin, gsize bufferin_size, GuestfsInternalTest *optargs, GCancellable *cancellable, GError **err)
{
  /* Check we haven't already been cancelled */
  if (g_cancellable_set_error_if_cancelled (cancellable, err))
    return FALSE;

  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "internal_test");
    return FALSE;
  }

  struct guestfs_internal_test_argv argv;
  struct guestfs_internal_test_argv *argvp = NULL;

  if (optargs) {
    argv.bitmask = 0;

    GValue obool_v = {0, };
    g_value_init (&obool_v, GUESTFS_TYPE_TRISTATE);
    g_object_get_property (G_OBJECT (optargs), "obool", &obool_v);
    GuestfsTristate obool = g_value_get_enum (&obool_v);
    if (obool != GUESTFS_TRISTATE_NONE) {
      argv.bitmask |= GUESTFS_INTERNAL_TEST_OBOOL_BITMASK;
      argv.obool = obool;
    }
    GValue oint_v = {0, };
    g_value_init (&oint_v, G_TYPE_INT);
    g_object_get_property (G_OBJECT (optargs), "oint", &oint_v);
    gint32 oint = g_value_get_int (&oint_v);
    if (oint != -1) {
      argv.bitmask |= GUESTFS_INTERNAL_TEST_OINT_BITMASK;
      argv.oint = oint;
    }
    GValue oint64_v = {0, };
    g_value_init (&oint64_v, G_TYPE_INT64);
    g_object_get_property (G_OBJECT (optargs), "oint64", &oint64_v);
    gint64 oint64 = g_value_get_int64 (&oint64_v);
    if (oint64 != -1) {
      argv.bitmask |= GUESTFS_INTERNAL_TEST_OINT64_BITMASK;
      argv.oint64 = oint64;
    }
    GValue ostring_v = {0, };
    g_value_init (&ostring_v, G_TYPE_STRING);
    g_object_get_property (G_OBJECT (optargs), "ostring", &ostring_v);
    const gchar *ostring = g_value_get_string (&ostring_v);
    if (ostring != NULL) {
      argv.bitmask |= GUESTFS_INTERNAL_TEST_OSTRING_BITMASK;
      argv.ostring = ostring;
    }
    argvp = &argv;
  }
  gulong id = 0;
  if (cancellable) {
    id = g_cancellable_connect (cancellable,
                               G_CALLBACK (cancelled_handler),
                               g, NULL);
  }

  int ret = guestfs_internal_test_argv (g, str, optstr, strlist, b, integer, integer64, filein, fileout, (const char *) bufferin, bufferin_size, argvp);
  g_cancellable_disconnect (cancellable, id);
  if (ret == -1) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return FALSE;
  }

  return TRUE;
}

/**
 * guestfs_session_internal_test_63_optargs:
 * @session: (transfer none): A GuestfsSession object
 * @optargs: (transfer none) (allow-none): a GuestfsInternalTest63Optargs containing optional arguments
 * @cancellable: A GCancellable object
 * @err: A GError object to receive any generated errors
 *
 * internal test function - do not use
 *
 * This is an internal test function which is used to test whether the
 * automatically generated bindings can handle the full range of 63 optargs
 * correctly. (Note that 63 is not an absolute limit and it could be raised
 * by changing the XDR protocol).
 * 
 * It echos the contents of each parameter to stdout (by default) or to a
 * file (if guestfs_session_internal_test_set_output() was called).
 * 
 * You probably don't want to call this function.
 * 
 * Returns: true on success, false on error
 */
gboolean
guestfs_session_internal_test_63_optargs (GuestfsSession *session, GuestfsInternalTest63Optargs *optargs, GCancellable *cancellable, GError **err)
{
  /* Check we haven't already been cancelled */
  if (g_cancellable_set_error_if_cancelled (cancellable, err))
    return FALSE;

  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "internal_test_63_optargs");
    return FALSE;
  }

  struct guestfs_internal_test_63_optargs_argv argv;
  struct guestfs_internal_test_63_optargs_argv *argvp = NULL;

  if (optargs) {
    argv.bitmask = 0;

    GValue opt1_v = {0, };
    g_value_init (&opt1_v, G_TYPE_INT);
    g_object_get_property (G_OBJECT (optargs), "opt1", &opt1_v);
    gint32 opt1 = g_value_get_int (&opt1_v);
    if (opt1 != -1) {
      argv.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT1_BITMASK;
      argv.opt1 = opt1;
    }
    GValue opt2_v = {0, };
    g_value_init (&opt2_v, G_TYPE_INT);
    g_object_get_property (G_OBJECT (optargs), "opt2", &opt2_v);
    gint32 opt2 = g_value_get_int (&opt2_v);
    if (opt2 != -1) {
      argv.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT2_BITMASK;
      argv.opt2 = opt2;
    }
    GValue opt3_v = {0, };
    g_value_init (&opt3_v, G_TYPE_INT);
    g_object_get_property (G_OBJECT (optargs), "opt3", &opt3_v);
    gint32 opt3 = g_value_get_int (&opt3_v);
    if (opt3 != -1) {
      argv.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT3_BITMASK;
      argv.opt3 = opt3;
    }
    GValue opt4_v = {0, };
    g_value_init (&opt4_v, G_TYPE_INT);
    g_object_get_property (G_OBJECT (optargs), "opt4", &opt4_v);
    gint32 opt4 = g_value_get_int (&opt4_v);
    if (opt4 != -1) {
      argv.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT4_BITMASK;
      argv.opt4 = opt4;
    }
    GValue opt5_v = {0, };
    g_value_init (&opt5_v, G_TYPE_INT);
    g_object_get_property (G_OBJECT (optargs), "opt5", &opt5_v);
    gint32 opt5 = g_value_get_int (&opt5_v);
    if (opt5 != -1) {
      argv.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT5_BITMASK;
      argv.opt5 = opt5;
    }
    GValue opt6_v = {0, };
    g_value_init (&opt6_v, G_TYPE_INT);
    g_object_get_property (G_OBJECT (optargs), "opt6", &opt6_v);
    gint32 opt6 = g_value_get_int (&opt6_v);
    if (opt6 != -1) {
      argv.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT6_BITMASK;
      argv.opt6 = opt6;
    }
    GValue opt7_v = {0, };
    g_value_init (&opt7_v, G_TYPE_INT);
    g_object_get_property (G_OBJECT (optargs), "opt7", &opt7_v);
    gint32 opt7 = g_value_get_int (&opt7_v);
    if (opt7 != -1) {
      argv.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT7_BITMASK;
      argv.opt7 = opt7;
    }
    GValue opt8_v = {0, };
    g_value_init (&opt8_v, G_TYPE_INT);
    g_object_get_property (G_OBJECT (optargs), "opt8", &opt8_v);
    gint32 opt8 = g_value_get_int (&opt8_v);
    if (opt8 != -1) {
      argv.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT8_BITMASK;
      argv.opt8 = opt8;
    }
    GValue opt9_v = {0, };
    g_value_init (&opt9_v, G_TYPE_INT);
    g_object_get_property (G_OBJECT (optargs), "opt9", &opt9_v);
    gint32 opt9 = g_value_get_int (&opt9_v);
    if (opt9 != -1) {
      argv.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT9_BITMASK;
      argv.opt9 = opt9;
    }
    GValue opt10_v = {0, };
    g_value_init (&opt10_v, G_TYPE_INT);
    g_object_get_property (G_OBJECT (optargs), "opt10", &opt10_v);
    gint32 opt10 = g_value_get_int (&opt10_v);
    if (opt10 != -1) {
      argv.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT10_BITMASK;
      argv.opt10 = opt10;
    }
    GValue opt11_v = {0, };
    g_value_init (&opt11_v, G_TYPE_INT);
    g_object_get_property (G_OBJECT (optargs), "opt11", &opt11_v);
    gint32 opt11 = g_value_get_int (&opt11_v);
    if (opt11 != -1) {
      argv.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT11_BITMASK;
      argv.opt11 = opt11;
    }
    GValue opt12_v = {0, };
    g_value_init (&opt12_v, G_TYPE_INT);
    g_object_get_property (G_OBJECT (optargs), "opt12", &opt12_v);
    gint32 opt12 = g_value_get_int (&opt12_v);
    if (opt12 != -1) {
      argv.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT12_BITMASK;
      argv.opt12 = opt12;
    }
    GValue opt13_v = {0, };
    g_value_init (&opt13_v, G_TYPE_INT);
    g_object_get_property (G_OBJECT (optargs), "opt13", &opt13_v);
    gint32 opt13 = g_value_get_int (&opt13_v);
    if (opt13 != -1) {
      argv.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT13_BITMASK;
      argv.opt13 = opt13;
    }
    GValue opt14_v = {0, };
    g_value_init (&opt14_v, G_TYPE_INT);
    g_object_get_property (G_OBJECT (optargs), "opt14", &opt14_v);
    gint32 opt14 = g_value_get_int (&opt14_v);
    if (opt14 != -1) {
      argv.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT14_BITMASK;
      argv.opt14 = opt14;
    }
    GValue opt15_v = {0, };
    g_value_init (&opt15_v, G_TYPE_INT);
    g_object_get_property (G_OBJECT (optargs), "opt15", &opt15_v);
    gint32 opt15 = g_value_get_int (&opt15_v);
    if (opt15 != -1) {
      argv.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT15_BITMASK;
      argv.opt15 = opt15;
    }
    GValue opt16_v = {0, };
    g_value_init (&opt16_v, G_TYPE_INT);
    g_object_get_property (G_OBJECT (optargs), "opt16", &opt16_v);
    gint32 opt16 = g_value_get_int (&opt16_v);
    if (opt16 != -1) {
      argv.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT16_BITMASK;
      argv.opt16 = opt16;
    }
    GValue opt17_v = {0, };
    g_value_init (&opt17_v, G_TYPE_INT);
    g_object_get_property (G_OBJECT (optargs), "opt17", &opt17_v);
    gint32 opt17 = g_value_get_int (&opt17_v);
    if (opt17 != -1) {
      argv.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT17_BITMASK;
      argv.opt17 = opt17;
    }
    GValue opt18_v = {0, };
    g_value_init (&opt18_v, G_TYPE_INT);
    g_object_get_property (G_OBJECT (optargs), "opt18", &opt18_v);
    gint32 opt18 = g_value_get_int (&opt18_v);
    if (opt18 != -1) {
      argv.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT18_BITMASK;
      argv.opt18 = opt18;
    }
    GValue opt19_v = {0, };
    g_value_init (&opt19_v, G_TYPE_INT);
    g_object_get_property (G_OBJECT (optargs), "opt19", &opt19_v);
    gint32 opt19 = g_value_get_int (&opt19_v);
    if (opt19 != -1) {
      argv.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT19_BITMASK;
      argv.opt19 = opt19;
    }
    GValue opt20_v = {0, };
    g_value_init (&opt20_v, G_TYPE_INT);
    g_object_get_property (G_OBJECT (optargs), "opt20", &opt20_v);
    gint32 opt20 = g_value_get_int (&opt20_v);
    if (opt20 != -1) {
      argv.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT20_BITMASK;
      argv.opt20 = opt20;
    }
    GValue opt21_v = {0, };
    g_value_init (&opt21_v, G_TYPE_INT);
    g_object_get_property (G_OBJECT (optargs), "opt21", &opt21_v);
    gint32 opt21 = g_value_get_int (&opt21_v);
    if (opt21 != -1) {
      argv.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT21_BITMASK;
      argv.opt21 = opt21;
    }
    GValue opt22_v = {0, };
    g_value_init (&opt22_v, G_TYPE_INT);
    g_object_get_property (G_OBJECT (optargs), "opt22", &opt22_v);
    gint32 opt22 = g_value_get_int (&opt22_v);
    if (opt22 != -1) {
      argv.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT22_BITMASK;
      argv.opt22 = opt22;
    }
    GValue opt23_v = {0, };
    g_value_init (&opt23_v, G_TYPE_INT);
    g_object_get_property (G_OBJECT (optargs), "opt23", &opt23_v);
    gint32 opt23 = g_value_get_int (&opt23_v);
    if (opt23 != -1) {
      argv.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT23_BITMASK;
      argv.opt23 = opt23;
    }
    GValue opt24_v = {0, };
    g_value_init (&opt24_v, G_TYPE_INT);
    g_object_get_property (G_OBJECT (optargs), "opt24", &opt24_v);
    gint32 opt24 = g_value_get_int (&opt24_v);
    if (opt24 != -1) {
      argv.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT24_BITMASK;
      argv.opt24 = opt24;
    }
    GValue opt25_v = {0, };
    g_value_init (&opt25_v, G_TYPE_INT);
    g_object_get_property (G_OBJECT (optargs), "opt25", &opt25_v);
    gint32 opt25 = g_value_get_int (&opt25_v);
    if (opt25 != -1) {
      argv.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT25_BITMASK;
      argv.opt25 = opt25;
    }
    GValue opt26_v = {0, };
    g_value_init (&opt26_v, G_TYPE_INT);
    g_object_get_property (G_OBJECT (optargs), "opt26", &opt26_v);
    gint32 opt26 = g_value_get_int (&opt26_v);
    if (opt26 != -1) {
      argv.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT26_BITMASK;
      argv.opt26 = opt26;
    }
    GValue opt27_v = {0, };
    g_value_init (&opt27_v, G_TYPE_INT);
    g_object_get_property (G_OBJECT (optargs), "opt27", &opt27_v);
    gint32 opt27 = g_value_get_int (&opt27_v);
    if (opt27 != -1) {
      argv.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT27_BITMASK;
      argv.opt27 = opt27;
    }
    GValue opt28_v = {0, };
    g_value_init (&opt28_v, G_TYPE_INT);
    g_object_get_property (G_OBJECT (optargs), "opt28", &opt28_v);
    gint32 opt28 = g_value_get_int (&opt28_v);
    if (opt28 != -1) {
      argv.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT28_BITMASK;
      argv.opt28 = opt28;
    }
    GValue opt29_v = {0, };
    g_value_init (&opt29_v, G_TYPE_INT);
    g_object_get_property (G_OBJECT (optargs), "opt29", &opt29_v);
    gint32 opt29 = g_value_get_int (&opt29_v);
    if (opt29 != -1) {
      argv.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT29_BITMASK;
      argv.opt29 = opt29;
    }
    GValue opt30_v = {0, };
    g_value_init (&opt30_v, G_TYPE_INT);
    g_object_get_property (G_OBJECT (optargs), "opt30", &opt30_v);
    gint32 opt30 = g_value_get_int (&opt30_v);
    if (opt30 != -1) {
      argv.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT30_BITMASK;
      argv.opt30 = opt30;
    }
    GValue opt31_v = {0, };
    g_value_init (&opt31_v, G_TYPE_INT);
    g_object_get_property (G_OBJECT (optargs), "opt31", &opt31_v);
    gint32 opt31 = g_value_get_int (&opt31_v);
    if (opt31 != -1) {
      argv.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT31_BITMASK;
      argv.opt31 = opt31;
    }
    GValue opt32_v = {0, };
    g_value_init (&opt32_v, G_TYPE_INT);
    g_object_get_property (G_OBJECT (optargs), "opt32", &opt32_v);
    gint32 opt32 = g_value_get_int (&opt32_v);
    if (opt32 != -1) {
      argv.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT32_BITMASK;
      argv.opt32 = opt32;
    }
    GValue opt33_v = {0, };
    g_value_init (&opt33_v, G_TYPE_INT);
    g_object_get_property (G_OBJECT (optargs), "opt33", &opt33_v);
    gint32 opt33 = g_value_get_int (&opt33_v);
    if (opt33 != -1) {
      argv.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT33_BITMASK;
      argv.opt33 = opt33;
    }
    GValue opt34_v = {0, };
    g_value_init (&opt34_v, G_TYPE_INT);
    g_object_get_property (G_OBJECT (optargs), "opt34", &opt34_v);
    gint32 opt34 = g_value_get_int (&opt34_v);
    if (opt34 != -1) {
      argv.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT34_BITMASK;
      argv.opt34 = opt34;
    }
    GValue opt35_v = {0, };
    g_value_init (&opt35_v, G_TYPE_INT);
    g_object_get_property (G_OBJECT (optargs), "opt35", &opt35_v);
    gint32 opt35 = g_value_get_int (&opt35_v);
    if (opt35 != -1) {
      argv.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT35_BITMASK;
      argv.opt35 = opt35;
    }
    GValue opt36_v = {0, };
    g_value_init (&opt36_v, G_TYPE_INT);
    g_object_get_property (G_OBJECT (optargs), "opt36", &opt36_v);
    gint32 opt36 = g_value_get_int (&opt36_v);
    if (opt36 != -1) {
      argv.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT36_BITMASK;
      argv.opt36 = opt36;
    }
    GValue opt37_v = {0, };
    g_value_init (&opt37_v, G_TYPE_INT);
    g_object_get_property (G_OBJECT (optargs), "opt37", &opt37_v);
    gint32 opt37 = g_value_get_int (&opt37_v);
    if (opt37 != -1) {
      argv.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT37_BITMASK;
      argv.opt37 = opt37;
    }
    GValue opt38_v = {0, };
    g_value_init (&opt38_v, G_TYPE_INT);
    g_object_get_property (G_OBJECT (optargs), "opt38", &opt38_v);
    gint32 opt38 = g_value_get_int (&opt38_v);
    if (opt38 != -1) {
      argv.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT38_BITMASK;
      argv.opt38 = opt38;
    }
    GValue opt39_v = {0, };
    g_value_init (&opt39_v, G_TYPE_INT);
    g_object_get_property (G_OBJECT (optargs), "opt39", &opt39_v);
    gint32 opt39 = g_value_get_int (&opt39_v);
    if (opt39 != -1) {
      argv.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT39_BITMASK;
      argv.opt39 = opt39;
    }
    GValue opt40_v = {0, };
    g_value_init (&opt40_v, G_TYPE_INT);
    g_object_get_property (G_OBJECT (optargs), "opt40", &opt40_v);
    gint32 opt40 = g_value_get_int (&opt40_v);
    if (opt40 != -1) {
      argv.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT40_BITMASK;
      argv.opt40 = opt40;
    }
    GValue opt41_v = {0, };
    g_value_init (&opt41_v, G_TYPE_INT);
    g_object_get_property (G_OBJECT (optargs), "opt41", &opt41_v);
    gint32 opt41 = g_value_get_int (&opt41_v);
    if (opt41 != -1) {
      argv.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT41_BITMASK;
      argv.opt41 = opt41;
    }
    GValue opt42_v = {0, };
    g_value_init (&opt42_v, G_TYPE_INT);
    g_object_get_property (G_OBJECT (optargs), "opt42", &opt42_v);
    gint32 opt42 = g_value_get_int (&opt42_v);
    if (opt42 != -1) {
      argv.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT42_BITMASK;
      argv.opt42 = opt42;
    }
    GValue opt43_v = {0, };
    g_value_init (&opt43_v, G_TYPE_INT);
    g_object_get_property (G_OBJECT (optargs), "opt43", &opt43_v);
    gint32 opt43 = g_value_get_int (&opt43_v);
    if (opt43 != -1) {
      argv.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT43_BITMASK;
      argv.opt43 = opt43;
    }
    GValue opt44_v = {0, };
    g_value_init (&opt44_v, G_TYPE_INT);
    g_object_get_property (G_OBJECT (optargs), "opt44", &opt44_v);
    gint32 opt44 = g_value_get_int (&opt44_v);
    if (opt44 != -1) {
      argv.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT44_BITMASK;
      argv.opt44 = opt44;
    }
    GValue opt45_v = {0, };
    g_value_init (&opt45_v, G_TYPE_INT);
    g_object_get_property (G_OBJECT (optargs), "opt45", &opt45_v);
    gint32 opt45 = g_value_get_int (&opt45_v);
    if (opt45 != -1) {
      argv.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT45_BITMASK;
      argv.opt45 = opt45;
    }
    GValue opt46_v = {0, };
    g_value_init (&opt46_v, G_TYPE_INT);
    g_object_get_property (G_OBJECT (optargs), "opt46", &opt46_v);
    gint32 opt46 = g_value_get_int (&opt46_v);
    if (opt46 != -1) {
      argv.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT46_BITMASK;
      argv.opt46 = opt46;
    }
    GValue opt47_v = {0, };
    g_value_init (&opt47_v, G_TYPE_INT);
    g_object_get_property (G_OBJECT (optargs), "opt47", &opt47_v);
    gint32 opt47 = g_value_get_int (&opt47_v);
    if (opt47 != -1) {
      argv.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT47_BITMASK;
      argv.opt47 = opt47;
    }
    GValue opt48_v = {0, };
    g_value_init (&opt48_v, G_TYPE_INT);
    g_object_get_property (G_OBJECT (optargs), "opt48", &opt48_v);
    gint32 opt48 = g_value_get_int (&opt48_v);
    if (opt48 != -1) {
      argv.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT48_BITMASK;
      argv.opt48 = opt48;
    }
    GValue opt49_v = {0, };
    g_value_init (&opt49_v, G_TYPE_INT);
    g_object_get_property (G_OBJECT (optargs), "opt49", &opt49_v);
    gint32 opt49 = g_value_get_int (&opt49_v);
    if (opt49 != -1) {
      argv.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT49_BITMASK;
      argv.opt49 = opt49;
    }
    GValue opt50_v = {0, };
    g_value_init (&opt50_v, G_TYPE_INT);
    g_object_get_property (G_OBJECT (optargs), "opt50", &opt50_v);
    gint32 opt50 = g_value_get_int (&opt50_v);
    if (opt50 != -1) {
      argv.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT50_BITMASK;
      argv.opt50 = opt50;
    }
    GValue opt51_v = {0, };
    g_value_init (&opt51_v, G_TYPE_INT);
    g_object_get_property (G_OBJECT (optargs), "opt51", &opt51_v);
    gint32 opt51 = g_value_get_int (&opt51_v);
    if (opt51 != -1) {
      argv.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT51_BITMASK;
      argv.opt51 = opt51;
    }
    GValue opt52_v = {0, };
    g_value_init (&opt52_v, G_TYPE_INT);
    g_object_get_property (G_OBJECT (optargs), "opt52", &opt52_v);
    gint32 opt52 = g_value_get_int (&opt52_v);
    if (opt52 != -1) {
      argv.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT52_BITMASK;
      argv.opt52 = opt52;
    }
    GValue opt53_v = {0, };
    g_value_init (&opt53_v, G_TYPE_INT);
    g_object_get_property (G_OBJECT (optargs), "opt53", &opt53_v);
    gint32 opt53 = g_value_get_int (&opt53_v);
    if (opt53 != -1) {
      argv.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT53_BITMASK;
      argv.opt53 = opt53;
    }
    GValue opt54_v = {0, };
    g_value_init (&opt54_v, G_TYPE_INT);
    g_object_get_property (G_OBJECT (optargs), "opt54", &opt54_v);
    gint32 opt54 = g_value_get_int (&opt54_v);
    if (opt54 != -1) {
      argv.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT54_BITMASK;
      argv.opt54 = opt54;
    }
    GValue opt55_v = {0, };
    g_value_init (&opt55_v, G_TYPE_INT);
    g_object_get_property (G_OBJECT (optargs), "opt55", &opt55_v);
    gint32 opt55 = g_value_get_int (&opt55_v);
    if (opt55 != -1) {
      argv.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT55_BITMASK;
      argv.opt55 = opt55;
    }
    GValue opt56_v = {0, };
    g_value_init (&opt56_v, G_TYPE_INT);
    g_object_get_property (G_OBJECT (optargs), "opt56", &opt56_v);
    gint32 opt56 = g_value_get_int (&opt56_v);
    if (opt56 != -1) {
      argv.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT56_BITMASK;
      argv.opt56 = opt56;
    }
    GValue opt57_v = {0, };
    g_value_init (&opt57_v, G_TYPE_INT);
    g_object_get_property (G_OBJECT (optargs), "opt57", &opt57_v);
    gint32 opt57 = g_value_get_int (&opt57_v);
    if (opt57 != -1) {
      argv.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT57_BITMASK;
      argv.opt57 = opt57;
    }
    GValue opt58_v = {0, };
    g_value_init (&opt58_v, G_TYPE_INT);
    g_object_get_property (G_OBJECT (optargs), "opt58", &opt58_v);
    gint32 opt58 = g_value_get_int (&opt58_v);
    if (opt58 != -1) {
      argv.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT58_BITMASK;
      argv.opt58 = opt58;
    }
    GValue opt59_v = {0, };
    g_value_init (&opt59_v, G_TYPE_INT);
    g_object_get_property (G_OBJECT (optargs), "opt59", &opt59_v);
    gint32 opt59 = g_value_get_int (&opt59_v);
    if (opt59 != -1) {
      argv.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT59_BITMASK;
      argv.opt59 = opt59;
    }
    GValue opt60_v = {0, };
    g_value_init (&opt60_v, G_TYPE_INT);
    g_object_get_property (G_OBJECT (optargs), "opt60", &opt60_v);
    gint32 opt60 = g_value_get_int (&opt60_v);
    if (opt60 != -1) {
      argv.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT60_BITMASK;
      argv.opt60 = opt60;
    }
    GValue opt61_v = {0, };
    g_value_init (&opt61_v, G_TYPE_INT);
    g_object_get_property (G_OBJECT (optargs), "opt61", &opt61_v);
    gint32 opt61 = g_value_get_int (&opt61_v);
    if (opt61 != -1) {
      argv.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT61_BITMASK;
      argv.opt61 = opt61;
    }
    GValue opt62_v = {0, };
    g_value_init (&opt62_v, G_TYPE_INT);
    g_object_get_property (G_OBJECT (optargs), "opt62", &opt62_v);
    gint32 opt62 = g_value_get_int (&opt62_v);
    if (opt62 != -1) {
      argv.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT62_BITMASK;
      argv.opt62 = opt62;
    }
    GValue opt63_v = {0, };
    g_value_init (&opt63_v, G_TYPE_INT);
    g_object_get_property (G_OBJECT (optargs), "opt63", &opt63_v);
    gint32 opt63 = g_value_get_int (&opt63_v);
    if (opt63 != -1) {
      argv.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT63_BITMASK;
      argv.opt63 = opt63;
    }
    argvp = &argv;
  }
  gulong id = 0;
  if (cancellable) {
    id = g_cancellable_connect (cancellable,
                               G_CALLBACK (cancelled_handler),
                               g, NULL);
  }

  int ret = guestfs_internal_test_63_optargs_argv (g, argvp);
  g_cancellable_disconnect (cancellable, id);
  if (ret == -1) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return FALSE;
  }

  return TRUE;
}

/**
 * guestfs_session_internal_test_close_output:
 * @session: (transfer none): A GuestfsSession object
 * @err: A GError object to receive any generated errors
 *
 * internal test function - do not use
 *
 * This is an internal test function which is used to test whether the
 * automatically generated bindings can handle every possible parameter
 * type correctly.
 * 
 * It closes the output file previously opened by
 * guestfs_session_internal_test_set_output().
 * 
 * You probably don't want to call this function.
 * 
 * Returns: true on success, false on error
 */
gboolean
guestfs_session_internal_test_close_output (GuestfsSession *session, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "internal_test_close_output");
    return FALSE;
  }

  int ret = guestfs_internal_test_close_output (g);
  if (ret == -1) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return FALSE;
  }

  return TRUE;
}

/**
 * guestfs_session_internal_test_only_optargs:
 * @session: (transfer none): A GuestfsSession object
 * @optargs: (transfer none) (allow-none): a GuestfsInternalTestOnlyOptargs containing optional arguments
 * @cancellable: A GCancellable object
 * @err: A GError object to receive any generated errors
 *
 * internal test function - do not use
 *
 * This is an internal test function which is used to test whether the
 * automatically generated bindings can handle no args, some optargs
 * correctly.
 * 
 * It echos the contents of each parameter to stdout (by default) or to a
 * file (if guestfs_session_internal_test_set_output() was called).
 * 
 * You probably don't want to call this function.
 * 
 * Returns: true on success, false on error
 */
gboolean
guestfs_session_internal_test_only_optargs (GuestfsSession *session, GuestfsInternalTestOnlyOptargs *optargs, GCancellable *cancellable, GError **err)
{
  /* Check we haven't already been cancelled */
  if (g_cancellable_set_error_if_cancelled (cancellable, err))
    return FALSE;

  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "internal_test_only_optargs");
    return FALSE;
  }

  struct guestfs_internal_test_only_optargs_argv argv;
  struct guestfs_internal_test_only_optargs_argv *argvp = NULL;

  if (optargs) {
    argv.bitmask = 0;

    GValue test_v = {0, };
    g_value_init (&test_v, G_TYPE_INT);
    g_object_get_property (G_OBJECT (optargs), "test", &test_v);
    gint32 test = g_value_get_int (&test_v);
    if (test != -1) {
      argv.bitmask |= GUESTFS_INTERNAL_TEST_ONLY_OPTARGS_TEST_BITMASK;
      argv.test = test;
    }
    argvp = &argv;
  }
  gulong id = 0;
  if (cancellable) {
    id = g_cancellable_connect (cancellable,
                               G_CALLBACK (cancelled_handler),
                               g, NULL);
  }

  int ret = guestfs_internal_test_only_optargs_argv (g, argvp);
  g_cancellable_disconnect (cancellable, id);
  if (ret == -1) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return FALSE;
  }

  return TRUE;
}

/**
 * guestfs_session_internal_test_rbool:
 * @session: (transfer none): A GuestfsSession object
 * @val: (transfer none) (type utf8):
 * @err: A GError object to receive any generated errors
 *
 * internal test function - do not use
 *
 * This is an internal test function which is used to test whether the
 * automatically generated bindings can handle every possible return type
 * correctly.
 * 
 * It converts string @val to the return type.
 * 
 * You probably don't want to call this function.
 * 
 * Returns: the returned value, or -1 on error
 */
gint8
guestfs_session_internal_test_rbool (GuestfsSession *session, const gchar *val, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "internal_test_rbool");
    return -1;
  }

  int ret = guestfs_internal_test_rbool (g, val);
  if (ret == -1) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return -1;
  }

  return ret;
}

/**
 * guestfs_session_internal_test_rboolerr:
 * @session: (transfer none): A GuestfsSession object
 * @err: A GError object to receive any generated errors
 *
 * internal test function - do not use
 *
 * This is an internal test function which is used to test whether the
 * automatically generated bindings can handle every possible return type
 * correctly.
 * 
 * This function always returns an error.
 * 
 * You probably don't want to call this function.
 * 
 * Returns: the returned value, or -1 on error
 */
gint8
guestfs_session_internal_test_rboolerr (GuestfsSession *session, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "internal_test_rboolerr");
    return -1;
  }

  int ret = guestfs_internal_test_rboolerr (g);
  if (ret == -1) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return -1;
  }

  return ret;
}

/**
 * guestfs_session_internal_test_rbufferout:
 * @session: (transfer none): A GuestfsSession object
 * @val: (transfer none) (type utf8):
 * @size_r: The size of the returned buffer, in bytes
 * @err: A GError object to receive any generated errors
 *
 * internal test function - do not use
 *
 * This is an internal test function which is used to test whether the
 * automatically generated bindings can handle every possible return type
 * correctly.
 * 
 * It converts string @val to the return type.
 * 
 * You probably don't want to call this function.
 * 
 * Returns: (transfer full) (array length=size_r) (element-type guint8): an array of binary data, or NULL on error
 */
guint8 *
guestfs_session_internal_test_rbufferout (GuestfsSession *session, const gchar *val, gsize *size_r, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "internal_test_rbufferout");
    return NULL;
  }

  char *ret = guestfs_internal_test_rbufferout (g, val, size_r);
  if (ret == NULL) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return NULL;
  }

  return (guint8 *) ret;
}

/**
 * guestfs_session_internal_test_rbufferouterr:
 * @session: (transfer none): A GuestfsSession object
 * @size_r: The size of the returned buffer, in bytes
 * @err: A GError object to receive any generated errors
 *
 * internal test function - do not use
 *
 * This is an internal test function which is used to test whether the
 * automatically generated bindings can handle every possible return type
 * correctly.
 * 
 * This function always returns an error.
 * 
 * You probably don't want to call this function.
 * 
 * Returns: (transfer full) (array length=size_r) (element-type guint8): an array of binary data, or NULL on error
 */
guint8 *
guestfs_session_internal_test_rbufferouterr (GuestfsSession *session, gsize *size_r, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "internal_test_rbufferouterr");
    return NULL;
  }

  char *ret = guestfs_internal_test_rbufferouterr (g, size_r);
  if (ret == NULL) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return NULL;
  }

  return (guint8 *) ret;
}

/**
 * guestfs_session_internal_test_rconstoptstring:
 * @session: (transfer none): A GuestfsSession object
 * @val: (transfer none) (type utf8):
 * @err: A GError object to receive any generated errors
 *
 * internal test function - do not use
 *
 * This is an internal test function which is used to test whether the
 * automatically generated bindings can handle every possible return type
 * correctly.
 * 
 * It converts string @val to the return type.
 * 
 * You probably don't want to call this function.
 * 
 * Returns: (transfer none): the returned string. Note that NULL does not indicate error
 */
const gchar *
guestfs_session_internal_test_rconstoptstring (GuestfsSession *session, const gchar *val, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "internal_test_rconstoptstring");
    return NULL;
  }

  const char *ret = guestfs_internal_test_rconstoptstring (g, val);

  return ret;
}

/**
 * guestfs_session_internal_test_rconstoptstringerr:
 * @session: (transfer none): A GuestfsSession object
 * @err: A GError object to receive any generated errors
 *
 * internal test function - do not use
 *
 * This is an internal test function which is used to test whether the
 * automatically generated bindings can handle every possible return type
 * correctly.
 * 
 * This function always returns an error.
 * 
 * You probably don't want to call this function.
 * 
 * Returns: (transfer none): the returned string. Note that NULL does not indicate error
 */
const gchar *
guestfs_session_internal_test_rconstoptstringerr (GuestfsSession *session, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "internal_test_rconstoptstringerr");
    return NULL;
  }

  const char *ret = guestfs_internal_test_rconstoptstringerr (g);

  return ret;
}

/**
 * guestfs_session_internal_test_rconststring:
 * @session: (transfer none): A GuestfsSession object
 * @val: (transfer none) (type utf8):
 * @err: A GError object to receive any generated errors
 *
 * internal test function - do not use
 *
 * This is an internal test function which is used to test whether the
 * automatically generated bindings can handle every possible return type
 * correctly.
 * 
 * It converts string @val to the return type.
 * 
 * You probably don't want to call this function.
 * 
 * Returns: (transfer none): the returned string, or NULL on error
 */
const gchar *
guestfs_session_internal_test_rconststring (GuestfsSession *session, const gchar *val, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "internal_test_rconststring");
    return NULL;
  }

  const char *ret = guestfs_internal_test_rconststring (g, val);
  if (ret == NULL) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return NULL;
  }

  return ret;
}

/**
 * guestfs_session_internal_test_rconststringerr:
 * @session: (transfer none): A GuestfsSession object
 * @err: A GError object to receive any generated errors
 *
 * internal test function - do not use
 *
 * This is an internal test function which is used to test whether the
 * automatically generated bindings can handle every possible return type
 * correctly.
 * 
 * This function always returns an error.
 * 
 * You probably don't want to call this function.
 * 
 * Returns: (transfer none): the returned string, or NULL on error
 */
const gchar *
guestfs_session_internal_test_rconststringerr (GuestfsSession *session, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "internal_test_rconststringerr");
    return NULL;
  }

  const char *ret = guestfs_internal_test_rconststringerr (g);
  if (ret == NULL) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return NULL;
  }

  return ret;
}

/**
 * guestfs_session_internal_test_rhashtable:
 * @session: (transfer none): A GuestfsSession object
 * @val: (transfer none) (type utf8):
 * @err: A GError object to receive any generated errors
 *
 * internal test function - do not use
 *
 * This is an internal test function which is used to test whether the
 * automatically generated bindings can handle every possible return type
 * correctly.
 * 
 * It converts string @val to the return type.
 * 
 * You probably don't want to call this function.
 * 
 * Returns: (transfer full) (element-type utf8 utf8): a GHashTable of results, or NULL on error
 */
GHashTable *
guestfs_session_internal_test_rhashtable (GuestfsSession *session, const gchar *val, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "internal_test_rhashtable");
    return NULL;
  }

  char **ret = guestfs_internal_test_rhashtable (g, val);
  if (ret == NULL) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return NULL;
  }

  GHashTable *h = g_hash_table_new_full (g_str_hash, g_str_equal, g_free, g_free);
  char **i = ret;
  while (*i) {
    char *key = *i; i++;
    char *value = *i; i++;
    g_hash_table_insert (h, key, value);
  };
  g_free (ret);
  return h;
}

/**
 * guestfs_session_internal_test_rhashtableerr:
 * @session: (transfer none): A GuestfsSession object
 * @err: A GError object to receive any generated errors
 *
 * internal test function - do not use
 *
 * This is an internal test function which is used to test whether the
 * automatically generated bindings can handle every possible return type
 * correctly.
 * 
 * This function always returns an error.
 * 
 * You probably don't want to call this function.
 * 
 * Returns: (transfer full) (element-type utf8 utf8): a GHashTable of results, or NULL on error
 */
GHashTable *
guestfs_session_internal_test_rhashtableerr (GuestfsSession *session, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "internal_test_rhashtableerr");
    return NULL;
  }

  char **ret = guestfs_internal_test_rhashtableerr (g);
  if (ret == NULL) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return NULL;
  }

  GHashTable *h = g_hash_table_new_full (g_str_hash, g_str_equal, g_free, g_free);
  char **i = ret;
  while (*i) {
    char *key = *i; i++;
    char *value = *i; i++;
    g_hash_table_insert (h, key, value);
  };
  g_free (ret);
  return h;
}

/**
 * guestfs_session_internal_test_rint:
 * @session: (transfer none): A GuestfsSession object
 * @val: (transfer none) (type utf8):
 * @err: A GError object to receive any generated errors
 *
 * internal test function - do not use
 *
 * This is an internal test function which is used to test whether the
 * automatically generated bindings can handle every possible return type
 * correctly.
 * 
 * It converts string @val to the return type.
 * 
 * You probably don't want to call this function.
 * 
 * Returns: the returned value, or -1 on error
 */
gint32
guestfs_session_internal_test_rint (GuestfsSession *session, const gchar *val, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "internal_test_rint");
    return -1;
  }

  int ret = guestfs_internal_test_rint (g, val);
  if (ret == -1) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return -1;
  }

  return ret;
}

/**
 * guestfs_session_internal_test_rint64:
 * @session: (transfer none): A GuestfsSession object
 * @val: (transfer none) (type utf8):
 * @err: A GError object to receive any generated errors
 *
 * internal test function - do not use
 *
 * This is an internal test function which is used to test whether the
 * automatically generated bindings can handle every possible return type
 * correctly.
 * 
 * It converts string @val to the return type.
 * 
 * You probably don't want to call this function.
 * 
 * Returns: the returned value, or -1 on error
 */
gint64
guestfs_session_internal_test_rint64 (GuestfsSession *session, const gchar *val, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "internal_test_rint64");
    return -1;
  }

  int64_t ret = guestfs_internal_test_rint64 (g, val);
  if (ret == -1) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return -1;
  }

  return ret;
}

/**
 * guestfs_session_internal_test_rint64err:
 * @session: (transfer none): A GuestfsSession object
 * @err: A GError object to receive any generated errors
 *
 * internal test function - do not use
 *
 * This is an internal test function which is used to test whether the
 * automatically generated bindings can handle every possible return type
 * correctly.
 * 
 * This function always returns an error.
 * 
 * You probably don't want to call this function.
 * 
 * Returns: the returned value, or -1 on error
 */
gint64
guestfs_session_internal_test_rint64err (GuestfsSession *session, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "internal_test_rint64err");
    return -1;
  }

  int64_t ret = guestfs_internal_test_rint64err (g);
  if (ret == -1) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return -1;
  }

  return ret;
}

/**
 * guestfs_session_internal_test_rinterr:
 * @session: (transfer none): A GuestfsSession object
 * @err: A GError object to receive any generated errors
 *
 * internal test function - do not use
 *
 * This is an internal test function which is used to test whether the
 * automatically generated bindings can handle every possible return type
 * correctly.
 * 
 * This function always returns an error.
 * 
 * You probably don't want to call this function.
 * 
 * Returns: the returned value, or -1 on error
 */
gint32
guestfs_session_internal_test_rinterr (GuestfsSession *session, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "internal_test_rinterr");
    return -1;
  }

  int ret = guestfs_internal_test_rinterr (g);
  if (ret == -1) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return -1;
  }

  return ret;
}

/**
 * guestfs_session_internal_test_rstring:
 * @session: (transfer none): A GuestfsSession object
 * @val: (transfer none) (type utf8):
 * @err: A GError object to receive any generated errors
 *
 * internal test function - do not use
 *
 * This is an internal test function which is used to test whether the
 * automatically generated bindings can handle every possible return type
 * correctly.
 * 
 * It converts string @val to the return type.
 * 
 * You probably don't want to call this function.
 * 
 * Returns: (transfer full): the returned string, or NULL on error
 */
gchar *
guestfs_session_internal_test_rstring (GuestfsSession *session, const gchar *val, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "internal_test_rstring");
    return NULL;
  }

  char *ret = guestfs_internal_test_rstring (g, val);
  if (ret == NULL) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return NULL;
  }

  return ret;
}

/**
 * guestfs_session_internal_test_rstringerr:
 * @session: (transfer none): A GuestfsSession object
 * @err: A GError object to receive any generated errors
 *
 * internal test function - do not use
 *
 * This is an internal test function which is used to test whether the
 * automatically generated bindings can handle every possible return type
 * correctly.
 * 
 * This function always returns an error.
 * 
 * You probably don't want to call this function.
 * 
 * Returns: (transfer full): the returned string, or NULL on error
 */
gchar *
guestfs_session_internal_test_rstringerr (GuestfsSession *session, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "internal_test_rstringerr");
    return NULL;
  }

  char *ret = guestfs_internal_test_rstringerr (g);
  if (ret == NULL) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return NULL;
  }

  return ret;
}

/**
 * guestfs_session_internal_test_rstringlist:
 * @session: (transfer none): A GuestfsSession object
 * @val: (transfer none) (type utf8):
 * @err: A GError object to receive any generated errors
 *
 * internal test function - do not use
 *
 * This is an internal test function which is used to test whether the
 * automatically generated bindings can handle every possible return type
 * correctly.
 * 
 * It converts string @val to the return type.
 * 
 * You probably don't want to call this function.
 * 
 * Returns: (transfer full) (array zero-terminated=1) (element-type utf8): an array of returned strings, or NULL on error
 */
gchar **
guestfs_session_internal_test_rstringlist (GuestfsSession *session, const gchar *val, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "internal_test_rstringlist");
    return NULL;
  }

  char **ret = guestfs_internal_test_rstringlist (g, val);
  if (ret == NULL) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return NULL;
  }

  return ret;
}

/**
 * guestfs_session_internal_test_rstringlisterr:
 * @session: (transfer none): A GuestfsSession object
 * @err: A GError object to receive any generated errors
 *
 * internal test function - do not use
 *
 * This is an internal test function which is used to test whether the
 * automatically generated bindings can handle every possible return type
 * correctly.
 * 
 * This function always returns an error.
 * 
 * You probably don't want to call this function.
 * 
 * Returns: (transfer full) (array zero-terminated=1) (element-type utf8): an array of returned strings, or NULL on error
 */
gchar **
guestfs_session_internal_test_rstringlisterr (GuestfsSession *session, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "internal_test_rstringlisterr");
    return NULL;
  }

  char **ret = guestfs_internal_test_rstringlisterr (g);
  if (ret == NULL) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return NULL;
  }

  return ret;
}

/**
 * guestfs_session_internal_test_rstruct:
 * @session: (transfer none): A GuestfsSession object
 * @val: (transfer none) (type utf8):
 * @err: A GError object to receive any generated errors
 *
 * internal test function - do not use
 *
 * This is an internal test function which is used to test whether the
 * automatically generated bindings can handle every possible return type
 * correctly.
 * 
 * It converts string @val to the return type.
 * 
 * You probably don't want to call this function.
 * 
 * Returns: (transfer full): a PV object, or NULL on error
 */
GuestfsPV *
guestfs_session_internal_test_rstruct (GuestfsSession *session, const gchar *val, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "internal_test_rstruct");
    return NULL;
  }

  struct guestfs_lvm_pv *ret = guestfs_internal_test_rstruct (g, val);
  if (ret == NULL) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return NULL;
  }

  GuestfsPV *s = g_slice_new0 (GuestfsPV);
  if (ret->pv_name) s->pv_name = g_strdup (ret->pv_name);
  if (ret->pv_uuid) memcpy (s->pv_uuid, ret->pv_uuid, sizeof (s->pv_uuid));
  if (ret->pv_fmt) s->pv_fmt = g_strdup (ret->pv_fmt);
  s->pv_size = ret->pv_size;
  s->dev_size = ret->dev_size;
  s->pv_free = ret->pv_free;
  s->pv_used = ret->pv_used;
  if (ret->pv_attr) s->pv_attr = g_strdup (ret->pv_attr);
  s->pv_pe_count = ret->pv_pe_count;
  s->pv_pe_alloc_count = ret->pv_pe_alloc_count;
  if (ret->pv_tags) s->pv_tags = g_strdup (ret->pv_tags);
  s->pe_start = ret->pe_start;
  s->pv_mda_count = ret->pv_mda_count;
  s->pv_mda_free = ret->pv_mda_free;
  guestfs_free_lvm_pv (ret);
  return s;
}

/**
 * guestfs_session_internal_test_rstructerr:
 * @session: (transfer none): A GuestfsSession object
 * @err: A GError object to receive any generated errors
 *
 * internal test function - do not use
 *
 * This is an internal test function which is used to test whether the
 * automatically generated bindings can handle every possible return type
 * correctly.
 * 
 * This function always returns an error.
 * 
 * You probably don't want to call this function.
 * 
 * Returns: (transfer full): a PV object, or NULL on error
 */
GuestfsPV *
guestfs_session_internal_test_rstructerr (GuestfsSession *session, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "internal_test_rstructerr");
    return NULL;
  }

  struct guestfs_lvm_pv *ret = guestfs_internal_test_rstructerr (g);
  if (ret == NULL) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return NULL;
  }

  GuestfsPV *s = g_slice_new0 (GuestfsPV);
  if (ret->pv_name) s->pv_name = g_strdup (ret->pv_name);
  if (ret->pv_uuid) memcpy (s->pv_uuid, ret->pv_uuid, sizeof (s->pv_uuid));
  if (ret->pv_fmt) s->pv_fmt = g_strdup (ret->pv_fmt);
  s->pv_size = ret->pv_size;
  s->dev_size = ret->dev_size;
  s->pv_free = ret->pv_free;
  s->pv_used = ret->pv_used;
  if (ret->pv_attr) s->pv_attr = g_strdup (ret->pv_attr);
  s->pv_pe_count = ret->pv_pe_count;
  s->pv_pe_alloc_count = ret->pv_pe_alloc_count;
  if (ret->pv_tags) s->pv_tags = g_strdup (ret->pv_tags);
  s->pe_start = ret->pe_start;
  s->pv_mda_count = ret->pv_mda_count;
  s->pv_mda_free = ret->pv_mda_free;
  guestfs_free_lvm_pv (ret);
  return s;
}

/**
 * guestfs_session_internal_test_rstructlist:
 * @session: (transfer none): A GuestfsSession object
 * @val: (transfer none) (type utf8):
 * @err: A GError object to receive any generated errors
 *
 * internal test function - do not use
 *
 * This is an internal test function which is used to test whether the
 * automatically generated bindings can handle every possible return type
 * correctly.
 * 
 * It converts string @val to the return type.
 * 
 * You probably don't want to call this function.
 * 
 * Returns: (transfer full) (array zero-terminated=1) (element-type GuestfsPV): an array of PV objects, or NULL on error
 */
GuestfsPV **
guestfs_session_internal_test_rstructlist (GuestfsSession *session, const gchar *val, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "internal_test_rstructlist");
    return NULL;
  }

  struct guestfs_lvm_pv_list *ret = guestfs_internal_test_rstructlist (g, val);
  if (ret == NULL) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return NULL;
  }

  GuestfsPV **l = g_malloc (sizeof (GuestfsPV*) * (ret->len + 1));
  gsize i;
  for (i = 0; i < ret->len; i++) {
    l[i] = g_slice_new0 (GuestfsPV);
    if (ret->val[i].pv_name) l[i]->pv_name = g_strdup (ret->val[i].pv_name);
    if (ret->val[i].pv_uuid) memcpy (l[i]->pv_uuid, ret->val[i].pv_uuid, sizeof (l[i]->pv_uuid));
    if (ret->val[i].pv_fmt) l[i]->pv_fmt = g_strdup (ret->val[i].pv_fmt);
    l[i]->pv_size = ret->val[i].pv_size;
    l[i]->dev_size = ret->val[i].dev_size;
    l[i]->pv_free = ret->val[i].pv_free;
    l[i]->pv_used = ret->val[i].pv_used;
    if (ret->val[i].pv_attr) l[i]->pv_attr = g_strdup (ret->val[i].pv_attr);
    l[i]->pv_pe_count = ret->val[i].pv_pe_count;
    l[i]->pv_pe_alloc_count = ret->val[i].pv_pe_alloc_count;
    if (ret->val[i].pv_tags) l[i]->pv_tags = g_strdup (ret->val[i].pv_tags);
    l[i]->pe_start = ret->val[i].pe_start;
    l[i]->pv_mda_count = ret->val[i].pv_mda_count;
    l[i]->pv_mda_free = ret->val[i].pv_mda_free;
  }
  guestfs_free_lvm_pv_list (ret);
  l[i] = NULL;
  return l;
}

/**
 * guestfs_session_internal_test_rstructlisterr:
 * @session: (transfer none): A GuestfsSession object
 * @err: A GError object to receive any generated errors
 *
 * internal test function - do not use
 *
 * This is an internal test function which is used to test whether the
 * automatically generated bindings can handle every possible return type
 * correctly.
 * 
 * This function always returns an error.
 * 
 * You probably don't want to call this function.
 * 
 * Returns: (transfer full) (array zero-terminated=1) (element-type GuestfsPV): an array of PV objects, or NULL on error
 */
GuestfsPV **
guestfs_session_internal_test_rstructlisterr (GuestfsSession *session, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "internal_test_rstructlisterr");
    return NULL;
  }

  struct guestfs_lvm_pv_list *ret = guestfs_internal_test_rstructlisterr (g);
  if (ret == NULL) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return NULL;
  }

  GuestfsPV **l = g_malloc (sizeof (GuestfsPV*) * (ret->len + 1));
  gsize i;
  for (i = 0; i < ret->len; i++) {
    l[i] = g_slice_new0 (GuestfsPV);
    if (ret->val[i].pv_name) l[i]->pv_name = g_strdup (ret->val[i].pv_name);
    if (ret->val[i].pv_uuid) memcpy (l[i]->pv_uuid, ret->val[i].pv_uuid, sizeof (l[i]->pv_uuid));
    if (ret->val[i].pv_fmt) l[i]->pv_fmt = g_strdup (ret->val[i].pv_fmt);
    l[i]->pv_size = ret->val[i].pv_size;
    l[i]->dev_size = ret->val[i].dev_size;
    l[i]->pv_free = ret->val[i].pv_free;
    l[i]->pv_used = ret->val[i].pv_used;
    if (ret->val[i].pv_attr) l[i]->pv_attr = g_strdup (ret->val[i].pv_attr);
    l[i]->pv_pe_count = ret->val[i].pv_pe_count;
    l[i]->pv_pe_alloc_count = ret->val[i].pv_pe_alloc_count;
    if (ret->val[i].pv_tags) l[i]->pv_tags = g_strdup (ret->val[i].pv_tags);
    l[i]->pe_start = ret->val[i].pe_start;
    l[i]->pv_mda_count = ret->val[i].pv_mda_count;
    l[i]->pv_mda_free = ret->val[i].pv_mda_free;
  }
  guestfs_free_lvm_pv_list (ret);
  l[i] = NULL;
  return l;
}

/**
 * guestfs_session_internal_test_set_output:
 * @session: (transfer none): A GuestfsSession object
 * @filename: (transfer none) (type utf8):
 * @err: A GError object to receive any generated errors
 *
 * internal test function - do not use
 *
 * This is an internal test function which is used to test whether the
 * automatically generated bindings can handle every possible parameter
 * type correctly.
 * 
 * It sets the output file used by guestfs_session_internal_test().
 * 
 * You probably don't want to call this function.
 * 
 * Returns: true on success, false on error
 */
gboolean
guestfs_session_internal_test_set_output (GuestfsSession *session, const gchar *filename, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "internal_test_set_output");
    return FALSE;
  }

  int ret = guestfs_internal_test_set_output (g, filename);
  if (ret == -1) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return FALSE;
  }

  return TRUE;
}

/**
 * guestfs_session_is_blockdev:
 * @session: (transfer none): A GuestfsSession object
 * @path: (transfer none) (type filename):
 * @optargs: (transfer none) (allow-none): a GuestfsIsBlockdev containing optional arguments
 * @err: A GError object to receive any generated errors
 *
 * test if block device
 *
 * This returns @true if and only if there is a block device with the given
 * @path name.
 * 
 * If the optional flag @followsymlinks is true, then a symlink (or chain
 * of symlinks) that ends with a block device also causes the function to
 * return true.
 * 
 * This call only looks at files within the guest filesystem. Libguestfs
 * partitions and block devices (eg. /dev/sda) cannot be used as the @path
 * parameter of this call.
 * 
 * See also guestfs_session_stat().
 * 
 * Returns: the returned value, or -1 on error
 * Since: 1.5.10
 */
gint8
guestfs_session_is_blockdev (GuestfsSession *session, const gchar *path, GuestfsIsBlockdev *optargs, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "is_blockdev");
    return -1;
  }

  struct guestfs_is_blockdev_opts_argv argv;
  struct guestfs_is_blockdev_opts_argv *argvp = NULL;

  if (optargs) {
    argv.bitmask = 0;

    GValue followsymlinks_v = {0, };
    g_value_init (&followsymlinks_v, GUESTFS_TYPE_TRISTATE);
    g_object_get_property (G_OBJECT (optargs), "followsymlinks", &followsymlinks_v);
    GuestfsTristate followsymlinks = g_value_get_enum (&followsymlinks_v);
    if (followsymlinks != GUESTFS_TRISTATE_NONE) {
      argv.bitmask |= GUESTFS_IS_BLOCKDEV_OPTS_FOLLOWSYMLINKS_BITMASK;
      argv.followsymlinks = followsymlinks;
    }
    argvp = &argv;
  }
  int ret = guestfs_is_blockdev_opts_argv (g, path, argvp);
  if (ret == -1) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return -1;
  }

  return ret;
}

/**
 * guestfs_session_is_busy:
 * @session: (transfer none): A GuestfsSession object
 * @err: A GError object to receive any generated errors
 *
 * is busy processing a command
 *
 * This always returns false. This function is deprecated with no
 * replacement. Do not use this function.
 * 
 * For more information on states, see guestfs(3).
 * 
 * Returns: the returned value, or -1 on error
 * Since: 1.0.2
 */
gint8
guestfs_session_is_busy (GuestfsSession *session, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "is_busy");
    return -1;
  }

  int ret = guestfs_is_busy (g);
  if (ret == -1) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return -1;
  }

  return ret;
}

/**
 * guestfs_session_is_chardev:
 * @session: (transfer none): A GuestfsSession object
 * @path: (transfer none) (type filename):
 * @optargs: (transfer none) (allow-none): a GuestfsIsChardev containing optional arguments
 * @err: A GError object to receive any generated errors
 *
 * test if character device
 *
 * This returns @true if and only if there is a character device with the
 * given @path name.
 * 
 * If the optional flag @followsymlinks is true, then a symlink (or chain
 * of symlinks) that ends with a chardev also causes the function to return
 * true.
 * 
 * See also guestfs_session_stat().
 * 
 * Returns: the returned value, or -1 on error
 * Since: 1.5.10
 */
gint8
guestfs_session_is_chardev (GuestfsSession *session, const gchar *path, GuestfsIsChardev *optargs, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "is_chardev");
    return -1;
  }

  struct guestfs_is_chardev_opts_argv argv;
  struct guestfs_is_chardev_opts_argv *argvp = NULL;

  if (optargs) {
    argv.bitmask = 0;

    GValue followsymlinks_v = {0, };
    g_value_init (&followsymlinks_v, GUESTFS_TYPE_TRISTATE);
    g_object_get_property (G_OBJECT (optargs), "followsymlinks", &followsymlinks_v);
    GuestfsTristate followsymlinks = g_value_get_enum (&followsymlinks_v);
    if (followsymlinks != GUESTFS_TRISTATE_NONE) {
      argv.bitmask |= GUESTFS_IS_CHARDEV_OPTS_FOLLOWSYMLINKS_BITMASK;
      argv.followsymlinks = followsymlinks;
    }
    argvp = &argv;
  }
  int ret = guestfs_is_chardev_opts_argv (g, path, argvp);
  if (ret == -1) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return -1;
  }

  return ret;
}

/**
 * guestfs_session_is_config:
 * @session: (transfer none): A GuestfsSession object
 * @err: A GError object to receive any generated errors
 *
 * is in configuration state
 *
 * This returns true iff this handle is being configured (in the @CONFIG
 * state).
 * 
 * For more information on states, see guestfs(3).
 * 
 * Returns: the returned value, or -1 on error
 * Since: 1.0.2
 */
gint8
guestfs_session_is_config (GuestfsSession *session, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "is_config");
    return -1;
  }

  int ret = guestfs_is_config (g);
  if (ret == -1) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return -1;
  }

  return ret;
}

/**
 * guestfs_session_is_dir:
 * @session: (transfer none): A GuestfsSession object
 * @path: (transfer none) (type filename):
 * @optargs: (transfer none) (allow-none): a GuestfsIsDir containing optional arguments
 * @err: A GError object to receive any generated errors
 *
 * test if a directory
 *
 * This returns @true if and only if there is a directory with the given
 * @path name. Note that it returns false for other objects like files.
 * 
 * If the optional flag @followsymlinks is true, then a symlink (or chain
 * of symlinks) that ends with a directory also causes the function to
 * return true.
 * 
 * See also guestfs_session_stat().
 * 
 * Returns: the returned value, or -1 on error
 * Since: 0.8
 */
gint8
guestfs_session_is_dir (GuestfsSession *session, const gchar *path, GuestfsIsDir *optargs, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "is_dir");
    return -1;
  }

  struct guestfs_is_dir_opts_argv argv;
  struct guestfs_is_dir_opts_argv *argvp = NULL;

  if (optargs) {
    argv.bitmask = 0;

    GValue followsymlinks_v = {0, };
    g_value_init (&followsymlinks_v, GUESTFS_TYPE_TRISTATE);
    g_object_get_property (G_OBJECT (optargs), "followsymlinks", &followsymlinks_v);
    GuestfsTristate followsymlinks = g_value_get_enum (&followsymlinks_v);
    if (followsymlinks != GUESTFS_TRISTATE_NONE) {
      argv.bitmask |= GUESTFS_IS_DIR_OPTS_FOLLOWSYMLINKS_BITMASK;
      argv.followsymlinks = followsymlinks;
    }
    argvp = &argv;
  }
  int ret = guestfs_is_dir_opts_argv (g, path, argvp);
  if (ret == -1) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return -1;
  }

  return ret;
}

/**
 * guestfs_session_is_fifo:
 * @session: (transfer none): A GuestfsSession object
 * @path: (transfer none) (type filename):
 * @optargs: (transfer none) (allow-none): a GuestfsIsFifo containing optional arguments
 * @err: A GError object to receive any generated errors
 *
 * test if FIFO (named pipe)
 *
 * This returns @true if and only if there is a FIFO (named pipe) with the
 * given @path name.
 * 
 * If the optional flag @followsymlinks is true, then a symlink (or chain
 * of symlinks) that ends with a FIFO also causes the function to return
 * true.
 * 
 * See also guestfs_session_stat().
 * 
 * Returns: the returned value, or -1 on error
 * Since: 1.5.10
 */
gint8
guestfs_session_is_fifo (GuestfsSession *session, const gchar *path, GuestfsIsFifo *optargs, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "is_fifo");
    return -1;
  }

  struct guestfs_is_fifo_opts_argv argv;
  struct guestfs_is_fifo_opts_argv *argvp = NULL;

  if (optargs) {
    argv.bitmask = 0;

    GValue followsymlinks_v = {0, };
    g_value_init (&followsymlinks_v, GUESTFS_TYPE_TRISTATE);
    g_object_get_property (G_OBJECT (optargs), "followsymlinks", &followsymlinks_v);
    GuestfsTristate followsymlinks = g_value_get_enum (&followsymlinks_v);
    if (followsymlinks != GUESTFS_TRISTATE_NONE) {
      argv.bitmask |= GUESTFS_IS_FIFO_OPTS_FOLLOWSYMLINKS_BITMASK;
      argv.followsymlinks = followsymlinks;
    }
    argvp = &argv;
  }
  int ret = guestfs_is_fifo_opts_argv (g, path, argvp);
  if (ret == -1) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return -1;
  }

  return ret;
}

/**
 * guestfs_session_is_file:
 * @session: (transfer none): A GuestfsSession object
 * @path: (transfer none) (type filename):
 * @optargs: (transfer none) (allow-none): a GuestfsIsFile containing optional arguments
 * @err: A GError object to receive any generated errors
 *
 * test if a regular file
 *
 * This returns @true if and only if there is a regular file with the given
 * @path name. Note that it returns false for other objects like
 * directories.
 * 
 * If the optional flag @followsymlinks is true, then a symlink (or chain
 * of symlinks) that ends with a file also causes the function to return
 * true.
 * 
 * See also guestfs_session_stat().
 * 
 * Returns: the returned value, or -1 on error
 * Since: 0.8
 */
gint8
guestfs_session_is_file (GuestfsSession *session, const gchar *path, GuestfsIsFile *optargs, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "is_file");
    return -1;
  }

  struct guestfs_is_file_opts_argv argv;
  struct guestfs_is_file_opts_argv *argvp = NULL;

  if (optargs) {
    argv.bitmask = 0;

    GValue followsymlinks_v = {0, };
    g_value_init (&followsymlinks_v, GUESTFS_TYPE_TRISTATE);
    g_object_get_property (G_OBJECT (optargs), "followsymlinks", &followsymlinks_v);
    GuestfsTristate followsymlinks = g_value_get_enum (&followsymlinks_v);
    if (followsymlinks != GUESTFS_TRISTATE_NONE) {
      argv.bitmask |= GUESTFS_IS_FILE_OPTS_FOLLOWSYMLINKS_BITMASK;
      argv.followsymlinks = followsymlinks;
    }
    argvp = &argv;
  }
  int ret = guestfs_is_file_opts_argv (g, path, argvp);
  if (ret == -1) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return -1;
  }

  return ret;
}

/**
 * guestfs_session_is_launching:
 * @session: (transfer none): A GuestfsSession object
 * @err: A GError object to receive any generated errors
 *
 * is launching subprocess
 *
 * This returns true iff this handle is launching the subprocess (in the
 * @LAUNCHING state).
 * 
 * For more information on states, see guestfs(3).
 * 
 * Returns: the returned value, or -1 on error
 * Since: 1.0.2
 */
gint8
guestfs_session_is_launching (GuestfsSession *session, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "is_launching");
    return -1;
  }

  int ret = guestfs_is_launching (g);
  if (ret == -1) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return -1;
  }

  return ret;
}

/**
 * guestfs_session_is_lv:
 * @session: (transfer none): A GuestfsSession object
 * @device: (transfer none) (type filename):
 * @err: A GError object to receive any generated errors
 *
 * test if device is a logical volume
 *
 * This command tests whether @device is a logical volume, and returns true
 * iff this is the case.
 * 
 * Returns: the returned value, or -1 on error
 * Since: 1.5.3
 */
gint8
guestfs_session_is_lv (GuestfsSession *session, const gchar *device, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "is_lv");
    return -1;
  }

  int ret = guestfs_is_lv (g, device);
  if (ret == -1) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return -1;
  }

  return ret;
}

/**
 * guestfs_session_is_ready:
 * @session: (transfer none): A GuestfsSession object
 * @err: A GError object to receive any generated errors
 *
 * is ready to accept commands
 *
 * This returns true iff this handle is ready to accept commands (in the
 * @READY state).
 * 
 * For more information on states, see guestfs(3).
 * 
 * Returns: the returned value, or -1 on error
 * Since: 1.0.2
 */
gint8
guestfs_session_is_ready (GuestfsSession *session, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "is_ready");
    return -1;
  }

  int ret = guestfs_is_ready (g);
  if (ret == -1) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return -1;
  }

  return ret;
}

/**
 * guestfs_session_is_socket:
 * @session: (transfer none): A GuestfsSession object
 * @path: (transfer none) (type filename):
 * @optargs: (transfer none) (allow-none): a GuestfsIsSocket containing optional arguments
 * @err: A GError object to receive any generated errors
 *
 * test if socket
 *
 * This returns @true if and only if there is a Unix domain socket with the
 * given @path name.
 * 
 * If the optional flag @followsymlinks is true, then a symlink (or chain
 * of symlinks) that ends with a socket also causes the function to return
 * true.
 * 
 * See also guestfs_session_stat().
 * 
 * Returns: the returned value, or -1 on error
 * Since: 1.5.10
 */
gint8
guestfs_session_is_socket (GuestfsSession *session, const gchar *path, GuestfsIsSocket *optargs, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "is_socket");
    return -1;
  }

  struct guestfs_is_socket_opts_argv argv;
  struct guestfs_is_socket_opts_argv *argvp = NULL;

  if (optargs) {
    argv.bitmask = 0;

    GValue followsymlinks_v = {0, };
    g_value_init (&followsymlinks_v, GUESTFS_TYPE_TRISTATE);
    g_object_get_property (G_OBJECT (optargs), "followsymlinks", &followsymlinks_v);
    GuestfsTristate followsymlinks = g_value_get_enum (&followsymlinks_v);
    if (followsymlinks != GUESTFS_TRISTATE_NONE) {
      argv.bitmask |= GUESTFS_IS_SOCKET_OPTS_FOLLOWSYMLINKS_BITMASK;
      argv.followsymlinks = followsymlinks;
    }
    argvp = &argv;
  }
  int ret = guestfs_is_socket_opts_argv (g, path, argvp);
  if (ret == -1) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return -1;
  }

  return ret;
}

/**
 * guestfs_session_is_symlink:
 * @session: (transfer none): A GuestfsSession object
 * @path: (transfer none) (type filename):
 * @err: A GError object to receive any generated errors
 *
 * test if symbolic link
 *
 * This returns @true if and only if there is a symbolic link with the
 * given @path name.
 * 
 * See also guestfs_session_stat().
 * 
 * Returns: the returned value, or -1 on error
 * Since: 1.5.10
 */
gint8
guestfs_session_is_symlink (GuestfsSession *session, const gchar *path, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "is_symlink");
    return -1;
  }

  int ret = guestfs_is_symlink (g, path);
  if (ret == -1) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return -1;
  }

  return ret;
}

/**
 * guestfs_session_is_whole_device:
 * @session: (transfer none): A GuestfsSession object
 * @device: (transfer none) (type filename):
 * @err: A GError object to receive any generated errors
 *
 * test if a device is a whole device
 *
 * This returns @true if and only if @device refers to a whole block
 * device. That is, not a partition or a logical device.
 * 
 * Returns: the returned value, or -1 on error
 * Since: 1.21.9
 */
gint8
guestfs_session_is_whole_device (GuestfsSession *session, const gchar *device, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "is_whole_device");
    return -1;
  }

  int ret = guestfs_is_whole_device (g, device);
  if (ret == -1) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return -1;
  }

  return ret;
}

/**
 * guestfs_session_is_zero:
 * @session: (transfer none): A GuestfsSession object
 * @path: (transfer none) (type filename):
 * @err: A GError object to receive any generated errors
 *
 * test if a file contains all zero bytes
 *
 * This returns true iff the file exists and the file is empty or it
 * contains all zero bytes.
 * 
 * Returns: the returned value, or -1 on error
 * Since: 1.11.8
 */
gint8
guestfs_session_is_zero (GuestfsSession *session, const gchar *path, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "is_zero");
    return -1;
  }

  int ret = guestfs_is_zero (g, path);
  if (ret == -1) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return -1;
  }

  return ret;
}

/**
 * guestfs_session_is_zero_device:
 * @session: (transfer none): A GuestfsSession object
 * @device: (transfer none) (type filename):
 * @err: A GError object to receive any generated errors
 *
 * test if a device contains all zero bytes
 *
 * This returns true iff the device exists and contains all zero bytes.
 * 
 * Note that for large devices this can take a long time to run.
 * 
 * Returns: the returned value, or -1 on error
 * Since: 1.11.8
 */
gint8
guestfs_session_is_zero_device (GuestfsSession *session, const gchar *device, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "is_zero_device");
    return -1;
  }

  int ret = guestfs_is_zero_device (g, device);
  if (ret == -1) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return -1;
  }

  return ret;
}

/**
 * guestfs_session_isoinfo:
 * @session: (transfer none): A GuestfsSession object
 * @isofile: (transfer none) (type filename):
 * @err: A GError object to receive any generated errors
 *
 * get ISO information from primary volume descriptor of ISO file
 *
 * This is the same as guestfs_session_isoinfo_device() except that it
 * works for an ISO file located inside some other mounted filesystem. Note
 * that in the common case where you have added an ISO file as a libguestfs
 * device, you would *not* call this. Instead you would call
 * guestfs_session_isoinfo_device().
 * 
 * Returns: (transfer full): a ISOInfo object, or NULL on error
 * Since: 1.17.19
 */
GuestfsISOInfo *
guestfs_session_isoinfo (GuestfsSession *session, const gchar *isofile, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "isoinfo");
    return NULL;
  }

  struct guestfs_isoinfo *ret = guestfs_isoinfo (g, isofile);
  if (ret == NULL) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return NULL;
  }

  GuestfsISOInfo *s = g_slice_new0 (GuestfsISOInfo);
  if (ret->iso_system_id) s->iso_system_id = g_strdup (ret->iso_system_id);
  if (ret->iso_volume_id) s->iso_volume_id = g_strdup (ret->iso_volume_id);
  s->iso_volume_space_size = ret->iso_volume_space_size;
  s->iso_volume_set_size = ret->iso_volume_set_size;
  s->iso_volume_sequence_number = ret->iso_volume_sequence_number;
  s->iso_logical_block_size = ret->iso_logical_block_size;
  if (ret->iso_volume_set_id) s->iso_volume_set_id = g_strdup (ret->iso_volume_set_id);
  if (ret->iso_publisher_id) s->iso_publisher_id = g_strdup (ret->iso_publisher_id);
  if (ret->iso_data_preparer_id) s->iso_data_preparer_id = g_strdup (ret->iso_data_preparer_id);
  if (ret->iso_application_id) s->iso_application_id = g_strdup (ret->iso_application_id);
  if (ret->iso_copyright_file_id) s->iso_copyright_file_id = g_strdup (ret->iso_copyright_file_id);
  if (ret->iso_abstract_file_id) s->iso_abstract_file_id = g_strdup (ret->iso_abstract_file_id);
  if (ret->iso_bibliographic_file_id) s->iso_bibliographic_file_id = g_strdup (ret->iso_bibliographic_file_id);
  s->iso_volume_creation_t = ret->iso_volume_creation_t;
  s->iso_volume_modification_t = ret->iso_volume_modification_t;
  s->iso_volume_expiration_t = ret->iso_volume_expiration_t;
  s->iso_volume_effective_t = ret->iso_volume_effective_t;
  guestfs_free_isoinfo (ret);
  return s;
}

/**
 * guestfs_session_isoinfo_device:
 * @session: (transfer none): A GuestfsSession object
 * @device: (transfer none) (type filename):
 * @err: A GError object to receive any generated errors
 *
 * get ISO information from primary volume descriptor of device
 *
 * @device is an ISO device. This returns a struct of information read from
 * the primary volume descriptor (the ISO equivalent of the superblock) of
 * the device.
 * 
 * Usually it is more efficient to use the isoinfo(1) command with the *-d*
 * option on the host to analyze ISO files, instead of going through
 * libguestfs.
 * 
 * For information on the primary volume descriptor fields, see <ulink
 * url='http://wiki.osdev.org/ISO_9660#The_Primary_Volume_Descriptor'>
 * http://wiki.osdev.org/ISO_9660#The_Primary_Volume_Descriptor </ulink>
 * 
 * Returns: (transfer full): a ISOInfo object, or NULL on error
 * Since: 1.17.19
 */
GuestfsISOInfo *
guestfs_session_isoinfo_device (GuestfsSession *session, const gchar *device, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "isoinfo_device");
    return NULL;
  }

  struct guestfs_isoinfo *ret = guestfs_isoinfo_device (g, device);
  if (ret == NULL) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return NULL;
  }

  GuestfsISOInfo *s = g_slice_new0 (GuestfsISOInfo);
  if (ret->iso_system_id) s->iso_system_id = g_strdup (ret->iso_system_id);
  if (ret->iso_volume_id) s->iso_volume_id = g_strdup (ret->iso_volume_id);
  s->iso_volume_space_size = ret->iso_volume_space_size;
  s->iso_volume_set_size = ret->iso_volume_set_size;
  s->iso_volume_sequence_number = ret->iso_volume_sequence_number;
  s->iso_logical_block_size = ret->iso_logical_block_size;
  if (ret->iso_volume_set_id) s->iso_volume_set_id = g_strdup (ret->iso_volume_set_id);
  if (ret->iso_publisher_id) s->iso_publisher_id = g_strdup (ret->iso_publisher_id);
  if (ret->iso_data_preparer_id) s->iso_data_preparer_id = g_strdup (ret->iso_data_preparer_id);
  if (ret->iso_application_id) s->iso_application_id = g_strdup (ret->iso_application_id);
  if (ret->iso_copyright_file_id) s->iso_copyright_file_id = g_strdup (ret->iso_copyright_file_id);
  if (ret->iso_abstract_file_id) s->iso_abstract_file_id = g_strdup (ret->iso_abstract_file_id);
  if (ret->iso_bibliographic_file_id) s->iso_bibliographic_file_id = g_strdup (ret->iso_bibliographic_file_id);
  s->iso_volume_creation_t = ret->iso_volume_creation_t;
  s->iso_volume_modification_t = ret->iso_volume_modification_t;
  s->iso_volume_expiration_t = ret->iso_volume_expiration_t;
  s->iso_volume_effective_t = ret->iso_volume_effective_t;
  guestfs_free_isoinfo (ret);
  return s;
}

/**
 * guestfs_session_journal_close:
 * @session: (transfer none): A GuestfsSession object
 * @err: A GError object to receive any generated errors
 *
 * close the systemd journal
 *
 * Close the journal handle.
 * 
 * Returns: true on success, false on error
 * Since: 1.23.11
 */
gboolean
guestfs_session_journal_close (GuestfsSession *session, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "journal_close");
    return FALSE;
  }

  int ret = guestfs_journal_close (g);
  if (ret == -1) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return FALSE;
  }

  return TRUE;
}

/**
 * guestfs_session_journal_get:
 * @session: (transfer none): A GuestfsSession object
 * @err: A GError object to receive any generated errors
 *
 * read the current journal entry
 *
 * Read the current journal entry. This returns all the fields in the
 * journal as a set of "(attrname, attrval)" pairs. The @attrname is the
 * field name (a string).
 * 
 * The @attrval is the field value (a binary blob, often but not always a
 * string). Please note that @attrval is a byte array, *not* a
 * \0-terminated C string.
 * 
 * The length of data may be truncated to the data threshold (see:
 * guestfs_session_journal_set_data_threshold(),
 * guestfs_session_journal_get_data_threshold()).
 * 
 * If you set the data threshold to unlimited (@0) then this call can read
 * a journal entry of any size, ie. it is not limited by the libguestfs
 * protocol.
 * 
 * Returns: (transfer full) (array zero-terminated=1) (element-type GuestfsXAttr): an array of XAttr objects, or NULL on error
 * Since: 1.23.11
 */
GuestfsXAttr **
guestfs_session_journal_get (GuestfsSession *session, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "journal_get");
    return NULL;
  }

  struct guestfs_xattr_list *ret = guestfs_journal_get (g);
  if (ret == NULL) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return NULL;
  }

  GuestfsXAttr **l = g_malloc (sizeof (GuestfsXAttr*) * (ret->len + 1));
  gsize i;
  for (i = 0; i < ret->len; i++) {
    l[i] = g_slice_new0 (GuestfsXAttr);
    if (ret->val[i].attrname) l[i]->attrname = g_strdup (ret->val[i].attrname);
    if (ret->val[i].attrval) {
      l[i]->attrval = g_byte_array_sized_new (ret->val[i].attrval_len);
      g_byte_array_append (l[i]->attrval, (const guint8 *) ret->val[i].attrval, ret->val[i].attrval_len);
    }
  }
  guestfs_free_xattr_list (ret);
  l[i] = NULL;
  return l;
}

/**
 * guestfs_session_journal_get_data_threshold:
 * @session: (transfer none): A GuestfsSession object
 * @err: A GError object to receive any generated errors
 *
 * get the data threshold for reading journal entries
 *
 * Get the current data threshold for reading journal entries. This is a
 * hint to the journal that it may truncate data fields to this size when
 * reading them (note also that it may not truncate them). If this returns
 * @0, then the threshold is unlimited.
 * 
 * See also guestfs_session_journal_set_data_threshold().
 * 
 * Returns: the returned value, or -1 on error
 * Since: 1.23.11
 */
gint64
guestfs_session_journal_get_data_threshold (GuestfsSession *session, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "journal_get_data_threshold");
    return -1;
  }

  int64_t ret = guestfs_journal_get_data_threshold (g);
  if (ret == -1) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return -1;
  }

  return ret;
}

/**
 * guestfs_session_journal_get_realtime_usec:
 * @session: (transfer none): A GuestfsSession object
 * @err: A GError object to receive any generated errors
 *
 * get the timestamp of the current journal entry
 *
 * Get the realtime (wallclock) timestamp of the current journal entry.
 * 
 * Returns: the returned value, or -1 on error
 * Since: 1.27.18
 */
gint64
guestfs_session_journal_get_realtime_usec (GuestfsSession *session, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "journal_get_realtime_usec");
    return -1;
  }

  int64_t ret = guestfs_journal_get_realtime_usec (g);
  if (ret == -1) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return -1;
  }

  return ret;
}

/**
 * guestfs_session_journal_next:
 * @session: (transfer none): A GuestfsSession object
 * @err: A GError object to receive any generated errors
 *
 * move to the next journal entry
 *
 * Move to the next journal entry. You have to call this at least once
 * after opening the handle before you are able to read data.
 * 
 * The returned boolean tells you if there are any more journal records to
 * read. @true means you can read the next record (eg. using
 * guestfs_session_journal_get()), and @false means you have reached the
 * end of the journal.
 * 
 * Returns: the returned value, or -1 on error
 * Since: 1.23.11
 */
gint8
guestfs_session_journal_next (GuestfsSession *session, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "journal_next");
    return -1;
  }

  int ret = guestfs_journal_next (g);
  if (ret == -1) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return -1;
  }

  return ret;
}

/**
 * guestfs_session_journal_open:
 * @session: (transfer none): A GuestfsSession object
 * @directory: (transfer none) (type filename):
 * @err: A GError object to receive any generated errors
 *
 * open the systemd journal
 *
 * Open the systemd journal located in directory. Any previously opened
 * journal handle is closed.
 * 
 * The contents of the journal can be read using
 * guestfs_session_journal_next() and guestfs_session_journal_get().
 * 
 * After you have finished using the journal, you should close the handle
 * by calling guestfs_session_journal_close().
 * 
 * Returns: true on success, false on error
 * Since: 1.23.11
 */
gboolean
guestfs_session_journal_open (GuestfsSession *session, const gchar *directory, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "journal_open");
    return FALSE;
  }

  int ret = guestfs_journal_open (g, directory);
  if (ret == -1) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return FALSE;
  }

  return TRUE;
}

/**
 * guestfs_session_journal_set_data_threshold:
 * @session: (transfer none): A GuestfsSession object
 * @threshold: (type gint64):
 * @err: A GError object to receive any generated errors
 *
 * set the data threshold for reading journal entries
 *
 * Set the data threshold for reading journal entries. This is a hint to
 * the journal that it may truncate data fields to this size when reading
 * them (note also that it may not truncate them). If you set this to @0,
 * then the threshold is unlimited.
 * 
 * See also guestfs_session_journal_get_data_threshold().
 * 
 * Returns: true on success, false on error
 * Since: 1.23.11
 */
gboolean
guestfs_session_journal_set_data_threshold (GuestfsSession *session, gint64 threshold, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "journal_set_data_threshold");
    return FALSE;
  }

  int ret = guestfs_journal_set_data_threshold (g, threshold);
  if (ret == -1) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return FALSE;
  }

  return TRUE;
}

/**
 * guestfs_session_journal_skip:
 * @session: (transfer none): A GuestfsSession object
 * @skip: (type gint64):
 * @err: A GError object to receive any generated errors
 *
 * skip forwards or backwards in the journal
 *
 * Skip forwards ("skip &ge; 0") or backwards ("skip &lt; 0") in the
 * journal.
 * 
 * The number of entries actually skipped is returned (note "rskip &ge;
 * 0"). If this is not the same as the absolute value of the skip parameter
 * ("|skip|") you passed in then it means you have reached the end or the
 * start of the journal.
 * 
 * Returns: the returned value, or -1 on error
 * Since: 1.23.11
 */
gint64
guestfs_session_journal_skip (GuestfsSession *session, gint64 skip, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "journal_skip");
    return -1;
  }

  int64_t ret = guestfs_journal_skip (g, skip);
  if (ret == -1) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return -1;
  }

  return ret;
}

/**
 * guestfs_session_kill_subprocess:
 * @session: (transfer none): A GuestfsSession object
 * @err: A GError object to receive any generated errors
 *
 * kill the hypervisor
 *
 * This kills the hypervisor.
 * 
 * Do not call this. See: guestfs_session_shutdown() instead.
 * 
 * Returns: true on success, false on error
 * Deprecated: In new code, use guestfs_session_shutdown() instead
 * Since: 0.3
 */
gboolean
guestfs_session_kill_subprocess (GuestfsSession *session, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "kill_subprocess");
    return FALSE;
  }

  int ret = guestfs_kill_subprocess (g);
  if (ret == -1) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return FALSE;
  }

  return TRUE;
}

/**
 * guestfs_session_launch:
 * @session: (transfer none): A GuestfsSession object
 * @err: A GError object to receive any generated errors
 *
 * launch the backend
 *
 * You should call this after configuring the handle (eg. adding drives)
 * but before performing any actions.
 * 
 * Do not call guestfs_session_launch() twice on the same handle. Although
 * it will not give an error (for historical reasons), the precise
 * behaviour when you do this is not well defined. Handles are very cheap
 * to create, so create a new one for each launch.
 * 
 * Returns: true on success, false on error
 * Since: 0.3
 */
gboolean
guestfs_session_launch (GuestfsSession *session, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "launch");
    return FALSE;
  }

  int ret = guestfs_launch (g);
  if (ret == -1) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return FALSE;
  }

  return TRUE;
}

/**
 * guestfs_session_lchown:
 * @session: (transfer none): A GuestfsSession object
 * @owner: (type gint32):
 * @group: (type gint32):
 * @path: (transfer none) (type filename):
 * @err: A GError object to receive any generated errors
 *
 * change file owner and group
 *
 * Change the file owner to @owner and group to @group. This is like
 * guestfs_session_chown() but if @path is a symlink then the link itself
 * is changed, not the target.
 * 
 * Only numeric uid and gid are supported. If you want to use names, you
 * will need to locate and parse the password file yourself (Augeas support
 * makes this relatively easy).
 * 
 * Returns: true on success, false on error
 * Since: 1.0.77
 */
gboolean
guestfs_session_lchown (GuestfsSession *session, gint32 owner, gint32 group, const gchar *path, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "lchown");
    return FALSE;
  }

  int ret = guestfs_lchown (g, owner, group, path);
  if (ret == -1) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return FALSE;
  }

  return TRUE;
}

/**
 * guestfs_session_ldmtool_create_all:
 * @session: (transfer none): A GuestfsSession object
 * @err: A GError object to receive any generated errors
 *
 * scan and create Windows dynamic disk volumes
 *
 * This function scans all block devices looking for Windows dynamic disk
 * volumes and partitions, and creates devices for any that were found.
 * 
 * Call guestfs_session_list_ldm_volumes() and
 * guestfs_session_list_ldm_partitions() to return all devices.
 * 
 * Note that you don't normally need to call this explicitly, since it is
 * done automatically at guestfs_session_launch() time. However you might
 * want to call this function if you have hotplugged disks or have just
 * created a Windows dynamic disk.
 * 
 * Returns: true on success, false on error
 * Since: 1.20.0
 */
gboolean
guestfs_session_ldmtool_create_all (GuestfsSession *session, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "ldmtool_create_all");
    return FALSE;
  }

  int ret = guestfs_ldmtool_create_all (g);
  if (ret == -1) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return FALSE;
  }

  return TRUE;
}

/**
 * guestfs_session_ldmtool_diskgroup_disks:
 * @session: (transfer none): A GuestfsSession object
 * @diskgroup: (transfer none) (type utf8):
 * @err: A GError object to receive any generated errors
 *
 * return the disks in a Windows dynamic disk group
 *
 * Return the disks in a Windows dynamic disk group. The @diskgroup
 * parameter should be the GUID of a disk group, one element from the list
 * returned by guestfs_session_ldmtool_scan().
 * 
 * Returns: (transfer full) (array zero-terminated=1) (element-type utf8): an array of returned strings, or NULL on error
 * Since: 1.20.0
 */
gchar **
guestfs_session_ldmtool_diskgroup_disks (GuestfsSession *session, const gchar *diskgroup, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "ldmtool_diskgroup_disks");
    return NULL;
  }

  char **ret = guestfs_ldmtool_diskgroup_disks (g, diskgroup);
  if (ret == NULL) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return NULL;
  }

  return ret;
}

/**
 * guestfs_session_ldmtool_diskgroup_name:
 * @session: (transfer none): A GuestfsSession object
 * @diskgroup: (transfer none) (type utf8):
 * @err: A GError object to receive any generated errors
 *
 * return the name of a Windows dynamic disk group
 *
 * Return the name of a Windows dynamic disk group. The @diskgroup
 * parameter should be the GUID of a disk group, one element from the list
 * returned by guestfs_session_ldmtool_scan().
 * 
 * Returns: (transfer full): the returned string, or NULL on error
 * Since: 1.20.0
 */
gchar *
guestfs_session_ldmtool_diskgroup_name (GuestfsSession *session, const gchar *diskgroup, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "ldmtool_diskgroup_name");
    return NULL;
  }

  char *ret = guestfs_ldmtool_diskgroup_name (g, diskgroup);
  if (ret == NULL) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return NULL;
  }

  return ret;
}

/**
 * guestfs_session_ldmtool_diskgroup_volumes:
 * @session: (transfer none): A GuestfsSession object
 * @diskgroup: (transfer none) (type utf8):
 * @err: A GError object to receive any generated errors
 *
 * return the volumes in a Windows dynamic disk group
 *
 * Return the volumes in a Windows dynamic disk group. The @diskgroup
 * parameter should be the GUID of a disk group, one element from the list
 * returned by guestfs_session_ldmtool_scan().
 * 
 * Returns: (transfer full) (array zero-terminated=1) (element-type utf8): an array of returned strings, or NULL on error
 * Since: 1.20.0
 */
gchar **
guestfs_session_ldmtool_diskgroup_volumes (GuestfsSession *session, const gchar *diskgroup, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "ldmtool_diskgroup_volumes");
    return NULL;
  }

  char **ret = guestfs_ldmtool_diskgroup_volumes (g, diskgroup);
  if (ret == NULL) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return NULL;
  }

  return ret;
}

/**
 * guestfs_session_ldmtool_remove_all:
 * @session: (transfer none): A GuestfsSession object
 * @err: A GError object to receive any generated errors
 *
 * remove all Windows dynamic disk volumes
 *
 * This is essentially the opposite of
 * guestfs_session_ldmtool_create_all(). It removes the device mapper
 * mappings for all Windows dynamic disk volumes
 * 
 * Returns: true on success, false on error
 * Since: 1.20.0
 */
gboolean
guestfs_session_ldmtool_remove_all (GuestfsSession *session, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "ldmtool_remove_all");
    return FALSE;
  }

  int ret = guestfs_ldmtool_remove_all (g);
  if (ret == -1) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return FALSE;
  }

  return TRUE;
}

/**
 * guestfs_session_ldmtool_scan:
 * @session: (transfer none): A GuestfsSession object
 * @err: A GError object to receive any generated errors
 *
 * scan for Windows dynamic disks
 *
 * This function scans for Windows dynamic disks. It returns a list of
 * identifiers (GUIDs) for all disk groups that were found. These
 * identifiers can be passed to other "guestfs_ldmtool_*" functions.
 * 
 * This function scans all block devices. To scan a subset of block
 * devices, call guestfs_session_ldmtool_scan_devices() instead.
 * 
 * Returns: (transfer full) (array zero-terminated=1) (element-type utf8): an array of returned strings, or NULL on error
 * Since: 1.20.0
 */
gchar **
guestfs_session_ldmtool_scan (GuestfsSession *session, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "ldmtool_scan");
    return NULL;
  }

  char **ret = guestfs_ldmtool_scan (g);
  if (ret == NULL) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return NULL;
  }

  return ret;
}

/**
 * guestfs_session_ldmtool_scan_devices:
 * @session: (transfer none): A GuestfsSession object
 * @devices: (transfer none) (array zero-terminated=1) (element-type filename): an array of strings
 * @err: A GError object to receive any generated errors
 *
 * scan for Windows dynamic disks
 *
 * This function scans for Windows dynamic disks. It returns a list of
 * identifiers (GUIDs) for all disk groups that were found. These
 * identifiers can be passed to other "guestfs_ldmtool_*" functions.
 * 
 * The parameter @devices is a list of block devices which are scanned. If
 * this list is empty, all block devices are scanned.
 * 
 * Returns: (transfer full) (array zero-terminated=1) (element-type utf8): an array of returned strings, or NULL on error
 * Since: 1.20.0
 */
gchar **
guestfs_session_ldmtool_scan_devices (GuestfsSession *session, gchar *const *devices, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "ldmtool_scan_devices");
    return NULL;
  }

  char **ret = guestfs_ldmtool_scan_devices (g, devices);
  if (ret == NULL) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return NULL;
  }

  return ret;
}

/**
 * guestfs_session_ldmtool_volume_hint:
 * @session: (transfer none): A GuestfsSession object
 * @diskgroup: (transfer none) (type utf8):
 * @volume: (transfer none) (type utf8):
 * @err: A GError object to receive any generated errors
 *
 * return the hint field of a Windows dynamic disk volume
 *
 * Return the hint field of the volume named @volume in the disk group with
 * GUID @diskgroup. This may not be defined, in which case the empty string
 * is returned. The hint field is often, though not always, the name of a
 * Windows drive, eg. "E:".
 * 
 * Returns: (transfer full): the returned string, or NULL on error
 * Since: 1.20.0
 */
gchar *
guestfs_session_ldmtool_volume_hint (GuestfsSession *session, const gchar *diskgroup, const gchar *volume, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "ldmtool_volume_hint");
    return NULL;
  }

  char *ret = guestfs_ldmtool_volume_hint (g, diskgroup, volume);
  if (ret == NULL) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return NULL;
  }

  return ret;
}

/**
 * guestfs_session_ldmtool_volume_partitions:
 * @session: (transfer none): A GuestfsSession object
 * @diskgroup: (transfer none) (type utf8):
 * @volume: (transfer none) (type utf8):
 * @err: A GError object to receive any generated errors
 *
 * return the partitions in a Windows dynamic disk volume
 *
 * Return the list of partitions in the volume named @volume in the disk
 * group with GUID @diskgroup.
 * 
 * Returns: (transfer full) (array zero-terminated=1) (element-type utf8): an array of returned strings, or NULL on error
 * Since: 1.20.0
 */
gchar **
guestfs_session_ldmtool_volume_partitions (GuestfsSession *session, const gchar *diskgroup, const gchar *volume, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "ldmtool_volume_partitions");
    return NULL;
  }

  char **ret = guestfs_ldmtool_volume_partitions (g, diskgroup, volume);
  if (ret == NULL) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return NULL;
  }

  return ret;
}

/**
 * guestfs_session_ldmtool_volume_type:
 * @session: (transfer none): A GuestfsSession object
 * @diskgroup: (transfer none) (type utf8):
 * @volume: (transfer none) (type utf8):
 * @err: A GError object to receive any generated errors
 *
 * return the type of a Windows dynamic disk volume
 *
 * Return the type of the volume named @volume in the disk group with GUID
 * @diskgroup.
 * 
 * Possible volume types that can be returned here include: @simple,
 * @spanned, @striped, @mirrored, @raid5. Other types may also be returned.
 * 
 * Returns: (transfer full): the returned string, or NULL on error
 * Since: 1.20.0
 */
gchar *
guestfs_session_ldmtool_volume_type (GuestfsSession *session, const gchar *diskgroup, const gchar *volume, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "ldmtool_volume_type");
    return NULL;
  }

  char *ret = guestfs_ldmtool_volume_type (g, diskgroup, volume);
  if (ret == NULL) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return NULL;
  }

  return ret;
}

/**
 * guestfs_session_lgetxattr:
 * @session: (transfer none): A GuestfsSession object
 * @path: (transfer none) (type filename):
 * @name: (transfer none) (type utf8):
 * @size_r: The size of the returned buffer, in bytes
 * @err: A GError object to receive any generated errors
 *
 * get a single extended attribute
 *
 * Get a single extended attribute from file @path named @name. If @path is
 * a symlink, then this call returns an extended attribute from the
 * symlink.
 * 
 * Normally it is better to get all extended attributes from a file in one
 * go by calling guestfs_session_getxattrs(). However some Linux filesystem
 * implementations are buggy and do not provide a way to list out
 * attributes. For these filesystems (notably ntfs-3g) you have to know the
 * names of the extended attributes you want in advance and call this
 * function.
 * 
 * Extended attribute values are blobs of binary data. If there is no
 * extended attribute named @name, this returns an error.
 * 
 * See also: guestfs_session_lgetxattrs(), guestfs_session_getxattr(),
 * attr(5).
 * 
 * Returns: (transfer full) (array length=size_r) (element-type guint8): an array of binary data, or NULL on error
 * Since: 1.7.24
 */
guint8 *
guestfs_session_lgetxattr (GuestfsSession *session, const gchar *path, const gchar *name, gsize *size_r, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "lgetxattr");
    return NULL;
  }

  char *ret = guestfs_lgetxattr (g, path, name, size_r);
  if (ret == NULL) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return NULL;
  }

  return (guint8 *) ret;
}

/**
 * guestfs_session_lgetxattrs:
 * @session: (transfer none): A GuestfsSession object
 * @path: (transfer none) (type filename):
 * @err: A GError object to receive any generated errors
 *
 * list extended attributes of a file or directory
 *
 * This is the same as guestfs_session_getxattrs(), but if @path is a
 * symbolic link, then it returns the extended attributes of the link
 * itself.
 * 
 * Returns: (transfer full) (array zero-terminated=1) (element-type GuestfsXAttr): an array of XAttr objects, or NULL on error
 * Since: 1.0.59
 */
GuestfsXAttr **
guestfs_session_lgetxattrs (GuestfsSession *session, const gchar *path, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "lgetxattrs");
    return NULL;
  }

  struct guestfs_xattr_list *ret = guestfs_lgetxattrs (g, path);
  if (ret == NULL) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return NULL;
  }

  GuestfsXAttr **l = g_malloc (sizeof (GuestfsXAttr*) * (ret->len + 1));
  gsize i;
  for (i = 0; i < ret->len; i++) {
    l[i] = g_slice_new0 (GuestfsXAttr);
    if (ret->val[i].attrname) l[i]->attrname = g_strdup (ret->val[i].attrname);
    if (ret->val[i].attrval) {
      l[i]->attrval = g_byte_array_sized_new (ret->val[i].attrval_len);
      g_byte_array_append (l[i]->attrval, (const guint8 *) ret->val[i].attrval, ret->val[i].attrval_len);
    }
  }
  guestfs_free_xattr_list (ret);
  l[i] = NULL;
  return l;
}

/**
 * guestfs_session_list_9p:
 * @session: (transfer none): A GuestfsSession object
 * @err: A GError object to receive any generated errors
 *
 * list 9p filesystems
 *
 * List all 9p filesystems attached to the guest. A list of mount tags is
 * returned.
 * 
 * Returns: (transfer full) (array zero-terminated=1) (element-type utf8): an array of returned strings, or NULL on error
 * Since: 1.11.12
 */
gchar **
guestfs_session_list_9p (GuestfsSession *session, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "list_9p");
    return NULL;
  }

  char **ret = guestfs_list_9p (g);
  if (ret == NULL) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return NULL;
  }

  return ret;
}

/**
 * guestfs_session_list_devices:
 * @session: (transfer none): A GuestfsSession object
 * @err: A GError object to receive any generated errors
 *
 * list the block devices
 *
 * List all the block devices.
 * 
 * The full block device names are returned, eg. /dev/sda.
 * 
 * See also guestfs_session_list_filesystems().
 * 
 * Returns: (transfer full) (array zero-terminated=1) (element-type utf8): an array of returned strings, or NULL on error
 * Since: 0.4
 */
gchar **
guestfs_session_list_devices (GuestfsSession *session, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "list_devices");
    return NULL;
  }

  char **ret = guestfs_list_devices (g);
  if (ret == NULL) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return NULL;
  }

  return ret;
}

/**
 * guestfs_session_list_disk_labels:
 * @session: (transfer none): A GuestfsSession object
 * @err: A GError object to receive any generated errors
 *
 * mapping of disk labels to devices
 *
 * If you add drives using the optional @label parameter of
 * guestfs_session_add_drive_opts(), you can use this call to map between
 * disk labels, and raw block device and partition names (like /dev/sda and
 * /dev/sda1).
 * 
 * This returns a hashtable, where keys are the disk labels (*without* the
 * /dev/disk/guestfs prefix), and the values are the full raw block device
 * and partition names (eg. /dev/sda and /dev/sda1).
 * 
 * Returns: (transfer full) (element-type utf8 utf8): a GHashTable of results, or NULL on error
 * Since: 1.19.49
 */
GHashTable *
guestfs_session_list_disk_labels (GuestfsSession *session, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "list_disk_labels");
    return NULL;
  }

  char **ret = guestfs_list_disk_labels (g);
  if (ret == NULL) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return NULL;
  }

  GHashTable *h = g_hash_table_new_full (g_str_hash, g_str_equal, g_free, g_free);
  char **i = ret;
  while (*i) {
    char *key = *i; i++;
    char *value = *i; i++;
    g_hash_table_insert (h, key, value);
  };
  g_free (ret);
  return h;
}

/**
 * guestfs_session_list_dm_devices:
 * @session: (transfer none): A GuestfsSession object
 * @err: A GError object to receive any generated errors
 *
 * list device mapper devices
 *
 * List all device mapper devices.
 * 
 * The returned list contains /dev/mapper/* devices, eg. ones created by a
 * previous call to guestfs_session_luks_open().
 * 
 * Device mapper devices which correspond to logical volumes are *not*
 * returned in this list. Call guestfs_session_lvs() if you want to list
 * logical volumes.
 * 
 * Returns: (transfer full) (array zero-terminated=1) (element-type utf8): an array of returned strings, or NULL on error
 * Since: 1.11.15
 */
gchar **
guestfs_session_list_dm_devices (GuestfsSession *session, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "list_dm_devices");
    return NULL;
  }

  char **ret = guestfs_list_dm_devices (g);
  if (ret == NULL) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return NULL;
  }

  return ret;
}

/**
 * guestfs_session_list_filesystems:
 * @session: (transfer none): A GuestfsSession object
 * @err: A GError object to receive any generated errors
 *
 * list filesystems
 *
 * This inspection command looks for filesystems on partitions, block
 * devices and logical volumes, returning a list of @mountables containing
 * filesystems and their type.
 * 
 * The return value is a hash, where the keys are the devices containing
 * filesystems, and the values are the filesystem types. For example:
 * 
 * <![CDATA["/dev/sda1" => "ntfs"]]>
 * 
 * <![CDATA["/dev/sda2" => "ext2"]]>
 * 
 * <![CDATA["/dev/vg_guest/lv_root" => "ext4"]]>
 * 
 * <![CDATA["/dev/vg_guest/lv_swap" => "swap"]]>
 * 
 * The key is not necessarily a block device. It may also be an opaque
 * 'mountable' string which can be passed to guestfs_session_mount().
 * 
 * The value can have the special value "unknown", meaning the content of
 * the device is undetermined or empty. "swap" means a Linux swap
 * partition.
 * 
 * This command runs other libguestfs commands, which might include
 * guestfs_session_mount() and guestfs_session_umount(), and therefore you
 * should use this soon after launch and only when nothing is mounted.
 * 
 * Not all of the filesystems returned will be mountable. In particular,
 * swap partitions are returned in the list. Also this command does not
 * check that each filesystem found is valid and mountable, and some
 * filesystems might be mountable but require special options. Filesystems
 * may not all belong to a single logical operating system (use
 * guestfs_session_inspect_os() to look for OSes).
 * 
 * Returns: (transfer full) (element-type utf8 utf8): a GHashTable of results, or NULL on error
 * Since: 1.5.15
 */
GHashTable *
guestfs_session_list_filesystems (GuestfsSession *session, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "list_filesystems");
    return NULL;
  }

  char **ret = guestfs_list_filesystems (g);
  if (ret == NULL) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return NULL;
  }

  GHashTable *h = g_hash_table_new_full (g_str_hash, g_str_equal, g_free, g_free);
  char **i = ret;
  while (*i) {
    char *key = *i; i++;
    char *value = *i; i++;
    g_hash_table_insert (h, key, value);
  };
  g_free (ret);
  return h;
}

/**
 * guestfs_session_list_ldm_partitions:
 * @session: (transfer none): A GuestfsSession object
 * @err: A GError object to receive any generated errors
 *
 * list all Windows dynamic disk partitions
 *
 * This function returns all Windows dynamic disk partitions that were
 * found at launch time. It returns a list of device names.
 * 
 * Returns: (transfer full) (array zero-terminated=1) (element-type utf8): an array of returned strings, or NULL on error
 * Since: 1.20.0
 */
gchar **
guestfs_session_list_ldm_partitions (GuestfsSession *session, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "list_ldm_partitions");
    return NULL;
  }

  char **ret = guestfs_list_ldm_partitions (g);
  if (ret == NULL) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return NULL;
  }

  return ret;
}

/**
 * guestfs_session_list_ldm_volumes:
 * @session: (transfer none): A GuestfsSession object
 * @err: A GError object to receive any generated errors
 *
 * list all Windows dynamic disk volumes
 *
 * This function returns all Windows dynamic disk volumes that were found
 * at launch time. It returns a list of device names.
 * 
 * Returns: (transfer full) (array zero-terminated=1) (element-type utf8): an array of returned strings, or NULL on error
 * Since: 1.20.0
 */
gchar **
guestfs_session_list_ldm_volumes (GuestfsSession *session, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "list_ldm_volumes");
    return NULL;
  }

  char **ret = guestfs_list_ldm_volumes (g);
  if (ret == NULL) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return NULL;
  }

  return ret;
}

/**
 * guestfs_session_list_md_devices:
 * @session: (transfer none): A GuestfsSession object
 * @err: A GError object to receive any generated errors
 *
 * list Linux md (RAID) devices
 *
 * List all Linux md devices.
 * 
 * Returns: (transfer full) (array zero-terminated=1) (element-type utf8): an array of returned strings, or NULL on error
 * Since: 1.15.4
 */
gchar **
guestfs_session_list_md_devices (GuestfsSession *session, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "list_md_devices");
    return NULL;
  }

  char **ret = guestfs_list_md_devices (g);
  if (ret == NULL) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return NULL;
  }

  return ret;
}

/**
 * guestfs_session_list_partitions:
 * @session: (transfer none): A GuestfsSession object
 * @err: A GError object to receive any generated errors
 *
 * list the partitions
 *
 * List all the partitions detected on all block devices.
 * 
 * The full partition device names are returned, eg. /dev/sda1
 * 
 * This does not return logical volumes. For that you will need to call
 * guestfs_session_lvs().
 * 
 * See also guestfs_session_list_filesystems().
 * 
 * Returns: (transfer full) (array zero-terminated=1) (element-type utf8): an array of returned strings, or NULL on error
 * Since: 0.4
 */
gchar **
guestfs_session_list_partitions (GuestfsSession *session, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "list_partitions");
    return NULL;
  }

  char **ret = guestfs_list_partitions (g);
  if (ret == NULL) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return NULL;
  }

  return ret;
}

/**
 * guestfs_session_ll:
 * @session: (transfer none): A GuestfsSession object
 * @directory: (transfer none) (type filename):
 * @err: A GError object to receive any generated errors
 *
 * list the files in a directory (long format)
 *
 * List the files in directory (relative to the root directory, there is no
 * cwd) in the format of 'ls -la'.
 * 
 * This command is mostly useful for interactive sessions. It is *not*
 * intended that you try to parse the output string.
 * 
 * Returns: (transfer full): the returned string, or NULL on error
 * Since: 0.4
 */
gchar *
guestfs_session_ll (GuestfsSession *session, const gchar *directory, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "ll");
    return NULL;
  }

  char *ret = guestfs_ll (g, directory);
  if (ret == NULL) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return NULL;
  }

  return ret;
}

/**
 * guestfs_session_llz:
 * @session: (transfer none): A GuestfsSession object
 * @directory: (transfer none) (type filename):
 * @err: A GError object to receive any generated errors
 *
 * list the files in a directory (long format with SELinux contexts)
 *
 * List the files in directory in the format of 'ls -laZ'.
 * 
 * This command is mostly useful for interactive sessions. It is *not*
 * intended that you try to parse the output string.
 * 
 * Returns: (transfer full): the returned string, or NULL on error
 * Since: 1.17.6
 */
gchar *
guestfs_session_llz (GuestfsSession *session, const gchar *directory, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "llz");
    return NULL;
  }

  char *ret = guestfs_llz (g, directory);
  if (ret == NULL) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return NULL;
  }

  return ret;
}

/**
 * guestfs_session_ln:
 * @session: (transfer none): A GuestfsSession object
 * @target: (transfer none) (type utf8):
 * @linkname: (transfer none) (type filename):
 * @err: A GError object to receive any generated errors
 *
 * create a hard link
 *
 * This command creates a hard link using the @ln command.
 * 
 * Returns: true on success, false on error
 * Since: 1.0.66
 */
gboolean
guestfs_session_ln (GuestfsSession *session, const gchar *target, const gchar *linkname, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "ln");
    return FALSE;
  }

  int ret = guestfs_ln (g, target, linkname);
  if (ret == -1) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return FALSE;
  }

  return TRUE;
}

/**
 * guestfs_session_ln_f:
 * @session: (transfer none): A GuestfsSession object
 * @target: (transfer none) (type utf8):
 * @linkname: (transfer none) (type filename):
 * @err: A GError object to receive any generated errors
 *
 * create a hard link
 *
 * This command creates a hard link using the "ln -f" command. The *-f*
 * option removes the link (@linkname) if it exists already.
 * 
 * Returns: true on success, false on error
 * Since: 1.0.66
 */
gboolean
guestfs_session_ln_f (GuestfsSession *session, const gchar *target, const gchar *linkname, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "ln_f");
    return FALSE;
  }

  int ret = guestfs_ln_f (g, target, linkname);
  if (ret == -1) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return FALSE;
  }

  return TRUE;
}

/**
 * guestfs_session_ln_s:
 * @session: (transfer none): A GuestfsSession object
 * @target: (transfer none) (type utf8):
 * @linkname: (transfer none) (type filename):
 * @err: A GError object to receive any generated errors
 *
 * create a symbolic link
 *
 * This command creates a symbolic link using the "ln -s" command.
 * 
 * Returns: true on success, false on error
 * Since: 1.0.66
 */
gboolean
guestfs_session_ln_s (GuestfsSession *session, const gchar *target, const gchar *linkname, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "ln_s");
    return FALSE;
  }

  int ret = guestfs_ln_s (g, target, linkname);
  if (ret == -1) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return FALSE;
  }

  return TRUE;
}

/**
 * guestfs_session_ln_sf:
 * @session: (transfer none): A GuestfsSession object
 * @target: (transfer none) (type utf8):
 * @linkname: (transfer none) (type filename):
 * @err: A GError object to receive any generated errors
 *
 * create a symbolic link
 *
 * This command creates a symbolic link using the "ln -sf" command, The
 * *-f* option removes the link (@linkname) if it exists already.
 * 
 * Returns: true on success, false on error
 * Since: 1.0.66
 */
gboolean
guestfs_session_ln_sf (GuestfsSession *session, const gchar *target, const gchar *linkname, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "ln_sf");
    return FALSE;
  }

  int ret = guestfs_ln_sf (g, target, linkname);
  if (ret == -1) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return FALSE;
  }

  return TRUE;
}

/**
 * guestfs_session_lremovexattr:
 * @session: (transfer none): A GuestfsSession object
 * @xattr: (transfer none) (type utf8):
 * @path: (transfer none) (type filename):
 * @err: A GError object to receive any generated errors
 *
 * remove extended attribute of a file or directory
 *
 * This is the same as guestfs_session_removexattr(), but if @path is a
 * symbolic link, then it removes an extended attribute of the link itself.
 * 
 * Returns: true on success, false on error
 * Since: 1.0.59
 */
gboolean
guestfs_session_lremovexattr (GuestfsSession *session, const gchar *xattr, const gchar *path, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "lremovexattr");
    return FALSE;
  }

  int ret = guestfs_lremovexattr (g, xattr, path);
  if (ret == -1) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return FALSE;
  }

  return TRUE;
}

/**
 * guestfs_session_ls:
 * @session: (transfer none): A GuestfsSession object
 * @directory: (transfer none) (type filename):
 * @err: A GError object to receive any generated errors
 *
 * list the files in a directory
 *
 * List the files in directory (relative to the root directory, there is no
 * cwd). The '.' and '..' entries are not returned, but hidden files are
 * shown.
 * 
 * Returns: (transfer full) (array zero-terminated=1) (element-type utf8): an array of returned strings, or NULL on error
 * Since: 0.4
 */
gchar **
guestfs_session_ls (GuestfsSession *session, const gchar *directory, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "ls");
    return NULL;
  }

  char **ret = guestfs_ls (g, directory);
  if (ret == NULL) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return NULL;
  }

  return ret;
}

/**
 * guestfs_session_ls0:
 * @session: (transfer none): A GuestfsSession object
 * @dir: (transfer none) (type filename):
 * @filenames: (transfer none) (type filename):
 * @err: A GError object to receive any generated errors
 *
 * get list of files in a directory
 *
 * This specialized command is used to get a listing of the filenames in
 * the directory @dir. The list of filenames is written to the local file
 * filenames (on the host).
 * 
 * In the output file, the filenames are separated by "\0" characters.
 * 
 * "." and ".." are not returned. The filenames are not sorted.
 * 
 * Returns: true on success, false on error
 * Since: 1.19.32
 */
gboolean
guestfs_session_ls0 (GuestfsSession *session, const gchar *dir, const gchar *filenames, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "ls0");
    return FALSE;
  }

  int ret = guestfs_ls0 (g, dir, filenames);
  if (ret == -1) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return FALSE;
  }

  return TRUE;
}

/**
 * guestfs_session_lsetxattr:
 * @session: (transfer none): A GuestfsSession object
 * @xattr: (transfer none) (type utf8):
 * @val: (transfer none) (type utf8):
 * @vallen: (type gint32):
 * @path: (transfer none) (type filename):
 * @err: A GError object to receive any generated errors
 *
 * set extended attribute of a file or directory
 *
 * This is the same as guestfs_session_setxattr(), but if @path is a
 * symbolic link, then it sets an extended attribute of the link itself.
 * 
 * Returns: true on success, false on error
 * Since: 1.0.59
 */
gboolean
guestfs_session_lsetxattr (GuestfsSession *session, const gchar *xattr, const gchar *val, gint32 vallen, const gchar *path, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "lsetxattr");
    return FALSE;
  }

  int ret = guestfs_lsetxattr (g, xattr, val, vallen, path);
  if (ret == -1) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return FALSE;
  }

  return TRUE;
}

/**
 * guestfs_session_lstat:
 * @session: (transfer none): A GuestfsSession object
 * @path: (transfer none) (type filename):
 * @err: A GError object to receive any generated errors
 *
 * get file information for a symbolic link
 *
 * Returns file information for the given @path.
 * 
 * This is the same as guestfs_session_stat() except that if @path is a
 * symbolic link, then the link is stat-ed, not the file it refers to.
 * 
 * This is the same as the lstat(2) system call.
 * 
 * Returns: (transfer full): a Stat object, or NULL on error
 * Deprecated: In new code, use guestfs_session_lstatns() instead
 * Since: 1.9.2
 */
GuestfsStat *
guestfs_session_lstat (GuestfsSession *session, const gchar *path, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "lstat");
    return NULL;
  }

  struct guestfs_stat *ret = guestfs_lstat (g, path);
  if (ret == NULL) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return NULL;
  }

  GuestfsStat *s = g_slice_new0 (GuestfsStat);
  s->dev = ret->dev;
  s->ino = ret->ino;
  s->mode = ret->mode;
  s->nlink = ret->nlink;
  s->uid = ret->uid;
  s->gid = ret->gid;
  s->rdev = ret->rdev;
  s->size = ret->size;
  s->blksize = ret->blksize;
  s->blocks = ret->blocks;
  s->atime = ret->atime;
  s->mtime = ret->mtime;
  s->ctime = ret->ctime;
  guestfs_free_stat (ret);
  return s;
}

/**
 * guestfs_session_lstatlist:
 * @session: (transfer none): A GuestfsSession object
 * @path: (transfer none) (type filename):
 * @names: (transfer none) (array zero-terminated=1) (element-type utf8): an array of strings
 * @err: A GError object to receive any generated errors
 *
 * lstat on multiple files
 *
 * This call allows you to perform the guestfs_session_lstat() operation on
 * multiple files, where all files are in the directory @path. @names is
 * the list of files from this directory.
 * 
 * On return you get a list of stat structs, with a one-to-one
 * correspondence to the @names list. If any name did not exist or could
 * not be lstat'd, then the @st_ino field of that structure is set to @-1.
 * 
 * This call is intended for programs that want to efficiently list a
 * directory contents without making many round-trips. See also
 * guestfs_session_lxattrlist() for a similarly efficient call for getting
 * extended attributes.
 * 
 * Returns: (transfer full) (array zero-terminated=1) (element-type GuestfsStat): an array of Stat objects, or NULL on error
 * Deprecated: In new code, use guestfs_session_lstatnslist() instead
 * Since: 1.0.77
 */
GuestfsStat **
guestfs_session_lstatlist (GuestfsSession *session, const gchar *path, gchar *const *names, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "lstatlist");
    return NULL;
  }

  struct guestfs_stat_list *ret = guestfs_lstatlist (g, path, names);
  if (ret == NULL) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return NULL;
  }

  GuestfsStat **l = g_malloc (sizeof (GuestfsStat*) * (ret->len + 1));
  gsize i;
  for (i = 0; i < ret->len; i++) {
    l[i] = g_slice_new0 (GuestfsStat);
    l[i]->dev = ret->val[i].dev;
    l[i]->ino = ret->val[i].ino;
    l[i]->mode = ret->val[i].mode;
    l[i]->nlink = ret->val[i].nlink;
    l[i]->uid = ret->val[i].uid;
    l[i]->gid = ret->val[i].gid;
    l[i]->rdev = ret->val[i].rdev;
    l[i]->size = ret->val[i].size;
    l[i]->blksize = ret->val[i].blksize;
    l[i]->blocks = ret->val[i].blocks;
    l[i]->atime = ret->val[i].atime;
    l[i]->mtime = ret->val[i].mtime;
    l[i]->ctime = ret->val[i].ctime;
  }
  guestfs_free_stat_list (ret);
  l[i] = NULL;
  return l;
}

/**
 * guestfs_session_lstatns:
 * @session: (transfer none): A GuestfsSession object
 * @path: (transfer none) (type filename):
 * @err: A GError object to receive any generated errors
 *
 * get file information for a symbolic link
 *
 * Returns file information for the given @path.
 * 
 * This is the same as guestfs_session_statns() except that if @path is a
 * symbolic link, then the link is stat-ed, not the file it refers to.
 * 
 * This is the same as the lstat(2) system call.
 * 
 * Returns: (transfer full): a StatNS object, or NULL on error
 * Since: 1.27.53
 */
GuestfsStatNS *
guestfs_session_lstatns (GuestfsSession *session, const gchar *path, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "lstatns");
    return NULL;
  }

  struct guestfs_statns *ret = guestfs_lstatns (g, path);
  if (ret == NULL) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return NULL;
  }

  GuestfsStatNS *s = g_slice_new0 (GuestfsStatNS);
  s->st_dev = ret->st_dev;
  s->st_ino = ret->st_ino;
  s->st_mode = ret->st_mode;
  s->st_nlink = ret->st_nlink;
  s->st_uid = ret->st_uid;
  s->st_gid = ret->st_gid;
  s->st_rdev = ret->st_rdev;
  s->st_size = ret->st_size;
  s->st_blksize = ret->st_blksize;
  s->st_blocks = ret->st_blocks;
  s->st_atime_sec = ret->st_atime_sec;
  s->st_atime_nsec = ret->st_atime_nsec;
  s->st_mtime_sec = ret->st_mtime_sec;
  s->st_mtime_nsec = ret->st_mtime_nsec;
  s->st_ctime_sec = ret->st_ctime_sec;
  s->st_ctime_nsec = ret->st_ctime_nsec;
  s->st_spare1 = ret->st_spare1;
  s->st_spare2 = ret->st_spare2;
  s->st_spare3 = ret->st_spare3;
  s->st_spare4 = ret->st_spare4;
  s->st_spare5 = ret->st_spare5;
  s->st_spare6 = ret->st_spare6;
  guestfs_free_statns (ret);
  return s;
}

/**
 * guestfs_session_lstatnslist:
 * @session: (transfer none): A GuestfsSession object
 * @path: (transfer none) (type filename):
 * @names: (transfer none) (array zero-terminated=1) (element-type utf8): an array of strings
 * @err: A GError object to receive any generated errors
 *
 * lstat on multiple files
 *
 * This call allows you to perform the guestfs_session_lstatns() operation
 * on multiple files, where all files are in the directory @path. @names is
 * the list of files from this directory.
 * 
 * On return you get a list of stat structs, with a one-to-one
 * correspondence to the @names list. If any name did not exist or could
 * not be lstat'd, then the @st_ino field of that structure is set to @-1.
 * 
 * This call is intended for programs that want to efficiently list a
 * directory contents without making many round-trips. See also
 * guestfs_session_lxattrlist() for a similarly efficient call for getting
 * extended attributes.
 * 
 * Returns: (transfer full) (array zero-terminated=1) (element-type GuestfsStatNS): an array of StatNS objects, or NULL on error
 * Since: 1.27.53
 */
GuestfsStatNS **
guestfs_session_lstatnslist (GuestfsSession *session, const gchar *path, gchar *const *names, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "lstatnslist");
    return NULL;
  }

  struct guestfs_statns_list *ret = guestfs_lstatnslist (g, path, names);
  if (ret == NULL) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return NULL;
  }

  GuestfsStatNS **l = g_malloc (sizeof (GuestfsStatNS*) * (ret->len + 1));
  gsize i;
  for (i = 0; i < ret->len; i++) {
    l[i] = g_slice_new0 (GuestfsStatNS);
    l[i]->st_dev = ret->val[i].st_dev;
    l[i]->st_ino = ret->val[i].st_ino;
    l[i]->st_mode = ret->val[i].st_mode;
    l[i]->st_nlink = ret->val[i].st_nlink;
    l[i]->st_uid = ret->val[i].st_uid;
    l[i]->st_gid = ret->val[i].st_gid;
    l[i]->st_rdev = ret->val[i].st_rdev;
    l[i]->st_size = ret->val[i].st_size;
    l[i]->st_blksize = ret->val[i].st_blksize;
    l[i]->st_blocks = ret->val[i].st_blocks;
    l[i]->st_atime_sec = ret->val[i].st_atime_sec;
    l[i]->st_atime_nsec = ret->val[i].st_atime_nsec;
    l[i]->st_mtime_sec = ret->val[i].st_mtime_sec;
    l[i]->st_mtime_nsec = ret->val[i].st_mtime_nsec;
    l[i]->st_ctime_sec = ret->val[i].st_ctime_sec;
    l[i]->st_ctime_nsec = ret->val[i].st_ctime_nsec;
    l[i]->st_spare1 = ret->val[i].st_spare1;
    l[i]->st_spare2 = ret->val[i].st_spare2;
    l[i]->st_spare3 = ret->val[i].st_spare3;
    l[i]->st_spare4 = ret->val[i].st_spare4;
    l[i]->st_spare5 = ret->val[i].st_spare5;
    l[i]->st_spare6 = ret->val[i].st_spare6;
  }
  guestfs_free_statns_list (ret);
  l[i] = NULL;
  return l;
}

/**
 * guestfs_session_luks_add_key:
 * @session: (transfer none): A GuestfsSession object
 * @device: (transfer none) (type filename):
 * @key: (transfer none) (type utf8):
 * @newkey: (transfer none) (type utf8):
 * @keyslot: (type gint32):
 * @err: A GError object to receive any generated errors
 *
 * add a key on a LUKS encrypted device
 *
 * This command adds a new key on LUKS device @device. @key is any existing
 * key, and is used to access the device. @newkey is the new key to add.
 * @keyslot is the key slot that will be replaced.
 * 
 * Note that if @keyslot already contains a key, then this command will
 * fail. You have to use guestfs_session_luks_kill_slot() first to remove
 * that key.
 * 
 * Returns: true on success, false on error
 * Since: 1.5.2
 */
gboolean
guestfs_session_luks_add_key (GuestfsSession *session, const gchar *device, const gchar *key, const gchar *newkey, gint32 keyslot, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "luks_add_key");
    return FALSE;
  }

  int ret = guestfs_luks_add_key (g, device, key, newkey, keyslot);
  if (ret == -1) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return FALSE;
  }

  return TRUE;
}

/**
 * guestfs_session_luks_close:
 * @session: (transfer none): A GuestfsSession object
 * @device: (transfer none) (type filename):
 * @err: A GError object to receive any generated errors
 *
 * close a LUKS device
 *
 * This closes a LUKS device that was created earlier by
 * guestfs_session_luks_open() or guestfs_session_luks_open_ro(). The
 * @device parameter must be the name of the LUKS mapping device (ie.
 * /dev/mapper/mapname) and *not* the name of the underlying block device.
 * 
 * Returns: true on success, false on error
 * Since: 1.5.1
 */
gboolean
guestfs_session_luks_close (GuestfsSession *session, const gchar *device, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "luks_close");
    return FALSE;
  }

  int ret = guestfs_luks_close (g, device);
  if (ret == -1) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return FALSE;
  }

  return TRUE;
}

/**
 * guestfs_session_luks_format:
 * @session: (transfer none): A GuestfsSession object
 * @device: (transfer none) (type filename):
 * @key: (transfer none) (type utf8):
 * @keyslot: (type gint32):
 * @err: A GError object to receive any generated errors
 *
 * format a block device as a LUKS encrypted device
 *
 * This command erases existing data on @device and formats the device as a
 * LUKS encrypted device. @key is the initial key, which is added to key
 * slot @slot. (LUKS supports 8 key slots, numbered 0-7).
 * 
 * Returns: true on success, false on error
 * Since: 1.5.2
 */
gboolean
guestfs_session_luks_format (GuestfsSession *session, const gchar *device, const gchar *key, gint32 keyslot, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "luks_format");
    return FALSE;
  }

  int ret = guestfs_luks_format (g, device, key, keyslot);
  if (ret == -1) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return FALSE;
  }

  return TRUE;
}

/**
 * guestfs_session_luks_format_cipher:
 * @session: (transfer none): A GuestfsSession object
 * @device: (transfer none) (type filename):
 * @key: (transfer none) (type utf8):
 * @keyslot: (type gint32):
 * @cipher: (transfer none) (type utf8):
 * @err: A GError object to receive any generated errors
 *
 * format a block device as a LUKS encrypted device
 *
 * This command is the same as guestfs_session_luks_format() but it also
 * allows you to set the @cipher used.
 * 
 * Returns: true on success, false on error
 * Since: 1.5.2
 */
gboolean
guestfs_session_luks_format_cipher (GuestfsSession *session, const gchar *device, const gchar *key, gint32 keyslot, const gchar *cipher, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "luks_format_cipher");
    return FALSE;
  }

  int ret = guestfs_luks_format_cipher (g, device, key, keyslot, cipher);
  if (ret == -1) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return FALSE;
  }

  return TRUE;
}

/**
 * guestfs_session_luks_kill_slot:
 * @session: (transfer none): A GuestfsSession object
 * @device: (transfer none) (type filename):
 * @key: (transfer none) (type utf8):
 * @keyslot: (type gint32):
 * @err: A GError object to receive any generated errors
 *
 * remove a key from a LUKS encrypted device
 *
 * This command deletes the key in key slot @keyslot from the encrypted
 * LUKS device @device. @key must be one of the *other* keys.
 * 
 * Returns: true on success, false on error
 * Since: 1.5.2
 */
gboolean
guestfs_session_luks_kill_slot (GuestfsSession *session, const gchar *device, const gchar *key, gint32 keyslot, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "luks_kill_slot");
    return FALSE;
  }

  int ret = guestfs_luks_kill_slot (g, device, key, keyslot);
  if (ret == -1) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return FALSE;
  }

  return TRUE;
}

/**
 * guestfs_session_luks_open:
 * @session: (transfer none): A GuestfsSession object
 * @device: (transfer none) (type filename):
 * @key: (transfer none) (type utf8):
 * @mapname: (transfer none) (type utf8):
 * @err: A GError object to receive any generated errors
 *
 * open a LUKS-encrypted block device
 *
 * This command opens a block device which has been encrypted according to
 * the Linux Unified Key Setup (LUKS) standard.
 * 
 * @device is the encrypted block device or partition.
 * 
 * The caller must supply one of the keys associated with the LUKS block
 * device, in the @key parameter.
 * 
 * This creates a new block device called /dev/mapper/mapname. Reads and
 * writes to this block device are decrypted from and encrypted to the
 * underlying @device respectively.
 * 
 * If this block device contains LVM volume groups, then calling
 * guestfs_session_vgscan() followed by guestfs_session_vg_activate_all()
 * will make them visible.
 * 
 * Use guestfs_session_list_dm_devices() to list all device mapper devices.
 * 
 * Returns: true on success, false on error
 * Since: 1.5.1
 */
gboolean
guestfs_session_luks_open (GuestfsSession *session, const gchar *device, const gchar *key, const gchar *mapname, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "luks_open");
    return FALSE;
  }

  int ret = guestfs_luks_open (g, device, key, mapname);
  if (ret == -1) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return FALSE;
  }

  return TRUE;
}

/**
 * guestfs_session_luks_open_ro:
 * @session: (transfer none): A GuestfsSession object
 * @device: (transfer none) (type filename):
 * @key: (transfer none) (type utf8):
 * @mapname: (transfer none) (type utf8):
 * @err: A GError object to receive any generated errors
 *
 * open a LUKS-encrypted block device read-only
 *
 * This is the same as guestfs_session_luks_open() except that a read-only
 * mapping is created.
 * 
 * Returns: true on success, false on error
 * Since: 1.5.1
 */
gboolean
guestfs_session_luks_open_ro (GuestfsSession *session, const gchar *device, const gchar *key, const gchar *mapname, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "luks_open_ro");
    return FALSE;
  }

  int ret = guestfs_luks_open_ro (g, device, key, mapname);
  if (ret == -1) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return FALSE;
  }

  return TRUE;
}

/**
 * guestfs_session_lvcreate:
 * @session: (transfer none): A GuestfsSession object
 * @logvol: (transfer none) (type utf8):
 * @volgroup: (transfer none) (type utf8):
 * @mbytes: (type gint32):
 * @err: A GError object to receive any generated errors
 *
 * create an LVM logical volume
 *
 * This creates an LVM logical volume called @logvol on the volume group
 * @volgroup, with @size megabytes.
 * 
 * Returns: true on success, false on error
 * Since: 0.8
 */
gboolean
guestfs_session_lvcreate (GuestfsSession *session, const gchar *logvol, const gchar *volgroup, gint32 mbytes, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "lvcreate");
    return FALSE;
  }

  int ret = guestfs_lvcreate (g, logvol, volgroup, mbytes);
  if (ret == -1) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return FALSE;
  }

  return TRUE;
}

/**
 * guestfs_session_lvcreate_free:
 * @session: (transfer none): A GuestfsSession object
 * @logvol: (transfer none) (type utf8):
 * @volgroup: (transfer none) (type utf8):
 * @percent: (type gint32):
 * @err: A GError object to receive any generated errors
 *
 * create an LVM logical volume in % remaining free space
 *
 * Create an LVM logical volume called /dev/volgroup/logvol, using
 * approximately @percent % of the free space remaining in the volume
 * group. Most usefully, when @percent is @100 this will create the largest
 * possible LV.
 * 
 * Returns: true on success, false on error
 * Since: 1.17.18
 */
gboolean
guestfs_session_lvcreate_free (GuestfsSession *session, const gchar *logvol, const gchar *volgroup, gint32 percent, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "lvcreate_free");
    return FALSE;
  }

  int ret = guestfs_lvcreate_free (g, logvol, volgroup, percent);
  if (ret == -1) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return FALSE;
  }

  return TRUE;
}

/**
 * guestfs_session_lvm_canonical_lv_name:
 * @session: (transfer none): A GuestfsSession object
 * @lvname: (transfer none) (type filename):
 * @err: A GError object to receive any generated errors
 *
 * get canonical name of an LV
 *
 * This converts alternative naming schemes for LVs that you might find to
 * the canonical name. For example, /dev/mapper/VG-LV is converted to
 * /dev/VG/LV.
 * 
 * This command returns an error if the @lvname parameter does not refer to
 * a logical volume.
 * 
 * See also guestfs_session_is_lv(),
 * guestfs_session_canonical_device_name().
 * 
 * Returns: (transfer full): the returned string, or NULL on error
 * Since: 1.5.24
 */
gchar *
guestfs_session_lvm_canonical_lv_name (GuestfsSession *session, const gchar *lvname, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "lvm_canonical_lv_name");
    return NULL;
  }

  char *ret = guestfs_lvm_canonical_lv_name (g, lvname);
  if (ret == NULL) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return NULL;
  }

  return ret;
}

/**
 * guestfs_session_lvm_clear_filter:
 * @session: (transfer none): A GuestfsSession object
 * @err: A GError object to receive any generated errors
 *
 * clear LVM device filter
 *
 * This undoes the effect of guestfs_session_lvm_set_filter(). LVM will be
 * able to see every block device.
 * 
 * This command also clears the LVM cache and performs a volume group scan.
 * 
 * Returns: true on success, false on error
 * Since: 1.5.1
 */
gboolean
guestfs_session_lvm_clear_filter (GuestfsSession *session, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "lvm_clear_filter");
    return FALSE;
  }

  int ret = guestfs_lvm_clear_filter (g);
  if (ret == -1) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return FALSE;
  }

  return TRUE;
}

/**
 * guestfs_session_lvm_remove_all:
 * @session: (transfer none): A GuestfsSession object
 * @err: A GError object to receive any generated errors
 *
 * remove all LVM LVs, VGs and PVs
 *
 * This command removes all LVM logical volumes, volume groups and physical
 * volumes.
 * 
 * Returns: true on success, false on error
 * Since: 0.8
 */
gboolean
guestfs_session_lvm_remove_all (GuestfsSession *session, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "lvm_remove_all");
    return FALSE;
  }

  int ret = guestfs_lvm_remove_all (g);
  if (ret == -1) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return FALSE;
  }

  return TRUE;
}

/**
 * guestfs_session_lvm_set_filter:
 * @session: (transfer none): A GuestfsSession object
 * @devices: (transfer none) (array zero-terminated=1) (element-type filename): an array of strings
 * @err: A GError object to receive any generated errors
 *
 * set LVM device filter
 *
 * This sets the LVM device filter so that LVM will only be able to "see"
 * the block devices in the list @devices, and will ignore all other
 * attached block devices.
 * 
 * Where disk image(s) contain duplicate PVs or VGs, this command is useful
 * to get LVM to ignore the duplicates, otherwise LVM can get confused.
 * Note also there are two types of duplication possible: either cloned
 * PVs/VGs which have identical UUIDs; or VGs that are not cloned but just
 * happen to have the same name. In normal operation you cannot create this
 * situation, but you can do it outside LVM, eg. by cloning disk images or
 * by bit twiddling inside the LVM metadata.
 * 
 * This command also clears the LVM cache and performs a volume group scan.
 * 
 * You can filter whole block devices or individual partitions.
 * 
 * You cannot use this if any VG is currently in use (eg. contains a
 * mounted filesystem), even if you are not filtering out that VG.
 * 
 * Returns: true on success, false on error
 * Since: 1.5.1
 */
gboolean
guestfs_session_lvm_set_filter (GuestfsSession *session, gchar *const *devices, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "lvm_set_filter");
    return FALSE;
  }

  int ret = guestfs_lvm_set_filter (g, devices);
  if (ret == -1) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return FALSE;
  }

  return TRUE;
}

/**
 * guestfs_session_lvremove:
 * @session: (transfer none): A GuestfsSession object
 * @device: (transfer none) (type filename):
 * @err: A GError object to receive any generated errors
 *
 * remove an LVM logical volume
 *
 * Remove an LVM logical volume @device, where @device is the path to the
 * LV, such as /dev/VG/LV.
 * 
 * You can also remove all LVs in a volume group by specifying the VG name,
 * /dev/VG.
 * 
 * Returns: true on success, false on error
 * Since: 1.0.13
 */
gboolean
guestfs_session_lvremove (GuestfsSession *session, const gchar *device, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "lvremove");
    return FALSE;
  }

  int ret = guestfs_lvremove (g, device);
  if (ret == -1) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return FALSE;
  }

  return TRUE;
}

/**
 * guestfs_session_lvrename:
 * @session: (transfer none): A GuestfsSession object
 * @logvol: (transfer none) (type utf8):
 * @newlogvol: (transfer none) (type utf8):
 * @err: A GError object to receive any generated errors
 *
 * rename an LVM logical volume
 *
 * Rename a logical volume @logvol with the new name @newlogvol.
 * 
 * Returns: true on success, false on error
 * Since: 1.0.83
 */
gboolean
guestfs_session_lvrename (GuestfsSession *session, const gchar *logvol, const gchar *newlogvol, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "lvrename");
    return FALSE;
  }

  int ret = guestfs_lvrename (g, logvol, newlogvol);
  if (ret == -1) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return FALSE;
  }

  return TRUE;
}

/**
 * guestfs_session_lvresize:
 * @session: (transfer none): A GuestfsSession object
 * @device: (transfer none) (type filename):
 * @mbytes: (type gint32):
 * @err: A GError object to receive any generated errors
 *
 * resize an LVM logical volume
 *
 * This resizes (expands or shrinks) an existing LVM logical volume to
 * @mbytes. When reducing, data in the reduced part is lost.
 * 
 * Returns: true on success, false on error
 * Since: 1.0.27
 */
gboolean
guestfs_session_lvresize (GuestfsSession *session, const gchar *device, gint32 mbytes, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "lvresize");
    return FALSE;
  }

  int ret = guestfs_lvresize (g, device, mbytes);
  if (ret == -1) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return FALSE;
  }

  return TRUE;
}

/**
 * guestfs_session_lvresize_free:
 * @session: (transfer none): A GuestfsSession object
 * @lv: (transfer none) (type filename):
 * @percent: (type gint32):
 * @err: A GError object to receive any generated errors
 *
 * expand an LV to fill free space
 *
 * This expands an existing logical volume @lv so that it fills @pc% of the
 * remaining free space in the volume group. Commonly you would call this
 * with pc = 100 which expands the logical volume as much as possible,
 * using all remaining free space in the volume group.
 * 
 * Returns: true on success, false on error
 * Since: 1.3.3
 */
gboolean
guestfs_session_lvresize_free (GuestfsSession *session, const gchar *lv, gint32 percent, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "lvresize_free");
    return FALSE;
  }

  int ret = guestfs_lvresize_free (g, lv, percent);
  if (ret == -1) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return FALSE;
  }

  return TRUE;
}

/**
 * guestfs_session_lvs:
 * @session: (transfer none): A GuestfsSession object
 * @err: A GError object to receive any generated errors
 *
 * list the LVM logical volumes (LVs)
 *
 * List all the logical volumes detected. This is the equivalent of the
 * lvs(8) command.
 * 
 * This returns a list of the logical volume device names (eg.
 * /dev/VolGroup00/LogVol00).
 * 
 * See also guestfs_session_lvs_full(), guestfs_session_list_filesystems().
 * 
 * Returns: (transfer full) (array zero-terminated=1) (element-type utf8): an array of returned strings, or NULL on error
 * Since: 0.4
 */
gchar **
guestfs_session_lvs (GuestfsSession *session, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "lvs");
    return NULL;
  }

  char **ret = guestfs_lvs (g);
  if (ret == NULL) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return NULL;
  }

  return ret;
}

/**
 * guestfs_session_lvs_full:
 * @session: (transfer none): A GuestfsSession object
 * @err: A GError object to receive any generated errors
 *
 * list the LVM logical volumes (LVs)
 *
 * List all the logical volumes detected. This is the equivalent of the
 * lvs(8) command. The "full" version includes all fields.
 * 
 * Returns: (transfer full) (array zero-terminated=1) (element-type GuestfsLV): an array of LV objects, or NULL on error
 * Since: 0.4
 */
GuestfsLV **
guestfs_session_lvs_full (GuestfsSession *session, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "lvs_full");
    return NULL;
  }

  struct guestfs_lvm_lv_list *ret = guestfs_lvs_full (g);
  if (ret == NULL) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return NULL;
  }

  GuestfsLV **l = g_malloc (sizeof (GuestfsLV*) * (ret->len + 1));
  gsize i;
  for (i = 0; i < ret->len; i++) {
    l[i] = g_slice_new0 (GuestfsLV);
    if (ret->val[i].lv_name) l[i]->lv_name = g_strdup (ret->val[i].lv_name);
    if (ret->val[i].lv_uuid) memcpy (l[i]->lv_uuid, ret->val[i].lv_uuid, sizeof (l[i]->lv_uuid));
    if (ret->val[i].lv_attr) l[i]->lv_attr = g_strdup (ret->val[i].lv_attr);
    l[i]->lv_major = ret->val[i].lv_major;
    l[i]->lv_minor = ret->val[i].lv_minor;
    l[i]->lv_kernel_major = ret->val[i].lv_kernel_major;
    l[i]->lv_kernel_minor = ret->val[i].lv_kernel_minor;
    l[i]->lv_size = ret->val[i].lv_size;
    l[i]->seg_count = ret->val[i].seg_count;
    if (ret->val[i].origin) l[i]->origin = g_strdup (ret->val[i].origin);
    l[i]->snap_percent = ret->val[i].snap_percent;
    l[i]->copy_percent = ret->val[i].copy_percent;
    if (ret->val[i].move_pv) l[i]->move_pv = g_strdup (ret->val[i].move_pv);
    if (ret->val[i].lv_tags) l[i]->lv_tags = g_strdup (ret->val[i].lv_tags);
    if (ret->val[i].mirror_log) l[i]->mirror_log = g_strdup (ret->val[i].mirror_log);
    if (ret->val[i].modules) l[i]->modules = g_strdup (ret->val[i].modules);
  }
  guestfs_free_lvm_lv_list (ret);
  l[i] = NULL;
  return l;
}

/**
 * guestfs_session_lvuuid:
 * @session: (transfer none): A GuestfsSession object
 * @device: (transfer none) (type filename):
 * @err: A GError object to receive any generated errors
 *
 * get the UUID of a logical volume
 *
 * This command returns the UUID of the LVM LV @device.
 * 
 * Returns: (transfer full): the returned string, or NULL on error
 * Since: 1.0.87
 */
gchar *
guestfs_session_lvuuid (GuestfsSession *session, const gchar *device, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "lvuuid");
    return NULL;
  }

  char *ret = guestfs_lvuuid (g, device);
  if (ret == NULL) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return NULL;
  }

  return ret;
}

/**
 * guestfs_session_lxattrlist:
 * @session: (transfer none): A GuestfsSession object
 * @path: (transfer none) (type filename):
 * @names: (transfer none) (array zero-terminated=1) (element-type utf8): an array of strings
 * @err: A GError object to receive any generated errors
 *
 * lgetxattr on multiple files
 *
 * This call allows you to get the extended attributes of multiple files,
 * where all files are in the directory @path. @names is the list of files
 * from this directory.
 * 
 * On return you get a flat list of xattr structs which must be interpreted
 * sequentially. The first xattr struct always has a zero-length @attrname.
 * @attrval in this struct is zero-length to indicate there was an error
 * doing @lgetxattr for this file, *or* is a C string which is a decimal
 * number (the number of following attributes for this file, which could be
 * "0"). Then after the first xattr struct are the zero or more attributes
 * for the first named file. This repeats for the second and subsequent
 * files.
 * 
 * This call is intended for programs that want to efficiently list a
 * directory contents without making many round-trips. See also
 * guestfs_session_lstatlist() for a similarly efficient call for getting
 * standard stats.
 * 
 * Returns: (transfer full) (array zero-terminated=1) (element-type GuestfsXAttr): an array of XAttr objects, or NULL on error
 * Since: 1.0.77
 */
GuestfsXAttr **
guestfs_session_lxattrlist (GuestfsSession *session, const gchar *path, gchar *const *names, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "lxattrlist");
    return NULL;
  }

  struct guestfs_xattr_list *ret = guestfs_lxattrlist (g, path, names);
  if (ret == NULL) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return NULL;
  }

  GuestfsXAttr **l = g_malloc (sizeof (GuestfsXAttr*) * (ret->len + 1));
  gsize i;
  for (i = 0; i < ret->len; i++) {
    l[i] = g_slice_new0 (GuestfsXAttr);
    if (ret->val[i].attrname) l[i]->attrname = g_strdup (ret->val[i].attrname);
    if (ret->val[i].attrval) {
      l[i]->attrval = g_byte_array_sized_new (ret->val[i].attrval_len);
      g_byte_array_append (l[i]->attrval, (const guint8 *) ret->val[i].attrval, ret->val[i].attrval_len);
    }
  }
  guestfs_free_xattr_list (ret);
  l[i] = NULL;
  return l;
}

/**
 * guestfs_session_max_disks:
 * @session: (transfer none): A GuestfsSession object
 * @err: A GError object to receive any generated errors
 *
 * maximum number of disks that may be added
 *
 * Return the maximum number of disks that may be added to a handle (eg. by
 * guestfs_session_add_drive_opts() and similar calls).
 * 
 * This function was added in libguestfs 1.19.7. In previous versions of
 * libguestfs the limit was 25.
 * 
 * See "MAXIMUM NUMBER OF DISKS" in guestfs(3) for additional information
 * on this topic.
 * 
 * Returns: the returned value, or -1 on error
 * Since: 1.19.7
 */
gint32
guestfs_session_max_disks (GuestfsSession *session, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "max_disks");
    return -1;
  }

  int ret = guestfs_max_disks (g);
  if (ret == -1) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return -1;
  }

  return ret;
}

/**
 * guestfs_session_md_create:
 * @session: (transfer none): A GuestfsSession object
 * @name: (transfer none) (type utf8):
 * @devices: (transfer none) (array zero-terminated=1) (element-type filename): an array of strings
 * @optargs: (transfer none) (allow-none): a GuestfsMDCreate containing optional arguments
 * @err: A GError object to receive any generated errors
 *
 * create a Linux md (RAID) device
 *
 * Create a Linux md (RAID) device named @name on the devices in the list
 * @devices.
 * 
 * The optional parameters are:
 * 
 * @missingbitmap
 * A bitmap of missing devices. If a bit is set it means that a missing
 * device is added to the array. The least significant bit corresponds
 * to the first device in the array.
 * 
 * As examples:
 * 
 * If "devices = ["/dev/sda"]" and "missingbitmap = 0x1" then the
 * resulting array would be "[&lt;missing&gt;, "/dev/sda"]".
 * 
 * If "devices = ["/dev/sda"]" and "missingbitmap = 0x2" then the
 * resulting array would be "["/dev/sda", &lt;missing&gt;]".
 * 
 * This defaults to @0 (no missing devices).
 * 
 * The length of @devices + the number of bits set in @missingbitmap
 * must equal @nrdevices + @spare.
 * 
 * @nrdevices
 * The number of active RAID devices.
 * 
 * If not set, this defaults to the length of @devices plus the number
 * of bits set in @missingbitmap.
 * 
 * @spare
 * The number of spare devices.
 * 
 * If not set, this defaults to @0.
 * 
 * @chunk
 * The chunk size in bytes.
 * 
 * @level
 * The RAID level, which can be one of: *linear*, *raid0*, *0*,
 * *stripe*, *raid1*, *1*, *mirror*, *raid4*, *4*, *raid5*, *5*,
 * *raid6*, *6*, *raid10*, *10*. Some of these are synonymous, and more
 * levels may be added in future.
 * 
 * If not set, this defaults to @raid1.
 * 
 * Returns: true on success, false on error
 * Since: 1.15.6
 */
gboolean
guestfs_session_md_create (GuestfsSession *session, const gchar *name, gchar *const *devices, GuestfsMDCreate *optargs, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "md_create");
    return FALSE;
  }

  struct guestfs_md_create_argv argv;
  struct guestfs_md_create_argv *argvp = NULL;

  if (optargs) {
    argv.bitmask = 0;

    GValue missingbitmap_v = {0, };
    g_value_init (&missingbitmap_v, G_TYPE_INT64);
    g_object_get_property (G_OBJECT (optargs), "missingbitmap", &missingbitmap_v);
    gint64 missingbitmap = g_value_get_int64 (&missingbitmap_v);
    if (missingbitmap != -1) {
      argv.bitmask |= GUESTFS_MD_CREATE_MISSINGBITMAP_BITMASK;
      argv.missingbitmap = missingbitmap;
    }
    GValue nrdevices_v = {0, };
    g_value_init (&nrdevices_v, G_TYPE_INT);
    g_object_get_property (G_OBJECT (optargs), "nrdevices", &nrdevices_v);
    gint32 nrdevices = g_value_get_int (&nrdevices_v);
    if (nrdevices != -1) {
      argv.bitmask |= GUESTFS_MD_CREATE_NRDEVICES_BITMASK;
      argv.nrdevices = nrdevices;
    }
    GValue spare_v = {0, };
    g_value_init (&spare_v, G_TYPE_INT);
    g_object_get_property (G_OBJECT (optargs), "spare", &spare_v);
    gint32 spare = g_value_get_int (&spare_v);
    if (spare != -1) {
      argv.bitmask |= GUESTFS_MD_CREATE_SPARE_BITMASK;
      argv.spare = spare;
    }
    GValue chunk_v = {0, };
    g_value_init (&chunk_v, G_TYPE_INT64);
    g_object_get_property (G_OBJECT (optargs), "chunk", &chunk_v);
    gint64 chunk = g_value_get_int64 (&chunk_v);
    if (chunk != -1) {
      argv.bitmask |= GUESTFS_MD_CREATE_CHUNK_BITMASK;
      argv.chunk = chunk;
    }
    GValue level_v = {0, };
    g_value_init (&level_v, G_TYPE_STRING);
    g_object_get_property (G_OBJECT (optargs), "level", &level_v);
    const gchar *level = g_value_get_string (&level_v);
    if (level != NULL) {
      argv.bitmask |= GUESTFS_MD_CREATE_LEVEL_BITMASK;
      argv.level = level;
    }
    argvp = &argv;
  }
  int ret = guestfs_md_create_argv (g, name, devices, argvp);
  if (ret == -1) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return FALSE;
  }

  return TRUE;
}

/**
 * guestfs_session_md_detail:
 * @session: (transfer none): A GuestfsSession object
 * @md: (transfer none) (type filename):
 * @err: A GError object to receive any generated errors
 *
 * obtain metadata for an MD device
 *
 * This command exposes the output of 'mdadm -DY &lt;md&gt;'. The following
 * fields are usually present in the returned hash. Other fields may also
 * be present.
 * 
 * @level
 * The raid level of the MD device.
 * 
 * @devices
 * The number of underlying devices in the MD device.
 * 
 * @metadata
 * The metadata version used.
 * 
 * @uuid
 * The UUID of the MD device.
 * 
 * @name
 * The name of the MD device.
 * 
 * Returns: (transfer full) (element-type utf8 utf8): a GHashTable of results, or NULL on error
 * Since: 1.15.6
 */
GHashTable *
guestfs_session_md_detail (GuestfsSession *session, const gchar *md, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "md_detail");
    return NULL;
  }

  char **ret = guestfs_md_detail (g, md);
  if (ret == NULL) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return NULL;
  }

  GHashTable *h = g_hash_table_new_full (g_str_hash, g_str_equal, g_free, g_free);
  char **i = ret;
  while (*i) {
    char *key = *i; i++;
    char *value = *i; i++;
    g_hash_table_insert (h, key, value);
  };
  g_free (ret);
  return h;
}

/**
 * guestfs_session_md_stat:
 * @session: (transfer none): A GuestfsSession object
 * @md: (transfer none) (type filename):
 * @err: A GError object to receive any generated errors
 *
 * get underlying devices from an MD device
 *
 * This call returns a list of the underlying devices which make up the
 * single software RAID array device @md.
 * 
 * To get a list of software RAID devices, call
 * guestfs_session_list_md_devices().
 * 
 * Each structure returned corresponds to one device along with additional
 * status information:
 * 
 * @mdstat_device
 * The name of the underlying device.
 * 
 * @mdstat_index
 * The index of this device within the array.
 * 
 * @mdstat_flags
 * Flags associated with this device. This is a string containing (in
 * no specific order) zero or more of the following flags:
 * 
 * @W  write-mostly
 * 
 * @F  device is faulty
 * 
 * @S  device is a RAID spare
 * 
 * @R  replacement
 * 
 * Returns: (transfer full) (array zero-terminated=1) (element-type GuestfsMDStat): an array of MDStat objects, or NULL on error
 * Since: 1.17.21
 */
GuestfsMDStat **
guestfs_session_md_stat (GuestfsSession *session, const gchar *md, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "md_stat");
    return NULL;
  }

  struct guestfs_mdstat_list *ret = guestfs_md_stat (g, md);
  if (ret == NULL) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return NULL;
  }

  GuestfsMDStat **l = g_malloc (sizeof (GuestfsMDStat*) * (ret->len + 1));
  gsize i;
  for (i = 0; i < ret->len; i++) {
    l[i] = g_slice_new0 (GuestfsMDStat);
    if (ret->val[i].mdstat_device) l[i]->mdstat_device = g_strdup (ret->val[i].mdstat_device);
    l[i]->mdstat_index = ret->val[i].mdstat_index;
    if (ret->val[i].mdstat_flags) l[i]->mdstat_flags = g_strdup (ret->val[i].mdstat_flags);
  }
  guestfs_free_mdstat_list (ret);
  l[i] = NULL;
  return l;
}

/**
 * guestfs_session_md_stop:
 * @session: (transfer none): A GuestfsSession object
 * @md: (transfer none) (type filename):
 * @err: A GError object to receive any generated errors
 *
 * stop a Linux md (RAID) device
 *
 * This command deactivates the MD array named @md. The device is stopped,
 * but it is not destroyed or zeroed.
 * 
 * Returns: true on success, false on error
 * Since: 1.15.6
 */
gboolean
guestfs_session_md_stop (GuestfsSession *session, const gchar *md, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "md_stop");
    return FALSE;
  }

  int ret = guestfs_md_stop (g, md);
  if (ret == -1) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return FALSE;
  }

  return TRUE;
}

/**
 * guestfs_session_mkdir:
 * @session: (transfer none): A GuestfsSession object
 * @path: (transfer none) (type filename):
 * @err: A GError object to receive any generated errors
 *
 * create a directory
 *
 * Create a directory named @path.
 * 
 * Returns: true on success, false on error
 * Since: 0.8
 */
gboolean
guestfs_session_mkdir (GuestfsSession *session, const gchar *path, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "mkdir");
    return FALSE;
  }

  int ret = guestfs_mkdir (g, path);
  if (ret == -1) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return FALSE;
  }

  return TRUE;
}

/**
 * guestfs_session_mkdir_mode:
 * @session: (transfer none): A GuestfsSession object
 * @path: (transfer none) (type filename):
 * @mode: (type gint32):
 * @err: A GError object to receive any generated errors
 *
 * create a directory with a particular mode
 *
 * This command creates a directory, setting the initial permissions of the
 * directory to @mode.
 * 
 * For common Linux filesystems, the actual mode which is set will be "mode
 * & ~umask & 01777". Non-native-Linux filesystems may interpret the mode
 * in other ways.
 * 
 * See also guestfs_session_mkdir(), guestfs_session_umask()
 * 
 * Returns: true on success, false on error
 * Since: 1.0.77
 */
gboolean
guestfs_session_mkdir_mode (GuestfsSession *session, const gchar *path, gint32 mode, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "mkdir_mode");
    return FALSE;
  }

  int ret = guestfs_mkdir_mode (g, path, mode);
  if (ret == -1) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return FALSE;
  }

  return TRUE;
}

/**
 * guestfs_session_mkdir_p:
 * @session: (transfer none): A GuestfsSession object
 * @path: (transfer none) (type filename):
 * @err: A GError object to receive any generated errors
 *
 * create a directory and parents
 *
 * Create a directory named @path, creating any parent directories as
 * necessary. This is like the "mkdir -p" shell command.
 * 
 * Returns: true on success, false on error
 * Since: 0.8
 */
gboolean
guestfs_session_mkdir_p (GuestfsSession *session, const gchar *path, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "mkdir_p");
    return FALSE;
  }

  int ret = guestfs_mkdir_p (g, path);
  if (ret == -1) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return FALSE;
  }

  return TRUE;
}

/**
 * guestfs_session_mkdtemp:
 * @session: (transfer none): A GuestfsSession object
 * @tmpl: (transfer none) (type filename):
 * @err: A GError object to receive any generated errors
 *
 * create a temporary directory
 *
 * This command creates a temporary directory. The @tmpl parameter should
 * be a full pathname for the temporary directory name with the final six
 * characters being "XXXXXX".
 * 
 * For example: "/tmp/myprogXXXXXX" or "/Temp/myprogXXXXXX", the second one
 * being suitable for Windows filesystems.
 * 
 * The name of the temporary directory that was created is returned.
 * 
 * The temporary directory is created with mode 0700 and is owned by root.
 * 
 * The caller is responsible for deleting the temporary directory and its
 * contents after use.
 * 
 * See also: mkdtemp(3)
 * 
 * Returns: (transfer full): the returned string, or NULL on error
 * Since: 1.0.54
 */
gchar *
guestfs_session_mkdtemp (GuestfsSession *session, const gchar *tmpl, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "mkdtemp");
    return NULL;
  }

  char *ret = guestfs_mkdtemp (g, tmpl);
  if (ret == NULL) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return NULL;
  }

  return ret;
}

/**
 * guestfs_session_mke2fs:
 * @session: (transfer none): A GuestfsSession object
 * @device: (transfer none) (type filename):
 * @optargs: (transfer none) (allow-none): a GuestfsMke2fs containing optional arguments
 * @err: A GError object to receive any generated errors
 *
 * create an ext2/ext3/ext4 filesystem on device
 *
 * @mke2fs is used to create an ext2, ext3, or ext4 filesystem on @device.
 * 
 * The optional @blockscount is the size of the filesystem in blocks. If
 * omitted it defaults to the size of @device. Note if the filesystem is
 * too small to contain a journal, @mke2fs will silently create an ext2
 * filesystem instead.
 * 
 * Returns: true on success, false on error
 * Since: 1.19.44
 */
gboolean
guestfs_session_mke2fs (GuestfsSession *session, const gchar *device, GuestfsMke2fs *optargs, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "mke2fs");
    return FALSE;
  }

  struct guestfs_mke2fs_argv argv;
  struct guestfs_mke2fs_argv *argvp = NULL;

  if (optargs) {
    argv.bitmask = 0;

    GValue blockscount_v = {0, };
    g_value_init (&blockscount_v, G_TYPE_INT64);
    g_object_get_property (G_OBJECT (optargs), "blockscount", &blockscount_v);
    gint64 blockscount = g_value_get_int64 (&blockscount_v);
    if (blockscount != -1) {
      argv.bitmask |= GUESTFS_MKE2FS_BLOCKSCOUNT_BITMASK;
      argv.blockscount = blockscount;
    }
    GValue blocksize_v = {0, };
    g_value_init (&blocksize_v, G_TYPE_INT64);
    g_object_get_property (G_OBJECT (optargs), "blocksize", &blocksize_v);
    gint64 blocksize = g_value_get_int64 (&blocksize_v);
    if (blocksize != -1) {
      argv.bitmask |= GUESTFS_MKE2FS_BLOCKSIZE_BITMASK;
      argv.blocksize = blocksize;
    }
    GValue fragsize_v = {0, };
    g_value_init (&fragsize_v, G_TYPE_INT64);
    g_object_get_property (G_OBJECT (optargs), "fragsize", &fragsize_v);
    gint64 fragsize = g_value_get_int64 (&fragsize_v);
    if (fragsize != -1) {
      argv.bitmask |= GUESTFS_MKE2FS_FRAGSIZE_BITMASK;
      argv.fragsize = fragsize;
    }
    GValue blockspergroup_v = {0, };
    g_value_init (&blockspergroup_v, G_TYPE_INT64);
    g_object_get_property (G_OBJECT (optargs), "blockspergroup", &blockspergroup_v);
    gint64 blockspergroup = g_value_get_int64 (&blockspergroup_v);
    if (blockspergroup != -1) {
      argv.bitmask |= GUESTFS_MKE2FS_BLOCKSPERGROUP_BITMASK;
      argv.blockspergroup = blockspergroup;
    }
    GValue numberofgroups_v = {0, };
    g_value_init (&numberofgroups_v, G_TYPE_INT64);
    g_object_get_property (G_OBJECT (optargs), "numberofgroups", &numberofgroups_v);
    gint64 numberofgroups = g_value_get_int64 (&numberofgroups_v);
    if (numberofgroups != -1) {
      argv.bitmask |= GUESTFS_MKE2FS_NUMBEROFGROUPS_BITMASK;
      argv.numberofgroups = numberofgroups;
    }
    GValue bytesperinode_v = {0, };
    g_value_init (&bytesperinode_v, G_TYPE_INT64);
    g_object_get_property (G_OBJECT (optargs), "bytesperinode", &bytesperinode_v);
    gint64 bytesperinode = g_value_get_int64 (&bytesperinode_v);
    if (bytesperinode != -1) {
      argv.bitmask |= GUESTFS_MKE2FS_BYTESPERINODE_BITMASK;
      argv.bytesperinode = bytesperinode;
    }
    GValue inodesize_v = {0, };
    g_value_init (&inodesize_v, G_TYPE_INT64);
    g_object_get_property (G_OBJECT (optargs), "inodesize", &inodesize_v);
    gint64 inodesize = g_value_get_int64 (&inodesize_v);
    if (inodesize != -1) {
      argv.bitmask |= GUESTFS_MKE2FS_INODESIZE_BITMASK;
      argv.inodesize = inodesize;
    }
    GValue journalsize_v = {0, };
    g_value_init (&journalsize_v, G_TYPE_INT64);
    g_object_get_property (G_OBJECT (optargs), "journalsize", &journalsize_v);
    gint64 journalsize = g_value_get_int64 (&journalsize_v);
    if (journalsize != -1) {
      argv.bitmask |= GUESTFS_MKE2FS_JOURNALSIZE_BITMASK;
      argv.journalsize = journalsize;
    }
    GValue numberofinodes_v = {0, };
    g_value_init (&numberofinodes_v, G_TYPE_INT64);
    g_object_get_property (G_OBJECT (optargs), "numberofinodes", &numberofinodes_v);
    gint64 numberofinodes = g_value_get_int64 (&numberofinodes_v);
    if (numberofinodes != -1) {
      argv.bitmask |= GUESTFS_MKE2FS_NUMBEROFINODES_BITMASK;
      argv.numberofinodes = numberofinodes;
    }
    GValue stridesize_v = {0, };
    g_value_init (&stridesize_v, G_TYPE_INT64);
    g_object_get_property (G_OBJECT (optargs), "stridesize", &stridesize_v);
    gint64 stridesize = g_value_get_int64 (&stridesize_v);
    if (stridesize != -1) {
      argv.bitmask |= GUESTFS_MKE2FS_STRIDESIZE_BITMASK;
      argv.stridesize = stridesize;
    }
    GValue stripewidth_v = {0, };
    g_value_init (&stripewidth_v, G_TYPE_INT64);
    g_object_get_property (G_OBJECT (optargs), "stripewidth", &stripewidth_v);
    gint64 stripewidth = g_value_get_int64 (&stripewidth_v);
    if (stripewidth != -1) {
      argv.bitmask |= GUESTFS_MKE2FS_STRIPEWIDTH_BITMASK;
      argv.stripewidth = stripewidth;
    }
    GValue maxonlineresize_v = {0, };
    g_value_init (&maxonlineresize_v, G_TYPE_INT64);
    g_object_get_property (G_OBJECT (optargs), "maxonlineresize", &maxonlineresize_v);
    gint64 maxonlineresize = g_value_get_int64 (&maxonlineresize_v);
    if (maxonlineresize != -1) {
      argv.bitmask |= GUESTFS_MKE2FS_MAXONLINERESIZE_BITMASK;
      argv.maxonlineresize = maxonlineresize;
    }
    GValue reservedblockspercentage_v = {0, };
    g_value_init (&reservedblockspercentage_v, G_TYPE_INT);
    g_object_get_property (G_OBJECT (optargs), "reservedblockspercentage", &reservedblockspercentage_v);
    gint32 reservedblockspercentage = g_value_get_int (&reservedblockspercentage_v);
    if (reservedblockspercentage != -1) {
      argv.bitmask |= GUESTFS_MKE2FS_RESERVEDBLOCKSPERCENTAGE_BITMASK;
      argv.reservedblockspercentage = reservedblockspercentage;
    }
    GValue mmpupdateinterval_v = {0, };
    g_value_init (&mmpupdateinterval_v, G_TYPE_INT);
    g_object_get_property (G_OBJECT (optargs), "mmpupdateinterval", &mmpupdateinterval_v);
    gint32 mmpupdateinterval = g_value_get_int (&mmpupdateinterval_v);
    if (mmpupdateinterval != -1) {
      argv.bitmask |= GUESTFS_MKE2FS_MMPUPDATEINTERVAL_BITMASK;
      argv.mmpupdateinterval = mmpupdateinterval;
    }
    GValue journaldevice_v = {0, };
    g_value_init (&journaldevice_v, G_TYPE_STRING);
    g_object_get_property (G_OBJECT (optargs), "journaldevice", &journaldevice_v);
    const gchar *journaldevice = g_value_get_string (&journaldevice_v);
    if (journaldevice != NULL) {
      argv.bitmask |= GUESTFS_MKE2FS_JOURNALDEVICE_BITMASK;
      argv.journaldevice = journaldevice;
    }
    GValue label_v = {0, };
    g_value_init (&label_v, G_TYPE_STRING);
    g_object_get_property (G_OBJECT (optargs), "label", &label_v);
    const gchar *label = g_value_get_string (&label_v);
    if (label != NULL) {
      argv.bitmask |= GUESTFS_MKE2FS_LABEL_BITMASK;
      argv.label = label;
    }
    GValue lastmounteddir_v = {0, };
    g_value_init (&lastmounteddir_v, G_TYPE_STRING);
    g_object_get_property (G_OBJECT (optargs), "lastmounteddir", &lastmounteddir_v);
    const gchar *lastmounteddir = g_value_get_string (&lastmounteddir_v);
    if (lastmounteddir != NULL) {
      argv.bitmask |= GUESTFS_MKE2FS_LASTMOUNTEDDIR_BITMASK;
      argv.lastmounteddir = lastmounteddir;
    }
    GValue creatoros_v = {0, };
    g_value_init (&creatoros_v, G_TYPE_STRING);
    g_object_get_property (G_OBJECT (optargs), "creatoros", &creatoros_v);
    const gchar *creatoros = g_value_get_string (&creatoros_v);
    if (creatoros != NULL) {
      argv.bitmask |= GUESTFS_MKE2FS_CREATOROS_BITMASK;
      argv.creatoros = creatoros;
    }
    GValue fstype_v = {0, };
    g_value_init (&fstype_v, G_TYPE_STRING);
    g_object_get_property (G_OBJECT (optargs), "fstype", &fstype_v);
    const gchar *fstype = g_value_get_string (&fstype_v);
    if (fstype != NULL) {
      argv.bitmask |= GUESTFS_MKE2FS_FSTYPE_BITMASK;
      argv.fstype = fstype;
    }
    GValue usagetype_v = {0, };
    g_value_init (&usagetype_v, G_TYPE_STRING);
    g_object_get_property (G_OBJECT (optargs), "usagetype", &usagetype_v);
    const gchar *usagetype = g_value_get_string (&usagetype_v);
    if (usagetype != NULL) {
      argv.bitmask |= GUESTFS_MKE2FS_USAGETYPE_BITMASK;
      argv.usagetype = usagetype;
    }
    GValue uuid_v = {0, };
    g_value_init (&uuid_v, G_TYPE_STRING);
    g_object_get_property (G_OBJECT (optargs), "uuid", &uuid_v);
    const gchar *uuid = g_value_get_string (&uuid_v);
    if (uuid != NULL) {
      argv.bitmask |= GUESTFS_MKE2FS_UUID_BITMASK;
      argv.uuid = uuid;
    }
    GValue forcecreate_v = {0, };
    g_value_init (&forcecreate_v, GUESTFS_TYPE_TRISTATE);
    g_object_get_property (G_OBJECT (optargs), "forcecreate", &forcecreate_v);
    GuestfsTristate forcecreate = g_value_get_enum (&forcecreate_v);
    if (forcecreate != GUESTFS_TRISTATE_NONE) {
      argv.bitmask |= GUESTFS_MKE2FS_FORCECREATE_BITMASK;
      argv.forcecreate = forcecreate;
    }
    GValue writesbandgrouponly_v = {0, };
    g_value_init (&writesbandgrouponly_v, GUESTFS_TYPE_TRISTATE);
    g_object_get_property (G_OBJECT (optargs), "writesbandgrouponly", &writesbandgrouponly_v);
    GuestfsTristate writesbandgrouponly = g_value_get_enum (&writesbandgrouponly_v);
    if (writesbandgrouponly != GUESTFS_TRISTATE_NONE) {
      argv.bitmask |= GUESTFS_MKE2FS_WRITESBANDGROUPONLY_BITMASK;
      argv.writesbandgrouponly = writesbandgrouponly;
    }
    GValue lazyitableinit_v = {0, };
    g_value_init (&lazyitableinit_v, GUESTFS_TYPE_TRISTATE);
    g_object_get_property (G_OBJECT (optargs), "lazyitableinit", &lazyitableinit_v);
    GuestfsTristate lazyitableinit = g_value_get_enum (&lazyitableinit_v);
    if (lazyitableinit != GUESTFS_TRISTATE_NONE) {
      argv.bitmask |= GUESTFS_MKE2FS_LAZYITABLEINIT_BITMASK;
      argv.lazyitableinit = lazyitableinit;
    }
    GValue lazyjournalinit_v = {0, };
    g_value_init (&lazyjournalinit_v, GUESTFS_TYPE_TRISTATE);
    g_object_get_property (G_OBJECT (optargs), "lazyjournalinit", &lazyjournalinit_v);
    GuestfsTristate lazyjournalinit = g_value_get_enum (&lazyjournalinit_v);
    if (lazyjournalinit != GUESTFS_TRISTATE_NONE) {
      argv.bitmask |= GUESTFS_MKE2FS_LAZYJOURNALINIT_BITMASK;
      argv.lazyjournalinit = lazyjournalinit;
    }
    GValue testfs_v = {0, };
    g_value_init (&testfs_v, GUESTFS_TYPE_TRISTATE);
    g_object_get_property (G_OBJECT (optargs), "testfs", &testfs_v);
    GuestfsTristate testfs = g_value_get_enum (&testfs_v);
    if (testfs != GUESTFS_TRISTATE_NONE) {
      argv.bitmask |= GUESTFS_MKE2FS_TESTFS_BITMASK;
      argv.testfs = testfs;
    }
    GValue discard_v = {0, };
    g_value_init (&discard_v, GUESTFS_TYPE_TRISTATE);
    g_object_get_property (G_OBJECT (optargs), "discard", &discard_v);
    GuestfsTristate discard = g_value_get_enum (&discard_v);
    if (discard != GUESTFS_TRISTATE_NONE) {
      argv.bitmask |= GUESTFS_MKE2FS_DISCARD_BITMASK;
      argv.discard = discard;
    }
    GValue quotatype_v = {0, };
    g_value_init (&quotatype_v, GUESTFS_TYPE_TRISTATE);
    g_object_get_property (G_OBJECT (optargs), "quotatype", &quotatype_v);
    GuestfsTristate quotatype = g_value_get_enum (&quotatype_v);
    if (quotatype != GUESTFS_TRISTATE_NONE) {
      argv.bitmask |= GUESTFS_MKE2FS_QUOTATYPE_BITMASK;
      argv.quotatype = quotatype;
    }
    GValue extent_v = {0, };
    g_value_init (&extent_v, GUESTFS_TYPE_TRISTATE);
    g_object_get_property (G_OBJECT (optargs), "extent", &extent_v);
    GuestfsTristate extent = g_value_get_enum (&extent_v);
    if (extent != GUESTFS_TRISTATE_NONE) {
      argv.bitmask |= GUESTFS_MKE2FS_EXTENT_BITMASK;
      argv.extent = extent;
    }
    GValue filetype_v = {0, };
    g_value_init (&filetype_v, GUESTFS_TYPE_TRISTATE);
    g_object_get_property (G_OBJECT (optargs), "filetype", &filetype_v);
    GuestfsTristate filetype = g_value_get_enum (&filetype_v);
    if (filetype != GUESTFS_TRISTATE_NONE) {
      argv.bitmask |= GUESTFS_MKE2FS_FILETYPE_BITMASK;
      argv.filetype = filetype;
    }
    GValue flexbg_v = {0, };
    g_value_init (&flexbg_v, GUESTFS_TYPE_TRISTATE);
    g_object_get_property (G_OBJECT (optargs), "flexbg", &flexbg_v);
    GuestfsTristate flexbg = g_value_get_enum (&flexbg_v);
    if (flexbg != GUESTFS_TRISTATE_NONE) {
      argv.bitmask |= GUESTFS_MKE2FS_FLEXBG_BITMASK;
      argv.flexbg = flexbg;
    }
    GValue hasjournal_v = {0, };
    g_value_init (&hasjournal_v, GUESTFS_TYPE_TRISTATE);
    g_object_get_property (G_OBJECT (optargs), "hasjournal", &hasjournal_v);
    GuestfsTristate hasjournal = g_value_get_enum (&hasjournal_v);
    if (hasjournal != GUESTFS_TRISTATE_NONE) {
      argv.bitmask |= GUESTFS_MKE2FS_HASJOURNAL_BITMASK;
      argv.hasjournal = hasjournal;
    }
    GValue journaldev_v = {0, };
    g_value_init (&journaldev_v, GUESTFS_TYPE_TRISTATE);
    g_object_get_property (G_OBJECT (optargs), "journaldev", &journaldev_v);
    GuestfsTristate journaldev = g_value_get_enum (&journaldev_v);
    if (journaldev != GUESTFS_TRISTATE_NONE) {
      argv.bitmask |= GUESTFS_MKE2FS_JOURNALDEV_BITMASK;
      argv.journaldev = journaldev;
    }
    GValue largefile_v = {0, };
    g_value_init (&largefile_v, GUESTFS_TYPE_TRISTATE);
    g_object_get_property (G_OBJECT (optargs), "largefile", &largefile_v);
    GuestfsTristate largefile = g_value_get_enum (&largefile_v);
    if (largefile != GUESTFS_TRISTATE_NONE) {
      argv.bitmask |= GUESTFS_MKE2FS_LARGEFILE_BITMASK;
      argv.largefile = largefile;
    }
    GValue quota_v = {0, };
    g_value_init (&quota_v, GUESTFS_TYPE_TRISTATE);
    g_object_get_property (G_OBJECT (optargs), "quota", &quota_v);
    GuestfsTristate quota = g_value_get_enum (&quota_v);
    if (quota != GUESTFS_TRISTATE_NONE) {
      argv.bitmask |= GUESTFS_MKE2FS_QUOTA_BITMASK;
      argv.quota = quota;
    }
    GValue resizeinode_v = {0, };
    g_value_init (&resizeinode_v, GUESTFS_TYPE_TRISTATE);
    g_object_get_property (G_OBJECT (optargs), "resizeinode", &resizeinode_v);
    GuestfsTristate resizeinode = g_value_get_enum (&resizeinode_v);
    if (resizeinode != GUESTFS_TRISTATE_NONE) {
      argv.bitmask |= GUESTFS_MKE2FS_RESIZEINODE_BITMASK;
      argv.resizeinode = resizeinode;
    }
    GValue sparsesuper_v = {0, };
    g_value_init (&sparsesuper_v, GUESTFS_TYPE_TRISTATE);
    g_object_get_property (G_OBJECT (optargs), "sparsesuper", &sparsesuper_v);
    GuestfsTristate sparsesuper = g_value_get_enum (&sparsesuper_v);
    if (sparsesuper != GUESTFS_TRISTATE_NONE) {
      argv.bitmask |= GUESTFS_MKE2FS_SPARSESUPER_BITMASK;
      argv.sparsesuper = sparsesuper;
    }
    GValue uninitbg_v = {0, };
    g_value_init (&uninitbg_v, GUESTFS_TYPE_TRISTATE);
    g_object_get_property (G_OBJECT (optargs), "uninitbg", &uninitbg_v);
    GuestfsTristate uninitbg = g_value_get_enum (&uninitbg_v);
    if (uninitbg != GUESTFS_TRISTATE_NONE) {
      argv.bitmask |= GUESTFS_MKE2FS_UNINITBG_BITMASK;
      argv.uninitbg = uninitbg;
    }
    argvp = &argv;
  }
  int ret = guestfs_mke2fs_argv (g, device, argvp);
  if (ret == -1) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return FALSE;
  }

  return TRUE;
}

/**
 * guestfs_session_mke2fs_J:
 * @session: (transfer none): A GuestfsSession object
 * @fstype: (transfer none) (type utf8):
 * @blocksize: (type gint32):
 * @device: (transfer none) (type filename):
 * @journal: (transfer none) (type filename):
 * @err: A GError object to receive any generated errors
 *
 * make ext2/3/4 filesystem with external journal
 *
 * This creates an ext2/3/4 filesystem on @device with an external journal
 * on @journal. It is equivalent to the command:
 * 
 * <![CDATA[mke2fs -t fstype -b blocksize -J device=<journal> <device>]]>
 * 
 * See also guestfs_session_mke2journal().
 * 
 * Returns: true on success, false on error
 * Deprecated: In new code, use guestfs_session_mke2fs() instead
 * Since: 1.0.68
 */
gboolean
guestfs_session_mke2fs_J (GuestfsSession *session, const gchar *fstype, gint32 blocksize, const gchar *device, const gchar *journal, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "mke2fs_J");
    return FALSE;
  }

  int ret = guestfs_mke2fs_J (g, fstype, blocksize, device, journal);
  if (ret == -1) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return FALSE;
  }

  return TRUE;
}

/**
 * guestfs_session_mke2fs_JL:
 * @session: (transfer none): A GuestfsSession object
 * @fstype: (transfer none) (type utf8):
 * @blocksize: (type gint32):
 * @device: (transfer none) (type filename):
 * @label: (transfer none) (type utf8):
 * @err: A GError object to receive any generated errors
 *
 * make ext2/3/4 filesystem with external journal
 *
 * This creates an ext2/3/4 filesystem on @device with an external journal
 * on the journal labeled @label.
 * 
 * See also guestfs_session_mke2journal_L().
 * 
 * Returns: true on success, false on error
 * Deprecated: In new code, use guestfs_session_mke2fs() instead
 * Since: 1.0.68
 */
gboolean
guestfs_session_mke2fs_JL (GuestfsSession *session, const gchar *fstype, gint32 blocksize, const gchar *device, const gchar *label, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "mke2fs_JL");
    return FALSE;
  }

  int ret = guestfs_mke2fs_JL (g, fstype, blocksize, device, label);
  if (ret == -1) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return FALSE;
  }

  return TRUE;
}

/**
 * guestfs_session_mke2fs_JU:
 * @session: (transfer none): A GuestfsSession object
 * @fstype: (transfer none) (type utf8):
 * @blocksize: (type gint32):
 * @device: (transfer none) (type filename):
 * @uuid: (transfer none) (type utf8):
 * @err: A GError object to receive any generated errors
 *
 * make ext2/3/4 filesystem with external journal
 *
 * This creates an ext2/3/4 filesystem on @device with an external journal
 * on the journal with UUID @uuid.
 * 
 * See also guestfs_session_mke2journal_U().
 * 
 * Returns: true on success, false on error
 * Deprecated: In new code, use guestfs_session_mke2fs() instead
 * Since: 1.0.68
 */
gboolean
guestfs_session_mke2fs_JU (GuestfsSession *session, const gchar *fstype, gint32 blocksize, const gchar *device, const gchar *uuid, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "mke2fs_JU");
    return FALSE;
  }

  int ret = guestfs_mke2fs_JU (g, fstype, blocksize, device, uuid);
  if (ret == -1) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return FALSE;
  }

  return TRUE;
}

/**
 * guestfs_session_mke2journal:
 * @session: (transfer none): A GuestfsSession object
 * @blocksize: (type gint32):
 * @device: (transfer none) (type filename):
 * @err: A GError object to receive any generated errors
 *
 * make ext2/3/4 external journal
 *
 * This creates an ext2 external journal on @device. It is equivalent to
 * the command:
 * 
 * <![CDATA[mke2fs -O journal_dev -b blocksize device]]>
 * 
 * Returns: true on success, false on error
 * Deprecated: In new code, use guestfs_session_mke2fs() instead
 * Since: 1.0.68
 */
gboolean
guestfs_session_mke2journal (GuestfsSession *session, gint32 blocksize, const gchar *device, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "mke2journal");
    return FALSE;
  }

  int ret = guestfs_mke2journal (g, blocksize, device);
  if (ret == -1) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return FALSE;
  }

  return TRUE;
}

/**
 * guestfs_session_mke2journal_L:
 * @session: (transfer none): A GuestfsSession object
 * @blocksize: (type gint32):
 * @label: (transfer none) (type utf8):
 * @device: (transfer none) (type filename):
 * @err: A GError object to receive any generated errors
 *
 * make ext2/3/4 external journal with label
 *
 * This creates an ext2 external journal on @device with label @label.
 * 
 * Returns: true on success, false on error
 * Deprecated: In new code, use guestfs_session_mke2fs() instead
 * Since: 1.0.68
 */
gboolean
guestfs_session_mke2journal_L (GuestfsSession *session, gint32 blocksize, const gchar *label, const gchar *device, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "mke2journal_L");
    return FALSE;
  }

  int ret = guestfs_mke2journal_L (g, blocksize, label, device);
  if (ret == -1) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return FALSE;
  }

  return TRUE;
}

/**
 * guestfs_session_mke2journal_U:
 * @session: (transfer none): A GuestfsSession object
 * @blocksize: (type gint32):
 * @uuid: (transfer none) (type utf8):
 * @device: (transfer none) (type filename):
 * @err: A GError object to receive any generated errors
 *
 * make ext2/3/4 external journal with UUID
 *
 * This creates an ext2 external journal on @device with UUID @uuid.
 * 
 * Returns: true on success, false on error
 * Deprecated: In new code, use guestfs_session_mke2fs() instead
 * Since: 1.0.68
 */
gboolean
guestfs_session_mke2journal_U (GuestfsSession *session, gint32 blocksize, const gchar *uuid, const gchar *device, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "mke2journal_U");
    return FALSE;
  }

  int ret = guestfs_mke2journal_U (g, blocksize, uuid, device);
  if (ret == -1) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return FALSE;
  }

  return TRUE;
}

/**
 * guestfs_session_mkfifo:
 * @session: (transfer none): A GuestfsSession object
 * @mode: (type gint32):
 * @path: (transfer none) (type filename):
 * @err: A GError object to receive any generated errors
 *
 * make FIFO (named pipe)
 *
 * This call creates a FIFO (named pipe) called @path with mode @mode. It
 * is just a convenient wrapper around guestfs_session_mknod().
 * 
 * Unlike with guestfs_session_mknod(), @mode must contain only permissions
 * bits.
 * 
 * The mode actually set is affected by the umask.
 * 
 * Returns: true on success, false on error
 * Since: 1.0.55
 */
gboolean
guestfs_session_mkfifo (GuestfsSession *session, gint32 mode, const gchar *path, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "mkfifo");
    return FALSE;
  }

  int ret = guestfs_mkfifo (g, mode, path);
  if (ret == -1) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return FALSE;
  }

  return TRUE;
}

/**
 * guestfs_session_mkfs:
 * @session: (transfer none): A GuestfsSession object
 * @fstype: (transfer none) (type utf8):
 * @device: (transfer none) (type filename):
 * @optargs: (transfer none) (allow-none): a GuestfsMkfs containing optional arguments
 * @err: A GError object to receive any generated errors
 *
 * make a filesystem
 *
 * This function creates a filesystem on @device. The filesystem type is
 * @fstype, for example @ext3.
 * 
 * The optional arguments are:
 * 
 * @blocksize
 * The filesystem block size. Supported block sizes depend on the
 * filesystem type, but typically they are @1024, @2048 or @4096 for
 * Linux ext2/3 filesystems.
 * 
 * For VFAT and NTFS the @blocksize parameter is treated as the
 * requested cluster size.
 * 
 * For UFS block sizes, please see mkfs.ufs(8).
 * 
 * @features
 * This passes the *-O* parameter to the external mkfs program.
 * 
 * For certain filesystem types, this allows extra filesystem features
 * to be selected. See mke2fs(8) and mkfs.ufs(8) for more details.
 * 
 * You cannot use this optional parameter with the @gfs or @gfs2
 * filesystem type.
 * 
 * @inode
 * This passes the *-I* parameter to the external mke2fs(8) program
 * which sets the inode size (only for ext2/3/4 filesystems at
 * present).
 * 
 * @sectorsize
 * This passes the *-S* parameter to external mkfs.ufs(8) program,
 * which sets sector size for ufs filesystem.
 * 
 * Returns: true on success, false on error
 * Since: 0.8
 */
gboolean
guestfs_session_mkfs (GuestfsSession *session, const gchar *fstype, const gchar *device, GuestfsMkfs *optargs, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "mkfs");
    return FALSE;
  }

  struct guestfs_mkfs_opts_argv argv;
  struct guestfs_mkfs_opts_argv *argvp = NULL;

  if (optargs) {
    argv.bitmask = 0;

    GValue blocksize_v = {0, };
    g_value_init (&blocksize_v, G_TYPE_INT);
    g_object_get_property (G_OBJECT (optargs), "blocksize", &blocksize_v);
    gint32 blocksize = g_value_get_int (&blocksize_v);
    if (blocksize != -1) {
      argv.bitmask |= GUESTFS_MKFS_OPTS_BLOCKSIZE_BITMASK;
      argv.blocksize = blocksize;
    }
    GValue features_v = {0, };
    g_value_init (&features_v, G_TYPE_STRING);
    g_object_get_property (G_OBJECT (optargs), "features", &features_v);
    const gchar *features = g_value_get_string (&features_v);
    if (features != NULL) {
      argv.bitmask |= GUESTFS_MKFS_OPTS_FEATURES_BITMASK;
      argv.features = features;
    }
    GValue inode_v = {0, };
    g_value_init (&inode_v, G_TYPE_INT);
    g_object_get_property (G_OBJECT (optargs), "inode", &inode_v);
    gint32 inode = g_value_get_int (&inode_v);
    if (inode != -1) {
      argv.bitmask |= GUESTFS_MKFS_OPTS_INODE_BITMASK;
      argv.inode = inode;
    }
    GValue sectorsize_v = {0, };
    g_value_init (&sectorsize_v, G_TYPE_INT);
    g_object_get_property (G_OBJECT (optargs), "sectorsize", &sectorsize_v);
    gint32 sectorsize = g_value_get_int (&sectorsize_v);
    if (sectorsize != -1) {
      argv.bitmask |= GUESTFS_MKFS_OPTS_SECTORSIZE_BITMASK;
      argv.sectorsize = sectorsize;
    }
    GValue label_v = {0, };
    g_value_init (&label_v, G_TYPE_STRING);
    g_object_get_property (G_OBJECT (optargs), "label", &label_v);
    const gchar *label = g_value_get_string (&label_v);
    if (label != NULL) {
      argv.bitmask |= GUESTFS_MKFS_OPTS_LABEL_BITMASK;
      argv.label = label;
    }
    argvp = &argv;
  }
  int ret = guestfs_mkfs_opts_argv (g, fstype, device, argvp);
  if (ret == -1) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return FALSE;
  }

  return TRUE;
}

/**
 * guestfs_session_mkfs_b:
 * @session: (transfer none): A GuestfsSession object
 * @fstype: (transfer none) (type utf8):
 * @blocksize: (type gint32):
 * @device: (transfer none) (type filename):
 * @err: A GError object to receive any generated errors
 *
 * make a filesystem with block size
 *
 * This call is similar to guestfs_session_mkfs(), but it allows you to
 * control the block size of the resulting filesystem. Supported block
 * sizes depend on the filesystem type, but typically they are @1024, @2048
 * or @4096 only.
 * 
 * For VFAT and NTFS the @blocksize parameter is treated as the requested
 * cluster size.
 * 
 * Returns: true on success, false on error
 * Deprecated: In new code, use guestfs_session_mkfs() instead
 * Since: 1.0.68
 */
gboolean
guestfs_session_mkfs_b (GuestfsSession *session, const gchar *fstype, gint32 blocksize, const gchar *device, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "mkfs_b");
    return FALSE;
  }

  int ret = guestfs_mkfs_b (g, fstype, blocksize, device);
  if (ret == -1) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return FALSE;
  }

  return TRUE;
}

/**
 * guestfs_session_mkfs_btrfs:
 * @session: (transfer none): A GuestfsSession object
 * @devices: (transfer none) (array zero-terminated=1) (element-type filename): an array of strings
 * @optargs: (transfer none) (allow-none): a GuestfsMkfsBtrfs containing optional arguments
 * @err: A GError object to receive any generated errors
 *
 * create a btrfs filesystem
 *
 * Create a btrfs filesystem, allowing all configurables to be set. For
 * more information on the optional arguments, see mkfs.btrfs(8).
 * 
 * Since btrfs filesystems can span multiple devices, this takes a
 * non-empty list of devices.
 * 
 * To create general filesystems, use guestfs_session_mkfs().
 * 
 * Returns: true on success, false on error
 * Since: 1.17.25
 */
gboolean
guestfs_session_mkfs_btrfs (GuestfsSession *session, gchar *const *devices, GuestfsMkfsBtrfs *optargs, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "mkfs_btrfs");
    return FALSE;
  }

  struct guestfs_mkfs_btrfs_argv argv;
  struct guestfs_mkfs_btrfs_argv *argvp = NULL;

  if (optargs) {
    argv.bitmask = 0;

    GValue allocstart_v = {0, };
    g_value_init (&allocstart_v, G_TYPE_INT64);
    g_object_get_property (G_OBJECT (optargs), "allocstart", &allocstart_v);
    gint64 allocstart = g_value_get_int64 (&allocstart_v);
    if (allocstart != -1) {
      argv.bitmask |= GUESTFS_MKFS_BTRFS_ALLOCSTART_BITMASK;
      argv.allocstart = allocstart;
    }
    GValue bytecount_v = {0, };
    g_value_init (&bytecount_v, G_TYPE_INT64);
    g_object_get_property (G_OBJECT (optargs), "bytecount", &bytecount_v);
    gint64 bytecount = g_value_get_int64 (&bytecount_v);
    if (bytecount != -1) {
      argv.bitmask |= GUESTFS_MKFS_BTRFS_BYTECOUNT_BITMASK;
      argv.bytecount = bytecount;
    }
    GValue datatype_v = {0, };
    g_value_init (&datatype_v, G_TYPE_STRING);
    g_object_get_property (G_OBJECT (optargs), "datatype", &datatype_v);
    const gchar *datatype = g_value_get_string (&datatype_v);
    if (datatype != NULL) {
      argv.bitmask |= GUESTFS_MKFS_BTRFS_DATATYPE_BITMASK;
      argv.datatype = datatype;
    }
    GValue leafsize_v = {0, };
    g_value_init (&leafsize_v, G_TYPE_INT);
    g_object_get_property (G_OBJECT (optargs), "leafsize", &leafsize_v);
    gint32 leafsize = g_value_get_int (&leafsize_v);
    if (leafsize != -1) {
      argv.bitmask |= GUESTFS_MKFS_BTRFS_LEAFSIZE_BITMASK;
      argv.leafsize = leafsize;
    }
    GValue label_v = {0, };
    g_value_init (&label_v, G_TYPE_STRING);
    g_object_get_property (G_OBJECT (optargs), "label", &label_v);
    const gchar *label = g_value_get_string (&label_v);
    if (label != NULL) {
      argv.bitmask |= GUESTFS_MKFS_BTRFS_LABEL_BITMASK;
      argv.label = label;
    }
    GValue metadata_v = {0, };
    g_value_init (&metadata_v, G_TYPE_STRING);
    g_object_get_property (G_OBJECT (optargs), "metadata", &metadata_v);
    const gchar *metadata = g_value_get_string (&metadata_v);
    if (metadata != NULL) {
      argv.bitmask |= GUESTFS_MKFS_BTRFS_METADATA_BITMASK;
      argv.metadata = metadata;
    }
    GValue nodesize_v = {0, };
    g_value_init (&nodesize_v, G_TYPE_INT);
    g_object_get_property (G_OBJECT (optargs), "nodesize", &nodesize_v);
    gint32 nodesize = g_value_get_int (&nodesize_v);
    if (nodesize != -1) {
      argv.bitmask |= GUESTFS_MKFS_BTRFS_NODESIZE_BITMASK;
      argv.nodesize = nodesize;
    }
    GValue sectorsize_v = {0, };
    g_value_init (&sectorsize_v, G_TYPE_INT);
    g_object_get_property (G_OBJECT (optargs), "sectorsize", &sectorsize_v);
    gint32 sectorsize = g_value_get_int (&sectorsize_v);
    if (sectorsize != -1) {
      argv.bitmask |= GUESTFS_MKFS_BTRFS_SECTORSIZE_BITMASK;
      argv.sectorsize = sectorsize;
    }
    argvp = &argv;
  }
  int ret = guestfs_mkfs_btrfs_argv (g, devices, argvp);
  if (ret == -1) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return FALSE;
  }

  return TRUE;
}

/**
 * guestfs_session_mklost_and_found:
 * @session: (transfer none): A GuestfsSession object
 * @mountpoint: (transfer none) (type filename):
 * @err: A GError object to receive any generated errors
 *
 * make lost+found directory on an ext2/3/4 filesystem
 *
 * Make the "lost+found" directory, normally in the root directory of an
 * ext2/3/4 filesystem. @mountpoint is the directory under which we try to
 * create the "lost+found" directory.
 * 
 * Returns: true on success, false on error
 * Since: 1.19.56
 */
gboolean
guestfs_session_mklost_and_found (GuestfsSession *session, const gchar *mountpoint, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "mklost_and_found");
    return FALSE;
  }

  int ret = guestfs_mklost_and_found (g, mountpoint);
  if (ret == -1) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return FALSE;
  }

  return TRUE;
}

/**
 * guestfs_session_mkmountpoint:
 * @session: (transfer none): A GuestfsSession object
 * @exemptpath: (transfer none) (type utf8):
 * @err: A GError object to receive any generated errors
 *
 * create a mountpoint
 *
 * guestfs_session_mkmountpoint() and guestfs_session_rmmountpoint() are
 * specialized calls that can be used to create extra mountpoints before
 * mounting the first filesystem.
 * 
 * These calls are *only* necessary in some very limited circumstances,
 * mainly the case where you want to mount a mix of unrelated and/or
 * read-only filesystems together.
 * 
 * For example, live CDs often contain a "Russian doll" nest of
 * filesystems, an ISO outer layer, with a squashfs image inside, with an
 * ext2/3 image inside that. You can unpack this as follows in guestfish:
 * 
 * <![CDATA[add-ro Fedora-11-i686-Live.iso]]>
 * 
 * <![CDATA[run]]>
 * 
 * <![CDATA[mkmountpoint /cd]]>
 * 
 * <![CDATA[mkmountpoint /sqsh]]>
 * 
 * <![CDATA[mkmountpoint /ext3fs]]>
 * 
 * <![CDATA[mount /dev/sda /cd]]>
 * 
 * <![CDATA[mount-loop /cd/LiveOS/squashfs.img /sqsh]]>
 * 
 * <![CDATA[mount-loop /sqsh/LiveOS/ext3fs.img /ext3fs]]>
 * 
 * The inner filesystem is now unpacked under the /ext3fs mountpoint.
 * 
 * guestfs_session_mkmountpoint() is not compatible with
 * guestfs_session_umount_all(). You may get unexpected errors if you try
 * to mix these calls. It is safest to manually unmount filesystems and
 * remove mountpoints after use.
 * 
 * guestfs_session_umount_all() unmounts filesystems by sorting the paths
 * longest first, so for this to work for manual mountpoints, you must
 * ensure that the innermost mountpoints have the longest pathnames, as in
 * the example code above.
 * 
 * For more details see <ulink
 * url='https://bugzilla.redhat.com/show_bug.cgi?id=599503'>
 * http://bugzilla.redhat.com/show_bug.cgi?id=599503 </ulink>
 * 
 * Autosync [see guestfs_session_set_autosync(), this is set by default on
 * handles] can cause guestfs_session_umount_all() to be called when the
 * handle is closed which can also trigger these issues.
 * 
 * Returns: true on success, false on error
 * Since: 1.0.62
 */
gboolean
guestfs_session_mkmountpoint (GuestfsSession *session, const gchar *exemptpath, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "mkmountpoint");
    return FALSE;
  }

  int ret = guestfs_mkmountpoint (g, exemptpath);
  if (ret == -1) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return FALSE;
  }

  return TRUE;
}

/**
 * guestfs_session_mknod:
 * @session: (transfer none): A GuestfsSession object
 * @mode: (type gint32):
 * @devmajor: (type gint32):
 * @devminor: (type gint32):
 * @path: (transfer none) (type filename):
 * @err: A GError object to receive any generated errors
 *
 * make block, character or FIFO devices
 *
 * This call creates block or character special devices, or named pipes
 * (FIFOs).
 * 
 * The @mode parameter should be the mode, using the standard constants.
 * @devmajor and @devminor are the device major and minor numbers, only
 * used when creating block and character special devices.
 * 
 * Note that, just like mknod(2), the mode must be bitwise OR'd with
 * S_IFBLK, S_IFCHR, S_IFIFO or S_IFSOCK (otherwise this call just creates
 * a regular file). These constants are available in the standard Linux
 * header files, or you can use guestfs_session_mknod_b(),
 * guestfs_session_mknod_c() or guestfs_session_mkfifo() which are wrappers
 * around this command which bitwise OR in the appropriate constant for
 * you.
 * 
 * The mode actually set is affected by the umask.
 * 
 * Returns: true on success, false on error
 * Since: 1.0.55
 */
gboolean
guestfs_session_mknod (GuestfsSession *session, gint32 mode, gint32 devmajor, gint32 devminor, const gchar *path, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "mknod");
    return FALSE;
  }

  int ret = guestfs_mknod (g, mode, devmajor, devminor, path);
  if (ret == -1) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return FALSE;
  }

  return TRUE;
}

/**
 * guestfs_session_mknod_b:
 * @session: (transfer none): A GuestfsSession object
 * @mode: (type gint32):
 * @devmajor: (type gint32):
 * @devminor: (type gint32):
 * @path: (transfer none) (type filename):
 * @err: A GError object to receive any generated errors
 *
 * make block device node
 *
 * This call creates a block device node called @path with mode @mode and
 * device major/minor @devmajor and @devminor. It is just a convenient
 * wrapper around guestfs_session_mknod().
 * 
 * Unlike with guestfs_session_mknod(), @mode must contain only permissions
 * bits.
 * 
 * The mode actually set is affected by the umask.
 * 
 * Returns: true on success, false on error
 * Since: 1.0.55
 */
gboolean
guestfs_session_mknod_b (GuestfsSession *session, gint32 mode, gint32 devmajor, gint32 devminor, const gchar *path, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "mknod_b");
    return FALSE;
  }

  int ret = guestfs_mknod_b (g, mode, devmajor, devminor, path);
  if (ret == -1) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return FALSE;
  }

  return TRUE;
}

/**
 * guestfs_session_mknod_c:
 * @session: (transfer none): A GuestfsSession object
 * @mode: (type gint32):
 * @devmajor: (type gint32):
 * @devminor: (type gint32):
 * @path: (transfer none) (type filename):
 * @err: A GError object to receive any generated errors
 *
 * make char device node
 *
 * This call creates a char device node called @path with mode @mode and
 * device major/minor @devmajor and @devminor. It is just a convenient
 * wrapper around guestfs_session_mknod().
 * 
 * Unlike with guestfs_session_mknod(), @mode must contain only permissions
 * bits.
 * 
 * The mode actually set is affected by the umask.
 * 
 * Returns: true on success, false on error
 * Since: 1.0.55
 */
gboolean
guestfs_session_mknod_c (GuestfsSession *session, gint32 mode, gint32 devmajor, gint32 devminor, const gchar *path, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "mknod_c");
    return FALSE;
  }

  int ret = guestfs_mknod_c (g, mode, devmajor, devminor, path);
  if (ret == -1) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return FALSE;
  }

  return TRUE;
}

/**
 * guestfs_session_mkswap:
 * @session: (transfer none): A GuestfsSession object
 * @device: (transfer none) (type filename):
 * @optargs: (transfer none) (allow-none): a GuestfsMkswap containing optional arguments
 * @err: A GError object to receive any generated errors
 *
 * create a swap partition
 *
 * Create a Linux swap partition on @device.
 * 
 * The option arguments @label and @uuid allow you to set the label and/or
 * UUID of the new swap partition.
 * 
 * Returns: true on success, false on error
 * Since: 1.0.55
 */
gboolean
guestfs_session_mkswap (GuestfsSession *session, const gchar *device, GuestfsMkswap *optargs, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "mkswap");
    return FALSE;
  }

  struct guestfs_mkswap_opts_argv argv;
  struct guestfs_mkswap_opts_argv *argvp = NULL;

  if (optargs) {
    argv.bitmask = 0;

    GValue label_v = {0, };
    g_value_init (&label_v, G_TYPE_STRING);
    g_object_get_property (G_OBJECT (optargs), "label", &label_v);
    const gchar *label = g_value_get_string (&label_v);
    if (label != NULL) {
      argv.bitmask |= GUESTFS_MKSWAP_OPTS_LABEL_BITMASK;
      argv.label = label;
    }
    GValue uuid_v = {0, };
    g_value_init (&uuid_v, G_TYPE_STRING);
    g_object_get_property (G_OBJECT (optargs), "uuid", &uuid_v);
    const gchar *uuid = g_value_get_string (&uuid_v);
    if (uuid != NULL) {
      argv.bitmask |= GUESTFS_MKSWAP_OPTS_UUID_BITMASK;
      argv.uuid = uuid;
    }
    argvp = &argv;
  }
  int ret = guestfs_mkswap_opts_argv (g, device, argvp);
  if (ret == -1) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return FALSE;
  }

  return TRUE;
}

/**
 * guestfs_session_mkswap_L:
 * @session: (transfer none): A GuestfsSession object
 * @label: (transfer none) (type utf8):
 * @device: (transfer none) (type filename):
 * @err: A GError object to receive any generated errors
 *
 * create a swap partition with a label
 *
 * Create a swap partition on @device with label @label.
 * 
 * Note that you cannot attach a swap label to a block device (eg.
 * /dev/sda), just to a partition. This appears to be a limitation of the
 * kernel or swap tools.
 * 
 * Returns: true on success, false on error
 * Deprecated: In new code, use guestfs_session_mkswap() instead
 * Since: 1.0.55
 */
gboolean
guestfs_session_mkswap_L (GuestfsSession *session, const gchar *label, const gchar *device, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "mkswap_L");
    return FALSE;
  }

  int ret = guestfs_mkswap_L (g, label, device);
  if (ret == -1) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return FALSE;
  }

  return TRUE;
}

/**
 * guestfs_session_mkswap_U:
 * @session: (transfer none): A GuestfsSession object
 * @uuid: (transfer none) (type utf8):
 * @device: (transfer none) (type filename):
 * @err: A GError object to receive any generated errors
 *
 * create a swap partition with an explicit UUID
 *
 * Create a swap partition on @device with UUID @uuid.
 * 
 * Returns: true on success, false on error
 * Deprecated: In new code, use guestfs_session_mkswap() instead
 * Since: 1.0.55
 */
gboolean
guestfs_session_mkswap_U (GuestfsSession *session, const gchar *uuid, const gchar *device, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "mkswap_U");
    return FALSE;
  }

  int ret = guestfs_mkswap_U (g, uuid, device);
  if (ret == -1) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return FALSE;
  }

  return TRUE;
}

/**
 * guestfs_session_mkswap_file:
 * @session: (transfer none): A GuestfsSession object
 * @path: (transfer none) (type filename):
 * @err: A GError object to receive any generated errors
 *
 * create a swap file
 *
 * Create a swap file.
 * 
 * This command just writes a swap file signature to an existing file. To
 * create the file itself, use something like guestfs_session_fallocate().
 * 
 * Returns: true on success, false on error
 * Since: 1.0.66
 */
gboolean
guestfs_session_mkswap_file (GuestfsSession *session, const gchar *path, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "mkswap_file");
    return FALSE;
  }

  int ret = guestfs_mkswap_file (g, path);
  if (ret == -1) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return FALSE;
  }

  return TRUE;
}

/**
 * guestfs_session_mktemp:
 * @session: (transfer none): A GuestfsSession object
 * @tmpl: (transfer none) (type filename):
 * @optargs: (transfer none) (allow-none): a GuestfsMktemp containing optional arguments
 * @err: A GError object to receive any generated errors
 *
 * create a temporary file
 *
 * This command creates a temporary file. The @tmpl parameter should be a
 * full pathname for the temporary directory name with the final six
 * characters being "XXXXXX".
 * 
 * For example: "/tmp/myprogXXXXXX" or "/Temp/myprogXXXXXX", the second one
 * being suitable for Windows filesystems.
 * 
 * The name of the temporary file that was created is returned.
 * 
 * The temporary file is created with mode 0600 and is owned by root.
 * 
 * The caller is responsible for deleting the temporary file after use.
 * 
 * If the optional @suffix parameter is given, then the suffix (eg. ".txt")
 * is appended to the temporary name.
 * 
 * See also: guestfs_session_mkdtemp().
 * 
 * Returns: (transfer full): the returned string, or NULL on error
 * Since: 1.19.53
 */
gchar *
guestfs_session_mktemp (GuestfsSession *session, const gchar *tmpl, GuestfsMktemp *optargs, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "mktemp");
    return NULL;
  }

  struct guestfs_mktemp_argv argv;
  struct guestfs_mktemp_argv *argvp = NULL;

  if (optargs) {
    argv.bitmask = 0;

    GValue suffix_v = {0, };
    g_value_init (&suffix_v, G_TYPE_STRING);
    g_object_get_property (G_OBJECT (optargs), "suffix", &suffix_v);
    const gchar *suffix = g_value_get_string (&suffix_v);
    if (suffix != NULL) {
      argv.bitmask |= GUESTFS_MKTEMP_SUFFIX_BITMASK;
      argv.suffix = suffix;
    }
    argvp = &argv;
  }
  char *ret = guestfs_mktemp_argv (g, tmpl, argvp);
  if (ret == NULL) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return NULL;
  }

  return ret;
}

/**
 * guestfs_session_modprobe:
 * @session: (transfer none): A GuestfsSession object
 * @modulename: (transfer none) (type utf8):
 * @err: A GError object to receive any generated errors
 *
 * load a kernel module
 *
 * This loads a kernel module in the appliance.
 * 
 * Returns: true on success, false on error
 * Since: 1.0.68
 */
gboolean
guestfs_session_modprobe (GuestfsSession *session, const gchar *modulename, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "modprobe");
    return FALSE;
  }

  int ret = guestfs_modprobe (g, modulename);
  if (ret == -1) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return FALSE;
  }

  return TRUE;
}

/**
 * guestfs_session_mount:
 * @session: (transfer none): A GuestfsSession object
 * @mountable: (transfer none) (type filename):
 * @mountpoint: (transfer none) (type utf8):
 * @err: A GError object to receive any generated errors
 *
 * mount a guest disk at a position in the filesystem
 *
 * Mount a guest disk at a position in the filesystem. Block devices are
 * named /dev/sda, /dev/sdb and so on, as they were added to the guest. If
 * those block devices contain partitions, they will have the usual names
 * (eg. /dev/sda1). Also LVM /dev/VG/LV-style names can be used, or
 * 'mountable' strings returned by guestfs_session_list_filesystems() or
 * guestfs_session_inspect_get_mountpoints().
 * 
 * The rules are the same as for mount(2): A filesystem must first be
 * mounted on / before others can be mounted. Other filesystems can only be
 * mounted on directories which already exist.
 * 
 * The mounted filesystem is writable, if we have sufficient permissions on
 * the underlying device.
 * 
 * Before libguestfs 1.13.16, this call implicitly added the options @sync
 * and @noatime. The @sync option greatly slowed writes and caused many
 * problems for users. If your program might need to work with older
 * versions of libguestfs, use guestfs_session_mount_options() instead
 * (using an empty string for the first parameter if you don't want any
 * options).
 * 
 * Returns: true on success, false on error
 * Since: 0.3
 */
gboolean
guestfs_session_mount (GuestfsSession *session, const gchar *mountable, const gchar *mountpoint, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "mount");
    return FALSE;
  }

  int ret = guestfs_mount (g, mountable, mountpoint);
  if (ret == -1) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return FALSE;
  }

  return TRUE;
}

/**
 * guestfs_session_mount_9p:
 * @session: (transfer none): A GuestfsSession object
 * @mounttag: (transfer none) (type utf8):
 * @mountpoint: (transfer none) (type utf8):
 * @optargs: (transfer none) (allow-none): a GuestfsMount9P containing optional arguments
 * @err: A GError object to receive any generated errors
 *
 * mount 9p filesystem
 *
 * Mount the virtio-9p filesystem with the tag @mounttag on the directory
 * @mountpoint.
 * 
 * If required, "trans=virtio" will be automatically added to the options.
 * Any other options required can be passed in the optional @options
 * parameter.
 * 
 * Returns: true on success, false on error
 * Since: 1.11.12
 */
gboolean
guestfs_session_mount_9p (GuestfsSession *session, const gchar *mounttag, const gchar *mountpoint, GuestfsMount9P *optargs, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "mount_9p");
    return FALSE;
  }

  struct guestfs_mount_9p_argv argv;
  struct guestfs_mount_9p_argv *argvp = NULL;

  if (optargs) {
    argv.bitmask = 0;

    GValue options_v = {0, };
    g_value_init (&options_v, G_TYPE_STRING);
    g_object_get_property (G_OBJECT (optargs), "options", &options_v);
    const gchar *options = g_value_get_string (&options_v);
    if (options != NULL) {
      argv.bitmask |= GUESTFS_MOUNT_9P_OPTIONS_BITMASK;
      argv.options = options;
    }
    argvp = &argv;
  }
  int ret = guestfs_mount_9p_argv (g, mounttag, mountpoint, argvp);
  if (ret == -1) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return FALSE;
  }

  return TRUE;
}

/**
 * guestfs_session_mount_local:
 * @session: (transfer none): A GuestfsSession object
 * @localmountpoint: (transfer none) (type utf8):
 * @optargs: (transfer none) (allow-none): a GuestfsMountLocal containing optional arguments
 * @err: A GError object to receive any generated errors
 *
 * mount on the local filesystem
 *
 * This call exports the libguestfs-accessible filesystem to a local
 * mountpoint (directory) called @localmountpoint. Ordinary reads and
 * writes to files and directories under @localmountpoint are redirected
 * through libguestfs.
 * 
 * If the optional @readonly flag is set to true, then writes to the
 * filesystem return error @EROFS.
 * 
 * @options is a comma-separated list of mount options. See guestmount(1)
 * for some useful options.
 * 
 * @cachetimeout sets the timeout (in seconds) for cached directory
 * entries. The default is 60 seconds. See guestmount(1) for further
 * information.
 * 
 * If @debugcalls is set to true, then additional debugging information is
 * generated for every FUSE call.
 * 
 * When guestfs_session_mount_local() returns, the filesystem is ready, but
 * is not processing requests (access to it will block). You have to call
 * guestfs_session_mount_local_run() to run the main loop.
 * 
 * See "MOUNT LOCAL" in guestfs(3) for full documentation.
 * 
 * Returns: true on success, false on error
 * Since: 1.17.22
 */
gboolean
guestfs_session_mount_local (GuestfsSession *session, const gchar *localmountpoint, GuestfsMountLocal *optargs, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "mount_local");
    return FALSE;
  }

  struct guestfs_mount_local_argv argv;
  struct guestfs_mount_local_argv *argvp = NULL;

  if (optargs) {
    argv.bitmask = 0;

    GValue readonly_v = {0, };
    g_value_init (&readonly_v, GUESTFS_TYPE_TRISTATE);
    g_object_get_property (G_OBJECT (optargs), "readonly", &readonly_v);
    GuestfsTristate readonly = g_value_get_enum (&readonly_v);
    if (readonly != GUESTFS_TRISTATE_NONE) {
      argv.bitmask |= GUESTFS_MOUNT_LOCAL_READONLY_BITMASK;
      argv.readonly = readonly;
    }
    GValue options_v = {0, };
    g_value_init (&options_v, G_TYPE_STRING);
    g_object_get_property (G_OBJECT (optargs), "options", &options_v);
    const gchar *options = g_value_get_string (&options_v);
    if (options != NULL) {
      argv.bitmask |= GUESTFS_MOUNT_LOCAL_OPTIONS_BITMASK;
      argv.options = options;
    }
    GValue cachetimeout_v = {0, };
    g_value_init (&cachetimeout_v, G_TYPE_INT);
    g_object_get_property (G_OBJECT (optargs), "cachetimeout", &cachetimeout_v);
    gint32 cachetimeout = g_value_get_int (&cachetimeout_v);
    if (cachetimeout != -1) {
      argv.bitmask |= GUESTFS_MOUNT_LOCAL_CACHETIMEOUT_BITMASK;
      argv.cachetimeout = cachetimeout;
    }
    GValue debugcalls_v = {0, };
    g_value_init (&debugcalls_v, GUESTFS_TYPE_TRISTATE);
    g_object_get_property (G_OBJECT (optargs), "debugcalls", &debugcalls_v);
    GuestfsTristate debugcalls = g_value_get_enum (&debugcalls_v);
    if (debugcalls != GUESTFS_TRISTATE_NONE) {
      argv.bitmask |= GUESTFS_MOUNT_LOCAL_DEBUGCALLS_BITMASK;
      argv.debugcalls = debugcalls;
    }
    argvp = &argv;
  }
  int ret = guestfs_mount_local_argv (g, localmountpoint, argvp);
  if (ret == -1) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return FALSE;
  }

  return TRUE;
}

/**
 * guestfs_session_mount_local_run:
 * @session: (transfer none): A GuestfsSession object
 * @cancellable: A GCancellable object
 * @err: A GError object to receive any generated errors
 *
 * run main loop of mount on the local filesystem
 *
 * Run the main loop which translates kernel calls to libguestfs calls.
 * 
 * This should only be called after guestfs_session_mount_local() returns
 * successfully. The call will not return until the filesystem is
 * unmounted.
 * 
 * Note you must *not* make concurrent libguestfs calls on the same handle
 * from another thread.
 * 
 * You may call this from a different thread than the one which called
 * guestfs_session_mount_local(), subject to the usual rules for threads
 * and libguestfs (see "MULTIPLE HANDLES AND MULTIPLE THREADS" in
 * guestfs(3)).
 * 
 * See "MOUNT LOCAL" in guestfs(3) for full documentation.
 * 
 * Returns: true on success, false on error
 * Since: 1.17.22
 */
gboolean
guestfs_session_mount_local_run (GuestfsSession *session, GCancellable *cancellable, GError **err)
{
  /* Check we haven't already been cancelled */
  if (g_cancellable_set_error_if_cancelled (cancellable, err))
    return FALSE;

  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "mount_local_run");
    return FALSE;
  }

  gulong id = 0;
  if (cancellable) {
    id = g_cancellable_connect (cancellable,
                               G_CALLBACK (cancelled_handler),
                               g, NULL);
  }

  int ret = guestfs_mount_local_run (g);
  g_cancellable_disconnect (cancellable, id);
  if (ret == -1) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return FALSE;
  }

  return TRUE;
}

/**
 * guestfs_session_mount_loop:
 * @session: (transfer none): A GuestfsSession object
 * @file: (transfer none) (type filename):
 * @mountpoint: (transfer none) (type filename):
 * @err: A GError object to receive any generated errors
 *
 * mount a file using the loop device
 *
 * This command lets you mount file (a filesystem image in a file) on a
 * mount point. It is entirely equivalent to the command "mount -o loop
 * file mountpoint".
 * 
 * Returns: true on success, false on error
 * Since: 1.0.54
 */
gboolean
guestfs_session_mount_loop (GuestfsSession *session, const gchar *file, const gchar *mountpoint, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "mount_loop");
    return FALSE;
  }

  int ret = guestfs_mount_loop (g, file, mountpoint);
  if (ret == -1) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return FALSE;
  }

  return TRUE;
}

/**
 * guestfs_session_mount_options:
 * @session: (transfer none): A GuestfsSession object
 * @options: (transfer none) (type utf8):
 * @mountable: (transfer none) (type filename):
 * @mountpoint: (transfer none) (type utf8):
 * @err: A GError object to receive any generated errors
 *
 * mount a guest disk with mount options
 *
 * This is the same as the guestfs_session_mount() command, but it allows
 * you to set the mount options as for the mount(8) *-o* flag.
 * 
 * If the @options parameter is an empty string, then no options are passed
 * (all options default to whatever the filesystem uses).
 * 
 * Returns: true on success, false on error
 * Since: 1.0.10
 */
gboolean
guestfs_session_mount_options (GuestfsSession *session, const gchar *options, const gchar *mountable, const gchar *mountpoint, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "mount_options");
    return FALSE;
  }

  int ret = guestfs_mount_options (g, options, mountable, mountpoint);
  if (ret == -1) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return FALSE;
  }

  return TRUE;
}

/**
 * guestfs_session_mount_ro:
 * @session: (transfer none): A GuestfsSession object
 * @mountable: (transfer none) (type filename):
 * @mountpoint: (transfer none) (type utf8):
 * @err: A GError object to receive any generated errors
 *
 * mount a guest disk, read-only
 *
 * This is the same as the guestfs_session_mount() command, but it mounts
 * the filesystem with the read-only (*-o ro*) flag.
 * 
 * Returns: true on success, false on error
 * Since: 1.0.10
 */
gboolean
guestfs_session_mount_ro (GuestfsSession *session, const gchar *mountable, const gchar *mountpoint, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "mount_ro");
    return FALSE;
  }

  int ret = guestfs_mount_ro (g, mountable, mountpoint);
  if (ret == -1) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return FALSE;
  }

  return TRUE;
}

/**
 * guestfs_session_mount_vfs:
 * @session: (transfer none): A GuestfsSession object
 * @options: (transfer none) (type utf8):
 * @vfstype: (transfer none) (type utf8):
 * @mountable: (transfer none) (type filename):
 * @mountpoint: (transfer none) (type utf8):
 * @err: A GError object to receive any generated errors
 *
 * mount a guest disk with mount options and vfstype
 *
 * This is the same as the guestfs_session_mount() command, but it allows
 * you to set both the mount options and the vfstype as for the mount(8)
 * *-o* and *-t* flags.
 * 
 * Returns: true on success, false on error
 * Since: 1.0.10
 */
gboolean
guestfs_session_mount_vfs (GuestfsSession *session, const gchar *options, const gchar *vfstype, const gchar *mountable, const gchar *mountpoint, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "mount_vfs");
    return FALSE;
  }

  int ret = guestfs_mount_vfs (g, options, vfstype, mountable, mountpoint);
  if (ret == -1) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return FALSE;
  }

  return TRUE;
}

/**
 * guestfs_session_mountpoints:
 * @session: (transfer none): A GuestfsSession object
 * @err: A GError object to receive any generated errors
 *
 * show mountpoints
 *
 * This call is similar to guestfs_session_mounts(). That call returns a
 * list of devices. This one returns a hash table (map) of device name to
 * directory where the device is mounted.
 * 
 * Returns: (transfer full) (element-type utf8 utf8): a GHashTable of results, or NULL on error
 * Since: 1.0.62
 */
GHashTable *
guestfs_session_mountpoints (GuestfsSession *session, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "mountpoints");
    return NULL;
  }

  char **ret = guestfs_mountpoints (g);
  if (ret == NULL) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return NULL;
  }

  GHashTable *h = g_hash_table_new_full (g_str_hash, g_str_equal, g_free, g_free);
  char **i = ret;
  while (*i) {
    char *key = *i; i++;
    char *value = *i; i++;
    g_hash_table_insert (h, key, value);
  };
  g_free (ret);
  return h;
}

/**
 * guestfs_session_mounts:
 * @session: (transfer none): A GuestfsSession object
 * @err: A GError object to receive any generated errors
 *
 * show mounted filesystems
 *
 * This returns the list of currently mounted filesystems. It returns the
 * list of devices (eg. /dev/sda1, /dev/VG/LV).
 * 
 * Some internal mounts are not shown.
 * 
 * See also: guestfs_session_mountpoints()
 * 
 * Returns: (transfer full) (array zero-terminated=1) (element-type utf8): an array of returned strings, or NULL on error
 * Since: 0.8
 */
gchar **
guestfs_session_mounts (GuestfsSession *session, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "mounts");
    return NULL;
  }

  char **ret = guestfs_mounts (g);
  if (ret == NULL) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return NULL;
  }

  return ret;
}

/**
 * guestfs_session_mv:
 * @session: (transfer none): A GuestfsSession object
 * @src: (transfer none) (type filename):
 * @dest: (transfer none) (type filename):
 * @err: A GError object to receive any generated errors
 *
 * move a file
 *
 * This moves a file from @src to @dest where @dest is either a destination
 * filename or destination directory.
 * 
 * See also: guestfs_session_rename().
 * 
 * Returns: true on success, false on error
 * Since: 1.0.18
 */
gboolean
guestfs_session_mv (GuestfsSession *session, const gchar *src, const gchar *dest, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "mv");
    return FALSE;
  }

  int ret = guestfs_mv (g, src, dest);
  if (ret == -1) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return FALSE;
  }

  return TRUE;
}

/**
 * guestfs_session_nr_devices:
 * @session: (transfer none): A GuestfsSession object
 * @err: A GError object to receive any generated errors
 *
 * return number of whole block devices (disks) added
 *
 * This returns the number of whole block devices that were added. This is
 * the same as the number of devices that would be returned if you called
 * guestfs_session_list_devices().
 * 
 * To find out the maximum number of devices that could be added, call
 * guestfs_session_max_disks().
 * 
 * Returns: the returned value, or -1 on error
 * Since: 1.19.15
 */
gint32
guestfs_session_nr_devices (GuestfsSession *session, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "nr_devices");
    return -1;
  }

  int ret = guestfs_nr_devices (g);
  if (ret == -1) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return -1;
  }

  return ret;
}

/**
 * guestfs_session_ntfs_3g_probe:
 * @session: (transfer none): A GuestfsSession object
 * @rw: (type gboolean):
 * @device: (transfer none) (type filename):
 * @err: A GError object to receive any generated errors
 *
 * probe NTFS volume
 *
 * This command runs the ntfs-3g.probe(8) command which probes an NTFS
 * @device for mountability. (Not all NTFS volumes can be mounted
 * read-write, and some cannot be mounted at all).
 * 
 * @rw is a boolean flag. Set it to true if you want to test if the volume
 * can be mounted read-write. Set it to false if you want to test if the
 * volume can be mounted read-only.
 * 
 * The return value is an integer which @0 if the operation would succeed,
 * or some non-zero value documented in the ntfs-3g.probe(8) manual page.
 * 
 * Returns: the returned value, or -1 on error
 * Since: 1.0.43
 */
gint32
guestfs_session_ntfs_3g_probe (GuestfsSession *session, gboolean rw, const gchar *device, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "ntfs_3g_probe");
    return -1;
  }

  int ret = guestfs_ntfs_3g_probe (g, rw, device);
  if (ret == -1) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return -1;
  }

  return ret;
}

/**
 * guestfs_session_ntfsclone_in:
 * @session: (transfer none): A GuestfsSession object
 * @backupfile: (transfer none) (type filename):
 * @device: (transfer none) (type filename):
 * @cancellable: A GCancellable object
 * @err: A GError object to receive any generated errors
 *
 * restore NTFS from backup file
 *
 * Restore the @backupfile (from a previous call to
 * guestfs_session_ntfsclone_out()) to @device, overwriting any existing
 * contents of this device.
 * 
 * Returns: true on success, false on error
 * Since: 1.17.9
 */
gboolean
guestfs_session_ntfsclone_in (GuestfsSession *session, const gchar *backupfile, const gchar *device, GCancellable *cancellable, GError **err)
{
  /* Check we haven't already been cancelled */
  if (g_cancellable_set_error_if_cancelled (cancellable, err))
    return FALSE;

  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "ntfsclone_in");
    return FALSE;
  }

  gulong id = 0;
  if (cancellable) {
    id = g_cancellable_connect (cancellable,
                               G_CALLBACK (cancelled_handler),
                               g, NULL);
  }

  int ret = guestfs_ntfsclone_in (g, backupfile, device);
  g_cancellable_disconnect (cancellable, id);
  if (ret == -1) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return FALSE;
  }

  return TRUE;
}

/**
 * guestfs_session_ntfsclone_out:
 * @session: (transfer none): A GuestfsSession object
 * @device: (transfer none) (type filename):
 * @backupfile: (transfer none) (type filename):
 * @optargs: (transfer none) (allow-none): a GuestfsNtfscloneOut containing optional arguments
 * @cancellable: A GCancellable object
 * @err: A GError object to receive any generated errors
 *
 * save NTFS to backup file
 *
 * Stream the NTFS filesystem @device to the local file @backupfile. The
 * format used for the backup file is a special format used by the
 * ntfsclone(8) tool.
 * 
 * If the optional @metadataonly flag is true, then *only* the metadata is
 * saved, losing all the user data (this is useful for diagnosing some
 * filesystem problems).
 * 
 * The optional @rescue, @ignorefscheck, @preservetimestamps and @force
 * flags have precise meanings detailed in the ntfsclone(8) man page.
 * 
 * Use guestfs_session_ntfsclone_in() to restore the file back to a
 * libguestfs device.
 * 
 * Returns: true on success, false on error
 * Since: 1.17.9
 */
gboolean
guestfs_session_ntfsclone_out (GuestfsSession *session, const gchar *device, const gchar *backupfile, GuestfsNtfscloneOut *optargs, GCancellable *cancellable, GError **err)
{
  /* Check we haven't already been cancelled */
  if (g_cancellable_set_error_if_cancelled (cancellable, err))
    return FALSE;

  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "ntfsclone_out");
    return FALSE;
  }

  struct guestfs_ntfsclone_out_argv argv;
  struct guestfs_ntfsclone_out_argv *argvp = NULL;

  if (optargs) {
    argv.bitmask = 0;

    GValue metadataonly_v = {0, };
    g_value_init (&metadataonly_v, GUESTFS_TYPE_TRISTATE);
    g_object_get_property (G_OBJECT (optargs), "metadataonly", &metadataonly_v);
    GuestfsTristate metadataonly = g_value_get_enum (&metadataonly_v);
    if (metadataonly != GUESTFS_TRISTATE_NONE) {
      argv.bitmask |= GUESTFS_NTFSCLONE_OUT_METADATAONLY_BITMASK;
      argv.metadataonly = metadataonly;
    }
    GValue rescue_v = {0, };
    g_value_init (&rescue_v, GUESTFS_TYPE_TRISTATE);
    g_object_get_property (G_OBJECT (optargs), "rescue", &rescue_v);
    GuestfsTristate rescue = g_value_get_enum (&rescue_v);
    if (rescue != GUESTFS_TRISTATE_NONE) {
      argv.bitmask |= GUESTFS_NTFSCLONE_OUT_RESCUE_BITMASK;
      argv.rescue = rescue;
    }
    GValue ignorefscheck_v = {0, };
    g_value_init (&ignorefscheck_v, GUESTFS_TYPE_TRISTATE);
    g_object_get_property (G_OBJECT (optargs), "ignorefscheck", &ignorefscheck_v);
    GuestfsTristate ignorefscheck = g_value_get_enum (&ignorefscheck_v);
    if (ignorefscheck != GUESTFS_TRISTATE_NONE) {
      argv.bitmask |= GUESTFS_NTFSCLONE_OUT_IGNOREFSCHECK_BITMASK;
      argv.ignorefscheck = ignorefscheck;
    }
    GValue preservetimestamps_v = {0, };
    g_value_init (&preservetimestamps_v, GUESTFS_TYPE_TRISTATE);
    g_object_get_property (G_OBJECT (optargs), "preservetimestamps", &preservetimestamps_v);
    GuestfsTristate preservetimestamps = g_value_get_enum (&preservetimestamps_v);
    if (preservetimestamps != GUESTFS_TRISTATE_NONE) {
      argv.bitmask |= GUESTFS_NTFSCLONE_OUT_PRESERVETIMESTAMPS_BITMASK;
      argv.preservetimestamps = preservetimestamps;
    }
    GValue force_v = {0, };
    g_value_init (&force_v, GUESTFS_TYPE_TRISTATE);
    g_object_get_property (G_OBJECT (optargs), "force", &force_v);
    GuestfsTristate force = g_value_get_enum (&force_v);
    if (force != GUESTFS_TRISTATE_NONE) {
      argv.bitmask |= GUESTFS_NTFSCLONE_OUT_FORCE_BITMASK;
      argv.force = force;
    }
    argvp = &argv;
  }
  gulong id = 0;
  if (cancellable) {
    id = g_cancellable_connect (cancellable,
                               G_CALLBACK (cancelled_handler),
                               g, NULL);
  }

  int ret = guestfs_ntfsclone_out_argv (g, device, backupfile, argvp);
  g_cancellable_disconnect (cancellable, id);
  if (ret == -1) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return FALSE;
  }

  return TRUE;
}

/**
 * guestfs_session_ntfsfix:
 * @session: (transfer none): A GuestfsSession object
 * @device: (transfer none) (type filename):
 * @optargs: (transfer none) (allow-none): a GuestfsNtfsfix containing optional arguments
 * @err: A GError object to receive any generated errors
 *
 * fix common errors and force Windows to check NTFS
 *
 * This command repairs some fundamental NTFS inconsistencies, resets the
 * NTFS journal file, and schedules an NTFS consistency check for the first
 * boot into Windows.
 * 
 * This is *not* an equivalent of Windows @chkdsk. It does *not* scan the
 * filesystem for inconsistencies.
 * 
 * The optional @clearbadsectors flag clears the list of bad sectors. This
 * is useful after cloning a disk with bad sectors to a new disk.
 * 
 * Returns: true on success, false on error
 * Since: 1.17.9
 */
gboolean
guestfs_session_ntfsfix (GuestfsSession *session, const gchar *device, GuestfsNtfsfix *optargs, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "ntfsfix");
    return FALSE;
  }

  struct guestfs_ntfsfix_argv argv;
  struct guestfs_ntfsfix_argv *argvp = NULL;

  if (optargs) {
    argv.bitmask = 0;

    GValue clearbadsectors_v = {0, };
    g_value_init (&clearbadsectors_v, GUESTFS_TYPE_TRISTATE);
    g_object_get_property (G_OBJECT (optargs), "clearbadsectors", &clearbadsectors_v);
    GuestfsTristate clearbadsectors = g_value_get_enum (&clearbadsectors_v);
    if (clearbadsectors != GUESTFS_TRISTATE_NONE) {
      argv.bitmask |= GUESTFS_NTFSFIX_CLEARBADSECTORS_BITMASK;
      argv.clearbadsectors = clearbadsectors;
    }
    argvp = &argv;
  }
  int ret = guestfs_ntfsfix_argv (g, device, argvp);
  if (ret == -1) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return FALSE;
  }

  return TRUE;
}

/**
 * guestfs_session_ntfsresize:
 * @session: (transfer none): A GuestfsSession object
 * @device: (transfer none) (type filename):
 * @optargs: (transfer none) (allow-none): a GuestfsNTFSResizeOpts containing optional arguments
 * @err: A GError object to receive any generated errors
 *
 * resize an NTFS filesystem
 *
 * This command resizes an NTFS filesystem, expanding or shrinking it to
 * the size of the underlying device.
 * 
 * The optional parameters are:
 * 
 * @size
 * The new size (in bytes) of the filesystem. If omitted, the
 * filesystem is resized to fit the container (eg. partition).
 * 
 * @force
 * If this option is true, then force the resize of the filesystem even
 * if the filesystem is marked as requiring a consistency check.
 * 
 * After the resize operation, the filesystem is always marked as
 * requiring a consistency check (for safety). You have to boot into
 * Windows to perform this check and clear this condition. If you
 * *don't* set the @force option then it is not possible to call
 * guestfs_session_ntfsresize() multiple times on a single filesystem
 * without booting into Windows between each resize.
 * 
 * See also ntfsresize(8).
 * 
 * Returns: true on success, false on error
 * Since: 1.3.2
 */
gboolean
guestfs_session_ntfsresize (GuestfsSession *session, const gchar *device, GuestfsNTFSResizeOpts *optargs, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "ntfsresize");
    return FALSE;
  }

  struct guestfs_ntfsresize_opts_argv argv;
  struct guestfs_ntfsresize_opts_argv *argvp = NULL;

  if (optargs) {
    argv.bitmask = 0;

    GValue size_v = {0, };
    g_value_init (&size_v, G_TYPE_INT64);
    g_object_get_property (G_OBJECT (optargs), "size", &size_v);
    gint64 size = g_value_get_int64 (&size_v);
    if (size != -1) {
      argv.bitmask |= GUESTFS_NTFSRESIZE_OPTS_SIZE_BITMASK;
      argv.size = size;
    }
    GValue force_v = {0, };
    g_value_init (&force_v, GUESTFS_TYPE_TRISTATE);
    g_object_get_property (G_OBJECT (optargs), "force", &force_v);
    GuestfsTristate force = g_value_get_enum (&force_v);
    if (force != GUESTFS_TRISTATE_NONE) {
      argv.bitmask |= GUESTFS_NTFSRESIZE_OPTS_FORCE_BITMASK;
      argv.force = force;
    }
    argvp = &argv;
  }
  int ret = guestfs_ntfsresize_opts_argv (g, device, argvp);
  if (ret == -1) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return FALSE;
  }

  return TRUE;
}

/**
 * guestfs_session_ntfsresize_size:
 * @session: (transfer none): A GuestfsSession object
 * @device: (transfer none) (type filename):
 * @size: (type gint64):
 * @err: A GError object to receive any generated errors
 *
 * resize an NTFS filesystem (with size)
 *
 * This command is the same as guestfs_session_ntfsresize() except that it
 * allows you to specify the new size (in bytes) explicitly.
 * 
 * Returns: true on success, false on error
 * Deprecated: In new code, use guestfs_session_ntfsresize() instead
 * Since: 1.3.14
 */
gboolean
guestfs_session_ntfsresize_size (GuestfsSession *session, const gchar *device, gint64 size, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "ntfsresize_size");
    return FALSE;
  }

  int ret = guestfs_ntfsresize_size (g, device, size);
  if (ret == -1) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return FALSE;
  }

  return TRUE;
}

/**
 * guestfs_session_parse_environment:
 * @session: (transfer none): A GuestfsSession object
 * @err: A GError object to receive any generated errors
 *
 * parse the environment and set handle flags accordingly
 *
 * Parse the program's environment and set flags in the handle accordingly.
 * For example if "LIBGUESTFS_DEBUG=1" then the 'verbose' flag is set in
 * the handle.
 * 
 * *Most programs do not need to call this*. It is done implicitly when you
 * call guestfs_session_create().
 * 
 * See "ENVIRONMENT VARIABLES" in guestfs(3) for a list of environment
 * variables that can affect libguestfs handles. See also
 * "guestfs_create_flags" in guestfs(3), and
 * guestfs_session_parse_environment_list().
 * 
 * Returns: true on success, false on error
 * Since: 1.19.53
 */
gboolean
guestfs_session_parse_environment (GuestfsSession *session, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "parse_environment");
    return FALSE;
  }

  int ret = guestfs_parse_environment (g);
  if (ret == -1) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return FALSE;
  }

  return TRUE;
}

/**
 * guestfs_session_parse_environment_list:
 * @session: (transfer none): A GuestfsSession object
 * @environment: (transfer none) (array zero-terminated=1) (element-type utf8): an array of strings
 * @err: A GError object to receive any generated errors
 *
 * parse the environment and set handle flags accordingly
 *
 * Parse the list of strings in the argument @environment and set flags in
 * the handle accordingly. For example if "LIBGUESTFS_DEBUG=1" is a string
 * in the list, then the 'verbose' flag is set in the handle.
 * 
 * This is the same as guestfs_session_parse_environment() except that it
 * parses an explicit list of strings instead of the program's environment.
 * 
 * Returns: true on success, false on error
 * Since: 1.19.53
 */
gboolean
guestfs_session_parse_environment_list (GuestfsSession *session, gchar *const *environment, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "parse_environment_list");
    return FALSE;
  }

  int ret = guestfs_parse_environment_list (g, environment);
  if (ret == -1) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return FALSE;
  }

  return TRUE;
}

/**
 * guestfs_session_part_add:
 * @session: (transfer none): A GuestfsSession object
 * @device: (transfer none) (type filename):
 * @prlogex: (transfer none) (type utf8):
 * @startsect: (type gint64):
 * @endsect: (type gint64):
 * @err: A GError object to receive any generated errors
 *
 * add a partition to the device
 *
 * This command adds a partition to @device. If there is no partition table
 * on the device, call guestfs_session_part_init() first.
 * 
 * The @prlogex parameter is the type of partition. Normally you should
 * pass @p or @primary here, but MBR partition tables also support @l (or
 * @logical) and @e (or @extended) partition types.
 * 
 * @startsect and @endsect are the start and end of the partition in
 * *sectors*. @endsect may be negative, which means it counts backwards
 * from the end of the disk (@-1 is the last sector).
 * 
 * Creating a partition which covers the whole disk is not so easy. Use
 * guestfs_session_part_disk() to do that.
 * 
 * Returns: true on success, false on error
 * Since: 1.0.78
 */
gboolean
guestfs_session_part_add (GuestfsSession *session, const gchar *device, const gchar *prlogex, gint64 startsect, gint64 endsect, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "part_add");
    return FALSE;
  }

  int ret = guestfs_part_add (g, device, prlogex, startsect, endsect);
  if (ret == -1) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return FALSE;
  }

  return TRUE;
}

/**
 * guestfs_session_part_del:
 * @session: (transfer none): A GuestfsSession object
 * @device: (transfer none) (type filename):
 * @partnum: (type gint32):
 * @err: A GError object to receive any generated errors
 *
 * delete a partition
 *
 * This command deletes the partition numbered @partnum on @device.
 * 
 * Note that in the case of MBR partitioning, deleting an extended
 * partition also deletes any logical partitions it contains.
 * 
 * Returns: true on success, false on error
 * Since: 1.3.2
 */
gboolean
guestfs_session_part_del (GuestfsSession *session, const gchar *device, gint32 partnum, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "part_del");
    return FALSE;
  }

  int ret = guestfs_part_del (g, device, partnum);
  if (ret == -1) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return FALSE;
  }

  return TRUE;
}

/**
 * guestfs_session_part_disk:
 * @session: (transfer none): A GuestfsSession object
 * @device: (transfer none) (type filename):
 * @parttype: (transfer none) (type utf8):
 * @err: A GError object to receive any generated errors
 *
 * partition whole disk with a single primary partition
 *
 * This command is simply a combination of guestfs_session_part_init()
 * followed by guestfs_session_part_add() to create a single primary
 * partition covering the whole disk.
 * 
 * @parttype is the partition table type, usually @mbr or @gpt, but other
 * possible values are described in guestfs_session_part_init().
 * 
 * Returns: true on success, false on error
 * Since: 1.0.78
 */
gboolean
guestfs_session_part_disk (GuestfsSession *session, const gchar *device, const gchar *parttype, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "part_disk");
    return FALSE;
  }

  int ret = guestfs_part_disk (g, device, parttype);
  if (ret == -1) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return FALSE;
  }

  return TRUE;
}

/**
 * guestfs_session_part_get_bootable:
 * @session: (transfer none): A GuestfsSession object
 * @device: (transfer none) (type filename):
 * @partnum: (type gint32):
 * @err: A GError object to receive any generated errors
 *
 * return true if a partition is bootable
 *
 * This command returns true if the partition @partnum on @device has the
 * bootable flag set.
 * 
 * See also guestfs_session_part_set_bootable().
 * 
 * Returns: the returned value, or -1 on error
 * Since: 1.3.2
 */
gint8
guestfs_session_part_get_bootable (GuestfsSession *session, const gchar *device, gint32 partnum, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "part_get_bootable");
    return -1;
  }

  int ret = guestfs_part_get_bootable (g, device, partnum);
  if (ret == -1) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return -1;
  }

  return ret;
}

/**
 * guestfs_session_part_get_gpt_guid:
 * @session: (transfer none): A GuestfsSession object
 * @device: (transfer none) (type filename):
 * @partnum: (type gint32):
 * @err: A GError object to receive any generated errors
 *
 * get the GUID of a GPT partition
 *
 * Return the GUID of numbered GPT partition @partnum.
 * 
 * Returns: (transfer full): the returned string, or NULL on error
 * Since: 1.29.25
 */
gchar *
guestfs_session_part_get_gpt_guid (GuestfsSession *session, const gchar *device, gint32 partnum, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "part_get_gpt_guid");
    return NULL;
  }

  char *ret = guestfs_part_get_gpt_guid (g, device, partnum);
  if (ret == NULL) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return NULL;
  }

  return ret;
}

/**
 * guestfs_session_part_get_gpt_type:
 * @session: (transfer none): A GuestfsSession object
 * @device: (transfer none) (type filename):
 * @partnum: (type gint32):
 * @err: A GError object to receive any generated errors
 *
 * get the type GUID of a GPT partition
 *
 * Return the type GUID of numbered GPT partition @partnum. For MBR
 * partitions, return an appropriate GUID corresponding to the MBR type.
 * Behaviour is undefined for other partition types.
 * 
 * Returns: (transfer full): the returned string, or NULL on error
 * Since: 1.21.1
 */
gchar *
guestfs_session_part_get_gpt_type (GuestfsSession *session, const gchar *device, gint32 partnum, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "part_get_gpt_type");
    return NULL;
  }

  char *ret = guestfs_part_get_gpt_type (g, device, partnum);
  if (ret == NULL) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return NULL;
  }

  return ret;
}

/**
 * guestfs_session_part_get_mbr_id:
 * @session: (transfer none): A GuestfsSession object
 * @device: (transfer none) (type filename):
 * @partnum: (type gint32):
 * @err: A GError object to receive any generated errors
 *
 * get the MBR type byte (ID byte) from a partition
 *
 * Returns the MBR type byte (also known as the ID byte) from the numbered
 * partition @partnum.
 * 
 * Note that only MBR (old DOS-style) partitions have type bytes. You will
 * get undefined results for other partition table types (see
 * guestfs_session_part_get_parttype()).
 * 
 * Returns: the returned value, or -1 on error
 * Since: 1.3.2
 */
gint32
guestfs_session_part_get_mbr_id (GuestfsSession *session, const gchar *device, gint32 partnum, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "part_get_mbr_id");
    return -1;
  }

  int ret = guestfs_part_get_mbr_id (g, device, partnum);
  if (ret == -1) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return -1;
  }

  return ret;
}

/**
 * guestfs_session_part_get_mbr_part_type:
 * @session: (transfer none): A GuestfsSession object
 * @device: (transfer none) (type filename):
 * @partnum: (type gint32):
 * @err: A GError object to receive any generated errors
 *
 * get the MBR partition type
 *
 * This returns the partition type of an MBR partition numbered @partnum on
 * device @device.
 * 
 * It returns @primary, @logical, or @extended.
 * 
 * Returns: (transfer full): the returned string, or NULL on error
 * Since: 1.29.32
 */
gchar *
guestfs_session_part_get_mbr_part_type (GuestfsSession *session, const gchar *device, gint32 partnum, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "part_get_mbr_part_type");
    return NULL;
  }

  char *ret = guestfs_part_get_mbr_part_type (g, device, partnum);
  if (ret == NULL) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return NULL;
  }

  return ret;
}

/**
 * guestfs_session_part_get_name:
 * @session: (transfer none): A GuestfsSession object
 * @device: (transfer none) (type filename):
 * @partnum: (type gint32):
 * @err: A GError object to receive any generated errors
 *
 * get partition name
 *
 * This gets the partition name on partition numbered @partnum on device
 * @device. Note that partitions are numbered from 1.
 * 
 * The partition name can only be read on certain types of partition table.
 * This works on @gpt but not on @mbr partitions.
 * 
 * Returns: (transfer full): the returned string, or NULL on error
 * Since: 1.25.33
 */
gchar *
guestfs_session_part_get_name (GuestfsSession *session, const gchar *device, gint32 partnum, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "part_get_name");
    return NULL;
  }

  char *ret = guestfs_part_get_name (g, device, partnum);
  if (ret == NULL) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return NULL;
  }

  return ret;
}

/**
 * guestfs_session_part_get_parttype:
 * @session: (transfer none): A GuestfsSession object
 * @device: (transfer none) (type filename):
 * @err: A GError object to receive any generated errors
 *
 * get the partition table type
 *
 * This command examines the partition table on @device and returns the
 * partition table type (format) being used.
 * 
 * Common return values include: @msdos (a DOS/Windows style MBR partition
 * table), @gpt (a GPT/EFI-style partition table). Other values are
 * possible, although unusual. See guestfs_session_part_init() for a full
 * list.
 * 
 * Returns: (transfer full): the returned string, or NULL on error
 * Since: 1.0.78
 */
gchar *
guestfs_session_part_get_parttype (GuestfsSession *session, const gchar *device, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "part_get_parttype");
    return NULL;
  }

  char *ret = guestfs_part_get_parttype (g, device);
  if (ret == NULL) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return NULL;
  }

  return ret;
}

/**
 * guestfs_session_part_init:
 * @session: (transfer none): A GuestfsSession object
 * @device: (transfer none) (type filename):
 * @parttype: (transfer none) (type utf8):
 * @err: A GError object to receive any generated errors
 *
 * create an empty partition table
 *
 * This creates an empty partition table on @device of one of the partition
 * types listed below. Usually @parttype should be either @msdos or @gpt
 * (for large disks).
 * 
 * Initially there are no partitions. Following this, you should call
 * guestfs_session_part_add() for each partition required.
 * 
 * Possible values for @parttype are:
 * 
 * efi
 * gpt Intel EFI / GPT partition table.
 * 
 * This is recommended for >= 2 TB partitions that will be accessed
 * from Linux and Intel-based Mac OS X. It also has limited backwards
 * compatibility with the @mbr format.
 * 
 * mbr
 * msdos
 * The standard PC "Master Boot Record" (MBR) format used by MS-DOS and
 * Windows. This partition type will only work for device sizes up to 2
 * TB. For large disks we recommend using @gpt.
 * 
 * Other partition table types that may work but are not supported include:
 * 
 * aix AIX disk labels.
 * 
 * amiga
 * rdb Amiga "Rigid Disk Block" format.
 * 
 * bsd BSD disk labels.
 * 
 * dasd
 * DASD, used on IBM mainframes.
 * 
 * dvh MIPS/SGI volumes.
 * 
 * mac Old Mac partition format. Modern Macs use @gpt.
 * 
 * pc98
 * NEC PC-98 format, common in Japan apparently.
 * 
 * sun Sun disk labels.
 * 
 * Returns: true on success, false on error
 * Since: 1.0.78
 */
gboolean
guestfs_session_part_init (GuestfsSession *session, const gchar *device, const gchar *parttype, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "part_init");
    return FALSE;
  }

  int ret = guestfs_part_init (g, device, parttype);
  if (ret == -1) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return FALSE;
  }

  return TRUE;
}

/**
 * guestfs_session_part_list:
 * @session: (transfer none): A GuestfsSession object
 * @device: (transfer none) (type filename):
 * @err: A GError object to receive any generated errors
 *
 * list partitions on a device
 *
 * This command parses the partition table on @device and returns the list
 * of partitions found.
 * 
 * The fields in the returned structure are:
 * 
 * part_num
 * Partition number, counting from 1.
 * 
 * part_start
 * Start of the partition *in bytes*. To get sectors you have to divide
 * by the device's sector size, see guestfs_session_blockdev_getss().
 * 
 * part_end
 * End of the partition in bytes.
 * 
 * part_size
 * Size of the partition in bytes.
 * 
 * Returns: (transfer full) (array zero-terminated=1) (element-type GuestfsPartition): an array of Partition objects, or NULL on error
 * Since: 1.0.78
 */
GuestfsPartition **
guestfs_session_part_list (GuestfsSession *session, const gchar *device, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "part_list");
    return NULL;
  }

  struct guestfs_partition_list *ret = guestfs_part_list (g, device);
  if (ret == NULL) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return NULL;
  }

  GuestfsPartition **l = g_malloc (sizeof (GuestfsPartition*) * (ret->len + 1));
  gsize i;
  for (i = 0; i < ret->len; i++) {
    l[i] = g_slice_new0 (GuestfsPartition);
    l[i]->part_num = ret->val[i].part_num;
    l[i]->part_start = ret->val[i].part_start;
    l[i]->part_end = ret->val[i].part_end;
    l[i]->part_size = ret->val[i].part_size;
  }
  guestfs_free_partition_list (ret);
  l[i] = NULL;
  return l;
}

/**
 * guestfs_session_part_set_bootable:
 * @session: (transfer none): A GuestfsSession object
 * @device: (transfer none) (type filename):
 * @partnum: (type gint32):
 * @bootable: (type gboolean):
 * @err: A GError object to receive any generated errors
 *
 * make a partition bootable
 *
 * This sets the bootable flag on partition numbered @partnum on device
 * @device. Note that partitions are numbered from 1.
 * 
 * The bootable flag is used by some operating systems (notably Windows) to
 * determine which partition to boot from. It is by no means universally
 * recognized.
 * 
 * Returns: true on success, false on error
 * Since: 1.0.78
 */
gboolean
guestfs_session_part_set_bootable (GuestfsSession *session, const gchar *device, gint32 partnum, gboolean bootable, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "part_set_bootable");
    return FALSE;
  }

  int ret = guestfs_part_set_bootable (g, device, partnum, bootable);
  if (ret == -1) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return FALSE;
  }

  return TRUE;
}

/**
 * guestfs_session_part_set_gpt_guid:
 * @session: (transfer none): A GuestfsSession object
 * @device: (transfer none) (type filename):
 * @partnum: (type gint32):
 * @guid: (transfer none) (type utf8):
 * @err: A GError object to receive any generated errors
 *
 * set the GUID of a GPT partition
 *
 * Set the GUID of numbered GPT partition @partnum to @guid. Return an
 * error if the partition table of @device isn't GPT, or if @guid is not a
 * valid GUID.
 * 
 * Returns: true on success, false on error
 * Since: 1.29.25
 */
gboolean
guestfs_session_part_set_gpt_guid (GuestfsSession *session, const gchar *device, gint32 partnum, const gchar *guid, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "part_set_gpt_guid");
    return FALSE;
  }

  int ret = guestfs_part_set_gpt_guid (g, device, partnum, guid);
  if (ret == -1) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return FALSE;
  }

  return TRUE;
}

/**
 * guestfs_session_part_set_gpt_type:
 * @session: (transfer none): A GuestfsSession object
 * @device: (transfer none) (type filename):
 * @partnum: (type gint32):
 * @guid: (transfer none) (type utf8):
 * @err: A GError object to receive any generated errors
 *
 * set the type GUID of a GPT partition
 *
 * Set the type GUID of numbered GPT partition @partnum to @guid. Return an
 * error if the partition table of @device isn't GPT, or if @guid is not a
 * valid GUID.
 * 
 * See <ulink
 * url='http://en.wikipedia.org/wiki/GUID_Partition_Table#Partition_type_GU
 * IDs'>
 * http://en.wikipedia.org/wiki/GUID_Partition_Table#Partition_type_GUIDs
 * </ulink> for a useful list of type GUIDs.
 * 
 * Returns: true on success, false on error
 * Since: 1.21.1
 */
gboolean
guestfs_session_part_set_gpt_type (GuestfsSession *session, const gchar *device, gint32 partnum, const gchar *guid, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "part_set_gpt_type");
    return FALSE;
  }

  int ret = guestfs_part_set_gpt_type (g, device, partnum, guid);
  if (ret == -1) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return FALSE;
  }

  return TRUE;
}

/**
 * guestfs_session_part_set_mbr_id:
 * @session: (transfer none): A GuestfsSession object
 * @device: (transfer none) (type filename):
 * @partnum: (type gint32):
 * @idbyte: (type gint32):
 * @err: A GError object to receive any generated errors
 *
 * set the MBR type byte (ID byte) of a partition
 *
 * Sets the MBR type byte (also known as the ID byte) of the numbered
 * partition @partnum to @idbyte. Note that the type bytes quoted in most
 * documentation are in fact hexadecimal numbers, but usually documented
 * without any leading "0x" which might be confusing.
 * 
 * Note that only MBR (old DOS-style) partitions have type bytes. You will
 * get undefined results for other partition table types (see
 * guestfs_session_part_get_parttype()).
 * 
 * Returns: true on success, false on error
 * Since: 1.3.2
 */
gboolean
guestfs_session_part_set_mbr_id (GuestfsSession *session, const gchar *device, gint32 partnum, gint32 idbyte, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "part_set_mbr_id");
    return FALSE;
  }

  int ret = guestfs_part_set_mbr_id (g, device, partnum, idbyte);
  if (ret == -1) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return FALSE;
  }

  return TRUE;
}

/**
 * guestfs_session_part_set_name:
 * @session: (transfer none): A GuestfsSession object
 * @device: (transfer none) (type filename):
 * @partnum: (type gint32):
 * @name: (transfer none) (type utf8):
 * @err: A GError object to receive any generated errors
 *
 * set partition name
 *
 * This sets the partition name on partition numbered @partnum on device
 * @device. Note that partitions are numbered from 1.
 * 
 * The partition name can only be set on certain types of partition table.
 * This works on @gpt but not on @mbr partitions.
 * 
 * Returns: true on success, false on error
 * Since: 1.0.78
 */
gboolean
guestfs_session_part_set_name (GuestfsSession *session, const gchar *device, gint32 partnum, const gchar *name, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "part_set_name");
    return FALSE;
  }

  int ret = guestfs_part_set_name (g, device, partnum, name);
  if (ret == -1) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return FALSE;
  }

  return TRUE;
}

/**
 * guestfs_session_part_to_dev:
 * @session: (transfer none): A GuestfsSession object
 * @partition: (transfer none) (type filename):
 * @err: A GError object to receive any generated errors
 *
 * convert partition name to device name
 *
 * This function takes a partition name (eg. "/dev/sdb1") and removes the
 * partition number, returning the device name (eg. "/dev/sdb").
 * 
 * The named partition must exist, for example as a string returned from
 * guestfs_session_list_partitions().
 * 
 * See also guestfs_session_part_to_partnum(),
 * guestfs_session_device_index().
 * 
 * Returns: (transfer full): the returned string, or NULL on error
 * Since: 1.5.15
 */
gchar *
guestfs_session_part_to_dev (GuestfsSession *session, const gchar *partition, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "part_to_dev");
    return NULL;
  }

  char *ret = guestfs_part_to_dev (g, partition);
  if (ret == NULL) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return NULL;
  }

  return ret;
}

/**
 * guestfs_session_part_to_partnum:
 * @session: (transfer none): A GuestfsSession object
 * @partition: (transfer none) (type filename):
 * @err: A GError object to receive any generated errors
 *
 * convert partition name to partition number
 *
 * This function takes a partition name (eg. "/dev/sdb1") and returns the
 * partition number (eg. @1).
 * 
 * The named partition must exist, for example as a string returned from
 * guestfs_session_list_partitions().
 * 
 * See also guestfs_session_part_to_dev().
 * 
 * Returns: the returned value, or -1 on error
 * Since: 1.13.25
 */
gint32
guestfs_session_part_to_partnum (GuestfsSession *session, const gchar *partition, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "part_to_partnum");
    return -1;
  }

  int ret = guestfs_part_to_partnum (g, partition);
  if (ret == -1) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return -1;
  }

  return ret;
}

/**
 * guestfs_session_ping_daemon:
 * @session: (transfer none): A GuestfsSession object
 * @err: A GError object to receive any generated errors
 *
 * ping the guest daemon
 *
 * This is a test probe into the guestfs daemon running inside the
 * libguestfs appliance. Calling this function checks that the daemon
 * responds to the ping message, without affecting the daemon or attached
 * block device(s) in any other way.
 * 
 * Returns: true on success, false on error
 * Since: 1.0.18
 */
gboolean
guestfs_session_ping_daemon (GuestfsSession *session, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "ping_daemon");
    return FALSE;
  }

  int ret = guestfs_ping_daemon (g);
  if (ret == -1) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return FALSE;
  }

  return TRUE;
}

/**
 * guestfs_session_pread:
 * @session: (transfer none): A GuestfsSession object
 * @path: (transfer none) (type filename):
 * @count: (type gint32):
 * @offset: (type gint64):
 * @size_r: The size of the returned buffer, in bytes
 * @err: A GError object to receive any generated errors
 *
 * read part of a file
 *
 * This command lets you read part of a file. It reads @count bytes of the
 * file, starting at @offset, from file @path.
 * 
 * This may read fewer bytes than requested. For further details see the
 * pread(2) system call.
 * 
 * See also guestfs_session_pwrite(), guestfs_session_pread_device().
 * 
 * Returns: (transfer full) (array length=size_r) (element-type guint8): an array of binary data, or NULL on error
 * Since: 1.0.77
 */
guint8 *
guestfs_session_pread (GuestfsSession *session, const gchar *path, gint32 count, gint64 offset, gsize *size_r, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "pread");
    return NULL;
  }

  char *ret = guestfs_pread (g, path, count, offset, size_r);
  if (ret == NULL) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return NULL;
  }

  return (guint8 *) ret;
}

/**
 * guestfs_session_pread_device:
 * @session: (transfer none): A GuestfsSession object
 * @device: (transfer none) (type filename):
 * @count: (type gint32):
 * @offset: (type gint64):
 * @size_r: The size of the returned buffer, in bytes
 * @err: A GError object to receive any generated errors
 *
 * read part of a device
 *
 * This command lets you read part of a block device. It reads @count bytes
 * of @device, starting at @offset.
 * 
 * This may read fewer bytes than requested. For further details see the
 * pread(2) system call.
 * 
 * See also guestfs_session_pread().
 * 
 * Returns: (transfer full) (array length=size_r) (element-type guint8): an array of binary data, or NULL on error
 * Since: 1.5.21
 */
guint8 *
guestfs_session_pread_device (GuestfsSession *session, const gchar *device, gint32 count, gint64 offset, gsize *size_r, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "pread_device");
    return NULL;
  }

  char *ret = guestfs_pread_device (g, device, count, offset, size_r);
  if (ret == NULL) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return NULL;
  }

  return (guint8 *) ret;
}

/**
 * guestfs_session_pvchange_uuid:
 * @session: (transfer none): A GuestfsSession object
 * @device: (transfer none) (type filename):
 * @err: A GError object to receive any generated errors
 *
 * generate a new random UUID for a physical volume
 *
 * Generate a new random UUID for the physical volume @device.
 * 
 * Returns: true on success, false on error
 * Since: 1.19.26
 */
gboolean
guestfs_session_pvchange_uuid (GuestfsSession *session, const gchar *device, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "pvchange_uuid");
    return FALSE;
  }

  int ret = guestfs_pvchange_uuid (g, device);
  if (ret == -1) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return FALSE;
  }

  return TRUE;
}

/**
 * guestfs_session_pvchange_uuid_all:
 * @session: (transfer none): A GuestfsSession object
 * @err: A GError object to receive any generated errors
 *
 * generate new random UUIDs for all physical volumes
 *
 * Generate new random UUIDs for all physical volumes.
 * 
 * Returns: true on success, false on error
 * Since: 1.19.26
 */
gboolean
guestfs_session_pvchange_uuid_all (GuestfsSession *session, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "pvchange_uuid_all");
    return FALSE;
  }

  int ret = guestfs_pvchange_uuid_all (g);
  if (ret == -1) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return FALSE;
  }

  return TRUE;
}

/**
 * guestfs_session_pvcreate:
 * @session: (transfer none): A GuestfsSession object
 * @device: (transfer none) (type filename):
 * @err: A GError object to receive any generated errors
 *
 * create an LVM physical volume
 *
 * This creates an LVM physical volume on the named @device, where @device
 * should usually be a partition name such as /dev/sda1.
 * 
 * Returns: true on success, false on error
 * Since: 0.8
 */
gboolean
guestfs_session_pvcreate (GuestfsSession *session, const gchar *device, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "pvcreate");
    return FALSE;
  }

  int ret = guestfs_pvcreate (g, device);
  if (ret == -1) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return FALSE;
  }

  return TRUE;
}

/**
 * guestfs_session_pvremove:
 * @session: (transfer none): A GuestfsSession object
 * @device: (transfer none) (type filename):
 * @err: A GError object to receive any generated errors
 *
 * remove an LVM physical volume
 *
 * This wipes a physical volume @device so that LVM will no longer
 * recognise it.
 * 
 * The implementation uses the @pvremove command which refuses to wipe
 * physical volumes that contain any volume groups, so you have to remove
 * those first.
 * 
 * Returns: true on success, false on error
 * Since: 1.0.13
 */
gboolean
guestfs_session_pvremove (GuestfsSession *session, const gchar *device, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "pvremove");
    return FALSE;
  }

  int ret = guestfs_pvremove (g, device);
  if (ret == -1) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return FALSE;
  }

  return TRUE;
}

/**
 * guestfs_session_pvresize:
 * @session: (transfer none): A GuestfsSession object
 * @device: (transfer none) (type filename):
 * @err: A GError object to receive any generated errors
 *
 * resize an LVM physical volume
 *
 * This resizes (expands or shrinks) an existing LVM physical volume to
 * match the new size of the underlying device.
 * 
 * Returns: true on success, false on error
 * Since: 1.0.26
 */
gboolean
guestfs_session_pvresize (GuestfsSession *session, const gchar *device, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "pvresize");
    return FALSE;
  }

  int ret = guestfs_pvresize (g, device);
  if (ret == -1) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return FALSE;
  }

  return TRUE;
}

/**
 * guestfs_session_pvresize_size:
 * @session: (transfer none): A GuestfsSession object
 * @device: (transfer none) (type filename):
 * @size: (type gint64):
 * @err: A GError object to receive any generated errors
 *
 * resize an LVM physical volume (with size)
 *
 * This command is the same as guestfs_session_pvresize() except that it
 * allows you to specify the new size (in bytes) explicitly.
 * 
 * Returns: true on success, false on error
 * Since: 1.3.14
 */
gboolean
guestfs_session_pvresize_size (GuestfsSession *session, const gchar *device, gint64 size, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "pvresize_size");
    return FALSE;
  }

  int ret = guestfs_pvresize_size (g, device, size);
  if (ret == -1) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return FALSE;
  }

  return TRUE;
}

/**
 * guestfs_session_pvs:
 * @session: (transfer none): A GuestfsSession object
 * @err: A GError object to receive any generated errors
 *
 * list the LVM physical volumes (PVs)
 *
 * List all the physical volumes detected. This is the equivalent of the
 * pvs(8) command.
 * 
 * This returns a list of just the device names that contain PVs (eg.
 * /dev/sda2).
 * 
 * See also guestfs_session_pvs_full().
 * 
 * Returns: (transfer full) (array zero-terminated=1) (element-type utf8): an array of returned strings, or NULL on error
 * Since: 0.4
 */
gchar **
guestfs_session_pvs (GuestfsSession *session, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "pvs");
    return NULL;
  }

  char **ret = guestfs_pvs (g);
  if (ret == NULL) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return NULL;
  }

  return ret;
}

/**
 * guestfs_session_pvs_full:
 * @session: (transfer none): A GuestfsSession object
 * @err: A GError object to receive any generated errors
 *
 * list the LVM physical volumes (PVs)
 *
 * List all the physical volumes detected. This is the equivalent of the
 * pvs(8) command. The "full" version includes all fields.
 * 
 * Returns: (transfer full) (array zero-terminated=1) (element-type GuestfsPV): an array of PV objects, or NULL on error
 * Since: 0.4
 */
GuestfsPV **
guestfs_session_pvs_full (GuestfsSession *session, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "pvs_full");
    return NULL;
  }

  struct guestfs_lvm_pv_list *ret = guestfs_pvs_full (g);
  if (ret == NULL) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return NULL;
  }

  GuestfsPV **l = g_malloc (sizeof (GuestfsPV*) * (ret->len + 1));
  gsize i;
  for (i = 0; i < ret->len; i++) {
    l[i] = g_slice_new0 (GuestfsPV);
    if (ret->val[i].pv_name) l[i]->pv_name = g_strdup (ret->val[i].pv_name);
    if (ret->val[i].pv_uuid) memcpy (l[i]->pv_uuid, ret->val[i].pv_uuid, sizeof (l[i]->pv_uuid));
    if (ret->val[i].pv_fmt) l[i]->pv_fmt = g_strdup (ret->val[i].pv_fmt);
    l[i]->pv_size = ret->val[i].pv_size;
    l[i]->dev_size = ret->val[i].dev_size;
    l[i]->pv_free = ret->val[i].pv_free;
    l[i]->pv_used = ret->val[i].pv_used;
    if (ret->val[i].pv_attr) l[i]->pv_attr = g_strdup (ret->val[i].pv_attr);
    l[i]->pv_pe_count = ret->val[i].pv_pe_count;
    l[i]->pv_pe_alloc_count = ret->val[i].pv_pe_alloc_count;
    if (ret->val[i].pv_tags) l[i]->pv_tags = g_strdup (ret->val[i].pv_tags);
    l[i]->pe_start = ret->val[i].pe_start;
    l[i]->pv_mda_count = ret->val[i].pv_mda_count;
    l[i]->pv_mda_free = ret->val[i].pv_mda_free;
  }
  guestfs_free_lvm_pv_list (ret);
  l[i] = NULL;
  return l;
}

/**
 * guestfs_session_pvuuid:
 * @session: (transfer none): A GuestfsSession object
 * @device: (transfer none) (type filename):
 * @err: A GError object to receive any generated errors
 *
 * get the UUID of a physical volume
 *
 * This command returns the UUID of the LVM PV @device.
 * 
 * Returns: (transfer full): the returned string, or NULL on error
 * Since: 1.0.87
 */
gchar *
guestfs_session_pvuuid (GuestfsSession *session, const gchar *device, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "pvuuid");
    return NULL;
  }

  char *ret = guestfs_pvuuid (g, device);
  if (ret == NULL) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return NULL;
  }

  return ret;
}

/**
 * guestfs_session_pwrite:
 * @session: (transfer none): A GuestfsSession object
 * @path: (transfer none) (type filename):
 * @content: (transfer none) (array length=content_size) (element-type guint8): an array of binary data
 * @content_size: The size of content, in bytes
 * @offset: (type gint64):
 * @err: A GError object to receive any generated errors
 *
 * write to part of a file
 *
 * This command writes to part of a file. It writes the data buffer
 * @content to the file @path starting at offset @offset.
 * 
 * This command implements the pwrite(2) system call, and like that system
 * call it may not write the full data requested. The return value is the
 * number of bytes that were actually written to the file. This could even
 * be 0, although short writes are unlikely for regular files in ordinary
 * circumstances.
 * 
 * See also guestfs_session_pread(), guestfs_session_pwrite_device().
 * 
 * Returns: the returned value, or -1 on error
 * Since: 1.3.14
 */
gint32
guestfs_session_pwrite (GuestfsSession *session, const gchar *path, const guint8 *content, gsize content_size, gint64 offset, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "pwrite");
    return -1;
  }

  int ret = guestfs_pwrite (g, path, (const char *) content, content_size, offset);
  if (ret == -1) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return -1;
  }

  return ret;
}

/**
 * guestfs_session_pwrite_device:
 * @session: (transfer none): A GuestfsSession object
 * @device: (transfer none) (type filename):
 * @content: (transfer none) (array length=content_size) (element-type guint8): an array of binary data
 * @content_size: The size of content, in bytes
 * @offset: (type gint64):
 * @err: A GError object to receive any generated errors
 *
 * write to part of a device
 *
 * This command writes to part of a device. It writes the data buffer
 * @content to @device starting at offset @offset.
 * 
 * This command implements the pwrite(2) system call, and like that system
 * call it may not write the full data requested (although short writes to
 * disk devices and partitions are probably impossible with standard Linux
 * kernels).
 * 
 * See also guestfs_session_pwrite().
 * 
 * Returns: the returned value, or -1 on error
 * Since: 1.5.20
 */
gint32
guestfs_session_pwrite_device (GuestfsSession *session, const gchar *device, const guint8 *content, gsize content_size, gint64 offset, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "pwrite_device");
    return -1;
  }

  int ret = guestfs_pwrite_device (g, device, (const char *) content, content_size, offset);
  if (ret == -1) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return -1;
  }

  return ret;
}

/**
 * guestfs_session_read_file:
 * @session: (transfer none): A GuestfsSession object
 * @path: (transfer none) (type filename):
 * @size_r: The size of the returned buffer, in bytes
 * @err: A GError object to receive any generated errors
 *
 * read a file
 *
 * This calls returns the contents of the file @path as a buffer.
 * 
 * Unlike guestfs_session_cat(), this function can correctly handle files
 * that contain embedded ASCII NUL characters.
 * 
 * Returns: (transfer full) (array length=size_r) (element-type guint8): an array of binary data, or NULL on error
 * Since: 1.0.63
 */
guint8 *
guestfs_session_read_file (GuestfsSession *session, const gchar *path, gsize *size_r, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "read_file");
    return NULL;
  }

  char *ret = guestfs_read_file (g, path, size_r);
  if (ret == NULL) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return NULL;
  }

  return (guint8 *) ret;
}

/**
 * guestfs_session_read_lines:
 * @session: (transfer none): A GuestfsSession object
 * @path: (transfer none) (type filename):
 * @err: A GError object to receive any generated errors
 *
 * read file as lines
 *
 * Return the contents of the file named @path.
 * 
 * The file contents are returned as a list of lines. Trailing @LF and
 * @CRLF character sequences are *not* returned.
 * 
 * Note that this function cannot correctly handle binary files
 * (specifically, files containing "\0" character which is treated as end
 * of string). For those you need to use the guestfs_session_read_file()
 * function and split the buffer into lines yourself.
 * 
 * Returns: (transfer full) (array zero-terminated=1) (element-type utf8): an array of returned strings, or NULL on error
 * Since: 0.7
 */
gchar **
guestfs_session_read_lines (GuestfsSession *session, const gchar *path, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "read_lines");
    return NULL;
  }

  char **ret = guestfs_read_lines (g, path);
  if (ret == NULL) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return NULL;
  }

  return ret;
}

/**
 * guestfs_session_readdir:
 * @session: (transfer none): A GuestfsSession object
 * @dir: (transfer none) (type filename):
 * @err: A GError object to receive any generated errors
 *
 * read directories entries
 *
 * This returns the list of directory entries in directory @dir.
 * 
 * All entries in the directory are returned, including "." and "..". The
 * entries are *not* sorted, but returned in the same order as the
 * underlying filesystem.
 * 
 * Also this call returns basic file type information about each file. The
 * @ftyp field will contain one of the following characters:
 * 
 * 'b' Block special
 * 
 * 'c' Char special
 * 
 * 'd' Directory
 * 
 * 'f' FIFO (named pipe)
 * 
 * 'l' Symbolic link
 * 
 * 'r' Regular file
 * 
 * 's' Socket
 * 
 * 'u' Unknown file type
 * 
 * '?' The readdir(3) call returned a @d_type field with an unexpected
 * value
 * 
 * This function is primarily intended for use by programs. To get a simple
 * list of names, use guestfs_session_ls(). To get a printable directory
 * for human consumption, use guestfs_session_ll().
 * 
 * Returns: (transfer full) (array zero-terminated=1) (element-type GuestfsDirent): an array of Dirent objects, or NULL on error
 * Since: 1.0.55
 */
GuestfsDirent **
guestfs_session_readdir (GuestfsSession *session, const gchar *dir, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "readdir");
    return NULL;
  }

  struct guestfs_dirent_list *ret = guestfs_readdir (g, dir);
  if (ret == NULL) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return NULL;
  }

  GuestfsDirent **l = g_malloc (sizeof (GuestfsDirent*) * (ret->len + 1));
  gsize i;
  for (i = 0; i < ret->len; i++) {
    l[i] = g_slice_new0 (GuestfsDirent);
    l[i]->ino = ret->val[i].ino;
    l[i]->ftyp = ret->val[i].ftyp;
    if (ret->val[i].name) l[i]->name = g_strdup (ret->val[i].name);
  }
  guestfs_free_dirent_list (ret);
  l[i] = NULL;
  return l;
}

/**
 * guestfs_session_readlink:
 * @session: (transfer none): A GuestfsSession object
 * @path: (transfer none) (type filename):
 * @err: A GError object to receive any generated errors
 *
 * read the target of a symbolic link
 *
 * This command reads the target of a symbolic link.
 * 
 * Returns: (transfer full): the returned string, or NULL on error
 * Since: 1.0.66
 */
gchar *
guestfs_session_readlink (GuestfsSession *session, const gchar *path, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "readlink");
    return NULL;
  }

  char *ret = guestfs_readlink (g, path);
  if (ret == NULL) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return NULL;
  }

  return ret;
}

/**
 * guestfs_session_readlinklist:
 * @session: (transfer none): A GuestfsSession object
 * @path: (transfer none) (type filename):
 * @names: (transfer none) (array zero-terminated=1) (element-type utf8): an array of strings
 * @err: A GError object to receive any generated errors
 *
 * readlink on multiple files
 *
 * This call allows you to do a @readlink operation on multiple files,
 * where all files are in the directory @path. @names is the list of files
 * from this directory.
 * 
 * On return you get a list of strings, with a one-to-one correspondence to
 * the @names list. Each string is the value of the symbolic link.
 * 
 * If the readlink(2) operation fails on any name, then the corresponding
 * result string is the empty string "". However the whole operation is
 * completed even if there were readlink(2) errors, and so you can call
 * this function with names where you don't know if they are symbolic links
 * already (albeit slightly less efficient).
 * 
 * This call is intended for programs that want to efficiently list a
 * directory contents without making many round-trips.
 * 
 * Returns: (transfer full) (array zero-terminated=1) (element-type utf8): an array of returned strings, or NULL on error
 * Since: 1.0.77
 */
gchar **
guestfs_session_readlinklist (GuestfsSession *session, const gchar *path, gchar *const *names, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "readlinklist");
    return NULL;
  }

  char **ret = guestfs_readlinklist (g, path, names);
  if (ret == NULL) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return NULL;
  }

  return ret;
}

/**
 * guestfs_session_realpath:
 * @session: (transfer none): A GuestfsSession object
 * @path: (transfer none) (type filename):
 * @err: A GError object to receive any generated errors
 *
 * canonicalized absolute pathname
 *
 * Return the canonicalized absolute pathname of @path. The returned path
 * has no ".", ".." or symbolic link path elements.
 * 
 * Returns: (transfer full): the returned string, or NULL on error
 * Since: 1.0.66
 */
gchar *
guestfs_session_realpath (GuestfsSession *session, const gchar *path, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "realpath");
    return NULL;
  }

  char *ret = guestfs_realpath (g, path);
  if (ret == NULL) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return NULL;
  }

  return ret;
}

/**
 * guestfs_session_remount:
 * @session: (transfer none): A GuestfsSession object
 * @mountpoint: (transfer none) (type filename):
 * @optargs: (transfer none) (allow-none): a GuestfsRemount containing optional arguments
 * @err: A GError object to receive any generated errors
 *
 * remount a filesystem with different options
 *
 * This call allows you to change the @rw (readonly/read-write) flag on an
 * already mounted filesystem at @mountpoint, converting a readonly
 * filesystem to be read-write, or vice-versa.
 * 
 * Note that at the moment you must supply the "optional" @rw parameter. In
 * future we may allow other flags to be adjusted.
 * 
 * Returns: true on success, false on error
 * Since: 1.23.2
 */
gboolean
guestfs_session_remount (GuestfsSession *session, const gchar *mountpoint, GuestfsRemount *optargs, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "remount");
    return FALSE;
  }

  struct guestfs_remount_argv argv;
  struct guestfs_remount_argv *argvp = NULL;

  if (optargs) {
    argv.bitmask = 0;

    GValue rw_v = {0, };
    g_value_init (&rw_v, GUESTFS_TYPE_TRISTATE);
    g_object_get_property (G_OBJECT (optargs), "rw", &rw_v);
    GuestfsTristate rw = g_value_get_enum (&rw_v);
    if (rw != GUESTFS_TRISTATE_NONE) {
      argv.bitmask |= GUESTFS_REMOUNT_RW_BITMASK;
      argv.rw = rw;
    }
    argvp = &argv;
  }
  int ret = guestfs_remount_argv (g, mountpoint, argvp);
  if (ret == -1) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return FALSE;
  }

  return TRUE;
}

/**
 * guestfs_session_remove_drive:
 * @session: (transfer none): A GuestfsSession object
 * @label: (transfer none) (type utf8):
 * @err: A GError object to receive any generated errors
 *
 * remove a disk image
 *
 * This function is conceptually the opposite of
 * guestfs_session_add_drive_opts(). It removes the drive that was
 * previously added with label @label.
 * 
 * Note that in order to remove drives, you have to add them with labels
 * (see the optional @label argument to guestfs_session_add_drive_opts()).
 * If you didn't use a label, then they cannot be removed.
 * 
 * You can call this function before or after launching the handle. If
 * called after launch, if the backend supports it, we try to hot unplug
 * the drive: see "HOTPLUGGING" in guestfs(3). The disk must not be in use
 * (eg. mounted) when you do this. We try to detect if the disk is in use
 * and stop you from doing this.
 * 
 * Returns: true on success, false on error
 * Since: 1.19.49
 */
gboolean
guestfs_session_remove_drive (GuestfsSession *session, const gchar *label, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "remove_drive");
    return FALSE;
  }

  int ret = guestfs_remove_drive (g, label);
  if (ret == -1) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return FALSE;
  }

  return TRUE;
}

/**
 * guestfs_session_removexattr:
 * @session: (transfer none): A GuestfsSession object
 * @xattr: (transfer none) (type utf8):
 * @path: (transfer none) (type filename):
 * @err: A GError object to receive any generated errors
 *
 * remove extended attribute of a file or directory
 *
 * This call removes the extended attribute named @xattr of the file @path.
 * 
 * See also: guestfs_session_lremovexattr(), attr(5).
 * 
 * Returns: true on success, false on error
 * Since: 1.0.59
 */
gboolean
guestfs_session_removexattr (GuestfsSession *session, const gchar *xattr, const gchar *path, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "removexattr");
    return FALSE;
  }

  int ret = guestfs_removexattr (g, xattr, path);
  if (ret == -1) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return FALSE;
  }

  return TRUE;
}

/**
 * guestfs_session_rename:
 * @session: (transfer none): A GuestfsSession object
 * @oldpath: (transfer none) (type filename):
 * @newpath: (transfer none) (type filename):
 * @err: A GError object to receive any generated errors
 *
 * rename a file on the same filesystem
 *
 * Rename a file to a new place on the same filesystem. This is the same as
 * the Linux rename(2) system call. In most cases you are better to use
 * guestfs_session_mv() instead.
 * 
 * Returns: true on success, false on error
 * Since: 1.21.5
 */
gboolean
guestfs_session_rename (GuestfsSession *session, const gchar *oldpath, const gchar *newpath, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "rename");
    return FALSE;
  }

  int ret = guestfs_rename (g, oldpath, newpath);
  if (ret == -1) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return FALSE;
  }

  return TRUE;
}

/**
 * guestfs_session_resize2fs:
 * @session: (transfer none): A GuestfsSession object
 * @device: (transfer none) (type filename):
 * @err: A GError object to receive any generated errors
 *
 * resize an ext2, ext3 or ext4 filesystem
 *
 * This resizes an ext2, ext3 or ext4 filesystem to match the size of the
 * underlying device.
 * 
 * See also "RESIZE2FS ERRORS" in guestfs(3).
 * 
 * Returns: true on success, false on error
 * Since: 1.0.27
 */
gboolean
guestfs_session_resize2fs (GuestfsSession *session, const gchar *device, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "resize2fs");
    return FALSE;
  }

  int ret = guestfs_resize2fs (g, device);
  if (ret == -1) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return FALSE;
  }

  return TRUE;
}

/**
 * guestfs_session_resize2fs_M:
 * @session: (transfer none): A GuestfsSession object
 * @device: (transfer none) (type filename):
 * @err: A GError object to receive any generated errors
 *
 * resize an ext2, ext3 or ext4 filesystem to the minimum size
 *
 * This command is the same as guestfs_session_resize2fs(), but the
 * filesystem is resized to its minimum size. This works like the *-M*
 * option to the @resize2fs command.
 * 
 * To get the resulting size of the filesystem you should call
 * guestfs_session_tune2fs_l() and read the "Block size" and "Block count"
 * values. These two numbers, multiplied together, give the resulting size
 * of the minimal filesystem in bytes.
 * 
 * See also "RESIZE2FS ERRORS" in guestfs(3).
 * 
 * Returns: true on success, false on error
 * Since: 1.9.4
 */
gboolean
guestfs_session_resize2fs_M (GuestfsSession *session, const gchar *device, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "resize2fs_M");
    return FALSE;
  }

  int ret = guestfs_resize2fs_M (g, device);
  if (ret == -1) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return FALSE;
  }

  return TRUE;
}

/**
 * guestfs_session_resize2fs_size:
 * @session: (transfer none): A GuestfsSession object
 * @device: (transfer none) (type filename):
 * @size: (type gint64):
 * @err: A GError object to receive any generated errors
 *
 * resize an ext2, ext3 or ext4 filesystem (with size)
 *
 * This command is the same as guestfs_session_resize2fs() except that it
 * allows you to specify the new size (in bytes) explicitly.
 * 
 * See also "RESIZE2FS ERRORS" in guestfs(3).
 * 
 * Returns: true on success, false on error
 * Since: 1.3.14
 */
gboolean
guestfs_session_resize2fs_size (GuestfsSession *session, const gchar *device, gint64 size, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "resize2fs_size");
    return FALSE;
  }

  int ret = guestfs_resize2fs_size (g, device, size);
  if (ret == -1) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return FALSE;
  }

  return TRUE;
}

/**
 * guestfs_session_rm:
 * @session: (transfer none): A GuestfsSession object
 * @path: (transfer none) (type filename):
 * @err: A GError object to receive any generated errors
 *
 * remove a file
 *
 * Remove the single file @path.
 * 
 * Returns: true on success, false on error
 * Since: 0.8
 */
gboolean
guestfs_session_rm (GuestfsSession *session, const gchar *path, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "rm");
    return FALSE;
  }

  int ret = guestfs_rm (g, path);
  if (ret == -1) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return FALSE;
  }

  return TRUE;
}

/**
 * guestfs_session_rm_f:
 * @session: (transfer none): A GuestfsSession object
 * @path: (transfer none) (type filename):
 * @err: A GError object to receive any generated errors
 *
 * remove a file ignoring errors
 *
 * Remove the file @path.
 * 
 * If the file doesn't exist, that error is ignored. (Other errors, eg. I/O
 * errors or bad paths, are not ignored)
 * 
 * This call cannot remove directories. Use guestfs_session_rmdir() to
 * remove an empty directory, or guestfs_session_rm_rf() to remove
 * directories recursively.
 * 
 * Returns: true on success, false on error
 * Since: 1.19.42
 */
gboolean
guestfs_session_rm_f (GuestfsSession *session, const gchar *path, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "rm_f");
    return FALSE;
  }

  int ret = guestfs_rm_f (g, path);
  if (ret == -1) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return FALSE;
  }

  return TRUE;
}

/**
 * guestfs_session_rm_rf:
 * @session: (transfer none): A GuestfsSession object
 * @path: (transfer none) (type filename):
 * @err: A GError object to receive any generated errors
 *
 * remove a file or directory recursively
 *
 * Remove the file or directory @path, recursively removing the contents if
 * its a directory. This is like the "rm -rf" shell command.
 * 
 * Returns: true on success, false on error
 * Since: 0.8
 */
gboolean
guestfs_session_rm_rf (GuestfsSession *session, const gchar *path, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "rm_rf");
    return FALSE;
  }

  int ret = guestfs_rm_rf (g, path);
  if (ret == -1) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return FALSE;
  }

  return TRUE;
}

/**
 * guestfs_session_rmdir:
 * @session: (transfer none): A GuestfsSession object
 * @path: (transfer none) (type filename):
 * @err: A GError object to receive any generated errors
 *
 * remove a directory
 *
 * Remove the single directory @path.
 * 
 * Returns: true on success, false on error
 * Since: 0.8
 */
gboolean
guestfs_session_rmdir (GuestfsSession *session, const gchar *path, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "rmdir");
    return FALSE;
  }

  int ret = guestfs_rmdir (g, path);
  if (ret == -1) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return FALSE;
  }

  return TRUE;
}

/**
 * guestfs_session_rmmountpoint:
 * @session: (transfer none): A GuestfsSession object
 * @exemptpath: (transfer none) (type utf8):
 * @err: A GError object to receive any generated errors
 *
 * remove a mountpoint
 *
 * This calls removes a mountpoint that was previously created with
 * guestfs_session_mkmountpoint(). See guestfs_session_mkmountpoint() for
 * full details.
 * 
 * Returns: true on success, false on error
 * Since: 1.0.62
 */
gboolean
guestfs_session_rmmountpoint (GuestfsSession *session, const gchar *exemptpath, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "rmmountpoint");
    return FALSE;
  }

  int ret = guestfs_rmmountpoint (g, exemptpath);
  if (ret == -1) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return FALSE;
  }

  return TRUE;
}

/**
 * guestfs_session_rsync:
 * @session: (transfer none): A GuestfsSession object
 * @src: (transfer none) (type filename):
 * @dest: (transfer none) (type filename):
 * @optargs: (transfer none) (allow-none): a GuestfsRsync containing optional arguments
 * @err: A GError object to receive any generated errors
 *
 * synchronize the contents of two directories
 *
 * This call may be used to copy or synchronize two directories under the
 * same libguestfs handle. This uses the rsync(1) program which uses a fast
 * algorithm that avoids copying files unnecessarily.
 * 
 * @src and @dest are the source and destination directories. Files are
 * copied from @src to @dest.
 * 
 * The optional arguments are:
 * 
 * @archive
 * Turns on archive mode. This is the same as passing the *--archive*
 * flag to @rsync.
 * 
 * @deletedest
 * Delete files at the destination that do not exist at the source.
 * 
 * Returns: true on success, false on error
 * Since: 1.19.29
 */
gboolean
guestfs_session_rsync (GuestfsSession *session, const gchar *src, const gchar *dest, GuestfsRsync *optargs, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "rsync");
    return FALSE;
  }

  struct guestfs_rsync_argv argv;
  struct guestfs_rsync_argv *argvp = NULL;

  if (optargs) {
    argv.bitmask = 0;

    GValue archive_v = {0, };
    g_value_init (&archive_v, GUESTFS_TYPE_TRISTATE);
    g_object_get_property (G_OBJECT (optargs), "archive", &archive_v);
    GuestfsTristate archive = g_value_get_enum (&archive_v);
    if (archive != GUESTFS_TRISTATE_NONE) {
      argv.bitmask |= GUESTFS_RSYNC_ARCHIVE_BITMASK;
      argv.archive = archive;
    }
    GValue deletedest_v = {0, };
    g_value_init (&deletedest_v, GUESTFS_TYPE_TRISTATE);
    g_object_get_property (G_OBJECT (optargs), "deletedest", &deletedest_v);
    GuestfsTristate deletedest = g_value_get_enum (&deletedest_v);
    if (deletedest != GUESTFS_TRISTATE_NONE) {
      argv.bitmask |= GUESTFS_RSYNC_DELETEDEST_BITMASK;
      argv.deletedest = deletedest;
    }
    argvp = &argv;
  }
  int ret = guestfs_rsync_argv (g, src, dest, argvp);
  if (ret == -1) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return FALSE;
  }

  return TRUE;
}

/**
 * guestfs_session_rsync_in:
 * @session: (transfer none): A GuestfsSession object
 * @remote: (transfer none) (type utf8):
 * @dest: (transfer none) (type filename):
 * @optargs: (transfer none) (allow-none): a GuestfsRsyncIn containing optional arguments
 * @err: A GError object to receive any generated errors
 *
 * synchronize host or remote filesystem with filesystem
 *
 * This call may be used to copy or synchronize the filesystem on the host
 * or on a remote computer with the filesystem within libguestfs. This uses
 * the rsync(1) program which uses a fast algorithm that avoids copying
 * files unnecessarily.
 * 
 * This call only works if the network is enabled. See
 * guestfs_session_set_network() or the *--network* option to various tools
 * like guestfish(1).
 * 
 * Files are copied from the remote server and directory specified by
 * @remote to the destination directory @dest.
 * 
 * The format of the remote server string is defined by rsync(1). Note that
 * there is no way to supply a password or passphrase so the target must be
 * set up not to require one.
 * 
 * The optional arguments are the same as those of guestfs_session_rsync().
 * 
 * Returns: true on success, false on error
 * Since: 1.19.29
 */
gboolean
guestfs_session_rsync_in (GuestfsSession *session, const gchar *remote, const gchar *dest, GuestfsRsyncIn *optargs, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "rsync_in");
    return FALSE;
  }

  struct guestfs_rsync_in_argv argv;
  struct guestfs_rsync_in_argv *argvp = NULL;

  if (optargs) {
    argv.bitmask = 0;

    GValue archive_v = {0, };
    g_value_init (&archive_v, GUESTFS_TYPE_TRISTATE);
    g_object_get_property (G_OBJECT (optargs), "archive", &archive_v);
    GuestfsTristate archive = g_value_get_enum (&archive_v);
    if (archive != GUESTFS_TRISTATE_NONE) {
      argv.bitmask |= GUESTFS_RSYNC_IN_ARCHIVE_BITMASK;
      argv.archive = archive;
    }
    GValue deletedest_v = {0, };
    g_value_init (&deletedest_v, GUESTFS_TYPE_TRISTATE);
    g_object_get_property (G_OBJECT (optargs), "deletedest", &deletedest_v);
    GuestfsTristate deletedest = g_value_get_enum (&deletedest_v);
    if (deletedest != GUESTFS_TRISTATE_NONE) {
      argv.bitmask |= GUESTFS_RSYNC_IN_DELETEDEST_BITMASK;
      argv.deletedest = deletedest;
    }
    argvp = &argv;
  }
  int ret = guestfs_rsync_in_argv (g, remote, dest, argvp);
  if (ret == -1) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return FALSE;
  }

  return TRUE;
}

/**
 * guestfs_session_rsync_out:
 * @session: (transfer none): A GuestfsSession object
 * @src: (transfer none) (type filename):
 * @remote: (transfer none) (type utf8):
 * @optargs: (transfer none) (allow-none): a GuestfsRsyncOut containing optional arguments
 * @err: A GError object to receive any generated errors
 *
 * synchronize filesystem with host or remote filesystem
 *
 * This call may be used to copy or synchronize the filesystem within
 * libguestfs with a filesystem on the host or on a remote computer. This
 * uses the rsync(1) program which uses a fast algorithm that avoids
 * copying files unnecessarily.
 * 
 * This call only works if the network is enabled. See
 * guestfs_session_set_network() or the *--network* option to various tools
 * like guestfish(1).
 * 
 * Files are copied from the source directory @src to the remote server and
 * directory specified by @remote.
 * 
 * The format of the remote server string is defined by rsync(1). Note that
 * there is no way to supply a password or passphrase so the target must be
 * set up not to require one.
 * 
 * The optional arguments are the same as those of guestfs_session_rsync().
 * 
 * Globbing does not happen on the @src parameter. In programs which use
 * the API directly you have to expand wildcards yourself (see
 * guestfs_session_glob_expand()). In guestfish you can use the @glob
 * command (see "glob" in guestfish(1)), for example:
 * 
 * <![CDATA[><fs> glob rsync-out /* rsync://remote/]]>
 * 
 * Returns: true on success, false on error
 * Since: 1.19.29
 */
gboolean
guestfs_session_rsync_out (GuestfsSession *session, const gchar *src, const gchar *remote, GuestfsRsyncOut *optargs, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "rsync_out");
    return FALSE;
  }

  struct guestfs_rsync_out_argv argv;
  struct guestfs_rsync_out_argv *argvp = NULL;

  if (optargs) {
    argv.bitmask = 0;

    GValue archive_v = {0, };
    g_value_init (&archive_v, GUESTFS_TYPE_TRISTATE);
    g_object_get_property (G_OBJECT (optargs), "archive", &archive_v);
    GuestfsTristate archive = g_value_get_enum (&archive_v);
    if (archive != GUESTFS_TRISTATE_NONE) {
      argv.bitmask |= GUESTFS_RSYNC_OUT_ARCHIVE_BITMASK;
      argv.archive = archive;
    }
    GValue deletedest_v = {0, };
    g_value_init (&deletedest_v, GUESTFS_TYPE_TRISTATE);
    g_object_get_property (G_OBJECT (optargs), "deletedest", &deletedest_v);
    GuestfsTristate deletedest = g_value_get_enum (&deletedest_v);
    if (deletedest != GUESTFS_TRISTATE_NONE) {
      argv.bitmask |= GUESTFS_RSYNC_OUT_DELETEDEST_BITMASK;
      argv.deletedest = deletedest;
    }
    argvp = &argv;
  }
  int ret = guestfs_rsync_out_argv (g, src, remote, argvp);
  if (ret == -1) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return FALSE;
  }

  return TRUE;
}

/**
 * guestfs_session_scrub_device:
 * @session: (transfer none): A GuestfsSession object
 * @device: (transfer none) (type filename):
 * @err: A GError object to receive any generated errors
 *
 * scrub (securely wipe) a device
 *
 * This command writes patterns over @device to make data retrieval more
 * difficult.
 * 
 * It is an interface to the scrub(1) program. See that manual page for
 * more details.
 * 
 * Returns: true on success, false on error
 * Since: 1.0.52
 */
gboolean
guestfs_session_scrub_device (GuestfsSession *session, const gchar *device, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "scrub_device");
    return FALSE;
  }

  int ret = guestfs_scrub_device (g, device);
  if (ret == -1) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return FALSE;
  }

  return TRUE;
}

/**
 * guestfs_session_scrub_file:
 * @session: (transfer none): A GuestfsSession object
 * @file: (transfer none) (type filename):
 * @err: A GError object to receive any generated errors
 *
 * scrub (securely wipe) a file
 *
 * This command writes patterns over a file to make data retrieval more
 * difficult.
 * 
 * The file is *removed* after scrubbing.
 * 
 * It is an interface to the scrub(1) program. See that manual page for
 * more details.
 * 
 * Returns: true on success, false on error
 * Since: 1.0.52
 */
gboolean
guestfs_session_scrub_file (GuestfsSession *session, const gchar *file, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "scrub_file");
    return FALSE;
  }

  int ret = guestfs_scrub_file (g, file);
  if (ret == -1) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return FALSE;
  }

  return TRUE;
}

/**
 * guestfs_session_scrub_freespace:
 * @session: (transfer none): A GuestfsSession object
 * @dir: (transfer none) (type filename):
 * @err: A GError object to receive any generated errors
 *
 * scrub (securely wipe) free space
 *
 * This command creates the directory @dir and then fills it with files
 * until the filesystem is full, and scrubs the files as for
 * guestfs_session_scrub_file(), and deletes them. The intention is to
 * scrub any free space on the partition containing @dir.
 * 
 * It is an interface to the scrub(1) program. See that manual page for
 * more details.
 * 
 * Returns: true on success, false on error
 * Since: 1.0.52
 */
gboolean
guestfs_session_scrub_freespace (GuestfsSession *session, const gchar *dir, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "scrub_freespace");
    return FALSE;
  }

  int ret = guestfs_scrub_freespace (g, dir);
  if (ret == -1) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return FALSE;
  }

  return TRUE;
}

/**
 * guestfs_session_set_append:
 * @session: (transfer none): A GuestfsSession object
 * @append: (transfer none) (type utf8) (allow-none):
 * @err: A GError object to receive any generated errors
 *
 * add options to kernel command line
 *
 * This function is used to add additional options to the libguestfs
 * appliance kernel command line.
 * 
 * The default is @NULL unless overridden by setting @LIBGUESTFS_APPEND
 * environment variable.
 * 
 * Setting @append to @NULL means *no* additional options are passed
 * (libguestfs always adds a few of its own).
 * 
 * Returns: true on success, false on error
 * Since: 1.0.26
 */
gboolean
guestfs_session_set_append (GuestfsSession *session, const gchar *append, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "set_append");
    return FALSE;
  }

  int ret = guestfs_set_append (g, append);
  if (ret == -1) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return FALSE;
  }

  return TRUE;
}

/**
 * guestfs_session_set_attach_method:
 * @session: (transfer none): A GuestfsSession object
 * @backend: (transfer none) (type utf8):
 * @err: A GError object to receive any generated errors
 *
 * set the backend
 *
 * Set the method that libguestfs uses to connect to the backend guestfsd
 * daemon.
 * 
 * See "BACKEND" in guestfs(3).
 * 
 * Returns: true on success, false on error
 * Deprecated: In new code, use guestfs_session_set_backend() instead
 * Since: 1.9.8
 */
gboolean
guestfs_session_set_attach_method (GuestfsSession *session, const gchar *backend, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "set_attach_method");
    return FALSE;
  }

  int ret = guestfs_set_attach_method (g, backend);
  if (ret == -1) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return FALSE;
  }

  return TRUE;
}

/**
 * guestfs_session_set_autosync:
 * @session: (transfer none): A GuestfsSession object
 * @autosync: (type gboolean):
 * @err: A GError object to receive any generated errors
 *
 * set autosync mode
 *
 * If @autosync is true, this enables autosync. Libguestfs will make a best
 * effort attempt to make filesystems consistent and synchronized when the
 * handle is closed (also if the program exits without closing handles).
 * 
 * This is enabled by default (since libguestfs 1.5.24, previously it was
 * disabled by default).
 * 
 * Returns: true on success, false on error
 * Since: 0.3
 */
gboolean
guestfs_session_set_autosync (GuestfsSession *session, gboolean autosync, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "set_autosync");
    return FALSE;
  }

  int ret = guestfs_set_autosync (g, autosync);
  if (ret == -1) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return FALSE;
  }

  return TRUE;
}

/**
 * guestfs_session_set_backend:
 * @session: (transfer none): A GuestfsSession object
 * @backend: (transfer none) (type utf8):
 * @err: A GError object to receive any generated errors
 *
 * set the backend
 *
 * Set the method that libguestfs uses to connect to the backend guestfsd
 * daemon.
 * 
 * This handle property was previously called the "attach method".
 * 
 * See "BACKEND" in guestfs(3).
 * 
 * Returns: true on success, false on error
 * Since: 1.21.26
 */
gboolean
guestfs_session_set_backend (GuestfsSession *session, const gchar *backend, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "set_backend");
    return FALSE;
  }

  int ret = guestfs_set_backend (g, backend);
  if (ret == -1) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return FALSE;
  }

  return TRUE;
}

/**
 * guestfs_session_set_backend_setting:
 * @session: (transfer none): A GuestfsSession object
 * @name: (transfer none) (type utf8):
 * @val: (transfer none) (type utf8):
 * @err: A GError object to receive any generated errors
 *
 * set a single per-backend settings string
 *
 * Append "name=value" to the backend settings string list. However if a
 * string already exists matching "name" or beginning with "name=", then
 * that setting is replaced.
 * 
 * See "BACKEND" in guestfs(3), "BACKEND SETTINGS" in guestfs(3).
 * 
 * Returns: true on success, false on error
 * Since: 1.27.2
 */
gboolean
guestfs_session_set_backend_setting (GuestfsSession *session, const gchar *name, const gchar *val, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "set_backend_setting");
    return FALSE;
  }

  int ret = guestfs_set_backend_setting (g, name, val);
  if (ret == -1) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return FALSE;
  }

  return TRUE;
}

/**
 * guestfs_session_set_backend_settings:
 * @session: (transfer none): A GuestfsSession object
 * @settings: (transfer none) (array zero-terminated=1) (element-type utf8): an array of strings
 * @err: A GError object to receive any generated errors
 *
 * replace per-backend settings strings
 *
 * Set a list of zero or more settings which are passed through to the
 * current backend. Each setting is a string which is interpreted in a
 * backend-specific way, or ignored if not understood by the backend.
 * 
 * The default value is an empty list, unless the environment variable
 * @LIBGUESTFS_BACKEND_SETTINGS was set when the handle was created. This
 * environment variable contains a colon-separated list of settings.
 * 
 * This call replaces all backend settings. If you want to replace a single
 * backend setting, see guestfs_session_set_backend_setting(). If you want
 * to clear a single backend setting, see
 * guestfs_session_clear_backend_setting().
 * 
 * See "BACKEND" in guestfs(3), "BACKEND SETTINGS" in guestfs(3).
 * 
 * Returns: true on success, false on error
 * Since: 1.25.24
 */
gboolean
guestfs_session_set_backend_settings (GuestfsSession *session, gchar *const *settings, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "set_backend_settings");
    return FALSE;
  }

  int ret = guestfs_set_backend_settings (g, settings);
  if (ret == -1) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return FALSE;
  }

  return TRUE;
}

/**
 * guestfs_session_set_cachedir:
 * @session: (transfer none): A GuestfsSession object
 * @cachedir: (transfer none) (type utf8) (allow-none):
 * @err: A GError object to receive any generated errors
 *
 * set the appliance cache directory
 *
 * Set the directory used by the handle to store the appliance cache, when
 * using a supermin appliance. The appliance is cached and shared between
 * all handles which have the same effective user ID.
 * 
 * The environment variables @LIBGUESTFS_CACHEDIR and @TMPDIR control the
 * default value: If @LIBGUESTFS_CACHEDIR is set, then that is the default.
 * Else if @TMPDIR is set, then that is the default. Else /var/tmp is the
 * default.
 * 
 * Returns: true on success, false on error
 * Since: 1.19.58
 */
gboolean
guestfs_session_set_cachedir (GuestfsSession *session, const gchar *cachedir, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "set_cachedir");
    return FALSE;
  }

  int ret = guestfs_set_cachedir (g, cachedir);
  if (ret == -1) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return FALSE;
  }

  return TRUE;
}

/**
 * guestfs_session_set_direct:
 * @session: (transfer none): A GuestfsSession object
 * @direct: (type gboolean):
 * @err: A GError object to receive any generated errors
 *
 * enable or disable direct appliance mode
 *
 * If the direct appliance mode flag is enabled, then stdin and stdout are
 * passed directly through to the appliance once it is launched.
 * 
 * One consequence of this is that log messages aren't caught by the
 * library and handled by guestfs_session_set_log_message_callback(), but
 * go straight to stdout.
 * 
 * You probably don't want to use this unless you know what you are doing.
 * 
 * The default is disabled.
 * 
 * Returns: true on success, false on error
 * Since: 1.0.72
 */
gboolean
guestfs_session_set_direct (GuestfsSession *session, gboolean direct, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "set_direct");
    return FALSE;
  }

  int ret = guestfs_set_direct (g, direct);
  if (ret == -1) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return FALSE;
  }

  return TRUE;
}

/**
 * guestfs_session_set_e2attrs:
 * @session: (transfer none): A GuestfsSession object
 * @file: (transfer none) (type filename):
 * @attrs: (transfer none) (type utf8):
 * @optargs: (transfer none) (allow-none): a GuestfsSetE2attrs containing optional arguments
 * @err: A GError object to receive any generated errors
 *
 * set ext2 file attributes of a file
 *
 * This sets or clears the file attributes @attrs associated with the inode
 * file.
 * 
 * @attrs is a string of characters representing file attributes. See
 * guestfs_session_get_e2attrs() for a list of possible attributes. Not all
 * attributes can be changed.
 * 
 * If optional boolean @clear is not present or false, then the @attrs
 * listed are set in the inode.
 * 
 * If @clear is true, then the @attrs listed are cleared in the inode.
 * 
 * In both cases, other attributes not present in the @attrs string are
 * left unchanged.
 * 
 * These attributes are only present when the file is located on an
 * ext2/3/4 filesystem. Using this call on other filesystem types will
 * result in an error.
 * 
 * Returns: true on success, false on error
 * Since: 1.17.31
 */
gboolean
guestfs_session_set_e2attrs (GuestfsSession *session, const gchar *file, const gchar *attrs, GuestfsSetE2attrs *optargs, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "set_e2attrs");
    return FALSE;
  }

  struct guestfs_set_e2attrs_argv argv;
  struct guestfs_set_e2attrs_argv *argvp = NULL;

  if (optargs) {
    argv.bitmask = 0;

    GValue clear_v = {0, };
    g_value_init (&clear_v, GUESTFS_TYPE_TRISTATE);
    g_object_get_property (G_OBJECT (optargs), "clear", &clear_v);
    GuestfsTristate clear = g_value_get_enum (&clear_v);
    if (clear != GUESTFS_TRISTATE_NONE) {
      argv.bitmask |= GUESTFS_SET_E2ATTRS_CLEAR_BITMASK;
      argv.clear = clear;
    }
    argvp = &argv;
  }
  int ret = guestfs_set_e2attrs_argv (g, file, attrs, argvp);
  if (ret == -1) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return FALSE;
  }

  return TRUE;
}

/**
 * guestfs_session_set_e2generation:
 * @session: (transfer none): A GuestfsSession object
 * @file: (transfer none) (type filename):
 * @generation: (type gint64):
 * @err: A GError object to receive any generated errors
 *
 * set ext2 file generation of a file
 *
 * This sets the ext2 file generation of a file.
 * 
 * See guestfs_session_get_e2generation().
 * 
 * Returns: true on success, false on error
 * Since: 1.17.31
 */
gboolean
guestfs_session_set_e2generation (GuestfsSession *session, const gchar *file, gint64 generation, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "set_e2generation");
    return FALSE;
  }

  int ret = guestfs_set_e2generation (g, file, generation);
  if (ret == -1) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return FALSE;
  }

  return TRUE;
}

/**
 * guestfs_session_set_e2label:
 * @session: (transfer none): A GuestfsSession object
 * @device: (transfer none) (type filename):
 * @label: (transfer none) (type utf8):
 * @err: A GError object to receive any generated errors
 *
 * set the ext2/3/4 filesystem label
 *
 * This sets the ext2/3/4 filesystem label of the filesystem on @device to
 * @label. Filesystem labels are limited to 16 characters.
 * 
 * You can use either guestfs_session_tune2fs_l() or
 * guestfs_session_get_e2label() to return the existing label on a
 * filesystem.
 * 
 * Returns: true on success, false on error
 * Deprecated: In new code, use guestfs_session_set_label() instead
 * Since: 1.0.15
 */
gboolean
guestfs_session_set_e2label (GuestfsSession *session, const gchar *device, const gchar *label, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "set_e2label");
    return FALSE;
  }

  int ret = guestfs_set_e2label (g, device, label);
  if (ret == -1) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return FALSE;
  }

  return TRUE;
}

/**
 * guestfs_session_set_e2uuid:
 * @session: (transfer none): A GuestfsSession object
 * @device: (transfer none) (type filename):
 * @uuid: (transfer none) (type utf8):
 * @err: A GError object to receive any generated errors
 *
 * set the ext2/3/4 filesystem UUID
 *
 * This sets the ext2/3/4 filesystem UUID of the filesystem on @device to
 * @uuid. The format of the UUID and alternatives such as @clear, @random
 * and @time are described in the tune2fs(8) manpage.
 * 
 * You can use guestfs_session_vfs_uuid() to return the existing UUID of a
 * filesystem.
 * 
 * Returns: true on success, false on error
 * Deprecated: In new code, use guestfs_session_set_uuid() instead
 * Since: 1.0.15
 */
gboolean
guestfs_session_set_e2uuid (GuestfsSession *session, const gchar *device, const gchar *uuid, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "set_e2uuid");
    return FALSE;
  }

  int ret = guestfs_set_e2uuid (g, device, uuid);
  if (ret == -1) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return FALSE;
  }

  return TRUE;
}

/**
 * guestfs_session_set_hv:
 * @session: (transfer none): A GuestfsSession object
 * @hv: (transfer none) (type utf8):
 * @err: A GError object to receive any generated errors
 *
 * set the hypervisor binary
 *
 * Set the hypervisor binary that we will use. The hypervisor depends on
 * the backend, but is usually the location of the qemu/KVM hypervisor. For
 * the uml backend, it is the location of the @linux or @vmlinux binary.
 * 
 * The default is chosen when the library was compiled by the configure
 * script.
 * 
 * You can also override this by setting the @LIBGUESTFS_HV environment
 * variable.
 * 
 * Note that you should call this function as early as possible after
 * creating the handle. This is because some pre-launch operations depend
 * on testing qemu features (by running "qemu -help"). If the qemu binary
 * changes, we don't retest features, and so you might see inconsistent
 * results. Using the environment variable @LIBGUESTFS_HV is safest of all
 * since that picks the qemu binary at the same time as the handle is
 * created.
 * 
 * Returns: true on success, false on error
 * Since: 1.23.17
 */
gboolean
guestfs_session_set_hv (GuestfsSession *session, const gchar *hv, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "set_hv");
    return FALSE;
  }

  int ret = guestfs_set_hv (g, hv);
  if (ret == -1) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return FALSE;
  }

  return TRUE;
}

/**
 * guestfs_session_set_label:
 * @session: (transfer none): A GuestfsSession object
 * @mountable: (transfer none) (type filename):
 * @label: (transfer none) (type utf8):
 * @err: A GError object to receive any generated errors
 *
 * set filesystem label
 *
 * Set the filesystem label on @mountable to @label.
 * 
 * Only some filesystem types support labels, and libguestfs supports
 * setting labels on only a subset of these.
 * 
 * ext2, ext3, ext4
 * Labels are limited to 16 bytes.
 * 
 * NTFS
 * Labels are limited to 128 unicode characters.
 * 
 * XFS The label is limited to 12 bytes. The filesystem must not be mounted
 * when trying to set the label.
 * 
 * btrfs
 * The label is limited to 256 bytes and some characters are not
 * allowed. Setting the label on a btrfs subvolume will set the label
 * on its parent filesystem. The filesystem must not be mounted when
 * trying to set the label.
 * 
 * To read the label on a filesystem, call guestfs_session_vfs_label().
 * 
 * Returns: true on success, false on error
 * Since: 1.17.9
 */
gboolean
guestfs_session_set_label (GuestfsSession *session, const gchar *mountable, const gchar *label, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "set_label");
    return FALSE;
  }

  int ret = guestfs_set_label (g, mountable, label);
  if (ret == -1) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return FALSE;
  }

  return TRUE;
}

/**
 * guestfs_session_set_libvirt_requested_credential:
 * @session: (transfer none): A GuestfsSession object
 * @index: (type gint32):
 * @cred: (transfer none) (array length=cred_size) (element-type guint8): an array of binary data
 * @cred_size: The size of cred, in bytes
 * @err: A GError object to receive any generated errors
 *
 * pass requested credential back to libvirt
 *
 * After requesting the @index'th credential from the user, call this
 * function to pass the answer back to libvirt.
 * 
 * See "LIBVIRT AUTHENTICATION" in guestfs(3) for documentation and example
 * code.
 * 
 * Returns: true on success, false on error
 * Since: 1.19.52
 */
gboolean
guestfs_session_set_libvirt_requested_credential (GuestfsSession *session, gint32 index, const guint8 *cred, gsize cred_size, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "set_libvirt_requested_credential");
    return FALSE;
  }

  int ret = guestfs_set_libvirt_requested_credential (g, index, (const char *) cred, cred_size);
  if (ret == -1) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return FALSE;
  }

  return TRUE;
}

/**
 * guestfs_session_set_libvirt_supported_credentials:
 * @session: (transfer none): A GuestfsSession object
 * @creds: (transfer none) (array zero-terminated=1) (element-type utf8): an array of strings
 * @err: A GError object to receive any generated errors
 *
 * set libvirt credentials supported by calling program
 *
 * Call this function before setting an event handler for
 * @GUESTFS_EVENT_LIBVIRT_AUTH, to supply the list of credential types that
 * the program knows how to process.
 * 
 * The @creds list must be a non-empty list of strings. Possible strings
 * are:
 * 
 * @username
 * @authname
 * @language
 * @cnonce
 * @passphrase
 * @echoprompt
 * @noechoprompt
 * @realm
 * @external
 * 
 * See libvirt documentation for the meaning of these credential types.
 * 
 * See "LIBVIRT AUTHENTICATION" in guestfs(3) for documentation and example
 * code.
 * 
 * Returns: true on success, false on error
 * Since: 1.19.52
 */
gboolean
guestfs_session_set_libvirt_supported_credentials (GuestfsSession *session, gchar *const *creds, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "set_libvirt_supported_credentials");
    return FALSE;
  }

  int ret = guestfs_set_libvirt_supported_credentials (g, creds);
  if (ret == -1) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return FALSE;
  }

  return TRUE;
}

/**
 * guestfs_session_set_memsize:
 * @session: (transfer none): A GuestfsSession object
 * @memsize: (type gint32):
 * @err: A GError object to receive any generated errors
 *
 * set memory allocated to the hypervisor
 *
 * This sets the memory size in megabytes allocated to the hypervisor. This
 * only has any effect if called before guestfs_session_launch().
 * 
 * You can also change this by setting the environment variable
 * @LIBGUESTFS_MEMSIZE before the handle is created.
 * 
 * For more information on the architecture of libguestfs, see guestfs(3).
 * 
 * Returns: true on success, false on error
 * Since: 1.0.55
 */
gboolean
guestfs_session_set_memsize (GuestfsSession *session, gint32 memsize, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "set_memsize");
    return FALSE;
  }

  int ret = guestfs_set_memsize (g, memsize);
  if (ret == -1) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return FALSE;
  }

  return TRUE;
}

/**
 * guestfs_session_set_network:
 * @session: (transfer none): A GuestfsSession object
 * @network: (type gboolean):
 * @err: A GError object to receive any generated errors
 *
 * set enable network flag
 *
 * If @network is true, then the network is enabled in the libguestfs
 * appliance. The default is false.
 * 
 * This affects whether commands are able to access the network (see
 * "RUNNING COMMANDS" in guestfs(3)).
 * 
 * You must call this before calling guestfs_session_launch(), otherwise it
 * has no effect.
 * 
 * Returns: true on success, false on error
 * Since: 1.5.4
 */
gboolean
guestfs_session_set_network (GuestfsSession *session, gboolean network, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "set_network");
    return FALSE;
  }

  int ret = guestfs_set_network (g, network);
  if (ret == -1) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return FALSE;
  }

  return TRUE;
}

/**
 * guestfs_session_set_path:
 * @session: (transfer none): A GuestfsSession object
 * @searchpath: (transfer none) (type utf8) (allow-none):
 * @err: A GError object to receive any generated errors
 *
 * set the search path
 *
 * Set the path that libguestfs searches for kernel and initrd.img.
 * 
 * The default is "$libdir/guestfs" unless overridden by setting
 * @LIBGUESTFS_PATH environment variable.
 * 
 * Setting @path to @NULL restores the default path.
 * 
 * Returns: true on success, false on error
 * Since: 0.3
 */
gboolean
guestfs_session_set_path (GuestfsSession *session, const gchar *searchpath, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "set_path");
    return FALSE;
  }

  int ret = guestfs_set_path (g, searchpath);
  if (ret == -1) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return FALSE;
  }

  return TRUE;
}

/**
 * guestfs_session_set_pgroup:
 * @session: (transfer none): A GuestfsSession object
 * @pgroup: (type gboolean):
 * @err: A GError object to receive any generated errors
 *
 * set process group flag
 *
 * If @pgroup is true, child processes are placed into their own process
 * group.
 * 
 * The practical upshot of this is that signals like @SIGINT (from users
 * pressing "^C") won't be received by the child process.
 * 
 * The default for this flag is false, because usually you want "^C" to
 * kill the subprocess. Guestfish sets this flag to true when used
 * interactively, so that "^C" can cancel long-running commands gracefully
 * (see guestfs_session_user_cancel()).
 * 
 * Returns: true on success, false on error
 * Since: 1.11.18
 */
gboolean
guestfs_session_set_pgroup (GuestfsSession *session, gboolean pgroup, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "set_pgroup");
    return FALSE;
  }

  int ret = guestfs_set_pgroup (g, pgroup);
  if (ret == -1) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return FALSE;
  }

  return TRUE;
}

/**
 * guestfs_session_set_program:
 * @session: (transfer none): A GuestfsSession object
 * @program: (transfer none) (type utf8):
 * @err: A GError object to receive any generated errors
 *
 * set the program name
 *
 * Set the program name. This is an informative string which the main
 * program may optionally set in the handle.
 * 
 * When the handle is created, the program name in the handle is set to the
 * basename from "argv[0]". If that was not possible, it is set to the
 * empty string (but never @NULL).
 * 
 * Returns: true on success, false on error
 * Since: 1.21.29
 */
gboolean
guestfs_session_set_program (GuestfsSession *session, const gchar *program, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "set_program");
    return FALSE;
  }

  int ret = guestfs_set_program (g, program);
  if (ret == -1) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return FALSE;
  }

  return TRUE;
}

/**
 * guestfs_session_set_qemu:
 * @session: (transfer none): A GuestfsSession object
 * @hv: (transfer none) (type utf8) (allow-none):
 * @err: A GError object to receive any generated errors
 *
 * set the hypervisor binary (usually qemu)
 *
 * Set the hypervisor binary (usually qemu) that we will use.
 * 
 * The default is chosen when the library was compiled by the configure
 * script.
 * 
 * You can also override this by setting the @LIBGUESTFS_HV environment
 * variable.
 * 
 * Setting @hv to @NULL restores the default qemu binary.
 * 
 * Note that you should call this function as early as possible after
 * creating the handle. This is because some pre-launch operations depend
 * on testing qemu features (by running "qemu -help"). If the qemu binary
 * changes, we don't retest features, and so you might see inconsistent
 * results. Using the environment variable @LIBGUESTFS_HV is safest of all
 * since that picks the qemu binary at the same time as the handle is
 * created.
 * 
 * Returns: true on success, false on error
 * Deprecated: In new code, use guestfs_session_set_hv() instead
 * Since: 1.0.6
 */
gboolean
guestfs_session_set_qemu (GuestfsSession *session, const gchar *hv, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "set_qemu");
    return FALSE;
  }

  int ret = guestfs_set_qemu (g, hv);
  if (ret == -1) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return FALSE;
  }

  return TRUE;
}

/**
 * guestfs_session_set_recovery_proc:
 * @session: (transfer none): A GuestfsSession object
 * @recoveryproc: (type gboolean):
 * @err: A GError object to receive any generated errors
 *
 * enable or disable the recovery process
 *
 * If this is called with the parameter @false then
 * guestfs_session_launch() does not create a recovery process. The purpose
 * of the recovery process is to stop runaway hypervisor processes in the
 * case where the main program aborts abruptly.
 * 
 * This only has any effect if called before guestfs_session_launch(), and
 * the default is true.
 * 
 * About the only time when you would want to disable this is if the main
 * process will fork itself into the background ("daemonize" itself). In
 * this case the recovery process thinks that the main program has
 * disappeared and so kills the hypervisor, which is not very helpful.
 * 
 * Returns: true on success, false on error
 * Since: 1.0.77
 */
gboolean
guestfs_session_set_recovery_proc (GuestfsSession *session, gboolean recoveryproc, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "set_recovery_proc");
    return FALSE;
  }

  int ret = guestfs_set_recovery_proc (g, recoveryproc);
  if (ret == -1) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return FALSE;
  }

  return TRUE;
}

/**
 * guestfs_session_set_selinux:
 * @session: (transfer none): A GuestfsSession object
 * @selinux: (type gboolean):
 * @err: A GError object to receive any generated errors
 *
 * set SELinux enabled or disabled at appliance boot
 *
 * This sets the selinux flag that is passed to the appliance at boot time.
 * The default is "selinux=0" (disabled).
 * 
 * Note that if SELinux is enabled, it is always in Permissive mode
 * ("enforcing=0").
 * 
 * For more information on the architecture of libguestfs, see guestfs(3).
 * 
 * Returns: true on success, false on error
 * Since: 1.0.67
 */
gboolean
guestfs_session_set_selinux (GuestfsSession *session, gboolean selinux, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "set_selinux");
    return FALSE;
  }

  int ret = guestfs_set_selinux (g, selinux);
  if (ret == -1) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return FALSE;
  }

  return TRUE;
}

/**
 * guestfs_session_set_smp:
 * @session: (transfer none): A GuestfsSession object
 * @smp: (type gint32):
 * @err: A GError object to receive any generated errors
 *
 * set number of virtual CPUs in appliance
 *
 * Change the number of virtual CPUs assigned to the appliance. The default
 * is @1. Increasing this may improve performance, though often it has no
 * effect.
 * 
 * This function must be called before guestfs_session_launch().
 * 
 * Returns: true on success, false on error
 * Since: 1.13.15
 */
gboolean
guestfs_session_set_smp (GuestfsSession *session, gint32 smp, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "set_smp");
    return FALSE;
  }

  int ret = guestfs_set_smp (g, smp);
  if (ret == -1) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return FALSE;
  }

  return TRUE;
}

/**
 * guestfs_session_set_tmpdir:
 * @session: (transfer none): A GuestfsSession object
 * @tmpdir: (transfer none) (type utf8) (allow-none):
 * @err: A GError object to receive any generated errors
 *
 * set the temporary directory
 *
 * Set the directory used by the handle to store temporary files.
 * 
 * The environment variables @LIBGUESTFS_TMPDIR and @TMPDIR control the
 * default value: If @LIBGUESTFS_TMPDIR is set, then that is the default.
 * Else if @TMPDIR is set, then that is the default. Else /tmp is the
 * default.
 * 
 * Returns: true on success, false on error
 * Since: 1.19.58
 */
gboolean
guestfs_session_set_tmpdir (GuestfsSession *session, const gchar *tmpdir, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "set_tmpdir");
    return FALSE;
  }

  int ret = guestfs_set_tmpdir (g, tmpdir);
  if (ret == -1) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return FALSE;
  }

  return TRUE;
}

/**
 * guestfs_session_set_trace:
 * @session: (transfer none): A GuestfsSession object
 * @trace: (type gboolean):
 * @err: A GError object to receive any generated errors
 *
 * enable or disable command traces
 *
 * If the command trace flag is set to 1, then libguestfs calls, parameters
 * and return values are traced.
 * 
 * If you want to trace C API calls into libguestfs (and other libraries)
 * then possibly a better way is to use the external ltrace(1) command.
 * 
 * Command traces are disabled unless the environment variable
 * @LIBGUESTFS_TRACE is defined and set to @1.
 * 
 * Trace messages are normally sent to @stderr, unless you register a
 * callback to send them somewhere else (see
 * guestfs_session_set_event_callback()).
 * 
 * Returns: true on success, false on error
 * Since: 1.0.69
 */
gboolean
guestfs_session_set_trace (GuestfsSession *session, gboolean trace, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "set_trace");
    return FALSE;
  }

  int ret = guestfs_set_trace (g, trace);
  if (ret == -1) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return FALSE;
  }

  return TRUE;
}

/**
 * guestfs_session_set_uuid:
 * @session: (transfer none): A GuestfsSession object
 * @device: (transfer none) (type filename):
 * @uuid: (transfer none) (type utf8):
 * @err: A GError object to receive any generated errors
 *
 * set the filesystem UUID
 *
 * Set the filesystem UUID on @device to @uuid.
 * 
 * Only some filesystem types support setting UUIDs.
 * 
 * To read the UUID on a filesystem, call guestfs_session_vfs_uuid().
 * 
 * Returns: true on success, false on error
 * Since: 1.23.10
 */
gboolean
guestfs_session_set_uuid (GuestfsSession *session, const gchar *device, const gchar *uuid, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "set_uuid");
    return FALSE;
  }

  int ret = guestfs_set_uuid (g, device, uuid);
  if (ret == -1) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return FALSE;
  }

  return TRUE;
}

/**
 * guestfs_session_set_verbose:
 * @session: (transfer none): A GuestfsSession object
 * @verbose: (type gboolean):
 * @err: A GError object to receive any generated errors
 *
 * set verbose mode
 *
 * If @verbose is true, this turns on verbose messages.
 * 
 * Verbose messages are disabled unless the environment variable
 * @LIBGUESTFS_DEBUG is defined and set to @1.
 * 
 * Verbose messages are normally sent to @stderr, unless you register a
 * callback to send them somewhere else (see
 * guestfs_session_set_event_callback()).
 * 
 * Returns: true on success, false on error
 * Since: 0.3
 */
gboolean
guestfs_session_set_verbose (GuestfsSession *session, gboolean verbose, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "set_verbose");
    return FALSE;
  }

  int ret = guestfs_set_verbose (g, verbose);
  if (ret == -1) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return FALSE;
  }

  return TRUE;
}

/**
 * guestfs_session_setcon:
 * @session: (transfer none): A GuestfsSession object
 * @context: (transfer none) (type utf8):
 * @err: A GError object to receive any generated errors
 *
 * set SELinux security context
 *
 * This sets the SELinux security context of the daemon to the string
 * @context.
 * 
 * See the documentation about SELINUX in guestfs(3).
 * 
 * Returns: true on success, false on error
 * Since: 1.0.67
 */
gboolean
guestfs_session_setcon (GuestfsSession *session, const gchar *context, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "setcon");
    return FALSE;
  }

  int ret = guestfs_setcon (g, context);
  if (ret == -1) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return FALSE;
  }

  return TRUE;
}

/**
 * guestfs_session_setxattr:
 * @session: (transfer none): A GuestfsSession object
 * @xattr: (transfer none) (type utf8):
 * @val: (transfer none) (type utf8):
 * @vallen: (type gint32):
 * @path: (transfer none) (type filename):
 * @err: A GError object to receive any generated errors
 *
 * set extended attribute of a file or directory
 *
 * This call sets the extended attribute named @xattr of the file @path to
 * the value @val (of length @vallen). The value is arbitrary 8 bit data.
 * 
 * See also: guestfs_session_lsetxattr(), attr(5).
 * 
 * Returns: true on success, false on error
 * Since: 1.0.59
 */
gboolean
guestfs_session_setxattr (GuestfsSession *session, const gchar *xattr, const gchar *val, gint32 vallen, const gchar *path, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "setxattr");
    return FALSE;
  }

  int ret = guestfs_setxattr (g, xattr, val, vallen, path);
  if (ret == -1) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return FALSE;
  }

  return TRUE;
}

/**
 * guestfs_session_sfdisk:
 * @session: (transfer none): A GuestfsSession object
 * @device: (transfer none) (type filename):
 * @cyls: (type gint32):
 * @heads: (type gint32):
 * @sectors: (type gint32):
 * @lines: (transfer none) (array zero-terminated=1) (element-type utf8): an array of strings
 * @err: A GError object to receive any generated errors
 *
 * create partitions on a block device
 *
 * This is a direct interface to the sfdisk(8) program for creating
 * partitions on block devices.
 * 
 * @device should be a block device, for example /dev/sda.
 * 
 * @cyls, @heads and @sectors are the number of cylinders, heads and
 * sectors on the device, which are passed directly to sfdisk as the *-C*,
 * *-H* and *-S* parameters. If you pass @0 for any of these, then the
 * corresponding parameter is omitted. Usually for 'large' disks, you can
 * just pass @0 for these, but for small (floppy-sized) disks, sfdisk (or
 * rather, the kernel) cannot work out the right geometry and you will need
 * to tell it.
 * 
 * @lines is a list of lines that we feed to @sfdisk. For more information
 * refer to the sfdisk(8) manpage.
 * 
 * To create a single partition occupying the whole disk, you would pass
 * @lines as a single element list, when the single element being the
 * string "," (comma).
 * 
 * See also: guestfs_session_sfdisk_l(), guestfs_session_sfdisk_N(),
 * guestfs_session_part_init()
 * 
 * Returns: true on success, false on error
 * Deprecated: In new code, use guestfs_session_part_add() instead
 * Since: 0.8
 */
gboolean
guestfs_session_sfdisk (GuestfsSession *session, const gchar *device, gint32 cyls, gint32 heads, gint32 sectors, gchar *const *lines, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "sfdisk");
    return FALSE;
  }

  int ret = guestfs_sfdisk (g, device, cyls, heads, sectors, lines);
  if (ret == -1) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return FALSE;
  }

  return TRUE;
}

/**
 * guestfs_session_sfdiskM:
 * @session: (transfer none): A GuestfsSession object
 * @device: (transfer none) (type filename):
 * @lines: (transfer none) (array zero-terminated=1) (element-type utf8): an array of strings
 * @err: A GError object to receive any generated errors
 *
 * create partitions on a block device
 *
 * This is a simplified interface to the guestfs_session_sfdisk() command,
 * where partition sizes are specified in megabytes only (rounded to the
 * nearest cylinder) and you don't need to specify the cyls, heads and
 * sectors parameters which were rarely if ever used anyway.
 * 
 * See also: guestfs_session_sfdisk(), the sfdisk(8) manpage and
 * guestfs_session_part_disk()
 * 
 * Returns: true on success, false on error
 * Deprecated: In new code, use guestfs_session_part_add() instead
 * Since: 1.0.55
 */
gboolean
guestfs_session_sfdiskM (GuestfsSession *session, const gchar *device, gchar *const *lines, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "sfdiskM");
    return FALSE;
  }

  int ret = guestfs_sfdiskM (g, device, lines);
  if (ret == -1) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return FALSE;
  }

  return TRUE;
}

/**
 * guestfs_session_sfdisk_N:
 * @session: (transfer none): A GuestfsSession object
 * @device: (transfer none) (type filename):
 * @partnum: (type gint32):
 * @cyls: (type gint32):
 * @heads: (type gint32):
 * @sectors: (type gint32):
 * @line: (transfer none) (type utf8):
 * @err: A GError object to receive any generated errors
 *
 * modify a single partition on a block device
 *
 * This runs sfdisk(8) option to modify just the single partition @n (note:
 * @n counts from 1).
 * 
 * For other parameters, see guestfs_session_sfdisk(). You should usually
 * pass @0 for the cyls/heads/sectors parameters.
 * 
 * See also: guestfs_session_part_add()
 * 
 * Returns: true on success, false on error
 * Deprecated: In new code, use guestfs_session_part_add() instead
 * Since: 1.0.26
 */
gboolean
guestfs_session_sfdisk_N (GuestfsSession *session, const gchar *device, gint32 partnum, gint32 cyls, gint32 heads, gint32 sectors, const gchar *line, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "sfdisk_N");
    return FALSE;
  }

  int ret = guestfs_sfdisk_N (g, device, partnum, cyls, heads, sectors, line);
  if (ret == -1) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return FALSE;
  }

  return TRUE;
}

/**
 * guestfs_session_sfdisk_disk_geometry:
 * @session: (transfer none): A GuestfsSession object
 * @device: (transfer none) (type filename):
 * @err: A GError object to receive any generated errors
 *
 * display the disk geometry from the partition table
 *
 * This displays the disk geometry of @device read from the partition
 * table. Especially in the case where the underlying block device has been
 * resized, this can be different from the kernel's idea of the geometry
 * (see guestfs_session_sfdisk_kernel_geometry()).
 * 
 * The result is in human-readable format, and not designed to be parsed.
 * 
 * Returns: (transfer full): the returned string, or NULL on error
 * Since: 1.0.26
 */
gchar *
guestfs_session_sfdisk_disk_geometry (GuestfsSession *session, const gchar *device, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "sfdisk_disk_geometry");
    return NULL;
  }

  char *ret = guestfs_sfdisk_disk_geometry (g, device);
  if (ret == NULL) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return NULL;
  }

  return ret;
}

/**
 * guestfs_session_sfdisk_kernel_geometry:
 * @session: (transfer none): A GuestfsSession object
 * @device: (transfer none) (type filename):
 * @err: A GError object to receive any generated errors
 *
 * display the kernel geometry
 *
 * This displays the kernel's idea of the geometry of @device.
 * 
 * The result is in human-readable format, and not designed to be parsed.
 * 
 * Returns: (transfer full): the returned string, or NULL on error
 * Since: 1.0.26
 */
gchar *
guestfs_session_sfdisk_kernel_geometry (GuestfsSession *session, const gchar *device, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "sfdisk_kernel_geometry");
    return NULL;
  }

  char *ret = guestfs_sfdisk_kernel_geometry (g, device);
  if (ret == NULL) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return NULL;
  }

  return ret;
}

/**
 * guestfs_session_sfdisk_l:
 * @session: (transfer none): A GuestfsSession object
 * @device: (transfer none) (type filename):
 * @err: A GError object to receive any generated errors
 *
 * display the partition table
 *
 * This displays the partition table on @device, in the human-readable
 * output of the sfdisk(8) command. It is not intended to be parsed.
 * 
 * See also: guestfs_session_part_list()
 * 
 * Returns: (transfer full): the returned string, or NULL on error
 * Deprecated: In new code, use guestfs_session_part_list() instead
 * Since: 1.0.26
 */
gchar *
guestfs_session_sfdisk_l (GuestfsSession *session, const gchar *device, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "sfdisk_l");
    return NULL;
  }

  char *ret = guestfs_sfdisk_l (g, device);
  if (ret == NULL) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return NULL;
  }

  return ret;
}

/**
 * guestfs_session_sh:
 * @session: (transfer none): A GuestfsSession object
 * @command: (transfer none) (type utf8):
 * @err: A GError object to receive any generated errors
 *
 * run a command via the shell
 *
 * This call runs a command from the guest filesystem via the guest's
 * /bin/sh.
 * 
 * This is like guestfs_session_command(), but passes the command to:
 * 
 * <![CDATA[/bin/sh -c "command"]]>
 * 
 * Depending on the guest's shell, this usually results in wildcards being
 * expanded, shell expressions being interpolated and so on.
 * 
 * All the provisos about guestfs_session_command() apply to this call.
 * 
 * Returns: (transfer full): the returned string, or NULL on error
 * Since: 1.0.50
 */
gchar *
guestfs_session_sh (GuestfsSession *session, const gchar *command, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "sh");
    return NULL;
  }

  char *ret = guestfs_sh (g, command);
  if (ret == NULL) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return NULL;
  }

  return ret;
}

/**
 * guestfs_session_sh_lines:
 * @session: (transfer none): A GuestfsSession object
 * @command: (transfer none) (type utf8):
 * @err: A GError object to receive any generated errors
 *
 * run a command via the shell returning lines
 *
 * This is the same as guestfs_session_sh(), but splits the result into a
 * list of lines.
 * 
 * See also: guestfs_session_command_lines()
 * 
 * Returns: (transfer full) (array zero-terminated=1) (element-type utf8): an array of returned strings, or NULL on error
 * Since: 1.0.50
 */
gchar **
guestfs_session_sh_lines (GuestfsSession *session, const gchar *command, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "sh_lines");
    return NULL;
  }

  char **ret = guestfs_sh_lines (g, command);
  if (ret == NULL) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return NULL;
  }

  return ret;
}

/**
 * guestfs_session_shutdown:
 * @session: (transfer none): A GuestfsSession object
 * @err: A GError object to receive any generated errors
 *
 * shutdown the hypervisor
 *
 * This is the opposite of guestfs_session_launch(). It performs an orderly
 * shutdown of the backend process(es). If the autosync flag is set (which
 * is the default) then the disk image is synchronized.
 * 
 * If the subprocess exits with an error then this function will return an
 * error, which should *not* be ignored (it may indicate that the disk
 * image could not be written out properly).
 * 
 * It is safe to call this multiple times. Extra calls are ignored.
 * 
 * This call does *not* close or free up the handle. You still need to call
 * guestfs_session_close() afterwards.
 * 
 * guestfs_session_close() will call this if you don't do it explicitly,
 * but note that any errors are ignored in that case.
 * 
 * Returns: true on success, false on error
 * Since: 1.19.16
 */
gboolean
guestfs_session_shutdown (GuestfsSession *session, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "shutdown");
    return FALSE;
  }

  int ret = guestfs_shutdown (g);
  if (ret == -1) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return FALSE;
  }

  return TRUE;
}

/**
 * guestfs_session_sleep:
 * @session: (transfer none): A GuestfsSession object
 * @secs: (type gint32):
 * @err: A GError object to receive any generated errors
 *
 * sleep for some seconds
 *
 * Sleep for @secs seconds.
 * 
 * Returns: true on success, false on error
 * Since: 1.0.41
 */
gboolean
guestfs_session_sleep (GuestfsSession *session, gint32 secs, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "sleep");
    return FALSE;
  }

  int ret = guestfs_sleep (g, secs);
  if (ret == -1) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return FALSE;
  }

  return TRUE;
}

/**
 * guestfs_session_stat:
 * @session: (transfer none): A GuestfsSession object
 * @path: (transfer none) (type filename):
 * @err: A GError object to receive any generated errors
 *
 * get file information
 *
 * Returns file information for the given @path.
 * 
 * This is the same as the stat(2) system call.
 * 
 * Returns: (transfer full): a Stat object, or NULL on error
 * Deprecated: In new code, use guestfs_session_statns() instead
 * Since: 1.9.2
 */
GuestfsStat *
guestfs_session_stat (GuestfsSession *session, const gchar *path, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "stat");
    return NULL;
  }

  struct guestfs_stat *ret = guestfs_stat (g, path);
  if (ret == NULL) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return NULL;
  }

  GuestfsStat *s = g_slice_new0 (GuestfsStat);
  s->dev = ret->dev;
  s->ino = ret->ino;
  s->mode = ret->mode;
  s->nlink = ret->nlink;
  s->uid = ret->uid;
  s->gid = ret->gid;
  s->rdev = ret->rdev;
  s->size = ret->size;
  s->blksize = ret->blksize;
  s->blocks = ret->blocks;
  s->atime = ret->atime;
  s->mtime = ret->mtime;
  s->ctime = ret->ctime;
  guestfs_free_stat (ret);
  return s;
}

/**
 * guestfs_session_statns:
 * @session: (transfer none): A GuestfsSession object
 * @path: (transfer none) (type filename):
 * @err: A GError object to receive any generated errors
 *
 * get file information
 *
 * Returns file information for the given @path.
 * 
 * This is the same as the stat(2) system call.
 * 
 * Returns: (transfer full): a StatNS object, or NULL on error
 * Since: 1.27.53
 */
GuestfsStatNS *
guestfs_session_statns (GuestfsSession *session, const gchar *path, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "statns");
    return NULL;
  }

  struct guestfs_statns *ret = guestfs_statns (g, path);
  if (ret == NULL) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return NULL;
  }

  GuestfsStatNS *s = g_slice_new0 (GuestfsStatNS);
  s->st_dev = ret->st_dev;
  s->st_ino = ret->st_ino;
  s->st_mode = ret->st_mode;
  s->st_nlink = ret->st_nlink;
  s->st_uid = ret->st_uid;
  s->st_gid = ret->st_gid;
  s->st_rdev = ret->st_rdev;
  s->st_size = ret->st_size;
  s->st_blksize = ret->st_blksize;
  s->st_blocks = ret->st_blocks;
  s->st_atime_sec = ret->st_atime_sec;
  s->st_atime_nsec = ret->st_atime_nsec;
  s->st_mtime_sec = ret->st_mtime_sec;
  s->st_mtime_nsec = ret->st_mtime_nsec;
  s->st_ctime_sec = ret->st_ctime_sec;
  s->st_ctime_nsec = ret->st_ctime_nsec;
  s->st_spare1 = ret->st_spare1;
  s->st_spare2 = ret->st_spare2;
  s->st_spare3 = ret->st_spare3;
  s->st_spare4 = ret->st_spare4;
  s->st_spare5 = ret->st_spare5;
  s->st_spare6 = ret->st_spare6;
  guestfs_free_statns (ret);
  return s;
}

/**
 * guestfs_session_statvfs:
 * @session: (transfer none): A GuestfsSession object
 * @path: (transfer none) (type filename):
 * @err: A GError object to receive any generated errors
 *
 * get file system statistics
 *
 * Returns file system statistics for any mounted file system. @path should
 * be a file or directory in the mounted file system (typically it is the
 * mount point itself, but it doesn't need to be).
 * 
 * This is the same as the statvfs(2) system call.
 * 
 * Returns: (transfer full): a StatVFS object, or NULL on error
 * Since: 1.9.2
 */
GuestfsStatVFS *
guestfs_session_statvfs (GuestfsSession *session, const gchar *path, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "statvfs");
    return NULL;
  }

  struct guestfs_statvfs *ret = guestfs_statvfs (g, path);
  if (ret == NULL) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return NULL;
  }

  GuestfsStatVFS *s = g_slice_new0 (GuestfsStatVFS);
  s->bsize = ret->bsize;
  s->frsize = ret->frsize;
  s->blocks = ret->blocks;
  s->bfree = ret->bfree;
  s->bavail = ret->bavail;
  s->files = ret->files;
  s->ffree = ret->ffree;
  s->favail = ret->favail;
  s->fsid = ret->fsid;
  s->flag = ret->flag;
  s->namemax = ret->namemax;
  guestfs_free_statvfs (ret);
  return s;
}

/**
 * guestfs_session_strings:
 * @session: (transfer none): A GuestfsSession object
 * @path: (transfer none) (type filename):
 * @err: A GError object to receive any generated errors
 *
 * print the printable strings in a file
 *
 * This runs the strings(1) command on a file and returns the list of
 * printable strings found.
 * 
 * The @strings command has, in the past, had problems with parsing
 * untrusted files. These are mitigated in the current version of
 * libguestfs, but see "CVE-2014-8484" in guestfs(3).
 * 
 * Returns: (transfer full) (array zero-terminated=1) (element-type utf8): an array of returned strings, or NULL on error
 * Since: 1.0.22
 */
gchar **
guestfs_session_strings (GuestfsSession *session, const gchar *path, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "strings");
    return NULL;
  }

  char **ret = guestfs_strings (g, path);
  if (ret == NULL) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return NULL;
  }

  return ret;
}

/**
 * guestfs_session_strings_e:
 * @session: (transfer none): A GuestfsSession object
 * @encoding: (transfer none) (type utf8):
 * @path: (transfer none) (type filename):
 * @err: A GError object to receive any generated errors
 *
 * print the printable strings in a file
 *
 * This is like the guestfs_session_strings() command, but allows you to
 * specify the encoding of strings that are looked for in the source file
 * @path.
 * 
 * Allowed encodings are:
 * 
 * s   Single 7-bit-byte characters like ASCII and the ASCII-compatible
 * parts of ISO-8859-X (this is what guestfs_session_strings() uses).
 * 
 * S   Single 8-bit-byte characters.
 * 
 * b   16-bit big endian strings such as those encoded in UTF-16BE or
 * UCS-2BE.
 * 
 * l (lower case letter L)
 * 16-bit little endian such as UTF-16LE and UCS-2LE. This is useful
 * for examining binaries in Windows guests.
 * 
 * B   32-bit big endian such as UCS-4BE.
 * 
 * L   32-bit little endian such as UCS-4LE.
 * 
 * The returned strings are transcoded to UTF-8.
 * 
 * The @strings command has, in the past, had problems with parsing
 * untrusted files. These are mitigated in the current version of
 * libguestfs, but see "CVE-2014-8484" in guestfs(3).
 * 
 * Returns: (transfer full) (array zero-terminated=1) (element-type utf8): an array of returned strings, or NULL on error
 * Since: 1.0.22
 */
gchar **
guestfs_session_strings_e (GuestfsSession *session, const gchar *encoding, const gchar *path, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "strings_e");
    return NULL;
  }

  char **ret = guestfs_strings_e (g, encoding, path);
  if (ret == NULL) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return NULL;
  }

  return ret;
}

/**
 * guestfs_session_swapoff_device:
 * @session: (transfer none): A GuestfsSession object
 * @device: (transfer none) (type filename):
 * @err: A GError object to receive any generated errors
 *
 * disable swap on device
 *
 * This command disables the libguestfs appliance swap device or partition
 * named @device. See guestfs_session_swapon_device().
 * 
 * Returns: true on success, false on error
 * Since: 1.0.66
 */
gboolean
guestfs_session_swapoff_device (GuestfsSession *session, const gchar *device, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "swapoff_device");
    return FALSE;
  }

  int ret = guestfs_swapoff_device (g, device);
  if (ret == -1) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return FALSE;
  }

  return TRUE;
}

/**
 * guestfs_session_swapoff_file:
 * @session: (transfer none): A GuestfsSession object
 * @file: (transfer none) (type filename):
 * @err: A GError object to receive any generated errors
 *
 * disable swap on file
 *
 * This command disables the libguestfs appliance swap on file.
 * 
 * Returns: true on success, false on error
 * Since: 1.0.66
 */
gboolean
guestfs_session_swapoff_file (GuestfsSession *session, const gchar *file, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "swapoff_file");
    return FALSE;
  }

  int ret = guestfs_swapoff_file (g, file);
  if (ret == -1) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return FALSE;
  }

  return TRUE;
}

/**
 * guestfs_session_swapoff_label:
 * @session: (transfer none): A GuestfsSession object
 * @label: (transfer none) (type utf8):
 * @err: A GError object to receive any generated errors
 *
 * disable swap on labeled swap partition
 *
 * This command disables the libguestfs appliance swap on labeled swap
 * partition.
 * 
 * Returns: true on success, false on error
 * Since: 1.0.66
 */
gboolean
guestfs_session_swapoff_label (GuestfsSession *session, const gchar *label, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "swapoff_label");
    return FALSE;
  }

  int ret = guestfs_swapoff_label (g, label);
  if (ret == -1) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return FALSE;
  }

  return TRUE;
}

/**
 * guestfs_session_swapoff_uuid:
 * @session: (transfer none): A GuestfsSession object
 * @uuid: (transfer none) (type utf8):
 * @err: A GError object to receive any generated errors
 *
 * disable swap on swap partition by UUID
 *
 * This command disables the libguestfs appliance swap partition with the
 * given UUID.
 * 
 * Returns: true on success, false on error
 * Since: 1.0.66
 */
gboolean
guestfs_session_swapoff_uuid (GuestfsSession *session, const gchar *uuid, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "swapoff_uuid");
    return FALSE;
  }

  int ret = guestfs_swapoff_uuid (g, uuid);
  if (ret == -1) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return FALSE;
  }

  return TRUE;
}

/**
 * guestfs_session_swapon_device:
 * @session: (transfer none): A GuestfsSession object
 * @device: (transfer none) (type filename):
 * @err: A GError object to receive any generated errors
 *
 * enable swap on device
 *
 * This command enables the libguestfs appliance to use the swap device or
 * partition named @device. The increased memory is made available for all
 * commands, for example those run using guestfs_session_command() or
 * guestfs_session_sh().
 * 
 * Note that you should not swap to existing guest swap partitions unless
 * you know what you are doing. They may contain hibernation information,
 * or other information that the guest doesn't want you to trash. You also
 * risk leaking information about the host to the guest this way. Instead,
 * attach a new host device to the guest and swap on that.
 * 
 * Returns: true on success, false on error
 * Since: 1.0.66
 */
gboolean
guestfs_session_swapon_device (GuestfsSession *session, const gchar *device, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "swapon_device");
    return FALSE;
  }

  int ret = guestfs_swapon_device (g, device);
  if (ret == -1) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return FALSE;
  }

  return TRUE;
}

/**
 * guestfs_session_swapon_file:
 * @session: (transfer none): A GuestfsSession object
 * @file: (transfer none) (type filename):
 * @err: A GError object to receive any generated errors
 *
 * enable swap on file
 *
 * This command enables swap to a file. See guestfs_session_swapon_device()
 * for other notes.
 * 
 * Returns: true on success, false on error
 * Since: 1.0.66
 */
gboolean
guestfs_session_swapon_file (GuestfsSession *session, const gchar *file, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "swapon_file");
    return FALSE;
  }

  int ret = guestfs_swapon_file (g, file);
  if (ret == -1) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return FALSE;
  }

  return TRUE;
}

/**
 * guestfs_session_swapon_label:
 * @session: (transfer none): A GuestfsSession object
 * @label: (transfer none) (type utf8):
 * @err: A GError object to receive any generated errors
 *
 * enable swap on labeled swap partition
 *
 * This command enables swap to a labeled swap partition. See
 * guestfs_session_swapon_device() for other notes.
 * 
 * Returns: true on success, false on error
 * Since: 1.0.66
 */
gboolean
guestfs_session_swapon_label (GuestfsSession *session, const gchar *label, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "swapon_label");
    return FALSE;
  }

  int ret = guestfs_swapon_label (g, label);
  if (ret == -1) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return FALSE;
  }

  return TRUE;
}

/**
 * guestfs_session_swapon_uuid:
 * @session: (transfer none): A GuestfsSession object
 * @uuid: (transfer none) (type utf8):
 * @err: A GError object to receive any generated errors
 *
 * enable swap on swap partition by UUID
 *
 * This command enables swap to a swap partition with the given UUID. See
 * guestfs_session_swapon_device() for other notes.
 * 
 * Returns: true on success, false on error
 * Since: 1.0.66
 */
gboolean
guestfs_session_swapon_uuid (GuestfsSession *session, const gchar *uuid, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "swapon_uuid");
    return FALSE;
  }

  int ret = guestfs_swapon_uuid (g, uuid);
  if (ret == -1) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return FALSE;
  }

  return TRUE;
}

/**
 * guestfs_session_sync:
 * @session: (transfer none): A GuestfsSession object
 * @err: A GError object to receive any generated errors
 *
 * sync disks, writes are flushed through to the disk image
 *
 * This syncs the disk, so that any writes are flushed through to the
 * underlying disk image.
 * 
 * You should always call this if you have modified a disk image, before
 * closing the handle.
 * 
 * Returns: true on success, false on error
 * Since: 0.3
 */
gboolean
guestfs_session_sync (GuestfsSession *session, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "sync");
    return FALSE;
  }

  int ret = guestfs_sync (g);
  if (ret == -1) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return FALSE;
  }

  return TRUE;
}

/**
 * guestfs_session_syslinux:
 * @session: (transfer none): A GuestfsSession object
 * @device: (transfer none) (type filename):
 * @optargs: (transfer none) (allow-none): a GuestfsSyslinux containing optional arguments
 * @err: A GError object to receive any generated errors
 *
 * install the SYSLINUX bootloader
 *
 * Install the SYSLINUX bootloader on @device.
 * 
 * The device parameter must be either a whole disk formatted as a FAT
 * filesystem, or a partition formatted as a FAT filesystem. In the latter
 * case, the partition should be marked as "active"
 * (guestfs_session_part_set_bootable()) and a Master Boot Record must be
 * installed (eg. using guestfs_session_pwrite_device()) on the first
 * sector of the whole disk. The SYSLINUX package comes with some suitable
 * Master Boot Records. See the syslinux(1) man page for further
 * information.
 * 
 * The optional arguments are:
 * 
 * directory
 * Install SYSLINUX in the named subdirectory, instead of in the root
 * directory of the FAT filesystem.
 * 
 * Additional configuration can be supplied to SYSLINUX by placing a file
 * called syslinux.cfg on the FAT filesystem, either in the root directory,
 * or under directory if that optional argument is being used. For further
 * information about the contents of this file, see syslinux(1).
 * 
 * See also guestfs_session_extlinux().
 * 
 * Returns: true on success, false on error
 * Since: 1.21.27
 */
gboolean
guestfs_session_syslinux (GuestfsSession *session, const gchar *device, GuestfsSyslinux *optargs, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "syslinux");
    return FALSE;
  }

  struct guestfs_syslinux_argv argv;
  struct guestfs_syslinux_argv *argvp = NULL;

  if (optargs) {
    argv.bitmask = 0;

    GValue directory_v = {0, };
    g_value_init (&directory_v, G_TYPE_STRING);
    g_object_get_property (G_OBJECT (optargs), "directory", &directory_v);
    const gchar *directory = g_value_get_string (&directory_v);
    if (directory != NULL) {
      argv.bitmask |= GUESTFS_SYSLINUX_DIRECTORY_BITMASK;
      argv.directory = directory;
    }
    argvp = &argv;
  }
  int ret = guestfs_syslinux_argv (g, device, argvp);
  if (ret == -1) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return FALSE;
  }

  return TRUE;
}

/**
 * guestfs_session_tail:
 * @session: (transfer none): A GuestfsSession object
 * @path: (transfer none) (type filename):
 * @err: A GError object to receive any generated errors
 *
 * return last 10 lines of a file
 *
 * This command returns up to the last 10 lines of a file as a list of
 * strings.
 * 
 * Returns: (transfer full) (array zero-terminated=1) (element-type utf8): an array of returned strings, or NULL on error
 * Since: 1.0.54
 */
gchar **
guestfs_session_tail (GuestfsSession *session, const gchar *path, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "tail");
    return NULL;
  }

  char **ret = guestfs_tail (g, path);
  if (ret == NULL) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return NULL;
  }

  return ret;
}

/**
 * guestfs_session_tail_n:
 * @session: (transfer none): A GuestfsSession object
 * @nrlines: (type gint32):
 * @path: (transfer none) (type filename):
 * @err: A GError object to receive any generated errors
 *
 * return last N lines of a file
 *
 * If the parameter @nrlines is a positive number, this returns the last
 * @nrlines lines of the file @path.
 * 
 * If the parameter @nrlines is a negative number, this returns lines from
 * the file @path, starting with the @-nrlinesth line.
 * 
 * If the parameter @nrlines is zero, this returns an empty list.
 * 
 * Returns: (transfer full) (array zero-terminated=1) (element-type utf8): an array of returned strings, or NULL on error
 * Since: 1.0.54
 */
gchar **
guestfs_session_tail_n (GuestfsSession *session, gint32 nrlines, const gchar *path, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "tail_n");
    return NULL;
  }

  char **ret = guestfs_tail_n (g, nrlines, path);
  if (ret == NULL) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return NULL;
  }

  return ret;
}

/**
 * guestfs_session_tar_in:
 * @session: (transfer none): A GuestfsSession object
 * @tarfile: (transfer none) (type filename):
 * @directory: (transfer none) (type filename):
 * @optargs: (transfer none) (allow-none): a GuestfsTarIn containing optional arguments
 * @cancellable: A GCancellable object
 * @err: A GError object to receive any generated errors
 *
 * unpack tarfile to directory
 *
 * This command uploads and unpacks local file @tarfile into directory.
 * 
 * The optional @compress flag controls compression. If not given, then the
 * input should be an uncompressed tar file. Otherwise one of the following
 * strings may be given to select the compression type of the input file:
 * @compress, @gzip, @bzip2, @xz, @lzop. (Note that not all builds of
 * libguestfs will support all of these compression types).
 * 
 * Returns: true on success, false on error
 * Since: 1.0.3
 */
gboolean
guestfs_session_tar_in (GuestfsSession *session, const gchar *tarfile, const gchar *directory, GuestfsTarIn *optargs, GCancellable *cancellable, GError **err)
{
  /* Check we haven't already been cancelled */
  if (g_cancellable_set_error_if_cancelled (cancellable, err))
    return FALSE;

  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "tar_in");
    return FALSE;
  }

  struct guestfs_tar_in_opts_argv argv;
  struct guestfs_tar_in_opts_argv *argvp = NULL;

  if (optargs) {
    argv.bitmask = 0;

    GValue compress_v = {0, };
    g_value_init (&compress_v, G_TYPE_STRING);
    g_object_get_property (G_OBJECT (optargs), "compress", &compress_v);
    const gchar *compress = g_value_get_string (&compress_v);
    if (compress != NULL) {
      argv.bitmask |= GUESTFS_TAR_IN_OPTS_COMPRESS_BITMASK;
      argv.compress = compress;
    }
    argvp = &argv;
  }
  gulong id = 0;
  if (cancellable) {
    id = g_cancellable_connect (cancellable,
                               G_CALLBACK (cancelled_handler),
                               g, NULL);
  }

  int ret = guestfs_tar_in_opts_argv (g, tarfile, directory, argvp);
  g_cancellable_disconnect (cancellable, id);
  if (ret == -1) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return FALSE;
  }

  return TRUE;
}

/**
 * guestfs_session_tar_out:
 * @session: (transfer none): A GuestfsSession object
 * @directory: (transfer none) (type utf8):
 * @tarfile: (transfer none) (type filename):
 * @optargs: (transfer none) (allow-none): a GuestfsTarOut containing optional arguments
 * @cancellable: A GCancellable object
 * @err: A GError object to receive any generated errors
 *
 * pack directory into tarfile
 *
 * This command packs the contents of directory and downloads it to local
 * file @tarfile.
 * 
 * The optional @compress flag controls compression. If not given, then the
 * output will be an uncompressed tar file. Otherwise one of the following
 * strings may be given to select the compression type of the output file:
 * @compress, @gzip, @bzip2, @xz, @lzop. (Note that not all builds of
 * libguestfs will support all of these compression types).
 * 
 * The other optional arguments are:
 * 
 * @excludes
 * A list of wildcards. Files are excluded if they match any of the
 * wildcards.
 * 
 * @numericowner
 * If set to true, the output tar file will contain UID/GID numbers
 * instead of user/group names.
 * 
 * Returns: true on success, false on error
 * Since: 1.0.3
 */
gboolean
guestfs_session_tar_out (GuestfsSession *session, const gchar *directory, const gchar *tarfile, GuestfsTarOut *optargs, GCancellable *cancellable, GError **err)
{
  /* Check we haven't already been cancelled */
  if (g_cancellable_set_error_if_cancelled (cancellable, err))
    return FALSE;

  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "tar_out");
    return FALSE;
  }

  struct guestfs_tar_out_opts_argv argv;
  struct guestfs_tar_out_opts_argv *argvp = NULL;

  if (optargs) {
    argv.bitmask = 0;

    GValue compress_v = {0, };
    g_value_init (&compress_v, G_TYPE_STRING);
    g_object_get_property (G_OBJECT (optargs), "compress", &compress_v);
    const gchar *compress = g_value_get_string (&compress_v);
    if (compress != NULL) {
      argv.bitmask |= GUESTFS_TAR_OUT_OPTS_COMPRESS_BITMASK;
      argv.compress = compress;
    }
    GValue numericowner_v = {0, };
    g_value_init (&numericowner_v, GUESTFS_TYPE_TRISTATE);
    g_object_get_property (G_OBJECT (optargs), "numericowner", &numericowner_v);
    GuestfsTristate numericowner = g_value_get_enum (&numericowner_v);
    if (numericowner != GUESTFS_TRISTATE_NONE) {
      argv.bitmask |= GUESTFS_TAR_OUT_OPTS_NUMERICOWNER_BITMASK;
      argv.numericowner = numericowner;
    }
    argvp = &argv;
  }
  gulong id = 0;
  if (cancellable) {
    id = g_cancellable_connect (cancellable,
                               G_CALLBACK (cancelled_handler),
                               g, NULL);
  }

  int ret = guestfs_tar_out_opts_argv (g, directory, tarfile, argvp);
  g_cancellable_disconnect (cancellable, id);
  if (ret == -1) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return FALSE;
  }

  return TRUE;
}

/**
 * guestfs_session_tgz_in:
 * @session: (transfer none): A GuestfsSession object
 * @tarball: (transfer none) (type filename):
 * @directory: (transfer none) (type filename):
 * @cancellable: A GCancellable object
 * @err: A GError object to receive any generated errors
 *
 * unpack compressed tarball to directory
 *
 * This command uploads and unpacks local file @tarball (a *gzip
 * compressed* tar file) into directory.
 * 
 * Returns: true on success, false on error
 * Deprecated: In new code, use guestfs_session_tar_in() instead
 * Since: 1.0.3
 */
gboolean
guestfs_session_tgz_in (GuestfsSession *session, const gchar *tarball, const gchar *directory, GCancellable *cancellable, GError **err)
{
  /* Check we haven't already been cancelled */
  if (g_cancellable_set_error_if_cancelled (cancellable, err))
    return FALSE;

  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "tgz_in");
    return FALSE;
  }

  gulong id = 0;
  if (cancellable) {
    id = g_cancellable_connect (cancellable,
                               G_CALLBACK (cancelled_handler),
                               g, NULL);
  }

  int ret = guestfs_tgz_in (g, tarball, directory);
  g_cancellable_disconnect (cancellable, id);
  if (ret == -1) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return FALSE;
  }

  return TRUE;
}

/**
 * guestfs_session_tgz_out:
 * @session: (transfer none): A GuestfsSession object
 * @directory: (transfer none) (type filename):
 * @tarball: (transfer none) (type filename):
 * @cancellable: A GCancellable object
 * @err: A GError object to receive any generated errors
 *
 * pack directory into compressed tarball
 *
 * This command packs the contents of directory and downloads it to local
 * file @tarball.
 * 
 * Returns: true on success, false on error
 * Deprecated: In new code, use guestfs_session_tar_out() instead
 * Since: 1.0.3
 */
gboolean
guestfs_session_tgz_out (GuestfsSession *session, const gchar *directory, const gchar *tarball, GCancellable *cancellable, GError **err)
{
  /* Check we haven't already been cancelled */
  if (g_cancellable_set_error_if_cancelled (cancellable, err))
    return FALSE;

  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "tgz_out");
    return FALSE;
  }

  gulong id = 0;
  if (cancellable) {
    id = g_cancellable_connect (cancellable,
                               G_CALLBACK (cancelled_handler),
                               g, NULL);
  }

  int ret = guestfs_tgz_out (g, directory, tarball);
  g_cancellable_disconnect (cancellable, id);
  if (ret == -1) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return FALSE;
  }

  return TRUE;
}

/**
 * guestfs_session_touch:
 * @session: (transfer none): A GuestfsSession object
 * @path: (transfer none) (type filename):
 * @err: A GError object to receive any generated errors
 *
 * update file timestamps or create a new file
 *
 * Touch acts like the touch(1) command. It can be used to update the
 * timestamps on a file, or, if the file does not exist, to create a new
 * zero-length file.
 * 
 * This command only works on regular files, and will fail on other file
 * types such as directories, symbolic links, block special etc.
 * 
 * Returns: true on success, false on error
 * Since: 0.3
 */
gboolean
guestfs_session_touch (GuestfsSession *session, const gchar *path, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "touch");
    return FALSE;
  }

  int ret = guestfs_touch (g, path);
  if (ret == -1) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return FALSE;
  }

  return TRUE;
}

/**
 * guestfs_session_truncate:
 * @session: (transfer none): A GuestfsSession object
 * @path: (transfer none) (type filename):
 * @err: A GError object to receive any generated errors
 *
 * truncate a file to zero size
 *
 * This command truncates @path to a zero-length file. The file must exist
 * already.
 * 
 * Returns: true on success, false on error
 * Since: 1.0.77
 */
gboolean
guestfs_session_truncate (GuestfsSession *session, const gchar *path, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "truncate");
    return FALSE;
  }

  int ret = guestfs_truncate (g, path);
  if (ret == -1) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return FALSE;
  }

  return TRUE;
}

/**
 * guestfs_session_truncate_size:
 * @session: (transfer none): A GuestfsSession object
 * @path: (transfer none) (type filename):
 * @size: (type gint64):
 * @err: A GError object to receive any generated errors
 *
 * truncate a file to a particular size
 *
 * This command truncates @path to size @size bytes. The file must exist
 * already.
 * 
 * If the current file size is less than @size then the file is extended to
 * the required size with zero bytes. This creates a sparse file (ie. disk
 * blocks are not allocated for the file until you write to it). To create
 * a non-sparse file of zeroes, use guestfs_session_fallocate64() instead.
 * 
 * Returns: true on success, false on error
 * Since: 1.0.77
 */
gboolean
guestfs_session_truncate_size (GuestfsSession *session, const gchar *path, gint64 size, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "truncate_size");
    return FALSE;
  }

  int ret = guestfs_truncate_size (g, path, size);
  if (ret == -1) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return FALSE;
  }

  return TRUE;
}

/**
 * guestfs_session_tune2fs:
 * @session: (transfer none): A GuestfsSession object
 * @device: (transfer none) (type filename):
 * @optargs: (transfer none) (allow-none): a GuestfsTune2FS containing optional arguments
 * @err: A GError object to receive any generated errors
 *
 * adjust ext2/ext3/ext4 filesystem parameters
 *
 * This call allows you to adjust various filesystem parameters of an
 * ext2/ext3/ext4 filesystem called @device.
 * 
 * The optional parameters are:
 * 
 * @force
 * Force tune2fs to complete the operation even in the face of errors.
 * This is the same as the tune2fs @-f option.
 * 
 * @maxmountcount
 * Set the number of mounts after which the filesystem is checked by
 * e2fsck(8). If this is @0 then the number of mounts is disregarded.
 * This is the same as the tune2fs @-c option.
 * 
 * @mountcount
 * Set the number of times the filesystem has been mounted. This is the
 * same as the tune2fs @-C option.
 * 
 * @errorbehavior
 * Change the behavior of the kernel code when errors are detected.
 * Possible values currently are: @continue, @remount-ro, @panic. In
 * practice these options don't really make any difference,
 * particularly for write errors.
 * 
 * This is the same as the tune2fs @-e option.
 * 
 * @group
 * Set the group which can use reserved filesystem blocks. This is the
 * same as the tune2fs @-g option except that it can only be specified
 * as a number.
 * 
 * @intervalbetweenchecks
 * Adjust the maximal time between two filesystem checks (in seconds).
 * If the option is passed as @0 then time-dependent checking is
 * disabled.
 * 
 * This is the same as the tune2fs @-i option.
 * 
 * @reservedblockspercentage
 * Set the percentage of the filesystem which may only be allocated by
 * privileged processes. This is the same as the tune2fs @-m option.
 * 
 * @lastmounteddirectory
 * Set the last mounted directory. This is the same as the tune2fs @-M
 * option.
 * 
 * @reservedblockscount Set the number of reserved filesystem blocks. This
 * is the same as the tune2fs @-r option.
 * @user
 * Set the user who can use the reserved filesystem blocks. This is the
 * same as the tune2fs @-u option except that it can only be specified
 * as a number.
 * 
 * To get the current values of filesystem parameters, see
 * guestfs_session_tune2fs_l(). For precise details of how tune2fs works,
 * see the tune2fs(8) man page.
 * 
 * Returns: true on success, false on error
 * Since: 1.15.4
 */
gboolean
guestfs_session_tune2fs (GuestfsSession *session, const gchar *device, GuestfsTune2FS *optargs, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "tune2fs");
    return FALSE;
  }

  struct guestfs_tune2fs_argv argv;
  struct guestfs_tune2fs_argv *argvp = NULL;

  if (optargs) {
    argv.bitmask = 0;

    GValue force_v = {0, };
    g_value_init (&force_v, GUESTFS_TYPE_TRISTATE);
    g_object_get_property (G_OBJECT (optargs), "force", &force_v);
    GuestfsTristate force = g_value_get_enum (&force_v);
    if (force != GUESTFS_TRISTATE_NONE) {
      argv.bitmask |= GUESTFS_TUNE2FS_FORCE_BITMASK;
      argv.force = force;
    }
    GValue maxmountcount_v = {0, };
    g_value_init (&maxmountcount_v, G_TYPE_INT);
    g_object_get_property (G_OBJECT (optargs), "maxmountcount", &maxmountcount_v);
    gint32 maxmountcount = g_value_get_int (&maxmountcount_v);
    if (maxmountcount != -1) {
      argv.bitmask |= GUESTFS_TUNE2FS_MAXMOUNTCOUNT_BITMASK;
      argv.maxmountcount = maxmountcount;
    }
    GValue mountcount_v = {0, };
    g_value_init (&mountcount_v, G_TYPE_INT);
    g_object_get_property (G_OBJECT (optargs), "mountcount", &mountcount_v);
    gint32 mountcount = g_value_get_int (&mountcount_v);
    if (mountcount != -1) {
      argv.bitmask |= GUESTFS_TUNE2FS_MOUNTCOUNT_BITMASK;
      argv.mountcount = mountcount;
    }
    GValue errorbehavior_v = {0, };
    g_value_init (&errorbehavior_v, G_TYPE_STRING);
    g_object_get_property (G_OBJECT (optargs), "errorbehavior", &errorbehavior_v);
    const gchar *errorbehavior = g_value_get_string (&errorbehavior_v);
    if (errorbehavior != NULL) {
      argv.bitmask |= GUESTFS_TUNE2FS_ERRORBEHAVIOR_BITMASK;
      argv.errorbehavior = errorbehavior;
    }
    GValue group_v = {0, };
    g_value_init (&group_v, G_TYPE_INT64);
    g_object_get_property (G_OBJECT (optargs), "group", &group_v);
    gint64 group = g_value_get_int64 (&group_v);
    if (group != -1) {
      argv.bitmask |= GUESTFS_TUNE2FS_GROUP_BITMASK;
      argv.group = group;
    }
    GValue intervalbetweenchecks_v = {0, };
    g_value_init (&intervalbetweenchecks_v, G_TYPE_INT);
    g_object_get_property (G_OBJECT (optargs), "intervalbetweenchecks", &intervalbetweenchecks_v);
    gint32 intervalbetweenchecks = g_value_get_int (&intervalbetweenchecks_v);
    if (intervalbetweenchecks != -1) {
      argv.bitmask |= GUESTFS_TUNE2FS_INTERVALBETWEENCHECKS_BITMASK;
      argv.intervalbetweenchecks = intervalbetweenchecks;
    }
    GValue reservedblockspercentage_v = {0, };
    g_value_init (&reservedblockspercentage_v, G_TYPE_INT);
    g_object_get_property (G_OBJECT (optargs), "reservedblockspercentage", &reservedblockspercentage_v);
    gint32 reservedblockspercentage = g_value_get_int (&reservedblockspercentage_v);
    if (reservedblockspercentage != -1) {
      argv.bitmask |= GUESTFS_TUNE2FS_RESERVEDBLOCKSPERCENTAGE_BITMASK;
      argv.reservedblockspercentage = reservedblockspercentage;
    }
    GValue lastmounteddirectory_v = {0, };
    g_value_init (&lastmounteddirectory_v, G_TYPE_STRING);
    g_object_get_property (G_OBJECT (optargs), "lastmounteddirectory", &lastmounteddirectory_v);
    const gchar *lastmounteddirectory = g_value_get_string (&lastmounteddirectory_v);
    if (lastmounteddirectory != NULL) {
      argv.bitmask |= GUESTFS_TUNE2FS_LASTMOUNTEDDIRECTORY_BITMASK;
      argv.lastmounteddirectory = lastmounteddirectory;
    }
    GValue reservedblockscount_v = {0, };
    g_value_init (&reservedblockscount_v, G_TYPE_INT64);
    g_object_get_property (G_OBJECT (optargs), "reservedblockscount", &reservedblockscount_v);
    gint64 reservedblockscount = g_value_get_int64 (&reservedblockscount_v);
    if (reservedblockscount != -1) {
      argv.bitmask |= GUESTFS_TUNE2FS_RESERVEDBLOCKSCOUNT_BITMASK;
      argv.reservedblockscount = reservedblockscount;
    }
    GValue user_v = {0, };
    g_value_init (&user_v, G_TYPE_INT64);
    g_object_get_property (G_OBJECT (optargs), "user", &user_v);
    gint64 user = g_value_get_int64 (&user_v);
    if (user != -1) {
      argv.bitmask |= GUESTFS_TUNE2FS_USER_BITMASK;
      argv.user = user;
    }
    argvp = &argv;
  }
  int ret = guestfs_tune2fs_argv (g, device, argvp);
  if (ret == -1) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return FALSE;
  }

  return TRUE;
}

/**
 * guestfs_session_tune2fs_l:
 * @session: (transfer none): A GuestfsSession object
 * @device: (transfer none) (type filename):
 * @err: A GError object to receive any generated errors
 *
 * get ext2/ext3/ext4 superblock details
 *
 * This returns the contents of the ext2, ext3 or ext4 filesystem
 * superblock on @device.
 * 
 * It is the same as running "tune2fs -l device". See tune2fs(8) manpage
 * for more details. The list of fields returned isn't clearly defined, and
 * depends on both the version of @tune2fs that libguestfs was built
 * against, and the filesystem itself.
 * 
 * Returns: (transfer full) (element-type utf8 utf8): a GHashTable of results, or NULL on error
 * Since: 1.9.2
 */
GHashTable *
guestfs_session_tune2fs_l (GuestfsSession *session, const gchar *device, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "tune2fs_l");
    return NULL;
  }

  char **ret = guestfs_tune2fs_l (g, device);
  if (ret == NULL) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return NULL;
  }

  GHashTable *h = g_hash_table_new_full (g_str_hash, g_str_equal, g_free, g_free);
  char **i = ret;
  while (*i) {
    char *key = *i; i++;
    char *value = *i; i++;
    g_hash_table_insert (h, key, value);
  };
  g_free (ret);
  return h;
}

/**
 * guestfs_session_txz_in:
 * @session: (transfer none): A GuestfsSession object
 * @tarball: (transfer none) (type filename):
 * @directory: (transfer none) (type filename):
 * @cancellable: A GCancellable object
 * @err: A GError object to receive any generated errors
 *
 * unpack compressed tarball to directory
 *
 * This command uploads and unpacks local file @tarball (an *xz compressed*
 * tar file) into directory.
 * 
 * Returns: true on success, false on error
 * Deprecated: In new code, use guestfs_session_tar_in() instead
 * Since: 1.3.2
 */
gboolean
guestfs_session_txz_in (GuestfsSession *session, const gchar *tarball, const gchar *directory, GCancellable *cancellable, GError **err)
{
  /* Check we haven't already been cancelled */
  if (g_cancellable_set_error_if_cancelled (cancellable, err))
    return FALSE;

  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "txz_in");
    return FALSE;
  }

  gulong id = 0;
  if (cancellable) {
    id = g_cancellable_connect (cancellable,
                               G_CALLBACK (cancelled_handler),
                               g, NULL);
  }

  int ret = guestfs_txz_in (g, tarball, directory);
  g_cancellable_disconnect (cancellable, id);
  if (ret == -1) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return FALSE;
  }

  return TRUE;
}

/**
 * guestfs_session_txz_out:
 * @session: (transfer none): A GuestfsSession object
 * @directory: (transfer none) (type filename):
 * @tarball: (transfer none) (type filename):
 * @cancellable: A GCancellable object
 * @err: A GError object to receive any generated errors
 *
 * pack directory into compressed tarball
 *
 * This command packs the contents of directory and downloads it to local
 * file @tarball (as an xz compressed tar archive).
 * 
 * Returns: true on success, false on error
 * Deprecated: In new code, use guestfs_session_tar_out() instead
 * Since: 1.3.2
 */
gboolean
guestfs_session_txz_out (GuestfsSession *session, const gchar *directory, const gchar *tarball, GCancellable *cancellable, GError **err)
{
  /* Check we haven't already been cancelled */
  if (g_cancellable_set_error_if_cancelled (cancellable, err))
    return FALSE;

  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "txz_out");
    return FALSE;
  }

  gulong id = 0;
  if (cancellable) {
    id = g_cancellable_connect (cancellable,
                               G_CALLBACK (cancelled_handler),
                               g, NULL);
  }

  int ret = guestfs_txz_out (g, directory, tarball);
  g_cancellable_disconnect (cancellable, id);
  if (ret == -1) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return FALSE;
  }

  return TRUE;
}

/**
 * guestfs_session_umask:
 * @session: (transfer none): A GuestfsSession object
 * @mask: (type gint32):
 * @err: A GError object to receive any generated errors
 *
 * set file mode creation mask (umask)
 *
 * This function sets the mask used for creating new files and device nodes
 * to "mask & 0777".
 * 
 * Typical umask values would be @022 which creates new files with
 * permissions like "-rw-r--r--" or "-rwxr-xr-x", and @002 which creates
 * new files with permissions like "-rw-rw-r--" or "-rwxrwxr-x".
 * 
 * The default umask is @022. This is important because it means that
 * directories and device nodes will be created with @0644 or @0755 mode
 * even if you specify @0777.
 * 
 * See also guestfs_session_get_umask(), umask(2), guestfs_session_mknod(),
 * guestfs_session_mkdir().
 * 
 * This call returns the previous umask.
 * 
 * Returns: the returned value, or -1 on error
 * Since: 1.0.55
 */
gint32
guestfs_session_umask (GuestfsSession *session, gint32 mask, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "umask");
    return -1;
  }

  int ret = guestfs_umask (g, mask);
  if (ret == -1) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return -1;
  }

  return ret;
}

/**
 * guestfs_session_umount:
 * @session: (transfer none): A GuestfsSession object
 * @pathordevice: (transfer none) (type filename):
 * @optargs: (transfer none) (allow-none): a GuestfsUmount containing optional arguments
 * @err: A GError object to receive any generated errors
 *
 * unmount a filesystem
 *
 * This unmounts the given filesystem. The filesystem may be specified
 * either by its mountpoint (path) or the device which contains the
 * filesystem.
 * 
 * Returns: true on success, false on error
 * Since: 0.8
 */
gboolean
guestfs_session_umount (GuestfsSession *session, const gchar *pathordevice, GuestfsUmount *optargs, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "umount");
    return FALSE;
  }

  struct guestfs_umount_opts_argv argv;
  struct guestfs_umount_opts_argv *argvp = NULL;

  if (optargs) {
    argv.bitmask = 0;

    GValue force_v = {0, };
    g_value_init (&force_v, GUESTFS_TYPE_TRISTATE);
    g_object_get_property (G_OBJECT (optargs), "force", &force_v);
    GuestfsTristate force = g_value_get_enum (&force_v);
    if (force != GUESTFS_TRISTATE_NONE) {
      argv.bitmask |= GUESTFS_UMOUNT_OPTS_FORCE_BITMASK;
      argv.force = force;
    }
    GValue lazyunmount_v = {0, };
    g_value_init (&lazyunmount_v, GUESTFS_TYPE_TRISTATE);
    g_object_get_property (G_OBJECT (optargs), "lazyunmount", &lazyunmount_v);
    GuestfsTristate lazyunmount = g_value_get_enum (&lazyunmount_v);
    if (lazyunmount != GUESTFS_TRISTATE_NONE) {
      argv.bitmask |= GUESTFS_UMOUNT_OPTS_LAZYUNMOUNT_BITMASK;
      argv.lazyunmount = lazyunmount;
    }
    argvp = &argv;
  }
  int ret = guestfs_umount_opts_argv (g, pathordevice, argvp);
  if (ret == -1) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return FALSE;
  }

  return TRUE;
}

/**
 * guestfs_session_umount_all:
 * @session: (transfer none): A GuestfsSession object
 * @err: A GError object to receive any generated errors
 *
 * unmount all filesystems
 *
 * This unmounts all mounted filesystems.
 * 
 * Some internal mounts are not unmounted by this call.
 * 
 * Returns: true on success, false on error
 * Since: 0.8
 */
gboolean
guestfs_session_umount_all (GuestfsSession *session, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "umount_all");
    return FALSE;
  }

  int ret = guestfs_umount_all (g);
  if (ret == -1) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return FALSE;
  }

  return TRUE;
}

/**
 * guestfs_session_umount_local:
 * @session: (transfer none): A GuestfsSession object
 * @optargs: (transfer none) (allow-none): a GuestfsUmountLocal containing optional arguments
 * @err: A GError object to receive any generated errors
 *
 * unmount a locally mounted filesystem
 *
 * If libguestfs is exporting the filesystem on a local mountpoint, then
 * this unmounts it.
 * 
 * See "MOUNT LOCAL" in guestfs(3) for full documentation.
 * 
 * Returns: true on success, false on error
 * Since: 1.17.22
 */
gboolean
guestfs_session_umount_local (GuestfsSession *session, GuestfsUmountLocal *optargs, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "umount_local");
    return FALSE;
  }

  struct guestfs_umount_local_argv argv;
  struct guestfs_umount_local_argv *argvp = NULL;

  if (optargs) {
    argv.bitmask = 0;

    GValue retry_v = {0, };
    g_value_init (&retry_v, GUESTFS_TYPE_TRISTATE);
    g_object_get_property (G_OBJECT (optargs), "retry", &retry_v);
    GuestfsTristate retry = g_value_get_enum (&retry_v);
    if (retry != GUESTFS_TRISTATE_NONE) {
      argv.bitmask |= GUESTFS_UMOUNT_LOCAL_RETRY_BITMASK;
      argv.retry = retry;
    }
    argvp = &argv;
  }
  int ret = guestfs_umount_local_argv (g, argvp);
  if (ret == -1) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return FALSE;
  }

  return TRUE;
}

/**
 * guestfs_session_upload:
 * @session: (transfer none): A GuestfsSession object
 * @filename: (transfer none) (type filename):
 * @remotefilename: (transfer none) (type filename):
 * @cancellable: A GCancellable object
 * @err: A GError object to receive any generated errors
 *
 * upload a file from the local machine
 *
 * Upload local file filename to remotefilename on the filesystem.
 * 
 * filename can also be a named pipe.
 * 
 * See also guestfs_session_download().
 * 
 * Returns: true on success, false on error
 * Since: 1.0.2
 */
gboolean
guestfs_session_upload (GuestfsSession *session, const gchar *filename, const gchar *remotefilename, GCancellable *cancellable, GError **err)
{
  /* Check we haven't already been cancelled */
  if (g_cancellable_set_error_if_cancelled (cancellable, err))
    return FALSE;

  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "upload");
    return FALSE;
  }

  gulong id = 0;
  if (cancellable) {
    id = g_cancellable_connect (cancellable,
                               G_CALLBACK (cancelled_handler),
                               g, NULL);
  }

  int ret = guestfs_upload (g, filename, remotefilename);
  g_cancellable_disconnect (cancellable, id);
  if (ret == -1) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return FALSE;
  }

  return TRUE;
}

/**
 * guestfs_session_upload_offset:
 * @session: (transfer none): A GuestfsSession object
 * @filename: (transfer none) (type filename):
 * @remotefilename: (transfer none) (type filename):
 * @offset: (type gint64):
 * @cancellable: A GCancellable object
 * @err: A GError object to receive any generated errors
 *
 * upload a file from the local machine with offset
 *
 * Upload local file filename to remotefilename on the filesystem.
 * 
 * remotefilename is overwritten starting at the byte @offset specified.
 * The intention is to overwrite parts of existing files or devices,
 * although if a non-existent file is specified then it is created with a
 * "hole" before @offset. The size of the data written is implicit in the
 * size of the source filename.
 * 
 * Note that there is no limit on the amount of data that can be uploaded
 * with this call, unlike with guestfs_session_pwrite(), and this call
 * always writes the full amount unless an error occurs.
 * 
 * See also guestfs_session_upload(), guestfs_session_pwrite().
 * 
 * Returns: true on success, false on error
 * Since: 1.5.17
 */
gboolean
guestfs_session_upload_offset (GuestfsSession *session, const gchar *filename, const gchar *remotefilename, gint64 offset, GCancellable *cancellable, GError **err)
{
  /* Check we haven't already been cancelled */
  if (g_cancellable_set_error_if_cancelled (cancellable, err))
    return FALSE;

  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "upload_offset");
    return FALSE;
  }

  gulong id = 0;
  if (cancellable) {
    id = g_cancellable_connect (cancellable,
                               G_CALLBACK (cancelled_handler),
                               g, NULL);
  }

  int ret = guestfs_upload_offset (g, filename, remotefilename, offset);
  g_cancellable_disconnect (cancellable, id);
  if (ret == -1) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return FALSE;
  }

  return TRUE;
}

/**
 * guestfs_session_user_cancel:
 * @session: (transfer none): A GuestfsSession object
 * @err: A GError object to receive any generated errors
 *
 * cancel the current upload or download operation
 *
 * This function cancels the current upload or download operation.
 * 
 * Unlike most other libguestfs calls, this function is signal safe and
 * thread safe. You can call it from a signal handler or from another
 * thread, without needing to do any locking.
 * 
 * The transfer that was in progress (if there is one) will stop shortly
 * afterwards, and will return an error. The errno (see
 * "guestfs_last_errno") is set to @EINTR, so you can test for this to find
 * out if the operation was cancelled or failed because of another error.
 * 
 * No cleanup is performed: for example, if a file was being uploaded then
 * after cancellation there may be a partially uploaded file. It is the
 * caller's responsibility to clean up if necessary.
 * 
 * There are two common places that you might call
 * guestfs_session_user_cancel():
 * 
 * In an interactive text-based program, you might call it from a @SIGINT
 * signal handler so that pressing "^C" cancels the current operation. (You
 * also need to call "guestfs_set_pgroup" so that child processes don't
 * receive the "^C" signal).
 * 
 * In a graphical program, when the main thread is displaying a progress
 * bar with a cancel button, wire up the cancel button to call this
 * function.
 * 
 * Returns: true on success, false on error
 * Since: 1.11.18
 */
gboolean
guestfs_session_user_cancel (GuestfsSession *session, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "user_cancel");
    return FALSE;
  }

  int ret = guestfs_user_cancel (g);
  if (ret == -1) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return FALSE;
  }

  return TRUE;
}

/**
 * guestfs_session_utimens:
 * @session: (transfer none): A GuestfsSession object
 * @path: (transfer none) (type filename):
 * @atsecs: (type gint64):
 * @atnsecs: (type gint64):
 * @mtsecs: (type gint64):
 * @mtnsecs: (type gint64):
 * @err: A GError object to receive any generated errors
 *
 * set timestamp of a file with nanosecond precision
 *
 * This command sets the timestamps of a file with nanosecond precision.
 * 
 * "atsecs, atnsecs" are the last access time (atime) in secs and
 * nanoseconds from the epoch.
 * 
 * "mtsecs, mtnsecs" are the last modification time (mtime) in secs and
 * nanoseconds from the epoch.
 * 
 * If the *nsecs field contains the special value @-1 then the
 * corresponding timestamp is set to the current time. (The *secs field is
 * ignored in this case).
 * 
 * If the *nsecs field contains the special value @-2 then the
 * corresponding timestamp is left unchanged. (The *secs field is ignored
 * in this case).
 * 
 * Returns: true on success, false on error
 * Since: 1.0.77
 */
gboolean
guestfs_session_utimens (GuestfsSession *session, const gchar *path, gint64 atsecs, gint64 atnsecs, gint64 mtsecs, gint64 mtnsecs, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "utimens");
    return FALSE;
  }

  int ret = guestfs_utimens (g, path, atsecs, atnsecs, mtsecs, mtnsecs);
  if (ret == -1) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return FALSE;
  }

  return TRUE;
}

/**
 * guestfs_session_utsname:
 * @session: (transfer none): A GuestfsSession object
 * @err: A GError object to receive any generated errors
 *
 * appliance kernel version
 *
 * This returns the kernel version of the appliance, where this is
 * available. This information is only useful for debugging. Nothing in the
 * returned structure is defined by the API.
 * 
 * Returns: (transfer full): a UTSName object, or NULL on error
 * Since: 1.19.27
 */
GuestfsUTSName *
guestfs_session_utsname (GuestfsSession *session, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "utsname");
    return NULL;
  }

  struct guestfs_utsname *ret = guestfs_utsname (g);
  if (ret == NULL) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return NULL;
  }

  GuestfsUTSName *s = g_slice_new0 (GuestfsUTSName);
  if (ret->uts_sysname) s->uts_sysname = g_strdup (ret->uts_sysname);
  if (ret->uts_release) s->uts_release = g_strdup (ret->uts_release);
  if (ret->uts_version) s->uts_version = g_strdup (ret->uts_version);
  if (ret->uts_machine) s->uts_machine = g_strdup (ret->uts_machine);
  guestfs_free_utsname (ret);
  return s;
}

/**
 * guestfs_session_version:
 * @session: (transfer none): A GuestfsSession object
 * @err: A GError object to receive any generated errors
 *
 * get the library version number
 *
 * Return the libguestfs version number that the program is linked against.
 * 
 * Note that because of dynamic linking this is not necessarily the version
 * of libguestfs that you compiled against. You can compile the program,
 * and then at runtime dynamically link against a completely different
 * libguestfs.so library.
 * 
 * This call was added in version 1.0.58. In previous versions of
 * libguestfs there was no way to get the version number. From C code you
 * can use dynamic linker functions to find out if this symbol exists (if
 * it doesn't, then it's an earlier version).
 * 
 * The call returns a structure with four elements. The first three
 * (@major, @minor and @release) are numbers and correspond to the usual
 * version triplet. The fourth element (@extra) is a string and is normally
 * empty, but may be used for distro-specific information.
 * 
 * To construct the original version string: "$major.$minor.$release$extra"
 * 
 * See also: "LIBGUESTFS VERSION NUMBERS" in guestfs(3).
 * 
 * *Note:* Don't use this call to test for availability of features. In
 * enterprise distributions we backport features from later versions into
 * earlier versions, making this an unreliable way to test for features.
 * Use guestfs_session_available() or guestfs_session_feature_available()
 * instead.
 * 
 * Returns: (transfer full): a Version object, or NULL on error
 * Since: 1.0.58
 */
GuestfsVersion *
guestfs_session_version (GuestfsSession *session, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "version");
    return NULL;
  }

  struct guestfs_version *ret = guestfs_version (g);
  if (ret == NULL) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return NULL;
  }

  GuestfsVersion *s = g_slice_new0 (GuestfsVersion);
  s->major = ret->major;
  s->minor = ret->minor;
  s->release = ret->release;
  if (ret->extra) s->extra = g_strdup (ret->extra);
  guestfs_free_version (ret);
  return s;
}

/**
 * guestfs_session_vfs_label:
 * @session: (transfer none): A GuestfsSession object
 * @mountable: (transfer none) (type filename):
 * @err: A GError object to receive any generated errors
 *
 * get the filesystem label
 *
 * This returns the label of the filesystem on @mountable.
 * 
 * If the filesystem is unlabeled, this returns the empty string.
 * 
 * To find a filesystem from the label, use guestfs_session_findfs_label().
 * 
 * Returns: (transfer full): the returned string, or NULL on error
 * Since: 1.3.18
 */
gchar *
guestfs_session_vfs_label (GuestfsSession *session, const gchar *mountable, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "vfs_label");
    return NULL;
  }

  char *ret = guestfs_vfs_label (g, mountable);
  if (ret == NULL) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return NULL;
  }

  return ret;
}

/**
 * guestfs_session_vfs_type:
 * @session: (transfer none): A GuestfsSession object
 * @mountable: (transfer none) (type filename):
 * @err: A GError object to receive any generated errors
 *
 * get the Linux VFS type corresponding to a mounted device
 *
 * This command gets the filesystem type corresponding to the filesystem on
 * @mountable.
 * 
 * For most filesystems, the result is the name of the Linux VFS module
 * which would be used to mount this filesystem if you mounted it without
 * specifying the filesystem type. For example a string such as @ext3 or
 * @ntfs.
 * 
 * Returns: (transfer full): the returned string, or NULL on error
 * Since: 1.0.75
 */
gchar *
guestfs_session_vfs_type (GuestfsSession *session, const gchar *mountable, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "vfs_type");
    return NULL;
  }

  char *ret = guestfs_vfs_type (g, mountable);
  if (ret == NULL) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return NULL;
  }

  return ret;
}

/**
 * guestfs_session_vfs_uuid:
 * @session: (transfer none): A GuestfsSession object
 * @mountable: (transfer none) (type filename):
 * @err: A GError object to receive any generated errors
 *
 * get the filesystem UUID
 *
 * This returns the filesystem UUID of the filesystem on @mountable.
 * 
 * If the filesystem does not have a UUID, this returns the empty string.
 * 
 * To find a filesystem from the UUID, use guestfs_session_findfs_uuid().
 * 
 * Returns: (transfer full): the returned string, or NULL on error
 * Since: 1.3.18
 */
gchar *
guestfs_session_vfs_uuid (GuestfsSession *session, const gchar *mountable, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "vfs_uuid");
    return NULL;
  }

  char *ret = guestfs_vfs_uuid (g, mountable);
  if (ret == NULL) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return NULL;
  }

  return ret;
}

/**
 * guestfs_session_vg_activate:
 * @session: (transfer none): A GuestfsSession object
 * @activate: (type gboolean):
 * @volgroups: (transfer none) (array zero-terminated=1) (element-type utf8): an array of strings
 * @err: A GError object to receive any generated errors
 *
 * activate or deactivate some volume groups
 *
 * This command activates or (if @activate is false) deactivates all
 * logical volumes in the listed volume groups @volgroups.
 * 
 * This command is the same as running "vgchange -a y|n volgroups..."
 * 
 * Note that if @volgroups is an empty list then all volume groups are
 * activated or deactivated.
 * 
 * Returns: true on success, false on error
 * Since: 1.0.26
 */
gboolean
guestfs_session_vg_activate (GuestfsSession *session, gboolean activate, gchar *const *volgroups, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "vg_activate");
    return FALSE;
  }

  int ret = guestfs_vg_activate (g, activate, volgroups);
  if (ret == -1) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return FALSE;
  }

  return TRUE;
}

/**
 * guestfs_session_vg_activate_all:
 * @session: (transfer none): A GuestfsSession object
 * @activate: (type gboolean):
 * @err: A GError object to receive any generated errors
 *
 * activate or deactivate all volume groups
 *
 * This command activates or (if @activate is false) deactivates all
 * logical volumes in all volume groups.
 * 
 * This command is the same as running "vgchange -a y|n"
 * 
 * Returns: true on success, false on error
 * Since: 1.0.26
 */
gboolean
guestfs_session_vg_activate_all (GuestfsSession *session, gboolean activate, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "vg_activate_all");
    return FALSE;
  }

  int ret = guestfs_vg_activate_all (g, activate);
  if (ret == -1) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return FALSE;
  }

  return TRUE;
}

/**
 * guestfs_session_vgchange_uuid:
 * @session: (transfer none): A GuestfsSession object
 * @vg: (transfer none) (type utf8):
 * @err: A GError object to receive any generated errors
 *
 * generate a new random UUID for a volume group
 *
 * Generate a new random UUID for the volume group @vg.
 * 
 * Returns: true on success, false on error
 * Since: 1.19.26
 */
gboolean
guestfs_session_vgchange_uuid (GuestfsSession *session, const gchar *vg, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "vgchange_uuid");
    return FALSE;
  }

  int ret = guestfs_vgchange_uuid (g, vg);
  if (ret == -1) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return FALSE;
  }

  return TRUE;
}

/**
 * guestfs_session_vgchange_uuid_all:
 * @session: (transfer none): A GuestfsSession object
 * @err: A GError object to receive any generated errors
 *
 * generate new random UUIDs for all volume groups
 *
 * Generate new random UUIDs for all volume groups.
 * 
 * Returns: true on success, false on error
 * Since: 1.19.26
 */
gboolean
guestfs_session_vgchange_uuid_all (GuestfsSession *session, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "vgchange_uuid_all");
    return FALSE;
  }

  int ret = guestfs_vgchange_uuid_all (g);
  if (ret == -1) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return FALSE;
  }

  return TRUE;
}

/**
 * guestfs_session_vgcreate:
 * @session: (transfer none): A GuestfsSession object
 * @volgroup: (transfer none) (type utf8):
 * @physvols: (transfer none) (array zero-terminated=1) (element-type filename): an array of strings
 * @err: A GError object to receive any generated errors
 *
 * create an LVM volume group
 *
 * This creates an LVM volume group called @volgroup from the non-empty
 * list of physical volumes @physvols.
 * 
 * Returns: true on success, false on error
 * Since: 0.8
 */
gboolean
guestfs_session_vgcreate (GuestfsSession *session, const gchar *volgroup, gchar *const *physvols, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "vgcreate");
    return FALSE;
  }

  int ret = guestfs_vgcreate (g, volgroup, physvols);
  if (ret == -1) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return FALSE;
  }

  return TRUE;
}

/**
 * guestfs_session_vglvuuids:
 * @session: (transfer none): A GuestfsSession object
 * @vgname: (transfer none) (type utf8):
 * @err: A GError object to receive any generated errors
 *
 * get the LV UUIDs of all LVs in the volume group
 *
 * Given a VG called @vgname, this returns the UUIDs of all the logical
 * volumes created in this volume group.
 * 
 * You can use this along with guestfs_session_lvs() and
 * guestfs_session_lvuuid() calls to associate logical volumes and volume
 * groups.
 * 
 * See also guestfs_session_vgpvuuids().
 * 
 * Returns: (transfer full) (array zero-terminated=1) (element-type utf8): an array of returned strings, or NULL on error
 * Since: 1.0.87
 */
gchar **
guestfs_session_vglvuuids (GuestfsSession *session, const gchar *vgname, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "vglvuuids");
    return NULL;
  }

  char **ret = guestfs_vglvuuids (g, vgname);
  if (ret == NULL) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return NULL;
  }

  return ret;
}

/**
 * guestfs_session_vgmeta:
 * @session: (transfer none): A GuestfsSession object
 * @vgname: (transfer none) (type utf8):
 * @size_r: The size of the returned buffer, in bytes
 * @err: A GError object to receive any generated errors
 *
 * get volume group metadata
 *
 * @vgname is an LVM volume group. This command examines the volume group
 * and returns its metadata.
 * 
 * Note that the metadata is an internal structure used by LVM, subject to
 * change at any time, and is provided for information only.
 * 
 * Returns: (transfer full) (array length=size_r) (element-type guint8): an array of binary data, or NULL on error
 * Since: 1.17.20
 */
guint8 *
guestfs_session_vgmeta (GuestfsSession *session, const gchar *vgname, gsize *size_r, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "vgmeta");
    return NULL;
  }

  char *ret = guestfs_vgmeta (g, vgname, size_r);
  if (ret == NULL) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return NULL;
  }

  return (guint8 *) ret;
}

/**
 * guestfs_session_vgpvuuids:
 * @session: (transfer none): A GuestfsSession object
 * @vgname: (transfer none) (type utf8):
 * @err: A GError object to receive any generated errors
 *
 * get the PV UUIDs containing the volume group
 *
 * Given a VG called @vgname, this returns the UUIDs of all the physical
 * volumes that this volume group resides on.
 * 
 * You can use this along with guestfs_session_pvs() and
 * guestfs_session_pvuuid() calls to associate physical volumes and volume
 * groups.
 * 
 * See also guestfs_session_vglvuuids().
 * 
 * Returns: (transfer full) (array zero-terminated=1) (element-type utf8): an array of returned strings, or NULL on error
 * Since: 1.0.87
 */
gchar **
guestfs_session_vgpvuuids (GuestfsSession *session, const gchar *vgname, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "vgpvuuids");
    return NULL;
  }

  char **ret = guestfs_vgpvuuids (g, vgname);
  if (ret == NULL) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return NULL;
  }

  return ret;
}

/**
 * guestfs_session_vgremove:
 * @session: (transfer none): A GuestfsSession object
 * @vgname: (transfer none) (type utf8):
 * @err: A GError object to receive any generated errors
 *
 * remove an LVM volume group
 *
 * Remove an LVM volume group @vgname, (for example @VG).
 * 
 * This also forcibly removes all logical volumes in the volume group (if
 * any).
 * 
 * Returns: true on success, false on error
 * Since: 1.0.13
 */
gboolean
guestfs_session_vgremove (GuestfsSession *session, const gchar *vgname, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "vgremove");
    return FALSE;
  }

  int ret = guestfs_vgremove (g, vgname);
  if (ret == -1) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return FALSE;
  }

  return TRUE;
}

/**
 * guestfs_session_vgrename:
 * @session: (transfer none): A GuestfsSession object
 * @volgroup: (transfer none) (type utf8):
 * @newvolgroup: (transfer none) (type utf8):
 * @err: A GError object to receive any generated errors
 *
 * rename an LVM volume group
 *
 * Rename a volume group @volgroup with the new name @newvolgroup.
 * 
 * Returns: true on success, false on error
 * Since: 1.0.83
 */
gboolean
guestfs_session_vgrename (GuestfsSession *session, const gchar *volgroup, const gchar *newvolgroup, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "vgrename");
    return FALSE;
  }

  int ret = guestfs_vgrename (g, volgroup, newvolgroup);
  if (ret == -1) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return FALSE;
  }

  return TRUE;
}

/**
 * guestfs_session_vgs:
 * @session: (transfer none): A GuestfsSession object
 * @err: A GError object to receive any generated errors
 *
 * list the LVM volume groups (VGs)
 *
 * List all the volumes groups detected. This is the equivalent of the
 * vgs(8) command.
 * 
 * This returns a list of just the volume group names that were detected
 * (eg. @VolGroup00).
 * 
 * See also guestfs_session_vgs_full().
 * 
 * Returns: (transfer full) (array zero-terminated=1) (element-type utf8): an array of returned strings, or NULL on error
 * Since: 0.4
 */
gchar **
guestfs_session_vgs (GuestfsSession *session, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "vgs");
    return NULL;
  }

  char **ret = guestfs_vgs (g);
  if (ret == NULL) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return NULL;
  }

  return ret;
}

/**
 * guestfs_session_vgs_full:
 * @session: (transfer none): A GuestfsSession object
 * @err: A GError object to receive any generated errors
 *
 * list the LVM volume groups (VGs)
 *
 * List all the volumes groups detected. This is the equivalent of the
 * vgs(8) command. The "full" version includes all fields.
 * 
 * Returns: (transfer full) (array zero-terminated=1) (element-type GuestfsVG): an array of VG objects, or NULL on error
 * Since: 0.4
 */
GuestfsVG **
guestfs_session_vgs_full (GuestfsSession *session, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "vgs_full");
    return NULL;
  }

  struct guestfs_lvm_vg_list *ret = guestfs_vgs_full (g);
  if (ret == NULL) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return NULL;
  }

  GuestfsVG **l = g_malloc (sizeof (GuestfsVG*) * (ret->len + 1));
  gsize i;
  for (i = 0; i < ret->len; i++) {
    l[i] = g_slice_new0 (GuestfsVG);
    if (ret->val[i].vg_name) l[i]->vg_name = g_strdup (ret->val[i].vg_name);
    if (ret->val[i].vg_uuid) memcpy (l[i]->vg_uuid, ret->val[i].vg_uuid, sizeof (l[i]->vg_uuid));
    if (ret->val[i].vg_fmt) l[i]->vg_fmt = g_strdup (ret->val[i].vg_fmt);
    if (ret->val[i].vg_attr) l[i]->vg_attr = g_strdup (ret->val[i].vg_attr);
    l[i]->vg_size = ret->val[i].vg_size;
    l[i]->vg_free = ret->val[i].vg_free;
    if (ret->val[i].vg_sysid) l[i]->vg_sysid = g_strdup (ret->val[i].vg_sysid);
    l[i]->vg_extent_size = ret->val[i].vg_extent_size;
    l[i]->vg_extent_count = ret->val[i].vg_extent_count;
    l[i]->vg_free_count = ret->val[i].vg_free_count;
    l[i]->max_lv = ret->val[i].max_lv;
    l[i]->max_pv = ret->val[i].max_pv;
    l[i]->pv_count = ret->val[i].pv_count;
    l[i]->lv_count = ret->val[i].lv_count;
    l[i]->snap_count = ret->val[i].snap_count;
    l[i]->vg_seqno = ret->val[i].vg_seqno;
    if (ret->val[i].vg_tags) l[i]->vg_tags = g_strdup (ret->val[i].vg_tags);
    l[i]->vg_mda_count = ret->val[i].vg_mda_count;
    l[i]->vg_mda_free = ret->val[i].vg_mda_free;
  }
  guestfs_free_lvm_vg_list (ret);
  l[i] = NULL;
  return l;
}

/**
 * guestfs_session_vgscan:
 * @session: (transfer none): A GuestfsSession object
 * @err: A GError object to receive any generated errors
 *
 * rescan for LVM physical volumes, volume groups and logical volumes
 *
 * This rescans all block devices and rebuilds the list of LVM physical
 * volumes, volume groups and logical volumes.
 * 
 * Returns: true on success, false on error
 * Since: 1.3.2
 */
gboolean
guestfs_session_vgscan (GuestfsSession *session, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "vgscan");
    return FALSE;
  }

  int ret = guestfs_vgscan (g);
  if (ret == -1) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return FALSE;
  }

  return TRUE;
}

/**
 * guestfs_session_vguuid:
 * @session: (transfer none): A GuestfsSession object
 * @vgname: (transfer none) (type utf8):
 * @err: A GError object to receive any generated errors
 *
 * get the UUID of a volume group
 *
 * This command returns the UUID of the LVM VG named @vgname.
 * 
 * Returns: (transfer full): the returned string, or NULL on error
 * Since: 1.0.87
 */
gchar *
guestfs_session_vguuid (GuestfsSession *session, const gchar *vgname, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "vguuid");
    return NULL;
  }

  char *ret = guestfs_vguuid (g, vgname);
  if (ret == NULL) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return NULL;
  }

  return ret;
}

/**
 * guestfs_session_wait_ready:
 * @session: (transfer none): A GuestfsSession object
 * @err: A GError object to receive any generated errors
 *
 * wait until the hypervisor launches (no op)
 *
 * This function is a no op.
 * 
 * In versions of the API &lt; 1.0.71 you had to call this function just
 * after calling guestfs_session_launch() to wait for the launch to
 * complete. However this is no longer necessary because
 * guestfs_session_launch() now does the waiting.
 * 
 * If you see any calls to this function in code then you can just remove
 * them, unless you want to retain compatibility with older versions of the
 * API.
 * 
 * Returns: true on success, false on error
 * Deprecated: In new code, use guestfs_session_launch() instead
 * Since: 0.3
 */
gboolean
guestfs_session_wait_ready (GuestfsSession *session, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "wait_ready");
    return FALSE;
  }

  int ret = guestfs_wait_ready (g);
  if (ret == -1) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return FALSE;
  }

  return TRUE;
}

/**
 * guestfs_session_wc_c:
 * @session: (transfer none): A GuestfsSession object
 * @path: (transfer none) (type filename):
 * @err: A GError object to receive any generated errors
 *
 * count characters in a file
 *
 * This command counts the characters in a file, using the "wc -c" external
 * command.
 * 
 * Returns: the returned value, or -1 on error
 * Since: 1.0.54
 */
gint32
guestfs_session_wc_c (GuestfsSession *session, const gchar *path, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "wc_c");
    return -1;
  }

  int ret = guestfs_wc_c (g, path);
  if (ret == -1) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return -1;
  }

  return ret;
}

/**
 * guestfs_session_wc_l:
 * @session: (transfer none): A GuestfsSession object
 * @path: (transfer none) (type filename):
 * @err: A GError object to receive any generated errors
 *
 * count lines in a file
 *
 * This command counts the lines in a file, using the "wc -l" external
 * command.
 * 
 * Returns: the returned value, or -1 on error
 * Since: 1.0.54
 */
gint32
guestfs_session_wc_l (GuestfsSession *session, const gchar *path, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "wc_l");
    return -1;
  }

  int ret = guestfs_wc_l (g, path);
  if (ret == -1) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return -1;
  }

  return ret;
}

/**
 * guestfs_session_wc_w:
 * @session: (transfer none): A GuestfsSession object
 * @path: (transfer none) (type filename):
 * @err: A GError object to receive any generated errors
 *
 * count words in a file
 *
 * This command counts the words in a file, using the "wc -w" external
 * command.
 * 
 * Returns: the returned value, or -1 on error
 * Since: 1.0.54
 */
gint32
guestfs_session_wc_w (GuestfsSession *session, const gchar *path, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "wc_w");
    return -1;
  }

  int ret = guestfs_wc_w (g, path);
  if (ret == -1) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return -1;
  }

  return ret;
}

/**
 * guestfs_session_wipefs:
 * @session: (transfer none): A GuestfsSession object
 * @device: (transfer none) (type filename):
 * @err: A GError object to receive any generated errors
 *
 * wipe a filesystem signature from a device
 *
 * This command erases filesystem or RAID signatures from the specified
 * @device to make the filesystem invisible to libblkid.
 * 
 * This does not erase the filesystem itself nor any other data from the
 * @device.
 * 
 * Compare with guestfs_session_zero() which zeroes the first few blocks of
 * a device.
 * 
 * Returns: true on success, false on error
 * Since: 1.17.6
 */
gboolean
guestfs_session_wipefs (GuestfsSession *session, const gchar *device, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "wipefs");
    return FALSE;
  }

  int ret = guestfs_wipefs (g, device);
  if (ret == -1) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return FALSE;
  }

  return TRUE;
}

/**
 * guestfs_session_write:
 * @session: (transfer none): A GuestfsSession object
 * @path: (transfer none) (type filename):
 * @content: (transfer none) (array length=content_size) (element-type guint8): an array of binary data
 * @content_size: The size of content, in bytes
 * @err: A GError object to receive any generated errors
 *
 * create a new file
 *
 * This call creates a file called @path. The content of the file is the
 * string @content (which can contain any 8 bit data).
 * 
 * See also guestfs_session_write_append().
 * 
 * Returns: true on success, false on error
 * Since: 1.3.14
 */
gboolean
guestfs_session_write (GuestfsSession *session, const gchar *path, const guint8 *content, gsize content_size, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "write");
    return FALSE;
  }

  int ret = guestfs_write (g, path, (const char *) content, content_size);
  if (ret == -1) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return FALSE;
  }

  return TRUE;
}

/**
 * guestfs_session_write_append:
 * @session: (transfer none): A GuestfsSession object
 * @path: (transfer none) (type filename):
 * @content: (transfer none) (array length=content_size) (element-type guint8): an array of binary data
 * @content_size: The size of content, in bytes
 * @err: A GError object to receive any generated errors
 *
 * append content to end of file
 *
 * This call appends @content to the end of file @path. If @path does not
 * exist, then a new file is created.
 * 
 * See also guestfs_session_write().
 * 
 * Returns: true on success, false on error
 * Since: 1.11.18
 */
gboolean
guestfs_session_write_append (GuestfsSession *session, const gchar *path, const guint8 *content, gsize content_size, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "write_append");
    return FALSE;
  }

  int ret = guestfs_write_append (g, path, (const char *) content, content_size);
  if (ret == -1) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return FALSE;
  }

  return TRUE;
}

/**
 * guestfs_session_write_file:
 * @session: (transfer none): A GuestfsSession object
 * @path: (transfer none) (type filename):
 * @content: (transfer none) (type utf8):
 * @size: (type gint32):
 * @err: A GError object to receive any generated errors
 *
 * create a file
 *
 * This call creates a file called @path. The contents of the file is the
 * string @content (which can contain any 8 bit data), with length @size.
 * 
 * As a special case, if @size is @0 then the length is calculated using
 * @strlen (so in this case the content cannot contain embedded ASCII
 * NULs).
 * 
 * *NB.* Owing to a bug, writing content containing ASCII NUL characters
 * does *not* work, even if the length is specified.
 * 
 * Returns: true on success, false on error
 * Deprecated: In new code, use guestfs_session_write() instead
 * Since: 0.8
 */
gboolean
guestfs_session_write_file (GuestfsSession *session, const gchar *path, const gchar *content, gint32 size, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "write_file");
    return FALSE;
  }

  int ret = guestfs_write_file (g, path, content, size);
  if (ret == -1) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return FALSE;
  }

  return TRUE;
}

/**
 * guestfs_session_xfs_admin:
 * @session: (transfer none): A GuestfsSession object
 * @device: (transfer none) (type filename):
 * @optargs: (transfer none) (allow-none): a GuestfsXfsAdmin containing optional arguments
 * @err: A GError object to receive any generated errors
 *
 * change parameters of an XFS filesystem
 *
 * Change the parameters of the XFS filesystem on @device.
 * 
 * Devices that are mounted cannot be modified. Administrators must unmount
 * filesystems before this call can modify parameters.
 * 
 * Some of the parameters of a mounted filesystem can be examined and
 * modified using the guestfs_session_xfs_info() and
 * guestfs_session_xfs_growfs() calls.
 * 
 * Returns: true on success, false on error
 * Since: 1.19.33
 */
gboolean
guestfs_session_xfs_admin (GuestfsSession *session, const gchar *device, GuestfsXfsAdmin *optargs, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "xfs_admin");
    return FALSE;
  }

  struct guestfs_xfs_admin_argv argv;
  struct guestfs_xfs_admin_argv *argvp = NULL;

  if (optargs) {
    argv.bitmask = 0;

    GValue extunwritten_v = {0, };
    g_value_init (&extunwritten_v, GUESTFS_TYPE_TRISTATE);
    g_object_get_property (G_OBJECT (optargs), "extunwritten", &extunwritten_v);
    GuestfsTristate extunwritten = g_value_get_enum (&extunwritten_v);
    if (extunwritten != GUESTFS_TRISTATE_NONE) {
      argv.bitmask |= GUESTFS_XFS_ADMIN_EXTUNWRITTEN_BITMASK;
      argv.extunwritten = extunwritten;
    }
    GValue imgfile_v = {0, };
    g_value_init (&imgfile_v, GUESTFS_TYPE_TRISTATE);
    g_object_get_property (G_OBJECT (optargs), "imgfile", &imgfile_v);
    GuestfsTristate imgfile = g_value_get_enum (&imgfile_v);
    if (imgfile != GUESTFS_TRISTATE_NONE) {
      argv.bitmask |= GUESTFS_XFS_ADMIN_IMGFILE_BITMASK;
      argv.imgfile = imgfile;
    }
    GValue v2log_v = {0, };
    g_value_init (&v2log_v, GUESTFS_TYPE_TRISTATE);
    g_object_get_property (G_OBJECT (optargs), "v2log", &v2log_v);
    GuestfsTristate v2log = g_value_get_enum (&v2log_v);
    if (v2log != GUESTFS_TRISTATE_NONE) {
      argv.bitmask |= GUESTFS_XFS_ADMIN_V2LOG_BITMASK;
      argv.v2log = v2log;
    }
    GValue projid32bit_v = {0, };
    g_value_init (&projid32bit_v, GUESTFS_TYPE_TRISTATE);
    g_object_get_property (G_OBJECT (optargs), "projid32bit", &projid32bit_v);
    GuestfsTristate projid32bit = g_value_get_enum (&projid32bit_v);
    if (projid32bit != GUESTFS_TRISTATE_NONE) {
      argv.bitmask |= GUESTFS_XFS_ADMIN_PROJID32BIT_BITMASK;
      argv.projid32bit = projid32bit;
    }
    GValue lazycounter_v = {0, };
    g_value_init (&lazycounter_v, GUESTFS_TYPE_TRISTATE);
    g_object_get_property (G_OBJECT (optargs), "lazycounter", &lazycounter_v);
    GuestfsTristate lazycounter = g_value_get_enum (&lazycounter_v);
    if (lazycounter != GUESTFS_TRISTATE_NONE) {
      argv.bitmask |= GUESTFS_XFS_ADMIN_LAZYCOUNTER_BITMASK;
      argv.lazycounter = lazycounter;
    }
    GValue label_v = {0, };
    g_value_init (&label_v, G_TYPE_STRING);
    g_object_get_property (G_OBJECT (optargs), "label", &label_v);
    const gchar *label = g_value_get_string (&label_v);
    if (label != NULL) {
      argv.bitmask |= GUESTFS_XFS_ADMIN_LABEL_BITMASK;
      argv.label = label;
    }
    GValue uuid_v = {0, };
    g_value_init (&uuid_v, G_TYPE_STRING);
    g_object_get_property (G_OBJECT (optargs), "uuid", &uuid_v);
    const gchar *uuid = g_value_get_string (&uuid_v);
    if (uuid != NULL) {
      argv.bitmask |= GUESTFS_XFS_ADMIN_UUID_BITMASK;
      argv.uuid = uuid;
    }
    argvp = &argv;
  }
  int ret = guestfs_xfs_admin_argv (g, device, argvp);
  if (ret == -1) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return FALSE;
  }

  return TRUE;
}

/**
 * guestfs_session_xfs_growfs:
 * @session: (transfer none): A GuestfsSession object
 * @path: (transfer none) (type filename):
 * @optargs: (transfer none) (allow-none): a GuestfsXfsGrowfs containing optional arguments
 * @err: A GError object to receive any generated errors
 *
 * expand an existing XFS filesystem
 *
 * Grow the XFS filesystem mounted at @path.
 * 
 * The returned struct contains geometry information. Missing fields are
 * returned as @-1 (for numeric fields) or empty string.
 * 
 * Returns: true on success, false on error
 * Since: 1.19.28
 */
gboolean
guestfs_session_xfs_growfs (GuestfsSession *session, const gchar *path, GuestfsXfsGrowfs *optargs, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "xfs_growfs");
    return FALSE;
  }

  struct guestfs_xfs_growfs_argv argv;
  struct guestfs_xfs_growfs_argv *argvp = NULL;

  if (optargs) {
    argv.bitmask = 0;

    GValue datasec_v = {0, };
    g_value_init (&datasec_v, GUESTFS_TYPE_TRISTATE);
    g_object_get_property (G_OBJECT (optargs), "datasec", &datasec_v);
    GuestfsTristate datasec = g_value_get_enum (&datasec_v);
    if (datasec != GUESTFS_TRISTATE_NONE) {
      argv.bitmask |= GUESTFS_XFS_GROWFS_DATASEC_BITMASK;
      argv.datasec = datasec;
    }
    GValue logsec_v = {0, };
    g_value_init (&logsec_v, GUESTFS_TYPE_TRISTATE);
    g_object_get_property (G_OBJECT (optargs), "logsec", &logsec_v);
    GuestfsTristate logsec = g_value_get_enum (&logsec_v);
    if (logsec != GUESTFS_TRISTATE_NONE) {
      argv.bitmask |= GUESTFS_XFS_GROWFS_LOGSEC_BITMASK;
      argv.logsec = logsec;
    }
    GValue rtsec_v = {0, };
    g_value_init (&rtsec_v, GUESTFS_TYPE_TRISTATE);
    g_object_get_property (G_OBJECT (optargs), "rtsec", &rtsec_v);
    GuestfsTristate rtsec = g_value_get_enum (&rtsec_v);
    if (rtsec != GUESTFS_TRISTATE_NONE) {
      argv.bitmask |= GUESTFS_XFS_GROWFS_RTSEC_BITMASK;
      argv.rtsec = rtsec;
    }
    GValue datasize_v = {0, };
    g_value_init (&datasize_v, G_TYPE_INT64);
    g_object_get_property (G_OBJECT (optargs), "datasize", &datasize_v);
    gint64 datasize = g_value_get_int64 (&datasize_v);
    if (datasize != -1) {
      argv.bitmask |= GUESTFS_XFS_GROWFS_DATASIZE_BITMASK;
      argv.datasize = datasize;
    }
    GValue logsize_v = {0, };
    g_value_init (&logsize_v, G_TYPE_INT64);
    g_object_get_property (G_OBJECT (optargs), "logsize", &logsize_v);
    gint64 logsize = g_value_get_int64 (&logsize_v);
    if (logsize != -1) {
      argv.bitmask |= GUESTFS_XFS_GROWFS_LOGSIZE_BITMASK;
      argv.logsize = logsize;
    }
    GValue rtsize_v = {0, };
    g_value_init (&rtsize_v, G_TYPE_INT64);
    g_object_get_property (G_OBJECT (optargs), "rtsize", &rtsize_v);
    gint64 rtsize = g_value_get_int64 (&rtsize_v);
    if (rtsize != -1) {
      argv.bitmask |= GUESTFS_XFS_GROWFS_RTSIZE_BITMASK;
      argv.rtsize = rtsize;
    }
    GValue rtextsize_v = {0, };
    g_value_init (&rtextsize_v, G_TYPE_INT64);
    g_object_get_property (G_OBJECT (optargs), "rtextsize", &rtextsize_v);
    gint64 rtextsize = g_value_get_int64 (&rtextsize_v);
    if (rtextsize != -1) {
      argv.bitmask |= GUESTFS_XFS_GROWFS_RTEXTSIZE_BITMASK;
      argv.rtextsize = rtextsize;
    }
    GValue maxpct_v = {0, };
    g_value_init (&maxpct_v, G_TYPE_INT);
    g_object_get_property (G_OBJECT (optargs), "maxpct", &maxpct_v);
    gint32 maxpct = g_value_get_int (&maxpct_v);
    if (maxpct != -1) {
      argv.bitmask |= GUESTFS_XFS_GROWFS_MAXPCT_BITMASK;
      argv.maxpct = maxpct;
    }
    argvp = &argv;
  }
  int ret = guestfs_xfs_growfs_argv (g, path, argvp);
  if (ret == -1) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return FALSE;
  }

  return TRUE;
}

/**
 * guestfs_session_xfs_info:
 * @session: (transfer none): A GuestfsSession object
 * @pathordevice: (transfer none) (type filename):
 * @err: A GError object to receive any generated errors
 *
 * get geometry of XFS filesystem
 *
 * @pathordevice is a mounted XFS filesystem or a device containing an XFS
 * filesystem. This command returns the geometry of the filesystem.
 * 
 * The returned struct contains geometry information. Missing fields are
 * returned as @-1 (for numeric fields) or empty string.
 * 
 * Returns: (transfer full): a XFSInfo object, or NULL on error
 * Since: 1.19.21
 */
GuestfsXFSInfo *
guestfs_session_xfs_info (GuestfsSession *session, const gchar *pathordevice, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "xfs_info");
    return NULL;
  }

  struct guestfs_xfsinfo *ret = guestfs_xfs_info (g, pathordevice);
  if (ret == NULL) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return NULL;
  }

  GuestfsXFSInfo *s = g_slice_new0 (GuestfsXFSInfo);
  if (ret->xfs_mntpoint) s->xfs_mntpoint = g_strdup (ret->xfs_mntpoint);
  s->xfs_inodesize = ret->xfs_inodesize;
  s->xfs_agcount = ret->xfs_agcount;
  s->xfs_agsize = ret->xfs_agsize;
  s->xfs_sectsize = ret->xfs_sectsize;
  s->xfs_attr = ret->xfs_attr;
  s->xfs_blocksize = ret->xfs_blocksize;
  s->xfs_datablocks = ret->xfs_datablocks;
  s->xfs_imaxpct = ret->xfs_imaxpct;
  s->xfs_sunit = ret->xfs_sunit;
  s->xfs_swidth = ret->xfs_swidth;
  s->xfs_dirversion = ret->xfs_dirversion;
  s->xfs_dirblocksize = ret->xfs_dirblocksize;
  s->xfs_cimode = ret->xfs_cimode;
  if (ret->xfs_logname) s->xfs_logname = g_strdup (ret->xfs_logname);
  s->xfs_logblocksize = ret->xfs_logblocksize;
  s->xfs_logblocks = ret->xfs_logblocks;
  s->xfs_logversion = ret->xfs_logversion;
  s->xfs_logsectsize = ret->xfs_logsectsize;
  s->xfs_logsunit = ret->xfs_logsunit;
  s->xfs_lazycount = ret->xfs_lazycount;
  if (ret->xfs_rtname) s->xfs_rtname = g_strdup (ret->xfs_rtname);
  s->xfs_rtextsize = ret->xfs_rtextsize;
  s->xfs_rtblocks = ret->xfs_rtblocks;
  s->xfs_rtextents = ret->xfs_rtextents;
  guestfs_free_xfsinfo (ret);
  return s;
}

/**
 * guestfs_session_xfs_repair:
 * @session: (transfer none): A GuestfsSession object
 * @device: (transfer none) (type filename):
 * @optargs: (transfer none) (allow-none): a GuestfsXfsRepair containing optional arguments
 * @err: A GError object to receive any generated errors
 *
 * repair an XFS filesystem
 *
 * Repair corrupt or damaged XFS filesystem on @device.
 * 
 * The filesystem is specified using the @device argument which should be
 * the device name of the disk partition or volume containing the
 * filesystem. If given the name of a block device, @xfs_repair will
 * attempt to find the raw device associated with the specified block
 * device and will use the raw device instead.
 * 
 * Regardless, the filesystem to be repaired must be unmounted, otherwise,
 * the resulting filesystem may be inconsistent or corrupt.
 * 
 * The returned status indicates whether filesystem corruption was detected
 * (returns @1) or was not detected (returns @0).
 * 
 * Returns: the returned value, or -1 on error
 * Since: 1.19.36
 */
gint32
guestfs_session_xfs_repair (GuestfsSession *session, const gchar *device, GuestfsXfsRepair *optargs, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "xfs_repair");
    return -1;
  }

  struct guestfs_xfs_repair_argv argv;
  struct guestfs_xfs_repair_argv *argvp = NULL;

  if (optargs) {
    argv.bitmask = 0;

    GValue forcelogzero_v = {0, };
    g_value_init (&forcelogzero_v, GUESTFS_TYPE_TRISTATE);
    g_object_get_property (G_OBJECT (optargs), "forcelogzero", &forcelogzero_v);
    GuestfsTristate forcelogzero = g_value_get_enum (&forcelogzero_v);
    if (forcelogzero != GUESTFS_TRISTATE_NONE) {
      argv.bitmask |= GUESTFS_XFS_REPAIR_FORCELOGZERO_BITMASK;
      argv.forcelogzero = forcelogzero;
    }
    GValue nomodify_v = {0, };
    g_value_init (&nomodify_v, GUESTFS_TYPE_TRISTATE);
    g_object_get_property (G_OBJECT (optargs), "nomodify", &nomodify_v);
    GuestfsTristate nomodify = g_value_get_enum (&nomodify_v);
    if (nomodify != GUESTFS_TRISTATE_NONE) {
      argv.bitmask |= GUESTFS_XFS_REPAIR_NOMODIFY_BITMASK;
      argv.nomodify = nomodify;
    }
    GValue noprefetch_v = {0, };
    g_value_init (&noprefetch_v, GUESTFS_TYPE_TRISTATE);
    g_object_get_property (G_OBJECT (optargs), "noprefetch", &noprefetch_v);
    GuestfsTristate noprefetch = g_value_get_enum (&noprefetch_v);
    if (noprefetch != GUESTFS_TRISTATE_NONE) {
      argv.bitmask |= GUESTFS_XFS_REPAIR_NOPREFETCH_BITMASK;
      argv.noprefetch = noprefetch;
    }
    GValue forcegeometry_v = {0, };
    g_value_init (&forcegeometry_v, GUESTFS_TYPE_TRISTATE);
    g_object_get_property (G_OBJECT (optargs), "forcegeometry", &forcegeometry_v);
    GuestfsTristate forcegeometry = g_value_get_enum (&forcegeometry_v);
    if (forcegeometry != GUESTFS_TRISTATE_NONE) {
      argv.bitmask |= GUESTFS_XFS_REPAIR_FORCEGEOMETRY_BITMASK;
      argv.forcegeometry = forcegeometry;
    }
    GValue maxmem_v = {0, };
    g_value_init (&maxmem_v, G_TYPE_INT64);
    g_object_get_property (G_OBJECT (optargs), "maxmem", &maxmem_v);
    gint64 maxmem = g_value_get_int64 (&maxmem_v);
    if (maxmem != -1) {
      argv.bitmask |= GUESTFS_XFS_REPAIR_MAXMEM_BITMASK;
      argv.maxmem = maxmem;
    }
    GValue ihashsize_v = {0, };
    g_value_init (&ihashsize_v, G_TYPE_INT64);
    g_object_get_property (G_OBJECT (optargs), "ihashsize", &ihashsize_v);
    gint64 ihashsize = g_value_get_int64 (&ihashsize_v);
    if (ihashsize != -1) {
      argv.bitmask |= GUESTFS_XFS_REPAIR_IHASHSIZE_BITMASK;
      argv.ihashsize = ihashsize;
    }
    GValue bhashsize_v = {0, };
    g_value_init (&bhashsize_v, G_TYPE_INT64);
    g_object_get_property (G_OBJECT (optargs), "bhashsize", &bhashsize_v);
    gint64 bhashsize = g_value_get_int64 (&bhashsize_v);
    if (bhashsize != -1) {
      argv.bitmask |= GUESTFS_XFS_REPAIR_BHASHSIZE_BITMASK;
      argv.bhashsize = bhashsize;
    }
    GValue agstride_v = {0, };
    g_value_init (&agstride_v, G_TYPE_INT64);
    g_object_get_property (G_OBJECT (optargs), "agstride", &agstride_v);
    gint64 agstride = g_value_get_int64 (&agstride_v);
    if (agstride != -1) {
      argv.bitmask |= GUESTFS_XFS_REPAIR_AGSTRIDE_BITMASK;
      argv.agstride = agstride;
    }
    GValue logdev_v = {0, };
    g_value_init (&logdev_v, G_TYPE_STRING);
    g_object_get_property (G_OBJECT (optargs), "logdev", &logdev_v);
    const gchar *logdev = g_value_get_string (&logdev_v);
    if (logdev != NULL) {
      argv.bitmask |= GUESTFS_XFS_REPAIR_LOGDEV_BITMASK;
      argv.logdev = logdev;
    }
    GValue rtdev_v = {0, };
    g_value_init (&rtdev_v, G_TYPE_STRING);
    g_object_get_property (G_OBJECT (optargs), "rtdev", &rtdev_v);
    const gchar *rtdev = g_value_get_string (&rtdev_v);
    if (rtdev != NULL) {
      argv.bitmask |= GUESTFS_XFS_REPAIR_RTDEV_BITMASK;
      argv.rtdev = rtdev;
    }
    argvp = &argv;
  }
  int ret = guestfs_xfs_repair_argv (g, device, argvp);
  if (ret == -1) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return -1;
  }

  return ret;
}

/**
 * guestfs_session_zegrep:
 * @session: (transfer none): A GuestfsSession object
 * @regex: (transfer none) (type utf8):
 * @path: (transfer none) (type filename):
 * @err: A GError object to receive any generated errors
 *
 * return lines matching a pattern
 *
 * This calls the external @zegrep program and returns the matching lines.
 * 
 * Returns: (transfer full) (array zero-terminated=1) (element-type utf8): an array of returned strings, or NULL on error
 * Deprecated: In new code, use guestfs_session_grep() instead
 * Since: 1.0.66
 */
gchar **
guestfs_session_zegrep (GuestfsSession *session, const gchar *regex, const gchar *path, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "zegrep");
    return NULL;
  }

  char **ret = guestfs_zegrep (g, regex, path);
  if (ret == NULL) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return NULL;
  }

  return ret;
}

/**
 * guestfs_session_zegrepi:
 * @session: (transfer none): A GuestfsSession object
 * @regex: (transfer none) (type utf8):
 * @path: (transfer none) (type filename):
 * @err: A GError object to receive any generated errors
 *
 * return lines matching a pattern
 *
 * This calls the external "zegrep -i" program and returns the matching
 * lines.
 * 
 * Returns: (transfer full) (array zero-terminated=1) (element-type utf8): an array of returned strings, or NULL on error
 * Deprecated: In new code, use guestfs_session_grep() instead
 * Since: 1.0.66
 */
gchar **
guestfs_session_zegrepi (GuestfsSession *session, const gchar *regex, const gchar *path, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "zegrepi");
    return NULL;
  }

  char **ret = guestfs_zegrepi (g, regex, path);
  if (ret == NULL) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return NULL;
  }

  return ret;
}

/**
 * guestfs_session_zero:
 * @session: (transfer none): A GuestfsSession object
 * @device: (transfer none) (type filename):
 * @err: A GError object to receive any generated errors
 *
 * write zeroes to the device
 *
 * This command writes zeroes over the first few blocks of @device.
 * 
 * How many blocks are zeroed isn't specified (but it's *not* enough to
 * securely wipe the device). It should be sufficient to remove any
 * partition tables, filesystem superblocks and so on.
 * 
 * If blocks are already zero, then this command avoids writing zeroes.
 * This prevents the underlying device from becoming non-sparse or growing
 * unnecessarily.
 * 
 * See also: guestfs_session_zero_device(), guestfs_session_scrub_device(),
 * guestfs_session_is_zero_device()
 * 
 * Returns: true on success, false on error
 * Since: 1.0.16
 */
gboolean
guestfs_session_zero (GuestfsSession *session, const gchar *device, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "zero");
    return FALSE;
  }

  int ret = guestfs_zero (g, device);
  if (ret == -1) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return FALSE;
  }

  return TRUE;
}

/**
 * guestfs_session_zero_device:
 * @session: (transfer none): A GuestfsSession object
 * @device: (transfer none) (type filename):
 * @err: A GError object to receive any generated errors
 *
 * write zeroes to an entire device
 *
 * This command writes zeroes over the entire @device. Compare with
 * guestfs_session_zero() which just zeroes the first few blocks of a
 * device.
 * 
 * If blocks are already zero, then this command avoids writing zeroes.
 * This prevents the underlying device from becoming non-sparse or growing
 * unnecessarily.
 * 
 * Returns: true on success, false on error
 * Since: 1.3.1
 */
gboolean
guestfs_session_zero_device (GuestfsSession *session, const gchar *device, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "zero_device");
    return FALSE;
  }

  int ret = guestfs_zero_device (g, device);
  if (ret == -1) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return FALSE;
  }

  return TRUE;
}

/**
 * guestfs_session_zero_free_space:
 * @session: (transfer none): A GuestfsSession object
 * @directory: (transfer none) (type filename):
 * @err: A GError object to receive any generated errors
 *
 * zero free space in a filesystem
 *
 * Zero the free space in the filesystem mounted on directory. The
 * filesystem must be mounted read-write.
 * 
 * The filesystem contents are not affected, but any free space in the
 * filesystem is freed.
 * 
 * Free space is not "trimmed". You may want to call
 * guestfs_session_fstrim() either as an alternative to this, or after
 * calling this, depending on your requirements.
 * 
 * Returns: true on success, false on error
 * Since: 1.17.18
 */
gboolean
guestfs_session_zero_free_space (GuestfsSession *session, const gchar *directory, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "zero_free_space");
    return FALSE;
  }

  int ret = guestfs_zero_free_space (g, directory);
  if (ret == -1) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return FALSE;
  }

  return TRUE;
}

/**
 * guestfs_session_zerofree:
 * @session: (transfer none): A GuestfsSession object
 * @device: (transfer none) (type filename):
 * @err: A GError object to receive any generated errors
 *
 * zero unused inodes and disk blocks on ext2/3 filesystem
 *
 * This runs the *zerofree* program on @device. This program claims to zero
 * unused inodes and disk blocks on an ext2/3 filesystem, thus making it
 * possible to compress the filesystem more effectively.
 * 
 * You should not run this program if the filesystem is mounted.
 * 
 * It is possible that using this program can damage the filesystem or data
 * on the filesystem.
 * 
 * Returns: true on success, false on error
 * Since: 1.0.26
 */
gboolean
guestfs_session_zerofree (GuestfsSession *session, const gchar *device, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "zerofree");
    return FALSE;
  }

  int ret = guestfs_zerofree (g, device);
  if (ret == -1) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return FALSE;
  }

  return TRUE;
}

/**
 * guestfs_session_zfgrep:
 * @session: (transfer none): A GuestfsSession object
 * @pattern: (transfer none) (type utf8):
 * @path: (transfer none) (type filename):
 * @err: A GError object to receive any generated errors
 *
 * return lines matching a pattern
 *
 * This calls the external @zfgrep program and returns the matching lines.
 * 
 * Returns: (transfer full) (array zero-terminated=1) (element-type utf8): an array of returned strings, or NULL on error
 * Deprecated: In new code, use guestfs_session_grep() instead
 * Since: 1.0.66
 */
gchar **
guestfs_session_zfgrep (GuestfsSession *session, const gchar *pattern, const gchar *path, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "zfgrep");
    return NULL;
  }

  char **ret = guestfs_zfgrep (g, pattern, path);
  if (ret == NULL) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return NULL;
  }

  return ret;
}

/**
 * guestfs_session_zfgrepi:
 * @session: (transfer none): A GuestfsSession object
 * @pattern: (transfer none) (type utf8):
 * @path: (transfer none) (type filename):
 * @err: A GError object to receive any generated errors
 *
 * return lines matching a pattern
 *
 * This calls the external "zfgrep -i" program and returns the matching
 * lines.
 * 
 * Returns: (transfer full) (array zero-terminated=1) (element-type utf8): an array of returned strings, or NULL on error
 * Deprecated: In new code, use guestfs_session_grep() instead
 * Since: 1.0.66
 */
gchar **
guestfs_session_zfgrepi (GuestfsSession *session, const gchar *pattern, const gchar *path, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "zfgrepi");
    return NULL;
  }

  char **ret = guestfs_zfgrepi (g, pattern, path);
  if (ret == NULL) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return NULL;
  }

  return ret;
}

/**
 * guestfs_session_zfile:
 * @session: (transfer none): A GuestfsSession object
 * @meth: (transfer none) (type utf8):
 * @path: (transfer none) (type filename):
 * @err: A GError object to receive any generated errors
 *
 * determine file type inside a compressed file
 *
 * This command runs file after first decompressing @path using @method.
 * 
 * @method must be one of @gzip, @compress or @bzip2.
 * 
 * Since 1.0.63, use guestfs_session_file() instead which can now process
 * compressed files.
 * 
 * Returns: (transfer full): the returned string, or NULL on error
 * Deprecated: In new code, use guestfs_session_file() instead
 * Since: 1.0.59
 */
gchar *
guestfs_session_zfile (GuestfsSession *session, const gchar *meth, const gchar *path, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "zfile");
    return NULL;
  }

  char *ret = guestfs_zfile (g, meth, path);
  if (ret == NULL) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return NULL;
  }

  return ret;
}

/**
 * guestfs_session_zgrep:
 * @session: (transfer none): A GuestfsSession object
 * @regex: (transfer none) (type utf8):
 * @path: (transfer none) (type filename):
 * @err: A GError object to receive any generated errors
 *
 * return lines matching a pattern
 *
 * This calls the external @zgrep program and returns the matching lines.
 * 
 * Returns: (transfer full) (array zero-terminated=1) (element-type utf8): an array of returned strings, or NULL on error
 * Deprecated: In new code, use guestfs_session_grep() instead
 * Since: 1.0.66
 */
gchar **
guestfs_session_zgrep (GuestfsSession *session, const gchar *regex, const gchar *path, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "zgrep");
    return NULL;
  }

  char **ret = guestfs_zgrep (g, regex, path);
  if (ret == NULL) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return NULL;
  }

  return ret;
}

/**
 * guestfs_session_zgrepi:
 * @session: (transfer none): A GuestfsSession object
 * @regex: (transfer none) (type utf8):
 * @path: (transfer none) (type filename):
 * @err: A GError object to receive any generated errors
 *
 * return lines matching a pattern
 *
 * This calls the external "zgrep -i" program and returns the matching
 * lines.
 * 
 * Returns: (transfer full) (array zero-terminated=1) (element-type utf8): an array of returned strings, or NULL on error
 * Deprecated: In new code, use guestfs_session_grep() instead
 * Since: 1.0.66
 */
gchar **
guestfs_session_zgrepi (GuestfsSession *session, const gchar *regex, const gchar *path, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error (err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "zgrepi");
    return NULL;
  }

  char **ret = guestfs_zgrepi (g, regex, path);
  if (ret == NULL) {
    g_set_error_literal (err, GUESTFS_ERROR, 0, guestfs_last_error (g));
    return NULL;
  }

  return ret;
}
