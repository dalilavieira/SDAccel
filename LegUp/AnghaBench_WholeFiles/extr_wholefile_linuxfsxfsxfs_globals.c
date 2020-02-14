#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_9__   TYPE_1__ ;

/* Type definitions */
typedef  int xfs_km_flags_t ;
typedef  int /*<<< orphan*/  xfs_dev_t ;
typedef  int /*<<< orphan*/  xfs_daddr_t ;
typedef  int /*<<< orphan*/  xfs_buf_t ;
typedef  int /*<<< orphan*/  xfs_buf_flags_t ;
typedef  int uint64_t ;
typedef  int uint32_t ;
struct xfs_mount {int dummy; } ;
struct xfs_buftarg {int dummy; } ;
struct xfs_buf_ops {int dummy; } ;
struct xfs_buf {int b_flags; int /*<<< orphan*/  b_length; int /*<<< orphan*/  b_addr; int /*<<< orphan*/  b_pin_count; int /*<<< orphan*/  b_lru_ref; int /*<<< orphan*/  b_lru; } ;
typedef  int /*<<< orphan*/  slab_flags_t ;
struct TYPE_9__ {int /*<<< orphan*/  mr_lock; } ;
typedef  TYPE_1__ mrlock_t ;
typedef  int /*<<< orphan*/  kuid_t ;
typedef  int /*<<< orphan*/  kmem_zone_t ;
typedef  int /*<<< orphan*/  kgid_t ;
typedef  int gfp_t ;
typedef  int /*<<< orphan*/  dev_t ;

/* Variables and functions */
 int /*<<< orphan*/  BBTOB (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  BUG_ON (int) ; 
 int /*<<< orphan*/  DEFINE_SINGLE_BUF_MAP (int /*<<< orphan*/ ,int /*<<< orphan*/ ,size_t) ; 
 int GFP_ATOMIC ; 
 int GFP_KERNEL ; 
 int KM_MAYFAIL ; 
 int KM_NOFS ; 
 int KM_NOSLEEP ; 
 int KM_SLEEP ; 
 int KM_ZERO ; 
 int /*<<< orphan*/  MKDEV (int,int /*<<< orphan*/ ) ; 
 int XBF_ASYNC ; 
 int __GFP_FS ; 
 int __GFP_NOWARN ; 
 int __GFP_RETRY_MAYFAIL ; 
 int __GFP_ZERO ; 
 int __xfs_buf_submit (struct xfs_buf*,int) ; 
 struct xfs_buf* _xfs_buf_alloc (struct xfs_buftarg*,int /*<<< orphan*/ *,int,int /*<<< orphan*/ ) ; 
 int atomic_read (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  atomic_set (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  do_div (int,int) ; 
 int /*<<< orphan*/  down_read_nested (int /*<<< orphan*/ *,int) ; 
 int down_read_trylock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  down_write_nested (int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  down_write_trylock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  downgrade_write (int /*<<< orphan*/ *) ; 
 int from_kgid (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int from_kuid (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  init_user_ns ; 
 void* kmem_alloc (size_t,int) ; 
 void* kmem_alloc_large (size_t,int) ; 
 int /*<<< orphan*/ * kmem_cache_create (char*,int,int /*<<< orphan*/ ,int /*<<< orphan*/ ,void (*) (void*)) ; 
 int /*<<< orphan*/  kmem_cache_destroy (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  kmem_cache_free (int /*<<< orphan*/ *,void*) ; 
 void* kmem_zone_alloc (int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  kvfree (void const*) ; 
 int /*<<< orphan*/  list_empty (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  make_kgid (int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  make_kuid (int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  map ; 
 int /*<<< orphan*/  schedule_timeout_uninterruptible (long) ; 
 int /*<<< orphan*/  sysv_encode_dev (int /*<<< orphan*/ ) ; 
 int sysv_major (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  sysv_minor (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  up_read (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  up_write (int /*<<< orphan*/ *) ; 
 struct xfs_buf* xfs_buf_get_map (struct xfs_buftarg*,int /*<<< orphan*/ *,int,int /*<<< orphan*/ ) ; 
 struct xfs_buf* xfs_buf_read_map (struct xfs_buftarg*,int /*<<< orphan*/ *,int,int /*<<< orphan*/ ,struct xfs_buf_ops const*) ; 
 void xfs_buf_readahead_map (struct xfs_buftarg*,int /*<<< orphan*/ *,int,struct xfs_buf_ops const*) ; 
 int /*<<< orphan*/  xfs_buf_rele (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  xfs_buf_unlock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  xfs_update_cksum (int /*<<< orphan*/ ,int /*<<< orphan*/ ,unsigned long) ; 
 int xfs_verify_cksum (int /*<<< orphan*/ ,int /*<<< orphan*/ ,unsigned long) ; 

__attribute__((used)) static inline gfp_t
kmem_flags_convert(xfs_km_flags_t flags)
{
	gfp_t	lflags;

	BUG_ON(flags & ~(KM_SLEEP|KM_NOSLEEP|KM_NOFS|KM_MAYFAIL|KM_ZERO));

	if (flags & KM_NOSLEEP) {
		lflags = GFP_ATOMIC | __GFP_NOWARN;
	} else {
		lflags = GFP_KERNEL | __GFP_NOWARN;
		if (flags & KM_NOFS)
			lflags &= ~__GFP_FS;
	}

	/*
	 * Default page/slab allocator behavior is to retry for ever
	 * for small allocations. We can override this behavior by using
	 * __GFP_RETRY_MAYFAIL which will tell the allocator to retry as long
	 * as it is feasible but rather fail than retry forever for all
	 * request sizes.
	 */
	if (flags & KM_MAYFAIL)
		lflags |= __GFP_RETRY_MAYFAIL;

	if (flags & KM_ZERO)
		lflags |= __GFP_ZERO;

	return lflags;
}

__attribute__((used)) static inline void  kmem_free(const void *ptr)
{
	kvfree(ptr);
}

__attribute__((used)) static inline void *
kmem_zalloc(size_t size, xfs_km_flags_t flags)
{
	return kmem_alloc(size, flags | KM_ZERO);
}

__attribute__((used)) static inline void *
kmem_zalloc_large(size_t size, xfs_km_flags_t flags)
{
	return kmem_alloc_large(size, flags | KM_ZERO);
}

__attribute__((used)) static inline kmem_zone_t *
kmem_zone_init(int size, char *zone_name)
{
	return kmem_cache_create(zone_name, size, 0, 0, NULL);
}

__attribute__((used)) static inline kmem_zone_t *
kmem_zone_init_flags(int size, char *zone_name, slab_flags_t flags,
		     void (*construct)(void *))
{
	return kmem_cache_create(zone_name, size, 0, flags, construct);
}

__attribute__((used)) static inline void
kmem_zone_free(kmem_zone_t *zone, void *ptr)
{
	kmem_cache_free(zone, ptr);
}

__attribute__((used)) static inline void
kmem_zone_destroy(kmem_zone_t *zone)
{
	kmem_cache_destroy(zone);
}

__attribute__((used)) static inline void *
kmem_zone_zalloc(kmem_zone_t *zone, xfs_km_flags_t flags)
{
	return kmem_zone_alloc(zone, flags | KM_ZERO);
}

__attribute__((used)) static inline void mraccess_nested(mrlock_t *mrp, int subclass)
{
	down_read_nested(&mrp->mr_lock, subclass);
}

__attribute__((used)) static inline void mrupdate_nested(mrlock_t *mrp, int subclass)
{
	down_write_nested(&mrp->mr_lock, subclass);
#if defined(DEBUG) || defined(XFS_WARN)
	mrp->mr_writer = 1;
#endif
}

__attribute__((used)) static inline int mrtryaccess(mrlock_t *mrp)
{
	return down_read_trylock(&mrp->mr_lock);
}

__attribute__((used)) static inline int mrtryupdate(mrlock_t *mrp)
{
	if (!down_write_trylock(&mrp->mr_lock))
		return 0;
#if defined(DEBUG) || defined(XFS_WARN)
	mrp->mr_writer = 1;
#endif
	return 1;
}

__attribute__((used)) static inline void mrunlock_excl(mrlock_t *mrp)
{
#if defined(DEBUG) || defined(XFS_WARN)
	mrp->mr_writer = 0;
#endif
	up_write(&mrp->mr_lock);
}

__attribute__((used)) static inline void mrunlock_shared(mrlock_t *mrp)
{
	up_read(&mrp->mr_lock);
}

__attribute__((used)) static inline void mrdemote(mrlock_t *mrp)
{
#if defined(DEBUG) || defined(XFS_WARN)
	mrp->mr_writer = 0;
#endif
	downgrade_write(&mrp->mr_lock);
}

__attribute__((used)) static inline int xfs_init_procfs(void)
{
	return 0;
}

__attribute__((used)) static inline void xfs_cleanup_procfs(void)
{
}

__attribute__((used)) static inline struct xfs_buf *
xfs_buf_alloc(
	struct xfs_buftarg	*target,
	xfs_daddr_t		blkno,
	size_t			numblks,
	xfs_buf_flags_t		flags)
{
	DEFINE_SINGLE_BUF_MAP(map, blkno, numblks);
	return _xfs_buf_alloc(target, &map, 1, flags);
}

__attribute__((used)) static inline struct xfs_buf *
xfs_buf_get(
	struct xfs_buftarg	*target,
	xfs_daddr_t		blkno,
	size_t			numblks,
	xfs_buf_flags_t		flags)
{
	DEFINE_SINGLE_BUF_MAP(map, blkno, numblks);
	return xfs_buf_get_map(target, &map, 1, flags);
}

__attribute__((used)) static inline struct xfs_buf *
xfs_buf_read(
	struct xfs_buftarg	*target,
	xfs_daddr_t		blkno,
	size_t			numblks,
	xfs_buf_flags_t		flags,
	const struct xfs_buf_ops *ops)
{
	DEFINE_SINGLE_BUF_MAP(map, blkno, numblks);
	return xfs_buf_read_map(target, &map, 1, flags, ops);
}

__attribute__((used)) static inline void
xfs_buf_readahead(
	struct xfs_buftarg	*target,
	xfs_daddr_t		blkno,
	size_t			numblks,
	const struct xfs_buf_ops *ops)
{
	DEFINE_SINGLE_BUF_MAP(map, blkno, numblks);
	return xfs_buf_readahead_map(target, &map, 1, ops);
}

__attribute__((used)) static inline int xfs_buf_submit(struct xfs_buf *bp)
{
	bool wait = bp->b_flags & XBF_ASYNC ? false : true;
	return __xfs_buf_submit(bp, wait);
}

__attribute__((used)) static inline void xfs_buf_oneshot(struct xfs_buf *bp)
{
	if (!list_empty(&bp->b_lru) || atomic_read(&bp->b_lru_ref) > 1)
		return;
	atomic_set(&bp->b_lru_ref, 0);
}

__attribute__((used)) static inline int xfs_buf_ispinned(struct xfs_buf *bp)
{
	return atomic_read(&bp->b_pin_count);
}

__attribute__((used)) static inline void xfs_buf_relse(xfs_buf_t *bp)
{
	xfs_buf_unlock(bp);
	xfs_buf_rele(bp);
}

__attribute__((used)) static inline int
xfs_buf_verify_cksum(struct xfs_buf *bp, unsigned long cksum_offset)
{
	return xfs_verify_cksum(bp->b_addr, BBTOB(bp->b_length),
				cksum_offset);
}

__attribute__((used)) static inline void
xfs_buf_update_cksum(struct xfs_buf *bp, unsigned long cksum_offset)
{
	xfs_update_cksum(bp->b_addr, BBTOB(bp->b_length),
			 cksum_offset);
}

void xfs_debug(const struct xfs_mount *mp, const char *fmt, ...)
{
}

__attribute__((used)) static inline void delay(long ticks)
{
	schedule_timeout_uninterruptible(ticks);
}

__attribute__((used)) static inline uint32_t xfs_kuid_to_uid(kuid_t uid)
{
	return from_kuid(&init_user_ns, uid);
}

__attribute__((used)) static inline kuid_t xfs_uid_to_kuid(uint32_t uid)
{
	return make_kuid(&init_user_ns, uid);
}

__attribute__((used)) static inline uint32_t xfs_kgid_to_gid(kgid_t gid)
{
	return from_kgid(&init_user_ns, gid);
}

__attribute__((used)) static inline kgid_t xfs_gid_to_kgid(uint32_t gid)
{
	return make_kgid(&init_user_ns, gid);
}

__attribute__((used)) static inline dev_t xfs_to_linux_dev_t(xfs_dev_t dev)
{
	return MKDEV(sysv_major(dev) & 0x1ff, sysv_minor(dev));
}

__attribute__((used)) static inline xfs_dev_t linux_to_xfs_dev_t(dev_t dev)
{
	return sysv_encode_dev(dev);
}

__attribute__((used)) static inline uint64_t roundup_64(uint64_t x, uint32_t y)
{
	x += y - 1;
	do_div(x, y);
	return x * y;
}

__attribute__((used)) static inline uint64_t howmany_64(uint64_t x, uint32_t y)
{
	x += y - 1;
	do_div(x, y);
	return x;
}

