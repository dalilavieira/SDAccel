#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_5__   TYPE_3__ ;
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
typedef  int u8 ;
struct led_classdev {int dummy; } ;
struct i2c_device_id {int dummy; } ;
struct device {int /*<<< orphan*/  kobj; } ;
struct i2c_client {int addr; struct device dev; struct i2c_adapter* adapter; } ;
struct i2c_board_info {int /*<<< orphan*/  type; } ;
struct i2c_adapter {int nr; } ;
struct device_attribute {int dummy; } ;
struct TYPE_4__ {int max_brightness; char* name; int (* brightness_set_blocking ) (struct led_classdev*,int) ;int /*<<< orphan*/  flags; } ;
struct blinkm_led {int id; TYPE_1__ led_cdev; struct i2c_client* i2c_client; } ;
struct blinkm_data {int red; int green; int blue; int next_red; int next_green; int next_blue; int* args; int next_hue; int next_saturation; int next_brightness; int hue; int saturation; int brightness; int script_id; int script_repeats; int script_startline; int i2c_addr; int fw_ver; struct blinkm_led* blinkm_leds; int /*<<< orphan*/  update_lock; struct i2c_client* i2c_client; } ;
typedef  int ssize_t ;
typedef  enum led_brightness { ____Placeholder_led_brightness } led_brightness ;
typedef  int /*<<< orphan*/  blinkm_led_name ;
struct TYPE_5__ {int nr_args; int cmdbyte; int nr_ret; } ;

/* Variables and functions */
#define  BLM_FADE_HSB 147 
#define  BLM_FADE_RAND_HSB 146 
#define  BLM_FADE_RAND_RGB 145 
#define  BLM_FADE_RGB 144 
#define  BLM_GET_ADDR 143 
#define  BLM_GET_CUR_RGB 142 
#define  BLM_GET_FW_VER 141 
#define  BLM_GO_RGB 140 
#define  BLM_PLAY_SCRIPT 139 
#define  BLM_READ_SCRIPT_LINE 138 
#define  BLM_SET_ADDR 137 
#define  BLM_SET_FADE_SPEED 136 
#define  BLM_SET_SCRIPT_LR 135 
#define  BLM_SET_STARTUP_PARAM 134 
#define  BLM_SET_TIME_ADJ 133 
#define  BLM_STOP_SCRIPT 132 
#define  BLM_WRITE_SCRIPT_LINE 131 
#define  BLUE 130 
 int EAGAIN ; 
 int EINVAL ; 
 int ENODEV ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
#define  GREEN 129 
 int I2C_FUNC_SMBUS_BYTE_DATA ; 
 int I2C_FUNC_SMBUS_WORD_DATA ; 
 int I2C_FUNC_SMBUS_WRITE_BYTE ; 
 int /*<<< orphan*/  I2C_NAME_SIZE ; 
 int /*<<< orphan*/  LED_CORE_SUSPENDRESUME ; 
 int /*<<< orphan*/  PAGE_SIZE ; 
#define  RED 128 
 TYPE_3__* blinkm_cmds ; 
 int /*<<< orphan*/  blinkm_group ; 
static  int blinkm_test_run (struct i2c_client*) ; 
static  int blinkm_transfer_hw (struct i2c_client*,int const) ; 
 struct blinkm_led* cdev_to_blmled (struct led_classdev*) ; 
 int /*<<< orphan*/  dev_dbg (struct device*,char*,int,int,int) ; 
 int /*<<< orphan*/  dev_err (struct device*,char*,...) ; 
 struct blinkm_data* devm_kzalloc (struct device*,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  i2c_check_functionality (struct i2c_adapter*,int) ; 
 struct blinkm_data* i2c_get_clientdata (struct i2c_client*) ; 
 int /*<<< orphan*/  i2c_set_clientdata (struct i2c_client*,struct blinkm_data*) ; 
 int i2c_smbus_read_byte (struct i2c_client*) ; 
 int i2c_smbus_write_byte (struct i2c_client*,int) ; 
 int kstrtou8 (char const*,int,int*) ; 
 int led_classdev_register (struct device*,TYPE_1__*) ; 
 int /*<<< orphan*/  led_classdev_unregister (TYPE_1__*) ; 
 int /*<<< orphan*/  msleep (int) ; 
 int /*<<< orphan*/  mutex_init (int /*<<< orphan*/ *) ; 
 scalar_t__ mutex_lock_interruptible (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 int scnprintf (char*,int /*<<< orphan*/ ,char*,...) ; 
 int /*<<< orphan*/  snprintf (char*,int,char*,int,int) ; 
 int /*<<< orphan*/  strlcpy (int /*<<< orphan*/ ,char*,int /*<<< orphan*/ ) ; 
 int sysfs_create_group (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  sysfs_remove_group (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 struct i2c_client* to_i2c_client (struct device*) ; 
 int /*<<< orphan*/  usleep_range (int,int) ; 

__attribute__((used)) static ssize_t show_color_common(struct device *dev, char *buf, int color)
{
	struct i2c_client *client;
	struct blinkm_data *data;
	int ret;

	client = to_i2c_client(dev);
	data = i2c_get_clientdata(client);

	ret = blinkm_transfer_hw(client, BLM_GET_CUR_RGB);
	if (ret < 0)
		return ret;
	switch (color) {
	case RED:
		return scnprintf(buf, PAGE_SIZE, "%02X\n", data->red);
	case GREEN:
		return scnprintf(buf, PAGE_SIZE, "%02X\n", data->green);
	case BLUE:
		return scnprintf(buf, PAGE_SIZE, "%02X\n", data->blue);
	default:
		return -EINVAL;
	}
	return -EINVAL;
}

__attribute__((used)) static int store_color_common(struct device *dev, const char *buf, int color)
{
	struct i2c_client *client;
	struct blinkm_data *data;
	int ret;
	u8 value;

	client = to_i2c_client(dev);
	data = i2c_get_clientdata(client);

	ret = kstrtou8(buf, 10, &value);
	if (ret < 0) {
		dev_err(dev, "BlinkM: value too large!\n");
		return ret;
	}

	switch (color) {
	case RED:
		data->next_red = value;
		break;
	case GREEN:
		data->next_green = value;
		break;
	case BLUE:
		data->next_blue = value;
		break;
	default:
		return -EINVAL;
	}

	dev_dbg(dev, "next_red = %d, next_green = %d, next_blue = %d\n",
			data->next_red, data->next_green, data->next_blue);

	/* if mode ... */
	ret = blinkm_transfer_hw(client, BLM_GO_RGB);
	if (ret < 0) {
		dev_err(dev, "BlinkM: can't set RGB\n");
		return ret;
	}
	return 0;
}

__attribute__((used)) static ssize_t show_red(struct device *dev, struct device_attribute *attr,
			char *buf)
{
	return show_color_common(dev, buf, RED);
}

__attribute__((used)) static ssize_t store_red(struct device *dev, struct device_attribute *attr,
			 const char *buf, size_t count)
{
	int ret;

	ret = store_color_common(dev, buf, RED);
	if (ret < 0)
		return ret;
	return count;
}

__attribute__((used)) static ssize_t show_green(struct device *dev, struct device_attribute *attr,
			  char *buf)
{
	return show_color_common(dev, buf, GREEN);
}

__attribute__((used)) static ssize_t store_green(struct device *dev, struct device_attribute *attr,
			   const char *buf, size_t count)
{

	int ret;

	ret = store_color_common(dev, buf, GREEN);
	if (ret < 0)
		return ret;
	return count;
}

__attribute__((used)) static ssize_t show_blue(struct device *dev, struct device_attribute *attr,
			 char *buf)
{
	return show_color_common(dev, buf, BLUE);
}

__attribute__((used)) static ssize_t store_blue(struct device *dev, struct device_attribute *attr,
			  const char *buf, size_t count)
{
	int ret;

	ret = store_color_common(dev, buf, BLUE);
	if (ret < 0)
		return ret;
	return count;
}

__attribute__((used)) static ssize_t show_test(struct device *dev, struct device_attribute *attr,
			 char *buf)
{
	return scnprintf(buf, PAGE_SIZE,
			 "#Write into test to start test sequence!#\n");
}

__attribute__((used)) static ssize_t store_test(struct device *dev, struct device_attribute *attr,
			  const char *buf, size_t count)
{

	struct i2c_client *client;
	int ret;
	client = to_i2c_client(dev);

	/*test */
	ret = blinkm_test_run(client);
	if (ret < 0)
		return ret;

	return count;
}

__attribute__((used)) static int blinkm_write(struct i2c_client *client, int cmd, u8 *arg)
{
	int result;
	int i;
	int arglen = blinkm_cmds[cmd].nr_args;
	/* write out cmd to blinkm - always / default step */
	result = i2c_smbus_write_byte(client, blinkm_cmds[cmd].cmdbyte);
	if (result < 0)
		return result;
	/* no args to write out */
	if (arglen == 0)
		return 0;

	for (i = 0; i < arglen; i++) {
		/* repeat for arglen */
		result = i2c_smbus_write_byte(client, arg[i]);
		if (result < 0)
			return result;
	}
	return 0;
}

__attribute__((used)) static int blinkm_read(struct i2c_client *client, int cmd, u8 *arg)
{
	int result;
	int i;
	int retlen = blinkm_cmds[cmd].nr_ret;
	for (i = 0; i < retlen; i++) {
		/* repeat for retlen */
		result = i2c_smbus_read_byte(client);
		if (result < 0)
			return result;
		arg[i] = result;
	}

	return 0;
}

__attribute__((used)) static int blinkm_transfer_hw(struct i2c_client *client, int cmd)
{
	/* the protocol is simple but non-standard:
	 * e.g.  cmd 'g' (= 0x67) for "get device address"
	 * - which defaults to 0x09 - would be the sequence:
	 *   a) write 0x67 to the device (byte write)
	 *   b) read the value (0x09) back right after (byte read)
	 *
	 * Watch out for "unfinished" sequences (i.e. not enough reads
	 * or writes after a command. It will make the blinkM misbehave.
	 * Sequence is key here.
	 */

	/* args / return are in private data struct */
	struct blinkm_data *data = i2c_get_clientdata(client);

	/* We start hardware transfers which are not to be
	 * mixed with other commands. Aquire a lock now. */
	if (mutex_lock_interruptible(&data->update_lock) < 0)
		return -EAGAIN;

	/* switch cmd - usually write before reads */
	switch (cmd) {
	case BLM_FADE_RAND_RGB:
	case BLM_GO_RGB:
	case BLM_FADE_RGB:
		data->args[0] = data->next_red;
		data->args[1] = data->next_green;
		data->args[2] = data->next_blue;
		blinkm_write(client, cmd, data->args);
		data->red = data->args[0];
		data->green = data->args[1];
		data->blue = data->args[2];
		break;
	case BLM_FADE_HSB:
	case BLM_FADE_RAND_HSB:
		data->args[0] = data->next_hue;
		data->args[1] = data->next_saturation;
		data->args[2] = data->next_brightness;
		blinkm_write(client, cmd, data->args);
		data->hue = data->next_hue;
		data->saturation = data->next_saturation;
		data->brightness = data->next_brightness;
		break;
	case BLM_PLAY_SCRIPT:
		data->args[0] = data->script_id;
		data->args[1] = data->script_repeats;
		data->args[2] = data->script_startline;
		blinkm_write(client, cmd, data->args);
		break;
	case BLM_STOP_SCRIPT:
		blinkm_write(client, cmd, NULL);
		break;
	case BLM_GET_CUR_RGB:
		data->args[0] = data->red;
		data->args[1] = data->green;
		data->args[2] = data->blue;
		blinkm_write(client, cmd, NULL);
		blinkm_read(client, cmd, data->args);
		data->red = data->args[0];
		data->green = data->args[1];
		data->blue = data->args[2];
		break;
	case BLM_GET_ADDR:
		data->args[0] = data->i2c_addr;
		blinkm_write(client, cmd, NULL);
		blinkm_read(client, cmd, data->args);
		data->i2c_addr = data->args[0];
		break;
	case BLM_SET_TIME_ADJ:
	case BLM_SET_FADE_SPEED:
	case BLM_READ_SCRIPT_LINE:
	case BLM_WRITE_SCRIPT_LINE:
	case BLM_SET_SCRIPT_LR:
	case BLM_SET_ADDR:
	case BLM_GET_FW_VER:
	case BLM_SET_STARTUP_PARAM:
		dev_err(&client->dev,
				"BlinkM: cmd %d not implemented yet.\n", cmd);
		break;
	default:
		dev_err(&client->dev, "BlinkM: unknown command %d\n", cmd);
		mutex_unlock(&data->update_lock);
		return -EINVAL;
	}			/* end switch(cmd) */

	/* transfers done, unlock */
	mutex_unlock(&data->update_lock);
	return 0;
}

__attribute__((used)) static int blinkm_led_common_set(struct led_classdev *led_cdev,
				 enum led_brightness value, int color)
{
	/* led_brightness is 0, 127 or 255 - we just use it here as-is */
	struct blinkm_led *led = cdev_to_blmled(led_cdev);
	struct blinkm_data *data = i2c_get_clientdata(led->i2c_client);

	switch (color) {
	case RED:
		/* bail out if there's no change */
		if (data->next_red == (u8) value)
			return 0;
		data->next_red = (u8) value;
		break;
	case GREEN:
		/* bail out if there's no change */
		if (data->next_green == (u8) value)
			return 0;
		data->next_green = (u8) value;
		break;
	case BLUE:
		/* bail out if there's no change */
		if (data->next_blue == (u8) value)
			return 0;
		data->next_blue = (u8) value;
		break;

	default:
		dev_err(&led->i2c_client->dev, "BlinkM: unknown color.\n");
		return -EINVAL;
	}

	blinkm_transfer_hw(led->i2c_client, BLM_GO_RGB);
	dev_dbg(&led->i2c_client->dev,
			"# DONE # next_red = %d, next_green = %d,"
			" next_blue = %d\n",
			data->next_red, data->next_green,
			data->next_blue);
	return 0;
}

__attribute__((used)) static int blinkm_led_red_set(struct led_classdev *led_cdev,
			       enum led_brightness value)
{
	return blinkm_led_common_set(led_cdev, value, RED);
}

__attribute__((used)) static int blinkm_led_green_set(struct led_classdev *led_cdev,
				 enum led_brightness value)
{
	return blinkm_led_common_set(led_cdev, value, GREEN);
}

__attribute__((used)) static int blinkm_led_blue_set(struct led_classdev *led_cdev,
				enum led_brightness value)
{
	return blinkm_led_common_set(led_cdev, value, BLUE);
}

__attribute__((used)) static void blinkm_init_hw(struct i2c_client *client)
{
	int ret;
	ret = blinkm_transfer_hw(client, BLM_STOP_SCRIPT);
	ret = blinkm_transfer_hw(client, BLM_GO_RGB);
}

__attribute__((used)) static int blinkm_test_run(struct i2c_client *client)
{
	int ret;
	struct blinkm_data *data = i2c_get_clientdata(client);

	data->next_red = 0x01;
	data->next_green = 0x05;
	data->next_blue = 0x10;
	ret = blinkm_transfer_hw(client, BLM_GO_RGB);
	if (ret < 0)
		return ret;
	msleep(2000);

	data->next_red = 0x25;
	data->next_green = 0x10;
	data->next_blue = 0x31;
	ret = blinkm_transfer_hw(client, BLM_FADE_RGB);
	if (ret < 0)
		return ret;
	msleep(2000);

	data->next_hue = 0x50;
	data->next_saturation = 0x10;
	data->next_brightness = 0x20;
	ret = blinkm_transfer_hw(client, BLM_FADE_HSB);
	if (ret < 0)
		return ret;
	msleep(2000);

	return 0;
}

__attribute__((used)) static int blinkm_detect(struct i2c_client *client, struct i2c_board_info *info)
{
	struct i2c_adapter *adapter = client->adapter;
	int ret;
	int count = 99;
	u8 tmpargs[7];

	if (!i2c_check_functionality(adapter, I2C_FUNC_SMBUS_BYTE_DATA
				     | I2C_FUNC_SMBUS_WORD_DATA
				     | I2C_FUNC_SMBUS_WRITE_BYTE))
		return -ENODEV;

	/* Now, we do the remaining detection. Simple for now. */
	/* We might need more guards to protect other i2c slaves */

	/* make sure the blinkM is balanced (read/writes) */
	while (count > 0) {
		ret = blinkm_write(client, BLM_GET_ADDR, NULL);
		if (ret)
			return ret;
		usleep_range(5000, 10000);
		ret = blinkm_read(client, BLM_GET_ADDR, tmpargs);
		if (ret)
			return ret;
		usleep_range(5000, 10000);
		if (tmpargs[0] == 0x09)
			count = 0;
		count--;
	}

	/* Step 1: Read BlinkM address back  -  cmd_char 'a' */
	ret = blinkm_write(client, BLM_GET_ADDR, NULL);
	if (ret < 0)
		return ret;
	usleep_range(20000, 30000);	/* allow a small delay */
	ret = blinkm_read(client, BLM_GET_ADDR, tmpargs);
	if (ret < 0)
		return ret;

	if (tmpargs[0] != 0x09) {
		dev_err(&client->dev, "enodev DEV ADDR = 0x%02X\n", tmpargs[0]);
		return -ENODEV;
	}

	strlcpy(info->type, "blinkm", I2C_NAME_SIZE);
	return 0;
}

__attribute__((used)) static int blinkm_probe(struct i2c_client *client,
			const struct i2c_device_id *id)
{
	struct blinkm_data *data;
	struct blinkm_led *led[3];
	int err, i;
	char blinkm_led_name[28];

	data = devm_kzalloc(&client->dev,
			sizeof(struct blinkm_data), GFP_KERNEL);
	if (!data) {
		err = -ENOMEM;
		goto exit;
	}

	data->i2c_addr = 0x09;
	data->i2c_addr = 0x08;
	/* i2c addr  - use fake addr of 0x08 initially (real is 0x09) */
	data->fw_ver = 0xfe;
	/* firmware version - use fake until we read real value
	 * (currently broken - BlinkM confused!) */
	data->script_id = 0x01;
	data->i2c_client = client;

	i2c_set_clientdata(client, data);
	mutex_init(&data->update_lock);

	/* Register sysfs hooks */
	err = sysfs_create_group(&client->dev.kobj, &blinkm_group);
	if (err < 0) {
		dev_err(&client->dev, "couldn't register sysfs group\n");
		goto exit;
	}

	for (i = 0; i < 3; i++) {
		/* RED = 0, GREEN = 1, BLUE = 2 */
		led[i] = &data->blinkm_leds[i];
		led[i]->i2c_client = client;
		led[i]->id = i;
		led[i]->led_cdev.max_brightness = 255;
		led[i]->led_cdev.flags = LED_CORE_SUSPENDRESUME;
		switch (i) {
		case RED:
			snprintf(blinkm_led_name, sizeof(blinkm_led_name),
					 "blinkm-%d-%d-red",
					 client->adapter->nr,
					 client->addr);
			led[i]->led_cdev.name = blinkm_led_name;
			led[i]->led_cdev.brightness_set_blocking =
							blinkm_led_red_set;
			err = led_classdev_register(&client->dev,
						    &led[i]->led_cdev);
			if (err < 0) {
				dev_err(&client->dev,
					"couldn't register LED %s\n",
					led[i]->led_cdev.name);
				goto failred;
			}
			break;
		case GREEN:
			snprintf(blinkm_led_name, sizeof(blinkm_led_name),
					 "blinkm-%d-%d-green",
					 client->adapter->nr,
					 client->addr);
			led[i]->led_cdev.name = blinkm_led_name;
			led[i]->led_cdev.brightness_set_blocking =
							blinkm_led_green_set;
			err = led_classdev_register(&client->dev,
						    &led[i]->led_cdev);
			if (err < 0) {
				dev_err(&client->dev,
					"couldn't register LED %s\n",
					led[i]->led_cdev.name);
				goto failgreen;
			}
			break;
		case BLUE:
			snprintf(blinkm_led_name, sizeof(blinkm_led_name),
					 "blinkm-%d-%d-blue",
					 client->adapter->nr,
					 client->addr);
			led[i]->led_cdev.name = blinkm_led_name;
			led[i]->led_cdev.brightness_set_blocking =
							blinkm_led_blue_set;
			err = led_classdev_register(&client->dev,
						    &led[i]->led_cdev);
			if (err < 0) {
				dev_err(&client->dev,
					"couldn't register LED %s\n",
					led[i]->led_cdev.name);
				goto failblue;
			}
			break;
		}		/* end switch */
	}			/* end for */

	/* Initialize the blinkm */
	blinkm_init_hw(client);

	return 0;

failblue:
	led_classdev_unregister(&led[GREEN]->led_cdev);

failgreen:
	led_classdev_unregister(&led[RED]->led_cdev);

failred:
	sysfs_remove_group(&client->dev.kobj, &blinkm_group);
exit:
	return err;
}

__attribute__((used)) static int blinkm_remove(struct i2c_client *client)
{
	struct blinkm_data *data = i2c_get_clientdata(client);
	int ret = 0;
	int i;

	/* make sure no workqueue entries are pending */
	for (i = 0; i < 3; i++)
		led_classdev_unregister(&data->blinkm_leds[i].led_cdev);

	/* reset rgb */
	data->next_red = 0x00;
	data->next_green = 0x00;
	data->next_blue = 0x00;
	ret = blinkm_transfer_hw(client, BLM_FADE_RGB);
	if (ret < 0)
		dev_err(&client->dev, "Failure in blinkm_remove ignored. Continuing.\n");

	/* reset hsb */
	data->next_hue = 0x00;
	data->next_saturation = 0x00;
	data->next_brightness = 0x00;
	ret = blinkm_transfer_hw(client, BLM_FADE_HSB);
	if (ret < 0)
		dev_err(&client->dev, "Failure in blinkm_remove ignored. Continuing.\n");

	/* red fade to off */
	data->next_red = 0xff;
	ret = blinkm_transfer_hw(client, BLM_GO_RGB);
	if (ret < 0)
		dev_err(&client->dev, "Failure in blinkm_remove ignored. Continuing.\n");

	/* off */
	data->next_red = 0x00;
	ret = blinkm_transfer_hw(client, BLM_FADE_RGB);
	if (ret < 0)
		dev_err(&client->dev, "Failure in blinkm_remove ignored. Continuing.\n");

	sysfs_remove_group(&client->dev.kobj, &blinkm_group);
	return 0;
}

