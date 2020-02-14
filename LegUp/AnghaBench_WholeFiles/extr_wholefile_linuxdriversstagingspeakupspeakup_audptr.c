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
struct spk_synth {int alive; int /*<<< orphan*/  long_name; TYPE_1__* io_ops; int /*<<< orphan*/  (* synth_immediate ) (struct spk_synth*,char*) ;} ;
struct TYPE_2__ {char (* synth_in ) () ;int /*<<< orphan*/  (* synth_out ) (struct spk_synth*,int /*<<< orphan*/ ) ;int /*<<< orphan*/  (* send_xchar ) (int /*<<< orphan*/ ) ;int /*<<< orphan*/  (* flush_buffer ) () ;} ;

/* Variables and functions */
 int /*<<< orphan*/  PROCSPEECH ; 
 int /*<<< orphan*/  SYNTH_CLEAR ; 
 int /*<<< orphan*/  pr_info (char*,int /*<<< orphan*/ ,char*) ; 
 int spk_ttyio_synth_probe (struct spk_synth*) ; 
 int /*<<< orphan*/  stub1 () ; 
 int /*<<< orphan*/  stub2 (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  stub3 (struct spk_synth*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  stub4 (struct spk_synth*,char*) ; 
 char stub5 () ; 
 char stub6 () ; 

__attribute__((used)) static void synth_flush(struct spk_synth *synth)
{
	synth->io_ops->flush_buffer();
	synth->io_ops->send_xchar(SYNTH_CLEAR);
	synth->io_ops->synth_out(synth, PROCSPEECH);
}

__attribute__((used)) static void synth_version(struct spk_synth *synth)
{
	unsigned char test = 0;
	char synth_id[40] = "";

	synth->synth_immediate(synth, "\x05[Q]");
	synth_id[test] = synth->io_ops->synth_in();
	if (synth_id[test] == 'A') {
		do {
			/* read version string from synth */
			synth_id[++test] = synth->io_ops->synth_in();
		} while (synth_id[test] != '\n' && test < 32);
		synth_id[++test] = 0x00;
	}
	if (synth_id[0] == 'A')
		pr_info("%s version: %s", synth->long_name, synth_id);
}

__attribute__((used)) static int synth_probe(struct spk_synth *synth)
{
	int failed;

	failed = spk_ttyio_synth_probe(synth);
	if (failed == 0)
		synth_version(synth);
	synth->alive = !failed;
	return 0;
}

