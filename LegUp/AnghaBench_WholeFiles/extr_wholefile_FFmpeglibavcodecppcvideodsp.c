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
typedef  int /*<<< orphan*/  uint8_t ;
typedef  int /*<<< orphan*/  ptrdiff_t ;

/* Variables and functions */

__attribute__((used)) static void prefetch_ppc(uint8_t *mem, ptrdiff_t stride, int h)
{
    register const uint8_t *p = mem;
    do {
        __asm__ volatile ("dcbt 0,%0" : : "r" (p));
        p += stride;
    } while(--h);
}

