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
typedef  int u32 ;
typedef  int u16 ;
struct i2c_board_info {int dummy; } ;
typedef  enum reboot_mode { ____Placeholder_reboot_mode } reboot_mode ;

/* Variables and functions */
 int /*<<< orphan*/  ARM_RSTCT1 ; 
 int /*<<< orphan*/  ARM_SYSST ; 
 int ARM_SYSST_ARM_WDRST_SHIFT ; 
 int ARM_SYSST_EXT_RST_SHIFT ; 
 int ARM_SYSST_GLOB_SWRST_SHIFT ; 
 int ARM_SYSST_POR_SHIFT ; 
 int /*<<< orphan*/  DPLL_CTL ; 
 int /*<<< orphan*/  OMAP1_IO_ADDRESS (int /*<<< orphan*/ ) ; 
 int OMAP_EXTWARM_RST_SRC_ID_SHIFT ; 
 int OMAP_GLOBAL_COLD_RST_SRC_ID_SHIFT ; 
 int OMAP_GLOBAL_WARM_RST_SRC_ID_SHIFT ; 
 int OMAP_MPU_WD_RST_SRC_ID_SHIFT ; 
 int __raw_readw (int /*<<< orphan*/ ) ; 
 scalar_t__ cpu_is_omap5912 () ; 
 int omap_readw (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  omap_writew (int,int /*<<< orphan*/ ) ; 

__attribute__((used)) static inline int omap_register_i2c_bus(int bus_id, u32 clkrate,
				 struct i2c_board_info const *info,
				 unsigned len)
{
	return 0;
}

__attribute__((used)) static inline int omap_register_i2c_bus_cmdline(void)
{
	return 0;
}

__attribute__((used)) static inline void omap7xx_map_io(void)
{
}

__attribute__((used)) static inline void omap1510_fpga_init_irq(void)
{
}

__attribute__((used)) static inline void omap15xx_map_io(void)
{
}

__attribute__((used)) static inline void omap16xx_map_io(void)
{
}

__attribute__((used)) static inline int omap_serial_wakeup_init(void)
{
	return 0;
}

void omap1_restart(enum reboot_mode mode, const char *cmd)
{
	/*
	 * Workaround for 5912/1611b bug mentioned in sprz209d.pdf p. 28
	 * "Global Software Reset Affects Traffic Controller Frequency".
	 */
	if (cpu_is_omap5912()) {
		omap_writew(omap_readw(DPLL_CTL) & ~(1 << 4), DPLL_CTL);
		omap_writew(0x8, ARM_RSTCT1);
	}

	omap_writew(1, ARM_RSTCT1);
}

u32 omap1_get_reset_sources(void)
{
	u32 ret = 0;
	u16 rs;

	rs = __raw_readw(OMAP1_IO_ADDRESS(ARM_SYSST));

	if (rs & (1 << ARM_SYSST_POR_SHIFT))
		ret |= 1 << OMAP_GLOBAL_COLD_RST_SRC_ID_SHIFT;
	if (rs & (1 << ARM_SYSST_EXT_RST_SHIFT))
		ret |= 1 << OMAP_EXTWARM_RST_SRC_ID_SHIFT;
	if (rs & (1 << ARM_SYSST_ARM_WDRST_SHIFT))
		ret |= 1 << OMAP_MPU_WD_RST_SRC_ID_SHIFT;
	if (rs & (1 << ARM_SYSST_GLOB_SWRST_SHIFT))
		ret |= 1 << OMAP_GLOBAL_WARM_RST_SRC_ID_SHIFT;

	return ret;
}

