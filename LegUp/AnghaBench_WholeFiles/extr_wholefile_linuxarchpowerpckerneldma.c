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
typedef  void* u64 ;
struct pci_dev {int /*<<< orphan*/  bus; } ;
struct TYPE_3__ {int (* dma_set_mask ) (struct pci_dev*,void*) ;void* (* dma_get_required_mask ) (struct pci_dev*) ;} ;
struct pci_controller {TYPE_1__ controller_ops; } ;
struct dma_map_ops {void* (* get_required_mask ) (struct device*) ;} ;
struct device {void** dma_mask; void* coherent_dma_mask; } ;
typedef  int /*<<< orphan*/  dma_addr_t ;
struct TYPE_4__ {int (* dma_set_mask ) (struct device*,void*) ;void* (* dma_get_required_mask ) (struct device*) ;} ;

/* Variables and functions */
 void* DMA_BIT_MASK (int) ; 
 int EIO ; 
 scalar_t__ dev_is_pci (struct device*) ; 
 int /*<<< orphan*/  dma_iommu_dma_supported (struct device*,void*) ; 
 struct dma_map_ops dma_nommu_ops ; 
 int /*<<< orphan*/  dma_supported (struct device*,void*) ; 
 struct dma_map_ops* get_dma_ops (struct device*) ; 
 int /*<<< orphan*/ * get_iommu_table_base (struct device*) ; 
 struct pci_controller* pci_bus_to_host (int /*<<< orphan*/ ) ; 
 TYPE_2__ ppc_md ; 
 int stub1 (struct device*,void*) ; 
 int stub2 (struct pci_dev*,void*) ; 
 void* stub3 (struct device*) ; 
 void* stub4 (struct device*) ; 
 void* stub5 (struct pci_dev*) ; 
 struct pci_dev* to_pci_dev (struct device*) ; 
 scalar_t__ unlikely (int /*<<< orphan*/ ) ; 

int dma_set_coherent_mask(struct device *dev, u64 mask)
{
	if (!dma_supported(dev, mask)) {
		/*
		 * We need to special case the direct DMA ops which can
		 * support a fallback for coherent allocations. There
		 * is no dma_op->set_coherent_mask() so we have to do
		 * things the hard way:
		 */
		if (get_dma_ops(dev) != &dma_nommu_ops ||
		    get_iommu_table_base(dev) == NULL ||
		    !dma_iommu_dma_supported(dev, mask))
			return -EIO;
	}
	dev->coherent_dma_mask = mask;
	return 0;
}

int dma_set_mask(struct device *dev, u64 dma_mask)
{
	if (ppc_md.dma_set_mask)
		return ppc_md.dma_set_mask(dev, dma_mask);

	if (dev_is_pci(dev)) {
		struct pci_dev *pdev = to_pci_dev(dev);
		struct pci_controller *phb = pci_bus_to_host(pdev->bus);
		if (phb->controller_ops.dma_set_mask)
			return phb->controller_ops.dma_set_mask(pdev, dma_mask);
	}

	if (!dev->dma_mask || !dma_supported(dev, dma_mask))
		return -EIO;
	*dev->dma_mask = dma_mask;
	return 0;
}

u64 __dma_get_required_mask(struct device *dev)
{
	const struct dma_map_ops *dma_ops = get_dma_ops(dev);

	if (unlikely(dma_ops == NULL))
		return 0;

	if (dma_ops->get_required_mask)
		return dma_ops->get_required_mask(dev);

	return DMA_BIT_MASK(8 * sizeof(dma_addr_t));
}

u64 dma_get_required_mask(struct device *dev)
{
	if (ppc_md.dma_get_required_mask)
		return ppc_md.dma_get_required_mask(dev);

	if (dev_is_pci(dev)) {
		struct pci_dev *pdev = to_pci_dev(dev);
		struct pci_controller *phb = pci_bus_to_host(pdev->bus);
		if (phb->controller_ops.dma_get_required_mask)
			return phb->controller_ops.dma_get_required_mask(pdev);
	}

	return __dma_get_required_mask(dev);
}

