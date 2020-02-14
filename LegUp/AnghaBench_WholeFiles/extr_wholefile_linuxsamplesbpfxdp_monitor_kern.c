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
typedef  scalar_t__ u32 ;
struct xdp_redirect_ctx {int dummy; } ;
struct xdp_exception_ctx {scalar_t__ act; } ;
struct devmap_xmit_ctx {scalar_t__ drops; scalar_t__ err; scalar_t__ sent; } ;
struct datarec {int info; int /*<<< orphan*/  err; int /*<<< orphan*/  dropped; int /*<<< orphan*/  processed; } ;
struct cpumap_kthread_ctx {scalar_t__ sched; scalar_t__ drops; scalar_t__ processed; } ;
struct cpumap_enqueue_ctx {scalar_t__ to_cpu; scalar_t__ processed; scalar_t__ drops; } ;

/* Variables and functions */
 scalar_t__ MAX_CPUS ; 
 scalar_t__ XDP_REDIRECT ; 
 scalar_t__ XDP_UNKNOWN ; 
 void* bpf_map_lookup_elem (int /*<<< orphan*/ *,scalar_t__*) ; 
 int /*<<< orphan*/  cpumap_enqueue_cnt ; 
 int /*<<< orphan*/  cpumap_kthread_cnt ; 
 int /*<<< orphan*/  devmap_xmit_cnt ; 
 int /*<<< orphan*/  exception_cnt ; 
 int xdp_redirect_collect_stat (struct xdp_redirect_ctx*) ; 

int trace_xdp_redirect_err(struct xdp_redirect_ctx *ctx)
{
	return xdp_redirect_collect_stat(ctx);
}

int trace_xdp_redirect_map_err(struct xdp_redirect_ctx *ctx)
{
	return xdp_redirect_collect_stat(ctx);
}

int trace_xdp_redirect(struct xdp_redirect_ctx *ctx)
{
	return xdp_redirect_collect_stat(ctx);
}

int trace_xdp_redirect_map(struct xdp_redirect_ctx *ctx)
{
	return xdp_redirect_collect_stat(ctx);
}

int trace_xdp_exception(struct xdp_exception_ctx *ctx)
{
	u64 *cnt;
	u32 key;

	key = ctx->act;
	if (key > XDP_REDIRECT)
		key = XDP_UNKNOWN;

	cnt = bpf_map_lookup_elem(&exception_cnt, &key);
	if (!cnt)
		return 1;
	*cnt += 1;

	return 0;
}

int trace_xdp_cpumap_enqueue(struct cpumap_enqueue_ctx *ctx)
{
	u32 to_cpu = ctx->to_cpu;
	struct datarec *rec;

	if (to_cpu >= MAX_CPUS)
		return 1;

	rec = bpf_map_lookup_elem(&cpumap_enqueue_cnt, &to_cpu);
	if (!rec)
		return 0;
	rec->processed += ctx->processed;
	rec->dropped   += ctx->drops;

	/* Record bulk events, then userspace can calc average bulk size */
	if (ctx->processed > 0)
		rec->info += 1;

	return 0;
}

int trace_xdp_cpumap_kthread(struct cpumap_kthread_ctx *ctx)
{
	struct datarec *rec;
	u32 key = 0;

	rec = bpf_map_lookup_elem(&cpumap_kthread_cnt, &key);
	if (!rec)
		return 0;
	rec->processed += ctx->processed;
	rec->dropped   += ctx->drops;

	/* Count times kthread yielded CPU via schedule call */
	if (ctx->sched)
		rec->info++;

	return 0;
}

int trace_xdp_devmap_xmit(struct devmap_xmit_ctx *ctx)
{
	struct datarec *rec;
	u32 key = 0;

	rec = bpf_map_lookup_elem(&devmap_xmit_cnt, &key);
	if (!rec)
		return 0;
	rec->processed += ctx->sent;
	rec->dropped   += ctx->drops;

	/* Record bulk events, then userspace can calc average bulk size */
	rec->info += 1;

	/* Record error cases, where no frame were sent */
	if (ctx->err)
		rec->err++;

	/* Catch API error of drv ndo_xdp_xmit sent more than count */
	if (ctx->drops < 0)
		rec->err++;

	return 1;
}

