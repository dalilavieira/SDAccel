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
struct regmap_field {int dummy; } ;
struct reg_field {int reg; } ;
typedef  struct regmap_field opp_table ;
struct device_node {int dummy; } ;
struct device {struct device_node* of_node; } ;
struct TYPE_2__ {struct device* cpu; struct regmap_field* syscfg_eng; struct regmap_field* syscfg; } ;

/* Variables and functions */
 unsigned int BIT (int) ; 
 int DEFAULT_VERSION ; 
 int ENODEV ; 
 int /*<<< orphan*/  HW_INFO_INDEX ; 
 scalar_t__ IS_ERR (struct regmap_field*) ; 
 int /*<<< orphan*/  MAJOR_ID_INDEX ; 
 int MAX_PCODE_NAME_LEN ; 
 int /*<<< orphan*/  MINOR_ID_INDEX ; 
 int PCODE ; 
 int PTR_ERR (struct regmap_field*) ; 
 int SUBSTRATE ; 
 int VERSION_ELEMENTS ; 
 unsigned int VERSION_SHIFT ; 
 TYPE_1__ ddata ; 
 int /*<<< orphan*/  dev_dbg (struct device*,char*,unsigned int,unsigned int,unsigned int,...) ; 
 int /*<<< orphan*/  dev_err (struct device*,char*,...) ; 
 struct regmap_field* dev_pm_opp_set_prop_name (struct device*,char*) ; 
 struct regmap_field* dev_pm_opp_set_supported_hw (struct device*,unsigned int*,int) ; 
 int /*<<< orphan*/  dev_warn (struct device*,char*) ; 
 struct regmap_field* devm_regmap_field_alloc (struct device*,struct regmap_field*,struct reg_field) ; 
 struct device* get_cpu_device (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  of_get_property (struct device_node*,char*,int /*<<< orphan*/ *) ; 
 scalar_t__ of_machine_is_compatible (char*) ; 
 int of_property_read_u32_index (struct device_node*,char*,int /*<<< orphan*/ ,unsigned int*) ; 
 int /*<<< orphan*/  platform_device_register_simple (char*,int,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int regmap_field_read (struct regmap_field*,unsigned int*) ; 
 int regmap_read (struct regmap_field*,unsigned int,unsigned int*) ; 
 int /*<<< orphan*/  snprintf (char*,int,char*,int) ; 
 struct reg_field const* sti_stih407_dvfs_regfields ; 
 void* syscon_regmap_lookup_by_phandle (struct device_node*,char*) ; 

__attribute__((used)) static int sti_cpufreq_fetch_major(void) {
	struct device_node *np = ddata.cpu->of_node;
	struct device *dev = ddata.cpu;
	unsigned int major_offset;
	unsigned int socid;
	int ret;

	ret = of_property_read_u32_index(np, "st,syscfg",
					 MAJOR_ID_INDEX, &major_offset);
	if (ret) {
		dev_err(dev, "No major number offset provided in %pOF [%d]\n",
			np, ret);
		return ret;
	}

	ret = regmap_read(ddata.syscfg, major_offset, &socid);
	if (ret) {
		dev_err(dev, "Failed to read major number from syscon [%d]\n",
			ret);
		return ret;
	}

	return ((socid >> VERSION_SHIFT) & 0xf) + 1;
}

__attribute__((used)) static int sti_cpufreq_fetch_minor(void)
{
	struct device *dev = ddata.cpu;
	struct device_node *np = dev->of_node;
	unsigned int minor_offset;
	unsigned int minid;
	int ret;

	ret = of_property_read_u32_index(np, "st,syscfg-eng",
					 MINOR_ID_INDEX, &minor_offset);
	if (ret) {
		dev_err(dev,
			"No minor number offset provided %pOF [%d]\n",
			np, ret);
		return ret;
	}

	ret = regmap_read(ddata.syscfg_eng, minor_offset, &minid);
	if (ret) {
		dev_err(dev,
			"Failed to read the minor number from syscon [%d]\n",
			ret);
		return ret;
	}

	return minid & 0xf;
}

__attribute__((used)) static int sti_cpufreq_fetch_regmap_field(const struct reg_field *reg_fields,
					  int hw_info_offset, int field)
{
	struct regmap_field *regmap_field;
	struct reg_field reg_field = reg_fields[field];
	struct device *dev = ddata.cpu;
	unsigned int value;
	int ret;

	reg_field.reg = hw_info_offset;
	regmap_field = devm_regmap_field_alloc(dev,
					       ddata.syscfg_eng,
					       reg_field);
	if (IS_ERR(regmap_field)) {
		dev_err(dev, "Failed to allocate reg field\n");
		return PTR_ERR(regmap_field);
	}

	ret = regmap_field_read(regmap_field, &value);
	if (ret) {
		dev_err(dev, "Failed to read %s code\n",
			field ? "SUBSTRATE" : "PCODE");
		return ret;
	}

	return value;
}

__attribute__((used)) static const struct reg_field *sti_cpufreq_match(void)
{
	if (of_machine_is_compatible("st,stih407") ||
	    of_machine_is_compatible("st,stih410"))
		return sti_stih407_dvfs_regfields;

	return NULL;
}

__attribute__((used)) static int sti_cpufreq_set_opp_info(void)
{
	struct device *dev = ddata.cpu;
	struct device_node *np = dev->of_node;
	const struct reg_field *reg_fields;
	unsigned int hw_info_offset;
	unsigned int version[VERSION_ELEMENTS];
	int pcode, substrate, major, minor;
	int ret;
	char name[MAX_PCODE_NAME_LEN];
	struct opp_table *opp_table;

	reg_fields = sti_cpufreq_match();
	if (!reg_fields) {
		dev_err(dev, "This SoC doesn't support voltage scaling\n");
		return -ENODEV;
	}

	ret = of_property_read_u32_index(np, "st,syscfg-eng",
					 HW_INFO_INDEX, &hw_info_offset);
	if (ret) {
		dev_warn(dev, "Failed to read HW info offset from DT\n");
		substrate = DEFAULT_VERSION;
		pcode = 0;
		goto use_defaults;
	}

	pcode = sti_cpufreq_fetch_regmap_field(reg_fields,
					       hw_info_offset,
					       PCODE);
	if (pcode < 0) {
		dev_warn(dev, "Failed to obtain process code\n");
		/* Use default pcode */
		pcode = 0;
	}

	substrate = sti_cpufreq_fetch_regmap_field(reg_fields,
						   hw_info_offset,
						   SUBSTRATE);
	if (substrate) {
		dev_warn(dev, "Failed to obtain substrate code\n");
		/* Use default substrate */
		substrate = DEFAULT_VERSION;
	}

use_defaults:
	major = sti_cpufreq_fetch_major();
	if (major < 0) {
		dev_err(dev, "Failed to obtain major version\n");
		/* Use default major number */
		major = DEFAULT_VERSION;
	}

	minor = sti_cpufreq_fetch_minor();
	if (minor < 0) {
		dev_err(dev, "Failed to obtain minor version\n");
		/* Use default minor number */
		minor = DEFAULT_VERSION;
	}

	snprintf(name, MAX_PCODE_NAME_LEN, "pcode%d", pcode);

	opp_table = dev_pm_opp_set_prop_name(dev, name);
	if (IS_ERR(opp_table)) {
		dev_err(dev, "Failed to set prop name\n");
		return PTR_ERR(opp_table);
	}

	version[0] = BIT(major);
	version[1] = BIT(minor);
	version[2] = BIT(substrate);

	opp_table = dev_pm_opp_set_supported_hw(dev, version, VERSION_ELEMENTS);
	if (IS_ERR(opp_table)) {
		dev_err(dev, "Failed to set supported hardware\n");
		return PTR_ERR(opp_table);
	}

	dev_dbg(dev, "pcode: %d major: %d minor: %d substrate: %d\n",
		pcode, major, minor, substrate);
	dev_dbg(dev, "version[0]: %x version[1]: %x version[2]: %x\n",
		version[0], version[1], version[2]);

	return 0;
}

__attribute__((used)) static int sti_cpufreq_fetch_syscon_registers(void)
{
	struct device *dev = ddata.cpu;
	struct device_node *np = dev->of_node;

	ddata.syscfg = syscon_regmap_lookup_by_phandle(np, "st,syscfg");
	if (IS_ERR(ddata.syscfg)) {
		dev_err(dev,  "\"st,syscfg\" not supplied\n");
		return PTR_ERR(ddata.syscfg);
	}

	ddata.syscfg_eng = syscon_regmap_lookup_by_phandle(np, "st,syscfg-eng");
	if (IS_ERR(ddata.syscfg_eng)) {
		dev_err(dev, "\"st,syscfg-eng\" not supplied\n");
		return PTR_ERR(ddata.syscfg_eng);
	}

	return 0;
}

__attribute__((used)) static int sti_cpufreq_init(void)
{
	int ret;

	if ((!of_machine_is_compatible("st,stih407")) &&
		(!of_machine_is_compatible("st,stih410")))
		return -ENODEV;

	ddata.cpu = get_cpu_device(0);
	if (!ddata.cpu) {
		dev_err(ddata.cpu, "Failed to get device for CPU0\n");
		goto skip_voltage_scaling;
	}

	if (!of_get_property(ddata.cpu->of_node, "operating-points-v2", NULL)) {
		dev_err(ddata.cpu, "OPP-v2 not supported\n");
		goto skip_voltage_scaling;
	}

	ret = sti_cpufreq_fetch_syscon_registers();
	if (ret)
		goto skip_voltage_scaling;

	ret = sti_cpufreq_set_opp_info();
	if (!ret)
		goto register_cpufreq_dt;

skip_voltage_scaling:
	dev_err(ddata.cpu, "Not doing voltage scaling\n");

register_cpufreq_dt:
	platform_device_register_simple("cpufreq-dt", -1, NULL, 0);

	return 0;
}

