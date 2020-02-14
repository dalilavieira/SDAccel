#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_12__   TYPE_9__ ;
typedef  struct TYPE_11__   TYPE_2__ ;
typedef  struct TYPE_10__   TYPE_1__ ;

/* Type definitions */
struct _pci_bar {unsigned long data; } ;
struct TYPE_11__ {TYPE_1__* cfg; } ;
typedef  TYPE_2__ pci_desc ;
typedef  int /*<<< orphan*/  pci_cfg ;
struct TYPE_12__ {int /*<<< orphan*/ * cfg; } ;
struct TYPE_10__ {unsigned long addr; unsigned long data; } ;
typedef  int /*<<< orphan*/  PCONFIGURATION_COMPONENT_DATA ;

/* Variables and functions */
 int PCI_BASECLASS ; 
 int PCI_DEVICEID ; 
 int PCI_HEADER_TYPE ; 
 int PCI_VENDORID ; 
 TYPE_9__ pci1_desc ; 
 unsigned long pci_cfg_addr (int,int,int,int) ; 
 int /*<<< orphan*/  printf (char*,...) ; 
 void* rev32 (unsigned long) ; 
 int /*<<< orphan*/  sync () ; 
 int /*<<< orphan*/  vga1_desc ; 
 int /*<<< orphan*/  vga_setup (int /*<<< orphan*/ ,TYPE_2__*,int /*<<< orphan*/ *,int,int,int) ; 

unsigned long pci_read( pci_desc *desc, int bus, int dev, int fn, int reg, int len ) {
    sync();
    unsigned long save_state = desc->cfg->addr, ret = 0;
    unsigned long addr = pci_cfg_addr(bus,dev,fn,reg);
    unsigned long offset = reg & 3;
    desc->cfg->addr = rev32(addr);
    sync();
    switch( len ) {
    case 4:
        ret = desc->cfg->data;
        break;
    case 2:
        ret = desc->cfg->data;
        ret = (ret >> (offset << 3)) & 0xffff;
        break;
    case 1:
        ret = desc->cfg->data;
        ret = (ret >> (offset << 3)) & 0xff;
        break;
    }
    desc->cfg->addr = save_state;
    sync();
    return ret;
    }

void pci_read_bar( pci_desc *desc, int bus, int dev, int fn, int bar,
           struct _pci_bar *bar_data ) {
    bar_data->data = pci_read( desc, bus, dev, fn, 0x10 + (bar * 4), 4 );
}

void pci_write( pci_desc *desc, int bus, int dev, int fn, int reg, int len, int val ) {
    unsigned long save_state = desc->cfg->addr;
    unsigned long addr = pci_cfg_addr(bus,dev,fn,reg);
    unsigned long offset = reg & 3;
    unsigned long oldval = pci_read( desc, bus, dev, fn, reg & ~3, 4 );
    unsigned long mask = ((1 << (len * 8)) - 1) << (offset << 3);
    oldval = (oldval & ~mask) | ((val << (offset << 3)) & mask);
    desc->cfg->addr = rev32(addr);
    sync();
    desc->cfg->data = rev32(oldval);
    sync();
    desc->cfg->addr = save_state;
    sync();
}

void pci_write_bar( pci_desc *desc, int bus, int dev, int fn, int bar, struct _pci_bar *bar_data ) {
    pci_write( desc, bus, dev, fn, 0x10 + (bar * 4), 4, bar_data->data );
}

void print_bar( struct _pci_bar *bar ) {
    printf("BAR: %x\n", bar->data);
}

void pci_setup( PCONFIGURATION_COMPONENT_DATA pcibus, pci_desc *desc ) {
    unsigned char type;
    unsigned short vendor, device, devclass;
    int funcs, bus, dev, fn;

    pci1_desc.cfg = (pci_cfg *)0x80000cf8;

    printf("PCI Bus:\n");
    for( bus = 0; bus < 1; bus++ ) {
        for( dev = 0; dev < 32; dev++ ) {
            type = pci_read(desc,bus,dev,0,PCI_HEADER_TYPE,1);
            vendor = pci_read(desc,bus,dev,0,PCI_VENDORID,2);
            device = pci_read(desc,bus,dev,0,PCI_DEVICEID,2);

            if(vendor == 0 || vendor == 0xffff) continue;
            if(type & 0x80) funcs = 8; else funcs = 1;

            for( fn = 0; fn < funcs; fn++ ) {
                devclass = pci_read(desc,bus,dev,fn,PCI_BASECLASS,1);
        printf(" %d:%d -> vendor:device:class %x:%x:%x\n",
               bus, dev, vendor, device, devclass);

                if( devclass == 3 ) {
            printf("Setting up vga...\n");
                    vga_setup(pcibus,desc,&vga1_desc,bus,dev,fn);
            printf("Done with vga\n");
                }
            }
        }
    }
    printf("^-- end PCI\n");
}

