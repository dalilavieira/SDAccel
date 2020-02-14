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

/* Variables and functions */
 int MAX_NEG_CROP ; 
 int* ff_crop_tab ; 
 int /*<<< orphan*/  motionpixels_tableinit () ; 
 int /*<<< orphan*/  mp_rgb_yuv_table ; 
 int /*<<< orphan*/  printf (char*) ; 
 int /*<<< orphan*/  write_int8_t_2d_array (int /*<<< orphan*/ ,int,int) ; 

__attribute__((used)) static int mp_yuv_to_rgb(int y, int v, int u, int clip_rgb) {
    const uint8_t *cm = ff_crop_tab + MAX_NEG_CROP;
    int r, g, b;

    r = (1000 * y + 701 * v) / 1000;
    g = (1000 * y - 357 * v - 172 * u) / 1000;
    b = (1000 * y + 886 * u) / 1000;
    if (clip_rgb)
        return ((cm[r * 8] & 0xF8) << 7) | ((cm[g * 8] & 0xF8) << 2) | (cm[b * 8] >> 3);
    if ((unsigned)r < 32 && (unsigned)g < 32 && (unsigned)b < 32)
        return (r << 10) | (g << 5) | b;
    return 1 << 15;
}

__attribute__((used)) static inline void write_fileheader(void)
{
    printf("/* This file was automatically generated. */\n");
    printf("#include <stdint.h>\n");
}

int main(void)
{
    motionpixels_tableinit();

    write_fileheader();

    printf("static const YuvPixel mp_rgb_yuv_table[1 << 15] = {\n");
    write_int8_t_2d_array(mp_rgb_yuv_table, 1 << 15, 3);
    printf("};\n");

    return 0;
}

