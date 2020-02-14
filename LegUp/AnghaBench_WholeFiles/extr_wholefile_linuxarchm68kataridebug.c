#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_8__   TYPE_4__ ;
typedef  struct TYPE_7__   TYPE_3__ ;
typedef  struct TYPE_6__   TYPE_2__ ;
typedef  struct TYPE_5__   TYPE_1__ ;

/* Type definitions */
struct console {int dummy; } ;
struct TYPE_8__ {int mid_ctrl; char mid_data; } ;
struct TYPE_7__ {int cha_b_ctrl; char cha_b_data; } ;
struct TYPE_6__ {int rd_data_reg_sel; char wd_data; } ;
struct TYPE_5__ {int trn_stat; char usart_dta; int par_dt_reg; } ;

/* Variables and functions */
 int ACIA_TDRE ; 
 int HZ ; 
 int /*<<< orphan*/  MFPDELAY () ; 
 TYPE_4__ acia ; 
 TYPE_3__ atari_scc ; 
 int /*<<< orphan*/  barrier () ; 
 int loops_per_jiffy ; 
 TYPE_2__ sound_ym ; 
 TYPE_1__ st_mfp ; 

__attribute__((used)) static inline void ata_mfp_out(char c)
{
	while (!(st_mfp.trn_stat & 0x80))	/* wait for tx buf empty */
		barrier();
	st_mfp.usart_dta = c;
}

__attribute__((used)) static void atari_mfp_console_write(struct console *co, const char *str,
				    unsigned int count)
{
	while (count--) {
		if (*str == '\n')
			ata_mfp_out('\r');
		ata_mfp_out(*str++);
	}
}

__attribute__((used)) static inline void ata_scc_out(char c)
{
	do {
		MFPDELAY();
	} while (!(atari_scc.cha_b_ctrl & 0x04)); /* wait for tx buf empty */
	MFPDELAY();
	atari_scc.cha_b_data = c;
}

__attribute__((used)) static void atari_scc_console_write(struct console *co, const char *str,
				    unsigned int count)
{
	while (count--) {
		if (*str == '\n')
			ata_scc_out('\r');
		ata_scc_out(*str++);
	}
}

__attribute__((used)) static inline void ata_midi_out(char c)
{
	while (!(acia.mid_ctrl & ACIA_TDRE))	/* wait for tx buf empty */
		barrier();
	acia.mid_data = c;
}

__attribute__((used)) static void atari_midi_console_write(struct console *co, const char *str,
				     unsigned int count)
{
	while (count--) {
		if (*str == '\n')
			ata_midi_out('\r');
		ata_midi_out(*str++);
	}
}

__attribute__((used)) static int ata_par_out(char c)
{
	unsigned char tmp;
	/* This a some-seconds timeout in case no printer is connected */
	unsigned long i = loops_per_jiffy > 1 ? loops_per_jiffy : 10000000/HZ;

	while ((st_mfp.par_dt_reg & 1) && --i) /* wait for BUSY == L */
		;
	if (!i)
		return 0;

	sound_ym.rd_data_reg_sel = 15;	/* select port B */
	sound_ym.wd_data = c;		/* put char onto port */
	sound_ym.rd_data_reg_sel = 14;	/* select port A */
	tmp = sound_ym.rd_data_reg_sel;
	sound_ym.wd_data = tmp & ~0x20;	/* set strobe L */
	MFPDELAY();			/* wait a bit */
	sound_ym.wd_data = tmp | 0x20;	/* set strobe H */
	return 1;
}

__attribute__((used)) static void atari_par_console_write(struct console *co, const char *str,
				    unsigned int count)
{
	static int printer_present = 1;

	if (!printer_present)
		return;

	while (count--) {
		if (*str == '\n') {
			if (!ata_par_out('\r')) {
				printer_present = 0;
				return;
			}
		}
		if (!ata_par_out(*str++)) {
			printer_present = 0;
			return;
		}
	}
}

