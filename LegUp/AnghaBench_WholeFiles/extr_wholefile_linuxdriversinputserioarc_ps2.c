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
struct serio {struct arc_ps2_port* port_data; int /*<<< orphan*/  dev; } ;
struct arc_ps2_port {int /*<<< orphan*/  status_addr; int /*<<< orphan*/  data_addr; TYPE_1__* io; } ;
struct arc_ps2_data {struct arc_ps2_port* port; int /*<<< orphan*/  buf_overflow; int /*<<< orphan*/  frame_error; int /*<<< orphan*/  total_int; } ;
typedef  int /*<<< orphan*/  irqreturn_t ;
struct TYPE_2__ {int /*<<< orphan*/  dev; } ;

/* Variables and functions */
 int ARC_PS2_PORTS ; 
 int ETIMEDOUT ; 
 int /*<<< orphan*/  IRQ_HANDLED ; 
 unsigned int PS2_STAT_RX_BUF_OVER ; 
 unsigned int PS2_STAT_RX_FRM_ERR ; 
 unsigned char PS2_STAT_RX_INT_EN ; 
 unsigned int PS2_STAT_RX_VAL ; 
 unsigned int PS2_STAT_TX_ISNOT_FUL ; 
 unsigned int SERIO_FRAME ; 
 unsigned int SERIO_PARITY ; 
 int STAT_TIMEOUT ; 
 int /*<<< orphan*/  cpu_relax () ; 
 int /*<<< orphan*/  dev_err (int /*<<< orphan*/ *,char*) ; 
 unsigned char ioread32 (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  iowrite32 (unsigned char,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  serio_interrupt (TYPE_1__*,unsigned char,unsigned int) ; 

__attribute__((used)) static void arc_ps2_check_rx(struct arc_ps2_data *arc_ps2,
			     struct arc_ps2_port *port)
{
	unsigned int timeout = 1000;
	unsigned int flag, status;
	unsigned char data;

	do {
		status = ioread32(port->status_addr);
		if (!(status & PS2_STAT_RX_VAL))
			return;

		data = ioread32(port->data_addr) & 0xff;

		flag = 0;
		arc_ps2->total_int++;
		if (status & PS2_STAT_RX_FRM_ERR) {
			arc_ps2->frame_error++;
			flag |= SERIO_PARITY;
		} else if (status & PS2_STAT_RX_BUF_OVER) {
			arc_ps2->buf_overflow++;
			flag |= SERIO_FRAME;
		}

		serio_interrupt(port->io, data, flag);
	} while (--timeout);

	dev_err(&port->io->dev, "PS/2 hardware stuck\n");
}

__attribute__((used)) static irqreturn_t arc_ps2_interrupt(int irq, void *dev)
{
	struct arc_ps2_data *arc_ps2 = dev;
	int i;

	for (i = 0; i < ARC_PS2_PORTS; i++)
		arc_ps2_check_rx(arc_ps2, &arc_ps2->port[i]);

	return IRQ_HANDLED;
}

__attribute__((used)) static int arc_ps2_write(struct serio *io, unsigned char val)
{
	unsigned status;
	struct arc_ps2_port *port = io->port_data;
	int timeout = STAT_TIMEOUT;

	do {
		status = ioread32(port->status_addr);
		cpu_relax();

		if (status & PS2_STAT_TX_ISNOT_FUL) {
			iowrite32(val & 0xff, port->data_addr);
			return 0;
		}

	} while (--timeout);

	dev_err(&io->dev, "write timeout\n");
	return -ETIMEDOUT;
}

__attribute__((used)) static int arc_ps2_open(struct serio *io)
{
	struct arc_ps2_port *port = io->port_data;

	iowrite32(PS2_STAT_RX_INT_EN, port->status_addr);

	return 0;
}

__attribute__((used)) static void arc_ps2_close(struct serio *io)
{
	struct arc_ps2_port *port = io->port_data;

	iowrite32(ioread32(port->status_addr) & ~PS2_STAT_RX_INT_EN,
		  port->status_addr);
}

