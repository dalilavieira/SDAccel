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
typedef  int u_int ;
typedef  scalar_t__ u32 ;
struct pci_device_id {int dummy; } ;
struct pci_dev {int /*<<< orphan*/  dev; } ;
struct mdpy_fb_par {scalar_t__* palette; } ;
struct TYPE_15__ {int /*<<< orphan*/  smem_len; int /*<<< orphan*/  smem_start; scalar_t__ line_length; } ;
struct TYPE_12__ {int length; scalar_t__ offset; } ;
struct TYPE_11__ {int length; scalar_t__ offset; } ;
struct TYPE_10__ {int length; scalar_t__ offset; } ;
struct TYPE_9__ {int length; scalar_t__ offset; } ;
struct TYPE_14__ {scalar_t__ yres_virtual; scalar_t__ xres_virtual; scalar_t__ yres; scalar_t__ xres; TYPE_4__ transp; TYPE_3__ blue; TYPE_2__ green; TYPE_1__ red; } ;
struct fb_info {scalar_t__ screen_base; int /*<<< orphan*/  node; scalar_t__* pseudo_palette; int /*<<< orphan*/  flags; int /*<<< orphan*/ * fbops; TYPE_7__ fix; TYPE_8__* apertures; int /*<<< orphan*/  screen_size; TYPE_6__ var; struct mdpy_fb_par* par; } ;
struct TYPE_16__ {TYPE_5__* ranges; } ;
struct TYPE_13__ {int /*<<< orphan*/  size; int /*<<< orphan*/  base; } ;

/* Variables and functions */
 scalar_t__ DRM_FORMAT_XRGB8888 ; 
 int EINVAL ; 
 int EIO ; 
 int ENOMEM ; 
 int /*<<< orphan*/  FBINFO_DEFAULT ; 
 int /*<<< orphan*/  MDPY_FORMAT_OFFSET ; 
 int /*<<< orphan*/  MDPY_HEIGHT_OFFSET ; 
 int /*<<< orphan*/  MDPY_WIDTH_OFFSET ; 
 int PSEUDO_PALETTE_SIZE ; 
 TYPE_8__* alloc_apertures (int) ; 
 struct fb_info* framebuffer_alloc (int,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  framebuffer_release (struct fb_info*) ; 
 scalar_t__ ioremap (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  iounmap (scalar_t__) ; 
 TYPE_7__ mdpy_fb_fix ; 
 int /*<<< orphan*/  mdpy_fb_ops ; 
 TYPE_6__ mdpy_fb_var ; 
 int pci_enable_device (struct pci_dev*) ; 
 int /*<<< orphan*/  pci_err (struct pci_dev*,char*,...) ; 
 struct fb_info* pci_get_drvdata (struct pci_dev*) ; 
 int /*<<< orphan*/  pci_info (struct pci_dev*,char*,scalar_t__,...) ; 
 int /*<<< orphan*/  pci_read_config_dword (struct pci_dev*,int /*<<< orphan*/ ,scalar_t__*) ; 
 int /*<<< orphan*/  pci_release_regions (struct pci_dev*) ; 
 int pci_request_regions (struct pci_dev*,char*) ; 
 int /*<<< orphan*/  pci_resource_len (struct pci_dev*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  pci_resource_start (struct pci_dev*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  pci_set_drvdata (struct pci_dev*,struct fb_info*) ; 
 int register_framebuffer (struct fb_info*) ; 
 int /*<<< orphan*/  unregister_framebuffer (struct fb_info*) ; 

__attribute__((used)) static int mdpy_fb_setcolreg(u_int regno, u_int red, u_int green, u_int blue,
			      u_int transp, struct fb_info *info)
{
	u32 *pal = info->pseudo_palette;
	u32 cr = red >> (16 - info->var.red.length);
	u32 cg = green >> (16 - info->var.green.length);
	u32 cb = blue >> (16 - info->var.blue.length);
	u32 value, mask;

	if (regno >= PSEUDO_PALETTE_SIZE)
		return -EINVAL;

	value = (cr << info->var.red.offset) |
		(cg << info->var.green.offset) |
		(cb << info->var.blue.offset);
	if (info->var.transp.length > 0) {
		mask = (1 << info->var.transp.length) - 1;
		mask <<= info->var.transp.offset;
		value |= mask;
	}
	pal[regno] = value;

	return 0;
}

__attribute__((used)) static void mdpy_fb_destroy(struct fb_info *info)
{
	if (info->screen_base)
		iounmap(info->screen_base);
}

__attribute__((used)) static int mdpy_fb_probe(struct pci_dev *pdev,
			 const struct pci_device_id *ent)
{
	struct fb_info *info;
	struct mdpy_fb_par *par;
	u32 format, width, height;
	int ret;

	ret = pci_enable_device(pdev);
	if (ret < 0)
		return ret;

	ret = pci_request_regions(pdev, "mdpy-fb");
	if (ret < 0)
		return ret;

	pci_read_config_dword(pdev, MDPY_FORMAT_OFFSET, &format);
	pci_read_config_dword(pdev, MDPY_WIDTH_OFFSET,	&width);
	pci_read_config_dword(pdev, MDPY_HEIGHT_OFFSET, &height);
	if (format != DRM_FORMAT_XRGB8888) {
		pci_err(pdev, "format mismatch (0x%x != 0x%x)\n",
			format, DRM_FORMAT_XRGB8888);
		return -EINVAL;
	}
	if (width < 100	 || width > 10000) {
		pci_err(pdev, "width (%d) out of range\n", width);
		return -EINVAL;
	}
	if (height < 100 || height > 10000) {
		pci_err(pdev, "height (%d) out of range\n", height);
		return -EINVAL;
	}
	pci_info(pdev, "mdpy found: %dx%d framebuffer\n",
		 width, height);

	info = framebuffer_alloc(sizeof(struct mdpy_fb_par), &pdev->dev);
	if (!info)
		goto err_release_regions;
	pci_set_drvdata(pdev, info);
	par = info->par;

	info->fix = mdpy_fb_fix;
	info->fix.smem_start = pci_resource_start(pdev, 0);
	info->fix.smem_len = pci_resource_len(pdev, 0);
	info->fix.line_length = width * 4;

	info->var = mdpy_fb_var;
	info->var.xres = width;
	info->var.yres = height;
	info->var.xres_virtual = width;
	info->var.yres_virtual = height;

	info->screen_size = info->fix.smem_len;
	info->screen_base = ioremap(info->fix.smem_start,
				    info->screen_size);
	if (!info->screen_base) {
		pci_err(pdev, "ioremap(pcibar) failed\n");
		ret = -EIO;
		goto err_release_fb;
	}

	info->apertures = alloc_apertures(1);
	if (!info->apertures) {
		ret = -ENOMEM;
		goto err_unmap;
	}
	info->apertures->ranges[0].base = info->fix.smem_start;
	info->apertures->ranges[0].size = info->fix.smem_len;

	info->fbops = &mdpy_fb_ops;
	info->flags = FBINFO_DEFAULT;
	info->pseudo_palette = par->palette;

	ret = register_framebuffer(info);
	if (ret < 0) {
		pci_err(pdev, "mdpy-fb device register failed: %d\n", ret);
		goto err_unmap;
	}

	pci_info(pdev, "fb%d registered\n", info->node);
	return 0;

err_unmap:
	iounmap(info->screen_base);

err_release_fb:
	framebuffer_release(info);

err_release_regions:
	pci_release_regions(pdev);

	return ret;
}

__attribute__((used)) static void mdpy_fb_remove(struct pci_dev *pdev)
{
	struct fb_info *info = pci_get_drvdata(pdev);

	unregister_framebuffer(info);
	framebuffer_release(info);
}

