#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_43__   TYPE_9__ ;
typedef  struct TYPE_42__   TYPE_8__ ;
typedef  struct TYPE_41__   TYPE_7__ ;
typedef  struct TYPE_40__   TYPE_6__ ;
typedef  struct TYPE_39__   TYPE_5__ ;
typedef  struct TYPE_38__   TYPE_4__ ;
typedef  struct TYPE_37__   TYPE_3__ ;
typedef  struct TYPE_36__   TYPE_2__ ;
typedef  struct TYPE_35__   TYPE_27__ ;
typedef  struct TYPE_34__   TYPE_1__ ;
typedef  struct TYPE_33__   TYPE_11__ ;
typedef  struct TYPE_32__   TYPE_10__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  user ;
typedef  int /*<<< orphan*/  pass ;
struct TYPE_43__ {int cbSoFar; char* pszLines; int cbLines; void* fBody; void* fHeader; int /*<<< orphan*/  dwPopId; } ;
struct TYPE_42__ {scalar_t__ cbMessages; scalar_t__ cMessages; } ;
struct TYPE_41__ {int cbSoFar; char* pszLines; int cbLines; void* fBody; void* fHeader; int /*<<< orphan*/  cPreviewLines; int /*<<< orphan*/  dwPopId; } ;
struct TYPE_38__ {char* szPassword; char* szUserName; } ;
struct TYPE_37__ {int /*<<< orphan*/  vtbl; int /*<<< orphan*/  vtblPOP3; } ;
struct TYPE_35__ {scalar_t__ pCallback; TYPE_4__ ServerInfo; TYPE_3__ u; scalar_t__ fCommandLogging; } ;
struct TYPE_40__ {int state; char* response; char* ptr; int command; TYPE_27__ InetTransport; void* valid_info; int /*<<< orphan*/  preview_lines; int /*<<< orphan*/  msgid; int /*<<< orphan*/  type; } ;
struct TYPE_39__ {char* pszUidl; scalar_t__ dwPopId; } ;
struct TYPE_36__ {char* pszResponse; int /*<<< orphan*/  hrServerError; int /*<<< orphan*/ * pszProblem; int /*<<< orphan*/  dwSocketError; int /*<<< orphan*/  hrResult; scalar_t__ uiServerError; } ;
struct TYPE_33__ {scalar_t__ cbSize; scalar_t__ dwPopId; } ;
struct TYPE_34__ {TYPE_7__ rTopInfo; TYPE_9__ rRetrInfo; int /*<<< orphan*/  dwPopId; TYPE_11__ rListInfo; TYPE_8__ rStatInfo; TYPE_5__ rUidlInfo; } ;
struct TYPE_32__ {int command; int fDone; TYPE_2__ rIxpResult; int /*<<< orphan*/ * pTransport; void* fValidInfo; TYPE_1__ u; } ;
typedef  int /*<<< orphan*/  REFIID ;
typedef  TYPE_5__ POP3UIDL ;
typedef  TYPE_6__ POP3Transport ;
typedef  TYPE_7__ POP3TOP ;
typedef  TYPE_8__ POP3STAT ;
typedef  TYPE_9__ POP3RETR ;
typedef  TYPE_10__ POP3RESPONSE ;
typedef  TYPE_11__ POP3LIST ;
typedef  int POP3COMMAND ;
typedef  int /*<<< orphan*/  LPVOID ;
typedef  int /*<<< orphan*/  IPOP3Transport ;
typedef  int /*<<< orphan*/  IPOP3Callback ;
typedef  int /*<<< orphan*/  IInternetTransport ;
typedef  int /*<<< orphan*/  IClassFactory ;
typedef  int /*<<< orphan*/  HRESULT ;
typedef  int /*<<< orphan*/  DWORD ;

/* Variables and functions */
 int /*<<< orphan*/  CMD_RESP ; 
 scalar_t__ FAILED (int /*<<< orphan*/ ) ; 
 void* FALSE ; 
 int /*<<< orphan*/  GetProcessHeap () ; 
 char* HeapAlloc (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  HeapFree (int /*<<< orphan*/ ,int /*<<< orphan*/ ,char*) ; 
 int /*<<< orphan*/  IClassFactory_QueryInterface (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  IPOP3Callback_OnResponse (int /*<<< orphan*/ *,TYPE_10__*) ; 
 int /*<<< orphan*/  ITransportCallback_OnCommand (scalar_t__,int /*<<< orphan*/ ,char*,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  IXP_AUTHORIZED ; 
 int /*<<< orphan*/  IXP_CONNECTED ; 
 int /*<<< orphan*/  InternetTransport_ChangeStatus (TYPE_27__*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  InternetTransport_DoCommand (TYPE_27__*,char*,void (*) (int /*<<< orphan*/ *,char*,int)) ; 
 int /*<<< orphan*/  InternetTransport_DropConnection (TYPE_27__*) ; 
 int /*<<< orphan*/  InternetTransport_ReadLine (TYPE_27__*,void (*) (int /*<<< orphan*/ *,char*,int)) ; 
 int /*<<< orphan*/  POP3CMD_GET_POPID ; 
 int /*<<< orphan*/  POP3TransportCF ; 
#define  POP3_DELE 136 
#define  POP3_LIST 135 
 int POP3_PASS ; 
#define  POP3_RETR 134 
#define  POP3_STAT 133 
#define  POP3_TOP 132 
#define  POP3_UIDL 131 
 scalar_t__ STATE_DONE ; 
#define  STATE_MULTILINE 130 
#define  STATE_NONE 129 
#define  STATE_OK 128 
 scalar_t__ SUCCEEDED (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  S_FALSE ; 
 int /*<<< orphan*/  S_OK ; 
 int /*<<< orphan*/  TRACE (char*,...) ; 
 void* TRUE ; 
 int /*<<< orphan*/  WARN (char*) ; 
 int /*<<< orphan*/  WSAGetLastError () ; 
 int /*<<< orphan*/  debugstr_a (char*) ; 
 int /*<<< orphan*/  debugstr_an (char*,int) ; 
 int /*<<< orphan*/  memcmp (char*,char*,int) ; 
 int /*<<< orphan*/  sscanf (char*,char*,scalar_t__*,...) ; 
 int /*<<< orphan*/  strcat (char*,char*) ; 
 char* strchr (char*,char) ; 
 int /*<<< orphan*/  strcpy (char*,char const*) ; 
 int strlen (char*) ; 

__attribute__((used)) static HRESULT parse_response(POP3Transport *This)
{
    switch (This->state)
    {
    case STATE_NONE:
        if (strlen(This->response) < 3)
        {
            WARN("parse error\n");
            This->state = STATE_DONE;
            return S_FALSE;
        }
        if (!memcmp(This->response, "+OK", 3))
        {
            This->ptr = This->response + 3;
            This->state = STATE_OK;
            return S_OK;
        }
        This->state = STATE_DONE;
        return S_FALSE;

    default: return S_OK;
    }
}

__attribute__((used)) static HRESULT parse_uidl_response(POP3Transport *This, POP3UIDL *uidl)
{
    char *p;

    uidl->dwPopId = 0;
    uidl->pszUidl = NULL;
    switch (This->state)
    {
    case STATE_OK:
        if (This->type == POP3CMD_GET_POPID)
        {
            if ((p = strchr(This->ptr, ' ')))
            {
                while (*p == ' ') p++;
                sscanf(p, "%u", &uidl->dwPopId);
                if ((p = strchr(p, ' ')))
                {
                    while (*p == ' ') p++;
                    uidl->pszUidl = p;
                    This->valid_info = TRUE;
                }
             }
             This->state = STATE_DONE;
             return S_OK;
        }
        This->state = STATE_MULTILINE;
        return S_OK;

    case STATE_MULTILINE:
        if (This->response[0] == '.' && !This->response[1])
        {
            This->valid_info = FALSE;
            This->state = STATE_DONE;
            return S_OK;
        }
        sscanf(This->response, "%u", &uidl->dwPopId);
        if ((p = strchr(This->response, ' ')))
        {
            while (*p == ' ') p++;
            uidl->pszUidl = p;
            This->valid_info = TRUE;
            return S_OK;
        }

    default:
        WARN("parse error\n");
        This->state = STATE_DONE;
        return S_FALSE;
    }
}

__attribute__((used)) static HRESULT parse_stat_response(POP3Transport *This, POP3STAT *stat)
{
    char *p;

    stat->cMessages = 0;
    stat->cbMessages = 0;
    switch (This->state)
    {
    case STATE_OK:
        if ((p = strchr(This->ptr, ' ')))
        {
            while (*p == ' ') p++;
            sscanf(p, "%u %u", &stat->cMessages, &stat->cbMessages);
            This->valid_info = TRUE;
            This->state = STATE_DONE;
            return S_OK;
        }

    default:
        WARN("parse error\n");
        This->state = STATE_DONE;
        return S_FALSE;
    }
}

__attribute__((used)) static HRESULT parse_list_response(POP3Transport *This, POP3LIST *list)
{
    char *p;

    list->dwPopId = 0;
    list->cbSize = 0;
    switch (This->state)
    {
    case STATE_OK:
        if (This->type == POP3CMD_GET_POPID)
        {
            if ((p = strchr(This->ptr, ' ')))
            {
                while (*p == ' ') p++;
                sscanf(p, "%u %u", &list->dwPopId, &list->cbSize);
                This->valid_info = TRUE;
            }
            This->state = STATE_DONE;
            return S_OK;
        }
        This->state = STATE_MULTILINE;
        return S_OK;

    case STATE_MULTILINE:
        if (This->response[0] == '.' && !This->response[1])
        {
            This->valid_info = FALSE;
            This->state = STATE_DONE;
            return S_OK;
        }
        sscanf(This->response, "%u", &list->dwPopId);
        if ((p = strchr(This->response, ' ')))
        {
            while (*p == ' ') p++;
            sscanf(p, "%u", &list->cbSize);
            This->valid_info = TRUE;
            return S_OK;
        }

    default:
        WARN("parse error\n");
        This->state = STATE_DONE;
        return S_FALSE;
    }
}

__attribute__((used)) static HRESULT parse_dele_response(POP3Transport *This, DWORD *dwPopId)
{
    switch (This->state)
    {
    case STATE_OK:
        *dwPopId = 0; /* FIXME */
        This->state = STATE_DONE;
        return S_OK;

    default:
        WARN("parse error\n");
        This->state = STATE_DONE;
        return S_FALSE;
    }
}

__attribute__((used)) static HRESULT parse_retr_response(POP3Transport *This, POP3RETR *retr)
{
    switch (This->state)
    {
    case STATE_OK:
        retr->fHeader = FALSE;
        retr->fBody = FALSE;
        retr->dwPopId = This->msgid;
        retr->cbSoFar = 0;
        retr->pszLines = This->response;
        retr->cbLines = 0;

        This->state = STATE_MULTILINE;
        This->valid_info = FALSE;
        return S_OK;

    case STATE_MULTILINE:
    {
        int len;

        if (This->response[0] == '.' && !This->response[1])
        {
            retr->cbLines = retr->cbSoFar;
            This->state = STATE_DONE;
            return S_OK;
        }
        retr->fHeader = TRUE;
        if (!This->response[0]) retr->fBody = TRUE;

        len = strlen(This->response);
        retr->cbSoFar += len;
        retr->pszLines = This->response;
        retr->cbLines = len;

        This->valid_info = TRUE;
        return S_OK;
    }

    default:
        WARN("parse error\n");
        This->state = STATE_DONE;
        return S_FALSE;
    }
}

__attribute__((used)) static HRESULT parse_top_response(POP3Transport *This, POP3TOP *top)
{
    switch (This->state)
    {
    case STATE_OK:
        top->fHeader = FALSE;
        top->fBody = FALSE;
        top->dwPopId = This->msgid;
        top->cPreviewLines = This->preview_lines;
        top->cbSoFar = 0;
        top->pszLines = This->response;
        top->cbLines = 0;

        This->state = STATE_MULTILINE;
        This->valid_info = FALSE;
        return S_OK;

    case STATE_MULTILINE:
    {
        int len;

        if (This->response[0] == '.' && !This->response[1])
        {
            top->cbLines = top->cbSoFar;
            This->state = STATE_DONE;
            return S_OK;
        }
        top->fHeader = TRUE;
        if (!This->response[0]) top->fBody = TRUE;

        len = strlen(This->response);
        top->cbSoFar += len;
        top->pszLines = This->response;
        top->cbLines = len;

        This->valid_info = TRUE;
        return S_OK;
    }

    default:
        WARN("parse error\n");
        This->state = STATE_DONE;
        return S_FALSE;
    }
}

__attribute__((used)) static void init_parser(POP3Transport *This, POP3COMMAND command)
{
    This->state = STATE_NONE;
    This->command = command;
}

__attribute__((used)) static HRESULT POP3Transport_ParseResponse(POP3Transport *This, char *pszResponse, POP3RESPONSE *pResponse)
{
    HRESULT hr;

    TRACE("response: %s\n", debugstr_a(pszResponse));

    This->response = pszResponse;
    This->valid_info = FALSE;
    TRACE("state %u\n", This->state);

    if (SUCCEEDED((hr = parse_response(This))))
    {
        switch (This->command)
        {
        case POP3_UIDL: hr = parse_uidl_response(This, &pResponse->u.rUidlInfo); break;
        case POP3_STAT: hr = parse_stat_response(This, &pResponse->u.rStatInfo); break;
        case POP3_LIST: hr = parse_list_response(This, &pResponse->u.rListInfo); break;
        case POP3_DELE: hr = parse_dele_response(This, &pResponse->u.dwPopId); break;
        case POP3_RETR: hr = parse_retr_response(This, &pResponse->u.rRetrInfo); break;
        case POP3_TOP: hr = parse_top_response(This, &pResponse->u.rTopInfo); break;
        default:
            This->state = STATE_DONE;
            break;
        }
    }
    pResponse->command = This->command;
    pResponse->fDone = (This->state == STATE_DONE);
    pResponse->fValidInfo = This->valid_info;
    pResponse->rIxpResult.hrResult = hr;
    pResponse->rIxpResult.pszResponse = pszResponse;
    pResponse->rIxpResult.uiServerError = 0;
    pResponse->rIxpResult.hrServerError = pResponse->rIxpResult.hrResult;
    pResponse->rIxpResult.dwSocketError = WSAGetLastError();
    pResponse->rIxpResult.pszProblem = NULL;
    pResponse->pTransport = (IPOP3Transport *)&This->InetTransport.u.vtblPOP3;

    if (This->InetTransport.pCallback && This->InetTransport.fCommandLogging)
    {
        ITransportCallback_OnCommand(This->InetTransport.pCallback, CMD_RESP,
            pResponse->rIxpResult.pszResponse, pResponse->rIxpResult.hrServerError,
            (IInternetTransport *)&This->InetTransport.u.vtbl);
    }
    return S_OK;
}

__attribute__((used)) static void POP3Transport_CallbackProcessDELEResp(IInternetTransport *iface, char *pBuffer, int cbBuffer)
{
    POP3Transport *This = (POP3Transport *)iface;
    POP3RESPONSE response;
    HRESULT hr;

    TRACE("\n");

    hr = POP3Transport_ParseResponse(This, pBuffer, &response);
    if (FAILED(hr))
    {
        /* FIXME: handle error */
        return;
    }

    IPOP3Callback_OnResponse((IPOP3Callback *)This->InetTransport.pCallback, &response);
}

__attribute__((used)) static void POP3Transport_CallbackRecvDELEResp(IInternetTransport *iface, char *pBuffer, int cbBuffer)
{
    POP3Transport *This = (POP3Transport *)iface;

    TRACE("\n");
    InternetTransport_ReadLine(&This->InetTransport, POP3Transport_CallbackProcessDELEResp);
}

__attribute__((used)) static void POP3Transport_CallbackProcessNOOPResp(IInternetTransport *iface, char *pBuffer, int cbBuffer)
{
    POP3Transport *This = (POP3Transport *)iface;
    POP3RESPONSE response;
    HRESULT hr;

    TRACE("\n");

    hr = POP3Transport_ParseResponse(This, pBuffer, &response);
    if (FAILED(hr))
    {
        /* FIXME: handle error */
        return;
    }

    IPOP3Callback_OnResponse((IPOP3Callback *)This->InetTransport.pCallback, &response);
}

__attribute__((used)) static void POP3Transport_CallbackRecvNOOPResp(IInternetTransport *iface, char *pBuffer, int cbBuffer)
{
    POP3Transport *This = (POP3Transport *)iface;

    TRACE("\n");
    InternetTransport_ReadLine(&This->InetTransport, POP3Transport_CallbackProcessNOOPResp);
}

__attribute__((used)) static void POP3Transport_CallbackProcessRSETResp(IInternetTransport *iface, char *pBuffer, int cbBuffer)
{
    POP3Transport *This = (POP3Transport *)iface;
    POP3RESPONSE response;
    HRESULT hr;

    TRACE("\n");

    hr = POP3Transport_ParseResponse(This, pBuffer, &response);
    if (FAILED(hr))
    {
        /* FIXME: handle error */
        return;
    }

    IPOP3Callback_OnResponse((IPOP3Callback *)This->InetTransport.pCallback, &response);
}

__attribute__((used)) static void POP3Transport_CallbackRecvRSETResp(IInternetTransport *iface, char *pBuffer, int cbBuffer)
{
    POP3Transport *This = (POP3Transport *)iface;

    TRACE("\n");
    InternetTransport_ReadLine(&This->InetTransport, POP3Transport_CallbackProcessRSETResp);
}

__attribute__((used)) static void POP3Transport_CallbackProcessRETRResp(IInternetTransport *iface, char *pBuffer, int cbBuffer)
{
    POP3Transport *This = (POP3Transport *)iface;
    POP3RESPONSE response;
    HRESULT hr;

    TRACE("\n");

    hr = POP3Transport_ParseResponse(This, pBuffer, &response);
    if (FAILED(hr))
    {
        /* FIXME: handle error */
        return;
    }

    IPOP3Callback_OnResponse((IPOP3Callback *)This->InetTransport.pCallback, &response);

    if (!response.fDone)
    {
        InternetTransport_ReadLine(&This->InetTransport, POP3Transport_CallbackProcessRETRResp);
        return;
    }

    IPOP3Callback_OnResponse((IPOP3Callback *)This->InetTransport.pCallback, &response);
}

__attribute__((used)) static void POP3Transport_CallbackRecvRETRResp(IInternetTransport *iface, char *pBuffer, int cbBuffer)
{
    POP3Transport *This = (POP3Transport *)iface;

    TRACE("\n");
    InternetTransport_ReadLine(&This->InetTransport, POP3Transport_CallbackProcessRETRResp);
}

__attribute__((used)) static void POP3Transport_CallbackProcessTOPResp(IInternetTransport *iface, char *pBuffer, int cbBuffer)
{
    POP3Transport *This = (POP3Transport *)iface;
    POP3RESPONSE response;
    HRESULT hr;

    TRACE("\n");

    hr = POP3Transport_ParseResponse(This, pBuffer, &response);
    if (FAILED(hr))
    {
        /* FIXME: handle error */
        return;
    }

    IPOP3Callback_OnResponse((IPOP3Callback *)This->InetTransport.pCallback, &response);

    if (!response.fDone)
    {
        InternetTransport_ReadLine(&This->InetTransport, POP3Transport_CallbackProcessTOPResp);
        return;
    }

    IPOP3Callback_OnResponse((IPOP3Callback *)This->InetTransport.pCallback, &response);
}

__attribute__((used)) static void POP3Transport_CallbackRecvTOPResp(IInternetTransport *iface, char *pBuffer, int cbBuffer)
{
    POP3Transport *This = (POP3Transport *)iface;

    TRACE("\n");
    InternetTransport_ReadLine(&This->InetTransport, POP3Transport_CallbackProcessTOPResp);
}

__attribute__((used)) static void POP3Transport_CallbackProcessLISTResp(IInternetTransport *iface, char *pBuffer, int cbBuffer)
{
    POP3Transport *This = (POP3Transport *)iface;
    POP3RESPONSE response;
    HRESULT hr;

    TRACE("\n");

    hr = POP3Transport_ParseResponse(This, pBuffer, &response);
    if (FAILED(hr))
    {
        /* FIXME: handle error */
        return;
    }

    IPOP3Callback_OnResponse((IPOP3Callback *)This->InetTransport.pCallback, &response);

    if (!response.fDone)
    {
        InternetTransport_ReadLine(&This->InetTransport, POP3Transport_CallbackProcessLISTResp);
        return;
    }

    IPOP3Callback_OnResponse((IPOP3Callback *)This->InetTransport.pCallback, &response);
}

__attribute__((used)) static void POP3Transport_CallbackRecvLISTResp(IInternetTransport *iface, char *pBuffer, int cbBuffer)
{
    POP3Transport *This = (POP3Transport *)iface;

    TRACE("\n");
    InternetTransport_ReadLine(&This->InetTransport, POP3Transport_CallbackProcessLISTResp);
}

__attribute__((used)) static void POP3Transport_CallbackProcessUIDLResp(IInternetTransport *iface, char *pBuffer, int cbBuffer)
{
    POP3Transport *This = (POP3Transport *)iface;
    POP3RESPONSE response;
    HRESULT hr;

    TRACE("\n");

    hr = POP3Transport_ParseResponse(This, pBuffer, &response);
    if (FAILED(hr))
    {
        /* FIXME: handle error */
        return;
    }

    IPOP3Callback_OnResponse((IPOP3Callback *)This->InetTransport.pCallback, &response);

    if (!response.fDone)
    {
        InternetTransport_ReadLine(&This->InetTransport, POP3Transport_CallbackProcessUIDLResp);
        return;
    }

    IPOP3Callback_OnResponse((IPOP3Callback *)This->InetTransport.pCallback, &response);
}

__attribute__((used)) static void POP3Transport_CallbackRecvUIDLResp(IInternetTransport *iface, char *pBuffer, int cbBuffer)
{
    POP3Transport *This = (POP3Transport *)iface;

    TRACE("\n");
    InternetTransport_ReadLine(&This->InetTransport, POP3Transport_CallbackProcessUIDLResp);
}

__attribute__((used)) static void POP3Transport_CallbackProcessSTATResp(IInternetTransport *iface, char *pBuffer, int cbBuffer)
{
    POP3Transport *This = (POP3Transport *)iface;
    POP3RESPONSE response;
    HRESULT hr;

    TRACE("\n");

    hr = POP3Transport_ParseResponse(This, pBuffer, &response);
    if (FAILED(hr))
    {
        /* FIXME: handle error */
        return;
    }

    IPOP3Callback_OnResponse((IPOP3Callback *)This->InetTransport.pCallback, &response);
}

__attribute__((used)) static void POP3Transport_CallbackRecvSTATResp(IInternetTransport *iface, char *pBuffer, int cbBuffer)
{
    POP3Transport *This = (POP3Transport *)iface;

    TRACE("\n");
    InternetTransport_ReadLine(&This->InetTransport, POP3Transport_CallbackProcessSTATResp);
}

__attribute__((used)) static void POP3Transport_CallbackProcessPASSResp(IInternetTransport *iface, char *pBuffer, int cbBuffer)
{
    POP3Transport *This = (POP3Transport *)iface;
    POP3RESPONSE response;
    HRESULT hr;

    TRACE("\n");

    hr = POP3Transport_ParseResponse(This, pBuffer, &response);
    if (FAILED(hr))
    {
        /* FIXME: handle error */
        return;
    }

    InternetTransport_ChangeStatus(&This->InetTransport, IXP_AUTHORIZED);
    InternetTransport_ChangeStatus(&This->InetTransport, IXP_CONNECTED);

    IPOP3Callback_OnResponse((IPOP3Callback *)This->InetTransport.pCallback, &response);
}

__attribute__((used)) static void POP3Transport_CallbackRecvPASSResp(IInternetTransport *iface, char *pBuffer, int cbBuffer)
{
    POP3Transport *This = (POP3Transport *)iface;

    TRACE("\n");
    InternetTransport_ReadLine(&This->InetTransport, POP3Transport_CallbackProcessPASSResp);
}

__attribute__((used)) static void POP3Transport_CallbackProcessUSERResp(IInternetTransport *iface, char *pBuffer, int cbBuffer)
{
    static const char pass[] = "PASS ";
    POP3Transport *This = (POP3Transport *)iface;
    POP3RESPONSE response;
    char *command;
    int len;
    HRESULT hr;

    TRACE("\n");

    hr = POP3Transport_ParseResponse(This, pBuffer, &response);
    if (FAILED(hr))
    {
        /* FIXME: handle error */
        return;
    }

    IPOP3Callback_OnResponse((IPOP3Callback *)This->InetTransport.pCallback, &response);

    len = sizeof(pass) + strlen(This->InetTransport.ServerInfo.szPassword) + 2; /* "\r\n" */
    command = HeapAlloc(GetProcessHeap(), 0, len);

    strcpy(command, pass);
    strcat(command, This->InetTransport.ServerInfo.szPassword);
    strcat(command, "\r\n");

    init_parser(This, POP3_PASS);

    InternetTransport_DoCommand(&This->InetTransport, command, POP3Transport_CallbackRecvPASSResp);
    HeapFree(GetProcessHeap(), 0, command);
}

__attribute__((used)) static void POP3Transport_CallbackRecvUSERResp(IInternetTransport *iface, char *pBuffer, int cbBuffer)
{
    POP3Transport *This = (POP3Transport *)iface;

    TRACE("\n");
    InternetTransport_ReadLine(&This->InetTransport, POP3Transport_CallbackProcessUSERResp);
}

__attribute__((used)) static void POP3Transport_CallbackSendUSERCmd(IInternetTransport *iface, char *pBuffer, int cbBuffer)
{
    static const char user[] = "USER ";
    POP3Transport *This = (POP3Transport *)iface;
    char *command;
    int len;

    TRACE("\n");

    len = sizeof(user) + strlen(This->InetTransport.ServerInfo.szUserName) + 2; /* "\r\n" */
    command = HeapAlloc(GetProcessHeap(), 0, len);

    strcpy(command, user);
    strcat(command, This->InetTransport.ServerInfo.szUserName);
    strcat(command, "\r\n");
    InternetTransport_DoCommand(&This->InetTransport, command, POP3Transport_CallbackRecvUSERResp);

    HeapFree(GetProcessHeap(), 0, command);
}

__attribute__((used)) static void POP3Transport_CallbackProcessQUITResponse(IInternetTransport *iface, char *pBuffer, int cbBuffer)
{
    POP3Transport *This = (POP3Transport *)iface;
    POP3RESPONSE response;
    HRESULT hr;

    TRACE("%s\n", debugstr_an(pBuffer, cbBuffer));

    hr = POP3Transport_ParseResponse(This, pBuffer, &response);
    if (FAILED(hr))
    {
        /* FIXME: handle error */
        return;
    }

    IPOP3Callback_OnResponse((IPOP3Callback *)This->InetTransport.pCallback, &response);
    InternetTransport_DropConnection(&This->InetTransport);
}

__attribute__((used)) static void POP3Transport_CallbackRecvQUITResp(IInternetTransport *iface, char *pBuffer, int cbBuffer)
{
    POP3Transport *This = (POP3Transport *)iface;

    TRACE("\n");
    InternetTransport_ReadLine(&This->InetTransport, POP3Transport_CallbackProcessQUITResponse);
}

HRESULT POP3TransportCF_Create(REFIID riid, LPVOID *ppv)
{
    return IClassFactory_QueryInterface((IClassFactory *)&POP3TransportCF, riid, ppv);
}

