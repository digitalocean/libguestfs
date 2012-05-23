/* libguestfs generated file
 * WARNING: THIS FILE IS GENERATED FROM:
 *   generator/generator_*.ml
 * ANY CHANGES YOU MAKE TO THIS FILE WILL BE LOST.
 *
 * Copyright (C) 2009-2012 Red Hat Inc.
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

/* Error quark */

#define GUESTFS_ERROR guestfs_error_quark()

static GQuark
guestfs_error_quark(void)
{
  return g_quark_from_static_string("guestfs");
}

/* Cancellation handler */
static void
cancelled_handler(gpointer data)
{
  guestfs_h *g = (guestfs_h *)data;
  guestfs_user_cancel(g);
}

/* GuestfsSessionEventParams */
static GuestfsSessionEventParams *
guestfs_session_event_params_copy(GuestfsSessionEventParams *src)
{
  return g_slice_dup(GuestfsSessionEventParams, src);
}

static void
guestfs_session_event_params_free(GuestfsSessionEventParams *src)
{
  g_slice_free(GuestfsSessionEventParams, src);
}

G_DEFINE_BOXED_TYPE(GuestfsSessionEventParams,
                    guestfs_session_event_params,
                    guestfs_session_event_params_copy,
                    guestfs_session_event_params_free)

/* Event callback */
static guint signals[8] = { 0 };

static GuestfsSessionEvent
guestfs_session_event_from_guestfs_event(uint64_t event)
{
  switch(event) {
    case GUESTFS_EVENT_CLOSE: return GUESTFS_SESSION_EVENT_CLOSE;
    case GUESTFS_EVENT_SUBPROCESS_QUIT: return GUESTFS_SESSION_EVENT_SUBPROCESS_QUIT;
    case GUESTFS_EVENT_LAUNCH_DONE: return GUESTFS_SESSION_EVENT_LAUNCH_DONE;
    case GUESTFS_EVENT_PROGRESS: return GUESTFS_SESSION_EVENT_PROGRESS;
    case GUESTFS_EVENT_APPLIANCE: return GUESTFS_SESSION_EVENT_APPLIANCE;
    case GUESTFS_EVENT_LIBRARY: return GUESTFS_SESSION_EVENT_LIBRARY;
    case GUESTFS_EVENT_TRACE: return GUESTFS_SESSION_EVENT_TRACE;
    case GUESTFS_EVENT_ENTER: return GUESTFS_SESSION_EVENT_ENTER;
  }

  g_warning("guestfs_session_event_from_guestfs_event: invalid event %lu",
            event);
  return UINT32_MAX;
}

static void
event_callback(guestfs_h *g, void *opaque,
               uint64_t event, int event_handle,
               int flags,
               const char *buf, size_t buf_len,
               const uint64_t *array, size_t array_len)
{
  GuestfsSessionEventParams *params = g_slice_new0(GuestfsSessionEventParams);

  params->event = guestfs_session_event_from_guestfs_event(event);
  params->flags = flags;

  params->buf = g_byte_array_sized_new(buf_len);
  g_byte_array_append(params->buf, buf, buf_len);

  for(size_t i = 0; i < array_len && i < 4; i++) {
    if(array_len > 4) {
      array_len = 4;
    }
    memcpy(params->array, array, sizeof(array[0]) * array_len);
  }
  params->array_len = array_len;

  GuestfsSession *session = (GuestfsSession *) opaque;

  g_signal_emit(session, signals[params->event], 0, params);

  guestfs_session_event_params_free(params);
}

/* GuestfsSessionEvent */

GType
guestfs_session_event_get_type(void)
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
    };
    etype = g_enum_register_static("GuestfsSessionEvent", values);
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

G_DEFINE_TYPE(GuestfsSession, guestfs_session, G_TYPE_OBJECT);

static void
guestfs_session_finalize(GObject *object)
{
  GuestfsSession *session = GUESTFS_SESSION(object);
  GuestfsSessionPrivate *priv = session->priv;

  if (priv->g) guestfs_close(priv->g);

  G_OBJECT_CLASS(guestfs_session_parent_class)->finalize(object);
}

static void
guestfs_session_class_init(GuestfsSessionClass *klass)
{
  GObjectClass *object_class = G_OBJECT_CLASS(klass);

  object_class->finalize = guestfs_session_finalize;

  g_type_class_add_private(klass, sizeof(GuestfsSessionPrivate));

  /**
   * GuestfsSession::close:
   * @session: The session which emitted the signal
   * @params: An object containing event parameters
   *
   * See "SETTING CALLBACKS TO HANDLE EVENTS" in guestfs(3) for
   * more details about this event.
   */
  signals[GUESTFS_SESSION_EVENT_CLOSE] =
    g_signal_new(g_intern_static_string("close"),
                 G_OBJECT_CLASS_TYPE(object_class),
                 G_SIGNAL_RUN_LAST,
                 0,
                 NULL, NULL,
                 NULL,
                 G_TYPE_NONE,
                 1, guestfs_session_event_params_get_type());

  /**
   * GuestfsSession::subprocess_quit:
   * @session: The session which emitted the signal
   * @params: An object containing event parameters
   *
   * See "SETTING CALLBACKS TO HANDLE EVENTS" in guestfs(3) for
   * more details about this event.
   */
  signals[GUESTFS_SESSION_EVENT_SUBPROCESS_QUIT] =
    g_signal_new(g_intern_static_string("subprocess_quit"),
                 G_OBJECT_CLASS_TYPE(object_class),
                 G_SIGNAL_RUN_LAST,
                 0,
                 NULL, NULL,
                 NULL,
                 G_TYPE_NONE,
                 1, guestfs_session_event_params_get_type());

  /**
   * GuestfsSession::launch_done:
   * @session: The session which emitted the signal
   * @params: An object containing event parameters
   *
   * See "SETTING CALLBACKS TO HANDLE EVENTS" in guestfs(3) for
   * more details about this event.
   */
  signals[GUESTFS_SESSION_EVENT_LAUNCH_DONE] =
    g_signal_new(g_intern_static_string("launch_done"),
                 G_OBJECT_CLASS_TYPE(object_class),
                 G_SIGNAL_RUN_LAST,
                 0,
                 NULL, NULL,
                 NULL,
                 G_TYPE_NONE,
                 1, guestfs_session_event_params_get_type());

  /**
   * GuestfsSession::progress:
   * @session: The session which emitted the signal
   * @params: An object containing event parameters
   *
   * See "SETTING CALLBACKS TO HANDLE EVENTS" in guestfs(3) for
   * more details about this event.
   */
  signals[GUESTFS_SESSION_EVENT_PROGRESS] =
    g_signal_new(g_intern_static_string("progress"),
                 G_OBJECT_CLASS_TYPE(object_class),
                 G_SIGNAL_RUN_LAST,
                 0,
                 NULL, NULL,
                 NULL,
                 G_TYPE_NONE,
                 1, guestfs_session_event_params_get_type());

  /**
   * GuestfsSession::appliance:
   * @session: The session which emitted the signal
   * @params: An object containing event parameters
   *
   * See "SETTING CALLBACKS TO HANDLE EVENTS" in guestfs(3) for
   * more details about this event.
   */
  signals[GUESTFS_SESSION_EVENT_APPLIANCE] =
    g_signal_new(g_intern_static_string("appliance"),
                 G_OBJECT_CLASS_TYPE(object_class),
                 G_SIGNAL_RUN_LAST,
                 0,
                 NULL, NULL,
                 NULL,
                 G_TYPE_NONE,
                 1, guestfs_session_event_params_get_type());

  /**
   * GuestfsSession::library:
   * @session: The session which emitted the signal
   * @params: An object containing event parameters
   *
   * See "SETTING CALLBACKS TO HANDLE EVENTS" in guestfs(3) for
   * more details about this event.
   */
  signals[GUESTFS_SESSION_EVENT_LIBRARY] =
    g_signal_new(g_intern_static_string("library"),
                 G_OBJECT_CLASS_TYPE(object_class),
                 G_SIGNAL_RUN_LAST,
                 0,
                 NULL, NULL,
                 NULL,
                 G_TYPE_NONE,
                 1, guestfs_session_event_params_get_type());

  /**
   * GuestfsSession::trace:
   * @session: The session which emitted the signal
   * @params: An object containing event parameters
   *
   * See "SETTING CALLBACKS TO HANDLE EVENTS" in guestfs(3) for
   * more details about this event.
   */
  signals[GUESTFS_SESSION_EVENT_TRACE] =
    g_signal_new(g_intern_static_string("trace"),
                 G_OBJECT_CLASS_TYPE(object_class),
                 G_SIGNAL_RUN_LAST,
                 0,
                 NULL, NULL,
                 NULL,
                 G_TYPE_NONE,
                 1, guestfs_session_event_params_get_type());

  /**
   * GuestfsSession::enter:
   * @session: The session which emitted the signal
   * @params: An object containing event parameters
   *
   * See "SETTING CALLBACKS TO HANDLE EVENTS" in guestfs(3) for
   * more details about this event.
   */
  signals[GUESTFS_SESSION_EVENT_ENTER] =
    g_signal_new(g_intern_static_string("enter"),
                 G_OBJECT_CLASS_TYPE(object_class),
                 G_SIGNAL_RUN_LAST,
                 0,
                 NULL, NULL,
                 NULL,
                 G_TYPE_NONE,
                 1, guestfs_session_event_params_get_type());
}

static void
guestfs_session_init(GuestfsSession *session)
{
  session->priv = GUESTFS_SESSION_GET_PRIVATE(session);
  session->priv->g = guestfs_create();

  guestfs_h *g = session->priv->g;

  session->priv->event_handle =
    guestfs_set_event_callback(g, event_callback, GUESTFS_EVENT_ALL,
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
guestfs_session_new(void)
{
  return GUESTFS_SESSION(g_object_new(GUESTFS_TYPE_SESSION, NULL));
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
guestfs_session_close(GuestfsSession *session, GError **err)
{
  guestfs_h *g = session->priv->g;

  if (g == NULL) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, "session is already closed");
    return FALSE;
  }

  guestfs_close(g);
  session->priv->g = NULL;

  return TRUE;
}
/**
 * guestfs_session_test0:
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
 * @optargs: (transfer none) (allow-none): a GuestfsTest0 containing optional arguments
 * @cancellable: A GCancellable object
 * @err: A GError object to receive any generated errors
 *
 * internal test function - do not use
 *
 * This is an internal test function which is used to test whether the
 * automatically generated bindings can handle every possible parameter
 * type correctly.
 * 
 * It echos the contents of each parameter to stdout.
 * 
 * You probably don't want to call this function.
 * 
 * Returns: true on success, false on error
 */
gboolean
guestfs_session_test0(GuestfsSession *session, const gchar *str, const gchar *optstr, gchar *const *strlist, gboolean b, gint32 integer, gint64 integer64, const gchar *filein, const gchar *fileout, const guint8 *bufferin, gsize bufferin_size, GuestfsTest0 *optargs, GCancellable *cancellable, GError **err)
{
  /* Check we haven't already been cancelled */
  if (g_cancellable_set_error_if_cancelled (cancellable, err))
    return FALSE;

  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "test0");
    return FALSE;
  }

  struct guestfs_test0_argv argv;
  struct guestfs_test0_argv *argvp = NULL;

  if (optargs) {
    argv.bitmask = 0;

    GValue obool_v = {0, };
    g_value_init(&obool_v, GUESTFS_TYPE_TRISTATE);
    g_object_get_property(G_OBJECT(optargs), "obool", &obool_v);
    GuestfsTristate obool = g_value_get_enum(&obool_v);
    if (obool != GUESTFS_TRISTATE_NONE) {
      argv.bitmask |= GUESTFS_TEST0_OBOOL_BITMASK;
      argv.obool = obool;
    }
    GValue oint_v = {0, };
    g_value_init(&oint_v, G_TYPE_INT);
    g_object_get_property(G_OBJECT(optargs), "oint", &oint_v);
    gint32 oint = g_value_get_int(&oint_v);
    if (oint != -1) {
      argv.bitmask |= GUESTFS_TEST0_OINT_BITMASK;
      argv.oint = oint;
    }
    GValue oint64_v = {0, };
    g_value_init(&oint64_v, G_TYPE_INT64);
    g_object_get_property(G_OBJECT(optargs), "oint64", &oint64_v);
    gint64 oint64 = g_value_get_int64(&oint64_v);
    if (oint64 != -1) {
      argv.bitmask |= GUESTFS_TEST0_OINT64_BITMASK;
      argv.oint64 = oint64;
    }
    GValue ostring_v = {0, };
    g_value_init(&ostring_v, G_TYPE_STRING);
    g_object_get_property(G_OBJECT(optargs), "ostring", &ostring_v);
    const gchar *ostring = g_value_get_string(&ostring_v);
    if (ostring != NULL) {
      argv.bitmask |= GUESTFS_TEST0_OSTRING_BITMASK;
      argv.ostring = ostring;
    }
    argvp = &argv;
  }
  gulong id = 0;
  if (cancellable) {
    id = g_cancellable_connect(cancellable,
                               G_CALLBACK(cancelled_handler),
                               g, NULL);
  }

  int ret = guestfs_test0_argv(g, str, optstr, strlist, b, integer, integer64, filein, fileout, bufferin, bufferin_size, argvp);
  g_cancellable_disconnect(cancellable, id);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return FALSE;
  }

  return TRUE;
}

/**
 * guestfs_session_test0rint:
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
guestfs_session_test0rint(GuestfsSession *session, const gchar *val, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "test0rint");
    return -1;
  }

  int ret = guestfs_test0rint(g, val);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return -1;
  }

  return ret;
}

/**
 * guestfs_session_test0rinterr:
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
guestfs_session_test0rinterr(GuestfsSession *session, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "test0rinterr");
    return -1;
  }

  int ret = guestfs_test0rinterr(g);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return -1;
  }

  return ret;
}

/**
 * guestfs_session_test0rint64:
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
guestfs_session_test0rint64(GuestfsSession *session, const gchar *val, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "test0rint64");
    return -1;
  }

  int64_t ret = guestfs_test0rint64(g, val);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return -1;
  }

  return ret;
}

/**
 * guestfs_session_test0rint64err:
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
guestfs_session_test0rint64err(GuestfsSession *session, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "test0rint64err");
    return -1;
  }

  int64_t ret = guestfs_test0rint64err(g);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return -1;
  }

  return ret;
}

/**
 * guestfs_session_test0rbool:
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
guestfs_session_test0rbool(GuestfsSession *session, const gchar *val, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "test0rbool");
    return -1;
  }

  int ret = guestfs_test0rbool(g, val);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return -1;
  }

  return ret;
}

/**
 * guestfs_session_test0rboolerr:
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
guestfs_session_test0rboolerr(GuestfsSession *session, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "test0rboolerr");
    return -1;
  }

  int ret = guestfs_test0rboolerr(g);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return -1;
  }

  return ret;
}

/**
 * guestfs_session_test0rconststring:
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
guestfs_session_test0rconststring(GuestfsSession *session, const gchar *val, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "test0rconststring");
    return NULL;
  }

  const char *ret = guestfs_test0rconststring(g, val);
  if (ret == NULL) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return NULL;
  }

  return ret;
}

/**
 * guestfs_session_test0rconststringerr:
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
guestfs_session_test0rconststringerr(GuestfsSession *session, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "test0rconststringerr");
    return NULL;
  }

  const char *ret = guestfs_test0rconststringerr(g);
  if (ret == NULL) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return NULL;
  }

  return ret;
}

/**
 * guestfs_session_test0rconstoptstring:
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
guestfs_session_test0rconstoptstring(GuestfsSession *session, const gchar *val, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "test0rconstoptstring");
    return NULL;
  }

  const char *ret = guestfs_test0rconstoptstring(g, val);

  return ret;
}

/**
 * guestfs_session_test0rconstoptstringerr:
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
guestfs_session_test0rconstoptstringerr(GuestfsSession *session, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "test0rconstoptstringerr");
    return NULL;
  }

  const char *ret = guestfs_test0rconstoptstringerr(g);

  return ret;
}

/**
 * guestfs_session_test0rstring:
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
guestfs_session_test0rstring(GuestfsSession *session, const gchar *val, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "test0rstring");
    return NULL;
  }

  char *ret = guestfs_test0rstring(g, val);
  if (ret == NULL) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return NULL;
  }

  return ret;
}

/**
 * guestfs_session_test0rstringerr:
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
guestfs_session_test0rstringerr(GuestfsSession *session, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "test0rstringerr");
    return NULL;
  }

  char *ret = guestfs_test0rstringerr(g);
  if (ret == NULL) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return NULL;
  }

  return ret;
}

/**
 * guestfs_session_test0rstringlist:
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
guestfs_session_test0rstringlist(GuestfsSession *session, const gchar *val, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "test0rstringlist");
    return NULL;
  }

  char **ret = guestfs_test0rstringlist(g, val);
  if (ret == NULL) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return NULL;
  }

  return ret;
}

/**
 * guestfs_session_test0rstringlisterr:
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
guestfs_session_test0rstringlisterr(GuestfsSession *session, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "test0rstringlisterr");
    return NULL;
  }

  char **ret = guestfs_test0rstringlisterr(g);
  if (ret == NULL) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return NULL;
  }

  return ret;
}

/**
 * guestfs_session_test0rstruct:
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
guestfs_session_test0rstruct(GuestfsSession *session, const gchar *val, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "test0rstruct");
    return NULL;
  }

  struct guestfs_lvm_pv *ret = guestfs_test0rstruct(g, val);
  if (ret == NULL) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return NULL;
  }

  GuestfsPV *s = g_slice_new0(GuestfsPV);
  if (ret->pv_name) s->pv_name = g_strdup(ret->pv_name);
  if (ret->pv_uuid) memcpy(s->pv_uuid, ret->pv_uuid, sizeof(s->pv_uuid));
  if (ret->pv_fmt) s->pv_fmt = g_strdup(ret->pv_fmt);
  s->pv_size = ret->pv_size;
  s->dev_size = ret->dev_size;
  s->pv_free = ret->pv_free;
  s->pv_used = ret->pv_used;
  if (ret->pv_attr) s->pv_attr = g_strdup(ret->pv_attr);
  s->pv_pe_count = ret->pv_pe_count;
  s->pv_pe_alloc_count = ret->pv_pe_alloc_count;
  if (ret->pv_tags) s->pv_tags = g_strdup(ret->pv_tags);
  s->pe_start = ret->pe_start;
  s->pv_mda_count = ret->pv_mda_count;
  s->pv_mda_free = ret->pv_mda_free;
  guestfs_free_lvm_pv(ret);
  return s;
}

/**
 * guestfs_session_test0rstructerr:
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
guestfs_session_test0rstructerr(GuestfsSession *session, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "test0rstructerr");
    return NULL;
  }

  struct guestfs_lvm_pv *ret = guestfs_test0rstructerr(g);
  if (ret == NULL) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return NULL;
  }

  GuestfsPV *s = g_slice_new0(GuestfsPV);
  if (ret->pv_name) s->pv_name = g_strdup(ret->pv_name);
  if (ret->pv_uuid) memcpy(s->pv_uuid, ret->pv_uuid, sizeof(s->pv_uuid));
  if (ret->pv_fmt) s->pv_fmt = g_strdup(ret->pv_fmt);
  s->pv_size = ret->pv_size;
  s->dev_size = ret->dev_size;
  s->pv_free = ret->pv_free;
  s->pv_used = ret->pv_used;
  if (ret->pv_attr) s->pv_attr = g_strdup(ret->pv_attr);
  s->pv_pe_count = ret->pv_pe_count;
  s->pv_pe_alloc_count = ret->pv_pe_alloc_count;
  if (ret->pv_tags) s->pv_tags = g_strdup(ret->pv_tags);
  s->pe_start = ret->pe_start;
  s->pv_mda_count = ret->pv_mda_count;
  s->pv_mda_free = ret->pv_mda_free;
  guestfs_free_lvm_pv(ret);
  return s;
}

/**
 * guestfs_session_test0rstructlist:
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
guestfs_session_test0rstructlist(GuestfsSession *session, const gchar *val, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "test0rstructlist");
    return NULL;
  }

  struct guestfs_lvm_pv_list *ret = guestfs_test0rstructlist(g, val);
  if (ret == NULL) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return NULL;
  }

  GuestfsPV **l = g_malloc(sizeof(GuestfsPV*) * (ret->len + 1));
  gsize i;
  for (i = 0; i < ret->len; i++) {
    l[i] = g_slice_new0(GuestfsPV);
    if (ret->val[i].pv_name) l[i]->pv_name = g_strdup(ret->val[i].pv_name);
    if (ret->val[i].pv_uuid) memcpy(l[i]->pv_uuid, ret->val[i].pv_uuid, sizeof(l[i]->pv_uuid));
    if (ret->val[i].pv_fmt) l[i]->pv_fmt = g_strdup(ret->val[i].pv_fmt);
    l[i]->pv_size = ret->val[i].pv_size;
    l[i]->dev_size = ret->val[i].dev_size;
    l[i]->pv_free = ret->val[i].pv_free;
    l[i]->pv_used = ret->val[i].pv_used;
    if (ret->val[i].pv_attr) l[i]->pv_attr = g_strdup(ret->val[i].pv_attr);
    l[i]->pv_pe_count = ret->val[i].pv_pe_count;
    l[i]->pv_pe_alloc_count = ret->val[i].pv_pe_alloc_count;
    if (ret->val[i].pv_tags) l[i]->pv_tags = g_strdup(ret->val[i].pv_tags);
    l[i]->pe_start = ret->val[i].pe_start;
    l[i]->pv_mda_count = ret->val[i].pv_mda_count;
    l[i]->pv_mda_free = ret->val[i].pv_mda_free;
  }
  guestfs_free_lvm_pv_list(ret);
  l[i] = NULL;
  return l;
}

/**
 * guestfs_session_test0rstructlisterr:
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
guestfs_session_test0rstructlisterr(GuestfsSession *session, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "test0rstructlisterr");
    return NULL;
  }

  struct guestfs_lvm_pv_list *ret = guestfs_test0rstructlisterr(g);
  if (ret == NULL) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return NULL;
  }

  GuestfsPV **l = g_malloc(sizeof(GuestfsPV*) * (ret->len + 1));
  gsize i;
  for (i = 0; i < ret->len; i++) {
    l[i] = g_slice_new0(GuestfsPV);
    if (ret->val[i].pv_name) l[i]->pv_name = g_strdup(ret->val[i].pv_name);
    if (ret->val[i].pv_uuid) memcpy(l[i]->pv_uuid, ret->val[i].pv_uuid, sizeof(l[i]->pv_uuid));
    if (ret->val[i].pv_fmt) l[i]->pv_fmt = g_strdup(ret->val[i].pv_fmt);
    l[i]->pv_size = ret->val[i].pv_size;
    l[i]->dev_size = ret->val[i].dev_size;
    l[i]->pv_free = ret->val[i].pv_free;
    l[i]->pv_used = ret->val[i].pv_used;
    if (ret->val[i].pv_attr) l[i]->pv_attr = g_strdup(ret->val[i].pv_attr);
    l[i]->pv_pe_count = ret->val[i].pv_pe_count;
    l[i]->pv_pe_alloc_count = ret->val[i].pv_pe_alloc_count;
    if (ret->val[i].pv_tags) l[i]->pv_tags = g_strdup(ret->val[i].pv_tags);
    l[i]->pe_start = ret->val[i].pe_start;
    l[i]->pv_mda_count = ret->val[i].pv_mda_count;
    l[i]->pv_mda_free = ret->val[i].pv_mda_free;
  }
  guestfs_free_lvm_pv_list(ret);
  l[i] = NULL;
  return l;
}

/**
 * guestfs_session_test0rhashtable:
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
guestfs_session_test0rhashtable(GuestfsSession *session, const gchar *val, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "test0rhashtable");
    return NULL;
  }

  char **ret = guestfs_test0rhashtable(g, val);
  if (ret == NULL) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return NULL;
  }

  GHashTable *h = g_hash_table_new_full(g_str_hash, g_str_equal, g_free, g_free);
  char **i = ret;
  while (*i) {
    char *key = *i; i++;
    char *value = *i; i++;
    g_hash_table_insert(h, key, value);
  };
  g_free(ret);
  return h;
}

/**
 * guestfs_session_test0rhashtableerr:
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
guestfs_session_test0rhashtableerr(GuestfsSession *session, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "test0rhashtableerr");
    return NULL;
  }

  char **ret = guestfs_test0rhashtableerr(g);
  if (ret == NULL) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return NULL;
  }

  GHashTable *h = g_hash_table_new_full(g_str_hash, g_str_equal, g_free, g_free);
  char **i = ret;
  while (*i) {
    char *key = *i; i++;
    char *value = *i; i++;
    g_hash_table_insert(h, key, value);
  };
  g_free(ret);
  return h;
}

/**
 * guestfs_session_test0rbufferout:
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
guestfs_session_test0rbufferout(GuestfsSession *session, const gchar *val, gsize *size_r, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "test0rbufferout");
    return NULL;
  }

  char *ret = guestfs_test0rbufferout(g, val, size_r);
  if (ret == NULL) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return NULL;
  }

  return ret;
}

/**
 * guestfs_session_test0rbufferouterr:
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
guestfs_session_test0rbufferouterr(GuestfsSession *session, gsize *size_r, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "test0rbufferouterr");
    return NULL;
  }

  char *ret = guestfs_test0rbufferouterr(g, size_r);
  if (ret == NULL) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return NULL;
  }

  return ret;
}

/**
 * guestfs_session_launch:
 * @session: (transfer none): A GuestfsSession object
 * @err: A GError object to receive any generated errors
 *
 * launch the qemu subprocess
 *
 * Internally libguestfs is implemented by running a virtual machine using
 * qemu(1).
 * 
 * You should call this after configuring the handle (eg. adding drives)
 * but before performing any actions.
 * 
 * Returns: true on success, false on error
 */
gboolean
guestfs_session_launch(GuestfsSession *session, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "launch");
    return FALSE;
  }

  int ret = guestfs_launch(g);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return FALSE;
  }

  return TRUE;
}

/**
 * guestfs_session_wait_ready:
 * @session: (transfer none): A GuestfsSession object
 * @err: A GError object to receive any generated errors
 *
 * wait until the qemu subprocess launches (no op)
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
 */
gboolean
guestfs_session_wait_ready(GuestfsSession *session, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "wait_ready");
    return FALSE;
  }

  int ret = guestfs_wait_ready(g);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return FALSE;
  }

  return TRUE;
}

/**
 * guestfs_session_kill_subprocess:
 * @session: (transfer none): A GuestfsSession object
 * @err: A GError object to receive any generated errors
 *
 * kill the qemu subprocess
 *
 * This kills the qemu subprocess. You should never need to call this.
 * 
 * Returns: true on success, false on error
 */
gboolean
guestfs_session_kill_subprocess(GuestfsSession *session, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "kill_subprocess");
    return FALSE;
  }

  int ret = guestfs_kill_subprocess(g);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return FALSE;
  }

  return TRUE;
}

/**
 * guestfs_session_add_drive:
 * @session: (transfer none): A GuestfsSession object
 * @filename: (transfer none) (type utf8):
 * @err: A GError object to receive any generated errors
 *
 * add an image to examine or modify
 *
 * This function is the equivalent of calling
 * guestfs_session_add_drive_opts() with no optional parameters, so the
 * disk is added writable, with the format being detected automatically.
 * 
 * Automatic detection of the format opens you up to a potential security
 * hole when dealing with untrusted raw-format images. See <ulink
 * url='https://cve.mitre.org/cgi-bin/cvename.cgi?name=CVE-2010-3851'>
 * CVE-2010-3851 </ulink> and <ulink
 * url='https://bugzilla.redhat.com/show_bug.cgi?id=642934'>
 * RHBZ&num;642934 </ulink>. Specifying the format closes this security
 * hole. Therefore you should think about replacing calls to this function
 * with calls to guestfs_session_add_drive_opts(), and specifying the
 * format.
 * 
 * Returns: true on success, false on error
 */
gboolean
guestfs_session_add_drive(GuestfsSession *session, const gchar *filename, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "add_drive");
    return FALSE;
  }

  int ret = guestfs_add_drive(g, filename);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
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
 * This is equivalent to the qemu parameter *-cdrom filename*.
 * 
 * Notes:
 * 
 * *   This call checks for the existence of @filename. This stops you from
 * specifying other types of drive which are supported by qemu such as
 * "nbd:" and "http:" URLs. To specify those, use the general
 * guestfs_session_config() call instead.
 * 
 * *   If you just want to add an ISO file (often you use this as an
 * efficient way to transfer large files into the guest), then you
 * should probably use guestfs_session_add_drive_ro() instead.
 * 
 * Returns: true on success, false on error
 */
gboolean
guestfs_session_add_cdrom(GuestfsSession *session, const gchar *filename, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "add_cdrom");
    return FALSE;
  }

  int ret = guestfs_add_cdrom(g, filename);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
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
 */
gboolean
guestfs_session_add_drive_ro(GuestfsSession *session, const gchar *filename, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "add_drive_ro");
    return FALSE;
  }

  int ret = guestfs_add_drive_ro(g, filename);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return FALSE;
  }

  return TRUE;
}

/**
 * guestfs_session_config:
 * @session: (transfer none): A GuestfsSession object
 * @qemuparam: (transfer none) (type utf8):
 * @qemuvalue: (transfer none) (type utf8) (allow-none):
 * @err: A GError object to receive any generated errors
 *
 * add qemu parameters
 *
 * This can be used to add arbitrary qemu command line parameters of the
 * form *-param value*. Actually it's not quite arbitrary - we prevent you
 * from setting some parameters which would interfere with parameters that
 * we use.
 * 
 * The first character of @param string must be a @- (dash).
 * 
 * @value can be NULL.
 * 
 * Returns: true on success, false on error
 */
gboolean
guestfs_session_config(GuestfsSession *session, const gchar *qemuparam, const gchar *qemuvalue, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "config");
    return FALSE;
  }

  int ret = guestfs_config(g, qemuparam, qemuvalue);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return FALSE;
  }

  return TRUE;
}

/**
 * guestfs_session_set_qemu:
 * @session: (transfer none): A GuestfsSession object
 * @qemu: (transfer none) (type utf8) (allow-none):
 * @err: A GError object to receive any generated errors
 *
 * set the qemu binary
 *
 * Set the qemu binary that we will use.
 * 
 * The default is chosen when the library was compiled by the configure
 * script.
 * 
 * You can also override this by setting the @LIBGUESTFS_QEMU environment
 * variable.
 * 
 * Setting @qemu to @NULL restores the default qemu binary.
 * 
 * Note that you should call this function as early as possible after
 * creating the handle. This is because some pre-launch operations depend
 * on testing qemu features (by running "qemu -help"). If the qemu binary
 * changes, we don't retest features, and so you might see inconsistent
 * results. Using the environment variable @LIBGUESTFS_QEMU is safest of
 * all since that picks the qemu binary at the same time as the handle is
 * created.
 * 
 * Returns: true on success, false on error
 */
gboolean
guestfs_session_set_qemu(GuestfsSession *session, const gchar *qemu, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "set_qemu");
    return FALSE;
  }

  int ret = guestfs_set_qemu(g, qemu);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return FALSE;
  }

  return TRUE;
}

/**
 * guestfs_session_get_qemu:
 * @session: (transfer none): A GuestfsSession object
 * @err: A GError object to receive any generated errors
 *
 * get the qemu binary
 *
 * Return the current qemu binary.
 * 
 * This is always non-NULL. If it wasn't set already, then this will return
 * the default qemu binary name.
 * 
 * Returns: (transfer none): the returned string, or NULL on error
 */
const gchar *
guestfs_session_get_qemu(GuestfsSession *session, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "get_qemu");
    return NULL;
  }

  const char *ret = guestfs_get_qemu(g);
  if (ret == NULL) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return NULL;
  }

  return ret;
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
 */
gboolean
guestfs_session_set_path(GuestfsSession *session, const gchar *searchpath, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "set_path");
    return FALSE;
  }

  int ret = guestfs_set_path(g, searchpath);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return FALSE;
  }

  return TRUE;
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
 */
const gchar *
guestfs_session_get_path(GuestfsSession *session, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "get_path");
    return NULL;
  }

  const char *ret = guestfs_get_path(g);
  if (ret == NULL) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return NULL;
  }

  return ret;
}

/**
 * guestfs_session_set_append:
 * @session: (transfer none): A GuestfsSession object
 * @append: (transfer none) (type utf8) (allow-none):
 * @err: A GError object to receive any generated errors
 *
 * add options to kernel command line
 *
 * This function is used to add additional options to the guest kernel
 * command line.
 * 
 * The default is @NULL unless overridden by setting @LIBGUESTFS_APPEND
 * environment variable.
 * 
 * Setting @append to @NULL means *no* additional options are passed
 * (libguestfs always adds a few of its own).
 * 
 * Returns: true on success, false on error
 */
gboolean
guestfs_session_set_append(GuestfsSession *session, const gchar *append, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "set_append");
    return FALSE;
  }

  int ret = guestfs_set_append(g, append);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
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
 * Return the additional kernel options which are added to the guest kernel
 * command line.
 * 
 * If @NULL then no options are added.
 * 
 * Returns: (transfer none): the returned string. Note that NULL does not indicate error
 */
const gchar *
guestfs_session_get_append(GuestfsSession *session, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "get_append");
    return NULL;
  }

  const char *ret = guestfs_get_append(g);

  return ret;
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
 */
gboolean
guestfs_session_set_autosync(GuestfsSession *session, gboolean autosync, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "set_autosync");
    return FALSE;
  }

  int ret = guestfs_set_autosync(g, autosync);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return FALSE;
  }

  return TRUE;
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
 */
gint8
guestfs_session_get_autosync(GuestfsSession *session, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "get_autosync");
    return -1;
  }

  int ret = guestfs_get_autosync(g);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return -1;
  }

  return ret;
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
 */
gboolean
guestfs_session_set_verbose(GuestfsSession *session, gboolean verbose, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "set_verbose");
    return FALSE;
  }

  int ret = guestfs_set_verbose(g, verbose);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return FALSE;
  }

  return TRUE;
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
 */
gint8
guestfs_session_get_verbose(GuestfsSession *session, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "get_verbose");
    return -1;
  }

  int ret = guestfs_get_verbose(g);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
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
 */
gint8
guestfs_session_is_ready(GuestfsSession *session, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "is_ready");
    return -1;
  }

  int ret = guestfs_is_ready(g);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
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
 */
gint8
guestfs_session_is_config(GuestfsSession *session, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "is_config");
    return -1;
  }

  int ret = guestfs_is_config(g);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
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
 */
gint8
guestfs_session_is_launching(GuestfsSession *session, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "is_launching");
    return -1;
  }

  int ret = guestfs_is_launching(g);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
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
 * This always returns false. Do not use this function.
 * 
 * For more information on states, see guestfs(3).
 * 
 * Returns: the returned value, or -1 on error
 */
gint8
guestfs_session_is_busy(GuestfsSession *session, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "is_busy");
    return -1;
  }

  int ret = guestfs_is_busy(g);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
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
 */
gint32
guestfs_session_get_state(GuestfsSession *session, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "get_state");
    return -1;
  }

  int ret = guestfs_get_state(g);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return -1;
  }

  return ret;
}

/**
 * guestfs_session_set_memsize:
 * @session: (transfer none): A GuestfsSession object
 * @memsize: (type gint32):
 * @err: A GError object to receive any generated errors
 *
 * set memory allocated to the qemu subprocess
 *
 * This sets the memory size in megabytes allocated to the qemu subprocess.
 * This only has any effect if called before guestfs_session_launch().
 * 
 * You can also change this by setting the environment variable
 * @LIBGUESTFS_MEMSIZE before the handle is created.
 * 
 * For more information on the architecture of libguestfs, see guestfs(3).
 * 
 * Returns: true on success, false on error
 */
gboolean
guestfs_session_set_memsize(GuestfsSession *session, gint32 memsize, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "set_memsize");
    return FALSE;
  }

  int ret = guestfs_set_memsize(g, memsize);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return FALSE;
  }

  return TRUE;
}

/**
 * guestfs_session_get_memsize:
 * @session: (transfer none): A GuestfsSession object
 * @err: A GError object to receive any generated errors
 *
 * get memory allocated to the qemu subprocess
 *
 * This gets the memory size in megabytes allocated to the qemu subprocess.
 * 
 * If guestfs_session_set_memsize() was not called on this handle, and if
 * @LIBGUESTFS_MEMSIZE was not set, then this returns the compiled-in
 * default value for memsize.
 * 
 * For more information on the architecture of libguestfs, see guestfs(3).
 * 
 * Returns: the returned value, or -1 on error
 */
gint32
guestfs_session_get_memsize(GuestfsSession *session, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "get_memsize");
    return -1;
  }

  int ret = guestfs_get_memsize(g);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return -1;
  }

  return ret;
}

/**
 * guestfs_session_get_pid:
 * @session: (transfer none): A GuestfsSession object
 * @err: A GError object to receive any generated errors
 *
 * get PID of qemu subprocess
 *
 * Return the process ID of the qemu subprocess. If there is no qemu
 * subprocess, then this will return an error.
 * 
 * This is an internal call used for debugging and testing.
 * 
 * Returns: the returned value, or -1 on error
 */
gint32
guestfs_session_get_pid(GuestfsSession *session, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "get_pid");
    return -1;
  }

  int ret = guestfs_get_pid(g);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return -1;
  }

  return ret;
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
 * "libguestfs.so" library.
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
 * Use guestfs_session_available() instead.
 * 
 * Returns: (transfer full): a Version object, or NULL on error
 */
GuestfsVersion *
guestfs_session_version(GuestfsSession *session, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "version");
    return NULL;
  }

  struct guestfs_version *ret = guestfs_version(g);
  if (ret == NULL) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return NULL;
  }

  GuestfsVersion *s = g_slice_new0(GuestfsVersion);
  s->major = ret->major;
  s->minor = ret->minor;
  s->release = ret->release;
  if (ret->extra) s->extra = g_strdup(ret->extra);
  guestfs_free_version(ret);
  return s;
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
 */
gboolean
guestfs_session_set_selinux(GuestfsSession *session, gboolean selinux, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "set_selinux");
    return FALSE;
  }

  int ret = guestfs_set_selinux(g, selinux);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return FALSE;
  }

  return TRUE;
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
 */
gint8
guestfs_session_get_selinux(GuestfsSession *session, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "get_selinux");
    return -1;
  }

  int ret = guestfs_get_selinux(g);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return -1;
  }

  return ret;
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
 */
gboolean
guestfs_session_set_trace(GuestfsSession *session, gboolean trace, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "set_trace");
    return FALSE;
  }

  int ret = guestfs_set_trace(g, trace);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return FALSE;
  }

  return TRUE;
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
 */
gint8
guestfs_session_get_trace(GuestfsSession *session, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "get_trace");
    return -1;
  }

  int ret = guestfs_get_trace(g);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return -1;
  }

  return ret;
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
 */
gboolean
guestfs_session_set_direct(GuestfsSession *session, gboolean direct, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "set_direct");
    return FALSE;
  }

  int ret = guestfs_set_direct(g, direct);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return FALSE;
  }

  return TRUE;
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
 */
gint8
guestfs_session_get_direct(GuestfsSession *session, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "get_direct");
    return -1;
  }

  int ret = guestfs_get_direct(g);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return -1;
  }

  return ret;
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
 * of the recovery process is to stop runaway qemu processes in the case
 * where the main program aborts abruptly.
 * 
 * This only has any effect if called before guestfs_session_launch(), and
 * the default is true.
 * 
 * About the only time when you would want to disable this is if the main
 * process will fork itself into the background ("daemonize" itself). In
 * this case the recovery process thinks that the main program has
 * disappeared and so kills qemu, which is not very helpful.
 * 
 * Returns: true on success, false on error
 */
gboolean
guestfs_session_set_recovery_proc(GuestfsSession *session, gboolean recoveryproc, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "set_recovery_proc");
    return FALSE;
  }

  int ret = guestfs_set_recovery_proc(g, recoveryproc);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return FALSE;
  }

  return TRUE;
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
 */
gint8
guestfs_session_get_recovery_proc(GuestfsSession *session, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "get_recovery_proc");
    return -1;
  }

  int ret = guestfs_get_recovery_proc(g);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return -1;
  }

  return ret;
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
 */
gboolean
guestfs_session_add_drive_with_if(GuestfsSession *session, const gchar *filename, const gchar *iface, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "add_drive_with_if");
    return FALSE;
  }

  int ret = guestfs_add_drive_with_if(g, filename, iface);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
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
 */
gboolean
guestfs_session_add_drive_ro_with_if(GuestfsSession *session, const gchar *filename, const gchar *iface, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "add_drive_ro_with_if");
    return FALSE;
  }

  int ret = guestfs_add_drive_ro_with_if(g, filename, iface);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return FALSE;
  }

  return TRUE;
}

/**
 * guestfs_session_file_architecture:
 * @session: (transfer none): A GuestfsSession object
 * @filename: (transfer none) (type filename):
 * @err: A GError object to receive any generated errors
 *
 * detect the architecture of a binary file
 *
 * This detects the architecture of the binary @filename, and returns it if
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
 */
gchar *
guestfs_session_file_architecture(GuestfsSession *session, const gchar *filename, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "file_architecture");
    return NULL;
  }

  char *ret = guestfs_file_architecture(g, filename);
  if (ret == NULL) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return NULL;
  }

  return ret;
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
 */
gchar **
guestfs_session_inspect_os(GuestfsSession *session, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "inspect_os");
    return NULL;
  }

  char **ret = guestfs_inspect_os(g);
  if (ret == NULL) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
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
 * "hurd"
 * GNU/Hurd.
 * 
 * "dos"
 * MS-DOS, FreeDOS and others.
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
 */
gchar *
guestfs_session_inspect_get_type(GuestfsSession *session, const gchar *root, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "inspect_get_type");
    return NULL;
  }

  char *ret = guestfs_inspect_get_type(g, root);
  if (ret == NULL) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return NULL;
  }

  return ret;
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
 */
gchar *
guestfs_session_inspect_get_arch(GuestfsSession *session, const gchar *root, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "inspect_get_arch");
    return NULL;
  }

  char *ret = guestfs_inspect_get_arch(g, root);
  if (ret == NULL) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
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
 * "debian"
 * Debian.
 * 
 * "fedora"
 * Fedora.
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
 * "opensuse"
 * OpenSUSE.
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
 */
gchar *
guestfs_session_inspect_get_distro(GuestfsSession *session, const gchar *root, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "inspect_get_distro");
    return NULL;
  }

  char *ret = guestfs_inspect_get_distro(g, root);
  if (ret == NULL) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return NULL;
  }

  return ret;
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
 */
gint32
guestfs_session_inspect_get_major_version(GuestfsSession *session, const gchar *root, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "inspect_get_major_version");
    return -1;
  }

  int ret = guestfs_inspect_get_major_version(g, root);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
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
 */
gint32
guestfs_session_inspect_get_minor_version(GuestfsSession *session, const gchar *root, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "inspect_get_minor_version");
    return -1;
  }

  int ret = guestfs_inspect_get_minor_version(g, root);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return -1;
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
 */
gchar *
guestfs_session_inspect_get_product_name(GuestfsSession *session, const gchar *root, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "inspect_get_product_name");
    return NULL;
  }

  char *ret = guestfs_inspect_get_product_name(g, root);
  if (ret == NULL) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return NULL;
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
 * "/etc/fstab". *In particular note* that this may return filesystems
 * which are non-existent or not mountable and callers should be prepared
 * to handle or ignore failures if they try to mount them.
 * 
 * Each element in the returned hashtable has a key which is the path of
 * the mountpoint (eg. "/boot") and a value which is the filesystem that
 * would be mounted there (eg. "/dev/sda1").
 * 
 * Non-mounted devices such as swap devices are *not* returned in this
 * list.
 * 
 * For operating systems like Windows which still use drive letters, this
 * call will only return an entry for the first drive "mounted on" "/". For
 * information about the mapping of drive letters to partitions, see
 * guestfs_session_inspect_get_drive_mappings().
 * 
 * Please read "INSPECTION" in guestfs(3) for more details. See also
 * guestfs_session_inspect_get_filesystems().
 * 
 * Returns: (transfer full) (element-type utf8 utf8): a GHashTable of results, or NULL on error
 */
GHashTable *
guestfs_session_inspect_get_mountpoints(GuestfsSession *session, const gchar *root, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "inspect_get_mountpoints");
    return NULL;
  }

  char **ret = guestfs_inspect_get_mountpoints(g, root);
  if (ret == NULL) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return NULL;
  }

  GHashTable *h = g_hash_table_new_full(g_str_hash, g_str_equal, g_free, g_free);
  char **i = ret;
  while (*i) {
    char *key = *i; i++;
    char *value = *i; i++;
    g_hash_table_insert(h, key, value);
  };
  g_free(ret);
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
 */
gchar **
guestfs_session_inspect_get_filesystems(GuestfsSession *session, const gchar *root, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "inspect_get_filesystems");
    return NULL;
  }

  char **ret = guestfs_inspect_get_filesystems(g, root);
  if (ret == NULL) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return NULL;
  }

  return ret;
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
 */
gboolean
guestfs_session_set_network(GuestfsSession *session, gboolean network, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "set_network");
    return FALSE;
  }

  int ret = guestfs_set_network(g, network);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return FALSE;
  }

  return TRUE;
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
 */
gint8
guestfs_session_get_network(GuestfsSession *session, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "get_network");
    return -1;
  }

  int ret = guestfs_get_network(g);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return -1;
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
 * devices and logical volumes, returning a list of devices containing
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
 */
GHashTable *
guestfs_session_list_filesystems(GuestfsSession *session, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "list_filesystems");
    return NULL;
  }

  char **ret = guestfs_list_filesystems(g);
  if (ret == NULL) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return NULL;
  }

  GHashTable *h = g_hash_table_new_full(g_str_hash, g_str_equal, g_free, g_free);
  char **i = ret;
  while (*i) {
    char *key = *i; i++;
    char *value = *i; i++;
    g_hash_table_insert(h, key, value);
  };
  g_free(ret);
  return h;
}

/**
 * guestfs_session_add_drive_opts:
 * @session: (transfer none): A GuestfsSession object
 * @filename: (transfer none) (type utf8):
 * @optargs: (transfer none) (allow-none): a GuestfsAddDriveOpts containing optional arguments
 * @err: A GError object to receive any generated errors
 *
 * add an image to examine or modify
 *
 * This function adds a virtual machine disk image @filename to libguestfs.
 * The first time you call this function, the disk appears as "/dev/sda",
 * the second time as "/dev/sdb", and so on.
 * 
 * You don't necessarily need to be root when using libguestfs. However you
 * obviously do need sufficient permissions to access the filename for
 * whatever operations you want to perform (ie. read access if you just
 * want to read the image or write access if you want to modify the image).
 * 
 * This call checks that @filename exists.
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
 * <ulink
 * url='https://cve.mitre.org/cgi-bin/cvename.cgi?name=CVE-2010-3851'>
 * CVE-2010-3851 </ulink> and <ulink
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
 * Returns: true on success, false on error
 */
gboolean
guestfs_session_add_drive_opts(GuestfsSession *session, const gchar *filename, GuestfsAddDriveOpts *optargs, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "add_drive_opts");
    return FALSE;
  }

  struct guestfs_add_drive_opts_argv argv;
  struct guestfs_add_drive_opts_argv *argvp = NULL;

  if (optargs) {
    argv.bitmask = 0;

    GValue readonly_v = {0, };
    g_value_init(&readonly_v, GUESTFS_TYPE_TRISTATE);
    g_object_get_property(G_OBJECT(optargs), "readonly", &readonly_v);
    GuestfsTristate readonly = g_value_get_enum(&readonly_v);
    if (readonly != GUESTFS_TRISTATE_NONE) {
      argv.bitmask |= GUESTFS_ADD_DRIVE_OPTS_READONLY_BITMASK;
      argv.readonly = readonly;
    }
    GValue format_v = {0, };
    g_value_init(&format_v, G_TYPE_STRING);
    g_object_get_property(G_OBJECT(optargs), "format", &format_v);
    const gchar *format = g_value_get_string(&format_v);
    if (format != NULL) {
      argv.bitmask |= GUESTFS_ADD_DRIVE_OPTS_FORMAT_BITMASK;
      argv.format = format;
    }
    GValue iface_v = {0, };
    g_value_init(&iface_v, G_TYPE_STRING);
    g_object_get_property(G_OBJECT(optargs), "iface", &iface_v);
    const gchar *iface = g_value_get_string(&iface_v);
    if (iface != NULL) {
      argv.bitmask |= GUESTFS_ADD_DRIVE_OPTS_IFACE_BITMASK;
      argv.iface = iface;
    }
    GValue name_v = {0, };
    g_value_init(&name_v, G_TYPE_STRING);
    g_object_get_property(G_OBJECT(optargs), "name", &name_v);
    const gchar *name = g_value_get_string(&name_v);
    if (name != NULL) {
      argv.bitmask |= GUESTFS_ADD_DRIVE_OPTS_NAME_BITMASK;
      argv.name = name;
    }
    argvp = &argv;
  }
  int ret = guestfs_add_drive_opts_argv(g, filename, argvp);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return FALSE;
  }

  return TRUE;
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
 * systemroot is a directory path such as "/WINDOWS".
 * 
 * This call assumes that the guest is Windows and that the systemroot
 * could be determined by inspection. If this is not the case then an error
 * is returned.
 * 
 * Please read "INSPECTION" in guestfs(3) for more details.
 * 
 * Returns: (transfer full): the returned string, or NULL on error
 */
gchar *
guestfs_session_inspect_get_windows_systemroot(GuestfsSession *session, const gchar *root, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "inspect_get_windows_systemroot");
    return NULL;
  }

  char *ret = guestfs_inspect_get_windows_systemroot(g, root);
  if (ret == NULL) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
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
 */
gchar **
guestfs_session_inspect_get_roots(GuestfsSession *session, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "inspect_get_roots");
    return NULL;
  }

  char **ret = guestfs_inspect_get_roots(g);
  if (ret == NULL) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return NULL;
  }

  return ret;
}

/**
 * guestfs_session_debug_cmdline:
 * @session: (transfer none): A GuestfsSession object
 * @err: A GError object to receive any generated errors
 *
 * debug the QEMU command line (internal use only)
 *
 * This returns the internal QEMU command line. 'debug' commands are not
 * part of the formal API and can be removed or changed at any time.
 * 
 * Returns: (transfer full) (array zero-terminated=1) (element-type utf8): an array of returned strings, or NULL on error
 */
gchar **
guestfs_session_debug_cmdline(GuestfsSession *session, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "debug_cmdline");
    return NULL;
  }

  char **ret = guestfs_debug_cmdline(g);
  if (ret == NULL) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
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
 */
gchar **
guestfs_session_debug_drives(GuestfsSession *session, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "debug_drives");
    return NULL;
  }

  char **ret = guestfs_debug_drives(g);
  if (ret == NULL) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return NULL;
  }

  return ret;
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
 */
gint32
guestfs_session_add_domain(GuestfsSession *session, const gchar *dom, GuestfsAddDomain *optargs, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "add_domain");
    return -1;
  }

  struct guestfs_add_domain_argv argv;
  struct guestfs_add_domain_argv *argvp = NULL;

  if (optargs) {
    argv.bitmask = 0;

    GValue libvirturi_v = {0, };
    g_value_init(&libvirturi_v, G_TYPE_STRING);
    g_object_get_property(G_OBJECT(optargs), "libvirturi", &libvirturi_v);
    const gchar *libvirturi = g_value_get_string(&libvirturi_v);
    if (libvirturi != NULL) {
      argv.bitmask |= GUESTFS_ADD_DOMAIN_LIBVIRTURI_BITMASK;
      argv.libvirturi = libvirturi;
    }
    GValue readonly_v = {0, };
    g_value_init(&readonly_v, GUESTFS_TYPE_TRISTATE);
    g_object_get_property(G_OBJECT(optargs), "readonly", &readonly_v);
    GuestfsTristate readonly = g_value_get_enum(&readonly_v);
    if (readonly != GUESTFS_TRISTATE_NONE) {
      argv.bitmask |= GUESTFS_ADD_DOMAIN_READONLY_BITMASK;
      argv.readonly = readonly;
    }
    GValue iface_v = {0, };
    g_value_init(&iface_v, G_TYPE_STRING);
    g_object_get_property(G_OBJECT(optargs), "iface", &iface_v);
    const gchar *iface = g_value_get_string(&iface_v);
    if (iface != NULL) {
      argv.bitmask |= GUESTFS_ADD_DOMAIN_IFACE_BITMASK;
      argv.iface = iface;
    }
    GValue live_v = {0, };
    g_value_init(&live_v, GUESTFS_TYPE_TRISTATE);
    g_object_get_property(G_OBJECT(optargs), "live", &live_v);
    GuestfsTristate live = g_value_get_enum(&live_v);
    if (live != GUESTFS_TRISTATE_NONE) {
      argv.bitmask |= GUESTFS_ADD_DOMAIN_LIVE_BITMASK;
      argv.live = live;
    }
    GValue allowuuid_v = {0, };
    g_value_init(&allowuuid_v, GUESTFS_TYPE_TRISTATE);
    g_object_get_property(G_OBJECT(optargs), "allowuuid", &allowuuid_v);
    GuestfsTristate allowuuid = g_value_get_enum(&allowuuid_v);
    if (allowuuid != GUESTFS_TRISTATE_NONE) {
      argv.bitmask |= GUESTFS_ADD_DOMAIN_ALLOWUUID_BITMASK;
      argv.allowuuid = allowuuid;
    }
    GValue readonlydisk_v = {0, };
    g_value_init(&readonlydisk_v, G_TYPE_STRING);
    g_object_get_property(G_OBJECT(optargs), "readonlydisk", &readonlydisk_v);
    const gchar *readonlydisk = g_value_get_string(&readonlydisk_v);
    if (readonlydisk != NULL) {
      argv.bitmask |= GUESTFS_ADD_DOMAIN_READONLYDISK_BITMASK;
      argv.readonlydisk = readonlydisk;
    }
    argvp = &argv;
  }
  int ret = guestfs_add_domain_argv(g, dom, argvp);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return -1;
  }

  return ret;
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
 * return @rpm (package format) and @yum (package management).
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
 */
gchar *
guestfs_session_inspect_get_package_format(GuestfsSession *session, const gchar *root, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "inspect_get_package_format");
    return NULL;
  }

  char *ret = guestfs_inspect_get_package_format(g, root);
  if (ret == NULL) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
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
 * @rpm (package format) and @yum (package management).
 * 
 * This returns the string @unknown if we could not determine the package
 * management tool *or* if the operating system does not have a real
 * packaging system (eg. Windows).
 * 
 * Possible strings include: @yum, @up2date, @apt (for all Debian
 * derivatives), @portage, @pisi, @pacman, @urpmi, @zypper. Future versions
 * of libguestfs may return other strings.
 * 
 * Please read "INSPECTION" in guestfs(3) for more details.
 * 
 * Returns: (transfer full): the returned string, or NULL on error
 */
gchar *
guestfs_session_inspect_get_package_management(GuestfsSession *session, const gchar *root, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "inspect_get_package_management");
    return NULL;
  }

  char *ret = guestfs_inspect_get_package_management(g, root);
  if (ret == NULL) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return NULL;
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
 */
GuestfsApplication **
guestfs_session_inspect_list_applications(GuestfsSession *session, const gchar *root, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "inspect_list_applications");
    return NULL;
  }

  struct guestfs_application_list *ret = guestfs_inspect_list_applications(g, root);
  if (ret == NULL) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return NULL;
  }

  GuestfsApplication **l = g_malloc(sizeof(GuestfsApplication*) * (ret->len + 1));
  gsize i;
  for (i = 0; i < ret->len; i++) {
    l[i] = g_slice_new0(GuestfsApplication);
    if (ret->val[i].app_name) l[i]->app_name = g_strdup(ret->val[i].app_name);
    if (ret->val[i].app_display_name) l[i]->app_display_name = g_strdup(ret->val[i].app_display_name);
    l[i]->app_epoch = ret->val[i].app_epoch;
    if (ret->val[i].app_version) l[i]->app_version = g_strdup(ret->val[i].app_version);
    if (ret->val[i].app_release) l[i]->app_release = g_strdup(ret->val[i].app_release);
    if (ret->val[i].app_install_path) l[i]->app_install_path = g_strdup(ret->val[i].app_install_path);
    if (ret->val[i].app_trans_path) l[i]->app_trans_path = g_strdup(ret->val[i].app_trans_path);
    if (ret->val[i].app_publisher) l[i]->app_publisher = g_strdup(ret->val[i].app_publisher);
    if (ret->val[i].app_url) l[i]->app_url = g_strdup(ret->val[i].app_url);
    if (ret->val[i].app_source_package) l[i]->app_source_package = g_strdup(ret->val[i].app_source_package);
    if (ret->val[i].app_summary) l[i]->app_summary = g_strdup(ret->val[i].app_summary);
    if (ret->val[i].app_description) l[i]->app_description = g_strdup(ret->val[i].app_description);
  }
  guestfs_free_application_list(ret);
  l[i] = NULL;
  return l;
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
 */
gchar *
guestfs_session_inspect_get_hostname(GuestfsSession *session, const gchar *root, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "inspect_get_hostname");
    return NULL;
  }

  char *ret = guestfs_inspect_get_hostname(g, root);
  if (ret == NULL) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
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
 */
gchar *
guestfs_session_inspect_get_format(GuestfsSession *session, const gchar *root, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "inspect_get_format");
    return NULL;
  }

  char *ret = guestfs_inspect_get_format(g, root);
  if (ret == NULL) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
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
 */
gint8
guestfs_session_inspect_is_live(GuestfsSession *session, const gchar *root, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "inspect_is_live");
    return -1;
  }

  int ret = guestfs_inspect_is_live(g, root);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
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
 */
gint8
guestfs_session_inspect_is_netinst(GuestfsSession *session, const gchar *root, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "inspect_is_netinst");
    return -1;
  }

  int ret = guestfs_inspect_is_netinst(g, root);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
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
 */
gint8
guestfs_session_inspect_is_multipart(GuestfsSession *session, const gchar *root, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "inspect_is_multipart");
    return -1;
  }

  int ret = guestfs_inspect_is_multipart(g, root);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return -1;
  }

  return ret;
}

/**
 * guestfs_session_set_attach_method:
 * @session: (transfer none): A GuestfsSession object
 * @attachmethod: (transfer none) (type utf8):
 * @err: A GError object to receive any generated errors
 *
 * set the attach method
 *
 * Set the method that libguestfs uses to connect to the back end guestfsd
 * daemon. Possible methods are:
 * 
 * @appliance
 * Launch an appliance and connect to it. This is the ordinary method
 * and the default.
 * 
 * "unix:*path*"
 * Connect to the Unix domain socket *path*.
 * 
 * This method lets you connect to an existing daemon or (using
 * virtio-serial) to a live guest. For more information, see "ATTACHING
 * TO RUNNING DAEMONS" in guestfs(3).
 * 
 * Returns: true on success, false on error
 */
gboolean
guestfs_session_set_attach_method(GuestfsSession *session, const gchar *attachmethod, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "set_attach_method");
    return FALSE;
  }

  int ret = guestfs_set_attach_method(g, attachmethod);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return FALSE;
  }

  return TRUE;
}

/**
 * guestfs_session_get_attach_method:
 * @session: (transfer none): A GuestfsSession object
 * @err: A GError object to receive any generated errors
 *
 * get the attach method
 *
 * Return the current attach method. See
 * guestfs_session_set_attach_method().
 * 
 * Returns: (transfer full): the returned string, or NULL on error
 */
gchar *
guestfs_session_get_attach_method(GuestfsSession *session, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "get_attach_method");
    return NULL;
  }

  char *ret = guestfs_get_attach_method(g);
  if (ret == NULL) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
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
 */
gchar *
guestfs_session_inspect_get_product_variant(GuestfsSession *session, const gchar *root, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "inspect_get_product_variant");
    return NULL;
  }

  char *ret = guestfs_inspect_get_product_variant(g, root);
  if (ret == NULL) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
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
 */
gchar *
guestfs_session_inspect_get_windows_current_control_set(GuestfsSession *session, const gchar *root, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "inspect_get_windows_current_control_set");
    return NULL;
  }

  char *ret = guestfs_inspect_get_windows_current_control_set(g, root);
  if (ret == NULL) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
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
 * assigning drive letters (like "C:") to partitions. This inspection API
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
 */
GHashTable *
guestfs_session_inspect_get_drive_mappings(GuestfsSession *session, const gchar *root, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "inspect_get_drive_mappings");
    return NULL;
  }

  char **ret = guestfs_inspect_get_drive_mappings(g, root);
  if (ret == NULL) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return NULL;
  }

  GHashTable *h = g_hash_table_new_full(g_str_hash, g_str_equal, g_free, g_free);
  char **i = ret;
  while (*i) {
    char *key = *i; i++;
    char *value = *i; i++;
    g_hash_table_insert(h, key, value);
  };
  g_free(ret);
  return h;
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
 * Libguestfs will start by looking for a file called "/etc/favicon.png" or
 * "C:\etc\favicon.png" and if it has the correct format, the contents of
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
 */
guint8 *
guestfs_session_inspect_get_icon(GuestfsSession *session, const gchar *root, GuestfsInspectGetIcon *optargs, gsize *size_r, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "inspect_get_icon");
    return NULL;
  }

  struct guestfs_inspect_get_icon_argv argv;
  struct guestfs_inspect_get_icon_argv *argvp = NULL;

  if (optargs) {
    argv.bitmask = 0;

    GValue favicon_v = {0, };
    g_value_init(&favicon_v, GUESTFS_TYPE_TRISTATE);
    g_object_get_property(G_OBJECT(optargs), "favicon", &favicon_v);
    GuestfsTristate favicon = g_value_get_enum(&favicon_v);
    if (favicon != GUESTFS_TRISTATE_NONE) {
      argv.bitmask |= GUESTFS_INSPECT_GET_ICON_FAVICON_BITMASK;
      argv.favicon = favicon;
    }
    GValue highquality_v = {0, };
    g_value_init(&highquality_v, GUESTFS_TYPE_TRISTATE);
    g_object_get_property(G_OBJECT(optargs), "highquality", &highquality_v);
    GuestfsTristate highquality = g_value_get_enum(&highquality_v);
    if (highquality != GUESTFS_TRISTATE_NONE) {
      argv.bitmask |= GUESTFS_INSPECT_GET_ICON_HIGHQUALITY_BITMASK;
      argv.highquality = highquality;
    }
    argvp = &argv;
  }
  char *ret = guestfs_inspect_get_icon_argv(g, root, size_r, argvp);
  if (ret == NULL) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return NULL;
  }

  return ret;
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
 */
gboolean
guestfs_session_set_pgroup(GuestfsSession *session, gboolean pgroup, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "set_pgroup");
    return FALSE;
  }

  int ret = guestfs_set_pgroup(g, pgroup);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return FALSE;
  }

  return TRUE;
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
 */
gint8
guestfs_session_get_pgroup(GuestfsSession *session, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "get_pgroup");
    return -1;
  }

  int ret = guestfs_get_pgroup(g);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return -1;
  }

  return ret;
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
 */
gboolean
guestfs_session_set_smp(GuestfsSession *session, gint32 smp, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "set_smp");
    return FALSE;
  }

  int ret = guestfs_set_smp(g, smp);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return FALSE;
  }

  return TRUE;
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
 */
gint32
guestfs_session_get_smp(GuestfsSession *session, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "get_smp");
    return -1;
  }

  int ret = guestfs_get_smp(g);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return -1;
  }

  return ret;
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
 */
gboolean
guestfs_session_mount_local(GuestfsSession *session, const gchar *localmountpoint, GuestfsMountLocal *optargs, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "mount_local");
    return FALSE;
  }

  struct guestfs_mount_local_argv argv;
  struct guestfs_mount_local_argv *argvp = NULL;

  if (optargs) {
    argv.bitmask = 0;

    GValue readonly_v = {0, };
    g_value_init(&readonly_v, GUESTFS_TYPE_TRISTATE);
    g_object_get_property(G_OBJECT(optargs), "readonly", &readonly_v);
    GuestfsTristate readonly = g_value_get_enum(&readonly_v);
    if (readonly != GUESTFS_TRISTATE_NONE) {
      argv.bitmask |= GUESTFS_MOUNT_LOCAL_READONLY_BITMASK;
      argv.readonly = readonly;
    }
    GValue options_v = {0, };
    g_value_init(&options_v, G_TYPE_STRING);
    g_object_get_property(G_OBJECT(optargs), "options", &options_v);
    const gchar *options = g_value_get_string(&options_v);
    if (options != NULL) {
      argv.bitmask |= GUESTFS_MOUNT_LOCAL_OPTIONS_BITMASK;
      argv.options = options;
    }
    GValue cachetimeout_v = {0, };
    g_value_init(&cachetimeout_v, G_TYPE_INT);
    g_object_get_property(G_OBJECT(optargs), "cachetimeout", &cachetimeout_v);
    gint32 cachetimeout = g_value_get_int(&cachetimeout_v);
    if (cachetimeout != -1) {
      argv.bitmask |= GUESTFS_MOUNT_LOCAL_CACHETIMEOUT_BITMASK;
      argv.cachetimeout = cachetimeout;
    }
    GValue debugcalls_v = {0, };
    g_value_init(&debugcalls_v, GUESTFS_TYPE_TRISTATE);
    g_object_get_property(G_OBJECT(optargs), "debugcalls", &debugcalls_v);
    GuestfsTristate debugcalls = g_value_get_enum(&debugcalls_v);
    if (debugcalls != GUESTFS_TRISTATE_NONE) {
      argv.bitmask |= GUESTFS_MOUNT_LOCAL_DEBUGCALLS_BITMASK;
      argv.debugcalls = debugcalls;
    }
    argvp = &argv;
  }
  int ret = guestfs_mount_local_argv(g, localmountpoint, argvp);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
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
 * from another thread, with the exception of
 * guestfs_session_umount_local().
 * 
 * You may call this from a different thread than the one which called
 * guestfs_session_mount_local(), subject to the usual rules for threads
 * and libguestfs (see "MULTIPLE HANDLES AND MULTIPLE THREADS" in
 * guestfs(3)).
 * 
 * See "MOUNT LOCAL" in guestfs(3) for full documentation.
 * 
 * Returns: true on success, false on error
 */
gboolean
guestfs_session_mount_local_run(GuestfsSession *session, GCancellable *cancellable, GError **err)
{
  /* Check we haven't already been cancelled */
  if (g_cancellable_set_error_if_cancelled (cancellable, err))
    return FALSE;

  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "mount_local_run");
    return FALSE;
  }

  gulong id = 0;
  if (cancellable) {
    id = g_cancellable_connect(cancellable,
                               G_CALLBACK(cancelled_handler),
                               g, NULL);
  }

  int ret = guestfs_mount_local_run(g);
  g_cancellable_disconnect(cancellable, id);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
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
 */
gboolean
guestfs_session_umount_local(GuestfsSession *session, GuestfsUmountLocal *optargs, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "umount_local");
    return FALSE;
  }

  struct guestfs_umount_local_argv argv;
  struct guestfs_umount_local_argv *argvp = NULL;

  if (optargs) {
    argv.bitmask = 0;

    GValue retry_v = {0, };
    g_value_init(&retry_v, GUESTFS_TYPE_TRISTATE);
    g_object_get_property(G_OBJECT(optargs), "retry", &retry_v);
    GuestfsTristate retry = g_value_get_enum(&retry_v);
    if (retry != GUESTFS_TRISTATE_NONE) {
      argv.bitmask |= GUESTFS_UMOUNT_LOCAL_RETRY_BITMASK;
      argv.retry = retry;
    }
    argvp = &argv;
  }
  int ret = guestfs_umount_local_argv(g, argvp);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return FALSE;
  }

  return TRUE;
}

/**
 * guestfs_session_mount:
 * @session: (transfer none): A GuestfsSession object
 * @device: (transfer none) (type filename):
 * @mountpoint: (transfer none) (type utf8):
 * @err: A GError object to receive any generated errors
 *
 * mount a guest disk at a position in the filesystem
 *
 * Mount a guest disk at a position in the filesystem. Block devices are
 * named "/dev/sda", "/dev/sdb" and so on, as they were added to the guest.
 * If those block devices contain partitions, they will have the usual
 * names (eg. "/dev/sda1"). Also LVM "/dev/VG/LV"-style names can be used.
 * 
 * The rules are the same as for mount(2): A filesystem must first be
 * mounted on "/" before others can be mounted. Other filesystems can only
 * be mounted on directories which already exist.
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
 */
gboolean
guestfs_session_mount(GuestfsSession *session, const gchar *device, const gchar *mountpoint, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "mount");
    return FALSE;
  }

  int ret = guestfs_mount(g, device, mountpoint);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
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
 */
gboolean
guestfs_session_sync(GuestfsSession *session, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "sync");
    return FALSE;
  }

  int ret = guestfs_sync(g);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
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
 */
gboolean
guestfs_session_touch(GuestfsSession *session, const gchar *path, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "touch");
    return FALSE;
  }

  int ret = guestfs_touch(g, path);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return FALSE;
  }

  return TRUE;
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
 * Note that this function cannot correctly handle binary files
 * (specifically, files containing "\0" character which is treated as end
 * of string). For those you need to use the guestfs_session_read_file() or
 * guestfs_session_download() functions which have a more complex
 * interface.
 * 
 * Returns: (transfer full): the returned string, or NULL on error
 */
gchar *
guestfs_session_cat(GuestfsSession *session, const gchar *path, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "cat");
    return NULL;
  }

  char *ret = guestfs_cat(g, path);
  if (ret == NULL) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
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
 * List the files in @directory (relative to the root directory, there is
 * no cwd) in the format of 'ls -la'.
 * 
 * This command is mostly useful for interactive sessions. It is *not*
 * intended that you try to parse the output string.
 * 
 * Returns: (transfer full): the returned string, or NULL on error
 */
gchar *
guestfs_session_ll(GuestfsSession *session, const gchar *directory, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "ll");
    return NULL;
  }

  char *ret = guestfs_ll(g, directory);
  if (ret == NULL) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return NULL;
  }

  return ret;
}

/**
 * guestfs_session_ls:
 * @session: (transfer none): A GuestfsSession object
 * @directory: (transfer none) (type filename):
 * @err: A GError object to receive any generated errors
 *
 * list the files in a directory
 *
 * List the files in @directory (relative to the root directory, there is
 * no cwd). The '.' and '..' entries are not returned, but hidden files are
 * shown.
 * 
 * This command is mostly useful for interactive sessions. Programs should
 * probably use guestfs_session_readdir() instead.
 * 
 * Returns: (transfer full) (array zero-terminated=1) (element-type utf8): an array of returned strings, or NULL on error
 */
gchar **
guestfs_session_ls(GuestfsSession *session, const gchar *directory, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "ls");
    return NULL;
  }

  char **ret = guestfs_ls(g, directory);
  if (ret == NULL) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
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
 * The full block device names are returned, eg. "/dev/sda".
 * 
 * See also guestfs_session_list_filesystems().
 * 
 * Returns: (transfer full) (array zero-terminated=1) (element-type utf8): an array of returned strings, or NULL on error
 */
gchar **
guestfs_session_list_devices(GuestfsSession *session, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "list_devices");
    return NULL;
  }

  char **ret = guestfs_list_devices(g);
  if (ret == NULL) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
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
 * The full partition device names are returned, eg. "/dev/sda1"
 * 
 * This does not return logical volumes. For that you will need to call
 * guestfs_session_lvs().
 * 
 * See also guestfs_session_list_filesystems().
 * 
 * Returns: (transfer full) (array zero-terminated=1) (element-type utf8): an array of returned strings, or NULL on error
 */
gchar **
guestfs_session_list_partitions(GuestfsSession *session, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "list_partitions");
    return NULL;
  }

  char **ret = guestfs_list_partitions(g);
  if (ret == NULL) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return NULL;
  }

  return ret;
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
 * "/dev/sda2").
 * 
 * See also guestfs_session_pvs_full().
 * 
 * Returns: (transfer full) (array zero-terminated=1) (element-type utf8): an array of returned strings, or NULL on error
 */
gchar **
guestfs_session_pvs(GuestfsSession *session, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "pvs");
    return NULL;
  }

  char **ret = guestfs_pvs(g);
  if (ret == NULL) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return NULL;
  }

  return ret;
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
 */
gchar **
guestfs_session_vgs(GuestfsSession *session, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "vgs");
    return NULL;
  }

  char **ret = guestfs_vgs(g);
  if (ret == NULL) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return NULL;
  }

  return ret;
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
 * "/dev/VolGroup00/LogVol00").
 * 
 * See also guestfs_session_lvs_full(), guestfs_session_list_filesystems().
 * 
 * Returns: (transfer full) (array zero-terminated=1) (element-type utf8): an array of returned strings, or NULL on error
 */
gchar **
guestfs_session_lvs(GuestfsSession *session, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "lvs");
    return NULL;
  }

  char **ret = guestfs_lvs(g);
  if (ret == NULL) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
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
 */
GuestfsPV **
guestfs_session_pvs_full(GuestfsSession *session, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "pvs_full");
    return NULL;
  }

  struct guestfs_lvm_pv_list *ret = guestfs_pvs_full(g);
  if (ret == NULL) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return NULL;
  }

  GuestfsPV **l = g_malloc(sizeof(GuestfsPV*) * (ret->len + 1));
  gsize i;
  for (i = 0; i < ret->len; i++) {
    l[i] = g_slice_new0(GuestfsPV);
    if (ret->val[i].pv_name) l[i]->pv_name = g_strdup(ret->val[i].pv_name);
    if (ret->val[i].pv_uuid) memcpy(l[i]->pv_uuid, ret->val[i].pv_uuid, sizeof(l[i]->pv_uuid));
    if (ret->val[i].pv_fmt) l[i]->pv_fmt = g_strdup(ret->val[i].pv_fmt);
    l[i]->pv_size = ret->val[i].pv_size;
    l[i]->dev_size = ret->val[i].dev_size;
    l[i]->pv_free = ret->val[i].pv_free;
    l[i]->pv_used = ret->val[i].pv_used;
    if (ret->val[i].pv_attr) l[i]->pv_attr = g_strdup(ret->val[i].pv_attr);
    l[i]->pv_pe_count = ret->val[i].pv_pe_count;
    l[i]->pv_pe_alloc_count = ret->val[i].pv_pe_alloc_count;
    if (ret->val[i].pv_tags) l[i]->pv_tags = g_strdup(ret->val[i].pv_tags);
    l[i]->pe_start = ret->val[i].pe_start;
    l[i]->pv_mda_count = ret->val[i].pv_mda_count;
    l[i]->pv_mda_free = ret->val[i].pv_mda_free;
  }
  guestfs_free_lvm_pv_list(ret);
  l[i] = NULL;
  return l;
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
 */
GuestfsVG **
guestfs_session_vgs_full(GuestfsSession *session, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "vgs_full");
    return NULL;
  }

  struct guestfs_lvm_vg_list *ret = guestfs_vgs_full(g);
  if (ret == NULL) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return NULL;
  }

  GuestfsVG **l = g_malloc(sizeof(GuestfsVG*) * (ret->len + 1));
  gsize i;
  for (i = 0; i < ret->len; i++) {
    l[i] = g_slice_new0(GuestfsVG);
    if (ret->val[i].vg_name) l[i]->vg_name = g_strdup(ret->val[i].vg_name);
    if (ret->val[i].vg_uuid) memcpy(l[i]->vg_uuid, ret->val[i].vg_uuid, sizeof(l[i]->vg_uuid));
    if (ret->val[i].vg_fmt) l[i]->vg_fmt = g_strdup(ret->val[i].vg_fmt);
    if (ret->val[i].vg_attr) l[i]->vg_attr = g_strdup(ret->val[i].vg_attr);
    l[i]->vg_size = ret->val[i].vg_size;
    l[i]->vg_free = ret->val[i].vg_free;
    if (ret->val[i].vg_sysid) l[i]->vg_sysid = g_strdup(ret->val[i].vg_sysid);
    l[i]->vg_extent_size = ret->val[i].vg_extent_size;
    l[i]->vg_extent_count = ret->val[i].vg_extent_count;
    l[i]->vg_free_count = ret->val[i].vg_free_count;
    l[i]->max_lv = ret->val[i].max_lv;
    l[i]->max_pv = ret->val[i].max_pv;
    l[i]->pv_count = ret->val[i].pv_count;
    l[i]->lv_count = ret->val[i].lv_count;
    l[i]->snap_count = ret->val[i].snap_count;
    l[i]->vg_seqno = ret->val[i].vg_seqno;
    if (ret->val[i].vg_tags) l[i]->vg_tags = g_strdup(ret->val[i].vg_tags);
    l[i]->vg_mda_count = ret->val[i].vg_mda_count;
    l[i]->vg_mda_free = ret->val[i].vg_mda_free;
  }
  guestfs_free_lvm_vg_list(ret);
  l[i] = NULL;
  return l;
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
 */
GuestfsLV **
guestfs_session_lvs_full(GuestfsSession *session, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "lvs_full");
    return NULL;
  }

  struct guestfs_lvm_lv_list *ret = guestfs_lvs_full(g);
  if (ret == NULL) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return NULL;
  }

  GuestfsLV **l = g_malloc(sizeof(GuestfsLV*) * (ret->len + 1));
  gsize i;
  for (i = 0; i < ret->len; i++) {
    l[i] = g_slice_new0(GuestfsLV);
    if (ret->val[i].lv_name) l[i]->lv_name = g_strdup(ret->val[i].lv_name);
    if (ret->val[i].lv_uuid) memcpy(l[i]->lv_uuid, ret->val[i].lv_uuid, sizeof(l[i]->lv_uuid));
    if (ret->val[i].lv_attr) l[i]->lv_attr = g_strdup(ret->val[i].lv_attr);
    l[i]->lv_major = ret->val[i].lv_major;
    l[i]->lv_minor = ret->val[i].lv_minor;
    l[i]->lv_kernel_major = ret->val[i].lv_kernel_major;
    l[i]->lv_kernel_minor = ret->val[i].lv_kernel_minor;
    l[i]->lv_size = ret->val[i].lv_size;
    l[i]->seg_count = ret->val[i].seg_count;
    if (ret->val[i].origin) l[i]->origin = g_strdup(ret->val[i].origin);
    l[i]->snap_percent = ret->val[i].snap_percent;
    l[i]->copy_percent = ret->val[i].copy_percent;
    if (ret->val[i].move_pv) l[i]->move_pv = g_strdup(ret->val[i].move_pv);
    if (ret->val[i].lv_tags) l[i]->lv_tags = g_strdup(ret->val[i].lv_tags);
    if (ret->val[i].mirror_log) l[i]->mirror_log = g_strdup(ret->val[i].mirror_log);
    if (ret->val[i].modules) l[i]->modules = g_strdup(ret->val[i].modules);
  }
  guestfs_free_lvm_lv_list(ret);
  l[i] = NULL;
  return l;
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
 * of line). For those you need to use the guestfs_session_read_file()
 * function which has a more complex interface.
 * 
 * Returns: (transfer full) (array zero-terminated=1) (element-type utf8): an array of returned strings, or NULL on error
 */
gchar **
guestfs_session_read_lines(GuestfsSession *session, const gchar *path, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "read_lines");
    return NULL;
  }

  char **ret = guestfs_read_lines(g, path);
  if (ret == NULL) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
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
 * @root is the filesystem root. @root must not be NULL, use "/" instead.
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
 */
gboolean
guestfs_session_aug_init(GuestfsSession *session, const gchar *root, gint32 flags, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "aug_init");
    return FALSE;
  }

  int ret = guestfs_aug_init(g, root, flags);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
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
 */
gboolean
guestfs_session_aug_close(GuestfsSession *session, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "aug_close");
    return FALSE;
  }

  int ret = guestfs_aug_close(g);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return FALSE;
  }

  return TRUE;
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
 */
gint32
guestfs_session_aug_defvar(GuestfsSession *session, const gchar *name, const gchar *expr, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "aug_defvar");
    return -1;
  }

  int ret = guestfs_aug_defvar(g, name, expr);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return -1;
  }

  return ret;
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
 */
GuestfsIntBool *
guestfs_session_aug_defnode(GuestfsSession *session, const gchar *name, const gchar *expr, const gchar *val, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "aug_defnode");
    return NULL;
  }

  struct guestfs_int_bool *ret = guestfs_aug_defnode(g, name, expr, val);
  if (ret == NULL) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return NULL;
  }

  GuestfsIntBool *s = g_slice_new0(GuestfsIntBool);
  s->i = ret->i;
  s->b = ret->b;
  guestfs_free_int_bool(ret);
  return s;
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
 */
gchar *
guestfs_session_aug_get(GuestfsSession *session, const gchar *augpath, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "aug_get");
    return NULL;
  }

  char *ret = guestfs_aug_get(g, augpath);
  if (ret == NULL) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return NULL;
  }

  return ret;
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
 */
gboolean
guestfs_session_aug_set(GuestfsSession *session, const gchar *augpath, const gchar *val, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "aug_set");
    return FALSE;
  }

  int ret = guestfs_aug_set(g, augpath, val);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
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
 * be a label, ie. not contain "/", "*" or end with a bracketed index
 * "[N]".
 * 
 * Returns: true on success, false on error
 */
gboolean
guestfs_session_aug_insert(GuestfsSession *session, const gchar *augpath, const gchar *label, gboolean before, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "aug_insert");
    return FALSE;
  }

  int ret = guestfs_aug_insert(g, augpath, label, before);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
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
 */
gint32
guestfs_session_aug_rm(GuestfsSession *session, const gchar *augpath, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "aug_rm");
    return -1;
  }

  int ret = guestfs_aug_rm(g, augpath);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return -1;
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
 */
gboolean
guestfs_session_aug_mv(GuestfsSession *session, const gchar *src, const gchar *dest, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "aug_mv");
    return FALSE;
  }

  int ret = guestfs_aug_mv(g, src, dest);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return FALSE;
  }

  return TRUE;
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
 */
gchar **
guestfs_session_aug_match(GuestfsSession *session, const gchar *augpath, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "aug_match");
    return NULL;
  }

  char **ret = guestfs_aug_match(g, augpath);
  if (ret == NULL) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return NULL;
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
 */
gboolean
guestfs_session_aug_save(GuestfsSession *session, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "aug_save");
    return FALSE;
  }

  int ret = guestfs_aug_save(g);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return FALSE;
  }

  return TRUE;
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
 */
gboolean
guestfs_session_aug_load(GuestfsSession *session, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "aug_load");
    return FALSE;
  }

  int ret = guestfs_aug_load(g);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
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
 */
gchar **
guestfs_session_aug_ls(GuestfsSession *session, const gchar *augpath, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "aug_ls");
    return NULL;
  }

  char **ret = guestfs_aug_ls(g, augpath);
  if (ret == NULL) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return NULL;
  }

  return ret;
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
 */
gboolean
guestfs_session_rm(GuestfsSession *session, const gchar *path, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "rm");
    return FALSE;
  }

  int ret = guestfs_rm(g, path);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
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
 */
gboolean
guestfs_session_rmdir(GuestfsSession *session, const gchar *path, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "rmdir");
    return FALSE;
  }

  int ret = guestfs_rmdir(g, path);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
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
 */
gboolean
guestfs_session_rm_rf(GuestfsSession *session, const gchar *path, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "rm_rf");
    return FALSE;
  }

  int ret = guestfs_rm_rf(g, path);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
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
 */
gboolean
guestfs_session_mkdir(GuestfsSession *session, const gchar *path, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "mkdir");
    return FALSE;
  }

  int ret = guestfs_mkdir(g, path);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
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
 */
gboolean
guestfs_session_mkdir_p(GuestfsSession *session, const gchar *path, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "mkdir_p");
    return FALSE;
  }

  int ret = guestfs_mkdir_p(g, path);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
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
 */
gboolean
guestfs_session_chmod(GuestfsSession *session, gint32 mode, const gchar *path, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "chmod");
    return FALSE;
  }

  int ret = guestfs_chmod(g, mode, path);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
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
 */
gboolean
guestfs_session_chown(GuestfsSession *session, gint32 owner, gint32 group, const gchar *path, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "chown");
    return FALSE;
  }

  int ret = guestfs_chown(g, owner, group, path);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return FALSE;
  }

  return TRUE;
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
 */
gint8
guestfs_session_exists(GuestfsSession *session, const gchar *path, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "exists");
    return -1;
  }

  int ret = guestfs_exists(g, path);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return -1;
  }

  return ret;
}

/**
 * guestfs_session_is_file:
 * @session: (transfer none): A GuestfsSession object
 * @path: (transfer none) (type filename):
 * @err: A GError object to receive any generated errors
 *
 * test if a regular file
 *
 * This returns @true if and only if there is a regular file with the given
 * @path name. Note that it returns false for other objects like
 * directories.
 * 
 * See also guestfs_session_stat().
 * 
 * Returns: the returned value, or -1 on error
 */
gint8
guestfs_session_is_file(GuestfsSession *session, const gchar *path, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "is_file");
    return -1;
  }

  int ret = guestfs_is_file(g, path);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return -1;
  }

  return ret;
}

/**
 * guestfs_session_is_dir:
 * @session: (transfer none): A GuestfsSession object
 * @path: (transfer none) (type filename):
 * @err: A GError object to receive any generated errors
 *
 * test if a directory
 *
 * This returns @true if and only if there is a directory with the given
 * @path name. Note that it returns false for other objects like files.
 * 
 * See also guestfs_session_stat().
 * 
 * Returns: the returned value, or -1 on error
 */
gint8
guestfs_session_is_dir(GuestfsSession *session, const gchar *path, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "is_dir");
    return -1;
  }

  int ret = guestfs_is_dir(g, path);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return -1;
  }

  return ret;
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
 * should usually be a partition name such as "/dev/sda1".
 * 
 * Returns: true on success, false on error
 */
gboolean
guestfs_session_pvcreate(GuestfsSession *session, const gchar *device, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "pvcreate");
    return FALSE;
  }

  int ret = guestfs_pvcreate(g, device);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
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
 */
gboolean
guestfs_session_vgcreate(GuestfsSession *session, const gchar *volgroup, gchar *const *physvols, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "vgcreate");
    return FALSE;
  }

  int ret = guestfs_vgcreate(g, volgroup, physvols);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
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
 */
gboolean
guestfs_session_lvcreate(GuestfsSession *session, const gchar *logvol, const gchar *volgroup, gint32 mbytes, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "lvcreate");
    return FALSE;
  }

  int ret = guestfs_lvcreate(g, logvol, volgroup, mbytes);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return FALSE;
  }

  return TRUE;
}

/**
 * guestfs_session_mkfs:
 * @session: (transfer none): A GuestfsSession object
 * @fstype: (transfer none) (type utf8):
 * @device: (transfer none) (type filename):
 * @err: A GError object to receive any generated errors
 *
 * make a filesystem
 *
 * This creates a filesystem on @device (usually a partition or LVM logical
 * volume). The filesystem type is @fstype, for example @ext3.
 * 
 * Returns: true on success, false on error
 */
gboolean
guestfs_session_mkfs(GuestfsSession *session, const gchar *fstype, const gchar *device, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "mkfs");
    return FALSE;
  }

  int ret = guestfs_mkfs(g, fstype, device);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
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
 * @device should be a block device, for example "/dev/sda".
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
 */
gboolean
guestfs_session_sfdisk(GuestfsSession *session, const gchar *device, gint32 cyls, gint32 heads, gint32 sectors, gchar *const *lines, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "sfdisk");
    return FALSE;
  }

  int ret = guestfs_sfdisk(g, device, cyls, heads, sectors, lines);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
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
 */
gboolean
guestfs_session_write_file(GuestfsSession *session, const gchar *path, const gchar *content, gint32 size, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "write_file");
    return FALSE;
  }

  int ret = guestfs_write_file(g, path, content, size);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return FALSE;
  }

  return TRUE;
}

/**
 * guestfs_session_umount:
 * @session: (transfer none): A GuestfsSession object
 * @pathordevice: (transfer none) (type utf8):
 * @err: A GError object to receive any generated errors
 *
 * unmount a filesystem
 *
 * This unmounts the given filesystem. The filesystem may be specified
 * either by its mountpoint (path) or the device which contains the
 * filesystem.
 * 
 * Returns: true on success, false on error
 */
gboolean
guestfs_session_umount(GuestfsSession *session, const gchar *pathordevice, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "umount");
    return FALSE;
  }

  int ret = guestfs_umount(g, pathordevice);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return FALSE;
  }

  return TRUE;
}

/**
 * guestfs_session_mounts:
 * @session: (transfer none): A GuestfsSession object
 * @err: A GError object to receive any generated errors
 *
 * show mounted filesystems
 *
 * This returns the list of currently mounted filesystems. It returns the
 * list of devices (eg. "/dev/sda1", "/dev/VG/LV").
 * 
 * Some internal mounts are not shown.
 * 
 * See also: guestfs_session_mountpoints()
 * 
 * Returns: (transfer full) (array zero-terminated=1) (element-type utf8): an array of returned strings, or NULL on error
 */
gchar **
guestfs_session_mounts(GuestfsSession *session, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "mounts");
    return NULL;
  }

  char **ret = guestfs_mounts(g);
  if (ret == NULL) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return NULL;
  }

  return ret;
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
 */
gboolean
guestfs_session_umount_all(GuestfsSession *session, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "umount_all");
    return FALSE;
  }

  int ret = guestfs_umount_all(g);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
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
 */
gboolean
guestfs_session_lvm_remove_all(GuestfsSession *session, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "lvm_remove_all");
    return FALSE;
  }

  int ret = guestfs_lvm_remove_all(g);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return FALSE;
  }

  return TRUE;
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
 */
gchar *
guestfs_session_file(GuestfsSession *session, const gchar *path, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "file");
    return NULL;
  }

  char *ret = guestfs_file(g, path);
  if (ret == NULL) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return NULL;
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
 * The $PATH environment variable will contain at least "/usr/bin" and
 * "/bin". If you require a program from another location, you should
 * provide the full path in the first parameter.
 * 
 * Shared libraries and data files required by the program must be
 * available on filesystems which are mounted in the correct places. It is
 * the caller's responsibility to ensure all filesystems that are needed
 * are mounted at the right locations.
 * 
 * Returns: (transfer full): the returned string, or NULL on error
 */
gchar *
guestfs_session_command(GuestfsSession *session, gchar *const *arguments, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "command");
    return NULL;
  }

  char *ret = guestfs_command(g, arguments);
  if (ret == NULL) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
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
 */
gchar **
guestfs_session_command_lines(GuestfsSession *session, gchar *const *arguments, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "command_lines");
    return NULL;
  }

  char **ret = guestfs_command_lines(g, arguments);
  if (ret == NULL) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return NULL;
  }

  return ret;
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
 */
GuestfsStat *
guestfs_session_stat(GuestfsSession *session, const gchar *path, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "stat");
    return NULL;
  }

  struct guestfs_stat *ret = guestfs_stat(g, path);
  if (ret == NULL) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return NULL;
  }

  GuestfsStat *s = g_slice_new0(GuestfsStat);
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
  guestfs_free_stat(ret);
  return s;
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
 */
GuestfsStat *
guestfs_session_lstat(GuestfsSession *session, const gchar *path, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "lstat");
    return NULL;
  }

  struct guestfs_stat *ret = guestfs_lstat(g, path);
  if (ret == NULL) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return NULL;
  }

  GuestfsStat *s = g_slice_new0(GuestfsStat);
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
  guestfs_free_stat(ret);
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
 */
GuestfsStatVFS *
guestfs_session_statvfs(GuestfsSession *session, const gchar *path, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "statvfs");
    return NULL;
  }

  struct guestfs_statvfs *ret = guestfs_statvfs(g, path);
  if (ret == NULL) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return NULL;
  }

  GuestfsStatVFS *s = g_slice_new0(GuestfsStatVFS);
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
  guestfs_free_statvfs(ret);
  return s;
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
 */
GHashTable *
guestfs_session_tune2fs_l(GuestfsSession *session, const gchar *device, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "tune2fs_l");
    return NULL;
  }

  char **ret = guestfs_tune2fs_l(g, device);
  if (ret == NULL) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return NULL;
  }

  GHashTable *h = g_hash_table_new_full(g_str_hash, g_str_equal, g_free, g_free);
  char **i = ret;
  while (*i) {
    char *key = *i; i++;
    char *value = *i; i++;
    g_hash_table_insert(h, key, value);
  };
  g_free(ret);
  return h;
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
 */
gboolean
guestfs_session_blockdev_setro(GuestfsSession *session, const gchar *device, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "blockdev_setro");
    return FALSE;
  }

  int ret = guestfs_blockdev_setro(g, device);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
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
 */
gboolean
guestfs_session_blockdev_setrw(GuestfsSession *session, const gchar *device, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "blockdev_setrw");
    return FALSE;
  }

  int ret = guestfs_blockdev_setrw(g, device);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return FALSE;
  }

  return TRUE;
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
 */
gint8
guestfs_session_blockdev_getro(GuestfsSession *session, const gchar *device, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "blockdev_getro");
    return -1;
  }

  int ret = guestfs_blockdev_getro(g, device);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
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
 */
gint32
guestfs_session_blockdev_getss(GuestfsSession *session, const gchar *device, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "blockdev_getss");
    return -1;
  }

  int ret = guestfs_blockdev_getss(g, device);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return -1;
  }

  return ret;
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
 * (Note this is different from both *size in blocks* and *filesystem block
 * size*).
 * 
 * This uses the blockdev(8) command.
 * 
 * Returns: the returned value, or -1 on error
 */
gint32
guestfs_session_blockdev_getbsz(GuestfsSession *session, const gchar *device, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "blockdev_getbsz");
    return -1;
  }

  int ret = guestfs_blockdev_getbsz(g, device);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return -1;
  }

  return ret;
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
 * This sets the block size of a device.
 * 
 * (Note this is different from both *size in blocks* and *filesystem block
 * size*).
 * 
 * This uses the blockdev(8) command.
 * 
 * Returns: true on success, false on error
 */
gboolean
guestfs_session_blockdev_setbsz(GuestfsSession *session, const gchar *device, gint32 blocksize, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "blockdev_setbsz");
    return FALSE;
  }

  int ret = guestfs_blockdev_setbsz(g, device, blocksize);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return FALSE;
  }

  return TRUE;
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
 */
gint64
guestfs_session_blockdev_getsz(GuestfsSession *session, const gchar *device, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "blockdev_getsz");
    return -1;
  }

  int64_t ret = guestfs_blockdev_getsz(g, device);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
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
 */
gint64
guestfs_session_blockdev_getsize64(GuestfsSession *session, const gchar *device, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "blockdev_getsize64");
    return -1;
  }

  int64_t ret = guestfs_blockdev_getsize64(g, device);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return -1;
  }

  return ret;
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
 */
gboolean
guestfs_session_blockdev_flushbufs(GuestfsSession *session, const gchar *device, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "blockdev_flushbufs");
    return FALSE;
  }

  int ret = guestfs_blockdev_flushbufs(g, device);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return FALSE;
  }

  return TRUE;
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
 */
gboolean
guestfs_session_blockdev_rereadpt(GuestfsSession *session, const gchar *device, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "blockdev_rereadpt");
    return FALSE;
  }

  int ret = guestfs_blockdev_rereadpt(g, device);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
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
 * Upload local file @filename to @remotefilename on the filesystem.
 * 
 * @filename can also be a named pipe.
 * 
 * See also guestfs_session_download().
 * 
 * Returns: true on success, false on error
 */
gboolean
guestfs_session_upload(GuestfsSession *session, const gchar *filename, const gchar *remotefilename, GCancellable *cancellable, GError **err)
{
  /* Check we haven't already been cancelled */
  if (g_cancellable_set_error_if_cancelled (cancellable, err))
    return FALSE;

  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "upload");
    return FALSE;
  }

  gulong id = 0;
  if (cancellable) {
    id = g_cancellable_connect(cancellable,
                               G_CALLBACK(cancelled_handler),
                               g, NULL);
  }

  int ret = guestfs_upload(g, filename, remotefilename);
  g_cancellable_disconnect(cancellable, id);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return FALSE;
  }

  return TRUE;
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
 * Download file @remotefilename and save it as @filename on the local
 * machine.
 * 
 * @filename can also be a named pipe.
 * 
 * See also guestfs_session_upload(), guestfs_session_cat().
 * 
 * Returns: true on success, false on error
 */
gboolean
guestfs_session_download(GuestfsSession *session, const gchar *remotefilename, const gchar *filename, GCancellable *cancellable, GError **err)
{
  /* Check we haven't already been cancelled */
  if (g_cancellable_set_error_if_cancelled (cancellable, err))
    return FALSE;

  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "download");
    return FALSE;
  }

  gulong id = 0;
  if (cancellable) {
    id = g_cancellable_connect(cancellable,
                               G_CALLBACK(cancelled_handler),
                               g, NULL);
  }

  int ret = guestfs_download(g, remotefilename, filename);
  g_cancellable_disconnect(cancellable, id);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return FALSE;
  }

  return TRUE;
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
 */
gchar *
guestfs_session_checksum(GuestfsSession *session, const gchar *csumtype, const gchar *path, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "checksum");
    return NULL;
  }

  char *ret = guestfs_checksum(g, csumtype, path);
  if (ret == NULL) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return NULL;
  }

  return ret;
}

/**
 * guestfs_session_tar_in:
 * @session: (transfer none): A GuestfsSession object
 * @tarfile: (transfer none) (type filename):
 * @directory: (transfer none) (type filename):
 * @cancellable: A GCancellable object
 * @err: A GError object to receive any generated errors
 *
 * unpack tarfile to directory
 *
 * This command uploads and unpacks local file @tarfile (an *uncompressed*
 * tar file) into @directory.
 * 
 * To upload a compressed tarball, use guestfs_session_tgz_in() or
 * guestfs_session_txz_in().
 * 
 * Returns: true on success, false on error
 */
gboolean
guestfs_session_tar_in(GuestfsSession *session, const gchar *tarfile, const gchar *directory, GCancellable *cancellable, GError **err)
{
  /* Check we haven't already been cancelled */
  if (g_cancellable_set_error_if_cancelled (cancellable, err))
    return FALSE;

  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "tar_in");
    return FALSE;
  }

  gulong id = 0;
  if (cancellable) {
    id = g_cancellable_connect(cancellable,
                               G_CALLBACK(cancelled_handler),
                               g, NULL);
  }

  int ret = guestfs_tar_in(g, tarfile, directory);
  g_cancellable_disconnect(cancellable, id);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return FALSE;
  }

  return TRUE;
}

/**
 * guestfs_session_tar_out:
 * @session: (transfer none): A GuestfsSession object
 * @directory: (transfer none) (type utf8):
 * @tarfile: (transfer none) (type filename):
 * @cancellable: A GCancellable object
 * @err: A GError object to receive any generated errors
 *
 * pack directory into tarfile
 *
 * This command packs the contents of @directory and downloads it to local
 * file @tarfile.
 * 
 * To download a compressed tarball, use guestfs_session_tgz_out() or
 * guestfs_session_txz_out().
 * 
 * Returns: true on success, false on error
 */
gboolean
guestfs_session_tar_out(GuestfsSession *session, const gchar *directory, const gchar *tarfile, GCancellable *cancellable, GError **err)
{
  /* Check we haven't already been cancelled */
  if (g_cancellable_set_error_if_cancelled (cancellable, err))
    return FALSE;

  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "tar_out");
    return FALSE;
  }

  gulong id = 0;
  if (cancellable) {
    id = g_cancellable_connect(cancellable,
                               G_CALLBACK(cancelled_handler),
                               g, NULL);
  }

  int ret = guestfs_tar_out(g, directory, tarfile);
  g_cancellable_disconnect(cancellable, id);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
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
 * compressed* tar file) into @directory.
 * 
 * To upload an uncompressed tarball, use guestfs_session_tar_in().
 * 
 * Returns: true on success, false on error
 */
gboolean
guestfs_session_tgz_in(GuestfsSession *session, const gchar *tarball, const gchar *directory, GCancellable *cancellable, GError **err)
{
  /* Check we haven't already been cancelled */
  if (g_cancellable_set_error_if_cancelled (cancellable, err))
    return FALSE;

  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "tgz_in");
    return FALSE;
  }

  gulong id = 0;
  if (cancellable) {
    id = g_cancellable_connect(cancellable,
                               G_CALLBACK(cancelled_handler),
                               g, NULL);
  }

  int ret = guestfs_tgz_in(g, tarball, directory);
  g_cancellable_disconnect(cancellable, id);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
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
 * This command packs the contents of @directory and downloads it to local
 * file @tarball.
 * 
 * To download an uncompressed tarball, use guestfs_session_tar_out().
 * 
 * Returns: true on success, false on error
 */
gboolean
guestfs_session_tgz_out(GuestfsSession *session, const gchar *directory, const gchar *tarball, GCancellable *cancellable, GError **err)
{
  /* Check we haven't already been cancelled */
  if (g_cancellable_set_error_if_cancelled (cancellable, err))
    return FALSE;

  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "tgz_out");
    return FALSE;
  }

  gulong id = 0;
  if (cancellable) {
    id = g_cancellable_connect(cancellable,
                               G_CALLBACK(cancelled_handler),
                               g, NULL);
  }

  int ret = guestfs_tgz_out(g, directory, tarball);
  g_cancellable_disconnect(cancellable, id);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return FALSE;
  }

  return TRUE;
}

/**
 * guestfs_session_mount_ro:
 * @session: (transfer none): A GuestfsSession object
 * @device: (transfer none) (type filename):
 * @mountpoint: (transfer none) (type utf8):
 * @err: A GError object to receive any generated errors
 *
 * mount a guest disk, read-only
 *
 * This is the same as the guestfs_session_mount() command, but it mounts
 * the filesystem with the read-only (*-o ro*) flag.
 * 
 * Returns: true on success, false on error
 */
gboolean
guestfs_session_mount_ro(GuestfsSession *session, const gchar *device, const gchar *mountpoint, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "mount_ro");
    return FALSE;
  }

  int ret = guestfs_mount_ro(g, device, mountpoint);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return FALSE;
  }

  return TRUE;
}

/**
 * guestfs_session_mount_options:
 * @session: (transfer none): A GuestfsSession object
 * @options: (transfer none) (type utf8):
 * @device: (transfer none) (type filename):
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
 */
gboolean
guestfs_session_mount_options(GuestfsSession *session, const gchar *options, const gchar *device, const gchar *mountpoint, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "mount_options");
    return FALSE;
  }

  int ret = guestfs_mount_options(g, options, device, mountpoint);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return FALSE;
  }

  return TRUE;
}

/**
 * guestfs_session_mount_vfs:
 * @session: (transfer none): A GuestfsSession object
 * @options: (transfer none) (type utf8):
 * @vfstype: (transfer none) (type utf8):
 * @device: (transfer none) (type filename):
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
 */
gboolean
guestfs_session_mount_vfs(GuestfsSession *session, const gchar *options, const gchar *vfstype, const gchar *device, const gchar *mountpoint, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "mount_vfs");
    return FALSE;
  }

  int ret = guestfs_mount_vfs(g, options, vfstype, device, mountpoint);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
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
 * (the guestfs daemon) that runs inside the qemu subprocess.
 * 
 * There is no comprehensive help for this command. You have to look at the
 * file "daemon/debug.c" in the libguestfs source to find out what you can
 * do.
 * 
 * Returns: (transfer full): the returned string, or NULL on error
 */
gchar *
guestfs_session_debug(GuestfsSession *session, const gchar *subcmd, gchar *const *extraargs, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "debug");
    return NULL;
  }

  char *ret = guestfs_debug(g, subcmd, extraargs);
  if (ret == NULL) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return NULL;
  }

  return ret;
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
 * LV, such as "/dev/VG/LV".
 * 
 * You can also remove all LVs in a volume group by specifying the VG name,
 * "/dev/VG".
 * 
 * Returns: true on success, false on error
 */
gboolean
guestfs_session_lvremove(GuestfsSession *session, const gchar *device, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "lvremove");
    return FALSE;
  }

  int ret = guestfs_lvremove(g, device);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return FALSE;
  }

  return TRUE;
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
 */
gboolean
guestfs_session_vgremove(GuestfsSession *session, const gchar *vgname, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "vgremove");
    return FALSE;
  }

  int ret = guestfs_vgremove(g, vgname);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
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
 */
gboolean
guestfs_session_pvremove(GuestfsSession *session, const gchar *device, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "pvremove");
    return FALSE;
  }

  int ret = guestfs_pvremove(g, device);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
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
 */
gboolean
guestfs_session_set_e2label(GuestfsSession *session, const gchar *device, const gchar *label, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "set_e2label");
    return FALSE;
  }

  int ret = guestfs_set_e2label(g, device, label);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return FALSE;
  }

  return TRUE;
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
 */
gchar *
guestfs_session_get_e2label(GuestfsSession *session, const gchar *device, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "get_e2label");
    return NULL;
  }

  char *ret = guestfs_get_e2label(g, device);
  if (ret == NULL) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return NULL;
  }

  return ret;
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
 * You can use either guestfs_session_tune2fs_l() or
 * guestfs_session_get_e2uuid() to return the existing UUID of a
 * filesystem.
 * 
 * Returns: true on success, false on error
 */
gboolean
guestfs_session_set_e2uuid(GuestfsSession *session, const gchar *device, const gchar *uuid, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "set_e2uuid");
    return FALSE;
  }

  int ret = guestfs_set_e2uuid(g, device, uuid);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return FALSE;
  }

  return TRUE;
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
 */
gchar *
guestfs_session_get_e2uuid(GuestfsSession *session, const gchar *device, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "get_e2uuid");
    return NULL;
  }

  char *ret = guestfs_get_e2uuid(g, device);
  if (ret == NULL) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
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
 */
gint32
guestfs_session_fsck(GuestfsSession *session, const gchar *fstype, const gchar *device, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "fsck");
    return -1;
  }

  int ret = guestfs_fsck(g, fstype, device);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return -1;
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
 */
gboolean
guestfs_session_zero(GuestfsSession *session, const gchar *device, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "zero");
    return FALSE;
  }

  int ret = guestfs_zero(g, device);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return FALSE;
  }

  return TRUE;
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
 * "/boot/grub/device.map" file first that contains the mapping between
 * grub device names and Linux device names. It is usually sufficient
 * to create a file containing:
 * 
 * <![CDATA[(hd0) /dev/vda]]>
 * 
 * replacing "/dev/vda" with the name of the installation device.
 * 
 * Returns: true on success, false on error
 */
gboolean
guestfs_session_grub_install(GuestfsSession *session, const gchar *root, const gchar *device, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "grub_install");
    return FALSE;
  }

  int ret = guestfs_grub_install(g, root, device);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
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
 */
gboolean
guestfs_session_cp(GuestfsSession *session, const gchar *src, const gchar *dest, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "cp");
    return FALSE;
  }

  int ret = guestfs_cp(g, src, dest);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
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
 */
gboolean
guestfs_session_cp_a(GuestfsSession *session, const gchar *src, const gchar *dest, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "cp_a");
    return FALSE;
  }

  int ret = guestfs_cp_a(g, src, dest);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return FALSE;
  }

  return TRUE;
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
 * Returns: true on success, false on error
 */
gboolean
guestfs_session_mv(GuestfsSession *session, const gchar *src, const gchar *dest, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "mv");
    return FALSE;
  }

  int ret = guestfs_mv(g, src, dest);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
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
 */
gboolean
guestfs_session_drop_caches(GuestfsSession *session, gint32 whattodrop, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "drop_caches");
    return FALSE;
  }

  int ret = guestfs_drop_caches(g, whattodrop);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return FALSE;
  }

  return TRUE;
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
 */
gchar *
guestfs_session_dmesg(GuestfsSession *session, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "dmesg");
    return NULL;
  }

  char *ret = guestfs_dmesg(g);
  if (ret == NULL) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return NULL;
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
 * This is a test probe into the guestfs daemon running inside the qemu
 * subprocess. Calling this function checks that the daemon responds to the
 * ping message, without affecting the daemon or attached block device(s)
 * in any other way.
 * 
 * Returns: true on success, false on error
 */
gboolean
guestfs_session_ping_daemon(GuestfsSession *session, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "ping_daemon");
    return FALSE;
  }

  int ret = guestfs_ping_daemon(g);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return FALSE;
  }

  return TRUE;
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
 * This compares the two files @file1 and @file2 and returns true if their
 * content is exactly equal, or false otherwise.
 * 
 * The external cmp(1) program is used for the comparison.
 * 
 * Returns: the returned value, or -1 on error
 */
gint8
guestfs_session_equal(GuestfsSession *session, const gchar *file1, const gchar *file2, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "equal");
    return -1;
  }

  int ret = guestfs_equal(g, file1, file2);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return -1;
  }

  return ret;
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
 * Returns: (transfer full) (array zero-terminated=1) (element-type utf8): an array of returned strings, or NULL on error
 */
gchar **
guestfs_session_strings(GuestfsSession *session, const gchar *path, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "strings");
    return NULL;
  }

  char **ret = guestfs_strings(g, path);
  if (ret == NULL) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
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
 * Returns: (transfer full) (array zero-terminated=1) (element-type utf8): an array of returned strings, or NULL on error
 */
gchar **
guestfs_session_strings_e(GuestfsSession *session, const gchar *encoding, const gchar *path, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "strings_e");
    return NULL;
  }

  char **ret = guestfs_strings_e(g, encoding, path);
  if (ret == NULL) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
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
 */
gchar *
guestfs_session_hexdump(GuestfsSession *session, const gchar *path, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "hexdump");
    return NULL;
  }

  char *ret = guestfs_hexdump(g, path);
  if (ret == NULL) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return NULL;
  }

  return ret;
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
 */
gboolean
guestfs_session_zerofree(GuestfsSession *session, const gchar *device, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "zerofree");
    return FALSE;
  }

  int ret = guestfs_zerofree(g, device);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
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
 */
gboolean
guestfs_session_pvresize(GuestfsSession *session, const gchar *device, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "pvresize");
    return FALSE;
  }

  int ret = guestfs_pvresize(g, device);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
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
 */
gboolean
guestfs_session_sfdisk_N(GuestfsSession *session, const gchar *device, gint32 partnum, gint32 cyls, gint32 heads, gint32 sectors, const gchar *line, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "sfdisk_N");
    return FALSE;
  }

  int ret = guestfs_sfdisk_N(g, device, partnum, cyls, heads, sectors, line);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return FALSE;
  }

  return TRUE;
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
 */
gchar *
guestfs_session_sfdisk_l(GuestfsSession *session, const gchar *device, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "sfdisk_l");
    return NULL;
  }

  char *ret = guestfs_sfdisk_l(g, device);
  if (ret == NULL) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
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
 */
gchar *
guestfs_session_sfdisk_kernel_geometry(GuestfsSession *session, const gchar *device, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "sfdisk_kernel_geometry");
    return NULL;
  }

  char *ret = guestfs_sfdisk_kernel_geometry(g, device);
  if (ret == NULL) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return NULL;
  }

  return ret;
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
 */
gchar *
guestfs_session_sfdisk_disk_geometry(GuestfsSession *session, const gchar *device, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "sfdisk_disk_geometry");
    return NULL;
  }

  char *ret = guestfs_sfdisk_disk_geometry(g, device);
  if (ret == NULL) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return NULL;
  }

  return ret;
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
 */
gboolean
guestfs_session_vg_activate_all(GuestfsSession *session, gboolean activate, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "vg_activate_all");
    return FALSE;
  }

  int ret = guestfs_vg_activate_all(g, activate);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return FALSE;
  }

  return TRUE;
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
 */
gboolean
guestfs_session_vg_activate(GuestfsSession *session, gboolean activate, gchar *const *volgroups, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "vg_activate");
    return FALSE;
  }

  int ret = guestfs_vg_activate(g, activate, volgroups);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
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
 */
gboolean
guestfs_session_lvresize(GuestfsSession *session, const gchar *device, gint32 mbytes, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "lvresize");
    return FALSE;
  }

  int ret = guestfs_lvresize(g, device, mbytes);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
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
 */
gboolean
guestfs_session_resize2fs(GuestfsSession *session, const gchar *device, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "resize2fs");
    return FALSE;
  }

  int ret = guestfs_resize2fs(g, device);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
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
 * at @directory. It is essentially equivalent to running the shell command
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
 * then the returned list from guestfs_session_find() "/tmp" would be 4
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
 * If @directory is not a directory, then this command returns an error.
 * 
 * The returned list is sorted.
 * 
 * See also guestfs_session_find0().
 * 
 * Returns: (transfer full) (array zero-terminated=1) (element-type utf8): an array of returned strings, or NULL on error
 */
gchar **
guestfs_session_find(GuestfsSession *session, const gchar *directory, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "find");
    return NULL;
  }

  char **ret = guestfs_find(g, directory);
  if (ret == NULL) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return NULL;
  }

  return ret;
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
 */
gboolean
guestfs_session_e2fsck_f(GuestfsSession *session, const gchar *device, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "e2fsck_f");
    return FALSE;
  }

  int ret = guestfs_e2fsck_f(g, device);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
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
 */
gboolean
guestfs_session_sleep(GuestfsSession *session, gint32 secs, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "sleep");
    return FALSE;
  }

  int ret = guestfs_sleep(g, secs);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return FALSE;
  }

  return TRUE;
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
 */
gint32
guestfs_session_ntfs_3g_probe(GuestfsSession *session, gboolean rw, const gchar *device, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "ntfs_3g_probe");
    return -1;
  }

  int ret = guestfs_ntfs_3g_probe(g, rw, device);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return -1;
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
 * "/bin/sh".
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
 */
gchar *
guestfs_session_sh(GuestfsSession *session, const gchar *command, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "sh");
    return NULL;
  }

  char *ret = guestfs_sh(g, command);
  if (ret == NULL) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
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
 */
gchar **
guestfs_session_sh_lines(GuestfsSession *session, const gchar *command, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "sh_lines");
    return NULL;
  }

  char **ret = guestfs_sh_lines(g, command);
  if (ret == NULL) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return NULL;
  }

  return ret;
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
 * (eg. "/dev/sd*"). Use guestfs_session_list_devices(),
 * guestfs_session_list_partitions() etc functions instead.
 * 
 * Returns: (transfer full) (array zero-terminated=1) (element-type utf8): an array of returned strings, or NULL on error
 */
gchar **
guestfs_session_glob_expand(GuestfsSession *session, const gchar *pattern, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "glob_expand");
    return NULL;
  }

  char **ret = guestfs_glob_expand(g, pattern);
  if (ret == NULL) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return NULL;
  }

  return ret;
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
 */
gboolean
guestfs_session_scrub_device(GuestfsSession *session, const gchar *device, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "scrub_device");
    return FALSE;
  }

  int ret = guestfs_scrub_device(g, device);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
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
 */
gboolean
guestfs_session_scrub_file(GuestfsSession *session, const gchar *file, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "scrub_file");
    return FALSE;
  }

  int ret = guestfs_scrub_file(g, file);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
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
 */
gboolean
guestfs_session_scrub_freespace(GuestfsSession *session, const gchar *dir, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "scrub_freespace");
    return FALSE;
  }

  int ret = guestfs_scrub_freespace(g, dir);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
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
 */
gchar *
guestfs_session_mkdtemp(GuestfsSession *session, const gchar *tmpl, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "mkdtemp");
    return NULL;
  }

  char *ret = guestfs_mkdtemp(g, tmpl);
  if (ret == NULL) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return NULL;
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
 */
gint32
guestfs_session_wc_l(GuestfsSession *session, const gchar *path, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "wc_l");
    return -1;
  }

  int ret = guestfs_wc_l(g, path);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
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
 */
gint32
guestfs_session_wc_w(GuestfsSession *session, const gchar *path, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "wc_w");
    return -1;
  }

  int ret = guestfs_wc_w(g, path);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return -1;
  }

  return ret;
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
 */
gint32
guestfs_session_wc_c(GuestfsSession *session, const gchar *path, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "wc_c");
    return -1;
  }

  int ret = guestfs_wc_c(g, path);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return -1;
  }

  return ret;
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
 */
gchar **
guestfs_session_head(GuestfsSession *session, const gchar *path, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "head");
    return NULL;
  }

  char **ret = guestfs_head(g, path);
  if (ret == NULL) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
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
 */
gchar **
guestfs_session_head_n(GuestfsSession *session, gint32 nrlines, const gchar *path, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "head_n");
    return NULL;
  }

  char **ret = guestfs_head_n(g, nrlines, path);
  if (ret == NULL) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return NULL;
  }

  return ret;
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
 */
gchar **
guestfs_session_tail(GuestfsSession *session, const gchar *path, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "tail");
    return NULL;
  }

  char **ret = guestfs_tail(g, path);
  if (ret == NULL) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
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
 */
gchar **
guestfs_session_tail_n(GuestfsSession *session, gint32 nrlines, const gchar *path, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "tail_n");
    return NULL;
  }

  char **ret = guestfs_tail_n(g, nrlines, path);
  if (ret == NULL) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return NULL;
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
 */
gchar *
guestfs_session_df(GuestfsSession *session, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "df");
    return NULL;
  }

  char *ret = guestfs_df(g);
  if (ret == NULL) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
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
 */
gchar *
guestfs_session_df_h(GuestfsSession *session, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "df_h");
    return NULL;
  }

  char *ret = guestfs_df_h(g);
  if (ret == NULL) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return NULL;
  }

  return ret;
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
 */
gint64
guestfs_session_du(GuestfsSession *session, const gchar *path, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "du");
    return -1;
  }

  int64_t ret = guestfs_du(g, path);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return -1;
  }

  return ret;
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
 * The files are listed without any initial "/" character. The files are
 * listed in the order they appear (not necessarily alphabetical).
 * Directory names are listed as separate items.
 * 
 * Old Linux kernels (2.4 and earlier) used a compressed ext2 filesystem as
 * initrd. We *only* support the newer initramfs format (compressed cpio
 * files).
 * 
 * Returns: (transfer full) (array zero-terminated=1) (element-type utf8): an array of returned strings, or NULL on error
 */
gchar **
guestfs_session_initrd_list(GuestfsSession *session, const gchar *path, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "initrd_list");
    return NULL;
  }

  char **ret = guestfs_initrd_list(g, path);
  if (ret == NULL) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return NULL;
  }

  return ret;
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
 * This command lets you mount @file (a filesystem image in a file) on a
 * mount point. It is entirely equivalent to the command "mount -o loop
 * file mountpoint".
 * 
 * Returns: true on success, false on error
 */
gboolean
guestfs_session_mount_loop(GuestfsSession *session, const gchar *file, const gchar *mountpoint, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "mount_loop");
    return FALSE;
  }

  int ret = guestfs_mount_loop(g, file, mountpoint);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return FALSE;
  }

  return TRUE;
}

/**
 * guestfs_session_mkswap:
 * @session: (transfer none): A GuestfsSession object
 * @device: (transfer none) (type filename):
 * @err: A GError object to receive any generated errors
 *
 * create a swap partition
 *
 * Create a swap partition on @device.
 * 
 * Returns: true on success, false on error
 */
gboolean
guestfs_session_mkswap(GuestfsSession *session, const gchar *device, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "mkswap");
    return FALSE;
  }

  int ret = guestfs_mkswap(g, device);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
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
 * "/dev/sda"), just to a partition. This appears to be a limitation of the
 * kernel or swap tools.
 * 
 * Returns: true on success, false on error
 */
gboolean
guestfs_session_mkswap_L(GuestfsSession *session, const gchar *label, const gchar *device, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "mkswap_L");
    return FALSE;
  }

  int ret = guestfs_mkswap_L(g, label, device);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
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
 */
gboolean
guestfs_session_mkswap_U(GuestfsSession *session, const gchar *uuid, const gchar *device, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "mkswap_U");
    return FALSE;
  }

  int ret = guestfs_mkswap_U(g, uuid, device);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
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
 */
gboolean
guestfs_session_mknod(GuestfsSession *session, gint32 mode, gint32 devmajor, gint32 devminor, const gchar *path, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "mknod");
    return FALSE;
  }

  int ret = guestfs_mknod(g, mode, devmajor, devminor, path);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
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
 * The mode actually set is affected by the umask.
 * 
 * Returns: true on success, false on error
 */
gboolean
guestfs_session_mkfifo(GuestfsSession *session, gint32 mode, const gchar *path, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "mkfifo");
    return FALSE;
  }

  int ret = guestfs_mkfifo(g, mode, path);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
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
 * The mode actually set is affected by the umask.
 * 
 * Returns: true on success, false on error
 */
gboolean
guestfs_session_mknod_b(GuestfsSession *session, gint32 mode, gint32 devmajor, gint32 devminor, const gchar *path, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "mknod_b");
    return FALSE;
  }

  int ret = guestfs_mknod_b(g, mode, devmajor, devminor, path);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
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
 * The mode actually set is affected by the umask.
 * 
 * Returns: true on success, false on error
 */
gboolean
guestfs_session_mknod_c(GuestfsSession *session, gint32 mode, gint32 devmajor, gint32 devminor, const gchar *path, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "mknod_c");
    return FALSE;
  }

  int ret = guestfs_mknod_c(g, mode, devmajor, devminor, path);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
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
 */
gint32
guestfs_session_umask(GuestfsSession *session, gint32 mask, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "umask");
    return -1;
  }

  int ret = guestfs_umask(g, mask);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return -1;
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
 */
GuestfsDirent **
guestfs_session_readdir(GuestfsSession *session, const gchar *dir, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "readdir");
    return NULL;
  }

  struct guestfs_dirent_list *ret = guestfs_readdir(g, dir);
  if (ret == NULL) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return NULL;
  }

  GuestfsDirent **l = g_malloc(sizeof(GuestfsDirent*) * (ret->len + 1));
  gsize i;
  for (i = 0; i < ret->len; i++) {
    l[i] = g_slice_new0(GuestfsDirent);
    l[i]->ino = ret->val[i].ino;
    l[i]->ftyp = ret->val[i].ftyp;
    if (ret->val[i].name) l[i]->name = g_strdup(ret->val[i].name);
  }
  guestfs_free_dirent_list(ret);
  l[i] = NULL;
  return l;
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
 */
gboolean
guestfs_session_sfdiskM(GuestfsSession *session, const gchar *device, gchar *const *lines, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "sfdiskM");
    return FALSE;
  }

  int ret = guestfs_sfdiskM(g, device, lines);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return FALSE;
  }

  return TRUE;
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
 * This command runs @file after first decompressing @path using @method.
 * 
 * @method must be one of @gzip, @compress or @bzip2.
 * 
 * Since 1.0.63, use guestfs_session_file() instead which can now process
 * compressed files.
 * 
 * Returns: (transfer full): the returned string, or NULL on error
 */
gchar *
guestfs_session_zfile(GuestfsSession *session, const gchar *meth, const gchar *path, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "zfile");
    return NULL;
  }

  char *ret = guestfs_zfile(g, meth, path);
  if (ret == NULL) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return NULL;
  }

  return ret;
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
 */
GuestfsXAttr **
guestfs_session_getxattrs(GuestfsSession *session, const gchar *path, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "getxattrs");
    return NULL;
  }

  struct guestfs_xattr_list *ret = guestfs_getxattrs(g, path);
  if (ret == NULL) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return NULL;
  }

  GuestfsXAttr **l = g_malloc(sizeof(GuestfsXAttr*) * (ret->len + 1));
  gsize i;
  for (i = 0; i < ret->len; i++) {
    l[i] = g_slice_new0(GuestfsXAttr);
    if (ret->val[i].attrname) l[i]->attrname = g_strdup(ret->val[i].attrname);
    if (ret->val[i].attrval) {
      l[i]->attrval = g_byte_array_sized_new(ret->val[i].attrval_len);
      g_byte_array_append(l[i]->attrval, ret->val[i].attrval, ret->val[i].attrval_len);
    }
  }
  guestfs_free_xattr_list(ret);
  l[i] = NULL;
  return l;
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
 */
GuestfsXAttr **
guestfs_session_lgetxattrs(GuestfsSession *session, const gchar *path, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "lgetxattrs");
    return NULL;
  }

  struct guestfs_xattr_list *ret = guestfs_lgetxattrs(g, path);
  if (ret == NULL) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return NULL;
  }

  GuestfsXAttr **l = g_malloc(sizeof(GuestfsXAttr*) * (ret->len + 1));
  gsize i;
  for (i = 0; i < ret->len; i++) {
    l[i] = g_slice_new0(GuestfsXAttr);
    if (ret->val[i].attrname) l[i]->attrname = g_strdup(ret->val[i].attrname);
    if (ret->val[i].attrval) {
      l[i]->attrval = g_byte_array_sized_new(ret->val[i].attrval_len);
      g_byte_array_append(l[i]->attrval, ret->val[i].attrval, ret->val[i].attrval_len);
    }
  }
  guestfs_free_xattr_list(ret);
  l[i] = NULL;
  return l;
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
 */
gboolean
guestfs_session_setxattr(GuestfsSession *session, const gchar *xattr, const gchar *val, gint32 vallen, const gchar *path, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "setxattr");
    return FALSE;
  }

  int ret = guestfs_setxattr(g, xattr, val, vallen, path);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
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
 */
gboolean
guestfs_session_lsetxattr(GuestfsSession *session, const gchar *xattr, const gchar *val, gint32 vallen, const gchar *path, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "lsetxattr");
    return FALSE;
  }

  int ret = guestfs_lsetxattr(g, xattr, val, vallen, path);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
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
 */
gboolean
guestfs_session_removexattr(GuestfsSession *session, const gchar *xattr, const gchar *path, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "removexattr");
    return FALSE;
  }

  int ret = guestfs_removexattr(g, xattr, path);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
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
 */
gboolean
guestfs_session_lremovexattr(GuestfsSession *session, const gchar *xattr, const gchar *path, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "lremovexattr");
    return FALSE;
  }

  int ret = guestfs_lremovexattr(g, xattr, path);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
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
 */
GHashTable *
guestfs_session_mountpoints(GuestfsSession *session, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "mountpoints");
    return NULL;
  }

  char **ret = guestfs_mountpoints(g);
  if (ret == NULL) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return NULL;
  }

  GHashTable *h = g_hash_table_new_full(g_str_hash, g_str_equal, g_free, g_free);
  char **i = ret;
  while (*i) {
    char *key = *i; i++;
    char *value = *i; i++;
    g_hash_table_insert(h, key, value);
  };
  g_free(ret);
  return h;
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
 */
gboolean
guestfs_session_mkmountpoint(GuestfsSession *session, const gchar *exemptpath, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "mkmountpoint");
    return FALSE;
  }

  int ret = guestfs_mkmountpoint(g, exemptpath);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
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
 */
gboolean
guestfs_session_rmmountpoint(GuestfsSession *session, const gchar *exemptpath, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "rmmountpoint");
    return FALSE;
  }

  int ret = guestfs_rmmountpoint(g, exemptpath);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return FALSE;
  }

  return TRUE;
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
 * that contain embedded ASCII NUL characters. However unlike
 * guestfs_session_download(), this function is limited in the total size
 * of file that can be handled.
 * 
 * Returns: (transfer full) (array length=size_r) (element-type guint8): an array of binary data, or NULL on error
 */
guint8 *
guestfs_session_read_file(GuestfsSession *session, const gchar *path, gsize *size_r, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "read_file");
    return NULL;
  }

  char *ret = guestfs_read_file(g, path, size_r);
  if (ret == NULL) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return NULL;
  }

  return ret;
}

/**
 * guestfs_session_grep:
 * @session: (transfer none): A GuestfsSession object
 * @regex: (transfer none) (type utf8):
 * @path: (transfer none) (type filename):
 * @err: A GError object to receive any generated errors
 *
 * return lines matching a pattern
 *
 * This calls the external @grep program and returns the matching lines.
 * 
 * Returns: (transfer full) (array zero-terminated=1) (element-type utf8): an array of returned strings, or NULL on error
 */
gchar **
guestfs_session_grep(GuestfsSession *session, const gchar *regex, const gchar *path, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "grep");
    return NULL;
  }

  char **ret = guestfs_grep(g, regex, path);
  if (ret == NULL) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
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
 */
gchar **
guestfs_session_egrep(GuestfsSession *session, const gchar *regex, const gchar *path, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "egrep");
    return NULL;
  }

  char **ret = guestfs_egrep(g, regex, path);
  if (ret == NULL) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return NULL;
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
 */
gchar **
guestfs_session_fgrep(GuestfsSession *session, const gchar *pattern, const gchar *path, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "fgrep");
    return NULL;
  }

  char **ret = guestfs_fgrep(g, pattern, path);
  if (ret == NULL) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
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
 */
gchar **
guestfs_session_grepi(GuestfsSession *session, const gchar *regex, const gchar *path, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "grepi");
    return NULL;
  }

  char **ret = guestfs_grepi(g, regex, path);
  if (ret == NULL) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
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
 */
gchar **
guestfs_session_egrepi(GuestfsSession *session, const gchar *regex, const gchar *path, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "egrepi");
    return NULL;
  }

  char **ret = guestfs_egrepi(g, regex, path);
  if (ret == NULL) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
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
 */
gchar **
guestfs_session_fgrepi(GuestfsSession *session, const gchar *pattern, const gchar *path, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "fgrepi");
    return NULL;
  }

  char **ret = guestfs_fgrepi(g, pattern, path);
  if (ret == NULL) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
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
 */
gchar **
guestfs_session_zgrep(GuestfsSession *session, const gchar *regex, const gchar *path, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "zgrep");
    return NULL;
  }

  char **ret = guestfs_zgrep(g, regex, path);
  if (ret == NULL) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return NULL;
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
 */
gchar **
guestfs_session_zegrep(GuestfsSession *session, const gchar *regex, const gchar *path, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "zegrep");
    return NULL;
  }

  char **ret = guestfs_zegrep(g, regex, path);
  if (ret == NULL) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return NULL;
  }

  return ret;
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
 */
gchar **
guestfs_session_zfgrep(GuestfsSession *session, const gchar *pattern, const gchar *path, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "zfgrep");
    return NULL;
  }

  char **ret = guestfs_zfgrep(g, pattern, path);
  if (ret == NULL) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
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
 */
gchar **
guestfs_session_zgrepi(GuestfsSession *session, const gchar *regex, const gchar *path, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "zgrepi");
    return NULL;
  }

  char **ret = guestfs_zgrepi(g, regex, path);
  if (ret == NULL) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
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
 */
gchar **
guestfs_session_zegrepi(GuestfsSession *session, const gchar *regex, const gchar *path, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "zegrepi");
    return NULL;
  }

  char **ret = guestfs_zegrepi(g, regex, path);
  if (ret == NULL) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
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
 */
gchar **
guestfs_session_zfgrepi(GuestfsSession *session, const gchar *pattern, const gchar *path, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "zfgrepi");
    return NULL;
  }

  char **ret = guestfs_zfgrepi(g, pattern, path);
  if (ret == NULL) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
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
 */
gchar *
guestfs_session_realpath(GuestfsSession *session, const gchar *path, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "realpath");
    return NULL;
  }

  char *ret = guestfs_realpath(g, path);
  if (ret == NULL) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
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
 */
gboolean
guestfs_session_ln(GuestfsSession *session, const gchar *target, const gchar *linkname, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "ln");
    return FALSE;
  }

  int ret = guestfs_ln(g, target, linkname);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
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
 */
gboolean
guestfs_session_ln_f(GuestfsSession *session, const gchar *target, const gchar *linkname, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "ln_f");
    return FALSE;
  }

  int ret = guestfs_ln_f(g, target, linkname);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
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
 */
gboolean
guestfs_session_ln_s(GuestfsSession *session, const gchar *target, const gchar *linkname, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "ln_s");
    return FALSE;
  }

  int ret = guestfs_ln_s(g, target, linkname);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
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
 */
gboolean
guestfs_session_ln_sf(GuestfsSession *session, const gchar *target, const gchar *linkname, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "ln_sf");
    return FALSE;
  }

  int ret = guestfs_ln_sf(g, target, linkname);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return FALSE;
  }

  return TRUE;
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
 */
gchar *
guestfs_session_readlink(GuestfsSession *session, const gchar *path, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "readlink");
    return NULL;
  }

  char *ret = guestfs_readlink(g, path);
  if (ret == NULL) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return NULL;
  }

  return ret;
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
 */
gboolean
guestfs_session_fallocate(GuestfsSession *session, const gchar *path, gint32 len, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "fallocate");
    return FALSE;
  }

  int ret = guestfs_fallocate(g, path, len);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
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
 */
gboolean
guestfs_session_swapon_device(GuestfsSession *session, const gchar *device, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "swapon_device");
    return FALSE;
  }

  int ret = guestfs_swapon_device(g, device);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return FALSE;
  }

  return TRUE;
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
 */
gboolean
guestfs_session_swapoff_device(GuestfsSession *session, const gchar *device, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "swapoff_device");
    return FALSE;
  }

  int ret = guestfs_swapoff_device(g, device);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
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
 */
gboolean
guestfs_session_swapon_file(GuestfsSession *session, const gchar *file, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "swapon_file");
    return FALSE;
  }

  int ret = guestfs_swapon_file(g, file);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
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
 */
gboolean
guestfs_session_swapoff_file(GuestfsSession *session, const gchar *file, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "swapoff_file");
    return FALSE;
  }

  int ret = guestfs_swapoff_file(g, file);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
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
 */
gboolean
guestfs_session_swapon_label(GuestfsSession *session, const gchar *label, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "swapon_label");
    return FALSE;
  }

  int ret = guestfs_swapon_label(g, label);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
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
 */
gboolean
guestfs_session_swapoff_label(GuestfsSession *session, const gchar *label, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "swapoff_label");
    return FALSE;
  }

  int ret = guestfs_swapoff_label(g, label);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
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
 */
gboolean
guestfs_session_swapon_uuid(GuestfsSession *session, const gchar *uuid, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "swapon_uuid");
    return FALSE;
  }

  int ret = guestfs_swapon_uuid(g, uuid);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
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
 */
gboolean
guestfs_session_swapoff_uuid(GuestfsSession *session, const gchar *uuid, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "swapoff_uuid");
    return FALSE;
  }

  int ret = guestfs_swapoff_uuid(g, uuid);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
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
 */
gboolean
guestfs_session_mkswap_file(GuestfsSession *session, const gchar *path, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "mkswap_file");
    return FALSE;
  }

  int ret = guestfs_mkswap_file(g, path);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return FALSE;
  }

  return TRUE;
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
 */
gboolean
guestfs_session_inotify_init(GuestfsSession *session, gint32 maxevents, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "inotify_init");
    return FALSE;
  }

  int ret = guestfs_inotify_init(g, maxevents);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return FALSE;
  }

  return TRUE;
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
 * the Linux kernel ABI and are listed in "/usr/include/sys/inotify.h".
 * 
 * Returns: the returned value, or -1 on error
 */
gint64
guestfs_session_inotify_add_watch(GuestfsSession *session, const gchar *path, gint32 mask, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "inotify_add_watch");
    return -1;
  }

  int64_t ret = guestfs_inotify_add_watch(g, path, mask);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return -1;
  }

  return ret;
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
 */
gboolean
guestfs_session_inotify_rm_watch(GuestfsSession *session, gint32 wd, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "inotify_rm_watch");
    return FALSE;
  }

  int ret = guestfs_inotify_rm_watch(g, wd);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
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
 */
GuestfsINotifyEvent **
guestfs_session_inotify_read(GuestfsSession *session, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "inotify_read");
    return NULL;
  }

  struct guestfs_inotify_event_list *ret = guestfs_inotify_read(g);
  if (ret == NULL) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return NULL;
  }

  GuestfsINotifyEvent **l = g_malloc(sizeof(GuestfsINotifyEvent*) * (ret->len + 1));
  gsize i;
  for (i = 0; i < ret->len; i++) {
    l[i] = g_slice_new0(GuestfsINotifyEvent);
    l[i]->in_wd = ret->val[i].in_wd;
    l[i]->in_mask = ret->val[i].in_mask;
    l[i]->in_cookie = ret->val[i].in_cookie;
    if (ret->val[i].in_name) l[i]->in_name = g_strdup(ret->val[i].in_name);
  }
  guestfs_free_inotify_event_list(ret);
  l[i] = NULL;
  return l;
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
 */
gchar **
guestfs_session_inotify_files(GuestfsSession *session, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "inotify_files");
    return NULL;
  }

  char **ret = guestfs_inotify_files(g);
  if (ret == NULL) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return NULL;
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
 */
gboolean
guestfs_session_inotify_close(GuestfsSession *session, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "inotify_close");
    return FALSE;
  }

  int ret = guestfs_inotify_close(g);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
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
 */
gboolean
guestfs_session_setcon(GuestfsSession *session, const gchar *context, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "setcon");
    return FALSE;
  }

  int ret = guestfs_setcon(g, context);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return FALSE;
  }

  return TRUE;
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
 */
gchar *
guestfs_session_getcon(GuestfsSession *session, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "getcon");
    return NULL;
  }

  char *ret = guestfs_getcon(g);
  if (ret == NULL) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return NULL;
  }

  return ret;
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
 */
gboolean
guestfs_session_mkfs_b(GuestfsSession *session, const gchar *fstype, gint32 blocksize, const gchar *device, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "mkfs_b");
    return FALSE;
  }

  int ret = guestfs_mkfs_b(g, fstype, blocksize, device);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
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
 */
gboolean
guestfs_session_mke2journal(GuestfsSession *session, gint32 blocksize, const gchar *device, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "mke2journal");
    return FALSE;
  }

  int ret = guestfs_mke2journal(g, blocksize, device);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
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
 */
gboolean
guestfs_session_mke2journal_L(GuestfsSession *session, gint32 blocksize, const gchar *label, const gchar *device, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "mke2journal_L");
    return FALSE;
  }

  int ret = guestfs_mke2journal_L(g, blocksize, label, device);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
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
 */
gboolean
guestfs_session_mke2journal_U(GuestfsSession *session, gint32 blocksize, const gchar *uuid, const gchar *device, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "mke2journal_U");
    return FALSE;
  }

  int ret = guestfs_mke2journal_U(g, blocksize, uuid, device);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
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
 */
gboolean
guestfs_session_mke2fs_J(GuestfsSession *session, const gchar *fstype, gint32 blocksize, const gchar *device, const gchar *journal, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "mke2fs_J");
    return FALSE;
  }

  int ret = guestfs_mke2fs_J(g, fstype, blocksize, device, journal);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
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
 */
gboolean
guestfs_session_mke2fs_JL(GuestfsSession *session, const gchar *fstype, gint32 blocksize, const gchar *device, const gchar *label, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "mke2fs_JL");
    return FALSE;
  }

  int ret = guestfs_mke2fs_JL(g, fstype, blocksize, device, label);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
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
 */
gboolean
guestfs_session_mke2fs_JU(GuestfsSession *session, const gchar *fstype, gint32 blocksize, const gchar *device, const gchar *uuid, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "mke2fs_JU");
    return FALSE;
  }

  int ret = guestfs_mke2fs_JU(g, fstype, blocksize, device, uuid);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return FALSE;
  }

  return TRUE;
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
 * The kernel module must have been whitelisted when libguestfs was built
 * (see "appliance/kmod.whitelist.in" in the source).
 * 
 * Returns: true on success, false on error
 */
gboolean
guestfs_session_modprobe(GuestfsSession *session, const gchar *modulename, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "modprobe");
    return FALSE;
  }

  int ret = guestfs_modprobe(g, modulename);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
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
 */
gchar *
guestfs_session_echo_daemon(GuestfsSession *session, gchar *const *words, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "echo_daemon");
    return NULL;
  }

  char *ret = guestfs_echo_daemon(g, words);
  if (ret == NULL) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
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
 * at @directory, placing the resulting list in the external file called
 * @files.
 * 
 * This command works the same way as guestfs_session_find() with the
 * following exceptions:
 * 
 * *   The resulting list is written to an external file.
 * 
 * *   Items (filenames) in the result are separated by "\0" characters.
 * See find(1) option *-print0*.
 * 
 * *   This command is not limited in the number of names that it can
 * return.
 * 
 * *   The result list is not sorted.
 * 
 * Returns: true on success, false on error
 */
gboolean
guestfs_session_find0(GuestfsSession *session, const gchar *directory, const gchar *files, GCancellable *cancellable, GError **err)
{
  /* Check we haven't already been cancelled */
  if (g_cancellable_set_error_if_cancelled (cancellable, err))
    return FALSE;

  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "find0");
    return FALSE;
  }

  gulong id = 0;
  if (cancellable) {
    id = g_cancellable_connect(cancellable,
                               G_CALLBACK(cancelled_handler),
                               g, NULL);
  }

  int ret = guestfs_find0(g, directory, files);
  g_cancellable_disconnect(cancellable, id);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
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
 * One consequence of this is that special directories such as "c:\windows"
 * may appear as "/WINDOWS" or "/windows" (or other things) depending on
 * the precise details of how they were created. In Windows itself this
 * would not be a problem.
 * 
 * Bug or feature? You decide: <ulink
 * url='http://www.tuxera.com/community/ntfs-3g-faq/#posixfilenames1'>
 * http://www.tuxera.com/community/ntfs-3g-faq/#posixfilenames1 </ulink>
 * 
 * This function resolves the true case of each element in the path and
 * returns the case-sensitive path.
 * 
 * Thus guestfs_session_case_sensitive_path() ("/Windows/System32") might
 * return "/WINDOWS/system32" (the exact return value would depend on
 * details of how the directories were originally created under Windows).
 * 
 * *Note*: This function does not handle drive names, backslashes etc.
 * 
 * See also guestfs_session_realpath().
 * 
 * Returns: (transfer full): the returned string, or NULL on error
 */
gchar *
guestfs_session_case_sensitive_path(GuestfsSession *session, const gchar *path, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "case_sensitive_path");
    return NULL;
  }

  char *ret = guestfs_case_sensitive_path(g, path);
  if (ret == NULL) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return NULL;
  }

  return ret;
}

/**
 * guestfs_session_vfs_type:
 * @session: (transfer none): A GuestfsSession object
 * @device: (transfer none) (type filename):
 * @err: A GError object to receive any generated errors
 *
 * get the Linux VFS type corresponding to a mounted device
 *
 * This command gets the filesystem type corresponding to the filesystem on
 * @device.
 * 
 * For most filesystems, the result is the name of the Linux VFS module
 * which would be used to mount this filesystem if you mounted it without
 * specifying the filesystem type. For example a string such as @ext3 or
 * @ntfs.
 * 
 * Returns: (transfer full): the returned string, or NULL on error
 */
gchar *
guestfs_session_vfs_type(GuestfsSession *session, const gchar *device, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "vfs_type");
    return NULL;
  }

  char *ret = guestfs_vfs_type(g, device);
  if (ret == NULL) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return NULL;
  }

  return ret;
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
 */
gboolean
guestfs_session_truncate(GuestfsSession *session, const gchar *path, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "truncate");
    return FALSE;
  }

  int ret = guestfs_truncate(g, path);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
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
 */
gboolean
guestfs_session_truncate_size(GuestfsSession *session, const gchar *path, gint64 size, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "truncate_size");
    return FALSE;
  }

  int ret = guestfs_truncate_size(g, path, size);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
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
 */
gboolean
guestfs_session_utimens(GuestfsSession *session, const gchar *path, gint64 atsecs, gint64 atnsecs, gint64 mtsecs, gint64 mtnsecs, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "utimens");
    return FALSE;
  }

  int ret = guestfs_utimens(g, path, atsecs, atnsecs, mtsecs, mtnsecs);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
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
 */
gboolean
guestfs_session_mkdir_mode(GuestfsSession *session, const gchar *path, gint32 mode, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "mkdir_mode");
    return FALSE;
  }

  int ret = guestfs_mkdir_mode(g, path, mode);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
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
 */
gboolean
guestfs_session_lchown(GuestfsSession *session, gint32 owner, gint32 group, const gchar *path, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "lchown");
    return FALSE;
  }

  int ret = guestfs_lchown(g, owner, group, path);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return FALSE;
  }

  return TRUE;
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
 * not be lstat'd, then the @ino field of that structure is set to @-1.
 * 
 * This call is intended for programs that want to efficiently list a
 * directory contents without making many round-trips. See also
 * guestfs_session_lxattrlist() for a similarly efficient call for getting
 * extended attributes. Very long directory listings might cause the
 * protocol message size to be exceeded, causing this call to fail. The
 * caller must split up such requests into smaller groups of names.
 * 
 * Returns: (transfer full) (array zero-terminated=1) (element-type GuestfsStat): an array of Stat objects, or NULL on error
 */
GuestfsStat **
guestfs_session_lstatlist(GuestfsSession *session, const gchar *path, gchar *const *names, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "lstatlist");
    return NULL;
  }

  struct guestfs_stat_list *ret = guestfs_lstatlist(g, path, names);
  if (ret == NULL) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return NULL;
  }

  GuestfsStat **l = g_malloc(sizeof(GuestfsStat*) * (ret->len + 1));
  gsize i;
  for (i = 0; i < ret->len; i++) {
    l[i] = g_slice_new0(GuestfsStat);
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
  guestfs_free_stat_list(ret);
  l[i] = NULL;
  return l;
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
 * standard stats. Very long directory listings might cause the protocol
 * message size to be exceeded, causing this call to fail. The caller must
 * split up such requests into smaller groups of names.
 * 
 * Returns: (transfer full) (array zero-terminated=1) (element-type GuestfsXAttr): an array of XAttr objects, or NULL on error
 */
GuestfsXAttr **
guestfs_session_lxattrlist(GuestfsSession *session, const gchar *path, gchar *const *names, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "lxattrlist");
    return NULL;
  }

  struct guestfs_xattr_list *ret = guestfs_lxattrlist(g, path, names);
  if (ret == NULL) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return NULL;
  }

  GuestfsXAttr **l = g_malloc(sizeof(GuestfsXAttr*) * (ret->len + 1));
  gsize i;
  for (i = 0; i < ret->len; i++) {
    l[i] = g_slice_new0(GuestfsXAttr);
    if (ret->val[i].attrname) l[i]->attrname = g_strdup(ret->val[i].attrname);
    if (ret->val[i].attrval) {
      l[i]->attrval = g_byte_array_sized_new(ret->val[i].attrval_len);
      g_byte_array_append(l[i]->attrval, ret->val[i].attrval, ret->val[i].attrval_len);
    }
  }
  guestfs_free_xattr_list(ret);
  l[i] = NULL;
  return l;
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
 * directory contents without making many round-trips. Very long directory
 * listings might cause the protocol message size to be exceeded, causing
 * this call to fail. The caller must split up such requests into smaller
 * groups of names.
 * 
 * Returns: (transfer full) (array zero-terminated=1) (element-type utf8): an array of returned strings, or NULL on error
 */
gchar **
guestfs_session_readlinklist(GuestfsSession *session, const gchar *path, gchar *const *names, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "readlinklist");
    return NULL;
  }

  char **ret = guestfs_readlinklist(g, path, names);
  if (ret == NULL) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return NULL;
  }

  return ret;
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
 */
guint8 *
guestfs_session_pread(GuestfsSession *session, const gchar *path, gint32 count, gint64 offset, gsize *size_r, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "pread");
    return NULL;
  }

  char *ret = guestfs_pread(g, path, count, offset, size_r);
  if (ret == NULL) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
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
 */
gboolean
guestfs_session_part_init(GuestfsSession *session, const gchar *device, const gchar *parttype, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "part_init");
    return FALSE;
  }

  int ret = guestfs_part_init(g, device, parttype);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
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
 */
gboolean
guestfs_session_part_add(GuestfsSession *session, const gchar *device, const gchar *prlogex, gint64 startsect, gint64 endsect, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "part_add");
    return FALSE;
  }

  int ret = guestfs_part_add(g, device, prlogex, startsect, endsect);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
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
 */
gboolean
guestfs_session_part_disk(GuestfsSession *session, const gchar *device, const gchar *parttype, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "part_disk");
    return FALSE;
  }

  int ret = guestfs_part_disk(g, device, parttype);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return FALSE;
  }

  return TRUE;
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
 */
gboolean
guestfs_session_part_set_bootable(GuestfsSession *session, const gchar *device, gint32 partnum, gboolean bootable, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "part_set_bootable");
    return FALSE;
  }

  int ret = guestfs_part_set_bootable(g, device, partnum, bootable);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
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
 */
gboolean
guestfs_session_part_set_name(GuestfsSession *session, const gchar *device, gint32 partnum, const gchar *name, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "part_set_name");
    return FALSE;
  }

  int ret = guestfs_part_set_name(g, device, partnum, name);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
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
 */
GuestfsPartition **
guestfs_session_part_list(GuestfsSession *session, const gchar *device, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "part_list");
    return NULL;
  }

  struct guestfs_partition_list *ret = guestfs_part_list(g, device);
  if (ret == NULL) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return NULL;
  }

  GuestfsPartition **l = g_malloc(sizeof(GuestfsPartition*) * (ret->len + 1));
  gsize i;
  for (i = 0; i < ret->len; i++) {
    l[i] = g_slice_new0(GuestfsPartition);
    l[i]->part_num = ret->val[i].part_num;
    l[i]->part_start = ret->val[i].part_start;
    l[i]->part_end = ret->val[i].part_end;
    l[i]->part_size = ret->val[i].part_size;
  }
  guestfs_free_partition_list(ret);
  l[i] = NULL;
  return l;
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
 */
gchar *
guestfs_session_part_get_parttype(GuestfsSession *session, const gchar *device, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "part_get_parttype");
    return NULL;
  }

  char *ret = guestfs_part_get_parttype(g, device);
  if (ret == NULL) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return NULL;
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
 */
gboolean
guestfs_session_fill(GuestfsSession *session, gint32 c, gint32 len, const gchar *path, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "fill");
    return FALSE;
  }

  int ret = guestfs_fill(g, c, len, path);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return FALSE;
  }

  return TRUE;
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
 * Returns: true on success, false on error
 */
gboolean
guestfs_session_available(GuestfsSession *session, gchar *const *groups, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "available");
    return FALSE;
  }

  int ret = guestfs_available(g, groups);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
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
 */
gboolean
guestfs_session_dd(GuestfsSession *session, const gchar *src, const gchar *dest, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "dd");
    return FALSE;
  }

  int ret = guestfs_dd(g, src, dest);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return FALSE;
  }

  return TRUE;
}

/**
 * guestfs_session_filesize:
 * @session: (transfer none): A GuestfsSession object
 * @file: (transfer none) (type filename):
 * @err: A GError object to receive any generated errors
 *
 * return the size of the file in bytes
 *
 * This command returns the size of @file in bytes.
 * 
 * To get other stats about a file, use guestfs_session_stat(),
 * guestfs_session_lstat(), guestfs_session_is_dir(),
 * guestfs_session_is_file() etc. To get the size of block devices, use
 * guestfs_session_blockdev_getsize64().
 * 
 * Returns: the returned value, or -1 on error
 */
gint64
guestfs_session_filesize(GuestfsSession *session, const gchar *file, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "filesize");
    return -1;
  }

  int64_t ret = guestfs_filesize(g, file);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return -1;
  }

  return ret;
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
 */
gboolean
guestfs_session_lvrename(GuestfsSession *session, const gchar *logvol, const gchar *newlogvol, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "lvrename");
    return FALSE;
  }

  int ret = guestfs_lvrename(g, logvol, newlogvol);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
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
 */
gboolean
guestfs_session_vgrename(GuestfsSession *session, const gchar *volgroup, const gchar *newvolgroup, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "vgrename");
    return FALSE;
  }

  int ret = guestfs_vgrename(g, volgroup, newvolgroup);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return FALSE;
  }

  return TRUE;
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
 * This command unpacks the file @filename from the initrd file called
 * @initrdpath. The filename must be given *without* the initial "/"
 * character.
 * 
 * For example, in guestfish you could use the following command to examine
 * the boot script (usually called "/init") contained in a Linux initrd or
 * initramfs image:
 * 
 * <![CDATA[initrd-cat /boot/initrd-<version>.img init]]>
 * 
 * See also guestfs_session_initrd_list().
 * 
 * Returns: (transfer full) (array length=size_r) (element-type guint8): an array of binary data, or NULL on error
 */
guint8 *
guestfs_session_initrd_cat(GuestfsSession *session, const gchar *initrdpath, const gchar *filename, gsize *size_r, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "initrd_cat");
    return NULL;
  }

  char *ret = guestfs_initrd_cat(g, initrdpath, filename, size_r);
  if (ret == NULL) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return NULL;
  }

  return ret;
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
 */
gchar *
guestfs_session_pvuuid(GuestfsSession *session, const gchar *device, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "pvuuid");
    return NULL;
  }

  char *ret = guestfs_pvuuid(g, device);
  if (ret == NULL) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return NULL;
  }

  return ret;
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
 */
gchar *
guestfs_session_vguuid(GuestfsSession *session, const gchar *vgname, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "vguuid");
    return NULL;
  }

  char *ret = guestfs_vguuid(g, vgname);
  if (ret == NULL) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return NULL;
  }

  return ret;
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
 */
gchar *
guestfs_session_lvuuid(GuestfsSession *session, const gchar *device, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "lvuuid");
    return NULL;
  }

  char *ret = guestfs_lvuuid(g, device);
  if (ret == NULL) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return NULL;
  }

  return ret;
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
 */
gchar **
guestfs_session_vgpvuuids(GuestfsSession *session, const gchar *vgname, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "vgpvuuids");
    return NULL;
  }

  char **ret = guestfs_vgpvuuids(g, vgname);
  if (ret == NULL) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return NULL;
  }

  return ret;
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
 */
gchar **
guestfs_session_vglvuuids(GuestfsSession *session, const gchar *vgname, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "vglvuuids");
    return NULL;
  }

  char **ret = guestfs_vglvuuids(g, vgname);
  if (ret == NULL) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return NULL;
  }

  return ret;
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
 */
gboolean
guestfs_session_copy_size(GuestfsSession *session, const gchar *src, const gchar *dest, gint64 size, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "copy_size");
    return FALSE;
  }

  int ret = guestfs_copy_size(g, src, dest, size);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
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
 */
gboolean
guestfs_session_zero_device(GuestfsSession *session, const gchar *device, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "zero_device");
    return FALSE;
  }

  int ret = guestfs_zero_device(g, device);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return FALSE;
  }

  return TRUE;
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
 * tar file) into @directory.
 * 
 * Returns: true on success, false on error
 */
gboolean
guestfs_session_txz_in(GuestfsSession *session, const gchar *tarball, const gchar *directory, GCancellable *cancellable, GError **err)
{
  /* Check we haven't already been cancelled */
  if (g_cancellable_set_error_if_cancelled (cancellable, err))
    return FALSE;

  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "txz_in");
    return FALSE;
  }

  gulong id = 0;
  if (cancellable) {
    id = g_cancellable_connect(cancellable,
                               G_CALLBACK(cancelled_handler),
                               g, NULL);
  }

  int ret = guestfs_txz_in(g, tarball, directory);
  g_cancellable_disconnect(cancellable, id);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
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
 * This command packs the contents of @directory and downloads it to local
 * file @tarball (as an xz compressed tar archive).
 * 
 * Returns: true on success, false on error
 */
gboolean
guestfs_session_txz_out(GuestfsSession *session, const gchar *directory, const gchar *tarball, GCancellable *cancellable, GError **err)
{
  /* Check we haven't already been cancelled */
  if (g_cancellable_set_error_if_cancelled (cancellable, err))
    return FALSE;

  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "txz_out");
    return FALSE;
  }

  gulong id = 0;
  if (cancellable) {
    id = g_cancellable_connect(cancellable,
                               G_CALLBACK(cancelled_handler),
                               g, NULL);
  }

  int ret = guestfs_txz_out(g, directory, tarball);
  g_cancellable_disconnect(cancellable, id);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return FALSE;
  }

  return TRUE;
}

/**
 * guestfs_session_ntfsresize:
 * @session: (transfer none): A GuestfsSession object
 * @device: (transfer none) (type filename):
 * @err: A GError object to receive any generated errors
 *
 * resize an NTFS filesystem
 *
 * This command resizes an NTFS filesystem, expanding or shrinking it to
 * the size of the underlying device.
 * 
 * *Note:* After the resize operation, the filesystem is marked as
 * requiring a consistency check (for safety). You have to boot into
 * Windows to perform this check and clear this condition. Furthermore,
 * ntfsresize refuses to resize filesystems which have been marked in this
 * way. So in effect it is not possible to call ntfsresize multiple times
 * on a single filesystem without booting into Windows between each resize.
 * 
 * See also ntfsresize(8).
 * 
 * Returns: true on success, false on error
 */
gboolean
guestfs_session_ntfsresize(GuestfsSession *session, const gchar *device, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "ntfsresize");
    return FALSE;
  }

  int ret = guestfs_ntfsresize(g, device);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return FALSE;
  }

  return TRUE;
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
 */
gboolean
guestfs_session_vgscan(GuestfsSession *session, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "vgscan");
    return FALSE;
  }

  int ret = guestfs_vgscan(g);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
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
 */
gboolean
guestfs_session_part_del(GuestfsSession *session, const gchar *device, gint32 partnum, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "part_del");
    return FALSE;
  }

  int ret = guestfs_part_del(g, device, partnum);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
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
 */
gint8
guestfs_session_part_get_bootable(GuestfsSession *session, const gchar *device, gint32 partnum, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "part_get_bootable");
    return -1;
  }

  int ret = guestfs_part_get_bootable(g, device, partnum);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return -1;
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
 */
gint32
guestfs_session_part_get_mbr_id(GuestfsSession *session, const gchar *device, gint32 partnum, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "part_get_mbr_id");
    return -1;
  }

  int ret = guestfs_part_get_mbr_id(g, device, partnum);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return -1;
  }

  return ret;
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
 */
gboolean
guestfs_session_part_set_mbr_id(GuestfsSession *session, const gchar *device, gint32 partnum, gint32 idbyte, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "part_set_mbr_id");
    return FALSE;
  }

  int ret = guestfs_part_set_mbr_id(g, device, partnum, idbyte);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return FALSE;
  }

  return TRUE;
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
 */
gchar *
guestfs_session_checksum_device(GuestfsSession *session, const gchar *csumtype, const gchar *device, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "checksum_device");
    return NULL;
  }

  char *ret = guestfs_checksum_device(g, csumtype, device);
  if (ret == NULL) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return NULL;
  }

  return ret;
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
 */
gboolean
guestfs_session_lvresize_free(GuestfsSession *session, const gchar *lv, gint32 percent, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "lvresize_free");
    return FALSE;
  }

  int ret = guestfs_lvresize_free(g, lv, percent);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return FALSE;
  }

  return TRUE;
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
 */
gboolean
guestfs_session_aug_clear(GuestfsSession *session, const gchar *augpath, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "aug_clear");
    return FALSE;
  }

  int ret = guestfs_aug_clear(g, augpath);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return FALSE;
  }

  return TRUE;
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
 */
gint32
guestfs_session_get_umask(GuestfsSession *session, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "get_umask");
    return -1;
  }

  int ret = guestfs_get_umask(g);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return -1;
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
 * file "daemon/debug.c" in the libguestfs source to find out what it is
 * for.
 * 
 * Returns: true on success, false on error
 */
gboolean
guestfs_session_debug_upload(GuestfsSession *session, const gchar *filename, const gchar *tmpname, gint32 mode, GCancellable *cancellable, GError **err)
{
  /* Check we haven't already been cancelled */
  if (g_cancellable_set_error_if_cancelled (cancellable, err))
    return FALSE;

  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "debug_upload");
    return FALSE;
  }

  gulong id = 0;
  if (cancellable) {
    id = g_cancellable_connect(cancellable,
                               G_CALLBACK(cancelled_handler),
                               g, NULL);
  }

  int ret = guestfs_debug_upload(g, filename, tmpname, mode);
  g_cancellable_disconnect(cancellable, id);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return FALSE;
  }

  return TRUE;
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
 * This command uploads base64-encoded data from @base64file to @filename.
 * 
 * Returns: true on success, false on error
 */
gboolean
guestfs_session_base64_in(GuestfsSession *session, const gchar *base64file, const gchar *filename, GCancellable *cancellable, GError **err)
{
  /* Check we haven't already been cancelled */
  if (g_cancellable_set_error_if_cancelled (cancellable, err))
    return FALSE;

  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "base64_in");
    return FALSE;
  }

  gulong id = 0;
  if (cancellable) {
    id = g_cancellable_connect(cancellable,
                               G_CALLBACK(cancelled_handler),
                               g, NULL);
  }

  int ret = guestfs_base64_in(g, base64file, filename);
  g_cancellable_disconnect(cancellable, id);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
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
 * This command downloads the contents of @filename, writing it out to
 * local file @base64file encoded as base64.
 * 
 * Returns: true on success, false on error
 */
gboolean
guestfs_session_base64_out(GuestfsSession *session, const gchar *filename, const gchar *base64file, GCancellable *cancellable, GError **err)
{
  /* Check we haven't already been cancelled */
  if (g_cancellable_set_error_if_cancelled (cancellable, err))
    return FALSE;

  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "base64_out");
    return FALSE;
  }

  gulong id = 0;
  if (cancellable) {
    id = g_cancellable_connect(cancellable,
                               G_CALLBACK(cancelled_handler),
                               g, NULL);
  }

  int ret = guestfs_base64_out(g, filename, base64file);
  g_cancellable_disconnect(cancellable, id);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return FALSE;
  }

  return TRUE;
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
 * This command computes the checksums of all regular files in @directory
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
 */
gboolean
guestfs_session_checksums_out(GuestfsSession *session, const gchar *csumtype, const gchar *directory, const gchar *sumsfile, GCancellable *cancellable, GError **err)
{
  /* Check we haven't already been cancelled */
  if (g_cancellable_set_error_if_cancelled (cancellable, err))
    return FALSE;

  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "checksums_out");
    return FALSE;
  }

  gulong id = 0;
  if (cancellable) {
    id = g_cancellable_connect(cancellable,
                               G_CALLBACK(cancelled_handler),
                               g, NULL);
  }

  int ret = guestfs_checksums_out(g, csumtype, directory, sumsfile);
  g_cancellable_disconnect(cancellable, id);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
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
 */
gboolean
guestfs_session_fill_pattern(GuestfsSession *session, const gchar *pattern, gint32 len, const gchar *path, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "fill_pattern");
    return FALSE;
  }

  int ret = guestfs_fill_pattern(g, pattern, len, path);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
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
 */
gboolean
guestfs_session_write(GuestfsSession *session, const gchar *path, const guint8 *content, gsize content_size, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "write");
    return FALSE;
  }

  int ret = guestfs_write(g, path, content, content_size);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return FALSE;
  }

  return TRUE;
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
 */
gint32
guestfs_session_pwrite(GuestfsSession *session, const gchar *path, const guint8 *content, gsize content_size, gint64 offset, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "pwrite");
    return -1;
  }

  int ret = guestfs_pwrite(g, path, content, content_size, offset);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return -1;
  }

  return ret;
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
 */
gboolean
guestfs_session_resize2fs_size(GuestfsSession *session, const gchar *device, gint64 size, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "resize2fs_size");
    return FALSE;
  }

  int ret = guestfs_resize2fs_size(g, device, size);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
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
 */
gboolean
guestfs_session_pvresize_size(GuestfsSession *session, const gchar *device, gint64 size, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "pvresize_size");
    return FALSE;
  }

  int ret = guestfs_pvresize_size(g, device, size);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
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
 */
gboolean
guestfs_session_ntfsresize_size(GuestfsSession *session, const gchar *device, gint64 size, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "ntfsresize_size");
    return FALSE;
  }

  int ret = guestfs_ntfsresize_size(g, device, size);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
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
 * guestfs_session_available() on each member of the returned list.
 * 
 * See also guestfs_session_available() and "AVAILABILITY" in guestfs(3).
 * 
 * Returns: (transfer full) (array zero-terminated=1) (element-type utf8): an array of returned strings, or NULL on error
 */
gchar **
guestfs_session_available_all_groups(GuestfsSession *session, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "available_all_groups");
    return NULL;
  }

  char **ret = guestfs_available_all_groups(g);
  if (ret == NULL) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return NULL;
  }

  return ret;
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
 */
gboolean
guestfs_session_fallocate64(GuestfsSession *session, const gchar *path, gint64 len, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "fallocate64");
    return FALSE;
  }

  int ret = guestfs_fallocate64(g, path, len);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return FALSE;
  }

  return TRUE;
}

/**
 * guestfs_session_vfs_label:
 * @session: (transfer none): A GuestfsSession object
 * @device: (transfer none) (type filename):
 * @err: A GError object to receive any generated errors
 *
 * get the filesystem label
 *
 * This returns the filesystem label of the filesystem on @device.
 * 
 * If the filesystem is unlabeled, this returns the empty string.
 * 
 * To find a filesystem from the label, use guestfs_session_findfs_label().
 * 
 * Returns: (transfer full): the returned string, or NULL on error
 */
gchar *
guestfs_session_vfs_label(GuestfsSession *session, const gchar *device, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "vfs_label");
    return NULL;
  }

  char *ret = guestfs_vfs_label(g, device);
  if (ret == NULL) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return NULL;
  }

  return ret;
}

/**
 * guestfs_session_vfs_uuid:
 * @session: (transfer none): A GuestfsSession object
 * @device: (transfer none) (type filename):
 * @err: A GError object to receive any generated errors
 *
 * get the filesystem UUID
 *
 * This returns the filesystem UUID of the filesystem on @device.
 * 
 * If the filesystem does not have a UUID, this returns the empty string.
 * 
 * To find a filesystem from the UUID, use guestfs_session_findfs_uuid().
 * 
 * Returns: (transfer full): the returned string, or NULL on error
 */
gchar *
guestfs_session_vfs_uuid(GuestfsSession *session, const gchar *device, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "vfs_uuid");
    return NULL;
  }

  char *ret = guestfs_vfs_uuid(g, device);
  if (ret == NULL) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return NULL;
  }

  return ret;
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
 */
gboolean
guestfs_session_lvm_set_filter(GuestfsSession *session, gchar *const *devices, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "lvm_set_filter");
    return FALSE;
  }

  int ret = guestfs_lvm_set_filter(g, devices);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return FALSE;
  }

  return TRUE;
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
 */
gboolean
guestfs_session_lvm_clear_filter(GuestfsSession *session, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "lvm_clear_filter");
    return FALSE;
  }

  int ret = guestfs_lvm_clear_filter(g);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
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
 * This creates a new block device called "/dev/mapper/mapname". Reads and
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
 */
gboolean
guestfs_session_luks_open(GuestfsSession *session, const gchar *device, const gchar *key, const gchar *mapname, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "luks_open");
    return FALSE;
  }

  int ret = guestfs_luks_open(g, device, key, mapname);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
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
 */
gboolean
guestfs_session_luks_open_ro(GuestfsSession *session, const gchar *device, const gchar *key, const gchar *mapname, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "luks_open_ro");
    return FALSE;
  }

  int ret = guestfs_luks_open_ro(g, device, key, mapname);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
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
 * "/dev/mapper/mapname") and *not* the name of the underlying block
 * device.
 * 
 * Returns: true on success, false on error
 */
gboolean
guestfs_session_luks_close(GuestfsSession *session, const gchar *device, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "luks_close");
    return FALSE;
  }

  int ret = guestfs_luks_close(g, device);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
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
 */
gboolean
guestfs_session_luks_format(GuestfsSession *session, const gchar *device, const gchar *key, gint32 keyslot, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "luks_format");
    return FALSE;
  }

  int ret = guestfs_luks_format(g, device, key, keyslot);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
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
 */
gboolean
guestfs_session_luks_format_cipher(GuestfsSession *session, const gchar *device, const gchar *key, gint32 keyslot, const gchar *cipher, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "luks_format_cipher");
    return FALSE;
  }

  int ret = guestfs_luks_format_cipher(g, device, key, keyslot, cipher);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return FALSE;
  }

  return TRUE;
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
 */
gboolean
guestfs_session_luks_add_key(GuestfsSession *session, const gchar *device, const gchar *key, const gchar *newkey, gint32 keyslot, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "luks_add_key");
    return FALSE;
  }

  int ret = guestfs_luks_add_key(g, device, key, newkey, keyslot);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
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
 */
gboolean
guestfs_session_luks_kill_slot(GuestfsSession *session, const gchar *device, const gchar *key, gint32 keyslot, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "luks_kill_slot");
    return FALSE;
  }

  int ret = guestfs_luks_kill_slot(g, device, key, keyslot);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return FALSE;
  }

  return TRUE;
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
 */
gint8
guestfs_session_is_lv(GuestfsSession *session, const gchar *device, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "is_lv");
    return -1;
  }

  int ret = guestfs_is_lv(g, device);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return -1;
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
 */
gchar *
guestfs_session_findfs_uuid(GuestfsSession *session, const gchar *uuid, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "findfs_uuid");
    return NULL;
  }

  char *ret = guestfs_findfs_uuid(g, uuid);
  if (ret == NULL) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return NULL;
  }

  return ret;
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
 */
gchar *
guestfs_session_findfs_label(GuestfsSession *session, const gchar *label, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "findfs_label");
    return NULL;
  }

  char *ret = guestfs_findfs_label(g, label);
  if (ret == NULL) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return NULL;
  }

  return ret;
}

/**
 * guestfs_session_is_chardev:
 * @session: (transfer none): A GuestfsSession object
 * @path: (transfer none) (type filename):
 * @err: A GError object to receive any generated errors
 *
 * test if character device
 *
 * This returns @true if and only if there is a character device with the
 * given @path name.
 * 
 * See also guestfs_session_stat().
 * 
 * Returns: the returned value, or -1 on error
 */
gint8
guestfs_session_is_chardev(GuestfsSession *session, const gchar *path, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "is_chardev");
    return -1;
  }

  int ret = guestfs_is_chardev(g, path);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return -1;
  }

  return ret;
}

/**
 * guestfs_session_is_blockdev:
 * @session: (transfer none): A GuestfsSession object
 * @path: (transfer none) (type filename):
 * @err: A GError object to receive any generated errors
 *
 * test if block device
 *
 * This returns @true if and only if there is a block device with the given
 * @path name.
 * 
 * See also guestfs_session_stat().
 * 
 * Returns: the returned value, or -1 on error
 */
gint8
guestfs_session_is_blockdev(GuestfsSession *session, const gchar *path, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "is_blockdev");
    return -1;
  }

  int ret = guestfs_is_blockdev(g, path);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return -1;
  }

  return ret;
}

/**
 * guestfs_session_is_fifo:
 * @session: (transfer none): A GuestfsSession object
 * @path: (transfer none) (type filename):
 * @err: A GError object to receive any generated errors
 *
 * test if FIFO (named pipe)
 *
 * This returns @true if and only if there is a FIFO (named pipe) with the
 * given @path name.
 * 
 * See also guestfs_session_stat().
 * 
 * Returns: the returned value, or -1 on error
 */
gint8
guestfs_session_is_fifo(GuestfsSession *session, const gchar *path, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "is_fifo");
    return -1;
  }

  int ret = guestfs_is_fifo(g, path);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
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
 */
gint8
guestfs_session_is_symlink(GuestfsSession *session, const gchar *path, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "is_symlink");
    return -1;
  }

  int ret = guestfs_is_symlink(g, path);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return -1;
  }

  return ret;
}

/**
 * guestfs_session_is_socket:
 * @session: (transfer none): A GuestfsSession object
 * @path: (transfer none) (type filename):
 * @err: A GError object to receive any generated errors
 *
 * test if socket
 *
 * This returns @true if and only if there is a Unix domain socket with the
 * given @path name.
 * 
 * See also guestfs_session_stat().
 * 
 * Returns: the returned value, or -1 on error
 */
gint8
guestfs_session_is_socket(GuestfsSession *session, const gchar *path, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "is_socket");
    return -1;
  }

  int ret = guestfs_is_socket(g, path);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return -1;
  }

  return ret;
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
 * See also guestfs_session_part_to_partnum().
 * 
 * Returns: (transfer full): the returned string, or NULL on error
 */
gchar *
guestfs_session_part_to_dev(GuestfsSession *session, const gchar *partition, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "part_to_dev");
    return NULL;
  }

  char *ret = guestfs_part_to_dev(g, partition);
  if (ret == NULL) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return NULL;
  }

  return ret;
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
 * Upload local file @filename to @remotefilename on the filesystem.
 * 
 * @remotefilename is overwritten starting at the byte @offset specified.
 * The intention is to overwrite parts of existing files or devices,
 * although if a non-existant file is specified then it is created with a
 * "hole" before @offset. The size of the data written is implicit in the
 * size of the source @filename.
 * 
 * Note that there is no limit on the amount of data that can be uploaded
 * with this call, unlike with guestfs_session_pwrite(), and this call
 * always writes the full amount unless an error occurs.
 * 
 * See also guestfs_session_upload(), guestfs_session_pwrite().
 * 
 * Returns: true on success, false on error
 */
gboolean
guestfs_session_upload_offset(GuestfsSession *session, const gchar *filename, const gchar *remotefilename, gint64 offset, GCancellable *cancellable, GError **err)
{
  /* Check we haven't already been cancelled */
  if (g_cancellable_set_error_if_cancelled (cancellable, err))
    return FALSE;

  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "upload_offset");
    return FALSE;
  }

  gulong id = 0;
  if (cancellable) {
    id = g_cancellable_connect(cancellable,
                               G_CALLBACK(cancelled_handler),
                               g, NULL);
  }

  int ret = guestfs_upload_offset(g, filename, remotefilename, offset);
  g_cancellable_disconnect(cancellable, id);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
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
 * Download file @remotefilename and save it as @filename on the local
 * machine.
 * 
 * @remotefilename is read for @size bytes starting at @offset (this region
 * must be within the file or device).
 * 
 * Note that there is no limit on the amount of data that can be downloaded
 * with this call, unlike with guestfs_session_pread(), and this call
 * always reads the full amount unless an error occurs.
 * 
 * See also guestfs_session_download(), guestfs_session_pread().
 * 
 * Returns: true on success, false on error
 */
gboolean
guestfs_session_download_offset(GuestfsSession *session, const gchar *remotefilename, const gchar *filename, gint64 offset, gint64 size, GCancellable *cancellable, GError **err)
{
  /* Check we haven't already been cancelled */
  if (g_cancellable_set_error_if_cancelled (cancellable, err))
    return FALSE;

  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "download_offset");
    return FALSE;
  }

  gulong id = 0;
  if (cancellable) {
    id = g_cancellable_connect(cancellable,
                               G_CALLBACK(cancelled_handler),
                               g, NULL);
  }

  int ret = guestfs_download_offset(g, remotefilename, filename, offset, size);
  g_cancellable_disconnect(cancellable, id);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return FALSE;
  }

  return TRUE;
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
 */
gint32
guestfs_session_pwrite_device(GuestfsSession *session, const gchar *device, const guint8 *content, gsize content_size, gint64 offset, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "pwrite_device");
    return -1;
  }

  int ret = guestfs_pwrite_device(g, device, content, content_size, offset);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return -1;
  }

  return ret;
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
 * This command lets you read part of a file. It reads @count bytes of
 * @device, starting at @offset.
 * 
 * This may read fewer bytes than requested. For further details see the
 * pread(2) system call.
 * 
 * See also guestfs_session_pread().
 * 
 * Returns: (transfer full) (array length=size_r) (element-type guint8): an array of binary data, or NULL on error
 */
guint8 *
guestfs_session_pread_device(GuestfsSession *session, const gchar *device, gint32 count, gint64 offset, gsize *size_r, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "pread_device");
    return NULL;
  }

  char *ret = guestfs_pread_device(g, device, count, offset, size_r);
  if (ret == NULL) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return NULL;
  }

  return ret;
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
 * the canonical name. For example, "/dev/mapper/VG-LV" is converted to
 * "/dev/VG/LV".
 * 
 * This command returns an error if the @lvname parameter does not refer to
 * a logical volume.
 * 
 * See also guestfs_session_is_lv().
 * 
 * Returns: (transfer full): the returned string, or NULL on error
 */
gchar *
guestfs_session_lvm_canonical_lv_name(GuestfsSession *session, const gchar *lvname, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "lvm_canonical_lv_name");
    return NULL;
  }

  char *ret = guestfs_lvm_canonical_lv_name(g, lvname);
  if (ret == NULL) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return NULL;
  }

  return ret;
}

/**
 * guestfs_session_mkfs_opts:
 * @session: (transfer none): A GuestfsSession object
 * @fstype: (transfer none) (type utf8):
 * @device: (transfer none) (type filename):
 * @optargs: (transfer none) (allow-none): a GuestfsMkfsOpts containing optional arguments
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
 */
gboolean
guestfs_session_mkfs_opts(GuestfsSession *session, const gchar *fstype, const gchar *device, GuestfsMkfsOpts *optargs, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "mkfs_opts");
    return FALSE;
  }

  struct guestfs_mkfs_opts_argv argv;
  struct guestfs_mkfs_opts_argv *argvp = NULL;

  if (optargs) {
    argv.bitmask = 0;

    GValue blocksize_v = {0, };
    g_value_init(&blocksize_v, G_TYPE_INT);
    g_object_get_property(G_OBJECT(optargs), "blocksize", &blocksize_v);
    gint32 blocksize = g_value_get_int(&blocksize_v);
    if (blocksize != -1) {
      argv.bitmask |= GUESTFS_MKFS_OPTS_BLOCKSIZE_BITMASK;
      argv.blocksize = blocksize;
    }
    GValue features_v = {0, };
    g_value_init(&features_v, G_TYPE_STRING);
    g_object_get_property(G_OBJECT(optargs), "features", &features_v);
    const gchar *features = g_value_get_string(&features_v);
    if (features != NULL) {
      argv.bitmask |= GUESTFS_MKFS_OPTS_FEATURES_BITMASK;
      argv.features = features;
    }
    GValue inode_v = {0, };
    g_value_init(&inode_v, G_TYPE_INT);
    g_object_get_property(G_OBJECT(optargs), "inode", &inode_v);
    gint32 inode = g_value_get_int(&inode_v);
    if (inode != -1) {
      argv.bitmask |= GUESTFS_MKFS_OPTS_INODE_BITMASK;
      argv.inode = inode;
    }
    GValue sectorsize_v = {0, };
    g_value_init(&sectorsize_v, G_TYPE_INT);
    g_object_get_property(G_OBJECT(optargs), "sectorsize", &sectorsize_v);
    gint32 sectorsize = g_value_get_int(&sectorsize_v);
    if (sectorsize != -1) {
      argv.bitmask |= GUESTFS_MKFS_OPTS_SECTORSIZE_BITMASK;
      argv.sectorsize = sectorsize;
    }
    argvp = &argv;
  }
  int ret = guestfs_mkfs_opts_argv(g, fstype, device, argvp);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return FALSE;
  }

  return TRUE;
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
 */
guint8 *
guestfs_session_getxattr(GuestfsSession *session, const gchar *path, const gchar *name, gsize *size_r, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "getxattr");
    return NULL;
  }

  char *ret = guestfs_getxattr(g, path, name, size_r);
  if (ret == NULL) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
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
 */
guint8 *
guestfs_session_lgetxattr(GuestfsSession *session, const gchar *path, const gchar *name, gsize *size_r, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "lgetxattr");
    return NULL;
  }

  char *ret = guestfs_lgetxattr(g, path, name, size_r);
  if (ret == NULL) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return NULL;
  }

  return ret;
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
 */
gboolean
guestfs_session_resize2fs_M(GuestfsSession *session, const gchar *device, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "resize2fs_M");
    return FALSE;
  }

  int ret = guestfs_resize2fs_M(g, device);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return FALSE;
  }

  return TRUE;
}

/**
 * guestfs_session_internal_autosync:
 * @session: (transfer none): A GuestfsSession object
 * @err: A GError object to receive any generated errors
 *
 * internal autosync operation
 *
 * This command performs the autosync operation just before the handle is
 * closed. You should not call this command directly. Instead, use the
 * autosync flag (guestfs_session_set_autosync()) to control whether or not
 * this operation is performed when the handle is closed.
 * 
 * Returns: true on success, false on error
 */
gboolean
guestfs_session_internal_autosync(GuestfsSession *session, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "internal_autosync");
    return FALSE;
  }

  int ret = guestfs_internal_autosync(g);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return FALSE;
  }

  return TRUE;
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
 */
gint8
guestfs_session_is_zero(GuestfsSession *session, const gchar *path, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "is_zero");
    return -1;
  }

  int ret = guestfs_is_zero(g, path);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
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
 */
gint8
guestfs_session_is_zero_device(GuestfsSession *session, const gchar *device, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "is_zero_device");
    return -1;
  }

  int ret = guestfs_is_zero_device(g, device);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return -1;
  }

  return ret;
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
 */
gchar **
guestfs_session_list_9p(GuestfsSession *session, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "list_9p");
    return NULL;
  }

  char **ret = guestfs_list_9p(g);
  if (ret == NULL) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return NULL;
  }

  return ret;
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
 */
gboolean
guestfs_session_mount_9p(GuestfsSession *session, const gchar *mounttag, const gchar *mountpoint, GuestfsMount9P *optargs, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "mount_9p");
    return FALSE;
  }

  struct guestfs_mount_9p_argv argv;
  struct guestfs_mount_9p_argv *argvp = NULL;

  if (optargs) {
    argv.bitmask = 0;

    GValue options_v = {0, };
    g_value_init(&options_v, G_TYPE_STRING);
    g_object_get_property(G_OBJECT(optargs), "options", &options_v);
    const gchar *options = g_value_get_string(&options_v);
    if (options != NULL) {
      argv.bitmask |= GUESTFS_MOUNT_9P_OPTIONS_BITMASK;
      argv.options = options;
    }
    argvp = &argv;
  }
  int ret = guestfs_mount_9p_argv(g, mounttag, mountpoint, argvp);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return FALSE;
  }

  return TRUE;
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
 * The returned list contains "/dev/mapper/*" devices, eg. ones created by
 * a previous call to guestfs_session_luks_open().
 * 
 * Device mapper devices which correspond to logical volumes are *not*
 * returned in this list. Call guestfs_session_lvs() if you want to list
 * logical volumes.
 * 
 * Returns: (transfer full) (array zero-terminated=1) (element-type utf8): an array of returned strings, or NULL on error
 */
gchar **
guestfs_session_list_dm_devices(GuestfsSession *session, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "list_dm_devices");
    return NULL;
  }

  char **ret = guestfs_list_dm_devices(g);
  if (ret == NULL) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return NULL;
  }

  return ret;
}

/**
 * guestfs_session_ntfsresize_opts:
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
 * guestfs_session_ntfsresize_opts() multiple times on a single
 * filesystem without booting into Windows between each resize.
 * 
 * See also ntfsresize(8).
 * 
 * Returns: true on success, false on error
 */
gboolean
guestfs_session_ntfsresize_opts(GuestfsSession *session, const gchar *device, GuestfsNTFSResizeOpts *optargs, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "ntfsresize_opts");
    return FALSE;
  }

  struct guestfs_ntfsresize_opts_argv argv;
  struct guestfs_ntfsresize_opts_argv *argvp = NULL;

  if (optargs) {
    argv.bitmask = 0;

    GValue size_v = {0, };
    g_value_init(&size_v, G_TYPE_INT64);
    g_object_get_property(G_OBJECT(optargs), "size", &size_v);
    gint64 size = g_value_get_int64(&size_v);
    if (size != -1) {
      argv.bitmask |= GUESTFS_NTFSRESIZE_OPTS_SIZE_BITMASK;
      argv.size = size;
    }
    GValue force_v = {0, };
    g_value_init(&force_v, GUESTFS_TYPE_TRISTATE);
    g_object_get_property(G_OBJECT(optargs), "force", &force_v);
    GuestfsTristate force = g_value_get_enum(&force_v);
    if (force != GUESTFS_TRISTATE_NONE) {
      argv.bitmask |= GUESTFS_NTFSRESIZE_OPTS_FORCE_BITMASK;
      argv.force = force;
    }
    argvp = &argv;
  }
  int ret = guestfs_ntfsresize_opts_argv(g, device, argvp);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
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
 */
gboolean
guestfs_session_btrfs_filesystem_resize(GuestfsSession *session, const gchar *mountpoint, GuestfsBTRFSFilesystemResize *optargs, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "btrfs_filesystem_resize");
    return FALSE;
  }

  struct guestfs_btrfs_filesystem_resize_argv argv;
  struct guestfs_btrfs_filesystem_resize_argv *argvp = NULL;

  if (optargs) {
    argv.bitmask = 0;

    GValue size_v = {0, };
    g_value_init(&size_v, G_TYPE_INT64);
    g_object_get_property(G_OBJECT(optargs), "size", &size_v);
    gint64 size = g_value_get_int64(&size_v);
    if (size != -1) {
      argv.bitmask |= GUESTFS_BTRFS_FILESYSTEM_RESIZE_SIZE_BITMASK;
      argv.size = size;
    }
    argvp = &argv;
  }
  int ret = guestfs_btrfs_filesystem_resize_argv(g, mountpoint, argvp);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
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
 */
gboolean
guestfs_session_write_append(GuestfsSession *session, const gchar *path, const guint8 *content, gsize content_size, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "write_append");
    return FALSE;
  }

  int ret = guestfs_write_append(g, path, content, content_size);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
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
 * This command compresses @file and writes it out to the local file
 * @zfile.
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
 */
gboolean
guestfs_session_compress_out(GuestfsSession *session, const gchar *ctype, const gchar *file, const gchar *zfile, GuestfsCompressOut *optargs, GCancellable *cancellable, GError **err)
{
  /* Check we haven't already been cancelled */
  if (g_cancellable_set_error_if_cancelled (cancellable, err))
    return FALSE;

  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "compress_out");
    return FALSE;
  }

  struct guestfs_compress_out_argv argv;
  struct guestfs_compress_out_argv *argvp = NULL;

  if (optargs) {
    argv.bitmask = 0;

    GValue level_v = {0, };
    g_value_init(&level_v, G_TYPE_INT);
    g_object_get_property(G_OBJECT(optargs), "level", &level_v);
    gint32 level = g_value_get_int(&level_v);
    if (level != -1) {
      argv.bitmask |= GUESTFS_COMPRESS_OUT_LEVEL_BITMASK;
      argv.level = level;
    }
    argvp = &argv;
  }
  gulong id = 0;
  if (cancellable) {
    id = g_cancellable_connect(cancellable,
                               G_CALLBACK(cancelled_handler),
                               g, NULL);
  }

  int ret = guestfs_compress_out_argv(g, ctype, file, zfile, argvp);
  g_cancellable_disconnect(cancellable, id);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return FALSE;
  }

  return TRUE;
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
 */
gboolean
guestfs_session_compress_device_out(GuestfsSession *session, const gchar *ctype, const gchar *device, const gchar *zdevice, GuestfsCompressDeviceOut *optargs, GCancellable *cancellable, GError **err)
{
  /* Check we haven't already been cancelled */
  if (g_cancellable_set_error_if_cancelled (cancellable, err))
    return FALSE;

  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "compress_device_out");
    return FALSE;
  }

  struct guestfs_compress_device_out_argv argv;
  struct guestfs_compress_device_out_argv *argvp = NULL;

  if (optargs) {
    argv.bitmask = 0;

    GValue level_v = {0, };
    g_value_init(&level_v, G_TYPE_INT);
    g_object_get_property(G_OBJECT(optargs), "level", &level_v);
    gint32 level = g_value_get_int(&level_v);
    if (level != -1) {
      argv.bitmask |= GUESTFS_COMPRESS_DEVICE_OUT_LEVEL_BITMASK;
      argv.level = level;
    }
    argvp = &argv;
  }
  gulong id = 0;
  if (cancellable) {
    id = g_cancellable_connect(cancellable,
                               G_CALLBACK(cancelled_handler),
                               g, NULL);
  }

  int ret = guestfs_compress_device_out_argv(g, ctype, device, zdevice, argvp);
  g_cancellable_disconnect(cancellable, id);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return FALSE;
  }

  return TRUE;
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
 */
gint32
guestfs_session_part_to_partnum(GuestfsSession *session, const gchar *partition, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "part_to_partnum");
    return -1;
  }

  int ret = guestfs_part_to_partnum(g, partition);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return -1;
  }

  return ret;
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
 * Returns: true on success, false on error
 */
gboolean
guestfs_session_copy_device_to_device(GuestfsSession *session, const gchar *src, const gchar *dest, GuestfsCopyDeviceToDevice *optargs, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "copy_device_to_device");
    return FALSE;
  }

  struct guestfs_copy_device_to_device_argv argv;
  struct guestfs_copy_device_to_device_argv *argvp = NULL;

  if (optargs) {
    argv.bitmask = 0;

    GValue srcoffset_v = {0, };
    g_value_init(&srcoffset_v, G_TYPE_INT64);
    g_object_get_property(G_OBJECT(optargs), "srcoffset", &srcoffset_v);
    gint64 srcoffset = g_value_get_int64(&srcoffset_v);
    if (srcoffset != -1) {
      argv.bitmask |= GUESTFS_COPY_DEVICE_TO_DEVICE_SRCOFFSET_BITMASK;
      argv.srcoffset = srcoffset;
    }
    GValue destoffset_v = {0, };
    g_value_init(&destoffset_v, G_TYPE_INT64);
    g_object_get_property(G_OBJECT(optargs), "destoffset", &destoffset_v);
    gint64 destoffset = g_value_get_int64(&destoffset_v);
    if (destoffset != -1) {
      argv.bitmask |= GUESTFS_COPY_DEVICE_TO_DEVICE_DESTOFFSET_BITMASK;
      argv.destoffset = destoffset;
    }
    GValue size_v = {0, };
    g_value_init(&size_v, G_TYPE_INT64);
    g_object_get_property(G_OBJECT(optargs), "size", &size_v);
    gint64 size = g_value_get_int64(&size_v);
    if (size != -1) {
      argv.bitmask |= GUESTFS_COPY_DEVICE_TO_DEVICE_SIZE_BITMASK;
      argv.size = size;
    }
    argvp = &argv;
  }
  int ret = guestfs_copy_device_to_device_argv(g, src, dest, argvp);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
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
 */
gboolean
guestfs_session_copy_device_to_file(GuestfsSession *session, const gchar *src, const gchar *dest, GuestfsCopyDeviceToFile *optargs, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "copy_device_to_file");
    return FALSE;
  }

  struct guestfs_copy_device_to_file_argv argv;
  struct guestfs_copy_device_to_file_argv *argvp = NULL;

  if (optargs) {
    argv.bitmask = 0;

    GValue srcoffset_v = {0, };
    g_value_init(&srcoffset_v, G_TYPE_INT64);
    g_object_get_property(G_OBJECT(optargs), "srcoffset", &srcoffset_v);
    gint64 srcoffset = g_value_get_int64(&srcoffset_v);
    if (srcoffset != -1) {
      argv.bitmask |= GUESTFS_COPY_DEVICE_TO_FILE_SRCOFFSET_BITMASK;
      argv.srcoffset = srcoffset;
    }
    GValue destoffset_v = {0, };
    g_value_init(&destoffset_v, G_TYPE_INT64);
    g_object_get_property(G_OBJECT(optargs), "destoffset", &destoffset_v);
    gint64 destoffset = g_value_get_int64(&destoffset_v);
    if (destoffset != -1) {
      argv.bitmask |= GUESTFS_COPY_DEVICE_TO_FILE_DESTOFFSET_BITMASK;
      argv.destoffset = destoffset;
    }
    GValue size_v = {0, };
    g_value_init(&size_v, G_TYPE_INT64);
    g_object_get_property(G_OBJECT(optargs), "size", &size_v);
    gint64 size = g_value_get_int64(&size_v);
    if (size != -1) {
      argv.bitmask |= GUESTFS_COPY_DEVICE_TO_FILE_SIZE_BITMASK;
      argv.size = size;
    }
    argvp = &argv;
  }
  int ret = guestfs_copy_device_to_file_argv(g, src, dest, argvp);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
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
 */
gboolean
guestfs_session_copy_file_to_device(GuestfsSession *session, const gchar *src, const gchar *dest, GuestfsCopyFileToDevice *optargs, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "copy_file_to_device");
    return FALSE;
  }

  struct guestfs_copy_file_to_device_argv argv;
  struct guestfs_copy_file_to_device_argv *argvp = NULL;

  if (optargs) {
    argv.bitmask = 0;

    GValue srcoffset_v = {0, };
    g_value_init(&srcoffset_v, G_TYPE_INT64);
    g_object_get_property(G_OBJECT(optargs), "srcoffset", &srcoffset_v);
    gint64 srcoffset = g_value_get_int64(&srcoffset_v);
    if (srcoffset != -1) {
      argv.bitmask |= GUESTFS_COPY_FILE_TO_DEVICE_SRCOFFSET_BITMASK;
      argv.srcoffset = srcoffset;
    }
    GValue destoffset_v = {0, };
    g_value_init(&destoffset_v, G_TYPE_INT64);
    g_object_get_property(G_OBJECT(optargs), "destoffset", &destoffset_v);
    gint64 destoffset = g_value_get_int64(&destoffset_v);
    if (destoffset != -1) {
      argv.bitmask |= GUESTFS_COPY_FILE_TO_DEVICE_DESTOFFSET_BITMASK;
      argv.destoffset = destoffset;
    }
    GValue size_v = {0, };
    g_value_init(&size_v, G_TYPE_INT64);
    g_object_get_property(G_OBJECT(optargs), "size", &size_v);
    gint64 size = g_value_get_int64(&size_v);
    if (size != -1) {
      argv.bitmask |= GUESTFS_COPY_FILE_TO_DEVICE_SIZE_BITMASK;
      argv.size = size;
    }
    argvp = &argv;
  }
  int ret = guestfs_copy_file_to_device_argv(g, src, dest, argvp);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
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
 */
gboolean
guestfs_session_copy_file_to_file(GuestfsSession *session, const gchar *src, const gchar *dest, GuestfsCopyFileToFile *optargs, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "copy_file_to_file");
    return FALSE;
  }

  struct guestfs_copy_file_to_file_argv argv;
  struct guestfs_copy_file_to_file_argv *argvp = NULL;

  if (optargs) {
    argv.bitmask = 0;

    GValue srcoffset_v = {0, };
    g_value_init(&srcoffset_v, G_TYPE_INT64);
    g_object_get_property(G_OBJECT(optargs), "srcoffset", &srcoffset_v);
    gint64 srcoffset = g_value_get_int64(&srcoffset_v);
    if (srcoffset != -1) {
      argv.bitmask |= GUESTFS_COPY_FILE_TO_FILE_SRCOFFSET_BITMASK;
      argv.srcoffset = srcoffset;
    }
    GValue destoffset_v = {0, };
    g_value_init(&destoffset_v, G_TYPE_INT64);
    g_object_get_property(G_OBJECT(optargs), "destoffset", &destoffset_v);
    gint64 destoffset = g_value_get_int64(&destoffset_v);
    if (destoffset != -1) {
      argv.bitmask |= GUESTFS_COPY_FILE_TO_FILE_DESTOFFSET_BITMASK;
      argv.destoffset = destoffset;
    }
    GValue size_v = {0, };
    g_value_init(&size_v, G_TYPE_INT64);
    g_object_get_property(G_OBJECT(optargs), "size", &size_v);
    gint64 size = g_value_get_int64(&size_v);
    if (size != -1) {
      argv.bitmask |= GUESTFS_COPY_FILE_TO_FILE_SIZE_BITMASK;
      argv.size = size;
    }
    argvp = &argv;
  }
  int ret = guestfs_copy_file_to_file_argv(g, src, dest, argvp);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
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
 */
gboolean
guestfs_session_tune2fs(GuestfsSession *session, const gchar *device, GuestfsTune2FS *optargs, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "tune2fs");
    return FALSE;
  }

  struct guestfs_tune2fs_argv argv;
  struct guestfs_tune2fs_argv *argvp = NULL;

  if (optargs) {
    argv.bitmask = 0;

    GValue force_v = {0, };
    g_value_init(&force_v, GUESTFS_TYPE_TRISTATE);
    g_object_get_property(G_OBJECT(optargs), "force", &force_v);
    GuestfsTristate force = g_value_get_enum(&force_v);
    if (force != GUESTFS_TRISTATE_NONE) {
      argv.bitmask |= GUESTFS_TUNE2FS_FORCE_BITMASK;
      argv.force = force;
    }
    GValue maxmountcount_v = {0, };
    g_value_init(&maxmountcount_v, G_TYPE_INT);
    g_object_get_property(G_OBJECT(optargs), "maxmountcount", &maxmountcount_v);
    gint32 maxmountcount = g_value_get_int(&maxmountcount_v);
    if (maxmountcount != -1) {
      argv.bitmask |= GUESTFS_TUNE2FS_MAXMOUNTCOUNT_BITMASK;
      argv.maxmountcount = maxmountcount;
    }
    GValue mountcount_v = {0, };
    g_value_init(&mountcount_v, G_TYPE_INT);
    g_object_get_property(G_OBJECT(optargs), "mountcount", &mountcount_v);
    gint32 mountcount = g_value_get_int(&mountcount_v);
    if (mountcount != -1) {
      argv.bitmask |= GUESTFS_TUNE2FS_MOUNTCOUNT_BITMASK;
      argv.mountcount = mountcount;
    }
    GValue errorbehavior_v = {0, };
    g_value_init(&errorbehavior_v, G_TYPE_STRING);
    g_object_get_property(G_OBJECT(optargs), "errorbehavior", &errorbehavior_v);
    const gchar *errorbehavior = g_value_get_string(&errorbehavior_v);
    if (errorbehavior != NULL) {
      argv.bitmask |= GUESTFS_TUNE2FS_ERRORBEHAVIOR_BITMASK;
      argv.errorbehavior = errorbehavior;
    }
    GValue group_v = {0, };
    g_value_init(&group_v, G_TYPE_INT64);
    g_object_get_property(G_OBJECT(optargs), "group", &group_v);
    gint64 group = g_value_get_int64(&group_v);
    if (group != -1) {
      argv.bitmask |= GUESTFS_TUNE2FS_GROUP_BITMASK;
      argv.group = group;
    }
    GValue intervalbetweenchecks_v = {0, };
    g_value_init(&intervalbetweenchecks_v, G_TYPE_INT);
    g_object_get_property(G_OBJECT(optargs), "intervalbetweenchecks", &intervalbetweenchecks_v);
    gint32 intervalbetweenchecks = g_value_get_int(&intervalbetweenchecks_v);
    if (intervalbetweenchecks != -1) {
      argv.bitmask |= GUESTFS_TUNE2FS_INTERVALBETWEENCHECKS_BITMASK;
      argv.intervalbetweenchecks = intervalbetweenchecks;
    }
    GValue reservedblockspercentage_v = {0, };
    g_value_init(&reservedblockspercentage_v, G_TYPE_INT);
    g_object_get_property(G_OBJECT(optargs), "reservedblockspercentage", &reservedblockspercentage_v);
    gint32 reservedblockspercentage = g_value_get_int(&reservedblockspercentage_v);
    if (reservedblockspercentage != -1) {
      argv.bitmask |= GUESTFS_TUNE2FS_RESERVEDBLOCKSPERCENTAGE_BITMASK;
      argv.reservedblockspercentage = reservedblockspercentage;
    }
    GValue lastmounteddirectory_v = {0, };
    g_value_init(&lastmounteddirectory_v, G_TYPE_STRING);
    g_object_get_property(G_OBJECT(optargs), "lastmounteddirectory", &lastmounteddirectory_v);
    const gchar *lastmounteddirectory = g_value_get_string(&lastmounteddirectory_v);
    if (lastmounteddirectory != NULL) {
      argv.bitmask |= GUESTFS_TUNE2FS_LASTMOUNTEDDIRECTORY_BITMASK;
      argv.lastmounteddirectory = lastmounteddirectory;
    }
    GValue reservedblockscount_v = {0, };
    g_value_init(&reservedblockscount_v, G_TYPE_INT64);
    g_object_get_property(G_OBJECT(optargs), "reservedblockscount", &reservedblockscount_v);
    gint64 reservedblockscount = g_value_get_int64(&reservedblockscount_v);
    if (reservedblockscount != -1) {
      argv.bitmask |= GUESTFS_TUNE2FS_RESERVEDBLOCKSCOUNT_BITMASK;
      argv.reservedblockscount = reservedblockscount;
    }
    GValue user_v = {0, };
    g_value_init(&user_v, G_TYPE_INT64);
    g_object_get_property(G_OBJECT(optargs), "user", &user_v);
    gint64 user = g_value_get_int64(&user_v);
    if (user != -1) {
      argv.bitmask |= GUESTFS_TUNE2FS_USER_BITMASK;
      argv.user = user;
    }
    argvp = &argv;
  }
  int ret = guestfs_tune2fs_argv(g, device, argvp);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return FALSE;
  }

  return TRUE;
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
 */
gboolean
guestfs_session_md_create(GuestfsSession *session, const gchar *name, gchar *const *devices, GuestfsMDCreate *optargs, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "md_create");
    return FALSE;
  }

  struct guestfs_md_create_argv argv;
  struct guestfs_md_create_argv *argvp = NULL;

  if (optargs) {
    argv.bitmask = 0;

    GValue missingbitmap_v = {0, };
    g_value_init(&missingbitmap_v, G_TYPE_INT64);
    g_object_get_property(G_OBJECT(optargs), "missingbitmap", &missingbitmap_v);
    gint64 missingbitmap = g_value_get_int64(&missingbitmap_v);
    if (missingbitmap != -1) {
      argv.bitmask |= GUESTFS_MD_CREATE_MISSINGBITMAP_BITMASK;
      argv.missingbitmap = missingbitmap;
    }
    GValue nrdevices_v = {0, };
    g_value_init(&nrdevices_v, G_TYPE_INT);
    g_object_get_property(G_OBJECT(optargs), "nrdevices", &nrdevices_v);
    gint32 nrdevices = g_value_get_int(&nrdevices_v);
    if (nrdevices != -1) {
      argv.bitmask |= GUESTFS_MD_CREATE_NRDEVICES_BITMASK;
      argv.nrdevices = nrdevices;
    }
    GValue spare_v = {0, };
    g_value_init(&spare_v, G_TYPE_INT);
    g_object_get_property(G_OBJECT(optargs), "spare", &spare_v);
    gint32 spare = g_value_get_int(&spare_v);
    if (spare != -1) {
      argv.bitmask |= GUESTFS_MD_CREATE_SPARE_BITMASK;
      argv.spare = spare;
    }
    GValue chunk_v = {0, };
    g_value_init(&chunk_v, G_TYPE_INT64);
    g_object_get_property(G_OBJECT(optargs), "chunk", &chunk_v);
    gint64 chunk = g_value_get_int64(&chunk_v);
    if (chunk != -1) {
      argv.bitmask |= GUESTFS_MD_CREATE_CHUNK_BITMASK;
      argv.chunk = chunk;
    }
    GValue level_v = {0, };
    g_value_init(&level_v, G_TYPE_STRING);
    g_object_get_property(G_OBJECT(optargs), "level", &level_v);
    const gchar *level = g_value_get_string(&level_v);
    if (level != NULL) {
      argv.bitmask |= GUESTFS_MD_CREATE_LEVEL_BITMASK;
      argv.level = level;
    }
    argvp = &argv;
  }
  int ret = guestfs_md_create_argv(g, name, devices, argvp);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return FALSE;
  }

  return TRUE;
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
 */
gchar **
guestfs_session_list_md_devices(GuestfsSession *session, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "list_md_devices");
    return NULL;
  }

  char **ret = guestfs_list_md_devices(g);
  if (ret == NULL) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return NULL;
  }

  return ret;
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
 */
GHashTable *
guestfs_session_md_detail(GuestfsSession *session, const gchar *md, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "md_detail");
    return NULL;
  }

  char **ret = guestfs_md_detail(g, md);
  if (ret == NULL) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return NULL;
  }

  GHashTable *h = g_hash_table_new_full(g_str_hash, g_str_equal, g_free, g_free);
  char **i = ret;
  while (*i) {
    char *key = *i; i++;
    char *value = *i; i++;
    g_hash_table_insert(h, key, value);
  };
  g_free(ret);
  return h;
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
 */
gboolean
guestfs_session_md_stop(GuestfsSession *session, const gchar *md, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "md_stop");
    return FALSE;
  }

  int ret = guestfs_md_stop(g, md);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return FALSE;
  }

  return TRUE;
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
 */
GHashTable *
guestfs_session_blkid(GuestfsSession *session, const gchar *device, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "blkid");
    return NULL;
  }

  char **ret = guestfs_blkid(g, device);
  if (ret == NULL) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return NULL;
  }

  GHashTable *h = g_hash_table_new_full(g_str_hash, g_str_equal, g_free, g_free);
  char **i = ret;
  while (*i) {
    char *key = *i; i++;
    char *value = *i; i++;
    g_hash_table_insert(h, key, value);
  };
  g_free(ret);
  return h;
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
 */
gboolean
guestfs_session_e2fsck(GuestfsSession *session, const gchar *device, GuestfsE2fsck *optargs, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "e2fsck");
    return FALSE;
  }

  struct guestfs_e2fsck_argv argv;
  struct guestfs_e2fsck_argv *argvp = NULL;

  if (optargs) {
    argv.bitmask = 0;

    GValue correct_v = {0, };
    g_value_init(&correct_v, GUESTFS_TYPE_TRISTATE);
    g_object_get_property(G_OBJECT(optargs), "correct", &correct_v);
    GuestfsTristate correct = g_value_get_enum(&correct_v);
    if (correct != GUESTFS_TRISTATE_NONE) {
      argv.bitmask |= GUESTFS_E2FSCK_CORRECT_BITMASK;
      argv.correct = correct;
    }
    GValue forceall_v = {0, };
    g_value_init(&forceall_v, GUESTFS_TYPE_TRISTATE);
    g_object_get_property(G_OBJECT(optargs), "forceall", &forceall_v);
    GuestfsTristate forceall = g_value_get_enum(&forceall_v);
    if (forceall != GUESTFS_TRISTATE_NONE) {
      argv.bitmask |= GUESTFS_E2FSCK_FORCEALL_BITMASK;
      argv.forceall = forceall;
    }
    argvp = &argv;
  }
  int ret = guestfs_e2fsck_argv(g, device, argvp);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return FALSE;
  }

  return TRUE;
}

/**
 * guestfs_session_llz:
 * @session: (transfer none): A GuestfsSession object
 * @directory: (transfer none) (type filename):
 * @err: A GError object to receive any generated errors
 *
 * list the files in a directory (long format with SELinux contexts)
 *
 * List the files in @directory in the format of 'ls -laZ'.
 * 
 * This command is mostly useful for interactive sessions. It is *not*
 * intended that you try to parse the output string.
 * 
 * Returns: (transfer full): the returned string, or NULL on error
 */
gchar *
guestfs_session_llz(GuestfsSession *session, const gchar *directory, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "llz");
    return NULL;
  }

  char *ret = guestfs_llz(g, directory);
  if (ret == NULL) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return NULL;
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
 */
gboolean
guestfs_session_wipefs(GuestfsSession *session, const gchar *device, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "wipefs");
    return FALSE;
  }

  int ret = guestfs_wipefs(g, device);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
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
 */
gboolean
guestfs_session_ntfsfix(GuestfsSession *session, const gchar *device, GuestfsNtfsfix *optargs, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "ntfsfix");
    return FALSE;
  }

  struct guestfs_ntfsfix_argv argv;
  struct guestfs_ntfsfix_argv *argvp = NULL;

  if (optargs) {
    argv.bitmask = 0;

    GValue clearbadsectors_v = {0, };
    g_value_init(&clearbadsectors_v, GUESTFS_TYPE_TRISTATE);
    g_object_get_property(G_OBJECT(optargs), "clearbadsectors", &clearbadsectors_v);
    GuestfsTristate clearbadsectors = g_value_get_enum(&clearbadsectors_v);
    if (clearbadsectors != GUESTFS_TRISTATE_NONE) {
      argv.bitmask |= GUESTFS_NTFSFIX_CLEARBADSECTORS_BITMASK;
      argv.clearbadsectors = clearbadsectors;
    }
    argvp = &argv;
  }
  int ret = guestfs_ntfsfix_argv(g, device, argvp);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
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
 */
gboolean
guestfs_session_ntfsclone_out(GuestfsSession *session, const gchar *device, const gchar *backupfile, GuestfsNtfscloneOut *optargs, GCancellable *cancellable, GError **err)
{
  /* Check we haven't already been cancelled */
  if (g_cancellable_set_error_if_cancelled (cancellable, err))
    return FALSE;

  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "ntfsclone_out");
    return FALSE;
  }

  struct guestfs_ntfsclone_out_argv argv;
  struct guestfs_ntfsclone_out_argv *argvp = NULL;

  if (optargs) {
    argv.bitmask = 0;

    GValue metadataonly_v = {0, };
    g_value_init(&metadataonly_v, GUESTFS_TYPE_TRISTATE);
    g_object_get_property(G_OBJECT(optargs), "metadataonly", &metadataonly_v);
    GuestfsTristate metadataonly = g_value_get_enum(&metadataonly_v);
    if (metadataonly != GUESTFS_TRISTATE_NONE) {
      argv.bitmask |= GUESTFS_NTFSCLONE_OUT_METADATAONLY_BITMASK;
      argv.metadataonly = metadataonly;
    }
    GValue rescue_v = {0, };
    g_value_init(&rescue_v, GUESTFS_TYPE_TRISTATE);
    g_object_get_property(G_OBJECT(optargs), "rescue", &rescue_v);
    GuestfsTristate rescue = g_value_get_enum(&rescue_v);
    if (rescue != GUESTFS_TRISTATE_NONE) {
      argv.bitmask |= GUESTFS_NTFSCLONE_OUT_RESCUE_BITMASK;
      argv.rescue = rescue;
    }
    GValue ignorefscheck_v = {0, };
    g_value_init(&ignorefscheck_v, GUESTFS_TYPE_TRISTATE);
    g_object_get_property(G_OBJECT(optargs), "ignorefscheck", &ignorefscheck_v);
    GuestfsTristate ignorefscheck = g_value_get_enum(&ignorefscheck_v);
    if (ignorefscheck != GUESTFS_TRISTATE_NONE) {
      argv.bitmask |= GUESTFS_NTFSCLONE_OUT_IGNOREFSCHECK_BITMASK;
      argv.ignorefscheck = ignorefscheck;
    }
    GValue preservetimestamps_v = {0, };
    g_value_init(&preservetimestamps_v, GUESTFS_TYPE_TRISTATE);
    g_object_get_property(G_OBJECT(optargs), "preservetimestamps", &preservetimestamps_v);
    GuestfsTristate preservetimestamps = g_value_get_enum(&preservetimestamps_v);
    if (preservetimestamps != GUESTFS_TRISTATE_NONE) {
      argv.bitmask |= GUESTFS_NTFSCLONE_OUT_PRESERVETIMESTAMPS_BITMASK;
      argv.preservetimestamps = preservetimestamps;
    }
    GValue force_v = {0, };
    g_value_init(&force_v, GUESTFS_TYPE_TRISTATE);
    g_object_get_property(G_OBJECT(optargs), "force", &force_v);
    GuestfsTristate force = g_value_get_enum(&force_v);
    if (force != GUESTFS_TRISTATE_NONE) {
      argv.bitmask |= GUESTFS_NTFSCLONE_OUT_FORCE_BITMASK;
      argv.force = force;
    }
    argvp = &argv;
  }
  gulong id = 0;
  if (cancellable) {
    id = g_cancellable_connect(cancellable,
                               G_CALLBACK(cancelled_handler),
                               g, NULL);
  }

  int ret = guestfs_ntfsclone_out_argv(g, device, backupfile, argvp);
  g_cancellable_disconnect(cancellable, id);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return FALSE;
  }

  return TRUE;
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
 */
gboolean
guestfs_session_ntfsclone_in(GuestfsSession *session, const gchar *backupfile, const gchar *device, GCancellable *cancellable, GError **err)
{
  /* Check we haven't already been cancelled */
  if (g_cancellable_set_error_if_cancelled (cancellable, err))
    return FALSE;

  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "ntfsclone_in");
    return FALSE;
  }

  gulong id = 0;
  if (cancellable) {
    id = g_cancellable_connect(cancellable,
                               G_CALLBACK(cancelled_handler),
                               g, NULL);
  }

  int ret = guestfs_ntfsclone_in(g, backupfile, device);
  g_cancellable_disconnect(cancellable, id);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return FALSE;
  }

  return TRUE;
}

/**
 * guestfs_session_set_label:
 * @session: (transfer none): A GuestfsSession object
 * @device: (transfer none) (type filename):
 * @label: (transfer none) (type utf8):
 * @err: A GError object to receive any generated errors
 *
 * set filesystem label
 *
 * Set the filesystem label on @device to @label.
 * 
 * Only some filesystem types support labels, and libguestfs supports
 * setting labels on only a subset of these.
 * 
 * On ext2/3/4 filesystems, labels are limited to 16 bytes.
 * 
 * On NTFS filesystems, labels are limited to 128 unicode characters.
 * 
 * To read the label on a filesystem, call guestfs_session_vfs_label().
 * 
 * Returns: true on success, false on error
 */
gboolean
guestfs_session_set_label(GuestfsSession *session, const gchar *device, const gchar *label, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "set_label");
    return FALSE;
  }

  int ret = guestfs_set_label(g, device, label);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
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
 * Zero the free space in the filesystem mounted on @directory. The
 * filesystem must be mounted read-write.
 * 
 * The filesystem contents are not affected, but any free space in the
 * filesystem is freed.
 * 
 * In future (but not currently) these zeroed blocks will be "sparsified" -
 * that is, given back to the host.
 * 
 * Returns: true on success, false on error
 */
gboolean
guestfs_session_zero_free_space(GuestfsSession *session, const gchar *directory, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "zero_free_space");
    return FALSE;
  }

  int ret = guestfs_zero_free_space(g, directory);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
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
 * Create an LVM logical volume called "/dev/volgroup/logvol", using
 * approximately @percent % of the free space remaining in the volume
 * group. Most usefully, when @percent is @100 this will create the largest
 * possible LV.
 * 
 * Returns: true on success, false on error
 */
gboolean
guestfs_session_lvcreate_free(GuestfsSession *session, const gchar *logvol, const gchar *volgroup, gint32 percent, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "lvcreate_free");
    return FALSE;
  }

  int ret = guestfs_lvcreate_free(g, logvol, volgroup, percent);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return FALSE;
  }

  return TRUE;
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
 */
GuestfsISOInfo *
guestfs_session_isoinfo_device(GuestfsSession *session, const gchar *device, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "isoinfo_device");
    return NULL;
  }

  struct guestfs_isoinfo *ret = guestfs_isoinfo_device(g, device);
  if (ret == NULL) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return NULL;
  }

  GuestfsISOInfo *s = g_slice_new0(GuestfsISOInfo);
  if (ret->iso_system_id) s->iso_system_id = g_strdup(ret->iso_system_id);
  if (ret->iso_volume_id) s->iso_volume_id = g_strdup(ret->iso_volume_id);
  s->iso_volume_space_size = ret->iso_volume_space_size;
  s->iso_volume_set_size = ret->iso_volume_set_size;
  s->iso_volume_sequence_number = ret->iso_volume_sequence_number;
  s->iso_logical_block_size = ret->iso_logical_block_size;
  if (ret->iso_volume_set_id) s->iso_volume_set_id = g_strdup(ret->iso_volume_set_id);
  if (ret->iso_publisher_id) s->iso_publisher_id = g_strdup(ret->iso_publisher_id);
  if (ret->iso_data_preparer_id) s->iso_data_preparer_id = g_strdup(ret->iso_data_preparer_id);
  if (ret->iso_application_id) s->iso_application_id = g_strdup(ret->iso_application_id);
  if (ret->iso_copyright_file_id) s->iso_copyright_file_id = g_strdup(ret->iso_copyright_file_id);
  if (ret->iso_abstract_file_id) s->iso_abstract_file_id = g_strdup(ret->iso_abstract_file_id);
  if (ret->iso_bibliographic_file_id) s->iso_bibliographic_file_id = g_strdup(ret->iso_bibliographic_file_id);
  s->iso_volume_creation_t = ret->iso_volume_creation_t;
  s->iso_volume_modification_t = ret->iso_volume_modification_t;
  s->iso_volume_expiration_t = ret->iso_volume_expiration_t;
  s->iso_volume_effective_t = ret->iso_volume_effective_t;
  guestfs_free_isoinfo(ret);
  return s;
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
 */
GuestfsISOInfo *
guestfs_session_isoinfo(GuestfsSession *session, const gchar *isofile, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "isoinfo");
    return NULL;
  }

  struct guestfs_isoinfo *ret = guestfs_isoinfo(g, isofile);
  if (ret == NULL) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return NULL;
  }

  GuestfsISOInfo *s = g_slice_new0(GuestfsISOInfo);
  if (ret->iso_system_id) s->iso_system_id = g_strdup(ret->iso_system_id);
  if (ret->iso_volume_id) s->iso_volume_id = g_strdup(ret->iso_volume_id);
  s->iso_volume_space_size = ret->iso_volume_space_size;
  s->iso_volume_set_size = ret->iso_volume_set_size;
  s->iso_volume_sequence_number = ret->iso_volume_sequence_number;
  s->iso_logical_block_size = ret->iso_logical_block_size;
  if (ret->iso_volume_set_id) s->iso_volume_set_id = g_strdup(ret->iso_volume_set_id);
  if (ret->iso_publisher_id) s->iso_publisher_id = g_strdup(ret->iso_publisher_id);
  if (ret->iso_data_preparer_id) s->iso_data_preparer_id = g_strdup(ret->iso_data_preparer_id);
  if (ret->iso_application_id) s->iso_application_id = g_strdup(ret->iso_application_id);
  if (ret->iso_copyright_file_id) s->iso_copyright_file_id = g_strdup(ret->iso_copyright_file_id);
  if (ret->iso_abstract_file_id) s->iso_abstract_file_id = g_strdup(ret->iso_abstract_file_id);
  if (ret->iso_bibliographic_file_id) s->iso_bibliographic_file_id = g_strdup(ret->iso_bibliographic_file_id);
  s->iso_volume_creation_t = ret->iso_volume_creation_t;
  s->iso_volume_modification_t = ret->iso_volume_modification_t;
  s->iso_volume_expiration_t = ret->iso_volume_expiration_t;
  s->iso_volume_effective_t = ret->iso_volume_effective_t;
  guestfs_free_isoinfo(ret);
  return s;
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
 */
guint8 *
guestfs_session_vgmeta(GuestfsSession *session, const gchar *vgname, gsize *size_r, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "vgmeta");
    return NULL;
  }

  char *ret = guestfs_vgmeta(g, vgname, size_r);
  if (ret == NULL) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return NULL;
  }

  return ret;
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
 */
GuestfsMDStat **
guestfs_session_md_stat(GuestfsSession *session, const gchar *md, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "md_stat");
    return NULL;
  }

  struct guestfs_mdstat_list *ret = guestfs_md_stat(g, md);
  if (ret == NULL) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return NULL;
  }

  GuestfsMDStat **l = g_malloc(sizeof(GuestfsMDStat*) * (ret->len + 1));
  gsize i;
  for (i = 0; i < ret->len; i++) {
    l[i] = g_slice_new0(GuestfsMDStat);
    if (ret->val[i].mdstat_device) l[i]->mdstat_device = g_strdup(ret->val[i].mdstat_device);
    l[i]->mdstat_index = ret->val[i].mdstat_index;
    if (ret->val[i].mdstat_flags) l[i]->mdstat_flags = g_strdup(ret->val[i].mdstat_flags);
  }
  guestfs_free_mdstat_list(ret);
  l[i] = NULL;
  return l;
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
 * To create general filesystems, use guestfs_session_mkfs_opts().
 * 
 * Returns: true on success, false on error
 */
gboolean
guestfs_session_mkfs_btrfs(GuestfsSession *session, gchar *const *devices, GuestfsMkfsBtrfs *optargs, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "mkfs_btrfs");
    return FALSE;
  }

  struct guestfs_mkfs_btrfs_argv argv;
  struct guestfs_mkfs_btrfs_argv *argvp = NULL;

  if (optargs) {
    argv.bitmask = 0;

    GValue allocstart_v = {0, };
    g_value_init(&allocstart_v, G_TYPE_INT64);
    g_object_get_property(G_OBJECT(optargs), "allocstart", &allocstart_v);
    gint64 allocstart = g_value_get_int64(&allocstart_v);
    if (allocstart != -1) {
      argv.bitmask |= GUESTFS_MKFS_BTRFS_ALLOCSTART_BITMASK;
      argv.allocstart = allocstart;
    }
    GValue bytecount_v = {0, };
    g_value_init(&bytecount_v, G_TYPE_INT64);
    g_object_get_property(G_OBJECT(optargs), "bytecount", &bytecount_v);
    gint64 bytecount = g_value_get_int64(&bytecount_v);
    if (bytecount != -1) {
      argv.bitmask |= GUESTFS_MKFS_BTRFS_BYTECOUNT_BITMASK;
      argv.bytecount = bytecount;
    }
    GValue datatype_v = {0, };
    g_value_init(&datatype_v, G_TYPE_STRING);
    g_object_get_property(G_OBJECT(optargs), "datatype", &datatype_v);
    const gchar *datatype = g_value_get_string(&datatype_v);
    if (datatype != NULL) {
      argv.bitmask |= GUESTFS_MKFS_BTRFS_DATATYPE_BITMASK;
      argv.datatype = datatype;
    }
    GValue leafsize_v = {0, };
    g_value_init(&leafsize_v, G_TYPE_INT);
    g_object_get_property(G_OBJECT(optargs), "leafsize", &leafsize_v);
    gint32 leafsize = g_value_get_int(&leafsize_v);
    if (leafsize != -1) {
      argv.bitmask |= GUESTFS_MKFS_BTRFS_LEAFSIZE_BITMASK;
      argv.leafsize = leafsize;
    }
    GValue label_v = {0, };
    g_value_init(&label_v, G_TYPE_STRING);
    g_object_get_property(G_OBJECT(optargs), "label", &label_v);
    const gchar *label = g_value_get_string(&label_v);
    if (label != NULL) {
      argv.bitmask |= GUESTFS_MKFS_BTRFS_LABEL_BITMASK;
      argv.label = label;
    }
    GValue metadata_v = {0, };
    g_value_init(&metadata_v, G_TYPE_STRING);
    g_object_get_property(G_OBJECT(optargs), "metadata", &metadata_v);
    const gchar *metadata = g_value_get_string(&metadata_v);
    if (metadata != NULL) {
      argv.bitmask |= GUESTFS_MKFS_BTRFS_METADATA_BITMASK;
      argv.metadata = metadata;
    }
    GValue nodesize_v = {0, };
    g_value_init(&nodesize_v, G_TYPE_INT);
    g_object_get_property(G_OBJECT(optargs), "nodesize", &nodesize_v);
    gint32 nodesize = g_value_get_int(&nodesize_v);
    if (nodesize != -1) {
      argv.bitmask |= GUESTFS_MKFS_BTRFS_NODESIZE_BITMASK;
      argv.nodesize = nodesize;
    }
    GValue sectorsize_v = {0, };
    g_value_init(&sectorsize_v, G_TYPE_INT);
    g_object_get_property(G_OBJECT(optargs), "sectorsize", &sectorsize_v);
    gint32 sectorsize = g_value_get_int(&sectorsize_v);
    if (sectorsize != -1) {
      argv.bitmask |= GUESTFS_MKFS_BTRFS_SECTORSIZE_BITMASK;
      argv.sectorsize = sectorsize;
    }
    argvp = &argv;
  }
  int ret = guestfs_mkfs_btrfs_argv(g, devices, argvp);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return FALSE;
  }

  return TRUE;
}

/**
 * guestfs_session_get_e2attrs:
 * @session: (transfer none): A GuestfsSession object
 * @file: (transfer none) (type filename):
 * @err: A GError object to receive any generated errors
 *
 * get ext2 file attributes of a file
 *
 * This returns the file attributes associated with @file.
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
 */
gchar *
guestfs_session_get_e2attrs(GuestfsSession *session, const gchar *file, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "get_e2attrs");
    return NULL;
  }

  char *ret = guestfs_get_e2attrs(g, file);
  if (ret == NULL) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return NULL;
  }

  return ret;
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
 * @file.
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
 */
gboolean
guestfs_session_set_e2attrs(GuestfsSession *session, const gchar *file, const gchar *attrs, GuestfsSetE2attrs *optargs, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "set_e2attrs");
    return FALSE;
  }

  struct guestfs_set_e2attrs_argv argv;
  struct guestfs_set_e2attrs_argv *argvp = NULL;

  if (optargs) {
    argv.bitmask = 0;

    GValue clear_v = {0, };
    g_value_init(&clear_v, GUESTFS_TYPE_TRISTATE);
    g_object_get_property(G_OBJECT(optargs), "clear", &clear_v);
    GuestfsTristate clear = g_value_get_enum(&clear_v);
    if (clear != GUESTFS_TRISTATE_NONE) {
      argv.bitmask |= GUESTFS_SET_E2ATTRS_CLEAR_BITMASK;
      argv.clear = clear;
    }
    argvp = &argv;
  }
  int ret = guestfs_set_e2attrs_argv(g, file, attrs, argvp);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return FALSE;
  }

  return TRUE;
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
 */
gint64
guestfs_session_get_e2generation(GuestfsSession *session, const gchar *file, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "get_e2generation");
    return -1;
  }

  int64_t ret = guestfs_get_e2generation(g, file);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return -1;
  }

  return ret;
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
 */
gboolean
guestfs_session_set_e2generation(GuestfsSession *session, const gchar *file, gint64 generation, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "set_e2generation");
    return FALSE;
  }

  int ret = guestfs_set_e2generation(g, file, generation);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return FALSE;
  }

  return TRUE;
}

/**
 * guestfs_session_btrfs_subvolume_snapshot:
 * @session: (transfer none): A GuestfsSession object
 * @source: (transfer none) (type filename):
 * @dest: (transfer none) (type filename):
 * @err: A GError object to receive any generated errors
 *
 * create a writable btrfs snapshot
 *
 * Create a writable snapshot of the btrfs subvolume @source. The @dest
 * argument is the destination directory and the name of the snapshot, in
 * the form "/path/to/dest/name".
 * 
 * Returns: true on success, false on error
 */
gboolean
guestfs_session_btrfs_subvolume_snapshot(GuestfsSession *session, const gchar *source, const gchar *dest, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "btrfs_subvolume_snapshot");
    return FALSE;
  }

  int ret = guestfs_btrfs_subvolume_snapshot(g, source, dest);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
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
 * delete a btrfs snapshot
 *
 * Delete the named btrfs subvolume.
 * 
 * Returns: true on success, false on error
 */
gboolean
guestfs_session_btrfs_subvolume_delete(GuestfsSession *session, const gchar *subvolume, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "btrfs_subvolume_delete");
    return FALSE;
  }

  int ret = guestfs_btrfs_subvolume_delete(g, subvolume);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return FALSE;
  }

  return TRUE;
}

/**
 * guestfs_session_btrfs_subvolume_create:
 * @session: (transfer none): A GuestfsSession object
 * @dest: (transfer none) (type filename):
 * @err: A GError object to receive any generated errors
 *
 * create a btrfs snapshot
 *
 * Create a btrfs subvolume. The @dest argument is the destination
 * directory and the name of the snapshot, in the form
 * "/path/to/dest/name".
 * 
 * Returns: true on success, false on error
 */
gboolean
guestfs_session_btrfs_subvolume_create(GuestfsSession *session, const gchar *dest, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "btrfs_subvolume_create");
    return FALSE;
  }

  int ret = guestfs_btrfs_subvolume_create(g, dest);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return FALSE;
  }

  return TRUE;
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
 */
GuestfsBTRFSSubvolume **
guestfs_session_btrfs_subvolume_list(GuestfsSession *session, const gchar *fs, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "btrfs_subvolume_list");
    return NULL;
  }

  struct guestfs_btrfssubvolume_list *ret = guestfs_btrfs_subvolume_list(g, fs);
  if (ret == NULL) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return NULL;
  }

  GuestfsBTRFSSubvolume **l = g_malloc(sizeof(GuestfsBTRFSSubvolume*) * (ret->len + 1));
  gsize i;
  for (i = 0; i < ret->len; i++) {
    l[i] = g_slice_new0(GuestfsBTRFSSubvolume);
    l[i]->btrfssubvolume_id = ret->val[i].btrfssubvolume_id;
    l[i]->btrfssubvolume_top_level_id = ret->val[i].btrfssubvolume_top_level_id;
    if (ret->val[i].btrfssubvolume_path) l[i]->btrfssubvolume_path = g_strdup(ret->val[i].btrfssubvolume_path);
  }
  guestfs_free_btrfssubvolume_list(ret);
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
 */
gboolean
guestfs_session_btrfs_subvolume_set_default(GuestfsSession *session, gint64 id, const gchar *fs, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "btrfs_subvolume_set_default");
    return FALSE;
  }

  int ret = guestfs_btrfs_subvolume_set_default(g, id, fs);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
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
 */
gboolean
guestfs_session_btrfs_filesystem_sync(GuestfsSession *session, const gchar *fs, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "btrfs_filesystem_sync");
    return FALSE;
  }

  int ret = guestfs_btrfs_filesystem_sync(g, fs);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
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
 */
gboolean
guestfs_session_btrfs_filesystem_balance(GuestfsSession *session, const gchar *fs, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "btrfs_filesystem_balance");
    return FALSE;
  }

  int ret = guestfs_btrfs_filesystem_balance(g, fs);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return FALSE;
  }

  return TRUE;
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
 */
gboolean
guestfs_session_btrfs_device_add(GuestfsSession *session, gchar *const *devices, const gchar *fs, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "btrfs_device_add");
    return FALSE;
  }

  int ret = guestfs_btrfs_device_add(g, devices, fs);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
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
 */
gboolean
guestfs_session_btrfs_device_delete(GuestfsSession *session, gchar *const *devices, const gchar *fs, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "btrfs_device_delete");
    return FALSE;
  }

  int ret = guestfs_btrfs_device_delete(g, devices, fs);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return FALSE;
  }

  return TRUE;
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
 */
gboolean
guestfs_session_btrfs_set_seeding(GuestfsSession *session, const gchar *device, gboolean seeding, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "btrfs_set_seeding");
    return FALSE;
  }

  int ret = guestfs_btrfs_set_seeding(g, device, seeding);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
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
 */
gboolean
guestfs_session_btrfs_fsck(GuestfsSession *session, const gchar *device, GuestfsBtrfsFsck *optargs, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (g == NULL) {
    g_set_error(err, GUESTFS_ERROR, 0,
                "attempt to call %s after the session has been closed",
                "btrfs_fsck");
    return FALSE;
  }

  struct guestfs_btrfs_fsck_argv argv;
  struct guestfs_btrfs_fsck_argv *argvp = NULL;

  if (optargs) {
    argv.bitmask = 0;

    GValue superblock_v = {0, };
    g_value_init(&superblock_v, G_TYPE_INT64);
    g_object_get_property(G_OBJECT(optargs), "superblock", &superblock_v);
    gint64 superblock = g_value_get_int64(&superblock_v);
    if (superblock != -1) {
      argv.bitmask |= GUESTFS_BTRFS_FSCK_SUPERBLOCK_BITMASK;
      argv.superblock = superblock;
    }
    GValue repair_v = {0, };
    g_value_init(&repair_v, GUESTFS_TYPE_TRISTATE);
    g_object_get_property(G_OBJECT(optargs), "repair", &repair_v);
    GuestfsTristate repair = g_value_get_enum(&repair_v);
    if (repair != GUESTFS_TRISTATE_NONE) {
      argv.bitmask |= GUESTFS_BTRFS_FSCK_REPAIR_BITMASK;
      argv.repair = repair;
    }
    argvp = &argv;
  }
  int ret = guestfs_btrfs_fsck_argv(g, device, argvp);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return FALSE;
  }

  return TRUE;
}
