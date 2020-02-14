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
typedef  int /*<<< orphan*/  mach_port_name_t ;
typedef  int /*<<< orphan*/  mach_port_mscount_t ;
typedef  int /*<<< orphan*/  ipc_port_t ;

/* Variables and functions */
 int /*<<< orphan*/  FALSE ; 
 int /*<<< orphan*/  IPC_PORT_ADJUST_SR_NONE ; 
 int /*<<< orphan*/  ipc_port_adjust_special_reply_port (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mach_notify_dead_name (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mach_notify_no_senders (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mach_notify_port_deleted (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mach_notify_port_destroyed (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mach_notify_send_once (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mach_notify_send_possible (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

void
ipc_notify_port_deleted(
	ipc_port_t		port,
	mach_port_name_t	name)
{
	(void)mach_notify_port_deleted(port, name);
	/* send-once right consumed */
}

void
ipc_notify_send_possible(
	ipc_port_t		port,
	mach_port_name_t	name)
{
	(void)mach_notify_send_possible(port, name);
	/* send-once right consumed */
}

void
ipc_notify_port_destroyed(
	ipc_port_t	port,
	ipc_port_t	right)
{
	mach_notify_port_destroyed(port, right);
	/* send-once and receive rights consumed */
}

void
ipc_notify_no_senders(
	ipc_port_t		port,
	mach_port_mscount_t	mscount)
{
	(void)mach_notify_no_senders(port, mscount);
	/* send-once right consumed */
}

void
ipc_notify_send_once(
	ipc_port_t	port)
{
	ipc_port_adjust_special_reply_port(port, IPC_PORT_ADJUST_SR_NONE, FALSE);

	(void)mach_notify_send_once(port);
	/* send-once right consumed */
}

void
ipc_notify_dead_name(
	ipc_port_t		port,
	mach_port_name_t	name)
{
	(void)mach_notify_dead_name(port, name);
	/* send-once right consumed */
}

