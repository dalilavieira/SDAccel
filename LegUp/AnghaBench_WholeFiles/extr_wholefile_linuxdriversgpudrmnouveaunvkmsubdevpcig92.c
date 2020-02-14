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
struct nvkm_pci {int dummy; } ;
struct nvkm_device {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  g92_pci_func ; 
 int nvkm_pci_new_ (int /*<<< orphan*/ *,struct nvkm_device*,int,struct nvkm_pci**) ; 
 int nvkm_pci_rd32 (struct nvkm_pci*,int) ; 

int
g92_pcie_version_supported(struct nvkm_pci *pci)
{
	if ((nvkm_pci_rd32(pci, 0x460) & 0x200) == 0x200)
		return 2;
	return 1;
}

int
g92_pci_new(struct nvkm_device *device, int index, struct nvkm_pci **ppci)
{
	return nvkm_pci_new_(&g92_pci_func, device, index, ppci);
}

