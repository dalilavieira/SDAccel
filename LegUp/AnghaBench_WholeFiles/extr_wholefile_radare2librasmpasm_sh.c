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
struct disassemble_info {int dummy; } ;
typedef  int /*<<< orphan*/  bfd_vma ;
typedef  int /*<<< orphan*/  bfd_byte ;

/* Variables and functions */
 int /*<<< orphan*/  bytes ; 
 int /*<<< orphan*/  memcpy (int /*<<< orphan*/ *,int /*<<< orphan*/ ,unsigned int) ; 

__attribute__((used)) static int sh_buffer_read_memory (bfd_vma memaddr, bfd_byte *myaddr, unsigned int length, struct disassemble_info *info) {
	//this is obviously wrong. but how can we read arbitrary data @ memaddr from here?
	memcpy (myaddr, bytes, length);
	return 0;
}

__attribute__((used)) static int symbol_at_address(bfd_vma addr, struct disassemble_info * info) {
	return 0;
}

__attribute__((used)) static void memory_error_func(int status, bfd_vma memaddr, struct disassemble_info *info) {
	//--
}

