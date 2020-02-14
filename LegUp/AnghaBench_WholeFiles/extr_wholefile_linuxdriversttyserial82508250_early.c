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
struct uart_port {int regshift; int iotype; unsigned int (* serial_in ) (struct uart_port*,int) ;int /*<<< orphan*/  (* serial_out ) (struct uart_port*,int,int) ;int /*<<< orphan*/  iobase; int /*<<< orphan*/  membase; } ;
struct earlycon_device {struct uart_port port; } ;
struct console {struct earlycon_device* data; } ;

/* Variables and functions */
 unsigned int BOTH_EMPTY ; 
 int UART_LSR ; 
 int UART_TX ; 
#define  UPIO_AU 133 
#define  UPIO_MEM 132 
#define  UPIO_MEM16 131 
#define  UPIO_MEM32 130 
#define  UPIO_MEM32BE 129 
#define  UPIO_PORT 128 
 int /*<<< orphan*/  cpu_relax () ; 
 unsigned int inb (int /*<<< orphan*/ ) ; 
 unsigned int ioread32be (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  iowrite32be (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  outb (int,int /*<<< orphan*/ ) ; 
 unsigned int readb (int /*<<< orphan*/ ) ; 
 unsigned int readl (int /*<<< orphan*/ ) ; 
 unsigned int readw (int /*<<< orphan*/ ) ; 
 unsigned int stub1 (struct uart_port*,int) ; 
 int /*<<< orphan*/  stub2 (struct uart_port*,int,int) ; 
 int /*<<< orphan*/  uart_console_write (struct uart_port*,char const*,unsigned int,void (*) (struct uart_port*,int)) ; 
 int /*<<< orphan*/  writeb (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  writel (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  writew (int,int /*<<< orphan*/ ) ; 

__attribute__((used)) static unsigned int serial8250_early_in(struct uart_port *port, int offset)
{
	int reg_offset = offset;
	offset <<= port->regshift;

	switch (port->iotype) {
	case UPIO_MEM:
		return readb(port->membase + offset);
	case UPIO_MEM16:
		return readw(port->membase + offset);
	case UPIO_MEM32:
		return readl(port->membase + offset);
	case UPIO_MEM32BE:
		return ioread32be(port->membase + offset);
	case UPIO_PORT:
		return inb(port->iobase + offset);
	case UPIO_AU:
		return port->serial_in(port, reg_offset);
	default:
		return 0;
	}
}

__attribute__((used)) static void serial8250_early_out(struct uart_port *port, int offset, int value)
{
	int reg_offset = offset;
	offset <<= port->regshift;

	switch (port->iotype) {
	case UPIO_MEM:
		writeb(value, port->membase + offset);
		break;
	case UPIO_MEM16:
		writew(value, port->membase + offset);
		break;
	case UPIO_MEM32:
		writel(value, port->membase + offset);
		break;
	case UPIO_MEM32BE:
		iowrite32be(value, port->membase + offset);
		break;
	case UPIO_PORT:
		outb(value, port->iobase + offset);
		break;
	case UPIO_AU:
		port->serial_out(port, reg_offset, value);
		break;
	}
}

__attribute__((used)) static void serial_putc(struct uart_port *port, int c)
{
	unsigned int status;

	serial8250_early_out(port, UART_TX, c);

	for (;;) {
		status = serial8250_early_in(port, UART_LSR);
		if ((status & BOTH_EMPTY) == BOTH_EMPTY)
			break;
		cpu_relax();
	}
}

__attribute__((used)) static void early_serial8250_write(struct console *console,
					const char *s, unsigned int count)
{
	struct earlycon_device *device = console->data;
	struct uart_port *port = &device->port;

	uart_console_write(port, s, count, serial_putc);
}

