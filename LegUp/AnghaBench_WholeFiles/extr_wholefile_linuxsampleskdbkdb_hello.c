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

/* Variables and functions */
 int KDB_ARGCOUNT ; 
 int /*<<< orphan*/  kdb_printf (char*,...) ; 

__attribute__((used)) static int kdb_hello_cmd(int argc, const char **argv)
{
	if (argc > 1)
		return KDB_ARGCOUNT;

	if (argc)
		kdb_printf("Hello %s.\n", argv[1]);
	else
		kdb_printf("Hello world!\n");

	return 0;
}

