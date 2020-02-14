#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_41__   TYPE_9__ ;
typedef  struct TYPE_40__   TYPE_8__ ;
typedef  struct TYPE_39__   TYPE_7__ ;
typedef  struct TYPE_38__   TYPE_6__ ;
typedef  struct TYPE_37__   TYPE_5__ ;
typedef  struct TYPE_36__   TYPE_4__ ;
typedef  struct TYPE_35__   TYPE_3__ ;
typedef  struct TYPE_34__   TYPE_2__ ;
typedef  struct TYPE_33__   TYPE_20__ ;
typedef  struct TYPE_32__   TYPE_1__ ;
typedef  struct TYPE_31__   TYPE_17__ ;
typedef  struct TYPE_30__   TYPE_16__ ;
typedef  struct TYPE_29__   TYPE_15__ ;
typedef  struct TYPE_28__   TYPE_13__ ;
typedef  struct TYPE_27__   TYPE_12__ ;
typedef  struct TYPE_26__   TYPE_11__ ;
typedef  struct TYPE_25__   TYPE_10__ ;

/* Type definitions */
typedef  int _u32 ;
typedef  unsigned int _u16 ;
typedef  int _i8 ;
typedef  int _i16 ;
struct TYPE_26__ {int sd; int /*<<< orphan*/  statusOrLen; } ;
typedef  TYPE_11__ _SocketResponse_t ;
struct TYPE_36__ {int family; int sd; int /*<<< orphan*/  address; int /*<<< orphan*/  port; } ;
struct TYPE_39__ {TYPE_12__* address; } ;
struct TYPE_27__ {TYPE_4__ IpV4; TYPE_7__ IpV6EUI48; } ;
typedef  TYPE_12__ _SocketAddrResponse_u ;
struct TYPE_34__ {TYPE_12__* address; } ;
struct TYPE_32__ {int FamilyAndFlags; int /*<<< orphan*/  address; int /*<<< orphan*/  port; } ;
struct TYPE_28__ {TYPE_2__ IpV6EUI48; TYPE_1__ IpV4; } ;
typedef  TYPE_13__ _SocketAddrCommand_u ;
typedef  TYPE_12__ _SelectAsyncResponse_t ;
struct TYPE_41__ {size_t ActionIndex; } ;
struct TYPE_40__ {int /*<<< orphan*/  SyncObj; TYPE_12__* pRespArgs; } ;
struct TYPE_37__ {TYPE_12__* _S6_u8; } ;
struct TYPE_38__ {TYPE_5__ _S6_un; } ;
struct TYPE_35__ {int /*<<< orphan*/  s_addr; } ;
struct TYPE_25__ {TYPE_9__ AsyncExt; } ;
struct TYPE_33__ {TYPE_10__ FunctionParams; TYPE_8__* ObjPool; } ;
struct TYPE_31__ {TYPE_6__ sin6_addr; } ;
struct TYPE_30__ {TYPE_3__ sin_addr; int /*<<< orphan*/  sin_port; } ;
struct TYPE_29__ {int sa_family; } ;
typedef  int SlSocklen_t ;
typedef  TYPE_15__ SlSockAddr_t ;
typedef  TYPE_16__ SlSockAddrIn_t ;
typedef  TYPE_17__ SlSockAddrIn6_t ;

/* Variables and functions */
 int BSD_SOCKET_ID_MASK ; 
 int SL_AF_INET ; 
 int SL_AF_INET6_EUI_48 ; 
 int SL_MAX_SOCKETS ; 
 unsigned int SL_SOCKET_PAYLOAD_BASE ; 
 int const SL_SOCKET_PAYLOAD_TYPE_MASK ; 
 int /*<<< orphan*/  VERIFY_PROTOCOL (int) ; 
 int /*<<< orphan*/  VERIFY_SOCKET_CB (int) ; 
 scalar_t__ _SL_RESP_ARGS_START (void*) ; 
 int /*<<< orphan*/  _SlDrvProtectionObjLockWaitForever () ; 
 int /*<<< orphan*/  _SlDrvProtectionObjUnLock () ; 
 int /*<<< orphan*/  _SlDrvSyncObjSignal (int /*<<< orphan*/ *) ; 
 unsigned int* _SlPayloadByProtocolLUT ; 
 TYPE_20__* g_pCB ; 
 int /*<<< orphan*/  sl_Memcpy (TYPE_12__*,TYPE_12__*,int) ; 

void _sl_BuildAddress(const SlSockAddr_t *addr, _SocketAddrCommand_u    *pCmd)
{

    /* Note: parsing of family and port in the generic way for all IPV4, IPV6 and EUI48
           is possible as long as these parameters are in the same offset and size for these
           three families. */
    pCmd->IpV4.FamilyAndFlags = (addr->sa_family << 4) & 0xF0;
    pCmd->IpV4.port = ((SlSockAddrIn_t *)addr)->sin_port;

    if(SL_AF_INET == addr->sa_family)
    {
        pCmd->IpV4.address  = ((SlSockAddrIn_t *)addr)->sin_addr.s_addr;
    }
    else if (SL_AF_INET6_EUI_48 == addr->sa_family )
    {
        sl_Memcpy( pCmd->IpV6EUI48.address,((SlSockAddrIn6_t *)addr)->sin6_addr._S6_un._S6_u8, 6);
    }
#ifdef SL_SUPPORT_IPV6
    else
    {
        sl_Memcpy(pCmd->IpV6.address, ((sockaddr_in6 *)addr)->sin6_addr._S6_un._S6_u32, 16 );
    }
#endif
}

_u16 _sl_TruncatePayloadByProtocol(const _i16 sd, const _u16 length)
{
   unsigned int maxLength;


   maxLength = SL_SOCKET_PAYLOAD_BASE + _SlPayloadByProtocolLUT[((sd & SL_SOCKET_PAYLOAD_TYPE_MASK) >> 4)];



   if( length > maxLength )
   {
      return maxLength;
   }
   else
   {
      return length;
   }
}

void _sl_ParseAddress(_SocketAddrResponse_u    *pRsp, SlSockAddr_t *addr, SlSocklen_t *addrlen)
{
    /*  Note: parsing of family and port in the generic way for all IPV4, IPV6 and EUI48 */
    /*  is possible as long as these parameters are in the same offset and size for these */
    /*  three families. */
    addr->sa_family                 = pRsp->IpV4.family;
    ((SlSockAddrIn_t *)addr)->sin_port = pRsp->IpV4.port;

    *addrlen = (SL_AF_INET == addr->sa_family) ? sizeof(SlSockAddrIn_t) : sizeof(SlSockAddrIn6_t);

    if(SL_AF_INET == addr->sa_family)
    {
        ((SlSockAddrIn_t *)addr)->sin_addr.s_addr  = pRsp->IpV4.address;
    }
    else if (SL_AF_INET6_EUI_48 == addr->sa_family )
    {
        sl_Memcpy(((SlSockAddrIn6_t *)addr)->sin6_addr._S6_un._S6_u8, pRsp->IpV6EUI48.address, 6);
    }
#ifdef SL_SUPPORT_IPV6
    else
    {
        sl_Memcpy(((sockaddr_in6 *)addr)->sin6_addr._S6_un._S6_u32, pRsp->IpV6.address, 16);
    }
#endif
}

void _sl_HandleAsync_Connect(void *pVoidBuf)
{
    _SocketResponse_t          *pMsgArgs   = (_SocketResponse_t *)_SL_RESP_ARGS_START(pVoidBuf);

    _SlDrvProtectionObjLockWaitForever();

    VERIFY_PROTOCOL((pMsgArgs->sd & BSD_SOCKET_ID_MASK) <= SL_MAX_SOCKETS);
    VERIFY_SOCKET_CB(NULL != g_pCB->ObjPool[g_pCB->FunctionParams.AsyncExt.ActionIndex].pRespArgs);
    

    ((_SocketResponse_t *)(g_pCB->ObjPool[g_pCB->FunctionParams.AsyncExt.ActionIndex].pRespArgs))->sd = pMsgArgs->sd;
    ((_SocketResponse_t *)(g_pCB->ObjPool[g_pCB->FunctionParams.AsyncExt.ActionIndex].pRespArgs))->statusOrLen = pMsgArgs->statusOrLen;


    _SlDrvSyncObjSignal(&g_pCB->ObjPool[g_pCB->FunctionParams.AsyncExt.ActionIndex].SyncObj);
    _SlDrvProtectionObjUnLock();
    return;
}

_u32 sl_Htonl( _u32 val )
{
  _u32 i = 1; 
  _i8 *p = (_i8 *)&i;  
  if (p[0] == 1) /* little endian */
  {
    p[0] = ((_i8* )&val)[3];
    p[1] = ((_i8* )&val)[2];
    p[2] = ((_i8* )&val)[1];
    p[3] = ((_i8* )&val)[0];
    return i;
  }
  else /* big endian */
  {
    return val; 
  }
}

_u16 sl_Htons( _u16 val )
{
  _i16 i = 1; 
  _i8 *p = (_i8 *)&i;  
  if (p[0] == 1) /* little endian */
  {
    p[0] = ((_i8* )&val)[1];
    p[1] = ((_i8* )&val)[0];
    return i;
  }
  else /* big endian */
  {
    return val; 
  }
}

void _sl_HandleAsync_Accept(void *pVoidBuf)
{
    _SocketAddrResponse_u      *pMsgArgs   = (_SocketAddrResponse_u *)_SL_RESP_ARGS_START(pVoidBuf);

    _SlDrvProtectionObjLockWaitForever();

    VERIFY_PROTOCOL(( pMsgArgs->IpV4.sd & BSD_SOCKET_ID_MASK) <= SL_MAX_SOCKETS);
    VERIFY_SOCKET_CB(NULL != g_pCB->ObjPool[g_pCB->FunctionParams.AsyncExt.ActionIndex].pRespArgs);

	sl_Memcpy(g_pCB->ObjPool[g_pCB->FunctionParams.AsyncExt.ActionIndex].pRespArgs, pMsgArgs,sizeof(_SocketAddrResponse_u));
	_SlDrvSyncObjSignal(&g_pCB->ObjPool[g_pCB->FunctionParams.AsyncExt.ActionIndex].SyncObj);

    _SlDrvProtectionObjUnLock();
    return;
}

void _sl_HandleAsync_Select(void *pVoidBuf)
{
    _SelectAsyncResponse_t     *pMsgArgs   = (_SelectAsyncResponse_t *)_SL_RESP_ARGS_START(pVoidBuf);

    _SlDrvProtectionObjLockWaitForever();    

    VERIFY_SOCKET_CB(NULL != g_pCB->ObjPool[g_pCB->FunctionParams.AsyncExt.ActionIndex].pRespArgs);

    sl_Memcpy(g_pCB->ObjPool[g_pCB->FunctionParams.AsyncExt.ActionIndex].pRespArgs, pMsgArgs, sizeof(_SelectAsyncResponse_t));

    _SlDrvSyncObjSignal(&g_pCB->ObjPool[g_pCB->FunctionParams.AsyncExt.ActionIndex].SyncObj);
    _SlDrvProtectionObjUnLock();

    return;
}

