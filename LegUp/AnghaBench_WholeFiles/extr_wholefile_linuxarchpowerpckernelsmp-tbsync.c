#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
typedef  scalar_t__ u64 ;
struct TYPE_4__ {long race_result; int ack; int handshake; int cmd; scalar_t__ tb; scalar_t__ mark; } ;

/* Variables and functions */
 int /*<<< orphan*/  GFP_KERNEL ; 
 int NUM_ITER ; 
 int abs (int) ; 
 int /*<<< orphan*/  barrier () ; 
 scalar_t__ get_tb () ; 
 int kExit ; 
 int kSetAndTest ; 
 int kTest ; 
 int /*<<< orphan*/  kfree (TYPE_1__*) ; 
 TYPE_1__* kzalloc (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  local_irq_disable () ; 
 int /*<<< orphan*/  local_irq_enable () ; 
 int /*<<< orphan*/  local_irq_restore (unsigned long) ; 
 int /*<<< orphan*/  local_irq_save (unsigned long) ; 
 int /*<<< orphan*/  mb () ; 
 int /*<<< orphan*/  pr_debug (char*,...) ; 
 int /*<<< orphan*/  rmb () ; 
 int running ; 
 int /*<<< orphan*/  set_tb (scalar_t__,scalar_t__) ; 
 TYPE_1__* tbsync ; 
 int /*<<< orphan*/  wmb () ; 

__attribute__((used)) static void enter_contest(u64 mark, long add)
{
	while (get_tb() < mark)
		tbsync->race_result = add;
}

void smp_generic_take_timebase(void)
{
	int cmd;
	u64 tb;
	unsigned long flags;

	local_irq_save(flags);
	while (!running)
		barrier();
	rmb();

	for (;;) {
		tbsync->ack = 1;
		while (!tbsync->handshake)
			barrier();
		rmb();

		cmd = tbsync->cmd;
		tb = tbsync->tb;
		mb();
		tbsync->ack = 0;
		if (cmd == kExit)
			break;

		while (tbsync->handshake)
			barrier();
		if (cmd == kSetAndTest)
			set_tb(tb >> 32, tb & 0xfffffffful);
		enter_contest(tbsync->mark, -1);
	}
	local_irq_restore(flags);
}

__attribute__((used)) static int start_contest(int cmd, long offset, int num)
{
	int i, score=0;
	u64 tb;
	u64 mark;

	tbsync->cmd = cmd;

	local_irq_disable();
	for (i = -3; i < num; ) {
		tb = get_tb() + 400;
		tbsync->tb = tb + offset;
		tbsync->mark = mark = tb + 400;

		wmb();

		tbsync->handshake = 1;
		while (tbsync->ack)
			barrier();

		while (get_tb() <= tb)
			barrier();
		tbsync->handshake = 0;
		enter_contest(mark, 1);

		while (!tbsync->ack)
			barrier();

		if (i++ > 0)
			score += tbsync->race_result;
	}
	local_irq_enable();
	return score;
}

void smp_generic_give_timebase(void)
{
	int i, score, score2, old, min=0, max=5000, offset=1000;

	pr_debug("Software timebase sync\n");

	/* if this fails then this kernel won't work anyway... */
	tbsync = kzalloc( sizeof(*tbsync), GFP_KERNEL );
	mb();
	running = 1;

	while (!tbsync->ack)
		barrier();

	pr_debug("Got ack\n");

	/* binary search */
	for (old = -1; old != offset ; offset = (min+max) / 2) {
		score = start_contest(kSetAndTest, offset, NUM_ITER);

		pr_debug("score %d, offset %d\n", score, offset );

		if( score > 0 )
			max = offset;
		else
			min = offset;
		old = offset;
	}
	score = start_contest(kSetAndTest, min, NUM_ITER);
	score2 = start_contest(kSetAndTest, max, NUM_ITER);

	pr_debug("Min %d (score %d), Max %d (score %d)\n",
		 min, score, max, score2);
	score = abs(score);
	score2 = abs(score2);
	offset = (score < score2) ? min : max;

	/* guard against inaccurate mttb */
	for (i = 0; i < 10; i++) {
		start_contest(kSetAndTest, offset, NUM_ITER/10);

		if ((score2 = start_contest(kTest, offset, NUM_ITER)) < 0)
			score2 = -score2;
		if (score2 <= score || score2 < 20)
			break;
	}
	pr_debug("Final offset: %d (%d/%d)\n", offset, score2, NUM_ITER );

	/* exiting */
	tbsync->cmd = kExit;
	wmb();
	tbsync->handshake = 1;
	while (tbsync->ack)
		barrier();
	tbsync->handshake = 0;
	kfree(tbsync);
	tbsync = NULL;
	running = 0;
}

