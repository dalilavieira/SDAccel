#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_42__   TYPE_1__ ;

/* Type definitions */
struct TYPE_42__ {scalar_t__ s; scalar_t__ t; } ;
typedef  scalar_t__ GLdouble ;
typedef  TYPE_1__ GLUvertex ;

/* Variables and functions */
 scalar_t__ EdgeEval (TYPE_1__*,TYPE_1__*,TYPE_1__*) ; 
 scalar_t__ EdgeSign (TYPE_1__*,TYPE_1__*,TYPE_1__*) ; 
 void* Interpolate (scalar_t__,int,scalar_t__,int) ; 
 int /*<<< orphan*/  Swap (TYPE_1__*,TYPE_1__*) ; 
 scalar_t__ TransEval (TYPE_1__*,TYPE_1__*,TYPE_1__*) ; 
 scalar_t__ TransLeq (TYPE_1__*,TYPE_1__*) ; 
 scalar_t__ TransSign (TYPE_1__*,TYPE_1__*,TYPE_1__*) ; 
 int VertLeq (TYPE_1__*,TYPE_1__*) ; 
 int /*<<< orphan*/  assert (int) ; 

int __gl_vertLeq( GLUvertex *u, GLUvertex *v )
{
  /* Returns TRUE if u is lexicographically <= v. */

  return VertLeq( u, v );
}

GLdouble __gl_edgeEval( GLUvertex *u, GLUvertex *v, GLUvertex *w )
{
  /* Given three vertices u,v,w such that VertLeq(u,v) && VertLeq(v,w),
   * evaluates the t-coord of the edge uw at the s-coord of the vertex v.
   * Returns v->t - (uw)(v->s), ie. the signed distance from uw to v.
   * If uw is vertical (and thus passes thru v), the result is zero.
   *
   * The calculation is extremely accurate and stable, even when v
   * is very close to u or w.  In particular if we set v->t = 0 and
   * let r be the negated result (this evaluates (uw)(v->s)), then
   * r is guaranteed to satisfy MIN(u->t,w->t) <= r <= MAX(u->t,w->t).
   */
  GLdouble gapL, gapR;

  assert( VertLeq( u, v ) && VertLeq( v, w ));
  
  gapL = v->s - u->s;
  gapR = w->s - v->s;

  if( gapL + gapR > 0 ) {
    if( gapL < gapR ) {
      return (v->t - u->t) + (u->t - w->t) * (gapL / (gapL + gapR));
    } else {
      return (v->t - w->t) + (w->t - u->t) * (gapR / (gapL + gapR));
    }
  }
  /* vertical line */
  return 0;
}

GLdouble __gl_edgeSign( GLUvertex *u, GLUvertex *v, GLUvertex *w )
{
  /* Returns a number whose sign matches EdgeEval(u,v,w) but which
   * is cheaper to evaluate.  Returns > 0, == 0 , or < 0
   * as v is above, on, or below the edge uw.
   */
  GLdouble gapL, gapR;

  assert( VertLeq( u, v ) && VertLeq( v, w ));
  
  gapL = v->s - u->s;
  gapR = w->s - v->s;

  if( gapL + gapR > 0 ) {
    return (v->t - w->t) * gapL + (v->t - u->t) * gapR;
  }
  /* vertical line */
  return 0;
}

GLdouble __gl_transEval( GLUvertex *u, GLUvertex *v, GLUvertex *w )
{
  /* Given three vertices u,v,w such that TransLeq(u,v) && TransLeq(v,w),
   * evaluates the t-coord of the edge uw at the s-coord of the vertex v.
   * Returns v->s - (uw)(v->t), ie. the signed distance from uw to v.
   * If uw is vertical (and thus passes thru v), the result is zero.
   *
   * The calculation is extremely accurate and stable, even when v
   * is very close to u or w.  In particular if we set v->s = 0 and
   * let r be the negated result (this evaluates (uw)(v->t)), then
   * r is guaranteed to satisfy MIN(u->s,w->s) <= r <= MAX(u->s,w->s).
   */
  GLdouble gapL, gapR;

  assert( TransLeq( u, v ) && TransLeq( v, w ));
  
  gapL = v->t - u->t;
  gapR = w->t - v->t;

  if( gapL + gapR > 0 ) {
    if( gapL < gapR ) {
      return (v->s - u->s) + (u->s - w->s) * (gapL / (gapL + gapR));
    } else {
      return (v->s - w->s) + (w->s - u->s) * (gapR / (gapL + gapR));
    }
  }
  /* vertical line */
  return 0;
}

GLdouble __gl_transSign( GLUvertex *u, GLUvertex *v, GLUvertex *w )
{
  /* Returns a number whose sign matches TransEval(u,v,w) but which
   * is cheaper to evaluate.  Returns > 0, == 0 , or < 0
   * as v is above, on, or below the edge uw.
   */
  GLdouble gapL, gapR;

  assert( TransLeq( u, v ) && TransLeq( v, w ));
  
  gapL = v->t - u->t;
  gapR = w->t - v->t;

  if( gapL + gapR > 0 ) {
    return (v->s - w->s) * gapL + (v->s - u->s) * gapR;
  }
  /* vertical line */
  return 0;
}

int __gl_vertCCW( GLUvertex *u, GLUvertex *v, GLUvertex *w )
{
  /* For almost-degenerate situations, the results are not reliable.
   * Unless the floating-point arithmetic can be performed without
   * rounding errors, *any* implementation will give incorrect results
   * on some degenerate inputs, so the client must have some way to
   * handle this situation.
   */
  return (u->s*(v->t - w->t) + v->s*(w->t - u->t) + w->s*(u->t - v->t)) >= 0;
}

void __gl_edgeIntersect( GLUvertex *o1, GLUvertex *d1,
			 GLUvertex *o2, GLUvertex *d2,
			 GLUvertex *v )
/* Given edges (o1,d1) and (o2,d2), compute their point of intersection.
 * The computed point is guaranteed to lie in the intersection of the
 * bounding rectangles defined by each edge.
 */
{
  GLdouble z1, z2;

  /* This is certainly not the most efficient way to find the intersection
   * of two line segments, but it is very numerically stable.
   *
   * Strategy: find the two middle vertices in the VertLeq ordering,
   * and interpolate the intersection s-value from these.  Then repeat
   * using the TransLeq ordering to find the intersection t-value.
   */

  if( ! VertLeq( o1, d1 )) { Swap( o1, d1 ); }
  if( ! VertLeq( o2, d2 )) { Swap( o2, d2 ); }
  if( ! VertLeq( o1, o2 )) { Swap( o1, o2 ); Swap( d1, d2 ); }

  if( ! VertLeq( o2, d1 )) {
    /* Technically, no intersection -- do our best */
    v->s = (o2->s + d1->s) / 2;
  } else if( VertLeq( d1, d2 )) {
    /* Interpolate between o2 and d1 */
    z1 = EdgeEval( o1, o2, d1 );
    z2 = EdgeEval( o2, d1, d2 );
    if( z1+z2 < 0 ) { z1 = -z1; z2 = -z2; }
    v->s = Interpolate( z1, o2->s, z2, d1->s );
  } else {
    /* Interpolate between o2 and d2 */
    z1 = EdgeSign( o1, o2, d1 );
    z2 = -EdgeSign( o1, d2, d1 );
    if( z1+z2 < 0 ) { z1 = -z1; z2 = -z2; }
    v->s = Interpolate( z1, o2->s, z2, d2->s );
  }

  /* Now repeat the process for t */

  if( ! TransLeq( o1, d1 )) { Swap( o1, d1 ); }
  if( ! TransLeq( o2, d2 )) { Swap( o2, d2 ); }
  if( ! TransLeq( o1, o2 )) { Swap( o1, o2 ); Swap( d1, d2 ); }

  if( ! TransLeq( o2, d1 )) {
    /* Technically, no intersection -- do our best */
    v->t = (o2->t + d1->t) / 2;
  } else if( TransLeq( d1, d2 )) {
    /* Interpolate between o2 and d1 */
    z1 = TransEval( o1, o2, d1 );
    z2 = TransEval( o2, d1, d2 );
    if( z1+z2 < 0 ) { z1 = -z1; z2 = -z2; }
    v->t = Interpolate( z1, o2->t, z2, d1->t );
  } else {
    /* Interpolate between o2 and d2 */
    z1 = TransSign( o1, o2, d1 );
    z2 = -TransSign( o1, d2, d1 );
    if( z1+z2 < 0 ) { z1 = -z1; z2 = -z2; }
    v->t = Interpolate( z1, o2->t, z2, d2->t );
  }
}

