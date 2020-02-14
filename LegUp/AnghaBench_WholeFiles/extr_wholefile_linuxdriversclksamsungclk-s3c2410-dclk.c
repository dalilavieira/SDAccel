#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_9__   TYPE_5__ ;
typedef  struct TYPE_8__   TYPE_3__ ;
typedef  struct TYPE_7__   TYPE_2__ ;
typedef  struct TYPE_6__   TYPE_1__ ;

/* Type definitions */
typedef  int u8 ;
typedef  int u32 ;
struct s3c24xx_dclk_drv_data {char** clkout0_parent_names; int clkout0_num_parents; char** clkout1_parent_names; int clkout1_num_parents; int /*<<< orphan*/  mux_num_parents; int /*<<< orphan*/  mux_parent_names; } ;
struct TYPE_8__ {int (* notifier_call ) (struct notifier_block*,unsigned long,void*) ;} ;
struct TYPE_6__ {int num; struct clk_hw** hws; } ;
struct s3c24xx_dclk {TYPE_3__ dclk0_div_change_nb; TYPE_3__ dclk1_div_change_nb; TYPE_1__ clk_data; int /*<<< orphan*/  dclk_lock; struct clk_hw* base; struct device* dev; } ;
struct clk_hw {int /*<<< orphan*/  clk; struct clk_init_data* init; } ;
struct s3c24xx_clkout {int shift; int mask; struct clk_hw hw; } ;
struct resource {int dummy; } ;
struct device {int dummy; } ;
struct platform_device {struct device dev; } ;
struct notifier_block {int dummy; } ;
struct clk_init_data {char const* name; char const** parent_names; int num_parents; int /*<<< orphan*/  flags; int /*<<< orphan*/ * ops; } ;
struct TYPE_9__ {int /*<<< orphan*/  hws; } ;
struct TYPE_7__ {scalar_t__ driver_data; } ;

/* Variables and functions */
 int /*<<< orphan*/  CLK_IS_BASIC ; 
 int /*<<< orphan*/  CLK_SET_RATE_PARENT ; 
 int DCLKCON_DCLK0_CMP_SHIFT ; 
 int DCLKCON_DCLK0_DIV_SHIFT ; 
 int DCLKCON_DCLK1_CMP_SHIFT ; 
 int DCLKCON_DCLK1_DIV_SHIFT ; 
 int DCLKCON_DCLK_DIV_MASK ; 
 int DCLK_MAX_CLKS ; 
 size_t DIV_DCLK0 ; 
 size_t DIV_DCLK1 ; 
 int EINVAL ; 
 int ENOMEM ; 
 struct clk_hw* ERR_PTR (int) ; 
 size_t GATE_DCLK0 ; 
 size_t GATE_DCLK1 ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int /*<<< orphan*/  IORESOURCE_MEM ; 
 scalar_t__ IS_ERR (struct clk_hw*) ; 
 size_t MUX_CLKOUT0 ; 
 size_t MUX_CLKOUT1 ; 
 size_t MUX_DCLK0 ; 
 size_t MUX_DCLK1 ; 
 int NOTIFY_DONE ; 
 unsigned long POST_RATE_CHANGE ; 
 int PTR_ERR (struct clk_hw*) ; 
 struct clk_hw* S3C24XX_MISCCR ; 
 TYPE_5__ clk_data ; 
 int clk_hw_get_num_parents (struct clk_hw*) ; 
 int clk_hw_register (struct device*,struct clk_hw*) ; 
 int clk_hw_register_clkdev (struct clk_hw*,char*,int /*<<< orphan*/ *) ; 
 struct clk_hw* clk_hw_register_divider (struct device*,char*,char*,int /*<<< orphan*/ ,struct clk_hw*,int,int,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 struct clk_hw* clk_hw_register_gate (struct device*,char*,char*,int /*<<< orphan*/ ,struct clk_hw*,int,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 struct clk_hw* clk_hw_register_mux (struct device*,char*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,struct clk_hw*,int,int,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  clk_hw_unregister (struct clk_hw*) ; 
 int clk_notifier_register (int /*<<< orphan*/ ,TYPE_3__*) ; 
 int /*<<< orphan*/  clk_notifier_unregister (int /*<<< orphan*/ ,TYPE_3__*) ; 
 int /*<<< orphan*/  dev_err (struct device*,char*,int) ; 
 struct clk_hw* devm_ioremap_resource (struct device*,struct resource*) ; 
 struct s3c24xx_dclk* devm_kzalloc (struct device*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 struct s3c24xx_clkout* kzalloc (int,int /*<<< orphan*/ ) ; 
 TYPE_2__* platform_get_device_id (struct platform_device*) ; 
 struct s3c24xx_dclk* platform_get_drvdata (struct platform_device*) ; 
 struct resource* platform_get_resource (struct platform_device*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  platform_set_drvdata (struct platform_device*,struct s3c24xx_dclk*) ; 
 int readl_relaxed (struct clk_hw*) ; 
 int /*<<< orphan*/  s3c2410_modify_misccr (int,int) ; 
 int /*<<< orphan*/  s3c24xx_clkout_ops ; 
 int /*<<< orphan*/  spin_lock_init (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  spin_lock_irqsave (int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  spin_unlock_irqrestore (int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  struct_size (struct s3c24xx_dclk*,int /*<<< orphan*/ ,int) ; 
 struct s3c24xx_clkout* to_s3c24xx_clkout (struct clk_hw*) ; 
 struct s3c24xx_dclk* to_s3c24xx_dclk0 (struct notifier_block*) ; 
 struct s3c24xx_dclk* to_s3c24xx_dclk1 (struct notifier_block*) ; 
 int /*<<< orphan*/  writel_relaxed (int,struct clk_hw*) ; 

__attribute__((used)) static u8 s3c24xx_clkout_get_parent(struct clk_hw *hw)
{
	struct s3c24xx_clkout *clkout = to_s3c24xx_clkout(hw);
	int num_parents = clk_hw_get_num_parents(hw);
	u32 val;

	val = readl_relaxed(S3C24XX_MISCCR) >> clkout->shift;
	val >>= clkout->shift;
	val &= clkout->mask;

	if (val >= num_parents)
		return -EINVAL;

	return val;
}

__attribute__((used)) static int s3c24xx_clkout_set_parent(struct clk_hw *hw, u8 index)
{
	struct s3c24xx_clkout *clkout = to_s3c24xx_clkout(hw);

	s3c2410_modify_misccr((clkout->mask << clkout->shift),
			      (index << clkout->shift));

	return 0;
}

__attribute__((used)) static struct clk_hw *s3c24xx_register_clkout(struct device *dev,
		const char *name, const char **parent_names, u8 num_parents,
		u8 shift, u32 mask)
{
	struct s3c24xx_clkout *clkout;
	struct clk_init_data init;
	int ret;

	/* allocate the clkout */
	clkout = kzalloc(sizeof(*clkout), GFP_KERNEL);
	if (!clkout)
		return ERR_PTR(-ENOMEM);

	init.name = name;
	init.ops = &s3c24xx_clkout_ops;
	init.flags = CLK_IS_BASIC;
	init.parent_names = parent_names;
	init.num_parents = num_parents;

	clkout->shift = shift;
	clkout->mask = mask;
	clkout->hw.init = &init;

	ret = clk_hw_register(dev, &clkout->hw);
	if (ret)
		return ERR_PTR(ret);

	return &clkout->hw;
}

__attribute__((used)) static void s3c24xx_dclk_update_cmp(struct s3c24xx_dclk *s3c24xx_dclk,
				    int div_shift, int cmp_shift)
{
	unsigned long flags = 0;
	u32 dclk_con, div, cmp;

	spin_lock_irqsave(&s3c24xx_dclk->dclk_lock, flags);

	dclk_con = readl_relaxed(s3c24xx_dclk->base);

	div = ((dclk_con >> div_shift) & DCLKCON_DCLK_DIV_MASK) + 1;
	cmp = ((div + 1) / 2) - 1;

	dclk_con &= ~(DCLKCON_DCLK_DIV_MASK << cmp_shift);
	dclk_con |= (cmp << cmp_shift);

	writel_relaxed(dclk_con, s3c24xx_dclk->base);

	spin_unlock_irqrestore(&s3c24xx_dclk->dclk_lock, flags);
}

__attribute__((used)) static int s3c24xx_dclk0_div_notify(struct notifier_block *nb,
			       unsigned long event, void *data)
{
	struct s3c24xx_dclk *s3c24xx_dclk = to_s3c24xx_dclk0(nb);

	if (event == POST_RATE_CHANGE) {
		s3c24xx_dclk_update_cmp(s3c24xx_dclk,
			DCLKCON_DCLK0_DIV_SHIFT, DCLKCON_DCLK0_CMP_SHIFT);
	}

	return NOTIFY_DONE;
}

__attribute__((used)) static int s3c24xx_dclk1_div_notify(struct notifier_block *nb,
			       unsigned long event, void *data)
{
	struct s3c24xx_dclk *s3c24xx_dclk = to_s3c24xx_dclk1(nb);

	if (event == POST_RATE_CHANGE) {
		s3c24xx_dclk_update_cmp(s3c24xx_dclk,
			DCLKCON_DCLK1_DIV_SHIFT, DCLKCON_DCLK1_CMP_SHIFT);
	}

	return NOTIFY_DONE;
}

__attribute__((used)) static int s3c24xx_dclk_probe(struct platform_device *pdev)
{
	struct s3c24xx_dclk *s3c24xx_dclk;
	struct resource *mem;
	struct s3c24xx_dclk_drv_data *dclk_variant;
	struct clk_hw **clk_table;
	int ret, i;

	s3c24xx_dclk = devm_kzalloc(&pdev->dev,
				    struct_size(s3c24xx_dclk, clk_data.hws,
						DCLK_MAX_CLKS),
				    GFP_KERNEL);
	if (!s3c24xx_dclk)
		return -ENOMEM;

	clk_table = s3c24xx_dclk->clk_data.hws;

	s3c24xx_dclk->dev = &pdev->dev;
	s3c24xx_dclk->clk_data.num = DCLK_MAX_CLKS;
	platform_set_drvdata(pdev, s3c24xx_dclk);
	spin_lock_init(&s3c24xx_dclk->dclk_lock);

	mem = platform_get_resource(pdev, IORESOURCE_MEM, 0);
	s3c24xx_dclk->base = devm_ioremap_resource(&pdev->dev, mem);
	if (IS_ERR(s3c24xx_dclk->base))
		return PTR_ERR(s3c24xx_dclk->base);

	dclk_variant = (struct s3c24xx_dclk_drv_data *)
				platform_get_device_id(pdev)->driver_data;


	clk_table[MUX_DCLK0] = clk_hw_register_mux(&pdev->dev, "mux_dclk0",
				dclk_variant->mux_parent_names,
				dclk_variant->mux_num_parents, 0,
				s3c24xx_dclk->base, 1, 1, 0,
				&s3c24xx_dclk->dclk_lock);
	clk_table[MUX_DCLK1] = clk_hw_register_mux(&pdev->dev, "mux_dclk1",
				dclk_variant->mux_parent_names,
				dclk_variant->mux_num_parents, 0,
				s3c24xx_dclk->base, 17, 1, 0,
				&s3c24xx_dclk->dclk_lock);

	clk_table[DIV_DCLK0] = clk_hw_register_divider(&pdev->dev, "div_dclk0",
				"mux_dclk0", 0, s3c24xx_dclk->base,
				4, 4, 0, &s3c24xx_dclk->dclk_lock);
	clk_table[DIV_DCLK1] = clk_hw_register_divider(&pdev->dev, "div_dclk1",
				"mux_dclk1", 0, s3c24xx_dclk->base,
				20, 4, 0, &s3c24xx_dclk->dclk_lock);

	clk_table[GATE_DCLK0] = clk_hw_register_gate(&pdev->dev, "gate_dclk0",
				"div_dclk0", CLK_SET_RATE_PARENT,
				s3c24xx_dclk->base, 0, 0,
				&s3c24xx_dclk->dclk_lock);
	clk_table[GATE_DCLK1] = clk_hw_register_gate(&pdev->dev, "gate_dclk1",
				"div_dclk1", CLK_SET_RATE_PARENT,
				s3c24xx_dclk->base, 16, 0,
				&s3c24xx_dclk->dclk_lock);

	clk_table[MUX_CLKOUT0] = s3c24xx_register_clkout(&pdev->dev,
				"clkout0", dclk_variant->clkout0_parent_names,
				dclk_variant->clkout0_num_parents, 4, 7);
	clk_table[MUX_CLKOUT1] = s3c24xx_register_clkout(&pdev->dev,
				"clkout1", dclk_variant->clkout1_parent_names,
				dclk_variant->clkout1_num_parents, 8, 7);

	for (i = 0; i < DCLK_MAX_CLKS; i++)
		if (IS_ERR(clk_table[i])) {
			dev_err(&pdev->dev, "clock %d failed to register\n", i);
			ret = PTR_ERR(clk_table[i]);
			goto err_clk_register;
		}

	ret = clk_hw_register_clkdev(clk_table[MUX_DCLK0], "dclk0", NULL);
	if (!ret)
		ret = clk_hw_register_clkdev(clk_table[MUX_DCLK1], "dclk1",
					     NULL);
	if (!ret)
		ret = clk_hw_register_clkdev(clk_table[MUX_CLKOUT0],
					     "clkout0", NULL);
	if (!ret)
		ret = clk_hw_register_clkdev(clk_table[MUX_CLKOUT1],
					     "clkout1", NULL);
	if (ret) {
		dev_err(&pdev->dev, "failed to register aliases, %d\n", ret);
		goto err_clk_register;
	}

	s3c24xx_dclk->dclk0_div_change_nb.notifier_call =
						s3c24xx_dclk0_div_notify;

	s3c24xx_dclk->dclk1_div_change_nb.notifier_call =
						s3c24xx_dclk1_div_notify;

	ret = clk_notifier_register(clk_table[DIV_DCLK0]->clk,
				    &s3c24xx_dclk->dclk0_div_change_nb);
	if (ret)
		goto err_clk_register;

	ret = clk_notifier_register(clk_table[DIV_DCLK1]->clk,
				    &s3c24xx_dclk->dclk1_div_change_nb);
	if (ret)
		goto err_dclk_notify;

	return 0;

err_dclk_notify:
	clk_notifier_unregister(clk_table[DIV_DCLK0]->clk,
				&s3c24xx_dclk->dclk0_div_change_nb);
err_clk_register:
	for (i = 0; i < DCLK_MAX_CLKS; i++)
		if (clk_table[i] && !IS_ERR(clk_table[i]))
			clk_hw_unregister(clk_table[i]);

	return ret;
}

__attribute__((used)) static int s3c24xx_dclk_remove(struct platform_device *pdev)
{
	struct s3c24xx_dclk *s3c24xx_dclk = platform_get_drvdata(pdev);
	struct clk_hw **clk_table = s3c24xx_dclk->clk_data.hws;
	int i;

	clk_notifier_unregister(clk_table[DIV_DCLK1]->clk,
				&s3c24xx_dclk->dclk1_div_change_nb);
	clk_notifier_unregister(clk_table[DIV_DCLK0]->clk,
				&s3c24xx_dclk->dclk0_div_change_nb);

	for (i = 0; i < DCLK_MAX_CLKS; i++)
		clk_hw_unregister(clk_table[i]);

	return 0;
}

