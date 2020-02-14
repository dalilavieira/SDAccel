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
typedef  int /*<<< orphan*/  uint8_t ;
typedef  int /*<<< orphan*/  time_t ;
struct tm {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  IO_RTC ; 
 int /*<<< orphan*/  RTC_HMEM_LSB ; 
 int /*<<< orphan*/  RTC_HMEM_MSB ; 
 int /*<<< orphan*/  RTC_HMEM_SB ; 
 int /*<<< orphan*/  RTC_LMEM_LSB ; 
 int /*<<< orphan*/  RTC_LMEM_MSB ; 
 int /*<<< orphan*/  assert (int) ; 
 int /*<<< orphan*/  dsdt_fixed_ioport (int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  dsdt_fixed_irq (int) ; 
 int /*<<< orphan*/  dsdt_indent (int) ; 
 int /*<<< orphan*/  dsdt_line (char*) ; 
 int /*<<< orphan*/  dsdt_unindent (int) ; 
 int /*<<< orphan*/  localtime_r (int /*<<< orphan*/ *,struct tm*) ; 
 size_t m_16MB ; 
 size_t m_64KB ; 
 int /*<<< orphan*/  time (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  timegm (struct tm*) ; 
 size_t xh_vm_get_highmem_size () ; 
 size_t xh_vm_get_lowmem_size () ; 
 int xh_vm_rtc_settime (int /*<<< orphan*/ ) ; 
 int xh_vm_rtc_write (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

__attribute__((used)) static time_t
rtc_time(int use_localtime)
{
	struct tm tm;
	time_t t;

	time(&t);
	if (use_localtime) {
		localtime_r(&t, &tm);
		t = timegm(&tm);
	}
	return (t);
}

void
rtc_init(int use_localtime)
{	
	size_t himem;
	size_t lomem;
	int err;

	/* XXX init diag/reset code/equipment/checksum ? */

	/*
	 * Report guest memory size in nvram cells as required by UEFI.
	 * Little-endian encoding.
	 * 0x34/0x35 - 64KB chunks above 16MB, below 4GB
	 * 0x5b/0x5c/0x5d - 64KB chunks above 4GB
	 */
	lomem = (xh_vm_get_lowmem_size() - m_16MB) / m_64KB;
	err = xh_vm_rtc_write(RTC_LMEM_LSB, ((uint8_t) lomem));
	assert(err == 0);
	err = xh_vm_rtc_write(RTC_LMEM_MSB, ((uint8_t) (lomem >> 8)));
	assert(err == 0);

	himem = xh_vm_get_highmem_size() / m_64KB;
	err = xh_vm_rtc_write(RTC_HMEM_LSB, ((uint8_t) himem));
	assert(err == 0);
	err = xh_vm_rtc_write(RTC_HMEM_SB, ((uint8_t) (himem >> 8)));
	assert(err == 0);
	err = xh_vm_rtc_write(RTC_HMEM_MSB, ((uint8_t) (himem >> 16)));
	assert(err == 0);

	err = xh_vm_rtc_settime(rtc_time(use_localtime));
	assert(err == 0);
}

__attribute__((used)) static void
rtc_dsdt(void)
{
	dsdt_line("");
	dsdt_line("Device (RTC)");
	dsdt_line("{");
	dsdt_line("  Name (_HID, EisaId (\"PNP0B00\"))");
	dsdt_line("  Name (_CRS, ResourceTemplate ()");
	dsdt_line("  {");
	dsdt_indent(2);
	dsdt_fixed_ioport(IO_RTC, 2);
	dsdt_fixed_irq(8);
	dsdt_unindent(2);
	dsdt_line("  })");
	dsdt_line("}");
}

