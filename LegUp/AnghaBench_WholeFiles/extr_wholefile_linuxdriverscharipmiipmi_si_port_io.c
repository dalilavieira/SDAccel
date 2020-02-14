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
struct si_sm_io {unsigned int addr_data; unsigned int regspacing; int regshift; int io_size; unsigned char (* inputb ) (struct si_sm_io const*,unsigned int) ;void (* outputb ) (struct si_sm_io const*,unsigned int,unsigned char) ;void (* io_cleanup ) (struct si_sm_io*) ;int /*<<< orphan*/  regsize; int /*<<< orphan*/  dev; } ;

/* Variables and functions */
 int /*<<< orphan*/  DEVICE_NAME ; 
 int EINVAL ; 
 int EIO ; 
 int ENODEV ; 
 int /*<<< orphan*/  dev_warn (int /*<<< orphan*/ ,char*,int /*<<< orphan*/ ) ; 
 unsigned char inb (unsigned int) ; 
 int inl (unsigned int) ; 
 int inw (unsigned int) ; 
 int /*<<< orphan*/  outb (unsigned char,unsigned int) ; 
 int /*<<< orphan*/  outl (unsigned char,unsigned int) ; 
 int /*<<< orphan*/  outw (unsigned char,unsigned int) ; 
 int /*<<< orphan*/  release_region (unsigned int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/ * request_region (unsigned int,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

__attribute__((used)) static inline void ipmi_si_pci_init(void) { }

__attribute__((used)) static inline void ipmi_si_pci_shutdown(void) { }

__attribute__((used)) static inline void ipmi_si_parisc_init(void) { }

__attribute__((used)) static inline void ipmi_si_parisc_shutdown(void) { }

__attribute__((used)) static unsigned char port_inb(const struct si_sm_io *io, unsigned int offset)
{
	unsigned int addr = io->addr_data;

	return inb(addr + (offset * io->regspacing));
}

__attribute__((used)) static void port_outb(const struct si_sm_io *io, unsigned int offset,
		      unsigned char b)
{
	unsigned int addr = io->addr_data;

	outb(b, addr + (offset * io->regspacing));
}

__attribute__((used)) static unsigned char port_inw(const struct si_sm_io *io, unsigned int offset)
{
	unsigned int addr = io->addr_data;

	return (inw(addr + (offset * io->regspacing)) >> io->regshift) & 0xff;
}

__attribute__((used)) static void port_outw(const struct si_sm_io *io, unsigned int offset,
		      unsigned char b)
{
	unsigned int addr = io->addr_data;

	outw(b << io->regshift, addr + (offset * io->regspacing));
}

__attribute__((used)) static unsigned char port_inl(const struct si_sm_io *io, unsigned int offset)
{
	unsigned int addr = io->addr_data;

	return (inl(addr + (offset * io->regspacing)) >> io->regshift) & 0xff;
}

__attribute__((used)) static void port_outl(const struct si_sm_io *io, unsigned int offset,
		      unsigned char b)
{
	unsigned int addr = io->addr_data;

	outl(b << io->regshift, addr+(offset * io->regspacing));
}

__attribute__((used)) static void port_cleanup(struct si_sm_io *io)
{
	unsigned int addr = io->addr_data;
	int          idx;

	if (addr) {
		for (idx = 0; idx < io->io_size; idx++)
			release_region(addr + idx * io->regspacing,
				       io->regsize);
	}
}

int ipmi_si_port_setup(struct si_sm_io *io)
{
	unsigned int addr = io->addr_data;
	int          idx;

	if (!addr)
		return -ENODEV;

	/*
	 * Figure out the actual inb/inw/inl/etc routine to use based
	 * upon the register size.
	 */
	switch (io->regsize) {
	case 1:
		io->inputb = port_inb;
		io->outputb = port_outb;
		break;
	case 2:
		io->inputb = port_inw;
		io->outputb = port_outw;
		break;
	case 4:
		io->inputb = port_inl;
		io->outputb = port_outl;
		break;
	default:
		dev_warn(io->dev, "Invalid register size: %d\n",
			 io->regsize);
		return -EINVAL;
	}

	/*
	 * Some BIOSes reserve disjoint I/O regions in their ACPI
	 * tables.  This causes problems when trying to register the
	 * entire I/O region.  Therefore we must register each I/O
	 * port separately.
	 */
	for (idx = 0; idx < io->io_size; idx++) {
		if (request_region(addr + idx * io->regspacing,
				   io->regsize, DEVICE_NAME) == NULL) {
			/* Undo allocations */
			while (idx--)
				release_region(addr + idx * io->regspacing,
					       io->regsize);
			return -EIO;
		}
	}

	io->io_cleanup = port_cleanup;

	return 0;
}

