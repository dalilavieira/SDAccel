#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
struct notifier_block {int dummy; } ;
struct TYPE_3__ {int id; void (* release ) (struct device*) ;int offline; int /*<<< orphan*/  groups; int /*<<< orphan*/ * bus; } ;
struct memory_block {int start_section_nr; unsigned long state; int end_section_nr; int section_count; TYPE_1__ dev; int /*<<< orphan*/  phys_device; } ;
struct mem_section {int dummy; } ;
struct device_attribute {int dummy; } ;
struct device {int dummy; } ;
typedef  size_t ssize_t ;

/* Variables and functions */
 size_t EINVAL ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 unsigned long MEM_OFFLINE ; 
 unsigned long MEM_ONLINE ; 
 int NR_MEM_SECTIONS ; 
 struct mem_section* __nr_to_section (int) ; 
 int __section_nr (struct mem_section*) ; 
 int /*<<< orphan*/  arch_get_memory_phys_device (unsigned long) ; 
 int atomic_notifier_chain_register (int /*<<< orphan*/ *,struct notifier_block*) ; 
 int /*<<< orphan*/  atomic_notifier_chain_unregister (int /*<<< orphan*/ *,struct notifier_block*) ; 
 int blocking_notifier_chain_register (int /*<<< orphan*/ *,struct notifier_block*) ; 
 int /*<<< orphan*/  blocking_notifier_chain_unregister (int /*<<< orphan*/ *,struct notifier_block*) ; 
 int device_register (TYPE_1__*) ; 
 struct memory_block* find_memory_block (struct mem_section*) ; 
 int /*<<< orphan*/  get_memory_block_size () ; 
 int /*<<< orphan*/  kfree (struct memory_block*) ; 
 struct memory_block* kzalloc (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mem_sysfs_mutex ; 
 int memhp_auto_online ; 
 int /*<<< orphan*/  memory_chain ; 
 int /*<<< orphan*/  memory_isolate_chain ; 
 int /*<<< orphan*/  memory_memblk_attr_groups ; 
 int /*<<< orphan*/  memory_subsys ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  present_section_nr (int) ; 
 int /*<<< orphan*/  put_device (TYPE_1__*) ; 
 unsigned long section_nr_to_pfn (int) ; 
 int sections_per_block ; 
 size_t sprintf (char*,char*,...) ; 
 scalar_t__ sysfs_streq (char const*,char*) ; 
 struct memory_block* to_memory_block (struct device*) ; 

__attribute__((used)) static inline int base_memory_block_id(int section_nr)
{
	return section_nr / sections_per_block;
}

int register_memory_notifier(struct notifier_block *nb)
{
	return blocking_notifier_chain_register(&memory_chain, nb);
}

void unregister_memory_notifier(struct notifier_block *nb)
{
	blocking_notifier_chain_unregister(&memory_chain, nb);
}

int register_memory_isolate_notifier(struct notifier_block *nb)
{
	return atomic_notifier_chain_register(&memory_isolate_chain, nb);
}

void unregister_memory_isolate_notifier(struct notifier_block *nb)
{
	atomic_notifier_chain_unregister(&memory_isolate_chain, nb);
}

__attribute__((used)) static void memory_block_release(struct device *dev)
{
	struct memory_block *mem = to_memory_block(dev);

	kfree(mem);
}

__attribute__((used)) static ssize_t
print_block_size(struct device *dev, struct device_attribute *attr,
		 char *buf)
{
	return sprintf(buf, "%lx\n", get_memory_block_size());
}

__attribute__((used)) static ssize_t
show_auto_online_blocks(struct device *dev, struct device_attribute *attr,
			char *buf)
{
	if (memhp_auto_online)
		return sprintf(buf, "online\n");
	else
		return sprintf(buf, "offline\n");
}

__attribute__((used)) static ssize_t
store_auto_online_blocks(struct device *dev, struct device_attribute *attr,
			 const char *buf, size_t count)
{
	if (sysfs_streq(buf, "online"))
		memhp_auto_online = true;
	else if (sysfs_streq(buf, "offline"))
		memhp_auto_online = false;
	else
		return -EINVAL;

	return count;
}

__attribute__((used)) static
int register_memory(struct memory_block *memory)
{
	int ret;

	memory->dev.bus = &memory_subsys;
	memory->dev.id = memory->start_section_nr / sections_per_block;
	memory->dev.release = memory_block_release;
	memory->dev.groups = memory_memblk_attr_groups;
	memory->dev.offline = memory->state == MEM_OFFLINE;

	ret = device_register(&memory->dev);
	if (ret)
		put_device(&memory->dev);

	return ret;
}

__attribute__((used)) static int init_memory_block(struct memory_block **memory,
			     struct mem_section *section, unsigned long state)
{
	struct memory_block *mem;
	unsigned long start_pfn;
	int scn_nr;
	int ret = 0;

	mem = kzalloc(sizeof(*mem), GFP_KERNEL);
	if (!mem)
		return -ENOMEM;

	scn_nr = __section_nr(section);
	mem->start_section_nr =
			base_memory_block_id(scn_nr) * sections_per_block;
	mem->end_section_nr = mem->start_section_nr + sections_per_block - 1;
	mem->state = state;
	start_pfn = section_nr_to_pfn(mem->start_section_nr);
	mem->phys_device = arch_get_memory_phys_device(start_pfn);

	ret = register_memory(mem);

	*memory = mem;
	return ret;
}

__attribute__((used)) static int add_memory_block(int base_section_nr)
{
	struct memory_block *mem;
	int i, ret, section_count = 0, section_nr;

	for (i = base_section_nr;
	     (i < base_section_nr + sections_per_block) && i < NR_MEM_SECTIONS;
	     i++) {
		if (!present_section_nr(i))
			continue;
		if (section_count == 0)
			section_nr = i;
		section_count++;
	}

	if (section_count == 0)
		return 0;
	ret = init_memory_block(&mem, __nr_to_section(section_nr), MEM_ONLINE);
	if (ret)
		return ret;
	mem->section_count = section_count;
	return 0;
}

int hotplug_memory_register(int nid, struct mem_section *section)
{
	int ret = 0;
	struct memory_block *mem;

	mutex_lock(&mem_sysfs_mutex);

	mem = find_memory_block(section);
	if (mem) {
		mem->section_count++;
		put_device(&mem->dev);
	} else {
		ret = init_memory_block(&mem, section, MEM_OFFLINE);
		if (ret)
			goto out;
		mem->section_count++;
	}

out:
	mutex_unlock(&mem_sysfs_mutex);
	return ret;
}

bool is_memblock_offlined(struct memory_block *mem)
{
	return mem->state == MEM_OFFLINE;
}

