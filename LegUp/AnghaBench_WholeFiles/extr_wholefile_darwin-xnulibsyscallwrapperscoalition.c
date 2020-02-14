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
typedef  int /*<<< orphan*/  uint64_t ;
typedef  int /*<<< orphan*/  uint32_t ;
typedef  void coalition_resource_usage ;
typedef  int /*<<< orphan*/  flags ;

/* Variables and functions */
 int /*<<< orphan*/  COALITION_INFO_RESOURCE_USAGE ; 
 int /*<<< orphan*/  COALITION_INFO_SET_EFFICIENCY ; 
 int /*<<< orphan*/  COALITION_INFO_SET_NAME ; 
 int /*<<< orphan*/  COALITION_OP_CREATE ; 
 int /*<<< orphan*/  COALITION_OP_REAP ; 
 int /*<<< orphan*/  COALITION_OP_TERMINATE ; 
 int __coalition (int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int __coalition_info (int /*<<< orphan*/ ,int /*<<< orphan*/ *,void*,size_t*) ; 

int coalition_create(uint64_t *cid_out, uint32_t flags)
{
	return __coalition(COALITION_OP_CREATE, cid_out, flags);
}

int coalition_terminate(uint64_t cid, uint32_t flags)
{
	return __coalition(COALITION_OP_TERMINATE, &cid, flags);
}

int coalition_reap(uint64_t cid, uint32_t flags)
{
	return __coalition(COALITION_OP_REAP, &cid, flags);
}

int coalition_info_resource_usage(uint64_t cid, struct coalition_resource_usage *cru, size_t sz)
{
	return __coalition_info(COALITION_INFO_RESOURCE_USAGE, &cid, cru, &sz);
}

int coalition_info_set_name(uint64_t cid, const char *name, size_t size)
{
	return __coalition_info(COALITION_INFO_SET_NAME, &cid, (void *)name, &size);
}

int coalition_info_set_efficiency(uint64_t cid, uint64_t flags)
{
    size_t size = sizeof(flags);
    return __coalition_info(COALITION_INFO_SET_EFFICIENCY, &cid, (void *)&flags, &size);
}

