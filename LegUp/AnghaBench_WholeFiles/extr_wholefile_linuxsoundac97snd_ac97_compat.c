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
struct TYPE_7__ {void (* release ) (struct device*) ;int /*<<< orphan*/ * parent; } ;
struct snd_ac97 {struct ac97_codec_device* private_data; TYPE_2__ dev; int /*<<< orphan*/ * bus; int /*<<< orphan*/  num; } ;
struct device {int dummy; } ;
struct ac97_controller {TYPE_1__* ops; } ;
struct ac97_codec_device {unsigned int vendor_id; int /*<<< orphan*/  num; struct ac97_controller* ac97_ctrl; int /*<<< orphan*/  dev; } ;
struct TYPE_6__ {unsigned short (* read ) (struct ac97_controller*,int /*<<< orphan*/ ,unsigned short) ;int /*<<< orphan*/  (* write ) (struct ac97_controller*,int /*<<< orphan*/ ,unsigned short,unsigned short) ;int /*<<< orphan*/  (* warm_reset ) (struct ac97_controller*) ;int /*<<< orphan*/  (* reset ) (struct ac97_controller*) ;} ;

/* Variables and functions */
 int ENODEV ; 
 int ENOMEM ; 
 struct snd_ac97* ERR_PTR (int) ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int /*<<< orphan*/  compat_soc_ac97_bus ; 
 int /*<<< orphan*/  dev_name (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  dev_set_name (TYPE_2__*,char*,int /*<<< orphan*/ ) ; 
 int device_register (TYPE_2__*) ; 
 int /*<<< orphan*/  device_unregister (TYPE_2__*) ; 
 int /*<<< orphan*/  kfree (int /*<<< orphan*/ ) ; 
 struct snd_ac97* kzalloc (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  put_device (TYPE_2__*) ; 
 unsigned int snd_ac97_bus_scan_one (struct ac97_controller*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  stub1 (struct ac97_controller*) ; 
 int /*<<< orphan*/  stub2 (struct ac97_controller*) ; 
 int /*<<< orphan*/  stub3 (struct ac97_controller*,int /*<<< orphan*/ ,unsigned short,unsigned short) ; 
 unsigned short stub4 (struct ac97_controller*,int /*<<< orphan*/ ,unsigned short) ; 
 struct ac97_codec_device* to_ac97_device (struct ac97_codec_device*) ; 
 int /*<<< orphan*/  to_ac97_t (struct device*) ; 

__attribute__((used)) static inline bool ac97_ids_match(unsigned int id1, unsigned int id2,
				  unsigned int mask)
{
	return (id1 & mask) == (id2 & mask);
}

__attribute__((used)) static void compat_ac97_release(struct device *dev)
{
	kfree(to_ac97_t(dev));
}

__attribute__((used)) static void compat_ac97_reset(struct snd_ac97 *ac97)
{
	struct ac97_codec_device *adev = to_ac97_device(ac97->private_data);
	struct ac97_controller *actrl = adev->ac97_ctrl;

	if (actrl->ops->reset)
		actrl->ops->reset(actrl);
}

__attribute__((used)) static void compat_ac97_warm_reset(struct snd_ac97 *ac97)
{
	struct ac97_codec_device *adev = to_ac97_device(ac97->private_data);
	struct ac97_controller *actrl = adev->ac97_ctrl;

	if (actrl->ops->warm_reset)
		actrl->ops->warm_reset(actrl);
}

__attribute__((used)) static void compat_ac97_write(struct snd_ac97 *ac97, unsigned short reg,
			      unsigned short val)
{
	struct ac97_codec_device *adev = to_ac97_device(ac97->private_data);
	struct ac97_controller *actrl = adev->ac97_ctrl;

	actrl->ops->write(actrl, ac97->num, reg, val);
}

__attribute__((used)) static unsigned short compat_ac97_read(struct snd_ac97 *ac97,
				       unsigned short reg)
{
	struct ac97_codec_device *adev = to_ac97_device(ac97->private_data);
	struct ac97_controller *actrl = adev->ac97_ctrl;

	return actrl->ops->read(actrl, ac97->num, reg);
}

struct snd_ac97 *snd_ac97_compat_alloc(struct ac97_codec_device *adev)
{
	struct snd_ac97 *ac97;
	int ret;

	ac97 = kzalloc(sizeof(struct snd_ac97), GFP_KERNEL);
	if (ac97 == NULL)
		return ERR_PTR(-ENOMEM);

	ac97->private_data = adev;
	ac97->bus = &compat_soc_ac97_bus;

	ac97->dev.parent = &adev->dev;
	ac97->dev.release = compat_ac97_release;
	dev_set_name(&ac97->dev, "%s-compat", dev_name(&adev->dev));
	ret = device_register(&ac97->dev);
	if (ret) {
		put_device(&ac97->dev);
		return ERR_PTR(ret);
	}

	return ac97;
}

void snd_ac97_compat_release(struct snd_ac97 *ac97)
{
	device_unregister(&ac97->dev);
}

int snd_ac97_reset(struct snd_ac97 *ac97, bool try_warm, unsigned int id,
	unsigned int id_mask)
{
	struct ac97_codec_device *adev = to_ac97_device(ac97->private_data);
	struct ac97_controller *actrl = adev->ac97_ctrl;
	unsigned int scanned;

	if (try_warm) {
		compat_ac97_warm_reset(ac97);
		scanned = snd_ac97_bus_scan_one(actrl, adev->num);
		if (ac97_ids_match(scanned, adev->vendor_id, id_mask))
			return 1;
	}

	compat_ac97_reset(ac97);
	compat_ac97_warm_reset(ac97);
	scanned = snd_ac97_bus_scan_one(actrl, adev->num);
	if (ac97_ids_match(scanned, adev->vendor_id, id_mask))
		return 0;

	return -ENODEV;
}

