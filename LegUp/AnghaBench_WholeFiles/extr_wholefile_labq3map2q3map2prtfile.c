#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_17__   TYPE_5__ ;
typedef  struct TYPE_16__   TYPE_4__ ;
typedef  struct TYPE_15__   TYPE_3__ ;
typedef  struct TYPE_14__   TYPE_2__ ;
typedef  struct TYPE_13__   TYPE_1__ ;

/* Type definitions */
struct TYPE_14__ {int numpoints; double** p; } ;
typedef  TYPE_2__ winding_t ;
typedef  double vec_t ;
typedef  int /*<<< orphan*/  vec3_t ;
struct TYPE_15__ {TYPE_5__* headnode; } ;
typedef  TYPE_3__ tree_t ;
struct TYPE_13__ {int /*<<< orphan*/  normal; } ;
struct TYPE_16__ {int compileFlags; struct TYPE_16__** next; TYPE_5__** nodes; TYPE_2__* winding; TYPE_1__ plane; } ;
typedef  TYPE_4__ portal_t ;
struct TYPE_17__ {scalar_t__ planenum; int cluster; int area; TYPE_4__* portals; scalar_t__ opaque; struct TYPE_17__** children; } ;
typedef  TYPE_5__ node_t ;
typedef  int /*<<< orphan*/  FILE ;

/* Variables and functions */
 int C_HINT ; 
 double DotProduct (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  Error (char*,char*) ; 
 scalar_t__ PLANENUM_LEAF ; 
 char* PORTALFILE ; 
 scalar_t__ PortalPassable (TYPE_4__*) ; 
 scalar_t__ Q_rint (double) ; 
 int /*<<< orphan*/  SYS_VRB ; 
 int /*<<< orphan*/  Sys_FPrintf (int /*<<< orphan*/ ,char*,...) ; 
 int /*<<< orphan*/  Sys_Printf (char*,char*) ; 
 int /*<<< orphan*/  WindingPlane (TYPE_2__*,int /*<<< orphan*/ ,double*) ; 
 double fabs (scalar_t__) ; 
 int /*<<< orphan*/  fclose (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/ * fopen (char*,char*) ; 
 int /*<<< orphan*/  fprintf (int /*<<< orphan*/ *,char*,...) ; 
 int num_solidfaces ; 
 int num_visclusters ; 
 int num_visportals ; 
 int /*<<< orphan*/ * pf ; 
 char* source ; 
 int /*<<< orphan*/  sprintf (char*,char*,char*) ; 

void WriteFloat( FILE *f, vec_t v ){
	if ( fabs( v - Q_rint( v ) ) < 0.001 ) {
		fprintf( f,"%i ",(int)Q_rint( v ) );
	}
	else{
		fprintf( f,"%f ",v );
	}
}

void WritePortalFile_r( node_t *node ){
	int i, s;
	portal_t    *p;
	winding_t   *w;
	vec3_t normal;
	vec_t dist;

	// decision node
	if ( node->planenum != PLANENUM_LEAF ) {
		WritePortalFile_r( node->children[0] );
		WritePortalFile_r( node->children[1] );
		return;
	}

	if ( node->opaque ) {
		return;
	}

	for ( p = node->portals ; p ; p = p->next[s] )
	{
		w = p->winding;
		s = ( p->nodes[1] == node );
		if ( w && p->nodes[0] == node ) {
			if ( !PortalPassable( p ) ) {
				continue;
			}
			// write out to the file

			// sometimes planes get turned around when they are very near
			// the changeover point between different axis.  interpret the
			// plane the same way vis will, and flip the side orders if needed
			// FIXME: is this still relevent?
			WindingPlane( w, normal, &dist );
			if ( DotProduct( p->plane.normal, normal ) < 0.99 ) { // backwards...
				fprintf( pf,"%i %i %i ",w->numpoints, p->nodes[1]->cluster, p->nodes[0]->cluster );
			}
			else{
				fprintf( pf,"%i %i %i ",w->numpoints, p->nodes[0]->cluster, p->nodes[1]->cluster );
			}

			/* ydnar: added this change to make antiportals work */
			if ( p->compileFlags & C_HINT ) {
				fprintf( pf, "1 " );
			}
			else{
				fprintf( pf, "0 " );
			}

			/* write the winding */
			for ( i = 0 ; i < w->numpoints ; i++ )
			{
				fprintf( pf,"(" );
				WriteFloat( pf, w->p[i][0] );
				WriteFloat( pf, w->p[i][1] );
				WriteFloat( pf, w->p[i][2] );
				fprintf( pf,") " );
			}
			fprintf( pf,"\n" );
		}
	}

}

void WriteFaceFile_r( node_t *node ){
	int i, s;
	portal_t    *p;
	winding_t   *w;

	// decision node
	if ( node->planenum != PLANENUM_LEAF ) {
		WriteFaceFile_r( node->children[0] );
		WriteFaceFile_r( node->children[1] );
		return;
	}

	if ( node->opaque ) {
		return;
	}

	for ( p = node->portals ; p ; p = p->next[s] )
	{
		w = p->winding;
		s = ( p->nodes[1] == node );
		if ( w ) {
			if ( PortalPassable( p ) ) {
				continue;
			}
			// write out to the file

			if ( p->nodes[0] == node ) {
				fprintf( pf,"%i %i ",w->numpoints, p->nodes[0]->cluster );
				for ( i = 0 ; i < w->numpoints ; i++ )
				{
					fprintf( pf,"(" );
					WriteFloat( pf, w->p[i][0] );
					WriteFloat( pf, w->p[i][1] );
					WriteFloat( pf, w->p[i][2] );
					fprintf( pf,") " );
				}
				fprintf( pf,"\n" );
			}
			else
			{
				fprintf( pf,"%i %i ",w->numpoints, p->nodes[1]->cluster );
				for ( i = w->numpoints - 1; i >= 0; i-- )
				{
					fprintf( pf,"(" );
					WriteFloat( pf, w->p[i][0] );
					WriteFloat( pf, w->p[i][1] );
					WriteFloat( pf, w->p[i][2] );
					fprintf( pf,") " );
				}
				fprintf( pf,"\n" );
			}
		}
	}
}

void NumberLeafs_r( node_t *node ){
	portal_t    *p;

	if ( node->planenum != PLANENUM_LEAF ) {
		// decision node
		node->cluster = -99;
		NumberLeafs_r( node->children[0] );
		NumberLeafs_r( node->children[1] );
		return;
	}

	node->area = -1;

	if ( node->opaque ) {
		// solid block, viewpoint never inside
		node->cluster = -1;
		return;
	}

	node->cluster = num_visclusters;
	num_visclusters++;

	// count the portals
	for ( p = node->portals ; p ; )
	{
		if ( p->nodes[0] == node ) {      // only write out from first leaf
			if ( PortalPassable( p ) ) {
				num_visportals++;
			}
			else{
				num_solidfaces++;
			}
			p = p->next[0];
		}
		else
		{
			if ( !PortalPassable( p ) ) {
				num_solidfaces++;
			}
			p = p->next[1];
		}
	}
}

void NumberClusters( tree_t *tree ) {
	num_visclusters = 0;
	num_visportals = 0;
	num_solidfaces = 0;

	Sys_FPrintf( SYS_VRB,"--- NumberClusters ---\n" );

	// set the cluster field in every leaf and count the total number of portals
	NumberLeafs_r( tree->headnode );

	Sys_FPrintf( SYS_VRB, "%9d visclusters\n", num_visclusters );
	Sys_FPrintf( SYS_VRB, "%9d visportals\n", num_visportals );
	Sys_FPrintf( SYS_VRB, "%9d solidfaces\n", num_solidfaces );
}

void WritePortalFile( tree_t *tree ){
	char filename[1024];

	Sys_FPrintf( SYS_VRB,"--- WritePortalFile ---\n" );

	// write the file
	sprintf( filename, "%s.prt", source );
	Sys_Printf( "writing %s\n", filename );
	pf = fopen( filename, "w" );
	if ( !pf ) {
		Error( "Error opening %s", filename );
	}

	fprintf( pf, "%s\n", PORTALFILE );
	fprintf( pf, "%i\n", num_visclusters );
	fprintf( pf, "%i\n", num_visportals );
	fprintf( pf, "%i\n", num_solidfaces );

	WritePortalFile_r( tree->headnode );
	WriteFaceFile_r( tree->headnode );

	fclose( pf );
}

