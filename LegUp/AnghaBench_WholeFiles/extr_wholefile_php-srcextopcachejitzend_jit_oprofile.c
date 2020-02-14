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
typedef  scalar_t__ zend_uintptr_t ;
typedef  int /*<<< orphan*/  uint64_t ;

/* Variables and functions */
 int errno ; 
 int /*<<< orphan*/  fprintf (int /*<<< orphan*/ ,char*,int) ; 
 scalar_t__ op_agent ; 
 int /*<<< orphan*/  op_close_agent (scalar_t__) ; 
 scalar_t__ op_open_agent () ; 
 int /*<<< orphan*/  op_write_native_code (scalar_t__,char const*,int /*<<< orphan*/ ,void const*,size_t) ; 
 int /*<<< orphan*/  stderr ; 

__attribute__((used)) static void zend_jit_oprofile_register(const char *name,
                                       const void *start,
                                       size_t      size)
{
	if (op_agent) {
		op_write_native_code(op_agent, name, (uint64_t)(zend_uintptr_t)start, start, size);
	}
}

__attribute__((used)) static int zend_jit_oprofile_startup(void)
{
	op_agent = op_open_agent();
	if (!op_agent) {
		fprintf(stderr, "OpAgent initialization failed [%d]!\n", errno);
		return 0;
	}
	return 1;
}

__attribute__((used)) static void zend_jit_oprofile_shutdown(void)
{
	if (op_agent) {
//???		sleep(60);
		op_close_agent(op_agent);
	}
}

