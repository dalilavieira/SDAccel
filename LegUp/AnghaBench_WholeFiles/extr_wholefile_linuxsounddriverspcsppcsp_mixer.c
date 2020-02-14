#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_12__   TYPE_6__ ;
typedef  struct TYPE_11__   TYPE_5__ ;
typedef  struct TYPE_10__   TYPE_4__ ;
typedef  struct TYPE_9__   TYPE_3__ ;
typedef  struct TYPE_8__   TYPE_2__ ;
typedef  struct TYPE_7__   TYPE_1__ ;

/* Type definitions */
struct snd_pcsp {int enable; scalar_t__ max_treble; int treble; int pcspkr; struct snd_card* card; } ;
struct snd_kcontrol_new {int dummy; } ;
struct snd_kcontrol {int dummy; } ;
struct TYPE_11__ {int* value; } ;
struct TYPE_8__ {int* item; } ;
struct TYPE_12__ {TYPE_5__ integer; TYPE_2__ enumerated; } ;
struct snd_ctl_elem_value {TYPE_6__ value; } ;
struct TYPE_9__ {int max; scalar_t__ min; } ;
struct TYPE_7__ {scalar_t__ items; scalar_t__ item; int /*<<< orphan*/  name; } ;
struct TYPE_10__ {TYPE_3__ integer; TYPE_1__ enumerated; } ;
struct snd_ctl_elem_info {int count; TYPE_4__ value; void* type; } ;
struct snd_card {int /*<<< orphan*/  mixername; } ;

/* Variables and functions */
 int ARRAY_SIZE (struct snd_kcontrol_new*) ; 
 scalar_t__ PCSP_CALC_RATE (scalar_t__) ; 
 void* SNDRV_CTL_ELEM_TYPE_BOOLEAN ; 
 void* SNDRV_CTL_ELEM_TYPE_ENUMERATED ; 
 int snd_ctl_add (struct snd_card*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  snd_ctl_new1 (struct snd_kcontrol_new*,struct snd_pcsp*) ; 
 struct snd_pcsp* snd_kcontrol_chip (struct snd_kcontrol*) ; 
 struct snd_kcontrol_new* snd_pcsp_controls_pcm ; 
 struct snd_kcontrol_new* snd_pcsp_controls_spkr ; 
 int /*<<< orphan*/  sprintf (int /*<<< orphan*/ ,char*,unsigned long) ; 
 int /*<<< orphan*/  strcpy (int /*<<< orphan*/ ,char*) ; 

__attribute__((used)) static int pcsp_enable_info(struct snd_kcontrol *kcontrol,
			    struct snd_ctl_elem_info *uinfo)
{
	uinfo->type = SNDRV_CTL_ELEM_TYPE_BOOLEAN;
	uinfo->count = 1;
	uinfo->value.integer.min = 0;
	uinfo->value.integer.max = 1;
	return 0;
}

__attribute__((used)) static int pcsp_enable_get(struct snd_kcontrol *kcontrol,
			   struct snd_ctl_elem_value *ucontrol)
{
	struct snd_pcsp *chip = snd_kcontrol_chip(kcontrol);
	ucontrol->value.integer.value[0] = chip->enable;
	return 0;
}

__attribute__((used)) static int pcsp_enable_put(struct snd_kcontrol *kcontrol,
			   struct snd_ctl_elem_value *ucontrol)
{
	struct snd_pcsp *chip = snd_kcontrol_chip(kcontrol);
	int changed = 0;
	int enab = ucontrol->value.integer.value[0];
	if (enab != chip->enable) {
		chip->enable = enab;
		changed = 1;
	}
	return changed;
}

__attribute__((used)) static int pcsp_treble_info(struct snd_kcontrol *kcontrol,
			    struct snd_ctl_elem_info *uinfo)
{
	struct snd_pcsp *chip = snd_kcontrol_chip(kcontrol);
	uinfo->type = SNDRV_CTL_ELEM_TYPE_ENUMERATED;
	uinfo->count = 1;
	uinfo->value.enumerated.items = chip->max_treble + 1;
	if (uinfo->value.enumerated.item > chip->max_treble)
		uinfo->value.enumerated.item = chip->max_treble;
	sprintf(uinfo->value.enumerated.name, "%lu",
		(unsigned long)PCSP_CALC_RATE(uinfo->value.enumerated.item));
	return 0;
}

__attribute__((used)) static int pcsp_treble_get(struct snd_kcontrol *kcontrol,
			   struct snd_ctl_elem_value *ucontrol)
{
	struct snd_pcsp *chip = snd_kcontrol_chip(kcontrol);
	ucontrol->value.enumerated.item[0] = chip->treble;
	return 0;
}

__attribute__((used)) static int pcsp_treble_put(struct snd_kcontrol *kcontrol,
			   struct snd_ctl_elem_value *ucontrol)
{
	struct snd_pcsp *chip = snd_kcontrol_chip(kcontrol);
	int changed = 0;
	int treble = ucontrol->value.enumerated.item[0];
	if (treble != chip->treble) {
		chip->treble = treble;
#if PCSP_DEBUG
		printk(KERN_INFO "PCSP: rate set to %li\n", PCSP_RATE());
#endif
		changed = 1;
	}
	return changed;
}

__attribute__((used)) static int pcsp_pcspkr_info(struct snd_kcontrol *kcontrol,
			    struct snd_ctl_elem_info *uinfo)
{
	uinfo->type = SNDRV_CTL_ELEM_TYPE_BOOLEAN;
	uinfo->count = 1;
	uinfo->value.integer.min = 0;
	uinfo->value.integer.max = 1;
	return 0;
}

__attribute__((used)) static int pcsp_pcspkr_get(struct snd_kcontrol *kcontrol,
			   struct snd_ctl_elem_value *ucontrol)
{
	struct snd_pcsp *chip = snd_kcontrol_chip(kcontrol);
	ucontrol->value.integer.value[0] = chip->pcspkr;
	return 0;
}

__attribute__((used)) static int pcsp_pcspkr_put(struct snd_kcontrol *kcontrol,
			   struct snd_ctl_elem_value *ucontrol)
{
	struct snd_pcsp *chip = snd_kcontrol_chip(kcontrol);
	int changed = 0;
	int spkr = ucontrol->value.integer.value[0];
	if (spkr != chip->pcspkr) {
		chip->pcspkr = spkr;
		changed = 1;
	}
	return changed;
}

__attribute__((used)) static int snd_pcsp_ctls_add(struct snd_pcsp *chip,
			     struct snd_kcontrol_new *ctls, int num)
{
	int i, err;
	struct snd_card *card = chip->card;
	for (i = 0; i < num; i++) {
		err = snd_ctl_add(card, snd_ctl_new1(ctls + i, chip));
		if (err < 0)
			return err;
	}
	return 0;
}

int snd_pcsp_new_mixer(struct snd_pcsp *chip, int nopcm)
{
	int err;
	struct snd_card *card = chip->card;

	if (!nopcm) {
		err = snd_pcsp_ctls_add(chip, snd_pcsp_controls_pcm,
			ARRAY_SIZE(snd_pcsp_controls_pcm));
		if (err < 0)
			return err;
	}
	err = snd_pcsp_ctls_add(chip, snd_pcsp_controls_spkr,
		ARRAY_SIZE(snd_pcsp_controls_spkr));
	if (err < 0)
		return err;

	strcpy(card->mixername, "PC-Speaker");

	return 0;
}

