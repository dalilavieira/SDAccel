#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_6__   TYPE_3__ ;
typedef  struct TYPE_5__   TYPE_2__ ;
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
typedef  unsigned long u64 ;
struct scmi_handle {TYPE_2__* clk_ops; } ;
struct device {struct device_node* of_node; } ;
struct scmi_device {struct scmi_handle* handle; struct device dev; } ;
struct clk_hw {struct clk_init_data* init; } ;
struct scmi_clk {int id; struct clk_hw hw; TYPE_3__* info; struct scmi_handle const* handle; } ;
struct device_node {int name; } ;
struct clk_init_data {int name; int /*<<< orphan*/ * ops; int /*<<< orphan*/  num_parents; int /*<<< orphan*/  flags; } ;
struct clk_hw_onecell_data {int num; struct clk_hw** hws; } ;
struct TYPE_4__ {unsigned long min_rate; unsigned long max_rate; int step_size; } ;
struct TYPE_6__ {int name; TYPE_1__ range; scalar_t__ rate_discrete; } ;
struct TYPE_5__ {int (* rate_get ) (struct scmi_handle const*,int,unsigned long*) ;int (* rate_set ) (struct scmi_handle const*,int,int /*<<< orphan*/ ,unsigned long) ;int (* enable ) (struct scmi_handle const*,int) ;int (* count_get ) (struct scmi_handle const*) ;TYPE_3__* (* info_get ) (struct scmi_handle const*,int) ;int /*<<< orphan*/  (* disable ) (struct scmi_handle const*,int) ;} ;

/* Variables and functions */
 int /*<<< orphan*/  CLK_GET_RATE_NOCACHE ; 
 int EINVAL ; 
 int ENODEV ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int /*<<< orphan*/  clk_hw_set_rate_range (struct clk_hw*,unsigned long,unsigned long) ; 
 int /*<<< orphan*/  dev_dbg (struct device*,char*,int) ; 
 int /*<<< orphan*/  dev_err (struct device*,char*,int) ; 
 int devm_clk_hw_register (struct device*,struct clk_hw*) ; 
 int /*<<< orphan*/  devm_kfree (struct device*,struct scmi_clk*) ; 
 void* devm_kzalloc (struct device*,int,int /*<<< orphan*/ ) ; 
 int devm_of_clk_add_hw_provider (struct device*,int /*<<< orphan*/ ,struct clk_hw_onecell_data*) ; 
 int /*<<< orphan*/  do_div (unsigned long,int) ; 
 int /*<<< orphan*/  of_clk_hw_onecell_get ; 
 int /*<<< orphan*/  scmi_clk_ops ; 
 int struct_size (struct clk_hw_onecell_data*,struct clk_hw**,int) ; 
 int stub1 (struct scmi_handle const*,int,unsigned long*) ; 
 int stub2 (struct scmi_handle const*,int,int /*<<< orphan*/ ,unsigned long) ; 
 int stub3 (struct scmi_handle const*,int) ; 
 int /*<<< orphan*/  stub4 (struct scmi_handle const*,int) ; 
 int stub5 (struct scmi_handle const*) ; 
 TYPE_3__* stub6 (struct scmi_handle const*,int) ; 
 struct scmi_clk* to_scmi_clk (struct clk_hw*) ; 

__attribute__((used)) static unsigned long scmi_clk_recalc_rate(struct clk_hw *hw,
					  unsigned long parent_rate)
{
	int ret;
	u64 rate;
	struct scmi_clk *clk = to_scmi_clk(hw);

	ret = clk->handle->clk_ops->rate_get(clk->handle, clk->id, &rate);
	if (ret)
		return 0;
	return rate;
}

__attribute__((used)) static long scmi_clk_round_rate(struct clk_hw *hw, unsigned long rate,
				unsigned long *parent_rate)
{
	u64 fmin, fmax, ftmp;
	struct scmi_clk *clk = to_scmi_clk(hw);

	/*
	 * We can't figure out what rate it will be, so just return the
	 * rate back to the caller. scmi_clk_recalc_rate() will be called
	 * after the rate is set and we'll know what rate the clock is
	 * running at then.
	 */
	if (clk->info->rate_discrete)
		return rate;

	fmin = clk->info->range.min_rate;
	fmax = clk->info->range.max_rate;
	if (rate <= fmin)
		return fmin;
	else if (rate >= fmax)
		return fmax;

	ftmp = rate - fmin;
	ftmp += clk->info->range.step_size - 1; /* to round up */
	do_div(ftmp, clk->info->range.step_size);

	return ftmp * clk->info->range.step_size + fmin;
}

__attribute__((used)) static int scmi_clk_set_rate(struct clk_hw *hw, unsigned long rate,
			     unsigned long parent_rate)
{
	struct scmi_clk *clk = to_scmi_clk(hw);

	return clk->handle->clk_ops->rate_set(clk->handle, clk->id, 0, rate);
}

__attribute__((used)) static int scmi_clk_enable(struct clk_hw *hw)
{
	struct scmi_clk *clk = to_scmi_clk(hw);

	return clk->handle->clk_ops->enable(clk->handle, clk->id);
}

__attribute__((used)) static void scmi_clk_disable(struct clk_hw *hw)
{
	struct scmi_clk *clk = to_scmi_clk(hw);

	clk->handle->clk_ops->disable(clk->handle, clk->id);
}

__attribute__((used)) static int scmi_clk_ops_init(struct device *dev, struct scmi_clk *sclk)
{
	int ret;
	struct clk_init_data init = {
		.flags = CLK_GET_RATE_NOCACHE,
		.num_parents = 0,
		.ops = &scmi_clk_ops,
		.name = sclk->info->name,
	};

	sclk->hw.init = &init;
	ret = devm_clk_hw_register(dev, &sclk->hw);
	if (!ret)
		clk_hw_set_rate_range(&sclk->hw, sclk->info->range.min_rate,
				      sclk->info->range.max_rate);
	return ret;
}

__attribute__((used)) static int scmi_clocks_probe(struct scmi_device *sdev)
{
	int idx, count, err;
	struct clk_hw **hws;
	struct clk_hw_onecell_data *clk_data;
	struct device *dev = &sdev->dev;
	struct device_node *np = dev->of_node;
	const struct scmi_handle *handle = sdev->handle;

	if (!handle || !handle->clk_ops)
		return -ENODEV;

	count = handle->clk_ops->count_get(handle);
	if (count < 0) {
		dev_err(dev, "%s: invalid clock output count\n", np->name);
		return -EINVAL;
	}

	clk_data = devm_kzalloc(dev, struct_size(clk_data, hws, count),
				GFP_KERNEL);
	if (!clk_data)
		return -ENOMEM;

	clk_data->num = count;
	hws = clk_data->hws;

	for (idx = 0; idx < count; idx++) {
		struct scmi_clk *sclk;

		sclk = devm_kzalloc(dev, sizeof(*sclk), GFP_KERNEL);
		if (!sclk)
			return -ENOMEM;

		sclk->info = handle->clk_ops->info_get(handle, idx);
		if (!sclk->info) {
			dev_dbg(dev, "invalid clock info for idx %d\n", idx);
			continue;
		}

		sclk->id = idx;
		sclk->handle = handle;

		err = scmi_clk_ops_init(dev, sclk);
		if (err) {
			dev_err(dev, "failed to register clock %d\n", idx);
			devm_kfree(dev, sclk);
			hws[idx] = NULL;
		} else {
			dev_dbg(dev, "Registered clock:%s\n", sclk->info->name);
			hws[idx] = &sclk->hw;
		}
	}

	return devm_of_clk_add_hw_provider(dev, of_clk_hw_onecell_get,
					   clk_data);
}

