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
typedef  struct TYPE_13__   TYPE_2__ ;
typedef  struct TYPE_12__   TYPE_1__ ;

/* Type definitions */
struct TYPE_14__ {scalar_t__ num_glyphs; TYPE_1__* stream; } ;
struct TYPE_13__ {int (* get_location ) (TYPE_4__*,scalar_t__,int*) ;scalar_t__ (* table_info ) (TYPE_4__*,scalar_t__,int*,int*,int*) ;} ;
struct TYPE_12__ {int* cursor; } ;
typedef  int FT_ULong ;
typedef  scalar_t__ FT_UInt ;
typedef  TYPE_1__* FT_Stream ;
typedef  TYPE_2__* FT_Service_TTGlyf ;
typedef  TYPE_2__* FT_Service_SFNT_Table ;
typedef  int FT_Int ;
typedef  TYPE_4__* FT_Face ;
typedef  scalar_t__ FT_Error ;
typedef  int* FT_Bytes ;
typedef  int FT_Bool ;

/* Variables and functions */
 int FALSE ; 
 scalar_t__ FT_Err_Ok ; 
 int /*<<< orphan*/  FT_FACE_FIND_SERVICE (TYPE_4__*,TYPE_2__*,int /*<<< orphan*/ ) ; 
 scalar_t__ FT_FRAME_ENTER (int) ; 
 int /*<<< orphan*/  FT_FRAME_EXIT () ; 
 scalar_t__ FT_READ_SHORT (int) ; 
 scalar_t__ FT_READ_USHORT (int) ; 
 scalar_t__ FT_STREAM_SEEK (int) ; 
 scalar_t__ FT_STREAM_SKIP (scalar_t__) ; 
 int /*<<< orphan*/  FT_UNUSED (scalar_t__) ; 
 int /*<<< orphan*/  SFNT_TABLE ; 
 int TRUE ; 
 int TTAG_fpgm ; 
 int TTAG_prep ; 
 int /*<<< orphan*/  TT_GLYF ; 
 scalar_t__ stub1 (TYPE_4__*,scalar_t__,int*,int*,int*) ; 
 int stub2 (TYPE_4__*,scalar_t__,int*) ; 

__attribute__((used)) static FT_Bool
  _tt_check_patents_in_range( FT_Stream  stream,
                              FT_ULong   size )
  {
    FT_Bool   result = FALSE;
    FT_Error  error;
    FT_Bytes  p, end;


    if ( FT_FRAME_ENTER( size ) )
      return 0;

    p   = stream->cursor;
    end = p + size;

    while ( p < end )
    {
      switch (p[0])
      {
      case 0x06:  /* SPvTL // */
      case 0x07:  /* SPvTL +  */
      case 0x08:  /* SFvTL // */
      case 0x09:  /* SFvTL +  */
      case 0x0A:  /* SPvFS    */
      case 0x0B:  /* SFvFS    */
        result = TRUE;
        goto Exit;

      case 0x40:
        if ( p + 1 >= end )
          goto Exit;

        p += p[1] + 2;
        break;

      case 0x41:
        if ( p + 1 >= end )
          goto Exit;

        p += p[1] * 2 + 2;
        break;

      case 0x71:  /* DELTAP2 */
      case 0x72:  /* DELTAP3 */
      case 0x73:  /* DELTAC0 */
      case 0x74:  /* DELTAC1 */
      case 0x75:  /* DELTAC2 */
        result = TRUE;
        goto Exit;

      case 0xB0:
      case 0xB1:
      case 0xB2:
      case 0xB3:
      case 0xB4:
      case 0xB5:
      case 0xB6:
      case 0xB7:
        p += ( p[0] - 0xB0 ) + 2;
        break;

      case 0xB8:
      case 0xB9:
      case 0xBA:
      case 0xBB:
      case 0xBC:
      case 0xBD:
      case 0xBE:
      case 0xBF:
        p += ( p[0] - 0xB8 ) * 2 + 3;
        break;

      default:
        p += 1;
        break;
      }
    }

  Exit:
    FT_UNUSED( error );
    FT_FRAME_EXIT();
    return result;
  }

__attribute__((used)) static FT_Bool
  _tt_check_patents_in_table( FT_Face   face,
                              FT_ULong  tag )
  {
    FT_Stream              stream = face->stream;
    FT_Error               error  = FT_Err_Ok;
    FT_Service_SFNT_Table  service;
    FT_Bool                result = FALSE;


    FT_FACE_FIND_SERVICE( face, service, SFNT_TABLE );

    if ( service )
    {
      FT_UInt   i = 0;
      FT_ULong  tag_i = 0, offset_i = 0, length_i = 0;


      for ( i = 0; !error && tag_i != tag ; i++ )
        error = service->table_info( face, i,
                                     &tag_i, &offset_i, &length_i );

      if ( error                      ||
           FT_STREAM_SEEK( offset_i ) )
        goto Exit;

      result = _tt_check_patents_in_range( stream, length_i );
    }

  Exit:
    return result;
  }

__attribute__((used)) static FT_Bool
  _tt_face_check_patents( FT_Face  face )
  {
    FT_Stream  stream = face->stream;
    FT_UInt    gindex;
    FT_Error   error;
    FT_Bool    result;

    FT_Service_TTGlyf  service;


    result = _tt_check_patents_in_table( face, TTAG_fpgm );
    if ( result )
      goto Exit;

    result = _tt_check_patents_in_table( face, TTAG_prep );
    if ( result )
      goto Exit;

    FT_FACE_FIND_SERVICE( face, service, TT_GLYF );
    if ( service == NULL )
      goto Exit;

    for ( gindex = 0; gindex < (FT_UInt)face->num_glyphs; gindex++ )
    {
      FT_ULong  offset, num_ins, size;
      FT_Int    num_contours;


      offset = service->get_location( face, gindex, &size );
      if ( size == 0 )
        continue;

      if ( FT_STREAM_SEEK( offset )      ||
           FT_READ_SHORT( num_contours ) )
        continue;

      if ( num_contours >= 0 )  /* simple glyph */
      {
        if ( FT_STREAM_SKIP( 8 + num_contours * 2 ) )
          continue;
      }
      else  /* compound glyph */
      {
        FT_Bool  has_instr = 0;


        if ( FT_STREAM_SKIP( 8 ) )
          continue;

        /* now read each component */
        for (;;)
        {
          FT_UInt  flags, toskip;


          if( FT_READ_USHORT( flags ) )
            break;

          toskip = 2 + 1 + 1;

          if ( ( flags & ( 1 << 0 ) ) != 0 )       /* ARGS_ARE_WORDS */
            toskip += 2;

          if ( ( flags & ( 1 << 3 ) ) != 0 )       /* WE_HAVE_A_SCALE */
            toskip += 2;
          else if ( ( flags & ( 1 << 6 ) ) != 0 )  /* WE_HAVE_X_Y_SCALE */
            toskip += 4;
          else if ( ( flags & ( 1 << 7 ) ) != 0 )  /* WE_HAVE_A_2x2 */
            toskip += 8;

          if ( ( flags & ( 1 << 8 ) ) != 0 )       /* WE_HAVE_INSTRUCTIONS */
            has_instr = 1;

          if ( FT_STREAM_SKIP( toskip ) )
            goto NextGlyph;

          if ( ( flags & ( 1 << 5 ) ) == 0 )       /* MORE_COMPONENTS */
            break;
        }

        if ( !has_instr )
          goto NextGlyph;
      }

      if ( FT_READ_USHORT( num_ins ) )
        continue;

      result = _tt_check_patents_in_range( stream, num_ins );
      if ( result )
        goto Exit;

    NextGlyph:
      ;
    }

  Exit:
    return result;
  }

