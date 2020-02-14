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
typedef  int u32 ;
typedef  int u16 ;
struct pmbus_driver_info {int pages; int /*<<< orphan*/ * func; } ;
struct i2c_msg {int len; unsigned char* buf; int /*<<< orphan*/  flags; int /*<<< orphan*/  addr; } ;
struct i2c_device_id {int /*<<< orphan*/  name; } ;
struct device {int dummy; } ;
struct i2c_client {int /*<<< orphan*/  adapter; struct device dev; int /*<<< orphan*/  addr; } ;
typedef  int s64 ;
typedef  int /*<<< orphan*/  rspbuf ;
typedef  int /*<<< orphan*/  cmdbuf ;

/* Variables and functions */
 int /*<<< orphan*/  ARRAY_SIZE (struct i2c_msg*) ; 
 int EINVAL ; 
 int ENODATA ; 
 int ENODEV ; 
 int ENOMEM ; 
 int ENOTSUPP ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int I2C_FUNC_SMBUS_BYTE_DATA ; 
 int I2C_FUNC_SMBUS_WORD_DATA ; 
 int /*<<< orphan*/  I2C_M_RD ; 
 int MAX31785 ; 
 int MAX31785A ; 
 int MAX31785_NR_FAN_PAGES ; 
 int MAX31785_NR_PAGES ; 
 int /*<<< orphan*/  MFR_FAN_CONFIG ; 
 int MFR_FAN_CONFIG_DUAL_TACH ; 
 int /*<<< orphan*/  MFR_REVISION ; 
 int PB_FAN_1_RPM ; 
#define  PMBUS_FAN_COMMAND_1 133 
#define  PMBUS_FAN_CONFIG_12 132 
 int /*<<< orphan*/  PMBUS_HAVE_FAN12 ; 
 int /*<<< orphan*/  PMBUS_PAGE ; 
 int /*<<< orphan*/  PMBUS_PAGE_VIRTUAL ; 
#define  PMBUS_READ_FAN_SPEED_1 131 
#define  PMBUS_VIRT_PWM_1 130 
#define  PMBUS_VIRT_PWM_ENABLE_1 129 
#define  PMBUS_VOUT_MODE 128 
 int /*<<< orphan*/  dev_warn (struct device*,char*) ; 
 struct pmbus_driver_info* devm_kzalloc (struct device*,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  i2c_check_functionality (int /*<<< orphan*/ ,int) ; 
 int i2c_smbus_read_word_data (struct i2c_client*,int /*<<< orphan*/ ) ; 
 int i2c_smbus_write_byte_data (struct i2c_client*,int /*<<< orphan*/ ,int) ; 
 int i2c_transfer (int /*<<< orphan*/ ,struct i2c_msg*,int /*<<< orphan*/ ) ; 
 struct pmbus_driver_info max31785_info ; 
 int /*<<< orphan*/  percent ; 
 int pmbus_do_probe (struct i2c_client*,struct i2c_device_id const*,struct pmbus_driver_info*) ; 
 int pmbus_get_fan_rate_cached (struct i2c_client*,int,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int pmbus_get_fan_rate_device (struct i2c_client*,int,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int pmbus_read_byte_data (struct i2c_client*,int,int const) ; 
 int pmbus_read_word_data (struct i2c_client*,int,int) ; 
 int pmbus_set_page (struct i2c_client*,int) ; 
 int pmbus_update_fan (struct i2c_client*,int,int /*<<< orphan*/ ,int,int,int) ; 
 int /*<<< orphan*/  rpm ; 
 int /*<<< orphan*/  strcmp (char*,int /*<<< orphan*/ ) ; 

__attribute__((used)) static int max31785_read_byte_data(struct i2c_client *client, int page,
				   int reg)
{
	if (page < MAX31785_NR_PAGES)
		return -ENODATA;

	switch (reg) {
	case PMBUS_VOUT_MODE:
		return -ENOTSUPP;
	case PMBUS_FAN_CONFIG_12:
		return pmbus_read_byte_data(client, page - MAX31785_NR_PAGES,
					    reg);
	}

	return -ENODATA;
}

__attribute__((used)) static int max31785_write_byte(struct i2c_client *client, int page, u8 value)
{
	if (page < MAX31785_NR_PAGES)
		return -ENODATA;

	return -ENOTSUPP;
}

__attribute__((used)) static int max31785_read_long_data(struct i2c_client *client, int page,
				   int reg, u32 *data)
{
	unsigned char cmdbuf[1];
	unsigned char rspbuf[4];
	int rc;

	struct i2c_msg msg[2] = {
		{
			.addr = client->addr,
			.flags = 0,
			.len = sizeof(cmdbuf),
			.buf = cmdbuf,
		},
		{
			.addr = client->addr,
			.flags = I2C_M_RD,
			.len = sizeof(rspbuf),
			.buf = rspbuf,
		},
	};

	cmdbuf[0] = reg;

	rc = pmbus_set_page(client, page);
	if (rc < 0)
		return rc;

	rc = i2c_transfer(client->adapter, msg, ARRAY_SIZE(msg));
	if (rc < 0)
		return rc;

	*data = (rspbuf[0] << (0 * 8)) | (rspbuf[1] << (1 * 8)) |
		(rspbuf[2] << (2 * 8)) | (rspbuf[3] << (3 * 8));

	return rc;
}

__attribute__((used)) static int max31785_get_pwm(struct i2c_client *client, int page)
{
	int rv;

	rv = pmbus_get_fan_rate_device(client, page, 0, percent);
	if (rv < 0)
		return rv;
	else if (rv >= 0x8000)
		return 0;
	else if (rv >= 0x2711)
		return 0x2710;

	return rv;
}

__attribute__((used)) static int max31785_get_pwm_mode(struct i2c_client *client, int page)
{
	int config;
	int command;

	config = pmbus_read_byte_data(client, page, PMBUS_FAN_CONFIG_12);
	if (config < 0)
		return config;

	command = pmbus_read_word_data(client, page, PMBUS_FAN_COMMAND_1);
	if (command < 0)
		return command;

	if (config & PB_FAN_1_RPM)
		return (command >= 0x8000) ? 3 : 2;

	if (command >= 0x8000)
		return 3;
	else if (command >= 0x2711)
		return 0;

	return 1;
}

__attribute__((used)) static int max31785_read_word_data(struct i2c_client *client, int page,
				   int reg)
{
	u32 val;
	int rv;

	switch (reg) {
	case PMBUS_READ_FAN_SPEED_1:
		if (page < MAX31785_NR_PAGES)
			return -ENODATA;

		rv = max31785_read_long_data(client, page - MAX31785_NR_PAGES,
					     reg, &val);
		if (rv < 0)
			return rv;

		rv = (val >> 16) & 0xffff;
		break;
	case PMBUS_FAN_COMMAND_1:
		/*
		 * PMBUS_FAN_COMMAND_x is probed to judge whether or not to
		 * expose fan control registers.
		 *
		 * Don't expose fan_target attribute for virtual pages.
		 */
		rv = (page >= MAX31785_NR_PAGES) ? -ENOTSUPP : -ENODATA;
		break;
	case PMBUS_VIRT_PWM_1:
		rv = max31785_get_pwm(client, page);
		break;
	case PMBUS_VIRT_PWM_ENABLE_1:
		rv = max31785_get_pwm_mode(client, page);
		break;
	default:
		rv = -ENODATA;
		break;
	}

	return rv;
}

__attribute__((used)) static inline u32 max31785_scale_pwm(u32 sensor_val)
{
	/*
	 * The datasheet describes the accepted value range for manual PWM as
	 * [0, 0x2710], while the hwmon pwmX sysfs interface accepts values in
	 * [0, 255]. The MAX31785 uses DIRECT mode to scale the FAN_COMMAND
	 * registers and in PWM mode the coefficients are m=1, b=0, R=2. The
	 * important observation here is that 0x2710 == 10000 == 100 * 100.
	 *
	 * R=2 (== 10^2 == 100) accounts for scaling the value provided at the
	 * sysfs interface into the required hardware resolution, but it does
	 * not yet yield a value that we can write to the device (this initial
	 * scaling is handled by pmbus_data2reg()). Multiplying by 100 below
	 * translates the parameter value into the percentage units required by
	 * PMBus, and then we scale back by 255 as required by the hwmon pwmX
	 * interface to yield the percentage value at the appropriate
	 * resolution for hardware.
	 */
	return (sensor_val * 100) / 255;
}

__attribute__((used)) static int max31785_pwm_enable(struct i2c_client *client, int page,
				    u16 word)
{
	int config = 0;
	int rate;

	switch (word) {
	case 0:
		rate = 0x7fff;
		break;
	case 1:
		rate = pmbus_get_fan_rate_cached(client, page, 0, percent);
		if (rate < 0)
			return rate;
		rate = max31785_scale_pwm(rate);
		break;
	case 2:
		config = PB_FAN_1_RPM;
		rate = pmbus_get_fan_rate_cached(client, page, 0, rpm);
		if (rate < 0)
			return rate;
		break;
	case 3:
		rate = 0xffff;
		break;
	default:
		return -EINVAL;
	}

	return pmbus_update_fan(client, page, 0, config, PB_FAN_1_RPM, rate);
}

__attribute__((used)) static int max31785_write_word_data(struct i2c_client *client, int page,
				    int reg, u16 word)
{
	switch (reg) {
	case PMBUS_VIRT_PWM_1:
		return pmbus_update_fan(client, page, 0, 0, PB_FAN_1_RPM,
					max31785_scale_pwm(word));
	case PMBUS_VIRT_PWM_ENABLE_1:
		return max31785_pwm_enable(client, page, word);
	default:
		break;
	}

	return -ENODATA;
}

__attribute__((used)) static int max31785_configure_dual_tach(struct i2c_client *client,
					struct pmbus_driver_info *info)
{
	int ret;
	int i;

	for (i = 0; i < MAX31785_NR_FAN_PAGES; i++) {
		ret = i2c_smbus_write_byte_data(client, PMBUS_PAGE, i);
		if (ret < 0)
			return ret;

		ret = i2c_smbus_read_word_data(client, MFR_FAN_CONFIG);
		if (ret < 0)
			return ret;

		if (ret & MFR_FAN_CONFIG_DUAL_TACH) {
			int virtual = MAX31785_NR_PAGES + i;

			info->pages = virtual + 1;
			info->func[virtual] |= PMBUS_HAVE_FAN12;
			info->func[virtual] |= PMBUS_PAGE_VIRTUAL;
		}
	}

	return 0;
}

__attribute__((used)) static int max31785_probe(struct i2c_client *client,
			  const struct i2c_device_id *id)
{
	struct device *dev = &client->dev;
	struct pmbus_driver_info *info;
	bool dual_tach = false;
	s64 ret;

	if (!i2c_check_functionality(client->adapter,
				     I2C_FUNC_SMBUS_BYTE_DATA |
				     I2C_FUNC_SMBUS_WORD_DATA))
		return -ENODEV;

	info = devm_kzalloc(dev, sizeof(struct pmbus_driver_info), GFP_KERNEL);
	if (!info)
		return -ENOMEM;

	*info = max31785_info;

	ret = i2c_smbus_write_byte_data(client, PMBUS_PAGE, 255);
	if (ret < 0)
		return ret;

	ret = i2c_smbus_read_word_data(client, MFR_REVISION);
	if (ret < 0)
		return ret;

	if (ret == MAX31785A) {
		dual_tach = true;
	} else if (ret == MAX31785) {
		if (!strcmp("max31785a", id->name))
			dev_warn(dev, "Expected max3175a, found max31785: cannot provide secondary tachometer readings\n");
	} else {
		return -ENODEV;
	}

	if (dual_tach) {
		ret = max31785_configure_dual_tach(client, info);
		if (ret < 0)
			return ret;
	}

	return pmbus_do_probe(client, id, info);
}

