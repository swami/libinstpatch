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
/**
 * SECTION: util
 * @short_description: Utility functions
 * @see_also:
 * @stability: Stable
 */
#include <glib.h>
#include <glib/gstdio.h>
#include <glib-object.h>
#include <errno.h>
#include <string.h>
#include "util.h"
#include "misc.h"
#include "compat.h"
#include "i18n.h"

/* Convenience boolean GValue constants */
GValue *ipatch_util_value_bool_true;
GValue *ipatch_util_value_bool_false;

/**
 * _ipatch_util_init: (skip)
 */
void
_ipatch_util_init(void)
{
    ipatch_util_value_bool_true = g_new0(GValue, 1);
    ipatch_util_value_bool_false = g_new0(GValue, 1);

    g_value_init(ipatch_util_value_bool_true, G_TYPE_BOOLEAN);
    g_value_init(ipatch_util_value_bool_false, G_TYPE_BOOLEAN);

    g_value_set_boolean(ipatch_util_value_bool_true, TRUE);
    g_value_set_boolean(ipatch_util_value_bool_false, FALSE);
}

/**
 * _ipatch_util_deinit
 *
 * Free GValue values
 */
void
_ipatch_util_deinit(void)
{
    g_value_unset(ipatch_util_value_bool_true);
    g_value_unset(ipatch_util_value_bool_false);

    g_free(ipatch_util_value_bool_true);
    g_free(ipatch_util_value_bool_false);
}

/* forward decl: actual hash loop shared by ipatch_util_garray_value_hash()
 * and the deprecated ipatch_util_value_array_hash() further below; used
 * directly here too so this internal dispatch doesn't trigger our own
 * deprecated-function warning */
static guint value_array_hash_raw(GValue *values, guint n_values);

/**
 * ipatch_util_value_hash:
 * @val: GValue to hash
 *
 * Hash a GValue.  The hash value can then be used in a GHashTable for example.
 *
 * Returns: Hash value corresponding to the @val key.
 */
guint
ipatch_util_value_hash(GValue *val)
{
    GValueArray *valarray;
    GType valtype;
    const char *sval;

    /* so we can access a float value as its raw data without gcc bitching */
    union
    {
        gfloat f;
        guint32 i;
    } fval;

    g_return_val_if_fail(G_IS_VALUE(val), 0);

    valtype = G_VALUE_TYPE(val);

    switch(G_TYPE_FUNDAMENTAL(valtype))
    {
    case G_TYPE_CHAR:
        return (g_value_get_char(val));

    case G_TYPE_UCHAR:
        return (g_value_get_uchar(val));

    case G_TYPE_BOOLEAN:
        return (g_value_get_boolean(val));

    case G_TYPE_INT:
        return (g_value_get_int(val));

    case G_TYPE_UINT:
        return (g_value_get_uint(val));

    case G_TYPE_LONG:
        return (g_value_get_long(val));

    case G_TYPE_ULONG:
        return (g_value_get_ulong(val));

    case G_TYPE_INT64:
        return (guint)(g_value_get_int64(val));

    case G_TYPE_UINT64:
        return (guint)(g_value_get_uint64(val));

    case G_TYPE_ENUM:
        return (g_value_get_enum(val));

    case G_TYPE_FLAGS:
        return (g_value_get_flags(val));

    case G_TYPE_FLOAT:
        fval.f = g_value_get_float(val);
        return (fval.i);	/* use the raw float data as hash */

    case G_TYPE_DOUBLE:
        fval.f = (gfloat)g_value_get_double(val);	/* convert double to float */
        return (fval.i);		/* use the raw float data as hash */

    case G_TYPE_STRING:
        sval = g_value_get_string(val);
        return (sval ? g_str_hash(sval) : 0);

    case G_TYPE_POINTER:
        return (GPOINTER_TO_UINT(g_value_get_pointer(val)));

    case G_TYPE_BOXED:
        if(valtype == G_TYPE_VALUE_ARRAY)	/* value array? */
        {
            valarray = g_value_get_boxed(val);
            return valarray ? value_array_hash_raw(valarray->values, valarray->n_values) : 0;
        }
        else
        {
            return (GPOINTER_TO_UINT(g_value_get_boxed(val)));
        }

    case G_TYPE_PARAM:
        return (GPOINTER_TO_UINT(g_value_get_param(val)));

    case G_TYPE_OBJECT:
        return (GPOINTER_TO_UINT(g_value_get_object(val)));

    default:
        g_assert_not_reached();
        return (0);	/* to keep compiler happy */
    }
}

/* actual hash loop, shared by both the GArray-based and deprecated
 * GValueArray-based public entry points below */
static guint
value_array_hash_raw(GValue *values, guint n_values)
{
    guint hashval = 0;
    guint i;

    for(i = 0; i < n_values; i++)
    {
        hashval += ipatch_util_value_hash(&values[i]);
    }

    return (hashval);
}

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
guint
ipatch_util_garray_value_hash(GArray *valarray)
{
    if(!valarray)
    {
        return (0);
    }

    return value_array_hash_raw((GValue *)valarray->data, valarray->len);
}

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
guint
ipatch_util_value_array_hash(GValueArray *valarray)
{
    if(!valarray)
    {
        return (0);
    }

    /* n_values/values are the public fields of GValueArray - same
     * contiguous-GValue layout as a GArray, so we can share the raw loop
     * above without going through any deprecated GValueArray accessors */
    return value_array_hash_raw(valarray->values, valarray->n_values);
}

/**
 * ipatch_util_file_size: (skip)
 * @fname: Path of file to get size of.
 * @err: Location to store error or %NULL
 *
 * Get the size of a file (tired of using stat every time?).
 *
 * Returns: File size.  Will return 0 on error, but @err must be checked if
 *   it is set to determine if an error really occurred.
 */
guint64
ipatch_util_file_size(const char *fname, GError **err)
{
    GStatBuf st;

    g_return_val_if_fail(fname != NULL, 0);
    g_return_val_if_fail(!err || !*err, 0);

    if(g_stat(fname, &st) != 0)
    {
        g_set_error(err, IPATCH_ERROR, IPATCH_ERROR_IO,
                    _("Error stating file '%s': %s"), fname, g_strerror(errno));
        return (0);
    }

    return (st.st_size);
}

/**
 * ipatch_util_abs_filename: (skip)
 * @filename: File name to make absolute
 *
 * Make a file name absolute, if it isn't already.
 *
 * Returns: Newly allocated filename, converted to an absolute filename (if necessary)
 *   or NULL if @filename was NULL
 *
 * Since: 1.1.0
 */
char *
ipatch_util_abs_filename(const char *filename)
{
    char *dirname, *abs_filename;

    if(!filename)
    {
        return (NULL);
    }

    if(g_path_is_absolute(filename))
    {
        return (g_strdup(filename));    // !! caller takes over allocation
    }

    dirname = g_get_current_dir();        // ++ alloc
    abs_filename = g_build_filename(dirname, filename, NULL);
    g_free(dirname);                      // -- free

    return (abs_filename);                // !! caller takes over allocation
}

/**
 * ipatch_util_weakref_destroy: (skip)
 * @value: Slice allocated GWeakRef to destroy
 *
 * A GDestroyNotify function for freeing a slice allocated
 * GWeakRef.
 *
 * Since: 1.1.0
 */
void
ipatch_util_weakref_destroy(gpointer value)
{
    GWeakRef *weakref = value;
    g_weak_ref_clear(weakref);
    g_slice_free(GWeakRef, weakref);
}

/**
 * ipatch_util_strncpy_pad:
 * @dest: Destination buffer of exactly @n bytes
 * @src: Source string to copy (may be %NULL, treated as empty)
 * @n: Size of @dest in bytes
 *
 * Copy up to @n bytes of @src into @dest: like strncpy(dest, src, n),
 * truncating without a trailing NUL if @src is @n bytes or longer, and
 * zero-padding the remainder of @dest if @src is shorter than @n bytes.
 * Used when writing fixed-width name fields into binary file formats
 * (SoundFont, DLS, GigaSampler, Spectralis) where truncation without a
 * trailing NUL is valid/expected once the field is exactly full.
 *
 * Implemented without calling strncpy() directly so this deliberate
 * truncate-and-pad usage doesn't trip GCC's -Wstringop-truncation, which
 * otherwise (correctly, in general, but not for this specific idiom)
 * flags any strncpy() call where the bound equals the destination size.
 *
 * Since: 1.1.1
 */
void
ipatch_util_strncpy_pad(char *dest, const char *src, gsize n)
{
    gsize len;

    g_return_if_fail(dest != NULL);

    if(!src)
    {
        memset(dest, 0, n);
        return;
    }

    len = strlen(src);

    if(len >= n)
    {
        memcpy(dest, src, n);
    }
    else
    {
        memcpy(dest, src, len);
        memset(dest + len, 0, n - len);
    }
}

