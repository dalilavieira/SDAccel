#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_2__ ;
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
struct snd_soc_dai {TYPE_1__* capture_dma_data; TYPE_2__* playback_dma_data; } ;
struct snd_pcm_substream {int /*<<< orphan*/  stream; } ;
struct snd_ac97 {int dummy; } ;
struct resource {int dummy; } ;
struct platform_device {int /*<<< orphan*/  dev; int /*<<< orphan*/  name; } ;
struct TYPE_3__ {int /*<<< orphan*/ * filter_data; } ;
struct TYPE_4__ {int /*<<< orphan*/ * filter_data; } ;
struct ep93xx_ac97_info {unsigned int regs; int /*<<< orphan*/ * dev; int /*<<< orphan*/  done; int /*<<< orphan*/  lock; TYPE_1__ dma_params_rx; TYPE_2__ dma_params_tx; } ;
typedef  int /*<<< orphan*/  irqreturn_t ;

/* Variables and functions */
 unsigned int AC97EOI ; 
 unsigned int AC97EOI_CODECREADY ; 
 unsigned int AC97EOI_WINT ; 
 unsigned int AC97GCR ; 
 unsigned int AC97GCR_AC97IFE ; 
 unsigned int AC97GIS ; 
 unsigned int AC97IM ; 
 unsigned int AC97RESET ; 
 unsigned int AC97RESET_TIMEDRESET ; 
 unsigned int AC97RXCR (int) ; 
 unsigned int AC97RXCR_CM ; 
 unsigned int AC97RXCR_REN ; 
 unsigned int AC97RXCR_RX3 ; 
 unsigned int AC97RXCR_RX4 ; 
 unsigned int AC97S1DATA ; 
 unsigned int AC97S2DATA ; 
 unsigned int AC97SR (int) ; 
 unsigned int AC97SR_TXFE ; 
 unsigned int AC97SR_TXUE ; 
 unsigned int AC97SYNC ; 
 unsigned int AC97SYNC_TIMEDSYNC ; 
 unsigned int AC97TXCR (int) ; 
 unsigned int AC97TXCR_CM ; 
 unsigned int AC97TXCR_TEN ; 
 unsigned int AC97TXCR_TX3 ; 
 unsigned int AC97TXCR_TX4 ; 
 unsigned int AC97_CODECREADY ; 
 unsigned int AC97_SLOT2RXVALID ; 
 unsigned int AC97_SLOT2TXCOMPLETE ; 
 unsigned long AC97_TIMEOUT ; 
 int EINVAL ; 
 int ENODEV ; 
 int ENOMEM ; 
 unsigned short ETIMEDOUT ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int /*<<< orphan*/  IORESOURCE_MEM ; 
 int /*<<< orphan*/  IRQF_TRIGGER_HIGH ; 
 int /*<<< orphan*/  IRQ_HANDLED ; 
 scalar_t__ IS_ERR (unsigned int) ; 
 int PTR_ERR (unsigned int) ; 
 int /*<<< orphan*/  SNDRV_PCM_STREAM_PLAYBACK ; 
#define  SNDRV_PCM_TRIGGER_PAUSE_PUSH 133 
#define  SNDRV_PCM_TRIGGER_PAUSE_RELEASE 132 
#define  SNDRV_PCM_TRIGGER_RESUME 131 
#define  SNDRV_PCM_TRIGGER_START 130 
#define  SNDRV_PCM_TRIGGER_STOP 129 
#define  SNDRV_PCM_TRIGGER_SUSPEND 128 
 int __raw_readl (unsigned int) ; 
 int /*<<< orphan*/  __raw_writel (unsigned int,unsigned int) ; 
 int /*<<< orphan*/  complete (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  dev_set_drvdata (int /*<<< orphan*/ *,struct ep93xx_ac97_info*) ; 
 int /*<<< orphan*/  dev_warn (int /*<<< orphan*/ *,char*,...) ; 
 int devm_ep93xx_pcm_platform_register (int /*<<< orphan*/ *) ; 
 unsigned int devm_ioremap_resource (int /*<<< orphan*/ *,struct resource*) ; 
 struct ep93xx_ac97_info* devm_kzalloc (int /*<<< orphan*/ *,int,int /*<<< orphan*/ ) ; 
 int devm_request_irq (int /*<<< orphan*/ *,int,int /*<<< orphan*/  (*) (int,void*),int /*<<< orphan*/ ,int /*<<< orphan*/ ,struct ep93xx_ac97_info*) ; 
 int /*<<< orphan*/  ep93xx_ac97_component ; 
 int /*<<< orphan*/  ep93xx_ac97_dai ; 
 struct ep93xx_ac97_info* ep93xx_ac97_info ; 
 int /*<<< orphan*/  ep93xx_ac97_ops ; 
 int /*<<< orphan*/  ep93xx_ac97_pcm_in ; 
 int /*<<< orphan*/  ep93xx_ac97_pcm_out ; 
 int /*<<< orphan*/  init_completion (int /*<<< orphan*/ *) ; 
 unsigned long jiffies ; 
 int /*<<< orphan*/  mutex_init (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 struct ep93xx_ac97_info* platform_get_drvdata (struct platform_device*) ; 
 int platform_get_irq (struct platform_device*,int /*<<< orphan*/ ) ; 
 struct resource* platform_get_resource (struct platform_device*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  platform_set_drvdata (struct platform_device*,struct ep93xx_ac97_info*) ; 
 struct ep93xx_ac97_info* snd_soc_dai_get_drvdata (struct snd_soc_dai*) ; 
 int snd_soc_register_component (int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int) ; 
 int snd_soc_set_ac97_ops (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  snd_soc_unregister_component (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  time_after (unsigned long,unsigned long) ; 
 int /*<<< orphan*/  usleep_range (int,int) ; 
 int /*<<< orphan*/  wait_for_completion_timeout (int /*<<< orphan*/ *,unsigned long) ; 

__attribute__((used)) static inline unsigned ep93xx_ac97_read_reg(struct ep93xx_ac97_info *info,
					    unsigned reg)
{
	return __raw_readl(info->regs + reg);
}

__attribute__((used)) static inline void ep93xx_ac97_write_reg(struct ep93xx_ac97_info *info,
					 unsigned reg, unsigned val)
{
	__raw_writel(val, info->regs + reg);
}

__attribute__((used)) static unsigned short ep93xx_ac97_read(struct snd_ac97 *ac97,
				       unsigned short reg)
{
	struct ep93xx_ac97_info *info = ep93xx_ac97_info;
	unsigned short val;

	mutex_lock(&info->lock);

	ep93xx_ac97_write_reg(info, AC97S1DATA, reg);
	ep93xx_ac97_write_reg(info, AC97IM, AC97_SLOT2RXVALID);
	if (!wait_for_completion_timeout(&info->done, AC97_TIMEOUT)) {
		dev_warn(info->dev, "timeout reading register %x\n", reg);
		mutex_unlock(&info->lock);
		return -ETIMEDOUT;
	}
	val = (unsigned short)ep93xx_ac97_read_reg(info, AC97S2DATA);

	mutex_unlock(&info->lock);
	return val;
}

__attribute__((used)) static void ep93xx_ac97_write(struct snd_ac97 *ac97,
			      unsigned short reg,
			      unsigned short val)
{
	struct ep93xx_ac97_info *info = ep93xx_ac97_info;

	mutex_lock(&info->lock);

	/*
	 * Writes to the codec need to be done so that slot 2 is filled in
	 * before slot 1.
	 */
	ep93xx_ac97_write_reg(info, AC97S2DATA, val);
	ep93xx_ac97_write_reg(info, AC97S1DATA, reg);

	ep93xx_ac97_write_reg(info, AC97IM, AC97_SLOT2TXCOMPLETE);
	if (!wait_for_completion_timeout(&info->done, AC97_TIMEOUT))
		dev_warn(info->dev, "timeout writing register %x\n", reg);

	mutex_unlock(&info->lock);
}

__attribute__((used)) static void ep93xx_ac97_warm_reset(struct snd_ac97 *ac97)
{
	struct ep93xx_ac97_info *info = ep93xx_ac97_info;

	mutex_lock(&info->lock);

	/*
	 * We are assuming that before this functions gets called, the codec
	 * BIT_CLK is stopped by forcing the codec into powerdown mode. We can
	 * control the SYNC signal directly via AC97SYNC register. Using
	 * TIMEDSYNC the controller will keep the SYNC high > 1us.
	 */
	ep93xx_ac97_write_reg(info, AC97SYNC, AC97SYNC_TIMEDSYNC);
	ep93xx_ac97_write_reg(info, AC97IM, AC97_CODECREADY);
	if (!wait_for_completion_timeout(&info->done, AC97_TIMEOUT))
		dev_warn(info->dev, "codec warm reset timeout\n");

	mutex_unlock(&info->lock);
}

__attribute__((used)) static void ep93xx_ac97_cold_reset(struct snd_ac97 *ac97)
{
	struct ep93xx_ac97_info *info = ep93xx_ac97_info;

	mutex_lock(&info->lock);

	/*
	 * For doing cold reset, we disable the AC97 controller interface, clear
	 * WINT and CODECREADY bits, and finally enable the interface again.
	 */
	ep93xx_ac97_write_reg(info, AC97GCR, 0);
	ep93xx_ac97_write_reg(info, AC97EOI, AC97EOI_CODECREADY | AC97EOI_WINT);
	ep93xx_ac97_write_reg(info, AC97GCR, AC97GCR_AC97IFE);

	/*
	 * Now, assert the reset and wait for the codec to become ready.
	 */
	ep93xx_ac97_write_reg(info, AC97RESET, AC97RESET_TIMEDRESET);
	ep93xx_ac97_write_reg(info, AC97IM, AC97_CODECREADY);
	if (!wait_for_completion_timeout(&info->done, AC97_TIMEOUT))
		dev_warn(info->dev, "codec cold reset timeout\n");

	/*
	 * Give the codec some time to come fully out from the reset. This way
	 * we ensure that the subsequent reads/writes will work.
	 */
	usleep_range(15000, 20000);

	mutex_unlock(&info->lock);
}

__attribute__((used)) static irqreturn_t ep93xx_ac97_interrupt(int irq, void *dev_id)
{
	struct ep93xx_ac97_info *info = dev_id;
	unsigned status, mask;

	/*
	 * Just mask out the interrupt and wake up the waiting thread.
	 * Interrupts are cleared via reading/writing to slot 1 & 2 registers by
	 * the waiting thread.
	 */
	status = ep93xx_ac97_read_reg(info, AC97GIS);
	mask = ep93xx_ac97_read_reg(info, AC97IM);
	mask &= ~status;
	ep93xx_ac97_write_reg(info, AC97IM, mask);

	complete(&info->done);
	return IRQ_HANDLED;
}

__attribute__((used)) static int ep93xx_ac97_trigger(struct snd_pcm_substream *substream,
			       int cmd, struct snd_soc_dai *dai)
{
	struct ep93xx_ac97_info *info = snd_soc_dai_get_drvdata(dai);
	unsigned v = 0;

	switch (cmd) {
	case SNDRV_PCM_TRIGGER_START:
	case SNDRV_PCM_TRIGGER_RESUME:
	case SNDRV_PCM_TRIGGER_PAUSE_RELEASE:
		if (substream->stream == SNDRV_PCM_STREAM_PLAYBACK) {
			/*
			 * Enable compact mode, TX slots 3 & 4, and the TX FIFO
			 * itself.
			 */
			v |= AC97TXCR_CM;
			v |= AC97TXCR_TX3 | AC97TXCR_TX4;
			v |= AC97TXCR_TEN;
			ep93xx_ac97_write_reg(info, AC97TXCR(1), v);
		} else {
			/*
			 * Enable compact mode, RX slots 3 & 4, and the RX FIFO
			 * itself.
			 */
			v |= AC97RXCR_CM;
			v |= AC97RXCR_RX3 | AC97RXCR_RX4;
			v |= AC97RXCR_REN;
			ep93xx_ac97_write_reg(info, AC97RXCR(1), v);
		}
		break;

	case SNDRV_PCM_TRIGGER_STOP:
	case SNDRV_PCM_TRIGGER_SUSPEND:
	case SNDRV_PCM_TRIGGER_PAUSE_PUSH:
		if (substream->stream == SNDRV_PCM_STREAM_PLAYBACK) {
			/*
			 * As per Cirrus EP93xx errata described below:
			 *
			 * http://www.cirrus.com/en/pubs/errata/ER667E2B.pdf
			 *
			 * we will wait for the TX FIFO to be empty before
			 * clearing the TEN bit.
			 */
			unsigned long timeout = jiffies + AC97_TIMEOUT;

			do {
				v = ep93xx_ac97_read_reg(info, AC97SR(1));
				if (time_after(jiffies, timeout)) {
					dev_warn(info->dev, "TX timeout\n");
					break;
				}
			} while (!(v & (AC97SR_TXFE | AC97SR_TXUE)));

			/* disable the TX FIFO */
			ep93xx_ac97_write_reg(info, AC97TXCR(1), 0);
		} else {
			/* disable the RX FIFO */
			ep93xx_ac97_write_reg(info, AC97RXCR(1), 0);
		}
		break;

	default:
		dev_warn(info->dev, "unknown command %d\n", cmd);
		return -EINVAL;
	}

	return 0;
}

__attribute__((used)) static int ep93xx_ac97_dai_probe(struct snd_soc_dai *dai)
{
	struct ep93xx_ac97_info *info = snd_soc_dai_get_drvdata(dai);

	info->dma_params_tx.filter_data = &ep93xx_ac97_pcm_out;
	info->dma_params_rx.filter_data = &ep93xx_ac97_pcm_in;

	dai->playback_dma_data = &info->dma_params_tx;
	dai->capture_dma_data = &info->dma_params_rx;

	return 0;
}

__attribute__((used)) static int ep93xx_ac97_probe(struct platform_device *pdev)
{
	struct ep93xx_ac97_info *info;
	struct resource *res;
	int irq;
	int ret;

	info = devm_kzalloc(&pdev->dev, sizeof(*info), GFP_KERNEL);
	if (!info)
		return -ENOMEM;

	res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
	info->regs = devm_ioremap_resource(&pdev->dev, res);
	if (IS_ERR(info->regs))
		return PTR_ERR(info->regs);

	irq = platform_get_irq(pdev, 0);
	if (irq <= 0)
		return irq < 0 ? irq : -ENODEV;

	ret = devm_request_irq(&pdev->dev, irq, ep93xx_ac97_interrupt,
			       IRQF_TRIGGER_HIGH, pdev->name, info);
	if (ret)
		goto fail;

	dev_set_drvdata(&pdev->dev, info);

	mutex_init(&info->lock);
	init_completion(&info->done);
	info->dev = &pdev->dev;

	ep93xx_ac97_info = info;
	platform_set_drvdata(pdev, info);

	ret = snd_soc_set_ac97_ops(&ep93xx_ac97_ops);
	if (ret)
		goto fail;

	ret = snd_soc_register_component(&pdev->dev, &ep93xx_ac97_component,
					 &ep93xx_ac97_dai, 1);
	if (ret)
		goto fail;

	ret = devm_ep93xx_pcm_platform_register(&pdev->dev);
	if (ret)
		goto fail_unregister;

	return 0;

fail_unregister:
	snd_soc_unregister_component(&pdev->dev);
fail:
	ep93xx_ac97_info = NULL;
	snd_soc_set_ac97_ops(NULL);
	return ret;
}

__attribute__((used)) static int ep93xx_ac97_remove(struct platform_device *pdev)
{
	struct ep93xx_ac97_info	*info = platform_get_drvdata(pdev);

	snd_soc_unregister_component(&pdev->dev);

	/* disable the AC97 controller */
	ep93xx_ac97_write_reg(info, AC97GCR, 0);

	ep93xx_ac97_info = NULL;

	snd_soc_set_ac97_ops(NULL);

	return 0;
}

