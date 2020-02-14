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
struct mac_iop {int ram_addr_lo; int ram_addr_hi; void* ram_data; int status_ctrl; } ;
struct iop_msg {scalar_t__ status; } ;
typedef  void* __u8 ;
typedef  int __u16 ;

/* Variables and functions */
 int IOP_ADDR_ALIVE ; 
 int IOP_AUTOINC ; 
 int IOP_BYPASS ; 
 int IOP_IRQ ; 
 scalar_t__ IOP_MSGSTATUS_UNUSED ; 
 scalar_t__ IOP_MSGSTATUS_WAITING ; 
 int IOP_RUN ; 
 int NUM_IOP_MSGS ; 
 struct iop_msg* iop_msg_pool ; 
 int /*<<< orphan*/  local_irq_restore (unsigned long) ; 
 int /*<<< orphan*/  local_irq_save (unsigned long) ; 

__attribute__((used)) static __inline__ void iop_loadaddr(volatile struct mac_iop *iop, __u16 addr)
{
	iop->ram_addr_lo = addr;
	iop->ram_addr_hi = addr >> 8;
}

__attribute__((used)) static __inline__ __u8 iop_readb(volatile struct mac_iop *iop, __u16 addr)
{
	iop->ram_addr_lo = addr;
	iop->ram_addr_hi = addr >> 8;
	return iop->ram_data;
}

__attribute__((used)) static __inline__ void iop_writeb(volatile struct mac_iop *iop, __u16 addr, __u8 data)
{
	iop->ram_addr_lo = addr;
	iop->ram_addr_hi = addr >> 8;
	iop->ram_data = data;
}

__attribute__((used)) static __inline__ void iop_stop(volatile struct mac_iop *iop)
{
	iop->status_ctrl &= ~IOP_RUN;
}

__attribute__((used)) static __inline__ void iop_start(volatile struct mac_iop *iop)
{
	iop->status_ctrl = IOP_RUN | IOP_AUTOINC;
}

__attribute__((used)) static __inline__ void iop_bypass(volatile struct mac_iop *iop)
{
	iop->status_ctrl |= IOP_BYPASS;
}

__attribute__((used)) static __inline__ void iop_interrupt(volatile struct mac_iop *iop)
{
	iop->status_ctrl |= IOP_IRQ;
}

__attribute__((used)) static int iop_alive(volatile struct mac_iop *iop)
{
	int retval;

	retval = (iop_readb(iop, IOP_ADDR_ALIVE) == 0xFF);
	iop_writeb(iop, IOP_ADDR_ALIVE, 0);
	return retval;
}

__attribute__((used)) static struct iop_msg *iop_get_unused_msg(void)
{
	int i;
	unsigned long flags;

	local_irq_save(flags);

	for (i = 0 ; i < NUM_IOP_MSGS ; i++) {
		if (iop_msg_pool[i].status == IOP_MSGSTATUS_UNUSED) {
			iop_msg_pool[i].status = IOP_MSGSTATUS_WAITING;
			local_irq_restore(flags);
			return &iop_msg_pool[i];
		}
	}

	local_irq_restore(flags);
	return NULL;
}

