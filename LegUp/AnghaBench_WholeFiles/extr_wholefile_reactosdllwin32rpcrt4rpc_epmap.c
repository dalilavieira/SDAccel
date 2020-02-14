#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_47__   TYPE_4__ ;
typedef  struct TYPE_46__   TYPE_3__ ;
typedef  struct TYPE_45__   TYPE_37__ ;
typedef  struct TYPE_44__   TYPE_2__ ;
typedef  struct TYPE_43__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  status ;
typedef  enum secure_packet_direction { ____Placeholder_secure_packet_direction } secure_packet_direction ;
typedef  char WCHAR ;
typedef  int ULONGLONG ;
typedef  int /*<<< orphan*/  ULONG ;
struct TYPE_47__ {char* Protseq; char* NetworkAddr; int /*<<< orphan*/ * AuthInfo; scalar_t__ server; } ;
struct TYPE_46__ {TYPE_1__* ops; } ;
struct TYPE_45__ {char* protseq; char* endpoint; } ;
struct TYPE_44__ {scalar_t__ dwCurrentState; } ;
struct TYPE_43__ {char const* name; int (* read ) (TYPE_3__*,void*,unsigned int) ;int (* write ) (TYPE_3__*,void const*,unsigned int) ;int (* close ) (TYPE_3__*) ;scalar_t__ (* handoff ) (TYPE_3__*,TYPE_3__*) ;int (* is_authorized ) (TYPE_3__*) ;scalar_t__ (* authorize ) (TYPE_3__*,int,unsigned char*,unsigned int,unsigned char*,unsigned int*) ;scalar_t__ (* secure_packet ) (TYPE_3__*,int,int /*<<< orphan*/ *,unsigned int,unsigned char*,unsigned int,int /*<<< orphan*/ *,unsigned char*,unsigned int) ;scalar_t__ (* impersonate_client ) (TYPE_3__*) ;scalar_t__ (* revert_to_self ) (TYPE_3__*) ;scalar_t__ (* inquire_auth_client ) (TYPE_3__*,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ;int /*<<< orphan*/  (* cancel_call ) (TYPE_3__*) ;int /*<<< orphan*/  (* close_read ) (TYPE_3__*) ;} ;
typedef  TYPE_2__ SERVICE_STATUS_PROCESS ;
typedef  int /*<<< orphan*/  SC_HANDLE ;
typedef  int /*<<< orphan*/  RpcPktHdr ;
typedef  TYPE_3__ RpcConnection ;
typedef  TYPE_4__ RpcBinding ;
typedef  int /*<<< orphan*/  RpcAuthVerifier ;
typedef  int /*<<< orphan*/  RPC_WSTR ;
typedef  scalar_t__ RPC_STATUS ;
typedef  TYPE_4__* RPC_BINDING_HANDLE ;
typedef  int /*<<< orphan*/  RPC_AUTHZ_HANDLE ;
typedef  int /*<<< orphan*/  DWORD ;
typedef  int /*<<< orphan*/  BYTE ;
typedef  int BOOL ;

/* Variables and functions */
 unsigned int ARRAY_SIZE (TYPE_37__*) ; 
 int /*<<< orphan*/  CloseServiceHandle (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ERR (char*) ; 
 scalar_t__ ERROR_SERVICE_ALREADY_RUNNING ; 
 int FALSE ; 
 int /*<<< orphan*/  FIXME (char*,int /*<<< orphan*/ ) ; 
 scalar_t__ GetLastError () ; 
 int GetTickCount64 () ; 
 int /*<<< orphan*/  OpenSCManagerW (int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  OpenServiceW (int /*<<< orphan*/ ,char const*,int) ; 
 int /*<<< orphan*/  QueryServiceStatusEx (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ *,int,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  RPCRT4_ResolveBinding (TYPE_4__*,char const*) ; 
 scalar_t__ RPC_S_INVALID_BINDING ; 
 scalar_t__ RPC_S_OK ; 
 scalar_t__ RPC_S_PROTSEQ_NOT_SUPPORTED ; 
 int /*<<< orphan*/  RpcAuthInfo_Release (int /*<<< orphan*/ *) ; 
 scalar_t__ RpcBindingCopy (TYPE_4__*,TYPE_4__**) ; 
 scalar_t__ RpcBindingFromStringBindingA (unsigned char*,TYPE_4__**) ; 
 int /*<<< orphan*/  SC_STATUS_PROCESS_INFO ; 
 int SERVICE_QUERY_STATUS ; 
 scalar_t__ SERVICE_RUNNING ; 
 int SERVICE_START ; 
 scalar_t__ SERVICE_START_PENDING ; 
 int /*<<< orphan*/  Sleep (int) ; 
 scalar_t__ StartServiceW (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  TRACE (char*) ; 
 int TRUE ; 
 int /*<<< orphan*/  WARN (char*,scalar_t__) ; 
 int /*<<< orphan*/  debugstr_a (char const*) ; 
 TYPE_37__* epm_endpoints ; 
 int /*<<< orphan*/  strcmp (char const*,char*) ; 
 int stub1 (TYPE_3__*,void*,unsigned int) ; 
 scalar_t__ stub10 (TYPE_3__*) ; 
 scalar_t__ stub11 (TYPE_3__*) ; 
 scalar_t__ stub12 (TYPE_3__*,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int stub2 (TYPE_3__*,void const*,unsigned int) ; 
 int stub3 (TYPE_3__*) ; 
 int /*<<< orphan*/  stub4 (TYPE_3__*) ; 
 int /*<<< orphan*/  stub5 (TYPE_3__*) ; 
 scalar_t__ stub6 (TYPE_3__*,TYPE_3__*) ; 
 int stub7 (TYPE_3__*) ; 
 scalar_t__ stub8 (TYPE_3__*,int,unsigned char*,unsigned int,unsigned char*,unsigned int*) ; 
 scalar_t__ stub9 (TYPE_3__*,int,int /*<<< orphan*/ *,unsigned int,unsigned char*,unsigned int,int /*<<< orphan*/ *,unsigned char*,unsigned int) ; 

__attribute__((used)) static inline const char *rpcrt4_conn_get_name(const RpcConnection *Connection)
{
  return Connection->ops->name;
}

__attribute__((used)) static inline int rpcrt4_conn_read(RpcConnection *Connection,
                     void *buffer, unsigned int len)
{
  return Connection->ops->read(Connection, buffer, len);
}

__attribute__((used)) static inline int rpcrt4_conn_write(RpcConnection *Connection,
                     const void *buffer, unsigned int len)
{
  return Connection->ops->write(Connection, buffer, len);
}

__attribute__((used)) static inline int rpcrt4_conn_close(RpcConnection *Connection)
{
  return Connection->ops->close(Connection);
}

__attribute__((used)) static inline void rpcrt4_conn_close_read(RpcConnection *connection)
{
  connection->ops->close_read(connection);
}

__attribute__((used)) static inline void rpcrt4_conn_cancel_call(RpcConnection *Connection)
{
  Connection->ops->cancel_call(Connection);
}

__attribute__((used)) static inline RPC_STATUS rpcrt4_conn_handoff(RpcConnection *old_conn, RpcConnection *new_conn)
{
  return old_conn->ops->handoff(old_conn, new_conn);
}

__attribute__((used)) static inline BOOL rpcrt4_conn_is_authorized(RpcConnection *Connection)
{
    return Connection->ops->is_authorized(Connection);
}

__attribute__((used)) static inline RPC_STATUS rpcrt4_conn_authorize(
    RpcConnection *conn, BOOL first_time, unsigned char *in_buffer,
    unsigned int in_len, unsigned char *out_buffer, unsigned int *out_len)
{
    return conn->ops->authorize(conn, first_time, in_buffer, in_len, out_buffer, out_len);
}

__attribute__((used)) static inline RPC_STATUS rpcrt4_conn_secure_packet(
    RpcConnection *conn, enum secure_packet_direction dir,
    RpcPktHdr *hdr, unsigned int hdr_size, unsigned char *stub_data,
    unsigned int stub_data_size, RpcAuthVerifier *auth_hdr,
    unsigned char *auth_value, unsigned int auth_value_size)
{
    return conn->ops->secure_packet(conn, dir, hdr, hdr_size, stub_data, stub_data_size, auth_hdr, auth_value, auth_value_size);
}

__attribute__((used)) static inline RPC_STATUS rpcrt4_conn_impersonate_client(
    RpcConnection *conn)
{
    return conn->ops->impersonate_client(conn);
}

__attribute__((used)) static inline RPC_STATUS rpcrt4_conn_revert_to_self(
    RpcConnection *conn)
{
    return conn->ops->revert_to_self(conn);
}

__attribute__((used)) static inline RPC_STATUS rpcrt4_conn_inquire_auth_client(
    RpcConnection *conn, RPC_AUTHZ_HANDLE *privs, RPC_WSTR *server_princ_name,
    ULONG *authn_level, ULONG *authn_svc, ULONG *authz_svc, ULONG flags)
{
    return conn->ops->inquire_auth_client(conn, privs, server_princ_name, authn_level, authn_svc, authz_svc, flags);
}

__attribute__((used)) static BOOL start_rpcss(void)
{
    static const WCHAR rpcssW[] = {'R','p','c','S','s',0};
    SC_HANDLE scm, service;
    SERVICE_STATUS_PROCESS status;
    BOOL ret = FALSE;

    TRACE("\n");

    if (!(scm = OpenSCManagerW( NULL, NULL, 0 )))
    {
        ERR( "failed to open service manager\n" );
        return FALSE;
    }
    if (!(service = OpenServiceW( scm, rpcssW, SERVICE_START | SERVICE_QUERY_STATUS )))
    {
        ERR( "failed to open RpcSs service\n" );
        CloseServiceHandle( scm );
        return FALSE;
    }
    if (StartServiceW( service, 0, NULL ) || GetLastError() == ERROR_SERVICE_ALREADY_RUNNING)
    {
        ULONGLONG start_time = GetTickCount64();
        do
        {
            DWORD dummy;

            if (!QueryServiceStatusEx( service, SC_STATUS_PROCESS_INFO,
                                       (BYTE *)&status, sizeof(status), &dummy ))
                break;
            if (status.dwCurrentState == SERVICE_RUNNING)
            {
                ret = TRUE;
                break;
            }
            if (GetTickCount64() - start_time > 30000) break;
            Sleep( 100 );

        } while (status.dwCurrentState == SERVICE_START_PENDING);

        if (status.dwCurrentState != SERVICE_RUNNING)
            WARN( "RpcSs failed to start %u\n", status.dwCurrentState );
    }
    else ERR( "failed to start RpcSs service\n" );

    CloseServiceHandle( service );
    CloseServiceHandle( scm );
    return ret;
}

__attribute__((used)) static inline BOOL is_epm_destination_local(RPC_BINDING_HANDLE handle)
{
    RpcBinding *bind = handle;
    const char *protseq = bind->Protseq;
    const char *network_addr = bind->NetworkAddr;

    return (!strcmp(protseq, "ncalrpc") ||
           (!strcmp(protseq, "ncacn_np") &&
                (!network_addr || !strcmp(network_addr, "."))));
}

__attribute__((used)) static RPC_STATUS get_epm_handle_client(RPC_BINDING_HANDLE handle, RPC_BINDING_HANDLE *epm_handle)
{
    RpcBinding *bind = handle;
    const char * pszEndpoint = NULL;
    RPC_STATUS status;
    RpcBinding* epm_bind;
    unsigned int i;

    if (bind->server)
        return RPC_S_INVALID_BINDING;

    for (i = 0; i < ARRAY_SIZE(epm_endpoints); i++)
        if (!strcmp(bind->Protseq, epm_endpoints[i].protseq))
            pszEndpoint = epm_endpoints[i].endpoint;

    if (!pszEndpoint)
    {
        FIXME("no endpoint for the endpoint-mapper found for protseq %s\n", debugstr_a(bind->Protseq));
        return RPC_S_PROTSEQ_NOT_SUPPORTED;
    }

    status = RpcBindingCopy(handle, epm_handle);
    if (status != RPC_S_OK) return status;

    epm_bind = *epm_handle;
    if (epm_bind->AuthInfo)
    {
        /* don't bother with authenticating against the EPM by default
        * (see EnableAuthEpResolution registry value) */
        RpcAuthInfo_Release(epm_bind->AuthInfo);
        epm_bind->AuthInfo = NULL;
    }
    RPCRT4_ResolveBinding(epm_bind, pszEndpoint);
    TRACE("RPC_S_OK\n");
    return RPC_S_OK;
}

__attribute__((used)) static RPC_STATUS get_epm_handle_server(RPC_BINDING_HANDLE *epm_handle)
{
    unsigned char string_binding[] = "ncacn_np:.[\\\\pipe\\\\epmapper]";

    return RpcBindingFromStringBindingA(string_binding, epm_handle);
}

