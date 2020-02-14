#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_18__   TYPE_2__ ;
typedef  struct TYPE_17__   TYPE_1__ ;

/* Type definitions */
typedef  size_t zend_ulong ;
typedef  int /*<<< orphan*/  zend_string ;
typedef  int zend_bool ;
struct TYPE_17__ {int indirect; size_t hash_value; size_t key_length; char const* key; struct TYPE_17__* next; struct TYPE_17__* data; } ;
typedef  TYPE_1__ zend_accel_hash_entry ;
struct TYPE_18__ {scalar_t__ num_entries; scalar_t__ max_num_entries; TYPE_1__** hash_table; scalar_t__ num_direct_entries; TYPE_1__* hash_entries; } ;
typedef  TYPE_2__ zend_accel_hash ;
typedef  size_t uint32_t ;

/* Variables and functions */
 int /*<<< orphan*/  ACCEL_LOG_FATAL ; 
 int FAILURE ; 
 int SUCCESS ; 
 size_t ZCG (int /*<<< orphan*/ ) ; 
 size_t ZSTR_LEN (int /*<<< orphan*/ *) ; 
 char const* ZSTR_VAL (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  memcmp (char const*,char const*,size_t) ; 
 int /*<<< orphan*/  memset (TYPE_1__**,int /*<<< orphan*/ ,int) ; 
 size_t num_prime_numbers ; 
 size_t* prime_numbers ; 
 int /*<<< orphan*/  root_hash ; 
 int /*<<< orphan*/  zend_accel_error (int /*<<< orphan*/ ,char*) ; 
 void* zend_accel_hash_find_ex (TYPE_2__*,char const*,size_t,size_t,int) ; 
 size_t zend_inline_hash_func (char const*,size_t) ; 
 void* zend_shared_alloc (int) ; 
 size_t zend_string_hash_val (int /*<<< orphan*/ *) ; 

__attribute__((used)) static inline zend_bool zend_accel_hash_is_full(zend_accel_hash *accel_hash)
{
	if (accel_hash->num_entries == accel_hash->max_num_entries) {
		return 1;
	} else {
		return 0;
	}
}

void zend_accel_hash_clean(zend_accel_hash *accel_hash)
{
	accel_hash->num_entries = 0;
	accel_hash->num_direct_entries = 0;
	memset(accel_hash->hash_table, 0, sizeof(zend_accel_hash_entry *)*accel_hash->max_num_entries);
}

void zend_accel_hash_init(zend_accel_hash *accel_hash, uint32_t hash_size)
{
	uint32_t i;

	for (i=0; i<num_prime_numbers; i++) {
		if (hash_size <= prime_numbers[i]) {
			hash_size = prime_numbers[i];
			break;
		}
	}

	accel_hash->num_entries = 0;
	accel_hash->num_direct_entries = 0;
	accel_hash->max_num_entries = hash_size;

	/* set up hash pointers table */
	accel_hash->hash_table = zend_shared_alloc(sizeof(zend_accel_hash_entry *)*accel_hash->max_num_entries);
	if (!accel_hash->hash_table) {
		zend_accel_error(ACCEL_LOG_FATAL, "Insufficient shared memory!");
		return;
	}

	/* set up hash values table */
	accel_hash->hash_entries = zend_shared_alloc(sizeof(zend_accel_hash_entry)*accel_hash->max_num_entries);
	if (!accel_hash->hash_entries) {
		zend_accel_error(ACCEL_LOG_FATAL, "Insufficient shared memory!");
		return;
	}
	memset(accel_hash->hash_table, 0, sizeof(zend_accel_hash_entry *)*accel_hash->max_num_entries);
}

zend_accel_hash_entry* zend_accel_hash_update(zend_accel_hash *accel_hash, const char *key, uint32_t key_length, zend_bool indirect, void *data)
{
	zend_ulong hash_value;
	zend_ulong index;
	zend_accel_hash_entry *entry;
	zend_accel_hash_entry *indirect_bucket = NULL;

	if (indirect) {
		indirect_bucket = (zend_accel_hash_entry*)data;
		while (indirect_bucket->indirect) {
			indirect_bucket = (zend_accel_hash_entry*)indirect_bucket->data;
		}
	}

	hash_value = zend_inline_hash_func(key, key_length);
#ifndef ZEND_WIN32
	hash_value ^= ZCG(root_hash);
#endif
	index = hash_value % accel_hash->max_num_entries;

	/* try to see if the element already exists in the hash */
	entry = accel_hash->hash_table[index];
	while (entry) {
		if (entry->hash_value == hash_value
			&& entry->key_length == key_length
			&& !memcmp(entry->key, key, key_length)) {

			if (entry->indirect) {
				if (indirect_bucket) {
					entry->data = indirect_bucket;
				} else {
					((zend_accel_hash_entry*)entry->data)->data = data;
				}
			} else {
				if (indirect_bucket) {
					accel_hash->num_direct_entries--;
					entry->data = indirect_bucket;
					entry->indirect = 1;
				} else {
					entry->data = data;
				}
			}
			return entry;
		}
		entry = entry->next;
	}

	/* Does not exist, add a new entry */
	if (accel_hash->num_entries == accel_hash->max_num_entries) {
		return NULL;
	}

	entry = &accel_hash->hash_entries[accel_hash->num_entries++];
	if (indirect) {
		entry->data = indirect_bucket;
		entry->indirect = 1;
	} else {
		accel_hash->num_direct_entries++;
		entry->data = data;
		entry->indirect = 0;
	}
	entry->hash_value = hash_value;
	entry->key = key;
	entry->key_length = key_length;
	entry->next = accel_hash->hash_table[index];
	accel_hash->hash_table[index] = entry;
	return entry;
}

void* zend_accel_hash_find(zend_accel_hash *accel_hash, zend_string *key)
{
	return zend_accel_hash_find_ex(
		accel_hash,
		ZSTR_VAL(key),
		ZSTR_LEN(key),
		zend_string_hash_val(key),
		1);
}

zend_accel_hash_entry* zend_accel_hash_find_entry(zend_accel_hash *accel_hash, zend_string *key)
{
	return (zend_accel_hash_entry *)zend_accel_hash_find_ex(
		accel_hash,
		ZSTR_VAL(key),
		ZSTR_LEN(key),
		zend_string_hash_val(key),
		0);
}

void* zend_accel_hash_str_find(zend_accel_hash *accel_hash, const char *key, uint32_t key_length)
{
	return zend_accel_hash_find_ex(
		accel_hash,
		key,
		key_length,
		zend_inline_hash_func(key, key_length),
		1);
}

zend_accel_hash_entry* zend_accel_hash_str_find_entry(zend_accel_hash *accel_hash, const char *key, uint32_t key_length)
{
	return (zend_accel_hash_entry *)zend_accel_hash_find_ex(
		accel_hash,
		key,
		key_length,
		zend_inline_hash_func(key, key_length),
		0);
}

int zend_accel_hash_unlink(zend_accel_hash *accel_hash, const char *key, uint32_t key_length)
{
    zend_ulong hash_value;
    zend_ulong index;
    zend_accel_hash_entry *entry, *last_entry=NULL;

	hash_value = zend_inline_hash_func(key, key_length);
#ifndef ZEND_WIN32
	hash_value ^= ZCG(root_hash);
#endif
	index = hash_value % accel_hash->max_num_entries;

	entry = accel_hash->hash_table[index];
	while (entry) {
		if (entry->hash_value == hash_value
			&& entry->key_length == key_length
			&& !memcmp(entry->key, key, key_length)) {
			if (!entry->indirect) {
				accel_hash->num_direct_entries--;
			}
			if (last_entry) {
				last_entry->next = entry->next;
			} else {
				accel_hash->hash_table[index] = entry->next;
			}
			return SUCCESS;
		}
		last_entry = entry;
		entry = entry->next;
	}
	return FAILURE;
}

