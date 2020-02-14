#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_28__   TYPE_6__ ;
typedef  struct TYPE_27__   TYPE_4__ ;
typedef  struct TYPE_26__   TYPE_3__ ;
typedef  struct TYPE_25__   TYPE_2__ ;
typedef  struct TYPE_24__   TYPE_1__ ;

/* Type definitions */
typedef  scalar_t__ vec_t ;
typedef  int /*<<< orphan*/  vec3_t ;
struct TYPE_25__ {scalar_t__ planenum; int contents; int detail_seperator; struct TYPE_25__** children; TYPE_6__* brushlist; scalar_t__ faces; int /*<<< orphan*/  maxs; int /*<<< orphan*/  mins; struct TYPE_25__* headnode; TYPE_6__* volume; TYPE_3__* portals; } ;
typedef  TYPE_2__ tree_t ;
struct TYPE_26__ {TYPE_2__** nodes; struct TYPE_26__** next; } ;
typedef  TYPE_3__ portal_t ;
struct TYPE_27__ {double* normal; scalar_t__ dist; } ;
typedef  TYPE_4__ plane_t ;
typedef  TYPE_2__ node_t ;
struct TYPE_28__ {struct TYPE_28__* next; TYPE_1__* original; } ;
typedef  TYPE_6__ bspbrush_t ;
struct TYPE_24__ {int brushnum; } ;

/* Variables and functions */
 int CONTENTS_LADDER ; 
 int CONTENTS_SOLID ; 
 int /*<<< orphan*/  ClearBounds (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 scalar_t__ DotProduct (int /*<<< orphan*/ ,double*) ; 
 int /*<<< orphan*/  Error (char*) ; 
 int /*<<< orphan*/  FreeBrush (TYPE_6__*) ; 
 int /*<<< orphan*/  FreeMemory (TYPE_2__*) ; 
 int /*<<< orphan*/  FreePortal (TYPE_3__*) ; 
 TYPE_2__* GetMemory (int) ; 
 int /*<<< orphan*/  Log_Print (char*,...) ; 
 scalar_t__ PLANENUM_LEAF ; 
 int /*<<< orphan*/  RemovePortalFromNode (TYPE_3__*,TYPE_2__*) ; 
 int /*<<< orphan*/  c_nodes ; 
 scalar_t__ c_pruned ; 
 scalar_t__ create_aas ; 
 scalar_t__ freedtreemem ; 
 TYPE_4__* mapplanes ; 
 int /*<<< orphan*/  memset (TYPE_2__*,int /*<<< orphan*/ ,int) ; 
 int numthreads ; 
 int /*<<< orphan*/  printf (char*,...) ; 

node_t *NodeForPoint (node_t *node, vec3_t origin)
{
	plane_t	*plane;
	vec_t	d;

	while (node->planenum != PLANENUM_LEAF)
	{
		plane = &mapplanes[node->planenum];
		d = DotProduct (origin, plane->normal) - plane->dist;
		if (d >= 0)
			node = node->children[0];
		else
			node = node->children[1];
	}
	return node;
}

void Tree_FreePortals_r (node_t *node)
{
	portal_t	*p, *nextp;
	int			s;

	// free children
	if (node->planenum != PLANENUM_LEAF)
	{
		Tree_FreePortals_r(node->children[0]);
		Tree_FreePortals_r(node->children[1]);
	}

	// free portals
	for (p = node->portals; p; p = nextp)
	{
		s = (p->nodes[1] == node);
		nextp = p->next[s];

		RemovePortalFromNode (p, p->nodes[!s]);
#ifdef ME
		if (p->winding) freedtreemem += MemorySize(p->winding);
		freedtreemem += MemorySize(p);
#endif //ME
		FreePortal(p);
	}
	node->portals = NULL;
}

void Tree_Free_r (node_t *node)
{
//	face_t *f, *nextf;
	bspbrush_t *brush, *nextbrush;

	//free children
	if (node->planenum != PLANENUM_LEAF)
	{
		Tree_Free_r (node->children[0]);
		Tree_Free_r (node->children[1]);
	} //end if
	//free bspbrushes
//	FreeBrushList (node->brushlist);
	for (brush = node->brushlist; brush; brush = nextbrush)
	{
		nextbrush = brush->next;
#ifdef ME
		freedtreemem += MemorySize(brush);
#endif //ME
		FreeBrush(brush);
	} //end for
	node->brushlist = NULL;

	/*
	NOTE: only used when creating Q2 bsp
	// free faces
	for (f = node->faces; f; f = nextf)
	{
		nextf = f->next;
#ifdef ME
		if (f->w) freedtreemem += MemorySize(f->w);
		freedtreemem += sizeof(face_t);
#endif //ME
		FreeFace(f);
	} //end for
	*/

	// free the node
	if (node->volume)
	{
#ifdef ME
		freedtreemem += MemorySize(node->volume);
#endif //ME
		FreeBrush (node->volume);
	} //end if

	if (numthreads == 1) c_nodes--;
#ifdef ME
	freedtreemem += MemorySize(node);
#endif //ME
	FreeMemory(node);
}

void Tree_Free(tree_t *tree)
{
	//if no tree just return
	if (!tree) return;
	//
	freedtreemem = 0;
	//
	Tree_FreePortals_r(tree->headnode);
	Tree_Free_r(tree->headnode);
#ifdef ME
	freedtreemem += MemorySize(tree);
#endif //ME
	FreeMemory(tree);
#ifdef ME
	Log_Print("freed ");
	PrintMemorySize(freedtreemem);
	Log_Print(" of tree memory\n");
#endif //ME
}

tree_t *Tree_Alloc(void)
{
	tree_t	*tree;

	tree = GetMemory(sizeof(*tree));
	memset (tree, 0, sizeof(*tree));
	ClearBounds (tree->mins, tree->maxs);

	return tree;
}

void Tree_Print_r (node_t *node, int depth)
{
	int		i;
	plane_t	*plane;
	bspbrush_t	*bb;

	for (i=0 ; i<depth ; i++)
		printf ("  ");
	if (node->planenum == PLANENUM_LEAF)
	{
		if (!node->brushlist)
			printf ("NULL\n");
		else
		{
			for (bb=node->brushlist ; bb ; bb=bb->next)
				printf ("%i ", bb->original->brushnum);
			printf ("\n");
		}
		return;
	}

	plane = &mapplanes[node->planenum];
	printf ("#%i (%5.2f %5.2f %5.2f):%5.2f\n", node->planenum,
		plane->normal[0], plane->normal[1], plane->normal[2],
		plane->dist);
	Tree_Print_r (node->children[0], depth+1);
	Tree_Print_r (node->children[1], depth+1);
}

void Tree_PruneNodes_r (node_t *node)
{
	bspbrush_t *b, *next;

	if (node->planenum == PLANENUM_LEAF) return;

	Tree_PruneNodes_r (node->children[0]);
	Tree_PruneNodes_r (node->children[1]);

	if (create_aas)
	{
		if ((node->children[0]->contents & CONTENTS_LADDER) ||
				(node->children[1]->contents & CONTENTS_LADDER)) return;
	}

	if ((node->children[0]->contents & CONTENTS_SOLID)
		&& (node->children[1]->contents & CONTENTS_SOLID))
	{
		if (node->faces)
			Error ("node->faces seperating CONTENTS_SOLID");
		if (node->children[0]->faces || node->children[1]->faces)
			Error ("!node->faces with children");
		// FIXME: free stuff
		node->planenum = PLANENUM_LEAF;
		node->contents = CONTENTS_SOLID;
		node->detail_seperator = false;

		if (node->brushlist)
			Error ("PruneNodes: node->brushlist");
		// combine brush lists
		node->brushlist = node->children[1]->brushlist;

		for (b = node->children[0]->brushlist; b; b = next)
		{
			next = b->next;
			b->next = node->brushlist;
			node->brushlist = b;
		} //end for
		//free the child nodes
		FreeMemory(node->children[0]);
		FreeMemory(node->children[1]);
		//two nodes are cut away
		c_pruned += 2;
	} //end if
}

void Tree_PruneNodes(node_t *node)
{
	Log_Print("------- Prune Nodes --------\n");
	c_pruned = 0;
	Tree_PruneNodes_r(node);
	Log_Print("%5i pruned nodes\n", c_pruned);
}

