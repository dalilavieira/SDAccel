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
struct TYPE_2__ {char const* dev_id; char const* con_id; struct clk* clk; } ;
struct clk {unsigned int bits; int module; scalar_t__ rate; scalar_t__* rates; int (* enable ) (struct clk*) ;void (* disable ) (struct clk*) ;TYPE_1__ cl; } ;

/* Variables and functions */
 scalar_t__ CLOCK_33M ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 unsigned int PMU_PCI ; 
 int /*<<< orphan*/  PMU_PWDCR ; 
 int /*<<< orphan*/  PMU_PWDSR ; 
 int /*<<< orphan*/  PWDCR (int) ; 
 int /*<<< orphan*/  PWDCR_DIS_XRX (int) ; 
 int /*<<< orphan*/  PWDCR_EN_XRX (int) ; 
 int /*<<< orphan*/  PWDSR (int) ; 
 int /*<<< orphan*/  PWDSR_XRX (int) ; 
 int /*<<< orphan*/  clkdev_add (TYPE_1__*) ; 
 int /*<<< orphan*/  g_pmu_lock ; 
 int /*<<< orphan*/  ifccr ; 
 void* kzalloc (int,int /*<<< orphan*/ ) ; 
 int ltq_cgu_r32 (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ltq_cgu_w32 (unsigned int,int /*<<< orphan*/ ) ; 
 scalar_t__ of_machine_is_compatible (char*) ; 
 int /*<<< orphan*/  panic (char*) ; 
 int /*<<< orphan*/  pcicr ; 
 unsigned int pmu_r32 (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  pmu_w32 (unsigned int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  pr_warn (char*) ; 
 int /*<<< orphan*/  spin_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  spin_unlock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  sprintf (char*,char*,int) ; 
 scalar_t__** valid_clkout_rates ; 
 scalar_t__* valid_pci_rates ; 

void ltq_pmu_enable(unsigned int module)
{
	int retry = 1000000;

	spin_lock(&g_pmu_lock);
	pmu_w32(pmu_r32(PMU_PWDCR) & ~module, PMU_PWDCR);
	do {} while (--retry && (pmu_r32(PMU_PWDSR) & module));
	spin_unlock(&g_pmu_lock);

	if (!retry)
		panic("activating PMU module failed!");
}

void ltq_pmu_disable(unsigned int module)
{
	int retry = 1000000;

	spin_lock(&g_pmu_lock);
	pmu_w32(pmu_r32(PMU_PWDCR) | module, PMU_PWDCR);
	do {} while (--retry && (!(pmu_r32(PMU_PWDSR) & module)));
	spin_unlock(&g_pmu_lock);

	if (!retry)
		pr_warn("deactivating PMU module failed!");
}

__attribute__((used)) static int cgu_enable(struct clk *clk)
{
	ltq_cgu_w32(ltq_cgu_r32(ifccr) | clk->bits, ifccr);
	return 0;
}

__attribute__((used)) static void cgu_disable(struct clk *clk)
{
	ltq_cgu_w32(ltq_cgu_r32(ifccr) & ~clk->bits, ifccr);
}

__attribute__((used)) static int pmu_enable(struct clk *clk)
{
	int retry = 1000000;

	if (of_machine_is_compatible("lantiq,ar10")
	    || of_machine_is_compatible("lantiq,grx390")) {
		pmu_w32(clk->bits, PWDCR_EN_XRX(clk->module));
		do {} while (--retry &&
			     (!(pmu_r32(PWDSR_XRX(clk->module)) & clk->bits)));

	} else {
		spin_lock(&g_pmu_lock);
		pmu_w32(pmu_r32(PWDCR(clk->module)) & ~clk->bits,
				PWDCR(clk->module));
		do {} while (--retry &&
			     (pmu_r32(PWDSR(clk->module)) & clk->bits));
		spin_unlock(&g_pmu_lock);
	}

	if (!retry)
		panic("activating PMU module failed!");

	return 0;
}

__attribute__((used)) static void pmu_disable(struct clk *clk)
{
	int retry = 1000000;

	if (of_machine_is_compatible("lantiq,ar10")
	    || of_machine_is_compatible("lantiq,grx390")) {
		pmu_w32(clk->bits, PWDCR_DIS_XRX(clk->module));
		do {} while (--retry &&
			     (pmu_r32(PWDSR_XRX(clk->module)) & clk->bits));
	} else {
		spin_lock(&g_pmu_lock);
		pmu_w32(pmu_r32(PWDCR(clk->module)) | clk->bits,
				PWDCR(clk->module));
		do {} while (--retry &&
			     (!(pmu_r32(PWDSR(clk->module)) & clk->bits)));
		spin_unlock(&g_pmu_lock);
	}

	if (!retry)
		pr_warn("deactivating PMU module failed!");
}

__attribute__((used)) static int pci_enable(struct clk *clk)
{
	unsigned int val = ltq_cgu_r32(ifccr);
	/* set bus clock speed */
	if (of_machine_is_compatible("lantiq,ar9") ||
			of_machine_is_compatible("lantiq,vr9")) {
		val &= ~0x1f00000;
		if (clk->rate == CLOCK_33M)
			val |= 0xe00000;
		else
			val |= 0x700000; /* 62.5M */
	} else {
		val &= ~0xf00000;
		if (clk->rate == CLOCK_33M)
			val |= 0x800000;
		else
			val |= 0x400000; /* 62.5M */
	}
	ltq_cgu_w32(val, ifccr);
	pmu_enable(clk);
	return 0;
}

__attribute__((used)) static int pci_ext_enable(struct clk *clk)
{
	ltq_cgu_w32(ltq_cgu_r32(ifccr) & ~(1 << 16), ifccr);
	ltq_cgu_w32((1 << 30), pcicr);
	return 0;
}

__attribute__((used)) static void pci_ext_disable(struct clk *clk)
{
	ltq_cgu_w32(ltq_cgu_r32(ifccr) | (1 << 16), ifccr);
	ltq_cgu_w32((1 << 31) | (1 << 30), pcicr);
}

__attribute__((used)) static int clkout_enable(struct clk *clk)
{
	int i;

	/* get the correct rate */
	for (i = 0; i < 4; i++) {
		if (clk->rates[i] == clk->rate) {
			int shift = 14 - (2 * clk->module);
			int enable = 7 - clk->module;
			unsigned int val = ltq_cgu_r32(ifccr);

			val &= ~(3 << shift);
			val |= i << shift;
			val |= enable;
			ltq_cgu_w32(val, ifccr);
			return 0;
		}
	}
	return -1;
}

__attribute__((used)) static void clkdev_add_pmu(const char *dev, const char *con, bool deactivate,
			   unsigned int module, unsigned int bits)
{
	struct clk *clk = kzalloc(sizeof(struct clk), GFP_KERNEL);

	clk->cl.dev_id = dev;
	clk->cl.con_id = con;
	clk->cl.clk = clk;
	clk->enable = pmu_enable;
	clk->disable = pmu_disable;
	clk->module = module;
	clk->bits = bits;
	if (deactivate) {
		/*
		 * Disable it during the initialization. Module should enable
		 * when used
		 */
		pmu_disable(clk);
	}
	clkdev_add(&clk->cl);
}

__attribute__((used)) static void clkdev_add_cgu(const char *dev, const char *con,
					unsigned int bits)
{
	struct clk *clk = kzalloc(sizeof(struct clk), GFP_KERNEL);

	clk->cl.dev_id = dev;
	clk->cl.con_id = con;
	clk->cl.clk = clk;
	clk->enable = cgu_enable;
	clk->disable = cgu_disable;
	clk->bits = bits;
	clkdev_add(&clk->cl);
}

__attribute__((used)) static void clkdev_add_pci(void)
{
	struct clk *clk = kzalloc(sizeof(struct clk), GFP_KERNEL);
	struct clk *clk_ext = kzalloc(sizeof(struct clk), GFP_KERNEL);

	/* main pci clock */
	clk->cl.dev_id = "17000000.pci";
	clk->cl.con_id = NULL;
	clk->cl.clk = clk;
	clk->rate = CLOCK_33M;
	clk->rates = valid_pci_rates;
	clk->enable = pci_enable;
	clk->disable = pmu_disable;
	clk->module = 0;
	clk->bits = PMU_PCI;
	clkdev_add(&clk->cl);

	/* use internal/external bus clock */
	clk_ext->cl.dev_id = "17000000.pci";
	clk_ext->cl.con_id = "external";
	clk_ext->cl.clk = clk_ext;
	clk_ext->enable = pci_ext_enable;
	clk_ext->disable = pci_ext_disable;
	clkdev_add(&clk_ext->cl);
}

__attribute__((used)) static void clkdev_add_clkout(void)
{
	int i;

	for (i = 0; i < 4; i++) {
		struct clk *clk;
		char *name;

		name = kzalloc(sizeof("clkout0"), GFP_KERNEL);
		sprintf(name, "clkout%d", i);

		clk = kzalloc(sizeof(struct clk), GFP_KERNEL);
		clk->cl.dev_id = "1f103000.cgu";
		clk->cl.con_id = name;
		clk->cl.clk = clk;
		clk->rate = 0;
		clk->rates = valid_clkout_rates[i];
		clk->enable = clkout_enable;
		clk->module = i;
		clkdev_add(&clk->cl);
	}
}

