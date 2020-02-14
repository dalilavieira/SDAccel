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
typedef  int u32 ;
struct drmem_lmb {int flags; int aa_index; } ;
struct device_node {int dummy; } ;
struct assoc_arrays {int n_arrays; int array_sz; int /*<<< orphan*/  const* arrays; } ;
typedef  int /*<<< orphan*/  const __be32 ;

/* Variables and functions */
 int DRCONF_MEM_AI_INVALID ; 
 int MAX_NUMNODES ; 
 int /*<<< orphan*/  WARN (int,char*,int,int) ; 
 int /*<<< orphan*/  WARN_ON (int) ; 
 int be32_to_cpu (int /*<<< orphan*/ ) ; 
 int cpu_first_thread_sibling (int) ; 
 scalar_t__ cpu_is_offline (int) ; 
 scalar_t__ cpu_present (unsigned long) ; 
 int cpu_to_node (int) ; 
 int** distance_lookup_table ; 
 int /*<<< orphan*/ * distance_ref_points ; 
 int distance_ref_points_depth ; 
 int first_online_node ; 
 int /*<<< orphan*/  form1_affinity ; 
 int /*<<< orphan*/  map_cpu_to_node (unsigned long,int) ; 
 int min_common_depth ; 
 int /*<<< orphan*/  node_possible (int) ; 
 int* numa_cpu_lookup_table ; 
 struct device_node* of_find_node_by_path (char*) ; 
 int /*<<< orphan*/  const* of_get_associativity (struct device_node*) ; 
 struct device_node* of_get_cpu_node (unsigned long,int /*<<< orphan*/ *) ; 
 struct device_node* of_get_next_parent (struct device_node*) ; 
 int /*<<< orphan*/  const* of_get_property (struct device_node*,char*,int*) ; 
 int /*<<< orphan*/  of_node_get (struct device_node*) ; 
 int /*<<< orphan*/  of_node_put (struct device_node*) ; 
 int of_read_number (int /*<<< orphan*/  const*,int) ; 
 int threads_per_core ; 

__attribute__((used)) static void initialize_distance_lookup_table(int nid,
		const __be32 *associativity)
{
	int i;

	if (!form1_affinity)
		return;

	for (i = 0; i < distance_ref_points_depth; i++) {
		const __be32 *entry;

		entry = &associativity[be32_to_cpu(distance_ref_points[i]) - 1];
		distance_lookup_table[nid][i] = of_read_number(entry, 1);
	}
}

__attribute__((used)) static int associativity_to_nid(const __be32 *associativity)
{
	int nid = -1;

	if (min_common_depth == -1)
		goto out;

	if (of_read_number(associativity, 1) >= min_common_depth)
		nid = of_read_number(&associativity[min_common_depth], 1);

	/* POWER4 LPAR uses 0xffff as invalid node */
	if (nid == 0xffff || nid >= MAX_NUMNODES)
		nid = -1;

	if (nid > 0 &&
		of_read_number(associativity, 1) >= distance_ref_points_depth) {
		/*
		 * Skip the length field and send start of associativity array
		 */
		initialize_distance_lookup_table(nid, associativity + 1);
	}

out:
	return nid;
}

__attribute__((used)) static int of_node_to_nid_single(struct device_node *device)
{
	int nid = -1;
	const __be32 *tmp;

	tmp = of_get_associativity(device);
	if (tmp)
		nid = associativity_to_nid(tmp);
	return nid;
}

int of_node_to_nid(struct device_node *device)
{
	int nid = -1;

	of_node_get(device);
	while (device) {
		nid = of_node_to_nid_single(device);
		if (nid != -1)
			break;

		device = of_get_next_parent(device);
	}
	of_node_put(device);

	return nid;
}

__attribute__((used)) static int of_get_assoc_arrays(struct assoc_arrays *aa)
{
	struct device_node *memory;
	const __be32 *prop;
	u32 len;

	memory = of_find_node_by_path("/ibm,dynamic-reconfiguration-memory");
	if (!memory)
		return -1;

	prop = of_get_property(memory, "ibm,associativity-lookup-arrays", &len);
	if (!prop || len < 2 * sizeof(unsigned int)) {
		of_node_put(memory);
		return -1;
	}

	aa->n_arrays = of_read_number(prop++, 1);
	aa->array_sz = of_read_number(prop++, 1);

	of_node_put(memory);

	/* Now that we know the number of arrays and size of each array,
	 * revalidate the size of the property read in.
	 */
	if (len < (aa->n_arrays * aa->array_sz + 2) * sizeof(unsigned int))
		return -1;

	aa->arrays = prop;
	return 0;
}

__attribute__((used)) static int of_drconf_to_nid_single(struct drmem_lmb *lmb)
{
	struct assoc_arrays aa = { .arrays = NULL };
	int default_nid = 0;
	int nid = default_nid;
	int rc, index;

	rc = of_get_assoc_arrays(&aa);
	if (rc)
		return default_nid;

	if (min_common_depth > 0 && min_common_depth <= aa.array_sz &&
	    !(lmb->flags & DRCONF_MEM_AI_INVALID) &&
	    lmb->aa_index < aa.n_arrays) {
		index = lmb->aa_index * aa.array_sz + min_common_depth - 1;
		nid = of_read_number(&aa.arrays[index], 1);

		if (nid == 0xffff || nid >= MAX_NUMNODES)
			nid = default_nid;

		if (nid > 0) {
			index = lmb->aa_index * aa.array_sz;
			initialize_distance_lookup_table(nid,
							&aa.arrays[index]);
		}
	}

	return nid;
}

__attribute__((used)) static int numa_setup_cpu(unsigned long lcpu)
{
	int nid = -1;
	struct device_node *cpu;

	/*
	 * If a valid cpu-to-node mapping is already available, use it
	 * directly instead of querying the firmware, since it represents
	 * the most recent mapping notified to us by the platform (eg: VPHN).
	 */
	if ((nid = numa_cpu_lookup_table[lcpu]) >= 0) {
		map_cpu_to_node(lcpu, nid);
		return nid;
	}

	cpu = of_get_cpu_node(lcpu, NULL);

	if (!cpu) {
		WARN_ON(1);
		if (cpu_present(lcpu))
			goto out_present;
		else
			goto out;
	}

	nid = of_node_to_nid_single(cpu);

out_present:
	if (nid < 0 || !node_possible(nid))
		nid = first_online_node;

	map_cpu_to_node(lcpu, nid);
	of_node_put(cpu);
out:
	return nid;
}

__attribute__((used)) static void verify_cpu_node_mapping(int cpu, int node)
{
	int base, sibling, i;

	/* Verify that all the threads in the core belong to the same node */
	base = cpu_first_thread_sibling(cpu);

	for (i = 0; i < threads_per_core; i++) {
		sibling = base + i;

		if (sibling == cpu || cpu_is_offline(sibling))
			continue;

		if (cpu_to_node(sibling) != node) {
			WARN(1, "CPU thread siblings %d and %d don't belong"
				" to the same node!\n", cpu, sibling);
			break;
		}
	}
}

__attribute__((used)) static int ppc_numa_cpu_prepare(unsigned int cpu)
{
	int nid;

	nid = numa_setup_cpu(cpu);
	verify_cpu_node_mapping(cpu, nid);
	return 0;
}

__attribute__((used)) static int ppc_numa_cpu_dead(unsigned int cpu)
{
#ifdef CONFIG_HOTPLUG_CPU
	unmap_cpu_from_node(cpu);
#endif
	return 0;
}

