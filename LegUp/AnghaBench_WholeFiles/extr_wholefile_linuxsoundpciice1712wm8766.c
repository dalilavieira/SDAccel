#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_14__   TYPE_7__ ;
typedef  struct TYPE_13__   TYPE_6__ ;
typedef  struct TYPE_12__   TYPE_5__ ;
typedef  struct TYPE_11__   TYPE_4__ ;
typedef  struct TYPE_10__   TYPE_3__ ;
typedef  struct TYPE_9__   TYPE_2__ ;
typedef  struct TYPE_8__   TYPE_1__ ;

/* Type definitions */
typedef  size_t u16 ;
struct TYPE_8__ {int /*<<< orphan*/  (* write ) (struct snd_wm8766*,size_t,size_t) ;} ;
struct snd_wm8766 {size_t* regs; TYPE_7__* ctl; int /*<<< orphan*/  card; TYPE_1__ ops; } ;
struct TYPE_13__ {int /*<<< orphan*/ * p; } ;
struct snd_kcontrol_new {int private_value; int (* get ) (struct snd_kcontrol*,struct snd_ctl_elem_value*) ;int (* put ) (struct snd_kcontrol*,struct snd_ctl_elem_value*) ;int (* info ) (struct snd_kcontrol*,struct snd_ctl_elem_info*) ;TYPE_6__ tlv; int /*<<< orphan*/  access; scalar_t__ name; int /*<<< orphan*/  iface; } ;
struct snd_kcontrol {int private_value; } ;
struct TYPE_11__ {size_t* value; } ;
struct TYPE_12__ {TYPE_4__ integer; } ;
struct snd_ctl_elem_value {TYPE_5__ value; } ;
struct TYPE_9__ {size_t min; size_t max; } ;
struct TYPE_10__ {TYPE_2__ integer; } ;
struct snd_ctl_elem_info {int type; int count; TYPE_3__ value; } ;
typedef  int /*<<< orphan*/  cont ;
struct TYPE_14__ {int flags; size_t min; size_t max; size_t reg1; size_t mask1; size_t reg2; size_t mask2; int type; scalar_t__ name; struct snd_kcontrol* kctl; int /*<<< orphan*/ * tlv; int /*<<< orphan*/  (* set ) (struct snd_wm8766*,size_t,size_t) ;int /*<<< orphan*/  (* get ) (struct snd_wm8766*,size_t*,size_t*) ;int /*<<< orphan*/  enum_names; } ;

/* Variables and functions */
 int ARRAY_SIZE (size_t const*) ; 
 int EINVAL ; 
 int ENOMEM ; 
 int /*<<< orphan*/  SNDRV_CTL_ELEM_ACCESS_INACTIVE ; 
 int /*<<< orphan*/  SNDRV_CTL_ELEM_ACCESS_READWRITE ; 
 int /*<<< orphan*/  SNDRV_CTL_ELEM_ACCESS_TLV_READ ; 
 int /*<<< orphan*/  SNDRV_CTL_ELEM_IFACE_MIXER ; 
#define  SNDRV_CTL_ELEM_TYPE_BOOLEAN 130 
#define  SNDRV_CTL_ELEM_TYPE_ENUMERATED 129 
#define  SNDRV_CTL_ELEM_TYPE_INTEGER 128 
 int WM8766_CTL_COUNT ; 
 int WM8766_FLAG_ALC ; 
 int WM8766_FLAG_INVERT ; 
 int WM8766_FLAG_LIM ; 
 int WM8766_FLAG_STEREO ; 
 int WM8766_FLAG_VOL_UPDATE ; 
 size_t WM8766_IF_MASK ; 
 size_t WM8766_REG_COUNT ; 
 size_t WM8766_REG_DACR1 ; 
 size_t WM8766_REG_IFCTRL ; 
 size_t WM8766_REG_RESET ; 
 size_t WM8766_VOL_UPDATE ; 
 size_t __ffs (size_t) ; 
 int /*<<< orphan*/  memcpy (TYPE_7__*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  memset (struct snd_kcontrol_new*,int /*<<< orphan*/ ,int) ; 
 int snd_ctl_add (int /*<<< orphan*/ ,struct snd_kcontrol*) ; 
 int snd_ctl_boolean_mono_info (struct snd_kcontrol*,struct snd_ctl_elem_info*) ; 
 int snd_ctl_boolean_stereo_info (struct snd_kcontrol*,struct snd_ctl_elem_info*) ; 
 int snd_ctl_enum_info (struct snd_ctl_elem_info*,int,size_t,int /*<<< orphan*/ ) ; 
 struct snd_kcontrol* snd_ctl_new1 (struct snd_kcontrol_new*,struct snd_wm8766*) ; 
 struct snd_wm8766* snd_kcontrol_chip (struct snd_kcontrol*) ; 
 int /*<<< orphan*/  snd_wm8766_default_ctl ; 
 int /*<<< orphan*/  stub1 (struct snd_wm8766*,size_t,size_t) ; 
 int /*<<< orphan*/  stub2 (struct snd_wm8766*,size_t*,size_t*) ; 
 int /*<<< orphan*/  stub3 (struct snd_wm8766*,size_t,size_t) ; 
 int /*<<< orphan*/  udelay (int) ; 

__attribute__((used)) static void snd_wm8766_write(struct snd_wm8766 *wm, u16 addr, u16 data)
{
	if (addr < WM8766_REG_COUNT)
		wm->regs[addr] = data;
	wm->ops.write(wm, addr, data);
}

void snd_wm8766_init(struct snd_wm8766 *wm)
{
	int i;
	static const u16 default_values[] = {
		0x000, 0x100,
		0x120, 0x000,
		0x000, 0x100, 0x000, 0x100, 0x000,
		0x000, 0x080,
	};

	memcpy(wm->ctl, snd_wm8766_default_ctl, sizeof(wm->ctl));

	snd_wm8766_write(wm, WM8766_REG_RESET, 0x00); /* reset */
	udelay(10);
	/* load defaults */
	for (i = 0; i < ARRAY_SIZE(default_values); i++)
		snd_wm8766_write(wm, i, default_values[i]);
}

void snd_wm8766_resume(struct snd_wm8766 *wm)
{
	int i;

	for (i = 0; i < WM8766_REG_COUNT; i++)
		snd_wm8766_write(wm, i, wm->regs[i]);
}

void snd_wm8766_set_if(struct snd_wm8766 *wm, u16 dac)
{
	u16 val = wm->regs[WM8766_REG_IFCTRL] & ~WM8766_IF_MASK;

	dac &= WM8766_IF_MASK;
	snd_wm8766_write(wm, WM8766_REG_IFCTRL, val | dac);
}

void snd_wm8766_volume_restore(struct snd_wm8766 *wm)
{
	u16 val = wm->regs[WM8766_REG_DACR1];
	/* restore volume after MCLK stopped */
	snd_wm8766_write(wm, WM8766_REG_DACR1, val | WM8766_VOL_UPDATE);
}

__attribute__((used)) static int snd_wm8766_volume_info(struct snd_kcontrol *kcontrol,
				   struct snd_ctl_elem_info *uinfo)
{
	struct snd_wm8766 *wm = snd_kcontrol_chip(kcontrol);
	int n = kcontrol->private_value;

	uinfo->type = SNDRV_CTL_ELEM_TYPE_INTEGER;
	uinfo->count = (wm->ctl[n].flags & WM8766_FLAG_STEREO) ? 2 : 1;
	uinfo->value.integer.min = wm->ctl[n].min;
	uinfo->value.integer.max = wm->ctl[n].max;

	return 0;
}

__attribute__((used)) static int snd_wm8766_enum_info(struct snd_kcontrol *kcontrol,
				      struct snd_ctl_elem_info *uinfo)
{
	struct snd_wm8766 *wm = snd_kcontrol_chip(kcontrol);
	int n = kcontrol->private_value;

	return snd_ctl_enum_info(uinfo, 1, wm->ctl[n].max,
						wm->ctl[n].enum_names);
}

__attribute__((used)) static int snd_wm8766_ctl_get(struct snd_kcontrol *kcontrol,
				  struct snd_ctl_elem_value *ucontrol)
{
	struct snd_wm8766 *wm = snd_kcontrol_chip(kcontrol);
	int n = kcontrol->private_value;
	u16 val1, val2;

	if (wm->ctl[n].get)
		wm->ctl[n].get(wm, &val1, &val2);
	else {
		val1 = wm->regs[wm->ctl[n].reg1] & wm->ctl[n].mask1;
		val1 >>= __ffs(wm->ctl[n].mask1);
		if (wm->ctl[n].flags & WM8766_FLAG_STEREO) {
			val2 = wm->regs[wm->ctl[n].reg2] & wm->ctl[n].mask2;
			val2 >>= __ffs(wm->ctl[n].mask2);
			if (wm->ctl[n].flags & WM8766_FLAG_VOL_UPDATE)
				val2 &= ~WM8766_VOL_UPDATE;
		}
	}
	if (wm->ctl[n].flags & WM8766_FLAG_INVERT) {
		val1 = wm->ctl[n].max - (val1 - wm->ctl[n].min);
		if (wm->ctl[n].flags & WM8766_FLAG_STEREO)
			val2 = wm->ctl[n].max - (val2 - wm->ctl[n].min);
	}
	ucontrol->value.integer.value[0] = val1;
	if (wm->ctl[n].flags & WM8766_FLAG_STEREO)
		ucontrol->value.integer.value[1] = val2;

	return 0;
}

__attribute__((used)) static int snd_wm8766_ctl_put(struct snd_kcontrol *kcontrol,
				  struct snd_ctl_elem_value *ucontrol)
{
	struct snd_wm8766 *wm = snd_kcontrol_chip(kcontrol);
	int n = kcontrol->private_value;
	u16 val, regval1, regval2;

	/* this also works for enum because value is a union */
	regval1 = ucontrol->value.integer.value[0];
	regval2 = ucontrol->value.integer.value[1];
	if (wm->ctl[n].flags & WM8766_FLAG_INVERT) {
		regval1 = wm->ctl[n].max - (regval1 - wm->ctl[n].min);
		regval2 = wm->ctl[n].max - (regval2 - wm->ctl[n].min);
	}
	if (wm->ctl[n].set)
		wm->ctl[n].set(wm, regval1, regval2);
	else {
		val = wm->regs[wm->ctl[n].reg1] & ~wm->ctl[n].mask1;
		val |= regval1 << __ffs(wm->ctl[n].mask1);
		/* both stereo controls in one register */
		if (wm->ctl[n].flags & WM8766_FLAG_STEREO &&
				wm->ctl[n].reg1 == wm->ctl[n].reg2) {
			val &= ~wm->ctl[n].mask2;
			val |= regval2 << __ffs(wm->ctl[n].mask2);
		}
		snd_wm8766_write(wm, wm->ctl[n].reg1, val);
		/* stereo controls in different registers */
		if (wm->ctl[n].flags & WM8766_FLAG_STEREO &&
				wm->ctl[n].reg1 != wm->ctl[n].reg2) {
			val = wm->regs[wm->ctl[n].reg2] & ~wm->ctl[n].mask2;
			val |= regval2 << __ffs(wm->ctl[n].mask2);
			if (wm->ctl[n].flags & WM8766_FLAG_VOL_UPDATE)
				val |= WM8766_VOL_UPDATE;
			snd_wm8766_write(wm, wm->ctl[n].reg2, val);
		}
	}

	return 0;
}

__attribute__((used)) static int snd_wm8766_add_control(struct snd_wm8766 *wm, int num)
{
	struct snd_kcontrol_new cont;
	struct snd_kcontrol *ctl;

	memset(&cont, 0, sizeof(cont));
	cont.iface = SNDRV_CTL_ELEM_IFACE_MIXER;
	cont.private_value = num;
	cont.name = wm->ctl[num].name;
	cont.access = SNDRV_CTL_ELEM_ACCESS_READWRITE;
	if (wm->ctl[num].flags & WM8766_FLAG_LIM ||
	    wm->ctl[num].flags & WM8766_FLAG_ALC)
		cont.access |= SNDRV_CTL_ELEM_ACCESS_INACTIVE;
	cont.tlv.p = NULL;
	cont.get = snd_wm8766_ctl_get;
	cont.put = snd_wm8766_ctl_put;

	switch (wm->ctl[num].type) {
	case SNDRV_CTL_ELEM_TYPE_INTEGER:
		cont.info = snd_wm8766_volume_info;
		cont.access |= SNDRV_CTL_ELEM_ACCESS_TLV_READ;
		cont.tlv.p = wm->ctl[num].tlv;
		break;
	case SNDRV_CTL_ELEM_TYPE_BOOLEAN:
		wm->ctl[num].max = 1;
		if (wm->ctl[num].flags & WM8766_FLAG_STEREO)
			cont.info = snd_ctl_boolean_stereo_info;
		else
			cont.info = snd_ctl_boolean_mono_info;
		break;
	case SNDRV_CTL_ELEM_TYPE_ENUMERATED:
		cont.info = snd_wm8766_enum_info;
		break;
	default:
		return -EINVAL;
	}
	ctl = snd_ctl_new1(&cont, wm);
	if (!ctl)
		return -ENOMEM;
	wm->ctl[num].kctl = ctl;

	return snd_ctl_add(wm->card, ctl);
}

int snd_wm8766_build_controls(struct snd_wm8766 *wm)
{
	int err, i;

	for (i = 0; i < WM8766_CTL_COUNT; i++)
		if (wm->ctl[i].name) {
			err = snd_wm8766_add_control(wm, i);
			if (err < 0)
				return err;
		}

	return 0;
}

