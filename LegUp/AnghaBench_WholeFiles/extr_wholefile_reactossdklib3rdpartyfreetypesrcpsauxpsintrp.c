#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_11__   TYPE_4__ ;
typedef  struct TYPE_10__   TYPE_3__ ;
typedef  struct TYPE_9__   TYPE_2__ ;
typedef  struct TYPE_8__   TYPE_1__ ;

/* Type definitions */
struct TYPE_11__ {scalar_t__ width_only; int /*<<< orphan*/  flex_state; } ;
struct TYPE_10__ {TYPE_4__* decoder; scalar_t__ isT1; } ;
struct TYPE_9__ {scalar_t__ used; scalar_t__ minDS; scalar_t__ maxDS; void* max; void* min; } ;
struct TYPE_8__ {int lenBV; void** BV; } ;
typedef  scalar_t__ FT_Bool ;
typedef  TYPE_1__* CFF_Blend ;
typedef  int CF2_UInt ;
typedef  TYPE_2__ CF2_StemHintRec ;
typedef  int /*<<< orphan*/  CF2_Stack ;
typedef  int CF2_Int ;
typedef  int /*<<< orphan*/  CF2_GlyphPath ;
typedef  TYPE_3__* CF2_Font ;
typedef  void* CF2_Fixed ;
typedef  int /*<<< orphan*/  CF2_ArrStack ;

/* Variables and functions */
 void* ADD_INT32 (void*,void*) ; 
 scalar_t__ const FALSE ; 
 scalar_t__ FT_BOOL (int) ; 
 int /*<<< orphan*/  FT_ERROR (char*) ; 
 void* FT_MulFix (int /*<<< orphan*/ ,void*) ; 
 int /*<<< orphan*/  SUB_INT32 (void*,void*) ; 
 scalar_t__ TRUE ; 
 int /*<<< orphan*/  cf2_arrstack_push (int /*<<< orphan*/ ,TYPE_2__*) ; 
 scalar_t__ cf2_fixedAbs (int /*<<< orphan*/ ) ; 
 void* cf2_getNominalWidthX (TYPE_4__*) ; 
 int /*<<< orphan*/  cf2_glyphpath_curveTo (int /*<<< orphan*/ ,void*,void*,void*,void*,void*,void*) ; 
 int /*<<< orphan*/  cf2_stack_clear (int /*<<< orphan*/ ) ; 
 int cf2_stack_count (int /*<<< orphan*/ ) ; 
 void* cf2_stack_getReal (int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  cf2_stack_pop (int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  cf2_stack_setReal (int /*<<< orphan*/ ,int,void*) ; 

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

