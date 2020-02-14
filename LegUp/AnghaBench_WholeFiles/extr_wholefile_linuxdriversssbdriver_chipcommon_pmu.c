#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_2__ ;
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  u8 ;
typedef  scalar_t__ u32 ;
typedef  int /*<<< orphan*/  u16 ;
struct ssb_extif {int dummy; } ;
struct ssb_device {int dummy; } ;
struct TYPE_3__ {scalar_t__ crystalfreq; int rev; } ;
struct ssb_chipcommon {int capabilities; TYPE_2__* dev; TYPE_1__ pmu; } ;
struct ssb_bus {int chip_id; scalar_t__ bustype; } ;
struct pmu_res_updown_tab_entry {scalar_t__ freq; scalar_t__ xf; scalar_t__ wb_frac; scalar_t__ resource; scalar_t__ updown; int task; scalar_t__ depend; scalar_t__ ndiv_frac; scalar_t__ ndiv_int; scalar_t__ p2div; scalar_t__ p1div; scalar_t__ wb_int; } ;
struct pmu_res_depend_tab_entry {scalar_t__ freq; scalar_t__ xf; scalar_t__ wb_frac; scalar_t__ resource; scalar_t__ updown; int task; scalar_t__ depend; scalar_t__ ndiv_frac; scalar_t__ ndiv_int; scalar_t__ p2div; scalar_t__ p1div; scalar_t__ wb_int; } ;
struct pmu1_plltab_entry {scalar_t__ freq; scalar_t__ xf; scalar_t__ wb_frac; scalar_t__ resource; scalar_t__ updown; int task; scalar_t__ depend; scalar_t__ ndiv_frac; scalar_t__ ndiv_int; scalar_t__ p2div; scalar_t__ p1div; scalar_t__ wb_int; } ;
struct pmu0_plltab_entry {scalar_t__ freq; scalar_t__ xf; scalar_t__ wb_frac; scalar_t__ resource; scalar_t__ updown; int task; scalar_t__ depend; scalar_t__ ndiv_frac; scalar_t__ ndiv_int; scalar_t__ p2div; scalar_t__ p1div; scalar_t__ wb_int; } ;
struct bcm47xx_wdt {int dummy; } ;
typedef  enum ssb_pmu_ldo_volt_id { ____Placeholder_ssb_pmu_ldo_volt_id } ssb_pmu_ldo_volt_id ;
struct TYPE_4__ {struct ssb_bus* bus; int /*<<< orphan*/  dev; } ;

/* Variables and functions */
 unsigned int ARRAY_SIZE (struct pmu_res_updown_tab_entry*) ; 
 int /*<<< orphan*/  BUG_ON (int) ; 
 int ENOTSUPP ; 
#define  LDO_PAREF 134 
#define  LDO_VOLT1 133 
#define  LDO_VOLT2 132 
#define  LDO_VOLT3 131 
#define  PMU_RES_DEP_ADD 130 
#define  PMU_RES_DEP_REMOVE 129 
#define  PMU_RES_DEP_SET 128 
 scalar_t__ SSB_BUSTYPE_SSB ; 
 int SSB_CHIPCO_CAP_PMU ; 
 int /*<<< orphan*/  SSB_CHIPCO_CHIPSTAT ; 
 scalar_t__ SSB_CHIPCO_CHST_4325_PMUTOP_2B ; 
 int /*<<< orphan*/  SSB_CHIPCO_CLKCTLST ; 
 scalar_t__ SSB_CHIPCO_CLKCTLST_HAVEHT ; 
 int /*<<< orphan*/  SSB_CHIPCO_PLLCTL_ADDR ; 
 int /*<<< orphan*/  SSB_CHIPCO_PLLCTL_DATA ; 
 int /*<<< orphan*/  SSB_CHIPCO_PMU_CAP ; 
 scalar_t__ SSB_CHIPCO_PMU_CAP_REVISION ; 
 int /*<<< orphan*/  SSB_CHIPCO_PMU_CTL ; 
 scalar_t__ SSB_CHIPCO_PMU_CTL_ILP_DIV ; 
 scalar_t__ SSB_CHIPCO_PMU_CTL_ILP_DIV_SHIFT ; 
 scalar_t__ SSB_CHIPCO_PMU_CTL_NOILPONW ; 
 scalar_t__ SSB_CHIPCO_PMU_CTL_PLL_UPD ; 
 scalar_t__ SSB_CHIPCO_PMU_CTL_XTALFREQ ; 
 scalar_t__ SSB_CHIPCO_PMU_CTL_XTALFREQ_SHIFT ; 
 int /*<<< orphan*/  SSB_CHIPCO_PMU_MAXRES_MSK ; 
 int /*<<< orphan*/  SSB_CHIPCO_PMU_MINRES_MSK ; 
 int /*<<< orphan*/  SSB_CHIPCO_PMU_RES_DEPMSK ; 
 int /*<<< orphan*/  SSB_CHIPCO_PMU_RES_TABSEL ; 
 int /*<<< orphan*/  SSB_CHIPCO_PMU_RES_UPDNTM ; 
 int /*<<< orphan*/  SSB_CHIPCO_REGCTL_ADDR ; 
 int /*<<< orphan*/  SSB_CHIPCO_REGCTL_DATA ; 
 scalar_t__ SSB_PMU0_DEFAULT_XTALFREQ ; 
 scalar_t__ SSB_PMU0_PLLCTL0 ; 
 scalar_t__ SSB_PMU0_PLLCTL0_PDIV_FREQ ; 
 scalar_t__ SSB_PMU0_PLLCTL0_PDIV_MSK ; 
 scalar_t__ SSB_PMU0_PLLCTL1 ; 
 scalar_t__ SSB_PMU0_PLLCTL1_STOPMOD ; 
 scalar_t__ SSB_PMU0_PLLCTL1_WILD_FMSK ; 
 scalar_t__ SSB_PMU0_PLLCTL1_WILD_FMSK_SHIFT ; 
 scalar_t__ SSB_PMU0_PLLCTL1_WILD_IMSK ; 
 scalar_t__ SSB_PMU0_PLLCTL1_WILD_IMSK_SHIFT ; 
 scalar_t__ SSB_PMU0_PLLCTL2 ; 
 scalar_t__ SSB_PMU0_PLLCTL2_WILD_IMSKHI ; 
 scalar_t__ SSB_PMU0_PLLCTL2_WILD_IMSKHI_SHIFT ; 
 scalar_t__ SSB_PMU1_DEFAULT_XTALFREQ ; 
 scalar_t__ SSB_PMU1_PLLCTL0 ; 
 scalar_t__ SSB_PMU1_PLLCTL0_P1DIV ; 
 scalar_t__ SSB_PMU1_PLLCTL0_P1DIV_SHIFT ; 
 scalar_t__ SSB_PMU1_PLLCTL0_P2DIV ; 
 scalar_t__ SSB_PMU1_PLLCTL0_P2DIV_SHIFT ; 
 scalar_t__ SSB_PMU1_PLLCTL1 ; 
 scalar_t__ SSB_PMU1_PLLCTL2 ; 
 scalar_t__ SSB_PMU1_PLLCTL2_NDIVINT ; 
 scalar_t__ SSB_PMU1_PLLCTL2_NDIVINT_SHIFT ; 
 scalar_t__ SSB_PMU1_PLLCTL2_NDIVMODE ; 
 int SSB_PMU1_PLLCTL2_NDIVMODE_SHIFT ; 
 scalar_t__ SSB_PMU1_PLLCTL3 ; 
 scalar_t__ SSB_PMU1_PLLCTL3_NDIVFRAC ; 
 scalar_t__ SSB_PMU1_PLLCTL3_NDIVFRAC_SHIFT ; 
 scalar_t__ SSB_PMU1_PLLCTL4 ; 
 scalar_t__ SSB_PMU1_PLLCTL5 ; 
 scalar_t__ SSB_PMU1_PLLCTL5_CLKDRV ; 
 scalar_t__ SSB_PMU1_PLLCTL5_CLKDRV_SHIFT ; 
 int SSB_PMURES_4312_PA_REF_LDO ; 
 int SSB_PMURES_4325_BBPLL_PWRSW_PU ; 
 int SSB_PMURES_4325_CBUCK_BURST ; 
 int SSB_PMURES_4325_CLDO_CBUCK_BURST ; 
 int SSB_PMURES_4325_HT_AVAIL ; 
 int SSB_PMURES_4325_LNLDO2_PU ; 
 int SSB_PMURES_4328_BB_PLL_PU ; 
 int SSB_PMURES_4328_BB_SWITCHER_PWM ; 
 int SSB_PMURES_4328_EXT_SWITCHER_PWM ; 
 int SSB_PMURES_4328_PA_REF_LDO ; 
 int SSB_PMURES_4328_XTAL_EN ; 
 int SSB_PMURES_5354_BB_PLL_PU ; 
 int SSB_PMURES_5354_PA_REF_LDO ; 
 int /*<<< orphan*/  WARN_ON (int) ; 
 int /*<<< orphan*/  chipco_mask32 (struct ssb_chipcommon*,int /*<<< orphan*/ ,int) ; 
 scalar_t__ chipco_read32 (struct ssb_chipcommon*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  chipco_set32 (struct ssb_chipcommon*,int /*<<< orphan*/ ,scalar_t__) ; 
 int /*<<< orphan*/  chipco_write32 (struct ssb_chipcommon*,int /*<<< orphan*/ ,scalar_t__) ; 
 int /*<<< orphan*/  dev_dbg (int /*<<< orphan*/ ,char*,int,scalar_t__) ; 
 int /*<<< orphan*/  dev_emerg (int /*<<< orphan*/ ,char*) ; 
 int /*<<< orphan*/  dev_err (int /*<<< orphan*/ ,char*,int) ; 
 int /*<<< orphan*/  dev_info (int /*<<< orphan*/ ,char*,scalar_t__,scalar_t__) ; 
 struct pmu_res_updown_tab_entry* pmu0_plltab ; 
 struct pmu_res_updown_tab_entry* pmu1_plltab ; 
 struct pmu_res_updown_tab_entry* pmu_res_depend_tab_4325a0 ; 
 struct pmu_res_updown_tab_entry* pmu_res_depend_tab_4328a0 ; 
 struct pmu_res_updown_tab_entry* pmu_res_updown_tab_4325a0 ; 
 struct pmu_res_updown_tab_entry* pmu_res_updown_tab_4328a0 ; 
 int /*<<< orphan*/  pr_err (char*) ; 
 int /*<<< orphan*/  udelay (int) ; 

__attribute__((used)) static inline int ssb_pci_switch_core(struct ssb_bus *bus,
				      struct ssb_device *dev)
{
	return 0;
}

__attribute__((used)) static inline int ssb_pci_switch_coreidx(struct ssb_bus *bus,
					 u8 coreidx)
{
	return 0;
}

__attribute__((used)) static inline int ssb_pci_xtal(struct ssb_bus *bus, u32 what,
			       int turn_on)
{
	return 0;
}

__attribute__((used)) static inline void ssb_pci_exit(struct ssb_bus *bus)
{
}

__attribute__((used)) static inline int ssb_pci_init(struct ssb_bus *bus)
{
	return 0;
}

__attribute__((used)) static inline int ssb_pcmcia_switch_coreidx(struct ssb_bus *bus,
					    u8 coreidx)
{
	return 0;
}

__attribute__((used)) static inline int ssb_pcmcia_switch_segment(struct ssb_bus *bus,
					    u8 seg)
{
	return 0;
}

__attribute__((used)) static inline int ssb_pcmcia_hardware_setup(struct ssb_bus *bus)
{
	return 0;
}

__attribute__((used)) static inline void ssb_pcmcia_exit(struct ssb_bus *bus)
{
}

__attribute__((used)) static inline int ssb_pcmcia_init(struct ssb_bus *bus)
{
	return 0;
}

__attribute__((used)) static inline int ssb_host_pcmcia_init(void)
{
	return 0;
}

__attribute__((used)) static inline void ssb_host_pcmcia_exit(void)
{
}

__attribute__((used)) static inline u32 ssb_sdio_scan_read32(struct ssb_bus *bus, u16 offset)
{
	return 0;
}

__attribute__((used)) static inline int ssb_sdio_scan_switch_coreidx(struct ssb_bus *bus, u8 coreidx)
{
	return 0;
}

__attribute__((used)) static inline void ssb_sdio_exit(struct ssb_bus *bus)
{
}

__attribute__((used)) static inline int ssb_sdio_init(struct ssb_bus *bus)
{
	return 0;
}

__attribute__((used)) static inline int b43_pci_ssb_bridge_init(void)
{
	return 0;
}

__attribute__((used)) static inline void b43_pci_ssb_bridge_exit(void)
{
}

__attribute__((used)) static inline int ssb_sflash_init(struct ssb_chipcommon *cc)
{
	pr_err("Serial flash not supported\n");
	return 0;
}

__attribute__((used)) static inline u32 ssb_extif_watchdog_timer_set_wdt(struct bcm47xx_wdt *wdt,
						   u32 ticks)
{
	return 0;
}

__attribute__((used)) static inline u32 ssb_extif_watchdog_timer_set_ms(struct bcm47xx_wdt *wdt,
						  u32 ms)
{
	return 0;
}

__attribute__((used)) static inline int ssb_watchdog_register(struct ssb_bus *bus)
{
	return 0;
}

__attribute__((used)) static inline void ssb_extif_init(struct ssb_extif *extif)
{
}

__attribute__((used)) static inline int ssb_gpio_init(struct ssb_bus *bus)
{
	return -ENOTSUPP;
}

__attribute__((used)) static inline int ssb_gpio_unregister(struct ssb_bus *bus)
{
	return 0;
}

__attribute__((used)) static u32 ssb_chipco_pll_read(struct ssb_chipcommon *cc, u32 offset)
{
	chipco_write32(cc, SSB_CHIPCO_PLLCTL_ADDR, offset);
	return chipco_read32(cc, SSB_CHIPCO_PLLCTL_DATA);
}

__attribute__((used)) static void ssb_chipco_pll_write(struct ssb_chipcommon *cc,
				 u32 offset, u32 value)
{
	chipco_write32(cc, SSB_CHIPCO_PLLCTL_ADDR, offset);
	chipco_write32(cc, SSB_CHIPCO_PLLCTL_DATA, value);
}

__attribute__((used)) static void ssb_chipco_regctl_maskset(struct ssb_chipcommon *cc,
				   u32 offset, u32 mask, u32 set)
{
	u32 value;

	chipco_read32(cc, SSB_CHIPCO_REGCTL_ADDR);
	chipco_write32(cc, SSB_CHIPCO_REGCTL_ADDR, offset);
	chipco_read32(cc, SSB_CHIPCO_REGCTL_ADDR);
	value = chipco_read32(cc, SSB_CHIPCO_REGCTL_DATA);
	value &= mask;
	value |= set;
	chipco_write32(cc, SSB_CHIPCO_REGCTL_DATA, value);
	chipco_read32(cc, SSB_CHIPCO_REGCTL_DATA);
}

__attribute__((used)) static const struct pmu0_plltab_entry * pmu0_plltab_find_entry(u32 crystalfreq)
{
	const struct pmu0_plltab_entry *e;
	unsigned int i;

	for (i = 0; i < ARRAY_SIZE(pmu0_plltab); i++) {
		e = &pmu0_plltab[i];
		if (e->freq == crystalfreq)
			return e;
	}

	return NULL;
}

__attribute__((used)) static void ssb_pmu0_pllinit_r0(struct ssb_chipcommon *cc,
				u32 crystalfreq)
{
	struct ssb_bus *bus = cc->dev->bus;
	const struct pmu0_plltab_entry *e = NULL;
	u32 pmuctl, tmp, pllctl;
	unsigned int i;

	if (crystalfreq)
		e = pmu0_plltab_find_entry(crystalfreq);
	if (!e)
		e = pmu0_plltab_find_entry(SSB_PMU0_DEFAULT_XTALFREQ);
	BUG_ON(!e);
	crystalfreq = e->freq;
	cc->pmu.crystalfreq = e->freq;

	/* Check if the PLL already is programmed to this frequency. */
	pmuctl = chipco_read32(cc, SSB_CHIPCO_PMU_CTL);
	if (((pmuctl & SSB_CHIPCO_PMU_CTL_XTALFREQ) >> SSB_CHIPCO_PMU_CTL_XTALFREQ_SHIFT) == e->xf) {
		/* We're already there... */
		return;
	}

	dev_info(cc->dev->dev, "Programming PLL to %u.%03u MHz\n",
		 crystalfreq / 1000, crystalfreq % 1000);

	/* First turn the PLL off. */
	switch (bus->chip_id) {
	case 0x4328:
		chipco_mask32(cc, SSB_CHIPCO_PMU_MINRES_MSK,
			      ~(1 << SSB_PMURES_4328_BB_PLL_PU));
		chipco_mask32(cc, SSB_CHIPCO_PMU_MAXRES_MSK,
			      ~(1 << SSB_PMURES_4328_BB_PLL_PU));
		break;
	case 0x5354:
		chipco_mask32(cc, SSB_CHIPCO_PMU_MINRES_MSK,
			      ~(1 << SSB_PMURES_5354_BB_PLL_PU));
		chipco_mask32(cc, SSB_CHIPCO_PMU_MAXRES_MSK,
			      ~(1 << SSB_PMURES_5354_BB_PLL_PU));
		break;
	default:
		WARN_ON(1);
	}
	for (i = 1500; i; i--) {
		tmp = chipco_read32(cc, SSB_CHIPCO_CLKCTLST);
		if (!(tmp & SSB_CHIPCO_CLKCTLST_HAVEHT))
			break;
		udelay(10);
	}
	tmp = chipco_read32(cc, SSB_CHIPCO_CLKCTLST);
	if (tmp & SSB_CHIPCO_CLKCTLST_HAVEHT)
		dev_emerg(cc->dev->dev, "Failed to turn the PLL off!\n");

	/* Set PDIV in PLL control 0. */
	pllctl = ssb_chipco_pll_read(cc, SSB_PMU0_PLLCTL0);
	if (crystalfreq >= SSB_PMU0_PLLCTL0_PDIV_FREQ)
		pllctl |= SSB_PMU0_PLLCTL0_PDIV_MSK;
	else
		pllctl &= ~SSB_PMU0_PLLCTL0_PDIV_MSK;
	ssb_chipco_pll_write(cc, SSB_PMU0_PLLCTL0, pllctl);

	/* Set WILD in PLL control 1. */
	pllctl = ssb_chipco_pll_read(cc, SSB_PMU0_PLLCTL1);
	pllctl &= ~SSB_PMU0_PLLCTL1_STOPMOD;
	pllctl &= ~(SSB_PMU0_PLLCTL1_WILD_IMSK | SSB_PMU0_PLLCTL1_WILD_FMSK);
	pllctl |= ((u32)e->wb_int << SSB_PMU0_PLLCTL1_WILD_IMSK_SHIFT) & SSB_PMU0_PLLCTL1_WILD_IMSK;
	pllctl |= ((u32)e->wb_frac << SSB_PMU0_PLLCTL1_WILD_FMSK_SHIFT) & SSB_PMU0_PLLCTL1_WILD_FMSK;
	if (e->wb_frac == 0)
		pllctl |= SSB_PMU0_PLLCTL1_STOPMOD;
	ssb_chipco_pll_write(cc, SSB_PMU0_PLLCTL1, pllctl);

	/* Set WILD in PLL control 2. */
	pllctl = ssb_chipco_pll_read(cc, SSB_PMU0_PLLCTL2);
	pllctl &= ~SSB_PMU0_PLLCTL2_WILD_IMSKHI;
	pllctl |= (((u32)e->wb_int >> 4) << SSB_PMU0_PLLCTL2_WILD_IMSKHI_SHIFT) & SSB_PMU0_PLLCTL2_WILD_IMSKHI;
	ssb_chipco_pll_write(cc, SSB_PMU0_PLLCTL2, pllctl);

	/* Set the crystalfrequency and the divisor. */
	pmuctl = chipco_read32(cc, SSB_CHIPCO_PMU_CTL);
	pmuctl &= ~SSB_CHIPCO_PMU_CTL_ILP_DIV;
	pmuctl |= (((crystalfreq + 127) / 128 - 1) << SSB_CHIPCO_PMU_CTL_ILP_DIV_SHIFT)
			& SSB_CHIPCO_PMU_CTL_ILP_DIV;
	pmuctl &= ~SSB_CHIPCO_PMU_CTL_XTALFREQ;
	pmuctl |= ((u32)e->xf << SSB_CHIPCO_PMU_CTL_XTALFREQ_SHIFT) & SSB_CHIPCO_PMU_CTL_XTALFREQ;
	chipco_write32(cc, SSB_CHIPCO_PMU_CTL, pmuctl);
}

__attribute__((used)) static const struct pmu1_plltab_entry * pmu1_plltab_find_entry(u32 crystalfreq)
{
	const struct pmu1_plltab_entry *e;
	unsigned int i;

	for (i = 0; i < ARRAY_SIZE(pmu1_plltab); i++) {
		e = &pmu1_plltab[i];
		if (e->freq == crystalfreq)
			return e;
	}

	return NULL;
}

__attribute__((used)) static void ssb_pmu1_pllinit_r0(struct ssb_chipcommon *cc,
				u32 crystalfreq)
{
	struct ssb_bus *bus = cc->dev->bus;
	const struct pmu1_plltab_entry *e = NULL;
	u32 buffer_strength = 0;
	u32 tmp, pllctl, pmuctl;
	unsigned int i;

	if (bus->chip_id == 0x4312) {
		/* We do not touch the BCM4312 PLL and assume
		 * the default crystal settings work out-of-the-box. */
		cc->pmu.crystalfreq = 20000;
		return;
	}

	if (crystalfreq)
		e = pmu1_plltab_find_entry(crystalfreq);
	if (!e)
		e = pmu1_plltab_find_entry(SSB_PMU1_DEFAULT_XTALFREQ);
	BUG_ON(!e);
	crystalfreq = e->freq;
	cc->pmu.crystalfreq = e->freq;

	/* Check if the PLL already is programmed to this frequency. */
	pmuctl = chipco_read32(cc, SSB_CHIPCO_PMU_CTL);
	if (((pmuctl & SSB_CHIPCO_PMU_CTL_XTALFREQ) >> SSB_CHIPCO_PMU_CTL_XTALFREQ_SHIFT) == e->xf) {
		/* We're already there... */
		return;
	}

	dev_info(cc->dev->dev, "Programming PLL to %u.%03u MHz\n",
		 crystalfreq / 1000, crystalfreq % 1000);

	/* First turn the PLL off. */
	switch (bus->chip_id) {
	case 0x4325:
		chipco_mask32(cc, SSB_CHIPCO_PMU_MINRES_MSK,
			      ~((1 << SSB_PMURES_4325_BBPLL_PWRSW_PU) |
				(1 << SSB_PMURES_4325_HT_AVAIL)));
		chipco_mask32(cc, SSB_CHIPCO_PMU_MAXRES_MSK,
			      ~((1 << SSB_PMURES_4325_BBPLL_PWRSW_PU) |
				(1 << SSB_PMURES_4325_HT_AVAIL)));
		/* Adjust the BBPLL to 2 on all channels later. */
		buffer_strength = 0x222222;
		break;
	default:
		WARN_ON(1);
	}
	for (i = 1500; i; i--) {
		tmp = chipco_read32(cc, SSB_CHIPCO_CLKCTLST);
		if (!(tmp & SSB_CHIPCO_CLKCTLST_HAVEHT))
			break;
		udelay(10);
	}
	tmp = chipco_read32(cc, SSB_CHIPCO_CLKCTLST);
	if (tmp & SSB_CHIPCO_CLKCTLST_HAVEHT)
		dev_emerg(cc->dev->dev, "Failed to turn the PLL off!\n");

	/* Set p1div and p2div. */
	pllctl = ssb_chipco_pll_read(cc, SSB_PMU1_PLLCTL0);
	pllctl &= ~(SSB_PMU1_PLLCTL0_P1DIV | SSB_PMU1_PLLCTL0_P2DIV);
	pllctl |= ((u32)e->p1div << SSB_PMU1_PLLCTL0_P1DIV_SHIFT) & SSB_PMU1_PLLCTL0_P1DIV;
	pllctl |= ((u32)e->p2div << SSB_PMU1_PLLCTL0_P2DIV_SHIFT) & SSB_PMU1_PLLCTL0_P2DIV;
	ssb_chipco_pll_write(cc, SSB_PMU1_PLLCTL0, pllctl);

	/* Set ndiv int and ndiv mode */
	pllctl = ssb_chipco_pll_read(cc, SSB_PMU1_PLLCTL2);
	pllctl &= ~(SSB_PMU1_PLLCTL2_NDIVINT | SSB_PMU1_PLLCTL2_NDIVMODE);
	pllctl |= ((u32)e->ndiv_int << SSB_PMU1_PLLCTL2_NDIVINT_SHIFT) & SSB_PMU1_PLLCTL2_NDIVINT;
	pllctl |= (1 << SSB_PMU1_PLLCTL2_NDIVMODE_SHIFT) & SSB_PMU1_PLLCTL2_NDIVMODE;
	ssb_chipco_pll_write(cc, SSB_PMU1_PLLCTL2, pllctl);

	/* Set ndiv frac */
	pllctl = ssb_chipco_pll_read(cc, SSB_PMU1_PLLCTL3);
	pllctl &= ~SSB_PMU1_PLLCTL3_NDIVFRAC;
	pllctl |= ((u32)e->ndiv_frac << SSB_PMU1_PLLCTL3_NDIVFRAC_SHIFT) & SSB_PMU1_PLLCTL3_NDIVFRAC;
	ssb_chipco_pll_write(cc, SSB_PMU1_PLLCTL3, pllctl);

	/* Change the drive strength, if required. */
	if (buffer_strength) {
		pllctl = ssb_chipco_pll_read(cc, SSB_PMU1_PLLCTL5);
		pllctl &= ~SSB_PMU1_PLLCTL5_CLKDRV;
		pllctl |= (buffer_strength << SSB_PMU1_PLLCTL5_CLKDRV_SHIFT) & SSB_PMU1_PLLCTL5_CLKDRV;
		ssb_chipco_pll_write(cc, SSB_PMU1_PLLCTL5, pllctl);
	}

	/* Tune the crystalfreq and the divisor. */
	pmuctl = chipco_read32(cc, SSB_CHIPCO_PMU_CTL);
	pmuctl &= ~(SSB_CHIPCO_PMU_CTL_ILP_DIV | SSB_CHIPCO_PMU_CTL_XTALFREQ);
	pmuctl |= ((((u32)e->freq + 127) / 128 - 1) << SSB_CHIPCO_PMU_CTL_ILP_DIV_SHIFT)
			& SSB_CHIPCO_PMU_CTL_ILP_DIV;
	pmuctl |= ((u32)e->xf << SSB_CHIPCO_PMU_CTL_XTALFREQ_SHIFT) & SSB_CHIPCO_PMU_CTL_XTALFREQ;
	chipco_write32(cc, SSB_CHIPCO_PMU_CTL, pmuctl);
}

__attribute__((used)) static void ssb_pmu_pll_init(struct ssb_chipcommon *cc)
{
	struct ssb_bus *bus = cc->dev->bus;
	u32 crystalfreq = 0; /* in kHz. 0 = keep default freq. */

	if (bus->bustype == SSB_BUSTYPE_SSB) {
#ifdef CONFIG_BCM47XX
		char buf[20];
		if (bcm47xx_nvram_getenv("xtalfreq", buf, sizeof(buf)) >= 0)
			crystalfreq = simple_strtoul(buf, NULL, 0);
#endif
	}

	switch (bus->chip_id) {
	case 0x4312:
	case 0x4325:
		ssb_pmu1_pllinit_r0(cc, crystalfreq);
		break;
	case 0x4328:
		ssb_pmu0_pllinit_r0(cc, crystalfreq);
		break;
	case 0x5354:
		if (crystalfreq == 0)
			crystalfreq = 25000;
		ssb_pmu0_pllinit_r0(cc, crystalfreq);
		break;
	case 0x4322:
		if (cc->pmu.rev == 2) {
			chipco_write32(cc, SSB_CHIPCO_PLLCTL_ADDR, 0x0000000A);
			chipco_write32(cc, SSB_CHIPCO_PLLCTL_DATA, 0x380005C0);
		}
		break;
	case 43222:
		break;
	default:
		dev_err(cc->dev->dev, "ERROR: PLL init unknown for device %04X\n",
			bus->chip_id);
	}
}

__attribute__((used)) static void ssb_pmu_resources_init(struct ssb_chipcommon *cc)
{
	struct ssb_bus *bus = cc->dev->bus;
	u32 min_msk = 0, max_msk = 0;
	unsigned int i;
	const struct pmu_res_updown_tab_entry *updown_tab = NULL;
	unsigned int updown_tab_size = 0;
	const struct pmu_res_depend_tab_entry *depend_tab = NULL;
	unsigned int depend_tab_size = 0;

	switch (bus->chip_id) {
	case 0x4312:
		 min_msk = 0xCBB;
		 break;
	case 0x4322:
	case 43222:
		/* We keep the default settings:
		 * min_msk = 0xCBB
		 * max_msk = 0x7FFFF
		 */
		break;
	case 0x4325:
		/* Power OTP down later. */
		min_msk = (1 << SSB_PMURES_4325_CBUCK_BURST) |
			  (1 << SSB_PMURES_4325_LNLDO2_PU);
		if (chipco_read32(cc, SSB_CHIPCO_CHIPSTAT) &
		    SSB_CHIPCO_CHST_4325_PMUTOP_2B)
			min_msk |= (1 << SSB_PMURES_4325_CLDO_CBUCK_BURST);
		/* The PLL may turn on, if it decides so. */
		max_msk = 0xFFFFF;
		updown_tab = pmu_res_updown_tab_4325a0;
		updown_tab_size = ARRAY_SIZE(pmu_res_updown_tab_4325a0);
		depend_tab = pmu_res_depend_tab_4325a0;
		depend_tab_size = ARRAY_SIZE(pmu_res_depend_tab_4325a0);
		break;
	case 0x4328:
		min_msk = (1 << SSB_PMURES_4328_EXT_SWITCHER_PWM) |
			  (1 << SSB_PMURES_4328_BB_SWITCHER_PWM) |
			  (1 << SSB_PMURES_4328_XTAL_EN);
		/* The PLL may turn on, if it decides so. */
		max_msk = 0xFFFFF;
		updown_tab = pmu_res_updown_tab_4328a0;
		updown_tab_size = ARRAY_SIZE(pmu_res_updown_tab_4328a0);
		depend_tab = pmu_res_depend_tab_4328a0;
		depend_tab_size = ARRAY_SIZE(pmu_res_depend_tab_4328a0);
		break;
	case 0x5354:
		/* The PLL may turn on, if it decides so. */
		max_msk = 0xFFFFF;
		break;
	default:
		dev_err(cc->dev->dev, "ERROR: PMU resource config unknown for device %04X\n",
			bus->chip_id);
	}

	if (updown_tab) {
		for (i = 0; i < updown_tab_size; i++) {
			chipco_write32(cc, SSB_CHIPCO_PMU_RES_TABSEL,
				       updown_tab[i].resource);
			chipco_write32(cc, SSB_CHIPCO_PMU_RES_UPDNTM,
				       updown_tab[i].updown);
		}
	}
	if (depend_tab) {
		for (i = 0; i < depend_tab_size; i++) {
			chipco_write32(cc, SSB_CHIPCO_PMU_RES_TABSEL,
				       depend_tab[i].resource);
			switch (depend_tab[i].task) {
			case PMU_RES_DEP_SET:
				chipco_write32(cc, SSB_CHIPCO_PMU_RES_DEPMSK,
					       depend_tab[i].depend);
				break;
			case PMU_RES_DEP_ADD:
				chipco_set32(cc, SSB_CHIPCO_PMU_RES_DEPMSK,
					     depend_tab[i].depend);
				break;
			case PMU_RES_DEP_REMOVE:
				chipco_mask32(cc, SSB_CHIPCO_PMU_RES_DEPMSK,
					      ~(depend_tab[i].depend));
				break;
			default:
				WARN_ON(1);
			}
		}
	}

	/* Set the resource masks. */
	if (min_msk)
		chipco_write32(cc, SSB_CHIPCO_PMU_MINRES_MSK, min_msk);
	if (max_msk)
		chipco_write32(cc, SSB_CHIPCO_PMU_MAXRES_MSK, max_msk);
}

void ssb_pmu_init(struct ssb_chipcommon *cc)
{
	u32 pmucap;

	if (!(cc->capabilities & SSB_CHIPCO_CAP_PMU))
		return;

	pmucap = chipco_read32(cc, SSB_CHIPCO_PMU_CAP);
	cc->pmu.rev = (pmucap & SSB_CHIPCO_PMU_CAP_REVISION);

	dev_dbg(cc->dev->dev, "Found rev %u PMU (capabilities 0x%08X)\n",
		cc->pmu.rev, pmucap);

	if (cc->pmu.rev == 1)
		chipco_mask32(cc, SSB_CHIPCO_PMU_CTL,
			      ~SSB_CHIPCO_PMU_CTL_NOILPONW);
	else
		chipco_set32(cc, SSB_CHIPCO_PMU_CTL,
			     SSB_CHIPCO_PMU_CTL_NOILPONW);
	ssb_pmu_pll_init(cc);
	ssb_pmu_resources_init(cc);
}

void ssb_pmu_set_ldo_voltage(struct ssb_chipcommon *cc,
			     enum ssb_pmu_ldo_volt_id id, u32 voltage)
{
	struct ssb_bus *bus = cc->dev->bus;
	u32 addr, shift, mask;

	switch (bus->chip_id) {
	case 0x4328:
	case 0x5354:
		switch (id) {
		case LDO_VOLT1:
			addr = 2;
			shift = 25;
			mask = 0xF;
			break;
		case LDO_VOLT2:
			addr = 3;
			shift = 1;
			mask = 0xF;
			break;
		case LDO_VOLT3:
			addr = 3;
			shift = 9;
			mask = 0xF;
			break;
		case LDO_PAREF:
			addr = 3;
			shift = 17;
			mask = 0x3F;
			break;
		default:
			WARN_ON(1);
			return;
		}
		break;
	case 0x4312:
		if (WARN_ON(id != LDO_PAREF))
			return;
		addr = 0;
		shift = 21;
		mask = 0x3F;
		break;
	default:
		return;
	}

	ssb_chipco_regctl_maskset(cc, addr, ~(mask << shift),
				  (voltage & mask) << shift);
}

void ssb_pmu_set_ldo_paref(struct ssb_chipcommon *cc, bool on)
{
	struct ssb_bus *bus = cc->dev->bus;
	int ldo;

	switch (bus->chip_id) {
	case 0x4312:
		ldo = SSB_PMURES_4312_PA_REF_LDO;
		break;
	case 0x4328:
		ldo = SSB_PMURES_4328_PA_REF_LDO;
		break;
	case 0x5354:
		ldo = SSB_PMURES_5354_PA_REF_LDO;
		break;
	default:
		return;
	}

	if (on)
		chipco_set32(cc, SSB_CHIPCO_PMU_MINRES_MSK, 1 << ldo);
	else
		chipco_mask32(cc, SSB_CHIPCO_PMU_MINRES_MSK, ~(1 << ldo));
	chipco_read32(cc, SSB_CHIPCO_PMU_MINRES_MSK); //SPEC FIXME found via mmiotrace - dummy read?
}

__attribute__((used)) static u32 ssb_pmu_get_alp_clock_clk0(struct ssb_chipcommon *cc)
{
	u32 crystalfreq;
	const struct pmu0_plltab_entry *e = NULL;

	crystalfreq = (chipco_read32(cc, SSB_CHIPCO_PMU_CTL) &
		       SSB_CHIPCO_PMU_CTL_XTALFREQ)  >> SSB_CHIPCO_PMU_CTL_XTALFREQ_SHIFT;
	e = pmu0_plltab_find_entry(crystalfreq);
	BUG_ON(!e);
	return e->freq * 1000;
}

u32 ssb_pmu_get_alp_clock(struct ssb_chipcommon *cc)
{
	struct ssb_bus *bus = cc->dev->bus;

	switch (bus->chip_id) {
	case 0x5354:
		return ssb_pmu_get_alp_clock_clk0(cc);
	default:
		dev_err(cc->dev->dev, "ERROR: PMU alp clock unknown for device %04X\n",
			bus->chip_id);
		return 0;
	}
}

u32 ssb_pmu_get_cpu_clock(struct ssb_chipcommon *cc)
{
	struct ssb_bus *bus = cc->dev->bus;

	switch (bus->chip_id) {
	case 0x5354:
		/* 5354 chip uses a non programmable PLL of frequency 240MHz */
		return 240000000;
	default:
		dev_err(cc->dev->dev, "ERROR: PMU cpu clock unknown for device %04X\n",
			bus->chip_id);
		return 0;
	}
}

u32 ssb_pmu_get_controlclock(struct ssb_chipcommon *cc)
{
	struct ssb_bus *bus = cc->dev->bus;

	switch (bus->chip_id) {
	case 0x5354:
		return 120000000;
	default:
		dev_err(cc->dev->dev, "ERROR: PMU controlclock unknown for device %04X\n",
			bus->chip_id);
		return 0;
	}
}

void ssb_pmu_spuravoid_pllupdate(struct ssb_chipcommon *cc, int spuravoid)
{
	u32 pmu_ctl = 0;

	switch (cc->dev->bus->chip_id) {
	case 0x4322:
		ssb_chipco_pll_write(cc, SSB_PMU1_PLLCTL0, 0x11100070);
		ssb_chipco_pll_write(cc, SSB_PMU1_PLLCTL1, 0x1014140a);
		ssb_chipco_pll_write(cc, SSB_PMU1_PLLCTL5, 0x88888854);
		if (spuravoid == 1)
			ssb_chipco_pll_write(cc, SSB_PMU1_PLLCTL2, 0x05201828);
		else
			ssb_chipco_pll_write(cc, SSB_PMU1_PLLCTL2, 0x05001828);
		pmu_ctl = SSB_CHIPCO_PMU_CTL_PLL_UPD;
		break;
	case 43222:
		if (spuravoid == 1) {
			ssb_chipco_pll_write(cc, SSB_PMU1_PLLCTL0, 0x11500008);
			ssb_chipco_pll_write(cc, SSB_PMU1_PLLCTL1, 0x0C000C06);
			ssb_chipco_pll_write(cc, SSB_PMU1_PLLCTL2, 0x0F600a08);
			ssb_chipco_pll_write(cc, SSB_PMU1_PLLCTL3, 0x00000000);
			ssb_chipco_pll_write(cc, SSB_PMU1_PLLCTL4, 0x2001E920);
			ssb_chipco_pll_write(cc, SSB_PMU1_PLLCTL5, 0x88888815);
		} else {
			ssb_chipco_pll_write(cc, SSB_PMU1_PLLCTL0, 0x11100008);
			ssb_chipco_pll_write(cc, SSB_PMU1_PLLCTL1, 0x0c000c06);
			ssb_chipco_pll_write(cc, SSB_PMU1_PLLCTL2, 0x03000a08);
			ssb_chipco_pll_write(cc, SSB_PMU1_PLLCTL3, 0x00000000);
			ssb_chipco_pll_write(cc, SSB_PMU1_PLLCTL4, 0x200005c0);
			ssb_chipco_pll_write(cc, SSB_PMU1_PLLCTL5, 0x88888855);
		}
		pmu_ctl = SSB_CHIPCO_PMU_CTL_PLL_UPD;
		break;
	default:
		dev_err(cc->dev->dev,
			"Unknown spuravoidance settings for chip 0x%04X, not changing PLL\n",
			cc->dev->bus->chip_id);
		return;
	}

	chipco_set32(cc, SSB_CHIPCO_PMU_CTL, pmu_ctl);
}

