#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_70__   TYPE_9__ ;
typedef  struct TYPE_69__   TYPE_8__ ;
typedef  struct TYPE_68__   TYPE_7__ ;
typedef  struct TYPE_67__   TYPE_6__ ;
typedef  struct TYPE_66__   TYPE_5__ ;
typedef  struct TYPE_65__   TYPE_4__ ;
typedef  struct TYPE_64__   TYPE_3__ ;
typedef  struct TYPE_63__   TYPE_33__ ;
typedef  struct TYPE_62__   TYPE_2__ ;
typedef  struct TYPE_61__   TYPE_28__ ;
typedef  struct TYPE_60__   TYPE_25__ ;
typedef  struct TYPE_59__   TYPE_23__ ;
typedef  struct TYPE_58__   TYPE_22__ ;
typedef  struct TYPE_57__   TYPE_21__ ;
typedef  struct TYPE_56__   TYPE_20__ ;
typedef  struct TYPE_55__   TYPE_1__ ;
typedef  struct TYPE_54__   TYPE_19__ ;
typedef  struct TYPE_53__   TYPE_18__ ;
typedef  struct TYPE_52__   TYPE_17__ ;
typedef  struct TYPE_51__   TYPE_16__ ;
typedef  struct TYPE_50__   TYPE_15__ ;
typedef  struct TYPE_49__   TYPE_14__ ;
typedef  struct TYPE_48__   TYPE_13__ ;
typedef  struct TYPE_47__   TYPE_12__ ;
typedef  struct TYPE_46__   TYPE_11__ ;
typedef  struct TYPE_45__   TYPE_10__ ;

/* Type definitions */
typedef  int* vec3_t ;
struct TYPE_45__ {int surfaceFlags; int contentFlags; char* damageShader; int /*<<< orphan*/  shader; } ;
typedef  TYPE_10__ shaderInfo_t ;
typedef  scalar_t__ qboolean ;
struct TYPE_46__ {int* normal; int /*<<< orphan*/  dist; } ;
typedef  TYPE_11__ plane_t ;
struct TYPE_70__ {int width; int height; TYPE_8__* verts; } ;
struct TYPE_47__ {TYPE_9__ mesh; struct TYPE_47__* next; } ;
typedef  TYPE_12__ parseMesh_t ;
struct TYPE_48__ {int* mins; int* maxs; scalar_t__ planenum; struct TYPE_48__** children; TYPE_16__* drawSurfReferences; scalar_t__ opaque; TYPE_23__* brushlist; int /*<<< orphan*/  area; int /*<<< orphan*/  cluster; } ;
typedef  TYPE_13__ node_t ;
struct TYPE_49__ {struct TYPE_49__* value; struct TYPE_49__* key; struct TYPE_49__* next; } ;
typedef  TYPE_14__ epair_t ;
struct TYPE_50__ {size_t firstBrush; int /*<<< orphan*/  numBrushes; TYPE_12__* patches; TYPE_23__* brushes; TYPE_14__* epairs; } ;
typedef  TYPE_15__ entity_t ;
struct TYPE_51__ {int /*<<< orphan*/  outputNum; struct TYPE_51__* nextRef; } ;
typedef  TYPE_16__ drawSurfRef_t ;
struct TYPE_52__ {int /*<<< orphan*/  dist; int /*<<< orphan*/  normal; } ;
typedef  TYPE_17__ bspPlane_t ;
struct TYPE_53__ {int planeNum; size_t* children; int /*<<< orphan*/  maxs; int /*<<< orphan*/  mins; } ;
typedef  TYPE_18__ bspNode_t ;
struct TYPE_54__ {void* firstBSPSurface; size_t firstBSPBrush; int /*<<< orphan*/  numBSPBrushes; void* numBSPSurfaces; int /*<<< orphan*/  maxs; int /*<<< orphan*/  mins; } ;
typedef  TYPE_19__ bspModel_t ;
struct TYPE_56__ {size_t firstBSPLeafBrush; size_t numBSPLeafBrushes; size_t firstBSPLeafSurface; size_t numBSPLeafSurfaces; int /*<<< orphan*/  maxs; int /*<<< orphan*/  mins; int /*<<< orphan*/  area; int /*<<< orphan*/  cluster; } ;
typedef  TYPE_20__ bspLeaf_t ;
struct TYPE_57__ {int shaderNum; size_t firstSide; scalar_t__ numSides; } ;
typedef  TYPE_21__ bspBrush_t ;
struct TYPE_58__ {int shaderNum; int /*<<< orphan*/  planeNum; } ;
typedef  TYPE_22__ bspBrushSide_t ;
struct TYPE_59__ {size_t outputNum; int numsides; int compileFlags; int /*<<< orphan*/  maxs; int /*<<< orphan*/  mins; struct TYPE_59__* next; TYPE_4__* sides; TYPE_2__* contentShader; TYPE_1__* original; } ;
typedef  TYPE_23__ brush_t ;
struct TYPE_69__ {int /*<<< orphan*/  xyz; } ;
struct TYPE_68__ {int outputNum; TYPE_6__* sides; } ;
struct TYPE_67__ {int /*<<< orphan*/ * visibleHull; } ;
struct TYPE_66__ {char const* shader; } ;
struct TYPE_65__ {int outputNum; TYPE_3__* shaderInfo; int /*<<< orphan*/  planenum; } ;
struct TYPE_64__ {char* shader; int contentFlags; int surfaceFlags; } ;
struct TYPE_63__ {char* shader; int brushNum; int visibleSide; } ;
struct TYPE_62__ {char* shader; int contentFlags; int surfaceFlags; } ;
struct TYPE_61__ {int surfaceFlags; int contentFlags; char* shader; } ;
struct TYPE_60__ {int visibleSide; TYPE_7__* brush; TYPE_5__* si; } ;
struct TYPE_55__ {int /*<<< orphan*/  outputNum; } ;

/* Variables and functions */
 int /*<<< orphan*/  AddPointToBounds (int /*<<< orphan*/ ,int*,int*) ; 
 int C_LIGHTGRID ; 
 int /*<<< orphan*/  ClearBounds (int*,int*) ; 
 int /*<<< orphan*/  Error (char*,...) ; 
 int IntForKey (TYPE_15__*,char*) ; 
 int LS_NONE ; 
 int LS_NORMAL ; 
 size_t MAX_MAP_BRUSHES ; 
 size_t MAX_MAP_BRUSHSIDES ; 
 size_t MAX_MAP_LEAFBRUSHES ; 
 size_t MAX_MAP_LEAFFACES ; 
 size_t MAX_MAP_LEAFS ; 
 size_t MAX_MAP_MODELS ; 
 size_t MAX_MAP_NODES ; 
 int MAX_MAP_SHADERS ; 
 int MAX_SWITCHED_LIGHTS ; 
 scalar_t__ PLANENUM_LEAF ; 
 int /*<<< orphan*/  Q_stricmp (char const*,char*) ; 
 scalar_t__ Q_strncasecmp (char const*,char*,int) ; 
 int /*<<< orphan*/  SYS_VRB ; 
 int /*<<< orphan*/  SYS_WRN ; 
 int /*<<< orphan*/  SetKeyValue (TYPE_15__*,char*,char*) ; 
 TYPE_10__* ShaderInfoForShader (char const*) ; 
 int /*<<< orphan*/  Sys_FPrintf (int /*<<< orphan*/ ,char*,...) ; 
 int /*<<< orphan*/  Sys_Printf (char*,...) ; 
 int /*<<< orphan*/  UnparseEntities () ; 
 char* ValueForKey (TYPE_15__*,char*) ; 
 int /*<<< orphan*/  VectorCopy (int*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  WriteBSPFile (char*) ; 
 int /*<<< orphan*/  WriteSurfaceExtraFile (char*) ; 
 TYPE_22__* bspBrushSides ; 
 TYPE_21__* bspBrushes ; 
 int* bspDrawIndexes ; 
 TYPE_33__* bspFogs ; 
 int /*<<< orphan*/ * bspLeafBrushes ; 
 int /*<<< orphan*/ * bspLeafSurfaces ; 
 TYPE_20__* bspLeafs ; 
 TYPE_19__* bspModels ; 
 TYPE_18__* bspNodes ; 
 TYPE_17__* bspPlanes ; 
 TYPE_28__* bspShaders ; 
 TYPE_15__* entities ; 
 int /*<<< orphan*/  free (TYPE_14__*) ; 
 size_t mapEntityNum ; 
 TYPE_25__* mapFogs ; 
 TYPE_11__* mapplanes ; 
 size_t numBSPBrushSides ; 
 size_t numBSPBrushes ; 
 int numBSPDrawIndexes ; 
 void* numBSPDrawSurfaces ; 
 int numBSPEntities ; 
 int numBSPFogs ; 
 size_t numBSPLeafBrushes ; 
 size_t numBSPLeafSurfaces ; 
 size_t numBSPLeafs ; 
 size_t numBSPModels ; 
 size_t numBSPNodes ; 
 size_t numBSPPlanes ; 
 int numBSPShaders ; 
 int numEntities ; 
 int numMapFogs ; 
 int /*<<< orphan*/  numStrippedLights ; 
 int nummapplanes ; 
 scalar_t__ qfalse ; 
 scalar_t__ qtrue ; 
 char* source ; 
 int /*<<< orphan*/  sprintf (char*,char*,...) ; 
 int /*<<< orphan*/  strcmp (char*,char const*) ; 
 int /*<<< orphan*/  strcpy (char*,char const*) ; 

int EmitShader( const char *shader, int *contentFlags, int *surfaceFlags ){
	int i;
	shaderInfo_t    *si;


	/* handle special cases */
	if ( shader == NULL ) {
		shader = "noshader";
	}

	/* try to find an existing shader */
	for ( i = 0; i < numBSPShaders; i++ )
	{
		/* ydnar: handle custom surface/content flags */
		if ( surfaceFlags != NULL && bspShaders[ i ].surfaceFlags != *surfaceFlags ) {
			continue;
		}
		if ( contentFlags != NULL && bspShaders[ i ].contentFlags != *contentFlags ) {
			continue;
		}

		/* compare name */
		if ( !Q_stricmp( shader, bspShaders[ i ].shader ) ) {
			return i;
		}
	}

	/* get shaderinfo */
	si = ShaderInfoForShader( shader );

	/* emit a new shader */
	if ( i == MAX_MAP_SHADERS ) {
		Error( "MAX_MAP_SHADERS" );
	}
	numBSPShaders++;
	strcpy( bspShaders[ i ].shader, shader );
	bspShaders[ i ].surfaceFlags = si->surfaceFlags;
	bspShaders[ i ].contentFlags = si->contentFlags;

	/* handle custom content/surface flags */
	if ( surfaceFlags != NULL ) {
		bspShaders[ i ].surfaceFlags = *surfaceFlags;
	}
	if ( contentFlags != NULL ) {
		bspShaders[ i ].contentFlags = *contentFlags;
	}

	/* recursively emit any damage shaders */
	if ( si->damageShader != NULL && si->damageShader[ 0 ] != '\0' ) {
		Sys_FPrintf( SYS_VRB, "Shader %s has damage shader %s\n", si->shader, si->damageShader );
		EmitShader( si->damageShader, NULL, NULL );
	}

	/* return it */
	return i;
}

void EmitPlanes( void ){
	int i;
	bspPlane_t  *bp;
	plane_t     *mp;


	/* walk plane list */
	mp = mapplanes;
	for ( i = 0; i < nummapplanes; i++, mp++ )
	{
		bp = &bspPlanes[ numBSPPlanes ];
		VectorCopy( mp->normal, bp->normal );
		bp->dist = mp->dist;
		numBSPPlanes++;
	}

	/* emit some statistics */
	Sys_FPrintf( SYS_VRB, "%9d BSP planes\n", numBSPPlanes );
}

void EmitLeaf( node_t *node ){
	bspLeaf_t       *leaf_p;
	brush_t         *b;
	drawSurfRef_t   *dsr;


	/* check limits */
	if ( numBSPLeafs >= MAX_MAP_LEAFS ) {
		Error( "MAX_MAP_LEAFS" );
	}

	leaf_p = &bspLeafs[numBSPLeafs];
	numBSPLeafs++;

	leaf_p->cluster = node->cluster;
	leaf_p->area = node->area;

	/* emit bounding box */
	VectorCopy( node->mins, leaf_p->mins );
	VectorCopy( node->maxs, leaf_p->maxs );

	/* emit leaf brushes */
	leaf_p->firstBSPLeafBrush = numBSPLeafBrushes;
	for ( b = node->brushlist; b; b = b->next )
	{
		/* something is corrupting brushes */
		if ( (size_t) b < 256 ) {
			Sys_FPrintf( SYS_WRN, "WARNING: Node brush list corrupted (0x%08X)\n", b );
			break;
		}
		//%	if( b->guard != 0xDEADBEEF )
		//%		Sys_Printf( "Brush %6d: 0x%08X Guard: 0x%08X Next: 0x%08X Original: 0x%08X Sides: %d\n", b->brushNum, b, b, b->next, b->original, b->numsides );

		if ( numBSPLeafBrushes >= MAX_MAP_LEAFBRUSHES ) {
			Error( "MAX_MAP_LEAFBRUSHES" );
		}
		bspLeafBrushes[ numBSPLeafBrushes ] = b->original->outputNum;
		numBSPLeafBrushes++;
	}

	leaf_p->numBSPLeafBrushes = numBSPLeafBrushes - leaf_p->firstBSPLeafBrush;

	/* emit leaf surfaces */
	if ( node->opaque ) {
		return;
	}

	/* add the drawSurfRef_t drawsurfs */
	leaf_p->firstBSPLeafSurface = numBSPLeafSurfaces;
	for ( dsr = node->drawSurfReferences; dsr; dsr = dsr->nextRef )
	{
		if ( numBSPLeafSurfaces >= MAX_MAP_LEAFFACES ) {
			Error( "MAX_MAP_LEAFFACES" );
		}
		bspLeafSurfaces[ numBSPLeafSurfaces ] = dsr->outputNum;
		numBSPLeafSurfaces++;
	}

	leaf_p->numBSPLeafSurfaces = numBSPLeafSurfaces - leaf_p->firstBSPLeafSurface;
}

int EmitDrawNode_r( node_t *node ){
	bspNode_t   *n;
	int i;


	/* check for leafnode */
	if ( node->planenum == PLANENUM_LEAF ) {
		EmitLeaf( node );
		return -numBSPLeafs;
	}

	/* emit a node */
	if ( numBSPNodes == MAX_MAP_NODES ) {
		Error( "MAX_MAP_NODES" );
	}
	n = &bspNodes[ numBSPNodes ];
	numBSPNodes++;

	VectorCopy( node->mins, n->mins );
	VectorCopy( node->maxs, n->maxs );

	if ( node->planenum & 1 ) {
		Error( "WriteDrawNodes_r: odd planenum" );
	}
	n->planeNum = node->planenum;

	//
	// recursively output the other nodes
	//
	for ( i = 0 ; i < 2 ; i++ )
	{
		if ( node->children[i]->planenum == PLANENUM_LEAF ) {
			n->children[i] = -( numBSPLeafs + 1 );
			EmitLeaf( node->children[i] );
		}
		else
		{
			n->children[i] = numBSPNodes;
			EmitDrawNode_r( node->children[i] );
		}
	}

	return n - bspNodes;
}

void SetModelNumbers( void ){
	int i;
	int models;
	char value[10];

	models = 1;
	for ( i = 1 ; i < numEntities ; i++ ) {
		if ( entities[i].brushes || entities[i].patches ) {
			sprintf( value, "*%i", models );
			models++;
			SetKeyValue( &entities[i], "model", value );
		}
	}

}

void SetLightStyles( void ){
	int i, j, style, numStyles;
	qboolean keepLights;
	qboolean noRadiosityLight;
	const char  *t;
	entity_t    *e;
	epair_t     *ep, *next;
	char value[ 10 ];
	char lightTargets[ MAX_SWITCHED_LIGHTS ][ 64 ];
	int lightStyles[ MAX_SWITCHED_LIGHTS ];


	/* ydnar: determine if we keep lights in the bsp */
	t = ValueForKey( &entities[ 0 ], "_keepLights" );
	keepLights = ( t[ 0 ] == '1' ) ? qtrue : qfalse;

	/* any light that is controlled (has a targetname) must have a unique style number generated for it */
	numStyles = 0;
	for ( i = 1; i < numEntities; i++ )
	{
		e = &entities[ i ];

		t = ValueForKey( e, "classname" );
		if ( Q_strncasecmp( t, "light", 5 ) ) {
			continue;
		}
		t = ValueForKey( e, "noradiosity" );
		noRadiosityLight = ( t[ 0 ] == '1' ) ? qtrue : qfalse;
		t = ValueForKey( e, "targetname" );
		if ( t[ 0 ] == '\0' ) {
			/* ydnar: strip the light from the BSP file */
			/* neumond: pass all dynamic lights to BSP regardless of keepLights.
				pass all lights (radiosity+dynamic) to BSP if keepLights */
			if ( keepLights == qfalse && noRadiosityLight == qfalse ) {
				ep = e->epairs;
				while ( ep != NULL )
				{
					next = ep->next;
					free( ep->key );
					free( ep->value );
					free( ep );
					ep = next;
				}
				e->epairs = NULL;
				numStrippedLights++;
			}

			/* next light */
			continue;
		}

		/* get existing style */
		style = IntForKey( e, "style" );
		if ( style < LS_NORMAL || style > LS_NONE ) {
			Error( "Invalid lightstyle (%d) on entity %d", style, i );
		}

		/* find this targetname */
		for ( j = 0; j < numStyles; j++ )
			if ( lightStyles[ j ] == style && !strcmp( lightTargets[ j ], t ) ) {
				break;
			}

		/* add a new style */
		if ( j >= numStyles ) {
			if ( numStyles == MAX_SWITCHED_LIGHTS ) {
				Error( "MAX_SWITCHED_LIGHTS (%d) exceeded, reduce the number of lights with targetnames", MAX_SWITCHED_LIGHTS );
			}
			strcpy( lightTargets[ j ], t );
			lightStyles[ j ] = style;
			numStyles++;
		}

		/* set explicit style */
		sprintf( value, "%d", 32 + j );
		SetKeyValue( e, "style", value );

		/* set old style */
		if ( style != LS_NORMAL ) {
			sprintf( value, "%d", style );
			SetKeyValue( e, "switch_style", value );
		}
	}

	/* emit some statistics */
	Sys_FPrintf( SYS_VRB, "%9d light entities stripped\n", numStrippedLights );
}

void BeginBSPFile( void ){
	/* these values may actually be initialized if the file existed when loaded, so clear them explicitly */
	numBSPModels = 0;
	numBSPNodes = 0;
	numBSPBrushSides = 0;
	numBSPLeafSurfaces = 0;
	numBSPLeafBrushes = 0;

	/* leave leaf 0 as an error, because leafs are referenced as negative number nodes */
	numBSPLeafs = 1;


	/* ydnar: gs mods: set the first 6 drawindexes to 0 1 2 2 1 3 for triangles and quads */
	numBSPDrawIndexes = 6;
	bspDrawIndexes[ 0 ] = 0;
	bspDrawIndexes[ 1 ] = 1;
	bspDrawIndexes[ 2 ] = 2;
	bspDrawIndexes[ 3 ] = 0;
	bspDrawIndexes[ 4 ] = 2;
	bspDrawIndexes[ 5 ] = 3;
}

void EndBSPFile( void ){
	char path[ 1024 ];


	Sys_FPrintf( SYS_VRB, "--- EndBSPFile ---\n" );

	EmitPlanes();

	numBSPEntities = numEntities;
	UnparseEntities();

	/* write the surface extra file */
	WriteSurfaceExtraFile( source );

	/* write the bsp */
	sprintf( path, "%s.bsp", source );
	Sys_Printf( "Writing %s\n", path );
	WriteBSPFile( path );
}

void EmitBrushes( brush_t *brushes, int *firstBrush, int *numBrushes ){
	int j;
	brush_t         *b;
	bspBrush_t      *db;
	bspBrushSide_t  *cp;


	/* set initial brush */
	if ( firstBrush != NULL ) {
		*firstBrush = numBSPBrushes;
	}
	if ( numBrushes != NULL ) {
		*numBrushes = 0;
	}

	/* walk list of brushes */
	for ( b = brushes; b != NULL; b = b->next )
	{
		/* check limits */
		if ( numBSPBrushes == MAX_MAP_BRUSHES ) {
			Error( "MAX_MAP_BRUSHES (%d)", numBSPBrushes );
		}

		/* get bsp brush */
		b->outputNum = numBSPBrushes;
		db = &bspBrushes[ numBSPBrushes ];
		numBSPBrushes++;
		if ( numBrushes != NULL ) {
			( *numBrushes )++;
		}

		db->shaderNum = EmitShader( b->contentShader->shader, &b->contentShader->contentFlags, &b->contentShader->surfaceFlags );
		db->firstSide = numBSPBrushSides;

		/* walk sides */
		db->numSides = 0;
		for ( j = 0; j < b->numsides; j++ )
		{
			/* set output number to bogus initially */
			b->sides[ j ].outputNum = -1;

			/* check count */
			if ( numBSPBrushSides == MAX_MAP_BRUSHSIDES ) {
				Error( "MAX_MAP_BRUSHSIDES " );
			}

			/* emit side */
			b->sides[ j ].outputNum = numBSPBrushSides;
			cp = &bspBrushSides[ numBSPBrushSides ];
			db->numSides++;
			numBSPBrushSides++;
			cp->planeNum = b->sides[ j ].planenum;

			/* emit shader */
			if ( b->sides[ j ].shaderInfo ) {
				cp->shaderNum = EmitShader( b->sides[ j ].shaderInfo->shader, &b->sides[ j ].shaderInfo->contentFlags, &b->sides[ j ].shaderInfo->surfaceFlags );
			}
			else{
				cp->shaderNum = EmitShader( NULL, NULL, NULL );
			}
		}
	}
}

void EmitFogs( void ){
	int i, j;


	/* setup */
	numBSPFogs = numMapFogs;

	/* walk list */
	for ( i = 0; i < numMapFogs; i++ )
	{
		/* set shader */
		strcpy( bspFogs[ i ].shader, mapFogs[ i ].si->shader );

		/* global fog doesn't have an associated brush */
		if ( mapFogs[ i ].brush == NULL ) {
			bspFogs[ i ].brushNum = -1;
			bspFogs[ i ].visibleSide = -1;
		}
		else
		{
			/* set brush */
			bspFogs[ i ].brushNum = mapFogs[ i ].brush->outputNum;

			/* try to use forced visible side */
			if ( mapFogs[ i ].visibleSide >= 0 ) {
				bspFogs[ i ].visibleSide = mapFogs[ i ].visibleSide;
				continue;
			}

			/* find visible side */
			for ( j = 0; j < 6; j++ )
			{
				if ( mapFogs[ i ].brush->sides[ j ].visibleHull != NULL ) {
					Sys_Printf( "Fog %d has visible side %d\n", i, j );
					bspFogs[ i ].visibleSide = j;
					break;
				}
			}
		}
	}
}

void BeginModel( void ){
	bspModel_t  *mod;
	brush_t     *b;
	entity_t    *e;
	vec3_t mins, maxs;
	vec3_t lgMins, lgMaxs;          /* ydnar: lightgrid mins/maxs */
	parseMesh_t *p;
	int i;


	/* test limits */
	if ( numBSPModels == MAX_MAP_MODELS ) {
		Error( "MAX_MAP_MODELS" );
	}

	/* get model and entity */
	mod = &bspModels[ numBSPModels ];
	e = &entities[ mapEntityNum ];

	/* ydnar: lightgrid mins/maxs */
	ClearBounds( lgMins, lgMaxs );

	/* bound the brushes */
	ClearBounds( mins, maxs );
	for ( b = e->brushes; b; b = b->next )
	{
		/* ignore non-real brushes (origin, etc) */
		if ( b->numsides == 0 ) {
			continue;
		}
		AddPointToBounds( b->mins, mins, maxs );
		AddPointToBounds( b->maxs, mins, maxs );

		/* ydnar: lightgrid bounds */
		if ( b->compileFlags & C_LIGHTGRID ) {
			AddPointToBounds( b->mins, lgMins, lgMaxs );
			AddPointToBounds( b->maxs, lgMins, lgMaxs );
		}
	}

	/* bound patches */
	for ( p = e->patches; p; p = p->next )
	{
		for ( i = 0; i < ( p->mesh.width * p->mesh.height ); i++ )
			AddPointToBounds( p->mesh.verts[i].xyz, mins, maxs );
	}

	/* ydnar: lightgrid mins/maxs */
	if ( lgMins[ 0 ] < 99999 ) {
		/* use lightgrid bounds */
		VectorCopy( lgMins, mod->mins );
		VectorCopy( lgMaxs, mod->maxs );
	}
	else
	{
		/* use brush/patch bounds */
		VectorCopy( mins, mod->mins );
		VectorCopy( maxs, mod->maxs );
	}

	/* note size */
	Sys_FPrintf( SYS_VRB, "BSP bounds: { %f %f %f } { %f %f %f }\n", mins[ 0 ], mins[ 1 ], mins[ 2 ], maxs[ 0 ], maxs[ 1 ], maxs[ 2 ] );
	Sys_FPrintf( SYS_VRB, "Lightgrid bounds: { %f %f %f } { %f %f %f }\n", lgMins[ 0 ], lgMins[ 1 ], lgMins[ 2 ], lgMaxs[ 0 ], lgMaxs[ 1 ], lgMaxs[ 2 ] );

	/* set firsts */
	mod->firstBSPSurface = numBSPDrawSurfaces;
	mod->firstBSPBrush = numBSPBrushes;
}

void EndModel( entity_t *e, node_t *headnode ){
	bspModel_t  *mod;


	/* note it */
	Sys_FPrintf( SYS_VRB, "--- EndModel ---\n" );

	/* emit the bsp */
	mod = &bspModels[ numBSPModels ];
	EmitDrawNode_r( headnode );

	/* set surfaces and brushes */
	mod->numBSPSurfaces = numBSPDrawSurfaces - mod->firstBSPSurface;
	mod->firstBSPBrush = e->firstBrush;
	mod->numBSPBrushes = e->numBrushes;

	/* increment model count */
	numBSPModels++;
}

