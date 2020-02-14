#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
struct TYPE_2__ {long long seek_sector; long long sectors; long long seek_head; long long heads; long long seek_cylinder; long long seekto; int bytespersec; short cylinders; scalar_t__ port; } ;
typedef  TYPE_1__ idectl_desc ;

/* Variables and functions */
 int GetPhysByte (scalar_t__) ; 
 short GetPhysHalf (scalar_t__) ; 
 short SWAP_W (short) ; 
 int /*<<< orphan*/  SetPhysByte (scalar_t__,int) ; 
 int /*<<< orphan*/  printf (char*,...) ; 
 int /*<<< orphan*/  strncpy (char*,char*,int) ; 
 int /*<<< orphan*/  sync () ; 

void ide_seek( void *extension, int low, int high ) {
    idectl_desc *desc = (idectl_desc *)extension;
    long long seekto = ((((long long)high) << 32) | (low & 0xffffffff));
    /* order = sector, head, cylinder */
    desc->seek_sector = seekto % desc->sectors;
    seekto /= desc->sectors;
    desc->seek_head = seekto % desc->heads;
    seekto /= desc->heads;
    desc->seek_cylinder = seekto;
    desc->seekto = seekto;
}

void ide_rdy( void *extension ) {
    idectl_desc *desc = (idectl_desc *)extension;
    while( !(GetPhysByte(desc->port+7) & 0x40) ) sync();
}

void ide_drq( void *extension ) {
    idectl_desc *desc = (idectl_desc *)extension;
    while( !(GetPhysByte(desc->port+7) & 0x08) ) sync();
}

void ide_bsy( void *extension ) {
    idectl_desc *desc = (idectl_desc *)extension;
    while( GetPhysByte(desc->port+7) & 0x80 )
    {
    printf("Waiting for not busy\n");
    sync();
    }
}

int ide_read( void *extension, char *buffer, int bytes ) {
    idectl_desc *desc = (idectl_desc *)extension;
    short *databuf = (short *)buffer;
    int inwords;

    ide_bsy( extension );
    SetPhysByte(desc->port+2, bytes / desc->bytespersec);
    SetPhysByte(desc->port+3, desc->seek_sector + 1);
    SetPhysByte(desc->port+4, desc->seek_cylinder);
    SetPhysByte(desc->port+5, desc->seek_cylinder >> 8);
    SetPhysByte(desc->port+6, desc->seek_head | 0xa0);
    SetPhysByte(desc->port+7, 0x20);

    for( inwords = 0; inwords < desc->bytespersec / sizeof(short); inwords++ ) {
    databuf[inwords] = GetPhysHalf(desc->port);
    }

    desc->seekto += desc->bytespersec;
    ide_seek( extension, desc->seekto, desc->seekto >> 32 );

    return bytes - (bytes % desc->bytespersec);
}

void ide_setup( void *extension ) {
    idectl_desc *desc = (idectl_desc *)extension;
    short identbuffer[256];
    char namebuf[41];
    short *databuf = (short *)identbuffer, in;
    int inwords;

    ide_rdy( extension );
    ide_bsy( extension );
    desc->bytespersec = 512;
    SetPhysByte(desc->port+2, 1);
    SetPhysByte(desc->port+3, 0);
    SetPhysByte(desc->port+4, 0);
    SetPhysByte(desc->port+5, 0);
    SetPhysByte(desc->port+6, 0);
    SetPhysByte(desc->port+7, 0xec);
    ide_drq( extension );

    for( inwords = 0; inwords < desc->bytespersec / sizeof(short); inwords++ ) {
    in = GetPhysHalf(desc->port);
    databuf[inwords] = SWAP_W(in);
    sync();
    }

    desc->cylinders = identbuffer[1];
    desc->heads = identbuffer[3];
    desc->sectors = identbuffer[6];

    /* Debug: Write out hard disc model */

    strncpy(namebuf, (char *)(identbuffer+0x1b), 41);
    printf("HARD DISC MODEL: %s c,h,s %d,%d,%d\n",
       namebuf, desc->cylinders, desc->heads, desc->sectors);
}

