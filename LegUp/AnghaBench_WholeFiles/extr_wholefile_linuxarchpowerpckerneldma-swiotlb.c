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
typedef  scalar_t__ u64 ;
struct dev_archdata {scalar_t__ max_direct_dma_addr; } ;
struct TYPE_2__ {struct dev_archdata archdata; } ;
struct pci_dev {TYPE_1__ dev; int /*<<< orphan*/  bus; } ;
struct pci_controller {scalar_t__ dma_window_base_cur; scalar_t__ dma_window_size; } ;
struct notifier_block {int dummy; } ;
struct device {struct dev_archdata archdata; } ;

/* Variables and functions */
 unsigned long BUS_NOTIFY_ADD_DEVICE ; 
 int NOTIFY_DONE ; 
 scalar_t__ dma_get_mask (struct device*) ; 
 int fls64 (scalar_t__) ; 
 scalar_t__ get_dma_offset (struct device*) ; 
 scalar_t__ memblock_end_of_DRAM () ; 
 struct pci_controller* pci_bus_to_host (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  powerpc_swiotlb_dma_ops ; 
 int /*<<< orphan*/  set_dma_ops (struct device*,int /*<<< orphan*/ *) ; 

__attribute__((used)) static u64 swiotlb_powerpc_get_required(struct device *dev)
{
	u64 end, mask, max_direct_dma_addr = dev->archdata.max_direct_dma_addr;

	end = memblock_end_of_DRAM();
	if (max_direct_dma_addr && end > max_direct_dma_addr)
		end = max_direct_dma_addr;
	end += get_dma_offset(dev);

	mask = 1ULL << (fls64(end) - 1);
	mask += mask - 1;

	return mask;
}

void pci_dma_dev_setup_swiotlb(struct pci_dev *pdev)
{
	struct pci_controller *hose;
	struct dev_archdata *sd;

	hose = pci_bus_to_host(pdev->bus);
	sd = &pdev->dev.archdata;
	sd->max_direct_dma_addr =
		hose->dma_window_base_cur + hose->dma_window_size;
}

__attribute__((used)) static int ppc_swiotlb_bus_notify(struct notifier_block *nb,
				  unsigned long action, void *data)
{
	struct device *dev = data;
	struct dev_archdata *sd;

	/* We are only intereted in device addition */
	if (action != BUS_NOTIFY_ADD_DEVICE)
		return 0;

	sd = &dev->archdata;
	sd->max_direct_dma_addr = 0;

	/* May need to bounce if the device can't address all of DRAM */
	if ((dma_get_mask(dev) + 1) < memblock_end_of_DRAM())
		set_dma_ops(dev, &powerpc_swiotlb_dma_ops);

	return NOTIFY_DONE;
}

