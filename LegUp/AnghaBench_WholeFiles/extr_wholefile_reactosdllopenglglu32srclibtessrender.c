#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_39__   TYPE_7__ ;
typedef  struct TYPE_38__   TYPE_6__ ;
typedef  struct TYPE_37__   TYPE_5__ ;
typedef  struct TYPE_36__   TYPE_4__ ;
typedef  struct TYPE_35__   TYPE_3__ ;
typedef  struct TYPE_34__   TYPE_2__ ;
typedef  struct TYPE_33__   TYPE_27__ ;
typedef  struct TYPE_32__   TYPE_1__ ;

/* Type definitions */
struct FaceCount {int size; void (* render ) (TYPE_3__*,TYPE_5__*,long) ;void (* member_2 ) (TYPE_3__*,TYPE_5__*,long) ;TYPE_5__* eStart; int /*<<< orphan*/ * member_1; int /*<<< orphan*/  member_0; } ;
struct TYPE_39__ {scalar_t__* coords; int /*<<< orphan*/  data; } ;
struct TYPE_38__ {int marked; TYPE_5__* anEdge; scalar_t__ inside; struct TYPE_38__* next; struct TYPE_38__* trail; } ;
struct TYPE_37__ {struct TYPE_37__* Lnext; TYPE_2__* Org; TYPE_1__* Dst; struct TYPE_37__* Onext; TYPE_27__* Lface; struct TYPE_37__* Dprev; TYPE_27__* Rface; struct TYPE_37__* Sym; struct TYPE_37__* Oprev; struct TYPE_37__* Dnext; struct TYPE_37__* Lprev; } ;
struct TYPE_36__ {TYPE_6__ fHead; } ;
struct TYPE_35__ {int cacheCount; scalar_t__* normal; int windingRule; scalar_t__ boundaryOnly; TYPE_7__* cache; scalar_t__ flagBoundary; TYPE_6__* lonelyTriList; } ;
struct TYPE_34__ {int /*<<< orphan*/  data; } ;
struct TYPE_33__ {void* marked; int /*<<< orphan*/  inside; } ;
struct TYPE_32__ {int /*<<< orphan*/  data; } ;
typedef  scalar_t__ GLdouble ;
typedef  void* GLboolean ;
typedef  TYPE_3__ GLUtesselator ;
typedef  TYPE_4__ GLUmesh ;
typedef  TYPE_5__ GLUhalfEdge ;
typedef  TYPE_6__ GLUface ;
typedef  TYPE_7__ CachedVertex ;

/* Variables and functions */
 int /*<<< orphan*/  AddToTrail (TYPE_27__*,TYPE_6__*) ; 
 int /*<<< orphan*/  CALL_BEGIN_OR_BEGIN_DATA (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  CALL_EDGE_FLAG_OR_EDGE_FLAG_DATA (int) ; 
 int /*<<< orphan*/  CALL_END_OR_END_DATA () ; 
 int /*<<< orphan*/  CALL_VERTEX_OR_VERTEX_DATA (int /*<<< orphan*/ ) ; 
 void* FALSE ; 
 int /*<<< orphan*/  FreeTrail (TYPE_6__*) ; 
#define  GLU_TESS_WINDING_ABS_GEQ_TWO 132 
#define  GLU_TESS_WINDING_NEGATIVE 131 
#define  GLU_TESS_WINDING_NONZERO 130 
#define  GLU_TESS_WINDING_ODD 129 
#define  GLU_TESS_WINDING_POSITIVE 128 
 int /*<<< orphan*/  GL_LINE_LOOP ; 
 int /*<<< orphan*/  GL_TRIANGLES ; 
 int /*<<< orphan*/  GL_TRIANGLE_FAN ; 
 int /*<<< orphan*/  GL_TRIANGLE_STRIP ; 
 scalar_t__ IsEven (long) ; 
 scalar_t__ Marked (TYPE_27__*) ; 
static  struct FaceCount MaximumFan (TYPE_5__*) ; 
static  struct FaceCount MaximumStrip (TYPE_5__*) ; 
static  void RenderFan (TYPE_3__*,TYPE_5__*,long) ; 
static  void RenderLonelyTriangles (TYPE_3__*,TYPE_6__*) ; 
static  void RenderMaximumFaceGroup (TYPE_3__*,TYPE_6__*) ; 
static  void RenderStrip (TYPE_3__*,TYPE_5__*,long) ; 
static  void RenderTriangle (TYPE_3__*,TYPE_5__*,long) ; 
 int SIGN_INCONSISTENT ; 
 void* TRUE ; 
 int /*<<< orphan*/  assert (int) ; 
 void stub1 (TYPE_3__*,TYPE_5__*,long) ; 

void __gl_renderMesh( GLUtesselator *tess, GLUmesh *mesh )
{
  GLUface *f;

  /* Make a list of separate triangles so we can render them all at once */
  tess->lonelyTriList = NULL;

  for( f = mesh->fHead.next; f != &mesh->fHead; f = f->next ) {
    f->marked = FALSE;
  }
  for( f = mesh->fHead.next; f != &mesh->fHead; f = f->next ) {

    /* We examine all faces in an arbitrary order.  Whenever we find
     * an unprocessed face F, we output a group of faces including F
     * whose size is maximum.
     */
    if( f->inside && ! f->marked ) {
      RenderMaximumFaceGroup( tess, f );
      assert( f->marked );
    }
  }
  if( tess->lonelyTriList != NULL ) {
    RenderLonelyTriangles( tess, tess->lonelyTriList );
    tess->lonelyTriList = NULL;
  }
}

__attribute__((used)) static void RenderMaximumFaceGroup( GLUtesselator *tess, GLUface *fOrig )
{
  /* We want to find the largest triangle fan or strip of unmarked faces
   * which includes the given face fOrig.  There are 3 possible fans
   * passing through fOrig (one centered at each vertex), and 3 possible
   * strips (one for each CCW permutation of the vertices).  Our strategy
   * is to try all of these, and take the primitive which uses the most
   * triangles (a greedy approach).
   */
  GLUhalfEdge *e = fOrig->anEdge;
  struct FaceCount max, newFace;

  max.size = 1;
  max.eStart = e;
  max.render = &RenderTriangle;

  if( ! tess->flagBoundary ) {
    newFace = MaximumFan( e ); if( newFace.size > max.size ) { max = newFace; }
    newFace = MaximumFan( e->Lnext ); if( newFace.size > max.size ) { max = newFace; }
    newFace = MaximumFan( e->Lprev ); if( newFace.size > max.size ) { max = newFace; }

    newFace = MaximumStrip( e ); if( newFace.size > max.size ) { max = newFace; }
    newFace = MaximumStrip( e->Lnext ); if( newFace.size > max.size ) { max = newFace; }
    newFace = MaximumStrip( e->Lprev ); if( newFace.size > max.size ) { max = newFace; }
  }
  (*(max.render))( tess, max.eStart, max.size );
}

__attribute__((used)) static struct FaceCount MaximumFan( GLUhalfEdge *eOrig )
{
  /* eOrig->Lface is the face we want to render.  We want to find the size
   * of a maximal fan around eOrig->Org.  To do this we just walk around
   * the origin vertex as far as possible in both directions.
   */
  struct FaceCount newFace = { 0, NULL, &RenderFan };
  GLUface *trail = NULL;
  GLUhalfEdge *e;

  for( e = eOrig; ! Marked( e->Lface ); e = e->Onext ) {
    AddToTrail( e->Lface, trail );
    ++newFace.size;
  }
  for( e = eOrig; ! Marked( e->Rface ); e = e->Oprev ) {
    AddToTrail( e->Rface, trail );
    ++newFace.size;
  }
  newFace.eStart = e;
  /*LINTED*/
  FreeTrail( trail );
  return newFace;
}

__attribute__((used)) static struct FaceCount MaximumStrip( GLUhalfEdge *eOrig )
{
  /* Here we are looking for a maximal strip that contains the vertices
   * eOrig->Org, eOrig->Dst, eOrig->Lnext->Dst (in that order or the
   * reverse, such that all triangles are oriented CCW).
   *
   * Again we walk forward and backward as far as possible.  However for
   * strips there is a twist: to get CCW orientations, there must be
   * an *even* number of triangles in the strip on one side of eOrig.
   * We walk the strip starting on a side with an even number of triangles;
   * if both side have an odd number, we are forced to shorten one side.
   */
  struct FaceCount newFace = { 0, NULL, &RenderStrip };
  long headSize = 0, tailSize = 0;
  GLUface *trail = NULL;
  GLUhalfEdge *e, *eTail, *eHead;

  for( e = eOrig; ! Marked( e->Lface ); ++tailSize, e = e->Onext ) {
    AddToTrail( e->Lface, trail );
    ++tailSize;
    e = e->Dprev;
    if( Marked( e->Lface )) break;
    AddToTrail( e->Lface, trail );
  }
  eTail = e;

  for( e = eOrig; ! Marked( e->Rface ); ++headSize, e = e->Dnext ) {
    AddToTrail( e->Rface, trail );
    ++headSize;
    e = e->Oprev;
    if( Marked( e->Rface )) break;
    AddToTrail( e->Rface, trail );
  }
  eHead = e;

  newFace.size = tailSize + headSize;
  if( IsEven( tailSize )) {
    newFace.eStart = eTail->Sym;
  } else if( IsEven( headSize )) {
    newFace.eStart = eHead;
  } else {
    /* Both sides have odd length, we must shorten one of them.  In fact,
     * we must start from eHead to guarantee inclusion of eOrig->Lface.
     */
    --newFace.size;
    newFace.eStart = eHead->Onext;
  }
  /*LINTED*/
  FreeTrail( trail );
  return newFace;
}

__attribute__((used)) static void RenderTriangle( GLUtesselator *tess, GLUhalfEdge *e, long size )
{
  /* Just add the triangle to a triangle list, so we can render all
   * the separate triangles at once.
   */
  assert( size == 1 );
  AddToTrail( e->Lface, tess->lonelyTriList );
}

__attribute__((used)) static void RenderLonelyTriangles( GLUtesselator *tess, GLUface *f )
{
  /* Now we render all the separate triangles which could not be
   * grouped into a triangle fan or strip.
   */
  GLUhalfEdge *e;
  int newState;
  int edgeState = -1;	/* force edge state output for first vertex */

  CALL_BEGIN_OR_BEGIN_DATA( GL_TRIANGLES );

  for( ; f != NULL; f = f->trail ) {
    /* Loop once for each edge (there will always be 3 edges) */

    e = f->anEdge;
    do {
      if( tess->flagBoundary ) {
	/* Set the "edge state" to TRUE just before we output the
	 * first vertex of each edge on the polygon boundary.
	 */
	newState = ! e->Rface->inside;
	if( edgeState != newState ) {
	  edgeState = newState;
          CALL_EDGE_FLAG_OR_EDGE_FLAG_DATA( edgeState );
	}
      }
      CALL_VERTEX_OR_VERTEX_DATA( e->Org->data );

      e = e->Lnext;
    } while( e != f->anEdge );
  }
  CALL_END_OR_END_DATA();
}

__attribute__((used)) static void RenderFan( GLUtesselator *tess, GLUhalfEdge *e, long size )
{
  /* Render as many CCW triangles as possible in a fan starting from
   * edge "e".  The fan *should* contain exactly "size" triangles
   * (otherwise we've goofed up somewhere).
   */
  CALL_BEGIN_OR_BEGIN_DATA( GL_TRIANGLE_FAN ); 
  CALL_VERTEX_OR_VERTEX_DATA( e->Org->data ); 
  CALL_VERTEX_OR_VERTEX_DATA( e->Dst->data ); 

  while( ! Marked( e->Lface )) {
    e->Lface->marked = TRUE;
    --size;
    e = e->Onext;
    CALL_VERTEX_OR_VERTEX_DATA( e->Dst->data ); 
  }

  assert( size == 0 );
  CALL_END_OR_END_DATA();
}

__attribute__((used)) static void RenderStrip( GLUtesselator *tess, GLUhalfEdge *e, long size )
{
  /* Render as many CCW triangles as possible in a strip starting from
   * edge "e".  The strip *should* contain exactly "size" triangles
   * (otherwise we've goofed up somewhere).
   */
  CALL_BEGIN_OR_BEGIN_DATA( GL_TRIANGLE_STRIP );
  CALL_VERTEX_OR_VERTEX_DATA( e->Org->data ); 
  CALL_VERTEX_OR_VERTEX_DATA( e->Dst->data ); 

  while( ! Marked( e->Lface )) {
    e->Lface->marked = TRUE;
    --size;
    e = e->Dprev;
    CALL_VERTEX_OR_VERTEX_DATA( e->Org->data ); 
    if( Marked( e->Lface )) break;

    e->Lface->marked = TRUE;
    --size;
    e = e->Onext;
    CALL_VERTEX_OR_VERTEX_DATA( e->Dst->data ); 
  }

  assert( size == 0 );
  CALL_END_OR_END_DATA();
}

void __gl_renderBoundary( GLUtesselator *tess, GLUmesh *mesh )
{
  GLUface *f;
  GLUhalfEdge *e;

  for( f = mesh->fHead.next; f != &mesh->fHead; f = f->next ) {
    if( f->inside ) {
      CALL_BEGIN_OR_BEGIN_DATA( GL_LINE_LOOP );
      e = f->anEdge;
      do {
        CALL_VERTEX_OR_VERTEX_DATA( e->Org->data ); 
	e = e->Lnext;
      } while( e != f->anEdge );
      CALL_END_OR_END_DATA();
    }
  }
}

__attribute__((used)) static int ComputeNormal( GLUtesselator *tess, GLdouble norm[3], int check )
/*
 * If check==FALSE, we compute the polygon normal and place it in norm[].
 * If check==TRUE, we check that each triangle in the fan from v0 has a
 * consistent orientation with respect to norm[].  If triangles are
 * consistently oriented CCW, return 1; if CW, return -1; if all triangles
 * are degenerate return 0; otherwise (no consistent orientation) return
 * SIGN_INCONSISTENT.
 */
{
  CachedVertex *v0 = tess->cache;
  CachedVertex *vn = v0 + tess->cacheCount;
  CachedVertex *vc;
  GLdouble dot, xc, yc, zc, xp, yp, zp, n[3];
  int sign = 0;

  /* Find the polygon normal.  It is important to get a reasonable
   * normal even when the polygon is self-intersecting (eg. a bowtie).
   * Otherwise, the computed normal could be very tiny, but perpendicular
   * to the true plane of the polygon due to numerical noise.  Then all
   * the triangles would appear to be degenerate and we would incorrectly
   * decompose the polygon as a fan (or simply not render it at all).
   *
   * We use a sum-of-triangles normal algorithm rather than the more
   * efficient sum-of-trapezoids method (used in CheckOrientation()
   * in normal.c).  This lets us explicitly reverse the signed area
   * of some triangles to get a reasonable normal in the self-intersecting
   * case.
   */
  if( ! check ) {
    norm[0] = norm[1] = norm[2] = 0.0;
  }

  vc = v0 + 1;
  xc = vc->coords[0] - v0->coords[0];
  yc = vc->coords[1] - v0->coords[1];
  zc = vc->coords[2] - v0->coords[2];
  while( ++vc < vn ) {
    xp = xc; yp = yc; zp = zc;
    xc = vc->coords[0] - v0->coords[0];
    yc = vc->coords[1] - v0->coords[1];
    zc = vc->coords[2] - v0->coords[2];

    /* Compute (vp - v0) cross (vc - v0) */
    n[0] = yp*zc - zp*yc;
    n[1] = zp*xc - xp*zc;
    n[2] = xp*yc - yp*xc;

    dot = n[0]*norm[0] + n[1]*norm[1] + n[2]*norm[2];
    if( ! check ) {
      /* Reverse the contribution of back-facing triangles to get
       * a reasonable normal for self-intersecting polygons (see above)
       */
      if( dot >= 0 ) {
	norm[0] += n[0]; norm[1] += n[1]; norm[2] += n[2];
      } else {
	norm[0] -= n[0]; norm[1] -= n[1]; norm[2] -= n[2];
      }
    } else if( dot != 0 ) {
      /* Check the new orientation for consistency with previous triangles */
      if( dot > 0 ) {
	if( sign < 0 ) return SIGN_INCONSISTENT;
	sign = 1;
      } else {
	if( sign > 0 ) return SIGN_INCONSISTENT;
	sign = -1;
      }
    }
  }
  return sign;
}

GLboolean __gl_renderCache( GLUtesselator *tess )
{
  CachedVertex *v0 = tess->cache;
  CachedVertex *vn = v0 + tess->cacheCount;
  CachedVertex *vc;
  GLdouble norm[3];
  int sign;

  if( tess->cacheCount < 3 ) {
    /* Degenerate contour -- no output */
    return TRUE;
  }

  norm[0] = tess->normal[0];
  norm[1] = tess->normal[1];
  norm[2] = tess->normal[2];
  if( norm[0] == 0 && norm[1] == 0 && norm[2] == 0 ) {
    ComputeNormal( tess, norm, FALSE );
  }

  sign = ComputeNormal( tess, norm, TRUE );
  if( sign == SIGN_INCONSISTENT ) {
    /* Fan triangles did not have a consistent orientation */
    return FALSE;
  }
  if( sign == 0 ) {
    /* All triangles were degenerate */
    return TRUE;
  }

  /* Make sure we do the right thing for each winding rule */
  switch( tess->windingRule ) {
  case GLU_TESS_WINDING_ODD:
  case GLU_TESS_WINDING_NONZERO:
    break;
  case GLU_TESS_WINDING_POSITIVE:
    if( sign < 0 ) return TRUE;
    break;
  case GLU_TESS_WINDING_NEGATIVE:
    if( sign > 0 ) return TRUE;
    break;
  case GLU_TESS_WINDING_ABS_GEQ_TWO:
    return TRUE;
  }

  CALL_BEGIN_OR_BEGIN_DATA( tess->boundaryOnly ? GL_LINE_LOOP
			  : (tess->cacheCount > 3) ? GL_TRIANGLE_FAN
			  : GL_TRIANGLES );

  CALL_VERTEX_OR_VERTEX_DATA( v0->data ); 
  if( sign > 0 ) {
    for( vc = v0+1; vc < vn; ++vc ) {
      CALL_VERTEX_OR_VERTEX_DATA( vc->data ); 
    }
  } else {
    for( vc = vn-1; vc > v0; --vc ) {
      CALL_VERTEX_OR_VERTEX_DATA( vc->data ); 
    }
  }
  CALL_END_OR_END_DATA();
  return TRUE;
}

