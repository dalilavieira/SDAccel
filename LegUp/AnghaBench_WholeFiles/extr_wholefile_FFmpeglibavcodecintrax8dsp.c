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
typedef  int uint32_t ;
typedef  int uint16_t ;
typedef  int ptrdiff_t ;
typedef  int int32_t ;

/* Variables and functions */
 int FFABS (int) ; 
 int FFMAX (int,int) ; 
 int FFMIN (int,int) ; 
 unsigned int abs (int) ; 
 int area1 ; 
 int area2 ; 
 int area3 ; 
 int area4 ; 
 int area5 ; 
 int area6 ; 
 int /*<<< orphan*/  memcpy (int*,int*,int) ; 
 int /*<<< orphan*/  memset (int*,int,int) ; 
 int* zero_prediction_weights ; 

__attribute__((used)) static void x8_setup_spatial_compensation(uint8_t *src, uint8_t *dst,
                                          ptrdiff_t stride, int *range,
                                          int *psum, int edges)
{
    uint8_t *ptr;
    int sum;
    int i;
    int min_pix, max_pix;
    uint8_t c;

    if ((edges & 3) == 3) {
        *psum  = 0x80 * (8 + 1 + 8 + 2);
        *range = 0;
        memset(dst, 0x80, 16 + 1 + 16 + 8);
        /* this triggers flat_dc for sure. flat_dc avoids all (other)
         * prediction modes, but requires dc_level decoding. */
        return;
    }

    min_pix = 256;
    max_pix = -1;

    sum = 0;

    if (!(edges & 1)) { // (mb_x != 0) // there is previous block on this row
        ptr = src - 1; // left column, area 2
        for (i = 7; i >= 0; i--) {
            c              = *(ptr - 1); // area1, same mb as area2, no need to check
            dst[area1 + i] = c;
            c              = *ptr;

            sum           += c;
            min_pix        = FFMIN(min_pix, c);
            max_pix        = FFMAX(max_pix, c);
            dst[area2 + i] = c;

            ptr += stride;
        }
    }

    if (!(edges & 2)) { // (mb_y != 0) // there is row above
        ptr = src - stride; // top line
        for (i = 0; i < 8; i++) {
            c       = *(ptr + i);
            sum    += c;
            min_pix = FFMIN(min_pix, c);
            max_pix = FFMAX(max_pix, c);
        }
        if (edges & 4) { // last block on the row?
            memset(dst + area5, c, 8); // set with last pixel fr
            memcpy(dst + area4, ptr, 8);
        } else {
            memcpy(dst + area4, ptr, 16); // both area4 and 5
        }
        // area6 always present in the above block
        memcpy(dst + area6, ptr - stride, 8);
    }
    // now calculate the stuff we need
    if (edges & 3) { // mb_x ==0 || mb_y == 0) {
        int avg = (sum + 4) >> 3;

        if (edges & 1) // (mb_x == 0) { // implies mb_y !=0
            memset(dst + area1, avg, 8 + 8 + 1); // areas 1, 2, 3 are averaged
        else // implies y == 0 x != 0
            memset(dst + area3, avg, 1 + 16 + 8); // areas 3, 4, 5, 6

        sum += avg * 9;
    } else {
        // the edge pixel, in the top line and left column
        uint8_t c = *(src - 1 - stride);
        dst[area3] = c;
        sum       += c;
        // edge pixel is not part of min/max
    }
    *range = max_pix - min_pix;
    sum   += *(dst + area5) + *(dst + area5 + 1);
    *psum  = sum;
}

__attribute__((used)) static void spatial_compensation_0(uint8_t *src, uint8_t *dst, ptrdiff_t stride)
{
    int i, j;
    int x, y;
    unsigned int p; // power divided by 2
    int a;
    uint16_t left_sum[2][8] = { { 0 } };
    uint16_t  top_sum[2][8] = { { 0 } };

    for (i = 0; i < 8; i++) {
        a = src[area2 + 7 - i] << 4;
        for (j = 0; j < 8; j++) {
            p                   = abs(i - j);
            left_sum[p & 1][j] += a >> (p >> 1);
        }
    }

    for (i = 0; i < 8; i++) {
        a = src[area4 + i] << 4;
        for (j = 0; j < 8; j++) {
            p                  = abs(i - j);
            top_sum[p & 1][j] += a >> (p >> 1);
        }
    }
    for (; i < 10; i++) {
        a = src[area4 + i] << 4;
        for (j = 5; j < 8; j++) {
            p                  = abs(i - j);
            top_sum[p & 1][j] += a >> (p >> 1);
        }
    }
    for (; i < 12; i++) {
        a = src[area4 + i] << 4;
        for (j = 7; j < 8; j++) {
            p                  = abs(i - j);
            top_sum[p & 1][j] += a >> (p >> 1);
        }
    }

    for (i = 0; i < 8; i++) {
        top_sum[0][i]  +=  (top_sum[1][i] * 181 + 128) >> 8; // 181 is sqrt(2)/2
        left_sum[0][i] += (left_sum[1][i] * 181 + 128) >> 8;
    }
    for (y = 0; y < 8; y++) {
        for (x = 0; x < 8; x++)
            dst[x] = ((uint32_t)  top_sum[0][x] * zero_prediction_weights[y * 16 + x * 2 + 0] +
                      (uint32_t) left_sum[0][y] * zero_prediction_weights[y * 16 + x * 2 + 1] +
                      0x8000) >> 16;
        dst += stride;
    }
}

__attribute__((used)) static void spatial_compensation_1(uint8_t *src, uint8_t *dst, ptrdiff_t stride)
{
    int x, y;

    for (y = 0; y < 8; y++) {
        for (x = 0; x < 8; x++)
            dst[x] = src[area4 + FFMIN(2 * y + x + 2, 15)];
        dst += stride;
    }
}

__attribute__((used)) static void spatial_compensation_2(uint8_t *src, uint8_t *dst, ptrdiff_t stride)
{
    int x, y;

    for (y = 0; y < 8; y++) {
        for (x = 0; x < 8; x++)
            dst[x] = src[area4 + 1 + y + x];
        dst += stride;
    }
}

__attribute__((used)) static void spatial_compensation_3(uint8_t *src, uint8_t *dst, ptrdiff_t stride)
{
    int x, y;

    for (y = 0; y < 8; y++) {
        for (x = 0; x < 8; x++)
            dst[x] = src[area4 + ((y + 1) >> 1) + x];
        dst += stride;
    }
}

__attribute__((used)) static void spatial_compensation_4(uint8_t *src, uint8_t *dst, ptrdiff_t stride)
{
    int x, y;

    for (y = 0; y < 8; y++) {
        for (x = 0; x < 8; x++)
            dst[x] = (src[area4 + x] + src[area6 + x] + 1) >> 1;
        dst += stride;
    }
}

__attribute__((used)) static void spatial_compensation_5(uint8_t *src, uint8_t *dst, ptrdiff_t stride)
{
    int x, y;

    for (y = 0; y < 8; y++) {
        for (x = 0; x < 8; x++) {
            if (2 * x - y < 0)
                dst[x] = src[area2 + 9 + 2 * x - y];
            else
                dst[x] = src[area4 + x - ((y + 1) >> 1)];
        }
        dst += stride;
    }
}

__attribute__((used)) static void spatial_compensation_6(uint8_t *src, uint8_t *dst, ptrdiff_t stride)
{
    int x, y;

    for (y = 0; y < 8; y++) {
        for (x = 0; x < 8; x++)
            dst[x] = src[area3 + x - y];
        dst += stride;
    }
}

__attribute__((used)) static void spatial_compensation_7(uint8_t *src, uint8_t *dst, ptrdiff_t stride)
{
    int x, y;

    for (y = 0; y < 8; y++) {
        for (x = 0; x < 8; x++) {
            if (x - 2 * y > 0)
                dst[x] = (src[area3 - 1 + x - 2 * y] + src[area3 + x - 2 * y] + 1) >> 1;
            else
                dst[x] = src[area2 + 8 - y + (x >> 1)];
        }
        dst += stride;
    }
}

__attribute__((used)) static void spatial_compensation_8(uint8_t *src, uint8_t *dst, ptrdiff_t stride)
{
    int x, y;

    for (y = 0; y < 8; y++) {
        for (x = 0; x < 8; x++)
            dst[x] = (src[area1 + 7 - y] + src[area2 + 7 - y] + 1) >> 1;
        dst += stride;
    }
}

__attribute__((used)) static void spatial_compensation_9(uint8_t *src, uint8_t *dst, ptrdiff_t stride)
{
    int x, y;

    for (y = 0; y < 8; y++) {
        for (x = 0; x < 8; x++)
            dst[x] = src[area2 + 6 - FFMIN(x + y, 6)];
        dst += stride;
    }
}

__attribute__((used)) static void spatial_compensation_10(uint8_t *src, uint8_t *dst, ptrdiff_t stride)
{
    int x, y;

    for (y = 0; y < 8; y++) {
        for (x = 0; x < 8; x++)
            dst[x] = (src[area2 + 7 - y] * (8 - x) + src[area4 + x] * x + 4) >> 3;
        dst += stride;
    }
}

__attribute__((used)) static void spatial_compensation_11(uint8_t *src, uint8_t *dst, ptrdiff_t stride)
{
    int x, y;

    for (y = 0; y < 8; y++) {
        for (x = 0; x < 8; x++)
            dst[x] = (src[area2 + 7 - y] * y + src[area4 + x] * (8 - y) + 4) >> 3;
        dst += stride;
    }
}

__attribute__((used)) static void x8_loop_filter(uint8_t *ptr, const ptrdiff_t a_stride,
                           const ptrdiff_t b_stride, int quant)
{
    int i, t;
    int p0, p1, p2, p3, p4, p5, p6, p7, p8, p9;
    int ql = (quant + 10) >> 3;

    for (i = 0; i < 8; i++, ptr += b_stride) {
        p0 = ptr[-5 * a_stride];
        p1 = ptr[-4 * a_stride];
        p2 = ptr[-3 * a_stride];
        p3 = ptr[-2 * a_stride];
        p4 = ptr[-1 * a_stride];
        p5 = ptr[0];
        p6 = ptr[1 * a_stride];
        p7 = ptr[2 * a_stride];
        p8 = ptr[3 * a_stride];
        p9 = ptr[4 * a_stride];

        t = (FFABS(p1 - p2) <= ql) +
            (FFABS(p2 - p3) <= ql) +
            (FFABS(p3 - p4) <= ql) +
            (FFABS(p4 - p5) <= ql);

        // You need at least 1 to be able to reach a total score of 6.
        if (t > 0) {
            t += (FFABS(p5 - p6) <= ql) +
                 (FFABS(p6 - p7) <= ql) +
                 (FFABS(p7 - p8) <= ql) +
                 (FFABS(p8 - p9) <= ql) +
                 (FFABS(p0 - p1) <= ql);
            if (t >= 6) {
                int min, max;

                min = max = p1;
                min = FFMIN(min, p3);
                max = FFMAX(max, p3);
                min = FFMIN(min, p5);
                max = FFMAX(max, p5);
                min = FFMIN(min, p8);
                max = FFMAX(max, p8);
                if (max - min < 2 * quant) { // early stop
                    min = FFMIN(min, p2);
                    max = FFMAX(max, p2);
                    min = FFMIN(min, p4);
                    max = FFMAX(max, p4);
                    min = FFMIN(min, p6);
                    max = FFMAX(max, p6);
                    min = FFMIN(min, p7);
                    max = FFMAX(max, p7);
                    if (max - min < 2 * quant) {
                        ptr[-2 * a_stride] = (4 * p2 + 3 * p3 + 1 * p7 + 4) >> 3;
                        ptr[-1 * a_stride] = (3 * p2 + 3 * p4 + 2 * p7 + 4) >> 3;
                        ptr[0]             = (2 * p2 + 3 * p5 + 3 * p7 + 4) >> 3;
                        ptr[1 * a_stride]  = (1 * p2 + 3 * p6 + 4 * p7 + 4) >> 3;
                        continue;
                    }
                }
            }
        }
        {
            int x, x0, x1, x2;
            int m;

            x0 = (2 * p3 - 5 * p4 + 5 * p5 - 2 * p6 + 4) >> 3;
            if (FFABS(x0) < quant) {
                x1 = (2 * p1 - 5 * p2 + 5 * p3 - 2 * p4 + 4) >> 3;
                x2 = (2 * p5 - 5 * p6 + 5 * p7 - 2 * p8 + 4) >> 3;

                x = FFABS(x0) - FFMIN(FFABS(x1), FFABS(x2));
                m = p4 - p5;

                if (x > 0 && (m ^ x0) < 0) {
                    int32_t sign;

                    sign = m >> 31;
                    m    = (m ^ sign) - sign; // abs(m)
                    m  >>= 1;

                    x = 5 * x >> 3;

                    if (x > m)
                        x = m;

                    x = (x ^ sign) - sign;

                    ptr[-1 * a_stride] -= x;
                    ptr[0]             += x;
                }
            }
        }
    }
}

__attribute__((used)) static void x8_h_loop_filter(uint8_t *src, ptrdiff_t stride, int qscale)
{
    x8_loop_filter(src, stride, 1, qscale);
}

__attribute__((used)) static void x8_v_loop_filter(uint8_t *src, ptrdiff_t stride, int qscale)
{
    x8_loop_filter(src, 1, stride, qscale);
}

