#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_11__   TYPE_3__ ;
typedef  struct TYPE_10__   TYPE_1__ ;

/* Type definitions */
struct TYPE_11__ {scalar_t__ buffer; scalar_t__ pitch; scalar_t__ width; int rows; } ;
struct TYPE_10__ {scalar_t__ line; scalar_t__ pitch; scalar_t__ width; int rows; int total; } ;
typedef  TYPE_1__ PFR_BitWriterRec ;
typedef  TYPE_1__* PFR_BitWriter ;
typedef  void* FT_ULong ;
typedef  int FT_UInt ;
typedef  int FT_Long ;
typedef  scalar_t__ FT_Int ;
typedef  int /*<<< orphan*/  FT_Error ;
typedef  int FT_Char ;
typedef  int FT_Byte ;
typedef  scalar_t__ FT_Bool ;
typedef  TYPE_3__ FT_Bitmap ;

/* Variables and functions */
 scalar_t__ FT_BOOL (int) ; 
 int /*<<< orphan*/  FT_ERROR (char*) ; 
 int /*<<< orphan*/  FT_Err_Ok ; 
 int FT_PEEK_USHORT (int*) ; 
 int /*<<< orphan*/  FT_THROW (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  FT_TRACE0 (char*) ; 
 int /*<<< orphan*/  Invalid_Table ; 
 int PFR_BITMAP_2BYTE_CHARCODE ; 
 int PFR_BITMAP_2BYTE_SIZE ; 
 int PFR_BITMAP_3BYTE_OFFSET ; 
 int PFR_BITMAP_CHARCODES_VALIDATED ; 
 int PFR_BITMAP_VALID_CHARCODES ; 
 int /*<<< orphan*/  PFR_CHECK (int) ; 
 void* PFR_NEXT_BYTE (int*) ; 
 int PFR_NEXT_INT8 (int*) ; 
 int PFR_NEXT_LONG (int*) ; 
 int PFR_NEXT_SHORT (int*) ; 
 void* PFR_NEXT_ULONG (int*) ; 
 void* PFR_NEXT_USHORT (int*) ; 

__attribute__((used)) static void
  pfr_bitwriter_init( PFR_BitWriter  writer,
                      FT_Bitmap*     target,
                      FT_Bool        decreasing )
  {
    writer->line   = target->buffer;
    writer->pitch  = target->pitch;
    writer->width  = target->width;
    writer->rows   = target->rows;
    writer->total  = writer->width * writer->rows;

    if ( !decreasing )
    {
      writer->line += writer->pitch * (FT_Int)( target->rows - 1 );
      writer->pitch = -writer->pitch;
    }
  }

__attribute__((used)) static void
  pfr_bitwriter_decode_bytes( PFR_BitWriter  writer,
                              FT_Byte*       p,
                              FT_Byte*       limit )
  {
    FT_UInt   n, reload;
    FT_UInt   left = writer->width;
    FT_Byte*  cur  = writer->line;
    FT_UInt   mask = 0x80;
    FT_UInt   val  = 0;
    FT_UInt   c    = 0;


    n = (FT_UInt)( limit - p ) * 8;
    if ( n > writer->total )
      n = writer->total;

    reload = n & 7;

    for ( ; n > 0; n-- )
    {
      if ( ( n & 7 ) == reload )
        val = *p++;

      if ( val & 0x80 )
        c |= mask;

      val  <<= 1;
      mask >>= 1;

      if ( --left <= 0 )
      {
        cur[0] = (FT_Byte)c;
        left   = writer->width;
        mask   = 0x80;

        writer->line += writer->pitch;
        cur           = writer->line;
        c             = 0;
      }
      else if ( mask == 0 )
      {
        cur[0] = (FT_Byte)c;
        mask   = 0x80;
        c      = 0;
        cur++;
      }
    }

    if ( mask != 0x80 )
      cur[0] = (FT_Byte)c;
  }

__attribute__((used)) static void
  pfr_bitwriter_decode_rle1( PFR_BitWriter  writer,
                             FT_Byte*       p,
                             FT_Byte*       limit )
  {
    FT_Int    phase, count, counts[2];
    FT_UInt   n, reload;
    FT_UInt   left = writer->width;
    FT_Byte*  cur  = writer->line;
    FT_UInt   mask = 0x80;
    FT_UInt   c    = 0;


    n = writer->total;

    phase     = 1;
    counts[0] = 0;
    counts[1] = 0;
    count     = 0;
    reload    = 1;

    for ( ; n > 0; n-- )
    {
      if ( reload )
      {
        do
        {
          if ( phase )
          {
            FT_Int  v;


            if ( p >= limit )
              break;

            v         = *p++;
            counts[0] = v >> 4;
            counts[1] = v & 15;
            phase     = 0;
            count     = counts[0];
          }
          else
          {
            phase = 1;
            count = counts[1];
          }

        } while ( count == 0 );
      }

      if ( phase )
        c |= mask;

      mask >>= 1;

      if ( --left <= 0 )
      {
        cur[0] = (FT_Byte)c;
        left   = writer->width;
        mask   = 0x80;

        writer->line += writer->pitch;
        cur           = writer->line;
        c             = 0;
      }
      else if ( mask == 0 )
      {
        cur[0] = (FT_Byte)c;
        mask   = 0x80;
        c      = 0;
        cur++;
      }

      reload = ( --count <= 0 );
    }

    if ( mask != 0x80 )
      cur[0] = (FT_Byte) c;
  }

__attribute__((used)) static void
  pfr_bitwriter_decode_rle2( PFR_BitWriter  writer,
                             FT_Byte*       p,
                             FT_Byte*       limit )
  {
    FT_Int    phase, count;
    FT_UInt   n, reload;
    FT_UInt   left = writer->width;
    FT_Byte*  cur  = writer->line;
    FT_UInt   mask = 0x80;
    FT_UInt   c    = 0;


    n = writer->total;

    phase  = 1;
    count  = 0;
    reload = 1;

    for ( ; n > 0; n-- )
    {
      if ( reload )
      {
        do
        {
          if ( p >= limit )
            break;

          count = *p++;
          phase = phase ^ 1;

        } while ( count == 0 );
      }

      if ( phase )
        c |= mask;

      mask >>= 1;

      if ( --left <= 0 )
      {
        cur[0] = (FT_Byte)c;
        c      = 0;
        mask   = 0x80;
        left   = writer->width;

        writer->line += writer->pitch;
        cur           = writer->line;
      }
      else if ( mask == 0 )
      {
        cur[0] = (FT_Byte)c;
        c      = 0;
        mask   = 0x80;
        cur++;
      }

      reload = ( --count <= 0 );
    }

    if ( mask != 0x80 )
      cur[0] = (FT_Byte) c;
  }

__attribute__((used)) static void
  pfr_lookup_bitmap_data( FT_Byte*   base,
                          FT_Byte*   limit,
                          FT_UInt    count,
                          FT_UInt*   flags,
                          FT_UInt    char_code,
                          FT_ULong*  found_offset,
                          FT_ULong*  found_size )
  {
    FT_UInt   min, max, char_len;
    FT_Bool   two = FT_BOOL( *flags & PFR_BITMAP_2BYTE_CHARCODE );
    FT_Byte*  buff;


    char_len = 4;
    if ( two )
      char_len += 1;
    if ( *flags & PFR_BITMAP_2BYTE_SIZE )
      char_len += 1;
    if ( *flags & PFR_BITMAP_3BYTE_OFFSET )
      char_len += 1;

    if ( !( *flags & PFR_BITMAP_CHARCODES_VALIDATED ) )
    {
      FT_Byte*  p;
      FT_Byte*  lim;
      FT_UInt   code;
      FT_Long   prev_code;


      *flags    |= PFR_BITMAP_VALID_CHARCODES;
      prev_code  = -1;
      lim        = base + count * char_len;

      if ( lim > limit )
      {
        FT_TRACE0(( "pfr_lookup_bitmap_data:"
                    " number of bitmap records too large,\n"
                    "                       "
                    " thus ignoring all bitmaps in this strike\n" ));
        *flags &= ~PFR_BITMAP_VALID_CHARCODES;
      }
      else
      {
        /* check whether records are sorted by code */
        for ( p = base; p < lim; p += char_len )
        {
          if ( two )
            code = FT_PEEK_USHORT( p );
          else
            code = *p;

          if ( (FT_Long)code <= prev_code )
          {
            FT_TRACE0(( "pfr_lookup_bitmap_data:"
                        " bitmap records are not sorted,\n"
                        "                       "
                        " thus ignoring all bitmaps in this strike\n" ));
            *flags &= ~PFR_BITMAP_VALID_CHARCODES;
            break;
          }

          prev_code = code;
        }
      }

      *flags |= PFR_BITMAP_CHARCODES_VALIDATED;
    }

    /* ignore bitmaps in case table is not valid     */
    /* (this might be sanitized, but PFR is dead...) */
    if ( !( *flags & PFR_BITMAP_VALID_CHARCODES ) )
      goto Fail;

    min = 0;
    max = count;

    /* binary search */
    while ( min < max )
    {
      FT_UInt  mid, code;


      mid  = ( min + max ) >> 1;
      buff = base + mid * char_len;

      if ( two )
        code = PFR_NEXT_USHORT( buff );
      else
        code = PFR_NEXT_BYTE( buff );

      if ( char_code < code )
        max = mid;
      else if ( char_code > code )
        min = mid + 1;
      else
        goto Found_It;
    }

  Fail:
    /* Not found */
    *found_size   = 0;
    *found_offset = 0;
    return;

  Found_It:
    if ( *flags & PFR_BITMAP_2BYTE_SIZE )
      *found_size = PFR_NEXT_USHORT( buff );
    else
      *found_size = PFR_NEXT_BYTE( buff );

    if ( *flags & PFR_BITMAP_3BYTE_OFFSET )
      *found_offset = PFR_NEXT_ULONG( buff );
    else
      *found_offset = PFR_NEXT_USHORT( buff );
  }

__attribute__((used)) static FT_Error
  pfr_load_bitmap_metrics( FT_Byte**  pdata,
                           FT_Byte*   limit,
                           FT_Long    scaled_advance,
                           FT_Long   *axpos,
                           FT_Long   *aypos,
                           FT_UInt   *axsize,
                           FT_UInt   *aysize,
                           FT_Long   *aadvance,
                           FT_UInt   *aformat )
  {
    FT_Error  error = FT_Err_Ok;
    FT_Byte   flags;
    FT_Byte   b;
    FT_Byte*  p = *pdata;
    FT_Long   xpos, ypos, advance;
    FT_UInt   xsize, ysize;


    PFR_CHECK( 1 );
    flags = PFR_NEXT_BYTE( p );

    xpos    = 0;
    ypos    = 0;
    xsize   = 0;
    ysize   = 0;
    advance = 0;

    switch ( flags & 3 )
    {
    case 0:
      PFR_CHECK( 1 );
      b    = PFR_NEXT_BYTE( p );
      xpos = (FT_Char)b >> 4;
      ypos = ( (FT_Char)( b << 4 ) ) >> 4;
      break;

    case 1:
      PFR_CHECK( 2 );
      xpos = PFR_NEXT_INT8( p );
      ypos = PFR_NEXT_INT8( p );
      break;

    case 2:
      PFR_CHECK( 4 );
      xpos = PFR_NEXT_SHORT( p );
      ypos = PFR_NEXT_SHORT( p );
      break;

    case 3:
      PFR_CHECK( 6 );
      xpos = PFR_NEXT_LONG( p );
      ypos = PFR_NEXT_LONG( p );
      break;

    default:
      ;
    }

    flags >>= 2;
    switch ( flags & 3 )
    {
    case 0:
      /* blank image */
      xsize = 0;
      ysize = 0;
      break;

    case 1:
      PFR_CHECK( 1 );
      b     = PFR_NEXT_BYTE( p );
      xsize = ( b >> 4 ) & 0xF;
      ysize = b & 0xF;
      break;

    case 2:
      PFR_CHECK( 2 );
      xsize = PFR_NEXT_BYTE( p );
      ysize = PFR_NEXT_BYTE( p );
      break;

    case 3:
      PFR_CHECK( 4 );
      xsize = PFR_NEXT_USHORT( p );
      ysize = PFR_NEXT_USHORT( p );
      break;

    default:
      ;
    }

    flags >>= 2;
    switch ( flags & 3 )
    {
    case 0:
      advance = scaled_advance;
      break;

    case 1:
      PFR_CHECK( 1 );
      advance = PFR_NEXT_INT8( p ) * 256;
      break;

    case 2:
      PFR_CHECK( 2 );
      advance = PFR_NEXT_SHORT( p );
      break;

    case 3:
      PFR_CHECK( 3 );
      advance = PFR_NEXT_LONG( p );
      break;

    default:
      ;
    }

    *axpos    = xpos;
    *aypos    = ypos;
    *axsize   = xsize;
    *aysize   = ysize;
    *aadvance = advance;
    *aformat  = flags >> 2;
    *pdata    = p;

  Exit:
    return error;

  Too_Short:
    error = FT_THROW( Invalid_Table );
    FT_ERROR(( "pfr_load_bitmap_metrics: invalid glyph data\n" ));
    goto Exit;
  }

__attribute__((used)) static FT_Error
  pfr_load_bitmap_bits( FT_Byte*    p,
                        FT_Byte*    limit,
                        FT_UInt     format,
                        FT_Bool     decreasing,
                        FT_Bitmap*  target )
  {
    FT_Error          error = FT_Err_Ok;
    PFR_BitWriterRec  writer;


    if ( target->rows > 0 && target->width > 0 )
    {
      pfr_bitwriter_init( &writer, target, decreasing );

      switch ( format )
      {
      case 0: /* packed bits */
        pfr_bitwriter_decode_bytes( &writer, p, limit );
        break;

      case 1: /* RLE1 */
        pfr_bitwriter_decode_rle1( &writer, p, limit );
        break;

      case 2: /* RLE2 */
        pfr_bitwriter_decode_rle2( &writer, p, limit );
        break;

      default:
        ;
      }
    }

    return error;
  }

