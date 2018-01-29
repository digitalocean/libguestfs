/* libguestfs generated file
 * WARNING: THIS FILE IS GENERATED FROM THE FOLLOWING FILES:
 *          generator/gobject.ml
 *          and from the code in the generator/ subdirectory.
 * ANY CHANGES YOU MAKE TO THIS FILE WILL BE LOST.
 *
 * Copyright (C) 2009-2018 Red Hat Inc.
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
 * SECTION:optargs-mke2fs
 * @short_description: An object encapsulating optional arguments for guestfs_session_mke2fs
 * @include: guestfs-gobject.h
 *
 An object encapsulating optional arguments for guestfs_session_mke2fs
 */

#include <string.h>

#define GUESTFS_MKE2FS_GET_PRIVATE(obj) (G_TYPE_INSTANCE_GET_PRIVATE ((obj), GUESTFS_TYPE_MKE2FS, GuestfsMke2fsPrivate))

struct _GuestfsMke2fsPrivate {
  gint64 blockscount;
  gint64 blocksize;
  gint64 fragsize;
  gint64 blockspergroup;
  gint64 numberofgroups;
  gint64 bytesperinode;
  gint64 inodesize;
  gint64 journalsize;
  gint64 numberofinodes;
  gint64 stridesize;
  gint64 stripewidth;
  gint64 maxonlineresize;
  gint reservedblockspercentage;
  gint mmpupdateinterval;
  gchar *journaldevice;
  gchar *label;
  gchar *lastmounteddir;
  gchar *creatoros;
  gchar *fstype;
  gchar *usagetype;
  gchar *uuid;
  GuestfsTristate forcecreate;
  GuestfsTristate writesbandgrouponly;
  GuestfsTristate lazyitableinit;
  GuestfsTristate lazyjournalinit;
  GuestfsTristate testfs;
  GuestfsTristate discard;
  GuestfsTristate quotatype;
  GuestfsTristate extent;
  GuestfsTristate filetype;
  GuestfsTristate flexbg;
  GuestfsTristate hasjournal;
  GuestfsTristate journaldev;
  GuestfsTristate largefile;
  GuestfsTristate quota;
  GuestfsTristate resizeinode;
  GuestfsTristate sparsesuper;
  GuestfsTristate uninitbg;
};

G_DEFINE_TYPE (GuestfsMke2fs, guestfs_mke2fs, G_TYPE_OBJECT);

enum {
  PROP_GUESTFS_MKE2FS_PROP0,
  PROP_GUESTFS_MKE2FS_BLOCKSCOUNT,
  PROP_GUESTFS_MKE2FS_BLOCKSIZE,
  PROP_GUESTFS_MKE2FS_FRAGSIZE,
  PROP_GUESTFS_MKE2FS_BLOCKSPERGROUP,
  PROP_GUESTFS_MKE2FS_NUMBEROFGROUPS,
  PROP_GUESTFS_MKE2FS_BYTESPERINODE,
  PROP_GUESTFS_MKE2FS_INODESIZE,
  PROP_GUESTFS_MKE2FS_JOURNALSIZE,
  PROP_GUESTFS_MKE2FS_NUMBEROFINODES,
  PROP_GUESTFS_MKE2FS_STRIDESIZE,
  PROP_GUESTFS_MKE2FS_STRIPEWIDTH,
  PROP_GUESTFS_MKE2FS_MAXONLINERESIZE,
  PROP_GUESTFS_MKE2FS_RESERVEDBLOCKSPERCENTAGE,
  PROP_GUESTFS_MKE2FS_MMPUPDATEINTERVAL,
  PROP_GUESTFS_MKE2FS_JOURNALDEVICE,
  PROP_GUESTFS_MKE2FS_LABEL,
  PROP_GUESTFS_MKE2FS_LASTMOUNTEDDIR,
  PROP_GUESTFS_MKE2FS_CREATOROS,
  PROP_GUESTFS_MKE2FS_FSTYPE,
  PROP_GUESTFS_MKE2FS_USAGETYPE,
  PROP_GUESTFS_MKE2FS_UUID,
  PROP_GUESTFS_MKE2FS_FORCECREATE,
  PROP_GUESTFS_MKE2FS_WRITESBANDGROUPONLY,
  PROP_GUESTFS_MKE2FS_LAZYITABLEINIT,
  PROP_GUESTFS_MKE2FS_LAZYJOURNALINIT,
  PROP_GUESTFS_MKE2FS_TESTFS,
  PROP_GUESTFS_MKE2FS_DISCARD,
  PROP_GUESTFS_MKE2FS_QUOTATYPE,
  PROP_GUESTFS_MKE2FS_EXTENT,
  PROP_GUESTFS_MKE2FS_FILETYPE,
  PROP_GUESTFS_MKE2FS_FLEXBG,
  PROP_GUESTFS_MKE2FS_HASJOURNAL,
  PROP_GUESTFS_MKE2FS_JOURNALDEV,
  PROP_GUESTFS_MKE2FS_LARGEFILE,
  PROP_GUESTFS_MKE2FS_QUOTA,
  PROP_GUESTFS_MKE2FS_RESIZEINODE,
  PROP_GUESTFS_MKE2FS_SPARSESUPER,
  PROP_GUESTFS_MKE2FS_UNINITBG
};

static void
guestfs_mke2fs_set_property(GObject *object, guint property_id, const GValue *value, GParamSpec *pspec)
{
  GuestfsMke2fs *self = GUESTFS_MKE2FS (object);
  GuestfsMke2fsPrivate *priv = self->priv;

  switch (property_id) {
    case PROP_GUESTFS_MKE2FS_BLOCKSCOUNT:
      priv->blockscount = g_value_get_int64 (value);
      break;

    case PROP_GUESTFS_MKE2FS_BLOCKSIZE:
      priv->blocksize = g_value_get_int64 (value);
      break;

    case PROP_GUESTFS_MKE2FS_FRAGSIZE:
      priv->fragsize = g_value_get_int64 (value);
      break;

    case PROP_GUESTFS_MKE2FS_BLOCKSPERGROUP:
      priv->blockspergroup = g_value_get_int64 (value);
      break;

    case PROP_GUESTFS_MKE2FS_NUMBEROFGROUPS:
      priv->numberofgroups = g_value_get_int64 (value);
      break;

    case PROP_GUESTFS_MKE2FS_BYTESPERINODE:
      priv->bytesperinode = g_value_get_int64 (value);
      break;

    case PROP_GUESTFS_MKE2FS_INODESIZE:
      priv->inodesize = g_value_get_int64 (value);
      break;

    case PROP_GUESTFS_MKE2FS_JOURNALSIZE:
      priv->journalsize = g_value_get_int64 (value);
      break;

    case PROP_GUESTFS_MKE2FS_NUMBEROFINODES:
      priv->numberofinodes = g_value_get_int64 (value);
      break;

    case PROP_GUESTFS_MKE2FS_STRIDESIZE:
      priv->stridesize = g_value_get_int64 (value);
      break;

    case PROP_GUESTFS_MKE2FS_STRIPEWIDTH:
      priv->stripewidth = g_value_get_int64 (value);
      break;

    case PROP_GUESTFS_MKE2FS_MAXONLINERESIZE:
      priv->maxonlineresize = g_value_get_int64 (value);
      break;

    case PROP_GUESTFS_MKE2FS_RESERVEDBLOCKSPERCENTAGE:
      priv->reservedblockspercentage = g_value_get_int (value);
      break;

    case PROP_GUESTFS_MKE2FS_MMPUPDATEINTERVAL:
      priv->mmpupdateinterval = g_value_get_int (value);
      break;

    case PROP_GUESTFS_MKE2FS_JOURNALDEVICE:
      g_free (priv->journaldevice);
      priv->journaldevice = g_value_dup_string (value);
      break;

    case PROP_GUESTFS_MKE2FS_LABEL:
      g_free (priv->label);
      priv->label = g_value_dup_string (value);
      break;

    case PROP_GUESTFS_MKE2FS_LASTMOUNTEDDIR:
      g_free (priv->lastmounteddir);
      priv->lastmounteddir = g_value_dup_string (value);
      break;

    case PROP_GUESTFS_MKE2FS_CREATOROS:
      g_free (priv->creatoros);
      priv->creatoros = g_value_dup_string (value);
      break;

    case PROP_GUESTFS_MKE2FS_FSTYPE:
      g_free (priv->fstype);
      priv->fstype = g_value_dup_string (value);
      break;

    case PROP_GUESTFS_MKE2FS_USAGETYPE:
      g_free (priv->usagetype);
      priv->usagetype = g_value_dup_string (value);
      break;

    case PROP_GUESTFS_MKE2FS_UUID:
      g_free (priv->uuid);
      priv->uuid = g_value_dup_string (value);
      break;

    case PROP_GUESTFS_MKE2FS_FORCECREATE:
      priv->forcecreate = g_value_get_enum (value);
      break;

    case PROP_GUESTFS_MKE2FS_WRITESBANDGROUPONLY:
      priv->writesbandgrouponly = g_value_get_enum (value);
      break;

    case PROP_GUESTFS_MKE2FS_LAZYITABLEINIT:
      priv->lazyitableinit = g_value_get_enum (value);
      break;

    case PROP_GUESTFS_MKE2FS_LAZYJOURNALINIT:
      priv->lazyjournalinit = g_value_get_enum (value);
      break;

    case PROP_GUESTFS_MKE2FS_TESTFS:
      priv->testfs = g_value_get_enum (value);
      break;

    case PROP_GUESTFS_MKE2FS_DISCARD:
      priv->discard = g_value_get_enum (value);
      break;

    case PROP_GUESTFS_MKE2FS_QUOTATYPE:
      priv->quotatype = g_value_get_enum (value);
      break;

    case PROP_GUESTFS_MKE2FS_EXTENT:
      priv->extent = g_value_get_enum (value);
      break;

    case PROP_GUESTFS_MKE2FS_FILETYPE:
      priv->filetype = g_value_get_enum (value);
      break;

    case PROP_GUESTFS_MKE2FS_FLEXBG:
      priv->flexbg = g_value_get_enum (value);
      break;

    case PROP_GUESTFS_MKE2FS_HASJOURNAL:
      priv->hasjournal = g_value_get_enum (value);
      break;

    case PROP_GUESTFS_MKE2FS_JOURNALDEV:
      priv->journaldev = g_value_get_enum (value);
      break;

    case PROP_GUESTFS_MKE2FS_LARGEFILE:
      priv->largefile = g_value_get_enum (value);
      break;

    case PROP_GUESTFS_MKE2FS_QUOTA:
      priv->quota = g_value_get_enum (value);
      break;

    case PROP_GUESTFS_MKE2FS_RESIZEINODE:
      priv->resizeinode = g_value_get_enum (value);
      break;

    case PROP_GUESTFS_MKE2FS_SPARSESUPER:
      priv->sparsesuper = g_value_get_enum (value);
      break;

    case PROP_GUESTFS_MKE2FS_UNINITBG:
      priv->uninitbg = g_value_get_enum (value);
      break;

    default:
      /* Invalid property */
      G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
  }
}

static void
guestfs_mke2fs_get_property(GObject *object, guint property_id, GValue *value, GParamSpec *pspec)
{
  GuestfsMke2fs *self = GUESTFS_MKE2FS (object);
  GuestfsMke2fsPrivate *priv = self->priv;

  switch (property_id) {
    case PROP_GUESTFS_MKE2FS_BLOCKSCOUNT:
      g_value_set_int64 (value, priv->blockscount);
      break;

    case PROP_GUESTFS_MKE2FS_BLOCKSIZE:
      g_value_set_int64 (value, priv->blocksize);
      break;

    case PROP_GUESTFS_MKE2FS_FRAGSIZE:
      g_value_set_int64 (value, priv->fragsize);
      break;

    case PROP_GUESTFS_MKE2FS_BLOCKSPERGROUP:
      g_value_set_int64 (value, priv->blockspergroup);
      break;

    case PROP_GUESTFS_MKE2FS_NUMBEROFGROUPS:
      g_value_set_int64 (value, priv->numberofgroups);
      break;

    case PROP_GUESTFS_MKE2FS_BYTESPERINODE:
      g_value_set_int64 (value, priv->bytesperinode);
      break;

    case PROP_GUESTFS_MKE2FS_INODESIZE:
      g_value_set_int64 (value, priv->inodesize);
      break;

    case PROP_GUESTFS_MKE2FS_JOURNALSIZE:
      g_value_set_int64 (value, priv->journalsize);
      break;

    case PROP_GUESTFS_MKE2FS_NUMBEROFINODES:
      g_value_set_int64 (value, priv->numberofinodes);
      break;

    case PROP_GUESTFS_MKE2FS_STRIDESIZE:
      g_value_set_int64 (value, priv->stridesize);
      break;

    case PROP_GUESTFS_MKE2FS_STRIPEWIDTH:
      g_value_set_int64 (value, priv->stripewidth);
      break;

    case PROP_GUESTFS_MKE2FS_MAXONLINERESIZE:
      g_value_set_int64 (value, priv->maxonlineresize);
      break;

    case PROP_GUESTFS_MKE2FS_RESERVEDBLOCKSPERCENTAGE:
      g_value_set_int (value, priv->reservedblockspercentage);
      break;

    case PROP_GUESTFS_MKE2FS_MMPUPDATEINTERVAL:
      g_value_set_int (value, priv->mmpupdateinterval);
      break;

    case PROP_GUESTFS_MKE2FS_JOURNALDEVICE:
      g_value_set_string (value, priv->journaldevice);
      break;

    case PROP_GUESTFS_MKE2FS_LABEL:
      g_value_set_string (value, priv->label);
      break;

    case PROP_GUESTFS_MKE2FS_LASTMOUNTEDDIR:
      g_value_set_string (value, priv->lastmounteddir);
      break;

    case PROP_GUESTFS_MKE2FS_CREATOROS:
      g_value_set_string (value, priv->creatoros);
      break;

    case PROP_GUESTFS_MKE2FS_FSTYPE:
      g_value_set_string (value, priv->fstype);
      break;

    case PROP_GUESTFS_MKE2FS_USAGETYPE:
      g_value_set_string (value, priv->usagetype);
      break;

    case PROP_GUESTFS_MKE2FS_UUID:
      g_value_set_string (value, priv->uuid);
      break;

    case PROP_GUESTFS_MKE2FS_FORCECREATE:
      g_value_set_enum (value, priv->forcecreate);
      break;

    case PROP_GUESTFS_MKE2FS_WRITESBANDGROUPONLY:
      g_value_set_enum (value, priv->writesbandgrouponly);
      break;

    case PROP_GUESTFS_MKE2FS_LAZYITABLEINIT:
      g_value_set_enum (value, priv->lazyitableinit);
      break;

    case PROP_GUESTFS_MKE2FS_LAZYJOURNALINIT:
      g_value_set_enum (value, priv->lazyjournalinit);
      break;

    case PROP_GUESTFS_MKE2FS_TESTFS:
      g_value_set_enum (value, priv->testfs);
      break;

    case PROP_GUESTFS_MKE2FS_DISCARD:
      g_value_set_enum (value, priv->discard);
      break;

    case PROP_GUESTFS_MKE2FS_QUOTATYPE:
      g_value_set_enum (value, priv->quotatype);
      break;

    case PROP_GUESTFS_MKE2FS_EXTENT:
      g_value_set_enum (value, priv->extent);
      break;

    case PROP_GUESTFS_MKE2FS_FILETYPE:
      g_value_set_enum (value, priv->filetype);
      break;

    case PROP_GUESTFS_MKE2FS_FLEXBG:
      g_value_set_enum (value, priv->flexbg);
      break;

    case PROP_GUESTFS_MKE2FS_HASJOURNAL:
      g_value_set_enum (value, priv->hasjournal);
      break;

    case PROP_GUESTFS_MKE2FS_JOURNALDEV:
      g_value_set_enum (value, priv->journaldev);
      break;

    case PROP_GUESTFS_MKE2FS_LARGEFILE:
      g_value_set_enum (value, priv->largefile);
      break;

    case PROP_GUESTFS_MKE2FS_QUOTA:
      g_value_set_enum (value, priv->quota);
      break;

    case PROP_GUESTFS_MKE2FS_RESIZEINODE:
      g_value_set_enum (value, priv->resizeinode);
      break;

    case PROP_GUESTFS_MKE2FS_SPARSESUPER:
      g_value_set_enum (value, priv->sparsesuper);
      break;

    case PROP_GUESTFS_MKE2FS_UNINITBG:
      g_value_set_enum (value, priv->uninitbg);
      break;

    default:
      /* Invalid property */
      G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
  }
}

static void
guestfs_mke2fs_finalize (GObject *object)
{
  GuestfsMke2fs *self = GUESTFS_MKE2FS (object);
  GuestfsMke2fsPrivate *priv = self->priv;

  g_free (priv->journaldevice);
  g_free (priv->label);
  g_free (priv->lastmounteddir);
  g_free (priv->creatoros);
  g_free (priv->fstype);
  g_free (priv->usagetype);
  g_free (priv->uuid);
  G_OBJECT_CLASS (guestfs_mke2fs_parent_class)->finalize (object);
}

static void
guestfs_mke2fs_class_init (GuestfsMke2fsClass *klass)
{
  GObjectClass *object_class = G_OBJECT_CLASS (klass);
  object_class->set_property = guestfs_mke2fs_set_property;
  object_class->get_property = guestfs_mke2fs_get_property;

  /**
   * GuestfsMke2fs:blockscount:
   *
   * A 64-bit integer.
   */
  g_object_class_install_property (
    object_class,
    PROP_GUESTFS_MKE2FS_BLOCKSCOUNT,
    g_param_spec_int64 (
      "blockscount",
      "blockscount",
      "A 64-bit integer.",
      G_MININT64, G_MAXINT64, -1,
      G_PARAM_CONSTRUCT | G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS
    )
  );

  /**
   * GuestfsMke2fs:blocksize:
   *
   * A 64-bit integer.
   */
  g_object_class_install_property (
    object_class,
    PROP_GUESTFS_MKE2FS_BLOCKSIZE,
    g_param_spec_int64 (
      "blocksize",
      "blocksize",
      "A 64-bit integer.",
      G_MININT64, G_MAXINT64, -1,
      G_PARAM_CONSTRUCT | G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS
    )
  );

  /**
   * GuestfsMke2fs:fragsize:
   *
   * A 64-bit integer.
   */
  g_object_class_install_property (
    object_class,
    PROP_GUESTFS_MKE2FS_FRAGSIZE,
    g_param_spec_int64 (
      "fragsize",
      "fragsize",
      "A 64-bit integer.",
      G_MININT64, G_MAXINT64, -1,
      G_PARAM_CONSTRUCT | G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS
    )
  );

  /**
   * GuestfsMke2fs:blockspergroup:
   *
   * A 64-bit integer.
   */
  g_object_class_install_property (
    object_class,
    PROP_GUESTFS_MKE2FS_BLOCKSPERGROUP,
    g_param_spec_int64 (
      "blockspergroup",
      "blockspergroup",
      "A 64-bit integer.",
      G_MININT64, G_MAXINT64, -1,
      G_PARAM_CONSTRUCT | G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS
    )
  );

  /**
   * GuestfsMke2fs:numberofgroups:
   *
   * A 64-bit integer.
   */
  g_object_class_install_property (
    object_class,
    PROP_GUESTFS_MKE2FS_NUMBEROFGROUPS,
    g_param_spec_int64 (
      "numberofgroups",
      "numberofgroups",
      "A 64-bit integer.",
      G_MININT64, G_MAXINT64, -1,
      G_PARAM_CONSTRUCT | G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS
    )
  );

  /**
   * GuestfsMke2fs:bytesperinode:
   *
   * A 64-bit integer.
   */
  g_object_class_install_property (
    object_class,
    PROP_GUESTFS_MKE2FS_BYTESPERINODE,
    g_param_spec_int64 (
      "bytesperinode",
      "bytesperinode",
      "A 64-bit integer.",
      G_MININT64, G_MAXINT64, -1,
      G_PARAM_CONSTRUCT | G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS
    )
  );

  /**
   * GuestfsMke2fs:inodesize:
   *
   * A 64-bit integer.
   */
  g_object_class_install_property (
    object_class,
    PROP_GUESTFS_MKE2FS_INODESIZE,
    g_param_spec_int64 (
      "inodesize",
      "inodesize",
      "A 64-bit integer.",
      G_MININT64, G_MAXINT64, -1,
      G_PARAM_CONSTRUCT | G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS
    )
  );

  /**
   * GuestfsMke2fs:journalsize:
   *
   * A 64-bit integer.
   */
  g_object_class_install_property (
    object_class,
    PROP_GUESTFS_MKE2FS_JOURNALSIZE,
    g_param_spec_int64 (
      "journalsize",
      "journalsize",
      "A 64-bit integer.",
      G_MININT64, G_MAXINT64, -1,
      G_PARAM_CONSTRUCT | G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS
    )
  );

  /**
   * GuestfsMke2fs:numberofinodes:
   *
   * A 64-bit integer.
   */
  g_object_class_install_property (
    object_class,
    PROP_GUESTFS_MKE2FS_NUMBEROFINODES,
    g_param_spec_int64 (
      "numberofinodes",
      "numberofinodes",
      "A 64-bit integer.",
      G_MININT64, G_MAXINT64, -1,
      G_PARAM_CONSTRUCT | G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS
    )
  );

  /**
   * GuestfsMke2fs:stridesize:
   *
   * A 64-bit integer.
   */
  g_object_class_install_property (
    object_class,
    PROP_GUESTFS_MKE2FS_STRIDESIZE,
    g_param_spec_int64 (
      "stridesize",
      "stridesize",
      "A 64-bit integer.",
      G_MININT64, G_MAXINT64, -1,
      G_PARAM_CONSTRUCT | G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS
    )
  );

  /**
   * GuestfsMke2fs:stripewidth:
   *
   * A 64-bit integer.
   */
  g_object_class_install_property (
    object_class,
    PROP_GUESTFS_MKE2FS_STRIPEWIDTH,
    g_param_spec_int64 (
      "stripewidth",
      "stripewidth",
      "A 64-bit integer.",
      G_MININT64, G_MAXINT64, -1,
      G_PARAM_CONSTRUCT | G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS
    )
  );

  /**
   * GuestfsMke2fs:maxonlineresize:
   *
   * A 64-bit integer.
   */
  g_object_class_install_property (
    object_class,
    PROP_GUESTFS_MKE2FS_MAXONLINERESIZE,
    g_param_spec_int64 (
      "maxonlineresize",
      "maxonlineresize",
      "A 64-bit integer.",
      G_MININT64, G_MAXINT64, -1,
      G_PARAM_CONSTRUCT | G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS
    )
  );

  /**
   * GuestfsMke2fs:reservedblockspercentage:
   *
   * A 32-bit integer.
   */
  g_object_class_install_property (
    object_class,
    PROP_GUESTFS_MKE2FS_RESERVEDBLOCKSPERCENTAGE,
    g_param_spec_int (
      "reservedblockspercentage",
      "reservedblockspercentage",
      "A 32-bit integer.",
      G_MININT32, G_MAXINT32, -1,
      G_PARAM_CONSTRUCT | G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS
    )
  );

  /**
   * GuestfsMke2fs:mmpupdateinterval:
   *
   * A 32-bit integer.
   */
  g_object_class_install_property (
    object_class,
    PROP_GUESTFS_MKE2FS_MMPUPDATEINTERVAL,
    g_param_spec_int (
      "mmpupdateinterval",
      "mmpupdateinterval",
      "A 32-bit integer.",
      G_MININT32, G_MAXINT32, -1,
      G_PARAM_CONSTRUCT | G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS
    )
  );

  /**
   * GuestfsMke2fs:journaldevice:
   *
   * A string.
   */
  g_object_class_install_property (
    object_class,
    PROP_GUESTFS_MKE2FS_JOURNALDEVICE,
    g_param_spec_string (
      "journaldevice",
      "journaldevice",
      "A string.",
      NULL,
      G_PARAM_CONSTRUCT | G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS
    )
  );

  /**
   * GuestfsMke2fs:label:
   *
   * A string.
   */
  g_object_class_install_property (
    object_class,
    PROP_GUESTFS_MKE2FS_LABEL,
    g_param_spec_string (
      "label",
      "label",
      "A string.",
      NULL,
      G_PARAM_CONSTRUCT | G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS
    )
  );

  /**
   * GuestfsMke2fs:lastmounteddir:
   *
   * A string.
   */
  g_object_class_install_property (
    object_class,
    PROP_GUESTFS_MKE2FS_LASTMOUNTEDDIR,
    g_param_spec_string (
      "lastmounteddir",
      "lastmounteddir",
      "A string.",
      NULL,
      G_PARAM_CONSTRUCT | G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS
    )
  );

  /**
   * GuestfsMke2fs:creatoros:
   *
   * A string.
   */
  g_object_class_install_property (
    object_class,
    PROP_GUESTFS_MKE2FS_CREATOROS,
    g_param_spec_string (
      "creatoros",
      "creatoros",
      "A string.",
      NULL,
      G_PARAM_CONSTRUCT | G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS
    )
  );

  /**
   * GuestfsMke2fs:fstype:
   *
   * A string.
   */
  g_object_class_install_property (
    object_class,
    PROP_GUESTFS_MKE2FS_FSTYPE,
    g_param_spec_string (
      "fstype",
      "fstype",
      "A string.",
      NULL,
      G_PARAM_CONSTRUCT | G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS
    )
  );

  /**
   * GuestfsMke2fs:usagetype:
   *
   * A string.
   */
  g_object_class_install_property (
    object_class,
    PROP_GUESTFS_MKE2FS_USAGETYPE,
    g_param_spec_string (
      "usagetype",
      "usagetype",
      "A string.",
      NULL,
      G_PARAM_CONSTRUCT | G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS
    )
  );

  /**
   * GuestfsMke2fs:uuid:
   *
   * A string.
   */
  g_object_class_install_property (
    object_class,
    PROP_GUESTFS_MKE2FS_UUID,
    g_param_spec_string (
      "uuid",
      "uuid",
      "A string.",
      NULL,
      G_PARAM_CONSTRUCT | G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS
    )
  );

  /**
   * GuestfsMke2fs:forcecreate:
   *
   * A boolean.
   */
  g_object_class_install_property (
    object_class,
    PROP_GUESTFS_MKE2FS_FORCECREATE,
    g_param_spec_enum (
      "forcecreate",
      "forcecreate",
      "A boolean.",
      GUESTFS_TYPE_TRISTATE, GUESTFS_TRISTATE_NONE,
      G_PARAM_CONSTRUCT | G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS
    )
  );

  /**
   * GuestfsMke2fs:writesbandgrouponly:
   *
   * A boolean.
   */
  g_object_class_install_property (
    object_class,
    PROP_GUESTFS_MKE2FS_WRITESBANDGROUPONLY,
    g_param_spec_enum (
      "writesbandgrouponly",
      "writesbandgrouponly",
      "A boolean.",
      GUESTFS_TYPE_TRISTATE, GUESTFS_TRISTATE_NONE,
      G_PARAM_CONSTRUCT | G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS
    )
  );

  /**
   * GuestfsMke2fs:lazyitableinit:
   *
   * A boolean.
   */
  g_object_class_install_property (
    object_class,
    PROP_GUESTFS_MKE2FS_LAZYITABLEINIT,
    g_param_spec_enum (
      "lazyitableinit",
      "lazyitableinit",
      "A boolean.",
      GUESTFS_TYPE_TRISTATE, GUESTFS_TRISTATE_NONE,
      G_PARAM_CONSTRUCT | G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS
    )
  );

  /**
   * GuestfsMke2fs:lazyjournalinit:
   *
   * A boolean.
   */
  g_object_class_install_property (
    object_class,
    PROP_GUESTFS_MKE2FS_LAZYJOURNALINIT,
    g_param_spec_enum (
      "lazyjournalinit",
      "lazyjournalinit",
      "A boolean.",
      GUESTFS_TYPE_TRISTATE, GUESTFS_TRISTATE_NONE,
      G_PARAM_CONSTRUCT | G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS
    )
  );

  /**
   * GuestfsMke2fs:testfs:
   *
   * A boolean.
   */
  g_object_class_install_property (
    object_class,
    PROP_GUESTFS_MKE2FS_TESTFS,
    g_param_spec_enum (
      "testfs",
      "testfs",
      "A boolean.",
      GUESTFS_TYPE_TRISTATE, GUESTFS_TRISTATE_NONE,
      G_PARAM_CONSTRUCT | G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS
    )
  );

  /**
   * GuestfsMke2fs:discard:
   *
   * A boolean.
   */
  g_object_class_install_property (
    object_class,
    PROP_GUESTFS_MKE2FS_DISCARD,
    g_param_spec_enum (
      "discard",
      "discard",
      "A boolean.",
      GUESTFS_TYPE_TRISTATE, GUESTFS_TRISTATE_NONE,
      G_PARAM_CONSTRUCT | G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS
    )
  );

  /**
   * GuestfsMke2fs:quotatype:
   *
   * A boolean.
   */
  g_object_class_install_property (
    object_class,
    PROP_GUESTFS_MKE2FS_QUOTATYPE,
    g_param_spec_enum (
      "quotatype",
      "quotatype",
      "A boolean.",
      GUESTFS_TYPE_TRISTATE, GUESTFS_TRISTATE_NONE,
      G_PARAM_CONSTRUCT | G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS
    )
  );

  /**
   * GuestfsMke2fs:extent:
   *
   * A boolean.
   */
  g_object_class_install_property (
    object_class,
    PROP_GUESTFS_MKE2FS_EXTENT,
    g_param_spec_enum (
      "extent",
      "extent",
      "A boolean.",
      GUESTFS_TYPE_TRISTATE, GUESTFS_TRISTATE_NONE,
      G_PARAM_CONSTRUCT | G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS
    )
  );

  /**
   * GuestfsMke2fs:filetype:
   *
   * A boolean.
   */
  g_object_class_install_property (
    object_class,
    PROP_GUESTFS_MKE2FS_FILETYPE,
    g_param_spec_enum (
      "filetype",
      "filetype",
      "A boolean.",
      GUESTFS_TYPE_TRISTATE, GUESTFS_TRISTATE_NONE,
      G_PARAM_CONSTRUCT | G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS
    )
  );

  /**
   * GuestfsMke2fs:flexbg:
   *
   * A boolean.
   */
  g_object_class_install_property (
    object_class,
    PROP_GUESTFS_MKE2FS_FLEXBG,
    g_param_spec_enum (
      "flexbg",
      "flexbg",
      "A boolean.",
      GUESTFS_TYPE_TRISTATE, GUESTFS_TRISTATE_NONE,
      G_PARAM_CONSTRUCT | G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS
    )
  );

  /**
   * GuestfsMke2fs:hasjournal:
   *
   * A boolean.
   */
  g_object_class_install_property (
    object_class,
    PROP_GUESTFS_MKE2FS_HASJOURNAL,
    g_param_spec_enum (
      "hasjournal",
      "hasjournal",
      "A boolean.",
      GUESTFS_TYPE_TRISTATE, GUESTFS_TRISTATE_NONE,
      G_PARAM_CONSTRUCT | G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS
    )
  );

  /**
   * GuestfsMke2fs:journaldev:
   *
   * A boolean.
   */
  g_object_class_install_property (
    object_class,
    PROP_GUESTFS_MKE2FS_JOURNALDEV,
    g_param_spec_enum (
      "journaldev",
      "journaldev",
      "A boolean.",
      GUESTFS_TYPE_TRISTATE, GUESTFS_TRISTATE_NONE,
      G_PARAM_CONSTRUCT | G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS
    )
  );

  /**
   * GuestfsMke2fs:largefile:
   *
   * A boolean.
   */
  g_object_class_install_property (
    object_class,
    PROP_GUESTFS_MKE2FS_LARGEFILE,
    g_param_spec_enum (
      "largefile",
      "largefile",
      "A boolean.",
      GUESTFS_TYPE_TRISTATE, GUESTFS_TRISTATE_NONE,
      G_PARAM_CONSTRUCT | G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS
    )
  );

  /**
   * GuestfsMke2fs:quota:
   *
   * A boolean.
   */
  g_object_class_install_property (
    object_class,
    PROP_GUESTFS_MKE2FS_QUOTA,
    g_param_spec_enum (
      "quota",
      "quota",
      "A boolean.",
      GUESTFS_TYPE_TRISTATE, GUESTFS_TRISTATE_NONE,
      G_PARAM_CONSTRUCT | G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS
    )
  );

  /**
   * GuestfsMke2fs:resizeinode:
   *
   * A boolean.
   */
  g_object_class_install_property (
    object_class,
    PROP_GUESTFS_MKE2FS_RESIZEINODE,
    g_param_spec_enum (
      "resizeinode",
      "resizeinode",
      "A boolean.",
      GUESTFS_TYPE_TRISTATE, GUESTFS_TRISTATE_NONE,
      G_PARAM_CONSTRUCT | G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS
    )
  );

  /**
   * GuestfsMke2fs:sparsesuper:
   *
   * A boolean.
   */
  g_object_class_install_property (
    object_class,
    PROP_GUESTFS_MKE2FS_SPARSESUPER,
    g_param_spec_enum (
      "sparsesuper",
      "sparsesuper",
      "A boolean.",
      GUESTFS_TYPE_TRISTATE, GUESTFS_TRISTATE_NONE,
      G_PARAM_CONSTRUCT | G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS
    )
  );

  /**
   * GuestfsMke2fs:uninitbg:
   *
   * A boolean.
   */
  g_object_class_install_property (
    object_class,
    PROP_GUESTFS_MKE2FS_UNINITBG,
    g_param_spec_enum (
      "uninitbg",
      "uninitbg",
      "A boolean.",
      GUESTFS_TYPE_TRISTATE, GUESTFS_TRISTATE_NONE,
      G_PARAM_CONSTRUCT | G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS
    )
  );

  object_class->finalize = guestfs_mke2fs_finalize;
  g_type_class_add_private (klass, sizeof (GuestfsMke2fsPrivate));
}

static void
guestfs_mke2fs_init (GuestfsMke2fs *o)
{
  o->priv = GUESTFS_MKE2FS_GET_PRIVATE (o);
  /* XXX: Find out if gobject already zeroes private structs */
  memset (o->priv, 0, sizeof (GuestfsMke2fsPrivate));
}

/**
 * guestfs_mke2fs_new:
 *
 * Create a new GuestfsMke2fs object
 *
 * Returns: (transfer full): a new GuestfsMke2fs object
 */
GuestfsMke2fs *
guestfs_mke2fs_new (void)
{
  return GUESTFS_MKE2FS (g_object_new (GUESTFS_TYPE_MKE2FS, NULL));
}
