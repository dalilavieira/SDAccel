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
typedef  int uint8_t ;
struct rc5t583_platform_data {int /*<<< orphan*/  irq_base; scalar_t__ enable_shutdown; } ;
struct rc5t583 {struct device* dev; int /*<<< orphan*/  regmap; } ;
struct i2c_device_id {int dummy; } ;
struct device {int dummy; } ;
struct i2c_client {struct device dev; int /*<<< orphan*/  irq; } ;
struct TYPE_2__ {unsigned int ds_pos_bit; int reg_add; } ;

/* Variables and functions */
 int /*<<< orphan*/  ARRAY_SIZE (int /*<<< orphan*/ ) ; 
 int BIT (int) ; 
 int EINVAL ; 
 int ENOMEM ; 
 int EXT_PWR_REQ ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 scalar_t__ IS_ERR (int /*<<< orphan*/ ) ; 
 int PTR_ERR (int /*<<< orphan*/ ) ; 
 int RC5T583_DS_DC0 ; 
 int RC5T583_DS_LDO4 ; 
 int RC5T583_EXT_PWRREQ1_CONTROL ; 
 int RC5T583_EXT_PWRREQ2_CONTROL ; 
#define  RC5T583_GPIO_EN_INT 138 
#define  RC5T583_GPIO_GPEDGE1 137 
#define  RC5T583_GPIO_GPEDGE2 136 
 unsigned int RC5T583_GPIO_GPOFUNC ; 
 unsigned int RC5T583_GPIO_IOSEL ; 
#define  RC5T583_GPIO_MON_IOIN 135 
#define  RC5T583_INT_EN_ADC1 134 
#define  RC5T583_INT_EN_ADC2 133 
#define  RC5T583_INT_EN_ADC3 132 
#define  RC5T583_INT_EN_DCDC 131 
#define  RC5T583_INT_EN_RTC 130 
#define  RC5T583_INT_EN_SYS1 129 
#define  RC5T583_INT_EN_SYS2 128 
 unsigned int RC5T583_REG_DC0CTL ; 
 unsigned int RC5T583_REG_LDO9DAC_DS ; 
 unsigned int RC5T583_REG_LDOEN1 ; 
 unsigned int RC5T583_REG_SR3CTL ; 
 unsigned int RC5T583_SLPSEQ1 ; 
 int RC5T583_SLPSEQ11 ; 
 int RICOH_ONOFFSEL_REG ; 
 int RICOH_SWCTL_REG ; 
 TYPE_1__* deepsleep_data ; 
 int /*<<< orphan*/  dev_err (struct device*,char*,...) ; 
 struct rc5t583_platform_data* dev_get_platdata (struct device*) ; 
 int /*<<< orphan*/  dev_warn (struct device*,char*,int,...) ; 
 struct rc5t583* devm_kzalloc (struct device*,int,int /*<<< orphan*/ ) ; 
 int devm_mfd_add_devices (struct device*,int,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  devm_regmap_init_i2c (struct i2c_client*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  i2c_set_clientdata (struct i2c_client*,struct rc5t583*) ; 
 int rc5t583_irq_init (struct rc5t583*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int rc5t583_read (struct device*,int,int*) ; 
 int /*<<< orphan*/  rc5t583_regmap_config ; 
 int rc5t583_set_bits (struct device*,int,int) ; 
 int /*<<< orphan*/  rc5t583_subdevs ; 
 int rc5t583_write (struct device*,int,int) ; 

__attribute__((used)) static int __rc5t583_set_ext_pwrreq1_control(struct device *dev,
	int id, int ext_pwr, int slots)
{
	int ret;
	uint8_t sleepseq_val = 0;
	unsigned int en_bit;
	unsigned int slot_bit;

	if (id == RC5T583_DS_DC0) {
		dev_err(dev, "PWRREQ1 is invalid control for rail %d\n", id);
		return -EINVAL;
	}

	en_bit = deepsleep_data[id].ds_pos_bit;
	slot_bit = en_bit + 1;
	ret = rc5t583_read(dev, deepsleep_data[id].reg_add, &sleepseq_val);
	if (ret < 0) {
		dev_err(dev, "Error in reading reg 0x%x\n",
				deepsleep_data[id].reg_add);
		return ret;
	}

	sleepseq_val &= ~(0xF << en_bit);
	sleepseq_val |= BIT(en_bit);
	sleepseq_val |= ((slots & 0x7) << slot_bit);
	ret = rc5t583_set_bits(dev, RICOH_ONOFFSEL_REG, BIT(1));
	if (ret < 0) {
		dev_err(dev, "Error in updating the 0x%02x register\n",
				RICOH_ONOFFSEL_REG);
		return ret;
	}

	ret = rc5t583_write(dev, deepsleep_data[id].reg_add, sleepseq_val);
	if (ret < 0) {
		dev_err(dev, "Error in writing reg 0x%x\n",
				deepsleep_data[id].reg_add);
		return ret;
	}

	if (id == RC5T583_DS_LDO4) {
		ret = rc5t583_write(dev, RICOH_SWCTL_REG, 0x1);
		if (ret < 0)
			dev_err(dev, "Error in writing reg 0x%x\n",
				RICOH_SWCTL_REG);
	}
	return ret;
}

__attribute__((used)) static int __rc5t583_set_ext_pwrreq2_control(struct device *dev,
	int id, int ext_pwr)
{
	int ret;

	if (id != RC5T583_DS_DC0) {
		dev_err(dev, "PWRREQ2 is invalid control for rail %d\n", id);
		return -EINVAL;
	}

	ret = rc5t583_set_bits(dev, RICOH_ONOFFSEL_REG, BIT(2));
	if (ret < 0)
		dev_err(dev, "Error in updating the ONOFFSEL 0x10 register\n");
	return ret;
}

int rc5t583_ext_power_req_config(struct device *dev, int ds_id,
	int ext_pwr_req, int deepsleep_slot_nr)
{
	if ((ext_pwr_req & EXT_PWR_REQ) == EXT_PWR_REQ)
		return -EINVAL;

	if (ext_pwr_req & RC5T583_EXT_PWRREQ1_CONTROL)
		return __rc5t583_set_ext_pwrreq1_control(dev, ds_id,
				ext_pwr_req, deepsleep_slot_nr);

	if (ext_pwr_req & RC5T583_EXT_PWRREQ2_CONTROL)
		return __rc5t583_set_ext_pwrreq2_control(dev,
			ds_id, ext_pwr_req);
	return 0;
}

__attribute__((used)) static int rc5t583_clear_ext_power_req(struct rc5t583 *rc5t583,
	struct rc5t583_platform_data *pdata)
{
	int ret;
	int i;
	uint8_t on_off_val = 0;

	/*  Clear ONOFFSEL register */
	if (pdata->enable_shutdown)
		on_off_val = 0x1;

	ret = rc5t583_write(rc5t583->dev, RICOH_ONOFFSEL_REG, on_off_val);
	if (ret < 0)
		dev_warn(rc5t583->dev, "Error in writing reg %d error: %d\n",
					RICOH_ONOFFSEL_REG, ret);

	ret = rc5t583_write(rc5t583->dev, RICOH_SWCTL_REG, 0x0);
	if (ret < 0)
		dev_warn(rc5t583->dev, "Error in writing reg %d error: %d\n",
					RICOH_SWCTL_REG, ret);

	/* Clear sleep sequence register */
	for (i = RC5T583_SLPSEQ1; i <= RC5T583_SLPSEQ11; ++i) {
		ret = rc5t583_write(rc5t583->dev, i, 0x0);
		if (ret < 0)
			dev_warn(rc5t583->dev,
				"Error in writing reg 0x%02x error: %d\n",
				i, ret);
	}
	return 0;
}

__attribute__((used)) static bool volatile_reg(struct device *dev, unsigned int reg)
{
	/* Enable caching in interrupt registers */
	switch (reg) {
	case RC5T583_INT_EN_SYS1:
	case RC5T583_INT_EN_SYS2:
	case RC5T583_INT_EN_DCDC:
	case RC5T583_INT_EN_RTC:
	case RC5T583_INT_EN_ADC1:
	case RC5T583_INT_EN_ADC2:
	case RC5T583_INT_EN_ADC3:
	case RC5T583_GPIO_GPEDGE1:
	case RC5T583_GPIO_GPEDGE2:
	case RC5T583_GPIO_EN_INT:
		return false;

	case RC5T583_GPIO_MON_IOIN:
		/* This is gpio input register */
		return true;

	default:
		/* Enable caching in gpio registers */
		if ((reg >= RC5T583_GPIO_IOSEL) &&
				(reg <= RC5T583_GPIO_GPOFUNC))
			return false;

		/* Enable caching in sleep seq registers */
		if ((reg >= RC5T583_SLPSEQ1) && (reg <= RC5T583_SLPSEQ11))
			return false;

		/* Enable caching of regulator registers */
		if ((reg >= RC5T583_REG_DC0CTL) && (reg <= RC5T583_REG_SR3CTL))
			return false;
		if ((reg >= RC5T583_REG_LDOEN1) &&
					(reg <= RC5T583_REG_LDO9DAC_DS))
			return false;

		break;
	}

	return true;
}

__attribute__((used)) static int rc5t583_i2c_probe(struct i2c_client *i2c,
			      const struct i2c_device_id *id)
{
	struct rc5t583 *rc5t583;
	struct rc5t583_platform_data *pdata = dev_get_platdata(&i2c->dev);
	int ret;

	if (!pdata) {
		dev_err(&i2c->dev, "Err: Platform data not found\n");
		return -EINVAL;
	}

	rc5t583 = devm_kzalloc(&i2c->dev, sizeof(*rc5t583), GFP_KERNEL);
	if (!rc5t583)
		return -ENOMEM;

	rc5t583->dev = &i2c->dev;
	i2c_set_clientdata(i2c, rc5t583);

	rc5t583->regmap = devm_regmap_init_i2c(i2c, &rc5t583_regmap_config);
	if (IS_ERR(rc5t583->regmap)) {
		ret = PTR_ERR(rc5t583->regmap);
		dev_err(&i2c->dev, "regmap initialization failed: %d\n", ret);
		return ret;
	}

	ret = rc5t583_clear_ext_power_req(rc5t583, pdata);
	if (ret < 0)
		return ret;

	if (i2c->irq) {
		ret = rc5t583_irq_init(rc5t583, i2c->irq, pdata->irq_base);
		/* Still continue with warning, if irq init fails */
		if (ret)
			dev_warn(&i2c->dev, "IRQ init failed: %d\n", ret);
	}

	ret = devm_mfd_add_devices(rc5t583->dev, -1, rc5t583_subdevs,
				   ARRAY_SIZE(rc5t583_subdevs), NULL, 0, NULL);
	if (ret) {
		dev_err(&i2c->dev, "add mfd devices failed: %d\n", ret);
		return ret;
	}

	return 0;
}

