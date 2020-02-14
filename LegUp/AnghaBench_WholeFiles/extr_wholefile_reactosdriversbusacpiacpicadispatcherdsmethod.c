#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_87__   TYPE_9__ ;
typedef  struct TYPE_86__   TYPE_8__ ;
typedef  struct TYPE_85__   TYPE_7__ ;
typedef  struct TYPE_84__   TYPE_6__ ;
typedef  struct TYPE_83__   TYPE_5__ ;
typedef  struct TYPE_82__   TYPE_4__ ;
typedef  struct TYPE_81__   TYPE_3__ ;
typedef  struct TYPE_80__   TYPE_2__ ;
typedef  struct TYPE_79__   TYPE_1__ ;
typedef  struct TYPE_78__   TYPE_17__ ;
typedef  struct TYPE_77__   TYPE_15__ ;
typedef  struct TYPE_76__   TYPE_14__ ;
typedef  struct TYPE_75__   TYPE_13__ ;
typedef  struct TYPE_74__   TYPE_12__ ;
typedef  struct TYPE_73__   TYPE_11__ ;
typedef  struct TYPE_72__   TYPE_10__ ;

/* Type definitions */
typedef  size_t UINT32 ;
struct TYPE_87__ {scalar_t__ CurrentSyncLevel; scalar_t__ ThreadId; } ;
struct TYPE_86__ {int (* Implementation ) (TYPE_13__*) ;} ;
struct TYPE_84__ {int /*<<< orphan*/  Integer; } ;
struct TYPE_85__ {TYPE_6__ Name; } ;
struct TYPE_83__ {int /*<<< orphan*/  AmlStart; } ;
struct TYPE_82__ {int Flags; int /*<<< orphan*/  Name; } ;
struct TYPE_80__ {int InfoFlags; scalar_t__ SyncLevel; } ;
struct TYPE_81__ {TYPE_2__ Method; } ;
struct TYPE_79__ {TYPE_13__* Node; } ;
struct TYPE_78__ {TYPE_15__** Parameters; } ;
struct TYPE_74__ {scalar_t__ SyncLevel; scalar_t__ ThreadCount; int InfoFlags; size_t ParamCount; scalar_t__ Node; int /*<<< orphan*/  OwnerId; TYPE_15__* Mutex; TYPE_8__ Dispatch; int /*<<< orphan*/  AmlLength; int /*<<< orphan*/  AmlStart; } ;
struct TYPE_72__ {scalar_t__ SyncLevel; scalar_t__ ThreadId; scalar_t__ OriginalSyncLevel; int /*<<< orphan*/  OsMutex; int /*<<< orphan*/  AcquisitionDepth; } ;
struct TYPE_77__ {TYPE_12__ Method; TYPE_10__ Mutex; } ;
struct TYPE_76__ {TYPE_1__ Common; } ;
struct TYPE_73__ {int /*<<< orphan*/  Ascii; int /*<<< orphan*/  Integer; } ;
struct TYPE_75__ {int (* DescendingCallback ) (TYPE_13__*,TYPE_14__**) ;size_t NumOperands; int MethodNestingDepth; TYPE_11__ Name; struct TYPE_75__* MethodNode; TYPE_9__* Thread; TYPE_15__* ReturnDesc; scalar_t__ ReturnUsed; TYPE_15__* ImplicitReturnObj; int /*<<< orphan*/  Results; int /*<<< orphan*/  MethodCallOp; int /*<<< orphan*/ * MethodPathname; int /*<<< orphan*/  MethodIsNested; TYPE_15__** Operands; struct TYPE_75__* MethodCallNode; int /*<<< orphan*/  PrevOp; int /*<<< orphan*/  Op; int /*<<< orphan*/  Opcode; TYPE_7__* DeferredNode; TYPE_5__ ParserState; int /*<<< orphan*/  Aml; TYPE_4__* OpInfo; TYPE_3__* MethodDesc; int /*<<< orphan*/  OwnerId; } ;
typedef  TYPE_13__ ACPI_WALK_STATE ;
typedef  int /*<<< orphan*/  ACPI_THREAD_STATE ;
typedef  int ACPI_STATUS ;
typedef  TYPE_14__ ACPI_PARSE_OBJECT ;
typedef  TYPE_15__ ACPI_OPERAND_OBJECT ;
typedef  TYPE_13__ ACPI_NAMESPACE_NODE ;
typedef  int /*<<< orphan*/  ACPI_NAME ;
typedef  TYPE_17__ ACPI_EVALUATE_INFO ;

/* Variables and functions */
 TYPE_17__* ACPI_ALLOCATE_ZEROED (int) ; 
 int /*<<< orphan*/  ACPI_DB_DISPATCH ; 
 int /*<<< orphan*/  ACPI_DB_EVALUATION ; 
 int /*<<< orphan*/  ACPI_DB_INFO ; 
 int /*<<< orphan*/  ACPI_DB_PARSE ; 
 int /*<<< orphan*/  ACPI_DEBUG_PRINT (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ACPI_DEBUG_PRINT_RAW (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ACPI_ERROR (int /*<<< orphan*/ ) ; 
 scalar_t__ ACPI_FAILURE (int) ; 
 int /*<<< orphan*/  ACPI_FREE (TYPE_17__*) ; 
 int /*<<< orphan*/  ACPI_FUNCTION_ENTRY () ; 
 int /*<<< orphan*/  ACPI_FUNCTION_NAME (int (*) (TYPE_13__*,TYPE_14__**)) ; 
 int /*<<< orphan*/  ACPI_FUNCTION_TRACE (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ACPI_FUNCTION_TRACE_PTR (int /*<<< orphan*/ ,TYPE_13__*) ; 
 int /*<<< orphan*/  ACPI_IMODE_EXECUTE ; 
 int /*<<< orphan*/  ACPI_INFO (char*) ; 
 int ACPI_METHOD_IGNORE_SYNC_LEVEL ; 
 int ACPI_METHOD_INTERNAL_ONLY ; 
 int ACPI_METHOD_MODIFIED_NAMESPACE ; 
 int ACPI_METHOD_MODULE_LEVEL ; 
 int ACPI_METHOD_SERIALIZED ; 
 int ACPI_METHOD_SERIALIZED_PENDING ; 
 scalar_t__ ACPI_PTR_DIFF (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 scalar_t__ ACPI_SUCCESS (int) ; 
 int /*<<< orphan*/  ACPI_TYPE_MUTEX ; 
 scalar_t__ ACPI_UINT8_MAX ; 
 int /*<<< orphan*/  ACPI_WAIT_FOREVER ; 
 int AE_AML_METHOD_LIMIT ; 
 int AE_AML_MUTEX_ORDER ; 
 int AE_CODE_CONTROL ; 
 int AE_CTRL_TERMINATE ; 
 int /*<<< orphan*/  AE_INFO ; 
 int AE_NO_MEMORY ; 
 int AE_NULL_ENTRY ; 
 int AE_NULL_OBJECT ; 
 int AE_OK ; 
 int AML_CREATE ; 
 int AML_FIELD ; 
 int /*<<< orphan*/  AML_METHOD_OP ; 
 int AML_NAMED ; 
 int /*<<< orphan*/  AcpiDsClearImplicitReturn (TYPE_13__*) ; 
 TYPE_13__* AcpiDsCreateWalkState (int /*<<< orphan*/ ,int /*<<< orphan*/ *,TYPE_15__*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  AcpiDsDeleteWalkState (TYPE_13__*) ; 
static  int AcpiDsDetectNamedOpcodes (TYPE_13__*,TYPE_14__**) ; 
 int /*<<< orphan*/  AcpiDsDoImplicitReturn (TYPE_15__*,TYPE_13__*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  AcpiDsDumpMethodStack (int,TYPE_13__*,int /*<<< orphan*/ ) ; 
 int AcpiDsInitAmlWalk (TYPE_13__*,TYPE_14__*,TYPE_13__*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,TYPE_17__*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  AcpiDsMethodDataDeleteAll (TYPE_13__*) ; 
 int AcpiDsResultPush (TYPE_15__*,TYPE_13__*) ; 
 void AcpiDsTerminateControlMethod (TYPE_15__*,TYPE_13__*) ; 
 int /*<<< orphan*/  AcpiExEnterInterpreter () ; 
 int /*<<< orphan*/  AcpiExExitInterpreter () ; 
 int /*<<< orphan*/  AcpiExStartTraceMethod (TYPE_13__*,TYPE_15__*,TYPE_13__*) ; 
 int /*<<< orphan*/  AcpiExStopTraceMethod (TYPE_13__*,TYPE_15__*,TYPE_13__*) ; 
 int AcpiExSystemWaitMutex (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int AcpiGbl_ExceptionHandler (int,int /*<<< orphan*/ ,int /*<<< orphan*/ ,size_t,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  AcpiMethodCount ; 
 int /*<<< orphan*/  AcpiNsDeleteNamespaceByOwner (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  AcpiNsDeleteNamespaceSubtree (TYPE_13__*) ; 
 TYPE_15__* AcpiNsGetAttachedObject (TYPE_13__*) ; 
 int /*<<< orphan*/ * AcpiNsGetNormalizedPathname (TYPE_13__*,int /*<<< orphan*/ ) ; 
 int AcpiOsCreateMutex (int /*<<< orphan*/ *) ; 
 scalar_t__ AcpiOsGetThreadId () ; 
 int /*<<< orphan*/  AcpiOsReleaseMutex (int /*<<< orphan*/ ) ; 
 TYPE_14__* AcpiPsAllocOp (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  AcpiPsDeleteParseTree (TYPE_14__*) ; 
 int /*<<< orphan*/  AcpiPsFreeOp (TYPE_14__*) ; 
 int AcpiPsParseAml (TYPE_13__*) ; 
 int /*<<< orphan*/  AcpiPsSetName (TYPE_14__*,int /*<<< orphan*/ ) ; 
 int AcpiUtAllocateOwnerId (int /*<<< orphan*/ *) ; 
 TYPE_15__* AcpiUtCreateInternalObject (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  AcpiUtDeleteObjectDesc (TYPE_15__*) ; 
 int /*<<< orphan*/  AcpiUtGetNodeName (TYPE_13__*) ; 
 int /*<<< orphan*/  AcpiUtReleaseOwnerId (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  AcpiUtRemoveReference (TYPE_15__*) ; 
 int /*<<< orphan*/  DsAutoSerializeMethod ; 
 int /*<<< orphan*/  DsBeginMethodExecution ; 
 int /*<<< orphan*/  DsCallControlMethod ; 
 int /*<<< orphan*/  DsCreateMethodMutex ; 
 int /*<<< orphan*/  DsRestartControlMethod ; 
 int /*<<< orphan*/  DsTerminateControlMethod ; 
 int /*<<< orphan*/  FALSE ; 
 int /*<<< orphan*/  TRUE ; 
 int /*<<< orphan*/  return_ACPI_STATUS (int) ; 
 int /*<<< orphan*/  return_VOID ; 
 int stub1 (TYPE_13__*) ; 

ACPI_STATUS
AcpiDsAutoSerializeMethod (
    ACPI_NAMESPACE_NODE     *Node,
    ACPI_OPERAND_OBJECT     *ObjDesc)
{
    ACPI_STATUS             Status;
    ACPI_PARSE_OBJECT       *Op = NULL;
    ACPI_WALK_STATE         *WalkState;


    ACPI_FUNCTION_TRACE_PTR (DsAutoSerializeMethod, Node);


    ACPI_DEBUG_PRINT ((ACPI_DB_PARSE,
        "Method auto-serialization parse [%4.4s] %p\n",
        AcpiUtGetNodeName (Node), Node));

    /* Create/Init a root op for the method parse tree */

    Op = AcpiPsAllocOp (AML_METHOD_OP, ObjDesc->Method.AmlStart);
    if (!Op)
    {
        return_ACPI_STATUS (AE_NO_MEMORY);
    }

    AcpiPsSetName (Op, Node->Name.Integer);
    Op->Common.Node = Node;

    /* Create and initialize a new walk state */

    WalkState = AcpiDsCreateWalkState (Node->OwnerId, NULL, NULL, NULL);
    if (!WalkState)
    {
        AcpiPsFreeOp (Op);
        return_ACPI_STATUS (AE_NO_MEMORY);
    }

    Status = AcpiDsInitAmlWalk (WalkState, Op, Node,
        ObjDesc->Method.AmlStart, ObjDesc->Method.AmlLength, NULL, 0);
    if (ACPI_FAILURE (Status))
    {
        AcpiDsDeleteWalkState (WalkState);
        AcpiPsFreeOp (Op);
        return_ACPI_STATUS (Status);
    }

    WalkState->DescendingCallback = AcpiDsDetectNamedOpcodes;

    /* Parse the method, scan for creation of named objects */

    Status = AcpiPsParseAml (WalkState);

    AcpiPsDeleteParseTree (Op);
    return_ACPI_STATUS (Status);
}

__attribute__((used)) static ACPI_STATUS
AcpiDsDetectNamedOpcodes (
    ACPI_WALK_STATE         *WalkState,
    ACPI_PARSE_OBJECT       **OutOp)
{

    ACPI_FUNCTION_NAME (AcpiDsDetectNamedOpcodes);


    /* We are only interested in opcodes that create a new name */

    if (!(WalkState->OpInfo->Flags & (AML_NAMED | AML_CREATE | AML_FIELD)))
    {
        return (AE_OK);
    }

    /*
     * At this point, we know we have a Named object opcode.
     * Mark the method as serialized. Later code will create a mutex for
     * this method to enforce serialization.
     *
     * Note, ACPI_METHOD_IGNORE_SYNC_LEVEL flag means that we will ignore the
     * Sync Level mechanism for this method, even though it is now serialized.
     * Otherwise, there can be conflicts with existing ASL code that actually
     * uses sync levels.
     */
    WalkState->MethodDesc->Method.SyncLevel = 0;
    WalkState->MethodDesc->Method.InfoFlags |=
        (ACPI_METHOD_SERIALIZED | ACPI_METHOD_IGNORE_SYNC_LEVEL);

    ACPI_DEBUG_PRINT ((ACPI_DB_INFO,
        "Method serialized [%4.4s] %p - [%s] (%4.4X)\n",
        WalkState->MethodNode->Name.Ascii, WalkState->MethodNode,
        WalkState->OpInfo->Name, WalkState->Opcode));

    /* Abort the parse, no need to examine this method any further */

    return (AE_CTRL_TERMINATE);
}

ACPI_STATUS
AcpiDsMethodError (
    ACPI_STATUS             Status,
    ACPI_WALK_STATE         *WalkState)
{
    UINT32                  AmlOffset;
    ACPI_NAME               Name = 0;


    ACPI_FUNCTION_ENTRY ();


    /* Ignore AE_OK and control exception codes */

    if (ACPI_SUCCESS (Status) ||
        (Status & AE_CODE_CONTROL))
    {
        return (Status);
    }

    /* Invoke the global exception handler */

    if (AcpiGbl_ExceptionHandler)
    {
        /* Exit the interpreter, allow handler to execute methods */

        AcpiExExitInterpreter ();

        /*
         * Handler can map the exception code to anything it wants, including
         * AE_OK, in which case the executing method will not be aborted.
         */
        AmlOffset = (UINT32) ACPI_PTR_DIFF (WalkState->Aml,
            WalkState->ParserState.AmlStart);

        if (WalkState->MethodNode)
        {
            Name = WalkState->MethodNode->Name.Integer;
        }
        else if (WalkState->DeferredNode)
        {
            Name = WalkState->DeferredNode->Name.Integer;
        }

        Status = AcpiGbl_ExceptionHandler (Status, Name,
            WalkState->Opcode, AmlOffset, NULL);
        AcpiExEnterInterpreter ();
    }

    AcpiDsClearImplicitReturn (WalkState);

    if (ACPI_FAILURE (Status))
    {
        AcpiDsDumpMethodStack (Status, WalkState, WalkState->Op);

        /* Display method locals/args if debugger is present */

#ifdef ACPI_DEBUGGER
        AcpiDbDumpMethodInfo (Status, WalkState);
#endif
    }

    return (Status);
}

__attribute__((used)) static ACPI_STATUS
AcpiDsCreateMethodMutex (
    ACPI_OPERAND_OBJECT     *MethodDesc)
{
    ACPI_OPERAND_OBJECT     *MutexDesc;
    ACPI_STATUS             Status;


    ACPI_FUNCTION_TRACE (DsCreateMethodMutex);


    /* Create the new mutex object */

    MutexDesc = AcpiUtCreateInternalObject (ACPI_TYPE_MUTEX);
    if (!MutexDesc)
    {
        return_ACPI_STATUS (AE_NO_MEMORY);
    }

    /* Create the actual OS Mutex */

    Status = AcpiOsCreateMutex (&MutexDesc->Mutex.OsMutex);
    if (ACPI_FAILURE (Status))
    {
        AcpiUtDeleteObjectDesc (MutexDesc);
        return_ACPI_STATUS (Status);
    }

    MutexDesc->Mutex.SyncLevel = MethodDesc->Method.SyncLevel;
    MethodDesc->Method.Mutex = MutexDesc;
    return_ACPI_STATUS (AE_OK);
}

ACPI_STATUS
AcpiDsBeginMethodExecution (
    ACPI_NAMESPACE_NODE     *MethodNode,
    ACPI_OPERAND_OBJECT     *ObjDesc,
    ACPI_WALK_STATE         *WalkState)
{
    ACPI_STATUS             Status = AE_OK;


    ACPI_FUNCTION_TRACE_PTR (DsBeginMethodExecution, MethodNode);


    if (!MethodNode)
    {
        return_ACPI_STATUS (AE_NULL_ENTRY);
    }

    AcpiExStartTraceMethod (MethodNode, ObjDesc, WalkState);

    /* Prevent wraparound of thread count */

    if (ObjDesc->Method.ThreadCount == ACPI_UINT8_MAX)
    {
        ACPI_ERROR ((AE_INFO,
            "Method reached maximum reentrancy limit (255)"));
        return_ACPI_STATUS (AE_AML_METHOD_LIMIT);
    }

    /*
     * If this method is serialized, we need to acquire the method mutex.
     */
    if (ObjDesc->Method.InfoFlags & ACPI_METHOD_SERIALIZED)
    {
        /*
         * Create a mutex for the method if it is defined to be Serialized
         * and a mutex has not already been created. We defer the mutex creation
         * until a method is actually executed, to minimize the object count
         */
        if (!ObjDesc->Method.Mutex)
        {
            Status = AcpiDsCreateMethodMutex (ObjDesc);
            if (ACPI_FAILURE (Status))
            {
                return_ACPI_STATUS (Status);
            }
        }

        /*
         * The CurrentSyncLevel (per-thread) must be less than or equal to
         * the sync level of the method. This mechanism provides some
         * deadlock prevention.
         *
         * If the method was auto-serialized, we just ignore the sync level
         * mechanism, because auto-serialization of methods can interfere
         * with ASL code that actually uses sync levels.
         *
         * Top-level method invocation has no walk state at this point
         */
        if (WalkState &&
            (!(ObjDesc->Method.InfoFlags & ACPI_METHOD_IGNORE_SYNC_LEVEL)) &&
            (WalkState->Thread->CurrentSyncLevel >
                ObjDesc->Method.Mutex->Mutex.SyncLevel))
        {
            ACPI_ERROR ((AE_INFO,
                "Cannot acquire Mutex for method [%4.4s]"
                ", current SyncLevel is too large (%u)",
                AcpiUtGetNodeName (MethodNode),
                WalkState->Thread->CurrentSyncLevel));

            return_ACPI_STATUS (AE_AML_MUTEX_ORDER);
        }

        /*
         * Obtain the method mutex if necessary. Do not acquire mutex for a
         * recursive call.
         */
        if (!WalkState ||
            !ObjDesc->Method.Mutex->Mutex.ThreadId ||
            (WalkState->Thread->ThreadId !=
                ObjDesc->Method.Mutex->Mutex.ThreadId))
        {
            /*
             * Acquire the method mutex. This releases the interpreter if we
             * block (and reacquires it before it returns)
             */
            Status = AcpiExSystemWaitMutex (
                ObjDesc->Method.Mutex->Mutex.OsMutex, ACPI_WAIT_FOREVER);
            if (ACPI_FAILURE (Status))
            {
                return_ACPI_STATUS (Status);
            }

            /* Update the mutex and walk info and save the original SyncLevel */

            if (WalkState)
            {
                ObjDesc->Method.Mutex->Mutex.OriginalSyncLevel =
                    WalkState->Thread->CurrentSyncLevel;

                ObjDesc->Method.Mutex->Mutex.ThreadId =
                    WalkState->Thread->ThreadId;

                /*
                 * Update the current SyncLevel only if this is not an auto-
                 * serialized method. In the auto case, we have to ignore
                 * the sync level for the method mutex (created for the
                 * auto-serialization) because we have no idea of what the
                 * sync level should be. Therefore, just ignore it.
                 */
                if (!(ObjDesc->Method.InfoFlags &
                    ACPI_METHOD_IGNORE_SYNC_LEVEL))
                {
                    WalkState->Thread->CurrentSyncLevel =
                        ObjDesc->Method.SyncLevel;
                }
            }
            else
            {
                ObjDesc->Method.Mutex->Mutex.OriginalSyncLevel =
                    ObjDesc->Method.Mutex->Mutex.SyncLevel;

                ObjDesc->Method.Mutex->Mutex.ThreadId =
                    AcpiOsGetThreadId ();
            }
        }

        /* Always increase acquisition depth */

        ObjDesc->Method.Mutex->Mutex.AcquisitionDepth++;
    }

    /*
     * Allocate an Owner ID for this method, only if this is the first thread
     * to begin concurrent execution. We only need one OwnerId, even if the
     * method is invoked recursively.
     */
    if (!ObjDesc->Method.OwnerId)
    {
        Status = AcpiUtAllocateOwnerId (&ObjDesc->Method.OwnerId);
        if (ACPI_FAILURE (Status))
        {
            goto Cleanup;
        }
    }

    /*
     * Increment the method parse tree thread count since it has been
     * reentered one more time (even if it is the same thread)
     */
    ObjDesc->Method.ThreadCount++;
    AcpiMethodCount++;
    return_ACPI_STATUS (Status);


Cleanup:
    /* On error, must release the method mutex (if present) */

    if (ObjDesc->Method.Mutex)
    {
        AcpiOsReleaseMutex (ObjDesc->Method.Mutex->Mutex.OsMutex);
    }
    return_ACPI_STATUS (Status);
}

ACPI_STATUS
AcpiDsCallControlMethod (
    ACPI_THREAD_STATE       *Thread,
    ACPI_WALK_STATE         *ThisWalkState,
    ACPI_PARSE_OBJECT       *Op)
{
    ACPI_STATUS             Status;
    ACPI_NAMESPACE_NODE     *MethodNode;
    ACPI_WALK_STATE         *NextWalkState = NULL;
    ACPI_OPERAND_OBJECT     *ObjDesc;
    ACPI_EVALUATE_INFO      *Info;
    UINT32                  i;


    ACPI_FUNCTION_TRACE_PTR (DsCallControlMethod, ThisWalkState);

    ACPI_DEBUG_PRINT ((ACPI_DB_DISPATCH,
        "Calling method %p, currentstate=%p\n",
        ThisWalkState->PrevOp, ThisWalkState));

    /*
     * Get the namespace entry for the control method we are about to call
     */
    MethodNode = ThisWalkState->MethodCallNode;
    if (!MethodNode)
    {
        return_ACPI_STATUS (AE_NULL_ENTRY);
    }

    ObjDesc = AcpiNsGetAttachedObject (MethodNode);
    if (!ObjDesc)
    {
        return_ACPI_STATUS (AE_NULL_OBJECT);
    }

    /* Init for new method, possibly wait on method mutex */

    Status = AcpiDsBeginMethodExecution (
        MethodNode, ObjDesc, ThisWalkState);
    if (ACPI_FAILURE (Status))
    {
        return_ACPI_STATUS (Status);
    }

    /* Begin method parse/execution. Create a new walk state */

    NextWalkState = AcpiDsCreateWalkState (
        ObjDesc->Method.OwnerId, NULL, ObjDesc, Thread);
    if (!NextWalkState)
    {
        Status = AE_NO_MEMORY;
        goto Cleanup;
    }

    /*
     * The resolved arguments were put on the previous walk state's operand
     * stack. Operands on the previous walk state stack always
     * start at index 0. Also, null terminate the list of arguments
     */
    ThisWalkState->Operands [ThisWalkState->NumOperands] = NULL;

    /*
     * Allocate and initialize the evaluation information block
     * TBD: this is somewhat inefficient, should change interface to
     * DsInitAmlWalk. For now, keeps this struct off the CPU stack
     */
    Info = ACPI_ALLOCATE_ZEROED (sizeof (ACPI_EVALUATE_INFO));
    if (!Info)
    {
        Status = AE_NO_MEMORY;
        goto Cleanup;
    }

    Info->Parameters = &ThisWalkState->Operands[0];

    Status = AcpiDsInitAmlWalk (NextWalkState, NULL, MethodNode,
        ObjDesc->Method.AmlStart, ObjDesc->Method.AmlLength,
        Info, ACPI_IMODE_EXECUTE);

    ACPI_FREE (Info);
    if (ACPI_FAILURE (Status))
    {
        goto Cleanup;
    }

    NextWalkState->MethodNestingDepth = ThisWalkState->MethodNestingDepth + 1;

    /*
     * Delete the operands on the previous walkstate operand stack
     * (they were copied to new objects)
     */
    for (i = 0; i < ObjDesc->Method.ParamCount; i++)
    {
        AcpiUtRemoveReference (ThisWalkState->Operands [i]);
        ThisWalkState->Operands [i] = NULL;
    }

    /* Clear the operand stack */

    ThisWalkState->NumOperands = 0;

    ACPI_DEBUG_PRINT ((ACPI_DB_DISPATCH,
        "**** Begin nested execution of [%4.4s] **** WalkState=%p\n",
        MethodNode->Name.Ascii, NextWalkState));

    ThisWalkState->MethodPathname = AcpiNsGetNormalizedPathname (MethodNode, TRUE);
    ThisWalkState->MethodIsNested = TRUE;

    /* Optional object evaluation log */

    ACPI_DEBUG_PRINT_RAW ((ACPI_DB_EVALUATION,
        "%-26s:  %*s%s\n", "   Nested method call",
        NextWalkState->MethodNestingDepth * 3, " ",
        &ThisWalkState->MethodPathname[1]));

    /* Invoke an internal method if necessary */

    if (ObjDesc->Method.InfoFlags & ACPI_METHOD_INTERNAL_ONLY)
    {
        Status = ObjDesc->Method.Dispatch.Implementation (NextWalkState);
        if (Status == AE_OK)
        {
            Status = AE_CTRL_TERMINATE;
        }
    }

    return_ACPI_STATUS (Status);


Cleanup:

    /* On error, we must terminate the method properly */

    AcpiDsTerminateControlMethod (ObjDesc, NextWalkState);
    AcpiDsDeleteWalkState (NextWalkState);

    return_ACPI_STATUS (Status);
}

ACPI_STATUS
AcpiDsRestartControlMethod (
    ACPI_WALK_STATE         *WalkState,
    ACPI_OPERAND_OBJECT     *ReturnDesc)
{
    ACPI_STATUS             Status;
    int                     SameAsImplicitReturn;


    ACPI_FUNCTION_TRACE_PTR (DsRestartControlMethod, WalkState);


    ACPI_DEBUG_PRINT ((ACPI_DB_DISPATCH,
        "****Restart [%4.4s] Op %p ReturnValueFromCallee %p\n",
        AcpiUtGetNodeName (WalkState->MethodNode),
        WalkState->MethodCallOp, ReturnDesc));

    ACPI_DEBUG_PRINT ((ACPI_DB_DISPATCH,
        "    ReturnFromThisMethodUsed?=%X ResStack %p Walk %p\n",
        WalkState->ReturnUsed,
        WalkState->Results, WalkState));

    /* Did the called method return a value? */

    if (ReturnDesc)
    {
        /* Is the implicit return object the same as the return desc? */

        SameAsImplicitReturn = (WalkState->ImplicitReturnObj == ReturnDesc);

        /* Are we actually going to use the return value? */

        if (WalkState->ReturnUsed)
        {
            /* Save the return value from the previous method */

            Status = AcpiDsResultPush (ReturnDesc, WalkState);
            if (ACPI_FAILURE (Status))
            {
                AcpiUtRemoveReference (ReturnDesc);
                return_ACPI_STATUS (Status);
            }

            /*
             * Save as THIS method's return value in case it is returned
             * immediately to yet another method
             */
            WalkState->ReturnDesc = ReturnDesc;
        }

        /*
         * The following code is the optional support for the so-called
         * "implicit return". Some AML code assumes that the last value of the
         * method is "implicitly" returned to the caller, in the absence of an
         * explicit return value.
         *
         * Just save the last result of the method as the return value.
         *
         * NOTE: this is optional because the ASL language does not actually
         * support this behavior.
         */
        else if (!AcpiDsDoImplicitReturn (ReturnDesc, WalkState, FALSE) ||
                 SameAsImplicitReturn)
        {
            /*
             * Delete the return value if it will not be used by the
             * calling method or remove one reference if the explicit return
             * is the same as the implicit return value.
             */
            AcpiUtRemoveReference (ReturnDesc);
        }
    }

    return_ACPI_STATUS (AE_OK);
}

void
AcpiDsTerminateControlMethod (
    ACPI_OPERAND_OBJECT     *MethodDesc,
    ACPI_WALK_STATE         *WalkState)
{

    ACPI_FUNCTION_TRACE_PTR (DsTerminateControlMethod, WalkState);


    /* MethodDesc is required, WalkState is optional */

    if (!MethodDesc)
    {
        return_VOID;
    }

    if (WalkState)
    {
        /* Delete all arguments and locals */

        AcpiDsMethodDataDeleteAll (WalkState);

        /*
         * Delete any namespace objects created anywhere within the
         * namespace by the execution of this method. Unless:
         * 1) This method is a module-level executable code method, in which
         *    case we want make the objects permanent.
         * 2) There are other threads executing the method, in which case we
         *    will wait until the last thread has completed.
         */
        if (!(MethodDesc->Method.InfoFlags & ACPI_METHOD_MODULE_LEVEL) &&
             (MethodDesc->Method.ThreadCount == 1))
        {
            /* Delete any direct children of (created by) this method */

            (void) AcpiExExitInterpreter ();
            AcpiNsDeleteNamespaceSubtree (WalkState->MethodNode);
            (void) AcpiExEnterInterpreter ();

            /*
             * Delete any objects that were created by this method
             * elsewhere in the namespace (if any were created).
             * Use of the ACPI_METHOD_MODIFIED_NAMESPACE optimizes the
             * deletion such that we don't have to perform an entire
             * namespace walk for every control method execution.
             */
            if (MethodDesc->Method.InfoFlags & ACPI_METHOD_MODIFIED_NAMESPACE)
            {
                (void) AcpiExExitInterpreter ();
                AcpiNsDeleteNamespaceByOwner (MethodDesc->Method.OwnerId);
                (void) AcpiExEnterInterpreter ();
                MethodDesc->Method.InfoFlags &=
                    ~ACPI_METHOD_MODIFIED_NAMESPACE;
            }
        }

        /*
         * If method is serialized, release the mutex and restore the
         * current sync level for this thread
         */
        if (MethodDesc->Method.Mutex)
        {
            /* Acquisition Depth handles recursive calls */

            MethodDesc->Method.Mutex->Mutex.AcquisitionDepth--;
            if (!MethodDesc->Method.Mutex->Mutex.AcquisitionDepth)
            {
                WalkState->Thread->CurrentSyncLevel =
                    MethodDesc->Method.Mutex->Mutex.OriginalSyncLevel;

                AcpiOsReleaseMutex (
                    MethodDesc->Method.Mutex->Mutex.OsMutex);
                MethodDesc->Method.Mutex->Mutex.ThreadId = 0;
            }
        }
    }

    /* Decrement the thread count on the method */

    if (MethodDesc->Method.ThreadCount)
    {
        MethodDesc->Method.ThreadCount--;
    }
    else
    {
        ACPI_ERROR ((AE_INFO,
            "Invalid zero thread count in method"));
    }

    /* Are there any other threads currently executing this method? */

    if (MethodDesc->Method.ThreadCount)
    {
        /*
         * Additional threads. Do not release the OwnerId in this case,
         * we immediately reuse it for the next thread executing this method
         */
        ACPI_DEBUG_PRINT ((ACPI_DB_DISPATCH,
            "*** Completed execution of one thread, %u threads remaining\n",
            MethodDesc->Method.ThreadCount));
    }
    else
    {
        /* This is the only executing thread for this method */

        /*
         * Support to dynamically change a method from NotSerialized to
         * Serialized if it appears that the method is incorrectly written and
         * does not support multiple thread execution. The best example of this
         * is if such a method creates namespace objects and blocks. A second
         * thread will fail with an AE_ALREADY_EXISTS exception.
         *
         * This code is here because we must wait until the last thread exits
         * before marking the method as serialized.
         */
        if (MethodDesc->Method.InfoFlags & ACPI_METHOD_SERIALIZED_PENDING)
        {
            if (WalkState)
            {
                ACPI_INFO ((
                    "Marking method %4.4s as Serialized "
                    "because of AE_ALREADY_EXISTS error",
                    WalkState->MethodNode->Name.Ascii));
            }

            /*
             * Method tried to create an object twice and was marked as
             * "pending serialized". The probable cause is that the method
             * cannot handle reentrancy.
             *
             * The method was created as NotSerialized, but it tried to create
             * a named object and then blocked, causing the second thread
             * entrance to begin and then fail. Workaround this problem by
             * marking the method permanently as Serialized when the last
             * thread exits here.
             */
            MethodDesc->Method.InfoFlags &=
                ~ACPI_METHOD_SERIALIZED_PENDING;

            MethodDesc->Method.InfoFlags |=
                (ACPI_METHOD_SERIALIZED | ACPI_METHOD_IGNORE_SYNC_LEVEL);
            MethodDesc->Method.SyncLevel = 0;
        }

        /* No more threads, we can free the OwnerId */

        if (!(MethodDesc->Method.InfoFlags & ACPI_METHOD_MODULE_LEVEL))
        {
            AcpiUtReleaseOwnerId (&MethodDesc->Method.OwnerId);
        }
    }

    AcpiExStopTraceMethod ((ACPI_NAMESPACE_NODE *) MethodDesc->Method.Node,
        MethodDesc, WalkState);

    return_VOID;
}

