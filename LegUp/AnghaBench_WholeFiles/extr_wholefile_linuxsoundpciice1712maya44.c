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
struct snd_wm8776 {unsigned int addr; unsigned short* regs; unsigned int** volumes; unsigned int switch_bits; } ;
struct snd_maya44 {struct snd_wm8776* wm; struct snd_ice1712* ice; int /*<<< orphan*/  mutex; } ;
struct snd_kcontrol {unsigned int private_value; } ;
struct TYPE_12__ {unsigned int (* get_dir ) (struct snd_ice1712*) ;unsigned int (* get_data ) (struct snd_ice1712*) ;unsigned int* saved; unsigned int direction; unsigned int write_mask; void (* set_pro_rate ) (struct snd_ice1712*,unsigned int) ;int /*<<< orphan*/  (* set_mask ) (struct snd_ice1712*,unsigned int) ;int /*<<< orphan*/  (* set_dir ) (struct snd_ice1712*,unsigned int) ;int /*<<< orphan*/  (* set_data ) (struct snd_ice1712*,unsigned int) ;} ;
struct snd_ice1712 {int num_total_dacs; int num_total_adcs; int force_rdma1; int own_routing; TYPE_6__ gpio; int /*<<< orphan*/ * hw_rates; scalar_t__ akm_codecs; struct snd_maya44* spec; int /*<<< orphan*/  card; int /*<<< orphan*/  gpio_mutex; } ;
struct TYPE_10__ {int* item; } ;
struct TYPE_9__ {unsigned int* value; } ;
struct TYPE_11__ {TYPE_4__ enumerated; TYPE_3__ integer; } ;
struct snd_ctl_elem_value {TYPE_5__ value; int /*<<< orphan*/  id; } ;
struct TYPE_7__ {unsigned int max; scalar_t__ min; } ;
struct TYPE_8__ {TYPE_1__ integer; } ;
struct snd_ctl_elem_info {int count; TYPE_2__ value; int /*<<< orphan*/  type; } ;
struct maya_vol_info {unsigned int maxval; unsigned int mute; unsigned int offset; unsigned int update; unsigned char* regs; unsigned short mask; short* mux_bits; } ;

/* Variables and functions */
 int ARRAY_SIZE (char const* const*) ; 
 int /*<<< orphan*/  DATA ; 
 int ENOMEM ; 
 scalar_t__ GET_GPIO_VAL_INV (unsigned int) ; 
 unsigned int GET_GPIO_VAL_SHIFT (unsigned int) ; 
 unsigned int GET_SW_VAL_IDX (unsigned int) ; 
 unsigned int GET_SW_VAL_MASK (unsigned int) ; 
 unsigned char GET_SW_VAL_REG (unsigned int) ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int GPIO_MIC_RELAY ; 
 int /*<<< orphan*/  ICEREG (struct snd_ice1712*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  INDEX ; 
 int MAYA_LINE_IN ; 
 int MAYA_MIC_IN ; 
 int /*<<< orphan*/  SNDRV_CTL_ELEM_TYPE_INTEGER ; 
 unsigned int WM8776_CLOCK_RATIO_128FS ; 
 unsigned int WM8776_CLOCK_RATIO_256FS ; 
 unsigned int WM8776_CLOCK_RATIO_384FS ; 
 unsigned int WM8776_CLOCK_RATIO_512FS ; 
 unsigned int WM8776_CLOCK_RATIO_768FS ; 
 unsigned char WM8776_REG_ADC_MUX ; 
 unsigned char WM8776_REG_MASTER_MODE_CONTROL ; 
 int WM_SW_DAC ; 
 int /*<<< orphan*/  dac_rates ; 
 int /*<<< orphan*/  inb (int /*<<< orphan*/ ) ; 
 struct snd_maya44* kzalloc (int,int /*<<< orphan*/ ) ; 
 char const* const* maya_controls ; 
 int /*<<< orphan*/  mutex_init (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  outb (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  snd_BUG () ; 
 int snd_ctl_add (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int snd_ctl_enum_info (struct snd_ctl_elem_info*,int,int,char const* const*) ; 
 size_t snd_ctl_get_ioff (struct snd_kcontrol*,int /*<<< orphan*/ *) ; 
 int snd_ctl_get_ioffidx (struct snd_kcontrol*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  snd_ctl_new1 (char const* const*,struct snd_maya44*) ; 
 int snd_ice1724_get_route_val (struct snd_ice1712*,int) ; 
 int snd_ice1724_put_route_val (struct snd_ice1712*,int,int) ; 
 struct snd_maya44* snd_kcontrol_chip (struct snd_kcontrol*) ; 
 int /*<<< orphan*/  snd_vt1724_write_i2c (struct snd_ice1712*,unsigned int,unsigned char,unsigned short) ; 
 int /*<<< orphan*/  stub1 (struct snd_ice1712*,unsigned int) ; 
 unsigned int stub2 (struct snd_ice1712*) ; 
 int /*<<< orphan*/  stub3 (struct snd_ice1712*,unsigned int) ; 
 int /*<<< orphan*/  stub4 (struct snd_ice1712*,unsigned int) ; 
 unsigned int stub5 (struct snd_ice1712*) ; 
 int /*<<< orphan*/  stub6 (struct snd_ice1712*,unsigned int) ; 
 int /*<<< orphan*/  stub7 (struct snd_ice1712*,unsigned int) ; 
 struct maya_vol_info* vol_info ; 
 unsigned int* wm8776_addr ; 

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

__attribute__((used)) static void wm8776_write(struct snd_ice1712 *ice, struct snd_wm8776 *wm,
			 unsigned char reg, unsigned short val)
{
	/*
	 * WM8776 registers are up to 9 bits wide, bit 8 is placed in the LSB
	 * of the address field
	 */
	snd_vt1724_write_i2c(ice, wm->addr,
			     (reg << 1) | ((val >> 8) & 1),
			     val & 0xff);
	wm->regs[reg] = val;
}

__attribute__((used)) static int wm8776_write_bits(struct snd_ice1712 *ice, struct snd_wm8776 *wm,
			     unsigned char reg,
			     unsigned short mask, unsigned short val)
{
	val |= wm->regs[reg] & ~mask;
	if (val != wm->regs[reg]) {
		wm8776_write(ice, wm, reg, val);
		return 1;
	}
	return 0;
}

__attribute__((used)) static int maya_vol_info(struct snd_kcontrol *kcontrol,
			 struct snd_ctl_elem_info *uinfo)
{
	unsigned int idx = kcontrol->private_value;
	struct maya_vol_info *vol = &vol_info[idx];

	uinfo->type = SNDRV_CTL_ELEM_TYPE_INTEGER;
	uinfo->count = 2;
	uinfo->value.integer.min = 0;
	uinfo->value.integer.max = vol->maxval;
	return 0;
}

__attribute__((used)) static int maya_vol_get(struct snd_kcontrol *kcontrol,
			struct snd_ctl_elem_value *ucontrol)
{
	struct snd_maya44 *chip = snd_kcontrol_chip(kcontrol);
	struct snd_wm8776 *wm =
		&chip->wm[snd_ctl_get_ioff(kcontrol, &ucontrol->id)];
	unsigned int idx = kcontrol->private_value;

	mutex_lock(&chip->mutex);
	ucontrol->value.integer.value[0] = wm->volumes[idx][0];
	ucontrol->value.integer.value[1] = wm->volumes[idx][1];
	mutex_unlock(&chip->mutex);
	return 0;
}

__attribute__((used)) static int maya_vol_put(struct snd_kcontrol *kcontrol,
			struct snd_ctl_elem_value *ucontrol)
{
	struct snd_maya44 *chip = snd_kcontrol_chip(kcontrol);
	struct snd_wm8776 *wm =
		&chip->wm[snd_ctl_get_ioff(kcontrol, &ucontrol->id)];
	unsigned int idx = kcontrol->private_value;
	struct maya_vol_info *vol = &vol_info[idx];
	unsigned int val, data;
	int ch, changed = 0;

	mutex_lock(&chip->mutex);
	for (ch = 0; ch < 2; ch++) {
		val = ucontrol->value.integer.value[ch];
		if (val > vol->maxval)
			val = vol->maxval;
		if (val == wm->volumes[idx][ch])
			continue;
		if (!val)
			data = vol->mute;
		else
			data = (val - 1) + vol->offset;
		data |= vol->update;
		changed |= wm8776_write_bits(chip->ice, wm, vol->regs[ch],
					     vol->mask | vol->update, data);
		if (vol->mux_bits[ch])
			wm8776_write_bits(chip->ice, wm, WM8776_REG_ADC_MUX,
					  vol->mux_bits[ch],
					  val ? 0 : vol->mux_bits[ch]);
		wm->volumes[idx][ch] = val;
	}
	mutex_unlock(&chip->mutex);
	return changed;
}

__attribute__((used)) static int maya_sw_get(struct snd_kcontrol *kcontrol,
		       struct snd_ctl_elem_value *ucontrol)
{
	struct snd_maya44 *chip = snd_kcontrol_chip(kcontrol);
	struct snd_wm8776 *wm =
		&chip->wm[snd_ctl_get_ioff(kcontrol, &ucontrol->id)];
	unsigned int idx = GET_SW_VAL_IDX(kcontrol->private_value);

	ucontrol->value.integer.value[0] = (wm->switch_bits >> idx) & 1;
	return 0;
}

__attribute__((used)) static int maya_sw_put(struct snd_kcontrol *kcontrol,
		       struct snd_ctl_elem_value *ucontrol)
{
	struct snd_maya44 *chip = snd_kcontrol_chip(kcontrol);
	struct snd_wm8776 *wm =
		&chip->wm[snd_ctl_get_ioff(kcontrol, &ucontrol->id)];
	unsigned int idx = GET_SW_VAL_IDX(kcontrol->private_value);
	unsigned int mask, val;
	int changed;

	mutex_lock(&chip->mutex);
	mask = 1 << idx;
	wm->switch_bits &= ~mask;
	val = ucontrol->value.integer.value[0];
	if (val)
		wm->switch_bits |= mask;
	mask = GET_SW_VAL_MASK(kcontrol->private_value);
	changed = wm8776_write_bits(chip->ice, wm,
				    GET_SW_VAL_REG(kcontrol->private_value),
				    mask, val ? mask : 0);
	mutex_unlock(&chip->mutex);
	return changed;
}

__attribute__((used)) static int maya_set_gpio_bits(struct snd_ice1712 *ice, unsigned int mask,
			      unsigned int bits)
{
	unsigned int data;
	data = snd_ice1712_gpio_read(ice);
	if ((data & mask) == bits)
		return 0;
	snd_ice1712_gpio_write(ice, (data & ~mask) | bits);
	return 1;
}

__attribute__((used)) static int maya_gpio_sw_get(struct snd_kcontrol *kcontrol,
			    struct snd_ctl_elem_value *ucontrol)
{
	struct snd_maya44 *chip = snd_kcontrol_chip(kcontrol);
	unsigned int shift = GET_GPIO_VAL_SHIFT(kcontrol->private_value);
	unsigned int val;

	val = (snd_ice1712_gpio_read(chip->ice) >> shift) & 1;
	if (GET_GPIO_VAL_INV(kcontrol->private_value))
		val = !val;
	ucontrol->value.integer.value[0] = val;
	return 0;
}

__attribute__((used)) static int maya_gpio_sw_put(struct snd_kcontrol *kcontrol,
			    struct snd_ctl_elem_value *ucontrol)
{
	struct snd_maya44 *chip = snd_kcontrol_chip(kcontrol);
	unsigned int shift = GET_GPIO_VAL_SHIFT(kcontrol->private_value);
	unsigned int val, mask;
	int changed;

	mutex_lock(&chip->mutex);
	mask = 1 << shift;
	val = ucontrol->value.integer.value[0];
	if (GET_GPIO_VAL_INV(kcontrol->private_value))
		val = !val;
	val = val ? mask : 0;
	changed = maya_set_gpio_bits(chip->ice, mask, val);
	mutex_unlock(&chip->mutex);
	return changed;
}

__attribute__((used)) static void wm8776_select_input(struct snd_maya44 *chip, int idx, int line)
{
	wm8776_write_bits(chip->ice, &chip->wm[idx], WM8776_REG_ADC_MUX,
			  0x1f, 1 << line);
}

__attribute__((used)) static int maya_rec_src_info(struct snd_kcontrol *kcontrol,
			     struct snd_ctl_elem_info *uinfo)
{
	static const char * const texts[] = { "Line", "Mic" };

	return snd_ctl_enum_info(uinfo, 1, ARRAY_SIZE(texts), texts);
}

__attribute__((used)) static int maya_rec_src_get(struct snd_kcontrol *kcontrol,
			    struct snd_ctl_elem_value *ucontrol)
{
	struct snd_maya44 *chip = snd_kcontrol_chip(kcontrol);
	int sel;

	if (snd_ice1712_gpio_read(chip->ice) & (1 << GPIO_MIC_RELAY))
		sel = 1;
	else
		sel = 0;
	ucontrol->value.enumerated.item[0] = sel;
	return 0;
}

__attribute__((used)) static int maya_rec_src_put(struct snd_kcontrol *kcontrol,
			    struct snd_ctl_elem_value *ucontrol)
{
	struct snd_maya44 *chip = snd_kcontrol_chip(kcontrol);
	int sel = ucontrol->value.enumerated.item[0];
	int changed;

	mutex_lock(&chip->mutex);
	changed = maya_set_gpio_bits(chip->ice, 1 << GPIO_MIC_RELAY,
				     sel ? (1 << GPIO_MIC_RELAY) : 0);
	wm8776_select_input(chip, 0, sel ? MAYA_MIC_IN : MAYA_LINE_IN);
	mutex_unlock(&chip->mutex);
	return changed;
}

__attribute__((used)) static int maya_pb_route_info(struct snd_kcontrol *kcontrol,
			      struct snd_ctl_elem_info *uinfo)
{
	static const char * const texts[] = {
		"PCM Out", /* 0 */
		"Input 1", "Input 2", "Input 3", "Input 4"
	};

	return snd_ctl_enum_info(uinfo, 1, ARRAY_SIZE(texts), texts);
}

__attribute__((used)) static int maya_pb_route_shift(int idx)
{
	static const unsigned char shift[10] =
		{ 8, 20, 0, 3, 11, 23, 14, 26, 17, 29 };
	return shift[idx % 10];
}

__attribute__((used)) static int maya_pb_route_get(struct snd_kcontrol *kcontrol,
			     struct snd_ctl_elem_value *ucontrol)
{
	struct snd_maya44 *chip = snd_kcontrol_chip(kcontrol);
	int idx = snd_ctl_get_ioffidx(kcontrol, &ucontrol->id);
	ucontrol->value.enumerated.item[0] =
		snd_ice1724_get_route_val(chip->ice, maya_pb_route_shift(idx));
	return 0;
}

__attribute__((used)) static int maya_pb_route_put(struct snd_kcontrol *kcontrol,
			     struct snd_ctl_elem_value *ucontrol)
{
	struct snd_maya44 *chip = snd_kcontrol_chip(kcontrol);
	int idx = snd_ctl_get_ioffidx(kcontrol, &ucontrol->id);
	return snd_ice1724_put_route_val(chip->ice,
					 ucontrol->value.enumerated.item[0],
					 maya_pb_route_shift(idx));
}

__attribute__((used)) static int maya44_add_controls(struct snd_ice1712 *ice)
{
	int err, i;

	for (i = 0; i < ARRAY_SIZE(maya_controls); i++) {
		err = snd_ctl_add(ice->card, snd_ctl_new1(&maya_controls[i],
							  ice->spec));
		if (err < 0)
			return err;
	}
	return 0;
}

__attribute__((used)) static void wm8776_init(struct snd_ice1712 *ice,
			struct snd_wm8776 *wm, unsigned int addr)
{
	static const unsigned short inits_wm8776[] = {
		0x02, 0x100, /* R2: headphone L+R muted + update */
		0x05, 0x100, /* R5: DAC output L+R muted + update */
		0x06, 0x000, /* R6: DAC output phase normal */
		0x07, 0x091, /* R7: DAC enable zero cross detection,
				normal output */
		0x08, 0x000, /* R8: DAC soft mute off */
		0x09, 0x000, /* R9: no deemph, DAC zero detect disabled */
		0x0a, 0x022, /* R10: DAC I2C mode, std polarities, 24bit */
		0x0b, 0x022, /* R11: ADC I2C mode, std polarities, 24bit,
				highpass filter enabled */
		0x0c, 0x042, /* R12: ADC+DAC slave, ADC+DAC 44,1kHz */
		0x0d, 0x000, /* R13: all power up */
		0x0e, 0x100, /* R14: ADC left muted,
				enable zero cross detection */
		0x0f, 0x100, /* R15: ADC right muted,
				enable zero cross detection */
			     /* R16: ALC...*/
		0x11, 0x000, /* R17: disable ALC */
			     /* R18: ALC...*/
			     /* R19: noise gate...*/
		0x15, 0x000, /* R21: ADC input mux init, mute all inputs */
		0x16, 0x001, /* R22: output mux, select DAC */
		0xff, 0xff
	};

	const unsigned short *ptr;
	unsigned char reg;
	unsigned short data;

	wm->addr = addr;
	/* enable DAC output; mute bypass, aux & all inputs */
	wm->switch_bits = (1 << WM_SW_DAC);

	ptr = inits_wm8776;
	while (*ptr != 0xff) {
		reg = *ptr++;
		data = *ptr++;
		wm8776_write(ice, wm, reg, data);
	}
}

__attribute__((used)) static void set_rate(struct snd_ice1712 *ice, unsigned int rate)
{
	struct snd_maya44 *chip = ice->spec;
	unsigned int ratio, adc_ratio, val;
	int i;

	switch (rate) {
	case 192000:
		ratio = WM8776_CLOCK_RATIO_128FS;
		break;
	case 176400:
		ratio = WM8776_CLOCK_RATIO_128FS;
		break;
	case 96000:
		ratio = WM8776_CLOCK_RATIO_256FS;
		break;
	case 88200:
		ratio = WM8776_CLOCK_RATIO_384FS;
		break;
	case 48000:
		ratio = WM8776_CLOCK_RATIO_512FS;
		break;
	case 44100:
		ratio = WM8776_CLOCK_RATIO_512FS;
		break;
	case 32000:
		ratio = WM8776_CLOCK_RATIO_768FS;
		break;
	case 0:
		/* no hint - S/PDIF input is master, simply return */
		return;
	default:
		snd_BUG();
		return;
	}

	/*
	 * this currently sets the same rate for ADC and DAC, but limits
	 * ADC rate to 256X (96kHz). For 256X mode (96kHz), this sets ADC
	 * oversampling to 64x, as recommended by WM8776 datasheet.
	 * Setting the rate is not really necessary in slave mode.
	 */
	adc_ratio = ratio;
	if (adc_ratio < WM8776_CLOCK_RATIO_256FS)
		adc_ratio = WM8776_CLOCK_RATIO_256FS;

	val = adc_ratio;
	if (adc_ratio == WM8776_CLOCK_RATIO_256FS)
		val |= 8;
	val |= ratio << 4;

	mutex_lock(&chip->mutex);
	for (i = 0; i < 2; i++)
		wm8776_write_bits(ice, &chip->wm[i],
				  WM8776_REG_MASTER_MODE_CONTROL,
				  0x180, val);
	mutex_unlock(&chip->mutex);
}

__attribute__((used)) static int maya44_init(struct snd_ice1712 *ice)
{
	int i;
	struct snd_maya44 *chip;

	chip = kzalloc(sizeof(*chip), GFP_KERNEL);
	if (!chip)
		return -ENOMEM;
	mutex_init(&chip->mutex);
	chip->ice = ice;
	ice->spec = chip;

	/* initialise codecs */
	ice->num_total_dacs = 4;
	ice->num_total_adcs = 4;
	ice->akm_codecs = 0;

	for (i = 0; i < 2; i++) {
		wm8776_init(ice, &chip->wm[i], wm8776_addr[i]);
		wm8776_select_input(chip, i, MAYA_LINE_IN);
	}

	/* set card specific rates */
	ice->hw_rates = &dac_rates;

	/* register change rate notifier */
	ice->gpio.set_pro_rate = set_rate;

	/* RDMA1 (2nd input channel) is used for ADC by default */
	ice->force_rdma1 = 1;

	/* have an own routing control */
	ice->own_routing = 1;

	return 0;
}

