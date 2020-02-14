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
typedef  int uint16_t ;
typedef  int /*<<< orphan*/  ptrdiff_t ;

/* Variables and functions */
 int /*<<< orphan*/  DCT_TEMPLATE (int*,int,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  SOP_COL ; 
 int /*<<< orphan*/  SOP_ROW ; 
 int av_clip_uint8 (int) ; 
 int* chroma_quant ; 
 int* luma_quant ; 

void ff_mss34_gen_quant_mat(uint16_t *qmat, int quality, int luma)
{
    int i;
    const uint8_t *qsrc = luma ? luma_quant : chroma_quant;

    if (quality >= 50) {
        int scale = 200 - 2 * quality;

        for (i = 0; i < 64; i++)
            qmat[i] = (qsrc[i] * scale + 50) / 100;
    } else {
        for (i = 0; i < 64; i++)
            qmat[i] = (5000 * qsrc[i] / quality + 50) / 100;
    }
}

void ff_mss34_dct_put(uint8_t *dst, ptrdiff_t stride, int *block)
{
    int i, j;
    int *ptr;

    ptr = block;
    for (i = 0; i < 8; i++) {
        DCT_TEMPLATE(ptr, 1, SOP_ROW, 13);
        ptr += 8;
    }

    ptr = block;
    for (i = 0; i < 8; i++) {
        DCT_TEMPLATE(ptr, 8, SOP_COL, 22);
        ptr++;
    }

    ptr = block;
    for (j = 0; j < 8; j++) {
        for (i = 0; i < 8; i++)
            dst[i] = av_clip_uint8(ptr[i] + 128);
        dst += stride;
        ptr += 8;
    }
}

