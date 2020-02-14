#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_21__   TYPE_6__ ;
typedef  struct TYPE_20__   TYPE_5__ ;
typedef  struct TYPE_19__   TYPE_4__ ;
typedef  struct TYPE_18__   TYPE_3__ ;
typedef  struct TYPE_17__   TYPE_2__ ;
typedef  struct TYPE_16__   TYPE_1__ ;

/* Type definitions */
struct TYPE_17__ {int /*<<< orphan*/  y; int /*<<< orphan*/  x; } ;
struct TYPE_16__ {scalar_t__ y; int /*<<< orphan*/  x; } ;
struct TYPE_19__ {int dst_width; int (* init ) (TYPE_4__*,TYPE_5__*,int) ;int (* draw_image ) (TYPE_4__*,TYPE_5__*) ;int (* cleanup ) (TYPE_4__*) ;TYPE_6__* state; int /*<<< orphan*/  src_height; int /*<<< orphan*/  src_width; TYPE_2__ scaled_size; TYPE_1__ scaled_offset; int /*<<< orphan*/  dst_height; } ;
typedef  TYPE_4__ zbar_window_t ;
struct TYPE_20__ {int width; scalar_t__ data; int /*<<< orphan*/  height; } ;
typedef  TYPE_5__ zbar_image_t ;
struct TYPE_18__ {int biWidth; int /*<<< orphan*/  biHeight; } ;
struct TYPE_21__ {TYPE_3__ bih; int /*<<< orphan*/  hdc; } ;
typedef  TYPE_6__ window_state_t ;
typedef  scalar_t__ uint32_t ;
typedef  int /*<<< orphan*/  BITMAPINFO ;

/* Variables and functions */
 int /*<<< orphan*/  DIB_RGB_COLORS ; 
 int /*<<< orphan*/  SRCCOPY ; 
 int /*<<< orphan*/  StretchDIBits (int /*<<< orphan*/ ,int /*<<< orphan*/ ,scalar_t__,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,void*,int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  _zbar_window_add_format (TYPE_4__*,scalar_t__) ; 
 int /*<<< orphan*/  _zbar_window_bih_init (TYPE_4__*,TYPE_5__*) ; 
 scalar_t__* dib_formats ; 

__attribute__((used)) static int dib_cleanup (zbar_window_t *w)
{
    return(0);
}

__attribute__((used)) static int dib_init (zbar_window_t *w,
                     zbar_image_t *img,
                     int new_format)
{
    if(new_format)
        _zbar_window_bih_init(w, img);

    window_state_t *win = w->state;
    w->dst_width = win->bih.biWidth = (img->width + 3) & ~3;
    w->dst_height = win->bih.biHeight = img->height;
    return(0);
}

__attribute__((used)) static int dib_draw (zbar_window_t *w,
                     zbar_image_t *img)
{
    StretchDIBits(w->state->hdc,
                  w->scaled_offset.x, w->scaled_offset.y + w->scaled_size.y - 1,
                  w->scaled_size.x, -w->scaled_size.y,
                  0, 0, w->src_width, w->src_height,
                  (void*)img->data, (BITMAPINFO*)&w->state->bih,
                  DIB_RGB_COLORS, SRCCOPY);
    return(0);
}

int _zbar_window_dib_init (zbar_window_t *w)
{
    uint32_t *fmt;
    for(fmt = dib_formats; *fmt; fmt++)
        _zbar_window_add_format(w, *fmt);

    w->init = dib_init;
    w->draw_image = dib_draw;
    w->cleanup = dib_cleanup;
    return(0);
}

