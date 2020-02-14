#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_14__   TYPE_7__ ;
typedef  struct TYPE_13__   TYPE_6__ ;
typedef  struct TYPE_12__   TYPE_5__ ;
typedef  struct TYPE_11__   TYPE_4__ ;
typedef  struct TYPE_10__   TYPE_3__ ;
typedef  struct TYPE_9__   TYPE_2__ ;
typedef  struct TYPE_8__   TYPE_1__ ;

/* Type definitions */
typedef  int u8 ;
typedef  int /*<<< orphan*/  u16 ;
struct vc_data {int /*<<< orphan*/  vc_video_erase_char; scalar_t__ vc_can_do_color; } ;
struct fbcon_ops {unsigned int cursor_size; int* cursor_src; } ;
struct TYPE_14__ {int scan_align; int buf_align; } ;
struct TYPE_13__ {scalar_t__ visual; } ;
struct TYPE_10__ {int /*<<< orphan*/  length; } ;
struct TYPE_9__ {int length; } ;
struct TYPE_8__ {int /*<<< orphan*/  length; } ;
struct TYPE_12__ {TYPE_3__ blue; TYPE_2__ red; TYPE_1__ green; } ;
struct fb_info {scalar_t__ state; TYPE_4__* fbops; TYPE_7__ pixmap; struct fbcon_ops* fbcon_par; TYPE_6__ fix; TYPE_5__ var; } ;
struct fb_image {int width; unsigned int height; int* data; } ;
struct fb_cursor {int rop; int* mask; scalar_t__ enable; struct fb_image image; } ;
struct display {int vrows; scalar_t__ yscroll; } ;
typedef  int __u32 ;
struct TYPE_11__ {int /*<<< orphan*/  (* fb_imageblit ) (struct fb_info*,struct fb_image*) ;} ;

/* Variables and functions */
 int ENOMEM ; 
 int FBCON_ATTRIBUTE_BOLD ; 
 int FBCON_ATTRIBUTE_REVERSE ; 
 int FBCON_ATTRIBUTE_UNDERLINE ; 
 scalar_t__ FBINFO_STATE_RUNNING ; 
 scalar_t__ FB_VISUAL_MONO01 ; 
 int /*<<< orphan*/  GFP_ATOMIC ; 
#define  ROP_COPY 129 
#define  ROP_XOR 128 
 int attr_bgcol (int,int /*<<< orphan*/ ) ; 
 scalar_t__ attr_bold (int /*<<< orphan*/ ) ; 
 int attr_fgcol (int,int /*<<< orphan*/ ) ; 
 scalar_t__ attr_reverse (int /*<<< orphan*/ ) ; 
 scalar_t__ attr_underline (int /*<<< orphan*/ ) ; 
 int* fb_get_buffer_offset (struct fb_info*,TYPE_7__*,unsigned int) ; 
 int fb_get_color_depth (TYPE_5__*,TYPE_6__*) ; 
 int /*<<< orphan*/  fb_pad_aligned_buffer (int*,unsigned int,int*,unsigned int,unsigned int) ; 
 int /*<<< orphan*/  kfree (int*) ; 
 int* kmalloc (unsigned int,int /*<<< orphan*/ ) ; 
 int max (int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  memcpy (int*,int*,unsigned int) ; 
 int /*<<< orphan*/  stub1 (struct fb_info*,struct fb_image*) ; 

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

int soft_cursor(struct fb_info *info, struct fb_cursor *cursor)
{
	struct fbcon_ops *ops = info->fbcon_par;
	unsigned int scan_align = info->pixmap.scan_align - 1;
	unsigned int buf_align = info->pixmap.buf_align - 1;
	unsigned int i, size, dsize, s_pitch, d_pitch;
	struct fb_image *image;
	u8 *src, *dst;

	if (info->state != FBINFO_STATE_RUNNING)
		return 0;

	s_pitch = (cursor->image.width + 7) >> 3;
	dsize = s_pitch * cursor->image.height;

	if (dsize + sizeof(struct fb_image) != ops->cursor_size) {
		kfree(ops->cursor_src);
		ops->cursor_size = dsize + sizeof(struct fb_image);

		ops->cursor_src = kmalloc(ops->cursor_size, GFP_ATOMIC);
		if (!ops->cursor_src) {
			ops->cursor_size = 0;
			return -ENOMEM;
		}
	}

	src = ops->cursor_src + sizeof(struct fb_image);
	image = (struct fb_image *)ops->cursor_src;
	*image = cursor->image;
	d_pitch = (s_pitch + scan_align) & ~scan_align;

	size = d_pitch * image->height + buf_align;
	size &= ~buf_align;
	dst = fb_get_buffer_offset(info, &info->pixmap, size);

	if (cursor->enable) {
		switch (cursor->rop) {
		case ROP_XOR:
			for (i = 0; i < dsize; i++)
				src[i] = image->data[i] ^ cursor->mask[i];
			break;
		case ROP_COPY:
		default:
			for (i = 0; i < dsize; i++)
				src[i] = image->data[i] & cursor->mask[i];
			break;
		}
	} else
		memcpy(src, image->data, dsize);

	fb_pad_aligned_buffer(dst, d_pitch, src, s_pitch, image->height);
	image->data = dst;
	info->fbops->fb_imageblit(info, image);
	return 0;
}

