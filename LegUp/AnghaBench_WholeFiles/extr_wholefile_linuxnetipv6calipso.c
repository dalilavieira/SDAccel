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
typedef  int /*<<< orphan*/  u32 ;
struct calipso_map_cache_entry {struct calipso_map_cache_entry* key; scalar_t__ lsm_data; } ;

/* Variables and functions */
 int /*<<< orphan*/  jhash (unsigned char const*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  kfree (struct calipso_map_cache_entry*) ; 
 int /*<<< orphan*/  netlbl_secattr_cache_free (scalar_t__) ; 

__attribute__((used)) static void calipso_cache_entry_free(struct calipso_map_cache_entry *entry)
{
	if (entry->lsm_data)
		netlbl_secattr_cache_free(entry->lsm_data);
	kfree(entry->key);
	kfree(entry);
}

__attribute__((used)) static u32 calipso_map_cache_hash(const unsigned char *key, u32 key_len)
{
	return jhash(key, key_len, 0);
}

