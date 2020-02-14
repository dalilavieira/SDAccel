#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_66__   TYPE_9__ ;
typedef  struct TYPE_65__   TYPE_8__ ;
typedef  struct TYPE_64__   TYPE_7__ ;
typedef  struct TYPE_63__   TYPE_6__ ;
typedef  struct TYPE_62__   TYPE_5__ ;
typedef  struct TYPE_61__   TYPE_4__ ;
typedef  struct TYPE_60__   TYPE_3__ ;
typedef  struct TYPE_59__   TYPE_2__ ;
typedef  struct TYPE_58__   TYPE_27__ ;
typedef  struct TYPE_57__   TYPE_21__ ;
typedef  struct TYPE_56__   TYPE_20__ ;
typedef  struct TYPE_55__   TYPE_1__ ;
typedef  struct TYPE_54__   TYPE_19__ ;
typedef  struct TYPE_53__   TYPE_18__ ;
typedef  struct TYPE_52__   TYPE_17__ ;
typedef  struct TYPE_51__   TYPE_16__ ;
typedef  struct TYPE_50__   TYPE_15__ ;
typedef  struct TYPE_49__   TYPE_14__ ;
typedef  struct TYPE_48__   TYPE_13__ ;
typedef  struct TYPE_47__   TYPE_12__ ;
typedef  struct TYPE_46__   TYPE_11__ ;
typedef  struct TYPE_45__   TYPE_10__ ;

/* Type definitions */
typedef  int UINT32 ;
typedef  scalar_t__ UINT16 ;
struct TYPE_66__ {TYPE_20__* RegionObj; TYPE_20__** InternalPccBuffer; } ;
struct TYPE_65__ {TYPE_20__* BufferObj; } ;
struct TYPE_64__ {TYPE_20__** Next; } ;
struct TYPE_63__ {int /*<<< orphan*/  RegionContext; } ;
struct TYPE_62__ {int HandlerFlags; int /*<<< orphan*/  Context; int /*<<< orphan*/  (* Setup ) (TYPE_20__*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ;TYPE_20__* RegionList; TYPE_20__* Next; } ;
struct TYPE_61__ {TYPE_20__* Next; TYPE_20__* Handler; TYPE_27__* Node; int /*<<< orphan*/  SpaceId; } ;
struct TYPE_60__ {int /*<<< orphan*/ * Node; TYPE_20__* Mutex; } ;
struct TYPE_59__ {int /*<<< orphan*/  OsMutex; } ;
struct TYPE_58__ {int Flags; } ;
struct TYPE_48__ {TYPE_20__* Object; } ;
struct TYPE_57__ {TYPE_13__ Update; } ;
struct TYPE_50__ {int Type; int Flags; scalar_t__ ReferenceCount; } ;
struct TYPE_47__ {TYPE_20__* Object; int /*<<< orphan*/  Class; } ;
struct TYPE_46__ {TYPE_20__* DataObj; TYPE_20__* IndexObj; } ;
struct TYPE_45__ {TYPE_20__* RegionObj; TYPE_20__* BankObj; } ;
struct TYPE_52__ {int Count; TYPE_20__** Elements; } ;
struct TYPE_54__ {TYPE_20__** NotifyList; TYPE_20__* Handler; } ;
struct TYPE_55__ {int /*<<< orphan*/ * OsSemaphore; } ;
struct TYPE_53__ {int /*<<< orphan*/  GpeBlock; } ;
struct TYPE_51__ {void* Pointer; } ;
struct TYPE_49__ {void* Pointer; } ;
struct TYPE_56__ {TYPE_15__ Common; TYPE_12__ Reference; TYPE_11__ IndexField; TYPE_10__ BankField; TYPE_9__ Field; TYPE_8__ BufferField; TYPE_17__ Package; TYPE_7__ Notify; TYPE_19__ CommonNotify; TYPE_6__ Extra; TYPE_5__ AddressSpace; TYPE_4__ Region; TYPE_3__ Method; TYPE_2__ Mutex; TYPE_1__ Event; TYPE_18__ Device; TYPE_16__ Buffer; TYPE_14__ String; } ;
typedef  void* ACPI_STATUS ;
typedef  TYPE_20__ ACPI_OPERAND_OBJECT ;
typedef  TYPE_21__ ACPI_GENERIC_STATE ;
typedef  int /*<<< orphan*/  ACPI_CPU_FLAGS ;

/* Variables and functions */
 int ACPI_ADDR_HANDLER_DEFAULT_INSTALLED ; 
 int /*<<< orphan*/  ACPI_DB_ALLOCATIONS ; 
 int /*<<< orphan*/  ACPI_DEBUG_PRINT (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ACPI_DEBUG_PRINT_RAW (int /*<<< orphan*/ ) ; 
 scalar_t__ ACPI_DESC_TYPE_NAMED ; 
 int /*<<< orphan*/  ACPI_ERROR (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ACPI_EXCEPTION (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ACPI_FAILURE (void*) ; 
 int /*<<< orphan*/  ACPI_FREE (TYPE_20__**) ; 
 int /*<<< orphan*/  ACPI_FUNCTION_ENTRY () ; 
 int /*<<< orphan*/  ACPI_FUNCTION_NAME (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ACPI_FUNCTION_TRACE_PTR (int /*<<< orphan*/ ,TYPE_20__*) ; 
 scalar_t__ ACPI_GET_DESCRIPTOR_TYPE (TYPE_20__*) ; 
 int /*<<< orphan*/  ACPI_GET_FUNCTION_NAME ; 
 scalar_t__ ACPI_MAX_REFERENCE_COUNT ; 
 int ACPI_NUM_NOTIFY_TYPES ; 
 int /*<<< orphan*/  ACPI_REFCLASS_INDEX ; 
 int /*<<< orphan*/  ACPI_REFCLASS_NAME ; 
 int /*<<< orphan*/  ACPI_REGION_DEACTIVATE ; 
#define  ACPI_TYPE_BUFFER 146 
#define  ACPI_TYPE_BUFFER_FIELD 145 
#define  ACPI_TYPE_DEVICE 144 
#define  ACPI_TYPE_EVENT 143 
#define  ACPI_TYPE_INTEGER 142 
#define  ACPI_TYPE_LOCAL_BANK_FIELD 141 
#define  ACPI_TYPE_LOCAL_INDEX_FIELD 140 
#define  ACPI_TYPE_LOCAL_REFERENCE 139 
#define  ACPI_TYPE_LOCAL_REGION_FIELD 138 
#define  ACPI_TYPE_METHOD 137 
#define  ACPI_TYPE_MUTEX 136 
#define  ACPI_TYPE_PACKAGE 135 
#define  ACPI_TYPE_POWER 134 
#define  ACPI_TYPE_PROCESSOR 133 
#define  ACPI_TYPE_REGION 132 
#define  ACPI_TYPE_STRING 131 
#define  ACPI_TYPE_THERMAL 130 
 int /*<<< orphan*/  ACPI_WARNING (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  AE_INFO ; 
 void* AE_OK ; 
 int ANOBJ_TEMPORARY ; 
 int AOPOBJ_STATIC_POINTER ; 
 int /*<<< orphan*/  AcpiEvDeleteGpeBlock (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  AcpiExUnlinkMutex (TYPE_20__*) ; 
 TYPE_20__* AcpiGbl_GlobalLockMutex ; 
 int /*<<< orphan*/ * AcpiGbl_GlobalLockSemaphore ; 
 int /*<<< orphan*/  AcpiGbl_ReferenceCountLock ; 
 TYPE_20__* AcpiNsGetSecondaryObject (TYPE_20__*) ; 
 int /*<<< orphan*/  AcpiOsAcquireLock (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  AcpiOsDeleteMutex (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  AcpiOsDeleteSemaphore (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  AcpiOsReleaseLock (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 void* AcpiUtCreateUpdateStateAndPush (TYPE_20__*,scalar_t__,TYPE_21__**) ; 
 int /*<<< orphan*/  AcpiUtDeleteGenericState (TYPE_21__*) ; 
 int /*<<< orphan*/  AcpiUtDeleteObjectDesc (TYPE_20__*) ; 
 int /*<<< orphan*/  AcpiUtGetObjectTypeName (TYPE_20__*) ; 
 TYPE_21__* AcpiUtPopGenericState (TYPE_21__**) ; 
 int /*<<< orphan*/  AcpiUtRemoveAddressRange (int /*<<< orphan*/ ,TYPE_27__*) ; 
 void AcpiUtRemoveReference (TYPE_20__*) ; 
 int /*<<< orphan*/  AcpiUtValidInternalObject (TYPE_20__*) ; 
#define  REF_DECREMENT 129 
#define  REF_INCREMENT 128 
 int /*<<< orphan*/  UtAddReference ; 
 int /*<<< orphan*/  UtDeleteInternalObj ; 
 int /*<<< orphan*/  UtRemoveReference ; 
 int /*<<< orphan*/  UtUpdateObjectReference ; 
 int /*<<< orphan*/  UtUpdateRefCount ; 
 int /*<<< orphan*/  return_VOID ; 
 int /*<<< orphan*/  stub1 (TYPE_20__*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 

__attribute__((used)) static void
AcpiUtDeleteInternalObj (
    ACPI_OPERAND_OBJECT     *Object)
{
    void                    *ObjPointer = NULL;
    ACPI_OPERAND_OBJECT     *HandlerDesc;
    ACPI_OPERAND_OBJECT     *SecondDesc;
    ACPI_OPERAND_OBJECT     *NextDesc;
    ACPI_OPERAND_OBJECT     *StartDesc;
    ACPI_OPERAND_OBJECT     **LastObjPtr;


    ACPI_FUNCTION_TRACE_PTR (UtDeleteInternalObj, Object);


    if (!Object)
    {
        return_VOID;
    }

    /*
     * Must delete or free any pointers within the object that are not
     * actual ACPI objects (for example, a raw buffer pointer).
     */
    switch (Object->Common.Type)
    {
    case ACPI_TYPE_STRING:

        ACPI_DEBUG_PRINT ((ACPI_DB_ALLOCATIONS, "**** String %p, ptr %p\n",
            Object, Object->String.Pointer));

        /* Free the actual string buffer */

        if (!(Object->Common.Flags & AOPOBJ_STATIC_POINTER))
        {
            /* But only if it is NOT a pointer into an ACPI table */

            ObjPointer = Object->String.Pointer;
        }
        break;

    case ACPI_TYPE_BUFFER:

        ACPI_DEBUG_PRINT ((ACPI_DB_ALLOCATIONS, "**** Buffer %p, ptr %p\n",
            Object, Object->Buffer.Pointer));

        /* Free the actual buffer */

        if (!(Object->Common.Flags & AOPOBJ_STATIC_POINTER))
        {
            /* But only if it is NOT a pointer into an ACPI table */

            ObjPointer = Object->Buffer.Pointer;
        }
        break;

    case ACPI_TYPE_PACKAGE:

        ACPI_DEBUG_PRINT ((ACPI_DB_ALLOCATIONS, " **** Package of count %X\n",
            Object->Package.Count));

        /*
         * Elements of the package are not handled here, they are deleted
         * separately
         */

        /* Free the (variable length) element pointer array */

        ObjPointer = Object->Package.Elements;
        break;

    /*
     * These objects have a possible list of notify handlers.
     * Device object also may have a GPE block.
     */
    case ACPI_TYPE_DEVICE:

        if (Object->Device.GpeBlock)
        {
            (void) AcpiEvDeleteGpeBlock (Object->Device.GpeBlock);
        }

        /*lint -fallthrough */

    case ACPI_TYPE_PROCESSOR:
    case ACPI_TYPE_THERMAL:

        /* Walk the address handler list for this object */

        HandlerDesc = Object->CommonNotify.Handler;
        while (HandlerDesc)
        {
            NextDesc = HandlerDesc->AddressSpace.Next;
            AcpiUtRemoveReference (HandlerDesc);
            HandlerDesc = NextDesc;
        }
        break;

    case ACPI_TYPE_MUTEX:

        ACPI_DEBUG_PRINT ((ACPI_DB_ALLOCATIONS,
            "***** Mutex %p, OS Mutex %p\n",
            Object, Object->Mutex.OsMutex));

        if (Object == AcpiGbl_GlobalLockMutex)
        {
            /* Global Lock has extra semaphore */

            (void) AcpiOsDeleteSemaphore (AcpiGbl_GlobalLockSemaphore);
            AcpiGbl_GlobalLockSemaphore = NULL;

            AcpiOsDeleteMutex (Object->Mutex.OsMutex);
            AcpiGbl_GlobalLockMutex = NULL;
        }
        else
        {
            AcpiExUnlinkMutex (Object);
            AcpiOsDeleteMutex (Object->Mutex.OsMutex);
        }
        break;

    case ACPI_TYPE_EVENT:

        ACPI_DEBUG_PRINT ((ACPI_DB_ALLOCATIONS,
            "***** Event %p, OS Semaphore %p\n",
            Object, Object->Event.OsSemaphore));

        (void) AcpiOsDeleteSemaphore (Object->Event.OsSemaphore);
        Object->Event.OsSemaphore = NULL;
        break;

    case ACPI_TYPE_METHOD:

        ACPI_DEBUG_PRINT ((ACPI_DB_ALLOCATIONS,
            "***** Method %p\n", Object));

        /* Delete the method mutex if it exists */

        if (Object->Method.Mutex)
        {
            AcpiOsDeleteMutex (Object->Method.Mutex->Mutex.OsMutex);
            AcpiUtDeleteObjectDesc (Object->Method.Mutex);
            Object->Method.Mutex = NULL;
        }

        if (Object->Method.Node)
        {
            Object->Method.Node = NULL;
        }
        break;

    case ACPI_TYPE_REGION:

        ACPI_DEBUG_PRINT ((ACPI_DB_ALLOCATIONS,
            "***** Region %p\n", Object));

        /*
         * Update AddressRange list. However, only permanent regions
         * are installed in this list. (Not created within a method)
         */
        if (!(Object->Region.Node->Flags & ANOBJ_TEMPORARY))
        {
            AcpiUtRemoveAddressRange (Object->Region.SpaceId,
                Object->Region.Node);
        }

        SecondDesc = AcpiNsGetSecondaryObject (Object);
        if (SecondDesc)
        {
            /*
             * Free the RegionContext if and only if the handler is one of the
             * default handlers -- and therefore, we created the context object
             * locally, it was not created by an external caller.
             */
            HandlerDesc = Object->Region.Handler;
            if (HandlerDesc)
            {
                NextDesc = HandlerDesc->AddressSpace.RegionList;
                StartDesc = NextDesc;
                LastObjPtr = &HandlerDesc->AddressSpace.RegionList;

                /* Remove the region object from the handler list */

                while (NextDesc)
                {
                    if (NextDesc == Object)
                    {
                        *LastObjPtr = NextDesc->Region.Next;
                        break;
                    }

                    /* Walk the linked list of handlers */

                    LastObjPtr = &NextDesc->Region.Next;
                    NextDesc = NextDesc->Region.Next;

                    /* Prevent infinite loop if list is corrupted */

                    if (NextDesc == StartDesc)
                    {
                        ACPI_ERROR ((AE_INFO,
                            "Circular region list in address handler object %p",
                            HandlerDesc));
                        return_VOID;
                    }
                }

                if (HandlerDesc->AddressSpace.HandlerFlags &
                    ACPI_ADDR_HANDLER_DEFAULT_INSTALLED)
                {
                    /* Deactivate region and free region context */

                    if (HandlerDesc->AddressSpace.Setup)
                    {
                        (void) HandlerDesc->AddressSpace.Setup (Object,
                            ACPI_REGION_DEACTIVATE,
                            HandlerDesc->AddressSpace.Context,
                            &SecondDesc->Extra.RegionContext);
                    }
                }

                AcpiUtRemoveReference (HandlerDesc);
            }

            /* Now we can free the Extra object */

            AcpiUtDeleteObjectDesc (SecondDesc);
        }
        if (Object->Field.InternalPccBuffer)
        {
            ACPI_FREE(Object->Field.InternalPccBuffer);
        }

        break;

    case ACPI_TYPE_BUFFER_FIELD:

        ACPI_DEBUG_PRINT ((ACPI_DB_ALLOCATIONS,
            "***** Buffer Field %p\n", Object));

        SecondDesc = AcpiNsGetSecondaryObject (Object);
        if (SecondDesc)
        {
            AcpiUtDeleteObjectDesc (SecondDesc);
        }
        break;

    case ACPI_TYPE_LOCAL_BANK_FIELD:

        ACPI_DEBUG_PRINT ((ACPI_DB_ALLOCATIONS,
            "***** Bank Field %p\n", Object));

        SecondDesc = AcpiNsGetSecondaryObject (Object);
        if (SecondDesc)
        {
            AcpiUtDeleteObjectDesc (SecondDesc);
        }
        break;

    default:

        break;
    }

    /* Free any allocated memory (pointer within the object) found above */

    if (ObjPointer)
    {
        ACPI_DEBUG_PRINT ((ACPI_DB_ALLOCATIONS, "Deleting Object Subptr %p\n",
            ObjPointer));
        ACPI_FREE (ObjPointer);
    }

    /* Now the object can be safely deleted */

    ACPI_DEBUG_PRINT_RAW ((ACPI_DB_ALLOCATIONS, "%s: Deleting Object %p [%s]\n",
        ACPI_GET_FUNCTION_NAME, Object, AcpiUtGetObjectTypeName (Object)));

    AcpiUtDeleteObjectDesc (Object);
    return_VOID;
}

void
AcpiUtDeleteInternalObjectList (
    ACPI_OPERAND_OBJECT     **ObjList)
{
    ACPI_OPERAND_OBJECT     **InternalObj;


    ACPI_FUNCTION_ENTRY ();


    /* Walk the null-terminated internal list */

    for (InternalObj = ObjList; *InternalObj; InternalObj++)
    {
        AcpiUtRemoveReference (*InternalObj);
    }

    /* Free the combined parameter pointer list and object array */

    ACPI_FREE (ObjList);
    return;
}

__attribute__((used)) static void
AcpiUtUpdateRefCount (
    ACPI_OPERAND_OBJECT     *Object,
    UINT32                  Action)
{
    UINT16                  OriginalCount;
    UINT16                  NewCount = 0;
    ACPI_CPU_FLAGS          LockFlags;
    char                    *Message;


    ACPI_FUNCTION_NAME (UtUpdateRefCount);


    if (!Object)
    {
        return;
    }

    /*
     * Always get the reference count lock. Note: Interpreter and/or
     * Namespace is not always locked when this function is called.
     */
    LockFlags = AcpiOsAcquireLock (AcpiGbl_ReferenceCountLock);
    OriginalCount = Object->Common.ReferenceCount;

    /* Perform the reference count action (increment, decrement) */

    switch (Action)
    {
    case REF_INCREMENT:

        NewCount = OriginalCount + 1;
        Object->Common.ReferenceCount = NewCount;
        AcpiOsReleaseLock (AcpiGbl_ReferenceCountLock, LockFlags);

        /* The current reference count should never be zero here */

        if (!OriginalCount)
        {
            ACPI_WARNING ((AE_INFO,
                "Obj %p, Reference Count was zero before increment\n",
                Object));
        }

        ACPI_DEBUG_PRINT ((ACPI_DB_ALLOCATIONS,
            "Obj %p Type %.2X [%s] Refs %.2X [Incremented]\n",
            Object, Object->Common.Type,
            AcpiUtGetObjectTypeName (Object), NewCount));
        Message = "Incremement";
        break;

    case REF_DECREMENT:

        /* The current reference count must be non-zero */

        if (OriginalCount)
        {
            NewCount = OriginalCount - 1;
            Object->Common.ReferenceCount = NewCount;
        }

        AcpiOsReleaseLock (AcpiGbl_ReferenceCountLock, LockFlags);

        if (!OriginalCount)
        {
            ACPI_WARNING ((AE_INFO,
                "Obj %p, Reference Count is already zero, cannot decrement\n",
                Object));
        }

        ACPI_DEBUG_PRINT_RAW ((ACPI_DB_ALLOCATIONS,
            "%s: Obj %p Type %.2X Refs %.2X [Decremented]\n",
            ACPI_GET_FUNCTION_NAME, Object, Object->Common.Type, NewCount));

        /* Actually delete the object on a reference count of zero */

        if (NewCount == 0)
        {
            AcpiUtDeleteInternalObj (Object);
        }
        Message = "Decrement";
        break;

    default:

        AcpiOsReleaseLock (AcpiGbl_ReferenceCountLock, LockFlags);
        ACPI_ERROR ((AE_INFO, "Unknown Reference Count action (0x%X)",
            Action));
        return;
    }

    /*
     * Sanity check the reference count, for debug purposes only.
     * (A deleted object will have a huge reference count)
     */
    if (NewCount > ACPI_MAX_REFERENCE_COUNT)
    {
        ACPI_WARNING ((AE_INFO,
            "Large Reference Count (0x%X) in object %p, Type=0x%.2X Operation=%s",
            NewCount, Object, Object->Common.Type, Message));
    }
}

ACPI_STATUS
AcpiUtUpdateObjectReference (
    ACPI_OPERAND_OBJECT     *Object,
    UINT16                  Action)
{
    ACPI_STATUS             Status = AE_OK;
    ACPI_GENERIC_STATE      *StateList = NULL;
    ACPI_OPERAND_OBJECT     *NextObject = NULL;
    ACPI_OPERAND_OBJECT     *PrevObject;
    ACPI_GENERIC_STATE      *State;
    UINT32                  i;


    ACPI_FUNCTION_NAME (UtUpdateObjectReference);


    while (Object)
    {
        /* Make sure that this isn't a namespace handle */

        if (ACPI_GET_DESCRIPTOR_TYPE (Object) == ACPI_DESC_TYPE_NAMED)
        {
            ACPI_DEBUG_PRINT ((ACPI_DB_ALLOCATIONS,
                "Object %p is NS handle\n", Object));
            return (AE_OK);
        }

        /*
         * All sub-objects must have their reference count incremented
         * also. Different object types have different subobjects.
         */
        switch (Object->Common.Type)
        {
        case ACPI_TYPE_DEVICE:
        case ACPI_TYPE_PROCESSOR:
        case ACPI_TYPE_POWER:
        case ACPI_TYPE_THERMAL:
            /*
             * Update the notify objects for these types (if present)
             * Two lists, system and device notify handlers.
             */
            for (i = 0; i < ACPI_NUM_NOTIFY_TYPES; i++)
            {
                PrevObject = Object->CommonNotify.NotifyList[i];
                while (PrevObject)
                {
                    NextObject = PrevObject->Notify.Next[i];
                    AcpiUtUpdateRefCount (PrevObject, Action);
                    PrevObject = NextObject;
                }
            }
            break;

        case ACPI_TYPE_PACKAGE:
            /*
             * We must update all the sub-objects of the package,
             * each of whom may have their own sub-objects.
             */
            for (i = 0; i < Object->Package.Count; i++)
            {
                /*
                 * Null package elements are legal and can be simply
                 * ignored.
                 */
                NextObject = Object->Package.Elements[i];
                if (!NextObject)
                {
                    continue;
                }

                switch (NextObject->Common.Type)
                {
                case ACPI_TYPE_INTEGER:
                case ACPI_TYPE_STRING:
                case ACPI_TYPE_BUFFER:
                    /*
                     * For these very simple sub-objects, we can just
                     * update the reference count here and continue.
                     * Greatly increases performance of this operation.
                     */
                    AcpiUtUpdateRefCount (NextObject, Action);
                    break;

                default:
                    /*
                     * For complex sub-objects, push them onto the stack
                     * for later processing (this eliminates recursion.)
                     */
                    Status = AcpiUtCreateUpdateStateAndPush (
                        NextObject, Action, &StateList);
                    if (ACPI_FAILURE (Status))
                    {
                        goto ErrorExit;
                    }
                    break;
                }
            }
            NextObject = NULL;
            break;

        case ACPI_TYPE_BUFFER_FIELD:

            NextObject = Object->BufferField.BufferObj;
            break;

        case ACPI_TYPE_LOCAL_REGION_FIELD:

            NextObject = Object->Field.RegionObj;
            break;

        case ACPI_TYPE_LOCAL_BANK_FIELD:

            NextObject = Object->BankField.BankObj;
            Status = AcpiUtCreateUpdateStateAndPush (
                Object->BankField.RegionObj, Action, &StateList);
            if (ACPI_FAILURE (Status))
            {
                goto ErrorExit;
            }
            break;

        case ACPI_TYPE_LOCAL_INDEX_FIELD:

            NextObject = Object->IndexField.IndexObj;
            Status = AcpiUtCreateUpdateStateAndPush (
                Object->IndexField.DataObj, Action, &StateList);
            if (ACPI_FAILURE (Status))
            {
                goto ErrorExit;
            }
            break;

        case ACPI_TYPE_LOCAL_REFERENCE:
            /*
             * The target of an Index (a package, string, or buffer) or a named
             * reference must track changes to the ref count of the index or
             * target object.
             */
            if ((Object->Reference.Class == ACPI_REFCLASS_INDEX) ||
                (Object->Reference.Class== ACPI_REFCLASS_NAME))
            {
                NextObject = Object->Reference.Object;
            }
            break;

        case ACPI_TYPE_REGION:
        default:

            break; /* No subobjects for all other types */
        }

        /*
         * Now we can update the count in the main object. This can only
         * happen after we update the sub-objects in case this causes the
         * main object to be deleted.
         */
        AcpiUtUpdateRefCount (Object, Action);
        Object = NULL;

        /* Move on to the next object to be updated */

        if (NextObject)
        {
            Object = NextObject;
            NextObject = NULL;
        }
        else if (StateList)
        {
            State = AcpiUtPopGenericState (&StateList);
            Object = State->Update.Object;
            AcpiUtDeleteGenericState (State);
        }
    }

    return (AE_OK);


ErrorExit:

    ACPI_EXCEPTION ((AE_INFO, Status,
        "Could not update object reference count"));

    /* Free any stacked Update State objects */

    while (StateList)
    {
        State = AcpiUtPopGenericState (&StateList);
        AcpiUtDeleteGenericState (State);
    }

    return (Status);
}

void
AcpiUtAddReference (
    ACPI_OPERAND_OBJECT     *Object)
{

    ACPI_FUNCTION_NAME (UtAddReference);


    /* Ensure that we have a valid object */

    if (!AcpiUtValidInternalObject (Object))
    {
        return;
    }

    ACPI_DEBUG_PRINT ((ACPI_DB_ALLOCATIONS,
        "Obj %p Current Refs=%X [To Be Incremented]\n",
        Object, Object->Common.ReferenceCount));

    /* Increment the reference count */

    (void) AcpiUtUpdateObjectReference (Object, REF_INCREMENT);
    return;
}

void
AcpiUtRemoveReference (
    ACPI_OPERAND_OBJECT     *Object)
{

    ACPI_FUNCTION_NAME (UtRemoveReference);


    /*
     * Allow a NULL pointer to be passed in, just ignore it. This saves
     * each caller from having to check. Also, ignore NS nodes.
     */
    if (!Object ||
        (ACPI_GET_DESCRIPTOR_TYPE (Object) == ACPI_DESC_TYPE_NAMED))

    {
        return;
    }

    /* Ensure that we have a valid object */

    if (!AcpiUtValidInternalObject (Object))
    {
        return;
    }

    ACPI_DEBUG_PRINT_RAW ((ACPI_DB_ALLOCATIONS,
        "%s: Obj %p Current Refs=%X [To Be Decremented]\n",
        ACPI_GET_FUNCTION_NAME, Object, Object->Common.ReferenceCount));

    /*
     * Decrement the reference count, and only actually delete the object
     * if the reference count becomes 0. (Must also decrement the ref count
     * of all subobjects!)
     */
    (void) AcpiUtUpdateObjectReference (Object, REF_DECREMENT);
    return;
}

