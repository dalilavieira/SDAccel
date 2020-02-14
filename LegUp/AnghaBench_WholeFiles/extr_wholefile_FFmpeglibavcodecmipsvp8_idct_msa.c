#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_32__   TYPE_1__ ;

/* Type definitions */
typedef  int v8i16 ;
typedef  int v4i32 ;
struct TYPE_32__ {int member_1; int member_2; int member_3; int member_4; int member_5; int member_6; int member_7; int /*<<< orphan*/  member_15; int /*<<< orphan*/  member_14; int /*<<< orphan*/  member_13; int /*<<< orphan*/  member_12; int /*<<< orphan*/  member_11; int /*<<< orphan*/  member_10; int /*<<< orphan*/  member_9; int /*<<< orphan*/  member_8; int /*<<< orphan*/  member_0; } ;
typedef  TYPE_1__ v16i8 ;
typedef  int /*<<< orphan*/  uint8_t ;
typedef  int ptrdiff_t ;
typedef  scalar_t__ int16_t ;

/* Variables and functions */
 int /*<<< orphan*/  ADD4 (int,int,int,int,int,int,int,int,int,int,int,int) ; 
 int /*<<< orphan*/  BUTTERFLY_4 (int,int,int,int,int,int,int,int) ; 
 int /*<<< orphan*/  CLIP_SH4_0_255 (int,int,int,int) ; 
 int CLIP_SW_0_255 (int) ; 
 int /*<<< orphan*/  ILVR_B4_SH (TYPE_1__,TYPE_1__,TYPE_1__,TYPE_1__,TYPE_1__,TYPE_1__,TYPE_1__,TYPE_1__,int,int,int,int) ; 
 int /*<<< orphan*/  ILVR_B4_SW (TYPE_1__,TYPE_1__,TYPE_1__,TYPE_1__,TYPE_1__,TYPE_1__,TYPE_1__,TYPE_1__,int,int,int,int) ; 
 int /*<<< orphan*/  ILVR_H4_SW (TYPE_1__,int,TYPE_1__,int,TYPE_1__,int,TYPE_1__,int,int,int,int,int) ; 
 int /*<<< orphan*/  LD_SB4 (int /*<<< orphan*/ *,int,TYPE_1__,TYPE_1__,TYPE_1__,TYPE_1__) ; 
 int /*<<< orphan*/  LD_SH2 (scalar_t__*,int,int,int) ; 
 int /*<<< orphan*/  SRARI_W4_SW (int,int,int,int,int) ; 
 int /*<<< orphan*/  SRA_4V (int,int,int,int,int) ; 
 int /*<<< orphan*/  ST4x4_UB (TYPE_1__,TYPE_1__,int /*<<< orphan*/ ,int,int /*<<< orphan*/ ,int,int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  TRANSPOSE4x4_SW_SW (int,int,int,int,int,int,int,int) ; 
 int /*<<< orphan*/  UNPCK_SH_SW (int,int,int) ; 
 int /*<<< orphan*/  VP8_IDCT_1D_W (int,int,int,int,int,int,int,int) ; 
 int /*<<< orphan*/  VSHF_B2_SB (int,int,int,int,TYPE_1__,TYPE_1__,TYPE_1__,TYPE_1__) ; 
 scalar_t__ __msa_copy_s_h (int,int) ; 
 int __msa_fill_h (scalar_t__) ; 
 int __msa_srari_h (int,int) ; 
 int /*<<< orphan*/  memset (scalar_t__*,int /*<<< orphan*/ ,int) ; 

void ff_vp8_idct_add_msa(uint8_t *dst, int16_t input[16], ptrdiff_t stride)
{
    v8i16 input0, input1;
    v4i32 in0, in1, in2, in3, hz0, hz1, hz2, hz3, vt0, vt1, vt2, vt3;
    v4i32 res0, res1, res2, res3;
    v16i8 zero = { 0 };
    v16i8 pred0, pred1, pred2, pred3, dest0, dest1;
    v16i8 mask = { 0, 4, 8, 12, 16, 20, 24, 28, 0, 0, 0, 0, 0, 0, 0, 0 };

    /* load short vector elements of 4x4 block */
    LD_SH2(input, 8, input0, input1);
    UNPCK_SH_SW(input0, in0, in1);
    UNPCK_SH_SW(input1, in2, in3);
    VP8_IDCT_1D_W(in0, in1, in2, in3, hz0, hz1, hz2, hz3);
    /* transpose the block */
    TRANSPOSE4x4_SW_SW(hz0, hz1, hz2, hz3, hz0, hz1, hz2, hz3);
    VP8_IDCT_1D_W(hz0, hz1, hz2, hz3, vt0, vt1, vt2, vt3);
    SRARI_W4_SW(vt0, vt1, vt2, vt3, 3);
    /* transpose the block */
    TRANSPOSE4x4_SW_SW(vt0, vt1, vt2, vt3, vt0, vt1, vt2, vt3);
    LD_SB4(dst, stride, pred0, pred1, pred2, pred3);
    ILVR_B4_SW(zero, pred0, zero, pred1, zero, pred2, zero, pred3,
               res0, res1, res2, res3);
    ILVR_H4_SW(zero, res0, zero, res1, zero, res2, zero, res3,
               res0, res1, res2, res3);
    ADD4(res0, vt0, res1, vt1, res2, vt2, res3, vt3, res0, res1, res2, res3);
    res0 = CLIP_SW_0_255(res0);
    res1 = CLIP_SW_0_255(res1);
    res2 = CLIP_SW_0_255(res2);
    res3 = CLIP_SW_0_255(res3);
    VSHF_B2_SB(res0, res1, res2, res3, mask, mask, dest0, dest1);
    ST4x4_UB(dest0, dest1, 0, 1, 0, 1, dst, stride);

    memset(input, 0, 4 * 4 * sizeof(*input));
}

void ff_vp8_idct_dc_add_msa(uint8_t *dst, int16_t in_dc[16], ptrdiff_t stride)
{
    v8i16 vec;
    v8i16 res0, res1, res2, res3;
    v16i8 zero = { 0 };
    v16i8 pred0, pred1, pred2, pred3, dest0, dest1;
    v16i8 mask = { 0, 2, 4, 6, 16, 18, 20, 22, 0, 0, 0, 0, 0, 0, 0, 0 };

    vec = __msa_fill_h(in_dc[0]);
    vec = __msa_srari_h(vec, 3);
    LD_SB4(dst, stride, pred0, pred1, pred2, pred3);
    ILVR_B4_SH(zero, pred0, zero, pred1, zero, pred2, zero, pred3,
               res0, res1, res2, res3);
    ADD4(res0, vec, res1, vec, res2, vec, res3, vec, res0, res1, res2, res3);
    CLIP_SH4_0_255(res0, res1, res2, res3);
    VSHF_B2_SB(res0, res1, res2, res3, mask, mask, dest0, dest1);
    ST4x4_UB(dest0, dest1, 0, 1, 0, 1, dst, stride);

    in_dc[0] = 0;
}

void ff_vp8_luma_dc_wht_msa(int16_t block[4][4][16], int16_t input[16])
{
    int16_t *mb_dq_coeff = &block[0][0][0];
    v8i16 input0, input1;
    v4i32 in0, in1, in2, in3, a1, b1, c1, d1;
    v4i32 hz0, hz1, hz2, hz3, vt0, vt1, vt2, vt3;

    /* load short vector elements of 4x4 block */
    LD_SH2(input, 8, input0, input1);
    UNPCK_SH_SW(input0, in0, in1);
    UNPCK_SH_SW(input1, in2, in3);
    BUTTERFLY_4(in0, in1, in2, in3, a1, b1, c1, d1);
    BUTTERFLY_4(a1, d1, c1, b1, hz0, hz1, hz3, hz2);
    /* transpose the block */
    TRANSPOSE4x4_SW_SW(hz0, hz1, hz2, hz3, hz0, hz1, hz2, hz3);
    BUTTERFLY_4(hz0, hz1, hz2, hz3, a1, b1, c1, d1);
    BUTTERFLY_4(a1, d1, c1, b1, vt0, vt1, vt3, vt2);
    ADD4(vt0, 3, vt1, 3, vt2, 3, vt3, 3, vt0, vt1, vt2, vt3);
    SRA_4V(vt0, vt1, vt2, vt3, 3);
    mb_dq_coeff[0] = __msa_copy_s_h((v8i16) vt0, 0);
    mb_dq_coeff[16] = __msa_copy_s_h((v8i16) vt1, 0);
    mb_dq_coeff[32] = __msa_copy_s_h((v8i16) vt2, 0);
    mb_dq_coeff[48] = __msa_copy_s_h((v8i16) vt3, 0);
    mb_dq_coeff[64] = __msa_copy_s_h((v8i16) vt0, 2);
    mb_dq_coeff[80] = __msa_copy_s_h((v8i16) vt1, 2);
    mb_dq_coeff[96] = __msa_copy_s_h((v8i16) vt2, 2);
    mb_dq_coeff[112] = __msa_copy_s_h((v8i16) vt3, 2);
    mb_dq_coeff[128] = __msa_copy_s_h((v8i16) vt0, 4);
    mb_dq_coeff[144] = __msa_copy_s_h((v8i16) vt1, 4);
    mb_dq_coeff[160] = __msa_copy_s_h((v8i16) vt2, 4);
    mb_dq_coeff[176] = __msa_copy_s_h((v8i16) vt3, 4);
    mb_dq_coeff[192] = __msa_copy_s_h((v8i16) vt0, 6);
    mb_dq_coeff[208] = __msa_copy_s_h((v8i16) vt1, 6);
    mb_dq_coeff[224] = __msa_copy_s_h((v8i16) vt2, 6);
    mb_dq_coeff[240] = __msa_copy_s_h((v8i16) vt3, 6);

    memset(input, 0, 4 * 4 * sizeof(int16_t));
}

void ff_vp8_idct_dc_add4y_msa(uint8_t *dst, int16_t block[4][16],
                              ptrdiff_t stride)
{
    ff_vp8_idct_dc_add_msa(dst, &block[0][0], stride);
    ff_vp8_idct_dc_add_msa(dst + 4, &block[1][0], stride);
    ff_vp8_idct_dc_add_msa(dst + 8, &block[2][0], stride);
    ff_vp8_idct_dc_add_msa(dst + 12, &block[3][0], stride);
}

void ff_vp8_idct_dc_add4uv_msa(uint8_t *dst, int16_t block[4][16],
                               ptrdiff_t stride)
{
    ff_vp8_idct_dc_add_msa(dst, &block[0][0], stride);
    ff_vp8_idct_dc_add_msa(dst + 4, &block[1][0], stride);
    ff_vp8_idct_dc_add_msa(dst + stride * 4, &block[2][0], stride);
    ff_vp8_idct_dc_add_msa(dst + stride * 4 + 4, &block[3][0], stride);
}

