#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_15__   TYPE_3__ ;
typedef  struct TYPE_14__   TYPE_2__ ;
typedef  struct TYPE_13__   TYPE_1__ ;

/* Type definitions */
typedef  unsigned long u8 ;
struct TYPE_13__ {int /*<<< orphan*/  device_addr; int /*<<< orphan*/  status_addr; } ;
struct TYPE_14__ {TYPE_1__ io_ports; } ;
typedef  TYPE_2__ ide_hwif_t ;
struct TYPE_15__ {scalar_t__ media; int dev_flags; unsigned long select; unsigned long pio_mode; TYPE_2__* hwif; } ;
typedef  TYPE_3__ ide_drive_t ;

/* Variables and functions */
 unsigned long ATA_DEVICE_OBS ; 
 int /*<<< orphan*/  HT_CONFIG_PORT ; 
 unsigned long HT_PREFETCH_MODE ; 
 int IDE_DFLAG_NO_UNMASK ; 
 int IDE_DFLAG_PRESENT ; 
 int IDE_DFLAG_UNMASK ; 
 unsigned long XFER_PIO_0 ; 
 int /*<<< orphan*/  ht6560b_lock ; 
 unsigned long ht_pio2timings (TYPE_3__*,unsigned long const) ; 
 scalar_t__ ide_disk ; 
 scalar_t__ ide_get_drivedata (TYPE_3__*) ; 
 int /*<<< orphan*/  ide_set_drivedata (TYPE_3__*,void*) ; 
 int /*<<< orphan*/  inb (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  local_irq_restore (unsigned long) ; 
 int /*<<< orphan*/  local_irq_save (unsigned long) ; 
 int /*<<< orphan*/  outb (unsigned long,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  spin_lock_irqsave (int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  spin_unlock_irqrestore (int /*<<< orphan*/ *,unsigned long) ; 

__attribute__((used)) static inline u8 HT_CONFIG(ide_drive_t *drive)
{
	return ((unsigned long)ide_get_drivedata(drive) & 0xff00) >> 8;
}

__attribute__((used)) static inline u8 HT_TIMING(ide_drive_t *drive)
{
	return (unsigned long)ide_get_drivedata(drive) & 0x00ff;
}

__attribute__((used)) static void ht6560b_dev_select(ide_drive_t *drive)
{
	ide_hwif_t *hwif = drive->hwif;
	unsigned long flags;
	static u8 current_select = 0;
	static u8 current_timing = 0;
	u8 select, timing;
	
	local_irq_save(flags);

	select = HT_CONFIG(drive);
	timing = HT_TIMING(drive);

	/*
	 * Need to enforce prefetch sometimes because otherwise
	 * it'll hang (hard).
	 */
	if (drive->media != ide_disk ||
	    (drive->dev_flags & IDE_DFLAG_PRESENT) == 0)
		select |= HT_PREFETCH_MODE;

	if (select != current_select || timing != current_timing) {
		current_select = select;
		current_timing = timing;
		(void)inb(HT_CONFIG_PORT);
		(void)inb(HT_CONFIG_PORT);
		(void)inb(HT_CONFIG_PORT);
		(void)inb(HT_CONFIG_PORT);
		outb(select, HT_CONFIG_PORT);
		/*
		 * Set timing for this drive:
		 */
		outb(timing, hwif->io_ports.device_addr);
		(void)inb(hwif->io_ports.status_addr);
#ifdef DEBUG
		printk("ht6560b: %s: select=%#x timing=%#x\n",
			drive->name, select, timing);
#endif
	}
	local_irq_restore(flags);

	outb(drive->select | ATA_DEVICE_OBS, hwif->io_ports.device_addr);
}

__attribute__((used)) static void ht_set_prefetch(ide_drive_t *drive, u8 state)
{
	unsigned long flags, config;
	int t = HT_PREFETCH_MODE << 8;

	spin_lock_irqsave(&ht6560b_lock, flags);

	config = (unsigned long)ide_get_drivedata(drive);

	/*
	 *  Prefetch mode and unmask irq seems to conflict
	 */
	if (state) {
		config |= t;   /* enable prefetch mode */
		drive->dev_flags |= IDE_DFLAG_NO_UNMASK;
		drive->dev_flags &= ~IDE_DFLAG_UNMASK;
	} else {
		config &= ~t;  /* disable prefetch mode */
		drive->dev_flags &= ~IDE_DFLAG_NO_UNMASK;
	}

	ide_set_drivedata(drive, (void *)config);

	spin_unlock_irqrestore(&ht6560b_lock, flags);

#ifdef DEBUG
	printk("ht6560b: drive %s prefetch mode %sabled\n", drive->name, (state ? "en" : "dis"));
#endif
}

__attribute__((used)) static void ht6560b_set_pio_mode(ide_hwif_t *hwif, ide_drive_t *drive)
{
	unsigned long flags, config;
	const u8 pio = drive->pio_mode - XFER_PIO_0;
	u8 timing;
	
	switch (pio) {
	case 8:         /* set prefetch off */
	case 9:         /* set prefetch on */
		ht_set_prefetch(drive, pio & 1);
		return;
	}

	timing = ht_pio2timings(drive, pio);

	spin_lock_irqsave(&ht6560b_lock, flags);
	config = (unsigned long)ide_get_drivedata(drive);
	config &= 0xff00;
	config |= timing;
	ide_set_drivedata(drive, (void *)config);
	spin_unlock_irqrestore(&ht6560b_lock, flags);

#ifdef DEBUG
	printk("ht6560b: drive %s tuned to pio mode %#x timing=%#x\n", drive->name, pio, timing);
#endif
}

