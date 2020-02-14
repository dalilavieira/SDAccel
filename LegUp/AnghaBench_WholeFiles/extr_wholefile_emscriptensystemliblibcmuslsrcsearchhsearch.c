#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_8__   TYPE_1__ ;

/* Type definitions */
struct hsearch_data {TYPE_1__* __tab; } ;
struct TYPE_8__ {int mask; char* key; int used; struct TYPE_8__* entries; } ;
typedef  TYPE_1__ ENTRY ;
typedef  scalar_t__ ACTION ;

/* Variables and functions */
 scalar_t__ FIND ; 
 size_t MAXSIZE ; 
 size_t MINSIZE ; 
 int __hcreate_r (size_t,struct hsearch_data*) ; 
 void __hdestroy_r (struct hsearch_data*) ; 
 int __hsearch_r (TYPE_1__,scalar_t__,TYPE_1__**,struct hsearch_data*) ; 
 void* calloc (int,int) ; 
 int /*<<< orphan*/  free (TYPE_1__*) ; 
 struct hsearch_data htab ; 
 scalar_t__ strcmp (char*,char*) ; 

__attribute__((used)) static size_t keyhash(char *k)
{
	unsigned char *p = (void *)k;
	size_t h = 0;

	while (*p)
		h = 31*h + *p++;
	return h;
}

__attribute__((used)) static int resize(size_t nel, struct hsearch_data *htab)
{
	size_t newsize;
	size_t i, j;
	ENTRY *e, *newe;
	ENTRY *oldtab = htab->__tab->entries;
	ENTRY *oldend = htab->__tab->entries + htab->__tab->mask + 1;

	if (nel > MAXSIZE)
		nel = MAXSIZE;
	for (newsize = MINSIZE; newsize < nel; newsize *= 2);
	htab->__tab->entries = calloc(newsize, sizeof *htab->__tab->entries);
	if (!htab->__tab->entries) {
		htab->__tab->entries = oldtab;
		return 0;
	}
	htab->__tab->mask = newsize - 1;
	if (!oldtab)
		return 1;
	for (e = oldtab; e < oldend; e++)
		if (e->key) {
			for (i=keyhash(e->key),j=1; ; i+=j++) {
				newe = htab->__tab->entries + (i & htab->__tab->mask);
				if (!newe->key)
					break;
			}
			*newe = *e;
		}
	free(oldtab);
	return 1;
}

int hcreate(size_t nel)
{
	return __hcreate_r(nel, &htab);
}

void hdestroy(void)
{
	__hdestroy_r(&htab);
}

__attribute__((used)) static ENTRY *lookup(char *key, size_t hash, struct hsearch_data *htab)
{
	size_t i, j;
	ENTRY *e;

	for (i=hash,j=1; ; i+=j++) {
		e = htab->__tab->entries + (i & htab->__tab->mask);
		if (!e->key || strcmp(e->key, key) == 0)
			break;
	}
	return e;
}

ENTRY *hsearch(ENTRY item, ACTION action)
{
	ENTRY *e;

	__hsearch_r(item, action, &e, &htab);
	return e;
}

int __hcreate_r(size_t nel, struct hsearch_data *htab)
{
	int r;

	htab->__tab = calloc(1, sizeof *htab->__tab);
	if (!htab->__tab)
		return 0;
	r = resize(nel, htab);
	if (r == 0) {
		free(htab->__tab);
		htab->__tab = 0;
	}
	return r;
}

void __hdestroy_r(struct hsearch_data *htab)
{
	if (htab->__tab) free(htab->__tab->entries);
	free(htab->__tab);
	htab->__tab = 0;
}

int __hsearch_r(ENTRY item, ACTION action, ENTRY **retval, struct hsearch_data *htab)
{
	size_t hash = keyhash(item.key);
	ENTRY *e = lookup(item.key, hash, htab);

	if (e->key) {
		*retval = e;
		return 1;
	}
	if (action == FIND) {
		*retval = 0;
		return 0;
	}
	*e = item;
	if (++htab->__tab->used > htab->__tab->mask - htab->__tab->mask/4) {
		if (!resize(2*htab->__tab->used, htab)) {
			htab->__tab->used--;
			e->key = 0;
			*retval = 0;
			return 0;
		}
		e = lookup(item.key, hash, htab);
	}
	*retval = e;
	return 1;
}

