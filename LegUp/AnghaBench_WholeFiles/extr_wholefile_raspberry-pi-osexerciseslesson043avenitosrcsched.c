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
struct TYPE_2__ {int sp; } ;
struct task_struct {int preempt_count; scalar_t__ state; int counter; int priority; TYPE_1__ cpu_context; } ;

/* Variables and functions */
 int NR_TASKS ; 
 scalar_t__ TASK_RUNNING ; 
 int /*<<< orphan*/  cpu_switch_to (struct task_struct*,struct task_struct*) ; 
 struct task_struct* current ; 
 int /*<<< orphan*/  disable_irq () ; 
 int /*<<< orphan*/  enable_irq () ; 
 int /*<<< orphan*/  printf (char*,...) ; 
 void switch_to (struct task_struct*) ; 
 struct task_struct** task ; 

void preempt_disable(void)
{
	current->preempt_count++;
}

void preempt_enable(void)
{
	current->preempt_count--;
}

void _schedule(void)
{
	preempt_disable();
	int next,c;
	struct task_struct * p;
	while (1) {
		c = -1;
		next = 0;
		for (int i = 0; i < NR_TASKS; i++){
			p = task[i];
			if (p && p->state == TASK_RUNNING && p->counter > c) {
				c = p->counter;
				next = i;
			}
		}
		if (c) {
			break;
		}
		for (int i = 0; i < NR_TASKS; i++) {
			p = task[i];
			if (p) {
				p->counter = (p->counter >> 1) + p->priority;
			}
		}
	}
	switch_to(task[next]);
	preempt_enable();
}

void schedule(void)
{
	current->counter = 0;
	_schedule();
}

void switch_to(struct task_struct * next) 
{
	struct task_struct * p;
	printf("\n\r\n\r----------- Task switch -----------\r\n");
	for(int t=0; t < NR_TASKS; t++) {
		p = task[t];
		printf("\n\rtask[%d] counter = %d\n\r", t, p->counter);
		printf("task[%d] priority = %d\n\r", t, p->priority);
		printf("task[%d] preempt_count = %d\n\r", t, p->preempt_count);
		printf("task[%d] sp = 0x%08x\n\r", t, p->cpu_context.sp);
		printf("\n\r------------------------------\r\n");
	}
	printf("\n\rtask output: ");
	
	if (current == next) 
		return;
	struct task_struct * prev = current;
	current = next;
	cpu_switch_to(prev, next);
}

void schedule_tail(void) {
	preempt_enable();
}

void timer_tick()
{
	--current->counter;
	if (current->counter>0 || current->preempt_count >0) {
		return;
	}
	current->counter=0;
	enable_irq();
	_schedule();
	disable_irq();
}

