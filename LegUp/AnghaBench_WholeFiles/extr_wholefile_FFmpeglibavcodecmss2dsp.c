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
 int /*<<< orphan*/  memcpy (int*,int*,int) ; 
 int /*<<< orphan*/  mss2_blit_wmv9_template (int*,int,int,int,int,int const*,int,int const*,int,int const*,int const*,int,int,int) ; 

__attribute__((used)) static void mss2_blit_wmv9_c(uint8_t *dst, ptrdiff_t dst_stride,
                             const uint8_t *srcy, ptrdiff_t srcy_stride,
                             const uint8_t *srcu, const uint8_t *srcv,
                             ptrdiff_t srcuv_stride, int w, int h)
{
    mss2_blit_wmv9_template(dst, dst_stride, 0, 0,
                            0, NULL, 0,
                            srcy, srcy_stride,
                            srcu, srcv, srcuv_stride,
                            w, h);
}

__attribute__((used)) static void mss2_blit_wmv9_masked_c(uint8_t *dst, ptrdiff_t dst_stride,
                                    int maskcolor, const uint8_t *mask,
                                    ptrdiff_t mask_stride,
                                    const uint8_t *srcy, ptrdiff_t srcy_stride,
                                    const uint8_t *srcu, const uint8_t *srcv,
                                    ptrdiff_t srcuv_stride, int w, int h)
{
    mss2_blit_wmv9_template(dst, dst_stride, 0, 1,
                            maskcolor, mask, mask_stride,
                            srcy, srcy_stride,
                            srcu, srcv, srcuv_stride,
                            w, h);
}

__attribute__((used)) static void mss2_gray_fill_masked_c(uint8_t *dst, ptrdiff_t dst_stride,
                                    int maskcolor, const uint8_t *mask,
                                    ptrdiff_t mask_stride, int w, int h)
{
    mss2_blit_wmv9_template(dst, dst_stride, 1, 1,
                            maskcolor, mask, mask_stride,
                            NULL, 0,
                            NULL, NULL, 0,
                            w, h);
}

__attribute__((used)) static void upsample_plane_c(uint8_t *plane, ptrdiff_t plane_stride, int w, int h)
{
    uint8_t *src1, *src2, *dst1, *dst2, *p, a, b;
    int i, j;

    if(!w || !h)
        return;

    w += (w & 1);
    h += (h & 1);

    j = h - 1;

    memcpy(plane + plane_stride *  j,
           plane + plane_stride * (j >> 1),
           w);

    while ((j -= 2) > 0) {
        dst1 = plane + plane_stride *  (j + 1);
        dst2 = plane + plane_stride *   j;
        src1 = plane + plane_stride * ((j + 1) >> 1);
        src2 = plane + plane_stride * ( j      >> 1);

        for (i = (w - 1) >> 1; i >= 0; i--) {
            a = src1[i];
            b = src2[i];
            dst1[i] = (3 * a + b + 2) >> 2;
            dst2[i] = (a + 3 * b + 2) >> 2;
        }
    }

    for (j = h - 1; j >= 0; j--) {
        p = plane + plane_stride * j;
        i = w - 1;

        p[i] = p[i >> 1];

        while ((i -= 2) > 0) {
            a = p[ i      >> 1];
            b = p[(i + 1) >> 1];
            p[i]     = (3 * a + b + 1) >> 2;
            p[i + 1] = (a + 3 * b + 1) >> 2;
        }
    }
}

