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
union cache_topology {unsigned long raw; struct cache_info* ci; } ;
struct seq_file {int dummy; } ;
struct cpu_cacheinfo {int num_leaves; unsigned int num_levels; struct cacheinfo* info_list; } ;
struct cacheinfo {int level; size_t type; int disable_sysfs; int size; int coherency_line_size; int ways_of_associativity; int number_of_sets; int /*<<< orphan*/  shared_cpu_map; } ;
struct cache_info {scalar_t__ scope; size_t type; } ;
typedef  enum cache_type { ____Placeholder_cache_type } cache_type ;

/* Variables and functions */
 int CACHE_MAX_LEVEL ; 
 scalar_t__ CACHE_SCOPE_PRIVATE ; 
 scalar_t__ CACHE_SCOPE_SHARED ; 
 int CACHE_TI_INSTRUCTION ; 
 int CACHE_TI_UNIFIED ; 
 int CACHE_TYPE_DATA ; 
 int CACHE_TYPE_INST ; 
 int CACHE_TYPE_NOCACHE ; 
 int CACHE_TYPE_SEPARATE ; 
 int /*<<< orphan*/  ECAG_CACHE_ATTRIBUTE ; 
 int EINVAL ; 
 int EOPNOTSUPP ; 
 int EXTRACT_ASSOCIATIVITY ; 
 int EXTRACT_LINE_SIZE ; 
 int EXTRACT_SIZE ; 
 int EXTRACT_TOPOLOGY ; 
 unsigned long __ecag (int /*<<< orphan*/ ,int) ; 
 int* cache_type_map ; 
 int* cache_type_string ; 
 int /*<<< orphan*/  cpu_online_mask ; 
 unsigned int cpumask_any (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  cpumask_set_cpu (int,int /*<<< orphan*/ *) ; 
 struct cpu_cacheinfo* get_cpu_cacheinfo (unsigned int) ; 
 int /*<<< orphan*/  seq_printf (struct seq_file*,char*,...) ; 
 int /*<<< orphan*/  seq_puts (struct seq_file*,char*) ; 
 int /*<<< orphan*/  test_facility (int) ; 

void show_cacheinfo(struct seq_file *m)
{
	struct cpu_cacheinfo *this_cpu_ci;
	struct cacheinfo *cache;
	int idx;

	if (!test_facility(34))
		return;
	this_cpu_ci = get_cpu_cacheinfo(cpumask_any(cpu_online_mask));
	for (idx = 0; idx < this_cpu_ci->num_leaves; idx++) {
		cache = this_cpu_ci->info_list + idx;
		seq_printf(m, "cache%-11d: ", idx);
		seq_printf(m, "level=%d ", cache->level);
		seq_printf(m, "type=%s ", cache_type_string[cache->type]);
		seq_printf(m, "scope=%s ",
			   cache->disable_sysfs ? "Shared" : "Private");
		seq_printf(m, "size=%dK ", cache->size >> 10);
		seq_printf(m, "line_size=%u ", cache->coherency_line_size);
		seq_printf(m, "associativity=%d", cache->ways_of_associativity);
		seq_puts(m, "\n");
	}
}

__attribute__((used)) static inline enum cache_type get_cache_type(struct cache_info *ci, int level)
{
	if (level >= CACHE_MAX_LEVEL)
		return CACHE_TYPE_NOCACHE;
	ci += level;
	if (ci->scope != CACHE_SCOPE_SHARED && ci->scope != CACHE_SCOPE_PRIVATE)
		return CACHE_TYPE_NOCACHE;
	return cache_type_map[ci->type];
}

__attribute__((used)) static inline unsigned long ecag(int ai, int li, int ti)
{
	return __ecag(ECAG_CACHE_ATTRIBUTE, ai << 4 | li << 1 | ti);
}

__attribute__((used)) static void ci_leaf_init(struct cacheinfo *this_leaf, int private,
			 enum cache_type type, unsigned int level, int cpu)
{
	int ti, num_sets;

	if (type == CACHE_TYPE_INST)
		ti = CACHE_TI_INSTRUCTION;
	else
		ti = CACHE_TI_UNIFIED;
	this_leaf->level = level + 1;
	this_leaf->type = type;
	this_leaf->coherency_line_size = ecag(EXTRACT_LINE_SIZE, level, ti);
	this_leaf->ways_of_associativity = ecag(EXTRACT_ASSOCIATIVITY, level, ti);
	this_leaf->size = ecag(EXTRACT_SIZE, level, ti);
	num_sets = this_leaf->size / this_leaf->coherency_line_size;
	num_sets /= this_leaf->ways_of_associativity;
	this_leaf->number_of_sets = num_sets;
	cpumask_set_cpu(cpu, &this_leaf->shared_cpu_map);
	if (!private)
		this_leaf->disable_sysfs = true;
}

int init_cache_level(unsigned int cpu)
{
	struct cpu_cacheinfo *this_cpu_ci = get_cpu_cacheinfo(cpu);
	unsigned int level = 0, leaves = 0;
	union cache_topology ct;
	enum cache_type ctype;

	if (!test_facility(34))
		return -EOPNOTSUPP;
	if (!this_cpu_ci)
		return -EINVAL;
	ct.raw = ecag(EXTRACT_TOPOLOGY, 0, 0);
	do {
		ctype = get_cache_type(&ct.ci[0], level);
		if (ctype == CACHE_TYPE_NOCACHE)
			break;
		/* Separate instruction and data caches */
		leaves += (ctype == CACHE_TYPE_SEPARATE) ? 2 : 1;
	} while (++level < CACHE_MAX_LEVEL);
	this_cpu_ci->num_levels = level;
	this_cpu_ci->num_leaves = leaves;
	return 0;
}

int populate_cache_leaves(unsigned int cpu)
{
	struct cpu_cacheinfo *this_cpu_ci = get_cpu_cacheinfo(cpu);
	struct cacheinfo *this_leaf = this_cpu_ci->info_list;
	unsigned int level, idx, pvt;
	union cache_topology ct;
	enum cache_type ctype;

	if (!test_facility(34))
		return -EOPNOTSUPP;
	ct.raw = ecag(EXTRACT_TOPOLOGY, 0, 0);
	for (idx = 0, level = 0; level < this_cpu_ci->num_levels &&
	     idx < this_cpu_ci->num_leaves; idx++, level++) {
		if (!this_leaf)
			return -EINVAL;
		pvt = (ct.ci[level].scope == CACHE_SCOPE_PRIVATE) ? 1 : 0;
		ctype = get_cache_type(&ct.ci[0], level);
		if (ctype == CACHE_TYPE_SEPARATE) {
			ci_leaf_init(this_leaf++, pvt, CACHE_TYPE_DATA, level, cpu);
			ci_leaf_init(this_leaf++, pvt, CACHE_TYPE_INST, level, cpu);
		} else {
			ci_leaf_init(this_leaf++, pvt, ctype, level, cpu);
		}
	}
	return 0;
}

