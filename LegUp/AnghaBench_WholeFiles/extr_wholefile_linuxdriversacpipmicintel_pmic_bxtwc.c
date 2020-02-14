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
typedef  size_t u8 ;
typedef  int u64 ;
typedef  int u32 ;
typedef  size_t u16 ;
struct regmap {int dummy; } ;
struct TYPE_2__ {int /*<<< orphan*/  parent; } ;
struct platform_device {TYPE_1__ dev; } ;
struct intel_soc_pmic {int /*<<< orphan*/  regmap; } ;

/* Variables and functions */
 int /*<<< orphan*/  ACPI_HANDLE (int /*<<< orphan*/ ) ; 
 size_t BIT (int) ; 
 int EIO ; 
 size_t WHISKEY_COVE_ADC_CURSRC (size_t) ; 
 size_t WHISKEY_COVE_ADC_HIGH_BIT (size_t) ; 
 size_t WHISKEY_COVE_ALRT_HIGH_BIT_MASK ; 
 size_t clamp_t (int /*<<< orphan*/ ,size_t,int /*<<< orphan*/ ,int) ; 
 struct intel_soc_pmic* dev_get_drvdata (int /*<<< orphan*/ ) ; 
 size_t fls (int) ; 
 int /*<<< orphan*/  intel_bxtwc_pmic_opregion_data ; 
 int intel_pmic_install_opregion_handler (TYPE_1__*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 scalar_t__ regmap_read (struct regmap*,int,...) ; 
 int regmap_update_bits (struct regmap*,int,size_t,size_t) ; 
 int regmap_write (struct regmap*,int,size_t) ; 
 int /*<<< orphan*/  s8 ; 

__attribute__((used)) static int intel_bxtwc_pmic_get_power(struct regmap *regmap, int reg,
		int bit, u64 *value)
{
	int data;

	if (regmap_read(regmap, reg, &data))
		return -EIO;

	*value = (data & bit) ? 1 : 0;
	return 0;
}

__attribute__((used)) static int intel_bxtwc_pmic_update_power(struct regmap *regmap, int reg,
		int bit, bool on)
{
	u8 val, mask = bit;

	if (on)
		val = 0xFF;
	else
		val = 0x0;

	return regmap_update_bits(regmap, reg, mask, val);
}

__attribute__((used)) static int intel_bxtwc_pmic_get_raw_temp(struct regmap *regmap, int reg)
{
	unsigned int val, adc_val, reg_val;
	u8 temp_l, temp_h, cursrc;
	unsigned long rlsb;
	static const unsigned long rlsb_array[] = {
		0, 260420, 130210, 65100, 32550, 16280,
		8140, 4070, 2030, 0, 260420, 130210 };

	if (regmap_read(regmap, reg, &val))
		return -EIO;
	temp_l = (u8) val;

	if (regmap_read(regmap, (reg - 1), &val))
		return -EIO;
	temp_h = (u8) val;

	reg_val = temp_l | WHISKEY_COVE_ADC_HIGH_BIT(temp_h);
	cursrc = WHISKEY_COVE_ADC_CURSRC(temp_h);
	rlsb = rlsb_array[cursrc];
	adc_val = reg_val * rlsb / 1000;

	return adc_val;
}

__attribute__((used)) static int
intel_bxtwc_pmic_update_aux(struct regmap *regmap, int reg, int raw)
{
	u32 bsr_num;
	u16 resi_val, count = 0, thrsh = 0;
	u8 alrt_h, alrt_l, cursel = 0;

	bsr_num = raw;
	bsr_num /= (1 << 5);

	count = fls(bsr_num) - 1;

	cursel = clamp_t(s8, (count - 7), 0, 7);
	thrsh = raw / (1 << (4 + cursel));

	resi_val = (cursel << 9) | thrsh;
	alrt_h = (resi_val >> 8) & WHISKEY_COVE_ALRT_HIGH_BIT_MASK;
	if (regmap_update_bits(regmap,
				reg - 1,
				WHISKEY_COVE_ALRT_HIGH_BIT_MASK,
				alrt_h))
		return -EIO;

	alrt_l = (u8)resi_val;
	return regmap_write(regmap, reg, alrt_l);
}

__attribute__((used)) static int
intel_bxtwc_pmic_get_policy(struct regmap *regmap, int reg, int bit, u64 *value)
{
	u8 mask = BIT(bit);
	unsigned int val;

	if (regmap_read(regmap, reg, &val))
		return -EIO;

	*value = (val & mask) >> bit;
	return 0;
}

__attribute__((used)) static int
intel_bxtwc_pmic_update_policy(struct regmap *regmap,
				int reg, int bit, int enable)
{
	u8 mask = BIT(bit), val = enable << bit;

	return regmap_update_bits(regmap, reg, mask, val);
}

__attribute__((used)) static int intel_bxtwc_pmic_opregion_probe(struct platform_device *pdev)
{
	struct intel_soc_pmic *pmic = dev_get_drvdata(pdev->dev.parent);

	return intel_pmic_install_opregion_handler(&pdev->dev,
			ACPI_HANDLE(pdev->dev.parent),
			pmic->regmap,
			&intel_bxtwc_pmic_opregion_data);
}

