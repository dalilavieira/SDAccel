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
typedef  int uint8_t ;
typedef  int ptrdiff_t ;

/* Variables and functions */

__attribute__((used)) static void reorder_pixels_scalar(uint8_t *dst, const uint8_t *src, ptrdiff_t size)
{
    const uint8_t *t1 = src;
    int half_size     = size / 2;
    const uint8_t *t2 = src + half_size;
    uint8_t *s        = dst;
    int i;

    for (i = 0; i < half_size; i++) {
        *(s++) = *(t1++);
        *(s++) = *(t2++);
    }
}

__attribute__((used)) static void predictor_scalar(uint8_t *src, ptrdiff_t size)
{
    ptrdiff_t i;

    for (i = 1; i < size; i++)
        src[i] += src[i-1] - 128;
}

