#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_12__   TYPE_5__ ;
typedef  struct TYPE_11__   TYPE_4__ ;
typedef  struct TYPE_10__   TYPE_3__ ;
typedef  struct TYPE_9__   TYPE_2__ ;
typedef  struct TYPE_8__   TYPE_1__ ;

/* Type definitions */
struct TYPE_8__ {int /*<<< orphan*/  irq_addr; } ;
struct TYPE_11__ {TYPE_1__ io_ports; } ;
typedef  TYPE_4__ ide_hwif_t ;
struct TYPE_12__ {TYPE_3__* hwif; } ;
typedef  TYPE_5__ ide_drive_t ;
struct TYPE_9__ {int /*<<< orphan*/  irq_addr; } ;
struct TYPE_10__ {TYPE_2__ io_ports; } ;

/* Variables and functions */
 unsigned char z_readb (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  z_writeb (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

__attribute__((used)) static int buddha_test_irq(ide_hwif_t *hwif)
{
    unsigned char ch;

    ch = z_readb(hwif->io_ports.irq_addr);
    if (!(ch & 0x80))
	    return 0;
    return 1;
}

__attribute__((used)) static void xsurf_clear_irq(ide_drive_t *drive)
{
    /*
     * X-Surf needs 0 written to IRQ register to ensure ISA bit A11 stays at 0
     */
    z_writeb(0, drive->hwif->io_ports.irq_addr);
}

