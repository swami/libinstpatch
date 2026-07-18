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
/*
 * IpatchConverter_priv.h - Helper macros for defining converters
 */
#ifndef __IPATCH_CONVERTER_PRIV_H__
#define __IPATCH_CONVERTER_PRIV_H__

/**
 * CONVERTER_GET_TYPE: (skip)
 */
#define CONVERTER_GET_TYPE(type_under, TypeCase) \
GType ipatch_converter_ ## type_under ## _get_type (void) \
{ \
  static GType obj_type = 0; \
 \
  if (!obj_type) { \
    static const GTypeInfo obj_info = { \
      sizeof (IpatchConverter ## TypeCase ## Class), NULL, NULL, \
      _ ## type_under ## _class_init, NULL, NULL, \
      sizeof (IpatchConverter ## TypeCase), 0, \
      NULL, NULL, \
    }; \
 \
    obj_type = g_type_register_static (IPATCH_TYPE_CONVERTER, \
				       "IpatchConverter" #TypeCase, \
				       &obj_info, 0); \
  } \
 \
  return (obj_type); \
}

/**
 * CONVERTER_CLASS_INIT: (skip)
 */
#define CONVERTER_CLASS_INIT(type_under) \
static void _ ## type_under ## _class_init (gpointer g_class, gpointer class_data) \
{ \
  IpatchConverterClass *klass = (IpatchConverterClass *) g_class; \
  (void) class_data; \
  klass->verify = NULL; \
  klass->notes = NULL; \
  klass->convert = _ ## type_under ## _convert; \
}

/**
 * CONVERTER_CLASS_INIT_NOTES: (skip)
 */
#define CONVERTER_CLASS_INIT_NOTES(type_under) \
static void _ ## type_under ## _class_init (gpointer g_class, gpointer class_data) \
{ \
  IpatchConverterClass *klass = (IpatchConverterClass *) g_class; \
  (void) class_data; \
  klass->verify = NULL; \
  klass->notes = _ ## type_under ## _notes; \
  klass->convert = _ ## type_under ## _convert; \
}

/**
 * CONVERTER_SF2_VOICE_CACHE_GET_TYPE: (skip)
 */
#define CONVERTER_SF2_VOICE_CACHE_GET_TYPE(type_under, TypeCase) \
GType ipatch_converter_ ## type_under ## _get_type (void) \
{ \
  static GType obj_type = 0; \
 \
  if (!obj_type) { \
    static const GTypeInfo obj_info = { \
      sizeof (IpatchConverter ## TypeCase ## Class), NULL, NULL, \
      _ ## type_under ## _class_init, NULL, NULL, \
      sizeof (IpatchConverter ## TypeCase), 0, \
      NULL, NULL, \
    }; \
 \
    obj_type = g_type_register_static (IPATCH_TYPE_CONVERTER_SF2_VOICE_CACHE, \
				       "IpatchConverter" #TypeCase, \
				       &obj_info, 0); \
  } \
 \
  return (obj_type); \
}

#endif
