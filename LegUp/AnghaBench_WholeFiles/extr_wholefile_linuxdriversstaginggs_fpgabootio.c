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
typedef  int int32_t ;
typedef  enum wbus { ____Placeholder_wbus } wbus ;

/* Variables and functions */
#define  bus_1byte 129 
#define  bus_2byte 128 
static  void byte0_out (unsigned char) ; 
static  void byte1_out (unsigned char) ; 
 scalar_t__ likely (int) ; 
 int /*<<< orphan*/  pr_err (char*,int) ; 
static  void xl_cclk_b (int) ; 

void xl_shift_cclk(int count)
{
	int i;

	for (i = 0; i < count; i++) {
		xl_cclk_b(1);
		xl_cclk_b(0);
	}
}

int xl_supported_prog_bus_width(enum wbus bus_bytes)
{
	switch (bus_bytes) {
	case bus_1byte:
		break;
	case bus_2byte:
		break;
	default:
		pr_err("unsupported program bus width %d\n",
				bus_bytes);
		return 0;
	}

	return 1;
}

void xl_shift_bytes_out(enum wbus bus_byte, unsigned char *pdata)
{
	/*
	 * supports 1 and 2 bytes programming mode
	 */
	if (likely(bus_byte == bus_2byte))
		byte0_out(pdata[0]);

	byte1_out(pdata[1]);
	xl_shift_cclk(1);
}

void xl_program_b(int32_t i)
{
}

void xl_rdwr_b(int32_t i)
{
}

void xl_csi_b(int32_t i)
{
}

int xl_get_init_b(void)
{
	return -1;
}

int xl_get_done_b(void)
{
	return -1;
}

__attribute__((used)) static inline void byte0_out(unsigned char data)
{
}

__attribute__((used)) static inline void byte1_out(unsigned char data)
{
}

__attribute__((used)) static inline void xl_cclk_b(int32_t i)
{
}

int xl_init_io(void)
{
	return -1;
}

