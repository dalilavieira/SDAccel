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
struct resource {unsigned long start; unsigned long end; } ;
struct ppc_pci_io {int dummy; } ;
struct pci_controller {unsigned long pci_io_size; struct device_node* dn; struct resource* mem_resources; scalar_t__ io_base_virt; } ;
struct iowa_bus {void* private; struct ppc_pci_io* ops; struct pci_controller* phb; } ;
struct device_node {int dummy; } ;
struct TYPE_2__ {int /*<<< orphan*/  ioremap; } ;
typedef  int /*<<< orphan*/  PCI_IO_ADDR ;

/* Variables and functions */
 int IOWA_MAX_BUS ; 
 int iowa_bus_count ; 
 struct iowa_bus* iowa_busses ; 
 int /*<<< orphan*/  iowa_ioremap ; 
 int /*<<< orphan*/  iowa_pci_io ; 
 TYPE_1__ ppc_md ; 
 int /*<<< orphan*/  ppc_pci_io ; 
 int /*<<< orphan*/  pr_debug (char*,int,struct device_node*) ; 
 int /*<<< orphan*/  pr_err (char*,struct device_node*) ; 
 int stub1 (struct iowa_bus*,void*) ; 

__attribute__((used)) static struct iowa_bus *iowa_pci_find(unsigned long vaddr, unsigned long paddr)
{
	int i, j;
	struct resource *res;
	unsigned long vstart, vend;

	for (i = 0; i < iowa_bus_count; i++) {
		struct iowa_bus *bus = &iowa_busses[i];
		struct pci_controller *phb = bus->phb;

		if (vaddr) {
			vstart = (unsigned long)phb->io_base_virt;
			vend = vstart + phb->pci_io_size - 1;
			if ((vaddr >= vstart) && (vaddr <= vend))
				return bus;
		}

		if (paddr)
			for (j = 0; j < 3; j++) {
				res = &phb->mem_resources[j];
				if (paddr >= res->start && paddr <= res->end)
					return bus;
			}
	}

	return NULL;
}

struct iowa_bus *iowa_mem_find_bus(const PCI_IO_ADDR addr)
{
	return NULL;
}

struct iowa_bus *iowa_pio_find_bus(unsigned long port)
{
	return NULL;
}

__attribute__((used)) static void io_workaround_init(void)
{
	static int io_workaround_inited;

	if (io_workaround_inited)
		return;
	ppc_pci_io = iowa_pci_io;
	ppc_md.ioremap = iowa_ioremap;
	io_workaround_inited = 1;
}

void iowa_register_bus(struct pci_controller *phb, struct ppc_pci_io *ops,
		       int (*initfunc)(struct iowa_bus *, void *), void *data)
{
	struct iowa_bus *bus;
	struct device_node *np = phb->dn;

	io_workaround_init();

	if (iowa_bus_count >= IOWA_MAX_BUS) {
		pr_err("IOWA:Too many pci bridges, "
		       "workarounds disabled for %pOF\n", np);
		return;
	}

	bus = &iowa_busses[iowa_bus_count];
	bus->phb = phb;
	bus->ops = ops;
	bus->private = data;

	if (initfunc)
		if ((*initfunc)(bus, data))
			return;

	iowa_bus_count++;

	pr_debug("IOWA:[%d]Add bus, %pOF.\n", iowa_bus_count-1, np);
}

