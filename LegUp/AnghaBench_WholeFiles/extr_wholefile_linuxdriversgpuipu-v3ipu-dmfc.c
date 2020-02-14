#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
typedef  int u32 ;
struct ipu_soc {unsigned int idmac_reg; struct ipu_dmfc_priv* dmfc_priv; } ;
struct ipu_dmfc_priv {scalar_t__ use_count; unsigned int base; struct dmfc_channel* channels; int /*<<< orphan*/  mutex; struct ipu_soc* ipu; struct device* dev; } ;
struct dmfc_channel {int slots; TYPE_1__* data; struct ipu_soc* ipu; struct ipu_dmfc_priv* priv; } ;
struct device {int dummy; } ;
struct clk {int dummy; } ;
struct TYPE_2__ {int max_fifo_lines; int eot_shift; int ipu_channel; } ;

/* Variables and functions */
 unsigned int DMFC_DP_CHAN ; 
 unsigned int DMFC_DP_CHAN_DEF ; 
 unsigned int DMFC_GENERAL1 ; 
 int DMFC_NUM_CHANNELS ; 
 unsigned int DMFC_WR_CHAN ; 
 unsigned int DMFC_WR_CHAN_DEF ; 
 int /*<<< orphan*/  ENODEV ; 
 int ENOMEM ; 
 struct dmfc_channel* ERR_PTR (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 scalar_t__ IPUV3_CHANNEL_MEM_BG_SYNC ; 
 scalar_t__ IPUV3_CHANNEL_MEM_DC_SYNC ; 
 scalar_t__ IPUV3_CHANNEL_MEM_FG_SYNC ; 
 int /*<<< orphan*/  IPU_CONF_DMFC_EN ; 
 int /*<<< orphan*/  PAGE_SIZE ; 
 unsigned int devm_ioremap (struct device*,unsigned long,int /*<<< orphan*/ ) ; 
 struct ipu_dmfc_priv* devm_kzalloc (struct device*,int,int /*<<< orphan*/ ) ; 
 TYPE_1__* dmfcdata ; 
 int /*<<< orphan*/  ipu_module_disable (struct ipu_soc*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ipu_module_enable (struct ipu_soc*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mutex_init (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 int readl (unsigned int) ; 
 int /*<<< orphan*/  writel (int,unsigned int) ; 

__attribute__((used)) static inline u32 ipu_idmac_read(struct ipu_soc *ipu, unsigned offset)
{
	return readl(ipu->idmac_reg + offset);
}

__attribute__((used)) static inline void ipu_idmac_write(struct ipu_soc *ipu, u32 value,
				   unsigned offset)
{
	writel(value, ipu->idmac_reg + offset);
}

int ipu_dmfc_enable_channel(struct dmfc_channel *dmfc)
{
	struct ipu_dmfc_priv *priv = dmfc->priv;
	mutex_lock(&priv->mutex);

	if (!priv->use_count)
		ipu_module_enable(priv->ipu, IPU_CONF_DMFC_EN);

	priv->use_count++;

	mutex_unlock(&priv->mutex);

	return 0;
}

void ipu_dmfc_disable_channel(struct dmfc_channel *dmfc)
{
	struct ipu_dmfc_priv *priv = dmfc->priv;

	mutex_lock(&priv->mutex);

	priv->use_count--;

	if (!priv->use_count)
		ipu_module_disable(priv->ipu, IPU_CONF_DMFC_EN);

	if (priv->use_count < 0)
		priv->use_count = 0;

	mutex_unlock(&priv->mutex);
}

void ipu_dmfc_config_wait4eot(struct dmfc_channel *dmfc, int width)
{
	struct ipu_dmfc_priv *priv = dmfc->priv;
	u32 dmfc_gen1;

	mutex_lock(&priv->mutex);

	dmfc_gen1 = readl(priv->base + DMFC_GENERAL1);

	if ((dmfc->slots * 64 * 4) / width > dmfc->data->max_fifo_lines)
		dmfc_gen1 |= 1 << dmfc->data->eot_shift;
	else
		dmfc_gen1 &= ~(1 << dmfc->data->eot_shift);

	writel(dmfc_gen1, priv->base + DMFC_GENERAL1);

	mutex_unlock(&priv->mutex);
}

struct dmfc_channel *ipu_dmfc_get(struct ipu_soc *ipu, int ipu_channel)
{
	struct ipu_dmfc_priv *priv = ipu->dmfc_priv;
	int i;

	for (i = 0; i < DMFC_NUM_CHANNELS; i++)
		if (dmfcdata[i].ipu_channel == ipu_channel)
			return &priv->channels[i];
	return ERR_PTR(-ENODEV);
}

void ipu_dmfc_put(struct dmfc_channel *dmfc)
{
}

int ipu_dmfc_init(struct ipu_soc *ipu, struct device *dev, unsigned long base,
		struct clk *ipu_clk)
{
	struct ipu_dmfc_priv *priv;
	int i;

	priv = devm_kzalloc(dev, sizeof(*priv), GFP_KERNEL);
	if (!priv)
		return -ENOMEM;

	priv->base = devm_ioremap(dev, base, PAGE_SIZE);
	if (!priv->base)
		return -ENOMEM;

	priv->dev = dev;
	priv->ipu = ipu;
	mutex_init(&priv->mutex);

	ipu->dmfc_priv = priv;

	for (i = 0; i < DMFC_NUM_CHANNELS; i++) {
		priv->channels[i].priv = priv;
		priv->channels[i].ipu = ipu;
		priv->channels[i].data = &dmfcdata[i];

		if (dmfcdata[i].ipu_channel == IPUV3_CHANNEL_MEM_BG_SYNC ||
		    dmfcdata[i].ipu_channel == IPUV3_CHANNEL_MEM_FG_SYNC ||
		    dmfcdata[i].ipu_channel == IPUV3_CHANNEL_MEM_DC_SYNC)
			priv->channels[i].slots = 2;
	}

	writel(0x00000050, priv->base + DMFC_WR_CHAN);
	writel(0x00005654, priv->base + DMFC_DP_CHAN);
	writel(0x202020f6, priv->base + DMFC_WR_CHAN_DEF);
	writel(0x2020f6f6, priv->base + DMFC_DP_CHAN_DEF);
	writel(0x00000003, priv->base + DMFC_GENERAL1);

	return 0;
}

void ipu_dmfc_exit(struct ipu_soc *ipu)
{
}

