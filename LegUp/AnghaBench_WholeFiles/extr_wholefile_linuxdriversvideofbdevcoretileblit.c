#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_18__   TYPE_9__ ;
typedef  struct TYPE_17__   TYPE_8__ ;
typedef  struct TYPE_16__   TYPE_7__ ;
typedef  struct TYPE_15__   TYPE_6__ ;
typedef  struct TYPE_14__   TYPE_5__ ;
typedef  struct TYPE_13__   TYPE_4__ ;
typedef  struct TYPE_12__   TYPE_3__ ;
typedef  struct TYPE_11__   TYPE_2__ ;
typedef  struct TYPE_10__   TYPE_1__ ;

/* Type definitions */
typedef  scalar_t__ u32 ;
typedef  int u16 ;
struct TYPE_10__ {int /*<<< orphan*/  height; int /*<<< orphan*/  width; } ;
struct vc_data {int vc_video_erase_char; int vc_cursor_type; TYPE_1__ vc_font; int /*<<< orphan*/  vc_y; int /*<<< orphan*/  vc_x; scalar_t__ vc_hi_font_mask; scalar_t__ vc_can_do_color; } ;
struct TYPE_16__ {int /*<<< orphan*/  vmode; int /*<<< orphan*/  yoffset; int /*<<< orphan*/  xoffset; } ;
struct fbcon_ops {void (* bmove ) (struct vc_data*,struct fb_info*,int,int,int,int,int,int) ;void (* clear ) (struct vc_data*,struct fb_info*,int,int,int,int) ;void (* putcs ) (struct vc_data*,struct fb_info*,unsigned short const*,int,int,int,int,int) ;void (* clear_margins ) (struct vc_data*,struct fb_info*,int,int) ;void (* cursor ) (struct vc_data*,struct fb_info*,int,int,int,int) ;int (* update_start ) (struct fb_info*) ;TYPE_2__* p; TYPE_7__ var; } ;
struct fb_tilerect {int index; int sx; int sy; int width; int height; int /*<<< orphan*/  rop; int /*<<< orphan*/  bg; int /*<<< orphan*/  fg; } ;
struct fb_tilemap {int depth; int length; int /*<<< orphan*/  data; int /*<<< orphan*/  height; int /*<<< orphan*/  width; } ;
struct fb_tilecursor {int mode; int fg; int bg; int /*<<< orphan*/  shape; int /*<<< orphan*/  sy; int /*<<< orphan*/  sx; } ;
struct fb_tileblit {int sx; int sy; int width; int height; int fg; int bg; int length; scalar_t__* indices; } ;
struct fb_tilearea {int sx; int sy; int dx; int dy; int height; int width; } ;
struct TYPE_14__ {int /*<<< orphan*/  length; } ;
struct TYPE_13__ {int length; } ;
struct TYPE_12__ {int /*<<< orphan*/  length; } ;
struct TYPE_17__ {int /*<<< orphan*/  vmode; int /*<<< orphan*/  yoffset; int /*<<< orphan*/  xoffset; TYPE_5__ blue; TYPE_4__ red; TYPE_3__ green; } ;
struct TYPE_18__ {scalar_t__ visual; } ;
struct fb_info {TYPE_6__* tileops; struct fbcon_ops* fbcon_par; TYPE_8__ var; int /*<<< orphan*/  pixmap; TYPE_9__ fix; } ;
struct display {int vrows; scalar_t__ yscroll; } ;
typedef  int __u32 ;
struct TYPE_15__ {int /*<<< orphan*/  (* fb_settile ) (struct fb_info*,struct fb_tilemap*) ;int /*<<< orphan*/  (* fb_tilecursor ) (struct fb_info*,struct fb_tilecursor*) ;int /*<<< orphan*/  (* fb_tileblit ) (struct fb_info*,struct fb_tileblit*) ;int /*<<< orphan*/  (* fb_tilefill ) (struct fb_info*,struct fb_tilerect*) ;int /*<<< orphan*/  (* fb_tilecopy ) (struct fb_info*,struct fb_tilearea*) ;} ;
struct TYPE_11__ {int /*<<< orphan*/  fontdata; scalar_t__ userfont; } ;

/* Variables and functions */
 int CM_ERASE ; 
#define  CUR_BLOCK 133 
#define  CUR_LOWER_HALF 132 
#define  CUR_LOWER_THIRD 131 
#define  CUR_NONE 130 
#define  CUR_TWO_THIRDS 129 
#define  CUR_UNDERLINE 128 
 int FBCON_ATTRIBUTE_BOLD ; 
 int FBCON_ATTRIBUTE_REVERSE ; 
 int FBCON_ATTRIBUTE_UNDERLINE ; 
 int /*<<< orphan*/  FB_TILE_CURSOR_BLOCK ; 
 int /*<<< orphan*/  FB_TILE_CURSOR_LOWER_HALF ; 
 int /*<<< orphan*/  FB_TILE_CURSOR_LOWER_THIRD ; 
 int /*<<< orphan*/  FB_TILE_CURSOR_NONE ; 
 int /*<<< orphan*/  FB_TILE_CURSOR_TWO_THIRDS ; 
 int /*<<< orphan*/  FB_TILE_CURSOR_UNDERLINE ; 
 scalar_t__ FB_VISUAL_MONO01 ; 
 int FNTCHARCNT (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ROP_COPY ; 
 int attr_bgcol (int,int) ; 
 int /*<<< orphan*/  attr_bgcol_ec (int,struct vc_data*,struct fb_info*) ; 
 scalar_t__ attr_bold (int) ; 
 int attr_fgcol (int,int) ; 
 int /*<<< orphan*/  attr_fgcol_ec (int,struct vc_data*,struct fb_info*) ; 
 scalar_t__ attr_reverse (int) ; 
 scalar_t__ attr_underline (int) ; 
 scalar_t__ fb_get_buffer_offset (struct fb_info*,int /*<<< orphan*/ *,int) ; 
 int fb_get_color_depth (TYPE_8__*,TYPE_9__*) ; 
 int fb_pan_display (struct fb_info*,TYPE_7__*) ; 
 int max (int /*<<< orphan*/ ,int) ; 
 unsigned short scr_readw (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  stub1 (struct fb_info*,struct fb_tilearea*) ; 
 int /*<<< orphan*/  stub2 (struct fb_info*,struct fb_tilerect*) ; 
 int /*<<< orphan*/  stub3 (struct fb_info*,struct fb_tileblit*) ; 
 int /*<<< orphan*/  stub4 (struct fb_info*,struct fb_tilecursor*) ; 
 int /*<<< orphan*/  stub5 (struct fb_info*,struct fb_tilemap*) ; 

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

__attribute__((used)) static void tile_bmove(struct vc_data *vc, struct fb_info *info, int sy,
		       int sx, int dy, int dx, int height, int width)
{
	struct fb_tilearea area;

	area.sx = sx;
	area.sy = sy;
	area.dx = dx;
	area.dy = dy;
	area.height = height;
	area.width = width;

	info->tileops->fb_tilecopy(info, &area);
}

__attribute__((used)) static void tile_clear(struct vc_data *vc, struct fb_info *info, int sy,
		       int sx, int height, int width)
{
	struct fb_tilerect rect;
	int bgshift = (vc->vc_hi_font_mask) ? 13 : 12;
	int fgshift = (vc->vc_hi_font_mask) ? 9 : 8;

	rect.index = vc->vc_video_erase_char &
		((vc->vc_hi_font_mask) ? 0x1ff : 0xff);
	rect.fg = attr_fgcol_ec(fgshift, vc, info);
	rect.bg = attr_bgcol_ec(bgshift, vc, info);
	rect.sx = sx;
	rect.sy = sy;
	rect.width = width;
	rect.height = height;
	rect.rop = ROP_COPY;

	info->tileops->fb_tilefill(info, &rect);
}

__attribute__((used)) static void tile_putcs(struct vc_data *vc, struct fb_info *info,
		       const unsigned short *s, int count, int yy, int xx,
		       int fg, int bg)
{
	struct fb_tileblit blit;
	unsigned short charmask = vc->vc_hi_font_mask ? 0x1ff : 0xff;
	int size = sizeof(u32) * count, i;

	blit.sx = xx;
	blit.sy = yy;
	blit.width = count;
	blit.height = 1;
	blit.fg = fg;
	blit.bg = bg;
	blit.length = count;
	blit.indices = (u32 *) fb_get_buffer_offset(info, &info->pixmap, size);
	for (i = 0; i < count; i++)
		blit.indices[i] = (u32)(scr_readw(s++) & charmask);

	info->tileops->fb_tileblit(info, &blit);
}

__attribute__((used)) static void tile_clear_margins(struct vc_data *vc, struct fb_info *info,
			       int color, int bottom_only)
{
	return;
}

__attribute__((used)) static void tile_cursor(struct vc_data *vc, struct fb_info *info, int mode,
			int softback_lines, int fg, int bg)
{
	struct fb_tilecursor cursor;
	int use_sw = (vc->vc_cursor_type & 0x10);

	cursor.sx = vc->vc_x;
	cursor.sy = vc->vc_y;
	cursor.mode = (mode == CM_ERASE || use_sw) ? 0 : 1;
	cursor.fg = fg;
	cursor.bg = bg;

	switch (vc->vc_cursor_type & 0x0f) {
	case CUR_NONE:
		cursor.shape = FB_TILE_CURSOR_NONE;
		break;
	case CUR_UNDERLINE:
		cursor.shape = FB_TILE_CURSOR_UNDERLINE;
		break;
	case CUR_LOWER_THIRD:
		cursor.shape = FB_TILE_CURSOR_LOWER_THIRD;
		break;
	case CUR_LOWER_HALF:
		cursor.shape = FB_TILE_CURSOR_LOWER_HALF;
		break;
	case CUR_TWO_THIRDS:
		cursor.shape = FB_TILE_CURSOR_TWO_THIRDS;
		break;
	case CUR_BLOCK:
	default:
		cursor.shape = FB_TILE_CURSOR_BLOCK;
		break;
	}

	info->tileops->fb_tilecursor(info, &cursor);
}

__attribute__((used)) static int tile_update_start(struct fb_info *info)
{
	struct fbcon_ops *ops = info->fbcon_par;
	int err;

	err = fb_pan_display(info, &ops->var);
	ops->var.xoffset = info->var.xoffset;
	ops->var.yoffset = info->var.yoffset;
	ops->var.vmode = info->var.vmode;
	return err;
}

void fbcon_set_tileops(struct vc_data *vc, struct fb_info *info)
{
	struct fb_tilemap map;
	struct fbcon_ops *ops = info->fbcon_par;

	ops->bmove = tile_bmove;
	ops->clear = tile_clear;
	ops->putcs = tile_putcs;
	ops->clear_margins = tile_clear_margins;
	ops->cursor = tile_cursor;
	ops->update_start = tile_update_start;

	if (ops->p) {
		map.width = vc->vc_font.width;
		map.height = vc->vc_font.height;
		map.depth = 1;
		map.length = (ops->p->userfont) ?
			FNTCHARCNT(ops->p->fontdata) : 256;
		map.data = ops->p->fontdata;
		info->tileops->fb_settile(info, &map);
	}
}

