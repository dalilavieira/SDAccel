#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_33__   TYPE_8__ ;
typedef  struct TYPE_32__   TYPE_4__ ;
typedef  struct TYPE_31__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  picoMemStream_t ;
struct TYPE_32__ {int /*<<< orphan*/  offset; } ;
struct TYPE_33__ {int /*<<< orphan*/  offset; } ;
struct TYPE_31__ {int nlayers; struct TYPE_31__* next; struct TYPE_31__* vmap; TYPE_4__ polygon; TYPE_8__ point; int /*<<< orphan*/  nsurfs; struct TYPE_31__* surf; int /*<<< orphan*/  taglist; void** bbox; struct TYPE_31__* layer; int /*<<< orphan*/  nclips; struct TYPE_31__* clip; int /*<<< orphan*/  nenvs; struct TYPE_31__* env; int /*<<< orphan*/  nvmaps; void* parent; struct TYPE_31__* name; void** pivot; void* flags; void* index; } ;
typedef  TYPE_1__ lwObject ;
typedef  TYPE_1__ lwNode ;
typedef  TYPE_1__ lwLayer ;
typedef  int /*<<< orphan*/  ListFreeFunc ;

/* Variables and functions */
#define  ID_BBOX 141 
#define  ID_CLIP 140 
#define  ID_DESC 139 
#define  ID_ENVL 138 
 unsigned int ID_FORM ; 
#define  ID_ICON 137 
#define  ID_LAYR 136 
 unsigned int ID_LWO2 ; 
 unsigned int ID_LWOB ; 
#define  ID_PNTS 135 
#define  ID_POLS 134 
#define  ID_PTAG 133 
#define  ID_SURF 132 
#define  ID_TAGS 131 
#define  ID_TEXT 130 
#define  ID_VMAD 129 
#define  ID_VMAP 128 
 int PICO_PMV_ERROR_IDENT ; 
 int PICO_PMV_ERROR_MEMORY ; 
 int PICO_PMV_ERROR_SIZE ; 
 int PICO_PMV_OK ; 
 int /*<<< orphan*/  PICO_SEEK_CUR ; 
 TYPE_1__* _pico_calloc (int,int) ; 
 int /*<<< orphan*/  _pico_free (TYPE_1__*) ; 
 int /*<<< orphan*/  _pico_memstream_seek (int /*<<< orphan*/ *,unsigned int,int /*<<< orphan*/ ) ; 
 int _pico_memstream_tell (int /*<<< orphan*/ *) ; 
 void* getF4 (int /*<<< orphan*/ *) ; 
 TYPE_1__* getS0 (int /*<<< orphan*/ *) ; 
 void* getU2 (int /*<<< orphan*/ *) ; 
 unsigned int getU4 (int /*<<< orphan*/ *) ; 
 int get_flen () ; 
 scalar_t__ lwFreeClip ; 
 scalar_t__ lwFreeEnvelope ; 
 int /*<<< orphan*/  lwFreePoints (TYPE_8__*) ; 
 int /*<<< orphan*/  lwFreePolygons (TYPE_4__*) ; 
 scalar_t__ lwFreeSurface ; 
 int /*<<< orphan*/  lwFreeTags (int /*<<< orphan*/ *) ; 
 scalar_t__ lwFreeVMap ; 
 int /*<<< orphan*/  lwGetBoundingBox (TYPE_8__*,void**) ; 
 scalar_t__ lwGetClip (int /*<<< orphan*/ *,unsigned int) ; 
 scalar_t__ lwGetEnvelope (int /*<<< orphan*/ *,unsigned int) ; 
 TYPE_1__* lwGetObject5 (char*,int /*<<< orphan*/ *,unsigned int*,int*) ; 
 int /*<<< orphan*/  lwGetPointPolygons (TYPE_8__*,TYPE_4__*) ; 
 int /*<<< orphan*/  lwGetPointVMaps (TYPE_8__*,TYPE_1__*) ; 
 int /*<<< orphan*/  lwGetPoints (int /*<<< orphan*/ *,unsigned int,TYPE_8__*) ; 
 int /*<<< orphan*/  lwGetPolyNormals (TYPE_8__*,TYPE_4__*) ; 
 int /*<<< orphan*/  lwGetPolyVMaps (TYPE_4__*,TYPE_1__*) ; 
 int /*<<< orphan*/  lwGetPolygonTags (int /*<<< orphan*/ *,unsigned int,int /*<<< orphan*/ *,TYPE_4__*) ; 
 int /*<<< orphan*/  lwGetPolygons (int /*<<< orphan*/ *,unsigned int,TYPE_4__*,int /*<<< orphan*/ ) ; 
 scalar_t__ lwGetSurface (int /*<<< orphan*/ *,unsigned int) ; 
 int /*<<< orphan*/  lwGetTags (int /*<<< orphan*/ *,unsigned int,int /*<<< orphan*/ *) ; 
 scalar_t__ lwGetVMap (int /*<<< orphan*/ *,unsigned int,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  lwGetVertNormals (TYPE_8__*,TYPE_4__*) ; 
 int /*<<< orphan*/  lwListAdd (void**,TYPE_1__*) ; 
 int /*<<< orphan*/  lwListFree (TYPE_1__*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  lwResolvePolySurfaces (TYPE_4__*,int /*<<< orphan*/ *,TYPE_1__**,int /*<<< orphan*/ *) ; 
 int lwValidateObject5 (char*,int /*<<< orphan*/ *,unsigned int*,int*) ; 
 int /*<<< orphan*/  set_flen (int /*<<< orphan*/ ) ; 

void lwFreeLayer( lwLayer *layer ){
	if ( layer ) {
		if ( layer->name ) {
			_pico_free( layer->name );
		}
		lwFreePoints( &layer->point );
		lwFreePolygons( &layer->polygon );
		lwListFree( layer->vmap, (ListFreeFunc) lwFreeVMap );
		_pico_free( layer );
	}
}

void lwFreeObject( lwObject *object ){
	if ( object ) {
		lwListFree( object->layer, (ListFreeFunc) lwFreeLayer );
		lwListFree( object->env, (ListFreeFunc) lwFreeEnvelope );
		lwListFree( object->clip, (ListFreeFunc) lwFreeClip );
		lwListFree( object->surf, (ListFreeFunc) lwFreeSurface );
		lwFreeTags( &object->taglist );
		_pico_free( object );
	}
}

lwObject *lwGetObject( char *filename, picoMemStream_t *fp, unsigned int *failID, int *failpos ){
	lwObject *object;
	lwLayer *layer;
	lwNode *node;
	unsigned int id, formsize, type, cksize;
	int i, rlen;

	/* open the file */

	if ( !fp ) {
		return NULL;
	}

	/* read the first 12 bytes */

	set_flen( 0 );
	id       = getU4( fp );
	formsize = getU4( fp );
	type     = getU4( fp );
	if ( 12 != get_flen() ) {
		return NULL;
	}

	/* is this a LW object? */

	if ( id != ID_FORM ) {
		if ( failpos ) {
			*failpos = 12;
		}
		return NULL;
	}

	if ( type != ID_LWO2 ) {
		if ( type == ID_LWOB ) {
			return lwGetObject5( filename, fp, failID, failpos );
		}
		else {
			if ( failpos ) {
				*failpos = 12;
			}
			return NULL;
		}
	}

	/* allocate an object and a default layer */

	object = _pico_calloc( 1, sizeof( lwObject ) );
	if ( !object ) {
		goto Fail;
	}

	layer = _pico_calloc( 1, sizeof( lwLayer ) );
	if ( !layer ) {
		goto Fail;
	}
	object->layer = layer;

	/* get the first chunk header */

	id = getU4( fp );
	cksize = getU4( fp );
	if ( 0 > get_flen() ) {
		goto Fail;
	}

	/* process chunks as they're encountered */

	while ( 1 ) {
		cksize += cksize & 1;

		switch ( id )
		{
		case ID_LAYR:
			if ( object->nlayers > 0 ) {
				layer = _pico_calloc( 1, sizeof( lwLayer ) );
				if ( !layer ) {
					goto Fail;
				}
				lwListAdd( (void **) &object->layer, layer );
			}
			object->nlayers++;

			set_flen( 0 );
			layer->index = getU2( fp );
			layer->flags = getU2( fp );
			layer->pivot[ 0 ] = getF4( fp );
			layer->pivot[ 1 ] = getF4( fp );
			layer->pivot[ 2 ] = getF4( fp );
			layer->name = getS0( fp );

			rlen = get_flen();
			if ( rlen < 0 || rlen > cksize ) {
				goto Fail;
			}
			if ( rlen <= cksize - 2 ) {
				layer->parent = getU2( fp );
			}
			rlen = get_flen();
			if ( rlen < cksize ) {
				_pico_memstream_seek( fp, cksize - rlen, PICO_SEEK_CUR );
			}
			break;

		case ID_PNTS:
			if ( !lwGetPoints( fp, cksize, &layer->point ) ) {
				goto Fail;
			}
			break;

		case ID_POLS:
			if ( !lwGetPolygons( fp, cksize, &layer->polygon,
								 layer->point.offset ) ) {
				goto Fail;
			}
			break;

		case ID_VMAP:
		case ID_VMAD:
			node = ( lwNode * ) lwGetVMap( fp, cksize, layer->point.offset,
										   layer->polygon.offset, id == ID_VMAD );
			if ( !node ) {
				goto Fail;
			}
			lwListAdd( (void **) &layer->vmap, node );
			layer->nvmaps++;
			break;

		case ID_PTAG:
			if ( !lwGetPolygonTags( fp, cksize, &object->taglist,
									&layer->polygon ) ) {
				goto Fail;
			}
			break;

		case ID_BBOX:
			set_flen( 0 );
			for ( i = 0; i < 6; i++ )
				layer->bbox[ i ] = getF4( fp );
			rlen = get_flen();
			if ( rlen < 0 || rlen > cksize ) {
				goto Fail;
			}
			if ( rlen < cksize ) {
				_pico_memstream_seek( fp, cksize - rlen, PICO_SEEK_CUR );
			}
			break;

		case ID_TAGS:
			if ( !lwGetTags( fp, cksize, &object->taglist ) ) {
				goto Fail;
			}
			break;

		case ID_ENVL:
			node = ( lwNode * ) lwGetEnvelope( fp, cksize );
			if ( !node ) {
				goto Fail;
			}
			lwListAdd( (void **) &object->env, node );
			object->nenvs++;
			break;

		case ID_CLIP:
			node = ( lwNode * ) lwGetClip( fp, cksize );
			if ( !node ) {
				goto Fail;
			}
			lwListAdd( (void **) &object->clip, node );
			object->nclips++;
			break;

		case ID_SURF:
			node = ( lwNode * ) lwGetSurface( fp, cksize );
			if ( !node ) {
				goto Fail;
			}
			lwListAdd( (void **) &object->surf, node );
			object->nsurfs++;
			break;

		case ID_DESC:
		case ID_TEXT:
		case ID_ICON:
		default:
			_pico_memstream_seek( fp, cksize, PICO_SEEK_CUR );
			break;
		}

		/* end of the file? */

		if ( formsize <= _pico_memstream_tell( fp ) - 8 ) {
			break;
		}

		/* get the next chunk header */

		set_flen( 0 );
		id = getU4( fp );
		cksize = getU4( fp );
		if ( 8 != get_flen() ) {
			goto Fail;
		}
	}

	if ( object->nlayers == 0 ) {
		object->nlayers = 1;
	}

	layer = object->layer;
	while ( layer ) {
		lwGetBoundingBox( &layer->point, layer->bbox );
		lwGetPolyNormals( &layer->point, &layer->polygon );
		if ( !lwGetPointPolygons( &layer->point, &layer->polygon ) ) {
			goto Fail;
		}
		if ( !lwResolvePolySurfaces( &layer->polygon, &object->taglist,
									 &object->surf, &object->nsurfs ) ) {
			goto Fail;
		}
		lwGetVertNormals( &layer->point, &layer->polygon );
		if ( !lwGetPointVMaps( &layer->point, layer->vmap ) ) {
			goto Fail;
		}
		if ( !lwGetPolyVMaps( &layer->polygon, layer->vmap ) ) {
			goto Fail;
		}
		layer = layer->next;
	}

	return object;

Fail:
	if ( failID ) {
		*failID = id;
	}
	if ( fp ) {
		if ( failpos ) {
			*failpos = _pico_memstream_tell( fp );
		}
	}
	lwFreeObject( object );
	return NULL;
}

int lwValidateObject( char *filename, picoMemStream_t *fp, unsigned int *failID, int *failpos ){
	unsigned int id, formsize, type;

	/* open the file */

	if ( !fp ) {
		return PICO_PMV_ERROR_MEMORY;
	}

	/* read the first 12 bytes */

	set_flen( 0 );
	id       = getU4( fp );
	formsize = getU4( fp );
	type     = getU4( fp );
	if ( 12 != get_flen() ) {
		return PICO_PMV_ERROR_SIZE;
	}

	/* is this a LW object? */

	if ( id != ID_FORM ) {
		if ( failpos ) {
			*failpos = 12;
		}
		return PICO_PMV_ERROR_SIZE;
	}

	if ( type != ID_LWO2 ) {
		if ( type == ID_LWOB ) {
			return lwValidateObject5( filename, fp, failID, failpos );
		}
		else {
			if ( failpos ) {
				*failpos = 12;
			}
			return PICO_PMV_ERROR_IDENT;
		}
	}

	return PICO_PMV_OK;
}

