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
struct seq_file {int dummy; } ;
struct fscache_object {int /*<<< orphan*/  event_mask; int /*<<< orphan*/  events; } ;
struct fscache_cookie {int aux_len; int /*<<< orphan*/  flags; void* aux; void* inline_aux; int /*<<< orphan*/  netfs_data; TYPE_1__* def; int /*<<< orphan*/  usage; } ;
typedef  int loff_t ;
typedef  enum fscache_cookie_trace { ____Placeholder_fscache_cookie_trace } fscache_cookie_trace ;
struct TYPE_2__ {int /*<<< orphan*/  (* put_context ) (int /*<<< orphan*/ ,void*) ;int /*<<< orphan*/  (* get_context ) (int /*<<< orphan*/ ,void*) ;} ;

/* Variables and functions */
 int /*<<< orphan*/  BUG_ON (int) ; 
 int /*<<< orphan*/  FSCACHE_COOKIE_AUX_UPDATED ; 
 unsigned long HZ ; 
 unsigned int NR_FSCACHE_OBJECT_EVENTS ; 
 int /*<<< orphan*/  WORK_CPU_UNBOUND ; 
 int atomic_inc_return (int /*<<< orphan*/ *) ; 
 unsigned int atomic_read (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  fscache_enqueue_object (struct fscache_object*) ; 
 int /*<<< orphan*/ * fscache_obj_instantiate_histogram ; 
 int /*<<< orphan*/  fscache_object_wq ; 
 int /*<<< orphan*/ * fscache_objs_histogram ; 
 int /*<<< orphan*/ * fscache_ops_histogram ; 
 int /*<<< orphan*/ * fscache_retrieval_delay_histogram ; 
 int /*<<< orphan*/ * fscache_retrieval_histogram ; 
 scalar_t__ memcmp (void*,void const*,int) ; 
 int /*<<< orphan*/  memcpy (void*,void const*,int) ; 
 int /*<<< orphan*/  seq_printf (struct seq_file*,char*,unsigned long,unsigned int,unsigned int,unsigned int,unsigned int,unsigned int,unsigned int) ; 
 int /*<<< orphan*/  seq_puts (struct seq_file*,char*) ; 
 int /*<<< orphan*/  set_bit (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  stub1 (int /*<<< orphan*/ ,void*) ; 
 int /*<<< orphan*/  stub2 (int /*<<< orphan*/ ,void*) ; 
 int /*<<< orphan*/  test_and_set_bit (unsigned int,int /*<<< orphan*/ *) ; 
 scalar_t__ test_bit (unsigned int,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  trace_fscache_cookie (struct fscache_cookie*,int,int) ; 
 int workqueue_congested (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

__attribute__((used)) static inline bool fscache_object_congested(void)
{
	return workqueue_congested(WORK_CPU_UNBOUND, fscache_object_wq);
}

__attribute__((used)) static inline void fscache_raise_event(struct fscache_object *object,
				       unsigned event)
{
	BUG_ON(event >= NR_FSCACHE_OBJECT_EVENTS);
#if 0
	printk("*** fscache_raise_event(OBJ%d{%lx},%x)\n",
	       object->debug_id, object->event_mask, (1 << event));
#endif
	if (!test_and_set_bit(event, &object->events) &&
	    test_bit(event, &object->event_mask))
		fscache_enqueue_object(object);
}

__attribute__((used)) static inline void fscache_cookie_get(struct fscache_cookie *cookie,
				      enum fscache_cookie_trace where)
{
	int usage = atomic_inc_return(&cookie->usage);

	trace_fscache_cookie(cookie, where, usage);
}

__attribute__((used)) static inline
void *fscache_get_context(struct fscache_cookie *cookie, void *context)
{
	if (cookie->def->get_context)
		cookie->def->get_context(cookie->netfs_data, context);
	return context;
}

__attribute__((used)) static inline
void fscache_put_context(struct fscache_cookie *cookie, void *context)
{
	if (cookie->def->put_context)
		cookie->def->put_context(cookie->netfs_data, context);
}

__attribute__((used)) static inline
void fscache_update_aux(struct fscache_cookie *cookie, const void *aux_data)
{
	void *p;

	if (!aux_data)
		return;
	if (cookie->aux_len <= sizeof(cookie->inline_aux))
		p = cookie->inline_aux;
	else
		p = cookie->aux;

	if (memcmp(p, aux_data, cookie->aux_len) != 0) {
		memcpy(p, aux_data, cookie->aux_len);
		set_bit(FSCACHE_COOKIE_AUX_UPDATED, &cookie->flags);
	}
}

__attribute__((used)) static int fscache_histogram_show(struct seq_file *m, void *v)
{
	unsigned long index;
	unsigned n[5], t;

	switch ((unsigned long) v) {
	case 1:
		seq_puts(m, "JIFS  SECS  OBJ INST  OP RUNS   OBJ RUNS  RETRV DLY RETRIEVLS\n");
		return 0;
	case 2:
		seq_puts(m, "===== ===== ========= ========= ========= ========= =========\n");
		return 0;
	default:
		index = (unsigned long) v - 3;
		n[0] = atomic_read(&fscache_obj_instantiate_histogram[index]);
		n[1] = atomic_read(&fscache_ops_histogram[index]);
		n[2] = atomic_read(&fscache_objs_histogram[index]);
		n[3] = atomic_read(&fscache_retrieval_delay_histogram[index]);
		n[4] = atomic_read(&fscache_retrieval_histogram[index]);
		if (!(n[0] | n[1] | n[2] | n[3] | n[4]))
			return 0;

		t = (index * 1000) / HZ;

		seq_printf(m, "%4lu  0.%03u %9u %9u %9u %9u %9u\n",
			   index, t, n[0], n[1], n[2], n[3], n[4]);
		return 0;
	}
}

__attribute__((used)) static void *fscache_histogram_start(struct seq_file *m, loff_t *_pos)
{
	if ((unsigned long long)*_pos >= HZ + 2)
		return NULL;
	if (*_pos == 0)
		*_pos = 1;
	return (void *)(unsigned long) *_pos;
}

__attribute__((used)) static void *fscache_histogram_next(struct seq_file *m, void *v, loff_t *pos)
{
	(*pos)++;
	return (unsigned long long)*pos > HZ + 2 ?
		NULL : (void *)(unsigned long) *pos;
}

__attribute__((used)) static void fscache_histogram_stop(struct seq_file *m, void *v)
{
}

