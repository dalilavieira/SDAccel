#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_28__   TYPE_5__ ;
typedef  struct TYPE_27__   TYPE_4__ ;
typedef  struct TYPE_26__   TYPE_3__ ;
typedef  struct TYPE_25__   TYPE_2__ ;
typedef  struct TYPE_24__   TYPE_1__ ;

/* Type definitions */
typedef  char UINT8 ;
struct TYPE_27__ {char* Pointer; int Length; } ;
struct TYPE_26__ {int Length; char* Pointer; } ;
struct TYPE_25__ {int Type; } ;
struct TYPE_24__ {char Value; } ;
struct TYPE_28__ {TYPE_4__ Buffer; TYPE_3__ String; TYPE_2__ Common; TYPE_1__ Integer; } ;
typedef  int /*<<< orphan*/  AML_RESOURCE_END_TAG ;
typedef  int /*<<< orphan*/  ACPI_WALK_STATE ;
typedef  int /*<<< orphan*/  ACPI_STATUS ;
typedef  int ACPI_SIZE ;
typedef  TYPE_5__ ACPI_OPERAND_OBJECT ;
typedef  int ACPI_OBJECT_TYPE ;

/* Variables and functions */
 int /*<<< orphan*/  ACPI_ERROR (int /*<<< orphan*/ ) ; 
 scalar_t__ ACPI_FAILURE (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ACPI_FUNCTION_TRACE (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ACPI_IMPLICIT_CONVERSION ; 
 int /*<<< orphan*/  ACPI_IMPLICIT_CONVERT_HEX ; 
 scalar_t__ ACPI_MUL_2 (int) ; 
 int ACPI_PTR_DIFF (char*,char*) ; 
 int ACPI_RESOURCE_NAME_END_TAG ; 
#define  ACPI_TYPE_BUFFER 130 
#define  ACPI_TYPE_INTEGER 129 
#define  ACPI_TYPE_STRING 128 
 int /*<<< orphan*/  AE_AML_INTERNAL ; 
 int /*<<< orphan*/  AE_INFO ; 
 int /*<<< orphan*/  AE_NO_MEMORY ; 
 int /*<<< orphan*/  AE_OK ; 
 int /*<<< orphan*/  AcpiExConvertToBuffer (TYPE_5__*,TYPE_5__**) ; 
 int /*<<< orphan*/  AcpiExConvertToInteger (TYPE_5__*,TYPE_5__**,int /*<<< orphan*/ ) ; 
static  int /*<<< orphan*/  AcpiExConvertToObjectTypeString (TYPE_5__*,TYPE_5__**) ; 
 int /*<<< orphan*/  AcpiExConvertToString (TYPE_5__*,TYPE_5__**,int /*<<< orphan*/ ) ; 
 int AcpiGbl_IntegerByteWidth ; 
 TYPE_5__* AcpiUtCreateBufferObject (int) ; 
 TYPE_5__* AcpiUtCreateStringObject (int) ; 
 int /*<<< orphan*/  AcpiUtGetResourceEndTag (TYPE_5__*,char**) ; 
 char* AcpiUtGetTypeName (int) ; 
 int /*<<< orphan*/  AcpiUtRemoveReference (TYPE_5__*) ; 
 int /*<<< orphan*/  ExConcatTemplate ; 
 int /*<<< orphan*/  ExDoConcatenate ; 
 int /*<<< orphan*/  memcpy (char*,char*,int) ; 
 int /*<<< orphan*/  return_ACPI_STATUS (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  strcat (char*,char const*) ; 
 int /*<<< orphan*/  strcpy (char*,char*) ; 
 scalar_t__ strlen (char const*) ; 

ACPI_STATUS
AcpiExDoConcatenate (
    ACPI_OPERAND_OBJECT     *Operand0,
    ACPI_OPERAND_OBJECT     *Operand1,
    ACPI_OPERAND_OBJECT     **ActualReturnDesc,
    ACPI_WALK_STATE         *WalkState)
{
    ACPI_OPERAND_OBJECT     *LocalOperand0 = Operand0;
    ACPI_OPERAND_OBJECT     *LocalOperand1 = Operand1;
    ACPI_OPERAND_OBJECT     *TempOperand1 = NULL;
    ACPI_OPERAND_OBJECT     *ReturnDesc;
    char                    *Buffer;
    ACPI_OBJECT_TYPE        Operand0Type;
    ACPI_OBJECT_TYPE        Operand1Type;
    ACPI_STATUS             Status;


    ACPI_FUNCTION_TRACE (ExDoConcatenate);


    /* Operand 0 preprocessing */

    switch (Operand0->Common.Type)
    {
    case ACPI_TYPE_INTEGER:
    case ACPI_TYPE_STRING:
    case ACPI_TYPE_BUFFER:

        Operand0Type = Operand0->Common.Type;
        break;

    default:

        /* For all other types, get the "object type" string */

        Status = AcpiExConvertToObjectTypeString (
            Operand0, &LocalOperand0);
        if (ACPI_FAILURE (Status))
        {
            goto Cleanup;
        }

        Operand0Type = ACPI_TYPE_STRING;
        break;
    }

    /* Operand 1 preprocessing */

    switch (Operand1->Common.Type)
    {
    case ACPI_TYPE_INTEGER:
    case ACPI_TYPE_STRING:
    case ACPI_TYPE_BUFFER:

        Operand1Type = Operand1->Common.Type;
        break;

    default:

        /* For all other types, get the "object type" string */

        Status = AcpiExConvertToObjectTypeString (
            Operand1, &LocalOperand1);
        if (ACPI_FAILURE (Status))
        {
            goto Cleanup;
        }

        Operand1Type = ACPI_TYPE_STRING;
        break;
    }

    /*
     * Convert the second operand if necessary. The first operand (0)
     * determines the type of the second operand (1) (See the Data Types
     * section of the ACPI specification). Both object types are
     * guaranteed to be either Integer/String/Buffer by the operand
     * resolution mechanism.
     */
    switch (Operand0Type)
    {
    case ACPI_TYPE_INTEGER:

        Status = AcpiExConvertToInteger (LocalOperand1, &TempOperand1,
            ACPI_IMPLICIT_CONVERSION);
        break;

    case ACPI_TYPE_BUFFER:

        Status = AcpiExConvertToBuffer (LocalOperand1, &TempOperand1);
        break;

    case ACPI_TYPE_STRING:

        switch (Operand1Type)
        {
        case ACPI_TYPE_INTEGER:
        case ACPI_TYPE_STRING:
        case ACPI_TYPE_BUFFER:

            /* Other types have already been converted to string */

            Status = AcpiExConvertToString (
                LocalOperand1, &TempOperand1, ACPI_IMPLICIT_CONVERT_HEX);
            break;

        default:

            Status = AE_OK;
            break;
        }
        break;

    default:

        ACPI_ERROR ((AE_INFO, "Invalid object type: 0x%X",
            Operand0->Common.Type));
        Status = AE_AML_INTERNAL;
    }

    if (ACPI_FAILURE (Status))
    {
        goto Cleanup;
    }

    /* Take care with any newly created operand objects */

    if ((LocalOperand1 != Operand1) &&
        (LocalOperand1 != TempOperand1))
    {
        AcpiUtRemoveReference (LocalOperand1);
    }

    LocalOperand1 = TempOperand1;

    /*
     * Both operands are now known to be the same object type
     * (Both are Integer, String, or Buffer), and we can now perform
     * the concatenation.
     *
     * There are three cases to handle, as per the ACPI spec:
     *
     * 1) Two Integers concatenated to produce a new Buffer
     * 2) Two Strings concatenated to produce a new String
     * 3) Two Buffers concatenated to produce a new Buffer
     */
    switch (Operand0Type)
    {
    case ACPI_TYPE_INTEGER:

        /* Result of two Integers is a Buffer */
        /* Need enough buffer space for two integers */

        ReturnDesc = AcpiUtCreateBufferObject (
            (ACPI_SIZE) ACPI_MUL_2 (AcpiGbl_IntegerByteWidth));
        if (!ReturnDesc)
        {
            Status = AE_NO_MEMORY;
            goto Cleanup;
        }

        Buffer = (char *) ReturnDesc->Buffer.Pointer;

        /* Copy the first integer, LSB first */

        memcpy (Buffer, &Operand0->Integer.Value,
            AcpiGbl_IntegerByteWidth);

        /* Copy the second integer (LSB first) after the first */

        memcpy (Buffer + AcpiGbl_IntegerByteWidth,
            &LocalOperand1->Integer.Value, AcpiGbl_IntegerByteWidth);
        break;

    case ACPI_TYPE_STRING:

        /* Result of two Strings is a String */

        ReturnDesc = AcpiUtCreateStringObject (
            ((ACPI_SIZE) LocalOperand0->String.Length +
            LocalOperand1->String.Length));
        if (!ReturnDesc)
        {
            Status = AE_NO_MEMORY;
            goto Cleanup;
        }

        Buffer = ReturnDesc->String.Pointer;

        /* Concatenate the strings */

        strcpy (Buffer, LocalOperand0->String.Pointer);
        strcat (Buffer, LocalOperand1->String.Pointer);
        break;

    case ACPI_TYPE_BUFFER:

        /* Result of two Buffers is a Buffer */

        ReturnDesc = AcpiUtCreateBufferObject (
            ((ACPI_SIZE) Operand0->Buffer.Length +
            LocalOperand1->Buffer.Length));
        if (!ReturnDesc)
        {
            Status = AE_NO_MEMORY;
            goto Cleanup;
        }

        Buffer = (char *) ReturnDesc->Buffer.Pointer;

        /* Concatenate the buffers */

        memcpy (Buffer, Operand0->Buffer.Pointer,
            Operand0->Buffer.Length);
        memcpy (Buffer + Operand0->Buffer.Length,
            LocalOperand1->Buffer.Pointer,
            LocalOperand1->Buffer.Length);
        break;

    default:

        /* Invalid object type, should not happen here */

        ACPI_ERROR ((AE_INFO, "Invalid object type: 0x%X",
            Operand0->Common.Type));
        Status = AE_AML_INTERNAL;
        goto Cleanup;
    }

    *ActualReturnDesc = ReturnDesc;

Cleanup:
    if (LocalOperand0 != Operand0)
    {
        AcpiUtRemoveReference (LocalOperand0);
    }

    if (LocalOperand1 != Operand1)
    {
        AcpiUtRemoveReference (LocalOperand1);
    }

    return_ACPI_STATUS (Status);
}

__attribute__((used)) static ACPI_STATUS
AcpiExConvertToObjectTypeString (
    ACPI_OPERAND_OBJECT     *ObjDesc,
    ACPI_OPERAND_OBJECT     **ResultDesc)
{
    ACPI_OPERAND_OBJECT     *ReturnDesc;
    const char              *TypeString;


    TypeString = AcpiUtGetTypeName (ObjDesc->Common.Type);

    ReturnDesc = AcpiUtCreateStringObject (
        ((ACPI_SIZE) strlen (TypeString) + 9)); /* 9 For "[ Object]" */
    if (!ReturnDesc)
    {
        return (AE_NO_MEMORY);
    }

    strcpy (ReturnDesc->String.Pointer, "[");
    strcat (ReturnDesc->String.Pointer, TypeString);
    strcat (ReturnDesc->String.Pointer, " Object]");

    *ResultDesc = ReturnDesc;
    return (AE_OK);
}

ACPI_STATUS
AcpiExConcatTemplate (
    ACPI_OPERAND_OBJECT     *Operand0,
    ACPI_OPERAND_OBJECT     *Operand1,
    ACPI_OPERAND_OBJECT     **ActualReturnDesc,
    ACPI_WALK_STATE         *WalkState)
{
    ACPI_STATUS             Status;
    ACPI_OPERAND_OBJECT     *ReturnDesc;
    UINT8                   *NewBuf;
    UINT8                   *EndTag;
    ACPI_SIZE               Length0;
    ACPI_SIZE               Length1;
    ACPI_SIZE               NewLength;


    ACPI_FUNCTION_TRACE (ExConcatTemplate);


    /*
     * Find the EndTag descriptor in each resource template.
     * Note1: returned pointers point TO the EndTag, not past it.
     * Note2: zero-length buffers are allowed; treated like one EndTag
     */

    /* Get the length of the first resource template */

    Status = AcpiUtGetResourceEndTag (Operand0, &EndTag);
    if (ACPI_FAILURE (Status))
    {
        return_ACPI_STATUS (Status);
    }

    Length0 = ACPI_PTR_DIFF (EndTag, Operand0->Buffer.Pointer);

    /* Get the length of the second resource template */

    Status = AcpiUtGetResourceEndTag (Operand1, &EndTag);
    if (ACPI_FAILURE (Status))
    {
        return_ACPI_STATUS (Status);
    }

    Length1 = ACPI_PTR_DIFF (EndTag, Operand1->Buffer.Pointer);

    /* Combine both lengths, minimum size will be 2 for EndTag */

    NewLength = Length0 + Length1 + sizeof (AML_RESOURCE_END_TAG);

    /* Create a new buffer object for the result (with one EndTag) */

    ReturnDesc = AcpiUtCreateBufferObject (NewLength);
    if (!ReturnDesc)
    {
        return_ACPI_STATUS (AE_NO_MEMORY);
    }

    /*
     * Copy the templates to the new buffer, 0 first, then 1 follows. One
     * EndTag descriptor is copied from Operand1.
     */
    NewBuf = ReturnDesc->Buffer.Pointer;
    memcpy (NewBuf, Operand0->Buffer.Pointer, Length0);
    memcpy (NewBuf + Length0, Operand1->Buffer.Pointer, Length1);

    /* Insert EndTag and set the checksum to zero, means "ignore checksum" */

    NewBuf[NewLength - 1] = 0;
    NewBuf[NewLength - 2] = ACPI_RESOURCE_NAME_END_TAG | 1;

    /* Return the completed resource template */

    *ActualReturnDesc = ReturnDesc;
    return_ACPI_STATUS (AE_OK);
}

