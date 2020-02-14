#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_21__   TYPE_3__ ;
typedef  struct TYPE_20__   TYPE_2__ ;
typedef  struct TYPE_19__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  szPort ;
struct addrinfo {scalar_t__ ai_addrlen; int /*<<< orphan*/ * ai_addr; int /*<<< orphan*/  ai_protocol; int /*<<< orphan*/  ai_socktype; int /*<<< orphan*/  ai_family; struct addrinfo* ai_next; int /*<<< orphan*/ * ai_canonname; scalar_t__ ai_flags; } ;
typedef  int /*<<< orphan*/  service ;
typedef  int /*<<< orphan*/  host ;
typedef  scalar_t__ boolean ;
struct TYPE_19__ {int /*<<< orphan*/  vtbl; } ;
struct TYPE_20__ {int /*<<< orphan*/  szServerName; scalar_t__ dwPort; } ;
struct TYPE_21__ {scalar_t__ Status; int Socket; int cbBuffer; TYPE_1__ u; int /*<<< orphan*/ * pCallback; scalar_t__ fCommandLogging; int /*<<< orphan*/  (* fnCompletion ) (int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ;int /*<<< orphan*/ * hwnd; scalar_t__ iCurrentBufferOffset; int /*<<< orphan*/  pBuffer; TYPE_2__ ServerInfo; } ;
typedef  int /*<<< orphan*/  LPSTR ;
typedef  TYPE_2__* LPINETSERVER ;
typedef  char* LPCSTR ;
typedef  int /*<<< orphan*/  LONG_PTR ;
typedef  TYPE_3__ InternetTransport ;
typedef  scalar_t__ IXPSTATUS ;
typedef  int /*<<< orphan*/  (* INETXPORT_COMPLETION_FUNCTION ) (int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ;
typedef  int /*<<< orphan*/  IInternetTransport ;
typedef  int /*<<< orphan*/  IImnAccount ;
typedef  int /*<<< orphan*/  HRESULT ;

/* Variables and functions */
 int /*<<< orphan*/  CMD_SEND ; 
 int /*<<< orphan*/ * CreateWindowW (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  DestroyWindow (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  ERR (char*,int) ; 
 int /*<<< orphan*/  E_NOTIMPL ; 
 scalar_t__ FALSE ; 
 int /*<<< orphan*/  FD_READ ; 
 int /*<<< orphan*/  FIXME (char*,int /*<<< orphan*/ *,TYPE_2__*) ; 
 int /*<<< orphan*/  GWLP_USERDATA ; 
 int /*<<< orphan*/  GetLastError () ; 
 int /*<<< orphan*/  GetProcessHeap () ; 
 int /*<<< orphan*/  HRESULT_FROM_WIN32 (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  HeapAlloc (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  IPPROTO_TCP ; 
 int /*<<< orphan*/  ITransportCallback_OnCommand (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  ITransportCallback_OnStatus (int /*<<< orphan*/ *,scalar_t__,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  ITransportCallback_Release (int /*<<< orphan*/ *) ; 
 scalar_t__ IXP_CONNECTED ; 
 scalar_t__ IXP_CONNECTING ; 
 scalar_t__ IXP_DISCONNECTED ; 
 int /*<<< orphan*/  IXP_E_ALREADY_CONNECTED ; 
 int /*<<< orphan*/  IXP_E_BUSY ; 
 int /*<<< orphan*/  IXP_E_CANT_FIND_HOST ; 
 int /*<<< orphan*/  IXP_E_NOT_CONNECTED ; 
 scalar_t__ IXP_FINDINGHOST ; 
 int /*<<< orphan*/  IX_READLINE ; 
 int /*<<< orphan*/  InternetTransport_ChangeStatus (TYPE_3__*,scalar_t__) ; 
 int NI_NUMERICHOST ; 
 int NI_NUMERICSERV ; 
 int /*<<< orphan*/  PF_UNSPEC ; 
 int /*<<< orphan*/  SD_BOTH ; 
 int SOCKET_ERROR ; 
 int /*<<< orphan*/  SOCK_STREAM ; 
 int /*<<< orphan*/  S_FALSE ; 
 int /*<<< orphan*/  S_OK ; 
 int /*<<< orphan*/  SetWindowLongPtrW (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  TRACE (char*,...) ; 
 scalar_t__ TRACE_ON (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  WARN (char*) ; 
 int WSAAsyncSelect (int,int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int WSAGetLastError () ; 
 int /*<<< orphan*/  closesocket (int) ; 
 scalar_t__ connect (int,int /*<<< orphan*/ *,scalar_t__) ; 
 int /*<<< orphan*/  freeaddrinfo (struct addrinfo*) ; 
 int getaddrinfo (int /*<<< orphan*/ ,char*,struct addrinfo*,struct addrinfo**) ; 
 int /*<<< orphan*/  getnameinfo (int /*<<< orphan*/ *,scalar_t__,char*,int,char*,int,int) ; 
 int /*<<< orphan*/  inetcomm ; 
 int send (int,char const*,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  shutdown (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  snprintf (char*,int,char*,unsigned short) ; 
 int socket (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int strlen (char*) ; 
 int /*<<< orphan*/  wszClassName ; 

HRESULT InternetTransport_Init(InternetTransport *This)
{
    This->pCallback = NULL;
    This->Status = IXP_DISCONNECTED;
    This->Socket = -1;
    This->fCommandLogging = FALSE;
    This->fnCompletion = NULL;

    return S_OK;
}

HRESULT InternetTransport_GetServerInfo(InternetTransport *This, LPINETSERVER pInetServer)
{
    if (This->Status == IXP_DISCONNECTED)
        return IXP_E_NOT_CONNECTED;

    *pInetServer = This->ServerInfo;
    return S_OK;
}

HRESULT InternetTransport_InetServerFromAccount(InternetTransport *This,
    IImnAccount *pAccount, LPINETSERVER pInetServer)
{
    FIXME("(%p, %p): stub\n", pAccount, pInetServer);
    return E_NOTIMPL;
}

HRESULT InternetTransport_Connect(InternetTransport *This,
    LPINETSERVER pInetServer, boolean fAuthenticate, boolean fCommandLogging)
{
    struct addrinfo *ai;
    struct addrinfo *ai_cur;
    struct addrinfo hints;
    int ret;
    char szPort[10];

    if (This->Status != IXP_DISCONNECTED)
        return IXP_E_ALREADY_CONNECTED;

    This->ServerInfo = *pInetServer;
    This->fCommandLogging = fCommandLogging;

    This->hwnd = CreateWindowW(wszClassName, wszClassName, 0, 0, 0, 0, 0, NULL, NULL, NULL, 0);
    if (!This->hwnd)
        return HRESULT_FROM_WIN32(GetLastError());
    SetWindowLongPtrW(This->hwnd, GWLP_USERDATA, (LONG_PTR)This);

    hints.ai_flags          = 0;
    hints.ai_family         = PF_UNSPEC;
    hints.ai_socktype       = SOCK_STREAM;
    hints.ai_protocol       = IPPROTO_TCP;
    hints.ai_addrlen        = 0;
    hints.ai_addr           = NULL;
    hints.ai_canonname      = NULL;
    hints.ai_next           = NULL;

    snprintf(szPort, sizeof(szPort), "%d", (unsigned short)pInetServer->dwPort);

    InternetTransport_ChangeStatus(This, IXP_FINDINGHOST);

    ret = getaddrinfo(pInetServer->szServerName, szPort, &hints, &ai);
    if (ret)
    {
        ERR("getaddrinfo failed: %d\n", ret);
        return IXP_E_CANT_FIND_HOST;
    }

    for (ai_cur = ai; ai_cur; ai_cur = ai->ai_next)
    {
        int so;

        if (TRACE_ON(inetcomm))
        {
            char host[256];
            char service[256];
            getnameinfo(ai_cur->ai_addr, ai_cur->ai_addrlen,
                host, sizeof(host), service, sizeof(service),
                NI_NUMERICHOST | NI_NUMERICSERV);
            TRACE("trying %s:%s\n", host, service);
        }

        InternetTransport_ChangeStatus(This, IXP_CONNECTING);

        so = socket(ai_cur->ai_family, ai_cur->ai_socktype, ai_cur->ai_protocol);
        if (so == -1)
        {
            WARN("socket() failed\n");
            continue;
        }
        This->Socket = so;

        /* FIXME: set to async */

        if (0 > connect(This->Socket, ai_cur->ai_addr, ai_cur->ai_addrlen))
        {
            WARN("connect() failed\n");
            closesocket(This->Socket);
            continue;
        }
        InternetTransport_ChangeStatus(This, IXP_CONNECTED);

        /* FIXME: call WSAAsyncSelect */

        freeaddrinfo(ai);
        TRACE("connected\n");
        return S_OK;
    }

    freeaddrinfo(ai);

    return IXP_E_CANT_FIND_HOST;
}

HRESULT InternetTransport_HandsOffCallback(InternetTransport *This)
{
    if (!This->pCallback)
        return S_FALSE;

    ITransportCallback_Release(This->pCallback);
    This->pCallback = NULL;

    return S_OK;
}

HRESULT InternetTransport_DropConnection(InternetTransport *This)
{
    if (This->Status == IXP_DISCONNECTED)
        return IXP_E_NOT_CONNECTED;

    shutdown(This->Socket, SD_BOTH);

    closesocket(This->Socket);

    DestroyWindow(This->hwnd);
    This->hwnd = NULL;

    InternetTransport_ChangeStatus(This, IXP_DISCONNECTED);

    return S_OK;
}

HRESULT InternetTransport_GetStatus(InternetTransport *This,
    IXPSTATUS *pCurrentStatus)
{
    *pCurrentStatus = This->Status;
    return S_OK;
}

HRESULT InternetTransport_ChangeStatus(InternetTransport *This, IXPSTATUS Status)
{
    This->Status = Status;
    if (This->pCallback)
        ITransportCallback_OnStatus(This->pCallback, Status,
            (IInternetTransport *)&This->u.vtbl);
    return S_OK;
}

HRESULT InternetTransport_ReadLine(InternetTransport *This,
    INETXPORT_COMPLETION_FUNCTION fnCompletion)
{
    if (This->Status == IXP_DISCONNECTED)
        return IXP_E_NOT_CONNECTED;

    if (This->fnCompletion)
        return IXP_E_BUSY;

    This->fnCompletion = fnCompletion;

    This->cbBuffer = 1024;
    This->pBuffer = HeapAlloc(GetProcessHeap(), 0, This->cbBuffer);
    This->iCurrentBufferOffset = 0;

    if (WSAAsyncSelect(This->Socket, This->hwnd, IX_READLINE, FD_READ) == SOCKET_ERROR)
    {
        ERR("WSAAsyncSelect failed with error %d\n", WSAGetLastError());
        /* FIXME: handle error */
    }
    return S_OK;
}

HRESULT InternetTransport_Write(InternetTransport *This, const char *pvData,
    int cbSize, INETXPORT_COMPLETION_FUNCTION fnCompletion)
{
    int ret;

    if (This->Status == IXP_DISCONNECTED)
        return IXP_E_NOT_CONNECTED;

    if (This->fnCompletion)
        return IXP_E_BUSY;

    /* FIXME: do this asynchronously */
    ret = send(This->Socket, pvData, cbSize, 0);
    if (ret == SOCKET_ERROR)
    {
        ERR("send failed with error %d\n", WSAGetLastError());
        /* FIXME: handle error */
    }

    fnCompletion((IInternetTransport *)&This->u.vtbl, NULL, 0);

    return S_OK;
}

HRESULT InternetTransport_DoCommand(InternetTransport *This,
    LPCSTR pszCommand, INETXPORT_COMPLETION_FUNCTION fnCompletion)
{
    if (This->Status == IXP_DISCONNECTED)
        return IXP_E_NOT_CONNECTED;

    if (This->fnCompletion)
        return IXP_E_BUSY;

    if (This->pCallback && This->fCommandLogging)
    {
        ITransportCallback_OnCommand(This->pCallback, CMD_SEND, (LPSTR)pszCommand, 0,
            (IInternetTransport *)&This->u.vtbl);
    }
    return InternetTransport_Write(This, pszCommand, strlen(pszCommand), fnCompletion);
}

