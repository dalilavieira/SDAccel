#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_7__   TYPE_2__ ;
typedef  struct TYPE_6__   TYPE_1__ ;

/* Type definitions */
struct unstripe_c {int stripes; int chunk_size; int unstripe; unsigned long long physical_start; int unstripe_offset; int unstripe_width; int chunk_shift; TYPE_2__* dev; } ;
struct queue_limits {int chunk_sectors; } ;
struct dm_target {char* error; unsigned long long len; struct unstripe_c* private; int /*<<< orphan*/  table; } ;
struct dm_stats {int /*<<< orphan*/  list; } ;
struct TYPE_6__ {unsigned long long bi_sector; } ;
struct bio {TYPE_1__ bi_iter; } ;
typedef  int status_type_t ;
typedef  unsigned long long sector_t ;
typedef  int (* iterate_devices_callout_fn ) (struct dm_target*,TYPE_2__*,unsigned long long,unsigned long long,void*) ;
struct TYPE_7__ {int /*<<< orphan*/  name; int /*<<< orphan*/  bdev; } ;

/* Variables and functions */
 int /*<<< orphan*/  DMEMIT (char*,int,unsigned long long,int,int /*<<< orphan*/ ,unsigned long long) ; 
 int DM_MAPIO_REMAPPED ; 
 int EINVAL ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
#define  STATUSTYPE_INFO 129 
#define  STATUSTYPE_TABLE 128 
 int /*<<< orphan*/  bio_set_dev (struct bio*,int /*<<< orphan*/ ) ; 
 scalar_t__ dm_get_device (struct dm_target*,char*,int /*<<< orphan*/ ,TYPE_2__**) ; 
 int /*<<< orphan*/  dm_put_device (struct dm_target*,TYPE_2__*) ; 
 scalar_t__ dm_set_target_max_io_len (struct dm_target*,int) ; 
 int /*<<< orphan*/  dm_table_get_mode (int /*<<< orphan*/ ) ; 
 int fls (int) ; 
 scalar_t__ is_power_of_2 (int) ; 
 int /*<<< orphan*/  kfree (struct unstripe_c*) ; 
 scalar_t__ kstrtouint (char*,int,int*) ; 
 struct unstripe_c* kzalloc (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  list_empty (int /*<<< orphan*/ *) ; 
 scalar_t__ sector_div (unsigned long long,int) ; 
 int sscanf (char*,char*,unsigned long long*,char*) ; 

__attribute__((used)) static inline bool dm_stats_used(struct dm_stats *st)
{
	return !list_empty(&st->list);
}

__attribute__((used)) static void cleanup_unstripe(struct unstripe_c *uc, struct dm_target *ti)
{
	if (uc->dev)
		dm_put_device(ti, uc->dev);
	kfree(uc);
}

__attribute__((used)) static int unstripe_ctr(struct dm_target *ti, unsigned int argc, char **argv)
{
	struct unstripe_c *uc;
	sector_t tmp_len;
	unsigned long long start;
	char dummy;

	if (argc != 5) {
		ti->error = "Invalid number of arguments";
		return -EINVAL;
	}

	uc = kzalloc(sizeof(*uc), GFP_KERNEL);
	if (!uc) {
		ti->error = "Memory allocation for unstriped context failed";
		return -ENOMEM;
	}

	if (kstrtouint(argv[0], 10, &uc->stripes) || !uc->stripes) {
		ti->error = "Invalid stripe count";
		goto err;
	}

	if (kstrtouint(argv[1], 10, &uc->chunk_size) || !uc->chunk_size) {
		ti->error = "Invalid chunk_size";
		goto err;
	}

	if (kstrtouint(argv[2], 10, &uc->unstripe)) {
		ti->error = "Invalid stripe number";
		goto err;
	}

	if (uc->unstripe > uc->stripes && uc->stripes > 1) {
		ti->error = "Please provide stripe between [0, # of stripes]";
		goto err;
	}

	if (dm_get_device(ti, argv[3], dm_table_get_mode(ti->table), &uc->dev)) {
		ti->error = "Couldn't get striped device";
		goto err;
	}

	if (sscanf(argv[4], "%llu%c", &start, &dummy) != 1 || start != (sector_t)start) {
		ti->error = "Invalid striped device offset";
		goto err;
	}
	uc->physical_start = start;

	uc->unstripe_offset = uc->unstripe * uc->chunk_size;
	uc->unstripe_width = (uc->stripes - 1) * uc->chunk_size;
	uc->chunk_shift = is_power_of_2(uc->chunk_size) ? fls(uc->chunk_size) - 1 : 0;

	tmp_len = ti->len;
	if (sector_div(tmp_len, uc->chunk_size)) {
		ti->error = "Target length not divisible by chunk size";
		goto err;
	}

	if (dm_set_target_max_io_len(ti, uc->chunk_size)) {
		ti->error = "Failed to set max io len";
		goto err;
	}

	ti->private = uc;
	return 0;
err:
	cleanup_unstripe(uc, ti);
	return -EINVAL;
}

__attribute__((used)) static void unstripe_dtr(struct dm_target *ti)
{
	struct unstripe_c *uc = ti->private;

	cleanup_unstripe(uc, ti);
}

__attribute__((used)) static sector_t map_to_core(struct dm_target *ti, struct bio *bio)
{
	struct unstripe_c *uc = ti->private;
	sector_t sector = bio->bi_iter.bi_sector;
	sector_t tmp_sector = sector;

	/* Shift us up to the right "row" on the stripe */
	if (uc->chunk_shift)
		tmp_sector >>= uc->chunk_shift;
	else
		sector_div(tmp_sector, uc->chunk_size);

	sector += uc->unstripe_width * tmp_sector;

	/* Account for what stripe we're operating on */
	return sector + uc->unstripe_offset;
}

__attribute__((used)) static int unstripe_map(struct dm_target *ti, struct bio *bio)
{
	struct unstripe_c *uc = ti->private;

	bio_set_dev(bio, uc->dev->bdev);
	bio->bi_iter.bi_sector = map_to_core(ti, bio) + uc->physical_start;

	return DM_MAPIO_REMAPPED;
}

__attribute__((used)) static void unstripe_status(struct dm_target *ti, status_type_t type,
			    unsigned int status_flags, char *result, unsigned int maxlen)
{
	struct unstripe_c *uc = ti->private;
	unsigned int sz = 0;

	switch (type) {
	case STATUSTYPE_INFO:
		break;

	case STATUSTYPE_TABLE:
		DMEMIT("%d %llu %d %s %llu",
		       uc->stripes, (unsigned long long)uc->chunk_size, uc->unstripe,
		       uc->dev->name, (unsigned long long)uc->physical_start);
		break;
	}
}

__attribute__((used)) static int unstripe_iterate_devices(struct dm_target *ti,
				    iterate_devices_callout_fn fn, void *data)
{
	struct unstripe_c *uc = ti->private;

	return fn(ti, uc->dev, uc->physical_start, ti->len, data);
}

__attribute__((used)) static void unstripe_io_hints(struct dm_target *ti,
			       struct queue_limits *limits)
{
	struct unstripe_c *uc = ti->private;

	limits->chunk_sectors = uc->chunk_size;
}

