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
typedef  unsigned long u32 ;
struct resource {int dummy; } ;
struct TYPE_3__ {void* platform_data; } ;
struct platform_device {TYPE_1__ dev; } ;
struct of_device_id {scalar_t__ data; } ;
struct mvebu_mpp_ctrl_data {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  IORESOURCE_MEM ; 
 scalar_t__ IS_ERR (scalar_t__) ; 
 unsigned int MVEBU_MPPS_PER_REG ; 
 unsigned int MVEBU_MPP_BITS ; 
 unsigned int MVEBU_MPP_MASK ; 
 int PTR_ERR (scalar_t__) ; 
 scalar_t__ devm_ioremap_resource (TYPE_1__*,struct resource*) ; 
 scalar_t__ high_mpp_base ; 
 scalar_t__ mpp_base ; 
 int mvebu_pinctrl_probe (struct platform_device*) ; 
 struct of_device_id* of_match_device (int /*<<< orphan*/ ,TYPE_1__*) ; 
 int /*<<< orphan*/  orion_pinctrl_of_match ; 
 struct resource* platform_get_resource (struct platform_device*,int /*<<< orphan*/ ,int) ; 
 unsigned int readl (scalar_t__) ; 
 int /*<<< orphan*/  writel (unsigned long,scalar_t__) ; 

__attribute__((used)) static int orion_mpp_ctrl_get(struct mvebu_mpp_ctrl_data *data,
			      unsigned pid, unsigned long *config)
{
	unsigned shift = (pid % MVEBU_MPPS_PER_REG) * MVEBU_MPP_BITS;

	if (pid < 16) {
		unsigned off = (pid / MVEBU_MPPS_PER_REG) * MVEBU_MPP_BITS;
		*config = (readl(mpp_base + off) >> shift) & MVEBU_MPP_MASK;
	}
	else {
		*config = (readl(high_mpp_base) >> shift) & MVEBU_MPP_MASK;
	}

	return 0;
}

__attribute__((used)) static int orion_mpp_ctrl_set(struct mvebu_mpp_ctrl_data *data,
			      unsigned pid, unsigned long config)
{
	unsigned shift = (pid % MVEBU_MPPS_PER_REG) * MVEBU_MPP_BITS;

	if (pid < 16) {
		unsigned off = (pid / MVEBU_MPPS_PER_REG) * MVEBU_MPP_BITS;
		u32 reg = readl(mpp_base + off) & ~(MVEBU_MPP_MASK << shift);
		writel(reg | (config << shift), mpp_base + off);
	}
	else {
		u32 reg = readl(high_mpp_base) & ~(MVEBU_MPP_MASK << shift);
		writel(reg | (config << shift), high_mpp_base);
	}

	return 0;
}

__attribute__((used)) static int orion_pinctrl_probe(struct platform_device *pdev)
{
	const struct of_device_id *match =
		of_match_device(orion_pinctrl_of_match, &pdev->dev);
	struct resource *res;

	pdev->dev.platform_data = (void*)match->data;

	res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
	mpp_base = devm_ioremap_resource(&pdev->dev, res);
	if (IS_ERR(mpp_base))
		return PTR_ERR(mpp_base);

	res = platform_get_resource(pdev, IORESOURCE_MEM, 1);
	high_mpp_base = devm_ioremap_resource(&pdev->dev, res);
	if (IS_ERR(high_mpp_base))
		return PTR_ERR(high_mpp_base);

	return mvebu_pinctrl_probe(pdev);
}

