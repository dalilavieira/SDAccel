#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_2__ ;
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
typedef  int u8 ;
typedef  int u32 ;
typedef  int /*<<< orphan*/  u16 ;
struct TYPE_4__ {int vbase; } ;
struct savagefb_par {int paletteEnabled; int /*<<< orphan*/  (* SavageWaitFifo ) (struct savagefb_par*,int) ;scalar_t__ bci_ptr; int /*<<< orphan*/  (* SavageWaitIdle ) (struct savagefb_par*) ;TYPE_2__ mmio; } ;
struct TYPE_3__ {scalar_t__ visual; } ;
struct fb_info {scalar_t__ pseudo_palette; TYPE_1__ fix; struct savagefb_par* par; } ;
struct fb_image {int width; int height; int depth; int fg_color; int bg_color; int dx; int dy; scalar_t__ data; } ;
struct fb_fillrect {int width; int height; int color; size_t rop; int dx; int dy; } ;
struct fb_copyarea {int sx; int dx; int sy; int dy; int width; int height; } ;

/* Variables and functions */
 int BCI_CLIP_LR (int,int) ; 
 int BCI_CMD_CLIP_LR ; 
 int BCI_CMD_DEST_GBD ; 
 int BCI_CMD_RECT ; 
 int BCI_CMD_RECT_XP ; 
 int BCI_CMD_RECT_YP ; 
 int BCI_CMD_SEND_COLOR ; 
 int /*<<< orphan*/  BCI_CMD_SET_ROP (int,int /*<<< orphan*/ ) ; 
 int BCI_CMD_SRC_GBD ; 
 int BCI_CMD_SRC_MONO ; 
 int BCI_CMD_SRC_SOLID ; 
 int /*<<< orphan*/  BCI_SEND (int) ; 
 int BCI_W_H (int,int) ; 
 int BCI_X_Y (int,int) ; 
 scalar_t__ FB_VISUAL_PSEUDOCOLOR ; 
 int /*<<< orphan*/  cfb_imageblit (struct fb_info*,struct fb_image const*) ; 
 int readb (int) ; 
 int readl (int) ; 
 int /*<<< orphan*/  readw (int) ; 
 int /*<<< orphan*/ * savagefb_rop ; 
 int /*<<< orphan*/  stub1 (struct savagefb_par*) ; 
 int /*<<< orphan*/  stub2 (struct savagefb_par*,int) ; 
 int /*<<< orphan*/  stub3 (struct savagefb_par*,int) ; 
 int /*<<< orphan*/  stub4 (struct savagefb_par*,int) ; 
 int /*<<< orphan*/  writeb (int,int) ; 
 int /*<<< orphan*/  writel (int,int) ; 
 int /*<<< orphan*/  writew (int /*<<< orphan*/ ,int) ; 

__attribute__((used)) static inline u8 savage_in8(u32 addr, struct savagefb_par *par)
{
	return readb(par->mmio.vbase + addr);
}

__attribute__((used)) static inline u16 savage_in16(u32 addr, struct savagefb_par *par)
{
	return readw(par->mmio.vbase + addr);
}

__attribute__((used)) static inline u32 savage_in32(u32 addr, struct savagefb_par *par)
{
	return readl(par->mmio.vbase + addr);
}

__attribute__((used)) static inline void savage_out8(u32 addr, u8 val, struct savagefb_par *par)
{
	writeb(val, par->mmio.vbase + addr);
}

__attribute__((used)) static inline void savage_out16(u32 addr, u16 val, struct savagefb_par *par)
{
	writew(val, par->mmio.vbase + addr);
}

__attribute__((used)) static inline void savage_out32(u32 addr, u32 val, struct savagefb_par *par)
{
	writel(val, par->mmio.vbase + addr);
}

__attribute__((used)) static inline u8 vga_in8(int addr, struct savagefb_par *par)
{
	return savage_in8(0x8000 + addr, par);
}

__attribute__((used)) static inline u16 vga_in16(int addr, struct savagefb_par *par)
{
	return savage_in16(0x8000 + addr, par);
}

__attribute__((used)) static inline u8 vga_in32(int addr, struct savagefb_par *par)
{
	return savage_in32(0x8000 + addr, par);
}

__attribute__((used)) static inline void vga_out8(int addr, u8 val, struct savagefb_par *par)
{
	savage_out8(0x8000 + addr, val, par);
}

__attribute__((used)) static inline void vga_out16(int addr, u16 val, struct savagefb_par *par)
{
	savage_out16(0x8000 + addr, val, par);
}

__attribute__((used)) static inline void vga_out32(int addr, u32 val, struct savagefb_par *par)
{
	savage_out32(0x8000 + addr, val, par);
}

__attribute__((used)) static inline u8 VGArCR (u8 index, struct savagefb_par *par)
{
	vga_out8(0x3d4, index,  par);
	return vga_in8(0x3d5, par);
}

__attribute__((used)) static inline u8 VGArGR (u8 index, struct savagefb_par *par)
{
	vga_out8(0x3ce, index, par);
	return vga_in8(0x3cf, par);
}

__attribute__((used)) static inline u8 VGArSEQ (u8 index, struct savagefb_par *par)
{
	vga_out8(0x3c4, index, par);
	return vga_in8(0x3c5, par);
}

__attribute__((used)) static inline void VGAwCR(u8 index, u8 val, struct savagefb_par *par)
{
	vga_out8(0x3d4, index, par);
	vga_out8(0x3d5, val, par);
}

__attribute__((used)) static inline void VGAwGR(u8 index, u8 val, struct savagefb_par *par)
{
	vga_out8(0x3ce, index, par);
	vga_out8(0x3cf, val, par);
}

__attribute__((used)) static inline void VGAwSEQ(u8 index, u8 val, struct savagefb_par *par)
{
	vga_out8(0x3c4, index, par);
	vga_out8 (0x3c5, val, par);
}

__attribute__((used)) static inline void VGAenablePalette(struct savagefb_par *par)
{
	vga_in8(0x3da, par);
	vga_out8(0x3c0, 0x00, par);
	par->paletteEnabled = 1;
}

__attribute__((used)) static inline void VGAdisablePalette(struct savagefb_par *par)
{
	vga_in8(0x3da, par);
	vga_out8(0x3c0, 0x20, par);
	par->paletteEnabled = 0;
}

__attribute__((used)) static inline void VGAwATTR(u8 index, u8 value, struct savagefb_par *par)
{
	if (par->paletteEnabled)
		index &= ~0x20;
	else
		index |= 0x20;

	vga_in8(0x3da, par);
	vga_out8(0x3c0, index, par);
	vga_out8 (0x3c0, value, par);
}

__attribute__((used)) static inline void VGAwMISC(u8 value, struct savagefb_par *par)
{
	vga_out8(0x3c2, value, par);
}

__attribute__((used)) static inline void VerticalRetraceWait(struct savagefb_par *par)
{
	vga_out8(0x3d4, 0x17, par);
	if (vga_in8(0x3d5, par) & 0x80) {
		while ((vga_in8(0x3da, par) & 0x08) == 0x08);
		while ((vga_in8(0x3da, par) & 0x08) == 0x00);
	}
}

int savagefb_sync(struct fb_info *info)
{
	struct savagefb_par *par = info->par;

	par->SavageWaitIdle(par);
	return 0;
}

void savagefb_copyarea(struct fb_info *info, const struct fb_copyarea *region)
{
	struct savagefb_par *par = info->par;
	int sx = region->sx, dx = region->dx;
	int sy = region->sy, dy = region->dy;
	int cmd;

	if (!region->width || !region->height)
		return;
	par->bci_ptr = 0;
	cmd = BCI_CMD_RECT | BCI_CMD_DEST_GBD | BCI_CMD_SRC_GBD;
	BCI_CMD_SET_ROP(cmd, savagefb_rop[0]);

	if (dx <= sx) {
		cmd |= BCI_CMD_RECT_XP;
	} else {
		sx += region->width - 1;
		dx += region->width - 1;
	}

	if (dy <= sy) {
		cmd |= BCI_CMD_RECT_YP;
	} else {
		sy += region->height - 1;
		dy += region->height - 1;
	}

	par->SavageWaitFifo(par,4);
	BCI_SEND(cmd);
	BCI_SEND(BCI_X_Y(sx, sy));
	BCI_SEND(BCI_X_Y(dx, dy));
	BCI_SEND(BCI_W_H(region->width, region->height));
}

void savagefb_fillrect(struct fb_info *info, const struct fb_fillrect *rect)
{
	struct savagefb_par *par = info->par;
	int cmd, color;

	if (!rect->width || !rect->height)
		return;

	if (info->fix.visual == FB_VISUAL_PSEUDOCOLOR)
		color = rect->color;
	else
		color = ((u32 *)info->pseudo_palette)[rect->color];

	cmd = BCI_CMD_RECT | BCI_CMD_RECT_XP | BCI_CMD_RECT_YP |
	      BCI_CMD_DEST_GBD | BCI_CMD_SRC_SOLID |
	      BCI_CMD_SEND_COLOR;

	par->bci_ptr = 0;
	BCI_CMD_SET_ROP(cmd, savagefb_rop[rect->rop]);

	par->SavageWaitFifo(par,4);
	BCI_SEND(cmd);
	BCI_SEND(color);
	BCI_SEND( BCI_X_Y(rect->dx, rect->dy) );
	BCI_SEND( BCI_W_H(rect->width, rect->height) );
}

void savagefb_imageblit(struct fb_info *info, const struct fb_image *image)
{
	struct savagefb_par *par = info->par;
	int fg, bg, size, i, width;
	int cmd;
	u32 *src = (u32 *) image->data;

	if (!image->width || !image->height)
		return;

	if (image->depth != 1) {
		cfb_imageblit(info, image);
		return;
	}

	if (info->fix.visual == FB_VISUAL_PSEUDOCOLOR) {
		fg = image->fg_color;
		bg = image->bg_color;
	} else {
		fg = ((u32 *)info->pseudo_palette)[image->fg_color];
		bg = ((u32 *)info->pseudo_palette)[image->bg_color];
	}

	cmd = BCI_CMD_RECT | BCI_CMD_RECT_XP | BCI_CMD_RECT_YP |
	      BCI_CMD_CLIP_LR | BCI_CMD_DEST_GBD | BCI_CMD_SRC_MONO |
	      BCI_CMD_SEND_COLOR;

	par->bci_ptr = 0;
	BCI_CMD_SET_ROP(cmd, savagefb_rop[0]);

	width = (image->width + 31) & ~31;
	size = (width * image->height)/8;
	size >>= 2;

	par->SavageWaitFifo(par, size + 5);
	BCI_SEND(cmd);
	BCI_SEND(BCI_CLIP_LR(image->dx, image->dx + image->width - 1));
	BCI_SEND(fg);
	BCI_SEND(bg);
	BCI_SEND(BCI_X_Y(image->dx, image->dy));
	BCI_SEND(BCI_W_H(width, image->height));
	for (i = 0; i < size; i++)
		BCI_SEND(src[i]);
}

