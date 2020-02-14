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
typedef  int u8 ;
typedef  int u16 ;
struct iio_dev_attr {int address; } ;
struct TYPE_2__ {struct device* parent; } ;
struct iio_dev {char const* name; int /*<<< orphan*/  modes; int /*<<< orphan*/ * info; TYPE_1__ dev; } ;
struct device_attribute {int dummy; } ;
struct device {unsigned short* platform_data; } ;
struct adt7316_bus {int (* write ) (int /*<<< orphan*/ ,int,int) ;int (* read ) (int /*<<< orphan*/ ,int,int*) ;scalar_t__ irq; unsigned short irq_flags; int /*<<< orphan*/  client; } ;
struct adt7316_chip_info {int config1; int id; int config2; int config3; int dac_bits; int dac_config; int ldac_config; unsigned short ldac_pin; int int_mask; struct adt7316_bus bus; } ;
typedef  int ssize_t ;
typedef  int /*<<< orphan*/  s64 ;
typedef  int /*<<< orphan*/  irqreturn_t ;

/* Variables and functions */
 int ADT7316_ADCLK_22_5 ; 
 scalar_t__ ADT7316_AD_MSB_DATA_BASE ; 
#define  ADT7316_AD_SINGLE_CH_EX 136 
#define  ADT7316_AD_SINGLE_CH_IN 135 
 int ADT7316_AD_SINGLE_CH_MASK ; 
 int ADT7316_AD_SINGLE_CH_MODE ; 
#define  ADT7316_AD_SINGLE_CH_VDD 134 
 int ADT7316_CONFIG1 ; 
 int ADT7316_CONFIG2 ; 
 int ADT7316_CONFIG3 ; 
 int ADT7316_DAC_CONFIG ; 
 int ADT7316_DAC_IN_VREF ; 
 int ADT7316_DA_2VREF_CH_MASK ; 
 int ADT7316_DA_DATA_BASE ; 
#define  ADT7316_DA_EN_MODE_ABCD 133 
#define  ADT7316_DA_EN_MODE_AB_CD 132 
 int ADT7316_DA_EN_MODE_LDAC ; 
 int ADT7316_DA_EN_MODE_MASK ; 
#define  ADT7316_DA_EN_MODE_SINGLE 131 
 int ADT7316_DA_EN_VIA_DAC_LDCA ; 
 int ADT7316_DA_HIGH_RESOLUTION ; 
 int ADT7316_DA_MSB_DATA_REGS ; 
 int ADT7316_DEVICE_ID ; 
 int ADT7316_DEVICE_REV ; 
 int ADT7316_DISABLE_AVERAGING ; 
 int ADT7316_EN ; 
 int ADT7316_EN_EX_TEMP_PROP_DACB ; 
 int ADT7316_EN_IN_TEMP_PROP_DACA ; 
 int ADT7316_EN_SMBUS_TIMEOUT ; 
 int ADT7316_EX_ANALOG_TEMP_OFFSET ; 
 int ADT7316_EX_TEMP_LOW ; 
 int ADT7316_EX_TEMP_OFFSET ; 
 int ADT7316_INT_EN ; 
 int ADT7316_INT_MASK1 ; 
 int ADT7316_INT_MASK2 ; 
 int ADT7316_INT_MASK2_VDD ; 
 int ADT7316_INT_POLARITY ; 
 int ADT7316_INT_STAT1 ; 
 int ADT7316_INT_STAT2 ; 
 int ADT7316_IN_ANALOG_TEMP_OFFSET ; 
 int ADT7316_IN_TEMP_OFFSET ; 
 int ADT7316_LDAC_CONFIG ; 
 int ADT7316_LDAC_EN_DA_MASK ; 
 int ADT7316_LSB_EX_TEMP_AIN ; 
 int ADT7316_LSB_EX_TEMP_MASK ; 
 int ADT7316_LSB_IN_TEMP_MASK ; 
 int ADT7316_LSB_IN_TEMP_VDD ; 
 int ADT7316_LSB_VDD_MASK ; 
 int ADT7316_LSB_VDD_OFFSET ; 
 int ADT7316_MANUFACTURE_ID ; 
 scalar_t__ ADT7316_MSB_EX_TEMP ; 
 int ADT7316_PD ; 
 int ADT7316_SPI_LOCK_STAT ; 
 int ADT7316_TEMP_AIN_INT_MASK ; 
 int ADT7316_TEMP_INT_MASK ; 
 int ADT7316_T_VALUE_FLOAT_MASK ; 
 int ADT7316_T_VALUE_FLOAT_OFFSET ; 
 int ADT7316_T_VALUE_SIGN ; 
 int ADT7316_VDD_INT_MASK ; 
 int ADT7316_VREF_BYPASS_DAC_AB ; 
 int ADT7316_VREF_BYPASS_DAC_CD ; 
#define  ADT7516_AD_SINGLE_CH_AIN2 130 
#define  ADT7516_AD_SINGLE_CH_AIN3 129 
#define  ADT7516_AD_SINGLE_CH_AIN4 128 
 int ADT7516_AD_SINGLE_CH_MASK ; 
 int ADT7516_AIN_INT_MASK ; 
 int ADT7516_AIN_IN_VREF ; 
 int ADT7516_DAC_AB_IN_VREF ; 
 int ADT7516_DAC_CD_IN_VREF ; 
 int ADT7516_DAC_IN_VREF_MASK ; 
 int ADT7516_DAC_IN_VREF_OFFSET ; 
 int ADT7516_LSB_AIN_SHIFT ; 
 int ADT7516_SEL_AIN1_2_EX_TEMP_MASK ; 
 int ADT7516_SEL_AIN3 ; 
 int ADT7516_SEL_EX_TEMP ; 
 int BIT (int) ; 
 int EINVAL ; 
 int EIO ; 
 int ENODEV ; 
 int ENOMEM ; 
 int EPERM ; 
 scalar_t__ ID_ADT7316 ; 
 scalar_t__ ID_ADT7317 ; 
 int ID_ADT73XX ; 
 scalar_t__ ID_ADT7516 ; 
 scalar_t__ ID_ADT7517 ; 
 int ID_ADT75XX ; 
 int ID_FAMILY_MASK ; 
 int /*<<< orphan*/  IIO_EV_DIR_EITHER ; 
 int /*<<< orphan*/  IIO_EV_DIR_FALLING ; 
 int /*<<< orphan*/  IIO_EV_DIR_RISING ; 
 int /*<<< orphan*/  IIO_EV_TYPE_THRESH ; 
 int /*<<< orphan*/  IIO_TEMP ; 
 int /*<<< orphan*/  IIO_UNMOD_EVENT_CODE (int /*<<< orphan*/ ,int,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  IIO_VOLTAGE ; 
 int /*<<< orphan*/  INDIO_DIRECT_MODE ; 
 int IRQF_ONESHOT ; 
 int IRQF_TRIGGER_HIGH ; 
 int /*<<< orphan*/  IRQ_HANDLED ; 
 int /*<<< orphan*/  adt7316_info ; 
 int /*<<< orphan*/  adt7516_info ; 
 int /*<<< orphan*/  dev_info (struct device*,char*,char const*) ; 
 int /*<<< orphan*/  dev_set_drvdata (struct device*,struct iio_dev*) ; 
 struct iio_dev* dev_to_iio_dev (struct device*) ; 
 struct iio_dev* devm_iio_device_alloc (struct device*,int) ; 
 int devm_iio_device_register (struct device*,struct iio_dev*) ; 
 int devm_request_threaded_irq (struct device*,scalar_t__,int /*<<< orphan*/ *,int /*<<< orphan*/  (*) (int,void*),int,char const*,struct iio_dev*) ; 
 int /*<<< orphan*/  gpio_set_value (unsigned short,int) ; 
 int /*<<< orphan*/  iio_get_time_ns (struct iio_dev*) ; 
 struct adt7316_chip_info* iio_priv (struct iio_dev*) ; 
 int /*<<< orphan*/  iio_push_event (struct iio_dev*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int kstrtoint (char const*,int,int*) ; 
 int kstrtou16 (char const*,int,int*) ; 
 int kstrtou8 (char const*,int,int*) ; 
 int /*<<< orphan*/  memcmp (char const*,char*,int) ; 
 int sprintf (char*,char*,...) ; 
 int stub1 (int /*<<< orphan*/ ,int,int) ; 
 int stub10 (int /*<<< orphan*/ ,int,int) ; 
 int stub11 (int /*<<< orphan*/ ,int,int) ; 
 int stub12 (int /*<<< orphan*/ ,int,int) ; 
 int stub13 (int /*<<< orphan*/ ,int,int) ; 
 int stub14 (int /*<<< orphan*/ ,int,int) ; 
 int stub15 (int /*<<< orphan*/ ,int,int) ; 
 int stub16 (int /*<<< orphan*/ ,int,int) ; 
 int stub17 (int /*<<< orphan*/ ,int,int) ; 
 int stub18 (int /*<<< orphan*/ ,int,int) ; 
 int stub19 (int /*<<< orphan*/ ,int,int*) ; 
 int stub2 (int /*<<< orphan*/ ,int,int) ; 
 int stub20 (int /*<<< orphan*/ ,int,int*) ; 
 int stub21 (int /*<<< orphan*/ ,int,int*) ; 
 int stub22 (int /*<<< orphan*/ ,int,int*) ; 
 int stub23 (int /*<<< orphan*/ ,int,int*) ; 
 int stub24 (int /*<<< orphan*/ ,int,int*) ; 
 int stub25 (int /*<<< orphan*/ ,int,int*) ; 
 int stub26 (int /*<<< orphan*/ ,int,int) ; 
 int stub27 (int /*<<< orphan*/ ,int,int*) ; 
 int stub28 (int /*<<< orphan*/ ,int,int*) ; 
 int stub29 (int /*<<< orphan*/ ,int,int) ; 
 int stub3 (int /*<<< orphan*/ ,int,int) ; 
 int stub30 (int /*<<< orphan*/ ,int,int) ; 
 int stub31 (int /*<<< orphan*/ ,int,int*) ; 
 int stub32 (int /*<<< orphan*/ ,int,int*) ; 
 int stub33 (int /*<<< orphan*/ ,int,int*) ; 
 int stub34 (int /*<<< orphan*/ ,int,int*) ; 
 int stub35 (int /*<<< orphan*/ ,int,int*) ; 
 int stub36 (int /*<<< orphan*/ ,int,int*) ; 
 int stub37 (int /*<<< orphan*/ ,int,int) ; 
 int stub38 (int /*<<< orphan*/ ,int,int) ; 
 int stub39 (int /*<<< orphan*/ ,int,int*) ; 
 int stub4 (int /*<<< orphan*/ ,int,int) ; 
 int stub40 (int /*<<< orphan*/ ,int,int) ; 
 int stub41 (int /*<<< orphan*/ ,int,int) ; 
 int stub42 (int /*<<< orphan*/ ,int,int) ; 
 int stub43 (int /*<<< orphan*/ ,int,int) ; 
 int stub5 (int /*<<< orphan*/ ,int,int) ; 
 int stub6 (int /*<<< orphan*/ ,int,int) ; 
 int stub7 (int /*<<< orphan*/ ,int,int) ; 
 int stub8 (int /*<<< orphan*/ ,int,int) ; 
 int stub9 (int /*<<< orphan*/ ,int,int) ; 
 struct iio_dev_attr* to_iio_dev_attr (struct device_attribute*) ; 

__attribute__((used)) static ssize_t adt7316_show_enabled(struct device *dev,
		struct device_attribute *attr,
		char *buf)
{
	struct iio_dev *dev_info = dev_to_iio_dev(dev);
	struct adt7316_chip_info *chip = iio_priv(dev_info);

	return sprintf(buf, "%d\n", !!(chip->config1 & ADT7316_EN));
}

__attribute__((used)) static ssize_t _adt7316_store_enabled(struct adt7316_chip_info *chip,
		int enable)
{
	u8 config1;
	int ret;

	if (enable)
		config1 = chip->config1 | ADT7316_EN;
	else
		config1 = chip->config1 & ~ADT7316_EN;

	ret = chip->bus.write(chip->bus.client, ADT7316_CONFIG1, config1);
	if (ret)
		return -EIO;

	chip->config1 = config1;

	return ret;
}

__attribute__((used)) static ssize_t adt7316_store_enabled(struct device *dev,
		struct device_attribute *attr,
		const char *buf,
		size_t len)
{
	struct iio_dev *dev_info = dev_to_iio_dev(dev);
	struct adt7316_chip_info *chip = iio_priv(dev_info);
	int enable;

	if (buf[0] == '1')
		enable = 1;
	else
		enable = 0;

	if (_adt7316_store_enabled(chip, enable) < 0)
		return -EIO;

	return len;
}

__attribute__((used)) static ssize_t adt7316_show_select_ex_temp(struct device *dev,
		struct device_attribute *attr,
		char *buf)
{
	struct iio_dev *dev_info = dev_to_iio_dev(dev);
	struct adt7316_chip_info *chip = iio_priv(dev_info);

	if ((chip->id & ID_FAMILY_MASK) != ID_ADT75XX)
		return -EPERM;

	return sprintf(buf, "%d\n", !!(chip->config1 & ADT7516_SEL_EX_TEMP));
}

__attribute__((used)) static ssize_t adt7316_store_select_ex_temp(struct device *dev,
		struct device_attribute *attr,
		const char *buf,
		size_t len)
{
	struct iio_dev *dev_info = dev_to_iio_dev(dev);
	struct adt7316_chip_info *chip = iio_priv(dev_info);
	u8 config1;
	int ret;

	if ((chip->id & ID_FAMILY_MASK) != ID_ADT75XX)
		return -EPERM;

	config1 = chip->config1 & (~ADT7516_SEL_EX_TEMP);
	if (buf[0] == '1')
		config1 |= ADT7516_SEL_EX_TEMP;

	ret = chip->bus.write(chip->bus.client, ADT7316_CONFIG1, config1);
	if (ret)
		return -EIO;

	chip->config1 = config1;

	return len;
}

__attribute__((used)) static ssize_t adt7316_show_mode(struct device *dev,
		struct device_attribute *attr,
		char *buf)
{
	struct iio_dev *dev_info = dev_to_iio_dev(dev);
	struct adt7316_chip_info *chip = iio_priv(dev_info);

	if (chip->config2 & ADT7316_AD_SINGLE_CH_MODE)
		return sprintf(buf, "single_channel\n");

	return sprintf(buf, "round_robin\n");
}

__attribute__((used)) static ssize_t adt7316_store_mode(struct device *dev,
		struct device_attribute *attr,
		const char *buf,
		size_t len)
{
	struct iio_dev *dev_info = dev_to_iio_dev(dev);
	struct adt7316_chip_info *chip = iio_priv(dev_info);
	u8 config2;
	int ret;

	config2 = chip->config2 & (~ADT7316_AD_SINGLE_CH_MODE);
	if (!memcmp(buf, "single_channel", 14))
		config2 |= ADT7316_AD_SINGLE_CH_MODE;

	ret = chip->bus.write(chip->bus.client, ADT7316_CONFIG2, config2);
	if (ret)
		return -EIO;

	chip->config2 = config2;

	return len;
}

__attribute__((used)) static ssize_t adt7316_show_all_modes(struct device *dev,
		struct device_attribute *attr,
		char *buf)
{
	return sprintf(buf, "single_channel\nround_robin\n");
}

__attribute__((used)) static ssize_t adt7316_show_ad_channel(struct device *dev,
		struct device_attribute *attr,
		char *buf)
{
	struct iio_dev *dev_info = dev_to_iio_dev(dev);
	struct adt7316_chip_info *chip = iio_priv(dev_info);

	if (!(chip->config2 & ADT7316_AD_SINGLE_CH_MODE))
		return -EPERM;

	switch (chip->config2 & ADT7516_AD_SINGLE_CH_MASK) {
	case ADT7316_AD_SINGLE_CH_VDD:
		return sprintf(buf, "0 - VDD\n");
	case ADT7316_AD_SINGLE_CH_IN:
		return sprintf(buf, "1 - Internal Temperature\n");
	case ADT7316_AD_SINGLE_CH_EX:
		if (((chip->id & ID_FAMILY_MASK) == ID_ADT75XX) &&
			(chip->config1 & ADT7516_SEL_AIN1_2_EX_TEMP_MASK) == 0)
			return sprintf(buf, "2 - AIN1\n");

		return sprintf(buf, "2 - External Temperature\n");
	case ADT7516_AD_SINGLE_CH_AIN2:
		if ((chip->config1 & ADT7516_SEL_AIN1_2_EX_TEMP_MASK) == 0)
			return sprintf(buf, "3 - AIN2\n");

		return sprintf(buf, "N/A\n");
	case ADT7516_AD_SINGLE_CH_AIN3:
		if (chip->config1 & ADT7516_SEL_AIN3)
			return sprintf(buf, "4 - AIN3\n");

		return sprintf(buf, "N/A\n");
	case ADT7516_AD_SINGLE_CH_AIN4:
		return sprintf(buf, "5 - AIN4\n");
	default:
		return sprintf(buf, "N/A\n");
	}
}

__attribute__((used)) static ssize_t adt7316_store_ad_channel(struct device *dev,
		struct device_attribute *attr,
		const char *buf,
		size_t len)
{
	struct iio_dev *dev_info = dev_to_iio_dev(dev);
	struct adt7316_chip_info *chip = iio_priv(dev_info);
	u8 config2;
	u8 data;
	int ret;

	if (!(chip->config2 & ADT7316_AD_SINGLE_CH_MODE))
		return -EPERM;

	ret = kstrtou8(buf, 10, &data);
	if (ret)
		return -EINVAL;

	if ((chip->id & ID_FAMILY_MASK) == ID_ADT75XX) {
		if (data > 5)
			return -EINVAL;

		config2 = chip->config2 & (~ADT7516_AD_SINGLE_CH_MASK);
	} else {
		if (data > 2)
			return -EINVAL;

		config2 = chip->config2 & (~ADT7316_AD_SINGLE_CH_MASK);
	}

	config2 |= data;

	ret = chip->bus.write(chip->bus.client, ADT7316_CONFIG2, config2);
	if (ret)
		return -EIO;

	chip->config2 = config2;

	return len;
}

__attribute__((used)) static ssize_t adt7316_show_all_ad_channels(struct device *dev,
		struct device_attribute *attr,
		char *buf)
{
	struct iio_dev *dev_info = dev_to_iio_dev(dev);
	struct adt7316_chip_info *chip = iio_priv(dev_info);

	if (!(chip->config2 & ADT7316_AD_SINGLE_CH_MODE))
		return -EPERM;

	if ((chip->id & ID_FAMILY_MASK) == ID_ADT75XX)
		return sprintf(buf, "0 - VDD\n1 - Internal Temperature\n"
				"2 - External Temperature or AIN1\n"
				"3 - AIN2\n4 - AIN3\n5 - AIN4\n");
	return sprintf(buf, "0 - VDD\n1 - Internal Temperature\n"
			"2 - External Temperature\n");
}

__attribute__((used)) static ssize_t adt7316_show_disable_averaging(struct device *dev,
		struct device_attribute *attr,
		char *buf)
{
	struct iio_dev *dev_info = dev_to_iio_dev(dev);
	struct adt7316_chip_info *chip = iio_priv(dev_info);

	return sprintf(buf, "%d\n",
		!!(chip->config2 & ADT7316_DISABLE_AVERAGING));
}

__attribute__((used)) static ssize_t adt7316_store_disable_averaging(struct device *dev,
		struct device_attribute *attr,
		const char *buf,
		size_t len)
{
	struct iio_dev *dev_info = dev_to_iio_dev(dev);
	struct adt7316_chip_info *chip = iio_priv(dev_info);
	u8 config2;
	int ret;

	config2 = chip->config2 & (~ADT7316_DISABLE_AVERAGING);
	if (buf[0] == '1')
		config2 |= ADT7316_DISABLE_AVERAGING;

	ret = chip->bus.write(chip->bus.client, ADT7316_CONFIG2, config2);
	if (ret)
		return -EIO;

	chip->config2 = config2;

	return len;
}

__attribute__((used)) static ssize_t adt7316_show_enable_smbus_timeout(struct device *dev,
		struct device_attribute *attr,
		char *buf)
{
	struct iio_dev *dev_info = dev_to_iio_dev(dev);
	struct adt7316_chip_info *chip = iio_priv(dev_info);

	return sprintf(buf, "%d\n",
		!!(chip->config2 & ADT7316_EN_SMBUS_TIMEOUT));
}

__attribute__((used)) static ssize_t adt7316_store_enable_smbus_timeout(struct device *dev,
		struct device_attribute *attr,
		const char *buf,
		size_t len)
{
	struct iio_dev *dev_info = dev_to_iio_dev(dev);
	struct adt7316_chip_info *chip = iio_priv(dev_info);
	u8 config2;
	int ret;

	config2 = chip->config2 & (~ADT7316_EN_SMBUS_TIMEOUT);
	if (buf[0] == '1')
		config2 |= ADT7316_EN_SMBUS_TIMEOUT;

	ret = chip->bus.write(chip->bus.client, ADT7316_CONFIG2, config2);
	if (ret)
		return -EIO;

	chip->config2 = config2;

	return len;
}

__attribute__((used)) static ssize_t adt7316_show_powerdown(struct device *dev,
		struct device_attribute *attr,
		char *buf)
{
	struct iio_dev *dev_info = dev_to_iio_dev(dev);
	struct adt7316_chip_info *chip = iio_priv(dev_info);

	return sprintf(buf, "%d\n", !!(chip->config1 & ADT7316_PD));
}

__attribute__((used)) static ssize_t adt7316_store_powerdown(struct device *dev,
		struct device_attribute *attr,
		const char *buf,
		size_t len)
{
	struct iio_dev *dev_info = dev_to_iio_dev(dev);
	struct adt7316_chip_info *chip = iio_priv(dev_info);
	u8 config1;
	int ret;

	config1 = chip->config1 & (~ADT7316_PD);
	if (buf[0] == '1')
		config1 |= ADT7316_PD;

	ret = chip->bus.write(chip->bus.client, ADT7316_CONFIG1, config1);
	if (ret)
		return -EIO;

	chip->config1 = config1;

	return len;
}

__attribute__((used)) static ssize_t adt7316_show_fast_ad_clock(struct device *dev,
		struct device_attribute *attr,
		char *buf)
{
	struct iio_dev *dev_info = dev_to_iio_dev(dev);
	struct adt7316_chip_info *chip = iio_priv(dev_info);

	return sprintf(buf, "%d\n", !!(chip->config3 & ADT7316_ADCLK_22_5));
}

__attribute__((used)) static ssize_t adt7316_store_fast_ad_clock(struct device *dev,
		struct device_attribute *attr,
		const char *buf,
		size_t len)
{
	struct iio_dev *dev_info = dev_to_iio_dev(dev);
	struct adt7316_chip_info *chip = iio_priv(dev_info);
	u8 config3;
	int ret;

	config3 = chip->config3 & (~ADT7316_ADCLK_22_5);
	if (buf[0] == '1')
		config3 |= ADT7316_ADCLK_22_5;

	ret = chip->bus.write(chip->bus.client, ADT7316_CONFIG3, config3);
	if (ret)
		return -EIO;

	chip->config3 = config3;

	return len;
}

__attribute__((used)) static ssize_t adt7316_show_da_high_resolution(struct device *dev,
		struct device_attribute *attr,
		char *buf)
{
	struct iio_dev *dev_info = dev_to_iio_dev(dev);
	struct adt7316_chip_info *chip = iio_priv(dev_info);

	if (chip->config3 & ADT7316_DA_HIGH_RESOLUTION) {
		if (chip->id == ID_ADT7316 || chip->id == ID_ADT7516)
			return sprintf(buf, "1 (12 bits)\n");
		if (chip->id == ID_ADT7317 || chip->id == ID_ADT7517)
			return sprintf(buf, "1 (10 bits)\n");
	}

	return sprintf(buf, "0 (8 bits)\n");
}

__attribute__((used)) static ssize_t adt7316_store_da_high_resolution(struct device *dev,
		struct device_attribute *attr,
		const char *buf,
		size_t len)
{
	struct iio_dev *dev_info = dev_to_iio_dev(dev);
	struct adt7316_chip_info *chip = iio_priv(dev_info);
	u8 config3;
	int ret;

	chip->dac_bits = 8;

	if (buf[0] == '1') {
		config3 = chip->config3 | ADT7316_DA_HIGH_RESOLUTION;
		if (chip->id == ID_ADT7316 || chip->id == ID_ADT7516)
			chip->dac_bits = 12;
		else if (chip->id == ID_ADT7317 || chip->id == ID_ADT7517)
			chip->dac_bits = 10;
	} else {
		config3 = chip->config3 & (~ADT7316_DA_HIGH_RESOLUTION);
	}

	ret = chip->bus.write(chip->bus.client, ADT7316_CONFIG3, config3);
	if (ret)
		return -EIO;

	chip->config3 = config3;

	return len;
}

__attribute__((used)) static ssize_t adt7316_show_AIN_internal_Vref(struct device *dev,
		struct device_attribute *attr,
		char *buf)
{
	struct iio_dev *dev_info = dev_to_iio_dev(dev);
	struct adt7316_chip_info *chip = iio_priv(dev_info);

	if ((chip->id & ID_FAMILY_MASK) != ID_ADT75XX)
		return -EPERM;

	return sprintf(buf, "%d\n",
		!!(chip->config3 & ADT7516_AIN_IN_VREF));
}

__attribute__((used)) static ssize_t adt7316_store_AIN_internal_Vref(struct device *dev,
		struct device_attribute *attr,
		const char *buf,
		size_t len)
{
	struct iio_dev *dev_info = dev_to_iio_dev(dev);
	struct adt7316_chip_info *chip = iio_priv(dev_info);
	u8 config3;
	int ret;

	if ((chip->id & ID_FAMILY_MASK) != ID_ADT75XX)
		return -EPERM;

	if (buf[0] != '1')
		config3 = chip->config3 & (~ADT7516_AIN_IN_VREF);
	else
		config3 = chip->config3 | ADT7516_AIN_IN_VREF;

	ret = chip->bus.write(chip->bus.client, ADT7316_CONFIG3, config3);
	if (ret)
		return -EIO;

	chip->config3 = config3;

	return len;
}

__attribute__((used)) static ssize_t adt7316_show_enable_prop_DACA(struct device *dev,
		struct device_attribute *attr,
		char *buf)
{
	struct iio_dev *dev_info = dev_to_iio_dev(dev);
	struct adt7316_chip_info *chip = iio_priv(dev_info);

	return sprintf(buf, "%d\n",
		!!(chip->config3 & ADT7316_EN_IN_TEMP_PROP_DACA));
}

__attribute__((used)) static ssize_t adt7316_store_enable_prop_DACA(struct device *dev,
		struct device_attribute *attr,
		const char *buf,
		size_t len)
{
	struct iio_dev *dev_info = dev_to_iio_dev(dev);
	struct adt7316_chip_info *chip = iio_priv(dev_info);
	u8 config3;
	int ret;

	config3 = chip->config3 & (~ADT7316_EN_IN_TEMP_PROP_DACA);
	if (buf[0] == '1')
		config3 |= ADT7316_EN_IN_TEMP_PROP_DACA;

	ret = chip->bus.write(chip->bus.client, ADT7316_CONFIG3, config3);
	if (ret)
		return -EIO;

	chip->config3 = config3;

	return len;
}

__attribute__((used)) static ssize_t adt7316_show_enable_prop_DACB(struct device *dev,
		struct device_attribute *attr,
		char *buf)
{
	struct iio_dev *dev_info = dev_to_iio_dev(dev);
	struct adt7316_chip_info *chip = iio_priv(dev_info);

	return sprintf(buf, "%d\n",
		!!(chip->config3 & ADT7316_EN_EX_TEMP_PROP_DACB));
}

__attribute__((used)) static ssize_t adt7316_store_enable_prop_DACB(struct device *dev,
		struct device_attribute *attr,
		const char *buf,
		size_t len)
{
	struct iio_dev *dev_info = dev_to_iio_dev(dev);
	struct adt7316_chip_info *chip = iio_priv(dev_info);
	u8 config3;
	int ret;

	config3 = chip->config3 & (~ADT7316_EN_EX_TEMP_PROP_DACB);
	if (buf[0] == '1')
		config3 |= ADT7316_EN_EX_TEMP_PROP_DACB;

	ret = chip->bus.write(chip->bus.client, ADT7316_CONFIG3, config3);
	if (ret)
		return -EIO;

	chip->config3 = config3;

	return len;
}

__attribute__((used)) static ssize_t adt7316_show_DAC_2Vref_ch_mask(struct device *dev,
		struct device_attribute *attr,
		char *buf)
{
	struct iio_dev *dev_info = dev_to_iio_dev(dev);
	struct adt7316_chip_info *chip = iio_priv(dev_info);

	return sprintf(buf, "0x%x\n",
		chip->dac_config & ADT7316_DA_2VREF_CH_MASK);
}

__attribute__((used)) static ssize_t adt7316_store_DAC_2Vref_ch_mask(struct device *dev,
		struct device_attribute *attr,
		const char *buf,
		size_t len)
{
	struct iio_dev *dev_info = dev_to_iio_dev(dev);
	struct adt7316_chip_info *chip = iio_priv(dev_info);
	u8 dac_config;
	u8 data;
	int ret;

	ret = kstrtou8(buf, 16, &data);
	if (ret || data > ADT7316_DA_2VREF_CH_MASK)
		return -EINVAL;

	dac_config = chip->dac_config & (~ADT7316_DA_2VREF_CH_MASK);
	dac_config |= data;

	ret = chip->bus.write(chip->bus.client, ADT7316_DAC_CONFIG, dac_config);
	if (ret)
		return -EIO;

	chip->dac_config = dac_config;

	return len;
}

__attribute__((used)) static ssize_t adt7316_show_DAC_update_mode(struct device *dev,
		struct device_attribute *attr,
		char *buf)
{
	struct iio_dev *dev_info = dev_to_iio_dev(dev);
	struct adt7316_chip_info *chip = iio_priv(dev_info);

	if (!(chip->config3 & ADT7316_DA_EN_VIA_DAC_LDCA))
		return sprintf(buf, "manual\n");

	switch (chip->dac_config & ADT7316_DA_EN_MODE_MASK) {
	case ADT7316_DA_EN_MODE_SINGLE:
		return sprintf(buf,
			"0 - auto at any MSB DAC writing\n");
	case ADT7316_DA_EN_MODE_AB_CD:
		return sprintf(buf,
			"1 - auto at MSB DAC AB and CD writing\n");
	case ADT7316_DA_EN_MODE_ABCD:
		return sprintf(buf,
			"2 - auto at MSB DAC ABCD writing\n");
	default: /* ADT7316_DA_EN_MODE_LDAC */
		return sprintf(buf, "3 - manual\n");
	}
}

__attribute__((used)) static ssize_t adt7316_store_DAC_update_mode(struct device *dev,
		struct device_attribute *attr,
		const char *buf,
		size_t len)
{
	struct iio_dev *dev_info = dev_to_iio_dev(dev);
	struct adt7316_chip_info *chip = iio_priv(dev_info);
	u8 dac_config;
	u8 data;
	int ret;

	if (!(chip->config3 & ADT7316_DA_EN_VIA_DAC_LDCA))
		return -EPERM;

	ret = kstrtou8(buf, 10, &data);
	if (ret || data > ADT7316_DA_EN_MODE_MASK)
		return -EINVAL;

	dac_config = chip->dac_config & (~ADT7316_DA_EN_MODE_MASK);
	dac_config |= data;

	ret = chip->bus.write(chip->bus.client, ADT7316_DAC_CONFIG, dac_config);
	if (ret)
		return -EIO;

	chip->dac_config = dac_config;

	return len;
}

__attribute__((used)) static ssize_t adt7316_show_all_DAC_update_modes(struct device *dev,
		struct device_attribute *attr,
		char *buf)
{
	struct iio_dev *dev_info = dev_to_iio_dev(dev);
	struct adt7316_chip_info *chip = iio_priv(dev_info);

	if (chip->config3 & ADT7316_DA_EN_VIA_DAC_LDCA)
		return sprintf(buf, "0 - auto at any MSB DAC writing\n"
				"1 - auto at MSB DAC AB and CD writing\n"
				"2 - auto at MSB DAC ABCD writing\n"
				"3 - manual\n");
	return sprintf(buf, "manual\n");
}

__attribute__((used)) static ssize_t adt7316_store_update_DAC(struct device *dev,
		struct device_attribute *attr,
		const char *buf,
		size_t len)
{
	struct iio_dev *dev_info = dev_to_iio_dev(dev);
	struct adt7316_chip_info *chip = iio_priv(dev_info);
	u8 ldac_config;
	u8 data;
	int ret;

	if (chip->config3 & ADT7316_DA_EN_VIA_DAC_LDCA) {
		if ((chip->dac_config & ADT7316_DA_EN_MODE_MASK) !=
			ADT7316_DA_EN_MODE_LDAC)
			return -EPERM;

		ret = kstrtou8(buf, 16, &data);
		if (ret || data > ADT7316_LDAC_EN_DA_MASK)
			return -EINVAL;

		ldac_config = chip->ldac_config & (~ADT7316_LDAC_EN_DA_MASK);
		ldac_config |= data;

		ret = chip->bus.write(chip->bus.client, ADT7316_LDAC_CONFIG,
			ldac_config);
		if (ret)
			return -EIO;
	} else {
		gpio_set_value(chip->ldac_pin, 0);
		gpio_set_value(chip->ldac_pin, 1);
	}

	return len;
}

__attribute__((used)) static ssize_t adt7316_show_DA_AB_Vref_bypass(struct device *dev,
		struct device_attribute *attr,
		char *buf)
{
	struct iio_dev *dev_info = dev_to_iio_dev(dev);
	struct adt7316_chip_info *chip = iio_priv(dev_info);

	if ((chip->id & ID_FAMILY_MASK) == ID_ADT75XX)
		return -EPERM;

	return sprintf(buf, "%d\n",
		!!(chip->dac_config & ADT7316_VREF_BYPASS_DAC_AB));
}

__attribute__((used)) static ssize_t adt7316_store_DA_AB_Vref_bypass(struct device *dev,
		struct device_attribute *attr,
		const char *buf,
		size_t len)
{
	struct iio_dev *dev_info = dev_to_iio_dev(dev);
	struct adt7316_chip_info *chip = iio_priv(dev_info);
	u8 dac_config;
	int ret;

	if ((chip->id & ID_FAMILY_MASK) == ID_ADT75XX)
		return -EPERM;

	dac_config = chip->dac_config & (~ADT7316_VREF_BYPASS_DAC_AB);
	if (buf[0] == '1')
		dac_config |= ADT7316_VREF_BYPASS_DAC_AB;

	ret = chip->bus.write(chip->bus.client, ADT7316_DAC_CONFIG, dac_config);
	if (ret)
		return -EIO;

	chip->dac_config = dac_config;

	return len;
}

__attribute__((used)) static ssize_t adt7316_show_DA_CD_Vref_bypass(struct device *dev,
		struct device_attribute *attr,
		char *buf)
{
	struct iio_dev *dev_info = dev_to_iio_dev(dev);
	struct adt7316_chip_info *chip = iio_priv(dev_info);

	if ((chip->id & ID_FAMILY_MASK) == ID_ADT75XX)
		return -EPERM;

	return sprintf(buf, "%d\n",
		!!(chip->dac_config & ADT7316_VREF_BYPASS_DAC_CD));
}

__attribute__((used)) static ssize_t adt7316_store_DA_CD_Vref_bypass(struct device *dev,
		struct device_attribute *attr,
		const char *buf,
		size_t len)
{
	struct iio_dev *dev_info = dev_to_iio_dev(dev);
	struct adt7316_chip_info *chip = iio_priv(dev_info);
	u8 dac_config;
	int ret;

	if ((chip->id & ID_FAMILY_MASK) == ID_ADT75XX)
		return -EPERM;

	dac_config = chip->dac_config & (~ADT7316_VREF_BYPASS_DAC_CD);
	if (buf[0] == '1')
		dac_config |= ADT7316_VREF_BYPASS_DAC_CD;

	ret = chip->bus.write(chip->bus.client, ADT7316_DAC_CONFIG, dac_config);
	if (ret)
		return -EIO;

	chip->dac_config = dac_config;

	return len;
}

__attribute__((used)) static ssize_t adt7316_show_DAC_internal_Vref(struct device *dev,
		struct device_attribute *attr,
		char *buf)
{
	struct iio_dev *dev_info = dev_to_iio_dev(dev);
	struct adt7316_chip_info *chip = iio_priv(dev_info);

	if ((chip->id & ID_FAMILY_MASK) == ID_ADT75XX)
		return sprintf(buf, "0x%x\n",
			(chip->dac_config & ADT7516_DAC_IN_VREF_MASK) >>
			ADT7516_DAC_IN_VREF_OFFSET);
	return sprintf(buf, "%d\n",
		       !!(chip->dac_config & ADT7316_DAC_IN_VREF));
}

__attribute__((used)) static ssize_t adt7316_store_DAC_internal_Vref(struct device *dev,
		struct device_attribute *attr,
		const char *buf,
		size_t len)
{
	struct iio_dev *dev_info = dev_to_iio_dev(dev);
	struct adt7316_chip_info *chip = iio_priv(dev_info);
	u8 ldac_config;
	u8 data;
	int ret;

	if ((chip->id & ID_FAMILY_MASK) == ID_ADT75XX) {
		ret = kstrtou8(buf, 16, &data);
		if (ret || data > 3)
			return -EINVAL;

		ldac_config = chip->ldac_config & (~ADT7516_DAC_IN_VREF_MASK);
		if (data & 0x1)
			ldac_config |= ADT7516_DAC_AB_IN_VREF;
		else if (data & 0x2)
			ldac_config |= ADT7516_DAC_CD_IN_VREF;
	} else {
		ret = kstrtou8(buf, 16, &data);
		if (ret)
			return -EINVAL;

		ldac_config = chip->ldac_config & (~ADT7316_DAC_IN_VREF);
		if (data)
			ldac_config = chip->ldac_config | ADT7316_DAC_IN_VREF;
	}

	ret = chip->bus.write(chip->bus.client, ADT7316_LDAC_CONFIG,
			ldac_config);
	if (ret)
		return -EIO;

	chip->ldac_config = ldac_config;

	return len;
}

__attribute__((used)) static ssize_t adt7316_show_ad(struct adt7316_chip_info *chip,
		int channel, char *buf)
{
	u16 data;
	u8 msb, lsb;
	char sign = ' ';
	int ret;

	if ((chip->config2 & ADT7316_AD_SINGLE_CH_MODE) &&
		channel != (chip->config2 & ADT7516_AD_SINGLE_CH_MASK))
		return -EPERM;

	switch (channel) {
	case ADT7316_AD_SINGLE_CH_IN:
		ret = chip->bus.read(chip->bus.client,
			ADT7316_LSB_IN_TEMP_VDD, &lsb);
		if (ret)
			return -EIO;

		ret = chip->bus.read(chip->bus.client,
			ADT7316_AD_MSB_DATA_BASE + channel, &msb);
		if (ret)
			return -EIO;

		data = msb << ADT7316_T_VALUE_FLOAT_OFFSET;
		data |= lsb & ADT7316_LSB_IN_TEMP_MASK;
		break;
	case ADT7316_AD_SINGLE_CH_VDD:
		ret = chip->bus.read(chip->bus.client,
			ADT7316_LSB_IN_TEMP_VDD, &lsb);
		if (ret)
			return -EIO;

		ret = chip->bus.read(chip->bus.client,

			ADT7316_AD_MSB_DATA_BASE + channel, &msb);
		if (ret)
			return -EIO;

		data = msb << ADT7316_T_VALUE_FLOAT_OFFSET;
		data |= (lsb & ADT7316_LSB_VDD_MASK) >> ADT7316_LSB_VDD_OFFSET;
		return sprintf(buf, "%d\n", data);
	default: /* ex_temp and ain */
		ret = chip->bus.read(chip->bus.client,
			ADT7316_LSB_EX_TEMP_AIN, &lsb);
		if (ret)
			return -EIO;

		ret = chip->bus.read(chip->bus.client,
			ADT7316_AD_MSB_DATA_BASE + channel, &msb);
		if (ret)
			return -EIO;

		data = msb << ADT7316_T_VALUE_FLOAT_OFFSET;
		data |= lsb & (ADT7316_LSB_EX_TEMP_MASK <<
			(ADT7516_LSB_AIN_SHIFT * (channel -
			(ADT7316_MSB_EX_TEMP - ADT7316_AD_MSB_DATA_BASE))));

		if ((chip->id & ID_FAMILY_MASK) == ID_ADT75XX)
			return sprintf(buf, "%d\n", data);

		break;
	}

	if (data & ADT7316_T_VALUE_SIGN) {
		/* convert supplement to positive value */
		data = (ADT7316_T_VALUE_SIGN << 1) - data;
		sign = '-';
	}

	return sprintf(buf, "%c%d.%.2d\n", sign,
		(data >> ADT7316_T_VALUE_FLOAT_OFFSET),
		(data & ADT7316_T_VALUE_FLOAT_MASK) * 25);
}

__attribute__((used)) static ssize_t adt7316_show_VDD(struct device *dev,
		struct device_attribute *attr,
		char *buf)
{
	struct iio_dev *dev_info = dev_to_iio_dev(dev);
	struct adt7316_chip_info *chip = iio_priv(dev_info);

	return adt7316_show_ad(chip, ADT7316_AD_SINGLE_CH_VDD, buf);
}

__attribute__((used)) static ssize_t adt7316_show_in_temp(struct device *dev,
		struct device_attribute *attr,
		char *buf)
{
	struct iio_dev *dev_info = dev_to_iio_dev(dev);
	struct adt7316_chip_info *chip = iio_priv(dev_info);

	return adt7316_show_ad(chip, ADT7316_AD_SINGLE_CH_IN, buf);
}

__attribute__((used)) static ssize_t adt7316_show_ex_temp_AIN1(struct device *dev,
		struct device_attribute *attr,
		char *buf)
{
	struct iio_dev *dev_info = dev_to_iio_dev(dev);
	struct adt7316_chip_info *chip = iio_priv(dev_info);

	return adt7316_show_ad(chip, ADT7316_AD_SINGLE_CH_EX, buf);
}

__attribute__((used)) static ssize_t adt7316_show_AIN2(struct device *dev,
		struct device_attribute *attr,
		char *buf)
{
	struct iio_dev *dev_info = dev_to_iio_dev(dev);
	struct adt7316_chip_info *chip = iio_priv(dev_info);

	return adt7316_show_ad(chip, ADT7516_AD_SINGLE_CH_AIN2, buf);
}

__attribute__((used)) static ssize_t adt7316_show_AIN3(struct device *dev,
		struct device_attribute *attr,
		char *buf)
{
	struct iio_dev *dev_info = dev_to_iio_dev(dev);
	struct adt7316_chip_info *chip = iio_priv(dev_info);

	return adt7316_show_ad(chip, ADT7516_AD_SINGLE_CH_AIN3, buf);
}

__attribute__((used)) static ssize_t adt7316_show_AIN4(struct device *dev,
		struct device_attribute *attr,
		char *buf)
{
	struct iio_dev *dev_info = dev_to_iio_dev(dev);
	struct adt7316_chip_info *chip = iio_priv(dev_info);

	return adt7316_show_ad(chip, ADT7516_AD_SINGLE_CH_AIN4, buf);
}

__attribute__((used)) static ssize_t adt7316_show_temp_offset(struct adt7316_chip_info *chip,
		int offset_addr, char *buf)
{
	int data;
	u8 val;
	int ret;

	ret = chip->bus.read(chip->bus.client, offset_addr, &val);
	if (ret)
		return -EIO;

	data = (int)val;
	if (val & 0x80)
		data -= 256;

	return sprintf(buf, "%d\n", data);
}

__attribute__((used)) static ssize_t adt7316_store_temp_offset(struct adt7316_chip_info *chip,
		int offset_addr, const char *buf, size_t len)
{
	int data;
	u8 val;
	int ret;

	ret = kstrtoint(buf, 10, &data);
	if (ret || data > 127 || data < -128)
		return -EINVAL;

	if (data < 0)
		data += 256;

	val = (u8)data;

	ret = chip->bus.write(chip->bus.client, offset_addr, val);
	if (ret)
		return -EIO;

	return len;
}

__attribute__((used)) static ssize_t adt7316_show_in_temp_offset(struct device *dev,
		struct device_attribute *attr,
		char *buf)
{
	struct iio_dev *dev_info = dev_to_iio_dev(dev);
	struct adt7316_chip_info *chip = iio_priv(dev_info);

	return adt7316_show_temp_offset(chip, ADT7316_IN_TEMP_OFFSET, buf);
}

__attribute__((used)) static ssize_t adt7316_store_in_temp_offset(struct device *dev,
		struct device_attribute *attr,
		const char *buf,
		size_t len)
{
	struct iio_dev *dev_info = dev_to_iio_dev(dev);
	struct adt7316_chip_info *chip = iio_priv(dev_info);

	return adt7316_store_temp_offset(chip, ADT7316_IN_TEMP_OFFSET, buf,
			len);
}

__attribute__((used)) static ssize_t adt7316_show_ex_temp_offset(struct device *dev,
		struct device_attribute *attr,
		char *buf)
{
	struct iio_dev *dev_info = dev_to_iio_dev(dev);
	struct adt7316_chip_info *chip = iio_priv(dev_info);

	return adt7316_show_temp_offset(chip, ADT7316_EX_TEMP_OFFSET, buf);
}

__attribute__((used)) static ssize_t adt7316_store_ex_temp_offset(struct device *dev,
		struct device_attribute *attr,
		const char *buf,
		size_t len)
{
	struct iio_dev *dev_info = dev_to_iio_dev(dev);
	struct adt7316_chip_info *chip = iio_priv(dev_info);

	return adt7316_store_temp_offset(chip, ADT7316_EX_TEMP_OFFSET, buf,
			len);
}

__attribute__((used)) static ssize_t adt7316_show_in_analog_temp_offset(struct device *dev,
		struct device_attribute *attr,
		char *buf)
{
	struct iio_dev *dev_info = dev_to_iio_dev(dev);
	struct adt7316_chip_info *chip = iio_priv(dev_info);

	return adt7316_show_temp_offset(chip,
			ADT7316_IN_ANALOG_TEMP_OFFSET, buf);
}

__attribute__((used)) static ssize_t adt7316_store_in_analog_temp_offset(struct device *dev,
		struct device_attribute *attr,
		const char *buf,
		size_t len)
{
	struct iio_dev *dev_info = dev_to_iio_dev(dev);
	struct adt7316_chip_info *chip = iio_priv(dev_info);

	return adt7316_store_temp_offset(chip,
			ADT7316_IN_ANALOG_TEMP_OFFSET, buf, len);
}

__attribute__((used)) static ssize_t adt7316_show_ex_analog_temp_offset(struct device *dev,
		struct device_attribute *attr,
		char *buf)
{
	struct iio_dev *dev_info = dev_to_iio_dev(dev);
	struct adt7316_chip_info *chip = iio_priv(dev_info);

	return adt7316_show_temp_offset(chip,
			ADT7316_EX_ANALOG_TEMP_OFFSET, buf);
}

__attribute__((used)) static ssize_t adt7316_store_ex_analog_temp_offset(struct device *dev,
		struct device_attribute *attr,
		const char *buf,
		size_t len)
{
	struct iio_dev *dev_info = dev_to_iio_dev(dev);
	struct adt7316_chip_info *chip = iio_priv(dev_info);

	return adt7316_store_temp_offset(chip,
			ADT7316_EX_ANALOG_TEMP_OFFSET, buf, len);
}

__attribute__((used)) static ssize_t adt7316_show_DAC(struct adt7316_chip_info *chip,
		int channel, char *buf)
{
	u16 data;
	u8 msb, lsb, offset;
	int ret;

	if (channel >= ADT7316_DA_MSB_DATA_REGS ||
		(channel == 0 &&
		(chip->config3 & ADT7316_EN_IN_TEMP_PROP_DACA)) ||
		(channel == 1 &&
		(chip->config3 & ADT7316_EN_EX_TEMP_PROP_DACB)))
		return -EPERM;

	offset = chip->dac_bits - 8;

	if (chip->dac_bits > 8) {
		ret = chip->bus.read(chip->bus.client,
			ADT7316_DA_DATA_BASE + channel * 2, &lsb);
		if (ret)
			return -EIO;
	}

	ret = chip->bus.read(chip->bus.client,
		ADT7316_DA_DATA_BASE + 1 + channel * 2, &msb);
	if (ret)
		return -EIO;

	data = (msb << offset) + (lsb & ((1 << offset) - 1));

	return sprintf(buf, "%d\n", data);
}

__attribute__((used)) static ssize_t adt7316_store_DAC(struct adt7316_chip_info *chip,
		int channel, const char *buf, size_t len)
{
	u8 msb, lsb, offset;
	u16 data;
	int ret;

	if (channel >= ADT7316_DA_MSB_DATA_REGS ||
		(channel == 0 &&
		(chip->config3 & ADT7316_EN_IN_TEMP_PROP_DACA)) ||
		(channel == 1 &&
		(chip->config3 & ADT7316_EN_EX_TEMP_PROP_DACB)))
		return -EPERM;

	offset = chip->dac_bits - 8;

	ret = kstrtou16(buf, 10, &data);
	if (ret || data >= (1 << chip->dac_bits))
		return -EINVAL;

	if (chip->dac_bits > 8) {
		lsb = data & (1 << offset);
		ret = chip->bus.write(chip->bus.client,
			ADT7316_DA_DATA_BASE + channel * 2, lsb);
		if (ret)
			return -EIO;
	}

	msb = data >> offset;
	ret = chip->bus.write(chip->bus.client,
		ADT7316_DA_DATA_BASE + 1 + channel * 2, msb);
	if (ret)
		return -EIO;

	return len;
}

__attribute__((used)) static ssize_t adt7316_show_DAC_A(struct device *dev,
		struct device_attribute *attr,
		char *buf)
{
	struct iio_dev *dev_info = dev_to_iio_dev(dev);
	struct adt7316_chip_info *chip = iio_priv(dev_info);

	return adt7316_show_DAC(chip, 0, buf);
}

__attribute__((used)) static ssize_t adt7316_store_DAC_A(struct device *dev,
		struct device_attribute *attr,
		const char *buf,
		size_t len)
{
	struct iio_dev *dev_info = dev_to_iio_dev(dev);
	struct adt7316_chip_info *chip = iio_priv(dev_info);

	return adt7316_store_DAC(chip, 0, buf, len);
}

__attribute__((used)) static ssize_t adt7316_show_DAC_B(struct device *dev,
		struct device_attribute *attr,
		char *buf)
{
	struct iio_dev *dev_info = dev_to_iio_dev(dev);
	struct adt7316_chip_info *chip = iio_priv(dev_info);

	return adt7316_show_DAC(chip, 1, buf);
}

__attribute__((used)) static ssize_t adt7316_store_DAC_B(struct device *dev,
		struct device_attribute *attr,
		const char *buf,
		size_t len)
{
	struct iio_dev *dev_info = dev_to_iio_dev(dev);
	struct adt7316_chip_info *chip = iio_priv(dev_info);

	return adt7316_store_DAC(chip, 1, buf, len);
}

__attribute__((used)) static ssize_t adt7316_show_DAC_C(struct device *dev,
		struct device_attribute *attr,
		char *buf)
{
	struct iio_dev *dev_info = dev_to_iio_dev(dev);
	struct adt7316_chip_info *chip = iio_priv(dev_info);

	return adt7316_show_DAC(chip, 2, buf);
}

__attribute__((used)) static ssize_t adt7316_store_DAC_C(struct device *dev,
		struct device_attribute *attr,
		const char *buf,
		size_t len)
{
	struct iio_dev *dev_info = dev_to_iio_dev(dev);
	struct adt7316_chip_info *chip = iio_priv(dev_info);

	return adt7316_store_DAC(chip, 2, buf, len);
}

__attribute__((used)) static ssize_t adt7316_show_DAC_D(struct device *dev,
		struct device_attribute *attr,
		char *buf)
{
	struct iio_dev *dev_info = dev_to_iio_dev(dev);
	struct adt7316_chip_info *chip = iio_priv(dev_info);

	return adt7316_show_DAC(chip, 3, buf);
}

__attribute__((used)) static ssize_t adt7316_store_DAC_D(struct device *dev,
		struct device_attribute *attr,
		const char *buf,
		size_t len)
{
	struct iio_dev *dev_info = dev_to_iio_dev(dev);
	struct adt7316_chip_info *chip = iio_priv(dev_info);

	return adt7316_store_DAC(chip, 3, buf, len);
}

__attribute__((used)) static ssize_t adt7316_show_device_id(struct device *dev,
		struct device_attribute *attr,
		char *buf)
{
	struct iio_dev *dev_info = dev_to_iio_dev(dev);
	struct adt7316_chip_info *chip = iio_priv(dev_info);
	u8 id;
	int ret;

	ret = chip->bus.read(chip->bus.client, ADT7316_DEVICE_ID, &id);
	if (ret)
		return -EIO;

	return sprintf(buf, "%d\n", id);
}

__attribute__((used)) static ssize_t adt7316_show_manufactorer_id(struct device *dev,
		struct device_attribute *attr,
		char *buf)
{
	struct iio_dev *dev_info = dev_to_iio_dev(dev);
	struct adt7316_chip_info *chip = iio_priv(dev_info);
	u8 id;
	int ret;

	ret = chip->bus.read(chip->bus.client, ADT7316_MANUFACTURE_ID, &id);
	if (ret)
		return -EIO;

	return sprintf(buf, "%d\n", id);
}

__attribute__((used)) static ssize_t adt7316_show_device_rev(struct device *dev,
		struct device_attribute *attr,
		char *buf)
{
	struct iio_dev *dev_info = dev_to_iio_dev(dev);
	struct adt7316_chip_info *chip = iio_priv(dev_info);
	u8 rev;
	int ret;

	ret = chip->bus.read(chip->bus.client, ADT7316_DEVICE_REV, &rev);
	if (ret)
		return -EIO;

	return sprintf(buf, "%d\n", rev);
}

__attribute__((used)) static ssize_t adt7316_show_bus_type(struct device *dev,
		struct device_attribute *attr,
		char *buf)
{
	struct iio_dev *dev_info = dev_to_iio_dev(dev);
	struct adt7316_chip_info *chip = iio_priv(dev_info);
	u8 stat;
	int ret;

	ret = chip->bus.read(chip->bus.client, ADT7316_SPI_LOCK_STAT, &stat);
	if (ret)
		return -EIO;

	if (stat)
		return sprintf(buf, "spi\n");

	return sprintf(buf, "i2c\n");
}

__attribute__((used)) static irqreturn_t adt7316_event_handler(int irq, void *private)
{
	struct iio_dev *indio_dev = private;
	struct adt7316_chip_info *chip = iio_priv(indio_dev);
	u8 stat1, stat2;
	int ret;
	s64 time;

	ret = chip->bus.read(chip->bus.client, ADT7316_INT_STAT1, &stat1);
	if (!ret) {
		if ((chip->id & ID_FAMILY_MASK) != ID_ADT75XX)
			stat1 &= 0x1F;

		time = iio_get_time_ns(indio_dev);
		if (stat1 & BIT(0))
			iio_push_event(indio_dev,
				       IIO_UNMOD_EVENT_CODE(IIO_TEMP, 0,
							    IIO_EV_TYPE_THRESH,
							    IIO_EV_DIR_RISING),
				       time);
		if (stat1 & BIT(1))
			iio_push_event(indio_dev,
				       IIO_UNMOD_EVENT_CODE(IIO_TEMP, 0,
							    IIO_EV_TYPE_THRESH,
							    IIO_EV_DIR_FALLING),
				       time);
		if (stat1 & BIT(2))
			iio_push_event(indio_dev,
				       IIO_UNMOD_EVENT_CODE(IIO_TEMP, 1,
							    IIO_EV_TYPE_THRESH,
							    IIO_EV_DIR_RISING),
				       time);
		if (stat1 & BIT(3))
			iio_push_event(indio_dev,
				       IIO_UNMOD_EVENT_CODE(IIO_TEMP, 1,
							    IIO_EV_TYPE_THRESH,
							    IIO_EV_DIR_FALLING),
				       time);
		if (stat1 & BIT(5))
			iio_push_event(indio_dev,
				       IIO_UNMOD_EVENT_CODE(IIO_VOLTAGE, 1,
							    IIO_EV_TYPE_THRESH,
							    IIO_EV_DIR_EITHER),
				       time);
		if (stat1 & BIT(6))
			iio_push_event(indio_dev,
				       IIO_UNMOD_EVENT_CODE(IIO_VOLTAGE, 2,
							    IIO_EV_TYPE_THRESH,
							    IIO_EV_DIR_EITHER),
				       time);
		if (stat1 & BIT(7))
			iio_push_event(indio_dev,
				       IIO_UNMOD_EVENT_CODE(IIO_VOLTAGE, 3,
							    IIO_EV_TYPE_THRESH,
							    IIO_EV_DIR_EITHER),
				       time);
		}
	ret = chip->bus.read(chip->bus.client, ADT7316_INT_STAT2, &stat2);
	if (!ret) {
		if (stat2 & ADT7316_INT_MASK2_VDD)
			iio_push_event(indio_dev,
				       IIO_UNMOD_EVENT_CODE(IIO_VOLTAGE,
							    0,
							    IIO_EV_TYPE_THRESH,
							    IIO_EV_DIR_RISING),
				       iio_get_time_ns(indio_dev));
	}

	return IRQ_HANDLED;
}

__attribute__((used)) static ssize_t adt7316_show_int_mask(struct device *dev,
		struct device_attribute *attr,
		char *buf)
{
	struct iio_dev *dev_info = dev_to_iio_dev(dev);
	struct adt7316_chip_info *chip = iio_priv(dev_info);

	return sprintf(buf, "0x%x\n", chip->int_mask);
}

__attribute__((used)) static ssize_t adt7316_set_int_mask(struct device *dev,
		struct device_attribute *attr,
		const char *buf,
		size_t len)
{
	struct iio_dev *dev_info = dev_to_iio_dev(dev);
	struct adt7316_chip_info *chip = iio_priv(dev_info);
	u16 data;
	int ret;
	u8 mask;

	ret = kstrtou16(buf, 16, &data);
	if (ret || data >= ADT7316_VDD_INT_MASK + 1)
		return -EINVAL;

	if (data & ADT7316_VDD_INT_MASK)
		mask = 0;			/* enable vdd int */
	else
		mask = ADT7316_INT_MASK2_VDD;	/* disable vdd int */

	ret = chip->bus.write(chip->bus.client, ADT7316_INT_MASK2, mask);
	if (!ret) {
		chip->int_mask &= ~ADT7316_VDD_INT_MASK;
		chip->int_mask |= data & ADT7316_VDD_INT_MASK;
	}

	if (data & ADT7316_TEMP_AIN_INT_MASK) {
		if ((chip->id & ID_FAMILY_MASK) == ID_ADT73XX)
			/* mask in reg is opposite, set 1 to disable */
			mask = (~data) & ADT7316_TEMP_INT_MASK;
		else
			/* mask in reg is opposite, set 1 to disable */
			mask = (~data) & ADT7316_TEMP_AIN_INT_MASK;
	}
	ret = chip->bus.write(chip->bus.client, ADT7316_INT_MASK1, mask);

	chip->int_mask = mask;

	return len;
}

__attribute__((used)) static inline ssize_t adt7316_show_ad_bound(struct device *dev,
		struct device_attribute *attr,
		char *buf)
{
	struct iio_dev_attr *this_attr = to_iio_dev_attr(attr);
	struct iio_dev *dev_info = dev_to_iio_dev(dev);
	struct adt7316_chip_info *chip = iio_priv(dev_info);
	u8 val;
	int data;
	int ret;

	if ((chip->id & ID_FAMILY_MASK) == ID_ADT73XX &&
		this_attr->address > ADT7316_EX_TEMP_LOW)
		return -EPERM;

	ret = chip->bus.read(chip->bus.client, this_attr->address, &val);
	if (ret)
		return -EIO;

	data = (int)val;

	if (!((chip->id & ID_FAMILY_MASK) == ID_ADT75XX &&
		(chip->config1 & ADT7516_SEL_AIN1_2_EX_TEMP_MASK) == 0)) {
		if (data & 0x80)
			data -= 256;
	}

	return sprintf(buf, "%d\n", data);
}

__attribute__((used)) static inline ssize_t adt7316_set_ad_bound(struct device *dev,
		struct device_attribute *attr,
		const char *buf,
		size_t len)
{
	struct iio_dev_attr *this_attr = to_iio_dev_attr(attr);
	struct iio_dev *dev_info = dev_to_iio_dev(dev);
	struct adt7316_chip_info *chip = iio_priv(dev_info);
	int data;
	u8 val;
	int ret;

	if ((chip->id & ID_FAMILY_MASK) == ID_ADT73XX &&
		this_attr->address > ADT7316_EX_TEMP_LOW)
		return -EPERM;

	ret = kstrtoint(buf, 10, &data);
	if (ret)
		return -EINVAL;

	if ((chip->id & ID_FAMILY_MASK) == ID_ADT75XX &&
		(chip->config1 & ADT7516_SEL_AIN1_2_EX_TEMP_MASK) == 0) {
		if (data > 255 || data < 0)
			return -EINVAL;
	} else {
		if (data > 127 || data < -128)
			return -EINVAL;

		if (data < 0)
			data += 256;
	}

	val = (u8)data;

	ret = chip->bus.write(chip->bus.client, this_attr->address, val);
	if (ret)
		return -EIO;

	return len;
}

__attribute__((used)) static ssize_t adt7316_show_int_enabled(struct device *dev,
		struct device_attribute *attr,
		char *buf)
{
	struct iio_dev *dev_info = dev_to_iio_dev(dev);
	struct adt7316_chip_info *chip = iio_priv(dev_info);

	return sprintf(buf, "%d\n", !!(chip->config1 & ADT7316_INT_EN));
}

__attribute__((used)) static ssize_t adt7316_set_int_enabled(struct device *dev,
		struct device_attribute *attr,
		const char *buf,
		size_t len)
{
	struct iio_dev *dev_info = dev_to_iio_dev(dev);
	struct adt7316_chip_info *chip = iio_priv(dev_info);
	u8 config1;
	int ret;

	config1 = chip->config1 & (~ADT7316_INT_EN);
	if (buf[0] == '1')
		config1 |= ADT7316_INT_EN;

	ret = chip->bus.write(chip->bus.client, ADT7316_CONFIG1, config1);
	if (ret)
		return -EIO;

	chip->config1 = config1;

	return len;
}

int adt7316_probe(struct device *dev, struct adt7316_bus *bus,
		const char *name)
{
	struct adt7316_chip_info *chip;
	struct iio_dev *indio_dev;
	unsigned short *adt7316_platform_data = dev->platform_data;
	int ret = 0;

	indio_dev = devm_iio_device_alloc(dev, sizeof(*chip));
	if (!indio_dev)
		return -ENOMEM;
	chip = iio_priv(indio_dev);
	/* this is only used for device removal purposes */
	dev_set_drvdata(dev, indio_dev);

	chip->bus = *bus;

	if (name[4] == '3')
		chip->id = ID_ADT7316 + (name[6] - '6');
	else if (name[4] == '5')
		chip->id = ID_ADT7516 + (name[6] - '6');
	else
		return -ENODEV;

	chip->ldac_pin = adt7316_platform_data[1];
	if (chip->ldac_pin) {
		chip->config3 |= ADT7316_DA_EN_VIA_DAC_LDCA;
		if ((chip->id & ID_FAMILY_MASK) == ID_ADT75XX)
			chip->config1 |= ADT7516_SEL_AIN3;
	}
	chip->int_mask = ADT7316_TEMP_INT_MASK | ADT7316_VDD_INT_MASK;
	if ((chip->id & ID_FAMILY_MASK) == ID_ADT75XX)
		chip->int_mask |= ADT7516_AIN_INT_MASK;

	indio_dev->dev.parent = dev;
	if ((chip->id & ID_FAMILY_MASK) == ID_ADT75XX)
		indio_dev->info = &adt7516_info;
	else
		indio_dev->info = &adt7316_info;
	indio_dev->name = name;
	indio_dev->modes = INDIO_DIRECT_MODE;

	if (chip->bus.irq > 0) {
		if (adt7316_platform_data[0])
			chip->bus.irq_flags = adt7316_platform_data[0];

		ret = devm_request_threaded_irq(dev, chip->bus.irq,
						NULL,
						adt7316_event_handler,
						chip->bus.irq_flags |
						IRQF_ONESHOT,
						indio_dev->name,
						indio_dev);
		if (ret)
			return ret;

		if (chip->bus.irq_flags & IRQF_TRIGGER_HIGH)
			chip->config1 |= ADT7316_INT_POLARITY;
	}

	ret = chip->bus.write(chip->bus.client, ADT7316_CONFIG1, chip->config1);
	if (ret)
		return -EIO;

	ret = chip->bus.write(chip->bus.client, ADT7316_CONFIG3, chip->config3);
	if (ret)
		return -EIO;

	ret = devm_iio_device_register(dev, indio_dev);
	if (ret)
		return ret;

	dev_info(dev, "%s temperature sensor, ADC and DAC registered.\n",
			indio_dev->name);

	return 0;
}

