#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_21__   TYPE_5__ ;
typedef  struct TYPE_20__   TYPE_4__ ;
typedef  struct TYPE_19__   TYPE_3__ ;
typedef  struct TYPE_18__   TYPE_2__ ;
typedef  struct TYPE_17__   TYPE_1__ ;

/* Type definitions */
struct TYPE_21__ {scalar_t__ inside; struct TYPE_21__* next; TYPE_4__* anEdge; } ;
struct TYPE_20__ {int winding; TYPE_2__* Lface; TYPE_1__* Rface; struct TYPE_20__* next; struct TYPE_20__* Sym; struct TYPE_20__* Lnext; struct TYPE_20__* Lprev; int /*<<< orphan*/  Org; int /*<<< orphan*/  Dst; } ;
struct TYPE_19__ {TYPE_4__ eHead; TYPE_5__ fHead; } ;
struct TYPE_18__ {scalar_t__ inside; } ;
struct TYPE_17__ {scalar_t__ inside; } ;
typedef  int /*<<< orphan*/  GLboolean ;
typedef  TYPE_3__ GLUmesh ;
typedef  TYPE_4__ GLUhalfEdge ;
typedef  TYPE_5__ GLUface ;

/* Variables and functions */
 scalar_t__ EdgeGoesLeft (TYPE_4__*) ; 
 scalar_t__ EdgeGoesRight (TYPE_4__*) ; 
 scalar_t__ EdgeSign (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 scalar_t__ VertLeq (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 TYPE_4__* __gl_meshConnect (TYPE_4__*,TYPE_4__*) ; 
 int /*<<< orphan*/  __gl_meshDelete (TYPE_4__*) ; 
 int /*<<< orphan*/  __gl_meshZapFace (TYPE_5__*) ; 
 int /*<<< orphan*/  assert (int) ; 

int __gl_meshTessellateMonoRegion( GLUface *face )
{
  GLUhalfEdge *up, *lo;

  /* All edges are oriented CCW around the boundary of the region.
   * First, find the half-edge whose origin vertex is rightmost.
   * Since the sweep goes from left to right, face->anEdge should
   * be close to the edge we want.
   */
  up = face->anEdge;
  assert( up->Lnext != up && up->Lnext->Lnext != up );

  for( ; VertLeq( up->Dst, up->Org ); up = up->Lprev )
    ;
  for( ; VertLeq( up->Org, up->Dst ); up = up->Lnext )
    ;
  lo = up->Lprev;

  while( up->Lnext != lo ) {
    if( VertLeq( up->Dst, lo->Org )) {
      /* up->Dst is on the left.  It is safe to form triangles from lo->Org.
       * The EdgeGoesLeft test guarantees progress even when some triangles
       * are CW, given that the upper and lower chains are truly monotone.
       */
      while( lo->Lnext != up && (EdgeGoesLeft( lo->Lnext )
	     || EdgeSign( lo->Org, lo->Dst, lo->Lnext->Dst ) <= 0 )) {
	GLUhalfEdge *tempHalfEdge= __gl_meshConnect( lo->Lnext, lo );
	if (tempHalfEdge == NULL) return 0;
	lo = tempHalfEdge->Sym;
      }
      lo = lo->Lprev;
    } else {
      /* lo->Org is on the left.  We can make CCW triangles from up->Dst. */
      while( lo->Lnext != up && (EdgeGoesRight( up->Lprev )
	     || EdgeSign( up->Dst, up->Org, up->Lprev->Org ) >= 0 )) {
	GLUhalfEdge *tempHalfEdge= __gl_meshConnect( up, up->Lprev );
	if (tempHalfEdge == NULL) return 0;
	up = tempHalfEdge->Sym;
      }
      up = up->Lnext;
    }
  }

  /* Now lo->Org == up->Dst == the leftmost vertex.  The remaining region
   * can be tessellated in a fan from this leftmost vertex.
   */
  assert( lo->Lnext != up );
  while( lo->Lnext->Lnext != up ) {
    GLUhalfEdge *tempHalfEdge= __gl_meshConnect( lo->Lnext, lo );
    if (tempHalfEdge == NULL) return 0;
    lo = tempHalfEdge->Sym;
  }

  return 1;
}

int __gl_meshTessellateInterior( GLUmesh *mesh )
{
  GLUface *f, *next;

  /*LINTED*/
  for( f = mesh->fHead.next; f != &mesh->fHead; f = next ) {
    /* Make sure we don''t try to tessellate the new triangles. */
    next = f->next;
    if( f->inside ) {
      if ( !__gl_meshTessellateMonoRegion( f ) ) return 0;
    }
  }

  return 1;
}

void __gl_meshDiscardExterior( GLUmesh *mesh )
{
  GLUface *f, *next;

  /*LINTED*/
  for( f = mesh->fHead.next; f != &mesh->fHead; f = next ) {
    /* Since f will be destroyed, save its next pointer. */
    next = f->next;
    if( ! f->inside ) {
      __gl_meshZapFace( f );
    }
  }
}

int __gl_meshSetWindingNumber( GLUmesh *mesh, int value,
			        GLboolean keepOnlyBoundary )
{
  GLUhalfEdge *e, *eNext;

  for( e = mesh->eHead.next; e != &mesh->eHead; e = eNext ) {
    eNext = e->next;
    if( e->Rface->inside != e->Lface->inside ) {

      /* This is a boundary edge (one side is interior, one is exterior). */
      e->winding = (e->Lface->inside) ? value : -value;
    } else {

      /* Both regions are interior, or both are exterior. */
      if( ! keepOnlyBoundary ) {
	e->winding = 0;
      } else {
	if ( !__gl_meshDelete( e ) ) return 0;
      }
    }
  }
  return 1;
}

