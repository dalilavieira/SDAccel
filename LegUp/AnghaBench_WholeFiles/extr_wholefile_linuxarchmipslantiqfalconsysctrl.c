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
struct TYPE_2__ {char const* dev_id; struct clk* clk; int /*<<< orphan*/ * con_id; } ;
struct clk {unsigned int module; unsigned int bits; int (* activate ) (struct clk*) ;void (* deactivate ) (struct clk*) ;int (* enable ) (struct clk*) ;void (* disable ) (struct clk*) ;void (* reboot ) (struct clk*) ;TYPE_1__ cl; } ;

/* Variables and functions */
 int /*<<< orphan*/  GFP_KERNEL ; 
 unsigned int GPEFREQ_MASK ; 
 unsigned int GPEFREQ_OFFSET ; 
 int GPPC_OFFSET ; 
 int /*<<< orphan*/  STATUS_CONFIG ; 
 unsigned int SYS1_HRSTOUTC ; 
 unsigned int SYS1_INFRAC ; 
 unsigned int SYSCTL_ACT ; 
 unsigned int SYSCTL_ACTS ; 
 unsigned int SYSCTL_CLKCLR ; 
 unsigned int SYSCTL_CLKEN ; 
 unsigned int SYSCTL_CLKS ; 
 unsigned int SYSCTL_DEACT ; 
 unsigned int SYSCTL_RBT ; 
 unsigned int SYSCTL_SYS1 ; 
 int /*<<< orphan*/  clkdev_add (TYPE_1__*) ; 
 struct clk* kzalloc (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  pr_err (char*,unsigned int,unsigned int,unsigned int,unsigned int) ; 
 unsigned int status_r32 (int /*<<< orphan*/ ) ; 
 unsigned int sysctl_r32 (unsigned int,unsigned int) ; 
 int /*<<< orphan*/  sysctl_w32 (unsigned int,unsigned int,unsigned int) ; 
 int /*<<< orphan*/  sysctl_w32_mask (unsigned int,int,int,unsigned int) ; 
 int /*<<< orphan*/  udelay (int) ; 

void falcon_trigger_hrst(int level)
{
	sysctl_w32(SYSCTL_SYS1, level & 1, SYS1_HRSTOUTC);
}

__attribute__((used)) static inline void sysctl_wait(struct clk *clk,
		unsigned int test, unsigned int reg)
{
	int err = 1000000;

	do {} while (--err && ((sysctl_r32(clk->module, reg)
					& clk->bits) != test));
	if (!err)
		pr_err("module de/activation failed %d %08X %08X %08X\n",
			clk->module, clk->bits, test,
			sysctl_r32(clk->module, reg) & clk->bits);
}

__attribute__((used)) static int sysctl_activate(struct clk *clk)
{
	sysctl_w32(clk->module, clk->bits, SYSCTL_CLKEN);
	sysctl_w32(clk->module, clk->bits, SYSCTL_ACT);
	sysctl_wait(clk, clk->bits, SYSCTL_ACTS);
	return 0;
}

__attribute__((used)) static void sysctl_deactivate(struct clk *clk)
{
	sysctl_w32(clk->module, clk->bits, SYSCTL_CLKCLR);
	sysctl_w32(clk->module, clk->bits, SYSCTL_DEACT);
	sysctl_wait(clk, 0, SYSCTL_ACTS);
}

__attribute__((used)) static int sysctl_clken(struct clk *clk)
{
	sysctl_w32(clk->module, clk->bits, SYSCTL_CLKEN);
	sysctl_w32(clk->module, clk->bits, SYSCTL_ACT);
	sysctl_wait(clk, clk->bits, SYSCTL_CLKS);
	return 0;
}

__attribute__((used)) static void sysctl_clkdis(struct clk *clk)
{
	sysctl_w32(clk->module, clk->bits, SYSCTL_CLKCLR);
	sysctl_wait(clk, 0, SYSCTL_CLKS);
}

__attribute__((used)) static void sysctl_reboot(struct clk *clk)
{
	unsigned int act;
	unsigned int bits;

	act = sysctl_r32(clk->module, SYSCTL_ACT);
	bits = ~act & clk->bits;
	if (bits != 0) {
		sysctl_w32(clk->module, bits, SYSCTL_CLKEN);
		sysctl_w32(clk->module, bits, SYSCTL_ACT);
		sysctl_wait(clk, bits, SYSCTL_ACTS);
	}
	sysctl_w32(clk->module, act & clk->bits, SYSCTL_RBT);
	sysctl_wait(clk, clk->bits, SYSCTL_ACTS);
}

__attribute__((used)) static void falcon_gpe_enable(void)
{
	unsigned int freq;
	unsigned int status;

	/* if if the clock is already enabled */
	status = sysctl_r32(SYSCTL_SYS1, SYS1_INFRAC);
	if (status & (1 << (GPPC_OFFSET + 1)))
		return;

	freq = (status_r32(STATUS_CONFIG) &
		GPEFREQ_MASK) >>
		GPEFREQ_OFFSET;
	if (freq == 0)
		freq = 1; /* use 625MHz on unfused chip */

	/* apply new frequency */
	sysctl_w32_mask(SYSCTL_SYS1, 7 << (GPPC_OFFSET + 1),
		freq << (GPPC_OFFSET + 2) , SYS1_INFRAC);
	udelay(1);

	/* enable new frequency */
	sysctl_w32_mask(SYSCTL_SYS1, 0, 1 << (GPPC_OFFSET + 1), SYS1_INFRAC);
	udelay(1);
}

__attribute__((used)) static inline void clkdev_add_sys(const char *dev, unsigned int module,
					unsigned int bits)
{
	struct clk *clk = kzalloc(sizeof(struct clk), GFP_KERNEL);

	clk->cl.dev_id = dev;
	clk->cl.con_id = NULL;
	clk->cl.clk = clk;
	clk->module = module;
	clk->bits = bits;
	clk->activate = sysctl_activate;
	clk->deactivate = sysctl_deactivate;
	clk->enable = sysctl_clken;
	clk->disable = sysctl_clkdis;
	clk->reboot = sysctl_reboot;
	clkdev_add(&clk->cl);
}

