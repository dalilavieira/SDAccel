#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_9__   TYPE_3__ ;
typedef  struct TYPE_8__   TYPE_2__ ;
typedef  struct TYPE_7__   TYPE_1__ ;

/* Type definitions */
typedef  int uint16 ;
struct TYPE_7__ {int td_compression; } ;
struct TYPE_9__ {int (* tif_fixuptags ) (TYPE_3__*) ;int (* tif_setupdecode ) (TYPE_3__*) ;int (* tif_setupencode ) (TYPE_3__*) ;void* tif_encodestatus; void* tif_decodestatus; int /*<<< orphan*/  tif_name; int /*<<< orphan*/  tif_clientdata; TYPE_1__ tif_dir; } ;
struct TYPE_8__ {char* name; int (* init ) (TYPE_3__*,int) ;} ;
typedef  TYPE_2__ TIFFCodec ;
typedef  TYPE_3__ TIFF ;

/* Variables and functions */
 void* FALSE ; 
 int /*<<< orphan*/  TIFFErrorExt (int /*<<< orphan*/ ,int /*<<< orphan*/ ,char*,char*) ; 
 TYPE_2__* TIFFFindCODEC (int) ; 
 int /*<<< orphan*/  sprintf (char*,char*,int) ; 

__attribute__((used)) static int
_notConfigured(TIFF* tif)
{
	const TIFFCodec* c = TIFFFindCODEC(tif->tif_dir.td_compression);
        char compression_code[20];
        
        sprintf(compression_code, "%d",tif->tif_dir.td_compression );
	TIFFErrorExt(tif->tif_clientdata, tif->tif_name,
                     "%s compression support is not configured", 
                     c ? c->name : compression_code );
	return (0);
}

__attribute__((used)) static int
NotConfigured(TIFF* tif, int scheme)
{
	(void) scheme;

	tif->tif_fixuptags = _notConfigured;
	tif->tif_decodestatus = FALSE;
	tif->tif_setupdecode = _notConfigured;
	tif->tif_encodestatus = FALSE;
	tif->tif_setupencode = _notConfigured;
	return (1);
}

int
TIFFIsCODECConfigured(uint16 scheme)
{
	const TIFFCodec* codec = TIFFFindCODEC(scheme);

	if(codec == NULL) {
		return 0;
	}
	if(codec->init == NULL) {
		return 0;
	}
	if(codec->init != NotConfigured){
		return 1;
	}
	return 0;
}

