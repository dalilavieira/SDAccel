#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_12__   TYPE_6__ ;
typedef  struct TYPE_11__   TYPE_4__ ;
typedef  struct TYPE_10__   TYPE_3__ ;
typedef  struct TYPE_9__   TYPE_2__ ;
typedef  struct TYPE_8__   TYPE_1__ ;

/* Type definitions */
typedef  int UINT8 ;
typedef  scalar_t__ UINT64 ;
typedef  int UINT32 ;
struct TYPE_11__ {int /*<<< orphan*/  Address; } ;
struct TYPE_12__ {TYPE_4__ SleepStatus; TYPE_4__ SleepControl; } ;
struct TYPE_8__ {scalar_t__ Value; } ;
struct TYPE_10__ {TYPE_1__ Integer; int /*<<< orphan*/  Type; } ;
struct TYPE_9__ {int Count; TYPE_3__* Pointer; } ;
typedef  scalar_t__ ACPI_STATUS ;
typedef  TYPE_2__ ACPI_OBJECT_LIST ;
typedef  TYPE_3__ ACPI_OBJECT ;

/* Variables and functions */
 int /*<<< orphan*/  ACPI_DB_INIT ; 
 int /*<<< orphan*/  ACPI_DEBUG_PRINT (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ACPI_EXCEPTION (int /*<<< orphan*/ ) ; 
 scalar_t__ ACPI_FAILURE (scalar_t__) ; 
 int /*<<< orphan*/  ACPI_FLUSH_CPU_CACHE () ; 
 int /*<<< orphan*/  ACPI_FUNCTION_TRACE (int /*<<< orphan*/ ) ; 
 int ACPI_SLEEP_TYPE_INVALID ; 
 int ACPI_SST_WAKING ; 
 int ACPI_SST_WORKING ; 
 int /*<<< orphan*/  ACPI_STATE_S0 ; 
 scalar_t__ ACPI_SUCCESS (scalar_t__) ; 
 int /*<<< orphan*/  ACPI_TYPE_INTEGER ; 
 int ACPI_X_SLEEP_ENABLE ; 
 int ACPI_X_SLEEP_TYPE_MASK ; 
 int ACPI_X_SLEEP_TYPE_POSITION ; 
 int ACPI_X_WAKE_STATUS ; 
 scalar_t__ AE_CTRL_TERMINATE ; 
 int /*<<< orphan*/  AE_INFO ; 
 scalar_t__ AE_NOT_EXIST ; 
 scalar_t__ AE_NOT_FOUND ; 
 scalar_t__ AE_OK ; 
 scalar_t__ AcpiEvaluateObject (int /*<<< orphan*/ *,char*,TYPE_2__*,int /*<<< orphan*/ *) ; 
 TYPE_6__ AcpiGbl_FADT ; 
 int AcpiGbl_SleepTypeA ; 
 int /*<<< orphan*/  AcpiGbl_SleepTypeB ; 
 int /*<<< orphan*/  AcpiGbl_SystemAwakeAndRunning ; 
 scalar_t__ AcpiGetSleepTypeData (int /*<<< orphan*/ ,int*,int /*<<< orphan*/ *) ; 
 scalar_t__ AcpiOsEnterSleep (int,int,int /*<<< orphan*/ ) ; 
 scalar_t__ AcpiRead (scalar_t__*,TYPE_4__*) ; 
 scalar_t__ AcpiWrite (scalar_t__,TYPE_4__*) ; 
 int /*<<< orphan*/  FALSE ; 
 int /*<<< orphan*/  HwExecuteSleepMethod ; 
 int /*<<< orphan*/  HwExtendedSleep ; 
 int /*<<< orphan*/  HwExtendedWake ; 
 int /*<<< orphan*/  HwExtendedWakePrep ; 
 char* METHOD_PATHNAME__SST ; 
 char* METHOD_PATHNAME__WAK ; 
 int /*<<< orphan*/  TRUE ; 
 int /*<<< orphan*/  return_ACPI_STATUS (scalar_t__) ; 
 int /*<<< orphan*/  return_VOID ; 

void
AcpiHwExecuteSleepMethod (
    char                    *MethodPathname,
    UINT32                  IntegerArgument)
{
    ACPI_OBJECT_LIST        ArgList;
    ACPI_OBJECT             Arg;
    ACPI_STATUS             Status;


    ACPI_FUNCTION_TRACE (HwExecuteSleepMethod);


    /* One argument, IntegerArgument; No return value expected */

    ArgList.Count = 1;
    ArgList.Pointer = &Arg;
    Arg.Type = ACPI_TYPE_INTEGER;
    Arg.Integer.Value = (UINT64) IntegerArgument;

    Status = AcpiEvaluateObject (NULL, MethodPathname, &ArgList, NULL);
    if (ACPI_FAILURE (Status) && Status != AE_NOT_FOUND)
    {
        ACPI_EXCEPTION ((AE_INFO, Status, "While executing method %s",
            MethodPathname));
    }

    return_VOID;
}

ACPI_STATUS
AcpiHwExtendedSleep (
    UINT8                   SleepState)
{
    ACPI_STATUS             Status;
    UINT8                   SleepControl;
    UINT64                  SleepStatus;


    ACPI_FUNCTION_TRACE (HwExtendedSleep);


    /* Extended sleep registers must be valid */

    if (!AcpiGbl_FADT.SleepControl.Address ||
        !AcpiGbl_FADT.SleepStatus.Address)
    {
        return_ACPI_STATUS (AE_NOT_EXIST);
    }

    /* Clear wake status (WAK_STS) */

    Status = AcpiWrite ((UINT64) ACPI_X_WAKE_STATUS,
        &AcpiGbl_FADT.SleepStatus);
    if (ACPI_FAILURE (Status))
    {
        return_ACPI_STATUS (Status);
    }

    AcpiGbl_SystemAwakeAndRunning = FALSE;

    /*
     * Set the SLP_TYP and SLP_EN bits.
     *
     * Note: We only use the first value returned by the \_Sx method
     * (AcpiGbl_SleepTypeA) - As per ACPI specification.
     */
    ACPI_DEBUG_PRINT ((ACPI_DB_INIT,
        "Entering sleep state [S%u]\n", SleepState));

    SleepControl = ((AcpiGbl_SleepTypeA << ACPI_X_SLEEP_TYPE_POSITION) &
        ACPI_X_SLEEP_TYPE_MASK) | ACPI_X_SLEEP_ENABLE;

    /* Flush caches, as per ACPI specification */

    ACPI_FLUSH_CPU_CACHE ();

    Status = AcpiOsEnterSleep (SleepState, SleepControl, 0);
    if (Status == AE_CTRL_TERMINATE)
    {
        return_ACPI_STATUS (AE_OK);
    }
    if (ACPI_FAILURE (Status))
    {
        return_ACPI_STATUS (Status);
    }

    Status = AcpiWrite ((UINT64) SleepControl, &AcpiGbl_FADT.SleepControl);
    if (ACPI_FAILURE (Status))
    {
        return_ACPI_STATUS (Status);
    }

    /* Wait for transition back to Working State */

    do
    {
        Status = AcpiRead (&SleepStatus, &AcpiGbl_FADT.SleepStatus);
        if (ACPI_FAILURE (Status))
        {
            return_ACPI_STATUS (Status);
        }

    } while (!(((UINT8) SleepStatus) & ACPI_X_WAKE_STATUS));

    return_ACPI_STATUS (AE_OK);
}

ACPI_STATUS
AcpiHwExtendedWakePrep (
    UINT8                   SleepState)
{
    ACPI_STATUS             Status;
    UINT8                   SleepTypeValue;


    ACPI_FUNCTION_TRACE (HwExtendedWakePrep);


    Status = AcpiGetSleepTypeData (ACPI_STATE_S0,
        &AcpiGbl_SleepTypeA, &AcpiGbl_SleepTypeB);
    if (ACPI_SUCCESS (Status))
    {
        SleepTypeValue = ((AcpiGbl_SleepTypeA << ACPI_X_SLEEP_TYPE_POSITION) &
            ACPI_X_SLEEP_TYPE_MASK);

        (void) AcpiWrite ((UINT64) (SleepTypeValue | ACPI_X_SLEEP_ENABLE),
            &AcpiGbl_FADT.SleepControl);
    }

    return_ACPI_STATUS (AE_OK);
}

ACPI_STATUS
AcpiHwExtendedWake (
    UINT8                   SleepState)
{
    ACPI_FUNCTION_TRACE (HwExtendedWake);


    /* Ensure EnterSleepStatePrep -> EnterSleepState ordering */

    AcpiGbl_SleepTypeA = ACPI_SLEEP_TYPE_INVALID;

    /* Execute the wake methods */

    AcpiHwExecuteSleepMethod (METHOD_PATHNAME__SST, ACPI_SST_WAKING);
    AcpiHwExecuteSleepMethod (METHOD_PATHNAME__WAK, SleepState);

    /*
     * Some BIOS code assumes that WAK_STS will be cleared on resume
     * and use it to determine whether the system is rebooting or
     * resuming. Clear WAK_STS for compatibility.
     */
    (void) AcpiWrite ((UINT64) ACPI_X_WAKE_STATUS, &AcpiGbl_FADT.SleepStatus);
    AcpiGbl_SystemAwakeAndRunning = TRUE;

    AcpiHwExecuteSleepMethod (METHOD_PATHNAME__SST, ACPI_SST_WORKING);
    return_ACPI_STATUS (AE_OK);
}

