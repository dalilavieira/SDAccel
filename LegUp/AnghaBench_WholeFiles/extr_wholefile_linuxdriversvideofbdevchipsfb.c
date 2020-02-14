#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_20__   TYPE_7__ ;
typedef  struct TYPE_19__   TYPE_6__ ;
typedef  struct TYPE_18__   TYPE_5__ ;
typedef  struct TYPE_17__   TYPE_4__ ;
typedef  struct TYPE_16__   TYPE_3__ ;
typedef  struct TYPE_15__   TYPE_2__ ;
typedef  struct TYPE_14__   TYPE_1__ ;

/* Type definitions */
typedef  int u_int ;
struct pci_device_id {int dummy; } ;
struct pci_dev {int /*<<< orphan*/  dev; TYPE_1__* resource; } ;
struct fb_var_screeninfo {int xres; int yres; int xres_virtual; int yres_virtual; int bits_per_pixel; int vmode; scalar_t__ nonstd; } ;
struct TYPE_19__ {int line_length; unsigned long smem_start; int smem_len; int /*<<< orphan*/  visual; } ;
struct TYPE_17__ {int offset; int length; } ;
struct TYPE_16__ {int offset; int length; } ;
struct TYPE_15__ {int offset; int length; } ;
struct TYPE_18__ {int bits_per_pixel; TYPE_4__ blue; TYPE_3__ green; TYPE_2__ red; } ;
struct fb_info {int /*<<< orphan*/ * screen_base; TYPE_6__ fix; int /*<<< orphan*/  node; int /*<<< orphan*/  cmap; int /*<<< orphan*/  flags; int /*<<< orphan*/ * fbops; TYPE_5__ var; } ;
struct TYPE_20__ {int addr; int data; } ;
struct TYPE_14__ {int flags; } ;

/* Variables and functions */
 int ARRAY_SIZE (TYPE_7__*) ; 
 int EBUSY ; 
 int EINVAL ; 
 int ENODEV ; 
 int ENOMEM ; 
 int /*<<< orphan*/  FBINFO_DEFAULT ; 
 int /*<<< orphan*/  FB_VISUAL_PSEUDOCOLOR ; 
 int /*<<< orphan*/  FB_VISUAL_TRUECOLOR ; 
 int FB_VMODE_MASK ; 
 int FB_VMODE_NONINTERLACED ; 
 int IORESOURCE_MEM ; 
 int /*<<< orphan*/  PCI_COMMAND ; 
 TYPE_7__* chips_init_ar ; 
 TYPE_7__* chips_init_cr ; 
 TYPE_7__* chips_init_fr ; 
 TYPE_7__* chips_init_gr ; 
 TYPE_7__* chips_init_sr ; 
 TYPE_7__* chips_init_xr ; 
 TYPE_6__ chipsfb_fix ; 
 int /*<<< orphan*/  chipsfb_ops ; 
 TYPE_5__ chipsfb_var ; 
 int /*<<< orphan*/  dev_err (int /*<<< orphan*/ *,char*) ; 
 int /*<<< orphan*/  dev_info (int /*<<< orphan*/ *,char*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  fb_alloc_cmap (int /*<<< orphan*/ *,int,int /*<<< orphan*/ ) ; 
 struct fb_info* framebuffer_alloc (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  framebuffer_release (struct fb_info*) ; 
 int /*<<< orphan*/ * ioremap (unsigned long,int) ; 
 int /*<<< orphan*/  iounmap (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  memset (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  outb (int,int) ; 
 scalar_t__ pci_enable_device (struct pci_dev*) ; 
 struct fb_info* pci_get_drvdata (struct pci_dev*) ; 
 int /*<<< orphan*/  pci_read_config_word (struct pci_dev*,int /*<<< orphan*/ ,unsigned short*) ; 
 int /*<<< orphan*/  pci_release_region (struct pci_dev*,int /*<<< orphan*/ ) ; 
 scalar_t__ pci_request_region (struct pci_dev*,int /*<<< orphan*/ ,char*) ; 
 unsigned long pci_resource_len (struct pci_dev*,int /*<<< orphan*/ ) ; 
 unsigned long pci_resource_start (struct pci_dev*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  pci_set_drvdata (struct pci_dev*,struct fb_info*) ; 
 int /*<<< orphan*/  pci_write_config_word (struct pci_dev*,int /*<<< orphan*/ ,unsigned short) ; 
 scalar_t__ register_framebuffer (struct fb_info*) ; 
 int /*<<< orphan*/  udelay (int) ; 
 int /*<<< orphan*/  unregister_framebuffer (struct fb_info*) ; 
 int /*<<< orphan*/  write_ar (int,int) ; 
 int /*<<< orphan*/  write_cr (int,int) ; 
 int /*<<< orphan*/  write_fr (int,int) ; 
 int /*<<< orphan*/  write_gr (int,int) ; 
 int /*<<< orphan*/  write_sr (int,int) ; 
 int /*<<< orphan*/  write_xr (int,int) ; 

__attribute__((used)) static int chipsfb_check_var(struct fb_var_screeninfo *var,
			     struct fb_info *info)
{
	if (var->xres > 800 || var->yres > 600
	    || var->xres_virtual > 800 || var->yres_virtual > 600
	    || (var->bits_per_pixel != 8 && var->bits_per_pixel != 16)
	    || var->nonstd
	    || (var->vmode & FB_VMODE_MASK) != FB_VMODE_NONINTERLACED)
		return -EINVAL;

	var->xres = var->xres_virtual = 800;
	var->yres = var->yres_virtual = 600;

	return 0;
}

__attribute__((used)) static int chipsfb_set_par(struct fb_info *info)
{
	if (info->var.bits_per_pixel == 16) {
		write_cr(0x13, 200);		// Set line length (doublewords)
		write_xr(0x81, 0x14);		// 15 bit (555) color mode
		write_xr(0x82, 0x00);		// Disable palettes
		write_xr(0x20, 0x10);		// 16 bit blitter mode

		info->fix.line_length = 800*2;
		info->fix.visual = FB_VISUAL_TRUECOLOR;

		info->var.red.offset = 10;
		info->var.green.offset = 5;
		info->var.blue.offset = 0;
		info->var.red.length = info->var.green.length =
			info->var.blue.length = 5;
		
	} else {
		/* p->var.bits_per_pixel == 8 */
		write_cr(0x13, 100);		// Set line length (doublewords)
		write_xr(0x81, 0x12);		// 8 bit color mode
		write_xr(0x82, 0x08);		// Graphics gamma enable
		write_xr(0x20, 0x00);		// 8 bit blitter mode

		info->fix.line_length = 800;
		info->fix.visual = FB_VISUAL_PSEUDOCOLOR;		

 		info->var.red.offset = info->var.green.offset =
			info->var.blue.offset = 0;
		info->var.red.length = info->var.green.length =
			info->var.blue.length = 8;
		
	}
	return 0;
}

__attribute__((used)) static int chipsfb_blank(int blank, struct fb_info *info)
{
	return 1;	/* get fb_blank to set the colormap to all black */
}

__attribute__((used)) static int chipsfb_setcolreg(u_int regno, u_int red, u_int green, u_int blue,
			     u_int transp, struct fb_info *info)
{
	if (regno > 255)
		return 1;
	red >>= 8;
	green >>= 8;
	blue >>= 8;
	outb(regno, 0x3c8);
	udelay(1);
	outb(red, 0x3c9);
	outb(green, 0x3c9);
	outb(blue, 0x3c9);

	return 0;
}

__attribute__((used)) static void chips_hw_init(void)
{
	int i;

	for (i = 0; i < ARRAY_SIZE(chips_init_xr); ++i)
		write_xr(chips_init_xr[i].addr, chips_init_xr[i].data);
	outb(0x29, 0x3c2); /* set misc output reg */
	for (i = 0; i < ARRAY_SIZE(chips_init_sr); ++i)
		write_sr(chips_init_sr[i].addr, chips_init_sr[i].data);
	for (i = 0; i < ARRAY_SIZE(chips_init_gr); ++i)
		write_gr(chips_init_gr[i].addr, chips_init_gr[i].data);
	for (i = 0; i < ARRAY_SIZE(chips_init_ar); ++i)
		write_ar(chips_init_ar[i].addr, chips_init_ar[i].data);
	for (i = 0; i < ARRAY_SIZE(chips_init_cr); ++i)
		write_cr(chips_init_cr[i].addr, chips_init_cr[i].data);
	for (i = 0; i < ARRAY_SIZE(chips_init_fr); ++i)
		write_fr(chips_init_fr[i].addr, chips_init_fr[i].data);
}

__attribute__((used)) static void init_chips(struct fb_info *p, unsigned long addr)
{
	memset(p->screen_base, 0, 0x100000);

	p->fix = chipsfb_fix;
	p->fix.smem_start = addr;

	p->var = chipsfb_var;

	p->fbops = &chipsfb_ops;
	p->flags = FBINFO_DEFAULT;

	fb_alloc_cmap(&p->cmap, 256, 0);

	chips_hw_init();
}

__attribute__((used)) static int chipsfb_pci_init(struct pci_dev *dp, const struct pci_device_id *ent)
{
	struct fb_info *p;
	unsigned long addr, size;
	unsigned short cmd;
	int rc = -ENODEV;

	if (pci_enable_device(dp) < 0) {
		dev_err(&dp->dev, "Cannot enable PCI device\n");
		goto err_out;
	}

	if ((dp->resource[0].flags & IORESOURCE_MEM) == 0)
		goto err_disable;
	addr = pci_resource_start(dp, 0);
	size = pci_resource_len(dp, 0);
	if (addr == 0)
		goto err_disable;

	p = framebuffer_alloc(0, &dp->dev);
	if (p == NULL) {
		dev_err(&dp->dev, "Cannot allocate framebuffer structure\n");
		rc = -ENOMEM;
		goto err_disable;
	}

	if (pci_request_region(dp, 0, "chipsfb") != 0) {
		dev_err(&dp->dev, "Cannot request framebuffer\n");
		rc = -EBUSY;
		goto err_release_fb;
	}

#ifdef __BIG_ENDIAN
	addr += 0x800000;	// Use big-endian aperture
#endif

	/* we should use pci_enable_device here, but,
	   the device doesn't declare its I/O ports in its BARs
	   so pci_enable_device won't turn on I/O responses */
	pci_read_config_word(dp, PCI_COMMAND, &cmd);
	cmd |= 3;	/* enable memory and IO space */
	pci_write_config_word(dp, PCI_COMMAND, cmd);

#ifdef CONFIG_PMAC_BACKLIGHT
	/* turn on the backlight */
	mutex_lock(&pmac_backlight_mutex);
	if (pmac_backlight) {
		pmac_backlight->props.power = FB_BLANK_UNBLANK;
		backlight_update_status(pmac_backlight);
	}
	mutex_unlock(&pmac_backlight_mutex);
#endif /* CONFIG_PMAC_BACKLIGHT */

#ifdef CONFIG_PPC
	p->screen_base = __ioremap(addr, 0x200000, _PAGE_NO_CACHE);
#else
	p->screen_base = ioremap(addr, 0x200000);
#endif
	if (p->screen_base == NULL) {
		dev_err(&dp->dev, "Cannot map framebuffer\n");
		rc = -ENOMEM;
		goto err_release_pci;
	}

	pci_set_drvdata(dp, p);

	init_chips(p, addr);

	if (register_framebuffer(p) < 0) {
		dev_err(&dp->dev,"C&T 65550 framebuffer failed to register\n");
		goto err_unmap;
	}

	dev_info(&dp->dev,"fb%d: Chips 65550 frame buffer"
		 " (%dK RAM detected)\n",
		 p->node, p->fix.smem_len / 1024);

	return 0;

 err_unmap:
	iounmap(p->screen_base);
 err_release_pci:
	pci_release_region(dp, 0);
 err_release_fb:
	framebuffer_release(p);
 err_disable:
 err_out:
	return rc;
}

__attribute__((used)) static void chipsfb_remove(struct pci_dev *dp)
{
	struct fb_info *p = pci_get_drvdata(dp);

	if (p->screen_base == NULL)
		return;
	unregister_framebuffer(p);
	iounmap(p->screen_base);
	p->screen_base = NULL;
	pci_release_region(dp, 0);
}

