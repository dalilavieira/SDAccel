#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_60__   TYPE_9__ ;
typedef  struct TYPE_59__   TYPE_8__ ;
typedef  struct TYPE_58__   TYPE_7__ ;
typedef  struct TYPE_57__   TYPE_6__ ;
typedef  struct TYPE_56__   TYPE_5__ ;
typedef  struct TYPE_55__   TYPE_4__ ;
typedef  struct TYPE_54__   TYPE_3__ ;
typedef  struct TYPE_53__   TYPE_2__ ;
typedef  struct TYPE_52__   TYPE_1__ ;
typedef  struct TYPE_51__   TYPE_10__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  UINT8 ;
typedef  size_t UINT32 ;
struct TYPE_54__ {TYPE_9__* Next; int /*<<< orphan*/  DescriptorType; } ;
struct TYPE_52__ {int /*<<< orphan*/ ** ObjDesc; } ;
struct TYPE_60__ {TYPE_3__ Common; TYPE_1__ Results; } ;
struct TYPE_59__ {int /*<<< orphan*/  Type; } ;
struct TYPE_53__ {TYPE_8__* Node; TYPE_7__* Parent; } ;
struct TYPE_58__ {TYPE_2__ Common; } ;
struct TYPE_57__ {scalar_t__ Scope; TYPE_8__* StartNode; TYPE_7__* StartOp; int /*<<< orphan*/ * PkgEnd; int /*<<< orphan*/ * AmlEnd; int /*<<< orphan*/ * AmlStart; int /*<<< orphan*/ * Aml; } ;
struct TYPE_56__ {TYPE_4__* WalkStateList; } ;
struct TYPE_55__ {scalar_t__ ResultCount; scalar_t__ ResultSize; scalar_t__ NumOperands; size_t OperandIndex; scalar_t__ DescriptorType; TYPE_9__* Results; TYPE_9__* ScopeInfo; TYPE_9__* ControlState; TYPE_6__ ParserState; int /*<<< orphan*/  Params; int /*<<< orphan*/ * MethodDesc; TYPE_8__* MethodNode; int /*<<< orphan*/  WalkType; int /*<<< orphan*/ * CallerReturnDesc; int /*<<< orphan*/  PassNumber; int /*<<< orphan*/ * NextOp; TYPE_5__* Thread; TYPE_7__* Origin; int /*<<< orphan*/  OwnerId; struct TYPE_55__* Next; int /*<<< orphan*/ ** Operands; int /*<<< orphan*/  CurrentResult; } ;
struct TYPE_51__ {int /*<<< orphan*/  ReturnObject; int /*<<< orphan*/  Parameters; } ;
typedef  size_t INT32 ;
typedef  TYPE_4__ ACPI_WALK_STATE ;
typedef  TYPE_5__ ACPI_THREAD_STATE ;
typedef  int /*<<< orphan*/  ACPI_STATUS ;
typedef  TYPE_6__ ACPI_PARSE_STATE ;
typedef  TYPE_7__ ACPI_PARSE_OBJECT ;
typedef  int /*<<< orphan*/  ACPI_OWNER_ID ;
typedef  int /*<<< orphan*/  ACPI_OPERAND_OBJECT ;
typedef  TYPE_8__ ACPI_NAMESPACE_NODE ;
typedef  TYPE_9__ ACPI_GENERIC_STATE ;
typedef  TYPE_10__ ACPI_EVALUATE_INFO ;

/* Variables and functions */
 TYPE_4__* ACPI_ALLOCATE_ZEROED (int) ; 
 int /*<<< orphan*/  ACPI_DB_EXEC ; 
 int /*<<< orphan*/  ACPI_DB_PARSE ; 
 int /*<<< orphan*/  ACPI_DEBUG_PRINT (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ACPI_DESC_TYPE_STATE_RESULT ; 
 scalar_t__ ACPI_DESC_TYPE_WALK ; 
 int /*<<< orphan*/  ACPI_ERROR (int /*<<< orphan*/ ) ; 
 scalar_t__ ACPI_FAILURE (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ACPI_FREE (TYPE_4__*) ; 
 int /*<<< orphan*/  ACPI_FUNCTION_NAME (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ACPI_FUNCTION_TRACE (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ACPI_FUNCTION_TRACE_PTR (int /*<<< orphan*/ ,TYPE_4__*) ; 
 int /*<<< orphan*/  ACPI_METHOD_NUM_ARGS ; 
 scalar_t__ ACPI_OBJ_NUM_OPERANDS ; 
 size_t ACPI_RESULTS_FRAME_OBJ_NUM ; 
 size_t ACPI_RESULTS_OBJ_NUM_MAX ; 
 int /*<<< orphan*/  ACPI_TYPE_METHOD ; 
 int /*<<< orphan*/  ACPI_WALK_METHOD ; 
 int /*<<< orphan*/  AE_AML_INTERNAL ; 
 int /*<<< orphan*/  AE_AML_NO_OPERAND ; 
 int /*<<< orphan*/  AE_AML_NO_RETURN_VALUE ; 
 int /*<<< orphan*/  AE_BAD_PARAMETER ; 
 int /*<<< orphan*/  AE_INFO ; 
 int /*<<< orphan*/  AE_NO_MEMORY ; 
 int /*<<< orphan*/  AE_OK ; 
 int /*<<< orphan*/  AE_STACK_OVERFLOW ; 
 int /*<<< orphan*/  AE_STACK_UNDERFLOW ; 
 int /*<<< orphan*/  AcpiDsInitCallbacks (TYPE_4__*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  AcpiDsMethodDataInit (TYPE_4__*) ; 
 int /*<<< orphan*/  AcpiDsMethodDataInitArgs (int /*<<< orphan*/ ,int /*<<< orphan*/ ,TYPE_4__*) ; 
static  int /*<<< orphan*/  AcpiDsResultStackPop (TYPE_4__*) ; 
static  int /*<<< orphan*/  AcpiDsResultStackPush (TYPE_4__*) ; 
 int /*<<< orphan*/  AcpiDsScopeStackPush (TYPE_8__*,int /*<<< orphan*/ ,TYPE_4__*) ; 
 int /*<<< orphan*/ * AcpiNsGetAttachedObject (TYPE_8__*) ; 
 int /*<<< orphan*/  AcpiPsCleanupScope (TYPE_6__*) ; 
 int /*<<< orphan*/  AcpiPsInitScope (TYPE_6__*,TYPE_7__*) ; 
 TYPE_9__* AcpiUtCreateGenericState () ; 
 int /*<<< orphan*/  AcpiUtDeleteGenericState (TYPE_9__*) ; 
 int /*<<< orphan*/  AcpiUtGetObjectTypeName (int /*<<< orphan*/ *) ; 
 TYPE_9__* AcpiUtPopGenericState (TYPE_9__**) ; 
 int /*<<< orphan*/  AcpiUtPushGenericState (TYPE_9__**,TYPE_9__*) ; 
 int /*<<< orphan*/  AcpiUtRemoveReference (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  DsCreateWalkState ; 
 int /*<<< orphan*/  DsDeleteWalkState ; 
 int /*<<< orphan*/  DsGetCurrentWalkState ; 
 int /*<<< orphan*/  DsInitAmlWalk ; 
 int /*<<< orphan*/  DsObjStackPop ; 
 int /*<<< orphan*/  DsObjStackPopAndDelete ; 
 int /*<<< orphan*/  DsObjStackPush ; 
 int /*<<< orphan*/  DsPopWalkState ; 
 int /*<<< orphan*/  DsPushWalkState ; 
 int /*<<< orphan*/  DsResultPop ; 
 int /*<<< orphan*/  DsResultPush ; 
 int /*<<< orphan*/  DsResultStackPop ; 
 int /*<<< orphan*/  DsResultStackPush ; 
 int /*<<< orphan*/  return_ACPI_STATUS (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  return_PTR (TYPE_4__*) ; 
 int /*<<< orphan*/  return_VOID ; 

ACPI_STATUS
AcpiDsResultPop (
    ACPI_OPERAND_OBJECT     **Object,
    ACPI_WALK_STATE         *WalkState)
{
    UINT32                  Index;
    ACPI_GENERIC_STATE      *State;
    ACPI_STATUS             Status;


    ACPI_FUNCTION_NAME (DsResultPop);


    State = WalkState->Results;

    /* Incorrect state of result stack */

    if (State && !WalkState->ResultCount)
    {
        ACPI_ERROR ((AE_INFO, "No results on result stack"));
        return (AE_AML_INTERNAL);
    }

    if (!State && WalkState->ResultCount)
    {
        ACPI_ERROR ((AE_INFO, "No result state for result stack"));
        return (AE_AML_INTERNAL);
    }

    /* Empty result stack */

    if (!State)
    {
        ACPI_ERROR ((AE_INFO, "Result stack is empty! State=%p", WalkState));
        return (AE_AML_NO_RETURN_VALUE);
    }

    /* Return object of the top element and clean that top element result stack */

    WalkState->ResultCount--;
    Index = (UINT32) WalkState->ResultCount % ACPI_RESULTS_FRAME_OBJ_NUM;

    *Object = State->Results.ObjDesc [Index];
    if (!*Object)
    {
        ACPI_ERROR ((AE_INFO, "No result objects on result stack, State=%p",
            WalkState));
        return (AE_AML_NO_RETURN_VALUE);
    }

    State->Results.ObjDesc [Index] = NULL;
    if (Index == 0)
    {
        Status = AcpiDsResultStackPop (WalkState);
        if (ACPI_FAILURE (Status))
        {
            return (Status);
        }
    }

    ACPI_DEBUG_PRINT ((ACPI_DB_EXEC,
        "Obj=%p [%s] Index=%X State=%p Num=%X\n", *Object,
        AcpiUtGetObjectTypeName (*Object),
        Index, WalkState, WalkState->ResultCount));

    return (AE_OK);
}

ACPI_STATUS
AcpiDsResultPush (
    ACPI_OPERAND_OBJECT     *Object,
    ACPI_WALK_STATE         *WalkState)
{
    ACPI_GENERIC_STATE      *State;
    ACPI_STATUS             Status;
    UINT32                  Index;


    ACPI_FUNCTION_NAME (DsResultPush);


    if (WalkState->ResultCount > WalkState->ResultSize)
    {
        ACPI_ERROR ((AE_INFO, "Result stack is full"));
        return (AE_AML_INTERNAL);
    }
    else if (WalkState->ResultCount == WalkState->ResultSize)
    {
        /* Extend the result stack */

        Status = AcpiDsResultStackPush (WalkState);
        if (ACPI_FAILURE (Status))
        {
            ACPI_ERROR ((AE_INFO, "Failed to extend the result stack"));
            return (Status);
        }
    }

    if (!(WalkState->ResultCount < WalkState->ResultSize))
    {
        ACPI_ERROR ((AE_INFO, "No free elements in result stack"));
        return (AE_AML_INTERNAL);
    }

    State = WalkState->Results;
    if (!State)
    {
        ACPI_ERROR ((AE_INFO, "No result stack frame during push"));
        return (AE_AML_INTERNAL);
    }

    if (!Object)
    {
        ACPI_ERROR ((AE_INFO,
            "Null Object! Obj=%p State=%p Num=%u",
            Object, WalkState, WalkState->ResultCount));
        return (AE_BAD_PARAMETER);
    }

    /* Assign the address of object to the top free element of result stack */

    Index = (UINT32) WalkState->ResultCount % ACPI_RESULTS_FRAME_OBJ_NUM;
    State->Results.ObjDesc [Index] = Object;
    WalkState->ResultCount++;

    ACPI_DEBUG_PRINT ((ACPI_DB_EXEC, "Obj=%p [%s] State=%p Num=%X Cur=%X\n",
        Object, AcpiUtGetObjectTypeName ((ACPI_OPERAND_OBJECT *) Object),
        WalkState, WalkState->ResultCount, WalkState->CurrentResult));

    return (AE_OK);
}

__attribute__((used)) static ACPI_STATUS
AcpiDsResultStackPush (
    ACPI_WALK_STATE         *WalkState)
{
    ACPI_GENERIC_STATE      *State;


    ACPI_FUNCTION_NAME (DsResultStackPush);


    /* Check for stack overflow */

    if (((UINT32) WalkState->ResultSize + ACPI_RESULTS_FRAME_OBJ_NUM) >
        ACPI_RESULTS_OBJ_NUM_MAX)
    {
        ACPI_ERROR ((AE_INFO, "Result stack overflow: State=%p Num=%u",
            WalkState, WalkState->ResultSize));
        return (AE_STACK_OVERFLOW);
    }

    State = AcpiUtCreateGenericState ();
    if (!State)
    {
        return (AE_NO_MEMORY);
    }

    State->Common.DescriptorType = ACPI_DESC_TYPE_STATE_RESULT;
    AcpiUtPushGenericState (&WalkState->Results, State);

    /* Increase the length of the result stack by the length of frame */

    WalkState->ResultSize += ACPI_RESULTS_FRAME_OBJ_NUM;

    ACPI_DEBUG_PRINT ((ACPI_DB_EXEC, "Results=%p State=%p\n",
        State, WalkState));

    return (AE_OK);
}

__attribute__((used)) static ACPI_STATUS
AcpiDsResultStackPop (
    ACPI_WALK_STATE         *WalkState)
{
    ACPI_GENERIC_STATE      *State;


    ACPI_FUNCTION_NAME (DsResultStackPop);


    /* Check for stack underflow */

    if (WalkState->Results == NULL)
    {
        ACPI_DEBUG_PRINT ((ACPI_DB_EXEC,
            "Result stack underflow - State=%p\n", WalkState));
        return (AE_AML_NO_OPERAND);
    }

    if (WalkState->ResultSize < ACPI_RESULTS_FRAME_OBJ_NUM)
    {
        ACPI_ERROR ((AE_INFO, "Insufficient result stack size"));
        return (AE_AML_INTERNAL);
    }

    State = AcpiUtPopGenericState (&WalkState->Results);
    AcpiUtDeleteGenericState (State);

    /* Decrease the length of result stack by the length of frame */

    WalkState->ResultSize -= ACPI_RESULTS_FRAME_OBJ_NUM;

    ACPI_DEBUG_PRINT ((ACPI_DB_EXEC,
        "Result=%p RemainingResults=%X State=%p\n",
        State, WalkState->ResultCount, WalkState));

    return (AE_OK);
}

ACPI_STATUS
AcpiDsObjStackPush (
    void                    *Object,
    ACPI_WALK_STATE         *WalkState)
{
    ACPI_FUNCTION_NAME (DsObjStackPush);


    /* Check for stack overflow */

    if (WalkState->NumOperands >= ACPI_OBJ_NUM_OPERANDS)
    {
        ACPI_ERROR ((AE_INFO,
            "Object stack overflow! Obj=%p State=%p #Ops=%u",
            Object, WalkState, WalkState->NumOperands));
        return (AE_STACK_OVERFLOW);
    }

    /* Put the object onto the stack */

    WalkState->Operands [WalkState->OperandIndex] = Object;
    WalkState->NumOperands++;

    /* For the usual order of filling the operand stack */

    WalkState->OperandIndex++;

    ACPI_DEBUG_PRINT ((ACPI_DB_EXEC, "Obj=%p [%s] State=%p #Ops=%X\n",
        Object, AcpiUtGetObjectTypeName ((ACPI_OPERAND_OBJECT *) Object),
        WalkState, WalkState->NumOperands));

    return (AE_OK);
}

ACPI_STATUS
AcpiDsObjStackPop (
    UINT32                  PopCount,
    ACPI_WALK_STATE         *WalkState)
{
    UINT32                  i;


    ACPI_FUNCTION_NAME (DsObjStackPop);


    for (i = 0; i < PopCount; i++)
    {
        /* Check for stack underflow */

        if (WalkState->NumOperands == 0)
        {
            ACPI_ERROR ((AE_INFO,
                "Object stack underflow! Count=%X State=%p #Ops=%u",
                PopCount, WalkState, WalkState->NumOperands));
            return (AE_STACK_UNDERFLOW);
        }

        /* Just set the stack entry to null */

        WalkState->NumOperands--;
        WalkState->Operands [WalkState->NumOperands] = NULL;
    }

    ACPI_DEBUG_PRINT ((ACPI_DB_EXEC, "Count=%X State=%p #Ops=%u\n",
        PopCount, WalkState, WalkState->NumOperands));

    return (AE_OK);
}

void
AcpiDsObjStackPopAndDelete (
    UINT32                  PopCount,
    ACPI_WALK_STATE         *WalkState)
{
    INT32                   i;
    ACPI_OPERAND_OBJECT     *ObjDesc;


    ACPI_FUNCTION_NAME (DsObjStackPopAndDelete);


    if (PopCount == 0)
    {
        return;
    }

    for (i = (INT32) PopCount - 1; i >= 0; i--)
    {
        if (WalkState->NumOperands == 0)
        {
            return;
        }

        /* Pop the stack and delete an object if present in this stack entry */

        WalkState->NumOperands--;
        ObjDesc = WalkState->Operands [i];
        if (ObjDesc)
        {
            AcpiUtRemoveReference (WalkState->Operands [i]);
            WalkState->Operands [i] = NULL;
        }
    }

    ACPI_DEBUG_PRINT ((ACPI_DB_EXEC, "Count=%X State=%p #Ops=%X\n",
        PopCount, WalkState, WalkState->NumOperands));
}

ACPI_WALK_STATE *
AcpiDsGetCurrentWalkState (
    ACPI_THREAD_STATE       *Thread)
{
    ACPI_FUNCTION_NAME (DsGetCurrentWalkState);


    if (!Thread)
    {
        return (NULL);
    }

    ACPI_DEBUG_PRINT ((ACPI_DB_PARSE, "Current WalkState %p\n",
        Thread->WalkStateList));

    return (Thread->WalkStateList);
}

void
AcpiDsPushWalkState (
    ACPI_WALK_STATE         *WalkState,
    ACPI_THREAD_STATE       *Thread)
{
    ACPI_FUNCTION_TRACE (DsPushWalkState);


    WalkState->Next = Thread->WalkStateList;
    Thread->WalkStateList = WalkState;

    return_VOID;
}

ACPI_WALK_STATE *
AcpiDsPopWalkState (
    ACPI_THREAD_STATE       *Thread)
{
    ACPI_WALK_STATE         *WalkState;


    ACPI_FUNCTION_TRACE (DsPopWalkState);


    WalkState = Thread->WalkStateList;

    if (WalkState)
    {
        /* Next walk state becomes the current walk state */

        Thread->WalkStateList = WalkState->Next;

        /*
         * Don't clear the NEXT field, this serves as an indicator
         * that there is a parent WALK STATE
         * Do Not: WalkState->Next = NULL;
         */
    }

    return_PTR (WalkState);
}

ACPI_WALK_STATE *
AcpiDsCreateWalkState (
    ACPI_OWNER_ID           OwnerId,
    ACPI_PARSE_OBJECT       *Origin,
    ACPI_OPERAND_OBJECT     *MethodDesc,
    ACPI_THREAD_STATE       *Thread)
{
    ACPI_WALK_STATE         *WalkState;


    ACPI_FUNCTION_TRACE (DsCreateWalkState);


    WalkState = ACPI_ALLOCATE_ZEROED (sizeof (ACPI_WALK_STATE));
    if (!WalkState)
    {
        return_PTR (NULL);
    }

    WalkState->DescriptorType = ACPI_DESC_TYPE_WALK;
    WalkState->MethodDesc = MethodDesc;
    WalkState->OwnerId = OwnerId;
    WalkState->Origin = Origin;
    WalkState->Thread = Thread;

    WalkState->ParserState.StartOp = Origin;

    /* Init the method args/local */

#ifndef ACPI_CONSTANT_EVAL_ONLY
    AcpiDsMethodDataInit (WalkState);
#endif

    /* Put the new state at the head of the walk list */

    if (Thread)
    {
        AcpiDsPushWalkState (WalkState, Thread);
    }

    return_PTR (WalkState);
}

ACPI_STATUS
AcpiDsInitAmlWalk (
    ACPI_WALK_STATE         *WalkState,
    ACPI_PARSE_OBJECT       *Op,
    ACPI_NAMESPACE_NODE     *MethodNode,
    UINT8                   *AmlStart,
    UINT32                  AmlLength,
    ACPI_EVALUATE_INFO      *Info,
    UINT8                   PassNumber)
{
    ACPI_STATUS             Status;
    ACPI_PARSE_STATE        *ParserState = &WalkState->ParserState;
    ACPI_PARSE_OBJECT       *ExtraOp;


    ACPI_FUNCTION_TRACE (DsInitAmlWalk);


    WalkState->ParserState.Aml =
    WalkState->ParserState.AmlStart = AmlStart;
    WalkState->ParserState.AmlEnd =
    WalkState->ParserState.PkgEnd = AmlStart + AmlLength;

    /* The NextOp of the NextWalk will be the beginning of the method */

    WalkState->NextOp = NULL;
    WalkState->PassNumber = PassNumber;

    if (Info)
    {
        WalkState->Params = Info->Parameters;
        WalkState->CallerReturnDesc = &Info->ReturnObject;
    }

    Status = AcpiPsInitScope (&WalkState->ParserState, Op);
    if (ACPI_FAILURE (Status))
    {
        return_ACPI_STATUS (Status);
    }

    if (MethodNode)
    {
        WalkState->ParserState.StartNode = MethodNode;
        WalkState->WalkType = ACPI_WALK_METHOD;
        WalkState->MethodNode = MethodNode;
        WalkState->MethodDesc = AcpiNsGetAttachedObject (MethodNode);

        /* Push start scope on scope stack and make it current  */

        Status = AcpiDsScopeStackPush (
            MethodNode, ACPI_TYPE_METHOD, WalkState);
        if (ACPI_FAILURE (Status))
        {
            return_ACPI_STATUS (Status);
        }

        /* Init the method arguments */

        Status = AcpiDsMethodDataInitArgs (WalkState->Params,
                    ACPI_METHOD_NUM_ARGS, WalkState);
        if (ACPI_FAILURE (Status))
        {
            return_ACPI_STATUS (Status);
        }
    }
    else
    {
        /*
         * Setup the current scope.
         * Find a Named Op that has a namespace node associated with it.
         * search upwards from this Op. Current scope is the first
         * Op with a namespace node.
         */
        ExtraOp = ParserState->StartOp;
        while (ExtraOp && !ExtraOp->Common.Node)
        {
            ExtraOp = ExtraOp->Common.Parent;
        }

        if (!ExtraOp)
        {
            ParserState->StartNode = NULL;
        }
        else
        {
            ParserState->StartNode = ExtraOp->Common.Node;
        }

        if (ParserState->StartNode)
        {
            /* Push start scope on scope stack and make it current  */

            Status = AcpiDsScopeStackPush (ParserState->StartNode,
                ParserState->StartNode->Type, WalkState);
            if (ACPI_FAILURE (Status))
            {
                return_ACPI_STATUS (Status);
            }
        }
    }

    Status = AcpiDsInitCallbacks (WalkState, PassNumber);
    return_ACPI_STATUS (Status);
}

void
AcpiDsDeleteWalkState (
    ACPI_WALK_STATE         *WalkState)
{
    ACPI_GENERIC_STATE      *State;


    ACPI_FUNCTION_TRACE_PTR (DsDeleteWalkState, WalkState);


    if (!WalkState)
    {
        return_VOID;
    }

    if (WalkState->DescriptorType != ACPI_DESC_TYPE_WALK)
    {
        ACPI_ERROR ((AE_INFO, "%p is not a valid walk state",
            WalkState));
        return_VOID;
    }

    /* There should not be any open scopes */

    if (WalkState->ParserState.Scope)
    {
        ACPI_ERROR ((AE_INFO, "%p walk still has a scope list",
            WalkState));
        AcpiPsCleanupScope (&WalkState->ParserState);
    }

    /* Always must free any linked control states */

    while (WalkState->ControlState)
    {
        State = WalkState->ControlState;
        WalkState->ControlState = State->Common.Next;

        AcpiUtDeleteGenericState (State);
    }

    /* Always must free any linked parse states */

    while (WalkState->ScopeInfo)
    {
        State = WalkState->ScopeInfo;
        WalkState->ScopeInfo = State->Common.Next;

        AcpiUtDeleteGenericState (State);
    }

    /* Always must free any stacked result states */

    while (WalkState->Results)
    {
        State = WalkState->Results;
        WalkState->Results = State->Common.Next;

        AcpiUtDeleteGenericState (State);
    }

    ACPI_FREE (WalkState);
    return_VOID;
}

