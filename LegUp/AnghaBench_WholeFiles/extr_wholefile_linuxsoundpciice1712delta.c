#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_22__   TYPE_9__ ;
typedef  struct TYPE_21__   TYPE_8__ ;
typedef  struct TYPE_20__   TYPE_7__ ;
typedef  struct TYPE_19__   TYPE_6__ ;
typedef  struct TYPE_18__   TYPE_5__ ;
typedef  struct TYPE_17__   TYPE_4__ ;
typedef  struct TYPE_16__   TYPE_3__ ;
typedef  struct TYPE_15__   TYPE_2__ ;
typedef  struct TYPE_14__   TYPE_1__ ;
typedef  struct TYPE_13__   TYPE_10__ ;

/* Type definitions */
typedef  unsigned char u8 ;
struct snd_pcm_substream {int dummy; } ;
struct snd_kcontrol {int dummy; } ;
struct TYPE_21__ {int subvendor; int gpiodir; } ;
struct TYPE_19__ {void (* open ) (struct snd_ice1712*,struct snd_pcm_substream*) ;void (* setup_rate ) (struct snd_ice1712*,int) ;void (* default_get ) (struct snd_ice1712*,struct snd_ctl_elem_value*) ;int (* default_put ) (struct snd_ice1712*,struct snd_ctl_elem_value*) ;void (* stream_get ) (struct snd_ice1712*,struct snd_ctl_elem_value*) ;int (* stream_put ) (struct snd_ice1712*,struct snd_ctl_elem_value*) ;} ;
struct TYPE_20__ {unsigned int cs8403_bits; unsigned int cs8403_stream_bits; TYPE_6__ ops; TYPE_2__* stream_ctl; } ;
struct TYPE_18__ {unsigned int (* get_dir ) (struct snd_ice1712*) ;unsigned int (* get_data ) (struct snd_ice1712*) ;unsigned int* saved; unsigned int direction; unsigned int write_mask; void (* set_pro_rate ) (struct snd_ice1712*,unsigned int) ;int /*<<< orphan*/  (* set_mask ) (struct snd_ice1712*,unsigned int) ;int /*<<< orphan*/  (* set_dir ) (struct snd_ice1712*,unsigned int) ;int /*<<< orphan*/  (* set_data ) (struct snd_ice1712*,unsigned int) ;} ;
struct snd_ice1712 {int num_total_dacs; int num_total_adcs; int akm_codecs; TYPE_8__ eeprom; TYPE_9__* card; struct snd_akm4xxx* akm; TYPE_7__ spdif; TYPE_5__ gpio; TYPE_10__* i2c; int /*<<< orphan*/  omni; int /*<<< orphan*/  cs8427; int /*<<< orphan*/  reg_lock; int /*<<< orphan*/  gpio_mutex; int /*<<< orphan*/ * playback_pro_substream; } ;
struct snd_i2c_device {int addr; TYPE_1__* bus; } ;
struct snd_i2c_bus {int dummy; } ;
struct TYPE_16__ {int* value; } ;
struct TYPE_17__ {TYPE_3__ integer; int /*<<< orphan*/  iec958; } ;
struct snd_ctl_elem_value {TYPE_4__ value; } ;
struct snd_akm4xxx {struct snd_ice1712** private_data; scalar_t__* private_value; } ;
struct snd_ak4xxx_private {int cs_mask; int cs_addr; } ;
struct TYPE_22__ {int /*<<< orphan*/  dev; } ;
struct TYPE_15__ {int /*<<< orphan*/  id; } ;
struct TYPE_14__ {struct snd_ice1712* private_data; } ;
struct TYPE_13__ {int /*<<< orphan*/ * ops; struct snd_ice1712* private_data; } ;

/* Variables and functions */
 int /*<<< orphan*/  CS8427_BASE_ADDR ; 
 char CS8427_UNLOCK ; 
 int /*<<< orphan*/  DATA ; 
 int EINVAL ; 
 int ENOENT ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 unsigned char ICE1712_DELTA_1010LT_CCLK ; 
 unsigned char ICE1712_DELTA_1010LT_CS ; 
 unsigned char ICE1712_DELTA_1010LT_CS_CS8427 ; 
 unsigned char ICE1712_DELTA_1010LT_CS_NONE ; 
 unsigned char ICE1712_DELTA_66E_CCLK ; 
 unsigned char ICE1712_DELTA_66E_CS_CHIP_A ; 
 unsigned char ICE1712_DELTA_66E_CS_CHIP_B ; 
 unsigned char ICE1712_DELTA_66E_CS_CS8427 ; 
 unsigned char ICE1712_DELTA_AP_CCLK ; 
 unsigned char ICE1712_DELTA_AP_CS_CODEC ; 
 unsigned char ICE1712_DELTA_AP_CS_DIGITAL ; 
 int ICE1712_DELTA_AP_DIN ; 
 unsigned char ICE1712_DELTA_AP_DOUT ; 
 int ICE1712_DELTA_CODEC_CHIP_A ; 
 int ICE1712_DELTA_CODEC_CHIP_B ; 
 unsigned char ICE1712_DELTA_DFS ; 
 unsigned char ICE1712_DELTA_SPDIF_OUT_STAT_CLOCK ; 
 unsigned char ICE1712_DELTA_SPDIF_OUT_STAT_DATA ; 
 unsigned char ICE1712_IREG_GPIO_DATA ; 
#define  ICE1712_SUBDEVICE_AUDIOPHILE 139 
#define  ICE1712_SUBDEVICE_DELTA1010 138 
#define  ICE1712_SUBDEVICE_DELTA1010E 137 
#define  ICE1712_SUBDEVICE_DELTA1010LT 136 
#define  ICE1712_SUBDEVICE_DELTA410 135 
#define  ICE1712_SUBDEVICE_DELTA44 134 
#define  ICE1712_SUBDEVICE_DELTA66 133 
#define  ICE1712_SUBDEVICE_DELTA66E 132 
#define  ICE1712_SUBDEVICE_DELTADIO2496 131 
#define  ICE1712_SUBDEVICE_EDIROLDA2496 130 
#define  ICE1712_SUBDEVICE_MEDIASTATION 129 
#define  ICE1712_SUBDEVICE_VX442 128 
 unsigned char ICE1712_VX442_CCLK ; 
 unsigned char ICE1712_VX442_CODEC_CHIP_A ; 
 unsigned char ICE1712_VX442_CODEC_CHIP_B ; 
 unsigned char ICE1712_VX442_CS_DIGITAL ; 
 int /*<<< orphan*/  ICEREG (struct snd_ice1712*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  INDEX ; 
 int /*<<< orphan*/  SNDRV_CTL_EVENT_MASK_VALUE ; 
 int /*<<< orphan*/  akm_audiophile ; 
 int /*<<< orphan*/  akm_audiophile_priv ; 
 int /*<<< orphan*/  akm_delta1010lt ; 
 int /*<<< orphan*/  akm_delta1010lt_priv ; 
 int /*<<< orphan*/  akm_delta410 ; 
 int /*<<< orphan*/  akm_delta410_priv ; 
 int /*<<< orphan*/  akm_delta44 ; 
 int /*<<< orphan*/  akm_delta44_priv ; 
 int /*<<< orphan*/  akm_delta66e ; 
 int /*<<< orphan*/  akm_delta66e_priv ; 
 int /*<<< orphan*/  akm_vx442 ; 
 int /*<<< orphan*/  akm_vx442_priv ; 
 int /*<<< orphan*/  ap_cs8427_i2c_ops ; 
 int /*<<< orphan*/  dev_err (int /*<<< orphan*/ ,char*,...) ; 
 unsigned char inb (int /*<<< orphan*/ ) ; 
 struct snd_akm4xxx* kmalloc (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  outb (unsigned char,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  snd_BUG () ; 
 unsigned char snd_akm4xxx_get (struct snd_akm4xxx*,int,int) ; 
 int /*<<< orphan*/  snd_akm4xxx_reset (struct snd_akm4xxx*,int) ; 
 int /*<<< orphan*/  snd_akm4xxx_write (struct snd_akm4xxx*,int,int,unsigned char) ; 
 int /*<<< orphan*/  snd_cs8403_decode_spdif_bits (int /*<<< orphan*/ *,unsigned int) ; 
 unsigned int snd_cs8403_encode_spdif_bits (int /*<<< orphan*/ *) ; 
 int snd_ctl_add (TYPE_9__*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  snd_ctl_new1 (int /*<<< orphan*/ *,struct snd_ice1712*) ; 
 int /*<<< orphan*/  snd_ctl_notify (TYPE_9__*,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int snd_i2c_bus_create (TYPE_9__*,char*,int /*<<< orphan*/ *,TYPE_10__**) ; 
 int /*<<< orphan*/  snd_i2c_readbytes (int /*<<< orphan*/ ,char*,int) ; 
 int snd_i2c_sendbytes (int /*<<< orphan*/ ,char*,int) ; 
 int snd_ice1712_akm4xxx_build_controls (struct snd_ice1712*) ; 
 int snd_ice1712_akm4xxx_init (struct snd_akm4xxx*,int /*<<< orphan*/ *,int /*<<< orphan*/ *,struct snd_ice1712*) ; 
 int /*<<< orphan*/  snd_ice1712_delta1010_wordclock_select ; 
 int /*<<< orphan*/  snd_ice1712_delta1010_wordclock_status ; 
 int /*<<< orphan*/  snd_ice1712_delta1010lt_wordclock_select ; 
 int /*<<< orphan*/  snd_ice1712_delta1010lt_wordclock_status ; 
 int /*<<< orphan*/  snd_ice1712_delta_spdif_in_status ; 
 int /*<<< orphan*/  snd_ice1712_deltadio2496_spdif_in_select ; 
 int snd_ice1712_init_cs8427 (struct snd_ice1712*,int /*<<< orphan*/ ) ; 
 int snd_ice1712_spdif_build_controls (struct snd_ice1712*) ; 
 struct snd_ice1712* snd_kcontrol_chip (struct snd_kcontrol*) ; 
 int /*<<< orphan*/  spin_lock_irq (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  spin_lock_irqsave (int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  spin_unlock_irq (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  spin_unlock_irqrestore (int /*<<< orphan*/ *,unsigned long) ; 
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

__attribute__((used)) static void ap_cs8427_write_byte(struct snd_ice1712 *ice, unsigned char data, unsigned char tmp)
{
	int idx;

	for (idx = 7; idx >= 0; idx--) {
		tmp &= ~(ICE1712_DELTA_AP_DOUT|ICE1712_DELTA_AP_CCLK);
		if (data & (1 << idx))
			tmp |= ICE1712_DELTA_AP_DOUT;
		snd_ice1712_write(ice, ICE1712_IREG_GPIO_DATA, tmp);
		udelay(5);
		tmp |= ICE1712_DELTA_AP_CCLK;
		snd_ice1712_write(ice, ICE1712_IREG_GPIO_DATA, tmp);
		udelay(5);
	}
}

__attribute__((used)) static unsigned char ap_cs8427_read_byte(struct snd_ice1712 *ice, unsigned char tmp)
{
	unsigned char data = 0;
	int idx;
	
	for (idx = 7; idx >= 0; idx--) {
		tmp &= ~ICE1712_DELTA_AP_CCLK;
		snd_ice1712_write(ice, ICE1712_IREG_GPIO_DATA, tmp);
		udelay(5);
		if (snd_ice1712_read(ice, ICE1712_IREG_GPIO_DATA) & ICE1712_DELTA_AP_DIN)
			data |= 1 << idx;
		tmp |= ICE1712_DELTA_AP_CCLK;
		snd_ice1712_write(ice, ICE1712_IREG_GPIO_DATA, tmp);
		udelay(5);
	}
	return data;
}

__attribute__((used)) static unsigned char ap_cs8427_codec_select(struct snd_ice1712 *ice)
{
	unsigned char tmp;
	tmp = snd_ice1712_read(ice, ICE1712_IREG_GPIO_DATA);
	switch (ice->eeprom.subvendor) {
	case ICE1712_SUBDEVICE_DELTA1010E:
	case ICE1712_SUBDEVICE_DELTA1010LT:
		tmp &= ~ICE1712_DELTA_1010LT_CS;
		tmp |= ICE1712_DELTA_1010LT_CCLK | ICE1712_DELTA_1010LT_CS_CS8427;
		break;
	case ICE1712_SUBDEVICE_AUDIOPHILE:
	case ICE1712_SUBDEVICE_DELTA410:
		tmp |= ICE1712_DELTA_AP_CCLK | ICE1712_DELTA_AP_CS_CODEC;
		tmp &= ~ICE1712_DELTA_AP_CS_DIGITAL;
		break;
	case ICE1712_SUBDEVICE_DELTA66E:
		tmp |= ICE1712_DELTA_66E_CCLK | ICE1712_DELTA_66E_CS_CHIP_A |
		       ICE1712_DELTA_66E_CS_CHIP_B;
		tmp &= ~ICE1712_DELTA_66E_CS_CS8427;
		break;
	case ICE1712_SUBDEVICE_VX442:
		tmp |= ICE1712_VX442_CCLK | ICE1712_VX442_CODEC_CHIP_A | ICE1712_VX442_CODEC_CHIP_B;
		tmp &= ~ICE1712_VX442_CS_DIGITAL;
		break;
	}
	snd_ice1712_write(ice, ICE1712_IREG_GPIO_DATA, tmp);
	udelay(5);
	return tmp;
}

__attribute__((used)) static void ap_cs8427_codec_deassert(struct snd_ice1712 *ice, unsigned char tmp)
{
	switch (ice->eeprom.subvendor) {
	case ICE1712_SUBDEVICE_DELTA1010E:
	case ICE1712_SUBDEVICE_DELTA1010LT:
		tmp &= ~ICE1712_DELTA_1010LT_CS;
		tmp |= ICE1712_DELTA_1010LT_CS_NONE;
		break;
	case ICE1712_SUBDEVICE_AUDIOPHILE:
	case ICE1712_SUBDEVICE_DELTA410:
		tmp |= ICE1712_DELTA_AP_CS_DIGITAL;
		break;
	case ICE1712_SUBDEVICE_DELTA66E:
		tmp |= ICE1712_DELTA_66E_CS_CS8427;
		break;
	case ICE1712_SUBDEVICE_VX442:
		tmp |= ICE1712_VX442_CS_DIGITAL;
		break;
	}
	snd_ice1712_write(ice, ICE1712_IREG_GPIO_DATA, tmp);
}

__attribute__((used)) static int ap_cs8427_sendbytes(struct snd_i2c_device *device, unsigned char *bytes, int count)
{
	struct snd_ice1712 *ice = device->bus->private_data;
	int res = count;
	unsigned char tmp;

	mutex_lock(&ice->gpio_mutex);
	tmp = ap_cs8427_codec_select(ice);
	ap_cs8427_write_byte(ice, (device->addr << 1) | 0, tmp); /* address + write mode */
	while (count-- > 0)
		ap_cs8427_write_byte(ice, *bytes++, tmp);
	ap_cs8427_codec_deassert(ice, tmp);
	mutex_unlock(&ice->gpio_mutex);
	return res;
}

__attribute__((used)) static int ap_cs8427_readbytes(struct snd_i2c_device *device, unsigned char *bytes, int count)
{
	struct snd_ice1712 *ice = device->bus->private_data;
	int res = count;
	unsigned char tmp;
	
	mutex_lock(&ice->gpio_mutex);
	tmp = ap_cs8427_codec_select(ice);
	ap_cs8427_write_byte(ice, (device->addr << 1) | 1, tmp); /* address + read mode */
	while (count-- > 0)
		*bytes++ = ap_cs8427_read_byte(ice, tmp);
	ap_cs8427_codec_deassert(ice, tmp);
	mutex_unlock(&ice->gpio_mutex);
	return res;
}

__attribute__((used)) static int ap_cs8427_probeaddr(struct snd_i2c_bus *bus, unsigned short addr)
{
	if (addr == 0x10)
		return 1;
	return -ENOENT;
}

__attribute__((used)) static void snd_ice1712_delta_cs8403_spdif_write(struct snd_ice1712 *ice, unsigned char bits)
{
	unsigned char tmp, mask1, mask2;
	int idx;
	/* send byte to transmitter */
	mask1 = ICE1712_DELTA_SPDIF_OUT_STAT_CLOCK;
	mask2 = ICE1712_DELTA_SPDIF_OUT_STAT_DATA;
	mutex_lock(&ice->gpio_mutex);
	tmp = snd_ice1712_read(ice, ICE1712_IREG_GPIO_DATA);
	for (idx = 7; idx >= 0; idx--) {
		tmp &= ~(mask1 | mask2);
		if (bits & (1 << idx))
			tmp |= mask2;
		snd_ice1712_write(ice, ICE1712_IREG_GPIO_DATA, tmp);
		udelay(100);
		tmp |= mask1;
		snd_ice1712_write(ice, ICE1712_IREG_GPIO_DATA, tmp);
		udelay(100);
	}
	tmp &= ~mask1;
	snd_ice1712_write(ice, ICE1712_IREG_GPIO_DATA, tmp);
	mutex_unlock(&ice->gpio_mutex);
}

__attribute__((used)) static void delta_spdif_default_get(struct snd_ice1712 *ice, struct snd_ctl_elem_value *ucontrol)
{
	snd_cs8403_decode_spdif_bits(&ucontrol->value.iec958, ice->spdif.cs8403_bits);
}

__attribute__((used)) static int delta_spdif_default_put(struct snd_ice1712 *ice, struct snd_ctl_elem_value *ucontrol)
{
	unsigned int val;
	int change;

	val = snd_cs8403_encode_spdif_bits(&ucontrol->value.iec958);
	spin_lock_irq(&ice->reg_lock);
	change = ice->spdif.cs8403_bits != val;
	ice->spdif.cs8403_bits = val;
	if (change && ice->playback_pro_substream == NULL) {
		spin_unlock_irq(&ice->reg_lock);
		snd_ice1712_delta_cs8403_spdif_write(ice, val);
	} else {
		spin_unlock_irq(&ice->reg_lock);
	}
	return change;
}

__attribute__((used)) static void delta_spdif_stream_get(struct snd_ice1712 *ice, struct snd_ctl_elem_value *ucontrol)
{
	snd_cs8403_decode_spdif_bits(&ucontrol->value.iec958, ice->spdif.cs8403_stream_bits);
}

__attribute__((used)) static int delta_spdif_stream_put(struct snd_ice1712 *ice, struct snd_ctl_elem_value *ucontrol)
{
	unsigned int val;
	int change;

	val = snd_cs8403_encode_spdif_bits(&ucontrol->value.iec958);
	spin_lock_irq(&ice->reg_lock);
	change = ice->spdif.cs8403_stream_bits != val;
	ice->spdif.cs8403_stream_bits = val;
	if (change && ice->playback_pro_substream != NULL) {
		spin_unlock_irq(&ice->reg_lock);
		snd_ice1712_delta_cs8403_spdif_write(ice, val);
	} else {
		spin_unlock_irq(&ice->reg_lock);
	}
	return change;
}

__attribute__((used)) static void delta_ak4524_lock(struct snd_akm4xxx *ak, int chip)
{
        struct snd_ak4xxx_private *priv = (void *)ak->private_value[0];
        struct snd_ice1712 *ice = ak->private_data[0];

	snd_ice1712_save_gpio_status(ice);
	priv->cs_mask =
	priv->cs_addr = chip == 0 ? ICE1712_DELTA_CODEC_CHIP_A :
				    ICE1712_DELTA_CODEC_CHIP_B;
}

__attribute__((used)) static void delta1010lt_ak4524_lock(struct snd_akm4xxx *ak, int chip)
{
        struct snd_ak4xxx_private *priv = (void *)ak->private_value[0];
        struct snd_ice1712 *ice = ak->private_data[0];

	snd_ice1712_save_gpio_status(ice);
	priv->cs_mask = ICE1712_DELTA_1010LT_CS;
	priv->cs_addr = chip << 4;
}

__attribute__((used)) static void delta66e_ak4524_lock(struct snd_akm4xxx *ak, int chip)
{
	struct snd_ak4xxx_private *priv = (void *)ak->private_value[0];
	struct snd_ice1712 *ice = ak->private_data[0];

	snd_ice1712_save_gpio_status(ice);
	priv->cs_mask =
	priv->cs_addr = chip == 0 ? ICE1712_DELTA_66E_CS_CHIP_A :
				    ICE1712_DELTA_66E_CS_CHIP_B;
}

__attribute__((used)) static void vx442_ak4524_lock(struct snd_akm4xxx *ak, int chip)
{
        struct snd_ak4xxx_private *priv = (void *)ak->private_value[0];
        struct snd_ice1712 *ice = ak->private_data[0];

	snd_ice1712_save_gpio_status(ice);
	priv->cs_mask =
	priv->cs_addr = chip == 0 ? ICE1712_VX442_CODEC_CHIP_A :
				    ICE1712_VX442_CODEC_CHIP_B;
}

__attribute__((used)) static void delta_1010_set_rate_val(struct snd_ice1712 *ice, unsigned int rate)
{
	unsigned char tmp, tmp2;

	if (rate == 0)	/* no hint - S/PDIF input is master, simply return */
		return;

	mutex_lock(&ice->gpio_mutex);
	tmp = snd_ice1712_read(ice, ICE1712_IREG_GPIO_DATA);
	tmp2 = tmp & ~ICE1712_DELTA_DFS;
	if (rate > 48000)
		tmp2 |= ICE1712_DELTA_DFS;
	if (tmp != tmp2)
		snd_ice1712_write(ice, ICE1712_IREG_GPIO_DATA, tmp2);
	mutex_unlock(&ice->gpio_mutex);
}

__attribute__((used)) static void delta_ak4524_set_rate_val(struct snd_akm4xxx *ak, unsigned int rate)
{
	unsigned char tmp, tmp2;
	struct snd_ice1712 *ice = ak->private_data[0];

	if (rate == 0)	/* no hint - S/PDIF input is master, simply return */
		return;

	/* check before reset ak4524 to avoid unnecessary clicks */
	mutex_lock(&ice->gpio_mutex);
	tmp = snd_ice1712_read(ice, ICE1712_IREG_GPIO_DATA);
	mutex_unlock(&ice->gpio_mutex);
	tmp2 = tmp & ~ICE1712_DELTA_DFS; 
	if (rate > 48000)
		tmp2 |= ICE1712_DELTA_DFS;
	if (tmp == tmp2)
		return;

	/* do it again */
	snd_akm4xxx_reset(ak, 1);
	mutex_lock(&ice->gpio_mutex);
	tmp = snd_ice1712_read(ice, ICE1712_IREG_GPIO_DATA) & ~ICE1712_DELTA_DFS;
	if (rate > 48000)
		tmp |= ICE1712_DELTA_DFS;
	snd_ice1712_write(ice, ICE1712_IREG_GPIO_DATA, tmp);
	mutex_unlock(&ice->gpio_mutex);
	snd_akm4xxx_reset(ak, 0);
}

__attribute__((used)) static void vx442_ak4524_set_rate_val(struct snd_akm4xxx *ak, unsigned int rate)
{
	unsigned char val;

	val = (rate > 48000) ? 0x65 : 0x60;
	if (snd_akm4xxx_get(ak, 0, 0x02) != val ||
	    snd_akm4xxx_get(ak, 1, 0x02) != val) {
		snd_akm4xxx_reset(ak, 1);
		snd_akm4xxx_write(ak, 0, 0x02, val);
		snd_akm4xxx_write(ak, 1, 0x02, val);
		snd_akm4xxx_reset(ak, 0);
	}
}

__attribute__((used)) static void delta_open_spdif(struct snd_ice1712 *ice, struct snd_pcm_substream *substream)
{
	ice->spdif.cs8403_stream_bits = ice->spdif.cs8403_bits;
}

__attribute__((used)) static void delta_setup_spdif(struct snd_ice1712 *ice, int rate)
{
	unsigned long flags;
	unsigned int tmp;
	int change;

	spin_lock_irqsave(&ice->reg_lock, flags);
	tmp = ice->spdif.cs8403_stream_bits;
	if (tmp & 0x01)		/* consumer */
		tmp &= (tmp & 0x01) ? ~0x06 : ~0x18;
	switch (rate) {
	case 32000: tmp |= (tmp & 0x01) ? 0x04 : 0x00; break;
	case 44100: tmp |= (tmp & 0x01) ? 0x00 : 0x10; break;
	case 48000: tmp |= (tmp & 0x01) ? 0x02 : 0x08; break;
	default: tmp |= (tmp & 0x01) ? 0x00 : 0x18; break;
	}
	change = ice->spdif.cs8403_stream_bits != tmp;
	ice->spdif.cs8403_stream_bits = tmp;
	spin_unlock_irqrestore(&ice->reg_lock, flags);
	if (change)
		snd_ctl_notify(ice->card, SNDRV_CTL_EVENT_MASK_VALUE, &ice->spdif.stream_ctl->id);
	snd_ice1712_delta_cs8403_spdif_write(ice, tmp);
}

__attribute__((used)) static int snd_ice1712_delta1010lt_wordclock_status_get(struct snd_kcontrol *kcontrol,
			 struct snd_ctl_elem_value *ucontrol)
{
	char reg = 0x10; /* CS8427 receiver error register */
	struct snd_ice1712 *ice = snd_kcontrol_chip(kcontrol);

	if (snd_i2c_sendbytes(ice->cs8427, &reg, 1) != 1)
		dev_err(ice->card->dev,
			"unable to send register 0x%x byte to CS8427\n", reg);
	snd_i2c_readbytes(ice->cs8427, &reg, 1);
	ucontrol->value.integer.value[0] = (reg & CS8427_UNLOCK) ? 1 : 0;
	return 0;
}

__attribute__((used)) static int snd_ice1712_delta_init(struct snd_ice1712 *ice)
{
	int err;
	struct snd_akm4xxx *ak;
	unsigned char tmp;

	if (ice->eeprom.subvendor == ICE1712_SUBDEVICE_DELTA1010 &&
	    ice->eeprom.gpiodir == 0x7b)
		ice->eeprom.subvendor = ICE1712_SUBDEVICE_DELTA1010E;

	if (ice->eeprom.subvendor == ICE1712_SUBDEVICE_DELTA66 &&
	    ice->eeprom.gpiodir == 0xfb)
	    	ice->eeprom.subvendor = ICE1712_SUBDEVICE_DELTA66E;

	/* determine I2C, DACs and ADCs */
	switch (ice->eeprom.subvendor) {
	case ICE1712_SUBDEVICE_AUDIOPHILE:
		ice->num_total_dacs = 2;
		ice->num_total_adcs = 2;
		break;
	case ICE1712_SUBDEVICE_DELTA410:
		ice->num_total_dacs = 8;
		ice->num_total_adcs = 2;
		break;
	case ICE1712_SUBDEVICE_DELTA44:
	case ICE1712_SUBDEVICE_DELTA66:
		ice->num_total_dacs = ice->omni ? 8 : 4;
		ice->num_total_adcs = ice->omni ? 8 : 4;
		break;
	case ICE1712_SUBDEVICE_DELTA1010:
	case ICE1712_SUBDEVICE_DELTA1010E:
	case ICE1712_SUBDEVICE_DELTA1010LT:
	case ICE1712_SUBDEVICE_MEDIASTATION:
	case ICE1712_SUBDEVICE_EDIROLDA2496:
		ice->num_total_dacs = 8;
		ice->num_total_adcs = 8;
		break;
	case ICE1712_SUBDEVICE_DELTADIO2496:
		ice->num_total_dacs = 4;	/* two AK4324 codecs */
		break;
	case ICE1712_SUBDEVICE_VX442:
	case ICE1712_SUBDEVICE_DELTA66E:	/* omni not supported yet */
		ice->num_total_dacs = 4;
		ice->num_total_adcs = 4;
		break;
	}
#ifdef CONFIG_PM_SLEEP
	ice->pm_resume = snd_ice1712_delta_resume;
	ice->pm_suspend = snd_ice1712_delta_suspend;
	ice->pm_suspend_enabled = 1;
#endif
	/* initialize the SPI clock to high */
	tmp = snd_ice1712_read(ice, ICE1712_IREG_GPIO_DATA);
	tmp |= ICE1712_DELTA_AP_CCLK;
	snd_ice1712_write(ice, ICE1712_IREG_GPIO_DATA, tmp);
	udelay(5);

	/* initialize spdif */
	switch (ice->eeprom.subvendor) {
	case ICE1712_SUBDEVICE_AUDIOPHILE:
	case ICE1712_SUBDEVICE_DELTA410:
	case ICE1712_SUBDEVICE_DELTA1010E:
	case ICE1712_SUBDEVICE_DELTA1010LT:
	case ICE1712_SUBDEVICE_VX442:
	case ICE1712_SUBDEVICE_DELTA66E:
		if ((err = snd_i2c_bus_create(ice->card, "ICE1712 GPIO 1", NULL, &ice->i2c)) < 0) {
			dev_err(ice->card->dev, "unable to create I2C bus\n");
			return err;
		}
		ice->i2c->private_data = ice;
		ice->i2c->ops = &ap_cs8427_i2c_ops;
		if ((err = snd_ice1712_init_cs8427(ice, CS8427_BASE_ADDR)) < 0)
			return err;
		break;
	case ICE1712_SUBDEVICE_DELTA1010:
	case ICE1712_SUBDEVICE_MEDIASTATION:
		ice->gpio.set_pro_rate = delta_1010_set_rate_val;
		break;
	case ICE1712_SUBDEVICE_DELTADIO2496:
		ice->gpio.set_pro_rate = delta_1010_set_rate_val;
		/* fall thru */
	case ICE1712_SUBDEVICE_DELTA66:
		ice->spdif.ops.open = delta_open_spdif;
		ice->spdif.ops.setup_rate = delta_setup_spdif;
		ice->spdif.ops.default_get = delta_spdif_default_get;
		ice->spdif.ops.default_put = delta_spdif_default_put;
		ice->spdif.ops.stream_get = delta_spdif_stream_get;
		ice->spdif.ops.stream_put = delta_spdif_stream_put;
		/* Set spdif defaults */
		snd_ice1712_delta_cs8403_spdif_write(ice, ice->spdif.cs8403_bits);
		break;
	}

	/* no analog? */
	switch (ice->eeprom.subvendor) {
	case ICE1712_SUBDEVICE_DELTA1010:
	case ICE1712_SUBDEVICE_DELTA1010E:
	case ICE1712_SUBDEVICE_DELTADIO2496:
	case ICE1712_SUBDEVICE_MEDIASTATION:
		return 0;
	}

	/* second stage of initialization, analog parts and others */
	ak = ice->akm = kmalloc(sizeof(struct snd_akm4xxx), GFP_KERNEL);
	if (! ak)
		return -ENOMEM;
	ice->akm_codecs = 1;

	switch (ice->eeprom.subvendor) {
	case ICE1712_SUBDEVICE_AUDIOPHILE:
		err = snd_ice1712_akm4xxx_init(ak, &akm_audiophile, &akm_audiophile_priv, ice);
		break;
	case ICE1712_SUBDEVICE_DELTA410:
		err = snd_ice1712_akm4xxx_init(ak, &akm_delta410, &akm_delta410_priv, ice);
		break;
	case ICE1712_SUBDEVICE_DELTA1010LT:
	case ICE1712_SUBDEVICE_EDIROLDA2496:
		err = snd_ice1712_akm4xxx_init(ak, &akm_delta1010lt, &akm_delta1010lt_priv, ice);
		break;
	case ICE1712_SUBDEVICE_DELTA66:
	case ICE1712_SUBDEVICE_DELTA44:
		err = snd_ice1712_akm4xxx_init(ak, &akm_delta44, &akm_delta44_priv, ice);
		break;
	case ICE1712_SUBDEVICE_VX442:
		err = snd_ice1712_akm4xxx_init(ak, &akm_vx442, &akm_vx442_priv, ice);
		break;
	case ICE1712_SUBDEVICE_DELTA66E:
		err = snd_ice1712_akm4xxx_init(ak, &akm_delta66e, &akm_delta66e_priv, ice);
		break;
	default:
		snd_BUG();
		return -EINVAL;
	}

	return err;
}

__attribute__((used)) static int snd_ice1712_delta_add_controls(struct snd_ice1712 *ice)
{
	int err;

	/* 1010 and dio specific controls */
	switch (ice->eeprom.subvendor) {
	case ICE1712_SUBDEVICE_DELTA1010:
	case ICE1712_SUBDEVICE_MEDIASTATION:
		err = snd_ctl_add(ice->card, snd_ctl_new1(&snd_ice1712_delta1010_wordclock_select, ice));
		if (err < 0)
			return err;
		err = snd_ctl_add(ice->card, snd_ctl_new1(&snd_ice1712_delta1010_wordclock_status, ice));
		if (err < 0)
			return err;
		break;
	case ICE1712_SUBDEVICE_DELTADIO2496:
		err = snd_ctl_add(ice->card, snd_ctl_new1(&snd_ice1712_deltadio2496_spdif_in_select, ice));
		if (err < 0)
			return err;
		break;
	case ICE1712_SUBDEVICE_DELTA1010E:
	case ICE1712_SUBDEVICE_DELTA1010LT:
		err = snd_ctl_add(ice->card, snd_ctl_new1(&snd_ice1712_delta1010lt_wordclock_select, ice));
		if (err < 0)
			return err;
		err = snd_ctl_add(ice->card, snd_ctl_new1(&snd_ice1712_delta1010lt_wordclock_status, ice));
		if (err < 0)
			return err;
		break;
	}

	/* normal spdif controls */
	switch (ice->eeprom.subvendor) {
	case ICE1712_SUBDEVICE_DELTA1010:
	case ICE1712_SUBDEVICE_DELTADIO2496:
	case ICE1712_SUBDEVICE_DELTA66:
	case ICE1712_SUBDEVICE_MEDIASTATION:
		err = snd_ice1712_spdif_build_controls(ice);
		if (err < 0)
			return err;
		break;
	}

	/* spdif status in */
	switch (ice->eeprom.subvendor) {
	case ICE1712_SUBDEVICE_DELTA1010:
	case ICE1712_SUBDEVICE_DELTADIO2496:
	case ICE1712_SUBDEVICE_DELTA66:
	case ICE1712_SUBDEVICE_MEDIASTATION:
		err = snd_ctl_add(ice->card, snd_ctl_new1(&snd_ice1712_delta_spdif_in_status, ice));
		if (err < 0)
			return err;
		break;
	}

	/* ak4524 controls */
	switch (ice->eeprom.subvendor) {
	case ICE1712_SUBDEVICE_DELTA1010LT:
	case ICE1712_SUBDEVICE_AUDIOPHILE:
	case ICE1712_SUBDEVICE_DELTA410:
	case ICE1712_SUBDEVICE_DELTA44:
	case ICE1712_SUBDEVICE_DELTA66:
	case ICE1712_SUBDEVICE_VX442:
	case ICE1712_SUBDEVICE_DELTA66E:
	case ICE1712_SUBDEVICE_EDIROLDA2496:
		err = snd_ice1712_akm4xxx_build_controls(ice);
		if (err < 0)
			return err;
		break;
	}

	return 0;
}

