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
typedef  unsigned int u64 ;
typedef  scalar_t__ u32 ;
struct tasklet_struct {int /*<<< orphan*/  count; } ;
struct pci_dev {int dummy; } ;
struct i915_syncmap {int height; scalar_t__ prefix; int bitmap; struct i915_syncmap* parent; } ;
typedef  scalar_t__ s32 ;

/* Variables and functions */
 int BIT (unsigned int) ; 
 int BITS_PER_BYTE ; 
 int /*<<< orphan*/  BUILD_BUG_ON (int) ; 
 int /*<<< orphan*/  BUILD_BUG_ON_NOT_POWER_OF_2 (unsigned int) ; 
 int /*<<< orphan*/  GEM_BUG_ON (int) ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int KSYNCMAP ; 
 unsigned int MASK ; 
 unsigned int SHIFT ; 
 int __sync_set (struct i915_syncmap**,unsigned int,scalar_t__) ; 
 scalar_t__ atomic_dec_return (int /*<<< orphan*/ *) ; 
 int atomic_inc_return (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  atomic_read (int /*<<< orphan*/ *) ; 
 unsigned int ffs (int) ; 
 int /*<<< orphan*/  kfree (struct i915_syncmap*) ; 
 struct i915_syncmap* kmalloc (int,int /*<<< orphan*/ ) ; 
 scalar_t__ likely (int) ; 
 int /*<<< orphan*/  tasklet_kill (struct tasklet_struct*) ; 
 int /*<<< orphan*/  tasklet_unlock_wait (struct tasklet_struct*) ; 
 scalar_t__ unlikely (int) ; 

__attribute__((used)) static inline void __tasklet_disable_sync_once(struct tasklet_struct *t)
{
	if (atomic_inc_return(&t->count) == 1)
		tasklet_unlock_wait(t);
}

__attribute__((used)) static inline void __tasklet_enable_sync_once(struct tasklet_struct *t)
{
	if (atomic_dec_return(&t->count) == 0)
		tasklet_kill(t);
}

__attribute__((used)) static inline bool __tasklet_is_enabled(const struct tasklet_struct *t)
{
	return !atomic_read(&t->count);
}

__attribute__((used)) static inline int i915_mock_selftests(void) { return 0; }

__attribute__((used)) static inline int i915_live_selftests(struct pci_dev *pdev) { return 0; }

void i915_syncmap_init(struct i915_syncmap **root)
{
	BUILD_BUG_ON_NOT_POWER_OF_2(KSYNCMAP);
	BUILD_BUG_ON_NOT_POWER_OF_2(SHIFT);
	BUILD_BUG_ON(KSYNCMAP > BITS_PER_BYTE * sizeof((*root)->bitmap));
	*root = NULL;
}

__attribute__((used)) static inline u32 *__sync_seqno(struct i915_syncmap *p)
{
	GEM_BUG_ON(p->height);
	return (u32 *)(p + 1);
}

__attribute__((used)) static inline struct i915_syncmap **__sync_child(struct i915_syncmap *p)
{
	GEM_BUG_ON(!p->height);
	return (struct i915_syncmap **)(p + 1);
}

__attribute__((used)) static inline unsigned int
__sync_branch_idx(const struct i915_syncmap *p, u64 id)
{
	return (id >> p->height) & MASK;
}

__attribute__((used)) static inline unsigned int
__sync_leaf_idx(const struct i915_syncmap *p, u64 id)
{
	GEM_BUG_ON(p->height);
	return id & MASK;
}

__attribute__((used)) static inline u64 __sync_branch_prefix(const struct i915_syncmap *p, u64 id)
{
	return id >> p->height >> SHIFT;
}

__attribute__((used)) static inline u64 __sync_leaf_prefix(const struct i915_syncmap *p, u64 id)
{
	GEM_BUG_ON(p->height);
	return id >> SHIFT;
}

__attribute__((used)) static inline bool seqno_later(u32 a, u32 b)
{
	return (s32)(a - b) >= 0;
}

bool i915_syncmap_is_later(struct i915_syncmap **root, u64 id, u32 seqno)
{
	struct i915_syncmap *p;
	unsigned int idx;

	p = *root;
	if (!p)
		return false;

	if (likely(__sync_leaf_prefix(p, id) == p->prefix))
		goto found;

	/* First climb the tree back to a parent branch */
	do {
		p = p->parent;
		if (!p)
			return false;

		if (__sync_branch_prefix(p, id) == p->prefix)
			break;
	} while (1);

	/* And then descend again until we find our leaf */
	do {
		if (!p->height)
			break;

		p = __sync_child(p)[__sync_branch_idx(p, id)];
		if (!p)
			return false;

		if (__sync_branch_prefix(p, id) != p->prefix)
			return false;
	} while (1);

	*root = p;
found:
	idx = __sync_leaf_idx(p, id);
	if (!(p->bitmap & BIT(idx)))
		return false;

	return seqno_later(__sync_seqno(p)[idx], seqno);
}

__attribute__((used)) static struct i915_syncmap *
__sync_alloc_leaf(struct i915_syncmap *parent, u64 id)
{
	struct i915_syncmap *p;

	p = kmalloc(sizeof(*p) + KSYNCMAP * sizeof(u32), GFP_KERNEL);
	if (unlikely(!p))
		return NULL;

	p->parent = parent;
	p->height = 0;
	p->bitmap = 0;
	p->prefix = __sync_leaf_prefix(p, id);
	return p;
}

__attribute__((used)) static inline void __sync_set_seqno(struct i915_syncmap *p, u64 id, u32 seqno)
{
	unsigned int idx = __sync_leaf_idx(p, id);

	p->bitmap |= BIT(idx);
	__sync_seqno(p)[idx] = seqno;
}

__attribute__((used)) static inline void __sync_set_child(struct i915_syncmap *p,
				    unsigned int idx,
				    struct i915_syncmap *child)
{
	p->bitmap |= BIT(idx);
	__sync_child(p)[idx] = child;
}

int i915_syncmap_set(struct i915_syncmap **root, u64 id, u32 seqno)
{
	struct i915_syncmap *p = *root;

	/*
	 * We expect to be called in sequence following is_later(id), which
	 * should have preloaded the root for us.
	 */
	if (likely(p && __sync_leaf_prefix(p, id) == p->prefix)) {
		__sync_set_seqno(p, id, seqno);
		return 0;
	}

	return __sync_set(root, id, seqno);
}

__attribute__((used)) static void __sync_free(struct i915_syncmap *p)
{
	if (p->height) {
		unsigned int i;

		while ((i = ffs(p->bitmap))) {
			p->bitmap &= ~0u << i;
			__sync_free(__sync_child(p)[i - 1]);
		}
	}

	kfree(p);
}

void i915_syncmap_free(struct i915_syncmap **root)
{
	struct i915_syncmap *p;

	p = *root;
	if (!p)
		return;

	while (p->parent)
		p = p->parent;

	__sync_free(p);
	*root = NULL;
}

