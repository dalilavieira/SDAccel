#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */

/* Type definitions */

/* Variables and functions */
 int __rand48_step (unsigned short*,unsigned short*) ; 
 unsigned short* __seed48 ; 

long nrand48(unsigned short s[3])
{
	return __rand48_step(s, __seed48+3) >> 17;
}

long lrand48(void)
{
	return nrand48(__seed48);
}

