#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  u32 ;
typedef  int u16 ;
struct device {int dummy; } ;
struct platform_device {struct device dev; } ;
struct csc_data {scalar_t__ base; TYPE_1__* res; struct platform_device* pdev; } ;
struct colorspace_coeffs {int* sd; int* hd; } ;
typedef  enum v4l2_colorspace { ____Placeholder_v4l2_colorspace } v4l2_colorspace ;
struct TYPE_3__ {int /*<<< orphan*/  start; } ;

/* Variables and functions */
 int /*<<< orphan*/  CSC_BYPASS ; 
 scalar_t__ CSC_CSC00 ; 
 scalar_t__ CSC_CSC01 ; 
 scalar_t__ CSC_CSC02 ; 
 scalar_t__ CSC_CSC03 ; 
 scalar_t__ CSC_CSC04 ; 
 scalar_t__ CSC_CSC05 ; 
 int /*<<< orphan*/  ENODEV ; 
 int /*<<< orphan*/  ENOMEM ; 
 struct csc_data* ERR_CAST (scalar_t__) ; 
 struct csc_data* ERR_PTR (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int /*<<< orphan*/  IORESOURCE_MEM ; 
 scalar_t__ IS_ERR (scalar_t__) ; 
 int V4L2_COLORSPACE_REC709 ; 
 int V4L2_COLORSPACE_SMPTE170M ; 
 int V4L2_COLORSPACE_SRGB ; 
 struct colorspace_coeffs* colorspace_coeffs ; 
 int /*<<< orphan*/  dev_dbg (struct device*,char*,...) ; 
 int /*<<< orphan*/  dev_err (struct device*,char*,...) ; 
 scalar_t__ devm_ioremap_resource (struct device*,TYPE_1__*) ; 
 struct csc_data* devm_kzalloc (struct device*,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ioread32 (scalar_t__) ; 
 TYPE_1__* platform_get_resource_byname (struct platform_device*,int /*<<< orphan*/ ,char const*) ; 

void csc_dump_regs(struct csc_data *csc)
{
	struct device *dev = &csc->pdev->dev;

#define DUMPREG(r) dev_dbg(dev, "%-35s %08x\n", #r, \
	ioread32(csc->base + CSC_##r))

	dev_dbg(dev, "CSC Registers @ %pa:\n", &csc->res->start);

	DUMPREG(CSC00);
	DUMPREG(CSC01);
	DUMPREG(CSC02);
	DUMPREG(CSC03);
	DUMPREG(CSC04);
	DUMPREG(CSC05);

#undef DUMPREG
}

void csc_set_coeff_bypass(struct csc_data *csc, u32 *csc_reg5)
{
	*csc_reg5 |= CSC_BYPASS;
}

void csc_set_coeff(struct csc_data *csc, u32 *csc_reg0,
		enum v4l2_colorspace src_colorspace,
		enum v4l2_colorspace dst_colorspace)
{
	u32 *csc_reg5 = csc_reg0 + 5;
	u32 *shadow_csc = csc_reg0;
	struct colorspace_coeffs *sd_hd_coeffs;
	u16 *coeff, *end_coeff;
	enum v4l2_colorspace yuv_colorspace;
	int sel = 0;

	/*
	 * support only graphics data range(full range) for now, a control ioctl
	 * would be nice here
	 */
	/* Y2R */
	if (dst_colorspace == V4L2_COLORSPACE_SRGB &&
			(src_colorspace == V4L2_COLORSPACE_SMPTE170M ||
			src_colorspace == V4L2_COLORSPACE_REC709)) {
		/* Y2R */
		sel = 1;
		yuv_colorspace = src_colorspace;
	} else if ((dst_colorspace == V4L2_COLORSPACE_SMPTE170M ||
			dst_colorspace == V4L2_COLORSPACE_REC709) &&
			src_colorspace == V4L2_COLORSPACE_SRGB) {
		/* R2Y */
		sel = 3;
		yuv_colorspace = dst_colorspace;
	} else {
		*csc_reg5 |= CSC_BYPASS;
		return;
	}

	sd_hd_coeffs = &colorspace_coeffs[sel];

	/* select between SD or HD coefficients */
	if (yuv_colorspace == V4L2_COLORSPACE_SMPTE170M)
		coeff = sd_hd_coeffs->sd;
	else
		coeff = sd_hd_coeffs->hd;

	end_coeff = coeff + 12;

	for (; coeff < end_coeff; coeff += 2)
		*shadow_csc++ = (*(coeff + 1) << 16) | *coeff;
}

struct csc_data *csc_create(struct platform_device *pdev, const char *res_name)
{
	struct csc_data *csc;

	dev_dbg(&pdev->dev, "csc_create\n");

	csc = devm_kzalloc(&pdev->dev, sizeof(*csc), GFP_KERNEL);
	if (!csc) {
		dev_err(&pdev->dev, "couldn't alloc csc_data\n");
		return ERR_PTR(-ENOMEM);
	}

	csc->pdev = pdev;

	csc->res = platform_get_resource_byname(pdev, IORESOURCE_MEM,
						res_name);
	if (csc->res == NULL) {
		dev_err(&pdev->dev, "missing '%s' platform resources data\n",
			res_name);
		return ERR_PTR(-ENODEV);
	}

	csc->base = devm_ioremap_resource(&pdev->dev, csc->res);
	if (IS_ERR(csc->base)) {
		dev_err(&pdev->dev, "failed to ioremap\n");
		return ERR_CAST(csc->base);
	}

	return csc;
}

