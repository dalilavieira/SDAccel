#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_6__   TYPE_3__ ;
typedef  struct TYPE_5__   TYPE_2__ ;
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
struct nokia_modem_device {int gpio_amount; int nokia_modem_rst_ind_irq; int /*<<< orphan*/  nokia_modem_rst_ind_tasklet; TYPE_2__* ssi_protocol; TYPE_1__* cmt_speech; struct device* device; TYPE_3__* gpios; } ;
struct hsi_port {int dummy; } ;
struct hsi_client {int /*<<< orphan*/  rx_cfg; int /*<<< orphan*/  tx_cfg; } ;
struct hsi_board_info {char* name; int /*<<< orphan*/ * archdata; int /*<<< orphan*/ * platform_data; int /*<<< orphan*/  rx_cfg; int /*<<< orphan*/  tx_cfg; } ;
struct device_node {int dummy; } ;
struct device {struct device_node* of_node; int /*<<< orphan*/  kobj; } ;
typedef  int /*<<< orphan*/  irqreturn_t ;
struct TYPE_6__ {int /*<<< orphan*/  gpio; int /*<<< orphan*/  name; } ;
struct TYPE_5__ {int /*<<< orphan*/  device; } ;
struct TYPE_4__ {int /*<<< orphan*/  device; } ;

/* Variables and functions */
 int EINVAL ; 
 int ENOMEM ; 
 int ENXIO ; 
 int EPROBE_DEFER ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int /*<<< orphan*/  GPIOD_OUT_LOW ; 
 int /*<<< orphan*/  IRQ_HANDLED ; 
 scalar_t__ IS_ERR (int /*<<< orphan*/ ) ; 
 int PTR_ERR (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  dev_dbg (struct device*,char*) ; 
 int /*<<< orphan*/  dev_err (struct device*,char*,...) ; 
 struct nokia_modem_device* dev_get_drvdata (struct device*) ; 
 int /*<<< orphan*/  dev_info (struct device*,char*) ; 
 int /*<<< orphan*/  dev_set_drvdata (struct device*,struct nokia_modem_device*) ; 
 int device_attach (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  devm_gpiod_get_index (struct device*,int /*<<< orphan*/ *,int,int /*<<< orphan*/ ) ; 
 TYPE_3__* devm_kcalloc (struct device*,int,int,int /*<<< orphan*/ ) ; 
 struct nokia_modem_device* devm_kzalloc (struct device*,int,int /*<<< orphan*/ ) ; 
 int devm_request_irq (struct device*,int,int /*<<< orphan*/  (*) (int,void*),int,char*,struct nokia_modem_device*) ; 
 int /*<<< orphan*/  disable_irq_wake (int) ; 
 int /*<<< orphan*/  enable_irq_wake (int) ; 
 int gpiod_export (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int gpiod_export_link (struct device*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  gpiod_unexport (int /*<<< orphan*/ ) ; 
 struct hsi_port* hsi_get_port (struct hsi_client*) ; 
 void* hsi_new_client (struct hsi_port*,struct hsi_board_info*) ; 
 int /*<<< orphan*/  hsi_remove_client (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int irq_get_trigger_type (int) ; 
 int irq_of_parse_and_map (struct device_node*,int /*<<< orphan*/ ) ; 
 int of_gpio_count (struct device_node*) ; 
 int of_property_count_strings (struct device_node*,char*) ; 
 int of_property_read_string_index (struct device_node*,char*,int,int /*<<< orphan*/ *) ; 
 scalar_t__ pm ; 
 int /*<<< orphan*/  ssip_reset_event (TYPE_2__*) ; 
 int /*<<< orphan*/  sysfs_remove_link (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  tasklet_init (int /*<<< orphan*/ *,void (*) (unsigned long),unsigned long) ; 
 int /*<<< orphan*/  tasklet_kill (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  tasklet_schedule (int /*<<< orphan*/ *) ; 
 struct hsi_client* to_hsi_client (struct device*) ; 

__attribute__((used)) static void do_nokia_modem_rst_ind_tasklet(unsigned long data)
{
	struct nokia_modem_device *modem = (struct nokia_modem_device *)data;

	if (!modem)
		return;

	dev_info(modem->device, "CMT rst line change detected\n");

	if (modem->ssi_protocol)
		ssip_reset_event(modem->ssi_protocol);
}

__attribute__((used)) static irqreturn_t nokia_modem_rst_ind_isr(int irq, void *data)
{
	struct nokia_modem_device *modem = (struct nokia_modem_device *)data;

	tasklet_schedule(&modem->nokia_modem_rst_ind_tasklet);

	return IRQ_HANDLED;
}

__attribute__((used)) static void nokia_modem_gpio_unexport(struct device *dev)
{
	struct nokia_modem_device *modem = dev_get_drvdata(dev);
	int i;

	for (i = 0; i < modem->gpio_amount; i++) {
		sysfs_remove_link(&dev->kobj, modem->gpios[i].name);
		gpiod_unexport(modem->gpios[i].gpio);
	}
}

__attribute__((used)) static int nokia_modem_gpio_probe(struct device *dev)
{
	struct device_node *np = dev->of_node;
	struct nokia_modem_device *modem = dev_get_drvdata(dev);
	int gpio_count, gpio_name_count, i, err;

	gpio_count = of_gpio_count(np);

	if (gpio_count < 0) {
		dev_err(dev, "missing gpios: %d\n", gpio_count);
		return gpio_count;
	}

	gpio_name_count = of_property_count_strings(np, "gpio-names");

	if (gpio_count != gpio_name_count) {
		dev_err(dev, "number of gpios does not equal number of gpio names\n");
		return -EINVAL;
	}

	modem->gpios = devm_kcalloc(dev, gpio_count, sizeof(*modem->gpios),
				    GFP_KERNEL);
	if (!modem->gpios)
		return -ENOMEM;

	modem->gpio_amount = gpio_count;

	for (i = 0; i < gpio_count; i++) {
		modem->gpios[i].gpio = devm_gpiod_get_index(dev, NULL, i,
							    GPIOD_OUT_LOW);
		if (IS_ERR(modem->gpios[i].gpio)) {
			dev_err(dev, "Could not get gpio %d\n", i);
			return PTR_ERR(modem->gpios[i].gpio);
		}

		err = of_property_read_string_index(np, "gpio-names", i,
						&(modem->gpios[i].name));
		if (err) {
			dev_err(dev, "Could not get gpio name %d\n", i);
			return err;
		}

		err = gpiod_export(modem->gpios[i].gpio, 0);
		if (err)
			return err;

		err = gpiod_export_link(dev, modem->gpios[i].name,
							modem->gpios[i].gpio);
		if (err)
			return err;
	}

	return 0;
}

__attribute__((used)) static int nokia_modem_probe(struct device *dev)
{
	struct device_node *np;
	struct nokia_modem_device *modem;
	struct hsi_client *cl = to_hsi_client(dev);
	struct hsi_port *port = hsi_get_port(cl);
	int irq, pflags, err;
	struct hsi_board_info ssip;
	struct hsi_board_info cmtspeech;

	np = dev->of_node;
	if (!np) {
		dev_err(dev, "device tree node not found\n");
		return -ENXIO;
	}

	modem = devm_kzalloc(dev, sizeof(*modem), GFP_KERNEL);
	if (!modem)
		return -ENOMEM;

	dev_set_drvdata(dev, modem);
	modem->device = dev;

	irq = irq_of_parse_and_map(np, 0);
	if (!irq) {
		dev_err(dev, "Invalid rst_ind interrupt (%d)\n", irq);
		return -EINVAL;
	}
	modem->nokia_modem_rst_ind_irq = irq;
	pflags = irq_get_trigger_type(irq);

	tasklet_init(&modem->nokia_modem_rst_ind_tasklet,
			do_nokia_modem_rst_ind_tasklet, (unsigned long)modem);
	err = devm_request_irq(dev, irq, nokia_modem_rst_ind_isr,
				pflags, "modem_rst_ind", modem);
	if (err < 0) {
		dev_err(dev, "Request rst_ind irq(%d) failed (flags %d)\n",
								irq, pflags);
		return err;
	}
	enable_irq_wake(irq);

	if (pm) {
		err = nokia_modem_gpio_probe(dev);
		if (err < 0) {
			dev_err(dev, "Could not probe GPIOs\n");
			goto error1;
		}
	}

	ssip.name = "ssi-protocol";
	ssip.tx_cfg = cl->tx_cfg;
	ssip.rx_cfg = cl->rx_cfg;
	ssip.platform_data = NULL;
	ssip.archdata = NULL;

	modem->ssi_protocol = hsi_new_client(port, &ssip);
	if (!modem->ssi_protocol) {
		dev_err(dev, "Could not register ssi-protocol device\n");
		err = -ENOMEM;
		goto error2;
	}

	err = device_attach(&modem->ssi_protocol->device);
	if (err == 0) {
		dev_dbg(dev, "Missing ssi-protocol driver\n");
		err = -EPROBE_DEFER;
		goto error3;
	} else if (err < 0) {
		dev_err(dev, "Could not load ssi-protocol driver (%d)\n", err);
		goto error3;
	}

	cmtspeech.name = "cmt-speech";
	cmtspeech.tx_cfg = cl->tx_cfg;
	cmtspeech.rx_cfg = cl->rx_cfg;
	cmtspeech.platform_data = NULL;
	cmtspeech.archdata = NULL;

	modem->cmt_speech = hsi_new_client(port, &cmtspeech);
	if (!modem->cmt_speech) {
		dev_err(dev, "Could not register cmt-speech device\n");
		err = -ENOMEM;
		goto error3;
	}

	err = device_attach(&modem->cmt_speech->device);
	if (err == 0) {
		dev_dbg(dev, "Missing cmt-speech driver\n");
		err = -EPROBE_DEFER;
		goto error4;
	} else if (err < 0) {
		dev_err(dev, "Could not load cmt-speech driver (%d)\n", err);
		goto error4;
	}

	dev_info(dev, "Registered Nokia HSI modem\n");

	return 0;

error4:
	hsi_remove_client(&modem->cmt_speech->device, NULL);
error3:
	hsi_remove_client(&modem->ssi_protocol->device, NULL);
error2:
	nokia_modem_gpio_unexport(dev);
error1:
	disable_irq_wake(modem->nokia_modem_rst_ind_irq);
	tasklet_kill(&modem->nokia_modem_rst_ind_tasklet);

	return err;
}

__attribute__((used)) static int nokia_modem_remove(struct device *dev)
{
	struct nokia_modem_device *modem = dev_get_drvdata(dev);

	if (!modem)
		return 0;

	if (modem->cmt_speech) {
		hsi_remove_client(&modem->cmt_speech->device, NULL);
		modem->cmt_speech = NULL;
	}

	if (modem->ssi_protocol) {
		hsi_remove_client(&modem->ssi_protocol->device, NULL);
		modem->ssi_protocol = NULL;
	}

	nokia_modem_gpio_unexport(dev);
	dev_set_drvdata(dev, NULL);
	disable_irq_wake(modem->nokia_modem_rst_ind_irq);
	tasklet_kill(&modem->nokia_modem_rst_ind_tasklet);

	return 0;
}

