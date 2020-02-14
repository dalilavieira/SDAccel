#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
typedef  int u8 ;
struct TYPE_2__ {struct nvkm_device* device; } ;
struct nvkm_pci {TYPE_1__ subdev; } ;
struct nvkm_device {int dummy; } ;
typedef  enum nvkm_pcie_speed { ____Placeholder_nvkm_pcie_speed } nvkm_pcie_speed ;

/* Variables and functions */
 scalar_t__ NVKM_PCIE_SPEED_5_0 ; 
 scalar_t__ g84_pcie_cur_speed (struct nvkm_pci*) ; 
 int /*<<< orphan*/  g84_pcie_set_link_speed (struct nvkm_pci*,int) ; 
 int /*<<< orphan*/  gf100_pci_func ; 
 int /*<<< orphan*/  nvkm_mask (struct nvkm_device*,int,int,int) ; 
 int nvkm_pci_new_ (int /*<<< orphan*/ *,struct nvkm_device*,int,struct nvkm_pci**) ; 
 int /*<<< orphan*/  nvkm_pci_wr08 (struct nvkm_pci*,int,int) ; 
 int nvkm_rd32 (struct nvkm_device*,int) ; 

__attribute__((used)) static void
gf100_pci_msi_rearm(struct nvkm_pci *pci)
{
	nvkm_pci_wr08(pci, 0x0704, 0xff);
}

void
gf100_pcie_set_version(struct nvkm_pci *pci, u8 ver)
{
	struct nvkm_device *device = pci->subdev.device;
	nvkm_mask(device, 0x02241c, 0x1, ver > 1 ? 1 : 0);
}

int
gf100_pcie_version(struct nvkm_pci *pci)
{
	struct nvkm_device *device = pci->subdev.device;
	return (nvkm_rd32(device, 0x02241c) & 0x1) + 1;
}

void
gf100_pcie_set_cap_speed(struct nvkm_pci *pci, bool full_speed)
{
	struct nvkm_device *device = pci->subdev.device;
	nvkm_mask(device, 0x02241c, 0x80, full_speed ? 0x80 : 0x0);
}

int
gf100_pcie_cap_speed(struct nvkm_pci *pci)
{
	struct nvkm_device *device = pci->subdev.device;
	u8 punits_pci_cap_speed = nvkm_rd32(device, 0x02241c) & 0x80;
	if (punits_pci_cap_speed == 0x80)
		return 1;
	return 0;
}

int
gf100_pcie_init(struct nvkm_pci *pci)
{
	bool full_speed = g84_pcie_cur_speed(pci) == NVKM_PCIE_SPEED_5_0;
	gf100_pcie_set_cap_speed(pci, full_speed);
	return 0;
}

int
gf100_pcie_set_link(struct nvkm_pci *pci, enum nvkm_pcie_speed speed, u8 width)
{
	gf100_pcie_set_cap_speed(pci, speed == NVKM_PCIE_SPEED_5_0);
	g84_pcie_set_link_speed(pci, speed);
	return 0;
}

int
gf100_pci_new(struct nvkm_device *device, int index, struct nvkm_pci **ppci)
{
	return nvkm_pci_new_(&gf100_pci_func, device, index, ppci);
}

