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
typedef  int u8 ;
typedef  int u16 ;
struct vc_data {scalar_t__ vc_mode; unsigned short* vc_screenbuf; size_t vc_x; size_t vc_y; size_t vc_cols; int vc_cursor_type; int vc_can_do_color; int vc_rows; scalar_t__ vc_num; unsigned long vc_origin; int vc_size_row; unsigned long vc_scr_end; int /*<<< orphan*/  vc_video_erase_char; } ;
struct sti_struct {int font_width; int font_height; } ;
typedef  enum con_scroll { ____Placeholder_con_scroll } con_scroll ;
typedef  int a ;

/* Variables and functions */
 int /*<<< orphan*/  BLANK ; 
#define  CM_DRAW 137 
#define  CM_ERASE 136 
#define  CM_MOVE 135 
 scalar_t__ CURSOR_DRAW_DELAY ; 
#define  CUR_BLOCK 134 
#define  CUR_LOWER_HALF 133 
#define  CUR_LOWER_THIRD 132 
#define  CUR_TWO_THIRDS 131 
#define  CUR_UNDERLINE 130 
 scalar_t__ KD_TEXT ; 
#define  SM_DOWN 129 
#define  SM_UP 128 
 scalar_t__ console_blanked ; 
 scalar_t__ cursor_drawn ; 
 scalar_t__ fg_console ; 
 unsigned short scr_readw (int*) ; 
 int /*<<< orphan*/  scr_writew (int,int /*<<< orphan*/ ) ; 
 unsigned long softback_buf ; 
 int softback_curr ; 
 unsigned long softback_end ; 
 unsigned long softback_in ; 
 int softback_lines ; 
 int /*<<< orphan*/  sti_bmove (struct sti_struct*,unsigned int,int /*<<< orphan*/ ,unsigned int,int /*<<< orphan*/ ,unsigned int,size_t) ; 
 int /*<<< orphan*/  sti_clear (struct sti_struct*,int,int,int,int,int /*<<< orphan*/ ) ; 
 int sti_onscreen_x (struct sti_struct*) ; 
 int sti_onscreen_y (struct sti_struct*) ; 
 int /*<<< orphan*/  sti_putc (struct sti_struct*,unsigned short,int,int) ; 
 int /*<<< orphan*/  sti_set (struct sti_struct*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int,int,int /*<<< orphan*/ ) ; 
 struct sti_struct* sticon_sti ; 
 scalar_t__ vbl_cursor_cnt ; 
 int /*<<< orphan*/  vc_resize (struct vc_data*,int,int) ; 
 int vga_is_gfx ; 

__attribute__((used)) static inline void cursor_undrawn(void)
{
    vbl_cursor_cnt = 0;
    cursor_drawn = 0;
}

__attribute__((used)) static const char *sticon_startup(void)
{
    return "STI console";
}

__attribute__((used)) static void sticon_putc(struct vc_data *conp, int c, int ypos, int xpos)
{
    int redraw_cursor = 0;

    if (vga_is_gfx || console_blanked)
	    return;

    if (conp->vc_mode != KD_TEXT)
    	    return;
#if 0
    if ((p->cursor_x == xpos) && (p->cursor_y == ypos)) {
	    cursor_undrawn();
	    redraw_cursor = 1;
    }
#endif

    sti_putc(sticon_sti, c, ypos, xpos);

    if (redraw_cursor)
	    vbl_cursor_cnt = CURSOR_DRAW_DELAY;
}

__attribute__((used)) static void sticon_putcs(struct vc_data *conp, const unsigned short *s,
			 int count, int ypos, int xpos)
{
    int redraw_cursor = 0;

    if (vga_is_gfx || console_blanked)
	    return;

    if (conp->vc_mode != KD_TEXT)
    	    return;

#if 0
    if ((p->cursor_y == ypos) && (xpos <= p->cursor_x) &&
	(p->cursor_x < (xpos + count))) {
	    cursor_undrawn();
	    redraw_cursor = 1;
    }
#endif

    while (count--) {
	sti_putc(sticon_sti, scr_readw(s++), ypos, xpos++);
    }

    if (redraw_cursor)
	    vbl_cursor_cnt = CURSOR_DRAW_DELAY;
}

__attribute__((used)) static void sticon_cursor(struct vc_data *conp, int mode)
{
    unsigned short car1;

    car1 = conp->vc_screenbuf[conp->vc_x + conp->vc_y * conp->vc_cols];
    switch (mode) {
    case CM_ERASE:
	sti_putc(sticon_sti, car1, conp->vc_y, conp->vc_x);
	break;
    case CM_MOVE:
    case CM_DRAW:
	switch (conp->vc_cursor_type & 0x0f) {
	case CUR_UNDERLINE:
	case CUR_LOWER_THIRD:
	case CUR_LOWER_HALF:
	case CUR_TWO_THIRDS:
	case CUR_BLOCK:
	    sti_putc(sticon_sti, (car1 & 255) + (0 << 8) + (7 << 11),
		     conp->vc_y, conp->vc_x);
	    break;
	}
	break;
    }
}

__attribute__((used)) static bool sticon_scroll(struct vc_data *conp, unsigned int t,
		unsigned int b, enum con_scroll dir, unsigned int count)
{
    struct sti_struct *sti = sticon_sti;

    if (vga_is_gfx)
        return false;

    sticon_cursor(conp, CM_ERASE);

    switch (dir) {
    case SM_UP:
	sti_bmove(sti, t + count, 0, t, 0, b - t - count, conp->vc_cols);
	sti_clear(sti, b - count, 0, count, conp->vc_cols, conp->vc_video_erase_char);
	break;

    case SM_DOWN:
	sti_bmove(sti, t, 0, t + count, 0, b - t - count, conp->vc_cols);
	sti_clear(sti, t, 0, count, conp->vc_cols, conp->vc_video_erase_char);
	break;
    }

    return false;
}

__attribute__((used)) static void sticon_init(struct vc_data *c, int init)
{
    struct sti_struct *sti = sticon_sti;
    int vc_cols, vc_rows;

    sti_set(sti, 0, 0, sti_onscreen_y(sti), sti_onscreen_x(sti), 0);
    vc_cols = sti_onscreen_x(sti) / sti->font_width;
    vc_rows = sti_onscreen_y(sti) / sti->font_height;
    c->vc_can_do_color = 1;
    
    if (init) {
	c->vc_cols = vc_cols;
	c->vc_rows = vc_rows;
    } else {
	/* vc_rows = (c->vc_rows > vc_rows) ? vc_rows : c->vc_rows; */
	/* vc_cols = (c->vc_cols > vc_cols) ? vc_cols : c->vc_cols; */
	vc_resize(c, vc_cols, vc_rows);
/*	vc_resize_con(vc_rows, vc_cols, c->vc_num); */
    }
}

__attribute__((used)) static void sticon_deinit(struct vc_data *c)
{
}

__attribute__((used)) static void sticon_clear(struct vc_data *conp, int sy, int sx, int height,
			 int width)
{
    if (!height || !width)
	return;

    sti_clear(sticon_sti, sy, sx, height, width, conp->vc_video_erase_char);
}

__attribute__((used)) static int sticon_switch(struct vc_data *conp)
{
    return 1;	/* needs refreshing */
}

__attribute__((used)) static int sticon_set_origin(struct vc_data *conp)
{
    return 0;
}

__attribute__((used)) static int sticon_blank(struct vc_data *c, int blank, int mode_switch)
{
    if (blank == 0) {
	if (mode_switch)
	    vga_is_gfx = 0;
	return 1;
    }
    sticon_set_origin(c);
    sti_clear(sticon_sti, 0,0, c->vc_rows, c->vc_cols, BLANK);
    if (mode_switch)
	vga_is_gfx = 1;
    return 1;
}

__attribute__((used)) static u16 *sticon_screen_pos(struct vc_data *conp, int offset)
{
    int line;
    unsigned long p;

    if (conp->vc_num != fg_console || !softback_lines)
    	return (u16 *)(conp->vc_origin + offset);
    line = offset / conp->vc_size_row;
    if (line >= softback_lines)
    	return (u16 *)(conp->vc_origin + offset - softback_lines * conp->vc_size_row);
    p = softback_curr + offset;
    if (p >= softback_end)
    	p += softback_buf - softback_end;
    return (u16 *)p;
}

__attribute__((used)) static unsigned long sticon_getxy(struct vc_data *conp, unsigned long pos,
				  int *px, int *py)
{
    int x, y;
    unsigned long ret;
    if (pos >= conp->vc_origin && pos < conp->vc_scr_end) {
    	unsigned long offset = (pos - conp->vc_origin) / 2;
    	
    	x = offset % conp->vc_cols;
    	y = offset / conp->vc_cols;
    	if (conp->vc_num == fg_console)
    	    y += softback_lines;
    	ret = pos + (conp->vc_cols - x) * 2;
    } else if (conp->vc_num == fg_console && softback_lines) {
    	unsigned long offset = pos - softback_curr;
    	
    	if (pos < softback_curr)
    	    offset += softback_end - softback_buf;
    	offset /= 2;
    	x = offset % conp->vc_cols;
    	y = offset / conp->vc_cols;
	ret = pos + (conp->vc_cols - x) * 2;
	if (ret == softback_end)
	    ret = softback_buf;
	if (ret == softback_in)
	    ret = conp->vc_origin;
    } else {
    	/* Should not happen */
    	x = y = 0;
    	ret = conp->vc_origin;
    }
    if (px) *px = x;
    if (py) *py = y;
    return ret;
}

__attribute__((used)) static u8 sticon_build_attr(struct vc_data *conp, u8 color, u8 intens,
			    u8 blink, u8 underline, u8 reverse, u8 italic)
{
    u8 attr = ((color & 0x70) >> 1) | ((color & 7));

    if (reverse) {
	color = ((color >> 3) & 0x7) | ((color & 0x7) << 3);
    }

    return attr;
}

__attribute__((used)) static void sticon_invert_region(struct vc_data *conp, u16 *p, int count)
{
    int col = 1; /* vga_can_do_color; */

    while (count--) {
	u16 a = scr_readw(p);

	if (col)
		a = ((a) & 0x88ff) | (((a) & 0x7000) >> 4) | (((a) & 0x0700) << 4);
	else
		a = ((a & 0x0700) == 0x0100) ? 0x7000 : 0x7700;

	scr_writew(a, p++);
    }
}

__attribute__((used)) static void sticon_save_screen(struct vc_data *conp)
{
}

