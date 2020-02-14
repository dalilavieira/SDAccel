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
struct serio_driver {int dummy; } ;
struct serio {int dummy; } ;
struct TYPE_2__ {size_t head; size_t tail; unsigned char* buf; } ;
struct iforce {int pkt; unsigned char id; unsigned char len; int idx; unsigned char* data; int /*<<< orphan*/  dev; struct serio* serio; int /*<<< orphan*/  bus; scalar_t__ csum; int /*<<< orphan*/  xmit_lock; int /*<<< orphan*/  xmit_flags; TYPE_1__ xmit; } ;
typedef  int /*<<< orphan*/  irqreturn_t ;

/* Variables and functions */
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int /*<<< orphan*/  IFORCE_232 ; 
 unsigned char IFORCE_MAX_LENGTH ; 
 int /*<<< orphan*/  IFORCE_XMIT_AGAIN ; 
 int /*<<< orphan*/  IFORCE_XMIT_RUNNING ; 
 int /*<<< orphan*/  IRQ_HANDLED ; 
 int /*<<< orphan*/  XMIT_INC (size_t,int) ; 
 int /*<<< orphan*/  clear_bit (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int iforce_init_device (struct iforce*) ; 
 int /*<<< orphan*/  iforce_process_packet (struct iforce*,int,unsigned char*) ; 
 int /*<<< orphan*/  input_unregister_device (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  kfree (struct iforce*) ; 
 struct iforce* kzalloc (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  serio_close (struct serio*) ; 
 struct iforce* serio_get_drvdata (struct serio*) ; 
 int serio_open (struct serio*,struct serio_driver*) ; 
 int /*<<< orphan*/  serio_set_drvdata (struct serio*,struct iforce*) ; 
 int /*<<< orphan*/  serio_write (struct serio*,unsigned char) ; 
 int /*<<< orphan*/  set_bit (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  spin_lock_irqsave (int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  spin_unlock_irqrestore (int /*<<< orphan*/ *,unsigned long) ; 
 scalar_t__ test_and_clear_bit (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 scalar_t__ test_and_set_bit (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

void iforce_serial_xmit(struct iforce *iforce)
{
	unsigned char cs;
	int i;
	unsigned long flags;

	if (test_and_set_bit(IFORCE_XMIT_RUNNING, iforce->xmit_flags)) {
		set_bit(IFORCE_XMIT_AGAIN, iforce->xmit_flags);
		return;
	}

	spin_lock_irqsave(&iforce->xmit_lock, flags);

again:
	if (iforce->xmit.head == iforce->xmit.tail) {
		clear_bit(IFORCE_XMIT_RUNNING, iforce->xmit_flags);
		spin_unlock_irqrestore(&iforce->xmit_lock, flags);
		return;
	}

	cs = 0x2b;

	serio_write(iforce->serio, 0x2b);

	serio_write(iforce->serio, iforce->xmit.buf[iforce->xmit.tail]);
	cs ^= iforce->xmit.buf[iforce->xmit.tail];
	XMIT_INC(iforce->xmit.tail, 1);

	for (i=iforce->xmit.buf[iforce->xmit.tail]; i >= 0; --i) {
		serio_write(iforce->serio, iforce->xmit.buf[iforce->xmit.tail]);
		cs ^= iforce->xmit.buf[iforce->xmit.tail];
		XMIT_INC(iforce->xmit.tail, 1);
	}

	serio_write(iforce->serio, cs);

	if (test_and_clear_bit(IFORCE_XMIT_AGAIN, iforce->xmit_flags))
		goto again;

	clear_bit(IFORCE_XMIT_RUNNING, iforce->xmit_flags);

	spin_unlock_irqrestore(&iforce->xmit_lock, flags);
}

__attribute__((used)) static void iforce_serio_write_wakeup(struct serio *serio)
{
	struct iforce *iforce = serio_get_drvdata(serio);

	iforce_serial_xmit(iforce);
}

__attribute__((used)) static irqreturn_t iforce_serio_irq(struct serio *serio,
		unsigned char data, unsigned int flags)
{
	struct iforce *iforce = serio_get_drvdata(serio);

	if (!iforce->pkt) {
		if (data == 0x2b)
			iforce->pkt = 1;
		goto out;
	}

	if (!iforce->id) {
		if (data > 3 && data != 0xff)
			iforce->pkt = 0;
		else
			iforce->id = data;
		goto out;
	}

	if (!iforce->len) {
		if (data > IFORCE_MAX_LENGTH) {
			iforce->pkt = 0;
			iforce->id = 0;
		} else {
			iforce->len = data;
		}
		goto out;
	}

	if (iforce->idx < iforce->len) {
		iforce->csum += iforce->data[iforce->idx++] = data;
		goto out;
	}

	if (iforce->idx == iforce->len) {
		iforce_process_packet(iforce, (iforce->id << 8) | iforce->idx, iforce->data);
		iforce->pkt = 0;
		iforce->id  = 0;
		iforce->len = 0;
		iforce->idx = 0;
		iforce->csum = 0;
	}
out:
	return IRQ_HANDLED;
}

__attribute__((used)) static int iforce_serio_connect(struct serio *serio, struct serio_driver *drv)
{
	struct iforce *iforce;
	int err;

	iforce = kzalloc(sizeof(struct iforce), GFP_KERNEL);
	if (!iforce)
		return -ENOMEM;

	iforce->bus = IFORCE_232;
	iforce->serio = serio;

	serio_set_drvdata(serio, iforce);

	err = serio_open(serio, drv);
	if (err)
		goto fail1;

	err = iforce_init_device(iforce);
	if (err)
		goto fail2;

	return 0;

 fail2:	serio_close(serio);
 fail1:	serio_set_drvdata(serio, NULL);
	kfree(iforce);
	return err;
}

__attribute__((used)) static void iforce_serio_disconnect(struct serio *serio)
{
	struct iforce *iforce = serio_get_drvdata(serio);

	input_unregister_device(iforce->dev);
	serio_close(serio);
	serio_set_drvdata(serio, NULL);
	kfree(iforce);
}

