#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_6__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  uint8_t ;
typedef  int uint16_t ;
typedef  int int64_t ;
struct TYPE_6__ {int srcFormat; int dstFormat; } ;
typedef  int /*<<< orphan*/ * SwsFunc ;
typedef  TYPE_1__ SwsContext ;

/* Variables and functions */
 scalar_t__ ARCH_PPC ; 
 scalar_t__ ARCH_X86 ; 
 int /*<<< orphan*/  AV_LOG_WARNING ; 
#define  AV_PIX_FMT_ABGR 150 
#define  AV_PIX_FMT_ARGB 149 
#define  AV_PIX_FMT_BGR24 148 
#define  AV_PIX_FMT_BGR4 147 
#define  AV_PIX_FMT_BGR444 146 
#define  AV_PIX_FMT_BGR48BE 145 
#define  AV_PIX_FMT_BGR48LE 144 
#define  AV_PIX_FMT_BGR4_BYTE 143 
#define  AV_PIX_FMT_BGR555 142 
#define  AV_PIX_FMT_BGR565 141 
#define  AV_PIX_FMT_BGR8 140 
#define  AV_PIX_FMT_BGRA 139 
#define  AV_PIX_FMT_MONOBLACK 138 
#define  AV_PIX_FMT_RGB24 137 
#define  AV_PIX_FMT_RGB4 136 
#define  AV_PIX_FMT_RGB444 135 
#define  AV_PIX_FMT_RGB48BE 134 
#define  AV_PIX_FMT_RGB48LE 133 
#define  AV_PIX_FMT_RGB4_BYTE 132 
#define  AV_PIX_FMT_RGB555 131 
#define  AV_PIX_FMT_RGB565 130 
#define  AV_PIX_FMT_RGB8 129 
#define  AV_PIX_FMT_RGBA 128 
 int /*<<< orphan*/  AV_WB16 (int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  AV_WL16 (int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  CONFIG_SWSCALE_ALPHA ; 
 int SWS_CS_DEFAULT ; 
 int YUVRGB_TABLE_HEADROOM ; 
 int const av_clip_uint8 (int) ; 
 int /*<<< orphan*/  av_get_pix_fmt_name (int) ; 
 int /*<<< orphan*/  av_log (TYPE_1__*,int /*<<< orphan*/ ,char*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int const** ff_yuv2rgb_coeffs ; 
 int /*<<< orphan*/ * ff_yuv2rgb_init_ppc (TYPE_1__*) ; 
 int /*<<< orphan*/ * ff_yuv2rgb_init_x86 (TYPE_1__*) ; 
 int /*<<< orphan*/  isALPHA (int) ; 
 int /*<<< orphan*/ * yuv2rgb_c_12_ordered_dither ; 
 int /*<<< orphan*/ * yuv2rgb_c_15_ordered_dither ; 
 int /*<<< orphan*/ * yuv2rgb_c_16_ordered_dither ; 
 int /*<<< orphan*/ * yuv2rgb_c_1_ordered_dither ; 
 int /*<<< orphan*/ * yuv2rgb_c_24_bgr ; 
 int /*<<< orphan*/ * yuv2rgb_c_24_rgb ; 
 int /*<<< orphan*/ * yuv2rgb_c_32 ; 
 int /*<<< orphan*/ * yuv2rgb_c_48 ; 
 int /*<<< orphan*/ * yuv2rgb_c_4_ordered_dither ; 
 int /*<<< orphan*/ * yuv2rgb_c_4b_ordered_dither ; 
 int /*<<< orphan*/ * yuv2rgb_c_8_ordered_dither ; 
 int /*<<< orphan*/ * yuv2rgb_c_bgr48 ; 
 int /*<<< orphan*/ * yuva2argb_c ; 
 int /*<<< orphan*/ * yuva2rgba_c ; 

__attribute__((used)) static inline void fillPlane16(uint8_t *plane, int stride, int width, int height, int y,
                               int alpha, int bits, const int big_endian)
{
    int i, j;
    uint8_t *ptr = plane + stride * y;
    int v = alpha ? 0xFFFF>>(16-bits) : (1<<(bits-1));
    for (i = 0; i < height; i++) {
#define FILL(wfunc) \
        for (j = 0; j < width; j++) {\
            wfunc(ptr+2*j, v);\
        }
        if (big_endian) {
            FILL(AV_WB16);
        } else {
            FILL(AV_WL16);
        }
        ptr += stride;
    }
}

const int *sws_getCoefficients(int colorspace)
{
    if (colorspace > 10 || colorspace < 0 || colorspace == 8)
        colorspace = SWS_CS_DEFAULT;
    return ff_yuv2rgb_coeffs[colorspace];
}

SwsFunc ff_yuv2rgb_get_func_ptr(SwsContext *c)
{
    SwsFunc t = NULL;

    if (ARCH_PPC)
        t = ff_yuv2rgb_init_ppc(c);
    if (ARCH_X86)
        t = ff_yuv2rgb_init_x86(c);

    if (t)
        return t;

    av_log(c, AV_LOG_WARNING,
           "No accelerated colorspace conversion found from %s to %s.\n",
           av_get_pix_fmt_name(c->srcFormat), av_get_pix_fmt_name(c->dstFormat));

    switch (c->dstFormat) {
    case AV_PIX_FMT_BGR48BE:
    case AV_PIX_FMT_BGR48LE:
        return yuv2rgb_c_bgr48;
    case AV_PIX_FMT_RGB48BE:
    case AV_PIX_FMT_RGB48LE:
        return yuv2rgb_c_48;
    case AV_PIX_FMT_ARGB:
    case AV_PIX_FMT_ABGR:
        if (CONFIG_SWSCALE_ALPHA && isALPHA(c->srcFormat))
            return yuva2argb_c;
    case AV_PIX_FMT_RGBA:
    case AV_PIX_FMT_BGRA:
        return (CONFIG_SWSCALE_ALPHA && isALPHA(c->srcFormat)) ? yuva2rgba_c : yuv2rgb_c_32;
    case AV_PIX_FMT_RGB24:
        return yuv2rgb_c_24_rgb;
    case AV_PIX_FMT_BGR24:
        return yuv2rgb_c_24_bgr;
    case AV_PIX_FMT_RGB565:
    case AV_PIX_FMT_BGR565:
        return yuv2rgb_c_16_ordered_dither;
    case AV_PIX_FMT_RGB555:
    case AV_PIX_FMT_BGR555:
        return yuv2rgb_c_15_ordered_dither;
    case AV_PIX_FMT_RGB444:
    case AV_PIX_FMT_BGR444:
        return yuv2rgb_c_12_ordered_dither;
    case AV_PIX_FMT_RGB8:
    case AV_PIX_FMT_BGR8:
        return yuv2rgb_c_8_ordered_dither;
    case AV_PIX_FMT_RGB4:
    case AV_PIX_FMT_BGR4:
        return yuv2rgb_c_4_ordered_dither;
    case AV_PIX_FMT_RGB4_BYTE:
    case AV_PIX_FMT_BGR4_BYTE:
        return yuv2rgb_c_4b_ordered_dither;
    case AV_PIX_FMT_MONOBLACK:
        return yuv2rgb_c_1_ordered_dither;
    }
    return NULL;
}

__attribute__((used)) static void fill_table(uint8_t* table[256 + 2*YUVRGB_TABLE_HEADROOM], const int elemsize,
                       const int64_t inc, void *y_tab)
{
    int i;
    uint8_t *y_table = y_tab;

    y_table -= elemsize * (inc >> 9);

    for (i = 0; i < 256 + 2*YUVRGB_TABLE_HEADROOM; i++) {
        int64_t cb = av_clip_uint8(i-YUVRGB_TABLE_HEADROOM)*inc;
        table[i] = y_table + elemsize * (cb >> 16);
    }
}

__attribute__((used)) static void fill_gv_table(int table[256 + 2*YUVRGB_TABLE_HEADROOM], const int elemsize, const int64_t inc)
{
    int i;
    int off    = -(inc >> 9);

    for (i = 0; i < 256 + 2*YUVRGB_TABLE_HEADROOM; i++) {
        int64_t cb = av_clip_uint8(i-YUVRGB_TABLE_HEADROOM)*inc;
        table[i] = elemsize * (off + (cb >> 16));
    }
}

__attribute__((used)) static uint16_t roundToInt16(int64_t f)
{
    int r = (f + (1 << 15)) >> 16;

    if (r < -0x7FFF)
        return 0x8000;
    else if (r > 0x7FFF)
        return 0x7FFF;
    else
        return r;
}

