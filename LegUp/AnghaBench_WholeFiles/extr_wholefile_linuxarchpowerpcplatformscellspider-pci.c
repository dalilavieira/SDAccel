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
typedef  int /*<<< orphan*/  u32 ;
struct spiderpci_iowa_private {scalar_t__ regs; } ;
struct iowa_bus {struct spiderpci_iowa_private* private; } ;
typedef  int /*<<< orphan*/  PCI_IO_ADDR ;

/* Variables and functions */
 scalar_t__ SPIDER_PCI_DUMMY_READ ; 
 int /*<<< orphan*/  __do_memcpy_fromio (void*,int /*<<< orphan*/  const,unsigned long) ; 
 int /*<<< orphan*/  in_be32 (scalar_t__) ; 
 int /*<<< orphan*/  iosync () ; 
 struct iowa_bus* iowa_mem_find_bus (int /*<<< orphan*/  const) ; 

__attribute__((used)) static void spiderpci_io_flush(struct iowa_bus *bus)
{
	struct spiderpci_iowa_private *priv;
	u32 val;

	priv = bus->private;
	val = in_be32(priv->regs + SPIDER_PCI_DUMMY_READ);
	iosync();
}

__attribute__((used)) static void spiderpci_memcpy_fromio(void *dest, const PCI_IO_ADDR src,
				    unsigned long n)
{
	__do_memcpy_fromio(dest, src, n);
	spiderpci_io_flush(iowa_mem_find_bus(src));
}

