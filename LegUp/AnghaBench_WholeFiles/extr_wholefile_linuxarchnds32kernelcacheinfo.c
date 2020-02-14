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
struct cpu_cacheinfo {int num_levels; int num_leaves; struct cacheinfo* info_list; } ;
struct cacheinfo {unsigned int level; int type; int coherency_line_size; int number_of_sets; int ways_of_associativity; int size; int /*<<< orphan*/  attributes; } ;
typedef  enum cache_type { ____Placeholder_cache_type } cache_type ;

/* Variables and functions */
 int CACHE_LINE_SIZE (char) ; 
 int CACHE_SET (char) ; 
 int CACHE_TYPE_DATA ; 
 int CACHE_TYPE_INST ; 
 int CACHE_WAY (char) ; 
 int /*<<< orphan*/  CACHE_WRITE_BACK ; 
 char DCACHE ; 
 char ICACHE ; 
 struct cpu_cacheinfo* get_cpu_cacheinfo (unsigned int) ; 

__attribute__((used)) static void ci_leaf_init(struct cacheinfo *this_leaf,
			 enum cache_type type, unsigned int level)
{
	char cache_type = (type & CACHE_TYPE_INST ? ICACHE : DCACHE);

	this_leaf->level = level;
	this_leaf->type = type;
	this_leaf->coherency_line_size = CACHE_LINE_SIZE(cache_type);
	this_leaf->number_of_sets = CACHE_SET(cache_type);;
	this_leaf->ways_of_associativity = CACHE_WAY(cache_type);
	this_leaf->size = this_leaf->number_of_sets *
	    this_leaf->coherency_line_size * this_leaf->ways_of_associativity;
#if defined(CONFIG_CPU_DCACHE_WRITETHROUGH)
	this_leaf->attributes = CACHE_WRITE_THROUGH;
#else
	this_leaf->attributes = CACHE_WRITE_BACK;
#endif
}

int init_cache_level(unsigned int cpu)
{
	struct cpu_cacheinfo *this_cpu_ci = get_cpu_cacheinfo(cpu);

	/* Only 1 level and I/D cache seperate. */
	this_cpu_ci->num_levels = 1;
	this_cpu_ci->num_leaves = 2;
	return 0;
}

int populate_cache_leaves(unsigned int cpu)
{
	unsigned int level, idx;
	struct cpu_cacheinfo *this_cpu_ci = get_cpu_cacheinfo(cpu);
	struct cacheinfo *this_leaf = this_cpu_ci->info_list;

	for (idx = 0, level = 1; level <= this_cpu_ci->num_levels &&
	     idx < this_cpu_ci->num_leaves; idx++, level++) {
		ci_leaf_init(this_leaf++, CACHE_TYPE_DATA, level);
		ci_leaf_init(this_leaf++, CACHE_TYPE_INST, level);
	}
	return 0;
}

