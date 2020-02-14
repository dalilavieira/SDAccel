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
typedef  int u64 ;
typedef  int u32 ;
struct tee_shm_pool_mgr {int /*<<< orphan*/ * ops; } ;
struct tee_shm {unsigned int size; int /*<<< orphan*/ * kaddr; int /*<<< orphan*/  paddr; } ;
struct page {int dummy; } ;

/* Variables and functions */
 int ENOMEM ; 
 struct tee_shm_pool_mgr* ERR_PTR (int) ; 
 int GFP_KERNEL ; 
 int OPTEE_SMC_RETURN_RPC_PREFIX ; 
 int OPTEE_SMC_RETURN_RPC_PREFIX_MASK ; 
 int OPTEE_SMC_RETURN_UNKNOWN_FUNCTION ; 
 unsigned int PAGE_SIZE ; 
 int __GFP_ZERO ; 
 struct page* alloc_pages (int,unsigned int) ; 
 int /*<<< orphan*/  free_pages (unsigned long,unsigned int) ; 
 unsigned int get_order (size_t) ; 
 int /*<<< orphan*/  kfree (struct tee_shm_pool_mgr*) ; 
 struct tee_shm_pool_mgr* kzalloc (int,int) ; 
 int /*<<< orphan*/ * page_address (struct page*) ; 
 int /*<<< orphan*/  page_to_phys (struct page*) ; 
 int /*<<< orphan*/  pool_ops ; 

__attribute__((used)) static inline void *reg_pair_to_ptr(u32 reg0, u32 reg1)
{
	return (void *)(unsigned long)(((u64)reg0 << 32) | reg1);
}

__attribute__((used)) static inline void reg_pair_from_64(u32 *reg0, u32 *reg1, u64 val)
{
	*reg0 = val >> 32;
	*reg1 = val;
}

__attribute__((used)) static inline bool __optee_smc_return_is_rpc(u32 ret)
{
	return ret != OPTEE_SMC_RETURN_UNKNOWN_FUNCTION &&
	       (ret & OPTEE_SMC_RETURN_RPC_PREFIX_MASK) ==
			OPTEE_SMC_RETURN_RPC_PREFIX;
}

__attribute__((used)) static int pool_op_alloc(struct tee_shm_pool_mgr *poolm,
			 struct tee_shm *shm, size_t size)
{
	unsigned int order = get_order(size);
	struct page *page;

	page = alloc_pages(GFP_KERNEL | __GFP_ZERO, order);
	if (!page)
		return -ENOMEM;

	shm->kaddr = page_address(page);
	shm->paddr = page_to_phys(page);
	shm->size = PAGE_SIZE << order;

	return 0;
}

__attribute__((used)) static void pool_op_free(struct tee_shm_pool_mgr *poolm,
			 struct tee_shm *shm)
{
	free_pages((unsigned long)shm->kaddr, get_order(shm->size));
	shm->kaddr = NULL;
}

__attribute__((used)) static void pool_op_destroy_poolmgr(struct tee_shm_pool_mgr *poolm)
{
	kfree(poolm);
}

struct tee_shm_pool_mgr *optee_shm_pool_alloc_pages(void)
{
	struct tee_shm_pool_mgr *mgr = kzalloc(sizeof(*mgr), GFP_KERNEL);

	if (!mgr)
		return ERR_PTR(-ENOMEM);

	mgr->ops = &pool_ops;

	return mgr;
}

