#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_13__   TYPE_7__ ;
typedef  struct TYPE_12__   TYPE_3__ ;
typedef  struct TYPE_11__   TYPE_2__ ;
typedef  struct TYPE_10__   TYPE_1__ ;

/* Type definitions */
struct TYPE_11__ {TYPE_7__* parent; } ;
struct rtc_device {int /*<<< orphan*/  nvmem; TYPE_3__* nvram; scalar_t__ nvram_old_abi; int /*<<< orphan*/  owner; TYPE_2__ dev; } ;
struct nvmem_config {size_t size; int /*<<< orphan*/  owner; TYPE_7__* dev; } ;
struct kobject {int dummy; } ;
struct file {int dummy; } ;
struct bin_attribute {struct rtc_device* private; } ;
typedef  int /*<<< orphan*/  ssize_t ;
typedef  int /*<<< orphan*/  loff_t ;
struct TYPE_13__ {int /*<<< orphan*/  kobj; } ;
struct TYPE_10__ {char* name; int mode; } ;
struct TYPE_12__ {size_t size; int /*<<< orphan*/  (* write ) (struct file*,struct kobject*,struct bin_attribute*,char*,int /*<<< orphan*/ ,size_t) ;int /*<<< orphan*/  (* read ) (struct file*,struct kobject*,struct bin_attribute*,char*,int /*<<< orphan*/ ,size_t) ;struct rtc_device* private; TYPE_1__ attr; } ;

/* Variables and functions */
 int EBUSY ; 
 int ENODEV ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 scalar_t__ IS_ERR (int /*<<< orphan*/ ) ; 
 scalar_t__ IS_ERR_OR_NULL (int /*<<< orphan*/ ) ; 
 int PTR_ERR (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  dev_warn_once (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  devm_kfree (TYPE_7__*,TYPE_3__*) ; 
 TYPE_3__* devm_kzalloc (TYPE_7__*,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  kobj_to_dev (struct kobject*) ; 
 int /*<<< orphan*/  nvmem_device_read (int /*<<< orphan*/ ,int /*<<< orphan*/ ,size_t,char*) ; 
 int /*<<< orphan*/  nvmem_device_write (int /*<<< orphan*/ ,int /*<<< orphan*/ ,size_t,char*) ; 
 int /*<<< orphan*/  nvmem_register (struct nvmem_config*) ; 
 int /*<<< orphan*/  nvmem_unregister (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  nvram_warning ; 
 int /*<<< orphan*/  sysfs_bin_attr_init (TYPE_3__*) ; 
 int sysfs_create_bin_file (int /*<<< orphan*/ *,TYPE_3__*) ; 
 int /*<<< orphan*/  sysfs_remove_bin_file (int /*<<< orphan*/ *,TYPE_3__*) ; 

__attribute__((used)) static ssize_t
rtc_nvram_read(struct file *filp, struct kobject *kobj,
	       struct bin_attribute *attr,
	       char *buf, loff_t off, size_t count)
{
	struct rtc_device *rtc = attr->private;

	dev_warn_once(kobj_to_dev(kobj), nvram_warning);

	return nvmem_device_read(rtc->nvmem, off, count, buf);
}

__attribute__((used)) static ssize_t
rtc_nvram_write(struct file *filp, struct kobject *kobj,
		struct bin_attribute *attr,
		char *buf, loff_t off, size_t count)
{
	struct rtc_device *rtc = attr->private;

	dev_warn_once(kobj_to_dev(kobj), nvram_warning);

	return nvmem_device_write(rtc->nvmem, off, count, buf);
}

__attribute__((used)) static int rtc_nvram_register(struct rtc_device *rtc, size_t size)
{
	int err;

	rtc->nvram = devm_kzalloc(rtc->dev.parent,
				sizeof(struct bin_attribute),
				GFP_KERNEL);
	if (!rtc->nvram)
		return -ENOMEM;

	rtc->nvram->attr.name = "nvram";
	rtc->nvram->attr.mode = 0644;
	rtc->nvram->private = rtc;

	sysfs_bin_attr_init(rtc->nvram);

	rtc->nvram->read = rtc_nvram_read;
	rtc->nvram->write = rtc_nvram_write;
	rtc->nvram->size = size;

	err = sysfs_create_bin_file(&rtc->dev.parent->kobj,
				    rtc->nvram);
	if (err) {
		devm_kfree(rtc->dev.parent, rtc->nvram);
		rtc->nvram = NULL;
	}

	return err;
}

__attribute__((used)) static void rtc_nvram_unregister(struct rtc_device *rtc)
{
	sysfs_remove_bin_file(&rtc->dev.parent->kobj, rtc->nvram);
}

int rtc_nvmem_register(struct rtc_device *rtc,
		       struct nvmem_config *nvmem_config)
{
	if (!IS_ERR_OR_NULL(rtc->nvmem))
		return -EBUSY;

	if (!nvmem_config)
		return -ENODEV;

	nvmem_config->dev = rtc->dev.parent;
	nvmem_config->owner = rtc->owner;
	rtc->nvmem = nvmem_register(nvmem_config);
	if (IS_ERR(rtc->nvmem))
		return PTR_ERR(rtc->nvmem);

	/* Register the old ABI */
	if (rtc->nvram_old_abi)
		rtc_nvram_register(rtc, nvmem_config->size);

	return 0;
}

void rtc_nvmem_unregister(struct rtc_device *rtc)
{
	if (IS_ERR_OR_NULL(rtc->nvmem))
		return;

	/* unregister the old ABI */
	if (rtc->nvram)
		rtc_nvram_unregister(rtc);

	nvmem_unregister(rtc->nvmem);
}

