#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_11__   TYPE_3__ ;
typedef  struct TYPE_10__   TYPE_2__ ;
typedef  struct TYPE_9__   TYPE_1__ ;

/* Type definitions */
struct TYPE_11__ {scalar_t__ y; scalar_t__ x; } ;
struct TYPE_9__ {size_t num_glyphs; int /*<<< orphan*/  private_dict; int /*<<< orphan*/  font_extra; int /*<<< orphan*/  font_info; scalar_t__ font_name; int /*<<< orphan*/ ** glyph_names; } ;
struct TYPE_10__ {scalar_t__ afm_data; TYPE_1__ type1; } ;
typedef  TYPE_2__* T1_Face ;
typedef  int /*<<< orphan*/  PS_PrivateRec ;
typedef  int /*<<< orphan*/  PS_FontInfoRec ;
typedef  int /*<<< orphan*/  PS_FontExtraRec ;
typedef  TYPE_3__ FT_Vector ;
typedef  int /*<<< orphan*/  FT_UInt ;
typedef  int /*<<< orphan*/  FT_String ;
typedef  int /*<<< orphan*/  FT_Module_Interface ;
typedef  size_t FT_Int ;
typedef  scalar_t__ FT_Face ;
typedef  int /*<<< orphan*/  FT_Error ;
typedef  scalar_t__ FT_Driver ;
typedef  int /*<<< orphan*/  AFM_FontInfo ;

/* Variables and functions */
 int /*<<< orphan*/  FT_UNUSED (scalar_t__) ; 
 int /*<<< orphan*/  T1_Err_Ok ; 
 int /*<<< orphan*/  T1_Get_Kerning (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,TYPE_3__*) ; 
 int /*<<< orphan*/  ft_service_list_lookup (int /*<<< orphan*/ ,int /*<<< orphan*/  const*) ; 
 int /*<<< orphan*/  ft_strcmp (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  t1_services ; 

__attribute__((used)) static FT_UInt
  t1_get_name_index( T1_Face     face,
                     FT_String*  glyph_name )
  {
    FT_Int      i;
    FT_String*  gname;


    for ( i = 0; i < face->type1.num_glyphs; i++ )
    {
      gname = face->type1.glyph_names[i];

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

    return T1_Err_Ok;
  }

__attribute__((used)) static FT_Error
  t1_ps_get_font_extra( FT_Face           face,
                        PS_FontExtraRec*  afont_extra )
  {
    *afont_extra = ((T1_Face)face)->type1.font_extra;

    return T1_Err_Ok;
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

    return T1_Err_Ok;
  }

__attribute__((used)) static FT_Module_Interface
  Get_Interface( FT_Driver         driver,
                 const FT_String*  t1_interface )
  {
    FT_UNUSED( driver );

    return ft_service_list_lookup( t1_services, t1_interface );
  }

__attribute__((used)) static FT_Error
  Get_Kerning( T1_Face     face,
               FT_UInt     left_glyph,
               FT_UInt     right_glyph,
               FT_Vector*  kerning )
  {
    kerning->x = 0;
    kerning->y = 0;

    if ( face->afm_data )
      T1_Get_Kerning( (AFM_FontInfo)face->afm_data,
                      left_glyph,
                      right_glyph,
                      kerning );

    return T1_Err_Ok;
  }

