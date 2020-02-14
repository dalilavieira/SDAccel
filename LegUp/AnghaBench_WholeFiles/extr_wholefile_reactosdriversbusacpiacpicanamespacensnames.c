#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_25__   TYPE_5__ ;
typedef  struct TYPE_24__   TYPE_4__ ;
typedef  struct TYPE_23__   TYPE_2__ ;
typedef  struct TYPE_22__   TYPE_1__ ;

/* Type definitions */
typedef  size_t UINT32 ;
struct TYPE_25__ {char* Pointer; } ;
struct TYPE_22__ {TYPE_2__* Node; } ;
struct TYPE_24__ {TYPE_1__ Scope; } ;
struct TYPE_23__ {struct TYPE_23__* Parent; int /*<<< orphan*/  Name; } ;
typedef  scalar_t__ BOOLEAN ;
typedef  int /*<<< orphan*/  ACPI_STATUS ;
typedef  size_t ACPI_SIZE ;
typedef  TYPE_2__ ACPI_NAMESPACE_NODE ;
typedef  TYPE_2__* ACPI_HANDLE ;
typedef  TYPE_4__ ACPI_GENERIC_STATE ;
typedef  TYPE_5__ ACPI_BUFFER ;

/* Variables and functions */
 char* ACPI_ALLOCATE_ZEROED (size_t) ; 
 int /*<<< orphan*/  ACPI_COPY_NAMESEG (char*,char const*) ; 
 int /*<<< orphan*/  ACPI_DB_EXEC ; 
 int /*<<< orphan*/  ACPI_DB_NAMES ; 
 int /*<<< orphan*/  ACPI_DEBUG_PRINT (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ACPI_DEBUG_PRINT_RAW (int /*<<< orphan*/ ) ; 
 scalar_t__ ACPI_DESC_TYPE_NAMED ; 
 int /*<<< orphan*/  ACPI_ERROR (int /*<<< orphan*/ ) ; 
 scalar_t__ ACPI_FAILURE (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ACPI_FREE (char*) ; 
 int /*<<< orphan*/  ACPI_FUNCTION_TRACE_PTR (int /*<<< orphan*/ ,TYPE_2__*) ; 
 scalar_t__ ACPI_GET_DESCRIPTOR_TYPE (TYPE_2__*) ; 
 int /*<<< orphan*/  ACPI_GET_FUNCTION_NAME ; 
 int /*<<< orphan*/  ACPI_MOVE_32_TO_32 (char*,int /*<<< orphan*/ *) ; 
 size_t ACPI_NAMESEG_SIZE ; 
 size_t ACPI_PATH_SEGMENT_LENGTH ; 
 int /*<<< orphan*/  ACPI_UINT32_MAX ; 
 int /*<<< orphan*/  AE_BAD_PARAMETER ; 
 int /*<<< orphan*/  AE_INFO ; 
 int /*<<< orphan*/  AE_OK ; 
 char AML_DUAL_NAME_PREFIX ; 
 char AML_ROOT_PREFIX ; 
 TYPE_2__* AcpiGbl_RootNode ; 
 size_t AcpiNsBuildNormalizedPath (TYPE_2__*,char*,size_t,scalar_t__) ; 
 int /*<<< orphan*/  AcpiNsExternalizeName (int /*<<< orphan*/ ,char const*,int /*<<< orphan*/ *,char**) ; 
 char* AcpiNsGetNormalizedPathname (TYPE_2__*,scalar_t__) ; 
static  void AcpiNsNormalizePathname (char*) ; 
 TYPE_2__* AcpiNsValidateHandle (TYPE_2__*) ; 
 char* AcpiUtGetNodeName (TYPE_2__*) ; 
 int /*<<< orphan*/  AcpiUtInitializeBuffer (TYPE_5__*,size_t) ; 
 scalar_t__ FALSE ; 
 int /*<<< orphan*/  NsBuildNormalizedPath ; 
 int /*<<< orphan*/  NsGetExternalPathname ; 
 int /*<<< orphan*/  NsGetNormalizedPathname ; 
 int /*<<< orphan*/  NsHandleToName ; 
 int /*<<< orphan*/  NsHandleToPathname ; 
 scalar_t__ TRUE ; 
 int /*<<< orphan*/  return_ACPI_STATUS (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  return_PTR (char*) ; 
 int /*<<< orphan*/  return_UINT32 (size_t) ; 
 int /*<<< orphan*/  strcat (char*,char*) ; 
 int /*<<< orphan*/  strcpy (char*,char*) ; 
 size_t strlen (char*) ; 

char *
AcpiNsGetExternalPathname (
    ACPI_NAMESPACE_NODE     *Node)
{
    char                    *NameBuffer;


    ACPI_FUNCTION_TRACE_PTR (NsGetExternalPathname, Node);


    NameBuffer = AcpiNsGetNormalizedPathname (Node, FALSE);
    return_PTR (NameBuffer);
}

ACPI_SIZE
AcpiNsGetPathnameLength (
    ACPI_NAMESPACE_NODE     *Node)
{
    ACPI_SIZE               Size;


    /* Validate the Node */

    if (ACPI_GET_DESCRIPTOR_TYPE (Node) != ACPI_DESC_TYPE_NAMED)
    {
        ACPI_ERROR ((AE_INFO,
            "Invalid/cached reference target node: %p, descriptor type %d",
            Node, ACPI_GET_DESCRIPTOR_TYPE (Node)));
        return (0);
    }

    Size = AcpiNsBuildNormalizedPath (Node, NULL, 0, FALSE);
    return (Size);
}

ACPI_STATUS
AcpiNsHandleToName (
    ACPI_HANDLE             TargetHandle,
    ACPI_BUFFER             *Buffer)
{
    ACPI_STATUS             Status;
    ACPI_NAMESPACE_NODE     *Node;
    const char              *NodeName;


    ACPI_FUNCTION_TRACE_PTR (NsHandleToName, TargetHandle);


    Node = AcpiNsValidateHandle (TargetHandle);
    if (!Node)
    {
        return_ACPI_STATUS (AE_BAD_PARAMETER);
    }

    /* Validate/Allocate/Clear caller buffer */

    Status = AcpiUtInitializeBuffer (Buffer, ACPI_PATH_SEGMENT_LENGTH);
    if (ACPI_FAILURE (Status))
    {
        return_ACPI_STATUS (Status);
    }

    /* Just copy the ACPI name from the Node and zero terminate it */

    NodeName = AcpiUtGetNodeName (Node);
    ACPI_COPY_NAMESEG (Buffer->Pointer, NodeName);
    ((char *) Buffer->Pointer) [ACPI_NAMESEG_SIZE] = 0;

    ACPI_DEBUG_PRINT ((ACPI_DB_EXEC, "%4.4s\n", (char *) Buffer->Pointer));
    return_ACPI_STATUS (AE_OK);
}

ACPI_STATUS
AcpiNsHandleToPathname (
    ACPI_HANDLE             TargetHandle,
    ACPI_BUFFER             *Buffer,
    BOOLEAN                 NoTrailing)
{
    ACPI_STATUS             Status;
    ACPI_NAMESPACE_NODE     *Node;
    ACPI_SIZE               RequiredSize;


    ACPI_FUNCTION_TRACE_PTR (NsHandleToPathname, TargetHandle);


    Node = AcpiNsValidateHandle (TargetHandle);
    if (!Node)
    {
        return_ACPI_STATUS (AE_BAD_PARAMETER);
    }

    /* Determine size required for the caller buffer */

    RequiredSize = AcpiNsBuildNormalizedPath (Node, NULL, 0, NoTrailing);
    if (!RequiredSize)
    {
        return_ACPI_STATUS (AE_BAD_PARAMETER);
    }

    /* Validate/Allocate/Clear caller buffer */

    Status = AcpiUtInitializeBuffer (Buffer, RequiredSize);
    if (ACPI_FAILURE (Status))
    {
        return_ACPI_STATUS (Status);
    }

    /* Build the path in the caller buffer */

    (void) AcpiNsBuildNormalizedPath (Node, Buffer->Pointer,
        RequiredSize, NoTrailing);

    ACPI_DEBUG_PRINT ((ACPI_DB_EXEC, "%s [%X]\n",
        (char *) Buffer->Pointer, (UINT32) RequiredSize));
    return_ACPI_STATUS (AE_OK);
}

UINT32
AcpiNsBuildNormalizedPath (
    ACPI_NAMESPACE_NODE     *Node,
    char                    *FullPath,
    UINT32                  PathSize,
    BOOLEAN                 NoTrailing)
{
    UINT32                  Length = 0, i;
    char                    Name[ACPI_NAMESEG_SIZE];
    BOOLEAN                 DoNoTrailing;
    char                    c, *Left, *Right;
    ACPI_NAMESPACE_NODE     *NextNode;


    ACPI_FUNCTION_TRACE_PTR (NsBuildNormalizedPath, Node);


#define ACPI_PATH_PUT8(Path, Size, Byte, Length)    \
    do {                                            \
        if ((Length) < (Size))                      \
        {                                           \
            (Path)[(Length)] = (Byte);              \
        }                                           \
        (Length)++;                                 \
    } while (0)

    /*
     * Make sure the PathSize is correct, so that we don't need to
     * validate both FullPath and PathSize.
     */
    if (!FullPath)
    {
        PathSize = 0;
    }

    if (!Node)
    {
        goto BuildTrailingNull;
    }

    NextNode = Node;
    while (NextNode && NextNode != AcpiGbl_RootNode)
    {
        if (NextNode != Node)
        {
            ACPI_PATH_PUT8(FullPath, PathSize, AML_DUAL_NAME_PREFIX, Length);
        }

        ACPI_MOVE_32_TO_32 (Name, &NextNode->Name);
        DoNoTrailing = NoTrailing;
        for (i = 0; i < 4; i++)
        {
            c = Name[4-i-1];
            if (DoNoTrailing && c != '_')
            {
                DoNoTrailing = FALSE;
            }
            if (!DoNoTrailing)
            {
                ACPI_PATH_PUT8(FullPath, PathSize, c, Length);
            }
        }

        NextNode = NextNode->Parent;
    }

    ACPI_PATH_PUT8(FullPath, PathSize, AML_ROOT_PREFIX, Length);

    /* Reverse the path string */

    if (Length <= PathSize)
    {
        Left = FullPath;
        Right = FullPath+Length - 1;

        while (Left < Right)
        {
            c = *Left;
            *Left++ = *Right;
            *Right-- = c;
        }
    }

    /* Append the trailing null */

BuildTrailingNull:
    ACPI_PATH_PUT8 (FullPath, PathSize, '\0', Length);

#undef ACPI_PATH_PUT8

    return_UINT32 (Length);
}

char *
AcpiNsGetNormalizedPathname (
    ACPI_NAMESPACE_NODE     *Node,
    BOOLEAN                 NoTrailing)
{
    char                    *NameBuffer;
    ACPI_SIZE               Size;


    ACPI_FUNCTION_TRACE_PTR (NsGetNormalizedPathname, Node);


    /* Calculate required buffer size based on depth below root */

    Size = AcpiNsBuildNormalizedPath (Node, NULL, 0, NoTrailing);
    if (!Size)
    {
        return_PTR (NULL);
    }

    /* Allocate a buffer to be returned to caller */

    NameBuffer = ACPI_ALLOCATE_ZEROED (Size);
    if (!NameBuffer)
    {
        ACPI_ERROR ((AE_INFO,
            "Could not allocate %u bytes", (UINT32) Size));
        return_PTR (NULL);
    }

    /* Build the path in the allocated buffer */

    (void) AcpiNsBuildNormalizedPath (Node, NameBuffer, Size, NoTrailing);

    ACPI_DEBUG_PRINT_RAW ((ACPI_DB_NAMES, "%s: Path \"%s\"\n",
        ACPI_GET_FUNCTION_NAME, NameBuffer));

    return_PTR (NameBuffer);
}

char *
AcpiNsBuildPrefixedPathname (
    ACPI_GENERIC_STATE      *PrefixScope,
    const char              *InternalPath)
{
    ACPI_STATUS             Status;
    char                    *FullPath = NULL;
    char                    *ExternalPath = NULL;
    char                    *PrefixPath = NULL;
    UINT32                  PrefixPathLength = 0;


    /* If there is a prefix, get the pathname to it */

    if (PrefixScope && PrefixScope->Scope.Node)
    {
        PrefixPath = AcpiNsGetNormalizedPathname (PrefixScope->Scope.Node, TRUE);
        if (PrefixPath)
        {
            PrefixPathLength = strlen (PrefixPath);
        }
    }

    Status = AcpiNsExternalizeName (ACPI_UINT32_MAX, InternalPath,
        NULL, &ExternalPath);
    if (ACPI_FAILURE (Status))
    {
        goto Cleanup;
    }

    /* Merge the prefix path and the path. 2 is for one dot and trailing null */

    FullPath = ACPI_ALLOCATE_ZEROED (
        PrefixPathLength + strlen (ExternalPath) + 2);
    if (!FullPath)
    {
        goto Cleanup;
    }

    /* Don't merge if the External path is already fully qualified */

    if (PrefixPath &&
        (*ExternalPath != '\\') &&
        (*ExternalPath != '^'))
    {
        strcat (FullPath, PrefixPath);
        if (PrefixPath[1])
        {
            strcat (FullPath, ".");
        }
    }

    AcpiNsNormalizePathname (ExternalPath);
    strcat (FullPath, ExternalPath);

Cleanup:
    if (PrefixPath)
    {
        ACPI_FREE (PrefixPath);
    }
    if (ExternalPath)
    {
        ACPI_FREE (ExternalPath);
    }

    return (FullPath);
}

__attribute__((used)) static void
AcpiNsNormalizePathname (
    char                    *OriginalPath)
{
    char                    *InputPath = OriginalPath;
    char                    *NewPathBuffer;
    char                    *NewPath;
    UINT32                  i;


    /* Allocate a temp buffer in which to construct the new path */

    NewPathBuffer = ACPI_ALLOCATE_ZEROED (strlen (InputPath) + 1);
    NewPath = NewPathBuffer;
    if (!NewPathBuffer)
    {
        return;
    }

    /* Special characters may appear at the beginning of the path */

    if (*InputPath == '\\')
    {
        *NewPath = *InputPath;
        NewPath++;
        InputPath++;
    }

    while (*InputPath == '^')
    {
        *NewPath = *InputPath;
        NewPath++;
        InputPath++;
    }

    /* Remainder of the path */

    while (*InputPath)
    {
        /* Do one nameseg at a time */

        for (i = 0; (i < ACPI_NAMESEG_SIZE) && *InputPath; i++)
        {
            if ((i == 0) || (*InputPath != '_')) /* First char is allowed to be underscore */
            {
                *NewPath = *InputPath;
                NewPath++;
            }

            InputPath++;
        }

        /* Dot means that there are more namesegs to come */

        if (*InputPath == '.')
        {
            *NewPath = *InputPath;
            NewPath++;
            InputPath++;
        }
    }

    *NewPath = 0;
    strcpy (OriginalPath, NewPathBuffer);
    ACPI_FREE (NewPathBuffer);
}

