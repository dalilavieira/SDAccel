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
typedef  size_t u8 ;
struct TYPE_4__ {unsigned int buffer_addr; int start; int end; int /*<<< orphan*/  num_bytes; } ;
struct TYPE_3__ {unsigned int buffer_addr; int num_chars; int /*<<< orphan*/  end; int /*<<< orphan*/  start; } ;
struct biosmemcon_ebda {scalar_t__ signature; TYPE_2__ v2; TYPE_1__ v1; } ;
typedef  int /*<<< orphan*/  ssize_t ;
typedef  int /*<<< orphan*/  loff_t ;

/* Variables and functions */
 scalar_t__ BIOS_MEMCONSOLE_V1_MAGIC ; 
 scalar_t__ BIOS_MEMCONSOLE_V2_MAGIC ; 
 unsigned int get_bios_ebda () ; 
 void* memconsole_baseaddr ; 
 int memconsole_length ; 
 int /*<<< orphan*/  memconsole_setup (int /*<<< orphan*/  (*) (char*,int /*<<< orphan*/ ,size_t)) ; 
 int /*<<< orphan*/  memory_read_from_buffer (char*,size_t,int /*<<< orphan*/ *,void*,int) ; 
 void* phys_to_virt (unsigned int) ; 
 int /*<<< orphan*/  pr_info (char*,...) ; 

__attribute__((used)) static ssize_t memconsole_read(char *buf, loff_t pos, size_t count)
{
	return memory_read_from_buffer(buf, count, &pos, memconsole_baseaddr,
				       memconsole_length);
}

__attribute__((used)) static void found_v1_header(struct biosmemcon_ebda *hdr)
{
	pr_info("memconsole: BIOS console v1 EBDA structure found at %p\n",
		hdr);
	pr_info("memconsole: BIOS console buffer at 0x%.8x, start = %d, end = %d, num = %d\n",
		hdr->v1.buffer_addr, hdr->v1.start,
		hdr->v1.end, hdr->v1.num_chars);

	memconsole_baseaddr = phys_to_virt(hdr->v1.buffer_addr);
	memconsole_length = hdr->v1.num_chars;
	memconsole_setup(memconsole_read);
}

__attribute__((used)) static void found_v2_header(struct biosmemcon_ebda *hdr)
{
	pr_info("memconsole: BIOS console v2 EBDA structure found at %p\n",
		hdr);
	pr_info("memconsole: BIOS console buffer at 0x%.8x, start = %d, end = %d, num_bytes = %d\n",
		hdr->v2.buffer_addr, hdr->v2.start,
		hdr->v2.end, hdr->v2.num_bytes);

	memconsole_baseaddr = phys_to_virt(hdr->v2.buffer_addr + hdr->v2.start);
	memconsole_length = hdr->v2.end - hdr->v2.start;
	memconsole_setup(memconsole_read);
}

__attribute__((used)) static bool memconsole_ebda_init(void)
{
	unsigned int address;
	size_t length, cur;

	address = get_bios_ebda();
	if (!address) {
		pr_info("memconsole: BIOS EBDA non-existent.\n");
		return false;
	}

	/* EBDA length is byte 0 of EBDA (in KB) */
	length = *(u8 *)phys_to_virt(address);
	length <<= 10; /* convert to bytes */

	/*
	 * Search through EBDA for BIOS memory console structure
	 * note: signature is not necessarily dword-aligned
	 */
	for (cur = 0; cur < length; cur++) {
		struct biosmemcon_ebda *hdr = phys_to_virt(address + cur);

		/* memconsole v1 */
		if (hdr->signature == BIOS_MEMCONSOLE_V1_MAGIC) {
			found_v1_header(hdr);
			return true;
		}

		/* memconsole v2 */
		if (hdr->signature == BIOS_MEMCONSOLE_V2_MAGIC) {
			found_v2_header(hdr);
			return true;
		}
	}

	pr_info("memconsole: BIOS console EBDA structure not found!\n");
	return false;
}

