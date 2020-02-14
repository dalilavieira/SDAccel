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
 long double copysign (long double,long double) ; 
 long double fmod (long double,long double) ; 
 long double scalbn (long double,int) ; 

long double fmodl(long double x, long double y)
{
    return fmod(x, y);
}

long double scalbnl(long double x, int exp)
{
    return scalbn(x, exp);
}

long double copysignl(long double x, long double y)
{
    return copysign(x, y);
}

