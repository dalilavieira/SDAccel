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
typedef  int u32 ;
struct TYPE_2__ {struct nvkm_device* device; } ;
struct nvkm_pci {int /*<<< orphan*/  pdev; TYPE_1__ subdev; } ;
struct nvkm_device {int dummy; } ;
typedef  enum nvkm_pcie_speed { ____Placeholder_nvkm_pcie_speed } nvkm_pcie_speed ;

/* Variables and functions */
 int NVKM_PCIE_SPEED_2_5 ; 
 int NVKM_PCIE_SPEED_5_0 ; 
 int NVKM_PCIE_SPEED_8_0 ; 
 int /*<<< orphan*/  g84_pci_func ; 
 int /*<<< orphan*/  nvkm_mask (struct nvkm_device*,int,int,int) ; 
 int /*<<< orphan*/  nvkm_pci_mask (struct nvkm_pci*,int,int,int) ; 
 int nvkm_pci_new_ (int /*<<< orphan*/ *,struct nvkm_device*,int,struct nvkm_pci**) ; 
 int nvkm_pci_rd32 (struct nvkm_pci*,int) ; 
 int nvkm_rd32 (struct nvkm_device*,int) ; 
 int /*<<< orphan*/  pci_is_pcie (int /*<<< orphan*/ ) ; 

__attribute__((used)) static int
g84_pcie_version_supported(struct nvkm_pci *pci)
{
	/* g84 and g86 report wrong information about what they support */
	return 1;
}

int
g84_pcie_version(struct nvkm_pci *pci)
{
	struct nvkm_device *device = pci->subdev.device;
	return (nvkm_rd32(device, 0x00154c) & 0x1) + 1;
}

void
g84_pcie_set_version(struct nvkm_pci *pci, u8 ver)
{
	struct nvkm_device *device = pci->subdev.device;
	nvkm_mask(device, 0x00154c, 0x1, (ver >= 2 ? 0x1 : 0x0));
}

__attribute__((used)) static void
g84_pcie_set_cap_speed(struct nvkm_pci *pci, bool full_speed)
{
	struct nvkm_device *device = pci->subdev.device;
	nvkm_mask(device, 0x00154c, 0x80, full_speed ? 0x80 : 0x0);
}

enum nvkm_pcie_speed
g84_pcie_cur_speed(struct nvkm_pci *pci)
{
	u32 reg_v = nvkm_pci_rd32(pci, 0x88) & 0x30000;
	switch (reg_v) {
	case 0x30000:
		return NVKM_PCIE_SPEED_8_0;
	case 0x20000:
		return NVKM_PCIE_SPEED_5_0;
	case 0x10000:
	default:
		return NVKM_PCIE_SPEED_2_5;
	}
}

enum nvkm_pcie_speed
g84_pcie_max_speed(struct nvkm_pci *pci)
{
	u32 reg_v = nvkm_pci_rd32(pci, 0x460) & 0x3300;
	if (reg_v == 0x2200)
		return NVKM_PCIE_SPEED_5_0;
	return NVKM_PCIE_SPEED_2_5;
}

void
g84_pcie_set_link_speed(struct nvkm_pci *pci, enum nvkm_pcie_speed speed)
{
	u32 mask_value;

	if (speed == NVKM_PCIE_SPEED_5_0)
		mask_value = 0x20;
	else
		mask_value = 0x10;

	nvkm_pci_mask(pci, 0x460, 0x30, mask_value);
	nvkm_pci_mask(pci, 0x460, 0x1, 0x1);
}

int
g84_pcie_set_link(struct nvkm_pci *pci, enum nvkm_pcie_speed speed, u8 width)
{
	g84_pcie_set_cap_speed(pci, speed == NVKM_PCIE_SPEED_5_0);
	g84_pcie_set_link_speed(pci, speed);
	return 0;
}

void
g84_pci_init(struct nvkm_pci *pci)
{
	/* The following only concerns PCIe cards. */
	if (!pci_is_pcie(pci->pdev))
		return;

	/* Tag field is 8-bit long, regardless of EXT_TAG.
	 * However, if EXT_TAG is disabled, only the lower 5 bits of the tag
	 * field should be used, limiting the number of request to 32.
	 *
	 * Apparently, 0x041c stores some limit on the number of requests
	 * possible, so if EXT_TAG is disabled, limit that requests number to
	 * 32
	 *
	 * Fixes fdo#86537
	 */
	if (nvkm_pci_rd32(pci, 0x007c) & 0x00000020)
		nvkm_pci_mask(pci, 0x0080, 0x00000100, 0x00000100);
	else
		nvkm_pci_mask(pci, 0x041c, 0x00000060, 0x00000000);
}

int
g84_pcie_init(struct nvkm_pci *pci)
{
	bool full_speed = g84_pcie_cur_speed(pci) == NVKM_PCIE_SPEED_5_0;
	g84_pcie_set_cap_speed(pci, full_speed);
	return 0;
}

int
g84_pci_new(struct nvkm_device *device, int index, struct nvkm_pci **ppci)
{
	return nvkm_pci_new_(&g84_pci_func, device, index, ppci);
}

