#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
typedef  scalar_t__ sb_status ;
struct TYPE_3__ {int base; } ;
typedef  TYPE_1__ SB16 ;

/* Variables and functions */
 scalar_t__ SB_FALSE ; 
 scalar_t__ SB_TRUE ; 
 int base ; 
 scalar_t__ reset_dsp (unsigned short) ; 

unsigned char read_dsp(unsigned short base)
{
//	while((inb(base+0x0e)&0x80)==0);	//Wait until there is something to read
//	return	inb(base+0x0a);
	return 0;
}

sb_status detect_dsp(SB16* sb16)
{
	for(base=0x200;base<0x280;base+=0x10)	//Tries to reset all DSP addresses there is
		if(reset_dsp(base)==SB_TRUE)
		{
			sb16->base=base;
		 	return SB_TRUE;
		}
	return SB_FALSE;
}

sb_status reset_dsp(unsigned short base_address)
{
//	int delay;

//	outb(base_address+DSP_RESET_PORT,1);
//	for(delay=0;delay<0xffff;delay++);

//	outb(base_address+DSP_RESET_PORT,0);
//	for(delay=0;delay<0xffff;delay++);

//	if((inb(base_address+DSP_READ_STATUS_PORT)&0x80)==0) return SB_FALSE;

//	if(inb(base_address+DSP_READ_DATA_PORT)!=0xAA) return SB_FALSE;

	return SB_TRUE;
}

void write_dsp(unsigned short base,unsigned char data)
{
//  while ((inb(base+DSP_WRITE_PORT) & 0x80) != 0);
//  outb(base+DSP_WRITE_PORT, data);
}

