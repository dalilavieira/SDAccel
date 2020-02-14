#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_52__   TYPE_7__ ;
typedef  struct TYPE_51__   TYPE_6__ ;
typedef  struct TYPE_50__   TYPE_5__ ;
typedef  struct TYPE_49__   TYPE_4__ ;
typedef  struct TYPE_48__   TYPE_3__ ;
typedef  struct TYPE_47__   TYPE_2__ ;
typedef  struct TYPE_46__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  UINT8 ;
typedef  int UINT32 ;
struct TYPE_50__ {int Type; int Flags; int ReferenceCount; } ;
struct TYPE_49__ {int /*<<< orphan*/  Ascii; } ;
struct TYPE_48__ {int Class; size_t Value; int TargetType; TYPE_7__* Object; TYPE_7__** Where; } ;
struct TYPE_47__ {int /*<<< orphan*/ * Pointer; } ;
struct TYPE_46__ {int /*<<< orphan*/  Value; } ;
struct TYPE_52__ {int Type; TYPE_5__ Common; TYPE_4__ Name; TYPE_3__ Reference; TYPE_2__ Buffer; TYPE_1__ Integer; } ;
struct TYPE_51__ {scalar_t__ Opcode; int /*<<< orphan*/  ResultObj; } ;
typedef  TYPE_6__ ACPI_WALK_STATE ;
typedef  int /*<<< orphan*/  ACPI_STATUS ;
typedef  TYPE_7__ ACPI_OPERAND_OBJECT ;
typedef  int ACPI_OBJECT_TYPE ;
typedef  TYPE_7__ ACPI_NAMESPACE_NODE ;

/* Variables and functions */
 int /*<<< orphan*/  ACPI_DB_EXEC ; 
 int /*<<< orphan*/  ACPI_DEBUG_OBJECT (TYPE_7__*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ACPI_DEBUG_PRINT (int /*<<< orphan*/ ) ; 
 scalar_t__ ACPI_DESC_TYPE_NAMED ; 
 int /*<<< orphan*/  ACPI_DUMP_ENTRY (TYPE_7__*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ACPI_ERROR (int /*<<< orphan*/ ) ; 
 scalar_t__ ACPI_FAILURE (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ACPI_FUNCTION_TRACE (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ACPI_FUNCTION_TRACE_PTR (int /*<<< orphan*/ ,TYPE_7__*) ; 
 scalar_t__ ACPI_GET_DESCRIPTOR_TYPE (TYPE_7__*) ; 
 int /*<<< orphan*/  ACPI_IMPLICIT_CONVERSION ; 
 int /*<<< orphan*/  ACPI_LV_INFO ; 
#define  ACPI_REFCLASS_ARG 148 
#define  ACPI_REFCLASS_DEBUG 147 
#define  ACPI_REFCLASS_INDEX 146 
#define  ACPI_REFCLASS_LOCAL 145 
#define  ACPI_REFCLASS_REFOF 144 
 int ACPI_REFCLASS_TABLE ; 
#define  ACPI_TYPE_BUFFER 143 
#define  ACPI_TYPE_BUFFER_FIELD 142 
#define  ACPI_TYPE_DEVICE 141 
#define  ACPI_TYPE_EVENT 140 
#define  ACPI_TYPE_INTEGER 139 
#define  ACPI_TYPE_LOCAL_BANK_FIELD 138 
#define  ACPI_TYPE_LOCAL_INDEX_FIELD 137 
#define  ACPI_TYPE_LOCAL_REFERENCE 136 
#define  ACPI_TYPE_LOCAL_REGION_FIELD 135 
#define  ACPI_TYPE_MUTEX 134 
#define  ACPI_TYPE_PACKAGE 133 
#define  ACPI_TYPE_POWER 132 
#define  ACPI_TYPE_PROCESSOR 131 
#define  ACPI_TYPE_REGION 130 
#define  ACPI_TYPE_STRING 129 
#define  ACPI_TYPE_THERMAL 128 
 int /*<<< orphan*/  AE_AML_INTERNAL ; 
 int /*<<< orphan*/  AE_AML_NO_OPERAND ; 
 int /*<<< orphan*/  AE_AML_OPERAND_TYPE ; 
 int /*<<< orphan*/  AE_AML_TARGET_TYPE ; 
 int /*<<< orphan*/  AE_INFO ; 
 int /*<<< orphan*/  AE_OK ; 
 scalar_t__ AML_COPY_OBJECT_OP ; 
 scalar_t__ AML_STORE_OP ; 
 int AOPOBJ_AML_CONSTANT ; 
 int /*<<< orphan*/  AcpiDsStoreObjectToLocal (int,size_t,TYPE_7__*,TYPE_6__*) ; 
 int /*<<< orphan*/  AcpiExResolveObject (TYPE_7__**,int,TYPE_6__*) ; 
static  int /*<<< orphan*/  AcpiExStoreDirectToNode (TYPE_7__*,TYPE_7__*,TYPE_6__*) ; 
static  int /*<<< orphan*/  AcpiExStoreObjectToIndex (TYPE_7__*,TYPE_7__*,TYPE_6__*) ; 
 int /*<<< orphan*/  AcpiExStoreObjectToNode (TYPE_7__*,TYPE_7__*,TYPE_6__*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  AcpiExStoreObjectToObject (TYPE_7__*,TYPE_7__*,TYPE_7__**,TYPE_6__*) ; 
 int /*<<< orphan*/  AcpiExWriteDataToField (TYPE_7__*,TYPE_7__*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  AcpiNsAttachObject (TYPE_7__*,TYPE_7__*,int) ; 
 TYPE_7__* AcpiNsGetAttachedObject (TYPE_7__*) ; 
 int AcpiNsGetType (TYPE_7__*) ; 
 int /*<<< orphan*/  AcpiUtAddReference (TYPE_7__*) ; 
 int /*<<< orphan*/  AcpiUtCopyIobjectToIobject (TYPE_7__*,TYPE_7__**,TYPE_6__*) ; 
 int /*<<< orphan*/  AcpiUtGetObjectTypeName (TYPE_7__*) ; 
 int /*<<< orphan*/  AcpiUtGetTypeName (int) ; 
 int /*<<< orphan*/  AcpiUtRemoveReference (TYPE_7__*) ; 
 int /*<<< orphan*/  ExStore ; 
 int /*<<< orphan*/  ExStoreDirectToNode ; 
 int /*<<< orphan*/  ExStoreObjectToIndex ; 
 int /*<<< orphan*/  ExStoreObjectToNode ; 
 int /*<<< orphan*/  return_ACPI_STATUS (int /*<<< orphan*/ ) ; 

ACPI_STATUS
AcpiExStore (
    ACPI_OPERAND_OBJECT     *SourceDesc,
    ACPI_OPERAND_OBJECT     *DestDesc,
    ACPI_WALK_STATE         *WalkState)
{
    ACPI_STATUS             Status = AE_OK;
    ACPI_OPERAND_OBJECT     *RefDesc = DestDesc;


    ACPI_FUNCTION_TRACE_PTR (ExStore, DestDesc);


    /* Validate parameters */

    if (!SourceDesc || !DestDesc)
    {
        ACPI_ERROR ((AE_INFO, "Null parameter"));
        return_ACPI_STATUS (AE_AML_NO_OPERAND);
    }

    /* DestDesc can be either a namespace node or an ACPI object */

    if (ACPI_GET_DESCRIPTOR_TYPE (DestDesc) == ACPI_DESC_TYPE_NAMED)
    {
        /*
         * Dest is a namespace node,
         * Storing an object into a Named node.
         */
        Status = AcpiExStoreObjectToNode (SourceDesc,
            (ACPI_NAMESPACE_NODE *) DestDesc, WalkState,
            ACPI_IMPLICIT_CONVERSION);

        return_ACPI_STATUS (Status);
    }

    /* Destination object must be a Reference or a Constant object */

    switch (DestDesc->Common.Type)
    {
    case ACPI_TYPE_LOCAL_REFERENCE:

        break;

    case ACPI_TYPE_INTEGER:

        /* Allow stores to Constants -- a Noop as per ACPI spec */

        if (DestDesc->Common.Flags & AOPOBJ_AML_CONSTANT)
        {
            return_ACPI_STATUS (AE_OK);
        }

        /*lint -fallthrough */

    default:

        /* Destination is not a Reference object */

        ACPI_ERROR ((AE_INFO,
            "Target is not a Reference or Constant object - [%s] %p",
            AcpiUtGetObjectTypeName (DestDesc), DestDesc));

        return_ACPI_STATUS (AE_AML_OPERAND_TYPE);
    }

    /*
     * Examine the Reference class. These cases are handled:
     *
     * 1) Store to Name (Change the object associated with a name)
     * 2) Store to an indexed area of a Buffer or Package
     * 3) Store to a Method Local or Arg
     * 4) Store to the debug object
     */
    switch (RefDesc->Reference.Class)
    {
    case ACPI_REFCLASS_REFOF:

        /* Storing an object into a Name "container" */

        Status = AcpiExStoreObjectToNode (SourceDesc,
            RefDesc->Reference.Object,
            WalkState, ACPI_IMPLICIT_CONVERSION);
        break;

    case ACPI_REFCLASS_INDEX:

        /* Storing to an Index (pointer into a packager or buffer) */

        Status = AcpiExStoreObjectToIndex (SourceDesc, RefDesc, WalkState);
        break;

    case ACPI_REFCLASS_LOCAL:
    case ACPI_REFCLASS_ARG:

        /* Store to a method local/arg  */

        Status = AcpiDsStoreObjectToLocal (RefDesc->Reference.Class,
            RefDesc->Reference.Value, SourceDesc, WalkState);
        break;

    case ACPI_REFCLASS_DEBUG:
        /*
         * Storing to the Debug object causes the value stored to be
         * displayed and otherwise has no effect -- see ACPI Specification
         */
        ACPI_DEBUG_PRINT ((ACPI_DB_EXEC,
            "**** Write to Debug Object: Object %p [%s] ****:\n\n",
            SourceDesc, AcpiUtGetObjectTypeName (SourceDesc)));

        ACPI_DEBUG_OBJECT (SourceDesc, 0, 0);
        break;

    default:

        ACPI_ERROR ((AE_INFO, "Unknown Reference Class 0x%2.2X",
            RefDesc->Reference.Class));
        ACPI_DUMP_ENTRY (RefDesc, ACPI_LV_INFO);

        Status = AE_AML_INTERNAL;
        break;
    }

    return_ACPI_STATUS (Status);
}

__attribute__((used)) static ACPI_STATUS
AcpiExStoreObjectToIndex (
    ACPI_OPERAND_OBJECT     *SourceDesc,
    ACPI_OPERAND_OBJECT     *IndexDesc,
    ACPI_WALK_STATE         *WalkState)
{
    ACPI_STATUS             Status = AE_OK;
    ACPI_OPERAND_OBJECT     *ObjDesc;
    ACPI_OPERAND_OBJECT     *NewDesc;
    UINT8                   Value = 0;
    UINT32                  i;


    ACPI_FUNCTION_TRACE (ExStoreObjectToIndex);


    /*
     * Destination must be a reference pointer, and
     * must point to either a buffer or a package
     */
    switch (IndexDesc->Reference.TargetType)
    {
    case ACPI_TYPE_PACKAGE:
        /*
         * Storing to a package element. Copy the object and replace
         * any existing object with the new object. No implicit
         * conversion is performed.
         *
         * The object at *(IndexDesc->Reference.Where) is the
         * element within the package that is to be modified.
         * The parent package object is at IndexDesc->Reference.Object
         */
        ObjDesc = *(IndexDesc->Reference.Where);

        if (SourceDesc->Common.Type == ACPI_TYPE_LOCAL_REFERENCE &&
            SourceDesc->Reference.Class == ACPI_REFCLASS_TABLE)
        {
            /* This is a DDBHandle, just add a reference to it */

            AcpiUtAddReference (SourceDesc);
            NewDesc = SourceDesc;
        }
        else
        {
            /* Normal object, copy it */

            Status = AcpiUtCopyIobjectToIobject (
                SourceDesc, &NewDesc, WalkState);
            if (ACPI_FAILURE (Status))
            {
                return_ACPI_STATUS (Status);
            }
        }

        if (ObjDesc)
        {
            /* Decrement reference count by the ref count of the parent package */

            for (i = 0;
                 i < ((ACPI_OPERAND_OBJECT *)
                        IndexDesc->Reference.Object)->Common.ReferenceCount;
                 i++)
            {
                AcpiUtRemoveReference (ObjDesc);
            }
        }

        *(IndexDesc->Reference.Where) = NewDesc;

        /* Increment ref count by the ref count of the parent package-1 */

        for (i = 1;
             i < ((ACPI_OPERAND_OBJECT *)
                    IndexDesc->Reference.Object)->Common.ReferenceCount;
             i++)
        {
            AcpiUtAddReference (NewDesc);
        }

        break;

    case ACPI_TYPE_BUFFER_FIELD:
        /*
         * Store into a Buffer or String (not actually a real BufferField)
         * at a location defined by an Index.
         *
         * The first 8-bit element of the source object is written to the
         * 8-bit Buffer location defined by the Index destination object,
         * according to the ACPI 2.0 specification.
         */

        /*
         * Make sure the target is a Buffer or String. An error should
         * not happen here, since the ReferenceObject was constructed
         * by the INDEX_OP code.
         */
        ObjDesc = IndexDesc->Reference.Object;
        if ((ObjDesc->Common.Type != ACPI_TYPE_BUFFER) &&
            (ObjDesc->Common.Type != ACPI_TYPE_STRING))
        {
            return_ACPI_STATUS (AE_AML_OPERAND_TYPE);
        }

        /*
         * The assignment of the individual elements will be slightly
         * different for each source type.
         */
        switch (SourceDesc->Common.Type)
        {
        case ACPI_TYPE_INTEGER:

            /* Use the least-significant byte of the integer */

            Value = (UINT8) (SourceDesc->Integer.Value);
            break;

        case ACPI_TYPE_BUFFER:
        case ACPI_TYPE_STRING:

            /* Note: Takes advantage of common string/buffer fields */

            Value = SourceDesc->Buffer.Pointer[0];
            break;

        default:

            /* All other types are invalid */

            ACPI_ERROR ((AE_INFO,
                "Source must be type [Integer/Buffer/String], found [%s]",
                AcpiUtGetObjectTypeName (SourceDesc)));
            return_ACPI_STATUS (AE_AML_OPERAND_TYPE);
        }

        /* Store the source value into the target buffer byte */

        ObjDesc->Buffer.Pointer[IndexDesc->Reference.Value] = Value;
        break;

    default:
        ACPI_ERROR ((AE_INFO,
            "Target is not of type [Package/BufferField]"));
        Status = AE_AML_TARGET_TYPE;
        break;
    }

    return_ACPI_STATUS (Status);
}

ACPI_STATUS
AcpiExStoreObjectToNode (
    ACPI_OPERAND_OBJECT     *SourceDesc,
    ACPI_NAMESPACE_NODE     *Node,
    ACPI_WALK_STATE         *WalkState,
    UINT8                   ImplicitConversion)
{
    ACPI_STATUS             Status = AE_OK;
    ACPI_OPERAND_OBJECT     *TargetDesc;
    ACPI_OPERAND_OBJECT     *NewDesc;
    ACPI_OBJECT_TYPE        TargetType;


    ACPI_FUNCTION_TRACE_PTR (ExStoreObjectToNode, SourceDesc);


    /* Get current type of the node, and object attached to Node */

    TargetType = AcpiNsGetType (Node);
    TargetDesc = AcpiNsGetAttachedObject (Node);

    ACPI_DEBUG_PRINT ((ACPI_DB_EXEC, "Storing %p [%s] to node %p [%s]\n",
        SourceDesc, AcpiUtGetObjectTypeName (SourceDesc),
        Node, AcpiUtGetTypeName (TargetType)));

    /* Only limited target types possible for everything except CopyObject */

    if (WalkState->Opcode != AML_COPY_OBJECT_OP)
    {
        /*
         * Only CopyObject allows all object types to be overwritten. For
         * TargetRef(s), there are restrictions on the object types that
         * are allowed.
         *
         * Allowable operations/typing for Store:
         *
         * 1) Simple Store
         *      Integer     --> Integer (Named/Local/Arg)
         *      String      --> String  (Named/Local/Arg)
         *      Buffer      --> Buffer  (Named/Local/Arg)
         *      Package     --> Package (Named/Local/Arg)
         *
         * 2) Store with implicit conversion
         *      Integer     --> String or Buffer  (Named)
         *      String      --> Integer or Buffer (Named)
         *      Buffer      --> Integer or String (Named)
         */
        switch (TargetType)
        {
        case ACPI_TYPE_PACKAGE:
            /*
             * Here, can only store a package to an existing package.
             * Storing a package to a Local/Arg is OK, and handled
             * elsewhere.
             */
            if (WalkState->Opcode == AML_STORE_OP)
            {
                if (SourceDesc->Common.Type != ACPI_TYPE_PACKAGE)
                {
                    ACPI_ERROR ((AE_INFO,
                        "Cannot assign type [%s] to [Package] "
                        "(source must be type Pkg)",
                        AcpiUtGetObjectTypeName (SourceDesc)));

                    return_ACPI_STATUS (AE_AML_TARGET_TYPE);
                }
                break;
            }

        /* Fallthrough */

        case ACPI_TYPE_DEVICE:
        case ACPI_TYPE_EVENT:
        case ACPI_TYPE_MUTEX:
        case ACPI_TYPE_REGION:
        case ACPI_TYPE_POWER:
        case ACPI_TYPE_PROCESSOR:
        case ACPI_TYPE_THERMAL:

            ACPI_ERROR ((AE_INFO,
                "Target must be [Buffer/Integer/String/Reference]"
                ", found [%s] (%4.4s)",
                AcpiUtGetTypeName (Node->Type), Node->Name.Ascii));

            return_ACPI_STATUS (AE_AML_TARGET_TYPE);

        default:
            break;
        }
    }

    /*
     * Resolve the source object to an actual value
     * (If it is a reference object)
     */
    Status = AcpiExResolveObject (&SourceDesc, TargetType, WalkState);
    if (ACPI_FAILURE (Status))
    {
        return_ACPI_STATUS (Status);
    }

    /* Do the actual store operation */

    switch (TargetType)
    {
        /*
         * The simple data types all support implicit source operand
         * conversion before the store.
         */
    case ACPI_TYPE_INTEGER:
    case ACPI_TYPE_STRING:
    case ACPI_TYPE_BUFFER:

        if ((WalkState->Opcode == AML_COPY_OBJECT_OP) ||
            !ImplicitConversion)
        {
            /*
             * However, CopyObject and Stores to ArgX do not perform
             * an implicit conversion, as per the ACPI specification.
             * A direct store is performed instead.
             */
            Status = AcpiExStoreDirectToNode (SourceDesc, Node, WalkState);
            break;
        }

        /* Store with implicit source operand conversion support */

        Status = AcpiExStoreObjectToObject (SourceDesc, TargetDesc,
            &NewDesc, WalkState);
        if (ACPI_FAILURE (Status))
        {
            return_ACPI_STATUS (Status);
        }

        if (NewDesc != TargetDesc)
        {
            /*
             * Store the new NewDesc as the new value of the Name, and set
             * the Name's type to that of the value being stored in it.
             * SourceDesc reference count is incremented by AttachObject.
             *
             * Note: This may change the type of the node if an explicit
             * store has been performed such that the node/object type
             * has been changed.
             */
            Status = AcpiNsAttachObject (
                Node, NewDesc, NewDesc->Common.Type);

            ACPI_DEBUG_PRINT ((ACPI_DB_EXEC,
                "Store type [%s] into [%s] via Convert/Attach\n",
                AcpiUtGetObjectTypeName (SourceDesc),
                AcpiUtGetObjectTypeName (NewDesc)));
        }
        break;

    case ACPI_TYPE_BUFFER_FIELD:
    case ACPI_TYPE_LOCAL_REGION_FIELD:
    case ACPI_TYPE_LOCAL_BANK_FIELD:
    case ACPI_TYPE_LOCAL_INDEX_FIELD:
        /*
         * For all fields, always write the source data to the target
         * field. Any required implicit source operand conversion is
         * performed in the function below as necessary. Note, field
         * objects must retain their original type permanently.
         */
        Status = AcpiExWriteDataToField (SourceDesc, TargetDesc,
            &WalkState->ResultObj);
        break;

    default:
        /*
         * CopyObject operator: No conversions for all other types.
         * Instead, directly store a copy of the source object.
         *
         * This is the ACPI spec-defined behavior for the CopyObject
         * operator. (Note, for this default case, all normal
         * Store/Target operations exited above with an error).
         */
        Status = AcpiExStoreDirectToNode (SourceDesc, Node, WalkState);
        break;
    }

    return_ACPI_STATUS (Status);
}

__attribute__((used)) static ACPI_STATUS
AcpiExStoreDirectToNode (
    ACPI_OPERAND_OBJECT     *SourceDesc,
    ACPI_NAMESPACE_NODE     *Node,
    ACPI_WALK_STATE         *WalkState)
{
    ACPI_STATUS             Status;
    ACPI_OPERAND_OBJECT     *NewDesc;


    ACPI_FUNCTION_TRACE (ExStoreDirectToNode);


    ACPI_DEBUG_PRINT ((ACPI_DB_EXEC,
        "Storing [%s] (%p) directly into node [%s] (%p)"
        " with no implicit conversion\n",
        AcpiUtGetObjectTypeName (SourceDesc), SourceDesc,
        AcpiUtGetTypeName (Node->Type), Node));

    /* Copy the source object to a new object */

    Status = AcpiUtCopyIobjectToIobject (SourceDesc, &NewDesc, WalkState);
    if (ACPI_FAILURE (Status))
    {
        return_ACPI_STATUS (Status);
    }

    /* Attach the new object to the node */

    Status = AcpiNsAttachObject (Node, NewDesc, NewDesc->Common.Type);
    AcpiUtRemoveReference (NewDesc);
    return_ACPI_STATUS (Status);
}

