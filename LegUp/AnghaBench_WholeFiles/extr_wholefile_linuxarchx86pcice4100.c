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
typedef  int u32 ;
struct TYPE_3__ {int value; int mask; } ;
struct sim_dev_reg {int reg; TYPE_1__ sim_reg; int /*<<< orphan*/  dev_func; } ;
struct TYPE_4__ {int /*<<< orphan*/  (* read ) (int /*<<< orphan*/ ,int,int /*<<< orphan*/ ,int,int,int*) ;} ;

/* Variables and functions */
 int /*<<< orphan*/  PCI_DEVFN (int,int /*<<< orphan*/ ) ; 
 TYPE_2__ pci_direct_conf1 ; 
 int /*<<< orphan*/  stub1 (int /*<<< orphan*/ ,int,int /*<<< orphan*/ ,int,int,int*) ; 
 int /*<<< orphan*/  stub2 (int /*<<< orphan*/ ,int,int /*<<< orphan*/ ,int,int,int*) ; 

__attribute__((used)) static void reg_init(struct sim_dev_reg *reg)
{
	pci_direct_conf1.read(0, 1, reg->dev_func, reg->reg, 4,
			      &reg->sim_reg.value);
}

__attribute__((used)) static void reg_read(struct sim_dev_reg *reg, u32 *value)
{
	*value = reg->sim_reg.value;
}

__attribute__((used)) static void reg_write(struct sim_dev_reg *reg, u32 value)
{
	reg->sim_reg.value = (value & reg->sim_reg.mask) |
		(reg->sim_reg.value & ~reg->sim_reg.mask);
}

__attribute__((used)) static void sata_reg_init(struct sim_dev_reg *reg)
{
	pci_direct_conf1.read(0, 1, PCI_DEVFN(14, 0), 0x10, 4,
			      &reg->sim_reg.value);
	reg->sim_reg.value += 0x400;
}

__attribute__((used)) static void ehci_reg_read(struct sim_dev_reg *reg, u32 *value)
{
	reg_read(reg, value);
	if (*value != reg->sim_reg.mask)
		*value |= 0x100;
}

void sata_revid_init(struct sim_dev_reg *reg)
{
	reg->sim_reg.value = 0x01060100;
	reg->sim_reg.mask = 0;
}

__attribute__((used)) static void sata_revid_read(struct sim_dev_reg *reg, u32 *value)
{
	reg_read(reg, value);
}

__attribute__((used)) static void reg_noirq_read(struct sim_dev_reg *reg, u32 *value)
{
	/* force interrupt pin value to 0 */
	*value = reg->sim_reg.value & 0xfff00ff;
}

