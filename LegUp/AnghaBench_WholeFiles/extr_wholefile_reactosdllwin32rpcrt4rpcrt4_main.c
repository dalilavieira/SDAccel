#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_31__   TYPE_2__ ;
typedef  struct TYPE_30__   TYPE_1__ ;

/* Type definitions */
typedef  enum secure_packet_direction { ____Placeholder_secure_packet_direction } secure_packet_direction ;
typedef  int /*<<< orphan*/  ULONG ;
struct TYPE_31__ {TYPE_1__* ops; } ;
struct TYPE_30__ {char const* name; int (* read ) (TYPE_2__*,void*,unsigned int) ;int (* write ) (TYPE_2__*,void const*,unsigned int) ;int (* close ) (TYPE_2__*) ;int /*<<< orphan*/  (* inquire_auth_client ) (TYPE_2__*,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ;int /*<<< orphan*/  (* revert_to_self ) (TYPE_2__*) ;int /*<<< orphan*/  (* impersonate_client ) (TYPE_2__*) ;int /*<<< orphan*/  (* secure_packet ) (TYPE_2__*,int,int /*<<< orphan*/ *,unsigned int,unsigned char*,unsigned int,int /*<<< orphan*/ *,unsigned char*,unsigned int) ;int /*<<< orphan*/  (* authorize ) (TYPE_2__*,int /*<<< orphan*/ ,unsigned char*,unsigned int,unsigned char*,unsigned int*) ;int /*<<< orphan*/  (* is_authorized ) (TYPE_2__*) ;int /*<<< orphan*/  (* handoff ) (TYPE_2__*,TYPE_2__*) ;int /*<<< orphan*/  (* cancel_call ) (TYPE_2__*) ;int /*<<< orphan*/  (* close_read ) (TYPE_2__*) ;} ;
typedef  int /*<<< orphan*/  RpcPktHdr ;
typedef  TYPE_2__ RpcConnection ;
typedef  int /*<<< orphan*/  RpcAuthVerifier ;
typedef  int /*<<< orphan*/  RPC_WSTR ;
typedef  int /*<<< orphan*/  RPC_STATUS ;
typedef  int /*<<< orphan*/  RPC_AUTHZ_HANDLE ;
typedef  int /*<<< orphan*/  BOOL ;

/* Variables and functions */
 int stub1 (TYPE_2__*,void*,unsigned int) ; 
 int /*<<< orphan*/  stub10 (TYPE_2__*) ; 
 int /*<<< orphan*/  stub11 (TYPE_2__*) ; 
 int /*<<< orphan*/  stub12 (TYPE_2__*,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int stub2 (TYPE_2__*,void const*,unsigned int) ; 
 int stub3 (TYPE_2__*) ; 
 int /*<<< orphan*/  stub4 (TYPE_2__*) ; 
 int /*<<< orphan*/  stub5 (TYPE_2__*) ; 
 int /*<<< orphan*/  stub6 (TYPE_2__*,TYPE_2__*) ; 
 int /*<<< orphan*/  stub7 (TYPE_2__*) ; 
 int /*<<< orphan*/  stub8 (TYPE_2__*,int /*<<< orphan*/ ,unsigned char*,unsigned int,unsigned char*,unsigned int*) ; 
 int /*<<< orphan*/  stub9 (TYPE_2__*,int,int /*<<< orphan*/ *,unsigned int,unsigned char*,unsigned int,int /*<<< orphan*/ *,unsigned char*,unsigned int) ; 

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

