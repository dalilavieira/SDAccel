#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_10__   TYPE_4__ ;
typedef  struct TYPE_9__   TYPE_1__ ;

/* Type definitions */
typedef  size_t u16 ;
struct regulator_init_data {int dummy; } ;
struct regulator_dev {int dummy; } ;
struct regulator_config {struct device_node* of_node; struct dbx500_regulator_info* driver_data; struct regulator_init_data* init_data; TYPE_1__* dev; } ;
struct TYPE_9__ {struct device_node* of_node; } ;
struct platform_device {TYPE_1__ dev; } ;
struct device_node {int dummy; } ;
struct TYPE_10__ {int name; } ;
struct dbx500_regulator_info {int is_enabled; size_t epod_id; int is_ramret; struct device_node* of_node; struct regulator_init_data* init_data; TYPE_4__ desc; struct regulator_dev* rdev; TYPE_1__* dev; int /*<<< orphan*/  exclude_from_power_state; } ;

/* Variables and functions */
 int ARRAY_SIZE (struct dbx500_regulator_info*) ; 
 int EINVAL ; 
 int /*<<< orphan*/  EPOD_STATE_OFF ; 
 int /*<<< orphan*/  EPOD_STATE_ON ; 
 int /*<<< orphan*/  EPOD_STATE_RAMRET ; 
 scalar_t__ IS_ERR (struct regulator_dev*) ; 
 int PTR_ERR (struct regulator_dev*) ; 
 struct dbx500_regulator_info* db8500_regulator_matches ; 
 struct dbx500_regulator_info* dbx500_regulator_info ; 
 int /*<<< orphan*/  dev_dbg (TYPE_1__*,char*,int) ; 
 int /*<<< orphan*/  dev_err (TYPE_1__*,char*,int,...) ; 
 struct regulator_init_data* dev_get_platdata (TYPE_1__*) ; 
 int /*<<< orphan*/  dev_vdbg (TYPE_1__*,char*,int,...) ; 
 struct regulator_dev* devm_regulator_register (TYPE_1__*,TYPE_4__*,struct regulator_config*) ; 
 int* epod_on ; 
 int* epod_ramret ; 
 int of_regulator_match (TYPE_1__*,struct device_node*,struct dbx500_regulator_info*,int) ; 
 int power_state_active_disable () ; 
 int /*<<< orphan*/  power_state_active_enable () ; 
 int prcmu_set_epod (size_t,int /*<<< orphan*/ ) ; 
 TYPE_1__* rdev_get_dev (struct regulator_dev*) ; 
 struct dbx500_regulator_info* rdev_get_drvdata (struct regulator_dev*) ; 

__attribute__((used)) static inline int ux500_regulator_debug_init(struct platform_device *pdev,
			     struct dbx500_regulator_info *regulator_info,
			     int num_regulators)
{
	return 0;
}

__attribute__((used)) static inline int ux500_regulator_debug_exit(void)
{
	return 0;
}

__attribute__((used)) static int db8500_regulator_enable(struct regulator_dev *rdev)
{
	struct dbx500_regulator_info *info = rdev_get_drvdata(rdev);

	if (info == NULL)
		return -EINVAL;

	dev_vdbg(rdev_get_dev(rdev), "regulator-%s-enable\n",
		info->desc.name);

	if (!info->is_enabled) {
		info->is_enabled = true;
		if (!info->exclude_from_power_state)
			power_state_active_enable();
	}

	return 0;
}

__attribute__((used)) static int db8500_regulator_disable(struct regulator_dev *rdev)
{
	struct dbx500_regulator_info *info = rdev_get_drvdata(rdev);
	int ret = 0;

	if (info == NULL)
		return -EINVAL;

	dev_vdbg(rdev_get_dev(rdev), "regulator-%s-disable\n",
		info->desc.name);

	if (info->is_enabled) {
		info->is_enabled = false;
		if (!info->exclude_from_power_state)
			ret = power_state_active_disable();
	}

	return ret;
}

__attribute__((used)) static int db8500_regulator_is_enabled(struct regulator_dev *rdev)
{
	struct dbx500_regulator_info *info = rdev_get_drvdata(rdev);

	if (info == NULL)
		return -EINVAL;

	dev_vdbg(rdev_get_dev(rdev), "regulator-%s-is_enabled (is_enabled):"
		" %i\n", info->desc.name, info->is_enabled);

	return info->is_enabled;
}

__attribute__((used)) static int enable_epod(u16 epod_id, bool ramret)
{
	int ret;

	if (ramret) {
		if (!epod_on[epod_id]) {
			ret = prcmu_set_epod(epod_id, EPOD_STATE_RAMRET);
			if (ret < 0)
				return ret;
		}
		epod_ramret[epod_id] = true;
	} else {
		ret = prcmu_set_epod(epod_id, EPOD_STATE_ON);
		if (ret < 0)
			return ret;
		epod_on[epod_id] = true;
	}

	return 0;
}

__attribute__((used)) static int disable_epod(u16 epod_id, bool ramret)
{
	int ret;

	if (ramret) {
		if (!epod_on[epod_id]) {
			ret = prcmu_set_epod(epod_id, EPOD_STATE_OFF);
			if (ret < 0)
				return ret;
		}
		epod_ramret[epod_id] = false;
	} else {
		if (epod_ramret[epod_id]) {
			ret = prcmu_set_epod(epod_id, EPOD_STATE_RAMRET);
			if (ret < 0)
				return ret;
		} else {
			ret = prcmu_set_epod(epod_id, EPOD_STATE_OFF);
			if (ret < 0)
				return ret;
		}
		epod_on[epod_id] = false;
	}

	return 0;
}

__attribute__((used)) static int db8500_regulator_switch_enable(struct regulator_dev *rdev)
{
	struct dbx500_regulator_info *info = rdev_get_drvdata(rdev);
	int ret;

	if (info == NULL)
		return -EINVAL;

	dev_vdbg(rdev_get_dev(rdev), "regulator-switch-%s-enable\n",
		info->desc.name);

	ret = enable_epod(info->epod_id, info->is_ramret);
	if (ret < 0) {
		dev_err(rdev_get_dev(rdev),
			"regulator-switch-%s-enable: prcmu call failed\n",
			info->desc.name);
		goto out;
	}

	info->is_enabled = true;
out:
	return ret;
}

__attribute__((used)) static int db8500_regulator_switch_disable(struct regulator_dev *rdev)
{
	struct dbx500_regulator_info *info = rdev_get_drvdata(rdev);
	int ret;

	if (info == NULL)
		return -EINVAL;

	dev_vdbg(rdev_get_dev(rdev), "regulator-switch-%s-disable\n",
		info->desc.name);

	ret = disable_epod(info->epod_id, info->is_ramret);
	if (ret < 0) {
		dev_err(rdev_get_dev(rdev),
			"regulator_switch-%s-disable: prcmu call failed\n",
			info->desc.name);
		goto out;
	}

	info->is_enabled = 0;
out:
	return ret;
}

__attribute__((used)) static int db8500_regulator_switch_is_enabled(struct regulator_dev *rdev)
{
	struct dbx500_regulator_info *info = rdev_get_drvdata(rdev);

	if (info == NULL)
		return -EINVAL;

	dev_vdbg(rdev_get_dev(rdev),
		"regulator-switch-%s-is_enabled (is_enabled): %i\n",
		info->desc.name, info->is_enabled);

	return info->is_enabled;
}

__attribute__((used)) static int db8500_regulator_register(struct platform_device *pdev,
					struct regulator_init_data *init_data,
					int id,
					struct device_node *np)
{
	struct dbx500_regulator_info *info;
	struct regulator_config config = { };
	int err;

	/* assign per-regulator data */
	info = &dbx500_regulator_info[id];
	info->dev = &pdev->dev;

	config.dev = &pdev->dev;
	config.init_data = init_data;
	config.driver_data = info;
	config.of_node = np;

	/* register with the regulator framework */
	info->rdev = devm_regulator_register(&pdev->dev, &info->desc, &config);
	if (IS_ERR(info->rdev)) {
		err = PTR_ERR(info->rdev);
		dev_err(&pdev->dev, "failed to register %s: err %i\n",
			info->desc.name, err);
		return err;
	}

	dev_dbg(rdev_get_dev(info->rdev),
		"regulator-%s-probed\n", info->desc.name);

	return 0;
}

__attribute__((used)) static int
db8500_regulator_of_probe(struct platform_device *pdev,
			struct device_node *np)
{
	int i, err;

	for (i = 0; i < ARRAY_SIZE(dbx500_regulator_info); i++) {
		err = db8500_regulator_register(
			pdev, db8500_regulator_matches[i].init_data,
			i, db8500_regulator_matches[i].of_node);
		if (err)
			return err;
	}

	return 0;
}

__attribute__((used)) static int db8500_regulator_probe(struct platform_device *pdev)
{
	struct regulator_init_data *db8500_init_data =
					dev_get_platdata(&pdev->dev);
	struct device_node *np = pdev->dev.of_node;
	int i, err;

	/* register all regulators */
	if (np) {
		err = of_regulator_match(&pdev->dev, np,
					db8500_regulator_matches,
					ARRAY_SIZE(db8500_regulator_matches));
		if (err < 0) {
			dev_err(&pdev->dev,
				"Error parsing regulator init data: %d\n", err);
			return err;
		}

		err = db8500_regulator_of_probe(pdev, np);
		if (err)
			return err;
	} else {
		for (i = 0; i < ARRAY_SIZE(dbx500_regulator_info); i++) {
			err = db8500_regulator_register(pdev,
							&db8500_init_data[i],
							i, NULL);
			if (err)
				return err;
		}
	}

	err = ux500_regulator_debug_init(pdev,
					 dbx500_regulator_info,
					 ARRAY_SIZE(dbx500_regulator_info));
	return 0;
}

__attribute__((used)) static int db8500_regulator_remove(struct platform_device *pdev)
{
	ux500_regulator_debug_exit();

	return 0;
}

