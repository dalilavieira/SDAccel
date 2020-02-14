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
typedef  struct TYPE_27__   TYPE_10__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  UINT8 ;
typedef  size_t UINT32 ;
struct TYPE_34__ {size_t Value; } ;
struct TYPE_33__ {scalar_t__ Type; } ;
struct TYPE_32__ {size_t Count; TYPE_9__** Elements; } ;
struct TYPE_29__ {int Length; } ;
struct TYPE_36__ {TYPE_7__ Integer; TYPE_6__ Common; TYPE_5__ Package; TYPE_2__ Buffer; } ;
struct TYPE_31__ {int Type; size_t Count1; size_t Count2; int /*<<< orphan*/  ObjectType1; int /*<<< orphan*/  ObjectType2; } ;
struct TYPE_30__ {size_t Count; int /*<<< orphan*/ * ObjectType; } ;
struct TYPE_28__ {size_t Count; int /*<<< orphan*/  TailObjectType; int /*<<< orphan*/ * ObjectType; } ;
struct TYPE_35__ {TYPE_4__ RetInfo; TYPE_3__ RetInfo2; TYPE_1__ RetInfo3; } ;
struct TYPE_27__ {int /*<<< orphan*/  FullPathname; int /*<<< orphan*/  NodeFlags; TYPE_9__* ParentPackage; TYPE_8__* Predefined; } ;
typedef  int /*<<< orphan*/  ACPI_STATUS ;
typedef  TYPE_8__ ACPI_PREDEFINED_INFO ;
typedef  TYPE_9__ ACPI_OPERAND_OBJECT ;
typedef  TYPE_10__ ACPI_EVALUATE_INFO ;

/* Variables and functions */
 int /*<<< orphan*/  ACPI_DB_NAMES ; 
 int /*<<< orphan*/  ACPI_DB_REPAIR ; 
 int /*<<< orphan*/  ACPI_DEBUG_PRINT (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ACPI_ERROR (int /*<<< orphan*/ ) ; 
 scalar_t__ ACPI_FAILURE (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ACPI_FUNCTION_NAME (int /*<<< orphan*/ ) ; 
#define  ACPI_PTYPE1_FIXED 140 
#define  ACPI_PTYPE1_OPTION 139 
#define  ACPI_PTYPE1_VAR 138 
#define  ACPI_PTYPE2 137 
#define  ACPI_PTYPE2_COUNT 136 
#define  ACPI_PTYPE2_FIXED 135 
#define  ACPI_PTYPE2_FIX_VAR 134 
#define  ACPI_PTYPE2_MIN 133 
#define  ACPI_PTYPE2_PKG_COUNT 132 
#define  ACPI_PTYPE2_REV_FIXED 131 
#define  ACPI_PTYPE2_UUID_PAIR 130 
#define  ACPI_PTYPE2_VAR_VAR 129 
#define  ACPI_PTYPE_CUSTOM 128 
 int /*<<< orphan*/  ACPI_RTYPE_INTEGER ; 
 int /*<<< orphan*/  ACPI_RTYPE_PACKAGE ; 
 int /*<<< orphan*/  ACPI_RTYPE_STRING ; 
 scalar_t__ ACPI_TYPE_INTEGER ; 
 scalar_t__ ACPI_TYPE_PACKAGE ; 
 int /*<<< orphan*/  ACPI_WARN_PREDEFINED (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  AE_AML_INTERNAL ; 
 int /*<<< orphan*/  AE_AML_OPERAND_TYPE ; 
 int /*<<< orphan*/  AE_AML_OPERAND_VALUE ; 
 int /*<<< orphan*/  AE_INFO ; 
 int /*<<< orphan*/  AE_OK ; 
 int /*<<< orphan*/  AcpiNsCheckObjectType (TYPE_10__*,TYPE_9__**,int /*<<< orphan*/ ,size_t) ; 
static  int /*<<< orphan*/  AcpiNsCheckPackageElements (TYPE_10__*,TYPE_9__**,int /*<<< orphan*/ ,size_t,int /*<<< orphan*/ ,size_t,size_t) ; 
static  int /*<<< orphan*/  AcpiNsCheckPackageList (TYPE_10__*,TYPE_8__ const*,TYPE_9__**,size_t) ; 
static  int /*<<< orphan*/  AcpiNsCustomPackage (TYPE_10__*,TYPE_9__**,size_t) ; 
 int /*<<< orphan*/  AcpiNsRemoveNullElements (TYPE_10__*,int,TYPE_9__*) ; 
 int /*<<< orphan*/  AcpiNsWrapWithPackage (TYPE_10__*,TYPE_9__*,TYPE_9__**) ; 
 int /*<<< orphan*/  NsCheckPackage ; 
 int /*<<< orphan*/  NsCustomPackage ; 
 int /*<<< orphan*/  return_ACPI_STATUS (int /*<<< orphan*/ ) ; 

ACPI_STATUS
AcpiNsCheckPackage (
    ACPI_EVALUATE_INFO          *Info,
    ACPI_OPERAND_OBJECT         **ReturnObjectPtr)
{
    ACPI_OPERAND_OBJECT         *ReturnObject = *ReturnObjectPtr;
    const ACPI_PREDEFINED_INFO  *Package;
    ACPI_OPERAND_OBJECT         **Elements;
    ACPI_STATUS                 Status = AE_OK;
    UINT32                      ExpectedCount;
    UINT32                      Count;
    UINT32                      i;


    ACPI_FUNCTION_NAME (NsCheckPackage);


    /* The package info for this name is in the next table entry */

    Package = Info->Predefined + 1;

    ACPI_DEBUG_PRINT ((ACPI_DB_NAMES,
        "%s Validating return Package of Type %X, Count %X\n",
        Info->FullPathname, Package->RetInfo.Type,
        ReturnObject->Package.Count));

    /*
     * For variable-length Packages, we can safely remove all embedded
     * and trailing NULL package elements
     */
    AcpiNsRemoveNullElements (Info, Package->RetInfo.Type, ReturnObject);

    /* Extract package count and elements array */

    Elements = ReturnObject->Package.Elements;
    Count = ReturnObject->Package.Count;

    /*
     * Most packages must have at least one element. The only exception
     * is the variable-length package (ACPI_PTYPE1_VAR).
     */
    if (!Count)
    {
        if (Package->RetInfo.Type == ACPI_PTYPE1_VAR)
        {
            return (AE_OK);
        }

        ACPI_WARN_PREDEFINED ((AE_INFO, Info->FullPathname, Info->NodeFlags,
            "Return Package has no elements (empty)"));

        return (AE_AML_OPERAND_VALUE);
    }

    /*
     * Decode the type of the expected package contents
     *
     * PTYPE1 packages contain no subpackages
     * PTYPE2 packages contain subpackages
     */
    switch (Package->RetInfo.Type)
    {
    case ACPI_PTYPE_CUSTOM:

        Status = AcpiNsCustomPackage (Info, Elements, Count);
        break;

    case ACPI_PTYPE1_FIXED:
        /*
         * The package count is fixed and there are no subpackages
         *
         * If package is too small, exit.
         * If package is larger than expected, issue warning but continue
         */
        ExpectedCount = Package->RetInfo.Count1 + Package->RetInfo.Count2;
        if (Count < ExpectedCount)
        {
            goto PackageTooSmall;
        }
        else if (Count > ExpectedCount)
        {
            ACPI_DEBUG_PRINT ((ACPI_DB_REPAIR,
                "%s: Return Package is larger than needed - "
                "found %u, expected %u\n",
                Info->FullPathname, Count, ExpectedCount));
        }

        /* Validate all elements of the returned package */

        Status = AcpiNsCheckPackageElements (Info, Elements,
            Package->RetInfo.ObjectType1, Package->RetInfo.Count1,
            Package->RetInfo.ObjectType2, Package->RetInfo.Count2, 0);
        break;

    case ACPI_PTYPE1_VAR:
        /*
         * The package count is variable, there are no subpackages, and all
         * elements must be of the same type
         */
        for (i = 0; i < Count; i++)
        {
            Status = AcpiNsCheckObjectType (Info, Elements,
                Package->RetInfo.ObjectType1, i);
            if (ACPI_FAILURE (Status))
            {
                return (Status);
            }

            Elements++;
        }
        break;

    case ACPI_PTYPE1_OPTION:
        /*
         * The package count is variable, there are no subpackages. There are
         * a fixed number of required elements, and a variable number of
         * optional elements.
         *
         * Check if package is at least as large as the minimum required
         */
        ExpectedCount = Package->RetInfo3.Count;
        if (Count < ExpectedCount)
        {
            goto PackageTooSmall;
        }

        /* Variable number of sub-objects */

        for (i = 0; i < Count; i++)
        {
            if (i < Package->RetInfo3.Count)
            {
                /* These are the required package elements (0, 1, or 2) */

                Status = AcpiNsCheckObjectType (Info, Elements,
                    Package->RetInfo3.ObjectType[i], i);
                if (ACPI_FAILURE (Status))
                {
                    return (Status);
                }
            }
            else
            {
                /* These are the optional package elements */

                Status = AcpiNsCheckObjectType (Info, Elements,
                    Package->RetInfo3.TailObjectType, i);
                if (ACPI_FAILURE (Status))
                {
                    return (Status);
                }
            }

            Elements++;
        }
        break;

    case ACPI_PTYPE2_REV_FIXED:

        /* First element is the (Integer) revision */

        Status = AcpiNsCheckObjectType (
            Info, Elements, ACPI_RTYPE_INTEGER, 0);
        if (ACPI_FAILURE (Status))
        {
            return (Status);
        }

        Elements++;
        Count--;

        /* Examine the subpackages */

        Status = AcpiNsCheckPackageList (Info, Package, Elements, Count);
        break;

    case ACPI_PTYPE2_PKG_COUNT:

        /* First element is the (Integer) count of subpackages to follow */

        Status = AcpiNsCheckObjectType (
            Info, Elements, ACPI_RTYPE_INTEGER, 0);
        if (ACPI_FAILURE (Status))
        {
            return (Status);
        }

        /*
         * Count cannot be larger than the parent package length, but allow it
         * to be smaller. The >= accounts for the Integer above.
         */
        ExpectedCount = (UINT32) (*Elements)->Integer.Value;
        if (ExpectedCount >= Count)
        {
            goto PackageTooSmall;
        }

        Count = ExpectedCount;
        Elements++;

        /* Examine the subpackages */

        Status = AcpiNsCheckPackageList (Info, Package, Elements, Count);
        break;

    case ACPI_PTYPE2:
    case ACPI_PTYPE2_FIXED:
    case ACPI_PTYPE2_MIN:
    case ACPI_PTYPE2_COUNT:
    case ACPI_PTYPE2_FIX_VAR:
        /*
         * These types all return a single Package that consists of a
         * variable number of subpackages.
         *
         * First, ensure that the first element is a subpackage. If not,
         * the BIOS may have incorrectly returned the object as a single
         * package instead of a Package of Packages (a common error if
         * there is only one entry). We may be able to repair this by
         * wrapping the returned Package with a new outer Package.
         */
        if (*Elements && ((*Elements)->Common.Type != ACPI_TYPE_PACKAGE))
        {
            /* Create the new outer package and populate it */

            Status = AcpiNsWrapWithPackage (
                Info, ReturnObject, ReturnObjectPtr);
            if (ACPI_FAILURE (Status))
            {
                return (Status);
            }

            /* Update locals to point to the new package (of 1 element) */

            ReturnObject = *ReturnObjectPtr;
            Elements = ReturnObject->Package.Elements;
            Count = 1;
        }

        /* Examine the subpackages */

        Status = AcpiNsCheckPackageList (Info, Package, Elements, Count);
        break;

    case ACPI_PTYPE2_VAR_VAR:
        /*
         * Returns a variable list of packages, each with a variable list
         * of objects.
         */
        break;

    case ACPI_PTYPE2_UUID_PAIR:

        /* The package must contain pairs of (UUID + type) */

        if (Count & 1)
        {
            ExpectedCount = Count + 1;
            goto PackageTooSmall;
        }

        while (Count > 0)
        {
            Status = AcpiNsCheckObjectType(Info, Elements,
                Package->RetInfo.ObjectType1, 0);
            if (ACPI_FAILURE(Status))
            {
                return (Status);
            }

            /* Validate length of the UUID buffer */

            if ((*Elements)->Buffer.Length != 16)
            {
                ACPI_WARN_PREDEFINED ((AE_INFO, Info->FullPathname,
                    Info->NodeFlags, "Invalid length for UUID Buffer"));
                return (AE_AML_OPERAND_VALUE);
            }

            Status = AcpiNsCheckObjectType(Info, Elements + 1,
                Package->RetInfo.ObjectType2, 0);
            if (ACPI_FAILURE(Status))
            {
                return (Status);
            }

            Elements += 2;
            Count -= 2;
        }
        break;

    default:

        /* Should not get here if predefined info table is correct */

        ACPI_WARN_PREDEFINED ((AE_INFO, Info->FullPathname, Info->NodeFlags,
            "Invalid internal return type in table entry: %X",
            Package->RetInfo.Type));

        return (AE_AML_INTERNAL);
    }

    return (Status);


PackageTooSmall:

    /* Error exit for the case with an incorrect package count */

    ACPI_WARN_PREDEFINED ((AE_INFO, Info->FullPathname, Info->NodeFlags,
        "Return Package is too small - found %u elements, expected %u",
        Count, ExpectedCount));

    return (AE_AML_OPERAND_VALUE);
}

__attribute__((used)) static ACPI_STATUS
AcpiNsCheckPackageList (
    ACPI_EVALUATE_INFO          *Info,
    const ACPI_PREDEFINED_INFO  *Package,
    ACPI_OPERAND_OBJECT         **Elements,
    UINT32                      Count)
{
    ACPI_OPERAND_OBJECT         *SubPackage;
    ACPI_OPERAND_OBJECT         **SubElements;
    ACPI_STATUS                 Status;
    UINT32                      ExpectedCount;
    UINT32                      i;
    UINT32                      j;


    /*
     * Validate each subpackage in the parent Package
     *
     * NOTE: assumes list of subpackages contains no NULL elements.
     * Any NULL elements should have been removed by earlier call
     * to AcpiNsRemoveNullElements.
     */
    for (i = 0; i < Count; i++)
    {
        SubPackage = *Elements;
        SubElements = SubPackage->Package.Elements;
        Info->ParentPackage = SubPackage;

        /* Each sub-object must be of type Package */

        Status = AcpiNsCheckObjectType (Info, &SubPackage,
            ACPI_RTYPE_PACKAGE, i);
        if (ACPI_FAILURE (Status))
        {
            return (Status);
        }

        /* Examine the different types of expected subpackages */

        Info->ParentPackage = SubPackage;
        switch (Package->RetInfo.Type)
        {
        case ACPI_PTYPE2:
        case ACPI_PTYPE2_PKG_COUNT:
        case ACPI_PTYPE2_REV_FIXED:

            /* Each subpackage has a fixed number of elements */

            ExpectedCount = Package->RetInfo.Count1 + Package->RetInfo.Count2;
            if (SubPackage->Package.Count < ExpectedCount)
            {
                goto PackageTooSmall;
            }

            Status = AcpiNsCheckPackageElements (Info, SubElements,
                Package->RetInfo.ObjectType1,
                Package->RetInfo.Count1,
                Package->RetInfo.ObjectType2,
                Package->RetInfo.Count2, 0);
            if (ACPI_FAILURE (Status))
            {
                return (Status);
            }
            break;

        case ACPI_PTYPE2_FIX_VAR:
            /*
             * Each subpackage has a fixed number of elements and an
             * optional element
             */
            ExpectedCount = Package->RetInfo.Count1 + Package->RetInfo.Count2;
            if (SubPackage->Package.Count < ExpectedCount)
            {
                goto PackageTooSmall;
            }

            Status = AcpiNsCheckPackageElements (Info, SubElements,
                Package->RetInfo.ObjectType1,
                Package->RetInfo.Count1,
                Package->RetInfo.ObjectType2,
                SubPackage->Package.Count - Package->RetInfo.Count1, 0);
            if (ACPI_FAILURE (Status))
            {
                return (Status);
            }
            break;

        case ACPI_PTYPE2_VAR_VAR:
            /*
             * Each subpackage has a fixed or variable number of elements
             */
            break;

        case ACPI_PTYPE2_FIXED:

            /* Each subpackage has a fixed length */

            ExpectedCount = Package->RetInfo2.Count;
            if (SubPackage->Package.Count < ExpectedCount)
            {
                goto PackageTooSmall;
            }

            /* Check the type of each subpackage element */

            for (j = 0; j < ExpectedCount; j++)
            {
                Status = AcpiNsCheckObjectType (Info, &SubElements[j],
                    Package->RetInfo2.ObjectType[j], j);
                if (ACPI_FAILURE (Status))
                {
                    return (Status);
                }
            }
            break;

        case ACPI_PTYPE2_MIN:

            /* Each subpackage has a variable but minimum length */

            ExpectedCount = Package->RetInfo.Count1;
            if (SubPackage->Package.Count < ExpectedCount)
            {
                goto PackageTooSmall;
            }

            /* Check the type of each subpackage element */

            Status = AcpiNsCheckPackageElements (Info, SubElements,
                Package->RetInfo.ObjectType1,
                SubPackage->Package.Count, 0, 0, 0);
            if (ACPI_FAILURE (Status))
            {
                return (Status);
            }
            break;

        case ACPI_PTYPE2_COUNT:
            /*
             * First element is the (Integer) count of elements, including
             * the count field (the ACPI name is NumElements)
             */
            Status = AcpiNsCheckObjectType (Info, SubElements,
                ACPI_RTYPE_INTEGER, 0);
            if (ACPI_FAILURE (Status))
            {
                return (Status);
            }

            /*
             * Make sure package is large enough for the Count and is
             * is as large as the minimum size
             */
            ExpectedCount = (UINT32) (*SubElements)->Integer.Value;
            if (SubPackage->Package.Count < ExpectedCount)
            {
                goto PackageTooSmall;
            }

            if (SubPackage->Package.Count < Package->RetInfo.Count1)
            {
                ExpectedCount = Package->RetInfo.Count1;
                goto PackageTooSmall;
            }

            if (ExpectedCount == 0)
            {
                /*
                 * Either the NumEntries element was originally zero or it was
                 * a NULL element and repaired to an Integer of value zero.
                 * In either case, repair it by setting NumEntries to be the
                 * actual size of the subpackage.
                 */
                ExpectedCount = SubPackage->Package.Count;
                (*SubElements)->Integer.Value = ExpectedCount;
            }

            /* Check the type of each subpackage element */

            Status = AcpiNsCheckPackageElements (Info, (SubElements + 1),
                Package->RetInfo.ObjectType1,
                (ExpectedCount - 1), 0, 0, 1);
            if (ACPI_FAILURE (Status))
            {
                return (Status);
            }
            break;

        default: /* Should not get here, type was validated by caller */

            ACPI_ERROR ((AE_INFO, "Invalid Package type: %X",
                Package->RetInfo.Type));
            return (AE_AML_INTERNAL);
        }

        Elements++;
    }

    return (AE_OK);


PackageTooSmall:

    /* The subpackage count was smaller than required */

    ACPI_WARN_PREDEFINED ((AE_INFO, Info->FullPathname, Info->NodeFlags,
        "Return SubPackage[%u] is too small - found %u elements, expected %u",
        i, SubPackage->Package.Count, ExpectedCount));

    return (AE_AML_OPERAND_VALUE);
}

__attribute__((used)) static ACPI_STATUS
AcpiNsCustomPackage (
    ACPI_EVALUATE_INFO          *Info,
    ACPI_OPERAND_OBJECT         **Elements,
    UINT32                      Count)
{
    UINT32                      ExpectedCount;
    UINT32                      Version;
    ACPI_STATUS                 Status = AE_OK;


    ACPI_FUNCTION_NAME (NsCustomPackage);


    /* Get version number, must be Integer */

    if ((*Elements)->Common.Type != ACPI_TYPE_INTEGER)
    {
        ACPI_WARN_PREDEFINED ((AE_INFO, Info->FullPathname, Info->NodeFlags,
            "Return Package has invalid object type for version number"));
        return_ACPI_STATUS (AE_AML_OPERAND_TYPE);
    }

    Version = (UINT32) (*Elements)->Integer.Value;
    ExpectedCount = 21;         /* Version 1 */

    if (Version == 0)
    {
        ExpectedCount = 20;     /* Version 0 */
    }

    if (Count < ExpectedCount)
    {
        ACPI_WARN_PREDEFINED ((AE_INFO, Info->FullPathname, Info->NodeFlags,
            "Return Package is too small - found %u elements, expected %u",
            Count, ExpectedCount));
        return_ACPI_STATUS (AE_AML_OPERAND_VALUE);
    }
    else if (Count > ExpectedCount)
    {
        ACPI_DEBUG_PRINT ((ACPI_DB_REPAIR,
            "%s: Return Package is larger than needed - "
            "found %u, expected %u\n",
            Info->FullPathname, Count, ExpectedCount));
    }

    /* Validate all elements of the returned package */

    Status = AcpiNsCheckPackageElements (Info, Elements,
        ACPI_RTYPE_INTEGER, 16,
        ACPI_RTYPE_STRING, 4, 0);
    if (ACPI_FAILURE (Status))
    {
        return_ACPI_STATUS (Status);
    }

    /* Version 1 has a single trailing integer */

    if (Version > 0)
    {
        Status = AcpiNsCheckPackageElements (Info, Elements + 20,
            ACPI_RTYPE_INTEGER, 1, 0, 0, 20);
    }

    return_ACPI_STATUS (Status);
}

__attribute__((used)) static ACPI_STATUS
AcpiNsCheckPackageElements (
    ACPI_EVALUATE_INFO          *Info,
    ACPI_OPERAND_OBJECT         **Elements,
    UINT8                       Type1,
    UINT32                      Count1,
    UINT8                       Type2,
    UINT32                      Count2,
    UINT32                      StartIndex)
{
    ACPI_OPERAND_OBJECT         **ThisElement = Elements;
    ACPI_STATUS                 Status;
    UINT32                      i;


    /*
     * Up to two groups of package elements are supported by the data
     * structure. All elements in each group must be of the same type.
     * The second group can have a count of zero.
     */
    for (i = 0; i < Count1; i++)
    {
        Status = AcpiNsCheckObjectType (Info, ThisElement,
            Type1, i + StartIndex);
        if (ACPI_FAILURE (Status))
        {
            return (Status);
        }

        ThisElement++;
    }

    for (i = 0; i < Count2; i++)
    {
        Status = AcpiNsCheckObjectType (Info, ThisElement,
            Type2, (i + Count1 + StartIndex));
        if (ACPI_FAILURE (Status))
        {
            return (Status);
        }

        ThisElement++;
    }

    return (AE_OK);
}

