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
typedef  int u8 ;
typedef  int u32 ;
struct TYPE_2__ {int* reg; int* rdata_reg; int clk; int wdata_shift; int rdata_shift; int cs; } ;

/* Variables and functions */
 int AT93C_ADDR_MAX ; 
 int AT93C_RCMD ; 
 int AT93C_WCMD ; 
 int AT93C_WDSCMD ; 
 int AT93C_WENCMD ; 
 TYPE_1__* at93c ; 
 int /*<<< orphan*/  lasat_ndelay (int) ; 

__attribute__((used)) static void at93c_reg_write(u32 val)
{
	*at93c->reg = val;
}

__attribute__((used)) static u32 at93c_reg_read(void)
{
	u32 tmp = *at93c->reg;
	return tmp;
}

__attribute__((used)) static u32 at93c_datareg_read(void)
{
	u32 tmp = *at93c->rdata_reg;
	return tmp;
}

__attribute__((used)) static void at93c_cycle_clk(u32 data)
{
	at93c_reg_write(data | at93c->clk);
	lasat_ndelay(250);
	at93c_reg_write(data & ~at93c->clk);
	lasat_ndelay(250);
}

__attribute__((used)) static void at93c_write_databit(u8 bit)
{
	u32 data = at93c_reg_read();
	if (bit)
		data |= 1 << at93c->wdata_shift;
	else
		data &= ~(1 << at93c->wdata_shift);

	at93c_reg_write(data);
	lasat_ndelay(100);
	at93c_cycle_clk(data);
}

__attribute__((used)) static unsigned int at93c_read_databit(void)
{
	u32 data;

	at93c_cycle_clk(at93c_reg_read());
	data = (at93c_datareg_read() >> at93c->rdata_shift) & 1;
	return data;
}

__attribute__((used)) static u8 at93c_read_byte(void)
{
	int i;
	u8 data = 0;

	for (i = 0; i <= 7; i++) {
		data <<= 1;
		data |= at93c_read_databit();
	}
	return data;
}

__attribute__((used)) static void at93c_write_bits(u32 data, int size)
{
	int i;
	int shift = size - 1;
	u32 mask = (1 << shift);

	for (i = 0; i < size; i++) {
		at93c_write_databit((data & mask) >> shift);
		data <<= 1;
	}
}

__attribute__((used)) static void at93c_init_op(void)
{
	at93c_reg_write((at93c_reg_read() | at93c->cs) &
			~at93c->clk & ~(1 << at93c->rdata_shift));
	lasat_ndelay(50);
}

__attribute__((used)) static void at93c_end_op(void)
{
	at93c_reg_write(at93c_reg_read() & ~at93c->cs);
	lasat_ndelay(250);
}

__attribute__((used)) static void at93c_wait(void)
{
	at93c_init_op();
	while (!at93c_read_databit())
		;
	at93c_end_op();
}

__attribute__((used)) static void at93c_disable_wp(void)
{
	at93c_init_op();
	at93c_write_bits(AT93C_WENCMD, 10);
	at93c_end_op();
}

__attribute__((used)) static void at93c_enable_wp(void)
{
	at93c_init_op();
	at93c_write_bits(AT93C_WDSCMD, 10);
	at93c_end_op();
}

u8 at93c_read(u8 addr)
{
	u8 byte;
	at93c_init_op();
	at93c_write_bits((addr & AT93C_ADDR_MAX)|AT93C_RCMD, 10);
	byte = at93c_read_byte();
	at93c_end_op();
	return byte;
}

void at93c_write(u8 addr, u8 data)
{
	at93c_disable_wp();
	at93c_init_op();
	at93c_write_bits((addr & AT93C_ADDR_MAX)|AT93C_WCMD, 10);
	at93c_write_bits(data, 8);
	at93c_end_op();
	at93c_wait();
	at93c_enable_wp();
}

