#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_9__   TYPE_3__ ;
typedef  struct TYPE_8__   TYPE_2__ ;
typedef  struct TYPE_7__   TYPE_1__ ;

/* Type definitions */
struct switch_path {int dummy; } ;
struct switch_ctx {unsigned int region_size; int region_size_bits; int region_table_entry_bits; int region_entries_per_slot; int region_entries_per_slot_bits; int nr_regions; int* region_table; unsigned int nr_paths; TYPE_2__* path_list; struct dm_target* ti; } ;
struct dm_target {int len; char* error; int num_discard_bios; struct switch_ctx* private; int /*<<< orphan*/  table; } ;
struct dm_arg_set {unsigned int argc; char** argv; } ;
struct dm_arg {int member_0; int member_1; char* member_2; } ;
struct block_device {int /*<<< orphan*/  bd_inode; } ;
struct TYPE_7__ {int bi_sector; } ;
struct bio {TYPE_1__ bi_iter; } ;
typedef  int status_type_t ;
typedef  int sector_t ;
typedef  int region_table_slot_t ;
typedef  int (* iterate_devices_callout_fn ) (struct dm_target*,TYPE_3__*,scalar_t__,scalar_t__,void*) ;
struct TYPE_9__ {unsigned long name; struct block_device* bdev; } ;
struct TYPE_8__ {unsigned long long start; TYPE_3__* dmdev; } ;
typedef  int /*<<< orphan*/  DEFINE_MUTEX ;

/* Variables and functions */
 int /*<<< orphan*/  DMEMIT (char*,unsigned long,unsigned long long) ; 
 int /*<<< orphan*/  DMWARN (char*,...) ; 
 int DM_MAPIO_REMAPPED ; 
 int EINVAL ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
#define  KMALLOC_MAX_SIZE 131 
 unsigned int READ_ONCE (int) ; 
 int SECTOR_SHIFT ; 
#define  STATUSTYPE_INFO 130 
#define  STATUSTYPE_TABLE 129 
#define  UINT_MAX 128 
 int ULONG_MAX ; 
 void* __ffs (int) ; 
 int /*<<< orphan*/  array_size (int,int) ; 
 int /*<<< orphan*/  bio_set_dev (struct bio*,struct block_device*) ; 
 int dm_get_device (struct dm_target*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,TYPE_3__**) ; 
 int /*<<< orphan*/  dm_put_device (struct dm_target*,TYPE_3__*) ; 
 int dm_read_arg (struct dm_arg const*,struct dm_arg_set*,unsigned int*,char**) ; 
 int dm_read_arg_group (struct dm_arg const*,struct dm_arg_set*,unsigned int*,char**) ; 
 int dm_set_target_max_io_len (struct dm_target*,unsigned int) ; 
 int /*<<< orphan*/  dm_shift_arg (struct dm_arg_set*) ; 
 int /*<<< orphan*/  dm_table_get_mode (int /*<<< orphan*/ ) ; 
 int dm_target_offset (struct dm_target*,int) ; 
 scalar_t__ i_size_read (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  kfree (struct switch_ctx*) ; 
 scalar_t__ kstrtoull (int /*<<< orphan*/ ,int,unsigned long long*) ; 
 struct switch_ctx* kzalloc (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 unsigned long parse_hex (char const**) ; 
 scalar_t__ sector_div (int,int) ; 
 int /*<<< orphan*/  strcasecmp (char*,char*) ; 
 scalar_t__ unlikely (char const) ; 
 int /*<<< orphan*/  vfree (int*) ; 
 int* vmalloc (int /*<<< orphan*/ ) ; 

__attribute__((used)) static struct switch_ctx *alloc_switch_ctx(struct dm_target *ti, unsigned nr_paths,
					   unsigned region_size)
{
	struct switch_ctx *sctx;

	sctx = kzalloc(sizeof(struct switch_ctx) + nr_paths * sizeof(struct switch_path),
		       GFP_KERNEL);
	if (!sctx)
		return NULL;

	sctx->ti = ti;
	sctx->region_size = region_size;

	ti->private = sctx;

	return sctx;
}

__attribute__((used)) static int alloc_region_table(struct dm_target *ti, unsigned nr_paths)
{
	struct switch_ctx *sctx = ti->private;
	sector_t nr_regions = ti->len;
	sector_t nr_slots;

	if (!(sctx->region_size & (sctx->region_size - 1)))
		sctx->region_size_bits = __ffs(sctx->region_size);
	else
		sctx->region_size_bits = -1;

	sctx->region_table_entry_bits = 1;
	while (sctx->region_table_entry_bits < sizeof(region_table_slot_t) * 8 &&
	       (region_table_slot_t)1 << sctx->region_table_entry_bits < nr_paths)
		sctx->region_table_entry_bits++;

	sctx->region_entries_per_slot = (sizeof(region_table_slot_t) * 8) / sctx->region_table_entry_bits;
	if (!(sctx->region_entries_per_slot & (sctx->region_entries_per_slot - 1)))
		sctx->region_entries_per_slot_bits = __ffs(sctx->region_entries_per_slot);
	else
		sctx->region_entries_per_slot_bits = -1;

	if (sector_div(nr_regions, sctx->region_size))
		nr_regions++;

	if (nr_regions >= ULONG_MAX) {
		ti->error = "Region table too large";
		return -EINVAL;
	}
	sctx->nr_regions = nr_regions;

	nr_slots = nr_regions;
	if (sector_div(nr_slots, sctx->region_entries_per_slot))
		nr_slots++;

	if (nr_slots > ULONG_MAX / sizeof(region_table_slot_t)) {
		ti->error = "Region table too large";
		return -EINVAL;
	}

	sctx->region_table = vmalloc(array_size(nr_slots,
						sizeof(region_table_slot_t)));
	if (!sctx->region_table) {
		ti->error = "Cannot allocate region table";
		return -ENOMEM;
	}

	return 0;
}

__attribute__((used)) static void switch_get_position(struct switch_ctx *sctx, unsigned long region_nr,
				unsigned long *region_index, unsigned *bit)
{
	if (sctx->region_entries_per_slot_bits >= 0) {
		*region_index = region_nr >> sctx->region_entries_per_slot_bits;
		*bit = region_nr & (sctx->region_entries_per_slot - 1);
	} else {
		*region_index = region_nr / sctx->region_entries_per_slot;
		*bit = region_nr % sctx->region_entries_per_slot;
	}

	*bit *= sctx->region_table_entry_bits;
}

__attribute__((used)) static unsigned switch_region_table_read(struct switch_ctx *sctx, unsigned long region_nr)
{
	unsigned long region_index;
	unsigned bit;

	switch_get_position(sctx, region_nr, &region_index, &bit);

	return (READ_ONCE(sctx->region_table[region_index]) >> bit) &
		((1 << sctx->region_table_entry_bits) - 1);
}

__attribute__((used)) static unsigned switch_get_path_nr(struct switch_ctx *sctx, sector_t offset)
{
	unsigned path_nr;
	sector_t p;

	p = offset;
	if (sctx->region_size_bits >= 0)
		p >>= sctx->region_size_bits;
	else
		sector_div(p, sctx->region_size);

	path_nr = switch_region_table_read(sctx, p);

	/* This can only happen if the processor uses non-atomic stores. */
	if (unlikely(path_nr >= sctx->nr_paths))
		path_nr = 0;

	return path_nr;
}

__attribute__((used)) static void switch_region_table_write(struct switch_ctx *sctx, unsigned long region_nr,
				      unsigned value)
{
	unsigned long region_index;
	unsigned bit;
	region_table_slot_t pte;

	switch_get_position(sctx, region_nr, &region_index, &bit);

	pte = sctx->region_table[region_index];
	pte &= ~((((region_table_slot_t)1 << sctx->region_table_entry_bits) - 1) << bit);
	pte |= (region_table_slot_t)value << bit;
	sctx->region_table[region_index] = pte;
}

__attribute__((used)) static void initialise_region_table(struct switch_ctx *sctx)
{
	unsigned path_nr = 0;
	unsigned long region_nr;

	for (region_nr = 0; region_nr < sctx->nr_regions; region_nr++) {
		switch_region_table_write(sctx, region_nr, path_nr);
		if (++path_nr >= sctx->nr_paths)
			path_nr = 0;
	}
}

__attribute__((used)) static int parse_path(struct dm_arg_set *as, struct dm_target *ti)
{
	struct switch_ctx *sctx = ti->private;
	unsigned long long start;
	int r;

	r = dm_get_device(ti, dm_shift_arg(as), dm_table_get_mode(ti->table),
			  &sctx->path_list[sctx->nr_paths].dmdev);
	if (r) {
		ti->error = "Device lookup failed";
		return r;
	}

	if (kstrtoull(dm_shift_arg(as), 10, &start) || start != (sector_t)start) {
		ti->error = "Invalid device starting offset";
		dm_put_device(ti, sctx->path_list[sctx->nr_paths].dmdev);
		return -EINVAL;
	}

	sctx->path_list[sctx->nr_paths].start = start;

	sctx->nr_paths++;

	return 0;
}

__attribute__((used)) static void switch_dtr(struct dm_target *ti)
{
	struct switch_ctx *sctx = ti->private;

	while (sctx->nr_paths--)
		dm_put_device(ti, sctx->path_list[sctx->nr_paths].dmdev);

	vfree(sctx->region_table);
	kfree(sctx);
}

__attribute__((used)) static int switch_ctr(struct dm_target *ti, unsigned argc, char **argv)
{
	static const struct dm_arg _args[] = {
		{1, (KMALLOC_MAX_SIZE - sizeof(struct switch_ctx)) / sizeof(struct switch_path), "Invalid number of paths"},
		{1, UINT_MAX, "Invalid region size"},
		{0, 0, "Invalid number of optional args"},
	};

	struct switch_ctx *sctx;
	struct dm_arg_set as;
	unsigned nr_paths, region_size, nr_optional_args;
	int r;

	as.argc = argc;
	as.argv = argv;

	r = dm_read_arg(_args, &as, &nr_paths, &ti->error);
	if (r)
		return -EINVAL;

	r = dm_read_arg(_args + 1, &as, &region_size, &ti->error);
	if (r)
		return r;

	r = dm_read_arg_group(_args + 2, &as, &nr_optional_args, &ti->error);
	if (r)
		return r;
	/* parse optional arguments here, if we add any */

	if (as.argc != nr_paths * 2) {
		ti->error = "Incorrect number of path arguments";
		return -EINVAL;
	}

	sctx = alloc_switch_ctx(ti, nr_paths, region_size);
	if (!sctx) {
		ti->error = "Cannot allocate redirection context";
		return -ENOMEM;
	}

	r = dm_set_target_max_io_len(ti, region_size);
	if (r)
		goto error;

	while (as.argc) {
		r = parse_path(&as, ti);
		if (r)
			goto error;
	}

	r = alloc_region_table(ti, nr_paths);
	if (r)
		goto error;

	initialise_region_table(sctx);

	/* For UNMAP, sending the request down any path is sufficient */
	ti->num_discard_bios = 1;

	return 0;

error:
	switch_dtr(ti);

	return r;
}

__attribute__((used)) static int switch_map(struct dm_target *ti, struct bio *bio)
{
	struct switch_ctx *sctx = ti->private;
	sector_t offset = dm_target_offset(ti, bio->bi_iter.bi_sector);
	unsigned path_nr = switch_get_path_nr(sctx, offset);

	bio_set_dev(bio, sctx->path_list[path_nr].dmdev->bdev);
	bio->bi_iter.bi_sector = sctx->path_list[path_nr].start + offset;

	return DM_MAPIO_REMAPPED;
}

__attribute__((used)) static int process_set_region_mappings(struct switch_ctx *sctx,
				       unsigned argc, char **argv)
{
	unsigned i;
	unsigned long region_index = 0;

	for (i = 1; i < argc; i++) {
		unsigned long path_nr;
		const char *string = argv[i];

		if ((*string & 0xdf) == 'R') {
			unsigned long cycle_length, num_write;

			string++;
			if (unlikely(*string == ',')) {
				DMWARN("invalid set_region_mappings argument: '%s'", argv[i]);
				return -EINVAL;
			}
			cycle_length = parse_hex(&string);
			if (unlikely(*string != ',')) {
				DMWARN("invalid set_region_mappings argument: '%s'", argv[i]);
				return -EINVAL;
			}
			string++;
			if (unlikely(!*string)) {
				DMWARN("invalid set_region_mappings argument: '%s'", argv[i]);
				return -EINVAL;
			}
			num_write = parse_hex(&string);
			if (unlikely(*string)) {
				DMWARN("invalid set_region_mappings argument: '%s'", argv[i]);
				return -EINVAL;
			}

			if (unlikely(!cycle_length) || unlikely(cycle_length - 1 > region_index)) {
				DMWARN("invalid set_region_mappings cycle length: %lu > %lu",
				       cycle_length - 1, region_index);
				return -EINVAL;
			}
			if (unlikely(region_index + num_write < region_index) ||
			    unlikely(region_index + num_write >= sctx->nr_regions)) {
				DMWARN("invalid set_region_mappings region number: %lu + %lu >= %lu",
				       region_index, num_write, sctx->nr_regions);
				return -EINVAL;
			}

			while (num_write--) {
				region_index++;
				path_nr = switch_region_table_read(sctx, region_index - cycle_length);
				switch_region_table_write(sctx, region_index, path_nr);
			}

			continue;
		}

		if (*string == ':')
			region_index++;
		else {
			region_index = parse_hex(&string);
			if (unlikely(*string != ':')) {
				DMWARN("invalid set_region_mappings argument: '%s'", argv[i]);
				return -EINVAL;
			}
		}

		string++;
		if (unlikely(!*string)) {
			DMWARN("invalid set_region_mappings argument: '%s'", argv[i]);
			return -EINVAL;
		}

		path_nr = parse_hex(&string);
		if (unlikely(*string)) {
			DMWARN("invalid set_region_mappings argument: '%s'", argv[i]);
			return -EINVAL;
		}
		if (unlikely(region_index >= sctx->nr_regions)) {
			DMWARN("invalid set_region_mappings region number: %lu >= %lu", region_index, sctx->nr_regions);
			return -EINVAL;
		}
		if (unlikely(path_nr >= sctx->nr_paths)) {
			DMWARN("invalid set_region_mappings device: %lu >= %u", path_nr, sctx->nr_paths);
			return -EINVAL;
		}

		switch_region_table_write(sctx, region_index, path_nr);
	}

	return 0;
}

__attribute__((used)) static int switch_message(struct dm_target *ti, unsigned argc, char **argv,
			  char *result, unsigned maxlen)
{
	static DEFINE_MUTEX(message_mutex);

	struct switch_ctx *sctx = ti->private;
	int r = -EINVAL;

	mutex_lock(&message_mutex);

	if (!strcasecmp(argv[0], "set_region_mappings"))
		r = process_set_region_mappings(sctx, argc, argv);
	else
		DMWARN("Unrecognised message received.");

	mutex_unlock(&message_mutex);

	return r;
}

__attribute__((used)) static void switch_status(struct dm_target *ti, status_type_t type,
			  unsigned status_flags, char *result, unsigned maxlen)
{
	struct switch_ctx *sctx = ti->private;
	unsigned sz = 0;
	int path_nr;

	switch (type) {
	case STATUSTYPE_INFO:
		result[0] = '\0';
		break;

	case STATUSTYPE_TABLE:
		DMEMIT("%u %u 0", sctx->nr_paths, sctx->region_size);
		for (path_nr = 0; path_nr < sctx->nr_paths; path_nr++)
			DMEMIT(" %s %llu", sctx->path_list[path_nr].dmdev->name,
			       (unsigned long long)sctx->path_list[path_nr].start);
		break;
	}
}

__attribute__((used)) static int switch_prepare_ioctl(struct dm_target *ti, struct block_device **bdev)
{
	struct switch_ctx *sctx = ti->private;
	unsigned path_nr;

	path_nr = switch_get_path_nr(sctx, 0);

	*bdev = sctx->path_list[path_nr].dmdev->bdev;

	/*
	 * Only pass ioctls through if the device sizes match exactly.
	 */
	if (ti->len + sctx->path_list[path_nr].start !=
	    i_size_read((*bdev)->bd_inode) >> SECTOR_SHIFT)
		return 1;
	return 0;
}

__attribute__((used)) static int switch_iterate_devices(struct dm_target *ti,
				  iterate_devices_callout_fn fn, void *data)
{
	struct switch_ctx *sctx = ti->private;
	int path_nr;
	int r;

	for (path_nr = 0; path_nr < sctx->nr_paths; path_nr++) {
		r = fn(ti, sctx->path_list[path_nr].dmdev,
			 sctx->path_list[path_nr].start, ti->len, data);
		if (r)
			return r;
	}

	return 0;
}

