#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
struct snd_sb {int hardware; int mode; unsigned int playback_format; int dma16; int dma8; unsigned int p_dma_size; unsigned int p_period_size; unsigned int force_mode16; scalar_t__ capture_format; unsigned int c_dma_size; unsigned int c_period_size; int open; int version; struct snd_card* card; int /*<<< orphan*/  open_lock; struct snd_pcm_substream* capture_substream; struct snd_pcm_substream* playback_substream; int /*<<< orphan*/  reg_lock; int /*<<< orphan*/  mixer_lock; } ;
struct snd_pcm_substream {scalar_t__ stream; struct snd_pcm_runtime* runtime; } ;
struct TYPE_3__ {int rate_min; int rate_max; int channels_max; int buffer_bytes_max; int period_bytes_max; int /*<<< orphan*/  rates; int /*<<< orphan*/  formats; } ;
struct snd_pcm_runtime {int channels; unsigned int rate; int* dma_area; int rate_den; TYPE_1__ hw; int /*<<< orphan*/  dma_addr; int /*<<< orphan*/  format; } ;
struct snd_pcm_hw_rule {int dummy; } ;
struct snd_pcm_hw_params {unsigned int rate_num; unsigned int rate_den; } ;
struct snd_pcm {struct snd_sb* private_data; int /*<<< orphan*/  info_flags; int /*<<< orphan*/  name; } ;
struct snd_interval {int min; scalar_t__ max; } ;
struct snd_card {int dummy; } ;
typedef  int /*<<< orphan*/  snd_pcm_uframes_t ;
typedef  int /*<<< orphan*/  irqreturn_t ;

/* Variables and functions */
 int DMA_AUTOINIT ; 
 int DMA_MODE_READ ; 
 int DMA_MODE_WRITE ; 
 int EAGAIN ; 
 int EBUSY ; 
 int EINVAL ; 
 int /*<<< orphan*/  IRQ_HANDLED ; 
 unsigned int SB8_RATE (int) ; 
 unsigned int SB_DSP_BLOCK_SIZE ; 
 int /*<<< orphan*/  SB_DSP_CAPTURE_FILT ; 
 unsigned int SB_DSP_DMA8_EXIT ; 
 unsigned int SB_DSP_DMA8_OFF ; 
 void* SB_DSP_HI_INPUT_AUTO ; 
 void* SB_DSP_HI_OUTPUT_AUTO ; 
 scalar_t__ SB_DSP_INPUT ; 
 void* SB_DSP_LO_INPUT_AUTO ; 
 void* SB_DSP_LO_OUTPUT_AUTO ; 
 unsigned char SB_DSP_MONO_16BIT ; 
 unsigned int SB_DSP_MONO_8BIT ; 
 unsigned int SB_DSP_OUTPUT ; 
 int /*<<< orphan*/  SB_DSP_PLAYBACK_FILT ; 
 unsigned int SB_DSP_SAMPLE_RATE ; 
 unsigned int SB_DSP_SPEAKER_OFF ; 
 unsigned int SB_DSP_SPEAKER_ON ; 
 unsigned char SB_DSP_STEREO_16BIT ; 
 unsigned int SB_DSP_STEREO_8BIT ; 
 int /*<<< orphan*/  SB_DSP_STEREO_SW ; 
#define  SB_HW_10 138 
#define  SB_HW_20 137 
#define  SB_HW_201 136 
#define  SB_HW_JAZZ16 135 
#define  SB_HW_PRO 134 
 int SB_MODE_CAPTURE ; 
#define  SB_MODE_CAPTURE_16 133 
#define  SB_MODE_CAPTURE_8 132 
 int SB_MODE_PLAYBACK ; 
#define  SB_MODE_PLAYBACK_16 131 
#define  SB_MODE_PLAYBACK_8 130 
 int SB_OPEN_PCM ; 
 int /*<<< orphan*/  SNDRV_DMA_TYPE_DEV ; 
 int /*<<< orphan*/  SNDRV_PCM_FMTBIT_S16_LE ; 
 int /*<<< orphan*/  SNDRV_PCM_FORMAT_S16_LE ; 
 int /*<<< orphan*/  SNDRV_PCM_HW_PARAM_BUFFER_BYTES ; 
 int /*<<< orphan*/  SNDRV_PCM_HW_PARAM_CHANNELS ; 
 int /*<<< orphan*/  SNDRV_PCM_HW_PARAM_PERIOD_BYTES ; 
 int /*<<< orphan*/  SNDRV_PCM_HW_PARAM_RATE ; 
 int /*<<< orphan*/  SNDRV_PCM_INFO_HALF_DUPLEX ; 
 int /*<<< orphan*/  SNDRV_PCM_RATE_8000_48000 ; 
 scalar_t__ SNDRV_PCM_STREAM_CAPTURE ; 
 scalar_t__ SNDRV_PCM_STREAM_PLAYBACK ; 
#define  SNDRV_PCM_TRIGGER_START 129 
#define  SNDRV_PCM_TRIGGER_STOP 128 
 int /*<<< orphan*/  bytes_to_frames (struct snd_pcm_runtime*,size_t) ; 
 int /*<<< orphan*/  hw_constraints_clock ; 
 struct snd_interval* hw_param_interval (struct snd_pcm_hw_params*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  params_buffer_bytes (struct snd_pcm_hw_params*) ; 
 int /*<<< orphan*/  snd_BUG_ON (int) ; 
 int /*<<< orphan*/  snd_dma_isa_data () ; 
 size_t snd_dma_pointer (int,unsigned int) ; 
 int /*<<< orphan*/  snd_dma_program (int,int /*<<< orphan*/ ,unsigned int,int) ; 
 int snd_interval_ratnum (struct snd_interval*,int,int /*<<< orphan*/ ,unsigned int*,unsigned int*) ; 
 int snd_interval_refine (struct snd_interval*,struct snd_interval*) ; 
 int /*<<< orphan*/  snd_pcm_hw_constraint_ratnums (struct snd_pcm_runtime*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  snd_pcm_hw_constraint_step (struct snd_pcm_runtime*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  snd_pcm_hw_rule_add (struct snd_pcm_runtime*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int (*) (struct snd_pcm_hw_params*,struct snd_pcm_hw_rule*),int /*<<< orphan*/ *,int /*<<< orphan*/ ,int,...) ; 
 void* snd_pcm_lib_buffer_bytes (struct snd_pcm_substream*) ; 
 int /*<<< orphan*/  snd_pcm_lib_free_pages (struct snd_pcm_substream*) ; 
 int snd_pcm_lib_malloc_pages (struct snd_pcm_substream*,int /*<<< orphan*/ ) ; 
 void* snd_pcm_lib_period_bytes (struct snd_pcm_substream*) ; 
 int /*<<< orphan*/  snd_pcm_lib_preallocate_pages_for_all (struct snd_pcm*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int,size_t) ; 
 int snd_pcm_new (struct snd_card*,char*,int,int,int,struct snd_pcm**) ; 
 int /*<<< orphan*/  snd_pcm_period_elapsed (struct snd_pcm_substream*) ; 
 int /*<<< orphan*/  snd_pcm_set_ops (struct snd_pcm*,scalar_t__,int /*<<< orphan*/ *) ; 
 struct snd_sb* snd_pcm_substream_chip (struct snd_pcm_substream*) ; 
 TYPE_1__ snd_sb8_capture ; 
 int /*<<< orphan*/  snd_sb8_capture_ops ; 
 TYPE_1__ snd_sb8_playback ; 
 int /*<<< orphan*/  snd_sb8_playback_ops ; 
 int /*<<< orphan*/  snd_sb_ack_8bit (struct snd_sb*) ; 
 int /*<<< orphan*/  snd_sbdsp_command (struct snd_sb*,unsigned int) ; 
 int /*<<< orphan*/  snd_sbdsp_reset (struct snd_sb*) ; 
 unsigned int snd_sbmixer_read (struct snd_sb*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  snd_sbmixer_write (struct snd_sb*,int /*<<< orphan*/ ,unsigned int) ; 
 int /*<<< orphan*/  spin_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  spin_lock_irqsave (int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  spin_unlock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  spin_unlock_irqrestore (int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  sprintf (int /*<<< orphan*/ ,char*,int,int) ; 
 int /*<<< orphan*/  stereo_clocks ; 

__attribute__((used)) static int snd_sb8_hw_constraint_rate_channels(struct snd_pcm_hw_params *params,
					       struct snd_pcm_hw_rule *rule)
{
	struct snd_interval *c = hw_param_interval(params, SNDRV_PCM_HW_PARAM_CHANNELS);
	if (c->min > 1) {
	  	unsigned int num = 0, den = 0;
		int err = snd_interval_ratnum(hw_param_interval(params, SNDRV_PCM_HW_PARAM_RATE),
					  2, stereo_clocks, &num, &den);
		if (err >= 0 && den) {
			params->rate_num = num;
			params->rate_den = den;
		}
		return err;
	}
	return 0;
}

__attribute__((used)) static int snd_sb8_hw_constraint_channels_rate(struct snd_pcm_hw_params *params,
					       struct snd_pcm_hw_rule *rule)
{
	struct snd_interval *r = hw_param_interval(params, SNDRV_PCM_HW_PARAM_RATE);
	if (r->min > SB8_RATE(22050) || r->max <= SB8_RATE(11025)) {
		struct snd_interval t = { .min = 1, .max = 1 };
		return snd_interval_refine(hw_param_interval(params, SNDRV_PCM_HW_PARAM_CHANNELS), &t);
	}
	return 0;
}

__attribute__((used)) static int snd_sb8_playback_prepare(struct snd_pcm_substream *substream)
{
	unsigned long flags;
	struct snd_sb *chip = snd_pcm_substream_chip(substream);
	struct snd_pcm_runtime *runtime = substream->runtime;
	unsigned int mixreg, rate, size, count;
	unsigned char format;
	unsigned char stereo = runtime->channels > 1;
	int dma;

	rate = runtime->rate;
	switch (chip->hardware) {
	case SB_HW_JAZZ16:
		if (runtime->format == SNDRV_PCM_FORMAT_S16_LE) {
			if (chip->mode & SB_MODE_CAPTURE_16)
				return -EBUSY;
			else
				chip->mode |= SB_MODE_PLAYBACK_16;
		}
		chip->playback_format = SB_DSP_LO_OUTPUT_AUTO;
		break;
	case SB_HW_PRO:
		if (runtime->channels > 1) {
			if (snd_BUG_ON(rate != SB8_RATE(11025) &&
				       rate != SB8_RATE(22050)))
				return -EINVAL;
			chip->playback_format = SB_DSP_HI_OUTPUT_AUTO;
			break;
		}
		/* fallthru */
	case SB_HW_201:
		if (rate > 23000) {
			chip->playback_format = SB_DSP_HI_OUTPUT_AUTO;
			break;
		}
		/* fallthru */
	case SB_HW_20:
		chip->playback_format = SB_DSP_LO_OUTPUT_AUTO;
		break;
	case SB_HW_10:
		chip->playback_format = SB_DSP_OUTPUT;
		break;
	default:
		return -EINVAL;
	}
	if (chip->mode & SB_MODE_PLAYBACK_16) {
		format = stereo ? SB_DSP_STEREO_16BIT : SB_DSP_MONO_16BIT;
		dma = chip->dma16;
	} else {
		format = stereo ? SB_DSP_STEREO_8BIT : SB_DSP_MONO_8BIT;
		chip->mode |= SB_MODE_PLAYBACK_8;
		dma = chip->dma8;
	}
	size = chip->p_dma_size = snd_pcm_lib_buffer_bytes(substream);
	count = chip->p_period_size = snd_pcm_lib_period_bytes(substream);
	spin_lock_irqsave(&chip->reg_lock, flags);
	snd_sbdsp_command(chip, SB_DSP_SPEAKER_ON);
	if (chip->hardware == SB_HW_JAZZ16)
		snd_sbdsp_command(chip, format);
	else if (stereo) {
		/* set playback stereo mode */
		spin_lock(&chip->mixer_lock);
		mixreg = snd_sbmixer_read(chip, SB_DSP_STEREO_SW);
		snd_sbmixer_write(chip, SB_DSP_STEREO_SW, mixreg | 0x02);
		spin_unlock(&chip->mixer_lock);

		/* Soundblaster hardware programming reference guide, 3-23 */
		snd_sbdsp_command(chip, SB_DSP_DMA8_EXIT);
		runtime->dma_area[0] = 0x80;
		snd_dma_program(dma, runtime->dma_addr, 1, DMA_MODE_WRITE);
		/* force interrupt */
		snd_sbdsp_command(chip, SB_DSP_OUTPUT);
		snd_sbdsp_command(chip, 0);
		snd_sbdsp_command(chip, 0);
	}
	snd_sbdsp_command(chip, SB_DSP_SAMPLE_RATE);
	if (stereo) {
		snd_sbdsp_command(chip, 256 - runtime->rate_den / 2);
		spin_lock(&chip->mixer_lock);
		/* save output filter status and turn it off */
		mixreg = snd_sbmixer_read(chip, SB_DSP_PLAYBACK_FILT);
		snd_sbmixer_write(chip, SB_DSP_PLAYBACK_FILT, mixreg | 0x20);
		spin_unlock(&chip->mixer_lock);
		/* just use force_mode16 for temporary storate... */
		chip->force_mode16 = mixreg;
	} else {
		snd_sbdsp_command(chip, 256 - runtime->rate_den);
	}
	if (chip->playback_format != SB_DSP_OUTPUT) {
		if (chip->mode & SB_MODE_PLAYBACK_16)
			count /= 2;
		count--;
		snd_sbdsp_command(chip, SB_DSP_BLOCK_SIZE);
		snd_sbdsp_command(chip, count & 0xff);
		snd_sbdsp_command(chip, count >> 8);
	}
	spin_unlock_irqrestore(&chip->reg_lock, flags);
	snd_dma_program(dma, runtime->dma_addr,
			size, DMA_MODE_WRITE | DMA_AUTOINIT);
	return 0;
}

__attribute__((used)) static int snd_sb8_playback_trigger(struct snd_pcm_substream *substream,
				    int cmd)
{
	unsigned long flags;
	struct snd_sb *chip = snd_pcm_substream_chip(substream);
	unsigned int count;

	spin_lock_irqsave(&chip->reg_lock, flags);
	switch (cmd) {
	case SNDRV_PCM_TRIGGER_START:
		snd_sbdsp_command(chip, chip->playback_format);
		if (chip->playback_format == SB_DSP_OUTPUT) {
			count = chip->p_period_size - 1;
			snd_sbdsp_command(chip, count & 0xff);
			snd_sbdsp_command(chip, count >> 8);
		}
		break;
	case SNDRV_PCM_TRIGGER_STOP:
		if (chip->playback_format == SB_DSP_HI_OUTPUT_AUTO) {
			struct snd_pcm_runtime *runtime = substream->runtime;
			snd_sbdsp_reset(chip);
			if (runtime->channels > 1) {
				spin_lock(&chip->mixer_lock);
				/* restore output filter and set hardware to mono mode */ 
				snd_sbmixer_write(chip, SB_DSP_STEREO_SW, chip->force_mode16 & ~0x02);
				spin_unlock(&chip->mixer_lock);
			}
		} else {
			snd_sbdsp_command(chip, SB_DSP_DMA8_OFF);
		}
		snd_sbdsp_command(chip, SB_DSP_SPEAKER_OFF);
	}
	spin_unlock_irqrestore(&chip->reg_lock, flags);
	return 0;
}

__attribute__((used)) static int snd_sb8_hw_params(struct snd_pcm_substream *substream,
			     struct snd_pcm_hw_params *hw_params)
{
	return snd_pcm_lib_malloc_pages(substream, params_buffer_bytes(hw_params));
}

__attribute__((used)) static int snd_sb8_hw_free(struct snd_pcm_substream *substream)
{
	snd_pcm_lib_free_pages(substream);
	return 0;
}

__attribute__((used)) static int snd_sb8_capture_prepare(struct snd_pcm_substream *substream)
{
	unsigned long flags;
	struct snd_sb *chip = snd_pcm_substream_chip(substream);
	struct snd_pcm_runtime *runtime = substream->runtime;
	unsigned int mixreg, rate, size, count;
	unsigned char format;
	unsigned char stereo = runtime->channels > 1;
	int dma;

	rate = runtime->rate;
	switch (chip->hardware) {
	case SB_HW_JAZZ16:
		if (runtime->format == SNDRV_PCM_FORMAT_S16_LE) {
			if (chip->mode & SB_MODE_PLAYBACK_16)
				return -EBUSY;
			else
				chip->mode |= SB_MODE_CAPTURE_16;
		}
		chip->capture_format = SB_DSP_LO_INPUT_AUTO;
		break;
	case SB_HW_PRO:
		if (runtime->channels > 1) {
			if (snd_BUG_ON(rate != SB8_RATE(11025) &&
				       rate != SB8_RATE(22050)))
				return -EINVAL;
			chip->capture_format = SB_DSP_HI_INPUT_AUTO;
			break;
		}
		chip->capture_format = (rate > 23000) ? SB_DSP_HI_INPUT_AUTO : SB_DSP_LO_INPUT_AUTO;
		break;
	case SB_HW_201:
		if (rate > 13000) {
			chip->capture_format = SB_DSP_HI_INPUT_AUTO;
			break;
		}
		/* fallthru */
	case SB_HW_20:
		chip->capture_format = SB_DSP_LO_INPUT_AUTO;
		break;
	case SB_HW_10:
		chip->capture_format = SB_DSP_INPUT;
		break;
	default:
		return -EINVAL;
	}
	if (chip->mode & SB_MODE_CAPTURE_16) {
		format = stereo ? SB_DSP_STEREO_16BIT : SB_DSP_MONO_16BIT;
		dma = chip->dma16;
	} else {
		format = stereo ? SB_DSP_STEREO_8BIT : SB_DSP_MONO_8BIT;
		chip->mode |= SB_MODE_CAPTURE_8;
		dma = chip->dma8;
	}
	size = chip->c_dma_size = snd_pcm_lib_buffer_bytes(substream);
	count = chip->c_period_size = snd_pcm_lib_period_bytes(substream);
	spin_lock_irqsave(&chip->reg_lock, flags);
	snd_sbdsp_command(chip, SB_DSP_SPEAKER_OFF);
	if (chip->hardware == SB_HW_JAZZ16)
		snd_sbdsp_command(chip, format);
	else if (stereo)
		snd_sbdsp_command(chip, SB_DSP_STEREO_8BIT);
	snd_sbdsp_command(chip, SB_DSP_SAMPLE_RATE);
	if (stereo) {
		snd_sbdsp_command(chip, 256 - runtime->rate_den / 2);
		spin_lock(&chip->mixer_lock);
		/* save input filter status and turn it off */
		mixreg = snd_sbmixer_read(chip, SB_DSP_CAPTURE_FILT);
		snd_sbmixer_write(chip, SB_DSP_CAPTURE_FILT, mixreg | 0x20);
		spin_unlock(&chip->mixer_lock);
		/* just use force_mode16 for temporary storate... */
		chip->force_mode16 = mixreg;
	} else {
		snd_sbdsp_command(chip, 256 - runtime->rate_den);
	}
	if (chip->capture_format != SB_DSP_INPUT) {
		if (chip->mode & SB_MODE_PLAYBACK_16)
			count /= 2;
		count--;
		snd_sbdsp_command(chip, SB_DSP_BLOCK_SIZE);
		snd_sbdsp_command(chip, count & 0xff);
		snd_sbdsp_command(chip, count >> 8);
	}
	spin_unlock_irqrestore(&chip->reg_lock, flags);
	snd_dma_program(dma, runtime->dma_addr,
			size, DMA_MODE_READ | DMA_AUTOINIT);
	return 0;
}

__attribute__((used)) static int snd_sb8_capture_trigger(struct snd_pcm_substream *substream,
				   int cmd)
{
	unsigned long flags;
	struct snd_sb *chip = snd_pcm_substream_chip(substream);
	unsigned int count;

	spin_lock_irqsave(&chip->reg_lock, flags);
	switch (cmd) {
	case SNDRV_PCM_TRIGGER_START:
		snd_sbdsp_command(chip, chip->capture_format);
		if (chip->capture_format == SB_DSP_INPUT) {
			count = chip->c_period_size - 1;
			snd_sbdsp_command(chip, count & 0xff);
			snd_sbdsp_command(chip, count >> 8);
		}
		break;
	case SNDRV_PCM_TRIGGER_STOP:
		if (chip->capture_format == SB_DSP_HI_INPUT_AUTO) {
			struct snd_pcm_runtime *runtime = substream->runtime;
			snd_sbdsp_reset(chip);
			if (runtime->channels > 1) {
				/* restore input filter status */
				spin_lock(&chip->mixer_lock);
				snd_sbmixer_write(chip, SB_DSP_CAPTURE_FILT, chip->force_mode16);
				spin_unlock(&chip->mixer_lock);
				/* set hardware to mono mode */
				snd_sbdsp_command(chip, SB_DSP_MONO_8BIT);
			}
		} else {
			snd_sbdsp_command(chip, SB_DSP_DMA8_OFF);
		}
		snd_sbdsp_command(chip, SB_DSP_SPEAKER_OFF);
	}
	spin_unlock_irqrestore(&chip->reg_lock, flags);
	return 0;
}

irqreturn_t snd_sb8dsp_interrupt(struct snd_sb *chip)
{
	struct snd_pcm_substream *substream;

	snd_sb_ack_8bit(chip);
	switch (chip->mode) {
	case SB_MODE_PLAYBACK_16:	/* ok.. playback is active */
		if (chip->hardware != SB_HW_JAZZ16)
			break;
		/* fallthru */
	case SB_MODE_PLAYBACK_8:
		substream = chip->playback_substream;
		if (chip->playback_format == SB_DSP_OUTPUT)
		    	snd_sb8_playback_trigger(substream, SNDRV_PCM_TRIGGER_START);
		snd_pcm_period_elapsed(substream);
		break;
	case SB_MODE_CAPTURE_16:
		if (chip->hardware != SB_HW_JAZZ16)
			break;
		/* fallthru */
	case SB_MODE_CAPTURE_8:
		substream = chip->capture_substream;
		if (chip->capture_format == SB_DSP_INPUT)
		    	snd_sb8_capture_trigger(substream, SNDRV_PCM_TRIGGER_START);
		snd_pcm_period_elapsed(substream);
		break;
	}
	return IRQ_HANDLED;
}

__attribute__((used)) static snd_pcm_uframes_t snd_sb8_playback_pointer(struct snd_pcm_substream *substream)
{
	struct snd_sb *chip = snd_pcm_substream_chip(substream);
	size_t ptr;
	int dma;

	if (chip->mode & SB_MODE_PLAYBACK_8)
		dma = chip->dma8;
	else if (chip->mode & SB_MODE_PLAYBACK_16)
		dma = chip->dma16;
	else
		return 0;
	ptr = snd_dma_pointer(dma, chip->p_dma_size);
	return bytes_to_frames(substream->runtime, ptr);
}

__attribute__((used)) static snd_pcm_uframes_t snd_sb8_capture_pointer(struct snd_pcm_substream *substream)
{
	struct snd_sb *chip = snd_pcm_substream_chip(substream);
	size_t ptr;
	int dma;

	if (chip->mode & SB_MODE_CAPTURE_8)
		dma = chip->dma8;
	else if (chip->mode & SB_MODE_CAPTURE_16)
		dma = chip->dma16;
	else
		return 0;
	ptr = snd_dma_pointer(dma, chip->c_dma_size);
	return bytes_to_frames(substream->runtime, ptr);
}

__attribute__((used)) static int snd_sb8_open(struct snd_pcm_substream *substream)
{
	struct snd_sb *chip = snd_pcm_substream_chip(substream);
	struct snd_pcm_runtime *runtime = substream->runtime;
	unsigned long flags;

	spin_lock_irqsave(&chip->open_lock, flags);
	if (chip->open) {
		spin_unlock_irqrestore(&chip->open_lock, flags);
		return -EAGAIN;
	}
	chip->open |= SB_OPEN_PCM;
	spin_unlock_irqrestore(&chip->open_lock, flags);
	if (substream->stream == SNDRV_PCM_STREAM_PLAYBACK) {
		chip->playback_substream = substream;
		runtime->hw = snd_sb8_playback;
	} else {
		chip->capture_substream = substream;
		runtime->hw = snd_sb8_capture;
	}
	switch (chip->hardware) {
	case SB_HW_JAZZ16:
		if (chip->dma16 == 5 || chip->dma16 == 7)
			runtime->hw.formats |= SNDRV_PCM_FMTBIT_S16_LE;
		runtime->hw.rates |= SNDRV_PCM_RATE_8000_48000;
		runtime->hw.rate_min = 4000;
		runtime->hw.rate_max = 50000;
		runtime->hw.channels_max = 2;
		break;
	case SB_HW_PRO:
		runtime->hw.rate_max = 44100;
		runtime->hw.channels_max = 2;
		snd_pcm_hw_rule_add(runtime, 0, SNDRV_PCM_HW_PARAM_RATE,
				    snd_sb8_hw_constraint_rate_channels, NULL,
				    SNDRV_PCM_HW_PARAM_CHANNELS,
				    SNDRV_PCM_HW_PARAM_RATE, -1);
		snd_pcm_hw_rule_add(runtime, 0, SNDRV_PCM_HW_PARAM_CHANNELS,
				     snd_sb8_hw_constraint_channels_rate, NULL,
				     SNDRV_PCM_HW_PARAM_RATE, -1);
		break;
	case SB_HW_201:
		if (substream->stream == SNDRV_PCM_STREAM_PLAYBACK) {
			runtime->hw.rate_max = 44100;
		} else {
			runtime->hw.rate_max = 15000;
		}
	default:
		break;
	}
	snd_pcm_hw_constraint_ratnums(runtime, 0, SNDRV_PCM_HW_PARAM_RATE,
				      &hw_constraints_clock);
	if (chip->dma8 > 3 || chip->dma16 >= 0) {
		snd_pcm_hw_constraint_step(runtime, 0,
					   SNDRV_PCM_HW_PARAM_BUFFER_BYTES, 2);
		snd_pcm_hw_constraint_step(runtime, 0,
					   SNDRV_PCM_HW_PARAM_PERIOD_BYTES, 2);
		runtime->hw.buffer_bytes_max = 128 * 1024 * 1024;
		runtime->hw.period_bytes_max = 128 * 1024 * 1024;
	}
	return 0;	
}

__attribute__((used)) static int snd_sb8_close(struct snd_pcm_substream *substream)
{
	unsigned long flags;
	struct snd_sb *chip = snd_pcm_substream_chip(substream);

	chip->playback_substream = NULL;
	chip->capture_substream = NULL;
	spin_lock_irqsave(&chip->open_lock, flags);
	chip->open &= ~SB_OPEN_PCM;
	if (substream->stream == SNDRV_PCM_STREAM_PLAYBACK)
		chip->mode &= ~SB_MODE_PLAYBACK;
	else
		chip->mode &= ~SB_MODE_CAPTURE;
	spin_unlock_irqrestore(&chip->open_lock, flags);
	return 0;
}

int snd_sb8dsp_pcm(struct snd_sb *chip, int device)
{
	struct snd_card *card = chip->card;
	struct snd_pcm *pcm;
	int err;
	size_t max_prealloc = 64 * 1024;

	if ((err = snd_pcm_new(card, "SB8 DSP", device, 1, 1, &pcm)) < 0)
		return err;
	sprintf(pcm->name, "DSP v%i.%i", chip->version >> 8, chip->version & 0xff);
	pcm->info_flags = SNDRV_PCM_INFO_HALF_DUPLEX;
	pcm->private_data = chip;

	snd_pcm_set_ops(pcm, SNDRV_PCM_STREAM_PLAYBACK, &snd_sb8_playback_ops);
	snd_pcm_set_ops(pcm, SNDRV_PCM_STREAM_CAPTURE, &snd_sb8_capture_ops);

	if (chip->dma8 > 3 || chip->dma16 >= 0)
		max_prealloc = 128 * 1024;
	snd_pcm_lib_preallocate_pages_for_all(pcm, SNDRV_DMA_TYPE_DEV,
					      snd_dma_isa_data(),
					      64*1024, max_prealloc);

	return 0;
}

