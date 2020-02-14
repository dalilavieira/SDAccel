#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_18__   TYPE_8__ ;
typedef  struct TYPE_17__   TYPE_7__ ;
typedef  struct TYPE_16__   TYPE_4__ ;
typedef  struct TYPE_15__   TYPE_3__ ;
typedef  struct TYPE_14__   TYPE_2__ ;
typedef  struct TYPE_13__   TYPE_1__ ;

/* Type definitions */
typedef  size_t WORD ;
typedef  int /*<<< orphan*/  VOID ;
typedef  size_t UINT ;
struct TYPE_18__ {scalar_t__ CurrentPsp; int /*<<< orphan*/  LastErrorCode; } ;
struct TYPE_17__ {int /*<<< orphan*/  ActiveCon; } ;
struct TYPE_13__ {int* Buffer; size_t Length; } ;
struct TYPE_16__ {int DeviceAttributes; int /*<<< orphan*/  (* CloseRoutine ) (TYPE_4__*) ;int /*<<< orphan*/  (* OpenRoutine ) (TYPE_4__*) ;TYPE_1__ Name; } ;
struct TYPE_15__ {int DeviceInfo; int* FileName; int /*<<< orphan*/  Win32Handle; int /*<<< orphan*/  DevicePointer; int /*<<< orphan*/  RefCount; } ;
struct TYPE_14__ {size_t HandleTableSize; int* HandleTable; void* HandleTablePtr; } ;
typedef  TYPE_2__* PDOS_PSP ;
typedef  TYPE_3__* PDOS_FILE_DESCRIPTOR ;
typedef  TYPE_4__* PDOS_DEVICE_NODE ;
typedef  int* LPBYTE ;
typedef  int /*<<< orphan*/  HANDLE ;
typedef  int BYTE ;
typedef  int /*<<< orphan*/  BOOLEAN ;

/* Variables and functions */
 int /*<<< orphan*/  ASSERT (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  CloseHandle (int /*<<< orphan*/ ) ; 
 size_t DEFAULT_JFT_SIZE ; 
 int /*<<< orphan*/  DPRINT (char*,size_t,...) ; 
 int /*<<< orphan*/  DPRINT1 (char*,size_t) ; 
 size_t DosAllocateMemory (size_t,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  DosCloseHandle (size_t) ; 
 int DosFindDeviceDescriptor (int /*<<< orphan*/ ) ; 
 int DosFindFreeDescriptor () ; 
 int DosFindWin32Descriptor (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  DosFreeMemory (size_t) ; 
 TYPE_4__* DosGetDriverNode (int /*<<< orphan*/ ) ; 
 TYPE_3__* DosGetFileDescriptor (int) ; 
 int /*<<< orphan*/  DosResizeMemory (size_t,size_t,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  ERROR_INVALID_HANDLE ; 
 int /*<<< orphan*/  FALSE ; 
 int* FAR_POINTER (void*) ; 
 int FILE_INFO_DEVICE ; 
 int /*<<< orphan*/  GetStdHandle (int /*<<< orphan*/ ) ; 
 size_t HIWORD (void*) ; 
 size_t INVALID_DOS_HANDLE ; 
 scalar_t__ IsConsoleHandle (int /*<<< orphan*/ ) ; 
 int LOWORD (void*) ; 
 void* MAKELONG (int,size_t) ; 
 int /*<<< orphan*/  RtlCopyMemory (int*,int*,size_t) ; 
 int /*<<< orphan*/  RtlFillMemory (int*,int,char) ; 
 int /*<<< orphan*/  RtlZeroMemory (TYPE_3__*,int) ; 
 TYPE_2__* SEGMENT_TO_PSP (scalar_t__) ; 
 int* SEG_OFF_TO_PTR (size_t,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  STD_ERROR_HANDLE ; 
 int /*<<< orphan*/  STD_INPUT_HANDLE ; 
 int /*<<< orphan*/  STD_OUTPUT_HANDLE ; 
 scalar_t__ SYSTEM_PSP ; 
 TYPE_8__* Sda ; 
 TYPE_7__* SysVars ; 
 int /*<<< orphan*/  TRUE ; 
 int /*<<< orphan*/  stub1 (TYPE_4__*) ; 
 int /*<<< orphan*/  stub2 (TYPE_4__*) ; 

VOID DosCopyHandleTable(LPBYTE DestinationTable)
{
    UINT i;
    PDOS_PSP PspBlock;
    LPBYTE SourceTable;
    PDOS_FILE_DESCRIPTOR Descriptor;

    /* Clear the table first */
    for (i = 0; i < DEFAULT_JFT_SIZE; i++) DestinationTable[i] = 0xFF;

    /* Check if this is the initial process */
    if (Sda->CurrentPsp == SYSTEM_PSP)
    {
        BYTE DescriptorId;
        HANDLE StandardHandles[3];

        /* Get the native standard handles */
        StandardHandles[0] = GetStdHandle(STD_INPUT_HANDLE);
        StandardHandles[1] = GetStdHandle(STD_OUTPUT_HANDLE);
        StandardHandles[2] = GetStdHandle(STD_ERROR_HANDLE);

        for (i = 0; i < 3; i++)
        {
            /* Find the corresponding SFT entry */
            if (IsConsoleHandle(StandardHandles[i]))
            {
                DescriptorId = DosFindDeviceDescriptor(SysVars->ActiveCon);
            }
            else
            {
                DescriptorId = DosFindWin32Descriptor(StandardHandles[i]);
            }

            if (DescriptorId != 0xFF)
            {
                Descriptor = DosGetFileDescriptor(DescriptorId);
            }
            else
            {
                /* Create a new SFT entry for it */
                DescriptorId = DosFindFreeDescriptor();
                if (DescriptorId == 0xFF)
                {
                    DPRINT1("Cannot create standard handle %d, the SFT is full!\n", i);
                    continue;
                }

                Descriptor = DosGetFileDescriptor(DescriptorId);
                ASSERT(Descriptor != NULL);
                RtlZeroMemory(Descriptor, sizeof(*Descriptor));

                if (IsConsoleHandle(StandardHandles[i]))
                {
                    PDOS_DEVICE_NODE Node = DosGetDriverNode(SysVars->ActiveCon);

                    Descriptor->DeviceInfo = Node->DeviceAttributes | FILE_INFO_DEVICE;
                    Descriptor->DevicePointer = SysVars->ActiveCon;
                    RtlFillMemory(Descriptor->FileName, sizeof(Descriptor->FileName), ' ');
                    RtlCopyMemory(Descriptor->FileName, Node->Name.Buffer, Node->Name.Length);

                    /* Call the open routine */
                    if (Node->OpenRoutine) Node->OpenRoutine(Node);
                }
                else
                {
                    Descriptor->Win32Handle = StandardHandles[i];
                }
            }

            Descriptor->RefCount++;
            DestinationTable[i] = DescriptorId;
        }
    }
    else
    {
        /* Get the parent PSP block and handle table */
        PspBlock = SEGMENT_TO_PSP(Sda->CurrentPsp);
        SourceTable = (LPBYTE)FAR_POINTER(PspBlock->HandleTablePtr);

        /* Copy the first 20 handles into the new table */
        for (i = 0; i < DEFAULT_JFT_SIZE; i++)
        {
            Descriptor = DosGetFileDescriptor(SourceTable[i]);
            DestinationTable[i] = SourceTable[i];

            /* Increase the reference count */
            Descriptor->RefCount++;
        }
    }
}

BOOLEAN DosResizeHandleTable(WORD NewSize)
{
    PDOS_PSP PspBlock;
    LPBYTE HandleTable;
    WORD Segment;

    /* Get the PSP block */
    PspBlock = SEGMENT_TO_PSP(Sda->CurrentPsp);

    if (NewSize == PspBlock->HandleTableSize)
    {
        /* No change */
        return TRUE;
    }

    if (PspBlock->HandleTableSize > DEFAULT_JFT_SIZE)
    {
        /* Get the segment of the current table */
        Segment = (LOWORD(PspBlock->HandleTablePtr) >> 4) + HIWORD(PspBlock->HandleTablePtr);

        if (NewSize <= DEFAULT_JFT_SIZE)
        {
            /* Get the current handle table */
            HandleTable = FAR_POINTER(PspBlock->HandleTablePtr);

            /* Copy it to the PSP */
            RtlCopyMemory(PspBlock->HandleTable, HandleTable, NewSize);

            /* Free the memory */
            DosFreeMemory(Segment);

            /* Update the handle table pointer and size */
            PspBlock->HandleTableSize = NewSize;
            PspBlock->HandleTablePtr = MAKELONG(0x18, Sda->CurrentPsp);
        }
        else
        {
            /* Resize the memory */
            if (!DosResizeMemory(Segment, NewSize, NULL))
            {
                /* Unable to resize, try allocating it somewhere else */
                Segment = DosAllocateMemory(NewSize, NULL);
                if (Segment == 0) return FALSE;

                /* Get the new handle table */
                HandleTable = SEG_OFF_TO_PTR(Segment, 0);

                /* Copy the handles to the new table */
                RtlCopyMemory(HandleTable,
                              FAR_POINTER(PspBlock->HandleTablePtr),
                              PspBlock->HandleTableSize);

                /* Update the handle table pointer */
                PspBlock->HandleTablePtr = MAKELONG(0, Segment);
            }

            /* Update the handle table size */
            PspBlock->HandleTableSize = NewSize;
        }
    }
    else if (NewSize > DEFAULT_JFT_SIZE)
    {
        Segment = DosAllocateMemory(NewSize, NULL);
        if (Segment == 0) return FALSE;

        /* Get the new handle table */
        HandleTable = SEG_OFF_TO_PTR(Segment, 0);

        /* Copy the handles from the PSP to the new table */
        RtlCopyMemory(HandleTable,
                      FAR_POINTER(PspBlock->HandleTablePtr),
                      PspBlock->HandleTableSize);

        /* Update the handle table pointer and size */
        PspBlock->HandleTableSize = NewSize;
        PspBlock->HandleTablePtr = MAKELONG(0, Segment);
    }

    return TRUE;
}

WORD DosOpenHandle(BYTE DescriptorId)
{
    WORD DosHandle;
    PDOS_PSP PspBlock;
    LPBYTE HandleTable;
    PDOS_FILE_DESCRIPTOR Descriptor = DosGetFileDescriptor(DescriptorId);

    DPRINT("DosOpenHandle: DescriptorId 0x%02X\n", DescriptorId);

    /* Make sure the descriptor ID is valid */
    if (Descriptor == NULL) return INVALID_DOS_HANDLE;

    /* The system PSP has no handle table */
    if (Sda->CurrentPsp == SYSTEM_PSP) return INVALID_DOS_HANDLE;

    /* Get a pointer to the handle table */
    PspBlock = SEGMENT_TO_PSP(Sda->CurrentPsp);
    HandleTable = (LPBYTE)FAR_POINTER(PspBlock->HandleTablePtr);

    /* Find a free entry in the JFT */
    for (DosHandle = 0; DosHandle < PspBlock->HandleTableSize; DosHandle++)
    {
        if (HandleTable[DosHandle] == 0xFF) break;
    }

    /* If there are no free entries, fail */
    if (DosHandle == PspBlock->HandleTableSize) return INVALID_DOS_HANDLE;

    /* Reference the descriptor */
    Descriptor->RefCount++;

    /* Set the JFT entry to that descriptor ID */
    HandleTable[DosHandle] = DescriptorId;

    /* Return the new handle */
    return DosHandle;
}

BYTE DosQueryHandle(WORD DosHandle)
{
    PDOS_PSP PspBlock;
    LPBYTE HandleTable;

    DPRINT("DosQueryHandle: DosHandle 0x%04X\n", DosHandle);

    /* The system PSP has no handle table */
    if (Sda->CurrentPsp == SYSTEM_PSP) return 0xFF;

    /* Get a pointer to the handle table */
    PspBlock = SEGMENT_TO_PSP(Sda->CurrentPsp);
    HandleTable = (LPBYTE)FAR_POINTER(PspBlock->HandleTablePtr);

    /* Return the descriptor ID */
    return HandleTable[DosHandle];
}

WORD DosDuplicateHandle(WORD DosHandle)
{
    BYTE DescriptorId = DosQueryHandle(DosHandle);

    if (DescriptorId == 0xFF)
    {
        Sda->LastErrorCode = ERROR_INVALID_HANDLE;
        return INVALID_DOS_HANDLE;
    }

    return DosOpenHandle(DescriptorId);
}

BOOLEAN DosForceDuplicateHandle(WORD OldHandle, WORD NewHandle)
{
    BYTE DescriptorId;
    PDOS_PSP PspBlock;
    LPBYTE HandleTable;
    PDOS_FILE_DESCRIPTOR Descriptor;

    DPRINT("DosForceDuplicateHandle: OldHandle 0x%04X, NewHandle 0x%04X\n",
           OldHandle,
           NewHandle);

    /* The system PSP has no handle table */
    if (Sda->CurrentPsp == SYSTEM_PSP) return FALSE;

    /* Get a pointer to the handle table */
    PspBlock = SEGMENT_TO_PSP(Sda->CurrentPsp);
    HandleTable = (LPBYTE)FAR_POINTER(PspBlock->HandleTablePtr);

    /* Make sure the old handle is open */
    if (HandleTable[OldHandle] == 0xFF) return FALSE;

    /* Check if the new handle is open */
    if (HandleTable[NewHandle] != 0xFF)
    {
        /* Close it */
        DosCloseHandle(NewHandle);
    }

    DescriptorId = HandleTable[OldHandle];
    Descriptor = DosGetFileDescriptor(DescriptorId);
    if (Descriptor == NULL) return FALSE;

    /* Increment the reference count of the descriptor */
    Descriptor->RefCount++;

    /* Make the new handle point to that descriptor */
    HandleTable[NewHandle] = DescriptorId;

    /* Return success */
    return TRUE;
}

BOOLEAN DosCloseHandle(WORD DosHandle)
{
    PDOS_PSP PspBlock;
    LPBYTE HandleTable;
    PDOS_FILE_DESCRIPTOR Descriptor;

    DPRINT("DosCloseHandle: DosHandle 0x%04X\n", DosHandle);

    /* The system PSP has no handle table */
    if (Sda->CurrentPsp == SYSTEM_PSP) return FALSE;

    /* Get a pointer to the handle table */
    PspBlock = SEGMENT_TO_PSP(Sda->CurrentPsp);
    HandleTable = (LPBYTE)FAR_POINTER(PspBlock->HandleTablePtr);

    /* Make sure the handle is open */
    if (HandleTable[DosHandle] == 0xFF) return FALSE;

    /* Make sure the descriptor is valid */
    Descriptor = DosGetFileDescriptor(HandleTable[DosHandle]);
    if (Descriptor == NULL) return FALSE;

    /* Decrement the reference count of the descriptor */
    Descriptor->RefCount--;

    /* Check if the reference count fell to zero */
    if (!Descriptor->RefCount)
    {
        if (Descriptor->DeviceInfo & FILE_INFO_DEVICE)
        {
            PDOS_DEVICE_NODE Node = DosGetDriverNode(Descriptor->DevicePointer);

            /* Call the close routine, if it exists */
            if (Node->CloseRoutine) Node->CloseRoutine(Node);
        }
        else
        {
            /* Close the Win32 handle */
            CloseHandle(Descriptor->Win32Handle);
        }
    }

    /* Clear the entry in the JFT */
    HandleTable[DosHandle] = 0xFF;

    return TRUE;
}

