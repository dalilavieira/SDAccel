#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */

/* Type definitions */
struct snd_soc_dai {int dummy; } ;
struct snd_pcm_substream {int /*<<< orphan*/  stream; } ;
struct snd_ac97 {int dummy; } ;
struct platform_device {int /*<<< orphan*/  dev; } ;
struct nuc900_audio {int irq_num; int /*<<< orphan*/  dev; scalar_t__ clk; scalar_t__ mmio; int /*<<< orphan*/  res; int /*<<< orphan*/  lock; } ;

/* Variables and functions */
 unsigned long ACLINK_EN ; 
 scalar_t__ ACTL_ACCON ; 
 scalar_t__ ACTL_ACIS0 ; 
 scalar_t__ ACTL_ACIS1 ; 
 scalar_t__ ACTL_ACIS2 ; 
 scalar_t__ ACTL_ACOS0 ; 
 scalar_t__ ACTL_ACOS1 ; 
 scalar_t__ ACTL_ACOS2 ; 
 scalar_t__ ACTL_CON ; 
 scalar_t__ ACTL_PSR ; 
 scalar_t__ ACTL_RESET ; 
 unsigned long ACTL_RESET_BIT ; 
 scalar_t__ ACTL_RSR ; 
 unsigned long AC_C_RES ; 
 unsigned long AC_PLAY ; 
 unsigned long AC_RECORD ; 
 unsigned long AC_RESET ; 
 int AC_R_FINISH ; 
 int AC_W_FINISH ; 
 unsigned long AC_W_RES ; 
 int AUDIO_READ (scalar_t__) ; 
 int /*<<< orphan*/  AUDIO_WRITE (scalar_t__,unsigned long) ; 
 int CODEC_READY ; 
 int EBUSY ; 
 int EINVAL ; 
 int ENOMEM ; 
 int EPERM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 unsigned long IIS_AC_PIN_SEL ; 
 int /*<<< orphan*/  IORESOURCE_MEM ; 
 scalar_t__ IS_ERR (scalar_t__) ; 
 int PTR_ERR (scalar_t__) ; 
 unsigned long P_DMA_END_IRQ ; 
 unsigned long P_DMA_MIDDLE_IRQ ; 
 unsigned long RESET_PRSR ; 
 unsigned long R_DMA_END_IRQ ; 
 unsigned long R_DMA_MIDDLE_IRQ ; 
 unsigned short R_WB ; 
 unsigned long SLOT1_VALID ; 
 unsigned long SLOT2_VALID ; 
 unsigned long SLOT3_VALID ; 
 unsigned long SLOT4_VALID ; 
 int /*<<< orphan*/  SNDRV_PCM_STREAM_PLAYBACK ; 
#define  SNDRV_PCM_TRIGGER_RESUME 131 
#define  SNDRV_PCM_TRIGGER_START 130 
#define  SNDRV_PCM_TRIGGER_STOP 129 
#define  SNDRV_PCM_TRIGGER_SUSPEND 128 
 unsigned long VALID_FRAME ; 
 int /*<<< orphan*/  ac97_mutex ; 
 int /*<<< orphan*/  clk_disable (scalar_t__) ; 
 int /*<<< orphan*/  clk_enable (scalar_t__) ; 
 int /*<<< orphan*/  dev_err (int /*<<< orphan*/ ,char*) ; 
 scalar_t__ devm_clk_get (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 scalar_t__ devm_ioremap_resource (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 struct nuc900_audio* devm_kzalloc (int /*<<< orphan*/ *,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mdelay (int) ; 
 int /*<<< orphan*/  mfp_set_groupg (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  nuc900_ac97_component ; 
 int /*<<< orphan*/  nuc900_ac97_dai ; 
 struct nuc900_audio* nuc900_ac97_data ; 
 int /*<<< orphan*/  nuc900_ac97_ops ; 
 int platform_get_irq (struct platform_device*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  platform_get_resource (struct platform_device*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int snd_soc_register_component (int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int) ; 
 int snd_soc_set_ac97_ops (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  snd_soc_unregister_component (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  spin_lock_init (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  udelay (int) ; 

__attribute__((used)) static int nuc900_checkready(void)
{
	struct nuc900_audio *nuc900_audio = nuc900_ac97_data;

	if (!(AUDIO_READ(nuc900_audio->mmio + ACTL_ACIS0) & CODEC_READY))
		return -EPERM;

	return 0;
}

__attribute__((used)) static unsigned short nuc900_ac97_read(struct snd_ac97 *ac97,
					unsigned short reg)
{
	struct nuc900_audio *nuc900_audio = nuc900_ac97_data;
	unsigned long timeout = 0x10000, val;

	mutex_lock(&ac97_mutex);

	val = nuc900_checkready();
	if (val) {
		dev_err(nuc900_audio->dev, "AC97 codec is not ready\n");
		goto out;
	}

	/* set the R_WB bit and write register index */
	AUDIO_WRITE(nuc900_audio->mmio + ACTL_ACOS1, R_WB | reg);

	/* set the valid frame bit and valid slots */
	val = AUDIO_READ(nuc900_audio->mmio + ACTL_ACOS0);
	val |= (VALID_FRAME | SLOT1_VALID);
	AUDIO_WRITE(nuc900_audio->mmio + ACTL_ACOS0, val);

	udelay(100);

	/* polling the AC_R_FINISH */
	while (!(AUDIO_READ(nuc900_audio->mmio + ACTL_ACCON) & AC_R_FINISH)
								&& --timeout)
		mdelay(1);

	if (!timeout) {
		dev_err(nuc900_audio->dev, "AC97 read register time out !\n");
		val = -EPERM;
		goto out;
	}

	val = AUDIO_READ(nuc900_audio->mmio + ACTL_ACOS0) ;
	val &= ~SLOT1_VALID;
	AUDIO_WRITE(nuc900_audio->mmio + ACTL_ACOS0, val);

	if (AUDIO_READ(nuc900_audio->mmio + ACTL_ACIS1) >> 2 != reg) {
		dev_err(nuc900_audio->dev,
				"R_INDEX of REG_ACTL_ACIS1 not match!\n");
	}

	udelay(100);
	val = (AUDIO_READ(nuc900_audio->mmio + ACTL_ACIS2) & 0xFFFF);

out:
	mutex_unlock(&ac97_mutex);
	return val;
}

__attribute__((used)) static void nuc900_ac97_write(struct snd_ac97 *ac97, unsigned short reg,
				unsigned short val)
{
	struct nuc900_audio *nuc900_audio = nuc900_ac97_data;
	unsigned long tmp, timeout = 0x10000;

	mutex_lock(&ac97_mutex);

	tmp = nuc900_checkready();
	if (tmp)
		dev_err(nuc900_audio->dev, "AC97 codec is not ready\n");

	/* clear the R_WB bit and write register index */
	AUDIO_WRITE(nuc900_audio->mmio + ACTL_ACOS1, reg);

	/* write register value */
	AUDIO_WRITE(nuc900_audio->mmio + ACTL_ACOS2, val);

	/* set the valid frame bit and valid slots */
	tmp = AUDIO_READ(nuc900_audio->mmio + ACTL_ACOS0);
	tmp |= SLOT1_VALID | SLOT2_VALID | VALID_FRAME;
	AUDIO_WRITE(nuc900_audio->mmio + ACTL_ACOS0, tmp);

	udelay(100);

	/* polling the AC_W_FINISH */
	while ((AUDIO_READ(nuc900_audio->mmio + ACTL_ACCON) & AC_W_FINISH)
								&& --timeout)
		mdelay(1);

	if (!timeout)
		dev_err(nuc900_audio->dev, "AC97 write register time out !\n");

	tmp = AUDIO_READ(nuc900_audio->mmio + ACTL_ACOS0);
	tmp &= ~(SLOT1_VALID | SLOT2_VALID);
	AUDIO_WRITE(nuc900_audio->mmio + ACTL_ACOS0, tmp);

	mutex_unlock(&ac97_mutex);

}

__attribute__((used)) static void nuc900_ac97_warm_reset(struct snd_ac97 *ac97)
{
	struct nuc900_audio *nuc900_audio = nuc900_ac97_data;
	unsigned long val;

	mutex_lock(&ac97_mutex);

	/* warm reset AC 97 */
	val = AUDIO_READ(nuc900_audio->mmio + ACTL_ACCON);
	val |= AC_W_RES;
	AUDIO_WRITE(nuc900_audio->mmio + ACTL_ACCON, val);

	udelay(100);

	val = nuc900_checkready();
	if (val)
		dev_err(nuc900_audio->dev, "AC97 codec is not ready\n");

	mutex_unlock(&ac97_mutex);
}

__attribute__((used)) static void nuc900_ac97_cold_reset(struct snd_ac97 *ac97)
{
	struct nuc900_audio *nuc900_audio = nuc900_ac97_data;
	unsigned long val;

	mutex_lock(&ac97_mutex);

	/* reset Audio Controller */
	val = AUDIO_READ(nuc900_audio->mmio + ACTL_RESET);
	val |= ACTL_RESET_BIT;
	AUDIO_WRITE(nuc900_audio->mmio + ACTL_RESET, val);

	val = AUDIO_READ(nuc900_audio->mmio + ACTL_RESET);
	val &= (~ACTL_RESET_BIT);
	AUDIO_WRITE(nuc900_audio->mmio + ACTL_RESET, val);

	/* reset AC-link interface */

	val = AUDIO_READ(nuc900_audio->mmio + ACTL_RESET);
	val |= AC_RESET;
	AUDIO_WRITE(nuc900_audio->mmio + ACTL_RESET, val);

	val = AUDIO_READ(nuc900_audio->mmio + ACTL_RESET);
	val &= ~AC_RESET;
	AUDIO_WRITE(nuc900_audio->mmio + ACTL_RESET, val);

	/* cold reset AC 97 */
	val = AUDIO_READ(nuc900_audio->mmio + ACTL_ACCON);
	val |= AC_C_RES;
	AUDIO_WRITE(nuc900_audio->mmio + ACTL_ACCON, val);

	val = AUDIO_READ(nuc900_audio->mmio + ACTL_ACCON);
	val &= (~AC_C_RES);
	AUDIO_WRITE(nuc900_audio->mmio + ACTL_ACCON, val);

	udelay(100);

	mutex_unlock(&ac97_mutex);

}

__attribute__((used)) static int nuc900_ac97_trigger(struct snd_pcm_substream *substream,
				int cmd, struct snd_soc_dai *dai)
{
	struct nuc900_audio *nuc900_audio = nuc900_ac97_data;
	int ret;
	unsigned long val, tmp;

	ret = 0;

	switch (cmd) {
	case SNDRV_PCM_TRIGGER_START:
	case SNDRV_PCM_TRIGGER_RESUME:
		val = AUDIO_READ(nuc900_audio->mmio + ACTL_RESET);
		if (substream->stream == SNDRV_PCM_STREAM_PLAYBACK) {
			tmp = AUDIO_READ(nuc900_audio->mmio + ACTL_ACOS0);
			tmp |= (SLOT3_VALID | SLOT4_VALID | VALID_FRAME);
			AUDIO_WRITE(nuc900_audio->mmio + ACTL_ACOS0, tmp);

			tmp = AUDIO_READ(nuc900_audio->mmio + ACTL_PSR);
			tmp |= (P_DMA_END_IRQ | P_DMA_MIDDLE_IRQ);
			AUDIO_WRITE(nuc900_audio->mmio + ACTL_PSR, tmp);
			val |= AC_PLAY;
		} else {
			tmp = AUDIO_READ(nuc900_audio->mmio + ACTL_RSR);
			tmp |= (R_DMA_END_IRQ | R_DMA_MIDDLE_IRQ);

			AUDIO_WRITE(nuc900_audio->mmio + ACTL_RSR, tmp);
			val |= AC_RECORD;
		}

		AUDIO_WRITE(nuc900_audio->mmio + ACTL_RESET, val);

		break;
	case SNDRV_PCM_TRIGGER_STOP:
	case SNDRV_PCM_TRIGGER_SUSPEND:
		val = AUDIO_READ(nuc900_audio->mmio + ACTL_RESET);
		if (substream->stream == SNDRV_PCM_STREAM_PLAYBACK) {
			tmp = AUDIO_READ(nuc900_audio->mmio + ACTL_ACOS0);
			tmp &= ~(SLOT3_VALID | SLOT4_VALID);
			AUDIO_WRITE(nuc900_audio->mmio + ACTL_ACOS0, tmp);

			AUDIO_WRITE(nuc900_audio->mmio + ACTL_PSR, RESET_PRSR);
			val &= ~AC_PLAY;
		} else {
			AUDIO_WRITE(nuc900_audio->mmio + ACTL_RSR, RESET_PRSR);
			val &= ~AC_RECORD;
		}

		AUDIO_WRITE(nuc900_audio->mmio + ACTL_RESET, val);

		break;
	default:
		ret = -EINVAL;
	}

	return ret;
}

__attribute__((used)) static int nuc900_ac97_probe(struct snd_soc_dai *dai)
{
	struct nuc900_audio *nuc900_audio = nuc900_ac97_data;
	unsigned long val;

	mutex_lock(&ac97_mutex);

	/* enable unit clock */
	clk_enable(nuc900_audio->clk);

	/* enable audio controller and AC-link interface */
	val = AUDIO_READ(nuc900_audio->mmio + ACTL_CON);
	val |= (IIS_AC_PIN_SEL | ACLINK_EN);
	AUDIO_WRITE(nuc900_audio->mmio + ACTL_CON, val);

	mutex_unlock(&ac97_mutex);

	return 0;
}

__attribute__((used)) static int nuc900_ac97_remove(struct snd_soc_dai *dai)
{
	struct nuc900_audio *nuc900_audio = nuc900_ac97_data;

	clk_disable(nuc900_audio->clk);
	return 0;
}

__attribute__((used)) static int nuc900_ac97_drvprobe(struct platform_device *pdev)
{
	struct nuc900_audio *nuc900_audio;
	int ret;

	if (nuc900_ac97_data)
		return -EBUSY;

	nuc900_audio = devm_kzalloc(&pdev->dev, sizeof(struct nuc900_audio),
				    GFP_KERNEL);
	if (!nuc900_audio)
		return -ENOMEM;

	spin_lock_init(&nuc900_audio->lock);

	nuc900_audio->res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
	nuc900_audio->mmio = devm_ioremap_resource(&pdev->dev,
						   nuc900_audio->res);
	if (IS_ERR(nuc900_audio->mmio))
		return PTR_ERR(nuc900_audio->mmio);

	nuc900_audio->clk = devm_clk_get(&pdev->dev, NULL);
	if (IS_ERR(nuc900_audio->clk)) {
		ret = PTR_ERR(nuc900_audio->clk);
		goto out;
	}

	ret = platform_get_irq(pdev, 0);
	if (ret < 0)
		goto out;
	nuc900_audio->irq_num = ret;

	nuc900_ac97_data = nuc900_audio;

	ret = snd_soc_set_ac97_ops(&nuc900_ac97_ops);
	if (ret)
		goto out;

	ret = snd_soc_register_component(&pdev->dev, &nuc900_ac97_component,
					 &nuc900_ac97_dai, 1);
	if (ret)
		goto out;

	/* enbale ac97 multifunction pin */
	mfp_set_groupg(nuc900_audio->dev, NULL);

	return 0;

out:
	snd_soc_set_ac97_ops(NULL);
	return ret;
}

__attribute__((used)) static int nuc900_ac97_drvremove(struct platform_device *pdev)
{
	snd_soc_unregister_component(&pdev->dev);

	nuc900_ac97_data = NULL;
	snd_soc_set_ac97_ops(NULL);

	return 0;
}

