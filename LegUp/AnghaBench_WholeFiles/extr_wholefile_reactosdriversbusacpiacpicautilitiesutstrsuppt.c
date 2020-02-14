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
typedef  int /*<<< orphan*/  UINT8 ;
typedef  scalar_t__ UINT64 ;
typedef  scalar_t__ UINT32 ;
typedef  int /*<<< orphan*/  BOOLEAN ;
typedef  int /*<<< orphan*/  ACPI_STATUS ;

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
 int AcpiGbl_IntegerBitWidth ; 
 scalar_t__ AcpiUtAsciiCharToHex (int) ; 
static  int /*<<< orphan*/  AcpiUtInsertDigit (scalar_t__*,scalar_t__,int) ; 
 void AcpiUtRemoveHexPrefix (char**) ; 
 int /*<<< orphan*/  AcpiUtShortDivide (scalar_t__,scalar_t__,scalar_t__*,int /*<<< orphan*/ *) ; 
static  int /*<<< orphan*/  AcpiUtStrtoulAdd64 (scalar_t__,scalar_t__,scalar_t__*) ; 
static  int /*<<< orphan*/  AcpiUtStrtoulMultiply64 (scalar_t__,scalar_t__,scalar_t__*) ; 
 int /*<<< orphan*/  FALSE ; 
 int /*<<< orphan*/  TRUE ; 
 int /*<<< orphan*/  isdigit (char) ; 
 scalar_t__ isspace (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  isxdigit (char) ; 
 char tolower (int) ; 

ACPI_STATUS
AcpiUtConvertOctalString (
    char                    *String,
    UINT64                  *ReturnValuePtr)
{
    UINT64                  AccumulatedValue = 0;
    ACPI_STATUS             Status = AE_OK;


    /* Convert each ASCII byte in the input string */

    while (*String)
    {
        /* Character must be ASCII 0-7, otherwise terminate with no error */

        if (!(ACPI_IS_OCTAL_DIGIT (*String)))
        {
            break;
        }

        /* Convert and insert this octal digit into the accumulator */

        Status = AcpiUtInsertDigit (&AccumulatedValue, 8, *String);
        if (ACPI_FAILURE (Status))
        {
            Status = AE_OCTAL_OVERFLOW;
            break;
        }

        String++;
    }

    /* Always return the value that has been accumulated */

    *ReturnValuePtr = AccumulatedValue;
    return (Status);
}

ACPI_STATUS
AcpiUtConvertDecimalString (
    char                    *String,
    UINT64                  *ReturnValuePtr)
{
    UINT64                  AccumulatedValue = 0;
    ACPI_STATUS             Status = AE_OK;


    /* Convert each ASCII byte in the input string */

    while (*String)
    {
        /* Character must be ASCII 0-9, otherwise terminate with no error */

        if (!isdigit (*String))
        {
           break;
        }

        /* Convert and insert this decimal digit into the accumulator */

        Status = AcpiUtInsertDigit (&AccumulatedValue, 10, *String);
        if (ACPI_FAILURE (Status))
        {
            Status = AE_DECIMAL_OVERFLOW;
            break;
        }

        String++;
    }

    /* Always return the value that has been accumulated */

    *ReturnValuePtr = AccumulatedValue;
    return (Status);
}

ACPI_STATUS
AcpiUtConvertHexString (
    char                    *String,
    UINT64                  *ReturnValuePtr)
{
    UINT64                  AccumulatedValue = 0;
    ACPI_STATUS             Status = AE_OK;


    /* Convert each ASCII byte in the input string */

    while (*String)
    {
        /* Must be ASCII A-F, a-f, or 0-9, otherwise terminate with no error */

        if (!isxdigit (*String))
        {
            break;
        }

        /* Convert and insert this hex digit into the accumulator */

        Status = AcpiUtInsertDigit (&AccumulatedValue, 16, *String);
        if (ACPI_FAILURE (Status))
        {
            Status = AE_HEX_OVERFLOW;
            break;
        }

        String++;
    }

    /* Always return the value that has been accumulated */

    *ReturnValuePtr = AccumulatedValue;
    return (Status);
}

char
AcpiUtRemoveLeadingZeros (
    char                    **String)
{

    while (**String == ACPI_ASCII_ZERO)
    {
        *String += 1;
    }

    return (**String);
}

char
AcpiUtRemoveWhitespace (
    char                    **String)
{

    while (isspace ((UINT8) **String))
    {
        *String += 1;
    }

    return (**String);
}

BOOLEAN
AcpiUtDetectHexPrefix (
    char                    **String)
{
    char                    *InitialPosition = *String;

    AcpiUtRemoveHexPrefix (String);
    if (*String != InitialPosition)
    {
        return (TRUE); /* String is past leading 0x */
    }

    return (FALSE);     /* Not a hex string */
}

void
AcpiUtRemoveHexPrefix (
    char                    **String)
{
    if ((**String == ACPI_ASCII_ZERO) &&
        (tolower ((int) *(*String + 1)) == 'x'))
    {
        *String += 2;        /* Go past the leading 0x */
    }
}

BOOLEAN
AcpiUtDetectOctalPrefix (
    char                    **String)
{

    if (**String == ACPI_ASCII_ZERO)
    {
        *String += 1;       /* Go past the leading 0 */
        return (TRUE);
    }

    return (FALSE);     /* Not an octal string */
}

__attribute__((used)) static ACPI_STATUS
AcpiUtInsertDigit (
    UINT64                  *AccumulatedValue,
    UINT32                  Base,
    int                     AsciiDigit)
{
    ACPI_STATUS             Status;
    UINT64                  Product;


     /* Make room in the accumulated value for the incoming digit */

    Status = AcpiUtStrtoulMultiply64 (*AccumulatedValue, Base, &Product);
    if (ACPI_FAILURE (Status))
    {
        return (Status);
    }

    /* Add in the new digit, and store the sum to the accumulated value */

    Status = AcpiUtStrtoulAdd64 (Product, AcpiUtAsciiCharToHex (AsciiDigit),
        AccumulatedValue);

    return (Status);
}

__attribute__((used)) static ACPI_STATUS
AcpiUtStrtoulMultiply64 (
    UINT64                  Multiplicand,
    UINT32                  Base,
    UINT64                  *OutProduct)
{
    UINT64                  Product;
    UINT64                  Quotient;


    /* Exit if either operand is zero */

    *OutProduct = 0;
    if (!Multiplicand || !Base)
    {
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
    AcpiUtShortDivide (ACPI_UINT64_MAX, Base, &Quotient, NULL);
    if (Multiplicand > Quotient)
    {
        return (AE_NUMERIC_OVERFLOW);
    }

    Product = Multiplicand * Base;

    /* Check for 32-bit overflow if necessary */

    if ((AcpiGbl_IntegerBitWidth == 32) && (Product > ACPI_UINT32_MAX))
    {
        return (AE_NUMERIC_OVERFLOW);
    }

    *OutProduct = Product;
    return (AE_OK);
}

__attribute__((used)) static ACPI_STATUS
AcpiUtStrtoulAdd64 (
    UINT64                  Addend1,
    UINT32                  Digit,
    UINT64                  *OutSum)
{
    UINT64                  Sum;


    /* Check for 64-bit overflow before the actual addition */

    if ((Addend1 > 0) && (Digit > (ACPI_UINT64_MAX - Addend1)))
    {
        return (AE_NUMERIC_OVERFLOW);
    }

    Sum = Addend1 + Digit;

    /* Check for 32-bit overflow if necessary */

    if ((AcpiGbl_IntegerBitWidth == 32) && (Sum > ACPI_UINT32_MAX))
    {
        return (AE_NUMERIC_OVERFLOW);
    }

    *OutSum = Sum;
    return (AE_OK);
}

