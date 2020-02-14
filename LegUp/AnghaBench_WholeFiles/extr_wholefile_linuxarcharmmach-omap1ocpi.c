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
typedef  int /*<<< orphan*/  u32 ;
struct i2c_board_info {int dummy; } ;

/* Variables and functions */
 int ENODEV ; 
 int /*<<< orphan*/  OCPI_PROT ; 
 int /*<<< orphan*/  OCPI_SEC ; 
 int /*<<< orphan*/  cpu_is_omap16xx () ; 
 unsigned int omap_readl (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  omap_writel (unsigned int,int /*<<< orphan*/ ) ; 

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

int ocpi_enable(void)
{
	unsigned int val;

	if (!cpu_is_omap16xx())
		return -ENODEV;

	/* Enable access for OHCI in OCPI */
	val = omap_readl(OCPI_PROT);
	val &= ~0xff;
	/* val &= (1 << 0);	 Allow access only to EMIFS */
	omap_writel(val, OCPI_PROT);

	val = omap_readl(OCPI_SEC);
	val &= ~0xff;
	omap_writel(val, OCPI_SEC);

	return 0;
}

