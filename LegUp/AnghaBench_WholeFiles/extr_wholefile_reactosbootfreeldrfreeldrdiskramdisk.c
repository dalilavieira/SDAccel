#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_11__   TYPE_4__ ;
typedef  struct TYPE_10__   TYPE_3__ ;
typedef  struct TYPE_9__   TYPE_2__ ;
typedef  struct TYPE_8__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  VOID ;
typedef  scalar_t__ ULONG_PTR ;
typedef  scalar_t__ ULONG ;
struct TYPE_8__ {scalar_t__ LowPart; } ;
struct TYPE_9__ {scalar_t__ LowPart; } ;
struct TYPE_11__ {TYPE_1__ CurrentAddress; TYPE_2__ EndingAddress; } ;
struct TYPE_10__ {scalar_t__ HighPart; scalar_t__ LowPart; } ;
typedef  scalar_t__ SEEKMODE ;
typedef  scalar_t__ PVOID ;
typedef  int /*<<< orphan*/  OPENMODE ;
typedef  TYPE_3__ LARGE_INTEGER ;
typedef  TYPE_4__ FILEINFORMATION ;
typedef  int /*<<< orphan*/  CHAR ;
typedef  int /*<<< orphan*/  ARC_STATUS ;

/* Variables and functions */
 int /*<<< orphan*/  EINVAL ; 
 int /*<<< orphan*/  EIO ; 
 int /*<<< orphan*/  ESUCCESS ; 
 int /*<<< orphan*/  RtlCopyMemory (int /*<<< orphan*/ *,scalar_t__,scalar_t__) ; 
 int /*<<< orphan*/  RtlZeroMemory (TYPE_4__*,int) ; 
 scalar_t__ SeekAbsolute ; 
 scalar_t__ gRamDiskBase ; 
 scalar_t__ gRamDiskOffset ; 
 scalar_t__ gRamDiskSize ; 

__attribute__((used)) static ARC_STATUS RamDiskClose(ULONG FileId)
{
    //
    // Nothing to do
    //
    return ESUCCESS;
}

__attribute__((used)) static ARC_STATUS RamDiskGetFileInformation(ULONG FileId, FILEINFORMATION* Information)
{
    //
    // Give current seek offset and ram disk size to caller
    //
    RtlZeroMemory(Information, sizeof(FILEINFORMATION));
    Information->EndingAddress.LowPart = gRamDiskSize;
    Information->CurrentAddress.LowPart = gRamDiskOffset;

    return ESUCCESS;
}

__attribute__((used)) static ARC_STATUS RamDiskOpen(CHAR* Path, OPENMODE OpenMode, ULONG* FileId)
{
    //
    // Always return success, as contents are already in memory
    //
    return ESUCCESS;
}

__attribute__((used)) static ARC_STATUS RamDiskRead(ULONG FileId, VOID* Buffer, ULONG N, ULONG* Count)
{
    PVOID StartAddress;

    //
    // Get actual pointer
    //
    StartAddress = (PVOID)((ULONG_PTR)gRamDiskBase + gRamDiskOffset);

    //
    // Don't allow reads past our image
    //
    if (gRamDiskOffset + N > gRamDiskSize)
    {
        *Count = 0;
        return EIO;
    }

    //
    // Do the read
    //
    RtlCopyMemory(Buffer, StartAddress, N);
    *Count = N;

    return ESUCCESS;
}

__attribute__((used)) static ARC_STATUS RamDiskSeek(ULONG FileId, LARGE_INTEGER* Position, SEEKMODE SeekMode)
{
    //
    // Only accept absolute mode now
    //
    if (SeekMode != SeekAbsolute)
        return EINVAL;

    //
    // Check if we're in the ramdisk
    //
    if (Position->HighPart != 0)
        return EINVAL;
    if (Position->LowPart >= gRamDiskSize)
        return EINVAL;

    //
    // OK, remember seek position
    //
    gRamDiskOffset = Position->LowPart;

    return ESUCCESS;
}

