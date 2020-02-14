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
struct pmbus_platform_data {int /*<<< orphan*/  flags; } ;
struct pmbus_driver_info {int* func; int pages; scalar_t__* format; int (* identify ) (struct i2c_client*,struct pmbus_driver_info*) ;int /*<<< orphan*/  vrm_version; } ;
struct i2c_device_id {int driver_data; int /*<<< orphan*/  name; } ;
struct device {struct pmbus_platform_data* platform_data; } ;
struct i2c_client {struct device dev; } ;

/* Variables and functions */
 int ENODEV ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int /*<<< orphan*/  PMBUS_FAN_CONFIG_12 ; 
 int /*<<< orphan*/  PMBUS_FAN_CONFIG_34 ; 
 int PMBUS_HAVE_FAN12 ; 
 int PMBUS_HAVE_FAN34 ; 
 int PMBUS_HAVE_IIN ; 
 int PMBUS_HAVE_IOUT ; 
 int PMBUS_HAVE_PIN ; 
 int PMBUS_HAVE_POUT ; 
 int PMBUS_HAVE_STATUS_FAN12 ; 
 int PMBUS_HAVE_STATUS_FAN34 ; 
 int PMBUS_HAVE_STATUS_INPUT ; 
 int PMBUS_HAVE_STATUS_IOUT ; 
 int PMBUS_HAVE_STATUS_TEMP ; 
 int PMBUS_HAVE_STATUS_VOUT ; 
 int PMBUS_HAVE_TEMP ; 
 int PMBUS_HAVE_TEMP2 ; 
 int PMBUS_HAVE_TEMP3 ; 
 int PMBUS_HAVE_VCAP ; 
 int PMBUS_HAVE_VIN ; 
 int PMBUS_HAVE_VOUT ; 
 int /*<<< orphan*/  PMBUS_PAGE ; 
 int PMBUS_PAGES ; 
 int /*<<< orphan*/  PMBUS_READ_FAN_SPEED_1 ; 
 int /*<<< orphan*/  PMBUS_READ_FAN_SPEED_3 ; 
 int /*<<< orphan*/  PMBUS_READ_IIN ; 
 int /*<<< orphan*/  PMBUS_READ_IOUT ; 
 int /*<<< orphan*/  PMBUS_READ_PIN ; 
 int /*<<< orphan*/  PMBUS_READ_POUT ; 
 int /*<<< orphan*/  PMBUS_READ_TEMPERATURE_1 ; 
 int /*<<< orphan*/  PMBUS_READ_TEMPERATURE_2 ; 
 int /*<<< orphan*/  PMBUS_READ_TEMPERATURE_3 ; 
 int /*<<< orphan*/  PMBUS_READ_VCAP ; 
 int /*<<< orphan*/  PMBUS_READ_VIN ; 
 int /*<<< orphan*/  PMBUS_READ_VOUT ; 
 int /*<<< orphan*/  PMBUS_SKIP_STATUS_CHECK ; 
 int /*<<< orphan*/  PMBUS_STATUS_FAN_12 ; 
 int /*<<< orphan*/  PMBUS_STATUS_FAN_34 ; 
 int /*<<< orphan*/  PMBUS_STATUS_INPUT ; 
 int /*<<< orphan*/  PMBUS_STATUS_IOUT ; 
 int /*<<< orphan*/  PMBUS_STATUS_TEMPERATURE ; 
 int /*<<< orphan*/  PMBUS_STATUS_VOUT ; 
 int /*<<< orphan*/  PMBUS_VOUT_MODE ; 
 size_t PSC_VOLTAGE_OUT ; 
 void* devm_kzalloc (struct device*,int,int /*<<< orphan*/ ) ; 
 scalar_t__ direct ; 
 scalar_t__ pmbus_check_byte_register (struct i2c_client*,int,int /*<<< orphan*/ ) ; 
 scalar_t__ pmbus_check_word_register (struct i2c_client*,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  pmbus_clear_faults (struct i2c_client*) ; 
 int pmbus_do_probe (struct i2c_client*,struct i2c_device_id const*,struct pmbus_driver_info*) ; 
 int pmbus_read_byte_data (struct i2c_client*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 scalar_t__ pmbus_set_page (struct i2c_client*,int) ; 
 int /*<<< orphan*/  strcmp (int /*<<< orphan*/ ,char*) ; 
 scalar_t__ vid ; 
 int /*<<< orphan*/  vr11 ; 

__attribute__((used)) static void pmbus_find_sensor_groups(struct i2c_client *client,
				     struct pmbus_driver_info *info)
{
	int page;

	/* Sensors detected on page 0 only */
	if (pmbus_check_word_register(client, 0, PMBUS_READ_VIN))
		info->func[0] |= PMBUS_HAVE_VIN;
	if (pmbus_check_word_register(client, 0, PMBUS_READ_VCAP))
		info->func[0] |= PMBUS_HAVE_VCAP;
	if (pmbus_check_word_register(client, 0, PMBUS_READ_IIN))
		info->func[0] |= PMBUS_HAVE_IIN;
	if (pmbus_check_word_register(client, 0, PMBUS_READ_PIN))
		info->func[0] |= PMBUS_HAVE_PIN;
	if (info->func[0]
	    && pmbus_check_byte_register(client, 0, PMBUS_STATUS_INPUT))
		info->func[0] |= PMBUS_HAVE_STATUS_INPUT;
	if (pmbus_check_byte_register(client, 0, PMBUS_FAN_CONFIG_12) &&
	    pmbus_check_word_register(client, 0, PMBUS_READ_FAN_SPEED_1)) {
		info->func[0] |= PMBUS_HAVE_FAN12;
		if (pmbus_check_byte_register(client, 0, PMBUS_STATUS_FAN_12))
			info->func[0] |= PMBUS_HAVE_STATUS_FAN12;
	}
	if (pmbus_check_byte_register(client, 0, PMBUS_FAN_CONFIG_34) &&
	    pmbus_check_word_register(client, 0, PMBUS_READ_FAN_SPEED_3)) {
		info->func[0] |= PMBUS_HAVE_FAN34;
		if (pmbus_check_byte_register(client, 0, PMBUS_STATUS_FAN_34))
			info->func[0] |= PMBUS_HAVE_STATUS_FAN34;
	}
	if (pmbus_check_word_register(client, 0, PMBUS_READ_TEMPERATURE_1))
		info->func[0] |= PMBUS_HAVE_TEMP;
	if (pmbus_check_word_register(client, 0, PMBUS_READ_TEMPERATURE_2))
		info->func[0] |= PMBUS_HAVE_TEMP2;
	if (pmbus_check_word_register(client, 0, PMBUS_READ_TEMPERATURE_3))
		info->func[0] |= PMBUS_HAVE_TEMP3;
	if (info->func[0] & (PMBUS_HAVE_TEMP | PMBUS_HAVE_TEMP2
			     | PMBUS_HAVE_TEMP3)
	    && pmbus_check_byte_register(client, 0,
					 PMBUS_STATUS_TEMPERATURE))
			info->func[0] |= PMBUS_HAVE_STATUS_TEMP;

	/* Sensors detected on all pages */
	for (page = 0; page < info->pages; page++) {
		if (pmbus_check_word_register(client, page, PMBUS_READ_VOUT)) {
			info->func[page] |= PMBUS_HAVE_VOUT;
			if (pmbus_check_byte_register(client, page,
						      PMBUS_STATUS_VOUT))
				info->func[page] |= PMBUS_HAVE_STATUS_VOUT;
		}
		if (pmbus_check_word_register(client, page, PMBUS_READ_IOUT)) {
			info->func[page] |= PMBUS_HAVE_IOUT;
			if (pmbus_check_byte_register(client, 0,
						      PMBUS_STATUS_IOUT))
				info->func[page] |= PMBUS_HAVE_STATUS_IOUT;
		}
		if (pmbus_check_word_register(client, page, PMBUS_READ_POUT))
			info->func[page] |= PMBUS_HAVE_POUT;
	}
}

__attribute__((used)) static int pmbus_identify(struct i2c_client *client,
			  struct pmbus_driver_info *info)
{
	int ret = 0;

	if (!info->pages) {
		/*
		 * Check if the PAGE command is supported. If it is,
		 * keep setting the page number until it fails or until the
		 * maximum number of pages has been reached. Assume that
		 * this is the number of pages supported by the chip.
		 */
		if (pmbus_check_byte_register(client, 0, PMBUS_PAGE)) {
			int page;

			for (page = 1; page < PMBUS_PAGES; page++) {
				if (pmbus_set_page(client, page) < 0)
					break;
			}
			pmbus_set_page(client, 0);
			info->pages = page;
		} else {
			info->pages = 1;
		}

		pmbus_clear_faults(client);
	}

	if (pmbus_check_byte_register(client, 0, PMBUS_VOUT_MODE)) {
		int vout_mode;

		vout_mode = pmbus_read_byte_data(client, 0, PMBUS_VOUT_MODE);
		if (vout_mode >= 0 && vout_mode != 0xff) {
			switch (vout_mode >> 5) {
			case 0:
				break;
			case 1:
				info->format[PSC_VOLTAGE_OUT] = vid;
				info->vrm_version = vr11;
				break;
			case 2:
				info->format[PSC_VOLTAGE_OUT] = direct;
				break;
			default:
				ret = -ENODEV;
				goto abort;
			}
		}
	}

	/*
	 * We should check if the COEFFICIENTS register is supported.
	 * If it is, and the chip is configured for direct mode, we can read
	 * the coefficients from the chip, one set per group of sensor
	 * registers.
	 *
	 * To do this, we will need access to a chip which actually supports the
	 * COEFFICIENTS command, since the command is too complex to implement
	 * without testing it. Until then, abort if a chip configured for direct
	 * mode was detected.
	 */
	if (info->format[PSC_VOLTAGE_OUT] == direct) {
		ret = -ENODEV;
		goto abort;
	}

	/* Try to find sensor groups  */
	pmbus_find_sensor_groups(client, info);
abort:
	return ret;
}

__attribute__((used)) static int pmbus_probe(struct i2c_client *client,
		       const struct i2c_device_id *id)
{
	struct pmbus_driver_info *info;
	struct pmbus_platform_data *pdata = NULL;
	struct device *dev = &client->dev;

	info = devm_kzalloc(dev, sizeof(struct pmbus_driver_info), GFP_KERNEL);
	if (!info)
		return -ENOMEM;

	if (!strcmp(id->name, "dps460") || !strcmp(id->name, "dps800") ||
	    !strcmp(id->name, "sgd009")) {
		pdata = devm_kzalloc(dev, sizeof(struct pmbus_platform_data),
				     GFP_KERNEL);
		if (!pdata)
			return -ENOMEM;

		pdata->flags = PMBUS_SKIP_STATUS_CHECK;
	}

	info->pages = id->driver_data;
	info->identify = pmbus_identify;
	dev->platform_data = pdata;

	return pmbus_do_probe(client, id, info);
}

