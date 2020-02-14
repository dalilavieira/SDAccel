#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_24__   TYPE_9__ ;
typedef  struct TYPE_23__   TYPE_8__ ;
typedef  struct TYPE_22__   TYPE_7__ ;
typedef  struct TYPE_21__   TYPE_6__ ;
typedef  struct TYPE_20__   TYPE_5__ ;
typedef  struct TYPE_19__   TYPE_4__ ;
typedef  struct TYPE_18__   TYPE_3__ ;
typedef  struct TYPE_17__   TYPE_2__ ;
typedef  struct TYPE_16__   TYPE_1__ ;
typedef  struct TYPE_15__   TYPE_13__ ;

/* Type definitions */
typedef  int u_int ;
typedef  int u32 ;
struct simplefb_platform_data {char const* format; int /*<<< orphan*/  stride; int /*<<< orphan*/  height; int /*<<< orphan*/  width; } ;
struct simplefb_params {TYPE_7__* format; int /*<<< orphan*/  height; int /*<<< orphan*/  width; int /*<<< orphan*/  stride; } ;
struct simplefb_par {int* palette; } ;
struct resource {int /*<<< orphan*/  start; } ;
struct TYPE_24__ {struct device_node* of_node; } ;
struct platform_device {TYPE_9__ dev; } ;
struct TYPE_23__ {int /*<<< orphan*/  line_length; int /*<<< orphan*/  smem_len; int /*<<< orphan*/  smem_start; } ;
struct TYPE_20__ {int length; int offset; } ;
struct TYPE_19__ {int length; int offset; } ;
struct TYPE_18__ {int length; int offset; } ;
struct TYPE_17__ {int length; int offset; } ;
struct TYPE_21__ {int /*<<< orphan*/  bits_per_pixel; int /*<<< orphan*/  yres; int /*<<< orphan*/  xres; TYPE_5__ transp; TYPE_4__ blue; TYPE_3__ green; TYPE_2__ red; int /*<<< orphan*/  yres_virtual; int /*<<< orphan*/  xres_virtual; } ;
struct fb_info {int* pseudo_palette; int flags; scalar_t__ screen_base; int /*<<< orphan*/  node; TYPE_8__ fix; TYPE_6__ var; int /*<<< orphan*/ * fbops; TYPE_13__* apertures; struct simplefb_par* par; } ;
struct device_node {int dummy; } ;
struct TYPE_22__ {int /*<<< orphan*/  name; TYPE_5__ transp; TYPE_4__ blue; TYPE_3__ green; TYPE_2__ red; int /*<<< orphan*/  bits_per_pixel; } ;
struct TYPE_16__ {int /*<<< orphan*/  size; int /*<<< orphan*/  base; } ;
struct TYPE_15__ {TYPE_1__* ranges; } ;

/* Variables and functions */
 int ARRAY_SIZE (TYPE_7__*) ; 
 int EINVAL ; 
 int ENODEV ; 
 int ENOMEM ; 
 int FBINFO_DEFAULT ; 
 int FBINFO_MISC_FIRMWARE ; 
 int /*<<< orphan*/  IORESOURCE_MEM ; 
 int PSEUDO_PALETTE_SIZE ; 
 TYPE_13__* alloc_apertures (int) ; 
 int /*<<< orphan*/  dev_err (TYPE_9__*,char*,...) ; 
 struct simplefb_platform_data* dev_get_platdata (TYPE_9__*) ; 
 int /*<<< orphan*/  dev_info (TYPE_9__*,char*,int /*<<< orphan*/ ,...) ; 
 scalar_t__ fb_get_options (char*,int /*<<< orphan*/ *) ; 
 struct fb_info* framebuffer_alloc (int,TYPE_9__*) ; 
 int /*<<< orphan*/  framebuffer_release (struct fb_info*) ; 
 scalar_t__ ioremap_wc (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  iounmap (scalar_t__) ; 
 int of_property_read_string (struct device_node*,char*,char const**) ; 
 int of_property_read_u32 (struct device_node*,char*,int /*<<< orphan*/ *) ; 
 struct fb_info* platform_get_drvdata (struct platform_device*) ; 
 struct resource* platform_get_resource (struct platform_device*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  platform_set_drvdata (struct platform_device*,struct fb_info*) ; 
 int register_framebuffer (struct fb_info*) ; 
 int /*<<< orphan*/  resource_size (struct resource*) ; 
static  void simplefb_clocks_destroy (struct simplefb_par*) ; 
 TYPE_8__ simplefb_fix ; 
 TYPE_7__* simplefb_formats ; 
 int /*<<< orphan*/  simplefb_ops ; 
static  void simplefb_regulators_destroy (struct simplefb_par*) ; 
 TYPE_6__ simplefb_var ; 
 scalar_t__ strcmp (char const*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  unregister_framebuffer (struct fb_info*) ; 

__attribute__((used)) static int simplefb_setcolreg(u_int regno, u_int red, u_int green, u_int blue,
			      u_int transp, struct fb_info *info)
{
	u32 *pal = info->pseudo_palette;
	u32 cr = red >> (16 - info->var.red.length);
	u32 cg = green >> (16 - info->var.green.length);
	u32 cb = blue >> (16 - info->var.blue.length);
	u32 value;

	if (regno >= PSEUDO_PALETTE_SIZE)
		return -EINVAL;

	value = (cr << info->var.red.offset) |
		(cg << info->var.green.offset) |
		(cb << info->var.blue.offset);
	if (info->var.transp.length > 0) {
		u32 mask = (1 << info->var.transp.length) - 1;
		mask <<= info->var.transp.offset;
		value |= mask;
	}
	pal[regno] = value;

	return 0;
}

__attribute__((used)) static void simplefb_destroy(struct fb_info *info)
{
	simplefb_regulators_destroy(info->par);
	simplefb_clocks_destroy(info->par);
	if (info->screen_base)
		iounmap(info->screen_base);
}

__attribute__((used)) static int simplefb_parse_dt(struct platform_device *pdev,
			   struct simplefb_params *params)
{
	struct device_node *np = pdev->dev.of_node;
	int ret;
	const char *format;
	int i;

	ret = of_property_read_u32(np, "width", &params->width);
	if (ret) {
		dev_err(&pdev->dev, "Can't parse width property\n");
		return ret;
	}

	ret = of_property_read_u32(np, "height", &params->height);
	if (ret) {
		dev_err(&pdev->dev, "Can't parse height property\n");
		return ret;
	}

	ret = of_property_read_u32(np, "stride", &params->stride);
	if (ret) {
		dev_err(&pdev->dev, "Can't parse stride property\n");
		return ret;
	}

	ret = of_property_read_string(np, "format", &format);
	if (ret) {
		dev_err(&pdev->dev, "Can't parse format property\n");
		return ret;
	}
	params->format = NULL;
	for (i = 0; i < ARRAY_SIZE(simplefb_formats); i++) {
		if (strcmp(format, simplefb_formats[i].name))
			continue;
		params->format = &simplefb_formats[i];
		break;
	}
	if (!params->format) {
		dev_err(&pdev->dev, "Invalid format value\n");
		return -EINVAL;
	}

	return 0;
}

__attribute__((used)) static int simplefb_parse_pd(struct platform_device *pdev,
			     struct simplefb_params *params)
{
	struct simplefb_platform_data *pd = dev_get_platdata(&pdev->dev);
	int i;

	params->width = pd->width;
	params->height = pd->height;
	params->stride = pd->stride;

	params->format = NULL;
	for (i = 0; i < ARRAY_SIZE(simplefb_formats); i++) {
		if (strcmp(pd->format, simplefb_formats[i].name))
			continue;

		params->format = &simplefb_formats[i];
		break;
	}

	if (!params->format) {
		dev_err(&pdev->dev, "Invalid format value\n");
		return -EINVAL;
	}

	return 0;
}

__attribute__((used)) static int simplefb_clocks_get(struct simplefb_par *par,
	struct platform_device *pdev) { return 0; }

__attribute__((used)) static void simplefb_clocks_enable(struct simplefb_par *par,
	struct platform_device *pdev) { }

__attribute__((used)) static void simplefb_clocks_destroy(struct simplefb_par *par) { }

__attribute__((used)) static int simplefb_regulators_get(struct simplefb_par *par,
	struct platform_device *pdev) { return 0; }

__attribute__((used)) static void simplefb_regulators_enable(struct simplefb_par *par,
	struct platform_device *pdev) { }

__attribute__((used)) static void simplefb_regulators_destroy(struct simplefb_par *par) { }

__attribute__((used)) static int simplefb_probe(struct platform_device *pdev)
{
	int ret;
	struct simplefb_params params;
	struct fb_info *info;
	struct simplefb_par *par;
	struct resource *mem;

	if (fb_get_options("simplefb", NULL))
		return -ENODEV;

	ret = -ENODEV;
	if (dev_get_platdata(&pdev->dev))
		ret = simplefb_parse_pd(pdev, &params);
	else if (pdev->dev.of_node)
		ret = simplefb_parse_dt(pdev, &params);

	if (ret)
		return ret;

	mem = platform_get_resource(pdev, IORESOURCE_MEM, 0);
	if (!mem) {
		dev_err(&pdev->dev, "No memory resource\n");
		return -EINVAL;
	}

	info = framebuffer_alloc(sizeof(struct simplefb_par), &pdev->dev);
	if (!info)
		return -ENOMEM;
	platform_set_drvdata(pdev, info);

	par = info->par;

	info->fix = simplefb_fix;
	info->fix.smem_start = mem->start;
	info->fix.smem_len = resource_size(mem);
	info->fix.line_length = params.stride;

	info->var = simplefb_var;
	info->var.xres = params.width;
	info->var.yres = params.height;
	info->var.xres_virtual = params.width;
	info->var.yres_virtual = params.height;
	info->var.bits_per_pixel = params.format->bits_per_pixel;
	info->var.red = params.format->red;
	info->var.green = params.format->green;
	info->var.blue = params.format->blue;
	info->var.transp = params.format->transp;

	info->apertures = alloc_apertures(1);
	if (!info->apertures) {
		ret = -ENOMEM;
		goto error_fb_release;
	}
	info->apertures->ranges[0].base = info->fix.smem_start;
	info->apertures->ranges[0].size = info->fix.smem_len;

	info->fbops = &simplefb_ops;
	info->flags = FBINFO_DEFAULT | FBINFO_MISC_FIRMWARE;
	info->screen_base = ioremap_wc(info->fix.smem_start,
				       info->fix.smem_len);
	if (!info->screen_base) {
		ret = -ENOMEM;
		goto error_fb_release;
	}
	info->pseudo_palette = par->palette;

	ret = simplefb_clocks_get(par, pdev);
	if (ret < 0)
		goto error_unmap;

	ret = simplefb_regulators_get(par, pdev);
	if (ret < 0)
		goto error_clocks;

	simplefb_clocks_enable(par, pdev);
	simplefb_regulators_enable(par, pdev);

	dev_info(&pdev->dev, "framebuffer at 0x%lx, 0x%x bytes, mapped to 0x%p\n",
			     info->fix.smem_start, info->fix.smem_len,
			     info->screen_base);
	dev_info(&pdev->dev, "format=%s, mode=%dx%dx%d, linelength=%d\n",
			     params.format->name,
			     info->var.xres, info->var.yres,
			     info->var.bits_per_pixel, info->fix.line_length);

	ret = register_framebuffer(info);
	if (ret < 0) {
		dev_err(&pdev->dev, "Unable to register simplefb: %d\n", ret);
		goto error_regulators;
	}

	dev_info(&pdev->dev, "fb%d: simplefb registered!\n", info->node);

	return 0;

error_regulators:
	simplefb_regulators_destroy(par);
error_clocks:
	simplefb_clocks_destroy(par);
error_unmap:
	iounmap(info->screen_base);
error_fb_release:
	framebuffer_release(info);
	return ret;
}

__attribute__((used)) static int simplefb_remove(struct platform_device *pdev)
{
	struct fb_info *info = platform_get_drvdata(pdev);

	unregister_framebuffer(info);
	framebuffer_release(info);

	return 0;
}

