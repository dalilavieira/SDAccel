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
struct task_struct {int dummy; } ;
struct TYPE_2__ {unsigned int id; scalar_t__ active; } ;
struct mm_struct {TYPE_1__ context; int /*<<< orphan*/  pgd; } ;
typedef  int /*<<< orphan*/  phys_addr_t ;

/* Variables and functions */
 int /*<<< orphan*/  CONFIG_PPC_8xx ; 
 unsigned int FIRST_CONTEXT ; 
 scalar_t__ IS_ENABLED (int /*<<< orphan*/ ) ; 
 unsigned int LAST_CONTEXT ; 
 unsigned int MMU_NO_CONTEXT ; 
 int /*<<< orphan*/  WARN_ON (int) ; 
 int /*<<< orphan*/  __clear_bit (unsigned int,unsigned long*) ; 
 scalar_t__ __test_and_set_bit (unsigned int,unsigned long*) ; 
 int /*<<< orphan*/  _tlbil_all () ; 
 int /*<<< orphan*/  context_lock ; 
 unsigned long* context_map ; 
 struct mm_struct** context_mm ; 
 int /*<<< orphan*/  cpu ; 
 unsigned int find_next_zero_bit (unsigned long*,unsigned int,unsigned int) ; 
 scalar_t__ likely (int) ; 
 int /*<<< orphan*/  local_flush_tlb_mm (struct mm_struct*) ; 
 unsigned int next_context ; 
 unsigned int nr_free_contexts ; 
 int /*<<< orphan*/  pr_hard (char*,struct mm_struct*,...) ; 
 int /*<<< orphan*/  pr_hardcont (char*,unsigned int,...) ; 
 int /*<<< orphan*/  raw_spin_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  raw_spin_lock_irqsave (int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  raw_spin_unlock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  raw_spin_unlock_irqrestore (int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  set_context (unsigned int,int /*<<< orphan*/ ) ; 

__attribute__((used)) static inline phys_addr_t v_block_mapped(unsigned long va) { return 0; }

__attribute__((used)) static inline unsigned long p_block_mapped(phys_addr_t pa) { return 0; }

__attribute__((used)) static unsigned int steal_all_contexts(void)
{
	struct mm_struct *mm;
#ifdef CONFIG_SMP
	int cpu = smp_processor_id();
#endif
	unsigned int id;

	for (id = FIRST_CONTEXT; id <= LAST_CONTEXT; id++) {
		/* Pick up the victim mm */
		mm = context_mm[id];

		pr_hardcont(" | steal %d from 0x%p", id, mm);

		/* Mark this mm as having no context anymore */
		mm->context.id = MMU_NO_CONTEXT;
		if (id != FIRST_CONTEXT) {
			context_mm[id] = NULL;
			__clear_bit(id, context_map);
#ifdef DEBUG_MAP_CONSISTENCY
			mm->context.active = 0;
#endif
		}
#ifdef CONFIG_SMP
		__clear_bit(id, stale_map[cpu]);
#endif
	}

	/* Flush the TLB for all contexts (not to be used on SMP) */
	_tlbil_all();

	nr_free_contexts = LAST_CONTEXT - FIRST_CONTEXT;

	return FIRST_CONTEXT;
}

__attribute__((used)) static unsigned int steal_context_up(unsigned int id)
{
	struct mm_struct *mm;
#ifdef CONFIG_SMP
	int cpu = smp_processor_id();
#endif

	/* Pick up the victim mm */
	mm = context_mm[id];

	pr_hardcont(" | steal %d from 0x%p", id, mm);

	/* Flush the TLB for that context */
	local_flush_tlb_mm(mm);

	/* Mark this mm has having no context anymore */
	mm->context.id = MMU_NO_CONTEXT;

	/* XXX This clear should ultimately be part of local_flush_tlb_mm */
#ifdef CONFIG_SMP
	__clear_bit(id, stale_map[cpu]);
#endif

	return id;
}

__attribute__((used)) static void context_check_map(void) { }

void switch_mmu_context(struct mm_struct *prev, struct mm_struct *next,
			struct task_struct *tsk)
{
	unsigned int id;
#ifdef CONFIG_SMP
	unsigned int i, cpu = smp_processor_id();
#endif
	unsigned long *map;

	/* No lockless fast path .. yet */
	raw_spin_lock(&context_lock);

	pr_hard("[%d] activating context for mm @%p, active=%d, id=%d",
		cpu, next, next->context.active, next->context.id);

#ifdef CONFIG_SMP
	/* Mark us active and the previous one not anymore */
	next->context.active++;
	if (prev) {
		pr_hardcont(" (old=0x%p a=%d)", prev, prev->context.active);
		WARN_ON(prev->context.active < 1);
		prev->context.active--;
	}

 again:
#endif /* CONFIG_SMP */

	/* If we already have a valid assigned context, skip all that */
	id = next->context.id;
	if (likely(id != MMU_NO_CONTEXT)) {
#ifdef DEBUG_MAP_CONSISTENCY
		if (context_mm[id] != next)
			pr_err("MMU: mm 0x%p has id %d but context_mm[%d] says 0x%p\n",
			       next, id, id, context_mm[id]);
#endif
		goto ctxt_ok;
	}

	/* We really don't have a context, let's try to acquire one */
	id = next_context;
	if (id > LAST_CONTEXT)
		id = FIRST_CONTEXT;
	map = context_map;

	/* No more free contexts, let's try to steal one */
	if (nr_free_contexts == 0) {
#ifdef CONFIG_SMP
		if (num_online_cpus() > 1) {
			id = steal_context_smp(id);
			if (id == MMU_NO_CONTEXT)
				goto again;
			goto stolen;
		}
#endif /* CONFIG_SMP */
		if (IS_ENABLED(CONFIG_PPC_8xx))
			id = steal_all_contexts();
		else
			id = steal_context_up(id);
		goto stolen;
	}
	nr_free_contexts--;

	/* We know there's at least one free context, try to find it */
	while (__test_and_set_bit(id, map)) {
		id = find_next_zero_bit(map, LAST_CONTEXT+1, id);
		if (id > LAST_CONTEXT)
			id = FIRST_CONTEXT;
	}
 stolen:
	next_context = id + 1;
	context_mm[id] = next;
	next->context.id = id;
	pr_hardcont(" | new id=%d,nrf=%d", id, nr_free_contexts);

	context_check_map();
 ctxt_ok:

	/* If that context got marked stale on this CPU, then flush the
	 * local TLB for it and unmark it before we use it
	 */
#ifdef CONFIG_SMP
	if (test_bit(id, stale_map[cpu])) {
		pr_hardcont(" | stale flush %d [%d..%d]",
			    id, cpu_first_thread_sibling(cpu),
			    cpu_last_thread_sibling(cpu));

		local_flush_tlb_mm(next);

		/* XXX This clear should ultimately be part of local_flush_tlb_mm */
		for (i = cpu_first_thread_sibling(cpu);
		     i <= cpu_last_thread_sibling(cpu); i++) {
			if (stale_map[i])
				__clear_bit(id, stale_map[i]);
		}
	}
#endif

	/* Flick the MMU and release lock */
	pr_hardcont(" -> %d\n", id);
	set_context(id, next->pgd);
	raw_spin_unlock(&context_lock);
}

int init_new_context(struct task_struct *t, struct mm_struct *mm)
{
	pr_hard("initing context for mm @%p\n", mm);

#ifdef	CONFIG_PPC_MM_SLICES
	/*
	 * We have MMU_NO_CONTEXT set to be ~0. Hence check
	 * explicitly against context.id == 0. This ensures that we properly
	 * initialize context slice details for newly allocated mm's (which will
	 * have id == 0) and don't alter context slice inherited via fork (which
	 * will have id != 0).
	 */
	if (mm->context.id == 0)
		slice_init_new_context_exec(mm);
#endif
	mm->context.id = MMU_NO_CONTEXT;
	mm->context.active = 0;
	return 0;
}

void destroy_context(struct mm_struct *mm)
{
	unsigned long flags;
	unsigned int id;

	if (mm->context.id == MMU_NO_CONTEXT)
		return;

	WARN_ON(mm->context.active != 0);

	raw_spin_lock_irqsave(&context_lock, flags);
	id = mm->context.id;
	if (id != MMU_NO_CONTEXT) {
		__clear_bit(id, context_map);
		mm->context.id = MMU_NO_CONTEXT;
#ifdef DEBUG_MAP_CONSISTENCY
		mm->context.active = 0;
#endif
		context_mm[id] = NULL;
		nr_free_contexts++;
	}
	raw_spin_unlock_irqrestore(&context_lock, flags);
}

