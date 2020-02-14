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
typedef  scalar_t__ u64 ;
typedef  scalar_t__ u32 ;
typedef  int /*<<< orphan*/  acpi_status ;

/* Variables and functions */
 char ACPI_ASCII_ZERO ; 
 scalar_t__ ACPI_FAILURE (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ACPI_IS_OCTAL_DIGIT (char) ; 
 scalar_t__ ACPI_UINT32_MAX ; 
 scalar_t__ ACPI_UINT64_MAX ; 
 int /*<<< orphan*/  AE_DECIMAL_OVERFLOW ; 
 int /*<<< orphan*/  AE_HEX_OVERFLOW ; 
 int /*<<< orphan*/  AE_NUMERIC_OVERFLOW ; 
 int /*<<< orphan*/  AE_OCTAL_OVERFLOW ; 
 int /*<<< orphan*/  AE_OK ; 
 int /*<<< orphan*/  FALSE ; 
 int /*<<< orphan*/  TRUE ; 
 int acpi_gbl_integer_bit_width ; 
 scalar_t__ acpi_ut_ascii_char_to_hex (int) ; 
static  int /*<<< orphan*/  acpi_ut_insert_digit (scalar_t__*,scalar_t__,int) ; 
 void acpi_ut_remove_hex_prefix (char**) ; 
 int /*<<< orphan*/  acpi_ut_short_divide (scalar_t__,scalar_t__,scalar_t__*,int /*<<< orphan*/ *) ; 
static  int /*<<< orphan*/  acpi_ut_strtoul_add64 (scalar_t__,scalar_t__,scalar_t__*) ; 
static  int /*<<< orphan*/  acpi_ut_strtoul_multiply64 (scalar_t__,scalar_t__,scalar_t__*) ; 
 int /*<<< orphan*/  isdigit (char) ; 
 scalar_t__ isspace (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  isxdigit (char) ; 
 char tolower (int) ; 

acpi_status acpi_ut_convert_octal_string(char *string, u64 *return_value_ptr)
{
	u64 accumulated_value = 0;
	acpi_status status = AE_OK;

	/* Convert each ASCII byte in the input string */

	while (*string) {

		/* Character must be ASCII 0-7, otherwise terminate with no error */

		if (!(ACPI_IS_OCTAL_DIGIT(*string))) {
			break;
		}

		/* Convert and insert this octal digit into the accumulator */

		status = acpi_ut_insert_digit(&accumulated_value, 8, *string);
		if (ACPI_FAILURE(status)) {
			status = AE_OCTAL_OVERFLOW;
			break;
		}

		string++;
	}

	/* Always return the value that has been accumulated */

	*return_value_ptr = accumulated_value;
	return (status);
}

acpi_status acpi_ut_convert_decimal_string(char *string, u64 *return_value_ptr)
{
	u64 accumulated_value = 0;
	acpi_status status = AE_OK;

	/* Convert each ASCII byte in the input string */

	while (*string) {

		/* Character must be ASCII 0-9, otherwise terminate with no error */

		if (!isdigit(*string)) {
			break;
		}

		/* Convert and insert this decimal digit into the accumulator */

		status = acpi_ut_insert_digit(&accumulated_value, 10, *string);
		if (ACPI_FAILURE(status)) {
			status = AE_DECIMAL_OVERFLOW;
			break;
		}

		string++;
	}

	/* Always return the value that has been accumulated */

	*return_value_ptr = accumulated_value;
	return (status);
}

acpi_status acpi_ut_convert_hex_string(char *string, u64 *return_value_ptr)
{
	u64 accumulated_value = 0;
	acpi_status status = AE_OK;

	/* Convert each ASCII byte in the input string */

	while (*string) {

		/* Must be ASCII A-F, a-f, or 0-9, otherwise terminate with no error */

		if (!isxdigit(*string)) {
			break;
		}

		/* Convert and insert this hex digit into the accumulator */

		status = acpi_ut_insert_digit(&accumulated_value, 16, *string);
		if (ACPI_FAILURE(status)) {
			status = AE_HEX_OVERFLOW;
			break;
		}

		string++;
	}

	/* Always return the value that has been accumulated */

	*return_value_ptr = accumulated_value;
	return (status);
}

char acpi_ut_remove_leading_zeros(char **string)
{

	while (**string == ACPI_ASCII_ZERO) {
		*string += 1;
	}

	return (**string);
}

char acpi_ut_remove_whitespace(char **string)
{

	while (isspace((u8)**string)) {
		*string += 1;
	}

	return (**string);
}

u8 acpi_ut_detect_hex_prefix(char **string)
{
	char *initial_position = *string;

	acpi_ut_remove_hex_prefix(string);
	if (*string != initial_position) {
		return (TRUE);	/* String is past leading 0x */
	}

	return (FALSE);		/* Not a hex string */
}

void acpi_ut_remove_hex_prefix(char **string)
{
	if ((**string == ACPI_ASCII_ZERO) &&
	    (tolower((int)*(*string + 1)) == 'x')) {
		*string += 2;	/* Go past the leading 0x */
	}
}

u8 acpi_ut_detect_octal_prefix(char **string)
{

	if (**string == ACPI_ASCII_ZERO) {
		*string += 1;	/* Go past the leading 0 */
		return (TRUE);
	}

	return (FALSE);		/* Not an octal string */
}

__attribute__((used)) static acpi_status
acpi_ut_insert_digit(u64 *accumulated_value, u32 base, int ascii_digit)
{
	acpi_status status;
	u64 product;

	/* Make room in the accumulated value for the incoming digit */

	status = acpi_ut_strtoul_multiply64(*accumulated_value, base, &product);
	if (ACPI_FAILURE(status)) {
		return (status);
	}

	/* Add in the new digit, and store the sum to the accumulated value */

	status =
	    acpi_ut_strtoul_add64(product,
				  acpi_ut_ascii_char_to_hex(ascii_digit),
				  accumulated_value);

	return (status);
}

__attribute__((used)) static acpi_status
acpi_ut_strtoul_multiply64(u64 multiplicand, u32 base, u64 *out_product)
{
	u64 product;
	u64 quotient;

	/* Exit if either operand is zero */

	*out_product = 0;
	if (!multiplicand || !base) {
		return (AE_OK);
	}

	/*
	 * Check for 64-bit overflow before the actual multiplication.
	 *
	 * Notes: 64-bit division is often not supported on 32-bit platforms
	 * (it requires a library function), Therefore ACPICA has a local
	 * 64-bit divide function. Also, Multiplier is currently only used
	 * as the radix (8/10/16), to the 64/32 divide will always work.
	 */
	acpi_ut_short_divide(ACPI_UINT64_MAX, base, &quotient, NULL);
	if (multiplicand > quotient) {
		return (AE_NUMERIC_OVERFLOW);
	}

	product = multiplicand * base;

	/* Check for 32-bit overflow if necessary */

	if ((acpi_gbl_integer_bit_width == 32) && (product > ACPI_UINT32_MAX)) {
		return (AE_NUMERIC_OVERFLOW);
	}

	*out_product = product;
	return (AE_OK);
}

__attribute__((used)) static acpi_status acpi_ut_strtoul_add64(u64 addend1, u32 digit, u64 *out_sum)
{
	u64 sum;

	/* Check for 64-bit overflow before the actual addition */

	if ((addend1 > 0) && (digit > (ACPI_UINT64_MAX - addend1))) {
		return (AE_NUMERIC_OVERFLOW);
	}

	sum = addend1 + digit;

	/* Check for 32-bit overflow if necessary */

	if ((acpi_gbl_integer_bit_width == 32) && (sum > ACPI_UINT32_MAX)) {
		return (AE_NUMERIC_OVERFLOW);
	}

	*out_sum = sum;
	return (AE_OK);
}

