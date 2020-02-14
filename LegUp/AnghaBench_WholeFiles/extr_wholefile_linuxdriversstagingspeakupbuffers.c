#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_10__   TYPE_5__ ;
typedef  struct TYPE_9__   TYPE_4__ ;
typedef  struct TYPE_8__   TYPE_3__ ;
typedef  struct TYPE_7__   TYPE_2__ ;
typedef  struct TYPE_6__   TYPE_1__ ;

/* Type definitions */
typedef  int u16 ;
struct TYPE_10__ {scalar_t__ tty_stopped; } ;
struct TYPE_9__ {int /*<<< orphan*/  alive; } ;
struct TYPE_8__ {TYPE_2__* d; } ;
struct TYPE_6__ {scalar_t__ tty; } ;
struct TYPE_7__ {TYPE_1__ port; } ;

/* Variables and functions */
 int MAX_NR_CONSOLES ; 
 int SYNTH_BUF_SIZE ; 
 int* buff_in ; 
 int* buff_out ; 
 int* buffer_end ; 
 TYPE_5__** speakup_console ; 
 int spk_paused ; 
 int /*<<< orphan*/  start_tty (scalar_t__) ; 
 int /*<<< orphan*/  stop_tty (scalar_t__) ; 
 TYPE_4__* synth ; 
 int* synth_buffer ; 
 int /*<<< orphan*/  synth_start () ; 
 TYPE_3__* vc_cons ; 

void speakup_start_ttys(void)
{
	int i;

	for (i = 0; i < MAX_NR_CONSOLES; i++) {
		if (speakup_console[i] && speakup_console[i]->tty_stopped)
			continue;
		if (vc_cons[i].d && vc_cons[i].d->port.tty)
			start_tty(vc_cons[i].d->port.tty);
	}
}

__attribute__((used)) static void speakup_stop_ttys(void)
{
	int i;

	for (i = 0; i < MAX_NR_CONSOLES; i++)
		if (vc_cons[i].d && vc_cons[i].d->port.tty)
			stop_tty(vc_cons[i].d->port.tty);
}

__attribute__((used)) static int synth_buffer_free(void)
{
	int chars_free;

	if (buff_in >= buff_out)
		chars_free = SYNTH_BUF_SIZE - (buff_in - buff_out);
	else
		chars_free = buff_out - buff_in;
	return chars_free;
}

int synth_buffer_empty(void)
{
	return (buff_in == buff_out);
}

void synth_buffer_add(u16 ch)
{
	if (!synth->alive) {
		/* This makes sure that we won't stop TTYs if there is no synth
		 * to restart them
		 */
		return;
	}
	if (synth_buffer_free() <= 100) {
		synth_start();
		speakup_stop_ttys();
	}
	if (synth_buffer_free() <= 1)
		return;
	*buff_in++ = ch;
	if (buff_in > buffer_end)
		buff_in = synth_buffer;
	/* We have written something to the speech synthesis, so we are not
	 * paused any more.
	 */
	spk_paused = false;
}

u16 synth_buffer_getc(void)
{
	u16 ch;

	if (buff_out == buff_in)
		return 0;
	ch = *buff_out++;
	if (buff_out > buffer_end)
		buff_out = synth_buffer;
	return ch;
}

u16 synth_buffer_peek(void)
{
	if (buff_out == buff_in)
		return 0;
	return *buff_out;
}

void synth_buffer_skip_nonlatin1(void)
{
	while (buff_out != buff_in) {
		if (*buff_out < 0x100)
			return;
		buff_out++;
		if (buff_out > buffer_end)
			buff_out = synth_buffer;
	}
}

void synth_buffer_clear(void)
{
	buff_in = synth_buffer;
	buff_out = synth_buffer;
}

