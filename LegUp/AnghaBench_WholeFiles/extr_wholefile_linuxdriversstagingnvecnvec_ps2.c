#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_9__   TYPE_4__ ;
typedef  struct TYPE_8__   TYPE_3__ ;
typedef  struct TYPE_7__   TYPE_2__ ;
typedef  struct TYPE_6__   TYPE_1__ ;

/* Type definitions */
struct TYPE_6__ {int /*<<< orphan*/  type; } ;
struct serio {int (* write ) (struct serio*,unsigned char) ;int (* start ) (struct serio*) ;void (* stop ) (struct serio*) ;int /*<<< orphan*/  phys; int /*<<< orphan*/  name; TYPE_1__ id; int /*<<< orphan*/  dev; } ;
struct TYPE_7__ {int /*<<< orphan*/  parent; } ;
struct platform_device {TYPE_2__ dev; } ;
struct nvec_chip {int dummy; } ;
struct notifier_block {int dummy; } ;
typedef  int /*<<< orphan*/  buf ;
struct TYPE_9__ {int (* notifier_call ) (struct notifier_block*,unsigned long,void*) ;} ;
struct TYPE_8__ {struct serio* ser_dev; TYPE_4__ notifier; struct nvec_chip* nvec; } ;

/* Variables and functions */
 unsigned char AUTO_RECEIVE_N ; 
 unsigned char CANCEL_AUTO_RECEIVE ; 
 unsigned char DISABLE_MOUSE ; 
 unsigned char ENABLE_MOUSE ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int NOTIFY_DONE ; 
 int NOTIFY_STOP ; 
 int /*<<< orphan*/  NVEC_PHD (char*,unsigned char*,unsigned char) ; 
#define  NVEC_PS2 129 
#define  NVEC_PS2_EVT 128 
 unsigned char PACKET_SIZE ; 
 unsigned char SEND_COMMAND ; 
 int /*<<< orphan*/  SERIO_8042 ; 
 int /*<<< orphan*/  dev_dbg (int /*<<< orphan*/ *,char*,unsigned char) ; 
 struct nvec_chip* dev_get_drvdata (int /*<<< orphan*/ ) ; 
 struct serio* kzalloc (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  nvec_register_notifier (struct nvec_chip*,TYPE_4__*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  nvec_unregister_notifier (struct nvec_chip*,TYPE_4__*) ; 
 int nvec_write_async (struct nvec_chip*,unsigned char*,int) ; 
 TYPE_3__ ps2_dev ; 
 int /*<<< orphan*/  serio_interrupt (struct serio*,unsigned char,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  serio_register_port (struct serio*) ; 
 int /*<<< orphan*/  serio_unregister_port (struct serio*) ; 
 int /*<<< orphan*/  strlcpy (int /*<<< orphan*/ ,char*,int) ; 

__attribute__((used)) static int ps2_startstreaming(struct serio *ser_dev)
{
	unsigned char buf[] = { NVEC_PS2, AUTO_RECEIVE_N, PACKET_SIZE };

	return nvec_write_async(ps2_dev.nvec, buf, sizeof(buf));
}

__attribute__((used)) static void ps2_stopstreaming(struct serio *ser_dev)
{
	unsigned char buf[] = { NVEC_PS2, CANCEL_AUTO_RECEIVE };

	nvec_write_async(ps2_dev.nvec, buf, sizeof(buf));
}

__attribute__((used)) static int ps2_sendcommand(struct serio *ser_dev, unsigned char cmd)
{
	unsigned char buf[] = { NVEC_PS2, SEND_COMMAND, ENABLE_MOUSE, 1 };

	buf[2] = cmd & 0xff;

	dev_dbg(&ser_dev->dev, "Sending ps2 cmd %02x\n", cmd);
	return nvec_write_async(ps2_dev.nvec, buf, sizeof(buf));
}

__attribute__((used)) static int nvec_ps2_notifier(struct notifier_block *nb,
			     unsigned long event_type, void *data)
{
	int i;
	unsigned char *msg = data;

	switch (event_type) {
	case NVEC_PS2_EVT:
		for (i = 0; i < msg[1]; i++)
			serio_interrupt(ps2_dev.ser_dev, msg[2 + i], 0);
		NVEC_PHD("ps/2 mouse event: ", &msg[2], msg[1]);
		return NOTIFY_STOP;

	case NVEC_PS2:
		if (msg[2] == 1) {
			for (i = 0; i < (msg[1] - 2); i++)
				serio_interrupt(ps2_dev.ser_dev, msg[i + 4], 0);
			NVEC_PHD("ps/2 mouse reply: ", &msg[4], msg[1] - 2);
		}

		else if (msg[1] != 2) /* !ack */
			NVEC_PHD("unhandled mouse event: ", msg, msg[1] + 2);
		return NOTIFY_STOP;
	}

	return NOTIFY_DONE;
}

__attribute__((used)) static int nvec_mouse_probe(struct platform_device *pdev)
{
	struct nvec_chip *nvec = dev_get_drvdata(pdev->dev.parent);
	struct serio *ser_dev;

	ser_dev = kzalloc(sizeof(*ser_dev), GFP_KERNEL);
	if (!ser_dev)
		return -ENOMEM;

	ser_dev->id.type = SERIO_8042;
	ser_dev->write = ps2_sendcommand;
	ser_dev->start = ps2_startstreaming;
	ser_dev->stop = ps2_stopstreaming;

	strlcpy(ser_dev->name, "nvec mouse", sizeof(ser_dev->name));
	strlcpy(ser_dev->phys, "nvec", sizeof(ser_dev->phys));

	ps2_dev.ser_dev = ser_dev;
	ps2_dev.notifier.notifier_call = nvec_ps2_notifier;
	ps2_dev.nvec = nvec;
	nvec_register_notifier(nvec, &ps2_dev.notifier, 0);

	serio_register_port(ser_dev);

	return 0;
}

__attribute__((used)) static int nvec_mouse_remove(struct platform_device *pdev)
{
	struct nvec_chip *nvec = dev_get_drvdata(pdev->dev.parent);

	ps2_sendcommand(ps2_dev.ser_dev, DISABLE_MOUSE);
	ps2_stopstreaming(ps2_dev.ser_dev);
	nvec_unregister_notifier(nvec, &ps2_dev.notifier);
	serio_unregister_port(ps2_dev.ser_dev);

	return 0;
}

