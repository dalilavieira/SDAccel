#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_7__   TYPE_2__ ;
typedef  struct TYPE_6__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  tid_t ;
struct list_head {scalar_t__ next; } ;
struct jbd2_revoke_record_s {unsigned long long blocknr; struct list_head hash; int /*<<< orphan*/  sequence; } ;
struct TYPE_7__ {int /*<<< orphan*/  j_revoke_lock; TYPE_1__* j_revoke; } ;
typedef  TYPE_2__ journal_t ;
typedef  int /*<<< orphan*/  gfp_t ;
struct TYPE_6__ {struct list_head* hash_table; int /*<<< orphan*/  hash_shift; } ;

/* Variables and functions */
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_NOFS ; 
 int /*<<< orphan*/  __GFP_NOFAIL ; 
 int hash_64 (unsigned long long,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/ * jbd2_revoke_record_cache ; 
 int /*<<< orphan*/ * jbd2_revoke_table_cache ; 
 scalar_t__ journal_oom_retry ; 
 struct jbd2_revoke_record_s* kmem_cache_alloc (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  kmem_cache_destroy (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  list_add (struct list_head*,struct list_head*) ; 
 int /*<<< orphan*/  spin_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  spin_unlock (int /*<<< orphan*/ *) ; 

__attribute__((used)) static inline int hash(journal_t *journal, unsigned long long block)
{
	return hash_64(block, journal->j_revoke->hash_shift);
}

__attribute__((used)) static int insert_revoke_hash(journal_t *journal, unsigned long long blocknr,
			      tid_t seq)
{
	struct list_head *hash_list;
	struct jbd2_revoke_record_s *record;
	gfp_t gfp_mask = GFP_NOFS;

	if (journal_oom_retry)
		gfp_mask |= __GFP_NOFAIL;
	record = kmem_cache_alloc(jbd2_revoke_record_cache, gfp_mask);
	if (!record)
		return -ENOMEM;

	record->sequence = seq;
	record->blocknr = blocknr;
	hash_list = &journal->j_revoke->hash_table[hash(journal, blocknr)];
	spin_lock(&journal->j_revoke_lock);
	list_add(&record->hash, hash_list);
	spin_unlock(&journal->j_revoke_lock);
	return 0;
}

__attribute__((used)) static struct jbd2_revoke_record_s *find_revoke_record(journal_t *journal,
						      unsigned long long blocknr)
{
	struct list_head *hash_list;
	struct jbd2_revoke_record_s *record;

	hash_list = &journal->j_revoke->hash_table[hash(journal, blocknr)];

	spin_lock(&journal->j_revoke_lock);
	record = (struct jbd2_revoke_record_s *) hash_list->next;
	while (&(record->hash) != hash_list) {
		if (record->blocknr == blocknr) {
			spin_unlock(&journal->j_revoke_lock);
			return record;
		}
		record = (struct jbd2_revoke_record_s *) record->hash.next;
	}
	spin_unlock(&journal->j_revoke_lock);
	return NULL;
}

void jbd2_journal_destroy_revoke_caches(void)
{
	kmem_cache_destroy(jbd2_revoke_record_cache);
	jbd2_revoke_record_cache = NULL;
	kmem_cache_destroy(jbd2_revoke_table_cache);
	jbd2_revoke_table_cache = NULL;
}

