#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_28__   TYPE_9__ ;
typedef  struct TYPE_27__   TYPE_8__ ;
typedef  struct TYPE_26__   TYPE_7__ ;
typedef  struct TYPE_25__   TYPE_6__ ;
typedef  struct TYPE_24__   TYPE_5__ ;
typedef  struct TYPE_23__   TYPE_4__ ;
typedef  struct TYPE_22__   TYPE_3__ ;
typedef  struct TYPE_21__   TYPE_2__ ;
typedef  struct TYPE_20__   TYPE_1__ ;

/* Type definitions */
struct TYPE_22__ {int member_0; int member_1; } ;
struct TYPE_21__ {int member_0; int member_1; } ;
struct TYPE_20__ {int member_0; int member_1; } ;
struct TYPE_24__ {scalar_t__ Length; scalar_t__ CheckSum; TYPE_3__ member_2; TYPE_2__ member_1; TYPE_1__ member_0; } ;
typedef  TYPE_5__ tt_sfnt_id_rec ;
struct TYPE_28__ {scalar_t__ family_name; scalar_t__ num_glyphs; } ;
struct TYPE_27__ {TYPE_9__* face; } ;
struct TYPE_26__ {int /*<<< orphan*/  face; } ;
struct TYPE_25__ {int num_tables; TYPE_4__* dir_tables; } ;
struct TYPE_23__ {int Tag; scalar_t__ Length; } ;
typedef  int /*<<< orphan*/  TT_Size ;
typedef  int /*<<< orphan*/  TT_GlyphSlot ;
typedef  TYPE_6__* TT_Face ;
typedef  int /*<<< orphan*/  FT_UShort ;
typedef  scalar_t__ FT_ULong ;
typedef  scalar_t__ FT_UInt ;
typedef  int /*<<< orphan*/  FT_Size_Request ;
typedef  TYPE_7__* FT_Size ;
typedef  int /*<<< orphan*/  FT_Short ;
typedef  int FT_Int32 ;
typedef  TYPE_8__* FT_GlyphSlot ;
typedef  int /*<<< orphan*/  FT_Fixed ;
typedef  TYPE_9__* FT_Face ;
typedef  int /*<<< orphan*/  FT_Error ;
typedef  scalar_t__ FT_Bool ;

/* Variables and functions */
 scalar_t__ FALSE ; 
 scalar_t__ FT_BOOL (int) ; 
 scalar_t__ FT_IS_SCALABLE (int /*<<< orphan*/ ) ; 
 scalar_t__ FT_IS_TRICKY (TYPE_9__*) ; 
 int FT_LOAD_IGNORE_GLOBAL_ADVANCE_WIDTH ; 
 int FT_LOAD_NO_AUTOHINT ; 
 int FT_LOAD_NO_BITMAP ; 
 int FT_LOAD_NO_HINTING ; 
 int FT_LOAD_NO_RECURSE ; 
 int FT_LOAD_NO_SCALE ; 
 int FT_LOAD_VERTICAL_LAYOUT ; 
 int /*<<< orphan*/  FT_MEM_SET (int*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  FT_Request_Metrics (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 scalar_t__ TRUE ; 
#define  TTAG_cvt 130 
#define  TTAG_fpgm 129 
#define  TTAG_prep 128 
 int /*<<< orphan*/  TT_Err_Invalid_Argument ; 
 int /*<<< orphan*/  TT_Err_Invalid_Size_Handle ; 
 int /*<<< orphan*/  TT_Err_Invalid_Slot_Handle ; 
 int /*<<< orphan*/  TT_Err_Ok ; 
 int /*<<< orphan*/  TT_Get_HMetrics (TYPE_6__*,scalar_t__,scalar_t__,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  TT_Get_VMetrics (TYPE_6__*,scalar_t__,scalar_t__,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  TT_Load_Glyph (int /*<<< orphan*/ ,int /*<<< orphan*/ ,scalar_t__,int) ; 
 scalar_t__ tt_check_trickyness_family (scalar_t__) ; 
 scalar_t__ tt_get_sfnt_checksum (TYPE_6__*,int) ; 
 int /*<<< orphan*/  tt_size_reset (int /*<<< orphan*/ ) ; 

__attribute__((used)) static FT_Error
  tt_get_advances( FT_Face    ttface,
                   FT_UInt    start,
                   FT_UInt    count,
                   FT_Int32   flags,
                   FT_Fixed  *advances )
  {
    FT_UInt  nn;
    TT_Face  face  = (TT_Face) ttface;
    FT_Bool  check = FT_BOOL(
                       !( flags & FT_LOAD_IGNORE_GLOBAL_ADVANCE_WIDTH ) );


    /* XXX: TODO: check for sbits */

    if ( flags & FT_LOAD_VERTICAL_LAYOUT )
    {
      for ( nn = 0; nn < count; nn++ )
      {
        FT_Short   tsb;
        FT_UShort  ah;


        TT_Get_VMetrics( face, start + nn, check, &tsb, &ah );
        advances[nn] = ah;
      }
    }
    else
    {
      for ( nn = 0; nn < count; nn++ )
      {
        FT_Short   lsb;
        FT_UShort  aw;


        TT_Get_HMetrics( face, start + nn, check, &lsb, &aw );
        advances[nn] = aw;
      }
    }

    return TT_Err_Ok;
  }

__attribute__((used)) static FT_Error
  tt_size_request( FT_Size          size,
                   FT_Size_Request  req )
  {
    TT_Size   ttsize = (TT_Size)size;
    FT_Error  error  = TT_Err_Ok;


#ifdef TT_CONFIG_OPTION_EMBEDDED_BITMAPS

    if ( FT_HAS_FIXED_SIZES( size->face ) )
    {
      TT_Face       ttface = (TT_Face)size->face;
      SFNT_Service  sfnt   = (SFNT_Service) ttface->sfnt;
      FT_ULong      strike_index;


      error = sfnt->set_sbit_strike( ttface, req, &strike_index );

      if ( error )
        ttsize->strike_index = 0xFFFFFFFFUL;
      else
        return tt_size_select( size, strike_index );
    }

#endif /* TT_CONFIG_OPTION_EMBEDDED_BITMAPS */

    FT_Request_Metrics( size->face, req );

    if ( FT_IS_SCALABLE( size->face ) )
      error = tt_size_reset( ttsize );

    return error;
  }

__attribute__((used)) static FT_Error
  Load_Glyph( FT_GlyphSlot  ttslot,         /* TT_GlyphSlot */
              FT_Size       ttsize,         /* TT_Size      */
              FT_UInt       glyph_index,
              FT_Int32      load_flags )
  {
    TT_GlyphSlot  slot = (TT_GlyphSlot)ttslot;
    TT_Size       size = (TT_Size)ttsize;
    FT_Face       face = ttslot->face;
    FT_Error      error;


    if ( !slot )
      return TT_Err_Invalid_Slot_Handle;

    if ( !size )
      return TT_Err_Invalid_Size_Handle;

    if ( !face )
      return TT_Err_Invalid_Argument;

#ifdef FT_CONFIG_OPTION_INCREMENTAL
    if ( glyph_index >= (FT_UInt)face->num_glyphs &&
         !face->internal->incremental_interface   )
#else
    if ( glyph_index >= (FT_UInt)face->num_glyphs )
#endif
      return TT_Err_Invalid_Argument;

    if ( load_flags & FT_LOAD_NO_HINTING )
    {
      /* both FT_LOAD_NO_HINTING and FT_LOAD_NO_AUTOHINT   */
      /* are necessary to disable hinting for tricky fonts */          

      if ( FT_IS_TRICKY( face ) )
        load_flags &= ~FT_LOAD_NO_HINTING;

      if ( load_flags & FT_LOAD_NO_AUTOHINT )
        load_flags |= FT_LOAD_NO_HINTING;
    }

    if ( load_flags & ( FT_LOAD_NO_RECURSE | FT_LOAD_NO_SCALE ) )
    {
      load_flags |= FT_LOAD_NO_BITMAP | FT_LOAD_NO_SCALE;

      if ( !FT_IS_TRICKY( face ) )
        load_flags |= FT_LOAD_NO_HINTING;
    }

    /* now load the glyph outline if necessary */
    error = TT_Load_Glyph( size, slot, glyph_index, load_flags );

    /* force drop-out mode to 2 - irrelevant now */
    /* slot->outline.dropout_mode = 2; */

    return error;
  }

__attribute__((used)) static FT_Bool
  tt_check_trickyness_sfnt_ids( TT_Face  face )
  {
#define TRICK_SFNT_IDS_PER_FACE   3
#define TRICK_SFNT_IDS_NUM_FACES  5

    static const tt_sfnt_id_rec sfnt_id[TRICK_SFNT_IDS_NUM_FACES]
                                       [TRICK_SFNT_IDS_PER_FACE] = {

#define TRICK_SFNT_ID_cvt   0
#define TRICK_SFNT_ID_fpgm  1
#define TRICK_SFNT_ID_prep  2

      { /* MingLiU 1995 */
        { 0x05bcf058, 0x000002e4 }, /* cvt  */
        { 0x28233bf1, 0x000087c4 }, /* fpgm */
        { 0xa344a1ea, 0x000001e1 }  /* prep */
      },
      { /* MingLiU 1996- */
        { 0x05bcf058, 0x000002e4 }, /* cvt  */
        { 0x28233bf1, 0x000087c4 }, /* fpgm */
        { 0xa344a1eb, 0x000001e1 }  /* prep */
      },
      { /* DFKaiShu */
        { 0x11e5ead4, 0x00000350 }, /* cvt  */
        { 0x5a30ca3b, 0x00009063 }, /* fpgm */
        { 0x13a42602, 0x0000007e }  /* prep */
      },
      { /* HuaTianKaiTi */
        { 0xfffbfffc, 0x00000008 }, /* cvt  */
        { 0x9c9e48b8, 0x0000bea2 }, /* fpgm */
        { 0x70020112, 0x00000008 }  /* prep */
      },
      { /* HuaTianSongTi */
        { 0xfffbfffc, 0x00000008 }, /* cvt  */
        { 0x0a5a0483, 0x00017c39 }, /* fpgm */
        { 0x70020112, 0x00000008 }  /* prep */
      }
    };

    FT_ULong  checksum;
    int       num_matched_ids[TRICK_SFNT_IDS_NUM_FACES];
    int       i, j, k;


    FT_MEM_SET( num_matched_ids, 0,
                sizeof( int ) * TRICK_SFNT_IDS_NUM_FACES );

    for ( i = 0; i < face->num_tables; i++ )
    {
      checksum = 0;

      switch( face->dir_tables[i].Tag )
      {
      case TTAG_cvt:
        k = TRICK_SFNT_ID_cvt;
        break;

      case TTAG_fpgm:
        k = TRICK_SFNT_ID_fpgm;
        break;

      case TTAG_prep:
        k = TRICK_SFNT_ID_prep;
        break;

      default:
        continue;
      }

      for ( j = 0; j < TRICK_SFNT_IDS_NUM_FACES; j++ )
        if ( face->dir_tables[i].Length == sfnt_id[j][k].Length )
        {
          if ( !checksum )
            checksum = tt_get_sfnt_checksum( face, i );

          if ( sfnt_id[j][k].CheckSum == checksum )
            num_matched_ids[j]++;

          if ( num_matched_ids[j] == TRICK_SFNT_IDS_PER_FACE )
            return TRUE;
        }
    }

    return FALSE;
  }

__attribute__((used)) static FT_Bool
  tt_check_trickyness( FT_Face  face )
  {
    if ( !face )
      return FALSE;

    /* First, check the face name. */
    if ( face->family_name )
    {
      if ( tt_check_trickyness_family( face->family_name ) )
        return TRUE;
      else
        return FALSE;
    }

    /* Type42 fonts may lack `name' tables, we thus try to identify */
    /* tricky fonts by checking the checksums of Type42-persistent  */
    /* sfnt tables (`cvt', `fpgm', and `prep').                     */
    if ( tt_check_trickyness_sfnt_ids( (TT_Face)face ) )
      return TRUE;

    return FALSE;
  }

