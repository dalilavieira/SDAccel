#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_33__   TYPE_9__ ;
typedef  struct TYPE_32__   TYPE_8__ ;
typedef  struct TYPE_31__   TYPE_7__ ;
typedef  struct TYPE_30__   TYPE_6__ ;
typedef  struct TYPE_29__   TYPE_4__ ;
typedef  struct TYPE_28__   TYPE_3__ ;
typedef  struct TYPE_27__   TYPE_2__ ;
typedef  struct TYPE_26__   TYPE_1__ ;

/* Type definitions */
struct TYPE_33__ {int index1; int index2; int x; int y; } ;
struct TYPE_32__ {int (* get_index ) (char const*,scalar_t__,void*) ;TYPE_4__* FontInfo; } ;
struct TYPE_31__ {int degree; int min_ptsize; int min_kern; int max_ptsize; int max_kern; } ;
struct TYPE_30__ {int /*<<< orphan*/  memory; } ;
struct TYPE_26__ {int xMin; int yMin; int xMax; int yMax; } ;
struct TYPE_29__ {int Ascender; int Descender; int NumTrackKern; scalar_t__ TrackKerns; int NumKernPair; scalar_t__ KernPairs; int /*<<< orphan*/  memory; int /*<<< orphan*/  limit; int /*<<< orphan*/  cursor; int /*<<< orphan*/  size; TYPE_1__ FontBBox; scalar_t__ IsCIDFont; } ;
struct TYPE_28__ {TYPE_2__* afm_parser_funcs; } ;
struct TYPE_27__ {int (* init ) (TYPE_8__*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ;int (* parse ) (TYPE_8__*) ;int /*<<< orphan*/  (* done ) (TYPE_8__*) ;} ;
typedef  TYPE_3__* PSAux_Service ;
typedef  scalar_t__ FT_UInt ;
typedef  TYPE_4__ FT_StreamRec ;
typedef  TYPE_4__* FT_Stream ;
typedef  scalar_t__ FT_Offset ;
typedef  int /*<<< orphan*/  FT_Memory ;
typedef  TYPE_6__* FT_Library ;
typedef  int FT_Error ;
typedef  TYPE_7__* AFM_TrackKern ;
typedef  TYPE_8__ AFM_ParserRec ;
typedef  TYPE_9__* AFM_KernPair ;
typedef  TYPE_4__ AFM_FontInfoRec ;
typedef  TYPE_4__* AFM_FontInfo ;

/* Variables and functions */
 int /*<<< orphan*/  FT_Done_FreeType (TYPE_6__*) ; 
 int FT_ERR (int /*<<< orphan*/ ) ; 
 int FT_Err_Ok ; 
 int /*<<< orphan*/  FT_FREE (scalar_t__) ; 
 scalar_t__ FT_Get_Module_Interface (TYPE_6__*,char*) ; 
 int FT_Init_FreeType (TYPE_6__**) ; 
 int /*<<< orphan*/  FT_Stream_Close (TYPE_4__*) ; 
 int FT_Stream_EnterFrame (TYPE_4__*,int /*<<< orphan*/ ) ; 
 int FT_Stream_Open (TYPE_4__*,char*) ; 
 int /*<<< orphan*/  FT_ZERO (TYPE_4__*) ; 
 int /*<<< orphan*/  Invalid_Argument ; 
 int /*<<< orphan*/  printf (char*,...) ; 
 int stub1 (TYPE_8__*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int stub2 (TYPE_8__*) ; 
 int /*<<< orphan*/  stub3 (TYPE_8__*) ; 

void dump_fontinfo( AFM_FontInfo  fi )
  {
    FT_UInt  i;


    printf( "This AFM is for %sCID font.\n\n",
            ( fi->IsCIDFont ) ? "" : "non-" );

    printf( "FontBBox: %.2f %.2f %.2f %.2f\n", fi->FontBBox.xMin / 65536.,
                                               fi->FontBBox.yMin / 65536.,
                                               fi->FontBBox.xMax / 65536.,
                                               fi->FontBBox.yMax / 65536. );
    printf( "Ascender: %.2f\n", fi->Ascender / 65536. );
    printf( "Descender: %.2f\n\n", fi->Descender / 65536. );

    if ( fi->NumTrackKern )
      printf( "There are %d sets of track kernings:\n",
              fi->NumTrackKern );
    else
      printf( "There is no track kerning.\n" );

    for ( i = 0; i < fi->NumTrackKern; i++ )
    {
      AFM_TrackKern  tk = fi->TrackKerns + i;


      printf( "\t%2d: %5.2f %5.2f %5.2f %5.2f\n", tk->degree,
                                                  tk->min_ptsize / 65536.,
                                                  tk->min_kern / 65536.,
                                                  tk->max_ptsize / 65536.,
                                                  tk->max_kern / 65536. );
    }

    printf( "\n" );

    if ( fi->NumKernPair )
      printf( "There are %d kerning pairs:\n",
              fi->NumKernPair );
    else
      printf( "There is no kerning pair.\n" );

    for ( i = 0; i < fi->NumKernPair; i++ )
    {
      AFM_KernPair  kp = fi->KernPairs + i;


      printf( "\t%3d + %3d => (%4d, %4d)\n", kp->index1,
                                             kp->index2,
                                             kp->x,
                                             kp->y );
    }

  }

int
  dummy_get_index( const char*  name,
                   FT_Offset    len,
                   void*        user_data )
  {
    if ( len )
      return name[0];
    else
      return 0;
  }

FT_Error
  parse_afm( FT_Library    library,
             FT_Stream     stream,
             AFM_FontInfo  fi )
  {
    PSAux_Service  psaux;
    AFM_ParserRec  parser;
    FT_Error       error = FT_Err_Ok;


    psaux = (PSAux_Service)FT_Get_Module_Interface( library, "psaux" );
    if ( !psaux || !psaux->afm_parser_funcs )
      return -1;

    error = FT_Stream_EnterFrame( stream, stream->size );
    if ( error )
      return error;

    error = psaux->afm_parser_funcs->init( &parser,
                                           library->memory,
                                           stream->cursor,
                                           stream->limit );
    if ( error )
      return error;

    parser.FontInfo = fi;
    parser.get_index = dummy_get_index;

    error = psaux->afm_parser_funcs->parse( &parser );

    psaux->afm_parser_funcs->done( &parser );

    return error;
  }

int main( int    argc,
            char** argv )
  {
    FT_Library       library;
    FT_StreamRec     stream;
    FT_Error         error = FT_Err_Ok;
    AFM_FontInfoRec  fi;


    if ( argc < 2 )
      return FT_ERR( Invalid_Argument );

    error = FT_Init_FreeType( &library );
    if ( error )
      return error;

    FT_ZERO( &stream );
    error = FT_Stream_Open( &stream, argv[1] );
    if ( error )
      goto Exit;
    stream.memory = library->memory;

    FT_ZERO( &fi );
    error = parse_afm( library, &stream, &fi );

    if ( !error )
    {
      FT_Memory  memory = library->memory;


      dump_fontinfo( &fi );

      if ( fi.KernPairs )
        FT_FREE( fi.KernPairs );
      if ( fi.TrackKerns )
        FT_FREE( fi.TrackKerns );
    }
    else
      printf( "parse error\n" );

    FT_Stream_Close( &stream );

  Exit:
    FT_Done_FreeType( library );

    return error;
  }

