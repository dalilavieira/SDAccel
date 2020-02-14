#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
struct uart_port {int minor; } ;
struct TYPE_3__ {int (* serial_in ) (TYPE_1__*,int) ;int flags; int regshift; scalar_t__ mapbase; scalar_t__ membase; int /*<<< orphan*/ * dev; int /*<<< orphan*/  iotype; int /*<<< orphan*/  uartclk; int /*<<< orphan*/  irq; int /*<<< orphan*/  (* serial_out ) (TYPE_1__*,int,int) ;} ;
struct uart_8250_port {int (* dl_read ) (struct uart_8250_port*) ;TYPE_1__ port; int /*<<< orphan*/  (* dl_write ) (struct uart_8250_port*,int) ;} ;
struct serial_card_type {unsigned int num_ports; scalar_t__* offset; int /*<<< orphan*/  uartclk; int /*<<< orphan*/  type; } ;
struct serial_card_info {unsigned int num_ports; scalar_t__* ports; scalar_t__ vaddr; } ;
struct expansion_card {int /*<<< orphan*/  dev; int /*<<< orphan*/  irq; } ;
struct ecard_id {struct serial_card_type* data; } ;
typedef  int status ;

/* Variables and functions */
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int UART_MCR ; 
 int UPF_BOOT_AUTOCONF ; 
 int UPF_SHARE_IRQ ; 
 int /*<<< orphan*/  UPIO_MEM ; 
 struct serial_card_info* ecard_get_drvdata (struct expansion_card*) ; 
 unsigned long ecard_resource_start (struct expansion_card*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ecard_set_drvdata (struct expansion_card*,struct serial_card_info*) ; 
 scalar_t__ ecardm_iomap (struct expansion_card*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  kfree (struct serial_card_info*) ; 
 struct serial_card_info* kzalloc (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  memset (struct uart_8250_port*,int /*<<< orphan*/ ,int) ; 
 scalar_t__ serial8250_register_8250_port (struct uart_8250_port*) ; 
 int /*<<< orphan*/  serial8250_unregister_port (scalar_t__) ; 
 int stub1 (TYPE_1__*,int) ; 
 int /*<<< orphan*/  stub2 (TYPE_1__*,int,int) ; 
 int stub3 (struct uart_8250_port*) ; 
 int /*<<< orphan*/  stub4 (struct uart_8250_port*,int) ; 

__attribute__((used)) static inline int serial_in(struct uart_8250_port *up, int offset)
{
	return up->port.serial_in(&up->port, offset);
}

__attribute__((used)) static inline void serial_out(struct uart_8250_port *up, int offset, int value)
{
	up->port.serial_out(&up->port, offset, value);
}

__attribute__((used)) static inline int serial_dl_read(struct uart_8250_port *up)
{
	return up->dl_read(up);
}

__attribute__((used)) static inline void serial_dl_write(struct uart_8250_port *up, int value)
{
	up->dl_write(up, value);
}

__attribute__((used)) static inline void serial8250_out_MCR(struct uart_8250_port *up, int value)
{
	serial_out(up, UART_MCR, value);
}

__attribute__((used)) static inline int serial8250_in_MCR(struct uart_8250_port *up)
{
	return serial_in(up, UART_MCR);
}

__attribute__((used)) static inline int serial8250_pnp_init(void) { return 0; }

__attribute__((used)) static inline void serial8250_pnp_exit(void) { }

__attribute__((used)) static inline int fintek_8250_probe(struct uart_8250_port *uart) { return 0; }

__attribute__((used)) static inline int is_omap1_8250(struct uart_8250_port *pt)
{
	return 0;
}

__attribute__((used)) static inline int is_omap1510_8250(struct uart_8250_port *pt)
{
	return 0;
}

__attribute__((used)) static inline int serial8250_tx_dma(struct uart_8250_port *p)
{
	return -1;
}

__attribute__((used)) static inline int serial8250_rx_dma(struct uart_8250_port *p)
{
	return -1;
}

__attribute__((used)) static inline void serial8250_rx_dma_flush(struct uart_8250_port *p) { }

__attribute__((used)) static inline int serial8250_request_dma(struct uart_8250_port *p)
{
	return -1;
}

__attribute__((used)) static inline void serial8250_release_dma(struct uart_8250_port *p) { }

__attribute__((used)) static inline int ns16550a_goto_highspeed(struct uart_8250_port *up)
{
	unsigned char status;

	status = serial_in(up, 0x04); /* EXCR2 */
#define PRESL(x) ((x) & 0x30)
	if (PRESL(status) == 0x10) {
		/* already in high speed mode */
		return 0;
	} else {
		status &= ~0xB0; /* Disable LOCK, mask out PRESL[01] */
		status |= 0x10;  /* 1.625 divisor for baud_base --> 921600 */
		serial_out(up, 0x04, status);
	}
	return 1;
}

__attribute__((used)) static inline int serial_index(struct uart_port *port)
{
	return port->minor - 64;
}

__attribute__((used)) static int
serial_card_probe(struct expansion_card *ec, const struct ecard_id *id)
{
	struct serial_card_info *info;
	struct serial_card_type *type = id->data;
	struct uart_8250_port uart;
	unsigned long bus_addr;
	unsigned int i;

	info = kzalloc(sizeof(struct serial_card_info), GFP_KERNEL);
	if (!info)
		return -ENOMEM;

	info->num_ports = type->num_ports;

	bus_addr = ecard_resource_start(ec, type->type);
	info->vaddr = ecardm_iomap(ec, type->type, 0, 0);
	if (!info->vaddr) {
		kfree(info);
		return -ENOMEM;
	}

	ecard_set_drvdata(ec, info);

	memset(&uart, 0, sizeof(struct uart_8250_port));
	uart.port.irq	= ec->irq;
	uart.port.flags	= UPF_BOOT_AUTOCONF | UPF_SHARE_IRQ;
	uart.port.uartclk	= type->uartclk;
	uart.port.iotype	= UPIO_MEM;
	uart.port.regshift	= 2;
	uart.port.dev	= &ec->dev;

	for (i = 0; i < info->num_ports; i++) {
		uart.port.membase = info->vaddr + type->offset[i];
		uart.port.mapbase = bus_addr + type->offset[i];

		info->ports[i] = serial8250_register_8250_port(&uart);
	}

	return 0;
}

__attribute__((used)) static void serial_card_remove(struct expansion_card *ec)
{
	struct serial_card_info *info = ecard_get_drvdata(ec);
	int i;

	ecard_set_drvdata(ec, NULL);

	for (i = 0; i < info->num_ports; i++)
		if (info->ports[i] > 0)
			serial8250_unregister_port(info->ports[i]);

	kfree(info);
}

