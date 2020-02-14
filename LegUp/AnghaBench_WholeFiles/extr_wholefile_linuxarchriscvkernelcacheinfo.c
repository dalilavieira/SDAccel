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
struct device_node {int dummy; } ;
struct cpu_cacheinfo {int num_levels; int num_leaves; struct cacheinfo* info_list; } ;
struct cacheinfo {unsigned int level; int type; int physical_line_partition; int attributes; } ;
typedef  enum cache_type { ____Placeholder_cache_type } cache_type ;

/* Variables and functions */
 int CACHE_READ_ALLOCATE ; 
 int CACHE_TYPE_DATA ; 
 int CACHE_TYPE_INST ; 
 int CACHE_TYPE_UNIFIED ; 
 int CACHE_WRITE_ALLOCATE ; 
 int CACHE_WRITE_BACK ; 
 struct cpu_cacheinfo* get_cpu_cacheinfo (unsigned int) ; 
 struct device_node* of_cpu_device_node_get (unsigned int) ; 
 int /*<<< orphan*/  of_device_is_compatible (struct device_node*,char*) ; 
 struct device_node* of_find_next_cache_node (struct device_node*) ; 
 scalar_t__ of_property_read_bool (struct device_node*,char*) ; 
 scalar_t__ of_property_read_u32 (struct device_node*,char*,int*) ; 

__attribute__((used)) static void ci_leaf_init(struct cacheinfo *this_leaf,
			 struct device_node *node,
			 enum cache_type type, unsigned int level)
{
	this_leaf->level = level;
	this_leaf->type = type;
	/* not a sector cache */
	this_leaf->physical_line_partition = 1;
	/* TODO: Add to DTS */
	this_leaf->attributes =
		CACHE_WRITE_BACK
		| CACHE_READ_ALLOCATE
		| CACHE_WRITE_ALLOCATE;
}

__attribute__((used)) static int __init_cache_level(unsigned int cpu)
{
	struct cpu_cacheinfo *this_cpu_ci = get_cpu_cacheinfo(cpu);
	struct device_node *np = of_cpu_device_node_get(cpu);
	int levels = 0, leaves = 0, level;

	if (of_property_read_bool(np, "cache-size"))
		++leaves;
	if (of_property_read_bool(np, "i-cache-size"))
		++leaves;
	if (of_property_read_bool(np, "d-cache-size"))
		++leaves;
	if (leaves > 0)
		levels = 1;

	while ((np = of_find_next_cache_node(np))) {
		if (!of_device_is_compatible(np, "cache"))
			break;
		if (of_property_read_u32(np, "cache-level", &level))
			break;
		if (level <= levels)
			break;
		if (of_property_read_bool(np, "cache-size"))
			++leaves;
		if (of_property_read_bool(np, "i-cache-size"))
			++leaves;
		if (of_property_read_bool(np, "d-cache-size"))
			++leaves;
		levels = level;
	}

	this_cpu_ci->num_levels = levels;
	this_cpu_ci->num_leaves = leaves;
	return 0;
}

__attribute__((used)) static int __populate_cache_leaves(unsigned int cpu)
{
	struct cpu_cacheinfo *this_cpu_ci = get_cpu_cacheinfo(cpu);
	struct cacheinfo *this_leaf = this_cpu_ci->info_list;
	struct device_node *np = of_cpu_device_node_get(cpu);
	int levels = 1, level = 1;

	if (of_property_read_bool(np, "cache-size"))
		ci_leaf_init(this_leaf++, np, CACHE_TYPE_UNIFIED, level);
	if (of_property_read_bool(np, "i-cache-size"))
		ci_leaf_init(this_leaf++, np, CACHE_TYPE_INST, level);
	if (of_property_read_bool(np, "d-cache-size"))
		ci_leaf_init(this_leaf++, np, CACHE_TYPE_DATA, level);

	while ((np = of_find_next_cache_node(np))) {
		if (!of_device_is_compatible(np, "cache"))
			break;
		if (of_property_read_u32(np, "cache-level", &level))
			break;
		if (level <= levels)
			break;
		if (of_property_read_bool(np, "cache-size"))
			ci_leaf_init(this_leaf++, np, CACHE_TYPE_UNIFIED, level);
		if (of_property_read_bool(np, "i-cache-size"))
			ci_leaf_init(this_leaf++, np, CACHE_TYPE_INST, level);
		if (of_property_read_bool(np, "d-cache-size"))
			ci_leaf_init(this_leaf++, np, CACHE_TYPE_DATA, level);
		levels = level;
	}

	return 0;
}

