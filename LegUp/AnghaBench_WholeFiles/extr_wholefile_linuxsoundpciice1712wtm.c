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
typedef  int /*<<< orphan*/  u8 ;
struct wtm_spec {int /*<<< orphan*/  mute_mutex; } ;
struct snd_kcontrol {scalar_t__ private_value; } ;
struct TYPE_12__ {unsigned int (* get_dir ) (struct snd_ice1712*) ;unsigned int (* get_data ) (struct snd_ice1712*) ;unsigned int* saved; unsigned int direction; unsigned int write_mask; void (* set_pro_rate ) (struct snd_ice1712*,unsigned int) ;int /*<<< orphan*/  (* set_mask ) (struct snd_ice1712*,unsigned int) ;int /*<<< orphan*/  (* set_dir ) (struct snd_ice1712*,unsigned int) ;int /*<<< orphan*/  (* set_data ) (struct snd_ice1712*,unsigned int) ;} ;
struct snd_ice1712 {int num_total_dacs; int num_total_adcs; int force_rdma1; TYPE_6__ gpio; struct wtm_spec* spec; int /*<<< orphan*/  card; int /*<<< orphan*/  gpio_mutex; } ;
struct TYPE_10__ {unsigned char* item; } ;
struct TYPE_9__ {unsigned char* value; } ;
struct TYPE_11__ {TYPE_4__ enumerated; TYPE_3__ integer; } ;
struct snd_ctl_elem_value {TYPE_5__ value; int /*<<< orphan*/  id; } ;
struct TYPE_7__ {int max; scalar_t__ min; } ;
struct TYPE_8__ {TYPE_1__ integer; } ;
struct snd_ctl_elem_info {int count; TYPE_2__ value; void* type; } ;

/* Variables and functions */
 unsigned int ARRAY_SIZE (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  DATA ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int /*<<< orphan*/  ICEREG (struct snd_ice1712*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  INDEX ; 
 void* SNDRV_CTL_ELEM_TYPE_INTEGER ; 
 int /*<<< orphan*/  STAC9460_2_I2C_ADDR ; 
 int /*<<< orphan*/  STAC9460_I2C_ADDR ; 
 int STAC946X_GENERAL_PURPOSE ; 
 int STAC946X_LF_VOLUME ; 
#define  STAC946X_MASTER_CLOCKING 129 
 int STAC946X_MASTER_VOLUME ; 
 int STAC946X_MIC_L_VOLUME ; 
#define  STAC946X_RESET 128 
 int /*<<< orphan*/  inb (int /*<<< orphan*/ ) ; 
 struct wtm_spec* kzalloc (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mutex_init (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  outb (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int snd_ctl_add (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int snd_ctl_enum_info (struct snd_ctl_elem_info*,int,int,char const* const*) ; 
 int snd_ctl_get_ioffidx (struct snd_kcontrol*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  snd_ctl_new1 (int /*<<< orphan*/ *,struct snd_ice1712*) ; 
 struct snd_ice1712* snd_kcontrol_chip (struct snd_kcontrol*) ; 
 unsigned char snd_vt1724_read_i2c (struct snd_ice1712*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  snd_vt1724_write_i2c (struct snd_ice1712*,int /*<<< orphan*/ ,int,unsigned char) ; 
 int /*<<< orphan*/ * stac9640_controls ; 
 int /*<<< orphan*/  stub1 (struct snd_ice1712*,unsigned int) ; 
 unsigned int stub2 (struct snd_ice1712*) ; 
 int /*<<< orphan*/  stub3 (struct snd_ice1712*,unsigned int) ; 
 int /*<<< orphan*/  stub4 (struct snd_ice1712*,unsigned int) ; 
 unsigned int stub5 (struct snd_ice1712*) ; 
 int /*<<< orphan*/  stub6 (struct snd_ice1712*,unsigned int) ; 
 int /*<<< orphan*/  stub7 (struct snd_ice1712*,unsigned int) ; 
 int /*<<< orphan*/  udelay (int) ; 

__attribute__((used)) static inline void snd_ice1712_gpio_set_dir(struct snd_ice1712 *ice, unsigned int bits)
{
	ice->gpio.set_dir(ice, bits);
}

__attribute__((used)) static inline unsigned int snd_ice1712_gpio_get_dir(struct snd_ice1712 *ice)
{
	return ice->gpio.get_dir(ice);
}

__attribute__((used)) static inline void snd_ice1712_gpio_set_mask(struct snd_ice1712 *ice, unsigned int bits)
{
	ice->gpio.set_mask(ice, bits);
}

__attribute__((used)) static inline void snd_ice1712_gpio_write(struct snd_ice1712 *ice, unsigned int val)
{
	ice->gpio.set_data(ice, val);
}

__attribute__((used)) static inline unsigned int snd_ice1712_gpio_read(struct snd_ice1712 *ice)
{
	return ice->gpio.get_data(ice);
}

__attribute__((used)) static inline void snd_ice1712_save_gpio_status(struct snd_ice1712 *ice)
{
	mutex_lock(&ice->gpio_mutex);
	ice->gpio.saved[0] = ice->gpio.direction;
	ice->gpio.saved[1] = ice->gpio.write_mask;
}

__attribute__((used)) static inline void snd_ice1712_restore_gpio_status(struct snd_ice1712 *ice)
{
	ice->gpio.set_dir(ice, ice->gpio.saved[0]);
	ice->gpio.set_mask(ice, ice->gpio.saved[1]);
	ice->gpio.direction = ice->gpio.saved[0];
	ice->gpio.write_mask = ice->gpio.saved[1];
	mutex_unlock(&ice->gpio_mutex);
}

__attribute__((used)) static inline void snd_ice1712_gpio_write_bits(struct snd_ice1712 *ice,
					       unsigned int mask, unsigned int bits)
{
	unsigned val;

	ice->gpio.direction |= mask;
	snd_ice1712_gpio_set_dir(ice, ice->gpio.direction);
	val = snd_ice1712_gpio_read(ice);
	val &= ~mask;
	val |= mask & bits;
	snd_ice1712_gpio_write(ice, val);
}

__attribute__((used)) static inline int snd_ice1712_gpio_read_bits(struct snd_ice1712 *ice,
					      unsigned int mask)
{
	ice->gpio.direction &= ~mask;
	snd_ice1712_gpio_set_dir(ice, ice->gpio.direction);
	return  snd_ice1712_gpio_read(ice) & mask;
}

__attribute__((used)) static inline void snd_ice1712_write(struct snd_ice1712 *ice, u8 addr, u8 data)
{
	outb(addr, ICEREG(ice, INDEX));
	outb(data, ICEREG(ice, DATA));
}

__attribute__((used)) static inline u8 snd_ice1712_read(struct snd_ice1712 *ice, u8 addr)
{
	outb(addr, ICEREG(ice, INDEX));
	return inb(ICEREG(ice, DATA));
}

__attribute__((used)) static inline void stac9460_put(struct snd_ice1712 *ice, int reg,
						unsigned char val)
{
	snd_vt1724_write_i2c(ice, STAC9460_I2C_ADDR, reg, val);
}

__attribute__((used)) static inline unsigned char stac9460_get(struct snd_ice1712 *ice, int reg)
{
	return snd_vt1724_read_i2c(ice, STAC9460_I2C_ADDR, reg);
}

__attribute__((used)) static inline void stac9460_2_put(struct snd_ice1712 *ice, int reg,
						unsigned char val)
{
	snd_vt1724_write_i2c(ice, STAC9460_2_I2C_ADDR, reg, val);
}

__attribute__((used)) static inline unsigned char stac9460_2_get(struct snd_ice1712 *ice, int reg)
{
	return snd_vt1724_read_i2c(ice, STAC9460_2_I2C_ADDR, reg);
}

__attribute__((used)) static void stac9460_dac_mute_all(struct snd_ice1712 *ice, unsigned char mute,
				unsigned short int *change_mask)
{
	unsigned char new, old;
	int id, idx, change;

	/*stac9460 1*/
	for (id = 0; id < 7; id++) {
		if (*change_mask & (0x01 << id)) {
			if (id == 0)
				idx = STAC946X_MASTER_VOLUME;
			else
				idx = STAC946X_LF_VOLUME - 1 + id;
			old = stac9460_get(ice, idx);
			new = (~mute << 7 & 0x80) | (old & ~0x80);
			change = (new != old);
			if (change) {
				stac9460_put(ice, idx, new);
				*change_mask = *change_mask | (0x01 << id);
			} else {
				*change_mask = *change_mask & ~(0x01 << id);
			}
		}
	}

	/*stac9460 2*/
	for (id = 0; id < 3; id++) {
		if (*change_mask & (0x01 << (id + 7))) {
			if (id == 0)
				idx = STAC946X_MASTER_VOLUME;
			else
				idx = STAC946X_LF_VOLUME - 1 + id;
			old = stac9460_2_get(ice, idx);
			new = (~mute << 7 & 0x80) | (old & ~0x80);
			change = (new != old);
			if (change) {
				stac9460_2_put(ice, idx, new);
				*change_mask = *change_mask | (0x01 << id);
			} else {
				*change_mask = *change_mask & ~(0x01 << id);
			}
		}
	}
}

__attribute__((used)) static int stac9460_dac_mute_get(struct snd_kcontrol *kcontrol,
				struct snd_ctl_elem_value *ucontrol)
{
	struct snd_ice1712 *ice = snd_kcontrol_chip(kcontrol);
	struct wtm_spec *spec = ice->spec;
	unsigned char val;
	int idx, id;

	mutex_lock(&spec->mute_mutex);

	if (kcontrol->private_value) {
		idx = STAC946X_MASTER_VOLUME;
		id = 0;
	} else {
		id = snd_ctl_get_ioffidx(kcontrol, &ucontrol->id);
		idx = id + STAC946X_LF_VOLUME;
	}
	if (id < 6)
		val = stac9460_get(ice, idx);
	else
		val = stac9460_2_get(ice, idx - 6);
	ucontrol->value.integer.value[0] = (~val >> 7) & 0x1;

	mutex_unlock(&spec->mute_mutex);
	return 0;
}

__attribute__((used)) static int stac9460_dac_mute_put(struct snd_kcontrol *kcontrol,
				struct snd_ctl_elem_value *ucontrol)
{
	struct snd_ice1712 *ice = snd_kcontrol_chip(kcontrol);
	unsigned char new, old;
	int id, idx;
	int change;

	if (kcontrol->private_value) {
		idx = STAC946X_MASTER_VOLUME;
		old = stac9460_get(ice, idx);
		new = (~ucontrol->value.integer.value[0] << 7 & 0x80) |
							(old & ~0x80);
		change = (new != old);
		if (change) {
			stac9460_put(ice, idx, new);
			stac9460_2_put(ice, idx, new);
		}
	} else {
		id = snd_ctl_get_ioffidx(kcontrol, &ucontrol->id);
		idx = id + STAC946X_LF_VOLUME;
		if (id < 6)
			old = stac9460_get(ice, idx);
		else
			old = stac9460_2_get(ice, idx - 6);
		new = (~ucontrol->value.integer.value[0] << 7 & 0x80) |
							(old & ~0x80);
		change = (new != old);
		if (change) {
			if (id < 6)
				stac9460_put(ice, idx, new);
			else
				stac9460_2_put(ice, idx - 6, new);
		}
	}
	return change;
}

__attribute__((used)) static int stac9460_dac_vol_info(struct snd_kcontrol *kcontrol,
				struct snd_ctl_elem_info *uinfo)
{
	uinfo->type = SNDRV_CTL_ELEM_TYPE_INTEGER;
	uinfo->count = 1;
	uinfo->value.integer.min = 0;			/* mute */
	uinfo->value.integer.max = 0x7f;		/* 0dB */
	return 0;
}

__attribute__((used)) static int stac9460_dac_vol_get(struct snd_kcontrol *kcontrol,
				struct snd_ctl_elem_value *ucontrol)
{
	struct snd_ice1712 *ice = snd_kcontrol_chip(kcontrol);
	int idx, id;
	unsigned char vol;

	if (kcontrol->private_value) {
		idx = STAC946X_MASTER_VOLUME;
		id = 0;
	} else {
		id = snd_ctl_get_ioffidx(kcontrol, &ucontrol->id);
		idx = id + STAC946X_LF_VOLUME;
	}
	if (id < 6)
		vol = stac9460_get(ice, idx) & 0x7f;
	else
		vol = stac9460_2_get(ice, idx - 6) & 0x7f;
	ucontrol->value.integer.value[0] = 0x7f - vol;
	return 0;
}

__attribute__((used)) static int stac9460_dac_vol_put(struct snd_kcontrol *kcontrol,
				struct snd_ctl_elem_value *ucontrol)
{
	struct snd_ice1712 *ice = snd_kcontrol_chip(kcontrol);
	int idx, id;
	unsigned char tmp, ovol, nvol;
	int change;

	if (kcontrol->private_value) {
		idx = STAC946X_MASTER_VOLUME;
		nvol = ucontrol->value.integer.value[0] & 0x7f;
		tmp = stac9460_get(ice, idx);
		ovol = 0x7f - (tmp & 0x7f);
		change = (ovol != nvol);
		if (change) {
			stac9460_put(ice, idx, (0x7f - nvol) | (tmp & 0x80));
			stac9460_2_put(ice, idx, (0x7f - nvol) | (tmp & 0x80));
		}
	} else {
		id = snd_ctl_get_ioffidx(kcontrol, &ucontrol->id);
		idx = id + STAC946X_LF_VOLUME;
		nvol = ucontrol->value.integer.value[0] & 0x7f;
		if (id < 6)
			tmp = stac9460_get(ice, idx);
		else
			tmp = stac9460_2_get(ice, idx - 6);
		ovol = 0x7f - (tmp & 0x7f);
		change = (ovol != nvol);
		if (change) {
			if (id < 6)
				stac9460_put(ice, idx, (0x7f - nvol) |
							(tmp & 0x80));
			else
				stac9460_2_put(ice, idx-6, (0x7f - nvol) |
							(tmp & 0x80));
		}
	}
	return change;
}

__attribute__((used)) static int stac9460_adc_mute_get(struct snd_kcontrol *kcontrol,
				struct snd_ctl_elem_value *ucontrol)
{
	struct snd_ice1712 *ice = snd_kcontrol_chip(kcontrol);
	unsigned char val;
	int i, id;

	id = snd_ctl_get_ioffidx(kcontrol, &ucontrol->id);
	if (id == 0) {
		for (i = 0; i < 2; ++i) {
			val = stac9460_get(ice, STAC946X_MIC_L_VOLUME + i);
			ucontrol->value.integer.value[i] = ~val>>7 & 0x1;
		}
	} else {
		for (i = 0; i < 2; ++i) {
			val = stac9460_2_get(ice, STAC946X_MIC_L_VOLUME + i);
			ucontrol->value.integer.value[i] = ~val>>7 & 0x1;
		}
	}
	return 0;
}

__attribute__((used)) static int stac9460_adc_mute_put(struct snd_kcontrol *kcontrol,
				struct snd_ctl_elem_value *ucontrol)
{
	struct snd_ice1712 *ice = snd_kcontrol_chip(kcontrol);
	unsigned char new, old;
	int i, reg, id;
	int change;

	id = snd_ctl_get_ioffidx(kcontrol, &ucontrol->id);
	if (id == 0) {
		for (i = 0; i < 2; ++i) {
			reg = STAC946X_MIC_L_VOLUME + i;
			old = stac9460_get(ice, reg);
			new = (~ucontrol->value.integer.value[i]<<7&0x80) |
								(old&~0x80);
			change = (new != old);
			if (change)
				stac9460_put(ice, reg, new);
		}
	} else {
		for (i = 0; i < 2; ++i) {
			reg = STAC946X_MIC_L_VOLUME + i;
			old = stac9460_2_get(ice, reg);
			new = (~ucontrol->value.integer.value[i]<<7&0x80) |
								(old&~0x80);
			change = (new != old);
			if (change)
				stac9460_2_put(ice, reg, new);
		}
	}
	return change;
}

__attribute__((used)) static int stac9460_adc_vol_info(struct snd_kcontrol *kcontrol,
				struct snd_ctl_elem_info *uinfo)
{
	uinfo->type = SNDRV_CTL_ELEM_TYPE_INTEGER;
	uinfo->count = 2;
	uinfo->value.integer.min = 0;		/* 0dB */
	uinfo->value.integer.max = 0x0f;	/* 22.5dB */
	return 0;
}

__attribute__((used)) static int stac9460_adc_vol_get(struct snd_kcontrol *kcontrol,
				struct snd_ctl_elem_value *ucontrol)
{
	struct snd_ice1712 *ice = snd_kcontrol_chip(kcontrol);
	int i, reg, id;
	unsigned char vol;

	id = snd_ctl_get_ioffidx(kcontrol, &ucontrol->id);
	if (id == 0) {
		for (i = 0; i < 2; ++i) {
			reg = STAC946X_MIC_L_VOLUME + i;
			vol = stac9460_get(ice, reg) & 0x0f;
			ucontrol->value.integer.value[i] = 0x0f - vol;
		}
	} else {
		for (i = 0; i < 2; ++i) {
			reg = STAC946X_MIC_L_VOLUME + i;
			vol = stac9460_2_get(ice, reg) & 0x0f;
			ucontrol->value.integer.value[i] = 0x0f - vol;
		}
	}
	return 0;
}

__attribute__((used)) static int stac9460_adc_vol_put(struct snd_kcontrol *kcontrol,
				struct snd_ctl_elem_value *ucontrol)
{
	struct snd_ice1712 *ice = snd_kcontrol_chip(kcontrol);
	int i, reg, id;
	unsigned char ovol, nvol;
	int change;

	id = snd_ctl_get_ioffidx(kcontrol, &ucontrol->id);
	if (id == 0) {
		for (i = 0; i < 2; ++i) {
			reg = STAC946X_MIC_L_VOLUME + i;
			nvol = ucontrol->value.integer.value[i] & 0x0f;
			ovol = 0x0f - stac9460_get(ice, reg);
			change = ((ovol & 0x0f) != nvol);
			if (change)
				stac9460_put(ice, reg, (0x0f - nvol) |
							(ovol & ~0x0f));
		}
	} else {
		for (i = 0; i < 2; ++i) {
			reg = STAC946X_MIC_L_VOLUME + i;
			nvol = ucontrol->value.integer.value[i] & 0x0f;
			ovol = 0x0f - stac9460_2_get(ice, reg);
			change = ((ovol & 0x0f) != nvol);
			if (change)
				stac9460_2_put(ice, reg, (0x0f - nvol) |
							(ovol & ~0x0f));
		}
	}
	return change;
}

__attribute__((used)) static int stac9460_mic_sw_info(struct snd_kcontrol *kcontrol,
				struct snd_ctl_elem_info *uinfo)
{
	static const char * const texts[2] = { "Line In", "Mic" };

	return snd_ctl_enum_info(uinfo, 1, 2, texts);
}

__attribute__((used)) static int stac9460_mic_sw_get(struct snd_kcontrol *kcontrol,
				struct snd_ctl_elem_value *ucontrol)
{
	struct snd_ice1712 *ice = snd_kcontrol_chip(kcontrol);
	unsigned char val;
	int id;

	id = snd_ctl_get_ioffidx(kcontrol, &ucontrol->id);
	if (id == 0)
		val = stac9460_get(ice, STAC946X_GENERAL_PURPOSE);
	else
		val = stac9460_2_get(ice, STAC946X_GENERAL_PURPOSE);
	ucontrol->value.enumerated.item[0] = (val >> 7) & 0x1;
	return 0;
}

__attribute__((used)) static int stac9460_mic_sw_put(struct snd_kcontrol *kcontrol,
				struct snd_ctl_elem_value *ucontrol)
{
	struct snd_ice1712 *ice = snd_kcontrol_chip(kcontrol);
	unsigned char new, old;
	int change, id;

	id = snd_ctl_get_ioffidx(kcontrol, &ucontrol->id);
	if (id == 0)
		old = stac9460_get(ice, STAC946X_GENERAL_PURPOSE);
	else
		old = stac9460_2_get(ice, STAC946X_GENERAL_PURPOSE);
	new = (ucontrol->value.enumerated.item[0] << 7 & 0x80) | (old & ~0x80);
	change = (new != old);
	if (change) {
		if (id == 0)
			stac9460_put(ice, STAC946X_GENERAL_PURPOSE, new);
		else
			stac9460_2_put(ice, STAC946X_GENERAL_PURPOSE, new);
	}
	return change;
}

__attribute__((used)) static void stac9460_set_rate_val(struct snd_ice1712 *ice, unsigned int rate)
{
	unsigned char old, new;
	unsigned short int changed;
	struct wtm_spec *spec = ice->spec;

	if (rate == 0)  /* no hint - S/PDIF input is master, simply return */
		return;
	else if (rate <= 48000)
		new = 0x08;     /* 256x, base rate mode */
	else if (rate <= 96000)
		new = 0x11;     /* 256x, mid rate mode */
	else
		new = 0x12;     /* 128x, high rate mode */

	old = stac9460_get(ice, STAC946X_MASTER_CLOCKING);
	if (old == new)
		return;
	/* change detected, setting master clock, muting first */
	/* due to possible conflicts with mute controls - mutexing */
	mutex_lock(&spec->mute_mutex);
	/* we have to remember current mute status for each DAC */
	changed = 0xFFFF;
	stac9460_dac_mute_all(ice, 0, &changed);
	/*printk(KERN_DEBUG "Rate change: %d, new MC: 0x%02x\n", rate, new);*/
	stac9460_put(ice, STAC946X_MASTER_CLOCKING, new);
	stac9460_2_put(ice, STAC946X_MASTER_CLOCKING, new);
	udelay(10);
	/* unmuting - only originally unmuted dacs -
	* i.e. those changed when muting */
	stac9460_dac_mute_all(ice, 1, &changed);
	mutex_unlock(&spec->mute_mutex);
}

__attribute__((used)) static int wtm_add_controls(struct snd_ice1712 *ice)
{
	unsigned int i;
	int err;

	for (i = 0; i < ARRAY_SIZE(stac9640_controls); i++) {
		err = snd_ctl_add(ice->card,
				snd_ctl_new1(&stac9640_controls[i], ice));
		if (err < 0)
			return err;
	}
	return 0;
}

__attribute__((used)) static int wtm_init(struct snd_ice1712 *ice)
{
	static unsigned short stac_inits_wtm[] = {
		STAC946X_RESET, 0,
		STAC946X_MASTER_CLOCKING, 0x11,
		(unsigned short)-1
	};
	unsigned short *p;
	struct wtm_spec *spec;

	/*WTM 192M*/
	ice->num_total_dacs = 8;
	ice->num_total_adcs = 4;
	ice->force_rdma1 = 1;

	/*init mutex for dac mute conflict*/
	spec = kzalloc(sizeof(*spec), GFP_KERNEL);
	if (!spec)
		return -ENOMEM;
	ice->spec = spec;
	mutex_init(&spec->mute_mutex);


	/*initialize codec*/
	p = stac_inits_wtm;
	for (; *p != (unsigned short)-1; p += 2) {
		stac9460_put(ice, p[0], p[1]);
		stac9460_2_put(ice, p[0], p[1]);
	}
	ice->gpio.set_pro_rate = stac9460_set_rate_val;
	return 0;
}

