#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_12__   TYPE_1__ ;

/* Type definitions */
struct TYPE_12__ {int subtable_length; } ;
typedef  TYPE_1__* GXV_Validator ;
typedef  int /*<<< orphan*/  (* GXV_Validate_Func ) (int,int,TYPE_1__*) ;
typedef  scalar_t__ FT_UShort ;
typedef  int FT_ULong ;
typedef  int FT_Bytes ;

/* Variables and functions */
 int /*<<< orphan*/  FT_INVALID_DATA ; 
 int /*<<< orphan*/  FT_INVALID_FORMAT ; 
 int FT_NEXT_ULONG (int) ; 
 int /*<<< orphan*/  GXV_EXIT ; 
 int /*<<< orphan*/  GXV_LIMIT_CHECK (int) ; 
 int /*<<< orphan*/  GXV_NAME_ENTER (char*) ; 
 int /*<<< orphan*/  GXV_TRACE (char*) ; 
 int /*<<< orphan*/  gxv_mort_coverage_validate (scalar_t__,TYPE_1__*) ; 
 int /*<<< orphan*/  gxv_mort_featurearray_validate (int,int,int,TYPE_1__*) ; 
 int /*<<< orphan*/  gxv_morx_subtable_type0_validate (int,int,TYPE_1__*) ; 
 int /*<<< orphan*/  gxv_morx_subtable_type1_validate (int,int,TYPE_1__*) ; 
 int /*<<< orphan*/  gxv_morx_subtable_type2_validate (int,int,TYPE_1__*) ; 
 int /*<<< orphan*/  gxv_morx_subtable_type4_validate (int,int,TYPE_1__*) ; 
 int /*<<< orphan*/  gxv_morx_subtable_type5_validate (int,int,TYPE_1__*) ; 

__attribute__((used)) static void
  gxv_morx_subtables_validate( FT_Bytes       table,
                               FT_Bytes       limit,
                               FT_UShort      nSubtables,
                               GXV_Validator  gxvalid )
  {
    FT_Bytes  p = table;

    GXV_Validate_Func fmt_funcs_table[] =
    {
      gxv_morx_subtable_type0_validate, /* 0 */
      gxv_morx_subtable_type1_validate, /* 1 */
      gxv_morx_subtable_type2_validate, /* 2 */
      NULL,                             /* 3 */
      gxv_morx_subtable_type4_validate, /* 4 */
      gxv_morx_subtable_type5_validate, /* 5 */

    };

    FT_UShort  i;


    GXV_NAME_ENTER( "subtables in a chain" );

    for ( i = 0; i < nSubtables; i++ )
    {
      GXV_Validate_Func  func;

      FT_ULong  length;
      FT_ULong  coverage;
#ifdef GXV_LOAD_UNUSED_VARS
      FT_ULong  subFeatureFlags;
#endif
      FT_ULong  type;
      FT_ULong  rest;


      GXV_LIMIT_CHECK( 4 + 4 + 4 );
      length          = FT_NEXT_ULONG( p );
      coverage        = FT_NEXT_ULONG( p );
#ifdef GXV_LOAD_UNUSED_VARS
      subFeatureFlags = FT_NEXT_ULONG( p );
#else
      p += 4;
#endif

      GXV_TRACE(( "validating chain subtable %d/%d (%d bytes)\n",
                  i + 1, nSubtables, length ));

      type = coverage & 0x0007;
      rest = length - ( 4 + 4 + 4 );
      GXV_LIMIT_CHECK( rest );

      /* morx coverage consists of mort_coverage & 16bit padding */
      gxv_mort_coverage_validate( (FT_UShort)( ( coverage >> 16 ) | coverage ),
                                  gxvalid );
      if ( type > 5 )
        FT_INVALID_FORMAT;

      func = fmt_funcs_table[type];
      if ( !func )
        GXV_TRACE(( "morx type %d is reserved\n", type ));

      func( p, p + rest, gxvalid );

      /* TODO: subFeatureFlags should be unique in a table? */
      p += rest;
    }

    gxvalid->subtable_length = (FT_ULong)( p - table );

    GXV_EXIT;
  }

__attribute__((used)) static void
  gxv_morx_chain_validate( FT_Bytes       table,
                           FT_Bytes       limit,
                           GXV_Validator  gxvalid )
  {
    FT_Bytes  p = table;
#ifdef GXV_LOAD_UNUSED_VARS
    FT_ULong  defaultFlags;
#endif
    FT_ULong  chainLength;
    FT_ULong  nFeatureFlags;
    FT_ULong  nSubtables;


    GXV_NAME_ENTER( "morx chain header" );

    GXV_LIMIT_CHECK( 4 + 4 + 4 + 4 );
#ifdef GXV_LOAD_UNUSED_VARS
    defaultFlags  = FT_NEXT_ULONG( p );
#else
    p += 4;
#endif
    chainLength   = FT_NEXT_ULONG( p );
    nFeatureFlags = FT_NEXT_ULONG( p );
    nSubtables    = FT_NEXT_ULONG( p );

    /* feature-array of morx is same with that of mort */
    gxv_mort_featurearray_validate( p, limit, nFeatureFlags, gxvalid );
    p += gxvalid->subtable_length;

    if ( nSubtables >= 0x10000L )
      FT_INVALID_DATA;

    gxv_morx_subtables_validate( p, table + chainLength,
                                 (FT_UShort)nSubtables, gxvalid );

    gxvalid->subtable_length = chainLength;

    /* TODO: defaultFlags should be compared with the flags in tables */

    GXV_EXIT;
  }

