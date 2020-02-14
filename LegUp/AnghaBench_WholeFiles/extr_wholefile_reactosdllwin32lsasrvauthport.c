#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_31__   TYPE_3__ ;
typedef  struct TYPE_30__   TYPE_2__ ;
typedef  struct TYPE_29__   TYPE_1__ ;
typedef  struct TYPE_28__   TYPE_15__ ;
typedef  struct TYPE_27__   TYPE_12__ ;

/* Type definitions */
struct TYPE_27__ {int /*<<< orphan*/  UniqueThread; int /*<<< orphan*/  UniqueProcess; } ;
struct TYPE_28__ {TYPE_12__ ClientId; } ;
struct TYPE_29__ {scalar_t__ CreateContext; int OperationalMode; TYPE_3__* Status; TYPE_3__* LogonProcessNameBuffer; } ;
struct TYPE_31__ {void* ClientProcessHandle; void* ConnectionHandle; int /*<<< orphan*/  Entry; TYPE_15__ h; TYPE_1__ ConnectInfo; } ;
struct TYPE_30__ {int Length; } ;
typedef  TYPE_2__ REMOTE_PORT_VIEW ;
typedef  int /*<<< orphan*/  PVOID ;
typedef  TYPE_3__* PLSA_API_MSG ;
typedef  TYPE_3__* PLSAP_LOGON_CONTEXT ;
typedef  int /*<<< orphan*/  OBJECT_ATTRIBUTES ;
typedef  TYPE_3__* NTSTATUS ;
typedef  int /*<<< orphan*/  LSAP_LOGON_CONTEXT ;
typedef  void* HANDLE ;
typedef  scalar_t__ BOOLEAN ;

/* Variables and functions */
 int /*<<< orphan*/  ERR (char*,TYPE_3__*) ; 
 scalar_t__ FALSE ; 
 int /*<<< orphan*/  HEAP_ZERO_MEMORY ; 
 int /*<<< orphan*/  InitializeObjectAttributes (int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  InsertHeadList (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  LsapLogonContextList ; 
 scalar_t__ NT_SUCCESS (TYPE_3__*) ; 
 TYPE_3__* NtAcceptConnectPort (void**,int /*<<< orphan*/ *,TYPE_15__*,scalar_t__,int /*<<< orphan*/ *,TYPE_2__*) ; 
 int /*<<< orphan*/  NtClose (void*) ; 
 TYPE_3__* NtCompleteConnectPort (void*) ; 
 TYPE_3__* NtOpenProcess (void**,int,int /*<<< orphan*/ *,TYPE_12__*) ; 
 int PROCESS_DUP_HANDLE ; 
 int PROCESS_VM_OPERATION ; 
 int PROCESS_VM_READ ; 
 int PROCESS_VM_WRITE ; 
 int /*<<< orphan*/  RemoveHeadList (int /*<<< orphan*/ *) ; 
 TYPE_3__* RtlAllocateHeap (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  RtlFreeHeap (int /*<<< orphan*/ ,int /*<<< orphan*/ ,TYPE_3__*) ; 
 int /*<<< orphan*/  RtlGetProcessHeap () ; 
 TYPE_3__* STATUS_INSUFFICIENT_RESOURCES ; 
 TYPE_3__* STATUS_SUCCESS ; 
 int /*<<< orphan*/  TRACE (char*,TYPE_3__*,...) ; 
 scalar_t__ TRUE ; 

__attribute__((used)) static NTSTATUS
LsapDeregisterLogonProcess(PLSA_API_MSG RequestMsg,
                           PLSAP_LOGON_CONTEXT LogonContext)
{
    TRACE("LsapDeregisterLogonProcess(%p %p)\n", RequestMsg, LogonContext);

    RemoveHeadList(&LogonContext->Entry);

    NtClose(LogonContext->ClientProcessHandle);
    NtClose(LogonContext->ConnectionHandle);

    RtlFreeHeap(RtlGetProcessHeap(), 0, LogonContext);

    return STATUS_SUCCESS;
}

__attribute__((used)) static NTSTATUS
LsapCheckLogonProcess(PLSA_API_MSG RequestMsg,
                      PLSAP_LOGON_CONTEXT *LogonContext)
{
    OBJECT_ATTRIBUTES ObjectAttributes;
    HANDLE ProcessHandle = NULL;
    PLSAP_LOGON_CONTEXT Context = NULL;
    NTSTATUS Status;

    TRACE("LsapCheckLogonProcess(%p)\n", RequestMsg);

    TRACE("Client ID: %p %p\n", RequestMsg->h.ClientId.UniqueProcess, RequestMsg->h.ClientId.UniqueThread);

    InitializeObjectAttributes(&ObjectAttributes,
                               NULL,
                               0,
                               NULL,
                               NULL);

    Status = NtOpenProcess(&ProcessHandle,
                           PROCESS_VM_READ | PROCESS_VM_WRITE | PROCESS_VM_OPERATION | PROCESS_DUP_HANDLE,
                           &ObjectAttributes,
                           &RequestMsg->h.ClientId);
    if (!NT_SUCCESS(Status))
    {
        TRACE("NtOpenProcess() failed (Status %lx)\n", Status);
        return Status;
    }

    /* Allocate the logon context */
    Context = RtlAllocateHeap(RtlGetProcessHeap(),
                              HEAP_ZERO_MEMORY,
                              sizeof(LSAP_LOGON_CONTEXT));
    if (Context == NULL)
    {
        NtClose(ProcessHandle);
        return STATUS_INSUFFICIENT_RESOURCES;
    }

    TRACE("New LogonContext: %p\n", Context);

    Context->ClientProcessHandle = ProcessHandle;

    *LogonContext = Context;

    return STATUS_SUCCESS;
}

__attribute__((used)) static NTSTATUS
LsapHandlePortConnection(PLSA_API_MSG RequestMsg)
{
    PLSAP_LOGON_CONTEXT LogonContext = NULL;
    HANDLE ConnectionHandle = NULL;
    BOOLEAN Accept;
    REMOTE_PORT_VIEW RemotePortView;
    NTSTATUS Status = STATUS_SUCCESS;

    TRACE("LsapHandlePortConnection(%p)\n", RequestMsg);

    TRACE("Logon Process Name: %s\n", RequestMsg->ConnectInfo.LogonProcessNameBuffer);

    if (RequestMsg->ConnectInfo.CreateContext != FALSE)
    {
        Status = LsapCheckLogonProcess(RequestMsg,
                                       &LogonContext);

        RequestMsg->ConnectInfo.OperationalMode = 0x43218765;

        RequestMsg->ConnectInfo.Status = Status;
    }

    if (NT_SUCCESS(Status))
    {
        Accept = TRUE;
    }
    else
    {
        Accept = FALSE;
    }

    RemotePortView.Length = sizeof(REMOTE_PORT_VIEW);
    Status = NtAcceptConnectPort(&ConnectionHandle,
                                 (PVOID*)LogonContext,
                                 &RequestMsg->h,
                                 Accept,
                                 NULL,
                                 &RemotePortView);
    if (!NT_SUCCESS(Status))
    {
        ERR("NtAcceptConnectPort failed (Status 0x%lx)\n", Status);
        return Status;
    }

    if (Accept != FALSE)
    {
        if (LogonContext != NULL)
        {
            LogonContext->ConnectionHandle = ConnectionHandle;

            InsertHeadList(&LsapLogonContextList,
                           &LogonContext->Entry);
        }

        Status = NtCompleteConnectPort(ConnectionHandle);
        if (!NT_SUCCESS(Status))
        {
            ERR("NtCompleteConnectPort failed (Status 0x%lx)\n", Status);
            return Status;
        }
    }

    return Status;
}

