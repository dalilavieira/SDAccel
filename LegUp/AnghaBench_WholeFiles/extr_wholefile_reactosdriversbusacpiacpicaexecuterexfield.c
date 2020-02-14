#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_42__   TYPE_9__ ;
typedef  struct TYPE_41__   TYPE_8__ ;
typedef  struct TYPE_40__   TYPE_7__ ;
typedef  struct TYPE_39__   TYPE_6__ ;
typedef  struct TYPE_38__   TYPE_5__ ;
typedef  struct TYPE_37__   TYPE_4__ ;
typedef  struct TYPE_36__   TYPE_3__ ;
typedef  struct TYPE_35__   TYPE_2__ ;
typedef  struct TYPE_34__   TYPE_1__ ;
typedef  struct TYPE_33__   TYPE_10__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  UINT64 ;
typedef  size_t UINT32 ;
struct TYPE_42__ {int /*<<< orphan*/  FieldFlags; int /*<<< orphan*/  BaseByteOffset; int /*<<< orphan*/  StartFieldBitOffset; int /*<<< orphan*/  BitLength; } ;
struct TYPE_41__ {scalar_t__ Type; int Flags; } ;
struct TYPE_40__ {int BaseByteOffset; TYPE_6__* RegionObj; int /*<<< orphan*/  BitLength; } ;
struct TYPE_38__ {int InternalPccBuffer; } ;
struct TYPE_37__ {scalar_t__ SpaceId; scalar_t__ Address; } ;
struct TYPE_39__ {TYPE_5__ Field; TYPE_4__ Region; } ;
struct TYPE_36__ {int /*<<< orphan*/  Value; } ;
struct TYPE_35__ {int Pointer; size_t Length; } ;
struct TYPE_34__ {size_t Length; void* Pointer; } ;
struct TYPE_33__ {TYPE_9__ CommonField; TYPE_8__ Common; TYPE_1__ String; TYPE_2__ Buffer; TYPE_3__ Integer; TYPE_7__ Field; } ;
typedef  int /*<<< orphan*/  ACPI_WALK_STATE ;
typedef  int /*<<< orphan*/  ACPI_STATUS ;
typedef  size_t ACPI_SIZE ;
typedef  TYPE_10__ ACPI_OPERAND_OBJECT ;

/* Variables and functions */
 scalar_t__ ACPI_ADR_SPACE_GPIO ; 
 scalar_t__ ACPI_ADR_SPACE_GSBUS ; 
 scalar_t__ ACPI_ADR_SPACE_IPMI ; 
 scalar_t__ ACPI_ADR_SPACE_PLATFORM_COMM ; 
 scalar_t__ ACPI_ADR_SPACE_SMBUS ; 
 int /*<<< orphan*/  ACPI_DB_BFIELD ; 
 int /*<<< orphan*/  ACPI_DEBUG_PRINT (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ACPI_ERROR (int /*<<< orphan*/ ) ; 
 scalar_t__ ACPI_FAILURE (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ACPI_FUNCTION_TRACE_PTR (int /*<<< orphan*/ ,TYPE_10__*) ; 
 scalar_t__ ACPI_INVALID_PROTOCOL_ID ; 
 size_t ACPI_MAX_PROTOCOL_ID ; 
 scalar_t__ ACPI_ROUND_BITS_UP_TO_BYTES (int /*<<< orphan*/ ) ; 
#define  ACPI_TYPE_BUFFER 130 
 scalar_t__ ACPI_TYPE_BUFFER_FIELD ; 
#define  ACPI_TYPE_INTEGER 129 
 scalar_t__ ACPI_TYPE_LOCAL_REGION_FIELD ; 
#define  ACPI_TYPE_STRING 128 
 int /*<<< orphan*/  ACPI_WRITE ; 
 int /*<<< orphan*/  AE_AML_NO_OPERAND ; 
 int /*<<< orphan*/  AE_AML_OPERAND_TYPE ; 
 int /*<<< orphan*/  AE_AML_PROTOCOL ; 
 int /*<<< orphan*/  AE_BAD_PARAMETER ; 
 int /*<<< orphan*/  AE_INFO ; 
 int /*<<< orphan*/  AE_NO_MEMORY ; 
 int /*<<< orphan*/  AE_OK ; 
 int AOPOBJ_DATA_VALID ; 
 int /*<<< orphan*/  AcpiDsGetBufferFieldArguments (TYPE_10__*) ; 
 int /*<<< orphan*/  AcpiExAccessRegion (TYPE_10__*,int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  AcpiExAcquireGlobalLock (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  AcpiExExtractFromField (TYPE_10__*,void*,size_t) ; 
 int /*<<< orphan*/  AcpiExInsertIntoField (TYPE_10__*,void*,size_t) ; 
 int /*<<< orphan*/  AcpiExReadGpio (TYPE_10__*,void*) ; 
 int /*<<< orphan*/  AcpiExReadSerialBus (TYPE_10__*,TYPE_10__**) ; 
 int /*<<< orphan*/  AcpiExReleaseGlobalLock (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  AcpiExWriteGpio (TYPE_10__*,TYPE_10__*,TYPE_10__**) ; 
 int /*<<< orphan*/  AcpiExWriteSerialBus (TYPE_10__*,TYPE_10__*,TYPE_10__**) ; 
 size_t AcpiGbl_IntegerByteWidth ; 
 scalar_t__* AcpiProtocolLengths ; 
 TYPE_10__* AcpiUtCreateBufferObject (size_t) ; 
 TYPE_10__* AcpiUtCreateIntegerObject (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  AcpiUtGetTypeName (int) ; 
 int /*<<< orphan*/  AcpiUtRemoveReference (TYPE_10__*) ; 
 int /*<<< orphan*/  ExReadDataFromField ; 
 int /*<<< orphan*/  ExWriteDataToField ; 
 scalar_t__ GENERIC_SUBSPACE_COMMAND (int) ; 
 scalar_t__ MASTER_SUBSPACE_COMMAND (int) ; 
 scalar_t__ PCC_MASTER_SUBSPACE ; 
 int /*<<< orphan*/  memcpy (void*,int,size_t) ; 
 int /*<<< orphan*/  return_ACPI_STATUS (int /*<<< orphan*/ ) ; 

ACPI_STATUS
AcpiExGetProtocolBufferLength (
    UINT32                  ProtocolId,
    UINT32                  *ReturnLength)
{

    if ((ProtocolId > ACPI_MAX_PROTOCOL_ID) ||
        (AcpiProtocolLengths[ProtocolId] == ACPI_INVALID_PROTOCOL_ID))
    {
        ACPI_ERROR ((AE_INFO,
            "Invalid Field/AccessAs protocol ID: 0x%4.4X", ProtocolId));

        return (AE_AML_PROTOCOL);
    }

    *ReturnLength = AcpiProtocolLengths[ProtocolId];
    return (AE_OK);
}

ACPI_STATUS
AcpiExReadDataFromField (
    ACPI_WALK_STATE         *WalkState,
    ACPI_OPERAND_OBJECT     *ObjDesc,
    ACPI_OPERAND_OBJECT     **RetBufferDesc)
{
    ACPI_STATUS             Status;
    ACPI_OPERAND_OBJECT     *BufferDesc;
    void                    *Buffer;
    UINT32                  BufferLength;


    ACPI_FUNCTION_TRACE_PTR (ExReadDataFromField, ObjDesc);


    /* Parameter validation */

    if (!ObjDesc)
    {
        return_ACPI_STATUS (AE_AML_NO_OPERAND);
    }
    if (!RetBufferDesc)
    {
        return_ACPI_STATUS (AE_BAD_PARAMETER);
    }

    if (ObjDesc->Common.Type == ACPI_TYPE_BUFFER_FIELD)
    {
        /*
         * If the BufferField arguments have not been previously evaluated,
         * evaluate them now and save the results.
         */
        if (!(ObjDesc->Common.Flags & AOPOBJ_DATA_VALID))
        {
            Status = AcpiDsGetBufferFieldArguments (ObjDesc);
            if (ACPI_FAILURE (Status))
            {
                return_ACPI_STATUS (Status);
            }
        }
    }
    else if ((ObjDesc->Common.Type == ACPI_TYPE_LOCAL_REGION_FIELD) &&
        (ObjDesc->Field.RegionObj->Region.SpaceId == ACPI_ADR_SPACE_SMBUS ||
         ObjDesc->Field.RegionObj->Region.SpaceId == ACPI_ADR_SPACE_GSBUS ||
         ObjDesc->Field.RegionObj->Region.SpaceId == ACPI_ADR_SPACE_IPMI))
    {
        /* SMBus, GSBus, IPMI serial */

        Status = AcpiExReadSerialBus (ObjDesc, RetBufferDesc);
        return_ACPI_STATUS (Status);
    }

    /*
     * Allocate a buffer for the contents of the field.
     *
     * If the field is larger than the current integer width, create
     * a BUFFER to hold it. Otherwise, use an INTEGER. This allows
     * the use of arithmetic operators on the returned value if the
     * field size is equal or smaller than an Integer.
     *
     * Note: Field.length is in bits.
     */
    BufferLength = (ACPI_SIZE) ACPI_ROUND_BITS_UP_TO_BYTES (
        ObjDesc->Field.BitLength);

    if (BufferLength > AcpiGbl_IntegerByteWidth)
    {
        /* Field is too large for an Integer, create a Buffer instead */

        BufferDesc = AcpiUtCreateBufferObject (BufferLength);
        if (!BufferDesc)
        {
            return_ACPI_STATUS (AE_NO_MEMORY);
        }
        Buffer = BufferDesc->Buffer.Pointer;
    }
    else
    {
        /* Field will fit within an Integer (normal case) */

        BufferDesc = AcpiUtCreateIntegerObject ((UINT64) 0);
        if (!BufferDesc)
        {
            return_ACPI_STATUS (AE_NO_MEMORY);
        }

        BufferLength = AcpiGbl_IntegerByteWidth;
        Buffer = &BufferDesc->Integer.Value;
    }

    if ((ObjDesc->Common.Type == ACPI_TYPE_LOCAL_REGION_FIELD) &&
        (ObjDesc->Field.RegionObj->Region.SpaceId == ACPI_ADR_SPACE_GPIO))
    {
        /* General Purpose I/O */

        Status = AcpiExReadGpio (ObjDesc, Buffer);
        goto Exit;
    }
    else if ((ObjDesc->Common.Type == ACPI_TYPE_LOCAL_REGION_FIELD) &&
        (ObjDesc->Field.RegionObj->Region.SpaceId == ACPI_ADR_SPACE_PLATFORM_COMM))
    {
        /*
         * Reading from a PCC field unit does not require the handler because
         * it only requires reading from the InternalPccBuffer.
         */
        ACPI_DEBUG_PRINT ((ACPI_DB_BFIELD,
            "PCC FieldRead bits %u\n", ObjDesc->Field.BitLength));

        memcpy (Buffer, ObjDesc->Field.RegionObj->Field.InternalPccBuffer +
        ObjDesc->Field.BaseByteOffset, (ACPI_SIZE) ACPI_ROUND_BITS_UP_TO_BYTES (
            ObjDesc->Field.BitLength));

        *RetBufferDesc = BufferDesc;
        return AE_OK;
    }

    ACPI_DEBUG_PRINT ((ACPI_DB_BFIELD,
        "FieldRead [TO]:   Obj %p, Type %X, Buf %p, ByteLen %X\n",
        ObjDesc, ObjDesc->Common.Type, Buffer, BufferLength));
    ACPI_DEBUG_PRINT ((ACPI_DB_BFIELD,
        "FieldRead [FROM]: BitLen %X, BitOff %X, ByteOff %X\n",
        ObjDesc->CommonField.BitLength,
        ObjDesc->CommonField.StartFieldBitOffset,
        ObjDesc->CommonField.BaseByteOffset));

    /* Lock entire transaction if requested */

    AcpiExAcquireGlobalLock (ObjDesc->CommonField.FieldFlags);

    /* Read from the field */

    Status = AcpiExExtractFromField (ObjDesc, Buffer, BufferLength);
    AcpiExReleaseGlobalLock (ObjDesc->CommonField.FieldFlags);


Exit:
    if (ACPI_FAILURE (Status))
    {
        AcpiUtRemoveReference (BufferDesc);
    }
    else
    {
        *RetBufferDesc = BufferDesc;
    }

    return_ACPI_STATUS (Status);
}

ACPI_STATUS
AcpiExWriteDataToField (
    ACPI_OPERAND_OBJECT     *SourceDesc,
    ACPI_OPERAND_OBJECT     *ObjDesc,
    ACPI_OPERAND_OBJECT     **ResultDesc)
{
    ACPI_STATUS             Status;
    UINT32                  BufferLength;
    UINT32                  DataLength;
    void                    *Buffer;


    ACPI_FUNCTION_TRACE_PTR (ExWriteDataToField, ObjDesc);


    /* Parameter validation */

    if (!SourceDesc || !ObjDesc)
    {
        return_ACPI_STATUS (AE_AML_NO_OPERAND);
    }

    if (ObjDesc->Common.Type == ACPI_TYPE_BUFFER_FIELD)
    {
        /*
         * If the BufferField arguments have not been previously evaluated,
         * evaluate them now and save the results.
         */
        if (!(ObjDesc->Common.Flags & AOPOBJ_DATA_VALID))
        {
            Status = AcpiDsGetBufferFieldArguments (ObjDesc);
            if (ACPI_FAILURE (Status))
            {
                return_ACPI_STATUS (Status);
            }
        }
    }
    else if ((ObjDesc->Common.Type == ACPI_TYPE_LOCAL_REGION_FIELD) &&
        (ObjDesc->Field.RegionObj->Region.SpaceId == ACPI_ADR_SPACE_GPIO))
    {
        /* General Purpose I/O */

        Status = AcpiExWriteGpio (SourceDesc, ObjDesc, ResultDesc);
        return_ACPI_STATUS (Status);
    }
    else if ((ObjDesc->Common.Type == ACPI_TYPE_LOCAL_REGION_FIELD) &&
        (ObjDesc->Field.RegionObj->Region.SpaceId == ACPI_ADR_SPACE_SMBUS ||
         ObjDesc->Field.RegionObj->Region.SpaceId == ACPI_ADR_SPACE_GSBUS ||
         ObjDesc->Field.RegionObj->Region.SpaceId == ACPI_ADR_SPACE_IPMI))
    {
        /* SMBus, GSBus, IPMI serial */

        Status = AcpiExWriteSerialBus (SourceDesc, ObjDesc, ResultDesc);
        return_ACPI_STATUS (Status);
    }
    else if ((ObjDesc->Common.Type == ACPI_TYPE_LOCAL_REGION_FIELD) &&
             (ObjDesc->Field.RegionObj->Region.SpaceId == ACPI_ADR_SPACE_PLATFORM_COMM))
    {
        /*
         * According to the spec a write to the COMD field will invoke the
         * region handler. Otherwise, write to the PccInternal buffer. This
         * implementation will use the offsets specified rather than the name
         * of the field. This is considered safer because some firmware tools
         * are known to obfiscate named objects.
         */
        DataLength = (ACPI_SIZE) ACPI_ROUND_BITS_UP_TO_BYTES (
            ObjDesc->Field.BitLength);
        memcpy (ObjDesc->Field.RegionObj->Field.InternalPccBuffer +
            ObjDesc->Field.BaseByteOffset,
            SourceDesc->Buffer.Pointer, DataLength);

        if ((ObjDesc->Field.RegionObj->Region.Address == PCC_MASTER_SUBSPACE &&
           MASTER_SUBSPACE_COMMAND (ObjDesc->Field.BaseByteOffset)) ||
           GENERIC_SUBSPACE_COMMAND (ObjDesc->Field.BaseByteOffset))
        {
            /* Perform the write */

            ACPI_DEBUG_PRINT ((ACPI_DB_BFIELD,
                "PCC COMD field has been written. Invoking PCC handler now.\n"));

            Status = AcpiExAccessRegion (
                ObjDesc, 0, (UINT64 *) ObjDesc->Field.RegionObj->Field.InternalPccBuffer,
                ACPI_WRITE);
            return_ACPI_STATUS (Status);
        }
        return (AE_OK);
    }


    /* Get a pointer to the data to be written */

    switch (SourceDesc->Common.Type)
    {
    case ACPI_TYPE_INTEGER:

        Buffer = &SourceDesc->Integer.Value;
        BufferLength = sizeof (SourceDesc->Integer.Value);
        break;

    case ACPI_TYPE_BUFFER:

        Buffer = SourceDesc->Buffer.Pointer;
        BufferLength = SourceDesc->Buffer.Length;
        break;

    case ACPI_TYPE_STRING:

        Buffer = SourceDesc->String.Pointer;
        BufferLength = SourceDesc->String.Length;
        break;

    default:
        return_ACPI_STATUS (AE_AML_OPERAND_TYPE);
    }

    ACPI_DEBUG_PRINT ((ACPI_DB_BFIELD,
        "FieldWrite [FROM]: Obj %p (%s:%X), Buf %p, ByteLen %X\n",
        SourceDesc, AcpiUtGetTypeName (SourceDesc->Common.Type),
        SourceDesc->Common.Type, Buffer, BufferLength));

    ACPI_DEBUG_PRINT ((ACPI_DB_BFIELD,
        "FieldWrite [TO]:   Obj %p (%s:%X), BitLen %X, BitOff %X, ByteOff %X\n",
        ObjDesc, AcpiUtGetTypeName (ObjDesc->Common.Type),
        ObjDesc->Common.Type,
        ObjDesc->CommonField.BitLength,
        ObjDesc->CommonField.StartFieldBitOffset,
        ObjDesc->CommonField.BaseByteOffset));

    /* Lock entire transaction if requested */

    AcpiExAcquireGlobalLock (ObjDesc->CommonField.FieldFlags);

    /* Write to the field */

    Status = AcpiExInsertIntoField (ObjDesc, Buffer, BufferLength);
    AcpiExReleaseGlobalLock (ObjDesc->CommonField.FieldFlags);
    return_ACPI_STATUS (Status);
}

