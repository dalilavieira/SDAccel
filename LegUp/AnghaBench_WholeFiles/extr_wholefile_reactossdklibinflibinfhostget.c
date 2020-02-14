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
typedef  int /*<<< orphan*/  WCHAR ;
typedef  int /*<<< orphan*/  VOID ;
typedef  int /*<<< orphan*/  ULONG ;
typedef  int /*<<< orphan*/  UCHAR ;
typedef  int /*<<< orphan*/  PINFCONTEXT ;
typedef  int /*<<< orphan*/  PCWSTR ;
typedef  int /*<<< orphan*/  LONG ;
typedef  int /*<<< orphan*/  INT ;
typedef  int /*<<< orphan*/  INFSTATUS ;
typedef  int /*<<< orphan*/  HINF ;

/* Variables and functions */
 scalar_t__ INF_SUCCESS (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  InfpFindFirstLine (int /*<<< orphan*/ ,int /*<<< orphan*/  const*,int /*<<< orphan*/  const*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  InfpFindFirstMatchLine (int /*<<< orphan*/ ,int /*<<< orphan*/  const*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  InfpFindNextLine (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  InfpFindNextMatchLine (int /*<<< orphan*/ ,int /*<<< orphan*/  const*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  InfpFreeContext (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  InfpGetBinaryField (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  InfpGetData (int /*<<< orphan*/ ,int /*<<< orphan*/ **,int /*<<< orphan*/ **) ; 
 int /*<<< orphan*/  InfpGetDataField (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ **) ; 
 int /*<<< orphan*/  InfpGetFieldCount (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  InfpGetIntField (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  InfpGetLineCount (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  InfpGetMultiSzField (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  InfpGetStringField (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  errno ; 

int
InfHostFindFirstLine(HINF InfHandle,
                     const WCHAR *Section,
                     const WCHAR *Key,
                     PINFCONTEXT *Context)
{
  INFSTATUS Status;

  Status = InfpFindFirstLine(InfHandle, Section, Key, Context);
  if (INF_SUCCESS(Status))
    {
      return 0;
    }
  else
    {
      errno = Status;
      return -1;
    }
}

int
InfHostFindNextLine(PINFCONTEXT ContextIn,
                    PINFCONTEXT ContextOut)
{
  INFSTATUS Status;

  Status = InfpFindNextLine(ContextIn, ContextOut);
  if (INF_SUCCESS(Status))
    {
      return 0;
    }
  else
    {
      errno = Status;
      return -1;
    }
}

int
InfHostFindFirstMatchLine(PINFCONTEXT ContextIn,
                          const WCHAR *Key,
                          PINFCONTEXT ContextOut)
{
  INFSTATUS Status;

  Status = InfpFindFirstMatchLine(ContextIn, Key, ContextOut);
  if (INF_SUCCESS(Status))
    {
      return 0;
    }
  else
    {
      errno = Status;
      return -1;
    }
}

int
InfHostFindNextMatchLine(PINFCONTEXT ContextIn,
                         const WCHAR *Key,
                         PINFCONTEXT ContextOut)
{
  INFSTATUS Status;

  Status = InfpFindNextMatchLine(ContextIn, Key, ContextOut);
  if (INF_SUCCESS(Status))
    {
      return 0;
    }
  else
    {
      errno = Status;
      return -1;
    }
}

LONG
InfHostGetLineCount(HINF InfHandle,
                    PCWSTR Section)
{
  return InfpGetLineCount(InfHandle, Section);
}

LONG
InfHostGetFieldCount(PINFCONTEXT Context)
{
  return InfpGetFieldCount(Context);
}

int
InfHostGetBinaryField(PINFCONTEXT Context,
                      ULONG FieldIndex,
                      UCHAR *ReturnBuffer,
                      ULONG ReturnBufferSize,
                      ULONG *RequiredSize)
{
  INFSTATUS Status;

  Status = InfpGetBinaryField(Context, FieldIndex, ReturnBuffer,
                              ReturnBufferSize, RequiredSize);
  if (INF_SUCCESS(Status))
    {
      return 0;
    }
  else
    {
      errno = Status;
      return -1;
    }
}

int
InfHostGetIntField(PINFCONTEXT Context,
                   ULONG FieldIndex,
                   INT *IntegerValue)
{
  INFSTATUS Status;

  Status = InfpGetIntField(Context, FieldIndex, IntegerValue);
  if (INF_SUCCESS(Status))
    {
      return 0;
    }
  else
    {
      errno = Status;
      return -1;
    }
}

int
InfHostGetMultiSzField(PINFCONTEXT Context,
                       ULONG FieldIndex,
                       WCHAR *ReturnBuffer,
                       ULONG ReturnBufferSize,
                       ULONG *RequiredSize)
{
  INFSTATUS Status;

  Status = InfpGetMultiSzField(Context, FieldIndex, ReturnBuffer,
                               ReturnBufferSize, RequiredSize);
  if (INF_SUCCESS(Status))
    {
      return 0;
    }
  else
    {
      errno = Status;
      return -1;
    }
}

int
InfHostGetStringField(PINFCONTEXT Context,
                      ULONG FieldIndex,
                      WCHAR *ReturnBuffer,
                      ULONG ReturnBufferSize,
                      ULONG *RequiredSize)
{
  INFSTATUS Status;

  Status = InfpGetStringField(Context, FieldIndex, ReturnBuffer,
                              ReturnBufferSize, RequiredSize);
  if (INF_SUCCESS(Status))
    {
      return 0;
    }
  else
    {
      errno = Status;
      return -1;
    }
}

int
InfHostGetData(PINFCONTEXT Context,
               WCHAR **Key,
               WCHAR **Data)
{
  INFSTATUS Status;

  Status = InfpGetData(Context, Key, Data);
  if (INF_SUCCESS(Status))
    {
      return 0;
    }
  else
    {
      errno = Status;
      return -1;
    }
}

int
InfHostGetDataField(PINFCONTEXT Context,
                    ULONG FieldIndex,
                    WCHAR **Data)
{
  INFSTATUS Status;

  Status = InfpGetDataField(Context, FieldIndex, Data);
  if (INF_SUCCESS(Status))
    {
      return 0;
    }
  else
    {
      errno = Status;
      return -1;
    }
}

VOID
InfHostFreeContext(PINFCONTEXT Context)
{
  InfpFreeContext(Context);
}

