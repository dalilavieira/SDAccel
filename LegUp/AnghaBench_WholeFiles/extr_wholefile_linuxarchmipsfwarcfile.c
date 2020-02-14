#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */

/* Type definitions */
struct linux_vdirent {int dummy; } ;
struct linux_finfo {int dummy; } ;
struct linux_bigint {int dummy; } ;
typedef  enum linux_seekmode { ____Placeholder_linux_seekmode } linux_seekmode ;
typedef  enum linux_omode { ____Placeholder_linux_omode } linux_omode ;
typedef  enum linux_mountops { ____Placeholder_linux_mountops } linux_mountops ;
typedef  struct linux_vdirent VOID ;
typedef  int /*<<< orphan*/  ULONG ;
typedef  struct linux_vdirent* PVOID ;
typedef  int /*<<< orphan*/ * PULONG ;
typedef  int /*<<< orphan*/  LONG ;
typedef  int /*<<< orphan*/  CHAR ;

/* Variables and functions */
 int /*<<< orphan*/  ARC_CALL1 (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ARC_CALL2 (int /*<<< orphan*/ ,char*,int) ; 
 int /*<<< orphan*/  ARC_CALL3 (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int,int) ; 
 int /*<<< orphan*/  ARC_CALL4 (int /*<<< orphan*/ ,int /*<<< orphan*/ ,struct linux_vdirent*,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  close ; 
 int /*<<< orphan*/  get_finfo ; 
 int /*<<< orphan*/  get_rstatus ; 
 int /*<<< orphan*/  get_vdirent ; 
 int /*<<< orphan*/  mount ; 
 int /*<<< orphan*/  open ; 
 int /*<<< orphan*/  read ; 
 int /*<<< orphan*/  seek ; 
 int /*<<< orphan*/  set_finfo ; 
 int /*<<< orphan*/  write ; 

LONG
ArcGetDirectoryEntry(ULONG FileID, struct linux_vdirent *Buffer,
		     ULONG N, ULONG *Count)
{
	return ARC_CALL4(get_vdirent, FileID, Buffer, N, Count);
}

LONG
ArcOpen(CHAR *Path, enum linux_omode OpenMode, ULONG *FileID)
{
	return ARC_CALL3(open, Path, OpenMode, FileID);
}

LONG
ArcClose(ULONG FileID)
{
	return ARC_CALL1(close, FileID);
}

LONG
ArcRead(ULONG FileID, VOID *Buffer, ULONG N, ULONG *Count)
{
	return ARC_CALL4(read, FileID, Buffer, N, Count);
}

LONG
ArcGetReadStatus(ULONG FileID)
{
	return ARC_CALL1(get_rstatus, FileID);
}

LONG
ArcWrite(ULONG FileID, PVOID Buffer, ULONG N, PULONG Count)
{
	return ARC_CALL4(write, FileID, Buffer, N, Count);
}

LONG
ArcSeek(ULONG FileID, struct linux_bigint *Position, enum linux_seekmode SeekMode)
{
	return ARC_CALL3(seek, FileID, Position, SeekMode);
}

LONG
ArcMount(char *name, enum linux_mountops op)
{
	return ARC_CALL2(mount, name, op);
}

LONG
ArcGetFileInformation(ULONG FileID, struct linux_finfo *Information)
{
	return ARC_CALL2(get_finfo, FileID, Information);
}

LONG ArcSetFileInformation(ULONG FileID, ULONG AttributeFlags,
			   ULONG AttributeMask)
{
	return ARC_CALL3(set_finfo, FileID, AttributeFlags, AttributeMask);
}

