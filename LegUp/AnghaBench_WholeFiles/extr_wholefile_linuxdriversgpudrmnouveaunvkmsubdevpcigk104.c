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
typedef  int u8 ;
typedef  int u32 ;
struct nvkm_subdev {struct nvkm_device* device; } ;
struct nvkm_pci {struct nvkm_subdev subdev; } ;
struct nvkm_device {int dummy; } ;
typedef  enum nvkm_pcie_speed { ____Placeholder_nvkm_pcie_speed } nvkm_pcie_speed ;

/* Variables and functions */
 int EINVAL ; 
#define  NVKM_PCIE_SPEED_2_5 130 
#define  NVKM_PCIE_SPEED_5_0 129 
#define  NVKM_PCIE_SPEED_8_0 128 
 int gf100_pcie_cap_speed (struct nvkm_pci*) ; 
 int /*<<< orphan*/  gf100_pcie_set_cap_speed (struct nvkm_pci*,int) ; 
 int gf100_pcie_version (struct nvkm_pci*) ; 
 int /*<<< orphan*/  gk104_pci_func ; 
 int /*<<< orphan*/  nvkm_debug (struct nvkm_subdev*,char*) ; 
 int /*<<< orphan*/  nvkm_error (struct nvkm_subdev*,char*) ; 
 int /*<<< orphan*/  nvkm_mask (struct nvkm_device*,int,int,int) ; 
 int /*<<< orphan*/  nvkm_pci_mask (struct nvkm_pci*,int,int,int) ; 
 int nvkm_pci_new_ (int /*<<< orphan*/ *,struct nvkm_device*,int,struct nvkm_pci**) ; 
 int nvkm_pci_rd32 (struct nvkm_pci*,int) ; 
 int nvkm_rd32 (struct nvkm_device*,int) ; 
 int /*<<< orphan*/  nvkm_trace (struct nvkm_subdev*,char*) ; 
 int /*<<< orphan*/  nvkm_warn (struct nvkm_subdev*,char*) ; 

__attribute__((used)) static int
gk104_pcie_version_supported(struct nvkm_pci *pci)
{
	return (nvkm_rd32(pci->subdev.device, 0x8c1c0) & 0x4) == 0x4 ? 2 : 1;
}

__attribute__((used)) static void
gk104_pcie_set_cap_speed(struct nvkm_pci *pci, enum nvkm_pcie_speed speed)
{
	struct nvkm_device *device = pci->subdev.device;

	switch (speed) {
	case NVKM_PCIE_SPEED_2_5:
		gf100_pcie_set_cap_speed(pci, false);
		nvkm_mask(device, 0x8c1c0, 0x30000, 0x10000);
		break;
	case NVKM_PCIE_SPEED_5_0:
		gf100_pcie_set_cap_speed(pci, true);
		nvkm_mask(device, 0x8c1c0, 0x30000, 0x20000);
		break;
	case NVKM_PCIE_SPEED_8_0:
		gf100_pcie_set_cap_speed(pci, true);
		nvkm_mask(device, 0x8c1c0, 0x30000, 0x30000);
		break;
	}
}

__attribute__((used)) static enum nvkm_pcie_speed
gk104_pcie_cap_speed(struct nvkm_pci *pci)
{
	int speed = gf100_pcie_cap_speed(pci);

	if (speed == 0)
		return NVKM_PCIE_SPEED_2_5;

	if (speed >= 1) {
		int speed2 = nvkm_rd32(pci->subdev.device, 0x8c1c0) & 0x30000;
		switch (speed2) {
		case 0x00000:
		case 0x10000:
			return NVKM_PCIE_SPEED_2_5;
		case 0x20000:
			return NVKM_PCIE_SPEED_5_0;
		case 0x30000:
			return NVKM_PCIE_SPEED_8_0;
		}
	}

	return -EINVAL;
}

__attribute__((used)) static void
gk104_pcie_set_lnkctl_speed(struct nvkm_pci *pci, enum nvkm_pcie_speed speed)
{
	u8 reg_v = 0;
	switch (speed) {
	case NVKM_PCIE_SPEED_2_5:
		reg_v = 1;
		break;
	case NVKM_PCIE_SPEED_5_0:
		reg_v = 2;
		break;
	case NVKM_PCIE_SPEED_8_0:
		reg_v = 3;
		break;
	}
	nvkm_pci_mask(pci, 0xa8, 0x3, reg_v);
}

__attribute__((used)) static enum nvkm_pcie_speed
gk104_pcie_lnkctl_speed(struct nvkm_pci *pci)
{
	u8 reg_v = nvkm_pci_rd32(pci, 0xa8) & 0x3;
	switch (reg_v) {
	case 0:
	case 1:
		return NVKM_PCIE_SPEED_2_5;
	case 2:
		return NVKM_PCIE_SPEED_5_0;
	case 3:
		return NVKM_PCIE_SPEED_8_0;
	}
	return -1;
}

__attribute__((used)) static enum nvkm_pcie_speed
gk104_pcie_max_speed(struct nvkm_pci *pci)
{
	u32 max_speed = nvkm_rd32(pci->subdev.device, 0x8c1c0) & 0x300000;
	switch (max_speed) {
	case 0x000000:
		return NVKM_PCIE_SPEED_8_0;
	case 0x100000:
		return NVKM_PCIE_SPEED_5_0;
	case 0x200000:
		return NVKM_PCIE_SPEED_2_5;
	}
	return NVKM_PCIE_SPEED_2_5;
}

__attribute__((used)) static void
gk104_pcie_set_link_speed(struct nvkm_pci *pci, enum nvkm_pcie_speed speed)
{
	struct nvkm_device *device = pci->subdev.device;
	u32 mask_value;

	switch (speed) {
	case NVKM_PCIE_SPEED_8_0:
		mask_value = 0x00000;
		break;
	case NVKM_PCIE_SPEED_5_0:
		mask_value = 0x40000;
		break;
	case NVKM_PCIE_SPEED_2_5:
	default:
		mask_value = 0x80000;
		break;
	}

	nvkm_mask(device, 0x8c040, 0xc0000, mask_value);
	nvkm_mask(device, 0x8c040, 0x1, 0x1);
}

__attribute__((used)) static int
gk104_pcie_init(struct nvkm_pci * pci)
{
	enum nvkm_pcie_speed lnkctl_speed, max_speed, cap_speed;
	struct nvkm_subdev *subdev = &pci->subdev;

	if (gf100_pcie_version(pci) < 2)
		return 0;

	lnkctl_speed = gk104_pcie_lnkctl_speed(pci);
	max_speed = gk104_pcie_max_speed(pci);
	cap_speed = gk104_pcie_cap_speed(pci);

	if (cap_speed != max_speed) {
		nvkm_trace(subdev, "adjusting cap to max speed\n");
		gk104_pcie_set_cap_speed(pci, max_speed);
		cap_speed = gk104_pcie_cap_speed(pci);
		if (cap_speed != max_speed)
			nvkm_warn(subdev, "failed to adjust cap speed\n");
	}

	if (lnkctl_speed != max_speed) {
		nvkm_debug(subdev, "adjusting lnkctl to max speed\n");
		gk104_pcie_set_lnkctl_speed(pci, max_speed);
		lnkctl_speed = gk104_pcie_lnkctl_speed(pci);
		if (lnkctl_speed != max_speed)
			nvkm_error(subdev, "failed to adjust lnkctl speed\n");
	}

	return 0;
}

__attribute__((used)) static int
gk104_pcie_set_link(struct nvkm_pci *pci, enum nvkm_pcie_speed speed, u8 width)
{
	struct nvkm_subdev *subdev = &pci->subdev;
	enum nvkm_pcie_speed lnk_ctl_speed = gk104_pcie_lnkctl_speed(pci);
	enum nvkm_pcie_speed lnk_cap_speed = gk104_pcie_cap_speed(pci);

	if (speed > lnk_cap_speed) {
		speed = lnk_cap_speed;
		nvkm_warn(subdev, "dropping requested speed due too low cap"
			  " speed\n");
	}

	if (speed > lnk_ctl_speed) {
		speed = lnk_ctl_speed;
		nvkm_warn(subdev, "dropping requested speed due too low"
			  " lnkctl speed\n");
	}

	gk104_pcie_set_link_speed(pci, speed);
	return 0;
}

int
gk104_pci_new(struct nvkm_device *device, int index, struct nvkm_pci **ppci)
{
	return nvkm_pci_new_(&gk104_pci_func, device, index, ppci);
}

