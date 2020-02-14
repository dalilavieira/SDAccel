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
typedef  int /*<<< orphan*/  u8 ;

/* Variables and functions */
 int /*<<< orphan*/  crc7_be_byte (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

u8 crc7_be(u8 crc, const u8 *buffer, size_t len)
{
	while (len--)
		crc = crc7_be_byte(crc, *buffer++);
	return crc;
}

