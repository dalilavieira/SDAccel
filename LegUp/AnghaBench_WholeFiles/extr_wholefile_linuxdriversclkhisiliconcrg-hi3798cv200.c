#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_6__   TYPE_2__ ;
typedef  struct TYPE_5__   TYPE_1__ ;

/* Type definitions */
struct TYPE_6__ {int /*<<< orphan*/  of_node; } ;
struct platform_device {TYPE_2__ dev; } ;
struct hisi_reset_controller {int dummy; } ;
struct hisi_crg_dev {TYPE_1__* funcs; struct hisi_reset_controller* rstc; struct hisi_clock_data* clk_data; } ;
struct hisi_clock_data {int /*<<< orphan*/  clk_data; } ;
struct TYPE_5__ {int /*<<< orphan*/  (* unregister_clks ) (struct platform_device*) ;struct hisi_clock_data* (* register_clks ) (struct platform_device*) ;} ;

/* Variables and functions */
 int /*<<< orphan*/  ARRAY_SIZE (int /*<<< orphan*/ ) ; 
 int ENOENT ; 
 int ENOMEM ; 
 struct hisi_clock_data* ERR_PTR (int) ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int /*<<< orphan*/  HI3798CV200_CRG_NR_CLKS ; 
 int /*<<< orphan*/  HI3798CV200_SYSCTRL_NR_CLKS ; 
 scalar_t__ IS_ERR (struct hisi_clock_data*) ; 
 int PTR_ERR (struct hisi_clock_data*) ; 
 struct hisi_crg_dev* devm_kmalloc (TYPE_2__*,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  hi3798cv200_fixed_rate_clks ; 
 int /*<<< orphan*/  hi3798cv200_gate_clks ; 
 int /*<<< orphan*/  hi3798cv200_mux_clks ; 
 int /*<<< orphan*/  hi3798cv200_phase_clks ; 
 int /*<<< orphan*/  hi3798cv200_sysctrl_gate_clks ; 
 struct hisi_clock_data* hisi_clk_alloc (struct platform_device*,int /*<<< orphan*/ ) ; 
 int hisi_clk_register_fixed_rate (int /*<<< orphan*/ ,int /*<<< orphan*/ ,struct hisi_clock_data*) ; 
 int hisi_clk_register_gate (int /*<<< orphan*/ ,int /*<<< orphan*/ ,struct hisi_clock_data*) ; 
 int hisi_clk_register_mux (int /*<<< orphan*/ ,int /*<<< orphan*/ ,struct hisi_clock_data*) ; 
 int hisi_clk_register_phase (TYPE_2__*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,struct hisi_clock_data*) ; 
 int /*<<< orphan*/  hisi_clk_unregister_fixed_rate (int /*<<< orphan*/ ,int /*<<< orphan*/ ,struct hisi_clock_data*) ; 
 int /*<<< orphan*/  hisi_clk_unregister_gate (int /*<<< orphan*/ ,int /*<<< orphan*/ ,struct hisi_clock_data*) ; 
 int /*<<< orphan*/  hisi_clk_unregister_mux (int /*<<< orphan*/ ,int /*<<< orphan*/ ,struct hisi_clock_data*) ; 
 int of_clk_add_provider (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  of_clk_del_provider (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  of_clk_src_onecell_get ; 
 TYPE_1__* of_device_get_match_data (TYPE_2__*) ; 
 struct hisi_crg_dev* platform_get_drvdata (struct platform_device*) ; 
 int /*<<< orphan*/  platform_set_drvdata (struct platform_device*,struct hisi_crg_dev*) ; 
 struct hisi_clock_data* stub1 (struct platform_device*) ; 
 int /*<<< orphan*/  stub2 (struct platform_device*) ; 

__attribute__((used)) static inline
struct hisi_reset_controller *hisi_reset_init(struct platform_device *pdev)
{
	return 0;
}

__attribute__((used)) static inline void hisi_reset_exit(struct hisi_reset_controller *rstc)
{}

__attribute__((used)) static struct hisi_clock_data *hi3798cv200_clk_register(
				struct platform_device *pdev)
{
	struct hisi_clock_data *clk_data;
	int ret;

	clk_data = hisi_clk_alloc(pdev, HI3798CV200_CRG_NR_CLKS);
	if (!clk_data)
		return ERR_PTR(-ENOMEM);

	/* hisi_phase_clock is resource managed */
	ret = hisi_clk_register_phase(&pdev->dev,
				hi3798cv200_phase_clks,
				ARRAY_SIZE(hi3798cv200_phase_clks),
				clk_data);
	if (ret)
		return ERR_PTR(ret);

	ret = hisi_clk_register_fixed_rate(hi3798cv200_fixed_rate_clks,
				     ARRAY_SIZE(hi3798cv200_fixed_rate_clks),
				     clk_data);
	if (ret)
		return ERR_PTR(ret);

	ret = hisi_clk_register_mux(hi3798cv200_mux_clks,
				ARRAY_SIZE(hi3798cv200_mux_clks),
				clk_data);
	if (ret)
		goto unregister_fixed_rate;

	ret = hisi_clk_register_gate(hi3798cv200_gate_clks,
				ARRAY_SIZE(hi3798cv200_gate_clks),
				clk_data);
	if (ret)
		goto unregister_mux;

	ret = of_clk_add_provider(pdev->dev.of_node,
			of_clk_src_onecell_get, &clk_data->clk_data);
	if (ret)
		goto unregister_gate;

	return clk_data;

unregister_gate:
	hisi_clk_unregister_gate(hi3798cv200_gate_clks,
				ARRAY_SIZE(hi3798cv200_gate_clks),
				clk_data);
unregister_mux:
	hisi_clk_unregister_mux(hi3798cv200_mux_clks,
				ARRAY_SIZE(hi3798cv200_mux_clks),
				clk_data);
unregister_fixed_rate:
	hisi_clk_unregister_fixed_rate(hi3798cv200_fixed_rate_clks,
				ARRAY_SIZE(hi3798cv200_fixed_rate_clks),
				clk_data);
	return ERR_PTR(ret);
}

__attribute__((used)) static void hi3798cv200_clk_unregister(struct platform_device *pdev)
{
	struct hisi_crg_dev *crg = platform_get_drvdata(pdev);

	of_clk_del_provider(pdev->dev.of_node);

	hisi_clk_unregister_gate(hi3798cv200_gate_clks,
				ARRAY_SIZE(hi3798cv200_gate_clks),
				crg->clk_data);
	hisi_clk_unregister_mux(hi3798cv200_mux_clks,
				ARRAY_SIZE(hi3798cv200_mux_clks),
				crg->clk_data);
	hisi_clk_unregister_fixed_rate(hi3798cv200_fixed_rate_clks,
				ARRAY_SIZE(hi3798cv200_fixed_rate_clks),
				crg->clk_data);
}

__attribute__((used)) static struct hisi_clock_data *hi3798cv200_sysctrl_clk_register(
					struct platform_device *pdev)
{
	struct hisi_clock_data *clk_data;
	int ret;

	clk_data = hisi_clk_alloc(pdev, HI3798CV200_SYSCTRL_NR_CLKS);
	if (!clk_data)
		return ERR_PTR(-ENOMEM);

	ret = hisi_clk_register_gate(hi3798cv200_sysctrl_gate_clks,
				ARRAY_SIZE(hi3798cv200_sysctrl_gate_clks),
				clk_data);
	if (ret)
		return ERR_PTR(ret);

	ret = of_clk_add_provider(pdev->dev.of_node,
			of_clk_src_onecell_get, &clk_data->clk_data);
	if (ret)
		goto unregister_gate;

	return clk_data;

unregister_gate:
	hisi_clk_unregister_gate(hi3798cv200_sysctrl_gate_clks,
				ARRAY_SIZE(hi3798cv200_sysctrl_gate_clks),
				clk_data);
	return ERR_PTR(ret);
}

__attribute__((used)) static void hi3798cv200_sysctrl_clk_unregister(struct platform_device *pdev)
{
	struct hisi_crg_dev *crg = platform_get_drvdata(pdev);

	of_clk_del_provider(pdev->dev.of_node);

	hisi_clk_unregister_gate(hi3798cv200_sysctrl_gate_clks,
				ARRAY_SIZE(hi3798cv200_sysctrl_gate_clks),
				crg->clk_data);
}

__attribute__((used)) static int hi3798cv200_crg_probe(struct platform_device *pdev)
{
	struct hisi_crg_dev *crg;

	crg = devm_kmalloc(&pdev->dev, sizeof(*crg), GFP_KERNEL);
	if (!crg)
		return -ENOMEM;

	crg->funcs = of_device_get_match_data(&pdev->dev);
	if (!crg->funcs)
		return -ENOENT;

	crg->rstc = hisi_reset_init(pdev);
	if (!crg->rstc)
		return -ENOMEM;

	crg->clk_data = crg->funcs->register_clks(pdev);
	if (IS_ERR(crg->clk_data)) {
		hisi_reset_exit(crg->rstc);
		return PTR_ERR(crg->clk_data);
	}

	platform_set_drvdata(pdev, crg);
	return 0;
}

__attribute__((used)) static int hi3798cv200_crg_remove(struct platform_device *pdev)
{
	struct hisi_crg_dev *crg = platform_get_drvdata(pdev);

	hisi_reset_exit(crg->rstc);
	crg->funcs->unregister_clks(pdev);
	return 0;
}

