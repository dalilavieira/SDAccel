#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_48__   TYPE_9__ ;
typedef  struct TYPE_47__   TYPE_8__ ;
typedef  struct TYPE_46__   TYPE_7__ ;
typedef  struct TYPE_45__   TYPE_6__ ;
typedef  struct TYPE_44__   TYPE_5__ ;
typedef  struct TYPE_43__   TYPE_4__ ;
typedef  struct TYPE_42__   TYPE_3__ ;
typedef  struct TYPE_41__   TYPE_2__ ;
typedef  struct TYPE_40__   TYPE_1__ ;
typedef  struct TYPE_39__   TYPE_19__ ;
typedef  struct TYPE_38__   TYPE_18__ ;
typedef  struct TYPE_37__   TYPE_17__ ;
typedef  struct TYPE_36__   TYPE_16__ ;
typedef  struct TYPE_35__   TYPE_15__ ;
typedef  struct TYPE_34__   TYPE_14__ ;
typedef  struct TYPE_33__   TYPE_13__ ;
typedef  struct TYPE_32__   TYPE_12__ ;
typedef  struct TYPE_31__   TYPE_11__ ;
typedef  struct TYPE_30__   TYPE_10__ ;

/* Type definitions */
struct TYPE_40__ {int /*<<< orphan*/  memory; } ;
struct TYPE_48__ {TYPE_1__ root; } ;
struct TYPE_47__ {int /*<<< orphan*/  outline; TYPE_5__* internal; } ;
struct TYPE_46__ {scalar_t__ y; scalar_t__ x; } ;
struct TYPE_45__ {scalar_t__ y; scalar_t__ x; } ;
struct TYPE_44__ {scalar_t__ glyph_hints; TYPE_12__* loader; } ;
struct TYPE_43__ {int /*<<< orphan*/  internal; } ;
struct TYPE_42__ {int /*<<< orphan*/  outline; } ;
struct TYPE_41__ {int /*<<< orphan*/  outline; } ;
struct TYPE_39__ {int load_points; int /*<<< orphan*/ * base; TYPE_17__* glyph; TYPE_7__ advance; TYPE_6__ left_bearing; scalar_t__ pos_y; scalar_t__ pos_x; scalar_t__ hints_funcs; void* hints_globals; int /*<<< orphan*/ * current; TYPE_12__* loader; int /*<<< orphan*/  memory; TYPE_9__* face; scalar_t__ path_begun; } ;
struct TYPE_33__ {void* yMax; void* xMax; void* yMin; void* xMin; } ;
struct TYPE_30__ {int x; int y; } ;
struct TYPE_31__ {int xx; int yx; int yy; int xy; } ;
struct TYPE_38__ {int units_per_em; int private_size; int private_offset; int cid_registry; int cid_ordering; int cid_supplement; TYPE_13__ font_bbox; TYPE_10__ font_offset; TYPE_11__ font_matrix; } ;
struct TYPE_37__ {TYPE_8__ root; } ;
struct TYPE_36__ {scalar_t__ topfont; } ;
struct TYPE_35__ {int** stack; int** top; int /*<<< orphan*/  object; } ;
struct TYPE_34__ {TYPE_4__ root; } ;
struct TYPE_32__ {TYPE_3__ current; TYPE_2__ base; } ;
typedef  TYPE_9__* TT_Face ;
typedef  TYPE_10__ FT_Vector ;
typedef  int FT_ULong ;
typedef  int FT_UInt ;
typedef  TYPE_11__ FT_Matrix ;
typedef  int FT_Long ;
typedef  int FT_Int ;
typedef  TYPE_12__* FT_GlyphLoader ;
typedef  int FT_Fixed ;
typedef  int /*<<< orphan*/  FT_Error ;
typedef  int FT_Byte ;
typedef  scalar_t__ FT_Bool ;
typedef  TYPE_13__ FT_BBox ;
typedef  TYPE_14__* CFF_Size ;
typedef  TYPE_15__* CFF_Parser ;
typedef  TYPE_16__* CFF_Internal ;
typedef  TYPE_17__* CFF_GlyphSlot ;
typedef  TYPE_18__* CFF_FontRecDict ;
typedef  TYPE_19__ CFF_Builder ;

/* Variables and functions */
 int /*<<< orphan*/  CFF_Err_Ok ; 
 int /*<<< orphan*/  CFF_Err_Stack_Underflow ; 
 int FT_ABS (int) ; 
 int /*<<< orphan*/  FT_ASSERT (int*) ; 
 int FT_DivFix (int,int) ; 
 int /*<<< orphan*/  FT_GlyphLoader_Rewind (TYPE_12__*) ; 
 int FT_MIN (int,int) ; 
 void* FT_RoundFix (int) ; 
 int /*<<< orphan*/  FT_TRACE1 (char*) ; 
 int cff_parse_integer (int*,int*) ; 
 int* power_tens ; 

__attribute__((used)) static FT_Fixed
  cff_parse_real( FT_Byte*  start,
                  FT_Byte*  limit,
                  FT_Long   power_ten,
                  FT_Long*  scaling )
  {
    FT_Byte*  p = start;
    FT_UInt   nib;
    FT_UInt   phase;

    FT_Long   result, number, exponent;
    FT_Int    sign = 0, exponent_sign = 0;
    FT_Long   exponent_add, integer_length, fraction_length;


    if ( scaling )
      *scaling = 0;

    result = 0;

    number   = 0;
    exponent = 0;

    exponent_add    = 0;
    integer_length  = 0;
    fraction_length = 0;

    /* First of all, read the integer part. */
    phase = 4;

    for (;;)
    {
      /* If we entered this iteration with phase == 4, we need to */
      /* read a new byte.  This also skips past the initial 0x1E. */
      if ( phase )
      {
        p++;

        /* Make sure we don't read past the end. */
        if ( p >= limit )
          goto Exit;
      }

      /* Get the nibble. */
      nib   = ( p[0] >> phase ) & 0xF;
      phase = 4 - phase;

      if ( nib == 0xE )
        sign = 1;
      else if ( nib > 9 )
        break;
      else
      {
        /* Increase exponent if we can't add the digit. */
        if ( number >= 0xCCCCCCCL )
          exponent_add++;
        /* Skip leading zeros. */
        else if ( nib || number )
        {
          integer_length++;
          number = number * 10 + nib;
        }
      }
    }

    /* Read fraction part, if any. */
    if ( nib == 0xa )
      for (;;)
      {
        /* If we entered this iteration with phase == 4, we need */
        /* to read a new byte.                                   */
        if ( phase )
        {
          p++;

          /* Make sure we don't read past the end. */
          if ( p >= limit )
            goto Exit;
        }

        /* Get the nibble. */
        nib   = ( p[0] >> phase ) & 0xF;
        phase = 4 - phase;
        if ( nib >= 10 )
          break;

        /* Skip leading zeros if possible. */
        if ( !nib && !number )
          exponent_add--;
        /* Only add digit if we don't overflow. */
        else if ( number < 0xCCCCCCCL && fraction_length < 9 )
        {
          fraction_length++;
          number = number * 10 + nib;
        }
      }

    /* Read exponent, if any. */
    if ( nib == 12 )
    {
      exponent_sign = 1;
      nib           = 11;
    }

    if ( nib == 11 )
    {
      for (;;)
      {
        /* If we entered this iteration with phase == 4, */
        /* we need to read a new byte.                   */
        if ( phase )
        {
          p++;

          /* Make sure we don't read past the end. */
          if ( p >= limit )
            goto Exit;
        }

        /* Get the nibble. */
        nib   = ( p[0] >> phase ) & 0xF;
        phase = 4 - phase;
        if ( nib >= 10 )
          break;

        exponent = exponent * 10 + nib;

        /* Arbitrarily limit exponent. */
        if ( exponent > 1000 )
          goto Exit;
      }

      if ( exponent_sign )
        exponent = -exponent;
    }

    /* We don't check `power_ten' and `exponent_add'. */
    exponent += power_ten + exponent_add;

    if ( scaling )
    {
      /* Only use `fraction_length'. */
      fraction_length += integer_length;
      exponent        += integer_length;

      if ( fraction_length <= 5 )
      {
        if ( number > 0x7FFFL )
        {
          result   = FT_DivFix( number, 10 );
          *scaling = exponent - fraction_length + 1;
        }
        else
        {
          if ( exponent > 0 )
          {
            FT_Long  new_fraction_length, shift;


            /* Make `scaling' as small as possible. */
            new_fraction_length = FT_MIN( exponent, 5 );
            exponent           -= new_fraction_length;
            shift               = new_fraction_length - fraction_length;

            number *= power_tens[shift];
            if ( number > 0x7FFFL )
            {
              number   /= 10;
              exponent += 1;
            }
          }
          else
            exponent -= fraction_length;

          result   = number << 16;
          *scaling = exponent;
        }
      }
      else
      {
        if ( ( number / power_tens[fraction_length - 5] ) > 0x7FFFL )
        {
          result   = FT_DivFix( number, power_tens[fraction_length - 4] );
          *scaling = exponent - 4;
        }
        else
        {
          result   = FT_DivFix( number, power_tens[fraction_length - 5] );
          *scaling = exponent - 5;
        }
      }
    }
    else
    {
      integer_length  += exponent;
      fraction_length -= exponent;

      /* Check for overflow and underflow. */
      if ( FT_ABS( integer_length ) > 5 )
        goto Exit;

      /* Remove non-significant digits. */
      if ( integer_length < 0 )
      {
        number          /= power_tens[-integer_length];
        fraction_length += integer_length;
      }

      /* this can only happen if exponent was non-zero */
      if ( fraction_length == 10 )
      {
        number          /= 10;
        fraction_length -= 1;
      }

      /* Convert into 16.16 format. */
      if ( fraction_length > 0 )
      {
        if ( ( number / power_tens[fraction_length] ) > 0x7FFFL )
          goto Exit;

        result = FT_DivFix( number, power_tens[fraction_length] );
      }
      else
      {
        number *= power_tens[-fraction_length];

        if ( number > 0x7FFFL )
          goto Exit;

        result = number << 16;
      }
    }

    if ( sign )
      result = -result;

  Exit:
    return result;
  }

__attribute__((used)) static FT_Long
  cff_parse_num( FT_Byte**  d )
  {
    return **d == 30 ? ( cff_parse_real( d[0], d[1], 0, NULL ) >> 16 )
                     :   cff_parse_integer( d[0], d[1] );
  }

__attribute__((used)) static FT_Fixed
  cff_parse_fixed( FT_Byte**  d )
  {
    return **d == 30 ? cff_parse_real( d[0], d[1], 0, NULL )
                     : cff_parse_integer( d[0], d[1] ) << 16;
  }

__attribute__((used)) static FT_Fixed
  cff_parse_fixed_scaled( FT_Byte**  d,
                          FT_Long    scaling )
  {
    return **d == 30 ? cff_parse_real( d[0], d[1], scaling, NULL )
                     : ( cff_parse_integer( d[0], d[1] ) *
                           power_tens[scaling] ) << 16;
  }

__attribute__((used)) static FT_Fixed
  cff_parse_fixed_dynamic( FT_Byte**  d,
                           FT_Long*   scaling )
  {
    FT_ASSERT( scaling );

    if ( **d == 30 )
      return cff_parse_real( d[0], d[1], 0, scaling );
    else
    {
      FT_Long  number;
      FT_Int   integer_length;


      number = cff_parse_integer( d[0], d[1] );

      if ( number > 0x7FFFL )
      {
        for ( integer_length = 5; integer_length < 10; integer_length++ )
          if ( number < power_tens[integer_length] )
            break;

        if ( ( number / power_tens[integer_length - 5] ) > 0x7FFFL )
        {
          *scaling = integer_length - 4;
          return FT_DivFix( number, power_tens[integer_length - 4] );
        }
        else
        {
          *scaling = integer_length - 5;
          return FT_DivFix( number, power_tens[integer_length - 5] );
        }
      }
      else
      {
        *scaling = 0;
        return number << 16;
      }
    }
  }

__attribute__((used)) static FT_Error
  cff_parse_font_matrix( CFF_Parser  parser )
  {
    CFF_FontRecDict  dict   = (CFF_FontRecDict)parser->object;
    FT_Matrix*       matrix = &dict->font_matrix;
    FT_Vector*       offset = &dict->font_offset;
    FT_ULong*        upm    = &dict->units_per_em;
    FT_Byte**        data   = parser->stack;
    FT_Error         error  = CFF_Err_Stack_Underflow;


    if ( parser->top >= parser->stack + 6 )
    {
      FT_Long  scaling;


      error = CFF_Err_Ok;

      /* We expect a well-formed font matrix, this is, the matrix elements */
      /* `xx' and `yy' are of approximately the same magnitude.  To avoid  */
      /* loss of precision, we use the magnitude of element `xx' to scale  */
      /* all other elements.  The scaling factor is then contained in the  */
      /* `units_per_em' value.                                             */

      matrix->xx = cff_parse_fixed_dynamic( data++, &scaling );

      scaling = -scaling;

      if ( scaling < 0 || scaling > 9 )
      {
        /* Return default matrix in case of unlikely values. */
        matrix->xx = 0x10000L;
        matrix->yx = 0;
        matrix->yx = 0;
        matrix->yy = 0x10000L;
        offset->x  = 0;
        offset->y  = 0;
        *upm       = 1;

        goto Exit;
      }

      matrix->yx = cff_parse_fixed_scaled( data++, scaling );
      matrix->xy = cff_parse_fixed_scaled( data++, scaling );
      matrix->yy = cff_parse_fixed_scaled( data++, scaling );
      offset->x  = cff_parse_fixed_scaled( data++, scaling );
      offset->y  = cff_parse_fixed_scaled( data,   scaling );

      *upm = power_tens[scaling];
    }

  Exit:
    return error;
  }

__attribute__((used)) static FT_Error
  cff_parse_font_bbox( CFF_Parser  parser )
  {
    CFF_FontRecDict  dict = (CFF_FontRecDict)parser->object;
    FT_BBox*         bbox = &dict->font_bbox;
    FT_Byte**        data = parser->stack;
    FT_Error         error;


    error = CFF_Err_Stack_Underflow;

    if ( parser->top >= parser->stack + 4 )
    {
      bbox->xMin = FT_RoundFix( cff_parse_fixed( data++ ) );
      bbox->yMin = FT_RoundFix( cff_parse_fixed( data++ ) );
      bbox->xMax = FT_RoundFix( cff_parse_fixed( data++ ) );
      bbox->yMax = FT_RoundFix( cff_parse_fixed( data   ) );
      error = CFF_Err_Ok;
    }

    return error;
  }

__attribute__((used)) static FT_Error
  cff_parse_private_dict( CFF_Parser  parser )
  {
    CFF_FontRecDict  dict = (CFF_FontRecDict)parser->object;
    FT_Byte**        data = parser->stack;
    FT_Error         error;


    error = CFF_Err_Stack_Underflow;

    if ( parser->top >= parser->stack + 2 )
    {
      dict->private_size   = cff_parse_num( data++ );
      dict->private_offset = cff_parse_num( data   );
      error = CFF_Err_Ok;
    }

    return error;
  }

__attribute__((used)) static FT_Error
  cff_parse_cid_ros( CFF_Parser  parser )
  {
    CFF_FontRecDict  dict = (CFF_FontRecDict)parser->object;
    FT_Byte**        data = parser->stack;
    FT_Error         error;


    error = CFF_Err_Stack_Underflow;

    if ( parser->top >= parser->stack + 3 )
    {
      dict->cid_registry   = (FT_UInt)cff_parse_num ( data++ );
      dict->cid_ordering   = (FT_UInt)cff_parse_num ( data++ );
      if ( **data == 30 )
        FT_TRACE1(( "cff_parse_cid_ros: real supplement is rounded\n" ));
      dict->cid_supplement = cff_parse_num( data );
      if ( dict->cid_supplement < 0 )
        FT_TRACE1(( "cff_parse_cid_ros: negative supplement %d is found\n",
                   dict->cid_supplement ));
      error = CFF_Err_Ok;
    }

    return error;
  }

__attribute__((used)) static void
  cff_builder_init( CFF_Builder*   builder,
                    TT_Face        face,
                    CFF_Size       size,
                    CFF_GlyphSlot  glyph,
                    FT_Bool        hinting )
  {
    builder->path_begun  = 0;
    builder->load_points = 1;

    builder->face   = face;
    builder->glyph  = glyph;
    builder->memory = face->root.memory;

    if ( glyph )
    {
      FT_GlyphLoader  loader = glyph->root.internal->loader;


      builder->loader  = loader;
      builder->base    = &loader->base.outline;
      builder->current = &loader->current.outline;
      FT_GlyphLoader_Rewind( loader );

      builder->hints_globals = 0;
      builder->hints_funcs   = 0;

      if ( hinting && size )
      {
        CFF_Internal  internal = (CFF_Internal)size->root.internal;


        builder->hints_globals = (void *)internal->topfont;
        builder->hints_funcs   = glyph->root.internal->glyph_hints;
      }
    }

    builder->pos_x = 0;
    builder->pos_y = 0;

    builder->left_bearing.x = 0;
    builder->left_bearing.y = 0;
    builder->advance.x      = 0;
    builder->advance.y      = 0;
  }

__attribute__((used)) static void
  cff_builder_done( CFF_Builder*  builder )
  {
    CFF_GlyphSlot  glyph = builder->glyph;


    if ( glyph )
      glyph->root.outline = *builder->base;
  }

__attribute__((used)) static FT_Int
  cff_compute_bias( FT_Int   in_charstring_type,
                    FT_UInt  num_subrs )
  {
    FT_Int  result;


    if ( in_charstring_type == 1 )
      result = 0;
    else if ( num_subrs < 1240 )
      result = 107;
    else if ( num_subrs < 33900U )
      result = 1131;
    else
      result = 32768U;

    return result;
  }

