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
typedef  int /*<<< orphan*/  vec_u8 ;
typedef  scalar_t__ vec_f ;

/* Variables and functions */
 int /*<<< orphan*/  vcprm (int,int,int,int /*<<< orphan*/ ) ; 
 scalar_t__ vec_madd (scalar_t__,scalar_t__,scalar_t__) ; 
 scalar_t__ vec_mergeh (scalar_t__,scalar_t__) ; 
 scalar_t__ vec_mergel (scalar_t__,scalar_t__) ; 
 scalar_t__ vec_nmsub (scalar_t__,scalar_t__,scalar_t__) ; 
 scalar_t__ vec_perm (scalar_t__,scalar_t__,int /*<<< orphan*/  const) ; 
 scalar_t__ vec_splat_u32 (int /*<<< orphan*/ ) ; 
 scalar_t__ vec_vsx_ld (int,float const*) ; 
 int /*<<< orphan*/  vec_vsx_st (scalar_t__,int,float*) ; 

void ff_vector_fmul_vsx(float *dst,
                        const float *src0, const float *src1,
                        int len)
{
    int i;
    vec_f d0, d1, zero = (vec_f)vec_splat_u32(0);
    for (i = 0; i < len - 7; i += 8) {
        d0 = vec_vsx_ld( 0, src0 + i);
        d1 = vec_vsx_ld(16, src0 + i);
        d0 = vec_madd(d0, vec_vsx_ld( 0, src1 + i), zero);
        d1 = vec_madd(d1, vec_vsx_ld(16, src1 + i), zero);
        vec_vsx_st(d0,  0, dst + i);
        vec_vsx_st(d1, 16, dst + i);
    }
}

void ff_vector_fmul_window_vsx(float *dst, const float *src0,
                               const float *src1, const float *win,
                               int len)
{
    vec_f zero, t0, t1, s0, s1, wi, wj;
    const vec_u8 reverse = vcprm(3, 2, 1, 0);
    int i, j;

    dst  += len;
    win  += len;
    src0 += len;

    zero = (vec_f)vec_splat_u32(0);

    for (i = -len * 4, j = len * 4 - 16; i < 0; i += 16, j -= 16) {
        s0 = vec_vsx_ld(i, src0);
        s1 = vec_vsx_ld(j, src1);
        wi = vec_vsx_ld(i, win);
        wj = vec_vsx_ld(j, win);

        s1 = vec_perm(s1, s1, reverse);
        wj = vec_perm(wj, wj, reverse);

        t0 = vec_madd(s0, wj, zero);
        t0 = vec_nmsub(s1, wi, t0);
        t1 = vec_madd(s0, wi, zero);
        t1 = vec_madd(s1, wj, t1);
        t1 = vec_perm(t1, t1, reverse);

        vec_vsx_st(t0, i, dst);
        vec_vsx_st(t1, j, dst);
    }
}

void ff_vector_fmul_add_vsx(float *dst, const float *src0,
                            const float *src1, const float *src2,
                            int len)
{
    int i;
    vec_f d, s0, s1, s2;

    for (i = 0; i < len - 3; i += 4) {
        s0 = vec_vsx_ld(0, src0 + i);
        s1 = vec_vsx_ld(0, src1 + i);
        s2 = vec_vsx_ld(0, src2 + i);
        d = vec_madd(s0, s1, s2);
        vec_vsx_st(d, 0, dst + i);
    }
}

void ff_vector_fmul_reverse_vsx(float *dst, const float *src0,
                                const float *src1, int len)
{
    int i;
    vec_f d, s0, s1, h0, l0, s2, s3;
    vec_f zero = (vec_f)vec_splat_u32(0);

    src1 += len - 4;
    for (i = 0; i < len - 7; i += 8) {
        s1 = vec_vsx_ld(0, src1 - i);              // [a,b,c,d]
        s0 = vec_vsx_ld(0, src0 + i);
        l0 = vec_mergel(s1, s1);               // [c,c,d,d]
        s3 = vec_vsx_ld(-16, src1 - i);
        h0 = vec_mergeh(s1, s1);               // [a,a,b,b]
        s2 = vec_vsx_ld(16, src0 + i);
        s1 = vec_mergeh(vec_mergel(l0, h0),    // [d,b,d,b]
                        vec_mergeh(l0, h0));   // [c,a,c,a]
        // [d,c,b,a]
        l0 = vec_mergel(s3, s3);
        d = vec_madd(s0, s1, zero);
        h0 = vec_mergeh(s3, s3);
        vec_vsx_st(d, 0, dst + i);
        s3 = vec_mergeh(vec_mergel(l0, h0),
                        vec_mergeh(l0, h0));
        d = vec_madd(s2, s3, zero);
        vec_vsx_st(d, 16, dst + i);
    }
}

