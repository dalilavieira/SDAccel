#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_2__ ;
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
typedef  size_t UINT32 ;
struct TYPE_4__ {size_t (* Handler ) (int /*<<< orphan*/ *) ;int /*<<< orphan*/ * Context; } ;
struct TYPE_3__ {int EnableRegisterId; size_t StatusBitMask; size_t EnableBitMask; int StatusRegisterId; } ;
typedef  int /*<<< orphan*/  ACPI_STATUS ;

/* Variables and functions */
 int /*<<< orphan*/  ACPI_CLEAR_STATUS ; 
 int /*<<< orphan*/  ACPI_DB_INTERRUPTS ; 
 int /*<<< orphan*/  ACPI_DEBUG_PRINT (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ACPI_DISABLE_EVENT ; 
 int /*<<< orphan*/  ACPI_ERROR (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ACPI_EVENT_TYPE_FIXED ; 
 int /*<<< orphan*/  ACPI_EXCEPTION (int /*<<< orphan*/ ) ; 
 scalar_t__ ACPI_FAILURE (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ACPI_FUNCTION_ENTRY () ; 
 int /*<<< orphan*/  ACPI_FUNCTION_NAME (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ACPI_FUNCTION_TRACE (int /*<<< orphan*/ ) ; 
 size_t ACPI_INTERRUPT_NOT_HANDLED ; 
 size_t ACPI_NUM_FIXED_EVENTS ; 
 int /*<<< orphan*/  ACPI_REGISTER_PM1_ENABLE ; 
 int /*<<< orphan*/  ACPI_REGISTER_PM1_STATUS ; 
 int /*<<< orphan*/  AE_INFO ; 
 int /*<<< orphan*/  AE_OK ; 
static  size_t AcpiEvFixedEventDispatch (size_t) ; 
static  int /*<<< orphan*/  AcpiEvFixedEventInitialize () ; 
 int /*<<< orphan*/  AcpiEvGpeInitialize () ; 
 int /*<<< orphan*/  AcpiEvInitGlobalLockHandler () ; 
 int /*<<< orphan*/  AcpiEvInstallSciHandler () ; 
 int /*<<< orphan*/ * AcpiFixedEventCount ; 
 int /*<<< orphan*/  AcpiGbl_EventsInitialized ; 
 TYPE_2__* AcpiGbl_FixedEventHandlers ; 
 TYPE_1__* AcpiGbl_FixedEventInfo ; 
 int /*<<< orphan*/  AcpiGbl_GlobalEventHandler (int /*<<< orphan*/ ,int /*<<< orphan*/ *,size_t,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  AcpiGbl_GlobalEventHandlerContext ; 
 scalar_t__ AcpiGbl_ReducedHardware ; 
 int /*<<< orphan*/  AcpiHwRegisterRead (int /*<<< orphan*/ ,size_t*) ; 
 int /*<<< orphan*/  AcpiUtGetEventName (size_t) ; 
 int /*<<< orphan*/  AcpiWriteBitRegister (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  EvFixedEventDetect ; 
 int /*<<< orphan*/  EvInitializeEvents ; 
 int /*<<< orphan*/  EvInstallXruptHandlers ; 
 int /*<<< orphan*/  TRUE ; 
 int /*<<< orphan*/  return_ACPI_STATUS (int /*<<< orphan*/ ) ; 
 size_t stub1 (int /*<<< orphan*/ *) ; 

ACPI_STATUS
AcpiEvInitializeEvents (
    void)
{
    ACPI_STATUS             Status;


    ACPI_FUNCTION_TRACE (EvInitializeEvents);


    /* If Hardware Reduced flag is set, there are no fixed events */

    if (AcpiGbl_ReducedHardware)
    {
        return_ACPI_STATUS (AE_OK);
    }

    /*
     * Initialize the Fixed and General Purpose Events. This is done prior to
     * enabling SCIs to prevent interrupts from occurring before the handlers
     * are installed.
     */
    Status = AcpiEvFixedEventInitialize ();
    if (ACPI_FAILURE (Status))
    {
        ACPI_EXCEPTION ((AE_INFO, Status,
            "Unable to initialize fixed events"));
        return_ACPI_STATUS (Status);
    }

    Status = AcpiEvGpeInitialize ();
    if (ACPI_FAILURE (Status))
    {
        ACPI_EXCEPTION ((AE_INFO, Status,
            "Unable to initialize general purpose events"));
        return_ACPI_STATUS (Status);
    }

    return_ACPI_STATUS (Status);
}

ACPI_STATUS
AcpiEvInstallXruptHandlers (
    void)
{
    ACPI_STATUS             Status;


    ACPI_FUNCTION_TRACE (EvInstallXruptHandlers);


    /* If Hardware Reduced flag is set, there is no ACPI h/w */

    if (AcpiGbl_ReducedHardware)
    {
        return_ACPI_STATUS (AE_OK);
    }

    /* Install the SCI handler */

    Status = AcpiEvInstallSciHandler ();
    if (ACPI_FAILURE (Status))
    {
        ACPI_EXCEPTION ((AE_INFO, Status,
            "Unable to install System Control Interrupt handler"));
        return_ACPI_STATUS (Status);
    }

    /* Install the handler for the Global Lock */

    Status = AcpiEvInitGlobalLockHandler ();
    if (ACPI_FAILURE (Status))
    {
        ACPI_EXCEPTION ((AE_INFO, Status,
            "Unable to initialize Global Lock handler"));
        return_ACPI_STATUS (Status);
    }

    AcpiGbl_EventsInitialized = TRUE;
    return_ACPI_STATUS (Status);
}

__attribute__((used)) static ACPI_STATUS
AcpiEvFixedEventInitialize (
    void)
{
    UINT32                  i;
    ACPI_STATUS             Status;


    /*
     * Initialize the structure that keeps track of fixed event handlers and
     * enable the fixed events.
     */
    for (i = 0; i < ACPI_NUM_FIXED_EVENTS; i++)
    {
        AcpiGbl_FixedEventHandlers[i].Handler = NULL;
        AcpiGbl_FixedEventHandlers[i].Context = NULL;

        /* Disable the fixed event */

        if (AcpiGbl_FixedEventInfo[i].EnableRegisterId != 0xFF)
        {
            Status = AcpiWriteBitRegister (
                AcpiGbl_FixedEventInfo[i].EnableRegisterId,
                ACPI_DISABLE_EVENT);
            if (ACPI_FAILURE (Status))
            {
                return (Status);
            }
        }
    }

    return (AE_OK);
}

UINT32
AcpiEvFixedEventDetect (
    void)
{
    UINT32                  IntStatus = ACPI_INTERRUPT_NOT_HANDLED;
    UINT32                  FixedStatus;
    UINT32                  FixedEnable;
    UINT32                  i;
    ACPI_STATUS             Status;


    ACPI_FUNCTION_NAME (EvFixedEventDetect);


    /*
     * Read the fixed feature status and enable registers, as all the cases
     * depend on their values. Ignore errors here.
     */
    Status = AcpiHwRegisterRead (ACPI_REGISTER_PM1_STATUS, &FixedStatus);
    Status |= AcpiHwRegisterRead (ACPI_REGISTER_PM1_ENABLE, &FixedEnable);
    if (ACPI_FAILURE (Status))
    {
        return (IntStatus);
    }

    ACPI_DEBUG_PRINT ((ACPI_DB_INTERRUPTS,
        "Fixed Event Block: Enable %08X Status %08X\n",
        FixedEnable, FixedStatus));

    /*
     * Check for all possible Fixed Events and dispatch those that are active
     */
    for (i = 0; i < ACPI_NUM_FIXED_EVENTS; i++)
    {
        /* Both the status and enable bits must be on for this event */

        if ((FixedStatus & AcpiGbl_FixedEventInfo[i].StatusBitMask) &&
            (FixedEnable & AcpiGbl_FixedEventInfo[i].EnableBitMask))
        {
            /*
             * Found an active (signalled) event. Invoke global event
             * handler if present.
             */
            AcpiFixedEventCount[i]++;
            if (AcpiGbl_GlobalEventHandler)
            {
                AcpiGbl_GlobalEventHandler (ACPI_EVENT_TYPE_FIXED, NULL,
                     i, AcpiGbl_GlobalEventHandlerContext);
            }

            IntStatus |= AcpiEvFixedEventDispatch (i);
        }
    }

    return (IntStatus);
}

__attribute__((used)) static UINT32
AcpiEvFixedEventDispatch (
    UINT32                  Event)
{

    ACPI_FUNCTION_ENTRY ();


    /* Clear the status bit */

    (void) AcpiWriteBitRegister (
        AcpiGbl_FixedEventInfo[Event].StatusRegisterId,
        ACPI_CLEAR_STATUS);

    /*
     * Make sure that a handler exists. If not, report an error
     * and disable the event to prevent further interrupts.
     */
    if (!AcpiGbl_FixedEventHandlers[Event].Handler)
    {
        (void) AcpiWriteBitRegister (
            AcpiGbl_FixedEventInfo[Event].EnableRegisterId,
            ACPI_DISABLE_EVENT);

        ACPI_ERROR ((AE_INFO,
            "No installed handler for fixed event - %s (%u), disabling",
            AcpiUtGetEventName (Event), Event));

        return (ACPI_INTERRUPT_NOT_HANDLED);
    }

    /* Invoke the Fixed Event handler */

    return ((AcpiGbl_FixedEventHandlers[Event].Handler)(
        AcpiGbl_FixedEventHandlers[Event].Context));
}

