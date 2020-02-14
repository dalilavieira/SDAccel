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
typedef  int u8 ;
typedef  scalar_t__ u64 ;
struct timer_list {int dummy; } ;
struct seq_file {int dummy; } ;
struct inode {int dummy; } ;
struct file {int dummy; } ;
struct ce_array {int n; int* array; unsigned long decays_done; unsigned long flags; int /*<<< orphan*/  pfns_poisoned; int /*<<< orphan*/  ces_entered; scalar_t__ decay_count; } ;

/* Variables and functions */
 scalar_t__ CEC_TIMER_MAX_INTERVAL ; 
 scalar_t__ CEC_TIMER_MIN_INTERVAL ; 
 int COUNT_BITS ; 
 scalar_t__ COUNT_MASK ; 
 int DECAY (int) ; 
 int DECAY_MASK ; 
 int EINVAL ; 
 int ENOKEY ; 
 unsigned int FULL_COUNT (int) ; 
 unsigned int FULL_COUNT_MASK ; 
 unsigned long HZ ; 
 scalar_t__ PFN (int) ; 
 int /*<<< orphan*/  WARN_ON (int) ; 
 struct ce_array ce_arr ; 
 int /*<<< orphan*/  ce_mutex ; 
 struct timer_list cec_timer ; 
 unsigned long count_threshold ; 
 unsigned long jiffies ; 
 int /*<<< orphan*/  memmove (void*,void*,int) ; 
 int /*<<< orphan*/  mod_timer (struct timer_list*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  round_jiffies (unsigned long) ; 
 int /*<<< orphan*/  seq_printf (struct seq_file*,char*,...) ; 
 int single_open (struct file*,int (*) (struct seq_file*,void*),int /*<<< orphan*/ *) ; 
 unsigned long timer_interval ; 

__attribute__((used)) static void do_spring_cleaning(struct ce_array *ca)
{
	int i;

	for (i = 0; i < ca->n; i++) {
		u8 decay = DECAY(ca->array[i]);

		if (!decay)
			continue;

		decay--;

		ca->array[i] &= ~(DECAY_MASK << COUNT_BITS);
		ca->array[i] |= (decay << COUNT_BITS);
	}
	ca->decay_count = 0;
	ca->decays_done++;
}

__attribute__((used)) static void cec_mod_timer(struct timer_list *t, unsigned long interval)
{
	unsigned long iv;

	iv = interval * HZ + jiffies;

	mod_timer(t, round_jiffies(iv));
}

__attribute__((used)) static void cec_timer_fn(struct timer_list *unused)
{
	do_spring_cleaning(&ce_arr);

	cec_mod_timer(&cec_timer, timer_interval);
}

__attribute__((used)) static int __find_elem(struct ce_array *ca, u64 pfn, unsigned int *to)
{
	u64 this_pfn;
	int min = 0, max = ca->n;

	while (min < max) {
		int tmp = (max + min) >> 1;

		this_pfn = PFN(ca->array[tmp]);

		if (this_pfn < pfn)
			min = tmp + 1;
		else if (this_pfn > pfn)
			max = tmp;
		else {
			min = tmp;
			break;
		}
	}

	if (to)
		*to = min;

	this_pfn = PFN(ca->array[min]);

	if (this_pfn == pfn)
		return min;

	return -ENOKEY;
}

__attribute__((used)) static int find_elem(struct ce_array *ca, u64 pfn, unsigned int *to)
{
	WARN_ON(!to);

	if (!ca->n) {
		*to = 0;
		return -ENOKEY;
	}
	return __find_elem(ca, pfn, to);
}

__attribute__((used)) static void del_elem(struct ce_array *ca, int idx)
{
	/* Save us a function call when deleting the last element. */
	if (ca->n - (idx + 1))
		memmove((void *)&ca->array[idx],
			(void *)&ca->array[idx + 1],
			(ca->n - (idx + 1)) * sizeof(u64));

	ca->n--;
}

__attribute__((used)) static u64 del_lru_elem_unlocked(struct ce_array *ca)
{
	unsigned int min = FULL_COUNT_MASK;
	int i, min_idx = 0;

	for (i = 0; i < ca->n; i++) {
		unsigned int this = FULL_COUNT(ca->array[i]);

		if (min > this) {
			min = this;
			min_idx = i;
		}
	}

	del_elem(ca, min_idx);

	return PFN(ca->array[min_idx]);
}

__attribute__((used)) static int decay_interval_set(void *data, u64 val)
{
	*(u64 *)data = val;

	if (val < CEC_TIMER_MIN_INTERVAL)
		return -EINVAL;

	if (val > CEC_TIMER_MAX_INTERVAL)
		return -EINVAL;

	timer_interval = val;

	cec_mod_timer(&cec_timer, timer_interval);
	return 0;
}

__attribute__((used)) static int count_threshold_set(void *data, u64 val)
{
	*(u64 *)data = val;

	if (val > COUNT_MASK)
		val = COUNT_MASK;

	count_threshold = val;

	return 0;
}

__attribute__((used)) static int array_dump(struct seq_file *m, void *v)
{
	struct ce_array *ca = &ce_arr;
	u64 prev = 0;
	int i;

	mutex_lock(&ce_mutex);

	seq_printf(m, "{ n: %d\n", ca->n);
	for (i = 0; i < ca->n; i++) {
		u64 this = PFN(ca->array[i]);

		seq_printf(m, " %03d: [%016llx|%03llx]\n", i, this, FULL_COUNT(ca->array[i]));

		WARN_ON(prev > this);

		prev = this;
	}

	seq_printf(m, "}\n");

	seq_printf(m, "Stats:\nCEs: %llu\nofflined pages: %llu\n",
		   ca->ces_entered, ca->pfns_poisoned);

	seq_printf(m, "Flags: 0x%x\n", ca->flags);

	seq_printf(m, "Timer interval: %lld seconds\n", timer_interval);
	seq_printf(m, "Decays: %lld\n", ca->decays_done);

	seq_printf(m, "Action threshold: %d\n", count_threshold);

	mutex_unlock(&ce_mutex);

	return 0;
}

__attribute__((used)) static int array_open(struct inode *inode, struct file *filp)
{
	return single_open(filp, array_dump, NULL);
}

