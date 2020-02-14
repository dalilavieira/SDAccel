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
struct TYPE_4__ {int /*<<< orphan*/  config_size; } ;
struct TYPE_3__ {int end; scalar_t__ start; int /*<<< orphan*/  name; } ;
struct nvdimm_drvdata {int ns_current; int ns_next; TYPE_2__ nsarea; int /*<<< orphan*/  kref; struct device* dev; TYPE_1__ dpa; } ;
struct nd_region {int dummy; } ;
struct nd_pfn {int dummy; } ;
struct nd_namespace_io {int dummy; } ;
struct nd_namespace_common {int dummy; } ;
struct gendisk {int /*<<< orphan*/  part0; int /*<<< orphan*/  queue; } ;
struct device {int dummy; } ;
struct dev_pagemap {int dummy; } ;
struct bio {struct gendisk* bi_disk; } ;
struct badblocks {scalar_t__ count; } ;
typedef  int /*<<< orphan*/  sector_t ;

/* Variables and functions */
 int EACCES ; 
 int ENODEV ; 
 int ENOMEM ; 
 int ENOTTY ; 
 int ENXIO ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int /*<<< orphan*/  badblocks_check (struct badblocks*,int /*<<< orphan*/ ,unsigned int,int /*<<< orphan*/ *,int*) ; 
 int /*<<< orphan*/  bio_op (struct bio*) ; 
 int /*<<< orphan*/  bio_sectors (struct bio*) ; 
 int /*<<< orphan*/  blk_queue_io_stat (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  dev_dbg (struct device*,char*,int /*<<< orphan*/ ) ; 
 struct nvdimm_drvdata* dev_get_drvdata (struct device*) ; 
 int /*<<< orphan*/  dev_name (struct device*) ; 
 int /*<<< orphan*/  dev_set_drvdata (struct device*,struct nvdimm_drvdata*) ; 
 int /*<<< orphan*/  generic_end_io_acct (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  generic_start_io_acct (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  get_device (struct device*) ; 
 unsigned long jiffies ; 
 int /*<<< orphan*/  kref_init (int /*<<< orphan*/ *) ; 
 struct nvdimm_drvdata* kzalloc (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  nd_label_copy (struct nvdimm_drvdata*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int nd_label_reserve_dpa (struct nvdimm_drvdata*) ; 
 int nd_label_validate (struct nvdimm_drvdata*) ; 
 int /*<<< orphan*/  nvdimm_bus_lock (struct device*) ; 
 int /*<<< orphan*/  nvdimm_bus_unlock (struct device*) ; 
 int nvdimm_check_config_data (struct device*) ; 
 int /*<<< orphan*/  nvdimm_clear_locked (struct device*) ; 
 int nvdimm_init_config_data (struct nvdimm_drvdata*) ; 
 int nvdimm_init_nsarea (struct nvdimm_drvdata*) ; 
 int /*<<< orphan*/  nvdimm_set_aliasing (struct device*) ; 
 int /*<<< orphan*/  nvdimm_set_locked (struct device*) ; 
 int /*<<< orphan*/  put_ndd (struct nvdimm_drvdata*) ; 
 int /*<<< orphan*/  to_current_namespace_index (struct nvdimm_drvdata*) ; 
 int /*<<< orphan*/  to_next_namespace_index (struct nvdimm_drvdata*) ; 

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

__attribute__((used)) static int nvdimm_probe(struct device *dev)
{
	struct nvdimm_drvdata *ndd;
	int rc;

	rc = nvdimm_check_config_data(dev);
	if (rc) {
		/* not required for non-aliased nvdimm, ex. NVDIMM-N */
		if (rc == -ENOTTY)
			rc = 0;
		return rc;
	}

	/* reset locked, to be validated below... */
	nvdimm_clear_locked(dev);

	ndd = kzalloc(sizeof(*ndd), GFP_KERNEL);
	if (!ndd)
		return -ENOMEM;

	dev_set_drvdata(dev, ndd);
	ndd->dpa.name = dev_name(dev);
	ndd->ns_current = -1;
	ndd->ns_next = -1;
	ndd->dpa.start = 0;
	ndd->dpa.end = -1;
	ndd->dev = dev;
	get_device(dev);
	kref_init(&ndd->kref);

	/*
	 * EACCES failures reading the namespace label-area-properties
	 * are interpreted as the DIMM capacity being locked but the
	 * namespace labels themselves being accessible.
	 */
	rc = nvdimm_init_nsarea(ndd);
	if (rc == -EACCES) {
		/*
		 * See nvdimm_namespace_common_probe() where we fail to
		 * allow namespaces to probe while the DIMM is locked,
		 * but we do allow for namespace enumeration.
		 */
		nvdimm_set_locked(dev);
		rc = 0;
	}
	if (rc)
		goto err;

	/*
	 * EACCES failures reading the namespace label-data are
	 * interpreted as the label area being locked in addition to the
	 * DIMM capacity. We fail the dimm probe to prevent regions from
	 * attempting to parse the label area.
	 */
	rc = nvdimm_init_config_data(ndd);
	if (rc == -EACCES)
		nvdimm_set_locked(dev);
	if (rc)
		goto err;

	dev_dbg(dev, "config data size: %d\n", ndd->nsarea.config_size);

	nvdimm_bus_lock(dev);
	ndd->ns_current = nd_label_validate(ndd);
	ndd->ns_next = nd_label_next_nsindex(ndd->ns_current);
	nd_label_copy(ndd, to_next_namespace_index(ndd),
			to_current_namespace_index(ndd));
	if (ndd->ns_current >= 0) {
		rc = nd_label_reserve_dpa(ndd);
		if (rc == 0)
			nvdimm_set_aliasing(dev);
	}
	nvdimm_bus_unlock(dev);

	if (rc)
		goto err;

	return 0;

 err:
	put_ndd(ndd);
	return rc;
}

__attribute__((used)) static int nvdimm_remove(struct device *dev)
{
	struct nvdimm_drvdata *ndd = dev_get_drvdata(dev);

	if (!ndd)
		return 0;

	nvdimm_bus_lock(dev);
	dev_set_drvdata(dev, NULL);
	nvdimm_bus_unlock(dev);
	put_ndd(ndd);

	return 0;
}

