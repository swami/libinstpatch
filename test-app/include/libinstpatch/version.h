/*
 * version.h - libInstPatch version information
 *
 * libInstPatch
 * Copyright (C) 1999-2002 Josh Green <jgreen@users.sourceforge.net>
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public License
 * as published by the Free Software Foundation; version 2.1
 * of the License only.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program; if not, see <https://www.gnu.org/licenses/>.
 */
#ifndef __IPATCH_VERSION_H__
#define __IPATCH_VERSION_H__

/**
 * IPATCH_VERSION: (skip)
 * libInstPatch version static string.
 */
#define IPATCH_VERSION       "1.1.7"

/**
 * IPATCH_VERSION_MAJOR: (skip)
 * libInstPatch major version integer.
 */
#define IPATCH_VERSION_MAJOR 1

/**
 * IPATCH_VERSION_MINOR: (skip)
 * libInstPatch minor version integer.
 */
#define IPATCH_VERSION_MINOR 1

/**
 * IPATCH_VERSION_MICRO: (skip)
 * libInstPatch micro version integer.
 */
#define IPATCH_VERSION_MICRO 7

void ipatch_version (guint *major, guint *minor, guint *micro);

#endif /* __IPATCH_VERSION_H__ */
