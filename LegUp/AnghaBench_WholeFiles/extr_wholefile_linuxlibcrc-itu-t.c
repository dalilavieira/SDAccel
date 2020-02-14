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
typedef  int /*<<< orphan*/  u16 ;

/* Variables and functions */
 int /*<<< orphan*/  crc_itu_t_byte (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

u16 crc_itu_t(u16 crc, const u8 *buffer, size_t len)
{
	while (len--)
		crc = crc_itu_t_byte(crc, *buffer++);
	return crc;
}

