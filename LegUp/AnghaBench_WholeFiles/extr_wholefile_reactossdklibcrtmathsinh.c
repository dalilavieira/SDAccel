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
 double exp (double) ; 

double sinh(double x)
{
 if(x >= 0.0)
 {
   const double epos = exp(x);
   return (epos - 1.0/epos) / 2.0;
 }
 else
 {
   const double eneg = exp(-x);
   return (1.0/eneg - eneg) / 2.0;
 }
}

