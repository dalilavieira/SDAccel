#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_18__   TYPE_4__ ;
typedef  struct TYPE_17__   TYPE_3__ ;
typedef  struct TYPE_16__   TYPE_2__ ;
typedef  struct TYPE_15__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  VOID ;
typedef  scalar_t__ UCHAR ;
struct TYPE_18__ {unsigned int Units; int /*<<< orphan*/  Billions; } ;
struct TYPE_15__ {void* HardReset; void* SoftReset; void* InterruptReset; } ;
struct TYPE_17__ {scalar_t__ All; TYPE_1__ Bits; } ;
struct TYPE_16__ {scalar_t__ IO_Address; } ;
typedef  scalar_t__ PUCHAR ;
typedef  TYPE_2__ BusLogic_HostAdapter_T ;
typedef  TYPE_3__ BusLogic_ControlRegister_T ;
typedef  int /*<<< orphan*/ * BusLogic_CommandSizeBuckets_T ;
typedef  TYPE_4__ BusLogic_ByteCounter_T ;

/* Variables and functions */
 scalar_t__ BusLogic_CommandParameterRegisterOffset ; 
 scalar_t__ BusLogic_ControlRegisterOffset ; 
 scalar_t__ BusLogic_DataInRegisterOffset ; 
 scalar_t__ BusLogic_ExecuteMailboxCommand ; 
 scalar_t__ BusLogic_GeometryRegisterOffset ; 
 scalar_t__ BusLogic_InterruptRegisterOffset ; 
 scalar_t__ BusLogic_StatusRegisterOffset ; 
 scalar_t__ ScsiPortReadPortUchar (scalar_t__) ; 
 int /*<<< orphan*/  ScsiPortWritePortUchar (scalar_t__,scalar_t__) ; 
 void* TRUE ; 

__attribute__((used)) static UCHAR
ReadBusLogicPort(PUCHAR adr )
{
    return ScsiPortReadPortUchar( adr );
}

__attribute__((used)) static VOID
WriteBusLogicPort(UCHAR data,
                  PUCHAR adr)
{
    ScsiPortWritePortUchar(adr, data);
}

__attribute__((used)) static void
BusLogic_InterruptReset(BusLogic_HostAdapter_T *HostAdapter)
{
  BusLogic_ControlRegister_T ControlRegister;
  ControlRegister.All = 0;
  ControlRegister.Bits.InterruptReset = TRUE;

  WriteBusLogicPort(ControlRegister.All,
       HostAdapter->IO_Address + BusLogic_ControlRegisterOffset);
}

__attribute__((used)) static void
BusLogic_SoftReset(BusLogic_HostAdapter_T *HostAdapter)
{
  BusLogic_ControlRegister_T ControlRegister;
  ControlRegister.All = 0;
  ControlRegister.Bits.SoftReset = TRUE;
  WriteBusLogicPort(ControlRegister.All,
       HostAdapter->IO_Address + BusLogic_ControlRegisterOffset);
}

__attribute__((used)) static void
BusLogic_HardReset(BusLogic_HostAdapter_T *HostAdapter)
{
  BusLogic_ControlRegister_T ControlRegister;
  ControlRegister.All = 0;
  ControlRegister.Bits.HardReset = TRUE;
  WriteBusLogicPort(ControlRegister.All,
       HostAdapter->IO_Address + BusLogic_ControlRegisterOffset);
}

__attribute__((used)) static UCHAR
BusLogic_ReadStatusRegister(BusLogic_HostAdapter_T *HostAdapter)
{
  return ReadBusLogicPort(HostAdapter->IO_Address + BusLogic_StatusRegisterOffset);
}

__attribute__((used)) static UCHAR
BusLogic_ReadInterruptRegister(BusLogic_HostAdapter_T *HostAdapter)
{
  return ReadBusLogicPort(HostAdapter->IO_Address + BusLogic_InterruptRegisterOffset);
}

__attribute__((used)) static UCHAR
BusLogic_ReadGeometryRegister(BusLogic_HostAdapter_T *HostAdapter)
{
  return ReadBusLogicPort(HostAdapter->IO_Address + BusLogic_GeometryRegisterOffset);
}

__attribute__((used)) static UCHAR
BusLogic_ReadDataInRegister(BusLogic_HostAdapter_T *HostAdapter)
{
  return ReadBusLogicPort(HostAdapter->IO_Address + BusLogic_DataInRegisterOffset);
}

__attribute__((used)) static void
BusLogic_WriteCommandParameterRegister(BusLogic_HostAdapter_T *HostAdapter,
                                       UCHAR Value)
{
  WriteBusLogicPort(Value,
                    HostAdapter->IO_Address + BusLogic_CommandParameterRegisterOffset);
}

__attribute__((used)) static void
BusLogic_StartMailboxCommand(BusLogic_HostAdapter_T *HostAdapter)
{
  BusLogic_WriteCommandParameterRegister(HostAdapter,
                                         BusLogic_ExecuteMailboxCommand);
}

__attribute__((used)) static void
BusLogic_IncrementByteCounter(BusLogic_ByteCounter_T *ByteCounter,
                              unsigned int Amount)
{
  ByteCounter->Units += Amount;
  if (ByteCounter->Units > 999999999)
  {
      ByteCounter->Units -= 1000000000;
      ByteCounter->Billions++;
  }
}

__attribute__((used)) static void
BusLogic_IncrementSizeBucket(BusLogic_CommandSizeBuckets_T CommandSizeBuckets,
                             unsigned int Amount)
{
  int Index = 0;
  if (Amount < 8*1024)
  {
    if (Amount < 2*1024)
        Index = (Amount < 1*1024 ? 0 : 1);
    else
        Index = (Amount < 4*1024 ? 2 : 3);
  }
  else if (Amount < 128*1024)
  {
    if (Amount < 32*1024)
        Index = (Amount < 16*1024 ? 4 : 5);
    else
        Index = (Amount < 64*1024 ? 6 : 7);
  }
  else
      Index = (Amount < 256*1024 ? 8 : 9);
  CommandSizeBuckets[Index]++;
}

__attribute__((used)) static void
BusLogic_IncrementErrorCounter(unsigned short *ErrorCounter)
{
  if (*ErrorCounter < 65535) (*ErrorCounter)++;
}

