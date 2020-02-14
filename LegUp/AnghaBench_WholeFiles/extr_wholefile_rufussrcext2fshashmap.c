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
typedef  int uint32_t ;
struct ext2fs_hashmap_entry {size_t size; void (* free ) (void*) ;int (* hash ) (void const*,size_t) ;void* data; size_t key_len; struct ext2fs_hashmap_entry* next; struct ext2fs_hashmap_entry** entries; struct ext2fs_hashmap_entry* first; struct ext2fs_hashmap_entry* list_next; void const* key; struct ext2fs_hashmap_entry* last; struct ext2fs_hashmap_entry* list_prev; } ;
struct ext2fs_hashmap {size_t size; void (* free ) (void*) ;int (* hash ) (void const*,size_t) ;void* data; size_t key_len; struct ext2fs_hashmap* next; struct ext2fs_hashmap** entries; struct ext2fs_hashmap* first; struct ext2fs_hashmap* list_next; void const* key; struct ext2fs_hashmap* last; struct ext2fs_hashmap* list_prev; } ;

/* Variables and functions */
 struct ext2fs_hashmap_entry* calloc (int,int) ; 
 int /*<<< orphan*/  free (struct ext2fs_hashmap_entry*) ; 
 struct ext2fs_hashmap_entry* malloc (int) ; 
 int /*<<< orphan*/  memcmp (void const*,void const*,size_t) ; 
 int stub1 (void const*,size_t) ; 
 int stub2 (void const*,size_t) ; 
 void stub3 (void*) ; 

uint32_t ext2fs_djb2_hash(const void *str, size_t size)
{
	int c;
	const char *s = str;
	uint32_t hash = 5381;

	while (size-- > 0) {
		c = *s++;
		hash = ((hash << 5) + hash) + c;
	}
	return hash;
}

struct ext2fs_hashmap *ext2fs_hashmap_create(
				uint32_t(*hash_fct)(const void*, size_t),
				void(*free_fct)(void*), size_t size)
{
	struct ext2fs_hashmap *h = calloc(sizeof(struct ext2fs_hashmap) +
				sizeof(struct ext2fs_hashmap_entry) * size, 1);
	if (!h)
		return h;
	h->size = size;
	h->free = free_fct;
	h->hash = hash_fct;
	h->first = h->last = NULL;
	return h;
}

void ext2fs_hashmap_add(struct ext2fs_hashmap *h, void *data, const void *key,
			size_t key_len)
{
	uint32_t hash = h->hash(key, key_len) % h->size;
	struct ext2fs_hashmap_entry *e = malloc(sizeof(*e));

	if (!e)
		return;
	e->data = data;
	e->key = key;
	e->key_len = key_len;
	e->next = h->entries[hash];
	h->entries[hash] = e;

	e->list_prev = NULL;
	e->list_next = h->first;
	if (h->first)
		h->first->list_prev = e;
	h->first = e;
	if (!h->last)
		h->last = e;
}

void *ext2fs_hashmap_lookup(struct ext2fs_hashmap *h, const void *key,
			    size_t key_len)
{
	struct ext2fs_hashmap_entry *iter;
	uint32_t hash = h->hash(key, key_len) % h->size;

	for (iter = h->entries[hash]; iter; iter = iter->next)
		if (iter->key_len == key_len && !memcmp(iter->key, key, key_len))
			return iter->data;
	return NULL;
}

void *ext2fs_hashmap_iter_in_order(struct ext2fs_hashmap *h,
				   struct ext2fs_hashmap_entry **it)
{
	*it = *it ? (*it)->list_next : h->first;
	return *it ? (*it)->data : NULL;
}

void ext2fs_hashmap_free(struct ext2fs_hashmap *h)
{
	size_t	i;

	for (i = 0; i < h->size; ++i) {
		struct ext2fs_hashmap_entry *it = h->entries[i];
		while (it) {
			struct ext2fs_hashmap_entry *tmp = it->next;
			if (h->free)
				h->free(it->data);
			free(it);
			it = tmp;
		}
	}
	free(h);
}

