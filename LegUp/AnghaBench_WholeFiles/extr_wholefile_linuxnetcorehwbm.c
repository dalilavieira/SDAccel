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
struct hwbm_pool {int frag_size; scalar_t__ buf_num; scalar_t__ size; int /*<<< orphan*/  lock; scalar_t__ (* construct ) (struct hwbm_pool*,void*) ;} ;
typedef  int /*<<< orphan*/  gfp_t ;

/* Variables and functions */
 int ENOMEM ; 
 int PAGE_SIZE ; 
 int /*<<< orphan*/  kfree (void*) ; 
 void* kmalloc (int,int /*<<< orphan*/ ) ; 
 scalar_t__ likely (int) ; 
 void* netdev_alloc_frag (int) ; 
 int /*<<< orphan*/  pr_debug (char*,int,unsigned int) ; 
 int /*<<< orphan*/  pr_warn (char*,...) ; 
 int /*<<< orphan*/  skb_free_frag (void*) ; 
 int /*<<< orphan*/  spin_lock_irqsave (int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  spin_unlock_irqrestore (int /*<<< orphan*/ *,unsigned long) ; 
 scalar_t__ stub1 (struct hwbm_pool*,void*) ; 

void hwbm_buf_free(struct hwbm_pool *bm_pool, void *buf)
{
	if (likely(bm_pool->frag_size <= PAGE_SIZE))
		skb_free_frag(buf);
	else
		kfree(buf);
}

int hwbm_pool_refill(struct hwbm_pool *bm_pool, gfp_t gfp)
{
	int frag_size = bm_pool->frag_size;
	void *buf;

	if (likely(frag_size <= PAGE_SIZE))
		buf = netdev_alloc_frag(frag_size);
	else
		buf = kmalloc(frag_size, gfp);

	if (!buf)
		return -ENOMEM;

	if (bm_pool->construct)
		if (bm_pool->construct(bm_pool, buf)) {
			hwbm_buf_free(bm_pool, buf);
			return -ENOMEM;
		}

	return 0;
}

int hwbm_pool_add(struct hwbm_pool *bm_pool, unsigned int buf_num, gfp_t gfp)
{
	int err, i;
	unsigned long flags;

	spin_lock_irqsave(&bm_pool->lock, flags);
	if (bm_pool->buf_num == bm_pool->size) {
		pr_warn("pool already filled\n");
		spin_unlock_irqrestore(&bm_pool->lock, flags);
		return bm_pool->buf_num;
	}

	if (buf_num + bm_pool->buf_num > bm_pool->size) {
		pr_warn("cannot allocate %d buffers for pool\n",
			buf_num);
		spin_unlock_irqrestore(&bm_pool->lock, flags);
		return 0;
	}

	if ((buf_num + bm_pool->buf_num) < bm_pool->buf_num) {
		pr_warn("Adding %d buffers to the %d current buffers will overflow\n",
			buf_num,  bm_pool->buf_num);
		spin_unlock_irqrestore(&bm_pool->lock, flags);
		return 0;
	}

	for (i = 0; i < buf_num; i++) {
		err = hwbm_pool_refill(bm_pool, gfp);
		if (err < 0)
			break;
	}

	/* Update BM driver with number of buffers added to pool */
	bm_pool->buf_num += i;

	pr_debug("hwpm pool: %d of %d buffers added\n", i, buf_num);
	spin_unlock_irqrestore(&bm_pool->lock, flags);

	return i;
}

