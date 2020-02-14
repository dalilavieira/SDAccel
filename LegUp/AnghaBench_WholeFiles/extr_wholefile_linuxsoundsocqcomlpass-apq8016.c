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
struct device {int dummy; } ;
struct platform_device {struct device dev; } ;
struct lpass_variant {int rdma_channels; int wrdma_channel_start; int wrdma_channels; } ;
struct lpass_data {void* pcnoc_sway_clk; void* pcnoc_mport_clk; int /*<<< orphan*/  dma_ch_bit_map; struct lpass_variant* variant; } ;

/* Variables and functions */
 int EBUSY ; 
 scalar_t__ IS_ERR (void*) ; 
 int PTR_ERR (void*) ; 
 int SNDRV_PCM_STREAM_PLAYBACK ; 
 int /*<<< orphan*/  clear_bit (int,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  clk_disable_unprepare (void*) ; 
 int clk_prepare_enable (void*) ; 
 int /*<<< orphan*/  dev_err (struct device*,char*,int) ; 
 void* devm_clk_get (struct device*,char*) ; 
 int find_first_zero_bit (int /*<<< orphan*/ *,int) ; 
 int find_next_zero_bit (int /*<<< orphan*/ *,int,int) ; 
 struct lpass_data* platform_get_drvdata (struct platform_device*) ; 
 int /*<<< orphan*/  set_bit (int,int /*<<< orphan*/ *) ; 

__attribute__((used)) static int apq8016_lpass_alloc_dma_channel(struct lpass_data *drvdata,
					   int direction)
{
	struct lpass_variant *v = drvdata->variant;
	int chan = 0;

	if (direction == SNDRV_PCM_STREAM_PLAYBACK) {
		chan = find_first_zero_bit(&drvdata->dma_ch_bit_map,
					v->rdma_channels);

		if (chan >= v->rdma_channels)
			return -EBUSY;
	} else {
		chan = find_next_zero_bit(&drvdata->dma_ch_bit_map,
					v->wrdma_channel_start +
					v->wrdma_channels,
					v->wrdma_channel_start);

		if (chan >=  v->wrdma_channel_start + v->wrdma_channels)
			return -EBUSY;
	}

	set_bit(chan, &drvdata->dma_ch_bit_map);

	return chan;
}

__attribute__((used)) static int apq8016_lpass_free_dma_channel(struct lpass_data *drvdata, int chan)
{
	clear_bit(chan, &drvdata->dma_ch_bit_map);

	return 0;
}

__attribute__((used)) static int apq8016_lpass_init(struct platform_device *pdev)
{
	struct lpass_data *drvdata = platform_get_drvdata(pdev);
	struct device *dev = &pdev->dev;
	int ret;

	drvdata->pcnoc_mport_clk = devm_clk_get(dev, "pcnoc-mport-clk");
	if (IS_ERR(drvdata->pcnoc_mport_clk)) {
		dev_err(&pdev->dev, "error getting pcnoc-mport-clk: %ld\n",
			PTR_ERR(drvdata->pcnoc_mport_clk));
		return PTR_ERR(drvdata->pcnoc_mport_clk);
	}

	ret = clk_prepare_enable(drvdata->pcnoc_mport_clk);
	if (ret) {
		dev_err(&pdev->dev, "Error enabling pcnoc-mport-clk: %d\n",
			ret);
		return ret;
	}

	drvdata->pcnoc_sway_clk = devm_clk_get(dev, "pcnoc-sway-clk");
	if (IS_ERR(drvdata->pcnoc_sway_clk)) {
		dev_err(&pdev->dev, "error getting pcnoc-sway-clk: %ld\n",
			PTR_ERR(drvdata->pcnoc_sway_clk));
		return PTR_ERR(drvdata->pcnoc_sway_clk);
	}

	ret = clk_prepare_enable(drvdata->pcnoc_sway_clk);
	if (ret) {
		dev_err(&pdev->dev, "Error enabling pcnoc_sway_clk: %d\n", ret);
		return ret;
	}

	return 0;
}

__attribute__((used)) static int apq8016_lpass_exit(struct platform_device *pdev)
{
	struct lpass_data *drvdata = platform_get_drvdata(pdev);

	clk_disable_unprepare(drvdata->pcnoc_mport_clk);
	clk_disable_unprepare(drvdata->pcnoc_sway_clk);

	return 0;
}

