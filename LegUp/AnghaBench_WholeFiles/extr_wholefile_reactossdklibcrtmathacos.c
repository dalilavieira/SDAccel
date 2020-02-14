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
 double atan2 (int /*<<< orphan*/ ,double) ; 
 int /*<<< orphan*/  sqrt (double) ; 

double acos(double __x)
{
    return atan2(sqrt(1.0 - __x * __x), __x);
}

