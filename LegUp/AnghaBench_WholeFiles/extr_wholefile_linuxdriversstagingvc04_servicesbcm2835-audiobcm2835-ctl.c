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
struct snd_kcontrol_new {int dummy; } ;
struct snd_kcontrol {scalar_t__ private_value; } ;
struct TYPE_7__ {int* status; } ;
struct TYPE_10__ {int* value; } ;
struct TYPE_11__ {TYPE_1__ iec958; TYPE_4__ integer; } ;
struct snd_ctl_elem_value {TYPE_5__ value; } ;
struct TYPE_8__ {int max; scalar_t__ min; } ;
struct TYPE_9__ {TYPE_2__ integer; } ;
struct snd_ctl_elem_info {int count; void* type; TYPE_3__ value; } ;
struct bcm2835_chip {int volume; int mute; int dest; int spdif_status; TYPE_6__* card; int /*<<< orphan*/  audio_mutex; scalar_t__* alsa_stream; } ;
struct TYPE_12__ {int /*<<< orphan*/  mixername; int /*<<< orphan*/  dev; } ;

/* Variables and functions */
 size_t ARRAY_SIZE (struct snd_kcontrol_new*) ; 
 int AUDIO_DEST_MAX ; 
 int CTRL_VOL_MAX ; 
 scalar_t__ CTRL_VOL_MIN ; 
 int EINVAL ; 
 int IEC958_AES0_NONAUDIO ; 
 int MAX_SUBSTREAMS ; 
 scalar_t__ PCM_PLAYBACK_DEVICE ; 
 scalar_t__ PCM_PLAYBACK_MUTE ; 
 scalar_t__ PCM_PLAYBACK_VOLUME ; 
 void* SNDRV_CTL_ELEM_TYPE_BOOLEAN ; 
 void* SNDRV_CTL_ELEM_TYPE_IEC958 ; 
 void* SNDRV_CTL_ELEM_TYPE_INTEGER ; 
 int bcm2835_audio_set_ctls (scalar_t__) ; 
 int /*<<< orphan*/  dev_err (int /*<<< orphan*/ ,char*) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 struct snd_kcontrol_new* snd_bcm2835_ctl ; 
 struct snd_kcontrol_new* snd_bcm2835_hdmi ; 
 struct snd_kcontrol_new* snd_bcm2835_headphones_ctl ; 
 struct snd_kcontrol_new* snd_bcm2835_spdif ; 
 int snd_ctl_add (TYPE_6__*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  snd_ctl_new1 (struct snd_kcontrol_new const*,struct bcm2835_chip*) ; 
 struct bcm2835_chip* snd_kcontrol_chip (struct snd_kcontrol*) ; 
 int /*<<< orphan*/  strcpy (int /*<<< orphan*/ ,char*) ; 

__attribute__((used)) static int bcm2835_audio_set_chip_ctls(struct bcm2835_chip *chip)
{
	int i, err = 0;

	/* change ctls for all substreams */
	for (i = 0; i < MAX_SUBSTREAMS; i++) {
		if (chip->alsa_stream[i]) {
			err = bcm2835_audio_set_ctls(chip->alsa_stream[i]);
			if (err < 0)
				break;
		}
	}
	return err;
}

__attribute__((used)) static int snd_bcm2835_ctl_info(struct snd_kcontrol *kcontrol,
				struct snd_ctl_elem_info *uinfo)
{
	if (kcontrol->private_value == PCM_PLAYBACK_VOLUME) {
		uinfo->type = SNDRV_CTL_ELEM_TYPE_INTEGER;
		uinfo->count = 1;
		uinfo->value.integer.min = CTRL_VOL_MIN;
		uinfo->value.integer.max = CTRL_VOL_MAX; /* 2303 */
	} else if (kcontrol->private_value == PCM_PLAYBACK_MUTE) {
		uinfo->type = SNDRV_CTL_ELEM_TYPE_BOOLEAN;
		uinfo->count = 1;
		uinfo->value.integer.min = 0;
		uinfo->value.integer.max = 1;
	} else if (kcontrol->private_value == PCM_PLAYBACK_DEVICE) {
		uinfo->type = SNDRV_CTL_ELEM_TYPE_INTEGER;
		uinfo->count = 1;
		uinfo->value.integer.min = 0;
		uinfo->value.integer.max = AUDIO_DEST_MAX - 1;
	}
	return 0;
}

__attribute__((used)) static int snd_bcm2835_ctl_get(struct snd_kcontrol *kcontrol,
			       struct snd_ctl_elem_value *ucontrol)
{
	struct bcm2835_chip *chip = snd_kcontrol_chip(kcontrol);

	mutex_lock(&chip->audio_mutex);

	if (kcontrol->private_value == PCM_PLAYBACK_VOLUME)
		ucontrol->value.integer.value[0] = chip->volume;
	else if (kcontrol->private_value == PCM_PLAYBACK_MUTE)
		ucontrol->value.integer.value[0] = chip->mute;
	else if (kcontrol->private_value == PCM_PLAYBACK_DEVICE)
		ucontrol->value.integer.value[0] = chip->dest;

	mutex_unlock(&chip->audio_mutex);
	return 0;
}

__attribute__((used)) static int snd_bcm2835_ctl_put(struct snd_kcontrol *kcontrol,
				struct snd_ctl_elem_value *ucontrol)
{
	struct bcm2835_chip *chip = snd_kcontrol_chip(kcontrol);
	int val, *valp;
	int changed = 0;

	if (kcontrol->private_value == PCM_PLAYBACK_VOLUME)
		valp = &chip->volume;
	else if (kcontrol->private_value == PCM_PLAYBACK_MUTE)
		valp = &chip->mute;
	else if (kcontrol->private_value == PCM_PLAYBACK_DEVICE)
		valp = &chip->dest;
	else
		return -EINVAL;

	val = ucontrol->value.integer.value[0];
	mutex_lock(&chip->audio_mutex);
	if (val != *valp) {
		*valp = val;
		changed = 1;
		if (bcm2835_audio_set_chip_ctls(chip))
			dev_err(chip->card->dev, "Failed to set ALSA controls..\n");
	}
	mutex_unlock(&chip->audio_mutex);
	return changed;
}

__attribute__((used)) static int snd_bcm2835_spdif_default_info(struct snd_kcontrol *kcontrol,
	struct snd_ctl_elem_info *uinfo)
{
	uinfo->type = SNDRV_CTL_ELEM_TYPE_IEC958;
	uinfo->count = 1;
	return 0;
}

__attribute__((used)) static int snd_bcm2835_spdif_default_get(struct snd_kcontrol *kcontrol,
	struct snd_ctl_elem_value *ucontrol)
{
	struct bcm2835_chip *chip = snd_kcontrol_chip(kcontrol);
	int i;

	mutex_lock(&chip->audio_mutex);

	for (i = 0; i < 4; i++)
		ucontrol->value.iec958.status[i] =
			(chip->spdif_status >> (i * 8)) & 0xff;

	mutex_unlock(&chip->audio_mutex);
	return 0;
}

__attribute__((used)) static int snd_bcm2835_spdif_default_put(struct snd_kcontrol *kcontrol,
	struct snd_ctl_elem_value *ucontrol)
{
	struct bcm2835_chip *chip = snd_kcontrol_chip(kcontrol);
	unsigned int val = 0;
	int i, change;

	mutex_lock(&chip->audio_mutex);

	for (i = 0; i < 4; i++)
		val |= (unsigned int)ucontrol->value.iec958.status[i] << (i * 8);

	change = val != chip->spdif_status;
	chip->spdif_status = val;

	mutex_unlock(&chip->audio_mutex);
	return change;
}

__attribute__((used)) static int snd_bcm2835_spdif_mask_info(struct snd_kcontrol *kcontrol,
	struct snd_ctl_elem_info *uinfo)
{
	uinfo->type = SNDRV_CTL_ELEM_TYPE_IEC958;
	uinfo->count = 1;
	return 0;
}

__attribute__((used)) static int snd_bcm2835_spdif_mask_get(struct snd_kcontrol *kcontrol,
	struct snd_ctl_elem_value *ucontrol)
{
	/*
	 * bcm2835 supports only consumer mode and sets all other format flags
	 * automatically. So the only thing left is signalling non-audio content
	 */
	ucontrol->value.iec958.status[0] = IEC958_AES0_NONAUDIO;
	return 0;
}

__attribute__((used)) static int create_ctls(struct bcm2835_chip *chip, size_t size,
		       const struct snd_kcontrol_new *kctls)
{
	int i, err;

	for (i = 0; i < size; i++) {
		err = snd_ctl_add(chip->card, snd_ctl_new1(&kctls[i], chip));
		if (err < 0)
			return err;
	}
	return 0;
}

int snd_bcm2835_new_ctl(struct bcm2835_chip *chip)
{
	int err;

	strcpy(chip->card->mixername, "Broadcom Mixer");
	err = create_ctls(chip, ARRAY_SIZE(snd_bcm2835_ctl), snd_bcm2835_ctl);
	if (err < 0)
		return err;
	return create_ctls(chip, ARRAY_SIZE(snd_bcm2835_spdif),
			   snd_bcm2835_spdif);
}

int snd_bcm2835_new_headphones_ctl(struct bcm2835_chip *chip)
{
	strcpy(chip->card->mixername, "Broadcom Mixer");
	return create_ctls(chip, ARRAY_SIZE(snd_bcm2835_headphones_ctl),
			   snd_bcm2835_headphones_ctl);
}

int snd_bcm2835_new_hdmi_ctl(struct bcm2835_chip *chip)
{
	strcpy(chip->card->mixername, "Broadcom Mixer");
	return create_ctls(chip, ARRAY_SIZE(snd_bcm2835_hdmi),
			   snd_bcm2835_hdmi);
}

