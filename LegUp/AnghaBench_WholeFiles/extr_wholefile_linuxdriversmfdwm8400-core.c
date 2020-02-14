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
typedef  int /*<<< orphan*/  u8 ;
typedef  int /*<<< orphan*/  u16 ;
struct wm8400_platform_data {int (* platform_init ) (int /*<<< orphan*/ ) ;} ;
struct wm8400 {int /*<<< orphan*/  regmap; int /*<<< orphan*/  dev; } ;
struct mfd_cell {char* name; int pdata_size; struct wm8400* platform_data; } ;
struct device {int dummy; } ;

/* Variables and functions */
 int EIO ; 
 int ENODEV ; 
 unsigned int WM8400_CHIP_REV_MASK ; 
 unsigned int WM8400_CHIP_REV_SHIFT ; 
 int /*<<< orphan*/  WM8400_ID ; 
#define  WM8400_INTERRUPT_LEVELS 130 
#define  WM8400_INTERRUPT_STATUS_1 129 
 int /*<<< orphan*/  WM8400_RESET_ID ; 
#define  WM8400_SHUTDOWN_REASON 128 
 int /*<<< orphan*/  dev_err (int /*<<< orphan*/ ,char*,...) ; 
 int /*<<< orphan*/  dev_info (int /*<<< orphan*/ ,char*,unsigned int) ; 
 int /*<<< orphan*/  dev_set_drvdata (int /*<<< orphan*/ ,struct wm8400*) ; 
 int /*<<< orphan*/  dev_warn (int /*<<< orphan*/ ,char*) ; 
 int devm_mfd_add_devices (int /*<<< orphan*/ ,int,struct mfd_cell const*,int,int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int regmap_bulk_read (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ *,int) ; 
 int regmap_read (int /*<<< orphan*/ ,int /*<<< orphan*/ ,unsigned int*) ; 
 int /*<<< orphan*/  regmap_reinit_cache (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int stub1 (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  wm8400_regmap_config ; 

__attribute__((used)) static bool wm8400_volatile(struct device *dev, unsigned int reg)
{
	switch (reg) {
	case WM8400_INTERRUPT_STATUS_1:
	case WM8400_INTERRUPT_LEVELS:
	case WM8400_SHUTDOWN_REASON:
		return true;
	default:
		return false;
	}
}

int wm8400_block_read(struct wm8400 *wm8400, u8 reg, int count, u16 *data)
{
	return regmap_bulk_read(wm8400->regmap, reg, data, count);
}

__attribute__((used)) static int wm8400_register_codec(struct wm8400 *wm8400)
{
	const struct mfd_cell cell = {
		.name = "wm8400-codec",
		.platform_data = wm8400,
		.pdata_size = sizeof(*wm8400),
	};

	return devm_mfd_add_devices(wm8400->dev, -1, &cell, 1, NULL, 0, NULL);
}

__attribute__((used)) static int wm8400_init(struct wm8400 *wm8400,
		       struct wm8400_platform_data *pdata)
{
	unsigned int reg;
	int ret;

	dev_set_drvdata(wm8400->dev, wm8400);

	/* Check that this is actually a WM8400 */
	ret = regmap_read(wm8400->regmap, WM8400_RESET_ID, &reg);
	if (ret != 0) {
		dev_err(wm8400->dev, "Chip ID register read failed\n");
		return -EIO;
	}
	if (reg != 0x6172) {
		dev_err(wm8400->dev, "Device is not a WM8400, ID is %x\n",
			reg);
		return -ENODEV;
	}

	ret = regmap_read(wm8400->regmap, WM8400_ID, &reg);
	if (ret != 0) {
		dev_err(wm8400->dev, "ID register read failed: %d\n", ret);
		return ret;
	}
	reg = (reg & WM8400_CHIP_REV_MASK) >> WM8400_CHIP_REV_SHIFT;
	dev_info(wm8400->dev, "WM8400 revision %x\n", reg);

	ret = wm8400_register_codec(wm8400);
	if (ret != 0) {
		dev_err(wm8400->dev, "Failed to register codec\n");
		return ret;
	}

	if (pdata && pdata->platform_init) {
		ret = pdata->platform_init(wm8400->dev);
		if (ret != 0) {
			dev_err(wm8400->dev, "Platform init failed: %d\n",
				ret);
			return ret;
		}
	} else
		dev_warn(wm8400->dev, "No platform initialisation supplied\n");

	return 0;
}

void wm8400_reset_codec_reg_cache(struct wm8400 *wm8400)
{
	regmap_reinit_cache(wm8400->regmap, &wm8400_regmap_config);
}

