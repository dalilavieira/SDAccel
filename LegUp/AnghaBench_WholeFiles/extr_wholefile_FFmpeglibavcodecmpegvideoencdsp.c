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
typedef  int int16_t ;

/* Variables and functions */
 int BASIS_SHIFT ; 
 int EDGE_BOTTOM ; 
 int EDGE_TOP ; 
 int RECON_SHIFT ; 
 int /*<<< orphan*/  av_assert2 (int) ; 
 int* ff_square_tab ; 
 int /*<<< orphan*/  memcpy (int*,int*,int) ; 
 int /*<<< orphan*/  memset (int*,int,int) ; 

__attribute__((used)) static int try_8x8basis_c(int16_t rem[64], int16_t weight[64],
                          int16_t basis[64], int scale)
{
    int i;
    unsigned int sum = 0;

    for (i = 0; i < 8 * 8; i++) {
        int b = rem[i] + ((basis[i] * scale +
                           (1 << (BASIS_SHIFT - RECON_SHIFT - 1))) >>
                          (BASIS_SHIFT - RECON_SHIFT));
        int w = weight[i];
        b >>= RECON_SHIFT;
        av_assert2(-512 < b && b < 512);

        sum += (w * b) * (w * b) >> 4;
    }
    return sum >> 2;
}

__attribute__((used)) static void add_8x8basis_c(int16_t rem[64], int16_t basis[64], int scale)
{
    int i;

    for (i = 0; i < 8 * 8; i++)
        rem[i] += (basis[i] * scale +
                   (1 << (BASIS_SHIFT - RECON_SHIFT - 1))) >>
                  (BASIS_SHIFT - RECON_SHIFT);
}

__attribute__((used)) static int pix_sum_c(uint8_t *pix, int line_size)
{
    int s = 0, i, j;

    for (i = 0; i < 16; i++) {
        for (j = 0; j < 16; j += 8) {
            s   += pix[0];
            s   += pix[1];
            s   += pix[2];
            s   += pix[3];
            s   += pix[4];
            s   += pix[5];
            s   += pix[6];
            s   += pix[7];
            pix += 8;
        }
        pix += line_size - 16;
    }
    return s;
}

__attribute__((used)) static int pix_norm1_c(uint8_t *pix, int line_size)
{
    int s = 0, i, j;
    const uint32_t *sq = ff_square_tab + 256;

    for (i = 0; i < 16; i++) {
        for (j = 0; j < 16; j += 8) {
#if HAVE_FAST_64BIT
            register uint64_t x = *(uint64_t *) pix;
            s += sq[x         & 0xff];
            s += sq[(x >>  8) & 0xff];
            s += sq[(x >> 16) & 0xff];
            s += sq[(x >> 24) & 0xff];
            s += sq[(x >> 32) & 0xff];
            s += sq[(x >> 40) & 0xff];
            s += sq[(x >> 48) & 0xff];
            s += sq[(x >> 56) & 0xff];
#else
            register uint32_t x = *(uint32_t *) pix;
            s += sq[x         & 0xff];
            s += sq[(x >>  8) & 0xff];
            s += sq[(x >> 16) & 0xff];
            s += sq[(x >> 24) & 0xff];
            x  = *(uint32_t *) (pix + 4);
            s += sq[x         & 0xff];
            s += sq[(x >>  8) & 0xff];
            s += sq[(x >> 16) & 0xff];
            s += sq[(x >> 24) & 0xff];
#endif
            pix += 8;
        }
        pix += line_size - 16;
    }
    return s;
}

__attribute__((used)) static void draw_edges_8_c(uint8_t *buf, int wrap, int width, int height,
                           int w, int h, int sides)
{
    uint8_t *ptr = buf, *last_line;
    int i;

    /* left and right */
    for (i = 0; i < height; i++) {
        memset(ptr - w, ptr[0], w);
        memset(ptr + width, ptr[width - 1], w);
        ptr += wrap;
    }

    /* top and bottom + corners */
    buf -= w;
    last_line = buf + (height - 1) * wrap;
    if (sides & EDGE_TOP)
        for (i = 0; i < h; i++)
            // top
            memcpy(buf - (i + 1) * wrap, buf, width + w + w);
    if (sides & EDGE_BOTTOM)
        for (i = 0; i < h; i++)
            // bottom
            memcpy(last_line + (i + 1) * wrap, last_line, width + w + w);
}

__attribute__((used)) static void shrink22(uint8_t *dst, int dst_wrap,
                     const uint8_t *src, int src_wrap,
                     int width, int height)
{
    int w;
    const uint8_t *s1, *s2;
    uint8_t *d;

    for (; height > 0; height--) {
        s1 = src;
        s2 = s1 + src_wrap;
        d = dst;
        for (w = width; w >= 4; w -= 4) {
            d[0] = (s1[0] + s1[1] + s2[0] + s2[1] + 2) >> 2;
            d[1] = (s1[2] + s1[3] + s2[2] + s2[3] + 2) >> 2;
            d[2] = (s1[4] + s1[5] + s2[4] + s2[5] + 2) >> 2;
            d[3] = (s1[6] + s1[7] + s2[6] + s2[7] + 2) >> 2;
            s1 += 8;
            s2 += 8;
            d += 4;
        }
        for (; w > 0; w--) {
            d[0] = (s1[0] + s1[1] + s2[0] + s2[1] + 2) >> 2;
            s1 += 2;
            s2 += 2;
            d++;
        }
        src += 2 * src_wrap;
        dst += dst_wrap;
    }
}

__attribute__((used)) static void shrink44(uint8_t *dst, int dst_wrap,
                     const uint8_t *src, int src_wrap,
                     int width, int height)
{
    int w;
    const uint8_t *s1, *s2, *s3, *s4;
    uint8_t *d;

    for (; height > 0; height--) {
        s1 = src;
        s2 = s1 + src_wrap;
        s3 = s2 + src_wrap;
        s4 = s3 + src_wrap;
        d = dst;
        for (w = width; w > 0; w--) {
            d[0] = (s1[0] + s1[1] + s1[2] + s1[3] +
                    s2[0] + s2[1] + s2[2] + s2[3] +
                    s3[0] + s3[1] + s3[2] + s3[3] +
                    s4[0] + s4[1] + s4[2] + s4[3] + 8) >> 4;
            s1 += 4;
            s2 += 4;
            s3 += 4;
            s4 += 4;
            d++;
        }
        src += 4 * src_wrap;
        dst += dst_wrap;
    }
}

__attribute__((used)) static void shrink88(uint8_t *dst, int dst_wrap,
                     const uint8_t *src, int src_wrap,
                     int width, int height)
{
    int w, i;

    for (; height > 0; height--) {
        for(w = width;w > 0; w--) {
            int tmp = 0;
            for (i = 0; i < 8; i++) {
                tmp += src[0] + src[1] + src[2] + src[3] +
                       src[4] + src[5] + src[6] + src[7];
                src += src_wrap;
            }
            *(dst++) = (tmp + 32) >> 6;
            src += 8 - 8 * src_wrap;
        }
        src += 8 * src_wrap - 8 * width;
        dst += dst_wrap - width;
    }
}

