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
typedef  struct TYPE_5__   TYPE_1__ ;

/* Type definitions */
struct mfd_cell {int dummy; } ;
struct TYPE_6__ {struct gpio_desc* reset; } ;
struct madera {int type; int num_micbias; int* num_childbias; int num_core_supplies; unsigned int rev; TYPE_1__* core_supplies; struct device* dev; struct gpio_desc* dcvdd; int /*<<< orphan*/  irq; int /*<<< orphan*/  regmap; int /*<<< orphan*/  type_name; TYPE_3__ pdata; int /*<<< orphan*/  regmap_32bit; int /*<<< orphan*/  notifier; } ;
struct gpio_desc {int dummy; } ;
struct device {int dummy; } ;
typedef  enum madera_type { ____Placeholder_madera_type } madera_type ;
struct TYPE_5__ {struct mfd_cell supply; } ;

/* Variables and functions */
 int ARRAY_SIZE (struct mfd_cell const*) ; 
 int /*<<< orphan*/  BLOCKING_INIT_NOTIFIER_HEAD (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  CONFIG_MFD_CS47L35 ; 
 int /*<<< orphan*/  CONFIG_MFD_CS47L85 ; 
 int /*<<< orphan*/  CONFIG_MFD_CS47L90 ; 
#define  CS47L35 135 
#define  CS47L35_SILICON_ID 134 
#define  CS47L85 133 
#define  CS47L85_SILICON_ID 132 
#define  CS47L90 131 
#define  CS47L90_SILICON_ID 130 
#define  CS47L91 129 
 int EINVAL ; 
 int ENODEV ; 
 int EPROBE_DEFER ; 
 int /*<<< orphan*/  GPIOD_OUT_LOW ; 
 int /*<<< orphan*/  IS_ENABLED (int /*<<< orphan*/ ) ; 
 scalar_t__ IS_ERR (struct gpio_desc*) ; 
 int MADERA_32KZ_MCLK2 ; 
 int /*<<< orphan*/  MADERA_BOOT_DONE_EINT1 ; 
 unsigned int MADERA_BOOT_DONE_STS1 ; 
 int /*<<< orphan*/  MADERA_BOOT_POLL_MAX_INTERVAL_US ; 
 int /*<<< orphan*/  MADERA_BOOT_POLL_TIMEOUT_US ; 
 int MADERA_CLK_32K_ENA ; 
 int MADERA_CLK_32K_ENA_MASK ; 
 int MADERA_CLK_32K_SRC_MASK ; 
 int /*<<< orphan*/  MADERA_CLOCK_32K_1 ; 
 int /*<<< orphan*/  MADERA_HARDWARE_REVISION ; 
 unsigned int MADERA_HW_REVISION_MASK ; 
 int /*<<< orphan*/  MADERA_IRQ1_RAW_STATUS_1 ; 
 int /*<<< orphan*/  MADERA_IRQ1_STATUS_1 ; 
 int /*<<< orphan*/  MADERA_SOFTWARE_RESET ; 
 int /*<<< orphan*/  PLATFORM_DEVID_NONE ; 
 int PTR_ERR (struct gpio_desc*) ; 
#define  WM1840 128 
 struct mfd_cell const* cs47l35_devs ; 
 int cs47l35_patch (struct madera*) ; 
 struct mfd_cell const* cs47l85_devs ; 
 int cs47l85_patch (struct madera*) ; 
 struct mfd_cell const* cs47l90_devs ; 
 int cs47l90_patch (struct madera*) ; 
 int /*<<< orphan*/  dev_err (struct device*,char*,int,...) ; 
 scalar_t__ dev_get_platdata (struct device*) ; 
 int /*<<< orphan*/  dev_info (struct device*,char*,int /*<<< orphan*/ ,unsigned int) ; 
 int /*<<< orphan*/  dev_set_drvdata (struct device*,struct madera*) ; 
 int /*<<< orphan*/  dev_warn (struct device*,char*) ; 
 struct gpio_desc* devm_gpiod_get_optional (struct device*,char*,int /*<<< orphan*/ ) ; 
 int devm_regulator_bulk_get (struct device*,int,TYPE_1__*) ; 
 int /*<<< orphan*/  disable_irq (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  gpiod_set_raw_value_cansleep (struct gpio_desc*,int) ; 
 struct mfd_cell const* madera_core_supplies ; 
 struct mfd_cell const* madera_ldo1_devs ; 
 int /*<<< orphan*/  memcpy (TYPE_3__*,scalar_t__,int) ; 
 int mfd_add_devices (struct device*,int /*<<< orphan*/ ,struct mfd_cell const*,int,int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mfd_remove_devices (struct device*) ; 
 int /*<<< orphan*/  pm_runtime_disable (struct device*) ; 
 int /*<<< orphan*/  pm_runtime_enable (struct device*) ; 
 int /*<<< orphan*/  pm_runtime_mark_last_busy (struct device*) ; 
 int /*<<< orphan*/  pm_runtime_set_active (struct device*) ; 
 int /*<<< orphan*/  pm_runtime_set_autosuspend_delay (struct device*,int) ; 
 int /*<<< orphan*/  pm_runtime_use_autosuspend (struct device*) ; 
 int /*<<< orphan*/  regcache_cache_only (int /*<<< orphan*/ ,int) ; 
 int regmap_read (int /*<<< orphan*/ ,int /*<<< orphan*/ ,unsigned int*) ; 
 int regmap_read_poll_timeout (int /*<<< orphan*/ ,int /*<<< orphan*/ ,unsigned int,unsigned int,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int regmap_update_bits (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int,int) ; 
 int regmap_write (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  regulator_bulk_disable (int,TYPE_1__*) ; 
 int regulator_bulk_enable (int,TYPE_1__*) ; 
 int /*<<< orphan*/  regulator_disable (struct gpio_desc*) ; 
 int regulator_enable (struct gpio_desc*) ; 
 struct gpio_desc* regulator_get (struct device*,char*) ; 
 int /*<<< orphan*/  regulator_put (struct gpio_desc*) ; 
 int /*<<< orphan*/  usleep_range (int,int) ; 

const char *madera_name_from_type(enum madera_type type)
{
	switch (type) {
	case CS47L35:
		return "CS47L35";
	case CS47L85:
		return "CS47L85";
	case CS47L90:
		return "CS47L90";
	case CS47L91:
		return "CS47L91";
	case WM1840:
		return "WM1840";
	default:
		return "Unknown";
	}
}

__attribute__((used)) static int madera_wait_for_boot(struct madera *madera)
{
	unsigned int val;
	int ret;

	/*
	 * We can't use an interrupt as we need to runtime resume to do so,
	 * so we poll the status bit. This won't race with the interrupt
	 * handler because it will be blocked on runtime resume.
	 */
	ret = regmap_read_poll_timeout(madera->regmap,
				       MADERA_IRQ1_RAW_STATUS_1,
				       val,
				       (val & MADERA_BOOT_DONE_STS1),
				       MADERA_BOOT_POLL_MAX_INTERVAL_US,
				       MADERA_BOOT_POLL_TIMEOUT_US);

	if (ret)
		dev_err(madera->dev, "Polling BOOT_DONE_STS failed: %d\n", ret);

	/*
	 * BOOT_DONE defaults to unmasked on boot so we must ack it.
	 * Do this unconditionally to avoid interrupt storms.
	 */
	regmap_write(madera->regmap, MADERA_IRQ1_STATUS_1,
		     MADERA_BOOT_DONE_EINT1);

	pm_runtime_mark_last_busy(madera->dev);

	return ret;
}

__attribute__((used)) static int madera_soft_reset(struct madera *madera)
{
	int ret;

	ret = regmap_write(madera->regmap, MADERA_SOFTWARE_RESET, 0);
	if (ret != 0) {
		dev_err(madera->dev, "Failed to soft reset device: %d\n", ret);
		return ret;
	}

	/* Allow time for internal clocks to startup after reset */
	usleep_range(1000, 2000);

	return 0;
}

__attribute__((used)) static void madera_enable_hard_reset(struct madera *madera)
{
	if (!madera->pdata.reset)
		return;

	/*
	 * There are many existing out-of-tree users of these codecs that we
	 * can't break so preserve the expected behaviour of setting the line
	 * low to assert reset.
	 */
	gpiod_set_raw_value_cansleep(madera->pdata.reset, 0);
}

__attribute__((used)) static void madera_disable_hard_reset(struct madera *madera)
{
	if (!madera->pdata.reset)
		return;

	gpiod_set_raw_value_cansleep(madera->pdata.reset, 1);
	usleep_range(1000, 2000);
}

__attribute__((used)) static int madera_get_reset_gpio(struct madera *madera)
{
	struct gpio_desc *reset;
	int ret;

	if (madera->pdata.reset)
		return 0;

	reset = devm_gpiod_get_optional(madera->dev, "reset", GPIOD_OUT_LOW);
	if (IS_ERR(reset)) {
		ret = PTR_ERR(reset);
		if (ret != -EPROBE_DEFER)
			dev_err(madera->dev, "Failed to request /RESET: %d\n",
				ret);
		return ret;
	}

	/*
	 * A hard reset is needed for full reset of the chip. We allow running
	 * without hard reset only because it can be useful for early
	 * prototyping and some debugging, but we need to warn it's not ideal.
	 */
	if (!reset)
		dev_warn(madera->dev,
			 "Running without reset GPIO is not recommended\n");

	madera->pdata.reset = reset;

	return 0;
}

__attribute__((used)) static void madera_set_micbias_info(struct madera *madera)
{
	/*
	 * num_childbias is an array because future codecs can have different
	 * childbiases for each micbias. Unspecified values default to 0.
	 */
	switch (madera->type) {
	case CS47L35:
		madera->num_micbias = 2;
		madera->num_childbias[0] = 2;
		madera->num_childbias[1] = 2;
		return;
	case CS47L85:
	case WM1840:
		madera->num_micbias = 4;
		/* no child biases */
		return;
	case CS47L90:
	case CS47L91:
		madera->num_micbias = 2;
		madera->num_childbias[0] = 4;
		madera->num_childbias[1] = 4;
		return;
	default:
		return;
	}
}

int madera_dev_init(struct madera *madera)
{
	struct device *dev = madera->dev;
	unsigned int hwid;
	int (*patch_fn)(struct madera *) = NULL;
	const struct mfd_cell *mfd_devs;
	int n_devs = 0;
	int i, ret;

	dev_set_drvdata(madera->dev, madera);
	BLOCKING_INIT_NOTIFIER_HEAD(&madera->notifier);
	madera_set_micbias_info(madera);

	/*
	 * We need writable hw config info that all children can share.
	 * Simplest to take one shared copy of pdata struct.
	 */
	if (dev_get_platdata(madera->dev)) {
		memcpy(&madera->pdata, dev_get_platdata(madera->dev),
		       sizeof(madera->pdata));
	}

	ret = madera_get_reset_gpio(madera);
	if (ret)
		return ret;

	regcache_cache_only(madera->regmap, true);
	regcache_cache_only(madera->regmap_32bit, true);

	for (i = 0; i < ARRAY_SIZE(madera_core_supplies); i++)
		madera->core_supplies[i].supply = madera_core_supplies[i];

	madera->num_core_supplies = ARRAY_SIZE(madera_core_supplies);

	/*
	 * On some codecs DCVDD could be supplied by the internal LDO1.
	 * For those we must add the LDO1 driver before requesting DCVDD
	 * No devm_ because we need to control shutdown order of children.
	 */
	switch (madera->type) {
	case CS47L35:
	case CS47L90:
	case CS47L91:
		break;
	case CS47L85:
	case WM1840:
		ret = mfd_add_devices(madera->dev, PLATFORM_DEVID_NONE,
				      madera_ldo1_devs,
				      ARRAY_SIZE(madera_ldo1_devs),
				      NULL, 0, NULL);
		if (ret) {
			dev_err(dev, "Failed to add LDO1 child: %d\n", ret);
			return ret;
		}
		break;
	default:
		/* No point continuing if the type is unknown */
		dev_err(madera->dev, "Unknown device type %d\n", madera->type);
		return -ENODEV;
	}

	ret = devm_regulator_bulk_get(dev, madera->num_core_supplies,
				      madera->core_supplies);
	if (ret) {
		dev_err(dev, "Failed to request core supplies: %d\n", ret);
		goto err_devs;
	}

	/*
	 * Don't use devres here. If the regulator is one of our children it
	 * will already have been removed before devres cleanup on this mfd
	 * driver tries to call put() on it. We need control of shutdown order.
	 */
	madera->dcvdd = regulator_get(madera->dev, "DCVDD");
	if (IS_ERR(madera->dcvdd)) {
		ret = PTR_ERR(madera->dcvdd);
		dev_err(dev, "Failed to request DCVDD: %d\n", ret);
		goto err_devs;
	}

	ret = regulator_bulk_enable(madera->num_core_supplies,
				    madera->core_supplies);
	if (ret) {
		dev_err(dev, "Failed to enable core supplies: %d\n", ret);
		goto err_dcvdd;
	}

	ret = regulator_enable(madera->dcvdd);
	if (ret) {
		dev_err(dev, "Failed to enable DCVDD: %d\n", ret);
		goto err_enable;
	}

	madera_disable_hard_reset(madera);

	regcache_cache_only(madera->regmap, false);
	regcache_cache_only(madera->regmap_32bit, false);

	/*
	 * Now we can power up and verify that this is a chip we know about
	 * before we start doing any writes to its registers.
	 */
	ret = regmap_read(madera->regmap, MADERA_SOFTWARE_RESET, &hwid);
	if (ret) {
		dev_err(dev, "Failed to read ID register: %d\n", ret);
		goto err_reset;
	}

	switch (hwid) {
	case CS47L35_SILICON_ID:
		if (IS_ENABLED(CONFIG_MFD_CS47L35)) {
			switch (madera->type) {
			case CS47L35:
				patch_fn = cs47l35_patch;
				mfd_devs = cs47l35_devs;
				n_devs = ARRAY_SIZE(cs47l35_devs);
				break;
			default:
				break;
			}
		}
		break;
	case CS47L85_SILICON_ID:
		if (IS_ENABLED(CONFIG_MFD_CS47L85)) {
			switch (madera->type) {
			case CS47L85:
			case WM1840:
				patch_fn = cs47l85_patch;
				mfd_devs = cs47l85_devs;
				n_devs = ARRAY_SIZE(cs47l85_devs);
				break;
			default:
				break;
			}
		}
		break;
	case CS47L90_SILICON_ID:
		if (IS_ENABLED(CONFIG_MFD_CS47L90)) {
			switch (madera->type) {
			case CS47L90:
			case CS47L91:
				patch_fn = cs47l90_patch;
				mfd_devs = cs47l90_devs;
				n_devs = ARRAY_SIZE(cs47l90_devs);
				break;
			default:
				break;
			}
		}
		break;
	default:
		dev_err(madera->dev, "Unknown device ID: %x\n", hwid);
		ret = -EINVAL;
		goto err_reset;
	}

	if (!n_devs) {
		dev_err(madera->dev, "Device ID 0x%x not a %s\n", hwid,
			madera->type_name);
		ret = -ENODEV;
		goto err_reset;
	}

	/*
	 * It looks like a device we support. If we don't have a hard reset
	 * we can now attempt a soft reset.
	 */
	if (!madera->pdata.reset) {
		ret = madera_soft_reset(madera);
		if (ret)
			goto err_reset;
	}

	ret = madera_wait_for_boot(madera);
	if (ret) {
		dev_err(madera->dev, "Device failed initial boot: %d\n", ret);
		goto err_reset;
	}

	ret = regmap_read(madera->regmap, MADERA_HARDWARE_REVISION,
			  &madera->rev);
	if (ret) {
		dev_err(dev, "Failed to read revision register: %d\n", ret);
		goto err_reset;
	}
	madera->rev &= MADERA_HW_REVISION_MASK;

	dev_info(dev, "%s silicon revision %d\n", madera->type_name,
		 madera->rev);

	/* Apply hardware patch */
	if (patch_fn) {
		ret = patch_fn(madera);
		if (ret) {
			dev_err(madera->dev, "Failed to apply patch %d\n", ret);
			goto err_reset;
		}
	}

	/* Init 32k clock sourced from MCLK2 */
	ret = regmap_update_bits(madera->regmap,
			MADERA_CLOCK_32K_1,
			MADERA_CLK_32K_ENA_MASK | MADERA_CLK_32K_SRC_MASK,
			MADERA_CLK_32K_ENA | MADERA_32KZ_MCLK2);
	if (ret) {
		dev_err(madera->dev, "Failed to init 32k clock: %d\n", ret);
		goto err_reset;
	}

	pm_runtime_set_active(madera->dev);
	pm_runtime_enable(madera->dev);
	pm_runtime_set_autosuspend_delay(madera->dev, 100);
	pm_runtime_use_autosuspend(madera->dev);

	/* No devm_ because we need to control shutdown order of children */
	ret = mfd_add_devices(madera->dev, PLATFORM_DEVID_NONE,
			      mfd_devs, n_devs,
			      NULL, 0, NULL);
	if (ret) {
		dev_err(madera->dev, "Failed to add subdevices: %d\n", ret);
		goto err_pm_runtime;
	}

	return 0;

err_pm_runtime:
	pm_runtime_disable(madera->dev);
err_reset:
	madera_enable_hard_reset(madera);
	regulator_disable(madera->dcvdd);
err_enable:
	regulator_bulk_disable(madera->num_core_supplies,
			       madera->core_supplies);
err_dcvdd:
	regulator_put(madera->dcvdd);
err_devs:
	mfd_remove_devices(dev);

	return ret;
}

int madera_dev_exit(struct madera *madera)
{
	/* Prevent any IRQs being serviced while we clean up */
	disable_irq(madera->irq);

	/*
	 * DCVDD could be supplied by a child node, we must disable it before
	 * removing the children, and prevent PM runtime from turning it back on
	 */
	pm_runtime_disable(madera->dev);

	regulator_disable(madera->dcvdd);
	regulator_put(madera->dcvdd);

	mfd_remove_devices(madera->dev);
	madera_enable_hard_reset(madera);

	regulator_bulk_disable(madera->num_core_supplies,
			       madera->core_supplies);
	return 0;
}

