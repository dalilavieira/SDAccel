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
typedef  int u32 ;
struct vmci_subscription {int /*<<< orphan*/  node; } ;
struct vmci_qp_page_store {int len; } ;
struct vmci_handle_arr {size_t size; } ;
struct vmci_ctx {int cid; } ;

/* Variables and functions */
 int VMCI_ERROR_NOT_FOUND ; 
 int VMCI_INVALID_ID ; 
 int VMCI_PRIVILEGE_FLAG_RESTRICTED ; 
 int VMCI_PRIVILEGE_FLAG_TRUSTED ; 
 int VMCI_SUCCESS ; 
 struct vmci_subscription* event_find (int) ; 
 int /*<<< orphan*/  kfree (struct vmci_subscription*) ; 
 int /*<<< orphan*/  list_del_rcu (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  subscriber_mutex ; 
 int /*<<< orphan*/  synchronize_rcu () ; 

__attribute__((used)) static inline size_t vmci_handle_arr_get_size(
	const struct vmci_handle_arr *array)
{
	return array->size;
}

__attribute__((used)) static inline bool vmci_deny_interaction(u32 part_one, u32 part_two)
{
	return ((part_one & VMCI_PRIVILEGE_FLAG_RESTRICTED) &&
		!(part_two & VMCI_PRIVILEGE_FLAG_TRUSTED)) ||
	       ((part_two & VMCI_PRIVILEGE_FLAG_RESTRICTED) &&
		!(part_one & VMCI_PRIVILEGE_FLAG_TRUSTED));
}

__attribute__((used)) static inline u32 vmci_ctx_get_id(struct vmci_ctx *context)
{
	if (!context)
		return VMCI_INVALID_ID;
	return context->cid;
}

__attribute__((used)) static inline bool
VMCI_QP_PAGESTORE_IS_WELLFORMED(struct vmci_qp_page_store *page_store)
{
	return page_store->len >= 2;
}

int vmci_event_unsubscribe(u32 sub_id)
{
	struct vmci_subscription *s;

	mutex_lock(&subscriber_mutex);
	s = event_find(sub_id);
	if (s)
		list_del_rcu(&s->node);
	mutex_unlock(&subscriber_mutex);

	if (!s)
		return VMCI_ERROR_NOT_FOUND;

	synchronize_rcu();
	kfree(s);

	return VMCI_SUCCESS;
}

