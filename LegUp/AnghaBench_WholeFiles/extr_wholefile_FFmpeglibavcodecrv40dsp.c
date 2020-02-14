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
typedef  int ptrdiff_t ;
typedef  int /*<<< orphan*/  int8_t ;

/* Variables and functions */
 int /*<<< orphan*/  avg_pixels16_xy2_8_c (int /*<<< orphan*/ *,int /*<<< orphan*/  const*,int,int) ; 
 int /*<<< orphan*/  avg_pixels8_xy2_8_c (int /*<<< orphan*/ *,int /*<<< orphan*/  const*,int,int) ; 
 int /*<<< orphan*/  put_pixels16_xy2_8_c (int /*<<< orphan*/ *,int /*<<< orphan*/  const*,int,int) ; 
 int /*<<< orphan*/  put_pixels8_xy2_8_c (int /*<<< orphan*/ *,int /*<<< orphan*/  const*,int,int) ; 
 int rv40_loop_filter_strength (int /*<<< orphan*/ *,int,int,int,int,int,int*,int*) ; 
 int /*<<< orphan*/  rv40_strong_loop_filter (int /*<<< orphan*/ *,int const,int const,int const,int const,int const,int const) ; 
 int /*<<< orphan*/  rv40_weak_loop_filter (int /*<<< orphan*/ *,int const,int const,int const,int const,int const,int const,int const,int const,int const) ; 

__attribute__((used)) static inline int8_t ff_u8_to_s8(uint8_t a)
{
    union {
        uint8_t u8;
        int8_t  s8;
    } b;
    b.u8 = a;
    return b.s8;
}

__attribute__((used)) static void put_rv40_qpel16_mc33_c(uint8_t *dst, const uint8_t *src, ptrdiff_t stride)
{
    put_pixels16_xy2_8_c(dst, src, stride, 16);
}

__attribute__((used)) static void avg_rv40_qpel16_mc33_c(uint8_t *dst, const uint8_t *src, ptrdiff_t stride)
{
    avg_pixels16_xy2_8_c(dst, src, stride, 16);
}

__attribute__((used)) static void put_rv40_qpel8_mc33_c(uint8_t *dst, const uint8_t *src, ptrdiff_t stride)
{
    put_pixels8_xy2_8_c(dst, src, stride, 8);
}

__attribute__((used)) static void avg_rv40_qpel8_mc33_c(uint8_t *dst, const uint8_t *src, ptrdiff_t stride)
{
    avg_pixels8_xy2_8_c(dst, src, stride, 8);
}

__attribute__((used)) static void rv40_h_weak_loop_filter(uint8_t *src, const ptrdiff_t stride,
                                    const int filter_p1, const int filter_q1,
                                    const int alpha, const int beta,
                                    const int lim_p0q0, const int lim_q1,
                                    const int lim_p1)
{
    rv40_weak_loop_filter(src, stride, 1, filter_p1, filter_q1,
                          alpha, beta, lim_p0q0, lim_q1, lim_p1);
}

__attribute__((used)) static void rv40_v_weak_loop_filter(uint8_t *src, const ptrdiff_t stride,
                                    const int filter_p1, const int filter_q1,
                                    const int alpha, const int beta,
                                    const int lim_p0q0, const int lim_q1,
                                    const int lim_p1)
{
    rv40_weak_loop_filter(src, 1, stride, filter_p1, filter_q1,
                          alpha, beta, lim_p0q0, lim_q1, lim_p1);
}

__attribute__((used)) static void rv40_h_strong_loop_filter(uint8_t *src, const ptrdiff_t stride,
                                      const int alpha, const int lims,
                                      const int dmode, const int chroma)
{
    rv40_strong_loop_filter(src, stride, 1, alpha, lims, dmode, chroma);
}

__attribute__((used)) static void rv40_v_strong_loop_filter(uint8_t *src, const ptrdiff_t stride,
                                      const int alpha, const int lims,
                                      const int dmode, const int chroma)
{
    rv40_strong_loop_filter(src, 1, stride, alpha, lims, dmode, chroma);
}

__attribute__((used)) static int rv40_h_loop_filter_strength(uint8_t *src, ptrdiff_t stride,
                                       int beta, int beta2, int edge,
                                       int *p1, int *q1)
{
    return rv40_loop_filter_strength(src, stride, 1, beta, beta2, edge, p1, q1);
}

__attribute__((used)) static int rv40_v_loop_filter_strength(uint8_t *src, ptrdiff_t stride,
                                       int beta, int beta2, int edge,
                                       int *p1, int *q1)
{
    return rv40_loop_filter_strength(src, 1, stride, beta, beta2, edge, p1, q1);
}

