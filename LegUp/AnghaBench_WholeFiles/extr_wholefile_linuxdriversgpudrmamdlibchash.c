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
typedef  int u8 ;
typedef  scalar_t__ u64 ;
typedef  int u32 ;
struct chash_table {int /*<<< orphan*/  data; int /*<<< orphan*/  table; } ;
struct chash_iter {size_t slot; int /*<<< orphan*/  mask; struct __chash_table* table; } ;
struct __chash_table {int key_size; scalar_t__ value_size; int /*<<< orphan*/  bits; scalar_t__* keys64; scalar_t__* keys32; } ;
typedef  int /*<<< orphan*/  gfp_t ;

/* Variables and functions */
 int /*<<< orphan*/  BUG_ON (int) ; 
 int /*<<< orphan*/  CHASH_IN_RANGE (struct __chash_table*,int,int,int) ; 
 int /*<<< orphan*/  CHASH_ITER_INC (struct chash_iter) ; 
 struct chash_iter CHASH_ITER_INIT (struct __chash_table*,int) ; 
 int /*<<< orphan*/  CHASH_ITER_SET (struct chash_iter,int) ; 
 int EINVAL ; 
 int ENOMEM ; 
 int /*<<< orphan*/  __CHASH_DATA_SIZE (int,int,unsigned int) ; 
 int /*<<< orphan*/  __CHASH_TABLE_INIT (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int,int,unsigned int) ; 
 int chash_iter_hash (struct chash_iter) ; 
 scalar_t__ chash_iter_is_empty (struct chash_iter) ; 
 scalar_t__ chash_iter_is_valid (struct chash_iter) ; 
 scalar_t__ chash_iter_key (struct chash_iter) ; 
 int /*<<< orphan*/  chash_iter_set_empty (struct chash_iter) ; 
 int /*<<< orphan*/  chash_iter_set_invalid (struct chash_iter) ; 
 int /*<<< orphan*/  chash_iter_set_valid (struct chash_iter) ; 
 void const* chash_iter_value (struct chash_iter) ; 
 int hash_32 (scalar_t__,int /*<<< orphan*/ ) ; 
 int hash_64 (scalar_t__,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  kcalloc (int /*<<< orphan*/ ,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  kfree (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  memcpy (void*,void const*,scalar_t__) ; 
 int /*<<< orphan*/  pr_err (char*) ; 

int chash_table_alloc(struct chash_table *table, u8 bits, u8 key_size,
		      unsigned int value_size, gfp_t gfp_mask)
{
	if (bits > 31)
		return -EINVAL;

	if (key_size != 4 && key_size != 8)
		return -EINVAL;

	table->data = kcalloc(__CHASH_DATA_SIZE(bits, key_size, value_size),
		       sizeof(long), gfp_mask);
	if (!table->data)
		return -ENOMEM;

	__CHASH_TABLE_INIT(table->table, table->data,
			   bits, key_size, value_size);

	return 0;
}

void chash_table_free(struct chash_table *table)
{
	kfree(table->data);
}

__attribute__((used)) static void chash_iter_relocate(struct chash_iter dst, struct chash_iter src)
{
	BUG_ON(src.table == dst.table && src.slot == dst.slot);
	BUG_ON(src.table->key_size != dst.table->key_size);
	BUG_ON(src.table->value_size != dst.table->value_size);

	if (dst.table->key_size == 4)
		dst.table->keys32[dst.slot] = src.table->keys32[src.slot];
	else
		dst.table->keys64[dst.slot] = src.table->keys64[src.slot];

	if (dst.table->value_size)
		memcpy(chash_iter_value(dst), chash_iter_value(src),
		       dst.table->value_size);

	chash_iter_set_valid(dst);
	chash_iter_set_invalid(src);

#ifdef CONFIG_CHASH_STATS
	if (src.table == dst.table) {
		dst.table->relocs++;
		dst.table->reloc_dist +=
			CHASH_SUB(dst.table, src.slot, dst.slot);
	}
#endif
}

__attribute__((used)) static int chash_table_find(struct chash_iter *iter, u64 key,
			    bool for_removal)
{
#ifdef CONFIG_CHASH_STATS
	u64 ts1 = local_clock();
#endif
	u32 hash = iter->slot;
	struct chash_iter first_redundant = CHASH_ITER_INIT(iter->table, -1);
	int first_avail = (for_removal ? -2 : -1);

	while (!chash_iter_is_valid(*iter) || chash_iter_key(*iter) != key) {
		if (chash_iter_is_empty(*iter)) {
			/* Found an empty slot, which ends the
			 * search. Clean up any preceding tombstones
			 * that are no longer needed because they lead
			 * to no-where
			 */
			if ((int)first_redundant.slot < 0)
				goto not_found;
			while (first_redundant.slot != iter->slot) {
				if (!chash_iter_is_valid(first_redundant))
					chash_iter_set_empty(first_redundant);
				CHASH_ITER_INC(first_redundant);
			}
#ifdef CHASH_DEBUG
			chash_table_check(iter->table);
#endif
			goto not_found;
		} else if (!chash_iter_is_valid(*iter)) {
			/* Found a tombstone. Remember it as candidate
			 * for relocating the entry we're looking for
			 * or for adding a new entry with the given key
			 */
			if (first_avail == -1)
				first_avail = iter->slot;
			/* Or mark it as the start of a series of
			 * potentially redundant tombstones
			 */
			else if (first_redundant.slot == -1)
				CHASH_ITER_SET(first_redundant, iter->slot);
		} else if (first_redundant.slot >= 0) {
			/* Found a valid, occupied slot with a
			 * preceding series of tombstones. Relocate it
			 * to a better position that no longer depends
			 * on those tombstones
			 */
			u32 cur_hash = chash_iter_hash(*iter);

			if (!CHASH_IN_RANGE(iter->table, cur_hash,
					    first_redundant.slot + 1,
					    iter->slot)) {
				/* This entry has a hash at or before
				 * the first tombstone we found. We
				 * can relocate it to that tombstone
				 * and advance to the next tombstone
				 */
				chash_iter_relocate(first_redundant, *iter);
				do {
					CHASH_ITER_INC(first_redundant);
				} while (chash_iter_is_valid(first_redundant));
			} else if (cur_hash != iter->slot) {
				/* Relocate entry to its home position
				 * or as close as possible so it no
				 * longer depends on any preceding
				 * tombstones
				 */
				struct chash_iter new_iter =
					CHASH_ITER_INIT(iter->table, cur_hash);

				while (new_iter.slot != iter->slot &&
				       chash_iter_is_valid(new_iter))
					CHASH_ITER_INC(new_iter);

				if (new_iter.slot != iter->slot)
					chash_iter_relocate(new_iter, *iter);
			}
		}

		CHASH_ITER_INC(*iter);
		if (iter->slot == hash) {
			iter->slot = -1;
			goto not_found;
		}
	}

#ifdef CONFIG_CHASH_STATS
	iter->table->hits++;
	iter->table->hits_steps += CHASH_SUB(iter->table, iter->slot, hash) + 1;
#endif

	if (first_avail >= 0) {
		CHASH_ITER_SET(first_redundant, first_avail);
		chash_iter_relocate(first_redundant, *iter);
		iter->slot = first_redundant.slot;
		iter->mask = first_redundant.mask;
	}

#ifdef CONFIG_CHASH_STATS
	iter->table->hits_time_ns += local_clock() - ts1;
#endif

	return 0;

not_found:
#ifdef CONFIG_CHASH_STATS
	iter->table->miss++;
	iter->table->miss_steps += (iter->slot < 0) ?
		(1 << iter->table->bits) :
		CHASH_SUB(iter->table, iter->slot, hash) + 1;
#endif

	if (first_avail >= 0)
		CHASH_ITER_SET(*iter, first_avail);

#ifdef CONFIG_CHASH_STATS
	iter->table->miss_time_ns += local_clock() - ts1;
#endif

	return -EINVAL;
}

int __chash_table_copy_in(struct __chash_table *table, u64 key,
			  const void *value)
{
	u32 hash = (table->key_size == 4) ?
		hash_32(key, table->bits) : hash_64(key, table->bits);
	struct chash_iter iter = CHASH_ITER_INIT(table, hash);
	int r = chash_table_find(&iter, key, false);

	/* Found an existing entry */
	if (!r) {
		if (value && table->value_size)
			memcpy(chash_iter_value(iter), value,
			       table->value_size);
		return 1;
	}

	/* Is there a place to add a new entry? */
	if (iter.slot < 0) {
		pr_err("Hash table overflow\n");
		return -ENOMEM;
	}

	chash_iter_set_valid(iter);

	if (table->key_size == 4)
		table->keys32[iter.slot] = key;
	else
		table->keys64[iter.slot] = key;
	if (value && table->value_size)
		memcpy(chash_iter_value(iter), value, table->value_size);

	return 0;
}

int __chash_table_copy_out(struct __chash_table *table, u64 key,
			   void *value, bool remove)
{
	u32 hash = (table->key_size == 4) ?
		hash_32(key, table->bits) : hash_64(key, table->bits);
	struct chash_iter iter = CHASH_ITER_INIT(table, hash);
	int r = chash_table_find(&iter, key, remove);

	if (r < 0)
		return r;

	if (value && table->value_size)
		memcpy(value, chash_iter_value(iter), table->value_size);

	if (remove)
		chash_iter_set_invalid(iter);

	return iter.slot;
}

