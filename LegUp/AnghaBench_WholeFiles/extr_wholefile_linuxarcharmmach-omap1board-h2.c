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
struct mtd_info {int dummy; } ;
struct i2c_board_info {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  H2_NAND_RB_GPIO_PIN ; 
 int gpio_get_value (int /*<<< orphan*/ ) ; 

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

__attribute__((used)) static int h2_nand_dev_ready(struct mtd_info *mtd)
{
	return gpio_get_value(H2_NAND_RB_GPIO_PIN);
}

