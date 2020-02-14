#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_6__   TYPE_2__ ;
typedef  struct TYPE_5__   TYPE_1__ ;

/* Type definitions */
struct TYPE_5__ {size_t num_glyphs; int /*<<< orphan*/  private_dict; int /*<<< orphan*/  font_extra; int /*<<< orphan*/  font_info; scalar_t__ font_name; scalar_t__* charstrings; scalar_t__** glyph_names; } ;
struct TYPE_6__ {TYPE_1__ type1; } ;
typedef  TYPE_2__* T42_Face ;
typedef  int /*<<< orphan*/  PS_PrivateRec ;
typedef  int /*<<< orphan*/  PS_FontInfoRec ;
typedef  int /*<<< orphan*/  PS_FontExtraRec ;
typedef  int /*<<< orphan*/  FT_UInt ;
typedef  scalar_t__ FT_String ;
typedef  int /*<<< orphan*/  FT_Module_Interface ;
typedef  size_t FT_Int ;
typedef  scalar_t__ FT_Face ;
typedef  int /*<<< orphan*/  FT_Error ;
typedef  scalar_t__ FT_Driver ;

/* Variables and functions */
 int /*<<< orphan*/  FT_UNUSED (scalar_t__) ; 
 int /*<<< orphan*/  T42_Err_Ok ; 
 int /*<<< orphan*/  ft_atol (char const*) ; 
 int /*<<< orphan*/  ft_service_list_lookup (int /*<<< orphan*/ ,scalar_t__ const*) ; 
 int /*<<< orphan*/  ft_strcmp (scalar_t__*,scalar_t__*) ; 
 int /*<<< orphan*/  t42_services ; 

__attribute__((used)) static FT_UInt
  t42_get_name_index( T42_Face    face,
                      FT_String*  glyph_name )
  {
    FT_Int      i;
    FT_String*  gname;


    for ( i = 0; i < face->type1.num_glyphs; i++ )
    {
      gname = face->type1.glyph_names[i];

      if ( glyph_name[0] == gname[0] && !ft_strcmp( glyph_name, gname ) )
        return (FT_UInt)ft_atol( (const char *)face->type1.charstrings[i] );
    }

    return 0;
  }

__attribute__((used)) static const char*
  t42_get_ps_font_name( T42_Face  face )
  {
    return (const char*)face->type1.font_name;
  }

__attribute__((used)) static FT_Error
  t42_ps_get_font_info( FT_Face          face,
                        PS_FontInfoRec*  afont_info )
  {
    *afont_info = ((T42_Face)face)->type1.font_info;

    return T42_Err_Ok;
  }

__attribute__((used)) static FT_Error
  t42_ps_get_font_extra( FT_Face           face,
                         PS_FontExtraRec*  afont_extra )
  {
    *afont_extra = ((T42_Face)face)->type1.font_extra;

    return T42_Err_Ok;
  }

__attribute__((used)) static FT_Int
  t42_ps_has_glyph_names( FT_Face  face )
  {
    FT_UNUSED( face );

    return 1;
  }

__attribute__((used)) static FT_Error
  t42_ps_get_font_private( FT_Face         face,
                           PS_PrivateRec*  afont_private )
  {
    *afont_private = ((T42_Face)face)->type1.private_dict;

    return T42_Err_Ok;
  }

__attribute__((used)) static FT_Module_Interface
  T42_Get_Interface( FT_Driver         driver,
                     const FT_String*  t42_interface )
  {
    FT_UNUSED( driver );

    return ft_service_list_lookup( t42_services, t42_interface );
  }

