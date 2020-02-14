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
struct snd_minor {int type; int card; int device; struct snd_card* card_ptr; void* private_data; struct file_operations const* f_ops; } ;
struct snd_card {int number; int /*<<< orphan*/  card_dev; } ;
struct file_operations {int dummy; } ;
struct device {int dummy; } ;

/* Variables and functions */
 unsigned int ARRAY_SIZE (struct snd_minor**) ; 
 int EBUSY ; 
 int EINVAL ; 
 int ENOENT ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int SNDRV_MINOR_OSS (int,int) ; 
 int SNDRV_MINOR_OSS_AUDIO ; 
 int SNDRV_MINOR_OSS_CARD (int) ; 
 int SNDRV_MINOR_OSS_DEVICE (int) ; 
 scalar_t__ SNDRV_MINOR_OSS_DEVICES ; 
 int SNDRV_MINOR_OSS_DMFM ; 
 int SNDRV_MINOR_OSS_DMMIDI ; 
 int SNDRV_MINOR_OSS_DMMIDI1 ; 
#define  SNDRV_MINOR_OSS_MIDI 137 
#define  SNDRV_MINOR_OSS_MIDI1 136 
 int SNDRV_MINOR_OSS_MIXER ; 
 int SNDRV_MINOR_OSS_MIXER1 ; 
 int SNDRV_MINOR_OSS_MUSIC ; 
#define  SNDRV_MINOR_OSS_PCM 135 
 int SNDRV_MINOR_OSS_PCM1 ; 
 int SNDRV_MINOR_OSS_SEQUENCER ; 
 int SNDRV_MINOR_OSS_SNDSTAT ; 
#define  SNDRV_OSS_DEVICE_TYPE_DMFM 134 
#define  SNDRV_OSS_DEVICE_TYPE_MIDI 133 
#define  SNDRV_OSS_DEVICE_TYPE_MIXER 132 
#define  SNDRV_OSS_DEVICE_TYPE_MUSIC 131 
#define  SNDRV_OSS_DEVICE_TYPE_PCM 130 
#define  SNDRV_OSS_DEVICE_TYPE_SEQUENCER 129 
#define  SNDRV_OSS_DEVICE_TYPE_SNDSTAT 128 
 int SNDRV_OSS_MINORS ; 
 int /*<<< orphan*/  get_device (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  kfree (struct snd_minor*) ; 
 struct snd_minor* kmalloc (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 int register_sound_special_device (struct file_operations const*,int,struct device*) ; 
 int /*<<< orphan*/  snd_BUG_ON (int) ; 
 struct device* snd_card_get_device_link (struct snd_card*) ; 
 struct snd_minor** snd_oss_minors ; 
 int /*<<< orphan*/  sound_oss_mutex ; 
 int /*<<< orphan*/  unregister_sound_special (int) ; 

void *snd_lookup_oss_minor_data(unsigned int minor, int type)
{
	struct snd_minor *mreg;
	void *private_data;

	if (minor >= ARRAY_SIZE(snd_oss_minors))
		return NULL;
	mutex_lock(&sound_oss_mutex);
	mreg = snd_oss_minors[minor];
	if (mreg && mreg->type == type) {
		private_data = mreg->private_data;
		if (private_data && mreg->card_ptr)
			get_device(&mreg->card_ptr->card_dev);
	} else
		private_data = NULL;
	mutex_unlock(&sound_oss_mutex);
	return private_data;
}

__attribute__((used)) static int snd_oss_kernel_minor(int type, struct snd_card *card, int dev)
{
	int minor;

	switch (type) {
	case SNDRV_OSS_DEVICE_TYPE_MIXER:
		if (snd_BUG_ON(!card || dev < 0 || dev > 1))
			return -EINVAL;
		minor = SNDRV_MINOR_OSS(card->number, (dev ? SNDRV_MINOR_OSS_MIXER1 : SNDRV_MINOR_OSS_MIXER));
		break;
	case SNDRV_OSS_DEVICE_TYPE_SEQUENCER:
		minor = SNDRV_MINOR_OSS_SEQUENCER;
		break;
	case SNDRV_OSS_DEVICE_TYPE_MUSIC:
		minor = SNDRV_MINOR_OSS_MUSIC;
		break;
	case SNDRV_OSS_DEVICE_TYPE_PCM:
		if (snd_BUG_ON(!card || dev < 0 || dev > 1))
			return -EINVAL;
		minor = SNDRV_MINOR_OSS(card->number, (dev ? SNDRV_MINOR_OSS_PCM1 : SNDRV_MINOR_OSS_PCM));
		break;
	case SNDRV_OSS_DEVICE_TYPE_MIDI:
		if (snd_BUG_ON(!card || dev < 0 || dev > 1))
			return -EINVAL;
		minor = SNDRV_MINOR_OSS(card->number, (dev ? SNDRV_MINOR_OSS_MIDI1 : SNDRV_MINOR_OSS_MIDI));
		break;
	case SNDRV_OSS_DEVICE_TYPE_DMFM:
		minor = SNDRV_MINOR_OSS(card->number, SNDRV_MINOR_OSS_DMFM);
		break;
	case SNDRV_OSS_DEVICE_TYPE_SNDSTAT:
		minor = SNDRV_MINOR_OSS_SNDSTAT;
		break;
	default:
		return -EINVAL;
	}
	if (minor < 0 || minor >= SNDRV_OSS_MINORS)
		return -EINVAL;
	return minor;
}

int snd_register_oss_device(int type, struct snd_card *card, int dev,
			    const struct file_operations *f_ops, void *private_data)
{
	int minor = snd_oss_kernel_minor(type, card, dev);
	int minor_unit;
	struct snd_minor *preg;
	int cidx = SNDRV_MINOR_OSS_CARD(minor);
	int track2 = -1;
	int register1 = -1, register2 = -1;
	struct device *carddev = snd_card_get_device_link(card);

	if (card && card->number >= SNDRV_MINOR_OSS_DEVICES)
		return 0; /* ignore silently */
	if (minor < 0)
		return minor;
	preg = kmalloc(sizeof(struct snd_minor), GFP_KERNEL);
	if (preg == NULL)
		return -ENOMEM;
	preg->type = type;
	preg->card = card ? card->number : -1;
	preg->device = dev;
	preg->f_ops = f_ops;
	preg->private_data = private_data;
	preg->card_ptr = card;
	mutex_lock(&sound_oss_mutex);
	snd_oss_minors[minor] = preg;
	minor_unit = SNDRV_MINOR_OSS_DEVICE(minor);
	switch (minor_unit) {
	case SNDRV_MINOR_OSS_PCM:
		track2 = SNDRV_MINOR_OSS(cidx, SNDRV_MINOR_OSS_AUDIO);
		break;
	case SNDRV_MINOR_OSS_MIDI:
		track2 = SNDRV_MINOR_OSS(cidx, SNDRV_MINOR_OSS_DMMIDI);
		break;
	case SNDRV_MINOR_OSS_MIDI1:
		track2 = SNDRV_MINOR_OSS(cidx, SNDRV_MINOR_OSS_DMMIDI1);
		break;
	}
	register1 = register_sound_special_device(f_ops, minor, carddev);
	if (register1 != minor)
		goto __end;
	if (track2 >= 0) {
		register2 = register_sound_special_device(f_ops, track2,
							  carddev);
		if (register2 != track2)
			goto __end;
		snd_oss_minors[track2] = preg;
	}
	mutex_unlock(&sound_oss_mutex);
	return 0;

      __end:
      	if (register2 >= 0)
      		unregister_sound_special(register2);
      	if (register1 >= 0)
      		unregister_sound_special(register1);
	snd_oss_minors[minor] = NULL;
	mutex_unlock(&sound_oss_mutex);
	kfree(preg);
      	return -EBUSY;
}

int snd_unregister_oss_device(int type, struct snd_card *card, int dev)
{
	int minor = snd_oss_kernel_minor(type, card, dev);
	int cidx = SNDRV_MINOR_OSS_CARD(minor);
	int track2 = -1;
	struct snd_minor *mptr;

	if (card && card->number >= SNDRV_MINOR_OSS_DEVICES)
		return 0;
	if (minor < 0)
		return minor;
	mutex_lock(&sound_oss_mutex);
	mptr = snd_oss_minors[minor];
	if (mptr == NULL) {
		mutex_unlock(&sound_oss_mutex);
		return -ENOENT;
	}
	unregister_sound_special(minor);
	switch (SNDRV_MINOR_OSS_DEVICE(minor)) {
	case SNDRV_MINOR_OSS_PCM:
		track2 = SNDRV_MINOR_OSS(cidx, SNDRV_MINOR_OSS_AUDIO);
		break;
	case SNDRV_MINOR_OSS_MIDI:
		track2 = SNDRV_MINOR_OSS(cidx, SNDRV_MINOR_OSS_DMMIDI);
		break;
	case SNDRV_MINOR_OSS_MIDI1:
		track2 = SNDRV_MINOR_OSS(cidx, SNDRV_MINOR_OSS_DMMIDI1);
		break;
	}
	if (track2 >= 0) {
		unregister_sound_special(track2);
		snd_oss_minors[track2] = NULL;
	}
	snd_oss_minors[minor] = NULL;
	mutex_unlock(&sound_oss_mutex);
	kfree(mptr);
	return 0;
}

