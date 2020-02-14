#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_7__   TYPE_3__ ;
typedef  struct TYPE_6__   TYPE_2__ ;
typedef  struct TYPE_5__   TYPE_1__ ;

/* Type definitions */
typedef  scalar_t__ ulong ;
typedef  scalar_t__ u32 ;
typedef  int /*<<< orphan*/  tmp ;
struct rootsector {struct partition_info* part; } ;
struct partition_info {int flg; char* id; int /*<<< orphan*/  st; int /*<<< orphan*/  siz; } ;
struct parsed_partitions {int access_beyond_eod; int limit; char* name; int /*<<< orphan*/  pp_buf; TYPE_3__* bdev; TYPE_1__* parts; } ;
typedef  scalar_t__ sector_t ;
struct TYPE_7__ {TYPE_2__* bd_inode; int /*<<< orphan*/  bd_disk; } ;
struct TYPE_6__ {int i_size; } ;
struct TYPE_5__ {scalar_t__ size; scalar_t__ from; } ;
typedef  int /*<<< orphan*/  Sector ;

/* Variables and functions */
 int /*<<< orphan*/  BDEVNAME_SIZE ; 
 int /*<<< orphan*/  PAGE_SIZE ; 
 int /*<<< orphan*/  VALID_PARTITION (struct partition_info*,scalar_t__) ; 
 int bdev_logical_block_size (TYPE_3__*) ; 
 scalar_t__ be32_to_cpu (int /*<<< orphan*/ ) ; 
 scalar_t__ get_capacity (int /*<<< orphan*/ ) ; 
 scalar_t__ memcmp (char*,char*,int) ; 
 int /*<<< orphan*/  printk (char*,...) ; 
 int /*<<< orphan*/  put_dev_sector (int /*<<< orphan*/ ) ; 
 void* read_dev_sector (TYPE_3__*,scalar_t__,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  snprintf (char*,int,char*,char*,int) ; 
 int /*<<< orphan*/  strlcat (int /*<<< orphan*/ ,char*,int /*<<< orphan*/ ) ; 

__attribute__((used)) static inline void *read_part_sector(struct parsed_partitions *state,
				     sector_t n, Sector *p)
{
	if (n >= get_capacity(state->bdev->bd_disk)) {
		state->access_beyond_eod = true;
		return NULL;
	}
	return read_dev_sector(state->bdev, n, p);
}

__attribute__((used)) static inline void
put_partition(struct parsed_partitions *p, int n, sector_t from, sector_t size)
{
	if (n < p->limit) {
		char tmp[1 + BDEVNAME_SIZE + 10 + 1];

		p->parts[n].from = from;
		p->parts[n].size = size;
		snprintf(tmp, sizeof(tmp), " %s%d", p->name, n);
		strlcat(p->pp_buf, tmp, PAGE_SIZE);
	}
}

__attribute__((used)) static inline int OK_id(char *s)
{
	return  memcmp (s, "GEM", 3) == 0 || memcmp (s, "BGM", 3) == 0 ||
		memcmp (s, "LNX", 3) == 0 || memcmp (s, "SWP", 3) == 0 ||
		memcmp (s, "RAW", 3) == 0 ;
}

int atari_partition(struct parsed_partitions *state)
{
	Sector sect;
	struct rootsector *rs;
	struct partition_info *pi;
	u32 extensect;
	u32 hd_size;
	int slot;
#ifdef ICD_PARTS
	int part_fmt = 0; /* 0:unknown, 1:AHDI, 2:ICD/Supra */
#endif

	/*
	 * ATARI partition scheme supports 512 lba only.  If this is not
	 * the case, bail early to avoid miscalculating hd_size.
	 */
	if (bdev_logical_block_size(state->bdev) != 512)
		return 0;

	rs = read_part_sector(state, 0, &sect);
	if (!rs)
		return -1;

	/* Verify this is an Atari rootsector: */
	hd_size = state->bdev->bd_inode->i_size >> 9;
	if (!VALID_PARTITION(&rs->part[0], hd_size) &&
	    !VALID_PARTITION(&rs->part[1], hd_size) &&
	    !VALID_PARTITION(&rs->part[2], hd_size) &&
	    !VALID_PARTITION(&rs->part[3], hd_size)) {
		/*
		 * if there's no valid primary partition, assume that no Atari
		 * format partition table (there's no reliable magic or the like
	         * :-()
		 */
		put_dev_sector(sect);
		return 0;
	}

	pi = &rs->part[0];
	strlcat(state->pp_buf, " AHDI", PAGE_SIZE);
	for (slot = 1; pi < &rs->part[4] && slot < state->limit; slot++, pi++) {
		struct rootsector *xrs;
		Sector sect2;
		ulong partsect;

		if ( !(pi->flg & 1) )
			continue;
		/* active partition */
		if (memcmp (pi->id, "XGM", 3) != 0) {
			/* we don't care about other id's */
			put_partition (state, slot, be32_to_cpu(pi->st),
					be32_to_cpu(pi->siz));
			continue;
		}
		/* extension partition */
#ifdef ICD_PARTS
		part_fmt = 1;
#endif
		strlcat(state->pp_buf, " XGM<", PAGE_SIZE);
		partsect = extensect = be32_to_cpu(pi->st);
		while (1) {
			xrs = read_part_sector(state, partsect, &sect2);
			if (!xrs) {
				printk (" block %ld read failed\n", partsect);
				put_dev_sector(sect);
				return -1;
			}

			/* ++roman: sanity check: bit 0 of flg field must be set */
			if (!(xrs->part[0].flg & 1)) {
				printk( "\nFirst sub-partition in extended partition is not valid!\n" );
				put_dev_sector(sect2);
				break;
			}

			put_partition(state, slot,
				   partsect + be32_to_cpu(xrs->part[0].st),
				   be32_to_cpu(xrs->part[0].siz));

			if (!(xrs->part[1].flg & 1)) {
				/* end of linked partition list */
				put_dev_sector(sect2);
				break;
			}
			if (memcmp( xrs->part[1].id, "XGM", 3 ) != 0) {
				printk("\nID of extended partition is not XGM!\n");
				put_dev_sector(sect2);
				break;
			}

			partsect = be32_to_cpu(xrs->part[1].st) + extensect;
			put_dev_sector(sect2);
			if (++slot == state->limit) {
				printk( "\nMaximum number of partitions reached!\n" );
				break;
			}
		}
		strlcat(state->pp_buf, " >", PAGE_SIZE);
	}
#ifdef ICD_PARTS
	if ( part_fmt!=1 ) { /* no extended partitions -> test ICD-format */
		pi = &rs->icdpart[0];
		/* sanity check: no ICD format if first partition invalid */
		if (OK_id(pi->id)) {
			strlcat(state->pp_buf, " ICD<", PAGE_SIZE);
			for (; pi < &rs->icdpart[8] && slot < state->limit; slot++, pi++) {
				/* accept only GEM,BGM,RAW,LNX,SWP partitions */
				if (!((pi->flg & 1) && OK_id(pi->id)))
					continue;
				part_fmt = 2;
				put_partition (state, slot,
						be32_to_cpu(pi->st),
						be32_to_cpu(pi->siz));
			}
			strlcat(state->pp_buf, " >", PAGE_SIZE);
		}
	}
#endif
	put_dev_sector(sect);

	strlcat(state->pp_buf, "\n", PAGE_SIZE);

	return 1;
}

