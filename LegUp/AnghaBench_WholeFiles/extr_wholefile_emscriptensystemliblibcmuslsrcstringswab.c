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
typedef  int ssize_t ;

/* Variables and functions */

void swab(const void *restrict _src, void *restrict _dest, ssize_t n)
{
	const char *src = _src;
	char *dest = _dest;
	for (; n>1; n-=2) {
		dest[0] = src[1];
		dest[1] = src[0];
		dest += 2;
		src += 2;
	}
}

