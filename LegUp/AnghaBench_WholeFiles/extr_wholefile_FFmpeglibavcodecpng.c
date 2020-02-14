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

/* Variables and functions */
 int PNG_COLOR_MASK_ALPHA ; 
 int PNG_COLOR_MASK_COLOR ; 
 int PNG_COLOR_MASK_PALETTE ; 
 int /*<<< orphan*/  av_free (void*) ; 
 void* av_mallocz_array (unsigned int,unsigned int) ; 
 int* ff_png_pass_xmin ; 
 int* ff_png_pass_xshift ; 

void *ff_png_zalloc(void *opaque, unsigned int items, unsigned int size)
{
    return av_mallocz_array(items, size);
}

void ff_png_zfree(void *opaque, void *ptr)
{
    av_free(ptr);
}

int ff_png_get_nb_channels(int color_type)
{
    int channels;
    channels = 1;
    if ((color_type & (PNG_COLOR_MASK_COLOR | PNG_COLOR_MASK_PALETTE)) ==
        PNG_COLOR_MASK_COLOR)
        channels = 3;
    if (color_type & PNG_COLOR_MASK_ALPHA)
        channels++;
    return channels;
}

int ff_png_pass_row_size(int pass, int bits_per_pixel, int width)
{
    int shift, xmin, pass_width;

    xmin = ff_png_pass_xmin[pass];
    if (width <= xmin)
        return 0;
    shift      = ff_png_pass_xshift[pass];
    pass_width = (width - xmin + (1 << shift) - 1) >> shift;
    return (pass_width * bits_per_pixel + 7) >> 3;
}

