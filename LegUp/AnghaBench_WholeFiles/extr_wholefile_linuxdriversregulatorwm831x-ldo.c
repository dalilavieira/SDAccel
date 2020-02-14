#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_9__   TYPE_3__ ;
typedef  struct TYPE_8__   TYPE_1__ ;

/* Type definitions */
struct wm831x_pdata {int wm831x_num; int /*<<< orphan*/ * ldo; } ;
struct TYPE_9__ {int id; int n_voltages; int vsel_reg; int vsel_mask; int enable_mask; int bypass_reg; int min_uV; int uV_step; int enable_time; void* enable_reg; void* owner; int /*<<< orphan*/ * ops; void* type; int /*<<< orphan*/  supply_name; int /*<<< orphan*/  name; int /*<<< orphan*/  bypass_mask; void* n_linear_ranges; void* linear_ranges; } ;
struct wm831x_ldo {int base; void* regulator; TYPE_3__ desc; int /*<<< orphan*/  supply_name; int /*<<< orphan*/  name; struct wm831x* wm831x; } ;
struct wm831x {TYPE_1__* dev; int /*<<< orphan*/  regmap; } ;
struct resource {int start; } ;
struct regulator_dev {int dummy; } ;
struct regulator_config {int /*<<< orphan*/  regmap; struct wm831x_ldo* driver_data; int /*<<< orphan*/  init_data; int /*<<< orphan*/  dev; } ;
struct TYPE_8__ {int /*<<< orphan*/  parent; } ;
struct platform_device {int id; TYPE_1__ dev; } ;
typedef  int /*<<< orphan*/  irqreturn_t ;

/* Variables and functions */
 void* ARRAY_SIZE (void*) ; 
 int EINVAL ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int /*<<< orphan*/  IORESOURCE_REG ; 
 int IRQF_ONESHOT ; 
 int IRQF_TRIGGER_RISING ; 
 int /*<<< orphan*/  IRQ_HANDLED ; 
 scalar_t__ IS_ERR (void*) ; 
 int PTR_ERR (void*) ; 
 int /*<<< orphan*/  REGULATOR_EVENT_UNDER_VOLTAGE ; 
#define  REGULATOR_MODE_IDLE 130 
#define  REGULATOR_MODE_NORMAL 129 
#define  REGULATOR_MODE_STANDBY 128 
 int REGULATOR_STATUS_ERROR ; 
 int REGULATOR_STATUS_OFF ; 
 int REGULATOR_STATUS_ON ; 
 void* REGULATOR_VOLTAGE ; 
 void* THIS_MODULE ; 
 int WM831X_ALIVE_LDO_MAX_SELECTOR ; 
 int WM831X_ALIVE_LDO_ON_CONTROL ; 
 int WM831X_ALIVE_LDO_SLEEP_CONTROL ; 
 int WM831X_LDO11_ON_VSEL_MASK ; 
 int WM831X_LDO1_LP_MODE ; 
 int WM831X_LDO1_ON_MODE ; 
 int WM831X_LDO1_ON_VSEL_MASK ; 
 int /*<<< orphan*/  WM831X_LDO1_SWI ; 
 int WM831X_LDO7_ON_MODE ; 
 int WM831X_LDO7_ON_VSEL_MASK ; 
 int /*<<< orphan*/  WM831X_LDO7_SWI ; 
 int WM831X_LDO_CONTROL ; 
 void* WM831X_LDO_ENABLE ; 
 int WM831X_LDO_ON_CONTROL ; 
 int WM831X_LDO_SLEEP_CONTROL ; 
 int WM831X_LDO_STATUS ; 
 int WM831X_LDO_UV_STATUS ; 
 int /*<<< orphan*/  dev_dbg (TYPE_1__*,char*,int) ; 
 int /*<<< orphan*/  dev_err (TYPE_1__*,char*,...) ; 
 struct wm831x* dev_get_drvdata (int /*<<< orphan*/ ) ; 
 struct wm831x_pdata* dev_get_platdata (TYPE_1__*) ; 
 struct wm831x_ldo* devm_kzalloc (TYPE_1__*,int,int /*<<< orphan*/ ) ; 
 void* devm_regulator_register (TYPE_1__*,TYPE_3__*,struct regulator_config*) ; 
 int devm_request_threaded_irq (TYPE_1__*,int,int /*<<< orphan*/ *,int /*<<< orphan*/  (*) (int,void*),int,int /*<<< orphan*/ ,struct wm831x_ldo*) ; 
 int /*<<< orphan*/  platform_get_irq_byname (struct platform_device*,char*) ; 
 struct resource* platform_get_resource (struct platform_device*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  platform_set_drvdata (struct platform_device*,struct wm831x_ldo*) ; 
 struct wm831x_ldo* rdev_get_drvdata (struct regulator_dev*) ; 
 int rdev_get_id (struct regulator_dev*) ; 
 int regulator_map_voltage_linear (struct regulator_dev*,int,int) ; 
 int regulator_map_voltage_linear_range (struct regulator_dev*,int,int) ; 
 int regulator_mode_to_status (int) ; 
 int /*<<< orphan*/  regulator_notifier_call_chain (void*,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  snprintf (int /*<<< orphan*/ ,int,char*,int) ; 
 int /*<<< orphan*/  wm831x_aldo_ops ; 
 void* wm831x_aldo_ranges ; 
 int /*<<< orphan*/  wm831x_alive_ldo_ops ; 
 int /*<<< orphan*/  wm831x_gp_ldo_ops ; 
 void* wm831x_gp_ldo_ranges ; 
 int wm831x_irq (struct wm831x*,int /*<<< orphan*/ ) ; 
 int wm831x_reg_read (struct wm831x*,int) ; 
 int wm831x_set_bits (struct wm831x*,int,int,int) ; 

__attribute__((used)) static irqreturn_t wm831x_ldo_uv_irq(int irq, void *data)
{
	struct wm831x_ldo *ldo = data;

	regulator_notifier_call_chain(ldo->regulator,
				      REGULATOR_EVENT_UNDER_VOLTAGE,
				      NULL);

	return IRQ_HANDLED;
}

__attribute__((used)) static int wm831x_gp_ldo_set_suspend_voltage(struct regulator_dev *rdev,
					     int uV)
{
	struct wm831x_ldo *ldo = rdev_get_drvdata(rdev);
	struct wm831x *wm831x = ldo->wm831x;
	int sel, reg = ldo->base + WM831X_LDO_SLEEP_CONTROL;

	sel = regulator_map_voltage_linear_range(rdev, uV, uV);
	if (sel < 0)
		return sel;

	return wm831x_set_bits(wm831x, reg, WM831X_LDO1_ON_VSEL_MASK, sel);
}

__attribute__((used)) static unsigned int wm831x_gp_ldo_get_mode(struct regulator_dev *rdev)
{
	struct wm831x_ldo *ldo = rdev_get_drvdata(rdev);
	struct wm831x *wm831x = ldo->wm831x;
	int ctrl_reg = ldo->base + WM831X_LDO_CONTROL;
	int on_reg = ldo->base + WM831X_LDO_ON_CONTROL;
	int ret;

	ret = wm831x_reg_read(wm831x, on_reg);
	if (ret < 0)
		return ret;

	if (!(ret & WM831X_LDO1_ON_MODE))
		return REGULATOR_MODE_NORMAL;

	ret = wm831x_reg_read(wm831x, ctrl_reg);
	if (ret < 0)
		return ret;

	if (ret & WM831X_LDO1_LP_MODE)
		return REGULATOR_MODE_STANDBY;
	else
		return REGULATOR_MODE_IDLE;
}

__attribute__((used)) static int wm831x_gp_ldo_set_mode(struct regulator_dev *rdev,
				  unsigned int mode)
{
	struct wm831x_ldo *ldo = rdev_get_drvdata(rdev);
	struct wm831x *wm831x = ldo->wm831x;
	int ctrl_reg = ldo->base + WM831X_LDO_CONTROL;
	int on_reg = ldo->base + WM831X_LDO_ON_CONTROL;
	int ret;


	switch (mode) {
	case REGULATOR_MODE_NORMAL:
		ret = wm831x_set_bits(wm831x, on_reg,
				      WM831X_LDO1_ON_MODE, 0);
		if (ret < 0)
			return ret;
		break;

	case REGULATOR_MODE_IDLE:
		ret = wm831x_set_bits(wm831x, ctrl_reg,
				      WM831X_LDO1_LP_MODE, 0);
		if (ret < 0)
			return ret;

		ret = wm831x_set_bits(wm831x, on_reg,
				      WM831X_LDO1_ON_MODE,
				      WM831X_LDO1_ON_MODE);
		if (ret < 0)
			return ret;
		break;

	case REGULATOR_MODE_STANDBY:
		ret = wm831x_set_bits(wm831x, ctrl_reg,
				      WM831X_LDO1_LP_MODE,
				      WM831X_LDO1_LP_MODE);
		if (ret < 0)
			return ret;

		ret = wm831x_set_bits(wm831x, on_reg,
				      WM831X_LDO1_ON_MODE,
				      WM831X_LDO1_ON_MODE);
		if (ret < 0)
			return ret;
		break;

	default:
		return -EINVAL;
	}

	return 0;
}

__attribute__((used)) static int wm831x_gp_ldo_get_status(struct regulator_dev *rdev)
{
	struct wm831x_ldo *ldo = rdev_get_drvdata(rdev);
	struct wm831x *wm831x = ldo->wm831x;
	int mask = 1 << rdev_get_id(rdev);
	int ret;

	/* Is the regulator on? */
	ret = wm831x_reg_read(wm831x, WM831X_LDO_STATUS);
	if (ret < 0)
		return ret;
	if (!(ret & mask))
		return REGULATOR_STATUS_OFF;

	/* Is it reporting under voltage? */
	ret = wm831x_reg_read(wm831x, WM831X_LDO_UV_STATUS);
	if (ret < 0)
		return ret;
	if (ret & mask)
		return REGULATOR_STATUS_ERROR;

	ret = wm831x_gp_ldo_get_mode(rdev);
	if (ret < 0)
		return ret;
	else
		return regulator_mode_to_status(ret);
}

__attribute__((used)) static unsigned int wm831x_gp_ldo_get_optimum_mode(struct regulator_dev *rdev,
						   int input_uV,
						   int output_uV, int load_uA)
{
	if (load_uA < 20000)
		return REGULATOR_MODE_STANDBY;
	if (load_uA < 50000)
		return REGULATOR_MODE_IDLE;
	return REGULATOR_MODE_NORMAL;
}

__attribute__((used)) static int wm831x_gp_ldo_probe(struct platform_device *pdev)
{
	struct wm831x *wm831x = dev_get_drvdata(pdev->dev.parent);
	struct wm831x_pdata *pdata = dev_get_platdata(wm831x->dev);
	struct regulator_config config = { };
	int id;
	struct wm831x_ldo *ldo;
	struct resource *res;
	int ret, irq;

	if (pdata && pdata->wm831x_num)
		id = (pdata->wm831x_num * 10) + 1;
	else
		id = 0;
	id = pdev->id - id;

	dev_dbg(&pdev->dev, "Probing LDO%d\n", id + 1);

	ldo = devm_kzalloc(&pdev->dev, sizeof(struct wm831x_ldo), GFP_KERNEL);
	if (!ldo)
		return -ENOMEM;

	ldo->wm831x = wm831x;

	res = platform_get_resource(pdev, IORESOURCE_REG, 0);
	if (res == NULL) {
		dev_err(&pdev->dev, "No REG resource\n");
		ret = -EINVAL;
		goto err;
	}
	ldo->base = res->start;

	snprintf(ldo->name, sizeof(ldo->name), "LDO%d", id + 1);
	ldo->desc.name = ldo->name;

	snprintf(ldo->supply_name, sizeof(ldo->supply_name),
		 "LDO%dVDD", id + 1);
	ldo->desc.supply_name = ldo->supply_name;

	ldo->desc.id = id;
	ldo->desc.type = REGULATOR_VOLTAGE;
	ldo->desc.n_voltages = 32;
	ldo->desc.ops = &wm831x_gp_ldo_ops;
	ldo->desc.owner = THIS_MODULE;
	ldo->desc.vsel_reg = ldo->base + WM831X_LDO_ON_CONTROL;
	ldo->desc.vsel_mask = WM831X_LDO1_ON_VSEL_MASK;
	ldo->desc.enable_reg = WM831X_LDO_ENABLE;
	ldo->desc.enable_mask = 1 << id;
	ldo->desc.bypass_reg = ldo->base;
	ldo->desc.bypass_mask = WM831X_LDO1_SWI;
	ldo->desc.linear_ranges = wm831x_gp_ldo_ranges;
	ldo->desc.n_linear_ranges = ARRAY_SIZE(wm831x_gp_ldo_ranges);

	config.dev = pdev->dev.parent;
	if (pdata)
		config.init_data = pdata->ldo[id];
	config.driver_data = ldo;
	config.regmap = wm831x->regmap;

	ldo->regulator = devm_regulator_register(&pdev->dev, &ldo->desc,
						 &config);
	if (IS_ERR(ldo->regulator)) {
		ret = PTR_ERR(ldo->regulator);
		dev_err(wm831x->dev, "Failed to register LDO%d: %d\n",
			id + 1, ret);
		goto err;
	}

	irq = wm831x_irq(wm831x, platform_get_irq_byname(pdev, "UV"));
	ret = devm_request_threaded_irq(&pdev->dev, irq, NULL,
					wm831x_ldo_uv_irq,
					IRQF_TRIGGER_RISING | IRQF_ONESHOT,
					ldo->name,
					ldo);
	if (ret != 0) {
		dev_err(&pdev->dev, "Failed to request UV IRQ %d: %d\n",
			irq, ret);
		goto err;
	}

	platform_set_drvdata(pdev, ldo);

	return 0;

err:
	return ret;
}

__attribute__((used)) static int wm831x_aldo_set_suspend_voltage(struct regulator_dev *rdev,
					     int uV)
{
	struct wm831x_ldo *ldo = rdev_get_drvdata(rdev);
	struct wm831x *wm831x = ldo->wm831x;
	int sel, reg = ldo->base + WM831X_LDO_SLEEP_CONTROL;

	sel = regulator_map_voltage_linear_range(rdev, uV, uV);
	if (sel < 0)
		return sel;

	return wm831x_set_bits(wm831x, reg, WM831X_LDO7_ON_VSEL_MASK, sel);
}

__attribute__((used)) static unsigned int wm831x_aldo_get_mode(struct regulator_dev *rdev)
{
	struct wm831x_ldo *ldo = rdev_get_drvdata(rdev);
	struct wm831x *wm831x = ldo->wm831x;
	int on_reg = ldo->base + WM831X_LDO_ON_CONTROL;
	int ret;

	ret = wm831x_reg_read(wm831x, on_reg);
	if (ret < 0)
		return 0;

	if (ret & WM831X_LDO7_ON_MODE)
		return REGULATOR_MODE_IDLE;
	else
		return REGULATOR_MODE_NORMAL;
}

__attribute__((used)) static int wm831x_aldo_set_mode(struct regulator_dev *rdev,
				  unsigned int mode)
{
	struct wm831x_ldo *ldo = rdev_get_drvdata(rdev);
	struct wm831x *wm831x = ldo->wm831x;
	int on_reg = ldo->base + WM831X_LDO_ON_CONTROL;
	int ret;


	switch (mode) {
	case REGULATOR_MODE_NORMAL:
		ret = wm831x_set_bits(wm831x, on_reg, WM831X_LDO7_ON_MODE, 0);
		if (ret < 0)
			return ret;
		break;

	case REGULATOR_MODE_IDLE:
		ret = wm831x_set_bits(wm831x, on_reg, WM831X_LDO7_ON_MODE,
				      WM831X_LDO7_ON_MODE);
		if (ret < 0)
			return ret;
		break;

	default:
		return -EINVAL;
	}

	return 0;
}

__attribute__((used)) static int wm831x_aldo_get_status(struct regulator_dev *rdev)
{
	struct wm831x_ldo *ldo = rdev_get_drvdata(rdev);
	struct wm831x *wm831x = ldo->wm831x;
	int mask = 1 << rdev_get_id(rdev);
	int ret;

	/* Is the regulator on? */
	ret = wm831x_reg_read(wm831x, WM831X_LDO_STATUS);
	if (ret < 0)
		return ret;
	if (!(ret & mask))
		return REGULATOR_STATUS_OFF;

	/* Is it reporting under voltage? */
	ret = wm831x_reg_read(wm831x, WM831X_LDO_UV_STATUS);
	if (ret < 0)
		return ret;
	if (ret & mask)
		return REGULATOR_STATUS_ERROR;

	ret = wm831x_aldo_get_mode(rdev);
	if (ret < 0)
		return ret;
	else
		return regulator_mode_to_status(ret);
}

__attribute__((used)) static int wm831x_aldo_probe(struct platform_device *pdev)
{
	struct wm831x *wm831x = dev_get_drvdata(pdev->dev.parent);
	struct wm831x_pdata *pdata = dev_get_platdata(wm831x->dev);
	struct regulator_config config = { };
	int id;
	struct wm831x_ldo *ldo;
	struct resource *res;
	int ret, irq;

	if (pdata && pdata->wm831x_num)
		id = (pdata->wm831x_num * 10) + 1;
	else
		id = 0;
	id = pdev->id - id;

	dev_dbg(&pdev->dev, "Probing LDO%d\n", id + 1);

	ldo = devm_kzalloc(&pdev->dev, sizeof(struct wm831x_ldo), GFP_KERNEL);
	if (!ldo)
		return -ENOMEM;

	ldo->wm831x = wm831x;

	res = platform_get_resource(pdev, IORESOURCE_REG, 0);
	if (res == NULL) {
		dev_err(&pdev->dev, "No REG resource\n");
		ret = -EINVAL;
		goto err;
	}
	ldo->base = res->start;

	snprintf(ldo->name, sizeof(ldo->name), "LDO%d", id + 1);
	ldo->desc.name = ldo->name;

	snprintf(ldo->supply_name, sizeof(ldo->supply_name),
		 "LDO%dVDD", id + 1);
	ldo->desc.supply_name = ldo->supply_name;

	ldo->desc.id = id;
	ldo->desc.type = REGULATOR_VOLTAGE;
	ldo->desc.n_voltages = 32;
	ldo->desc.linear_ranges = wm831x_aldo_ranges;
	ldo->desc.n_linear_ranges = ARRAY_SIZE(wm831x_aldo_ranges);
	ldo->desc.ops = &wm831x_aldo_ops;
	ldo->desc.owner = THIS_MODULE;
	ldo->desc.vsel_reg = ldo->base + WM831X_LDO_ON_CONTROL;
	ldo->desc.vsel_mask = WM831X_LDO7_ON_VSEL_MASK;
	ldo->desc.enable_reg = WM831X_LDO_ENABLE;
	ldo->desc.enable_mask = 1 << id;
	ldo->desc.bypass_reg = ldo->base;
	ldo->desc.bypass_mask = WM831X_LDO7_SWI;

	config.dev = pdev->dev.parent;
	if (pdata)
		config.init_data = pdata->ldo[id];
	config.driver_data = ldo;
	config.regmap = wm831x->regmap;

	ldo->regulator = devm_regulator_register(&pdev->dev, &ldo->desc,
						 &config);
	if (IS_ERR(ldo->regulator)) {
		ret = PTR_ERR(ldo->regulator);
		dev_err(wm831x->dev, "Failed to register LDO%d: %d\n",
			id + 1, ret);
		goto err;
	}

	irq = wm831x_irq(wm831x, platform_get_irq_byname(pdev, "UV"));
	ret = devm_request_threaded_irq(&pdev->dev, irq, NULL,
					wm831x_ldo_uv_irq,
					IRQF_TRIGGER_RISING | IRQF_ONESHOT,
					ldo->name, ldo);
	if (ret != 0) {
		dev_err(&pdev->dev, "Failed to request UV IRQ %d: %d\n",
			irq, ret);
		goto err;
	}

	platform_set_drvdata(pdev, ldo);

	return 0;

err:
	return ret;
}

__attribute__((used)) static int wm831x_alive_ldo_set_suspend_voltage(struct regulator_dev *rdev,
					     int uV)
{
	struct wm831x_ldo *ldo = rdev_get_drvdata(rdev);
	struct wm831x *wm831x = ldo->wm831x;
	int sel, reg = ldo->base + WM831X_ALIVE_LDO_SLEEP_CONTROL;

	sel = regulator_map_voltage_linear(rdev, uV, uV);
	if (sel < 0)
		return sel;

	return wm831x_set_bits(wm831x, reg, WM831X_LDO11_ON_VSEL_MASK, sel);
}

__attribute__((used)) static int wm831x_alive_ldo_get_status(struct regulator_dev *rdev)
{
	struct wm831x_ldo *ldo = rdev_get_drvdata(rdev);
	struct wm831x *wm831x = ldo->wm831x;
	int mask = 1 << rdev_get_id(rdev);
	int ret;

	/* Is the regulator on? */
	ret = wm831x_reg_read(wm831x, WM831X_LDO_STATUS);
	if (ret < 0)
		return ret;
	if (ret & mask)
		return REGULATOR_STATUS_ON;
	else
		return REGULATOR_STATUS_OFF;
}

__attribute__((used)) static int wm831x_alive_ldo_probe(struct platform_device *pdev)
{
	struct wm831x *wm831x = dev_get_drvdata(pdev->dev.parent);
	struct wm831x_pdata *pdata = dev_get_platdata(wm831x->dev);
	struct regulator_config config = { };
	int id;
	struct wm831x_ldo *ldo;
	struct resource *res;
	int ret;

	if (pdata && pdata->wm831x_num)
		id = (pdata->wm831x_num * 10) + 1;
	else
		id = 0;
	id = pdev->id - id;


	dev_dbg(&pdev->dev, "Probing LDO%d\n", id + 1);

	ldo = devm_kzalloc(&pdev->dev, sizeof(struct wm831x_ldo), GFP_KERNEL);
	if (!ldo)
		return -ENOMEM;

	ldo->wm831x = wm831x;

	res = platform_get_resource(pdev, IORESOURCE_REG, 0);
	if (res == NULL) {
		dev_err(&pdev->dev, "No REG resource\n");
		ret = -EINVAL;
		goto err;
	}
	ldo->base = res->start;

	snprintf(ldo->name, sizeof(ldo->name), "LDO%d", id + 1);
	ldo->desc.name = ldo->name;

	snprintf(ldo->supply_name, sizeof(ldo->supply_name),
		 "LDO%dVDD", id + 1);
	ldo->desc.supply_name = ldo->supply_name;

	ldo->desc.id = id;
	ldo->desc.type = REGULATOR_VOLTAGE;
	ldo->desc.n_voltages = WM831X_ALIVE_LDO_MAX_SELECTOR + 1;
	ldo->desc.ops = &wm831x_alive_ldo_ops;
	ldo->desc.owner = THIS_MODULE;
	ldo->desc.vsel_reg = ldo->base + WM831X_ALIVE_LDO_ON_CONTROL;
	ldo->desc.vsel_mask = WM831X_LDO11_ON_VSEL_MASK;
	ldo->desc.enable_reg = WM831X_LDO_ENABLE;
	ldo->desc.enable_mask = 1 << id;
	ldo->desc.min_uV = 800000;
	ldo->desc.uV_step = 50000;
	ldo->desc.enable_time = 1000;

	config.dev = pdev->dev.parent;
	if (pdata)
		config.init_data = pdata->ldo[id];
	config.driver_data = ldo;
	config.regmap = wm831x->regmap;

	ldo->regulator = devm_regulator_register(&pdev->dev, &ldo->desc,
						 &config);
	if (IS_ERR(ldo->regulator)) {
		ret = PTR_ERR(ldo->regulator);
		dev_err(wm831x->dev, "Failed to register LDO%d: %d\n",
			id + 1, ret);
		goto err;
	}

	platform_set_drvdata(pdev, ldo);

	return 0;

err:
	return ret;
}

