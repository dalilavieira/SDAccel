#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_8__   TYPE_2__ ;
typedef  struct TYPE_7__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  u32 ;
struct rpm_regulator_req {void* value; void* nbytes; void* key; } ;
struct rpm_regulator_data {scalar_t__ name; int /*<<< orphan*/  supply; int /*<<< orphan*/  desc; int /*<<< orphan*/  id; int /*<<< orphan*/  type; } ;
struct regulator_dev {int dummy; } ;
struct regulator_config {struct qcom_rpm_reg* driver_data; TYPE_1__* dev; } ;
struct qcom_smd_rpm {int dummy; } ;
struct TYPE_8__ {int id; scalar_t__ of_match; int /*<<< orphan*/  supply_name; scalar_t__ name; int /*<<< orphan*/  type; int /*<<< orphan*/  owner; } ;
struct qcom_rpm_reg {int is_enabled; int uV; TYPE_2__ desc; struct qcom_smd_rpm* rpm; int /*<<< orphan*/  id; int /*<<< orphan*/  type; TYPE_1__* dev; } ;
struct TYPE_7__ {int /*<<< orphan*/  parent; } ;
struct platform_device {TYPE_1__ dev; } ;
struct of_device_id {struct rpm_regulator_data* data; } ;
typedef  int /*<<< orphan*/  req ;

/* Variables and functions */
 int ENODEV ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 scalar_t__ IS_ERR (struct regulator_dev*) ; 
 int PTR_ERR (struct regulator_dev*) ; 
 int /*<<< orphan*/  QCOM_SMD_RPM_ACTIVE_STATE ; 
 int /*<<< orphan*/  REGULATOR_VOLTAGE ; 
 int RPM_KEY_MA ; 
 int RPM_KEY_SWEN ; 
 int RPM_KEY_UV ; 
 int /*<<< orphan*/  THIS_MODULE ; 
 void* cpu_to_le32 (int) ; 
 int /*<<< orphan*/  dev_err (TYPE_1__*,char*,...) ; 
 struct qcom_smd_rpm* dev_get_drvdata (int /*<<< orphan*/ ) ; 
 struct qcom_rpm_reg* devm_kzalloc (TYPE_1__*,int,int /*<<< orphan*/ ) ; 
 struct regulator_dev* devm_regulator_register (TYPE_1__*,TYPE_2__*,struct regulator_config*) ; 
 int /*<<< orphan*/  memcpy (TYPE_2__*,int /*<<< orphan*/ ,int) ; 
 struct of_device_id* of_match_device (int /*<<< orphan*/ ,TYPE_1__*) ; 
 int qcom_rpm_smd_write (struct qcom_smd_rpm*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,struct rpm_regulator_req*,size_t) ; 
 struct qcom_rpm_reg* rdev_get_drvdata (struct regulator_dev*) ; 
 int /*<<< orphan*/  rpm_of_match ; 

__attribute__((used)) static int rpm_reg_write_active(struct qcom_rpm_reg *vreg,
				struct rpm_regulator_req *req,
				size_t size)
{
	return qcom_rpm_smd_write(vreg->rpm,
				  QCOM_SMD_RPM_ACTIVE_STATE,
				  vreg->type,
				  vreg->id,
				  req, size);
}

__attribute__((used)) static int rpm_reg_enable(struct regulator_dev *rdev)
{
	struct qcom_rpm_reg *vreg = rdev_get_drvdata(rdev);
	struct rpm_regulator_req req;
	int ret;

	req.key = cpu_to_le32(RPM_KEY_SWEN);
	req.nbytes = cpu_to_le32(sizeof(u32));
	req.value = cpu_to_le32(1);

	ret = rpm_reg_write_active(vreg, &req, sizeof(req));
	if (!ret)
		vreg->is_enabled = 1;

	return ret;
}

__attribute__((used)) static int rpm_reg_is_enabled(struct regulator_dev *rdev)
{
	struct qcom_rpm_reg *vreg = rdev_get_drvdata(rdev);

	return vreg->is_enabled;
}

__attribute__((used)) static int rpm_reg_disable(struct regulator_dev *rdev)
{
	struct qcom_rpm_reg *vreg = rdev_get_drvdata(rdev);
	struct rpm_regulator_req req;
	int ret;

	req.key = cpu_to_le32(RPM_KEY_SWEN);
	req.nbytes = cpu_to_le32(sizeof(u32));
	req.value = 0;

	ret = rpm_reg_write_active(vreg, &req, sizeof(req));
	if (!ret)
		vreg->is_enabled = 0;

	return ret;
}

__attribute__((used)) static int rpm_reg_get_voltage(struct regulator_dev *rdev)
{
	struct qcom_rpm_reg *vreg = rdev_get_drvdata(rdev);

	return vreg->uV;
}

__attribute__((used)) static int rpm_reg_set_voltage(struct regulator_dev *rdev,
			       int min_uV,
			       int max_uV,
			       unsigned *selector)
{
	struct qcom_rpm_reg *vreg = rdev_get_drvdata(rdev);
	struct rpm_regulator_req req;
	int ret = 0;

	req.key = cpu_to_le32(RPM_KEY_UV);
	req.nbytes = cpu_to_le32(sizeof(u32));
	req.value = cpu_to_le32(min_uV);

	ret = rpm_reg_write_active(vreg, &req, sizeof(req));
	if (!ret)
		vreg->uV = min_uV;

	return ret;
}

__attribute__((used)) static int rpm_reg_set_load(struct regulator_dev *rdev, int load_uA)
{
	struct qcom_rpm_reg *vreg = rdev_get_drvdata(rdev);
	struct rpm_regulator_req req;

	req.key = cpu_to_le32(RPM_KEY_MA);
	req.nbytes = cpu_to_le32(sizeof(u32));
	req.value = cpu_to_le32(load_uA / 1000);

	return rpm_reg_write_active(vreg, &req, sizeof(req));
}

__attribute__((used)) static int rpm_reg_probe(struct platform_device *pdev)
{
	const struct rpm_regulator_data *reg;
	const struct of_device_id *match;
	struct regulator_config config = { };
	struct regulator_dev *rdev;
	struct qcom_rpm_reg *vreg;
	struct qcom_smd_rpm *rpm;

	rpm = dev_get_drvdata(pdev->dev.parent);
	if (!rpm) {
		dev_err(&pdev->dev, "unable to retrieve handle to rpm\n");
		return -ENODEV;
	}

	match = of_match_device(rpm_of_match, &pdev->dev);
	if (!match) {
		dev_err(&pdev->dev, "failed to match device\n");
		return -ENODEV;
	}

	for (reg = match->data; reg->name; reg++) {
		vreg = devm_kzalloc(&pdev->dev, sizeof(*vreg), GFP_KERNEL);
		if (!vreg)
			return -ENOMEM;

		vreg->dev = &pdev->dev;
		vreg->type = reg->type;
		vreg->id = reg->id;
		vreg->rpm = rpm;

		memcpy(&vreg->desc, reg->desc, sizeof(vreg->desc));

		vreg->desc.id = -1;
		vreg->desc.owner = THIS_MODULE;
		vreg->desc.type = REGULATOR_VOLTAGE;
		vreg->desc.name = reg->name;
		vreg->desc.supply_name = reg->supply;
		vreg->desc.of_match = reg->name;

		config.dev = &pdev->dev;
		config.driver_data = vreg;
		rdev = devm_regulator_register(&pdev->dev, &vreg->desc, &config);
		if (IS_ERR(rdev)) {
			dev_err(&pdev->dev, "failed to register %s\n", reg->name);
			return PTR_ERR(rdev);
		}
	}

	return 0;
}

