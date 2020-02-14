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
typedef  int u32 ;
struct qcom_coincell {int base_addr; TYPE_1__* dev; int /*<<< orphan*/  regmap; } ;
struct TYPE_2__ {int /*<<< orphan*/  parent; struct device_node* of_node; } ;
struct platform_device {TYPE_1__ dev; } ;
struct device_node {int dummy; } ;

/* Variables and functions */
 int ARRAY_SIZE (int*) ; 
 int EINVAL ; 
 int QCOM_COINCELL_ENABLE ; 
 int QCOM_COINCELL_REG_ENABLE ; 
 int QCOM_COINCELL_REG_RSET ; 
 int QCOM_COINCELL_REG_VSET ; 
 int /*<<< orphan*/  dev_err (TYPE_1__*,char*,...) ; 
 int /*<<< orphan*/  dev_get_regmap (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  of_property_read_bool (struct device_node*,char*) ; 
 int of_property_read_u32 (struct device_node*,char*,int*) ; 
 int* qcom_rset_map ; 
 int* qcom_vset_map ; 
 int regmap_write (int /*<<< orphan*/ ,int,int) ; 

__attribute__((used)) static int qcom_coincell_chgr_config(struct qcom_coincell *chgr, int rset,
				     int vset, bool enable)
{
	int i, j, rc;

	/* if disabling, just do that and skip other operations */
	if (!enable)
		return regmap_write(chgr->regmap,
			  chgr->base_addr + QCOM_COINCELL_REG_ENABLE, 0);

	/* find index for current-limiting resistor */
	for (i = 0; i < ARRAY_SIZE(qcom_rset_map); i++)
		if (rset == qcom_rset_map[i])
			break;

	if (i >= ARRAY_SIZE(qcom_rset_map)) {
		dev_err(chgr->dev, "invalid rset-ohms value %d\n", rset);
		return -EINVAL;
	}

	/* find index for charge voltage */
	for (j = 0; j < ARRAY_SIZE(qcom_vset_map); j++)
		if (vset == qcom_vset_map[j])
			break;

	if (j >= ARRAY_SIZE(qcom_vset_map)) {
		dev_err(chgr->dev, "invalid vset-millivolts value %d\n", vset);
		return -EINVAL;
	}

	rc = regmap_write(chgr->regmap,
			  chgr->base_addr + QCOM_COINCELL_REG_RSET, i);
	if (rc) {
		/*
		 * This is mainly to flag a bad base_addr (reg) from dts.
		 * Other failures writing to the registers should be
		 * extremely rare, or indicative of problems that
		 * should be reported elsewhere (eg. spmi failure).
		 */
		dev_err(chgr->dev, "could not write to RSET register\n");
		return rc;
	}

	rc = regmap_write(chgr->regmap,
		chgr->base_addr + QCOM_COINCELL_REG_VSET, j);
	if (rc)
		return rc;

	/* set 'enable' register */
	return regmap_write(chgr->regmap,
			    chgr->base_addr + QCOM_COINCELL_REG_ENABLE,
			    QCOM_COINCELL_ENABLE);
}

__attribute__((used)) static int qcom_coincell_probe(struct platform_device *pdev)
{
	struct device_node *node = pdev->dev.of_node;
	struct qcom_coincell chgr;
	u32 rset = 0;
	u32 vset = 0;
	bool enable;
	int rc;

	chgr.dev = &pdev->dev;

	chgr.regmap = dev_get_regmap(pdev->dev.parent, NULL);
	if (!chgr.regmap) {
		dev_err(chgr.dev, "Unable to get regmap\n");
		return -EINVAL;
	}

	rc = of_property_read_u32(node, "reg", &chgr.base_addr);
	if (rc)
		return rc;

	enable = !of_property_read_bool(node, "qcom,charger-disable");

	if (enable) {
		rc = of_property_read_u32(node, "qcom,rset-ohms", &rset);
		if (rc) {
			dev_err(chgr.dev,
				"can't find 'qcom,rset-ohms' in DT block");
			return rc;
		}

		rc = of_property_read_u32(node, "qcom,vset-millivolts", &vset);
		if (rc) {
			dev_err(chgr.dev,
			    "can't find 'qcom,vset-millivolts' in DT block");
			return rc;
		}
	}

	return qcom_coincell_chgr_config(&chgr, rset, vset, enable);
}

