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
typedef  unsigned int int32_t ;

/* Variables and functions */
 float* f_ict_params ; 
 scalar_t__* i_ict_params ; 

__attribute__((used)) static void ict_float(void *_src0, void *_src1, void *_src2, int csize)
{
    float *src0 = _src0, *src1 = _src1, *src2 = _src2;
    float i0f, i1f, i2f;
    int i;

    for (i = 0; i < csize; i++) {
        i0f = *src0 + (f_ict_params[0] * *src2);
        i1f = *src0 - (f_ict_params[1] * *src1)
                    - (f_ict_params[2] * *src2);
        i2f = *src0 + (f_ict_params[3] * *src1);
        *src0++ = i0f;
        *src1++ = i1f;
        *src2++ = i2f;
    }
}

__attribute__((used)) static void ict_int(void *_src0, void *_src1, void *_src2, int csize)
{
    int32_t *src0 = _src0, *src1 = _src1, *src2 = _src2;
    int32_t i0, i1, i2;
    int i;

    for (i = 0; i < csize; i++) {
        i0 = *src0 + *src2 + ((int)((26345U * *src2) + (1 << 15)) >> 16);
        i1 = *src0 - ((int)(((unsigned)i_ict_params[1] * *src1) + (1 << 15)) >> 16)
                   - ((int)(((unsigned)i_ict_params[2] * *src2) + (1 << 15)) >> 16);
        i2 = *src0 + (2 * *src1) + ((int)((-14942U * *src1) + (1 << 15)) >> 16);
        *src0++ = i0;
        *src1++ = i1;
        *src2++ = i2;
    }
}

__attribute__((used)) static void rct_int(void *_src0, void *_src1, void *_src2, int csize)
{
    int32_t *src0 = _src0, *src1 = _src1, *src2 = _src2;
    int32_t i0, i1, i2;
    int i;

    for (i = 0; i < csize; i++) {
        i1 = *src0 - (*src2 + *src1 >> 2);
        i0 = i1 + *src2;
        i2 = i1 + *src1;
        *src0++ = i0;
        *src1++ = i1;
        *src2++ = i2;
    }
}

