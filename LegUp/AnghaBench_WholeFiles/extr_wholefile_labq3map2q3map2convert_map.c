#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_45__   TYPE_9__ ;
typedef  struct TYPE_44__   TYPE_8__ ;
typedef  struct TYPE_43__   TYPE_7__ ;
typedef  struct TYPE_42__   TYPE_6__ ;
typedef  struct TYPE_41__   TYPE_5__ ;
typedef  struct TYPE_40__   TYPE_4__ ;
typedef  struct TYPE_39__   TYPE_3__ ;
typedef  struct TYPE_38__   TYPE_2__ ;
typedef  struct TYPE_37__   TYPE_25__ ;
typedef  struct TYPE_36__   TYPE_23__ ;
typedef  struct TYPE_35__   TYPE_1__ ;
typedef  struct TYPE_34__   TYPE_12__ ;
typedef  struct TYPE_33__   TYPE_11__ ;
typedef  struct TYPE_32__   TYPE_10__ ;

/* Type definitions */
typedef  double* vec3_t ;
struct TYPE_35__ {size_t planenum; TYPE_25__* winding; TYPE_23__* shaderInfo; } ;
typedef  TYPE_1__ side_t ;
struct TYPE_38__ {char* key; char* value; struct TYPE_38__* next; } ;
typedef  TYPE_2__ epair_t ;
struct TYPE_39__ {TYPE_2__* epairs; } ;
typedef  TYPE_3__ entity_t ;
struct TYPE_40__ {char* shader; } ;
typedef  TYPE_4__ bspShader_t ;
struct TYPE_41__ {int /*<<< orphan*/  dist; int /*<<< orphan*/  normal; } ;
typedef  TYPE_5__ bspPlane_t ;
struct TYPE_42__ {int numBSPBrushes; int firstBSPBrush; int numBSPSurfaces; int firstBSPSurface; } ;
typedef  TYPE_6__ bspModel_t ;
struct TYPE_43__ {double* xyz; double* st; } ;
typedef  TYPE_7__ bspDrawVert_t ;
struct TYPE_44__ {scalar_t__ surfaceType; size_t shaderNum; int patchWidth; int patchHeight; int firstVert; } ;
typedef  TYPE_8__ bspDrawSurface_t ;
struct TYPE_45__ {int numSides; int firstSide; } ;
typedef  TYPE_9__ bspBrush_t ;
struct TYPE_32__ {size_t shaderNum; size_t planeNum; } ;
typedef  TYPE_10__ bspBrushSide_t ;
struct TYPE_37__ {double** p; } ;
struct TYPE_36__ {char* shader; } ;
struct TYPE_34__ {int numsides; struct TYPE_34__* original; scalar_t__ entityNum; TYPE_1__* sides; } ;
struct TYPE_33__ {int /*<<< orphan*/ * hash_chain; int /*<<< orphan*/  normal; int /*<<< orphan*/  type; int /*<<< orphan*/  dist; } ;
typedef  int /*<<< orphan*/  FILE ;

/* Variables and functions */
 TYPE_12__* AllocBrush (int) ; 
 int /*<<< orphan*/  CreateBrushWindings (TYPE_12__*) ; 
 int /*<<< orphan*/  Error (char*,char*) ; 
 int /*<<< orphan*/  ExtractFileBase (char*,char*) ; 
 int /*<<< orphan*/  FreeWinding (TYPE_25__*) ; 
 int /*<<< orphan*/  GetVectorForKey (TYPE_3__*,char*,double*) ; 
 scalar_t__ MST_PATCH ; 
 int /*<<< orphan*/  PlaneTypeForNormal (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  Q_stricmp (char*,char*) ; 
 int /*<<< orphan*/  Q_strncasecmp (char*,char*,int) ; 
 TYPE_23__* ShaderInfoForShader (char*) ; 
 int /*<<< orphan*/  StripExtension (char*) ; 
 int /*<<< orphan*/  Sys_Printf (char*,...) ; 
 char* ValueForKey (TYPE_3__*,char*) ; 
 int /*<<< orphan*/  VectorAdd (double*,double*,double*) ; 
 int /*<<< orphan*/  VectorClear (double*) ; 
 int /*<<< orphan*/  VectorCopy (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int atoi (char const*) ; 
 TYPE_10__* bspBrushSides ; 
 TYPE_9__* bspBrushes ; 
 TYPE_8__* bspDrawSurfaces ; 
 TYPE_7__* bspDrawVerts ; 
 TYPE_6__* bspModels ; 
 TYPE_5__* bspPlanes ; 
 TYPE_4__* bspShaders ; 
 TYPE_12__* buildBrush ; 
 TYPE_3__* entities ; 
 int /*<<< orphan*/  fclose (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/ * fopen (char*,char*) ; 
 int /*<<< orphan*/  fprintf (int /*<<< orphan*/ *,char*,...) ; 
 int /*<<< orphan*/  free (TYPE_12__*) ; 
 TYPE_11__* mapplanes ; 
 int numBSPPlanes ; 
 size_t numBSPShaders ; 
 int numEntities ; 
 int nummapplanes ; 
 int /*<<< orphan*/  strcat (char*,char*) ; 
 int /*<<< orphan*/  strcpy (char*,char*) ; 

__attribute__((used)) static void ConvertBrush( FILE *f, int num, bspBrush_t *brush, vec3_t origin ){
	int i, j;
	bspBrushSide_t  *side;
	side_t          *buildSide;
	bspShader_t     *shader;
	char            *texture;
	bspPlane_t      *plane;
	vec3_t pts[ 3 ];


	/* start brush */
	fprintf( f, "\t// brush %d\n", num );
	fprintf( f, "\t{\n" );

	/* clear out build brush */
	for ( i = 0; i < buildBrush->numsides; i++ )
	{
		buildSide = &buildBrush->sides[ i ];
		if ( buildSide->winding != NULL ) {
			FreeWinding( buildSide->winding );
			buildSide->winding = NULL;
		}
	}
	buildBrush->numsides = 0;

	/* iterate through bsp brush sides */
	for ( i = 0; i < brush->numSides; i++ )
	{
		/* get side */
		side = &bspBrushSides[ brush->firstSide + i ];

		/* get shader */
		if ( side->shaderNum < 0 || side->shaderNum >= numBSPShaders ) {
			continue;
		}
		shader = &bspShaders[ side->shaderNum ];
		if ( !Q_stricmp( shader->shader, "default" ) || !Q_stricmp( shader->shader, "noshader" ) ) {
			continue;
		}

		/* get plane */
		plane = &bspPlanes[ side->planeNum ];

		/* add build side */
		buildSide = &buildBrush->sides[ buildBrush->numsides ];
		buildBrush->numsides++;

		/* tag it */
		buildSide->shaderInfo = ShaderInfoForShader( shader->shader );
		buildSide->planenum = side->planeNum;
		buildSide->winding = NULL;
	}

	/* make brush windings */
	if ( !CreateBrushWindings( buildBrush ) ) {
		return;
	}

	/* iterate through build brush sides */
	for ( i = 0; i < buildBrush->numsides; i++ )
	{
		/* get build side */
		buildSide = &buildBrush->sides[ i ];

		/* dummy check */
		if ( buildSide->shaderInfo == NULL || buildSide->winding == NULL ) {
			continue;
		}

		/* get texture name */
		if ( !Q_strncasecmp( buildSide->shaderInfo->shader, "textures/", 9 ) ) {
			texture = buildSide->shaderInfo->shader + 9;
		}
		else{
			texture = buildSide->shaderInfo->shader;
		}

		/* get plane points and offset by origin */
		for ( j = 0; j < 3; j++ )
		{
			VectorAdd( buildSide->winding->p[ j ], origin, pts[ j ] );
			//%	pts[ j ][ 0 ] = SNAP_INT_TO_FLOAT * floor( pts[ j ][ 0 ] * SNAP_FLOAT_TO_INT + 0.5f );
			//%	pts[ j ][ 1 ] = SNAP_INT_TO_FLOAT * floor( pts[ j ][ 1 ] * SNAP_FLOAT_TO_INT + 0.5f );
			//%	pts[ j ][ 2 ] = SNAP_INT_TO_FLOAT * floor( pts[ j ][ 2 ] * SNAP_FLOAT_TO_INT + 0.5f );
		}

		/* print brush side */
		/* ( 640 24 -224 ) ( 448 24 -224 ) ( 448 -232 -224 ) common/caulk 0 48 0 0.500000 0.500000 0 0 0 */
		fprintf( f, "\t\t( %.3f %.3f %.3f ) ( %.3f %.3f %.3f ) ( %.3f %.3f %.3f ) %s 0 0 0 0.5 0.5 0 0 0\n",
				 pts[ 0 ][ 0 ], pts[ 0 ][ 1 ], pts[ 0 ][ 2 ],
				 pts[ 1 ][ 0 ], pts[ 1 ][ 1 ], pts[ 1 ][ 2 ],
				 pts[ 2 ][ 0 ], pts[ 2 ][ 1 ], pts[ 2 ][ 2 ],
				 texture );
	}

	/* end brush */
	fprintf( f, "\t}\n\n" );
}

__attribute__((used)) static void ConvertPatch( FILE *f, int num, bspDrawSurface_t *ds, vec3_t origin ){
	int x, y;
	bspShader_t     *shader;
	char            *texture;
	bspDrawVert_t   *dv;
	vec3_t xyz;


	/* only patches */
	if ( ds->surfaceType != MST_PATCH ) {
		return;
	}

	/* get shader */
	if ( ds->shaderNum < 0 || ds->shaderNum >= numBSPShaders ) {
		return;
	}
	shader = &bspShaders[ ds->shaderNum ];

	/* get texture name */
	if ( !Q_strncasecmp( shader->shader, "textures/", 9 ) ) {
		texture = shader->shader + 9;
	}
	else{
		texture = shader->shader;
	}

	/* start patch */
	fprintf( f, "\t// patch %d\n", num );
	fprintf( f, "\t{\n" );
	fprintf( f, "\t\tpatchDef2\n" );
	fprintf( f, "\t\t{\n" );
	fprintf( f, "\t\t\t%s\n", texture );
	fprintf( f, "\t\t\t( %d %d 0 0 0 )\n", ds->patchWidth, ds->patchHeight );
	fprintf( f, "\t\t\t(\n" );

	/* iterate through the verts */
	for ( x = 0; x < ds->patchWidth; x++ )
	{
		/* start row */
		fprintf( f, "\t\t\t\t(" );

		/* iterate through the row */
		for ( y = 0; y < ds->patchHeight; y++ )
		{
			/* get vert */
			dv = &bspDrawVerts[ ds->firstVert + ( y * ds->patchWidth ) + x ];

			/* offset it */
			VectorAdd( origin, dv->xyz, xyz );

			/* print vertex */
			fprintf( f, " ( %f %f %f %f %f )", xyz[ 0 ], xyz[ 1 ], xyz[ 2 ], dv->st[ 0 ], dv->st[ 1 ] );
		}

		/* end row */
		fprintf( f, " )\n" );
	}

	/* end patch */
	fprintf( f, "\t\t\t)\n" );
	fprintf( f, "\t\t}\n" );
	fprintf( f, "\t}\n\n" );
}

__attribute__((used)) static void ConvertModel( FILE *f, bspModel_t *model, int modelNum, vec3_t origin ){
	int i, num;
	bspBrush_t          *brush;
	bspDrawSurface_t    *ds;


	/* convert bsp planes to map planes */
	nummapplanes = numBSPPlanes;
	for ( i = 0; i < numBSPPlanes; i++ )
	{
		VectorCopy( bspPlanes[ i ].normal, mapplanes[ i ].normal );
		mapplanes[ i ].dist = bspPlanes[ i ].dist;
		mapplanes[ i ].type = PlaneTypeForNormal( mapplanes[ i ].normal );
		mapplanes[ i ].hash_chain = NULL;
	}

	/* allocate a build brush */
	buildBrush = AllocBrush( 512 );
	buildBrush->entityNum = 0;
	buildBrush->original = buildBrush;

	/* go through each brush in the model */
	for ( i = 0; i < model->numBSPBrushes; i++ )
	{
		num = i + model->firstBSPBrush;
		brush = &bspBrushes[ num ];
		ConvertBrush( f, num, brush, origin );
	}

	/* free the build brush */
	free( buildBrush );

	/* go through each drawsurf in the model */
	for ( i = 0; i < model->numBSPSurfaces; i++ )
	{
		num = i + model->firstBSPSurface;
		ds = &bspDrawSurfaces[ num ];

		/* we only love patches */
		if ( ds->surfaceType == MST_PATCH ) {
			ConvertPatch( f, num, ds, origin );
		}
	}
}

__attribute__((used)) static void ConvertEPairs( FILE *f, entity_t *e ){
	epair_t *ep;


	/* walk epairs */
	for ( ep = e->epairs; ep != NULL; ep = ep->next )
	{
		/* ignore empty keys/values */
		if ( ep->key[ 0 ] == '\0' || ep->value[ 0 ] == '\0' ) {
			continue;
		}

		/* ignore model keys with * prefixed values */
		if ( !Q_stricmp( ep->key, "model" ) && ep->value[ 0 ] == '*' ) {
			continue;
		}

		/* emit the epair */
		fprintf( f, "\t\"%s\" \"%s\"\n", ep->key, ep->value );
	}
}

int ConvertBSPToMap( char *bspName ){
	int i, modelNum;
	FILE            *f;
	bspModel_t      *model;
	entity_t        *e;
	vec3_t origin;
	const char      *value;
	char name[ 1024 ], base[ 1024 ];


	/* note it */
	Sys_Printf( "--- Convert BSP to MAP ---\n" );

	/* create the bsp filename from the bsp name */
	strcpy( name, bspName );
	StripExtension( name );
	strcat( name, "_converted.map" );
	Sys_Printf( "writing %s\n", name );

	ExtractFileBase( bspName, base );
	strcat( base, ".bsp" );

	/* open it */
	f = fopen( name, "wb" );
	if ( f == NULL ) {
		Error( "Open failed on %s\n", name );
	}

	/* print header */
	fprintf( f, "// Generated by Q3Map2 (ydnar) -convert -format map\n" );

	/* walk entity list */
	for ( i = 0; i < numEntities; i++ )
	{
		/* get entity */
		e = &entities[ i ];

		/* start entity */
		fprintf( f, "// entity %d\n", i );
		fprintf( f, "{\n" );

		/* export keys */
		ConvertEPairs( f, e );
		fprintf( f, "\n" );

		/* get model num */
		if ( i == 0 ) {
			modelNum = 0;
		}
		else
		{
			value = ValueForKey( e, "model" );
			if ( value[ 0 ] == '*' ) {
				modelNum = atoi( value + 1 );
			}
			else{
				modelNum = -1;
			}
		}

		/* only handle bsp models */
		if ( modelNum >= 0 ) {
			/* get model */
			model = &bspModels[ modelNum ];

			/* get entity origin */
			value = ValueForKey( e, "origin" );
			if ( value[ 0 ] == '\0' ) {
				VectorClear( origin );
			}
			else{
				GetVectorForKey( e, "origin", origin );
			}

			/* convert model */
			ConvertModel( f, model, modelNum, origin );
		}

		/* end entity */
		fprintf( f, "}\n\n" );
	}

	/* close the file and return */
	fclose( f );

	/* return to sender */
	return 0;
}

