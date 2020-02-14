#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_9__   TYPE_4__ ;
typedef  struct TYPE_8__   TYPE_3__ ;
typedef  struct TYPE_7__   TYPE_2__ ;
typedef  struct TYPE_6__   TYPE_1__ ;

/* Type definitions */
struct TYPE_8__ {int (* start ) (struct device*) ;int (* stop ) (struct device*) ;} ;
struct TYPE_9__ {char* name; int (* attach_dev ) (struct generic_pm_domain*,struct device*) ;void (* detach_dev ) (struct generic_pm_domain*,struct device*) ;TYPE_3__ dev_ops; } ;
struct ti_sci_pm_domain {TYPE_4__ pd; struct device* dev; struct ti_sci_handle const* ti_sci; } ;
struct TYPE_6__ {int (* get_device ) (struct ti_sci_handle const*,int) ;int (* put_device ) (struct ti_sci_handle const*,int) ;int (* is_valid ) (struct ti_sci_handle const*,int) ;} ;
struct TYPE_7__ {TYPE_1__ dev_ops; } ;
typedef  struct ti_sci_handle {TYPE_2__ ops; } const ti_sci_handle ;
struct ti_sci_genpd_dev_data {int idx; } ;
struct device {struct device_node* of_node; int /*<<< orphan*/  pm_domain; } ;
struct platform_device {struct device dev; } ;
struct of_phandle_args {int args_count; int* args; } ;
struct generic_pm_domain_data {struct ti_sci_genpd_dev_data* data; } ;
struct generic_pm_domain {int dummy; } ;
struct device_node {int dummy; } ;

/* Variables and functions */
 int EINVAL ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 scalar_t__ IS_ERR (struct ti_sci_handle const*) ; 
 int PTR_ERR (struct ti_sci_handle const*) ; 
 struct generic_pm_domain_data* dev_gpd_data (struct device*) ; 
 struct ti_sci_pm_domain* devm_kzalloc (struct device*,int,int /*<<< orphan*/ ) ; 
 struct ti_sci_handle const* devm_ti_sci_get_handle (struct device*) ; 
 struct ti_sci_pm_domain* genpd_to_ti_sci_pd (struct generic_pm_domain*) ; 
 int /*<<< orphan*/  kfree (struct ti_sci_genpd_dev_data*) ; 
 struct ti_sci_genpd_dev_data* kzalloc (int,int /*<<< orphan*/ ) ; 
 int of_genpd_add_provider_simple (struct device_node*,TYPE_4__*) ; 
 int of_parse_phandle_with_args (struct device_node*,char*,char*,int /*<<< orphan*/ ,struct of_phandle_args*) ; 
 struct generic_pm_domain* pd_to_genpd (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  pm_genpd_init (TYPE_4__*,int /*<<< orphan*/ *,int) ; 
 int stub1 (struct ti_sci_handle const*,int) ; 
 int stub2 (struct ti_sci_handle const*,int) ; 
 int stub3 (struct ti_sci_handle const*,int) ; 

__attribute__((used)) static int ti_sci_dev_id(struct device *dev)
{
	struct generic_pm_domain_data *genpd_data = dev_gpd_data(dev);
	struct ti_sci_genpd_dev_data *sci_dev_data = genpd_data->data;

	return sci_dev_data->idx;
}

__attribute__((used)) static const struct ti_sci_handle *ti_sci_dev_to_sci_handle(struct device *dev)
{
	struct generic_pm_domain *pd = pd_to_genpd(dev->pm_domain);
	struct ti_sci_pm_domain *ti_sci_genpd = genpd_to_ti_sci_pd(pd);

	return ti_sci_genpd->ti_sci;
}

__attribute__((used)) static int ti_sci_dev_start(struct device *dev)
{
	const struct ti_sci_handle *ti_sci = ti_sci_dev_to_sci_handle(dev);
	int idx = ti_sci_dev_id(dev);

	return ti_sci->ops.dev_ops.get_device(ti_sci, idx);
}

__attribute__((used)) static int ti_sci_dev_stop(struct device *dev)
{
	const struct ti_sci_handle *ti_sci = ti_sci_dev_to_sci_handle(dev);
	int idx = ti_sci_dev_id(dev);

	return ti_sci->ops.dev_ops.put_device(ti_sci, idx);
}

__attribute__((used)) static int ti_sci_pd_attach_dev(struct generic_pm_domain *domain,
				struct device *dev)
{
	struct device_node *np = dev->of_node;
	struct of_phandle_args pd_args;
	struct ti_sci_pm_domain *ti_sci_genpd = genpd_to_ti_sci_pd(domain);
	const struct ti_sci_handle *ti_sci = ti_sci_genpd->ti_sci;
	struct ti_sci_genpd_dev_data *sci_dev_data;
	struct generic_pm_domain_data *genpd_data;
	int idx, ret = 0;

	ret = of_parse_phandle_with_args(np, "power-domains",
					 "#power-domain-cells", 0, &pd_args);
	if (ret < 0)
		return ret;

	if (pd_args.args_count != 1)
		return -EINVAL;

	idx = pd_args.args[0];

	/*
	 * Check the validity of the requested idx, if the index is not valid
	 * the PMMC will return a NAK here and we will not allocate it.
	 */
	ret = ti_sci->ops.dev_ops.is_valid(ti_sci, idx);
	if (ret)
		return -EINVAL;

	sci_dev_data = kzalloc(sizeof(*sci_dev_data), GFP_KERNEL);
	if (!sci_dev_data)
		return -ENOMEM;

	sci_dev_data->idx = idx;

	genpd_data = dev_gpd_data(dev);
	genpd_data->data = sci_dev_data;

	return 0;
}

__attribute__((used)) static void ti_sci_pd_detach_dev(struct generic_pm_domain *domain,
				 struct device *dev)
{
	struct generic_pm_domain_data *genpd_data = dev_gpd_data(dev);
	struct ti_sci_genpd_dev_data *sci_dev_data = genpd_data->data;

	kfree(sci_dev_data);
	genpd_data->data = NULL;
}

__attribute__((used)) static int ti_sci_pm_domain_probe(struct platform_device *pdev)
{
	struct device *dev = &pdev->dev;
	struct device_node *np = dev->of_node;
	struct ti_sci_pm_domain *ti_sci_pd;
	int ret;

	ti_sci_pd = devm_kzalloc(dev, sizeof(*ti_sci_pd), GFP_KERNEL);
	if (!ti_sci_pd)
		return -ENOMEM;

	ti_sci_pd->ti_sci = devm_ti_sci_get_handle(dev);
	if (IS_ERR(ti_sci_pd->ti_sci))
		return PTR_ERR(ti_sci_pd->ti_sci);

	ti_sci_pd->dev = dev;

	ti_sci_pd->pd.name = "ti_sci_pd";

	ti_sci_pd->pd.attach_dev = ti_sci_pd_attach_dev;
	ti_sci_pd->pd.detach_dev = ti_sci_pd_detach_dev;

	ti_sci_pd->pd.dev_ops.start = ti_sci_dev_start;
	ti_sci_pd->pd.dev_ops.stop = ti_sci_dev_stop;

	pm_genpd_init(&ti_sci_pd->pd, NULL, true);

	ret = of_genpd_add_provider_simple(np, &ti_sci_pd->pd);

	return ret;
}

