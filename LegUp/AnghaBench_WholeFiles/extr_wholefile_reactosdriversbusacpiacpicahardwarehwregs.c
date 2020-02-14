#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_16__   TYPE_1__ ;
typedef  struct TYPE_15__   TYPE_14__ ;

/* Type definitions */
typedef  int UINT8 ;
typedef  int UINT64 ;
typedef  int UINT32 ;
struct TYPE_16__ {int BitOffset; int BitWidth; int AccessWidth; scalar_t__ SpaceId; int Address; } ;
struct TYPE_15__ {scalar_t__ SmiCommand; TYPE_1__ XPmTimerBlock; TYPE_1__ XPm2ControlBlock; TYPE_1__ XPm1bControlBlock; TYPE_1__ XPm1aControlBlock; } ;
typedef  int /*<<< orphan*/  ACPI_STATUS ;
typedef  scalar_t__ ACPI_PHYSICAL_ADDRESS ;
typedef  scalar_t__ ACPI_IO_ADDRESS ;
typedef  TYPE_1__ ACPI_GENERIC_ADDRESS ;
typedef  int /*<<< orphan*/  ACPI_CPU_FLAGS ;
typedef  int /*<<< orphan*/  ACPI_BIT_REGISTER_INFO ;

/* Variables and functions */
 int ACPI_ACCESS_BIT_WIDTH (int) ; 
 scalar_t__ ACPI_ADR_SPACE_SYSTEM_IO ; 
 scalar_t__ ACPI_ADR_SPACE_SYSTEM_MEMORY ; 
 int ACPI_BITMASK_ALL_FIXED_STATUS ; 
 int ACPI_BITREG_MAX ; 
 int /*<<< orphan*/  ACPI_DB_IO ; 
 int /*<<< orphan*/  ACPI_DEBUG_PRINT (int /*<<< orphan*/ ) ; 
 int ACPI_DIV_8 (int) ; 
 int /*<<< orphan*/  ACPI_ERROR (int /*<<< orphan*/ ) ; 
 scalar_t__ ACPI_FAILURE (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ACPI_FORMAT_UINT64 (int) ; 
 int /*<<< orphan*/  ACPI_FUNCTION_ENTRY () ; 
 int /*<<< orphan*/  ACPI_FUNCTION_NAME (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ACPI_FUNCTION_TRACE (int /*<<< orphan*/ ) ; 
 int ACPI_GET_BITS (int*,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ACPI_INSERT_BITS (int,int /*<<< orphan*/ ,int) ; 
 scalar_t__ ACPI_IS_ALIGNED (int,int) ; 
 scalar_t__ ACPI_IS_POWER_OF_TWO (int) ; 
 int /*<<< orphan*/  ACPI_MASK_BITS_ABOVE_64 (int) ; 
 int /*<<< orphan*/  ACPI_MOVE_64_TO_64 (int*,int*) ; 
 int /*<<< orphan*/  ACPI_PM1_CONTROL_PRESERVED_BITS ; 
 int ACPI_PM1_CONTROL_WRITEONLY_BITS ; 
 int ACPI_PM1_STATUS_PRESERVED_BITS ; 
 int /*<<< orphan*/  ACPI_PM2_CONTROL_PRESERVED_BITS ; 
#define  ACPI_REGISTER_PM1_CONTROL 133 
#define  ACPI_REGISTER_PM1_ENABLE 132 
#define  ACPI_REGISTER_PM1_STATUS 131 
#define  ACPI_REGISTER_PM2_CONTROL 130 
#define  ACPI_REGISTER_PM_TIMER 129 
#define  ACPI_REGISTER_SMI_COMMAND_BLOCK 128 
 int ACPI_ROUND_UP (int,int) ; 
 int ACPI_ROUND_UP_POWER_OF_TWO_8 (int) ; 
 int /*<<< orphan*/  ACPI_SET_BITS (int*,int,int /*<<< orphan*/ ,int) ; 
 scalar_t__ ACPI_SUCCESS (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ACPI_WARNING (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  AE_BAD_ADDRESS ; 
 int /*<<< orphan*/  AE_BAD_PARAMETER ; 
 int /*<<< orphan*/  AE_INFO ; 
 int /*<<< orphan*/  AE_OK ; 
 int /*<<< orphan*/  AE_SUPPORT ; 
 int /*<<< orphan*/  AcpiEvWalkGpeList (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/ * AcpiGbl_BitRegisterInfo ; 
 TYPE_14__ AcpiGbl_FADT ; 
 int /*<<< orphan*/  AcpiGbl_HardwareLock ; 
 TYPE_1__ AcpiGbl_XPm1aEnable ; 
 TYPE_1__ AcpiGbl_XPm1aStatus ; 
 TYPE_1__ AcpiGbl_XPm1bEnable ; 
 TYPE_1__ AcpiGbl_XPm1bStatus ; 
 int /*<<< orphan*/  AcpiHwClearGpeBlock ; 
static  int /*<<< orphan*/  AcpiHwReadMultiple (int*,TYPE_1__*,TYPE_1__*) ; 
 int /*<<< orphan*/  AcpiHwReadPort (scalar_t__,int*,int) ; 
 int /*<<< orphan*/  AcpiHwRegisterWrite (int,int) ; 
static  int /*<<< orphan*/  AcpiHwWriteMultiple (int,TYPE_1__*,TYPE_1__*) ; 
 int /*<<< orphan*/  AcpiHwWritePort (scalar_t__,int,int) ; 
 int /*<<< orphan*/  AcpiOsAcquireLock (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  AcpiOsReadMemory (scalar_t__,int*,int) ; 
 int /*<<< orphan*/  AcpiOsReleaseLock (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  AcpiOsWriteMemory (scalar_t__,int,int) ; 
 int /*<<< orphan*/  AcpiUtGetRegionName (scalar_t__) ; 
 int /*<<< orphan*/  HwClearAcpiStatus ; 
 int /*<<< orphan*/  HwRead ; 
 int /*<<< orphan*/  HwRegisterRead ; 
 int /*<<< orphan*/  HwRegisterWrite ; 
 int /*<<< orphan*/  HwWrite ; 
 int /*<<< orphan*/  HwWritePm1Control ; 
 int /*<<< orphan*/  return_ACPI_STATUS (int /*<<< orphan*/ ) ; 

__attribute__((used)) static UINT8
AcpiHwGetAccessBitWidth (
    UINT64                  Address,
    ACPI_GENERIC_ADDRESS    *Reg,
    UINT8                   MaxBitWidth)
{
    UINT8                   AccessBitWidth;


    /*
     * GAS format "register", used by FADT:
     *  1. Detected if BitOffset is 0 and BitWidth is 8/16/32/64;
     *  2. AccessSize field is ignored and BitWidth field is used for
     *     determining the boundary of the IO accesses.
     * GAS format "region", used by APEI registers:
     *  1. Detected if BitOffset is not 0 or BitWidth is not 8/16/32/64;
     *  2. AccessSize field is used for determining the boundary of the
     *     IO accesses;
     *  3. BitOffset/BitWidth fields are used to describe the "region".
     *
     * Note: This algorithm assumes that the "Address" fields should always
     *       contain aligned values.
     */
    if (!Reg->BitOffset && Reg->BitWidth &&
        ACPI_IS_POWER_OF_TWO (Reg->BitWidth) &&
        ACPI_IS_ALIGNED (Reg->BitWidth, 8))
    {
        AccessBitWidth = Reg->BitWidth;
    }
    else if (Reg->AccessWidth)
    {
        AccessBitWidth = ACPI_ACCESS_BIT_WIDTH (Reg->AccessWidth);
    }
    else
    {
        AccessBitWidth = ACPI_ROUND_UP_POWER_OF_TWO_8 (
            Reg->BitOffset + Reg->BitWidth);
        if (AccessBitWidth <= 8)
        {
            AccessBitWidth = 8;
        }
        else
        {
            while (!ACPI_IS_ALIGNED (Address, AccessBitWidth >> 3))
            {
                AccessBitWidth >>= 1;
            }
        }
    }

    /* Maximum IO port access bit width is 32 */

    if (Reg->SpaceId == ACPI_ADR_SPACE_SYSTEM_IO)
    {
        MaxBitWidth = 32;
    }

    /*
     * Return access width according to the requested maximum access bit width,
     * as the caller should know the format of the register and may enforce
     * a 32-bit accesses.
     */
    if (AccessBitWidth < MaxBitWidth)
    {
        return (AccessBitWidth);
    }
    return (MaxBitWidth);
}

ACPI_STATUS
AcpiHwValidateRegister (
    ACPI_GENERIC_ADDRESS    *Reg,
    UINT8                   MaxBitWidth,
    UINT64                  *Address)
{
    UINT8                   BitWidth;
    UINT8                   AccessWidth;


    /* Must have a valid pointer to a GAS structure */

    if (!Reg)
    {
        return (AE_BAD_PARAMETER);
    }

    /*
     * Copy the target address. This handles possible alignment issues.
     * Address must not be null. A null address also indicates an optional
     * ACPI register that is not supported, so no error message.
     */
    ACPI_MOVE_64_TO_64 (Address, &Reg->Address);
    if (!(*Address))
    {
        return (AE_BAD_ADDRESS);
    }

    /* Validate the SpaceID */

    if ((Reg->SpaceId != ACPI_ADR_SPACE_SYSTEM_MEMORY) &&
        (Reg->SpaceId != ACPI_ADR_SPACE_SYSTEM_IO))
    {
        ACPI_ERROR ((AE_INFO,
            "Unsupported address space: 0x%X", Reg->SpaceId));
        return (AE_SUPPORT);
    }

    /* Validate the AccessWidth */

    if (Reg->AccessWidth > 4)
    {
        ACPI_ERROR ((AE_INFO,
            "Unsupported register access width: 0x%X", Reg->AccessWidth));
        return (AE_SUPPORT);
    }

    /* Validate the BitWidth, convert AccessWidth into number of bits */

    AccessWidth = AcpiHwGetAccessBitWidth (*Address, Reg, MaxBitWidth);
    BitWidth = ACPI_ROUND_UP (Reg->BitOffset + Reg->BitWidth, AccessWidth);
    if (MaxBitWidth < BitWidth)
    {
        ACPI_WARNING ((AE_INFO,
            "Requested bit width 0x%X is smaller than register bit width 0x%X",
            MaxBitWidth, BitWidth));
        return (AE_SUPPORT);
    }

    return (AE_OK);
}

ACPI_STATUS
AcpiHwRead (
    UINT64                  *Value,
    ACPI_GENERIC_ADDRESS    *Reg)
{
    UINT64                  Address;
    UINT8                   AccessWidth;
    UINT32                  BitWidth;
    UINT8                   BitOffset;
    UINT64                  Value64;
    UINT32                  Value32;
    UINT8                   Index;
    ACPI_STATUS             Status;


    ACPI_FUNCTION_NAME (HwRead);


    /* Validate contents of the GAS register */

    Status = AcpiHwValidateRegister (Reg, 64, &Address);
    if (ACPI_FAILURE (Status))
    {
        return (Status);
    }

    /*
     * Initialize entire 64-bit return value to zero, convert AccessWidth
     * into number of bits based
     */
    *Value = 0;
    AccessWidth = AcpiHwGetAccessBitWidth (Address, Reg, 64);
    BitWidth = Reg->BitOffset + Reg->BitWidth;
    BitOffset = Reg->BitOffset;

    /*
     * Two address spaces supported: Memory or IO. PCI_Config is
     * not supported here because the GAS structure is insufficient
     */
    Index = 0;
    while (BitWidth)
    {
        if (BitOffset >= AccessWidth)
        {
            Value64 = 0;
            BitOffset -= AccessWidth;
        }
        else
        {
            if (Reg->SpaceId == ACPI_ADR_SPACE_SYSTEM_MEMORY)
            {
                Status = AcpiOsReadMemory ((ACPI_PHYSICAL_ADDRESS)
                    Address + Index * ACPI_DIV_8 (AccessWidth),
                    &Value64, AccessWidth);
            }
            else /* ACPI_ADR_SPACE_SYSTEM_IO, validated earlier */
            {
                Status = AcpiHwReadPort ((ACPI_IO_ADDRESS)
                    Address + Index * ACPI_DIV_8 (AccessWidth),
                    &Value32, AccessWidth);
                Value64 = (UINT64) Value32;
            }
        }

        /*
         * Use offset style bit writes because "Index * AccessWidth" is
         * ensured to be less than 64-bits by AcpiHwValidateRegister().
         */
        ACPI_SET_BITS (Value, Index * AccessWidth,
            ACPI_MASK_BITS_ABOVE_64 (AccessWidth), Value64);

        BitWidth -= BitWidth > AccessWidth ? AccessWidth : BitWidth;
        Index++;
    }

    ACPI_DEBUG_PRINT ((ACPI_DB_IO,
        "Read:  %8.8X%8.8X width %2d from %8.8X%8.8X (%s)\n",
        ACPI_FORMAT_UINT64 (*Value), AccessWidth,
        ACPI_FORMAT_UINT64 (Address), AcpiUtGetRegionName (Reg->SpaceId)));

    return (Status);
}

ACPI_STATUS
AcpiHwWrite (
    UINT64                  Value,
    ACPI_GENERIC_ADDRESS    *Reg)
{
    UINT64                  Address;
    UINT8                   AccessWidth;
    UINT32                  BitWidth;
    UINT8                   BitOffset;
    UINT64                  Value64;
    UINT8                   Index;
    ACPI_STATUS             Status;


    ACPI_FUNCTION_NAME (HwWrite);


    /* Validate contents of the GAS register */

    Status = AcpiHwValidateRegister (Reg, 64, &Address);
    if (ACPI_FAILURE (Status))
    {
        return (Status);
    }

    /* Convert AccessWidth into number of bits based */

    AccessWidth = AcpiHwGetAccessBitWidth (Address, Reg, 64);
    BitWidth = Reg->BitOffset + Reg->BitWidth;
    BitOffset = Reg->BitOffset;

    /*
     * Two address spaces supported: Memory or IO. PCI_Config is
     * not supported here because the GAS structure is insufficient
     */
    Index = 0;
    while (BitWidth)
    {
        /*
         * Use offset style bit reads because "Index * AccessWidth" is
         * ensured to be less than 64-bits by AcpiHwValidateRegister().
         */
        Value64 = ACPI_GET_BITS (&Value, Index * AccessWidth,
            ACPI_MASK_BITS_ABOVE_64 (AccessWidth));

        if (BitOffset >= AccessWidth)
        {
            BitOffset -= AccessWidth;
        }
        else
        {
            if (Reg->SpaceId == ACPI_ADR_SPACE_SYSTEM_MEMORY)
            {
                Status = AcpiOsWriteMemory ((ACPI_PHYSICAL_ADDRESS)
                    Address + Index * ACPI_DIV_8 (AccessWidth),
                    Value64, AccessWidth);
            }
            else /* ACPI_ADR_SPACE_SYSTEM_IO, validated earlier */
            {
                Status = AcpiHwWritePort ((ACPI_IO_ADDRESS)
                    Address + Index * ACPI_DIV_8 (AccessWidth),
                    (UINT32) Value64, AccessWidth);
            }
        }

        /*
         * Index * AccessWidth is ensured to be less than 32-bits by
         * AcpiHwValidateRegister().
         */
        BitWidth -= BitWidth > AccessWidth ? AccessWidth : BitWidth;
        Index++;
    }

    ACPI_DEBUG_PRINT ((ACPI_DB_IO,
        "Wrote: %8.8X%8.8X width %2d   to %8.8X%8.8X (%s)\n",
        ACPI_FORMAT_UINT64 (Value), AccessWidth,
        ACPI_FORMAT_UINT64 (Address), AcpiUtGetRegionName (Reg->SpaceId)));

    return (Status);
}

ACPI_STATUS
AcpiHwClearAcpiStatus (
    void)
{
    ACPI_STATUS             Status;
    ACPI_CPU_FLAGS          LockFlags = 0;


    ACPI_FUNCTION_TRACE (HwClearAcpiStatus);


    ACPI_DEBUG_PRINT ((ACPI_DB_IO, "About to write %04X to %8.8X%8.8X\n",
        ACPI_BITMASK_ALL_FIXED_STATUS,
        ACPI_FORMAT_UINT64 (AcpiGbl_XPm1aStatus.Address)));

    LockFlags = AcpiOsAcquireLock (AcpiGbl_HardwareLock);

    /* Clear the fixed events in PM1 A/B */

    Status = AcpiHwRegisterWrite (ACPI_REGISTER_PM1_STATUS,
        ACPI_BITMASK_ALL_FIXED_STATUS);

    AcpiOsReleaseLock (AcpiGbl_HardwareLock, LockFlags);

    if (ACPI_FAILURE (Status))
    {
        goto Exit;
    }

    /* Clear the GPE Bits in all GPE registers in all GPE blocks */

    Status = AcpiEvWalkGpeList (AcpiHwClearGpeBlock, NULL);

Exit:
    return_ACPI_STATUS (Status);
}

ACPI_BIT_REGISTER_INFO *
AcpiHwGetBitRegisterInfo (
    UINT32                  RegisterId)
{
    ACPI_FUNCTION_ENTRY ();


    if (RegisterId > ACPI_BITREG_MAX)
    {
        ACPI_ERROR ((AE_INFO, "Invalid BitRegister ID: 0x%X", RegisterId));
        return (NULL);
    }

    return (&AcpiGbl_BitRegisterInfo[RegisterId]);
}

ACPI_STATUS
AcpiHwWritePm1Control (
    UINT32                  Pm1aControl,
    UINT32                  Pm1bControl)
{
    ACPI_STATUS             Status;


    ACPI_FUNCTION_TRACE (HwWritePm1Control);


    Status = AcpiHwWrite (Pm1aControl, &AcpiGbl_FADT.XPm1aControlBlock);
    if (ACPI_FAILURE (Status))
    {
        return_ACPI_STATUS (Status);
    }

    if (AcpiGbl_FADT.XPm1bControlBlock.Address)
    {
        Status = AcpiHwWrite (Pm1bControl, &AcpiGbl_FADT.XPm1bControlBlock);
    }
    return_ACPI_STATUS (Status);
}

ACPI_STATUS
AcpiHwRegisterRead (
    UINT32                  RegisterId,
    UINT32                  *ReturnValue)
{
    UINT32                  Value = 0;
    UINT64                  Value64;
    ACPI_STATUS             Status;


    ACPI_FUNCTION_TRACE (HwRegisterRead);


    switch (RegisterId)
    {
    case ACPI_REGISTER_PM1_STATUS:           /* PM1 A/B: 16-bit access each */

        Status = AcpiHwReadMultiple (&Value,
            &AcpiGbl_XPm1aStatus,
            &AcpiGbl_XPm1bStatus);
        break;

    case ACPI_REGISTER_PM1_ENABLE:           /* PM1 A/B: 16-bit access each */

        Status = AcpiHwReadMultiple (&Value,
            &AcpiGbl_XPm1aEnable,
            &AcpiGbl_XPm1bEnable);
        break;

    case ACPI_REGISTER_PM1_CONTROL:          /* PM1 A/B: 16-bit access each */

        Status = AcpiHwReadMultiple (&Value,
            &AcpiGbl_FADT.XPm1aControlBlock,
            &AcpiGbl_FADT.XPm1bControlBlock);

        /*
         * Zero the write-only bits. From the ACPI specification, "Hardware
         * Write-Only Bits": "Upon reads to registers with write-only bits,
         * software masks out all write-only bits."
         */
        Value &= ~ACPI_PM1_CONTROL_WRITEONLY_BITS;
        break;

    case ACPI_REGISTER_PM2_CONTROL:          /* 8-bit access */

        Status = AcpiHwRead (&Value64, &AcpiGbl_FADT.XPm2ControlBlock);
        if (ACPI_SUCCESS (Status))
        {
            Value = (UINT32) Value64;
        }
        break;

    case ACPI_REGISTER_PM_TIMER:             /* 32-bit access */

        Status = AcpiHwRead (&Value64, &AcpiGbl_FADT.XPmTimerBlock);
        if (ACPI_SUCCESS (Status))
        {
            Value = (UINT32) Value64;
        }

        break;

    case ACPI_REGISTER_SMI_COMMAND_BLOCK:    /* 8-bit access */

        Status = AcpiHwReadPort (AcpiGbl_FADT.SmiCommand, &Value, 8);
        break;

    default:

        ACPI_ERROR ((AE_INFO, "Unknown Register ID: 0x%X",
            RegisterId));
        Status = AE_BAD_PARAMETER;
        break;
    }

    if (ACPI_SUCCESS (Status))
    {
        *ReturnValue = (UINT32) Value;
    }

    return_ACPI_STATUS (Status);
}

ACPI_STATUS
AcpiHwRegisterWrite (
    UINT32                  RegisterId,
    UINT32                  Value)
{
    ACPI_STATUS             Status;
    UINT32                  ReadValue;
    UINT64                  ReadValue64;


    ACPI_FUNCTION_TRACE (HwRegisterWrite);


    switch (RegisterId)
    {
    case ACPI_REGISTER_PM1_STATUS:           /* PM1 A/B: 16-bit access each */
        /*
         * Handle the "ignored" bit in PM1 Status. According to the ACPI
         * specification, ignored bits are to be preserved when writing.
         * Normally, this would mean a read/modify/write sequence. However,
         * preserving a bit in the status register is different. Writing a
         * one clears the status, and writing a zero preserves the status.
         * Therefore, we must always write zero to the ignored bit.
         *
         * This behavior is clarified in the ACPI 4.0 specification.
         */
        Value &= ~ACPI_PM1_STATUS_PRESERVED_BITS;

        Status = AcpiHwWriteMultiple (Value,
            &AcpiGbl_XPm1aStatus,
            &AcpiGbl_XPm1bStatus);
        break;

    case ACPI_REGISTER_PM1_ENABLE:           /* PM1 A/B: 16-bit access each */

        Status = AcpiHwWriteMultiple (Value,
            &AcpiGbl_XPm1aEnable,
            &AcpiGbl_XPm1bEnable);
        break;

    case ACPI_REGISTER_PM1_CONTROL:          /* PM1 A/B: 16-bit access each */
        /*
         * Perform a read first to preserve certain bits (per ACPI spec)
         * Note: This includes SCI_EN, we never want to change this bit
         */
        Status = AcpiHwReadMultiple (&ReadValue,
            &AcpiGbl_FADT.XPm1aControlBlock,
            &AcpiGbl_FADT.XPm1bControlBlock);
        if (ACPI_FAILURE (Status))
        {
            goto Exit;
        }

        /* Insert the bits to be preserved */

        ACPI_INSERT_BITS (Value, ACPI_PM1_CONTROL_PRESERVED_BITS, ReadValue);

        /* Now we can write the data */

        Status = AcpiHwWriteMultiple (Value,
            &AcpiGbl_FADT.XPm1aControlBlock,
            &AcpiGbl_FADT.XPm1bControlBlock);
        break;

    case ACPI_REGISTER_PM2_CONTROL:          /* 8-bit access */
        /*
         * For control registers, all reserved bits must be preserved,
         * as per the ACPI spec.
         */
        Status = AcpiHwRead (&ReadValue64, &AcpiGbl_FADT.XPm2ControlBlock);
        if (ACPI_FAILURE (Status))
        {
            goto Exit;
        }
        ReadValue = (UINT32) ReadValue64;

        /* Insert the bits to be preserved */

        ACPI_INSERT_BITS (Value, ACPI_PM2_CONTROL_PRESERVED_BITS, ReadValue);

        Status = AcpiHwWrite (Value, &AcpiGbl_FADT.XPm2ControlBlock);
        break;

    case ACPI_REGISTER_PM_TIMER:             /* 32-bit access */

        Status = AcpiHwWrite (Value, &AcpiGbl_FADT.XPmTimerBlock);
        break;

    case ACPI_REGISTER_SMI_COMMAND_BLOCK:    /* 8-bit access */

        /* SMI_CMD is currently always in IO space */

        Status = AcpiHwWritePort (AcpiGbl_FADT.SmiCommand, Value, 8);
        break;

    default:

        ACPI_ERROR ((AE_INFO, "Unknown Register ID: 0x%X",
            RegisterId));
        Status = AE_BAD_PARAMETER;
        break;
    }

Exit:
    return_ACPI_STATUS (Status);
}

__attribute__((used)) static ACPI_STATUS
AcpiHwReadMultiple (
    UINT32                  *Value,
    ACPI_GENERIC_ADDRESS    *RegisterA,
    ACPI_GENERIC_ADDRESS    *RegisterB)
{
    UINT32                  ValueA = 0;
    UINT32                  ValueB = 0;
    UINT64                  Value64;
    ACPI_STATUS             Status;


    /* The first register is always required */

    Status = AcpiHwRead (&Value64, RegisterA);
    if (ACPI_FAILURE (Status))
    {
        return (Status);
    }
    ValueA = (UINT32) Value64;

    /* Second register is optional */

    if (RegisterB->Address)
    {
        Status = AcpiHwRead (&Value64, RegisterB);
        if (ACPI_FAILURE (Status))
        {
            return (Status);
        }
        ValueB = (UINT32) Value64;
    }

    /*
     * OR the two return values together. No shifting or masking is necessary,
     * because of how the PM1 registers are defined in the ACPI specification:
     *
     * "Although the bits can be split between the two register blocks (each
     * register block has a unique pointer within the FADT), the bit positions
     * are maintained. The register block with unimplemented bits (that is,
     * those implemented in the other register block) always returns zeros,
     * and writes have no side effects"
     */
    *Value = (ValueA | ValueB);
    return (AE_OK);
}

__attribute__((used)) static ACPI_STATUS
AcpiHwWriteMultiple (
    UINT32                  Value,
    ACPI_GENERIC_ADDRESS    *RegisterA,
    ACPI_GENERIC_ADDRESS    *RegisterB)
{
    ACPI_STATUS             Status;


    /* The first register is always required */

    Status = AcpiHwWrite (Value, RegisterA);
    if (ACPI_FAILURE (Status))
    {
        return (Status);
    }

    /*
     * Second register is optional
     *
     * No bit shifting or clearing is necessary, because of how the PM1
     * registers are defined in the ACPI specification:
     *
     * "Although the bits can be split between the two register blocks (each
     * register block has a unique pointer within the FADT), the bit positions
     * are maintained. The register block with unimplemented bits (that is,
     * those implemented in the other register block) always returns zeros,
     * and writes have no side effects"
     */
    if (RegisterB->Address)
    {
        Status = AcpiHwWrite (Value, RegisterB);
    }

    return (Status);
}

