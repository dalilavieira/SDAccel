#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_5__   TYPE_2__ ;
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
typedef  scalar_t__ u32 ;
struct TYPE_5__ {int /*<<< orphan*/  of_node; } ;
struct platform_device {TYPE_2__ dev; } ;
struct of_phandle_args {int args_count; scalar_t__* args; } ;
struct of_dma {int dummy; } ;
struct of_dev_auxdata {int dummy; } ;
struct dma_chan {int dummy; } ;
typedef  int /*<<< orphan*/  dma_cap_mask_t ;
struct TYPE_4__ {scalar_t__ hw_req; } ;

/* Variables and functions */
 int /*<<< orphan*/  DMA_SLAVE ; 
 struct of_dev_auxdata* dev_get_platdata (TYPE_2__*) ; 
 int /*<<< orphan*/  dma_cap_set (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  dma_cap_zero (int /*<<< orphan*/ ) ; 
 struct dma_chan* dma_request_channel (int /*<<< orphan*/ ,int /*<<< orphan*/ ,void*) ; 
 int /*<<< orphan*/  of_dma_controller_free (int /*<<< orphan*/ ) ; 
 int of_dma_controller_register (int /*<<< orphan*/ ,struct dma_chan* (*) (struct of_phandle_args*,struct of_dma*),struct platform_device*) ; 
 int of_platform_populate (int /*<<< orphan*/ ,int /*<<< orphan*/ *,struct of_dev_auxdata const*,TYPE_2__*) ; 
 int /*<<< orphan*/  shdma_chan_filter ; 
 TYPE_1__* to_shdma_chan (struct dma_chan*) ; 

__attribute__((used)) static struct dma_chan *shdma_of_xlate(struct of_phandle_args *dma_spec,
				       struct of_dma *ofdma)
{
	u32 id = dma_spec->args[0];
	dma_cap_mask_t mask;
	struct dma_chan *chan;

	if (dma_spec->args_count != 1)
		return NULL;

	dma_cap_zero(mask);
	/* Only slave DMA channels can be allocated via DT */
	dma_cap_set(DMA_SLAVE, mask);

	chan = dma_request_channel(mask, shdma_chan_filter,
				   (void *)(uintptr_t)id);
	if (chan)
		to_shdma_chan(chan)->hw_req = id;

	return chan;
}

__attribute__((used)) static int shdma_of_probe(struct platform_device *pdev)
{
	const struct of_dev_auxdata *lookup = dev_get_platdata(&pdev->dev);
	int ret;

	ret = of_dma_controller_register(pdev->dev.of_node,
					 shdma_of_xlate, pdev);
	if (ret < 0)
		return ret;

	ret = of_platform_populate(pdev->dev.of_node, NULL, lookup, &pdev->dev);
	if (ret < 0)
		of_dma_controller_free(pdev->dev.of_node);

	return ret;
}

