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
struct string_list {char* string; } ;
struct hash_table {int hash_count; } ;
struct hash_bucket {int dummy; } ;

/* Variables and functions */
 int DEFAULT_HASH_SIZE ; 
 void* calloc (int,int) ; 
 int /*<<< orphan*/  free (void*) ; 
 int /*<<< orphan*/  warning (char*,char*) ; 

struct string_list *
new_string_list(size_t size)
{
	struct string_list *rval;

	rval = calloc(1, sizeof(struct string_list) + size);
	if (rval != NULL)
		rval->string = ((char *)rval) + sizeof(struct string_list);
	return (rval);
}

struct hash_table *
new_hash_table(int count)
{
	struct hash_table *rval;

	rval = calloc(1, sizeof(struct hash_table) -
	    (DEFAULT_HASH_SIZE * sizeof(struct hash_bucket *)) +
	    (count * sizeof(struct hash_bucket *)));
	if (rval == NULL)
		return (NULL);
	rval->hash_count = count;
	return (rval);
}

struct hash_bucket *
new_hash_bucket(void)
{
	struct hash_bucket *rval = calloc(1, sizeof(struct hash_bucket));

	return (rval);
}

void
dfree(void *ptr, char *name)
{
	if (!ptr) {
		warning("dfree %s: free on null pointer.", name);
		return;
	}
	free(ptr);
}

void
free_hash_bucket(struct hash_bucket *ptr, char *name)
{
	dfree(ptr, name);
}

