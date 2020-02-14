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
typedef  size_t u_short ;
typedef  int u_char ;
struct cirrus_state {int misc1; int misc2; int* timer; } ;
typedef  int /*<<< orphan*/  irqreturn_t ;
struct TYPE_3__ {struct cirrus_state cirrus; } ;
struct TYPE_4__ {unsigned int ioaddr; TYPE_1__ state; int /*<<< orphan*/  psock; } ;

/* Variables and functions */
 size_t I365_CSC ; 
 void* I365_REG (int /*<<< orphan*/ ,size_t) ; 
 int /*<<< orphan*/  IRQ_HANDLED ; 
 int PD67_MC1_INPACK_ENA ; 
 int PD67_MC1_MEDIA_ENA ; 
 int PD67_MC2_SUSPEND ; 
 size_t PD67_MISC_CTL_1 ; 
 size_t PD67_MISC_CTL_2 ; 
 size_t PD67_TIME_SETUP (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  bus_lock ; 
 int /*<<< orphan*/  free_irq (int,int /*<<< orphan*/  (*) (int,void*)) ; 
static  int /*<<< orphan*/  i365_count_irq (int,void*) ; 
 int inb (unsigned int) ; 
 int /*<<< orphan*/  irq_hits ; 
 size_t irq_sock ; 
 int /*<<< orphan*/  mdelay (int) ; 
 int /*<<< orphan*/  outb (int,unsigned int) ; 
 int /*<<< orphan*/  pr_debug (char*,int) ; 
 scalar_t__ request_irq (int,int /*<<< orphan*/  (*) (int,void*),int,char*,int /*<<< orphan*/  (*) (int,void*)) ; 
 TYPE_2__* socket ; 
 int /*<<< orphan*/  spin_lock_irqsave (int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  spin_unlock_irqrestore (int /*<<< orphan*/ *,unsigned long) ; 

__attribute__((used)) static inline int _check_irq(int irq, int flags)
{
    if (request_irq(irq, i365_count_irq, flags, "x", i365_count_irq) != 0)
	return -1;
    free_irq(irq, i365_count_irq);
    return 0;
}

__attribute__((used)) static u_char i365_get(u_short sock, u_short reg)
{
    unsigned long flags;
    spin_lock_irqsave(&bus_lock,flags);
    {
	unsigned int port = socket[sock].ioaddr;
	u_char val;
	reg = I365_REG(socket[sock].psock, reg);
	outb(reg, port); val = inb(port+1);
	spin_unlock_irqrestore(&bus_lock,flags);
	return val;
    }
}

__attribute__((used)) static void i365_set(u_short sock, u_short reg, u_char data)
{
    unsigned long flags;
    spin_lock_irqsave(&bus_lock,flags);
    {
	unsigned int port = socket[sock].ioaddr;
	u_char val = I365_REG(socket[sock].psock, reg);
	outb(val, port); outb(data, port+1);
	spin_unlock_irqrestore(&bus_lock,flags);
    }
}

__attribute__((used)) static void i365_bset(u_short sock, u_short reg, u_char mask)
{
    u_char d = i365_get(sock, reg);
    d |= mask;
    i365_set(sock, reg, d);
}

__attribute__((used)) static void i365_bclr(u_short sock, u_short reg, u_char mask)
{
    u_char d = i365_get(sock, reg);
    d &= ~mask;
    i365_set(sock, reg, d);
}

__attribute__((used)) static void i365_bflip(u_short sock, u_short reg, u_char mask, int b)
{
    u_char d = i365_get(sock, reg);
    if (b)
	d |= mask;
    else
	d &= ~mask;
    i365_set(sock, reg, d);
}

__attribute__((used)) static u_short i365_get_pair(u_short sock, u_short reg)
{
    u_short a, b;
    a = i365_get(sock, reg);
    b = i365_get(sock, reg+1);
    return (a + (b<<8));
}

__attribute__((used)) static void i365_set_pair(u_short sock, u_short reg, u_short data)
{
    i365_set(sock, reg, data & 0xff);
    i365_set(sock, reg+1, data >> 8);
}

__attribute__((used)) static void cirrus_get_state(u_short s)
{
    int i;
    struct cirrus_state *p = &socket[s].state.cirrus;
    p->misc1 = i365_get(s, PD67_MISC_CTL_1);
    p->misc1 &= (PD67_MC1_MEDIA_ENA | PD67_MC1_INPACK_ENA);
    p->misc2 = i365_get(s, PD67_MISC_CTL_2);
    for (i = 0; i < 6; i++)
	p->timer[i] = i365_get(s, PD67_TIME_SETUP(0)+i);
}

__attribute__((used)) static void cirrus_set_state(u_short s)
{
    int i;
    u_char misc;
    struct cirrus_state *p = &socket[s].state.cirrus;

    misc = i365_get(s, PD67_MISC_CTL_2);
    i365_set(s, PD67_MISC_CTL_2, p->misc2);
    if (misc & PD67_MC2_SUSPEND) mdelay(50);
    misc = i365_get(s, PD67_MISC_CTL_1);
    misc &= ~(PD67_MC1_MEDIA_ENA | PD67_MC1_INPACK_ENA);
    i365_set(s, PD67_MISC_CTL_1, misc | p->misc1);
    for (i = 0; i < 6; i++)
	i365_set(s, PD67_TIME_SETUP(0)+i, p->timer[i]);
}

__attribute__((used)) static irqreturn_t i365_count_irq(int irq, void *dev)
{
    i365_get(irq_sock, I365_CSC);
    irq_hits++;
    pr_debug("i82365: -> hit on irq %d\n", irq);
    return IRQ_HANDLED;
}

