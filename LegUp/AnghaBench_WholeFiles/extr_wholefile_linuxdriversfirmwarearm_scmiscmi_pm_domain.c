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
typedef  scalar_t__ u32 ;
struct scmi_power_ops {int (* state_set ) (struct scmi_handle const*,int,scalar_t__) ;int (* state_get ) (struct scmi_handle const*,int,scalar_t__*) ;int (* num_domains_get ) (struct scmi_handle const*) ;int /*<<< orphan*/  (* name_get ) (struct scmi_handle const*,int) ;} ;
struct generic_pm_domain {int (* power_off ) (struct generic_pm_domain*) ;int (* power_on ) (struct generic_pm_domain*) ;int /*<<< orphan*/  name; } ;
struct scmi_pm_domain {int domain; struct generic_pm_domain genpd; int /*<<< orphan*/  name; struct scmi_handle const* handle; } ;
struct scmi_handle {struct scmi_power_ops* power_ops; } ;
struct device {struct device_node* of_node; } ;
struct scmi_device {struct scmi_handle* handle; struct device dev; } ;
struct genpd_onecell_data {int num_domains; struct generic_pm_domain** domains; } ;
struct device_node {int dummy; } ;

/* Variables and functions */
 int EIO ; 
 int ENODEV ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 scalar_t__ SCMI_POWER_STATE_GENERIC_OFF ; 
 scalar_t__ SCMI_POWER_STATE_GENERIC_ON ; 
 int /*<<< orphan*/  dev_err (struct device*,char*) ; 
 int /*<<< orphan*/  dev_warn (struct device*,char*,int) ; 
 void* devm_kcalloc (struct device*,int,int,int /*<<< orphan*/ ) ; 
 struct genpd_onecell_data* devm_kzalloc (struct device*,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  of_genpd_add_provider_onecell (struct device_node*,struct genpd_onecell_data*) ; 
 int /*<<< orphan*/  pm_genpd_init (struct generic_pm_domain*,int /*<<< orphan*/ *,int) ; 
 int stub1 (struct scmi_handle const*,int,scalar_t__) ; 
 int stub2 (struct scmi_handle const*,int,scalar_t__*) ; 
 int stub3 (struct scmi_handle const*) ; 
 int /*<<< orphan*/  stub4 (struct scmi_handle const*,int) ; 
 int stub5 (struct scmi_handle const*,int,scalar_t__*) ; 
 struct scmi_pm_domain* to_scmi_pd (struct generic_pm_domain*) ; 

__attribute__((used)) static int scmi_pd_power(struct generic_pm_domain *domain, bool power_on)
{
	int ret;
	u32 state, ret_state;
	struct scmi_pm_domain *pd = to_scmi_pd(domain);
	const struct scmi_power_ops *ops = pd->handle->power_ops;

	if (power_on)
		state = SCMI_POWER_STATE_GENERIC_ON;
	else
		state = SCMI_POWER_STATE_GENERIC_OFF;

	ret = ops->state_set(pd->handle, pd->domain, state);
	if (!ret)
		ret = ops->state_get(pd->handle, pd->domain, &ret_state);
	if (!ret && state != ret_state)
		return -EIO;

	return ret;
}

__attribute__((used)) static int scmi_pd_power_on(struct generic_pm_domain *domain)
{
	return scmi_pd_power(domain, true);
}

__attribute__((used)) static int scmi_pd_power_off(struct generic_pm_domain *domain)
{
	return scmi_pd_power(domain, false);
}

__attribute__((used)) static int scmi_pm_domain_probe(struct scmi_device *sdev)
{
	int num_domains, i;
	struct device *dev = &sdev->dev;
	struct device_node *np = dev->of_node;
	struct scmi_pm_domain *scmi_pd;
	struct genpd_onecell_data *scmi_pd_data;
	struct generic_pm_domain **domains;
	const struct scmi_handle *handle = sdev->handle;

	if (!handle || !handle->power_ops)
		return -ENODEV;

	num_domains = handle->power_ops->num_domains_get(handle);
	if (num_domains < 0) {
		dev_err(dev, "number of domains not found\n");
		return num_domains;
	}

	scmi_pd = devm_kcalloc(dev, num_domains, sizeof(*scmi_pd), GFP_KERNEL);
	if (!scmi_pd)
		return -ENOMEM;

	scmi_pd_data = devm_kzalloc(dev, sizeof(*scmi_pd_data), GFP_KERNEL);
	if (!scmi_pd_data)
		return -ENOMEM;

	domains = devm_kcalloc(dev, num_domains, sizeof(*domains), GFP_KERNEL);
	if (!domains)
		return -ENOMEM;

	for (i = 0; i < num_domains; i++, scmi_pd++) {
		u32 state;

		domains[i] = &scmi_pd->genpd;

		scmi_pd->domain = i;
		scmi_pd->handle = handle;
		scmi_pd->name = handle->power_ops->name_get(handle, i);
		scmi_pd->genpd.name = scmi_pd->name;
		scmi_pd->genpd.power_off = scmi_pd_power_off;
		scmi_pd->genpd.power_on = scmi_pd_power_on;

		if (handle->power_ops->state_get(handle, i, &state)) {
			dev_warn(dev, "failed to get state for domain %d\n", i);
			continue;
		}

		pm_genpd_init(&scmi_pd->genpd, NULL,
			      state == SCMI_POWER_STATE_GENERIC_OFF);
	}

	scmi_pd_data->domains = domains;
	scmi_pd_data->num_domains = num_domains;

	of_genpd_add_provider_onecell(np, scmi_pd_data);

	return 0;
}

