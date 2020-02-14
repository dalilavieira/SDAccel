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
struct fscache_object {int /*<<< orphan*/  event_mask; int /*<<< orphan*/  events; } ;
struct fscache_cookie {int aux_len; int /*<<< orphan*/  flags; void* aux; void* inline_aux; int /*<<< orphan*/  netfs_data; TYPE_1__* def; int /*<<< orphan*/  usage; } ;
typedef  enum fscache_cookie_trace { ____Placeholder_fscache_cookie_trace } fscache_cookie_trace ;
struct TYPE_2__ {int /*<<< orphan*/  (* put_context ) (int /*<<< orphan*/ ,void*) ;int /*<<< orphan*/  (* get_context ) (int /*<<< orphan*/ ,void*) ;} ;

/* Variables and functions */
 int /*<<< orphan*/  BUG_ON (int) ; 
 int /*<<< orphan*/  FSCACHE_COOKIE_AUX_UPDATED ; 
 unsigned int NR_FSCACHE_OBJECT_EVENTS ; 
 int /*<<< orphan*/  WORK_CPU_UNBOUND ; 
 int atomic_inc_return (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  fscache_enqueue_object (struct fscache_object*) ; 
 int /*<<< orphan*/  fscache_object_wq ; 
 scalar_t__ memcmp (void*,void const*,int) ; 
 int /*<<< orphan*/  memcpy (void*,void const*,int) ; 
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

