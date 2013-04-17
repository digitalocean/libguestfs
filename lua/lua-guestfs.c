/* libguestfs generated file
 * WARNING: THIS FILE IS GENERATED FROM:
 *   generator/ *.ml
 * ANY CHANGES YOU MAKE TO THIS FILE WILL BE LOST.
 *
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
#include <stdint.h>
#include <inttypes.h>
#include <string.h>
#include <errno.h>
#include <assert.h>

/*#define LUA_LIB*/
#include <lua.h>
#include <lauxlib.h>

#if LUA_VERSION_NUM >= 502
#define lua_objlen lua_rawlen
#endif

#include <guestfs.h>
#include "guestfs-internal-frontend.h"

#define GUESTFS_LUA_HANDLE "guestfs handle"

/* This struct is managed on the Lua heap.  If the GC collects it,
 * the Lua '__gc' function is called which ends up calling
 * guestfs_lua_finalizer.
 *
 * There is also an entry in the Lua registry, indexed by 'g'
 * (allocated on demand) which stores per-handle Lua data.  See
 * functions 'get_per_handle_table', 'free_per_handle_table'.
 */
struct userdata {
  guestfs_h *g;          /* Libguestfs handle, NULL if closed. */
  struct event_state *es;
};

/* Structure passed to event_callback_wrapper. */
struct event_state {
  struct event_state *next;             /* Stored in a linked list. */
  lua_State *L;
  struct userdata *u;
  int ref;                              /* Reference to closure. */
};

static struct userdata *get_handle (lua_State *L, int index);

static void get_per_handle_table (lua_State *L, guestfs_h *g);
static void free_per_handle_table (lua_State *L, guestfs_h *g);

static char **get_string_list (lua_State *L, int index);
static void push_string_list (lua_State *L, char **strs);
static void push_table (lua_State *L, char **table);
static int64_t get_int64 (lua_State *L, int index);
static void push_int64 (lua_State *L, int64_t i64);
static void push_int64_array (lua_State *L, const int64_t *array, size_t len);

static void print_any (lua_State *L, int index, FILE *out);

static void event_callback_wrapper (guestfs_h *g, void *esvp, uint64_t event, int eh, int flags, const char *buf, size_t buf_len, const uint64_t *array, size_t array_len);
static uint64_t get_event (lua_State *L, int index);
static uint64_t get_event_bitmask (lua_State *L, int index);
static void push_event (lua_State *L, uint64_t event);

static void push_lvm_lv (lua_State *L, struct guestfs_lvm_lv *v);
static void push_lvm_lv_list (lua_State *L, struct guestfs_lvm_lv_list *v);
static void push_dirent (lua_State *L, struct guestfs_dirent *v);
static void push_dirent_list (lua_State *L, struct guestfs_dirent_list *v);
static void push_utsname (lua_State *L, struct guestfs_utsname *v);
static void push_version (lua_State *L, struct guestfs_version *v);
static void push_int_bool (lua_State *L, struct guestfs_int_bool *v);
static void push_partition (lua_State *L, struct guestfs_partition *v);
static void push_partition_list (lua_State *L, struct guestfs_partition_list *v);
static void push_application2 (lua_State *L, struct guestfs_application2 *v);
static void push_application2_list (lua_State *L, struct guestfs_application2_list *v);
static void push_inotify_event (lua_State *L, struct guestfs_inotify_event *v);
static void push_inotify_event_list (lua_State *L, struct guestfs_inotify_event_list *v);
static void push_xfsinfo (lua_State *L, struct guestfs_xfsinfo *v);
static void push_application (lua_State *L, struct guestfs_application *v);
static void push_application_list (lua_State *L, struct guestfs_application_list *v);
static void push_isoinfo (lua_State *L, struct guestfs_isoinfo *v);
static void push_hivex_value (lua_State *L, struct guestfs_hivex_value *v);
static void push_hivex_value_list (lua_State *L, struct guestfs_hivex_value_list *v);
static void push_xattr (lua_State *L, struct guestfs_xattr *v);
static void push_xattr_list (lua_State *L, struct guestfs_xattr_list *v);
static void push_lvm_pv (lua_State *L, struct guestfs_lvm_pv *v);
static void push_lvm_pv_list (lua_State *L, struct guestfs_lvm_pv_list *v);
static void push_lvm_vg (lua_State *L, struct guestfs_lvm_vg *v);
static void push_lvm_vg_list (lua_State *L, struct guestfs_lvm_vg_list *v);
static void push_btrfssubvolume (lua_State *L, struct guestfs_btrfssubvolume *v);
static void push_btrfssubvolume_list (lua_State *L, struct guestfs_btrfssubvolume_list *v);
static void push_mdstat (lua_State *L, struct guestfs_mdstat *v);
static void push_mdstat_list (lua_State *L, struct guestfs_mdstat_list *v);
static void push_hivex_node (lua_State *L, struct guestfs_hivex_node *v);
static void push_hivex_node_list (lua_State *L, struct guestfs_hivex_node_list *v);
static void push_stat (lua_State *L, struct guestfs_stat *v);
static void push_stat_list (lua_State *L, struct guestfs_stat_list *v);
static void push_statvfs (lua_State *L, struct guestfs_statvfs *v);

/* On the stack at 'index' should be a table.  Check if 'name' (string)
 * is a key in this table, and if so execute 'code'.  While 'code' is
 * executing, the top of stack (ie. index == -1) is the value of 'name'.
 */
#define OPTARG_IF_SET(index, name, code) \
  do {                                   \
    lua_pushliteral (L, name);           \
    lua_gettable (L, index);             \
    if (!lua_isnil (L, -1)) {            \
      code                               \
    }                                    \
    lua_pop (L, 1);                      \
  } while (0)

/* Create a new connection. */
static int
guestfs_lua_create (lua_State *L)
{
  guestfs_h *g;
  struct userdata *u;
  unsigned flags = 0;

  if (lua_gettop (L) == 1) {
    OPTARG_IF_SET (1, "environment",
        if (! lua_toboolean (L, -1))
            flags |= GUESTFS_CREATE_NO_ENVIRONMENT;
    );
    OPTARG_IF_SET (1, "close_on_exit",
        if (! lua_toboolean (L, -1))
            flags |= GUESTFS_CREATE_NO_CLOSE_ON_EXIT;
    );
  }
  else if (lua_gettop (L) > 1)
    return luaL_error (L, "Guestfs.create: too many arguments");

  g = guestfs_create_flags (flags);
  if (!g)
    return luaL_error (L, "Guestfs.create: cannot create handle: %s",
                       strerror (errno));

  guestfs_set_error_handler (g, NULL, NULL);

  u = lua_newuserdata (L, sizeof (struct userdata));
  luaL_getmetatable (L, GUESTFS_LUA_HANDLE);
  assert (lua_type (L, -1) == LUA_TTABLE);
  lua_setmetatable (L, -2);

  u->g = g;
  u->es = NULL;

  return 1;
}

static void
close_handle (lua_State *L, guestfs_h *g)
{
  guestfs_close (g);
  /* There is a potential and hard-to-solve race here: If another
   * thread allocates another 'g' at the same address, then
   * get_per_handle_table might be called with the same address
   * before we call free_per_handle_table here.  XXX
   */
  free_per_handle_table (L, g);
}

/* Finalizer. */
static int
guestfs_lua_finalizer (lua_State *L)
{
  struct userdata *u = get_handle (L, 1);
  struct event_state *es, *es_next;

  if (u->g)
    close_handle (L, u->g);

  for (es = u->es; es != NULL; es = es_next) {
    es_next = es->next;
    free (es);
  }

  /* u will be freed by Lua when we return. */

  return 0;
}

/* Explicit close. */
static int
guestfs_lua_close (lua_State *L)
{
  struct userdata *u = get_handle (L, 1);

  if (u->g) {
    close_handle (L, u->g);
    u->g = NULL;
  }

  return 0;
}

/* __tostring function attached to all exceptions. */
static int
error__tostring (lua_State *L)
{
  int code;
  const char *msg;

  lua_pushliteral (L, "code");
  lua_gettable (L, 1);
  code = luaL_checkint (L, -1);
  lua_pushliteral (L, "msg");
  lua_gettable (L, 1);
  msg = luaL_checkstring (L, -1);

  if (code)
    lua_pushfstring (L, "%s: %s", msg, strerror (code));
  else
    lua_pushstring (L, msg);

  return 1;
}

/* Return the last error in the handle. */
static int
last_error (lua_State *L, guestfs_h *g)
{
  /* Construct an error object on the stack containing 'msg'
   * and 'code' fields.
   */
  lua_newtable (L);
  lua_pushliteral (L, "msg");
  lua_pushstring (L, guestfs_last_error (g));
  lua_settable (L, -3);
  lua_pushliteral (L, "code");
  lua_pushinteger (L, guestfs_last_errno (g));
  lua_settable (L, -3);

  lua_newtable (L);
  lua_pushliteral (L, "__tostring");
  lua_pushcfunction (L, error__tostring);
  lua_settable (L, -3);

  lua_setmetatable (L, -2);

  /* Raise an exception with the error object. */
  return lua_error (L);
}

/* Push the per-handle Lua table onto the stack.  This is stored
 * in the global Lua registry.  It is allocated on demand the first
 * time you call this function.  Use luaL_ref to allocate new
 * entries in this table.
 * See also: http://www.lua.org/pil/27.3.1.html
 */
static void
get_per_handle_table (lua_State *L, guestfs_h *g)
{
 again:
  lua_pushlightuserdata (L, g);
  lua_gettable (L, LUA_REGISTRYINDEX);
  if (lua_isnil (L, -1)) {
    lua_pop (L, 1);
    /* registry[g] = {} */
    lua_pushlightuserdata (L, g);
    lua_newtable (L);
    lua_settable (L, LUA_REGISTRYINDEX);
    goto again;
  }
}

/* Free the per-handle Lua table.  It doesn't literally "free"
 * anything since the GC will do that.  It just removes the entry
 * from the global registry.
 */
static void
free_per_handle_table (lua_State *L, guestfs_h *g)
{
  /* registry[g] = nil */
  lua_pushlightuserdata (L, g);
  lua_pushnil (L);
  lua_settable (L, LUA_REGISTRYINDEX);
}

/* Set an event callback. */
static int
guestfs_lua_set_event_callback (lua_State *L)
{
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  uint64_t event_bitmask;
  int eh;
  int ref;
  struct event_state *es;

  if (g == NULL)
    return luaL_error (L, "Guestfs.%s: handle is closed",
                       "set_event_callback");

  event_bitmask = get_event_bitmask (L, 3);

  /* Save the function in the per-handle table, so that the GC doesn't
   * clean it up before the event fires.
   */
  luaL_checktype (L, 2, LUA_TFUNCTION);
  get_per_handle_table (L, g);
  lua_pushvalue (L, 2);
  ref = luaL_ref (L, -2);
  lua_pop (L, 1);

  es = malloc (sizeof *es);
  if (!es)
    return luaL_error (L, "failed to allocate event_state");
  es->next = u->es;
  es->L = L;
  es->u = u;
  es->ref = ref;
  u->es = es;

  eh = guestfs_set_event_callback (g, event_callback_wrapper,
                                   event_bitmask, 0, es);
  if (eh == -1)
    return last_error (L, g);

  /* Return the event handle. */
  lua_pushinteger (L, eh);
  return 1;
}

static void
event_callback_wrapper (guestfs_h *g,
                        void *esvp,
                        uint64_t event,
                        int eh,
                        int flags,
                        const char *buf, size_t buf_len,
                        const uint64_t *array, size_t array_len)
{
  struct event_state *es = esvp;
  lua_State *L = es->L;
  struct userdata *u = es->u;

  /* Look up the closure to call in the per-handle table. */
  get_per_handle_table (L, g);
  lua_rawgeti (L, -1, es->ref);

  if (!lua_isfunction (L, -1)) {
    fprintf (stderr, "lua-guestfs: %s: internal error: no closure found for g = %p, eh = %d\n",
             __func__, g, eh);
    goto out;
  }

  /* Call the event handler: event_handler (g, event, eh, flags, buf, array) */
  /* XXX 'g' parameter is wrong, but fixing it is rather complex.  See:
   * http://article.gmane.org/gmane.comp.lang.lua.general/95051
   */
  lua_pushlightuserdata (L, u);
  push_event (L, event);
  lua_pushinteger (L, eh);
  lua_pushinteger (L, flags);
  lua_pushlstring (L, buf, buf_len);
  push_int64_array (L, (const int64_t *) array, array_len);

  switch (lua_pcall (L, 6, 0, 0)) {
  case 0: /* call ok - do nothing */
    break;
  case LUA_ERRRUN:
    fprintf (stderr, "lua-guestfs: %s: unexpected error in event handler: ",
             __func__);
    print_any (L, -1, stderr);
    lua_pop (L, 1);
    fprintf (stderr, "\n");
    break;
  case LUA_ERRERR: /* can probably never happen */
    fprintf (stderr, "lua-guestfs: %s: error calling error handler\n",
             __func__);
    break;
  case LUA_ERRMEM:
    fprintf (stderr, "lua-guestfs: %s: memory allocation failed\n", __func__);
    break;
  default:
    fprintf (stderr, "lua-guestfs: %s: unknown error\n", __func__);
  }

  /* Pop the per-handle table. */
 out:
  lua_pop (L, 1);
}

/* Delete an event callback. */
static int
guestfs_lua_delete_event_callback (lua_State *L)
{
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  int eh;

  if (g == NULL)
    return luaL_error (L, "Guestfs.%s: handle is closed",
                       "delete_event_callback");

  eh = luaL_checkint (L, 2);

  guestfs_delete_event_callback (g, eh);

  return 0;
}

static int
guestfs_lua_acl_delete_def_file (lua_State *L)
{
  int r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  const char *dir;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "acl_delete_def_file");

  dir = luaL_checkstring (L, 2);

  r = guestfs_acl_delete_def_file (g, dir);
  if (r == -1)
    return last_error (L, g);

  return 0;
}

static int
guestfs_lua_acl_get_file (lua_State *L)
{
  char *r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  const char *path;
  const char *acltype;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "acl_get_file");

  path = luaL_checkstring (L, 2);
  acltype = luaL_checkstring (L, 3);

  r = guestfs_acl_get_file (g, path, acltype);
  if (r == NULL)
    return last_error (L, g);

  lua_pushstring (L, r);
  free (r);
  return 1;
}

static int
guestfs_lua_acl_set_file (lua_State *L)
{
  int r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  const char *path;
  const char *acltype;
  const char *acl;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "acl_set_file");

  path = luaL_checkstring (L, 2);
  acltype = luaL_checkstring (L, 3);
  acl = luaL_checkstring (L, 4);

  r = guestfs_acl_set_file (g, path, acltype, acl);
  if (r == -1)
    return last_error (L, g);

  return 0;
}

static int
guestfs_lua_add_cdrom (lua_State *L)
{
  int r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  const char *filename;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "add_cdrom");

  filename = luaL_checkstring (L, 2);

  r = guestfs_add_cdrom (g, filename);
  if (r == -1)
    return last_error (L, g);

  return 0;
}

static int
guestfs_lua_add_domain (lua_State *L)
{
  int r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  const char *dom;
  struct guestfs_add_domain_argv optargs_s = { .bitmask = 0 };
  struct guestfs_add_domain_argv *optargs = &optargs_s;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "add_domain");

  dom = luaL_checkstring (L, 2);

  /* Check for optional arguments, encoded in a table. */
  if (lua_type (L, 3) == LUA_TTABLE) {
    OPTARG_IF_SET (3, "libvirturi",
      optargs_s.bitmask |= GUESTFS_ADD_DOMAIN_LIBVIRTURI_BITMASK;
      optargs_s.libvirturi = luaL_checkstring (L, -1);
    );
    OPTARG_IF_SET (3, "readonly",
      optargs_s.bitmask |= GUESTFS_ADD_DOMAIN_READONLY_BITMASK;
      optargs_s.readonly = lua_toboolean (L, -1);
    );
    OPTARG_IF_SET (3, "iface",
      optargs_s.bitmask |= GUESTFS_ADD_DOMAIN_IFACE_BITMASK;
      optargs_s.iface = luaL_checkstring (L, -1);
    );
    OPTARG_IF_SET (3, "live",
      optargs_s.bitmask |= GUESTFS_ADD_DOMAIN_LIVE_BITMASK;
      optargs_s.live = lua_toboolean (L, -1);
    );
    OPTARG_IF_SET (3, "allowuuid",
      optargs_s.bitmask |= GUESTFS_ADD_DOMAIN_ALLOWUUID_BITMASK;
      optargs_s.allowuuid = lua_toboolean (L, -1);
    );
    OPTARG_IF_SET (3, "readonlydisk",
      optargs_s.bitmask |= GUESTFS_ADD_DOMAIN_READONLYDISK_BITMASK;
      optargs_s.readonlydisk = luaL_checkstring (L, -1);
    );
  }

  r = guestfs_add_domain_argv (g, dom, optargs);
  if (r == -1)
    return last_error (L, g);

  lua_pushinteger (L, r);
  return 1;
}

static int
guestfs_lua_add_drive (lua_State *L)
{
  int r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  const char *filename;
  struct guestfs_add_drive_opts_argv optargs_s = { .bitmask = 0 };
  struct guestfs_add_drive_opts_argv *optargs = &optargs_s;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "add_drive");

  filename = luaL_checkstring (L, 2);

  /* Check for optional arguments, encoded in a table. */
  if (lua_type (L, 3) == LUA_TTABLE) {
    OPTARG_IF_SET (3, "readonly",
      optargs_s.bitmask |= GUESTFS_ADD_DRIVE_OPTS_READONLY_BITMASK;
      optargs_s.readonly = lua_toboolean (L, -1);
    );
    OPTARG_IF_SET (3, "format",
      optargs_s.bitmask |= GUESTFS_ADD_DRIVE_OPTS_FORMAT_BITMASK;
      optargs_s.format = luaL_checkstring (L, -1);
    );
    OPTARG_IF_SET (3, "iface",
      optargs_s.bitmask |= GUESTFS_ADD_DRIVE_OPTS_IFACE_BITMASK;
      optargs_s.iface = luaL_checkstring (L, -1);
    );
    OPTARG_IF_SET (3, "name",
      optargs_s.bitmask |= GUESTFS_ADD_DRIVE_OPTS_NAME_BITMASK;
      optargs_s.name = luaL_checkstring (L, -1);
    );
    OPTARG_IF_SET (3, "label",
      optargs_s.bitmask |= GUESTFS_ADD_DRIVE_OPTS_LABEL_BITMASK;
      optargs_s.label = luaL_checkstring (L, -1);
    );
    OPTARG_IF_SET (3, "protocol",
      optargs_s.bitmask |= GUESTFS_ADD_DRIVE_OPTS_PROTOCOL_BITMASK;
      optargs_s.protocol = luaL_checkstring (L, -1);
    );
    OPTARG_IF_SET (3, "server",
      optargs_s.bitmask |= GUESTFS_ADD_DRIVE_OPTS_SERVER_BITMASK;
      optargs_s.server = get_string_list (L, -1);
    );
  }

  r = guestfs_add_drive_opts_argv (g, filename, optargs);
  free ((char *) optargs_s.server);
  if (r == -1)
    return last_error (L, g);

  return 0;
}

static int
guestfs_lua_add_drive_ro (lua_State *L)
{
  int r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  const char *filename;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "add_drive_ro");

  filename = luaL_checkstring (L, 2);

  r = guestfs_add_drive_ro (g, filename);
  if (r == -1)
    return last_error (L, g);

  return 0;
}

static int
guestfs_lua_add_drive_ro_with_if (lua_State *L)
{
  int r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  const char *filename;
  const char *iface;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "add_drive_ro_with_if");

  filename = luaL_checkstring (L, 2);
  iface = luaL_checkstring (L, 3);

  r = guestfs_add_drive_ro_with_if (g, filename, iface);
  if (r == -1)
    return last_error (L, g);

  return 0;
}

static int
guestfs_lua_add_drive_with_if (lua_State *L)
{
  int r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  const char *filename;
  const char *iface;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "add_drive_with_if");

  filename = luaL_checkstring (L, 2);
  iface = luaL_checkstring (L, 3);

  r = guestfs_add_drive_with_if (g, filename, iface);
  if (r == -1)
    return last_error (L, g);

  return 0;
}

static int
guestfs_lua_aug_clear (lua_State *L)
{
  int r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  const char *augpath;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "aug_clear");

  augpath = luaL_checkstring (L, 2);

  r = guestfs_aug_clear (g, augpath);
  if (r == -1)
    return last_error (L, g);

  return 0;
}

static int
guestfs_lua_aug_close (lua_State *L)
{
  int r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "aug_close");


  r = guestfs_aug_close (g);
  if (r == -1)
    return last_error (L, g);

  return 0;
}

static int
guestfs_lua_aug_defnode (lua_State *L)
{
  struct guestfs_int_bool *r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  const char *name;
  const char *expr;
  const char *val;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "aug_defnode");

  name = luaL_checkstring (L, 2);
  expr = luaL_checkstring (L, 3);
  val = luaL_checkstring (L, 4);

  r = guestfs_aug_defnode (g, name, expr, val);
  if (r == NULL)
    return last_error (L, g);

  push_int_bool (L, r);
  guestfs_free_int_bool (r);
  return 1;
}

static int
guestfs_lua_aug_defvar (lua_State *L)
{
  int r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  const char *name;
  const char *expr;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "aug_defvar");

  name = luaL_checkstring (L, 2);
  expr = luaL_optstring (L, 3, NULL);

  r = guestfs_aug_defvar (g, name, expr);
  if (r == -1)
    return last_error (L, g);

  lua_pushinteger (L, r);
  return 1;
}

static int
guestfs_lua_aug_get (lua_State *L)
{
  char *r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  const char *augpath;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "aug_get");

  augpath = luaL_checkstring (L, 2);

  r = guestfs_aug_get (g, augpath);
  if (r == NULL)
    return last_error (L, g);

  lua_pushstring (L, r);
  free (r);
  return 1;
}

static int
guestfs_lua_aug_init (lua_State *L)
{
  int r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  const char *root;
  int flags;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "aug_init");

  root = luaL_checkstring (L, 2);
  flags = luaL_checkint (L, 3);

  r = guestfs_aug_init (g, root, flags);
  if (r == -1)
    return last_error (L, g);

  return 0;
}

static int
guestfs_lua_aug_insert (lua_State *L)
{
  int r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  const char *augpath;
  const char *label;
  int before;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "aug_insert");

  augpath = luaL_checkstring (L, 2);
  label = luaL_checkstring (L, 3);
  before = lua_toboolean (L, 4);

  r = guestfs_aug_insert (g, augpath, label, before);
  if (r == -1)
    return last_error (L, g);

  return 0;
}

static int
guestfs_lua_aug_load (lua_State *L)
{
  int r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "aug_load");


  r = guestfs_aug_load (g);
  if (r == -1)
    return last_error (L, g);

  return 0;
}

static int
guestfs_lua_aug_ls (lua_State *L)
{
  char **r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  const char *augpath;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "aug_ls");

  augpath = luaL_checkstring (L, 2);

  r = guestfs_aug_ls (g, augpath);
  if (r == NULL)
    return last_error (L, g);

  push_string_list (L, r);
  guestfs___free_string_list (r);
  return 1;
}

static int
guestfs_lua_aug_match (lua_State *L)
{
  char **r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  const char *augpath;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "aug_match");

  augpath = luaL_checkstring (L, 2);

  r = guestfs_aug_match (g, augpath);
  if (r == NULL)
    return last_error (L, g);

  push_string_list (L, r);
  guestfs___free_string_list (r);
  return 1;
}

static int
guestfs_lua_aug_mv (lua_State *L)
{
  int r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  const char *src;
  const char *dest;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "aug_mv");

  src = luaL_checkstring (L, 2);
  dest = luaL_checkstring (L, 3);

  r = guestfs_aug_mv (g, src, dest);
  if (r == -1)
    return last_error (L, g);

  return 0;
}

static int
guestfs_lua_aug_rm (lua_State *L)
{
  int r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  const char *augpath;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "aug_rm");

  augpath = luaL_checkstring (L, 2);

  r = guestfs_aug_rm (g, augpath);
  if (r == -1)
    return last_error (L, g);

  lua_pushinteger (L, r);
  return 1;
}

static int
guestfs_lua_aug_save (lua_State *L)
{
  int r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "aug_save");


  r = guestfs_aug_save (g);
  if (r == -1)
    return last_error (L, g);

  return 0;
}

static int
guestfs_lua_aug_set (lua_State *L)
{
  int r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  const char *augpath;
  const char *val;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "aug_set");

  augpath = luaL_checkstring (L, 2);
  val = luaL_checkstring (L, 3);

  r = guestfs_aug_set (g, augpath, val);
  if (r == -1)
    return last_error (L, g);

  return 0;
}

static int
guestfs_lua_available (lua_State *L)
{
  int r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  char **groups;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "available");

  groups = get_string_list (L, 2);

  r = guestfs_available (g, groups);
  free (groups);
  if (r == -1)
    return last_error (L, g);

  return 0;
}

static int
guestfs_lua_available_all_groups (lua_State *L)
{
  char **r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "available_all_groups");


  r = guestfs_available_all_groups (g);
  if (r == NULL)
    return last_error (L, g);

  push_string_list (L, r);
  guestfs___free_string_list (r);
  return 1;
}

static int
guestfs_lua_base64_in (lua_State *L)
{
  int r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  const char *base64file;
  const char *filename;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "base64_in");

  base64file = luaL_checkstring (L, 2);
  filename = luaL_checkstring (L, 3);

  r = guestfs_base64_in (g, base64file, filename);
  if (r == -1)
    return last_error (L, g);

  return 0;
}

static int
guestfs_lua_base64_out (lua_State *L)
{
  int r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  const char *filename;
  const char *base64file;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "base64_out");

  filename = luaL_checkstring (L, 2);
  base64file = luaL_checkstring (L, 3);

  r = guestfs_base64_out (g, filename, base64file);
  if (r == -1)
    return last_error (L, g);

  return 0;
}

static int
guestfs_lua_blkid (lua_State *L)
{
  char **r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  const char *device;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "blkid");

  device = luaL_checkstring (L, 2);

  r = guestfs_blkid (g, device);
  if (r == NULL)
    return last_error (L, g);

  push_table (L, r);
  guestfs___free_string_list (r);
  return 1;
}

static int
guestfs_lua_blockdev_flushbufs (lua_State *L)
{
  int r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  const char *device;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "blockdev_flushbufs");

  device = luaL_checkstring (L, 2);

  r = guestfs_blockdev_flushbufs (g, device);
  if (r == -1)
    return last_error (L, g);

  return 0;
}

static int
guestfs_lua_blockdev_getbsz (lua_State *L)
{
  int r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  const char *device;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "blockdev_getbsz");

  device = luaL_checkstring (L, 2);

  r = guestfs_blockdev_getbsz (g, device);
  if (r == -1)
    return last_error (L, g);

  lua_pushinteger (L, r);
  return 1;
}

static int
guestfs_lua_blockdev_getro (lua_State *L)
{
  int r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  const char *device;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "blockdev_getro");

  device = luaL_checkstring (L, 2);

  r = guestfs_blockdev_getro (g, device);
  if (r == -1)
    return last_error (L, g);

  lua_pushboolean (L, r);
  return 1;
}

static int
guestfs_lua_blockdev_getsize64 (lua_State *L)
{
  int64_t r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  const char *device;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "blockdev_getsize64");

  device = luaL_checkstring (L, 2);

  r = guestfs_blockdev_getsize64 (g, device);
  if (r == -1)
    return last_error (L, g);

  push_int64 (L, r);
  return 1;
}

static int
guestfs_lua_blockdev_getss (lua_State *L)
{
  int r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  const char *device;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "blockdev_getss");

  device = luaL_checkstring (L, 2);

  r = guestfs_blockdev_getss (g, device);
  if (r == -1)
    return last_error (L, g);

  lua_pushinteger (L, r);
  return 1;
}

static int
guestfs_lua_blockdev_getsz (lua_State *L)
{
  int64_t r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  const char *device;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "blockdev_getsz");

  device = luaL_checkstring (L, 2);

  r = guestfs_blockdev_getsz (g, device);
  if (r == -1)
    return last_error (L, g);

  push_int64 (L, r);
  return 1;
}

static int
guestfs_lua_blockdev_rereadpt (lua_State *L)
{
  int r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  const char *device;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "blockdev_rereadpt");

  device = luaL_checkstring (L, 2);

  r = guestfs_blockdev_rereadpt (g, device);
  if (r == -1)
    return last_error (L, g);

  return 0;
}

static int
guestfs_lua_blockdev_setbsz (lua_State *L)
{
  int r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  const char *device;
  int blocksize;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "blockdev_setbsz");

  device = luaL_checkstring (L, 2);
  blocksize = luaL_checkint (L, 3);

  r = guestfs_blockdev_setbsz (g, device, blocksize);
  if (r == -1)
    return last_error (L, g);

  return 0;
}

static int
guestfs_lua_blockdev_setro (lua_State *L)
{
  int r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  const char *device;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "blockdev_setro");

  device = luaL_checkstring (L, 2);

  r = guestfs_blockdev_setro (g, device);
  if (r == -1)
    return last_error (L, g);

  return 0;
}

static int
guestfs_lua_blockdev_setrw (lua_State *L)
{
  int r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  const char *device;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "blockdev_setrw");

  device = luaL_checkstring (L, 2);

  r = guestfs_blockdev_setrw (g, device);
  if (r == -1)
    return last_error (L, g);

  return 0;
}

static int
guestfs_lua_btrfs_device_add (lua_State *L)
{
  int r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  char **devices;
  const char *fs;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "btrfs_device_add");

  devices = get_string_list (L, 2);
  fs = luaL_checkstring (L, 3);

  r = guestfs_btrfs_device_add (g, devices, fs);
  free (devices);
  if (r == -1)
    return last_error (L, g);

  return 0;
}

static int
guestfs_lua_btrfs_device_delete (lua_State *L)
{
  int r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  char **devices;
  const char *fs;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "btrfs_device_delete");

  devices = get_string_list (L, 2);
  fs = luaL_checkstring (L, 3);

  r = guestfs_btrfs_device_delete (g, devices, fs);
  free (devices);
  if (r == -1)
    return last_error (L, g);

  return 0;
}

static int
guestfs_lua_btrfs_filesystem_balance (lua_State *L)
{
  int r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  const char *fs;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "btrfs_filesystem_balance");

  fs = luaL_checkstring (L, 2);

  r = guestfs_btrfs_filesystem_balance (g, fs);
  if (r == -1)
    return last_error (L, g);

  return 0;
}

static int
guestfs_lua_btrfs_filesystem_resize (lua_State *L)
{
  int r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  const char *mountpoint;
  struct guestfs_btrfs_filesystem_resize_argv optargs_s = { .bitmask = 0 };
  struct guestfs_btrfs_filesystem_resize_argv *optargs = &optargs_s;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "btrfs_filesystem_resize");

  mountpoint = luaL_checkstring (L, 2);

  /* Check for optional arguments, encoded in a table. */
  if (lua_type (L, 3) == LUA_TTABLE) {
    OPTARG_IF_SET (3, "size",
      optargs_s.bitmask |= GUESTFS_BTRFS_FILESYSTEM_RESIZE_SIZE_BITMASK;
      optargs_s.size = get_int64 (L, -1);
    );
  }

  r = guestfs_btrfs_filesystem_resize_argv (g, mountpoint, optargs);
  if (r == -1)
    return last_error (L, g);

  return 0;
}

static int
guestfs_lua_btrfs_filesystem_sync (lua_State *L)
{
  int r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  const char *fs;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "btrfs_filesystem_sync");

  fs = luaL_checkstring (L, 2);

  r = guestfs_btrfs_filesystem_sync (g, fs);
  if (r == -1)
    return last_error (L, g);

  return 0;
}

static int
guestfs_lua_btrfs_fsck (lua_State *L)
{
  int r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  const char *device;
  struct guestfs_btrfs_fsck_argv optargs_s = { .bitmask = 0 };
  struct guestfs_btrfs_fsck_argv *optargs = &optargs_s;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "btrfs_fsck");

  device = luaL_checkstring (L, 2);

  /* Check for optional arguments, encoded in a table. */
  if (lua_type (L, 3) == LUA_TTABLE) {
    OPTARG_IF_SET (3, "superblock",
      optargs_s.bitmask |= GUESTFS_BTRFS_FSCK_SUPERBLOCK_BITMASK;
      optargs_s.superblock = get_int64 (L, -1);
    );
    OPTARG_IF_SET (3, "repair",
      optargs_s.bitmask |= GUESTFS_BTRFS_FSCK_REPAIR_BITMASK;
      optargs_s.repair = lua_toboolean (L, -1);
    );
  }

  r = guestfs_btrfs_fsck_argv (g, device, optargs);
  if (r == -1)
    return last_error (L, g);

  return 0;
}

static int
guestfs_lua_btrfs_set_seeding (lua_State *L)
{
  int r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  const char *device;
  int seeding;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "btrfs_set_seeding");

  device = luaL_checkstring (L, 2);
  seeding = lua_toboolean (L, 3);

  r = guestfs_btrfs_set_seeding (g, device, seeding);
  if (r == -1)
    return last_error (L, g);

  return 0;
}

static int
guestfs_lua_btrfs_subvolume_create (lua_State *L)
{
  int r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  const char *dest;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "btrfs_subvolume_create");

  dest = luaL_checkstring (L, 2);

  r = guestfs_btrfs_subvolume_create (g, dest);
  if (r == -1)
    return last_error (L, g);

  return 0;
}

static int
guestfs_lua_btrfs_subvolume_delete (lua_State *L)
{
  int r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  const char *subvolume;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "btrfs_subvolume_delete");

  subvolume = luaL_checkstring (L, 2);

  r = guestfs_btrfs_subvolume_delete (g, subvolume);
  if (r == -1)
    return last_error (L, g);

  return 0;
}

static int
guestfs_lua_btrfs_subvolume_list (lua_State *L)
{
  struct guestfs_btrfssubvolume_list *r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  const char *fs;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "btrfs_subvolume_list");

  fs = luaL_checkstring (L, 2);

  r = guestfs_btrfs_subvolume_list (g, fs);
  if (r == NULL)
    return last_error (L, g);

  push_btrfssubvolume_list (L, r);
  guestfs_free_btrfssubvolume_list (r);
  return 1;
}

static int
guestfs_lua_btrfs_subvolume_set_default (lua_State *L)
{
  int r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  int64_t id;
  const char *fs;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "btrfs_subvolume_set_default");

  id = get_int64 (L, 2);
  fs = luaL_checkstring (L, 3);

  r = guestfs_btrfs_subvolume_set_default (g, id, fs);
  if (r == -1)
    return last_error (L, g);

  return 0;
}

static int
guestfs_lua_btrfs_subvolume_snapshot (lua_State *L)
{
  int r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  const char *source;
  const char *dest;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "btrfs_subvolume_snapshot");

  source = luaL_checkstring (L, 2);
  dest = luaL_checkstring (L, 3);

  r = guestfs_btrfs_subvolume_snapshot (g, source, dest);
  if (r == -1)
    return last_error (L, g);

  return 0;
}

static int
guestfs_lua_canonical_device_name (lua_State *L)
{
  char *r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  const char *device;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "canonical_device_name");

  device = luaL_checkstring (L, 2);

  r = guestfs_canonical_device_name (g, device);
  if (r == NULL)
    return last_error (L, g);

  lua_pushstring (L, r);
  free (r);
  return 1;
}

static int
guestfs_lua_cap_get_file (lua_State *L)
{
  char *r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  const char *path;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "cap_get_file");

  path = luaL_checkstring (L, 2);

  r = guestfs_cap_get_file (g, path);
  if (r == NULL)
    return last_error (L, g);

  lua_pushstring (L, r);
  free (r);
  return 1;
}

static int
guestfs_lua_cap_set_file (lua_State *L)
{
  int r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  const char *path;
  const char *cap;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "cap_set_file");

  path = luaL_checkstring (L, 2);
  cap = luaL_checkstring (L, 3);

  r = guestfs_cap_set_file (g, path, cap);
  if (r == -1)
    return last_error (L, g);

  return 0;
}

static int
guestfs_lua_case_sensitive_path (lua_State *L)
{
  char *r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  const char *path;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "case_sensitive_path");

  path = luaL_checkstring (L, 2);

  r = guestfs_case_sensitive_path (g, path);
  if (r == NULL)
    return last_error (L, g);

  lua_pushstring (L, r);
  free (r);
  return 1;
}

static int
guestfs_lua_cat (lua_State *L)
{
  char *r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  const char *path;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "cat");

  path = luaL_checkstring (L, 2);

  r = guestfs_cat (g, path);
  if (r == NULL)
    return last_error (L, g);

  lua_pushstring (L, r);
  free (r);
  return 1;
}

static int
guestfs_lua_checksum (lua_State *L)
{
  char *r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  const char *csumtype;
  const char *path;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "checksum");

  csumtype = luaL_checkstring (L, 2);
  path = luaL_checkstring (L, 3);

  r = guestfs_checksum (g, csumtype, path);
  if (r == NULL)
    return last_error (L, g);

  lua_pushstring (L, r);
  free (r);
  return 1;
}

static int
guestfs_lua_checksum_device (lua_State *L)
{
  char *r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  const char *csumtype;
  const char *device;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "checksum_device");

  csumtype = luaL_checkstring (L, 2);
  device = luaL_checkstring (L, 3);

  r = guestfs_checksum_device (g, csumtype, device);
  if (r == NULL)
    return last_error (L, g);

  lua_pushstring (L, r);
  free (r);
  return 1;
}

static int
guestfs_lua_checksums_out (lua_State *L)
{
  int r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  const char *csumtype;
  const char *directory;
  const char *sumsfile;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "checksums_out");

  csumtype = luaL_checkstring (L, 2);
  directory = luaL_checkstring (L, 3);
  sumsfile = luaL_checkstring (L, 4);

  r = guestfs_checksums_out (g, csumtype, directory, sumsfile);
  if (r == -1)
    return last_error (L, g);

  return 0;
}

static int
guestfs_lua_chmod (lua_State *L)
{
  int r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  int mode;
  const char *path;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "chmod");

  mode = luaL_checkint (L, 2);
  path = luaL_checkstring (L, 3);

  r = guestfs_chmod (g, mode, path);
  if (r == -1)
    return last_error (L, g);

  return 0;
}

static int
guestfs_lua_chown (lua_State *L)
{
  int r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  int owner;
  int group;
  const char *path;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "chown");

  owner = luaL_checkint (L, 2);
  group = luaL_checkint (L, 3);
  path = luaL_checkstring (L, 4);

  r = guestfs_chown (g, owner, group, path);
  if (r == -1)
    return last_error (L, g);

  return 0;
}

static int
guestfs_lua_command (lua_State *L)
{
  char *r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  char **arguments;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "command");

  arguments = get_string_list (L, 2);

  r = guestfs_command (g, arguments);
  free (arguments);
  if (r == NULL)
    return last_error (L, g);

  lua_pushstring (L, r);
  free (r);
  return 1;
}

static int
guestfs_lua_command_lines (lua_State *L)
{
  char **r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  char **arguments;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "command_lines");

  arguments = get_string_list (L, 2);

  r = guestfs_command_lines (g, arguments);
  free (arguments);
  if (r == NULL)
    return last_error (L, g);

  push_string_list (L, r);
  guestfs___free_string_list (r);
  return 1;
}

static int
guestfs_lua_compress_device_out (lua_State *L)
{
  int r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  const char *ctype;
  const char *device;
  const char *zdevice;
  struct guestfs_compress_device_out_argv optargs_s = { .bitmask = 0 };
  struct guestfs_compress_device_out_argv *optargs = &optargs_s;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "compress_device_out");

  ctype = luaL_checkstring (L, 2);
  device = luaL_checkstring (L, 3);
  zdevice = luaL_checkstring (L, 4);

  /* Check for optional arguments, encoded in a table. */
  if (lua_type (L, 5) == LUA_TTABLE) {
    OPTARG_IF_SET (5, "level",
      optargs_s.bitmask |= GUESTFS_COMPRESS_DEVICE_OUT_LEVEL_BITMASK;
      optargs_s.level = luaL_checkint (L, -1);
    );
  }

  r = guestfs_compress_device_out_argv (g, ctype, device, zdevice, optargs);
  if (r == -1)
    return last_error (L, g);

  return 0;
}

static int
guestfs_lua_compress_out (lua_State *L)
{
  int r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  const char *ctype;
  const char *file;
  const char *zfile;
  struct guestfs_compress_out_argv optargs_s = { .bitmask = 0 };
  struct guestfs_compress_out_argv *optargs = &optargs_s;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "compress_out");

  ctype = luaL_checkstring (L, 2);
  file = luaL_checkstring (L, 3);
  zfile = luaL_checkstring (L, 4);

  /* Check for optional arguments, encoded in a table. */
  if (lua_type (L, 5) == LUA_TTABLE) {
    OPTARG_IF_SET (5, "level",
      optargs_s.bitmask |= GUESTFS_COMPRESS_OUT_LEVEL_BITMASK;
      optargs_s.level = luaL_checkint (L, -1);
    );
  }

  r = guestfs_compress_out_argv (g, ctype, file, zfile, optargs);
  if (r == -1)
    return last_error (L, g);

  return 0;
}

static int
guestfs_lua_config (lua_State *L)
{
  int r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  const char *qemuparam;
  const char *qemuvalue;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "config");

  qemuparam = luaL_checkstring (L, 2);
  qemuvalue = luaL_optstring (L, 3, NULL);

  r = guestfs_config (g, qemuparam, qemuvalue);
  if (r == -1)
    return last_error (L, g);

  return 0;
}

static int
guestfs_lua_copy_device_to_device (lua_State *L)
{
  int r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  const char *src;
  const char *dest;
  struct guestfs_copy_device_to_device_argv optargs_s = { .bitmask = 0 };
  struct guestfs_copy_device_to_device_argv *optargs = &optargs_s;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "copy_device_to_device");

  src = luaL_checkstring (L, 2);
  dest = luaL_checkstring (L, 3);

  /* Check for optional arguments, encoded in a table. */
  if (lua_type (L, 4) == LUA_TTABLE) {
    OPTARG_IF_SET (4, "srcoffset",
      optargs_s.bitmask |= GUESTFS_COPY_DEVICE_TO_DEVICE_SRCOFFSET_BITMASK;
      optargs_s.srcoffset = get_int64 (L, -1);
    );
    OPTARG_IF_SET (4, "destoffset",
      optargs_s.bitmask |= GUESTFS_COPY_DEVICE_TO_DEVICE_DESTOFFSET_BITMASK;
      optargs_s.destoffset = get_int64 (L, -1);
    );
    OPTARG_IF_SET (4, "size",
      optargs_s.bitmask |= GUESTFS_COPY_DEVICE_TO_DEVICE_SIZE_BITMASK;
      optargs_s.size = get_int64 (L, -1);
    );
  }

  r = guestfs_copy_device_to_device_argv (g, src, dest, optargs);
  if (r == -1)
    return last_error (L, g);

  return 0;
}

static int
guestfs_lua_copy_device_to_file (lua_State *L)
{
  int r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  const char *src;
  const char *dest;
  struct guestfs_copy_device_to_file_argv optargs_s = { .bitmask = 0 };
  struct guestfs_copy_device_to_file_argv *optargs = &optargs_s;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "copy_device_to_file");

  src = luaL_checkstring (L, 2);
  dest = luaL_checkstring (L, 3);

  /* Check for optional arguments, encoded in a table. */
  if (lua_type (L, 4) == LUA_TTABLE) {
    OPTARG_IF_SET (4, "srcoffset",
      optargs_s.bitmask |= GUESTFS_COPY_DEVICE_TO_FILE_SRCOFFSET_BITMASK;
      optargs_s.srcoffset = get_int64 (L, -1);
    );
    OPTARG_IF_SET (4, "destoffset",
      optargs_s.bitmask |= GUESTFS_COPY_DEVICE_TO_FILE_DESTOFFSET_BITMASK;
      optargs_s.destoffset = get_int64 (L, -1);
    );
    OPTARG_IF_SET (4, "size",
      optargs_s.bitmask |= GUESTFS_COPY_DEVICE_TO_FILE_SIZE_BITMASK;
      optargs_s.size = get_int64 (L, -1);
    );
  }

  r = guestfs_copy_device_to_file_argv (g, src, dest, optargs);
  if (r == -1)
    return last_error (L, g);

  return 0;
}

static int
guestfs_lua_copy_file_to_device (lua_State *L)
{
  int r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  const char *src;
  const char *dest;
  struct guestfs_copy_file_to_device_argv optargs_s = { .bitmask = 0 };
  struct guestfs_copy_file_to_device_argv *optargs = &optargs_s;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "copy_file_to_device");

  src = luaL_checkstring (L, 2);
  dest = luaL_checkstring (L, 3);

  /* Check for optional arguments, encoded in a table. */
  if (lua_type (L, 4) == LUA_TTABLE) {
    OPTARG_IF_SET (4, "srcoffset",
      optargs_s.bitmask |= GUESTFS_COPY_FILE_TO_DEVICE_SRCOFFSET_BITMASK;
      optargs_s.srcoffset = get_int64 (L, -1);
    );
    OPTARG_IF_SET (4, "destoffset",
      optargs_s.bitmask |= GUESTFS_COPY_FILE_TO_DEVICE_DESTOFFSET_BITMASK;
      optargs_s.destoffset = get_int64 (L, -1);
    );
    OPTARG_IF_SET (4, "size",
      optargs_s.bitmask |= GUESTFS_COPY_FILE_TO_DEVICE_SIZE_BITMASK;
      optargs_s.size = get_int64 (L, -1);
    );
  }

  r = guestfs_copy_file_to_device_argv (g, src, dest, optargs);
  if (r == -1)
    return last_error (L, g);

  return 0;
}

static int
guestfs_lua_copy_file_to_file (lua_State *L)
{
  int r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  const char *src;
  const char *dest;
  struct guestfs_copy_file_to_file_argv optargs_s = { .bitmask = 0 };
  struct guestfs_copy_file_to_file_argv *optargs = &optargs_s;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "copy_file_to_file");

  src = luaL_checkstring (L, 2);
  dest = luaL_checkstring (L, 3);

  /* Check for optional arguments, encoded in a table. */
  if (lua_type (L, 4) == LUA_TTABLE) {
    OPTARG_IF_SET (4, "srcoffset",
      optargs_s.bitmask |= GUESTFS_COPY_FILE_TO_FILE_SRCOFFSET_BITMASK;
      optargs_s.srcoffset = get_int64 (L, -1);
    );
    OPTARG_IF_SET (4, "destoffset",
      optargs_s.bitmask |= GUESTFS_COPY_FILE_TO_FILE_DESTOFFSET_BITMASK;
      optargs_s.destoffset = get_int64 (L, -1);
    );
    OPTARG_IF_SET (4, "size",
      optargs_s.bitmask |= GUESTFS_COPY_FILE_TO_FILE_SIZE_BITMASK;
      optargs_s.size = get_int64 (L, -1);
    );
  }

  r = guestfs_copy_file_to_file_argv (g, src, dest, optargs);
  if (r == -1)
    return last_error (L, g);

  return 0;
}

static int
guestfs_lua_copy_size (lua_State *L)
{
  int r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  const char *src;
  const char *dest;
  int64_t size;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "copy_size");

  src = luaL_checkstring (L, 2);
  dest = luaL_checkstring (L, 3);
  size = get_int64 (L, 4);

  r = guestfs_copy_size (g, src, dest, size);
  if (r == -1)
    return last_error (L, g);

  return 0;
}

static int
guestfs_lua_cp (lua_State *L)
{
  int r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  const char *src;
  const char *dest;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "cp");

  src = luaL_checkstring (L, 2);
  dest = luaL_checkstring (L, 3);

  r = guestfs_cp (g, src, dest);
  if (r == -1)
    return last_error (L, g);

  return 0;
}

static int
guestfs_lua_cp_a (lua_State *L)
{
  int r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  const char *src;
  const char *dest;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "cp_a");

  src = luaL_checkstring (L, 2);
  dest = luaL_checkstring (L, 3);

  r = guestfs_cp_a (g, src, dest);
  if (r == -1)
    return last_error (L, g);

  return 0;
}

static int
guestfs_lua_dd (lua_State *L)
{
  int r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  const char *src;
  const char *dest;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "dd");

  src = luaL_checkstring (L, 2);
  dest = luaL_checkstring (L, 3);

  r = guestfs_dd (g, src, dest);
  if (r == -1)
    return last_error (L, g);

  return 0;
}

static int
guestfs_lua_debug (lua_State *L)
{
  char *r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  const char *subcmd;
  char **extraargs;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "debug");

  subcmd = luaL_checkstring (L, 2);
  extraargs = get_string_list (L, 3);

  r = guestfs_debug (g, subcmd, extraargs);
  free (extraargs);
  if (r == NULL)
    return last_error (L, g);

  lua_pushstring (L, r);
  free (r);
  return 1;
}

static int
guestfs_lua_debug_drives (lua_State *L)
{
  char **r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "debug_drives");


  r = guestfs_debug_drives (g);
  if (r == NULL)
    return last_error (L, g);

  push_string_list (L, r);
  guestfs___free_string_list (r);
  return 1;
}

static int
guestfs_lua_debug_upload (lua_State *L)
{
  int r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  const char *filename;
  const char *tmpname;
  int mode;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "debug_upload");

  filename = luaL_checkstring (L, 2);
  tmpname = luaL_checkstring (L, 3);
  mode = luaL_checkint (L, 4);

  r = guestfs_debug_upload (g, filename, tmpname, mode);
  if (r == -1)
    return last_error (L, g);

  return 0;
}

static int
guestfs_lua_device_index (lua_State *L)
{
  int r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  const char *device;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "device_index");

  device = luaL_checkstring (L, 2);

  r = guestfs_device_index (g, device);
  if (r == -1)
    return last_error (L, g);

  lua_pushinteger (L, r);
  return 1;
}

static int
guestfs_lua_df (lua_State *L)
{
  char *r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "df");


  r = guestfs_df (g);
  if (r == NULL)
    return last_error (L, g);

  lua_pushstring (L, r);
  free (r);
  return 1;
}

static int
guestfs_lua_df_h (lua_State *L)
{
  char *r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "df_h");


  r = guestfs_df_h (g);
  if (r == NULL)
    return last_error (L, g);

  lua_pushstring (L, r);
  free (r);
  return 1;
}

static int
guestfs_lua_disk_format (lua_State *L)
{
  char *r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  const char *filename;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "disk_format");

  filename = luaL_checkstring (L, 2);

  r = guestfs_disk_format (g, filename);
  if (r == NULL)
    return last_error (L, g);

  lua_pushstring (L, r);
  free (r);
  return 1;
}

static int
guestfs_lua_disk_has_backing_file (lua_State *L)
{
  int r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  const char *filename;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "disk_has_backing_file");

  filename = luaL_checkstring (L, 2);

  r = guestfs_disk_has_backing_file (g, filename);
  if (r == -1)
    return last_error (L, g);

  lua_pushboolean (L, r);
  return 1;
}

static int
guestfs_lua_disk_virtual_size (lua_State *L)
{
  int64_t r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  const char *filename;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "disk_virtual_size");

  filename = luaL_checkstring (L, 2);

  r = guestfs_disk_virtual_size (g, filename);
  if (r == -1)
    return last_error (L, g);

  push_int64 (L, r);
  return 1;
}

static int
guestfs_lua_dmesg (lua_State *L)
{
  char *r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "dmesg");


  r = guestfs_dmesg (g);
  if (r == NULL)
    return last_error (L, g);

  lua_pushstring (L, r);
  free (r);
  return 1;
}

static int
guestfs_lua_download (lua_State *L)
{
  int r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  const char *remotefilename;
  const char *filename;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "download");

  remotefilename = luaL_checkstring (L, 2);
  filename = luaL_checkstring (L, 3);

  r = guestfs_download (g, remotefilename, filename);
  if (r == -1)
    return last_error (L, g);

  return 0;
}

static int
guestfs_lua_download_offset (lua_State *L)
{
  int r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  const char *remotefilename;
  const char *filename;
  int64_t offset;
  int64_t size;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "download_offset");

  remotefilename = luaL_checkstring (L, 2);
  filename = luaL_checkstring (L, 3);
  offset = get_int64 (L, 4);
  size = get_int64 (L, 5);

  r = guestfs_download_offset (g, remotefilename, filename, offset, size);
  if (r == -1)
    return last_error (L, g);

  return 0;
}

static int
guestfs_lua_drop_caches (lua_State *L)
{
  int r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  int whattodrop;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "drop_caches");

  whattodrop = luaL_checkint (L, 2);

  r = guestfs_drop_caches (g, whattodrop);
  if (r == -1)
    return last_error (L, g);

  return 0;
}

static int
guestfs_lua_du (lua_State *L)
{
  int64_t r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  const char *path;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "du");

  path = luaL_checkstring (L, 2);

  r = guestfs_du (g, path);
  if (r == -1)
    return last_error (L, g);

  push_int64 (L, r);
  return 1;
}

static int
guestfs_lua_e2fsck (lua_State *L)
{
  int r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  const char *device;
  struct guestfs_e2fsck_argv optargs_s = { .bitmask = 0 };
  struct guestfs_e2fsck_argv *optargs = &optargs_s;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "e2fsck");

  device = luaL_checkstring (L, 2);

  /* Check for optional arguments, encoded in a table. */
  if (lua_type (L, 3) == LUA_TTABLE) {
    OPTARG_IF_SET (3, "correct",
      optargs_s.bitmask |= GUESTFS_E2FSCK_CORRECT_BITMASK;
      optargs_s.correct = lua_toboolean (L, -1);
    );
    OPTARG_IF_SET (3, "forceall",
      optargs_s.bitmask |= GUESTFS_E2FSCK_FORCEALL_BITMASK;
      optargs_s.forceall = lua_toboolean (L, -1);
    );
  }

  r = guestfs_e2fsck_argv (g, device, optargs);
  if (r == -1)
    return last_error (L, g);

  return 0;
}

static int
guestfs_lua_e2fsck_f (lua_State *L)
{
  int r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  const char *device;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "e2fsck_f");

  device = luaL_checkstring (L, 2);

  r = guestfs_e2fsck_f (g, device);
  if (r == -1)
    return last_error (L, g);

  return 0;
}

static int
guestfs_lua_echo_daemon (lua_State *L)
{
  char *r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  char **words;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "echo_daemon");

  words = get_string_list (L, 2);

  r = guestfs_echo_daemon (g, words);
  free (words);
  if (r == NULL)
    return last_error (L, g);

  lua_pushstring (L, r);
  free (r);
  return 1;
}

static int
guestfs_lua_egrep (lua_State *L)
{
  char **r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  const char *regex;
  const char *path;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "egrep");

  regex = luaL_checkstring (L, 2);
  path = luaL_checkstring (L, 3);

  r = guestfs_egrep (g, regex, path);
  if (r == NULL)
    return last_error (L, g);

  push_string_list (L, r);
  guestfs___free_string_list (r);
  return 1;
}

static int
guestfs_lua_egrepi (lua_State *L)
{
  char **r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  const char *regex;
  const char *path;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "egrepi");

  regex = luaL_checkstring (L, 2);
  path = luaL_checkstring (L, 3);

  r = guestfs_egrepi (g, regex, path);
  if (r == NULL)
    return last_error (L, g);

  push_string_list (L, r);
  guestfs___free_string_list (r);
  return 1;
}

static int
guestfs_lua_equal (lua_State *L)
{
  int r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  const char *file1;
  const char *file2;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "equal");

  file1 = luaL_checkstring (L, 2);
  file2 = luaL_checkstring (L, 3);

  r = guestfs_equal (g, file1, file2);
  if (r == -1)
    return last_error (L, g);

  lua_pushboolean (L, r);
  return 1;
}

static int
guestfs_lua_exists (lua_State *L)
{
  int r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  const char *path;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "exists");

  path = luaL_checkstring (L, 2);

  r = guestfs_exists (g, path);
  if (r == -1)
    return last_error (L, g);

  lua_pushboolean (L, r);
  return 1;
}

static int
guestfs_lua_fallocate (lua_State *L)
{
  int r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  const char *path;
  int len;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "fallocate");

  path = luaL_checkstring (L, 2);
  len = luaL_checkint (L, 3);

  r = guestfs_fallocate (g, path, len);
  if (r == -1)
    return last_error (L, g);

  return 0;
}

static int
guestfs_lua_fallocate64 (lua_State *L)
{
  int r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  const char *path;
  int64_t len;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "fallocate64");

  path = luaL_checkstring (L, 2);
  len = get_int64 (L, 3);

  r = guestfs_fallocate64 (g, path, len);
  if (r == -1)
    return last_error (L, g);

  return 0;
}

static int
guestfs_lua_fgrep (lua_State *L)
{
  char **r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  const char *pattern;
  const char *path;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "fgrep");

  pattern = luaL_checkstring (L, 2);
  path = luaL_checkstring (L, 3);

  r = guestfs_fgrep (g, pattern, path);
  if (r == NULL)
    return last_error (L, g);

  push_string_list (L, r);
  guestfs___free_string_list (r);
  return 1;
}

static int
guestfs_lua_fgrepi (lua_State *L)
{
  char **r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  const char *pattern;
  const char *path;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "fgrepi");

  pattern = luaL_checkstring (L, 2);
  path = luaL_checkstring (L, 3);

  r = guestfs_fgrepi (g, pattern, path);
  if (r == NULL)
    return last_error (L, g);

  push_string_list (L, r);
  guestfs___free_string_list (r);
  return 1;
}

static int
guestfs_lua_file (lua_State *L)
{
  char *r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  const char *path;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "file");

  path = luaL_checkstring (L, 2);

  r = guestfs_file (g, path);
  if (r == NULL)
    return last_error (L, g);

  lua_pushstring (L, r);
  free (r);
  return 1;
}

static int
guestfs_lua_file_architecture (lua_State *L)
{
  char *r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  const char *filename;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "file_architecture");

  filename = luaL_checkstring (L, 2);

  r = guestfs_file_architecture (g, filename);
  if (r == NULL)
    return last_error (L, g);

  lua_pushstring (L, r);
  free (r);
  return 1;
}

static int
guestfs_lua_filesize (lua_State *L)
{
  int64_t r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  const char *file;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "filesize");

  file = luaL_checkstring (L, 2);

  r = guestfs_filesize (g, file);
  if (r == -1)
    return last_error (L, g);

  push_int64 (L, r);
  return 1;
}

static int
guestfs_lua_filesystem_available (lua_State *L)
{
  int r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  const char *filesystem;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "filesystem_available");

  filesystem = luaL_checkstring (L, 2);

  r = guestfs_filesystem_available (g, filesystem);
  if (r == -1)
    return last_error (L, g);

  lua_pushboolean (L, r);
  return 1;
}

static int
guestfs_lua_fill (lua_State *L)
{
  int r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  int c;
  int len;
  const char *path;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "fill");

  c = luaL_checkint (L, 2);
  len = luaL_checkint (L, 3);
  path = luaL_checkstring (L, 4);

  r = guestfs_fill (g, c, len, path);
  if (r == -1)
    return last_error (L, g);

  return 0;
}

static int
guestfs_lua_fill_dir (lua_State *L)
{
  int r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  const char *dir;
  int nr;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "fill_dir");

  dir = luaL_checkstring (L, 2);
  nr = luaL_checkint (L, 3);

  r = guestfs_fill_dir (g, dir, nr);
  if (r == -1)
    return last_error (L, g);

  return 0;
}

static int
guestfs_lua_fill_pattern (lua_State *L)
{
  int r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  const char *pattern;
  int len;
  const char *path;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "fill_pattern");

  pattern = luaL_checkstring (L, 2);
  len = luaL_checkint (L, 3);
  path = luaL_checkstring (L, 4);

  r = guestfs_fill_pattern (g, pattern, len, path);
  if (r == -1)
    return last_error (L, g);

  return 0;
}

static int
guestfs_lua_find (lua_State *L)
{
  char **r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  const char *directory;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "find");

  directory = luaL_checkstring (L, 2);

  r = guestfs_find (g, directory);
  if (r == NULL)
    return last_error (L, g);

  push_string_list (L, r);
  guestfs___free_string_list (r);
  return 1;
}

static int
guestfs_lua_find0 (lua_State *L)
{
  int r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  const char *directory;
  const char *files;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "find0");

  directory = luaL_checkstring (L, 2);
  files = luaL_checkstring (L, 3);

  r = guestfs_find0 (g, directory, files);
  if (r == -1)
    return last_error (L, g);

  return 0;
}

static int
guestfs_lua_findfs_label (lua_State *L)
{
  char *r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  const char *label;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "findfs_label");

  label = luaL_checkstring (L, 2);

  r = guestfs_findfs_label (g, label);
  if (r == NULL)
    return last_error (L, g);

  lua_pushstring (L, r);
  free (r);
  return 1;
}

static int
guestfs_lua_findfs_uuid (lua_State *L)
{
  char *r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  const char *uuid;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "findfs_uuid");

  uuid = luaL_checkstring (L, 2);

  r = guestfs_findfs_uuid (g, uuid);
  if (r == NULL)
    return last_error (L, g);

  lua_pushstring (L, r);
  free (r);
  return 1;
}

static int
guestfs_lua_fsck (lua_State *L)
{
  int r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  const char *fstype;
  const char *device;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "fsck");

  fstype = luaL_checkstring (L, 2);
  device = luaL_checkstring (L, 3);

  r = guestfs_fsck (g, fstype, device);
  if (r == -1)
    return last_error (L, g);

  lua_pushinteger (L, r);
  return 1;
}

static int
guestfs_lua_fstrim (lua_State *L)
{
  int r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  const char *mountpoint;
  struct guestfs_fstrim_argv optargs_s = { .bitmask = 0 };
  struct guestfs_fstrim_argv *optargs = &optargs_s;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "fstrim");

  mountpoint = luaL_checkstring (L, 2);

  /* Check for optional arguments, encoded in a table. */
  if (lua_type (L, 3) == LUA_TTABLE) {
    OPTARG_IF_SET (3, "offset",
      optargs_s.bitmask |= GUESTFS_FSTRIM_OFFSET_BITMASK;
      optargs_s.offset = get_int64 (L, -1);
    );
    OPTARG_IF_SET (3, "length",
      optargs_s.bitmask |= GUESTFS_FSTRIM_LENGTH_BITMASK;
      optargs_s.length = get_int64 (L, -1);
    );
    OPTARG_IF_SET (3, "minimumfreeextent",
      optargs_s.bitmask |= GUESTFS_FSTRIM_MINIMUMFREEEXTENT_BITMASK;
      optargs_s.minimumfreeextent = get_int64 (L, -1);
    );
  }

  r = guestfs_fstrim_argv (g, mountpoint, optargs);
  if (r == -1)
    return last_error (L, g);

  return 0;
}

static int
guestfs_lua_get_append (lua_State *L)
{
  const char *r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "get_append");


  r = guestfs_get_append (g);
  lua_pushstring (L, r);
  return 1;
}

static int
guestfs_lua_get_attach_method (lua_State *L)
{
  char *r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "get_attach_method");


  r = guestfs_get_attach_method (g);
  if (r == NULL)
    return last_error (L, g);

  lua_pushstring (L, r);
  free (r);
  return 1;
}

static int
guestfs_lua_get_autosync (lua_State *L)
{
  int r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "get_autosync");


  r = guestfs_get_autosync (g);
  if (r == -1)
    return last_error (L, g);

  lua_pushboolean (L, r);
  return 1;
}

static int
guestfs_lua_get_cachedir (lua_State *L)
{
  char *r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "get_cachedir");


  r = guestfs_get_cachedir (g);
  if (r == NULL)
    return last_error (L, g);

  lua_pushstring (L, r);
  free (r);
  return 1;
}

static int
guestfs_lua_get_direct (lua_State *L)
{
  int r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "get_direct");


  r = guestfs_get_direct (g);
  if (r == -1)
    return last_error (L, g);

  lua_pushboolean (L, r);
  return 1;
}

static int
guestfs_lua_get_e2attrs (lua_State *L)
{
  char *r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  const char *file;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "get_e2attrs");

  file = luaL_checkstring (L, 2);

  r = guestfs_get_e2attrs (g, file);
  if (r == NULL)
    return last_error (L, g);

  lua_pushstring (L, r);
  free (r);
  return 1;
}

static int
guestfs_lua_get_e2generation (lua_State *L)
{
  int64_t r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  const char *file;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "get_e2generation");

  file = luaL_checkstring (L, 2);

  r = guestfs_get_e2generation (g, file);
  if (r == -1)
    return last_error (L, g);

  push_int64 (L, r);
  return 1;
}

static int
guestfs_lua_get_e2label (lua_State *L)
{
  char *r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  const char *device;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "get_e2label");

  device = luaL_checkstring (L, 2);

  r = guestfs_get_e2label (g, device);
  if (r == NULL)
    return last_error (L, g);

  lua_pushstring (L, r);
  free (r);
  return 1;
}

static int
guestfs_lua_get_e2uuid (lua_State *L)
{
  char *r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  const char *device;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "get_e2uuid");

  device = luaL_checkstring (L, 2);

  r = guestfs_get_e2uuid (g, device);
  if (r == NULL)
    return last_error (L, g);

  lua_pushstring (L, r);
  free (r);
  return 1;
}

static int
guestfs_lua_get_libvirt_requested_credential_challenge (lua_State *L)
{
  char *r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  int index;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "get_libvirt_requested_credential_challenge");

  index = luaL_checkint (L, 2);

  r = guestfs_get_libvirt_requested_credential_challenge (g, index);
  if (r == NULL)
    return last_error (L, g);

  lua_pushstring (L, r);
  free (r);
  return 1;
}

static int
guestfs_lua_get_libvirt_requested_credential_defresult (lua_State *L)
{
  char *r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  int index;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "get_libvirt_requested_credential_defresult");

  index = luaL_checkint (L, 2);

  r = guestfs_get_libvirt_requested_credential_defresult (g, index);
  if (r == NULL)
    return last_error (L, g);

  lua_pushstring (L, r);
  free (r);
  return 1;
}

static int
guestfs_lua_get_libvirt_requested_credential_prompt (lua_State *L)
{
  char *r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  int index;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "get_libvirt_requested_credential_prompt");

  index = luaL_checkint (L, 2);

  r = guestfs_get_libvirt_requested_credential_prompt (g, index);
  if (r == NULL)
    return last_error (L, g);

  lua_pushstring (L, r);
  free (r);
  return 1;
}

static int
guestfs_lua_get_libvirt_requested_credentials (lua_State *L)
{
  char **r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "get_libvirt_requested_credentials");


  r = guestfs_get_libvirt_requested_credentials (g);
  if (r == NULL)
    return last_error (L, g);

  push_string_list (L, r);
  guestfs___free_string_list (r);
  return 1;
}

static int
guestfs_lua_get_memsize (lua_State *L)
{
  int r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "get_memsize");


  r = guestfs_get_memsize (g);
  if (r == -1)
    return last_error (L, g);

  lua_pushinteger (L, r);
  return 1;
}

static int
guestfs_lua_get_network (lua_State *L)
{
  int r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "get_network");


  r = guestfs_get_network (g);
  if (r == -1)
    return last_error (L, g);

  lua_pushboolean (L, r);
  return 1;
}

static int
guestfs_lua_get_path (lua_State *L)
{
  const char *r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "get_path");


  r = guestfs_get_path (g);
  if (r == NULL)
    return last_error (L, g);

  lua_pushstring (L, r);
  return 1;
}

static int
guestfs_lua_get_pgroup (lua_State *L)
{
  int r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "get_pgroup");


  r = guestfs_get_pgroup (g);
  if (r == -1)
    return last_error (L, g);

  lua_pushboolean (L, r);
  return 1;
}

static int
guestfs_lua_get_pid (lua_State *L)
{
  int r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "get_pid");


  r = guestfs_get_pid (g);
  if (r == -1)
    return last_error (L, g);

  lua_pushinteger (L, r);
  return 1;
}

static int
guestfs_lua_get_qemu (lua_State *L)
{
  const char *r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "get_qemu");


  r = guestfs_get_qemu (g);
  if (r == NULL)
    return last_error (L, g);

  lua_pushstring (L, r);
  return 1;
}

static int
guestfs_lua_get_recovery_proc (lua_State *L)
{
  int r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "get_recovery_proc");


  r = guestfs_get_recovery_proc (g);
  if (r == -1)
    return last_error (L, g);

  lua_pushboolean (L, r);
  return 1;
}

static int
guestfs_lua_get_selinux (lua_State *L)
{
  int r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "get_selinux");


  r = guestfs_get_selinux (g);
  if (r == -1)
    return last_error (L, g);

  lua_pushboolean (L, r);
  return 1;
}

static int
guestfs_lua_get_smp (lua_State *L)
{
  int r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "get_smp");


  r = guestfs_get_smp (g);
  if (r == -1)
    return last_error (L, g);

  lua_pushinteger (L, r);
  return 1;
}

static int
guestfs_lua_get_state (lua_State *L)
{
  int r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "get_state");


  r = guestfs_get_state (g);
  if (r == -1)
    return last_error (L, g);

  lua_pushinteger (L, r);
  return 1;
}

static int
guestfs_lua_get_tmpdir (lua_State *L)
{
  char *r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "get_tmpdir");


  r = guestfs_get_tmpdir (g);
  if (r == NULL)
    return last_error (L, g);

  lua_pushstring (L, r);
  free (r);
  return 1;
}

static int
guestfs_lua_get_trace (lua_State *L)
{
  int r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "get_trace");


  r = guestfs_get_trace (g);
  if (r == -1)
    return last_error (L, g);

  lua_pushboolean (L, r);
  return 1;
}

static int
guestfs_lua_get_umask (lua_State *L)
{
  int r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "get_umask");


  r = guestfs_get_umask (g);
  if (r == -1)
    return last_error (L, g);

  lua_pushinteger (L, r);
  return 1;
}

static int
guestfs_lua_get_verbose (lua_State *L)
{
  int r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "get_verbose");


  r = guestfs_get_verbose (g);
  if (r == -1)
    return last_error (L, g);

  lua_pushboolean (L, r);
  return 1;
}

static int
guestfs_lua_getcon (lua_State *L)
{
  char *r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "getcon");


  r = guestfs_getcon (g);
  if (r == NULL)
    return last_error (L, g);

  lua_pushstring (L, r);
  free (r);
  return 1;
}

static int
guestfs_lua_getxattr (lua_State *L)
{
  char *r;
  size_t size;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  const char *path;
  const char *name;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "getxattr");

  path = luaL_checkstring (L, 2);
  name = luaL_checkstring (L, 3);

  r = guestfs_getxattr (g, path, name, &size);
  if (r == NULL)
    return last_error (L, g);

  lua_pushlstring (L, r, size);
  free (r);
  return 1;
}

static int
guestfs_lua_getxattrs (lua_State *L)
{
  struct guestfs_xattr_list *r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  const char *path;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "getxattrs");

  path = luaL_checkstring (L, 2);

  r = guestfs_getxattrs (g, path);
  if (r == NULL)
    return last_error (L, g);

  push_xattr_list (L, r);
  guestfs_free_xattr_list (r);
  return 1;
}

static int
guestfs_lua_glob_expand (lua_State *L)
{
  char **r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  const char *pattern;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "glob_expand");

  pattern = luaL_checkstring (L, 2);

  r = guestfs_glob_expand (g, pattern);
  if (r == NULL)
    return last_error (L, g);

  push_string_list (L, r);
  guestfs___free_string_list (r);
  return 1;
}

static int
guestfs_lua_grep (lua_State *L)
{
  char **r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  const char *regex;
  const char *path;
  struct guestfs_grep_opts_argv optargs_s = { .bitmask = 0 };
  struct guestfs_grep_opts_argv *optargs = &optargs_s;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "grep");

  regex = luaL_checkstring (L, 2);
  path = luaL_checkstring (L, 3);

  /* Check for optional arguments, encoded in a table. */
  if (lua_type (L, 4) == LUA_TTABLE) {
    OPTARG_IF_SET (4, "extended",
      optargs_s.bitmask |= GUESTFS_GREP_OPTS_EXTENDED_BITMASK;
      optargs_s.extended = lua_toboolean (L, -1);
    );
    OPTARG_IF_SET (4, "fixed",
      optargs_s.bitmask |= GUESTFS_GREP_OPTS_FIXED_BITMASK;
      optargs_s.fixed = lua_toboolean (L, -1);
    );
    OPTARG_IF_SET (4, "insensitive",
      optargs_s.bitmask |= GUESTFS_GREP_OPTS_INSENSITIVE_BITMASK;
      optargs_s.insensitive = lua_toboolean (L, -1);
    );
    OPTARG_IF_SET (4, "compressed",
      optargs_s.bitmask |= GUESTFS_GREP_OPTS_COMPRESSED_BITMASK;
      optargs_s.compressed = lua_toboolean (L, -1);
    );
  }

  r = guestfs_grep_opts_argv (g, regex, path, optargs);
  if (r == NULL)
    return last_error (L, g);

  push_string_list (L, r);
  guestfs___free_string_list (r);
  return 1;
}

static int
guestfs_lua_grepi (lua_State *L)
{
  char **r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  const char *regex;
  const char *path;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "grepi");

  regex = luaL_checkstring (L, 2);
  path = luaL_checkstring (L, 3);

  r = guestfs_grepi (g, regex, path);
  if (r == NULL)
    return last_error (L, g);

  push_string_list (L, r);
  guestfs___free_string_list (r);
  return 1;
}

static int
guestfs_lua_grub_install (lua_State *L)
{
  int r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  const char *root;
  const char *device;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "grub_install");

  root = luaL_checkstring (L, 2);
  device = luaL_checkstring (L, 3);

  r = guestfs_grub_install (g, root, device);
  if (r == -1)
    return last_error (L, g);

  return 0;
}

static int
guestfs_lua_head (lua_State *L)
{
  char **r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  const char *path;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "head");

  path = luaL_checkstring (L, 2);

  r = guestfs_head (g, path);
  if (r == NULL)
    return last_error (L, g);

  push_string_list (L, r);
  guestfs___free_string_list (r);
  return 1;
}

static int
guestfs_lua_head_n (lua_State *L)
{
  char **r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  int nrlines;
  const char *path;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "head_n");

  nrlines = luaL_checkint (L, 2);
  path = luaL_checkstring (L, 3);

  r = guestfs_head_n (g, nrlines, path);
  if (r == NULL)
    return last_error (L, g);

  push_string_list (L, r);
  guestfs___free_string_list (r);
  return 1;
}

static int
guestfs_lua_hexdump (lua_State *L)
{
  char *r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  const char *path;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "hexdump");

  path = luaL_checkstring (L, 2);

  r = guestfs_hexdump (g, path);
  if (r == NULL)
    return last_error (L, g);

  lua_pushstring (L, r);
  free (r);
  return 1;
}

static int
guestfs_lua_hivex_close (lua_State *L)
{
  int r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "hivex_close");


  r = guestfs_hivex_close (g);
  if (r == -1)
    return last_error (L, g);

  return 0;
}

static int
guestfs_lua_hivex_commit (lua_State *L)
{
  int r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  const char *filename;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "hivex_commit");

  filename = luaL_optstring (L, 2, NULL);

  r = guestfs_hivex_commit (g, filename);
  if (r == -1)
    return last_error (L, g);

  return 0;
}

static int
guestfs_lua_hivex_node_add_child (lua_State *L)
{
  int64_t r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  int64_t parent;
  const char *name;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "hivex_node_add_child");

  parent = get_int64 (L, 2);
  name = luaL_checkstring (L, 3);

  r = guestfs_hivex_node_add_child (g, parent, name);
  if (r == -1)
    return last_error (L, g);

  push_int64 (L, r);
  return 1;
}

static int
guestfs_lua_hivex_node_children (lua_State *L)
{
  struct guestfs_hivex_node_list *r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  int64_t nodeh;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "hivex_node_children");

  nodeh = get_int64 (L, 2);

  r = guestfs_hivex_node_children (g, nodeh);
  if (r == NULL)
    return last_error (L, g);

  push_hivex_node_list (L, r);
  guestfs_free_hivex_node_list (r);
  return 1;
}

static int
guestfs_lua_hivex_node_delete_child (lua_State *L)
{
  int r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  int64_t nodeh;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "hivex_node_delete_child");

  nodeh = get_int64 (L, 2);

  r = guestfs_hivex_node_delete_child (g, nodeh);
  if (r == -1)
    return last_error (L, g);

  return 0;
}

static int
guestfs_lua_hivex_node_get_child (lua_State *L)
{
  int64_t r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  int64_t nodeh;
  const char *name;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "hivex_node_get_child");

  nodeh = get_int64 (L, 2);
  name = luaL_checkstring (L, 3);

  r = guestfs_hivex_node_get_child (g, nodeh, name);
  if (r == -1)
    return last_error (L, g);

  push_int64 (L, r);
  return 1;
}

static int
guestfs_lua_hivex_node_get_value (lua_State *L)
{
  int64_t r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  int64_t nodeh;
  const char *key;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "hivex_node_get_value");

  nodeh = get_int64 (L, 2);
  key = luaL_checkstring (L, 3);

  r = guestfs_hivex_node_get_value (g, nodeh, key);
  if (r == -1)
    return last_error (L, g);

  push_int64 (L, r);
  return 1;
}

static int
guestfs_lua_hivex_node_name (lua_State *L)
{
  char *r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  int64_t nodeh;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "hivex_node_name");

  nodeh = get_int64 (L, 2);

  r = guestfs_hivex_node_name (g, nodeh);
  if (r == NULL)
    return last_error (L, g);

  lua_pushstring (L, r);
  free (r);
  return 1;
}

static int
guestfs_lua_hivex_node_parent (lua_State *L)
{
  int64_t r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  int64_t nodeh;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "hivex_node_parent");

  nodeh = get_int64 (L, 2);

  r = guestfs_hivex_node_parent (g, nodeh);
  if (r == -1)
    return last_error (L, g);

  push_int64 (L, r);
  return 1;
}

static int
guestfs_lua_hivex_node_set_value (lua_State *L)
{
  int r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  int64_t nodeh;
  const char *key;
  int64_t t;
  const char *val;
  size_t val_size;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "hivex_node_set_value");

  nodeh = get_int64 (L, 2);
  key = luaL_checkstring (L, 3);
  t = get_int64 (L, 4);
  val = luaL_checklstring (L, 5, &val_size);

  r = guestfs_hivex_node_set_value (g, nodeh, key, t, val, val_size);
  if (r == -1)
    return last_error (L, g);

  return 0;
}

static int
guestfs_lua_hivex_node_values (lua_State *L)
{
  struct guestfs_hivex_value_list *r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  int64_t nodeh;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "hivex_node_values");

  nodeh = get_int64 (L, 2);

  r = guestfs_hivex_node_values (g, nodeh);
  if (r == NULL)
    return last_error (L, g);

  push_hivex_value_list (L, r);
  guestfs_free_hivex_value_list (r);
  return 1;
}

static int
guestfs_lua_hivex_open (lua_State *L)
{
  int r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  const char *filename;
  struct guestfs_hivex_open_argv optargs_s = { .bitmask = 0 };
  struct guestfs_hivex_open_argv *optargs = &optargs_s;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "hivex_open");

  filename = luaL_checkstring (L, 2);

  /* Check for optional arguments, encoded in a table. */
  if (lua_type (L, 3) == LUA_TTABLE) {
    OPTARG_IF_SET (3, "verbose",
      optargs_s.bitmask |= GUESTFS_HIVEX_OPEN_VERBOSE_BITMASK;
      optargs_s.verbose = lua_toboolean (L, -1);
    );
    OPTARG_IF_SET (3, "debug",
      optargs_s.bitmask |= GUESTFS_HIVEX_OPEN_DEBUG_BITMASK;
      optargs_s.debug = lua_toboolean (L, -1);
    );
    OPTARG_IF_SET (3, "write",
      optargs_s.bitmask |= GUESTFS_HIVEX_OPEN_WRITE_BITMASK;
      optargs_s.write = lua_toboolean (L, -1);
    );
  }

  r = guestfs_hivex_open_argv (g, filename, optargs);
  if (r == -1)
    return last_error (L, g);

  return 0;
}

static int
guestfs_lua_hivex_root (lua_State *L)
{
  int64_t r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "hivex_root");


  r = guestfs_hivex_root (g);
  if (r == -1)
    return last_error (L, g);

  push_int64 (L, r);
  return 1;
}

static int
guestfs_lua_hivex_value_key (lua_State *L)
{
  char *r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  int64_t valueh;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "hivex_value_key");

  valueh = get_int64 (L, 2);

  r = guestfs_hivex_value_key (g, valueh);
  if (r == NULL)
    return last_error (L, g);

  lua_pushstring (L, r);
  free (r);
  return 1;
}

static int
guestfs_lua_hivex_value_type (lua_State *L)
{
  int64_t r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  int64_t valueh;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "hivex_value_type");

  valueh = get_int64 (L, 2);

  r = guestfs_hivex_value_type (g, valueh);
  if (r == -1)
    return last_error (L, g);

  push_int64 (L, r);
  return 1;
}

static int
guestfs_lua_hivex_value_utf8 (lua_State *L)
{
  char *r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  int64_t valueh;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "hivex_value_utf8");

  valueh = get_int64 (L, 2);

  r = guestfs_hivex_value_utf8 (g, valueh);
  if (r == NULL)
    return last_error (L, g);

  lua_pushstring (L, r);
  free (r);
  return 1;
}

static int
guestfs_lua_hivex_value_value (lua_State *L)
{
  char *r;
  size_t size;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  int64_t valueh;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "hivex_value_value");

  valueh = get_int64 (L, 2);

  r = guestfs_hivex_value_value (g, valueh, &size);
  if (r == NULL)
    return last_error (L, g);

  lua_pushlstring (L, r, size);
  free (r);
  return 1;
}

static int
guestfs_lua_initrd_cat (lua_State *L)
{
  char *r;
  size_t size;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  const char *initrdpath;
  const char *filename;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "initrd_cat");

  initrdpath = luaL_checkstring (L, 2);
  filename = luaL_checkstring (L, 3);

  r = guestfs_initrd_cat (g, initrdpath, filename, &size);
  if (r == NULL)
    return last_error (L, g);

  lua_pushlstring (L, r, size);
  free (r);
  return 1;
}

static int
guestfs_lua_initrd_list (lua_State *L)
{
  char **r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  const char *path;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "initrd_list");

  path = luaL_checkstring (L, 2);

  r = guestfs_initrd_list (g, path);
  if (r == NULL)
    return last_error (L, g);

  push_string_list (L, r);
  guestfs___free_string_list (r);
  return 1;
}

static int
guestfs_lua_inotify_add_watch (lua_State *L)
{
  int64_t r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  const char *path;
  int mask;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "inotify_add_watch");

  path = luaL_checkstring (L, 2);
  mask = luaL_checkint (L, 3);

  r = guestfs_inotify_add_watch (g, path, mask);
  if (r == -1)
    return last_error (L, g);

  push_int64 (L, r);
  return 1;
}

static int
guestfs_lua_inotify_close (lua_State *L)
{
  int r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "inotify_close");


  r = guestfs_inotify_close (g);
  if (r == -1)
    return last_error (L, g);

  return 0;
}

static int
guestfs_lua_inotify_files (lua_State *L)
{
  char **r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "inotify_files");


  r = guestfs_inotify_files (g);
  if (r == NULL)
    return last_error (L, g);

  push_string_list (L, r);
  guestfs___free_string_list (r);
  return 1;
}

static int
guestfs_lua_inotify_init (lua_State *L)
{
  int r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  int maxevents;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "inotify_init");

  maxevents = luaL_checkint (L, 2);

  r = guestfs_inotify_init (g, maxevents);
  if (r == -1)
    return last_error (L, g);

  return 0;
}

static int
guestfs_lua_inotify_read (lua_State *L)
{
  struct guestfs_inotify_event_list *r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "inotify_read");


  r = guestfs_inotify_read (g);
  if (r == NULL)
    return last_error (L, g);

  push_inotify_event_list (L, r);
  guestfs_free_inotify_event_list (r);
  return 1;
}

static int
guestfs_lua_inotify_rm_watch (lua_State *L)
{
  int r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  int wd;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "inotify_rm_watch");

  wd = luaL_checkint (L, 2);

  r = guestfs_inotify_rm_watch (g, wd);
  if (r == -1)
    return last_error (L, g);

  return 0;
}

static int
guestfs_lua_inspect_get_arch (lua_State *L)
{
  char *r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  const char *root;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "inspect_get_arch");

  root = luaL_checkstring (L, 2);

  r = guestfs_inspect_get_arch (g, root);
  if (r == NULL)
    return last_error (L, g);

  lua_pushstring (L, r);
  free (r);
  return 1;
}

static int
guestfs_lua_inspect_get_distro (lua_State *L)
{
  char *r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  const char *root;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "inspect_get_distro");

  root = luaL_checkstring (L, 2);

  r = guestfs_inspect_get_distro (g, root);
  if (r == NULL)
    return last_error (L, g);

  lua_pushstring (L, r);
  free (r);
  return 1;
}

static int
guestfs_lua_inspect_get_drive_mappings (lua_State *L)
{
  char **r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  const char *root;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "inspect_get_drive_mappings");

  root = luaL_checkstring (L, 2);

  r = guestfs_inspect_get_drive_mappings (g, root);
  if (r == NULL)
    return last_error (L, g);

  push_table (L, r);
  guestfs___free_string_list (r);
  return 1;
}

static int
guestfs_lua_inspect_get_filesystems (lua_State *L)
{
  char **r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  const char *root;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "inspect_get_filesystems");

  root = luaL_checkstring (L, 2);

  r = guestfs_inspect_get_filesystems (g, root);
  if (r == NULL)
    return last_error (L, g);

  push_string_list (L, r);
  guestfs___free_string_list (r);
  return 1;
}

static int
guestfs_lua_inspect_get_format (lua_State *L)
{
  char *r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  const char *root;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "inspect_get_format");

  root = luaL_checkstring (L, 2);

  r = guestfs_inspect_get_format (g, root);
  if (r == NULL)
    return last_error (L, g);

  lua_pushstring (L, r);
  free (r);
  return 1;
}

static int
guestfs_lua_inspect_get_hostname (lua_State *L)
{
  char *r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  const char *root;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "inspect_get_hostname");

  root = luaL_checkstring (L, 2);

  r = guestfs_inspect_get_hostname (g, root);
  if (r == NULL)
    return last_error (L, g);

  lua_pushstring (L, r);
  free (r);
  return 1;
}

static int
guestfs_lua_inspect_get_icon (lua_State *L)
{
  char *r;
  size_t size;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  const char *root;
  struct guestfs_inspect_get_icon_argv optargs_s = { .bitmask = 0 };
  struct guestfs_inspect_get_icon_argv *optargs = &optargs_s;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "inspect_get_icon");

  root = luaL_checkstring (L, 2);

  /* Check for optional arguments, encoded in a table. */
  if (lua_type (L, 3) == LUA_TTABLE) {
    OPTARG_IF_SET (3, "favicon",
      optargs_s.bitmask |= GUESTFS_INSPECT_GET_ICON_FAVICON_BITMASK;
      optargs_s.favicon = lua_toboolean (L, -1);
    );
    OPTARG_IF_SET (3, "highquality",
      optargs_s.bitmask |= GUESTFS_INSPECT_GET_ICON_HIGHQUALITY_BITMASK;
      optargs_s.highquality = lua_toboolean (L, -1);
    );
  }

  r = guestfs_inspect_get_icon_argv (g, root, &size, optargs);
  if (r == NULL)
    return last_error (L, g);

  lua_pushlstring (L, r, size);
  free (r);
  return 1;
}

static int
guestfs_lua_inspect_get_major_version (lua_State *L)
{
  int r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  const char *root;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "inspect_get_major_version");

  root = luaL_checkstring (L, 2);

  r = guestfs_inspect_get_major_version (g, root);
  if (r == -1)
    return last_error (L, g);

  lua_pushinteger (L, r);
  return 1;
}

static int
guestfs_lua_inspect_get_minor_version (lua_State *L)
{
  int r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  const char *root;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "inspect_get_minor_version");

  root = luaL_checkstring (L, 2);

  r = guestfs_inspect_get_minor_version (g, root);
  if (r == -1)
    return last_error (L, g);

  lua_pushinteger (L, r);
  return 1;
}

static int
guestfs_lua_inspect_get_mountpoints (lua_State *L)
{
  char **r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  const char *root;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "inspect_get_mountpoints");

  root = luaL_checkstring (L, 2);

  r = guestfs_inspect_get_mountpoints (g, root);
  if (r == NULL)
    return last_error (L, g);

  push_table (L, r);
  guestfs___free_string_list (r);
  return 1;
}

static int
guestfs_lua_inspect_get_package_format (lua_State *L)
{
  char *r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  const char *root;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "inspect_get_package_format");

  root = luaL_checkstring (L, 2);

  r = guestfs_inspect_get_package_format (g, root);
  if (r == NULL)
    return last_error (L, g);

  lua_pushstring (L, r);
  free (r);
  return 1;
}

static int
guestfs_lua_inspect_get_package_management (lua_State *L)
{
  char *r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  const char *root;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "inspect_get_package_management");

  root = luaL_checkstring (L, 2);

  r = guestfs_inspect_get_package_management (g, root);
  if (r == NULL)
    return last_error (L, g);

  lua_pushstring (L, r);
  free (r);
  return 1;
}

static int
guestfs_lua_inspect_get_product_name (lua_State *L)
{
  char *r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  const char *root;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "inspect_get_product_name");

  root = luaL_checkstring (L, 2);

  r = guestfs_inspect_get_product_name (g, root);
  if (r == NULL)
    return last_error (L, g);

  lua_pushstring (L, r);
  free (r);
  return 1;
}

static int
guestfs_lua_inspect_get_product_variant (lua_State *L)
{
  char *r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  const char *root;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "inspect_get_product_variant");

  root = luaL_checkstring (L, 2);

  r = guestfs_inspect_get_product_variant (g, root);
  if (r == NULL)
    return last_error (L, g);

  lua_pushstring (L, r);
  free (r);
  return 1;
}

static int
guestfs_lua_inspect_get_roots (lua_State *L)
{
  char **r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "inspect_get_roots");


  r = guestfs_inspect_get_roots (g);
  if (r == NULL)
    return last_error (L, g);

  push_string_list (L, r);
  guestfs___free_string_list (r);
  return 1;
}

static int
guestfs_lua_inspect_get_type (lua_State *L)
{
  char *r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  const char *root;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "inspect_get_type");

  root = luaL_checkstring (L, 2);

  r = guestfs_inspect_get_type (g, root);
  if (r == NULL)
    return last_error (L, g);

  lua_pushstring (L, r);
  free (r);
  return 1;
}

static int
guestfs_lua_inspect_get_windows_current_control_set (lua_State *L)
{
  char *r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  const char *root;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "inspect_get_windows_current_control_set");

  root = luaL_checkstring (L, 2);

  r = guestfs_inspect_get_windows_current_control_set (g, root);
  if (r == NULL)
    return last_error (L, g);

  lua_pushstring (L, r);
  free (r);
  return 1;
}

static int
guestfs_lua_inspect_get_windows_systemroot (lua_State *L)
{
  char *r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  const char *root;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "inspect_get_windows_systemroot");

  root = luaL_checkstring (L, 2);

  r = guestfs_inspect_get_windows_systemroot (g, root);
  if (r == NULL)
    return last_error (L, g);

  lua_pushstring (L, r);
  free (r);
  return 1;
}

static int
guestfs_lua_inspect_is_live (lua_State *L)
{
  int r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  const char *root;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "inspect_is_live");

  root = luaL_checkstring (L, 2);

  r = guestfs_inspect_is_live (g, root);
  if (r == -1)
    return last_error (L, g);

  lua_pushboolean (L, r);
  return 1;
}

static int
guestfs_lua_inspect_is_multipart (lua_State *L)
{
  int r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  const char *root;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "inspect_is_multipart");

  root = luaL_checkstring (L, 2);

  r = guestfs_inspect_is_multipart (g, root);
  if (r == -1)
    return last_error (L, g);

  lua_pushboolean (L, r);
  return 1;
}

static int
guestfs_lua_inspect_is_netinst (lua_State *L)
{
  int r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  const char *root;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "inspect_is_netinst");

  root = luaL_checkstring (L, 2);

  r = guestfs_inspect_is_netinst (g, root);
  if (r == -1)
    return last_error (L, g);

  lua_pushboolean (L, r);
  return 1;
}

static int
guestfs_lua_inspect_list_applications (lua_State *L)
{
  struct guestfs_application_list *r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  const char *root;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "inspect_list_applications");

  root = luaL_checkstring (L, 2);

  r = guestfs_inspect_list_applications (g, root);
  if (r == NULL)
    return last_error (L, g);

  push_application_list (L, r);
  guestfs_free_application_list (r);
  return 1;
}

static int
guestfs_lua_inspect_list_applications2 (lua_State *L)
{
  struct guestfs_application2_list *r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  const char *root;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "inspect_list_applications2");

  root = luaL_checkstring (L, 2);

  r = guestfs_inspect_list_applications2 (g, root);
  if (r == NULL)
    return last_error (L, g);

  push_application2_list (L, r);
  guestfs_free_application2_list (r);
  return 1;
}

static int
guestfs_lua_inspect_os (lua_State *L)
{
  char **r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "inspect_os");


  r = guestfs_inspect_os (g);
  if (r == NULL)
    return last_error (L, g);

  push_string_list (L, r);
  guestfs___free_string_list (r);
  return 1;
}

static int
guestfs_lua_internal_test (lua_State *L)
{
  int r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  const char *str;
  const char *optstr;
  char **strlist;
  int b;
  int integer;
  int64_t integer64;
  const char *filein;
  const char *fileout;
  const char *bufferin;
  size_t bufferin_size;
  struct guestfs_internal_test_argv optargs_s = { .bitmask = 0 };
  struct guestfs_internal_test_argv *optargs = &optargs_s;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "internal_test");

  str = luaL_checkstring (L, 2);
  optstr = luaL_optstring (L, 3, NULL);
  strlist = get_string_list (L, 4);
  b = lua_toboolean (L, 5);
  integer = luaL_checkint (L, 6);
  integer64 = get_int64 (L, 7);
  filein = luaL_checkstring (L, 8);
  fileout = luaL_checkstring (L, 9);
  bufferin = luaL_checklstring (L, 10, &bufferin_size);

  /* Check for optional arguments, encoded in a table. */
  if (lua_type (L, 11) == LUA_TTABLE) {
    OPTARG_IF_SET (11, "obool",
      optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_OBOOL_BITMASK;
      optargs_s.obool = lua_toboolean (L, -1);
    );
    OPTARG_IF_SET (11, "oint",
      optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_OINT_BITMASK;
      optargs_s.oint = luaL_checkint (L, -1);
    );
    OPTARG_IF_SET (11, "oint64",
      optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_OINT64_BITMASK;
      optargs_s.oint64 = get_int64 (L, -1);
    );
    OPTARG_IF_SET (11, "ostring",
      optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_OSTRING_BITMASK;
      optargs_s.ostring = luaL_checkstring (L, -1);
    );
    OPTARG_IF_SET (11, "ostringlist",
      optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_OSTRINGLIST_BITMASK;
      optargs_s.ostringlist = get_string_list (L, -1);
    );
  }

  r = guestfs_internal_test_argv (g, str, optstr, strlist, b, integer, integer64, filein, fileout, bufferin, bufferin_size, optargs);
  free (strlist);
  free ((char *) optargs_s.ostringlist);
  if (r == -1)
    return last_error (L, g);

  return 0;
}

static int
guestfs_lua_internal_test_63_optargs (lua_State *L)
{
  int r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  struct guestfs_internal_test_63_optargs_argv optargs_s = { .bitmask = 0 };
  struct guestfs_internal_test_63_optargs_argv *optargs = &optargs_s;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "internal_test_63_optargs");


  /* Check for optional arguments, encoded in a table. */
  if (lua_type (L, 2) == LUA_TTABLE) {
    OPTARG_IF_SET (2, "opt1",
      optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT1_BITMASK;
      optargs_s.opt1 = luaL_checkint (L, -1);
    );
    OPTARG_IF_SET (2, "opt2",
      optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT2_BITMASK;
      optargs_s.opt2 = luaL_checkint (L, -1);
    );
    OPTARG_IF_SET (2, "opt3",
      optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT3_BITMASK;
      optargs_s.opt3 = luaL_checkint (L, -1);
    );
    OPTARG_IF_SET (2, "opt4",
      optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT4_BITMASK;
      optargs_s.opt4 = luaL_checkint (L, -1);
    );
    OPTARG_IF_SET (2, "opt5",
      optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT5_BITMASK;
      optargs_s.opt5 = luaL_checkint (L, -1);
    );
    OPTARG_IF_SET (2, "opt6",
      optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT6_BITMASK;
      optargs_s.opt6 = luaL_checkint (L, -1);
    );
    OPTARG_IF_SET (2, "opt7",
      optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT7_BITMASK;
      optargs_s.opt7 = luaL_checkint (L, -1);
    );
    OPTARG_IF_SET (2, "opt8",
      optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT8_BITMASK;
      optargs_s.opt8 = luaL_checkint (L, -1);
    );
    OPTARG_IF_SET (2, "opt9",
      optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT9_BITMASK;
      optargs_s.opt9 = luaL_checkint (L, -1);
    );
    OPTARG_IF_SET (2, "opt10",
      optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT10_BITMASK;
      optargs_s.opt10 = luaL_checkint (L, -1);
    );
    OPTARG_IF_SET (2, "opt11",
      optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT11_BITMASK;
      optargs_s.opt11 = luaL_checkint (L, -1);
    );
    OPTARG_IF_SET (2, "opt12",
      optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT12_BITMASK;
      optargs_s.opt12 = luaL_checkint (L, -1);
    );
    OPTARG_IF_SET (2, "opt13",
      optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT13_BITMASK;
      optargs_s.opt13 = luaL_checkint (L, -1);
    );
    OPTARG_IF_SET (2, "opt14",
      optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT14_BITMASK;
      optargs_s.opt14 = luaL_checkint (L, -1);
    );
    OPTARG_IF_SET (2, "opt15",
      optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT15_BITMASK;
      optargs_s.opt15 = luaL_checkint (L, -1);
    );
    OPTARG_IF_SET (2, "opt16",
      optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT16_BITMASK;
      optargs_s.opt16 = luaL_checkint (L, -1);
    );
    OPTARG_IF_SET (2, "opt17",
      optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT17_BITMASK;
      optargs_s.opt17 = luaL_checkint (L, -1);
    );
    OPTARG_IF_SET (2, "opt18",
      optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT18_BITMASK;
      optargs_s.opt18 = luaL_checkint (L, -1);
    );
    OPTARG_IF_SET (2, "opt19",
      optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT19_BITMASK;
      optargs_s.opt19 = luaL_checkint (L, -1);
    );
    OPTARG_IF_SET (2, "opt20",
      optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT20_BITMASK;
      optargs_s.opt20 = luaL_checkint (L, -1);
    );
    OPTARG_IF_SET (2, "opt21",
      optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT21_BITMASK;
      optargs_s.opt21 = luaL_checkint (L, -1);
    );
    OPTARG_IF_SET (2, "opt22",
      optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT22_BITMASK;
      optargs_s.opt22 = luaL_checkint (L, -1);
    );
    OPTARG_IF_SET (2, "opt23",
      optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT23_BITMASK;
      optargs_s.opt23 = luaL_checkint (L, -1);
    );
    OPTARG_IF_SET (2, "opt24",
      optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT24_BITMASK;
      optargs_s.opt24 = luaL_checkint (L, -1);
    );
    OPTARG_IF_SET (2, "opt25",
      optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT25_BITMASK;
      optargs_s.opt25 = luaL_checkint (L, -1);
    );
    OPTARG_IF_SET (2, "opt26",
      optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT26_BITMASK;
      optargs_s.opt26 = luaL_checkint (L, -1);
    );
    OPTARG_IF_SET (2, "opt27",
      optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT27_BITMASK;
      optargs_s.opt27 = luaL_checkint (L, -1);
    );
    OPTARG_IF_SET (2, "opt28",
      optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT28_BITMASK;
      optargs_s.opt28 = luaL_checkint (L, -1);
    );
    OPTARG_IF_SET (2, "opt29",
      optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT29_BITMASK;
      optargs_s.opt29 = luaL_checkint (L, -1);
    );
    OPTARG_IF_SET (2, "opt30",
      optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT30_BITMASK;
      optargs_s.opt30 = luaL_checkint (L, -1);
    );
    OPTARG_IF_SET (2, "opt31",
      optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT31_BITMASK;
      optargs_s.opt31 = luaL_checkint (L, -1);
    );
    OPTARG_IF_SET (2, "opt32",
      optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT32_BITMASK;
      optargs_s.opt32 = luaL_checkint (L, -1);
    );
    OPTARG_IF_SET (2, "opt33",
      optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT33_BITMASK;
      optargs_s.opt33 = luaL_checkint (L, -1);
    );
    OPTARG_IF_SET (2, "opt34",
      optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT34_BITMASK;
      optargs_s.opt34 = luaL_checkint (L, -1);
    );
    OPTARG_IF_SET (2, "opt35",
      optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT35_BITMASK;
      optargs_s.opt35 = luaL_checkint (L, -1);
    );
    OPTARG_IF_SET (2, "opt36",
      optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT36_BITMASK;
      optargs_s.opt36 = luaL_checkint (L, -1);
    );
    OPTARG_IF_SET (2, "opt37",
      optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT37_BITMASK;
      optargs_s.opt37 = luaL_checkint (L, -1);
    );
    OPTARG_IF_SET (2, "opt38",
      optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT38_BITMASK;
      optargs_s.opt38 = luaL_checkint (L, -1);
    );
    OPTARG_IF_SET (2, "opt39",
      optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT39_BITMASK;
      optargs_s.opt39 = luaL_checkint (L, -1);
    );
    OPTARG_IF_SET (2, "opt40",
      optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT40_BITMASK;
      optargs_s.opt40 = luaL_checkint (L, -1);
    );
    OPTARG_IF_SET (2, "opt41",
      optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT41_BITMASK;
      optargs_s.opt41 = luaL_checkint (L, -1);
    );
    OPTARG_IF_SET (2, "opt42",
      optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT42_BITMASK;
      optargs_s.opt42 = luaL_checkint (L, -1);
    );
    OPTARG_IF_SET (2, "opt43",
      optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT43_BITMASK;
      optargs_s.opt43 = luaL_checkint (L, -1);
    );
    OPTARG_IF_SET (2, "opt44",
      optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT44_BITMASK;
      optargs_s.opt44 = luaL_checkint (L, -1);
    );
    OPTARG_IF_SET (2, "opt45",
      optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT45_BITMASK;
      optargs_s.opt45 = luaL_checkint (L, -1);
    );
    OPTARG_IF_SET (2, "opt46",
      optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT46_BITMASK;
      optargs_s.opt46 = luaL_checkint (L, -1);
    );
    OPTARG_IF_SET (2, "opt47",
      optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT47_BITMASK;
      optargs_s.opt47 = luaL_checkint (L, -1);
    );
    OPTARG_IF_SET (2, "opt48",
      optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT48_BITMASK;
      optargs_s.opt48 = luaL_checkint (L, -1);
    );
    OPTARG_IF_SET (2, "opt49",
      optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT49_BITMASK;
      optargs_s.opt49 = luaL_checkint (L, -1);
    );
    OPTARG_IF_SET (2, "opt50",
      optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT50_BITMASK;
      optargs_s.opt50 = luaL_checkint (L, -1);
    );
    OPTARG_IF_SET (2, "opt51",
      optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT51_BITMASK;
      optargs_s.opt51 = luaL_checkint (L, -1);
    );
    OPTARG_IF_SET (2, "opt52",
      optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT52_BITMASK;
      optargs_s.opt52 = luaL_checkint (L, -1);
    );
    OPTARG_IF_SET (2, "opt53",
      optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT53_BITMASK;
      optargs_s.opt53 = luaL_checkint (L, -1);
    );
    OPTARG_IF_SET (2, "opt54",
      optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT54_BITMASK;
      optargs_s.opt54 = luaL_checkint (L, -1);
    );
    OPTARG_IF_SET (2, "opt55",
      optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT55_BITMASK;
      optargs_s.opt55 = luaL_checkint (L, -1);
    );
    OPTARG_IF_SET (2, "opt56",
      optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT56_BITMASK;
      optargs_s.opt56 = luaL_checkint (L, -1);
    );
    OPTARG_IF_SET (2, "opt57",
      optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT57_BITMASK;
      optargs_s.opt57 = luaL_checkint (L, -1);
    );
    OPTARG_IF_SET (2, "opt58",
      optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT58_BITMASK;
      optargs_s.opt58 = luaL_checkint (L, -1);
    );
    OPTARG_IF_SET (2, "opt59",
      optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT59_BITMASK;
      optargs_s.opt59 = luaL_checkint (L, -1);
    );
    OPTARG_IF_SET (2, "opt60",
      optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT60_BITMASK;
      optargs_s.opt60 = luaL_checkint (L, -1);
    );
    OPTARG_IF_SET (2, "opt61",
      optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT61_BITMASK;
      optargs_s.opt61 = luaL_checkint (L, -1);
    );
    OPTARG_IF_SET (2, "opt62",
      optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT62_BITMASK;
      optargs_s.opt62 = luaL_checkint (L, -1);
    );
    OPTARG_IF_SET (2, "opt63",
      optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_63_OPTARGS_OPT63_BITMASK;
      optargs_s.opt63 = luaL_checkint (L, -1);
    );
  }

  r = guestfs_internal_test_63_optargs_argv (g, optargs);
  if (r == -1)
    return last_error (L, g);

  return 0;
}

static int
guestfs_lua_internal_test_close_output (lua_State *L)
{
  int r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "internal_test_close_output");


  r = guestfs_internal_test_close_output (g);
  if (r == -1)
    return last_error (L, g);

  return 0;
}

static int
guestfs_lua_internal_test_only_optargs (lua_State *L)
{
  int r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  struct guestfs_internal_test_only_optargs_argv optargs_s = { .bitmask = 0 };
  struct guestfs_internal_test_only_optargs_argv *optargs = &optargs_s;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "internal_test_only_optargs");


  /* Check for optional arguments, encoded in a table. */
  if (lua_type (L, 2) == LUA_TTABLE) {
    OPTARG_IF_SET (2, "test",
      optargs_s.bitmask |= GUESTFS_INTERNAL_TEST_ONLY_OPTARGS_TEST_BITMASK;
      optargs_s.test = luaL_checkint (L, -1);
    );
  }

  r = guestfs_internal_test_only_optargs_argv (g, optargs);
  if (r == -1)
    return last_error (L, g);

  return 0;
}

static int
guestfs_lua_internal_test_rbool (lua_State *L)
{
  int r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  const char *val;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "internal_test_rbool");

  val = luaL_checkstring (L, 2);

  r = guestfs_internal_test_rbool (g, val);
  if (r == -1)
    return last_error (L, g);

  lua_pushboolean (L, r);
  return 1;
}

static int
guestfs_lua_internal_test_rboolerr (lua_State *L)
{
  int r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "internal_test_rboolerr");


  r = guestfs_internal_test_rboolerr (g);
  if (r == -1)
    return last_error (L, g);

  lua_pushboolean (L, r);
  return 1;
}

static int
guestfs_lua_internal_test_rbufferout (lua_State *L)
{
  char *r;
  size_t size;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  const char *val;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "internal_test_rbufferout");

  val = luaL_checkstring (L, 2);

  r = guestfs_internal_test_rbufferout (g, val, &size);
  if (r == NULL)
    return last_error (L, g);

  lua_pushlstring (L, r, size);
  free (r);
  return 1;
}

static int
guestfs_lua_internal_test_rbufferouterr (lua_State *L)
{
  char *r;
  size_t size;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "internal_test_rbufferouterr");


  r = guestfs_internal_test_rbufferouterr (g, &size);
  if (r == NULL)
    return last_error (L, g);

  lua_pushlstring (L, r, size);
  free (r);
  return 1;
}

static int
guestfs_lua_internal_test_rconstoptstring (lua_State *L)
{
  const char *r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  const char *val;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "internal_test_rconstoptstring");

  val = luaL_checkstring (L, 2);

  r = guestfs_internal_test_rconstoptstring (g, val);
  lua_pushstring (L, r);
  return 1;
}

static int
guestfs_lua_internal_test_rconstoptstringerr (lua_State *L)
{
  const char *r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "internal_test_rconstoptstringerr");


  r = guestfs_internal_test_rconstoptstringerr (g);
  lua_pushstring (L, r);
  return 1;
}

static int
guestfs_lua_internal_test_rconststring (lua_State *L)
{
  const char *r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  const char *val;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "internal_test_rconststring");

  val = luaL_checkstring (L, 2);

  r = guestfs_internal_test_rconststring (g, val);
  if (r == NULL)
    return last_error (L, g);

  lua_pushstring (L, r);
  return 1;
}

static int
guestfs_lua_internal_test_rconststringerr (lua_State *L)
{
  const char *r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "internal_test_rconststringerr");


  r = guestfs_internal_test_rconststringerr (g);
  if (r == NULL)
    return last_error (L, g);

  lua_pushstring (L, r);
  return 1;
}

static int
guestfs_lua_internal_test_rhashtable (lua_State *L)
{
  char **r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  const char *val;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "internal_test_rhashtable");

  val = luaL_checkstring (L, 2);

  r = guestfs_internal_test_rhashtable (g, val);
  if (r == NULL)
    return last_error (L, g);

  push_table (L, r);
  guestfs___free_string_list (r);
  return 1;
}

static int
guestfs_lua_internal_test_rhashtableerr (lua_State *L)
{
  char **r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "internal_test_rhashtableerr");


  r = guestfs_internal_test_rhashtableerr (g);
  if (r == NULL)
    return last_error (L, g);

  push_table (L, r);
  guestfs___free_string_list (r);
  return 1;
}

static int
guestfs_lua_internal_test_rint (lua_State *L)
{
  int r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  const char *val;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "internal_test_rint");

  val = luaL_checkstring (L, 2);

  r = guestfs_internal_test_rint (g, val);
  if (r == -1)
    return last_error (L, g);

  lua_pushinteger (L, r);
  return 1;
}

static int
guestfs_lua_internal_test_rint64 (lua_State *L)
{
  int64_t r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  const char *val;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "internal_test_rint64");

  val = luaL_checkstring (L, 2);

  r = guestfs_internal_test_rint64 (g, val);
  if (r == -1)
    return last_error (L, g);

  push_int64 (L, r);
  return 1;
}

static int
guestfs_lua_internal_test_rint64err (lua_State *L)
{
  int64_t r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "internal_test_rint64err");


  r = guestfs_internal_test_rint64err (g);
  if (r == -1)
    return last_error (L, g);

  push_int64 (L, r);
  return 1;
}

static int
guestfs_lua_internal_test_rinterr (lua_State *L)
{
  int r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "internal_test_rinterr");


  r = guestfs_internal_test_rinterr (g);
  if (r == -1)
    return last_error (L, g);

  lua_pushinteger (L, r);
  return 1;
}

static int
guestfs_lua_internal_test_rstring (lua_State *L)
{
  char *r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  const char *val;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "internal_test_rstring");

  val = luaL_checkstring (L, 2);

  r = guestfs_internal_test_rstring (g, val);
  if (r == NULL)
    return last_error (L, g);

  lua_pushstring (L, r);
  free (r);
  return 1;
}

static int
guestfs_lua_internal_test_rstringerr (lua_State *L)
{
  char *r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "internal_test_rstringerr");


  r = guestfs_internal_test_rstringerr (g);
  if (r == NULL)
    return last_error (L, g);

  lua_pushstring (L, r);
  free (r);
  return 1;
}

static int
guestfs_lua_internal_test_rstringlist (lua_State *L)
{
  char **r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  const char *val;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "internal_test_rstringlist");

  val = luaL_checkstring (L, 2);

  r = guestfs_internal_test_rstringlist (g, val);
  if (r == NULL)
    return last_error (L, g);

  push_string_list (L, r);
  guestfs___free_string_list (r);
  return 1;
}

static int
guestfs_lua_internal_test_rstringlisterr (lua_State *L)
{
  char **r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "internal_test_rstringlisterr");


  r = guestfs_internal_test_rstringlisterr (g);
  if (r == NULL)
    return last_error (L, g);

  push_string_list (L, r);
  guestfs___free_string_list (r);
  return 1;
}

static int
guestfs_lua_internal_test_rstruct (lua_State *L)
{
  struct guestfs_lvm_pv *r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  const char *val;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "internal_test_rstruct");

  val = luaL_checkstring (L, 2);

  r = guestfs_internal_test_rstruct (g, val);
  if (r == NULL)
    return last_error (L, g);

  push_lvm_pv (L, r);
  guestfs_free_lvm_pv (r);
  return 1;
}

static int
guestfs_lua_internal_test_rstructerr (lua_State *L)
{
  struct guestfs_lvm_pv *r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "internal_test_rstructerr");


  r = guestfs_internal_test_rstructerr (g);
  if (r == NULL)
    return last_error (L, g);

  push_lvm_pv (L, r);
  guestfs_free_lvm_pv (r);
  return 1;
}

static int
guestfs_lua_internal_test_rstructlist (lua_State *L)
{
  struct guestfs_lvm_pv_list *r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  const char *val;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "internal_test_rstructlist");

  val = luaL_checkstring (L, 2);

  r = guestfs_internal_test_rstructlist (g, val);
  if (r == NULL)
    return last_error (L, g);

  push_lvm_pv_list (L, r);
  guestfs_free_lvm_pv_list (r);
  return 1;
}

static int
guestfs_lua_internal_test_rstructlisterr (lua_State *L)
{
  struct guestfs_lvm_pv_list *r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "internal_test_rstructlisterr");


  r = guestfs_internal_test_rstructlisterr (g);
  if (r == NULL)
    return last_error (L, g);

  push_lvm_pv_list (L, r);
  guestfs_free_lvm_pv_list (r);
  return 1;
}

static int
guestfs_lua_internal_test_set_output (lua_State *L)
{
  int r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  const char *filename;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "internal_test_set_output");

  filename = luaL_checkstring (L, 2);

  r = guestfs_internal_test_set_output (g, filename);
  if (r == -1)
    return last_error (L, g);

  return 0;
}

static int
guestfs_lua_is_blockdev (lua_State *L)
{
  int r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  const char *path;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "is_blockdev");

  path = luaL_checkstring (L, 2);

  r = guestfs_is_blockdev (g, path);
  if (r == -1)
    return last_error (L, g);

  lua_pushboolean (L, r);
  return 1;
}

static int
guestfs_lua_is_busy (lua_State *L)
{
  int r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "is_busy");


  r = guestfs_is_busy (g);
  if (r == -1)
    return last_error (L, g);

  lua_pushboolean (L, r);
  return 1;
}

static int
guestfs_lua_is_chardev (lua_State *L)
{
  int r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  const char *path;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "is_chardev");

  path = luaL_checkstring (L, 2);

  r = guestfs_is_chardev (g, path);
  if (r == -1)
    return last_error (L, g);

  lua_pushboolean (L, r);
  return 1;
}

static int
guestfs_lua_is_config (lua_State *L)
{
  int r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "is_config");


  r = guestfs_is_config (g);
  if (r == -1)
    return last_error (L, g);

  lua_pushboolean (L, r);
  return 1;
}

static int
guestfs_lua_is_dir (lua_State *L)
{
  int r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  const char *path;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "is_dir");

  path = luaL_checkstring (L, 2);

  r = guestfs_is_dir (g, path);
  if (r == -1)
    return last_error (L, g);

  lua_pushboolean (L, r);
  return 1;
}

static int
guestfs_lua_is_fifo (lua_State *L)
{
  int r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  const char *path;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "is_fifo");

  path = luaL_checkstring (L, 2);

  r = guestfs_is_fifo (g, path);
  if (r == -1)
    return last_error (L, g);

  lua_pushboolean (L, r);
  return 1;
}

static int
guestfs_lua_is_file (lua_State *L)
{
  int r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  const char *path;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "is_file");

  path = luaL_checkstring (L, 2);

  r = guestfs_is_file (g, path);
  if (r == -1)
    return last_error (L, g);

  lua_pushboolean (L, r);
  return 1;
}

static int
guestfs_lua_is_launching (lua_State *L)
{
  int r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "is_launching");


  r = guestfs_is_launching (g);
  if (r == -1)
    return last_error (L, g);

  lua_pushboolean (L, r);
  return 1;
}

static int
guestfs_lua_is_lv (lua_State *L)
{
  int r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  const char *device;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "is_lv");

  device = luaL_checkstring (L, 2);

  r = guestfs_is_lv (g, device);
  if (r == -1)
    return last_error (L, g);

  lua_pushboolean (L, r);
  return 1;
}

static int
guestfs_lua_is_ready (lua_State *L)
{
  int r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "is_ready");


  r = guestfs_is_ready (g);
  if (r == -1)
    return last_error (L, g);

  lua_pushboolean (L, r);
  return 1;
}

static int
guestfs_lua_is_socket (lua_State *L)
{
  int r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  const char *path;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "is_socket");

  path = luaL_checkstring (L, 2);

  r = guestfs_is_socket (g, path);
  if (r == -1)
    return last_error (L, g);

  lua_pushboolean (L, r);
  return 1;
}

static int
guestfs_lua_is_symlink (lua_State *L)
{
  int r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  const char *path;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "is_symlink");

  path = luaL_checkstring (L, 2);

  r = guestfs_is_symlink (g, path);
  if (r == -1)
    return last_error (L, g);

  lua_pushboolean (L, r);
  return 1;
}

static int
guestfs_lua_is_whole_device (lua_State *L)
{
  int r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  const char *device;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "is_whole_device");

  device = luaL_checkstring (L, 2);

  r = guestfs_is_whole_device (g, device);
  if (r == -1)
    return last_error (L, g);

  lua_pushboolean (L, r);
  return 1;
}

static int
guestfs_lua_is_zero (lua_State *L)
{
  int r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  const char *path;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "is_zero");

  path = luaL_checkstring (L, 2);

  r = guestfs_is_zero (g, path);
  if (r == -1)
    return last_error (L, g);

  lua_pushboolean (L, r);
  return 1;
}

static int
guestfs_lua_is_zero_device (lua_State *L)
{
  int r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  const char *device;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "is_zero_device");

  device = luaL_checkstring (L, 2);

  r = guestfs_is_zero_device (g, device);
  if (r == -1)
    return last_error (L, g);

  lua_pushboolean (L, r);
  return 1;
}

static int
guestfs_lua_isoinfo (lua_State *L)
{
  struct guestfs_isoinfo *r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  const char *isofile;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "isoinfo");

  isofile = luaL_checkstring (L, 2);

  r = guestfs_isoinfo (g, isofile);
  if (r == NULL)
    return last_error (L, g);

  push_isoinfo (L, r);
  guestfs_free_isoinfo (r);
  return 1;
}

static int
guestfs_lua_isoinfo_device (lua_State *L)
{
  struct guestfs_isoinfo *r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  const char *device;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "isoinfo_device");

  device = luaL_checkstring (L, 2);

  r = guestfs_isoinfo_device (g, device);
  if (r == NULL)
    return last_error (L, g);

  push_isoinfo (L, r);
  guestfs_free_isoinfo (r);
  return 1;
}

static int
guestfs_lua_kill_subprocess (lua_State *L)
{
  int r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "kill_subprocess");


  r = guestfs_kill_subprocess (g);
  if (r == -1)
    return last_error (L, g);

  return 0;
}

static int
guestfs_lua_launch (lua_State *L)
{
  int r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "launch");


  r = guestfs_launch (g);
  if (r == -1)
    return last_error (L, g);

  return 0;
}

static int
guestfs_lua_lchown (lua_State *L)
{
  int r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  int owner;
  int group;
  const char *path;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "lchown");

  owner = luaL_checkint (L, 2);
  group = luaL_checkint (L, 3);
  path = luaL_checkstring (L, 4);

  r = guestfs_lchown (g, owner, group, path);
  if (r == -1)
    return last_error (L, g);

  return 0;
}

static int
guestfs_lua_ldmtool_create_all (lua_State *L)
{
  int r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "ldmtool_create_all");


  r = guestfs_ldmtool_create_all (g);
  if (r == -1)
    return last_error (L, g);

  return 0;
}

static int
guestfs_lua_ldmtool_diskgroup_disks (lua_State *L)
{
  char **r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  const char *diskgroup;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "ldmtool_diskgroup_disks");

  diskgroup = luaL_checkstring (L, 2);

  r = guestfs_ldmtool_diskgroup_disks (g, diskgroup);
  if (r == NULL)
    return last_error (L, g);

  push_string_list (L, r);
  guestfs___free_string_list (r);
  return 1;
}

static int
guestfs_lua_ldmtool_diskgroup_name (lua_State *L)
{
  char *r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  const char *diskgroup;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "ldmtool_diskgroup_name");

  diskgroup = luaL_checkstring (L, 2);

  r = guestfs_ldmtool_diskgroup_name (g, diskgroup);
  if (r == NULL)
    return last_error (L, g);

  lua_pushstring (L, r);
  free (r);
  return 1;
}

static int
guestfs_lua_ldmtool_diskgroup_volumes (lua_State *L)
{
  char **r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  const char *diskgroup;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "ldmtool_diskgroup_volumes");

  diskgroup = luaL_checkstring (L, 2);

  r = guestfs_ldmtool_diskgroup_volumes (g, diskgroup);
  if (r == NULL)
    return last_error (L, g);

  push_string_list (L, r);
  guestfs___free_string_list (r);
  return 1;
}

static int
guestfs_lua_ldmtool_remove_all (lua_State *L)
{
  int r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "ldmtool_remove_all");


  r = guestfs_ldmtool_remove_all (g);
  if (r == -1)
    return last_error (L, g);

  return 0;
}

static int
guestfs_lua_ldmtool_scan (lua_State *L)
{
  char **r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "ldmtool_scan");


  r = guestfs_ldmtool_scan (g);
  if (r == NULL)
    return last_error (L, g);

  push_string_list (L, r);
  guestfs___free_string_list (r);
  return 1;
}

static int
guestfs_lua_ldmtool_scan_devices (lua_State *L)
{
  char **r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  char **devices;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "ldmtool_scan_devices");

  devices = get_string_list (L, 2);

  r = guestfs_ldmtool_scan_devices (g, devices);
  free (devices);
  if (r == NULL)
    return last_error (L, g);

  push_string_list (L, r);
  guestfs___free_string_list (r);
  return 1;
}

static int
guestfs_lua_ldmtool_volume_hint (lua_State *L)
{
  char *r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  const char *diskgroup;
  const char *volume;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "ldmtool_volume_hint");

  diskgroup = luaL_checkstring (L, 2);
  volume = luaL_checkstring (L, 3);

  r = guestfs_ldmtool_volume_hint (g, diskgroup, volume);
  if (r == NULL)
    return last_error (L, g);

  lua_pushstring (L, r);
  free (r);
  return 1;
}

static int
guestfs_lua_ldmtool_volume_partitions (lua_State *L)
{
  char **r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  const char *diskgroup;
  const char *volume;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "ldmtool_volume_partitions");

  diskgroup = luaL_checkstring (L, 2);
  volume = luaL_checkstring (L, 3);

  r = guestfs_ldmtool_volume_partitions (g, diskgroup, volume);
  if (r == NULL)
    return last_error (L, g);

  push_string_list (L, r);
  guestfs___free_string_list (r);
  return 1;
}

static int
guestfs_lua_ldmtool_volume_type (lua_State *L)
{
  char *r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  const char *diskgroup;
  const char *volume;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "ldmtool_volume_type");

  diskgroup = luaL_checkstring (L, 2);
  volume = luaL_checkstring (L, 3);

  r = guestfs_ldmtool_volume_type (g, diskgroup, volume);
  if (r == NULL)
    return last_error (L, g);

  lua_pushstring (L, r);
  free (r);
  return 1;
}

static int
guestfs_lua_lgetxattr (lua_State *L)
{
  char *r;
  size_t size;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  const char *path;
  const char *name;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "lgetxattr");

  path = luaL_checkstring (L, 2);
  name = luaL_checkstring (L, 3);

  r = guestfs_lgetxattr (g, path, name, &size);
  if (r == NULL)
    return last_error (L, g);

  lua_pushlstring (L, r, size);
  free (r);
  return 1;
}

static int
guestfs_lua_lgetxattrs (lua_State *L)
{
  struct guestfs_xattr_list *r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  const char *path;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "lgetxattrs");

  path = luaL_checkstring (L, 2);

  r = guestfs_lgetxattrs (g, path);
  if (r == NULL)
    return last_error (L, g);

  push_xattr_list (L, r);
  guestfs_free_xattr_list (r);
  return 1;
}

static int
guestfs_lua_list_9p (lua_State *L)
{
  char **r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "list_9p");


  r = guestfs_list_9p (g);
  if (r == NULL)
    return last_error (L, g);

  push_string_list (L, r);
  guestfs___free_string_list (r);
  return 1;
}

static int
guestfs_lua_list_devices (lua_State *L)
{
  char **r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "list_devices");


  r = guestfs_list_devices (g);
  if (r == NULL)
    return last_error (L, g);

  push_string_list (L, r);
  guestfs___free_string_list (r);
  return 1;
}

static int
guestfs_lua_list_disk_labels (lua_State *L)
{
  char **r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "list_disk_labels");


  r = guestfs_list_disk_labels (g);
  if (r == NULL)
    return last_error (L, g);

  push_table (L, r);
  guestfs___free_string_list (r);
  return 1;
}

static int
guestfs_lua_list_dm_devices (lua_State *L)
{
  char **r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "list_dm_devices");


  r = guestfs_list_dm_devices (g);
  if (r == NULL)
    return last_error (L, g);

  push_string_list (L, r);
  guestfs___free_string_list (r);
  return 1;
}

static int
guestfs_lua_list_filesystems (lua_State *L)
{
  char **r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "list_filesystems");


  r = guestfs_list_filesystems (g);
  if (r == NULL)
    return last_error (L, g);

  push_table (L, r);
  guestfs___free_string_list (r);
  return 1;
}

static int
guestfs_lua_list_ldm_partitions (lua_State *L)
{
  char **r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "list_ldm_partitions");


  r = guestfs_list_ldm_partitions (g);
  if (r == NULL)
    return last_error (L, g);

  push_string_list (L, r);
  guestfs___free_string_list (r);
  return 1;
}

static int
guestfs_lua_list_ldm_volumes (lua_State *L)
{
  char **r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "list_ldm_volumes");


  r = guestfs_list_ldm_volumes (g);
  if (r == NULL)
    return last_error (L, g);

  push_string_list (L, r);
  guestfs___free_string_list (r);
  return 1;
}

static int
guestfs_lua_list_md_devices (lua_State *L)
{
  char **r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "list_md_devices");


  r = guestfs_list_md_devices (g);
  if (r == NULL)
    return last_error (L, g);

  push_string_list (L, r);
  guestfs___free_string_list (r);
  return 1;
}

static int
guestfs_lua_list_partitions (lua_State *L)
{
  char **r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "list_partitions");


  r = guestfs_list_partitions (g);
  if (r == NULL)
    return last_error (L, g);

  push_string_list (L, r);
  guestfs___free_string_list (r);
  return 1;
}

static int
guestfs_lua_ll (lua_State *L)
{
  char *r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  const char *directory;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "ll");

  directory = luaL_checkstring (L, 2);

  r = guestfs_ll (g, directory);
  if (r == NULL)
    return last_error (L, g);

  lua_pushstring (L, r);
  free (r);
  return 1;
}

static int
guestfs_lua_llz (lua_State *L)
{
  char *r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  const char *directory;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "llz");

  directory = luaL_checkstring (L, 2);

  r = guestfs_llz (g, directory);
  if (r == NULL)
    return last_error (L, g);

  lua_pushstring (L, r);
  free (r);
  return 1;
}

static int
guestfs_lua_ln (lua_State *L)
{
  int r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  const char *target;
  const char *linkname;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "ln");

  target = luaL_checkstring (L, 2);
  linkname = luaL_checkstring (L, 3);

  r = guestfs_ln (g, target, linkname);
  if (r == -1)
    return last_error (L, g);

  return 0;
}

static int
guestfs_lua_ln_f (lua_State *L)
{
  int r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  const char *target;
  const char *linkname;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "ln_f");

  target = luaL_checkstring (L, 2);
  linkname = luaL_checkstring (L, 3);

  r = guestfs_ln_f (g, target, linkname);
  if (r == -1)
    return last_error (L, g);

  return 0;
}

static int
guestfs_lua_ln_s (lua_State *L)
{
  int r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  const char *target;
  const char *linkname;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "ln_s");

  target = luaL_checkstring (L, 2);
  linkname = luaL_checkstring (L, 3);

  r = guestfs_ln_s (g, target, linkname);
  if (r == -1)
    return last_error (L, g);

  return 0;
}

static int
guestfs_lua_ln_sf (lua_State *L)
{
  int r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  const char *target;
  const char *linkname;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "ln_sf");

  target = luaL_checkstring (L, 2);
  linkname = luaL_checkstring (L, 3);

  r = guestfs_ln_sf (g, target, linkname);
  if (r == -1)
    return last_error (L, g);

  return 0;
}

static int
guestfs_lua_lremovexattr (lua_State *L)
{
  int r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  const char *xattr;
  const char *path;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "lremovexattr");

  xattr = luaL_checkstring (L, 2);
  path = luaL_checkstring (L, 3);

  r = guestfs_lremovexattr (g, xattr, path);
  if (r == -1)
    return last_error (L, g);

  return 0;
}

static int
guestfs_lua_ls (lua_State *L)
{
  char **r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  const char *directory;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "ls");

  directory = luaL_checkstring (L, 2);

  r = guestfs_ls (g, directory);
  if (r == NULL)
    return last_error (L, g);

  push_string_list (L, r);
  guestfs___free_string_list (r);
  return 1;
}

static int
guestfs_lua_ls0 (lua_State *L)
{
  int r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  const char *dir;
  const char *filenames;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "ls0");

  dir = luaL_checkstring (L, 2);
  filenames = luaL_checkstring (L, 3);

  r = guestfs_ls0 (g, dir, filenames);
  if (r == -1)
    return last_error (L, g);

  return 0;
}

static int
guestfs_lua_lsetxattr (lua_State *L)
{
  int r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  const char *xattr;
  const char *val;
  int vallen;
  const char *path;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "lsetxattr");

  xattr = luaL_checkstring (L, 2);
  val = luaL_checkstring (L, 3);
  vallen = luaL_checkint (L, 4);
  path = luaL_checkstring (L, 5);

  r = guestfs_lsetxattr (g, xattr, val, vallen, path);
  if (r == -1)
    return last_error (L, g);

  return 0;
}

static int
guestfs_lua_lstat (lua_State *L)
{
  struct guestfs_stat *r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  const char *path;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "lstat");

  path = luaL_checkstring (L, 2);

  r = guestfs_lstat (g, path);
  if (r == NULL)
    return last_error (L, g);

  push_stat (L, r);
  guestfs_free_stat (r);
  return 1;
}

static int
guestfs_lua_lstatlist (lua_State *L)
{
  struct guestfs_stat_list *r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  const char *path;
  char **names;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "lstatlist");

  path = luaL_checkstring (L, 2);
  names = get_string_list (L, 3);

  r = guestfs_lstatlist (g, path, names);
  free (names);
  if (r == NULL)
    return last_error (L, g);

  push_stat_list (L, r);
  guestfs_free_stat_list (r);
  return 1;
}

static int
guestfs_lua_luks_add_key (lua_State *L)
{
  int r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  const char *device;
  const char *key;
  const char *newkey;
  int keyslot;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "luks_add_key");

  device = luaL_checkstring (L, 2);
  key = luaL_checkstring (L, 3);
  newkey = luaL_checkstring (L, 4);
  keyslot = luaL_checkint (L, 5);

  r = guestfs_luks_add_key (g, device, key, newkey, keyslot);
  if (r == -1)
    return last_error (L, g);

  return 0;
}

static int
guestfs_lua_luks_close (lua_State *L)
{
  int r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  const char *device;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "luks_close");

  device = luaL_checkstring (L, 2);

  r = guestfs_luks_close (g, device);
  if (r == -1)
    return last_error (L, g);

  return 0;
}

static int
guestfs_lua_luks_format (lua_State *L)
{
  int r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  const char *device;
  const char *key;
  int keyslot;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "luks_format");

  device = luaL_checkstring (L, 2);
  key = luaL_checkstring (L, 3);
  keyslot = luaL_checkint (L, 4);

  r = guestfs_luks_format (g, device, key, keyslot);
  if (r == -1)
    return last_error (L, g);

  return 0;
}

static int
guestfs_lua_luks_format_cipher (lua_State *L)
{
  int r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  const char *device;
  const char *key;
  int keyslot;
  const char *cipher;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "luks_format_cipher");

  device = luaL_checkstring (L, 2);
  key = luaL_checkstring (L, 3);
  keyslot = luaL_checkint (L, 4);
  cipher = luaL_checkstring (L, 5);

  r = guestfs_luks_format_cipher (g, device, key, keyslot, cipher);
  if (r == -1)
    return last_error (L, g);

  return 0;
}

static int
guestfs_lua_luks_kill_slot (lua_State *L)
{
  int r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  const char *device;
  const char *key;
  int keyslot;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "luks_kill_slot");

  device = luaL_checkstring (L, 2);
  key = luaL_checkstring (L, 3);
  keyslot = luaL_checkint (L, 4);

  r = guestfs_luks_kill_slot (g, device, key, keyslot);
  if (r == -1)
    return last_error (L, g);

  return 0;
}

static int
guestfs_lua_luks_open (lua_State *L)
{
  int r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  const char *device;
  const char *key;
  const char *mapname;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "luks_open");

  device = luaL_checkstring (L, 2);
  key = luaL_checkstring (L, 3);
  mapname = luaL_checkstring (L, 4);

  r = guestfs_luks_open (g, device, key, mapname);
  if (r == -1)
    return last_error (L, g);

  return 0;
}

static int
guestfs_lua_luks_open_ro (lua_State *L)
{
  int r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  const char *device;
  const char *key;
  const char *mapname;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "luks_open_ro");

  device = luaL_checkstring (L, 2);
  key = luaL_checkstring (L, 3);
  mapname = luaL_checkstring (L, 4);

  r = guestfs_luks_open_ro (g, device, key, mapname);
  if (r == -1)
    return last_error (L, g);

  return 0;
}

static int
guestfs_lua_lvcreate (lua_State *L)
{
  int r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  const char *logvol;
  const char *volgroup;
  int mbytes;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "lvcreate");

  logvol = luaL_checkstring (L, 2);
  volgroup = luaL_checkstring (L, 3);
  mbytes = luaL_checkint (L, 4);

  r = guestfs_lvcreate (g, logvol, volgroup, mbytes);
  if (r == -1)
    return last_error (L, g);

  return 0;
}

static int
guestfs_lua_lvcreate_free (lua_State *L)
{
  int r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  const char *logvol;
  const char *volgroup;
  int percent;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "lvcreate_free");

  logvol = luaL_checkstring (L, 2);
  volgroup = luaL_checkstring (L, 3);
  percent = luaL_checkint (L, 4);

  r = guestfs_lvcreate_free (g, logvol, volgroup, percent);
  if (r == -1)
    return last_error (L, g);

  return 0;
}

static int
guestfs_lua_lvm_canonical_lv_name (lua_State *L)
{
  char *r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  const char *lvname;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "lvm_canonical_lv_name");

  lvname = luaL_checkstring (L, 2);

  r = guestfs_lvm_canonical_lv_name (g, lvname);
  if (r == NULL)
    return last_error (L, g);

  lua_pushstring (L, r);
  free (r);
  return 1;
}

static int
guestfs_lua_lvm_clear_filter (lua_State *L)
{
  int r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "lvm_clear_filter");


  r = guestfs_lvm_clear_filter (g);
  if (r == -1)
    return last_error (L, g);

  return 0;
}

static int
guestfs_lua_lvm_remove_all (lua_State *L)
{
  int r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "lvm_remove_all");


  r = guestfs_lvm_remove_all (g);
  if (r == -1)
    return last_error (L, g);

  return 0;
}

static int
guestfs_lua_lvm_set_filter (lua_State *L)
{
  int r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  char **devices;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "lvm_set_filter");

  devices = get_string_list (L, 2);

  r = guestfs_lvm_set_filter (g, devices);
  free (devices);
  if (r == -1)
    return last_error (L, g);

  return 0;
}

static int
guestfs_lua_lvremove (lua_State *L)
{
  int r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  const char *device;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "lvremove");

  device = luaL_checkstring (L, 2);

  r = guestfs_lvremove (g, device);
  if (r == -1)
    return last_error (L, g);

  return 0;
}

static int
guestfs_lua_lvrename (lua_State *L)
{
  int r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  const char *logvol;
  const char *newlogvol;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "lvrename");

  logvol = luaL_checkstring (L, 2);
  newlogvol = luaL_checkstring (L, 3);

  r = guestfs_lvrename (g, logvol, newlogvol);
  if (r == -1)
    return last_error (L, g);

  return 0;
}

static int
guestfs_lua_lvresize (lua_State *L)
{
  int r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  const char *device;
  int mbytes;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "lvresize");

  device = luaL_checkstring (L, 2);
  mbytes = luaL_checkint (L, 3);

  r = guestfs_lvresize (g, device, mbytes);
  if (r == -1)
    return last_error (L, g);

  return 0;
}

static int
guestfs_lua_lvresize_free (lua_State *L)
{
  int r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  const char *lv;
  int percent;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "lvresize_free");

  lv = luaL_checkstring (L, 2);
  percent = luaL_checkint (L, 3);

  r = guestfs_lvresize_free (g, lv, percent);
  if (r == -1)
    return last_error (L, g);

  return 0;
}

static int
guestfs_lua_lvs (lua_State *L)
{
  char **r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "lvs");


  r = guestfs_lvs (g);
  if (r == NULL)
    return last_error (L, g);

  push_string_list (L, r);
  guestfs___free_string_list (r);
  return 1;
}

static int
guestfs_lua_lvs_full (lua_State *L)
{
  struct guestfs_lvm_lv_list *r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "lvs_full");


  r = guestfs_lvs_full (g);
  if (r == NULL)
    return last_error (L, g);

  push_lvm_lv_list (L, r);
  guestfs_free_lvm_lv_list (r);
  return 1;
}

static int
guestfs_lua_lvuuid (lua_State *L)
{
  char *r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  const char *device;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "lvuuid");

  device = luaL_checkstring (L, 2);

  r = guestfs_lvuuid (g, device);
  if (r == NULL)
    return last_error (L, g);

  lua_pushstring (L, r);
  free (r);
  return 1;
}

static int
guestfs_lua_lxattrlist (lua_State *L)
{
  struct guestfs_xattr_list *r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  const char *path;
  char **names;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "lxattrlist");

  path = luaL_checkstring (L, 2);
  names = get_string_list (L, 3);

  r = guestfs_lxattrlist (g, path, names);
  free (names);
  if (r == NULL)
    return last_error (L, g);

  push_xattr_list (L, r);
  guestfs_free_xattr_list (r);
  return 1;
}

static int
guestfs_lua_max_disks (lua_State *L)
{
  int r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "max_disks");


  r = guestfs_max_disks (g);
  if (r == -1)
    return last_error (L, g);

  lua_pushinteger (L, r);
  return 1;
}

static int
guestfs_lua_md_create (lua_State *L)
{
  int r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  const char *name;
  char **devices;
  struct guestfs_md_create_argv optargs_s = { .bitmask = 0 };
  struct guestfs_md_create_argv *optargs = &optargs_s;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "md_create");

  name = luaL_checkstring (L, 2);
  devices = get_string_list (L, 3);

  /* Check for optional arguments, encoded in a table. */
  if (lua_type (L, 4) == LUA_TTABLE) {
    OPTARG_IF_SET (4, "missingbitmap",
      optargs_s.bitmask |= GUESTFS_MD_CREATE_MISSINGBITMAP_BITMASK;
      optargs_s.missingbitmap = get_int64 (L, -1);
    );
    OPTARG_IF_SET (4, "nrdevices",
      optargs_s.bitmask |= GUESTFS_MD_CREATE_NRDEVICES_BITMASK;
      optargs_s.nrdevices = luaL_checkint (L, -1);
    );
    OPTARG_IF_SET (4, "spare",
      optargs_s.bitmask |= GUESTFS_MD_CREATE_SPARE_BITMASK;
      optargs_s.spare = luaL_checkint (L, -1);
    );
    OPTARG_IF_SET (4, "chunk",
      optargs_s.bitmask |= GUESTFS_MD_CREATE_CHUNK_BITMASK;
      optargs_s.chunk = get_int64 (L, -1);
    );
    OPTARG_IF_SET (4, "level",
      optargs_s.bitmask |= GUESTFS_MD_CREATE_LEVEL_BITMASK;
      optargs_s.level = luaL_checkstring (L, -1);
    );
  }

  r = guestfs_md_create_argv (g, name, devices, optargs);
  free (devices);
  if (r == -1)
    return last_error (L, g);

  return 0;
}

static int
guestfs_lua_md_detail (lua_State *L)
{
  char **r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  const char *md;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "md_detail");

  md = luaL_checkstring (L, 2);

  r = guestfs_md_detail (g, md);
  if (r == NULL)
    return last_error (L, g);

  push_table (L, r);
  guestfs___free_string_list (r);
  return 1;
}

static int
guestfs_lua_md_stat (lua_State *L)
{
  struct guestfs_mdstat_list *r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  const char *md;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "md_stat");

  md = luaL_checkstring (L, 2);

  r = guestfs_md_stat (g, md);
  if (r == NULL)
    return last_error (L, g);

  push_mdstat_list (L, r);
  guestfs_free_mdstat_list (r);
  return 1;
}

static int
guestfs_lua_md_stop (lua_State *L)
{
  int r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  const char *md;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "md_stop");

  md = luaL_checkstring (L, 2);

  r = guestfs_md_stop (g, md);
  if (r == -1)
    return last_error (L, g);

  return 0;
}

static int
guestfs_lua_mkdir (lua_State *L)
{
  int r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  const char *path;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "mkdir");

  path = luaL_checkstring (L, 2);

  r = guestfs_mkdir (g, path);
  if (r == -1)
    return last_error (L, g);

  return 0;
}

static int
guestfs_lua_mkdir_mode (lua_State *L)
{
  int r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  const char *path;
  int mode;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "mkdir_mode");

  path = luaL_checkstring (L, 2);
  mode = luaL_checkint (L, 3);

  r = guestfs_mkdir_mode (g, path, mode);
  if (r == -1)
    return last_error (L, g);

  return 0;
}

static int
guestfs_lua_mkdir_p (lua_State *L)
{
  int r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  const char *path;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "mkdir_p");

  path = luaL_checkstring (L, 2);

  r = guestfs_mkdir_p (g, path);
  if (r == -1)
    return last_error (L, g);

  return 0;
}

static int
guestfs_lua_mkdtemp (lua_State *L)
{
  char *r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  const char *tmpl;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "mkdtemp");

  tmpl = luaL_checkstring (L, 2);

  r = guestfs_mkdtemp (g, tmpl);
  if (r == NULL)
    return last_error (L, g);

  lua_pushstring (L, r);
  free (r);
  return 1;
}

static int
guestfs_lua_mke2fs (lua_State *L)
{
  int r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  const char *device;
  struct guestfs_mke2fs_argv optargs_s = { .bitmask = 0 };
  struct guestfs_mke2fs_argv *optargs = &optargs_s;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "mke2fs");

  device = luaL_checkstring (L, 2);

  /* Check for optional arguments, encoded in a table. */
  if (lua_type (L, 3) == LUA_TTABLE) {
    OPTARG_IF_SET (3, "blockscount",
      optargs_s.bitmask |= GUESTFS_MKE2FS_BLOCKSCOUNT_BITMASK;
      optargs_s.blockscount = get_int64 (L, -1);
    );
    OPTARG_IF_SET (3, "blocksize",
      optargs_s.bitmask |= GUESTFS_MKE2FS_BLOCKSIZE_BITMASK;
      optargs_s.blocksize = get_int64 (L, -1);
    );
    OPTARG_IF_SET (3, "fragsize",
      optargs_s.bitmask |= GUESTFS_MKE2FS_FRAGSIZE_BITMASK;
      optargs_s.fragsize = get_int64 (L, -1);
    );
    OPTARG_IF_SET (3, "blockspergroup",
      optargs_s.bitmask |= GUESTFS_MKE2FS_BLOCKSPERGROUP_BITMASK;
      optargs_s.blockspergroup = get_int64 (L, -1);
    );
    OPTARG_IF_SET (3, "numberofgroups",
      optargs_s.bitmask |= GUESTFS_MKE2FS_NUMBEROFGROUPS_BITMASK;
      optargs_s.numberofgroups = get_int64 (L, -1);
    );
    OPTARG_IF_SET (3, "bytesperinode",
      optargs_s.bitmask |= GUESTFS_MKE2FS_BYTESPERINODE_BITMASK;
      optargs_s.bytesperinode = get_int64 (L, -1);
    );
    OPTARG_IF_SET (3, "inodesize",
      optargs_s.bitmask |= GUESTFS_MKE2FS_INODESIZE_BITMASK;
      optargs_s.inodesize = get_int64 (L, -1);
    );
    OPTARG_IF_SET (3, "journalsize",
      optargs_s.bitmask |= GUESTFS_MKE2FS_JOURNALSIZE_BITMASK;
      optargs_s.journalsize = get_int64 (L, -1);
    );
    OPTARG_IF_SET (3, "numberofinodes",
      optargs_s.bitmask |= GUESTFS_MKE2FS_NUMBEROFINODES_BITMASK;
      optargs_s.numberofinodes = get_int64 (L, -1);
    );
    OPTARG_IF_SET (3, "stridesize",
      optargs_s.bitmask |= GUESTFS_MKE2FS_STRIDESIZE_BITMASK;
      optargs_s.stridesize = get_int64 (L, -1);
    );
    OPTARG_IF_SET (3, "stripewidth",
      optargs_s.bitmask |= GUESTFS_MKE2FS_STRIPEWIDTH_BITMASK;
      optargs_s.stripewidth = get_int64 (L, -1);
    );
    OPTARG_IF_SET (3, "maxonlineresize",
      optargs_s.bitmask |= GUESTFS_MKE2FS_MAXONLINERESIZE_BITMASK;
      optargs_s.maxonlineresize = get_int64 (L, -1);
    );
    OPTARG_IF_SET (3, "reservedblockspercentage",
      optargs_s.bitmask |= GUESTFS_MKE2FS_RESERVEDBLOCKSPERCENTAGE_BITMASK;
      optargs_s.reservedblockspercentage = luaL_checkint (L, -1);
    );
    OPTARG_IF_SET (3, "mmpupdateinterval",
      optargs_s.bitmask |= GUESTFS_MKE2FS_MMPUPDATEINTERVAL_BITMASK;
      optargs_s.mmpupdateinterval = luaL_checkint (L, -1);
    );
    OPTARG_IF_SET (3, "journaldevice",
      optargs_s.bitmask |= GUESTFS_MKE2FS_JOURNALDEVICE_BITMASK;
      optargs_s.journaldevice = luaL_checkstring (L, -1);
    );
    OPTARG_IF_SET (3, "label",
      optargs_s.bitmask |= GUESTFS_MKE2FS_LABEL_BITMASK;
      optargs_s.label = luaL_checkstring (L, -1);
    );
    OPTARG_IF_SET (3, "lastmounteddir",
      optargs_s.bitmask |= GUESTFS_MKE2FS_LASTMOUNTEDDIR_BITMASK;
      optargs_s.lastmounteddir = luaL_checkstring (L, -1);
    );
    OPTARG_IF_SET (3, "creatoros",
      optargs_s.bitmask |= GUESTFS_MKE2FS_CREATOROS_BITMASK;
      optargs_s.creatoros = luaL_checkstring (L, -1);
    );
    OPTARG_IF_SET (3, "fstype",
      optargs_s.bitmask |= GUESTFS_MKE2FS_FSTYPE_BITMASK;
      optargs_s.fstype = luaL_checkstring (L, -1);
    );
    OPTARG_IF_SET (3, "usagetype",
      optargs_s.bitmask |= GUESTFS_MKE2FS_USAGETYPE_BITMASK;
      optargs_s.usagetype = luaL_checkstring (L, -1);
    );
    OPTARG_IF_SET (3, "uuid",
      optargs_s.bitmask |= GUESTFS_MKE2FS_UUID_BITMASK;
      optargs_s.uuid = luaL_checkstring (L, -1);
    );
    OPTARG_IF_SET (3, "forcecreate",
      optargs_s.bitmask |= GUESTFS_MKE2FS_FORCECREATE_BITMASK;
      optargs_s.forcecreate = lua_toboolean (L, -1);
    );
    OPTARG_IF_SET (3, "writesbandgrouponly",
      optargs_s.bitmask |= GUESTFS_MKE2FS_WRITESBANDGROUPONLY_BITMASK;
      optargs_s.writesbandgrouponly = lua_toboolean (L, -1);
    );
    OPTARG_IF_SET (3, "lazyitableinit",
      optargs_s.bitmask |= GUESTFS_MKE2FS_LAZYITABLEINIT_BITMASK;
      optargs_s.lazyitableinit = lua_toboolean (L, -1);
    );
    OPTARG_IF_SET (3, "lazyjournalinit",
      optargs_s.bitmask |= GUESTFS_MKE2FS_LAZYJOURNALINIT_BITMASK;
      optargs_s.lazyjournalinit = lua_toboolean (L, -1);
    );
    OPTARG_IF_SET (3, "testfs",
      optargs_s.bitmask |= GUESTFS_MKE2FS_TESTFS_BITMASK;
      optargs_s.testfs = lua_toboolean (L, -1);
    );
    OPTARG_IF_SET (3, "discard",
      optargs_s.bitmask |= GUESTFS_MKE2FS_DISCARD_BITMASK;
      optargs_s.discard = lua_toboolean (L, -1);
    );
    OPTARG_IF_SET (3, "quotatype",
      optargs_s.bitmask |= GUESTFS_MKE2FS_QUOTATYPE_BITMASK;
      optargs_s.quotatype = lua_toboolean (L, -1);
    );
    OPTARG_IF_SET (3, "extent",
      optargs_s.bitmask |= GUESTFS_MKE2FS_EXTENT_BITMASK;
      optargs_s.extent = lua_toboolean (L, -1);
    );
    OPTARG_IF_SET (3, "filetype",
      optargs_s.bitmask |= GUESTFS_MKE2FS_FILETYPE_BITMASK;
      optargs_s.filetype = lua_toboolean (L, -1);
    );
    OPTARG_IF_SET (3, "flexbg",
      optargs_s.bitmask |= GUESTFS_MKE2FS_FLEXBG_BITMASK;
      optargs_s.flexbg = lua_toboolean (L, -1);
    );
    OPTARG_IF_SET (3, "hasjournal",
      optargs_s.bitmask |= GUESTFS_MKE2FS_HASJOURNAL_BITMASK;
      optargs_s.hasjournal = lua_toboolean (L, -1);
    );
    OPTARG_IF_SET (3, "journaldev",
      optargs_s.bitmask |= GUESTFS_MKE2FS_JOURNALDEV_BITMASK;
      optargs_s.journaldev = lua_toboolean (L, -1);
    );
    OPTARG_IF_SET (3, "largefile",
      optargs_s.bitmask |= GUESTFS_MKE2FS_LARGEFILE_BITMASK;
      optargs_s.largefile = lua_toboolean (L, -1);
    );
    OPTARG_IF_SET (3, "quota",
      optargs_s.bitmask |= GUESTFS_MKE2FS_QUOTA_BITMASK;
      optargs_s.quota = lua_toboolean (L, -1);
    );
    OPTARG_IF_SET (3, "resizeinode",
      optargs_s.bitmask |= GUESTFS_MKE2FS_RESIZEINODE_BITMASK;
      optargs_s.resizeinode = lua_toboolean (L, -1);
    );
    OPTARG_IF_SET (3, "sparsesuper",
      optargs_s.bitmask |= GUESTFS_MKE2FS_SPARSESUPER_BITMASK;
      optargs_s.sparsesuper = lua_toboolean (L, -1);
    );
    OPTARG_IF_SET (3, "uninitbg",
      optargs_s.bitmask |= GUESTFS_MKE2FS_UNINITBG_BITMASK;
      optargs_s.uninitbg = lua_toboolean (L, -1);
    );
  }

  r = guestfs_mke2fs_argv (g, device, optargs);
  if (r == -1)
    return last_error (L, g);

  return 0;
}

static int
guestfs_lua_mke2fs_J (lua_State *L)
{
  int r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  const char *fstype;
  int blocksize;
  const char *device;
  const char *journal;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "mke2fs_J");

  fstype = luaL_checkstring (L, 2);
  blocksize = luaL_checkint (L, 3);
  device = luaL_checkstring (L, 4);
  journal = luaL_checkstring (L, 5);

  r = guestfs_mke2fs_J (g, fstype, blocksize, device, journal);
  if (r == -1)
    return last_error (L, g);

  return 0;
}

static int
guestfs_lua_mke2fs_JL (lua_State *L)
{
  int r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  const char *fstype;
  int blocksize;
  const char *device;
  const char *label;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "mke2fs_JL");

  fstype = luaL_checkstring (L, 2);
  blocksize = luaL_checkint (L, 3);
  device = luaL_checkstring (L, 4);
  label = luaL_checkstring (L, 5);

  r = guestfs_mke2fs_JL (g, fstype, blocksize, device, label);
  if (r == -1)
    return last_error (L, g);

  return 0;
}

static int
guestfs_lua_mke2fs_JU (lua_State *L)
{
  int r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  const char *fstype;
  int blocksize;
  const char *device;
  const char *uuid;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "mke2fs_JU");

  fstype = luaL_checkstring (L, 2);
  blocksize = luaL_checkint (L, 3);
  device = luaL_checkstring (L, 4);
  uuid = luaL_checkstring (L, 5);

  r = guestfs_mke2fs_JU (g, fstype, blocksize, device, uuid);
  if (r == -1)
    return last_error (L, g);

  return 0;
}

static int
guestfs_lua_mke2journal (lua_State *L)
{
  int r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  int blocksize;
  const char *device;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "mke2journal");

  blocksize = luaL_checkint (L, 2);
  device = luaL_checkstring (L, 3);

  r = guestfs_mke2journal (g, blocksize, device);
  if (r == -1)
    return last_error (L, g);

  return 0;
}

static int
guestfs_lua_mke2journal_L (lua_State *L)
{
  int r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  int blocksize;
  const char *label;
  const char *device;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "mke2journal_L");

  blocksize = luaL_checkint (L, 2);
  label = luaL_checkstring (L, 3);
  device = luaL_checkstring (L, 4);

  r = guestfs_mke2journal_L (g, blocksize, label, device);
  if (r == -1)
    return last_error (L, g);

  return 0;
}

static int
guestfs_lua_mke2journal_U (lua_State *L)
{
  int r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  int blocksize;
  const char *uuid;
  const char *device;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "mke2journal_U");

  blocksize = luaL_checkint (L, 2);
  uuid = luaL_checkstring (L, 3);
  device = luaL_checkstring (L, 4);

  r = guestfs_mke2journal_U (g, blocksize, uuid, device);
  if (r == -1)
    return last_error (L, g);

  return 0;
}

static int
guestfs_lua_mkfifo (lua_State *L)
{
  int r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  int mode;
  const char *path;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "mkfifo");

  mode = luaL_checkint (L, 2);
  path = luaL_checkstring (L, 3);

  r = guestfs_mkfifo (g, mode, path);
  if (r == -1)
    return last_error (L, g);

  return 0;
}

static int
guestfs_lua_mkfs (lua_State *L)
{
  int r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  const char *fstype;
  const char *device;
  struct guestfs_mkfs_opts_argv optargs_s = { .bitmask = 0 };
  struct guestfs_mkfs_opts_argv *optargs = &optargs_s;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "mkfs");

  fstype = luaL_checkstring (L, 2);
  device = luaL_checkstring (L, 3);

  /* Check for optional arguments, encoded in a table. */
  if (lua_type (L, 4) == LUA_TTABLE) {
    OPTARG_IF_SET (4, "blocksize",
      optargs_s.bitmask |= GUESTFS_MKFS_OPTS_BLOCKSIZE_BITMASK;
      optargs_s.blocksize = luaL_checkint (L, -1);
    );
    OPTARG_IF_SET (4, "features",
      optargs_s.bitmask |= GUESTFS_MKFS_OPTS_FEATURES_BITMASK;
      optargs_s.features = luaL_checkstring (L, -1);
    );
    OPTARG_IF_SET (4, "inode",
      optargs_s.bitmask |= GUESTFS_MKFS_OPTS_INODE_BITMASK;
      optargs_s.inode = luaL_checkint (L, -1);
    );
    OPTARG_IF_SET (4, "sectorsize",
      optargs_s.bitmask |= GUESTFS_MKFS_OPTS_SECTORSIZE_BITMASK;
      optargs_s.sectorsize = luaL_checkint (L, -1);
    );
  }

  r = guestfs_mkfs_opts_argv (g, fstype, device, optargs);
  if (r == -1)
    return last_error (L, g);

  return 0;
}

static int
guestfs_lua_mkfs_b (lua_State *L)
{
  int r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  const char *fstype;
  int blocksize;
  const char *device;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "mkfs_b");

  fstype = luaL_checkstring (L, 2);
  blocksize = luaL_checkint (L, 3);
  device = luaL_checkstring (L, 4);

  r = guestfs_mkfs_b (g, fstype, blocksize, device);
  if (r == -1)
    return last_error (L, g);

  return 0;
}

static int
guestfs_lua_mkfs_btrfs (lua_State *L)
{
  int r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  char **devices;
  struct guestfs_mkfs_btrfs_argv optargs_s = { .bitmask = 0 };
  struct guestfs_mkfs_btrfs_argv *optargs = &optargs_s;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "mkfs_btrfs");

  devices = get_string_list (L, 2);

  /* Check for optional arguments, encoded in a table. */
  if (lua_type (L, 3) == LUA_TTABLE) {
    OPTARG_IF_SET (3, "allocstart",
      optargs_s.bitmask |= GUESTFS_MKFS_BTRFS_ALLOCSTART_BITMASK;
      optargs_s.allocstart = get_int64 (L, -1);
    );
    OPTARG_IF_SET (3, "bytecount",
      optargs_s.bitmask |= GUESTFS_MKFS_BTRFS_BYTECOUNT_BITMASK;
      optargs_s.bytecount = get_int64 (L, -1);
    );
    OPTARG_IF_SET (3, "datatype",
      optargs_s.bitmask |= GUESTFS_MKFS_BTRFS_DATATYPE_BITMASK;
      optargs_s.datatype = luaL_checkstring (L, -1);
    );
    OPTARG_IF_SET (3, "leafsize",
      optargs_s.bitmask |= GUESTFS_MKFS_BTRFS_LEAFSIZE_BITMASK;
      optargs_s.leafsize = luaL_checkint (L, -1);
    );
    OPTARG_IF_SET (3, "label",
      optargs_s.bitmask |= GUESTFS_MKFS_BTRFS_LABEL_BITMASK;
      optargs_s.label = luaL_checkstring (L, -1);
    );
    OPTARG_IF_SET (3, "metadata",
      optargs_s.bitmask |= GUESTFS_MKFS_BTRFS_METADATA_BITMASK;
      optargs_s.metadata = luaL_checkstring (L, -1);
    );
    OPTARG_IF_SET (3, "nodesize",
      optargs_s.bitmask |= GUESTFS_MKFS_BTRFS_NODESIZE_BITMASK;
      optargs_s.nodesize = luaL_checkint (L, -1);
    );
    OPTARG_IF_SET (3, "sectorsize",
      optargs_s.bitmask |= GUESTFS_MKFS_BTRFS_SECTORSIZE_BITMASK;
      optargs_s.sectorsize = luaL_checkint (L, -1);
    );
  }

  r = guestfs_mkfs_btrfs_argv (g, devices, optargs);
  free (devices);
  if (r == -1)
    return last_error (L, g);

  return 0;
}

static int
guestfs_lua_mklost_and_found (lua_State *L)
{
  int r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  const char *mountpoint;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "mklost_and_found");

  mountpoint = luaL_checkstring (L, 2);

  r = guestfs_mklost_and_found (g, mountpoint);
  if (r == -1)
    return last_error (L, g);

  return 0;
}

static int
guestfs_lua_mkmountpoint (lua_State *L)
{
  int r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  const char *exemptpath;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "mkmountpoint");

  exemptpath = luaL_checkstring (L, 2);

  r = guestfs_mkmountpoint (g, exemptpath);
  if (r == -1)
    return last_error (L, g);

  return 0;
}

static int
guestfs_lua_mknod (lua_State *L)
{
  int r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  int mode;
  int devmajor;
  int devminor;
  const char *path;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "mknod");

  mode = luaL_checkint (L, 2);
  devmajor = luaL_checkint (L, 3);
  devminor = luaL_checkint (L, 4);
  path = luaL_checkstring (L, 5);

  r = guestfs_mknod (g, mode, devmajor, devminor, path);
  if (r == -1)
    return last_error (L, g);

  return 0;
}

static int
guestfs_lua_mknod_b (lua_State *L)
{
  int r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  int mode;
  int devmajor;
  int devminor;
  const char *path;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "mknod_b");

  mode = luaL_checkint (L, 2);
  devmajor = luaL_checkint (L, 3);
  devminor = luaL_checkint (L, 4);
  path = luaL_checkstring (L, 5);

  r = guestfs_mknod_b (g, mode, devmajor, devminor, path);
  if (r == -1)
    return last_error (L, g);

  return 0;
}

static int
guestfs_lua_mknod_c (lua_State *L)
{
  int r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  int mode;
  int devmajor;
  int devminor;
  const char *path;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "mknod_c");

  mode = luaL_checkint (L, 2);
  devmajor = luaL_checkint (L, 3);
  devminor = luaL_checkint (L, 4);
  path = luaL_checkstring (L, 5);

  r = guestfs_mknod_c (g, mode, devmajor, devminor, path);
  if (r == -1)
    return last_error (L, g);

  return 0;
}

static int
guestfs_lua_mkswap (lua_State *L)
{
  int r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  const char *device;
  struct guestfs_mkswap_opts_argv optargs_s = { .bitmask = 0 };
  struct guestfs_mkswap_opts_argv *optargs = &optargs_s;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "mkswap");

  device = luaL_checkstring (L, 2);

  /* Check for optional arguments, encoded in a table. */
  if (lua_type (L, 3) == LUA_TTABLE) {
    OPTARG_IF_SET (3, "label",
      optargs_s.bitmask |= GUESTFS_MKSWAP_OPTS_LABEL_BITMASK;
      optargs_s.label = luaL_checkstring (L, -1);
    );
    OPTARG_IF_SET (3, "uuid",
      optargs_s.bitmask |= GUESTFS_MKSWAP_OPTS_UUID_BITMASK;
      optargs_s.uuid = luaL_checkstring (L, -1);
    );
  }

  r = guestfs_mkswap_opts_argv (g, device, optargs);
  if (r == -1)
    return last_error (L, g);

  return 0;
}

static int
guestfs_lua_mkswap_L (lua_State *L)
{
  int r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  const char *label;
  const char *device;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "mkswap_L");

  label = luaL_checkstring (L, 2);
  device = luaL_checkstring (L, 3);

  r = guestfs_mkswap_L (g, label, device);
  if (r == -1)
    return last_error (L, g);

  return 0;
}

static int
guestfs_lua_mkswap_U (lua_State *L)
{
  int r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  const char *uuid;
  const char *device;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "mkswap_U");

  uuid = luaL_checkstring (L, 2);
  device = luaL_checkstring (L, 3);

  r = guestfs_mkswap_U (g, uuid, device);
  if (r == -1)
    return last_error (L, g);

  return 0;
}

static int
guestfs_lua_mkswap_file (lua_State *L)
{
  int r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  const char *path;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "mkswap_file");

  path = luaL_checkstring (L, 2);

  r = guestfs_mkswap_file (g, path);
  if (r == -1)
    return last_error (L, g);

  return 0;
}

static int
guestfs_lua_mktemp (lua_State *L)
{
  char *r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  const char *tmpl;
  struct guestfs_mktemp_argv optargs_s = { .bitmask = 0 };
  struct guestfs_mktemp_argv *optargs = &optargs_s;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "mktemp");

  tmpl = luaL_checkstring (L, 2);

  /* Check for optional arguments, encoded in a table. */
  if (lua_type (L, 3) == LUA_TTABLE) {
    OPTARG_IF_SET (3, "suffix",
      optargs_s.bitmask |= GUESTFS_MKTEMP_SUFFIX_BITMASK;
      optargs_s.suffix = luaL_checkstring (L, -1);
    );
  }

  r = guestfs_mktemp_argv (g, tmpl, optargs);
  if (r == NULL)
    return last_error (L, g);

  lua_pushstring (L, r);
  free (r);
  return 1;
}

static int
guestfs_lua_modprobe (lua_State *L)
{
  int r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  const char *modulename;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "modprobe");

  modulename = luaL_checkstring (L, 2);

  r = guestfs_modprobe (g, modulename);
  if (r == -1)
    return last_error (L, g);

  return 0;
}

static int
guestfs_lua_mount (lua_State *L)
{
  int r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  const char *mountable;
  const char *mountpoint;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "mount");

  mountable = luaL_checkstring (L, 2);
  mountpoint = luaL_checkstring (L, 3);

  r = guestfs_mount (g, mountable, mountpoint);
  if (r == -1)
    return last_error (L, g);

  return 0;
}

static int
guestfs_lua_mount_9p (lua_State *L)
{
  int r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  const char *mounttag;
  const char *mountpoint;
  struct guestfs_mount_9p_argv optargs_s = { .bitmask = 0 };
  struct guestfs_mount_9p_argv *optargs = &optargs_s;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "mount_9p");

  mounttag = luaL_checkstring (L, 2);
  mountpoint = luaL_checkstring (L, 3);

  /* Check for optional arguments, encoded in a table. */
  if (lua_type (L, 4) == LUA_TTABLE) {
    OPTARG_IF_SET (4, "options",
      optargs_s.bitmask |= GUESTFS_MOUNT_9P_OPTIONS_BITMASK;
      optargs_s.options = luaL_checkstring (L, -1);
    );
  }

  r = guestfs_mount_9p_argv (g, mounttag, mountpoint, optargs);
  if (r == -1)
    return last_error (L, g);

  return 0;
}

static int
guestfs_lua_mount_local (lua_State *L)
{
  int r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  const char *localmountpoint;
  struct guestfs_mount_local_argv optargs_s = { .bitmask = 0 };
  struct guestfs_mount_local_argv *optargs = &optargs_s;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "mount_local");

  localmountpoint = luaL_checkstring (L, 2);

  /* Check for optional arguments, encoded in a table. */
  if (lua_type (L, 3) == LUA_TTABLE) {
    OPTARG_IF_SET (3, "readonly",
      optargs_s.bitmask |= GUESTFS_MOUNT_LOCAL_READONLY_BITMASK;
      optargs_s.readonly = lua_toboolean (L, -1);
    );
    OPTARG_IF_SET (3, "options",
      optargs_s.bitmask |= GUESTFS_MOUNT_LOCAL_OPTIONS_BITMASK;
      optargs_s.options = luaL_checkstring (L, -1);
    );
    OPTARG_IF_SET (3, "cachetimeout",
      optargs_s.bitmask |= GUESTFS_MOUNT_LOCAL_CACHETIMEOUT_BITMASK;
      optargs_s.cachetimeout = luaL_checkint (L, -1);
    );
    OPTARG_IF_SET (3, "debugcalls",
      optargs_s.bitmask |= GUESTFS_MOUNT_LOCAL_DEBUGCALLS_BITMASK;
      optargs_s.debugcalls = lua_toboolean (L, -1);
    );
  }

  r = guestfs_mount_local_argv (g, localmountpoint, optargs);
  if (r == -1)
    return last_error (L, g);

  return 0;
}

static int
guestfs_lua_mount_local_run (lua_State *L)
{
  int r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "mount_local_run");


  r = guestfs_mount_local_run (g);
  if (r == -1)
    return last_error (L, g);

  return 0;
}

static int
guestfs_lua_mount_loop (lua_State *L)
{
  int r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  const char *file;
  const char *mountpoint;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "mount_loop");

  file = luaL_checkstring (L, 2);
  mountpoint = luaL_checkstring (L, 3);

  r = guestfs_mount_loop (g, file, mountpoint);
  if (r == -1)
    return last_error (L, g);

  return 0;
}

static int
guestfs_lua_mount_options (lua_State *L)
{
  int r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  const char *options;
  const char *mountable;
  const char *mountpoint;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "mount_options");

  options = luaL_checkstring (L, 2);
  mountable = luaL_checkstring (L, 3);
  mountpoint = luaL_checkstring (L, 4);

  r = guestfs_mount_options (g, options, mountable, mountpoint);
  if (r == -1)
    return last_error (L, g);

  return 0;
}

static int
guestfs_lua_mount_ro (lua_State *L)
{
  int r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  const char *mountable;
  const char *mountpoint;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "mount_ro");

  mountable = luaL_checkstring (L, 2);
  mountpoint = luaL_checkstring (L, 3);

  r = guestfs_mount_ro (g, mountable, mountpoint);
  if (r == -1)
    return last_error (L, g);

  return 0;
}

static int
guestfs_lua_mount_vfs (lua_State *L)
{
  int r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  const char *options;
  const char *vfstype;
  const char *mountable;
  const char *mountpoint;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "mount_vfs");

  options = luaL_checkstring (L, 2);
  vfstype = luaL_checkstring (L, 3);
  mountable = luaL_checkstring (L, 4);
  mountpoint = luaL_checkstring (L, 5);

  r = guestfs_mount_vfs (g, options, vfstype, mountable, mountpoint);
  if (r == -1)
    return last_error (L, g);

  return 0;
}

static int
guestfs_lua_mountpoints (lua_State *L)
{
  char **r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "mountpoints");


  r = guestfs_mountpoints (g);
  if (r == NULL)
    return last_error (L, g);

  push_table (L, r);
  guestfs___free_string_list (r);
  return 1;
}

static int
guestfs_lua_mounts (lua_State *L)
{
  char **r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "mounts");


  r = guestfs_mounts (g);
  if (r == NULL)
    return last_error (L, g);

  push_string_list (L, r);
  guestfs___free_string_list (r);
  return 1;
}

static int
guestfs_lua_mv (lua_State *L)
{
  int r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  const char *src;
  const char *dest;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "mv");

  src = luaL_checkstring (L, 2);
  dest = luaL_checkstring (L, 3);

  r = guestfs_mv (g, src, dest);
  if (r == -1)
    return last_error (L, g);

  return 0;
}

static int
guestfs_lua_nr_devices (lua_State *L)
{
  int r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "nr_devices");


  r = guestfs_nr_devices (g);
  if (r == -1)
    return last_error (L, g);

  lua_pushinteger (L, r);
  return 1;
}

static int
guestfs_lua_ntfs_3g_probe (lua_State *L)
{
  int r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  int rw;
  const char *device;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "ntfs_3g_probe");

  rw = lua_toboolean (L, 2);
  device = luaL_checkstring (L, 3);

  r = guestfs_ntfs_3g_probe (g, rw, device);
  if (r == -1)
    return last_error (L, g);

  lua_pushinteger (L, r);
  return 1;
}

static int
guestfs_lua_ntfsclone_in (lua_State *L)
{
  int r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  const char *backupfile;
  const char *device;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "ntfsclone_in");

  backupfile = luaL_checkstring (L, 2);
  device = luaL_checkstring (L, 3);

  r = guestfs_ntfsclone_in (g, backupfile, device);
  if (r == -1)
    return last_error (L, g);

  return 0;
}

static int
guestfs_lua_ntfsclone_out (lua_State *L)
{
  int r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  const char *device;
  const char *backupfile;
  struct guestfs_ntfsclone_out_argv optargs_s = { .bitmask = 0 };
  struct guestfs_ntfsclone_out_argv *optargs = &optargs_s;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "ntfsclone_out");

  device = luaL_checkstring (L, 2);
  backupfile = luaL_checkstring (L, 3);

  /* Check for optional arguments, encoded in a table. */
  if (lua_type (L, 4) == LUA_TTABLE) {
    OPTARG_IF_SET (4, "metadataonly",
      optargs_s.bitmask |= GUESTFS_NTFSCLONE_OUT_METADATAONLY_BITMASK;
      optargs_s.metadataonly = lua_toboolean (L, -1);
    );
    OPTARG_IF_SET (4, "rescue",
      optargs_s.bitmask |= GUESTFS_NTFSCLONE_OUT_RESCUE_BITMASK;
      optargs_s.rescue = lua_toboolean (L, -1);
    );
    OPTARG_IF_SET (4, "ignorefscheck",
      optargs_s.bitmask |= GUESTFS_NTFSCLONE_OUT_IGNOREFSCHECK_BITMASK;
      optargs_s.ignorefscheck = lua_toboolean (L, -1);
    );
    OPTARG_IF_SET (4, "preservetimestamps",
      optargs_s.bitmask |= GUESTFS_NTFSCLONE_OUT_PRESERVETIMESTAMPS_BITMASK;
      optargs_s.preservetimestamps = lua_toboolean (L, -1);
    );
    OPTARG_IF_SET (4, "force",
      optargs_s.bitmask |= GUESTFS_NTFSCLONE_OUT_FORCE_BITMASK;
      optargs_s.force = lua_toboolean (L, -1);
    );
  }

  r = guestfs_ntfsclone_out_argv (g, device, backupfile, optargs);
  if (r == -1)
    return last_error (L, g);

  return 0;
}

static int
guestfs_lua_ntfsfix (lua_State *L)
{
  int r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  const char *device;
  struct guestfs_ntfsfix_argv optargs_s = { .bitmask = 0 };
  struct guestfs_ntfsfix_argv *optargs = &optargs_s;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "ntfsfix");

  device = luaL_checkstring (L, 2);

  /* Check for optional arguments, encoded in a table. */
  if (lua_type (L, 3) == LUA_TTABLE) {
    OPTARG_IF_SET (3, "clearbadsectors",
      optargs_s.bitmask |= GUESTFS_NTFSFIX_CLEARBADSECTORS_BITMASK;
      optargs_s.clearbadsectors = lua_toboolean (L, -1);
    );
  }

  r = guestfs_ntfsfix_argv (g, device, optargs);
  if (r == -1)
    return last_error (L, g);

  return 0;
}

static int
guestfs_lua_ntfsresize (lua_State *L)
{
  int r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  const char *device;
  struct guestfs_ntfsresize_opts_argv optargs_s = { .bitmask = 0 };
  struct guestfs_ntfsresize_opts_argv *optargs = &optargs_s;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "ntfsresize");

  device = luaL_checkstring (L, 2);

  /* Check for optional arguments, encoded in a table. */
  if (lua_type (L, 3) == LUA_TTABLE) {
    OPTARG_IF_SET (3, "size",
      optargs_s.bitmask |= GUESTFS_NTFSRESIZE_OPTS_SIZE_BITMASK;
      optargs_s.size = get_int64 (L, -1);
    );
    OPTARG_IF_SET (3, "force",
      optargs_s.bitmask |= GUESTFS_NTFSRESIZE_OPTS_FORCE_BITMASK;
      optargs_s.force = lua_toboolean (L, -1);
    );
  }

  r = guestfs_ntfsresize_opts_argv (g, device, optargs);
  if (r == -1)
    return last_error (L, g);

  return 0;
}

static int
guestfs_lua_ntfsresize_size (lua_State *L)
{
  int r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  const char *device;
  int64_t size;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "ntfsresize_size");

  device = luaL_checkstring (L, 2);
  size = get_int64 (L, 3);

  r = guestfs_ntfsresize_size (g, device, size);
  if (r == -1)
    return last_error (L, g);

  return 0;
}

static int
guestfs_lua_parse_environment (lua_State *L)
{
  int r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "parse_environment");


  r = guestfs_parse_environment (g);
  if (r == -1)
    return last_error (L, g);

  return 0;
}

static int
guestfs_lua_parse_environment_list (lua_State *L)
{
  int r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  char **environment;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "parse_environment_list");

  environment = get_string_list (L, 2);

  r = guestfs_parse_environment_list (g, environment);
  free (environment);
  if (r == -1)
    return last_error (L, g);

  return 0;
}

static int
guestfs_lua_part_add (lua_State *L)
{
  int r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  const char *device;
  const char *prlogex;
  int64_t startsect;
  int64_t endsect;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "part_add");

  device = luaL_checkstring (L, 2);
  prlogex = luaL_checkstring (L, 3);
  startsect = get_int64 (L, 4);
  endsect = get_int64 (L, 5);

  r = guestfs_part_add (g, device, prlogex, startsect, endsect);
  if (r == -1)
    return last_error (L, g);

  return 0;
}

static int
guestfs_lua_part_del (lua_State *L)
{
  int r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  const char *device;
  int partnum;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "part_del");

  device = luaL_checkstring (L, 2);
  partnum = luaL_checkint (L, 3);

  r = guestfs_part_del (g, device, partnum);
  if (r == -1)
    return last_error (L, g);

  return 0;
}

static int
guestfs_lua_part_disk (lua_State *L)
{
  int r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  const char *device;
  const char *parttype;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "part_disk");

  device = luaL_checkstring (L, 2);
  parttype = luaL_checkstring (L, 3);

  r = guestfs_part_disk (g, device, parttype);
  if (r == -1)
    return last_error (L, g);

  return 0;
}

static int
guestfs_lua_part_get_bootable (lua_State *L)
{
  int r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  const char *device;
  int partnum;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "part_get_bootable");

  device = luaL_checkstring (L, 2);
  partnum = luaL_checkint (L, 3);

  r = guestfs_part_get_bootable (g, device, partnum);
  if (r == -1)
    return last_error (L, g);

  lua_pushboolean (L, r);
  return 1;
}

static int
guestfs_lua_part_get_gpt_type (lua_State *L)
{
  char *r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  const char *device;
  int partnum;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "part_get_gpt_type");

  device = luaL_checkstring (L, 2);
  partnum = luaL_checkint (L, 3);

  r = guestfs_part_get_gpt_type (g, device, partnum);
  if (r == NULL)
    return last_error (L, g);

  lua_pushstring (L, r);
  free (r);
  return 1;
}

static int
guestfs_lua_part_get_mbr_id (lua_State *L)
{
  int r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  const char *device;
  int partnum;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "part_get_mbr_id");

  device = luaL_checkstring (L, 2);
  partnum = luaL_checkint (L, 3);

  r = guestfs_part_get_mbr_id (g, device, partnum);
  if (r == -1)
    return last_error (L, g);

  lua_pushinteger (L, r);
  return 1;
}

static int
guestfs_lua_part_get_parttype (lua_State *L)
{
  char *r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  const char *device;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "part_get_parttype");

  device = luaL_checkstring (L, 2);

  r = guestfs_part_get_parttype (g, device);
  if (r == NULL)
    return last_error (L, g);

  lua_pushstring (L, r);
  free (r);
  return 1;
}

static int
guestfs_lua_part_init (lua_State *L)
{
  int r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  const char *device;
  const char *parttype;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "part_init");

  device = luaL_checkstring (L, 2);
  parttype = luaL_checkstring (L, 3);

  r = guestfs_part_init (g, device, parttype);
  if (r == -1)
    return last_error (L, g);

  return 0;
}

static int
guestfs_lua_part_list (lua_State *L)
{
  struct guestfs_partition_list *r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  const char *device;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "part_list");

  device = luaL_checkstring (L, 2);

  r = guestfs_part_list (g, device);
  if (r == NULL)
    return last_error (L, g);

  push_partition_list (L, r);
  guestfs_free_partition_list (r);
  return 1;
}

static int
guestfs_lua_part_set_bootable (lua_State *L)
{
  int r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  const char *device;
  int partnum;
  int bootable;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "part_set_bootable");

  device = luaL_checkstring (L, 2);
  partnum = luaL_checkint (L, 3);
  bootable = lua_toboolean (L, 4);

  r = guestfs_part_set_bootable (g, device, partnum, bootable);
  if (r == -1)
    return last_error (L, g);

  return 0;
}

static int
guestfs_lua_part_set_gpt_type (lua_State *L)
{
  int r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  const char *device;
  int partnum;
  const char *guid;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "part_set_gpt_type");

  device = luaL_checkstring (L, 2);
  partnum = luaL_checkint (L, 3);
  guid = luaL_checkstring (L, 4);

  r = guestfs_part_set_gpt_type (g, device, partnum, guid);
  if (r == -1)
    return last_error (L, g);

  return 0;
}

static int
guestfs_lua_part_set_mbr_id (lua_State *L)
{
  int r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  const char *device;
  int partnum;
  int idbyte;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "part_set_mbr_id");

  device = luaL_checkstring (L, 2);
  partnum = luaL_checkint (L, 3);
  idbyte = luaL_checkint (L, 4);

  r = guestfs_part_set_mbr_id (g, device, partnum, idbyte);
  if (r == -1)
    return last_error (L, g);

  return 0;
}

static int
guestfs_lua_part_set_name (lua_State *L)
{
  int r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  const char *device;
  int partnum;
  const char *name;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "part_set_name");

  device = luaL_checkstring (L, 2);
  partnum = luaL_checkint (L, 3);
  name = luaL_checkstring (L, 4);

  r = guestfs_part_set_name (g, device, partnum, name);
  if (r == -1)
    return last_error (L, g);

  return 0;
}

static int
guestfs_lua_part_to_dev (lua_State *L)
{
  char *r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  const char *partition;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "part_to_dev");

  partition = luaL_checkstring (L, 2);

  r = guestfs_part_to_dev (g, partition);
  if (r == NULL)
    return last_error (L, g);

  lua_pushstring (L, r);
  free (r);
  return 1;
}

static int
guestfs_lua_part_to_partnum (lua_State *L)
{
  int r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  const char *partition;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "part_to_partnum");

  partition = luaL_checkstring (L, 2);

  r = guestfs_part_to_partnum (g, partition);
  if (r == -1)
    return last_error (L, g);

  lua_pushinteger (L, r);
  return 1;
}

static int
guestfs_lua_ping_daemon (lua_State *L)
{
  int r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "ping_daemon");


  r = guestfs_ping_daemon (g);
  if (r == -1)
    return last_error (L, g);

  return 0;
}

static int
guestfs_lua_pread (lua_State *L)
{
  char *r;
  size_t size;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  const char *path;
  int count;
  int64_t offset;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "pread");

  path = luaL_checkstring (L, 2);
  count = luaL_checkint (L, 3);
  offset = get_int64 (L, 4);

  r = guestfs_pread (g, path, count, offset, &size);
  if (r == NULL)
    return last_error (L, g);

  lua_pushlstring (L, r, size);
  free (r);
  return 1;
}

static int
guestfs_lua_pread_device (lua_State *L)
{
  char *r;
  size_t size;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  const char *device;
  int count;
  int64_t offset;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "pread_device");

  device = luaL_checkstring (L, 2);
  count = luaL_checkint (L, 3);
  offset = get_int64 (L, 4);

  r = guestfs_pread_device (g, device, count, offset, &size);
  if (r == NULL)
    return last_error (L, g);

  lua_pushlstring (L, r, size);
  free (r);
  return 1;
}

static int
guestfs_lua_pvchange_uuid (lua_State *L)
{
  int r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  const char *device;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "pvchange_uuid");

  device = luaL_checkstring (L, 2);

  r = guestfs_pvchange_uuid (g, device);
  if (r == -1)
    return last_error (L, g);

  return 0;
}

static int
guestfs_lua_pvchange_uuid_all (lua_State *L)
{
  int r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "pvchange_uuid_all");


  r = guestfs_pvchange_uuid_all (g);
  if (r == -1)
    return last_error (L, g);

  return 0;
}

static int
guestfs_lua_pvcreate (lua_State *L)
{
  int r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  const char *device;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "pvcreate");

  device = luaL_checkstring (L, 2);

  r = guestfs_pvcreate (g, device);
  if (r == -1)
    return last_error (L, g);

  return 0;
}

static int
guestfs_lua_pvremove (lua_State *L)
{
  int r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  const char *device;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "pvremove");

  device = luaL_checkstring (L, 2);

  r = guestfs_pvremove (g, device);
  if (r == -1)
    return last_error (L, g);

  return 0;
}

static int
guestfs_lua_pvresize (lua_State *L)
{
  int r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  const char *device;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "pvresize");

  device = luaL_checkstring (L, 2);

  r = guestfs_pvresize (g, device);
  if (r == -1)
    return last_error (L, g);

  return 0;
}

static int
guestfs_lua_pvresize_size (lua_State *L)
{
  int r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  const char *device;
  int64_t size;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "pvresize_size");

  device = luaL_checkstring (L, 2);
  size = get_int64 (L, 3);

  r = guestfs_pvresize_size (g, device, size);
  if (r == -1)
    return last_error (L, g);

  return 0;
}

static int
guestfs_lua_pvs (lua_State *L)
{
  char **r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "pvs");


  r = guestfs_pvs (g);
  if (r == NULL)
    return last_error (L, g);

  push_string_list (L, r);
  guestfs___free_string_list (r);
  return 1;
}

static int
guestfs_lua_pvs_full (lua_State *L)
{
  struct guestfs_lvm_pv_list *r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "pvs_full");


  r = guestfs_pvs_full (g);
  if (r == NULL)
    return last_error (L, g);

  push_lvm_pv_list (L, r);
  guestfs_free_lvm_pv_list (r);
  return 1;
}

static int
guestfs_lua_pvuuid (lua_State *L)
{
  char *r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  const char *device;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "pvuuid");

  device = luaL_checkstring (L, 2);

  r = guestfs_pvuuid (g, device);
  if (r == NULL)
    return last_error (L, g);

  lua_pushstring (L, r);
  free (r);
  return 1;
}

static int
guestfs_lua_pwrite (lua_State *L)
{
  int r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  const char *path;
  const char *content;
  size_t content_size;
  int64_t offset;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "pwrite");

  path = luaL_checkstring (L, 2);
  content = luaL_checklstring (L, 3, &content_size);
  offset = get_int64 (L, 4);

  r = guestfs_pwrite (g, path, content, content_size, offset);
  if (r == -1)
    return last_error (L, g);

  lua_pushinteger (L, r);
  return 1;
}

static int
guestfs_lua_pwrite_device (lua_State *L)
{
  int r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  const char *device;
  const char *content;
  size_t content_size;
  int64_t offset;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "pwrite_device");

  device = luaL_checkstring (L, 2);
  content = luaL_checklstring (L, 3, &content_size);
  offset = get_int64 (L, 4);

  r = guestfs_pwrite_device (g, device, content, content_size, offset);
  if (r == -1)
    return last_error (L, g);

  lua_pushinteger (L, r);
  return 1;
}

static int
guestfs_lua_read_file (lua_State *L)
{
  char *r;
  size_t size;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  const char *path;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "read_file");

  path = luaL_checkstring (L, 2);

  r = guestfs_read_file (g, path, &size);
  if (r == NULL)
    return last_error (L, g);

  lua_pushlstring (L, r, size);
  free (r);
  return 1;
}

static int
guestfs_lua_read_lines (lua_State *L)
{
  char **r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  const char *path;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "read_lines");

  path = luaL_checkstring (L, 2);

  r = guestfs_read_lines (g, path);
  if (r == NULL)
    return last_error (L, g);

  push_string_list (L, r);
  guestfs___free_string_list (r);
  return 1;
}

static int
guestfs_lua_readdir (lua_State *L)
{
  struct guestfs_dirent_list *r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  const char *dir;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "readdir");

  dir = luaL_checkstring (L, 2);

  r = guestfs_readdir (g, dir);
  if (r == NULL)
    return last_error (L, g);

  push_dirent_list (L, r);
  guestfs_free_dirent_list (r);
  return 1;
}

static int
guestfs_lua_readlink (lua_State *L)
{
  char *r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  const char *path;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "readlink");

  path = luaL_checkstring (L, 2);

  r = guestfs_readlink (g, path);
  if (r == NULL)
    return last_error (L, g);

  lua_pushstring (L, r);
  free (r);
  return 1;
}

static int
guestfs_lua_readlinklist (lua_State *L)
{
  char **r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  const char *path;
  char **names;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "readlinklist");

  path = luaL_checkstring (L, 2);
  names = get_string_list (L, 3);

  r = guestfs_readlinklist (g, path, names);
  free (names);
  if (r == NULL)
    return last_error (L, g);

  push_string_list (L, r);
  guestfs___free_string_list (r);
  return 1;
}

static int
guestfs_lua_realpath (lua_State *L)
{
  char *r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  const char *path;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "realpath");

  path = luaL_checkstring (L, 2);

  r = guestfs_realpath (g, path);
  if (r == NULL)
    return last_error (L, g);

  lua_pushstring (L, r);
  free (r);
  return 1;
}

static int
guestfs_lua_remove_drive (lua_State *L)
{
  int r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  const char *label;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "remove_drive");

  label = luaL_checkstring (L, 2);

  r = guestfs_remove_drive (g, label);
  if (r == -1)
    return last_error (L, g);

  return 0;
}

static int
guestfs_lua_removexattr (lua_State *L)
{
  int r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  const char *xattr;
  const char *path;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "removexattr");

  xattr = luaL_checkstring (L, 2);
  path = luaL_checkstring (L, 3);

  r = guestfs_removexattr (g, xattr, path);
  if (r == -1)
    return last_error (L, g);

  return 0;
}

static int
guestfs_lua_rename (lua_State *L)
{
  int r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  const char *oldpath;
  const char *newpath;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "rename");

  oldpath = luaL_checkstring (L, 2);
  newpath = luaL_checkstring (L, 3);

  r = guestfs_rename (g, oldpath, newpath);
  if (r == -1)
    return last_error (L, g);

  return 0;
}

static int
guestfs_lua_resize2fs (lua_State *L)
{
  int r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  const char *device;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "resize2fs");

  device = luaL_checkstring (L, 2);

  r = guestfs_resize2fs (g, device);
  if (r == -1)
    return last_error (L, g);

  return 0;
}

static int
guestfs_lua_resize2fs_M (lua_State *L)
{
  int r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  const char *device;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "resize2fs_M");

  device = luaL_checkstring (L, 2);

  r = guestfs_resize2fs_M (g, device);
  if (r == -1)
    return last_error (L, g);

  return 0;
}

static int
guestfs_lua_resize2fs_size (lua_State *L)
{
  int r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  const char *device;
  int64_t size;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "resize2fs_size");

  device = luaL_checkstring (L, 2);
  size = get_int64 (L, 3);

  r = guestfs_resize2fs_size (g, device, size);
  if (r == -1)
    return last_error (L, g);

  return 0;
}

static int
guestfs_lua_rm (lua_State *L)
{
  int r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  const char *path;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "rm");

  path = luaL_checkstring (L, 2);

  r = guestfs_rm (g, path);
  if (r == -1)
    return last_error (L, g);

  return 0;
}

static int
guestfs_lua_rm_f (lua_State *L)
{
  int r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  const char *path;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "rm_f");

  path = luaL_checkstring (L, 2);

  r = guestfs_rm_f (g, path);
  if (r == -1)
    return last_error (L, g);

  return 0;
}

static int
guestfs_lua_rm_rf (lua_State *L)
{
  int r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  const char *path;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "rm_rf");

  path = luaL_checkstring (L, 2);

  r = guestfs_rm_rf (g, path);
  if (r == -1)
    return last_error (L, g);

  return 0;
}

static int
guestfs_lua_rmdir (lua_State *L)
{
  int r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  const char *path;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "rmdir");

  path = luaL_checkstring (L, 2);

  r = guestfs_rmdir (g, path);
  if (r == -1)
    return last_error (L, g);

  return 0;
}

static int
guestfs_lua_rmmountpoint (lua_State *L)
{
  int r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  const char *exemptpath;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "rmmountpoint");

  exemptpath = luaL_checkstring (L, 2);

  r = guestfs_rmmountpoint (g, exemptpath);
  if (r == -1)
    return last_error (L, g);

  return 0;
}

static int
guestfs_lua_rsync (lua_State *L)
{
  int r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  const char *src;
  const char *dest;
  struct guestfs_rsync_argv optargs_s = { .bitmask = 0 };
  struct guestfs_rsync_argv *optargs = &optargs_s;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "rsync");

  src = luaL_checkstring (L, 2);
  dest = luaL_checkstring (L, 3);

  /* Check for optional arguments, encoded in a table. */
  if (lua_type (L, 4) == LUA_TTABLE) {
    OPTARG_IF_SET (4, "archive",
      optargs_s.bitmask |= GUESTFS_RSYNC_ARCHIVE_BITMASK;
      optargs_s.archive = lua_toboolean (L, -1);
    );
    OPTARG_IF_SET (4, "deletedest",
      optargs_s.bitmask |= GUESTFS_RSYNC_DELETEDEST_BITMASK;
      optargs_s.deletedest = lua_toboolean (L, -1);
    );
  }

  r = guestfs_rsync_argv (g, src, dest, optargs);
  if (r == -1)
    return last_error (L, g);

  return 0;
}

static int
guestfs_lua_rsync_in (lua_State *L)
{
  int r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  const char *remote;
  const char *dest;
  struct guestfs_rsync_in_argv optargs_s = { .bitmask = 0 };
  struct guestfs_rsync_in_argv *optargs = &optargs_s;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "rsync_in");

  remote = luaL_checkstring (L, 2);
  dest = luaL_checkstring (L, 3);

  /* Check for optional arguments, encoded in a table. */
  if (lua_type (L, 4) == LUA_TTABLE) {
    OPTARG_IF_SET (4, "archive",
      optargs_s.bitmask |= GUESTFS_RSYNC_IN_ARCHIVE_BITMASK;
      optargs_s.archive = lua_toboolean (L, -1);
    );
    OPTARG_IF_SET (4, "deletedest",
      optargs_s.bitmask |= GUESTFS_RSYNC_IN_DELETEDEST_BITMASK;
      optargs_s.deletedest = lua_toboolean (L, -1);
    );
  }

  r = guestfs_rsync_in_argv (g, remote, dest, optargs);
  if (r == -1)
    return last_error (L, g);

  return 0;
}

static int
guestfs_lua_rsync_out (lua_State *L)
{
  int r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  const char *src;
  const char *remote;
  struct guestfs_rsync_out_argv optargs_s = { .bitmask = 0 };
  struct guestfs_rsync_out_argv *optargs = &optargs_s;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "rsync_out");

  src = luaL_checkstring (L, 2);
  remote = luaL_checkstring (L, 3);

  /* Check for optional arguments, encoded in a table. */
  if (lua_type (L, 4) == LUA_TTABLE) {
    OPTARG_IF_SET (4, "archive",
      optargs_s.bitmask |= GUESTFS_RSYNC_OUT_ARCHIVE_BITMASK;
      optargs_s.archive = lua_toboolean (L, -1);
    );
    OPTARG_IF_SET (4, "deletedest",
      optargs_s.bitmask |= GUESTFS_RSYNC_OUT_DELETEDEST_BITMASK;
      optargs_s.deletedest = lua_toboolean (L, -1);
    );
  }

  r = guestfs_rsync_out_argv (g, src, remote, optargs);
  if (r == -1)
    return last_error (L, g);

  return 0;
}

static int
guestfs_lua_scrub_device (lua_State *L)
{
  int r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  const char *device;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "scrub_device");

  device = luaL_checkstring (L, 2);

  r = guestfs_scrub_device (g, device);
  if (r == -1)
    return last_error (L, g);

  return 0;
}

static int
guestfs_lua_scrub_file (lua_State *L)
{
  int r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  const char *file;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "scrub_file");

  file = luaL_checkstring (L, 2);

  r = guestfs_scrub_file (g, file);
  if (r == -1)
    return last_error (L, g);

  return 0;
}

static int
guestfs_lua_scrub_freespace (lua_State *L)
{
  int r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  const char *dir;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "scrub_freespace");

  dir = luaL_checkstring (L, 2);

  r = guestfs_scrub_freespace (g, dir);
  if (r == -1)
    return last_error (L, g);

  return 0;
}

static int
guestfs_lua_set_append (lua_State *L)
{
  int r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  const char *append;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "set_append");

  append = luaL_optstring (L, 2, NULL);

  r = guestfs_set_append (g, append);
  if (r == -1)
    return last_error (L, g);

  return 0;
}

static int
guestfs_lua_set_attach_method (lua_State *L)
{
  int r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  const char *attachmethod;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "set_attach_method");

  attachmethod = luaL_checkstring (L, 2);

  r = guestfs_set_attach_method (g, attachmethod);
  if (r == -1)
    return last_error (L, g);

  return 0;
}

static int
guestfs_lua_set_autosync (lua_State *L)
{
  int r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  int autosync;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "set_autosync");

  autosync = lua_toboolean (L, 2);

  r = guestfs_set_autosync (g, autosync);
  if (r == -1)
    return last_error (L, g);

  return 0;
}

static int
guestfs_lua_set_cachedir (lua_State *L)
{
  int r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  const char *cachedir;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "set_cachedir");

  cachedir = luaL_optstring (L, 2, NULL);

  r = guestfs_set_cachedir (g, cachedir);
  if (r == -1)
    return last_error (L, g);

  return 0;
}

static int
guestfs_lua_set_direct (lua_State *L)
{
  int r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  int direct;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "set_direct");

  direct = lua_toboolean (L, 2);

  r = guestfs_set_direct (g, direct);
  if (r == -1)
    return last_error (L, g);

  return 0;
}

static int
guestfs_lua_set_e2attrs (lua_State *L)
{
  int r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  const char *file;
  const char *attrs;
  struct guestfs_set_e2attrs_argv optargs_s = { .bitmask = 0 };
  struct guestfs_set_e2attrs_argv *optargs = &optargs_s;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "set_e2attrs");

  file = luaL_checkstring (L, 2);
  attrs = luaL_checkstring (L, 3);

  /* Check for optional arguments, encoded in a table. */
  if (lua_type (L, 4) == LUA_TTABLE) {
    OPTARG_IF_SET (4, "clear",
      optargs_s.bitmask |= GUESTFS_SET_E2ATTRS_CLEAR_BITMASK;
      optargs_s.clear = lua_toboolean (L, -1);
    );
  }

  r = guestfs_set_e2attrs_argv (g, file, attrs, optargs);
  if (r == -1)
    return last_error (L, g);

  return 0;
}

static int
guestfs_lua_set_e2generation (lua_State *L)
{
  int r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  const char *file;
  int64_t generation;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "set_e2generation");

  file = luaL_checkstring (L, 2);
  generation = get_int64 (L, 3);

  r = guestfs_set_e2generation (g, file, generation);
  if (r == -1)
    return last_error (L, g);

  return 0;
}

static int
guestfs_lua_set_e2label (lua_State *L)
{
  int r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  const char *device;
  const char *label;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "set_e2label");

  device = luaL_checkstring (L, 2);
  label = luaL_checkstring (L, 3);

  r = guestfs_set_e2label (g, device, label);
  if (r == -1)
    return last_error (L, g);

  return 0;
}

static int
guestfs_lua_set_e2uuid (lua_State *L)
{
  int r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  const char *device;
  const char *uuid;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "set_e2uuid");

  device = luaL_checkstring (L, 2);
  uuid = luaL_checkstring (L, 3);

  r = guestfs_set_e2uuid (g, device, uuid);
  if (r == -1)
    return last_error (L, g);

  return 0;
}

static int
guestfs_lua_set_label (lua_State *L)
{
  int r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  const char *mountable;
  const char *label;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "set_label");

  mountable = luaL_checkstring (L, 2);
  label = luaL_checkstring (L, 3);

  r = guestfs_set_label (g, mountable, label);
  if (r == -1)
    return last_error (L, g);

  return 0;
}

static int
guestfs_lua_set_libvirt_requested_credential (lua_State *L)
{
  int r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  int index;
  const char *cred;
  size_t cred_size;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "set_libvirt_requested_credential");

  index = luaL_checkint (L, 2);
  cred = luaL_checklstring (L, 3, &cred_size);

  r = guestfs_set_libvirt_requested_credential (g, index, cred, cred_size);
  if (r == -1)
    return last_error (L, g);

  return 0;
}

static int
guestfs_lua_set_libvirt_supported_credentials (lua_State *L)
{
  int r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  char **creds;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "set_libvirt_supported_credentials");

  creds = get_string_list (L, 2);

  r = guestfs_set_libvirt_supported_credentials (g, creds);
  free (creds);
  if (r == -1)
    return last_error (L, g);

  return 0;
}

static int
guestfs_lua_set_memsize (lua_State *L)
{
  int r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  int memsize;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "set_memsize");

  memsize = luaL_checkint (L, 2);

  r = guestfs_set_memsize (g, memsize);
  if (r == -1)
    return last_error (L, g);

  return 0;
}

static int
guestfs_lua_set_network (lua_State *L)
{
  int r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  int network;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "set_network");

  network = lua_toboolean (L, 2);

  r = guestfs_set_network (g, network);
  if (r == -1)
    return last_error (L, g);

  return 0;
}

static int
guestfs_lua_set_path (lua_State *L)
{
  int r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  const char *searchpath;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "set_path");

  searchpath = luaL_optstring (L, 2, NULL);

  r = guestfs_set_path (g, searchpath);
  if (r == -1)
    return last_error (L, g);

  return 0;
}

static int
guestfs_lua_set_pgroup (lua_State *L)
{
  int r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  int pgroup;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "set_pgroup");

  pgroup = lua_toboolean (L, 2);

  r = guestfs_set_pgroup (g, pgroup);
  if (r == -1)
    return last_error (L, g);

  return 0;
}

static int
guestfs_lua_set_qemu (lua_State *L)
{
  int r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  const char *qemu;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "set_qemu");

  qemu = luaL_optstring (L, 2, NULL);

  r = guestfs_set_qemu (g, qemu);
  if (r == -1)
    return last_error (L, g);

  return 0;
}

static int
guestfs_lua_set_recovery_proc (lua_State *L)
{
  int r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  int recoveryproc;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "set_recovery_proc");

  recoveryproc = lua_toboolean (L, 2);

  r = guestfs_set_recovery_proc (g, recoveryproc);
  if (r == -1)
    return last_error (L, g);

  return 0;
}

static int
guestfs_lua_set_selinux (lua_State *L)
{
  int r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  int selinux;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "set_selinux");

  selinux = lua_toboolean (L, 2);

  r = guestfs_set_selinux (g, selinux);
  if (r == -1)
    return last_error (L, g);

  return 0;
}

static int
guestfs_lua_set_smp (lua_State *L)
{
  int r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  int smp;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "set_smp");

  smp = luaL_checkint (L, 2);

  r = guestfs_set_smp (g, smp);
  if (r == -1)
    return last_error (L, g);

  return 0;
}

static int
guestfs_lua_set_tmpdir (lua_State *L)
{
  int r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  const char *tmpdir;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "set_tmpdir");

  tmpdir = luaL_optstring (L, 2, NULL);

  r = guestfs_set_tmpdir (g, tmpdir);
  if (r == -1)
    return last_error (L, g);

  return 0;
}

static int
guestfs_lua_set_trace (lua_State *L)
{
  int r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  int trace;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "set_trace");

  trace = lua_toboolean (L, 2);

  r = guestfs_set_trace (g, trace);
  if (r == -1)
    return last_error (L, g);

  return 0;
}

static int
guestfs_lua_set_verbose (lua_State *L)
{
  int r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  int verbose;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "set_verbose");

  verbose = lua_toboolean (L, 2);

  r = guestfs_set_verbose (g, verbose);
  if (r == -1)
    return last_error (L, g);

  return 0;
}

static int
guestfs_lua_setcon (lua_State *L)
{
  int r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  const char *context;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "setcon");

  context = luaL_checkstring (L, 2);

  r = guestfs_setcon (g, context);
  if (r == -1)
    return last_error (L, g);

  return 0;
}

static int
guestfs_lua_setxattr (lua_State *L)
{
  int r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  const char *xattr;
  const char *val;
  int vallen;
  const char *path;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "setxattr");

  xattr = luaL_checkstring (L, 2);
  val = luaL_checkstring (L, 3);
  vallen = luaL_checkint (L, 4);
  path = luaL_checkstring (L, 5);

  r = guestfs_setxattr (g, xattr, val, vallen, path);
  if (r == -1)
    return last_error (L, g);

  return 0;
}

static int
guestfs_lua_sfdisk (lua_State *L)
{
  int r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  const char *device;
  int cyls;
  int heads;
  int sectors;
  char **lines;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "sfdisk");

  device = luaL_checkstring (L, 2);
  cyls = luaL_checkint (L, 3);
  heads = luaL_checkint (L, 4);
  sectors = luaL_checkint (L, 5);
  lines = get_string_list (L, 6);

  r = guestfs_sfdisk (g, device, cyls, heads, sectors, lines);
  free (lines);
  if (r == -1)
    return last_error (L, g);

  return 0;
}

static int
guestfs_lua_sfdiskM (lua_State *L)
{
  int r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  const char *device;
  char **lines;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "sfdiskM");

  device = luaL_checkstring (L, 2);
  lines = get_string_list (L, 3);

  r = guestfs_sfdiskM (g, device, lines);
  free (lines);
  if (r == -1)
    return last_error (L, g);

  return 0;
}

static int
guestfs_lua_sfdisk_N (lua_State *L)
{
  int r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  const char *device;
  int partnum;
  int cyls;
  int heads;
  int sectors;
  const char *line;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "sfdisk_N");

  device = luaL_checkstring (L, 2);
  partnum = luaL_checkint (L, 3);
  cyls = luaL_checkint (L, 4);
  heads = luaL_checkint (L, 5);
  sectors = luaL_checkint (L, 6);
  line = luaL_checkstring (L, 7);

  r = guestfs_sfdisk_N (g, device, partnum, cyls, heads, sectors, line);
  if (r == -1)
    return last_error (L, g);

  return 0;
}

static int
guestfs_lua_sfdisk_disk_geometry (lua_State *L)
{
  char *r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  const char *device;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "sfdisk_disk_geometry");

  device = luaL_checkstring (L, 2);

  r = guestfs_sfdisk_disk_geometry (g, device);
  if (r == NULL)
    return last_error (L, g);

  lua_pushstring (L, r);
  free (r);
  return 1;
}

static int
guestfs_lua_sfdisk_kernel_geometry (lua_State *L)
{
  char *r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  const char *device;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "sfdisk_kernel_geometry");

  device = luaL_checkstring (L, 2);

  r = guestfs_sfdisk_kernel_geometry (g, device);
  if (r == NULL)
    return last_error (L, g);

  lua_pushstring (L, r);
  free (r);
  return 1;
}

static int
guestfs_lua_sfdisk_l (lua_State *L)
{
  char *r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  const char *device;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "sfdisk_l");

  device = luaL_checkstring (L, 2);

  r = guestfs_sfdisk_l (g, device);
  if (r == NULL)
    return last_error (L, g);

  lua_pushstring (L, r);
  free (r);
  return 1;
}

static int
guestfs_lua_sh (lua_State *L)
{
  char *r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  const char *command;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "sh");

  command = luaL_checkstring (L, 2);

  r = guestfs_sh (g, command);
  if (r == NULL)
    return last_error (L, g);

  lua_pushstring (L, r);
  free (r);
  return 1;
}

static int
guestfs_lua_sh_lines (lua_State *L)
{
  char **r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  const char *command;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "sh_lines");

  command = luaL_checkstring (L, 2);

  r = guestfs_sh_lines (g, command);
  if (r == NULL)
    return last_error (L, g);

  push_string_list (L, r);
  guestfs___free_string_list (r);
  return 1;
}

static int
guestfs_lua_shutdown (lua_State *L)
{
  int r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "shutdown");


  r = guestfs_shutdown (g);
  if (r == -1)
    return last_error (L, g);

  return 0;
}

static int
guestfs_lua_sleep (lua_State *L)
{
  int r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  int secs;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "sleep");

  secs = luaL_checkint (L, 2);

  r = guestfs_sleep (g, secs);
  if (r == -1)
    return last_error (L, g);

  return 0;
}

static int
guestfs_lua_stat (lua_State *L)
{
  struct guestfs_stat *r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  const char *path;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "stat");

  path = luaL_checkstring (L, 2);

  r = guestfs_stat (g, path);
  if (r == NULL)
    return last_error (L, g);

  push_stat (L, r);
  guestfs_free_stat (r);
  return 1;
}

static int
guestfs_lua_statvfs (lua_State *L)
{
  struct guestfs_statvfs *r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  const char *path;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "statvfs");

  path = luaL_checkstring (L, 2);

  r = guestfs_statvfs (g, path);
  if (r == NULL)
    return last_error (L, g);

  push_statvfs (L, r);
  guestfs_free_statvfs (r);
  return 1;
}

static int
guestfs_lua_strings (lua_State *L)
{
  char **r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  const char *path;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "strings");

  path = luaL_checkstring (L, 2);

  r = guestfs_strings (g, path);
  if (r == NULL)
    return last_error (L, g);

  push_string_list (L, r);
  guestfs___free_string_list (r);
  return 1;
}

static int
guestfs_lua_strings_e (lua_State *L)
{
  char **r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  const char *encoding;
  const char *path;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "strings_e");

  encoding = luaL_checkstring (L, 2);
  path = luaL_checkstring (L, 3);

  r = guestfs_strings_e (g, encoding, path);
  if (r == NULL)
    return last_error (L, g);

  push_string_list (L, r);
  guestfs___free_string_list (r);
  return 1;
}

static int
guestfs_lua_swapoff_device (lua_State *L)
{
  int r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  const char *device;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "swapoff_device");

  device = luaL_checkstring (L, 2);

  r = guestfs_swapoff_device (g, device);
  if (r == -1)
    return last_error (L, g);

  return 0;
}

static int
guestfs_lua_swapoff_file (lua_State *L)
{
  int r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  const char *file;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "swapoff_file");

  file = luaL_checkstring (L, 2);

  r = guestfs_swapoff_file (g, file);
  if (r == -1)
    return last_error (L, g);

  return 0;
}

static int
guestfs_lua_swapoff_label (lua_State *L)
{
  int r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  const char *label;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "swapoff_label");

  label = luaL_checkstring (L, 2);

  r = guestfs_swapoff_label (g, label);
  if (r == -1)
    return last_error (L, g);

  return 0;
}

static int
guestfs_lua_swapoff_uuid (lua_State *L)
{
  int r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  const char *uuid;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "swapoff_uuid");

  uuid = luaL_checkstring (L, 2);

  r = guestfs_swapoff_uuid (g, uuid);
  if (r == -1)
    return last_error (L, g);

  return 0;
}

static int
guestfs_lua_swapon_device (lua_State *L)
{
  int r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  const char *device;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "swapon_device");

  device = luaL_checkstring (L, 2);

  r = guestfs_swapon_device (g, device);
  if (r == -1)
    return last_error (L, g);

  return 0;
}

static int
guestfs_lua_swapon_file (lua_State *L)
{
  int r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  const char *file;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "swapon_file");

  file = luaL_checkstring (L, 2);

  r = guestfs_swapon_file (g, file);
  if (r == -1)
    return last_error (L, g);

  return 0;
}

static int
guestfs_lua_swapon_label (lua_State *L)
{
  int r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  const char *label;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "swapon_label");

  label = luaL_checkstring (L, 2);

  r = guestfs_swapon_label (g, label);
  if (r == -1)
    return last_error (L, g);

  return 0;
}

static int
guestfs_lua_swapon_uuid (lua_State *L)
{
  int r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  const char *uuid;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "swapon_uuid");

  uuid = luaL_checkstring (L, 2);

  r = guestfs_swapon_uuid (g, uuid);
  if (r == -1)
    return last_error (L, g);

  return 0;
}

static int
guestfs_lua_sync (lua_State *L)
{
  int r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "sync");


  r = guestfs_sync (g);
  if (r == -1)
    return last_error (L, g);

  return 0;
}

static int
guestfs_lua_tail (lua_State *L)
{
  char **r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  const char *path;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "tail");

  path = luaL_checkstring (L, 2);

  r = guestfs_tail (g, path);
  if (r == NULL)
    return last_error (L, g);

  push_string_list (L, r);
  guestfs___free_string_list (r);
  return 1;
}

static int
guestfs_lua_tail_n (lua_State *L)
{
  char **r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  int nrlines;
  const char *path;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "tail_n");

  nrlines = luaL_checkint (L, 2);
  path = luaL_checkstring (L, 3);

  r = guestfs_tail_n (g, nrlines, path);
  if (r == NULL)
    return last_error (L, g);

  push_string_list (L, r);
  guestfs___free_string_list (r);
  return 1;
}

static int
guestfs_lua_tar_in (lua_State *L)
{
  int r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  const char *tarfile;
  const char *directory;
  struct guestfs_tar_in_opts_argv optargs_s = { .bitmask = 0 };
  struct guestfs_tar_in_opts_argv *optargs = &optargs_s;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "tar_in");

  tarfile = luaL_checkstring (L, 2);
  directory = luaL_checkstring (L, 3);

  /* Check for optional arguments, encoded in a table. */
  if (lua_type (L, 4) == LUA_TTABLE) {
    OPTARG_IF_SET (4, "compress",
      optargs_s.bitmask |= GUESTFS_TAR_IN_OPTS_COMPRESS_BITMASK;
      optargs_s.compress = luaL_checkstring (L, -1);
    );
  }

  r = guestfs_tar_in_opts_argv (g, tarfile, directory, optargs);
  if (r == -1)
    return last_error (L, g);

  return 0;
}

static int
guestfs_lua_tar_out (lua_State *L)
{
  int r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  const char *directory;
  const char *tarfile;
  struct guestfs_tar_out_opts_argv optargs_s = { .bitmask = 0 };
  struct guestfs_tar_out_opts_argv *optargs = &optargs_s;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "tar_out");

  directory = luaL_checkstring (L, 2);
  tarfile = luaL_checkstring (L, 3);

  /* Check for optional arguments, encoded in a table. */
  if (lua_type (L, 4) == LUA_TTABLE) {
    OPTARG_IF_SET (4, "compress",
      optargs_s.bitmask |= GUESTFS_TAR_OUT_OPTS_COMPRESS_BITMASK;
      optargs_s.compress = luaL_checkstring (L, -1);
    );
    OPTARG_IF_SET (4, "numericowner",
      optargs_s.bitmask |= GUESTFS_TAR_OUT_OPTS_NUMERICOWNER_BITMASK;
      optargs_s.numericowner = lua_toboolean (L, -1);
    );
    OPTARG_IF_SET (4, "excludes",
      optargs_s.bitmask |= GUESTFS_TAR_OUT_OPTS_EXCLUDES_BITMASK;
      optargs_s.excludes = get_string_list (L, -1);
    );
  }

  r = guestfs_tar_out_opts_argv (g, directory, tarfile, optargs);
  free ((char *) optargs_s.excludes);
  if (r == -1)
    return last_error (L, g);

  return 0;
}

static int
guestfs_lua_tgz_in (lua_State *L)
{
  int r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  const char *tarball;
  const char *directory;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "tgz_in");

  tarball = luaL_checkstring (L, 2);
  directory = luaL_checkstring (L, 3);

  r = guestfs_tgz_in (g, tarball, directory);
  if (r == -1)
    return last_error (L, g);

  return 0;
}

static int
guestfs_lua_tgz_out (lua_State *L)
{
  int r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  const char *directory;
  const char *tarball;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "tgz_out");

  directory = luaL_checkstring (L, 2);
  tarball = luaL_checkstring (L, 3);

  r = guestfs_tgz_out (g, directory, tarball);
  if (r == -1)
    return last_error (L, g);

  return 0;
}

static int
guestfs_lua_touch (lua_State *L)
{
  int r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  const char *path;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "touch");

  path = luaL_checkstring (L, 2);

  r = guestfs_touch (g, path);
  if (r == -1)
    return last_error (L, g);

  return 0;
}

static int
guestfs_lua_truncate (lua_State *L)
{
  int r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  const char *path;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "truncate");

  path = luaL_checkstring (L, 2);

  r = guestfs_truncate (g, path);
  if (r == -1)
    return last_error (L, g);

  return 0;
}

static int
guestfs_lua_truncate_size (lua_State *L)
{
  int r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  const char *path;
  int64_t size;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "truncate_size");

  path = luaL_checkstring (L, 2);
  size = get_int64 (L, 3);

  r = guestfs_truncate_size (g, path, size);
  if (r == -1)
    return last_error (L, g);

  return 0;
}

static int
guestfs_lua_tune2fs (lua_State *L)
{
  int r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  const char *device;
  struct guestfs_tune2fs_argv optargs_s = { .bitmask = 0 };
  struct guestfs_tune2fs_argv *optargs = &optargs_s;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "tune2fs");

  device = luaL_checkstring (L, 2);

  /* Check for optional arguments, encoded in a table. */
  if (lua_type (L, 3) == LUA_TTABLE) {
    OPTARG_IF_SET (3, "force",
      optargs_s.bitmask |= GUESTFS_TUNE2FS_FORCE_BITMASK;
      optargs_s.force = lua_toboolean (L, -1);
    );
    OPTARG_IF_SET (3, "maxmountcount",
      optargs_s.bitmask |= GUESTFS_TUNE2FS_MAXMOUNTCOUNT_BITMASK;
      optargs_s.maxmountcount = luaL_checkint (L, -1);
    );
    OPTARG_IF_SET (3, "mountcount",
      optargs_s.bitmask |= GUESTFS_TUNE2FS_MOUNTCOUNT_BITMASK;
      optargs_s.mountcount = luaL_checkint (L, -1);
    );
    OPTARG_IF_SET (3, "errorbehavior",
      optargs_s.bitmask |= GUESTFS_TUNE2FS_ERRORBEHAVIOR_BITMASK;
      optargs_s.errorbehavior = luaL_checkstring (L, -1);
    );
    OPTARG_IF_SET (3, "group",
      optargs_s.bitmask |= GUESTFS_TUNE2FS_GROUP_BITMASK;
      optargs_s.group = get_int64 (L, -1);
    );
    OPTARG_IF_SET (3, "intervalbetweenchecks",
      optargs_s.bitmask |= GUESTFS_TUNE2FS_INTERVALBETWEENCHECKS_BITMASK;
      optargs_s.intervalbetweenchecks = luaL_checkint (L, -1);
    );
    OPTARG_IF_SET (3, "reservedblockspercentage",
      optargs_s.bitmask |= GUESTFS_TUNE2FS_RESERVEDBLOCKSPERCENTAGE_BITMASK;
      optargs_s.reservedblockspercentage = luaL_checkint (L, -1);
    );
    OPTARG_IF_SET (3, "lastmounteddirectory",
      optargs_s.bitmask |= GUESTFS_TUNE2FS_LASTMOUNTEDDIRECTORY_BITMASK;
      optargs_s.lastmounteddirectory = luaL_checkstring (L, -1);
    );
    OPTARG_IF_SET (3, "reservedblockscount",
      optargs_s.bitmask |= GUESTFS_TUNE2FS_RESERVEDBLOCKSCOUNT_BITMASK;
      optargs_s.reservedblockscount = get_int64 (L, -1);
    );
    OPTARG_IF_SET (3, "user",
      optargs_s.bitmask |= GUESTFS_TUNE2FS_USER_BITMASK;
      optargs_s.user = get_int64 (L, -1);
    );
  }

  r = guestfs_tune2fs_argv (g, device, optargs);
  if (r == -1)
    return last_error (L, g);

  return 0;
}

static int
guestfs_lua_tune2fs_l (lua_State *L)
{
  char **r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  const char *device;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "tune2fs_l");

  device = luaL_checkstring (L, 2);

  r = guestfs_tune2fs_l (g, device);
  if (r == NULL)
    return last_error (L, g);

  push_table (L, r);
  guestfs___free_string_list (r);
  return 1;
}

static int
guestfs_lua_txz_in (lua_State *L)
{
  int r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  const char *tarball;
  const char *directory;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "txz_in");

  tarball = luaL_checkstring (L, 2);
  directory = luaL_checkstring (L, 3);

  r = guestfs_txz_in (g, tarball, directory);
  if (r == -1)
    return last_error (L, g);

  return 0;
}

static int
guestfs_lua_txz_out (lua_State *L)
{
  int r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  const char *directory;
  const char *tarball;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "txz_out");

  directory = luaL_checkstring (L, 2);
  tarball = luaL_checkstring (L, 3);

  r = guestfs_txz_out (g, directory, tarball);
  if (r == -1)
    return last_error (L, g);

  return 0;
}

static int
guestfs_lua_umask (lua_State *L)
{
  int r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  int mask;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "umask");

  mask = luaL_checkint (L, 2);

  r = guestfs_umask (g, mask);
  if (r == -1)
    return last_error (L, g);

  lua_pushinteger (L, r);
  return 1;
}

static int
guestfs_lua_umount (lua_State *L)
{
  int r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  const char *pathordevice;
  struct guestfs_umount_opts_argv optargs_s = { .bitmask = 0 };
  struct guestfs_umount_opts_argv *optargs = &optargs_s;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "umount");

  pathordevice = luaL_checkstring (L, 2);

  /* Check for optional arguments, encoded in a table. */
  if (lua_type (L, 3) == LUA_TTABLE) {
    OPTARG_IF_SET (3, "force",
      optargs_s.bitmask |= GUESTFS_UMOUNT_OPTS_FORCE_BITMASK;
      optargs_s.force = lua_toboolean (L, -1);
    );
    OPTARG_IF_SET (3, "lazyunmount",
      optargs_s.bitmask |= GUESTFS_UMOUNT_OPTS_LAZYUNMOUNT_BITMASK;
      optargs_s.lazyunmount = lua_toboolean (L, -1);
    );
  }

  r = guestfs_umount_opts_argv (g, pathordevice, optargs);
  if (r == -1)
    return last_error (L, g);

  return 0;
}

static int
guestfs_lua_umount_all (lua_State *L)
{
  int r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "umount_all");


  r = guestfs_umount_all (g);
  if (r == -1)
    return last_error (L, g);

  return 0;
}

static int
guestfs_lua_umount_local (lua_State *L)
{
  int r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  struct guestfs_umount_local_argv optargs_s = { .bitmask = 0 };
  struct guestfs_umount_local_argv *optargs = &optargs_s;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "umount_local");


  /* Check for optional arguments, encoded in a table. */
  if (lua_type (L, 2) == LUA_TTABLE) {
    OPTARG_IF_SET (2, "retry",
      optargs_s.bitmask |= GUESTFS_UMOUNT_LOCAL_RETRY_BITMASK;
      optargs_s.retry = lua_toboolean (L, -1);
    );
  }

  r = guestfs_umount_local_argv (g, optargs);
  if (r == -1)
    return last_error (L, g);

  return 0;
}

static int
guestfs_lua_upload (lua_State *L)
{
  int r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  const char *filename;
  const char *remotefilename;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "upload");

  filename = luaL_checkstring (L, 2);
  remotefilename = luaL_checkstring (L, 3);

  r = guestfs_upload (g, filename, remotefilename);
  if (r == -1)
    return last_error (L, g);

  return 0;
}

static int
guestfs_lua_upload_offset (lua_State *L)
{
  int r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  const char *filename;
  const char *remotefilename;
  int64_t offset;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "upload_offset");

  filename = luaL_checkstring (L, 2);
  remotefilename = luaL_checkstring (L, 3);
  offset = get_int64 (L, 4);

  r = guestfs_upload_offset (g, filename, remotefilename, offset);
  if (r == -1)
    return last_error (L, g);

  return 0;
}

static int
guestfs_lua_user_cancel (lua_State *L)
{
  int r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "user_cancel");


  r = guestfs_user_cancel (g);
  if (r == -1)
    return last_error (L, g);

  return 0;
}

static int
guestfs_lua_utimens (lua_State *L)
{
  int r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  const char *path;
  int64_t atsecs;
  int64_t atnsecs;
  int64_t mtsecs;
  int64_t mtnsecs;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "utimens");

  path = luaL_checkstring (L, 2);
  atsecs = get_int64 (L, 3);
  atnsecs = get_int64 (L, 4);
  mtsecs = get_int64 (L, 5);
  mtnsecs = get_int64 (L, 6);

  r = guestfs_utimens (g, path, atsecs, atnsecs, mtsecs, mtnsecs);
  if (r == -1)
    return last_error (L, g);

  return 0;
}

static int
guestfs_lua_utsname (lua_State *L)
{
  struct guestfs_utsname *r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "utsname");


  r = guestfs_utsname (g);
  if (r == NULL)
    return last_error (L, g);

  push_utsname (L, r);
  guestfs_free_utsname (r);
  return 1;
}

static int
guestfs_lua_version (lua_State *L)
{
  struct guestfs_version *r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "version");


  r = guestfs_version (g);
  if (r == NULL)
    return last_error (L, g);

  push_version (L, r);
  guestfs_free_version (r);
  return 1;
}

static int
guestfs_lua_vfs_label (lua_State *L)
{
  char *r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  const char *mountable;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "vfs_label");

  mountable = luaL_checkstring (L, 2);

  r = guestfs_vfs_label (g, mountable);
  if (r == NULL)
    return last_error (L, g);

  lua_pushstring (L, r);
  free (r);
  return 1;
}

static int
guestfs_lua_vfs_type (lua_State *L)
{
  char *r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  const char *mountable;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "vfs_type");

  mountable = luaL_checkstring (L, 2);

  r = guestfs_vfs_type (g, mountable);
  if (r == NULL)
    return last_error (L, g);

  lua_pushstring (L, r);
  free (r);
  return 1;
}

static int
guestfs_lua_vfs_uuid (lua_State *L)
{
  char *r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  const char *mountable;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "vfs_uuid");

  mountable = luaL_checkstring (L, 2);

  r = guestfs_vfs_uuid (g, mountable);
  if (r == NULL)
    return last_error (L, g);

  lua_pushstring (L, r);
  free (r);
  return 1;
}

static int
guestfs_lua_vg_activate (lua_State *L)
{
  int r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  int activate;
  char **volgroups;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "vg_activate");

  activate = lua_toboolean (L, 2);
  volgroups = get_string_list (L, 3);

  r = guestfs_vg_activate (g, activate, volgroups);
  free (volgroups);
  if (r == -1)
    return last_error (L, g);

  return 0;
}

static int
guestfs_lua_vg_activate_all (lua_State *L)
{
  int r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  int activate;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "vg_activate_all");

  activate = lua_toboolean (L, 2);

  r = guestfs_vg_activate_all (g, activate);
  if (r == -1)
    return last_error (L, g);

  return 0;
}

static int
guestfs_lua_vgchange_uuid (lua_State *L)
{
  int r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  const char *vg;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "vgchange_uuid");

  vg = luaL_checkstring (L, 2);

  r = guestfs_vgchange_uuid (g, vg);
  if (r == -1)
    return last_error (L, g);

  return 0;
}

static int
guestfs_lua_vgchange_uuid_all (lua_State *L)
{
  int r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "vgchange_uuid_all");


  r = guestfs_vgchange_uuid_all (g);
  if (r == -1)
    return last_error (L, g);

  return 0;
}

static int
guestfs_lua_vgcreate (lua_State *L)
{
  int r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  const char *volgroup;
  char **physvols;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "vgcreate");

  volgroup = luaL_checkstring (L, 2);
  physvols = get_string_list (L, 3);

  r = guestfs_vgcreate (g, volgroup, physvols);
  free (physvols);
  if (r == -1)
    return last_error (L, g);

  return 0;
}

static int
guestfs_lua_vglvuuids (lua_State *L)
{
  char **r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  const char *vgname;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "vglvuuids");

  vgname = luaL_checkstring (L, 2);

  r = guestfs_vglvuuids (g, vgname);
  if (r == NULL)
    return last_error (L, g);

  push_string_list (L, r);
  guestfs___free_string_list (r);
  return 1;
}

static int
guestfs_lua_vgmeta (lua_State *L)
{
  char *r;
  size_t size;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  const char *vgname;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "vgmeta");

  vgname = luaL_checkstring (L, 2);

  r = guestfs_vgmeta (g, vgname, &size);
  if (r == NULL)
    return last_error (L, g);

  lua_pushlstring (L, r, size);
  free (r);
  return 1;
}

static int
guestfs_lua_vgpvuuids (lua_State *L)
{
  char **r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  const char *vgname;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "vgpvuuids");

  vgname = luaL_checkstring (L, 2);

  r = guestfs_vgpvuuids (g, vgname);
  if (r == NULL)
    return last_error (L, g);

  push_string_list (L, r);
  guestfs___free_string_list (r);
  return 1;
}

static int
guestfs_lua_vgremove (lua_State *L)
{
  int r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  const char *vgname;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "vgremove");

  vgname = luaL_checkstring (L, 2);

  r = guestfs_vgremove (g, vgname);
  if (r == -1)
    return last_error (L, g);

  return 0;
}

static int
guestfs_lua_vgrename (lua_State *L)
{
  int r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  const char *volgroup;
  const char *newvolgroup;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "vgrename");

  volgroup = luaL_checkstring (L, 2);
  newvolgroup = luaL_checkstring (L, 3);

  r = guestfs_vgrename (g, volgroup, newvolgroup);
  if (r == -1)
    return last_error (L, g);

  return 0;
}

static int
guestfs_lua_vgs (lua_State *L)
{
  char **r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "vgs");


  r = guestfs_vgs (g);
  if (r == NULL)
    return last_error (L, g);

  push_string_list (L, r);
  guestfs___free_string_list (r);
  return 1;
}

static int
guestfs_lua_vgs_full (lua_State *L)
{
  struct guestfs_lvm_vg_list *r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "vgs_full");


  r = guestfs_vgs_full (g);
  if (r == NULL)
    return last_error (L, g);

  push_lvm_vg_list (L, r);
  guestfs_free_lvm_vg_list (r);
  return 1;
}

static int
guestfs_lua_vgscan (lua_State *L)
{
  int r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "vgscan");


  r = guestfs_vgscan (g);
  if (r == -1)
    return last_error (L, g);

  return 0;
}

static int
guestfs_lua_vguuid (lua_State *L)
{
  char *r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  const char *vgname;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "vguuid");

  vgname = luaL_checkstring (L, 2);

  r = guestfs_vguuid (g, vgname);
  if (r == NULL)
    return last_error (L, g);

  lua_pushstring (L, r);
  free (r);
  return 1;
}

static int
guestfs_lua_wait_ready (lua_State *L)
{
  int r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "wait_ready");


  r = guestfs_wait_ready (g);
  if (r == -1)
    return last_error (L, g);

  return 0;
}

static int
guestfs_lua_wc_c (lua_State *L)
{
  int r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  const char *path;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "wc_c");

  path = luaL_checkstring (L, 2);

  r = guestfs_wc_c (g, path);
  if (r == -1)
    return last_error (L, g);

  lua_pushinteger (L, r);
  return 1;
}

static int
guestfs_lua_wc_l (lua_State *L)
{
  int r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  const char *path;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "wc_l");

  path = luaL_checkstring (L, 2);

  r = guestfs_wc_l (g, path);
  if (r == -1)
    return last_error (L, g);

  lua_pushinteger (L, r);
  return 1;
}

static int
guestfs_lua_wc_w (lua_State *L)
{
  int r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  const char *path;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "wc_w");

  path = luaL_checkstring (L, 2);

  r = guestfs_wc_w (g, path);
  if (r == -1)
    return last_error (L, g);

  lua_pushinteger (L, r);
  return 1;
}

static int
guestfs_lua_wipefs (lua_State *L)
{
  int r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  const char *device;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "wipefs");

  device = luaL_checkstring (L, 2);

  r = guestfs_wipefs (g, device);
  if (r == -1)
    return last_error (L, g);

  return 0;
}

static int
guestfs_lua_write (lua_State *L)
{
  int r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  const char *path;
  const char *content;
  size_t content_size;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "write");

  path = luaL_checkstring (L, 2);
  content = luaL_checklstring (L, 3, &content_size);

  r = guestfs_write (g, path, content, content_size);
  if (r == -1)
    return last_error (L, g);

  return 0;
}

static int
guestfs_lua_write_append (lua_State *L)
{
  int r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  const char *path;
  const char *content;
  size_t content_size;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "write_append");

  path = luaL_checkstring (L, 2);
  content = luaL_checklstring (L, 3, &content_size);

  r = guestfs_write_append (g, path, content, content_size);
  if (r == -1)
    return last_error (L, g);

  return 0;
}

static int
guestfs_lua_write_file (lua_State *L)
{
  int r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  const char *path;
  const char *content;
  int size;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "write_file");

  path = luaL_checkstring (L, 2);
  content = luaL_checkstring (L, 3);
  size = luaL_checkint (L, 4);

  r = guestfs_write_file (g, path, content, size);
  if (r == -1)
    return last_error (L, g);

  return 0;
}

static int
guestfs_lua_xfs_admin (lua_State *L)
{
  int r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  const char *device;
  struct guestfs_xfs_admin_argv optargs_s = { .bitmask = 0 };
  struct guestfs_xfs_admin_argv *optargs = &optargs_s;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "xfs_admin");

  device = luaL_checkstring (L, 2);

  /* Check for optional arguments, encoded in a table. */
  if (lua_type (L, 3) == LUA_TTABLE) {
    OPTARG_IF_SET (3, "extunwritten",
      optargs_s.bitmask |= GUESTFS_XFS_ADMIN_EXTUNWRITTEN_BITMASK;
      optargs_s.extunwritten = lua_toboolean (L, -1);
    );
    OPTARG_IF_SET (3, "imgfile",
      optargs_s.bitmask |= GUESTFS_XFS_ADMIN_IMGFILE_BITMASK;
      optargs_s.imgfile = lua_toboolean (L, -1);
    );
    OPTARG_IF_SET (3, "v2log",
      optargs_s.bitmask |= GUESTFS_XFS_ADMIN_V2LOG_BITMASK;
      optargs_s.v2log = lua_toboolean (L, -1);
    );
    OPTARG_IF_SET (3, "projid32bit",
      optargs_s.bitmask |= GUESTFS_XFS_ADMIN_PROJID32BIT_BITMASK;
      optargs_s.projid32bit = lua_toboolean (L, -1);
    );
    OPTARG_IF_SET (3, "lazycounter",
      optargs_s.bitmask |= GUESTFS_XFS_ADMIN_LAZYCOUNTER_BITMASK;
      optargs_s.lazycounter = lua_toboolean (L, -1);
    );
    OPTARG_IF_SET (3, "label",
      optargs_s.bitmask |= GUESTFS_XFS_ADMIN_LABEL_BITMASK;
      optargs_s.label = luaL_checkstring (L, -1);
    );
    OPTARG_IF_SET (3, "uuid",
      optargs_s.bitmask |= GUESTFS_XFS_ADMIN_UUID_BITMASK;
      optargs_s.uuid = luaL_checkstring (L, -1);
    );
  }

  r = guestfs_xfs_admin_argv (g, device, optargs);
  if (r == -1)
    return last_error (L, g);

  return 0;
}

static int
guestfs_lua_xfs_growfs (lua_State *L)
{
  int r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  const char *path;
  struct guestfs_xfs_growfs_argv optargs_s = { .bitmask = 0 };
  struct guestfs_xfs_growfs_argv *optargs = &optargs_s;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "xfs_growfs");

  path = luaL_checkstring (L, 2);

  /* Check for optional arguments, encoded in a table. */
  if (lua_type (L, 3) == LUA_TTABLE) {
    OPTARG_IF_SET (3, "datasec",
      optargs_s.bitmask |= GUESTFS_XFS_GROWFS_DATASEC_BITMASK;
      optargs_s.datasec = lua_toboolean (L, -1);
    );
    OPTARG_IF_SET (3, "logsec",
      optargs_s.bitmask |= GUESTFS_XFS_GROWFS_LOGSEC_BITMASK;
      optargs_s.logsec = lua_toboolean (L, -1);
    );
    OPTARG_IF_SET (3, "rtsec",
      optargs_s.bitmask |= GUESTFS_XFS_GROWFS_RTSEC_BITMASK;
      optargs_s.rtsec = lua_toboolean (L, -1);
    );
    OPTARG_IF_SET (3, "datasize",
      optargs_s.bitmask |= GUESTFS_XFS_GROWFS_DATASIZE_BITMASK;
      optargs_s.datasize = get_int64 (L, -1);
    );
    OPTARG_IF_SET (3, "logsize",
      optargs_s.bitmask |= GUESTFS_XFS_GROWFS_LOGSIZE_BITMASK;
      optargs_s.logsize = get_int64 (L, -1);
    );
    OPTARG_IF_SET (3, "rtsize",
      optargs_s.bitmask |= GUESTFS_XFS_GROWFS_RTSIZE_BITMASK;
      optargs_s.rtsize = get_int64 (L, -1);
    );
    OPTARG_IF_SET (3, "rtextsize",
      optargs_s.bitmask |= GUESTFS_XFS_GROWFS_RTEXTSIZE_BITMASK;
      optargs_s.rtextsize = get_int64 (L, -1);
    );
    OPTARG_IF_SET (3, "maxpct",
      optargs_s.bitmask |= GUESTFS_XFS_GROWFS_MAXPCT_BITMASK;
      optargs_s.maxpct = luaL_checkint (L, -1);
    );
  }

  r = guestfs_xfs_growfs_argv (g, path, optargs);
  if (r == -1)
    return last_error (L, g);

  return 0;
}

static int
guestfs_lua_xfs_info (lua_State *L)
{
  struct guestfs_xfsinfo *r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  const char *pathordevice;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "xfs_info");

  pathordevice = luaL_checkstring (L, 2);

  r = guestfs_xfs_info (g, pathordevice);
  if (r == NULL)
    return last_error (L, g);

  push_xfsinfo (L, r);
  guestfs_free_xfsinfo (r);
  return 1;
}

static int
guestfs_lua_xfs_repair (lua_State *L)
{
  int r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  const char *device;
  struct guestfs_xfs_repair_argv optargs_s = { .bitmask = 0 };
  struct guestfs_xfs_repair_argv *optargs = &optargs_s;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "xfs_repair");

  device = luaL_checkstring (L, 2);

  /* Check for optional arguments, encoded in a table. */
  if (lua_type (L, 3) == LUA_TTABLE) {
    OPTARG_IF_SET (3, "forcelogzero",
      optargs_s.bitmask |= GUESTFS_XFS_REPAIR_FORCELOGZERO_BITMASK;
      optargs_s.forcelogzero = lua_toboolean (L, -1);
    );
    OPTARG_IF_SET (3, "nomodify",
      optargs_s.bitmask |= GUESTFS_XFS_REPAIR_NOMODIFY_BITMASK;
      optargs_s.nomodify = lua_toboolean (L, -1);
    );
    OPTARG_IF_SET (3, "noprefetch",
      optargs_s.bitmask |= GUESTFS_XFS_REPAIR_NOPREFETCH_BITMASK;
      optargs_s.noprefetch = lua_toboolean (L, -1);
    );
    OPTARG_IF_SET (3, "forcegeometry",
      optargs_s.bitmask |= GUESTFS_XFS_REPAIR_FORCEGEOMETRY_BITMASK;
      optargs_s.forcegeometry = lua_toboolean (L, -1);
    );
    OPTARG_IF_SET (3, "maxmem",
      optargs_s.bitmask |= GUESTFS_XFS_REPAIR_MAXMEM_BITMASK;
      optargs_s.maxmem = get_int64 (L, -1);
    );
    OPTARG_IF_SET (3, "ihashsize",
      optargs_s.bitmask |= GUESTFS_XFS_REPAIR_IHASHSIZE_BITMASK;
      optargs_s.ihashsize = get_int64 (L, -1);
    );
    OPTARG_IF_SET (3, "bhashsize",
      optargs_s.bitmask |= GUESTFS_XFS_REPAIR_BHASHSIZE_BITMASK;
      optargs_s.bhashsize = get_int64 (L, -1);
    );
    OPTARG_IF_SET (3, "agstride",
      optargs_s.bitmask |= GUESTFS_XFS_REPAIR_AGSTRIDE_BITMASK;
      optargs_s.agstride = get_int64 (L, -1);
    );
    OPTARG_IF_SET (3, "logdev",
      optargs_s.bitmask |= GUESTFS_XFS_REPAIR_LOGDEV_BITMASK;
      optargs_s.logdev = luaL_checkstring (L, -1);
    );
    OPTARG_IF_SET (3, "rtdev",
      optargs_s.bitmask |= GUESTFS_XFS_REPAIR_RTDEV_BITMASK;
      optargs_s.rtdev = luaL_checkstring (L, -1);
    );
  }

  r = guestfs_xfs_repair_argv (g, device, optargs);
  if (r == -1)
    return last_error (L, g);

  lua_pushinteger (L, r);
  return 1;
}

static int
guestfs_lua_zegrep (lua_State *L)
{
  char **r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  const char *regex;
  const char *path;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "zegrep");

  regex = luaL_checkstring (L, 2);
  path = luaL_checkstring (L, 3);

  r = guestfs_zegrep (g, regex, path);
  if (r == NULL)
    return last_error (L, g);

  push_string_list (L, r);
  guestfs___free_string_list (r);
  return 1;
}

static int
guestfs_lua_zegrepi (lua_State *L)
{
  char **r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  const char *regex;
  const char *path;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "zegrepi");

  regex = luaL_checkstring (L, 2);
  path = luaL_checkstring (L, 3);

  r = guestfs_zegrepi (g, regex, path);
  if (r == NULL)
    return last_error (L, g);

  push_string_list (L, r);
  guestfs___free_string_list (r);
  return 1;
}

static int
guestfs_lua_zero (lua_State *L)
{
  int r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  const char *device;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "zero");

  device = luaL_checkstring (L, 2);

  r = guestfs_zero (g, device);
  if (r == -1)
    return last_error (L, g);

  return 0;
}

static int
guestfs_lua_zero_device (lua_State *L)
{
  int r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  const char *device;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "zero_device");

  device = luaL_checkstring (L, 2);

  r = guestfs_zero_device (g, device);
  if (r == -1)
    return last_error (L, g);

  return 0;
}

static int
guestfs_lua_zero_free_space (lua_State *L)
{
  int r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  const char *directory;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "zero_free_space");

  directory = luaL_checkstring (L, 2);

  r = guestfs_zero_free_space (g, directory);
  if (r == -1)
    return last_error (L, g);

  return 0;
}

static int
guestfs_lua_zerofree (lua_State *L)
{
  int r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  const char *device;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "zerofree");

  device = luaL_checkstring (L, 2);

  r = guestfs_zerofree (g, device);
  if (r == -1)
    return last_error (L, g);

  return 0;
}

static int
guestfs_lua_zfgrep (lua_State *L)
{
  char **r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  const char *pattern;
  const char *path;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "zfgrep");

  pattern = luaL_checkstring (L, 2);
  path = luaL_checkstring (L, 3);

  r = guestfs_zfgrep (g, pattern, path);
  if (r == NULL)
    return last_error (L, g);

  push_string_list (L, r);
  guestfs___free_string_list (r);
  return 1;
}

static int
guestfs_lua_zfgrepi (lua_State *L)
{
  char **r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  const char *pattern;
  const char *path;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "zfgrepi");

  pattern = luaL_checkstring (L, 2);
  path = luaL_checkstring (L, 3);

  r = guestfs_zfgrepi (g, pattern, path);
  if (r == NULL)
    return last_error (L, g);

  push_string_list (L, r);
  guestfs___free_string_list (r);
  return 1;
}

static int
guestfs_lua_zfile (lua_State *L)
{
  char *r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  const char *meth;
  const char *path;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "zfile");

  meth = luaL_checkstring (L, 2);
  path = luaL_checkstring (L, 3);

  r = guestfs_zfile (g, meth, path);
  if (r == NULL)
    return last_error (L, g);

  lua_pushstring (L, r);
  free (r);
  return 1;
}

static int
guestfs_lua_zgrep (lua_State *L)
{
  char **r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  const char *regex;
  const char *path;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "zgrep");

  regex = luaL_checkstring (L, 2);
  path = luaL_checkstring (L, 3);

  r = guestfs_zgrep (g, regex, path);
  if (r == NULL)
    return last_error (L, g);

  push_string_list (L, r);
  guestfs___free_string_list (r);
  return 1;
}

static int
guestfs_lua_zgrepi (lua_State *L)
{
  char **r;
  struct userdata *u = get_handle (L, 1);
  guestfs_h *g = u->g;
  const char *regex;
  const char *path;

  if (g == NULL)
    luaL_error (L, "Guestfs.%s: handle is closed",
                "zgrepi");

  regex = luaL_checkstring (L, 2);
  path = luaL_checkstring (L, 3);

  r = guestfs_zgrepi (g, regex, path);
  if (r == NULL)
    return last_error (L, g);

  push_string_list (L, r);
  guestfs___free_string_list (r);
  return 1;
}

static struct userdata *
get_handle (lua_State *L, int index)
{
  struct userdata *u;

  u = luaL_checkudata (L, index, GUESTFS_LUA_HANDLE);
  return u;
}

/* NB: caller must free the array, but NOT the strings */
static char **
get_string_list (lua_State *L, int index)
{
  size_t len = lua_objlen (L, index);
  size_t i;
  char **strs;

  strs = malloc ((len+1) * sizeof (char *));
  if (strs == NULL) {
    luaL_error (L, "get_string_list: malloc failed: %s",
                strerror (errno));
    /*NOTREACHED*/
    return NULL;
  }

  for (i = 0; i < len; ++i) {
    lua_rawgeti (L, index, i+1 /* because of base 1 arrays */);
    strs[i] = (char *) luaL_checkstring (L, -1);
    lua_pop (L, 1);
  }
  strs[len] = NULL;

  return strs;
}

static void
push_string_list (lua_State *L, char **strs)
{
  size_t i;

  lua_newtable (L);
  for (i = 0; strs[i] != NULL; ++i) {
    lua_pushstring (L, strs[i]);
    lua_rawseti (L, -2, i+1 /* because of base 1 arrays */);
  }
}

static void
push_table (lua_State *L, char **table)
{
  size_t i;

  lua_newtable (L);
  for (i = 0; table[i] != NULL; i += 2) {
    lua_pushstring (L, table[i]);
    lua_pushstring (L, table[i+1]);
    lua_settable (L, -3);
  }
}

/* Because Lua doesn't have real 64 bit ints (eg. on 32 bit), which
 * sucks, we implement these as strings.  It's left as an exercise to
 * the caller to turn strings to/from integers.
 */
static int64_t
get_int64 (lua_State *L, int index)
{
  int64_t r;
  const char *s;

  switch (lua_type (L, index)) {
  case LUA_TSTRING:
    s = luaL_checkstring (L, index);
    if (sscanf (s, "%" SCNi64, &r) != 1)
      return luaL_error (L, "int64 parameter expected");
    return r;

  case LUA_TNUMBER:
    return luaL_checkint (L, index);

  default:
    return luaL_error (L, "expecting 64 bit integer");
  }
}

static void
push_int64 (lua_State *L, int64_t i64)
{
  char s[64];

  snprintf (s, sizeof s, "%" PRIi64, i64);
  lua_pushstring (L, s);
}

static void
push_int64_array (lua_State *L, const int64_t *array, size_t len)
{
  size_t i;

  lua_newtable (L);
  for (i = 0; i < len; ++i) {
    push_int64 (L, array[i]);
    lua_rawseti (L, -2, i+1 /* because of base 1 arrays */);
  }
}

/* Use Lua tostring method to print out any.  Useful for debugging
 * these bindings, but also used if a callback throws an exception.
 */
static void
print_any (lua_State *L, int index, FILE *out)
{
  lua_getglobal(L, "tostring");
  lua_pushvalue (L, index >= 0 ? index : index-1);
  lua_call (L, 1, 1);
  fprintf (out, "%s", luaL_checkstring (L, -1));
  lua_pop (L, 1);
}

static const char *event_all[] = {
  "close",
  "subprocess_quit",
  "launch_done",
  "progress",
  "appliance",
  "library",
  "trace",
  "enter",
  "libvirt_auth",
  NULL
};

static uint64_t
get_event_bitmask (lua_State *L, int index)
{
  uint64_t bitmask;

  if (lua_isstring (L, index))
    return get_event (L, index);

  bitmask = 0;

  lua_pushnil (L);
  while (lua_next (L, index) != 0) {
    bitmask |= get_event (L, -1);
    lua_pop (L, 1); /* pop value */
  }
  lua_pop (L, 1); /* pop key */

  return bitmask;
}

static uint64_t
get_event (lua_State *L, int index)
{
  int r = luaL_checkoption (L, index, NULL, event_all);

  return UINT64_C(1) << r;
}

static void
push_event (lua_State *L, uint64_t event)
{
  if (event == 1) {
    lua_pushliteral (L, "close");
    return;
  }
  if (event == 2) {
    lua_pushliteral (L, "subprocess_quit");
    return;
  }
  if (event == 4) {
    lua_pushliteral (L, "launch_done");
    return;
  }
  if (event == 8) {
    lua_pushliteral (L, "progress");
    return;
  }
  if (event == 16) {
    lua_pushliteral (L, "appliance");
    return;
  }
  if (event == 32) {
    lua_pushliteral (L, "library");
    return;
  }
  if (event == 64) {
    lua_pushliteral (L, "trace");
    return;
  }
  if (event == 128) {
    lua_pushliteral (L, "enter");
    return;
  }
  if (event == 256) {
    lua_pushliteral (L, "libvirt_auth");
    return;
  }
  abort (); /* should never happen */
}

static void
push_lvm_lv (lua_State *L, struct guestfs_lvm_lv *v)
{
  lua_newtable (L);
  lua_pushliteral (L, "lv_name");
  lua_pushstring (L, v->lv_name);
  lua_settable (L, -3);
  lua_pushliteral (L, "lv_uuid");
  lua_pushlstring (L, v->lv_uuid, 32);
  lua_settable (L, -3);
  lua_pushliteral (L, "lv_attr");
  lua_pushstring (L, v->lv_attr);
  lua_settable (L, -3);
  lua_pushliteral (L, "lv_major");
  push_int64 (L, (int64_t) v->lv_major);
  lua_settable (L, -3);
  lua_pushliteral (L, "lv_minor");
  push_int64 (L, (int64_t) v->lv_minor);
  lua_settable (L, -3);
  lua_pushliteral (L, "lv_kernel_major");
  push_int64 (L, (int64_t) v->lv_kernel_major);
  lua_settable (L, -3);
  lua_pushliteral (L, "lv_kernel_minor");
  push_int64 (L, (int64_t) v->lv_kernel_minor);
  lua_settable (L, -3);
  lua_pushliteral (L, "lv_size");
  push_int64 (L, (int64_t) v->lv_size);
  lua_settable (L, -3);
  lua_pushliteral (L, "seg_count");
  push_int64 (L, (int64_t) v->seg_count);
  lua_settable (L, -3);
  lua_pushliteral (L, "origin");
  lua_pushstring (L, v->origin);
  lua_settable (L, -3);
  lua_pushliteral (L, "snap_percent");
  lua_pushnumber (L, v->snap_percent);
  lua_settable (L, -3);
  lua_pushliteral (L, "copy_percent");
  lua_pushnumber (L, v->copy_percent);
  lua_settable (L, -3);
  lua_pushliteral (L, "move_pv");
  lua_pushstring (L, v->move_pv);
  lua_settable (L, -3);
  lua_pushliteral (L, "lv_tags");
  lua_pushstring (L, v->lv_tags);
  lua_settable (L, -3);
  lua_pushliteral (L, "mirror_log");
  lua_pushstring (L, v->mirror_log);
  lua_settable (L, -3);
  lua_pushliteral (L, "modules");
  lua_pushstring (L, v->modules);
  lua_settable (L, -3);
}

static void
push_lvm_lv_list (lua_State *L, struct guestfs_lvm_lv_list *v)
{
  size_t i;

  lua_newtable (L);
  for (i = 0; i < v->len; ++i) {
    push_lvm_lv (L, &v->val[i]);
    lua_rawseti (L, -2, i+1 /* because of base 1 arrays */);
  }
}

static void
push_dirent (lua_State *L, struct guestfs_dirent *v)
{
  lua_newtable (L);
  lua_pushliteral (L, "ino");
  push_int64 (L, (int64_t) v->ino);
  lua_settable (L, -3);
  lua_pushliteral (L, "ftyp");
  lua_pushlstring (L, &v->ftyp, 1);
  lua_settable (L, -3);
  lua_pushliteral (L, "name");
  lua_pushstring (L, v->name);
  lua_settable (L, -3);
}

static void
push_dirent_list (lua_State *L, struct guestfs_dirent_list *v)
{
  size_t i;

  lua_newtable (L);
  for (i = 0; i < v->len; ++i) {
    push_dirent (L, &v->val[i]);
    lua_rawseti (L, -2, i+1 /* because of base 1 arrays */);
  }
}

static void
push_utsname (lua_State *L, struct guestfs_utsname *v)
{
  lua_newtable (L);
  lua_pushliteral (L, "uts_sysname");
  lua_pushstring (L, v->uts_sysname);
  lua_settable (L, -3);
  lua_pushliteral (L, "uts_release");
  lua_pushstring (L, v->uts_release);
  lua_settable (L, -3);
  lua_pushliteral (L, "uts_version");
  lua_pushstring (L, v->uts_version);
  lua_settable (L, -3);
  lua_pushliteral (L, "uts_machine");
  lua_pushstring (L, v->uts_machine);
  lua_settable (L, -3);
}

static void
push_version (lua_State *L, struct guestfs_version *v)
{
  lua_newtable (L);
  lua_pushliteral (L, "major");
  push_int64 (L, (int64_t) v->major);
  lua_settable (L, -3);
  lua_pushliteral (L, "minor");
  push_int64 (L, (int64_t) v->minor);
  lua_settable (L, -3);
  lua_pushliteral (L, "release");
  push_int64 (L, (int64_t) v->release);
  lua_settable (L, -3);
  lua_pushliteral (L, "extra");
  lua_pushstring (L, v->extra);
  lua_settable (L, -3);
}

static void
push_int_bool (lua_State *L, struct guestfs_int_bool *v)
{
  lua_newtable (L);
  lua_pushliteral (L, "i");
  lua_pushinteger (L, v->i);
  lua_settable (L, -3);
  lua_pushliteral (L, "b");
  lua_pushinteger (L, v->b);
  lua_settable (L, -3);
}

static void
push_partition (lua_State *L, struct guestfs_partition *v)
{
  lua_newtable (L);
  lua_pushliteral (L, "part_num");
  lua_pushinteger (L, v->part_num);
  lua_settable (L, -3);
  lua_pushliteral (L, "part_start");
  push_int64 (L, (int64_t) v->part_start);
  lua_settable (L, -3);
  lua_pushliteral (L, "part_end");
  push_int64 (L, (int64_t) v->part_end);
  lua_settable (L, -3);
  lua_pushliteral (L, "part_size");
  push_int64 (L, (int64_t) v->part_size);
  lua_settable (L, -3);
}

static void
push_partition_list (lua_State *L, struct guestfs_partition_list *v)
{
  size_t i;

  lua_newtable (L);
  for (i = 0; i < v->len; ++i) {
    push_partition (L, &v->val[i]);
    lua_rawseti (L, -2, i+1 /* because of base 1 arrays */);
  }
}

static void
push_application2 (lua_State *L, struct guestfs_application2 *v)
{
  lua_newtable (L);
  lua_pushliteral (L, "app2_name");
  lua_pushstring (L, v->app2_name);
  lua_settable (L, -3);
  lua_pushliteral (L, "app2_display_name");
  lua_pushstring (L, v->app2_display_name);
  lua_settable (L, -3);
  lua_pushliteral (L, "app2_epoch");
  lua_pushinteger (L, v->app2_epoch);
  lua_settable (L, -3);
  lua_pushliteral (L, "app2_version");
  lua_pushstring (L, v->app2_version);
  lua_settable (L, -3);
  lua_pushliteral (L, "app2_release");
  lua_pushstring (L, v->app2_release);
  lua_settable (L, -3);
  lua_pushliteral (L, "app2_arch");
  lua_pushstring (L, v->app2_arch);
  lua_settable (L, -3);
  lua_pushliteral (L, "app2_install_path");
  lua_pushstring (L, v->app2_install_path);
  lua_settable (L, -3);
  lua_pushliteral (L, "app2_trans_path");
  lua_pushstring (L, v->app2_trans_path);
  lua_settable (L, -3);
  lua_pushliteral (L, "app2_publisher");
  lua_pushstring (L, v->app2_publisher);
  lua_settable (L, -3);
  lua_pushliteral (L, "app2_url");
  lua_pushstring (L, v->app2_url);
  lua_settable (L, -3);
  lua_pushliteral (L, "app2_source_package");
  lua_pushstring (L, v->app2_source_package);
  lua_settable (L, -3);
  lua_pushliteral (L, "app2_summary");
  lua_pushstring (L, v->app2_summary);
  lua_settable (L, -3);
  lua_pushliteral (L, "app2_description");
  lua_pushstring (L, v->app2_description);
  lua_settable (L, -3);
  lua_pushliteral (L, "app2_spare1");
  lua_pushstring (L, v->app2_spare1);
  lua_settable (L, -3);
  lua_pushliteral (L, "app2_spare2");
  lua_pushstring (L, v->app2_spare2);
  lua_settable (L, -3);
  lua_pushliteral (L, "app2_spare3");
  lua_pushstring (L, v->app2_spare3);
  lua_settable (L, -3);
  lua_pushliteral (L, "app2_spare4");
  lua_pushstring (L, v->app2_spare4);
  lua_settable (L, -3);
}

static void
push_application2_list (lua_State *L, struct guestfs_application2_list *v)
{
  size_t i;

  lua_newtable (L);
  for (i = 0; i < v->len; ++i) {
    push_application2 (L, &v->val[i]);
    lua_rawseti (L, -2, i+1 /* because of base 1 arrays */);
  }
}

static void
push_inotify_event (lua_State *L, struct guestfs_inotify_event *v)
{
  lua_newtable (L);
  lua_pushliteral (L, "in_wd");
  push_int64 (L, (int64_t) v->in_wd);
  lua_settable (L, -3);
  lua_pushliteral (L, "in_mask");
  lua_pushinteger (L, v->in_mask);
  lua_settable (L, -3);
  lua_pushliteral (L, "in_cookie");
  lua_pushinteger (L, v->in_cookie);
  lua_settable (L, -3);
  lua_pushliteral (L, "in_name");
  lua_pushstring (L, v->in_name);
  lua_settable (L, -3);
}

static void
push_inotify_event_list (lua_State *L, struct guestfs_inotify_event_list *v)
{
  size_t i;

  lua_newtable (L);
  for (i = 0; i < v->len; ++i) {
    push_inotify_event (L, &v->val[i]);
    lua_rawseti (L, -2, i+1 /* because of base 1 arrays */);
  }
}

static void
push_xfsinfo (lua_State *L, struct guestfs_xfsinfo *v)
{
  lua_newtable (L);
  lua_pushliteral (L, "xfs_mntpoint");
  lua_pushstring (L, v->xfs_mntpoint);
  lua_settable (L, -3);
  lua_pushliteral (L, "xfs_inodesize");
  lua_pushinteger (L, v->xfs_inodesize);
  lua_settable (L, -3);
  lua_pushliteral (L, "xfs_agcount");
  lua_pushinteger (L, v->xfs_agcount);
  lua_settable (L, -3);
  lua_pushliteral (L, "xfs_agsize");
  lua_pushinteger (L, v->xfs_agsize);
  lua_settable (L, -3);
  lua_pushliteral (L, "xfs_sectsize");
  lua_pushinteger (L, v->xfs_sectsize);
  lua_settable (L, -3);
  lua_pushliteral (L, "xfs_attr");
  lua_pushinteger (L, v->xfs_attr);
  lua_settable (L, -3);
  lua_pushliteral (L, "xfs_blocksize");
  lua_pushinteger (L, v->xfs_blocksize);
  lua_settable (L, -3);
  lua_pushliteral (L, "xfs_datablocks");
  push_int64 (L, (int64_t) v->xfs_datablocks);
  lua_settable (L, -3);
  lua_pushliteral (L, "xfs_imaxpct");
  lua_pushinteger (L, v->xfs_imaxpct);
  lua_settable (L, -3);
  lua_pushliteral (L, "xfs_sunit");
  lua_pushinteger (L, v->xfs_sunit);
  lua_settable (L, -3);
  lua_pushliteral (L, "xfs_swidth");
  lua_pushinteger (L, v->xfs_swidth);
  lua_settable (L, -3);
  lua_pushliteral (L, "xfs_dirversion");
  lua_pushinteger (L, v->xfs_dirversion);
  lua_settable (L, -3);
  lua_pushliteral (L, "xfs_dirblocksize");
  lua_pushinteger (L, v->xfs_dirblocksize);
  lua_settable (L, -3);
  lua_pushliteral (L, "xfs_cimode");
  lua_pushinteger (L, v->xfs_cimode);
  lua_settable (L, -3);
  lua_pushliteral (L, "xfs_logname");
  lua_pushstring (L, v->xfs_logname);
  lua_settable (L, -3);
  lua_pushliteral (L, "xfs_logblocksize");
  lua_pushinteger (L, v->xfs_logblocksize);
  lua_settable (L, -3);
  lua_pushliteral (L, "xfs_logblocks");
  lua_pushinteger (L, v->xfs_logblocks);
  lua_settable (L, -3);
  lua_pushliteral (L, "xfs_logversion");
  lua_pushinteger (L, v->xfs_logversion);
  lua_settable (L, -3);
  lua_pushliteral (L, "xfs_logsectsize");
  lua_pushinteger (L, v->xfs_logsectsize);
  lua_settable (L, -3);
  lua_pushliteral (L, "xfs_logsunit");
  lua_pushinteger (L, v->xfs_logsunit);
  lua_settable (L, -3);
  lua_pushliteral (L, "xfs_lazycount");
  lua_pushinteger (L, v->xfs_lazycount);
  lua_settable (L, -3);
  lua_pushliteral (L, "xfs_rtname");
  lua_pushstring (L, v->xfs_rtname);
  lua_settable (L, -3);
  lua_pushliteral (L, "xfs_rtextsize");
  lua_pushinteger (L, v->xfs_rtextsize);
  lua_settable (L, -3);
  lua_pushliteral (L, "xfs_rtblocks");
  push_int64 (L, (int64_t) v->xfs_rtblocks);
  lua_settable (L, -3);
  lua_pushliteral (L, "xfs_rtextents");
  push_int64 (L, (int64_t) v->xfs_rtextents);
  lua_settable (L, -3);
}

static void
push_application (lua_State *L, struct guestfs_application *v)
{
  lua_newtable (L);
  lua_pushliteral (L, "app_name");
  lua_pushstring (L, v->app_name);
  lua_settable (L, -3);
  lua_pushliteral (L, "app_display_name");
  lua_pushstring (L, v->app_display_name);
  lua_settable (L, -3);
  lua_pushliteral (L, "app_epoch");
  lua_pushinteger (L, v->app_epoch);
  lua_settable (L, -3);
  lua_pushliteral (L, "app_version");
  lua_pushstring (L, v->app_version);
  lua_settable (L, -3);
  lua_pushliteral (L, "app_release");
  lua_pushstring (L, v->app_release);
  lua_settable (L, -3);
  lua_pushliteral (L, "app_install_path");
  lua_pushstring (L, v->app_install_path);
  lua_settable (L, -3);
  lua_pushliteral (L, "app_trans_path");
  lua_pushstring (L, v->app_trans_path);
  lua_settable (L, -3);
  lua_pushliteral (L, "app_publisher");
  lua_pushstring (L, v->app_publisher);
  lua_settable (L, -3);
  lua_pushliteral (L, "app_url");
  lua_pushstring (L, v->app_url);
  lua_settable (L, -3);
  lua_pushliteral (L, "app_source_package");
  lua_pushstring (L, v->app_source_package);
  lua_settable (L, -3);
  lua_pushliteral (L, "app_summary");
  lua_pushstring (L, v->app_summary);
  lua_settable (L, -3);
  lua_pushliteral (L, "app_description");
  lua_pushstring (L, v->app_description);
  lua_settable (L, -3);
}

static void
push_application_list (lua_State *L, struct guestfs_application_list *v)
{
  size_t i;

  lua_newtable (L);
  for (i = 0; i < v->len; ++i) {
    push_application (L, &v->val[i]);
    lua_rawseti (L, -2, i+1 /* because of base 1 arrays */);
  }
}

static void
push_isoinfo (lua_State *L, struct guestfs_isoinfo *v)
{
  lua_newtable (L);
  lua_pushliteral (L, "iso_system_id");
  lua_pushstring (L, v->iso_system_id);
  lua_settable (L, -3);
  lua_pushliteral (L, "iso_volume_id");
  lua_pushstring (L, v->iso_volume_id);
  lua_settable (L, -3);
  lua_pushliteral (L, "iso_volume_space_size");
  lua_pushinteger (L, v->iso_volume_space_size);
  lua_settable (L, -3);
  lua_pushliteral (L, "iso_volume_set_size");
  lua_pushinteger (L, v->iso_volume_set_size);
  lua_settable (L, -3);
  lua_pushliteral (L, "iso_volume_sequence_number");
  lua_pushinteger (L, v->iso_volume_sequence_number);
  lua_settable (L, -3);
  lua_pushliteral (L, "iso_logical_block_size");
  lua_pushinteger (L, v->iso_logical_block_size);
  lua_settable (L, -3);
  lua_pushliteral (L, "iso_volume_set_id");
  lua_pushstring (L, v->iso_volume_set_id);
  lua_settable (L, -3);
  lua_pushliteral (L, "iso_publisher_id");
  lua_pushstring (L, v->iso_publisher_id);
  lua_settable (L, -3);
  lua_pushliteral (L, "iso_data_preparer_id");
  lua_pushstring (L, v->iso_data_preparer_id);
  lua_settable (L, -3);
  lua_pushliteral (L, "iso_application_id");
  lua_pushstring (L, v->iso_application_id);
  lua_settable (L, -3);
  lua_pushliteral (L, "iso_copyright_file_id");
  lua_pushstring (L, v->iso_copyright_file_id);
  lua_settable (L, -3);
  lua_pushliteral (L, "iso_abstract_file_id");
  lua_pushstring (L, v->iso_abstract_file_id);
  lua_settable (L, -3);
  lua_pushliteral (L, "iso_bibliographic_file_id");
  lua_pushstring (L, v->iso_bibliographic_file_id);
  lua_settable (L, -3);
  lua_pushliteral (L, "iso_volume_creation_t");
  push_int64 (L, (int64_t) v->iso_volume_creation_t);
  lua_settable (L, -3);
  lua_pushliteral (L, "iso_volume_modification_t");
  push_int64 (L, (int64_t) v->iso_volume_modification_t);
  lua_settable (L, -3);
  lua_pushliteral (L, "iso_volume_expiration_t");
  push_int64 (L, (int64_t) v->iso_volume_expiration_t);
  lua_settable (L, -3);
  lua_pushliteral (L, "iso_volume_effective_t");
  push_int64 (L, (int64_t) v->iso_volume_effective_t);
  lua_settable (L, -3);
}

static void
push_hivex_value (lua_State *L, struct guestfs_hivex_value *v)
{
  lua_newtable (L);
  lua_pushliteral (L, "hivex_value_h");
  push_int64 (L, (int64_t) v->hivex_value_h);
  lua_settable (L, -3);
}

static void
push_hivex_value_list (lua_State *L, struct guestfs_hivex_value_list *v)
{
  size_t i;

  lua_newtable (L);
  for (i = 0; i < v->len; ++i) {
    push_hivex_value (L, &v->val[i]);
    lua_rawseti (L, -2, i+1 /* because of base 1 arrays */);
  }
}

static void
push_xattr (lua_State *L, struct guestfs_xattr *v)
{
  lua_newtable (L);
  lua_pushliteral (L, "attrname");
  lua_pushstring (L, v->attrname);
  lua_settable (L, -3);
  lua_pushliteral (L, "attrval");
  lua_pushlstring (L, v->attrval, v->attrval_len);
  lua_settable (L, -3);
}

static void
push_xattr_list (lua_State *L, struct guestfs_xattr_list *v)
{
  size_t i;

  lua_newtable (L);
  for (i = 0; i < v->len; ++i) {
    push_xattr (L, &v->val[i]);
    lua_rawseti (L, -2, i+1 /* because of base 1 arrays */);
  }
}

static void
push_lvm_pv (lua_State *L, struct guestfs_lvm_pv *v)
{
  lua_newtable (L);
  lua_pushliteral (L, "pv_name");
  lua_pushstring (L, v->pv_name);
  lua_settable (L, -3);
  lua_pushliteral (L, "pv_uuid");
  lua_pushlstring (L, v->pv_uuid, 32);
  lua_settable (L, -3);
  lua_pushliteral (L, "pv_fmt");
  lua_pushstring (L, v->pv_fmt);
  lua_settable (L, -3);
  lua_pushliteral (L, "pv_size");
  push_int64 (L, (int64_t) v->pv_size);
  lua_settable (L, -3);
  lua_pushliteral (L, "dev_size");
  push_int64 (L, (int64_t) v->dev_size);
  lua_settable (L, -3);
  lua_pushliteral (L, "pv_free");
  push_int64 (L, (int64_t) v->pv_free);
  lua_settable (L, -3);
  lua_pushliteral (L, "pv_used");
  push_int64 (L, (int64_t) v->pv_used);
  lua_settable (L, -3);
  lua_pushliteral (L, "pv_attr");
  lua_pushstring (L, v->pv_attr);
  lua_settable (L, -3);
  lua_pushliteral (L, "pv_pe_count");
  push_int64 (L, (int64_t) v->pv_pe_count);
  lua_settable (L, -3);
  lua_pushliteral (L, "pv_pe_alloc_count");
  push_int64 (L, (int64_t) v->pv_pe_alloc_count);
  lua_settable (L, -3);
  lua_pushliteral (L, "pv_tags");
  lua_pushstring (L, v->pv_tags);
  lua_settable (L, -3);
  lua_pushliteral (L, "pe_start");
  push_int64 (L, (int64_t) v->pe_start);
  lua_settable (L, -3);
  lua_pushliteral (L, "pv_mda_count");
  push_int64 (L, (int64_t) v->pv_mda_count);
  lua_settable (L, -3);
  lua_pushliteral (L, "pv_mda_free");
  push_int64 (L, (int64_t) v->pv_mda_free);
  lua_settable (L, -3);
}

static void
push_lvm_pv_list (lua_State *L, struct guestfs_lvm_pv_list *v)
{
  size_t i;

  lua_newtable (L);
  for (i = 0; i < v->len; ++i) {
    push_lvm_pv (L, &v->val[i]);
    lua_rawseti (L, -2, i+1 /* because of base 1 arrays */);
  }
}

static void
push_lvm_vg (lua_State *L, struct guestfs_lvm_vg *v)
{
  lua_newtable (L);
  lua_pushliteral (L, "vg_name");
  lua_pushstring (L, v->vg_name);
  lua_settable (L, -3);
  lua_pushliteral (L, "vg_uuid");
  lua_pushlstring (L, v->vg_uuid, 32);
  lua_settable (L, -3);
  lua_pushliteral (L, "vg_fmt");
  lua_pushstring (L, v->vg_fmt);
  lua_settable (L, -3);
  lua_pushliteral (L, "vg_attr");
  lua_pushstring (L, v->vg_attr);
  lua_settable (L, -3);
  lua_pushliteral (L, "vg_size");
  push_int64 (L, (int64_t) v->vg_size);
  lua_settable (L, -3);
  lua_pushliteral (L, "vg_free");
  push_int64 (L, (int64_t) v->vg_free);
  lua_settable (L, -3);
  lua_pushliteral (L, "vg_sysid");
  lua_pushstring (L, v->vg_sysid);
  lua_settable (L, -3);
  lua_pushliteral (L, "vg_extent_size");
  push_int64 (L, (int64_t) v->vg_extent_size);
  lua_settable (L, -3);
  lua_pushliteral (L, "vg_extent_count");
  push_int64 (L, (int64_t) v->vg_extent_count);
  lua_settable (L, -3);
  lua_pushliteral (L, "vg_free_count");
  push_int64 (L, (int64_t) v->vg_free_count);
  lua_settable (L, -3);
  lua_pushliteral (L, "max_lv");
  push_int64 (L, (int64_t) v->max_lv);
  lua_settable (L, -3);
  lua_pushliteral (L, "max_pv");
  push_int64 (L, (int64_t) v->max_pv);
  lua_settable (L, -3);
  lua_pushliteral (L, "pv_count");
  push_int64 (L, (int64_t) v->pv_count);
  lua_settable (L, -3);
  lua_pushliteral (L, "lv_count");
  push_int64 (L, (int64_t) v->lv_count);
  lua_settable (L, -3);
  lua_pushliteral (L, "snap_count");
  push_int64 (L, (int64_t) v->snap_count);
  lua_settable (L, -3);
  lua_pushliteral (L, "vg_seqno");
  push_int64 (L, (int64_t) v->vg_seqno);
  lua_settable (L, -3);
  lua_pushliteral (L, "vg_tags");
  lua_pushstring (L, v->vg_tags);
  lua_settable (L, -3);
  lua_pushliteral (L, "vg_mda_count");
  push_int64 (L, (int64_t) v->vg_mda_count);
  lua_settable (L, -3);
  lua_pushliteral (L, "vg_mda_free");
  push_int64 (L, (int64_t) v->vg_mda_free);
  lua_settable (L, -3);
}

static void
push_lvm_vg_list (lua_State *L, struct guestfs_lvm_vg_list *v)
{
  size_t i;

  lua_newtable (L);
  for (i = 0; i < v->len; ++i) {
    push_lvm_vg (L, &v->val[i]);
    lua_rawseti (L, -2, i+1 /* because of base 1 arrays */);
  }
}

static void
push_btrfssubvolume (lua_State *L, struct guestfs_btrfssubvolume *v)
{
  lua_newtable (L);
  lua_pushliteral (L, "btrfssubvolume_id");
  push_int64 (L, (int64_t) v->btrfssubvolume_id);
  lua_settable (L, -3);
  lua_pushliteral (L, "btrfssubvolume_top_level_id");
  push_int64 (L, (int64_t) v->btrfssubvolume_top_level_id);
  lua_settable (L, -3);
  lua_pushliteral (L, "btrfssubvolume_path");
  lua_pushstring (L, v->btrfssubvolume_path);
  lua_settable (L, -3);
}

static void
push_btrfssubvolume_list (lua_State *L, struct guestfs_btrfssubvolume_list *v)
{
  size_t i;

  lua_newtable (L);
  for (i = 0; i < v->len; ++i) {
    push_btrfssubvolume (L, &v->val[i]);
    lua_rawseti (L, -2, i+1 /* because of base 1 arrays */);
  }
}

static void
push_mdstat (lua_State *L, struct guestfs_mdstat *v)
{
  lua_newtable (L);
  lua_pushliteral (L, "mdstat_device");
  lua_pushstring (L, v->mdstat_device);
  lua_settable (L, -3);
  lua_pushliteral (L, "mdstat_index");
  lua_pushinteger (L, v->mdstat_index);
  lua_settable (L, -3);
  lua_pushliteral (L, "mdstat_flags");
  lua_pushstring (L, v->mdstat_flags);
  lua_settable (L, -3);
}

static void
push_mdstat_list (lua_State *L, struct guestfs_mdstat_list *v)
{
  size_t i;

  lua_newtable (L);
  for (i = 0; i < v->len; ++i) {
    push_mdstat (L, &v->val[i]);
    lua_rawseti (L, -2, i+1 /* because of base 1 arrays */);
  }
}

static void
push_hivex_node (lua_State *L, struct guestfs_hivex_node *v)
{
  lua_newtable (L);
  lua_pushliteral (L, "hivex_node_h");
  push_int64 (L, (int64_t) v->hivex_node_h);
  lua_settable (L, -3);
}

static void
push_hivex_node_list (lua_State *L, struct guestfs_hivex_node_list *v)
{
  size_t i;

  lua_newtable (L);
  for (i = 0; i < v->len; ++i) {
    push_hivex_node (L, &v->val[i]);
    lua_rawseti (L, -2, i+1 /* because of base 1 arrays */);
  }
}

static void
push_stat (lua_State *L, struct guestfs_stat *v)
{
  lua_newtable (L);
  lua_pushliteral (L, "dev");
  push_int64 (L, (int64_t) v->dev);
  lua_settable (L, -3);
  lua_pushliteral (L, "ino");
  push_int64 (L, (int64_t) v->ino);
  lua_settable (L, -3);
  lua_pushliteral (L, "mode");
  push_int64 (L, (int64_t) v->mode);
  lua_settable (L, -3);
  lua_pushliteral (L, "nlink");
  push_int64 (L, (int64_t) v->nlink);
  lua_settable (L, -3);
  lua_pushliteral (L, "uid");
  push_int64 (L, (int64_t) v->uid);
  lua_settable (L, -3);
  lua_pushliteral (L, "gid");
  push_int64 (L, (int64_t) v->gid);
  lua_settable (L, -3);
  lua_pushliteral (L, "rdev");
  push_int64 (L, (int64_t) v->rdev);
  lua_settable (L, -3);
  lua_pushliteral (L, "size");
  push_int64 (L, (int64_t) v->size);
  lua_settable (L, -3);
  lua_pushliteral (L, "blksize");
  push_int64 (L, (int64_t) v->blksize);
  lua_settable (L, -3);
  lua_pushliteral (L, "blocks");
  push_int64 (L, (int64_t) v->blocks);
  lua_settable (L, -3);
  lua_pushliteral (L, "atime");
  push_int64 (L, (int64_t) v->atime);
  lua_settable (L, -3);
  lua_pushliteral (L, "mtime");
  push_int64 (L, (int64_t) v->mtime);
  lua_settable (L, -3);
  lua_pushliteral (L, "ctime");
  push_int64 (L, (int64_t) v->ctime);
  lua_settable (L, -3);
}

static void
push_stat_list (lua_State *L, struct guestfs_stat_list *v)
{
  size_t i;

  lua_newtable (L);
  for (i = 0; i < v->len; ++i) {
    push_stat (L, &v->val[i]);
    lua_rawseti (L, -2, i+1 /* because of base 1 arrays */);
  }
}

static void
push_statvfs (lua_State *L, struct guestfs_statvfs *v)
{
  lua_newtable (L);
  lua_pushliteral (L, "bsize");
  push_int64 (L, (int64_t) v->bsize);
  lua_settable (L, -3);
  lua_pushliteral (L, "frsize");
  push_int64 (L, (int64_t) v->frsize);
  lua_settable (L, -3);
  lua_pushliteral (L, "blocks");
  push_int64 (L, (int64_t) v->blocks);
  lua_settable (L, -3);
  lua_pushliteral (L, "bfree");
  push_int64 (L, (int64_t) v->bfree);
  lua_settable (L, -3);
  lua_pushliteral (L, "bavail");
  push_int64 (L, (int64_t) v->bavail);
  lua_settable (L, -3);
  lua_pushliteral (L, "files");
  push_int64 (L, (int64_t) v->files);
  lua_settable (L, -3);
  lua_pushliteral (L, "ffree");
  push_int64 (L, (int64_t) v->ffree);
  lua_settable (L, -3);
  lua_pushliteral (L, "favail");
  push_int64 (L, (int64_t) v->favail);
  lua_settable (L, -3);
  lua_pushliteral (L, "fsid");
  push_int64 (L, (int64_t) v->fsid);
  lua_settable (L, -3);
  lua_pushliteral (L, "flag");
  push_int64 (L, (int64_t) v->flag);
  lua_settable (L, -3);
  lua_pushliteral (L, "namemax");
  push_int64 (L, (int64_t) v->namemax);
  lua_settable (L, -3);
}

/* Metamethods.
 * See: http://article.gmane.org/gmane.comp.lang.lua.general/95065
 */
static luaL_Reg metamethods[] = {
  { "__gc", guestfs_lua_finalizer },
  { NULL, NULL }
};

/* Module functions. */
static luaL_Reg functions[] = {
  { "create", guestfs_lua_create },
  { NULL, NULL }
};

/* Methods. */
static luaL_Reg methods[] = {
  { "close", guestfs_lua_close },
  { "set_event_callback", guestfs_lua_set_event_callback },
  { "delete_event_callback", guestfs_lua_delete_event_callback },

  { "acl_delete_def_file", guestfs_lua_acl_delete_def_file },
  { "acl_get_file", guestfs_lua_acl_get_file },
  { "acl_set_file", guestfs_lua_acl_set_file },
  { "add_cdrom", guestfs_lua_add_cdrom },
  { "add_domain", guestfs_lua_add_domain },
  { "add_drive", guestfs_lua_add_drive },
  { "add_drive_ro", guestfs_lua_add_drive_ro },
  { "add_drive_ro_with_if", guestfs_lua_add_drive_ro_with_if },
  { "add_drive_with_if", guestfs_lua_add_drive_with_if },
  { "aug_clear", guestfs_lua_aug_clear },
  { "aug_close", guestfs_lua_aug_close },
  { "aug_defnode", guestfs_lua_aug_defnode },
  { "aug_defvar", guestfs_lua_aug_defvar },
  { "aug_get", guestfs_lua_aug_get },
  { "aug_init", guestfs_lua_aug_init },
  { "aug_insert", guestfs_lua_aug_insert },
  { "aug_load", guestfs_lua_aug_load },
  { "aug_ls", guestfs_lua_aug_ls },
  { "aug_match", guestfs_lua_aug_match },
  { "aug_mv", guestfs_lua_aug_mv },
  { "aug_rm", guestfs_lua_aug_rm },
  { "aug_save", guestfs_lua_aug_save },
  { "aug_set", guestfs_lua_aug_set },
  { "available", guestfs_lua_available },
  { "available_all_groups", guestfs_lua_available_all_groups },
  { "base64_in", guestfs_lua_base64_in },
  { "base64_out", guestfs_lua_base64_out },
  { "blkid", guestfs_lua_blkid },
  { "blockdev_flushbufs", guestfs_lua_blockdev_flushbufs },
  { "blockdev_getbsz", guestfs_lua_blockdev_getbsz },
  { "blockdev_getro", guestfs_lua_blockdev_getro },
  { "blockdev_getsize64", guestfs_lua_blockdev_getsize64 },
  { "blockdev_getss", guestfs_lua_blockdev_getss },
  { "blockdev_getsz", guestfs_lua_blockdev_getsz },
  { "blockdev_rereadpt", guestfs_lua_blockdev_rereadpt },
  { "blockdev_setbsz", guestfs_lua_blockdev_setbsz },
  { "blockdev_setro", guestfs_lua_blockdev_setro },
  { "blockdev_setrw", guestfs_lua_blockdev_setrw },
  { "btrfs_device_add", guestfs_lua_btrfs_device_add },
  { "btrfs_device_delete", guestfs_lua_btrfs_device_delete },
  { "btrfs_filesystem_balance", guestfs_lua_btrfs_filesystem_balance },
  { "btrfs_filesystem_resize", guestfs_lua_btrfs_filesystem_resize },
  { "btrfs_filesystem_sync", guestfs_lua_btrfs_filesystem_sync },
  { "btrfs_fsck", guestfs_lua_btrfs_fsck },
  { "btrfs_set_seeding", guestfs_lua_btrfs_set_seeding },
  { "btrfs_subvolume_create", guestfs_lua_btrfs_subvolume_create },
  { "btrfs_subvolume_delete", guestfs_lua_btrfs_subvolume_delete },
  { "btrfs_subvolume_list", guestfs_lua_btrfs_subvolume_list },
  { "btrfs_subvolume_set_default", guestfs_lua_btrfs_subvolume_set_default },
  { "btrfs_subvolume_snapshot", guestfs_lua_btrfs_subvolume_snapshot },
  { "canonical_device_name", guestfs_lua_canonical_device_name },
  { "cap_get_file", guestfs_lua_cap_get_file },
  { "cap_set_file", guestfs_lua_cap_set_file },
  { "case_sensitive_path", guestfs_lua_case_sensitive_path },
  { "cat", guestfs_lua_cat },
  { "checksum", guestfs_lua_checksum },
  { "checksum_device", guestfs_lua_checksum_device },
  { "checksums_out", guestfs_lua_checksums_out },
  { "chmod", guestfs_lua_chmod },
  { "chown", guestfs_lua_chown },
  { "command", guestfs_lua_command },
  { "command_lines", guestfs_lua_command_lines },
  { "compress_device_out", guestfs_lua_compress_device_out },
  { "compress_out", guestfs_lua_compress_out },
  { "config", guestfs_lua_config },
  { "copy_device_to_device", guestfs_lua_copy_device_to_device },
  { "copy_device_to_file", guestfs_lua_copy_device_to_file },
  { "copy_file_to_device", guestfs_lua_copy_file_to_device },
  { "copy_file_to_file", guestfs_lua_copy_file_to_file },
  { "copy_size", guestfs_lua_copy_size },
  { "cp", guestfs_lua_cp },
  { "cp_a", guestfs_lua_cp_a },
  { "dd", guestfs_lua_dd },
  { "debug", guestfs_lua_debug },
  { "debug_drives", guestfs_lua_debug_drives },
  { "debug_upload", guestfs_lua_debug_upload },
  { "device_index", guestfs_lua_device_index },
  { "df", guestfs_lua_df },
  { "df_h", guestfs_lua_df_h },
  { "disk_format", guestfs_lua_disk_format },
  { "disk_has_backing_file", guestfs_lua_disk_has_backing_file },
  { "disk_virtual_size", guestfs_lua_disk_virtual_size },
  { "dmesg", guestfs_lua_dmesg },
  { "download", guestfs_lua_download },
  { "download_offset", guestfs_lua_download_offset },
  { "drop_caches", guestfs_lua_drop_caches },
  { "du", guestfs_lua_du },
  { "e2fsck", guestfs_lua_e2fsck },
  { "e2fsck_f", guestfs_lua_e2fsck_f },
  { "echo_daemon", guestfs_lua_echo_daemon },
  { "egrep", guestfs_lua_egrep },
  { "egrepi", guestfs_lua_egrepi },
  { "equal", guestfs_lua_equal },
  { "exists", guestfs_lua_exists },
  { "fallocate", guestfs_lua_fallocate },
  { "fallocate64", guestfs_lua_fallocate64 },
  { "fgrep", guestfs_lua_fgrep },
  { "fgrepi", guestfs_lua_fgrepi },
  { "file", guestfs_lua_file },
  { "file_architecture", guestfs_lua_file_architecture },
  { "filesize", guestfs_lua_filesize },
  { "filesystem_available", guestfs_lua_filesystem_available },
  { "fill", guestfs_lua_fill },
  { "fill_dir", guestfs_lua_fill_dir },
  { "fill_pattern", guestfs_lua_fill_pattern },
  { "find", guestfs_lua_find },
  { "find0", guestfs_lua_find0 },
  { "findfs_label", guestfs_lua_findfs_label },
  { "findfs_uuid", guestfs_lua_findfs_uuid },
  { "fsck", guestfs_lua_fsck },
  { "fstrim", guestfs_lua_fstrim },
  { "get_append", guestfs_lua_get_append },
  { "get_attach_method", guestfs_lua_get_attach_method },
  { "get_autosync", guestfs_lua_get_autosync },
  { "get_cachedir", guestfs_lua_get_cachedir },
  { "get_direct", guestfs_lua_get_direct },
  { "get_e2attrs", guestfs_lua_get_e2attrs },
  { "get_e2generation", guestfs_lua_get_e2generation },
  { "get_e2label", guestfs_lua_get_e2label },
  { "get_e2uuid", guestfs_lua_get_e2uuid },
  { "get_libvirt_requested_credential_challenge", guestfs_lua_get_libvirt_requested_credential_challenge },
  { "get_libvirt_requested_credential_defresult", guestfs_lua_get_libvirt_requested_credential_defresult },
  { "get_libvirt_requested_credential_prompt", guestfs_lua_get_libvirt_requested_credential_prompt },
  { "get_libvirt_requested_credentials", guestfs_lua_get_libvirt_requested_credentials },
  { "get_memsize", guestfs_lua_get_memsize },
  { "get_network", guestfs_lua_get_network },
  { "get_path", guestfs_lua_get_path },
  { "get_pgroup", guestfs_lua_get_pgroup },
  { "get_pid", guestfs_lua_get_pid },
  { "get_qemu", guestfs_lua_get_qemu },
  { "get_recovery_proc", guestfs_lua_get_recovery_proc },
  { "get_selinux", guestfs_lua_get_selinux },
  { "get_smp", guestfs_lua_get_smp },
  { "get_state", guestfs_lua_get_state },
  { "get_tmpdir", guestfs_lua_get_tmpdir },
  { "get_trace", guestfs_lua_get_trace },
  { "get_umask", guestfs_lua_get_umask },
  { "get_verbose", guestfs_lua_get_verbose },
  { "getcon", guestfs_lua_getcon },
  { "getxattr", guestfs_lua_getxattr },
  { "getxattrs", guestfs_lua_getxattrs },
  { "glob_expand", guestfs_lua_glob_expand },
  { "grep", guestfs_lua_grep },
  { "grepi", guestfs_lua_grepi },
  { "grub_install", guestfs_lua_grub_install },
  { "head", guestfs_lua_head },
  { "head_n", guestfs_lua_head_n },
  { "hexdump", guestfs_lua_hexdump },
  { "hivex_close", guestfs_lua_hivex_close },
  { "hivex_commit", guestfs_lua_hivex_commit },
  { "hivex_node_add_child", guestfs_lua_hivex_node_add_child },
  { "hivex_node_children", guestfs_lua_hivex_node_children },
  { "hivex_node_delete_child", guestfs_lua_hivex_node_delete_child },
  { "hivex_node_get_child", guestfs_lua_hivex_node_get_child },
  { "hivex_node_get_value", guestfs_lua_hivex_node_get_value },
  { "hivex_node_name", guestfs_lua_hivex_node_name },
  { "hivex_node_parent", guestfs_lua_hivex_node_parent },
  { "hivex_node_set_value", guestfs_lua_hivex_node_set_value },
  { "hivex_node_values", guestfs_lua_hivex_node_values },
  { "hivex_open", guestfs_lua_hivex_open },
  { "hivex_root", guestfs_lua_hivex_root },
  { "hivex_value_key", guestfs_lua_hivex_value_key },
  { "hivex_value_type", guestfs_lua_hivex_value_type },
  { "hivex_value_utf8", guestfs_lua_hivex_value_utf8 },
  { "hivex_value_value", guestfs_lua_hivex_value_value },
  { "initrd_cat", guestfs_lua_initrd_cat },
  { "initrd_list", guestfs_lua_initrd_list },
  { "inotify_add_watch", guestfs_lua_inotify_add_watch },
  { "inotify_close", guestfs_lua_inotify_close },
  { "inotify_files", guestfs_lua_inotify_files },
  { "inotify_init", guestfs_lua_inotify_init },
  { "inotify_read", guestfs_lua_inotify_read },
  { "inotify_rm_watch", guestfs_lua_inotify_rm_watch },
  { "inspect_get_arch", guestfs_lua_inspect_get_arch },
  { "inspect_get_distro", guestfs_lua_inspect_get_distro },
  { "inspect_get_drive_mappings", guestfs_lua_inspect_get_drive_mappings },
  { "inspect_get_filesystems", guestfs_lua_inspect_get_filesystems },
  { "inspect_get_format", guestfs_lua_inspect_get_format },
  { "inspect_get_hostname", guestfs_lua_inspect_get_hostname },
  { "inspect_get_icon", guestfs_lua_inspect_get_icon },
  { "inspect_get_major_version", guestfs_lua_inspect_get_major_version },
  { "inspect_get_minor_version", guestfs_lua_inspect_get_minor_version },
  { "inspect_get_mountpoints", guestfs_lua_inspect_get_mountpoints },
  { "inspect_get_package_format", guestfs_lua_inspect_get_package_format },
  { "inspect_get_package_management", guestfs_lua_inspect_get_package_management },
  { "inspect_get_product_name", guestfs_lua_inspect_get_product_name },
  { "inspect_get_product_variant", guestfs_lua_inspect_get_product_variant },
  { "inspect_get_roots", guestfs_lua_inspect_get_roots },
  { "inspect_get_type", guestfs_lua_inspect_get_type },
  { "inspect_get_windows_current_control_set", guestfs_lua_inspect_get_windows_current_control_set },
  { "inspect_get_windows_systemroot", guestfs_lua_inspect_get_windows_systemroot },
  { "inspect_is_live", guestfs_lua_inspect_is_live },
  { "inspect_is_multipart", guestfs_lua_inspect_is_multipart },
  { "inspect_is_netinst", guestfs_lua_inspect_is_netinst },
  { "inspect_list_applications", guestfs_lua_inspect_list_applications },
  { "inspect_list_applications2", guestfs_lua_inspect_list_applications2 },
  { "inspect_os", guestfs_lua_inspect_os },
  { "internal_test", guestfs_lua_internal_test },
  { "internal_test_63_optargs", guestfs_lua_internal_test_63_optargs },
  { "internal_test_close_output", guestfs_lua_internal_test_close_output },
  { "internal_test_only_optargs", guestfs_lua_internal_test_only_optargs },
  { "internal_test_rbool", guestfs_lua_internal_test_rbool },
  { "internal_test_rboolerr", guestfs_lua_internal_test_rboolerr },
  { "internal_test_rbufferout", guestfs_lua_internal_test_rbufferout },
  { "internal_test_rbufferouterr", guestfs_lua_internal_test_rbufferouterr },
  { "internal_test_rconstoptstring", guestfs_lua_internal_test_rconstoptstring },
  { "internal_test_rconstoptstringerr", guestfs_lua_internal_test_rconstoptstringerr },
  { "internal_test_rconststring", guestfs_lua_internal_test_rconststring },
  { "internal_test_rconststringerr", guestfs_lua_internal_test_rconststringerr },
  { "internal_test_rhashtable", guestfs_lua_internal_test_rhashtable },
  { "internal_test_rhashtableerr", guestfs_lua_internal_test_rhashtableerr },
  { "internal_test_rint", guestfs_lua_internal_test_rint },
  { "internal_test_rint64", guestfs_lua_internal_test_rint64 },
  { "internal_test_rint64err", guestfs_lua_internal_test_rint64err },
  { "internal_test_rinterr", guestfs_lua_internal_test_rinterr },
  { "internal_test_rstring", guestfs_lua_internal_test_rstring },
  { "internal_test_rstringerr", guestfs_lua_internal_test_rstringerr },
  { "internal_test_rstringlist", guestfs_lua_internal_test_rstringlist },
  { "internal_test_rstringlisterr", guestfs_lua_internal_test_rstringlisterr },
  { "internal_test_rstruct", guestfs_lua_internal_test_rstruct },
  { "internal_test_rstructerr", guestfs_lua_internal_test_rstructerr },
  { "internal_test_rstructlist", guestfs_lua_internal_test_rstructlist },
  { "internal_test_rstructlisterr", guestfs_lua_internal_test_rstructlisterr },
  { "internal_test_set_output", guestfs_lua_internal_test_set_output },
  { "is_blockdev", guestfs_lua_is_blockdev },
  { "is_busy", guestfs_lua_is_busy },
  { "is_chardev", guestfs_lua_is_chardev },
  { "is_config", guestfs_lua_is_config },
  { "is_dir", guestfs_lua_is_dir },
  { "is_fifo", guestfs_lua_is_fifo },
  { "is_file", guestfs_lua_is_file },
  { "is_launching", guestfs_lua_is_launching },
  { "is_lv", guestfs_lua_is_lv },
  { "is_ready", guestfs_lua_is_ready },
  { "is_socket", guestfs_lua_is_socket },
  { "is_symlink", guestfs_lua_is_symlink },
  { "is_whole_device", guestfs_lua_is_whole_device },
  { "is_zero", guestfs_lua_is_zero },
  { "is_zero_device", guestfs_lua_is_zero_device },
  { "isoinfo", guestfs_lua_isoinfo },
  { "isoinfo_device", guestfs_lua_isoinfo_device },
  { "kill_subprocess", guestfs_lua_kill_subprocess },
  { "launch", guestfs_lua_launch },
  { "lchown", guestfs_lua_lchown },
  { "ldmtool_create_all", guestfs_lua_ldmtool_create_all },
  { "ldmtool_diskgroup_disks", guestfs_lua_ldmtool_diskgroup_disks },
  { "ldmtool_diskgroup_name", guestfs_lua_ldmtool_diskgroup_name },
  { "ldmtool_diskgroup_volumes", guestfs_lua_ldmtool_diskgroup_volumes },
  { "ldmtool_remove_all", guestfs_lua_ldmtool_remove_all },
  { "ldmtool_scan", guestfs_lua_ldmtool_scan },
  { "ldmtool_scan_devices", guestfs_lua_ldmtool_scan_devices },
  { "ldmtool_volume_hint", guestfs_lua_ldmtool_volume_hint },
  { "ldmtool_volume_partitions", guestfs_lua_ldmtool_volume_partitions },
  { "ldmtool_volume_type", guestfs_lua_ldmtool_volume_type },
  { "lgetxattr", guestfs_lua_lgetxattr },
  { "lgetxattrs", guestfs_lua_lgetxattrs },
  { "list_9p", guestfs_lua_list_9p },
  { "list_devices", guestfs_lua_list_devices },
  { "list_disk_labels", guestfs_lua_list_disk_labels },
  { "list_dm_devices", guestfs_lua_list_dm_devices },
  { "list_filesystems", guestfs_lua_list_filesystems },
  { "list_ldm_partitions", guestfs_lua_list_ldm_partitions },
  { "list_ldm_volumes", guestfs_lua_list_ldm_volumes },
  { "list_md_devices", guestfs_lua_list_md_devices },
  { "list_partitions", guestfs_lua_list_partitions },
  { "ll", guestfs_lua_ll },
  { "llz", guestfs_lua_llz },
  { "ln", guestfs_lua_ln },
  { "ln_f", guestfs_lua_ln_f },
  { "ln_s", guestfs_lua_ln_s },
  { "ln_sf", guestfs_lua_ln_sf },
  { "lremovexattr", guestfs_lua_lremovexattr },
  { "ls", guestfs_lua_ls },
  { "ls0", guestfs_lua_ls0 },
  { "lsetxattr", guestfs_lua_lsetxattr },
  { "lstat", guestfs_lua_lstat },
  { "lstatlist", guestfs_lua_lstatlist },
  { "luks_add_key", guestfs_lua_luks_add_key },
  { "luks_close", guestfs_lua_luks_close },
  { "luks_format", guestfs_lua_luks_format },
  { "luks_format_cipher", guestfs_lua_luks_format_cipher },
  { "luks_kill_slot", guestfs_lua_luks_kill_slot },
  { "luks_open", guestfs_lua_luks_open },
  { "luks_open_ro", guestfs_lua_luks_open_ro },
  { "lvcreate", guestfs_lua_lvcreate },
  { "lvcreate_free", guestfs_lua_lvcreate_free },
  { "lvm_canonical_lv_name", guestfs_lua_lvm_canonical_lv_name },
  { "lvm_clear_filter", guestfs_lua_lvm_clear_filter },
  { "lvm_remove_all", guestfs_lua_lvm_remove_all },
  { "lvm_set_filter", guestfs_lua_lvm_set_filter },
  { "lvremove", guestfs_lua_lvremove },
  { "lvrename", guestfs_lua_lvrename },
  { "lvresize", guestfs_lua_lvresize },
  { "lvresize_free", guestfs_lua_lvresize_free },
  { "lvs", guestfs_lua_lvs },
  { "lvs_full", guestfs_lua_lvs_full },
  { "lvuuid", guestfs_lua_lvuuid },
  { "lxattrlist", guestfs_lua_lxattrlist },
  { "max_disks", guestfs_lua_max_disks },
  { "md_create", guestfs_lua_md_create },
  { "md_detail", guestfs_lua_md_detail },
  { "md_stat", guestfs_lua_md_stat },
  { "md_stop", guestfs_lua_md_stop },
  { "mkdir", guestfs_lua_mkdir },
  { "mkdir_mode", guestfs_lua_mkdir_mode },
  { "mkdir_p", guestfs_lua_mkdir_p },
  { "mkdtemp", guestfs_lua_mkdtemp },
  { "mke2fs", guestfs_lua_mke2fs },
  { "mke2fs_J", guestfs_lua_mke2fs_J },
  { "mke2fs_JL", guestfs_lua_mke2fs_JL },
  { "mke2fs_JU", guestfs_lua_mke2fs_JU },
  { "mke2journal", guestfs_lua_mke2journal },
  { "mke2journal_L", guestfs_lua_mke2journal_L },
  { "mke2journal_U", guestfs_lua_mke2journal_U },
  { "mkfifo", guestfs_lua_mkfifo },
  { "mkfs", guestfs_lua_mkfs },
  { "mkfs_b", guestfs_lua_mkfs_b },
  { "mkfs_btrfs", guestfs_lua_mkfs_btrfs },
  { "mklost_and_found", guestfs_lua_mklost_and_found },
  { "mkmountpoint", guestfs_lua_mkmountpoint },
  { "mknod", guestfs_lua_mknod },
  { "mknod_b", guestfs_lua_mknod_b },
  { "mknod_c", guestfs_lua_mknod_c },
  { "mkswap", guestfs_lua_mkswap },
  { "mkswap_L", guestfs_lua_mkswap_L },
  { "mkswap_U", guestfs_lua_mkswap_U },
  { "mkswap_file", guestfs_lua_mkswap_file },
  { "mktemp", guestfs_lua_mktemp },
  { "modprobe", guestfs_lua_modprobe },
  { "mount", guestfs_lua_mount },
  { "mount_9p", guestfs_lua_mount_9p },
  { "mount_local", guestfs_lua_mount_local },
  { "mount_local_run", guestfs_lua_mount_local_run },
  { "mount_loop", guestfs_lua_mount_loop },
  { "mount_options", guestfs_lua_mount_options },
  { "mount_ro", guestfs_lua_mount_ro },
  { "mount_vfs", guestfs_lua_mount_vfs },
  { "mountpoints", guestfs_lua_mountpoints },
  { "mounts", guestfs_lua_mounts },
  { "mv", guestfs_lua_mv },
  { "nr_devices", guestfs_lua_nr_devices },
  { "ntfs_3g_probe", guestfs_lua_ntfs_3g_probe },
  { "ntfsclone_in", guestfs_lua_ntfsclone_in },
  { "ntfsclone_out", guestfs_lua_ntfsclone_out },
  { "ntfsfix", guestfs_lua_ntfsfix },
  { "ntfsresize", guestfs_lua_ntfsresize },
  { "ntfsresize_size", guestfs_lua_ntfsresize_size },
  { "parse_environment", guestfs_lua_parse_environment },
  { "parse_environment_list", guestfs_lua_parse_environment_list },
  { "part_add", guestfs_lua_part_add },
  { "part_del", guestfs_lua_part_del },
  { "part_disk", guestfs_lua_part_disk },
  { "part_get_bootable", guestfs_lua_part_get_bootable },
  { "part_get_gpt_type", guestfs_lua_part_get_gpt_type },
  { "part_get_mbr_id", guestfs_lua_part_get_mbr_id },
  { "part_get_parttype", guestfs_lua_part_get_parttype },
  { "part_init", guestfs_lua_part_init },
  { "part_list", guestfs_lua_part_list },
  { "part_set_bootable", guestfs_lua_part_set_bootable },
  { "part_set_gpt_type", guestfs_lua_part_set_gpt_type },
  { "part_set_mbr_id", guestfs_lua_part_set_mbr_id },
  { "part_set_name", guestfs_lua_part_set_name },
  { "part_to_dev", guestfs_lua_part_to_dev },
  { "part_to_partnum", guestfs_lua_part_to_partnum },
  { "ping_daemon", guestfs_lua_ping_daemon },
  { "pread", guestfs_lua_pread },
  { "pread_device", guestfs_lua_pread_device },
  { "pvchange_uuid", guestfs_lua_pvchange_uuid },
  { "pvchange_uuid_all", guestfs_lua_pvchange_uuid_all },
  { "pvcreate", guestfs_lua_pvcreate },
  { "pvremove", guestfs_lua_pvremove },
  { "pvresize", guestfs_lua_pvresize },
  { "pvresize_size", guestfs_lua_pvresize_size },
  { "pvs", guestfs_lua_pvs },
  { "pvs_full", guestfs_lua_pvs_full },
  { "pvuuid", guestfs_lua_pvuuid },
  { "pwrite", guestfs_lua_pwrite },
  { "pwrite_device", guestfs_lua_pwrite_device },
  { "read_file", guestfs_lua_read_file },
  { "read_lines", guestfs_lua_read_lines },
  { "readdir", guestfs_lua_readdir },
  { "readlink", guestfs_lua_readlink },
  { "readlinklist", guestfs_lua_readlinklist },
  { "realpath", guestfs_lua_realpath },
  { "remove_drive", guestfs_lua_remove_drive },
  { "removexattr", guestfs_lua_removexattr },
  { "rename", guestfs_lua_rename },
  { "resize2fs", guestfs_lua_resize2fs },
  { "resize2fs_M", guestfs_lua_resize2fs_M },
  { "resize2fs_size", guestfs_lua_resize2fs_size },
  { "rm", guestfs_lua_rm },
  { "rm_f", guestfs_lua_rm_f },
  { "rm_rf", guestfs_lua_rm_rf },
  { "rmdir", guestfs_lua_rmdir },
  { "rmmountpoint", guestfs_lua_rmmountpoint },
  { "rsync", guestfs_lua_rsync },
  { "rsync_in", guestfs_lua_rsync_in },
  { "rsync_out", guestfs_lua_rsync_out },
  { "scrub_device", guestfs_lua_scrub_device },
  { "scrub_file", guestfs_lua_scrub_file },
  { "scrub_freespace", guestfs_lua_scrub_freespace },
  { "set_append", guestfs_lua_set_append },
  { "set_attach_method", guestfs_lua_set_attach_method },
  { "set_autosync", guestfs_lua_set_autosync },
  { "set_cachedir", guestfs_lua_set_cachedir },
  { "set_direct", guestfs_lua_set_direct },
  { "set_e2attrs", guestfs_lua_set_e2attrs },
  { "set_e2generation", guestfs_lua_set_e2generation },
  { "set_e2label", guestfs_lua_set_e2label },
  { "set_e2uuid", guestfs_lua_set_e2uuid },
  { "set_label", guestfs_lua_set_label },
  { "set_libvirt_requested_credential", guestfs_lua_set_libvirt_requested_credential },
  { "set_libvirt_supported_credentials", guestfs_lua_set_libvirt_supported_credentials },
  { "set_memsize", guestfs_lua_set_memsize },
  { "set_network", guestfs_lua_set_network },
  { "set_path", guestfs_lua_set_path },
  { "set_pgroup", guestfs_lua_set_pgroup },
  { "set_qemu", guestfs_lua_set_qemu },
  { "set_recovery_proc", guestfs_lua_set_recovery_proc },
  { "set_selinux", guestfs_lua_set_selinux },
  { "set_smp", guestfs_lua_set_smp },
  { "set_tmpdir", guestfs_lua_set_tmpdir },
  { "set_trace", guestfs_lua_set_trace },
  { "set_verbose", guestfs_lua_set_verbose },
  { "setcon", guestfs_lua_setcon },
  { "setxattr", guestfs_lua_setxattr },
  { "sfdisk", guestfs_lua_sfdisk },
  { "sfdiskM", guestfs_lua_sfdiskM },
  { "sfdisk_N", guestfs_lua_sfdisk_N },
  { "sfdisk_disk_geometry", guestfs_lua_sfdisk_disk_geometry },
  { "sfdisk_kernel_geometry", guestfs_lua_sfdisk_kernel_geometry },
  { "sfdisk_l", guestfs_lua_sfdisk_l },
  { "sh", guestfs_lua_sh },
  { "sh_lines", guestfs_lua_sh_lines },
  { "shutdown", guestfs_lua_shutdown },
  { "sleep", guestfs_lua_sleep },
  { "stat", guestfs_lua_stat },
  { "statvfs", guestfs_lua_statvfs },
  { "strings", guestfs_lua_strings },
  { "strings_e", guestfs_lua_strings_e },
  { "swapoff_device", guestfs_lua_swapoff_device },
  { "swapoff_file", guestfs_lua_swapoff_file },
  { "swapoff_label", guestfs_lua_swapoff_label },
  { "swapoff_uuid", guestfs_lua_swapoff_uuid },
  { "swapon_device", guestfs_lua_swapon_device },
  { "swapon_file", guestfs_lua_swapon_file },
  { "swapon_label", guestfs_lua_swapon_label },
  { "swapon_uuid", guestfs_lua_swapon_uuid },
  { "sync", guestfs_lua_sync },
  { "tail", guestfs_lua_tail },
  { "tail_n", guestfs_lua_tail_n },
  { "tar_in", guestfs_lua_tar_in },
  { "tar_out", guestfs_lua_tar_out },
  { "tgz_in", guestfs_lua_tgz_in },
  { "tgz_out", guestfs_lua_tgz_out },
  { "touch", guestfs_lua_touch },
  { "truncate", guestfs_lua_truncate },
  { "truncate_size", guestfs_lua_truncate_size },
  { "tune2fs", guestfs_lua_tune2fs },
  { "tune2fs_l", guestfs_lua_tune2fs_l },
  { "txz_in", guestfs_lua_txz_in },
  { "txz_out", guestfs_lua_txz_out },
  { "umask", guestfs_lua_umask },
  { "umount", guestfs_lua_umount },
  { "umount_all", guestfs_lua_umount_all },
  { "umount_local", guestfs_lua_umount_local },
  { "upload", guestfs_lua_upload },
  { "upload_offset", guestfs_lua_upload_offset },
  { "user_cancel", guestfs_lua_user_cancel },
  { "utimens", guestfs_lua_utimens },
  { "utsname", guestfs_lua_utsname },
  { "version", guestfs_lua_version },
  { "vfs_label", guestfs_lua_vfs_label },
  { "vfs_type", guestfs_lua_vfs_type },
  { "vfs_uuid", guestfs_lua_vfs_uuid },
  { "vg_activate", guestfs_lua_vg_activate },
  { "vg_activate_all", guestfs_lua_vg_activate_all },
  { "vgchange_uuid", guestfs_lua_vgchange_uuid },
  { "vgchange_uuid_all", guestfs_lua_vgchange_uuid_all },
  { "vgcreate", guestfs_lua_vgcreate },
  { "vglvuuids", guestfs_lua_vglvuuids },
  { "vgmeta", guestfs_lua_vgmeta },
  { "vgpvuuids", guestfs_lua_vgpvuuids },
  { "vgremove", guestfs_lua_vgremove },
  { "vgrename", guestfs_lua_vgrename },
  { "vgs", guestfs_lua_vgs },
  { "vgs_full", guestfs_lua_vgs_full },
  { "vgscan", guestfs_lua_vgscan },
  { "vguuid", guestfs_lua_vguuid },
  { "wait_ready", guestfs_lua_wait_ready },
  { "wc_c", guestfs_lua_wc_c },
  { "wc_l", guestfs_lua_wc_l },
  { "wc_w", guestfs_lua_wc_w },
  { "wipefs", guestfs_lua_wipefs },
  { "write", guestfs_lua_write },
  { "write_append", guestfs_lua_write_append },
  { "write_file", guestfs_lua_write_file },
  { "xfs_admin", guestfs_lua_xfs_admin },
  { "xfs_growfs", guestfs_lua_xfs_growfs },
  { "xfs_info", guestfs_lua_xfs_info },
  { "xfs_repair", guestfs_lua_xfs_repair },
  { "zegrep", guestfs_lua_zegrep },
  { "zegrepi", guestfs_lua_zegrepi },
  { "zero", guestfs_lua_zero },
  { "zero_device", guestfs_lua_zero_device },
  { "zero_free_space", guestfs_lua_zero_free_space },
  { "zerofree", guestfs_lua_zerofree },
  { "zfgrep", guestfs_lua_zfgrep },
  { "zfgrepi", guestfs_lua_zfgrepi },
  { "zfile", guestfs_lua_zfile },
  { "zgrep", guestfs_lua_zgrep },
  { "zgrepi", guestfs_lua_zgrepi },

  { NULL, NULL }
};

static void
make_version_string (char *version, size_t size)
{
  guestfs_h *g;
  struct guestfs_version *v;

  g = guestfs_create ();
  v = guestfs_version (g);
  snprintf (version, size,
            "libguestfs %" PRIi64 ".%" PRIi64 ".%" PRIi64 "%s",
            v->major, v->minor, v->release, v->extra);
  free (v);
  guestfs_close (g);
}

extern int luaopen_guestfs (lua_State *L);

int
luaopen_guestfs (lua_State *L)
{
  char v[256];

  /* Create metatable. */
  luaL_newmetatable (L, GUESTFS_LUA_HANDLE);
#if LUA_VERSION_NUM >= 502
  luaL_setfuncs (L, metamethods, 0);
#else
  luaL_register (L, NULL, metamethods);
#endif

  /* Create methods table. */
  lua_newtable (L);
#if LUA_VERSION_NUM >= 502
  luaL_setfuncs (L, methods, 0);
#else
  luaL_register (L, NULL, methods);
#endif

  /* Set __index field of metatable to point to methods table. */
  lua_setfield (L, -2, "__index");

  /* Pop metatable, it is no longer needed. */
  lua_pop (L, 1);

  /* Create module functions table. */
  lua_newtable (L);
#if LUA_VERSION_NUM >= 502
  luaL_setfuncs (L, functions, 0);
#else
  luaL_register (L, NULL, functions);
#endif

  /* Globals in the module namespace. */
  lua_pushliteral (L, "event_all");
  push_string_list (L, (char **) event_all);
  lua_settable (L, -3);

  /* Add _COPYRIGHT, etc. fields to the module namespace. */
  lua_pushliteral (L, "_COPYRIGHT");
  lua_pushliteral (L, "Copyright (C) 2009-2013 Red Hat Inc.");
  lua_settable (L, -3);

  lua_pushliteral (L, "_DESCRIPTION");
  lua_pushliteral (L, "Lua binding to libguestfs");
  lua_settable (L, -3);

  lua_pushliteral (L, "_VERSION");
  make_version_string (v, sizeof v);
  lua_pushlstring (L, v, strlen (v));
  lua_settable (L, -3);

  /* Return module table, so users choose their own name for the module:
   * local G = require "guestfs"
   * g = G.create ()
   */
  return 1;
}
