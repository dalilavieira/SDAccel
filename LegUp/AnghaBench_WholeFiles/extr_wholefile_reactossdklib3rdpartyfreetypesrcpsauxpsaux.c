#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_54__   TYPE_9__ ;
typedef  struct TYPE_53__   TYPE_8__ ;
typedef  struct TYPE_52__   TYPE_7__ ;
typedef  struct TYPE_51__   TYPE_6__ ;
typedef  struct TYPE_50__   TYPE_5__ ;
typedef  struct TYPE_49__   TYPE_4__ ;
typedef  struct TYPE_48__   TYPE_3__ ;
typedef  struct TYPE_47__   TYPE_2__ ;
typedef  struct TYPE_46__   TYPE_1__ ;
typedef  struct TYPE_45__   TYPE_13__ ;
typedef  struct TYPE_44__   TYPE_12__ ;
typedef  struct TYPE_43__   TYPE_11__ ;
typedef  struct TYPE_42__   TYPE_10__ ;

/* Type definitions */
struct TYPE_54__ {scalar_t__ max; scalar_t__ min; int used; scalar_t__ minDS; scalar_t__ maxDS; } ;
struct TYPE_53__ {int lenBV; scalar_t__* BV; } ;
struct TYPE_48__ {int /*<<< orphan*/  vsindex; } ;
struct TYPE_46__ {int /*<<< orphan*/  font; } ;
struct TYPE_52__ {TYPE_3__ private_dict; TYPE_1__ blend; } ;
struct TYPE_51__ {scalar_t__ dataCount; } ;
struct TYPE_50__ {scalar_t__ width_only; int /*<<< orphan*/  flex_state; } ;
struct TYPE_49__ {scalar_t__ c; scalar_t__ b; scalar_t__ d; scalar_t__ a; } ;
struct TYPE_47__ {int usedBV; int /*<<< orphan*/  font; } ;
struct TYPE_45__ {void* status; } ;
struct TYPE_42__ {scalar_t__ ty; scalar_t__ tx; } ;
struct TYPE_44__ {scalar_t__ syntheticEmboldeningAmountX; scalar_t__ syntheticEmboldeningAmountY; int lenNDV; scalar_t__ ppem; int hinted; int renderingFlags; int stemDarkened; scalar_t__ unitsPerEm; scalar_t__ stdVW; int darkenX; scalar_t__ stdHW; int darkenY; int darkened; int reverseWinding; TYPE_5__* decoder; scalar_t__ isT1; int /*<<< orphan*/  blues; int /*<<< orphan*/  darkenParams; TYPE_4__ outerTransform; TYPE_10__ innerTransform; TYPE_10__ currentTransform; int /*<<< orphan*/ * NDV; int /*<<< orphan*/  vsindex; TYPE_2__ blend; int /*<<< orphan*/  cffload; TYPE_7__* lastSubfont; int /*<<< orphan*/  error; } ;
struct TYPE_43__ {scalar_t__ csCoord; scalar_t__ flags; size_t index; scalar_t__ dsCoord; scalar_t__ scale; } ;
typedef  TYPE_5__ PS_Decoder ;
typedef  int /*<<< orphan*/  FT_Service_CFFLoad ;
typedef  int /*<<< orphan*/  FT_Fixed ;
typedef  int FT_Bool ;
typedef  TYPE_6__ CFF_VStoreRec ;
typedef  TYPE_7__* CFF_SubFont ;
typedef  TYPE_8__* CFF_Blend ;
typedef  int CF2_UInt ;
typedef  TYPE_9__ CF2_StemHintRec ;
typedef  int /*<<< orphan*/  CF2_Stack ;
typedef  TYPE_10__ CF2_Matrix ;
typedef  scalar_t__ CF2_Int ;
typedef  TYPE_11__* CF2_Hint ;
typedef  int /*<<< orphan*/  CF2_GlyphPath ;
typedef  TYPE_12__* CF2_Font ;
typedef  scalar_t__ CF2_Fixed ;
typedef  int /*<<< orphan*/  CF2_ArrStack ;
typedef  TYPE_13__* AFM_Stream ;

/* Variables and functions */
 void* ADD_INT32 (scalar_t__,scalar_t__) ; 
 int AFM_GETC () ; 
 scalar_t__ AFM_IS_EOF (int) ; 
 scalar_t__ AFM_IS_NEWLINE (int) ; 
 scalar_t__ AFM_IS_SEP (int) ; 
 scalar_t__ AFM_IS_SPACE (int) ; 
 scalar_t__ AFM_STATUS_EOC (TYPE_13__*) ; 
 scalar_t__ AFM_STATUS_EOL (TYPE_13__*) ; 
 char* AFM_STREAM_KEY_BEGIN (TYPE_13__*) ; 
 void* AFM_STREAM_STATUS_EOC ; 
 void* AFM_STREAM_STATUS_EOF ; 
 void* AFM_STREAM_STATUS_EOL ; 
 int CF2_FlagsDarkened ; 
 int CF2_FlagsHinted ; 
 scalar_t__ CF2_GhostBottom ; 
 scalar_t__ CF2_GhostTop ; 
 void* CF2_PairBottom ; 
 void* CF2_PairTop ; 
 int const FALSE ; 
 int FT_BOOL (int) ; 
 void* FT_DivFix (scalar_t__,scalar_t__) ; 
 int /*<<< orphan*/  FT_ERROR (char*) ; 
 int /*<<< orphan*/  FT_Err_Ok ; 
 scalar_t__ FT_MAX (scalar_t__,void*) ; 
 scalar_t__ FT_MulFix (scalar_t__,scalar_t__) ; 
 int /*<<< orphan*/  FT_ZERO (TYPE_11__*) ; 
 scalar_t__ MUL_INT32 (int,scalar_t__) ; 
 int SUB_INT32 (scalar_t__,scalar_t__) ; 
 void* TRUE ; 
 scalar_t__ cf2_arrstack_getPointer (int /*<<< orphan*/  const,size_t) ; 
 int /*<<< orphan*/  cf2_arrstack_push (int /*<<< orphan*/ ,TYPE_9__*) ; 
 int /*<<< orphan*/  cf2_blues_init (int /*<<< orphan*/ *,TYPE_12__*) ; 
 int /*<<< orphan*/  cf2_computeDarkening (scalar_t__,scalar_t__,scalar_t__,int*,scalar_t__,int const,int /*<<< orphan*/ ) ; 
 scalar_t__ cf2_fixedAbs (int) ; 
 scalar_t__ cf2_getNominalWidthX (TYPE_5__*) ; 
 scalar_t__ cf2_getPpemY (TYPE_5__*) ; 
 scalar_t__ cf2_getStdHW (TYPE_5__*) ; 
 scalar_t__ cf2_getStdVW (TYPE_5__*) ; 
 TYPE_7__* cf2_getSubfont (TYPE_5__*) ; 
 TYPE_6__* cf2_getVStore (TYPE_5__*) ; 
 int /*<<< orphan*/  cf2_glyphpath_curveTo (int /*<<< orphan*/ ,scalar_t__,scalar_t__,scalar_t__,scalar_t__,scalar_t__,scalar_t__) ; 
 scalar_t__ cf2_hint_isTop (TYPE_11__*) ; 
 int /*<<< orphan*/  cf2_hint_lock (TYPE_11__*) ; 
 scalar_t__ cf2_intToFixed (int) ; 
 int /*<<< orphan*/  cf2_stack_clear (int /*<<< orphan*/ ) ; 
 int cf2_stack_count (int /*<<< orphan*/ ) ; 
 scalar_t__ cf2_stack_getReal (int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  cf2_stack_pop (int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  cf2_stack_setReal (int /*<<< orphan*/ ,int,scalar_t__) ; 
 scalar_t__ ft_memcmp (TYPE_10__ const*,TYPE_10__*,int) ; 

__attribute__((used)) static int
  afm_stream_skip_spaces( AFM_Stream  stream )
  {
    int  ch = 0;  /* make stupid compiler happy */


    if ( AFM_STATUS_EOC( stream ) )
      return ';';

    while ( 1 )
    {
      ch = AFM_GETC();
      if ( !AFM_IS_SPACE( ch ) )
        break;
    }

    if ( AFM_IS_NEWLINE( ch ) )
      stream->status = AFM_STREAM_STATUS_EOL;
    else if ( AFM_IS_SEP( ch ) )
      stream->status = AFM_STREAM_STATUS_EOC;
    else if ( AFM_IS_EOF( ch ) )
      stream->status = AFM_STREAM_STATUS_EOF;

    return ch;
  }

__attribute__((used)) static char*
  afm_stream_read_one( AFM_Stream  stream )
  {
    char*  str;


    afm_stream_skip_spaces( stream );
    if ( AFM_STATUS_EOC( stream ) )
      return NULL;

    str = AFM_STREAM_KEY_BEGIN( stream );

    while ( 1 )
    {
      int  ch = AFM_GETC();


      if ( AFM_IS_SPACE( ch ) )
        break;
      else if ( AFM_IS_NEWLINE( ch ) )
      {
        stream->status = AFM_STREAM_STATUS_EOL;
        break;
      }
      else if ( AFM_IS_SEP( ch ) )
      {
        stream->status = AFM_STREAM_STATUS_EOC;
        break;
      }
      else if ( AFM_IS_EOF( ch ) )
      {
        stream->status = AFM_STREAM_STATUS_EOF;
        break;
      }
    }

    return str;
  }

__attribute__((used)) static char*
  afm_stream_read_string( AFM_Stream  stream )
  {
    char*  str;


    afm_stream_skip_spaces( stream );
    if ( AFM_STATUS_EOL( stream ) )
      return NULL;

    str = AFM_STREAM_KEY_BEGIN( stream );

    /* scan to eol */
    while ( 1 )
    {
      int  ch = AFM_GETC();


      if ( AFM_IS_NEWLINE( ch ) )
      {
        stream->status = AFM_STREAM_STATUS_EOL;
        break;
      }
      else if ( AFM_IS_EOF( ch ) )
      {
        stream->status = AFM_STREAM_STATUS_EOF;
        break;
      }
    }

    return str;
  }

__attribute__((used)) static void
  cf2_font_setup( CF2_Font           font,
                  const CF2_Matrix*  transform )
  {
    /* pointer to parsed font object */
    PS_Decoder*  decoder = font->decoder;

    FT_Bool  needExtraSetup = FALSE;

    CFF_VStoreRec*  vstore;
    FT_Bool         hasVariations = FALSE;

    /* character space units */
    CF2_Fixed  boldenX = font->syntheticEmboldeningAmountX;
    CF2_Fixed  boldenY = font->syntheticEmboldeningAmountY;

    CFF_SubFont  subFont;
    CF2_Fixed    ppem;

    CF2_UInt   lenNormalizedV = 0;
    FT_Fixed*  normalizedV    = NULL;

    /* clear previous error */
    font->error = FT_Err_Ok;

    /* if a CID fontDict has changed, we need to recompute some cached */
    /* data                                                            */
    subFont = cf2_getSubfont( decoder );
    if ( font->lastSubfont != subFont )
    {
      font->lastSubfont = subFont;
      needExtraSetup    = TRUE;
    }

    if ( !font->isT1 )
    {
      FT_Service_CFFLoad  cffload = (FT_Service_CFFLoad)font->cffload;


      /* check for variation vectors */
      vstore        = cf2_getVStore( decoder );
      hasVariations = ( vstore->dataCount != 0 );

      if ( hasVariations )
      {
#ifdef TT_CONFIG_OPTION_GX_VAR_SUPPORT
        /* check whether Private DICT in this subfont needs to be reparsed */
        font->error = cf2_getNormalizedVector( decoder,
                                               &lenNormalizedV,
                                               &normalizedV );
        if ( font->error )
          return;

        if ( cffload->blend_check_vector( &subFont->blend,
                                          subFont->private_dict.vsindex,
                                          lenNormalizedV,
                                          normalizedV ) )
        {
          /* blend has changed, reparse */
          cffload->load_private_dict( decoder->cff,
                                      subFont,
                                      lenNormalizedV,
                                      normalizedV );
          needExtraSetup = TRUE;
        }
#endif

        /* copy from subfont */
        font->blend.font = subFont->blend.font;

        /* clear state of charstring blend */
        font->blend.usedBV = FALSE;

        /* initialize value for charstring */
        font->vsindex = subFont->private_dict.vsindex;

        /* store vector inputs for blends in charstring */
        font->lenNDV = lenNormalizedV;
        font->NDV    = normalizedV;
      }
    }

    /* if ppem has changed, we need to recompute some cached data         */
    /* note: because of CID font matrix concatenation, ppem and transform */
    /*       do not necessarily track.                                    */
    ppem = cf2_getPpemY( decoder );
    if ( font->ppem != ppem )
    {
      font->ppem     = ppem;
      needExtraSetup = TRUE;
    }

    /* copy hinted flag on each call */
    font->hinted = (FT_Bool)( font->renderingFlags & CF2_FlagsHinted );

    /* determine if transform has changed;       */
    /* include Fontmatrix but ignore translation */
    if ( ft_memcmp( transform,
                    &font->currentTransform,
                    4 * sizeof ( CF2_Fixed ) ) != 0 )
    {
      /* save `key' information for `cache of one' matrix data; */
      /* save client transform, without the translation         */
      font->currentTransform    = *transform;
      font->currentTransform.tx =
      font->currentTransform.ty = cf2_intToFixed( 0 );

      /* TODO: FreeType transform is simple scalar; for now, use identity */
      /*       for outer                                                  */
      font->innerTransform   = *transform;
      font->outerTransform.a =
      font->outerTransform.d = cf2_intToFixed( 1 );
      font->outerTransform.b =
      font->outerTransform.c = cf2_intToFixed( 0 );

      needExtraSetup = TRUE;
    }

    /*
     * font->darkened is set to true if there is a stem darkening request or
     * the font is synthetic emboldened.
     * font->darkened controls whether to adjust blue zones, winding order,
     * and hinting.
     *
     */
    if ( font->stemDarkened != ( font->renderingFlags & CF2_FlagsDarkened ) )
    {
      font->stemDarkened =
        (FT_Bool)( font->renderingFlags & CF2_FlagsDarkened );

      /* blue zones depend on darkened flag */
      needExtraSetup = TRUE;
    }

    /* recompute variables that are dependent on transform or FontDict or */
    /* darken flag                                                        */
    if ( needExtraSetup )
    {
      /* StdVW is found in the private dictionary;                       */
      /* recompute darkening amounts whenever private dictionary or      */
      /* transform change                                                */
      /* Note: a rendering flag turns darkening on or off, so we want to */
      /*       store the `on' amounts;                                   */
      /*       darkening amount is computed in character space           */
      /* TODO: testing size-dependent darkening here;                    */
      /*       what to do for rotations?                                 */

      CF2_Fixed  emRatio;
      CF2_Fixed  stdHW;
      CF2_Int    unitsPerEm = font->unitsPerEm;


      if ( unitsPerEm == 0 )
        unitsPerEm = 1000;

      ppem = FT_MAX( cf2_intToFixed( 4 ),
                     font->ppem ); /* use minimum ppem of 4 */

#if 0
      /* since vstem is measured in the x-direction, we use the `a' member */
      /* of the fontMatrix                                                 */
      emRatio = cf2_fixedFracMul( cf2_intToFixed( 1000 ), fontMatrix->a );
#endif

      /* Freetype does not preserve the fontMatrix when parsing; use */
      /* unitsPerEm instead.                                         */
      /* TODO: check precision of this                               */
      emRatio     = cf2_intToFixed( 1000 ) / unitsPerEm;
      font->stdVW = cf2_getStdVW( decoder );

      if ( font->stdVW <= 0 )
        font->stdVW = FT_DivFix( cf2_intToFixed( 75 ), emRatio );

      if ( boldenX > 0 )
      {
        /* Ensure that boldenX is at least 1 pixel for synthetic bold font */
        /* (similar to what Avalon does)                                   */
        boldenX = FT_MAX( boldenX,
                          FT_DivFix( cf2_intToFixed( unitsPerEm ), ppem ) );

        /* Synthetic emboldening adds at least 1 pixel to darkenX, while */
        /* stem darkening adds at most half pixel.  Since the purpose of */
        /* stem darkening (readability at small sizes) is met with       */
        /* synthetic emboldening, no need to add stem darkening for a    */
        /* synthetic bold font.                                          */
        cf2_computeDarkening( emRatio,
                              ppem,
                              font->stdVW,
                              &font->darkenX,
                              boldenX,
                              FALSE,
                              font->darkenParams );
      }
      else
        cf2_computeDarkening( emRatio,
                              ppem,
                              font->stdVW,
                              &font->darkenX,
                              0,
                              font->stemDarkened,
                              font->darkenParams );

#if 0
      /* since hstem is measured in the y-direction, we use the `d' member */
      /* of the fontMatrix                                                 */
      /* TODO: use the same units per em as above; check this              */
      emRatio = cf2_fixedFracMul( cf2_intToFixed( 1000 ), fontMatrix->d );
#endif

      /* set the default stem width, because it must be the same for all */
      /* family members;                                                 */
      /* choose a constant for StdHW that depends on font contrast       */
      stdHW = cf2_getStdHW( decoder );

      if ( stdHW > 0 && font->stdVW > MUL_INT32( 2, stdHW ) )
        font->stdHW = FT_DivFix( cf2_intToFixed( 75 ), emRatio );
      else
      {
        /* low contrast font gets less hstem darkening */
        font->stdHW = FT_DivFix( cf2_intToFixed( 110 ), emRatio );
      }

      cf2_computeDarkening( emRatio,
                            ppem,
                            font->stdHW,
                            &font->darkenY,
                            boldenY,
                            font->stemDarkened,
                            font->darkenParams );

      if ( font->darkenX != 0 || font->darkenY != 0 )
        font->darkened = TRUE;
      else
        font->darkened = FALSE;

      font->reverseWinding = FALSE; /* initial expectation is CCW */

      /* compute blue zones for this instance */
      cf2_blues_init( &font->blues, font );

    } /* needExtraSetup */
  }

__attribute__((used)) static CF2_Int
  cf2_getWindingMomentum( CF2_Fixed  x1,
                          CF2_Fixed  y1,
                          CF2_Fixed  x2,
                          CF2_Fixed  y2 )
  {
    /* cross product of pt1 position from origin with pt2 position from  */
    /* pt1; we reduce the precision so that the result fits into 32 bits */

    return ( x1 >> 16 ) * ( SUB_INT32( y2, y1 ) >> 16 ) -
           ( y1 >> 16 ) * ( SUB_INT32( x2, x1 ) >> 16 );
  }

__attribute__((used)) static void
  cf2_hint_init( CF2_Hint            hint,
                 const CF2_ArrStack  stemHintArray,
                 size_t              indexStemHint,
                 const CF2_Font      font,
                 CF2_Fixed           hintOrigin,
                 CF2_Fixed           scale,
                 FT_Bool             bottom )
  {
    CF2_Fixed               width;
    const CF2_StemHintRec*  stemHint;


    FT_ZERO( hint );

    stemHint = (const CF2_StemHintRec*)cf2_arrstack_getPointer(
                                         stemHintArray,
                                         indexStemHint );

    width = SUB_INT32( stemHint->max, stemHint->min );

    if ( width == cf2_intToFixed( -21 ) )
    {
      /* ghost bottom */

      if ( bottom )
      {
        hint->csCoord = stemHint->max;
        hint->flags   = CF2_GhostBottom;
      }
      else
        hint->flags = 0;
    }

    else if ( width == cf2_intToFixed( -20 ) )
    {
      /* ghost top */

      if ( bottom )
        hint->flags = 0;
      else
      {
        hint->csCoord = stemHint->min;
        hint->flags   = CF2_GhostTop;
      }
    }

    else if ( width < 0 )
    {
      /* inverted pair */

      /*
       * Hints with negative widths were produced by an early version of a
       * non-Adobe font tool.  The Type 2 spec allows edge (ghost) hints
       * with negative widths, but says
       *
       *   All other negative widths have undefined meaning.
       *
       * CoolType has a silent workaround that negates the hint width; for
       * permissive mode, we do the same here.
       *
       * Note: Such fonts cannot use ghost hints, but should otherwise work.
       * Note: Some poor hints in our faux fonts can produce negative
       *       widths at some blends.  For example, see a light weight of
       *       `u' in ASerifMM.
       *
       */
      if ( bottom )
      {
        hint->csCoord = stemHint->max;
        hint->flags   = CF2_PairBottom;
      }
      else
      {
        hint->csCoord = stemHint->min;
        hint->flags   = CF2_PairTop;
      }
    }

    else
    {
      /* normal pair */

      if ( bottom )
      {
        hint->csCoord = stemHint->min;
        hint->flags   = CF2_PairBottom;
      }
      else
      {
        hint->csCoord = stemHint->max;
        hint->flags   = CF2_PairTop;
      }
    }

    /* Now that ghost hints have been detected, adjust this edge for      */
    /* darkening.  Bottoms are not changed; tops are incremented by twice */
    /* `darkenY'.                                                         */
    if ( cf2_hint_isTop( hint ) )
      hint->csCoord = ADD_INT32( hint->csCoord, 2 * font->darkenY );

    hint->csCoord = ADD_INT32( hint->csCoord, hintOrigin );
    hint->scale   = scale;
    hint->index   = indexStemHint;   /* index in original stem hint array */

    /* if original stem hint has been used, use the same position */
    if ( hint->flags != 0 && stemHint->used )
    {
      if ( cf2_hint_isTop( hint ) )
        hint->dsCoord = stemHint->maxDS;
      else
        hint->dsCoord = stemHint->minDS;

      cf2_hint_lock( hint );
    }
    else
      hint->dsCoord = FT_MulFix( hint->csCoord, scale );
  }

__attribute__((used)) static void
  cf2_hint_initZero( CF2_Hint  hint )
  {
    FT_ZERO( hint );
  }

__attribute__((used)) static void
  cf2_doStems( const CF2_Font  font,
               CF2_Stack       opStack,
               CF2_ArrStack    stemHintArray,
               CF2_Fixed*      width,
               FT_Bool*        haveWidth,
               CF2_Fixed       hintOffset )
  {
    CF2_UInt  i;
    CF2_UInt  count       = cf2_stack_count( opStack );
    FT_Bool   hasWidthArg = (FT_Bool)( count & 1 );

    /* variable accumulates delta values from operand stack */
    CF2_Fixed  position = hintOffset;

    if ( font->isT1 && !font->decoder->flex_state && !*haveWidth )
      FT_ERROR(( "cf2_doStems (Type 1 mode):"
                 " No width. Use hsbw/sbw as first op\n" ));

    if ( !font->isT1 && hasWidthArg && !*haveWidth )
      *width = ADD_INT32( cf2_stack_getReal( opStack, 0 ),
                          cf2_getNominalWidthX( font->decoder ) );

    if ( font->decoder->width_only )
      goto exit;

    for ( i = hasWidthArg ? 1 : 0; i < count; i += 2 )
    {
      /* construct a CF2_StemHint and push it onto the list */
      CF2_StemHintRec  stemhint;


      stemhint.min =
      position     = ADD_INT32( position,
                                cf2_stack_getReal( opStack, i ) );
      stemhint.max =
      position     = ADD_INT32( position,
                                cf2_stack_getReal( opStack, i + 1 ) );

      stemhint.used  = FALSE;
      stemhint.maxDS =
      stemhint.minDS = 0;

      cf2_arrstack_push( stemHintArray, &stemhint ); /* defer error check */
    }

    cf2_stack_clear( opStack );

  exit:
    /* cf2_doStems must define a width (may be default) */
    *haveWidth = TRUE;
  }

__attribute__((used)) static void
  cf2_doFlex( CF2_Stack       opStack,
              CF2_Fixed*      curX,
              CF2_Fixed*      curY,
              CF2_GlyphPath   glyphPath,
              const FT_Bool*  readFromStack,
              FT_Bool         doConditionalLastRead )
  {
    CF2_Fixed  vals[14];
    CF2_UInt   idx;
    FT_Bool    isHFlex;
    CF2_Int    top, i, j;


    vals[0] = *curX;
    vals[1] = *curY;
    idx     = 0;
    isHFlex = FT_BOOL( readFromStack[9] == FALSE );
    top     = isHFlex ? 9 : 10;

    for ( i = 0; i < top; i++ )
    {
      vals[i + 2] = vals[i];
      if ( readFromStack[i] )
        vals[i + 2] = ADD_INT32( vals[i + 2], cf2_stack_getReal( opStack,
                                                                 idx++ ) );
    }

    if ( isHFlex )
      vals[9 + 2] = *curY;

    if ( doConditionalLastRead )
    {
      FT_Bool    lastIsX = (FT_Bool)(
                             cf2_fixedAbs( SUB_INT32( vals[10], *curX ) ) >
                             cf2_fixedAbs( SUB_INT32( vals[11], *curY ) ) );
      CF2_Fixed  lastVal = cf2_stack_getReal( opStack, idx );


      if ( lastIsX )
      {
        vals[12] = ADD_INT32( vals[10], lastVal );
        vals[13] = *curY;
      }
      else
      {
        vals[12] = *curX;
        vals[13] = ADD_INT32( vals[11], lastVal );
      }
    }
    else
    {
      if ( readFromStack[10] )
        vals[12] = ADD_INT32( vals[10],
                              cf2_stack_getReal( opStack, idx++ ) );
      else
        vals[12] = *curX;

      if ( readFromStack[11] )
        vals[13] = ADD_INT32( vals[11],
                              cf2_stack_getReal( opStack, idx ) );
      else
        vals[13] = *curY;
    }

    for ( j = 0; j < 2; j++ )
      cf2_glyphpath_curveTo( glyphPath, vals[j * 6 + 2],
                                        vals[j * 6 + 3],
                                        vals[j * 6 + 4],
                                        vals[j * 6 + 5],
                                        vals[j * 6 + 6],
                                        vals[j * 6 + 7] );

    cf2_stack_clear( opStack );

    *curX = vals[12];
    *curY = vals[13];
  }

__attribute__((used)) static void
  cf2_doBlend( const CFF_Blend  blend,
               CF2_Stack        opStack,
               CF2_UInt         numBlends )
  {
    CF2_UInt  delta;
    CF2_UInt  base;
    CF2_UInt  i, j;
    CF2_UInt  numOperands = (CF2_UInt)( numBlends * blend->lenBV );


    base  = cf2_stack_count( opStack ) - numOperands;
    delta = base + numBlends;

    for ( i = 0; i < numBlends; i++ )
    {
      const CF2_Fixed*  weight = &blend->BV[1];

      /* start with first term */
      CF2_Fixed  sum = cf2_stack_getReal( opStack, i + base );


      for ( j = 1; j < blend->lenBV; j++ )
        sum = ADD_INT32( sum,
                         FT_MulFix( *weight++,
                                    cf2_stack_getReal( opStack,
                                                       delta++ ) ) );

      /* store blended result  */
      cf2_stack_setReal( opStack, i + base, sum );
    }

    /* leave only `numBlends' results on stack */
    cf2_stack_pop( opStack, numOperands - numBlends );
  }

