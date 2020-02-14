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
struct parport_state {int dummy; } ;
struct parport {int dummy; } ;
struct pardevice {int dummy; } ;
struct TYPE_4__ {int rd_data_reg_sel; unsigned char wd_data; } ;
struct TYPE_3__ {int par_dt_reg; } ;

/* Variables and functions */
 int /*<<< orphan*/  IRQ_MFP_BUSY ; 
 unsigned char PARPORT_CONTROL_STROBE ; 
 unsigned char PARPORT_STATUS_BUSY ; 
 unsigned char PARPORT_STATUS_ERROR ; 
 unsigned char PARPORT_STATUS_SELECT ; 
 int /*<<< orphan*/  disable_irq (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  enable_irq (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  local_irq_restore (unsigned long) ; 
 int /*<<< orphan*/  local_irq_save (unsigned long) ; 
 TYPE_2__ sound_ym ; 
 TYPE_1__ st_mfp ; 

__attribute__((used)) static unsigned char
parport_atari_read_data(struct parport *p)
{
	unsigned long flags;
	unsigned char data;

	local_irq_save(flags);
	sound_ym.rd_data_reg_sel = 15;
	data = sound_ym.rd_data_reg_sel;
	local_irq_restore(flags);
	return data;
}

__attribute__((used)) static void
parport_atari_write_data(struct parport *p, unsigned char data)
{
	unsigned long flags;

	local_irq_save(flags);
	sound_ym.rd_data_reg_sel = 15;
	sound_ym.wd_data = data;
	local_irq_restore(flags);
}

__attribute__((used)) static unsigned char
parport_atari_read_control(struct parport *p)
{
	unsigned long flags;
	unsigned char control = 0;

	local_irq_save(flags);
	sound_ym.rd_data_reg_sel = 14;
	if (!(sound_ym.rd_data_reg_sel & (1 << 5)))
		control = PARPORT_CONTROL_STROBE;
	local_irq_restore(flags);
	return control;
}

__attribute__((used)) static void
parport_atari_write_control(struct parport *p, unsigned char control)
{
	unsigned long flags;

	local_irq_save(flags);
	sound_ym.rd_data_reg_sel = 14;
	if (control & PARPORT_CONTROL_STROBE)
		sound_ym.wd_data = sound_ym.rd_data_reg_sel & ~(1 << 5);
	else
		sound_ym.wd_data = sound_ym.rd_data_reg_sel | (1 << 5);
	local_irq_restore(flags);
}

__attribute__((used)) static unsigned char
parport_atari_frob_control(struct parport *p, unsigned char mask,
			   unsigned char val)
{
	unsigned char old = parport_atari_read_control(p);
	parport_atari_write_control(p, (old & ~mask) ^ val);
	return old;
}

__attribute__((used)) static unsigned char
parport_atari_read_status(struct parport *p)
{
	return ((st_mfp.par_dt_reg & 1 ? 0 : PARPORT_STATUS_BUSY) |
		PARPORT_STATUS_SELECT | PARPORT_STATUS_ERROR);
}

__attribute__((used)) static void
parport_atari_init_state(struct pardevice *d, struct parport_state *s)
{
}

__attribute__((used)) static void
parport_atari_save_state(struct parport *p, struct parport_state *s)
{
}

__attribute__((used)) static void
parport_atari_restore_state(struct parport *p, struct parport_state *s)
{
}

__attribute__((used)) static void
parport_atari_enable_irq(struct parport *p)
{
	enable_irq(IRQ_MFP_BUSY);
}

__attribute__((used)) static void
parport_atari_disable_irq(struct parport *p)
{
	disable_irq(IRQ_MFP_BUSY);
}

__attribute__((used)) static void
parport_atari_data_forward(struct parport *p)
{
	unsigned long flags;

	local_irq_save(flags);
	/* Soundchip port B as output. */
	sound_ym.rd_data_reg_sel = 7;
	sound_ym.wd_data = sound_ym.rd_data_reg_sel | 0x40;
	local_irq_restore(flags);
}

__attribute__((used)) static void
parport_atari_data_reverse(struct parport *p)
{
}

