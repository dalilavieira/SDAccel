#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_20__   TYPE_8__ ;
typedef  struct TYPE_19__   TYPE_7__ ;
typedef  struct TYPE_18__   TYPE_6__ ;
typedef  struct TYPE_17__   TYPE_5__ ;
typedef  struct TYPE_16__   TYPE_4__ ;
typedef  struct TYPE_15__   TYPE_3__ ;
typedef  struct TYPE_14__   TYPE_2__ ;
typedef  struct TYPE_13__   TYPE_1__ ;

/* Type definitions */
struct TYPE_16__ {int member_0; int member_1; } ;
struct TYPE_15__ {int member_0; int member_1; } ;
struct TYPE_14__ {int member_0; int member_1; } ;
struct TYPE_18__ {scalar_t__ Length; int CheckSum; TYPE_4__ member_2; TYPE_3__ member_1; TYPE_2__ member_0; } ;
typedef  TYPE_6__ tt_sfnt_id_rec ;
struct TYPE_20__ {scalar_t__ family_name; } ;
struct TYPE_13__ {int /*<<< orphan*/  stream; } ;
struct TYPE_19__ {int num_tables; TYPE_5__* dir_tables; TYPE_1__ root; int /*<<< orphan*/  (* goto_table ) (TYPE_7__*,int,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ;} ;
struct TYPE_17__ {int CheckSum; int Tag; int Length; } ;
typedef  TYPE_7__* TT_Face ;
typedef  size_t FT_UShort ;
typedef  int FT_ULong ;
typedef  scalar_t__ FT_UInt32 ;
typedef  int /*<<< orphan*/  FT_Stream ;
typedef  TYPE_8__* FT_Face ;
typedef  int /*<<< orphan*/  FT_Error ;
typedef  scalar_t__ FT_Bool ;

/* Variables and functions */
 scalar_t__ FALSE ; 
 scalar_t__ FT_FRAME_ENTER (int) ; 
 int /*<<< orphan*/  FT_FRAME_EXIT () ; 
 int FT_GET_BYTE () ; 
 scalar_t__ FT_GET_ULONG () ; 
 int /*<<< orphan*/  FT_MEM_SET (int*,int /*<<< orphan*/ ,int) ; 
 scalar_t__ TRUE ; 
#define  TTAG_cvt 130 
#define  TTAG_fpgm 129 
#define  TTAG_prep 128 
 int /*<<< orphan*/  stub1 (TYPE_7__*,int,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 scalar_t__ tt_check_trickyness_family (scalar_t__) ; 

__attribute__((used)) static FT_UInt32
  tt_synth_sfnt_checksum( FT_Stream  stream,
                          FT_ULong   length )
  {
    FT_Error   error;
    FT_UInt32  checksum = 0;
    int        i;


    if ( FT_FRAME_ENTER( length ) )
      return 0;

    for ( ; length > 3; length -= 4 )
      checksum += (FT_UInt32)FT_GET_ULONG();

    for ( i = 3; length > 0; length --, i-- )
      checksum += (FT_UInt32)( FT_GET_BYTE() << ( i * 8 ) );

    FT_FRAME_EXIT();

    return checksum;
  }

__attribute__((used)) static FT_ULong
  tt_get_sfnt_checksum( TT_Face    face,
                        FT_UShort  i )
  {
    if ( face->dir_tables[i].CheckSum )
      return face->dir_tables[i].CheckSum;

    else if ( !face->goto_table )
      return 0;

    else if ( !face->goto_table( face,
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

