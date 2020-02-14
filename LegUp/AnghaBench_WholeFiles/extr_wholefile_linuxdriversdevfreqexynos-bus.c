#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  u32 ;
struct device {struct device_node* of_node; } ;
struct platform_device {struct device dev; } ;
struct exynos_bus {int edev_count; unsigned long curr_freq; unsigned long voltage_tolerance; int ratio; struct devfreq* clk; struct devfreq* devfreq; struct device* dev; int /*<<< orphan*/  lock; struct devfreq* regulator; struct devfreq** edev; } ;
struct device_node {int dummy; } ;
struct devfreq_simple_ondemand_data {int upthreshold; int downdifferential; struct devfreq* parent; } ;
struct devfreq_passive_data {int upthreshold; int downdifferential; struct devfreq* parent; } ;
struct devfreq_event_data {unsigned long load_count; unsigned long total_count; } ;
struct devfreq_dev_status {unsigned long current_frequency; int total_time; int busy_time; } ;
struct devfreq_dev_profile {int polling_ms; int (* target ) (struct device*,unsigned long*,int /*<<< orphan*/ ) ;int (* get_dev_status ) (struct device*,struct devfreq_dev_status*) ;void (* exit ) (struct device*) ;} ;
struct devfreq {TYPE_1__* profile; } ;
struct dev_pm_opp {TYPE_1__* profile; } ;
struct TYPE_2__ {int max_state; int* freq_table; } ;

/* Variables and functions */
 int DEFAULT_SATURATION_RATIO ; 
 int DEFAULT_VOLTAGE_TOLERANCE ; 
 int /*<<< orphan*/  DEVFREQ_GOV_PASSIVE ; 
 int /*<<< orphan*/  DEVFREQ_GOV_SIMPLE_ONDEMAND ; 
 int EINVAL ; 
 int ENOMEM ; 
 int EPROBE_DEFER ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 scalar_t__ IS_ERR (struct devfreq*) ; 
 int PTR_ERR (struct devfreq*) ; 
 int /*<<< orphan*/  clk_disable_unprepare (struct devfreq*) ; 
 unsigned long clk_get_rate (struct devfreq*) ; 
 int clk_prepare_enable (struct devfreq*) ; 
 int clk_set_rate (struct devfreq*,unsigned long) ; 
 int /*<<< orphan*/  dev_dbg (struct device*,char*,unsigned long,unsigned long,...) ; 
 int /*<<< orphan*/  dev_err (struct device*,char*) ; 
 struct exynos_bus* dev_get_drvdata (struct device*) ; 
 int /*<<< orphan*/  dev_name (struct device*) ; 
 void* dev_pm_opp_get_freq (struct devfreq*) ; 
 unsigned long dev_pm_opp_get_voltage (struct devfreq*) ; 
 int dev_pm_opp_of_add_table (struct device*) ; 
 int /*<<< orphan*/  dev_pm_opp_of_remove_table (struct device*) ; 
 int /*<<< orphan*/  dev_pm_opp_put (struct devfreq*) ; 
 int /*<<< orphan*/  dev_warn (struct device*,char*) ; 
 struct devfreq* devfreq_event_get_edev_by_phandle (struct device*,int) ; 
 int devfreq_event_get_edev_count (struct device*) ; 
 int devfreq_event_get_event (struct devfreq*,struct devfreq_event_data*) ; 
 struct devfreq* devfreq_get_devfreq_by_phandle (struct device*,int /*<<< orphan*/ ) ; 
 struct devfreq* devfreq_recommended_opp (struct device*,unsigned long*,int /*<<< orphan*/ ) ; 
 struct devfreq* devm_clk_get (struct device*,char*) ; 
 void* devm_devfreq_add_device (struct device*,struct devfreq_dev_profile*,int /*<<< orphan*/ ,struct devfreq_simple_ondemand_data*) ; 
 int devm_devfreq_register_opp_notifier (struct device*,struct devfreq*) ; 
 void* devm_kzalloc (struct device*,int,int /*<<< orphan*/ ) ; 
 struct devfreq* devm_regulator_get (struct device*,char*) ; 
 int exynos_bus_disable_edev (struct exynos_bus*) ; 
 int exynos_bus_enable_edev (struct exynos_bus*) ; 
 int exynos_bus_set_event (struct exynos_bus*) ; 
 int /*<<< orphan*/  mutex_init (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  of_node_put (struct device_node*) ; 
 struct device_node* of_parse_phandle (struct device_node*,char*,int /*<<< orphan*/ ) ; 
 scalar_t__ of_property_read_u32 (struct device_node*,char*,int*) ; 
 int /*<<< orphan*/  platform_set_drvdata (struct platform_device*,struct exynos_bus*) ; 
 int /*<<< orphan*/  pr_info (char*,int /*<<< orphan*/ ,unsigned long,unsigned long) ; 
 int /*<<< orphan*/  regulator_disable (struct devfreq*) ; 
 int regulator_enable (struct devfreq*) ; 
 int regulator_set_voltage_tol (struct devfreq*,unsigned long,unsigned long) ; 

__attribute__((used)) static int exynos_bus_get_event(struct exynos_bus *bus,
				struct devfreq_event_data *edata)
{
	struct devfreq_event_data event_data;
	unsigned long load_count = 0, total_count = 0;
	int i, ret = 0;

	for (i = 0; i < bus->edev_count; i++) {
		if (!bus->edev[i])
			continue;

		ret = devfreq_event_get_event(bus->edev[i], &event_data);
		if (ret < 0)
			return ret;

		if (i == 0 || event_data.load_count > load_count) {
			load_count = event_data.load_count;
			total_count = event_data.total_count;
		}
	}

	edata->load_count = load_count;
	edata->total_count = total_count;

	return ret;
}

__attribute__((used)) static int exynos_bus_target(struct device *dev, unsigned long *freq, u32 flags)
{
	struct exynos_bus *bus = dev_get_drvdata(dev);
	struct dev_pm_opp *new_opp;
	unsigned long old_freq, new_freq, new_volt, tol;
	int ret = 0;

	/* Get new opp-bus instance according to new bus clock */
	new_opp = devfreq_recommended_opp(dev, freq, flags);
	if (IS_ERR(new_opp)) {
		dev_err(dev, "failed to get recommended opp instance\n");
		return PTR_ERR(new_opp);
	}

	new_freq = dev_pm_opp_get_freq(new_opp);
	new_volt = dev_pm_opp_get_voltage(new_opp);
	dev_pm_opp_put(new_opp);

	old_freq = bus->curr_freq;

	if (old_freq == new_freq)
		return 0;
	tol = new_volt * bus->voltage_tolerance / 100;

	/* Change voltage and frequency according to new OPP level */
	mutex_lock(&bus->lock);

	if (old_freq < new_freq) {
		ret = regulator_set_voltage_tol(bus->regulator, new_volt, tol);
		if (ret < 0) {
			dev_err(bus->dev, "failed to set voltage\n");
			goto out;
		}
	}

	ret = clk_set_rate(bus->clk, new_freq);
	if (ret < 0) {
		dev_err(dev, "failed to change clock of bus\n");
		clk_set_rate(bus->clk, old_freq);
		goto out;
	}

	if (old_freq > new_freq) {
		ret = regulator_set_voltage_tol(bus->regulator, new_volt, tol);
		if (ret < 0) {
			dev_err(bus->dev, "failed to set voltage\n");
			goto out;
		}
	}
	bus->curr_freq = new_freq;

	dev_dbg(dev, "Set the frequency of bus (%luHz -> %luHz, %luHz)\n",
			old_freq, new_freq, clk_get_rate(bus->clk));
out:
	mutex_unlock(&bus->lock);

	return ret;
}

__attribute__((used)) static int exynos_bus_get_dev_status(struct device *dev,
				     struct devfreq_dev_status *stat)
{
	struct exynos_bus *bus = dev_get_drvdata(dev);
	struct devfreq_event_data edata;
	int ret;

	stat->current_frequency = bus->curr_freq;

	ret = exynos_bus_get_event(bus, &edata);
	if (ret < 0) {
		stat->total_time = stat->busy_time = 0;
		goto err;
	}

	stat->busy_time = (edata.load_count * 100) / bus->ratio;
	stat->total_time = edata.total_count;

	dev_dbg(dev, "Usage of devfreq-event : %lu/%lu\n", stat->busy_time,
							stat->total_time);

err:
	ret = exynos_bus_set_event(bus);
	if (ret < 0) {
		dev_err(dev, "failed to set event to devfreq-event devices\n");
		return ret;
	}

	return ret;
}

__attribute__((used)) static void exynos_bus_exit(struct device *dev)
{
	struct exynos_bus *bus = dev_get_drvdata(dev);
	int ret;

	ret = exynos_bus_disable_edev(bus);
	if (ret < 0)
		dev_warn(dev, "failed to disable the devfreq-event devices\n");

	if (bus->regulator)
		regulator_disable(bus->regulator);

	dev_pm_opp_of_remove_table(dev);
	clk_disable_unprepare(bus->clk);
}

__attribute__((used)) static int exynos_bus_passive_target(struct device *dev, unsigned long *freq,
					u32 flags)
{
	struct exynos_bus *bus = dev_get_drvdata(dev);
	struct dev_pm_opp *new_opp;
	unsigned long old_freq, new_freq;
	int ret = 0;

	/* Get new opp-bus instance according to new bus clock */
	new_opp = devfreq_recommended_opp(dev, freq, flags);
	if (IS_ERR(new_opp)) {
		dev_err(dev, "failed to get recommended opp instance\n");
		return PTR_ERR(new_opp);
	}

	new_freq = dev_pm_opp_get_freq(new_opp);
	dev_pm_opp_put(new_opp);

	old_freq = bus->curr_freq;

	if (old_freq == new_freq)
		return 0;

	/* Change the frequency according to new OPP level */
	mutex_lock(&bus->lock);

	ret = clk_set_rate(bus->clk, new_freq);
	if (ret < 0) {
		dev_err(dev, "failed to set the clock of bus\n");
		goto out;
	}

	*freq = new_freq;
	bus->curr_freq = new_freq;

	dev_dbg(dev, "Set the frequency of bus (%luHz -> %luHz, %luHz)\n",
			old_freq, new_freq, clk_get_rate(bus->clk));
out:
	mutex_unlock(&bus->lock);

	return ret;
}

__attribute__((used)) static void exynos_bus_passive_exit(struct device *dev)
{
	struct exynos_bus *bus = dev_get_drvdata(dev);

	dev_pm_opp_of_remove_table(dev);
	clk_disable_unprepare(bus->clk);
}

__attribute__((used)) static int exynos_bus_parent_parse_of(struct device_node *np,
					struct exynos_bus *bus)
{
	struct device *dev = bus->dev;
	int i, ret, count, size;

	/* Get the regulator to provide each bus with the power */
	bus->regulator = devm_regulator_get(dev, "vdd");
	if (IS_ERR(bus->regulator)) {
		dev_err(dev, "failed to get VDD regulator\n");
		return PTR_ERR(bus->regulator);
	}

	ret = regulator_enable(bus->regulator);
	if (ret < 0) {
		dev_err(dev, "failed to enable VDD regulator\n");
		return ret;
	}

	/*
	 * Get the devfreq-event devices to get the current utilization of
	 * buses. This raw data will be used in devfreq ondemand governor.
	 */
	count = devfreq_event_get_edev_count(dev);
	if (count < 0) {
		dev_err(dev, "failed to get the count of devfreq-event dev\n");
		ret = count;
		goto err_regulator;
	}
	bus->edev_count = count;

	size = sizeof(*bus->edev) * count;
	bus->edev = devm_kzalloc(dev, size, GFP_KERNEL);
	if (!bus->edev) {
		ret = -ENOMEM;
		goto err_regulator;
	}

	for (i = 0; i < count; i++) {
		bus->edev[i] = devfreq_event_get_edev_by_phandle(dev, i);
		if (IS_ERR(bus->edev[i])) {
			ret = -EPROBE_DEFER;
			goto err_regulator;
		}
	}

	/*
	 * Optionally, Get the saturation ratio according to Exynos SoC
	 * When measuring the utilization of each AXI bus with devfreq-event
	 * devices, the measured real cycle might be much lower than the
	 * total cycle of bus during sampling rate. In result, the devfreq
	 * simple-ondemand governor might not decide to change the current
	 * frequency due to too utilization (= real cycle/total cycle).
	 * So, this property is used to adjust the utilization when calculating
	 * the busy_time in exynos_bus_get_dev_status().
	 */
	if (of_property_read_u32(np, "exynos,saturation-ratio", &bus->ratio))
		bus->ratio = DEFAULT_SATURATION_RATIO;

	if (of_property_read_u32(np, "exynos,voltage-tolerance",
					&bus->voltage_tolerance))
		bus->voltage_tolerance = DEFAULT_VOLTAGE_TOLERANCE;

	return 0;

err_regulator:
	regulator_disable(bus->regulator);

	return ret;
}

__attribute__((used)) static int exynos_bus_parse_of(struct device_node *np,
			      struct exynos_bus *bus)
{
	struct device *dev = bus->dev;
	struct dev_pm_opp *opp;
	unsigned long rate;
	int ret;

	/* Get the clock to provide each bus with source clock */
	bus->clk = devm_clk_get(dev, "bus");
	if (IS_ERR(bus->clk)) {
		dev_err(dev, "failed to get bus clock\n");
		return PTR_ERR(bus->clk);
	}

	ret = clk_prepare_enable(bus->clk);
	if (ret < 0) {
		dev_err(dev, "failed to get enable clock\n");
		return ret;
	}

	/* Get the freq and voltage from OPP table to scale the bus freq */
	ret = dev_pm_opp_of_add_table(dev);
	if (ret < 0) {
		dev_err(dev, "failed to get OPP table\n");
		goto err_clk;
	}

	rate = clk_get_rate(bus->clk);

	opp = devfreq_recommended_opp(dev, &rate, 0);
	if (IS_ERR(opp)) {
		dev_err(dev, "failed to find dev_pm_opp\n");
		ret = PTR_ERR(opp);
		goto err_opp;
	}
	bus->curr_freq = dev_pm_opp_get_freq(opp);
	dev_pm_opp_put(opp);

	return 0;

err_opp:
	dev_pm_opp_of_remove_table(dev);
err_clk:
	clk_disable_unprepare(bus->clk);

	return ret;
}

__attribute__((used)) static int exynos_bus_probe(struct platform_device *pdev)
{
	struct device *dev = &pdev->dev;
	struct device_node *np = dev->of_node, *node;
	struct devfreq_dev_profile *profile;
	struct devfreq_simple_ondemand_data *ondemand_data;
	struct devfreq_passive_data *passive_data;
	struct devfreq *parent_devfreq;
	struct exynos_bus *bus;
	int ret, max_state;
	unsigned long min_freq, max_freq;

	if (!np) {
		dev_err(dev, "failed to find devicetree node\n");
		return -EINVAL;
	}

	bus = devm_kzalloc(&pdev->dev, sizeof(*bus), GFP_KERNEL);
	if (!bus)
		return -ENOMEM;
	mutex_init(&bus->lock);
	bus->dev = &pdev->dev;
	platform_set_drvdata(pdev, bus);

	/* Parse the device-tree to get the resource information */
	ret = exynos_bus_parse_of(np, bus);
	if (ret < 0)
		return ret;

	profile = devm_kzalloc(dev, sizeof(*profile), GFP_KERNEL);
	if (!profile) {
		ret = -ENOMEM;
		goto err;
	}

	node = of_parse_phandle(dev->of_node, "devfreq", 0);
	if (node) {
		of_node_put(node);
		goto passive;
	} else {
		ret = exynos_bus_parent_parse_of(np, bus);
	}

	if (ret < 0)
		goto err;

	/* Initialize the struct profile and governor data for parent device */
	profile->polling_ms = 50;
	profile->target = exynos_bus_target;
	profile->get_dev_status = exynos_bus_get_dev_status;
	profile->exit = exynos_bus_exit;

	ondemand_data = devm_kzalloc(dev, sizeof(*ondemand_data), GFP_KERNEL);
	if (!ondemand_data) {
		ret = -ENOMEM;
		goto err;
	}
	ondemand_data->upthreshold = 40;
	ondemand_data->downdifferential = 5;

	/* Add devfreq device to monitor and handle the exynos bus */
	bus->devfreq = devm_devfreq_add_device(dev, profile,
						DEVFREQ_GOV_SIMPLE_ONDEMAND,
						ondemand_data);
	if (IS_ERR(bus->devfreq)) {
		dev_err(dev, "failed to add devfreq device\n");
		ret = PTR_ERR(bus->devfreq);
		goto err;
	}

	/* Register opp_notifier to catch the change of OPP  */
	ret = devm_devfreq_register_opp_notifier(dev, bus->devfreq);
	if (ret < 0) {
		dev_err(dev, "failed to register opp notifier\n");
		goto err;
	}

	/*
	 * Enable devfreq-event to get raw data which is used to determine
	 * current bus load.
	 */
	ret = exynos_bus_enable_edev(bus);
	if (ret < 0) {
		dev_err(dev, "failed to enable devfreq-event devices\n");
		goto err;
	}

	ret = exynos_bus_set_event(bus);
	if (ret < 0) {
		dev_err(dev, "failed to set event to devfreq-event devices\n");
		goto err;
	}

	goto out;
passive:
	/* Initialize the struct profile and governor data for passive device */
	profile->target = exynos_bus_passive_target;
	profile->exit = exynos_bus_passive_exit;

	/* Get the instance of parent devfreq device */
	parent_devfreq = devfreq_get_devfreq_by_phandle(dev, 0);
	if (IS_ERR(parent_devfreq)) {
		ret = -EPROBE_DEFER;
		goto err;
	}

	passive_data = devm_kzalloc(dev, sizeof(*passive_data), GFP_KERNEL);
	if (!passive_data) {
		ret = -ENOMEM;
		goto err;
	}
	passive_data->parent = parent_devfreq;

	/* Add devfreq device for exynos bus with passive governor */
	bus->devfreq = devm_devfreq_add_device(dev, profile, DEVFREQ_GOV_PASSIVE,
						passive_data);
	if (IS_ERR(bus->devfreq)) {
		dev_err(dev,
			"failed to add devfreq dev with passive governor\n");
		ret = PTR_ERR(bus->devfreq);
		goto err;
	}

out:
	max_state = bus->devfreq->profile->max_state;
	min_freq = (bus->devfreq->profile->freq_table[0] / 1000);
	max_freq = (bus->devfreq->profile->freq_table[max_state - 1] / 1000);
	pr_info("exynos-bus: new bus device registered: %s (%6ld KHz ~ %6ld KHz)\n",
			dev_name(dev), min_freq, max_freq);

	return 0;

err:
	dev_pm_opp_of_remove_table(dev);
	clk_disable_unprepare(bus->clk);

	return ret;
}

