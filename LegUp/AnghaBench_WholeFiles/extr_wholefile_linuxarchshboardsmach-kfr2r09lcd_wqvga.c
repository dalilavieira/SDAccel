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
struct sh_mobile_lcdc_sys_bus_ops {unsigned long (* read_data ) (void*) ;int /*<<< orphan*/  (* write_index ) (void*,unsigned long) ;int /*<<< orphan*/  (* write_data ) (void*,unsigned long) ;} ;

/* Variables and functions */
 int ARRAY_SIZE (unsigned char*) ; 
 int ENODEV ; 
 int /*<<< orphan*/  GPIO_PTE4 ; 
 int /*<<< orphan*/  GPIO_PTF4 ; 
 unsigned char* data_frame_if ; 
 unsigned char* data_gamma ; 
 unsigned char* data_panel ; 
 unsigned char* data_power ; 
 unsigned char* data_timing ; 
 unsigned char* data_timing_src ; 
 int /*<<< orphan*/  gpio_set_value (int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  mdelay (int) ; 
 int /*<<< orphan*/  pr_info (char*) ; 
 unsigned long stub1 (void*) ; 
 int /*<<< orphan*/  stub2 (void*,unsigned long) ; 
 int /*<<< orphan*/  stub3 (void*,unsigned long) ; 
 int /*<<< orphan*/  udelay (int) ; 

__attribute__((used)) static unsigned long read_reg(void *sohandle,
			      struct sh_mobile_lcdc_sys_bus_ops *so)
{
	return so->read_data(sohandle);
}

__attribute__((used)) static void write_reg(void *sohandle,
		      struct sh_mobile_lcdc_sys_bus_ops *so,
		      int i, unsigned long v)
{
	if (i)
		so->write_data(sohandle, v); /* PTH4/LCDRS High [param, 17:0] */
	else
		so->write_index(sohandle, v); /* PTH4/LCDRS Low [cmd, 7:0] */
}

__attribute__((used)) static void write_data(void *sohandle,
		       struct sh_mobile_lcdc_sys_bus_ops *so,
		       unsigned char const *data, int no_data)
{
	int i;

	for (i = 0; i < no_data; i++)
		write_reg(sohandle, so, 1, data[i]);
}

__attribute__((used)) static unsigned long read_device_code(void *sohandle,
				      struct sh_mobile_lcdc_sys_bus_ops *so)
{
	unsigned long device_code;

	/* access protect OFF */
	write_reg(sohandle, so, 0, 0xb0);
	write_reg(sohandle, so, 1, 0x00);

	/* deep standby OFF */
	write_reg(sohandle, so, 0, 0xb1);
	write_reg(sohandle, so, 1, 0x00);

	/* device code command */
	write_reg(sohandle, so, 0, 0xbf);
	mdelay(50);

	/* dummy read */
	read_reg(sohandle, so);

	/* read device code */
	device_code = ((read_reg(sohandle, so) & 0xff) << 24);
	device_code |= ((read_reg(sohandle, so) & 0xff) << 16);
	device_code |= ((read_reg(sohandle, so) & 0xff) << 8);
	device_code |= (read_reg(sohandle, so) & 0xff);

	return device_code;
}

__attribute__((used)) static void write_memory_start(void *sohandle,
			       struct sh_mobile_lcdc_sys_bus_ops *so)
{
	write_reg(sohandle, so, 0, 0x2c);
}

__attribute__((used)) static void clear_memory(void *sohandle,
			 struct sh_mobile_lcdc_sys_bus_ops *so)
{
	int i;

	/* write start */
	write_memory_start(sohandle, so);

	/* paint it black */
	for (i = 0; i < (240 * 400); i++)
		write_reg(sohandle, so, 1, 0x00);
}

__attribute__((used)) static void display_on(void *sohandle,
		       struct sh_mobile_lcdc_sys_bus_ops *so)
{
	/* access protect off */
	write_reg(sohandle, so, 0, 0xb0);
	write_reg(sohandle, so, 1, 0x00);

	/* exit deep standby mode */
	write_reg(sohandle, so, 0, 0xb1);
	write_reg(sohandle, so, 1, 0x00);

	/* frame memory I/F */
	write_reg(sohandle, so, 0, 0xb3);
	write_data(sohandle, so, data_frame_if, ARRAY_SIZE(data_frame_if));

	/* display mode and frame memory write mode */
	write_reg(sohandle, so, 0, 0xb4);
	write_reg(sohandle, so, 1, 0x00); /* DBI, internal clock */

	/* panel */
	write_reg(sohandle, so, 0, 0xc0);
	write_data(sohandle, so, data_panel, ARRAY_SIZE(data_panel));

	/* timing (normal) */
	write_reg(sohandle, so, 0, 0xc1);
	write_data(sohandle, so, data_timing, ARRAY_SIZE(data_timing));

	/* timing (partial) */
	write_reg(sohandle, so, 0, 0xc2);
	write_data(sohandle, so, data_timing, ARRAY_SIZE(data_timing));

	/* timing (idle) */
	write_reg(sohandle, so, 0, 0xc3);
	write_data(sohandle, so, data_timing, ARRAY_SIZE(data_timing));

	/* timing (source/VCOM/gate driving) */
	write_reg(sohandle, so, 0, 0xc4);
	write_data(sohandle, so, data_timing_src, ARRAY_SIZE(data_timing_src));

	/* gamma (red) */
	write_reg(sohandle, so, 0, 0xc8);
	write_data(sohandle, so, data_gamma, ARRAY_SIZE(data_gamma));

	/* gamma (green) */
	write_reg(sohandle, so, 0, 0xc9);
	write_data(sohandle, so, data_gamma, ARRAY_SIZE(data_gamma));

	/* gamma (blue) */
	write_reg(sohandle, so, 0, 0xca);
	write_data(sohandle, so, data_gamma, ARRAY_SIZE(data_gamma));

	/* power (common) */
	write_reg(sohandle, so, 0, 0xd0);
	write_data(sohandle, so, data_power, ARRAY_SIZE(data_power));

	/* VCOM */
	write_reg(sohandle, so, 0, 0xd1);
	write_reg(sohandle, so, 1, 0x00);
	write_reg(sohandle, so, 1, 0x0f);
	write_reg(sohandle, so, 1, 0x02);

	/* power (normal) */
	write_reg(sohandle, so, 0, 0xd2);
	write_reg(sohandle, so, 1, 0x63);
	write_reg(sohandle, so, 1, 0x24);

	/* power (partial) */
	write_reg(sohandle, so, 0, 0xd3);
	write_reg(sohandle, so, 1, 0x63);
	write_reg(sohandle, so, 1, 0x24);

	/* power (idle) */
	write_reg(sohandle, so, 0, 0xd4);
	write_reg(sohandle, so, 1, 0x63);
	write_reg(sohandle, so, 1, 0x24);

	write_reg(sohandle, so, 0, 0xd8);
	write_reg(sohandle, so, 1, 0x77);
	write_reg(sohandle, so, 1, 0x77);

	/* TE signal */
	write_reg(sohandle, so, 0, 0x35);
	write_reg(sohandle, so, 1, 0x00);

	/* TE signal line */
	write_reg(sohandle, so, 0, 0x44);
	write_reg(sohandle, so, 1, 0x00);
	write_reg(sohandle, so, 1, 0x00);

	/* column address */
	write_reg(sohandle, so, 0, 0x2a);
	write_reg(sohandle, so, 1, 0x00);
	write_reg(sohandle, so, 1, 0x00);
	write_reg(sohandle, so, 1, 0x00);
	write_reg(sohandle, so, 1, 0xef);

	/* page address */
	write_reg(sohandle, so, 0, 0x2b);
	write_reg(sohandle, so, 1, 0x00);
	write_reg(sohandle, so, 1, 0x00);
	write_reg(sohandle, so, 1, 0x01);
	write_reg(sohandle, so, 1, 0x8f);

	/* exit sleep mode */
	write_reg(sohandle, so, 0, 0x11);

	mdelay(120);

	/* clear vram */
	clear_memory(sohandle, so);

	/* display ON */
	write_reg(sohandle, so, 0, 0x29);
	mdelay(1);

	write_memory_start(sohandle, so);
}

int kfr2r09_lcd_setup(void *sohandle, struct sh_mobile_lcdc_sys_bus_ops *so)
{
	/* power on */
	gpio_set_value(GPIO_PTF4, 0);  /* PROTECT/ -> L */
	gpio_set_value(GPIO_PTE4, 0);  /* LCD_RST/ -> L */
	gpio_set_value(GPIO_PTF4, 1);  /* PROTECT/ -> H */
	udelay(1100);
	gpio_set_value(GPIO_PTE4, 1);  /* LCD_RST/ -> H */
	udelay(10);
	gpio_set_value(GPIO_PTF4, 0);  /* PROTECT/ -> L */
	mdelay(20);

	if (read_device_code(sohandle, so) != 0x01221517)
		return -ENODEV;

	pr_info("KFR2R09 WQVGA LCD Module detected.\n");

	display_on(sohandle, so);
	return 0;
}

void kfr2r09_lcd_start(void *sohandle, struct sh_mobile_lcdc_sys_bus_ops *so)
{
	write_memory_start(sohandle, so);
}

