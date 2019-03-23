
/*
 builtin_enums.c

 This file contains functions registration of type enumeration (or flags) defined in the
 respectives headers files.
 Typically this file could be generated automatically at make time (with the help
 of glib-mkenums).
 Compiling on Windows: glib-mkenums is a perl script and Perl isn't natively installed.
 To avoid Perl dependency, the file should manually updated. This shouldn't be a problem
 when new enumerations are slowly added over time.
 
 Please respect the naming conventions. This example assumes  an enum definition 
 in a header file:
 typedef enum
 {
  IPATCH_BASE_CHANGED = 1 << 4,
  IPATCH_BASE_SAVED   = 1 << 5)
 } IpatchBaseFlags;

 The name of registration function should be: xxx_get_type, with xxx the enum name (e.g
 word-separated by underscores. (e.g  patch_base_flags_get_type
 When the enum value definitions contain bit-shift operators, this function must call
 g_flags_register_static()otherwise g_enum_register_static() must be called.

 First parameter of g_flags_register_static or g_enum_register_static(type name) must
 be the enum name (e.g "IpatchBaseFlags").
 Second parameter of of g_flags_register_static() must be GFlagsValue table value.
 Second parameter of of g_enum_register_static() must be GFEnumValue table value.
 Each value (GFlagsValue or GFEnumValue) must be {ENUM_VALUE, "VALUE_NAME", "valuenick"}:
 - ENUM_VALUE, the integer value for the enum value.(e.g IPATCH_BASE_CHANGED).
 - VALUE_NAME, name with words uppercase and word-separated by underscores
  (e.g "IPATCH_BASE_CHANGED").
 - valuenick, this is usually stripping common prefix words of all the enum values.
 the words are lowercase and underscores are substituted by a minus (e.g. "changed").
*/

#include "libinstpatch.h"
#include "ipatch_priv.h"

/* enumerations from "IpatchBase.h" */
GType
ipatch_base_flags_get_type (void)
{
  static GType etype = 0;
  if (etype == 0) {
    static const GFlagsValue values[] = {
      { IPATCH_BASE_CHANGED, "IPATCH_BASE_CHANGED", "changed" },
      { IPATCH_BASE_SAVED, "IPATCH_BASE_SAVED", "saved" },
      { 0, NULL, NULL }
    };
    etype = g_flags_register_static ("IpatchBaseFlags", values);
  }
  return etype;
}

/* enumerations from "IpatchConverter.h" */
GType
ipatch_converter_log_type_get_type (void)
{
  static GType etype = 0;
  if (etype == 0) {
    static const GEnumValue values[] = {
      { IPATCH_CONVERTER_LOG_RATING, "IPATCH_CONVERTER_LOG_RATING", "rating" },
      { IPATCH_CONVERTER_LOG_INFO, "IPATCH_CONVERTER_LOG_INFO", "info" },
      { IPATCH_CONVERTER_LOG_WARN, "IPATCH_CONVERTER_LOG_WARN", "warn" },
      { IPATCH_CONVERTER_LOG_CRITICAL, "IPATCH_CONVERTER_LOG_CRITICAL", "critical" },
      { IPATCH_CONVERTER_LOG_FATAL, "IPATCH_CONVERTER_LOG_FATAL", "fatal" },
      { 0, NULL, NULL }
    };
    etype = g_enum_register_static ("IpatchConverterLogType", values);
  }
  return etype;
}
GType
ipatch_converter_count_get_type (void)
{
  static GType etype = 0;
  if (etype == 0) {
    static const GEnumValue values[] = {
      { IPATCH_CONVERTER_COUNT_ONE_OR_MORE, "IPATCH_CONVERTER_COUNT_ONE_OR_MORE", "one-or-more" },
      { IPATCH_CONVERTER_COUNT_ZERO_OR_MORE, "IPATCH_CONVERTER_COUNT_ZERO_OR_MORE", "zero-or-more" },
      { 0, NULL, NULL }
    };
    etype = g_enum_register_static ("IpatchConverterCount", values);
  }
  return etype;
}

GType
ipatch_converter_flags_get_type (void)
{
  static GType etype = 0;
  if (etype == 0) {
    static const GFlagsValue values[] = {
      { IPATCH_CONVERTER_SRC_DERIVED, "IPATCH_CONVERTER_SRC_DERIVED", "derived" },
      { IPATCH_CONVERTER_DEST_DERIVED, "IPATCH_CONVERTER_DEST_DERIVED", "derived" },
      { 0, NULL, NULL }
    };
    etype = g_flags_register_static ("IpatchConverterFlags", values);
  }
  return etype;
}

GType
ipatch_converter_priority_get_type (void)
{
  static GType etype = 0;
  if (etype == 0) {
    static const GEnumValue values[] = {
      { IPATCH_CONVERTER_PRIORITY_LOWEST, "IPATCH_CONVERTER_PRIORITY_LOWEST", "lowest" },
      { IPATCH_CONVERTER_PRIORITY_LOW, "IPATCH_CONVERTER_PRIORITY_LOW", "low" },
      { IPATCH_CONVERTER_PRIORITY_DEFAULT, "IPATCH_CONVERTER_PRIORITY_DEFAULT", "default" },
      { IPATCH_CONVERTER_PRIORITY_HIGH, "IPATCH_CONVERTER_PRIORITY_HIGH", "high" },
      { IPATCH_CONVERTER_PRIORITY_HIGHEST, "IPATCH_CONVERTER_PRIORITY_HIGHEST", "highest" },
      { 0, NULL, NULL }
    };
    etype = g_enum_register_static ("IpatchConverterPriority", values);
  }
  return etype;
}

/* enumerations from "IpatchDLS2Conn.h" */
GType
ipatch_dls2_conn_src_type_get_type (void)
{
  static GType etype = 0;
  if (etype == 0) {
    static const GEnumValue values[] = {
      { IPATCH_DLS2_CONN_SRC_NONE, "IPATCH_DLS2_CONN_SRC_NONE", "none" },
      { IPATCH_DLS2_CONN_SRC_LFO, "IPATCH_DLS2_CONN_SRC_LFO", "lfo" },
      { IPATCH_DLS2_CONN_SRC_VELOCITY, "IPATCH_DLS2_CONN_SRC_VELOCITY", "velocity" },
      { IPATCH_DLS2_CONN_SRC_NOTE, "IPATCH_DLS2_CONN_SRC_NOTE", "note" },
      { IPATCH_DLS2_CONN_SRC_EG1, "IPATCH_DLS2_CONN_SRC_EG1", "eg1" },
      { IPATCH_DLS2_CONN_SRC_EG2, "IPATCH_DLS2_CONN_SRC_EG2", "eg2" },
      { IPATCH_DLS2_CONN_SRC_PITCH_WHEEL, "IPATCH_DLS2_CONN_SRC_PITCH_WHEEL", "pitch-wheel" },
      { IPATCH_DLS2_CONN_SRC_POLY_PRESSURE, "IPATCH_DLS2_CONN_SRC_POLY_PRESSURE", "poly-pressure" },
      { IPATCH_DLS2_CONN_SRC_CHANNEL_PRESSURE, "IPATCH_DLS2_CONN_SRC_CHANNEL_PRESSURE", "channel-pressure" },
      { IPATCH_DLS2_CONN_SRC_VIBRATO, "IPATCH_DLS2_CONN_SRC_VIBRATO", "vibrato" },
      { IPATCH_DLS2_CONN_SRC_CC1, "IPATCH_DLS2_CONN_SRC_CC1", "cc1" },
      { IPATCH_DLS2_CONN_SRC_CC7, "IPATCH_DLS2_CONN_SRC_CC7", "cc7" },
      { IPATCH_DLS2_CONN_SRC_CC10, "IPATCH_DLS2_CONN_SRC_CC10", "cc10" },
      { IPATCH_DLS2_CONN_SRC_CC11, "IPATCH_DLS2_CONN_SRC_CC11", "cc11" },
      { IPATCH_DLS2_CONN_SRC_CC91, "IPATCH_DLS2_CONN_SRC_CC91", "cc91" },
      { IPATCH_DLS2_CONN_SRC_CC93, "IPATCH_DLS2_CONN_SRC_CC93", "cc93" },
      { IPATCH_DLS2_CONN_SRC_RPN0, "IPATCH_DLS2_CONN_SRC_RPN0", "rpn0" },
      { IPATCH_DLS2_CONN_SRC_RPN1, "IPATCH_DLS2_CONN_SRC_RPN1", "rpn1" },
      { IPATCH_DLS2_CONN_SRC_RPN2, "IPATCH_DLS2_CONN_SRC_RPN2", "rpn2" },
      { 0, NULL, NULL }
    };
    etype = g_enum_register_static ("IpatchDLS2ConnSrcType", values);
  }
  return etype;
}
GType
ipatch_dls2_conn_dest_type_get_type (void)
{
  static GType etype = 0;
  if (etype == 0) {
    static const GEnumValue values[] = {
      { IPATCH_DLS2_CONN_DEST_NONE, "IPATCH_DLS2_CONN_DEST_NONE", "none" },
      { IPATCH_DLS2_CONN_DEST_GAIN, "IPATCH_DLS2_CONN_DEST_GAIN", "gain" },
      { IPATCH_DLS2_CONN_DEST_RESERVED, "IPATCH_DLS2_CONN_DEST_RESERVED", "reserved" },
      { IPATCH_DLS2_CONN_DEST_PITCH, "IPATCH_DLS2_CONN_DEST_PITCH", "pitch" },
      { IPATCH_DLS2_CONN_DEST_PAN, "IPATCH_DLS2_CONN_DEST_PAN", "pan" },
      { IPATCH_DLS2_CONN_DEST_NOTE, "IPATCH_DLS2_CONN_DEST_NOTE", "note" },
      { IPATCH_DLS2_CONN_DEST_LEFT, "IPATCH_DLS2_CONN_DEST_LEFT", "left" },
      { IPATCH_DLS2_CONN_DEST_RIGHT, "IPATCH_DLS2_CONN_DEST_RIGHT", "right" },
      { IPATCH_DLS2_CONN_DEST_CENTER, "IPATCH_DLS2_CONN_DEST_CENTER", "center" },
      { IPATCH_DLS2_CONN_DEST_LFE_CHANNEL, "IPATCH_DLS2_CONN_DEST_LFE_CHANNEL", "lfe-channel" },
      { IPATCH_DLS2_CONN_DEST_LEFT_REAR, "IPATCH_DLS2_CONN_DEST_LEFT_REAR", "left-rear" },
      { IPATCH_DLS2_CONN_DEST_RIGHT_REAR, "IPATCH_DLS2_CONN_DEST_RIGHT_REAR", "right-rear" },
      { IPATCH_DLS2_CONN_DEST_CHORUS, "IPATCH_DLS2_CONN_DEST_CHORUS", "chorus" },
      { IPATCH_DLS2_CONN_DEST_REVERB, "IPATCH_DLS2_CONN_DEST_REVERB", "reverb" },
      { IPATCH_DLS2_CONN_DEST_LFO_FREQ, "IPATCH_DLS2_CONN_DEST_LFO_FREQ", "lfo-freq" },
      { IPATCH_DLS2_CONN_DEST_LFO_DELAY, "IPATCH_DLS2_CONN_DEST_LFO_DELAY", "lfo-delay" },
      { IPATCH_DLS2_CONN_DEST_VIB_FREQ, "IPATCH_DLS2_CONN_DEST_VIB_FREQ", "vib-freq" },
      { IPATCH_DLS2_CONN_DEST_VIB_DELAY, "IPATCH_DLS2_CONN_DEST_VIB_DELAY", "vib-delay" },
      { IPATCH_DLS2_CONN_DEST_EG1_ATTACK, "IPATCH_DLS2_CONN_DEST_EG1_ATTACK", "eg1-attack" },
      { IPATCH_DLS2_CONN_DEST_EG1_DECAY, "IPATCH_DLS2_CONN_DEST_EG1_DECAY", "eg1-decay" },
      { IPATCH_DLS2_CONN_DEST_EG1_RESERVED, "IPATCH_DLS2_CONN_DEST_EG1_RESERVED", "eg1-reserved" },
      { IPATCH_DLS2_CONN_DEST_EG1_RELEASE, "IPATCH_DLS2_CONN_DEST_EG1_RELEASE", "eg1-release" },
      { IPATCH_DLS2_CONN_DEST_EG1_SUSTAIN, "IPATCH_DLS2_CONN_DEST_EG1_SUSTAIN", "eg1-sustain" },
      { IPATCH_DLS2_CONN_DEST_EG1_DELAY, "IPATCH_DLS2_CONN_DEST_EG1_DELAY", "eg1-delay" },
      { IPATCH_DLS2_CONN_DEST_EG1_HOLD, "IPATCH_DLS2_CONN_DEST_EG1_HOLD", "eg1-hold" },
      { IPATCH_DLS2_CONN_DEST_EG1_SHUTDOWN, "IPATCH_DLS2_CONN_DEST_EG1_SHUTDOWN", "eg1-shutdown" },
      { IPATCH_DLS2_CONN_DEST_EG2_ATTACK, "IPATCH_DLS2_CONN_DEST_EG2_ATTACK", "eg2-attack" },
      { IPATCH_DLS2_CONN_DEST_EG2_DECAY, "IPATCH_DLS2_CONN_DEST_EG2_DECAY", "eg2-decay" },
      { IPATCH_DLS2_CONN_DEST_EG2_RESERVED, "IPATCH_DLS2_CONN_DEST_EG2_RESERVED", "eg2-reserved" },
      { IPATCH_DLS2_CONN_DEST_EG2_RELEASE, "IPATCH_DLS2_CONN_DEST_EG2_RELEASE", "eg2-release" },
      { IPATCH_DLS2_CONN_DEST_EG2_SUSTAIN, "IPATCH_DLS2_CONN_DEST_EG2_SUSTAIN", "eg2-sustain" },
      { IPATCH_DLS2_CONN_DEST_EG2_DELAY, "IPATCH_DLS2_CONN_DEST_EG2_DELAY", "eg2-delay" },
      { IPATCH_DLS2_CONN_DEST_EG2_HOLD, "IPATCH_DLS2_CONN_DEST_EG2_HOLD", "eg2-hold" },
      { IPATCH_DLS2_CONN_DEST_FILTER_CUTOFF, "IPATCH_DLS2_CONN_DEST_FILTER_CUTOFF", "filter-cutoff" },
      { IPATCH_DLS2_CONN_DEST_FILTER_Q, "IPATCH_DLS2_CONN_DEST_FILTER_Q", "filter-q" },
      { 0, NULL, NULL }
    };
    etype = g_enum_register_static ("IpatchDLS2ConnDestType", values);
  }
  return etype;
}
GType
ipatch_dls2_conn_transform_type_get_type (void)
{
  static GType etype = 0;
  if (etype == 0) {
    static const GEnumValue values[] = {
      { IPATCH_DLS2_CONN_TRANS_LINEAR, "IPATCH_DLS2_CONN_TRANS_LINEAR", "linear" },
      { IPATCH_DLS2_CONN_TRANS_CONCAVE, "IPATCH_DLS2_CONN_TRANS_CONCAVE", "concave" },
      { IPATCH_DLS2_CONN_TRANS_CONVEX, "IPATCH_DLS2_CONN_TRANS_CONVEX", "convex" },
      { IPATCH_DLS2_CONN_TRANS_SWITCH, "IPATCH_DLS2_CONN_TRANS_SWITCH", "switch" },
      { 0, NULL, NULL }
    };
    etype = g_enum_register_static ("IpatchDLS2ConnTransformType", values);
  }
  return etype;
}
GType
ipatch_dls2_conn_polarity_type_get_type (void)
{
  static GType etype = 0;
  if (etype == 0) {
    static const GEnumValue values[] = {
      { IPATCH_DLS2_CONN_POLARITY_UNI, "IPATCH_DLS2_CONN_POLARITY_UNI", "uni" },
      { IPATCH_DLS2_CONN_POLARITY_BI, "IPATCH_DLS2_CONN_POLARITY_BI", "bi" },
      { 0, NULL, NULL }
    };
    etype = g_enum_register_static ("IpatchDLS2ConnPolarityType", values);
  }
  return etype;
}
GType
ipatch_dls2_conn_transform_masks_get_type (void)
{
  static GType etype = 0;
  if (etype == 0) {
    static const GEnumValue values[] = {
      { IPATCH_DLS2_CONN_MASK_OUTPUT_TRANS, "IPATCH_DLS2_CONN_MASK_OUTPUT_TRANS", "output-trans" },
      { IPATCH_DLS2_CONN_MASK_CTRLSRC_TRANS, "IPATCH_DLS2_CONN_MASK_CTRLSRC_TRANS", "ctrlsrc-trans" },
      { IPATCH_DLS2_CONN_MASK_CTRLSRC_POLARITY, "IPATCH_DLS2_CONN_MASK_CTRLSRC_POLARITY", "ctrlsrc-polarity" },
      { IPATCH_DLS2_CONN_MASK_CTRLSRC_INVERT, "IPATCH_DLS2_CONN_MASK_CTRLSRC_INVERT", "ctrlsrc-invert" },
      { IPATCH_DLS2_CONN_MASK_SRC_TRANS, "IPATCH_DLS2_CONN_MASK_SRC_TRANS", "src-trans" },
      { IPATCH_DLS2_CONN_MASK_SRC_POLARITY, "IPATCH_DLS2_CONN_MASK_SRC_POLARITY", "src-polarity" },
      { IPATCH_DLS2_CONN_MASK_SRC_INVERT, "IPATCH_DLS2_CONN_MASK_SRC_INVERT", "src-invert" },
      { 0, NULL, NULL }
    };
    etype = g_enum_register_static ("IpatchDLS2ConnTransformMasks", values);
  }
  return etype;
}
GType
ipatch_dls2_conn_transform_shifts_get_type (void)
{
  static GType etype = 0;
  if (etype == 0) {
    static const GEnumValue values[] = {
      { IPATCH_DLS2_CONN_SHIFT_OUTPUT_TRANS, "IPATCH_DLS2_CONN_SHIFT_OUTPUT_TRANS", "output-trans" },
      { IPATCH_DLS2_CONN_SHIFT_CTRLSRC_TRANS, "IPATCH_DLS2_CONN_SHIFT_CTRLSRC_TRANS", "ctrlsrc-trans" },
      { IPATCH_DLS2_CONN_SHIFT_CTRLSRC_POLARITY, "IPATCH_DLS2_CONN_SHIFT_CTRLSRC_POLARITY", "ctrlsrc-polarity" },
      { IPATCH_DLS2_CONN_SHIFT_CTRLSRC_INVERT, "IPATCH_DLS2_CONN_SHIFT_CTRLSRC_INVERT", "ctrlsrc-invert" },
      { IPATCH_DLS2_CONN_SHIFT_SRC_TRANS, "IPATCH_DLS2_CONN_SHIFT_SRC_TRANS", "src-trans" },
      { IPATCH_DLS2_CONN_SHIFT_SRC_POLARITY, "IPATCH_DLS2_CONN_SHIFT_SRC_POLARITY", "src-polarity" },
      { IPATCH_DLS2_CONN_SHIFT_SRC_INVERT, "IPATCH_DLS2_CONN_SHIFT_SRC_INVERT", "src-invert" },
      { 0, NULL, NULL }
    };
    etype = g_enum_register_static ("IpatchDLS2ConnTransformShifts", values);
  }
  return etype;
}

/* enumerations from "IpatchDLS2.h" */
GType
ipatch_dls2_flags_get_type (void)
{
  static GType etype = 0;
  if (etype == 0) {
    static const GFlagsValue values[] = {
      { IPATCH_DLS2_VERSION_SET, "IPATCH_DLS2_VERSION_SET", "set" },
      { 0, NULL, NULL }
    };
    etype = g_flags_register_static ("IpatchDLS2Flags", values);
  }
  return etype;
}

/* enumerations from "IpatchDLS2Info.h" */
GType
ipatch_dls2_info_type_get_type (void)
{
  static GType etype = 0;
  if (etype == 0) {
    static const GEnumValue values[] = {
      { IPATCH_DLS2_ARCHIVE_LOCATION, "IPATCH_DLS2_ARCHIVE_LOCATION", "archive-location" },
      { IPATCH_DLS2_ARTIST, "IPATCH_DLS2_ARTIST", "artist" },
      { IPATCH_DLS2_COMMISSIONED, "IPATCH_DLS2_COMMISSIONED", "commissioned" },
      { IPATCH_DLS2_COMMENT, "IPATCH_DLS2_COMMENT", "comment" },
      { IPATCH_DLS2_COPYRIGHT, "IPATCH_DLS2_COPYRIGHT", "copyright" },
      { IPATCH_DLS2_DATE, "IPATCH_DLS2_DATE", "date" },
      { IPATCH_DLS2_ENGINEER, "IPATCH_DLS2_ENGINEER", "engineer" },
      { IPATCH_DLS2_GENRE, "IPATCH_DLS2_GENRE", "genre" },
      { IPATCH_DLS2_KEYWORDS, "IPATCH_DLS2_KEYWORDS", "keywords" },
      { IPATCH_DLS2_MEDIUM, "IPATCH_DLS2_MEDIUM", "medium" },
      { IPATCH_DLS2_NAME, "IPATCH_DLS2_NAME", "name" },
      { IPATCH_DLS2_PRODUCT, "IPATCH_DLS2_PRODUCT", "product" },
      { IPATCH_DLS2_SUBJECT, "IPATCH_DLS2_SUBJECT", "subject" },
      { IPATCH_DLS2_SOFTWARE, "IPATCH_DLS2_SOFTWARE", "software" },
      { IPATCH_DLS2_SOURCE, "IPATCH_DLS2_SOURCE", "source" },
      { IPATCH_DLS2_SOURCE_FORM, "IPATCH_DLS2_SOURCE_FORM", "source-form" },
      { IPATCH_DLS2_TECHNICIAN, "IPATCH_DLS2_TECHNICIAN", "technician" },
      { 0, NULL, NULL }
    };
    etype = g_enum_register_static ("IpatchDLS2InfoType", values);
  }
  return etype;
}

/* enumerations from "IpatchDLS2Inst.h" */
GType
ipatch_dls2_inst_flags_get_type (void)
{
  static GType etype = 0;
  if (etype == 0) {
    static const GFlagsValue values[] = {
      { IPATCH_DLS2_INST_PERCUSSION, "IPATCH_DLS2_INST_PERCUSSION", "percussion" },
      { 0, NULL, NULL }
    };
    etype = g_flags_register_static ("IpatchDLS2InstFlags", values);
  }
  return etype;
}

/* enumerations from "IpatchDLS2Region.h" */
GType
ipatch_dls2_param_get_type (void)
{
  static GType etype = 0;
  if (etype == 0) {
    static const GEnumValue values[] = {
      { IPATCH_DLS2_PARAM_MOD_LFO_FREQ, "IPATCH_DLS2_PARAM_MOD_LFO_FREQ", "mod-lfo-freq" },
      { IPATCH_DLS2_PARAM_MOD_LFO_DELAY, "IPATCH_DLS2_PARAM_MOD_LFO_DELAY", "mod-lfo-delay" },
      { IPATCH_DLS2_PARAM_VIB_LFO_FREQ, "IPATCH_DLS2_PARAM_VIB_LFO_FREQ", "vib-lfo-freq" },
      { IPATCH_DLS2_PARAM_VIB_LFO_DELAY, "IPATCH_DLS2_PARAM_VIB_LFO_DELAY", "vib-lfo-delay" },
      { IPATCH_DLS2_PARAM_VOL_EG_DELAY, "IPATCH_DLS2_PARAM_VOL_EG_DELAY", "vol-eg-delay" },
      { IPATCH_DLS2_PARAM_VOL_EG_ATTACK, "IPATCH_DLS2_PARAM_VOL_EG_ATTACK", "vol-eg-attack" },
      { IPATCH_DLS2_PARAM_VOL_EG_HOLD, "IPATCH_DLS2_PARAM_VOL_EG_HOLD", "vol-eg-hold" },
      { IPATCH_DLS2_PARAM_VOL_EG_DECAY, "IPATCH_DLS2_PARAM_VOL_EG_DECAY", "vol-eg-decay" },
      { IPATCH_DLS2_PARAM_VOL_EG_SUSTAIN, "IPATCH_DLS2_PARAM_VOL_EG_SUSTAIN", "vol-eg-sustain" },
      { IPATCH_DLS2_PARAM_VOL_EG_RELEASE, "IPATCH_DLS2_PARAM_VOL_EG_RELEASE", "vol-eg-release" },
      { IPATCH_DLS2_PARAM_VOL_EG_SHUTDOWN, "IPATCH_DLS2_PARAM_VOL_EG_SHUTDOWN", "vol-eg-shutdown" },
      { IPATCH_DLS2_PARAM_VOL_EG_VELOCITY_TO_ATTACK, "IPATCH_DLS2_PARAM_VOL_EG_VELOCITY_TO_ATTACK", "vol-eg-velocity-to-attack" },
      { IPATCH_DLS2_PARAM_VOL_EG_NOTE_TO_DECAY, "IPATCH_DLS2_PARAM_VOL_EG_NOTE_TO_DECAY", "vol-eg-note-to-decay" },
      { IPATCH_DLS2_PARAM_VOL_EG_NOTE_TO_HOLD, "IPATCH_DLS2_PARAM_VOL_EG_NOTE_TO_HOLD", "vol-eg-note-to-hold" },
      { IPATCH_DLS2_PARAM_MOD_EG_DELAY, "IPATCH_DLS2_PARAM_MOD_EG_DELAY", "mod-eg-delay" },
      { IPATCH_DLS2_PARAM_MOD_EG_ATTACK, "IPATCH_DLS2_PARAM_MOD_EG_ATTACK", "mod-eg-attack" },
      { IPATCH_DLS2_PARAM_MOD_EG_HOLD, "IPATCH_DLS2_PARAM_MOD_EG_HOLD", "mod-eg-hold" },
      { IPATCH_DLS2_PARAM_MOD_EG_DECAY, "IPATCH_DLS2_PARAM_MOD_EG_DECAY", "mod-eg-decay" },
      { IPATCH_DLS2_PARAM_MOD_EG_SUSTAIN, "IPATCH_DLS2_PARAM_MOD_EG_SUSTAIN", "mod-eg-sustain" },
      { IPATCH_DLS2_PARAM_MOD_EG_RELEASE, "IPATCH_DLS2_PARAM_MOD_EG_RELEASE", "mod-eg-release" },
      { IPATCH_DLS2_PARAM_MOD_EG_VELOCITY_TO_ATTACK, "IPATCH_DLS2_PARAM_MOD_EG_VELOCITY_TO_ATTACK", "mod-eg-velocity-to-attack" },
      { IPATCH_DLS2_PARAM_MOD_EG_NOTE_TO_DECAY, "IPATCH_DLS2_PARAM_MOD_EG_NOTE_TO_DECAY", "mod-eg-note-to-decay" },
      { IPATCH_DLS2_PARAM_MOD_EG_NOTE_TO_HOLD, "IPATCH_DLS2_PARAM_MOD_EG_NOTE_TO_HOLD", "mod-eg-note-to-hold" },
      { IPATCH_DLS2_PARAM_SCALE_TUNE, "IPATCH_DLS2_PARAM_SCALE_TUNE", "scale-tune" },
      { IPATCH_DLS2_PARAM_RPN2_TO_NOTE, "IPATCH_DLS2_PARAM_RPN2_TO_NOTE", "rpn2-to-note" },
      { IPATCH_DLS2_PARAM_FILTER_CUTOFF, "IPATCH_DLS2_PARAM_FILTER_CUTOFF", "filter-cutoff" },
      { IPATCH_DLS2_PARAM_FILTER_Q, "IPATCH_DLS2_PARAM_FILTER_Q", "filter-q" },
      { IPATCH_DLS2_PARAM_MOD_LFO_TO_FILTER_CUTOFF, "IPATCH_DLS2_PARAM_MOD_LFO_TO_FILTER_CUTOFF", "mod-lfo-to-filter-cutoff" },
      { IPATCH_DLS2_PARAM_MOD_LFO_CC1_TO_FILTER_CUTOFF, "IPATCH_DLS2_PARAM_MOD_LFO_CC1_TO_FILTER_CUTOFF", "mod-lfo-cc1-to-filter-cutoff" },
      { IPATCH_DLS2_PARAM_MOD_LFO_CHANNEL_PRESS_TO_FILTER_CUTOFF, "IPATCH_DLS2_PARAM_MOD_LFO_CHANNEL_PRESS_TO_FILTER_CUTOFF", "mod-lfo-channel-press-to-filter-cutoff" },
      { IPATCH_DLS2_PARAM_MOD_EG_TO_FILTER_CUTOFF, "IPATCH_DLS2_PARAM_MOD_EG_TO_FILTER_CUTOFF", "mod-eg-to-filter-cutoff" },
      { IPATCH_DLS2_PARAM_VELOCITY_TO_FILTER_CUTOFF, "IPATCH_DLS2_PARAM_VELOCITY_TO_FILTER_CUTOFF", "velocity-to-filter-cutoff" },
      { IPATCH_DLS2_PARAM_NOTE_TO_FILTER_CUTOFF, "IPATCH_DLS2_PARAM_NOTE_TO_FILTER_CUTOFF", "note-to-filter-cutoff" },
      { IPATCH_DLS2_PARAM_MOD_LFO_TO_GAIN, "IPATCH_DLS2_PARAM_MOD_LFO_TO_GAIN", "mod-lfo-to-gain" },
      { IPATCH_DLS2_PARAM_MOD_LFO_CC1_TO_GAIN, "IPATCH_DLS2_PARAM_MOD_LFO_CC1_TO_GAIN", "mod-lfo-cc1-to-gain" },
      { IPATCH_DLS2_PARAM_MOD_LFO_CHANNEL_PRESS_TO_GAIN, "IPATCH_DLS2_PARAM_MOD_LFO_CHANNEL_PRESS_TO_GAIN", "mod-lfo-channel-press-to-gain" },
      { IPATCH_DLS2_PARAM_VELOCITY_TO_GAIN, "IPATCH_DLS2_PARAM_VELOCITY_TO_GAIN", "velocity-to-gain" },
      { IPATCH_DLS2_PARAM_CC7_TO_GAIN, "IPATCH_DLS2_PARAM_CC7_TO_GAIN", "cc7-to-gain" },
      { IPATCH_DLS2_PARAM_CC11_TO_GAIN, "IPATCH_DLS2_PARAM_CC11_TO_GAIN", "cc11-to-gain" },
      { IPATCH_DLS2_PARAM_TUNE, "IPATCH_DLS2_PARAM_TUNE", "tune" },
      { IPATCH_DLS2_PARAM_PITCH_WHEEL_RPN0_TO_PITCH, "IPATCH_DLS2_PARAM_PITCH_WHEEL_RPN0_TO_PITCH", "pitch-wheel-rpn0-to-pitch" },
      { IPATCH_DLS2_PARAM_NOTE_NUMBER_TO_PITCH, "IPATCH_DLS2_PARAM_NOTE_NUMBER_TO_PITCH", "note-number-to-pitch" },
      { IPATCH_DLS2_PARAM_RPN1_TO_PITCH, "IPATCH_DLS2_PARAM_RPN1_TO_PITCH", "rpn1-to-pitch" },
      { IPATCH_DLS2_PARAM_VIB_LFO_TO_PITCH, "IPATCH_DLS2_PARAM_VIB_LFO_TO_PITCH", "vib-lfo-to-pitch" },
      { IPATCH_DLS2_PARAM_VIB_LFO_CC1_TO_PITCH, "IPATCH_DLS2_PARAM_VIB_LFO_CC1_TO_PITCH", "vib-lfo-cc1-to-pitch" },
      { IPATCH_DLS2_PARAM_VIB_LFO_CHANNEL_PRESS_TO_PITCH, "IPATCH_DLS2_PARAM_VIB_LFO_CHANNEL_PRESS_TO_PITCH", "vib-lfo-channel-press-to-pitch" },
      { IPATCH_DLS2_PARAM_MOD_LFO_TO_PITCH, "IPATCH_DLS2_PARAM_MOD_LFO_TO_PITCH", "mod-lfo-to-pitch" },
      { IPATCH_DLS2_PARAM_MOD_LFO_CC1_TO_PITCH, "IPATCH_DLS2_PARAM_MOD_LFO_CC1_TO_PITCH", "mod-lfo-cc1-to-pitch" },
      { IPATCH_DLS2_PARAM_MOD_LFO_CHANNEL_PRESS_TO_PITCH, "IPATCH_DLS2_PARAM_MOD_LFO_CHANNEL_PRESS_TO_PITCH", "mod-lfo-channel-press-to-pitch" },
      { IPATCH_DLS2_PARAM_MOD_EG_TO_PITCH, "IPATCH_DLS2_PARAM_MOD_EG_TO_PITCH", "mod-eg-to-pitch" },
      { IPATCH_DLS2_PARAM_PAN, "IPATCH_DLS2_PARAM_PAN", "pan" },
      { IPATCH_DLS2_PARAM_CC10_TO_PAN, "IPATCH_DLS2_PARAM_CC10_TO_PAN", "cc10-to-pan" },
      { IPATCH_DLS2_PARAM_CC91_TO_REVERB_SEND, "IPATCH_DLS2_PARAM_CC91_TO_REVERB_SEND", "cc91-to-reverb-send" },
      { IPATCH_DLS2_PARAM_REVERB_SEND, "IPATCH_DLS2_PARAM_REVERB_SEND", "reverb-send" },
      { IPATCH_DLS2_PARAM_CC93_TO_CHORUS_SEND, "IPATCH_DLS2_PARAM_CC93_TO_CHORUS_SEND", "cc93-to-chorus-send" },
      { IPATCH_DLS2_PARAM_CHORUS_SEND, "IPATCH_DLS2_PARAM_CHORUS_SEND", "chorus-send" },
      { IPATCH_DLS2_PARAM_COUNT, "IPATCH_DLS2_PARAM_COUNT", "count" },
      { 0, NULL, NULL }
    };
    etype = g_enum_register_static ("IpatchDLS2Param", values);
  }
  return etype;
}
GType
ipatch_dls2_region_channel_type_get_type (void)
{
  static GType etype = 0;
  if (etype == 0) {
    static const GEnumValue values[] = {
      { IPATCH_DLS2_REGION_CHANNEL_LEFT, "IPATCH_DLS2_REGION_CHANNEL_LEFT", "left" },
      { IPATCH_DLS2_REGION_CHANNEL_RIGHT, "IPATCH_DLS2_REGION_CHANNEL_RIGHT", "right" },
      { IPATCH_DLS2_REGION_CHANNEL_CENTER, "IPATCH_DLS2_REGION_CHANNEL_CENTER", "center" },
      { IPATCH_DLS2_REGION_CHANNEL_LOW_FREQ, "IPATCH_DLS2_REGION_CHANNEL_LOW_FREQ", "low-freq" },
      { IPATCH_DLS2_REGION_CHANNEL_SURROUND_LEFT, "IPATCH_DLS2_REGION_CHANNEL_SURROUND_LEFT", "surround-left" },
      { IPATCH_DLS2_REGION_CHANNEL_SURROUND_RIGHT, "IPATCH_DLS2_REGION_CHANNEL_SURROUND_RIGHT", "surround-right" },
      { IPATCH_DLS2_REGION_CHANNEL_LEFT_OF_CENTER, "IPATCH_DLS2_REGION_CHANNEL_LEFT_OF_CENTER", "left-of-center" },
      { IPATCH_DLS2_REGION_CHANNEL_RIGHT_OF_CENTER, "IPATCH_DLS2_REGION_CHANNEL_RIGHT_OF_CENTER", "right-of-center" },
      { IPATCH_DLS2_REGION_CHANNEL_SURROUND_CENTER, "IPATCH_DLS2_REGION_CHANNEL_SURROUND_CENTER", "surround-center" },
      { IPATCH_DLS2_REGION_CHANNEL_SIDE_LEFT, "IPATCH_DLS2_REGION_CHANNEL_SIDE_LEFT", "side-left" },
      { IPATCH_DLS2_REGION_CHANNEL_SIDE_RIGHT, "IPATCH_DLS2_REGION_CHANNEL_SIDE_RIGHT", "side-right" },
      { IPATCH_DLS2_REGION_CHANNEL_TOP, "IPATCH_DLS2_REGION_CHANNEL_TOP", "top" },
      { IPATCH_DLS2_REGION_CHANNEL_TOP_FRONT_LEFT, "IPATCH_DLS2_REGION_CHANNEL_TOP_FRONT_LEFT", "top-front-left" },
      { IPATCH_DLS2_REGION_CHANNEL_TOP_FRONT_CENTER, "IPATCH_DLS2_REGION_CHANNEL_TOP_FRONT_CENTER", "top-front-center" },
      { IPATCH_DLS2_REGION_CHANNEL_TOP_FRONT_RIGHT, "IPATCH_DLS2_REGION_CHANNEL_TOP_FRONT_RIGHT", "top-front-right" },
      { IPATCH_DLS2_REGION_CHANNEL_TOP_REAR_LEFT, "IPATCH_DLS2_REGION_CHANNEL_TOP_REAR_LEFT", "top-rear-left" },
      { IPATCH_DLS2_REGION_CHANNEL_TOP_REAR_CENTER, "IPATCH_DLS2_REGION_CHANNEL_TOP_REAR_CENTER", "top-rear-center" },
      { IPATCH_DLS2_REGION_CHANNEL_TOP_REAR_RIGHT, "IPATCH_DLS2_REGION_CHANNEL_TOP_REAR_RIGHT", "top-rear-right" },
      { 0, NULL, NULL }
    };
    etype = g_enum_register_static ("IpatchDLS2RegionChannelType", values);
  }
  return etype;
}
GType
ipatch_dls2_region_flags_get_type (void)
{
  static GType etype = 0;
  if (etype == 0) {
    static const GFlagsValue values[] = {
      { IPATCH_DLS2_REGION_SELF_NON_EXCLUSIVE, "IPATCH_DLS2_REGION_SELF_NON_EXCLUSIVE", "self-non-exclusive" },
      { IPATCH_DLS2_REGION_PHASE_MASTER, "IPATCH_DLS2_REGION_PHASE_MASTER", "phase-master" },
      { IPATCH_DLS2_REGION_MULTI_CHANNEL, "IPATCH_DLS2_REGION_MULTI_CHANNEL", "multi-channel" },
      { IPATCH_DLS2_REGION_SAMPLE_INFO_OVERRIDE, "IPATCH_DLS2_REGION_SAMPLE_INFO_OVERRIDE", "sample-info-override" },
      { 0, NULL, NULL }
    };
    etype = g_flags_register_static ("IpatchDLS2RegionFlags", values);
  }
  return etype;
}

/* enumerations from "IpatchDLS2Sample.h" */
GType
ipatch_dls2_sample_flags_get_type (void)
{
  static GType etype = 0;
  if (etype == 0) {
    static const GFlagsValue values[] = {
      { IPATCH_DLS2_SAMPLE_NO_TRUNCATION, "IPATCH_DLS2_SAMPLE_NO_TRUNCATION", "truncation" },
      { IPATCH_DLS2_SAMPLE_NO_COMPRESSION, "IPATCH_DLS2_SAMPLE_NO_COMPRESSION", "compression" },
      { 0, NULL, NULL }
    };
    etype = g_flags_register_static ("IpatchDLS2SampleFlags", values);
  }
  return etype;
}

/* enumerations from "IpatchDLSReader.h" */
GType
ipatch_dls_reader_error_get_type (void)
{
  static GType etype = 0;
  if (etype == 0) {
    static const GEnumValue values[] = {
      { IPATCH_DLS_READER_ERROR_GIG, "IPATCH_DLS_READER_ERROR_GIG", "gig" },
      { 0, NULL, NULL }
    };
    etype = g_enum_register_static ("IpatchDLSReaderError", values);
  }
  return etype;
}

/* enumerations from "IpatchFile.h" */
GType
ipatch_file_flags_get_type (void)
{
  static GType etype = 0;
  if (etype == 0) {
    static const GFlagsValue values[] = {
      { IPATCH_FILE_FLAG_SWAP, "IPATCH_FILE_FLAG_SWAP", "swap" },
      { IPATCH_FILE_FLAG_BIG_ENDIAN, "IPATCH_FILE_FLAG_BIG_ENDIAN", "big-endian" },
      { IPATCH_FILE_FLAG_FREE_IOFUNCS, "IPATCH_FILE_FLAG_FREE_IOFUNCS", "free-iofuncs" },
      { 0, NULL, NULL }
    };
    etype = g_flags_register_static ("IpatchFileFlags", values);
  }
  return etype;
}
GType
ipatch_file_identify_order_get_type (void)
{
  static GType etype = 0;
  if (etype == 0) {
    static const GEnumValue values[] = {
      { IPATCH_FILE_IDENTIFY_ORDER_LAST, "IPATCH_FILE_IDENTIFY_ORDER_LAST", "last" },
      { IPATCH_FILE_IDENTIFY_ORDER_DEFAULT, "IPATCH_FILE_IDENTIFY_ORDER_DEFAULT", "default" },
      { IPATCH_FILE_IDENTIFY_ORDER_FIRST, "IPATCH_FILE_IDENTIFY_ORDER_FIRST", "first" },
      { 0, NULL, NULL }
    };
    etype = g_enum_register_static ("IpatchFileIdentifyOrder", values);
  }
  return etype;
}

/* enumerations from "IpatchGigDimension.h" */
GType
ipatch_gig_dimension_type_get_type (void)
{
  static GType etype = 0;
  if (etype == 0) {
    static const GEnumValue values[] = {
      { IPATCH_GIG_DIMENSION_NONE, "IPATCH_GIG_DIMENSION_NONE", "none" },
      { IPATCH_GIG_DIMENSION_MOD_WHEEL, "IPATCH_GIG_DIMENSION_MOD_WHEEL", "mod-wheel" },
      { IPATCH_GIG_DIMENSION_BREATH, "IPATCH_GIG_DIMENSION_BREATH", "breath" },
      { IPATCH_GIG_DIMENSION_FOOT, "IPATCH_GIG_DIMENSION_FOOT", "foot" },
      { IPATCH_GIG_DIMENSION_PORTAMENTO_TIME, "IPATCH_GIG_DIMENSION_PORTAMENTO_TIME", "portamento-time" },
      { IPATCH_GIG_DIMENSION_EFFECT_1, "IPATCH_GIG_DIMENSION_EFFECT_1", "effect-1" },
      { IPATCH_GIG_DIMENSION_EFFECT_2, "IPATCH_GIG_DIMENSION_EFFECT_2", "effect-2" },
      { IPATCH_GIG_DIMENSION_GEN_PURPOSE_1, "IPATCH_GIG_DIMENSION_GEN_PURPOSE_1", "gen-purpose-1" },
      { IPATCH_GIG_DIMENSION_GEN_PURPOSE_2, "IPATCH_GIG_DIMENSION_GEN_PURPOSE_2", "gen-purpose-2" },
      { IPATCH_GIG_DIMENSION_GEN_PURPOSE_3, "IPATCH_GIG_DIMENSION_GEN_PURPOSE_3", "gen-purpose-3" },
      { IPATCH_GIG_DIMENSION_GEN_PURPOSE_4, "IPATCH_GIG_DIMENSION_GEN_PURPOSE_4", "gen-purpose-4" },
      { IPATCH_GIG_DIMENSION_SUSTAIN_PEDAL, "IPATCH_GIG_DIMENSION_SUSTAIN_PEDAL", "sustain-pedal" },
      { IPATCH_GIG_DIMENSION_PORTAMENTO, "IPATCH_GIG_DIMENSION_PORTAMENTO", "portamento" },
      { IPATCH_GIG_DIMENSION_SOSTENUTO, "IPATCH_GIG_DIMENSION_SOSTENUTO", "sostenuto" },
      { IPATCH_GIG_DIMENSION_SOFT_PEDAL, "IPATCH_GIG_DIMENSION_SOFT_PEDAL", "soft-pedal" },
      { IPATCH_GIG_DIMENSION_GEN_PURPOSE_5, "IPATCH_GIG_DIMENSION_GEN_PURPOSE_5", "gen-purpose-5" },
      { IPATCH_GIG_DIMENSION_GEN_PURPOSE_6, "IPATCH_GIG_DIMENSION_GEN_PURPOSE_6", "gen-purpose-6" },
      { IPATCH_GIG_DIMENSION_GEN_PURPOSE_7, "IPATCH_GIG_DIMENSION_GEN_PURPOSE_7", "gen-purpose-7" },
      { IPATCH_GIG_DIMENSION_GEN_PURPOSE_8, "IPATCH_GIG_DIMENSION_GEN_PURPOSE_8", "gen-purpose-8" },
      { IPATCH_GIG_DIMENSION_EFFECT_DEPTH_1, "IPATCH_GIG_DIMENSION_EFFECT_DEPTH_1", "effect-depth-1" },
      { IPATCH_GIG_DIMENSION_EFFECT_DEPTH_2, "IPATCH_GIG_DIMENSION_EFFECT_DEPTH_2", "effect-depth-2" },
      { IPATCH_GIG_DIMENSION_EFFECT_DEPTH_3, "IPATCH_GIG_DIMENSION_EFFECT_DEPTH_3", "effect-depth-3" },
      { IPATCH_GIG_DIMENSION_EFFECT_DEPTH_4, "IPATCH_GIG_DIMENSION_EFFECT_DEPTH_4", "effect-depth-4" },
      { IPATCH_GIG_DIMENSION_EFFECT_DEPTH_5, "IPATCH_GIG_DIMENSION_EFFECT_DEPTH_5", "effect-depth-5" },
      { IPATCH_GIG_DIMENSION_CHANNEL, "IPATCH_GIG_DIMENSION_CHANNEL", "channel" },
      { IPATCH_GIG_DIMENSION_LAYER, "IPATCH_GIG_DIMENSION_LAYER", "layer" },
      { IPATCH_GIG_DIMENSION_VELOCITY, "IPATCH_GIG_DIMENSION_VELOCITY", "velocity" },
      { IPATCH_GIG_DIMENSION_AFTER_TOUCH, "IPATCH_GIG_DIMENSION_AFTER_TOUCH", "after-touch" },
      { IPATCH_GIG_DIMENSION_RELEASE_TRIG, "IPATCH_GIG_DIMENSION_RELEASE_TRIG", "release-trig" },
      { IPATCH_GIG_DIMENSION_KEYBOARD, "IPATCH_GIG_DIMENSION_KEYBOARD", "keyboard" },
      { IPATCH_GIG_DIMENSION_ROUND_ROBIN, "IPATCH_GIG_DIMENSION_ROUND_ROBIN", "round-robin" },
      { IPATCH_GIG_DIMENSION_RANDOM, "IPATCH_GIG_DIMENSION_RANDOM", "random" },
      { 0, NULL, NULL }
    };
    etype = g_enum_register_static ("IpatchGigDimensionType", values);
  }
  return etype;
}

/* enumerations from "IpatchGigEffects.h" */
GType
ipatch_gig_filter_type_get_type (void)
{
  static GType etype = 0;
  if (etype == 0) {
    static const GEnumValue values[] = {
      { IPATCH_GIG_FILTER_LOWPASS, "IPATCH_GIG_FILTER_LOWPASS", "lowpass" },
      { IPATCH_GIG_FILTER_BANDPASS, "IPATCH_GIG_FILTER_BANDPASS", "bandpass" },
      { IPATCH_GIG_FILTER_HIGHPASS, "IPATCH_GIG_FILTER_HIGHPASS", "highpass" },
      { IPATCH_GIG_FILTER_BANDREJECT, "IPATCH_GIG_FILTER_BANDREJECT", "bandreject" },
      { 0, NULL, NULL }
    };
    etype = g_enum_register_static ("IpatchGigFilterType", values);
  }
  return etype;
}
GType
ipatch_gig_control_type_get_type (void)
{
  static GType etype = 0;
  if (etype == 0) {
    static const GEnumValue values[] = {
      { IPATCH_GIG_CTRL_MOD_WHEEL, "IPATCH_GIG_CTRL_MOD_WHEEL", "mod-wheel" },
      { IPATCH_GIG_CTRL_BREATH, "IPATCH_GIG_CTRL_BREATH", "breath" },
      { IPATCH_GIG_CTRL_FOOT, "IPATCH_GIG_CTRL_FOOT", "foot" },
      { IPATCH_GIG_CTRL_PORTAMENTO_TIME, "IPATCH_GIG_CTRL_PORTAMENTO_TIME", "portamento-time" },
      { IPATCH_GIG_CTRL_EFFECT_1, "IPATCH_GIG_CTRL_EFFECT_1", "effect-1" },
      { IPATCH_GIG_CTRL_EFFECT_2, "IPATCH_GIG_CTRL_EFFECT_2", "effect-2" },
      { IPATCH_GIG_CTRL_GEN_PURPOSE_1, "IPATCH_GIG_CTRL_GEN_PURPOSE_1", "gen-purpose-1" },
      { IPATCH_GIG_CTRL_GEN_PURPOSE_2, "IPATCH_GIG_CTRL_GEN_PURPOSE_2", "gen-purpose-2" },
      { IPATCH_GIG_CTRL_GEN_PURPOSE_3, "IPATCH_GIG_CTRL_GEN_PURPOSE_3", "gen-purpose-3" },
      { IPATCH_GIG_CTRL_GEN_PURPOSE_4, "IPATCH_GIG_CTRL_GEN_PURPOSE_4", "gen-purpose-4" },
      { IPATCH_GIG_CTRL_SUSTAIN_PEDAL, "IPATCH_GIG_CTRL_SUSTAIN_PEDAL", "sustain-pedal" },
      { IPATCH_GIG_CTRL_PORTAMENTO, "IPATCH_GIG_CTRL_PORTAMENTO", "portamento" },
      { IPATCH_GIG_CTRL_SOSTENUTO, "IPATCH_GIG_CTRL_SOSTENUTO", "sostenuto" },
      { IPATCH_GIG_CTRL_SOFT_PEDAL, "IPATCH_GIG_CTRL_SOFT_PEDAL", "soft-pedal" },
      { IPATCH_GIG_CTRL_GEN_PURPOSE_5, "IPATCH_GIG_CTRL_GEN_PURPOSE_5", "gen-purpose-5" },
      { IPATCH_GIG_CTRL_GEN_PURPOSE_6, "IPATCH_GIG_CTRL_GEN_PURPOSE_6", "gen-purpose-6" },
      { IPATCH_GIG_CTRL_GEN_PURPOSE_7, "IPATCH_GIG_CTRL_GEN_PURPOSE_7", "gen-purpose-7" },
      { IPATCH_GIG_CTRL_GEN_PURPOSE_8, "IPATCH_GIG_CTRL_GEN_PURPOSE_8", "gen-purpose-8" },
      { IPATCH_GIG_CTRL_EFFECT_DEPTH_1, "IPATCH_GIG_CTRL_EFFECT_DEPTH_1", "effect-depth-1" },
      { IPATCH_GIG_CTRL_EFFECT_DEPTH_2, "IPATCH_GIG_CTRL_EFFECT_DEPTH_2", "effect-depth-2" },
      { IPATCH_GIG_CTRL_EFFECT_DEPTH_3, "IPATCH_GIG_CTRL_EFFECT_DEPTH_3", "effect-depth-3" },
      { IPATCH_GIG_CTRL_EFFECT_DEPTH_4, "IPATCH_GIG_CTRL_EFFECT_DEPTH_4", "effect-depth-4" },
      { IPATCH_GIG_CTRL_EFFECT_DEPTH_5, "IPATCH_GIG_CTRL_EFFECT_DEPTH_5", "effect-depth-5" },
      { 0, NULL, NULL }
    };
    etype = g_enum_register_static ("IpatchGigControlType", values);
  }
  return etype;
}

/* enumerations from "IpatchGigRegion.h" */
GType
ipatch_gig_region_flags_get_type (void)
{
  static GType etype = 0;
  if (etype == 0) {
    static const GFlagsValue values[] = {
      { IPATCH_GIG_REGION_SELF_NON_EXCLUSIVE, "IPATCH_GIG_REGION_SELF_NON_EXCLUSIVE", "self-non-exclusive" },
      { IPATCH_GIG_REGION_PHASE_MASTER, "IPATCH_GIG_REGION_PHASE_MASTER", "phase-master" },
      { IPATCH_GIG_REGION_MULTI_CHANNEL, "IPATCH_GIG_REGION_MULTI_CHANNEL", "multi-channel" },
      { 0, NULL, NULL }
    };
    etype = g_flags_register_static ("IpatchGigRegionFlags", values);
  }
  return etype;
}

/* enumerations from "IpatchGigSubRegion.h" */
GType
ipatch_gig_sub_region_flags_get_type (void)
{
  static GType etype = 0;
  if (etype == 0) {
    static const GFlagsValue values[] = {
      { IPATCH_GIG_SUB_REGION_SAMPLE_INFO_OVERRIDE, "IPATCH_GIG_SUB_REGION_SAMPLE_INFO_OVERRIDE", "override" },
      { 0, NULL, NULL }
    };
    etype = g_flags_register_static ("IpatchGigSubRegionFlags", values);
  }
  return etype;
}

/* enumerations from "IpatchItem.h" */
GType
ipatch_item_flags_get_type (void)
{
  static GType etype = 0;
  if (etype == 0) {
    static const GFlagsValue values[] = {
      { IPATCH_ITEM_HOOKS_ACTIVE, "IPATCH_ITEM_HOOKS_ACTIVE", "hooks-active" },
      { IPATCH_ITEM_FREE_MUTEX, "IPATCH_ITEM_FREE_MUTEX", "free-mutex" },
      { 0, NULL, NULL }
    };
    etype = g_flags_register_static ("IpatchItemFlags", values);
  }
  return etype;
}

/* enumerations from "IpatchPaste.h" */
GType
ipatch_paste_choice_get_type (void)
{
  static GType etype = 0;
  if (etype == 0) {
    static const GEnumValue values[] = {
      { IPATCH_PASTE_CHOICE_IGNORE, "IPATCH_PASTE_CHOICE_IGNORE", "ignore" },
      { IPATCH_PASTE_CHOICE_REPLACE, "IPATCH_PASTE_CHOICE_REPLACE", "replace" },
      { IPATCH_PASTE_CHOICE_KEEP, "IPATCH_PASTE_CHOICE_KEEP", "keep" },
      { IPATCH_PASTE_CHOICE_CANCEL, "IPATCH_PASTE_CHOICE_CANCEL", "cancel" },
      { 0, NULL, NULL }
    };
    etype = g_enum_register_static ("IpatchPasteChoice", values);
  }
  return etype;
}
GType
ipatch_paste_priority_get_type (void)
{
  static GType etype = 0;
  if (etype == 0) {
    static const GEnumValue values[] = {
      { IPATCH_PASTE_PRIORITY_LOWEST, "IPATCH_PASTE_PRIORITY_LOWEST", "lowest" },
      { IPATCH_PASTE_PRIORITY_LOW, "IPATCH_PASTE_PRIORITY_LOW", "low" },
      { IPATCH_PASTE_PRIORITY_DEFAULT, "IPATCH_PASTE_PRIORITY_DEFAULT", "default" },
      { IPATCH_PASTE_PRIORITY_HIGH, "IPATCH_PASTE_PRIORITY_HIGH", "high" },
      { IPATCH_PASTE_PRIORITY_HIGHEST, "IPATCH_PASTE_PRIORITY_HIGHEST", "highest" },
      { 0, NULL, NULL }
    };
    etype = g_enum_register_static ("IpatchPastePriority", values);
  }
  return etype;
}

/* enumerations from "IpatchRiff.h" */
GType
ipatch_riff_status_get_type (void)
{
  static GType etype = 0;
  if (etype == 0) {
    static const GEnumValue values[] = {
      { IPATCH_RIFF_STATUS_FAIL, "IPATCH_RIFF_STATUS_FAIL", "fail" },
      { IPATCH_RIFF_STATUS_BEGIN, "IPATCH_RIFF_STATUS_BEGIN", "begin" },
      { IPATCH_RIFF_STATUS_FINISHED, "IPATCH_RIFF_STATUS_FINISHED", "finished" },
      { IPATCH_RIFF_STATUS_NORMAL, "IPATCH_RIFF_STATUS_NORMAL", "normal" },
      { IPATCH_RIFF_STATUS_CHUNK_END, "IPATCH_RIFF_STATUS_CHUNK_END", "chunk-end" },
      { 0, NULL, NULL }
    };
    etype = g_enum_register_static ("IpatchRiffStatus", values);
  }
  return etype;
}
GType
ipatch_riff_mode_get_type (void)
{
  static GType etype = 0;
  if (etype == 0) {
    static const GEnumValue values[] = {
      { IPATCH_RIFF_READ, "IPATCH_RIFF_READ", "read" },
      { IPATCH_RIFF_WRITE, "IPATCH_RIFF_WRITE", "write" },
      { 0, NULL, NULL }
    };
    etype = g_enum_register_static ("IpatchRiffMode", values);
  }
  return etype;
}
GType
ipatch_riff_chunk_type_get_type (void)
{
  static GType etype = 0;
  if (etype == 0) {
    static const GEnumValue values[] = {
      { IPATCH_RIFF_CHUNK_RIFF, "IPATCH_RIFF_CHUNK_RIFF", "riff" },
      { IPATCH_RIFF_CHUNK_LIST, "IPATCH_RIFF_CHUNK_LIST", "list" },
      { IPATCH_RIFF_CHUNK_SUB, "IPATCH_RIFF_CHUNK_SUB", "sub" },
      { 0, NULL, NULL }
    };
    etype = g_enum_register_static ("IpatchRiffChunkType", values);
  }
  return etype;
}
GType
ipatch_riff_error_get_type (void)
{
  static GType etype = 0;
  if (etype == 0) {
    static const GEnumValue values[] = {
      { IPATCH_RIFF_ERROR_NOT_RIFF, "IPATCH_RIFF_ERROR_NOT_RIFF", "not-riff" },
      { IPATCH_RIFF_ERROR_UNEXPECTED_ID, "IPATCH_RIFF_ERROR_UNEXPECTED_ID", "unexpected-id" },
      { IPATCH_RIFF_ERROR_UNEXPECTED_CHUNK_END, "IPATCH_RIFF_ERROR_UNEXPECTED_CHUNK_END", "unexpected-chunk-end" },
      { IPATCH_RIFF_ERROR_INVALID_ID, "IPATCH_RIFF_ERROR_INVALID_ID", "invalid-id" },
      { IPATCH_RIFF_ERROR_ODD_SIZE, "IPATCH_RIFF_ERROR_ODD_SIZE", "odd-size" },
      { IPATCH_RIFF_ERROR_SIZE_EXCEEDED, "IPATCH_RIFF_ERROR_SIZE_EXCEEDED", "size-exceeded" },
      { IPATCH_RIFF_ERROR_SIZE_MISMATCH, "IPATCH_RIFF_ERROR_SIZE_MISMATCH", "size-mismatch" },
      { IPATCH_RIFF_ERROR_INVALID_DATA, "IPATCH_RIFF_ERROR_INVALID_DATA", "invalid-data" },
      { 0, NULL, NULL }
    };
    etype = g_enum_register_static ("IpatchRiffError", values);
  }
  return etype;
}

/* enumerations from "IpatchSample.h" */
GType
ipatch_sample_loop_type_get_type (void)
{
  static GType etype = 0;
  if (etype == 0) {
    static const GEnumValue values[] = {
      { IPATCH_SAMPLE_LOOP_NONE, "IPATCH_SAMPLE_LOOP_NONE", "none" },
      { IPATCH_SAMPLE_LOOP_STANDARD, "IPATCH_SAMPLE_LOOP_STANDARD", "standard" },
      { IPATCH_SAMPLE_LOOP_RELEASE, "IPATCH_SAMPLE_LOOP_RELEASE", "release" },
      { IPATCH_SAMPLE_LOOP_PINGPONG, "IPATCH_SAMPLE_LOOP_PINGPONG", "pingpong" },
      { 0, NULL, NULL }
    };
    etype = g_enum_register_static ("IpatchSampleLoopType", values);
  }
  return etype;
}

/* enumerations from "IpatchSampleStoreRam.h" */
GType
ipatch_sample_store_ram_flags_get_type (void)
{
  static GType etype = 0;
  if (etype == 0) {
    static const GFlagsValue values[] = {
      { IPATCH_SAMPLE_STORE_RAM_ALLOCATED, "IPATCH_SAMPLE_STORE_RAM_ALLOCATED", "allocated" },
      { 0, NULL, NULL }
    };
    etype = g_flags_register_static ("IpatchSampleStoreRamFlags", values);
  }
  return etype;
}

/* enumerations from "IpatchSF2.h" */
GType
ipatch_sf2_flags_get_type (void)
{
  static GType etype = 0;
  if (etype == 0) {
    static const GFlagsValue values[] = {
      { IPATCH_SF2_SAMPLES_24BIT, "IPATCH_SF2_SAMPLES_24BIT", "24bit" },
      { 0, NULL, NULL }
    };
    etype = g_flags_register_static ("IpatchSF2Flags", values);
  }
  return etype;
}
GType
ipatch_sf2_info_type_get_type (void)
{
  static GType etype = 0;
  if (etype == 0) {
    static const GEnumValue values[] = {
      { IPATCH_SF2_UNKNOWN, "IPATCH_SF2_UNKNOWN", "unknown" },
      { IPATCH_SF2_VERSION, "IPATCH_SF2_VERSION", "version" },
      { IPATCH_SF2_ENGINE, "IPATCH_SF2_ENGINE", "engine" },
      { IPATCH_SF2_NAME, "IPATCH_SF2_NAME", "name" },
      { IPATCH_SF2_ROM_NAME, "IPATCH_SF2_ROM_NAME", "rom-name" },
      { IPATCH_SF2_ROM_VERSION, "IPATCH_SF2_ROM_VERSION", "rom-version" },
      { IPATCH_SF2_DATE, "IPATCH_SF2_DATE", "date" },
      { IPATCH_SF2_AUTHOR, "IPATCH_SF2_AUTHOR", "author" },
      { IPATCH_SF2_PRODUCT, "IPATCH_SF2_PRODUCT", "product" },
      { IPATCH_SF2_COPYRIGHT, "IPATCH_SF2_COPYRIGHT", "copyright" },
      { IPATCH_SF2_COMMENT, "IPATCH_SF2_COMMENT", "comment" },
      { IPATCH_SF2_SOFTWARE, "IPATCH_SF2_SOFTWARE", "software" },
      { 0, NULL, NULL }
    };
    etype = g_enum_register_static ("IpatchSF2InfoType", values);
  }
  return etype;
}

/* enumerations from "IpatchSF2Gen.h" */
GType
ipatch_sf2_gen_props_type_get_type (void)
{
  static GType etype = 0;
  if (etype == 0) {
    static const GEnumValue values[] = {
      { IPATCH_SF2_GEN_PROPS_INST, "IPATCH_SF2_GEN_PROPS_INST", "inst" },
      { IPATCH_SF2_GEN_PROPS_PRESET, "IPATCH_SF2_GEN_PROPS_PRESET", "preset" },
      { IPATCH_SF2_GEN_PROPS_INST_GLOBAL, "IPATCH_SF2_GEN_PROPS_INST_GLOBAL", "inst-global" },
      { IPATCH_SF2_GEN_PROPS_PRESET_GLOBAL, "IPATCH_SF2_GEN_PROPS_PRESET_GLOBAL", "preset-global" },
      { 0, NULL, NULL }
    };
    etype = g_enum_register_static ("IpatchSF2GenPropsType", values);
  }
  return etype;
}
GType
ipatch_sf2_gen_type_get_type (void)
{
  static GType etype = 0;
  if (etype == 0) {
    static const GEnumValue values[] = {
      { IPATCH_SF2_GEN_SAMPLE_START, "IPATCH_SF2_GEN_SAMPLE_START", "sample-start" },
      { IPATCH_SF2_GEN_SAMPLE_END, "IPATCH_SF2_GEN_SAMPLE_END", "sample-end" },
      { IPATCH_SF2_GEN_SAMPLE_LOOP_START, "IPATCH_SF2_GEN_SAMPLE_LOOP_START", "sample-loop-start" },
      { IPATCH_SF2_GEN_SAMPLE_LOOP_END, "IPATCH_SF2_GEN_SAMPLE_LOOP_END", "sample-loop-end" },
      { IPATCH_SF2_GEN_SAMPLE_COARSE_START, "IPATCH_SF2_GEN_SAMPLE_COARSE_START", "sample-coarse-start" },
      { IPATCH_SF2_GEN_MOD_LFO_TO_PITCH, "IPATCH_SF2_GEN_MOD_LFO_TO_PITCH", "mod-lfo-to-pitch" },
      { IPATCH_SF2_GEN_VIB_LFO_TO_PITCH, "IPATCH_SF2_GEN_VIB_LFO_TO_PITCH", "vib-lfo-to-pitch" },
      { IPATCH_SF2_GEN_MOD_ENV_TO_PITCH, "IPATCH_SF2_GEN_MOD_ENV_TO_PITCH", "mod-env-to-pitch" },
      { IPATCH_SF2_GEN_FILTER_CUTOFF, "IPATCH_SF2_GEN_FILTER_CUTOFF", "filter-cutoff" },
      { IPATCH_SF2_GEN_FILTER_Q, "IPATCH_SF2_GEN_FILTER_Q", "filter-q" },
      { IPATCH_SF2_GEN_MOD_LFO_TO_FILTER_CUTOFF, "IPATCH_SF2_GEN_MOD_LFO_TO_FILTER_CUTOFF", "mod-lfo-to-filter-cutoff" },
      { IPATCH_SF2_GEN_MOD_ENV_TO_FILTER_CUTOFF, "IPATCH_SF2_GEN_MOD_ENV_TO_FILTER_CUTOFF", "mod-env-to-filter-cutoff" },
      { IPATCH_SF2_GEN_SAMPLE_COARSE_END, "IPATCH_SF2_GEN_SAMPLE_COARSE_END", "sample-coarse-end" },
      { IPATCH_SF2_GEN_MOD_LFO_TO_VOLUME, "IPATCH_SF2_GEN_MOD_LFO_TO_VOLUME", "mod-lfo-to-volume" },
      { IPATCH_SF2_GEN_UNUSED1, "IPATCH_SF2_GEN_UNUSED1", "unused1" },
      { IPATCH_SF2_GEN_CHORUS, "IPATCH_SF2_GEN_CHORUS", "chorus" },
      { IPATCH_SF2_GEN_REVERB, "IPATCH_SF2_GEN_REVERB", "reverb" },
      { IPATCH_SF2_GEN_PAN, "IPATCH_SF2_GEN_PAN", "pan" },
      { IPATCH_SF2_GEN_UNUSED2, "IPATCH_SF2_GEN_UNUSED2", "unused2" },
      { IPATCH_SF2_GEN_UNUSED3, "IPATCH_SF2_GEN_UNUSED3", "unused3" },
      { IPATCH_SF2_GEN_UNUSED4, "IPATCH_SF2_GEN_UNUSED4", "unused4" },
      { IPATCH_SF2_GEN_MOD_LFO_DELAY, "IPATCH_SF2_GEN_MOD_LFO_DELAY", "mod-lfo-delay" },
      { IPATCH_SF2_GEN_MOD_LFO_FREQ, "IPATCH_SF2_GEN_MOD_LFO_FREQ", "mod-lfo-freq" },
      { IPATCH_SF2_GEN_VIB_LFO_DELAY, "IPATCH_SF2_GEN_VIB_LFO_DELAY", "vib-lfo-delay" },
      { IPATCH_SF2_GEN_VIB_LFO_FREQ, "IPATCH_SF2_GEN_VIB_LFO_FREQ", "vib-lfo-freq" },
      { IPATCH_SF2_GEN_MOD_ENV_DELAY, "IPATCH_SF2_GEN_MOD_ENV_DELAY", "mod-env-delay" },
      { IPATCH_SF2_GEN_MOD_ENV_ATTACK, "IPATCH_SF2_GEN_MOD_ENV_ATTACK", "mod-env-attack" },
      { IPATCH_SF2_GEN_MOD_ENV_HOLD, "IPATCH_SF2_GEN_MOD_ENV_HOLD", "mod-env-hold" },
      { IPATCH_SF2_GEN_MOD_ENV_DECAY, "IPATCH_SF2_GEN_MOD_ENV_DECAY", "mod-env-decay" },
      { IPATCH_SF2_GEN_MOD_ENV_SUSTAIN, "IPATCH_SF2_GEN_MOD_ENV_SUSTAIN", "mod-env-sustain" },
      { IPATCH_SF2_GEN_MOD_ENV_RELEASE, "IPATCH_SF2_GEN_MOD_ENV_RELEASE", "mod-env-release" },
      { IPATCH_SF2_GEN_NOTE_TO_MOD_ENV_HOLD, "IPATCH_SF2_GEN_NOTE_TO_MOD_ENV_HOLD", "note-to-mod-env-hold" },
      { IPATCH_SF2_GEN_NOTE_TO_MOD_ENV_DECAY, "IPATCH_SF2_GEN_NOTE_TO_MOD_ENV_DECAY", "note-to-mod-env-decay" },
      { IPATCH_SF2_GEN_VOL_ENV_DELAY, "IPATCH_SF2_GEN_VOL_ENV_DELAY", "vol-env-delay" },
      { IPATCH_SF2_GEN_VOL_ENV_ATTACK, "IPATCH_SF2_GEN_VOL_ENV_ATTACK", "vol-env-attack" },
      { IPATCH_SF2_GEN_VOL_ENV_HOLD, "IPATCH_SF2_GEN_VOL_ENV_HOLD", "vol-env-hold" },
      { IPATCH_SF2_GEN_VOL_ENV_DECAY, "IPATCH_SF2_GEN_VOL_ENV_DECAY", "vol-env-decay" },
      { IPATCH_SF2_GEN_VOL_ENV_SUSTAIN, "IPATCH_SF2_GEN_VOL_ENV_SUSTAIN", "vol-env-sustain" },
      { IPATCH_SF2_GEN_VOL_ENV_RELEASE, "IPATCH_SF2_GEN_VOL_ENV_RELEASE", "vol-env-release" },
      { IPATCH_SF2_GEN_NOTE_TO_VOL_ENV_HOLD, "IPATCH_SF2_GEN_NOTE_TO_VOL_ENV_HOLD", "note-to-vol-env-hold" },
      { IPATCH_SF2_GEN_NOTE_TO_VOL_ENV_DECAY, "IPATCH_SF2_GEN_NOTE_TO_VOL_ENV_DECAY", "note-to-vol-env-decay" },
      { IPATCH_SF2_GEN_INSTRUMENT_ID, "IPATCH_SF2_GEN_INSTRUMENT_ID", "instrument-id" },
      { IPATCH_SF2_GEN_RESERVED1, "IPATCH_SF2_GEN_RESERVED1", "reserved1" },
      { IPATCH_SF2_GEN_NOTE_RANGE, "IPATCH_SF2_GEN_NOTE_RANGE", "note-range" },
      { IPATCH_SF2_GEN_VELOCITY_RANGE, "IPATCH_SF2_GEN_VELOCITY_RANGE", "velocity-range" },
      { IPATCH_SF2_GEN_SAMPLE_COARSE_LOOP_START, "IPATCH_SF2_GEN_SAMPLE_COARSE_LOOP_START", "sample-coarse-loop-start" },
      { IPATCH_SF2_GEN_FIXED_NOTE, "IPATCH_SF2_GEN_FIXED_NOTE", "fixed-note" },
      { IPATCH_SF2_GEN_FIXED_VELOCITY, "IPATCH_SF2_GEN_FIXED_VELOCITY", "fixed-velocity" },
      { IPATCH_SF2_GEN_ATTENUATION, "IPATCH_SF2_GEN_ATTENUATION", "attenuation" },
      { IPATCH_SF2_GEN_RESERVED2, "IPATCH_SF2_GEN_RESERVED2", "reserved2" },
      { IPATCH_SF2_GEN_SAMPLE_COARSE_LOOP_END, "IPATCH_SF2_GEN_SAMPLE_COARSE_LOOP_END", "sample-coarse-loop-end" },
      { IPATCH_SF2_GEN_COARSE_TUNE, "IPATCH_SF2_GEN_COARSE_TUNE", "coarse-tune" },
      { IPATCH_SF2_GEN_FINE_TUNE_OVERRIDE, "IPATCH_SF2_GEN_FINE_TUNE_OVERRIDE", "fine-tune-override" },
      { IPATCH_SF2_GEN_SAMPLE_ID, "IPATCH_SF2_GEN_SAMPLE_ID", "sample-id" },
      { IPATCH_SF2_GEN_SAMPLE_MODES, "IPATCH_SF2_GEN_SAMPLE_MODES", "sample-modes" },
      { IPATCH_SF2_GEN_RESERVED3, "IPATCH_SF2_GEN_RESERVED3", "reserved3" },
      { IPATCH_SF2_GEN_SCALE_TUNE, "IPATCH_SF2_GEN_SCALE_TUNE", "scale-tune" },
      { IPATCH_SF2_GEN_EXCLUSIVE_CLASS, "IPATCH_SF2_GEN_EXCLUSIVE_CLASS", "exclusive-class" },
      { IPATCH_SF2_GEN_ROOT_NOTE_OVERRIDE, "IPATCH_SF2_GEN_ROOT_NOTE_OVERRIDE", "root-note-override" },
      { 0, NULL, NULL }
    };
    etype = g_enum_register_static ("IpatchSF2GenType", values);
  }
  return etype;
}
GType
ipatch_sf2_gen_sample_modes_get_type (void)
{
  static GType etype = 0;
  if (etype == 0) {
    static const GFlagsValue values[] = {
      { IPATCH_SF2_GEN_SAMPLE_MODE_NOLOOP, "IPATCH_SF2_GEN_SAMPLE_MODE_NOLOOP", "noloop" },
      { IPATCH_SF2_GEN_SAMPLE_MODE_LOOP, "IPATCH_SF2_GEN_SAMPLE_MODE_LOOP", "loop" },
      { IPATCH_SF2_GEN_SAMPLE_MODE_LOOP_RELEASE, "IPATCH_SF2_GEN_SAMPLE_MODE_LOOP_RELEASE", "loop-release" },
      { 0, NULL, NULL }
    };
    etype = g_flags_register_static ("IpatchSF2GenSampleModes", values);
  }
  return etype;
}

/* enumerations from "IpatchSF2Mod.h" */
GType
ipatch_sf2_mod_field_masks_get_type (void)
{
  static GType etype = 0;
  if (etype == 0) {
    static const GEnumValue values[] = {
      { IPATCH_SF2_MOD_MASK_CONTROL, "IPATCH_SF2_MOD_MASK_CONTROL", "control" },
      { IPATCH_SF2_MOD_MASK_CC, "IPATCH_SF2_MOD_MASK_CC", "cc" },
      { IPATCH_SF2_MOD_MASK_DIRECTION, "IPATCH_SF2_MOD_MASK_DIRECTION", "direction" },
      { IPATCH_SF2_MOD_MASK_POLARITY, "IPATCH_SF2_MOD_MASK_POLARITY", "polarity" },
      { IPATCH_SF2_MOD_MASK_TYPE, "IPATCH_SF2_MOD_MASK_TYPE", "type" },
      { 0, NULL, NULL }
    };
    etype = g_enum_register_static ("IpatchSF2ModFieldMasks", values);
  }
  return etype;
}
GType
ipatch_sf2_mod_field_shifts_get_type (void)
{
  static GType etype = 0;
  if (etype == 0) {
    static const GEnumValue values[] = {
      { IPATCH_SF2_MOD_SHIFT_CONTROL, "IPATCH_SF2_MOD_SHIFT_CONTROL", "control" },
      { IPATCH_SF2_MOD_SHIFT_CC, "IPATCH_SF2_MOD_SHIFT_CC", "cc" },
      { IPATCH_SF2_MOD_SHIFT_DIRECTION, "IPATCH_SF2_MOD_SHIFT_DIRECTION", "direction" },
      { IPATCH_SF2_MOD_SHIFT_POLARITY, "IPATCH_SF2_MOD_SHIFT_POLARITY", "polarity" },
      { IPATCH_SF2_MOD_SHIFT_TYPE, "IPATCH_SF2_MOD_SHIFT_TYPE", "type" },
      { 0, NULL, NULL }
    };
    etype = g_enum_register_static ("IpatchSF2ModFieldShifts", values);
  }
  return etype;
}
GType
ipatch_sf2_mod_control_get_type (void)
{
  static GType etype = 0;
  if (etype == 0) {
    static const GEnumValue values[] = {
      { IPATCH_SF2_MOD_CONTROL_NONE, "IPATCH_SF2_MOD_CONTROL_NONE", "none" },
      { IPATCH_SF2_MOD_CONTROL_NOTE_ON_VELOCITY, "IPATCH_SF2_MOD_CONTROL_NOTE_ON_VELOCITY", "note-on-velocity" },
      { IPATCH_SF2_MOD_CONTROL_NOTE_NUMBER, "IPATCH_SF2_MOD_CONTROL_NOTE_NUMBER", "note-number" },
      { IPATCH_SF2_MOD_CONTROL_POLY_PRESSURE, "IPATCH_SF2_MOD_CONTROL_POLY_PRESSURE", "poly-pressure" },
      { IPATCH_SF2_MOD_CONTROL_CHAN_PRESSURE, "IPATCH_SF2_MOD_CONTROL_CHAN_PRESSURE", "chan-pressure" },
      { IPATCH_SF2_MOD_CONTROL_PITCH_WHEEL, "IPATCH_SF2_MOD_CONTROL_PITCH_WHEEL", "pitch-wheel" },
      { IPATCH_SF2_MOD_CONTROL_BEND_RANGE, "IPATCH_SF2_MOD_CONTROL_BEND_RANGE", "bend-range" },
      { 0, NULL, NULL }
    };
    etype = g_enum_register_static ("IpatchSF2ModControl", values);
  }
  return etype;
}
GType
ipatch_sf2_mod_control_palette_get_type (void)
{
  static GType etype = 0;
  if (etype == 0) {
    static const GFlagsValue values[] = {
      { IPATCH_SF2_MOD_CC_GENERAL, "IPATCH_SF2_MOD_CC_GENERAL", "general" },
      { IPATCH_SF2_MOD_CC_MIDI, "IPATCH_SF2_MOD_CC_MIDI", "midi" },
      { 0, NULL, NULL }
    };
    etype = g_flags_register_static ("IpatchSF2ModControlPalette", values);
  }
  return etype;
}
GType
ipatch_sf2_mod_direction_get_type (void)
{
  static GType etype = 0;
  if (etype == 0) {
    static const GFlagsValue values[] = {
      { IPATCH_SF2_MOD_DIRECTION_POSITIVE, "IPATCH_SF2_MOD_DIRECTION_POSITIVE", "positive" },
      { IPATCH_SF2_MOD_DIRECTION_NEGATIVE, "IPATCH_SF2_MOD_DIRECTION_NEGATIVE", "negative" },
      { 0, NULL, NULL }
    };
    etype = g_flags_register_static ("IpatchSF2ModDirection", values);
  }
  return etype;
}
GType
ipatch_sf2_mod_polarity_get_type (void)
{
  static GType etype = 0;
  if (etype == 0) {
    static const GFlagsValue values[] = {
      { IPATCH_SF2_MOD_POLARITY_UNIPOLAR, "IPATCH_SF2_MOD_POLARITY_UNIPOLAR", "unipolar" },
      { IPATCH_SF2_MOD_POLARITY_BIPOLAR, "IPATCH_SF2_MOD_POLARITY_BIPOLAR", "bipolar" },
      { 0, NULL, NULL }
    };
    etype = g_flags_register_static ("IpatchSF2ModPolarity", values);
  }
  return etype;
}
GType
ipatch_sf2_mod_type_get_type (void)
{
  static GType etype = 0;
  if (etype == 0) {
    static const GFlagsValue values[] = {
      { IPATCH_SF2_MOD_TYPE_LINEAR, "IPATCH_SF2_MOD_TYPE_LINEAR", "linear" },
      { IPATCH_SF2_MOD_TYPE_CONCAVE, "IPATCH_SF2_MOD_TYPE_CONCAVE", "concave" },
      { IPATCH_SF2_MOD_TYPE_CONVEX, "IPATCH_SF2_MOD_TYPE_CONVEX", "convex" },
      { IPATCH_SF2_MOD_TYPE_SWITCH, "IPATCH_SF2_MOD_TYPE_SWITCH", "switch" },
      { 0, NULL, NULL }
    };
    etype = g_flags_register_static ("IpatchSF2ModType", values);
  }
  return etype;
}
GType
ipatch_sf2_mod_transform_get_type (void)
{
  static GType etype = 0;
  if (etype == 0) {
    static const GEnumValue values[] = {
      { IPATCH_SF2_MOD_TRANSFORM_LINEAR, "IPATCH_SF2_MOD_TRANSFORM_LINEAR", "linear" },
      { 0, NULL, NULL }
    };
    etype = g_enum_register_static ("IpatchSF2ModTransform", values);
  }
  return etype;
}
GType
ipatch_sf2_mod_flags_get_type (void)
{
  static GType etype = 0;
  if (etype == 0) {
    static const GFlagsValue values[] = {
      { IPATCH_SF2_MOD_NO_DUPLICATE, "IPATCH_SF2_MOD_NO_DUPLICATE", "duplicate" },
      { IPATCH_SF2_MOD_NO_NOTIFY, "IPATCH_SF2_MOD_NO_NOTIFY", "notify" },
      { 0, NULL, NULL }
    };
    etype = g_flags_register_static ("IpatchSF2ModFlags", values);
  }
  return etype;
}

/* enumerations from "IpatchSF2Sample.h" */
GType
ipatch_sf2_sample_channel_get_type (void)
{
  static GType etype = 0;
  if (etype == 0) {
    static const GEnumValue values[] = {
      { IPATCH_SF2_SAMPLE_CHANNEL_MONO, "IPATCH_SF2_SAMPLE_CHANNEL_MONO", "mono" },
      { IPATCH_SF2_SAMPLE_CHANNEL_LEFT, "IPATCH_SF2_SAMPLE_CHANNEL_LEFT", "left" },
      { IPATCH_SF2_SAMPLE_CHANNEL_RIGHT, "IPATCH_SF2_SAMPLE_CHANNEL_RIGHT", "right" },
      { 0, NULL, NULL }
    };
    etype = g_enum_register_static ("IpatchSF2SampleChannel", values);
  }
  return etype;
}

/* enumerations from "IpatchSF2VoiceCache.h" */
GType
ipatch_sf2_voice_sel_type_get_type (void)
{
  static GType etype = 0;
  if (etype == 0) {
    static const GEnumValue values[] = {
      { IPATCH_SF2_VOICE_SEL_NOTE, "IPATCH_SF2_VOICE_SEL_NOTE", "note" },
      { IPATCH_SF2_VOICE_SEL_VELOCITY, "IPATCH_SF2_VOICE_SEL_VELOCITY", "velocity" },
      { IPATCH_SF2_VOICE_SEL_AFTER_TOUCH, "IPATCH_SF2_VOICE_SEL_AFTER_TOUCH", "after-touch" },
      { IPATCH_SF2_VOICE_SEL_MIDI_CC, "IPATCH_SF2_VOICE_SEL_MIDI_CC", "midi-cc" },
      { 0, NULL, NULL }
    };
    etype = g_enum_register_static ("IpatchSF2VoiceSelType", values);
  }
  return etype;
}

/* enumerations from "IpatchSndFile.h" */
GType
ipatch_snd_file_endian_get_type (void)
{
  static GType etype = 0;
  if (etype == 0) {
    static const GEnumValue values[] = {
      { IPATCH_SND_FILE_ENDIAN_FILE, "IPATCH_SND_FILE_ENDIAN_FILE", "file" },
      { IPATCH_SND_FILE_ENDIAN_LITTLE, "IPATCH_SND_FILE_ENDIAN_LITTLE", "little" },
      { IPATCH_SND_FILE_ENDIAN_BIG, "IPATCH_SND_FILE_ENDIAN_BIG", "big" },
      { IPATCH_SND_FILE_ENDIAN_CPU, "IPATCH_SND_FILE_ENDIAN_CPU", "cpu" },
      { 0, NULL, NULL }
    };
    etype = g_enum_register_static ("IpatchSndFileEndian", values);
  }
  return etype;
}

/* enumerations from "IpatchTypeProp.h" */
GType
ipatch_splits_type_get_type (void)
{
  static GType etype = 0;
  if (etype == 0) {
    static const GEnumValue values[] = {
      { IPATCH_SPLITS_NONE, "IPATCH_SPLITS_NONE", "none" },
      { IPATCH_SPLITS_NORMAL, "IPATCH_SPLITS_NORMAL", "normal" },
      { IPATCH_SPLITS_NO_OVERLAP, "IPATCH_SPLITS_NO_OVERLAP", "no-overlap" },
      { 0, NULL, NULL }
    };
    etype = g_enum_register_static ("IpatchSplitsType", values);
  }
  return etype;
}

/* enumerations from "IpatchUnit.h" */
GType
ipatch_unit_flags_get_type (void)
{
  static GType etype = 0;
  if (etype == 0) {
    static const GFlagsValue values[] = {
      { IPATCH_UNIT_LOGARITHMIC, "IPATCH_UNIT_LOGARITHMIC", "logarithmic" },
      { IPATCH_UNIT_USER, "IPATCH_UNIT_USER", "user" },
      { 0, NULL, NULL }
    };
    etype = g_flags_register_static ("IpatchUnitFlags", values);
  }
  return etype;
}
GType
ipatch_unit_type_get_type (void)
{
  static GType etype = 0;
  if (etype == 0) {
    static const GEnumValue values[] = {
      { IPATCH_UNIT_TYPE_NONE, "IPATCH_UNIT_TYPE_NONE", "none" },
      { IPATCH_UNIT_TYPE_INT, "IPATCH_UNIT_TYPE_INT", "int" },
      { IPATCH_UNIT_TYPE_UINT, "IPATCH_UNIT_TYPE_UINT", "uint" },
      { IPATCH_UNIT_TYPE_RANGE, "IPATCH_UNIT_TYPE_RANGE", "range" },
      { IPATCH_UNIT_TYPE_DECIBELS, "IPATCH_UNIT_TYPE_DECIBELS", "decibels" },
      { IPATCH_UNIT_TYPE_PERCENT, "IPATCH_UNIT_TYPE_PERCENT", "percent" },
      { IPATCH_UNIT_TYPE_SEMITONES, "IPATCH_UNIT_TYPE_SEMITONES", "semitones" },
      { IPATCH_UNIT_TYPE_CENTS, "IPATCH_UNIT_TYPE_CENTS", "cents" },
      { IPATCH_UNIT_TYPE_TIME_CENTS, "IPATCH_UNIT_TYPE_TIME_CENTS", "time-cents" },
      { IPATCH_UNIT_TYPE_SAMPLE_RATE, "IPATCH_UNIT_TYPE_SAMPLE_RATE", "sample-rate" },
      { IPATCH_UNIT_TYPE_SAMPLES, "IPATCH_UNIT_TYPE_SAMPLES", "samples" },
      { IPATCH_UNIT_TYPE_HERTZ, "IPATCH_UNIT_TYPE_HERTZ", "hertz" },
      { IPATCH_UNIT_TYPE_SECONDS, "IPATCH_UNIT_TYPE_SECONDS", "seconds" },
      { IPATCH_UNIT_TYPE_MULTIPLIER, "IPATCH_UNIT_TYPE_MULTIPLIER", "multiplier" },
      { IPATCH_UNIT_TYPE_DLS_GAIN, "IPATCH_UNIT_TYPE_DLS_GAIN", "dls-gain" },
      { IPATCH_UNIT_TYPE_DLS_ABS_TIME, "IPATCH_UNIT_TYPE_DLS_ABS_TIME", "dls-abs-time" },
      { IPATCH_UNIT_TYPE_DLS_REL_TIME, "IPATCH_UNIT_TYPE_DLS_REL_TIME", "dls-rel-time" },
      { IPATCH_UNIT_TYPE_DLS_ABS_PITCH, "IPATCH_UNIT_TYPE_DLS_ABS_PITCH", "dls-abs-pitch" },
      { IPATCH_UNIT_TYPE_DLS_REL_PITCH, "IPATCH_UNIT_TYPE_DLS_REL_PITCH", "dls-rel-pitch" },
      { IPATCH_UNIT_TYPE_DLS_PERCENT, "IPATCH_UNIT_TYPE_DLS_PERCENT", "dls-percent" },
      { IPATCH_UNIT_TYPE_SF2_ABS_PITCH, "IPATCH_UNIT_TYPE_SF2_ABS_PITCH", "sf2-abs-pitch" },
      { IPATCH_UNIT_TYPE_SF2_OFS_PITCH, "IPATCH_UNIT_TYPE_SF2_OFS_PITCH", "sf2-ofs-pitch" },
      { IPATCH_UNIT_TYPE_SF2_ABS_TIME, "IPATCH_UNIT_TYPE_SF2_ABS_TIME", "sf2-abs-time" },
      { IPATCH_UNIT_TYPE_SF2_OFS_TIME, "IPATCH_UNIT_TYPE_SF2_OFS_TIME", "sf2-ofs-time" },
      { IPATCH_UNIT_TYPE_CENTIBELS, "IPATCH_UNIT_TYPE_CENTIBELS", "centibels" },
      { IPATCH_UNIT_TYPE_32K_SAMPLES, "IPATCH_UNIT_TYPE_32K_SAMPLES", "32k-samples" },
      { IPATCH_UNIT_TYPE_TENTH_PERCENT, "IPATCH_UNIT_TYPE_TENTH_PERCENT", "tenth-percent" },
      { 0, NULL, NULL }
    };
    etype = g_enum_register_static ("IpatchUnitType", values);
  }
  return etype;
}
GType
ipatch_unit_class_type_get_type (void)
{
  static GType etype = 0;
  if (etype == 0) {
    static const GEnumValue values[] = {
      { IPATCH_UNIT_CLASS_NONE, "IPATCH_UNIT_CLASS_NONE", "none" },
      { IPATCH_UNIT_CLASS_USER, "IPATCH_UNIT_CLASS_USER", "user" },
      { IPATCH_UNIT_CLASS_DLS, "IPATCH_UNIT_CLASS_DLS", "dls" },
      { IPATCH_UNIT_CLASS_COUNT, "IPATCH_UNIT_CLASS_COUNT", "count" },
      { 0, NULL, NULL }
    };
    etype = g_enum_register_static ("IpatchUnitClassType", values);
  }
  return etype;
}

/* enumerations from "IpatchVBankRegion.h" */
GType
ipatch_vbank_region_note_range_mode_get_type (void)
{
  static GType etype = 0;
  if (etype == 0) {
    static const GEnumValue values[] = {
      { IPATCH_VBANK_REGION_NOTE_RANGE_MODE_INTERSECT, "IPATCH_VBANK_REGION_NOTE_RANGE_MODE_INTERSECT", "intersect" },
      { IPATCH_VBANK_REGION_NOTE_RANGE_MODE_OVERRIDE, "IPATCH_VBANK_REGION_NOTE_RANGE_MODE_OVERRIDE", "override" },
      { 0, NULL, NULL }
    };
    etype = g_enum_register_static ("IpatchVBankRegionNoteRangeMode", values);
  }
  return etype;
}
GType
ipatch_vbank_region_root_note_mode_get_type (void)
{
  static GType etype = 0;
  if (etype == 0) {
    static const GEnumValue values[] = {
      { IPATCH_VBANK_REGION_ROOT_NOTE_MODE_OFFSET, "IPATCH_VBANK_REGION_ROOT_NOTE_MODE_OFFSET", "offset" },
      { IPATCH_VBANK_REGION_ROOT_NOTE_MODE_OVERRIDE, "IPATCH_VBANK_REGION_ROOT_NOTE_MODE_OVERRIDE", "override" },
      { 0, NULL, NULL }
    };
    etype = g_enum_register_static ("IpatchVBankRegionRootNoteMode", values);
  }
  return etype;
}

/* enumerations from "misc.h" */
GType
ipatch_error_get_type (void)
{
  static GType etype = 0;
  if (etype == 0) {
    static const GEnumValue values[] = {
      { IPATCH_ERROR_FAIL, "IPATCH_ERROR_FAIL", "fail" },
      { IPATCH_ERROR_IO, "IPATCH_ERROR_IO", "io" },
      { IPATCH_ERROR_PROGRAM, "IPATCH_ERROR_PROGRAM", "program" },
      { IPATCH_ERROR_INVALID, "IPATCH_ERROR_INVALID", "invalid" },
      { IPATCH_ERROR_CORRUPT, "IPATCH_ERROR_CORRUPT", "corrupt" },
      { IPATCH_ERROR_NOMEM, "IPATCH_ERROR_NOMEM", "nomem" },
      { IPATCH_ERROR_UNSUPPORTED, "IPATCH_ERROR_UNSUPPORTED", "unsupported" },
      { IPATCH_ERROR_UNEXPECTED_EOF, "IPATCH_ERROR_UNEXPECTED_EOF", "unexpected-eof" },
      { IPATCH_ERROR_UNHANDLED_CONVERSION, "IPATCH_ERROR_UNHANDLED_CONVERSION", "unhandled-conversion" },
      { IPATCH_ERROR_BUSY, "IPATCH_ERROR_BUSY", "busy" },
	  { 0, NULL, NULL }
    };
    etype = g_enum_register_static ("IpatchError", values);
  }
  return etype;
}

/* enumerations from "sample.h" */
GType
ipatch_sample_width_get_type (void)
{
  static GType etype = 0;
  if (etype == 0) {
    static const GEnumValue values[] = {
      { IPATCH_SAMPLE_INVALID, "IPATCH_SAMPLE_INVALID", "invalid" },
      { IPATCH_SAMPLE_8BIT, "IPATCH_SAMPLE_8BIT", "8bit" },
      { IPATCH_SAMPLE_16BIT, "IPATCH_SAMPLE_16BIT", "16bit" },
      { IPATCH_SAMPLE_24BIT, "IPATCH_SAMPLE_24BIT", "24bit" },
      { IPATCH_SAMPLE_32BIT, "IPATCH_SAMPLE_32BIT", "32bit" },
      { IPATCH_SAMPLE_FLOAT, "IPATCH_SAMPLE_FLOAT", "float" },
      { IPATCH_SAMPLE_DOUBLE, "IPATCH_SAMPLE_DOUBLE", "double" },
      { IPATCH_SAMPLE_REAL24BIT, "IPATCH_SAMPLE_REAL24BIT", "real24bit" },
      { 0, NULL, NULL }
    };
    etype = g_enum_register_static ("IpatchSampleWidth", values);
  }
  return etype;
}
GType
ipatch_sample_channel_get_type (void)
{
  static GType etype = 0;
  if (etype == 0) {
    static const GFlagsValue values[] = {
      { IPATCH_SAMPLE_MONO, "IPATCH_SAMPLE_MONO", "mono" },
      { IPATCH_SAMPLE_STEREO, "IPATCH_SAMPLE_STEREO", "stereo" },
      { 0, NULL, NULL }
    };
    etype = g_flags_register_static ("IpatchSampleChannel", values);
  }
  return etype;
}
GType
ipatch_sample_channel_type_get_type (void)
{
  static GType etype = 0;
  if (etype == 0) {
    static const GEnumValue values[] = {
      { IPATCH_SAMPLE_LEFT, "IPATCH_SAMPLE_LEFT", "left" },
      { IPATCH_SAMPLE_RIGHT, "IPATCH_SAMPLE_RIGHT", "right" },
      { 0, NULL, NULL }
    };
    etype = g_enum_register_static ("IpatchSampleChannelType", values);
  }
  return etype;
}
GType
ipatch_sample_sign_get_type (void)
{
  static GType etype = 0;
  if (etype == 0) {
    static const GFlagsValue values[] = {
      { IPATCH_SAMPLE_SIGNED, "IPATCH_SAMPLE_SIGNED", "signed" },
      { IPATCH_SAMPLE_UNSIGNED, "IPATCH_SAMPLE_UNSIGNED", "unsigned" },
      { 0, NULL, NULL }
    };
    etype = g_flags_register_static ("IpatchSampleSign", values);
  }
  return etype;
}
GType
ipatch_sample_endian_get_type (void)
{
  static GType etype = 0;
  if (etype == 0) {
    static const GFlagsValue values[] = {
      { IPATCH_SAMPLE_LENDIAN, "IPATCH_SAMPLE_LENDIAN", "lendian" },
      { IPATCH_SAMPLE_BENDIAN, "IPATCH_SAMPLE_BENDIAN", "bendian" },
      { 0, NULL, NULL }
    };
    etype = g_flags_register_static ("IpatchSampleEndian", values);
  }
  return etype;
}

/* Generated data ends here */

