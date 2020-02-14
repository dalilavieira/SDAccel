#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_26__   TYPE_8__ ;
typedef  struct TYPE_25__   TYPE_7__ ;
typedef  struct TYPE_24__   TYPE_6__ ;
typedef  struct TYPE_23__   TYPE_5__ ;
typedef  struct TYPE_22__   TYPE_4__ ;
typedef  struct TYPE_21__   TYPE_3__ ;
typedef  struct TYPE_20__   TYPE_2__ ;
typedef  struct TYPE_19__   TYPE_1__ ;
typedef  struct TYPE_18__   TYPE_12__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  szCommandFormat ;
typedef  int /*<<< orphan*/  response ;
typedef  int ULONG ;
struct TYPE_21__ {char* pszResponse; int uiServerError; void* hrServerError; void* hrResult; scalar_t__ dwSocketError; } ;
struct TYPE_26__ {int fDone; TYPE_3__ rIxpResult; int /*<<< orphan*/  command; int /*<<< orphan*/  member_0; int /*<<< orphan*/ * pTransport; } ;
struct TYPE_20__ {int dwFlags; } ;
struct TYPE_19__ {int /*<<< orphan*/  vtbl; int /*<<< orphan*/  vtblSMTP2; } ;
struct TYPE_18__ {scalar_t__ pCallback; TYPE_2__ ServerInfo; TYPE_1__ u; scalar_t__ fCommandLogging; } ;
struct TYPE_23__ {size_t cAddress; TYPE_4__* prgAddress; } ;
struct TYPE_24__ {int cbSize; TYPE_5__ rAddressList; int /*<<< orphan*/  pstmMsg; } ;
struct TYPE_25__ {char* addrlist; int fESMTP; size_t ulCurrentAddressIndex; TYPE_12__ InetTransport; TYPE_6__ pending_message; } ;
struct TYPE_22__ {char* szEmail; int addrtype; } ;
typedef  TYPE_7__ SMTPTransport ;
typedef  TYPE_8__ SMTPRESPONSE ;
typedef  int /*<<< orphan*/  REFIID ;
typedef  int /*<<< orphan*/  LPVOID ;
typedef  int /*<<< orphan*/  ISMTPTransport ;
typedef  int /*<<< orphan*/  ISMTPCallback ;
typedef  int /*<<< orphan*/  IInternetTransport ;
typedef  int /*<<< orphan*/  IClassFactory ;
typedef  void* HRESULT ;

/* Variables and functions */
 int ADDR_TO ; 
 int ADDR_TOFROM_MASK ; 
 int /*<<< orphan*/  CMD_RESP ; 
 int /*<<< orphan*/  ERR (char*,int /*<<< orphan*/ ) ; 
 scalar_t__ FAILED (void*) ; 
 int /*<<< orphan*/  GetProcessHeap () ; 
 char* HeapAlloc (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  HeapFree (int /*<<< orphan*/ ,int /*<<< orphan*/ ,char*) ; 
 void* IClassFactory_QueryInterface (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int ISF_QUERYAUTHSUPPORT ; 
 int ISF_QUERYDSNSUPPORT ; 
 int ISF_SSLONSAMEPORT ; 
 int /*<<< orphan*/  ISMTPCallback_OnResponse (int /*<<< orphan*/ *,TYPE_8__*) ; 
 void* IStream_Read (int /*<<< orphan*/ ,char*,int,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  IStream_Release (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ITransportCallback_OnCommand (scalar_t__,int /*<<< orphan*/ ,char*,void*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  IXP_AUTHORIZED ; 
 int /*<<< orphan*/  IXP_CONNECTED ; 
 void* IXP_E_SMTP_211_SYSTEM_STATUS ; 
 void* IXP_E_SMTP_214_HELP_MESSAGE ; 
 void* IXP_E_SMTP_220_READY ; 
 void* IXP_E_SMTP_221_CLOSING ; 
 void* IXP_E_SMTP_245_AUTH_SUCCESS ; 
 void* IXP_E_SMTP_250_MAIL_ACTION_OKAY ; 
 void* IXP_E_SMTP_251_FORWARDING_MAIL ; 
 void* IXP_E_SMTP_334_AUTH_READY_RESPONSE ; 
 void* IXP_E_SMTP_354_START_MAIL_INPUT ; 
 void* IXP_E_SMTP_421_NOT_AVAILABLE ; 
 void* IXP_E_SMTP_450_MAILBOX_BUSY ; 
 void* IXP_E_SMTP_451_ERROR_PROCESSING ; 
 void* IXP_E_SMTP_452_NO_SYSTEM_STORAGE ; 
 void* IXP_E_SMTP_454_STARTTLS_FAILED ; 
 void* IXP_E_SMTP_500_SYNTAX_ERROR ; 
 void* IXP_E_SMTP_501_PARAM_SYNTAX ; 
 void* IXP_E_SMTP_502_COMMAND_NOTIMPL ; 
 void* IXP_E_SMTP_503_COMMAND_SEQ ; 
 void* IXP_E_SMTP_504_COMMAND_PARAM_NOTIMPL ; 
 void* IXP_E_SMTP_530_STARTTLS_REQUIRED ; 
 void* IXP_E_SMTP_550_MAILBOX_NOT_FOUND ; 
 void* IXP_E_SMTP_551_USER_NOT_LOCAL ; 
 void* IXP_E_SMTP_552_STORAGE_OVERFLOW ; 
 void* IXP_E_SMTP_553_MAILBOX_NAME_SYNTAX ; 
 void* IXP_E_SMTP_554_TRANSACT_FAILED ; 
 void* IXP_E_SMTP_RESPONSE_ERROR ; 
 int /*<<< orphan*/  InternetTransport_ChangeStatus (TYPE_12__*,int /*<<< orphan*/ ) ; 
 void* InternetTransport_DoCommand (TYPE_12__*,char*,void (*) (int /*<<< orphan*/ *,char*,int)) ; 
 int /*<<< orphan*/  InternetTransport_DropConnection (TYPE_12__*) ; 
 int /*<<< orphan*/  InternetTransport_ReadLine (TYPE_12__*,void (*) (int /*<<< orphan*/ *,char*,int)) ; 
 void* InternetTransport_Write (TYPE_12__*,char*,int,void (*) (int /*<<< orphan*/ *,char*,int)) ; 
 int /*<<< orphan*/  SMTPTransportCF ; 
static  void SMTPTransport_CallbackMessageSendTo (int /*<<< orphan*/ *,char*,int) ; 
 int /*<<< orphan*/  SMTP_BANNER ; 
 int /*<<< orphan*/  SMTP_CONNECTED ; 
 int /*<<< orphan*/  SMTP_DATA ; 
 int /*<<< orphan*/  SMTP_EHLO ; 
 int /*<<< orphan*/  SMTP_HELO ; 
 int /*<<< orphan*/  SMTP_MAIL ; 
 int /*<<< orphan*/  SMTP_RCPT ; 
 int /*<<< orphan*/  SMTP_SEND_MESSAGE ; 
 void* S_OK ; 
 int /*<<< orphan*/  TRACE (char*,...) ; 
 int TRUE ; 
 int /*<<< orphan*/  debugstr_a (char*) ; 
 int /*<<< orphan*/  isdigit (char) ; 
 int /*<<< orphan*/  memset (TYPE_8__*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  sprintf (char*,char const*,char*) ; 
 int /*<<< orphan*/  strcat (char*,char const*) ; 
 int /*<<< orphan*/  strcpy (char*,char const*) ; 
 int strlen (char const*) ; 
 scalar_t__ strstr (char*,char*) ; 
 int strtol (char*,char**,int) ; 

__attribute__((used)) static HRESULT SMTPTransport_ParseResponse(SMTPTransport *This, char *pszResponse, SMTPRESPONSE *pResponse)
{
    HRESULT hrServerError;

    TRACE("response: %s\n", debugstr_a(pszResponse));

    if (!isdigit(*pszResponse))
        return IXP_E_SMTP_RESPONSE_ERROR;
    pResponse->pTransport = (ISMTPTransport *)&This->InetTransport.u.vtblSMTP2;
    pResponse->rIxpResult.pszResponse = pszResponse;
    pResponse->rIxpResult.dwSocketError = 0;
    pResponse->rIxpResult.uiServerError = strtol(pszResponse, &pszResponse, 10);
    pResponse->fDone = (*pszResponse != '-');

    switch (pResponse->rIxpResult.uiServerError)
    {
    case 211: hrServerError = IXP_E_SMTP_211_SYSTEM_STATUS; break;
    case 214: hrServerError = IXP_E_SMTP_214_HELP_MESSAGE; break;
    case 220: hrServerError = IXP_E_SMTP_220_READY; break;
    case 221: hrServerError = IXP_E_SMTP_221_CLOSING; break;
    case 245: hrServerError = IXP_E_SMTP_245_AUTH_SUCCESS; break;
    case 250: hrServerError = IXP_E_SMTP_250_MAIL_ACTION_OKAY; break;
    case 251: hrServerError = IXP_E_SMTP_251_FORWARDING_MAIL; break;
    case 334: hrServerError = IXP_E_SMTP_334_AUTH_READY_RESPONSE; break;
    case 354: hrServerError = IXP_E_SMTP_354_START_MAIL_INPUT; break;
    case 421: hrServerError = IXP_E_SMTP_421_NOT_AVAILABLE; break;
    case 450: hrServerError = IXP_E_SMTP_450_MAILBOX_BUSY; break;
    case 451: hrServerError = IXP_E_SMTP_451_ERROR_PROCESSING; break;
    case 452: hrServerError = IXP_E_SMTP_452_NO_SYSTEM_STORAGE; break;
    case 454: hrServerError = IXP_E_SMTP_454_STARTTLS_FAILED; break;
    case 500: hrServerError = IXP_E_SMTP_500_SYNTAX_ERROR; break;
    case 501: hrServerError = IXP_E_SMTP_501_PARAM_SYNTAX; break;
    case 502: hrServerError = IXP_E_SMTP_502_COMMAND_NOTIMPL; break;
    case 503: hrServerError = IXP_E_SMTP_503_COMMAND_SEQ; break;
    case 504: hrServerError = IXP_E_SMTP_504_COMMAND_PARAM_NOTIMPL; break;
    case 530: hrServerError = IXP_E_SMTP_530_STARTTLS_REQUIRED; break;
    case 550: hrServerError = IXP_E_SMTP_550_MAILBOX_NOT_FOUND; break;
    case 551: hrServerError = IXP_E_SMTP_551_USER_NOT_LOCAL; break;
    case 552: hrServerError = IXP_E_SMTP_552_STORAGE_OVERFLOW; break;
    case 553: hrServerError = IXP_E_SMTP_553_MAILBOX_NAME_SYNTAX; break;
    case 554: hrServerError = IXP_E_SMTP_554_TRANSACT_FAILED; break;
    default:
        hrServerError = IXP_E_SMTP_RESPONSE_ERROR;
        break;
    }
    pResponse->rIxpResult.hrResult = hrServerError;
    pResponse->rIxpResult.hrServerError = hrServerError;

    if (This->InetTransport.pCallback && This->InetTransport.fCommandLogging)
    {
        ITransportCallback_OnCommand(This->InetTransport.pCallback, CMD_RESP,
            pResponse->rIxpResult.pszResponse, hrServerError,
            (IInternetTransport *)&This->InetTransport.u.vtbl);
    }
    return S_OK;
}

__attribute__((used)) static void SMTPTransport_CallbackDoNothing(IInternetTransport *iface, char *pBuffer, int cbBuffer)
{
    TRACE("\n");
}

__attribute__((used)) static void SMTPTransport_CallbackReadResponseDoNothing(IInternetTransport *iface, char *pBuffer, int cbBuffer)
{
    SMTPTransport *This = (SMTPTransport *)iface;

    TRACE("\n");
    InternetTransport_ReadLine(&This->InetTransport, SMTPTransport_CallbackDoNothing);
}

__attribute__((used)) static void SMTPTransport_CallbackProcessDATAResponse(IInternetTransport *iface, char *pBuffer, int cbBuffer)
{
    SMTPTransport *This = (SMTPTransport *)iface;
    SMTPRESPONSE response = { 0 };
    HRESULT hr;

    TRACE("\n");

    hr = SMTPTransport_ParseResponse(This, pBuffer, &response);
    if (FAILED(hr))
    {
        /* FIXME: handle error */
        return;
    }

    response.command = SMTP_DATA;
    ISMTPCallback_OnResponse((ISMTPCallback *)This->InetTransport.pCallback, &response);

    if (FAILED(response.rIxpResult.hrServerError))
    {
        ERR("server error: %s\n", debugstr_a(pBuffer));
        /* FIXME: handle error */
        return;
    }
}

__attribute__((used)) static void SMTPTransport_CallbackReadDATAResponse(IInternetTransport *iface, char *pBuffer, int cbBuffer)
{
    SMTPTransport *This = (SMTPTransport *)iface;

    TRACE("\n");
    InternetTransport_ReadLine(&This->InetTransport, SMTPTransport_CallbackProcessDATAResponse);
}

__attribute__((used)) static void SMTPTransport_CallbackProcessMAILResponse(IInternetTransport *iface, char *pBuffer, int cbBuffer)
{
    SMTPTransport *This = (SMTPTransport *)iface;
    SMTPRESPONSE response = { 0 };
    HRESULT hr;

    TRACE("\n");

    hr = SMTPTransport_ParseResponse(This, pBuffer, &response);
    if (FAILED(hr))
    {
        /* FIXME: handle error */
        return;
    }

    response.command = SMTP_MAIL;
    ISMTPCallback_OnResponse((ISMTPCallback *)This->InetTransport.pCallback, &response);

    if (FAILED(response.rIxpResult.hrServerError))
    {
        ERR("server error: %s\n", debugstr_a(pBuffer));
        /* FIXME: handle error */
        return;
    }
}

__attribute__((used)) static void SMTPTransport_CallbackReadMAILResponse(IInternetTransport *iface, char *pBuffer, int cbBuffer)
{
    SMTPTransport *This = (SMTPTransport *)iface;

    TRACE("\n");
    InternetTransport_ReadLine(&This->InetTransport, SMTPTransport_CallbackProcessMAILResponse);
}

__attribute__((used)) static void SMTPTransport_CallbackProcessRCPTResponse(IInternetTransport *iface, char *pBuffer, int cbBuffer)
{
    SMTPTransport *This = (SMTPTransport *)iface;
    SMTPRESPONSE response = { 0 };
    HRESULT hr;

    TRACE("\n");

    HeapFree(GetProcessHeap(), 0, This->addrlist);
    This->addrlist = NULL;

    hr = SMTPTransport_ParseResponse(This, pBuffer, &response);
    if (FAILED(hr))
    {
        /* FIXME: handle error */
        return;
    }

    response.command = SMTP_RCPT;
    ISMTPCallback_OnResponse((ISMTPCallback *)This->InetTransport.pCallback, &response);

    if (FAILED(response.rIxpResult.hrServerError))
    {
        ERR("server error: %s\n", debugstr_a(pBuffer));
        /* FIXME: handle error */
        return;
    }
}

__attribute__((used)) static void SMTPTransport_CallbackReadRCPTResponse(IInternetTransport *iface, char *pBuffer, int cbBuffer)
{
    SMTPTransport *This = (SMTPTransport *)iface;

    TRACE("\n");
    InternetTransport_ReadLine(&This->InetTransport, SMTPTransport_CallbackProcessRCPTResponse);
}

__attribute__((used)) static void SMTPTransport_CallbackProcessHelloResp(IInternetTransport *iface, char *pBuffer, int cbBuffer)
{
    SMTPTransport *This = (SMTPTransport *)iface;
    SMTPRESPONSE response = { 0 };
    HRESULT hr;

    TRACE("\n");

    hr = SMTPTransport_ParseResponse(This, pBuffer, &response);
    if (FAILED(hr))
    {
        /* FIXME: handle error */
        return;
    }

    response.command = This->fESMTP ? SMTP_EHLO : SMTP_HELO;
    ISMTPCallback_OnResponse((ISMTPCallback *)This->InetTransport.pCallback, &response);

    if (FAILED(response.rIxpResult.hrServerError))
    {
        ERR("server error: %s\n", debugstr_a(pBuffer));
        /* FIXME: handle error */
        return;
    }

    if (!response.fDone)
    {
        InternetTransport_ReadLine(&This->InetTransport,
            SMTPTransport_CallbackProcessHelloResp);
        return;
    }

    /* FIXME: try to authorize */

    /* always changed to this status, even if authorization not support on server */
    InternetTransport_ChangeStatus(&This->InetTransport, IXP_AUTHORIZED);
    InternetTransport_ChangeStatus(&This->InetTransport, IXP_CONNECTED);

    memset(&response, 0, sizeof(response));
    response.command = SMTP_CONNECTED;
    response.fDone = TRUE;
    ISMTPCallback_OnResponse((ISMTPCallback *)This->InetTransport.pCallback, &response);
}

__attribute__((used)) static void SMTPTransport_CallbackRecvHelloResp(IInternetTransport *iface, char *pBuffer, int cbBuffer)
{
    SMTPTransport *This = (SMTPTransport *)iface;

    TRACE("\n");
    InternetTransport_ReadLine(&This->InetTransport, SMTPTransport_CallbackProcessHelloResp);
}

__attribute__((used)) static void SMTPTransport_CallbackSendHello(IInternetTransport *iface, char *pBuffer, int cbBuffer)
{
    SMTPTransport *This = (SMTPTransport *)iface;
    SMTPRESPONSE response = { 0 };
    HRESULT hr;
    const char *pszHello;
    char *pszCommand;
    static const char szHostName[] = "localhost"; /* FIXME */

    TRACE("\n");

    hr = SMTPTransport_ParseResponse(This, pBuffer, &response);
    if (FAILED(hr))
    {
        /* FIXME: handle error */
        return;
    }

    response.command = SMTP_BANNER;
    ISMTPCallback_OnResponse((ISMTPCallback *)This->InetTransport.pCallback, &response);

    if (FAILED(response.rIxpResult.hrServerError))
    {
        ERR("server error: %s\n", debugstr_a(pBuffer));
        /* FIXME: handle error */
        return;
    }

    TRACE("(%s)\n", pBuffer);

    This->fESMTP = strstr(response.rIxpResult.pszResponse, "ESMTP") &&
        This->InetTransport.ServerInfo.dwFlags & (ISF_SSLONSAMEPORT|ISF_QUERYDSNSUPPORT|ISF_QUERYAUTHSUPPORT);

    if (This->fESMTP)
        pszHello = "EHLO ";
    else
        pszHello = "HELO ";

    pszCommand = HeapAlloc(GetProcessHeap(), 0, strlen(pszHello) + strlen(szHostName) + 2);
    strcpy(pszCommand, pszHello);
    strcat(pszCommand, szHostName);
    pszCommand[strlen(pszCommand)+1] = '\0';
    pszCommand[strlen(pszCommand)] = '\n';

    InternetTransport_DoCommand(&This->InetTransport, pszCommand,
        SMTPTransport_CallbackRecvHelloResp);

    HeapFree(GetProcessHeap(), 0, pszCommand);
}

__attribute__((used)) static void SMTPTransport_CallbackDisconnect(IInternetTransport *iface, char *pBuffer, int cbBuffer)
{
    SMTPTransport *This = (SMTPTransport *)iface;
    SMTPRESPONSE response;
    HRESULT hr;

    TRACE("\n");

    if (pBuffer)
    {
        hr = SMTPTransport_ParseResponse(This, pBuffer, &response);
        if (FAILED(hr))
        {
            /* FIXME: handle error */
            return;
        }

        if (FAILED(response.rIxpResult.hrServerError))
        {
            ERR("server error: %s\n", debugstr_a(pBuffer));
            /* FIXME: handle error */
            return;
        }
    }
    InternetTransport_DropConnection(&This->InetTransport);
}

__attribute__((used)) static void SMTPTransport_CallbackMessageProcessResponse(IInternetTransport *iface, char *pBuffer, int cbBuffer)
{
    SMTPTransport *This = (SMTPTransport *)iface;
    SMTPRESPONSE response = { 0 };
    HRESULT hr;

    TRACE("\n");

    hr = SMTPTransport_ParseResponse(This, pBuffer, &response);
    if (FAILED(hr))
    {
        /* FIXME: handle error */
        return;
    }

    if (FAILED(response.rIxpResult.hrServerError))
    {
        ERR("server error: %s\n", debugstr_a(pBuffer));
        /* FIXME: handle error */
        return;
    }

    response.command = SMTP_SEND_MESSAGE;
    response.rIxpResult.hrResult = S_OK;
    ISMTPCallback_OnResponse((ISMTPCallback *)This->InetTransport.pCallback, &response);
}

__attribute__((used)) static void SMTPTransport_CallbackMessageReadResponse(IInternetTransport *iface, char *pBuffer, int cbBuffer)
{
    SMTPTransport *This = (SMTPTransport *)iface;
    InternetTransport_ReadLine(&This->InetTransport, SMTPTransport_CallbackMessageProcessResponse);
}

__attribute__((used)) static void SMTPTransport_CallbackMessageSendDOT(IInternetTransport *iface, char *pBuffer, int cbBuffer)
{
    SMTPTransport *This = (SMTPTransport *)iface;

    IStream_Release(This->pending_message.pstmMsg);
    InternetTransport_DoCommand(&This->InetTransport, "\n.\n",
        SMTPTransport_CallbackMessageReadResponse);
}

__attribute__((used)) static void SMTPTransport_CallbackMessageSendDataStream(IInternetTransport *iface, char *pBuffer, int cbBuffer)
{
    SMTPTransport *This = (SMTPTransport *)iface;
    SMTPRESPONSE response;
    HRESULT hr;
    char *pszBuffer;
    ULONG cbSize;

    TRACE("\n");

    hr = SMTPTransport_ParseResponse(This, pBuffer, &response);
    if (FAILED(hr))
    {
        /* FIXME: handle error */
        return;
    }

    if (FAILED(response.rIxpResult.hrServerError))
    {
        ERR("server error: %s\n", debugstr_a(pBuffer));
        /* FIXME: handle error */
        return;
    }

    pszBuffer = HeapAlloc(GetProcessHeap(), 0, This->pending_message.cbSize);
    hr = IStream_Read(This->pending_message.pstmMsg, pszBuffer, This->pending_message.cbSize, NULL);
    if (FAILED(hr))
    {
        /* FIXME: handle error */
        return;
    }
    cbSize = This->pending_message.cbSize;

    /* FIXME: map "\n.\n" to "\n..\n", reallocate memory, update cbSize */

    /* FIXME: properly stream the message rather than writing it all at once */

    hr = InternetTransport_Write(&This->InetTransport, pszBuffer, cbSize,
        SMTPTransport_CallbackMessageSendDOT);

    HeapFree(GetProcessHeap(), 0, pszBuffer);
}

__attribute__((used)) static void SMTPTransport_CallbackMessageReadDataResponse(IInternetTransport *iface, char *pBuffer, int cbBuffer)
{
    SMTPTransport *This = (SMTPTransport *)iface;

    TRACE("\n");
    InternetTransport_ReadLine(&This->InetTransport, SMTPTransport_CallbackMessageSendDataStream);
}

__attribute__((used)) static void SMTPTransport_CallbackMessageReadToResponse(IInternetTransport *iface, char *pBuffer, int cbBuffer)
{
    SMTPTransport *This = (SMTPTransport *)iface;

    TRACE("\n");
    InternetTransport_ReadLine(&This->InetTransport, SMTPTransport_CallbackMessageSendTo);
}

__attribute__((used)) static void SMTPTransport_CallbackMessageSendTo(IInternetTransport *iface, char *pBuffer, int cbBuffer)
{
    SMTPTransport *This = (SMTPTransport *)iface;
    SMTPRESPONSE response;
    HRESULT hr;

    TRACE("\n");

    hr = SMTPTransport_ParseResponse(This, pBuffer, &response);
    if (FAILED(hr))
    {
        /* FIXME: handle error */
        return;
    }

    if (FAILED(response.rIxpResult.hrServerError))
    {
        ERR("server error: %s\n", debugstr_a(pBuffer));
        /* FIXME: handle error */
        return;
    }

    for (; This->ulCurrentAddressIndex < This->pending_message.rAddressList.cAddress; This->ulCurrentAddressIndex++)
    {
        TRACE("address[%d]: %s\n", This->ulCurrentAddressIndex,
            This->pending_message.rAddressList.prgAddress[This->ulCurrentAddressIndex].szEmail);

        if ((This->pending_message.rAddressList.prgAddress[This->ulCurrentAddressIndex].addrtype & ADDR_TOFROM_MASK) == ADDR_TO)
        {
            static const char szCommandFormat[] = "RCPT TO: <%s>\n";
            char *szCommand;
            int len = sizeof(szCommandFormat) - 2 /* "%s" */ +
                strlen(This->pending_message.rAddressList.prgAddress[This->ulCurrentAddressIndex].szEmail);

            szCommand = HeapAlloc(GetProcessHeap(), 0, len);
            if (!szCommand)
                return;

            sprintf(szCommand, szCommandFormat,
                This->pending_message.rAddressList.prgAddress[This->ulCurrentAddressIndex].szEmail);

            This->ulCurrentAddressIndex++;
            hr = InternetTransport_DoCommand(&This->InetTransport, szCommand,
                SMTPTransport_CallbackMessageReadToResponse);

            HeapFree(GetProcessHeap(), 0, szCommand);
            return;
        }
    }

    hr = InternetTransport_DoCommand(&This->InetTransport, "DATA\n",
        SMTPTransport_CallbackMessageReadDataResponse);
}

__attribute__((used)) static void SMTPTransport_CallbackMessageReadFromResponse(IInternetTransport *iface, char *pBuffer, int cbBuffer)
{
    SMTPTransport *This = (SMTPTransport *)iface;

    TRACE("\n");
    InternetTransport_ReadLine(&This->InetTransport, SMTPTransport_CallbackMessageSendTo);
}

HRESULT SMTPTransportCF_Create(REFIID riid, LPVOID *ppv)
{
    return IClassFactory_QueryInterface((IClassFactory *)&SMTPTransportCF, riid, ppv);
}

