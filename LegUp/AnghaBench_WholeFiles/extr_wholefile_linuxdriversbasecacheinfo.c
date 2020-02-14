#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_24__   TYPE_9__ ;
typedef  struct TYPE_23__   TYPE_8__ ;
typedef  struct TYPE_22__   TYPE_7__ ;
typedef  struct TYPE_21__   TYPE_6__ ;
typedef  struct TYPE_20__   TYPE_5__ ;
typedef  struct TYPE_19__   TYPE_4__ ;
typedef  struct TYPE_18__   TYPE_3__ ;
typedef  struct TYPE_17__   TYPE_2__ ;
typedef  struct TYPE_16__   TYPE_1__ ;
typedef  struct TYPE_15__   TYPE_12__ ;
typedef  struct TYPE_14__   TYPE_11__ ;
typedef  struct TYPE_13__   TYPE_10__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  umode_t ;
struct kobject {int dummy; } ;
struct device_attribute {int dummy; } ;
struct device {int dummy; } ;
struct cpumask {int dummy; } ;
struct cpu_cacheinfo {int dummy; } ;
struct cacheinfo {int level; int size; int type; unsigned int attributes; scalar_t__ physical_line_partition; scalar_t__ number_of_sets; scalar_t__ coherency_line_size; struct cpumask shared_cpu_map; } ;
struct attribute {int /*<<< orphan*/  mode; } ;
typedef  int ssize_t ;
struct TYPE_24__ {struct attribute attr; } ;
struct TYPE_23__ {struct attribute attr; } ;
struct TYPE_22__ {struct attribute attr; } ;
struct TYPE_21__ {struct attribute attr; } ;
struct TYPE_20__ {struct attribute attr; } ;
struct TYPE_19__ {struct attribute attr; } ;
struct TYPE_18__ {struct attribute attr; } ;
struct TYPE_17__ {struct attribute attr; } ;
struct TYPE_16__ {struct attribute attr; } ;
struct TYPE_15__ {struct attribute attr; } ;
struct TYPE_14__ {struct attribute attr; } ;
struct TYPE_13__ {struct attribute attr; } ;

/* Variables and functions */
 int CACHE_ALLOCATE_POLICY_MASK ; 
 int CACHE_ID ; 
 unsigned int CACHE_READ_ALLOCATE ; 
#define  CACHE_TYPE_DATA 130 
#define  CACHE_TYPE_INST 129 
#define  CACHE_TYPE_UNIFIED 128 
 unsigned int CACHE_WRITE_ALLOCATE ; 
 unsigned int CACHE_WRITE_BACK ; 
 int CACHE_WRITE_POLICY_MASK ; 
 unsigned int CACHE_WRITE_THROUGH ; 
 int EINVAL ; 
 struct cpu_cacheinfo* ci_cacheinfo (unsigned int) ; 
 int cpumap_print_to_pagebuf (int,char*,struct cpumask const*) ; 
 int /*<<< orphan*/  cpumask_empty (struct cpumask const*) ; 
 TYPE_12__ dev_attr_allocation_policy ; 
 TYPE_11__ dev_attr_coherency_line_size ; 
 TYPE_10__ dev_attr_id ; 
 TYPE_9__ dev_attr_level ; 
 TYPE_8__ dev_attr_number_of_sets ; 
 TYPE_7__ dev_attr_physical_line_partition ; 
 TYPE_6__ dev_attr_shared_cpu_list ; 
 TYPE_5__ dev_attr_shared_cpu_map ; 
 TYPE_4__ dev_attr_size ; 
 TYPE_3__ dev_attr_type ; 
 TYPE_2__ dev_attr_ways_of_associativity ; 
 TYPE_1__ dev_attr_write_policy ; 
 struct cacheinfo* dev_get_drvdata (struct device*) ; 
 struct device* kobj_to_dev (struct kobject*) ; 
 int sprintf (char*,char*,...) ; 

struct cpu_cacheinfo *get_cpu_cacheinfo(unsigned int cpu)
{
	return ci_cacheinfo(cpu);
}

__attribute__((used)) static inline int cache_setup_of_node(unsigned int cpu) { return 0; }

__attribute__((used)) static inline bool cache_leaves_are_shared(struct cacheinfo *this_leaf,
					   struct cacheinfo *sib_leaf)
{
	/*
	 * For non-DT/ACPI systems, assume unique level 1 caches, system-wide
	 * shared caches for all other levels. This will be used only if
	 * arch specific code has not populated shared_cpu_map
	 */
	return !(this_leaf->level == 1);
}

__attribute__((used)) static ssize_t size_show(struct device *dev,
			 struct device_attribute *attr, char *buf)
{
	struct cacheinfo *this_leaf = dev_get_drvdata(dev);

	return sprintf(buf, "%uK\n", this_leaf->size >> 10);
}

__attribute__((used)) static ssize_t shared_cpumap_show_func(struct device *dev, bool list, char *buf)
{
	struct cacheinfo *this_leaf = dev_get_drvdata(dev);
	const struct cpumask *mask = &this_leaf->shared_cpu_map;

	return cpumap_print_to_pagebuf(list, buf, mask);
}

__attribute__((used)) static ssize_t shared_cpu_map_show(struct device *dev,
				   struct device_attribute *attr, char *buf)
{
	return shared_cpumap_show_func(dev, false, buf);
}

__attribute__((used)) static ssize_t shared_cpu_list_show(struct device *dev,
				    struct device_attribute *attr, char *buf)
{
	return shared_cpumap_show_func(dev, true, buf);
}

__attribute__((used)) static ssize_t type_show(struct device *dev,
			 struct device_attribute *attr, char *buf)
{
	struct cacheinfo *this_leaf = dev_get_drvdata(dev);

	switch (this_leaf->type) {
	case CACHE_TYPE_DATA:
		return sprintf(buf, "Data\n");
	case CACHE_TYPE_INST:
		return sprintf(buf, "Instruction\n");
	case CACHE_TYPE_UNIFIED:
		return sprintf(buf, "Unified\n");
	default:
		return -EINVAL;
	}
}

__attribute__((used)) static ssize_t allocation_policy_show(struct device *dev,
				      struct device_attribute *attr, char *buf)
{
	struct cacheinfo *this_leaf = dev_get_drvdata(dev);
	unsigned int ci_attr = this_leaf->attributes;
	int n = 0;

	if ((ci_attr & CACHE_READ_ALLOCATE) && (ci_attr & CACHE_WRITE_ALLOCATE))
		n = sprintf(buf, "ReadWriteAllocate\n");
	else if (ci_attr & CACHE_READ_ALLOCATE)
		n = sprintf(buf, "ReadAllocate\n");
	else if (ci_attr & CACHE_WRITE_ALLOCATE)
		n = sprintf(buf, "WriteAllocate\n");
	return n;
}

__attribute__((used)) static ssize_t write_policy_show(struct device *dev,
				 struct device_attribute *attr, char *buf)
{
	struct cacheinfo *this_leaf = dev_get_drvdata(dev);
	unsigned int ci_attr = this_leaf->attributes;
	int n = 0;

	if (ci_attr & CACHE_WRITE_THROUGH)
		n = sprintf(buf, "WriteThrough\n");
	else if (ci_attr & CACHE_WRITE_BACK)
		n = sprintf(buf, "WriteBack\n");
	return n;
}

__attribute__((used)) static umode_t
cache_default_attrs_is_visible(struct kobject *kobj,
			       struct attribute *attr, int unused)
{
	struct device *dev = kobj_to_dev(kobj);
	struct cacheinfo *this_leaf = dev_get_drvdata(dev);
	const struct cpumask *mask = &this_leaf->shared_cpu_map;
	umode_t mode = attr->mode;

	if ((attr == &dev_attr_id.attr) && (this_leaf->attributes & CACHE_ID))
		return mode;
	if ((attr == &dev_attr_type.attr) && this_leaf->type)
		return mode;
	if ((attr == &dev_attr_level.attr) && this_leaf->level)
		return mode;
	if ((attr == &dev_attr_shared_cpu_map.attr) && !cpumask_empty(mask))
		return mode;
	if ((attr == &dev_attr_shared_cpu_list.attr) && !cpumask_empty(mask))
		return mode;
	if ((attr == &dev_attr_coherency_line_size.attr) &&
	    this_leaf->coherency_line_size)
		return mode;
	if ((attr == &dev_attr_ways_of_associativity.attr) &&
	    this_leaf->size) /* allow 0 = full associativity */
		return mode;
	if ((attr == &dev_attr_number_of_sets.attr) &&
	    this_leaf->number_of_sets)
		return mode;
	if ((attr == &dev_attr_size.attr) && this_leaf->size)
		return mode;
	if ((attr == &dev_attr_write_policy.attr) &&
	    (this_leaf->attributes & CACHE_WRITE_POLICY_MASK))
		return mode;
	if ((attr == &dev_attr_allocation_policy.attr) &&
	    (this_leaf->attributes & CACHE_ALLOCATE_POLICY_MASK))
		return mode;
	if ((attr == &dev_attr_physical_line_partition.attr) &&
	    this_leaf->physical_line_partition)
		return mode;

	return 0;
}

