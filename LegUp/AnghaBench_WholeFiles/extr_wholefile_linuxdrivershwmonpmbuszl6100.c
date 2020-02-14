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
typedef  char u8 ;
typedef  int u16 ;
struct pmbus_driver_info {int pages; int* func; int (* read_word_data ) (struct i2c_client*,int,int) ;int (* read_byte_data ) (struct i2c_client*,int,int) ;int (* write_word_data ) (struct i2c_client*,int,int,int) ;int (* write_byte ) (struct i2c_client*,int,char) ;} ;
struct zl6100_data {scalar_t__ delay; scalar_t__ id; void* access; struct pmbus_driver_info info; } ;
struct i2c_device_id {scalar_t__ driver_data; scalar_t__* name; } ;
struct i2c_client {int /*<<< orphan*/  dev; int /*<<< orphan*/  adapter; } ;
typedef  scalar_t__ s64 ;
typedef  long s32 ;
typedef  int s16 ;

/* Variables and functions */
 void* DIV_ROUND_CLOSEST (int,int) ; 
 int ENODEV ; 
 int ENOMEM ; 
 int ENXIO ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int I2C_FUNC_SMBUS_READ_BLOCK_DATA ; 
 int I2C_FUNC_SMBUS_READ_WORD_DATA ; 
 int /*<<< orphan*/  I2C_SMBUS_BLOCK_MAX ; 
 long MAX_MANTISSA ; 
 int MFR_READ_VMON ; 
 int MFR_VMON_OV_FAULT_LIMIT ; 
 int MFR_VMON_UV_FAULT_LIMIT ; 
 long MIN_MANTISSA ; 
 int PB_VOLTAGE_OV_FAULT ; 
 int PB_VOLTAGE_OV_WARNING ; 
 int PB_VOLTAGE_UV_FAULT ; 
 int PB_VOLTAGE_UV_WARNING ; 
 int PMBUS_HAVE_IOUT ; 
 int PMBUS_HAVE_STATUS_INPUT ; 
 int PMBUS_HAVE_STATUS_IOUT ; 
 int PMBUS_HAVE_STATUS_TEMP ; 
 int PMBUS_HAVE_STATUS_VMON ; 
 int PMBUS_HAVE_STATUS_VOUT ; 
 int PMBUS_HAVE_TEMP ; 
 int PMBUS_HAVE_TEMP2 ; 
 int PMBUS_HAVE_VIN ; 
 int PMBUS_HAVE_VMON ; 
 int PMBUS_HAVE_VOUT ; 
#define  PMBUS_IOUT_OC_WARN_LIMIT 136 
 int PMBUS_STATUS_MFR_SPECIFIC ; 
 int PMBUS_VIRT_BASE ; 
#define  PMBUS_VIRT_READ_VMON 135 
#define  PMBUS_VIRT_STATUS_VMON 134 
#define  PMBUS_VIRT_VMON_OV_FAULT_LIMIT 133 
#define  PMBUS_VIRT_VMON_OV_WARN_LIMIT 132 
#define  PMBUS_VIRT_VMON_UV_FAULT_LIMIT 131 
#define  PMBUS_VIRT_VMON_UV_WARN_LIMIT 130 
#define  PMBUS_VOUT_OV_WARN_LIMIT 129 
#define  PMBUS_VOUT_UV_WARN_LIMIT 128 
 int VMON_OV_FAULT ; 
 int VMON_OV_WARNING ; 
 int VMON_UV_FAULT ; 
 int VMON_UV_WARNING ; 
 int /*<<< orphan*/  ZL6100_DEVICE_ID ; 
 int /*<<< orphan*/  ZL6100_MFR_CONFIG ; 
 int ZL6100_MFR_XTEMP_ENABLE ; 
 scalar_t__ delay ; 
 int /*<<< orphan*/  dev_err (int /*<<< orphan*/ *,char*) ; 
 int /*<<< orphan*/  dev_info (int /*<<< orphan*/ *,char*,char*) ; 
 int /*<<< orphan*/  dev_notice (int /*<<< orphan*/ *,char*,scalar_t__*,scalar_t__*) ; 
 struct zl6100_data* devm_kzalloc (int /*<<< orphan*/ *,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  i2c_check_functionality (int /*<<< orphan*/ ,int) ; 
 int i2c_smbus_read_block_data (struct i2c_client*,int /*<<< orphan*/ ,char*) ; 
 int i2c_smbus_read_word_data (struct i2c_client*,int /*<<< orphan*/ ) ; 
 void* ktime_get () ; 
 scalar_t__ ktime_us_delta (void*,void*) ; 
 int /*<<< orphan*/  pmbus_clear_cache (struct i2c_client*) ; 
 int pmbus_do_probe (struct i2c_client*,struct i2c_device_id const*,struct pmbus_driver_info*) ; 
 struct pmbus_driver_info* pmbus_get_driver_info (struct i2c_client*) ; 
 int pmbus_read_byte_data (struct i2c_client*,int,int) ; 
 int pmbus_read_word_data (struct i2c_client*,int,int) ; 
 int pmbus_write_byte (struct i2c_client*,int,char) ; 
 int pmbus_write_word_data (struct i2c_client*,int,int,int) ; 
 int /*<<< orphan*/  strlen (scalar_t__*) ; 
 int /*<<< orphan*/  strncasecmp (scalar_t__*,char*,int /*<<< orphan*/ ) ; 
 struct zl6100_data* to_zl6100_data (struct pmbus_driver_info const*) ; 
 int /*<<< orphan*/  udelay (scalar_t__) ; 
 scalar_t__ zl2004 ; 
 scalar_t__ zl2005 ; 
 struct i2c_device_id* zl6100_id ; 
 scalar_t__ zl9101 ; 
 scalar_t__ zl9117 ; 

__attribute__((used)) static long zl6100_l2d(s16 l)
{
	s16 exponent;
	s32 mantissa;
	long val;

	exponent = l >> 11;
	mantissa = ((s16)((l & 0x7ff) << 5)) >> 5;

	val = mantissa;

	/* scale result to milli-units */
	val = val * 1000L;

	if (exponent >= 0)
		val <<= exponent;
	else
		val >>= -exponent;

	return val;
}

__attribute__((used)) static u16 zl6100_d2l(long val)
{
	s16 exponent = 0, mantissa;
	bool negative = false;

	/* simple case */
	if (val == 0)
		return 0;

	if (val < 0) {
		negative = true;
		val = -val;
	}

	/* Reduce large mantissa until it fits into 10 bit */
	while (val >= MAX_MANTISSA && exponent < 15) {
		exponent++;
		val >>= 1;
	}
	/* Increase small mantissa to improve precision */
	while (val < MIN_MANTISSA && exponent > -15) {
		exponent--;
		val <<= 1;
	}

	/* Convert mantissa from milli-units to units */
	mantissa = DIV_ROUND_CLOSEST(val, 1000);

	/* Ensure that resulting number is within range */
	if (mantissa > 0x3ff)
		mantissa = 0x3ff;

	/* restore sign */
	if (negative)
		mantissa = -mantissa;

	/* Convert to 5 bit exponent, 11 bit mantissa */
	return (mantissa & 0x7ff) | ((exponent << 11) & 0xf800);
}

__attribute__((used)) static inline void zl6100_wait(const struct zl6100_data *data)
{
	if (data->delay) {
		s64 delta = ktime_us_delta(ktime_get(), data->access);
		if (delta < data->delay)
			udelay(data->delay - delta);
	}
}

__attribute__((used)) static int zl6100_read_word_data(struct i2c_client *client, int page, int reg)
{
	const struct pmbus_driver_info *info = pmbus_get_driver_info(client);
	struct zl6100_data *data = to_zl6100_data(info);
	int ret, vreg;

	if (page > 0)
		return -ENXIO;

	if (data->id == zl2005) {
		/*
		 * Limit register detection is not reliable on ZL2005.
		 * Make sure registers are not erroneously detected.
		 */
		switch (reg) {
		case PMBUS_VOUT_OV_WARN_LIMIT:
		case PMBUS_VOUT_UV_WARN_LIMIT:
		case PMBUS_IOUT_OC_WARN_LIMIT:
			return -ENXIO;
		}
	}

	switch (reg) {
	case PMBUS_VIRT_READ_VMON:
		vreg = MFR_READ_VMON;
		break;
	case PMBUS_VIRT_VMON_OV_WARN_LIMIT:
	case PMBUS_VIRT_VMON_OV_FAULT_LIMIT:
		vreg = MFR_VMON_OV_FAULT_LIMIT;
		break;
	case PMBUS_VIRT_VMON_UV_WARN_LIMIT:
	case PMBUS_VIRT_VMON_UV_FAULT_LIMIT:
		vreg = MFR_VMON_UV_FAULT_LIMIT;
		break;
	default:
		if (reg >= PMBUS_VIRT_BASE)
			return -ENXIO;
		vreg = reg;
		break;
	}

	zl6100_wait(data);
	ret = pmbus_read_word_data(client, page, vreg);
	data->access = ktime_get();
	if (ret < 0)
		return ret;

	switch (reg) {
	case PMBUS_VIRT_VMON_OV_WARN_LIMIT:
		ret = zl6100_d2l(DIV_ROUND_CLOSEST(zl6100_l2d(ret) * 9, 10));
		break;
	case PMBUS_VIRT_VMON_UV_WARN_LIMIT:
		ret = zl6100_d2l(DIV_ROUND_CLOSEST(zl6100_l2d(ret) * 11, 10));
		break;
	}

	return ret;
}

__attribute__((used)) static int zl6100_read_byte_data(struct i2c_client *client, int page, int reg)
{
	const struct pmbus_driver_info *info = pmbus_get_driver_info(client);
	struct zl6100_data *data = to_zl6100_data(info);
	int ret, status;

	if (page > 0)
		return -ENXIO;

	zl6100_wait(data);

	switch (reg) {
	case PMBUS_VIRT_STATUS_VMON:
		ret = pmbus_read_byte_data(client, 0,
					   PMBUS_STATUS_MFR_SPECIFIC);
		if (ret < 0)
			break;

		status = 0;
		if (ret & VMON_UV_WARNING)
			status |= PB_VOLTAGE_UV_WARNING;
		if (ret & VMON_OV_WARNING)
			status |= PB_VOLTAGE_OV_WARNING;
		if (ret & VMON_UV_FAULT)
			status |= PB_VOLTAGE_UV_FAULT;
		if (ret & VMON_OV_FAULT)
			status |= PB_VOLTAGE_OV_FAULT;
		ret = status;
		break;
	default:
		ret = pmbus_read_byte_data(client, page, reg);
		break;
	}
	data->access = ktime_get();

	return ret;
}

__attribute__((used)) static int zl6100_write_word_data(struct i2c_client *client, int page, int reg,
				  u16 word)
{
	const struct pmbus_driver_info *info = pmbus_get_driver_info(client);
	struct zl6100_data *data = to_zl6100_data(info);
	int ret, vreg;

	if (page > 0)
		return -ENXIO;

	switch (reg) {
	case PMBUS_VIRT_VMON_OV_WARN_LIMIT:
		word = zl6100_d2l(DIV_ROUND_CLOSEST(zl6100_l2d(word) * 10, 9));
		vreg = MFR_VMON_OV_FAULT_LIMIT;
		pmbus_clear_cache(client);
		break;
	case PMBUS_VIRT_VMON_OV_FAULT_LIMIT:
		vreg = MFR_VMON_OV_FAULT_LIMIT;
		pmbus_clear_cache(client);
		break;
	case PMBUS_VIRT_VMON_UV_WARN_LIMIT:
		word = zl6100_d2l(DIV_ROUND_CLOSEST(zl6100_l2d(word) * 10, 11));
		vreg = MFR_VMON_UV_FAULT_LIMIT;
		pmbus_clear_cache(client);
		break;
	case PMBUS_VIRT_VMON_UV_FAULT_LIMIT:
		vreg = MFR_VMON_UV_FAULT_LIMIT;
		pmbus_clear_cache(client);
		break;
	default:
		if (reg >= PMBUS_VIRT_BASE)
			return -ENXIO;
		vreg = reg;
	}

	zl6100_wait(data);
	ret = pmbus_write_word_data(client, page, vreg, word);
	data->access = ktime_get();

	return ret;
}

__attribute__((used)) static int zl6100_write_byte(struct i2c_client *client, int page, u8 value)
{
	const struct pmbus_driver_info *info = pmbus_get_driver_info(client);
	struct zl6100_data *data = to_zl6100_data(info);
	int ret;

	if (page > 0)
		return -ENXIO;

	zl6100_wait(data);
	ret = pmbus_write_byte(client, page, value);
	data->access = ktime_get();

	return ret;
}

__attribute__((used)) static int zl6100_probe(struct i2c_client *client,
			const struct i2c_device_id *id)
{
	int ret;
	struct zl6100_data *data;
	struct pmbus_driver_info *info;
	u8 device_id[I2C_SMBUS_BLOCK_MAX + 1];
	const struct i2c_device_id *mid;

	if (!i2c_check_functionality(client->adapter,
				     I2C_FUNC_SMBUS_READ_WORD_DATA
				     | I2C_FUNC_SMBUS_READ_BLOCK_DATA))
		return -ENODEV;

	ret = i2c_smbus_read_block_data(client, ZL6100_DEVICE_ID,
					device_id);
	if (ret < 0) {
		dev_err(&client->dev, "Failed to read device ID\n");
		return ret;
	}
	device_id[ret] = '\0';
	dev_info(&client->dev, "Device ID %s\n", device_id);

	mid = NULL;
	for (mid = zl6100_id; mid->name[0]; mid++) {
		if (!strncasecmp(mid->name, device_id, strlen(mid->name)))
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

	data = devm_kzalloc(&client->dev, sizeof(struct zl6100_data),
			    GFP_KERNEL);
	if (!data)
		return -ENOMEM;

	data->id = mid->driver_data;

	/*
	 * According to information from the chip vendor, all currently
	 * supported chips are known to require a wait time between I2C
	 * accesses.
	 */
	data->delay = delay;

	/*
	 * Since there was a direct I2C device access above, wait before
	 * accessing the chip again.
	 */
	data->access = ktime_get();
	zl6100_wait(data);

	info = &data->info;

	info->pages = 1;
	info->func[0] = PMBUS_HAVE_VIN | PMBUS_HAVE_STATUS_INPUT
	  | PMBUS_HAVE_VOUT | PMBUS_HAVE_STATUS_VOUT
	  | PMBUS_HAVE_IOUT | PMBUS_HAVE_STATUS_IOUT
	  | PMBUS_HAVE_TEMP | PMBUS_HAVE_STATUS_TEMP;

	/*
	 * ZL2004, ZL9101M, and ZL9117M support monitoring an extra voltage
	 * (VMON for ZL2004, VDRV for ZL9101M and ZL9117M). Report it as vmon.
	 */
	if (data->id == zl2004 || data->id == zl9101 || data->id == zl9117)
		info->func[0] |= PMBUS_HAVE_VMON | PMBUS_HAVE_STATUS_VMON;

	ret = i2c_smbus_read_word_data(client, ZL6100_MFR_CONFIG);
	if (ret < 0)
		return ret;

	if (ret & ZL6100_MFR_XTEMP_ENABLE)
		info->func[0] |= PMBUS_HAVE_TEMP2;

	data->access = ktime_get();
	zl6100_wait(data);

	info->read_word_data = zl6100_read_word_data;
	info->read_byte_data = zl6100_read_byte_data;
	info->write_word_data = zl6100_write_word_data;
	info->write_byte = zl6100_write_byte;

	return pmbus_do_probe(client, mid, info);
}

