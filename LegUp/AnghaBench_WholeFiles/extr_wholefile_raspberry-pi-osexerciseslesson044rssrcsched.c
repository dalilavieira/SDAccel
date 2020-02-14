#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */

/* Type definitions */
struct task_struct {scalar_t__ preempt_count; scalar_t__ state; int counter; int priority; struct task_struct* next; } ;

/* Variables and functions */
 scalar_t__ TASK_RUNNING ; 
 int /*<<< orphan*/  cpu_switch_to (struct task_struct*,struct task_struct*) ; 
 struct task_struct* current ; 
 int /*<<< orphan*/  disable_irq () ; 
 int /*<<< orphan*/  enable_irq () ; 
 struct task_struct* init ; 
 void switch_to (struct task_struct*) ; 

void preempt_disable(void) { current->preempt_count++; }

void preempt_enable(void) { current->preempt_count--; }

void _schedule(void) {
  preempt_disable();
  int c;
  struct task_struct *p, *next;
  while (1) {
    c = -1;
    for (p = init; p; p = p->next) {
      if (p && p->state == TASK_RUNNING && p->counter > c) {
        c = p->counter;
        next = p;
      }
    }
    if (c) {
      break;
    }
    for (p = init; p; p = p->next) {
      if (p) {
        p->counter = (p->counter >> 1) + p->priority;
      }
    }
  }
  switch_to(next);
  preempt_enable();
}

void schedule(void) {
  current->counter = 0;
  _schedule();
}

void switch_to(struct task_struct *next) {
  if (current == next)
    return;
  struct task_struct *prev = current;
  current = next;
  cpu_switch_to(prev, next);
}

void schedule_tail(void) { preempt_enable(); }

void timer_tick() {
  --current->counter;
  if (current->counter > 0 || current->preempt_count > 0) {
    return;
  }
  current->counter = 0;
  enable_irq();
  _schedule();
  disable_irq();
}

