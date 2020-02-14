#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_8__   TYPE_4__ ;
typedef  struct TYPE_7__   TYPE_3__ ;
typedef  struct TYPE_6__   TYPE_2__ ;
typedef  struct TYPE_5__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  tmp ;
struct slice {int /*<<< orphan*/  nblocks; int /*<<< orphan*/  blkoff; } ;
struct parsed_partitions {int access_beyond_eod; int limit; char* name; int /*<<< orphan*/  pp_buf; TYPE_1__* parts; TYPE_4__* bdev; } ;
struct TYPE_7__ {int /*<<< orphan*/  ios_slcblk; int /*<<< orphan*/  ios_slccnt; } ;
struct TYPE_6__ {int /*<<< orphan*/  vid_mac; } ;
struct dkblk0 {TYPE_3__ dk_ios; TYPE_2__ dk_vid; } ;
typedef  scalar_t__ sector_t ;
struct TYPE_8__ {int /*<<< orphan*/  bd_disk; } ;
struct TYPE_5__ {scalar_t__ size; scalar_t__ from; } ;
typedef  int /*<<< orphan*/  Sector ;

/* Variables and functions */
 int /*<<< orphan*/  BDEVNAME_SIZE ; 
 int /*<<< orphan*/  PAGE_SIZE ; 
 int be16_to_cpu (int /*<<< orphan*/ ) ; 
 int be32_to_cpu (int /*<<< orphan*/ ) ; 
 scalar_t__ get_capacity (int /*<<< orphan*/ ) ; 
 scalar_t__ memcmp (int /*<<< orphan*/ ,char*,int) ; 
 int /*<<< orphan*/  put_dev_sector (int /*<<< orphan*/ ) ; 
 void* read_dev_sector (TYPE_4__*,scalar_t__,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  snprintf (char*,int,char*,...) ; 
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

int sysv68_partition(struct parsed_partitions *state)
{
	int i, slices;
	int slot = 1;
	Sector sect;
	unsigned char *data;
	struct dkblk0 *b;
	struct slice *slice;
	char tmp[64];

	data = read_part_sector(state, 0, &sect);
	if (!data)
		return -1;

	b = (struct dkblk0 *)data;
	if (memcmp(b->dk_vid.vid_mac, "MOTOROLA", sizeof(b->dk_vid.vid_mac))) {
		put_dev_sector(sect);
		return 0;
	}
	slices = be16_to_cpu(b->dk_ios.ios_slccnt);
	i = be32_to_cpu(b->dk_ios.ios_slcblk);
	put_dev_sector(sect);

	data = read_part_sector(state, i, &sect);
	if (!data)
		return -1;

	slices -= 1; /* last slice is the whole disk */
	snprintf(tmp, sizeof(tmp), "sysV68: %s(s%u)", state->name, slices);
	strlcat(state->pp_buf, tmp, PAGE_SIZE);
	slice = (struct slice *)data;
	for (i = 0; i < slices; i++, slice++) {
		if (slot == state->limit)
			break;
		if (be32_to_cpu(slice->nblocks)) {
			put_partition(state, slot,
				be32_to_cpu(slice->blkoff),
				be32_to_cpu(slice->nblocks));
			snprintf(tmp, sizeof(tmp), "(s%u)", i);
			strlcat(state->pp_buf, tmp, PAGE_SIZE);
		}
		slot++;
	}
	strlcat(state->pp_buf, "\n", PAGE_SIZE);
	put_dev_sector(sect);
	return 1;
}

