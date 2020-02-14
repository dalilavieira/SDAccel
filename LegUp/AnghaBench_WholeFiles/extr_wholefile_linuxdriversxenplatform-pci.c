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
typedef  int uint64_t ;
typedef  int u8 ;
struct pci_device_id {int dummy; } ;
struct pci_dev {int irq; int pin; int devfn; int /*<<< orphan*/  dev; TYPE_1__* bus; } ;
typedef  int /*<<< orphan*/  irqreturn_t ;
struct TYPE_2__ {scalar_t__ number; } ;

/* Variables and functions */
 int /*<<< orphan*/  BUG_ON (int) ; 
 int /*<<< orphan*/  DRV_NAME ; 
 int ENODEV ; 
 int ENOENT ; 
 int HVM_CALLBACK_VIA_TYPE_SHIFT ; 
 int IRQF_NOBALANCING ; 
 int IRQF_TRIGGER_RISING ; 
 int /*<<< orphan*/  IRQ_HANDLED ; 
 unsigned int PAGE_SIZE ; 
 int callback_via ; 
 int /*<<< orphan*/  dev_err (int /*<<< orphan*/ *,char*) ; 
 int /*<<< orphan*/  dev_warn (int /*<<< orphan*/ *,char*,int) ; 
 int /*<<< orphan*/  gnttab_free_auto_xlat_frames () ; 
 int gnttab_init () ; 
 unsigned int gnttab_max_grant_frames () ; 
 int gnttab_setup_auto_xlat_frames (unsigned long) ; 
 int /*<<< orphan*/  pci_disable_device (struct pci_dev*) ; 
 scalar_t__ pci_domain_nr (TYPE_1__*) ; 
 int pci_enable_device (struct pci_dev*) ; 
 int /*<<< orphan*/  pci_release_region (struct pci_dev*,int) ; 
 int pci_request_region (struct pci_dev*,int,int /*<<< orphan*/ ) ; 
 long pci_resource_len (struct pci_dev*,int) ; 
 long pci_resource_start (struct pci_dev*,int) ; 
 unsigned long platform_mmio ; 
 unsigned long platform_mmio_alloc ; 
 unsigned long platform_mmiolen ; 
 int request_irq (int,int /*<<< orphan*/  (*) (int,void*),int,char*,struct pci_dev*) ; 
 int /*<<< orphan*/  xen_domain () ; 
 scalar_t__ xen_have_vector_callback ; 
 int /*<<< orphan*/  xen_hvm_evtchn_do_upcall () ; 
 int xen_set_callback_via (int) ; 
 int /*<<< orphan*/  xenbus_probe (int /*<<< orphan*/ *) ; 

__attribute__((used)) static unsigned long alloc_xen_mmio(unsigned long len)
{
	unsigned long addr;

	addr = platform_mmio + platform_mmio_alloc;
	platform_mmio_alloc += len;
	BUG_ON(platform_mmio_alloc > platform_mmiolen);

	return addr;
}

__attribute__((used)) static uint64_t get_callback_via(struct pci_dev *pdev)
{
	u8 pin;
	int irq;

	irq = pdev->irq;
	if (irq < 16)
		return irq; /* ISA IRQ */

	pin = pdev->pin;

	/* We don't know the GSI. Specify the PCI INTx line instead. */
	return ((uint64_t)0x01 << HVM_CALLBACK_VIA_TYPE_SHIFT) | /* PCI INTx identifier */
		((uint64_t)pci_domain_nr(pdev->bus) << 32) |
		((uint64_t)pdev->bus->number << 16) |
		((uint64_t)(pdev->devfn & 0xff) << 8) |
		((uint64_t)(pin - 1) & 3);
}

__attribute__((used)) static irqreturn_t do_hvm_evtchn_intr(int irq, void *dev_id)
{
	xen_hvm_evtchn_do_upcall();
	return IRQ_HANDLED;
}

__attribute__((used)) static int xen_allocate_irq(struct pci_dev *pdev)
{
	return request_irq(pdev->irq, do_hvm_evtchn_intr,
			IRQF_NOBALANCING | IRQF_TRIGGER_RISING,
			"xen-platform-pci", pdev);
}

__attribute__((used)) static int platform_pci_resume(struct pci_dev *pdev)
{
	int err;

	if (xen_have_vector_callback)
		return 0;

	err = xen_set_callback_via(callback_via);
	if (err) {
		dev_err(&pdev->dev, "platform_pci_resume failure!\n");
		return err;
	}
	return 0;
}

__attribute__((used)) static int platform_pci_probe(struct pci_dev *pdev,
			      const struct pci_device_id *ent)
{
	int i, ret;
	long ioaddr;
	long mmio_addr, mmio_len;
	unsigned int max_nr_gframes;
	unsigned long grant_frames;

	if (!xen_domain())
		return -ENODEV;

	i = pci_enable_device(pdev);
	if (i)
		return i;

	ioaddr = pci_resource_start(pdev, 0);

	mmio_addr = pci_resource_start(pdev, 1);
	mmio_len = pci_resource_len(pdev, 1);

	if (mmio_addr == 0 || ioaddr == 0) {
		dev_err(&pdev->dev, "no resources found\n");
		ret = -ENOENT;
		goto pci_out;
	}

	ret = pci_request_region(pdev, 1, DRV_NAME);
	if (ret < 0)
		goto pci_out;

	ret = pci_request_region(pdev, 0, DRV_NAME);
	if (ret < 0)
		goto mem_out;

	platform_mmio = mmio_addr;
	platform_mmiolen = mmio_len;
	if (!xen_have_vector_callback) {
		ret = xen_allocate_irq(pdev);
		if (ret) {
			dev_warn(&pdev->dev, "request_irq failed err=%d\n", ret);
			goto out;
		}
		callback_via = get_callback_via(pdev);
		ret = xen_set_callback_via(callback_via);
		if (ret) {
			dev_warn(&pdev->dev, "Unable to set the evtchn callback "
					 "err=%d\n", ret);
			goto out;
		}
	}

	max_nr_gframes = gnttab_max_grant_frames();
	grant_frames = alloc_xen_mmio(PAGE_SIZE * max_nr_gframes);
	ret = gnttab_setup_auto_xlat_frames(grant_frames);
	if (ret)
		goto out;
	ret = gnttab_init();
	if (ret)
		goto grant_out;
	xenbus_probe(NULL);
	return 0;
grant_out:
	gnttab_free_auto_xlat_frames();
out:
	pci_release_region(pdev, 0);
mem_out:
	pci_release_region(pdev, 1);
pci_out:
	pci_disable_device(pdev);
	return ret;
}

