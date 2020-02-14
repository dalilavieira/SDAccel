#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */

/* Type definitions */
struct kobj_uevent_env {int dummy; } ;
struct hdac_driver {scalar_t__ type; int (* match ) (struct hdac_device*,struct hdac_driver*) ;struct hda_device_id* id_table; } ;
struct hdac_device {scalar_t__ vendor_id; scalar_t__ revision_id; scalar_t__ type; } ;
struct hda_device_id {scalar_t__ vendor_id; scalar_t__ rev_id; } ;
struct device_driver {int dummy; } ;
struct device {int dummy; } ;
typedef  int /*<<< orphan*/  modalias ;

/* Variables and functions */
 int ENOMEM ; 
 scalar_t__ add_uevent_var (struct kobj_uevent_env*,char*,char*) ; 
 struct hdac_device* dev_to_hdac_dev (struct device*) ; 
 struct hdac_driver* drv_to_hdac_driver (struct device_driver*) ; 
 int /*<<< orphan*/  snd_hdac_codec_modalias (struct hdac_device*,char*,int) ; 
 int stub1 (struct hdac_device*,struct hdac_driver*) ; 

const struct hda_device_id *
hdac_get_device_id(struct hdac_device *hdev, struct hdac_driver *drv)
{
	if (drv->id_table) {
		const struct hda_device_id *id  = drv->id_table;

		while (id->vendor_id) {
			if (hdev->vendor_id == id->vendor_id &&
				(!id->rev_id || id->rev_id == hdev->revision_id))
				return id;
			id++;
		}
	}

	return NULL;
}

__attribute__((used)) static int hdac_codec_match(struct hdac_device *dev, struct hdac_driver *drv)
{
	if (hdac_get_device_id(dev, drv))
		return 1;
	else
		return 0;
}

__attribute__((used)) static int hda_bus_match(struct device *dev, struct device_driver *drv)
{
	struct hdac_device *hdev = dev_to_hdac_dev(dev);
	struct hdac_driver *hdrv = drv_to_hdac_driver(drv);

	if (hdev->type != hdrv->type)
		return 0;

	/*
	 * if driver provided a match function use that otherwise we will
	 * use hdac_codec_match function
	 */
	if (hdrv->match)
		return hdrv->match(hdev, hdrv);
	else
		return hdac_codec_match(hdev, hdrv);
	return 1;
}

__attribute__((used)) static int hda_uevent(struct device *dev, struct kobj_uevent_env *env)
{
	char modalias[32];

	snd_hdac_codec_modalias(dev_to_hdac_dev(dev), modalias,
				sizeof(modalias));
	if (add_uevent_var(env, "MODALIAS=%s", modalias))
		return -ENOMEM;
	return 0;
}

