#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_72__   TYPE_9__ ;
typedef  struct TYPE_71__   TYPE_8__ ;
typedef  struct TYPE_70__   TYPE_7__ ;
typedef  struct TYPE_69__   TYPE_6__ ;
typedef  struct TYPE_68__   TYPE_5__ ;
typedef  struct TYPE_67__   TYPE_4__ ;
typedef  struct TYPE_66__   TYPE_3__ ;
typedef  struct TYPE_65__   TYPE_2__ ;
typedef  struct TYPE_64__   TYPE_20__ ;
typedef  struct TYPE_63__   TYPE_1__ ;
typedef  struct TYPE_62__   TYPE_18__ ;
typedef  struct TYPE_61__   TYPE_17__ ;
typedef  struct TYPE_60__   TYPE_16__ ;
typedef  struct TYPE_59__   TYPE_15__ ;
typedef  struct TYPE_58__   TYPE_14__ ;
typedef  struct TYPE_57__   TYPE_13__ ;
typedef  struct TYPE_56__   TYPE_12__ ;
typedef  struct TYPE_55__   TYPE_11__ ;
typedef  struct TYPE_54__   TYPE_10__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  val ;
struct TYPE_58__ {size_t unique_id; char num_blue_values; size_t blue_fuzz; size_t blue_shift; char num_other_blues; char num_family_blues; char num_family_other_blues; char num_snap_widths; char num_snap_heights; int round_stem_up; int force_bold; size_t lenIV; scalar_t__ password; scalar_t__ language_group; int /*<<< orphan*/ * min_feature; int /*<<< orphan*/ * snap_heights; int /*<<< orphan*/ * snap_widths; int /*<<< orphan*/ * family_other_blues; int /*<<< orphan*/ * family_blues; int /*<<< orphan*/ * other_blues; int /*<<< orphan*/  blue_scale; int /*<<< orphan*/ * blue_values; int /*<<< orphan*/ * standard_height; int /*<<< orphan*/ * standard_width; } ;
struct TYPE_66__ {int /*<<< orphan*/  yy; int /*<<< orphan*/  yx; int /*<<< orphan*/  xy; int /*<<< orphan*/  xx; } ;
struct TYPE_59__ {int is_fixed_pitch; char const* version; char const* notice; char const* full_name; char const* family_name; char const* weight; scalar_t__ italic_angle; int /*<<< orphan*/  underline_thickness; int /*<<< orphan*/  underline_position; } ;
struct TYPE_60__ {int /*<<< orphan*/  fs_type; } ;
struct TYPE_65__ {char const** char_name; scalar_t__ num_chars; } ;
struct TYPE_63__ {int /*<<< orphan*/  yMax; int /*<<< orphan*/  xMax; int /*<<< orphan*/  yMin; int /*<<< orphan*/  xMin; } ;
struct TYPE_72__ {size_t num_glyphs; char** glyph_names; char const* font_name; char font_type; char paint_type; size_t num_subrs; TYPE_14__ private_dict; scalar_t__* charstrings_len; scalar_t__* charstrings; int /*<<< orphan*/  font_offset; TYPE_3__ font_matrix; TYPE_15__ font_info; TYPE_16__ font_extra; scalar_t__* subrs; int /*<<< orphan*/ * subrs_len; int /*<<< orphan*/  subrs_hash; TYPE_2__ encoding; int /*<<< orphan*/  encoding_type; TYPE_1__ font_bbox; } ;
struct TYPE_71__ {int /*<<< orphan*/  hint; } ;
struct TYPE_68__ {char* cursor; char* limit; void* error; int /*<<< orphan*/  memory; } ;
struct TYPE_69__ {TYPE_5__ root; } ;
struct TYPE_70__ {int keywords_encountered; int /*<<< orphan*/  subrs_hash; int /*<<< orphan*/  subrs; int /*<<< orphan*/  swap_table; int /*<<< orphan*/  glyph_names; int /*<<< orphan*/  charstrings; int /*<<< orphan*/  encoding_table; TYPE_6__ parser; } ;
struct TYPE_67__ {scalar_t__ glyph; scalar_t__ metrics_only; scalar_t__ face; } ;
struct TYPE_64__ {size_t length; scalar_t__ pointer; } ;
struct TYPE_62__ {int /*<<< orphan*/  (* t1_make_subfont ) (int /*<<< orphan*/ ,TYPE_14__*,int /*<<< orphan*/ *) ;int /*<<< orphan*/  (* ps_decoder_init ) (TYPE_17__*,TYPE_13__*,int) ;TYPE_12__* t1_decoder_funcs; } ;
struct TYPE_61__ {int /*<<< orphan*/ * current_subfont; } ;
struct TYPE_57__ {TYPE_4__ builder; int /*<<< orphan*/  font_offset; TYPE_3__ font_matrix; } ;
struct TYPE_56__ {void* (* parse_charstrings ) (TYPE_17__*,char*,size_t) ;void* (* parse_metrics ) (TYPE_13__*,char*,int) ;} ;
struct TYPE_55__ {TYPE_9__ type1; int /*<<< orphan*/  psaux; } ;
struct TYPE_54__ {int const dict; scalar_t__ ident; } ;
typedef  TYPE_6__* T1_Parser ;
typedef  TYPE_7__* T1_Loader ;
typedef  TYPE_8__* T1_GlyphSlot ;
typedef  TYPE_9__* T1_Font ;
typedef  TYPE_10__* T1_Field ;
typedef  TYPE_11__* T1_Face ;
typedef  int /*<<< orphan*/  T1_EncodingType ;
typedef  TYPE_12__* T1_Decoder_Funcs ;
typedef  TYPE_13__* T1_Decoder ;
typedef  TYPE_14__ PS_PrivateRec ;
typedef  TYPE_15__ PS_FontInfoRec ;
typedef  TYPE_16__ PS_FontExtraRec ;
typedef  int PS_Dict_Keys ;
typedef  TYPE_17__ PS_Decoder ;
typedef  TYPE_18__* PSAux_Service ;
typedef  int /*<<< orphan*/  FT_UShort ;
typedef  size_t FT_ULong ;
typedef  int FT_UInt ;
typedef  char const FT_String ;
typedef  int /*<<< orphan*/  FT_Short ;
typedef  int /*<<< orphan*/  FT_Memory ;
typedef  scalar_t__ FT_Long ;
typedef  size_t FT_Int ;
typedef  int /*<<< orphan*/  FT_Fixed ;
typedef  TYPE_11__* FT_Face ;
typedef  void* FT_Error ;
typedef  TYPE_20__ FT_Data ;
typedef  int /*<<< orphan*/  FT_Char ;
typedef  char FT_Byte ;
typedef  int FT_Bool ;
typedef  int /*<<< orphan*/  CFF_SubFontRec ;

/* Variables and functions */
 int /*<<< orphan*/  FALSE ; 
 scalar_t__ FT_ERR_EQ (void*,int /*<<< orphan*/ ) ; 
 void* FT_Err_Ok ; 
 int /*<<< orphan*/  FT_FACE (TYPE_11__*) ; 
 int /*<<< orphan*/  FT_FREE (int /*<<< orphan*/ ) ; 
 void* FT_THROW (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  FT_TRACE1 (char*) ; 
 int /*<<< orphan*/  FT_UNUSED (TYPE_11__*) ; 
 int /*<<< orphan*/  FT_ZERO (TYPE_7__*) ; 
 int /*<<< orphan*/  Glyph_Too_Big ; 
 int /*<<< orphan*/  IS_INCREMENTAL ; 
 scalar_t__ IS_PS_TOKEN (char*,char*,char*) ; 
 int /*<<< orphan*/  Ignore ; 
 int /*<<< orphan*/  Invalid_File_Format ; 
#define  PS_DICT_BLUE_FUZZ 173 
#define  PS_DICT_BLUE_SCALE 172 
#define  PS_DICT_BLUE_SHIFT 171 
#define  PS_DICT_BLUE_VALUE 170 
#define  PS_DICT_CHAR_STRING 169 
#define  PS_DICT_CHAR_STRING_KEY 168 
#define  PS_DICT_ENCODING_ENTRY 167 
#define  PS_DICT_ENCODING_TYPE 166 
#define  PS_DICT_FAMILY_BLUE 165 
#define  PS_DICT_FAMILY_NAME 164 
#define  PS_DICT_FAMILY_OTHER_BLUE 163 
#define  PS_DICT_FONT_BBOX 162 
#define  PS_DICT_FONT_MATRIX 161 
#define  PS_DICT_FONT_NAME 160 
#define  PS_DICT_FONT_TYPE 159 
#define  PS_DICT_FORCE_BOLD 158 
#define  PS_DICT_FS_TYPE 157 
#define  PS_DICT_FULL_NAME 156 
#define  PS_DICT_IS_FIXED_PITCH 155 
#define  PS_DICT_ITALIC_ANGLE 154 
#define  PS_DICT_LANGUAGE_GROUP 153 
#define  PS_DICT_LEN_IV 152 
#define  PS_DICT_MIN_FEATURE 151 
#define  PS_DICT_NOTICE 150 
#define  PS_DICT_NUM_BLUE_VALUES 149 
#define  PS_DICT_NUM_CHAR_STRINGS 148 
#define  PS_DICT_NUM_FAMILY_BLUES 147 
#define  PS_DICT_NUM_FAMILY_OTHER_BLUES 146 
#define  PS_DICT_NUM_OTHER_BLUES 145 
#define  PS_DICT_NUM_STEM_SNAP_H 144 
#define  PS_DICT_NUM_STEM_SNAP_V 143 
#define  PS_DICT_NUM_SUBRS 142 
#define  PS_DICT_OTHER_BLUE 141 
#define  PS_DICT_PAINT_TYPE 140 
#define  PS_DICT_PASSWORD 139 
#define  PS_DICT_RND_STEM_UP 138 
#define  PS_DICT_STD_HW 137 
#define  PS_DICT_STD_VW 136 
#define  PS_DICT_STEM_SNAP_H 135 
#define  PS_DICT_STEM_SNAP_V 134 
#define  PS_DICT_SUBR 133 
#define  PS_DICT_UNDERLINE_POSITION 132 
#define  PS_DICT_UNDERLINE_THICKNESS 131 
#define  PS_DICT_UNIQUE_ID 130 
#define  PS_DICT_VERSION 129 
#define  PS_DICT_WEIGHT 128 
 int /*<<< orphan*/  T1_ENCODING_TYPE_ARRAY ; 
 int T1_FIELD_DICT_FONTDICT ; 
 int T1_FIELD_DICT_PRIVATE ; 
 int T1_FONTDIR_AFTER_PRIVATE ; 
 int /*<<< orphan*/  T1_Finalize_Parser (TYPE_6__*) ; 
 int T1_PRIVATE ; 
 int /*<<< orphan*/  T1_Release_Table (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  T1_Skip_PS_Token (TYPE_6__*) ; 
 int /*<<< orphan*/  T1_Skip_Spaces (TYPE_6__*) ; 
 int TRUE ; 
 int /*<<< orphan*/  ft_hash_num_free (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 size_t* ft_hash_num_lookup (size_t,int /*<<< orphan*/ ) ; 
 scalar_t__ ft_isdigit (char) ; 
 scalar_t__ ft_memcmp (char*,char*,int) ; 
 int /*<<< orphan*/  ft_memcpy (void*,void*,size_t) ; 
 scalar_t__ ft_strcmp (char const*,char const*) ; 
 int ft_strlen (char const*) ; 
 int /*<<< orphan*/  read_binary_data (TYPE_6__*,size_t*,char**,int /*<<< orphan*/ ) ; 
 void* stub1 (TYPE_13__*,char*,int) ; 
 int /*<<< orphan*/  stub2 (TYPE_17__*,TYPE_13__*,int) ; 
 int /*<<< orphan*/  stub3 (int /*<<< orphan*/ ,TYPE_14__*,int /*<<< orphan*/ *) ; 
 void* stub4 (TYPE_17__*,char*,size_t) ; 
 void* stub5 (TYPE_17__*,char*,size_t) ; 
 int /*<<< orphan*/  t1_keywords ; 
 void* t1_load_keyword (TYPE_11__*,TYPE_7__*,TYPE_10__*) ; 

__attribute__((used)) static FT_UInt
  t1_get_name_index( T1_Face     face,
                     FT_String*  glyph_name )
  {
    FT_Int  i;


    for ( i = 0; i < face->type1.num_glyphs; i++ )
    {
      FT_String*  gname = face->type1.glyph_names[i];


      if ( !ft_strcmp( glyph_name, gname ) )
        return (FT_UInt)i;
    }

    return 0;
  }

__attribute__((used)) static const char*
  t1_get_ps_name( T1_Face  face )
  {
    return (const char*) face->type1.font_name;
  }

__attribute__((used)) static FT_Error
  t1_ps_get_font_info( FT_Face          face,
                       PS_FontInfoRec*  afont_info )
  {
    *afont_info = ((T1_Face)face)->type1.font_info;

    return FT_Err_Ok;
  }

__attribute__((used)) static FT_Error
  t1_ps_get_font_extra( FT_Face           face,
                        PS_FontExtraRec*  afont_extra )
  {
    *afont_extra = ((T1_Face)face)->type1.font_extra;

    return FT_Err_Ok;
  }

__attribute__((used)) static FT_Int
  t1_ps_has_glyph_names( FT_Face  face )
  {
    FT_UNUSED( face );

    return 1;
  }

__attribute__((used)) static FT_Error
  t1_ps_get_font_private( FT_Face         face,
                          PS_PrivateRec*  afont_private )
  {
    *afont_private = ((T1_Face)face)->type1.private_dict;

    return FT_Err_Ok;
  }

__attribute__((used)) static FT_Long
  t1_ps_get_font_value( FT_Face       face,
                        PS_Dict_Keys  key,
                        FT_UInt       idx,
                        void         *value,
                        FT_Long       value_len_ )
  {
    FT_ULong  retval    = 0; /* always >= 1 if valid */
    FT_ULong  value_len = value_len_ < 0 ? 0 : (FT_ULong)value_len_;

    T1_Face  t1face = (T1_Face)face;
    T1_Font  type1  = &t1face->type1;


    switch ( key )
    {
    case PS_DICT_FONT_TYPE:
      retval = sizeof ( type1->font_type );
      if ( value && value_len >= retval )
        *((FT_Byte *)value) = type1->font_type;
      break;

    case PS_DICT_FONT_MATRIX:
      if ( idx < sizeof ( type1->font_matrix ) /
                   sizeof ( type1->font_matrix.xx ) )
      {
        FT_Fixed  val = 0;


        retval = sizeof ( val );
        if ( value && value_len >= retval )
        {
          switch ( idx )
          {
          case 0:
            val = type1->font_matrix.xx;
            break;
          case 1:
            val = type1->font_matrix.xy;
            break;
          case 2:
            val = type1->font_matrix.yx;
            break;
          case 3:
            val = type1->font_matrix.yy;
            break;
          }
          *((FT_Fixed *)value) = val;
        }
      }
      break;

    case PS_DICT_FONT_BBOX:
      if ( idx < sizeof ( type1->font_bbox ) /
                   sizeof ( type1->font_bbox.xMin ) )
      {
        FT_Fixed  val = 0;


        retval = sizeof ( val );
        if ( value && value_len >= retval )
        {
          switch ( idx )
          {
          case 0:
            val = type1->font_bbox.xMin;
            break;
          case 1:
            val = type1->font_bbox.yMin;
            break;
          case 2:
            val = type1->font_bbox.xMax;
            break;
          case 3:
            val = type1->font_bbox.yMax;
            break;
          }
          *((FT_Fixed *)value) = val;
        }
      }
      break;

    case PS_DICT_PAINT_TYPE:
      retval = sizeof ( type1->paint_type );
      if ( value && value_len >= retval )
        *((FT_Byte *)value) = type1->paint_type;
      break;

    case PS_DICT_FONT_NAME:
      retval = ft_strlen( type1->font_name ) + 1;
      if ( value && value_len >= retval )
        ft_memcpy( value, (void *)( type1->font_name ), retval );
      break;

    case PS_DICT_UNIQUE_ID:
      retval = sizeof ( type1->private_dict.unique_id );
      if ( value && value_len >= retval )
        *((FT_Int *)value) = type1->private_dict.unique_id;
      break;

    case PS_DICT_NUM_CHAR_STRINGS:
      retval = sizeof ( type1->num_glyphs );
      if ( value && value_len >= retval )
        *((FT_Int *)value) = type1->num_glyphs;
      break;

    case PS_DICT_CHAR_STRING_KEY:
      if ( idx < (FT_UInt)type1->num_glyphs )
      {
        retval = ft_strlen( type1->glyph_names[idx] ) + 1;
        if ( value && value_len >= retval )
        {
          ft_memcpy( value, (void *)( type1->glyph_names[idx] ), retval );
          ((FT_Char *)value)[retval - 1] = (FT_Char)'\0';
        }
      }
      break;

    case PS_DICT_CHAR_STRING:
      if ( idx < (FT_UInt)type1->num_glyphs )
      {
        retval = type1->charstrings_len[idx] + 1;
        if ( value && value_len >= retval )
        {
          ft_memcpy( value, (void *)( type1->charstrings[idx] ),
                     retval - 1 );
          ((FT_Char *)value)[retval - 1] = (FT_Char)'\0';
        }
      }
      break;

    case PS_DICT_ENCODING_TYPE:
      retval = sizeof ( type1->encoding_type );
      if ( value && value_len >= retval )
        *((T1_EncodingType *)value) = type1->encoding_type;
      break;

    case PS_DICT_ENCODING_ENTRY:
      if ( type1->encoding_type == T1_ENCODING_TYPE_ARRAY &&
           idx < (FT_UInt)type1->encoding.num_chars       )
      {
        retval = ft_strlen( type1->encoding.char_name[idx] ) + 1;
        if ( value && value_len >= retval )
        {
          ft_memcpy( value, (void *)( type1->encoding.char_name[idx] ),
                     retval - 1 );
          ((FT_Char *)value)[retval - 1] = (FT_Char)'\0';
        }
      }
      break;

    case PS_DICT_NUM_SUBRS:
      retval = sizeof ( type1->num_subrs );
      if ( value && value_len >= retval )
        *((FT_Int *)value) = type1->num_subrs;
      break;

    case PS_DICT_SUBR:
      {
        FT_Bool  ok = 0;


        if ( type1->subrs_hash )
        {
          /* convert subr index to array index */
          size_t*  val = ft_hash_num_lookup( (FT_Int)idx,
                                             type1->subrs_hash );


          if ( val )
          {
            idx = *val;
            ok  = 1;
          }
        }
        else
        {
          if ( idx < (FT_UInt)type1->num_subrs )
            ok = 1;
        }

        if ( ok )
        {
          retval = type1->subrs_len[idx] + 1;
          if ( value && value_len >= retval )
          {
            ft_memcpy( value, (void *)( type1->subrs[idx] ), retval - 1 );
            ((FT_Char *)value)[retval - 1] = (FT_Char)'\0';
          }
        }
      }
      break;

    case PS_DICT_STD_HW:
      retval = sizeof ( type1->private_dict.standard_width[0] );
      if ( value && value_len >= retval )
        *((FT_UShort *)value) = type1->private_dict.standard_width[0];
      break;

    case PS_DICT_STD_VW:
      retval = sizeof ( type1->private_dict.standard_height[0] );
      if ( value && value_len >= retval )
        *((FT_UShort *)value) = type1->private_dict.standard_height[0];
      break;

    case PS_DICT_NUM_BLUE_VALUES:
      retval = sizeof ( type1->private_dict.num_blue_values );
      if ( value && value_len >= retval )
        *((FT_Byte *)value) = type1->private_dict.num_blue_values;
      break;

    case PS_DICT_BLUE_VALUE:
      if ( idx < type1->private_dict.num_blue_values )
      {
        retval = sizeof ( type1->private_dict.blue_values[idx] );
        if ( value && value_len >= retval )
          *((FT_Short *)value) = type1->private_dict.blue_values[idx];
      }
      break;

    case PS_DICT_BLUE_SCALE:
      retval = sizeof ( type1->private_dict.blue_scale );
      if ( value && value_len >= retval )
        *((FT_Fixed *)value) = type1->private_dict.blue_scale;
      break;

    case PS_DICT_BLUE_FUZZ:
      retval = sizeof ( type1->private_dict.blue_fuzz );
      if ( value && value_len >= retval )
        *((FT_Int *)value) = type1->private_dict.blue_fuzz;
      break;

    case PS_DICT_BLUE_SHIFT:
      retval = sizeof ( type1->private_dict.blue_shift );
      if ( value && value_len >= retval )
        *((FT_Int *)value) = type1->private_dict.blue_shift;
      break;

    case PS_DICT_NUM_OTHER_BLUES:
      retval = sizeof ( type1->private_dict.num_other_blues );
      if ( value && value_len >= retval )
        *((FT_Byte *)value) = type1->private_dict.num_other_blues;
      break;

    case PS_DICT_OTHER_BLUE:
      if ( idx < type1->private_dict.num_other_blues )
      {
        retval = sizeof ( type1->private_dict.other_blues[idx] );
        if ( value && value_len >= retval )
          *((FT_Short *)value) = type1->private_dict.other_blues[idx];
      }
      break;

    case PS_DICT_NUM_FAMILY_BLUES:
      retval = sizeof ( type1->private_dict.num_family_blues );
      if ( value && value_len >= retval )
        *((FT_Byte *)value) = type1->private_dict.num_family_blues;
      break;

    case PS_DICT_FAMILY_BLUE:
      if ( idx < type1->private_dict.num_family_blues )
      {
        retval = sizeof ( type1->private_dict.family_blues[idx] );
        if ( value && value_len >= retval )
          *((FT_Short *)value) = type1->private_dict.family_blues[idx];
      }
      break;

    case PS_DICT_NUM_FAMILY_OTHER_BLUES:
      retval = sizeof ( type1->private_dict.num_family_other_blues );
      if ( value && value_len >= retval )
        *((FT_Byte *)value) = type1->private_dict.num_family_other_blues;
      break;

    case PS_DICT_FAMILY_OTHER_BLUE:
      if ( idx < type1->private_dict.num_family_other_blues )
      {
        retval = sizeof ( type1->private_dict.family_other_blues[idx] );
        if ( value && value_len >= retval )
          *((FT_Short *)value) = type1->private_dict.family_other_blues[idx];
      }
      break;

    case PS_DICT_NUM_STEM_SNAP_H:
      retval = sizeof ( type1->private_dict.num_snap_widths );
      if ( value && value_len >= retval )
        *((FT_Byte *)value) = type1->private_dict.num_snap_widths;
      break;

    case PS_DICT_STEM_SNAP_H:
      if ( idx < type1->private_dict.num_snap_widths )
      {
        retval = sizeof ( type1->private_dict.snap_widths[idx] );
        if ( value && value_len >= retval )
          *((FT_Short *)value) = type1->private_dict.snap_widths[idx];
      }
      break;

    case PS_DICT_NUM_STEM_SNAP_V:
      retval = sizeof ( type1->private_dict.num_snap_heights );
      if ( value && value_len >= retval )
        *((FT_Byte *)value) = type1->private_dict.num_snap_heights;
      break;

    case PS_DICT_STEM_SNAP_V:
      if ( idx < type1->private_dict.num_snap_heights )
      {
        retval = sizeof ( type1->private_dict.snap_heights[idx] );
        if ( value && value_len >= retval )
          *((FT_Short *)value) = type1->private_dict.snap_heights[idx];
      }
      break;

    case PS_DICT_RND_STEM_UP:
      retval = sizeof ( type1->private_dict.round_stem_up );
      if ( value && value_len >= retval )
        *((FT_Bool *)value) = type1->private_dict.round_stem_up;
      break;

    case PS_DICT_FORCE_BOLD:
      retval = sizeof ( type1->private_dict.force_bold );
      if ( value && value_len >= retval )
        *((FT_Bool *)value) = type1->private_dict.force_bold;
      break;

    case PS_DICT_MIN_FEATURE:
      if ( idx < sizeof ( type1->private_dict.min_feature ) /
                   sizeof ( type1->private_dict.min_feature[0] ) )
      {
        retval = sizeof ( type1->private_dict.min_feature[idx] );
        if ( value && value_len >= retval )
          *((FT_Short *)value) = type1->private_dict.min_feature[idx];
      }
      break;

    case PS_DICT_LEN_IV:
      retval = sizeof ( type1->private_dict.lenIV );
      if ( value && value_len >= retval )
        *((FT_Int *)value) = type1->private_dict.lenIV;
      break;

    case PS_DICT_PASSWORD:
      retval = sizeof ( type1->private_dict.password );
      if ( value && value_len >= retval )
        *((FT_Long *)value) = type1->private_dict.password;
      break;

    case PS_DICT_LANGUAGE_GROUP:
      retval = sizeof ( type1->private_dict.language_group );
      if ( value && value_len >= retval )
        *((FT_Long *)value) = type1->private_dict.language_group;
      break;

    case PS_DICT_IS_FIXED_PITCH:
      retval = sizeof ( type1->font_info.is_fixed_pitch );
      if ( value && value_len >= retval )
        *((FT_Bool *)value) = type1->font_info.is_fixed_pitch;
      break;

    case PS_DICT_UNDERLINE_POSITION:
      retval = sizeof ( type1->font_info.underline_position );
      if ( value && value_len >= retval )
        *((FT_Short *)value) = type1->font_info.underline_position;
      break;

    case PS_DICT_UNDERLINE_THICKNESS:
      retval = sizeof ( type1->font_info.underline_thickness );
      if ( value && value_len >= retval )
        *((FT_UShort *)value) = type1->font_info.underline_thickness;
      break;

    case PS_DICT_FS_TYPE:
      retval = sizeof ( type1->font_extra.fs_type );
      if ( value && value_len >= retval )
        *((FT_UShort *)value) = type1->font_extra.fs_type;
      break;

    case PS_DICT_VERSION:
      retval = ft_strlen( type1->font_info.version ) + 1;
      if ( value && value_len >= retval )
        ft_memcpy( value, (void *)( type1->font_info.version ), retval );
      break;

    case PS_DICT_NOTICE:
      retval = ft_strlen( type1->font_info.notice ) + 1;
      if ( value && value_len >= retval )
        ft_memcpy( value, (void *)( type1->font_info.notice ), retval );
      break;

    case PS_DICT_FULL_NAME:
      retval = ft_strlen( type1->font_info.full_name ) + 1;
      if ( value && value_len >= retval )
        ft_memcpy( value, (void *)( type1->font_info.full_name ), retval );
      break;

    case PS_DICT_FAMILY_NAME:
      retval = ft_strlen( type1->font_info.family_name ) + 1;
      if ( value && value_len >= retval )
        ft_memcpy( value, (void *)( type1->font_info.family_name ), retval );
      break;

    case PS_DICT_WEIGHT:
      retval = ft_strlen( type1->font_info.weight ) + 1;
      if ( value && value_len >= retval )
        ft_memcpy( value, (void *)( type1->font_info.weight ), retval );
      break;

    case PS_DICT_ITALIC_ANGLE:
      retval = sizeof ( type1->font_info.italic_angle );
      if ( value && value_len >= retval )
        *((FT_Long *)value) = type1->font_info.italic_angle;
      break;
    }

    return retval == 0 ? -1 : (FT_Long)retval;
  }

__attribute__((used)) static FT_Error
  T1_Parse_Glyph_And_Get_Char_String( T1_Decoder  decoder,
                                      FT_UInt     glyph_index,
                                      FT_Data*    char_string,
                                      FT_Bool*    force_scaling )
  {
    T1_Face   face  = (T1_Face)decoder->builder.face;
    T1_Font   type1 = &face->type1;
    FT_Error  error = FT_Err_Ok;

    PSAux_Service           psaux         = (PSAux_Service)face->psaux;
    const T1_Decoder_Funcs  decoder_funcs = psaux->t1_decoder_funcs;
    PS_Decoder              psdecoder;

#ifdef FT_CONFIG_OPTION_INCREMENTAL
    FT_Incremental_InterfaceRec *inc =
                      face->root.internal->incremental_interface;
#endif

#ifdef T1_CONFIG_OPTION_OLD_ENGINE
    PS_Driver  driver = (PS_Driver)FT_FACE_DRIVER( face );
#endif

    decoder->font_matrix = type1->font_matrix;
    decoder->font_offset = type1->font_offset;

#ifdef FT_CONFIG_OPTION_INCREMENTAL

    /* For incremental fonts get the character data using the */
    /* callback function.                                     */
    if ( inc )
      error = inc->funcs->get_glyph_data( inc->object,
                                          glyph_index, char_string );
    else

#endif /* FT_CONFIG_OPTION_INCREMENTAL */

    /* For ordinary fonts get the character data stored in the face record. */
    {
      char_string->pointer = type1->charstrings[glyph_index];
      char_string->length  = (FT_Int)type1->charstrings_len[glyph_index];
    }

    if ( !error )
    {
      /* choose which renderer to use */
#ifdef T1_CONFIG_OPTION_OLD_ENGINE
      if ( driver->hinting_engine == FT_HINTING_FREETYPE ||
           decoder->builder.metrics_only                 )
        error = decoder_funcs->parse_charstrings_old(
                  decoder,
                  (FT_Byte*)char_string->pointer,
                  (FT_UInt)char_string->length );
#else
      if ( decoder->builder.metrics_only )
        error = decoder_funcs->parse_metrics(
                  decoder,
                  (FT_Byte*)char_string->pointer,
                  (FT_UInt)char_string->length );
#endif
      else
      {
        CFF_SubFontRec  subfont;


        psaux->ps_decoder_init( &psdecoder, decoder, TRUE );

        psaux->t1_make_subfont( FT_FACE( face ),
                                &face->type1.private_dict, &subfont );
        psdecoder.current_subfont = &subfont;

        error = decoder_funcs->parse_charstrings(
                  &psdecoder,
                  (FT_Byte*)char_string->pointer,
                  (FT_ULong)char_string->length );

        /* Adobe's engine uses 16.16 numbers everywhere;              */
        /* as a consequence, glyphs larger than 2000ppem get rejected */
        if ( FT_ERR_EQ( error, Glyph_Too_Big ) )
        {
          /* this time, we retry unhinted and scale up the glyph later on */
          /* (the engine uses and sets the hardcoded value 0x10000 / 64 = */
          /* 0x400 for both `x_scale' and `y_scale' in this case)         */
          ((T1_GlyphSlot)decoder->builder.glyph)->hint = FALSE;

          *force_scaling = TRUE;

          error = decoder_funcs->parse_charstrings(
                    &psdecoder,
                    (FT_Byte*)char_string->pointer,
                    (FT_ULong)char_string->length );
        }
      }
    }

#ifdef FT_CONFIG_OPTION_INCREMENTAL

    /* Incremental fonts can optionally override the metrics. */
    if ( !error && inc && inc->funcs->get_glyph_metrics )
    {
      FT_Incremental_MetricsRec  metrics;


      metrics.bearing_x = FIXED_TO_INT( decoder->builder.left_bearing.x );
      metrics.bearing_y = 0;
      metrics.advance   = FIXED_TO_INT( decoder->builder.advance.x );
      metrics.advance_v = FIXED_TO_INT( decoder->builder.advance.y );

      error = inc->funcs->get_glyph_metrics( inc->object,
                                             glyph_index, FALSE, &metrics );

      decoder->builder.left_bearing.x = INT_TO_FIXED( metrics.bearing_x );
      decoder->builder.advance.x      = INT_TO_FIXED( metrics.advance );
      decoder->builder.advance.y      = INT_TO_FIXED( metrics.advance_v );
    }

#endif /* FT_CONFIG_OPTION_INCREMENTAL */

    return error;
  }

__attribute__((used)) static FT_Error
  parse_dict( T1_Face    face,
              T1_Loader  loader,
              FT_Byte*   base,
              FT_ULong   size )
  {
    T1_Parser  parser = &loader->parser;
    FT_Byte   *limit, *start_binary = NULL;
    FT_Bool    have_integer = 0;


    parser->root.cursor = base;
    parser->root.limit  = base + size;
    parser->root.error  = FT_Err_Ok;

    limit = parser->root.limit;

    T1_Skip_Spaces( parser );

    while ( parser->root.cursor < limit )
    {
      FT_Byte*  cur;


      cur = parser->root.cursor;

      /* look for `eexec' */
      if ( IS_PS_TOKEN( cur, limit, "eexec" ) )
        break;

      /* look for `closefile' which ends the eexec section */
      else if ( IS_PS_TOKEN( cur, limit, "closefile" ) )
        break;

      /* in a synthetic font the base font starts after a           */
      /* `FontDictionary' token that is placed after a Private dict */
      else if ( IS_PS_TOKEN( cur, limit, "FontDirectory" ) )
      {
        if ( loader->keywords_encountered & T1_PRIVATE )
          loader->keywords_encountered |=
            T1_FONTDIR_AFTER_PRIVATE;
        parser->root.cursor += 13;
      }

      /* check whether we have an integer */
      else if ( ft_isdigit( *cur ) )
      {
        start_binary = cur;
        T1_Skip_PS_Token( parser );
        if ( parser->root.error )
          goto Exit;
        have_integer = 1;
      }

      /* in valid Type 1 fonts we don't see `RD' or `-|' directly */
      /* since those tokens are handled by parse_subrs and        */
      /* parse_charstrings                                        */
      else if ( *cur == 'R' && cur + 6 < limit && *(cur + 1) == 'D' &&
                have_integer )
      {
        FT_ULong  s;
        FT_Byte*  b;


        parser->root.cursor = start_binary;
        if ( !read_binary_data( parser, &s, &b, IS_INCREMENTAL ) )
          return FT_THROW( Invalid_File_Format );
        have_integer = 0;
      }

      else if ( *cur == '-' && cur + 6 < limit && *(cur + 1) == '|' &&
                have_integer )
      {
        FT_ULong  s;
        FT_Byte*  b;


        parser->root.cursor = start_binary;
        if ( !read_binary_data( parser, &s, &b, IS_INCREMENTAL ) )
          return FT_THROW( Invalid_File_Format );
        have_integer = 0;
      }

      /* look for immediates */
      else if ( *cur == '/' && cur + 2 < limit )
      {
        FT_UInt  len;


        cur++;

        parser->root.cursor = cur;
        T1_Skip_PS_Token( parser );
        if ( parser->root.error )
          goto Exit;

        len = (FT_UInt)( parser->root.cursor - cur );

        if ( len > 0 && len < 22 && parser->root.cursor < limit )
        {
          /* now compare the immediate name to the keyword table */
          T1_Field  keyword = (T1_Field)t1_keywords;


          for (;;)
          {
            FT_Byte*  name;


            name = (FT_Byte*)keyword->ident;
            if ( !name )
              break;

            if ( cur[0] == name[0]                      &&
                 len == ft_strlen( (const char *)name ) &&
                 ft_memcmp( cur, name, len ) == 0       )
            {
              /* We found it -- run the parsing callback!     */
              /* We record every instance of every field      */
              /* (until we reach the base font of a           */
              /* synthetic font) to deal adequately with      */
              /* multiple master fonts; this is also          */
              /* necessary because later PostScript           */
              /* definitions override earlier ones.           */

              /* Once we encounter `FontDirectory' after      */
              /* `/Private', we know that this is a synthetic */
              /* font; except for `/CharStrings' we are not   */
              /* interested in anything that follows this     */
              /* `FontDirectory'.                             */

              /* MM fonts have more than one /Private token at */
              /* the top level; let's hope that all the junk   */
              /* that follows the first /Private token is not  */
              /* interesting to us.                            */

              /* According to Adobe Tech Note #5175 (CID-Keyed */
              /* Font Installation for ATM Software) a `begin' */
              /* must be followed by exactly one `end', and    */
              /* `begin' -- `end' pairs must be accurately     */
              /* paired.  We could use this to distinguish     */
              /* between the global Private and the Private    */
              /* dict that is a member of the Blend dict.      */

              const FT_UInt dict =
                ( loader->keywords_encountered & T1_PRIVATE )
                    ? T1_FIELD_DICT_PRIVATE
                    : T1_FIELD_DICT_FONTDICT;

              if ( !( dict & keyword->dict ) )
              {
                FT_TRACE1(( "parse_dict: found `%s' but ignoring it"
                            " since it is in the wrong dictionary\n",
                            keyword->ident ));
                break;
              }

              if ( !( loader->keywords_encountered &
                      T1_FONTDIR_AFTER_PRIVATE     )                  ||
                   ft_strcmp( (const char*)name, "CharStrings" ) == 0 )
              {
                parser->root.error = t1_load_keyword( face,
                                                      loader,
                                                      keyword );
                if ( parser->root.error )
                {
                  if ( FT_ERR_EQ( parser->root.error, Ignore ) )
                    parser->root.error = FT_Err_Ok;
                  else
                    return parser->root.error;
                }
              }
              break;
            }

            keyword++;
          }
        }

        have_integer = 0;
      }
      else
      {
        T1_Skip_PS_Token( parser );
        if ( parser->root.error )
          goto Exit;
        have_integer = 0;
      }

      T1_Skip_Spaces( parser );
    }

  Exit:
    return parser->root.error;
  }

__attribute__((used)) static void
  t1_init_loader( T1_Loader  loader,
                  T1_Face    face )
  {
    FT_UNUSED( face );

    FT_ZERO( loader );
  }

__attribute__((used)) static void
  t1_done_loader( T1_Loader  loader )
  {
    T1_Parser  parser = &loader->parser;
    FT_Memory  memory = parser->root.memory;


    /* finalize tables */
    T1_Release_Table( &loader->encoding_table );
    T1_Release_Table( &loader->charstrings );
    T1_Release_Table( &loader->glyph_names );
    T1_Release_Table( &loader->swap_table );
    T1_Release_Table( &loader->subrs );

    /* finalize hash */
    ft_hash_num_free( loader->subrs_hash, memory );
    FT_FREE( loader->subrs_hash );

    /* finalize parser */
    T1_Finalize_Parser( parser );
  }

