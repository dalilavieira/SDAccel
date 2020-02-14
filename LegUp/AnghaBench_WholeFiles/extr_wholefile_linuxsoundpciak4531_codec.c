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
struct snd_kcontrol {int private_value; } ;
struct snd_info_entry {struct snd_ak4531* private_data; } ;
struct snd_info_buffer {int dummy; } ;
struct snd_device_ops {int (* dev_free ) (struct snd_device*) ;} ;
struct snd_device {struct snd_ak4531* device_data; } ;
struct TYPE_7__ {int* value; } ;
struct TYPE_8__ {TYPE_3__ integer; } ;
struct snd_ctl_elem_value {TYPE_4__ value; } ;
struct TYPE_5__ {int max; scalar_t__ min; } ;
struct TYPE_6__ {TYPE_1__ integer; } ;
struct snd_ctl_elem_info {int count; TYPE_2__ value; void* type; } ;
struct snd_card {int /*<<< orphan*/  mixername; } ;
struct snd_ak4531 {int* regs; int /*<<< orphan*/  (* write ) (struct snd_ak4531*,unsigned int,int) ;int /*<<< orphan*/  reg_mutex; int /*<<< orphan*/  (* private_free ) (struct snd_ak4531*) ;} ;

/* Variables and functions */
 size_t AK4531_AD_IN ; 
 unsigned int AK4531_CLOCK ; 
 size_t AK4531_MIC_GAIN ; 
 unsigned int AK4531_RESET ; 
 unsigned int ARRAY_SIZE (int /*<<< orphan*/ *) ; 
 int EINVAL ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 void* SNDRV_CTL_ELEM_TYPE_BOOLEAN ; 
 void* SNDRV_CTL_ELEM_TYPE_INTEGER ; 
 int /*<<< orphan*/  SNDRV_DEV_CODEC ; 
 int /*<<< orphan*/  kfree (struct snd_ak4531*) ; 
 struct snd_ak4531* kzalloc (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mutex_init (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 scalar_t__ snd_BUG_ON (int) ; 
 int /*<<< orphan*/ * snd_ak4531_controls ; 
 int* snd_ak4531_initial_map ; 
static  void snd_ak4531_proc_init (struct snd_card*,struct snd_ak4531*) ; 
 int /*<<< orphan*/  snd_card_proc_new (struct snd_card*,char*,struct snd_info_entry**) ; 
 int snd_component_add (struct snd_card*,char*) ; 
 int snd_ctl_add (struct snd_card*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  snd_ctl_new1 (int /*<<< orphan*/ *,struct snd_ak4531*) ; 
 int snd_device_new (struct snd_card*,int /*<<< orphan*/ ,struct snd_ak4531*,struct snd_device_ops*) ; 
 int /*<<< orphan*/  snd_info_set_text_ops (struct snd_info_entry*,struct snd_ak4531*,void (*) (struct snd_info_entry*,struct snd_info_buffer*)) ; 
 int /*<<< orphan*/  snd_iprintf (struct snd_info_buffer*,char*,...) ; 
 struct snd_ak4531* snd_kcontrol_chip (struct snd_kcontrol*) ; 
 int /*<<< orphan*/  strcpy (int /*<<< orphan*/ ,char*) ; 
 int /*<<< orphan*/  stub1 (struct snd_ak4531*,int,int) ; 
 int /*<<< orphan*/  stub10 (struct snd_ak4531*,unsigned int,int) ; 
 int /*<<< orphan*/  stub2 (struct snd_ak4531*,int,int) ; 
 int /*<<< orphan*/  stub3 (struct snd_ak4531*,int,int) ; 
 int /*<<< orphan*/  stub4 (struct snd_ak4531*,int,int) ; 
 int /*<<< orphan*/  stub5 (struct snd_ak4531*,int,int) ; 
 int /*<<< orphan*/  stub6 (struct snd_ak4531*,int,int) ; 
 int /*<<< orphan*/  stub7 (struct snd_ak4531*) ; 
 int /*<<< orphan*/  stub8 (struct snd_ak4531*,unsigned int,int) ; 
 int /*<<< orphan*/  stub9 (struct snd_ak4531*,unsigned int,int) ; 
 int /*<<< orphan*/  udelay (int) ; 

__attribute__((used)) static int snd_ak4531_info_single(struct snd_kcontrol *kcontrol, struct snd_ctl_elem_info *uinfo)
{
	int mask = (kcontrol->private_value >> 24) & 0xff;

	uinfo->type = mask == 1 ? SNDRV_CTL_ELEM_TYPE_BOOLEAN : SNDRV_CTL_ELEM_TYPE_INTEGER;
	uinfo->count = 1;
	uinfo->value.integer.min = 0;
	uinfo->value.integer.max = mask;
	return 0;
}

__attribute__((used)) static int snd_ak4531_get_single(struct snd_kcontrol *kcontrol, struct snd_ctl_elem_value *ucontrol)
{
	struct snd_ak4531 *ak4531 = snd_kcontrol_chip(kcontrol);
	int reg = kcontrol->private_value & 0xff;
	int shift = (kcontrol->private_value >> 16) & 0x07;
	int mask = (kcontrol->private_value >> 24) & 0xff;
	int invert = (kcontrol->private_value >> 22) & 1;
	int val;

	mutex_lock(&ak4531->reg_mutex);
	val = (ak4531->regs[reg] >> shift) & mask;
	mutex_unlock(&ak4531->reg_mutex);
	if (invert) {
		val = mask - val;
	}
	ucontrol->value.integer.value[0] = val;
	return 0;
}

__attribute__((used)) static int snd_ak4531_put_single(struct snd_kcontrol *kcontrol, struct snd_ctl_elem_value *ucontrol)
{
	struct snd_ak4531 *ak4531 = snd_kcontrol_chip(kcontrol);
	int reg = kcontrol->private_value & 0xff;
	int shift = (kcontrol->private_value >> 16) & 0x07;
	int mask = (kcontrol->private_value >> 24) & 0xff;
	int invert = (kcontrol->private_value >> 22) & 1;
	int change;
	int val;

	val = ucontrol->value.integer.value[0] & mask;
	if (invert) {
		val = mask - val;
	}
	val <<= shift;
	mutex_lock(&ak4531->reg_mutex);
	val = (ak4531->regs[reg] & ~(mask << shift)) | val;
	change = val != ak4531->regs[reg];
	ak4531->write(ak4531, reg, ak4531->regs[reg] = val);
	mutex_unlock(&ak4531->reg_mutex);
	return change;
}

__attribute__((used)) static int snd_ak4531_info_double(struct snd_kcontrol *kcontrol, struct snd_ctl_elem_info *uinfo)
{
	int mask = (kcontrol->private_value >> 24) & 0xff;

	uinfo->type = mask == 1 ? SNDRV_CTL_ELEM_TYPE_BOOLEAN : SNDRV_CTL_ELEM_TYPE_INTEGER;
	uinfo->count = 2;
	uinfo->value.integer.min = 0;
	uinfo->value.integer.max = mask;
	return 0;
}

__attribute__((used)) static int snd_ak4531_get_double(struct snd_kcontrol *kcontrol, struct snd_ctl_elem_value *ucontrol)
{
	struct snd_ak4531 *ak4531 = snd_kcontrol_chip(kcontrol);
	int left_reg = kcontrol->private_value & 0xff;
	int right_reg = (kcontrol->private_value >> 8) & 0xff;
	int left_shift = (kcontrol->private_value >> 16) & 0x07;
	int right_shift = (kcontrol->private_value >> 19) & 0x07;
	int mask = (kcontrol->private_value >> 24) & 0xff;
	int invert = (kcontrol->private_value >> 22) & 1;
	int left, right;

	mutex_lock(&ak4531->reg_mutex);
	left = (ak4531->regs[left_reg] >> left_shift) & mask;
	right = (ak4531->regs[right_reg] >> right_shift) & mask;
	mutex_unlock(&ak4531->reg_mutex);
	if (invert) {
		left = mask - left;
		right = mask - right;
	}
	ucontrol->value.integer.value[0] = left;
	ucontrol->value.integer.value[1] = right;
	return 0;
}

__attribute__((used)) static int snd_ak4531_put_double(struct snd_kcontrol *kcontrol, struct snd_ctl_elem_value *ucontrol)
{
	struct snd_ak4531 *ak4531 = snd_kcontrol_chip(kcontrol);
	int left_reg = kcontrol->private_value & 0xff;
	int right_reg = (kcontrol->private_value >> 8) & 0xff;
	int left_shift = (kcontrol->private_value >> 16) & 0x07;
	int right_shift = (kcontrol->private_value >> 19) & 0x07;
	int mask = (kcontrol->private_value >> 24) & 0xff;
	int invert = (kcontrol->private_value >> 22) & 1;
	int change;
	int left, right;

	left = ucontrol->value.integer.value[0] & mask;
	right = ucontrol->value.integer.value[1] & mask;
	if (invert) {
		left = mask - left;
		right = mask - right;
	}
	left <<= left_shift;
	right <<= right_shift;
	mutex_lock(&ak4531->reg_mutex);
	if (left_reg == right_reg) {
		left = (ak4531->regs[left_reg] & ~((mask << left_shift) | (mask << right_shift))) | left | right;
		change = left != ak4531->regs[left_reg];
		ak4531->write(ak4531, left_reg, ak4531->regs[left_reg] = left);
	} else {
		left = (ak4531->regs[left_reg] & ~(mask << left_shift)) | left;
		right = (ak4531->regs[right_reg] & ~(mask << right_shift)) | right;
		change = left != ak4531->regs[left_reg] || right != ak4531->regs[right_reg];
		ak4531->write(ak4531, left_reg, ak4531->regs[left_reg] = left);
		ak4531->write(ak4531, right_reg, ak4531->regs[right_reg] = right);
	}
	mutex_unlock(&ak4531->reg_mutex);
	return change;
}

__attribute__((used)) static int snd_ak4531_info_input_sw(struct snd_kcontrol *kcontrol, struct snd_ctl_elem_info *uinfo)
{
	uinfo->type = SNDRV_CTL_ELEM_TYPE_BOOLEAN;
	uinfo->count = 4;
	uinfo->value.integer.min = 0;
	uinfo->value.integer.max = 1;
	return 0;
}

__attribute__((used)) static int snd_ak4531_get_input_sw(struct snd_kcontrol *kcontrol, struct snd_ctl_elem_value *ucontrol)
{
	struct snd_ak4531 *ak4531 = snd_kcontrol_chip(kcontrol);
	int reg1 = kcontrol->private_value & 0xff;
	int reg2 = (kcontrol->private_value >> 8) & 0xff;
	int left_shift = (kcontrol->private_value >> 16) & 0x0f;
	int right_shift = (kcontrol->private_value >> 24) & 0x0f;

	mutex_lock(&ak4531->reg_mutex);
	ucontrol->value.integer.value[0] = (ak4531->regs[reg1] >> left_shift) & 1;
	ucontrol->value.integer.value[1] = (ak4531->regs[reg2] >> left_shift) & 1;
	ucontrol->value.integer.value[2] = (ak4531->regs[reg1] >> right_shift) & 1;
	ucontrol->value.integer.value[3] = (ak4531->regs[reg2] >> right_shift) & 1;
	mutex_unlock(&ak4531->reg_mutex);
	return 0;
}

__attribute__((used)) static int snd_ak4531_put_input_sw(struct snd_kcontrol *kcontrol, struct snd_ctl_elem_value *ucontrol)
{
	struct snd_ak4531 *ak4531 = snd_kcontrol_chip(kcontrol);
	int reg1 = kcontrol->private_value & 0xff;
	int reg2 = (kcontrol->private_value >> 8) & 0xff;
	int left_shift = (kcontrol->private_value >> 16) & 0x0f;
	int right_shift = (kcontrol->private_value >> 24) & 0x0f;
	int change;
	int val1, val2;

	mutex_lock(&ak4531->reg_mutex);
	val1 = ak4531->regs[reg1] & ~((1 << left_shift) | (1 << right_shift));
	val2 = ak4531->regs[reg2] & ~((1 << left_shift) | (1 << right_shift));
	val1 |= (ucontrol->value.integer.value[0] & 1) << left_shift;
	val2 |= (ucontrol->value.integer.value[1] & 1) << left_shift;
	val1 |= (ucontrol->value.integer.value[2] & 1) << right_shift;
	val2 |= (ucontrol->value.integer.value[3] & 1) << right_shift;
	change = val1 != ak4531->regs[reg1] || val2 != ak4531->regs[reg2];
	ak4531->write(ak4531, reg1, ak4531->regs[reg1] = val1);
	ak4531->write(ak4531, reg2, ak4531->regs[reg2] = val2);
	mutex_unlock(&ak4531->reg_mutex);
	return change;
}

__attribute__((used)) static int snd_ak4531_free(struct snd_ak4531 *ak4531)
{
	if (ak4531) {
		if (ak4531->private_free)
			ak4531->private_free(ak4531);
		kfree(ak4531);
	}
	return 0;
}

__attribute__((used)) static int snd_ak4531_dev_free(struct snd_device *device)
{
	struct snd_ak4531 *ak4531 = device->device_data;
	return snd_ak4531_free(ak4531);
}

int snd_ak4531_mixer(struct snd_card *card,
		     struct snd_ak4531 *_ak4531,
		     struct snd_ak4531 **rak4531)
{
	unsigned int idx;
	int err;
	struct snd_ak4531 *ak4531;
	static struct snd_device_ops ops = {
		.dev_free =	snd_ak4531_dev_free,
	};

	if (snd_BUG_ON(!card || !_ak4531))
		return -EINVAL;
	if (rak4531)
		*rak4531 = NULL;
	ak4531 = kzalloc(sizeof(*ak4531), GFP_KERNEL);
	if (ak4531 == NULL)
		return -ENOMEM;
	*ak4531 = *_ak4531;
	mutex_init(&ak4531->reg_mutex);
	if ((err = snd_component_add(card, "AK4531")) < 0) {
		snd_ak4531_free(ak4531);
		return err;
	}
	strcpy(card->mixername, "Asahi Kasei AK4531");
	ak4531->write(ak4531, AK4531_RESET, 0x03);	/* no RST, PD */
	udelay(100);
	ak4531->write(ak4531, AK4531_CLOCK, 0x00);	/* CODEC ADC and CODEC DAC use {LR,B}CLK2 and run off LRCLK2 PLL */
	for (idx = 0; idx <= 0x19; idx++) {
		if (idx == AK4531_RESET || idx == AK4531_CLOCK)
			continue;
		ak4531->write(ak4531, idx, ak4531->regs[idx] = snd_ak4531_initial_map[idx]);	/* recording source is mixer */
	}
	for (idx = 0; idx < ARRAY_SIZE(snd_ak4531_controls); idx++) {
		if ((err = snd_ctl_add(card, snd_ctl_new1(&snd_ak4531_controls[idx], ak4531))) < 0) {
			snd_ak4531_free(ak4531);
			return err;
		}
	}
	snd_ak4531_proc_init(card, ak4531);
	if ((err = snd_device_new(card, SNDRV_DEV_CODEC, ak4531, &ops)) < 0) {
		snd_ak4531_free(ak4531);
		return err;
	}

#if 0
	snd_ak4531_dump(ak4531);
#endif
	if (rak4531)
		*rak4531 = ak4531;
	return 0;
}

__attribute__((used)) static void snd_ak4531_proc_read(struct snd_info_entry *entry, 
				 struct snd_info_buffer *buffer)
{
	struct snd_ak4531 *ak4531 = entry->private_data;

	snd_iprintf(buffer, "Asahi Kasei AK4531\n\n");
	snd_iprintf(buffer, "Recording source   : %s\n"
		    "MIC gain           : %s\n",
		    ak4531->regs[AK4531_AD_IN] & 1 ? "external" : "mixer",
		    ak4531->regs[AK4531_MIC_GAIN] & 1 ? "+30dB" : "+0dB");
}

__attribute__((used)) static void
snd_ak4531_proc_init(struct snd_card *card, struct snd_ak4531 *ak4531)
{
	struct snd_info_entry *entry;

	if (! snd_card_proc_new(card, "ak4531", &entry))
		snd_info_set_text_ops(entry, ak4531, snd_ak4531_proc_read);
}

