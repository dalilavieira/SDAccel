#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_10__   TYPE_4__ ;
typedef  struct TYPE_9__   TYPE_3__ ;
typedef  struct TYPE_8__   TYPE_2__ ;
typedef  struct TYPE_7__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  u16 ;
struct TYPE_7__ {void* ctl_addr; void* status_addr; void* device_addr; void* lbah_addr; void* lbam_addr; void* lbal_addr; void* nsect_addr; void* error_addr; int /*<<< orphan*/  data_addr; } ;
struct ide_hw {int irq; TYPE_1__ io_ports; } ;
struct ide_cmd {int tf_flags; } ;
struct TYPE_10__ {scalar_t__ media; TYPE_3__* hwif; } ;
typedef  TYPE_4__ ide_drive_t ;
struct TYPE_8__ {unsigned long data_addr; } ;
struct TYPE_9__ {TYPE_2__ io_ports; } ;

/* Variables and functions */
 int IDE_TFLAG_FS ; 
 void* Q40_ISA_IO_B (unsigned long) ; 
 int /*<<< orphan*/  Q40_ISA_IO_W (unsigned long) ; 
 int /*<<< orphan*/  __ide_mm_insw (unsigned long,void*,unsigned int) ; 
 int /*<<< orphan*/  __ide_mm_outsw (unsigned long,void*,unsigned int) ; 
 scalar_t__ ide_disk ; 
 int /*<<< orphan*/  memset (struct ide_hw*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  raw_insw_swapw (int /*<<< orphan*/ *,void*,unsigned int) ; 
 int /*<<< orphan*/  raw_outsw_swapw (int /*<<< orphan*/ *,void*,unsigned int) ; 

__attribute__((used)) static int q40ide_default_irq(unsigned long base)
{
           switch (base) {
	            case 0x1f0: return 14;
		    case 0x170: return 15;
		    case 0x1e8: return 11;
		    default:
			return 0;
	   }
}

__attribute__((used)) static void q40_ide_setup_ports(struct ide_hw *hw, unsigned long base, int irq)
{
	memset(hw, 0, sizeof(*hw));
	/* BIG FAT WARNING: 
	   assumption: only DATA port is ever used in 16 bit mode */
	hw->io_ports.data_addr = Q40_ISA_IO_W(base);
	hw->io_ports.error_addr = Q40_ISA_IO_B(base + 1);
	hw->io_ports.nsect_addr = Q40_ISA_IO_B(base + 2);
	hw->io_ports.lbal_addr = Q40_ISA_IO_B(base + 3);
	hw->io_ports.lbam_addr = Q40_ISA_IO_B(base + 4);
	hw->io_ports.lbah_addr = Q40_ISA_IO_B(base + 5);
	hw->io_ports.device_addr = Q40_ISA_IO_B(base + 6);
	hw->io_ports.status_addr = Q40_ISA_IO_B(base + 7);
	hw->io_ports.ctl_addr = Q40_ISA_IO_B(base + 0x206);

	hw->irq = irq;
}

__attribute__((used)) static void q40ide_input_data(ide_drive_t *drive, struct ide_cmd *cmd,
			      void *buf, unsigned int len)
{
	unsigned long data_addr = drive->hwif->io_ports.data_addr;

	if (drive->media == ide_disk && cmd && (cmd->tf_flags & IDE_TFLAG_FS)) {
		__ide_mm_insw(data_addr, buf, (len + 1) / 2);
		return;
	}

	raw_insw_swapw((u16 *)data_addr, buf, (len + 1) / 2);
}

__attribute__((used)) static void q40ide_output_data(ide_drive_t *drive, struct ide_cmd *cmd,
			       void *buf, unsigned int len)
{
	unsigned long data_addr = drive->hwif->io_ports.data_addr;

	if (drive->media == ide_disk && cmd && (cmd->tf_flags & IDE_TFLAG_FS)) {
		__ide_mm_outsw(data_addr, buf, (len + 1) / 2);
		return;
	}

	raw_outsw_swapw((u16 *)data_addr, buf, (len + 1) / 2);
}

