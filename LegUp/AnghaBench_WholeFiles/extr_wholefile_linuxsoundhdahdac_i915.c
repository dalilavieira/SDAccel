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
struct pci_device_id {int class; int class_mask; int /*<<< orphan*/  member_0; } ;
struct pci_dev {int dummy; } ;
struct i915_audio_component {int dummy; } ;
struct hdac_bus {int /*<<< orphan*/  dev; struct drm_audio_component* audio_component; } ;
struct drm_audio_component {TYPE_2__* ops; int /*<<< orphan*/ * audio_ops; int /*<<< orphan*/  dev; } ;
struct device {TYPE_1__* driver; } ;
struct TYPE_4__ {int (* get_cdclk_freq ) (int /*<<< orphan*/ ) ;} ;
struct TYPE_3__ {int /*<<< orphan*/  name; } ;

/* Variables and functions */
 int /*<<< orphan*/  CONTROLLER_IN_GPU (struct pci_dev*) ; 
 int ENODEV ; 
 int /*<<< orphan*/  HSW_EM4 ; 
 int /*<<< orphan*/  HSW_EM5 ; 
#define  PCI_ANY_ID 130 
#define  PCI_BASE_CLASS_DISPLAY 129 
 int /*<<< orphan*/  PCI_DEVICE (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
#define  PCI_VENDOR_ID_INTEL 128 
 int /*<<< orphan*/  bind_complete ; 
 int /*<<< orphan*/  complete_all (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  dev_info (int /*<<< orphan*/ ,char*) ; 
 int /*<<< orphan*/  i915_init_ops ; 
 int /*<<< orphan*/  init_completion (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  msecs_to_jiffies (int) ; 
 int pci_dev_present (struct pci_device_id const*) ; 
 int /*<<< orphan*/  request_module (char*) ; 
 int /*<<< orphan*/  snd_hdac_acomp_exit (struct hdac_bus*) ; 
 int snd_hdac_acomp_init (struct hdac_bus*,int /*<<< orphan*/ *,int (*) (struct device*,void*),int) ; 
 int /*<<< orphan*/  snd_hdac_chip_writew (struct hdac_bus*,int /*<<< orphan*/ ,unsigned int) ; 
 int /*<<< orphan*/  strcmp (int /*<<< orphan*/ ,char*) ; 
 int stub1 (int /*<<< orphan*/ ) ; 
 struct pci_dev* to_pci_dev (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  wait_for_completion_timeout (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 

void snd_hdac_i915_set_bclk(struct hdac_bus *bus)
{
	struct drm_audio_component *acomp = bus->audio_component;
	struct pci_dev *pci = to_pci_dev(bus->dev);
	int cdclk_freq;
	unsigned int bclk_m, bclk_n;

	if (!acomp || !acomp->ops || !acomp->ops->get_cdclk_freq)
		return; /* only for i915 binding */
	if (!CONTROLLER_IN_GPU(pci))
		return; /* only HSW/BDW */

	cdclk_freq = acomp->ops->get_cdclk_freq(acomp->dev);
	switch (cdclk_freq) {
	case 337500:
		bclk_m = 16;
		bclk_n = 225;
		break;

	case 450000:
	default: /* default CDCLK 450MHz */
		bclk_m = 4;
		bclk_n = 75;
		break;

	case 540000:
		bclk_m = 4;
		bclk_n = 90;
		break;

	case 675000:
		bclk_m = 8;
		bclk_n = 225;
		break;
	}

	snd_hdac_chip_writew(bus, HSW_EM4, bclk_m);
	snd_hdac_chip_writew(bus, HSW_EM5, bclk_n);
}

__attribute__((used)) static int i915_component_master_match(struct device *dev, void *data)
{
	return !strcmp(dev->driver->name, "i915");
}

__attribute__((used)) static bool i915_gfx_present(void)
{
	static const struct pci_device_id ids[] = {
		{ PCI_DEVICE(PCI_VENDOR_ID_INTEL, PCI_ANY_ID),
		  .class = PCI_BASE_CLASS_DISPLAY << 16,
		  .class_mask = 0xff << 16 },
		{}
	};
	return pci_dev_present(ids);
}

__attribute__((used)) static int i915_master_bind(struct device *dev,
			    struct drm_audio_component *acomp)
{
	complete_all(&bind_complete);
	/* clear audio_ops here as it was needed only for completion call */
	acomp->audio_ops = NULL;
	return 0;
}

int snd_hdac_i915_init(struct hdac_bus *bus)
{
	struct drm_audio_component *acomp;
	int err;

	if (!i915_gfx_present())
		return -ENODEV;

	init_completion(&bind_complete);

	err = snd_hdac_acomp_init(bus, &i915_init_ops,
				  i915_component_master_match,
				  sizeof(struct i915_audio_component) - sizeof(*acomp));
	if (err < 0)
		return err;
	acomp = bus->audio_component;
	if (!acomp)
		return -ENODEV;
	if (!acomp->ops) {
		request_module("i915");
		/* 60s timeout */
		wait_for_completion_timeout(&bind_complete,
					    msecs_to_jiffies(60 * 1000));
	}
	if (!acomp->ops) {
		dev_info(bus->dev, "couldn't bind with audio component\n");
		snd_hdac_acomp_exit(bus);
		return -ENODEV;
	}
	return 0;
}

