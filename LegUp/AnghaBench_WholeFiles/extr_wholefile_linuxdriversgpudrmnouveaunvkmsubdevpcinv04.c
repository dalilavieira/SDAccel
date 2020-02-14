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
typedef  int /*<<< orphan*/  u8 ;
typedef  int /*<<< orphan*/  u32 ;
typedef  scalar_t__ u16 ;
struct TYPE_2__ {struct nvkm_device* device; } ;
struct nvkm_pci {TYPE_1__ subdev; } ;
struct nvkm_device {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  nv04_pci_func ; 
 int nvkm_pci_new_ (int /*<<< orphan*/ *,struct nvkm_device*,int,struct nvkm_pci**) ; 
 int /*<<< orphan*/  nvkm_rd32 (struct nvkm_device*,scalar_t__) ; 
 int /*<<< orphan*/  nvkm_wr08 (struct nvkm_device*,scalar_t__,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  nvkm_wr32 (struct nvkm_device*,scalar_t__,int /*<<< orphan*/ ) ; 

__attribute__((used)) static u32
nv04_pci_rd32(struct nvkm_pci *pci, u16 addr)
{
	struct nvkm_device *device = pci->subdev.device;
	return nvkm_rd32(device, 0x001800 + addr);
}

__attribute__((used)) static void
nv04_pci_wr08(struct nvkm_pci *pci, u16 addr, u8 data)
{
	struct nvkm_device *device = pci->subdev.device;
	nvkm_wr08(device, 0x001800 + addr, data);
}

__attribute__((used)) static void
nv04_pci_wr32(struct nvkm_pci *pci, u16 addr, u32 data)
{
	struct nvkm_device *device = pci->subdev.device;
	nvkm_wr32(device, 0x001800 + addr, data);
}

int
nv04_pci_new(struct nvkm_device *device, int index, struct nvkm_pci **ppci)
{
	return nvkm_pci_new_(&nv04_pci_func, device, index, ppci);
}

