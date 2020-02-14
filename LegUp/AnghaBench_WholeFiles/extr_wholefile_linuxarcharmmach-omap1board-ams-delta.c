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
typedef  int u16 ;
struct omap1_cam_platform_data {int dummy; } ;
struct i2c_board_info {int dummy; } ;
struct gpio_chip {int /*<<< orphan*/  label; } ;

/* Variables and functions */
 int /*<<< orphan*/  gpio_set_value (int,int) ; 
 int /*<<< orphan*/  omap1_camera_init (struct omap1_cam_platform_data*) ; 
 int /*<<< orphan*/  strcmp (char*,int /*<<< orphan*/ ) ; 

__attribute__((used)) static inline void omap1_set_camera_info(struct omap1_cam_platform_data *info)
{
	omap1_camera_init(info);
}

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

void ams_delta_latch_write(int base, int ngpio, u16 mask, u16 value)
{
	int bit = 0;
	u16 bitpos = 1 << bit;

	for (; bit < ngpio; bit++, bitpos = bitpos << 1) {
		if (!(mask & bitpos))
			continue;
		else
			gpio_set_value(base + bit, (value & bitpos) != 0);
	}
}

__attribute__((used)) static int gpiochip_match_by_label(struct gpio_chip *chip, void *data)
{
	char *label = data;

	return !strcmp(label, chip->label);
}

