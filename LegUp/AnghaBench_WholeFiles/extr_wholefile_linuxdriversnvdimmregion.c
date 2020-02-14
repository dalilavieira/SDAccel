#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
struct resource {scalar_t__ end; scalar_t__ start; } ;
struct nd_region_data {int ns_active; int ns_count; } ;
struct TYPE_2__ {int /*<<< orphan*/  sd; } ;
struct device {TYPE_1__ kobj; } ;
struct nd_region {scalar_t__ num_lanes; int /*<<< orphan*/ * bb_state; int /*<<< orphan*/  bb; scalar_t__ ndr_size; scalar_t__ ndr_start; struct device dev; struct device* dax_seed; struct device* pfn_seed; struct device* btt_seed; int /*<<< orphan*/ * ns_seed; } ;
struct nd_pfn {int dummy; } ;
struct nd_namespace_io {int dummy; } ;
struct nd_namespace_common {int dummy; } ;
struct gendisk {int /*<<< orphan*/  part0; int /*<<< orphan*/  queue; } ;
struct dev_pagemap {int dummy; } ;
struct bio {struct gendisk* bi_disk; } ;
struct badblocks {scalar_t__ count; } ;
typedef  int /*<<< orphan*/  sector_t ;
typedef  enum nvdimm_event { ____Placeholder_nvdimm_event } nvdimm_event ;

/* Variables and functions */
 int ENODEV ; 
 int ENXIO ; 
 int /*<<< orphan*/  ND_SYNC ; 
 int NVDIMM_REVALIDATE_POISON ; 
 int /*<<< orphan*/  badblocks_check (struct badblocks*,int /*<<< orphan*/ ,unsigned int,int /*<<< orphan*/ *,int*) ; 
 int /*<<< orphan*/  bio_op (struct bio*) ; 
 int /*<<< orphan*/  bio_sectors (struct bio*) ; 
 int /*<<< orphan*/  blk_queue_io_stat (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  dev_dbg (struct device*,char*,scalar_t__,...) ; 
 int /*<<< orphan*/  dev_err (struct device*,char*,int,char*) ; 
 struct nd_region_data* dev_get_drvdata (struct device*) ; 
 int /*<<< orphan*/  dev_set_drvdata (struct device*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  dev_warn (struct device*,char*) ; 
 int /*<<< orphan*/  device_for_each_child (struct device*,int*,int (*) (struct device*,void*)) ; 
 scalar_t__ devm_init_badblocks (struct device*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  generic_end_io_acct (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  generic_start_io_acct (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 scalar_t__ is_nd_blk (struct device*) ; 
 scalar_t__ is_nd_pmem (struct device*) ; 
 scalar_t__ is_nd_volatile (struct device*) ; 
 unsigned long jiffies ; 
 int nd_blk_region_init (struct nd_region*) ; 
 int /*<<< orphan*/  nd_device_notify (struct device*,int) ; 
 int /*<<< orphan*/  nd_device_unregister (struct device*,int /*<<< orphan*/ ) ; 
 int nd_region_activate (struct nd_region*) ; 
 int nd_region_register_namespaces (struct nd_region*,int*) ; 
 scalar_t__ num_online_cpus () ; 
 scalar_t__ num_possible_cpus () ; 
 int /*<<< orphan*/  nvdimm_badblocks_populate (struct nd_region*,int /*<<< orphan*/ *,struct resource*) ; 
 int /*<<< orphan*/  nvdimm_bus_lock (struct device*) ; 
 int /*<<< orphan*/  nvdimm_bus_unlock (struct device*) ; 
 int /*<<< orphan*/ * sysfs_get_dirent (int /*<<< orphan*/ ,char*) ; 
 int /*<<< orphan*/  sysfs_notify_dirent (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  sysfs_put (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  test_and_set_bit (int /*<<< orphan*/ ,unsigned long*) ; 
 struct nd_region* to_nd_region (struct device*) ; 

__attribute__((used)) static inline bool is_nd_region(struct device *dev)
{
	return is_nd_pmem(dev) || is_nd_blk(dev) || is_nd_volatile(dev);
}

__attribute__((used)) static inline bool is_memory(struct device *dev)
{
	return is_nd_pmem(dev) || is_nd_volatile(dev);
}

__attribute__((used)) static inline int nd_label_next_nsindex(int index)
{
	if (index < 0)
		return -1;

	return (index + 1) % 2;
}

__attribute__((used)) static inline unsigned nd_inc_seq(unsigned seq)
{
	static const unsigned next[] = { 0, 2, 3, 1 };

	return next[seq & 3];
}

__attribute__((used)) static inline int nd_btt_probe(struct device *dev,
		struct nd_namespace_common *ndns)
{
	return -ENODEV;
}

__attribute__((used)) static inline bool is_nd_btt(struct device *dev)
{
	return false;
}

__attribute__((used)) static inline struct device *nd_btt_create(struct nd_region *nd_region)
{
	return NULL;
}

__attribute__((used)) static inline int nd_pfn_probe(struct device *dev,
		struct nd_namespace_common *ndns)
{
	return -ENODEV;
}

__attribute__((used)) static inline bool is_nd_pfn(struct device *dev)
{
	return false;
}

__attribute__((used)) static inline struct device *nd_pfn_create(struct nd_region *nd_region)
{
	return NULL;
}

__attribute__((used)) static inline int nd_pfn_validate(struct nd_pfn *nd_pfn, const char *sig)
{
	return -ENODEV;
}

__attribute__((used)) static inline int nd_dax_probe(struct device *dev,
		struct nd_namespace_common *ndns)
{
	return -ENODEV;
}

__attribute__((used)) static inline bool is_nd_dax(struct device *dev)
{
	return false;
}

__attribute__((used)) static inline struct device *nd_dax_create(struct nd_region *nd_region)
{
	return NULL;
}

__attribute__((used)) static inline int nvdimm_setup_pfn(struct nd_pfn *nd_pfn,
				   struct dev_pagemap *pgmap)
{
	return -ENXIO;
}

__attribute__((used)) static inline int devm_nsio_enable(struct device *dev,
		struct nd_namespace_io *nsio)
{
	return -ENXIO;
}

__attribute__((used)) static inline void devm_nsio_disable(struct device *dev,
		struct nd_namespace_io *nsio)
{
}

__attribute__((used)) static inline bool nd_iostat_start(struct bio *bio, unsigned long *start)
{
	struct gendisk *disk = bio->bi_disk;

	if (!blk_queue_io_stat(disk->queue))
		return false;

	*start = jiffies;
	generic_start_io_acct(disk->queue, bio_op(bio), bio_sectors(bio),
			      &disk->part0);
	return true;
}

__attribute__((used)) static inline void nd_iostat_end(struct bio *bio, unsigned long start)
{
	struct gendisk *disk = bio->bi_disk;

	generic_end_io_acct(disk->queue, bio_op(bio), &disk->part0, start);
}

__attribute__((used)) static inline bool is_bad_pmem(struct badblocks *bb, sector_t sector,
		unsigned int len)
{
	if (bb->count) {
		sector_t first_bad;
		int num_bad;

		return !!badblocks_check(bb, sector, len / 512, &first_bad,
				&num_bad);
	}

	return false;
}

__attribute__((used)) static int nd_region_probe(struct device *dev)
{
	int err, rc;
	static unsigned long once;
	struct nd_region_data *ndrd;
	struct nd_region *nd_region = to_nd_region(dev);

	if (nd_region->num_lanes > num_online_cpus()
			&& nd_region->num_lanes < num_possible_cpus()
			&& !test_and_set_bit(0, &once)) {
		dev_dbg(dev, "online cpus (%d) < concurrent i/o lanes (%d) < possible cpus (%d)\n",
				num_online_cpus(), nd_region->num_lanes,
				num_possible_cpus());
		dev_dbg(dev, "setting nr_cpus=%d may yield better libnvdimm device performance\n",
				nd_region->num_lanes);
	}

	rc = nd_region_activate(nd_region);
	if (rc)
		return rc;

	rc = nd_blk_region_init(nd_region);
	if (rc)
		return rc;

	rc = nd_region_register_namespaces(nd_region, &err);
	if (rc < 0)
		return rc;

	ndrd = dev_get_drvdata(dev);
	ndrd->ns_active = rc;
	ndrd->ns_count = rc + err;

	if (rc && err && rc == err)
		return -ENODEV;

	if (is_nd_pmem(&nd_region->dev)) {
		struct resource ndr_res;

		if (devm_init_badblocks(dev, &nd_region->bb))
			return -ENODEV;
		nd_region->bb_state = sysfs_get_dirent(nd_region->dev.kobj.sd,
						       "badblocks");
		if (!nd_region->bb_state)
			dev_warn(&nd_region->dev,
					"'badblocks' notification disabled\n");
		ndr_res.start = nd_region->ndr_start;
		ndr_res.end = nd_region->ndr_start + nd_region->ndr_size - 1;
		nvdimm_badblocks_populate(nd_region, &nd_region->bb, &ndr_res);
	}

	nd_region->btt_seed = nd_btt_create(nd_region);
	nd_region->pfn_seed = nd_pfn_create(nd_region);
	nd_region->dax_seed = nd_dax_create(nd_region);
	if (err == 0)
		return 0;

	/*
	 * Given multiple namespaces per region, we do not want to
	 * disable all the successfully registered peer namespaces upon
	 * a single registration failure.  If userspace is missing a
	 * namespace that it expects it can disable/re-enable the region
	 * to retry discovery after correcting the failure.
	 * <regionX>/namespaces returns the current
	 * "<async-registered>/<total>" namespace count.
	 */
	dev_err(dev, "failed to register %d namespace%s, continuing...\n",
			err, err == 1 ? "" : "s");
	return 0;
}

__attribute__((used)) static int child_unregister(struct device *dev, void *data)
{
	nd_device_unregister(dev, ND_SYNC);
	return 0;
}

__attribute__((used)) static int nd_region_remove(struct device *dev)
{
	struct nd_region *nd_region = to_nd_region(dev);

	device_for_each_child(dev, NULL, child_unregister);

	/* flush attribute readers and disable */
	nvdimm_bus_lock(dev);
	nd_region->ns_seed = NULL;
	nd_region->btt_seed = NULL;
	nd_region->pfn_seed = NULL;
	nd_region->dax_seed = NULL;
	dev_set_drvdata(dev, NULL);
	nvdimm_bus_unlock(dev);

	/*
	 * Note, this assumes device_lock() context to not race
	 * nd_region_notify()
	 */
	sysfs_put(nd_region->bb_state);
	nd_region->bb_state = NULL;

	return 0;
}

__attribute__((used)) static int child_notify(struct device *dev, void *data)
{
	nd_device_notify(dev, *(enum nvdimm_event *) data);
	return 0;
}

__attribute__((used)) static void nd_region_notify(struct device *dev, enum nvdimm_event event)
{
	if (event == NVDIMM_REVALIDATE_POISON) {
		struct nd_region *nd_region = to_nd_region(dev);
		struct resource res;

		if (is_nd_pmem(&nd_region->dev)) {
			res.start = nd_region->ndr_start;
			res.end = nd_region->ndr_start +
				nd_region->ndr_size - 1;
			nvdimm_badblocks_populate(nd_region,
					&nd_region->bb, &res);
			if (nd_region->bb_state)
				sysfs_notify_dirent(nd_region->bb_state);
		}
	}
	device_for_each_child(dev, &event, child_notify);
}

