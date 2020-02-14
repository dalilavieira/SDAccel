#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_11__   TYPE_5__ ;
typedef  struct TYPE_10__   TYPE_4__ ;
typedef  struct TYPE_9__   TYPE_3__ ;
typedef  struct TYPE_8__   TYPE_2__ ;
typedef  struct TYPE_7__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  u8 ;
typedef  int u32 ;
typedef  int u16 ;
struct pci_dev {scalar_t__ irq; int device; } ;
struct nvkm_subdev {int dummy; } ;
struct nvkm_pci_func {int (* rd32 ) (struct nvkm_pci*,int) ;int /*<<< orphan*/  (* msi_rearm ) (struct nvkm_pci*) ;int /*<<< orphan*/  (* init ) (struct nvkm_pci*) ;int /*<<< orphan*/  (* wr32 ) (struct nvkm_pci*,int,int) ;int /*<<< orphan*/  (* wr08 ) (struct nvkm_pci*,int,int /*<<< orphan*/ ) ;} ;
struct TYPE_11__ {struct nvkm_device* device; } ;
struct TYPE_9__ {int speed; int width; } ;
struct TYPE_7__ {scalar_t__ bridge; } ;
struct nvkm_pci {scalar_t__ irq; int msi; TYPE_5__ subdev; struct pci_dev* pdev; TYPE_3__ pcie; struct nvkm_pci_func const* func; TYPE_1__ agp; } ;
struct nvkm_device {scalar_t__ type; int /*<<< orphan*/  cfgopt; int /*<<< orphan*/  chipset; TYPE_2__* func; } ;
typedef  int /*<<< orphan*/  irqreturn_t ;
struct TYPE_10__ {struct pci_dev* pdev; } ;
struct TYPE_8__ {TYPE_4__* (* pci ) (struct nvkm_device*) ;} ;

/* Variables and functions */
 int ENOMEM ; 
 int ENOSYS ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int /*<<< orphan*/  IRQF_SHARED ; 
 int /*<<< orphan*/  IRQ_HANDLED ; 
 int /*<<< orphan*/  IRQ_NONE ; 
 scalar_t__ NVKM_DEVICE_AGP ; 
 int /*<<< orphan*/  free_irq (int,struct nvkm_pci*) ; 
 struct nvkm_pci* kzalloc (int,int /*<<< orphan*/ ) ; 
 int nvkm_boolopt (int /*<<< orphan*/ ,char*,int) ; 
 int /*<<< orphan*/  nvkm_debug (TYPE_5__*,char*) ; 
 int /*<<< orphan*/  nvkm_mc_intr (struct nvkm_device*,int*) ; 
 int /*<<< orphan*/  nvkm_mc_intr_rearm (struct nvkm_device*) ; 
 int /*<<< orphan*/  nvkm_mc_intr_unarm (struct nvkm_device*) ; 
 void* nvkm_pci (struct nvkm_subdev*) ; 
 int /*<<< orphan*/  nvkm_pci_func ; 
 int /*<<< orphan*/  nvkm_pcie_init (struct nvkm_pci*) ; 
 int nvkm_pcie_oneinit (struct nvkm_pci*) ; 
 int /*<<< orphan*/  nvkm_subdev_ctor (int /*<<< orphan*/ *,struct nvkm_device*,int,TYPE_5__*) ; 
 int /*<<< orphan*/  pci_disable_msi (struct pci_dev*) ; 
 scalar_t__ pci_enable_msi (struct pci_dev*) ; 
 scalar_t__ pci_is_pcie (struct pci_dev*) ; 
 int request_irq (scalar_t__,int /*<<< orphan*/  (*) (int,void*),int /*<<< orphan*/ ,char*,struct nvkm_pci*) ; 
 int stub1 (struct nvkm_pci*,int) ; 
 int /*<<< orphan*/  stub2 (struct nvkm_pci*,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  stub3 (struct nvkm_pci*,int,int) ; 
 int stub4 (struct nvkm_pci*,int) ; 
 int /*<<< orphan*/  stub5 (struct nvkm_pci*,int,int) ; 
 int /*<<< orphan*/  stub6 (struct nvkm_pci*) ; 
 int /*<<< orphan*/  stub7 (struct nvkm_pci*) ; 
 int /*<<< orphan*/  stub8 (struct nvkm_pci*) ; 
 TYPE_4__* stub9 (struct nvkm_device*) ; 

__attribute__((used)) static inline void nvkm_agp_ctor(struct nvkm_pci *pci) {}

__attribute__((used)) static inline void nvkm_agp_dtor(struct nvkm_pci *pci) {}

__attribute__((used)) static inline void nvkm_agp_preinit(struct nvkm_pci *pci) {}

__attribute__((used)) static inline int nvkm_agp_init(struct nvkm_pci *pci) { return -ENOSYS; }

__attribute__((used)) static inline void nvkm_agp_fini(struct nvkm_pci *pci) {}

u32
nvkm_pci_rd32(struct nvkm_pci *pci, u16 addr)
{
	return pci->func->rd32(pci, addr);
}

void
nvkm_pci_wr08(struct nvkm_pci *pci, u16 addr, u8 data)
{
	pci->func->wr08(pci, addr, data);
}

void
nvkm_pci_wr32(struct nvkm_pci *pci, u16 addr, u32 data)
{
	pci->func->wr32(pci, addr, data);
}

u32
nvkm_pci_mask(struct nvkm_pci *pci, u16 addr, u32 mask, u32 value)
{
	u32 data = pci->func->rd32(pci, addr);
	pci->func->wr32(pci, addr, (data & ~mask) | value);
	return data;
}

void
nvkm_pci_rom_shadow(struct nvkm_pci *pci, bool shadow)
{
	u32 data = nvkm_pci_rd32(pci, 0x0050);
	if (shadow)
		data |=  0x00000001;
	else
		data &= ~0x00000001;
	nvkm_pci_wr32(pci, 0x0050, data);
}

__attribute__((used)) static irqreturn_t
nvkm_pci_intr(int irq, void *arg)
{
	struct nvkm_pci *pci = arg;
	struct nvkm_device *device = pci->subdev.device;
	bool handled = false;

	if (pci->irq < 0)
		return IRQ_HANDLED;

	nvkm_mc_intr_unarm(device);
	if (pci->msi)
		pci->func->msi_rearm(pci);
	nvkm_mc_intr(device, &handled);
	nvkm_mc_intr_rearm(device);
	return handled ? IRQ_HANDLED : IRQ_NONE;
}

__attribute__((used)) static int
nvkm_pci_fini(struct nvkm_subdev *subdev, bool suspend)
{
	struct nvkm_pci *pci = nvkm_pci(subdev);

	if (pci->agp.bridge)
		nvkm_agp_fini(pci);

	return 0;
}

__attribute__((used)) static int
nvkm_pci_preinit(struct nvkm_subdev *subdev)
{
	struct nvkm_pci *pci = nvkm_pci(subdev);
	if (pci->agp.bridge)
		nvkm_agp_preinit(pci);
	return 0;
}

__attribute__((used)) static int
nvkm_pci_oneinit(struct nvkm_subdev *subdev)
{
	struct nvkm_pci *pci = nvkm_pci(subdev);
	struct pci_dev *pdev = pci->pdev;
	int ret;

	if (pci_is_pcie(pci->pdev)) {
		ret = nvkm_pcie_oneinit(pci);
		if (ret)
			return ret;
	}

	ret = request_irq(pdev->irq, nvkm_pci_intr, IRQF_SHARED, "nvkm", pci);
	if (ret)
		return ret;

	pci->irq = pdev->irq;
	return 0;
}

__attribute__((used)) static int
nvkm_pci_init(struct nvkm_subdev *subdev)
{
	struct nvkm_pci *pci = nvkm_pci(subdev);
	int ret;

	if (pci->agp.bridge) {
		ret = nvkm_agp_init(pci);
		if (ret)
			return ret;
	} else if (pci_is_pcie(pci->pdev)) {
		nvkm_pcie_init(pci);
	}

	if (pci->func->init)
		pci->func->init(pci);

	/* Ensure MSI interrupts are armed, for the case where there are
	 * already interrupts pending (for whatever reason) at load time.
	 */
	if (pci->msi)
		pci->func->msi_rearm(pci);

	return 0;
}

__attribute__((used)) static void *
nvkm_pci_dtor(struct nvkm_subdev *subdev)
{
	struct nvkm_pci *pci = nvkm_pci(subdev);

	nvkm_agp_dtor(pci);

	if (pci->irq >= 0) {
		/* freq_irq() will call the handler, we use pci->irq == -1
		 * to signal that it's been torn down and should be a noop.
		 */
		int irq = pci->irq;
		pci->irq = -1;
		free_irq(irq, pci);
	}

	if (pci->msi)
		pci_disable_msi(pci->pdev);

	return nvkm_pci(subdev);
}

int
nvkm_pci_new_(const struct nvkm_pci_func *func, struct nvkm_device *device,
	      int index, struct nvkm_pci **ppci)
{
	struct nvkm_pci *pci;

	if (!(pci = *ppci = kzalloc(sizeof(**ppci), GFP_KERNEL)))
		return -ENOMEM;
	nvkm_subdev_ctor(&nvkm_pci_func, device, index, &pci->subdev);
	pci->func = func;
	pci->pdev = device->func->pci(device)->pdev;
	pci->irq = -1;
	pci->pcie.speed = -1;
	pci->pcie.width = -1;

	if (device->type == NVKM_DEVICE_AGP)
		nvkm_agp_ctor(pci);

	switch (pci->pdev->device & 0x0ff0) {
	case 0x00f0:
	case 0x02e0:
		/* BR02? NFI how these would be handled yet exactly */
		break;
	default:
		switch (device->chipset) {
		case 0xaa:
			/* reported broken, nv also disable it */
			break;
		default:
			pci->msi = true;
			break;
		}
	}

#ifdef __BIG_ENDIAN
	pci->msi = false;
#endif

	pci->msi = nvkm_boolopt(device->cfgopt, "NvMSI", pci->msi);
	if (pci->msi && func->msi_rearm) {
		pci->msi = pci_enable_msi(pci->pdev) == 0;
		if (pci->msi)
			nvkm_debug(&pci->subdev, "MSI enabled\n");
	} else {
		pci->msi = false;
	}

	return 0;
}

