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
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA
 * 02110-1301, USA or on the web at http://www.gnu.org.
 */
/* Older glib compatibility functions */

#ifndef __LIBINSTPATCH_COMPAT_H__
#define __LIBINSTPATCH_COMPAT_H__

#include <glib-object.h>

// Enable GWeakRef emulation if glib version less than 2.32
#ifndef GLIB_VERSION_2_32

#define IPATCH_COMPAT_GWEAKREF  1

typedef struct _GWeakRef
{
    gpointer obj;
} GWeakRef;

void g_weak_ref_init(GWeakRef *weak_ref, gpointer object);
void g_weak_ref_clear(GWeakRef *weak_ref);
gpointer g_weak_ref_get(GWeakRef *weak_ref);
void g_weak_ref_set(GWeakRef *weak_ref, gpointer object);

#endif

// Enable g_slist_free_full emulation if glib version less than 2.28
#ifndef GLIB_VERSION_2_28

#define IPATCH_COMPAT_SLIST_FREE_FULL   1

void g_slist_free_full(GSList *list, GDestroyNotify free_func);

#endif

#endif

