#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_26__   TYPE_6__ ;
typedef  struct TYPE_25__   TYPE_5__ ;
typedef  struct TYPE_24__   TYPE_4__ ;
typedef  struct TYPE_23__   TYPE_3__ ;
typedef  struct TYPE_22__   TYPE_2__ ;
typedef  struct TYPE_21__   TYPE_1__ ;

/* Type definitions */
struct TYPE_22__ {int numpoints; double** p; } ;
typedef  TYPE_2__ winding_t ;
typedef  double vec_t ;
typedef  int /*<<< orphan*/  vec3_t ;
struct TYPE_23__ {TYPE_5__* headnode; } ;
typedef  TYPE_3__ tree_t ;
struct TYPE_21__ {int /*<<< orphan*/  normal; } ;
struct TYPE_24__ {struct TYPE_24__** next; TYPE_5__** nodes; TYPE_1__ plane; TYPE_2__* winding; } ;
typedef  TYPE_4__ portal_t ;
struct TYPE_25__ {scalar_t__ planenum; int contents; int cluster; struct TYPE_25__** children; scalar_t__ detail_seperator; TYPE_4__* portals; } ;
typedef  TYPE_5__ node_t ;
struct TYPE_26__ {int cluster; } ;
typedef  int /*<<< orphan*/  FILE ;

/* Variables and functions */
 int CONTENTS_SOLID ; 
 double DotProduct (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  Error (char*,char*) ; 
 int /*<<< orphan*/  MakeHeadnodePortals (TYPE_3__*) ; 
 int /*<<< orphan*/  MakeNodePortal (TYPE_5__*) ; 
 scalar_t__ PLANENUM_LEAF ; 
 char* PORTALFILE ; 
 scalar_t__ Portal_VisFlood (TYPE_4__*) ; 
 scalar_t__ Q_rint (double) ; 
 int /*<<< orphan*/  SplitNodePortals (TYPE_5__*) ; 
 int /*<<< orphan*/  Tree_FreePortals_r (TYPE_5__*) ; 
 int /*<<< orphan*/  WindingPlane (TYPE_2__*,int /*<<< orphan*/ ,double*) ; 
 int clusterleaf ; 
 TYPE_6__* dleafs ; 
 double fabs (scalar_t__) ; 
 int /*<<< orphan*/  fclose (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/ * fopen (char*,char*) ; 
 int /*<<< orphan*/  fprintf (int /*<<< orphan*/ *,char*,...) ; 
 int num_visclusters ; 
 int num_visportals ; 
 int /*<<< orphan*/ * pf ; 
 int /*<<< orphan*/  printf (char*,char*) ; 
 int /*<<< orphan*/  qprintf (char*,...) ; 
 char* source ; 
 int /*<<< orphan*/  sprintf (char*,char*,char*) ; 

void WriteFloat2 (FILE *f, vec_t v)
{
	if ( fabs(v - Q_rint(v)) < 0.001 )
		fprintf (f,"%i ",(int)Q_rint(v));
	else
		fprintf (f,"%f ",v);
}

void WritePortalFile_r (node_t *node)
{
	int			i, s;	
	portal_t	*p;
	winding_t	*w;
	vec3_t		normal;
	vec_t		dist;

	// decision node
	if (node->planenum != PLANENUM_LEAF && !node->detail_seperator)
	{
		WritePortalFile_r (node->children[0]);
		WritePortalFile_r (node->children[1]);
		return;
	}
	
	if (node->contents & CONTENTS_SOLID)
		return;

	for (p = node->portals ; p ; p=p->next[s])
	{
		w = p->winding;
		s = (p->nodes[1] == node);
		if (w && p->nodes[0] == node)
		{
			if (!Portal_VisFlood (p))
				continue;
		// write out to the file
		
		// sometimes planes get turned around when they are very near
		// the changeover point between different axis.  interpret the
		// plane the same way vis will, and flip the side orders if needed
			// FIXME: is this still relevent?
			WindingPlane (w, normal, &dist);
			if ( DotProduct (p->plane.normal, normal) < 0.99 )
			{	// backwards...
				fprintf (pf,"%i %i %i ",w->numpoints, p->nodes[1]->cluster, p->nodes[0]->cluster);
			}
			else
				fprintf (pf,"%i %i %i ",w->numpoints, p->nodes[0]->cluster, p->nodes[1]->cluster);
			for (i=0 ; i<w->numpoints ; i++)
			{
				fprintf (pf,"(");
				WriteFloat2 (pf, w->p[i][0]);
				WriteFloat2 (pf, w->p[i][1]);
				WriteFloat2 (pf, w->p[i][2]);
				fprintf (pf,") ");
			}
			fprintf (pf,"\n");
		}
	}

}

void FillLeafNumbers_r (node_t *node, int num)
{
	if (node->planenum == PLANENUM_LEAF)
	{
		if (node->contents & CONTENTS_SOLID)
			node->cluster = -1;
		else
			node->cluster = num;
		return;
	}
	node->cluster = num;
	FillLeafNumbers_r (node->children[0], num);
	FillLeafNumbers_r (node->children[1], num);
}

void NumberLeafs_r (node_t *node)
{
	portal_t	*p;

	if (node->planenum != PLANENUM_LEAF && !node->detail_seperator)
	{	// decision node
		node->cluster = -99;
		NumberLeafs_r (node->children[0]);
		NumberLeafs_r (node->children[1]);
		return;
	}
	
	// either a leaf or a detail cluster

	if ( node->contents & CONTENTS_SOLID )
	{	// solid block, viewpoint never inside
		node->cluster = -1;
		return;
	}

	FillLeafNumbers_r (node, num_visclusters);
	num_visclusters++;

	// count the portals
	for (p = node->portals ; p ; )
	{
		if (p->nodes[0] == node)		// only write out from first leaf
		{
			if (Portal_VisFlood (p))
				num_visportals++;
			p = p->next[0];
		}
		else
			p = p->next[1];		
	}

}

void CreateVisPortals_r (node_t *node)
{
	// stop as soon as we get to a detail_seperator, which
	// means that everything below is in a single cluster
	if (node->planenum == PLANENUM_LEAF || node->detail_seperator )
		return;

	MakeNodePortal (node);
	SplitNodePortals (node);

	CreateVisPortals_r (node->children[0]);
	CreateVisPortals_r (node->children[1]);
}

void FinishVisPortals2_r (node_t *node)
{
	if (node->planenum == PLANENUM_LEAF)
		return;

	MakeNodePortal (node);
	SplitNodePortals (node);

	FinishVisPortals2_r (node->children[0]);
	FinishVisPortals2_r (node->children[1]);
}

void FinishVisPortals_r (node_t *node)
{
	if (node->planenum == PLANENUM_LEAF)
		return;

	if (node->detail_seperator)
	{
		FinishVisPortals2_r (node);
		return;
	}

	FinishVisPortals_r (node->children[0]);
	FinishVisPortals_r (node->children[1]);
}

void SaveClusters_r (node_t *node)
{
	if (node->planenum == PLANENUM_LEAF)
	{
		dleafs[clusterleaf++].cluster = node->cluster;
		return;
	}
	SaveClusters_r (node->children[0]);
	SaveClusters_r (node->children[1]);
}

void WritePortalFile (tree_t *tree)
{
	char	filename[1024];
	node_t *headnode;

	qprintf ("--- WritePortalFile ---\n");

	headnode = tree->headnode;
	num_visclusters = 0;
	num_visportals = 0;

	Tree_FreePortals_r (headnode);

	MakeHeadnodePortals (tree);

	CreateVisPortals_r (headnode);

// set the cluster field in every leaf and count the total number of portals

	NumberLeafs_r (headnode);
	
// write the file
	sprintf (filename, "%s.prt", source);
	printf ("writing %s\n", filename);
	pf = fopen (filename, "w");
	if (!pf)
		Error ("Error opening %s", filename);
		
	fprintf (pf, "%s\n", PORTALFILE);
	fprintf (pf, "%i\n", num_visclusters);
	fprintf (pf, "%i\n", num_visportals);

	qprintf ("%5i visclusters\n", num_visclusters);
	qprintf ("%5i visportals\n", num_visportals);

	WritePortalFile_r (headnode);

	fclose (pf);

	// we need to store the clusters out now because ordering
	// issues made us do this after writebsp...
	clusterleaf = 1;
	SaveClusters_r (headnode);
}

