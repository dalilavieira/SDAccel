#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_6__   TYPE_3__ ;
typedef  struct TYPE_5__   TYPE_2__ ;
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
typedef  char u_char ;
struct TYPE_4__ {int value; } ;
struct TYPE_5__ {TYPE_1__ n; } ;
struct var_t {TYPE_2__ u; } ;
struct spk_synth {int alive; int /*<<< orphan*/  version; int /*<<< orphan*/  long_name; int /*<<< orphan*/  (* flush ) (struct spk_synth*) ;} ;
struct TYPE_6__ {int /*<<< orphan*/  spinlock; scalar_t__ flushing; } ;

/* Variables and functions */
 int /*<<< orphan*/  DELAY ; 
 int EBUSY ; 
 int ENODEV ; 
 int /*<<< orphan*/  FULL ; 
 int /*<<< orphan*/  JIFFY ; 
 char PROCSPEECH ; 
 char SPACE ; 
 int /*<<< orphan*/  SWAIT ; 
 char SYNTH_CLEAR ; 
 int SYNTH_IO_EXTENT ; 
 int /*<<< orphan*/  TASK_INTERRUPTIBLE ; 
 int /*<<< orphan*/  TASK_RUNNING ; 
 int UART_RX ; 
 unsigned int inb (int) ; 
 int inb_p (int) ; 
 int jiffies ; 
 int /*<<< orphan*/  kthread_should_stop () ; 
 int /*<<< orphan*/  msecs_to_jiffies (int) ; 
 int /*<<< orphan*/  outb_p (char,int) ; 
 int port_forced ; 
 int /*<<< orphan*/  pr_info (char*,int,...) ; 
 int /*<<< orphan*/  pr_warn (char*,...) ; 
 int /*<<< orphan*/  schedule_timeout (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  set_current_state (int /*<<< orphan*/ ) ; 
 TYPE_3__ speakup_info ; 
 int /*<<< orphan*/  spin_lock_irqsave (int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  spin_unlock_irqrestore (int /*<<< orphan*/ *,unsigned long) ; 
 struct var_t* spk_get_var (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  spk_stop_serial_interrupt () ; 
 int /*<<< orphan*/  stub1 (struct spk_synth*) ; 
 scalar_t__ synth_buffer_empty () ; 
 char synth_buffer_getc () ; 
 int /*<<< orphan*/  synth_buffer_skip_nonlatin1 () ; 
 int synth_port ; 
 int* synth_portlist ; 
 int /*<<< orphan*/  synth_release_region (int,int) ; 
 scalar_t__ synth_request_region (int,int) ; 
 scalar_t__ time_after_eq (int,unsigned long) ; 
 int /*<<< orphan*/  udelay (int) ; 

__attribute__((used)) static inline bool synth_writable(void)
{
	return (inb_p(synth_port + UART_RX) & 0x10) != 0;
}

__attribute__((used)) static inline bool synth_full(void)
{
	return (inb_p(synth_port + UART_RX) & 0x80) == 0;
}

__attribute__((used)) static char *oops(void)
{
	int s1, s2, s3, s4;

	s1 = inb_p(synth_port);
	s2 = inb_p(synth_port + 1);
	s3 = inb_p(synth_port + 2);
	s4 = inb_p(synth_port + 3);
	pr_warn("synth timeout %d %d %d %d\n", s1, s2, s3, s4);
	return NULL;
}

__attribute__((used)) static const char *synth_immediate(struct spk_synth *synth, const char *buf)
{
	u_char ch;
	int timeout;

	while ((ch = *buf)) {
		if (ch == '\n')
			ch = PROCSPEECH;
		if (synth_full())
			return buf;
		timeout = 1000;
		while (synth_writable())
			if (--timeout <= 0)
				return oops();
		outb_p(ch, synth_port);
		udelay(70);
		buf++;
	}
	return NULL;
}

__attribute__((used)) static void do_catch_up(struct spk_synth *synth)
{
	u_char ch;
	int timeout;
	unsigned long flags;
	unsigned long jiff_max;
	struct var_t *jiffy_delta;
	struct var_t *delay_time;
	struct var_t *full_time;
	int delay_time_val;
	int full_time_val;
	int jiffy_delta_val;

	jiffy_delta = spk_get_var(JIFFY);
	delay_time = spk_get_var(DELAY);
	full_time = spk_get_var(FULL);
spin_lock_irqsave(&speakup_info.spinlock, flags);
	jiffy_delta_val = jiffy_delta->u.n.value;
	spin_unlock_irqrestore(&speakup_info.spinlock, flags);

	jiff_max = jiffies + jiffy_delta_val;
	while (!kthread_should_stop()) {
		spin_lock_irqsave(&speakup_info.spinlock, flags);
		if (speakup_info.flushing) {
			speakup_info.flushing = 0;
			spin_unlock_irqrestore(&speakup_info.spinlock, flags);
			synth->flush(synth);
			continue;
		}
		synth_buffer_skip_nonlatin1();
		if (synth_buffer_empty()) {
			spin_unlock_irqrestore(&speakup_info.spinlock, flags);
			break;
		}
		set_current_state(TASK_INTERRUPTIBLE);
		full_time_val = full_time->u.n.value;
		spin_unlock_irqrestore(&speakup_info.spinlock, flags);
		if (synth_full()) {
			schedule_timeout(msecs_to_jiffies(full_time_val));
			continue;
		}
		set_current_state(TASK_RUNNING);
		timeout = 1000;
		while (synth_writable())
			if (--timeout <= 0)
				break;
		if (timeout <= 0) {
			oops();
			break;
		}
		spin_lock_irqsave(&speakup_info.spinlock, flags);
		ch = synth_buffer_getc();
		spin_unlock_irqrestore(&speakup_info.spinlock, flags);
		if (ch == '\n')
			ch = PROCSPEECH;
		outb_p(ch, synth_port);
		SWAIT;
		if (time_after_eq(jiffies, jiff_max) && (ch == SPACE)) {
			timeout = 1000;
			while (synth_writable())
				if (--timeout <= 0)
					break;
			if (timeout <= 0) {
				oops();
				break;
			}
			outb_p(PROCSPEECH, synth_port);
			spin_lock_irqsave(&speakup_info.spinlock, flags);
			jiffy_delta_val = jiffy_delta->u.n.value;
			delay_time_val = delay_time->u.n.value;
			spin_unlock_irqrestore(&speakup_info.spinlock, flags);
			schedule_timeout(msecs_to_jiffies(delay_time_val));
			jiff_max = jiffies+jiffy_delta_val;
		}
	}
	timeout = 1000;
	while (synth_writable())
		if (--timeout <= 0)
			break;
	if (timeout <= 0)
		oops();
	else
		outb_p(PROCSPEECH, synth_port);
}

__attribute__((used)) static void synth_flush(struct spk_synth *synth)
{
	outb_p(SYNTH_CLEAR, synth_port);
}

__attribute__((used)) static int synth_probe(struct spk_synth *synth)
{
	unsigned int port_val = 0;
	int i = 0;

	pr_info("Probing for %s.\n", synth->long_name);
	if (port_forced) {
		synth_port = port_forced;
		pr_info("probe forced to %x by kernel command line\n",
			synth_port);
		if (synth_request_region(synth_port-1, SYNTH_IO_EXTENT)) {
			pr_warn("sorry, port already reserved\n");
			return -EBUSY;
		}
		port_val = inb(synth_port);
	} else {
		for (i = 0; synth_portlist[i]; i++) {
			if (synth_request_region(synth_portlist[i],
						 SYNTH_IO_EXTENT)) {
				pr_warn
				    ("request_region: failed with 0x%x, %d\n",
				     synth_portlist[i], SYNTH_IO_EXTENT);
				continue;
			}
			port_val = inb(synth_portlist[i]);
			if (port_val == 0x80) {
				synth_port = synth_portlist[i];
				break;
			}
		}
	}
	if (port_val != 0x80) {
		pr_info("%s: not found\n", synth->long_name);
		synth_release_region(synth_port, SYNTH_IO_EXTENT);
		synth_port = 0;
		return -ENODEV;
	}
	pr_info("%s: %03x-%03x, driver version %s,\n", synth->long_name,
		synth_port, synth_port+SYNTH_IO_EXTENT-1,
		synth->version);
	synth->alive = 1;
	return 0;
}

__attribute__((used)) static void keynote_release(void)
{
	spk_stop_serial_interrupt();
	if (synth_port)
		synth_release_region(synth_port, SYNTH_IO_EXTENT);
	synth_port = 0;
}

