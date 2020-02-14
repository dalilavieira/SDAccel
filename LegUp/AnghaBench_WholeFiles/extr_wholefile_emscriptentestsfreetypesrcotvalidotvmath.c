#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_11__   TYPE_1__ ;

/* Type definitions */
struct TYPE_11__ {int glyph_count; } ;
typedef  TYPE_1__* OTV_Validator ;
typedef  int FT_UInt ;
typedef  scalar_t__ FT_Int ;
typedef  int FT_Bytes ;

/* Variables and functions */
 int Coverage ; 
 int DeviceTableOffset ; 
 scalar_t__ FALSE ; 
 int /*<<< orphan*/  FT_INVALID_GLYPH_ID ; 
 int FT_NEXT_USHORT (int) ; 
 int /*<<< orphan*/  FT_UNUSED (scalar_t__) ; 
 int GlyphAssembly ; 
 int HCoverage ; 
 int MKRecordOffset ; 
 int /*<<< orphan*/  OTV_EXIT ; 
 int /*<<< orphan*/  OTV_LIMIT_CHECK (int) ; 
 int /*<<< orphan*/  OTV_NAME_ENTER (char*) ; 
 int /*<<< orphan*/  OTV_OPTIONAL_OFFSET (int) ; 
 int /*<<< orphan*/  OTV_OPTIONAL_TABLE (int) ; 
 int /*<<< orphan*/  OTV_SIZE_CHECK (int) ; 
 int Offset ; 
 scalar_t__ TRUE ; 
 int VCoverage ; 
 int /*<<< orphan*/  otv_Coverage_validate (int,TYPE_1__*,int) ; 
 int /*<<< orphan*/  otv_Device_validate (int,TYPE_1__*) ; 

__attribute__((used)) static void
  otv_MathItalicsCorrectionInfo_validate( FT_Bytes       table,
                                          OTV_Validator  valid,
                                          FT_Int         isItalic )
  {
    FT_Bytes  p = table;
    FT_UInt   i, cnt, table_size ;

    OTV_OPTIONAL_TABLE( Coverage );
    OTV_OPTIONAL_TABLE( DeviceTableOffset );

    FT_UNUSED( isItalic );  /* only used if tracing is active */


    OTV_NAME_ENTER( isItalic ? "MathItalicsCorrectionInfo"
                             : "MathTopAccentAttachment" );

    OTV_LIMIT_CHECK( 4 );

    OTV_OPTIONAL_OFFSET( Coverage );
    cnt = FT_NEXT_USHORT( p );

    OTV_LIMIT_CHECK( 4 * cnt );
    table_size = 4 + 4 * cnt;

    OTV_SIZE_CHECK( Coverage );
    otv_Coverage_validate( table + Coverage, valid, cnt );

    for ( i = 0; i < cnt; ++i )
    {
      p += 2;                                            /* Skip the value */
      OTV_OPTIONAL_OFFSET( DeviceTableOffset );
      OTV_SIZE_CHECK( DeviceTableOffset );
      if ( DeviceTableOffset )
        otv_Device_validate( table + DeviceTableOffset, valid );
    }

    OTV_EXIT;
  }

__attribute__((used)) static void
  otv_MathKern_validate( FT_Bytes       table,
                         OTV_Validator  valid )
  {
    FT_Bytes  p = table;
    FT_UInt   i, cnt, table_size;

    OTV_OPTIONAL_TABLE( DeviceTableOffset );


    /* OTV_NAME_ENTER( "MathKern" );*/

    OTV_LIMIT_CHECK( 2 );

    cnt = FT_NEXT_USHORT( p );

    OTV_LIMIT_CHECK( 4 * cnt + 2 );
    table_size = 4 + 4 * cnt;

    /* Heights */
    for ( i = 0; i < cnt; ++i )
    {
      p += 2;                                            /* Skip the value */
      OTV_OPTIONAL_OFFSET( DeviceTableOffset );
      OTV_SIZE_CHECK( DeviceTableOffset );
      if ( DeviceTableOffset )
        otv_Device_validate( table + DeviceTableOffset, valid );
    }

    /* One more Kerning value */
    for ( i = 0; i < cnt + 1; ++i )
    {
      p += 2;                                            /* Skip the value */
      OTV_OPTIONAL_OFFSET( DeviceTableOffset );
      OTV_SIZE_CHECK( DeviceTableOffset );
      if ( DeviceTableOffset )
        otv_Device_validate( table + DeviceTableOffset, valid );
    }

    OTV_EXIT;
  }

__attribute__((used)) static void
  otv_MathKernInfo_validate( FT_Bytes       table,
                             OTV_Validator  valid )
  {
    FT_Bytes  p = table;
    FT_UInt   i, j, cnt, table_size;

    OTV_OPTIONAL_TABLE( Coverage );
    OTV_OPTIONAL_TABLE( MKRecordOffset );


    OTV_NAME_ENTER( "MathKernInfo" );

    OTV_LIMIT_CHECK( 4 );

    OTV_OPTIONAL_OFFSET( Coverage );
    cnt = FT_NEXT_USHORT( p );

    OTV_LIMIT_CHECK( 8 * cnt );
    table_size = 4 + 8 * cnt;

    OTV_SIZE_CHECK( Coverage );
    otv_Coverage_validate( table + Coverage, valid, cnt );

    for ( i = 0; i < cnt; ++i )
    {
      for ( j = 0; j < 4; ++j )
      {
        OTV_OPTIONAL_OFFSET( MKRecordOffset );
        OTV_SIZE_CHECK( MKRecordOffset );
        if ( MKRecordOffset )
          otv_MathKern_validate( table + MKRecordOffset, valid );
      }
    }

    OTV_EXIT;
  }

__attribute__((used)) static void
  otv_MathGlyphInfo_validate( FT_Bytes       table,
                              OTV_Validator  valid )
  {
    FT_Bytes  p = table;
    FT_UInt   MathItalicsCorrectionInfo, MathTopAccentAttachment;
    FT_UInt   ExtendedShapeCoverage, MathKernInfo;


    OTV_NAME_ENTER( "MathGlyphInfo" );

    OTV_LIMIT_CHECK( 8 );

    MathItalicsCorrectionInfo = FT_NEXT_USHORT( p );
    MathTopAccentAttachment   = FT_NEXT_USHORT( p );
    ExtendedShapeCoverage     = FT_NEXT_USHORT( p );
    MathKernInfo              = FT_NEXT_USHORT( p );

    if ( MathItalicsCorrectionInfo )
      otv_MathItalicsCorrectionInfo_validate(
        table + MathItalicsCorrectionInfo, valid, TRUE );

    /* Italic correction and Top Accent Attachment have the same format */
    if ( MathTopAccentAttachment )
      otv_MathItalicsCorrectionInfo_validate(
        table + MathTopAccentAttachment, valid, FALSE );

    if ( ExtendedShapeCoverage )
    {
      OTV_NAME_ENTER( "ExtendedShapeCoverage" );
      otv_Coverage_validate( table + ExtendedShapeCoverage, valid, -1 );
      OTV_EXIT;
    }

    if ( MathKernInfo )
      otv_MathKernInfo_validate( table + MathKernInfo, valid );

    OTV_EXIT;
  }

__attribute__((used)) static void
  otv_GlyphAssembly_validate( FT_Bytes       table,
                              OTV_Validator  valid )
  {
    FT_Bytes  p = table;
    FT_UInt   pcnt, table_size;
    FT_UInt   i;

    OTV_OPTIONAL_TABLE( DeviceTableOffset );


    /* OTV_NAME_ENTER( "GlyphAssembly" ); */

    OTV_LIMIT_CHECK( 6 );

    p += 2;                           /* Skip the Italics Correction value */
    OTV_OPTIONAL_OFFSET( DeviceTableOffset );
    pcnt = FT_NEXT_USHORT( p );

    OTV_LIMIT_CHECK( 8 * pcnt );
    table_size = 6 + 8 * pcnt;

    OTV_SIZE_CHECK( DeviceTableOffset );
    if ( DeviceTableOffset )
      otv_Device_validate( table + DeviceTableOffset, valid );

    for ( i = 0; i < pcnt; ++i )
    {
      FT_UInt  gid;


      gid = FT_NEXT_USHORT( p );
      if ( gid >= valid->glyph_count )
        FT_INVALID_GLYPH_ID;
      p += 2*4;             /* skip the Start, End, Full, and Flags fields */
    }

    /* OTV_EXIT; */
  }

__attribute__((used)) static void
  otv_MathGlyphConstruction_validate( FT_Bytes       table,
                                      OTV_Validator  valid )
  {
    FT_Bytes  p = table;
    FT_UInt   vcnt, table_size;
    FT_UInt   i;

    OTV_OPTIONAL_TABLE( GlyphAssembly );


    /* OTV_NAME_ENTER( "MathGlyphConstruction" ); */

    OTV_LIMIT_CHECK( 4 );

    OTV_OPTIONAL_OFFSET( GlyphAssembly );
    vcnt = FT_NEXT_USHORT( p );

    OTV_LIMIT_CHECK( 4 * vcnt );
    table_size = 4 + 4 * vcnt;

    for ( i = 0; i < vcnt; ++i )
    {
      FT_UInt  gid;


      gid = FT_NEXT_USHORT( p );
      if ( gid >= valid->glyph_count )
        FT_INVALID_GLYPH_ID;
      p += 2;                          /* skip the size */
    }

    OTV_SIZE_CHECK( GlyphAssembly );
    if ( GlyphAssembly )
      otv_GlyphAssembly_validate( table+GlyphAssembly, valid );

    /* OTV_EXIT; */
  }

__attribute__((used)) static void
  otv_MathVariants_validate( FT_Bytes       table,
                             OTV_Validator  valid )
  {
    FT_Bytes  p = table;
    FT_UInt   vcnt, hcnt, i, table_size;

    OTV_OPTIONAL_TABLE( VCoverage );
    OTV_OPTIONAL_TABLE( HCoverage );
    OTV_OPTIONAL_TABLE( Offset );


    OTV_NAME_ENTER( "MathVariants" );

    OTV_LIMIT_CHECK( 10 );

    p += 2;                       /* Skip the MinConnectorOverlap constant */
    OTV_OPTIONAL_OFFSET( VCoverage );
    OTV_OPTIONAL_OFFSET( HCoverage );
    vcnt = FT_NEXT_USHORT( p );
    hcnt = FT_NEXT_USHORT( p );

    OTV_LIMIT_CHECK( 2 * vcnt + 2 * hcnt );
    table_size = 10 + 2 * vcnt + 2 * hcnt;

    OTV_SIZE_CHECK( VCoverage );
    if ( VCoverage )
      otv_Coverage_validate( table + VCoverage, valid, vcnt );

    OTV_SIZE_CHECK( HCoverage );
    if ( HCoverage )
      otv_Coverage_validate( table + HCoverage, valid, hcnt );

    for ( i = 0; i < vcnt; ++i )
    {
      OTV_OPTIONAL_OFFSET( Offset );
      OTV_SIZE_CHECK( Offset );
      otv_MathGlyphConstruction_validate( table + Offset, valid );
    }

    for ( i = 0; i < hcnt; ++i )
    {
      OTV_OPTIONAL_OFFSET( Offset );
      OTV_SIZE_CHECK( Offset );
      otv_MathGlyphConstruction_validate( table + Offset, valid );
    }

    OTV_EXIT;
  }

