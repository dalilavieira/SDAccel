#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_10__   TYPE_4__ ;
typedef  struct TYPE_9__   TYPE_3__ ;
typedef  struct TYPE_8__   TYPE_2__ ;
typedef  struct TYPE_7__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  ULONG_PTR ;
typedef  int /*<<< orphan*/  ULONG ;
struct TYPE_7__ {int /*<<< orphan*/  LowPart; scalar_t__ HighPart; } ;
struct TYPE_8__ {TYPE_1__ u; } ;
struct TYPE_10__ {TYPE_2__ CurrentByteOffset; } ;
struct TYPE_9__ {int /*<<< orphan*/  Information; } ;
typedef  scalar_t__ PVOID ;
typedef  TYPE_3__ IO_STATUS_BLOCK ;
typedef  int /*<<< orphan*/  HANDLE ;
typedef  TYPE_4__ FILE_POSITION_INFORMATION ;
typedef  int BOOLEAN ;

/* Variables and functions */
 int /*<<< orphan*/  FilePositionInformation ; 
 int NT_SUCCESS (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  RosSymStatus ; 
 int /*<<< orphan*/  ZwReadFile (int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *,TYPE_3__*,scalar_t__,int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  ZwSetInformationFile (int /*<<< orphan*/ ,TYPE_3__*,scalar_t__,int,int /*<<< orphan*/ ) ; 

BOOLEAN
RosSymZwReadFile(PVOID FileContext, PVOID Buffer, ULONG Size)
{
	//NTSTATUS Status;
  IO_STATUS_BLOCK IoStatusBlock;

  RosSymStatus = ZwReadFile(*((HANDLE *) FileContext),
                      NULL, NULL, NULL,
                      &IoStatusBlock,
                      Buffer,
                      Size,
                      NULL, NULL);

  return NT_SUCCESS(RosSymStatus) && IoStatusBlock.Information == Size;
}

BOOLEAN
RosSymZwSeekFile(PVOID FileContext, ULONG_PTR Position)
{
	//NTSTATUS Status;
  IO_STATUS_BLOCK IoStatusBlock;
  FILE_POSITION_INFORMATION NewPosition;

  NewPosition.CurrentByteOffset.u.HighPart = 0;
  NewPosition.CurrentByteOffset.u.LowPart = Position;
  RosSymStatus = ZwSetInformationFile(*((HANDLE *) FileContext),
                                &IoStatusBlock,
                                (PVOID) &NewPosition,
                                sizeof(FILE_POSITION_INFORMATION),
                                FilePositionInformation);

  return NT_SUCCESS(RosSymStatus);
}

