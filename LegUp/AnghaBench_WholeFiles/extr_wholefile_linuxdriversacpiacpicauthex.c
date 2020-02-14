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
typedef  int u8 ;
typedef  int u64 ;
typedef  int /*<<< orphan*/  u32 ;
typedef  int /*<<< orphan*/  acpi_status ;

/* Variables and functions */
 int /*<<< orphan*/  AE_BAD_HEX_CONSTANT ; 
 int /*<<< orphan*/  AE_OK ; 
 char* acpi_gbl_hex_to_ascii ; 
 int acpi_ut_ascii_char_to_hex (int) ; 
 int /*<<< orphan*/  acpi_ut_short_shift_right (int,int /*<<< orphan*/ ,int*) ; 
 int /*<<< orphan*/  isxdigit (int) ; 

char acpi_ut_hex_to_ascii_char(u64 integer, u32 position)
{
	u64 index;

	acpi_ut_short_shift_right(integer, position, &index);
	return (acpi_gbl_hex_to_ascii[index & 0xF]);
}

acpi_status acpi_ut_ascii_to_hex_byte(char *two_ascii_chars, u8 *return_byte)
{

	/* Both ASCII characters must be valid hex digits */

	if (!isxdigit((int)two_ascii_chars[0]) ||
	    !isxdigit((int)two_ascii_chars[1])) {
		return (AE_BAD_HEX_CONSTANT);
	}

	*return_byte =
	    acpi_ut_ascii_char_to_hex(two_ascii_chars[1]) |
	    (acpi_ut_ascii_char_to_hex(two_ascii_chars[0]) << 4);

	return (AE_OK);
}

u8 acpi_ut_ascii_char_to_hex(int hex_char)
{

	/* Values 0-9 */

	if (hex_char <= '9') {
		return ((u8)(hex_char - '0'));
	}

	/* Upper case A-F */

	if (hex_char <= 'F') {
		return ((u8)(hex_char - 0x37));
	}

	/* Lower case a-f */

	return ((u8)(hex_char - 0x57));
}

