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
typedef  int u32 ;
struct mfd_cell {char* name; int /*<<< orphan*/  properties; } ;
struct intel_lpss_platform_info {scalar_t__ irq; TYPE_2__* mem; int /*<<< orphan*/  properties; int /*<<< orphan*/  clk_con_id; int /*<<< orphan*/  clk_rate; } ;
struct intel_lpss {int active_ltr; int idle_ltr; int caps; unsigned int type; int devid; int* priv_ctx; scalar_t__ priv; struct mfd_cell* cell; struct device* dev; struct intel_lpss_platform_info const* info; struct dentry* clk; int /*<<< orphan*/  clock; struct dentry* debugfs; } ;
struct TYPE_3__ {void (* set_latency_tolerance ) (struct device*,int) ;} ;
struct device {TYPE_1__ power; } ;
struct dentry {int dummy; } ;
typedef  struct dentry clk ;
typedef  int s32 ;
typedef  scalar_t__ resource_size_t ;
typedef  int /*<<< orphan*/  name ;
typedef  int /*<<< orphan*/  devname ;
struct TYPE_4__ {scalar_t__ start; } ;

/* Variables and functions */
 int /*<<< orphan*/  CLK_SET_RATE_PARENT ; 
 int /*<<< orphan*/  DPM_FLAG_SMART_SUSPEND ; 
 int EINVAL ; 
 int ENODEV ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 scalar_t__ IS_ERR (struct dentry*) ; 
 scalar_t__ IS_ERR_OR_NULL (struct dentry*) ; 
#define  LPSS_DEV_I2C 130 
#define  LPSS_DEV_SPI 129 
#define  LPSS_DEV_UART 128 
 char* LPSS_IDMA64_DRIVER_NAME ; 
 scalar_t__ LPSS_PRIV_ACTIVELTR ; 
 scalar_t__ LPSS_PRIV_CAPS ; 
 int LPSS_PRIV_CAPS_NO_IDMA ; 
 unsigned int LPSS_PRIV_CAPS_TYPE_MASK ; 
 unsigned int LPSS_PRIV_CAPS_TYPE_SHIFT ; 
 scalar_t__ LPSS_PRIV_IDLELTR ; 
 int LPSS_PRIV_LTR_REQ ; 
 int LPSS_PRIV_LTR_SCALE_1US ; 
 int LPSS_PRIV_LTR_SCALE_32US ; 
 int LPSS_PRIV_LTR_SCALE_MASK ; 
 int LPSS_PRIV_LTR_VALUE_MASK ; 
 scalar_t__ LPSS_PRIV_OFFSET ; 
 unsigned int LPSS_PRIV_REG_COUNT ; 
 scalar_t__ LPSS_PRIV_REMAP_ADDR ; 
 scalar_t__ LPSS_PRIV_RESETS ; 
 int LPSS_PRIV_RESETS_FUNC ; 
 int LPSS_PRIV_RESETS_IDMA ; 
 int /*<<< orphan*/  LPSS_PRIV_SIZE ; 
 scalar_t__ LPSS_PRIV_SSP_REG ; 
 int LPSS_PRIV_SSP_REG_DIS_DMA_FIN ; 
 int PM_QOS_LATENCY_ANY ; 
 int PTR_ERR (struct dentry*) ; 
 int /*<<< orphan*/  S_IRUGO ; 
 int /*<<< orphan*/  __clk_get_name (struct dentry*) ; 
 struct dentry* clk_get_parent (struct dentry*) ; 
 struct dentry* clk_register_fixed_rate (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 struct dentry* clk_register_fractional_divider (int /*<<< orphan*/ *,char*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,scalar_t__,int,int,int,int,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 struct dentry* clk_register_gate (int /*<<< orphan*/ *,char*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,scalar_t__,int,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  clk_unregister (struct dentry*) ; 
 int /*<<< orphan*/  clkdev_create (struct dentry*,int /*<<< orphan*/ ,char*,char*) ; 
 int /*<<< orphan*/  clkdev_drop (int /*<<< orphan*/ ) ; 
 struct dentry* debugfs_create_dir (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  debugfs_create_x32 (char*,int /*<<< orphan*/ ,struct dentry*,int*) ; 
 int /*<<< orphan*/  debugfs_remove_recursive (struct dentry*) ; 
 struct intel_lpss* dev_get_drvdata (struct device*) ; 
 int /*<<< orphan*/  dev_name (struct device*) ; 
 int /*<<< orphan*/  dev_pm_qos_expose_latency_tolerance (struct device*) ; 
 int /*<<< orphan*/  dev_pm_qos_hide_latency_tolerance (struct device*) ; 
 int /*<<< orphan*/  dev_pm_set_driver_flags (struct device*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  dev_pm_test_driver_flags (struct device*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  dev_set_drvdata (struct device*,struct intel_lpss*) ; 
 int /*<<< orphan*/  dev_warn (struct device*,char*,...) ; 
 int /*<<< orphan*/  device_for_each_child_reverse (struct device*,int /*<<< orphan*/ *,int (*) (struct device*,void*)) ; 
 scalar_t__ devm_ioremap (struct device*,scalar_t__,int /*<<< orphan*/ ) ; 
 struct mfd_cell* devm_kmemdup (struct device*,struct mfd_cell const*,int,int /*<<< orphan*/ ) ; 
 struct intel_lpss* devm_kzalloc (struct device*,int,int /*<<< orphan*/ ) ; 
 int ida_simple_get (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ida_simple_remove (int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  intel_lpss_debugfs ; 
 int /*<<< orphan*/  intel_lpss_devid_ida ; 
 struct mfd_cell intel_lpss_i2c_cell ; 
 struct mfd_cell intel_lpss_idma64_cell ; 
 struct mfd_cell intel_lpss_spi_cell ; 
 struct mfd_cell intel_lpss_uart_cell ; 
 int /*<<< orphan*/  lo_hi_writeq (scalar_t__,scalar_t__) ; 
 int mfd_add_devices (struct device*,int,struct mfd_cell*,int,TYPE_2__*,scalar_t__,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mfd_remove_devices (struct device*) ; 
 int /*<<< orphan*/  pm_runtime_resume (struct device*) ; 
 void* readl (scalar_t__) ; 
 int request_module (char*,char const*) ; 
 int /*<<< orphan*/  snprintf (char*,int,char*,char const*,...) ; 
 int /*<<< orphan*/  writel (int,scalar_t__) ; 

__attribute__((used)) static int intel_lpss_request_dma_module(const char *name)
{
	static bool intel_lpss_dma_requested;

	if (intel_lpss_dma_requested)
		return 0;

	intel_lpss_dma_requested = true;
	return request_module("%s", name);
}

__attribute__((used)) static void intel_lpss_cache_ltr(struct intel_lpss *lpss)
{
	lpss->active_ltr = readl(lpss->priv + LPSS_PRIV_ACTIVELTR);
	lpss->idle_ltr = readl(lpss->priv + LPSS_PRIV_IDLELTR);
}

__attribute__((used)) static int intel_lpss_debugfs_add(struct intel_lpss *lpss)
{
	struct dentry *dir;

	dir = debugfs_create_dir(dev_name(lpss->dev), intel_lpss_debugfs);
	if (IS_ERR(dir))
		return PTR_ERR(dir);

	/* Cache the values into lpss structure */
	intel_lpss_cache_ltr(lpss);

	debugfs_create_x32("capabilities", S_IRUGO, dir, &lpss->caps);
	debugfs_create_x32("active_ltr", S_IRUGO, dir, &lpss->active_ltr);
	debugfs_create_x32("idle_ltr", S_IRUGO, dir, &lpss->idle_ltr);

	lpss->debugfs = dir;
	return 0;
}

__attribute__((used)) static void intel_lpss_debugfs_remove(struct intel_lpss *lpss)
{
	debugfs_remove_recursive(lpss->debugfs);
}

__attribute__((used)) static void intel_lpss_ltr_set(struct device *dev, s32 val)
{
	struct intel_lpss *lpss = dev_get_drvdata(dev);
	u32 ltr;

	/*
	 * Program latency tolerance (LTR) accordingly what has been asked
	 * by the PM QoS layer or disable it in case we were passed
	 * negative value or PM_QOS_LATENCY_ANY.
	 */
	ltr = readl(lpss->priv + LPSS_PRIV_ACTIVELTR);

	if (val == PM_QOS_LATENCY_ANY || val < 0) {
		ltr &= ~LPSS_PRIV_LTR_REQ;
	} else {
		ltr |= LPSS_PRIV_LTR_REQ;
		ltr &= ~LPSS_PRIV_LTR_SCALE_MASK;
		ltr &= ~LPSS_PRIV_LTR_VALUE_MASK;

		if (val > LPSS_PRIV_LTR_VALUE_MASK)
			ltr |= LPSS_PRIV_LTR_SCALE_32US | val >> 5;
		else
			ltr |= LPSS_PRIV_LTR_SCALE_1US | val;
	}

	if (ltr == lpss->active_ltr)
		return;

	writel(ltr, lpss->priv + LPSS_PRIV_ACTIVELTR);
	writel(ltr, lpss->priv + LPSS_PRIV_IDLELTR);

	/* Cache the values into lpss structure */
	intel_lpss_cache_ltr(lpss);
}

__attribute__((used)) static void intel_lpss_ltr_expose(struct intel_lpss *lpss)
{
	lpss->dev->power.set_latency_tolerance = intel_lpss_ltr_set;
	dev_pm_qos_expose_latency_tolerance(lpss->dev);
}

__attribute__((used)) static void intel_lpss_ltr_hide(struct intel_lpss *lpss)
{
	dev_pm_qos_hide_latency_tolerance(lpss->dev);
	lpss->dev->power.set_latency_tolerance = NULL;
}

__attribute__((used)) static int intel_lpss_assign_devs(struct intel_lpss *lpss)
{
	const struct mfd_cell *cell;
	unsigned int type;

	type = lpss->caps & LPSS_PRIV_CAPS_TYPE_MASK;
	type >>= LPSS_PRIV_CAPS_TYPE_SHIFT;

	switch (type) {
	case LPSS_DEV_I2C:
		cell = &intel_lpss_i2c_cell;
		break;
	case LPSS_DEV_UART:
		cell = &intel_lpss_uart_cell;
		break;
	case LPSS_DEV_SPI:
		cell = &intel_lpss_spi_cell;
		break;
	default:
		return -ENODEV;
	}

	lpss->cell = devm_kmemdup(lpss->dev, cell, sizeof(*cell), GFP_KERNEL);
	if (!lpss->cell)
		return -ENOMEM;

	lpss->type = type;

	return 0;
}

__attribute__((used)) static bool intel_lpss_has_idma(const struct intel_lpss *lpss)
{
	return (lpss->caps & LPSS_PRIV_CAPS_NO_IDMA) == 0;
}

__attribute__((used)) static void intel_lpss_set_remap_addr(const struct intel_lpss *lpss)
{
	resource_size_t addr = lpss->info->mem->start;

	lo_hi_writeq(addr, lpss->priv + LPSS_PRIV_REMAP_ADDR);
}

__attribute__((used)) static void intel_lpss_deassert_reset(const struct intel_lpss *lpss)
{
	u32 value = LPSS_PRIV_RESETS_FUNC | LPSS_PRIV_RESETS_IDMA;

	/* Bring out the device from reset */
	writel(value, lpss->priv + LPSS_PRIV_RESETS);
}

__attribute__((used)) static void intel_lpss_init_dev(const struct intel_lpss *lpss)
{
	u32 value = LPSS_PRIV_SSP_REG_DIS_DMA_FIN;

	intel_lpss_deassert_reset(lpss);

	intel_lpss_set_remap_addr(lpss);

	if (!intel_lpss_has_idma(lpss))
		return;

	/* Make sure that SPI multiblock DMA transfers are re-enabled */
	if (lpss->type == LPSS_DEV_SPI)
		writel(value, lpss->priv + LPSS_PRIV_SSP_REG);
}

__attribute__((used)) static void intel_lpss_unregister_clock_tree(struct clk *clk)
{
	struct clk *parent;

	while (clk) {
		parent = clk_get_parent(clk);
		clk_unregister(clk);
		clk = parent;
	}
}

__attribute__((used)) static int intel_lpss_register_clock_divider(struct intel_lpss *lpss,
					     const char *devname,
					     struct clk **clk)
{
	char name[32];
	struct clk *tmp = *clk;

	snprintf(name, sizeof(name), "%s-enable", devname);
	tmp = clk_register_gate(NULL, name, __clk_get_name(tmp), 0,
				lpss->priv, 0, 0, NULL);
	if (IS_ERR(tmp))
		return PTR_ERR(tmp);

	snprintf(name, sizeof(name), "%s-div", devname);
	tmp = clk_register_fractional_divider(NULL, name, __clk_get_name(tmp),
					      0, lpss->priv, 1, 15, 16, 15, 0,
					      NULL);
	if (IS_ERR(tmp))
		return PTR_ERR(tmp);
	*clk = tmp;

	snprintf(name, sizeof(name), "%s-update", devname);
	tmp = clk_register_gate(NULL, name, __clk_get_name(tmp),
				CLK_SET_RATE_PARENT, lpss->priv, 31, 0, NULL);
	if (IS_ERR(tmp))
		return PTR_ERR(tmp);
	*clk = tmp;

	return 0;
}

__attribute__((used)) static int intel_lpss_register_clock(struct intel_lpss *lpss)
{
	const struct mfd_cell *cell = lpss->cell;
	struct clk *clk;
	char devname[24];
	int ret;

	if (!lpss->info->clk_rate)
		return 0;

	/* Root clock */
	clk = clk_register_fixed_rate(NULL, dev_name(lpss->dev), NULL, 0,
				      lpss->info->clk_rate);
	if (IS_ERR(clk))
		return PTR_ERR(clk);

	snprintf(devname, sizeof(devname), "%s.%d", cell->name, lpss->devid);

	/*
	 * Support for clock divider only if it has some preset value.
	 * Otherwise we assume that the divider is not used.
	 */
	if (lpss->type != LPSS_DEV_I2C) {
		ret = intel_lpss_register_clock_divider(lpss, devname, &clk);
		if (ret)
			goto err_clk_register;
	}

	ret = -ENOMEM;

	/* Clock for the host controller */
	lpss->clock = clkdev_create(clk, lpss->info->clk_con_id, "%s", devname);
	if (!lpss->clock)
		goto err_clk_register;

	lpss->clk = clk;

	return 0;

err_clk_register:
	intel_lpss_unregister_clock_tree(clk);

	return ret;
}

__attribute__((used)) static void intel_lpss_unregister_clock(struct intel_lpss *lpss)
{
	if (IS_ERR_OR_NULL(lpss->clk))
		return;

	clkdev_drop(lpss->clock);
	intel_lpss_unregister_clock_tree(lpss->clk);
}

int intel_lpss_probe(struct device *dev,
		     const struct intel_lpss_platform_info *info)
{
	struct intel_lpss *lpss;
	int ret;

	if (!info || !info->mem || info->irq <= 0)
		return -EINVAL;

	lpss = devm_kzalloc(dev, sizeof(*lpss), GFP_KERNEL);
	if (!lpss)
		return -ENOMEM;

	lpss->priv = devm_ioremap(dev, info->mem->start + LPSS_PRIV_OFFSET,
				  LPSS_PRIV_SIZE);
	if (!lpss->priv)
		return -ENOMEM;

	lpss->info = info;
	lpss->dev = dev;
	lpss->caps = readl(lpss->priv + LPSS_PRIV_CAPS);

	dev_set_drvdata(dev, lpss);

	ret = intel_lpss_assign_devs(lpss);
	if (ret)
		return ret;

	lpss->cell->properties = info->properties;

	intel_lpss_init_dev(lpss);

	lpss->devid = ida_simple_get(&intel_lpss_devid_ida, 0, 0, GFP_KERNEL);
	if (lpss->devid < 0)
		return lpss->devid;

	ret = intel_lpss_register_clock(lpss);
	if (ret)
		goto err_clk_register;

	intel_lpss_ltr_expose(lpss);

	ret = intel_lpss_debugfs_add(lpss);
	if (ret)
		dev_warn(dev, "Failed to create debugfs entries\n");

	if (intel_lpss_has_idma(lpss)) {
		/*
		 * Ensure the DMA driver is loaded before the host
		 * controller device appears, so that the host controller
		 * driver can request its DMA channels as early as
		 * possible.
		 *
		 * If the DMA module is not there that's OK as well.
		 */
		intel_lpss_request_dma_module(LPSS_IDMA64_DRIVER_NAME);

		ret = mfd_add_devices(dev, lpss->devid, &intel_lpss_idma64_cell,
				      1, info->mem, info->irq, NULL);
		if (ret)
			dev_warn(dev, "Failed to add %s, fallback to PIO\n",
				 LPSS_IDMA64_DRIVER_NAME);
	}

	ret = mfd_add_devices(dev, lpss->devid, lpss->cell,
			      1, info->mem, info->irq, NULL);
	if (ret)
		goto err_remove_ltr;

	dev_pm_set_driver_flags(dev, DPM_FLAG_SMART_SUSPEND);

	return 0;

err_remove_ltr:
	intel_lpss_debugfs_remove(lpss);
	intel_lpss_ltr_hide(lpss);
	intel_lpss_unregister_clock(lpss);

err_clk_register:
	ida_simple_remove(&intel_lpss_devid_ida, lpss->devid);

	return ret;
}

void intel_lpss_remove(struct device *dev)
{
	struct intel_lpss *lpss = dev_get_drvdata(dev);

	mfd_remove_devices(dev);
	intel_lpss_debugfs_remove(lpss);
	intel_lpss_ltr_hide(lpss);
	intel_lpss_unregister_clock(lpss);
	ida_simple_remove(&intel_lpss_devid_ida, lpss->devid);
}

__attribute__((used)) static int resume_lpss_device(struct device *dev, void *data)
{
	if (!dev_pm_test_driver_flags(dev, DPM_FLAG_SMART_SUSPEND))
		pm_runtime_resume(dev);

	return 0;
}

int intel_lpss_prepare(struct device *dev)
{
	/*
	 * Resume both child devices before entering system sleep. This
	 * ensures that they are in proper state before they get suspended.
	 */
	device_for_each_child_reverse(dev, NULL, resume_lpss_device);
	return 0;
}

int intel_lpss_suspend(struct device *dev)
{
	struct intel_lpss *lpss = dev_get_drvdata(dev);
	unsigned int i;

	/* Save device context */
	for (i = 0; i < LPSS_PRIV_REG_COUNT; i++)
		lpss->priv_ctx[i] = readl(lpss->priv + i * 4);

	/*
	 * If the device type is not UART, then put the controller into
	 * reset. UART cannot be put into reset since S3/S0ix fail when
	 * no_console_suspend flag is enabled.
	 */
	if (lpss->type != LPSS_DEV_UART)
		writel(0, lpss->priv + LPSS_PRIV_RESETS);

	return 0;
}

int intel_lpss_resume(struct device *dev)
{
	struct intel_lpss *lpss = dev_get_drvdata(dev);
	unsigned int i;

	intel_lpss_deassert_reset(lpss);

	/* Restore device context */
	for (i = 0; i < LPSS_PRIV_REG_COUNT; i++)
		writel(lpss->priv_ctx[i], lpss->priv + i * 4);

	return 0;
}

