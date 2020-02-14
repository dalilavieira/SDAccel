#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_45__   TYPE_9__ ;
typedef  struct TYPE_44__   TYPE_8__ ;
typedef  struct TYPE_43__   TYPE_7__ ;
typedef  struct TYPE_42__   TYPE_6__ ;
typedef  struct TYPE_41__   TYPE_5__ ;
typedef  struct TYPE_40__   TYPE_4__ ;
typedef  struct TYPE_39__   TYPE_3__ ;
typedef  struct TYPE_38__   TYPE_2__ ;
typedef  struct TYPE_37__   TYPE_1__ ;

/* Type definitions */
typedef  int UINT8 ;
typedef  int /*<<< orphan*/  UINT64 ;
typedef  int UINT32 ;
struct TYPE_45__ {int ReturnBtype; int ReturnFlags; int /*<<< orphan*/  FullPathname; TYPE_4__* ParentPackage; TYPE_8__* Node; } ;
struct TYPE_37__ {int /*<<< orphan*/  Ascii; } ;
struct TYPE_44__ {TYPE_1__ Name; } ;
struct TYPE_41__ {int Count; TYPE_7__** Elements; } ;
struct TYPE_38__ {int /*<<< orphan*/  ReferenceCount; } ;
struct TYPE_43__ {TYPE_5__ Package; TYPE_2__ Common; } ;
struct TYPE_42__ {int UnexpectedBtypes; scalar_t__ PackageIndex; int /*<<< orphan*/  Name; int /*<<< orphan*/  (* ObjectConverter ) (TYPE_8__*,TYPE_7__*,TYPE_7__**) ;} ;
struct TYPE_39__ {int /*<<< orphan*/  ReferenceCount; } ;
struct TYPE_40__ {TYPE_3__ Common; } ;
typedef  int /*<<< orphan*/  ACPI_STATUS ;
typedef  TYPE_6__ ACPI_SIMPLE_REPAIR_INFO ;
typedef  TYPE_7__ ACPI_OPERAND_OBJECT ;
typedef  TYPE_8__ ACPI_NAMESPACE_NODE ;
typedef  TYPE_9__ ACPI_EVALUATE_INFO ;

/* Variables and functions */
 scalar_t__ ACPI_ALL_PACKAGE_ELEMENTS ; 
 scalar_t__ ACPI_COMPARE_NAMESEG (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ACPI_DB_REPAIR ; 
 int /*<<< orphan*/  ACPI_DEBUG_PRINT (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ACPI_EXCEPTION (int /*<<< orphan*/ ) ; 
 scalar_t__ ACPI_FAILURE (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ACPI_FUNCTION_NAME (int /*<<< orphan*/ ) ; 
 int ACPI_NOT_PACKAGE_ELEMENT ; 
 int ACPI_OBJECT_REPAIRED ; 
 int ACPI_OBJECT_WRAPPED ; 
#define  ACPI_PTYPE1_FIXED 138 
#define  ACPI_PTYPE1_OPTION 137 
#define  ACPI_PTYPE1_VAR 136 
#define  ACPI_PTYPE2 135 
#define  ACPI_PTYPE2_COUNT 134 
#define  ACPI_PTYPE2_FIXED 133 
#define  ACPI_PTYPE2_FIX_VAR 132 
#define  ACPI_PTYPE2_MIN 131 
#define  ACPI_PTYPE2_PKG_COUNT 130 
#define  ACPI_PTYPE2_REV_FIXED 129 
#define  ACPI_PTYPE2_VAR_VAR 128 
 int ACPI_RTYPE_BUFFER ; 
 int ACPI_RTYPE_INTEGER ; 
 int ACPI_RTYPE_NONE ; 
 int ACPI_RTYPE_PACKAGE ; 
 int ACPI_RTYPE_STRING ; 
 scalar_t__ ACPI_SUCCESS (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ACPI_WARN_ALWAYS ; 
 int /*<<< orphan*/  ACPI_WARN_PREDEFINED (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  AE_AML_NO_RETURN_VALUE ; 
 int /*<<< orphan*/  AE_AML_OPERAND_TYPE ; 
 int /*<<< orphan*/  AE_INFO ; 
 int /*<<< orphan*/  AE_NO_MEMORY ; 
 int /*<<< orphan*/  AE_OK ; 
 int /*<<< orphan*/  AcpiNsConvertToBuffer (TYPE_7__*,TYPE_7__**) ; 
 int /*<<< orphan*/  AcpiNsConvertToInteger (TYPE_7__*,TYPE_7__**) ; 
 int /*<<< orphan*/  AcpiNsConvertToString (TYPE_7__*,TYPE_7__**) ; 
static  TYPE_6__ const* AcpiNsMatchSimpleRepair (TYPE_8__*,int,int) ; 
 int /*<<< orphan*/  AcpiNsRepairNullElement (TYPE_9__*,int,int,TYPE_7__**) ; 
 int /*<<< orphan*/  AcpiNsWrapWithPackage (TYPE_9__*,TYPE_7__*,TYPE_7__**) ; 
 TYPE_6__* AcpiObjectRepairInfo ; 
 TYPE_7__* AcpiUtCreateBufferObject (int /*<<< orphan*/ ) ; 
 TYPE_7__* AcpiUtCreateIntegerObject (int /*<<< orphan*/ ) ; 
 TYPE_7__* AcpiUtCreatePackageObject (int) ; 
 TYPE_7__* AcpiUtCreateStringObject (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  AcpiUtGetObjectTypeName (TYPE_7__*) ; 
 int /*<<< orphan*/  AcpiUtRemoveReference (TYPE_7__*) ; 
 int /*<<< orphan*/  NsRemoveNullElements ; 
 int /*<<< orphan*/  NsRepairNullElement ; 
 int /*<<< orphan*/  NsSimpleRepair ; 
 int /*<<< orphan*/  NsWrapWithPackage ; 
 int /*<<< orphan*/  stub1 (TYPE_8__*,TYPE_7__*,TYPE_7__**) ; 

ACPI_STATUS
AcpiNsSimpleRepair (
    ACPI_EVALUATE_INFO      *Info,
    UINT32                  ExpectedBtypes,
    UINT32                  PackageIndex,
    ACPI_OPERAND_OBJECT     **ReturnObjectPtr)
{
    ACPI_OPERAND_OBJECT     *ReturnObject = *ReturnObjectPtr;
    ACPI_OPERAND_OBJECT     *NewObject = NULL;
    ACPI_STATUS             Status;
    const ACPI_SIMPLE_REPAIR_INFO   *Predefined;


    ACPI_FUNCTION_NAME (NsSimpleRepair);


    /*
     * Special repairs for certain names that are in the repair table.
     * Check if this name is in the list of repairable names.
     */
    Predefined = AcpiNsMatchSimpleRepair (Info->Node,
        Info->ReturnBtype, PackageIndex);
    if (Predefined)
    {
        if (!ReturnObject)
        {
            ACPI_WARN_PREDEFINED ((AE_INFO, Info->FullPathname,
                ACPI_WARN_ALWAYS, "Missing expected return value"));
        }

        Status = Predefined->ObjectConverter (Info->Node, ReturnObject,
            &NewObject);
        if (ACPI_FAILURE (Status))
        {
            /* A fatal error occurred during a conversion */

            ACPI_EXCEPTION ((AE_INFO, Status,
                "During return object analysis"));
            return (Status);
        }
        if (NewObject)
        {
            goto ObjectRepaired;
        }
    }

    /*
     * Do not perform simple object repair unless the return type is not
     * expected.
     */
    if (Info->ReturnBtype & ExpectedBtypes)
    {
        return (AE_OK);
    }

    /*
     * At this point, we know that the type of the returned object was not
     * one of the expected types for this predefined name. Attempt to
     * repair the object by converting it to one of the expected object
     * types for this predefined name.
     */

    /*
     * If there is no return value, check if we require a return value for
     * this predefined name. Either one return value is expected, or none,
     * for both methods and other objects.
     *
     * Try to fix if there was no return object. Warning if failed to fix.
     */
    if (!ReturnObject)
    {
        if (ExpectedBtypes && (!(ExpectedBtypes & ACPI_RTYPE_NONE)))
        {
            if (PackageIndex != ACPI_NOT_PACKAGE_ELEMENT)
            {
                ACPI_WARN_PREDEFINED ((AE_INFO, Info->FullPathname,
                    ACPI_WARN_ALWAYS, "Found unexpected NULL package element"));

                Status = AcpiNsRepairNullElement (Info, ExpectedBtypes,
                    PackageIndex, ReturnObjectPtr);
                if (ACPI_SUCCESS (Status))
                {
                    return (AE_OK); /* Repair was successful */
                }
            }
            else
            {
                ACPI_WARN_PREDEFINED ((AE_INFO, Info->FullPathname,
                    ACPI_WARN_ALWAYS, "Missing expected return value"));
            }

            return (AE_AML_NO_RETURN_VALUE);
        }
    }

    if (ExpectedBtypes & ACPI_RTYPE_INTEGER)
    {
        Status = AcpiNsConvertToInteger (ReturnObject, &NewObject);
        if (ACPI_SUCCESS (Status))
        {
            goto ObjectRepaired;
        }
    }
    if (ExpectedBtypes & ACPI_RTYPE_STRING)
    {
        Status = AcpiNsConvertToString (ReturnObject, &NewObject);
        if (ACPI_SUCCESS (Status))
        {
            goto ObjectRepaired;
        }
    }
    if (ExpectedBtypes & ACPI_RTYPE_BUFFER)
    {
        Status = AcpiNsConvertToBuffer (ReturnObject, &NewObject);
        if (ACPI_SUCCESS (Status))
        {
            goto ObjectRepaired;
        }
    }
    if (ExpectedBtypes & ACPI_RTYPE_PACKAGE)
    {
        /*
         * A package is expected. We will wrap the existing object with a
         * new package object. It is often the case that if a variable-length
         * package is required, but there is only a single object needed, the
         * BIOS will return that object instead of wrapping it with a Package
         * object. Note: after the wrapping, the package will be validated
         * for correct contents (expected object type or types).
         */
        Status = AcpiNsWrapWithPackage (Info, ReturnObject, &NewObject);
        if (ACPI_SUCCESS (Status))
        {
            /*
             * The original object just had its reference count
             * incremented for being inserted into the new package.
             */
            *ReturnObjectPtr = NewObject;       /* New Package object */
            Info->ReturnFlags |= ACPI_OBJECT_REPAIRED;
            return (AE_OK);
        }
    }

    /* We cannot repair this object */

    return (AE_AML_OPERAND_TYPE);


ObjectRepaired:

    /* Object was successfully repaired */

    if (PackageIndex != ACPI_NOT_PACKAGE_ELEMENT)
    {
        /* Update reference count of new object */

        if (!(Info->ReturnFlags & ACPI_OBJECT_WRAPPED))
        {
            NewObject->Common.ReferenceCount =
                ReturnObject->Common.ReferenceCount;
        }

        ACPI_DEBUG_PRINT ((ACPI_DB_REPAIR,
            "%s: Converted %s to expected %s at Package index %u\n",
            Info->FullPathname, AcpiUtGetObjectTypeName (ReturnObject),
            AcpiUtGetObjectTypeName (NewObject), PackageIndex));
    }
    else
    {
        ACPI_DEBUG_PRINT ((ACPI_DB_REPAIR,
            "%s: Converted %s to expected %s\n",
            Info->FullPathname, AcpiUtGetObjectTypeName (ReturnObject),
            AcpiUtGetObjectTypeName (NewObject)));
    }

    /* Delete old object, install the new return object */

    AcpiUtRemoveReference (ReturnObject);
    *ReturnObjectPtr = NewObject;
    Info->ReturnFlags |= ACPI_OBJECT_REPAIRED;
    return (AE_OK);
}

__attribute__((used)) static const ACPI_SIMPLE_REPAIR_INFO *
AcpiNsMatchSimpleRepair (
    ACPI_NAMESPACE_NODE     *Node,
    UINT32                  ReturnBtype,
    UINT32                  PackageIndex)
{
    const ACPI_SIMPLE_REPAIR_INFO   *ThisName;


    /* Search info table for a repairable predefined method/object name */

    ThisName = AcpiObjectRepairInfo;
    while (ThisName->ObjectConverter)
    {
        if (ACPI_COMPARE_NAMESEG (Node->Name.Ascii, ThisName->Name))
        {
            /* Check if we can actually repair this name/type combination */

            if ((ReturnBtype & ThisName->UnexpectedBtypes) &&
                (ThisName->PackageIndex == ACPI_ALL_PACKAGE_ELEMENTS ||
                 PackageIndex == ThisName->PackageIndex))
            {
                return (ThisName);
            }

            return (NULL);
        }

        ThisName++;
    }

    return (NULL); /* Name was not found in the repair table */
}

ACPI_STATUS
AcpiNsRepairNullElement (
    ACPI_EVALUATE_INFO      *Info,
    UINT32                  ExpectedBtypes,
    UINT32                  PackageIndex,
    ACPI_OPERAND_OBJECT     **ReturnObjectPtr)
{
    ACPI_OPERAND_OBJECT     *ReturnObject = *ReturnObjectPtr;
    ACPI_OPERAND_OBJECT     *NewObject;


    ACPI_FUNCTION_NAME (NsRepairNullElement);


    /* No repair needed if return object is non-NULL */

    if (ReturnObject)
    {
        return (AE_OK);
    }

    /*
     * Attempt to repair a NULL element of a Package object. This applies to
     * predefined names that return a fixed-length package and each element
     * is required. It does not apply to variable-length packages where NULL
     * elements are allowed, especially at the end of the package.
     */
    if (ExpectedBtypes & ACPI_RTYPE_INTEGER)
    {
        /* Need an Integer - create a zero-value integer */

        NewObject = AcpiUtCreateIntegerObject ((UINT64) 0);
    }
    else if (ExpectedBtypes & ACPI_RTYPE_STRING)
    {
        /* Need a String - create a NULL string */

        NewObject = AcpiUtCreateStringObject (0);
    }
    else if (ExpectedBtypes & ACPI_RTYPE_BUFFER)
    {
        /* Need a Buffer - create a zero-length buffer */

        NewObject = AcpiUtCreateBufferObject (0);
    }
    else
    {
        /* Error for all other expected types */

        return (AE_AML_OPERAND_TYPE);
    }

    if (!NewObject)
    {
        return (AE_NO_MEMORY);
    }

    /* Set the reference count according to the parent Package object */

    NewObject->Common.ReferenceCount =
        Info->ParentPackage->Common.ReferenceCount;

    ACPI_DEBUG_PRINT ((ACPI_DB_REPAIR,
        "%s: Converted NULL package element to expected %s at index %u\n",
        Info->FullPathname, AcpiUtGetObjectTypeName (NewObject),
        PackageIndex));

    *ReturnObjectPtr = NewObject;
    Info->ReturnFlags |= ACPI_OBJECT_REPAIRED;
    return (AE_OK);
}

void
AcpiNsRemoveNullElements (
    ACPI_EVALUATE_INFO      *Info,
    UINT8                   PackageType,
    ACPI_OPERAND_OBJECT     *ObjDesc)
{
    ACPI_OPERAND_OBJECT     **Source;
    ACPI_OPERAND_OBJECT     **Dest;
    UINT32                  Count;
    UINT32                  NewCount;
    UINT32                  i;


    ACPI_FUNCTION_NAME (NsRemoveNullElements);


    /*
     * We can safely remove all NULL elements from these package types:
     * PTYPE1_VAR packages contain a variable number of simple data types.
     * PTYPE2 packages contain a variable number of subpackages.
     */
    switch (PackageType)
    {
    case ACPI_PTYPE1_VAR:
    case ACPI_PTYPE2:
    case ACPI_PTYPE2_COUNT:
    case ACPI_PTYPE2_PKG_COUNT:
    case ACPI_PTYPE2_FIXED:
    case ACPI_PTYPE2_MIN:
    case ACPI_PTYPE2_REV_FIXED:
    case ACPI_PTYPE2_FIX_VAR:
        break;

    default:
    case ACPI_PTYPE2_VAR_VAR:
    case ACPI_PTYPE1_FIXED:
    case ACPI_PTYPE1_OPTION:
        return;
    }

    Count = ObjDesc->Package.Count;
    NewCount = Count;

    Source = ObjDesc->Package.Elements;
    Dest = Source;

    /* Examine all elements of the package object, remove nulls */

    for (i = 0; i < Count; i++)
    {
        if (!*Source)
        {
            NewCount--;
        }
        else
        {
            *Dest = *Source;
            Dest++;
        }

        Source++;
    }

    /* Update parent package if any null elements were removed */

    if (NewCount < Count)
    {
        ACPI_DEBUG_PRINT ((ACPI_DB_REPAIR,
            "%s: Found and removed %u NULL elements\n",
            Info->FullPathname, (Count - NewCount)));

        /* NULL terminate list and update the package count */

        *Dest = NULL;
        ObjDesc->Package.Count = NewCount;
    }
}

ACPI_STATUS
AcpiNsWrapWithPackage (
    ACPI_EVALUATE_INFO      *Info,
    ACPI_OPERAND_OBJECT     *OriginalObject,
    ACPI_OPERAND_OBJECT     **ObjDescPtr)
{
    ACPI_OPERAND_OBJECT     *PkgObjDesc;


    ACPI_FUNCTION_NAME (NsWrapWithPackage);


    /*
     * Create the new outer package and populate it. The new
     * package will have a single element, the lone sub-object.
     */
    PkgObjDesc = AcpiUtCreatePackageObject (1);
    if (!PkgObjDesc)
    {
        return (AE_NO_MEMORY);
    }

    PkgObjDesc->Package.Elements[0] = OriginalObject;

    ACPI_DEBUG_PRINT ((ACPI_DB_REPAIR,
        "%s: Wrapped %s with expected Package object\n",
        Info->FullPathname, AcpiUtGetObjectTypeName (OriginalObject)));

    /* Return the new object in the object pointer */

    *ObjDescPtr = PkgObjDesc;
    Info->ReturnFlags |= ACPI_OBJECT_REPAIRED | ACPI_OBJECT_WRAPPED;
    return (AE_OK);
}

