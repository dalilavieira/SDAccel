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
typedef  int u64 ;
typedef  int u32 ;
struct tps68470_pmic_table {int reg; int bitmask; } ;
struct tps68470_pmic_opregion {int /*<<< orphan*/  lock; struct regmap* regmap; } ;
struct regmap {int dummy; } ;
struct device {int /*<<< orphan*/  parent; } ;
struct platform_device {struct device dev; } ;
typedef  int /*<<< orphan*/  acpi_status ;
typedef  int acpi_physical_address ;
typedef  int /*<<< orphan*/  acpi_handle ;

/* Variables and functions */
 scalar_t__ ACPI_FAILURE (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ACPI_HANDLE (int /*<<< orphan*/ ) ; 
 int ACPI_READ ; 
 int ACPI_WRITE ; 
 int /*<<< orphan*/  AE_BAD_PARAMETER ; 
 int /*<<< orphan*/  AE_ERROR ; 
 int /*<<< orphan*/  AE_OK ; 
 unsigned int ARRAY_SIZE (struct tps68470_pmic_table*) ; 
 int EINVAL ; 
 int EIO ; 
 int ENODEV ; 
 int ENOENT ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int /*<<< orphan*/  TI_PMIC_CLKFREQ_OPREGION_ID ; 
 int /*<<< orphan*/  TI_PMIC_CLOCK_OPREGION_ID ; 
 int /*<<< orphan*/  TI_PMIC_POWER_OPREGION_ID ; 
 int /*<<< orphan*/  TI_PMIC_VR_VAL_OPREGION_ID ; 
 int /*<<< orphan*/  acpi_install_address_space_handler (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/  (*) (int,int,int,int*,void*,void*),int /*<<< orphan*/ *,struct tps68470_pmic_opregion*) ; 
 int /*<<< orphan*/  acpi_remove_address_space_handler (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/  (*) (int,int,int,int*,void*,void*)) ; 
 struct tps68470_pmic_table* clk_freq_table ; 
 struct tps68470_pmic_table* clk_table ; 
 struct regmap* dev_get_drvdata (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  dev_warn (struct device*,char*) ; 
 struct tps68470_pmic_opregion* devm_kzalloc (struct device*,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mutex_destroy (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_init (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 struct tps68470_pmic_table* power_table ; 
 scalar_t__ regmap_read (struct regmap*,int,unsigned int*) ; 
 int regmap_update_bits (struct regmap*,int,int,int) ; 
 struct tps68470_pmic_table* vr_val_table ; 

__attribute__((used)) static int pmic_get_reg_bit(u64 address,
			    const struct tps68470_pmic_table *table,
			    const unsigned int table_size, int *reg,
			    int *bitmask)
{
	u64 i;

	i = address / 4;
	if (i >= table_size)
		return -ENOENT;

	if (!reg || !bitmask)
		return -EINVAL;

	*reg = table[i].reg;
	*bitmask = table[i].bitmask;

	return 0;
}

__attribute__((used)) static int tps68470_pmic_get_power(struct regmap *regmap, int reg,
				       int bitmask, u64 *value)
{
	unsigned int data;

	if (regmap_read(regmap, reg, &data))
		return -EIO;

	*value = (data & bitmask) ? 1 : 0;
	return 0;
}

__attribute__((used)) static int tps68470_pmic_get_vr_val(struct regmap *regmap, int reg,
				       int bitmask, u64 *value)
{
	unsigned int data;

	if (regmap_read(regmap, reg, &data))
		return -EIO;

	*value = data & bitmask;
	return 0;
}

__attribute__((used)) static int tps68470_pmic_get_clk(struct regmap *regmap, int reg,
				       int bitmask, u64 *value)
{
	unsigned int data;

	if (regmap_read(regmap, reg, &data))
		return -EIO;

	*value = (data & bitmask) ? 1 : 0;
	return 0;
}

__attribute__((used)) static int tps68470_pmic_get_clk_freq(struct regmap *regmap, int reg,
				       int bitmask, u64 *value)
{
	unsigned int data;

	if (regmap_read(regmap, reg, &data))
		return -EIO;

	*value = data & bitmask;
	return 0;
}

__attribute__((used)) static int ti_tps68470_regmap_update_bits(struct regmap *regmap, int reg,
					int bitmask, u64 value)
{
	return regmap_update_bits(regmap, reg, bitmask, value);
}

__attribute__((used)) static acpi_status tps68470_pmic_common_handler(u32 function,
					  acpi_physical_address address,
					  u32 bits, u64 *value,
					  void *region_context,
					  int (*get)(struct regmap *,
						     int, int, u64 *),
					  int (*update)(struct regmap *,
							int, int, u64),
					  const struct tps68470_pmic_table *tbl,
					  unsigned int tbl_size)
{
	struct tps68470_pmic_opregion *opregion = region_context;
	struct regmap *regmap = opregion->regmap;
	int reg, ret, bitmask;

	if (bits != 32)
		return AE_BAD_PARAMETER;

	ret = pmic_get_reg_bit(address, tbl, tbl_size, &reg, &bitmask);
	if (ret < 0)
		return AE_BAD_PARAMETER;

	if (function == ACPI_WRITE && *value > bitmask)
		return AE_BAD_PARAMETER;

	mutex_lock(&opregion->lock);

	ret = (function == ACPI_READ) ?
		get(regmap, reg, bitmask, value) :
		update(regmap, reg, bitmask, *value);

	mutex_unlock(&opregion->lock);

	return ret ? AE_ERROR : AE_OK;
}

__attribute__((used)) static acpi_status tps68470_pmic_cfreq_handler(u32 function,
					    acpi_physical_address address,
					    u32 bits, u64 *value,
					    void *handler_context,
					    void *region_context)
{
	return tps68470_pmic_common_handler(function, address, bits, value,
				region_context,
				tps68470_pmic_get_clk_freq,
				ti_tps68470_regmap_update_bits,
				clk_freq_table,
				ARRAY_SIZE(clk_freq_table));
}

__attribute__((used)) static acpi_status tps68470_pmic_clk_handler(u32 function,
				       acpi_physical_address address, u32 bits,
				       u64 *value, void *handler_context,
				       void *region_context)
{
	return tps68470_pmic_common_handler(function, address, bits, value,
				region_context,
				tps68470_pmic_get_clk,
				ti_tps68470_regmap_update_bits,
				clk_table,
				ARRAY_SIZE(clk_table));
}

__attribute__((used)) static acpi_status tps68470_pmic_vrval_handler(u32 function,
					  acpi_physical_address address,
					  u32 bits, u64 *value,
					  void *handler_context,
					  void *region_context)
{
	return tps68470_pmic_common_handler(function, address, bits, value,
				region_context,
				tps68470_pmic_get_vr_val,
				ti_tps68470_regmap_update_bits,
				vr_val_table,
				ARRAY_SIZE(vr_val_table));
}

__attribute__((used)) static acpi_status tps68470_pmic_pwr_handler(u32 function,
					 acpi_physical_address address,
					 u32 bits, u64 *value,
					 void *handler_context,
					 void *region_context)
{
	if (bits != 32)
		return AE_BAD_PARAMETER;

	/* set/clear for bit 0, bits 0 and 1 together */
	if (function == ACPI_WRITE &&
	    !(*value == 0 || *value == 1 || *value == 3)) {
		return AE_BAD_PARAMETER;
	}

	return tps68470_pmic_common_handler(function, address, bits, value,
				region_context,
				tps68470_pmic_get_power,
				ti_tps68470_regmap_update_bits,
				power_table,
				ARRAY_SIZE(power_table));
}

__attribute__((used)) static int tps68470_pmic_opregion_probe(struct platform_device *pdev)
{
	struct regmap *tps68470_regmap = dev_get_drvdata(pdev->dev.parent);
	acpi_handle handle = ACPI_HANDLE(pdev->dev.parent);
	struct device *dev = &pdev->dev;
	struct tps68470_pmic_opregion *opregion;
	acpi_status status;

	if (!dev || !tps68470_regmap) {
		dev_warn(dev, "dev or regmap is NULL\n");
		return -EINVAL;
	}

	if (!handle) {
		dev_warn(dev, "acpi handle is NULL\n");
		return -ENODEV;
	}

	opregion = devm_kzalloc(dev, sizeof(*opregion), GFP_KERNEL);
	if (!opregion)
		return -ENOMEM;

	mutex_init(&opregion->lock);
	opregion->regmap = tps68470_regmap;

	status = acpi_install_address_space_handler(handle,
						    TI_PMIC_POWER_OPREGION_ID,
						    tps68470_pmic_pwr_handler,
						    NULL, opregion);
	if (ACPI_FAILURE(status))
		goto out_mutex_destroy;

	status = acpi_install_address_space_handler(handle,
						    TI_PMIC_VR_VAL_OPREGION_ID,
						    tps68470_pmic_vrval_handler,
						    NULL, opregion);
	if (ACPI_FAILURE(status))
		goto out_remove_power_handler;

	status = acpi_install_address_space_handler(handle,
						    TI_PMIC_CLOCK_OPREGION_ID,
						    tps68470_pmic_clk_handler,
						    NULL, opregion);
	if (ACPI_FAILURE(status))
		goto out_remove_vr_val_handler;

	status = acpi_install_address_space_handler(handle,
						    TI_PMIC_CLKFREQ_OPREGION_ID,
						    tps68470_pmic_cfreq_handler,
						    NULL, opregion);
	if (ACPI_FAILURE(status))
		goto out_remove_clk_handler;

	return 0;

out_remove_clk_handler:
	acpi_remove_address_space_handler(handle, TI_PMIC_CLOCK_OPREGION_ID,
					  tps68470_pmic_clk_handler);
out_remove_vr_val_handler:
	acpi_remove_address_space_handler(handle, TI_PMIC_VR_VAL_OPREGION_ID,
					  tps68470_pmic_vrval_handler);
out_remove_power_handler:
	acpi_remove_address_space_handler(handle, TI_PMIC_POWER_OPREGION_ID,
					  tps68470_pmic_pwr_handler);
out_mutex_destroy:
	mutex_destroy(&opregion->lock);
	return -ENODEV;
}

