#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_11__   TYPE_5__ ;
typedef  struct TYPE_10__   TYPE_2__ ;
typedef  struct TYPE_9__   TYPE_1__ ;

/* Type definitions */
typedef  int u8 ;
struct TYPE_11__ {TYPE_2__* parent; } ;
struct TYPE_9__ {int /*<<< orphan*/  type; } ;
struct serio {int (* open ) (struct serio*) ;void (* close ) (struct serio*) ;int /*<<< orphan*/  name; TYPE_5__ dev; struct ams_delta_serio* port_data; int /*<<< orphan*/  phys; TYPE_1__ id; } ;
struct TYPE_10__ {int* platform_data; } ;
struct platform_device {TYPE_2__ dev; } ;
struct ams_delta_serio {int* fiq_buffer; struct serio* serio; int /*<<< orphan*/  vcc; } ;
typedef  int /*<<< orphan*/  irqreturn_t ;

/* Variables and functions */
 int /*<<< orphan*/  DRIVER_NAME ; 
 int EINVAL ; 
 int ENODEV ; 
 int ENOMEM ; 
 int ENXIO ; 
 int EPROBE_DEFER ; 
 size_t FIQ_BUF_LEN ; 
 size_t FIQ_CIRC_BUFF ; 
 size_t FIQ_HEAD_OFFSET ; 
 size_t FIQ_IRQ_PEND ; 
 size_t FIQ_KEYS_CNT ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int /*<<< orphan*/  IRQ_HANDLED ; 
 int /*<<< orphan*/  IRQ_TYPE_EDGE_RISING ; 
 scalar_t__ IS_ERR (int /*<<< orphan*/ ) ; 
 int PTR_ERR (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  SERIO_8042 ; 
 int SERIO_FRAME ; 
 int SERIO_PARITY ; 
 int /*<<< orphan*/  dev_err (TYPE_2__*,char*,int) ; 
 int /*<<< orphan*/  dev_info (TYPE_5__*,char*,int /*<<< orphan*/ ) ; 
 char* dev_name (TYPE_2__*) ; 
 int /*<<< orphan*/  dev_warn (TYPE_5__*,char*,int,...) ; 
 struct ams_delta_serio* devm_kzalloc (TYPE_2__*,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  devm_regulator_get (TYPE_2__*,char*) ; 
 int devm_request_irq (TYPE_2__*,int,int /*<<< orphan*/  (*) (int,void*),int /*<<< orphan*/ ,int /*<<< orphan*/ ,struct ams_delta_serio*) ; 
 struct serio* kzalloc (int,int /*<<< orphan*/ ) ; 
 struct ams_delta_serio* platform_get_drvdata (struct platform_device*) ; 
 int platform_get_irq (struct platform_device*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  platform_set_drvdata (struct platform_device*,struct ams_delta_serio*) ; 
 int /*<<< orphan*/  regulator_disable (int /*<<< orphan*/ ) ; 
 int regulator_enable (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  serio_interrupt (struct serio*,int,int) ; 
 int /*<<< orphan*/  serio_register_port (struct serio*) ; 
 int /*<<< orphan*/  serio_unregister_port (struct serio*) ; 
 int /*<<< orphan*/  strlcpy (int /*<<< orphan*/ ,char*,int) ; 

__attribute__((used)) static int check_data(struct serio *serio, int data)
{
	int i, parity = 0;

	/* check valid stop bit */
	if (!(data & 0x400)) {
		dev_warn(&serio->dev, "invalid stop bit, data=0x%X\n", data);
		return SERIO_FRAME;
	}
	/* calculate the parity */
	for (i = 1; i < 10; i++) {
		if (data & (1 << i))
			parity++;
	}
	/* it should be odd */
	if (!(parity & 0x01)) {
		dev_warn(&serio->dev,
			 "parity check failed, data=0x%X parity=0x%X\n", data,
			 parity);
		return SERIO_PARITY;
	}
	return 0;
}

__attribute__((used)) static irqreturn_t ams_delta_serio_interrupt(int irq, void *dev_id)
{
	struct ams_delta_serio *priv = dev_id;
	int *circ_buff = &priv->fiq_buffer[FIQ_CIRC_BUFF];
	int data, dfl;
	u8 scancode;

	priv->fiq_buffer[FIQ_IRQ_PEND] = 0;

	/*
	 * Read data from the circular buffer, check it
	 * and then pass it on the serio
	 */
	while (priv->fiq_buffer[FIQ_KEYS_CNT] > 0) {

		data = circ_buff[priv->fiq_buffer[FIQ_HEAD_OFFSET]++];
		priv->fiq_buffer[FIQ_KEYS_CNT]--;
		if (priv->fiq_buffer[FIQ_HEAD_OFFSET] ==
		    priv->fiq_buffer[FIQ_BUF_LEN])
			priv->fiq_buffer[FIQ_HEAD_OFFSET] = 0;

		dfl = check_data(priv->serio, data);
		scancode = (u8) (data >> 1) & 0xFF;
		serio_interrupt(priv->serio, scancode, dfl);
	}
	return IRQ_HANDLED;
}

__attribute__((used)) static int ams_delta_serio_open(struct serio *serio)
{
	struct ams_delta_serio *priv = serio->port_data;

	/* enable keyboard */
	return regulator_enable(priv->vcc);
}

__attribute__((used)) static void ams_delta_serio_close(struct serio *serio)
{
	struct ams_delta_serio *priv = serio->port_data;

	/* disable keyboard */
	regulator_disable(priv->vcc);
}

__attribute__((used)) static int ams_delta_serio_init(struct platform_device *pdev)
{
	struct ams_delta_serio *priv;
	struct serio *serio;
	int irq, err;

	priv = devm_kzalloc(&pdev->dev, sizeof(*priv), GFP_KERNEL);
	if (!priv)
		return -ENOMEM;

	priv->fiq_buffer = pdev->dev.platform_data;
	if (!priv->fiq_buffer)
		return -EINVAL;

	priv->vcc = devm_regulator_get(&pdev->dev, "vcc");
	if (IS_ERR(priv->vcc)) {
		err = PTR_ERR(priv->vcc);
		dev_err(&pdev->dev, "regulator request failed (%d)\n", err);
		/*
		 * When running on a non-dt platform and requested regulator
		 * is not available, devm_regulator_get() never returns
		 * -EPROBE_DEFER as it is not able to justify if the regulator
		 * may still appear later.  On the other hand, the board can
		 * still set full constriants flag at late_initcall in order
		 * to instruct devm_regulator_get() to returnn a dummy one
		 * if sufficient.  Hence, if we get -ENODEV here, let's convert
		 * it to -EPROBE_DEFER and wait for the board to decide or
		 * let Deferred Probe infrastructure handle this error.
		 */
		if (err == -ENODEV)
			err = -EPROBE_DEFER;
		return err;
	}

	irq = platform_get_irq(pdev, 0);
	if (irq < 0)
		return -ENXIO;

	err = devm_request_irq(&pdev->dev, irq, ams_delta_serio_interrupt,
			       IRQ_TYPE_EDGE_RISING, DRIVER_NAME, priv);
	if (err < 0) {
		dev_err(&pdev->dev, "IRQ request failed (%d)\n", err);
		return err;
	}

	serio = kzalloc(sizeof(*serio), GFP_KERNEL);
	if (!serio)
		return -ENOMEM;

	priv->serio = serio;

	serio->id.type = SERIO_8042;
	serio->open = ams_delta_serio_open;
	serio->close = ams_delta_serio_close;
	strlcpy(serio->name, "AMS DELTA keyboard adapter", sizeof(serio->name));
	strlcpy(serio->phys, dev_name(&pdev->dev), sizeof(serio->phys));
	serio->dev.parent = &pdev->dev;
	serio->port_data = priv;

	serio_register_port(serio);

	platform_set_drvdata(pdev, priv);

	dev_info(&serio->dev, "%s\n", serio->name);

	return 0;
}

__attribute__((used)) static int ams_delta_serio_exit(struct platform_device *pdev)
{
	struct ams_delta_serio *priv = platform_get_drvdata(pdev);

	serio_unregister_port(priv->serio);

	return 0;
}

