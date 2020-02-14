#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_23__   TYPE_8__ ;
typedef  struct TYPE_22__   TYPE_7__ ;
typedef  struct TYPE_21__   TYPE_6__ ;
typedef  struct TYPE_20__   TYPE_5__ ;
typedef  struct TYPE_19__   TYPE_4__ ;
typedef  struct TYPE_18__   TYPE_3__ ;
typedef  struct TYPE_17__   TYPE_2__ ;
typedef  struct TYPE_16__   TYPE_1__ ;

/* Type definitions */
struct TYPE_20__ {int member_0; int member_1; } ;
struct TYPE_19__ {int member_0; int member_1; } ;
struct TYPE_18__ {int member_0; int member_1; } ;
struct TYPE_21__ {scalar_t__ Length; int CheckSum; TYPE_5__ member_2; TYPE_4__ member_1; TYPE_3__ member_0; } ;
typedef  TYPE_6__ tt_sfnt_id_rec ;
struct TYPE_23__ {scalar_t__ family_name; } ;
struct TYPE_16__ {int /*<<< orphan*/  stream; } ;
struct TYPE_22__ {size_t num_tables; int num_locations; TYPE_2__* dir_tables; TYPE_1__ root; scalar_t__ (* goto_table ) (TYPE_7__*,int,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ;} ;
struct TYPE_17__ {int Tag; int Length; } ;
typedef  TYPE_7__* TT_Face ;
typedef  size_t FT_UShort ;
typedef  int FT_ULong ;
typedef  int FT_UInt32 ;
typedef  int FT_UInt ;
typedef  int /*<<< orphan*/  FT_Stream ;
typedef  TYPE_8__* FT_Face ;
typedef  int /*<<< orphan*/  FT_Error ;
typedef  scalar_t__ FT_Bool ;

/* Variables and functions */
 scalar_t__ FALSE ; 
 scalar_t__ FT_FRAME_ENTER (int) ; 
 int /*<<< orphan*/  FT_FRAME_EXIT () ; 
 scalar_t__ FT_GET_BYTE () ; 
 scalar_t__ FT_GET_ULONG () ; 
 int /*<<< orphan*/  FT_Get_Glyph_Name (TYPE_8__*,int,char*,int) ; 
 int /*<<< orphan*/  FT_MEM_SET (int*,int /*<<< orphan*/ ,int) ; 
 scalar_t__ TRUE ; 
#define  TTAG_cvt 130 
#define  TTAG_fpgm 129 
#define  TTAG_prep 128 
 int /*<<< orphan*/  ft_strncmp (char*,char*,int) ; 
 scalar_t__ stub1 (TYPE_7__*,int,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 scalar_t__ tt_check_trickyness_family (scalar_t__) ; 
 int /*<<< orphan*/  tt_face_get_location (TYPE_7__*,int,int*) ; 

__attribute__((used)) static FT_UInt32
  tt_synth_sfnt_checksum( FT_Stream  stream,
                          FT_ULong   length )
  {
    FT_Error   error;
    FT_UInt32  checksum = 0;
    FT_UInt    i;


    if ( FT_FRAME_ENTER( length ) )
      return 0;

    for ( ; length > 3; length -= 4 )
      checksum += (FT_UInt32)FT_GET_ULONG();

    for ( i = 3; length > 0; length--, i-- )
      checksum += (FT_UInt32)FT_GET_BYTE() << ( i * 8 );

    FT_FRAME_EXIT();

    return checksum;
  }

__attribute__((used)) static FT_ULong
  tt_get_sfnt_checksum( TT_Face    face,
                        FT_UShort  i )
  {
#if 0 /* if we believe the written value, use following part. */
    if ( face->dir_tables[i].CheckSum )
      return face->dir_tables[i].CheckSum;
#endif

    if ( !face->goto_table )
      return 0;

    if ( face->goto_table( face,
                           face->dir_tables[i].Tag,
                           face->root.stream,
                           NULL ) )
      return 0;

    return (FT_ULong)tt_synth_sfnt_checksum( face->root.stream,
                                             face->dir_tables[i].Length );
  }

__attribute__((used)) static FT_Bool
  tt_check_trickyness_sfnt_ids( TT_Face  face )
  {
#define TRICK_SFNT_IDS_PER_FACE   3
#define TRICK_SFNT_IDS_NUM_FACES  26

    static const tt_sfnt_id_rec sfnt_id[TRICK_SFNT_IDS_NUM_FACES]
                                       [TRICK_SFNT_IDS_PER_FACE] = {

#define TRICK_SFNT_ID_cvt   0
#define TRICK_SFNT_ID_fpgm  1
#define TRICK_SFNT_ID_prep  2

      { /* MingLiU 1995 */
        { 0x05BCF058UL, 0x000002E4UL }, /* cvt  */
        { 0x28233BF1UL, 0x000087C4UL }, /* fpgm */
        { 0xA344A1EAUL, 0x000001E1UL }  /* prep */
      },
      { /* MingLiU 1996- */
        { 0x05BCF058UL, 0x000002E4UL }, /* cvt  */
        { 0x28233BF1UL, 0x000087C4UL }, /* fpgm */
        { 0xA344A1EBUL, 0x000001E1UL }  /* prep */
      },
      { /* DFGothic-EB */
        { 0x12C3EBB2UL, 0x00000350UL }, /* cvt  */
        { 0xB680EE64UL, 0x000087A7UL }, /* fpgm */
        { 0xCE939563UL, 0x00000758UL }  /* prep */
      },
      { /* DFGyoSho-Lt */
        { 0x11E5EAD4UL, 0x00000350UL }, /* cvt  */
        { 0xCE5956E9UL, 0x0000BC85UL }, /* fpgm */
        { 0x8272F416UL, 0x00000045UL }  /* prep */
      },
      { /* DFHSGothic-W5 */
        { 0x1262EB4EUL, 0x00000350UL }, /* cvt  */
        { 0xE86A5D64UL, 0x00007940UL }, /* fpgm */
        { 0x7850F729UL, 0x000005FFUL }  /* prep */
      },
      { /* DFHSMincho-W3 */
        { 0x122DEB0AUL, 0x00000350UL }, /* cvt  */
        { 0x3D16328AUL, 0x0000859BUL }, /* fpgm */
        { 0xA93FC33BUL, 0x000002CBUL }  /* prep */
      },
      { /* DFHSMincho-W7 */
        { 0x125FEB26UL, 0x00000350UL }, /* cvt  */
        { 0xA5ACC982UL, 0x00007EE1UL }, /* fpgm */
        { 0x90999196UL, 0x0000041FUL }  /* prep */
      },
      { /* DFKaiShu */
        { 0x11E5EAD4UL, 0x00000350UL }, /* cvt  */
        { 0x5A30CA3BUL, 0x00009063UL }, /* fpgm */
        { 0x13A42602UL, 0x0000007EUL }  /* prep */
      },
      { /* DFKaiShu, variant */
        { 0x11E5EAD4UL, 0x00000350UL }, /* cvt  */
        { 0xA6E78C01UL, 0x00008998UL }, /* fpgm */
        { 0x13A42602UL, 0x0000007EUL }  /* prep */
      },
      { /* DLCLiShu */
        { 0x07DCF546UL, 0x00000308UL }, /* cvt  */
        { 0x40FE7C90UL, 0x00008E2AUL }, /* fpgm */
        { 0x608174B5UL, 0x0000007AUL }  /* prep */
      },
      { /* DLCHayBold */
        { 0xEB891238UL, 0x00000308UL }, /* cvt  */
        { 0xD2E4DCD4UL, 0x0000676FUL }, /* fpgm */
        { 0x8EA5F293UL, 0x000003B8UL }  /* prep */
      },
      { /* HuaTianKaiTi */
        { 0xFFFBFFFCUL, 0x00000008UL }, /* cvt  */
        { 0x9C9E48B8UL, 0x0000BEA2UL }, /* fpgm */
        { 0x70020112UL, 0x00000008UL }  /* prep */
      },
      { /* HuaTianSongTi */
        { 0xFFFBFFFCUL, 0x00000008UL }, /* cvt  */
        { 0x0A5A0483UL, 0x00017C39UL }, /* fpgm */
        { 0x70020112UL, 0x00000008UL }  /* prep */
      },
      { /* NEC fadpop7.ttf */
        { 0x00000000UL, 0x00000000UL }, /* cvt  */
        { 0x40C92555UL, 0x000000E5UL }, /* fpgm */
        { 0xA39B58E3UL, 0x0000117CUL }  /* prep */
      },
      { /* NEC fadrei5.ttf */
        { 0x00000000UL, 0x00000000UL }, /* cvt  */
        { 0x33C41652UL, 0x000000E5UL }, /* fpgm */
        { 0x26D6C52AUL, 0x00000F6AUL }  /* prep */
      },
      { /* NEC fangot7.ttf */
        { 0x00000000UL, 0x00000000UL }, /* cvt  */
        { 0x6DB1651DUL, 0x0000019DUL }, /* fpgm */
        { 0x6C6E4B03UL, 0x00002492UL }  /* prep */
      },
      { /* NEC fangyo5.ttf */
        { 0x00000000UL, 0x00000000UL }, /* cvt  */
        { 0x40C92555UL, 0x000000E5UL }, /* fpgm */
        { 0xDE51FAD0UL, 0x0000117CUL }  /* prep */
      },
      { /* NEC fankyo5.ttf */
        { 0x00000000UL, 0x00000000UL }, /* cvt  */
        { 0x85E47664UL, 0x000000E5UL }, /* fpgm */
        { 0xA6C62831UL, 0x00001CAAUL }  /* prep */
      },
      { /* NEC fanrgo5.ttf */
        { 0x00000000UL, 0x00000000UL }, /* cvt  */
        { 0x2D891CFDUL, 0x0000019DUL }, /* fpgm */
        { 0xA0604633UL, 0x00001DE8UL }  /* prep */
      },
      { /* NEC fangot5.ttc */
        { 0x00000000UL, 0x00000000UL }, /* cvt  */
        { 0x40AA774CUL, 0x000001CBUL }, /* fpgm */
        { 0x9B5CAA96UL, 0x00001F9AUL }  /* prep */
      },
      { /* NEC fanmin3.ttc */
        { 0x00000000UL, 0x00000000UL }, /* cvt  */
        { 0x0D3DE9CBUL, 0x00000141UL }, /* fpgm */
        { 0xD4127766UL, 0x00002280UL }  /* prep */
      },
      { /* NEC FA-Gothic, 1996 */
        { 0x00000000UL, 0x00000000UL }, /* cvt  */
        { 0x4A692698UL, 0x000001F0UL }, /* fpgm */
        { 0x340D4346UL, 0x00001FCAUL }  /* prep */
      },
      { /* NEC FA-Minchou, 1996 */
        { 0x00000000UL, 0x00000000UL }, /* cvt  */
        { 0xCD34C604UL, 0x00000166UL }, /* fpgm */
        { 0x6CF31046UL, 0x000022B0UL }  /* prep */
      },
      { /* NEC FA-RoundGothicB, 1996 */
        { 0x00000000UL, 0x00000000UL }, /* cvt  */
        { 0x5DA75315UL, 0x0000019DUL }, /* fpgm */
        { 0x40745A5FUL, 0x000022E0UL }  /* prep */
      },
      { /* NEC FA-RoundGothicM, 1996 */
        { 0x00000000UL, 0x00000000UL }, /* cvt  */
        { 0xF055FC48UL, 0x000001C2UL }, /* fpgm */
        { 0x3900DED3UL, 0x00001E18UL }  /* prep */
      },
        { /* MINGLI.TTF, 1992 */
        { 0x00170003UL, 0x00000060UL }, /* cvt  */
        { 0xDBB4306EUL, 0x000058AAUL }, /* fpgm */
        { 0xD643482AUL, 0x00000035UL }  /* prep */
      }
    };

    FT_ULong   checksum;
    int        num_matched_ids[TRICK_SFNT_IDS_NUM_FACES];
    FT_Bool    has_cvt, has_fpgm, has_prep;
    FT_UShort  i;
    int        j, k;


    FT_MEM_SET( num_matched_ids, 0,
                sizeof ( int ) * TRICK_SFNT_IDS_NUM_FACES );
    has_cvt  = FALSE;
    has_fpgm = FALSE;
    has_prep = FALSE;

    for ( i = 0; i < face->num_tables; i++ )
    {
      checksum = 0;

      switch( face->dir_tables[i].Tag )
      {
      case TTAG_cvt:
        k = TRICK_SFNT_ID_cvt;
        has_cvt  = TRUE;
        break;

      case TTAG_fpgm:
        k = TRICK_SFNT_ID_fpgm;
        has_fpgm = TRUE;
        break;

      case TTAG_prep:
        k = TRICK_SFNT_ID_prep;
        has_prep = TRUE;
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

    for ( j = 0; j < TRICK_SFNT_IDS_NUM_FACES; j++ )
    {
      if ( !has_cvt  && !sfnt_id[j][TRICK_SFNT_ID_cvt].Length )
        num_matched_ids[j]++;
      if ( !has_fpgm && !sfnt_id[j][TRICK_SFNT_ID_fpgm].Length )
        num_matched_ids[j]++;
      if ( !has_prep && !sfnt_id[j][TRICK_SFNT_ID_prep].Length )
        num_matched_ids[j]++;
      if ( num_matched_ids[j] == TRICK_SFNT_IDS_PER_FACE )
        return TRUE;
    }

    return FALSE;
  }

__attribute__((used)) static FT_Bool
  tt_check_trickyness( FT_Face  face )
  {
    if ( !face )
      return FALSE;

    /* For first, check the face name for quick check. */
    if ( face->family_name                               &&
         tt_check_trickyness_family( face->family_name ) )
      return TRUE;

    /* Type42 fonts may lack `name' tables, we thus try to identify */
    /* tricky fonts by checking the checksums of Type42-persistent  */
    /* sfnt tables (`cvt', `fpgm', and `prep').                     */
    if ( tt_check_trickyness_sfnt_ids( (TT_Face)face ) )
      return TRUE;

    return FALSE;
  }

__attribute__((used)) static FT_Bool
  tt_check_single_notdef( FT_Face  ttface )
  {
    FT_Bool   result = FALSE;

    TT_Face   face = (TT_Face)ttface;
    FT_UInt   asize;
    FT_ULong  i;
    FT_ULong  glyph_index = 0;
    FT_UInt   count       = 0;


    for( i = 0; i < face->num_locations; i++ )
    {
      tt_face_get_location( face, i, &asize );
      if ( asize > 0 )
      {
        count += 1;
        if ( count > 1 )
          break;
        glyph_index = i;
      }
    }

    /* Only have a single outline. */
    if ( count == 1 )
    {
      if ( glyph_index == 0 )
        result = TRUE;
      else
      {
        /* FIXME: Need to test glyphname == .notdef ? */
        FT_Error error;
        char buf[8];


        error = FT_Get_Glyph_Name( ttface, glyph_index, buf, 8 );
        if ( !error                                            &&
             buf[0] == '.' && !ft_strncmp( buf, ".notdef", 8 ) )
          result = TRUE;
      }
    }

    return result;
  }

