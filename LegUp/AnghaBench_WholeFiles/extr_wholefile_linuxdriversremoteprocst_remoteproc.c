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
typedef  int u32 ;
struct st_rproc_config {scalar_t__ pwr_reset; scalar_t__ sw_reset; int /*<<< orphan*/  bootaddr_mask; } ;
struct TYPE_4__ {int tx_block; int knows_txdone; void (* rx_callback ) (struct mbox_client*,void*) ;int /*<<< orphan*/ * tx_done; struct device* dev; } ;
struct st_rproc {struct mbox_chan** mbox_chan; struct mbox_chan* clk; TYPE_2__ mbox_client_vq1; TYPE_2__ mbox_client_vq0; int /*<<< orphan*/  clk_rate; struct st_rproc_config* config; int /*<<< orphan*/  boot_offset; struct mbox_chan* boot_base; struct mbox_chan* pwr_reset; struct mbox_chan* sw_reset; } ;
struct device {struct device_node* of_node; struct device* parent; } ;
struct rproc {int has_iommu; struct st_rproc* priv; struct device dev; int /*<<< orphan*/  state; int /*<<< orphan*/  power; int /*<<< orphan*/  bootaddr; TYPE_1__* ops; } ;
struct resource_table {int dummy; } ;
struct platform_device {struct device dev; } ;
struct of_device_id {scalar_t__ data; } ;
struct mbox_client {struct device* dev; } ;
struct mbox_chan {int dummy; } ;
struct firmware {int dummy; } ;
struct device_node {int /*<<< orphan*/  name; } ;
struct TYPE_3__ {int (* sanity_check ) (struct rproc*,struct firmware const*) ;int (* get_boot_addr ) (struct rproc*,struct firmware const*) ;int (* load ) (struct rproc*,struct firmware const*) ;int (* parse_fw ) (struct rproc*,struct firmware const*) ;struct resource_table* (* find_loaded_rsc_table ) (struct rproc*,struct firmware const*) ;} ;

/* Variables and functions */
 int EINVAL ; 
 int ENODEV ; 
 int ENOMEM ; 
 scalar_t__ IRQ_NONE ; 
 scalar_t__ IS_ERR (struct mbox_chan*) ; 
 int MBOX_MAX ; 
 int MBOX_RX ; 
 int MBOX_TX ; 
 int PTR_ERR (struct mbox_chan*) ; 
 int /*<<< orphan*/  RPROC_RUNNING ; 
 int ST_RPROC_MAX_VRING ; 
 int ST_RPROC_VQ0 ; 
 int ST_RPROC_VQ1 ; 
 scalar_t__ WARN_ON (int) ; 
 int /*<<< orphan*/  atomic_inc (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  clk_disable (struct mbox_chan*) ; 
 int /*<<< orphan*/  clk_disable_unprepare (struct mbox_chan*) ; 
 int clk_enable (struct mbox_chan*) ; 
 int clk_prepare (struct mbox_chan*) ; 
 int /*<<< orphan*/  clk_set_rate (struct mbox_chan*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  clk_unprepare (struct mbox_chan*) ; 
 int /*<<< orphan*/  dev_dbg (struct device*,char*,int) ; 
 int /*<<< orphan*/  dev_err (struct device*,char*,...) ; 
 struct rproc* dev_get_drvdata (struct device*) ; 
 int /*<<< orphan*/  dev_info (struct device*,char*,int /*<<< orphan*/ ) ; 
 struct mbox_chan* devm_clk_get (struct device*,int /*<<< orphan*/ *) ; 
 void* devm_reset_control_get_exclusive (struct device*,char*) ; 
 int /*<<< orphan*/  mbox_free_channel (struct mbox_chan*) ; 
 struct mbox_chan* mbox_request_channel_byname (TYPE_2__*,char*) ; 
 int mbox_send_message (struct mbox_chan*,void*) ; 
 scalar_t__ of_get_property (struct device_node*,char*,int /*<<< orphan*/ *) ; 
 struct of_device_id* of_match_device (int /*<<< orphan*/ ,struct device*) ; 
 int of_property_read_u32 (struct device_node*,char*,int /*<<< orphan*/ *) ; 
 int of_property_read_u32_index (struct device_node*,char*,int,int /*<<< orphan*/ *) ; 
 int of_reserved_mem_device_init (struct device*) ; 
 int /*<<< orphan*/  of_reserved_mem_device_release (struct device*) ; 
 struct rproc* platform_get_drvdata (struct platform_device*) ; 
 int /*<<< orphan*/  platform_set_drvdata (struct platform_device*,struct rproc*) ; 
 int /*<<< orphan*/  regmap_update_bits (struct mbox_chan*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int reset_control_assert (struct mbox_chan*) ; 
 int reset_control_deassert (struct mbox_chan*) ; 
 int reset_control_status (struct mbox_chan*) ; 
 int rproc_add (struct rproc*) ; 
 struct rproc* rproc_alloc (struct device*,int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  rproc_del (struct rproc*) ; 
 int /*<<< orphan*/  rproc_free (struct rproc*) ; 
 scalar_t__ rproc_vq_interrupt (struct rproc*,int) ; 
 int /*<<< orphan*/  st_rproc_match ; 
 int /*<<< orphan*/  st_rproc_ops ; 
 int stub1 (struct rproc*,struct firmware const*) ; 
 int stub2 (struct rproc*,struct firmware const*) ; 
 int stub3 (struct rproc*,struct firmware const*) ; 
 int stub4 (struct rproc*,struct firmware const*) ; 
 struct resource_table* stub5 (struct rproc*,struct firmware const*) ; 
 struct mbox_chan* syscon_regmap_lookup_by_phandle (struct device_node*,char*) ; 

__attribute__((used)) static inline
int rproc_fw_sanity_check(struct rproc *rproc, const struct firmware *fw)
{
	if (rproc->ops->sanity_check)
		return rproc->ops->sanity_check(rproc, fw);

	return 0;
}

__attribute__((used)) static inline
u32 rproc_get_boot_addr(struct rproc *rproc, const struct firmware *fw)
{
	if (rproc->ops->get_boot_addr)
		return rproc->ops->get_boot_addr(rproc, fw);

	return 0;
}

__attribute__((used)) static inline
int rproc_load_segments(struct rproc *rproc, const struct firmware *fw)
{
	if (rproc->ops->load)
		return rproc->ops->load(rproc, fw);

	return -EINVAL;
}

__attribute__((used)) static inline int rproc_parse_fw(struct rproc *rproc, const struct firmware *fw)
{
	if (rproc->ops->parse_fw)
		return rproc->ops->parse_fw(rproc, fw);

	return 0;
}

__attribute__((used)) static inline
struct resource_table *rproc_find_loaded_rsc_table(struct rproc *rproc,
						   const struct firmware *fw)
{
	if (rproc->ops->find_loaded_rsc_table)
		return rproc->ops->find_loaded_rsc_table(rproc, fw);

	return NULL;
}

__attribute__((used)) static void st_rproc_mbox_callback(struct device *dev, u32 msg)
{
	struct rproc *rproc = dev_get_drvdata(dev);

	if (rproc_vq_interrupt(rproc, msg) == IRQ_NONE)
		dev_dbg(dev, "no message was found in vqid %d\n", msg);
}

__attribute__((used)) static
void st_rproc_mbox_callback_vq0(struct mbox_client *mbox_client, void *data)
{
	st_rproc_mbox_callback(mbox_client->dev, 0);
}

__attribute__((used)) static
void st_rproc_mbox_callback_vq1(struct mbox_client *mbox_client, void *data)
{
	st_rproc_mbox_callback(mbox_client->dev, 1);
}

__attribute__((used)) static void st_rproc_kick(struct rproc *rproc, int vqid)
{
	struct st_rproc *ddata = rproc->priv;
	struct device *dev = rproc->dev.parent;
	int ret;

	/* send the index of the triggered virtqueue in the mailbox payload */
	if (WARN_ON(vqid >= ST_RPROC_MAX_VRING))
		return;

	ret = mbox_send_message(ddata->mbox_chan[vqid * MBOX_MAX + MBOX_TX],
				(void *)&vqid);
	if (ret < 0)
		dev_err(dev, "failed to send message via mbox: %d\n", ret);
}

__attribute__((used)) static int st_rproc_start(struct rproc *rproc)
{
	struct st_rproc *ddata = rproc->priv;
	int err;

	regmap_update_bits(ddata->boot_base, ddata->boot_offset,
			   ddata->config->bootaddr_mask, rproc->bootaddr);

	err = clk_enable(ddata->clk);
	if (err) {
		dev_err(&rproc->dev, "Failed to enable clock\n");
		return err;
	}

	if (ddata->config->sw_reset) {
		err = reset_control_deassert(ddata->sw_reset);
		if (err) {
			dev_err(&rproc->dev, "Failed to deassert S/W Reset\n");
			goto sw_reset_fail;
		}
	}

	if (ddata->config->pwr_reset) {
		err = reset_control_deassert(ddata->pwr_reset);
		if (err) {
			dev_err(&rproc->dev, "Failed to deassert Power Reset\n");
			goto pwr_reset_fail;
		}
	}

	dev_info(&rproc->dev, "Started from 0x%x\n", rproc->bootaddr);

	return 0;


pwr_reset_fail:
	if (ddata->config->pwr_reset)
		reset_control_assert(ddata->sw_reset);
sw_reset_fail:
	clk_disable(ddata->clk);

	return err;
}

__attribute__((used)) static int st_rproc_stop(struct rproc *rproc)
{
	struct st_rproc *ddata = rproc->priv;
	int sw_err = 0, pwr_err = 0;

	if (ddata->config->sw_reset) {
		sw_err = reset_control_assert(ddata->sw_reset);
		if (sw_err)
			dev_err(&rproc->dev, "Failed to assert S/W Reset\n");
	}

	if (ddata->config->pwr_reset) {
		pwr_err = reset_control_assert(ddata->pwr_reset);
		if (pwr_err)
			dev_err(&rproc->dev, "Failed to assert Power Reset\n");
	}

	clk_disable(ddata->clk);

	return sw_err ?: pwr_err;
}

__attribute__((used)) static int st_rproc_state(struct platform_device *pdev)
{
	struct rproc *rproc = platform_get_drvdata(pdev);
	struct st_rproc *ddata = rproc->priv;
	int reset_sw = 0, reset_pwr = 0;

	if (ddata->config->sw_reset)
		reset_sw = reset_control_status(ddata->sw_reset);

	if (ddata->config->pwr_reset)
		reset_pwr = reset_control_status(ddata->pwr_reset);

	if (reset_sw < 0 || reset_pwr < 0)
		return -EINVAL;

	return !reset_sw && !reset_pwr;
}

__attribute__((used)) static int st_rproc_parse_dt(struct platform_device *pdev)
{
	struct device *dev = &pdev->dev;
	struct rproc *rproc = platform_get_drvdata(pdev);
	struct st_rproc *ddata = rproc->priv;
	struct device_node *np = dev->of_node;
	int err;

	if (ddata->config->sw_reset) {
		ddata->sw_reset = devm_reset_control_get_exclusive(dev,
								   "sw_reset");
		if (IS_ERR(ddata->sw_reset)) {
			dev_err(dev, "Failed to get S/W Reset\n");
			return PTR_ERR(ddata->sw_reset);
		}
	}

	if (ddata->config->pwr_reset) {
		ddata->pwr_reset = devm_reset_control_get_exclusive(dev,
								    "pwr_reset");
		if (IS_ERR(ddata->pwr_reset)) {
			dev_err(dev, "Failed to get Power Reset\n");
			return PTR_ERR(ddata->pwr_reset);
		}
	}

	ddata->clk = devm_clk_get(dev, NULL);
	if (IS_ERR(ddata->clk)) {
		dev_err(dev, "Failed to get clock\n");
		return PTR_ERR(ddata->clk);
	}

	err = of_property_read_u32(np, "clock-frequency", &ddata->clk_rate);
	if (err) {
		dev_err(dev, "failed to get clock frequency\n");
		return err;
	}

	ddata->boot_base = syscon_regmap_lookup_by_phandle(np, "st,syscfg");
	if (IS_ERR(ddata->boot_base)) {
		dev_err(dev, "Boot base not found\n");
		return PTR_ERR(ddata->boot_base);
	}

	err = of_property_read_u32_index(np, "st,syscfg", 1,
					 &ddata->boot_offset);
	if (err) {
		dev_err(dev, "Boot offset not found\n");
		return -EINVAL;
	}

	err = of_reserved_mem_device_init(dev);
	if (err) {
		dev_err(dev, "Failed to obtain shared memory\n");
		return err;
	}

	err = clk_prepare(ddata->clk);
	if (err)
		dev_err(dev, "failed to get clock\n");

	return err;
}

__attribute__((used)) static int st_rproc_probe(struct platform_device *pdev)
{
	struct device *dev = &pdev->dev;
	const struct of_device_id *match;
	struct st_rproc *ddata;
	struct device_node *np = dev->of_node;
	struct rproc *rproc;
	struct mbox_chan *chan;
	int enabled;
	int ret, i;

	match = of_match_device(st_rproc_match, dev);
	if (!match || !match->data) {
		dev_err(dev, "No device match found\n");
		return -ENODEV;
	}

	rproc = rproc_alloc(dev, np->name, &st_rproc_ops, NULL, sizeof(*ddata));
	if (!rproc)
		return -ENOMEM;

	rproc->has_iommu = false;
	ddata = rproc->priv;
	ddata->config = (struct st_rproc_config *)match->data;

	platform_set_drvdata(pdev, rproc);

	ret = st_rproc_parse_dt(pdev);
	if (ret)
		goto free_rproc;

	enabled = st_rproc_state(pdev);
	if (enabled < 0) {
		ret = enabled;
		goto free_clk;
	}

	if (enabled) {
		atomic_inc(&rproc->power);
		rproc->state = RPROC_RUNNING;
	} else {
		clk_set_rate(ddata->clk, ddata->clk_rate);
	}

	if (of_get_property(np, "mbox-names", NULL)) {
		ddata->mbox_client_vq0.dev		= dev;
		ddata->mbox_client_vq0.tx_done		= NULL;
		ddata->mbox_client_vq0.tx_block	= false;
		ddata->mbox_client_vq0.knows_txdone	= false;
		ddata->mbox_client_vq0.rx_callback	= st_rproc_mbox_callback_vq0;

		ddata->mbox_client_vq1.dev		= dev;
		ddata->mbox_client_vq1.tx_done		= NULL;
		ddata->mbox_client_vq1.tx_block	= false;
		ddata->mbox_client_vq1.knows_txdone	= false;
		ddata->mbox_client_vq1.rx_callback	= st_rproc_mbox_callback_vq1;

		/*
		 * To control a co-processor without IPC mechanism.
		 * This driver can be used without mbox and rpmsg.
		 */
		chan = mbox_request_channel_byname(&ddata->mbox_client_vq0, "vq0_rx");
		if (IS_ERR(chan)) {
			dev_err(&rproc->dev, "failed to request mbox chan 0\n");
			ret = PTR_ERR(chan);
			goto free_clk;
		}
		ddata->mbox_chan[ST_RPROC_VQ0 * MBOX_MAX + MBOX_RX] = chan;

		chan = mbox_request_channel_byname(&ddata->mbox_client_vq0, "vq0_tx");
		if (IS_ERR(chan)) {
			dev_err(&rproc->dev, "failed to request mbox chan 0\n");
			ret = PTR_ERR(chan);
			goto free_mbox;
		}
		ddata->mbox_chan[ST_RPROC_VQ0 * MBOX_MAX + MBOX_TX] = chan;

		chan = mbox_request_channel_byname(&ddata->mbox_client_vq1, "vq1_rx");
		if (IS_ERR(chan)) {
			dev_err(&rproc->dev, "failed to request mbox chan 1\n");
			ret = PTR_ERR(chan);
			goto free_mbox;
		}
		ddata->mbox_chan[ST_RPROC_VQ1 * MBOX_MAX + MBOX_RX] = chan;

		chan = mbox_request_channel_byname(&ddata->mbox_client_vq1, "vq1_tx");
		if (IS_ERR(chan)) {
			dev_err(&rproc->dev, "failed to request mbox chan 1\n");
			ret = PTR_ERR(chan);
			goto free_mbox;
		}
		ddata->mbox_chan[ST_RPROC_VQ1 * MBOX_MAX + MBOX_TX] = chan;
	}

	ret = rproc_add(rproc);
	if (ret)
		goto free_mbox;

	return 0;

free_mbox:
	for (i = 0; i < ST_RPROC_MAX_VRING * MBOX_MAX; i++)
		mbox_free_channel(ddata->mbox_chan[i]);
free_clk:
	clk_unprepare(ddata->clk);
free_rproc:
	rproc_free(rproc);
	return ret;
}

__attribute__((used)) static int st_rproc_remove(struct platform_device *pdev)
{
	struct rproc *rproc = platform_get_drvdata(pdev);
	struct st_rproc *ddata = rproc->priv;
	int i;

	rproc_del(rproc);

	clk_disable_unprepare(ddata->clk);

	of_reserved_mem_device_release(&pdev->dev);

	for (i = 0; i < ST_RPROC_MAX_VRING * MBOX_MAX; i++)
		mbox_free_channel(ddata->mbox_chan[i]);

	rproc_free(rproc);

	return 0;
}

