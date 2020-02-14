#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_8__   TYPE_2__ ;
typedef  struct TYPE_7__   TYPE_1__ ;

/* Type definitions */
struct TYPE_7__ {char* registry; char* ordering; int /*<<< orphan*/  supplement; int /*<<< orphan*/  font_info; } ;
struct TYPE_8__ {TYPE_1__ cid; int /*<<< orphan*/  font_extra; } ;
typedef  int /*<<< orphan*/  PS_FontInfoRec ;
typedef  int /*<<< orphan*/  PS_FontExtraRec ;
typedef  int /*<<< orphan*/  FT_UInt ;
typedef  int /*<<< orphan*/  FT_Int ;
typedef  scalar_t__ FT_Face ;
typedef  int /*<<< orphan*/  FT_Error ;
typedef  int FT_Bool ;
typedef  TYPE_1__* CID_FaceInfo ;
typedef  TYPE_2__* CID_Face ;

/* Variables and functions */
 int /*<<< orphan*/  FT_Err_Ok ; 
 int /*<<< orphan*/  FT_UNUSED (TYPE_2__*) ; 

__attribute__((used)) static FT_Error
  cid_ps_get_font_info( FT_Face          face,
                        PS_FontInfoRec*  afont_info )
  {
    *afont_info = ((CID_Face)face)->cid.font_info;

    return FT_Err_Ok;
  }

__attribute__((used)) static FT_Error
  cid_ps_get_font_extra( FT_Face          face,
                        PS_FontExtraRec*  afont_extra )
  {
    *afont_extra = ((CID_Face)face)->font_extra;

    return FT_Err_Ok;
  }

__attribute__((used)) static FT_Error
  cid_get_ros( CID_Face      face,
               const char*  *registry,
               const char*  *ordering,
               FT_Int       *supplement )
  {
    CID_FaceInfo  cid = &face->cid;


    if ( registry )
      *registry = cid->registry;

    if ( ordering )
      *ordering = cid->ordering;

    if ( supplement )
      *supplement = cid->supplement;

    return FT_Err_Ok;
  }

__attribute__((used)) static FT_Error
  cid_get_is_cid( CID_Face  face,
                  FT_Bool  *is_cid )
  {
    FT_Error  error = FT_Err_Ok;
    FT_UNUSED( face );


    if ( is_cid )
      *is_cid = 1; /* cid driver is only used for CID keyed fonts */

    return error;
  }

__attribute__((used)) static FT_Error
  cid_get_cid_from_glyph_index( CID_Face  face,
                                FT_UInt   glyph_index,
                                FT_UInt  *cid )
  {
    FT_Error  error = FT_Err_Ok;
    FT_UNUSED( face );


    if ( cid )
      *cid = glyph_index; /* identity mapping */

    return error;
  }

