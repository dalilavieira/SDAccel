#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
struct TYPE_4__ {scalar_t__ Length; void* Pointer; } ;
typedef  int /*<<< orphan*/  ACPI_STATUS ;
typedef  int ACPI_SIZE ;
typedef  int /*<<< orphan*/  ACPI_PARSE_OBJ_NAMED ;
typedef  int /*<<< orphan*/  ACPI_PARSE_OBJ_COMMON ;
typedef  int /*<<< orphan*/  ACPI_OPERAND_OBJECT ;
typedef  int /*<<< orphan*/  ACPI_NAMESPACE_NODE ;
typedef  int /*<<< orphan*/  ACPI_GENERIC_STATE ;
typedef  TYPE_1__ ACPI_BUFFER ;

/* Variables and functions */
 void* ACPI_ALLOCATE (int) ; 
#define  ACPI_ALLOCATE_BUFFER 130 
#define  ACPI_ALLOCATE_LOCAL_BUFFER 129 
 scalar_t__ ACPI_FAILURE (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ACPI_FUNCTION_ENTRY () ; 
 int /*<<< orphan*/  ACPI_MAX_EXTPARSE_CACHE_DEPTH ; 
 int /*<<< orphan*/  ACPI_MAX_NAMESPACE_CACHE_DEPTH ; 
 int /*<<< orphan*/  ACPI_MAX_OBJECT_CACHE_DEPTH ; 
 int /*<<< orphan*/  ACPI_MAX_PARSE_CACHE_DEPTH ; 
 int /*<<< orphan*/  ACPI_MAX_STATE_CACHE_DEPTH ; 
#define  ACPI_NO_BUFFER 128 
 int /*<<< orphan*/  AE_BAD_PARAMETER ; 
 int /*<<< orphan*/  AE_BUFFER_OVERFLOW ; 
 int /*<<< orphan*/  AE_NO_MEMORY ; 
 int /*<<< orphan*/  AE_OK ; 
 int /*<<< orphan*/ * AcpiGbl_NamespaceCache ; 
 int /*<<< orphan*/ * AcpiGbl_OperandCache ; 
 int /*<<< orphan*/ * AcpiGbl_PsNodeCache ; 
 int /*<<< orphan*/ * AcpiGbl_PsNodeExtCache ; 
 int /*<<< orphan*/ * AcpiGbl_StateCache ; 
 void* AcpiOsAllocate (int) ; 
 int /*<<< orphan*/  AcpiOsCreateCache (char*,int,int /*<<< orphan*/ ,int /*<<< orphan*/ **) ; 
 int /*<<< orphan*/  AcpiOsDeleteCache (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  memset (void*,int /*<<< orphan*/ ,int) ; 

void *
AcpiOsAllocateZeroed (
    ACPI_SIZE               Size)
{
    void                    *Allocation;


    ACPI_FUNCTION_ENTRY ();


    Allocation = AcpiOsAllocate (Size);
    if (Allocation)
    {
        /* Clear the memory block */

        memset (Allocation, 0, Size);
    }

    return (Allocation);
}

ACPI_STATUS
AcpiUtCreateCaches (
    void)
{
    ACPI_STATUS             Status;


    /* Object Caches, for frequently used objects */

    Status = AcpiOsCreateCache ("Acpi-Namespace", sizeof (ACPI_NAMESPACE_NODE),
        ACPI_MAX_NAMESPACE_CACHE_DEPTH, &AcpiGbl_NamespaceCache);
    if (ACPI_FAILURE (Status))
    {
        return (Status);
    }

    Status = AcpiOsCreateCache ("Acpi-State", sizeof (ACPI_GENERIC_STATE),
        ACPI_MAX_STATE_CACHE_DEPTH, &AcpiGbl_StateCache);
    if (ACPI_FAILURE (Status))
    {
        return (Status);
    }

    Status = AcpiOsCreateCache ("Acpi-Parse", sizeof (ACPI_PARSE_OBJ_COMMON),
        ACPI_MAX_PARSE_CACHE_DEPTH, &AcpiGbl_PsNodeCache);
    if (ACPI_FAILURE (Status))
    {
        return (Status);
    }

    Status = AcpiOsCreateCache ("Acpi-ParseExt", sizeof (ACPI_PARSE_OBJ_NAMED),
        ACPI_MAX_EXTPARSE_CACHE_DEPTH, &AcpiGbl_PsNodeExtCache);
    if (ACPI_FAILURE (Status))
    {
        return (Status);
    }

    Status = AcpiOsCreateCache ("Acpi-Operand", sizeof (ACPI_OPERAND_OBJECT),
        ACPI_MAX_OBJECT_CACHE_DEPTH, &AcpiGbl_OperandCache);
    if (ACPI_FAILURE (Status))
    {
        return (Status);
    }

#ifdef ACPI_ASL_COMPILER
    /*
     * For use with the ASL-/ASL+ option. This cache keeps track of regular
     * 0xA9 0x01 comments.
     */
    Status = AcpiOsCreateCache ("Acpi-Comment", sizeof (ACPI_COMMENT_NODE),
        ACPI_MAX_COMMENT_CACHE_DEPTH, &AcpiGbl_RegCommentCache);
    if (ACPI_FAILURE (Status))
    {
        return (Status);
    }

    /*
     * This cache keeps track of the starting addresses of where the comments
     * lie. This helps prevent duplication of comments.
     */
    Status = AcpiOsCreateCache ("Acpi-Comment-Addr", sizeof (ACPI_COMMENT_ADDR_NODE),
        ACPI_MAX_COMMENT_CACHE_DEPTH, &AcpiGbl_CommentAddrCache);
    if (ACPI_FAILURE (Status))
    {
        return (Status);
    }

    /*
     * This cache will be used for nodes that represent files.
     */
    Status = AcpiOsCreateCache ("Acpi-File", sizeof (ACPI_FILE_NODE),
        ACPI_MAX_COMMENT_CACHE_DEPTH, &AcpiGbl_FileCache);
    if (ACPI_FAILURE (Status))
    {
        return (Status);
    }
#endif


#ifdef ACPI_DBG_TRACK_ALLOCATIONS

    /* Memory allocation lists */

    Status = AcpiUtCreateList ("Acpi-Global", 0,
        &AcpiGbl_GlobalList);
    if (ACPI_FAILURE (Status))
    {
        return (Status);
    }

    Status = AcpiUtCreateList ("Acpi-Namespace", sizeof (ACPI_NAMESPACE_NODE),
        &AcpiGbl_NsNodeList);
    if (ACPI_FAILURE (Status))
    {
        return (Status);
    }
#endif

    return (AE_OK);
}

ACPI_STATUS
AcpiUtDeleteCaches (
    void)
{
#ifdef ACPI_DBG_TRACK_ALLOCATIONS
    char                    Buffer[7];


    if (AcpiGbl_DisplayFinalMemStats)
    {
        strcpy (Buffer, "MEMORY");
        (void) AcpiDbDisplayStatistics (Buffer);
    }
#endif

    (void) AcpiOsDeleteCache (AcpiGbl_NamespaceCache);
    AcpiGbl_NamespaceCache = NULL;

    (void) AcpiOsDeleteCache (AcpiGbl_StateCache);
    AcpiGbl_StateCache = NULL;

    (void) AcpiOsDeleteCache (AcpiGbl_OperandCache);
    AcpiGbl_OperandCache = NULL;

    (void) AcpiOsDeleteCache (AcpiGbl_PsNodeCache);
    AcpiGbl_PsNodeCache = NULL;

    (void) AcpiOsDeleteCache (AcpiGbl_PsNodeExtCache);
    AcpiGbl_PsNodeExtCache = NULL;

#ifdef ACPI_ASL_COMPILER
    (void) AcpiOsDeleteCache (AcpiGbl_RegCommentCache);
    AcpiGbl_RegCommentCache = NULL;

    (void) AcpiOsDeleteCache (AcpiGbl_CommentAddrCache);
    AcpiGbl_CommentAddrCache = NULL;

    (void) AcpiOsDeleteCache (AcpiGbl_FileCache);
    AcpiGbl_FileCache = NULL;
#endif

#ifdef ACPI_DBG_TRACK_ALLOCATIONS

    /* Debug only - display leftover memory allocation, if any */

    AcpiUtDumpAllocations (ACPI_UINT32_MAX, NULL);

    /* Free memory lists */

    AcpiOsFree (AcpiGbl_GlobalList);
    AcpiGbl_GlobalList = NULL;

    AcpiOsFree (AcpiGbl_NsNodeList);
    AcpiGbl_NsNodeList = NULL;
#endif

    return (AE_OK);
}

ACPI_STATUS
AcpiUtValidateBuffer (
    ACPI_BUFFER             *Buffer)
{

    /* Obviously, the structure pointer must be valid */

    if (!Buffer)
    {
        return (AE_BAD_PARAMETER);
    }

    /* Special semantics for the length */

    if ((Buffer->Length == ACPI_NO_BUFFER)              ||
        (Buffer->Length == ACPI_ALLOCATE_BUFFER)        ||
        (Buffer->Length == ACPI_ALLOCATE_LOCAL_BUFFER))
    {
        return (AE_OK);
    }

    /* Length is valid, the buffer pointer must be also */

    if (!Buffer->Pointer)
    {
        return (AE_BAD_PARAMETER);
    }

    return (AE_OK);
}

ACPI_STATUS
AcpiUtInitializeBuffer (
    ACPI_BUFFER             *Buffer,
    ACPI_SIZE               RequiredLength)
{
    ACPI_SIZE               InputBufferLength;


    /* Parameter validation */

    if (!Buffer || !RequiredLength)
    {
        return (AE_BAD_PARAMETER);
    }

    /*
     * Buffer->Length is used as both an input and output parameter. Get the
     * input actual length and set the output required buffer length.
     */
    InputBufferLength = Buffer->Length;
    Buffer->Length = RequiredLength;

    /*
     * The input buffer length contains the actual buffer length, or the type
     * of buffer to be allocated by this routine.
     */
    switch (InputBufferLength)
    {
    case ACPI_NO_BUFFER:

        /* Return the exception (and the required buffer length) */

        return (AE_BUFFER_OVERFLOW);

    case ACPI_ALLOCATE_BUFFER:
        /*
         * Allocate a new buffer. We directectly call AcpiOsAllocate here to
         * purposefully bypass the (optionally enabled) internal allocation
         * tracking mechanism since we only want to track internal
         * allocations. Note: The caller should use AcpiOsFree to free this
         * buffer created via ACPI_ALLOCATE_BUFFER.
         */
        Buffer->Pointer = AcpiOsAllocate (RequiredLength);
        break;

    case ACPI_ALLOCATE_LOCAL_BUFFER:

        /* Allocate a new buffer with local interface to allow tracking */

        Buffer->Pointer = ACPI_ALLOCATE (RequiredLength);
        break;

    default:

        /* Existing buffer: Validate the size of the buffer */

        if (InputBufferLength < RequiredLength)
        {
            return (AE_BUFFER_OVERFLOW);
        }
        break;
    }

    /* Validate allocation from above or input buffer pointer */

    if (!Buffer->Pointer)
    {
        return (AE_NO_MEMORY);
    }

    /* Have a valid buffer, clear it */

    memset (Buffer->Pointer, 0, RequiredLength);
    return (AE_OK);
}

