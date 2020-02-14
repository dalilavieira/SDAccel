#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_14__   TYPE_4__ ;
typedef  struct TYPE_13__   TYPE_2__ ;
typedef  struct TYPE_12__   TYPE_1__ ;

/* Type definitions */
struct regulator_bulk_data {int dummy; } ;
struct qcom_wcnss {int dummy; } ;
struct qcom_iris {int num_vregs; TYPE_2__* vregs; int /*<<< orphan*/  xo_clk; TYPE_4__* dev; } ;
struct TYPE_14__ {int /*<<< orphan*/  parent; } ;
struct platform_device {TYPE_4__ dev; } ;
struct iris_data {int num_vregs; int use_48mhz_xo; TYPE_1__* vregs; } ;
struct TYPE_13__ {int /*<<< orphan*/  consumer; int /*<<< orphan*/  supply; } ;
struct TYPE_12__ {scalar_t__ load_uA; scalar_t__ max_voltage; int /*<<< orphan*/  min_voltage; int /*<<< orphan*/  name; } ;

/* Variables and functions */
 int ENOMEM ; 
 int EPROBE_DEFER ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 scalar_t__ IS_ERR (int /*<<< orphan*/ ) ; 
 int PTR_ERR (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  clk_disable_unprepare (int /*<<< orphan*/ ) ; 
 int clk_prepare_enable (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  dev_err (TYPE_4__*,char*) ; 
 struct qcom_wcnss* dev_get_drvdata (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  devm_clk_get (TYPE_4__*,char*) ; 
 TYPE_2__* devm_kcalloc (TYPE_4__*,int,int,int /*<<< orphan*/ ) ; 
 struct qcom_iris* devm_kzalloc (TYPE_4__*,int,int /*<<< orphan*/ ) ; 
 int devm_regulator_bulk_get (TYPE_4__*,int,TYPE_2__*) ; 
 struct iris_data* of_device_get_match_data (TYPE_4__*) ; 
 int /*<<< orphan*/  qcom_wcnss_assign_iris (struct qcom_wcnss*,struct qcom_iris*,int) ; 
 int /*<<< orphan*/  regulator_bulk_disable (int,TYPE_2__*) ; 
 int regulator_bulk_enable (int,TYPE_2__*) ; 
 int /*<<< orphan*/  regulator_set_load (int /*<<< orphan*/ ,scalar_t__) ; 
 int /*<<< orphan*/  regulator_set_voltage (int /*<<< orphan*/ ,int /*<<< orphan*/ ,scalar_t__) ; 

int qcom_iris_enable(struct qcom_iris *iris)
{
	int ret;

	ret = regulator_bulk_enable(iris->num_vregs, iris->vregs);
	if (ret)
		return ret;

	ret = clk_prepare_enable(iris->xo_clk);
	if (ret) {
		dev_err(iris->dev, "failed to enable xo clk\n");
		goto disable_regulators;
	}

	return 0;

disable_regulators:
	regulator_bulk_disable(iris->num_vregs, iris->vregs);

	return ret;
}

void qcom_iris_disable(struct qcom_iris *iris)
{
	clk_disable_unprepare(iris->xo_clk);
	regulator_bulk_disable(iris->num_vregs, iris->vregs);
}

__attribute__((used)) static int qcom_iris_probe(struct platform_device *pdev)
{
	const struct iris_data *data;
	struct qcom_wcnss *wcnss;
	struct qcom_iris *iris;
	int ret;
	int i;

	iris = devm_kzalloc(&pdev->dev, sizeof(struct qcom_iris), GFP_KERNEL);
	if (!iris)
		return -ENOMEM;

	data = of_device_get_match_data(&pdev->dev);
	wcnss = dev_get_drvdata(pdev->dev.parent);

	iris->xo_clk = devm_clk_get(&pdev->dev, "xo");
	if (IS_ERR(iris->xo_clk)) {
		if (PTR_ERR(iris->xo_clk) != -EPROBE_DEFER)
			dev_err(&pdev->dev, "failed to acquire xo clk\n");
		return PTR_ERR(iris->xo_clk);
	}

	iris->num_vregs = data->num_vregs;
	iris->vregs = devm_kcalloc(&pdev->dev,
				   iris->num_vregs,
				   sizeof(struct regulator_bulk_data),
				   GFP_KERNEL);
	if (!iris->vregs)
		return -ENOMEM;

	for (i = 0; i < iris->num_vregs; i++)
		iris->vregs[i].supply = data->vregs[i].name;

	ret = devm_regulator_bulk_get(&pdev->dev, iris->num_vregs, iris->vregs);
	if (ret) {
		dev_err(&pdev->dev, "failed to get regulators\n");
		return ret;
	}

	for (i = 0; i < iris->num_vregs; i++) {
		if (data->vregs[i].max_voltage)
			regulator_set_voltage(iris->vregs[i].consumer,
					      data->vregs[i].min_voltage,
					      data->vregs[i].max_voltage);

		if (data->vregs[i].load_uA)
			regulator_set_load(iris->vregs[i].consumer,
					   data->vregs[i].load_uA);
	}

	qcom_wcnss_assign_iris(wcnss, iris, data->use_48mhz_xo);

	return 0;
}

__attribute__((used)) static int qcom_iris_remove(struct platform_device *pdev)
{
	struct qcom_wcnss *wcnss = dev_get_drvdata(pdev->dev.parent);

	qcom_wcnss_assign_iris(wcnss, NULL, false);

	return 0;
}

