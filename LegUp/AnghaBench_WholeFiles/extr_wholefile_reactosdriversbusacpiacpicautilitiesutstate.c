#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_21__   TYPE_5__ ;
typedef  struct TYPE_20__   TYPE_4__ ;
typedef  struct TYPE_19__   TYPE_3__ ;
typedef  struct TYPE_18__   TYPE_2__ ;
typedef  struct TYPE_17__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  UINT32 ;
typedef  int /*<<< orphan*/  UINT16 ;
struct TYPE_20__ {int /*<<< orphan*/  State; int /*<<< orphan*/  DescriptorType; TYPE_5__* Next; } ;
struct TYPE_19__ {int NumPackages; int /*<<< orphan*/  Index; void* DestObject; int /*<<< orphan*/ * SourceObject; } ;
struct TYPE_18__ {int /*<<< orphan*/  Value; int /*<<< orphan*/ * Object; } ;
struct TYPE_17__ {scalar_t__ ThreadId; } ;
struct TYPE_21__ {TYPE_4__ Common; TYPE_3__ Pkg; TYPE_2__ Update; TYPE_1__ Thread; } ;
typedef  int /*<<< orphan*/  ACPI_THREAD_STATE ;
typedef  scalar_t__ ACPI_THREAD_ID ;
typedef  int /*<<< orphan*/  ACPI_OPERAND_OBJECT ;
typedef  TYPE_5__ ACPI_GENERIC_STATE ;

/* Variables and functions */
 int /*<<< orphan*/  ACPI_CONTROL_CONDITIONAL_EXECUTING ; 
 int /*<<< orphan*/  ACPI_DESC_TYPE_STATE ; 
 int /*<<< orphan*/  ACPI_DESC_TYPE_STATE_CONTROL ; 
 int /*<<< orphan*/  ACPI_DESC_TYPE_STATE_PACKAGE ; 
 int /*<<< orphan*/  ACPI_DESC_TYPE_STATE_THREAD ; 
 int /*<<< orphan*/  ACPI_DESC_TYPE_STATE_UPDATE ; 
 int /*<<< orphan*/  ACPI_ERROR (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ACPI_FUNCTION_ENTRY () ; 
 int /*<<< orphan*/  AE_INFO ; 
 int /*<<< orphan*/  AcpiGbl_StateCache ; 
 TYPE_5__* AcpiOsAcquireObject (int /*<<< orphan*/ ) ; 
 scalar_t__ AcpiOsGetThreadId () ; 
 int /*<<< orphan*/  AcpiOsReleaseObject (int /*<<< orphan*/ ,TYPE_5__*) ; 

void
AcpiUtPushGenericState (
    ACPI_GENERIC_STATE      **ListHead,
    ACPI_GENERIC_STATE      *State)
{
    ACPI_FUNCTION_ENTRY ();


    /* Push the state object onto the front of the list (stack) */

    State->Common.Next = *ListHead;
    *ListHead = State;
    return;
}

ACPI_GENERIC_STATE *
AcpiUtPopGenericState (
    ACPI_GENERIC_STATE      **ListHead)
{
    ACPI_GENERIC_STATE      *State;


    ACPI_FUNCTION_ENTRY ();


    /* Remove the state object at the head of the list (stack) */

    State = *ListHead;
    if (State)
    {
        /* Update the list head */

        *ListHead = State->Common.Next;
    }

    return (State);
}

ACPI_GENERIC_STATE *
AcpiUtCreateGenericState (
    void)
{
    ACPI_GENERIC_STATE      *State;


    ACPI_FUNCTION_ENTRY ();


    State = AcpiOsAcquireObject (AcpiGbl_StateCache);
    if (State)
    {
        /* Initialize */
        State->Common.DescriptorType = ACPI_DESC_TYPE_STATE;
    }

    return (State);
}

ACPI_THREAD_STATE *
AcpiUtCreateThreadState (
    void)
{
    ACPI_GENERIC_STATE      *State;


    ACPI_FUNCTION_ENTRY ();


    /* Create the generic state object */

    State = AcpiUtCreateGenericState ();
    if (!State)
    {
        return (NULL);
    }

    /* Init fields specific to the update struct */

    State->Common.DescriptorType = ACPI_DESC_TYPE_STATE_THREAD;
    State->Thread.ThreadId = AcpiOsGetThreadId ();

    /* Check for invalid thread ID - zero is very bad, it will break things */

    if (!State->Thread.ThreadId)
    {
        ACPI_ERROR ((AE_INFO, "Invalid zero ID from AcpiOsGetThreadId"));
        State->Thread.ThreadId = (ACPI_THREAD_ID) 1;
    }

    return ((ACPI_THREAD_STATE *) State);
}

ACPI_GENERIC_STATE *
AcpiUtCreateUpdateState (
    ACPI_OPERAND_OBJECT     *Object,
    UINT16                  Action)
{
    ACPI_GENERIC_STATE      *State;


    ACPI_FUNCTION_ENTRY ();


    /* Create the generic state object */

    State = AcpiUtCreateGenericState ();
    if (!State)
    {
        return (NULL);
    }

    /* Init fields specific to the update struct */

    State->Common.DescriptorType = ACPI_DESC_TYPE_STATE_UPDATE;
    State->Update.Object = Object;
    State->Update.Value = Action;
    return (State);
}

ACPI_GENERIC_STATE *
AcpiUtCreatePkgState (
    void                    *InternalObject,
    void                    *ExternalObject,
    UINT32                  Index)
{
    ACPI_GENERIC_STATE      *State;


    ACPI_FUNCTION_ENTRY ();


    /* Create the generic state object */

    State = AcpiUtCreateGenericState ();
    if (!State)
    {
        return (NULL);
    }

    /* Init fields specific to the update struct */

    State->Common.DescriptorType = ACPI_DESC_TYPE_STATE_PACKAGE;
    State->Pkg.SourceObject = (ACPI_OPERAND_OBJECT *) InternalObject;
    State->Pkg.DestObject = ExternalObject;
    State->Pkg.Index= Index;
    State->Pkg.NumPackages = 1;

    return (State);
}

ACPI_GENERIC_STATE *
AcpiUtCreateControlState (
    void)
{
    ACPI_GENERIC_STATE      *State;


    ACPI_FUNCTION_ENTRY ();


    /* Create the generic state object */

    State = AcpiUtCreateGenericState ();
    if (!State)
    {
        return (NULL);
    }

    /* Init fields specific to the control struct */

    State->Common.DescriptorType = ACPI_DESC_TYPE_STATE_CONTROL;
    State->Common.State = ACPI_CONTROL_CONDITIONAL_EXECUTING;

    return (State);
}

void
AcpiUtDeleteGenericState (
    ACPI_GENERIC_STATE      *State)
{
    ACPI_FUNCTION_ENTRY ();


    /* Ignore null state */

    if (State)
    {
        (void) AcpiOsReleaseObject (AcpiGbl_StateCache, State);
    }

    return;
}

