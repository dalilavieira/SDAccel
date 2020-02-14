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
typedef  int /*<<< orphan*/  u8 ;
typedef  int u32 ;
typedef  int u16 ;

/* Variables and functions */
#define  BCM3368_CPU_ID 135 
#define  BCM6328_CPU_ID 134 
#define  BCM6338_CPU_ID 133 
#define  BCM6345_CPU_ID 132 
#define  BCM6348_CPU_ID 131 
#define  BCM6358_CPU_ID 130 
#define  BCM6362_CPU_ID 129 
#define  BCM6368_CPU_ID 128 
 scalar_t__ BCMCPU_IS_3368 () ; 
 scalar_t__ BCMCPU_IS_6328 () ; 
 scalar_t__ BCMCPU_IS_6338 () ; 
 scalar_t__ BCMCPU_IS_6345 () ; 
 scalar_t__ BCMCPU_IS_6348 () ; 
 scalar_t__ BCMCPU_IS_6358 () ; 
 scalar_t__ BCMCPU_IS_6362 () ; 
 scalar_t__ BCMCPU_IS_6368 () ; 
 int /*<<< orphan*/  DDR_CSEND_REG ; 
 int /*<<< orphan*/  DDR_DMIPSPLLCFG_6368_REG ; 
 int /*<<< orphan*/  DDR_DMIPSPLLCFG_REG ; 
 int /*<<< orphan*/  DDR_DMIPSPLLDIV_6368_REG ; 
 unsigned int DMIPSPLLCFG_6368_NDIV_MASK ; 
 unsigned int DMIPSPLLCFG_6368_NDIV_SHIFT ; 
 unsigned int DMIPSPLLCFG_6368_P1_MASK ; 
 unsigned int DMIPSPLLCFG_6368_P1_SHIFT ; 
 unsigned int DMIPSPLLCFG_6368_P2_MASK ; 
 unsigned int DMIPSPLLCFG_6368_P2_SHIFT ; 
 unsigned int DMIPSPLLCFG_M1_MASK ; 
 unsigned int DMIPSPLLCFG_M1_SHIFT ; 
 unsigned int DMIPSPLLCFG_N1_MASK ; 
 unsigned int DMIPSPLLCFG_N1_SHIFT ; 
 unsigned int DMIPSPLLCFG_N2_MASK ; 
 unsigned int DMIPSPLLCFG_N2_SHIFT ; 
 unsigned int DMIPSPLLDIV_6368_MDIV_MASK ; 
 unsigned int DMIPSPLLDIV_6368_MDIV_SHIFT ; 
 int MEMC_CFG_32B_MASK ; 
 int MEMC_CFG_COL_MASK ; 
 int MEMC_CFG_COL_SHIFT ; 
 int /*<<< orphan*/  MEMC_CFG_REG ; 
 int MEMC_CFG_ROW_MASK ; 
 int MEMC_CFG_ROW_SHIFT ; 
 unsigned int MIPSPLLCTL_M1CPU_MASK ; 
 unsigned int MIPSPLLCTL_M1CPU_SHIFT ; 
 unsigned int MIPSPLLCTL_N1_MASK ; 
 unsigned int MIPSPLLCTL_N1_SHIFT ; 
 unsigned int MIPSPLLCTL_N2_MASK ; 
 unsigned int MIPSPLLCTL_N2_SHIFT ; 
 int /*<<< orphan*/  MISC_STRAPBUS_6328_REG ; 
 int /*<<< orphan*/  MISC_STRAPBUS_6362_REG ; 
 int /*<<< orphan*/  PERF_MIPSPLLCTL_REG ; 
 int SDRAM_CFG_32B_MASK ; 
 int SDRAM_CFG_BANK_MASK ; 
 int SDRAM_CFG_COL_MASK ; 
 int SDRAM_CFG_COL_SHIFT ; 
 int /*<<< orphan*/  SDRAM_CFG_REG ; 
 int SDRAM_CFG_ROW_MASK ; 
 int SDRAM_CFG_ROW_SHIFT ; 
 int /*<<< orphan*/  SDRAM_MBASE_REG ; 
 unsigned int STRAPBUS_6328_FCVO_MASK ; 
 unsigned int STRAPBUS_6328_FCVO_SHIFT ; 
 unsigned int STRAPBUS_6362_FCVO_MASK ; 
 unsigned int STRAPBUS_6362_FCVO_SHIFT ; 
 unsigned int bcm63xx_cpu_freq ; 
 int /*<<< orphan*/  bcm63xx_cpu_rev ; 
 int bcm63xx_get_cpu_id () ; 
 unsigned int bcm63xx_memory_size ; 
 int bcm_ddr_readl (int /*<<< orphan*/ ) ; 
 int bcm_memc_readl (int /*<<< orphan*/ ) ; 
 unsigned int bcm_misc_readl (int /*<<< orphan*/ ) ; 
 unsigned int bcm_perf_readl (int /*<<< orphan*/ ) ; 
 int bcm_sdram_readl (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  panic (char*,int) ; 

u8 bcm63xx_get_cpu_rev(void)
{
	return bcm63xx_cpu_rev;
}

unsigned int bcm63xx_get_cpu_freq(void)
{
	return bcm63xx_cpu_freq;
}

unsigned int bcm63xx_get_memory_size(void)
{
	return bcm63xx_memory_size;
}

__attribute__((used)) static unsigned int detect_cpu_clock(void)
{
	u16 cpu_id = bcm63xx_get_cpu_id();

	switch (cpu_id) {
	case BCM3368_CPU_ID:
		return 300000000;

	case BCM6328_CPU_ID:
	{
		unsigned int tmp, mips_pll_fcvo;

		tmp = bcm_misc_readl(MISC_STRAPBUS_6328_REG);
		mips_pll_fcvo = (tmp & STRAPBUS_6328_FCVO_MASK)
				>> STRAPBUS_6328_FCVO_SHIFT;

		switch (mips_pll_fcvo) {
		case 0x12:
		case 0x14:
		case 0x19:
			return 160000000;
		case 0x1c:
			return 192000000;
		case 0x13:
		case 0x15:
			return 200000000;
		case 0x1a:
			return 384000000;
		case 0x16:
			return 400000000;
		default:
			return 320000000;
		}

	}
	case BCM6338_CPU_ID:
		/* BCM6338 has a fixed 240 Mhz frequency */
		return 240000000;

	case BCM6345_CPU_ID:
		/* BCM6345 has a fixed 140Mhz frequency */
		return 140000000;

	case BCM6348_CPU_ID:
	{
		unsigned int tmp, n1, n2, m1;

		/* 16MHz * (N1 + 1) * (N2 + 2) / (M1_CPU + 1) */
		tmp = bcm_perf_readl(PERF_MIPSPLLCTL_REG);
		n1 = (tmp & MIPSPLLCTL_N1_MASK) >> MIPSPLLCTL_N1_SHIFT;
		n2 = (tmp & MIPSPLLCTL_N2_MASK) >> MIPSPLLCTL_N2_SHIFT;
		m1 = (tmp & MIPSPLLCTL_M1CPU_MASK) >> MIPSPLLCTL_M1CPU_SHIFT;
		n1 += 1;
		n2 += 2;
		m1 += 1;
		return (16 * 1000000 * n1 * n2) / m1;
	}

	case BCM6358_CPU_ID:
	{
		unsigned int tmp, n1, n2, m1;

		/* 16MHz * N1 * N2 / M1_CPU */
		tmp = bcm_ddr_readl(DDR_DMIPSPLLCFG_REG);
		n1 = (tmp & DMIPSPLLCFG_N1_MASK) >> DMIPSPLLCFG_N1_SHIFT;
		n2 = (tmp & DMIPSPLLCFG_N2_MASK) >> DMIPSPLLCFG_N2_SHIFT;
		m1 = (tmp & DMIPSPLLCFG_M1_MASK) >> DMIPSPLLCFG_M1_SHIFT;
		return (16 * 1000000 * n1 * n2) / m1;
	}

	case BCM6362_CPU_ID:
	{
		unsigned int tmp, mips_pll_fcvo;

		tmp = bcm_misc_readl(MISC_STRAPBUS_6362_REG);
		mips_pll_fcvo = (tmp & STRAPBUS_6362_FCVO_MASK)
				>> STRAPBUS_6362_FCVO_SHIFT;
		switch (mips_pll_fcvo) {
		case 0x03:
		case 0x0b:
		case 0x13:
		case 0x1b:
			return 240000000;
		case 0x04:
		case 0x0c:
		case 0x14:
		case 0x1c:
			return 160000000;
		case 0x05:
		case 0x0e:
		case 0x16:
		case 0x1e:
		case 0x1f:
			return 400000000;
		case 0x06:
			return 440000000;
		case 0x07:
		case 0x17:
			return 384000000;
		case 0x15:
		case 0x1d:
			return 200000000;
		default:
			return 320000000;
		}
	}
	case BCM6368_CPU_ID:
	{
		unsigned int tmp, p1, p2, ndiv, m1;

		/* (64MHz / P1) * P2 * NDIV / M1_CPU */
		tmp = bcm_ddr_readl(DDR_DMIPSPLLCFG_6368_REG);

		p1 = (tmp & DMIPSPLLCFG_6368_P1_MASK) >>
			DMIPSPLLCFG_6368_P1_SHIFT;

		p2 = (tmp & DMIPSPLLCFG_6368_P2_MASK) >>
			DMIPSPLLCFG_6368_P2_SHIFT;

		ndiv = (tmp & DMIPSPLLCFG_6368_NDIV_MASK) >>
			DMIPSPLLCFG_6368_NDIV_SHIFT;

		tmp = bcm_ddr_readl(DDR_DMIPSPLLDIV_6368_REG);
		m1 = (tmp & DMIPSPLLDIV_6368_MDIV_MASK) >>
			DMIPSPLLDIV_6368_MDIV_SHIFT;

		return (((64 * 1000000) / p1) * p2 * ndiv) / m1;
	}

	default:
		panic("Failed to detect clock for CPU with id=%04X\n", cpu_id);
	}
}

__attribute__((used)) static unsigned int detect_memory_size(void)
{
	unsigned int cols = 0, rows = 0, is_32bits = 0, banks = 0;
	u32 val;

	if (BCMCPU_IS_6328() || BCMCPU_IS_6362())
		return bcm_ddr_readl(DDR_CSEND_REG) << 24;

	if (BCMCPU_IS_6345()) {
		val = bcm_sdram_readl(SDRAM_MBASE_REG);
		return val * 8 * 1024 * 1024;
	}

	if (BCMCPU_IS_6338() || BCMCPU_IS_6348()) {
		val = bcm_sdram_readl(SDRAM_CFG_REG);
		rows = (val & SDRAM_CFG_ROW_MASK) >> SDRAM_CFG_ROW_SHIFT;
		cols = (val & SDRAM_CFG_COL_MASK) >> SDRAM_CFG_COL_SHIFT;
		is_32bits = (val & SDRAM_CFG_32B_MASK) ? 1 : 0;
		banks = (val & SDRAM_CFG_BANK_MASK) ? 2 : 1;
	}

	if (BCMCPU_IS_3368() || BCMCPU_IS_6358() || BCMCPU_IS_6368()) {
		val = bcm_memc_readl(MEMC_CFG_REG);
		rows = (val & MEMC_CFG_ROW_MASK) >> MEMC_CFG_ROW_SHIFT;
		cols = (val & MEMC_CFG_COL_MASK) >> MEMC_CFG_COL_SHIFT;
		is_32bits = (val & MEMC_CFG_32B_MASK) ? 0 : 1;
		banks = 2;
	}

	/* 0 => 11 address bits ... 2 => 13 address bits */
	rows += 11;

	/* 0 => 8 address bits ... 2 => 10 address bits */
	cols += 8;

	return 1 << (cols + rows + (is_32bits + 1) + banks);
}

