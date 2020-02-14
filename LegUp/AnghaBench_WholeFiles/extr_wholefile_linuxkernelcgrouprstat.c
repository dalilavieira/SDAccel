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
struct css_set {int /*<<< orphan*/  refcount; } ;
struct cgroup_rstat_cpu {struct cgroup* updated_next; struct cgroup* updated_children; } ;
struct TYPE_2__ {int flags; } ;
struct cgroup {int /*<<< orphan*/ * rstat_cpu; int /*<<< orphan*/  flags; TYPE_1__ self; } ;
typedef  struct cgroup_rstat_cpu raw_spinlock_t ;

/* Variables and functions */
 int /*<<< orphan*/  CGRP_NOTIFY_ON_RELEASE ; 
 int CSS_ONLINE ; 
 int /*<<< orphan*/  WARN_ON_ONCE (int) ; 
 struct cgroup* cgroup_parent (struct cgroup*) ; 
 int /*<<< orphan*/  cgroup_rstat_cpu_lock ; 
 int /*<<< orphan*/  css_set_lock ; 
 struct cgroup_rstat_cpu* per_cpu_ptr (int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  put_css_set_locked (struct css_set*) ; 
 int /*<<< orphan*/  raw_spin_lock_irqsave (struct cgroup_rstat_cpu*,unsigned long) ; 
 int /*<<< orphan*/  raw_spin_unlock_irqrestore (struct cgroup_rstat_cpu*,unsigned long) ; 
 scalar_t__ refcount_dec_not_one (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  refcount_inc (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  smp_mb () ; 
 int /*<<< orphan*/  spin_lock_irqsave (int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  spin_unlock_irqrestore (int /*<<< orphan*/ *,unsigned long) ; 
 int test_bit (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 

__attribute__((used)) static inline bool cgroup_is_dead(const struct cgroup *cgrp)
{
	return !(cgrp->self.flags & CSS_ONLINE);
}

__attribute__((used)) static inline bool notify_on_release(const struct cgroup *cgrp)
{
	return test_bit(CGRP_NOTIFY_ON_RELEASE, &cgrp->flags);
}

__attribute__((used)) static inline void put_css_set(struct css_set *cset)
{
	unsigned long flags;

	/*
	 * Ensure that the refcount doesn't hit zero while any readers
	 * can see it. Similar to atomic_dec_and_lock(), but for an
	 * rwlock
	 */
	if (refcount_dec_not_one(&cset->refcount))
		return;

	spin_lock_irqsave(&css_set_lock, flags);
	put_css_set_locked(cset);
	spin_unlock_irqrestore(&css_set_lock, flags);
}

__attribute__((used)) static inline void get_css_set(struct css_set *cset)
{
	refcount_inc(&cset->refcount);
}

__attribute__((used)) static struct cgroup_rstat_cpu *cgroup_rstat_cpu(struct cgroup *cgrp, int cpu)
{
	return per_cpu_ptr(cgrp->rstat_cpu, cpu);
}

void cgroup_rstat_updated(struct cgroup *cgrp, int cpu)
{
	raw_spinlock_t *cpu_lock = per_cpu_ptr(&cgroup_rstat_cpu_lock, cpu);
	struct cgroup *parent;
	unsigned long flags;

	/* nothing to do for root */
	if (!cgroup_parent(cgrp))
		return;

	/*
	 * Paired with the one in cgroup_rstat_cpu_pop_upated().  Either we
	 * see NULL updated_next or they see our updated stat.
	 */
	smp_mb();

	/*
	 * Because @parent's updated_children is terminated with @parent
	 * instead of NULL, we can tell whether @cgrp is on the list by
	 * testing the next pointer for NULL.
	 */
	if (cgroup_rstat_cpu(cgrp, cpu)->updated_next)
		return;

	raw_spin_lock_irqsave(cpu_lock, flags);

	/* put @cgrp and all ancestors on the corresponding updated lists */
	for (parent = cgroup_parent(cgrp); parent;
	     cgrp = parent, parent = cgroup_parent(cgrp)) {
		struct cgroup_rstat_cpu *rstatc = cgroup_rstat_cpu(cgrp, cpu);
		struct cgroup_rstat_cpu *prstatc = cgroup_rstat_cpu(parent, cpu);

		/*
		 * Both additions and removals are bottom-up.  If a cgroup
		 * is already in the tree, all ancestors are.
		 */
		if (rstatc->updated_next)
			break;

		rstatc->updated_next = prstatc->updated_children;
		prstatc->updated_children = cgrp;
	}

	raw_spin_unlock_irqrestore(cpu_lock, flags);
}

__attribute__((used)) static struct cgroup *cgroup_rstat_cpu_pop_updated(struct cgroup *pos,
						   struct cgroup *root, int cpu)
{
	struct cgroup_rstat_cpu *rstatc;

	if (pos == root)
		return NULL;

	/*
	 * We're gonna walk down to the first leaf and visit/remove it.  We
	 * can pick whatever unvisited node as the starting point.
	 */
	if (!pos)
		pos = root;
	else
		pos = cgroup_parent(pos);

	/* walk down to the first leaf */
	while (true) {
		rstatc = cgroup_rstat_cpu(pos, cpu);
		if (rstatc->updated_children == pos)
			break;
		pos = rstatc->updated_children;
	}

	/*
	 * Unlink @pos from the tree.  As the updated_children list is
	 * singly linked, we have to walk it to find the removal point.
	 * However, due to the way we traverse, @pos will be the first
	 * child in most cases. The only exception is @root.
	 */
	if (rstatc->updated_next) {
		struct cgroup *parent = cgroup_parent(pos);
		struct cgroup_rstat_cpu *prstatc = cgroup_rstat_cpu(parent, cpu);
		struct cgroup_rstat_cpu *nrstatc;
		struct cgroup **nextp;

		nextp = &prstatc->updated_children;
		while (true) {
			nrstatc = cgroup_rstat_cpu(*nextp, cpu);
			if (*nextp == pos)
				break;

			WARN_ON_ONCE(*nextp == parent);
			nextp = &nrstatc->updated_next;
		}

		*nextp = rstatc->updated_next;
		rstatc->updated_next = NULL;

		/*
		 * Paired with the one in cgroup_rstat_cpu_updated().
		 * Either they see NULL updated_next or we see their
		 * updated stat.
		 */
		smp_mb();

		return pos;
	}

	/* only happens for @root */
	return NULL;
}

