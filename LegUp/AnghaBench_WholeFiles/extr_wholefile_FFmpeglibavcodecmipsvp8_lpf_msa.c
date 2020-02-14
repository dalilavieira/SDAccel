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
typedef  int /*<<< orphan*/  v8i16 ;
typedef  scalar_t__ v4i32 ;
typedef  int /*<<< orphan*/  v2i64 ;
typedef  scalar_t__ v16u8 ;
typedef  int /*<<< orphan*/  v16i8 ;
typedef  int /*<<< orphan*/  uint8_t ;
typedef  int /*<<< orphan*/  uint64_t ;
typedef  int ptrdiff_t ;
typedef  int int32_t ;

/* Variables and functions */
 int /*<<< orphan*/  ILVL_B2_SH (scalar_t__,scalar_t__,scalar_t__,scalar_t__,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ILVRL_B2_SH (scalar_t__,scalar_t__,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ILVRL_H2_SH (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ILVRL_H2_SW (scalar_t__,scalar_t__,scalar_t__,scalar_t__) ; 
 int /*<<< orphan*/  ILVR_B2_SH (scalar_t__,scalar_t__,scalar_t__,scalar_t__,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ILVR_B2_SW (scalar_t__,scalar_t__,scalar_t__,scalar_t__,scalar_t__,scalar_t__) ; 
 int /*<<< orphan*/  ILVR_D4_UB (scalar_t__,scalar_t__,scalar_t__,scalar_t__,scalar_t__,scalar_t__,scalar_t__,scalar_t__,scalar_t__,scalar_t__,scalar_t__,scalar_t__) ; 
 int /*<<< orphan*/  LD_UB4 (int /*<<< orphan*/ *,int,scalar_t__,scalar_t__,scalar_t__,scalar_t__) ; 
 int /*<<< orphan*/  LD_UB8 (int /*<<< orphan*/ *,int,scalar_t__,scalar_t__,scalar_t__,scalar_t__,scalar_t__,scalar_t__,scalar_t__,scalar_t__) ; 
 int /*<<< orphan*/  LPF_MASK_HEV (scalar_t__,scalar_t__,scalar_t__,scalar_t__,scalar_t__,scalar_t__,scalar_t__,scalar_t__,scalar_t__,scalar_t__,scalar_t__,scalar_t__,scalar_t__,scalar_t__) ; 
 int /*<<< orphan*/  SD (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  SD4 (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  ST2x4_UB (int /*<<< orphan*/ ,int,int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  ST4x4_UB (scalar_t__,scalar_t__,int /*<<< orphan*/ ,int,int,int,int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  ST4x8_UB (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  ST_UB2 (scalar_t__,scalar_t__,int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  ST_UB4 (scalar_t__,scalar_t__,scalar_t__,scalar_t__,int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  TRANSPOSE16x4_UB_UB (scalar_t__,scalar_t__,scalar_t__,scalar_t__,scalar_t__,scalar_t__,scalar_t__,scalar_t__,scalar_t__,scalar_t__,scalar_t__,scalar_t__,scalar_t__,scalar_t__,scalar_t__,scalar_t__,scalar_t__,scalar_t__,scalar_t__,scalar_t__) ; 
 int /*<<< orphan*/  TRANSPOSE16x8_UB_UB (scalar_t__,scalar_t__,scalar_t__,scalar_t__,scalar_t__,scalar_t__,scalar_t__,scalar_t__,scalar_t__,scalar_t__,scalar_t__,scalar_t__,scalar_t__,scalar_t__,scalar_t__,scalar_t__,scalar_t__,scalar_t__,scalar_t__,scalar_t__,scalar_t__,scalar_t__,scalar_t__,scalar_t__) ; 
 int /*<<< orphan*/  VP8_LPF_FILTER4_4W (scalar_t__,scalar_t__,scalar_t__,scalar_t__,scalar_t__,scalar_t__) ; 
 int /*<<< orphan*/  VP8_MBFILTER (scalar_t__,scalar_t__,scalar_t__,scalar_t__,scalar_t__,scalar_t__,scalar_t__,scalar_t__) ; 
 int /*<<< orphan*/  VP8_SIMPLE_FILT (scalar_t__,scalar_t__,scalar_t__,scalar_t__,scalar_t__) ; 
 int /*<<< orphan*/  VP8_SIMPLE_MASK (scalar_t__,scalar_t__,scalar_t__,scalar_t__,scalar_t__,scalar_t__) ; 
 int /*<<< orphan*/  VP8_ST6x1_UB (int /*<<< orphan*/ ,int,int /*<<< orphan*/ ,int,int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  __msa_copy_u_d (int /*<<< orphan*/ ,int) ; 
 scalar_t__ __msa_fill_b (int) ; 
 scalar_t__ __msa_ilvl_b (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

void ff_vp8_v_loop_filter16_msa(uint8_t *src, ptrdiff_t pitch, int b_limit_in,
                                int limit_in, int thresh_in)
{
    uint8_t *temp_src;
    v16u8 p3, p2, p1, p0, q3, q2, q1, q0;
    v16u8 mask, hev, flat, thresh, limit, b_limit;

    b_limit = (v16u8) __msa_fill_b(b_limit_in);
    limit = (v16u8) __msa_fill_b(limit_in);
    thresh = (v16u8) __msa_fill_b(thresh_in);
    /* load vector elements */
    temp_src = src - (pitch << 2);
    LD_UB8(temp_src, pitch, p3, p2, p1, p0, q0, q1, q2, q3);
    LPF_MASK_HEV(p3, p2, p1, p0, q0, q1, q2, q3, limit, b_limit, thresh,
                 hev, mask, flat);
    VP8_MBFILTER(p2, p1, p0, q0, q1, q2, mask, hev);
    /* store vector elements */
    temp_src = src - 3 * pitch;
    ST_UB4(p2, p1, p0, q0, temp_src, pitch);
    temp_src += (4 * pitch);
    ST_UB2(q1, q2, temp_src, pitch);
}

void ff_vp8_v_loop_filter8uv_msa(uint8_t *src_u, uint8_t *src_v,
                                 ptrdiff_t pitch, int b_limit_in, int limit_in,
                                 int thresh_in)
{
    uint8_t *temp_src;
    uint64_t p2_d, p1_d, p0_d, q0_d, q1_d, q2_d;
    v16u8 p3, p2, p1, p0, q3, q2, q1, q0;
    v16u8 mask, hev, flat, thresh, limit, b_limit;
    v16u8 p3_u, p2_u, p1_u, p0_u, q3_u, q2_u, q1_u, q0_u;
    v16u8 p3_v, p2_v, p1_v, p0_v, q3_v, q2_v, q1_v, q0_v;

    b_limit = (v16u8) __msa_fill_b(b_limit_in);
    limit = (v16u8) __msa_fill_b(limit_in);
    thresh = (v16u8) __msa_fill_b(thresh_in);

    temp_src = src_u - (pitch << 2);
    LD_UB8(temp_src, pitch, p3_u, p2_u, p1_u, p0_u, q0_u, q1_u, q2_u, q3_u);
    temp_src = src_v - (pitch << 2);
    LD_UB8(temp_src, pitch, p3_v, p2_v, p1_v, p0_v, q0_v, q1_v, q2_v, q3_v);

    /* rht 8 element of p3 are u pixel and left 8 element of p3 are v pixel */
    ILVR_D4_UB(p3_v, p3_u, p2_v, p2_u, p1_v, p1_u, p0_v, p0_u, p3, p2, p1, p0);
    ILVR_D4_UB(q0_v, q0_u, q1_v, q1_u, q2_v, q2_u, q3_v, q3_u, q0, q1, q2, q3);
    LPF_MASK_HEV(p3, p2, p1, p0, q0, q1, q2, q3, limit, b_limit, thresh,
                 hev, mask, flat);
    VP8_MBFILTER(p2, p1, p0, q0, q1, q2, mask, hev);

    p2_d = __msa_copy_u_d((v2i64) p2, 0);
    p1_d = __msa_copy_u_d((v2i64) p1, 0);
    p0_d = __msa_copy_u_d((v2i64) p0, 0);
    q0_d = __msa_copy_u_d((v2i64) q0, 0);
    q1_d = __msa_copy_u_d((v2i64) q1, 0);
    q2_d = __msa_copy_u_d((v2i64) q2, 0);
    src_u -= (pitch * 3);
    SD4(p2_d, p1_d, p0_d, q0_d, src_u, pitch);
    src_u += 4 * pitch;
    SD(q1_d, src_u);
    src_u += pitch;
    SD(q2_d, src_u);

    p2_d = __msa_copy_u_d((v2i64) p2, 1);
    p1_d = __msa_copy_u_d((v2i64) p1, 1);
    p0_d = __msa_copy_u_d((v2i64) p0, 1);
    q0_d = __msa_copy_u_d((v2i64) q0, 1);
    q1_d = __msa_copy_u_d((v2i64) q1, 1);
    q2_d = __msa_copy_u_d((v2i64) q2, 1);
    src_v -= (pitch * 3);
    SD4(p2_d, p1_d, p0_d, q0_d, src_v, pitch);
    src_v += 4 * pitch;
    SD(q1_d, src_v);
    src_v += pitch;
    SD(q2_d, src_v);
}

void ff_vp8_h_loop_filter16_msa(uint8_t *src, ptrdiff_t pitch, int b_limit_in,
                                int limit_in, int thresh_in)
{
    uint8_t *temp_src;
    v16u8 p3, p2, p1, p0, q3, q2, q1, q0;
    v16u8 mask, hev, flat, thresh, limit, b_limit;
    v16u8 row0, row1, row2, row3, row4, row5, row6, row7, row8;
    v16u8 row9, row10, row11, row12, row13, row14, row15;
    v8i16 tmp0, tmp1, tmp2, tmp3, tmp4, tmp5, tmp6, tmp7;

    b_limit = (v16u8) __msa_fill_b(b_limit_in);
    limit = (v16u8) __msa_fill_b(limit_in);
    thresh = (v16u8) __msa_fill_b(thresh_in);
    temp_src = src - 4;
    LD_UB8(temp_src, pitch, row0, row1, row2, row3, row4, row5, row6, row7);
    temp_src += (8 * pitch);
    LD_UB8(temp_src, pitch,
           row8, row9, row10, row11, row12, row13, row14, row15);
    TRANSPOSE16x8_UB_UB(row0, row1, row2, row3, row4, row5, row6, row7,
                        row8, row9, row10, row11, row12, row13, row14, row15,
                        p3, p2, p1, p0, q0, q1, q2, q3);

    LPF_MASK_HEV(p3, p2, p1, p0, q0, q1, q2, q3, limit, b_limit, thresh,
                 hev, mask, flat);
    VP8_MBFILTER(p2, p1, p0, q0, q1, q2, mask, hev);
    ILVR_B2_SH(p1, p2, q0, p0, tmp0, tmp1);
    ILVRL_H2_SH(tmp1, tmp0, tmp3, tmp4);
    ILVL_B2_SH(p1, p2, q0, p0, tmp0, tmp1);
    ILVRL_H2_SH(tmp1, tmp0, tmp6, tmp7);
    ILVRL_B2_SH(q2, q1, tmp2, tmp5);

    temp_src = src - 3;
    VP8_ST6x1_UB(tmp3, 0, tmp2, 0, temp_src, 4);
    temp_src += pitch;
    VP8_ST6x1_UB(tmp3, 1, tmp2, 1, temp_src, 4);
    temp_src += pitch;
    VP8_ST6x1_UB(tmp3, 2, tmp2, 2, temp_src, 4);
    temp_src += pitch;
    VP8_ST6x1_UB(tmp3, 3, tmp2, 3, temp_src, 4);
    temp_src += pitch;
    VP8_ST6x1_UB(tmp4, 0, tmp2, 4, temp_src, 4);
    temp_src += pitch;
    VP8_ST6x1_UB(tmp4, 1, tmp2, 5, temp_src, 4);
    temp_src += pitch;
    VP8_ST6x1_UB(tmp4, 2, tmp2, 6, temp_src, 4);
    temp_src += pitch;
    VP8_ST6x1_UB(tmp4, 3, tmp2, 7, temp_src, 4);
    temp_src += pitch;
    VP8_ST6x1_UB(tmp6, 0, tmp5, 0, temp_src, 4);
    temp_src += pitch;
    VP8_ST6x1_UB(tmp6, 1, tmp5, 1, temp_src, 4);
    temp_src += pitch;
    VP8_ST6x1_UB(tmp6, 2, tmp5, 2, temp_src, 4);
    temp_src += pitch;
    VP8_ST6x1_UB(tmp6, 3, tmp5, 3, temp_src, 4);
    temp_src += pitch;
    VP8_ST6x1_UB(tmp7, 0, tmp5, 4, temp_src, 4);
    temp_src += pitch;
    VP8_ST6x1_UB(tmp7, 1, tmp5, 5, temp_src, 4);
    temp_src += pitch;
    VP8_ST6x1_UB(tmp7, 2, tmp5, 6, temp_src, 4);
    temp_src += pitch;
    VP8_ST6x1_UB(tmp7, 3, tmp5, 7, temp_src, 4);
}

void ff_vp8_h_loop_filter8uv_msa(uint8_t *src_u, uint8_t *src_v,
                                 ptrdiff_t pitch, int b_limit_in, int limit_in,
                                 int thresh_in)
{
    v16u8 p3, p2, p1, p0, q3, q2, q1, q0;
    v16u8 mask, hev, flat, thresh, limit, b_limit;
    v16u8 row0, row1, row2, row3, row4, row5, row6, row7, row8;
    v16u8 row9, row10, row11, row12, row13, row14, row15;
    v8i16 tmp0, tmp1, tmp2, tmp3, tmp4, tmp5, tmp6, tmp7;

    b_limit = (v16u8) __msa_fill_b(b_limit_in);
    limit = (v16u8) __msa_fill_b(limit_in);
    thresh = (v16u8) __msa_fill_b(thresh_in);

    LD_UB8(src_u - 4, pitch, row0, row1, row2, row3, row4, row5, row6, row7);
    LD_UB8(src_v - 4, pitch,
           row8, row9, row10, row11, row12, row13, row14, row15);
    TRANSPOSE16x8_UB_UB(row0, row1, row2, row3, row4, row5, row6, row7,
                        row8, row9, row10, row11, row12, row13, row14, row15,
                        p3, p2, p1, p0, q0, q1, q2, q3);

    LPF_MASK_HEV(p3, p2, p1, p0, q0, q1, q2, q3, limit, b_limit, thresh,
                 hev, mask, flat);
    VP8_MBFILTER(p2, p1, p0, q0, q1, q2, mask, hev);

    ILVR_B2_SH(p1, p2, q0, p0, tmp0, tmp1);
    ILVRL_H2_SH(tmp1, tmp0, tmp3, tmp4);
    ILVL_B2_SH(p1, p2, q0, p0, tmp0, tmp1);
    ILVRL_H2_SH(tmp1, tmp0, tmp6, tmp7);
    ILVRL_B2_SH(q2, q1, tmp2, tmp5);

    src_u -= 3;
    VP8_ST6x1_UB(tmp3, 0, tmp2, 0, src_u, 4);
    src_u += pitch;
    VP8_ST6x1_UB(tmp3, 1, tmp2, 1, src_u, 4);
    src_u += pitch;
    VP8_ST6x1_UB(tmp3, 2, tmp2, 2, src_u, 4);
    src_u += pitch;
    VP8_ST6x1_UB(tmp3, 3, tmp2, 3, src_u, 4);
    src_u += pitch;
    VP8_ST6x1_UB(tmp4, 0, tmp2, 4, src_u, 4);
    src_u += pitch;
    VP8_ST6x1_UB(tmp4, 1, tmp2, 5, src_u, 4);
    src_u += pitch;
    VP8_ST6x1_UB(tmp4, 2, tmp2, 6, src_u, 4);
    src_u += pitch;
    VP8_ST6x1_UB(tmp4, 3, tmp2, 7, src_u, 4);

    src_v -= 3;
    VP8_ST6x1_UB(tmp6, 0, tmp5, 0, src_v, 4);
    src_v += pitch;
    VP8_ST6x1_UB(tmp6, 1, tmp5, 1, src_v, 4);
    src_v += pitch;
    VP8_ST6x1_UB(tmp6, 2, tmp5, 2, src_v, 4);
    src_v += pitch;
    VP8_ST6x1_UB(tmp6, 3, tmp5, 3, src_v, 4);
    src_v += pitch;
    VP8_ST6x1_UB(tmp7, 0, tmp5, 4, src_v, 4);
    src_v += pitch;
    VP8_ST6x1_UB(tmp7, 1, tmp5, 5, src_v, 4);
    src_v += pitch;
    VP8_ST6x1_UB(tmp7, 2, tmp5, 6, src_v, 4);
    src_v += pitch;
    VP8_ST6x1_UB(tmp7, 3, tmp5, 7, src_v, 4);
}

void ff_vp8_v_loop_filter_simple_msa(uint8_t *src, ptrdiff_t pitch,
                                     int b_limit_ptr)
{
    v16u8 p1, p0, q1, q0;
    v16u8 mask, b_limit;

    b_limit = (v16u8) __msa_fill_b(b_limit_ptr);
    /* load vector elements */
    LD_UB4(src - (pitch << 1), pitch, p1, p0, q0, q1);
    VP8_SIMPLE_MASK(p1, p0, q0, q1, b_limit, mask);
    VP8_SIMPLE_FILT(p1, p0, q0, q1, mask);
    ST_UB2(p0, q0, (src - pitch), pitch);
}

void ff_vp8_h_loop_filter_simple_msa(uint8_t *src, ptrdiff_t pitch,
                                     int b_limit_ptr)
{
    uint8_t *temp_src;
    v16u8 p1, p0, q1, q0;
    v16u8 mask, b_limit;
    v16u8 row0, row1, row2, row3, row4, row5, row6, row7, row8;
    v16u8 row9, row10, row11, row12, row13, row14, row15;
    v8i16 tmp0, tmp1;

    b_limit = (v16u8) __msa_fill_b(b_limit_ptr);
    temp_src = src - 2;
    LD_UB8(temp_src, pitch, row0, row1, row2, row3, row4, row5, row6, row7);
    temp_src += (8 * pitch);
    LD_UB8(temp_src, pitch,
           row8, row9, row10, row11, row12, row13, row14, row15);
    TRANSPOSE16x4_UB_UB(row0, row1, row2, row3, row4, row5, row6, row7,
                        row8, row9, row10, row11, row12, row13, row14, row15,
                        p1, p0, q0, q1);
    VP8_SIMPLE_MASK(p1, p0, q0, q1, b_limit, mask);
    VP8_SIMPLE_FILT(p1, p0, q0, q1, mask);
    ILVRL_B2_SH(q0, p0, tmp1, tmp0);

    src -= 1;
    ST2x4_UB(tmp1, 0, src, pitch);
    src += 4 * pitch;
    ST2x4_UB(tmp1, 4, src, pitch);
    src += 4 * pitch;
    ST2x4_UB(tmp0, 0, src, pitch);
    src += 4 * pitch;
    ST2x4_UB(tmp0, 4, src, pitch);
    src += 4 * pitch;
}

void ff_vp8_v_loop_filter8uv_inner_msa(uint8_t *src_u, uint8_t *src_v,
                                       ptrdiff_t pitch, int b_limit_in,
                                       int limit_in, int thresh_in)
{
    uint64_t p1_d, p0_d, q0_d, q1_d;
    v16u8 p3, p2, p1, p0, q3, q2, q1, q0;
    v16u8 mask, hev, flat, thresh, limit, b_limit;
    v16u8 p3_u, p2_u, p1_u, p0_u, q3_u, q2_u, q1_u, q0_u;
    v16u8 p3_v, p2_v, p1_v, p0_v, q3_v, q2_v, q1_v, q0_v;

    thresh = (v16u8) __msa_fill_b(thresh_in);
    limit = (v16u8) __msa_fill_b(limit_in);
    b_limit = (v16u8) __msa_fill_b(b_limit_in);

    src_u = src_u - (pitch << 2);
    LD_UB8(src_u, pitch, p3_u, p2_u, p1_u, p0_u, q0_u, q1_u, q2_u, q3_u);
    src_u += (5 * pitch);
    src_v = src_v - (pitch << 2);
    LD_UB8(src_v, pitch, p3_v, p2_v, p1_v, p0_v, q0_v, q1_v, q2_v, q3_v);
    src_v += (5 * pitch);

    /* right 8 element of p3 are u pixel and
       left 8 element of p3 are v pixel */
    ILVR_D4_UB(p3_v, p3_u, p2_v, p2_u, p1_v, p1_u, p0_v, p0_u, p3, p2, p1, p0);
    ILVR_D4_UB(q0_v, q0_u, q1_v, q1_u, q2_v, q2_u, q3_v, q3_u, q0, q1, q2, q3);
    LPF_MASK_HEV(p3, p2, p1, p0, q0, q1, q2, q3, limit, b_limit, thresh,
                 hev, mask, flat);
    VP8_LPF_FILTER4_4W(p1, p0, q0, q1, mask, hev);

    p1_d = __msa_copy_u_d((v2i64) p1, 0);
    p0_d = __msa_copy_u_d((v2i64) p0, 0);
    q0_d = __msa_copy_u_d((v2i64) q0, 0);
    q1_d = __msa_copy_u_d((v2i64) q1, 0);
    SD4(q1_d, q0_d, p0_d, p1_d, src_u, (- pitch));

    p1_d = __msa_copy_u_d((v2i64) p1, 1);
    p0_d = __msa_copy_u_d((v2i64) p0, 1);
    q0_d = __msa_copy_u_d((v2i64) q0, 1);
    q1_d = __msa_copy_u_d((v2i64) q1, 1);
    SD4(q1_d, q0_d, p0_d, p1_d, src_v, (- pitch));
}

void ff_vp8_h_loop_filter8uv_inner_msa(uint8_t *src_u, uint8_t *src_v,
                                       ptrdiff_t pitch, int b_limit_in,
                                       int limit_in, int thresh_in)
{
    uint8_t *temp_src_u, *temp_src_v;
    v16u8 p3, p2, p1, p0, q3, q2, q1, q0;
    v16u8 mask, hev, flat, thresh, limit, b_limit;
    v16u8 row0, row1, row2, row3, row4, row5, row6, row7, row8;
    v16u8 row9, row10, row11, row12, row13, row14, row15;
    v4i32 tmp0, tmp1, tmp2, tmp3, tmp4, tmp5;

    thresh = (v16u8) __msa_fill_b(thresh_in);
    limit = (v16u8) __msa_fill_b(limit_in);
    b_limit = (v16u8) __msa_fill_b(b_limit_in);

    LD_UB8(src_u - 4, pitch, row0, row1, row2, row3, row4, row5, row6, row7);
    LD_UB8(src_v - 4, pitch,
           row8, row9, row10, row11, row12, row13, row14, row15);
    TRANSPOSE16x8_UB_UB(row0, row1, row2, row3, row4, row5, row6, row7,
                        row8, row9, row10, row11, row12, row13, row14, row15,
                        p3, p2, p1, p0, q0, q1, q2, q3);

    LPF_MASK_HEV(p3, p2, p1, p0, q0, q1, q2, q3, limit, b_limit, thresh,
                 hev, mask, flat);
    VP8_LPF_FILTER4_4W(p1, p0, q0, q1, mask, hev);
    ILVR_B2_SW(p0, p1, q1, q0, tmp0, tmp1);
    ILVRL_H2_SW(tmp1, tmp0, tmp2, tmp3);
    tmp0 = (v4i32) __msa_ilvl_b((v16i8) p0, (v16i8) p1);
    tmp1 = (v4i32) __msa_ilvl_b((v16i8) q1, (v16i8) q0);
    ILVRL_H2_SW(tmp1, tmp0, tmp4, tmp5);

    temp_src_u = src_u - 2;
    ST4x4_UB(tmp2, tmp2, 0, 1, 2, 3, temp_src_u, pitch);
    temp_src_u += 4 * pitch;
    ST4x4_UB(tmp3, tmp3, 0, 1, 2, 3, temp_src_u, pitch);

    temp_src_v = src_v - 2;
    ST4x4_UB(tmp4, tmp4, 0, 1, 2, 3, temp_src_v, pitch);
    temp_src_v += 4 * pitch;
    ST4x4_UB(tmp5, tmp5, 0, 1, 2, 3, temp_src_v, pitch);
}

void ff_vp8_v_loop_filter16_inner_msa(uint8_t *src, ptrdiff_t pitch,
                                      int32_t e, int32_t i, int32_t h)
{
    v16u8 mask, hev, flat;
    v16u8 thresh, b_limit, limit;
    v16u8 p3, p2, p1, p0, q3, q2, q1, q0;

    /* load vector elements */
    LD_UB8((src - 4 * pitch), pitch, p3, p2, p1, p0, q0, q1, q2, q3);
    thresh = (v16u8) __msa_fill_b(h);
    b_limit = (v16u8) __msa_fill_b(e);
    limit = (v16u8) __msa_fill_b(i);

    LPF_MASK_HEV(p3, p2, p1, p0, q0, q1, q2, q3, limit, b_limit, thresh,
                 hev, mask, flat);
    VP8_LPF_FILTER4_4W(p1, p0, q0, q1, mask, hev);

    ST_UB4(p1, p0, q0, q1, (src - 2 * pitch), pitch);
}

void ff_vp8_h_loop_filter16_inner_msa(uint8_t *src, ptrdiff_t pitch,
                                      int32_t e, int32_t i, int32_t h)
{
    v16u8 mask, hev, flat;
    v16u8 thresh, b_limit, limit;
    v16u8 p3, p2, p1, p0, q3, q2, q1, q0;
    v16u8 row0, row1, row2, row3, row4, row5, row6, row7;
    v16u8 row8, row9, row10, row11, row12, row13, row14, row15;
    v8i16 tmp0, tmp1, tmp2, tmp3, tmp4, tmp5;

    LD_UB8(src - 4, pitch, row0, row1, row2, row3, row4, row5, row6, row7);
    LD_UB8(src - 4 + (8 * pitch), pitch,
           row8, row9, row10, row11, row12, row13, row14, row15);
    TRANSPOSE16x8_UB_UB(row0, row1, row2, row3, row4, row5, row6, row7,
                        row8, row9, row10, row11, row12, row13, row14, row15,
                        p3, p2, p1, p0, q0, q1, q2, q3);

    thresh = (v16u8) __msa_fill_b(h);
    b_limit = (v16u8) __msa_fill_b(e);
    limit = (v16u8) __msa_fill_b(i);

    LPF_MASK_HEV(p3, p2, p1, p0, q0, q1, q2, q3, limit, b_limit, thresh,
                 hev, mask, flat);
    VP8_LPF_FILTER4_4W(p1, p0, q0, q1, mask, hev);
    ILVR_B2_SH(p0, p1, q1, q0, tmp0, tmp1);
    ILVRL_H2_SH(tmp1, tmp0, tmp2, tmp3);
    ILVL_B2_SH(p0, p1, q1, q0, tmp0, tmp1);
    ILVRL_H2_SH(tmp1, tmp0, tmp4, tmp5);

    src -= 2;
    ST4x8_UB(tmp2, tmp3, src, pitch);
    src += (8 * pitch);
    ST4x8_UB(tmp4, tmp5, src, pitch);
}

