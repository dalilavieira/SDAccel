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
struct snd_pcm_substream {struct snd_pcm_runtime* runtime; TYPE_1__* pcm; } ;
struct TYPE_8__ {int channels_max; int rate_max; } ;
struct snd_pcm_runtime {void (* private_free ) (struct snd_pcm_runtime*) ;unsigned long buffer_size; struct ct_atc_pcm* private_data; TYPE_3__ hw; } ;
struct snd_pcm_hw_params {int dummy; } ;
struct snd_pcm_chmap_elem {int dummy; } ;
struct snd_pcm {int /*<<< orphan*/  name; int /*<<< orphan*/  dev_subclass; scalar_t__ info_flags; struct ct_atc* private_data; } ;
struct ct_atc_pcm {void (* interrupt ) (struct ct_atc_pcm*) ;void* timer; struct snd_pcm_substream* substream; scalar_t__ started; } ;
struct ct_atc {int (* spdif_passthru_playback_prepare ) (struct ct_atc*,struct ct_atc_pcm*) ;int (* pcm_playback_prepare ) (struct ct_atc*,struct ct_atc_pcm*) ;unsigned long (* pcm_playback_position ) (struct ct_atc*,struct ct_atc_pcm*) ;int rsr; int msr; int (* pcm_capture_prepare ) (struct ct_atc*,struct ct_atc_pcm*) ;unsigned long (* pcm_capture_position ) (struct ct_atc*,struct ct_atc_pcm*) ;int /*<<< orphan*/  pci; TYPE_2__* card; int /*<<< orphan*/  (* pcm_capture_stop ) (struct ct_atc*,struct ct_atc_pcm*) ;int /*<<< orphan*/  (* pcm_capture_start ) (struct ct_atc*,struct ct_atc_pcm*) ;int /*<<< orphan*/  timer; int /*<<< orphan*/  (* pcm_playback_stop ) (struct ct_atc*,struct ct_atc_pcm*) ;int /*<<< orphan*/  (* pcm_playback_start ) (struct ct_atc*,struct ct_atc_pcm*) ;int /*<<< orphan*/  (* pcm_release_resources ) (struct ct_atc*,struct ct_atc_pcm*) ;int /*<<< orphan*/  (* spdif_out_passthru ) (struct ct_atc*,int) ;} ;
typedef  unsigned long snd_pcm_uframes_t ;
typedef  enum CTALSADEVS { ____Placeholder_CTALSADEVS } CTALSADEVS ;
struct TYPE_7__ {int /*<<< orphan*/  dev; } ;
struct TYPE_6__ {scalar_t__ device; } ;

/* Variables and functions */
#define  CLFE 137 
 int ENOMEM ; 
#define  FRONT 136 
 int /*<<< orphan*/  GFP_KERNEL ; 
 scalar_t__ IEC958 ; 
#define  SIDE 135 
 int /*<<< orphan*/  SNDRV_DMA_TYPE_DEV_SG ; 
 int /*<<< orphan*/  SNDRV_PCM_HW_PARAM_BUFFER_BYTES ; 
 int /*<<< orphan*/  SNDRV_PCM_HW_PARAM_PERIODS ; 
 int /*<<< orphan*/  SNDRV_PCM_STREAM_CAPTURE ; 
 int /*<<< orphan*/  SNDRV_PCM_STREAM_PLAYBACK ; 
 int /*<<< orphan*/  SNDRV_PCM_SUBCLASS_GENERIC_MIX ; 
#define  SNDRV_PCM_TRIGGER_PAUSE_PUSH 134 
#define  SNDRV_PCM_TRIGGER_PAUSE_RELEASE 133 
#define  SNDRV_PCM_TRIGGER_RESUME 132 
#define  SNDRV_PCM_TRIGGER_START 131 
#define  SNDRV_PCM_TRIGGER_STOP 130 
#define  SNDRV_PCM_TRIGGER_SUSPEND 129 
#define  SURROUND 128 
 int /*<<< orphan*/  UINT_MAX ; 
 unsigned long bytes_to_frames (struct snd_pcm_runtime*,unsigned long) ; 
 struct snd_pcm_chmap_elem* clfe_map ; 
 TYPE_3__ ct_pcm_capture_hw ; 
 int /*<<< orphan*/  ct_pcm_capture_ops ; 
 TYPE_3__ ct_pcm_playback_hw ; 
 int /*<<< orphan*/  ct_pcm_playback_ops ; 
 TYPE_3__ ct_spdif_passthru_playback_hw ; 
 int /*<<< orphan*/  ct_timer_instance_free (void*) ; 
 void* ct_timer_instance_new (int /*<<< orphan*/ ,struct ct_atc_pcm*) ; 
 int /*<<< orphan*/  dev_err (int /*<<< orphan*/ ,char*,...) ; 
 int /*<<< orphan*/  kfree (struct ct_atc_pcm*) ; 
 struct ct_atc_pcm* kzalloc (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  params_buffer_bytes (struct snd_pcm_hw_params*) ; 
 struct snd_pcm_chmap_elem* side_map ; 
 int /*<<< orphan*/  snd_dma_pci_data (int /*<<< orphan*/ ) ; 
 int snd_pcm_add_chmap_ctls (struct snd_pcm*,int /*<<< orphan*/ ,struct snd_pcm_chmap_elem const*,int,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int snd_pcm_hw_constraint_integer (struct snd_pcm_runtime*,int /*<<< orphan*/ ) ; 
 int snd_pcm_hw_constraint_minmax (struct snd_pcm_runtime*,int /*<<< orphan*/ ,int,int /*<<< orphan*/ ) ; 
 int snd_pcm_lib_free_pages (struct snd_pcm_substream*) ; 
 int snd_pcm_lib_malloc_pages (struct snd_pcm_substream*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  snd_pcm_lib_preallocate_pages_for_all (struct snd_pcm*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int,int) ; 
 int snd_pcm_new (TYPE_2__*,char*,int,int,int,struct snd_pcm**) ; 
 int /*<<< orphan*/  snd_pcm_period_elapsed (struct snd_pcm_substream*) ; 
 int /*<<< orphan*/  snd_pcm_set_ops (struct snd_pcm*,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 struct snd_pcm_chmap_elem* snd_pcm_std_chmaps ; 
 struct ct_atc* snd_pcm_substream_chip (struct snd_pcm_substream*) ; 
 int /*<<< orphan*/  strlcpy (int /*<<< orphan*/ ,char const*,int) ; 
 int /*<<< orphan*/  stub1 (struct ct_atc*,struct ct_atc_pcm*) ; 
 unsigned long stub10 (struct ct_atc*,struct ct_atc_pcm*) ; 
 int stub11 (struct ct_atc*,struct ct_atc_pcm*) ; 
 int /*<<< orphan*/  stub12 (struct ct_atc*,struct ct_atc_pcm*) ; 
 int /*<<< orphan*/  stub13 (struct ct_atc*,struct ct_atc_pcm*) ; 
 int /*<<< orphan*/  stub14 (struct ct_atc*,struct ct_atc_pcm*) ; 
 unsigned long stub15 (struct ct_atc*,struct ct_atc_pcm*) ; 
 int /*<<< orphan*/  stub2 (struct ct_atc*,int) ; 
 int /*<<< orphan*/  stub3 (struct ct_atc*,int) ; 
 int /*<<< orphan*/  stub4 (struct ct_atc*,struct ct_atc_pcm*) ; 
 int /*<<< orphan*/  stub5 (struct ct_atc*,struct ct_atc_pcm*) ; 
 int stub6 (struct ct_atc*,struct ct_atc_pcm*) ; 
 int stub7 (struct ct_atc*,struct ct_atc_pcm*) ; 
 int /*<<< orphan*/  stub8 (struct ct_atc*,struct ct_atc_pcm*) ; 
 int /*<<< orphan*/  stub9 (struct ct_atc*,struct ct_atc_pcm*) ; 
 struct snd_pcm_chmap_elem* surround_map ; 

__attribute__((used)) static void ct_atc_pcm_interrupt(struct ct_atc_pcm *atc_pcm)
{
	struct ct_atc_pcm *apcm = atc_pcm;

	if (!apcm->substream)
		return;

	snd_pcm_period_elapsed(apcm->substream);
}

__attribute__((used)) static void ct_atc_pcm_free_substream(struct snd_pcm_runtime *runtime)
{
	struct ct_atc_pcm *apcm = runtime->private_data;
	struct ct_atc *atc = snd_pcm_substream_chip(apcm->substream);

	atc->pcm_release_resources(atc, apcm);
	ct_timer_instance_free(apcm->timer);
	kfree(apcm);
	runtime->private_data = NULL;
}

__attribute__((used)) static int ct_pcm_playback_open(struct snd_pcm_substream *substream)
{
	struct ct_atc *atc = snd_pcm_substream_chip(substream);
	struct snd_pcm_runtime *runtime = substream->runtime;
	struct ct_atc_pcm *apcm;
	int err;

	apcm = kzalloc(sizeof(*apcm), GFP_KERNEL);
	if (!apcm)
		return -ENOMEM;

	apcm->substream = substream;
	apcm->interrupt = ct_atc_pcm_interrupt;
	if (IEC958 == substream->pcm->device) {
		runtime->hw = ct_spdif_passthru_playback_hw;
		atc->spdif_out_passthru(atc, 1);
	} else {
		runtime->hw = ct_pcm_playback_hw;
		if (FRONT == substream->pcm->device)
			runtime->hw.channels_max = 8;
	}

	err = snd_pcm_hw_constraint_integer(runtime,
					    SNDRV_PCM_HW_PARAM_PERIODS);
	if (err < 0)
		goto free_pcm;

	err = snd_pcm_hw_constraint_minmax(runtime,
					   SNDRV_PCM_HW_PARAM_BUFFER_BYTES,
					   1024, UINT_MAX);
	if (err < 0)
		goto free_pcm;

	apcm->timer = ct_timer_instance_new(atc->timer, apcm);
	if (!apcm->timer) {
		err = -ENOMEM;
		goto free_pcm;
	}
	runtime->private_data = apcm;
	runtime->private_free = ct_atc_pcm_free_substream;

	return 0;

free_pcm:
	kfree(apcm);
	return err;
}

__attribute__((used)) static int ct_pcm_playback_close(struct snd_pcm_substream *substream)
{
	struct ct_atc *atc = snd_pcm_substream_chip(substream);

	/* TODO: Notify mixer inactive. */
	if (IEC958 == substream->pcm->device)
		atc->spdif_out_passthru(atc, 0);

	/* The ct_atc_pcm object will be freed by runtime->private_free */

	return 0;
}

__attribute__((used)) static int ct_pcm_hw_params(struct snd_pcm_substream *substream,
				     struct snd_pcm_hw_params *hw_params)
{
	struct ct_atc *atc = snd_pcm_substream_chip(substream);
	struct ct_atc_pcm *apcm = substream->runtime->private_data;
	int err;

	err = snd_pcm_lib_malloc_pages(substream,
					params_buffer_bytes(hw_params));
	if (err < 0)
		return err;
	/* clear previous resources */
	atc->pcm_release_resources(atc, apcm);
	return err;
}

__attribute__((used)) static int ct_pcm_hw_free(struct snd_pcm_substream *substream)
{
	struct ct_atc *atc = snd_pcm_substream_chip(substream);
	struct ct_atc_pcm *apcm = substream->runtime->private_data;

	/* clear previous resources */
	atc->pcm_release_resources(atc, apcm);
	/* Free snd-allocated pages */
	return snd_pcm_lib_free_pages(substream);
}

__attribute__((used)) static int ct_pcm_playback_prepare(struct snd_pcm_substream *substream)
{
	int err;
	struct ct_atc *atc = snd_pcm_substream_chip(substream);
	struct snd_pcm_runtime *runtime = substream->runtime;
	struct ct_atc_pcm *apcm = runtime->private_data;

	if (IEC958 == substream->pcm->device)
		err = atc->spdif_passthru_playback_prepare(atc, apcm);
	else
		err = atc->pcm_playback_prepare(atc, apcm);

	if (err < 0) {
		dev_err(atc->card->dev,
			"Preparing pcm playback failed!!!\n");
		return err;
	}

	return 0;
}

__attribute__((used)) static int
ct_pcm_playback_trigger(struct snd_pcm_substream *substream, int cmd)
{
	struct ct_atc *atc = snd_pcm_substream_chip(substream);
	struct snd_pcm_runtime *runtime = substream->runtime;
	struct ct_atc_pcm *apcm = runtime->private_data;

	switch (cmd) {
	case SNDRV_PCM_TRIGGER_START:
	case SNDRV_PCM_TRIGGER_RESUME:
	case SNDRV_PCM_TRIGGER_PAUSE_RELEASE:
		atc->pcm_playback_start(atc, apcm);
		break;
	case SNDRV_PCM_TRIGGER_STOP:
	case SNDRV_PCM_TRIGGER_SUSPEND:
	case SNDRV_PCM_TRIGGER_PAUSE_PUSH:
		atc->pcm_playback_stop(atc, apcm);
		break;
	default:
		break;
	}

	return 0;
}

__attribute__((used)) static snd_pcm_uframes_t
ct_pcm_playback_pointer(struct snd_pcm_substream *substream)
{
	unsigned long position;
	struct ct_atc *atc = snd_pcm_substream_chip(substream);
	struct snd_pcm_runtime *runtime = substream->runtime;
	struct ct_atc_pcm *apcm = runtime->private_data;

	/* Read out playback position */
	position = atc->pcm_playback_position(atc, apcm);
	position = bytes_to_frames(runtime, position);
	if (position >= runtime->buffer_size)
		position = 0;
	return position;
}

__attribute__((used)) static int ct_pcm_capture_open(struct snd_pcm_substream *substream)
{
	struct ct_atc *atc = snd_pcm_substream_chip(substream);
	struct snd_pcm_runtime *runtime = substream->runtime;
	struct ct_atc_pcm *apcm;
	int err;

	apcm = kzalloc(sizeof(*apcm), GFP_KERNEL);
	if (!apcm)
		return -ENOMEM;

	apcm->started = 0;
	apcm->substream = substream;
	apcm->interrupt = ct_atc_pcm_interrupt;
	runtime->hw = ct_pcm_capture_hw;
	runtime->hw.rate_max = atc->rsr * atc->msr;

	err = snd_pcm_hw_constraint_integer(runtime,
					    SNDRV_PCM_HW_PARAM_PERIODS);
	if (err < 0)
		goto free_pcm;

	err = snd_pcm_hw_constraint_minmax(runtime,
					   SNDRV_PCM_HW_PARAM_BUFFER_BYTES,
					   1024, UINT_MAX);
	if (err < 0)
		goto free_pcm;

	apcm->timer = ct_timer_instance_new(atc->timer, apcm);
	if (!apcm->timer) {
		err = -ENOMEM;
		goto free_pcm;
	}
	runtime->private_data = apcm;
	runtime->private_free = ct_atc_pcm_free_substream;

	return 0;

free_pcm:
	kfree(apcm);
	return err;
}

__attribute__((used)) static int ct_pcm_capture_close(struct snd_pcm_substream *substream)
{
	/* The ct_atc_pcm object will be freed by runtime->private_free */
	/* TODO: Notify mixer inactive. */
	return 0;
}

__attribute__((used)) static int ct_pcm_capture_prepare(struct snd_pcm_substream *substream)
{
	int err;
	struct ct_atc *atc = snd_pcm_substream_chip(substream);
	struct snd_pcm_runtime *runtime = substream->runtime;
	struct ct_atc_pcm *apcm = runtime->private_data;

	err = atc->pcm_capture_prepare(atc, apcm);
	if (err < 0) {
		dev_err(atc->card->dev,
			"Preparing pcm capture failed!!!\n");
		return err;
	}

	return 0;
}

__attribute__((used)) static int
ct_pcm_capture_trigger(struct snd_pcm_substream *substream, int cmd)
{
	struct ct_atc *atc = snd_pcm_substream_chip(substream);
	struct snd_pcm_runtime *runtime = substream->runtime;
	struct ct_atc_pcm *apcm = runtime->private_data;

	switch (cmd) {
	case SNDRV_PCM_TRIGGER_START:
		atc->pcm_capture_start(atc, apcm);
		break;
	case SNDRV_PCM_TRIGGER_STOP:
		atc->pcm_capture_stop(atc, apcm);
		break;
	default:
		atc->pcm_capture_stop(atc, apcm);
		break;
	}

	return 0;
}

__attribute__((used)) static snd_pcm_uframes_t
ct_pcm_capture_pointer(struct snd_pcm_substream *substream)
{
	unsigned long position;
	struct ct_atc *atc = snd_pcm_substream_chip(substream);
	struct snd_pcm_runtime *runtime = substream->runtime;
	struct ct_atc_pcm *apcm = runtime->private_data;

	/* Read out playback position */
	position = atc->pcm_capture_position(atc, apcm);
	position = bytes_to_frames(runtime, position);
	if (position >= runtime->buffer_size)
		position = 0;
	return position;
}

int ct_alsa_pcm_create(struct ct_atc *atc,
		       enum CTALSADEVS device,
		       const char *device_name)
{
	struct snd_pcm *pcm;
	const struct snd_pcm_chmap_elem *map;
	int chs;
	int err;
	int playback_count, capture_count;

	playback_count = (IEC958 == device) ? 1 : 256;
	capture_count = (FRONT == device) ? 1 : 0;
	err = snd_pcm_new(atc->card, "ctxfi", device,
			  playback_count, capture_count, &pcm);
	if (err < 0) {
		dev_err(atc->card->dev, "snd_pcm_new failed!! Err=%d\n",
			err);
		return err;
	}

	pcm->private_data = atc;
	pcm->info_flags = 0;
	pcm->dev_subclass = SNDRV_PCM_SUBCLASS_GENERIC_MIX;
	strlcpy(pcm->name, device_name, sizeof(pcm->name));

	snd_pcm_set_ops(pcm, SNDRV_PCM_STREAM_PLAYBACK, &ct_pcm_playback_ops);

	if (FRONT == device)
		snd_pcm_set_ops(pcm,
				SNDRV_PCM_STREAM_CAPTURE, &ct_pcm_capture_ops);

	snd_pcm_lib_preallocate_pages_for_all(pcm, SNDRV_DMA_TYPE_DEV_SG,
			snd_dma_pci_data(atc->pci), 128*1024, 128*1024);

	chs = 2;
	switch (device) {
	case FRONT:
		chs = 8;
		map = snd_pcm_std_chmaps;
		break;
	case SURROUND:
		map = surround_map;
		break;
	case CLFE:
		map = clfe_map;
		break;
	case SIDE:
		map = side_map;
		break;
	default:
		map = snd_pcm_std_chmaps;
		break;
	}
	err = snd_pcm_add_chmap_ctls(pcm, SNDRV_PCM_STREAM_PLAYBACK, map, chs,
				     0, NULL);
	if (err < 0)
		return err;

#ifdef CONFIG_PM_SLEEP
	atc->pcms[device] = pcm;
#endif

	return 0;
}

