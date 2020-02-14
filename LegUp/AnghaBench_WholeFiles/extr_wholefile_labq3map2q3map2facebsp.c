#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_38__   TYPE_7__ ;
typedef  struct TYPE_37__   TYPE_6__ ;
typedef  struct TYPE_36__   TYPE_5__ ;
typedef  struct TYPE_35__   TYPE_4__ ;
typedef  struct TYPE_34__   TYPE_3__ ;
typedef  struct TYPE_33__   TYPE_2__ ;
typedef  struct TYPE_32__   TYPE_1__ ;

/* Type definitions */
struct TYPE_32__ {int numpoints; int /*<<< orphan*/ * p; } ;
typedef  TYPE_1__ winding_t ;
typedef  int* vec3_t ;
struct TYPE_33__ {float* mins; float* maxs; TYPE_5__* headnode; } ;
typedef  TYPE_2__ tree_t ;
struct TYPE_34__ {int compileFlags; int planenum; TYPE_1__* visibleHull; TYPE_1__* winding; } ;
typedef  TYPE_3__ side_t ;
struct TYPE_35__ {int* normal; float dist; int type; } ;
typedef  TYPE_4__ plane_t ;
struct TYPE_36__ {int* mins; float* maxs; int planenum; struct TYPE_36__** children; struct TYPE_36__* parent; int /*<<< orphan*/  compileFlags; } ;
typedef  TYPE_5__ node_t ;
struct TYPE_37__ {size_t planenum; int compileFlags; struct TYPE_37__* next; scalar_t__ priority; TYPE_1__* w; scalar_t__ checked; } ;
typedef  TYPE_6__ face_t ;
struct TYPE_38__ {int numsides; TYPE_3__* sides; scalar_t__ detail; struct TYPE_38__* next; } ;
typedef  TYPE_7__ brush_t ;

/* Variables and functions */
 scalar_t__ ANTIPORTAL_PRIORITY ; 
 scalar_t__ AREAPORTAL_PRIORITY ; 
 int /*<<< orphan*/  AddPointToBounds (int /*<<< orphan*/ ,float*,float*) ; 
 void* AllocNode () ; 
 TYPE_2__* AllocTree () ; 
 int CLIP_EPSILON ; 
 int C_ANTIPORTAL ; 
 int C_AREAPORTAL ; 
 int C_HINT ; 
 int C_SKIP ; 
 int /*<<< orphan*/  ClipWindingEpsilon (TYPE_1__*,int*,float,int,TYPE_1__**,TYPE_1__**) ; 
 void* CopyWinding (TYPE_1__*) ; 
 int FindFloatPlane (int*,float,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  FreeWinding (TYPE_1__*) ; 
 scalar_t__ HINT_PRIORITY ; 
 int PLANENUM_LEAF ; 
 int SIDE_BACK ; 
 int SIDE_CROSS ; 
 int SIDE_FRONT ; 
 int /*<<< orphan*/  SYS_VRB ; 
 int /*<<< orphan*/  Sys_FPrintf (int /*<<< orphan*/ ,char*,...) ; 
 int /*<<< orphan*/  VectorClear (int*) ; 
 int /*<<< orphan*/  VectorCopy (float*,float*) ; 
 int WindingOnPlaneSide (TYPE_1__*,int*,float) ; 
 int* blockSize ; 
 int c_faceLeafs ; 
 int floor (int) ; 
 int /*<<< orphan*/  free (TYPE_6__*) ; 
 TYPE_4__* mapplanes ; 
 int /*<<< orphan*/  memset (TYPE_6__*,int /*<<< orphan*/ ,int) ; 
 scalar_t__ qfalse ; 
 scalar_t__ qtrue ; 
 TYPE_6__* safe_malloc (int) ; 

face_t  *AllocBspFace( void ) {
	face_t  *f;

	f = safe_malloc( sizeof( *f ) );
	memset( f, 0, sizeof( *f ) );

	return f;
}

void    FreeBspFace( face_t *f ) {
	if ( f->w ) {
		FreeWinding( f->w );
	}
	free( f );
}

__attribute__((used)) static void SelectSplitPlaneNum( node_t *node, face_t *list, int *splitPlaneNum, int *compileFlags ){
	face_t      *split;
	face_t      *check;
	face_t      *bestSplit;
	int splits, facing, front, back;
	int side;
	plane_t     *plane;
	int value, bestValue;
	int i;
	vec3_t normal;
	float dist;
	int planenum;


	/* ydnar: set some defaults */
	*splitPlaneNum = -1; /* leaf */
	*compileFlags = 0;

	/* ydnar 2002-06-24: changed this to split on z-axis as well */
	/* ydnar 2002-09-21: changed blocksize to be a vector, so mappers can specify a 3 element value */

	/* if it is crossing a block boundary, force a split */
	for ( i = 0; i < 3; i++ )
	{
		if ( blockSize[ i ] <= 0 ) {
			continue;
		}
		dist = blockSize[ i ] * ( floor( node->mins[ i ] / blockSize[ i ] ) + 1 );
		if ( node->maxs[ i ] > dist ) {
			VectorClear( normal );
			normal[ i ] = 1;
			planenum = FindFloatPlane( normal, dist, 0, NULL );
			*splitPlaneNum = planenum;
			return;
		}
	}

	/* pick one of the face planes */
	bestValue = -99999;
	bestSplit = list;

	for ( split = list; split; split = split->next )
		split->checked = qfalse;

	for ( split = list; split; split = split->next )
	{
		if ( split->checked ) {
			continue;
		}

		plane = &mapplanes[ split->planenum ];
		splits = 0;
		facing = 0;
		front = 0;
		back = 0;
		for ( check = list ; check ; check = check->next ) {
			if ( check->planenum == split->planenum ) {
				facing++;
				check->checked = qtrue; // won't need to test this plane again
				continue;
			}
			side = WindingOnPlaneSide( check->w, plane->normal, plane->dist );
			if ( side == SIDE_CROSS ) {
				splits++;
			}
			else if ( side == SIDE_FRONT ) {
				front++;
			}
			else if ( side == SIDE_BACK ) {
				back++;
			}
		}
		value =  5 * facing - 5 * splits; // - abs(front-back);
		if ( plane->type < 3 ) {
			value += 5;       // axial is better
		}
		value += split->priority;       // prioritize hints higher

		if ( value > bestValue ) {
			bestValue = value;
			bestSplit = split;
		}
	}

	/* nothing, we have a leaf */
	if ( bestValue == -99999 ) {
		return;
	}

	/* set best split data */
	*splitPlaneNum = bestSplit->planenum;
	*compileFlags = bestSplit->compileFlags;
}

int CountFaceList( face_t *list ){
	int c;


	c = 0;
	for ( ; list != NULL; list = list->next )
		c++;
	return c;
}

void BuildFaceTree_r( node_t *node, face_t *list ){
	face_t      *split;
	face_t      *next;
	int side;
	plane_t     *plane;
	face_t      *newFace;
	face_t      *childLists[2];
	winding_t   *frontWinding, *backWinding;
	int i;
	int splitPlaneNum, compileFlags;


	/* count faces left */
	i = CountFaceList( list );

	/* select the best split plane */
	SelectSplitPlaneNum( node, list, &splitPlaneNum, &compileFlags );

	/* if we don't have any more faces, this is a node */
	if ( splitPlaneNum == -1 ) {
		node->planenum = PLANENUM_LEAF;
		c_faceLeafs++;
		return;
	}

	/* partition the list */
	node->planenum = splitPlaneNum;
	node->compileFlags = compileFlags;
	plane = &mapplanes[ splitPlaneNum ];
	childLists[0] = NULL;
	childLists[1] = NULL;
	for ( split = list; split; split = next )
	{
		/* set next */
		next = split->next;

		/* don't split by identical plane */
		if ( split->planenum == node->planenum ) {
			FreeBspFace( split );
			continue;
		}

		/* determine which side the face falls on */
		side = WindingOnPlaneSide( split->w, plane->normal, plane->dist );

		/* switch on side */
		if ( side == SIDE_CROSS ) {
			ClipWindingEpsilon( split->w, plane->normal, plane->dist, CLIP_EPSILON * 2,
								&frontWinding, &backWinding );
			if ( frontWinding ) {
				newFace = AllocBspFace();
				newFace->w = frontWinding;
				newFace->next = childLists[0];
				newFace->planenum = split->planenum;
				newFace->priority = split->priority;
				newFace->compileFlags = split->compileFlags;
				childLists[0] = newFace;
			}
			if ( backWinding ) {
				newFace = AllocBspFace();
				newFace->w = backWinding;
				newFace->next = childLists[1];
				newFace->planenum = split->planenum;
				newFace->priority = split->priority;
				newFace->compileFlags = split->compileFlags;
				childLists[1] = newFace;
			}
			FreeBspFace( split );
		}
		else if ( side == SIDE_FRONT ) {
			split->next = childLists[0];
			childLists[0] = split;
		}
		else if ( side == SIDE_BACK ) {
			split->next = childLists[1];
			childLists[1] = split;
		}
	}


	// recursively process children
	for ( i = 0 ; i < 2 ; i++ ) {
		node->children[i] = AllocNode();
		node->children[i]->parent = node;
		VectorCopy( node->mins, node->children[i]->mins );
		VectorCopy( node->maxs, node->children[i]->maxs );
	}

	for ( i = 0 ; i < 3 ; i++ ) {
		if ( plane->normal[i] == 1 ) {
			node->children[0]->mins[i] = plane->dist;
			node->children[1]->maxs[i] = plane->dist;
			break;
		}
	}

	for ( i = 0 ; i < 2 ; i++ ) {
		BuildFaceTree_r( node->children[i], childLists[i] );
	}
}

tree_t *FaceBSP( face_t *list ) {
	tree_t      *tree;
	face_t  *face;
	int i;
	int count;

	Sys_FPrintf( SYS_VRB, "--- FaceBSP ---\n" );

	tree = AllocTree();

	count = 0;
	for ( face = list; face != NULL; face = face->next )
	{
		count++;
		for ( i = 0; i < face->w->numpoints; i++ )
		{
			AddPointToBounds( face->w->p[ i ], tree->mins, tree->maxs );
		}
	}
	Sys_FPrintf( SYS_VRB, "%9d faces\n", count );

	tree->headnode = AllocNode();
	VectorCopy( tree->mins, tree->headnode->mins );
	VectorCopy( tree->maxs, tree->headnode->maxs );
	c_faceLeafs = 0;

	BuildFaceTree_r( tree->headnode, list );

	Sys_FPrintf( SYS_VRB, "%9d leafs\n", c_faceLeafs );

	return tree;
}

face_t *MakeStructuralBSPFaceList( brush_t *list ){
	brush_t     *b;
	int i;
	side_t      *s;
	winding_t   *w;
	face_t      *f, *flist;


	flist = NULL;
	for ( b = list; b != NULL; b = b->next )
	{
		if ( b->detail ) {
			continue;
		}

		for ( i = 0; i < b->numsides; i++ )
		{
			/* get side and winding */
			s = &b->sides[ i ];
			w = s->winding;
			if ( w == NULL ) {
				continue;
			}

			/* ydnar: skip certain faces */
			if ( s->compileFlags & C_SKIP ) {
				continue;
			}

			/* allocate a face */
			f = AllocBspFace();
			f->w = CopyWinding( w );
			f->planenum = s->planenum & ~1;
			f->compileFlags = s->compileFlags;  /* ydnar */

			/* ydnar: set priority */
			f->priority = 0;
			if ( f->compileFlags & C_HINT ) {
				f->priority += HINT_PRIORITY;
			}
			if ( f->compileFlags & C_ANTIPORTAL ) {
				f->priority += ANTIPORTAL_PRIORITY;
			}
			if ( f->compileFlags & C_AREAPORTAL ) {
				f->priority += AREAPORTAL_PRIORITY;
			}

			/* get next face */
			f->next = flist;
			flist = f;
		}
	}

	return flist;
}

face_t *MakeVisibleBSPFaceList( brush_t *list ){
	brush_t     *b;
	int i;
	side_t      *s;
	winding_t   *w;
	face_t      *f, *flist;


	flist = NULL;
	for ( b = list; b != NULL; b = b->next )
	{
		if ( b->detail ) {
			continue;
		}

		for ( i = 0; i < b->numsides; i++ )
		{
			/* get side and winding */
			s = &b->sides[ i ];
			w = s->visibleHull;
			if ( w == NULL ) {
				continue;
			}

			/* ydnar: skip certain faces */
			if ( s->compileFlags & C_SKIP ) {
				continue;
			}

			/* allocate a face */
			f = AllocBspFace();
			f->w = CopyWinding( w );
			f->planenum = s->planenum & ~1;
			f->compileFlags = s->compileFlags;  /* ydnar */

			/* ydnar: set priority */
			f->priority = 0;
			if ( f->compileFlags & C_HINT ) {
				f->priority += HINT_PRIORITY;
			}
			if ( f->compileFlags & C_ANTIPORTAL ) {
				f->priority += ANTIPORTAL_PRIORITY;
			}
			if ( f->compileFlags & C_AREAPORTAL ) {
				f->priority += AREAPORTAL_PRIORITY;
			}

			/* get next face */
			f->next = flist;
			flist = f;
		}
	}

	return flist;
}

