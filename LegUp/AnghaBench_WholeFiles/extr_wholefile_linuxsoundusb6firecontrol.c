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
typedef  int u8 ;
struct usb_device {int /*<<< orphan*/  dev; } ;
struct snd_kcontrol_new {scalar_t__ name; } ;
struct snd_kcontrol {unsigned int private_value; } ;
struct TYPE_10__ {scalar_t__* value; } ;
struct TYPE_9__ {scalar_t__* item; } ;
struct TYPE_11__ {TYPE_4__ integer; TYPE_3__ enumerated; } ;
struct snd_ctl_elem_value {TYPE_5__ value; } ;
struct TYPE_7__ {int max; scalar_t__ min; } ;
struct TYPE_8__ {TYPE_1__ integer; } ;
struct snd_ctl_elem_info {int count; TYPE_2__ value; void* type; } ;
struct snd_card {int dummy; } ;
struct sfire_chip {struct control_runtime* control; struct usb_device* dev; struct snd_card* card; struct comm_runtime* comm; } ;
struct control_runtime {int ovol_updated; scalar_t__* output_vol; int output_mute; int ivol_updated; int* input_vol; scalar_t__ line_phono_switch; scalar_t__ opt_coax_switch; scalar_t__ digital_thru_switch; int (* update_streaming ) (struct control_runtime*) ;int (* set_rate ) (struct control_runtime*,int) ;int (* set_channels ) (struct control_runtime*,int,int,int,int) ;struct sfire_chip* chip; scalar_t__ usb_streaming; } ;
struct comm_runtime {int (* write16 ) (struct comm_runtime*,int,int,int,int) ;int /*<<< orphan*/  (* write8 ) (struct comm_runtime*,int,int,scalar_t__) ;} ;
struct TYPE_12__ {int type; int reg; scalar_t__ value; } ;

/* Variables and functions */
 int CONTROL_N_RATES ; 
 int DIGITAL_THRU_ONLY_SAMPLERATE ; 
 int EINVAL ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 void* SNDRV_CTL_ELEM_TYPE_INTEGER ; 
 int /*<<< orphan*/  dev_err (int /*<<< orphan*/ *,char*) ; 
 struct snd_kcontrol_new* elements ; 
 TYPE_6__* init_data ; 
 int /*<<< orphan*/  kfree (struct control_runtime*) ; 
 struct control_runtime* kzalloc (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  line_phono_texts ; 
 struct snd_kcontrol_new* mute_elements ; 
 int /*<<< orphan*/  opt_coax_texts ; 
 int* rates_6fire_vh ; 
 int* rates_6fire_vl ; 
 int /*<<< orphan*/ * rates_altsetting ; 
 int snd_ctl_add (struct snd_card*,struct snd_kcontrol*) ; 
 int snd_ctl_add_slave (struct snd_kcontrol*,struct snd_kcontrol*) ; 
 int snd_ctl_enum_info (struct snd_ctl_elem_info*,int,int,int /*<<< orphan*/ ) ; 
 struct snd_kcontrol* snd_ctl_make_virtual_master (char*,int /*<<< orphan*/ ) ; 
 struct snd_kcontrol* snd_ctl_new1 (struct snd_kcontrol_new*,struct control_runtime*) ; 
 struct control_runtime* snd_kcontrol_chip (struct snd_kcontrol*) ; 
 int /*<<< orphan*/  stub1 (struct comm_runtime*,int,int,scalar_t__) ; 
 int stub10 (struct comm_runtime*,int,int,int,int) ; 
 int stub11 (struct comm_runtime*,int,int,int,int) ; 
 int /*<<< orphan*/  stub12 (struct comm_runtime*,int,int,scalar_t__) ; 
 int /*<<< orphan*/  stub2 (struct comm_runtime*,int,int,int) ; 
 int /*<<< orphan*/  stub3 (struct comm_runtime*,int,int,int) ; 
 int /*<<< orphan*/  stub4 (struct comm_runtime*,int,int,scalar_t__) ; 
 int /*<<< orphan*/  stub5 (struct comm_runtime*,int,int,scalar_t__) ; 
 int /*<<< orphan*/  stub6 (struct comm_runtime*,int,int,scalar_t__) ; 
 int /*<<< orphan*/  stub7 (struct comm_runtime*,int,int,scalar_t__) ; 
 int stub8 (struct comm_runtime*,int,int,int,int) ; 
 int stub9 (struct comm_runtime*,int,int,int,int) ; 
 int /*<<< orphan*/  tlv_output ; 
 int usb_set_interface (struct usb_device*,int,int /*<<< orphan*/ ) ; 
 struct snd_kcontrol_new* vol_elements ; 

__attribute__((used)) static void usb6fire_control_output_vol_update(struct control_runtime *rt)
{
	struct comm_runtime *comm_rt = rt->chip->comm;
	int i;

	if (comm_rt)
		for (i = 0; i < 6; i++)
			if (!(rt->ovol_updated & (1 << i))) {
				comm_rt->write8(comm_rt, 0x12, 0x0f + i,
					180 - rt->output_vol[i]);
				rt->ovol_updated |= 1 << i;
			}
}

__attribute__((used)) static void usb6fire_control_output_mute_update(struct control_runtime *rt)
{
	struct comm_runtime *comm_rt = rt->chip->comm;

	if (comm_rt)
		comm_rt->write8(comm_rt, 0x12, 0x0e, ~rt->output_mute);
}

__attribute__((used)) static void usb6fire_control_input_vol_update(struct control_runtime *rt)
{
	struct comm_runtime *comm_rt = rt->chip->comm;
	int i;

	if (comm_rt)
		for (i = 0; i < 2; i++)
			if (!(rt->ivol_updated & (1 << i))) {
				comm_rt->write8(comm_rt, 0x12, 0x1c + i,
					rt->input_vol[i] & 0x3f);
				rt->ivol_updated |= 1 << i;
			}
}

__attribute__((used)) static void usb6fire_control_line_phono_update(struct control_runtime *rt)
{
	struct comm_runtime *comm_rt = rt->chip->comm;
	if (comm_rt) {
		comm_rt->write8(comm_rt, 0x22, 0x02, rt->line_phono_switch);
		comm_rt->write8(comm_rt, 0x21, 0x02, rt->line_phono_switch);
	}
}

__attribute__((used)) static void usb6fire_control_opt_coax_update(struct control_runtime *rt)
{
	struct comm_runtime *comm_rt = rt->chip->comm;
	if (comm_rt) {
		comm_rt->write8(comm_rt, 0x22, 0x00, rt->opt_coax_switch);
		comm_rt->write8(comm_rt, 0x21, 0x00, rt->opt_coax_switch);
	}
}

__attribute__((used)) static int usb6fire_control_set_rate(struct control_runtime *rt, int rate)
{
	int ret;
	struct usb_device *device = rt->chip->dev;
	struct comm_runtime *comm_rt = rt->chip->comm;

	if (rate < 0 || rate >= CONTROL_N_RATES)
		return -EINVAL;

	ret = usb_set_interface(device, 1, rates_altsetting[rate]);
	if (ret < 0)
		return ret;

	/* set soundcard clock */
	ret = comm_rt->write16(comm_rt, 0x02, 0x01, rates_6fire_vl[rate],
			rates_6fire_vh[rate]);
	if (ret < 0)
		return ret;

	return 0;
}

__attribute__((used)) static int usb6fire_control_set_channels(
	struct control_runtime *rt, int n_analog_out,
	int n_analog_in, bool spdif_out, bool spdif_in)
{
	int ret;
	struct comm_runtime *comm_rt = rt->chip->comm;

	/* enable analog inputs and outputs
	 * (one bit per stereo-channel) */
	ret = comm_rt->write16(comm_rt, 0x02, 0x02,
			(1 << (n_analog_out / 2)) - 1,
			(1 << (n_analog_in / 2)) - 1);
	if (ret < 0)
		return ret;

	/* disable digital inputs and outputs */
	/* TODO: use spdif_x to enable/disable digital channels */
	ret = comm_rt->write16(comm_rt, 0x02, 0x03, 0x00, 0x00);
	if (ret < 0)
		return ret;

	return 0;
}

__attribute__((used)) static int usb6fire_control_streaming_update(struct control_runtime *rt)
{
	struct comm_runtime *comm_rt = rt->chip->comm;

	if (comm_rt) {
		if (!rt->usb_streaming && rt->digital_thru_switch)
			usb6fire_control_set_rate(rt,
				DIGITAL_THRU_ONLY_SAMPLERATE);
		return comm_rt->write16(comm_rt, 0x02, 0x00, 0x00,
			(rt->usb_streaming ? 0x01 : 0x00) |
			(rt->digital_thru_switch ? 0x08 : 0x00));
	}
	return -EINVAL;
}

__attribute__((used)) static int usb6fire_control_output_vol_info(struct snd_kcontrol *kcontrol,
		struct snd_ctl_elem_info *uinfo)
{
	uinfo->type = SNDRV_CTL_ELEM_TYPE_INTEGER;
	uinfo->count = 2;
	uinfo->value.integer.min = 0;
	uinfo->value.integer.max = 180;
	return 0;
}

__attribute__((used)) static int usb6fire_control_output_vol_put(struct snd_kcontrol *kcontrol,
		struct snd_ctl_elem_value *ucontrol)
{
	struct control_runtime *rt = snd_kcontrol_chip(kcontrol);
	unsigned int ch = kcontrol->private_value;
	int changed = 0;

	if (ch > 4) {
		dev_err(&rt->chip->dev->dev,
			"Invalid channel in volume control.");
		return -EINVAL;
	}

	if (rt->output_vol[ch] != ucontrol->value.integer.value[0]) {
		rt->output_vol[ch] = ucontrol->value.integer.value[0];
		rt->ovol_updated &= ~(1 << ch);
		changed = 1;
	}
	if (rt->output_vol[ch + 1] != ucontrol->value.integer.value[1]) {
		rt->output_vol[ch + 1] = ucontrol->value.integer.value[1];
		rt->ovol_updated &= ~(2 << ch);
		changed = 1;
	}

	if (changed)
		usb6fire_control_output_vol_update(rt);

	return changed;
}

__attribute__((used)) static int usb6fire_control_output_vol_get(struct snd_kcontrol *kcontrol,
		struct snd_ctl_elem_value *ucontrol)
{
	struct control_runtime *rt = snd_kcontrol_chip(kcontrol);
	unsigned int ch = kcontrol->private_value;

	if (ch > 4) {
		dev_err(&rt->chip->dev->dev,
			"Invalid channel in volume control.");
		return -EINVAL;
	}

	ucontrol->value.integer.value[0] = rt->output_vol[ch];
	ucontrol->value.integer.value[1] = rt->output_vol[ch + 1];
	return 0;
}

__attribute__((used)) static int usb6fire_control_output_mute_put(struct snd_kcontrol *kcontrol,
	struct snd_ctl_elem_value *ucontrol)
{
	struct control_runtime *rt = snd_kcontrol_chip(kcontrol);
	unsigned int ch = kcontrol->private_value;
	u8 old = rt->output_mute;
	u8 value = 0;

	if (ch > 4) {
		dev_err(&rt->chip->dev->dev,
			"Invalid channel in volume control.");
		return -EINVAL;
	}

	rt->output_mute &= ~(3 << ch);
	if (ucontrol->value.integer.value[0])
		value |= 1;
	if (ucontrol->value.integer.value[1])
		value |= 2;
	rt->output_mute |= value << ch;

	if (rt->output_mute != old)
		usb6fire_control_output_mute_update(rt);

	return rt->output_mute != old;
}

__attribute__((used)) static int usb6fire_control_output_mute_get(struct snd_kcontrol *kcontrol,
	struct snd_ctl_elem_value *ucontrol)
{
	struct control_runtime *rt = snd_kcontrol_chip(kcontrol);
	unsigned int ch = kcontrol->private_value;
	u8 value = rt->output_mute >> ch;

	if (ch > 4) {
		dev_err(&rt->chip->dev->dev,
			"Invalid channel in volume control.");
		return -EINVAL;
	}

	ucontrol->value.integer.value[0] = 1 & value;
	value >>= 1;
	ucontrol->value.integer.value[1] = 1 & value;

	return 0;
}

__attribute__((used)) static int usb6fire_control_input_vol_info(struct snd_kcontrol *kcontrol,
		struct snd_ctl_elem_info *uinfo)
{
	uinfo->type = SNDRV_CTL_ELEM_TYPE_INTEGER;
	uinfo->count = 2;
	uinfo->value.integer.min = 0;
	uinfo->value.integer.max = 30;
	return 0;
}

__attribute__((used)) static int usb6fire_control_input_vol_put(struct snd_kcontrol *kcontrol,
		struct snd_ctl_elem_value *ucontrol)
{
	struct control_runtime *rt = snd_kcontrol_chip(kcontrol);
	int changed = 0;

	if (rt->input_vol[0] != ucontrol->value.integer.value[0]) {
		rt->input_vol[0] = ucontrol->value.integer.value[0] - 15;
		rt->ivol_updated &= ~(1 << 0);
		changed = 1;
	}
	if (rt->input_vol[1] != ucontrol->value.integer.value[1]) {
		rt->input_vol[1] = ucontrol->value.integer.value[1] - 15;
		rt->ivol_updated &= ~(1 << 1);
		changed = 1;
	}

	if (changed)
		usb6fire_control_input_vol_update(rt);

	return changed;
}

__attribute__((used)) static int usb6fire_control_input_vol_get(struct snd_kcontrol *kcontrol,
		struct snd_ctl_elem_value *ucontrol)
{
	struct control_runtime *rt = snd_kcontrol_chip(kcontrol);

	ucontrol->value.integer.value[0] = rt->input_vol[0] + 15;
	ucontrol->value.integer.value[1] = rt->input_vol[1] + 15;

	return 0;
}

__attribute__((used)) static int usb6fire_control_line_phono_info(struct snd_kcontrol *kcontrol,
		struct snd_ctl_elem_info *uinfo)
{
	return snd_ctl_enum_info(uinfo, 1, 2, line_phono_texts);
}

__attribute__((used)) static int usb6fire_control_line_phono_put(struct snd_kcontrol *kcontrol,
		struct snd_ctl_elem_value *ucontrol)
{
	struct control_runtime *rt = snd_kcontrol_chip(kcontrol);
	int changed = 0;
	if (rt->line_phono_switch != ucontrol->value.integer.value[0]) {
		rt->line_phono_switch = ucontrol->value.integer.value[0];
		usb6fire_control_line_phono_update(rt);
		changed = 1;
	}
	return changed;
}

__attribute__((used)) static int usb6fire_control_line_phono_get(struct snd_kcontrol *kcontrol,
		struct snd_ctl_elem_value *ucontrol)
{
	struct control_runtime *rt = snd_kcontrol_chip(kcontrol);
	ucontrol->value.integer.value[0] = rt->line_phono_switch;
	return 0;
}

__attribute__((used)) static int usb6fire_control_opt_coax_info(struct snd_kcontrol *kcontrol,
		struct snd_ctl_elem_info *uinfo)
{
	return snd_ctl_enum_info(uinfo, 1, 2, opt_coax_texts);
}

__attribute__((used)) static int usb6fire_control_opt_coax_put(struct snd_kcontrol *kcontrol,
		struct snd_ctl_elem_value *ucontrol)
{
	struct control_runtime *rt = snd_kcontrol_chip(kcontrol);
	int changed = 0;

	if (rt->opt_coax_switch != ucontrol->value.enumerated.item[0]) {
		rt->opt_coax_switch = ucontrol->value.enumerated.item[0];
		usb6fire_control_opt_coax_update(rt);
		changed = 1;
	}
	return changed;
}

__attribute__((used)) static int usb6fire_control_opt_coax_get(struct snd_kcontrol *kcontrol,
		struct snd_ctl_elem_value *ucontrol)
{
	struct control_runtime *rt = snd_kcontrol_chip(kcontrol);
	ucontrol->value.enumerated.item[0] = rt->opt_coax_switch;
	return 0;
}

__attribute__((used)) static int usb6fire_control_digital_thru_put(struct snd_kcontrol *kcontrol,
		struct snd_ctl_elem_value *ucontrol)
{
	struct control_runtime *rt = snd_kcontrol_chip(kcontrol);
	int changed = 0;

	if (rt->digital_thru_switch != ucontrol->value.integer.value[0]) {
		rt->digital_thru_switch = ucontrol->value.integer.value[0];
		usb6fire_control_streaming_update(rt);
		changed = 1;
	}
	return changed;
}

__attribute__((used)) static int usb6fire_control_digital_thru_get(struct snd_kcontrol *kcontrol,
		struct snd_ctl_elem_value *ucontrol)
{
	struct control_runtime *rt = snd_kcontrol_chip(kcontrol);
	ucontrol->value.integer.value[0] = rt->digital_thru_switch;
	return 0;
}

__attribute__((used)) static int usb6fire_control_add_virtual(
	struct control_runtime *rt,
	struct snd_card *card,
	char *name,
	struct snd_kcontrol_new *elems)
{
	int ret;
	int i;
	struct snd_kcontrol *vmaster =
		snd_ctl_make_virtual_master(name, tlv_output);
	struct snd_kcontrol *control;

	if (!vmaster)
		return -ENOMEM;
	ret = snd_ctl_add(card, vmaster);
	if (ret < 0)
		return ret;

	i = 0;
	while (elems[i].name) {
		control = snd_ctl_new1(&elems[i], rt);
		if (!control)
			return -ENOMEM;
		ret = snd_ctl_add(card, control);
		if (ret < 0)
			return ret;
		ret = snd_ctl_add_slave(vmaster, control);
		if (ret < 0)
			return ret;
		i++;
	}
	return 0;
}

int usb6fire_control_init(struct sfire_chip *chip)
{
	int i;
	int ret;
	struct control_runtime *rt = kzalloc(sizeof(struct control_runtime),
			GFP_KERNEL);
	struct comm_runtime *comm_rt = chip->comm;

	if (!rt)
		return -ENOMEM;

	rt->chip = chip;
	rt->update_streaming = usb6fire_control_streaming_update;
	rt->set_rate = usb6fire_control_set_rate;
	rt->set_channels = usb6fire_control_set_channels;

	i = 0;
	while (init_data[i].type) {
		comm_rt->write8(comm_rt, init_data[i].type, init_data[i].reg,
				init_data[i].value);
		i++;
	}

	usb6fire_control_opt_coax_update(rt);
	usb6fire_control_line_phono_update(rt);
	usb6fire_control_output_vol_update(rt);
	usb6fire_control_output_mute_update(rt);
	usb6fire_control_input_vol_update(rt);
	usb6fire_control_streaming_update(rt);

	ret = usb6fire_control_add_virtual(rt, chip->card,
		"Master Playback Volume", vol_elements);
	if (ret) {
		dev_err(&chip->dev->dev, "cannot add control.\n");
		kfree(rt);
		return ret;
	}
	ret = usb6fire_control_add_virtual(rt, chip->card,
		"Master Playback Switch", mute_elements);
	if (ret) {
		dev_err(&chip->dev->dev, "cannot add control.\n");
		kfree(rt);
		return ret;
	}

	i = 0;
	while (elements[i].name) {
		ret = snd_ctl_add(chip->card, snd_ctl_new1(&elements[i], rt));
		if (ret < 0) {
			kfree(rt);
			dev_err(&chip->dev->dev, "cannot add control.\n");
			return ret;
		}
		i++;
	}

	chip->control = rt;
	return 0;
}

void usb6fire_control_abort(struct sfire_chip *chip)
{}

void usb6fire_control_destroy(struct sfire_chip *chip)
{
	kfree(chip->control);
	chip->control = NULL;
}

