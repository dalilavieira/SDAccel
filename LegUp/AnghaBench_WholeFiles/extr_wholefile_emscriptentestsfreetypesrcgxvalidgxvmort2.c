#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_14__   TYPE_4__ ;
typedef  struct TYPE_13__   TYPE_3__ ;
typedef  struct TYPE_12__   TYPE_2__ ;
typedef  struct TYPE_11__   TYPE_1__ ;

/* Type definitions */
struct TYPE_12__ {int /*<<< orphan*/  optdata; } ;
struct TYPE_14__ {TYPE_2__ statetable; TYPE_1__* root; } ;
struct TYPE_13__ {scalar_t__ ligActionTable; scalar_t__ componentTable; scalar_t__ ligatureTable; scalar_t__ ligActionTable_length; scalar_t__ componentTable_length; scalar_t__ ligatureTable_length; } ;
struct TYPE_11__ {scalar_t__ level; } ;
typedef  TYPE_3__* GXV_mort_subtable_type2_StateOptRecData ;
typedef  TYPE_4__* GXV_Validator ;
typedef  scalar_t__ GXV_StateTable_GlyphOffsetCPtr ;
typedef  scalar_t__ FT_UShort ;
typedef  int FT_ULong ;
typedef  scalar_t__ FT_Bytes ;
typedef  scalar_t__ FT_Byte ;

/* Variables and functions */
 int /*<<< orphan*/  FT_INVALID_OFFSET ; 
 int FT_NEXT_ULONG (scalar_t__) ; 
 void* FT_NEXT_USHORT (scalar_t__) ; 
 int /*<<< orphan*/  FT_UNUSED (scalar_t__) ; 
 scalar_t__ FT_VALIDATE_PARANOID ; 
 int /*<<< orphan*/  GXV_32BIT_ALIGNMENT_VALIDATE (scalar_t__) ; 
 int /*<<< orphan*/  GXV_EXIT ; 
 int /*<<< orphan*/  GXV_LIMIT_CHECK (int) ; 
 int /*<<< orphan*/  GXV_NAME_ENTER (char*) ; 
 int /*<<< orphan*/  GXV_TRACE (char*) ; 
 int /*<<< orphan*/  gxv_set_length_by_ushort_offset (scalar_t__*,scalar_t__**,scalar_t__*,int,scalar_t__,TYPE_4__*) ; 

__attribute__((used)) static void
  gxv_mort_subtable_type2_opttable_load( FT_Bytes       table,
                                         FT_Bytes       limit,
                                         GXV_Validator  valid )
  {
    FT_Bytes p = table;
    GXV_mort_subtable_type2_StateOptRecData  optdata =
      (GXV_mort_subtable_type2_StateOptRecData)valid->statetable.optdata;


    GXV_LIMIT_CHECK( 2 + 2 + 2 );
    optdata->ligActionTable = FT_NEXT_USHORT( p );
    optdata->componentTable = FT_NEXT_USHORT( p );
    optdata->ligatureTable  = FT_NEXT_USHORT( p );

    GXV_TRACE(( "offset to ligActionTable=0x%04x\n",
                optdata->ligActionTable ));
    GXV_TRACE(( "offset to componentTable=0x%04x\n",
                optdata->componentTable ));
    GXV_TRACE(( "offset to ligatureTable=0x%04x\n",
                optdata->ligatureTable ));
  }

__attribute__((used)) static void
  gxv_mort_subtable_type2_subtable_setup( FT_UShort      table_size,
                                          FT_UShort      classTable,
                                          FT_UShort      stateArray,
                                          FT_UShort      entryTable,
                                          FT_UShort      *classTable_length_p,
                                          FT_UShort      *stateArray_length_p,
                                          FT_UShort      *entryTable_length_p,
                                          GXV_Validator  valid )
  {
    FT_UShort  o[6];
    FT_UShort  *l[6];
    FT_UShort  buff[7];

    GXV_mort_subtable_type2_StateOptRecData  optdata =
      (GXV_mort_subtable_type2_StateOptRecData)valid->statetable.optdata;


    GXV_NAME_ENTER( "subtable boundaries setup" );

    o[0] = classTable;
    o[1] = stateArray;
    o[2] = entryTable;
    o[3] = optdata->ligActionTable;
    o[4] = optdata->componentTable;
    o[5] = optdata->ligatureTable;
    l[0] = classTable_length_p;
    l[1] = stateArray_length_p;
    l[2] = entryTable_length_p;
    l[3] = &(optdata->ligActionTable_length);
    l[4] = &(optdata->componentTable_length);
    l[5] = &(optdata->ligatureTable_length);

    gxv_set_length_by_ushort_offset( o, l, buff, 6, table_size, valid );

    GXV_TRACE(( "classTable: offset=0x%04x length=0x%04x\n",
                classTable, *classTable_length_p ));
    GXV_TRACE(( "stateArray: offset=0x%04x length=0x%04x\n",
                stateArray, *stateArray_length_p ));
    GXV_TRACE(( "entryTable: offset=0x%04x length=0x%04x\n",
                entryTable, *entryTable_length_p ));
    GXV_TRACE(( "ligActionTable: offset=0x%04x length=0x%04x\n",
                optdata->ligActionTable,
                optdata->ligActionTable_length ));
    GXV_TRACE(( "componentTable: offset=0x%04x length=0x%04x\n",
                optdata->componentTable,
                optdata->componentTable_length ));
    GXV_TRACE(( "ligatureTable:  offset=0x%04x length=0x%04x\n",
                optdata->ligatureTable,
                optdata->ligatureTable_length ));

    GXV_EXIT;
  }

__attribute__((used)) static void
  gxv_mort_subtable_type2_ligActionOffset_validate(
    FT_Bytes       table,
    FT_UShort      ligActionOffset,
    GXV_Validator  valid )
  {
    /* access ligActionTable */
    GXV_mort_subtable_type2_StateOptRecData  optdata =
      (GXV_mort_subtable_type2_StateOptRecData)valid->statetable.optdata;

    FT_Bytes lat_base  = table + optdata->ligActionTable;
    FT_Bytes p         = table + ligActionOffset;
    FT_Bytes lat_limit = lat_base + optdata->ligActionTable;


    GXV_32BIT_ALIGNMENT_VALIDATE( ligActionOffset );
    if ( p < lat_base )
    {
      GXV_TRACE(( "too short offset 0x%04x: p < lat_base (%d byte rewind)\n",
                  ligActionOffset, lat_base - p ));

      /* FontValidator, ftxvalidator, ftxdumperfuser warn but continue */
      if ( valid->root->level >= FT_VALIDATE_PARANOID )
        FT_INVALID_OFFSET;
    }
    else if ( lat_limit < p )
    {
      GXV_TRACE(( "too large offset 0x%04x: lat_limit < p (%d byte overrun)\n",
                  ligActionOffset, p - lat_limit ));

      /* FontValidator, ftxvalidator, ftxdumperfuser warn but continue */
      if ( valid->root->level >= FT_VALIDATE_PARANOID )
        FT_INVALID_OFFSET;
    }
    else
    {
      /* validate entry in ligActionTable */
      FT_ULong   lig_action;
      FT_UShort  last;
      FT_UShort  store;
      FT_ULong   offset;


      lig_action = FT_NEXT_ULONG( p );
      last   = (FT_UShort)( ( lig_action >> 31 ) & 1 );
      store  = (FT_UShort)( ( lig_action >> 30 ) & 1 );

      offset = lig_action & 0x3FFFFFFFUL;
    }
  }

__attribute__((used)) static void
  gxv_mort_subtable_type2_entry_validate(
    FT_Byte                         state,
    FT_UShort                       flags,
    GXV_StateTable_GlyphOffsetCPtr  glyphOffset_p,
    FT_Bytes                        table,
    FT_Bytes                        limit,
    GXV_Validator                   valid )
  {
    FT_UShort setComponent;
    FT_UShort dontAdvance;
    FT_UShort offset;

    FT_UNUSED( state );
    FT_UNUSED( glyphOffset_p );
    FT_UNUSED( limit );


    setComponent = (FT_UShort)( ( flags >> 15 ) & 1 );
    dontAdvance  = (FT_UShort)( ( flags >> 14 ) & 1 );

    offset = (FT_UShort)( flags & 0x3FFFU );

    if ( 0 < offset )
      gxv_mort_subtable_type2_ligActionOffset_validate( table, offset,
                                                        valid );
  }

__attribute__((used)) static void
  gxv_mort_subtable_type2_ligatureTable_validate( FT_Bytes       table,
                                                  GXV_Validator  valid )
  {
    GXV_mort_subtable_type2_StateOptRecData  optdata =
      (GXV_mort_subtable_type2_StateOptRecData)valid->statetable.optdata;

    FT_Bytes p     = table + optdata->ligatureTable;
    FT_Bytes limit = table + optdata->ligatureTable
                           + optdata->ligatureTable_length;


    GXV_NAME_ENTER( "mort chain subtable type2 - substitutionTable" );
    if ( 0 != optdata->ligatureTable )
    {
      /* Apple does not give specification of ligatureTable format */
      while ( p < limit )
      {
        FT_UShort  lig_gid;


        GXV_LIMIT_CHECK( 2 );
        lig_gid = FT_NEXT_USHORT( p );
      }
    }
    GXV_EXIT;
  }

