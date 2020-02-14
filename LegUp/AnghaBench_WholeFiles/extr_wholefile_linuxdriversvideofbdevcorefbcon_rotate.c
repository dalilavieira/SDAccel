#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_16__   TYPE_8__ ;
typedef  struct TYPE_15__   TYPE_7__ ;
typedef  struct TYPE_14__   TYPE_6__ ;
typedef  struct TYPE_13__   TYPE_5__ ;
typedef  struct TYPE_12__   TYPE_4__ ;
typedef  struct TYPE_11__   TYPE_3__ ;
typedef  struct TYPE_10__   TYPE_2__ ;
typedef  struct TYPE_9__   TYPE_1__ ;

/* Type definitions */
typedef  char u8 ;
typedef  int u32 ;
typedef  int /*<<< orphan*/  u16 ;
struct TYPE_11__ {scalar_t__ data; int width; int height; } ;
struct vc_data {TYPE_3__ vc_font; int /*<<< orphan*/  vc_video_erase_char; scalar_t__ vc_can_do_color; } ;
struct fbcon_ops {scalar_t__ fontdata; scalar_t__ cur_rotate; int rotate; int fd_size; char* fontbuffer; TYPE_1__* p; } ;
struct TYPE_16__ {scalar_t__ visual; } ;
struct TYPE_14__ {int /*<<< orphan*/  length; } ;
struct TYPE_13__ {int length; } ;
struct TYPE_12__ {int /*<<< orphan*/  length; } ;
struct TYPE_15__ {TYPE_6__ blue; TYPE_5__ red; TYPE_4__ green; } ;
struct fb_info {TYPE_2__* fbops; struct fbcon_ops* fbcon_par; TYPE_8__ fix; TYPE_7__ var; } ;
struct display {int vrows; scalar_t__ yscroll; } ;
typedef  int __u32 ;
struct TYPE_10__ {int /*<<< orphan*/  (* fb_sync ) (struct fb_info*) ;} ;
struct TYPE_9__ {scalar_t__ con_rotate; int /*<<< orphan*/  userfont; } ;

/* Variables and functions */
 int ENOMEM ; 
 int FBCON_ATTRIBUTE_BOLD ; 
 int FBCON_ATTRIBUTE_REVERSE ; 
 int FBCON_ATTRIBUTE_UNDERLINE ; 
#define  FB_ROTATE_CCW 130 
#define  FB_ROTATE_CW 129 
#define  FB_ROTATE_UD 128 
 scalar_t__ FB_VISUAL_MONO01 ; 
 int FNTCHARCNT (char const*) ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int attr_bgcol (int,int /*<<< orphan*/ ) ; 
 scalar_t__ attr_bold (int /*<<< orphan*/ ) ; 
 int attr_fgcol (int,int /*<<< orphan*/ ) ; 
 scalar_t__ attr_reverse (int /*<<< orphan*/ ) ; 
 scalar_t__ attr_underline (int /*<<< orphan*/ ) ; 
 int fb_get_color_depth (TYPE_7__*,TYPE_8__*) ; 
 int /*<<< orphan*/  kfree (char*) ; 
 char* kmalloc_array (int,int,int /*<<< orphan*/ ) ; 
 int max (int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  memset (char*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  stub1 (struct fb_info*) ; 

__attribute__((used)) static inline int mono_col(const struct fb_info *info)
{
	__u32 max_len;
	max_len = max(info->var.green.length, info->var.red.length);
	max_len = max(info->var.blue.length, max_len);
	return (~(0xfff << max_len)) & 0xff;
}

__attribute__((used)) static inline int attr_col_ec(int shift, struct vc_data *vc,
			      struct fb_info *info, int is_fg)
{
	int is_mono01;
	int col;
	int fg;
	int bg;

	if (!vc)
		return 0;

	if (vc->vc_can_do_color)
		return is_fg ? attr_fgcol(shift,vc->vc_video_erase_char)
			: attr_bgcol(shift,vc->vc_video_erase_char);

	if (!info)
		return 0;

	col = mono_col(info);
	is_mono01 = info->fix.visual == FB_VISUAL_MONO01;

	if (attr_reverse(vc->vc_video_erase_char)) {
		fg = is_mono01 ? col : 0;
		bg = is_mono01 ? 0 : col;
	}
	else {
		fg = is_mono01 ? 0 : col;
		bg = is_mono01 ? col : 0;
	}

	return is_fg ? fg : bg;
}

__attribute__((used)) static inline int real_y(struct display *p, int ypos)
{
	int rows = p->vrows;

	ypos += p->yscroll;
	return ypos < rows ? ypos : ypos - rows;
}

__attribute__((used)) static inline int get_attribute(struct fb_info *info, u16 c)
{
	int attribute = 0;

	if (fb_get_color_depth(&info->var, &info->fix) == 1) {
		if (attr_underline(c))
			attribute |= FBCON_ATTRIBUTE_UNDERLINE;
		if (attr_reverse(c))
			attribute |= FBCON_ATTRIBUTE_REVERSE;
		if (attr_bold(c))
			attribute |= FBCON_ATTRIBUTE_BOLD;
	}

	return attribute;
}

__attribute__((used)) static inline int pattern_test_bit(u32 x, u32 y, u32 pitch, const char *pat)
{
	u32 tmp = (y * pitch) + x, index = tmp / 8,  bit = tmp % 8;

	pat +=index;
	return (*pat) & (0x80 >> bit);
}

__attribute__((used)) static inline void pattern_set_bit(u32 x, u32 y, u32 pitch, char *pat)
{
	u32 tmp = (y * pitch) + x, index = tmp / 8, bit = tmp % 8;

	pat += index;

	(*pat) |= 0x80 >> bit;
}

__attribute__((used)) static inline void rotate_ud(const char *in, char *out, u32 width, u32 height)
{
	int i, j;
	int shift = (8 - (width % 8)) & 7;

	width = (width + 7) & ~7;

	for (i = 0; i < height; i++) {
		for (j = 0; j < width - shift; j++) {
			if (pattern_test_bit(j, i, width, in))
				pattern_set_bit(width - (1 + j + shift),
						height - (1 + i),
						width, out);
		}

	}
}

__attribute__((used)) static inline void rotate_cw(const char *in, char *out, u32 width, u32 height)
{
	int i, j, h = height, w = width;
	int shift = (8 - (height % 8)) & 7;

	width = (width + 7) & ~7;
	height = (height + 7) & ~7;

	for (i = 0; i < h; i++) {
		for (j = 0; j < w; j++) {
			if (pattern_test_bit(j, i, width, in))
				pattern_set_bit(height - 1 - i - shift, j,
						height, out);

		}
	}
}

__attribute__((used)) static inline void rotate_ccw(const char *in, char *out, u32 width, u32 height)
{
	int i, j, h = height, w = width;
	int shift = (8 - (width % 8)) & 7;

	width = (width + 7) & ~7;
	height = (height + 7) & ~7;

	for (i = 0; i < h; i++) {
		for (j = 0; j < w; j++) {
			if (pattern_test_bit(j, i, width, in))
				pattern_set_bit(i, width - 1 - j - shift,
						height, out);
		}
	}
}

__attribute__((used)) static int fbcon_rotate_font(struct fb_info *info, struct vc_data *vc)
{
	struct fbcon_ops *ops = info->fbcon_par;
	int len, err = 0;
	int s_cellsize, d_cellsize, i;
	const u8 *src;
	u8 *dst;

	if (vc->vc_font.data == ops->fontdata &&
	    ops->p->con_rotate == ops->cur_rotate)
		goto finished;

	src = ops->fontdata = vc->vc_font.data;
	ops->cur_rotate = ops->p->con_rotate;
	len = (!ops->p->userfont) ? 256 : FNTCHARCNT(src);
	s_cellsize = ((vc->vc_font.width + 7)/8) *
		vc->vc_font.height;
	d_cellsize = s_cellsize;

	if (ops->rotate == FB_ROTATE_CW ||
	    ops->rotate == FB_ROTATE_CCW)
		d_cellsize = ((vc->vc_font.height + 7)/8) *
			vc->vc_font.width;

	if (info->fbops->fb_sync)
		info->fbops->fb_sync(info);

	if (ops->fd_size < d_cellsize * len) {
		dst = kmalloc_array(len, d_cellsize, GFP_KERNEL);

		if (dst == NULL) {
			err = -ENOMEM;
			goto finished;
		}

		ops->fd_size = d_cellsize * len;
		kfree(ops->fontbuffer);
		ops->fontbuffer = dst;
	}

	dst = ops->fontbuffer;
	memset(dst, 0, ops->fd_size);

	switch (ops->rotate) {
	case FB_ROTATE_UD:
		for (i = len; i--; ) {
			rotate_ud(src, dst, vc->vc_font.width,
				  vc->vc_font.height);

			src += s_cellsize;
			dst += d_cellsize;
		}
		break;
	case FB_ROTATE_CW:
		for (i = len; i--; ) {
			rotate_cw(src, dst, vc->vc_font.width,
				  vc->vc_font.height);
			src += s_cellsize;
			dst += d_cellsize;
		}
		break;
	case FB_ROTATE_CCW:
		for (i = len; i--; ) {
			rotate_ccw(src, dst, vc->vc_font.width,
				   vc->vc_font.height);
			src += s_cellsize;
			dst += d_cellsize;
		}
		break;
	}

finished:
	return err;
}

