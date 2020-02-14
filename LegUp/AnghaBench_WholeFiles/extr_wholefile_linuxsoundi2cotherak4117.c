#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_16__   TYPE_8__ ;
typedef  struct TYPE_15__   TYPE_7__ ;
typedef  struct TYPE_14__   TYPE_6__ ;
typedef  struct TYPE_13__   TYPE_5__ ;
typedef  struct TYPE_12__   TYPE_4__ ;
typedef  struct TYPE_11__   TYPE_3__ ;
typedef  struct TYPE_10__   TYPE_2__ ;
typedef  struct TYPE_9__   TYPE_1__ ;

/* Type definitions */
typedef  int u8 ;
struct timer_list {int dummy; } ;
struct snd_pcm_substream {struct snd_pcm_runtime* runtime; int /*<<< orphan*/  number; TYPE_7__* pcm; } ;
struct snd_pcm_runtime {int rate; int /*<<< orphan*/  sleep; } ;
struct TYPE_16__ {int /*<<< orphan*/  subdevice; int /*<<< orphan*/  device; } ;
struct snd_kcontrol {size_t private_value; TYPE_8__ id; } ;
struct snd_device_ops {int (* dev_free ) (struct snd_device*) ;} ;
struct snd_device {struct ak4117* device_data; } ;
struct TYPE_13__ {unsigned char* data; } ;
struct TYPE_12__ {int* value; } ;
struct TYPE_9__ {unsigned char* status; } ;
struct TYPE_14__ {TYPE_5__ bytes; TYPE_4__ integer; TYPE_1__ iec958; } ;
struct snd_ctl_elem_value {TYPE_6__ value; } ;
struct TYPE_10__ {int max; scalar_t__ min; } ;
struct TYPE_11__ {TYPE_2__ integer; } ;
struct snd_ctl_elem_info {int count; void* type; TYPE_3__ value; } ;
struct snd_card {int dummy; } ;
struct ak4117 {unsigned char* regmap; unsigned char (* read ) (void*,unsigned char) ;unsigned char rcs0; unsigned char rcs1; unsigned char rcs2; int init; int* errors; int /*<<< orphan*/  timer; struct snd_pcm_substream* substream; int /*<<< orphan*/  (* change_callback ) (struct ak4117*,unsigned char,unsigned char) ;struct snd_kcontrol** kctls; struct snd_card* card; int /*<<< orphan*/  lock; void* private_data; int /*<<< orphan*/  (* write ) (void*,unsigned char,unsigned char) ;} ;
typedef  int /*<<< orphan*/  (* ak4117_write_t ) (void*,unsigned char,unsigned char) ;
typedef  unsigned char (* ak4117_read_t ) (void*,unsigned char) ;
struct TYPE_15__ {int /*<<< orphan*/  device; } ;

/* Variables and functions */
 unsigned char AK4117_AUDION ; 
 unsigned char AK4117_AUTO ; 
 unsigned char AK4117_CCRC ; 
 size_t AK4117_CCRC_ERRORS ; 
 unsigned int AK4117_CHECK_NO_RATE ; 
 unsigned int AK4117_CHECK_NO_STAT ; 
 unsigned char AK4117_CINT ; 
 unsigned int AK4117_CONTROLS ; 
 int AK4117_DTSCD ; 
 unsigned char AK4117_FS0 ; 
 unsigned char AK4117_FS1 ; 
 unsigned char AK4117_FS2 ; 
 unsigned char AK4117_FS3 ; 
#define  AK4117_FS_176400HZ 134 
#define  AK4117_FS_192000HZ 133 
#define  AK4117_FS_32000HZ 132 
#define  AK4117_FS_44100HZ 131 
#define  AK4117_FS_48000HZ 130 
#define  AK4117_FS_88200HZ 129 
#define  AK4117_FS_96000HZ 128 
 int AK4117_IPS ; 
 int AK4117_NPCM ; 
 unsigned char AK4117_PAR ; 
 size_t AK4117_PARITY_ERRORS ; 
 int AK4117_PEM ; 
 unsigned char AK4117_PWN ; 
 unsigned char AK4117_QCRC ; 
 size_t AK4117_QCRC_ERRORS ; 
 unsigned char AK4117_QINT ; 
 size_t AK4117_REG_IO ; 
 size_t AK4117_REG_PWRDN ; 
 unsigned char AK4117_REG_Pc0 ; 
 unsigned char AK4117_REG_Pc1 ; 
 unsigned char AK4117_REG_Pd0 ; 
 unsigned char AK4117_REG_Pd1 ; 
 unsigned int AK4117_REG_QSUB_ADDR ; 
 unsigned int AK4117_REG_QSUB_SIZE ; 
 unsigned char AK4117_REG_RCS0 ; 
 unsigned char AK4117_REG_RCS1 ; 
 unsigned char AK4117_REG_RCS2 ; 
 unsigned int AK4117_REG_RXCSB0 ; 
 unsigned int AK4117_REG_RXCSB_SIZE ; 
 unsigned char AK4117_RST ; 
 unsigned char AK4117_STC ; 
 unsigned char AK4117_UNLCK ; 
 unsigned char AK4117_V ; 
 size_t AK4117_V_BIT_ERRORS ; 
 int EINVAL ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int LONG_MAX ; 
 void* SNDRV_CTL_ELEM_TYPE_BYTES ; 
 void* SNDRV_CTL_ELEM_TYPE_IEC958 ; 
 void* SNDRV_CTL_ELEM_TYPE_INTEGER ; 
 int /*<<< orphan*/  SNDRV_CTL_EVENT_MASK_VALUE ; 
 int /*<<< orphan*/  SNDRV_DEV_CODEC ; 
 int /*<<< orphan*/  SNDRV_PCM_STATE_DRAINING ; 
 struct ak4117* chip ; 
 int /*<<< orphan*/  del_timer (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  del_timer_sync (int /*<<< orphan*/ *) ; 
 struct ak4117* from_timer (int /*<<< orphan*/ ,struct timer_list*,int /*<<< orphan*/ ) ; 
 scalar_t__ jiffies ; 
 int /*<<< orphan*/  kfree (struct ak4117*) ; 
 struct ak4117* kzalloc (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  memset (unsigned char*,int,unsigned int) ; 
 int /*<<< orphan*/  mod_timer (int /*<<< orphan*/ *,scalar_t__) ; 
 scalar_t__ snd_BUG_ON (int) ; 
 int /*<<< orphan*/ * snd_ak4117_iec958_controls ; 
 void snd_ak4117_reinit (struct ak4117*) ; 
static  void snd_ak4117_timer (struct timer_list*) ; 
 int snd_ctl_add (struct snd_card*,struct snd_kcontrol*) ; 
 struct snd_kcontrol* snd_ctl_new1 (int /*<<< orphan*/ *,struct ak4117*) ; 
 int /*<<< orphan*/  snd_ctl_notify (struct snd_card*,int /*<<< orphan*/ ,TYPE_8__*) ; 
 int snd_device_new (struct snd_card*,int /*<<< orphan*/ ,struct ak4117*,struct snd_device_ops*) ; 
 struct ak4117* snd_kcontrol_chip (struct snd_kcontrol*) ; 
 scalar_t__ snd_pcm_running (struct snd_pcm_substream*) ; 
 int /*<<< orphan*/  snd_pcm_stop (struct snd_pcm_substream*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  snd_pcm_stream_lock_irqsave (struct snd_pcm_substream*,unsigned long) ; 
 int /*<<< orphan*/  snd_pcm_stream_unlock_irqrestore (struct snd_pcm_substream*,unsigned long) ; 
 int /*<<< orphan*/  spin_lock_init (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  spin_lock_irq (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  spin_lock_irqsave (int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  spin_unlock_irq (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  spin_unlock_irqrestore (int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  stub1 (void*,unsigned char,unsigned char) ; 
 unsigned char stub2 (void*,unsigned char) ; 
 int /*<<< orphan*/  stub3 (struct ak4117*,unsigned char,unsigned char) ; 
 int /*<<< orphan*/  timer ; 
 int /*<<< orphan*/  timer_setup (int /*<<< orphan*/ *,void (*) (struct timer_list*),int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  udelay (int) ; 
 int /*<<< orphan*/  wake_up (int /*<<< orphan*/ *) ; 

__attribute__((used)) static void reg_write(struct ak4117 *ak4117, unsigned char reg, unsigned char val)
{
	ak4117->write(ak4117->private_data, reg, val);
	if (reg < sizeof(ak4117->regmap))
		ak4117->regmap[reg] = val;
}

__attribute__((used)) static inline unsigned char reg_read(struct ak4117 *ak4117, unsigned char reg)
{
	return ak4117->read(ak4117->private_data, reg);
}

__attribute__((used)) static void snd_ak4117_free(struct ak4117 *chip)
{
	del_timer_sync(&chip->timer);
	kfree(chip);
}

__attribute__((used)) static int snd_ak4117_dev_free(struct snd_device *device)
{
	struct ak4117 *chip = device->device_data;
	snd_ak4117_free(chip);
	return 0;
}

int snd_ak4117_create(struct snd_card *card, ak4117_read_t *read, ak4117_write_t *write,
		      const unsigned char pgm[5], void *private_data, struct ak4117 **r_ak4117)
{
	struct ak4117 *chip;
	int err = 0;
	unsigned char reg;
	static struct snd_device_ops ops = {
		.dev_free =     snd_ak4117_dev_free,
	};

	chip = kzalloc(sizeof(*chip), GFP_KERNEL);
	if (chip == NULL)
		return -ENOMEM;
	spin_lock_init(&chip->lock);
	chip->card = card;
	chip->read = read;
	chip->write = write;
	chip->private_data = private_data;
	timer_setup(&chip->timer, snd_ak4117_timer, 0);

	for (reg = 0; reg < 5; reg++)
		chip->regmap[reg] = pgm[reg];
	snd_ak4117_reinit(chip);

	chip->rcs0 = reg_read(chip, AK4117_REG_RCS0) & ~(AK4117_QINT | AK4117_CINT | AK4117_STC);
	chip->rcs1 = reg_read(chip, AK4117_REG_RCS1);
	chip->rcs2 = reg_read(chip, AK4117_REG_RCS2);

	if ((err = snd_device_new(card, SNDRV_DEV_CODEC, chip, &ops)) < 0)
		goto __fail;

	if (r_ak4117)
		*r_ak4117 = chip;
	return 0;

      __fail:
	snd_ak4117_free(chip);
	return err;
}

void snd_ak4117_reg_write(struct ak4117 *chip, unsigned char reg, unsigned char mask, unsigned char val)
{
	if (reg >= 5)
		return;
	reg_write(chip, reg, (chip->regmap[reg] & ~mask) | val);
}

void snd_ak4117_reinit(struct ak4117 *chip)
{
	unsigned char old = chip->regmap[AK4117_REG_PWRDN], reg;

	del_timer(&chip->timer);
	chip->init = 1;
	/* bring the chip to reset state and powerdown state */
	reg_write(chip, AK4117_REG_PWRDN, 0);
	udelay(200);
	/* release reset, but leave powerdown */
	reg_write(chip, AK4117_REG_PWRDN, (old | AK4117_RST) & ~AK4117_PWN);
	udelay(200);
	for (reg = 1; reg < 5; reg++)
		reg_write(chip, reg, chip->regmap[reg]);
	/* release powerdown, everything is initialized now */
	reg_write(chip, AK4117_REG_PWRDN, old | AK4117_RST | AK4117_PWN);
	chip->init = 0;
	mod_timer(&chip->timer, 1 + jiffies);
}

__attribute__((used)) static unsigned int external_rate(unsigned char rcs1)
{
	switch (rcs1 & (AK4117_FS0|AK4117_FS1|AK4117_FS2|AK4117_FS3)) {
	case AK4117_FS_32000HZ: return 32000;
	case AK4117_FS_44100HZ: return 44100;
	case AK4117_FS_48000HZ: return 48000;
	case AK4117_FS_88200HZ: return 88200;
	case AK4117_FS_96000HZ: return 96000;
	case AK4117_FS_176400HZ: return 176400;
	case AK4117_FS_192000HZ: return 192000;
	default:		return 0;
	}
}

__attribute__((used)) static int snd_ak4117_in_error_info(struct snd_kcontrol *kcontrol,
				    struct snd_ctl_elem_info *uinfo)
{
	uinfo->type = SNDRV_CTL_ELEM_TYPE_INTEGER;
	uinfo->count = 1;
	uinfo->value.integer.min = 0;
	uinfo->value.integer.max = LONG_MAX;
	return 0;
}

__attribute__((used)) static int snd_ak4117_in_error_get(struct snd_kcontrol *kcontrol,
				   struct snd_ctl_elem_value *ucontrol)
{
	struct ak4117 *chip = snd_kcontrol_chip(kcontrol);

	spin_lock_irq(&chip->lock);
	ucontrol->value.integer.value[0] =
		       chip->errors[kcontrol->private_value];
	chip->errors[kcontrol->private_value] = 0;
	spin_unlock_irq(&chip->lock);
	return 0;
}

__attribute__((used)) static int snd_ak4117_in_bit_get(struct snd_kcontrol *kcontrol,
				 struct snd_ctl_elem_value *ucontrol)
{
	struct ak4117 *chip = snd_kcontrol_chip(kcontrol);
	unsigned char reg = kcontrol->private_value & 0xff;
	unsigned char bit = (kcontrol->private_value >> 8) & 0xff;
	unsigned char inv = (kcontrol->private_value >> 31) & 1;

	ucontrol->value.integer.value[0] = ((reg_read(chip, reg) & (1 << bit)) ? 1 : 0) ^ inv;
	return 0;
}

__attribute__((used)) static int snd_ak4117_rx_info(struct snd_kcontrol *kcontrol,
			      struct snd_ctl_elem_info *uinfo)
{
	uinfo->type = SNDRV_CTL_ELEM_TYPE_INTEGER;
	uinfo->count = 1;
	uinfo->value.integer.min = 0;
	uinfo->value.integer.max = 1;
	return 0;
}

__attribute__((used)) static int snd_ak4117_rx_get(struct snd_kcontrol *kcontrol,
			     struct snd_ctl_elem_value *ucontrol)
{
	struct ak4117 *chip = snd_kcontrol_chip(kcontrol);

	ucontrol->value.integer.value[0] = (chip->regmap[AK4117_REG_IO] & AK4117_IPS) ? 1 : 0;
	return 0;
}

__attribute__((used)) static int snd_ak4117_rx_put(struct snd_kcontrol *kcontrol,
			     struct snd_ctl_elem_value *ucontrol)
{
	struct ak4117 *chip = snd_kcontrol_chip(kcontrol);
	int change;
	u8 old_val;
	
	spin_lock_irq(&chip->lock);
	old_val = chip->regmap[AK4117_REG_IO];
	change = !!ucontrol->value.integer.value[0] != ((old_val & AK4117_IPS) ? 1 : 0);
	if (change)
		reg_write(chip, AK4117_REG_IO, (old_val & ~AK4117_IPS) | (ucontrol->value.integer.value[0] ? AK4117_IPS : 0));
	spin_unlock_irq(&chip->lock);
	return change;
}

__attribute__((used)) static int snd_ak4117_rate_info(struct snd_kcontrol *kcontrol,
				struct snd_ctl_elem_info *uinfo)
{
	uinfo->type = SNDRV_CTL_ELEM_TYPE_INTEGER;
	uinfo->count = 1;
	uinfo->value.integer.min = 0;
	uinfo->value.integer.max = 192000;
	return 0;
}

__attribute__((used)) static int snd_ak4117_rate_get(struct snd_kcontrol *kcontrol,
			       struct snd_ctl_elem_value *ucontrol)
{
	struct ak4117 *chip = snd_kcontrol_chip(kcontrol);

	ucontrol->value.integer.value[0] = external_rate(reg_read(chip, AK4117_REG_RCS1));
	return 0;
}

__attribute__((used)) static int snd_ak4117_spdif_info(struct snd_kcontrol *kcontrol, struct snd_ctl_elem_info *uinfo)
{
	uinfo->type = SNDRV_CTL_ELEM_TYPE_IEC958;
	uinfo->count = 1;
	return 0;
}

__attribute__((used)) static int snd_ak4117_spdif_get(struct snd_kcontrol *kcontrol,
				struct snd_ctl_elem_value *ucontrol)
{
	struct ak4117 *chip = snd_kcontrol_chip(kcontrol);
	unsigned i;

	for (i = 0; i < AK4117_REG_RXCSB_SIZE; i++)
		ucontrol->value.iec958.status[i] = reg_read(chip, AK4117_REG_RXCSB0 + i);
	return 0;
}

__attribute__((used)) static int snd_ak4117_spdif_mask_info(struct snd_kcontrol *kcontrol, struct snd_ctl_elem_info *uinfo)
{
	uinfo->type = SNDRV_CTL_ELEM_TYPE_IEC958;
	uinfo->count = 1;
	return 0;
}

__attribute__((used)) static int snd_ak4117_spdif_mask_get(struct snd_kcontrol *kcontrol,
				      struct snd_ctl_elem_value *ucontrol)
{
	memset(ucontrol->value.iec958.status, 0xff, AK4117_REG_RXCSB_SIZE);
	return 0;
}

__attribute__((used)) static int snd_ak4117_spdif_pinfo(struct snd_kcontrol *kcontrol, struct snd_ctl_elem_info *uinfo)
{
	uinfo->type = SNDRV_CTL_ELEM_TYPE_INTEGER;
	uinfo->value.integer.min = 0;
	uinfo->value.integer.max = 0xffff;
	uinfo->count = 4;
	return 0;
}

__attribute__((used)) static int snd_ak4117_spdif_pget(struct snd_kcontrol *kcontrol,
				 struct snd_ctl_elem_value *ucontrol)
{
	struct ak4117 *chip = snd_kcontrol_chip(kcontrol);
	unsigned short tmp;

	ucontrol->value.integer.value[0] = 0xf8f2;
	ucontrol->value.integer.value[1] = 0x4e1f;
	tmp = reg_read(chip, AK4117_REG_Pc0) | (reg_read(chip, AK4117_REG_Pc1) << 8);
	ucontrol->value.integer.value[2] = tmp;
	tmp = reg_read(chip, AK4117_REG_Pd0) | (reg_read(chip, AK4117_REG_Pd1) << 8);
	ucontrol->value.integer.value[3] = tmp;
	return 0;
}

__attribute__((used)) static int snd_ak4117_spdif_qinfo(struct snd_kcontrol *kcontrol, struct snd_ctl_elem_info *uinfo)
{
	uinfo->type = SNDRV_CTL_ELEM_TYPE_BYTES;
	uinfo->count = AK4117_REG_QSUB_SIZE;
	return 0;
}

__attribute__((used)) static int snd_ak4117_spdif_qget(struct snd_kcontrol *kcontrol,
				 struct snd_ctl_elem_value *ucontrol)
{
	struct ak4117 *chip = snd_kcontrol_chip(kcontrol);
	unsigned i;

	for (i = 0; i < AK4117_REG_QSUB_SIZE; i++)
		ucontrol->value.bytes.data[i] = reg_read(chip, AK4117_REG_QSUB_ADDR + i);
	return 0;
}

int snd_ak4117_build(struct ak4117 *ak4117, struct snd_pcm_substream *cap_substream)
{
	struct snd_kcontrol *kctl;
	unsigned int idx;
	int err;

	if (snd_BUG_ON(!cap_substream))
		return -EINVAL;
	ak4117->substream = cap_substream;
	for (idx = 0; idx < AK4117_CONTROLS; idx++) {
		kctl = snd_ctl_new1(&snd_ak4117_iec958_controls[idx], ak4117);
		if (kctl == NULL)
			return -ENOMEM;
		kctl->id.device = cap_substream->pcm->device;
		kctl->id.subdevice = cap_substream->number;
		err = snd_ctl_add(ak4117->card, kctl);
		if (err < 0)
			return err;
		ak4117->kctls[idx] = kctl;
	}
	return 0;
}

int snd_ak4117_external_rate(struct ak4117 *ak4117)
{
	unsigned char rcs1;

	rcs1 = reg_read(ak4117, AK4117_REG_RCS1);
	return external_rate(rcs1);
}

int snd_ak4117_check_rate_and_errors(struct ak4117 *ak4117, unsigned int flags)
{
	struct snd_pcm_runtime *runtime = ak4117->substream ? ak4117->substream->runtime : NULL;
	unsigned long _flags;
	int res = 0;
	unsigned char rcs0, rcs1, rcs2;
	unsigned char c0, c1;

	rcs1 = reg_read(ak4117, AK4117_REG_RCS1);
	if (flags & AK4117_CHECK_NO_STAT)
		goto __rate;
	rcs0 = reg_read(ak4117, AK4117_REG_RCS0);
	rcs2 = reg_read(ak4117, AK4117_REG_RCS2);
	// printk(KERN_DEBUG "AK IRQ: rcs0 = 0x%x, rcs1 = 0x%x, rcs2 = 0x%x\n", rcs0, rcs1, rcs2);
	spin_lock_irqsave(&ak4117->lock, _flags);
	if (rcs0 & AK4117_PAR)
		ak4117->errors[AK4117_PARITY_ERRORS]++;
	if (rcs0 & AK4117_V)
		ak4117->errors[AK4117_V_BIT_ERRORS]++;
	if (rcs2 & AK4117_CCRC)
		ak4117->errors[AK4117_CCRC_ERRORS]++;
	if (rcs2 & AK4117_QCRC)
		ak4117->errors[AK4117_QCRC_ERRORS]++;
	c0 = (ak4117->rcs0 & (AK4117_QINT | AK4117_CINT | AK4117_STC | AK4117_AUDION | AK4117_AUTO | AK4117_UNLCK)) ^
                     (rcs0 & (AK4117_QINT | AK4117_CINT | AK4117_STC | AK4117_AUDION | AK4117_AUTO | AK4117_UNLCK));
	c1 = (ak4117->rcs1 & (AK4117_DTSCD | AK4117_NPCM | AK4117_PEM | 0x0f)) ^
	             (rcs1 & (AK4117_DTSCD | AK4117_NPCM | AK4117_PEM | 0x0f));
	ak4117->rcs0 = rcs0 & ~(AK4117_QINT | AK4117_CINT | AK4117_STC);
	ak4117->rcs1 = rcs1;
	ak4117->rcs2 = rcs2;
	spin_unlock_irqrestore(&ak4117->lock, _flags);

	if (rcs0 & AK4117_PAR)
		snd_ctl_notify(ak4117->card, SNDRV_CTL_EVENT_MASK_VALUE, &ak4117->kctls[0]->id);
	if (rcs0 & AK4117_V)
		snd_ctl_notify(ak4117->card, SNDRV_CTL_EVENT_MASK_VALUE, &ak4117->kctls[1]->id);
	if (rcs2 & AK4117_CCRC)
		snd_ctl_notify(ak4117->card, SNDRV_CTL_EVENT_MASK_VALUE, &ak4117->kctls[2]->id);
	if (rcs2 & AK4117_QCRC)
		snd_ctl_notify(ak4117->card, SNDRV_CTL_EVENT_MASK_VALUE, &ak4117->kctls[3]->id);

	/* rate change */
	if (c1 & 0x0f)
		snd_ctl_notify(ak4117->card, SNDRV_CTL_EVENT_MASK_VALUE, &ak4117->kctls[4]->id);

	if ((c1 & AK4117_PEM) | (c0 & AK4117_CINT))
		snd_ctl_notify(ak4117->card, SNDRV_CTL_EVENT_MASK_VALUE, &ak4117->kctls[6]->id);
	if (c0 & AK4117_QINT)
		snd_ctl_notify(ak4117->card, SNDRV_CTL_EVENT_MASK_VALUE, &ak4117->kctls[8]->id);

	if (c0 & AK4117_AUDION)
		snd_ctl_notify(ak4117->card, SNDRV_CTL_EVENT_MASK_VALUE, &ak4117->kctls[9]->id);
	if (c1 & AK4117_NPCM)
		snd_ctl_notify(ak4117->card, SNDRV_CTL_EVENT_MASK_VALUE, &ak4117->kctls[10]->id);
	if (c1 & AK4117_DTSCD)
		snd_ctl_notify(ak4117->card, SNDRV_CTL_EVENT_MASK_VALUE, &ak4117->kctls[11]->id);
		
	if (ak4117->change_callback && (c0 | c1) != 0)
		ak4117->change_callback(ak4117, c0, c1);

      __rate:
	/* compare rate */
	res = external_rate(rcs1);
	if (!(flags & AK4117_CHECK_NO_RATE) && runtime && runtime->rate != res) {
		snd_pcm_stream_lock_irqsave(ak4117->substream, _flags);
		if (snd_pcm_running(ak4117->substream)) {
			// printk(KERN_DEBUG "rate changed (%i <- %i)\n", runtime->rate, res);
			snd_pcm_stop(ak4117->substream, SNDRV_PCM_STATE_DRAINING);
			wake_up(&runtime->sleep);
			res = 1;
		}
		snd_pcm_stream_unlock_irqrestore(ak4117->substream, _flags);
	}
	return res;
}

__attribute__((used)) static void snd_ak4117_timer(struct timer_list *t)
{
	struct ak4117 *chip = from_timer(chip, t, timer);

	if (chip->init)
		return;
	snd_ak4117_check_rate_and_errors(chip, 0);
	mod_timer(&chip->timer, 1 + jiffies);
}

