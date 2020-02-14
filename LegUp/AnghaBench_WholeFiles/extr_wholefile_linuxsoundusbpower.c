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
struct usb_host_interface {int /*<<< orphan*/  extralen; int /*<<< orphan*/  extra; } ;
struct usb_device {int /*<<< orphan*/  dev; } ;
struct uac3_power_domain_descriptor {int bNrEntities; unsigned char* baEntityID; int bPowerDomainID; int /*<<< orphan*/  waRecoveryTime2; int /*<<< orphan*/  waRecoveryTime1; } ;
struct snd_usb_power_domain {int pd_id; int pd_d1d0_rec; int pd_d2d0_rec; } ;
struct snd_usb_audio {struct usb_device* dev; int /*<<< orphan*/  ctrl_intf; } ;
typedef  int /*<<< orphan*/  state ;
typedef  int /*<<< orphan*/  current_state ;
struct TYPE_2__ {int bInterfaceNumber; } ;

/* Variables and functions */
 int EINVAL ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int /*<<< orphan*/  UAC2_CS_CUR ; 
 int UAC3_AC_POWER_DOMAIN_CONTROL ; 
 unsigned char UAC3_PD_STATE_D0 ; 
#define  UAC3_PD_STATE_D1 129 
#define  UAC3_PD_STATE_D2 128 
 int /*<<< orphan*/  UAC3_POWER_DOMAIN ; 
 int USB_DIR_IN ; 
 int USB_DIR_OUT ; 
 int USB_RECIP_INTERFACE ; 
 int USB_TYPE_CLASS ; 
 int /*<<< orphan*/  dev_dbg (int /*<<< orphan*/ *,char*,int,unsigned char) ; 
 int /*<<< orphan*/  dev_err (int /*<<< orphan*/ *,char*,unsigned char,...) ; 
 TYPE_1__* get_iface_desc (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  kfree (struct snd_usb_power_domain*) ; 
 struct snd_usb_power_domain* kzalloc (int,int /*<<< orphan*/ ) ; 
 void* le16_to_cpu (int /*<<< orphan*/ ) ; 
 int snd_usb_ctl_msg (struct usb_device*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int,int,int,unsigned char*,int) ; 
 void* snd_usb_find_csint_desc (int /*<<< orphan*/ ,int /*<<< orphan*/ ,void*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  udelay (int) ; 
 int /*<<< orphan*/  usb_rcvctrlpipe (struct usb_device*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  usb_sndctrlpipe (struct usb_device*,int /*<<< orphan*/ ) ; 

__attribute__((used)) static inline int snd_usb_ctrl_intf(struct snd_usb_audio *chip)
{
	return get_iface_desc(chip->ctrl_intf)->bInterfaceNumber;
}

__attribute__((used)) static inline int snd_usb_autoresume(struct snd_usb_audio *chip)
{
	return 0;
}

__attribute__((used)) static inline void snd_usb_autosuspend(struct snd_usb_audio *chip)
{
}

struct snd_usb_power_domain *
snd_usb_find_power_domain(struct usb_host_interface *ctrl_iface,
			  unsigned char id)
{
	struct snd_usb_power_domain *pd;
	void *p;

	pd = kzalloc(sizeof(*pd), GFP_KERNEL);
	if (!pd)
		return NULL;

	p = NULL;
	while ((p = snd_usb_find_csint_desc(ctrl_iface->extra,
					    ctrl_iface->extralen,
					    p, UAC3_POWER_DOMAIN)) != NULL) {
		struct uac3_power_domain_descriptor *pd_desc = p;
		int i;

		for (i = 0; i < pd_desc->bNrEntities; i++) {
			if (pd_desc->baEntityID[i] == id) {
				pd->pd_id = pd_desc->bPowerDomainID;
				pd->pd_d1d0_rec =
					le16_to_cpu(pd_desc->waRecoveryTime1);
				pd->pd_d2d0_rec =
					le16_to_cpu(pd_desc->waRecoveryTime2);
				return pd;
			}
		}
	}

	kfree(pd);
	return NULL;
}

int snd_usb_power_domain_set(struct snd_usb_audio *chip,
			     struct snd_usb_power_domain *pd,
			     unsigned char state)
{
	struct usb_device *dev = chip->dev;
	unsigned char current_state;
	int err, idx;

	idx = snd_usb_ctrl_intf(chip) | (pd->pd_id << 8);

	err = snd_usb_ctl_msg(chip->dev, usb_rcvctrlpipe(chip->dev, 0),
			      UAC2_CS_CUR,
			      USB_RECIP_INTERFACE | USB_TYPE_CLASS | USB_DIR_IN,
			      UAC3_AC_POWER_DOMAIN_CONTROL << 8, idx,
			      &current_state, sizeof(current_state));
	if (err < 0) {
		dev_err(&dev->dev, "Can't get UAC3 power state for id %d\n",
			pd->pd_id);
		return err;
	}

	if (current_state == state) {
		dev_dbg(&dev->dev, "UAC3 power domain id %d already in state %d\n",
			pd->pd_id, state);
		return 0;
	}

	err = snd_usb_ctl_msg(chip->dev, usb_sndctrlpipe(chip->dev, 0), UAC2_CS_CUR,
			      USB_RECIP_INTERFACE | USB_TYPE_CLASS | USB_DIR_OUT,
			      UAC3_AC_POWER_DOMAIN_CONTROL << 8, idx,
			      &state, sizeof(state));
	if (err < 0) {
		dev_err(&dev->dev, "Can't set UAC3 power state to %d for id %d\n",
			state, pd->pd_id);
		return err;
	}

	if (state == UAC3_PD_STATE_D0) {
		switch (current_state) {
		case UAC3_PD_STATE_D2:
			udelay(pd->pd_d2d0_rec * 50);
			break;
		case UAC3_PD_STATE_D1:
			udelay(pd->pd_d1d0_rec * 50);
			break;
		default:
			return -EINVAL;
		}
	}

	dev_dbg(&dev->dev, "UAC3 power domain id %d change to state %d\n",
		pd->pd_id, state);

	return 0;
}

