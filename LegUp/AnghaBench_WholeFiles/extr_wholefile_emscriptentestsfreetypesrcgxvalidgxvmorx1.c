#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_28__   TYPE_8__ ;
typedef  struct TYPE_27__   TYPE_7__ ;
typedef  struct TYPE_26__   TYPE_6__ ;
typedef  struct TYPE_25__   TYPE_5__ ;
typedef  struct TYPE_24__   TYPE_4__ ;
typedef  struct TYPE_23__   TYPE_3__ ;
typedef  struct TYPE_22__   TYPE_2__ ;
typedef  struct TYPE_21__   TYPE_1__ ;

/* Type definitions */
struct TYPE_28__ {scalar_t__ u; } ;
struct TYPE_27__ {void* u; } ;
struct TYPE_26__ {int ul; } ;
struct TYPE_23__ {int /*<<< orphan*/  optdata; } ;
struct TYPE_25__ {int lookuptbl_head; void (* lookupval_func ) (int,TYPE_8__*,TYPE_5__*) ;TYPE_7__ (* lookupfmt4_trans ) (int,TYPE_8__*,int,TYPE_5__*) ;int /*<<< orphan*/  lookupval_sign; TYPE_3__ xstatetable; TYPE_2__* face; TYPE_1__* root; } ;
struct TYPE_24__ {int substitutionTable; int substitutionTable_length; scalar_t__ substitutionTable_num_lookupTables; } ;
struct TYPE_22__ {scalar_t__ num_glyphs; } ;
struct TYPE_21__ {scalar_t__ level; } ;
typedef  TYPE_4__* GXV_morx_subtable_type1_StateOptRecData ;
typedef  TYPE_5__* GXV_Validator ;
typedef  TYPE_6__* GXV_StateTable_GlyphOffsetCPtr ;
typedef  TYPE_7__ GXV_LookupValueDesc ;
typedef  TYPE_8__* GXV_LookupValueCPtr ;
typedef  int FT_UShort ;
typedef  int FT_ULong ;
typedef  scalar_t__ FT_Short ;
typedef  int FT_Bytes ;

/* Variables and functions */
 int /*<<< orphan*/  FT_INVALID_DATA ; 
 int /*<<< orphan*/  FT_INVALID_GLYPH_ID ; 
 int FT_NEXT_ULONG (int) ; 
 void* FT_NEXT_USHORT (int) ; 
 int /*<<< orphan*/  FT_UNUSED (int) ; 
 scalar_t__ FT_VALIDATE_PARANOID ; 
 int /*<<< orphan*/  GXV_LIMIT_CHECK (int) ; 
 int /*<<< orphan*/  GXV_LOOKUPVALUE_UNSIGNED ; 
 int /*<<< orphan*/  GXV_TRACE (char*) ; 
 int /*<<< orphan*/  gxv_LookupTable_validate (int,int,TYPE_5__*) ; 
 int /*<<< orphan*/  gxv_set_length_by_ulong_offset (int*,int**,int*,int,int,TYPE_5__*) ; 

__attribute__((used)) static void
  gxv_morx_subtable_type1_substitutionTable_load( FT_Bytes       table,
                                                  FT_Bytes       limit,
                                                  GXV_Validator  valid )
  {
    FT_Bytes  p = table;

    GXV_morx_subtable_type1_StateOptRecData  optdata =
      (GXV_morx_subtable_type1_StateOptRecData)valid->xstatetable.optdata;


    GXV_LIMIT_CHECK( 2 );
    optdata->substitutionTable = FT_NEXT_USHORT( p );
  }

__attribute__((used)) static void
  gxv_morx_subtable_type1_subtable_setup( FT_ULong       table_size,
                                          FT_ULong       classTable,
                                          FT_ULong       stateArray,
                                          FT_ULong       entryTable,
                                          FT_ULong*      classTable_length_p,
                                          FT_ULong*      stateArray_length_p,
                                          FT_ULong*      entryTable_length_p,
                                          GXV_Validator  valid )
  {
    FT_ULong  o[4];
    FT_ULong  *l[4];
    FT_ULong  buff[5];

    GXV_morx_subtable_type1_StateOptRecData  optdata =
      (GXV_morx_subtable_type1_StateOptRecData)valid->xstatetable.optdata;


    o[0] = classTable;
    o[1] = stateArray;
    o[2] = entryTable;
    o[3] = optdata->substitutionTable;
    l[0] = classTable_length_p;
    l[1] = stateArray_length_p;
    l[2] = entryTable_length_p;
    l[3] = &(optdata->substitutionTable_length);

    gxv_set_length_by_ulong_offset( o, l, buff, 4, table_size, valid );
  }

__attribute__((used)) static void
  gxv_morx_subtable_type1_entry_validate(
    FT_UShort                       state,
    FT_UShort                       flags,
    GXV_StateTable_GlyphOffsetCPtr  glyphOffset_p,
    FT_Bytes                        table,
    FT_Bytes                        limit,
    GXV_Validator                   valid )
  {
    FT_UShort  setMark;
    FT_UShort  dontAdvance;
    FT_UShort  reserved;
    FT_Short   markIndex;
    FT_Short   currentIndex;

    GXV_morx_subtable_type1_StateOptRecData  optdata =
      (GXV_morx_subtable_type1_StateOptRecData)valid->xstatetable.optdata;

    FT_UNUSED( state );
    FT_UNUSED( table );
    FT_UNUSED( limit );


    setMark      = (FT_UShort)( ( flags >> 15 ) & 1 );
    dontAdvance  = (FT_UShort)( ( flags >> 14 ) & 1 );

    reserved = (FT_UShort)( flags & 0x3FFF );

    markIndex    = (FT_Short)( glyphOffset_p->ul >> 16 );
    currentIndex = (FT_Short)( glyphOffset_p->ul       );

    GXV_TRACE(( " setMark=%01d dontAdvance=%01d\n",
                setMark, dontAdvance ));

    if ( 0 < reserved )
    {
      GXV_TRACE(( " non-zero bits found in reserved range\n" ));
      if ( valid->root->level >= FT_VALIDATE_PARANOID )
        FT_INVALID_DATA;
    }

    GXV_TRACE(( "markIndex = %d, currentIndex = %d\n",
                markIndex, currentIndex ));

    if ( optdata->substitutionTable_num_lookupTables < markIndex + 1 )
      optdata->substitutionTable_num_lookupTables =
        (FT_Short)( markIndex + 1 );

    if ( optdata->substitutionTable_num_lookupTables < currentIndex + 1 )
      optdata->substitutionTable_num_lookupTables =
        (FT_Short)( currentIndex + 1 );
  }

__attribute__((used)) static void
  gxv_morx_subtable_type1_LookupValue_validate( FT_UShort            glyph,
                                                GXV_LookupValueCPtr  value_p,
                                                GXV_Validator        valid )
  {
    FT_UNUSED( glyph ); /* for the non-debugging case */

    GXV_TRACE(( "morx subtable type1 subst.: %d -> %d\n", glyph, value_p->u ));

    if ( value_p->u > valid->face->num_glyphs )
      FT_INVALID_GLYPH_ID;
  }

__attribute__((used)) static GXV_LookupValueDesc
  gxv_morx_subtable_type1_LookupFmt4_transit(
    FT_UShort            relative_gindex,
    GXV_LookupValueCPtr  base_value_p,
    FT_Bytes             lookuptbl_limit,
    GXV_Validator        valid )
  {
    FT_Bytes             p;
    FT_Bytes             limit;
    FT_UShort            offset;
    GXV_LookupValueDesc  value;

    /* XXX: check range? */
    offset = (FT_UShort)( base_value_p->u +
                          relative_gindex * sizeof ( FT_UShort ) );

    p     = valid->lookuptbl_head + offset;
    limit = lookuptbl_limit;

    GXV_LIMIT_CHECK ( 2 );
    value.u = FT_NEXT_USHORT( p );

    return value;
  }

__attribute__((used)) static void
  gxv_morx_subtable_type1_substitutionTable_validate( FT_Bytes       table,
                                                      FT_Bytes       limit,
                                                      GXV_Validator  valid )
  {
    FT_Bytes   p = table;
    FT_UShort  i;

    GXV_morx_subtable_type1_StateOptRecData  optdata =
      (GXV_morx_subtable_type1_StateOptRecData)valid->xstatetable.optdata;


    /* TODO: calculate offset/length for each lookupTables */
    valid->lookupval_sign   = GXV_LOOKUPVALUE_UNSIGNED;
    valid->lookupval_func   = gxv_morx_subtable_type1_LookupValue_validate;
    valid->lookupfmt4_trans = gxv_morx_subtable_type1_LookupFmt4_transit;

    for ( i = 0; i < optdata->substitutionTable_num_lookupTables; i++ )
    {
      FT_ULong  offset;


      GXV_LIMIT_CHECK( 4 );
      offset = FT_NEXT_ULONG( p );

      gxv_LookupTable_validate( table + offset, limit, valid );
    }

    /* TODO: overlapping of lookupTables in substitutionTable */
  }

