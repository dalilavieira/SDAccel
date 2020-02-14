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
typedef  int u8 ;
typedef  int u16 ;
struct TYPE_8__ {int /*<<< orphan*/  (* write ) (struct snd_wm8776*,int,int) ;} ;
struct snd_wm8776 {int* regs; int agc_mode; TYPE_7__* ctl; struct snd_card* card; TYPE_1__ ops; } ;
struct snd_kcontrol_volatile {int /*<<< orphan*/  access; } ;
struct TYPE_13__ {int /*<<< orphan*/ * p; } ;
struct snd_kcontrol_new {char* name; int private_value; int (* get ) (struct snd_kcontrol*,struct snd_ctl_elem_value*) ;int (* put ) (struct snd_kcontrol*,struct snd_ctl_elem_value*) ;int (* info ) (struct snd_kcontrol*,struct snd_ctl_elem_info*) ;TYPE_6__ tlv; int /*<<< orphan*/  access; void* iface; } ;
struct snd_kcontrol {int private_value; int /*<<< orphan*/  id; struct snd_kcontrol_volatile* vd; } ;
struct TYPE_11__ {int* value; } ;
struct TYPE_12__ {TYPE_4__ integer; } ;
struct snd_ctl_elem_value {TYPE_5__ value; } ;
struct TYPE_9__ {int min; int max; } ;
struct TYPE_10__ {TYPE_2__ integer; } ;
struct snd_ctl_elem_info {int type; int count; TYPE_3__ value; } ;
struct snd_ctl_elem_id {char* name; int private_value; int (* get ) (struct snd_kcontrol*,struct snd_ctl_elem_value*) ;int (* put ) (struct snd_kcontrol*,struct snd_ctl_elem_value*) ;int (* info ) (struct snd_kcontrol*,struct snd_ctl_elem_info*) ;TYPE_6__ tlv; int /*<<< orphan*/  access; void* iface; } ;
struct snd_card {int dummy; } ;
typedef  int /*<<< orphan*/  elem_id ;
typedef  int /*<<< orphan*/  cont ;
struct TYPE_14__ {int flags; char* name; int min; int max; size_t reg1; int mask1; size_t reg2; int mask2; int type; int /*<<< orphan*/ * tlv; int /*<<< orphan*/  (* set ) (struct snd_wm8776*,int,int) ;int /*<<< orphan*/  (* get ) (struct snd_wm8776*,int*,int*) ;int /*<<< orphan*/  enum_names; } ;

/* Variables and functions */
 int ARRAY_SIZE (int const*) ; 
 int EINVAL ; 
 int ENOMEM ; 
 int /*<<< orphan*/  SNDRV_CTL_ELEM_ACCESS_INACTIVE ; 
 int /*<<< orphan*/  SNDRV_CTL_ELEM_ACCESS_READWRITE ; 
 int /*<<< orphan*/  SNDRV_CTL_ELEM_ACCESS_TLV_READ ; 
 void* SNDRV_CTL_ELEM_IFACE_MIXER ; 
#define  SNDRV_CTL_ELEM_TYPE_BOOLEAN 135 
#define  SNDRV_CTL_ELEM_TYPE_ENUMERATED 134 
#define  SNDRV_CTL_ELEM_TYPE_INTEGER 133 
 int /*<<< orphan*/  SNDRV_CTL_EVENT_MASK_INFO ; 
#define  WM8776_AGC_ALC_L 132 
#define  WM8776_AGC_ALC_R 131 
#define  WM8776_AGC_ALC_STEREO 130 
#define  WM8776_AGC_LIM 129 
#define  WM8776_AGC_OFF 128 
 int WM8776_ALC1_LCSEL_ALCL ; 
 int WM8776_ALC1_LCSEL_ALCR ; 
 int WM8776_ALC1_LCSEL_ALCSTEREO ; 
 int WM8776_ALC1_LCT_MASK ; 
 int WM8776_ALC2_LCEN ; 
 int WM8776_CTL_COUNT ; 
 int WM8776_FLAG_ALC ; 
 int WM8776_FLAG_INVERT ; 
 int WM8776_FLAG_LIM ; 
 int WM8776_FLAG_STEREO ; 
 int WM8776_FLAG_VOL_UPDATE ; 
 size_t WM8776_REG_ALCCTRL1 ; 
 size_t WM8776_REG_ALCCTRL2 ; 
 int WM8776_REG_COUNT ; 
 size_t WM8776_REG_DACRVOL ; 
 int WM8776_REG_PWRDOWN ; 
 int WM8776_REG_RESET ; 
 int WM8776_VOL_UPDATE ; 
 int __ffs (int) ; 
 int /*<<< orphan*/  memcpy (TYPE_7__*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  memset (struct snd_kcontrol_new*,int /*<<< orphan*/ ,int) ; 
 int snd_ctl_add (struct snd_card*,struct snd_kcontrol*) ; 
 int snd_ctl_boolean_mono_info (struct snd_kcontrol*,struct snd_ctl_elem_info*) ; 
 int snd_ctl_boolean_stereo_info (struct snd_kcontrol*,struct snd_ctl_elem_info*) ; 
 int snd_ctl_enum_info (struct snd_ctl_elem_info*,int,int,int /*<<< orphan*/ ) ; 
 struct snd_kcontrol* snd_ctl_find_id (struct snd_card*,struct snd_kcontrol_new*) ; 
 unsigned int snd_ctl_get_ioff (struct snd_kcontrol*,int /*<<< orphan*/ *) ; 
 struct snd_kcontrol* snd_ctl_new1 (struct snd_kcontrol_new*,struct snd_wm8776*) ; 
 int /*<<< orphan*/  snd_ctl_notify (struct snd_card*,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 struct snd_wm8776* snd_kcontrol_chip (struct snd_kcontrol*) ; 
 int /*<<< orphan*/  snd_wm8776_default_ctl ; 
 int /*<<< orphan*/  strlcpy (char*,char const*,int) ; 
 int /*<<< orphan*/  stub1 (struct snd_wm8776*,int,int) ; 
 int /*<<< orphan*/  stub2 (struct snd_wm8776*,int*,int*) ; 
 int /*<<< orphan*/  stub3 (struct snd_wm8776*,int,int) ; 
 int /*<<< orphan*/  udelay (int) ; 

__attribute__((used)) static void snd_wm8776_write(struct snd_wm8776 *wm, u16 addr, u16 data)
{
	u8 bus_addr = addr << 1 | data >> 8;	/* addr + 9th data bit */
	u8 bus_data = data & 0xff;		/* remaining 8 data bits */

	if (addr < WM8776_REG_RESET)
		wm->regs[addr] = data;
	wm->ops.write(wm, bus_addr, bus_data);
}

__attribute__((used)) static void snd_wm8776_activate_ctl(struct snd_wm8776 *wm,
				    const char *ctl_name,
				    bool active)
{
	struct snd_card *card = wm->card;
	struct snd_kcontrol *kctl;
	struct snd_kcontrol_volatile *vd;
	struct snd_ctl_elem_id elem_id;
	unsigned int index_offset;

	memset(&elem_id, 0, sizeof(elem_id));
	strlcpy(elem_id.name, ctl_name, sizeof(elem_id.name));
	elem_id.iface = SNDRV_CTL_ELEM_IFACE_MIXER;
	kctl = snd_ctl_find_id(card, &elem_id);
	if (!kctl)
		return;
	index_offset = snd_ctl_get_ioff(kctl, &kctl->id);
	vd = &kctl->vd[index_offset];
	if (active)
		vd->access &= ~SNDRV_CTL_ELEM_ACCESS_INACTIVE;
	else
		vd->access |= SNDRV_CTL_ELEM_ACCESS_INACTIVE;
	snd_ctl_notify(card, SNDRV_CTL_EVENT_MASK_INFO, &kctl->id);
}

__attribute__((used)) static void snd_wm8776_update_agc_ctl(struct snd_wm8776 *wm)
{
	int i, flags_on = 0, flags_off = 0;

	switch (wm->agc_mode) {
	case WM8776_AGC_OFF:
		flags_off = WM8776_FLAG_LIM | WM8776_FLAG_ALC;
		break;
	case WM8776_AGC_LIM:
		flags_off = WM8776_FLAG_ALC;
		flags_on = WM8776_FLAG_LIM;
		break;
	case WM8776_AGC_ALC_R:
	case WM8776_AGC_ALC_L:
	case WM8776_AGC_ALC_STEREO:
		flags_off = WM8776_FLAG_LIM;
		flags_on = WM8776_FLAG_ALC;
		break;
	}

	for (i = 0; i < WM8776_CTL_COUNT; i++)
		if (wm->ctl[i].flags & flags_off)
			snd_wm8776_activate_ctl(wm, wm->ctl[i].name, false);
		else if (wm->ctl[i].flags & flags_on)
			snd_wm8776_activate_ctl(wm, wm->ctl[i].name, true);
}

__attribute__((used)) static void snd_wm8776_set_agc(struct snd_wm8776 *wm, u16 agc, u16 nothing)
{
	u16 alc1 = wm->regs[WM8776_REG_ALCCTRL1] & ~WM8776_ALC1_LCT_MASK;
	u16 alc2 = wm->regs[WM8776_REG_ALCCTRL2] & ~WM8776_ALC2_LCEN;

	switch (agc) {
	case 0:	/* Off */
		wm->agc_mode = WM8776_AGC_OFF;
		break;
	case 1: /* Limiter */
		alc2 |= WM8776_ALC2_LCEN;
		wm->agc_mode = WM8776_AGC_LIM;
		break;
	case 2: /* ALC Right */
		alc1 |= WM8776_ALC1_LCSEL_ALCR;
		alc2 |= WM8776_ALC2_LCEN;
		wm->agc_mode = WM8776_AGC_ALC_R;
		break;
	case 3: /* ALC Left */
		alc1 |= WM8776_ALC1_LCSEL_ALCL;
		alc2 |= WM8776_ALC2_LCEN;
		wm->agc_mode = WM8776_AGC_ALC_L;
		break;
	case 4: /* ALC Stereo */
		alc1 |= WM8776_ALC1_LCSEL_ALCSTEREO;
		alc2 |= WM8776_ALC2_LCEN;
		wm->agc_mode = WM8776_AGC_ALC_STEREO;
		break;
	}
	snd_wm8776_write(wm, WM8776_REG_ALCCTRL1, alc1);
	snd_wm8776_write(wm, WM8776_REG_ALCCTRL2, alc2);
	snd_wm8776_update_agc_ctl(wm);
}

__attribute__((used)) static void snd_wm8776_get_agc(struct snd_wm8776 *wm, u16 *mode, u16 *nothing)
{
	*mode = wm->agc_mode;
}

void snd_wm8776_init(struct snd_wm8776 *wm)
{
	int i;
	static const u16 default_values[] = {
		0x000, 0x100, 0x000,
		0x000, 0x100, 0x000,
		0x000, 0x090, 0x000, 0x000,
		0x022, 0x022, 0x022,
		0x008, 0x0cf, 0x0cf, 0x07b, 0x000,
		0x032, 0x000, 0x0a6, 0x001, 0x001
	};

	memcpy(wm->ctl, snd_wm8776_default_ctl, sizeof(wm->ctl));

	snd_wm8776_write(wm, WM8776_REG_RESET, 0x00); /* reset */
	udelay(10);
	/* load defaults */
	for (i = 0; i < ARRAY_SIZE(default_values); i++)
		snd_wm8776_write(wm, i, default_values[i]);
}

void snd_wm8776_resume(struct snd_wm8776 *wm)
{
	int i;

	for (i = 0; i < WM8776_REG_COUNT; i++)
		snd_wm8776_write(wm, i, wm->regs[i]);
}

void snd_wm8776_set_power(struct snd_wm8776 *wm, u16 power)
{
	snd_wm8776_write(wm, WM8776_REG_PWRDOWN, power);
}

void snd_wm8776_volume_restore(struct snd_wm8776 *wm)
{
	u16 val = wm->regs[WM8776_REG_DACRVOL];
	/* restore volume after MCLK stopped */
	snd_wm8776_write(wm, WM8776_REG_DACRVOL, val | WM8776_VOL_UPDATE);
}

__attribute__((used)) static int snd_wm8776_volume_info(struct snd_kcontrol *kcontrol,
				   struct snd_ctl_elem_info *uinfo)
{
	struct snd_wm8776 *wm = snd_kcontrol_chip(kcontrol);
	int n = kcontrol->private_value;

	uinfo->type = SNDRV_CTL_ELEM_TYPE_INTEGER;
	uinfo->count = (wm->ctl[n].flags & WM8776_FLAG_STEREO) ? 2 : 1;
	uinfo->value.integer.min = wm->ctl[n].min;
	uinfo->value.integer.max = wm->ctl[n].max;

	return 0;
}

__attribute__((used)) static int snd_wm8776_enum_info(struct snd_kcontrol *kcontrol,
				      struct snd_ctl_elem_info *uinfo)
{
	struct snd_wm8776 *wm = snd_kcontrol_chip(kcontrol);
	int n = kcontrol->private_value;

	return snd_ctl_enum_info(uinfo, 1, wm->ctl[n].max,
						wm->ctl[n].enum_names);
}

__attribute__((used)) static int snd_wm8776_ctl_get(struct snd_kcontrol *kcontrol,
				  struct snd_ctl_elem_value *ucontrol)
{
	struct snd_wm8776 *wm = snd_kcontrol_chip(kcontrol);
	int n = kcontrol->private_value;
	u16 val1, val2;

	if (wm->ctl[n].get)
		wm->ctl[n].get(wm, &val1, &val2);
	else {
		val1 = wm->regs[wm->ctl[n].reg1] & wm->ctl[n].mask1;
		val1 >>= __ffs(wm->ctl[n].mask1);
		if (wm->ctl[n].flags & WM8776_FLAG_STEREO) {
			val2 = wm->regs[wm->ctl[n].reg2] & wm->ctl[n].mask2;
			val2 >>= __ffs(wm->ctl[n].mask2);
			if (wm->ctl[n].flags & WM8776_FLAG_VOL_UPDATE)
				val2 &= ~WM8776_VOL_UPDATE;
		}
	}
	if (wm->ctl[n].flags & WM8776_FLAG_INVERT) {
		val1 = wm->ctl[n].max - (val1 - wm->ctl[n].min);
		if (wm->ctl[n].flags & WM8776_FLAG_STEREO)
			val2 = wm->ctl[n].max - (val2 - wm->ctl[n].min);
	}
	ucontrol->value.integer.value[0] = val1;
	if (wm->ctl[n].flags & WM8776_FLAG_STEREO)
		ucontrol->value.integer.value[1] = val2;

	return 0;
}

__attribute__((used)) static int snd_wm8776_ctl_put(struct snd_kcontrol *kcontrol,
				  struct snd_ctl_elem_value *ucontrol)
{
	struct snd_wm8776 *wm = snd_kcontrol_chip(kcontrol);
	int n = kcontrol->private_value;
	u16 val, regval1, regval2;

	/* this also works for enum because value is a union */
	regval1 = ucontrol->value.integer.value[0];
	regval2 = ucontrol->value.integer.value[1];
	if (wm->ctl[n].flags & WM8776_FLAG_INVERT) {
		regval1 = wm->ctl[n].max - (regval1 - wm->ctl[n].min);
		regval2 = wm->ctl[n].max - (regval2 - wm->ctl[n].min);
	}
	if (wm->ctl[n].set)
		wm->ctl[n].set(wm, regval1, regval2);
	else {
		val = wm->regs[wm->ctl[n].reg1] & ~wm->ctl[n].mask1;
		val |= regval1 << __ffs(wm->ctl[n].mask1);
		/* both stereo controls in one register */
		if (wm->ctl[n].flags & WM8776_FLAG_STEREO &&
				wm->ctl[n].reg1 == wm->ctl[n].reg2) {
			val &= ~wm->ctl[n].mask2;
			val |= regval2 << __ffs(wm->ctl[n].mask2);
		}
		snd_wm8776_write(wm, wm->ctl[n].reg1, val);
		/* stereo controls in different registers */
		if (wm->ctl[n].flags & WM8776_FLAG_STEREO &&
				wm->ctl[n].reg1 != wm->ctl[n].reg2) {
			val = wm->regs[wm->ctl[n].reg2] & ~wm->ctl[n].mask2;
			val |= regval2 << __ffs(wm->ctl[n].mask2);
			if (wm->ctl[n].flags & WM8776_FLAG_VOL_UPDATE)
				val |= WM8776_VOL_UPDATE;
			snd_wm8776_write(wm, wm->ctl[n].reg2, val);
		}
	}

	return 0;
}

__attribute__((used)) static int snd_wm8776_add_control(struct snd_wm8776 *wm, int num)
{
	struct snd_kcontrol_new cont;
	struct snd_kcontrol *ctl;

	memset(&cont, 0, sizeof(cont));
	cont.iface = SNDRV_CTL_ELEM_IFACE_MIXER;
	cont.private_value = num;
	cont.name = wm->ctl[num].name;
	cont.access = SNDRV_CTL_ELEM_ACCESS_READWRITE;
	if (wm->ctl[num].flags & WM8776_FLAG_LIM ||
	    wm->ctl[num].flags & WM8776_FLAG_ALC)
		cont.access |= SNDRV_CTL_ELEM_ACCESS_INACTIVE;
	cont.tlv.p = NULL;
	cont.get = snd_wm8776_ctl_get;
	cont.put = snd_wm8776_ctl_put;

	switch (wm->ctl[num].type) {
	case SNDRV_CTL_ELEM_TYPE_INTEGER:
		cont.info = snd_wm8776_volume_info;
		cont.access |= SNDRV_CTL_ELEM_ACCESS_TLV_READ;
		cont.tlv.p = wm->ctl[num].tlv;
		break;
	case SNDRV_CTL_ELEM_TYPE_BOOLEAN:
		wm->ctl[num].max = 1;
		if (wm->ctl[num].flags & WM8776_FLAG_STEREO)
			cont.info = snd_ctl_boolean_stereo_info;
		else
			cont.info = snd_ctl_boolean_mono_info;
		break;
	case SNDRV_CTL_ELEM_TYPE_ENUMERATED:
		cont.info = snd_wm8776_enum_info;
		break;
	default:
		return -EINVAL;
	}
	ctl = snd_ctl_new1(&cont, wm);
	if (!ctl)
		return -ENOMEM;

	return snd_ctl_add(wm->card, ctl);
}

int snd_wm8776_build_controls(struct snd_wm8776 *wm)
{
	int err, i;

	for (i = 0; i < WM8776_CTL_COUNT; i++)
		if (wm->ctl[i].name) {
			err = snd_wm8776_add_control(wm, i);
			if (err < 0)
				return err;
		}

	return 0;
}

