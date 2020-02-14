#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_28__   TYPE_7__ ;
typedef  struct TYPE_27__   TYPE_6__ ;
typedef  struct TYPE_26__   TYPE_4__ ;
typedef  struct TYPE_25__   TYPE_2__ ;
typedef  struct TYPE_24__   TYPE_21__ ;
typedef  struct TYPE_23__   TYPE_1__ ;

/* Type definitions */
struct TYPE_28__ {int width; int rows; int pitch; int* buffer; int /*<<< orphan*/  pixel_mode; } ;
struct TYPE_23__ {TYPE_21__* glyph; int /*<<< orphan*/  stream; } ;
struct TYPE_27__ {int* sbit_table; int sbit_table_size; TYPE_1__ root; void* (* goto_table ) (TYPE_6__*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int*) ;} ;
struct TYPE_26__ {int metrics_loaded; int bitmap_allocated; int ebdt_start; int ebdt_size; int* eblc_base; int* eblc_limit; int strike_index_array; int strike_index_count; int bit_depth; int /*<<< orphan*/  stream; TYPE_7__* bitmap; TYPE_2__* metrics; TYPE_6__* face; } ;
struct TYPE_25__ {scalar_t__ width; scalar_t__ height; int horiAdvance; int vertAdvance; void* vertBearingY; void* vertBearingX; void* horiBearingY; void* horiBearingX; } ;
struct TYPE_24__ {TYPE_7__ bitmap; } ;
typedef  TYPE_2__ TT_SBit_MetricsRec ;
typedef  TYPE_2__* TT_SBit_Metrics ;
typedef  void* (* TT_SBitDecoder_LoadFunc ) (TYPE_4__*,int*,int*,scalar_t__,scalar_t__) ;
typedef  TYPE_4__* TT_SBitDecoder ;
typedef  TYPE_6__* TT_Face ;
typedef  int FT_UShort ;
typedef  int FT_ULong ;
typedef  scalar_t__ FT_UInt ;
typedef  int /*<<< orphan*/  FT_Stream ;
typedef  int FT_Long ;
typedef  scalar_t__ FT_Int ;
typedef  void* FT_Error ;
typedef  void* FT_Char ;
typedef  int FT_Byte ;
typedef  int FT_Bool ;
typedef  TYPE_7__ FT_Bitmap ;

/* Variables and functions */
 scalar_t__ FT_FRAME_EXTRACT (int,int*) ; 
 int /*<<< orphan*/  FT_FRAME_RELEASE (int*) ; 
 int FT_NEXT_BYTE (int*) ; 
 void* FT_NEXT_ULONG (int*) ; 
 void* FT_NEXT_USHORT (int*) ; 
 int FT_PEEK_USHORT (int*) ; 
 int /*<<< orphan*/  FT_PIXEL_MODE_GRAY ; 
 int /*<<< orphan*/  FT_PIXEL_MODE_GRAY2 ; 
 int /*<<< orphan*/  FT_PIXEL_MODE_GRAY4 ; 
 int /*<<< orphan*/  FT_PIXEL_MODE_MONO ; 
 int FT_STREAM_POS () ; 
 scalar_t__ FT_STREAM_SEEK (int) ; 
 int /*<<< orphan*/  FT_UNUSED (TYPE_4__*) ; 
 void* SFNT_Err_Invalid_Argument ; 
 void* SFNT_Err_Invalid_File_Format ; 
 void* SFNT_Err_Invalid_Table ; 
 void* SFNT_Err_Ok ; 
 int /*<<< orphan*/  TTAG_EBDT ; 
 int /*<<< orphan*/  TTAG_bdat ; 
 void* ft_glyphslot_alloc_bitmap (TYPE_21__*,int) ; 
 void* stub1 (TYPE_6__*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int*) ; 
 void* stub2 (TYPE_6__*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int*) ; 
static  void* tt_sbit_decoder_load_image (TYPE_4__*,scalar_t__,scalar_t__,scalar_t__) ; 

__attribute__((used)) static FT_Error
  tt_sbit_decoder_init( TT_SBitDecoder       decoder,
                        TT_Face              face,
                        FT_ULong             strike_index,
                        TT_SBit_MetricsRec*  metrics )
  {
    FT_Error   error;
    FT_Stream  stream = face->root.stream;
    FT_ULong   ebdt_size;


    error = face->goto_table( face, TTAG_EBDT, stream, &ebdt_size );
    if ( error )
      error = face->goto_table( face, TTAG_bdat, stream, &ebdt_size );
    if ( error )
      goto Exit;

    decoder->face    = face;
    decoder->stream  = stream;
    decoder->bitmap  = &face->root.glyph->bitmap;
    decoder->metrics = metrics;

    decoder->metrics_loaded   = 0;
    decoder->bitmap_allocated = 0;

    decoder->ebdt_start = FT_STREAM_POS();
    decoder->ebdt_size  = ebdt_size;

    decoder->eblc_base  = face->sbit_table;
    decoder->eblc_limit = face->sbit_table + face->sbit_table_size;

    /* now find the strike corresponding to the index */
    {
      FT_Byte*  p;


      if ( 8 + 48 * strike_index + 3 * 4 + 34 + 1 > face->sbit_table_size )
      {
        error = SFNT_Err_Invalid_File_Format;
        goto Exit;
      }

      p = decoder->eblc_base + 8 + 48 * strike_index;

      decoder->strike_index_array = FT_NEXT_ULONG( p );
      p                          += 4;
      decoder->strike_index_count = FT_NEXT_ULONG( p );
      p                          += 34;
      decoder->bit_depth          = *p;

      if ( decoder->strike_index_array > face->sbit_table_size             ||
           decoder->strike_index_array + 8 * decoder->strike_index_count >
             face->sbit_table_size                                         )
        error = SFNT_Err_Invalid_File_Format;
    }

  Exit:
    return error;
  }

__attribute__((used)) static void
  tt_sbit_decoder_done( TT_SBitDecoder  decoder )
  {
    FT_UNUSED( decoder );
  }

__attribute__((used)) static FT_Error
  tt_sbit_decoder_alloc_bitmap( TT_SBitDecoder  decoder )
  {
    FT_Error    error = SFNT_Err_Ok;
    FT_UInt     width, height;
    FT_Bitmap*  map = decoder->bitmap;
    FT_Long     size;


    if ( !decoder->metrics_loaded )
    {
      error = SFNT_Err_Invalid_Argument;
      goto Exit;
    }

    width  = decoder->metrics->width;
    height = decoder->metrics->height;

    map->width = (int)width;
    map->rows  = (int)height;

    switch ( decoder->bit_depth )
    {
    case 1:
      map->pixel_mode = FT_PIXEL_MODE_MONO;
      map->pitch      = ( map->width + 7 ) >> 3;
      break;

    case 2:
      map->pixel_mode = FT_PIXEL_MODE_GRAY2;
      map->pitch      = ( map->width + 3 ) >> 2;
      break;

    case 4:
      map->pixel_mode = FT_PIXEL_MODE_GRAY4;
      map->pitch      = ( map->width + 1 ) >> 1;
      break;

    case 8:
      map->pixel_mode = FT_PIXEL_MODE_GRAY;
      map->pitch      = map->width;
      break;

    default:
      error = SFNT_Err_Invalid_File_Format;
      goto Exit;
    }

    size = map->rows * map->pitch;

    /* check that there is no empty image */
    if ( size == 0 )
      goto Exit;     /* exit successfully! */

    error = ft_glyphslot_alloc_bitmap( decoder->face->root.glyph, size );
    if ( error )
      goto Exit;

    decoder->bitmap_allocated = 1;

  Exit:
    return error;
  }

__attribute__((used)) static FT_Error
  tt_sbit_decoder_load_metrics( TT_SBitDecoder  decoder,
                                FT_Byte*       *pp,
                                FT_Byte*        limit,
                                FT_Bool         big )
  {
    FT_Byte*         p       = *pp;
    TT_SBit_Metrics  metrics = decoder->metrics;


    if ( p + 5 > limit )
      goto Fail;

    metrics->height       = p[0];
    metrics->width        = p[1];
    metrics->horiBearingX = (FT_Char)p[2];
    metrics->horiBearingY = (FT_Char)p[3];
    metrics->horiAdvance  = p[4];

    p += 5;
    if ( big )
    {
      if ( p + 3 > limit )
        goto Fail;

      metrics->vertBearingX = (FT_Char)p[0];
      metrics->vertBearingY = (FT_Char)p[1];
      metrics->vertAdvance  = p[2];

      p += 3;
    }

    decoder->metrics_loaded = 1;
    *pp = p;
    return SFNT_Err_Ok;

  Fail:
    return SFNT_Err_Invalid_Argument;
  }

__attribute__((used)) static FT_Error
  tt_sbit_decoder_load_byte_aligned( TT_SBitDecoder  decoder,
                                     FT_Byte*        p,
                                     FT_Byte*        limit,
                                     FT_Int          x_pos,
                                     FT_Int          y_pos )
  {
    FT_Error    error = SFNT_Err_Ok;
    FT_Byte*    line;
    FT_Int      bit_height, bit_width, pitch, width, height, h;
    FT_Bitmap*  bitmap;


    if ( !decoder->bitmap_allocated )
    {
      error = tt_sbit_decoder_alloc_bitmap( decoder );
      if ( error )
        goto Exit;
    }

    /* check that we can write the glyph into the bitmap */
    bitmap     = decoder->bitmap;
    bit_width  = bitmap->width;
    bit_height = bitmap->rows;
    pitch      = bitmap->pitch;
    line       = bitmap->buffer;

    width  = decoder->metrics->width;
    height = decoder->metrics->height;

    if ( x_pos < 0 || x_pos + width > bit_width   ||
         y_pos < 0 || y_pos + height > bit_height )
    {
      error = SFNT_Err_Invalid_File_Format;
      goto Exit;
    }

    if ( p + ( ( width + 7 ) >> 3 ) * height > limit )
    {
      error = SFNT_Err_Invalid_File_Format;
      goto Exit;
    }

    /* now do the blit */
    line  += y_pos * pitch + ( x_pos >> 3 );
    x_pos &= 7;

    if ( x_pos == 0 )  /* the easy one */
    {
      for ( h = height; h > 0; h--, line += pitch )
      {
        FT_Byte*  write = line;
        FT_Int    w;


        for ( w = width; w >= 8; w -= 8 )
        {
          write[0] = (FT_Byte)( write[0] | *p++ );
          write   += 1;
        }

        if ( w > 0 )
          write[0] = (FT_Byte)( write[0] | ( *p++ & ( 0xFF00U >> w ) ) );
      }
    }
    else  /* x_pos > 0 */
    {
      for ( h = height; h > 0; h--, line += pitch )
      {
        FT_Byte*  write = line;
        FT_Int    w;
        FT_UInt   wval = 0;


        for ( w = width; w >= 8; w -= 8 )
        {
          wval      = (FT_UInt)( wval | *p++ );
          write[0]  = (FT_Byte)( write[0] | ( wval >> x_pos ) );
          write    += 1;
          wval    <<= 8;
        }

        if ( w > 0 )
          wval = (FT_UInt)( wval | ( *p++ & ( 0xFF00U >> w ) ) );

        /* all bits read and there are `x_pos + w' bits to be written */

        write[0] = (FT_Byte)( write[0] | ( wval >> x_pos ) );

        if ( x_pos + w > 8 )
        {
          write++;
          wval   <<= 8;
          write[0] = (FT_Byte)( write[0] | ( wval >> x_pos ) );
        }
      }
    }

  Exit:
    return error;
  }

__attribute__((used)) static FT_Error
  tt_sbit_decoder_load_bit_aligned( TT_SBitDecoder  decoder,
                                    FT_Byte*        p,
                                    FT_Byte*        limit,
                                    FT_Int          x_pos,
                                    FT_Int          y_pos )
  {
    FT_Error    error = SFNT_Err_Ok;
    FT_Byte*    line;
    FT_Int      bit_height, bit_width, pitch, width, height, h, nbits;
    FT_Bitmap*  bitmap;
    FT_UShort   rval;


    if ( !decoder->bitmap_allocated )
    {
      error = tt_sbit_decoder_alloc_bitmap( decoder );
      if ( error )
        goto Exit;
    }

    /* check that we can write the glyph into the bitmap */
    bitmap     = decoder->bitmap;
    bit_width  = bitmap->width;
    bit_height = bitmap->rows;
    pitch      = bitmap->pitch;
    line       = bitmap->buffer;

    width  = decoder->metrics->width;
    height = decoder->metrics->height;

    if ( x_pos < 0 || x_pos + width  > bit_width  ||
         y_pos < 0 || y_pos + height > bit_height )
    {
      error = SFNT_Err_Invalid_File_Format;
      goto Exit;
    }

    if ( p + ( ( width * height + 7 ) >> 3 ) > limit )
    {
      error = SFNT_Err_Invalid_File_Format;
      goto Exit;
    }

    /* now do the blit */

    /* adjust `line' to point to the first byte of the bitmap */
    line  += y_pos * pitch + ( x_pos >> 3 );
    x_pos &= 7;

    /* the higher byte of `rval' is used as a buffer */
    rval  = 0;
    nbits = 0;

    for ( h = height; h > 0; h--, line += pitch )
    {
      FT_Byte*  write = line;
      FT_Int    w     = width;


      /* handle initial byte (in target bitmap) specially if necessary */
      if ( x_pos )
      {
        w = ( width < 8 - x_pos ) ? width : 8 - x_pos;

        if ( h == height )
        {
          rval  = *p++;
          nbits = x_pos;
        }
        else if ( nbits < w )
        {
          if ( p < limit )
            rval |= *p++;
          nbits += 8 - w;
        }
        else
        {
          rval  >>= 8;
          nbits  -= w;
        }

        *write++ |= ( ( rval >> nbits ) & 0xFF ) &
                    ( ~( 0xFF << w ) << ( 8 - w - x_pos ) );
        rval    <<= 8;

        w = width - w;
      }

      /* handle medial bytes */
      for ( ; w >= 8; w -= 8 )
      {
        rval     |= *p++;
        *write++ |= ( rval >> nbits ) & 0xFF;

        rval <<= 8;
      }

      /* handle final byte if necessary */
      if ( w > 0 )
      {
        if ( nbits < w )
        {
          if ( p < limit )
            rval |= *p++;
          *write |= ( ( rval >> nbits ) & 0xFF ) & ( 0xFF00U >> w );
          nbits  += 8 - w;

          rval <<= 8;
        }
        else
        {
          *write |= ( ( rval >> nbits ) & 0xFF ) & ( 0xFF00U >> w );
          nbits  -= w;
        }
      }
    }

  Exit:
    return error;
  }

__attribute__((used)) static FT_Error
  tt_sbit_decoder_load_compound( TT_SBitDecoder  decoder,
                                 FT_Byte*        p,
                                 FT_Byte*        limit,
                                 FT_Int          x_pos,
                                 FT_Int          y_pos )
  {
    FT_Error  error = SFNT_Err_Ok;
    FT_UInt   num_components, nn;

    FT_Char  horiBearingX = decoder->metrics->horiBearingX;
    FT_Char  horiBearingY = decoder->metrics->horiBearingY;
    FT_Byte  horiAdvance  = decoder->metrics->horiAdvance;
    FT_Char  vertBearingX = decoder->metrics->vertBearingX;
    FT_Char  vertBearingY = decoder->metrics->vertBearingY;
    FT_Byte  vertAdvance  = decoder->metrics->vertAdvance;


    if ( p + 2 > limit )
      goto Fail;

    num_components = FT_NEXT_USHORT( p );
    if ( p + 4 * num_components > limit )
      goto Fail;

    if ( !decoder->bitmap_allocated )
    {
      error = tt_sbit_decoder_alloc_bitmap( decoder );
      if ( error )
        goto Exit;
    }

    for ( nn = 0; nn < num_components; nn++ )
    {
      FT_UInt  gindex = FT_NEXT_USHORT( p );
      FT_Byte  dx     = FT_NEXT_BYTE( p );
      FT_Byte  dy     = FT_NEXT_BYTE( p );


      /* NB: a recursive call */
      error = tt_sbit_decoder_load_image( decoder, gindex,
                                          x_pos + dx, y_pos + dy );
      if ( error )
        break;
    }

    decoder->metrics->horiBearingX = horiBearingX;
    decoder->metrics->horiBearingY = horiBearingY;
    decoder->metrics->horiAdvance  = horiAdvance;
    decoder->metrics->vertBearingX = vertBearingX;
    decoder->metrics->vertBearingY = vertBearingY;
    decoder->metrics->vertAdvance  = vertAdvance;
    decoder->metrics->width        = (FT_UInt)decoder->bitmap->width;
    decoder->metrics->height       = (FT_UInt)decoder->bitmap->rows;

  Exit:
    return error;

  Fail:
    error = SFNT_Err_Invalid_File_Format;
    goto Exit;
  }

__attribute__((used)) static FT_Error
  tt_sbit_decoder_load_bitmap( TT_SBitDecoder  decoder,
                               FT_UInt         glyph_format,
                               FT_ULong        glyph_start,
                               FT_ULong        glyph_size,
                               FT_Int          x_pos,
                               FT_Int          y_pos )
  {
    FT_Error   error;
    FT_Stream  stream = decoder->stream;
    FT_Byte*   p;
    FT_Byte*   p_limit;
    FT_Byte*   data;


    /* seek into the EBDT table now */
    if ( glyph_start + glyph_size > decoder->ebdt_size )
    {
      error = SFNT_Err_Invalid_Argument;
      goto Exit;
    }

    if ( FT_STREAM_SEEK( decoder->ebdt_start + glyph_start ) ||
         FT_FRAME_EXTRACT( glyph_size, data )                )
      goto Exit;

    p       = data;
    p_limit = p + glyph_size;

    /* read the data, depending on the glyph format */
    switch ( glyph_format )
    {
    case 1:
    case 2:
    case 8:
      error = tt_sbit_decoder_load_metrics( decoder, &p, p_limit, 0 );
      break;

    case 6:
    case 7:
    case 9:
      error = tt_sbit_decoder_load_metrics( decoder, &p, p_limit, 1 );
      break;

    default:
      error = SFNT_Err_Ok;
    }

    if ( error )
      goto Fail;

    {
      TT_SBitDecoder_LoadFunc  loader;


      switch ( glyph_format )
      {
      case 1:
      case 6:
        loader = tt_sbit_decoder_load_byte_aligned;
        break;

      case 2:
      case 5:
      case 7:
        loader = tt_sbit_decoder_load_bit_aligned;
        break;

      case 8:
        if ( p + 1 > p_limit )
          goto Fail;

        p += 1;  /* skip padding */
        /* fall-through */

      case 9:
        loader = tt_sbit_decoder_load_compound;
        break;

      default:
        goto Fail;
      }

      error = loader( decoder, p, p_limit, x_pos, y_pos );
    }

  Fail:
    FT_FRAME_RELEASE( data );

  Exit:
    return error;
  }

__attribute__((used)) static FT_Error
  tt_sbit_decoder_load_image( TT_SBitDecoder  decoder,
                              FT_UInt         glyph_index,
                              FT_Int          x_pos,
                              FT_Int          y_pos )
  {
    /*
     *  First, we find the correct strike range that applies to this
     *  glyph index.
     */

    FT_Byte*  p          = decoder->eblc_base + decoder->strike_index_array;
    FT_Byte*  p_limit    = decoder->eblc_limit;
    FT_ULong  num_ranges = decoder->strike_index_count;
    FT_UInt   start, end, index_format, image_format;
    FT_ULong  image_start = 0, image_end = 0, image_offset;


    for ( ; num_ranges > 0; num_ranges-- )
    {
      start = FT_NEXT_USHORT( p );
      end   = FT_NEXT_USHORT( p );

      if ( glyph_index >= start && glyph_index <= end )
        goto FoundRange;

      p += 4;  /* ignore index offset */
    }
    goto NoBitmap;

  FoundRange:
    image_offset = FT_NEXT_ULONG( p );

    /* overflow check */
    if ( decoder->eblc_base + decoder->strike_index_array + image_offset <
           decoder->eblc_base )
      goto Failure;

    p = decoder->eblc_base + decoder->strike_index_array + image_offset;
    if ( p + 8 > p_limit )
      goto NoBitmap;

    /* now find the glyph's location and extend within the ebdt table */
    index_format = FT_NEXT_USHORT( p );
    image_format = FT_NEXT_USHORT( p );
    image_offset = FT_NEXT_ULONG ( p );

    switch ( index_format )
    {
    case 1: /* 4-byte offsets relative to `image_offset' */
      {
        p += 4 * ( glyph_index - start );
        if ( p + 8 > p_limit )
          goto NoBitmap;

        image_start = FT_NEXT_ULONG( p );
        image_end   = FT_NEXT_ULONG( p );

        if ( image_start == image_end )  /* missing glyph */
          goto NoBitmap;
      }
      break;

    case 2: /* big metrics, constant image size */
      {
        FT_ULong  image_size;


        if ( p + 12 > p_limit )
          goto NoBitmap;

        image_size = FT_NEXT_ULONG( p );

        if ( tt_sbit_decoder_load_metrics( decoder, &p, p_limit, 1 ) )
          goto NoBitmap;

        image_start = image_size * ( glyph_index - start );
        image_end   = image_start + image_size;
      }
      break;

    case 3: /* 2-byte offsets relative to 'image_offset' */
      {
        p += 2 * ( glyph_index - start );
        if ( p + 4 > p_limit )
          goto NoBitmap;

        image_start = FT_NEXT_USHORT( p );
        image_end   = FT_NEXT_USHORT( p );

        if ( image_start == image_end )  /* missing glyph */
          goto NoBitmap;
      }
      break;

    case 4: /* sparse glyph array with (glyph,offset) pairs */
      {
        FT_ULong  mm, num_glyphs;


        if ( p + 4 > p_limit )
          goto NoBitmap;

        num_glyphs = FT_NEXT_ULONG( p );

        /* overflow check */
        if ( p + ( num_glyphs + 1 ) * 4 < p )
          goto Failure;

        if ( p + ( num_glyphs + 1 ) * 4 > p_limit )
          goto NoBitmap;

        for ( mm = 0; mm < num_glyphs; mm++ )
        {
          FT_UInt  gindex = FT_NEXT_USHORT( p );


          if ( gindex == glyph_index )
          {
            image_start = FT_NEXT_USHORT( p );
            p          += 2;
            image_end   = FT_PEEK_USHORT( p );
            break;
          }
          p += 2;
        }

        if ( mm >= num_glyphs )
          goto NoBitmap;
      }
      break;

    case 5: /* constant metrics with sparse glyph codes */
      {
        FT_ULong  image_size, mm, num_glyphs;


        if ( p + 16 > p_limit )
          goto NoBitmap;

        image_size = FT_NEXT_ULONG( p );

        if ( tt_sbit_decoder_load_metrics( decoder, &p, p_limit, 1 ) )
          goto NoBitmap;

        num_glyphs = FT_NEXT_ULONG( p );

        /* overflow check */
        if ( p + 2 * num_glyphs < p )
          goto Failure;

        if ( p + 2 * num_glyphs > p_limit )
          goto NoBitmap;

        for ( mm = 0; mm < num_glyphs; mm++ )
        {
          FT_UInt  gindex = FT_NEXT_USHORT( p );


          if ( gindex == glyph_index )
            break;
        }

        if ( mm >= num_glyphs )
          goto NoBitmap;

        image_start = image_size * mm;
        image_end   = image_start + image_size;
      }
      break;

    default:
      goto NoBitmap;
    }

    if ( image_start > image_end )
      goto NoBitmap;

    image_end  -= image_start;
    image_start = image_offset + image_start;

    return tt_sbit_decoder_load_bitmap( decoder,
                                        image_format,
                                        image_start,
                                        image_end,
                                        x_pos,
                                        y_pos );

  Failure:
    return SFNT_Err_Invalid_Table;

  NoBitmap:
    return SFNT_Err_Invalid_Argument;
  }

