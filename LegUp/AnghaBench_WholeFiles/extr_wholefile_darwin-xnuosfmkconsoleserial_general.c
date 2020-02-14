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
typedef  int /*<<< orphan*/  uint64_t ;
typedef  int uint32_t ;
typedef  int /*<<< orphan*/  thread_t ;
typedef  int /*<<< orphan*/  thread_continue_t ;
struct console_printbuf_state {int flags; int total; int pos; int* str; } ;
typedef  scalar_t__ kern_return_t ;
typedef  int /*<<< orphan*/  event_t ;
typedef  int boolean_t ;

/* Variables and functions */
 int CONS_PB_CANBLOCK ; 
 int CONS_PB_WRITE_NEWLINE ; 
 scalar_t__ KERN_SUCCESS ; 
 int /*<<< orphan*/  MAXPRI_KERNEL ; 
 int SERIALMODE_INPUT ; 
 int SERIALMODE_SYNCDRAIN ; 
 int SERIAL_CONS_BUF_SIZE ; 
 int SERIAL_CONS_OPS ; 
 int /*<<< orphan*/  THREAD_UNINT ; 
 int TRUE ; 
 int VC_CONS_OPS ; 
 int _serial_getc (int /*<<< orphan*/ ,int,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  assert_wait_deadline (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  bzero (struct console_printbuf_state*,int) ; 
 int /*<<< orphan*/  clock_interval_to_deadline (int,int,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  cons_cinput (char) ; 
 int cons_ops_index ; 
 int /*<<< orphan*/  console_write (char*,size_t) ; 
 scalar_t__ kernel_thread_start_priority (int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  kprintf (char*) ; 
 int nconsops ; 
 int /*<<< orphan*/  panic (char*) ; 
 int /*<<< orphan*/  printf (char*,int) ; 
 void serial_keyboard_poll () ; 
 void serial_keyboard_start () ; 
 int serialmode ; 
 int /*<<< orphan*/  thread_block (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  thread_deallocate (int /*<<< orphan*/ ) ; 

void
serial_keyboard_init(void)
{
	kern_return_t	result;
	thread_t		thread;

	if(!(serialmode & SERIALMODE_INPUT)) /* Leave if we do not want a serial console */
		return;

	kprintf("Serial keyboard started\n");
	result = kernel_thread_start_priority((thread_continue_t)serial_keyboard_start, NULL, MAXPRI_KERNEL, &thread);
	if (result != KERN_SUCCESS)
		panic("serial_keyboard_init");

	thread_deallocate(thread);
}

void
serial_keyboard_start(void)
{
	/* Go see if there are any characters pending now */
	serial_keyboard_poll();
	panic("serial_keyboard_start: we can't get back here\n");
}

void
serial_keyboard_poll(void)
{
	int chr;
	uint64_t next;

	while(1) {
		chr = _serial_getc(0, 1, 0, 1);	/* Get a character if there is one */
		if(chr < 0) /* The serial buffer is empty */
			break;
		cons_cinput((char)chr);			/* Buffer up the character */
	}

	clock_interval_to_deadline(16, 1000000, &next);	/* Get time of pop */

	assert_wait_deadline((event_t)serial_keyboard_poll, THREAD_UNINT, next);	/* Show we are "waiting" */
	thread_block((thread_continue_t)serial_keyboard_poll);	/* Wait for it */
	panic("serial_keyboard_poll: Shouldn't never ever get here...\n");
}

boolean_t
console_is_serial(void)
{
	return (cons_ops_index == SERIAL_CONS_OPS);
}

int
switch_to_video_console(void)
{
	int old_cons_ops = cons_ops_index;
	cons_ops_index = VC_CONS_OPS;
	return old_cons_ops;
}

int
switch_to_serial_console(void)
{
	int old_cons_ops = cons_ops_index;
	cons_ops_index = SERIAL_CONS_OPS;
	return old_cons_ops;
}

void
switch_to_old_console(int old_console)
{
	static boolean_t squawked;
	uint32_t ops = old_console;

	if ((ops >= nconsops) && !squawked) {
		squawked = TRUE;
		printf("switch_to_old_console: unknown ops %d\n", ops);
	} else
		cons_ops_index = ops;
}

void
console_printbuf_state_init(struct console_printbuf_state * data, int write_on_newline, int can_block)
{
	if (data == NULL)
		return;
	bzero(data, sizeof(struct console_printbuf_state));
	if (write_on_newline)
		data->flags |= CONS_PB_WRITE_NEWLINE;
	if (can_block)
		data->flags |= CONS_PB_CANBLOCK;
}

void
console_printbuf_putc(int ch, void * arg)
{
	struct console_printbuf_state * info = (struct console_printbuf_state *)arg;
	info->total += 1;
	if (info->pos < (SERIAL_CONS_BUF_SIZE - 1)) {
		info->str[info->pos] = ch;
		info->pos += 1;
	} else {
		/*
		 * when len(line) > SERIAL_CONS_BUF_SIZE, we truncate the message
		 * if boot-arg 'drain_uart_sync=1' is set, then
		 * drain all the buffer right now and append new ch
		 */
		if (serialmode & SERIALMODE_SYNCDRAIN) {
			info->str[info->pos] = '\0';
			console_write(info->str, info->pos);
			info->pos            = 0;
			info->str[info->pos] = ch;
			info->pos += 1;
		}
	}

	info->str[info->pos] = '\0';
	/* if newline, then try output to console */
	if (ch == '\n' && info->flags & CONS_PB_WRITE_NEWLINE) {
		console_write(info->str, info->pos);
		info->pos            = 0;
		info->str[info->pos] = '\0';
	}
}

void
console_printbuf_clear(struct console_printbuf_state * info) {
	if (info->pos != 0) {
		console_write(info->str, info->pos);
	}
	info->pos = 0;
	info->str[info->pos] = '\0';
	info->total = 0;
}

