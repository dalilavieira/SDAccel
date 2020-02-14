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
struct spk_synth {int /*<<< orphan*/  (* synth_immediate ) (struct spk_synth*,char*) ;TYPE_3__* io_ops; int /*<<< orphan*/  (* flush ) (struct spk_synth*) ;} ;
struct TYPE_8__ {int /*<<< orphan*/  spinlock; scalar_t__ flushing; } ;
struct TYPE_7__ {int /*<<< orphan*/  (* flush_buffer ) () ;int /*<<< orphan*/  (* synth_out ) (struct spk_synth*,char) ;} ;

/* Variables and functions */
 int /*<<< orphan*/  DELAY ; 
 int /*<<< orphan*/  JIFFY ; 
 char PROCSPEECH ; 
 char SPACE ; 
 int /*<<< orphan*/  TASK_INTERRUPTIBLE ; 
 int /*<<< orphan*/  TASK_RUNNING ; 
 int in_escape ; 
 int jiffies ; 
 int /*<<< orphan*/  kthread_should_stop () ; 
 int last_char ; 
 int /*<<< orphan*/  msecs_to_jiffies (int) ; 
 int /*<<< orphan*/  schedule_timeout (int /*<<< orphan*/ ) ; 
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
 int /*<<< orphan*/  stub6 () ; 
 int /*<<< orphan*/  stub7 (struct spk_synth*,char*) ; 
 scalar_t__ synth_buffer_empty () ; 
 int /*<<< orphan*/  synth_buffer_getc () ; 
 char synth_buffer_peek () ; 
 int /*<<< orphan*/  synth_buffer_skip_nonlatin1 () ; 
 scalar_t__ time_after_eq (int,unsigned long) ; 

__attribute__((used)) static void read_buff_add(u_char ch)
{
	last_char = ch;
}

__attribute__((used)) static inline bool synth_full(void)
{
	return last_char == 0x13;
}

__attribute__((used)) static void do_catch_up(struct spk_synth *synth)
{
	u_char ch;
	static u_char last = '\0';
	unsigned long flags;
	unsigned long jiff_max;
	struct var_t *jiffy_delta;
	struct var_t *delay_time;
	int jiffy_delta_val = 0;
	int delay_time_val = 0;

	jiffy_delta = spk_get_var(JIFFY);
	delay_time = spk_get_var(DELAY);

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
		ch = synth_buffer_peek();
		set_current_state(TASK_INTERRUPTIBLE);
		delay_time_val = delay_time->u.n.value;
		spin_unlock_irqrestore(&speakup_info.spinlock, flags);
		if (ch == '\n')
			ch = 0x0D;
		if (synth_full() || !synth->io_ops->synth_out(synth, ch)) {
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
	in_escape = 0;
	synth->io_ops->flush_buffer();
	synth->synth_immediate(synth, "\033P;10z\033\\");
}

