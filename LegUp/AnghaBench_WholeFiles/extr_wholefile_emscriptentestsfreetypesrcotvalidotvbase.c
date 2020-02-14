#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */

/* Type definitions */
typedef  int /*<<< orphan*/  OTV_Validator ;
typedef  int FT_UInt ;
typedef  int FT_Bytes ;

/* Variables and functions */
 int BaseTagList ; 
 int BaseValues ; 
 int DefaultMinMax ; 
 int FT_NEXT_USHORT (int) ; 
 int MaxCoord ; 
 int MinCoord ; 
 int /*<<< orphan*/  OTV_EXIT ; 
 int /*<<< orphan*/  OTV_LIMIT_CHECK (int) ; 
 int /*<<< orphan*/  OTV_NAME_ENTER (char*) ; 
 int /*<<< orphan*/  OTV_OPTIONAL_OFFSET (int) ; 
 int /*<<< orphan*/  OTV_OPTIONAL_TABLE (int) ; 
 int /*<<< orphan*/  OTV_SIZE_CHECK (int) ; 
 int /*<<< orphan*/  OTV_TRACE (char*) ; 
 int /*<<< orphan*/  otv_BaseCoord_validate (int,int /*<<< orphan*/ ) ; 

__attribute__((used)) static void
  otv_BaseTagList_validate( FT_Bytes       table,
                            OTV_Validator  valid )
  {
    FT_Bytes  p = table;
    FT_UInt   BaseTagCount;


    OTV_NAME_ENTER( "BaseTagList" );

    OTV_LIMIT_CHECK( 2 );

    BaseTagCount = FT_NEXT_USHORT( p );

    OTV_TRACE(( " (BaseTagCount = %d)\n", BaseTagCount ));

    OTV_LIMIT_CHECK( BaseTagCount * 4 );          /* BaselineTag */

    OTV_EXIT;
  }

__attribute__((used)) static void
  otv_BaseValues_validate( FT_Bytes       table,
                           OTV_Validator  valid )
  {
    FT_Bytes  p = table;
    FT_UInt   BaseCoordCount;


    OTV_NAME_ENTER( "BaseValues" );

    OTV_LIMIT_CHECK( 4 );

    p             += 2;                     /* skip DefaultIndex */
    BaseCoordCount = FT_NEXT_USHORT( p );

    OTV_TRACE(( " (BaseCoordCount = %d)\n", BaseCoordCount ));

    OTV_LIMIT_CHECK( BaseCoordCount * 2 );

    /* BaseCoord */
    for ( ; BaseCoordCount > 0; BaseCoordCount-- )
      otv_BaseCoord_validate( table + FT_NEXT_USHORT( p ), valid );

    OTV_EXIT;
  }

__attribute__((used)) static void
  otv_MinMax_validate( FT_Bytes       table,
                       OTV_Validator  valid )
  {
    FT_Bytes  p = table;
    FT_UInt   table_size;
    FT_UInt   FeatMinMaxCount;

    OTV_OPTIONAL_TABLE( MinCoord );
    OTV_OPTIONAL_TABLE( MaxCoord );


    OTV_NAME_ENTER( "MinMax" );

    OTV_LIMIT_CHECK( 6 );

    OTV_OPTIONAL_OFFSET( MinCoord );
    OTV_OPTIONAL_OFFSET( MaxCoord );
    FeatMinMaxCount = FT_NEXT_USHORT( p );

    OTV_TRACE(( " (FeatMinMaxCount = %d)\n", FeatMinMaxCount ));

    table_size = FeatMinMaxCount * 8 + 6;

    OTV_SIZE_CHECK( MinCoord );
    if ( MinCoord )
      otv_BaseCoord_validate( table + MinCoord, valid );

    OTV_SIZE_CHECK( MaxCoord );
    if ( MaxCoord )
      otv_BaseCoord_validate( table + MaxCoord, valid );

    OTV_LIMIT_CHECK( FeatMinMaxCount * 8 );

    /* FeatMinMaxRecord */
    for ( ; FeatMinMaxCount > 0; FeatMinMaxCount-- )
    {
      p += 4;                           /* skip FeatureTableTag */

      OTV_OPTIONAL_OFFSET( MinCoord );
      OTV_OPTIONAL_OFFSET( MaxCoord );

      OTV_SIZE_CHECK( MinCoord );
      if ( MinCoord )
        otv_BaseCoord_validate( table + MinCoord, valid );

      OTV_SIZE_CHECK( MaxCoord );
      if ( MaxCoord )
        otv_BaseCoord_validate( table + MaxCoord, valid );
    }

    OTV_EXIT;
  }

__attribute__((used)) static void
  otv_BaseScript_validate( FT_Bytes       table,
                           OTV_Validator  valid )
  {
    FT_Bytes  p = table;
    FT_UInt   table_size;
    FT_UInt   BaseLangSysCount;

    OTV_OPTIONAL_TABLE( BaseValues    );
    OTV_OPTIONAL_TABLE( DefaultMinMax );


    OTV_NAME_ENTER( "BaseScript" );

    OTV_LIMIT_CHECK( 6 );
    OTV_OPTIONAL_OFFSET( BaseValues    );
    OTV_OPTIONAL_OFFSET( DefaultMinMax );
    BaseLangSysCount = FT_NEXT_USHORT( p );

    OTV_TRACE(( " (BaseLangSysCount = %d)\n", BaseLangSysCount ));

    table_size = BaseLangSysCount * 6 + 6;

    OTV_SIZE_CHECK( BaseValues );
    if ( BaseValues )
      otv_BaseValues_validate( table + BaseValues, valid );

    OTV_SIZE_CHECK( DefaultMinMax );
    if ( DefaultMinMax )
      otv_MinMax_validate( table + DefaultMinMax, valid );

    OTV_LIMIT_CHECK( BaseLangSysCount * 6 );

    /* BaseLangSysRecord */
    for ( ; BaseLangSysCount > 0; BaseLangSysCount-- )
    {
      p += 4;       /* skip BaseLangSysTag */

      otv_MinMax_validate( table + FT_NEXT_USHORT( p ), valid );
    }

    OTV_EXIT;
  }

__attribute__((used)) static void
  otv_BaseScriptList_validate( FT_Bytes       table,
                               OTV_Validator  valid )
  {
    FT_Bytes  p = table;
    FT_UInt   BaseScriptCount;


    OTV_NAME_ENTER( "BaseScriptList" );

    OTV_LIMIT_CHECK( 2 );
    BaseScriptCount = FT_NEXT_USHORT( p );

    OTV_TRACE(( " (BaseScriptCount = %d)\n", BaseScriptCount ));

    OTV_LIMIT_CHECK( BaseScriptCount * 6 );

    /* BaseScriptRecord */
    for ( ; BaseScriptCount > 0; BaseScriptCount-- )
    {
      p += 4;       /* skip BaseScriptTag */

      /* BaseScript */
      otv_BaseScript_validate( table + FT_NEXT_USHORT( p ), valid );
    }

    OTV_EXIT;
  }

__attribute__((used)) static void
  otv_Axis_validate( FT_Bytes       table,
                     OTV_Validator  valid )
  {
    FT_Bytes  p = table;
    FT_UInt   table_size;

    OTV_OPTIONAL_TABLE( BaseTagList );


    OTV_NAME_ENTER( "Axis" );

    OTV_LIMIT_CHECK( 4 );
    OTV_OPTIONAL_OFFSET( BaseTagList );

    table_size = 4;

    OTV_SIZE_CHECK( BaseTagList );
    if ( BaseTagList )
      otv_BaseTagList_validate( table + BaseTagList, valid );

    /* BaseScriptList */
    otv_BaseScriptList_validate( table + FT_NEXT_USHORT( p ), valid );

    OTV_EXIT;
  }

