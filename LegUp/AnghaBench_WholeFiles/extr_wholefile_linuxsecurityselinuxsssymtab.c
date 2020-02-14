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
struct symtab {scalar_t__ nprim; int /*<<< orphan*/  table; } ;
struct hashtab {int size; } ;

/* Variables and functions */
 int ENOMEM ; 
 int /*<<< orphan*/  hashtab_create (unsigned int (*) (struct hashtab*,void const*),int (*) (struct hashtab*,void const*,void const*),unsigned int) ; 
 int strcmp (char const*,char const*) ; 
 unsigned int strlen (char const*) ; 

__attribute__((used)) static unsigned int symhash(struct hashtab *h, const void *key)
{
	const char *p, *keyp;
	unsigned int size;
	unsigned int val;

	val = 0;
	keyp = key;
	size = strlen(keyp);
	for (p = keyp; (p - keyp) < size; p++)
		val = (val << 4 | (val >> (8*sizeof(unsigned int)-4))) ^ (*p);
	return val & (h->size - 1);
}

__attribute__((used)) static int symcmp(struct hashtab *h, const void *key1, const void *key2)
{
	const char *keyp1, *keyp2;

	keyp1 = key1;
	keyp2 = key2;
	return strcmp(keyp1, keyp2);
}

int symtab_init(struct symtab *s, unsigned int size)
{
	s->table = hashtab_create(symhash, symcmp, size);
	if (!s->table)
		return -ENOMEM;
	s->nprim = 0;
	return 0;
}

