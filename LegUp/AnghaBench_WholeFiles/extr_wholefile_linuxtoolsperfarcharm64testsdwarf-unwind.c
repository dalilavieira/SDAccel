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
typedef  scalar_t__ u64 ;
struct thread {int /*<<< orphan*/  mg; } ;
struct stack_dump {char* data; scalar_t__ size; } ;
struct regs_dump {scalar_t__* regs; int /*<<< orphan*/  mask; int /*<<< orphan*/  abi; } ;
struct perf_sample {struct regs_dump user_regs; struct stack_dump user_stack; } ;
struct map {scalar_t__ end; } ;

/* Variables and functions */
 int /*<<< orphan*/  PERF_REGS_MASK ; 
 int PERF_REGS_MAX ; 
 size_t PERF_REG_ARM64_SP ; 
 int /*<<< orphan*/  PERF_SAMPLE_REGS_ABI ; 
 scalar_t__ STACK_SIZE ; 
 scalar_t__* calloc (int,int) ; 
 int /*<<< orphan*/  free (scalar_t__*) ; 
 scalar_t__* malloc (scalar_t__) ; 
 struct map* map_groups__find (int /*<<< orphan*/ ,scalar_t__) ; 
 int /*<<< orphan*/  memcpy (scalar_t__*,void*,scalar_t__) ; 
 int /*<<< orphan*/  perf_regs_load (scalar_t__*) ; 
 int /*<<< orphan*/  pr_debug (char*) ; 

__attribute__((used)) static int sample_ustack(struct perf_sample *sample,
		struct thread *thread, u64 *regs)
{
	struct stack_dump *stack = &sample->user_stack;
	struct map *map;
	unsigned long sp;
	u64 stack_size, *buf;

	buf = malloc(STACK_SIZE);
	if (!buf) {
		pr_debug("failed to allocate sample uregs data\n");
		return -1;
	}

	sp = (unsigned long) regs[PERF_REG_ARM64_SP];

	map = map_groups__find(thread->mg, (u64)sp);
	if (!map) {
		pr_debug("failed to get stack map\n");
		free(buf);
		return -1;
	}

	stack_size = map->end - sp;
	stack_size = stack_size > STACK_SIZE ? STACK_SIZE : stack_size;

	memcpy(buf, (void *) sp, stack_size);
	stack->data = (char *) buf;
	stack->size = stack_size;
	return 0;
}

int test__arch_unwind_sample(struct perf_sample *sample,
		struct thread *thread)
{
	struct regs_dump *regs = &sample->user_regs;
	u64 *buf;

	buf = calloc(1, sizeof(u64) * PERF_REGS_MAX);
	if (!buf) {
		pr_debug("failed to allocate sample uregs data\n");
		return -1;
	}

	perf_regs_load(buf);
	regs->abi  = PERF_SAMPLE_REGS_ABI;
	regs->regs = buf;
	regs->mask = PERF_REGS_MASK;

	return sample_ustack(sample, thread, buf);
}

