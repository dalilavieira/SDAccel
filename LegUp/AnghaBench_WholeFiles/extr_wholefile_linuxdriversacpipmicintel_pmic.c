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
typedef  int u64 ;
typedef  int u32 ;
struct regmap {int dummy; } ;
struct pmic_table {int address; int reg; int bit; } ;
struct intel_pmic_opregion_data {int power_table_count; int (* get_power ) (struct regmap*,int,int,int*) ;int (* update_power ) (struct regmap*,int,int,int) ;int (* get_raw_temp ) (struct regmap*,int) ;int (* update_aux ) (struct regmap*,int,int) ;int (* get_policy ) (struct regmap*,int,int,int*) ;int (* update_policy ) (struct regmap*,int,int,int) ;int thermal_table_count; struct pmic_table* thermal_table; struct pmic_table* power_table; } ;
struct TYPE_2__ {int addr; int val; } ;
struct intel_pmic_opregion {scalar_t__ lpat_table; struct intel_pmic_opregion_data* data; struct regmap* regmap; int /*<<< orphan*/  lock; TYPE_1__ ctx; } ;
struct device {int dummy; } ;
typedef  int /*<<< orphan*/  acpi_status ;
typedef  int acpi_physical_address ;
typedef  int /*<<< orphan*/  acpi_handle ;

/* Variables and functions */
 scalar_t__ ACPI_FAILURE (int /*<<< orphan*/ ) ; 
 int ACPI_READ ; 
 int ACPI_WRITE ; 
 int /*<<< orphan*/  AE_BAD_PARAMETER ; 
 int /*<<< orphan*/  AE_ERROR ; 
 int /*<<< orphan*/  AE_OK ; 
 int EINVAL ; 
 int ENODEV ; 
 int ENOENT ; 
 int ENOMEM ; 
 int ENXIO ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int /*<<< orphan*/  PMIC_POWER_OPREGION_ID ; 
 int /*<<< orphan*/  PMIC_REGS_OPREGION_ID ; 
 int /*<<< orphan*/  PMIC_THERMAL_OPREGION_ID ; 
 int /*<<< orphan*/  acpi_install_address_space_handler (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/  (*) (int,int,int,int*,void*,void*),int /*<<< orphan*/ *,struct intel_pmic_opregion*) ; 
 int /*<<< orphan*/  acpi_lpat_free_conversion_table (scalar_t__) ; 
 scalar_t__ acpi_lpat_get_conversion_table (int /*<<< orphan*/ ) ; 
 int acpi_lpat_raw_to_temp (scalar_t__,int) ; 
 int acpi_lpat_temp_to_raw (scalar_t__,int) ; 
 int /*<<< orphan*/  acpi_remove_address_space_handler (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/  (*) (int,int,int,int*,void*,void*)) ; 
 struct intel_pmic_opregion* devm_kzalloc (struct device*,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  memset (TYPE_1__*,int,int) ; 
 int /*<<< orphan*/  mutex_init (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 int regmap_read (struct regmap*,int,int*) ; 
 int regmap_write (struct regmap*,int,int) ; 
 int stub1 (struct regmap*,int,int,int*) ; 
 int stub2 (struct regmap*,int,int,int) ; 
 int stub3 (struct regmap*,int) ; 
 int stub4 (struct regmap*,int,int) ; 
 int stub5 (struct regmap*,int,int,int*) ; 
 int stub6 (struct regmap*,int,int,int) ; 

__attribute__((used)) static int pmic_get_reg_bit(int address, struct pmic_table *table,
			    int count, int *reg, int *bit)
{
	int i;

	for (i = 0; i < count; i++) {
		if (table[i].address == address) {
			*reg = table[i].reg;
			if (bit)
				*bit = table[i].bit;
			return 0;
		}
	}
	return -ENOENT;
}

__attribute__((used)) static acpi_status intel_pmic_power_handler(u32 function,
		acpi_physical_address address, u32 bits, u64 *value64,
		void *handler_context, void *region_context)
{
	struct intel_pmic_opregion *opregion = region_context;
	struct regmap *regmap = opregion->regmap;
	struct intel_pmic_opregion_data *d = opregion->data;
	int reg, bit, result;

	if (bits != 32 || !value64)
		return AE_BAD_PARAMETER;

	if (function == ACPI_WRITE && !(*value64 == 0 || *value64 == 1))
		return AE_BAD_PARAMETER;

	result = pmic_get_reg_bit(address, d->power_table,
				  d->power_table_count, &reg, &bit);
	if (result == -ENOENT)
		return AE_BAD_PARAMETER;

	mutex_lock(&opregion->lock);

	result = function == ACPI_READ ?
		d->get_power(regmap, reg, bit, value64) :
		d->update_power(regmap, reg, bit, *value64 == 1);

	mutex_unlock(&opregion->lock);

	return result ? AE_ERROR : AE_OK;
}

__attribute__((used)) static int pmic_read_temp(struct intel_pmic_opregion *opregion,
			  int reg, u64 *value)
{
	int raw_temp, temp;

	if (!opregion->data->get_raw_temp)
		return -ENXIO;

	raw_temp = opregion->data->get_raw_temp(opregion->regmap, reg);
	if (raw_temp < 0)
		return raw_temp;

	if (!opregion->lpat_table) {
		*value = raw_temp;
		return 0;
	}

	temp = acpi_lpat_raw_to_temp(opregion->lpat_table, raw_temp);
	if (temp < 0)
		return temp;

	*value = temp;
	return 0;
}

__attribute__((used)) static int pmic_thermal_temp(struct intel_pmic_opregion *opregion, int reg,
			     u32 function, u64 *value)
{
	return function == ACPI_READ ?
		pmic_read_temp(opregion, reg, value) : -EINVAL;
}

__attribute__((used)) static int pmic_thermal_aux(struct intel_pmic_opregion *opregion, int reg,
			    u32 function, u64 *value)
{
	int raw_temp;

	if (function == ACPI_READ)
		return pmic_read_temp(opregion, reg, value);

	if (!opregion->data->update_aux)
		return -ENXIO;

	if (opregion->lpat_table) {
		raw_temp = acpi_lpat_temp_to_raw(opregion->lpat_table, *value);
		if (raw_temp < 0)
			return raw_temp;
	} else {
		raw_temp = *value;
	}

	return opregion->data->update_aux(opregion->regmap, reg, raw_temp);
}

__attribute__((used)) static int pmic_thermal_pen(struct intel_pmic_opregion *opregion, int reg,
			    int bit, u32 function, u64 *value)
{
	struct intel_pmic_opregion_data *d = opregion->data;
	struct regmap *regmap = opregion->regmap;

	if (!d->get_policy || !d->update_policy)
		return -ENXIO;

	if (function == ACPI_READ)
		return d->get_policy(regmap, reg, bit, value);

	if (*value != 0 && *value != 1)
		return -EINVAL;

	return d->update_policy(regmap, reg, bit, *value);
}

__attribute__((used)) static bool pmic_thermal_is_temp(int address)
{
	return (address <= 0x3c) && !(address % 12);
}

__attribute__((used)) static bool pmic_thermal_is_aux(int address)
{
	return (address >= 4 && address <= 0x40 && !((address - 4) % 12)) ||
	       (address >= 8 && address <= 0x44 && !((address - 8) % 12));
}

__attribute__((used)) static bool pmic_thermal_is_pen(int address)
{
	return address >= 0x48 && address <= 0x5c;
}

__attribute__((used)) static acpi_status intel_pmic_thermal_handler(u32 function,
		acpi_physical_address address, u32 bits, u64 *value64,
		void *handler_context, void *region_context)
{
	struct intel_pmic_opregion *opregion = region_context;
	struct intel_pmic_opregion_data *d = opregion->data;
	int reg, bit, result;

	if (bits != 32 || !value64)
		return AE_BAD_PARAMETER;

	result = pmic_get_reg_bit(address, d->thermal_table,
				  d->thermal_table_count, &reg, &bit);
	if (result == -ENOENT)
		return AE_BAD_PARAMETER;

	mutex_lock(&opregion->lock);

	if (pmic_thermal_is_temp(address))
		result = pmic_thermal_temp(opregion, reg, function, value64);
	else if (pmic_thermal_is_aux(address))
		result = pmic_thermal_aux(opregion, reg, function, value64);
	else if (pmic_thermal_is_pen(address))
		result = pmic_thermal_pen(opregion, reg, bit,
						function, value64);
	else
		result = -EINVAL;

	mutex_unlock(&opregion->lock);

	if (result < 0) {
		if (result == -EINVAL)
			return AE_BAD_PARAMETER;
		else
			return AE_ERROR;
	}

	return AE_OK;
}

__attribute__((used)) static acpi_status intel_pmic_regs_handler(u32 function,
		acpi_physical_address address, u32 bits, u64 *value64,
		void *handler_context, void *region_context)
{
	struct intel_pmic_opregion *opregion = region_context;
	int result = 0;

	switch (address) {
	case 0:
		return AE_OK;
	case 1:
		opregion->ctx.addr |= (*value64 & 0xff) << 8;
		return AE_OK;
	case 2:
		opregion->ctx.addr |= *value64 & 0xff;
		return AE_OK;
	case 3:
		opregion->ctx.val = *value64 & 0xff;
		return AE_OK;
	case 4:
		if (*value64) {
			result = regmap_write(opregion->regmap, opregion->ctx.addr,
					      opregion->ctx.val);
		} else {
			result = regmap_read(opregion->regmap, opregion->ctx.addr,
					     &opregion->ctx.val);
			if (result == 0)
				*value64 = opregion->ctx.val;
		}
		memset(&opregion->ctx, 0x00, sizeof(opregion->ctx));
	}

	if (result < 0) {
		if (result == -EINVAL)
			return AE_BAD_PARAMETER;
		else
			return AE_ERROR;
	}

	return AE_OK;
}

int intel_pmic_install_opregion_handler(struct device *dev, acpi_handle handle,
					struct regmap *regmap,
					struct intel_pmic_opregion_data *d)
{
	acpi_status status;
	struct intel_pmic_opregion *opregion;
	int ret;

	if (!dev || !regmap || !d)
		return -EINVAL;

	if (!handle)
		return -ENODEV;

	opregion = devm_kzalloc(dev, sizeof(*opregion), GFP_KERNEL);
	if (!opregion)
		return -ENOMEM;

	mutex_init(&opregion->lock);
	opregion->regmap = regmap;
	opregion->lpat_table = acpi_lpat_get_conversion_table(handle);

	status = acpi_install_address_space_handler(handle,
						    PMIC_POWER_OPREGION_ID,
						    intel_pmic_power_handler,
						    NULL, opregion);
	if (ACPI_FAILURE(status)) {
		ret = -ENODEV;
		goto out_error;
	}

	status = acpi_install_address_space_handler(handle,
						    PMIC_THERMAL_OPREGION_ID,
						    intel_pmic_thermal_handler,
						    NULL, opregion);
	if (ACPI_FAILURE(status)) {
		acpi_remove_address_space_handler(handle, PMIC_POWER_OPREGION_ID,
						  intel_pmic_power_handler);
		ret = -ENODEV;
		goto out_remove_power_handler;
	}

	status = acpi_install_address_space_handler(handle,
			PMIC_REGS_OPREGION_ID, intel_pmic_regs_handler, NULL,
			opregion);
	if (ACPI_FAILURE(status)) {
		ret = -ENODEV;
		goto out_remove_thermal_handler;
	}

	opregion->data = d;
	return 0;

out_remove_thermal_handler:
	acpi_remove_address_space_handler(handle, PMIC_THERMAL_OPREGION_ID,
					  intel_pmic_thermal_handler);

out_remove_power_handler:
	acpi_remove_address_space_handler(handle, PMIC_POWER_OPREGION_ID,
					  intel_pmic_power_handler);

out_error:
	acpi_lpat_free_conversion_table(opregion->lpat_table);
	return ret;
}

