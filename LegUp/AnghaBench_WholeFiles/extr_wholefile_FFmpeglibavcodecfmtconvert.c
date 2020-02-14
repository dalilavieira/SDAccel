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
typedef  float int32_t ;
struct TYPE_3__ {int /*<<< orphan*/  (* int32_to_float_fmul_scalar ) (float*,float const*,int /*<<< orphan*/ ,int) ;} ;
typedef  TYPE_1__ FmtConvertContext ;

/* Variables and functions */
 int /*<<< orphan*/  stub1 (float*,float const*,int /*<<< orphan*/ ,int) ; 

__attribute__((used)) static void int32_to_float_fmul_scalar_c(float *dst, const int32_t *src,
                                         float mul, int len)
{
    int i;
    for(i=0; i<len; i++)
        dst[i] = src[i] * mul;
}

__attribute__((used)) static void int32_to_float_c(float *dst, const int32_t *src, intptr_t len)
{
    int i;

    for (i = 0; i < len; i++)
        dst[i] = (float)src[i];
}

__attribute__((used)) static void int32_to_float_fmul_array8_c(FmtConvertContext *c, float *dst,
                                         const int32_t *src, const float *mul,
                                         int len)
{
    int i;
    for (i = 0; i < len; i += 8)
        c->int32_to_float_fmul_scalar(&dst[i], &src[i], *mul++, 8);
}

