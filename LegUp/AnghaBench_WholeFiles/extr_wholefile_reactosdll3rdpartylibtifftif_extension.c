#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_15__   TYPE_5__ ;
typedef  struct TYPE_14__   TYPE_4__ ;
typedef  struct TYPE_13__   TYPE_3__ ;
typedef  struct TYPE_12__   TYPE_2__ ;
typedef  struct TYPE_11__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  uint32 ;
typedef  int tmsize_t ;
struct TYPE_13__ {int td_customValueCount; TYPE_2__* td_customValues; } ;
struct TYPE_15__ {TYPE_4__* tif_clientinfo; int /*<<< orphan*/  tif_tagmethods; TYPE_3__ tif_dir; } ;
struct TYPE_14__ {char* name; void* data; struct TYPE_14__* next; } ;
struct TYPE_12__ {TYPE_1__* info; } ;
struct TYPE_11__ {int /*<<< orphan*/  field_tag; } ;
typedef  int /*<<< orphan*/  TIFFTagMethods ;
typedef  TYPE_3__ TIFFDirectory ;
typedef  TYPE_4__ TIFFClientInfoLink ;
typedef  TYPE_5__ TIFF ;

/* Variables and functions */
 scalar_t__ _TIFFmalloc (int) ; 
 int /*<<< orphan*/  assert (int /*<<< orphan*/ ) ; 
 scalar_t__ strcmp (char*,char const*) ; 
 int /*<<< orphan*/  strcpy (char*,char const*) ; 
 scalar_t__ strlen (char const*) ; 

int TIFFGetTagListCount( TIFF *tif )

{
    TIFFDirectory* td = &tif->tif_dir;
    
    return td->td_customValueCount;
}

uint32 TIFFGetTagListEntry( TIFF *tif, int tag_index )

{
    TIFFDirectory* td = &tif->tif_dir;

    if( tag_index < 0 || tag_index >= td->td_customValueCount )
        return (uint32)(-1);
    else
        return td->td_customValues[tag_index].info->field_tag;
}

TIFFTagMethods *TIFFAccessTagMethods( TIFF *tif )

{
    return &(tif->tif_tagmethods);
}

void *TIFFGetClientInfo( TIFF *tif, const char *name )

{
    TIFFClientInfoLink *psLink = tif->tif_clientinfo;

    while( psLink != NULL && strcmp(psLink->name,name) != 0 )
        psLink = psLink->next;

    if( psLink != NULL )
        return psLink->data;
    else
        return NULL;
}

void TIFFSetClientInfo( TIFF *tif, void *data, const char *name )

{
    TIFFClientInfoLink *psLink = tif->tif_clientinfo;

    /*
    ** Do we have an existing link with this name?  If so, just
    ** set it.
    */
    while( psLink != NULL && strcmp(psLink->name,name) != 0 )
        psLink = psLink->next;

    if( psLink != NULL )
    {
        psLink->data = data;
        return;
    }

    /*
    ** Create a new link.
    */

    psLink = (TIFFClientInfoLink *) _TIFFmalloc(sizeof(TIFFClientInfoLink));
    assert (psLink != NULL);
    psLink->next = tif->tif_clientinfo;
    psLink->name = (char *) _TIFFmalloc((tmsize_t)(strlen(name)+1));
    assert (psLink->name != NULL);
    strcpy(psLink->name, name);
    psLink->data = data;

    tif->tif_clientinfo = psLink;
}

