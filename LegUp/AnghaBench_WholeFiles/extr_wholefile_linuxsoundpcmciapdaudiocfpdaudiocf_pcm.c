#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_8__   TYPE_3__ ;
typedef  struct TYPE_7__   TYPE_2__ ;
typedef  struct TYPE_6__   TYPE_1__ ;

/* Type definitions */
typedef  unsigned short u16 ;
struct snd_pdacf {unsigned short* regmap; int chip_status; int pcm_little; int pcm_swab; int pcm_xor; int pcm_sample; int pcm_frame; TYPE_3__* ak4117; struct snd_pcm* pcm; TYPE_2__* card; int /*<<< orphan*/  pcm_hwptr; struct snd_pcm_substream* pcm_substream; int /*<<< orphan*/  pcm_area; int /*<<< orphan*/  pcm_period; int /*<<< orphan*/  pcm_size; int /*<<< orphan*/  pcm_channels; int /*<<< orphan*/  reg_lock; scalar_t__ pcm_running; int /*<<< orphan*/  pcm_tdone; scalar_t__ port; } ;
struct snd_pcm_substream {struct snd_pcm_runtime* runtime; } ;
struct snd_pcm_runtime {int rate; int format; struct snd_pdacf* private_data; int /*<<< orphan*/  hw; int /*<<< orphan*/  dma_area; int /*<<< orphan*/  period_size; int /*<<< orphan*/  buffer_size; int /*<<< orphan*/  channels; } ;
struct snd_pcm_hw_params {int dummy; } ;
struct snd_pcm {int nonatomic; TYPE_1__* streams; int /*<<< orphan*/  name; scalar_t__ info_flags; struct snd_pdacf* private_data; } ;
typedef  int /*<<< orphan*/  snd_pcm_uframes_t ;
struct TYPE_8__ {int rcs0; } ;
struct TYPE_7__ {int /*<<< orphan*/  shortname; } ;
struct TYPE_6__ {int /*<<< orphan*/  substream; } ;

/* Variables and functions */
 int AK4117_CHECK_NO_RATE ; 
 int AK4117_CHECK_NO_STAT ; 
 int AK4117_DIF0 ; 
 int AK4117_DIF1 ; 
 int AK4117_DIF2 ; 
 unsigned short AK4117_DIF_16R ; 
 unsigned short AK4117_DIF_24R ; 
 int /*<<< orphan*/  AK4117_REG_IO ; 
 int AK4117_UNLCK ; 
 int EBUSY ; 
 int EINVAL ; 
 int EIO ; 
 unsigned short PDAUDIOCF_DATAFMT0 ; 
 unsigned short PDAUDIOCF_DATAFMT1 ; 
 unsigned short PDAUDIOCF_IRQLVLEN0 ; 
 unsigned short PDAUDIOCF_IRQLVLEN1 ; 
 unsigned short PDAUDIOCF_RECORD ; 
 unsigned char PDAUDIOCF_REG_IER ; 
 scalar_t__ PDAUDIOCF_REG_MD ; 
 scalar_t__ PDAUDIOCF_REG_RDP ; 
 unsigned char PDAUDIOCF_REG_SCR ; 
 scalar_t__ PDAUDIOCF_REG_WDP ; 
 int PDAUDIOCF_STAT_IS_STALE ; 
#define  SNDRV_PCM_FORMAT_S16_BE 137 
#define  SNDRV_PCM_FORMAT_S16_LE 136 
#define  SNDRV_PCM_FORMAT_S24_3BE 135 
#define  SNDRV_PCM_FORMAT_S24_3LE 134 
 size_t SNDRV_PCM_STREAM_CAPTURE ; 
#define  SNDRV_PCM_TRIGGER_PAUSE_PUSH 133 
#define  SNDRV_PCM_TRIGGER_PAUSE_RELEASE 132 
#define  SNDRV_PCM_TRIGGER_RESUME 131 
#define  SNDRV_PCM_TRIGGER_START 130 
#define  SNDRV_PCM_TRIGGER_STOP 129 
#define  SNDRV_PCM_TRIGGER_SUSPEND 128 
 scalar_t__ inw (scalar_t__) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  outw (unsigned short,scalar_t__) ; 
 int /*<<< orphan*/  params_buffer_bytes (struct snd_pcm_hw_params*) ; 
 int /*<<< orphan*/  pdacf_pcm_capture_hw ; 
 int /*<<< orphan*/  pdacf_pcm_capture_ops ; 
 int /*<<< orphan*/  pdacf_reinit (struct snd_pdacf*,int /*<<< orphan*/ ) ; 
 int snd_ak4117_build (TYPE_3__*,int /*<<< orphan*/ ) ; 
 int snd_ak4117_check_rate_and_errors (TYPE_3__*,int) ; 
 int /*<<< orphan*/  snd_ak4117_reg_write (TYPE_3__*,int /*<<< orphan*/ ,int,unsigned short) ; 
 scalar_t__ snd_pcm_format_little_endian (int) ; 
 scalar_t__ snd_pcm_format_unsigned (int) ; 
 int snd_pcm_lib_alloc_vmalloc_32_buffer (struct snd_pcm_substream*,int /*<<< orphan*/ ) ; 
 int snd_pcm_lib_free_vmalloc_buffer (struct snd_pcm_substream*) ; 
 int snd_pcm_new (TYPE_2__*,char*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int,struct snd_pcm**) ; 
 int /*<<< orphan*/  snd_pcm_set_ops (struct snd_pcm*,size_t,int /*<<< orphan*/ *) ; 
 struct snd_pdacf* snd_pcm_substream_chip (struct snd_pcm_substream*) ; 
 int /*<<< orphan*/  strcpy (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

__attribute__((used)) static inline void pdacf_reg_write(struct snd_pdacf *chip, unsigned char reg, unsigned short val)
{
	outw(chip->regmap[reg>>1] = val, chip->port + reg);
}

__attribute__((used)) static inline unsigned short pdacf_reg_read(struct snd_pdacf *chip, unsigned char reg)
{
	return inw(chip->port + reg);
}

__attribute__((used)) static int pdacf_pcm_clear_sram(struct snd_pdacf *chip)
{
	int max_loop = 64 * 1024;

	while (inw(chip->port + PDAUDIOCF_REG_RDP) != inw(chip->port + PDAUDIOCF_REG_WDP)) {
		if (max_loop-- < 0)
			return -EIO;
		inw(chip->port + PDAUDIOCF_REG_MD);
	}
	return 0;
}

__attribute__((used)) static int pdacf_pcm_trigger(struct snd_pcm_substream *subs, int cmd)
{
	struct snd_pdacf *chip = snd_pcm_substream_chip(subs);
	struct snd_pcm_runtime *runtime = subs->runtime;
	int inc, ret = 0, rate;
	unsigned short mask, val, tmp;

	if (chip->chip_status & PDAUDIOCF_STAT_IS_STALE)
		return -EBUSY;

	switch (cmd) {
	case SNDRV_PCM_TRIGGER_START:
		chip->pcm_hwptr = 0;
		chip->pcm_tdone = 0;
		/* fall thru */
	case SNDRV_PCM_TRIGGER_PAUSE_RELEASE:
	case SNDRV_PCM_TRIGGER_RESUME:
		mask = 0;
		val = PDAUDIOCF_RECORD;
		inc = 1;
		rate = snd_ak4117_check_rate_and_errors(chip->ak4117, AK4117_CHECK_NO_STAT|AK4117_CHECK_NO_RATE);
		break;
	case SNDRV_PCM_TRIGGER_STOP:
	case SNDRV_PCM_TRIGGER_PAUSE_PUSH:
	case SNDRV_PCM_TRIGGER_SUSPEND:
		mask = PDAUDIOCF_RECORD;
		val = 0;
		inc = -1;
		rate = 0;
		break;
	default:
		return -EINVAL;
	}
	mutex_lock(&chip->reg_lock);
	chip->pcm_running += inc;
	tmp = pdacf_reg_read(chip, PDAUDIOCF_REG_SCR);
	if (chip->pcm_running) {
		if ((chip->ak4117->rcs0 & AK4117_UNLCK) || runtime->rate != rate) {
			chip->pcm_running -= inc;
			ret = -EIO;
			goto __end;
		}
	}
	tmp &= ~mask;
	tmp |= val;
	pdacf_reg_write(chip, PDAUDIOCF_REG_SCR, tmp);
      __end:
	mutex_unlock(&chip->reg_lock);
	snd_ak4117_check_rate_and_errors(chip->ak4117, AK4117_CHECK_NO_RATE);
	return ret;
}

__attribute__((used)) static int pdacf_pcm_hw_params(struct snd_pcm_substream *subs,
				     struct snd_pcm_hw_params *hw_params)
{
	return snd_pcm_lib_alloc_vmalloc_32_buffer
					(subs, params_buffer_bytes(hw_params));
}

__attribute__((used)) static int pdacf_pcm_hw_free(struct snd_pcm_substream *subs)
{
	return snd_pcm_lib_free_vmalloc_buffer(subs);
}

__attribute__((used)) static int pdacf_pcm_prepare(struct snd_pcm_substream *subs)
{
	struct snd_pdacf *chip = snd_pcm_substream_chip(subs);
	struct snd_pcm_runtime *runtime = subs->runtime;
	u16 val, nval, aval;

	if (chip->chip_status & PDAUDIOCF_STAT_IS_STALE)
		return -EBUSY;

	chip->pcm_channels = runtime->channels;

	chip->pcm_little = snd_pcm_format_little_endian(runtime->format) > 0;
#ifdef SNDRV_LITTLE_ENDIAN
	chip->pcm_swab = snd_pcm_format_big_endian(runtime->format) > 0;
#else
	chip->pcm_swab = chip->pcm_little;
#endif

	if (snd_pcm_format_unsigned(runtime->format))
		chip->pcm_xor = 0x80008000;

	if (pdacf_pcm_clear_sram(chip) < 0)
		return -EIO;
	
	val = nval = pdacf_reg_read(chip, PDAUDIOCF_REG_SCR);
	nval &= ~(PDAUDIOCF_DATAFMT0|PDAUDIOCF_DATAFMT1);
	switch (runtime->format) {
	case SNDRV_PCM_FORMAT_S16_LE:
	case SNDRV_PCM_FORMAT_S16_BE:
		break;
	default: /* 24-bit */
		nval |= PDAUDIOCF_DATAFMT0 | PDAUDIOCF_DATAFMT1;
		break;
	}
	aval = 0;
	chip->pcm_sample = 4;
	switch (runtime->format) {
	case SNDRV_PCM_FORMAT_S16_LE:
	case SNDRV_PCM_FORMAT_S16_BE:
		aval = AK4117_DIF_16R;
		chip->pcm_frame = 2;
		chip->pcm_sample = 2;
		break;
	case SNDRV_PCM_FORMAT_S24_3LE:
	case SNDRV_PCM_FORMAT_S24_3BE:
		chip->pcm_sample = 3;
		/* fall through */
	default: /* 24-bit */
		aval = AK4117_DIF_24R;
		chip->pcm_frame = 3;
		chip->pcm_xor &= 0xffff0000;
		break;
	}

	if (val != nval) {
		snd_ak4117_reg_write(chip->ak4117, AK4117_REG_IO, AK4117_DIF2|AK4117_DIF1|AK4117_DIF0, aval);
		pdacf_reg_write(chip, PDAUDIOCF_REG_SCR, nval);
	}

	val = pdacf_reg_read(chip,  PDAUDIOCF_REG_IER);
	val &= ~(PDAUDIOCF_IRQLVLEN1);
	val |= PDAUDIOCF_IRQLVLEN0;
	pdacf_reg_write(chip, PDAUDIOCF_REG_IER, val);

	chip->pcm_size = runtime->buffer_size;
	chip->pcm_period = runtime->period_size;
	chip->pcm_area = runtime->dma_area;

	return 0;
}

__attribute__((used)) static int pdacf_pcm_capture_open(struct snd_pcm_substream *subs)
{
	struct snd_pcm_runtime *runtime = subs->runtime;
	struct snd_pdacf *chip = snd_pcm_substream_chip(subs);

	if (chip->chip_status & PDAUDIOCF_STAT_IS_STALE)
		return -EBUSY;

	runtime->hw = pdacf_pcm_capture_hw;
	runtime->private_data = chip;
	chip->pcm_substream = subs;

	return 0;
}

__attribute__((used)) static int pdacf_pcm_capture_close(struct snd_pcm_substream *subs)
{
	struct snd_pdacf *chip = snd_pcm_substream_chip(subs);

	if (!chip)
		return -EINVAL;
	pdacf_reinit(chip, 0);
	chip->pcm_substream = NULL;
	return 0;
}

__attribute__((used)) static snd_pcm_uframes_t pdacf_pcm_capture_pointer(struct snd_pcm_substream *subs)
{
	struct snd_pdacf *chip = snd_pcm_substream_chip(subs);
	return chip->pcm_hwptr;
}

int snd_pdacf_pcm_new(struct snd_pdacf *chip)
{
	struct snd_pcm *pcm;
	int err;

	err = snd_pcm_new(chip->card, "PDAudioCF", 0, 0, 1, &pcm);
	if (err < 0)
		return err;
		
	snd_pcm_set_ops(pcm, SNDRV_PCM_STREAM_CAPTURE, &pdacf_pcm_capture_ops);

	pcm->private_data = chip;
	pcm->info_flags = 0;
	pcm->nonatomic = true;
	strcpy(pcm->name, chip->card->shortname);
	chip->pcm = pcm;
	
	err = snd_ak4117_build(chip->ak4117, pcm->streams[SNDRV_PCM_STREAM_CAPTURE].substream);
	if (err < 0)
		return err;

	return 0;
}

