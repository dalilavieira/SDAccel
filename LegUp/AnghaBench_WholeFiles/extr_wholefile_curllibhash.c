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
struct curl_llist_element {struct curl_hash_element* ptr; struct curl_llist_element* next; } ;
struct curl_llist {struct curl_llist_element* head; int /*<<< orphan*/  tail; } ;
struct curl_hash_iterator {int slot_index; struct curl_llist_element* current_element; struct curl_hash* hash; } ;
struct curl_hash_element {void* ptr; size_t key_len; int /*<<< orphan*/  key; int /*<<< orphan*/  list; } ;
struct curl_hash {int slots; struct curl_llist* table; scalar_t__ size; scalar_t__ (* comp_func ) (int /*<<< orphan*/ ,size_t,void*,size_t) ;int /*<<< orphan*/  (* dtor ) (void*) ;scalar_t__ hash_func; } ;
typedef  scalar_t__ hash_function ;
typedef  int /*<<< orphan*/  curl_llist_dtor ;
typedef  int /*<<< orphan*/  (* curl_hash_dtor ) (void*) ;
typedef  scalar_t__ (* comp_function ) (int /*<<< orphan*/ ,size_t,void*,size_t) ;

/* Variables and functions */
 void Curl_hash_clean_with_criterium (struct curl_hash*,void*,int (*) (void*,void*)) ; 
 int /*<<< orphan*/  Curl_llist_destroy (struct curl_llist*,void*) ; 
 int /*<<< orphan*/  Curl_llist_init (struct curl_llist*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  Curl_llist_insert_next (struct curl_llist*,int /*<<< orphan*/ ,struct curl_hash_element*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  Curl_llist_remove (struct curl_llist*,struct curl_llist_element*,void*) ; 
 int /*<<< orphan*/  Curl_safefree (struct curl_llist*) ; 
 struct curl_llist* FETCH_LIST (struct curl_hash*,void*,size_t) ; 
 int /*<<< orphan*/  free (struct curl_hash_element*) ; 
 void* malloc (int) ; 
 int /*<<< orphan*/  memcmp (void*,void*,size_t) ; 
 int /*<<< orphan*/  memcpy (int /*<<< orphan*/ ,void const*,size_t) ; 
 int /*<<< orphan*/  stub1 (void*) ; 
 scalar_t__ stub2 (int /*<<< orphan*/ ,size_t,void*,size_t) ; 
 scalar_t__ stub3 (int /*<<< orphan*/ ,size_t,void*,size_t) ; 
 scalar_t__ stub4 (int /*<<< orphan*/ ,size_t,void*,size_t) ; 

__attribute__((used)) static void
hash_element_dtor(void *user, void *element)
{
  struct curl_hash *h = (struct curl_hash *) user;
  struct curl_hash_element *e = (struct curl_hash_element *) element;

  if(e->ptr) {
    h->dtor(e->ptr);
    e->ptr = NULL;
  }

  e->key_len = 0;

  free(e);
}

int
Curl_hash_init(struct curl_hash *h,
               int slots,
               hash_function hfunc,
               comp_function comparator,
               curl_hash_dtor dtor)
{
  if(!slots || !hfunc || !comparator ||!dtor) {
    return 1; /* failure */
  }

  h->hash_func = hfunc;
  h->comp_func = comparator;
  h->dtor = dtor;
  h->size = 0;
  h->slots = slots;

  h->table = malloc(slots * sizeof(struct curl_llist));
  if(h->table) {
    int i;
    for(i = 0; i < slots; ++i)
      Curl_llist_init(&h->table[i], (curl_llist_dtor) hash_element_dtor);
    return 0; /* fine */
  }
  h->slots = 0;
  return 1; /* failure */
}

__attribute__((used)) static struct curl_hash_element *
mk_hash_element(const void *key, size_t key_len, const void *p)
{
  /* allocate the struct plus memory after it to store the key */
  struct curl_hash_element *he = malloc(sizeof(struct curl_hash_element) +
                                        key_len);
  if(he) {
    /* copy the key */
    memcpy(he->key, key, key_len);
    he->key_len = key_len;
    he->ptr = (void *) p;
  }
  return he;
}

void *
Curl_hash_add(struct curl_hash *h, void *key, size_t key_len, void *p)
{
  struct curl_hash_element  *he;
  struct curl_llist_element *le;
  struct curl_llist *l = FETCH_LIST(h, key, key_len);

  for(le = l->head; le; le = le->next) {
    he = (struct curl_hash_element *) le->ptr;
    if(h->comp_func(he->key, he->key_len, key, key_len)) {
      Curl_llist_remove(l, le, (void *)h);
      --h->size;
      break;
    }
  }

  he = mk_hash_element(key, key_len, p);
  if(he) {
    Curl_llist_insert_next(l, l->tail, he, &he->list);
    ++h->size;
    return p; /* return the new entry */
  }

  return NULL; /* failure */
}

int Curl_hash_delete(struct curl_hash *h, void *key, size_t key_len)
{
  struct curl_llist_element *le;
  struct curl_llist *l = FETCH_LIST(h, key, key_len);

  for(le = l->head; le; le = le->next) {
    struct curl_hash_element *he = le->ptr;
    if(h->comp_func(he->key, he->key_len, key, key_len)) {
      Curl_llist_remove(l, le, (void *) h);
      --h->size;
      return 0;
    }
  }
  return 1;
}

void *
Curl_hash_pick(struct curl_hash *h, void *key, size_t key_len)
{
  struct curl_llist_element *le;
  struct curl_llist *l;

  if(h) {
    l = FETCH_LIST(h, key, key_len);
    for(le = l->head; le; le = le->next) {
      struct curl_hash_element *he = le->ptr;
      if(h->comp_func(he->key, he->key_len, key, key_len)) {
        return he->ptr;
      }
    }
  }

  return NULL;
}

void
Curl_hash_destroy(struct curl_hash *h)
{
  int i;

  for(i = 0; i < h->slots; ++i) {
    Curl_llist_destroy(&h->table[i], (void *) h);
  }

  Curl_safefree(h->table);
  h->size = 0;
  h->slots = 0;
}

void
Curl_hash_clean(struct curl_hash *h)
{
  Curl_hash_clean_with_criterium(h, NULL, NULL);
}

void
Curl_hash_clean_with_criterium(struct curl_hash *h, void *user,
                               int (*comp)(void *, void *))
{
  struct curl_llist_element *le;
  struct curl_llist_element *lnext;
  struct curl_llist *list;
  int i;

  if(!h)
    return;

  for(i = 0; i < h->slots; ++i) {
    list = &h->table[i];
    le = list->head; /* get first list entry */
    while(le) {
      struct curl_hash_element *he = le->ptr;
      lnext = le->next;
      /* ask the callback function if we shall remove this entry or not */
      if(comp == NULL || comp(user, he->ptr)) {
        Curl_llist_remove(list, le, (void *) h);
        --h->size; /* one less entry in the hash now */
      }
      le = lnext;
    }
  }
}

size_t Curl_hash_str(void *key, size_t key_length, size_t slots_num)
{
  const char *key_str = (const char *) key;
  const char *end = key_str + key_length;
  size_t h = 5381;

  while(key_str < end) {
    h += h << 5;
    h ^= *key_str++;
  }

  return (h % slots_num);
}

size_t Curl_str_key_compare(void *k1, size_t key1_len,
                            void *k2, size_t key2_len)
{
  if((key1_len == key2_len) && !memcmp(k1, k2, key1_len))
    return 1;

  return 0;
}

void Curl_hash_start_iterate(struct curl_hash *hash,
                             struct curl_hash_iterator *iter)
{
  iter->hash = hash;
  iter->slot_index = 0;
  iter->current_element = NULL;
}

struct curl_hash_element *
Curl_hash_next_element(struct curl_hash_iterator *iter)
{
  struct curl_hash *h = iter->hash;

  /* Get the next element in the current list, if any */
  if(iter->current_element)
    iter->current_element = iter->current_element->next;

  /* If we have reached the end of the list, find the next one */
  if(!iter->current_element) {
    int i;
    for(i = iter->slot_index; i < h->slots; i++) {
      if(h->table[i].head) {
        iter->current_element = h->table[i].head;
        iter->slot_index = i + 1;
        break;
      }
    }
  }

  if(iter->current_element) {
    struct curl_hash_element *he = iter->current_element->ptr;
    return he;
  }
  iter->current_element = NULL;
  return NULL;
}

