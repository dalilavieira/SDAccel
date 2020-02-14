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
typedef  int /*<<< orphan*/  mach_port_t ;
typedef  int /*<<< orphan*/  buffer ;

/* Variables and functions */
 int /*<<< orphan*/  __SIGABRT ; 
 int /*<<< orphan*/  __STDERR_FILENO ; 
 int /*<<< orphan*/  __exit (int) ; 
 int /*<<< orphan*/  __getpid () ; 
 int /*<<< orphan*/  __kill (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int _mach_snprintf (char*,int,char*,char const*) ; 
 int /*<<< orphan*/  host_reboot (int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  master_host_port ; 
 int /*<<< orphan*/  write (int /*<<< orphan*/ ,char*,int) ; 

__attribute__((used)) static inline void __attribute__((noreturn))
abort(void) {
	(void)__kill(__getpid(), __SIGABRT, 0);
	__exit(1);
}

void
panic_init(mach_port_t port)
{
	master_host_port = port;
}

void
panic(const char *s, ...)
{
	char buffer[1024];
	int len = _mach_snprintf(buffer, sizeof(buffer), "panic: %s\n", s);
	write(__STDERR_FILENO, buffer, len);
	
#define RB_DEBUGGER	0x1000	/* enter debugger NOW */
	(void) host_reboot(master_host_port, RB_DEBUGGER);

	/* 4279008 - don't return */
	abort();
}

