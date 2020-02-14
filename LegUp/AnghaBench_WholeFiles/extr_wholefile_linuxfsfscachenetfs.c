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
struct fscache_netfs {int /*<<< orphan*/  name; struct fscache_cookie* primary_index; int /*<<< orphan*/  version; } ;
struct fscache_cookie {int aux_len; int flags; int /*<<< orphan*/  n_children; struct fscache_cookie* parent; void* aux; void* inline_aux; int /*<<< orphan*/  netfs_data; TYPE_1__* def; int /*<<< orphan*/  usage; } ;
typedef  enum fscache_cookie_trace { ____Placeholder_fscache_cookie_trace } fscache_cookie_trace ;
struct TYPE_2__ {int /*<<< orphan*/  (* put_context ) (int /*<<< orphan*/ ,void*) ;int /*<<< orphan*/  (* get_context ) (int /*<<< orphan*/ ,void*) ;} ;

/* Variables and functions */
 int /*<<< orphan*/  BUG_ON (int) ; 
 int EEXIST ; 
 int ENOMEM ; 
 int /*<<< orphan*/  FSCACHE_COOKIE_AUX_UPDATED ; 
 int FSCACHE_COOKIE_ENABLED ; 
 unsigned int NR_FSCACHE_OBJECT_EVENTS ; 
 int /*<<< orphan*/  WORK_CPU_UNBOUND ; 
 int /*<<< orphan*/  _enter (char*,int /*<<< orphan*/ ,...) ; 
 int /*<<< orphan*/  _leave (char*) ; 
 int /*<<< orphan*/  atomic_inc (int /*<<< orphan*/ *) ; 
 int atomic_inc_return (int /*<<< orphan*/ *) ; 
 struct fscache_cookie* fscache_alloc_cookie (int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ *,int,struct fscache_netfs*,int /*<<< orphan*/ ) ; 
 int fscache_cookie_discard ; 
 int fscache_cookie_get_register_netfs ; 
 int /*<<< orphan*/  fscache_cookie_put (struct fscache_cookie*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  fscache_cookie_put_dup_netfs ; 
 int /*<<< orphan*/  fscache_enqueue_object (struct fscache_object*) ; 
 int /*<<< orphan*/  fscache_free_cookie (struct fscache_cookie*) ; 
 int /*<<< orphan*/  fscache_fsdef_index ; 
 int /*<<< orphan*/  fscache_fsdef_netfs_def ; 
 struct fscache_cookie* fscache_hash_cookie (struct fscache_cookie*) ; 
 int /*<<< orphan*/  fscache_object_wq ; 
 int /*<<< orphan*/  fscache_relinquish_cookie (struct fscache_cookie*,int /*<<< orphan*/ *,int) ; 
 scalar_t__ memcmp (void*,void const*,int) ; 
 int /*<<< orphan*/  memcpy (void*,void const*,int) ; 
 int /*<<< orphan*/  pr_notice (char*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  set_bit (int /*<<< orphan*/ ,int*) ; 
 int /*<<< orphan*/  strlen (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  stub1 (int /*<<< orphan*/ ,void*) ; 
 int /*<<< orphan*/  stub2 (int /*<<< orphan*/ ,void*) ; 
 int /*<<< orphan*/  test_and_set_bit (unsigned int,int /*<<< orphan*/ *) ; 
 scalar_t__ test_bit (unsigned int,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  trace_fscache_cookie (struct fscache_cookie*,int,int) ; 
 int /*<<< orphan*/  trace_fscache_netfs (struct fscache_netfs*) ; 
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

int __fscache_register_netfs(struct fscache_netfs *netfs)
{
	struct fscache_cookie *candidate, *cookie;

	_enter("{%s}", netfs->name);

	/* allocate a cookie for the primary index */
	candidate = fscache_alloc_cookie(&fscache_fsdef_index,
					 &fscache_fsdef_netfs_def,
					 netfs->name, strlen(netfs->name),
					 &netfs->version, sizeof(netfs->version),
					 netfs, 0);
	if (!candidate) {
		_leave(" = -ENOMEM");
		return -ENOMEM;
	}

	candidate->flags = 1 << FSCACHE_COOKIE_ENABLED;

	/* check the netfs type is not already present */
	cookie = fscache_hash_cookie(candidate);
	if (!cookie)
		goto already_registered;
	if (cookie != candidate) {
		trace_fscache_cookie(candidate, fscache_cookie_discard, 1);
		fscache_free_cookie(candidate);
	}

	fscache_cookie_get(cookie->parent, fscache_cookie_get_register_netfs);
	atomic_inc(&cookie->parent->n_children);

	netfs->primary_index = cookie;

	pr_notice("Netfs '%s' registered for caching\n", netfs->name);
	trace_fscache_netfs(netfs);
	_leave(" = 0");
	return 0;

already_registered:
	fscache_cookie_put(candidate, fscache_cookie_put_dup_netfs);
	_leave(" = -EEXIST");
	return -EEXIST;
}

void __fscache_unregister_netfs(struct fscache_netfs *netfs)
{
	_enter("{%s.%u}", netfs->name, netfs->version);

	fscache_relinquish_cookie(netfs->primary_index, NULL, false);
	pr_notice("Netfs '%s' unregistered from caching\n", netfs->name);

	_leave("");
}

