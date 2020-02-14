#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_16__   TYPE_3__ ;
typedef  struct TYPE_15__   TYPE_2__ ;
typedef  struct TYPE_14__   TYPE_1__ ;

/* Type definitions */
typedef  int UINT8 ;
typedef  int UINT64 ;
typedef  int UINT32 ;
struct TYPE_16__ {int RegisterCount; TYPE_1__* RegisterInfo; } ;
struct TYPE_15__ {int GpeNumber; TYPE_1__* RegisterInfo; int /*<<< orphan*/  Flags; } ;
struct TYPE_14__ {int BaseGpeNumber; int EnableMask; int MaskForRun; int EnableForRun; int EnableForWake; int /*<<< orphan*/  StatusAddress; int /*<<< orphan*/  EnableAddress; } ;
typedef  int /*<<< orphan*/  ACPI_STATUS ;
typedef  int /*<<< orphan*/  ACPI_GPE_XRUPT_INFO ;
typedef  TYPE_1__ ACPI_GPE_REGISTER_INFO ;
typedef  TYPE_2__ ACPI_GPE_EVENT_INFO ;
typedef  TYPE_3__ ACPI_GPE_BLOCK_INFO ;
typedef  int /*<<< orphan*/  ACPI_EVENT_STATUS ;

/* Variables and functions */
 int /*<<< orphan*/  ACPI_CLEAR_BIT (int,int) ; 
 int /*<<< orphan*/  ACPI_ERROR (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ACPI_EVENT_FLAG_ENABLED ; 
 int /*<<< orphan*/  ACPI_EVENT_FLAG_ENABLE_SET ; 
 int /*<<< orphan*/  ACPI_EVENT_FLAG_HAS_HANDLER ; 
 int /*<<< orphan*/  ACPI_EVENT_FLAG_MASKED ; 
 int /*<<< orphan*/  ACPI_EVENT_FLAG_STATUS_SET ; 
 int /*<<< orphan*/  ACPI_EVENT_FLAG_WAKE_ENABLED ; 
 scalar_t__ ACPI_FAILURE (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ACPI_FUNCTION_ENTRY () ; 
 int /*<<< orphan*/  ACPI_FUNCTION_TRACE (int /*<<< orphan*/ ) ; 
#define  ACPI_GPE_CONDITIONAL_ENABLE 130 
#define  ACPI_GPE_DISABLE 129 
 scalar_t__ ACPI_GPE_DISPATCH_NONE ; 
 scalar_t__ ACPI_GPE_DISPATCH_TYPE (int /*<<< orphan*/ ) ; 
#define  ACPI_GPE_ENABLE 128 
 int /*<<< orphan*/  ACPI_SET_BIT (int,int) ; 
 int /*<<< orphan*/  AE_BAD_PARAMETER ; 
 int /*<<< orphan*/  AE_INFO ; 
 int /*<<< orphan*/  AE_NOT_EXIST ; 
 int /*<<< orphan*/  AE_OK ; 
 int /*<<< orphan*/  AcpiEvWalkGpeList (int /*<<< orphan*/  (*) (int /*<<< orphan*/ *,TYPE_3__*,void*),int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  AcpiHwRead (int*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  AcpiHwWrite (int,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  HwDisableAllGpes ; 
 int /*<<< orphan*/  HwEnableAllRuntimeGpes ; 
 int /*<<< orphan*/  HwEnableAllWakeupGpes ; 
 int /*<<< orphan*/  return_ACPI_STATUS (int /*<<< orphan*/ ) ; 

UINT32
AcpiHwGetGpeRegisterBit (
    ACPI_GPE_EVENT_INFO     *GpeEventInfo)
{

    return ((UINT32) 1 <<
        (GpeEventInfo->GpeNumber - GpeEventInfo->RegisterInfo->BaseGpeNumber));
}

ACPI_STATUS
AcpiHwLowSetGpe (
    ACPI_GPE_EVENT_INFO     *GpeEventInfo,
    UINT32                  Action)
{
    ACPI_GPE_REGISTER_INFO  *GpeRegisterInfo;
    ACPI_STATUS             Status = AE_OK;
    UINT64                  EnableMask;
    UINT32                  RegisterBit;


    ACPI_FUNCTION_ENTRY ();


    /* Get the info block for the entire GPE register */

    GpeRegisterInfo = GpeEventInfo->RegisterInfo;
    if (!GpeRegisterInfo)
    {
        return (AE_NOT_EXIST);
    }

    /* Get current value of the enable register that contains this GPE */

    Status = AcpiHwRead (&EnableMask, &GpeRegisterInfo->EnableAddress);
    if (ACPI_FAILURE (Status))
    {
        return (Status);
    }

    /* Set or clear just the bit that corresponds to this GPE */

    RegisterBit = AcpiHwGetGpeRegisterBit (GpeEventInfo);
    switch (Action)
    {
    case ACPI_GPE_CONDITIONAL_ENABLE:

        /* Only enable if the corresponding EnableMask bit is set */

        if (!(RegisterBit & GpeRegisterInfo->EnableMask))
        {
            return (AE_BAD_PARAMETER);
        }

        /*lint -fallthrough */

    case ACPI_GPE_ENABLE:

        ACPI_SET_BIT (EnableMask, RegisterBit);
        break;

    case ACPI_GPE_DISABLE:

        ACPI_CLEAR_BIT (EnableMask, RegisterBit);
        break;

    default:

        ACPI_ERROR ((AE_INFO, "Invalid GPE Action, %u", Action));
        return (AE_BAD_PARAMETER);
    }

    if (!(RegisterBit & GpeRegisterInfo->MaskForRun))
    {
        /* Write the updated enable mask */

        Status = AcpiHwWrite (EnableMask, &GpeRegisterInfo->EnableAddress);
    }
    return (Status);
}

ACPI_STATUS
AcpiHwClearGpe (
    ACPI_GPE_EVENT_INFO     *GpeEventInfo)
{
    ACPI_GPE_REGISTER_INFO  *GpeRegisterInfo;
    ACPI_STATUS             Status;
    UINT32                  RegisterBit;


    ACPI_FUNCTION_ENTRY ();

    /* Get the info block for the entire GPE register */

    GpeRegisterInfo = GpeEventInfo->RegisterInfo;
    if (!GpeRegisterInfo)
    {
        return (AE_NOT_EXIST);
    }

    /*
     * Write a one to the appropriate bit in the status register to
     * clear this GPE.
     */
    RegisterBit = AcpiHwGetGpeRegisterBit (GpeEventInfo);

    Status = AcpiHwWrite (RegisterBit, &GpeRegisterInfo->StatusAddress);
    return (Status);
}

ACPI_STATUS
AcpiHwGetGpeStatus (
    ACPI_GPE_EVENT_INFO     *GpeEventInfo,
    ACPI_EVENT_STATUS       *EventStatus)
{
    UINT64                  InByte;
    UINT32                  RegisterBit;
    ACPI_GPE_REGISTER_INFO  *GpeRegisterInfo;
    ACPI_EVENT_STATUS       LocalEventStatus = 0;
    ACPI_STATUS             Status;


    ACPI_FUNCTION_ENTRY ();


    if (!EventStatus)
    {
        return (AE_BAD_PARAMETER);
    }

    /* GPE currently handled? */

    if (ACPI_GPE_DISPATCH_TYPE (GpeEventInfo->Flags) !=
        ACPI_GPE_DISPATCH_NONE)
    {
        LocalEventStatus |= ACPI_EVENT_FLAG_HAS_HANDLER;
    }

    /* Get the info block for the entire GPE register */

    GpeRegisterInfo = GpeEventInfo->RegisterInfo;

    /* Get the register bitmask for this GPE */

    RegisterBit = AcpiHwGetGpeRegisterBit (GpeEventInfo);

    /* GPE currently enabled? (enabled for runtime?) */

    if (RegisterBit & GpeRegisterInfo->EnableForRun)
    {
        LocalEventStatus |= ACPI_EVENT_FLAG_ENABLED;
    }

    /* GPE currently masked? (masked for runtime?) */

    if (RegisterBit & GpeRegisterInfo->MaskForRun)
    {
        LocalEventStatus |= ACPI_EVENT_FLAG_MASKED;
    }

    /* GPE enabled for wake? */

    if (RegisterBit & GpeRegisterInfo->EnableForWake)
    {
        LocalEventStatus |= ACPI_EVENT_FLAG_WAKE_ENABLED;
    }

    /* GPE currently enabled (enable bit == 1)? */

    Status = AcpiHwRead (&InByte, &GpeRegisterInfo->EnableAddress);
    if (ACPI_FAILURE (Status))
    {
        return (Status);
    }

    if (RegisterBit & InByte)
    {
        LocalEventStatus |= ACPI_EVENT_FLAG_ENABLE_SET;
    }

    /* GPE currently active (status bit == 1)? */

    Status = AcpiHwRead (&InByte, &GpeRegisterInfo->StatusAddress);
    if (ACPI_FAILURE (Status))
    {
        return (Status);
    }

    if (RegisterBit & InByte)
    {
        LocalEventStatus |= ACPI_EVENT_FLAG_STATUS_SET;
    }

    /* Set return value */

    (*EventStatus) = LocalEventStatus;
    return (AE_OK);
}

__attribute__((used)) static ACPI_STATUS
AcpiHwGpeEnableWrite (
    UINT8                   EnableMask,
    ACPI_GPE_REGISTER_INFO  *GpeRegisterInfo)
{
    ACPI_STATUS             Status;


    GpeRegisterInfo->EnableMask = EnableMask;

    Status = AcpiHwWrite (EnableMask, &GpeRegisterInfo->EnableAddress);
    return (Status);
}

ACPI_STATUS
AcpiHwDisableGpeBlock (
    ACPI_GPE_XRUPT_INFO     *GpeXruptInfo,
    ACPI_GPE_BLOCK_INFO     *GpeBlock,
    void                    *Context)
{
    UINT32                  i;
    ACPI_STATUS             Status;


    /* Examine each GPE Register within the block */

    for (i = 0; i < GpeBlock->RegisterCount; i++)
    {
        /* Disable all GPEs in this register */

        Status = AcpiHwGpeEnableWrite (0x00, &GpeBlock->RegisterInfo[i]);
        if (ACPI_FAILURE (Status))
        {
            return (Status);
        }
    }

    return (AE_OK);
}

ACPI_STATUS
AcpiHwClearGpeBlock (
    ACPI_GPE_XRUPT_INFO     *GpeXruptInfo,
    ACPI_GPE_BLOCK_INFO     *GpeBlock,
    void                    *Context)
{
    UINT32                  i;
    ACPI_STATUS             Status;


    /* Examine each GPE Register within the block */

    for (i = 0; i < GpeBlock->RegisterCount; i++)
    {
        /* Clear status on all GPEs in this register */

        Status = AcpiHwWrite (0xFF, &GpeBlock->RegisterInfo[i].StatusAddress);
        if (ACPI_FAILURE (Status))
        {
            return (Status);
        }
    }

    return (AE_OK);
}

ACPI_STATUS
AcpiHwEnableRuntimeGpeBlock (
    ACPI_GPE_XRUPT_INFO     *GpeXruptInfo,
    ACPI_GPE_BLOCK_INFO     *GpeBlock,
    void                    *Context)
{
    UINT32                  i;
    ACPI_STATUS             Status;
    ACPI_GPE_REGISTER_INFO  *GpeRegisterInfo;
    UINT8                   EnableMask;


    /* NOTE: assumes that all GPEs are currently disabled */

    /* Examine each GPE Register within the block */

    for (i = 0; i < GpeBlock->RegisterCount; i++)
    {
        GpeRegisterInfo = &GpeBlock->RegisterInfo[i];
        if (!GpeRegisterInfo->EnableForRun)
        {
            continue;
        }

        /* Enable all "runtime" GPEs in this register */

        EnableMask = GpeRegisterInfo->EnableForRun &
            ~GpeRegisterInfo->MaskForRun;
        Status = AcpiHwGpeEnableWrite (EnableMask, GpeRegisterInfo);
        if (ACPI_FAILURE (Status))
        {
            return (Status);
        }
    }

    return (AE_OK);
}

__attribute__((used)) static ACPI_STATUS
AcpiHwEnableWakeupGpeBlock (
    ACPI_GPE_XRUPT_INFO     *GpeXruptInfo,
    ACPI_GPE_BLOCK_INFO     *GpeBlock,
    void                    *Context)
{
    UINT32                  i;
    ACPI_STATUS             Status;
    ACPI_GPE_REGISTER_INFO  *GpeRegisterInfo;


    /* Examine each GPE Register within the block */

    for (i = 0; i < GpeBlock->RegisterCount; i++)
    {
        GpeRegisterInfo = &GpeBlock->RegisterInfo[i];

        /*
         * Enable all "wake" GPEs in this register and disable the
         * remaining ones.
         */
        Status = AcpiHwGpeEnableWrite (GpeRegisterInfo->EnableForWake,
            GpeRegisterInfo);
        if (ACPI_FAILURE (Status))
        {
            return (Status);
        }
    }

    return (AE_OK);
}

ACPI_STATUS
AcpiHwDisableAllGpes (
    void)
{
    ACPI_STATUS             Status;


    ACPI_FUNCTION_TRACE (HwDisableAllGpes);


    Status = AcpiEvWalkGpeList (AcpiHwDisableGpeBlock, NULL);
    return_ACPI_STATUS (Status);
}

ACPI_STATUS
AcpiHwEnableAllRuntimeGpes (
    void)
{
    ACPI_STATUS             Status;


    ACPI_FUNCTION_TRACE (HwEnableAllRuntimeGpes);


    Status = AcpiEvWalkGpeList (AcpiHwEnableRuntimeGpeBlock, NULL);
    return_ACPI_STATUS (Status);
}

ACPI_STATUS
AcpiHwEnableAllWakeupGpes (
    void)
{
    ACPI_STATUS             Status;


    ACPI_FUNCTION_TRACE (HwEnableAllWakeupGpes);


    Status = AcpiEvWalkGpeList (AcpiHwEnableWakeupGpeBlock, NULL);
    return_ACPI_STATUS (Status);
}

