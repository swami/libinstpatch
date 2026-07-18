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
 * SECTION: IpatchVirtualContainer
 * @short_description: Virtual container object
 * @see_also:
 * @stability: Stable
 *
 * Virtual containers are used in user interfaces to group items in
 * containers that aren't actually present in the hierarchy, such as
 * "Instruments", "Melodic Presets", "Percussion Presets" in SF2 files.
 */
#include <stdio.h>
#include <glib.h>
#include <glib-object.h>
#include "IpatchVirtualContainer.h"
#include "IpatchTypeProp.h"

G_DEFINE_ABSTRACT_TYPE(IpatchVirtualContainer, ipatch_virtual_container, IPATCH_TYPE_ITEM)

static void
ipatch_virtual_container_init(IpatchVirtualContainer *container)
{
}

static void
ipatch_virtual_container_class_init(IpatchVirtualContainerClass *klass)
{
}
