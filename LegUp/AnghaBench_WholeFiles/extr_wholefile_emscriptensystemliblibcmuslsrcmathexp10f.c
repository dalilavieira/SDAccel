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
typedef  int uint32_t ;

/* Variables and functions */
 float exp2 (double) ; 
 float exp2f (float) ; 
 float modff (float,float*) ; 

float exp10f(float x)
{
	static const float p10[] = {
		1e-7f, 1e-6f, 1e-5f, 1e-4f, 1e-3f, 1e-2f, 1e-1f,
		1, 1e1, 1e2, 1e3, 1e4, 1e5, 1e6, 1e7
	};
	float n, y = modff(x, &n);
	union {float f; uint32_t i;} u = {n};
	/* fabsf(n) < 8 without raising invalid on nan */
	if ((u.i>>23 & 0xff) < 0x7f+3) {
		if (!y) return p10[(int)n+7];
		y = exp2f(3.32192809488736234787031942948939f * y);
		return y * p10[(int)n+7];
	}
	return exp2(3.32192809488736234787031942948939 * x);
}

