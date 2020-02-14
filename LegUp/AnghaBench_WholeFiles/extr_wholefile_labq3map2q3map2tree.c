#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_23__   TYPE_6__ ;
typedef  struct TYPE_22__   TYPE_4__ ;
typedef  struct TYPE_21__   TYPE_3__ ;
typedef  struct TYPE_20__   TYPE_2__ ;
typedef  struct TYPE_19__   TYPE_1__ ;

/* Type definitions */
typedef  scalar_t__ vec_t ;
typedef  int /*<<< orphan*/  vec3_t ;
struct TYPE_20__ {scalar_t__ planenum; struct TYPE_20__** children; TYPE_6__* brushlist; struct TYPE_20__* headnode; scalar_t__ volume; TYPE_3__* portals; } ;
typedef  TYPE_2__ tree_t ;
struct TYPE_21__ {TYPE_2__** nodes; struct TYPE_21__** next; } ;
typedef  TYPE_3__ portal_t ;
struct TYPE_22__ {scalar_t__ dist; int /*<<< orphan*/ * normal; } ;
typedef  TYPE_4__ plane_t ;
typedef  TYPE_2__ node_t ;
struct TYPE_23__ {TYPE_1__* original; struct TYPE_23__* next; } ;
typedef  TYPE_6__ brush_t ;
struct TYPE_19__ {int /*<<< orphan*/  brushNum; } ;

/* Variables and functions */
 scalar_t__ DotProduct (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  FreeBrush (scalar_t__) ; 
 int /*<<< orphan*/  FreeBrushList (TYPE_6__*) ; 
 int /*<<< orphan*/  FreePortal (TYPE_3__*) ; 
 scalar_t__ PLANENUM_LEAF ; 
 int /*<<< orphan*/  RemovePortalFromNode (TYPE_3__*,TYPE_2__*) ; 
 int /*<<< orphan*/  Sys_Printf (char*,...) ; 
 int /*<<< orphan*/  free (TYPE_2__*) ; 
 TYPE_4__* mapplanes ; 

node_t *NodeForPoint( node_t *node, vec3_t origin ){
	plane_t *plane;
	vec_t d;

	while ( node->planenum != PLANENUM_LEAF )
	{
		plane = &mapplanes[node->planenum];
		d = DotProduct( origin, plane->normal ) - plane->dist;
		if ( d >= 0 ) {
			node = node->children[0];
		}
		else{
			node = node->children[1];
		}
	}

	return node;
}

void FreeTreePortals_r( node_t *node ){
	portal_t    *p, *nextp;
	int s;

	// free children
	if ( node->planenum != PLANENUM_LEAF ) {
		FreeTreePortals_r( node->children[0] );
		FreeTreePortals_r( node->children[1] );
	}

	// free portals
	for ( p = node->portals ; p ; p = nextp )
	{
		s = ( p->nodes[1] == node );
		nextp = p->next[s];

		RemovePortalFromNode( p, p->nodes[!s] );
		FreePortal( p );
	}
	node->portals = NULL;
}

void FreeTree_r( node_t *node ){
	// free children
	if ( node->planenum != PLANENUM_LEAF ) {
		FreeTree_r( node->children[0] );
		FreeTree_r( node->children[1] );
	}

	// free bspbrushes
	FreeBrushList( node->brushlist );

	// free the node
	if ( node->volume ) {
		FreeBrush( node->volume );
	}

	free( node );
}

void FreeTree( tree_t *tree ){
	FreeTreePortals_r( tree->headnode );
	FreeTree_r( tree->headnode );
	free( tree );
}

void PrintTree_r( node_t *node, int depth ){
	int i;
	plane_t *plane;
	brush_t *bb;

	for ( i = 0 ; i < depth ; i++ )
		Sys_Printf( "  " );
	if ( node->planenum == PLANENUM_LEAF ) {
		if ( !node->brushlist ) {
			Sys_Printf( "NULL\n" );
		}
		else
		{
			for ( bb = node->brushlist ; bb ; bb = bb->next )
				Sys_Printf( "%d ", bb->original->brushNum );
			Sys_Printf( "\n" );
		}
		return;
	}

	plane = &mapplanes[node->planenum];
	Sys_Printf( "#%d (%5.2f %5.2f %5.2f):%5.2f\n", node->planenum,
				plane->normal[0], plane->normal[1], plane->normal[2],
				plane->dist );
	PrintTree_r( node->children[0], depth + 1 );
	PrintTree_r( node->children[1], depth + 1 );
}

