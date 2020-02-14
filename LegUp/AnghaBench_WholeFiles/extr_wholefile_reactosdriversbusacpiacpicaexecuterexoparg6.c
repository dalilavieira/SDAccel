#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_17__   TYPE_4__ ;
typedef  struct TYPE_16__   TYPE_3__ ;
typedef  struct TYPE_15__   TYPE_2__ ;
typedef  struct TYPE_14__   TYPE_1__ ;

/* Type definitions */
typedef  size_t UINT64 ;
typedef  int UINT32 ;
struct TYPE_15__ {size_t Value; } ;
struct TYPE_14__ {size_t Count; TYPE_4__** Elements; } ;
struct TYPE_17__ {TYPE_2__ Integer; TYPE_1__ Package; } ;
struct TYPE_16__ {int Opcode; TYPE_4__* ResultObj; TYPE_4__** Operands; } ;
typedef  void* BOOLEAN ;
typedef  TYPE_3__ ACPI_WALK_STATE ;
typedef  int /*<<< orphan*/  ACPI_STATUS ;
typedef  TYPE_4__ ACPI_OPERAND_OBJECT ;

/* Variables and functions */
 int /*<<< orphan*/  ACPI_ERROR (int /*<<< orphan*/ ) ; 
 scalar_t__ ACPI_FAILURE (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ACPI_FORMAT_UINT64 (size_t) ; 
 int /*<<< orphan*/  ACPI_FUNCTION_TRACE_STR (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ACPI_UINT64_MAX ; 
 int /*<<< orphan*/  AE_AML_BAD_OPCODE ; 
 int /*<<< orphan*/  AE_AML_OPERAND_VALUE ; 
 int /*<<< orphan*/  AE_AML_PACKAGE_LIMIT ; 
 int /*<<< orphan*/  AE_INFO ; 
 int /*<<< orphan*/  AE_NO_MEMORY ; 
 int /*<<< orphan*/  AE_OK ; 
#define  AML_LOAD_TABLE_OP 135 
 int /*<<< orphan*/  AML_LOGICAL_EQUAL_OP ; 
 int /*<<< orphan*/  AML_LOGICAL_GREATER_OP ; 
 int /*<<< orphan*/  AML_LOGICAL_LESS_OP ; 
#define  AML_MATCH_OP 134 
 int /*<<< orphan*/  AcpiExDoLogicalOp (int /*<<< orphan*/ ,TYPE_4__*,TYPE_4__*,void**) ; 
 int /*<<< orphan*/  AcpiExLoadTableOp (TYPE_3__*,TYPE_4__**) ; 
 int /*<<< orphan*/  AcpiPsGetOpcodeName (int) ; 
 TYPE_4__* AcpiUtCreateIntegerObject (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  AcpiUtRemoveReference (TYPE_4__*) ; 
 int /*<<< orphan*/  ExOpcode_6A_0T_1R ; 
 void* FALSE ; 
#define  MATCH_MEQ 133 
#define  MATCH_MGE 132 
#define  MATCH_MGT 131 
#define  MATCH_MLE 130 
#define  MATCH_MLT 129 
#define  MATCH_MTR 128 
 size_t MAX_MATCH_OPERATOR ; 
 void* TRUE ; 
 int /*<<< orphan*/  return_ACPI_STATUS (int /*<<< orphan*/ ) ; 

__attribute__((used)) static BOOLEAN
AcpiExDoMatch (
    UINT32                  MatchOp,
    ACPI_OPERAND_OBJECT     *PackageObj,
    ACPI_OPERAND_OBJECT     *MatchObj)
{
    BOOLEAN                 LogicalResult = TRUE;
    ACPI_STATUS             Status;


    /*
     * Note: Since the PackageObj/MatchObj ordering is opposite to that of
     * the standard logical operators, we have to reverse them when we call
     * DoLogicalOp in order to make the implicit conversion rules work
     * correctly. However, this means we have to flip the entire equation
     * also. A bit ugly perhaps, but overall, better than fussing the
     * parameters around at runtime, over and over again.
     *
     * Below, P[i] refers to the package element, M refers to the Match object.
     */
    switch (MatchOp)
    {
    case MATCH_MTR:

        /* Always true */

        break;

    case MATCH_MEQ:
        /*
         * True if equal: (P[i] == M)
         * Change to:     (M == P[i])
         */
        Status = AcpiExDoLogicalOp (
            AML_LOGICAL_EQUAL_OP, MatchObj, PackageObj, &LogicalResult);
        if (ACPI_FAILURE (Status))
        {
            return (FALSE);
        }
        break;

    case MATCH_MLE:
        /*
         * True if less than or equal: (P[i] <= M) (P[i] NotGreater than M)
         * Change to:                  (M >= P[i]) (M NotLess than P[i])
         */
        Status = AcpiExDoLogicalOp (
            AML_LOGICAL_LESS_OP, MatchObj, PackageObj, &LogicalResult);
        if (ACPI_FAILURE (Status))
        {
            return (FALSE);
        }
        LogicalResult = (BOOLEAN) !LogicalResult;
        break;

    case MATCH_MLT:
        /*
         * True if less than: (P[i] < M)
         * Change to:         (M > P[i])
         */
        Status = AcpiExDoLogicalOp (
            AML_LOGICAL_GREATER_OP, MatchObj, PackageObj, &LogicalResult);
        if (ACPI_FAILURE (Status))
        {
            return (FALSE);
        }
        break;

    case MATCH_MGE:
        /*
         * True if greater than or equal: (P[i] >= M) (P[i] NotLess than M)
         * Change to:                     (M <= P[i]) (M NotGreater than P[i])
         */
        Status = AcpiExDoLogicalOp (
            AML_LOGICAL_GREATER_OP, MatchObj, PackageObj, &LogicalResult);
        if (ACPI_FAILURE (Status))
        {
            return (FALSE);
        }
        LogicalResult = (BOOLEAN)!LogicalResult;
        break;

    case MATCH_MGT:
        /*
         * True if greater than: (P[i] > M)
         * Change to:            (M < P[i])
         */
        Status = AcpiExDoLogicalOp (
            AML_LOGICAL_LESS_OP, MatchObj, PackageObj, &LogicalResult);
        if (ACPI_FAILURE (Status))
        {
            return (FALSE);
        }
        break;

    default:

        /* Undefined */

        return (FALSE);
    }

    return (LogicalResult);
}

ACPI_STATUS
AcpiExOpcode_6A_0T_1R (
    ACPI_WALK_STATE         *WalkState)
{
    ACPI_OPERAND_OBJECT     **Operand = &WalkState->Operands[0];
    ACPI_OPERAND_OBJECT     *ReturnDesc = NULL;
    ACPI_STATUS             Status = AE_OK;
    UINT64                  Index;
    ACPI_OPERAND_OBJECT     *ThisElement;


    ACPI_FUNCTION_TRACE_STR (ExOpcode_6A_0T_1R,
        AcpiPsGetOpcodeName (WalkState->Opcode));


    switch (WalkState->Opcode)
    {
    case AML_MATCH_OP:
        /*
         * Match (SearchPkg[0], MatchOp1[1], MatchObj1[2],
         *                      MatchOp2[3], MatchObj2[4], StartIndex[5])
         */

        /* Validate both Match Term Operators (MTR, MEQ, etc.) */

        if ((Operand[1]->Integer.Value > MAX_MATCH_OPERATOR) ||
            (Operand[3]->Integer.Value > MAX_MATCH_OPERATOR))
        {
            ACPI_ERROR ((AE_INFO, "Match operator out of range"));
            Status = AE_AML_OPERAND_VALUE;
            goto Cleanup;
        }

        /* Get the package StartIndex, validate against the package length */

        Index = Operand[5]->Integer.Value;
        if (Index >= Operand[0]->Package.Count)
        {
            ACPI_ERROR ((AE_INFO,
                "Index (0x%8.8X%8.8X) beyond package end (0x%X)",
                ACPI_FORMAT_UINT64 (Index), Operand[0]->Package.Count));
            Status = AE_AML_PACKAGE_LIMIT;
            goto Cleanup;
        }

        /* Create an integer for the return value */
        /* Default return value is ACPI_UINT64_MAX if no match found */

        ReturnDesc = AcpiUtCreateIntegerObject (ACPI_UINT64_MAX);
        if (!ReturnDesc)
        {
            Status = AE_NO_MEMORY;
            goto Cleanup;

        }

        /*
         * Examine each element until a match is found. Both match conditions
         * must be satisfied for a match to occur. Within the loop,
         * "continue" signifies that the current element does not match
         * and the next should be examined.
         *
         * Upon finding a match, the loop will terminate via "break" at
         * the bottom. If it terminates "normally", MatchValue will be
         * ACPI_UINT64_MAX (Ones) (its initial value) indicating that no
         * match was found.
         */
        for ( ; Index < Operand[0]->Package.Count; Index++)
        {
            /* Get the current package element */

            ThisElement = Operand[0]->Package.Elements[Index];

            /* Treat any uninitialized (NULL) elements as non-matching */

            if (!ThisElement)
            {
                continue;
            }

            /*
             * Both match conditions must be satisfied. Execution of a continue
             * (proceed to next iteration of enclosing for loop) signifies a
             * non-match.
             */
            if (!AcpiExDoMatch ((UINT32) Operand[1]->Integer.Value,
                    ThisElement, Operand[2]))
            {
                continue;
            }

            if (!AcpiExDoMatch ((UINT32) Operand[3]->Integer.Value,
                    ThisElement, Operand[4]))
            {
                continue;
            }

            /* Match found: Index is the return value */

            ReturnDesc->Integer.Value = Index;
            break;
        }
        break;

    case AML_LOAD_TABLE_OP:

        Status = AcpiExLoadTableOp (WalkState, &ReturnDesc);
        break;

    default:

        ACPI_ERROR ((AE_INFO, "Unknown AML opcode 0x%X",
            WalkState->Opcode));

        Status = AE_AML_BAD_OPCODE;
        goto Cleanup;
    }


Cleanup:

    /* Delete return object on error */

    if (ACPI_FAILURE (Status))
    {
        AcpiUtRemoveReference (ReturnDesc);
    }

    /* Save return object on success */

    else
    {
        WalkState->ResultObj = ReturnDesc;
    }

    return_ACPI_STATUS (Status);
}

