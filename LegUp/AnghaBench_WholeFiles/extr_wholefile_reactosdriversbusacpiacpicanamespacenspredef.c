#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_36__   TYPE_9__ ;
typedef  struct TYPE_35__   TYPE_8__ ;
typedef  struct TYPE_34__   TYPE_7__ ;
typedef  struct TYPE_33__   TYPE_6__ ;
typedef  struct TYPE_32__   TYPE_5__ ;
typedef  struct TYPE_31__   TYPE_4__ ;
typedef  struct TYPE_30__   TYPE_3__ ;
typedef  struct TYPE_29__   TYPE_2__ ;
typedef  struct TYPE_28__   TYPE_1__ ;

/* Type definitions */
typedef  scalar_t__ UINT32 ;
struct TYPE_36__ {int ReturnFlags; scalar_t__ ReturnBtype; int /*<<< orphan*/  NodeFlags; int /*<<< orphan*/  FullPathname; TYPE_7__* ParentPackage; TYPE_6__* Predefined; } ;
struct TYPE_35__ {int /*<<< orphan*/  Flags; } ;
struct TYPE_32__ {scalar_t__ Type; } ;
struct TYPE_31__ {scalar_t__ Class; } ;
struct TYPE_29__ {int /*<<< orphan*/  Ascii; } ;
struct TYPE_30__ {int /*<<< orphan*/  Type; TYPE_2__ Name; } ;
struct TYPE_34__ {TYPE_5__ Common; TYPE_4__ Reference; TYPE_3__ Node; } ;
struct TYPE_28__ {scalar_t__ ExpectedBtypes; } ;
struct TYPE_33__ {TYPE_1__ Info; } ;
typedef  scalar_t__ ACPI_STATUS ;
typedef  TYPE_6__ ACPI_PREDEFINED_INFO ;
typedef  TYPE_7__ ACPI_OPERAND_OBJECT ;
typedef  TYPE_8__ ACPI_NAMESPACE_NODE ;
typedef  TYPE_9__ ACPI_EVALUATE_INFO ;

/* Variables and functions */
 scalar_t__ ACPI_DESC_TYPE_NAMED ; 
 scalar_t__ ACPI_FAILURE (scalar_t__) ; 
 scalar_t__ ACPI_GET_DESCRIPTOR_TYPE (TYPE_7__*) ; 
 scalar_t__ ACPI_NOT_PACKAGE_ELEMENT ; 
 int ACPI_OBJECT_REPAIRED ; 
 scalar_t__ ACPI_REFCLASS_NAME ; 
 scalar_t__ ACPI_RTYPE_ALL ; 
 scalar_t__ ACPI_RTYPE_ANY ; 
 scalar_t__ ACPI_RTYPE_BUFFER ; 
 scalar_t__ ACPI_RTYPE_INTEGER ; 
 scalar_t__ ACPI_RTYPE_NONE ; 
 scalar_t__ ACPI_RTYPE_PACKAGE ; 
 scalar_t__ ACPI_RTYPE_REFERENCE ; 
 scalar_t__ ACPI_RTYPE_STRING ; 
 scalar_t__ ACPI_SUCCESS (scalar_t__) ; 
#define  ACPI_TYPE_BUFFER 132 
#define  ACPI_TYPE_INTEGER 131 
#define  ACPI_TYPE_LOCAL_REFERENCE 130 
#define  ACPI_TYPE_PACKAGE 129 
#define  ACPI_TYPE_STRING 128 
 int /*<<< orphan*/  ACPI_WARN_PREDEFINED (int /*<<< orphan*/ ) ; 
 scalar_t__ AE_AML_OPERAND_TYPE ; 
 scalar_t__ AE_AML_OPERAND_VALUE ; 
 scalar_t__ AE_CTRL_RETURN_VALUE ; 
 int /*<<< orphan*/  AE_INFO ; 
 scalar_t__ AE_OK ; 
 int /*<<< orphan*/  ANOBJ_EVALUATED ; 
 scalar_t__ AcpiGbl_DisableAutoRepair ; 
 scalar_t__ AcpiNsCheckObjectType (TYPE_9__*,TYPE_7__**,scalar_t__,scalar_t__) ; 
 scalar_t__ AcpiNsCheckPackage (TYPE_9__*,TYPE_7__**) ; 
static  scalar_t__ AcpiNsCheckReference (TYPE_9__*,TYPE_7__*) ; 
 scalar_t__ AcpiNsComplexRepairs (TYPE_9__*,TYPE_8__*,scalar_t__,TYPE_7__**) ; 
static  scalar_t__ AcpiNsGetBitmappedType (TYPE_7__*) ; 
 scalar_t__ AcpiNsSimpleRepair (TYPE_9__*,scalar_t__,scalar_t__,TYPE_7__**) ; 
 int /*<<< orphan*/  AcpiUtGetExpectedReturnTypes (char*,scalar_t__) ; 
 int /*<<< orphan*/  AcpiUtGetObjectTypeName (TYPE_7__*) ; 
 int /*<<< orphan*/  AcpiUtGetReferenceName (TYPE_7__*) ; 
 int /*<<< orphan*/  AcpiUtGetTypeName (int /*<<< orphan*/ ) ; 

ACPI_STATUS
AcpiNsCheckReturnValue (
    ACPI_NAMESPACE_NODE         *Node,
    ACPI_EVALUATE_INFO          *Info,
    UINT32                      UserParamCount,
    ACPI_STATUS                 ReturnStatus,
    ACPI_OPERAND_OBJECT         **ReturnObjectPtr)
{
    ACPI_STATUS                 Status;
    const ACPI_PREDEFINED_INFO  *Predefined;


    /* If not a predefined name, we cannot validate the return object */

    Predefined = Info->Predefined;
    if (!Predefined)
    {
        return (AE_OK);
    }

    /*
     * If the method failed or did not actually return an object, we cannot
     * validate the return object
     */
    if ((ReturnStatus != AE_OK) &&
        (ReturnStatus != AE_CTRL_RETURN_VALUE))
    {
        return (AE_OK);
    }

    /*
     * Return value validation and possible repair.
     *
     * 1) Don't perform return value validation/repair if this feature
     * has been disabled via a global option.
     *
     * 2) We have a return value, but if one wasn't expected, just exit,
     * this is not a problem. For example, if the "Implicit Return"
     * feature is enabled, methods will always return a value.
     *
     * 3) If the return value can be of any type, then we cannot perform
     * any validation, just exit.
     */
    if (AcpiGbl_DisableAutoRepair ||
        (!Predefined->Info.ExpectedBtypes) ||
        (Predefined->Info.ExpectedBtypes == ACPI_RTYPE_ALL))
    {
        return (AE_OK);
    }

    /*
     * Check that the type of the main return object is what is expected
     * for this predefined name
     */
    Status = AcpiNsCheckObjectType (Info, ReturnObjectPtr,
        Predefined->Info.ExpectedBtypes, ACPI_NOT_PACKAGE_ELEMENT);
    if (ACPI_FAILURE (Status))
    {
        goto Exit;
    }

    /*
     *
     * 4) If there is no return value and it is optional, just return
     * AE_OK (_WAK).
     */
    if (!(*ReturnObjectPtr))
    {
        goto Exit;
    }

    /*
     * For returned Package objects, check the type of all sub-objects.
     * Note: Package may have been newly created by call above.
     */
    if ((*ReturnObjectPtr)->Common.Type == ACPI_TYPE_PACKAGE)
    {
        Info->ParentPackage = *ReturnObjectPtr;
        Status = AcpiNsCheckPackage (Info, ReturnObjectPtr);
        if (ACPI_FAILURE (Status))
        {
            /* We might be able to fix some errors */

            if ((Status != AE_AML_OPERAND_TYPE) &&
                (Status != AE_AML_OPERAND_VALUE))
            {
                goto Exit;
            }
        }
    }

    /*
     * The return object was OK, or it was successfully repaired above.
     * Now make some additional checks such as verifying that package
     * objects are sorted correctly (if required) or buffer objects have
     * the correct data width (bytes vs. dwords). These repairs are
     * performed on a per-name basis, i.e., the code is specific to
     * particular predefined names.
     */
    Status = AcpiNsComplexRepairs (Info, Node, Status, ReturnObjectPtr);

Exit:
    /*
     * If the object validation failed or if we successfully repaired one
     * or more objects, mark the parent node to suppress further warning
     * messages during the next evaluation of the same method/object.
     */
    if (ACPI_FAILURE (Status) ||
       (Info->ReturnFlags & ACPI_OBJECT_REPAIRED))
    {
        Node->Flags |= ANOBJ_EVALUATED;
    }

    return (Status);
}

ACPI_STATUS
AcpiNsCheckObjectType (
    ACPI_EVALUATE_INFO          *Info,
    ACPI_OPERAND_OBJECT         **ReturnObjectPtr,
    UINT32                      ExpectedBtypes,
    UINT32                      PackageIndex)
{
    ACPI_OPERAND_OBJECT         *ReturnObject = *ReturnObjectPtr;
    ACPI_STATUS                 Status = AE_OK;
    char                        TypeBuffer[96]; /* Room for 10 types */


    /* A Namespace node should not get here, but make sure */

    if (ReturnObject &&
        ACPI_GET_DESCRIPTOR_TYPE (ReturnObject) == ACPI_DESC_TYPE_NAMED)
    {
        ACPI_WARN_PREDEFINED ((AE_INFO, Info->FullPathname, Info->NodeFlags,
            "Invalid return type - Found a Namespace node [%4.4s] type %s",
            ReturnObject->Node.Name.Ascii,
            AcpiUtGetTypeName (ReturnObject->Node.Type)));
        return (AE_AML_OPERAND_TYPE);
    }

    /*
     * Convert the object type (ACPI_TYPE_xxx) to a bitmapped object type.
     * The bitmapped type allows multiple possible return types.
     *
     * Note, the cases below must handle all of the possible types returned
     * from all of the predefined names (including elements of returned
     * packages)
     */
    Info->ReturnBtype = AcpiNsGetBitmappedType (ReturnObject);
    if (Info->ReturnBtype == ACPI_RTYPE_ANY)
    {
        /* Not one of the supported objects, must be incorrect */
        goto TypeErrorExit;
    }

    /* For reference objects, check that the reference type is correct */

    if ((Info->ReturnBtype & ExpectedBtypes) == ACPI_RTYPE_REFERENCE)
    {
        Status = AcpiNsCheckReference (Info, ReturnObject);
        return (Status);
    }

    /* Attempt simple repair of the returned object if necessary */

    Status = AcpiNsSimpleRepair (Info, ExpectedBtypes,
        PackageIndex, ReturnObjectPtr);
    if (ACPI_SUCCESS (Status))
    {
        return (AE_OK); /* Successful repair */
    }


TypeErrorExit:

    /* Create a string with all expected types for this predefined object */

    AcpiUtGetExpectedReturnTypes (TypeBuffer, ExpectedBtypes);

    if (!ReturnObject)
    {
        ACPI_WARN_PREDEFINED ((AE_INFO, Info->FullPathname, Info->NodeFlags,
            "Expected return object of type %s",
            TypeBuffer));
    }
    else if (PackageIndex == ACPI_NOT_PACKAGE_ELEMENT)
    {
        ACPI_WARN_PREDEFINED ((AE_INFO, Info->FullPathname, Info->NodeFlags,
            "Return type mismatch - found %s, expected %s",
            AcpiUtGetObjectTypeName (ReturnObject), TypeBuffer));
    }
    else
    {
        ACPI_WARN_PREDEFINED ((AE_INFO, Info->FullPathname, Info->NodeFlags,
            "Return Package type mismatch at index %u - "
            "found %s, expected %s", PackageIndex,
            AcpiUtGetObjectTypeName (ReturnObject), TypeBuffer));
    }

    return (AE_AML_OPERAND_TYPE);
}

__attribute__((used)) static ACPI_STATUS
AcpiNsCheckReference (
    ACPI_EVALUATE_INFO          *Info,
    ACPI_OPERAND_OBJECT         *ReturnObject)
{

    /*
     * Check the reference object for the correct reference type (opcode).
     * The only type of reference that can be converted to an ACPI_OBJECT is
     * a reference to a named object (reference class: NAME)
     */
    if (ReturnObject->Reference.Class == ACPI_REFCLASS_NAME)
    {
        return (AE_OK);
    }

    ACPI_WARN_PREDEFINED ((AE_INFO, Info->FullPathname, Info->NodeFlags,
        "Return type mismatch - unexpected reference object type [%s] %2.2X",
        AcpiUtGetReferenceName (ReturnObject),
        ReturnObject->Reference.Class));

    return (AE_AML_OPERAND_TYPE);
}

__attribute__((used)) static UINT32
AcpiNsGetBitmappedType (
    ACPI_OPERAND_OBJECT         *ReturnObject)
{
    UINT32                      ReturnBtype;


    if (!ReturnObject)
    {
        return (ACPI_RTYPE_NONE);
    }

    /* Map ACPI_OBJECT_TYPE to internal bitmapped type */

    switch (ReturnObject->Common.Type)
    {
    case ACPI_TYPE_INTEGER:

        ReturnBtype = ACPI_RTYPE_INTEGER;
        break;

    case ACPI_TYPE_BUFFER:

        ReturnBtype = ACPI_RTYPE_BUFFER;
        break;

    case ACPI_TYPE_STRING:

        ReturnBtype = ACPI_RTYPE_STRING;
        break;

    case ACPI_TYPE_PACKAGE:

        ReturnBtype = ACPI_RTYPE_PACKAGE;
        break;

    case ACPI_TYPE_LOCAL_REFERENCE:

        ReturnBtype = ACPI_RTYPE_REFERENCE;
        break;

    default:

        /* Not one of the supported objects, must be incorrect */

        ReturnBtype = ACPI_RTYPE_ANY;
        break;
    }

    return (ReturnBtype);
}

