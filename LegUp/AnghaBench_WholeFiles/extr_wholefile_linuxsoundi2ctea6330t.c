#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_8__   TYPE_4__ ;
typedef  struct TYPE_7__   TYPE_3__ ;
typedef  struct TYPE_6__   TYPE_2__ ;
typedef  struct TYPE_5__   TYPE_1__ ;

/* Type definitions */
typedef  void* u8 ;
struct tea6330t {unsigned char mleft; unsigned char mright; unsigned char* regs; int max_bass; unsigned char bass; int equalizer; int max_treble; unsigned char treble; int fader; struct snd_i2c_bus* bus; struct snd_i2c_device* device; } ;
struct snd_kcontrol_new {int /*<<< orphan*/  name; } ;
struct snd_kcontrol {int dummy; } ;
struct snd_i2c_device {void (* private_free ) (struct snd_i2c_device*) ;struct tea6330t* private_data; } ;
struct snd_i2c_bus {int dummy; } ;
struct TYPE_7__ {unsigned char* value; } ;
struct TYPE_8__ {TYPE_3__ integer; } ;
struct snd_ctl_elem_value {TYPE_4__ value; } ;
struct TYPE_5__ {int max; scalar_t__ min; } ;
struct TYPE_6__ {TYPE_1__ integer; } ;
struct snd_ctl_elem_info {int count; TYPE_2__ value; void* type; } ;
struct snd_card {int /*<<< orphan*/  mixername; } ;

/* Variables and functions */
 unsigned int ARRAY_SIZE (struct snd_kcontrol_new*) ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 void* SNDRV_CTL_ELEM_TYPE_INTEGER ; 
 int /*<<< orphan*/  TEA6330T_ADDR ; 
 int TEA6330T_EQN ; 
 size_t TEA6330T_SADDR_AUDIO_SWITCH ; 
 size_t TEA6330T_SADDR_BASS ; 
 size_t TEA6330T_SADDR_FADER ; 
 size_t TEA6330T_SADDR_TREBLE ; 
 size_t TEA6330T_SADDR_VOLUME_LEFT ; 
 size_t TEA6330T_SADDR_VOLUME_RIGHT ; 
 int /*<<< orphan*/  kfree (struct tea6330t*) ; 
 struct tea6330t* kzalloc (int,int /*<<< orphan*/ ) ; 
 int snd_component_add (struct snd_card*,char*) ; 
 int snd_ctl_add (struct snd_card*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  snd_ctl_new1 (struct snd_kcontrol_new*,struct tea6330t*) ; 
 int snd_i2c_device_create (struct snd_i2c_bus*,char*,int /*<<< orphan*/ ,struct snd_i2c_device**) ; 
 int /*<<< orphan*/  snd_i2c_device_free (struct snd_i2c_device*) ; 
 int /*<<< orphan*/  snd_i2c_lock (struct snd_i2c_bus*) ; 
 int snd_i2c_probeaddr (struct snd_i2c_bus*,int /*<<< orphan*/ ) ; 
 int snd_i2c_sendbytes (struct snd_i2c_device*,unsigned char*,int) ; 
 int /*<<< orphan*/  snd_i2c_unlock (struct snd_i2c_bus*) ; 
 struct tea6330t* snd_kcontrol_chip (struct snd_kcontrol*) ; 
 struct snd_kcontrol_new* snd_tea6330t_controls ; 
 int /*<<< orphan*/  strcat (int /*<<< orphan*/ ,char*) ; 
 int /*<<< orphan*/  strcmp (int /*<<< orphan*/ ,char*) ; 

int snd_tea6330t_detect(struct snd_i2c_bus *bus, int equalizer)
{
	int res;

	snd_i2c_lock(bus);
	res = snd_i2c_probeaddr(bus, TEA6330T_ADDR);
	snd_i2c_unlock(bus);
	return res;
}

__attribute__((used)) static int snd_tea6330t_info_master_volume(struct snd_kcontrol *kcontrol,
					   struct snd_ctl_elem_info *uinfo)
{
	uinfo->type = SNDRV_CTL_ELEM_TYPE_INTEGER;
	uinfo->count = 2;
	uinfo->value.integer.min = 0;
	uinfo->value.integer.max = 43;
	return 0;
}

__attribute__((used)) static int snd_tea6330t_get_master_volume(struct snd_kcontrol *kcontrol,
					  struct snd_ctl_elem_value *ucontrol)
{
	struct tea6330t *tea = snd_kcontrol_chip(kcontrol);
	
	snd_i2c_lock(tea->bus);
	ucontrol->value.integer.value[0] = tea->mleft - 0x14;
	ucontrol->value.integer.value[1] = tea->mright - 0x14;
	snd_i2c_unlock(tea->bus);
	return 0;
}

__attribute__((used)) static int snd_tea6330t_put_master_volume(struct snd_kcontrol *kcontrol,
					  struct snd_ctl_elem_value *ucontrol)
{
	struct tea6330t *tea = snd_kcontrol_chip(kcontrol);
	int change, count, err;
	unsigned char bytes[3];
	unsigned char val1, val2;
	
	val1 = (ucontrol->value.integer.value[0] % 44) + 0x14;
	val2 = (ucontrol->value.integer.value[1] % 44) + 0x14;
	snd_i2c_lock(tea->bus);
	change = val1 != tea->mleft || val2 != tea->mright;
	tea->mleft = val1;
	tea->mright = val2;
	count = 0;
	if (tea->regs[TEA6330T_SADDR_VOLUME_LEFT] != 0) {
		bytes[count++] = TEA6330T_SADDR_VOLUME_LEFT;
		bytes[count++] = tea->regs[TEA6330T_SADDR_VOLUME_LEFT] = tea->mleft;
	}
	if (tea->regs[TEA6330T_SADDR_VOLUME_RIGHT] != 0) {
		if (count == 0)
			bytes[count++] = TEA6330T_SADDR_VOLUME_RIGHT;
		bytes[count++] = tea->regs[TEA6330T_SADDR_VOLUME_RIGHT] = tea->mright;
	}
	if (count > 0) {
		if ((err = snd_i2c_sendbytes(tea->device, bytes, count)) < 0)
			change = err;
	}
	snd_i2c_unlock(tea->bus);
	return change;
}

__attribute__((used)) static int snd_tea6330t_get_master_switch(struct snd_kcontrol *kcontrol,
					  struct snd_ctl_elem_value *ucontrol)
{
	struct tea6330t *tea = snd_kcontrol_chip(kcontrol);
	
	snd_i2c_lock(tea->bus);
	ucontrol->value.integer.value[0] = tea->regs[TEA6330T_SADDR_VOLUME_LEFT] == 0 ? 0 : 1;
	ucontrol->value.integer.value[1] = tea->regs[TEA6330T_SADDR_VOLUME_RIGHT] == 0 ? 0 : 1;
	snd_i2c_unlock(tea->bus);
	return 0;
}

__attribute__((used)) static int snd_tea6330t_put_master_switch(struct snd_kcontrol *kcontrol,
					  struct snd_ctl_elem_value *ucontrol)
{
	struct tea6330t *tea = snd_kcontrol_chip(kcontrol);
	int change, err;
	unsigned char bytes[3];
	unsigned char oval1, oval2, val1, val2;
	
	val1 = ucontrol->value.integer.value[0] & 1;
	val2 = ucontrol->value.integer.value[1] & 1;
	snd_i2c_lock(tea->bus);
	oval1 = tea->regs[TEA6330T_SADDR_VOLUME_LEFT] == 0 ? 0 : 1;
	oval2 = tea->regs[TEA6330T_SADDR_VOLUME_RIGHT] == 0 ? 0 : 1;
	change = val1 != oval1 || val2 != oval2;
	tea->regs[TEA6330T_SADDR_VOLUME_LEFT] = val1 ? tea->mleft : 0;
	tea->regs[TEA6330T_SADDR_VOLUME_RIGHT] = val2 ? tea->mright : 0;
	bytes[0] = TEA6330T_SADDR_VOLUME_LEFT;
	bytes[1] = tea->regs[TEA6330T_SADDR_VOLUME_LEFT];
	bytes[2] = tea->regs[TEA6330T_SADDR_VOLUME_RIGHT];
	if ((err = snd_i2c_sendbytes(tea->device, bytes, 3)) < 0)
		change = err;
	snd_i2c_unlock(tea->bus);
	return change;
}

__attribute__((used)) static int snd_tea6330t_info_bass(struct snd_kcontrol *kcontrol,
				  struct snd_ctl_elem_info *uinfo)
{
	struct tea6330t *tea = snd_kcontrol_chip(kcontrol);

	uinfo->type = SNDRV_CTL_ELEM_TYPE_INTEGER;
	uinfo->count = 1;
	uinfo->value.integer.min = 0;
	uinfo->value.integer.max = tea->max_bass;
	return 0;
}

__attribute__((used)) static int snd_tea6330t_get_bass(struct snd_kcontrol *kcontrol,
				 struct snd_ctl_elem_value *ucontrol)
{
	struct tea6330t *tea = snd_kcontrol_chip(kcontrol);
	
	ucontrol->value.integer.value[0] = tea->bass;
	return 0;
}

__attribute__((used)) static int snd_tea6330t_put_bass(struct snd_kcontrol *kcontrol,
				 struct snd_ctl_elem_value *ucontrol)
{
	struct tea6330t *tea = snd_kcontrol_chip(kcontrol);
	int change, err;
	unsigned char bytes[2];
	unsigned char val1;
	
	val1 = ucontrol->value.integer.value[0] % (tea->max_bass + 1);
	snd_i2c_lock(tea->bus);
	tea->bass = val1;
	val1 += tea->equalizer ? 7 : 3;
	change = tea->regs[TEA6330T_SADDR_BASS] != val1;
	bytes[0] = TEA6330T_SADDR_BASS;
	bytes[1] = tea->regs[TEA6330T_SADDR_BASS] = val1;
	if ((err = snd_i2c_sendbytes(tea->device, bytes, 2)) < 0)
		change = err;
	snd_i2c_unlock(tea->bus);
	return change;
}

__attribute__((used)) static int snd_tea6330t_info_treble(struct snd_kcontrol *kcontrol,
				    struct snd_ctl_elem_info *uinfo)
{
	struct tea6330t *tea = snd_kcontrol_chip(kcontrol);

	uinfo->type = SNDRV_CTL_ELEM_TYPE_INTEGER;
	uinfo->count = 1;
	uinfo->value.integer.min = 0;
	uinfo->value.integer.max = tea->max_treble;
	return 0;
}

__attribute__((used)) static int snd_tea6330t_get_treble(struct snd_kcontrol *kcontrol,
				   struct snd_ctl_elem_value *ucontrol)
{
	struct tea6330t *tea = snd_kcontrol_chip(kcontrol);
	
	ucontrol->value.integer.value[0] = tea->treble;
	return 0;
}

__attribute__((used)) static int snd_tea6330t_put_treble(struct snd_kcontrol *kcontrol,
				   struct snd_ctl_elem_value *ucontrol)
{
	struct tea6330t *tea = snd_kcontrol_chip(kcontrol);
	int change, err;
	unsigned char bytes[2];
	unsigned char val1;
	
	val1 = ucontrol->value.integer.value[0] % (tea->max_treble + 1);
	snd_i2c_lock(tea->bus);
	tea->treble = val1;
	val1 += 3;
	change = tea->regs[TEA6330T_SADDR_TREBLE] != val1;
	bytes[0] = TEA6330T_SADDR_TREBLE;
	bytes[1] = tea->regs[TEA6330T_SADDR_TREBLE] = val1;
	if ((err = snd_i2c_sendbytes(tea->device, bytes, 2)) < 0)
		change = err;
	snd_i2c_unlock(tea->bus);
	return change;
}

__attribute__((used)) static void snd_tea6330_free(struct snd_i2c_device *device)
{
	kfree(device->private_data);
}

int snd_tea6330t_update_mixer(struct snd_card *card,
			      struct snd_i2c_bus *bus,
			      int equalizer, int fader)
{
	struct snd_i2c_device *device;
	struct tea6330t *tea;
	struct snd_kcontrol_new *knew;
	unsigned int idx;
	int err = -ENOMEM;
	u8 default_treble, default_bass;
	unsigned char bytes[7];

	tea = kzalloc(sizeof(*tea), GFP_KERNEL);
	if (tea == NULL)
		return -ENOMEM;
	if ((err = snd_i2c_device_create(bus, "TEA6330T", TEA6330T_ADDR, &device)) < 0) {
		kfree(tea);
		return err;
	}
	tea->device = device;
	tea->bus = bus;
	tea->equalizer = equalizer;
	tea->fader = fader;
	device->private_data = tea;
	device->private_free = snd_tea6330_free;

	snd_i2c_lock(bus);

	/* turn fader off and handle equalizer */
	tea->regs[TEA6330T_SADDR_FADER] = 0x3f;
	tea->regs[TEA6330T_SADDR_AUDIO_SWITCH] = equalizer ? 0 : TEA6330T_EQN;
	/* initialize mixer */
	if (!tea->equalizer) {
		tea->max_bass = 9;
		tea->max_treble = 8;
		default_bass = 3 + 4;
		tea->bass = 4;
		default_treble = 3 + 4;
		tea->treble = 4;
	} else {
		tea->max_bass = 5;
		tea->max_treble = 0;
		default_bass = 7 + 4;
		tea->bass = 4;
		default_treble = 3;
		tea->treble = 0;
	}
	tea->mleft = tea->mright = 0x14;
	tea->regs[TEA6330T_SADDR_BASS] = default_bass;
	tea->regs[TEA6330T_SADDR_TREBLE] = default_treble;

	/* compose I2C message and put the hardware to initial state */
	bytes[0] = TEA6330T_SADDR_VOLUME_LEFT;
	for (idx = 0; idx < 6; idx++)
		bytes[idx+1] = tea->regs[idx];
	if ((err = snd_i2c_sendbytes(device, bytes, 7)) < 0)
		goto __error;

	strcat(card->mixername, ",TEA6330T");
	if ((err = snd_component_add(card, "TEA6330T")) < 0)
		goto __error;

	for (idx = 0; idx < ARRAY_SIZE(snd_tea6330t_controls); idx++) {
		knew = &snd_tea6330t_controls[idx];
		if (tea->treble == 0 && !strcmp(knew->name, "Tone Control - Treble"))
			continue;
		if ((err = snd_ctl_add(card, snd_ctl_new1(knew, tea))) < 0)
			goto __error;
	}

	snd_i2c_unlock(bus);
	return 0;
	
      __error:
      	snd_i2c_unlock(bus);
      	snd_i2c_device_free(device);
      	return err;
}

