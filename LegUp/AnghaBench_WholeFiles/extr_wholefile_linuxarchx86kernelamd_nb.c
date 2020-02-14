#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_2__ ;
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
typedef  int u8 ;
typedef  int u32 ;
typedef  int u16 ;
struct pci_device_id {int dummy; } ;
struct pci_dev {int dummy; } ;
struct amd_northbridge {struct pci_dev* link; struct pci_dev* misc; struct pci_dev* root; } ;
struct TYPE_4__ {int num; unsigned int flags; struct amd_northbridge* nb; } ;
struct TYPE_3__ {int x86; int x86_model; int x86_stepping; } ;

/* Variables and functions */
 unsigned int AMD_NB_GART ; 
 unsigned int AMD_NB_L3_INDEX_DISABLE ; 
 unsigned int AMD_NB_L3_PARTITIONING ; 
 int ENODEV ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int /*<<< orphan*/  PCI_ANY_ID ; 
 scalar_t__ amd_gart_present () ; 
 struct pci_device_id* amd_nb_link_ids ; 
 struct pci_device_id* amd_nb_misc_ids ; 
 TYPE_2__ amd_northbridges ; 
 struct pci_device_id* amd_root_ids ; 
 TYPE_1__ boot_cpu_data ; 
 int /*<<< orphan*/  cpuid_edx (int) ; 
 struct amd_northbridge* kcalloc (int,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  msr_set_bit (int,int) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 struct pci_dev* pci_get_device (int /*<<< orphan*/ ,int /*<<< orphan*/ ,struct pci_dev*) ; 
 int /*<<< orphan*/  pci_match_id (struct pci_device_id const*,struct pci_dev*) ; 
 int pci_read_config_dword (struct pci_dev*,int,int*) ; 
 int pci_write_config_dword (struct pci_dev*,int,int) ; 
 int /*<<< orphan*/  pr_warn (char*,...) ; 
 int /*<<< orphan*/  smn_mutex ; 

u16 amd_nb_num(void)
{
	return amd_northbridges.num;
}

bool amd_nb_has_feature(unsigned int feature)
{
	return ((amd_northbridges.flags & feature) == feature);
}

struct amd_northbridge *node_to_amd_nb(int node)
{
	return (node < amd_northbridges.num) ? &amd_northbridges.nb[node] : NULL;
}

__attribute__((used)) static struct pci_dev *next_northbridge(struct pci_dev *dev,
					const struct pci_device_id *ids)
{
	do {
		dev = pci_get_device(PCI_ANY_ID, PCI_ANY_ID, dev);
		if (!dev)
			break;
	} while (!pci_match_id(ids, dev));
	return dev;
}

__attribute__((used)) static int __amd_smn_rw(u16 node, u32 address, u32 *value, bool write)
{
	struct pci_dev *root;
	int err = -ENODEV;

	if (node >= amd_northbridges.num)
		goto out;

	root = node_to_amd_nb(node)->root;
	if (!root)
		goto out;

	mutex_lock(&smn_mutex);

	err = pci_write_config_dword(root, 0x60, address);
	if (err) {
		pr_warn("Error programming SMN address 0x%x.\n", address);
		goto out_unlock;
	}

	err = (write ? pci_write_config_dword(root, 0x64, *value)
		     : pci_read_config_dword(root, 0x64, value));
	if (err)
		pr_warn("Error %s SMN address 0x%x.\n",
			(write ? "writing to" : "reading from"), address);

out_unlock:
	mutex_unlock(&smn_mutex);

out:
	return err;
}

int amd_smn_read(u16 node, u32 address, u32 *value)
{
	return __amd_smn_rw(node, address, value, false);
}

int amd_smn_write(u16 node, u32 address, u32 value)
{
	return __amd_smn_rw(node, address, &value, true);
}

int amd_df_indirect_read(u16 node, u8 func, u16 reg, u8 instance_id, u32 *lo)
{
	struct pci_dev *F4;
	u32 ficaa;
	int err = -ENODEV;

	if (node >= amd_northbridges.num)
		goto out;

	F4 = node_to_amd_nb(node)->link;
	if (!F4)
		goto out;

	ficaa  = 1;
	ficaa |= reg & 0x3FC;
	ficaa |= (func & 0x7) << 11;
	ficaa |= instance_id << 16;

	mutex_lock(&smn_mutex);

	err = pci_write_config_dword(F4, 0x5C, ficaa);
	if (err) {
		pr_warn("Error writing DF Indirect FICAA, FICAA=0x%x\n", ficaa);
		goto out_unlock;
	}

	err = pci_read_config_dword(F4, 0x98, lo);
	if (err)
		pr_warn("Error reading DF Indirect FICAD LO, FICAA=0x%x.\n", ficaa);

out_unlock:
	mutex_unlock(&smn_mutex);

out:
	return err;
}

int amd_cache_northbridges(void)
{
	u16 i = 0;
	struct amd_northbridge *nb;
	struct pci_dev *root, *misc, *link;

	if (amd_northbridges.num)
		return 0;

	misc = NULL;
	while ((misc = next_northbridge(misc, amd_nb_misc_ids)) != NULL)
		i++;

	if (!i)
		return -ENODEV;

	nb = kcalloc(i, sizeof(struct amd_northbridge), GFP_KERNEL);
	if (!nb)
		return -ENOMEM;

	amd_northbridges.nb = nb;
	amd_northbridges.num = i;

	link = misc = root = NULL;
	for (i = 0; i != amd_northbridges.num; i++) {
		node_to_amd_nb(i)->root = root =
			next_northbridge(root, amd_root_ids);
		node_to_amd_nb(i)->misc = misc =
			next_northbridge(misc, amd_nb_misc_ids);
		node_to_amd_nb(i)->link = link =
			next_northbridge(link, amd_nb_link_ids);
	}

	if (amd_gart_present())
		amd_northbridges.flags |= AMD_NB_GART;

	/*
	 * Check for L3 cache presence.
	 */
	if (!cpuid_edx(0x80000006))
		return 0;

	/*
	 * Some CPU families support L3 Cache Index Disable. There are some
	 * limitations because of E382 and E388 on family 0x10.
	 */
	if (boot_cpu_data.x86 == 0x10 &&
	    boot_cpu_data.x86_model >= 0x8 &&
	    (boot_cpu_data.x86_model > 0x9 ||
	     boot_cpu_data.x86_stepping >= 0x1))
		amd_northbridges.flags |= AMD_NB_L3_INDEX_DISABLE;

	if (boot_cpu_data.x86 == 0x15)
		amd_northbridges.flags |= AMD_NB_L3_INDEX_DISABLE;

	/* L3 cache partitioning is supported on family 0x15 */
	if (boot_cpu_data.x86 == 0x15)
		amd_northbridges.flags |= AMD_NB_L3_PARTITIONING;

	return 0;
}

__attribute__((used)) static void __fix_erratum_688(void *info)
{
#define MSR_AMD64_IC_CFG 0xC0011021

	msr_set_bit(MSR_AMD64_IC_CFG, 3);
	msr_set_bit(MSR_AMD64_IC_CFG, 14);
}

