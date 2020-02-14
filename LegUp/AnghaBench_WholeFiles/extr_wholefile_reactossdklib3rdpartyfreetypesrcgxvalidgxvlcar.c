#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_15__   TYPE_4__ ;
typedef  struct TYPE_14__   TYPE_3__ ;
typedef  struct TYPE_13__   TYPE_2__ ;
typedef  struct TYPE_12__   TYPE_1__ ;

/* Type definitions */
struct TYPE_15__ {int u; } ;
struct TYPE_14__ {void* u; } ;
struct TYPE_13__ {TYPE_1__* root; } ;
struct TYPE_12__ {int base; int limit; } ;
typedef  TYPE_2__* GXV_Validator ;
typedef  TYPE_3__ GXV_LookupValueDesc ;
typedef  TYPE_4__* GXV_LookupValueCPtr ;
typedef  int FT_UShort ;
typedef  scalar_t__ FT_Short ;
typedef  int FT_Bytes ;

/* Variables and functions */
 scalar_t__ FT_NEXT_SHORT (int) ; 
 void* FT_NEXT_USHORT (int) ; 
 int /*<<< orphan*/  FT_UNUSED (int) ; 
 int /*<<< orphan*/  GXV_EXIT ; 
 int GXV_LCAR_DATA (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  GXV_LIMIT_CHECK (int) ; 
 int /*<<< orphan*/  GXV_NAME_ENTER (char*) ; 
 int /*<<< orphan*/  format ; 
 int /*<<< orphan*/  gxv_ctlPoint_validate (int,int,TYPE_2__*) ; 

__attribute__((used)) static void
  gxv_lcar_partial_validate( FT_Short       partial,
                             FT_UShort      glyph,
                             GXV_Validator  gxvalid )
  {
    GXV_NAME_ENTER( "partial" );

    if ( GXV_LCAR_DATA( format ) != 1 )
      goto Exit;

    gxv_ctlPoint_validate( glyph, (FT_UShort)partial, gxvalid );

  Exit:
    GXV_EXIT;
  }

__attribute__((used)) static void
  gxv_lcar_LookupValue_validate( FT_UShort            glyph,
                                 GXV_LookupValueCPtr  value_p,
                                 GXV_Validator        gxvalid )
  {
    FT_Bytes   p     = gxvalid->root->base + value_p->u;
    FT_Bytes   limit = gxvalid->root->limit;
    FT_UShort  count;
    FT_Short   partial;
    FT_UShort  i;


    GXV_NAME_ENTER( "element in lookupTable" );

    GXV_LIMIT_CHECK( 2 );
    count = FT_NEXT_USHORT( p );

    GXV_LIMIT_CHECK( 2 * count );
    for ( i = 0; i < count; i++ )
    {
      partial = FT_NEXT_SHORT( p );
      gxv_lcar_partial_validate( partial, glyph, gxvalid );
    }

    GXV_EXIT;
  }

__attribute__((used)) static GXV_LookupValueDesc
  gxv_lcar_LookupFmt4_transit( FT_UShort            relative_gindex,
                               GXV_LookupValueCPtr  base_value_p,
                               FT_Bytes             lookuptbl_limit,
                               GXV_Validator        gxvalid )
  {
    FT_Bytes             p;
    FT_Bytes             limit;
    FT_UShort            offset;
    GXV_LookupValueDesc  value;

    FT_UNUSED( lookuptbl_limit );

    /* XXX: check range? */
    offset = (FT_UShort)( base_value_p->u +
                          relative_gindex * sizeof ( FT_UShort ) );
    p      = gxvalid->root->base + offset;
    limit  = gxvalid->root->limit;

    GXV_LIMIT_CHECK ( 2 );
    value.u = FT_NEXT_USHORT( p );

    return value;
  }

