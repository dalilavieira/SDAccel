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
struct vmci_qp_page_store {int len; } ;
struct vmci_handle_arr {size_t size; } ;
struct vmci_ctx {int cid; } ;

/* Variables and functions */
 int VMCI_HOST_CONTEXT_ID ; 
 int VMCI_INVALID_ID ; 
 int VMCI_PRIVILEGE_FLAG_RESTRICTED ; 
 int VMCI_PRIVILEGE_FLAG_TRUSTED ; 
 int vmci_get_vm_context_id () ; 
 scalar_t__ vmci_guest_code_active () ; 
 scalar_t__ vmci_host_code_active () ; 

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

u32 vmci_get_context_id(void)
{
	if (vmci_guest_code_active())
		return vmci_get_vm_context_id();
	else if (vmci_host_code_active())
		return VMCI_HOST_CONTEXT_ID;

	return VMCI_INVALID_ID;
}

