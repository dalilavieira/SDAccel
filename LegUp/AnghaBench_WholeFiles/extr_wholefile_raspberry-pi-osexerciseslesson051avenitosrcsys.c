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
 int copy_process (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,unsigned long) ; 
 int /*<<< orphan*/  exit_process () ; 
 unsigned long get_free_page () ; 
 int /*<<< orphan*/  printf (char*) ; 

void sys_write(char * buf){
	printf(buf);
}

int sys_clone(unsigned long stack){
	return copy_process(0, 0, 0, stack);
}

unsigned long sys_malloc(){
	unsigned long addr = get_free_page();
	if (!addr) {
		return -1;
	}
	return addr;
}

void sys_exit(){
	exit_process();
}

