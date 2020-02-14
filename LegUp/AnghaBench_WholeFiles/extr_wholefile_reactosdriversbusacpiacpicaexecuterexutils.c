#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_8__   TYPE_3__ ;
typedef  struct TYPE_7__   TYPE_2__ ;
typedef  struct TYPE_6__   TYPE_1__ ;

/* Type definitions */
typedef  scalar_t__ UINT8 ;
typedef  scalar_t__ UINT64 ;
typedef  int UINT32 ;
struct TYPE_7__ {scalar_t__ Value; } ;
struct TYPE_6__ {scalar_t__ Type; } ;
struct TYPE_8__ {TYPE_2__ Integer; TYPE_1__ Common; } ;
typedef  int /*<<< orphan*/  BOOLEAN ;
typedef  int /*<<< orphan*/  ACPI_STATUS ;
typedef  TYPE_3__ ACPI_OPERAND_OBJECT ;

/* Variables and functions */
 scalar_t__ ACPI_ADR_SPACE_DATA_TABLE ; 
 scalar_t__ ACPI_ADR_SPACE_FIXED_HARDWARE ; 
 scalar_t__ ACPI_DESC_TYPE_OPERAND ; 
 int /*<<< orphan*/  ACPI_ERROR (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ACPI_EXCEPTION (int /*<<< orphan*/ ) ; 
 scalar_t__ ACPI_FAILURE (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ACPI_FORMAT_UINT64 (scalar_t__) ; 
 int /*<<< orphan*/  ACPI_FUNCTION_ENTRY () ; 
 int /*<<< orphan*/  ACPI_FUNCTION_TRACE (int /*<<< orphan*/ ) ; 
 scalar_t__ ACPI_GET_DESCRIPTOR_TYPE (TYPE_3__*) ; 
 int /*<<< orphan*/  ACPI_MTX_INTERPRETER ; 
 int /*<<< orphan*/  ACPI_MTX_NAMESPACE ; 
 scalar_t__ ACPI_NUM_PREDEFINED_REGIONS ; 
 scalar_t__ ACPI_TYPE_INTEGER ; 
 scalar_t__ ACPI_UINT32_MAX ; 
 scalar_t__ ACPI_USER_REGION_BEGIN ; 
 int /*<<< orphan*/  ACPI_WAIT_FOREVER ; 
 int /*<<< orphan*/  ACPI_WARNING (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  AE_INFO ; 
 int AML_FIELD_LOCK_RULE_MASK ; 
 int /*<<< orphan*/  AcpiExAcquireMutexObject (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  AcpiExReleaseMutexObject (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  AcpiGbl_GlobalLockMutex ; 
 int AcpiGbl_IntegerByteWidth ; 
 int /*<<< orphan*/  AcpiOsGetThreadId () ; 
 int /*<<< orphan*/  AcpiUtAcquireMutex (int /*<<< orphan*/ ) ; 
 int AcpiUtDwordByteSwap (int) ; 
 char AcpiUtHexToAsciiChar (scalar_t__,int) ; 
 int /*<<< orphan*/  AcpiUtReleaseMutex (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  AcpiUtShortDivide (scalar_t__,int,scalar_t__*,int*) ; 
 int /*<<< orphan*/  ExAcquireGlobalLock ; 
 int /*<<< orphan*/  ExDigitsNeeded ; 
 int /*<<< orphan*/  ExEnterInterpreter ; 
 int /*<<< orphan*/  ExExitInterpreter ; 
 int /*<<< orphan*/  ExReleaseGlobalLock ; 
 int /*<<< orphan*/  FALSE ; 
 int /*<<< orphan*/  TRUE ; 
 int /*<<< orphan*/  return_UINT32 (int) ; 
 int /*<<< orphan*/  return_VOID ; 

void
AcpiExEnterInterpreter (
    void)
{
    ACPI_STATUS             Status;


    ACPI_FUNCTION_TRACE (ExEnterInterpreter);


    Status = AcpiUtAcquireMutex (ACPI_MTX_INTERPRETER);
    if (ACPI_FAILURE (Status))
    {
        ACPI_ERROR ((AE_INFO, "Could not acquire AML Interpreter mutex"));
    }
    Status = AcpiUtAcquireMutex (ACPI_MTX_NAMESPACE);
    if (ACPI_FAILURE (Status))
    {
        ACPI_ERROR ((AE_INFO, "Could not acquire AML Namespace mutex"));
    }

    return_VOID;
}

void
AcpiExExitInterpreter (
    void)
{
    ACPI_STATUS             Status;


    ACPI_FUNCTION_TRACE (ExExitInterpreter);


    Status = AcpiUtReleaseMutex (ACPI_MTX_NAMESPACE);
    if (ACPI_FAILURE (Status))
    {
        ACPI_ERROR ((AE_INFO, "Could not release AML Namespace mutex"));
    }
    Status = AcpiUtReleaseMutex (ACPI_MTX_INTERPRETER);
    if (ACPI_FAILURE (Status))
    {
        ACPI_ERROR ((AE_INFO, "Could not release AML Interpreter mutex"));
    }

    return_VOID;
}

BOOLEAN
AcpiExTruncateFor32bitTable (
    ACPI_OPERAND_OBJECT     *ObjDesc)
{

    ACPI_FUNCTION_ENTRY ();


    /*
     * Object must be a valid number and we must be executing
     * a control method. Object could be NS node for AML_INT_NAMEPATH_OP.
     */
    if ((!ObjDesc) ||
        (ACPI_GET_DESCRIPTOR_TYPE (ObjDesc) != ACPI_DESC_TYPE_OPERAND) ||
        (ObjDesc->Common.Type != ACPI_TYPE_INTEGER))
    {
        return (FALSE);
    }

    if ((AcpiGbl_IntegerByteWidth == 4) &&
        (ObjDesc->Integer.Value > (UINT64) ACPI_UINT32_MAX))
    {
        /*
         * We are executing in a 32-bit ACPI table. Truncate
         * the value to 32 bits by zeroing out the upper 32-bit field
         */
        ObjDesc->Integer.Value &= (UINT64) ACPI_UINT32_MAX;
        return (TRUE);
    }

    return (FALSE);
}

void
AcpiExAcquireGlobalLock (
    UINT32                  FieldFlags)
{
    ACPI_STATUS             Status;


    ACPI_FUNCTION_TRACE (ExAcquireGlobalLock);


    /* Only use the lock if the AlwaysLock bit is set */

    if (!(FieldFlags & AML_FIELD_LOCK_RULE_MASK))
    {
        return_VOID;
    }

    /* Attempt to get the global lock, wait forever */

    Status = AcpiExAcquireMutexObject (ACPI_WAIT_FOREVER,
        AcpiGbl_GlobalLockMutex, AcpiOsGetThreadId ());

    if (ACPI_FAILURE (Status))
    {
        ACPI_EXCEPTION ((AE_INFO, Status,
            "Could not acquire Global Lock"));
    }

    return_VOID;
}

void
AcpiExReleaseGlobalLock (
    UINT32                  FieldFlags)
{
    ACPI_STATUS             Status;


    ACPI_FUNCTION_TRACE (ExReleaseGlobalLock);


    /* Only use the lock if the AlwaysLock bit is set */

    if (!(FieldFlags & AML_FIELD_LOCK_RULE_MASK))
    {
        return_VOID;
    }

    /* Release the global lock */

    Status = AcpiExReleaseMutexObject (AcpiGbl_GlobalLockMutex);
    if (ACPI_FAILURE (Status))
    {
        /* Report the error, but there isn't much else we can do */

        ACPI_EXCEPTION ((AE_INFO, Status,
            "Could not release Global Lock"));
    }

    return_VOID;
}

__attribute__((used)) static UINT32
AcpiExDigitsNeeded (
    UINT64                  Value,
    UINT32                  Base)
{
    UINT32                  NumDigits;
    UINT64                  CurrentValue;


    ACPI_FUNCTION_TRACE (ExDigitsNeeded);


    /* UINT64 is unsigned, so we don't worry about a '-' prefix */

    if (Value == 0)
    {
        return_UINT32 (1);
    }

    CurrentValue = Value;
    NumDigits = 0;

    /* Count the digits in the requested base */

    while (CurrentValue)
    {
        (void) AcpiUtShortDivide (CurrentValue, Base, &CurrentValue, NULL);
        NumDigits++;
    }

    return_UINT32 (NumDigits);
}

void
AcpiExEisaIdToString (
    char                    *OutString,
    UINT64                  CompressedId)
{
    UINT32                  SwappedId;


    ACPI_FUNCTION_ENTRY ();


    /* The EISAID should be a 32-bit integer */

    if (CompressedId > ACPI_UINT32_MAX)
    {
        ACPI_WARNING ((AE_INFO,
            "Expected EISAID is larger than 32 bits: "
            "0x%8.8X%8.8X, truncating",
            ACPI_FORMAT_UINT64 (CompressedId)));
    }

    /* Swap ID to big-endian to get contiguous bits */

    SwappedId = AcpiUtDwordByteSwap ((UINT32) CompressedId);

    /* First 3 bytes are uppercase letters. Next 4 bytes are hexadecimal */

    OutString[0] = (char) (0x40 + (((unsigned long) SwappedId >> 26) & 0x1F));
    OutString[1] = (char) (0x40 + ((SwappedId >> 21) & 0x1F));
    OutString[2] = (char) (0x40 + ((SwappedId >> 16) & 0x1F));
    OutString[3] = AcpiUtHexToAsciiChar ((UINT64) SwappedId, 12);
    OutString[4] = AcpiUtHexToAsciiChar ((UINT64) SwappedId, 8);
    OutString[5] = AcpiUtHexToAsciiChar ((UINT64) SwappedId, 4);
    OutString[6] = AcpiUtHexToAsciiChar ((UINT64) SwappedId, 0);
    OutString[7] = 0;
}

void
AcpiExIntegerToString (
    char                    *OutString,
    UINT64                  Value)
{
    UINT32                  Count;
    UINT32                  DigitsNeeded;
    UINT32                  Remainder;


    ACPI_FUNCTION_ENTRY ();


    DigitsNeeded = AcpiExDigitsNeeded (Value, 10);
    OutString[DigitsNeeded] = 0;

    for (Count = DigitsNeeded; Count > 0; Count--)
    {
        (void) AcpiUtShortDivide (Value, 10, &Value, &Remainder);
        OutString[Count-1] = (char) ('0' + Remainder);\
    }
}

void
AcpiExPciClsToString (
    char                    *OutString,
    UINT8                   ClassCode[3])
{

    ACPI_FUNCTION_ENTRY ();


    /* All 3 bytes are hexadecimal */

    OutString[0] = AcpiUtHexToAsciiChar ((UINT64) ClassCode[0], 4);
    OutString[1] = AcpiUtHexToAsciiChar ((UINT64) ClassCode[0], 0);
    OutString[2] = AcpiUtHexToAsciiChar ((UINT64) ClassCode[1], 4);
    OutString[3] = AcpiUtHexToAsciiChar ((UINT64) ClassCode[1], 0);
    OutString[4] = AcpiUtHexToAsciiChar ((UINT64) ClassCode[2], 4);
    OutString[5] = AcpiUtHexToAsciiChar ((UINT64) ClassCode[2], 0);
    OutString[6] = 0;
}

BOOLEAN
AcpiIsValidSpaceId (
    UINT8                   SpaceId)
{

    if ((SpaceId >= ACPI_NUM_PREDEFINED_REGIONS) &&
        (SpaceId < ACPI_USER_REGION_BEGIN) &&
        (SpaceId != ACPI_ADR_SPACE_DATA_TABLE) &&
        (SpaceId != ACPI_ADR_SPACE_FIXED_HARDWARE))
    {
        return (FALSE);
    }

    return (TRUE);
}

