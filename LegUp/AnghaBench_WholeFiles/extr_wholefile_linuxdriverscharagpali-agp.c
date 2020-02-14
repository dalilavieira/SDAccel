#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_5__   TYPE_2__ ;
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
typedef  scalar_t__ u8 ;
typedef  int u32 ;
struct pci_device_id {int dummy; } ;
struct pci_dev {scalar_t__ device; int /*<<< orphan*/  dev; int /*<<< orphan*/  vendor; } ;
struct page {int dummy; } ;
struct aper_size_info_32 {int size_value; int size; int page_order; } ;
struct agp_memory {int /*<<< orphan*/  pages; } ;
struct agp_device_ids {char* chipset_name; scalar_t__ device_id; } ;
struct agp_bridge_data {int mode; scalar_t__ capndx; int /*<<< orphan*/ * driver; struct pci_dev* dev; } ;
struct TYPE_5__ {int aperture_size_idx; int gatt_bus_addr; struct pci_dev* dev; void* current_size; int /*<<< orphan*/  gart_bus_addr; void* previous_size; TYPE_1__* driver; } ;
struct TYPE_4__ {int num_aperture_sizes; void* aperture_sizes; } ;

/* Variables and functions */
 int /*<<< orphan*/  AGP_APERTURE_BAR ; 
 int AGP_PAGE_DESTROY_UNMAP ; 
 scalar_t__ ALI_ATTBASE ; 
 int ALI_CACHE_FLUSH_ADDR_MASK ; 
 scalar_t__ ALI_CACHE_FLUSH_CTRL ; 
 int ALI_CACHE_FLUSH_EN ; 
 scalar_t__ ALI_TAGCTRL ; 
 scalar_t__ ALI_TLBCTRL ; 
 struct aper_size_info_32* A_SIZE_32 (void*) ; 
 int ENODEV ; 
 int ENOMEM ; 
 int PAGE_SIZE ; 
 scalar_t__ PCI_AGP_STATUS ; 
 int /*<<< orphan*/  PCI_CAP_ID_AGP ; 
#define  PCI_DEVICE_ID_AL_M1541 129 
#define  PCI_DEVICE_ID_AL_M1621 128 
 int agp_add_bridge (struct agp_bridge_data*) ; 
 struct agp_bridge_data* agp_alloc_bridge () ; 
 TYPE_2__* agp_bridge ; 
 struct page* agp_generic_alloc_page (TYPE_2__*) ; 
 int /*<<< orphan*/  agp_generic_destroy_page (struct page*,int) ; 
 int /*<<< orphan*/  agp_put_bridge (struct agp_bridge_data*) ; 
 int /*<<< orphan*/  agp_remove_bridge (struct agp_bridge_data*) ; 
 struct agp_device_ids* ali_agp_device_ids ; 
 int /*<<< orphan*/  ali_generic_bridge ; 
 int /*<<< orphan*/  ali_m1541_bridge ; 
 int /*<<< orphan*/  dev_err (int /*<<< orphan*/ *,char*,int /*<<< orphan*/ ,scalar_t__) ; 
 int /*<<< orphan*/  dev_info (int /*<<< orphan*/ *,char*,char*) ; 
 int /*<<< orphan*/  global_cache_flush () ; 
 int /*<<< orphan*/  kvfree (int /*<<< orphan*/ ) ; 
 int page_to_phys (struct page*) ; 
 int /*<<< orphan*/  pci_bus_address (struct pci_dev*,int /*<<< orphan*/ ) ; 
 scalar_t__ pci_find_capability (struct pci_dev*,int /*<<< orphan*/ ) ; 
 struct agp_bridge_data* pci_get_drvdata (struct pci_dev*) ; 
 int /*<<< orphan*/  pci_read_config_byte (struct pci_dev*,int,scalar_t__*) ; 
 int /*<<< orphan*/  pci_read_config_dword (struct pci_dev*,scalar_t__,int*) ; 
 int /*<<< orphan*/  pci_set_drvdata (struct pci_dev*,struct agp_bridge_data*) ; 
 int /*<<< orphan*/  pci_write_config_dword (struct pci_dev*,scalar_t__,int) ; 

__attribute__((used)) static inline void agp_free_page_array(struct agp_memory *mem)
{
	kvfree(mem->pages);
}

__attribute__((used)) static int ali_fetch_size(void)
{
	int i;
	u32 temp;
	struct aper_size_info_32 *values;

	pci_read_config_dword(agp_bridge->dev, ALI_ATTBASE, &temp);
	temp &= ~(0xfffffff0);
	values = A_SIZE_32(agp_bridge->driver->aperture_sizes);

	for (i = 0; i < agp_bridge->driver->num_aperture_sizes; i++) {
		if (temp == values[i].size_value) {
			agp_bridge->previous_size =
			    agp_bridge->current_size = (void *) (values + i);
			agp_bridge->aperture_size_idx = i;
			return values[i].size;
		}
	}

	return 0;
}

__attribute__((used)) static void ali_tlbflush(struct agp_memory *mem)
{
	u32 temp;

	pci_read_config_dword(agp_bridge->dev, ALI_TLBCTRL, &temp);
	temp &= 0xfffffff0;
	temp |= (1<<0 | 1<<1);
	pci_write_config_dword(agp_bridge->dev, ALI_TAGCTRL, temp);
}

__attribute__((used)) static void ali_cleanup(void)
{
	struct aper_size_info_32 *previous_size;
	u32 temp;

	previous_size = A_SIZE_32(agp_bridge->previous_size);

	pci_read_config_dword(agp_bridge->dev, ALI_TLBCTRL, &temp);
// clear tag
	pci_write_config_dword(agp_bridge->dev, ALI_TAGCTRL,
			((temp & 0xffffff00) | 0x00000001|0x00000002));

	pci_read_config_dword(agp_bridge->dev,  ALI_ATTBASE, &temp);
	pci_write_config_dword(agp_bridge->dev, ALI_ATTBASE,
			((temp & 0x00000ff0) | previous_size->size_value));
}

__attribute__((used)) static int ali_configure(void)
{
	u32 temp;
	struct aper_size_info_32 *current_size;

	current_size = A_SIZE_32(agp_bridge->current_size);

	/* aperture size and gatt addr */
	pci_read_config_dword(agp_bridge->dev, ALI_ATTBASE, &temp);
	temp = (((temp & 0x00000ff0) | (agp_bridge->gatt_bus_addr & 0xfffff000))
			| (current_size->size_value & 0xf));
	pci_write_config_dword(agp_bridge->dev, ALI_ATTBASE, temp);

	/* tlb control */
	pci_read_config_dword(agp_bridge->dev, ALI_TLBCTRL, &temp);
	pci_write_config_dword(agp_bridge->dev, ALI_TLBCTRL, ((temp & 0xffffff00) | 0x00000010));

	/* address to map to */
	agp_bridge->gart_bus_addr = pci_bus_address(agp_bridge->dev,
						    AGP_APERTURE_BAR);

#if 0
	if (agp_bridge->type == ALI_M1541) {
		u32 nlvm_addr = 0;

		switch (current_size->size_value) {
			case 0:  break;
			case 1:  nlvm_addr = 0x100000;break;
			case 2:  nlvm_addr = 0x200000;break;
			case 3:  nlvm_addr = 0x400000;break;
			case 4:  nlvm_addr = 0x800000;break;
			case 6:  nlvm_addr = 0x1000000;break;
			case 7:  nlvm_addr = 0x2000000;break;
			case 8:  nlvm_addr = 0x4000000;break;
			case 9:  nlvm_addr = 0x8000000;break;
			case 10: nlvm_addr = 0x10000000;break;
			default: break;
		}
		nlvm_addr--;
		nlvm_addr&=0xfff00000;

		nlvm_addr+= agp_bridge->gart_bus_addr;
		nlvm_addr|=(agp_bridge->gart_bus_addr>>12);
		dev_info(&agp_bridge->dev->dev, "nlvm top &base = %8x\n",
			 nlvm_addr);
	}
#endif

	pci_read_config_dword(agp_bridge->dev, ALI_TLBCTRL, &temp);
	temp &= 0xffffff7f;		//enable TLB
	pci_write_config_dword(agp_bridge->dev, ALI_TLBCTRL, temp);

	return 0;
}

__attribute__((used)) static void m1541_cache_flush(void)
{
	int i, page_count;
	u32 temp;

	global_cache_flush();

	page_count = 1 << A_SIZE_32(agp_bridge->current_size)->page_order;
	for (i = 0; i < PAGE_SIZE * page_count; i += PAGE_SIZE) {
		pci_read_config_dword(agp_bridge->dev, ALI_CACHE_FLUSH_CTRL,
				&temp);
		pci_write_config_dword(agp_bridge->dev, ALI_CACHE_FLUSH_CTRL,
				(((temp & ALI_CACHE_FLUSH_ADDR_MASK) |
				  (agp_bridge->gatt_bus_addr + i)) |
				 ALI_CACHE_FLUSH_EN));
	}
}

__attribute__((used)) static struct page *m1541_alloc_page(struct agp_bridge_data *bridge)
{
	struct page *page = agp_generic_alloc_page(agp_bridge);
	u32 temp;

	if (!page)
		return NULL;

	pci_read_config_dword(agp_bridge->dev, ALI_CACHE_FLUSH_CTRL, &temp);
	pci_write_config_dword(agp_bridge->dev, ALI_CACHE_FLUSH_CTRL,
			(((temp & ALI_CACHE_FLUSH_ADDR_MASK) |
			  page_to_phys(page)) | ALI_CACHE_FLUSH_EN ));
	return page;
}

__attribute__((used)) static void ali_destroy_page(struct page *page, int flags)
{
	if (page) {
		if (flags & AGP_PAGE_DESTROY_UNMAP) {
			global_cache_flush();	/* is this really needed?  --hch */
			agp_generic_destroy_page(page, flags);
		} else
			agp_generic_destroy_page(page, flags);
	}
}

__attribute__((used)) static void m1541_destroy_page(struct page *page, int flags)
{
	u32 temp;

	if (page == NULL)
		return;

	if (flags & AGP_PAGE_DESTROY_UNMAP) {
		global_cache_flush();

		pci_read_config_dword(agp_bridge->dev, ALI_CACHE_FLUSH_CTRL, &temp);
		pci_write_config_dword(agp_bridge->dev, ALI_CACHE_FLUSH_CTRL,
				       (((temp & ALI_CACHE_FLUSH_ADDR_MASK) |
					 page_to_phys(page)) | ALI_CACHE_FLUSH_EN));
	}
	agp_generic_destroy_page(page, flags);
}

__attribute__((used)) static int agp_ali_probe(struct pci_dev *pdev, const struct pci_device_id *ent)
{
	struct agp_device_ids *devs = ali_agp_device_ids;
	struct agp_bridge_data *bridge;
	u8 hidden_1621_id, cap_ptr;
	int j;

	cap_ptr = pci_find_capability(pdev, PCI_CAP_ID_AGP);
	if (!cap_ptr)
		return -ENODEV;

	/* probe for known chipsets */
	for (j = 0; devs[j].chipset_name; j++) {
		if (pdev->device == devs[j].device_id)
			goto found;
	}

	dev_err(&pdev->dev, "unsupported ALi chipset [%04x/%04x])\n",
		pdev->vendor, pdev->device);
	return -ENODEV;


found:
	bridge = agp_alloc_bridge();
	if (!bridge)
		return -ENOMEM;

	bridge->dev = pdev;
	bridge->capndx = cap_ptr;

	switch (pdev->device) {
	case PCI_DEVICE_ID_AL_M1541:
		bridge->driver = &ali_m1541_bridge;
		break;
	case PCI_DEVICE_ID_AL_M1621:
		pci_read_config_byte(pdev, 0xFB, &hidden_1621_id);
		switch (hidden_1621_id) {
		case 0x31:
			devs[j].chipset_name = "M1631";
			break;
		case 0x32:
			devs[j].chipset_name = "M1632";
			break;
		case 0x41:
			devs[j].chipset_name = "M1641";
			break;
		case 0x43:
			devs[j].chipset_name = "M1621";
			break;
		case 0x47:
			devs[j].chipset_name = "M1647";
			break;
		case 0x51:
			devs[j].chipset_name = "M1651";
			break;
		default:
			break;
		}
		/*FALLTHROUGH*/
	default:
		bridge->driver = &ali_generic_bridge;
	}

	dev_info(&pdev->dev, "ALi %s chipset\n", devs[j].chipset_name);

	/* Fill in the mode register */
	pci_read_config_dword(pdev,
			bridge->capndx+PCI_AGP_STATUS,
			&bridge->mode);

	pci_set_drvdata(pdev, bridge);
	return agp_add_bridge(bridge);
}

__attribute__((used)) static void agp_ali_remove(struct pci_dev *pdev)
{
	struct agp_bridge_data *bridge = pci_get_drvdata(pdev);

	agp_remove_bridge(bridge);
	agp_put_bridge(bridge);
}

