#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_6__   TYPE_3__ ;
typedef  struct TYPE_5__   TYPE_2__ ;
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
typedef  int u_long ;
struct smtcfb_info {int chip_id; struct fb_info* fb; int /*<<< orphan*/  chip_rev_id; void* dp_regs; int /*<<< orphan*/  vp_regs; int /*<<< orphan*/ * mmio; int /*<<< orphan*/ * lfb; int /*<<< orphan*/  colreg; struct pci_dev* pdev; } ;
struct pci_device_id {int device; } ;
struct pci_dev {int /*<<< orphan*/  dev; } ;
struct TYPE_4__ {int bits_per_pixel; scalar_t__ xres; scalar_t__ xres_virtual; int /*<<< orphan*/  yres; int /*<<< orphan*/  yres_virtual; } ;
struct TYPE_5__ {int smem_len; unsigned long mmio_start; int mmio_len; int /*<<< orphan*/  id; void* smem_start; } ;
struct fb_info {TYPE_1__ var; TYPE_2__ fix; struct smtcfb_info* par; int /*<<< orphan*/  pseudo_palette; int /*<<< orphan*/ * fbops; int /*<<< orphan*/  flags; int /*<<< orphan*/ * screen_base; } ;
struct TYPE_6__ {scalar_t__ lfb_width; int lfb_depth; int /*<<< orphan*/  lfb_height; } ;

/* Variables and functions */
 int ENOMEM ; 
 int /*<<< orphan*/  FBINFO_FLAG_DEFAULT ; 
 int /*<<< orphan*/  PCI_REVISION_ID ; 
 int SCREEN_BPP ; 
 scalar_t__ SCREEN_X_RES ; 
 int /*<<< orphan*/  SCREEN_Y_RES ; 
 int SM712_VIDEOMEMORYSIZE ; 
 int SM722_VIDEOMEMORYSIZE ; 
 scalar_t__ big_addr ; 
 int /*<<< orphan*/  big_pixel_depth (int,int) ; 
 int /*<<< orphan*/  dev_err (int /*<<< orphan*/ *,char*,...) ; 
 int /*<<< orphan*/  dev_info (int /*<<< orphan*/ *,char*,...) ; 
 struct fb_info* framebuffer_alloc (int,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  framebuffer_release (struct fb_info*) ; 
 void* ioremap (unsigned long,int) ; 
 int /*<<< orphan*/  iounmap (int /*<<< orphan*/ *) ; 
 int mmio_addr ; 
 int /*<<< orphan*/  outb_p (int,int) ; 
 int /*<<< orphan*/  pci_disable_device (struct pci_dev*) ; 
 int pci_enable_device (struct pci_dev*) ; 
 struct smtcfb_info* pci_get_drvdata (struct pci_dev*) ; 
 int /*<<< orphan*/  pci_read_config_byte (struct pci_dev*,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  pci_release_region (struct pci_dev*,int /*<<< orphan*/ ) ; 
 int pci_request_region (struct pci_dev*,int /*<<< orphan*/ ,char*) ; 
 void* pci_resource_start (struct pci_dev*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  pci_set_drvdata (struct pci_dev*,struct smtcfb_info*) ; 
 int register_framebuffer (struct fb_info*) ; 
 int /*<<< orphan*/  seqw17 () ; 
 unsigned int smtc_mmiorb (int) ; 
 int /*<<< orphan*/  smtc_mmiowb (int,int) ; 
 int /*<<< orphan*/ * smtc_regbaseaddress ; 
 TYPE_3__ smtc_scr_info ; 
 TYPE_2__ smtcfb_fix ; 
 int /*<<< orphan*/  smtcfb_ops ; 
 int /*<<< orphan*/  smtcfb_setmode (struct smtcfb_info*) ; 
 TYPE_1__ smtcfb_var ; 
 int /*<<< orphan*/  sprintf (int /*<<< orphan*/ ,char*,int) ; 
 int /*<<< orphan*/  unregister_framebuffer (struct fb_info*) ; 

__attribute__((used)) static inline void smtc_crtcw(int reg, int val)
{
	smtc_mmiowb(reg, 0x3d4);
	smtc_mmiowb(val, 0x3d5);
}

__attribute__((used)) static inline void smtc_grphw(int reg, int val)
{
	smtc_mmiowb(reg, 0x3ce);
	smtc_mmiowb(val, 0x3cf);
}

__attribute__((used)) static inline void smtc_attrw(int reg, int val)
{
	smtc_mmiorb(0x3da);
	smtc_mmiowb(reg, 0x3c0);
	smtc_mmiorb(0x3c1);
	smtc_mmiowb(val, 0x3c0);
}

__attribute__((used)) static inline void smtc_seqw(int reg, int val)
{
	smtc_mmiowb(reg, 0x3c4);
	smtc_mmiowb(val, 0x3c5);
}

__attribute__((used)) static inline unsigned int smtc_seqr(int reg)
{
	smtc_mmiowb(reg, 0x3c4);
	return smtc_mmiorb(0x3c5);
}

__attribute__((used)) static void smtc_unmap_mmio(struct smtcfb_info *sfb)
{
	if (sfb && smtc_regbaseaddress)
		smtc_regbaseaddress = NULL;
}

__attribute__((used)) static int smtc_map_smem(struct smtcfb_info *sfb,
			 struct pci_dev *pdev, u_long smem_len)
{
	sfb->fb->fix.smem_start = pci_resource_start(pdev, 0);

	if (sfb->fb->var.bits_per_pixel == 32)
		sfb->fb->fix.smem_start += big_addr;

	sfb->fb->fix.smem_len = smem_len;

	sfb->fb->screen_base = sfb->lfb;

	if (!sfb->fb->screen_base) {
		dev_err(&pdev->dev,
			"%s: unable to map screen memory\n", sfb->fb->fix.id);
		return -ENOMEM;
	}

	return 0;
}

__attribute__((used)) static void smtc_unmap_smem(struct smtcfb_info *sfb)
{
	if (sfb && sfb->fb->screen_base) {
		iounmap(sfb->fb->screen_base);
		sfb->fb->screen_base = NULL;
	}
}

__attribute__((used)) static inline void sm7xx_init_hw(void)
{
	outb_p(0x18, 0x3c4);
	outb_p(0x11, 0x3c5);
}

__attribute__((used)) static int smtcfb_pci_probe(struct pci_dev *pdev,
			    const struct pci_device_id *ent)
{
	struct smtcfb_info *sfb;
	struct fb_info *info;
	u_long smem_size = 0x00800000;	/* default 8MB */
	int err;
	unsigned long mmio_base;

	dev_info(&pdev->dev, "Silicon Motion display driver.\n");

	err = pci_enable_device(pdev);	/* enable SMTC chip */
	if (err)
		return err;

	err = pci_request_region(pdev, 0, "sm7xxfb");
	if (err < 0) {
		dev_err(&pdev->dev, "cannot reserve framebuffer region\n");
		goto failed_regions;
	}

	sprintf(smtcfb_fix.id, "sm%Xfb", ent->device);

	info = framebuffer_alloc(sizeof(*sfb), &pdev->dev);
	if (!info) {
		dev_err(&pdev->dev, "framebuffer_alloc failed\n");
		err = -ENOMEM;
		goto failed_free;
	}

	sfb = info->par;
	sfb->fb = info;
	sfb->chip_id = ent->device;
	sfb->pdev = pdev;
	info->flags = FBINFO_FLAG_DEFAULT;
	info->fbops = &smtcfb_ops;
	info->fix = smtcfb_fix;
	info->var = smtcfb_var;
	info->pseudo_palette = sfb->colreg;
	info->par = sfb;

	pci_set_drvdata(pdev, sfb);

	sm7xx_init_hw();

	/* get mode parameter from smtc_scr_info */
	if (smtc_scr_info.lfb_width != 0) {
		sfb->fb->var.xres = smtc_scr_info.lfb_width;
		sfb->fb->var.yres = smtc_scr_info.lfb_height;
		sfb->fb->var.bits_per_pixel = smtc_scr_info.lfb_depth;
	} else {
		/* default resolution 1024x600 16bit mode */
		sfb->fb->var.xres = SCREEN_X_RES;
		sfb->fb->var.yres = SCREEN_Y_RES;
		sfb->fb->var.bits_per_pixel = SCREEN_BPP;
	}

	big_pixel_depth(sfb->fb->var.bits_per_pixel, smtc_scr_info.lfb_depth);
	/* Map address and memory detection */
	mmio_base = pci_resource_start(pdev, 0);
	pci_read_config_byte(pdev, PCI_REVISION_ID, &sfb->chip_rev_id);

	switch (sfb->chip_id) {
	case 0x710:
	case 0x712:
		sfb->fb->fix.mmio_start = mmio_base + 0x00400000;
		sfb->fb->fix.mmio_len = 0x00400000;
		smem_size = SM712_VIDEOMEMORYSIZE;
		sfb->lfb = ioremap(mmio_base, mmio_addr);
		if (!sfb->lfb) {
			dev_err(&pdev->dev,
				"%s: unable to map memory mapped IO!\n",
				sfb->fb->fix.id);
			err = -ENOMEM;
			goto failed_fb;
		}

		sfb->mmio = (smtc_regbaseaddress =
		    sfb->lfb + 0x00700000);
		sfb->dp_regs = sfb->lfb + 0x00408000;
		sfb->vp_regs = sfb->lfb + 0x0040c000;
		if (sfb->fb->var.bits_per_pixel == 32) {
			sfb->lfb += big_addr;
			dev_info(&pdev->dev, "sfb->lfb=%p\n", sfb->lfb);
		}

		/* set MCLK = 14.31818 * (0x16 / 0x2) */
		smtc_seqw(0x6a, 0x16);
		smtc_seqw(0x6b, 0x02);
		smtc_seqw(0x62, 0x3e);
		/* enable PCI burst */
		smtc_seqw(0x17, 0x20);
		/* enable word swap */
		if (sfb->fb->var.bits_per_pixel == 32)
			seqw17();
		break;
	case 0x720:
		sfb->fb->fix.mmio_start = mmio_base;
		sfb->fb->fix.mmio_len = 0x00200000;
		smem_size = SM722_VIDEOMEMORYSIZE;
		sfb->dp_regs = ioremap(mmio_base, 0x00a00000);
		sfb->lfb = sfb->dp_regs + 0x00200000;
		sfb->mmio = (smtc_regbaseaddress =
		    sfb->dp_regs + 0x000c0000);
		sfb->vp_regs = sfb->dp_regs + 0x800;

		smtc_seqw(0x62, 0xff);
		smtc_seqw(0x6a, 0x0d);
		smtc_seqw(0x6b, 0x02);
		break;
	default:
		dev_err(&pdev->dev,
			"No valid Silicon Motion display chip was detected!\n");

		goto failed_fb;
	}

	/* can support 32 bpp */
	if (sfb->fb->var.bits_per_pixel == 15)
		sfb->fb->var.bits_per_pixel = 16;

	sfb->fb->var.xres_virtual = sfb->fb->var.xres;
	sfb->fb->var.yres_virtual = sfb->fb->var.yres;
	err = smtc_map_smem(sfb, pdev, smem_size);
	if (err)
		goto failed;

	smtcfb_setmode(sfb);

	err = register_framebuffer(info);
	if (err < 0)
		goto failed;

	dev_info(&pdev->dev,
		 "Silicon Motion SM%X Rev%X primary display mode %dx%d-%d Init Complete.\n",
		 sfb->chip_id, sfb->chip_rev_id, sfb->fb->var.xres,
		 sfb->fb->var.yres, sfb->fb->var.bits_per_pixel);

	return 0;

failed:
	dev_err(&pdev->dev, "Silicon Motion, Inc. primary display init fail.\n");

	smtc_unmap_smem(sfb);
	smtc_unmap_mmio(sfb);
failed_fb:
	framebuffer_release(info);

failed_free:
	pci_release_region(pdev, 0);

failed_regions:
	pci_disable_device(pdev);

	return err;
}

__attribute__((used)) static void smtcfb_pci_remove(struct pci_dev *pdev)
{
	struct smtcfb_info *sfb;

	sfb = pci_get_drvdata(pdev);
	smtc_unmap_smem(sfb);
	smtc_unmap_mmio(sfb);
	unregister_framebuffer(sfb->fb);
	framebuffer_release(sfb->fb);
	pci_release_region(pdev, 0);
	pci_disable_device(pdev);
}

