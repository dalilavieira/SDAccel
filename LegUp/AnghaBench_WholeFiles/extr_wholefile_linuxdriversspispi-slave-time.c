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
typedef  int u64 ;
typedef  int u32 ;
struct TYPE_5__ {int len; void** tx_buf; } ;
struct TYPE_4__ {int status; void (* complete ) (void*) ;struct spi_slave_time_priv* context; } ;
struct spi_slave_time_priv {int /*<<< orphan*/  finished; TYPE_2__ xfer; void** buf; struct spi_device* spi; TYPE_1__ msg; } ;
struct spi_device {int /*<<< orphan*/  dev; } ;

/* Variables and functions */
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int /*<<< orphan*/  complete (int /*<<< orphan*/ *) ; 
 void* cpu_to_be32 (int) ; 
 int /*<<< orphan*/  dev_err (int /*<<< orphan*/ *,char*,int) ; 
 int /*<<< orphan*/  dev_info (int /*<<< orphan*/ *,char*) ; 
 struct spi_slave_time_priv* devm_kzalloc (int /*<<< orphan*/ *,int,int /*<<< orphan*/ ) ; 
 int do_div (int,int) ; 
 int /*<<< orphan*/  init_completion (int /*<<< orphan*/ *) ; 
 int local_clock () ; 
 int spi_async (struct spi_device*,TYPE_1__*) ; 
 struct spi_slave_time_priv* spi_get_drvdata (struct spi_device*) ; 
 int /*<<< orphan*/  spi_message_init_with_transfers (TYPE_1__*,TYPE_2__*,int) ; 
 int /*<<< orphan*/  spi_set_drvdata (struct spi_device*,struct spi_slave_time_priv*) ; 
 int /*<<< orphan*/  spi_slave_abort (struct spi_device*) ; 
static  int spi_slave_time_submit (struct spi_slave_time_priv*) ; 
 int /*<<< orphan*/  wait_for_completion (int /*<<< orphan*/ *) ; 

__attribute__((used)) static void spi_slave_time_complete(void *arg)
{
	struct spi_slave_time_priv *priv = arg;
	int ret;

	ret = priv->msg.status;
	if (ret)
		goto terminate;

	ret = spi_slave_time_submit(priv);
	if (ret)
		goto terminate;

	return;

terminate:
	dev_info(&priv->spi->dev, "Terminating\n");
	complete(&priv->finished);
}

__attribute__((used)) static int spi_slave_time_submit(struct spi_slave_time_priv *priv)
{
	u32 rem_us;
	int ret;
	u64 ts;

	ts = local_clock();
	rem_us = do_div(ts, 1000000000) / 1000;

	priv->buf[0] = cpu_to_be32(ts);
	priv->buf[1] = cpu_to_be32(rem_us);

	spi_message_init_with_transfers(&priv->msg, &priv->xfer, 1);

	priv->msg.complete = spi_slave_time_complete;
	priv->msg.context = priv;

	ret = spi_async(priv->spi, &priv->msg);
	if (ret)
		dev_err(&priv->spi->dev, "spi_async() failed %d\n", ret);

	return ret;
}

__attribute__((used)) static int spi_slave_time_probe(struct spi_device *spi)
{
	struct spi_slave_time_priv *priv;
	int ret;

	priv = devm_kzalloc(&spi->dev, sizeof(*priv), GFP_KERNEL);
	if (!priv)
		return -ENOMEM;

	priv->spi = spi;
	init_completion(&priv->finished);
	priv->xfer.tx_buf = priv->buf;
	priv->xfer.len = sizeof(priv->buf);

	ret = spi_slave_time_submit(priv);
	if (ret)
		return ret;

	spi_set_drvdata(spi, priv);
	return 0;
}

__attribute__((used)) static int spi_slave_time_remove(struct spi_device *spi)
{
	struct spi_slave_time_priv *priv = spi_get_drvdata(spi);

	spi_slave_abort(spi);
	wait_for_completion(&priv->finished);
	return 0;
}

