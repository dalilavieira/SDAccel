#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_2__ ;
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
struct uart_driver {int minor; int nr; struct console* cons; TYPE_1__* tty_driver; } ;
struct device_node {int /*<<< orphan*/  name; } ;
struct console {int index; int cflag; int /*<<< orphan*/  name; } ;
struct TYPE_4__ {int baud; unsigned int cflag; } ;
struct TYPE_3__ {int name_base; } ;

/* Variables and functions */
 int B115200 ; 
 int B1200 ; 
 int B150 ; 
 int B19200 ; 
 int B230400 ; 
 int B2400 ; 
 int B300 ; 
 int B38400 ; 
 int B460800 ; 
 int B4800 ; 
 int B57600 ; 
 int B600 ; 
 int B9600 ; 
 unsigned int CBAUD ; 
 int CLOCAL ; 
 int CREAD ; 
 int CS5 ; 
 int CS6 ; 
 int CS7 ; 
 int CS8 ; 
 int CSTOPB ; 
 int HUPCL ; 
 int PARENB ; 
 int PARODD ; 
 int /*<<< orphan*/  add_preferred_console (int /*<<< orphan*/ ,int,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  console_set_on_cmdline ; 
 TYPE_2__* mouse_baud_table ; 
 struct device_node* of_console_device ; 
 char* of_console_options ; 
 struct device_node* of_find_node_by_path (char*) ; 
 char* of_get_property (struct device_node*,char*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  of_node_put (struct device_node*) ; 
 int simple_strtoul (char const*,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 char* strchr (char const*,char) ; 
 int /*<<< orphan*/  strcmp (int /*<<< orphan*/ ,char*) ; 
 int sunserial_current_minor ; 
 int uart_register_driver (struct uart_driver*) ; 
 int /*<<< orphan*/  uart_unregister_driver (struct uart_driver*) ; 

int sunserial_register_minors(struct uart_driver *drv, int count)
{
	int err = 0;

	drv->minor = sunserial_current_minor;
	drv->nr += count;
	/* Register the driver on the first call */
	if (drv->nr == count)
		err = uart_register_driver(drv);
	if (err == 0) {
		sunserial_current_minor += count;
		drv->tty_driver->name_base = drv->minor - 64;
	}
	return err;
}

void sunserial_unregister_minors(struct uart_driver *drv, int count)
{
	drv->nr -= count;
	sunserial_current_minor -= count;

	if (drv->nr == 0)
		uart_unregister_driver(drv);
}

int sunserial_console_match(struct console *con, struct device_node *dp,
			    struct uart_driver *drv, int line, bool ignore_line)
{
	if (!con)
		return 0;

	drv->cons = con;

	if (of_console_device != dp)
		return 0;

	if (!ignore_line) {
		int off = 0;

		if (of_console_options &&
		    *of_console_options == 'b')
			off = 1;

		if ((line & 1) != off)
			return 0;
	}

	if (!console_set_on_cmdline) {
		con->index = line;
		add_preferred_console(con->name, line, NULL);
	}
	return 1;
}

void sunserial_console_termios(struct console *con, struct device_node *uart_dp)
{
	const char *mode, *s;
	char mode_prop[] = "ttyX-mode";
	int baud, bits, stop, cflag;
	char parity;

	if (!strcmp(uart_dp->name, "rsc") ||
	    !strcmp(uart_dp->name, "rsc-console") ||
	    !strcmp(uart_dp->name, "rsc-control")) {
		mode = of_get_property(uart_dp,
				       "ssp-console-modes", NULL);
		if (!mode)
			mode = "115200,8,n,1,-";
	} else if (!strcmp(uart_dp->name, "lom-console")) {
		mode = "9600,8,n,1,-";
	} else {
		struct device_node *dp;
		char c;

		c = 'a';
		if (of_console_options)
			c = *of_console_options;

		mode_prop[3] = c;

		dp = of_find_node_by_path("/options");
		mode = of_get_property(dp, mode_prop, NULL);
		if (!mode)
			mode = "9600,8,n,1,-";
		of_node_put(dp);
	}

	cflag = CREAD | HUPCL | CLOCAL;

	s = mode;
	baud = simple_strtoul(s, NULL, 0);
	s = strchr(s, ',');
	bits = simple_strtoul(++s, NULL, 0);
	s = strchr(s, ',');
	parity = *(++s);
	s = strchr(s, ',');
	stop = simple_strtoul(++s, NULL, 0);
	s = strchr(s, ',');
	/* XXX handshake is not handled here. */

	switch (baud) {
		case 150: cflag |= B150; break;
		case 300: cflag |= B300; break;
		case 600: cflag |= B600; break;
		case 1200: cflag |= B1200; break;
		case 2400: cflag |= B2400; break;
		case 4800: cflag |= B4800; break;
		case 9600: cflag |= B9600; break;
		case 19200: cflag |= B19200; break;
		case 38400: cflag |= B38400; break;
		case 57600: cflag |= B57600; break;
		case 115200: cflag |= B115200; break;
		case 230400: cflag |= B230400; break;
		case 460800: cflag |= B460800; break;
		default: baud = 9600; cflag |= B9600; break;
	}

	switch (bits) {
		case 5: cflag |= CS5; break;
		case 6: cflag |= CS6; break;
		case 7: cflag |= CS7; break;
		case 8: cflag |= CS8; break;
		default: cflag |= CS8; break;
	}

	switch (parity) {
		case 'o': cflag |= (PARENB | PARODD); break;
		case 'e': cflag |= PARENB; break;
		case 'n': default: break;
	}

	switch (stop) {
		case 2: cflag |= CSTOPB; break;
		case 1: default: break;
	}

	con->cflag = cflag;
}

unsigned int suncore_mouse_baud_cflag_next(unsigned int cflag, int *new_baud)
{
	int i;

	for (i = 0; mouse_baud_table[i].baud != -1; i++)
		if (mouse_baud_table[i].cflag == (cflag & CBAUD))
			break;

	i += 1;
	if (mouse_baud_table[i].baud == -1)
		i = 0;

	*new_baud = mouse_baud_table[i].baud;
	return mouse_baud_table[i].cflag;
}

int suncore_mouse_baud_detection(unsigned char ch, int is_break)
{
	static int mouse_got_break = 0;
	static int ctr = 0;

	if (is_break) {
		/* Let a few normal bytes go by before we jump the gun
		 * and say we need to try another baud rate.
		 */
		if (mouse_got_break && ctr < 8)
			return 1;

		/* Ok, we need to try another baud. */
		ctr = 0;
		mouse_got_break = 1;
		return 2;
	}
	if (mouse_got_break) {
		ctr++;
		if (ch == 0x87) {
			/* Correct baud rate determined. */
			mouse_got_break = 0;
		}
		return 1;
	}
	return 0;
}

