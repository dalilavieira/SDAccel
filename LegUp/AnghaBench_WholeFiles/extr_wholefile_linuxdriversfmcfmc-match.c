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
struct fru_common_header {int format; } ;
struct fru_board_info_area {int dummy; } ;
struct fmc_fru_id {scalar_t__ product_name; scalar_t__ manufacturer; } ;
struct TYPE_3__ {int fru_id_nr; struct fmc_fru_id* fru_id; } ;
struct fmc_driver {TYPE_1__ id_table; } ;
struct TYPE_4__ {int /*<<< orphan*/ * product_name; int /*<<< orphan*/ * manufacturer; } ;
struct fmc_device {size_t eeprom_len; TYPE_2__ id; int /*<<< orphan*/ * mezzanine_name; int /*<<< orphan*/ * eeprom; int /*<<< orphan*/  slot_id; int /*<<< orphan*/  hwdev; int /*<<< orphan*/  dev; } ;
struct device_driver {int dummy; } ;
struct device {int dummy; } ;

/* Variables and functions */
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int /*<<< orphan*/  dev_info (int /*<<< orphan*/ ,char*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  dev_warn (int /*<<< orphan*/ *,char*) ; 
 int fmc_read_ee (struct fmc_device*,int /*<<< orphan*/ ,int /*<<< orphan*/ *,size_t) ; 
 int /*<<< orphan*/  fru_bia_cksum_ok (struct fru_board_info_area*) ; 
 struct fru_board_info_area* fru_get_board_area (struct fru_common_header*) ; 
 int /*<<< orphan*/ * fru_get_board_manufacturer (struct fru_common_header*) ; 
 int /*<<< orphan*/ * fru_get_product_name (struct fru_common_header*) ; 
 int /*<<< orphan*/  fru_header_cksum_ok (struct fru_common_header*) ; 
 int /*<<< orphan*/  kfree (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/ * kstrdup (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 void* kzalloc (size_t,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  pr_info (char*,...) ; 
 scalar_t__ strcmp (scalar_t__,int /*<<< orphan*/ *) ; 
 struct fmc_device* to_fmc_device (struct device*) ; 
 struct fmc_driver* to_fmc_driver (struct device_driver*) ; 

void *fru_alloc(size_t size)
{
	return kzalloc(size, GFP_KERNEL);
}

int fmc_match(struct device *dev, struct device_driver *drv)
{
	struct fmc_driver *fdrv = to_fmc_driver(drv);
	struct fmc_device *fdev = to_fmc_device(dev);
	struct fmc_fru_id *fid;
	int i, matched = 0;

	/* This currently only matches the EEPROM (FRU id) */
	fid = fdrv->id_table.fru_id;
	if (!fid) {
		dev_warn(&fdev->dev, "Driver has no ID: matches all\n");
		matched = 1;
	} else {
		if (!fdev->id.manufacturer || !fdev->id.product_name)
			return 0; /* the device has no FRU information */
		for (i = 0; i < fdrv->id_table.fru_id_nr; i++, fid++) {
			if (fid->manufacturer &&
			    strcmp(fid->manufacturer, fdev->id.manufacturer))
				continue;
			if (fid->product_name &&
			    strcmp(fid->product_name, fdev->id.product_name))
				continue;
			matched = 1;
			break;
		}
	}

	/* FIXME: match SDB contents */
	return matched;
}

int fmc_fill_id_info(struct fmc_device *fmc)
{
	struct fru_common_header *h;
	struct fru_board_info_area *bia;
	int ret, allocated = 0;

	/* If we know the eeprom length, try to read it off the device */
	if (fmc->eeprom_len && !fmc->eeprom) {
		fmc->eeprom = kzalloc(fmc->eeprom_len, GFP_KERNEL);
		if (!fmc->eeprom)
			return -ENOMEM;
		allocated = 1;
		ret = fmc_read_ee(fmc, 0, fmc->eeprom, fmc->eeprom_len);
		if (ret < 0)
			goto out;
	}

	/* If no eeprom, continue with other matches */
	if (!fmc->eeprom)
		return 0;

	dev_info(fmc->hwdev, "mezzanine %i\n", fmc->slot_id); /* header */

	/* So we have the eeprom: parse the FRU part (if any) */
	h = (void *)fmc->eeprom;
	if (h->format != 1) {
		pr_info("      EEPROM has no FRU information\n");
		goto out;
	}
	if (!fru_header_cksum_ok(h)) {
		pr_info("      FRU: wrong header checksum\n");
		goto out;
	}
	bia = fru_get_board_area(h);
	if (!fru_bia_cksum_ok(bia)) {
		pr_info("      FRU: wrong board area checksum\n");
		goto out;
	}
	fmc->id.manufacturer = fru_get_board_manufacturer(h);
	fmc->id.product_name = fru_get_product_name(h);
	pr_info("      Manufacturer: %s\n", fmc->id.manufacturer);
	pr_info("      Product name: %s\n", fmc->id.product_name);

	/* Create the short name (FIXME: look in sdb as well) */
	fmc->mezzanine_name = kstrdup(fmc->id.product_name, GFP_KERNEL);

out:
	if (allocated) {
		kfree(fmc->eeprom);
		fmc->eeprom = NULL;
	}
	return 0; /* no error: let other identification work */
}

void fmc_free_id_info(struct fmc_device *fmc)
{
	kfree(fmc->mezzanine_name);
	kfree(fmc->id.manufacturer);
	kfree(fmc->id.product_name);
}

