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
typedef  int /*<<< orphan*/  u64 ;
struct multicall_space {int /*<<< orphan*/ * args; struct multicall_entry* mc; int /*<<< orphan*/ * member_1; int /*<<< orphan*/ * member_0; } ;
struct multicall_entry {unsigned long op; int /*<<< orphan*/  result; int /*<<< orphan*/ * args; } ;
struct mc_buffer {int mcidx; scalar_t__ argidx; int cbidx; struct callback* callbacks; int /*<<< orphan*/ * args; struct multicall_entry* entries; } ;
struct callback {void (* fn ) (void*) ;void* data; } ;

/* Variables and functions */
 int /*<<< orphan*/  BUG () ; 
 int /*<<< orphan*/  BUG_ON (int) ; 
 int /*<<< orphan*/  HYPERVISOR_multicall (struct multicall_entry*,int) ; 
 unsigned int MC_ARGS ; 
 scalar_t__ MC_BATCH ; 
 int /*<<< orphan*/  WARN_ON (int) ; 
 int /*<<< orphan*/  XEN_MC_FL_ARGS ; 
 int /*<<< orphan*/  XEN_MC_FL_BATCH ; 
 int /*<<< orphan*/  XEN_MC_FL_CALLBACK ; 
 int /*<<< orphan*/  XEN_MC_XE_BAD_OP ; 
 int /*<<< orphan*/  XEN_MC_XE_NO_SPACE ; 
 int /*<<< orphan*/  XEN_MC_XE_OK ; 
 int /*<<< orphan*/  __this_cpu_write (int /*<<< orphan*/ ,unsigned long) ; 
 struct multicall_space __xen_mc_entry (size_t) ; 
 int /*<<< orphan*/  local_irq_restore (unsigned long) ; 
 int /*<<< orphan*/  local_irq_save (unsigned long) ; 
 int /*<<< orphan*/  mc_buffer ; 
 unsigned int paravirt_get_lazy_mode () ; 
 int preemptible () ; 
 unsigned int roundup (scalar_t__,int) ; 
 void stub1 (void*) ; 
 struct mc_buffer* this_cpu_ptr (int /*<<< orphan*/ *) ; 
 unsigned long this_cpu_read (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  trace_xen_mc_batch (unsigned int) ; 
 int /*<<< orphan*/  trace_xen_mc_callback (void (*) (void*),void*) ; 
 int /*<<< orphan*/  trace_xen_mc_entry_alloc (size_t) ; 
 int /*<<< orphan*/  trace_xen_mc_extend_args (unsigned long,size_t,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  trace_xen_mc_flush (int,scalar_t__,int) ; 
 int /*<<< orphan*/  trace_xen_mc_flush_reason (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  trace_xen_mc_issue (unsigned int) ; 
 scalar_t__ unlikely (int) ; 
 void xen_mc_flush () ; 
 int /*<<< orphan*/  xen_mc_irq_flags ; 
 int /*<<< orphan*/  xen_single_call (unsigned long,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

__attribute__((used)) static inline void xen_smp_init(void) {}

__attribute__((used)) static inline void xen_hvm_smp_init(void) {}

__attribute__((used)) static inline void xen_init_spinlocks(void)
{
}

__attribute__((used)) static inline void xen_init_lock_cpu(int cpu)
{
}

__attribute__((used)) static inline void xen_uninit_lock_cpu(int cpu)
{
}

__attribute__((used)) static inline void xen_pv_pre_suspend(void) {}

__attribute__((used)) static inline void xen_pv_post_suspend(int suspend_cancelled) {}

__attribute__((used)) static inline void xen_hvm_post_suspend(int suspend_cancelled) {}

__attribute__((used)) static inline void xen_mc_batch(void)
{
	unsigned long flags;

	/* need to disable interrupts until this entry is complete */
	local_irq_save(flags);
	trace_xen_mc_batch(paravirt_get_lazy_mode());
	__this_cpu_write(xen_mc_irq_flags, flags);
}

__attribute__((used)) static inline struct multicall_space xen_mc_entry(size_t args)
{
	xen_mc_batch();
	return __xen_mc_entry(args);
}

__attribute__((used)) static inline void xen_mc_issue(unsigned mode)
{
	trace_xen_mc_issue(mode);

	if ((paravirt_get_lazy_mode() & mode) == 0)
		xen_mc_flush();

	/* restore flags saved in xen_mc_batch */
	local_irq_restore(this_cpu_read(xen_mc_irq_flags));
}

void xen_mc_flush(void)
{
	struct mc_buffer *b = this_cpu_ptr(&mc_buffer);
	struct multicall_entry *mc;
	int ret = 0;
	unsigned long flags;
	int i;

	BUG_ON(preemptible());

	/* Disable interrupts in case someone comes in and queues
	   something in the middle */
	local_irq_save(flags);

	trace_xen_mc_flush(b->mcidx, b->argidx, b->cbidx);

	switch (b->mcidx) {
	case 0:
		/* no-op */
		BUG_ON(b->argidx != 0);
		break;

	case 1:
		/* Singleton multicall - bypass multicall machinery
		   and just do the call directly. */
		mc = &b->entries[0];

		mc->result = xen_single_call(mc->op, mc->args[0], mc->args[1],
					     mc->args[2], mc->args[3],
					     mc->args[4]);
		ret = mc->result < 0;
		break;

	default:
#if MC_DEBUG
		memcpy(b->debug, b->entries,
		       b->mcidx * sizeof(struct multicall_entry));
#endif

		if (HYPERVISOR_multicall(b->entries, b->mcidx) != 0)
			BUG();
		for (i = 0; i < b->mcidx; i++)
			if (b->entries[i].result < 0)
				ret++;

#if MC_DEBUG
		if (ret) {
			printk(KERN_ERR "%d multicall(s) failed: cpu %d\n",
			       ret, smp_processor_id());
			dump_stack();
			for (i = 0; i < b->mcidx; i++) {
				printk(KERN_DEBUG "  call %2d/%d: op=%lu arg=[%lx] result=%ld\t%pF\n",
				       i+1, b->mcidx,
				       b->debug[i].op,
				       b->debug[i].args[0],
				       b->entries[i].result,
				       b->caller[i]);
			}
		}
#endif
	}

	b->mcidx = 0;
	b->argidx = 0;

	for (i = 0; i < b->cbidx; i++) {
		struct callback *cb = &b->callbacks[i];

		(*cb->fn)(cb->data);
	}
	b->cbidx = 0;

	local_irq_restore(flags);

	WARN_ON(ret);
}

struct multicall_space __xen_mc_entry(size_t args)
{
	struct mc_buffer *b = this_cpu_ptr(&mc_buffer);
	struct multicall_space ret;
	unsigned argidx = roundup(b->argidx, sizeof(u64));

	trace_xen_mc_entry_alloc(args);

	BUG_ON(preemptible());
	BUG_ON(b->argidx >= MC_ARGS);

	if (unlikely(b->mcidx == MC_BATCH ||
		     (argidx + args) >= MC_ARGS)) {
		trace_xen_mc_flush_reason((b->mcidx == MC_BATCH) ?
					  XEN_MC_FL_BATCH : XEN_MC_FL_ARGS);
		xen_mc_flush();
		argidx = roundup(b->argidx, sizeof(u64));
	}

	ret.mc = &b->entries[b->mcidx];
#if MC_DEBUG
	b->caller[b->mcidx] = __builtin_return_address(0);
#endif
	b->mcidx++;
	ret.args = &b->args[argidx];
	b->argidx = argidx + args;

	BUG_ON(b->argidx >= MC_ARGS);
	return ret;
}

struct multicall_space xen_mc_extend_args(unsigned long op, size_t size)
{
	struct mc_buffer *b = this_cpu_ptr(&mc_buffer);
	struct multicall_space ret = { NULL, NULL };

	BUG_ON(preemptible());
	BUG_ON(b->argidx >= MC_ARGS);

	if (unlikely(b->mcidx == 0 ||
		     b->entries[b->mcidx - 1].op != op)) {
		trace_xen_mc_extend_args(op, size, XEN_MC_XE_BAD_OP);
		goto out;
	}

	if (unlikely((b->argidx + size) >= MC_ARGS)) {
		trace_xen_mc_extend_args(op, size, XEN_MC_XE_NO_SPACE);
		goto out;
	}

	ret.mc = &b->entries[b->mcidx - 1];
	ret.args = &b->args[b->argidx];
	b->argidx += size;

	BUG_ON(b->argidx >= MC_ARGS);

	trace_xen_mc_extend_args(op, size, XEN_MC_XE_OK);
out:
	return ret;
}

void xen_mc_callback(void (*fn)(void *), void *data)
{
	struct mc_buffer *b = this_cpu_ptr(&mc_buffer);
	struct callback *cb;

	if (b->cbidx == MC_BATCH) {
		trace_xen_mc_flush_reason(XEN_MC_FL_CALLBACK);
		xen_mc_flush();
	}

	trace_xen_mc_callback(fn, data);

	cb = &b->callbacks[b->cbidx++];
	cb->fn = fn;
	cb->data = data;
}

