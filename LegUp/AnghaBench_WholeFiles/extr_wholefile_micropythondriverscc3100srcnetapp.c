#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_30__   TYPE_8__ ;
typedef  struct TYPE_29__   TYPE_7__ ;
typedef  struct TYPE_28__   TYPE_6__ ;
typedef  struct TYPE_27__   TYPE_5__ ;
typedef  struct TYPE_26__   TYPE_4__ ;
typedef  struct TYPE_25__   TYPE_3__ ;
typedef  struct TYPE_24__   TYPE_2__ ;
typedef  struct TYPE_23__   TYPE_1__ ;
typedef  struct TYPE_22__   TYPE_16__ ;
typedef  struct TYPE_21__   TYPE_13__ ;
typedef  struct TYPE_20__   TYPE_11__ ;
typedef  struct TYPE_19__   TYPE_10__ ;

/* Type definitions */
typedef  scalar_t__ _u16 ;
struct TYPE_29__ {int /*<<< orphan*/  testTime; int /*<<< orphan*/  rttAvg; int /*<<< orphan*/  rttMax; int /*<<< orphan*/  rttMin; int /*<<< orphan*/  numSuccsessPings; int /*<<< orphan*/  numSendsPings; } ;
typedef  TYPE_7__ _i8 ;
struct TYPE_28__ {int Opcode; } ;
struct TYPE_30__ {TYPE_6__ GenHeader; } ;
typedef  TYPE_8__ _SlResponseHeader_t ;
typedef  TYPE_7__ _PingReportResponse_t ;
struct TYPE_19__ {scalar_t__ TextLen; int /*<<< orphan*/  Status; int /*<<< orphan*/  Port; int /*<<< orphan*/  Address; } ;
typedef  TYPE_10__ _GetHostByServiceIPv4AsyncResponse_t ;
struct TYPE_20__ {scalar_t__* inout_TextLen; int /*<<< orphan*/ * out_pText; int /*<<< orphan*/  Status; int /*<<< orphan*/ * out_pPort; int /*<<< orphan*/ * out_pAddr; } ;
typedef  TYPE_11__ _GetHostByServiceAsyncResponse_t ;
typedef  int /*<<< orphan*/  _GetHostByNameIPv6AsyncResponse_t ;
typedef  TYPE_7__ _GetHostByNameIPv4AsyncResponse_t ;
struct TYPE_26__ {size_t ActionIndex; } ;
struct TYPE_27__ {TYPE_4__ AsyncExt; } ;
struct TYPE_25__ {int AdditionalData; int /*<<< orphan*/  SyncObj; int /*<<< orphan*/ * pRespArgs; } ;
struct TYPE_23__ {int /*<<< orphan*/ * pAsyncRsp; } ;
struct TYPE_24__ {TYPE_1__ PingAsync; } ;
struct TYPE_22__ {TYPE_5__ FunctionParams; TYPE_3__* ObjPool; TYPE_2__ PingCB; } ;
struct TYPE_21__ {int /*<<< orphan*/  TestTime; int /*<<< orphan*/  AvgRoundTime; int /*<<< orphan*/  MaxRoundTime; int /*<<< orphan*/  MinRoundTime; int /*<<< orphan*/  PacketsReceived; int /*<<< orphan*/  PacketsSent; } ;
typedef  TYPE_13__ SlPingReport_t ;

/* Variables and functions */
 int /*<<< orphan*/  DBG_MSG ; 
 int /*<<< orphan*/  MSG_303 ; 
 int /*<<< orphan*/  MSG_305 ; 
 int /*<<< orphan*/  SL_ERROR_TRACE2 (int /*<<< orphan*/ ,char*,int,int) ; 
 int SL_NETAPP_FAMILY_MASK ; 
#define  SL_OPCODE_NETAPP_DNSGETHOSTBYNAMEASYNCRESPONSE 132 
#define  SL_OPCODE_NETAPP_DNSGETHOSTBYNAMEASYNCRESPONSE_V6 131 
#define  SL_OPCODE_NETAPP_MDNSGETHOSTBYSERVICEASYNCRESPONSE 130 
#define  SL_OPCODE_NETAPP_MDNSGETHOSTBYSERVICEASYNCRESPONSE_V6 129 
#define  SL_OPCODE_NETAPP_PINGREPORTREQUESTRESPONSE 128 
 int /*<<< orphan*/  SL_TRACE0 (int /*<<< orphan*/ ,int /*<<< orphan*/ ,char*) ; 
 int /*<<< orphan*/  VERIFY_PROTOCOL (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  VERIFY_SOCKET_CB (int) ; 
 scalar_t__ _SL_RESP_ARGS_START (void*) ; 
 int /*<<< orphan*/  _SlDrvProtectionObjLockWaitForever () ; 
 int /*<<< orphan*/  _SlDrvProtectionObjUnLock () ; 
 int /*<<< orphan*/  _SlDrvSyncObjSignal (int /*<<< orphan*/ *) ; 
 TYPE_16__* g_pCB ; 
 int /*<<< orphan*/  pPingCallBackFunc (TYPE_13__*) ; 
 int /*<<< orphan*/  sl_Memcpy (int /*<<< orphan*/ *,TYPE_7__*,int) ; 

void _sl_HandleAsync_DnsGetHostByService(void *pVoidBuf)
{

	_GetHostByServiceAsyncResponse_t* Res;
	_u16 				  TextLen;
	_u16 				  UserTextLen;


	/*pVoidBuf - is point to opcode of the event.*/
    
	/*set pMsgArgs to point to the attribute of the event.*/
	_GetHostByServiceIPv4AsyncResponse_t   *pMsgArgs   = (_GetHostByServiceIPv4AsyncResponse_t *)_SL_RESP_ARGS_START(pVoidBuf);

    VERIFY_SOCKET_CB(NULL != g_pCB->ObjPool[g_pCB->FunctionParams.AsyncExt.ActionIndex].pRespArgs);

	/*IPv6*/
	if(g_pCB->ObjPool[g_pCB->FunctionParams.AsyncExt.ActionIndex].AdditionalData & SL_NETAPP_FAMILY_MASK)
	{
		return;
	}
	/*IPv4*/
	else
	{
    /*************************************************************************************************
	
	1. Copy the attribute part of the evnt to the attribute part of the response
	sl_Memcpy(g_pCB->GetHostByServiceCB.pAsyncRsp, pMsgArgs, sizeof(_GetHostByServiceIPv4AsyncResponse_t));

    set to TextLen the text length of the service.*/
	TextLen = pMsgArgs->TextLen;
	
	/*Res pointed to mDNS global object struct */
		Res = (_GetHostByServiceAsyncResponse_t*)g_pCB->ObjPool[g_pCB->FunctionParams.AsyncExt.ActionIndex].pRespArgs;



	/*It is 4 bytes so we avoid from memcpy*/
	Res->out_pAddr[0]	= pMsgArgs->Address;
	Res->out_pPort[0]	= pMsgArgs->Port;
	Res->Status			= pMsgArgs->Status;
	
	/*set to TextLen the text length of the user (input fromthe user).*/
	UserTextLen			= Res->inout_TextLen[0];
    
	/*Cut the service text if the user requested for smaller text.*/
	UserTextLen = (TextLen <= UserTextLen) ? TextLen : UserTextLen;
	Res->inout_TextLen[0] = UserTextLen ;

    /**************************************************************************************************

	2. Copy the payload part of the evnt (the text) to the payload part of the response
	the lenght of the copy is according to the text length in the attribute part. */
	

	sl_Memcpy(Res->out_pText          ,
		     (_i8 *)(& pMsgArgs[1])  ,   /* & pMsgArgs[1] -> 1st byte after the fixed header = 1st byte of variable text.*/
			 UserTextLen              );


    /**************************************************************************************************/

		_SlDrvSyncObjSignal(&g_pCB->ObjPool[g_pCB->FunctionParams.AsyncExt.ActionIndex].SyncObj);
		return;
	}
}

void _sl_HandleAsync_DnsGetHostByAddr(void *pVoidBuf)
{
    SL_TRACE0(DBG_MSG, MSG_303, "STUB: _sl_HandleAsync_DnsGetHostByAddr not implemented yet!");
    return;
}

void _sl_HandleAsync_DnsGetHostByName(void *pVoidBuf)
{
    _GetHostByNameIPv4AsyncResponse_t     *pMsgArgs   = (_GetHostByNameIPv4AsyncResponse_t *)_SL_RESP_ARGS_START(pVoidBuf);

   _SlDrvProtectionObjLockWaitForever();

    VERIFY_SOCKET_CB(NULL != g_pCB->ObjPool[g_pCB->FunctionParams.AsyncExt.ActionIndex].pRespArgs);

	/*IPv6 */
	if(g_pCB->ObjPool[g_pCB->FunctionParams.AsyncExt.ActionIndex].AdditionalData & SL_NETAPP_FAMILY_MASK)
	{
		sl_Memcpy(g_pCB->ObjPool[g_pCB->FunctionParams.AsyncExt.ActionIndex].pRespArgs, pMsgArgs, sizeof(_GetHostByNameIPv6AsyncResponse_t));
	}
	/*IPv4 */
	else
	{
		sl_Memcpy(g_pCB->ObjPool[g_pCB->FunctionParams.AsyncExt.ActionIndex].pRespArgs, pMsgArgs, sizeof(_GetHostByNameIPv4AsyncResponse_t));
	}
	_SlDrvSyncObjSignal(&g_pCB->ObjPool[g_pCB->FunctionParams.AsyncExt.ActionIndex].SyncObj);
    _SlDrvProtectionObjUnLock();
    return;
}

void CopyPingResultsToReport(_PingReportResponse_t *pResults,SlPingReport_t *pReport)
{
    pReport->PacketsSent     = pResults->numSendsPings;
    pReport->PacketsReceived = pResults->numSuccsessPings;
    pReport->MinRoundTime    = pResults->rttMin;
    pReport->MaxRoundTime    = pResults->rttMax;
    pReport->AvgRoundTime    = pResults->rttAvg;
    pReport->TestTime        = pResults->testTime;
}

void _sl_HandleAsync_PingResponse(void *pVoidBuf)
{
    _PingReportResponse_t     *pMsgArgs   = (_PingReportResponse_t *)_SL_RESP_ARGS_START(pVoidBuf);
    SlPingReport_t            pingReport;
    
    if(pPingCallBackFunc)
    {
        CopyPingResultsToReport(pMsgArgs,&pingReport);
        pPingCallBackFunc(&pingReport);
    }
    else
    {
       
        _SlDrvProtectionObjLockWaitForever();
        
        VERIFY_SOCKET_CB(NULL != g_pCB->PingCB.PingAsync.pAsyncRsp);

		if (NULL != g_pCB->ObjPool[g_pCB->FunctionParams.AsyncExt.ActionIndex].pRespArgs)
		{
		   sl_Memcpy(g_pCB->ObjPool[g_pCB->FunctionParams.AsyncExt.ActionIndex].pRespArgs, pMsgArgs, sizeof(_PingReportResponse_t));
		   _SlDrvSyncObjSignal(&g_pCB->ObjPool[g_pCB->FunctionParams.AsyncExt.ActionIndex].SyncObj);
		}
       _SlDrvProtectionObjUnLock();
    }
    return;
}

void _SlDrvNetAppEventHandler(void* pArgs)
{
    _SlResponseHeader_t     *pHdr       = (_SlResponseHeader_t *)pArgs;
#if defined(sl_HttpServerCallback) || defined(EXT_LIB_REGISTERED_HTTP_SERVER_EVENTS)
    SlHttpServerEvent_t		httpServerEvent;
    SlHttpServerResponse_t	httpServerResponse;
#endif
    
    switch(pHdr->GenHeader.Opcode)
    {
        case SL_OPCODE_NETAPP_DNSGETHOSTBYNAMEASYNCRESPONSE:
        case SL_OPCODE_NETAPP_DNSGETHOSTBYNAMEASYNCRESPONSE_V6:
            _sl_HandleAsync_DnsGetHostByName(pArgs);
            break;
#ifndef SL_TINY_EXT            
        case SL_OPCODE_NETAPP_MDNSGETHOSTBYSERVICEASYNCRESPONSE:
        case SL_OPCODE_NETAPP_MDNSGETHOSTBYSERVICEASYNCRESPONSE_V6:
            _sl_HandleAsync_DnsGetHostByService(pArgs);
            break;
        case SL_OPCODE_NETAPP_PINGREPORTREQUESTRESPONSE:
            _sl_HandleAsync_PingResponse(pArgs);
            break;
#endif

#if defined(sl_HttpServerCallback) || defined(EXT_LIB_REGISTERED_HTTP_SERVER_EVENTS)
		case SL_OPCODE_NETAPP_HTTPGETTOKENVALUE:
		{              
			_u8 *pTokenName;
			slHttpServerData_t Token_value;
			sl_NetAppHttpServerGetToken_t *httpGetToken = (sl_NetAppHttpServerGetToken_t *)_SL_RESP_ARGS_START(pHdr);
                        pTokenName = (_u8 *)((sl_NetAppHttpServerGetToken_t *)httpGetToken + 1);

			httpServerResponse.Response = SL_NETAPP_HTTPSETTOKENVALUE;
			httpServerResponse.ResponseData.token_value.len = MAX_TOKEN_VALUE_LEN;

            /* Reuse the async buffer for getting the token value response from the user */
			httpServerResponse.ResponseData.token_value.data = (_u8 *)_SL_RESP_ARGS_START(pHdr) + MAX_TOKEN_NAME_LEN;

            httpServerEvent.Event = SL_NETAPP_HTTPGETTOKENVALUE_EVENT;
			httpServerEvent.EventData.httpTokenName.len = httpGetToken->token_name_len;
			httpServerEvent.EventData.httpTokenName.data = pTokenName;

			Token_value.token_name =  pTokenName;

            _SlDrvHandleHttpServerEvents (&httpServerEvent, &httpServerResponse);			

			Token_value.value_len = httpServerResponse.ResponseData.token_value.len;
			Token_value.name_len = httpServerEvent.EventData.httpTokenName.len;
			Token_value.token_value = httpServerResponse.ResponseData.token_value.data;
			    

			_sl_NetAppSendTokenValue(&Token_value);
		}
		break;

		case SL_OPCODE_NETAPP_HTTPPOSTTOKENVALUE:
		{
			_u8 *pPostParams;

			sl_NetAppHttpServerPostToken_t *httpPostTokenArgs = (sl_NetAppHttpServerPostToken_t *)_SL_RESP_ARGS_START(pHdr);
			pPostParams = (_u8 *)((sl_NetAppHttpServerPostToken_t *)httpPostTokenArgs + 1);

			httpServerEvent.Event = SL_NETAPP_HTTPPOSTTOKENVALUE_EVENT;

			httpServerEvent.EventData.httpPostData.action.len = httpPostTokenArgs->post_action_len;
			httpServerEvent.EventData.httpPostData.action.data = pPostParams;
			pPostParams+=httpPostTokenArgs->post_action_len;

			httpServerEvent.EventData.httpPostData.token_name.len = httpPostTokenArgs->token_name_len;
			httpServerEvent.EventData.httpPostData.token_name.data = pPostParams;
			pPostParams+=httpPostTokenArgs->token_name_len;

			httpServerEvent.EventData.httpPostData.token_value.len = httpPostTokenArgs->token_value_len;
			httpServerEvent.EventData.httpPostData.token_value.data = pPostParams;

			httpServerResponse.Response = SL_NETAPP_RESPONSE_NONE;

            _SlDrvHandleHttpServerEvents (&httpServerEvent, &httpServerResponse);
			
		}
		break;
#endif

        
        default:
            SL_ERROR_TRACE2(MSG_305, "ASSERT: _SlDrvNetAppEventHandler : invalid opcode = 0x%x = %1", pHdr->GenHeader.Opcode, pHdr->GenHeader.Opcode);
            VERIFY_PROTOCOL(0);
    }
}

