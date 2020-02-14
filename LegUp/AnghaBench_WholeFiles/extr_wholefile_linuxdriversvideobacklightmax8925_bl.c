#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_9__   TYPE_5__ ;
typedef  struct TYPE_8__   TYPE_2__ ;
typedef  struct TYPE_7__   TYPE_1__ ;

/* Type definitions */
typedef  scalar_t__ u32 ;
struct resource {int /*<<< orphan*/  start; } ;
struct TYPE_8__ {struct max8925_backlight_pdata* platform_data; TYPE_5__* parent; } ;
struct platform_device {TYPE_2__ dev; } ;
struct max8925_chip {int /*<<< orphan*/  i2c; int /*<<< orphan*/  dev; } ;
struct max8925_backlight_pdata {scalar_t__ dual_string; scalar_t__ lxw_freq; scalar_t__ lxw_scl; } ;
struct max8925_backlight_data {unsigned char current_brightness; int /*<<< orphan*/  reg_mode_cntl; struct max8925_chip* chip; int /*<<< orphan*/  reg_cntl; } ;
struct device_node {int dummy; } ;
struct backlight_properties {int max_brightness; int /*<<< orphan*/  type; } ;
struct TYPE_7__ {int brightness; scalar_t__ power; scalar_t__ fb_blank; int state; } ;
struct backlight_device {TYPE_1__ props; } ;
struct TYPE_9__ {struct device_node* of_node; } ;

/* Variables and functions */
 int /*<<< orphan*/  BACKLIGHT_RAW ; 
 int BL_CORE_SUSPENDED ; 
 int /*<<< orphan*/  CONFIG_OF ; 
 int EINVAL ; 
 int ENOMEM ; 
 int ENXIO ; 
 scalar_t__ FB_BLANK_UNBLANK ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int /*<<< orphan*/  IORESOURCE_REG ; 
 int /*<<< orphan*/  IS_ENABLED (int /*<<< orphan*/ ) ; 
 scalar_t__ IS_ERR (struct backlight_device*) ; 
 int LWX_FREQ (scalar_t__) ; 
 int MAX_BRIGHTNESS ; 
 int PTR_ERR (struct backlight_device*) ; 
 int /*<<< orphan*/  backlight_update_status (struct backlight_device*) ; 
 struct max8925_backlight_data* bl_get_data (struct backlight_device*) ; 
 int /*<<< orphan*/  dev_dbg (int /*<<< orphan*/ ,char*,unsigned char,...) ; 
 int /*<<< orphan*/  dev_err (TYPE_2__*,char*) ; 
 struct max8925_chip* dev_get_drvdata (TYPE_5__*) ; 
 struct backlight_device* devm_backlight_device_register (TYPE_2__*,char*,TYPE_2__*,struct max8925_backlight_data*,int /*<<< orphan*/ *,struct backlight_properties*) ; 
 void* devm_kzalloc (TYPE_2__*,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  max8925_backlight_ops ; 
 int max8925_reg_read (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int max8925_reg_write (int /*<<< orphan*/ ,int /*<<< orphan*/ ,unsigned char) ; 
 int max8925_set_bits (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int,unsigned char) ; 
 int /*<<< orphan*/  memset (struct backlight_properties*,int /*<<< orphan*/ ,int) ; 
 struct device_node* of_get_child_by_name (struct device_node*,char*) ; 
 int /*<<< orphan*/  of_node_put (struct device_node*) ; 
 int /*<<< orphan*/  of_property_read_u32 (struct device_node*,char*,scalar_t__*) ; 
 struct resource* platform_get_resource (struct platform_device*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  platform_set_drvdata (struct platform_device*,struct backlight_device*) ; 

__attribute__((used)) static int max8925_backlight_set(struct backlight_device *bl, int brightness)
{
	struct max8925_backlight_data *data = bl_get_data(bl);
	struct max8925_chip *chip = data->chip;
	unsigned char value;
	int ret;

	if (brightness > MAX_BRIGHTNESS)
		value = MAX_BRIGHTNESS;
	else
		value = brightness;

	ret = max8925_reg_write(chip->i2c, data->reg_cntl, value);
	if (ret < 0)
		goto out;

	if (!data->current_brightness && brightness)
		/* enable WLED output */
		ret = max8925_set_bits(chip->i2c, data->reg_mode_cntl, 1, 1);
	else if (!brightness)
		/* disable WLED output */
		ret = max8925_set_bits(chip->i2c, data->reg_mode_cntl, 1, 0);
	if (ret < 0)
		goto out;
	dev_dbg(chip->dev, "set brightness %d\n", value);
	data->current_brightness = value;
	return 0;
out:
	dev_dbg(chip->dev, "set brightness %d failure with return value:%d\n",
		value, ret);
	return ret;
}

__attribute__((used)) static int max8925_backlight_update_status(struct backlight_device *bl)
{
	int brightness = bl->props.brightness;

	if (bl->props.power != FB_BLANK_UNBLANK)
		brightness = 0;

	if (bl->props.fb_blank != FB_BLANK_UNBLANK)
		brightness = 0;

	if (bl->props.state & BL_CORE_SUSPENDED)
		brightness = 0;

	return max8925_backlight_set(bl, brightness);
}

__attribute__((used)) static int max8925_backlight_get_brightness(struct backlight_device *bl)
{
	struct max8925_backlight_data *data = bl_get_data(bl);
	struct max8925_chip *chip = data->chip;
	int ret;

	ret = max8925_reg_read(chip->i2c, data->reg_cntl);
	if (ret < 0)
		return -EINVAL;
	data->current_brightness = ret;
	dev_dbg(chip->dev, "get brightness %d\n", data->current_brightness);
	return ret;
}

__attribute__((used)) static void max8925_backlight_dt_init(struct platform_device *pdev)
{
	struct device_node *nproot = pdev->dev.parent->of_node, *np;
	struct max8925_backlight_pdata *pdata;
	u32 val;

	if (!nproot || !IS_ENABLED(CONFIG_OF))
		return;

	pdata = devm_kzalloc(&pdev->dev,
			     sizeof(struct max8925_backlight_pdata),
			     GFP_KERNEL);
	if (!pdata)
		return;

	np = of_get_child_by_name(nproot, "backlight");
	if (!np) {
		dev_err(&pdev->dev, "failed to find backlight node\n");
		return;
	}

	if (!of_property_read_u32(np, "maxim,max8925-dual-string", &val))
		pdata->dual_string = val;

	of_node_put(np);

	pdev->dev.platform_data = pdata;
}

__attribute__((used)) static int max8925_backlight_probe(struct platform_device *pdev)
{
	struct max8925_chip *chip = dev_get_drvdata(pdev->dev.parent);
	struct max8925_backlight_pdata *pdata;
	struct max8925_backlight_data *data;
	struct backlight_device *bl;
	struct backlight_properties props;
	struct resource *res;
	unsigned char value;
	int ret = 0;

	data = devm_kzalloc(&pdev->dev, sizeof(struct max8925_backlight_data),
			    GFP_KERNEL);
	if (data == NULL)
		return -ENOMEM;

	res = platform_get_resource(pdev, IORESOURCE_REG, 0);
	if (!res) {
		dev_err(&pdev->dev, "No REG resource for mode control!\n");
		return -ENXIO;
	}
	data->reg_mode_cntl = res->start;
	res = platform_get_resource(pdev, IORESOURCE_REG, 1);
	if (!res) {
		dev_err(&pdev->dev, "No REG resource for control!\n");
		return -ENXIO;
	}
	data->reg_cntl = res->start;

	data->chip = chip;
	data->current_brightness = 0;

	memset(&props, 0, sizeof(struct backlight_properties));
	props.type = BACKLIGHT_RAW;
	props.max_brightness = MAX_BRIGHTNESS;
	bl = devm_backlight_device_register(&pdev->dev, "max8925-backlight",
					&pdev->dev, data,
					&max8925_backlight_ops, &props);
	if (IS_ERR(bl)) {
		dev_err(&pdev->dev, "failed to register backlight\n");
		return PTR_ERR(bl);
	}
	bl->props.brightness = MAX_BRIGHTNESS;

	platform_set_drvdata(pdev, bl);

	value = 0;
	if (!pdev->dev.platform_data)
		max8925_backlight_dt_init(pdev);

	pdata = pdev->dev.platform_data;
	if (pdata) {
		if (pdata->lxw_scl)
			value |= (1 << 7);
		if (pdata->lxw_freq)
			value |= (LWX_FREQ(pdata->lxw_freq) << 4);
		if (pdata->dual_string)
			value |= (1 << 1);
	}
	ret = max8925_set_bits(chip->i2c, data->reg_mode_cntl, 0xfe, value);
	if (ret < 0)
		return ret;
	backlight_update_status(bl);
	return 0;
}

