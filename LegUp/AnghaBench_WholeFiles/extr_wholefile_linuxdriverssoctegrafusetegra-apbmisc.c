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
typedef  int u8 ;
typedef  int u32 ;

/* Variables and functions */
 int PMC_STRAPPING_OPT_A_RAM_CODE_MASK_LONG ; 
 int PMC_STRAPPING_OPT_A_RAM_CODE_MASK_SHORT ; 
 int PMC_STRAPPING_OPT_A_RAM_CODE_SHIFT ; 
 int /*<<< orphan*/  WARN (int,char*) ; 
 scalar_t__ apbmisc_base ; 
 scalar_t__ long_ram_code ; 
 int readl_relaxed (scalar_t__) ; 
 scalar_t__ strapping_base ; 

u32 tegra_read_chipid(void)
{
	if (!apbmisc_base) {
		WARN(1, "Tegra Chip ID not yet available\n");
		return 0;
	}

	return readl_relaxed(apbmisc_base + 4);
}

u8 tegra_get_chip_id(void)
{
	return (tegra_read_chipid() >> 8) & 0xff;
}

u32 tegra_read_straps(void)
{
	if (strapping_base)
		return readl_relaxed(strapping_base);
	else
		return 0;
}

u32 tegra_read_ram_code(void)
{
	u32 straps = tegra_read_straps();

	if (long_ram_code)
		straps &= PMC_STRAPPING_OPT_A_RAM_CODE_MASK_LONG;
	else
		straps &= PMC_STRAPPING_OPT_A_RAM_CODE_MASK_SHORT;

	return straps >> PMC_STRAPPING_OPT_A_RAM_CODE_SHIFT;
}

