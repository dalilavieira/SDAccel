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
typedef  int /*<<< orphan*/  VOID ;
typedef  int /*<<< orphan*/  ULONG ;
typedef  int /*<<< orphan*/  PWSTR ;
typedef  int /*<<< orphan*/  PWCHAR ;
typedef  int /*<<< orphan*/  PULONG ;
typedef  int /*<<< orphan*/  PUCHAR ;
typedef  int /*<<< orphan*/  PINFCONTEXT ;
typedef  int /*<<< orphan*/  PCWSTR ;
typedef  int /*<<< orphan*/  LONG ;
typedef  int /*<<< orphan*/  INT ;
typedef  int /*<<< orphan*/  HINF ;
typedef  int /*<<< orphan*/  BOOLEAN ;

/* Variables and functions */
 int /*<<< orphan*/  INF_SUCCESS (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  InfpFindFirstLine (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  InfpFindFirstMatchLine (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  InfpFindNextLine (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  InfpFindNextMatchLine (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  InfpFreeContext (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  InfpGetBinaryField (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  InfpGetData (int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  InfpGetDataField (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  InfpGetFieldCount (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  InfpGetIntField (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  InfpGetLineCount (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  InfpGetMultiSzField (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  InfpGetStringField (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

BOOLEAN
InfFindFirstLine(HINF InfHandle,
                 PCWSTR Section,
                 PCWSTR Key,
                 PINFCONTEXT *Context)
{
  return INF_SUCCESS(InfpFindFirstLine(InfHandle, Section, Key, Context));
}

BOOLEAN
InfFindNextLine(PINFCONTEXT ContextIn,
                 PINFCONTEXT ContextOut)
{
  return INF_SUCCESS(InfpFindNextLine(ContextIn, ContextOut));
}

BOOLEAN
InfFindFirstMatchLine(PINFCONTEXT ContextIn,
                      PCWSTR Key,
                      PINFCONTEXT ContextOut)
{
  return INF_SUCCESS(InfpFindFirstMatchLine(ContextIn, Key, ContextOut));
}

BOOLEAN
InfFindNextMatchLine(PINFCONTEXT ContextIn,
                     PCWSTR Key,
                     PINFCONTEXT ContextOut)
{
  return INF_SUCCESS(InfpFindNextMatchLine(ContextIn, Key, ContextOut));
}

LONG
InfGetLineCount(HINF InfHandle,
                PCWSTR Section)
{
  return InfpGetLineCount(InfHandle, Section);
}

LONG
InfGetFieldCount(PINFCONTEXT Context)
{
  return InfpGetFieldCount(Context);
}

BOOLEAN
InfGetBinaryField(PINFCONTEXT Context,
                  ULONG FieldIndex,
                  PUCHAR ReturnBuffer,
                  ULONG ReturnBufferSize,
                  PULONG RequiredSize)
{
  return INF_SUCCESS(InfpGetBinaryField(Context, FieldIndex, ReturnBuffer,
                                        ReturnBufferSize, RequiredSize));
}

BOOLEAN
InfGetIntField(PINFCONTEXT Context,
               ULONG FieldIndex,
               INT *IntegerValue)
{
  return INF_SUCCESS(InfpGetIntField(Context, FieldIndex, IntegerValue));
}

BOOLEAN
InfGetMultiSzField(PINFCONTEXT Context,
                   ULONG FieldIndex,
                   PWSTR ReturnBuffer,
                   ULONG ReturnBufferSize,
                   PULONG RequiredSize)
{
  return INF_SUCCESS(InfpGetMultiSzField(Context, FieldIndex, ReturnBuffer,
                                         ReturnBufferSize, RequiredSize));
}

BOOLEAN
InfGetStringField(PINFCONTEXT Context,
                  ULONG FieldIndex,
                  PWSTR ReturnBuffer,
                  ULONG ReturnBufferSize,
                  PULONG RequiredSize)
{
  return INF_SUCCESS(InfpGetStringField(Context, FieldIndex, ReturnBuffer,
                                        ReturnBufferSize, RequiredSize));
}

BOOLEAN
InfGetData(PINFCONTEXT Context,
           PWCHAR *Key,
           PWCHAR *Data)
{
  return INF_SUCCESS(InfpGetData(Context, Key, Data));
}

BOOLEAN
InfGetDataField (PINFCONTEXT Context,
                 ULONG FieldIndex,
                 PWCHAR *Data)
{
  return INF_SUCCESS(InfpGetDataField(Context, FieldIndex, Data));
}

VOID
InfFreeContext(PINFCONTEXT Context)
{
  InfpFreeContext(Context);
}

