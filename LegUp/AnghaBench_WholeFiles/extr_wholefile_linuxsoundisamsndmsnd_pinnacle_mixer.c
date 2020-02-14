#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_10__   TYPE_5__ ;
typedef  struct TYPE_9__   TYPE_4__ ;
typedef  struct TYPE_8__   TYPE_3__ ;
typedef  struct TYPE_7__   TYPE_2__ ;
typedef  struct TYPE_6__   TYPE_1__ ;

/* Type definitions */
struct snd_msnd {int recsrc; int* left_levels; int* right_levels; scalar_t__ type; int /*<<< orphan*/  mixer_lock; scalar_t__ SMA; int /*<<< orphan*/  flags; } ;
struct snd_kcontrol {int private_value; } ;
struct TYPE_9__ {int* value; } ;
struct TYPE_6__ {int* item; } ;
struct TYPE_10__ {TYPE_4__ integer; TYPE_1__ enumerated; } ;
struct snd_ctl_elem_value {TYPE_5__ value; } ;
struct TYPE_7__ {int max; scalar_t__ min; } ;
struct TYPE_8__ {TYPE_2__ integer; } ;
struct snd_ctl_elem_info {int count; TYPE_3__ value; int /*<<< orphan*/  type; } ;
struct snd_card {int /*<<< orphan*/  mixername; struct snd_msnd* private_data; } ;

/* Variables and functions */
 unsigned int ARRAY_SIZE (scalar_t__) ; 
 int EINVAL ; 
 int /*<<< orphan*/  F_HAVEDIGITAL ; 
 int /*<<< orphan*/  HDEXAR_AUX_SET_POTS ; 
 unsigned char HDEXAR_IN_SET_POTS ; 
 unsigned char HDEXAR_MIC_SET_POTS ; 
 unsigned char HDEXAR_SET_ANA_IN ; 
 unsigned char HDEXAR_SET_DAT_IN ; 
 unsigned char HDEXAR_SET_SYNTH_IN ; 
 int /*<<< orphan*/  HDEX_AUX_REQ ; 
 int LEVEL_ENTRIES ; 
 unsigned int MSND_MASK_DIGITAL ; 
 unsigned int MSND_MASK_IMIX ; 
 int MSND_MASK_SYNTH ; 
#define  MSND_MIXER_AUX 134 
#define  MSND_MIXER_IMIX 133 
#define  MSND_MIXER_LINE 132 
#define  MSND_MIXER_MIC 131 
#define  MSND_MIXER_PCM 130 
#define  MSND_MIXER_SYNTH 129 
#define  MSND_MIXER_VOLUME 128 
 scalar_t__ SMA_bInPotPosLeft ; 
 scalar_t__ SMA_bInPotPosRight ; 
 scalar_t__ SMA_bMicPotPosLeft ; 
 scalar_t__ SMA_bMicPotPosRight ; 
 scalar_t__ SMA_wCurrMastVolLeft ; 
 scalar_t__ SMA_wCurrMastVolRight ; 
 int /*<<< orphan*/  SNDRV_CTL_ELEM_TYPE_INTEGER ; 
 int /*<<< orphan*/  bAuxPotPos ; 
 int /*<<< orphan*/  bInPotPos ; 
 int /*<<< orphan*/  bMicPotPos ; 
 scalar_t__ msndClassic ; 
 scalar_t__ msndPinnacle ; 
 scalar_t__ snd_BUG_ON (int) ; 
 int snd_ctl_add (struct snd_card*,int /*<<< orphan*/ ) ; 
 int snd_ctl_enum_info (struct snd_ctl_elem_info*,int,unsigned int,char const* const*) ; 
 int /*<<< orphan*/  snd_ctl_new1 (scalar_t__,struct snd_msnd*) ; 
 struct snd_msnd* snd_kcontrol_chip (struct snd_kcontrol*) ; 
 scalar_t__ snd_msnd_controls ; 
 int /*<<< orphan*/  snd_msnd_send_dsp_cmd (struct snd_msnd*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  snd_msnd_send_word (struct snd_msnd*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,unsigned char) ; 
 int /*<<< orphan*/  spin_lock_init (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  spin_lock_irqsave (int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  spin_unlock_irqrestore (int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  strcpy (int /*<<< orphan*/ ,char*) ; 
 scalar_t__ test_bit (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  update_pot (int const,int /*<<< orphan*/ ,unsigned char) ; 
 int /*<<< orphan*/  update_potm (int const,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  update_volm (int const,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  wCurrInVol ; 
 int /*<<< orphan*/  wCurrMHdrVol ; 
 int /*<<< orphan*/  wCurrPlayVol ; 
 int /*<<< orphan*/  writeb (int,scalar_t__) ; 
 int /*<<< orphan*/  writew (int,scalar_t__) ; 

__attribute__((used)) static int snd_msndmix_info_mux(struct snd_kcontrol *kcontrol,
				struct snd_ctl_elem_info *uinfo)
{
	static const char * const texts[3] = {
		"Analog", "MASS", "SPDIF",
	};
	struct snd_msnd *chip = snd_kcontrol_chip(kcontrol);
	unsigned items = test_bit(F_HAVEDIGITAL, &chip->flags) ? 3 : 2;

	return snd_ctl_enum_info(uinfo, 1, items, texts);
}

__attribute__((used)) static int snd_msndmix_get_mux(struct snd_kcontrol *kcontrol,
				struct snd_ctl_elem_value *ucontrol)
{
	struct snd_msnd *chip = snd_kcontrol_chip(kcontrol);
	/* MSND_MASK_IMIX is the default */
	ucontrol->value.enumerated.item[0] = 0;

	if (chip->recsrc & MSND_MASK_SYNTH) {
		ucontrol->value.enumerated.item[0] = 1;
	} else if ((chip->recsrc & MSND_MASK_DIGITAL) &&
		 test_bit(F_HAVEDIGITAL, &chip->flags)) {
		ucontrol->value.enumerated.item[0] = 2;
	}


	return 0;
}

__attribute__((used)) static int snd_msndmix_set_mux(struct snd_msnd *chip, int val)
{
	unsigned newrecsrc;
	int change;
	unsigned char msndbyte;

	switch (val) {
	case 0:
		newrecsrc = MSND_MASK_IMIX;
		msndbyte = HDEXAR_SET_ANA_IN;
		break;
	case 1:
		newrecsrc = MSND_MASK_SYNTH;
		msndbyte = HDEXAR_SET_SYNTH_IN;
		break;
	case 2:
		newrecsrc = MSND_MASK_DIGITAL;
		msndbyte = HDEXAR_SET_DAT_IN;
		break;
	default:
		return -EINVAL;
	}
	change  = newrecsrc != chip->recsrc;
	if (change) {
		change = 0;
		if (!snd_msnd_send_word(chip, 0, 0, msndbyte))
			if (!snd_msnd_send_dsp_cmd(chip, HDEX_AUX_REQ)) {
				chip->recsrc = newrecsrc;
				change = 1;
			}
	}
	return change;
}

__attribute__((used)) static int snd_msndmix_put_mux(struct snd_kcontrol *kcontrol,
				struct snd_ctl_elem_value *ucontrol)
{
	struct snd_msnd *msnd = snd_kcontrol_chip(kcontrol);
	return snd_msndmix_set_mux(msnd, ucontrol->value.enumerated.item[0]);
}

__attribute__((used)) static int snd_msndmix_volume_info(struct snd_kcontrol *kcontrol,
				   struct snd_ctl_elem_info *uinfo)
{
	uinfo->type = SNDRV_CTL_ELEM_TYPE_INTEGER;
	uinfo->count = 2;
	uinfo->value.integer.min = 0;
	uinfo->value.integer.max = 100;
	return 0;
}

__attribute__((used)) static int snd_msndmix_volume_get(struct snd_kcontrol *kcontrol,
				  struct snd_ctl_elem_value *ucontrol)
{
	struct snd_msnd *msnd = snd_kcontrol_chip(kcontrol);
	int addr = kcontrol->private_value;
	unsigned long flags;

	spin_lock_irqsave(&msnd->mixer_lock, flags);
	ucontrol->value.integer.value[0] = msnd->left_levels[addr] * 100;
	ucontrol->value.integer.value[0] /= 0xFFFF;
	ucontrol->value.integer.value[1] = msnd->right_levels[addr] * 100;
	ucontrol->value.integer.value[1] /= 0xFFFF;
	spin_unlock_irqrestore(&msnd->mixer_lock, flags);
	return 0;
}

__attribute__((used)) static int snd_msndmix_set(struct snd_msnd *dev, int d, int left, int right)
{
	int bLeft, bRight;
	int wLeft, wRight;
	int updatemaster = 0;

	if (d >= LEVEL_ENTRIES)
		return -EINVAL;

	bLeft = left * 0xff / 100;
	wLeft = left * 0xffff / 100;

	bRight = right * 0xff / 100;
	wRight = right * 0xffff / 100;

	dev->left_levels[d] = wLeft;
	dev->right_levels[d] = wRight;

	switch (d) {
		/* master volume unscaled controls */
	case MSND_MIXER_LINE:			/* line pot control */
		/* scaled by IMIX in digital mix */
		writeb(bLeft, dev->SMA + SMA_bInPotPosLeft);
		writeb(bRight, dev->SMA + SMA_bInPotPosRight);
		if (snd_msnd_send_word(dev, 0, 0, HDEXAR_IN_SET_POTS) == 0)
			snd_msnd_send_dsp_cmd(dev, HDEX_AUX_REQ);
		break;
	case MSND_MIXER_MIC:			/* mic pot control */
		if (dev->type == msndClassic)
			return -EINVAL;
		/* scaled by IMIX in digital mix */
		writeb(bLeft, dev->SMA + SMA_bMicPotPosLeft);
		writeb(bRight, dev->SMA + SMA_bMicPotPosRight);
		if (snd_msnd_send_word(dev, 0, 0, HDEXAR_MIC_SET_POTS) == 0)
			snd_msnd_send_dsp_cmd(dev, HDEX_AUX_REQ);
		break;
	case MSND_MIXER_VOLUME:		/* master volume */
		writew(wLeft, dev->SMA + SMA_wCurrMastVolLeft);
		writew(wRight, dev->SMA + SMA_wCurrMastVolRight);
		/* fall through */

	case MSND_MIXER_AUX:			/* aux pot control */
		/* scaled by master volume */
		/* fall through */

		/* digital controls */
	case MSND_MIXER_SYNTH:			/* synth vol (dsp mix) */
	case MSND_MIXER_PCM:			/* pcm vol (dsp mix) */
	case MSND_MIXER_IMIX:			/* input monitor (dsp mix) */
		/* scaled by master volume */
		updatemaster = 1;
		break;

	default:
		return -EINVAL;
	}

	if (updatemaster) {
		/* update master volume scaled controls */
		update_volm(MSND_MIXER_PCM, wCurrPlayVol);
		update_volm(MSND_MIXER_IMIX, wCurrInVol);
		if (dev->type == msndPinnacle)
			update_volm(MSND_MIXER_SYNTH, wCurrMHdrVol);
		update_potm(MSND_MIXER_AUX, bAuxPotPos, HDEXAR_AUX_SET_POTS);
	}

	return 0;
}

__attribute__((used)) static int snd_msndmix_volume_put(struct snd_kcontrol *kcontrol,
				  struct snd_ctl_elem_value *ucontrol)
{
	struct snd_msnd *msnd = snd_kcontrol_chip(kcontrol);
	int change, addr = kcontrol->private_value;
	int left, right;
	unsigned long flags;

	left = ucontrol->value.integer.value[0] % 101;
	right = ucontrol->value.integer.value[1] % 101;
	spin_lock_irqsave(&msnd->mixer_lock, flags);
	change = msnd->left_levels[addr] != left
		|| msnd->right_levels[addr] != right;
	snd_msndmix_set(msnd, addr, left, right);
	spin_unlock_irqrestore(&msnd->mixer_lock, flags);
	return change;
}

int snd_msndmix_new(struct snd_card *card)
{
	struct snd_msnd *chip = card->private_data;
	unsigned int idx;
	int err;

	if (snd_BUG_ON(!chip))
		return -EINVAL;
	spin_lock_init(&chip->mixer_lock);
	strcpy(card->mixername, "MSND Pinnacle Mixer");

	for (idx = 0; idx < ARRAY_SIZE(snd_msnd_controls); idx++) {
		err = snd_ctl_add(card,
				  snd_ctl_new1(snd_msnd_controls + idx, chip));
		if (err < 0)
			return err;
	}

	return 0;
}

void snd_msndmix_setup(struct snd_msnd *dev)
{
	update_pot(MSND_MIXER_LINE, bInPotPos, HDEXAR_IN_SET_POTS);
	update_potm(MSND_MIXER_AUX, bAuxPotPos, HDEXAR_AUX_SET_POTS);
	update_volm(MSND_MIXER_PCM, wCurrPlayVol);
	update_volm(MSND_MIXER_IMIX, wCurrInVol);
	if (dev->type == msndPinnacle) {
		update_pot(MSND_MIXER_MIC, bMicPotPos, HDEXAR_MIC_SET_POTS);
		update_volm(MSND_MIXER_SYNTH, wCurrMHdrVol);
	}
}

int snd_msndmix_force_recsrc(struct snd_msnd *dev, int recsrc)
{
	dev->recsrc = -1;
	return snd_msndmix_set_mux(dev, recsrc);
}

