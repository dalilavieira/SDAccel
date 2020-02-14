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
typedef  int /*<<< orphan*/  u16 ;
struct pmbus_driver_info {int pages; int* func; int (* read_word_data ) (struct i2c_client*,int,int) ;int (* read_byte_data ) (struct i2c_client*,int,int) ;int (* write_word_data ) (struct i2c_client*,int,int,int /*<<< orphan*/ ) ;int /*<<< orphan*/ * R; int /*<<< orphan*/ * b; int /*<<< orphan*/ * m; void** format; } ;
struct i2c_device_id {scalar_t__ driver_data; scalar_t__* name; } ;
struct i2c_client {int /*<<< orphan*/  dev; int /*<<< orphan*/  adapter; } ;
struct coefficients {int /*<<< orphan*/  R; int /*<<< orphan*/  b; int /*<<< orphan*/  m; } ;
struct adm1275_data {int have_uc_fault; int have_oc_fault; int have_vout; int have_iout_min; int have_pin_min; int have_pin_max; int have_temp_max; int have_vaux_status; int have_mfr_vaux_status; scalar_t__ id; struct pmbus_driver_info info; } ;

/* Variables and functions */
#define  ADM1075_IRANGE_25 164 
#define  ADM1075_IRANGE_50 163 
 int ADM1075_IRANGE_MASK ; 
 int /*<<< orphan*/  ADM1075_READ_VAUX ; 
 int ADM1075_VAUX_OV_WARN ; 
 int /*<<< orphan*/  ADM1075_VAUX_OV_WARN_LIMIT ; 
 int const ADM1075_VAUX_STATUS ; 
 int ADM1075_VAUX_UV_WARN ; 
 int /*<<< orphan*/  ADM1075_VAUX_UV_WARN_LIMIT ; 
#define  ADM1272_IRANGE 162 
 int /*<<< orphan*/  ADM1275_DEVICE_CONFIG ; 
 int /*<<< orphan*/  ADM1275_IOUT_WARN2_LIMIT ; 
 int ADM1275_IOUT_WARN2_SELECT ; 
 int ADM1275_MFR_STATUS_IOUT_WARN2 ; 
 int /*<<< orphan*/  ADM1275_PEAK_IOUT ; 
 int /*<<< orphan*/  ADM1275_PEAK_VIN ; 
 int /*<<< orphan*/  ADM1275_PEAK_VOUT ; 
 int /*<<< orphan*/  ADM1275_PMON_CONFIG ; 
 int ADM1275_VIN_VOUT_SELECT ; 
#define  ADM1275_VRANGE 161 
 int /*<<< orphan*/  ADM1276_PEAK_PIN ; 
 int /*<<< orphan*/  ADM1278_PEAK_TEMP ; 
 int ADM1278_TEMP1_EN ; 
 int ADM1278_VIN_EN ; 
 int ADM1278_VOUT_EN ; 
 int /*<<< orphan*/  ADM1293_IOUT_MIN ; 
#define  ADM1293_IRANGE_100 160 
#define  ADM1293_IRANGE_200 159 
#define  ADM1293_IRANGE_25 158 
#define  ADM1293_IRANGE_50 157 
 int ADM1293_IRANGE_MASK ; 
 int ADM1293_MFR_STATUS_VAUX_OV_WARN ; 
 int ADM1293_MFR_STATUS_VAUX_UV_WARN ; 
 int /*<<< orphan*/  ADM1293_PIN_MIN ; 
 int ADM1293_VAUX_EN ; 
#define  ADM1293_VIN_SEL_012 156 
#define  ADM1293_VIN_SEL_074 155 
#define  ADM1293_VIN_SEL_210 154 
 int ADM1293_VIN_SEL_MASK ; 
 int ENODATA ; 
 int ENODEV ; 
 int ENOMEM ; 
 int ENXIO ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int I2C_FUNC_SMBUS_BLOCK_DATA ; 
 int I2C_FUNC_SMBUS_READ_BYTE_DATA ; 
 int /*<<< orphan*/  I2C_SMBUS_BLOCK_MAX ; 
 int PB_IOUT_OC_FAULT ; 
 int PB_IOUT_UC_FAULT ; 
 int PB_VOLTAGE_OV_WARNING ; 
 int PB_VOLTAGE_UV_WARNING ; 
 int PMBUS_HAVE_IOUT ; 
 int PMBUS_HAVE_PIN ; 
 int PMBUS_HAVE_STATUS_INPUT ; 
 int PMBUS_HAVE_STATUS_IOUT ; 
 int PMBUS_HAVE_STATUS_TEMP ; 
 int PMBUS_HAVE_STATUS_VOUT ; 
 int PMBUS_HAVE_TEMP ; 
 int PMBUS_HAVE_VIN ; 
 int PMBUS_HAVE_VOUT ; 
#define  PMBUS_IOUT_OC_FAULT_LIMIT 153 
#define  PMBUS_IOUT_UC_FAULT_LIMIT 152 
 int /*<<< orphan*/  PMBUS_MFR_ID ; 
 int /*<<< orphan*/  PMBUS_MFR_MODEL ; 
#define  PMBUS_READ_VOUT 151 
#define  PMBUS_STATUS_IOUT 150 
 int const PMBUS_STATUS_MFR_SPECIFIC ; 
#define  PMBUS_STATUS_VOUT 149 
#define  PMBUS_VIRT_READ_IOUT_MAX 148 
#define  PMBUS_VIRT_READ_IOUT_MIN 147 
#define  PMBUS_VIRT_READ_PIN_MAX 146 
#define  PMBUS_VIRT_READ_PIN_MIN 145 
#define  PMBUS_VIRT_READ_TEMP_MAX 144 
#define  PMBUS_VIRT_READ_VIN_MAX 143 
#define  PMBUS_VIRT_READ_VOUT_MAX 142 
#define  PMBUS_VIRT_RESET_IOUT_HISTORY 141 
#define  PMBUS_VIRT_RESET_PIN_HISTORY 140 
#define  PMBUS_VIRT_RESET_TEMP_HISTORY 139 
#define  PMBUS_VIRT_RESET_VIN_HISTORY 138 
#define  PMBUS_VIRT_RESET_VOUT_HISTORY 137 
#define  PMBUS_VOUT_OV_WARN_LIMIT 136 
#define  PMBUS_VOUT_UV_WARN_LIMIT 135 
 size_t PSC_CURRENT_OUT ; 
 size_t PSC_POWER ; 
 size_t PSC_TEMPERATURE ; 
 size_t PSC_VOLTAGE_IN ; 
 size_t PSC_VOLTAGE_OUT ; 
#define  adm1075 134 
 struct coefficients* adm1075_coefficients ; 
#define  adm1272 133 
 struct coefficients* adm1272_coefficients ; 
#define  adm1275 132 
 struct coefficients* adm1275_coefficients ; 
 struct i2c_device_id* adm1275_id ; 
#define  adm1276 131 
 struct coefficients* adm1276_coefficients ; 
#define  adm1278 130 
 struct coefficients* adm1278_coefficients ; 
#define  adm1293 129 
 struct coefficients* adm1293_coefficients ; 
#define  adm1294 128 
 int /*<<< orphan*/  dev_err (int /*<<< orphan*/ *,char*) ; 
 int /*<<< orphan*/  dev_notice (int /*<<< orphan*/ *,char*,scalar_t__*,scalar_t__*) ; 
 struct adm1275_data* devm_kzalloc (int /*<<< orphan*/ *,int,int /*<<< orphan*/ ) ; 
 void* direct ; 
 int /*<<< orphan*/  i2c_check_functionality (int /*<<< orphan*/ ,int) ; 
 int i2c_smbus_read_block_data (struct i2c_client*,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int i2c_smbus_read_byte_data (struct i2c_client*,int /*<<< orphan*/ ) ; 
 int i2c_smbus_write_byte_data (struct i2c_client*,int /*<<< orphan*/ ,int) ; 
 int pmbus_do_probe (struct i2c_client*,struct i2c_device_id const*,struct pmbus_driver_info*) ; 
 struct pmbus_driver_info* pmbus_get_driver_info (struct i2c_client*) ; 
 int pmbus_read_byte_data (struct i2c_client*,int,int const) ; 
 int pmbus_read_word_data (struct i2c_client*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int pmbus_write_word_data (struct i2c_client*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  strlen (scalar_t__*) ; 
 int /*<<< orphan*/  strncasecmp (scalar_t__*,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 scalar_t__ strncmp (int /*<<< orphan*/ *,char*,int) ; 
 struct adm1275_data* to_adm1275_data (struct pmbus_driver_info const*) ; 

__attribute__((used)) static int adm1275_read_word_data(struct i2c_client *client, int page, int reg)
{
	const struct pmbus_driver_info *info = pmbus_get_driver_info(client);
	const struct adm1275_data *data = to_adm1275_data(info);
	int ret = 0;

	if (page > 0)
		return -ENXIO;

	switch (reg) {
	case PMBUS_IOUT_UC_FAULT_LIMIT:
		if (!data->have_uc_fault)
			return -ENXIO;
		ret = pmbus_read_word_data(client, 0, ADM1275_IOUT_WARN2_LIMIT);
		break;
	case PMBUS_IOUT_OC_FAULT_LIMIT:
		if (!data->have_oc_fault)
			return -ENXIO;
		ret = pmbus_read_word_data(client, 0, ADM1275_IOUT_WARN2_LIMIT);
		break;
	case PMBUS_VOUT_OV_WARN_LIMIT:
		if (data->have_vout)
			return -ENODATA;
		ret = pmbus_read_word_data(client, 0,
					   ADM1075_VAUX_OV_WARN_LIMIT);
		break;
	case PMBUS_VOUT_UV_WARN_LIMIT:
		if (data->have_vout)
			return -ENODATA;
		ret = pmbus_read_word_data(client, 0,
					   ADM1075_VAUX_UV_WARN_LIMIT);
		break;
	case PMBUS_READ_VOUT:
		if (data->have_vout)
			return -ENODATA;
		ret = pmbus_read_word_data(client, 0, ADM1075_READ_VAUX);
		break;
	case PMBUS_VIRT_READ_IOUT_MIN:
		if (!data->have_iout_min)
			return -ENXIO;
		ret = pmbus_read_word_data(client, 0, ADM1293_IOUT_MIN);
		break;
	case PMBUS_VIRT_READ_IOUT_MAX:
		ret = pmbus_read_word_data(client, 0, ADM1275_PEAK_IOUT);
		break;
	case PMBUS_VIRT_READ_VOUT_MAX:
		ret = pmbus_read_word_data(client, 0, ADM1275_PEAK_VOUT);
		break;
	case PMBUS_VIRT_READ_VIN_MAX:
		ret = pmbus_read_word_data(client, 0, ADM1275_PEAK_VIN);
		break;
	case PMBUS_VIRT_READ_PIN_MIN:
		if (!data->have_pin_min)
			return -ENXIO;
		ret = pmbus_read_word_data(client, 0, ADM1293_PIN_MIN);
		break;
	case PMBUS_VIRT_READ_PIN_MAX:
		if (!data->have_pin_max)
			return -ENXIO;
		ret = pmbus_read_word_data(client, 0, ADM1276_PEAK_PIN);
		break;
	case PMBUS_VIRT_READ_TEMP_MAX:
		if (!data->have_temp_max)
			return -ENXIO;
		ret = pmbus_read_word_data(client, 0, ADM1278_PEAK_TEMP);
		break;
	case PMBUS_VIRT_RESET_IOUT_HISTORY:
	case PMBUS_VIRT_RESET_VOUT_HISTORY:
	case PMBUS_VIRT_RESET_VIN_HISTORY:
		break;
	case PMBUS_VIRT_RESET_PIN_HISTORY:
		if (!data->have_pin_max)
			return -ENXIO;
		break;
	case PMBUS_VIRT_RESET_TEMP_HISTORY:
		if (!data->have_temp_max)
			return -ENXIO;
		break;
	default:
		ret = -ENODATA;
		break;
	}
	return ret;
}

__attribute__((used)) static int adm1275_write_word_data(struct i2c_client *client, int page, int reg,
				   u16 word)
{
	const struct pmbus_driver_info *info = pmbus_get_driver_info(client);
	const struct adm1275_data *data = to_adm1275_data(info);
	int ret;

	if (page > 0)
		return -ENXIO;

	switch (reg) {
	case PMBUS_IOUT_UC_FAULT_LIMIT:
	case PMBUS_IOUT_OC_FAULT_LIMIT:
		ret = pmbus_write_word_data(client, 0, ADM1275_IOUT_WARN2_LIMIT,
					    word);
		break;
	case PMBUS_VIRT_RESET_IOUT_HISTORY:
		ret = pmbus_write_word_data(client, 0, ADM1275_PEAK_IOUT, 0);
		if (!ret && data->have_iout_min)
			ret = pmbus_write_word_data(client, 0,
						    ADM1293_IOUT_MIN, 0);
		break;
	case PMBUS_VIRT_RESET_VOUT_HISTORY:
		ret = pmbus_write_word_data(client, 0, ADM1275_PEAK_VOUT, 0);
		break;
	case PMBUS_VIRT_RESET_VIN_HISTORY:
		ret = pmbus_write_word_data(client, 0, ADM1275_PEAK_VIN, 0);
		break;
	case PMBUS_VIRT_RESET_PIN_HISTORY:
		ret = pmbus_write_word_data(client, 0, ADM1276_PEAK_PIN, 0);
		if (!ret && data->have_pin_min)
			ret = pmbus_write_word_data(client, 0,
						    ADM1293_PIN_MIN, 0);
		break;
	case PMBUS_VIRT_RESET_TEMP_HISTORY:
		ret = pmbus_write_word_data(client, 0, ADM1278_PEAK_TEMP, 0);
		break;
	default:
		ret = -ENODATA;
		break;
	}
	return ret;
}

__attribute__((used)) static int adm1275_read_byte_data(struct i2c_client *client, int page, int reg)
{
	const struct pmbus_driver_info *info = pmbus_get_driver_info(client);
	const struct adm1275_data *data = to_adm1275_data(info);
	int mfr_status, ret;

	if (page > 0)
		return -ENXIO;

	switch (reg) {
	case PMBUS_STATUS_IOUT:
		ret = pmbus_read_byte_data(client, page, PMBUS_STATUS_IOUT);
		if (ret < 0)
			break;
		if (!data->have_oc_fault && !data->have_uc_fault)
			break;
		mfr_status = pmbus_read_byte_data(client, page,
						  PMBUS_STATUS_MFR_SPECIFIC);
		if (mfr_status < 0)
			return mfr_status;
		if (mfr_status & ADM1275_MFR_STATUS_IOUT_WARN2) {
			ret |= data->have_oc_fault ?
			  PB_IOUT_OC_FAULT : PB_IOUT_UC_FAULT;
		}
		break;
	case PMBUS_STATUS_VOUT:
		if (data->have_vout)
			return -ENODATA;
		ret = 0;
		if (data->have_vaux_status) {
			mfr_status = pmbus_read_byte_data(client, 0,
							  ADM1075_VAUX_STATUS);
			if (mfr_status < 0)
				return mfr_status;
			if (mfr_status & ADM1075_VAUX_OV_WARN)
				ret |= PB_VOLTAGE_OV_WARNING;
			if (mfr_status & ADM1075_VAUX_UV_WARN)
				ret |= PB_VOLTAGE_UV_WARNING;
		} else if (data->have_mfr_vaux_status) {
			mfr_status = pmbus_read_byte_data(client, page,
						PMBUS_STATUS_MFR_SPECIFIC);
			if (mfr_status < 0)
				return mfr_status;
			if (mfr_status & ADM1293_MFR_STATUS_VAUX_OV_WARN)
				ret |= PB_VOLTAGE_OV_WARNING;
			if (mfr_status & ADM1293_MFR_STATUS_VAUX_UV_WARN)
				ret |= PB_VOLTAGE_UV_WARNING;
		}
		break;
	default:
		ret = -ENODATA;
		break;
	}
	return ret;
}

__attribute__((used)) static int adm1275_probe(struct i2c_client *client,
			 const struct i2c_device_id *id)
{
	u8 block_buffer[I2C_SMBUS_BLOCK_MAX + 1];
	int config, device_config;
	int ret;
	struct pmbus_driver_info *info;
	struct adm1275_data *data;
	const struct i2c_device_id *mid;
	const struct coefficients *coefficients;
	int vindex = -1, voindex = -1, cindex = -1, pindex = -1;
	int tindex = -1;

	if (!i2c_check_functionality(client->adapter,
				     I2C_FUNC_SMBUS_READ_BYTE_DATA
				     | I2C_FUNC_SMBUS_BLOCK_DATA))
		return -ENODEV;

	ret = i2c_smbus_read_block_data(client, PMBUS_MFR_ID, block_buffer);
	if (ret < 0) {
		dev_err(&client->dev, "Failed to read Manufacturer ID\n");
		return ret;
	}
	if (ret != 3 || strncmp(block_buffer, "ADI", 3)) {
		dev_err(&client->dev, "Unsupported Manufacturer ID\n");
		return -ENODEV;
	}

	ret = i2c_smbus_read_block_data(client, PMBUS_MFR_MODEL, block_buffer);
	if (ret < 0) {
		dev_err(&client->dev, "Failed to read Manufacturer Model\n");
		return ret;
	}
	for (mid = adm1275_id; mid->name[0]; mid++) {
		if (!strncasecmp(mid->name, block_buffer, strlen(mid->name)))
			break;
	}
	if (!mid->name[0]) {
		dev_err(&client->dev, "Unsupported device\n");
		return -ENODEV;
	}

	if (id->driver_data != mid->driver_data)
		dev_notice(&client->dev,
			   "Device mismatch: Configured %s, detected %s\n",
			   id->name, mid->name);

	config = i2c_smbus_read_byte_data(client, ADM1275_PMON_CONFIG);
	if (config < 0)
		return config;

	device_config = i2c_smbus_read_byte_data(client, ADM1275_DEVICE_CONFIG);
	if (device_config < 0)
		return device_config;

	data = devm_kzalloc(&client->dev, sizeof(struct adm1275_data),
			    GFP_KERNEL);
	if (!data)
		return -ENOMEM;

	data->id = mid->driver_data;

	info = &data->info;

	info->pages = 1;
	info->format[PSC_VOLTAGE_IN] = direct;
	info->format[PSC_VOLTAGE_OUT] = direct;
	info->format[PSC_CURRENT_OUT] = direct;
	info->format[PSC_POWER] = direct;
	info->format[PSC_TEMPERATURE] = direct;
	info->func[0] = PMBUS_HAVE_IOUT | PMBUS_HAVE_STATUS_IOUT;

	info->read_word_data = adm1275_read_word_data;
	info->read_byte_data = adm1275_read_byte_data;
	info->write_word_data = adm1275_write_word_data;

	switch (data->id) {
	case adm1075:
		if (device_config & ADM1275_IOUT_WARN2_SELECT)
			data->have_oc_fault = true;
		else
			data->have_uc_fault = true;
		data->have_pin_max = true;
		data->have_vaux_status = true;

		coefficients = adm1075_coefficients;
		vindex = 0;
		switch (config & ADM1075_IRANGE_MASK) {
		case ADM1075_IRANGE_25:
			cindex = 1;
			pindex = 3;
			break;
		case ADM1075_IRANGE_50:
			cindex = 2;
			pindex = 4;
			break;
		default:
			dev_err(&client->dev, "Invalid input current range");
			break;
		}

		info->func[0] |= PMBUS_HAVE_VIN | PMBUS_HAVE_PIN
		  | PMBUS_HAVE_STATUS_INPUT;
		if (config & ADM1275_VIN_VOUT_SELECT)
			info->func[0] |=
			  PMBUS_HAVE_VOUT | PMBUS_HAVE_STATUS_VOUT;
		break;
	case adm1272:
		data->have_vout = true;
		data->have_pin_max = true;
		data->have_temp_max = true;

		coefficients = adm1272_coefficients;
		vindex = (config & ADM1275_VRANGE) ? 1 : 0;
		cindex = (config & ADM1272_IRANGE) ? 3 : 2;
		/* pindex depends on the combination of the above */
		switch (config & (ADM1275_VRANGE | ADM1272_IRANGE)) {
		case 0:
		default:
			pindex = 4;
			break;
		case ADM1275_VRANGE:
			pindex = 5;
			break;
		case ADM1272_IRANGE:
			pindex = 6;
			break;
		case ADM1275_VRANGE | ADM1272_IRANGE:
			pindex = 7;
			break;
		}
		tindex = 8;

		info->func[0] |= PMBUS_HAVE_PIN | PMBUS_HAVE_STATUS_INPUT |
			PMBUS_HAVE_VOUT | PMBUS_HAVE_STATUS_VOUT;

		/* Enable VOUT if not enabled (it is disabled by default) */
		if (!(config & ADM1278_VOUT_EN)) {
			config |= ADM1278_VOUT_EN;
			ret = i2c_smbus_write_byte_data(client,
							ADM1275_PMON_CONFIG,
							config);
			if (ret < 0) {
				dev_err(&client->dev,
					"Failed to enable VOUT monitoring\n");
				return -ENODEV;
			}
		}

		if (config & ADM1278_TEMP1_EN)
			info->func[0] |=
				PMBUS_HAVE_TEMP | PMBUS_HAVE_STATUS_TEMP;
		if (config & ADM1278_VIN_EN)
			info->func[0] |= PMBUS_HAVE_VIN;
		break;
	case adm1275:
		if (device_config & ADM1275_IOUT_WARN2_SELECT)
			data->have_oc_fault = true;
		else
			data->have_uc_fault = true;
		data->have_vout = true;

		coefficients = adm1275_coefficients;
		vindex = (config & ADM1275_VRANGE) ? 0 : 1;
		cindex = 2;

		if (config & ADM1275_VIN_VOUT_SELECT)
			info->func[0] |=
			  PMBUS_HAVE_VOUT | PMBUS_HAVE_STATUS_VOUT;
		else
			info->func[0] |=
			  PMBUS_HAVE_VIN | PMBUS_HAVE_STATUS_INPUT;
		break;
	case adm1276:
		if (device_config & ADM1275_IOUT_WARN2_SELECT)
			data->have_oc_fault = true;
		else
			data->have_uc_fault = true;
		data->have_vout = true;
		data->have_pin_max = true;

		coefficients = adm1276_coefficients;
		vindex = (config & ADM1275_VRANGE) ? 0 : 1;
		cindex = 2;
		pindex = (config & ADM1275_VRANGE) ? 3 : 4;

		info->func[0] |= PMBUS_HAVE_VIN | PMBUS_HAVE_PIN
		  | PMBUS_HAVE_STATUS_INPUT;
		if (config & ADM1275_VIN_VOUT_SELECT)
			info->func[0] |=
			  PMBUS_HAVE_VOUT | PMBUS_HAVE_STATUS_VOUT;
		break;
	case adm1278:
		data->have_vout = true;
		data->have_pin_max = true;
		data->have_temp_max = true;

		coefficients = adm1278_coefficients;
		vindex = 0;
		cindex = 1;
		pindex = 2;
		tindex = 3;

		info->func[0] |= PMBUS_HAVE_PIN | PMBUS_HAVE_STATUS_INPUT |
			PMBUS_HAVE_VOUT | PMBUS_HAVE_STATUS_VOUT;

		/* Enable VOUT if not enabled (it is disabled by default) */
		if (!(config & ADM1278_VOUT_EN)) {
			config |= ADM1278_VOUT_EN;
			ret = i2c_smbus_write_byte_data(client,
							ADM1275_PMON_CONFIG,
							config);
			if (ret < 0) {
				dev_err(&client->dev,
					"Failed to enable VOUT monitoring\n");
				return -ENODEV;
			}
		}

		if (config & ADM1278_TEMP1_EN)
			info->func[0] |=
				PMBUS_HAVE_TEMP | PMBUS_HAVE_STATUS_TEMP;
		if (config & ADM1278_VIN_EN)
			info->func[0] |= PMBUS_HAVE_VIN;
		break;
	case adm1293:
	case adm1294:
		data->have_iout_min = true;
		data->have_pin_min = true;
		data->have_pin_max = true;
		data->have_mfr_vaux_status = true;

		coefficients = adm1293_coefficients;

		voindex = 0;
		switch (config & ADM1293_VIN_SEL_MASK) {
		case ADM1293_VIN_SEL_012:	/* 1.2V */
			vindex = 0;
			break;
		case ADM1293_VIN_SEL_074:	/* 7.4V */
			vindex = 1;
			break;
		case ADM1293_VIN_SEL_210:	/* 21V */
			vindex = 2;
			break;
		default:			/* disabled */
			break;
		}

		switch (config & ADM1293_IRANGE_MASK) {
		case ADM1293_IRANGE_25:
			cindex = 3;
			break;
		case ADM1293_IRANGE_50:
			cindex = 4;
			break;
		case ADM1293_IRANGE_100:
			cindex = 5;
			break;
		case ADM1293_IRANGE_200:
			cindex = 6;
			break;
		}

		if (vindex >= 0)
			pindex = 7 + vindex * 4 + (cindex - 3);

		if (config & ADM1293_VAUX_EN)
			info->func[0] |=
				PMBUS_HAVE_VOUT | PMBUS_HAVE_STATUS_VOUT;

		info->func[0] |= PMBUS_HAVE_PIN |
			PMBUS_HAVE_VIN | PMBUS_HAVE_STATUS_INPUT;

		break;
	default:
		dev_err(&client->dev, "Unsupported device\n");
		return -ENODEV;
	}

	if (voindex < 0)
		voindex = vindex;
	if (vindex >= 0) {
		info->m[PSC_VOLTAGE_IN] = coefficients[vindex].m;
		info->b[PSC_VOLTAGE_IN] = coefficients[vindex].b;
		info->R[PSC_VOLTAGE_IN] = coefficients[vindex].R;
	}
	if (voindex >= 0) {
		info->m[PSC_VOLTAGE_OUT] = coefficients[voindex].m;
		info->b[PSC_VOLTAGE_OUT] = coefficients[voindex].b;
		info->R[PSC_VOLTAGE_OUT] = coefficients[voindex].R;
	}
	if (cindex >= 0) {
		info->m[PSC_CURRENT_OUT] = coefficients[cindex].m;
		info->b[PSC_CURRENT_OUT] = coefficients[cindex].b;
		info->R[PSC_CURRENT_OUT] = coefficients[cindex].R;
	}
	if (pindex >= 0) {
		info->m[PSC_POWER] = coefficients[pindex].m;
		info->b[PSC_POWER] = coefficients[pindex].b;
		info->R[PSC_POWER] = coefficients[pindex].R;
	}
	if (tindex >= 0) {
		info->m[PSC_TEMPERATURE] = coefficients[tindex].m;
		info->b[PSC_TEMPERATURE] = coefficients[tindex].b;
		info->R[PSC_TEMPERATURE] = coefficients[tindex].R;
	}

	return pmbus_do_probe(client, id, info);
}

