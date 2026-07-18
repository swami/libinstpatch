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
 * SECTION: IpatchSF2PZone
 * @short_description: SoundFont preset zone object
 * @see_also: #IpatchSF2Preset, #IpatchSF2Inst
 * @stability: Stable
 *
 * Preset zones are children to #IpatchSF2Preset objects and define how
 * offset generators (effect parameters) for their referenced #IpatchSF2Inst.
 */
#include <stdarg.h>
#include <string.h>
#include <glib.h>
#include <glib-object.h>
#include "IpatchSF2PZone.h"
#include "IpatchSF2Zone.h"
#include "IpatchSF2GenItem.h"
#include "IpatchTypeProp.h"
#include "ipatch_priv.h"

enum
{
    /* generator IDs are used for lower numbers */
    PROP_LINK_ITEM = IPATCH_SF2_GEN_ITEM_FIRST_PROP_USER_ID
};

static void ipatch_sf2_pzone_gen_item_iface_init
(gpointer g_iface, gpointer iface_data);
static void ipatch_sf2_pzone_set_property(GObject *object,
        guint property_id,
        const GValue *value,
        GParamSpec *pspec);
static void ipatch_sf2_pzone_get_property(GObject *object,
        guint property_id, GValue *value,
        GParamSpec *pspec);

/* For passing data from class init to gen item interface init */
static GParamSpec **gen_item_specs = NULL;
static GParamSpec **gen_item_setspecs = NULL;

G_DEFINE_TYPE_WITH_CODE(IpatchSF2PZone, ipatch_sf2_pzone, IPATCH_TYPE_SF2_ZONE,
                        G_IMPLEMENT_INTERFACE(IPATCH_TYPE_SF2_GEN_ITEM,
                                              ipatch_sf2_pzone_gen_item_iface_init))

/* gen item interface initialization */
static void
ipatch_sf2_pzone_gen_item_iface_init(gpointer g_iface, gpointer iface_data)
{
    IpatchSF2GenItemIface *genitem_iface = (IpatchSF2GenItemIface *)g_iface;
    (void)iface_data;

    genitem_iface->genarray_ofs = G_STRUCT_OFFSET(IpatchSF2Zone, genarray);
    genitem_iface->propstype = IPATCH_SF2_GEN_PROPS_PRESET;

    g_return_if_fail(gen_item_specs != NULL);
    g_return_if_fail(gen_item_setspecs != NULL);

    memcpy(&genitem_iface->specs, gen_item_specs, sizeof(genitem_iface->specs));
    memcpy(&genitem_iface->setspecs, gen_item_setspecs, sizeof(genitem_iface->setspecs));
    g_free(gen_item_specs);
    g_free(gen_item_setspecs);
}

static void
ipatch_sf2_pzone_class_init(IpatchSF2PZoneClass *klass)
{
    GObjectClass *obj_class = G_OBJECT_CLASS(klass);
    IpatchItemClass *item_class = IPATCH_ITEM_CLASS(klass);

    obj_class->get_property = ipatch_sf2_pzone_get_property;

    item_class->item_set_property = ipatch_sf2_pzone_set_property;

    g_object_class_install_property(obj_class, PROP_LINK_ITEM,
                                    g_param_spec_object("link-item", _("Link item"),
                                            _("Link item"),
                                            IPATCH_TYPE_SF2_INST,
                                            G_PARAM_READWRITE));
    /* install generator properties */
    ipatch_sf2_gen_item_iface_install_properties(obj_class,
            IPATCH_SF2_GEN_PROPS_PRESET,
            &gen_item_specs, &gen_item_setspecs);
}

static void
ipatch_sf2_pzone_set_property(GObject *object, guint property_id,
                              const GValue *value, GParamSpec *pspec)
{
    IpatchSF2PZone *pzone = IPATCH_SF2_PZONE(object);
    IpatchSF2Inst *inst;

    if(property_id == PROP_LINK_ITEM)
    {
        inst = g_value_get_object(value);
        g_return_if_fail(IPATCH_IS_SF2_INST(inst));
        ipatch_sf2_zone_set_link_item_no_notify((IpatchSF2Zone *)pzone,
                                                (IpatchItem *)inst, NULL);
    }
    else if(!ipatch_sf2_gen_item_iface_set_property((IpatchSF2GenItem *)pzone,
            property_id, value))
    {
        G_OBJECT_WARN_INVALID_PROPERTY_ID(object, property_id, pspec);
        return;
    }
}

static void
ipatch_sf2_pzone_get_property(GObject *object, guint property_id,
                              GValue *value, GParamSpec *pspec)
{
    IpatchSF2PZone *pzone = IPATCH_SF2_PZONE(object);

    if(property_id == PROP_LINK_ITEM)
    {
        g_value_take_object(value, ipatch_sf2_zone_get_link_item
                            ((IpatchSF2Zone *)pzone));
    }
    else if(!ipatch_sf2_gen_item_iface_get_property((IpatchSF2GenItem *)pzone,
            property_id, value))
    {
        G_OBJECT_WARN_INVALID_PROPERTY_ID(object, property_id, pspec);
        return;
    }
}

static
void ipatch_sf2_pzone_init(IpatchSF2PZone *pzone)
{
    ipatch_sf2_gen_array_init(&((IpatchSF2Zone *)pzone)->genarray, TRUE, FALSE);
}

/**
 * ipatch_sf2_pzone_new:
 *
 * Create a new SoundFont preset zone object.
 *
 * Returns: New SoundFont preset zone with a reference count of 1. Caller
 * owns the reference and removing it will destroy the item, unless another
 * reference is added (if its parented for example).
 */
IpatchSF2PZone *
ipatch_sf2_pzone_new(void)
{
    return (IPATCH_SF2_PZONE(g_object_new(IPATCH_TYPE_SF2_PZONE, NULL)));
}

/**
 * ipatch_sf2_pzone_first: (skip)
 * @iter: Patch item iterator containing #IpatchSF2PZone items
 *
 * Gets the first item in a preset zone iterator. A convenience
 * wrapper for ipatch_iter_first().
 *
 * Returns: The first preset zone in @iter or %NULL if empty.
 */
IpatchSF2PZone *
ipatch_sf2_pzone_first(IpatchIter *iter)
{
    GObject *obj;
    g_return_val_if_fail(iter != NULL, NULL);

    obj = ipatch_iter_first(iter);

    if(obj)
    {
        return (IPATCH_SF2_PZONE(obj));
    }
    else
    {
        return (NULL);
    }
}

/**
 * ipatch_sf2_pzone_next: (skip)
 * @iter: Patch item iterator containing #IpatchSF2PZone items
 *
 * Gets the next item in a preset zone iterator. A convenience wrapper
 * for ipatch_iter_next().
 *
 * Returns: The next preset zone in @iter or %NULL if at the end of
 *   the list.
 */
IpatchSF2PZone *
ipatch_sf2_pzone_next(IpatchIter *iter)
{
    GObject *obj;
    g_return_val_if_fail(iter != NULL, NULL);

    obj = ipatch_iter_next(iter);

    if(obj)
    {
        return (IPATCH_SF2_PZONE(obj));
    }
    else
    {
        return (NULL);
    }
}

/**
 * ipatch_sf2_pzone_set_inst:
 * @pzone: Preset zone to set referenced instrument of
 * @inst: Instrument to set preset zone's referenced item to
 *
 * Sets the referenced instrument of a preset zone.
 */
void
ipatch_sf2_pzone_set_inst(IpatchSF2PZone *pzone, IpatchSF2Inst *inst)
{
    g_return_if_fail(IPATCH_IS_SF2_PZONE(pzone));
    g_return_if_fail(IPATCH_IS_SF2_INST(inst));

    ipatch_sf2_zone_set_link_item(IPATCH_SF2_ZONE(pzone), IPATCH_ITEM(inst));
}

/**
 * ipatch_sf2_pzone_get_inst:
 * @pzone: Preset zone to get referenced instrument from
 *
 * Gets the referenced instrument from a preset zone.
 * The returned instrument's reference count is incremented and the caller
 * is responsible for unrefing it with g_object_unref().
 *
 * Returns: (transfer full): Preset zone's referenced instrument or %NULL if global
 * zone. Remember to unreference the instrument with g_object_unref() when
 * done with it.
 */
IpatchSF2Inst *
ipatch_sf2_pzone_get_inst(IpatchSF2PZone *pzone)
{
    IpatchItem *item;

    g_return_val_if_fail(IPATCH_IS_SF2_PZONE(pzone), NULL);

    item = ipatch_sf2_zone_get_link_item(IPATCH_SF2_ZONE(pzone));
    return (item ? IPATCH_SF2_INST(item) : NULL);
}
