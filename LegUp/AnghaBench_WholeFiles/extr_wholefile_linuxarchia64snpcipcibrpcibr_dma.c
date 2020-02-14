#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_8__   TYPE_4__ ;
typedef  struct TYPE_7__   TYPE_3__ ;
typedef  struct TYPE_6__   TYPE_2__ ;
typedef  struct TYPE_5__   TYPE_1__ ;

/* Type definitions */
typedef  size_t u8 ;
typedef  size_t u64 ;
typedef  int u32 ;
struct sn_flush_nasid_entry {size_t* iio_itte; struct sn_flush_device_kernel** widget_p; } ;
struct sn_flush_device_kernel {int /*<<< orphan*/  sfdl_flush_lock; struct sn_flush_device_common* common; } ;
struct sn_flush_device_common {int* sfdl_flush_addr; scalar_t__ sfdl_force_int_addr; scalar_t__ sfdl_slot; int /*<<< orphan*/  sfdl_pcibus_info; TYPE_1__* sfdl_bar_list; } ;
struct pcidev_info {scalar_t__ pdi_pcibus_info; struct pcidev_info* pdi_host_pcidev_info; TYPE_3__* pdi_linux_pcidev; } ;
struct pcibus_info {size_t pbi_hub_xid; int* pbi_devreg; size_t pbi_dir_xbase; } ;
struct TYPE_6__ {unsigned long coherent_dma_mask; } ;
struct pci_dev {int dma_mask; TYPE_2__ dev; } ;
struct hubdev_info {struct sn_flush_nasid_entry hdi_flush_nasid_list; } ;
typedef  int nasid_t ;
typedef  size_t dma_addr_t ;
struct TYPE_8__ {struct hubdev_info* pdinfo; } ;
struct TYPE_7__ {int /*<<< orphan*/  devfn; } ;
struct TYPE_5__ {scalar_t__ start; size_t end; } ;

/* Variables and functions */
 size_t ATE_SWAP_OFF (size_t) ; 
 int /*<<< orphan*/  ATE_SWAP_ON (size_t) ; 
 int /*<<< orphan*/  BUG_ON (int) ; 
 size_t BWIN_WINDOWNUM (size_t) ; 
 int DEV_PER_WIDGET ; 
 int HUB_L (int /*<<< orphan*/ ) ; 
 int IIO_ITTE_WIDGET (size_t) ; 
 int IOPG (size_t) ; 
 size_t IOPGOFF (size_t) ; 
 int IOPGSIZE ; 
 scalar_t__ IS_PCI32_MAPPED (size_t) ; 
 scalar_t__ IS_PCIX (struct pcibus_info*) ; 
 scalar_t__ IS_PIC_SOFT (struct pcibus_info*) ; 
 scalar_t__ IS_TIOCP_SOFT (struct pcibus_info*) ; 
 int /*<<< orphan*/  MINIMAL_ATE_FLAG (size_t,size_t) ; 
 int NASID_GET (size_t) ; 
 TYPE_4__* NODEPDA (int) ; 
 size_t PCI32_ATE_BAR ; 
 size_t PCI32_ATE_MSI ; 
 size_t PCI32_ATE_PIO ; 
 size_t PCI32_ATE_PREF ; 
 size_t PCI32_ATE_V ; 
 size_t PCI32_DIRECT_BASE ; 
 size_t PCI32_MAPPED_BASE ; 
 size_t PCI64_ATTR_BAR ; 
 size_t PCI64_ATTR_PREF ; 
 size_t PCI64_ATTR_VIRTUAL ; 
 int PCIBR_DEV_SWAP_DIR ; 
 scalar_t__ PCI_FUNC (int /*<<< orphan*/ ) ; 
 int PCI_ROM_RESOURCE ; 
 size_t PCI_SLOT (int /*<<< orphan*/ ) ; 
 size_t PHYS_TO_DMA (size_t) ; 
 size_t PHYS_TO_TIODMA (size_t) ; 
 size_t PIC_ATE_TARGETID_SHFT ; 
 size_t PIC_PCI64_ATTR_TARG_SHFT ; 
 int PV907516 ; 
 int SN_DMA_ADDRTYPE (int) ; 
 int SN_DMA_ADDR_PHYS ; 
 int SN_DMA_MSI ; 
 struct pcidev_info* SN_PCIDEV_INFO (struct pci_dev*) ; 
 int SWIN_WIDGETNUM (size_t) ; 
 size_t TIOCP_PCI64_CMDTYPE_MEM ; 
 size_t TIOCP_PCI64_CMDTYPE_MSI ; 
 int TIO_BWIN_WINDOWNUM (size_t) ; 
 scalar_t__ TIO_HWIN (size_t) ; 
 int /*<<< orphan*/  TIO_IOSPACE_ADDR (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  TIO_ITTE_VALID (size_t) ; 
 int TIO_ITTE_WIDGET (size_t) ; 
 int /*<<< orphan*/  TIO_NODE_ID ; 
 int TIO_SWIN_WIDGETNUM (size_t) ; 
 int XWIDGET_PART_REV_NUM (int) ; 
 int XWIDGET_PART_REV_NUM_REV (int) ; 
 int /*<<< orphan*/  ate_write (struct pcibus_info*,int,int,size_t) ; 
 int /*<<< orphan*/  cpu_relax () ; 
 int nasid_to_cnodeid (int) ; 
 int pcibr_ate_alloc (struct pcibus_info*,int) ; 
 int /*<<< orphan*/  pcibr_ate_free (struct pcibus_info*,int) ; 
 int /*<<< orphan*/  pcireg_wrb_flush_get (int /*<<< orphan*/ ,scalar_t__) ; 
 int /*<<< orphan*/  sn_ioif_inited ; 
 int /*<<< orphan*/  spin_lock_irqsave (int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  spin_unlock_irqrestore (int /*<<< orphan*/ *,unsigned long) ; 

__attribute__((used)) static dma_addr_t
pcibr_dmamap_ate32(struct pcidev_info *info,
		   u64 paddr, size_t req_size, u64 flags, int dma_flags)
{

	struct pcidev_info *pcidev_info = info->pdi_host_pcidev_info;
	struct pcibus_info *pcibus_info = (struct pcibus_info *)pcidev_info->
	    pdi_pcibus_info;
	u8 internal_device = (PCI_SLOT(pcidev_info->pdi_host_pcidev_info->
					    pdi_linux_pcidev->devfn)) - 1;
	int ate_count;
	int ate_index;
	u64 ate_flags = flags | PCI32_ATE_V;
	u64 ate;
	u64 pci_addr;
	u64 xio_addr;
	u64 offset;

	/* PIC in PCI-X mode does not supports 32bit PageMap mode */
	if (IS_PIC_SOFT(pcibus_info) && IS_PCIX(pcibus_info)) {
		return 0;
	}

	/* Calculate the number of ATEs needed. */
	if (!(MINIMAL_ATE_FLAG(paddr, req_size))) {
		ate_count = IOPG((IOPGSIZE - 1)	/* worst case start offset */
				 +req_size	/* max mapping bytes */
				 - 1) + 1;	/* round UP */
	} else {		/* assume requested target is page aligned */
		ate_count = IOPG(req_size	/* max mapping bytes */
				 - 1) + 1;	/* round UP */
	}

	/* Get the number of ATEs required. */
	ate_index = pcibr_ate_alloc(pcibus_info, ate_count);
	if (ate_index < 0)
		return 0;

	/* In PCI-X mode, Prefetch not supported */
	if (IS_PCIX(pcibus_info))
		ate_flags &= ~(PCI32_ATE_PREF);

	if (SN_DMA_ADDRTYPE(dma_flags == SN_DMA_ADDR_PHYS))
		xio_addr = IS_PIC_SOFT(pcibus_info) ? PHYS_TO_DMA(paddr) :
	    					      PHYS_TO_TIODMA(paddr);
	else
		xio_addr = paddr;

	offset = IOPGOFF(xio_addr);
	ate = ate_flags | (xio_addr - offset);

	/* If PIC, put the targetid in the ATE */
	if (IS_PIC_SOFT(pcibus_info)) {
		ate |= (pcibus_info->pbi_hub_xid << PIC_ATE_TARGETID_SHFT);
	}

	/*
	 * If we're mapping for MSI, set the MSI bit in the ATE.  If it's a
	 * TIOCP based pci bus, we also need to set the PIO bit in the ATE.
	 */
	if (dma_flags & SN_DMA_MSI) {
		ate |= PCI32_ATE_MSI;
		if (IS_TIOCP_SOFT(pcibus_info))
			ate |= PCI32_ATE_PIO;
	}

	ate_write(pcibus_info, ate_index, ate_count, ate);

	/*
	 * Set up the DMA mapped Address.
	 */
	pci_addr = PCI32_MAPPED_BASE + offset + IOPGSIZE * ate_index;

	/*
	 * If swap was set in device in pcibr_endian_set()
	 * we need to turn swapping on.
	 */
	if (pcibus_info->pbi_devreg[internal_device] & PCIBR_DEV_SWAP_DIR)
		ATE_SWAP_ON(pci_addr);


	return pci_addr;
}

__attribute__((used)) static dma_addr_t
pcibr_dmatrans_direct64(struct pcidev_info * info, u64 paddr,
			u64 dma_attributes, int dma_flags)
{
	struct pcibus_info *pcibus_info = (struct pcibus_info *)
	    ((info->pdi_host_pcidev_info)->pdi_pcibus_info);
	u64 pci_addr;

	/* Translate to Crosstalk View of Physical Address */
	if (SN_DMA_ADDRTYPE(dma_flags) == SN_DMA_ADDR_PHYS)
		pci_addr = IS_PIC_SOFT(pcibus_info) ?
				PHYS_TO_DMA(paddr) :
				PHYS_TO_TIODMA(paddr);
	else
		pci_addr = paddr;
	pci_addr |= dma_attributes;

	/* Handle Bus mode */
	if (IS_PCIX(pcibus_info))
		pci_addr &= ~PCI64_ATTR_PREF;

	/* Handle Bridge Chipset differences */
	if (IS_PIC_SOFT(pcibus_info)) {
		pci_addr |=
		    ((u64) pcibus_info->
		     pbi_hub_xid << PIC_PCI64_ATTR_TARG_SHFT);
	} else
		pci_addr |= (dma_flags & SN_DMA_MSI) ?
				TIOCP_PCI64_CMDTYPE_MSI :
				TIOCP_PCI64_CMDTYPE_MEM;

	/* If PCI mode, func zero uses VCHAN0, every other func uses VCHAN1 */
	if (!IS_PCIX(pcibus_info) && PCI_FUNC(info->pdi_linux_pcidev->devfn))
		pci_addr |= PCI64_ATTR_VIRTUAL;

	return pci_addr;
}

__attribute__((used)) static dma_addr_t
pcibr_dmatrans_direct32(struct pcidev_info * info,
			u64 paddr, size_t req_size, u64 flags, int dma_flags)
{
	struct pcidev_info *pcidev_info = info->pdi_host_pcidev_info;
	struct pcibus_info *pcibus_info = (struct pcibus_info *)pcidev_info->
	    pdi_pcibus_info;
	u64 xio_addr;

	u64 xio_base;
	u64 offset;
	u64 endoff;

	if (IS_PCIX(pcibus_info)) {
		return 0;
	}

	if (dma_flags & SN_DMA_MSI)
		return 0;

	if (SN_DMA_ADDRTYPE(dma_flags) == SN_DMA_ADDR_PHYS)
		xio_addr = IS_PIC_SOFT(pcibus_info) ? PHYS_TO_DMA(paddr) :
	    					      PHYS_TO_TIODMA(paddr);
	else
		xio_addr = paddr;

	xio_base = pcibus_info->pbi_dir_xbase;
	offset = xio_addr - xio_base;
	endoff = req_size + offset;
	if ((req_size > (1ULL << 31)) ||	/* Too Big */
	    (xio_addr < xio_base) ||	/* Out of range for mappings */
	    (endoff > (1ULL << 31))) {	/* Too Big */
		return 0;
	}

	return PCI32_DIRECT_BASE | offset;
}

void
pcibr_dma_unmap(struct pci_dev *hwdev, dma_addr_t dma_handle, int direction)
{
	struct pcidev_info *pcidev_info = SN_PCIDEV_INFO(hwdev);
	struct pcibus_info *pcibus_info =
	    (struct pcibus_info *)pcidev_info->pdi_pcibus_info;

	if (IS_PCI32_MAPPED(dma_handle)) {
		int ate_index;

		ate_index =
		    IOPG((ATE_SWAP_OFF(dma_handle) - PCI32_MAPPED_BASE));
		pcibr_ate_free(pcibus_info, ate_index);
	}
}

void sn_dma_flush(u64 addr)
{
	nasid_t nasid;
	int is_tio;
	int wid_num;
	int i, j;
	unsigned long flags;
	u64 itte;
	struct hubdev_info *hubinfo;
	struct sn_flush_device_kernel *p;
	struct sn_flush_device_common *common;
	struct sn_flush_nasid_entry *flush_nasid_list;

	if (!sn_ioif_inited)
		return;

	nasid = NASID_GET(addr);
	if (-1 == nasid_to_cnodeid(nasid))
		return;

	hubinfo = (NODEPDA(nasid_to_cnodeid(nasid)))->pdinfo;

	BUG_ON(!hubinfo);

	flush_nasid_list = &hubinfo->hdi_flush_nasid_list;
	if (flush_nasid_list->widget_p == NULL)
		return;

	is_tio = (nasid & 1);
	if (is_tio) {
		int itte_index;

		if (TIO_HWIN(addr))
			itte_index = 0;
		else if (TIO_BWIN_WINDOWNUM(addr))
			itte_index = TIO_BWIN_WINDOWNUM(addr);
		else
			itte_index = -1;

		if (itte_index >= 0) {
			itte = flush_nasid_list->iio_itte[itte_index];
			if (! TIO_ITTE_VALID(itte))
				return;
			wid_num = TIO_ITTE_WIDGET(itte);
		} else
			wid_num = TIO_SWIN_WIDGETNUM(addr);
	} else {
		if (BWIN_WINDOWNUM(addr)) {
			itte = flush_nasid_list->iio_itte[BWIN_WINDOWNUM(addr)];
			wid_num = IIO_ITTE_WIDGET(itte);
		} else
			wid_num = SWIN_WIDGETNUM(addr);
	}
	if (flush_nasid_list->widget_p[wid_num] == NULL)
		return;
	p = &flush_nasid_list->widget_p[wid_num][0];

	/* find a matching BAR */
	for (i = 0; i < DEV_PER_WIDGET; i++,p++) {
		common = p->common;
		for (j = 0; j < PCI_ROM_RESOURCE; j++) {
			if (common->sfdl_bar_list[j].start == 0)
				break;
			if (addr >= common->sfdl_bar_list[j].start
			    && addr <= common->sfdl_bar_list[j].end)
				break;
		}
		if (j < PCI_ROM_RESOURCE && common->sfdl_bar_list[j].start != 0)
			break;
	}

	/* if no matching BAR, return without doing anything. */
	if (i == DEV_PER_WIDGET)
		return;

	/*
	 * For TIOCP use the Device(x) Write Request Buffer Flush Bridge
	 * register since it ensures the data has entered the coherence
	 * domain, unlike PIC.
	 */
	if (is_tio) {
		/*
	 	 * Note:  devices behind TIOCE should never be matched in the
		 * above code, and so the following code is PIC/CP centric.
		 * If CE ever needs the sn_dma_flush mechanism, we will have
		 * to account for that here and in tioce_bus_fixup().
	 	 */
		u32 tio_id = HUB_L(TIO_IOSPACE_ADDR(nasid, TIO_NODE_ID));
		u32 revnum = XWIDGET_PART_REV_NUM(tio_id);

		/* TIOCP BRINGUP WAR (PV907516): Don't write buffer flush reg */
		if ((1 << XWIDGET_PART_REV_NUM_REV(revnum)) & PV907516) {
			return;
		} else {
			pcireg_wrb_flush_get(common->sfdl_pcibus_info,
					     (common->sfdl_slot - 1));
		}
	} else {
		spin_lock_irqsave(&p->sfdl_flush_lock, flags);
		*common->sfdl_flush_addr = 0;

		/* force an interrupt. */
		*(volatile u32 *)(common->sfdl_force_int_addr) = 1;

		/* wait for the interrupt to come back. */
		while (*(common->sfdl_flush_addr) != 0x10f)
			cpu_relax();

		/* okay, everything is synched up. */
		spin_unlock_irqrestore(&p->sfdl_flush_lock, flags);
	}
	return;
}

dma_addr_t
pcibr_dma_map(struct pci_dev * hwdev, unsigned long phys_addr, size_t size, int dma_flags)
{
	dma_addr_t dma_handle;
	struct pcidev_info *pcidev_info = SN_PCIDEV_INFO(hwdev);

	/* SN cannot support DMA addresses smaller than 32 bits. */
	if (hwdev->dma_mask < 0x7fffffff) {
		return 0;
	}

	if (hwdev->dma_mask == ~0UL) {
		/*
		 * Handle the most common case: 64 bit cards.  This
		 * call should always succeed.
		 */

		dma_handle = pcibr_dmatrans_direct64(pcidev_info, phys_addr,
						     PCI64_ATTR_PREF, dma_flags);
	} else {
		/* Handle 32-63 bit cards via direct mapping */
		dma_handle = pcibr_dmatrans_direct32(pcidev_info, phys_addr,
						     size, 0, dma_flags);
		if (!dma_handle) {
			/*
			 * It is a 32 bit card and we cannot do direct mapping,
			 * so we use an ATE.
			 */

			dma_handle = pcibr_dmamap_ate32(pcidev_info, phys_addr,
							size, PCI32_ATE_PREF,
							dma_flags);
		}
	}

	return dma_handle;
}

dma_addr_t
pcibr_dma_map_consistent(struct pci_dev * hwdev, unsigned long phys_addr,
			 size_t size, int dma_flags)
{
	dma_addr_t dma_handle;
	struct pcidev_info *pcidev_info = SN_PCIDEV_INFO(hwdev);

	if (hwdev->dev.coherent_dma_mask == ~0UL) {
		dma_handle = pcibr_dmatrans_direct64(pcidev_info, phys_addr,
					    PCI64_ATTR_BAR, dma_flags);
	} else {
		dma_handle = (dma_addr_t) pcibr_dmamap_ate32(pcidev_info,
						    phys_addr, size,
						    PCI32_ATE_BAR, dma_flags);
	}

	return dma_handle;
}

