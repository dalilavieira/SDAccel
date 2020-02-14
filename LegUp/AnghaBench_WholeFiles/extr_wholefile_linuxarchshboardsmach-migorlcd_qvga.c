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
 int ARRAY_SIZE (unsigned short*) ; 
 int ENODEV ; 
 int /*<<< orphan*/  GPIO_PTH2 ; 
 int /*<<< orphan*/  gpio_set_value (int /*<<< orphan*/ ,int) ; 
 unsigned short* magic0_data ; 
 unsigned short* magic1_data ; 
 unsigned short* magic2_data ; 
 unsigned short* magic3_data ; 
 int /*<<< orphan*/  mdelay (int) ; 
 int /*<<< orphan*/  pr_info (char*) ; 
 int /*<<< orphan*/  stub1 (void*,unsigned long) ; 
 int /*<<< orphan*/  stub2 (void*,unsigned long) ; 
 int /*<<< orphan*/  stub3 (void*,unsigned long) ; 
 int /*<<< orphan*/  stub4 (void*,unsigned long) ; 
 unsigned long stub5 (void*) ; 
 unsigned short* sync_data ; 

__attribute__((used)) static void reset_lcd_module(void)
{
	gpio_set_value(GPIO_PTH2, 0);
	mdelay(2);
	gpio_set_value(GPIO_PTH2, 1);
	mdelay(1);
}

__attribute__((used)) static unsigned long adjust_reg18(unsigned short data)
{
	unsigned long tmp1, tmp2;

	tmp1 = (data<<1 | 0x00000001) & 0x000001FF;
	tmp2 = (data<<2 | 0x00000200) & 0x0003FE00;
	return tmp1 | tmp2;
}

__attribute__((used)) static void write_reg(void *sys_ops_handle,
		       struct sh_mobile_lcdc_sys_bus_ops *sys_ops,
		       unsigned short reg, unsigned short data)
{
	sys_ops->write_index(sys_ops_handle, adjust_reg18(reg << 8 | data));
}

__attribute__((used)) static void write_reg16(void *sys_ops_handle,
			struct sh_mobile_lcdc_sys_bus_ops *sys_ops,
			unsigned short reg, unsigned short data)
{
	sys_ops->write_index(sys_ops_handle, adjust_reg18(reg));
	sys_ops->write_data(sys_ops_handle, adjust_reg18(data));
}

__attribute__((used)) static unsigned long read_reg16(void *sys_ops_handle,
				struct sh_mobile_lcdc_sys_bus_ops *sys_ops,
				unsigned short reg)
{
	unsigned long data;

	sys_ops->write_index(sys_ops_handle, adjust_reg18(reg));
	data = sys_ops->read_data(sys_ops_handle);
	return ((data >> 1) & 0xff) | ((data >> 2) & 0xff00);
}

__attribute__((used)) static void migor_lcd_qvga_seq(void *sys_ops_handle,
			       struct sh_mobile_lcdc_sys_bus_ops *sys_ops,
			       unsigned short const *data, int no_data)
{
	int i;

	for (i = 0; i < no_data; i += 2)
		write_reg16(sys_ops_handle, sys_ops, data[i], data[i + 1]);
}

int migor_lcd_qvga_setup(void *sohandle, struct sh_mobile_lcdc_sys_bus_ops *so)
{
	unsigned long xres = 320;
	unsigned long yres = 240;
	int k;

	reset_lcd_module();
	migor_lcd_qvga_seq(sohandle, so, sync_data, ARRAY_SIZE(sync_data));

	if (read_reg16(sohandle, so, 0) != 0x1505)
		return -ENODEV;

	pr_info("Migo-R QVGA LCD Module detected.\n");

	migor_lcd_qvga_seq(sohandle, so, sync_data, ARRAY_SIZE(sync_data));
	write_reg16(sohandle, so, 0x00A4, 0x0001);
	mdelay(10);

	migor_lcd_qvga_seq(sohandle, so, magic0_data, ARRAY_SIZE(magic0_data));
	mdelay(100);

	migor_lcd_qvga_seq(sohandle, so, magic1_data, ARRAY_SIZE(magic1_data));
	write_reg16(sohandle, so, 0x0050, 0xef - (yres - 1));
	write_reg16(sohandle, so, 0x0051, 0x00ef);
	write_reg16(sohandle, so, 0x0052, 0x0000);
	write_reg16(sohandle, so, 0x0053, xres - 1);

	migor_lcd_qvga_seq(sohandle, so, magic2_data, ARRAY_SIZE(magic2_data));
	mdelay(10);

	migor_lcd_qvga_seq(sohandle, so, magic3_data, ARRAY_SIZE(magic3_data));
	mdelay(40);

	/* clear GRAM to avoid displaying garbage */

	write_reg16(sohandle, so, 0x0020, 0x0000); /* horiz addr */
	write_reg16(sohandle, so, 0x0021, 0x0000); /* vert addr */

	for (k = 0; k < (xres * 256); k++) /* yes, 256 words per line */
		write_reg16(sohandle, so, 0x0022, 0x0000);

	write_reg16(sohandle, so, 0x0020, 0x0000); /* reset horiz addr */
	write_reg16(sohandle, so, 0x0021, 0x0000); /* reset vert addr */
	write_reg16(sohandle, so, 0x0007, 0x0173);
	mdelay(40);

	/* enable display */
	write_reg(sohandle, so, 0x00, 0x22);
	mdelay(100);
	return 0;
}

