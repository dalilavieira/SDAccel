#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_13__   TYPE_5__ ;
typedef  struct TYPE_12__   TYPE_4__ ;
typedef  struct TYPE_11__   TYPE_3__ ;
typedef  struct TYPE_10__   TYPE_2__ ;
typedef  struct TYPE_9__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  u32 ;
struct TYPE_12__ {int /*<<< orphan*/  of_node; TYPE_2__* driver; } ;
struct platform_device {TYPE_4__ dev; } ;
struct owl_sps_info {int num_domains; TYPE_1__* domains; } ;
struct TYPE_11__ {int (* power_on ) (struct generic_pm_domain*) ;int (* power_off ) (struct generic_pm_domain*) ;int /*<<< orphan*/  flags; int /*<<< orphan*/  name; } ;
struct owl_sps_domain {TYPE_3__ genpd; TYPE_1__* info; struct owl_sps* sps; } ;
struct TYPE_13__ {int num_domains; TYPE_3__** domains; } ;
struct owl_sps {TYPE_5__ genpd_data; TYPE_3__** domains; struct owl_sps_info const* info; TYPE_4__* dev; int /*<<< orphan*/  base; } ;
struct of_device_id {struct owl_sps_info* data; } ;
struct generic_pm_domain {int dummy; } ;
struct TYPE_10__ {int /*<<< orphan*/  of_match_table; } ;
struct TYPE_9__ {int /*<<< orphan*/  genpd_flags; int /*<<< orphan*/  name; int /*<<< orphan*/  pwr_bit; int /*<<< orphan*/  ack_bit; } ;

/* Variables and functions */
 int /*<<< orphan*/  BIT (int /*<<< orphan*/ ) ; 
 int EINVAL ; 
 int ENODEV ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 scalar_t__ IS_ERR (int /*<<< orphan*/ ) ; 
 int PTR_ERR (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  dev_dbg (TYPE_4__*,char*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  dev_err (TYPE_4__*,char*,...) ; 
 void* devm_kzalloc (TYPE_4__*,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  domains ; 
 int of_genpd_add_provider_onecell (int /*<<< orphan*/ ,TYPE_5__*) ; 
 int /*<<< orphan*/  of_io_request_and_map (int /*<<< orphan*/ ,int /*<<< orphan*/ ,char*) ; 
 struct of_device_id* of_match_device (int /*<<< orphan*/ ,TYPE_4__*) ; 
 int owl_sps_set_pg (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  pm_genpd_init (TYPE_3__*,int /*<<< orphan*/ *,int) ; 
 int struct_size (struct owl_sps*,int /*<<< orphan*/ ,int) ; 
 struct owl_sps_domain* to_owl_pd (struct generic_pm_domain*) ; 

__attribute__((used)) static int owl_sps_set_power(struct owl_sps_domain *pd, bool enable)
{
	u32 pwr_mask, ack_mask;

	ack_mask = BIT(pd->info->ack_bit);
	pwr_mask = BIT(pd->info->pwr_bit);

	return owl_sps_set_pg(pd->sps->base, pwr_mask, ack_mask, enable);
}

__attribute__((used)) static int owl_sps_power_on(struct generic_pm_domain *domain)
{
	struct owl_sps_domain *pd = to_owl_pd(domain);

	dev_dbg(pd->sps->dev, "%s power on", pd->info->name);

	return owl_sps_set_power(pd, true);
}

__attribute__((used)) static int owl_sps_power_off(struct generic_pm_domain *domain)
{
	struct owl_sps_domain *pd = to_owl_pd(domain);

	dev_dbg(pd->sps->dev, "%s power off", pd->info->name);

	return owl_sps_set_power(pd, false);
}

__attribute__((used)) static int owl_sps_init_domain(struct owl_sps *sps, int index)
{
	struct owl_sps_domain *pd;

	pd = devm_kzalloc(sps->dev, sizeof(*pd), GFP_KERNEL);
	if (!pd)
		return -ENOMEM;

	pd->info = &sps->info->domains[index];
	pd->sps = sps;

	pd->genpd.name = pd->info->name;
	pd->genpd.power_on = owl_sps_power_on;
	pd->genpd.power_off = owl_sps_power_off;
	pd->genpd.flags = pd->info->genpd_flags;
	pm_genpd_init(&pd->genpd, NULL, false);

	sps->genpd_data.domains[index] = &pd->genpd;

	return 0;
}

__attribute__((used)) static int owl_sps_probe(struct platform_device *pdev)
{
	const struct of_device_id *match;
	const struct owl_sps_info *sps_info;
	struct owl_sps *sps;
	int i, ret;

	if (!pdev->dev.of_node) {
		dev_err(&pdev->dev, "no device node\n");
		return -ENODEV;
	}

	match = of_match_device(pdev->dev.driver->of_match_table, &pdev->dev);
	if (!match || !match->data) {
		dev_err(&pdev->dev, "unknown compatible or missing data\n");
		return -EINVAL;
	}

	sps_info = match->data;

	sps = devm_kzalloc(&pdev->dev,
			   struct_size(sps, domains, sps_info->num_domains),
			   GFP_KERNEL);
	if (!sps)
		return -ENOMEM;

	sps->base = of_io_request_and_map(pdev->dev.of_node, 0, "owl-sps");
	if (IS_ERR(sps->base)) {
		dev_err(&pdev->dev, "failed to map sps registers\n");
		return PTR_ERR(sps->base);
	}

	sps->dev = &pdev->dev;
	sps->info = sps_info;
	sps->genpd_data.domains = sps->domains;
	sps->genpd_data.num_domains = sps_info->num_domains;

	for (i = 0; i < sps_info->num_domains; i++) {
		ret = owl_sps_init_domain(sps, i);
		if (ret)
			return ret;
	}

	ret = of_genpd_add_provider_onecell(pdev->dev.of_node, &sps->genpd_data);
	if (ret) {
		dev_err(&pdev->dev, "failed to add provider (%d)", ret);
		return ret;
	}

	return 0;
}

