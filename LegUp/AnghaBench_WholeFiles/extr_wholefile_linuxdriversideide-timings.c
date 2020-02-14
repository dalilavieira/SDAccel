#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
typedef  int u8 ;
typedef  int u16 ;
struct ide_timing {int mode; int cycle; scalar_t__ setup; scalar_t__ act8b; scalar_t__ rec8b; scalar_t__ cyc8b; scalar_t__ active; scalar_t__ recover; scalar_t__ udma; } ;
typedef  int /*<<< orphan*/  p ;
struct TYPE_4__ {int* id; int pio_mode; } ;
typedef  TYPE_1__ ide_drive_t ;

/* Variables and functions */
 size_t ATA_ID_EIDE_DMA_MIN ; 
 size_t ATA_ID_EIDE_PIO ; 
 size_t ATA_ID_EIDE_PIO_IORDY ; 
 size_t ATA_ID_FIELD_VALID ; 
 int EINVAL ; 
 void* EZ (scalar_t__,int) ; 
 unsigned int IDE_TIMING_ACT8B ; 
 unsigned int IDE_TIMING_ACTIVE ; 
 unsigned int IDE_TIMING_ALL ; 
 unsigned int IDE_TIMING_CYC8B ; 
 unsigned int IDE_TIMING_CYCLE ; 
 unsigned int IDE_TIMING_REC8B ; 
 unsigned int IDE_TIMING_RECOVER ; 
 unsigned int IDE_TIMING_SETUP ; 
 unsigned int IDE_TIMING_UDMA ; 
 int XFER_MW_DMA_0 ; 
 int XFER_MW_DMA_2 ; 
 int XFER_PIO_0 ; 
 int XFER_PIO_2 ; 
 int XFER_PIO_4 ; 
 int XFER_PIO_5 ; 
 int XFER_SW_DMA_0 ; 
 scalar_t__ ata_id_has_iordy (int*) ; 
 scalar_t__ ata_id_is_cfa (int*) ; 
 struct ide_timing* ide_timing ; 
 void* max (scalar_t__,scalar_t__) ; 
 int /*<<< orphan*/  memset (struct ide_timing*,int /*<<< orphan*/ ,int) ; 

struct ide_timing *ide_timing_find_mode(u8 speed)
{
	struct ide_timing *t;

	for (t = ide_timing; t->mode != speed; t++)
		if (t->mode == 0xff)
			return NULL;
	return t;
}

u16 ide_pio_cycle_time(ide_drive_t *drive, u8 pio)
{
	u16 *id = drive->id;
	struct ide_timing *t = ide_timing_find_mode(XFER_PIO_0 + pio);
	u16 cycle = 0;

	if (id[ATA_ID_FIELD_VALID] & 2) {
		if (ata_id_has_iordy(drive->id))
			cycle = id[ATA_ID_EIDE_PIO_IORDY];
		else
			cycle = id[ATA_ID_EIDE_PIO];

		/* conservative "downgrade" for all pre-ATA2 drives */
		if (pio < 3 && cycle < t->cycle)
			cycle = 0; /* use standard timing */

		/* Use the standard timing for the CF specific modes too */
		if (pio > 4 && ata_id_is_cfa(id))
			cycle = 0;
	}

	return cycle ? cycle : t->cycle;
}

__attribute__((used)) static void ide_timing_quantize(struct ide_timing *t, struct ide_timing *q,
				int T, int UT)
{
	q->setup   = EZ(t->setup,   T);
	q->act8b   = EZ(t->act8b,   T);
	q->rec8b   = EZ(t->rec8b,   T);
	q->cyc8b   = EZ(t->cyc8b,   T);
	q->active  = EZ(t->active,  T);
	q->recover = EZ(t->recover, T);
	q->cycle   = EZ(t->cycle,   T);
	q->udma    = EZ(t->udma,    UT);
}

void ide_timing_merge(struct ide_timing *a, struct ide_timing *b,
		      struct ide_timing *m, unsigned int what)
{
	if (what & IDE_TIMING_SETUP)
		m->setup   = max(a->setup,   b->setup);
	if (what & IDE_TIMING_ACT8B)
		m->act8b   = max(a->act8b,   b->act8b);
	if (what & IDE_TIMING_REC8B)
		m->rec8b   = max(a->rec8b,   b->rec8b);
	if (what & IDE_TIMING_CYC8B)
		m->cyc8b   = max(a->cyc8b,   b->cyc8b);
	if (what & IDE_TIMING_ACTIVE)
		m->active  = max(a->active,  b->active);
	if (what & IDE_TIMING_RECOVER)
		m->recover = max(a->recover, b->recover);
	if (what & IDE_TIMING_CYCLE)
		m->cycle   = max(a->cycle,   b->cycle);
	if (what & IDE_TIMING_UDMA)
		m->udma    = max(a->udma,    b->udma);
}

int ide_timing_compute(ide_drive_t *drive, u8 speed,
		       struct ide_timing *t, int T, int UT)
{
	u16 *id = drive->id;
	struct ide_timing *s, p;

	/*
	 * Find the mode.
	 */
	s = ide_timing_find_mode(speed);
	if (s == NULL)
		return -EINVAL;

	/*
	 * Copy the timing from the table.
	 */
	*t = *s;

	/*
	 * If the drive is an EIDE drive, it can tell us it needs extended
	 * PIO/MWDMA cycle timing.
	 */
	if (id[ATA_ID_FIELD_VALID] & 2) {	/* EIDE drive */
		memset(&p, 0, sizeof(p));

		if (speed >= XFER_PIO_0 && speed < XFER_SW_DMA_0) {
			if (speed <= XFER_PIO_2)
				p.cycle = p.cyc8b = id[ATA_ID_EIDE_PIO];
			else if ((speed <= XFER_PIO_4) ||
				 (speed == XFER_PIO_5 && !ata_id_is_cfa(id)))
				p.cycle = p.cyc8b = id[ATA_ID_EIDE_PIO_IORDY];
		} else if (speed >= XFER_MW_DMA_0 && speed <= XFER_MW_DMA_2)
			p.cycle = id[ATA_ID_EIDE_DMA_MIN];

		ide_timing_merge(&p, t, t, IDE_TIMING_CYCLE | IDE_TIMING_CYC8B);
	}

	/*
	 * Convert the timing to bus clock counts.
	 */
	ide_timing_quantize(t, t, T, UT);

	/*
	 * Even in DMA/UDMA modes we still use PIO access for IDENTIFY,
	 * S.M.A.R.T and some other commands. We have to ensure that the
	 * DMA cycle timing is slower/equal than the current PIO timing.
	 */
	if (speed >= XFER_SW_DMA_0) {
		ide_timing_compute(drive, drive->pio_mode, &p, T, UT);
		ide_timing_merge(&p, t, t, IDE_TIMING_ALL);
	}

	/*
	 * Lengthen active & recovery time so that cycle time is correct.
	 */
	if (t->act8b + t->rec8b < t->cyc8b) {
		t->act8b += (t->cyc8b - (t->act8b + t->rec8b)) / 2;
		t->rec8b = t->cyc8b - t->act8b;
	}

	if (t->active + t->recover < t->cycle) {
		t->active += (t->cycle - (t->active + t->recover)) / 2;
		t->recover = t->cycle - t->active;
	}

	return 0;
}

