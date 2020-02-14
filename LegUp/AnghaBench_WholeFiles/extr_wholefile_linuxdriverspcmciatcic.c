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
typedef  int u_short ;
typedef  int u_int ;
typedef  int u_char ;

/* Variables and functions */
 int /*<<< orphan*/  TCIC_AUX ; 
 int /*<<< orphan*/  TCIC_MODE ; 
 int TCIC_MODE_PGMMASK ; 
 int cycle_time ; 
 int /*<<< orphan*/  outw (int,int) ; 
 int tcic_base ; 
 int tcic_getb (int /*<<< orphan*/ ) ; 
 int tcic_getw (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  tcic_setb (int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  tcic_setw (int /*<<< orphan*/ ,int) ; 

__attribute__((used)) static void tcic_setl(u_char reg, u_int data)
{
#ifdef DEBUG_X
    printk(KERN_DEBUG "tcic_setl(%#x, %#lx)\n", tcic_base+reg, data);
#endif
    outw(data & 0xffff, tcic_base+reg);
    outw(data >> 16, tcic_base+reg+2);
}

__attribute__((used)) static void tcic_aux_setb(u_short reg, u_char data)
{
    u_char mode = (tcic_getb(TCIC_MODE) & TCIC_MODE_PGMMASK) | reg;
    tcic_setb(TCIC_MODE, mode);
    tcic_setb(TCIC_AUX, data);
}

__attribute__((used)) static u_short tcic_aux_getw(u_short reg)
{
    u_char mode = (tcic_getb(TCIC_MODE) & TCIC_MODE_PGMMASK) | reg;
    tcic_setb(TCIC_MODE, mode);
    return tcic_getw(TCIC_AUX);
}

__attribute__((used)) static void tcic_aux_setw(u_short reg, u_short data)
{
    u_char mode = (tcic_getb(TCIC_MODE) & TCIC_MODE_PGMMASK) | reg;
    tcic_setb(TCIC_MODE, mode);
    tcic_setw(TCIC_AUX, data);
}

__attribute__((used)) static int to_cycles(int ns)
{
    if (ns < 14)
	return 0;
    else
	return 2*(ns-14)/cycle_time;
}

