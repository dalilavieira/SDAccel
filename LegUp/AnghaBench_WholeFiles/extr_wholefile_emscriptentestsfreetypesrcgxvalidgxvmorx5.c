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
struct TYPE_14__ {int ul; } ;
struct TYPE_11__ {int /*<<< orphan*/  optdata; } ;
struct TYPE_13__ {TYPE_1__ xstatetable; } ;
struct TYPE_12__ {int /*<<< orphan*/  insertionGlyphList_length; int /*<<< orphan*/  insertionGlyphList; } ;
typedef  TYPE_2__* GXV_morx_subtable_type5_StateOptRecData ;
typedef  TYPE_3__* GXV_Validator ;
typedef  TYPE_4__* GXV_StateTable_GlyphOffsetCPtr ;
typedef  int FT_UShort ;
typedef  int /*<<< orphan*/  FT_ULong ;
typedef  scalar_t__ FT_Bytes ;
typedef  scalar_t__ FT_Byte ;
typedef  int /*<<< orphan*/  FT_Bool ;

/* Variables and functions */
 int /*<<< orphan*/  FT_BOOL (int) ; 
 int /*<<< orphan*/  FT_NEXT_ULONG (scalar_t__) ; 
 int FT_NEXT_USHORT (scalar_t__) ; 
 int /*<<< orphan*/  FT_UNUSED (int) ; 
 int /*<<< orphan*/  GXV_LIMIT_CHECK (int) ; 
 int /*<<< orphan*/  GXV_TRACE (char*) ; 
 int /*<<< orphan*/  gxv_set_length_by_ulong_offset (int /*<<< orphan*/ *,int /*<<< orphan*/ **,int /*<<< orphan*/ *,int,int /*<<< orphan*/ ,TYPE_3__*) ; 

__attribute__((used)) static void
  gxv_morx_subtable_type5_insertionGlyphList_load( FT_Bytes       table,
                                                   FT_Bytes       limit,
                                                   GXV_Validator  valid )
  {
    FT_Bytes  p = table;

    GXV_morx_subtable_type5_StateOptRecData  optdata =
      (GXV_morx_subtable_type5_StateOptRecData)valid->xstatetable.optdata;


    GXV_LIMIT_CHECK( 4 );
    optdata->insertionGlyphList = FT_NEXT_ULONG( p );
  }

__attribute__((used)) static void
  gxv_morx_subtable_type5_subtable_setup( FT_ULong       table_size,
                                          FT_ULong       classTable,
                                          FT_ULong       stateArray,
                                          FT_ULong       entryTable,
                                          FT_ULong*      classTable_length_p,
                                          FT_ULong*      stateArray_length_p,
                                          FT_ULong*      entryTable_length_p,
                                          GXV_Validator  valid )
  {
    FT_ULong   o[4];
    FT_ULong*  l[4];
    FT_ULong   buff[5];

    GXV_morx_subtable_type5_StateOptRecData  optdata =
      (GXV_morx_subtable_type5_StateOptRecData)valid->xstatetable.optdata;


    o[0] = classTable;
    o[1] = stateArray;
    o[2] = entryTable;
    o[3] = optdata->insertionGlyphList;
    l[0] = classTable_length_p;
    l[1] = stateArray_length_p;
    l[2] = entryTable_length_p;
    l[3] = &(optdata->insertionGlyphList_length);

    gxv_set_length_by_ulong_offset( o, l, buff, 4, table_size, valid );
  }

__attribute__((used)) static void
  gxv_morx_subtable_type5_InsertList_validate( FT_UShort      table_index,
                                               FT_UShort      count,
                                               FT_Bytes       table,
                                               FT_Bytes       limit,
                                               GXV_Validator  valid )
  {
    FT_Bytes p = table + table_index * 2;


    while ( p < table + count * 2 + table_index * 2 )
    {
      FT_UShort  insert_glyphID;


      GXV_LIMIT_CHECK( 2 );
      insert_glyphID = FT_NEXT_USHORT( p );
      GXV_TRACE(( " 0x%04x", insert_glyphID ));
    }

    GXV_TRACE(( "\n" ));
  }

__attribute__((used)) static void
  gxv_morx_subtable_type5_entry_validate(
    FT_UShort                       state,
    FT_UShort                       flags,
    GXV_StateTable_GlyphOffsetCPtr  glyphOffset_p,
    FT_Bytes                        table,
    FT_Bytes                        limit,
    GXV_Validator                   valid )
  {
    FT_Bool    setMark;
    FT_Bool    dontAdvance;
    FT_Bool    currentIsKashidaLike;
    FT_Bool    markedIsKashidaLike;
    FT_Bool    currentInsertBefore;
    FT_Bool    markedInsertBefore;
    FT_Byte    currentInsertCount;
    FT_Byte    markedInsertCount;
    FT_Byte    currentInsertList;
    FT_UShort  markedInsertList;

    FT_UNUSED( state );


    setMark              = FT_BOOL( ( flags >> 15 ) & 1 );
    dontAdvance          = FT_BOOL( ( flags >> 14 ) & 1 );
    currentIsKashidaLike = FT_BOOL( ( flags >> 13 ) & 1 );
    markedIsKashidaLike  = FT_BOOL( ( flags >> 12 ) & 1 );
    currentInsertBefore  = FT_BOOL( ( flags >> 11 ) & 1 );
    markedInsertBefore   = FT_BOOL( ( flags >> 10 ) & 1 );

    currentInsertCount = (FT_Byte)( ( flags >> 5 ) & 0x1F   );
    markedInsertCount  = (FT_Byte)(   flags        & 0x001F );

    currentInsertList = (FT_Byte)  ( glyphOffset_p->ul >> 16 );
    markedInsertList  = (FT_UShort)( glyphOffset_p->ul       );

    if ( currentInsertList && 0 != currentInsertCount )
      gxv_morx_subtable_type5_InsertList_validate( currentInsertList,
                                                   currentInsertCount,
                                                   table, limit,
                                                   valid );

    if ( markedInsertList && 0 != markedInsertCount )
      gxv_morx_subtable_type5_InsertList_validate( markedInsertList,
                                                   markedInsertCount,
                                                   table, limit,
                                                   valid );
  }

