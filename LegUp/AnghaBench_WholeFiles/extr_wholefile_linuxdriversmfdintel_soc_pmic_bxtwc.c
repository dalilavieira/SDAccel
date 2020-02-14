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
typedef  unsigned int u8 ;
typedef  int /*<<< orphan*/  u32 ;
struct regmap_irq_chip_data {int dummy; } ;
struct regmap_irq_chip {int /*<<< orphan*/  name; } ;
struct device {int /*<<< orphan*/  kobj; } ;
struct platform_device {struct device dev; } ;
struct intel_soc_pmic {int irq; int /*<<< orphan*/  regmap; struct regmap_irq_chip_data* irq_chip_data_crit; struct regmap_irq_chip_data* irq_chip_data; struct regmap_irq_chip_data* irq_chip_data_chgr; struct regmap_irq_chip_data* irq_chip_data_adc; struct regmap_irq_chip_data* irq_chip_data_bcu; struct regmap_irq_chip_data* irq_chip_data_tmu; struct device* dev; } ;
struct device_attribute {int dummy; } ;
typedef  int ssize_t ;
typedef  int /*<<< orphan*/  ipc_in ;
typedef  int /*<<< orphan*/  acpi_status ;
typedef  int /*<<< orphan*/  acpi_handle ;

/* Variables and functions */
 scalar_t__ ACPI_FAILURE (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ACPI_HANDLE (struct device*) ; 
 int /*<<< orphan*/  ARRAY_SIZE (int /*<<< orphan*/ ) ; 
 unsigned long long BROXTON_PMIC_WC_HRV ; 
 int BXTWC_ADC_LVL1_IRQ ; 
 int BXTWC_BCU_LVL1_IRQ ; 
 int BXTWC_CHGR_LVL1_IRQ ; 
 int BXTWC_CRIT_LVL1_IRQ ; 
 int BXTWC_DEVICE1_ADDR ; 
 int /*<<< orphan*/  BXTWC_MIRQLVL1 ; 
 int /*<<< orphan*/  BXTWC_MIRQLVL1_MCHGR ; 
 int BXTWC_TMU_LVL1_IRQ ; 
 int EINVAL ; 
 int EIO ; 
 int ENODEV ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int IRQF_ONESHOT ; 
 int IRQF_SHARED ; 
 scalar_t__ IS_ERR (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  PLATFORM_DEVID_NONE ; 
 int /*<<< orphan*/  PMC_IPC_PMIC_ACCESS ; 
 int /*<<< orphan*/  PMC_IPC_PMIC_ACCESS_READ ; 
 int /*<<< orphan*/  PMC_IPC_PMIC_ACCESS_WRITE ; 
 int PTR_ERR (int /*<<< orphan*/ ) ; 
 unsigned int REG_ADDR_MASK ; 
 unsigned int REG_ADDR_SHIFT ; 
 unsigned int REG_OFFSET_MASK ; 
 int /*<<< orphan*/  acpi_evaluate_integer (int /*<<< orphan*/ ,char*,int /*<<< orphan*/ *,unsigned long long*) ; 
 int /*<<< orphan*/  bxt_wc_dev ; 
 int /*<<< orphan*/  bxtwc_group ; 
 int bxtwc_reg_addr ; 
 int /*<<< orphan*/  bxtwc_regmap_config ; 
 struct regmap_irq_chip const bxtwc_regmap_irq_chip ; 
 struct regmap_irq_chip bxtwc_regmap_irq_chip_adc ; 
 struct regmap_irq_chip bxtwc_regmap_irq_chip_bcu ; 
 struct regmap_irq_chip bxtwc_regmap_irq_chip_chgr ; 
 struct regmap_irq_chip bxtwc_regmap_irq_chip_crit ; 
 struct regmap_irq_chip bxtwc_regmap_irq_chip_tmu ; 
 int /*<<< orphan*/  dev_err (struct device*,char*,...) ; 
 struct intel_soc_pmic* dev_get_drvdata (struct device*) ; 
 int /*<<< orphan*/  dev_set_drvdata (struct device*,struct intel_soc_pmic*) ; 
 struct intel_soc_pmic* devm_kzalloc (struct device*,int,int /*<<< orphan*/ ) ; 
 int devm_mfd_add_devices (struct device*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int devm_regmap_add_irq_chip (struct device*,int /*<<< orphan*/ ,int,int,int /*<<< orphan*/ ,struct regmap_irq_chip const*,struct regmap_irq_chip_data**) ; 
 int /*<<< orphan*/  devm_regmap_init (struct device*,int /*<<< orphan*/ *,struct intel_soc_pmic*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  disable_irq (int) ; 
 int intel_pmc_ipc_command (int /*<<< orphan*/ ,int /*<<< orphan*/ ,unsigned int*,int,int /*<<< orphan*/ *,int) ; 
 int kstrtouint (char const*,int /*<<< orphan*/ ,unsigned int*) ; 
 scalar_t__ kstrtoul (char const*,int /*<<< orphan*/ ,int*) ; 
 int platform_get_irq (struct platform_device*,int /*<<< orphan*/ ) ; 
 int regmap_irq_get_virq (struct regmap_irq_chip_data*,int) ; 
 int regmap_read (int /*<<< orphan*/ ,int,unsigned int*) ; 
 int /*<<< orphan*/  regmap_update_bits (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int regmap_write (int /*<<< orphan*/ ,int,unsigned int) ; 
 int sprintf (char*,char*,unsigned int) ; 
 int sysfs_create_group (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  sysfs_remove_group (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 

__attribute__((used)) static int regmap_ipc_byte_reg_read(void *context, unsigned int reg,
				    unsigned int *val)
{
	int ret;
	int i2c_addr;
	u8 ipc_in[2];
	u8 ipc_out[4];
	struct intel_soc_pmic *pmic = context;

	if (!pmic)
		return -EINVAL;

	if (reg & REG_ADDR_MASK)
		i2c_addr = (reg & REG_ADDR_MASK) >> REG_ADDR_SHIFT;
	else
		i2c_addr = BXTWC_DEVICE1_ADDR;

	reg &= REG_OFFSET_MASK;

	ipc_in[0] = reg;
	ipc_in[1] = i2c_addr;
	ret = intel_pmc_ipc_command(PMC_IPC_PMIC_ACCESS,
			PMC_IPC_PMIC_ACCESS_READ,
			ipc_in, sizeof(ipc_in), (u32 *)ipc_out, 1);
	if (ret) {
		dev_err(pmic->dev, "Failed to read from PMIC\n");
		return ret;
	}
	*val = ipc_out[0];

	return 0;
}

__attribute__((used)) static int regmap_ipc_byte_reg_write(void *context, unsigned int reg,
				       unsigned int val)
{
	int ret;
	int i2c_addr;
	u8 ipc_in[3];
	struct intel_soc_pmic *pmic = context;

	if (!pmic)
		return -EINVAL;

	if (reg & REG_ADDR_MASK)
		i2c_addr = (reg & REG_ADDR_MASK) >> REG_ADDR_SHIFT;
	else
		i2c_addr = BXTWC_DEVICE1_ADDR;

	reg &= REG_OFFSET_MASK;

	ipc_in[0] = reg;
	ipc_in[1] = i2c_addr;
	ipc_in[2] = val;
	ret = intel_pmc_ipc_command(PMC_IPC_PMIC_ACCESS,
			PMC_IPC_PMIC_ACCESS_WRITE,
			ipc_in, sizeof(ipc_in), NULL, 0);
	if (ret) {
		dev_err(pmic->dev, "Failed to write to PMIC\n");
		return ret;
	}

	return 0;
}

__attribute__((used)) static ssize_t bxtwc_reg_show(struct device *dev,
		struct device_attribute *attr, char *buf)
{
	return sprintf(buf, "0x%lx\n", bxtwc_reg_addr);
}

__attribute__((used)) static ssize_t bxtwc_reg_store(struct device *dev,
	struct device_attribute *attr, const char *buf, size_t count)
{
	if (kstrtoul(buf, 0, &bxtwc_reg_addr)) {
		dev_err(dev, "Invalid register address\n");
		return -EINVAL;
	}
	return (ssize_t)count;
}

__attribute__((used)) static ssize_t bxtwc_val_show(struct device *dev,
		struct device_attribute *attr, char *buf)
{
	int ret;
	unsigned int val;
	struct intel_soc_pmic *pmic = dev_get_drvdata(dev);

	ret = regmap_read(pmic->regmap, bxtwc_reg_addr, &val);
	if (ret < 0) {
		dev_err(dev, "Failed to read 0x%lx\n", bxtwc_reg_addr);
		return -EIO;
	}

	return sprintf(buf, "0x%02x\n", val);
}

__attribute__((used)) static ssize_t bxtwc_val_store(struct device *dev,
	struct device_attribute *attr, const char *buf, size_t count)
{
	int ret;
	unsigned int val;
	struct intel_soc_pmic *pmic = dev_get_drvdata(dev);

	ret = kstrtouint(buf, 0, &val);
	if (ret)
		return ret;

	ret = regmap_write(pmic->regmap, bxtwc_reg_addr, val);
	if (ret) {
		dev_err(dev, "Failed to write value 0x%02x to address 0x%lx",
			val, bxtwc_reg_addr);
		return -EIO;
	}
	return count;
}

__attribute__((used)) static int bxtwc_add_chained_irq_chip(struct intel_soc_pmic *pmic,
				struct regmap_irq_chip_data *pdata,
				int pirq, int irq_flags,
				const struct regmap_irq_chip *chip,
				struct regmap_irq_chip_data **data)
{
	int irq;

	irq = regmap_irq_get_virq(pdata, pirq);
	if (irq < 0) {
		dev_err(pmic->dev,
			"Failed to get parent vIRQ(%d) for chip %s, ret:%d\n",
			pirq, chip->name, irq);
		return irq;
	}

	return devm_regmap_add_irq_chip(pmic->dev, pmic->regmap, irq, irq_flags,
					0, chip, data);
}

__attribute__((used)) static int bxtwc_probe(struct platform_device *pdev)
{
	int ret;
	acpi_handle handle;
	acpi_status status;
	unsigned long long hrv;
	struct intel_soc_pmic *pmic;

	handle = ACPI_HANDLE(&pdev->dev);
	status = acpi_evaluate_integer(handle, "_HRV", NULL, &hrv);
	if (ACPI_FAILURE(status)) {
		dev_err(&pdev->dev, "Failed to get PMIC hardware revision\n");
		return -ENODEV;
	}
	if (hrv != BROXTON_PMIC_WC_HRV) {
		dev_err(&pdev->dev, "Invalid PMIC hardware revision: %llu\n",
			hrv);
		return -ENODEV;
	}

	pmic = devm_kzalloc(&pdev->dev, sizeof(*pmic), GFP_KERNEL);
	if (!pmic)
		return -ENOMEM;

	ret = platform_get_irq(pdev, 0);
	if (ret < 0) {
		dev_err(&pdev->dev, "Invalid IRQ\n");
		return ret;
	}
	pmic->irq = ret;

	dev_set_drvdata(&pdev->dev, pmic);
	pmic->dev = &pdev->dev;

	pmic->regmap = devm_regmap_init(&pdev->dev, NULL, pmic,
					&bxtwc_regmap_config);
	if (IS_ERR(pmic->regmap)) {
		ret = PTR_ERR(pmic->regmap);
		dev_err(&pdev->dev, "Failed to initialise regmap: %d\n", ret);
		return ret;
	}

	ret = devm_regmap_add_irq_chip(&pdev->dev, pmic->regmap, pmic->irq,
				       IRQF_ONESHOT | IRQF_SHARED,
				       0, &bxtwc_regmap_irq_chip,
				       &pmic->irq_chip_data);
	if (ret) {
		dev_err(&pdev->dev, "Failed to add IRQ chip\n");
		return ret;
	}

	ret = bxtwc_add_chained_irq_chip(pmic, pmic->irq_chip_data,
					 BXTWC_TMU_LVL1_IRQ,
					 IRQF_ONESHOT,
					 &bxtwc_regmap_irq_chip_tmu,
					 &pmic->irq_chip_data_tmu);
	if (ret) {
		dev_err(&pdev->dev, "Failed to add TMU IRQ chip\n");
		return ret;
	}

	/* Add chained IRQ handler for BCU IRQs */
	ret = bxtwc_add_chained_irq_chip(pmic, pmic->irq_chip_data,
					 BXTWC_BCU_LVL1_IRQ,
					 IRQF_ONESHOT,
					 &bxtwc_regmap_irq_chip_bcu,
					 &pmic->irq_chip_data_bcu);


	if (ret) {
		dev_err(&pdev->dev, "Failed to add BUC IRQ chip\n");
		return ret;
	}

	/* Add chained IRQ handler for ADC IRQs */
	ret = bxtwc_add_chained_irq_chip(pmic, pmic->irq_chip_data,
					 BXTWC_ADC_LVL1_IRQ,
					 IRQF_ONESHOT,
					 &bxtwc_regmap_irq_chip_adc,
					 &pmic->irq_chip_data_adc);


	if (ret) {
		dev_err(&pdev->dev, "Failed to add ADC IRQ chip\n");
		return ret;
	}

	/* Add chained IRQ handler for CHGR IRQs */
	ret = bxtwc_add_chained_irq_chip(pmic, pmic->irq_chip_data,
					 BXTWC_CHGR_LVL1_IRQ,
					 IRQF_ONESHOT,
					 &bxtwc_regmap_irq_chip_chgr,
					 &pmic->irq_chip_data_chgr);


	if (ret) {
		dev_err(&pdev->dev, "Failed to add CHGR IRQ chip\n");
		return ret;
	}

	/* Add chained IRQ handler for CRIT IRQs */
	ret = bxtwc_add_chained_irq_chip(pmic, pmic->irq_chip_data,
					 BXTWC_CRIT_LVL1_IRQ,
					 IRQF_ONESHOT,
					 &bxtwc_regmap_irq_chip_crit,
					 &pmic->irq_chip_data_crit);


	if (ret) {
		dev_err(&pdev->dev, "Failed to add CRIT IRQ chip\n");
		return ret;
	}

	ret = devm_mfd_add_devices(&pdev->dev, PLATFORM_DEVID_NONE, bxt_wc_dev,
				   ARRAY_SIZE(bxt_wc_dev), NULL, 0, NULL);
	if (ret) {
		dev_err(&pdev->dev, "Failed to add devices\n");
		return ret;
	}

	ret = sysfs_create_group(&pdev->dev.kobj, &bxtwc_group);
	if (ret) {
		dev_err(&pdev->dev, "Failed to create sysfs group %d\n", ret);
		return ret;
	}

	/*
	 * There is known hw bug. Upon reset BIT 5 of register
	 * BXTWC_CHGR_LVL1_IRQ is 0 which is the expected value. However,
	 * later it's set to 1(masked) automatically by hardware. So we
	 * have the software workaround here to unmaksed it in order to let
	 * charger interrutp work.
	 */
	regmap_update_bits(pmic->regmap, BXTWC_MIRQLVL1,
				BXTWC_MIRQLVL1_MCHGR, 0);

	return 0;
}

__attribute__((used)) static int bxtwc_remove(struct platform_device *pdev)
{
	sysfs_remove_group(&pdev->dev.kobj, &bxtwc_group);

	return 0;
}

__attribute__((used)) static void bxtwc_shutdown(struct platform_device *pdev)
{
	struct intel_soc_pmic *pmic = dev_get_drvdata(&pdev->dev);

	disable_irq(pmic->irq);
}

