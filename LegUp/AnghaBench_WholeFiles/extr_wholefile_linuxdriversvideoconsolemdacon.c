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
struct vc_data {int vc_complement_mask; unsigned int vc_cols; int vc_rows; int vc_video_erase_char; unsigned int vc_screenbuf_size; unsigned int vc_y; int vc_x; int vc_cursor_type; struct vc_data** vc_display_fg; } ;
typedef  enum con_scroll { ____Placeholder_con_scroll } con_scroll ;

/* Variables and functions */
 int CM_ERASE ; 
#define  CUR_BLOCK 134 
#define  CUR_LOWER_HALF 133 
#define  CUR_LOWER_THIRD 132 
#define  CUR_NONE 131 
#define  CUR_TWO_THIRDS 130 
 unsigned int MDA_CURSOR_OFF ; 
 int MDA_MODE_BLINK_EN ; 
 int MDA_MODE_VIDEO_EN ; 
 int MDA_STATUS_VSYNC ; 
#define  SM_DOWN 129 
#define  SM_UP 128 
 scalar_t__ TYPE_HERC ; 
 scalar_t__ TYPE_HERCCOLOR ; 
 scalar_t__ TYPE_HERCPLUS ; 
 scalar_t__ TYPE_MDA ; 
 scalar_t__ VGA_MAP_MEM (int,int) ; 
 int inb (int) ; 
 int inb_p (int) ; 
 unsigned int mda_cursor_loc ; 
 int mda_cursor_size_from ; 
 int mda_cursor_size_to ; 
 struct vc_data* mda_display_fg ; 
 int mda_gfx_port ; 
 int mda_index_port ; 
 int /*<<< orphan*/  mda_lock ; 
 int mda_mode_port ; 
 unsigned int mda_num_columns ; 
 int mda_num_lines ; 
 int mda_status_port ; 
 scalar_t__ mda_type ; 
 char* mda_type_name ; 
 int mda_value_port ; 
 int* mda_vram_base ; 
 int mda_vram_len ; 
 int /*<<< orphan*/  outb_p (int,int) ; 
 int /*<<< orphan*/  printk (char*,...) ; 
 int /*<<< orphan*/  scr_memmovew (int*,int*,unsigned int) ; 
 int /*<<< orphan*/  scr_memsetw (int*,int,unsigned int) ; 
 int scr_readw (int*) ; 
 int /*<<< orphan*/  scr_writew (int,int*) ; 
 int /*<<< orphan*/  spin_lock_irqsave (int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  spin_unlock_irqrestore (int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  udelay (int) ; 
 int /*<<< orphan*/  vc_resize (struct vc_data*,unsigned int,int) ; 

__attribute__((used)) static void write_mda_b(unsigned int val, unsigned char reg)
{
	unsigned long flags;

	spin_lock_irqsave(&mda_lock, flags);	

	outb_p(reg, mda_index_port); 
	outb_p(val, mda_value_port);

	spin_unlock_irqrestore(&mda_lock, flags);
}

__attribute__((used)) static void write_mda_w(unsigned int val, unsigned char reg)
{
	unsigned long flags;

	spin_lock_irqsave(&mda_lock, flags);

	outb_p(reg,   mda_index_port); outb_p(val >> 8,   mda_value_port);
	outb_p(reg+1, mda_index_port); outb_p(val & 0xff, mda_value_port);

	spin_unlock_irqrestore(&mda_lock, flags);
}

__attribute__((used)) static inline void mda_set_cursor(unsigned int location) 
{
	if (mda_cursor_loc == location)
		return;

	write_mda_w(location >> 1, 0x0e);

	mda_cursor_loc = location;
}

__attribute__((used)) static inline void mda_set_cursor_size(int from, int to)
{
	if (mda_cursor_size_from==from && mda_cursor_size_to==to)
		return;
	
	if (from > to) {
		write_mda_b(MDA_CURSOR_OFF, 0x0a);	/* disable cursor */
	} else {
		write_mda_b(from, 0x0a);	/* cursor start */
		write_mda_b(to,   0x0b);	/* cursor end */
	}

	mda_cursor_size_from = from;
	mda_cursor_size_to   = to;
}

__attribute__((used)) static int mda_detect(void)
{
	int count=0;
	u16 *p, p_save;
	u16 *q, q_save;

	/* do a memory check */

	p = mda_vram_base;
	q = mda_vram_base + 0x01000 / 2;

	p_save = scr_readw(p);
	q_save = scr_readw(q);

	scr_writew(0xAA55, p);
	if (scr_readw(p) == 0xAA55)
		count++;

	scr_writew(0x55AA, p);
	if (scr_readw(p) == 0x55AA)
		count++;

	scr_writew(p_save, p);

	if (count != 2) {
		return 0;
	}

	/* check if we have 4K or 8K */

	scr_writew(0xA55A, q);
	scr_writew(0x0000, p);
	if (scr_readw(q) == 0xA55A)
		count++;
	
	scr_writew(0x5AA5, q);
	scr_writew(0x0000, p);
	if (scr_readw(q) == 0x5AA5)
		count++;

	scr_writew(p_save, p);
	scr_writew(q_save, q);
	
	if (count == 4) {
		mda_vram_len = 0x02000;
	}
	
	/* Ok, there is definitely a card registering at the correct
	 * memory location, so now we do an I/O port test.
	 */

#ifdef TEST_MDA_B
	/* Edward: These two mess `tests' mess up my cursor on bootup */

	/* cursor low register */
	if (!test_mda_b(0x66, 0x0f))
		return 0;

	/* cursor low register */
	if (!test_mda_b(0x99, 0x0f))
		return 0;
#endif

	/* See if the card is a Hercules, by checking whether the vsync
	 * bit of the status register is changing.  This test lasts for
	 * approximately 1/10th of a second.
	 */
	
	p_save = q_save = inb_p(mda_status_port) & MDA_STATUS_VSYNC;

	for (count = 0; count < 50000 && p_save == q_save; count++) {
		q_save = inb(mda_status_port) & MDA_STATUS_VSYNC;
		udelay(2);
	}

	if (p_save != q_save) {
		switch (inb_p(mda_status_port) & 0x70) {
		case 0x10:
			mda_type = TYPE_HERCPLUS;
			mda_type_name = "HerculesPlus";
			break;
		case 0x50:
			mda_type = TYPE_HERCCOLOR;
			mda_type_name = "HerculesColor";
			break;
		default:
			mda_type = TYPE_HERC;
			mda_type_name = "Hercules";
			break;
		}
	}

	return 1;
}

__attribute__((used)) static void mda_initialize(void)
{
	write_mda_b(97, 0x00);		/* horizontal total */
	write_mda_b(80, 0x01);		/* horizontal displayed */
	write_mda_b(82, 0x02);		/* horizontal sync pos */
	write_mda_b(15, 0x03);		/* horizontal sync width */

	write_mda_b(25, 0x04);		/* vertical total */
	write_mda_b(6,  0x05);		/* vertical total adjust */
	write_mda_b(25, 0x06);		/* vertical displayed */
	write_mda_b(25, 0x07);		/* vertical sync pos */

	write_mda_b(2,  0x08);		/* interlace mode */
	write_mda_b(13, 0x09);		/* maximum scanline */
	write_mda_b(12, 0x0a);		/* cursor start */
	write_mda_b(13, 0x0b);		/* cursor end */

	write_mda_w(0x0000, 0x0c);	/* start address */
	write_mda_w(0x0000, 0x0e);	/* cursor location */

	outb_p(MDA_MODE_VIDEO_EN | MDA_MODE_BLINK_EN, mda_mode_port);
	outb_p(0x00, mda_status_port);
	outb_p(0x00, mda_gfx_port);
}

__attribute__((used)) static const char *mdacon_startup(void)
{
	mda_num_columns = 80;
	mda_num_lines   = 25;

	mda_vram_len  = 0x01000;
	mda_vram_base = (u16 *)VGA_MAP_MEM(0xb0000, mda_vram_len);

	mda_index_port  = 0x3b4;
	mda_value_port  = 0x3b5;
	mda_mode_port   = 0x3b8;
	mda_status_port = 0x3ba;
	mda_gfx_port    = 0x3bf;

	mda_type = TYPE_MDA;
	mda_type_name = "MDA";

	if (! mda_detect()) {
		printk("mdacon: MDA card not detected.\n");
		return NULL;
	}

	if (mda_type != TYPE_MDA) {
		mda_initialize();
	}

	/* cursor looks ugly during boot-up, so turn it off */
	mda_set_cursor(mda_vram_len - 1);

	printk("mdacon: %s with %ldK of memory detected.\n",
		mda_type_name, mda_vram_len/1024);

	return "MDA-2";
}

__attribute__((used)) static void mdacon_init(struct vc_data *c, int init)
{
	c->vc_complement_mask = 0x0800;	 /* reverse video */
	c->vc_display_fg = &mda_display_fg;

	if (init) {
		c->vc_cols = mda_num_columns;
		c->vc_rows = mda_num_lines;
	} else
		vc_resize(c, mda_num_columns, mda_num_lines);

	/* make the first MDA console visible */

	if (mda_display_fg == NULL)
		mda_display_fg = c;
}

__attribute__((used)) static void mdacon_deinit(struct vc_data *c)
{
	/* con_set_default_unimap(c->vc_num); */

	if (mda_display_fg == c)
		mda_display_fg = NULL;
}

__attribute__((used)) static inline u16 mda_convert_attr(u16 ch)
{
	u16 attr = 0x0700;

	/* Underline and reverse-video are mutually exclusive on MDA.
	 * Since reverse-video is used for cursors and selected areas,
	 * it takes precedence. 
	 */

	if (ch & 0x0800)	attr = 0x7000;	/* reverse */
	else if (ch & 0x0400)	attr = 0x0100;	/* underline */

	return ((ch & 0x0200) << 2) | 		/* intensity */ 
		(ch & 0x8000) |			/* blink */ 
		(ch & 0x00ff) | attr;
}

__attribute__((used)) static u8 mdacon_build_attr(struct vc_data *c, u8 color, u8 intensity, 
			    u8 blink, u8 underline, u8 reverse, u8 italic)
{
	/* The attribute is just a bit vector:
	 *
	 *	Bit 0..1 : intensity (0..2)
	 *	Bit 2    : underline
	 *	Bit 3    : reverse
	 *	Bit 7    : blink
	 */

	return (intensity & 3) |
		((underline & 1) << 2) |
		((reverse   & 1) << 3) |
		(!!italic << 4) |
		((blink     & 1) << 7);
}

__attribute__((used)) static void mdacon_invert_region(struct vc_data *c, u16 *p, int count)
{
	for (; count > 0; count--) {
		scr_writew(scr_readw(p) ^ 0x0800, p);
		p++;
	}
}

__attribute__((used)) static inline u16 *mda_addr(unsigned int x, unsigned int y)
{
	return mda_vram_base + y * mda_num_columns + x;
}

__attribute__((used)) static void mdacon_putc(struct vc_data *c, int ch, int y, int x)
{
	scr_writew(mda_convert_attr(ch), mda_addr(x, y));
}

__attribute__((used)) static void mdacon_putcs(struct vc_data *c, const unsigned short *s,
		         int count, int y, int x)
{
	u16 *dest = mda_addr(x, y);

	for (; count > 0; count--) {
		scr_writew(mda_convert_attr(scr_readw(s++)), dest++);
	}
}

__attribute__((used)) static void mdacon_clear(struct vc_data *c, int y, int x, 
			  int height, int width)
{
	u16 *dest = mda_addr(x, y);
	u16 eattr = mda_convert_attr(c->vc_video_erase_char);

	if (width <= 0 || height <= 0)
		return;

	if (x==0 && width==mda_num_columns) {
		scr_memsetw(dest, eattr, height*width*2);
	} else {
		for (; height > 0; height--, dest+=mda_num_columns)
			scr_memsetw(dest, eattr, width*2);
	}
}

__attribute__((used)) static int mdacon_switch(struct vc_data *c)
{
	return 1;	/* redrawing needed */
}

__attribute__((used)) static int mdacon_blank(struct vc_data *c, int blank, int mode_switch)
{
	if (mda_type == TYPE_MDA) {
		if (blank) 
			scr_memsetw(mda_vram_base,
				mda_convert_attr(c->vc_video_erase_char),
				c->vc_screenbuf_size);
		/* Tell console.c that it has to restore the screen itself */
		return 1;
	} else {
		if (blank)
			outb_p(0x00, mda_mode_port);	/* disable video */
		else
			outb_p(MDA_MODE_VIDEO_EN | MDA_MODE_BLINK_EN, 
				mda_mode_port);
		return 0;
	}
}

__attribute__((used)) static void mdacon_cursor(struct vc_data *c, int mode)
{
	if (mode == CM_ERASE) {
		mda_set_cursor(mda_vram_len - 1);
		return;
	}

	mda_set_cursor(c->vc_y*mda_num_columns*2 + c->vc_x*2);

	switch (c->vc_cursor_type & 0x0f) {

		case CUR_LOWER_THIRD:	mda_set_cursor_size(10, 13); break;
		case CUR_LOWER_HALF:	mda_set_cursor_size(7,  13); break;
		case CUR_TWO_THIRDS:	mda_set_cursor_size(4,  13); break;
		case CUR_BLOCK:		mda_set_cursor_size(1,  13); break;
		case CUR_NONE:		mda_set_cursor_size(14, 13); break;
		default:		mda_set_cursor_size(12, 13); break;
	}
}

__attribute__((used)) static bool mdacon_scroll(struct vc_data *c, unsigned int t, unsigned int b,
		enum con_scroll dir, unsigned int lines)
{
	u16 eattr = mda_convert_attr(c->vc_video_erase_char);

	if (!lines)
		return false;

	if (lines > c->vc_rows)   /* maximum realistic size */
		lines = c->vc_rows;

	switch (dir) {

	case SM_UP:
		scr_memmovew(mda_addr(0, t), mda_addr(0, t + lines),
				(b-t-lines)*mda_num_columns*2);
		scr_memsetw(mda_addr(0, b - lines), eattr,
				lines*mda_num_columns*2);
		break;

	case SM_DOWN:
		scr_memmovew(mda_addr(0, t + lines), mda_addr(0, t),
				(b-t-lines)*mda_num_columns*2);
		scr_memsetw(mda_addr(0, t), eattr, lines*mda_num_columns*2);
		break;
	}

	return false;
}

