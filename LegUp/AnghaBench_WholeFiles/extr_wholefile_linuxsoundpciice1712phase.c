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
typedef  int /*<<< orphan*/  u8 ;
struct snd_kcontrol {int private_value; } ;
struct TYPE_9__ {int subvendor; } ;
struct TYPE_8__ {unsigned int (* get_dir ) (struct snd_ice1712*) ;unsigned int (* get_data ) (struct snd_ice1712*) ;unsigned int* saved; unsigned int direction; unsigned int write_mask; int /*<<< orphan*/  (* set_mask ) (struct snd_ice1712*,unsigned int) ;int /*<<< orphan*/  (* set_dir ) (struct snd_ice1712*,unsigned int) ;int /*<<< orphan*/  (* set_data ) (struct snd_ice1712*,unsigned int) ;} ;
struct snd_ice1712 {int num_total_dacs; int num_total_adcs; int vt1720; int akm_codecs; int /*<<< orphan*/  card; int /*<<< orphan*/  gpio_mutex; struct phase28_spec* spec; struct snd_akm4xxx* akm; TYPE_2__ eeprom; TYPE_1__ gpio; } ;
struct TYPE_13__ {int* item; } ;
struct TYPE_12__ {int* value; } ;
struct TYPE_14__ {TYPE_6__ enumerated; TYPE_5__ integer; } ;
struct snd_ctl_elem_value {TYPE_7__ value; } ;
struct TYPE_10__ {unsigned short max; scalar_t__ min; } ;
struct TYPE_11__ {TYPE_3__ integer; } ;
struct snd_ctl_elem_info {int count; TYPE_4__ value; void* type; } ;
struct snd_akm4xxx {unsigned short* images; } ;
struct phase28_spec {unsigned short* master; unsigned short* vol; } ;

/* Variables and functions */
 unsigned int ARRAY_SIZE (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  DATA ; 
 int EINVAL ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int /*<<< orphan*/  ICEREG (struct snd_ice1712*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  INDEX ; 
 unsigned short PCM_MIN ; 
 unsigned short PCM_RES ; 
 unsigned int PHASE28_HP_SEL ; 
 unsigned int PHASE28_SPI_CLK ; 
 unsigned int PHASE28_SPI_MOSI ; 
 unsigned int PHASE28_WM_CS ; 
 unsigned int PHASE28_WM_RESET ; 
 unsigned int PHASE28_WM_RW ; 
 void* SNDRV_CTL_ELEM_TYPE_BOOLEAN ; 
 void* SNDRV_CTL_ELEM_TYPE_INTEGER ; 
#define  VT1724_SUBDEVICE_PHASE22 129 
#define  VT1724_SUBDEVICE_TS22 128 
 int WM_DAC_ATTEN ; 
 int WM_DAC_CTRL2 ; 
 int WM_DAC_DIG_MASTER_ATTEN ; 
 int WM_MASTER ; 
 int WM_MUTE ; 
 unsigned short WM_VOL_MAX ; 
 unsigned short WM_VOL_MUTE ; 
 int /*<<< orphan*/  akm_phase22 ; 
 int /*<<< orphan*/  akm_phase22_priv ; 
 int /*<<< orphan*/  inb (int /*<<< orphan*/ ) ; 
 void* kzalloc (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  outb (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/ * phase28_dac_controls ; 
 int /*<<< orphan*/  snd_BUG () ; 
 int snd_ctl_add (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int snd_ctl_enum_info (struct snd_ctl_elem_info*,int,int,char const* const*) ; 
 int /*<<< orphan*/  snd_ctl_new1 (int /*<<< orphan*/ *,struct snd_ice1712*) ; 
 int snd_ice1712_akm4xxx_build_controls (struct snd_ice1712*) ; 
 int snd_ice1712_akm4xxx_init (struct snd_akm4xxx*,int /*<<< orphan*/ *,int /*<<< orphan*/ *,struct snd_ice1712*) ; 
 struct snd_ice1712* snd_kcontrol_chip (struct snd_kcontrol*) ; 
 int /*<<< orphan*/  stub1 (struct snd_ice1712*,unsigned int) ; 
 unsigned int stub2 (struct snd_ice1712*) ; 
 int /*<<< orphan*/  stub3 (struct snd_ice1712*,unsigned int) ; 
 int /*<<< orphan*/  stub4 (struct snd_ice1712*,unsigned int) ; 
 unsigned int stub5 (struct snd_ice1712*) ; 
 int /*<<< orphan*/  stub6 (struct snd_ice1712*,unsigned int) ; 
 int /*<<< orphan*/  stub7 (struct snd_ice1712*,unsigned int) ; 
 int /*<<< orphan*/  udelay (int) ; 
 int /*<<< orphan*/ * wm_controls ; 
 int* wm_vol ; 

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

__attribute__((used)) static int phase22_init(struct snd_ice1712 *ice)
{
	struct snd_akm4xxx *ak;
	int err;

	/* Configure DAC/ADC description for generic part of ice1724 */
	switch (ice->eeprom.subvendor) {
	case VT1724_SUBDEVICE_PHASE22:
	case VT1724_SUBDEVICE_TS22:
		ice->num_total_dacs = 2;
		ice->num_total_adcs = 2;
		ice->vt1720 = 1; /* Envy24HT-S have 16 bit wide GPIO */
		break;
	default:
		snd_BUG();
		return -EINVAL;
	}

	/* Initialize analog chips */
	ice->akm = kzalloc(sizeof(struct snd_akm4xxx), GFP_KERNEL);
	ak = ice->akm;
	if (!ak)
		return -ENOMEM;
	ice->akm_codecs = 1;
	switch (ice->eeprom.subvendor) {
	case VT1724_SUBDEVICE_PHASE22:
	case VT1724_SUBDEVICE_TS22:
		err = snd_ice1712_akm4xxx_init(ak, &akm_phase22,
						&akm_phase22_priv, ice);
		if (err < 0)
			return err;
		break;
	}

	return 0;
}

__attribute__((used)) static int phase22_add_controls(struct snd_ice1712 *ice)
{
	int err = 0;

	switch (ice->eeprom.subvendor) {
	case VT1724_SUBDEVICE_PHASE22:
	case VT1724_SUBDEVICE_TS22:
		err = snd_ice1712_akm4xxx_build_controls(ice);
		if (err < 0)
			return err;
	}
	return 0;
}

__attribute__((used)) static void phase28_spi_write(struct snd_ice1712 *ice, unsigned int cs,
				unsigned int data, int bits)
{
	unsigned int tmp;
	int i;

	tmp = snd_ice1712_gpio_read(ice);

	snd_ice1712_gpio_set_mask(ice, ~(PHASE28_WM_RW|PHASE28_SPI_MOSI|
					PHASE28_SPI_CLK|PHASE28_WM_CS));
	tmp |= PHASE28_WM_RW;
	tmp &= ~cs;
	snd_ice1712_gpio_write(ice, tmp);
	udelay(1);

	for (i = bits - 1; i >= 0; i--) {
		tmp &= ~PHASE28_SPI_CLK;
		snd_ice1712_gpio_write(ice, tmp);
		udelay(1);
		if (data & (1 << i))
			tmp |= PHASE28_SPI_MOSI;
		else
			tmp &= ~PHASE28_SPI_MOSI;
		snd_ice1712_gpio_write(ice, tmp);
		udelay(1);
		tmp |= PHASE28_SPI_CLK;
		snd_ice1712_gpio_write(ice, tmp);
		udelay(1);
	}

	tmp &= ~PHASE28_SPI_CLK;
	tmp |= cs;
	snd_ice1712_gpio_write(ice, tmp);
	udelay(1);
	tmp |= PHASE28_SPI_CLK;
	snd_ice1712_gpio_write(ice, tmp);
	udelay(1);
}

__attribute__((used)) static unsigned short wm_get(struct snd_ice1712 *ice, int reg)
{
	reg <<= 1;
	return ((unsigned short)ice->akm[0].images[reg] << 8) |
		ice->akm[0].images[reg + 1];
}

__attribute__((used)) static void wm_put_nocache(struct snd_ice1712 *ice, int reg, unsigned short val)
{
	phase28_spi_write(ice, PHASE28_WM_CS, (reg << 9) | (val & 0x1ff), 16);
}

__attribute__((used)) static void wm_put(struct snd_ice1712 *ice, int reg, unsigned short val)
{
	wm_put_nocache(ice, reg, val);
	reg <<= 1;
	ice->akm[0].images[reg] = val >> 8;
	ice->akm[0].images[reg + 1] = val;
}

__attribute__((used)) static void wm_set_vol(struct snd_ice1712 *ice, unsigned int index,
			unsigned short vol, unsigned short master)
{
	unsigned char nvol;

	if ((master & WM_VOL_MUTE) || (vol & WM_VOL_MUTE))
		nvol = 0;
	else
		nvol = 127 - wm_vol[(((vol & ~WM_VOL_MUTE) *
			(master & ~WM_VOL_MUTE)) / 127) & WM_VOL_MAX];

	wm_put(ice, index, nvol);
	wm_put_nocache(ice, index, 0x180 | nvol);
}

__attribute__((used)) static int wm_pcm_mute_get(struct snd_kcontrol *kcontrol,
				struct snd_ctl_elem_value *ucontrol)
{
	struct snd_ice1712 *ice = snd_kcontrol_chip(kcontrol);

	mutex_lock(&ice->gpio_mutex);
	ucontrol->value.integer.value[0] = (wm_get(ice, WM_MUTE) & 0x10) ?
						0 : 1;
	mutex_unlock(&ice->gpio_mutex);
	return 0;
}

__attribute__((used)) static int wm_pcm_mute_put(struct snd_kcontrol *kcontrol,
				struct snd_ctl_elem_value *ucontrol)
{
	struct snd_ice1712 *ice = snd_kcontrol_chip(kcontrol);
	unsigned short nval, oval;
	int change;

	snd_ice1712_save_gpio_status(ice);
	oval = wm_get(ice, WM_MUTE);
	nval = (oval & ~0x10) | (ucontrol->value.integer.value[0] ? 0 : 0x10);
	change = (nval != oval);
	if (change)
		wm_put(ice, WM_MUTE, nval);
	snd_ice1712_restore_gpio_status(ice);

	return change;
}

__attribute__((used)) static int wm_master_vol_info(struct snd_kcontrol *kcontrol,
				struct snd_ctl_elem_info *uinfo)
{
	uinfo->type = SNDRV_CTL_ELEM_TYPE_INTEGER;
	uinfo->count = 2;
	uinfo->value.integer.min = 0;
	uinfo->value.integer.max = WM_VOL_MAX;
	return 0;
}

__attribute__((used)) static int wm_master_vol_get(struct snd_kcontrol *kcontrol,
				struct snd_ctl_elem_value *ucontrol)
{
	struct snd_ice1712 *ice = snd_kcontrol_chip(kcontrol);
	struct phase28_spec *spec = ice->spec;
	int i;
	for (i = 0; i < 2; i++)
		ucontrol->value.integer.value[i] = spec->master[i] &
							~WM_VOL_MUTE;
	return 0;
}

__attribute__((used)) static int wm_master_vol_put(struct snd_kcontrol *kcontrol,
				struct snd_ctl_elem_value *ucontrol)
{
	struct snd_ice1712 *ice = snd_kcontrol_chip(kcontrol);
	struct phase28_spec *spec = ice->spec;
	int ch, change = 0;

	snd_ice1712_save_gpio_status(ice);
	for (ch = 0; ch < 2; ch++) {
		unsigned int vol = ucontrol->value.integer.value[ch];
		if (vol > WM_VOL_MAX)
			continue;
		vol |= spec->master[ch] & WM_VOL_MUTE;
		if (vol != spec->master[ch]) {
			int dac;
			spec->master[ch] = vol;
			for (dac = 0; dac < ice->num_total_dacs; dac += 2)
				wm_set_vol(ice, WM_DAC_ATTEN + dac + ch,
					   spec->vol[dac + ch],
					   spec->master[ch]);
			change = 1;
		}
	}
	snd_ice1712_restore_gpio_status(ice);
	return change;
}

__attribute__((used)) static int phase28_init(struct snd_ice1712 *ice)
{
	static const unsigned short wm_inits_phase28[] = {
		/* These come first to reduce init pop noise */
		0x1b, 0x044,	/* ADC Mux (AC'97 source) */
		0x1c, 0x00B,	/* Out Mux1 (VOUT1 = DAC+AUX, VOUT2 = DAC) */
		0x1d, 0x009,	/* Out Mux2 (VOUT2 = DAC, VOUT3 = DAC) */

		0x18, 0x000,	/* All power-up */

		0x16, 0x122,	/* I2S, normal polarity, 24bit */
		0x17, 0x022,	/* 256fs, slave mode */
		0x00, 0,	/* DAC1 analog mute */
		0x01, 0,	/* DAC2 analog mute */
		0x02, 0,	/* DAC3 analog mute */
		0x03, 0,	/* DAC4 analog mute */
		0x04, 0,	/* DAC5 analog mute */
		0x05, 0,	/* DAC6 analog mute */
		0x06, 0,	/* DAC7 analog mute */
		0x07, 0,	/* DAC8 analog mute */
		0x08, 0x100,	/* master analog mute */
		0x09, 0xff,	/* DAC1 digital full */
		0x0a, 0xff,	/* DAC2 digital full */
		0x0b, 0xff,	/* DAC3 digital full */
		0x0c, 0xff,	/* DAC4 digital full */
		0x0d, 0xff,	/* DAC5 digital full */
		0x0e, 0xff,	/* DAC6 digital full */
		0x0f, 0xff,	/* DAC7 digital full */
		0x10, 0xff,	/* DAC8 digital full */
		0x11, 0x1ff,	/* master digital full */
		0x12, 0x000,	/* phase normal */
		0x13, 0x090,	/* unmute DAC L/R */
		0x14, 0x000,	/* all unmute */
		0x15, 0x000,	/* no deemphasis, no ZFLG */
		0x19, 0x000,	/* -12dB ADC/L */
		0x1a, 0x000,	/* -12dB ADC/R */
		(unsigned short)-1
	};

	unsigned int tmp;
	struct snd_akm4xxx *ak;
	struct phase28_spec *spec;
	const unsigned short *p;
	int i;

	ice->num_total_dacs = 8;
	ice->num_total_adcs = 2;

	spec = kzalloc(sizeof(*spec), GFP_KERNEL);
	if (!spec)
		return -ENOMEM;
	ice->spec = spec;

	/* Initialize analog chips */
	ice->akm = kzalloc(sizeof(struct snd_akm4xxx), GFP_KERNEL);
	ak = ice->akm;
	if (!ak)
		return -ENOMEM;
	ice->akm_codecs = 1;

	snd_ice1712_gpio_set_dir(ice, 0x5fffff); /* fix this for time being */

	/* reset the wm codec as the SPI mode */
	snd_ice1712_save_gpio_status(ice);
	snd_ice1712_gpio_set_mask(ice, ~(PHASE28_WM_RESET|PHASE28_WM_CS|
					PHASE28_HP_SEL));

	tmp = snd_ice1712_gpio_read(ice);
	tmp &= ~PHASE28_WM_RESET;
	snd_ice1712_gpio_write(ice, tmp);
	udelay(1);
	tmp |= PHASE28_WM_CS;
	snd_ice1712_gpio_write(ice, tmp);
	udelay(1);
	tmp |= PHASE28_WM_RESET;
	snd_ice1712_gpio_write(ice, tmp);
	udelay(1);

	p = wm_inits_phase28;
	for (; *p != (unsigned short)-1; p += 2)
		wm_put(ice, p[0], p[1]);

	snd_ice1712_restore_gpio_status(ice);

	spec->master[0] = WM_VOL_MUTE;
	spec->master[1] = WM_VOL_MUTE;
	for (i = 0; i < ice->num_total_dacs; i++) {
		spec->vol[i] = WM_VOL_MUTE;
		wm_set_vol(ice, i, spec->vol[i], spec->master[i % 2]);
	}

	return 0;
}

__attribute__((used)) static int wm_vol_info(struct snd_kcontrol *kcontrol,
			struct snd_ctl_elem_info *uinfo)
{
	int voices = kcontrol->private_value >> 8;
	uinfo->type = SNDRV_CTL_ELEM_TYPE_INTEGER;
	uinfo->count = voices;
	uinfo->value.integer.min = 0;		/* mute (-101dB) */
	uinfo->value.integer.max = 0x7F;	/* 0dB */
	return 0;
}

__attribute__((used)) static int wm_vol_get(struct snd_kcontrol *kcontrol,
			struct snd_ctl_elem_value *ucontrol)
{
	struct snd_ice1712 *ice = snd_kcontrol_chip(kcontrol);
	struct phase28_spec *spec = ice->spec;
	int i, ofs, voices;

	voices = kcontrol->private_value >> 8;
	ofs = kcontrol->private_value & 0xff;
	for (i = 0; i < voices; i++)
		ucontrol->value.integer.value[i] =
			spec->vol[ofs+i] & ~WM_VOL_MUTE;
	return 0;
}

__attribute__((used)) static int wm_vol_put(struct snd_kcontrol *kcontrol,
			struct snd_ctl_elem_value *ucontrol)
{
	struct snd_ice1712 *ice = snd_kcontrol_chip(kcontrol);
	struct phase28_spec *spec = ice->spec;
	int i, idx, ofs, voices;
	int change = 0;

	voices = kcontrol->private_value >> 8;
	ofs = kcontrol->private_value & 0xff;
	snd_ice1712_save_gpio_status(ice);
	for (i = 0; i < voices; i++) {
		unsigned int vol;
		vol = ucontrol->value.integer.value[i];
		if (vol > 0x7f)
			continue;
		vol |= spec->vol[ofs+i] & WM_VOL_MUTE;
		if (vol != spec->vol[ofs+i]) {
			spec->vol[ofs+i] = vol;
			idx  = WM_DAC_ATTEN + ofs + i;
			wm_set_vol(ice, idx, spec->vol[ofs+i],
				   spec->master[i]);
			change = 1;
		}
	}
	snd_ice1712_restore_gpio_status(ice);
	return change;
}

__attribute__((used)) static int wm_mute_info(struct snd_kcontrol *kcontrol,
			struct snd_ctl_elem_info *uinfo) {
	uinfo->type = SNDRV_CTL_ELEM_TYPE_BOOLEAN;
	uinfo->count = kcontrol->private_value >> 8;
	uinfo->value.integer.min = 0;
	uinfo->value.integer.max = 1;
	return 0;
}

__attribute__((used)) static int wm_mute_get(struct snd_kcontrol *kcontrol,
			struct snd_ctl_elem_value *ucontrol)
{
	struct snd_ice1712 *ice = snd_kcontrol_chip(kcontrol);
	struct phase28_spec *spec = ice->spec;
	int voices, ofs, i;

	voices = kcontrol->private_value >> 8;
	ofs = kcontrol->private_value & 0xFF;

	for (i = 0; i < voices; i++)
		ucontrol->value.integer.value[i] =
			(spec->vol[ofs+i] & WM_VOL_MUTE) ? 0 : 1;
	return 0;
}

__attribute__((used)) static int wm_mute_put(struct snd_kcontrol *kcontrol,
			struct snd_ctl_elem_value *ucontrol)
{
	struct snd_ice1712 *ice = snd_kcontrol_chip(kcontrol);
	struct phase28_spec *spec = ice->spec;
	int change = 0, voices, ofs, i;

	voices = kcontrol->private_value >> 8;
	ofs = kcontrol->private_value & 0xFF;

	snd_ice1712_save_gpio_status(ice);
	for (i = 0; i < voices; i++) {
		int val = (spec->vol[ofs + i] & WM_VOL_MUTE) ? 0 : 1;
		if (ucontrol->value.integer.value[i] != val) {
			spec->vol[ofs + i] &= ~WM_VOL_MUTE;
			spec->vol[ofs + i] |=
				ucontrol->value.integer.value[i] ? 0 :
				WM_VOL_MUTE;
			wm_set_vol(ice, ofs + i, spec->vol[ofs + i],
					spec->master[i]);
			change = 1;
		}
	}
	snd_ice1712_restore_gpio_status(ice);

	return change;
}

__attribute__((used)) static int wm_master_mute_get(struct snd_kcontrol *kcontrol,
				struct snd_ctl_elem_value *ucontrol)
{
	struct snd_ice1712 *ice = snd_kcontrol_chip(kcontrol);
	struct phase28_spec *spec = ice->spec;

	ucontrol->value.integer.value[0] =
		(spec->master[0] & WM_VOL_MUTE) ? 0 : 1;
	ucontrol->value.integer.value[1] =
		(spec->master[1] & WM_VOL_MUTE) ? 0 : 1;
	return 0;
}

__attribute__((used)) static int wm_master_mute_put(struct snd_kcontrol *kcontrol,
				struct snd_ctl_elem_value *ucontrol)
{
	struct snd_ice1712 *ice = snd_kcontrol_chip(kcontrol);
	struct phase28_spec *spec = ice->spec;
	int change = 0, i;

	snd_ice1712_save_gpio_status(ice);
	for (i = 0; i < 2; i++) {
		int val = (spec->master[i] & WM_VOL_MUTE) ? 0 : 1;
		if (ucontrol->value.integer.value[i] != val) {
			int dac;
			spec->master[i] &= ~WM_VOL_MUTE;
			spec->master[i] |=
				ucontrol->value.integer.value[i] ? 0 :
				WM_VOL_MUTE;
			for (dac = 0; dac < ice->num_total_dacs; dac += 2)
				wm_set_vol(ice, WM_DAC_ATTEN + dac + i,
						spec->vol[dac + i],
						spec->master[i]);
			change = 1;
		}
	}
	snd_ice1712_restore_gpio_status(ice);

	return change;
}

__attribute__((used)) static int wm_pcm_vol_info(struct snd_kcontrol *kcontrol,
				struct snd_ctl_elem_info *uinfo)
{
	uinfo->type = SNDRV_CTL_ELEM_TYPE_INTEGER;
	uinfo->count = 1;
	uinfo->value.integer.min = 0;		/* mute (-64dB) */
	uinfo->value.integer.max = PCM_RES;	/* 0dB */
	return 0;
}

__attribute__((used)) static int wm_pcm_vol_get(struct snd_kcontrol *kcontrol,
				struct snd_ctl_elem_value *ucontrol)
{
	struct snd_ice1712 *ice = snd_kcontrol_chip(kcontrol);
	unsigned short val;

	mutex_lock(&ice->gpio_mutex);
	val = wm_get(ice, WM_DAC_DIG_MASTER_ATTEN) & 0xff;
	val = val > PCM_MIN ? (val - PCM_MIN) : 0;
	ucontrol->value.integer.value[0] = val;
	mutex_unlock(&ice->gpio_mutex);
	return 0;
}

__attribute__((used)) static int wm_pcm_vol_put(struct snd_kcontrol *kcontrol,
				struct snd_ctl_elem_value *ucontrol)
{
	struct snd_ice1712 *ice = snd_kcontrol_chip(kcontrol);
	unsigned short ovol, nvol;
	int change = 0;

	nvol = ucontrol->value.integer.value[0];
	if (nvol > PCM_RES)
		return -EINVAL;
	snd_ice1712_save_gpio_status(ice);
	nvol = (nvol ? (nvol + PCM_MIN) : 0) & 0xff;
	ovol = wm_get(ice, WM_DAC_DIG_MASTER_ATTEN) & 0xff;
	if (ovol != nvol) {
		wm_put(ice, WM_DAC_DIG_MASTER_ATTEN, nvol); /* prelatch */
		/* update */
		wm_put_nocache(ice, WM_DAC_DIG_MASTER_ATTEN, nvol | 0x100);
		change = 1;
	}
	snd_ice1712_restore_gpio_status(ice);
	return change;
}

__attribute__((used)) static int phase28_deemp_get(struct snd_kcontrol *kcontrol,
				struct snd_ctl_elem_value *ucontrol)
{
	struct snd_ice1712 *ice = snd_kcontrol_chip(kcontrol);
	ucontrol->value.integer.value[0] = (wm_get(ice, WM_DAC_CTRL2) & 0xf) ==
						0xf;
	return 0;
}

__attribute__((used)) static int phase28_deemp_put(struct snd_kcontrol *kcontrol,
				struct snd_ctl_elem_value *ucontrol)
{
	struct snd_ice1712 *ice = snd_kcontrol_chip(kcontrol);
	int temp, temp2;
	temp = wm_get(ice, WM_DAC_CTRL2);
	temp2 = temp;
	if (ucontrol->value.integer.value[0])
		temp |= 0xf;
	else
		temp &= ~0xf;
	if (temp != temp2) {
		wm_put(ice, WM_DAC_CTRL2, temp);
		return 1;
	}
	return 0;
}

__attribute__((used)) static int phase28_oversampling_info(struct snd_kcontrol *k,
					struct snd_ctl_elem_info *uinfo)
{
	static const char * const texts[2] = { "128x", "64x"	};

	return snd_ctl_enum_info(uinfo, 1, 2, texts);
}

__attribute__((used)) static int phase28_oversampling_get(struct snd_kcontrol *kcontrol,
					struct snd_ctl_elem_value *ucontrol)
{
	struct snd_ice1712 *ice = snd_kcontrol_chip(kcontrol);
	ucontrol->value.enumerated.item[0] = (wm_get(ice, WM_MASTER) & 0x8) ==
						0x8;
	return 0;
}

__attribute__((used)) static int phase28_oversampling_put(struct snd_kcontrol *kcontrol,
					struct snd_ctl_elem_value *ucontrol)
{
	int temp, temp2;
	struct snd_ice1712 *ice = snd_kcontrol_chip(kcontrol);

	temp = wm_get(ice, WM_MASTER);
	temp2 = temp;

	if (ucontrol->value.enumerated.item[0])
		temp |= 0x8;
	else
		temp &= ~0x8;

	if (temp != temp2) {
		wm_put(ice, WM_MASTER, temp);
		return 1;
	}
	return 0;
}

__attribute__((used)) static int phase28_add_controls(struct snd_ice1712 *ice)
{
	unsigned int i, counts;
	int err;

	counts = ARRAY_SIZE(phase28_dac_controls);
	for (i = 0; i < counts; i++) {
		err = snd_ctl_add(ice->card,
					snd_ctl_new1(&phase28_dac_controls[i],
							ice));
		if (err < 0)
			return err;
	}

	for (i = 0; i < ARRAY_SIZE(wm_controls); i++) {
		err = snd_ctl_add(ice->card,
					snd_ctl_new1(&wm_controls[i], ice));
		if (err < 0)
			return err;
	}

	return 0;
}

