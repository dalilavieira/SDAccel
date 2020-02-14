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
typedef  struct TYPE_28__   TYPE_22__ ;
typedef  struct TYPE_27__   TYPE_1__ ;
typedef  struct TYPE_26__   TYPE_16__ ;
typedef  struct TYPE_25__   TYPE_12__ ;
typedef  struct TYPE_24__   TYPE_11__ ;
typedef  struct TYPE_23__   TYPE_10__ ;

/* Type definitions */
typedef  int UINT8 ;
typedef  int UINT32 ;
typedef  int /*<<< orphan*/  UINT16 ;
struct TYPE_36__ {int FieldFlags; int Attribute; int BitLength; int AccessByteWidth; int BaseByteOffset; int StartFieldBitOffset; int /*<<< orphan*/  Node; } ;
struct TYPE_35__ {scalar_t__ Type; int Flags; TYPE_11__* NextObject; } ;
struct TYPE_34__ {int Value; int AccessByteWidth; TYPE_16__* DataObj; TYPE_16__* IndexObj; int /*<<< orphan*/  BaseByteOffset; int /*<<< orphan*/  StartFieldBitOffset; } ;
struct TYPE_33__ {int /*<<< orphan*/  Length; int /*<<< orphan*/  Data; } ;
struct TYPE_32__ {int /*<<< orphan*/  AmlLength; int /*<<< orphan*/  AmlStart; } ;
struct TYPE_31__ {TYPE_16__* BankObj; TYPE_16__* RegionObj; int /*<<< orphan*/  BaseByteOffset; int /*<<< orphan*/  StartFieldBitOffset; int /*<<< orphan*/  Value; } ;
struct TYPE_30__ {int /*<<< orphan*/  SpaceId; } ;
struct TYPE_29__ {int /*<<< orphan*/  Length; int /*<<< orphan*/  Pointer; } ;
struct TYPE_28__ {TYPE_6__ Named; } ;
struct TYPE_27__ {TYPE_11__* Object; } ;
struct TYPE_26__ {TYPE_3__ Region; } ;
struct TYPE_25__ {int FieldType; int FieldFlags; int Attribute; int FieldBitPosition; int FieldBitLength; int /*<<< orphan*/  FieldNode; int /*<<< orphan*/  DataRegisterNode; int /*<<< orphan*/  RegisterNode; int /*<<< orphan*/  RegionNode; int /*<<< orphan*/  BankValue; int /*<<< orphan*/  PinNumberIndex; int /*<<< orphan*/  ResourceLength; int /*<<< orphan*/  ResourceBuffer; TYPE_1__* ConnectionNode; int /*<<< orphan*/  AccessLength; } ;
struct TYPE_23__ {int /*<<< orphan*/  AccessByteWidth; TYPE_16__* RegionObj; int /*<<< orphan*/  BaseByteOffset; int /*<<< orphan*/  StartFieldBitOffset; int /*<<< orphan*/  PinNumberIndex; int /*<<< orphan*/  ResourceLength; int /*<<< orphan*/  ResourceBuffer; int /*<<< orphan*/  AccessLength; } ;
struct TYPE_24__ {TYPE_7__ IndexField; TYPE_10__ Field; TYPE_5__ Extra; TYPE_8__ Common; TYPE_4__ BankField; TYPE_9__ CommonField; TYPE_2__ Buffer; } ;
typedef  int /*<<< orphan*/  ACPI_STATUS ;
typedef  TYPE_11__ ACPI_OPERAND_OBJECT ;
typedef  TYPE_12__ ACPI_CREATE_FIELD_INFO ;

/* Variables and functions */
 int /*<<< orphan*/  ACPI_ADR_SPACE_EC ; 
 TYPE_22__* ACPI_CAST_PTR (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ACPI_DB_BFIELD ; 
 int /*<<< orphan*/  ACPI_DEBUG_PRINT (int /*<<< orphan*/ ) ; 
 int ACPI_DIV_8 (int) ; 
 int /*<<< orphan*/  ACPI_ERROR (int /*<<< orphan*/ ) ; 
 scalar_t__ ACPI_FAILURE (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ACPI_FUNCTION_TRACE (int /*<<< orphan*/ ) ; 
 int ACPI_MUL_8 (int) ; 
 int /*<<< orphan*/  ACPI_PARSE_OBJECT ; 
 int ACPI_ROUND_BITS_DOWN_TO_BYTES (int) ; 
 int ACPI_ROUND_BITS_UP_TO_BYTES (int) ; 
 scalar_t__ ACPI_ROUND_DOWN (int,int) ; 
 scalar_t__ ACPI_TYPE_BUFFER_FIELD ; 
#define  ACPI_TYPE_LOCAL_BANK_FIELD 136 
#define  ACPI_TYPE_LOCAL_INDEX_FIELD 135 
#define  ACPI_TYPE_LOCAL_REGION_FIELD 134 
 int ACPI_TYPE_REGION ; 
 int /*<<< orphan*/  AE_AML_INTERNAL ; 
 int /*<<< orphan*/  AE_AML_NO_OPERAND ; 
 int /*<<< orphan*/  AE_AML_OPERAND_TYPE ; 
 int /*<<< orphan*/  AE_AML_OPERAND_VALUE ; 
 int /*<<< orphan*/  AE_INFO ; 
 int /*<<< orphan*/  AE_NO_MEMORY ; 
 int /*<<< orphan*/  AE_OK ; 
#define  AML_FIELD_ACCESS_ANY 133 
#define  AML_FIELD_ACCESS_BUFFER 132 
#define  AML_FIELD_ACCESS_BYTE 131 
#define  AML_FIELD_ACCESS_DWORD 130 
#define  AML_FIELD_ACCESS_QWORD 129 
 int AML_FIELD_ACCESS_TYPE_MASK ; 
#define  AML_FIELD_ACCESS_WORD 128 
 int AOPOBJ_DATA_VALID ; 
 int /*<<< orphan*/  AcpiDsGetBufferArguments (TYPE_11__*) ; 
 int /*<<< orphan*/  AcpiNsAttachObject (int /*<<< orphan*/ ,TYPE_11__*,int) ; 
 void* AcpiNsGetAttachedObject (int /*<<< orphan*/ ) ; 
 int AcpiNsGetType (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  AcpiUtAddReference (TYPE_16__*) ; 
 TYPE_11__* AcpiUtCreateInternalObject (int) ; 
 int /*<<< orphan*/  AcpiUtDeleteObjectDesc (TYPE_11__*) ; 
 int /*<<< orphan*/  AcpiUtGetNodeName (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  AcpiUtGetTypeName (int) ; 
 int /*<<< orphan*/  AcpiUtRemoveReference (TYPE_11__*) ; 
 int /*<<< orphan*/  ExDecodeFieldAccess ; 
 int /*<<< orphan*/  ExPrepCommonFieldObject ; 
 int /*<<< orphan*/  ExPrepFieldValue ; 
 int /*<<< orphan*/  return_ACPI_STATUS (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  return_UINT32 (int) ; 

__attribute__((used)) static UINT32
AcpiExDecodeFieldAccess (
    ACPI_OPERAND_OBJECT     *ObjDesc,
    UINT8                   FieldFlags,
    UINT32                  *ReturnByteAlignment)
{
    UINT32                  Access;
    UINT32                  ByteAlignment;
    UINT32                  BitLength;


    ACPI_FUNCTION_TRACE (ExDecodeFieldAccess);


    Access = (FieldFlags & AML_FIELD_ACCESS_TYPE_MASK);

    switch (Access)
    {
    case AML_FIELD_ACCESS_ANY:

#ifdef ACPI_UNDER_DEVELOPMENT
        ByteAlignment =
            AcpiExGenerateAccess (ObjDesc->CommonField.StartFieldBitOffset,
                ObjDesc->CommonField.BitLength,
                0xFFFFFFFF /* Temp until we pass RegionLength as parameter */);
        BitLength = ByteAlignment * 8;
#endif

        ByteAlignment = 1;
        BitLength = 8;
        break;

    case AML_FIELD_ACCESS_BYTE:
    case AML_FIELD_ACCESS_BUFFER:   /* ACPI 2.0 (SMBus Buffer) */

        ByteAlignment = 1;
        BitLength     = 8;
        break;

    case AML_FIELD_ACCESS_WORD:

        ByteAlignment = 2;
        BitLength     = 16;
        break;

    case AML_FIELD_ACCESS_DWORD:

        ByteAlignment = 4;
        BitLength     = 32;
        break;

    case AML_FIELD_ACCESS_QWORD:    /* ACPI 2.0 */

        ByteAlignment = 8;
        BitLength     = 64;
        break;

    default:

        /* Invalid field access type */

        ACPI_ERROR ((AE_INFO,
            "Unknown field access type 0x%X",
            Access));

        return_UINT32 (0);
    }

    if (ObjDesc->Common.Type == ACPI_TYPE_BUFFER_FIELD)
    {
        /*
         * BufferField access can be on any byte boundary, so the
         * ByteAlignment is always 1 byte -- regardless of any ByteAlignment
         * implied by the field access type.
         */
        ByteAlignment = 1;
    }

    *ReturnByteAlignment = ByteAlignment;
    return_UINT32 (BitLength);
}

ACPI_STATUS
AcpiExPrepCommonFieldObject (
    ACPI_OPERAND_OBJECT     *ObjDesc,
    UINT8                   FieldFlags,
    UINT8                   FieldAttribute,
    UINT32                  FieldBitPosition,
    UINT32                  FieldBitLength)
{
    UINT32                  AccessBitWidth;
    UINT32                  ByteAlignment;
    UINT32                  NearestByteAddress;


    ACPI_FUNCTION_TRACE (ExPrepCommonFieldObject);


    /*
     * Note: the structure being initialized is the
     * ACPI_COMMON_FIELD_INFO;  No structure fields outside of the common
     * area are initialized by this procedure.
     */
    ObjDesc->CommonField.FieldFlags = FieldFlags;
    ObjDesc->CommonField.Attribute  = FieldAttribute;
    ObjDesc->CommonField.BitLength  = FieldBitLength;

    /*
     * Decode the access type so we can compute offsets. The access type gives
     * two pieces of information - the width of each field access and the
     * necessary ByteAlignment (address granularity) of the access.
     *
     * For AnyAcc, the AccessBitWidth is the largest width that is both
     * necessary and possible in an attempt to access the whole field in one
     * I/O operation. However, for AnyAcc, the ByteAlignment is always one
     * byte.
     *
     * For all Buffer Fields, the ByteAlignment is always one byte.
     *
     * For all other access types (Byte, Word, Dword, Qword), the Bitwidth is
     * the same (equivalent) as the ByteAlignment.
     */
    AccessBitWidth = AcpiExDecodeFieldAccess (
        ObjDesc, FieldFlags, &ByteAlignment);
    if (!AccessBitWidth)
    {
        return_ACPI_STATUS (AE_AML_OPERAND_VALUE);
    }

    /* Setup width (access granularity) fields (values are: 1, 2, 4, 8) */

    ObjDesc->CommonField.AccessByteWidth = (UINT8)
        ACPI_DIV_8 (AccessBitWidth);

    /*
     * BaseByteOffset is the address of the start of the field within the
     * region. It is the byte address of the first *datum* (field-width data
     * unit) of the field. (i.e., the first datum that contains at least the
     * first *bit* of the field.)
     *
     * Note: ByteAlignment is always either equal to the AccessBitWidth or 8
     * (Byte access), and it defines the addressing granularity of the parent
     * region or buffer.
     */
    NearestByteAddress =
        ACPI_ROUND_BITS_DOWN_TO_BYTES (FieldBitPosition);
    ObjDesc->CommonField.BaseByteOffset = (UINT32)
        ACPI_ROUND_DOWN (NearestByteAddress, ByteAlignment);

    /*
     * StartFieldBitOffset is the offset of the first bit of the field within
     * a field datum.
     */
    ObjDesc->CommonField.StartFieldBitOffset = (UINT8)
        (FieldBitPosition - ACPI_MUL_8 (ObjDesc->CommonField.BaseByteOffset));

    return_ACPI_STATUS (AE_OK);
}

ACPI_STATUS
AcpiExPrepFieldValue (
    ACPI_CREATE_FIELD_INFO  *Info)
{
    ACPI_OPERAND_OBJECT     *ObjDesc;
    ACPI_OPERAND_OBJECT     *SecondDesc = NULL;
    ACPI_STATUS             Status;
    UINT32                  AccessByteWidth;
    UINT32                  Type;


    ACPI_FUNCTION_TRACE (ExPrepFieldValue);


    /* Parameter validation */

    if (Info->FieldType != ACPI_TYPE_LOCAL_INDEX_FIELD)
    {
        if (!Info->RegionNode)
        {
            ACPI_ERROR ((AE_INFO, "Null RegionNode"));
            return_ACPI_STATUS (AE_AML_NO_OPERAND);
        }

        Type = AcpiNsGetType (Info->RegionNode);
        if (Type != ACPI_TYPE_REGION)
        {
            ACPI_ERROR ((AE_INFO, "Needed Region, found type 0x%X (%s)",
                Type, AcpiUtGetTypeName (Type)));

            return_ACPI_STATUS (AE_AML_OPERAND_TYPE);
        }
    }

    /* Allocate a new field object */

    ObjDesc = AcpiUtCreateInternalObject (Info->FieldType);
    if (!ObjDesc)
    {
        return_ACPI_STATUS (AE_NO_MEMORY);
    }

    /* Initialize areas of the object that are common to all fields */

    ObjDesc->CommonField.Node = Info->FieldNode;
    Status = AcpiExPrepCommonFieldObject (ObjDesc,
        Info->FieldFlags, Info->Attribute,
        Info->FieldBitPosition, Info->FieldBitLength);
    if (ACPI_FAILURE (Status))
    {
        AcpiUtDeleteObjectDesc (ObjDesc);
        return_ACPI_STATUS (Status);
    }

    /* Initialize areas of the object that are specific to the field type */

    switch (Info->FieldType)
    {
    case ACPI_TYPE_LOCAL_REGION_FIELD:

        ObjDesc->Field.RegionObj = AcpiNsGetAttachedObject (Info->RegionNode);

        /* Fields specific to GenericSerialBus fields */

        ObjDesc->Field.AccessLength = Info->AccessLength;

        if (Info->ConnectionNode)
        {
            SecondDesc = Info->ConnectionNode->Object;
            if (!(SecondDesc->Common.Flags & AOPOBJ_DATA_VALID))
            {
                Status = AcpiDsGetBufferArguments (SecondDesc);
                if (ACPI_FAILURE (Status))
                {
                    AcpiUtDeleteObjectDesc (ObjDesc);
                    return_ACPI_STATUS (Status);
                }
            }

            ObjDesc->Field.ResourceBuffer =
                SecondDesc->Buffer.Pointer;
            ObjDesc->Field.ResourceLength =
                (UINT16) SecondDesc->Buffer.Length;
        }
        else if (Info->ResourceBuffer)
        {
            ObjDesc->Field.ResourceBuffer = Info->ResourceBuffer;
            ObjDesc->Field.ResourceLength = Info->ResourceLength;
        }

        ObjDesc->Field.PinNumberIndex = Info->PinNumberIndex;

        /* Allow full data read from EC address space */

        if ((ObjDesc->Field.RegionObj->Region.SpaceId == ACPI_ADR_SPACE_EC) &&
            (ObjDesc->CommonField.BitLength > 8))
        {
            AccessByteWidth = ACPI_ROUND_BITS_UP_TO_BYTES (
                ObjDesc->CommonField.BitLength);

            /* Maximum byte width supported is 255 */

            if (AccessByteWidth < 256)
            {
                ObjDesc->CommonField.AccessByteWidth =
                    (UINT8) AccessByteWidth;
            }
        }

        /* An additional reference for the container */

        AcpiUtAddReference (ObjDesc->Field.RegionObj);

        ACPI_DEBUG_PRINT ((ACPI_DB_BFIELD,
            "RegionField: BitOff %X, Off %X, Gran %X, Region %p\n",
            ObjDesc->Field.StartFieldBitOffset,
            ObjDesc->Field.BaseByteOffset,
            ObjDesc->Field.AccessByteWidth,
            ObjDesc->Field.RegionObj));
        break;

    case ACPI_TYPE_LOCAL_BANK_FIELD:

        ObjDesc->BankField.Value = Info->BankValue;
        ObjDesc->BankField.RegionObj =
            AcpiNsGetAttachedObject (Info->RegionNode);
        ObjDesc->BankField.BankObj =
            AcpiNsGetAttachedObject (Info->RegisterNode);

        /* An additional reference for the attached objects */

        AcpiUtAddReference (ObjDesc->BankField.RegionObj);
        AcpiUtAddReference (ObjDesc->BankField.BankObj);

        ACPI_DEBUG_PRINT ((ACPI_DB_BFIELD,
            "Bank Field: BitOff %X, Off %X, Gran %X, Region %p, BankReg %p\n",
            ObjDesc->BankField.StartFieldBitOffset,
            ObjDesc->BankField.BaseByteOffset,
            ObjDesc->Field.AccessByteWidth,
            ObjDesc->BankField.RegionObj,
            ObjDesc->BankField.BankObj));

        /*
         * Remember location in AML stream of the field unit
         * opcode and operands -- since the BankValue
         * operands must be evaluated.
         */
        SecondDesc = ObjDesc->Common.NextObject;
        SecondDesc->Extra.AmlStart = ACPI_CAST_PTR (ACPI_PARSE_OBJECT,
            Info->DataRegisterNode)->Named.Data;
        SecondDesc->Extra.AmlLength = ACPI_CAST_PTR (ACPI_PARSE_OBJECT,
            Info->DataRegisterNode)->Named.Length;

        break;

    case ACPI_TYPE_LOCAL_INDEX_FIELD:

        /* Get the Index and Data registers */

        ObjDesc->IndexField.IndexObj =
            AcpiNsGetAttachedObject (Info->RegisterNode);
        ObjDesc->IndexField.DataObj =
            AcpiNsGetAttachedObject (Info->DataRegisterNode);

        if (!ObjDesc->IndexField.DataObj || !ObjDesc->IndexField.IndexObj)
        {
            ACPI_ERROR ((AE_INFO, "Null Index Object during field prep"));
            AcpiUtDeleteObjectDesc (ObjDesc);
            return_ACPI_STATUS (AE_AML_INTERNAL);
        }

        /* An additional reference for the attached objects */

        AcpiUtAddReference (ObjDesc->IndexField.DataObj);
        AcpiUtAddReference (ObjDesc->IndexField.IndexObj);

        /*
         * April 2006: Changed to match MS behavior
         *
         * The value written to the Index register is the byte offset of the
         * target field in units of the granularity of the IndexField
         *
         * Previously, the value was calculated as an index in terms of the
         * width of the Data register, as below:
         *
         *      ObjDesc->IndexField.Value = (UINT32)
         *          (Info->FieldBitPosition / ACPI_MUL_8 (
         *              ObjDesc->Field.AccessByteWidth));
         *
         * February 2006: Tried value as a byte offset:
         *      ObjDesc->IndexField.Value = (UINT32)
         *          ACPI_DIV_8 (Info->FieldBitPosition);
         */
        ObjDesc->IndexField.Value = (UINT32) ACPI_ROUND_DOWN (
            ACPI_DIV_8 (Info->FieldBitPosition),
            ObjDesc->IndexField.AccessByteWidth);

        ACPI_DEBUG_PRINT ((ACPI_DB_BFIELD,
            "IndexField: BitOff %X, Off %X, Value %X, "
            "Gran %X, Index %p, Data %p\n",
            ObjDesc->IndexField.StartFieldBitOffset,
            ObjDesc->IndexField.BaseByteOffset,
            ObjDesc->IndexField.Value,
            ObjDesc->Field.AccessByteWidth,
            ObjDesc->IndexField.IndexObj,
            ObjDesc->IndexField.DataObj));
        break;

    default:

        /* No other types should get here */

        break;
    }

    /*
     * Store the constructed descriptor (ObjDesc) into the parent Node,
     * preserving the current type of that NamedObj.
     */
    Status = AcpiNsAttachObject (
        Info->FieldNode, ObjDesc, AcpiNsGetType (Info->FieldNode));

    ACPI_DEBUG_PRINT ((ACPI_DB_BFIELD,
        "Set NamedObj %p [%4.4s], ObjDesc %p\n",
        Info->FieldNode, AcpiUtGetNodeName (Info->FieldNode), ObjDesc));

    /* Remove local reference to the object */

    AcpiUtRemoveReference (ObjDesc);
    return_ACPI_STATUS (Status);
}

