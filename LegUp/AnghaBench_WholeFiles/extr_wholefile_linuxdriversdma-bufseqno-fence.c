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
struct seqno_fence {TYPE_1__* ops; int /*<<< orphan*/  base; int /*<<< orphan*/  sync_buf; } ;
struct dma_fence {int dummy; } ;
struct TYPE_2__ {char const* (* get_driver_name ) (struct dma_fence*) ;char const* (* get_timeline_name ) (struct dma_fence*) ;int (* enable_signaling ) (struct dma_fence*) ;long (* wait ) (struct dma_fence*,int,long) ;int /*<<< orphan*/  (* release ) (struct dma_fence*) ;scalar_t__ (* signaled ) (struct dma_fence*) ;} ;

/* Variables and functions */
 int /*<<< orphan*/  dma_buf_put (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  dma_fence_free (int /*<<< orphan*/ *) ; 
 char const* stub1 (struct dma_fence*) ; 
 char const* stub2 (struct dma_fence*) ; 
 int stub3 (struct dma_fence*) ; 
 scalar_t__ stub4 (struct dma_fence*) ; 
 int /*<<< orphan*/  stub5 (struct dma_fence*) ; 
 long stub6 (struct dma_fence*,int,long) ; 
 struct seqno_fence* to_seqno_fence (struct dma_fence*) ; 

__attribute__((used)) static const char *seqno_fence_get_driver_name(struct dma_fence *fence)
{
	struct seqno_fence *seqno_fence = to_seqno_fence(fence);

	return seqno_fence->ops->get_driver_name(fence);
}

__attribute__((used)) static const char *seqno_fence_get_timeline_name(struct dma_fence *fence)
{
	struct seqno_fence *seqno_fence = to_seqno_fence(fence);

	return seqno_fence->ops->get_timeline_name(fence);
}

__attribute__((used)) static bool seqno_enable_signaling(struct dma_fence *fence)
{
	struct seqno_fence *seqno_fence = to_seqno_fence(fence);

	return seqno_fence->ops->enable_signaling(fence);
}

__attribute__((used)) static bool seqno_signaled(struct dma_fence *fence)
{
	struct seqno_fence *seqno_fence = to_seqno_fence(fence);

	return seqno_fence->ops->signaled && seqno_fence->ops->signaled(fence);
}

__attribute__((used)) static void seqno_release(struct dma_fence *fence)
{
	struct seqno_fence *f = to_seqno_fence(fence);

	dma_buf_put(f->sync_buf);
	if (f->ops->release)
		f->ops->release(fence);
	else
		dma_fence_free(&f->base);
}

__attribute__((used)) static signed long seqno_wait(struct dma_fence *fence, bool intr,
			      signed long timeout)
{
	struct seqno_fence *f = to_seqno_fence(fence);

	return f->ops->wait(fence, intr, timeout);
}

