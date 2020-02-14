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
struct tty_struct {int count; struct tty_port* port; } ;
struct tty_port {int dummy; } ;
struct timer_list {int dummy; } ;
struct seq_file {int dummy; } ;
struct file {int dummy; } ;

/* Variables and functions */
 scalar_t__ SERIAL_TIMER_VALUE ; 
 int /*<<< orphan*/  TTY_NORMAL ; 
 int /*<<< orphan*/  del_timer_sync (int /*<<< orphan*/ *) ; 
 scalar_t__ jiffies ; 
 int /*<<< orphan*/  mod_timer (int /*<<< orphan*/ *,scalar_t__) ; 
static  void rs_poll (struct timer_list*) ; 
 int /*<<< orphan*/  seq_printf (struct seq_file*,char*,int /*<<< orphan*/ ) ; 
 struct tty_port serial_port ; 
 int /*<<< orphan*/  serial_timer ; 
 int /*<<< orphan*/  serial_version ; 
 scalar_t__ simc_poll (int /*<<< orphan*/ ) ; 
 int simc_read (int /*<<< orphan*/ ,unsigned char*,int) ; 
 int /*<<< orphan*/  simc_write (int,unsigned char const*,int) ; 
 int /*<<< orphan*/  spin_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  spin_lock_bh (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  spin_unlock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  spin_unlock_bh (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  timer_lock ; 
 int /*<<< orphan*/  timer_setup (int /*<<< orphan*/ *,void (*) (struct timer_list*),int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  tty_flip_buffer_push (struct tty_port*) ; 
 int /*<<< orphan*/  tty_insert_flip_char (struct tty_port*,unsigned char,int /*<<< orphan*/ ) ; 

__attribute__((used)) static int rs_open(struct tty_struct *tty, struct file * filp)
{
	tty->port = &serial_port;
	spin_lock_bh(&timer_lock);
	if (tty->count == 1) {
		timer_setup(&serial_timer, rs_poll, 0);
		mod_timer(&serial_timer, jiffies + SERIAL_TIMER_VALUE);
	}
	spin_unlock_bh(&timer_lock);

	return 0;
}

__attribute__((used)) static void rs_close(struct tty_struct *tty, struct file * filp)
{
	spin_lock_bh(&timer_lock);
	if (tty->count == 1)
		del_timer_sync(&serial_timer);
	spin_unlock_bh(&timer_lock);
}

__attribute__((used)) static int rs_write(struct tty_struct * tty,
		    const unsigned char *buf, int count)
{
	/* see drivers/char/serialX.c to reference original version */

	simc_write(1, buf, count);
	return count;
}

__attribute__((used)) static void rs_poll(struct timer_list *unused)
{
	struct tty_port *port = &serial_port;
	int i = 0;
	int rd = 1;
	unsigned char c;

	spin_lock(&timer_lock);

	while (simc_poll(0)) {
		rd = simc_read(0, &c, 1);
		if (rd <= 0)
			break;
		tty_insert_flip_char(port, c, TTY_NORMAL);
		i++;
	}

	if (i)
		tty_flip_buffer_push(port);
	if (rd)
		mod_timer(&serial_timer, jiffies + SERIAL_TIMER_VALUE);
	spin_unlock(&timer_lock);
}

__attribute__((used)) static int rs_put_char(struct tty_struct *tty, unsigned char ch)
{
	return rs_write(tty, &ch, 1);
}

__attribute__((used)) static void rs_flush_chars(struct tty_struct *tty)
{
}

__attribute__((used)) static int rs_write_room(struct tty_struct *tty)
{
	/* Let's say iss can always accept 2K characters.. */
	return 2 * 1024;
}

__attribute__((used)) static int rs_chars_in_buffer(struct tty_struct *tty)
{
	/* the iss doesn't buffer characters */
	return 0;
}

__attribute__((used)) static void rs_hangup(struct tty_struct *tty)
{
	/* Stub, once again.. */
}

__attribute__((used)) static void rs_wait_until_sent(struct tty_struct *tty, int timeout)
{
	/* Stub, once again.. */
}

__attribute__((used)) static int rs_proc_show(struct seq_file *m, void *v)
{
	seq_printf(m, "serinfo:1.0 driver:%s\n", serial_version);
	return 0;
}

