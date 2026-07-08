/*
 * libInstPatch
 * Copyright (C) 1999-2014 Element Green <element@elementsofsound.org>
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public License
 * as published by the Free Software Foundation; version 2.1
 * of the License only.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program; if not, see <https://www.gnu.org/licenses/>.
 */
#ifndef __IPATCH_UTIL_H__
#define __IPATCH_UTIL_H__

#include <glib.h>
#include <glib-object.h>

extern GValue *ipatch_util_value_bool_true;
extern GValue *ipatch_util_value_bool_false;

/* a pointer to a constant boolean GValue for TRUE or FALSE depending on input
 * value. */
#define IPATCH_UTIL_VALUE_BOOL(b) \
  ((b) ? ipatch_util_value_bool_true : ipatch_util_value_bool_false)

guint ipatch_util_value_hash(GValue *val);

/**
 * ipatch_util_garray_value_hash:
 * @valarray: (element-type GValue): GArray of GValue to hash
 *
 * Hash a #GArray of #GValue elements (as returned by
 * ipatch_item_get_unique_props_array()). The hash value can then be used
 * in a #GHashTable for example.
 *
 * Returns: Hash value corresponding to the sum of all values returned
 * by ipatch_util_value_hash() for each GValue in the array.
 *
 * Since: 1.1.1
 */
guint ipatch_util_garray_value_hash(GArray *valarray);

/**
 * ipatch_util_value_array_hash:
 * @valarray: GValueArray to hash
 *
 * Hash a GValueArray.  The hash value can then be used in a GHashTable for
 * example.
 *
 * Returns: Hash value corresponding to the sum of all values returned
 * by ipatch_util_value_hash() for each GValue in the array.
 *
 * Deprecated: 1.1.1: Use ipatch_util_garray_value_hash() instead, since
 * #GValueArray is deprecated in GLib.
 */
guint ipatch_util_value_array_hash(GValueArray *valarray) G_GNUC_DEPRECATED_FOR(ipatch_util_garray_value_hash);

guint64 ipatch_util_file_size(const char *fname, GError **err);
char *ipatch_util_abs_filename(const char *filename);
void ipatch_util_weakref_destroy(gpointer value);

#endif
