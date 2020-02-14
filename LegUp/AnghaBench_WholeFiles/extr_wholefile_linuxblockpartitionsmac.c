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
typedef  int /*<<< orphan*/  tmp ;
struct parsed_partitions {int access_beyond_eod; int limit; char* name; int /*<<< orphan*/  pp_buf; TYPE_1__* parts; TYPE_2__* bdev; } ;
struct mac_partition {int /*<<< orphan*/  type; int /*<<< orphan*/  block_count; int /*<<< orphan*/  start_block; int /*<<< orphan*/  signature; int /*<<< orphan*/  map_count; } ;
struct mac_driver_desc {int /*<<< orphan*/  block_size; int /*<<< orphan*/  signature; } ;
typedef  scalar_t__ sector_t ;
struct TYPE_4__ {int /*<<< orphan*/  bd_disk; } ;
struct TYPE_3__ {int /*<<< orphan*/  flags; scalar_t__ size; scalar_t__ from; } ;
typedef  int /*<<< orphan*/  Sector ;

/* Variables and functions */
 int /*<<< orphan*/  ADDPART_FLAG_RAID ; 
 int /*<<< orphan*/  BDEVNAME_SIZE ; 
 int DISK_MAX_PARTS ; 
 unsigned int MAC_DRIVER_MAGIC ; 
 unsigned int MAC_PARTITION_MAGIC ; 
 int /*<<< orphan*/  PAGE_SIZE ; 
 unsigned int be16_to_cpu (int /*<<< orphan*/ ) ; 
 unsigned int be32_to_cpu (int /*<<< orphan*/ ) ; 
 scalar_t__ get_capacity (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  put_dev_sector (int /*<<< orphan*/ ) ; 
 void* read_dev_sector (TYPE_2__*,scalar_t__,int /*<<< orphan*/ *) ; 
 unsigned int round_down (unsigned int,int) ; 
 int /*<<< orphan*/  snprintf (char*,int,char*,char*,int) ; 
 int /*<<< orphan*/  strlcat (int /*<<< orphan*/ ,char*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  strncasecmp (int /*<<< orphan*/ ,char*,int) ; 

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

__attribute__((used)) static inline void mac_fix_string(char *stg, int len)
{
	int i;

	for (i = len - 1; i >= 0 && stg[i] == ' '; i--)
		stg[i] = 0;
}

int mac_partition(struct parsed_partitions *state)
{
	Sector sect;
	unsigned char *data;
	int slot, blocks_in_map;
	unsigned secsize, datasize, partoffset;
#ifdef CONFIG_PPC_PMAC
	int found_root = 0;
	int found_root_goodness = 0;
#endif
	struct mac_partition *part;
	struct mac_driver_desc *md;

	/* Get 0th block and look at the first partition map entry. */
	md = read_part_sector(state, 0, &sect);
	if (!md)
		return -1;
	if (be16_to_cpu(md->signature) != MAC_DRIVER_MAGIC) {
		put_dev_sector(sect);
		return 0;
	}
	secsize = be16_to_cpu(md->block_size);
	put_dev_sector(sect);
	datasize = round_down(secsize, 512);
	data = read_part_sector(state, datasize / 512, &sect);
	if (!data)
		return -1;
	partoffset = secsize % 512;
	if (partoffset + sizeof(*part) > datasize)
		return -1;
	part = (struct mac_partition *) (data + partoffset);
	if (be16_to_cpu(part->signature) != MAC_PARTITION_MAGIC) {
		put_dev_sector(sect);
		return 0;		/* not a MacOS disk */
	}
	blocks_in_map = be32_to_cpu(part->map_count);
	if (blocks_in_map < 0 || blocks_in_map >= DISK_MAX_PARTS) {
		put_dev_sector(sect);
		return 0;
	}

	if (blocks_in_map >= state->limit)
		blocks_in_map = state->limit - 1;

	strlcat(state->pp_buf, " [mac]", PAGE_SIZE);
	for (slot = 1; slot <= blocks_in_map; ++slot) {
		int pos = slot * secsize;
		put_dev_sector(sect);
		data = read_part_sector(state, pos/512, &sect);
		if (!data)
			return -1;
		part = (struct mac_partition *) (data + pos%512);
		if (be16_to_cpu(part->signature) != MAC_PARTITION_MAGIC)
			break;
		put_partition(state, slot,
			be32_to_cpu(part->start_block) * (secsize/512),
			be32_to_cpu(part->block_count) * (secsize/512));

		if (!strncasecmp(part->type, "Linux_RAID", 10))
			state->parts[slot].flags = ADDPART_FLAG_RAID;
#ifdef CONFIG_PPC_PMAC
		/*
		 * If this is the first bootable partition, tell the
		 * setup code, in case it wants to make this the root.
		 */
		if (machine_is(powermac)) {
			int goodness = 0;

			mac_fix_string(part->processor, 16);
			mac_fix_string(part->name, 32);
			mac_fix_string(part->type, 32);					
		    
			if ((be32_to_cpu(part->status) & MAC_STATUS_BOOTABLE)
			    && strcasecmp(part->processor, "powerpc") == 0)
				goodness++;

			if (strcasecmp(part->type, "Apple_UNIX_SVR2") == 0
			    || (strncasecmp(part->type, "Linux", 5) == 0
			        && strcasecmp(part->type, "Linux_swap") != 0)) {
				int i, l;

				goodness++;
				l = strlen(part->name);
				if (strcmp(part->name, "/") == 0)
					goodness++;
				for (i = 0; i <= l - 4; ++i) {
					if (strncasecmp(part->name + i, "root",
						     4) == 0) {
						goodness += 2;
						break;
					}
				}
				if (strncasecmp(part->name, "swap", 4) == 0)
					goodness--;
			}

			if (goodness > found_root_goodness) {
				found_root = slot;
				found_root_goodness = goodness;
			}
		}
#endif /* CONFIG_PPC_PMAC */
	}
#ifdef CONFIG_PPC_PMAC
	if (found_root_goodness)
		note_bootable_part(state->bdev->bd_dev, found_root,
				   found_root_goodness);
#endif

	put_dev_sector(sect);
	strlcat(state->pp_buf, "\n", PAGE_SIZE);
	return 1;
}

