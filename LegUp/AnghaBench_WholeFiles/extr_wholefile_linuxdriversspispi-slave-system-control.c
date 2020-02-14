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
typedef  int u16 ;
struct TYPE_5__ {int len; int /*<<< orphan*/ * rx_buf; } ;
struct TYPE_4__ {void (* complete ) (void*) ;struct spi_slave_system_control_priv* context; scalar_t__ status; } ;
struct spi_slave_system_control_priv {int /*<<< orphan*/  finished; TYPE_2__ xfer; int /*<<< orphan*/  cmd; struct spi_device* spi; TYPE_1__ msg; } ;
struct spi_device {int /*<<< orphan*/  dev; } ;

/* Variables and functions */
#define  CMD_HALT 131 
#define  CMD_POWEROFF 130 
#define  CMD_REBOOT 129 
#define  CMD_SUSPEND 128 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int /*<<< orphan*/  PM_SUSPEND_MEM ; 
 int be16_to_cpu (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  complete (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  dev_err (int /*<<< orphan*/ *,char*,int) ; 
 int /*<<< orphan*/  dev_info (int /*<<< orphan*/ *,char*) ; 
 int /*<<< orphan*/  dev_warn (int /*<<< orphan*/ *,char*,int) ; 
 struct spi_slave_system_control_priv* devm_kzalloc (int /*<<< orphan*/ *,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  init_completion (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  kernel_halt () ; 
 int /*<<< orphan*/  kernel_power_off () ; 
 int /*<<< orphan*/  kernel_restart (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  pm_suspend (int /*<<< orphan*/ ) ; 
 int spi_async (struct spi_device*,TYPE_1__*) ; 
 struct spi_slave_system_control_priv* spi_get_drvdata (struct spi_device*) ; 
 int /*<<< orphan*/  spi_message_init_with_transfers (TYPE_1__*,TYPE_2__*,int) ; 
 int /*<<< orphan*/  spi_set_drvdata (struct spi_device*,struct spi_slave_system_control_priv*) ; 
 int /*<<< orphan*/  spi_slave_abort (struct spi_device*) ; 
static  int spi_slave_system_control_submit (struct spi_slave_system_control_priv*) ; 
 int /*<<< orphan*/  wait_for_completion (int /*<<< orphan*/ *) ; 

__attribute__((used)) static void spi_slave_system_control_complete(void *arg)
{
	struct spi_slave_system_control_priv *priv = arg;
	u16 cmd;
	int ret;

	if (priv->msg.status)
		goto terminate;

	cmd = be16_to_cpu(priv->cmd);
	switch (cmd) {
	case CMD_REBOOT:
		dev_info(&priv->spi->dev, "Rebooting system...\n");
		kernel_restart(NULL);

	case CMD_POWEROFF:
		dev_info(&priv->spi->dev, "Powering off system...\n");
		kernel_power_off();
		break;

	case CMD_HALT:
		dev_info(&priv->spi->dev, "Halting system...\n");
		kernel_halt();
		break;

	case CMD_SUSPEND:
		dev_info(&priv->spi->dev, "Suspending system...\n");
		pm_suspend(PM_SUSPEND_MEM);
		break;

	default:
		dev_warn(&priv->spi->dev, "Unknown command 0x%x\n", cmd);
		break;
	}

	ret = spi_slave_system_control_submit(priv);
	if (ret)
		goto terminate;

	return;

terminate:
	dev_info(&priv->spi->dev, "Terminating\n");
	complete(&priv->finished);
}

__attribute__((used)) static
int spi_slave_system_control_submit(struct spi_slave_system_control_priv *priv)
{
	int ret;

	spi_message_init_with_transfers(&priv->msg, &priv->xfer, 1);

	priv->msg.complete = spi_slave_system_control_complete;
	priv->msg.context = priv;

	ret = spi_async(priv->spi, &priv->msg);
	if (ret)
		dev_err(&priv->spi->dev, "spi_async() failed %d\n", ret);

	return ret;
}

__attribute__((used)) static int spi_slave_system_control_probe(struct spi_device *spi)
{
	struct spi_slave_system_control_priv *priv;
	int ret;

	priv = devm_kzalloc(&spi->dev, sizeof(*priv), GFP_KERNEL);
	if (!priv)
		return -ENOMEM;

	priv->spi = spi;
	init_completion(&priv->finished);
	priv->xfer.rx_buf = &priv->cmd;
	priv->xfer.len = sizeof(priv->cmd);

	ret = spi_slave_system_control_submit(priv);
	if (ret)
		return ret;

	spi_set_drvdata(spi, priv);
	return 0;
}

__attribute__((used)) static int spi_slave_system_control_remove(struct spi_device *spi)
{
	struct spi_slave_system_control_priv *priv = spi_get_drvdata(spi);

	spi_slave_abort(spi);
	wait_for_completion(&priv->finished);
	return 0;
}

