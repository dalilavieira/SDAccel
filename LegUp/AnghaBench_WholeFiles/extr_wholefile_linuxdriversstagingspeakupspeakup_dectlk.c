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
typedef  char u_char ;
struct TYPE_5__ {int value; } ;
struct TYPE_6__ {TYPE_1__ n; } ;
struct var_t {TYPE_2__ u; } ;
struct spk_synth {TYPE_3__* io_ops; int /*<<< orphan*/  (* flush ) (struct spk_synth*) ;} ;
struct TYPE_8__ {int /*<<< orphan*/  spinlock; scalar_t__ flushing; } ;
struct TYPE_7__ {int /*<<< orphan*/  (* synth_out ) (struct spk_synth*,char) ;int /*<<< orphan*/  (* flush_buffer ) () ;} ;

/* Variables and functions */
 int /*<<< orphan*/  DEFINE_WAIT (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  DELAY ; 
 int /*<<< orphan*/  JIFFY ; 
 char PROCSPEECH ; 
 char SPACE ; 
 char SYNTH_CLEAR ; 
 int /*<<< orphan*/  TASK_INTERRUPTIBLE ; 
 int /*<<< orphan*/  TASK_RUNNING ; 
 int /*<<< orphan*/  finish_wait (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  flush ; 
 int /*<<< orphan*/  flush_lock ; 
 int in_escape ; 
 int is_flushing ; 
 int jiffies ; 
 int /*<<< orphan*/  kthread_should_stop () ; 
 char lastind ; 
 unsigned long msecs_to_jiffies (int) ; 
 int /*<<< orphan*/  prepare_to_wait (int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 unsigned long schedule_timeout (unsigned long) ; 
 int /*<<< orphan*/  set_current_state (int /*<<< orphan*/ ) ; 
 TYPE_4__ speakup_info ; 
 int /*<<< orphan*/  spin_lock_irqsave (int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  spin_unlock_irqrestore (int /*<<< orphan*/ *,unsigned long) ; 
 struct var_t* spk_get_var (int /*<<< orphan*/ ) ; 
 scalar_t__ strchr (char*,char) ; 
 int /*<<< orphan*/  stub1 (struct spk_synth*) ; 
 int /*<<< orphan*/  stub2 (struct spk_synth*,char) ; 
 int /*<<< orphan*/  stub3 (struct spk_synth*,char) ; 
 int /*<<< orphan*/  stub4 (struct spk_synth*,char) ; 
 int /*<<< orphan*/  stub5 (struct spk_synth*,char) ; 
 int /*<<< orphan*/  stub6 (struct spk_synth*,char) ; 
 int /*<<< orphan*/  stub7 () ; 
 int /*<<< orphan*/  stub8 (struct spk_synth*,char) ; 
 scalar_t__ synth_buffer_empty () ; 
 int /*<<< orphan*/  synth_buffer_getc () ; 
 char synth_buffer_peek () ; 
 int /*<<< orphan*/  synth_buffer_skip_nonlatin1 () ; 
 scalar_t__ time_after_eq (int,unsigned long) ; 
 int /*<<< orphan*/  wait ; 
 int /*<<< orphan*/  wake_up_interruptible (int /*<<< orphan*/ *) ; 
 int xoff ; 

__attribute__((used)) static inline int synth_full(void)
{
	return xoff;
}

__attribute__((used)) static int is_indnum(u_char *ch)
{
	if ((*ch >= '0') && (*ch <= '9')) {
		*ch = *ch - '0';
		return 1;
	}
	return 0;
}

__attribute__((used)) static unsigned char get_index(struct spk_synth *synth)
{
	u_char rv;

	rv = lastind;
	lastind = 0;
	return rv;
}

__attribute__((used)) static void read_buff_add(u_char c)
{
	static int ind = -1;

	if (c == 0x01) {
		unsigned long flags;

		spin_lock_irqsave(&flush_lock, flags);
		is_flushing = 0;
		wake_up_interruptible(&flush);
		spin_unlock_irqrestore(&flush_lock, flags);
	} else if (c == 0x13) {
		xoff = 1;
	} else if (c == 0x11) {
		xoff = 0;
	} else if (is_indnum(&c)) {
		if (ind == -1)
			ind = c;
		else
			ind = ind * 10 + c;
	} else if ((c > 31) && (c < 127)) {
		if (ind != -1)
			lastind = (u_char)ind;
		ind = -1;
	}
}

__attribute__((used)) static void do_catch_up(struct spk_synth *synth)
{
	int synth_full_val = 0;
	static u_char ch;
	static u_char last = '\0';
	unsigned long flags;
	unsigned long jiff_max;
	unsigned long timeout = msecs_to_jiffies(4000);
	DEFINE_WAIT(wait);
	struct var_t *jiffy_delta;
	struct var_t *delay_time;
	int jiffy_delta_val;
	int delay_time_val;

	jiffy_delta = spk_get_var(JIFFY);
	delay_time = spk_get_var(DELAY);
	spin_lock_irqsave(&speakup_info.spinlock, flags);
	jiffy_delta_val = jiffy_delta->u.n.value;
	spin_unlock_irqrestore(&speakup_info.spinlock, flags);
	jiff_max = jiffies + jiffy_delta_val;

	while (!kthread_should_stop()) {
		/* if no ctl-a in 4, send data anyway */
		spin_lock_irqsave(&flush_lock, flags);
		while (is_flushing && timeout) {
			prepare_to_wait(&flush, &wait, TASK_INTERRUPTIBLE);
			spin_unlock_irqrestore(&flush_lock, flags);
			timeout = schedule_timeout(timeout);
			spin_lock_irqsave(&flush_lock, flags);
		}
		finish_wait(&flush, &wait);
		is_flushing = 0;
		spin_unlock_irqrestore(&flush_lock, flags);

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
		ch = synth_buffer_peek();
		set_current_state(TASK_INTERRUPTIBLE);
		delay_time_val = delay_time->u.n.value;
		synth_full_val = synth_full();
		spin_unlock_irqrestore(&speakup_info.spinlock, flags);
		if (ch == '\n')
			ch = 0x0D;
		if (synth_full_val || !synth->io_ops->synth_out(synth, ch)) {
			schedule_timeout(msecs_to_jiffies(delay_time_val));
			continue;
		}
		set_current_state(TASK_RUNNING);
		spin_lock_irqsave(&speakup_info.spinlock, flags);
		synth_buffer_getc();
		spin_unlock_irqrestore(&speakup_info.spinlock, flags);
		if (ch == '[') {
			in_escape = 1;
		} else if (ch == ']') {
			in_escape = 0;
		} else if (ch <= SPACE) {
			if (!in_escape && strchr(",.!?;:", last))
				synth->io_ops->synth_out(synth, PROCSPEECH);
			if (time_after_eq(jiffies, jiff_max)) {
				if (!in_escape)
					synth->io_ops->synth_out(synth, PROCSPEECH);
				spin_lock_irqsave(&speakup_info.spinlock,
						  flags);
				jiffy_delta_val = jiffy_delta->u.n.value;
				delay_time_val = delay_time->u.n.value;
				spin_unlock_irqrestore(&speakup_info.spinlock,
						       flags);
				schedule_timeout(msecs_to_jiffies
						 (delay_time_val));
				jiff_max = jiffies + jiffy_delta_val;
			}
		}
		last = ch;
	}
	if (!in_escape)
		synth->io_ops->synth_out(synth, PROCSPEECH);
}

__attribute__((used)) static void synth_flush(struct spk_synth *synth)
{
	if (in_escape)
		/* if in command output ']' so we don't get an error */
		synth->io_ops->synth_out(synth, ']');
	in_escape = 0;
	is_flushing = 1;
	synth->io_ops->flush_buffer();
	synth->io_ops->synth_out(synth, SYNTH_CLEAR);
}

