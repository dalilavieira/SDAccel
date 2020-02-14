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
typedef  scalar_t__ u8 ;
typedef  int u64 ;
typedef  int u32 ;
typedef  int u16 ;
struct TYPE_2__ {int* state; } ;
struct qman_cgrs {TYPE_1__ q; } ;
struct qm_mcr_querywq {int channel_wq; } ;
struct qm_mcr_querycgr {int /*<<< orphan*/  a_bcnt_lo; scalar_t__ a_bcnt_hi; int /*<<< orphan*/  i_bcnt_lo; scalar_t__ i_bcnt_hi; } ;

/* Variables and functions */
 int CGR_BIT (scalar_t__) ; 
 size_t CGR_WORD (scalar_t__) ; 
 int be32_to_cpu (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  dpaa_invalidate (void*) ; 
 int /*<<< orphan*/  memset (struct qman_cgrs*,int,int) ; 
 int /*<<< orphan*/  prefetch (void*) ; 

__attribute__((used)) static inline void dpaa_flush(void *p)
{
	/*
	 * Only PPC needs to flush the cache currently - on ARM the mapping
	 * is non cacheable
	 */
#ifdef CONFIG_PPC
	flush_dcache_range((unsigned long)p, (unsigned long)p+64);
#endif
}

__attribute__((used)) static inline void dpaa_touch_ro(void *p)
{
#if (L1_CACHE_BYTES == 32)
	prefetch(p+32);
#endif
	prefetch(p);
}

__attribute__((used)) static inline void dpaa_invalidate_touch_ro(void *p)
{
	dpaa_invalidate(p);
	dpaa_touch_ro(p);
}

__attribute__((used)) static inline u8 dpaa_cyc_diff(u8 ringsize, u8 first, u8 last)
{
	/* 'first' is included, 'last' is excluded */
	if (first <= last)
		return last - first;
	return ringsize + last - first;
}

__attribute__((used)) static inline u16 qm_mcr_querywq_get_chan(const struct qm_mcr_querywq *wq)
{
	return wq->channel_wq >> 3;
}

__attribute__((used)) static inline u64 qm_mcr_querycgr_i_get64(const struct qm_mcr_querycgr *q)
{
	return ((u64)q->i_bcnt_hi << 32) | be32_to_cpu(q->i_bcnt_lo);
}

__attribute__((used)) static inline u64 qm_mcr_querycgr_a_get64(const struct qm_mcr_querycgr *q)
{
	return ((u64)q->a_bcnt_hi << 32) | be32_to_cpu(q->a_bcnt_lo);
}

__attribute__((used)) static inline void qman_cgrs_init(struct qman_cgrs *c)
{
	memset(c, 0, sizeof(*c));
}

__attribute__((used)) static inline void qman_cgrs_fill(struct qman_cgrs *c)
{
	memset(c, 0xff, sizeof(*c));
}

__attribute__((used)) static inline int qman_cgrs_get(struct qman_cgrs *c, u8 cgr)
{
	return c->q.state[CGR_WORD(cgr)] & CGR_BIT(cgr);
}

__attribute__((used)) static inline void qman_cgrs_cp(struct qman_cgrs *dest,
				const struct qman_cgrs *src)
{
	*dest = *src;
}

__attribute__((used)) static inline void qman_cgrs_and(struct qman_cgrs *dest,
			const struct qman_cgrs *a, const struct qman_cgrs *b)
{
	int ret;
	u32 *_d = dest->q.state;
	const u32 *_a = a->q.state;
	const u32 *_b = b->q.state;

	for (ret = 0; ret < 8; ret++)
		*_d++ = *_a++ & *_b++;
}

__attribute__((used)) static inline void qman_cgrs_xor(struct qman_cgrs *dest,
			const struct qman_cgrs *a, const struct qman_cgrs *b)
{
	int ret;
	u32 *_d = dest->q.state;
	const u32 *_a = a->q.state;
	const u32 *_b = b->q.state;

	for (ret = 0; ret < 8; ret++)
		*_d++ = *_a++ ^ *_b++;
}

__attribute__((used)) static int test_init(void)
{
	int loop = 1;
	int err = 0;

	while (loop--) {
#ifdef CONFIG_FSL_QMAN_TEST_STASH
		err = qman_test_stash();
		if (err)
			break;
#endif
#ifdef CONFIG_FSL_QMAN_TEST_API
		err = qman_test_api();
		if (err)
			break;
#endif
	}
	return err;
}

__attribute__((used)) static void test_exit(void)
{
}

