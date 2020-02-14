#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_12__   TYPE_3__ ;
typedef  struct TYPE_11__   TYPE_2__ ;
typedef  struct TYPE_10__   TYPE_1__ ;

/* Type definitions */
struct TYPE_12__ {int darkenY; } ;
struct TYPE_11__ {int csCoord; scalar_t__ flags; int scale; size_t index; int /*<<< orphan*/  dsCoord; } ;
struct TYPE_10__ {int max; int min; int /*<<< orphan*/  minDS; int /*<<< orphan*/  maxDS; scalar_t__ used; } ;
typedef  scalar_t__ FT_Bool ;
typedef  TYPE_1__ CF2_StemHintRec ;
typedef  int CF2_Int ;
typedef  TYPE_2__* CF2_Hint ;
typedef  TYPE_3__* CF2_Font ;
typedef  int CF2_Fixed ;
typedef  int /*<<< orphan*/  CF2_ArrStack ;

/* Variables and functions */
 void* ADD_INT32 (int,int) ; 
 scalar_t__ CF2_GhostBottom ; 
 scalar_t__ CF2_GhostTop ; 
 void* CF2_PairBottom ; 
 void* CF2_PairTop ; 
 int /*<<< orphan*/  FT_MulFix (int,int) ; 
 int /*<<< orphan*/  FT_ZERO (TYPE_2__*) ; 
 int SUB_INT32 (int,int) ; 
 scalar_t__ cf2_arrstack_getPointer (int /*<<< orphan*/  const,size_t) ; 
 scalar_t__ cf2_hint_isTop (TYPE_2__*) ; 
 int /*<<< orphan*/  cf2_hint_lock (TYPE_2__*) ; 
 int cf2_intToFixed (int) ; 

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

