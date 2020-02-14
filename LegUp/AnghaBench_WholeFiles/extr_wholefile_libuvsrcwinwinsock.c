#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  guid ;
struct TYPE_2__ {int dwServiceFlags1; } ;
typedef  TYPE_1__ WSAPROTOCOL_INFOW ;
typedef  int /*<<< orphan*/  WSADATA ;
typedef  scalar_t__ SOCKET ;
typedef  int NTSTATUS ;
typedef  int /*<<< orphan*/  LPFN_CONNECTEX ;
typedef  int /*<<< orphan*/  LPFN_ACCEPTEX ;
typedef  int /*<<< orphan*/  GUID ;
typedef  scalar_t__ DWORD ;
typedef  int /*<<< orphan*/  BOOL ;

/* Variables and functions */
 int /*<<< orphan*/  AF_INET ; 
 int /*<<< orphan*/  AF_INET6 ; 
 int ERROR_IO_PENDING ; 
 int ERROR_SEVERITY_ERROR ; 
 int ERROR_SEVERITY_WARNING ; 
 int ERROR_SUCCESS ; 
 int FACILITY_NTWIN32 ; 
 int /*<<< orphan*/  FALSE ; 
 int GetSystemMetrics (int /*<<< orphan*/ ) ; 
 scalar_t__ INVALID_SOCKET ; 
 int /*<<< orphan*/  IPPROTO_IP ; 
 int /*<<< orphan*/  MAKEWORD (int,int) ; 
 int /*<<< orphan*/  SIO_GET_EXTENSION_FUNCTION_POINTER ; 
 int /*<<< orphan*/  SM_CLEANBOOT ; 
 int SOCKET_ERROR ; 
 int /*<<< orphan*/  SOCK_STREAM ; 
 int /*<<< orphan*/  SOL_SOCKET ; 
 int /*<<< orphan*/  SO_PROTOCOL_INFOW ; 
#define  STATUS_ACCESS_DENIED 184 
#define  STATUS_ACCESS_VIOLATION 183 
#define  STATUS_ADDRESS_ALREADY_EXISTS 182 
#define  STATUS_BAD_NETWORK_PATH 181 
#define  STATUS_BUFFER_OVERFLOW 180 
#define  STATUS_BUFFER_TOO_SMALL 179 
#define  STATUS_CANCELLED 178 
#define  STATUS_COMMITMENT_LIMIT 177 
#define  STATUS_CONFLICTING_ADDRESSES 176 
#define  STATUS_CONNECTION_ABORTED 175 
#define  STATUS_CONNECTION_DISCONNECTED 174 
#define  STATUS_CONNECTION_REFUSED 173 
#define  STATUS_CONNECTION_RESET 172 
#define  STATUS_DEVICE_NOT_READY 171 
#define  STATUS_GRACEFUL_DISCONNECT 170 
#define  STATUS_HOPLIMIT_EXCEEDED 169 
#define  STATUS_HOST_UNREACHABLE 168 
#define  STATUS_INSUFFICIENT_RESOURCES 167 
#define  STATUS_INVALID_ADDRESS 166 
#define  STATUS_INVALID_ADDRESS_COMPONENT 165 
#define  STATUS_INVALID_BUFFER_SIZE 164 
#define  STATUS_INVALID_CONNECTION 163 
#define  STATUS_INVALID_HANDLE 162 
#define  STATUS_INVALID_NETWORK_RESPONSE 161 
#define  STATUS_IO_TIMEOUT 160 
#define  STATUS_LINK_FAILED 159 
#define  STATUS_LINK_TIMEOUT 158 
#define  STATUS_LOCAL_DISCONNECT 157 
#define  STATUS_NETWORK_BUSY 156 
#define  STATUS_NETWORK_UNREACHABLE 155 
#define  STATUS_NOT_IMPLEMENTED 154 
#define  STATUS_NOT_SUPPORTED 153 
#define  STATUS_NO_MEMORY 152 
#define  STATUS_NO_SUCH_DEVICE 151 
#define  STATUS_NO_SUCH_FILE 150 
#define  STATUS_OBJECT_NAME_NOT_FOUND 149 
#define  STATUS_OBJECT_PATH_NOT_FOUND 148 
#define  STATUS_OBJECT_TYPE_MISMATCH 147 
#define  STATUS_PAGEFILE_QUOTA 146 
#define  STATUS_PENDING 145 
#define  STATUS_PIPE_DISCONNECTED 144 
#define  STATUS_PORT_UNREACHABLE 143 
#define  STATUS_PROTOCOL_UNREACHABLE 142 
#define  STATUS_QUOTA_EXCEEDED 141 
#define  STATUS_REMOTE_DISCONNECT 140 
#define  STATUS_REMOTE_NOT_LISTENING 139 
#define  STATUS_REMOTE_RESOURCES 138 
#define  STATUS_REQUEST_ABORTED 137 
#define  STATUS_REQUEST_NOT_ACCEPTED 136 
#define  STATUS_SHARING_VIOLATION 135 
#define  STATUS_SUCCESS 134 
#define  STATUS_TIMEOUT 133 
#define  STATUS_TOO_MANY_ADDRESSES 132 
#define  STATUS_TOO_MANY_PAGING_FILES 131 
#define  STATUS_TRANSACTION_ABORTED 130 
#define  STATUS_UNEXPECTED_NETWORK_ERROR 129 
#define  STATUS_WORKING_SET_QUOTA 128 
 int /*<<< orphan*/  TRUE ; 
 int WSAEACCES ; 
 int WSAEADDRINUSE ; 
 int WSAEADDRNOTAVAIL ; 
 scalar_t__ WSAEAFNOSUPPORT ; 
 int WSAECONNABORTED ; 
 int WSAECONNREFUSED ; 
 int WSAECONNRESET ; 
 int WSAEDISCON ; 
 int WSAEFAULT ; 
 int WSAEHOSTUNREACH ; 
 int WSAEINTR ; 
 int WSAEINVAL ; 
 int WSAEMSGSIZE ; 
 int WSAENETDOWN ; 
 int WSAENETUNREACH ; 
 int WSAENOBUFS ; 
 int WSAENOTCONN ; 
 int WSAENOTSOCK ; 
 int WSAEOPNOTSUPP ; 
 scalar_t__ WSAEPFNOSUPPORT ; 
 scalar_t__ WSAEPROTONOSUPPORT ; 
 int WSAESHUTDOWN ; 
 scalar_t__ WSAESOCKTNOSUPPORT ; 
 int WSAETIMEDOUT ; 
 int WSAEWOULDBLOCK ; 
 int WSAGetLastError () ; 
 int /*<<< orphan*/  WSAID_ACCEPTEX ; 
 int /*<<< orphan*/  WSAID_CONNECTEX ; 
 int WSAIoctl (scalar_t__,int /*<<< orphan*/ ,int /*<<< orphan*/ *,int,void*,int,scalar_t__*,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int WSAStartup (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int XP1_IFS_HANDLES ; 
 int /*<<< orphan*/  abort () ; 
 int closesocket (scalar_t__) ; 
 int getsockopt (scalar_t__,int /*<<< orphan*/ ,int /*<<< orphan*/ ,char*,int*) ; 
 scalar_t__ socket (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  uv_addr_ip4_any_ ; 
 int /*<<< orphan*/  uv_addr_ip6_any_ ; 
 int /*<<< orphan*/  uv_fatal_error (int,char*) ; 
 scalar_t__ uv_ip4_addr (char*,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 scalar_t__ uv_ip6_addr (char*,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int uv_tcp_non_ifs_lsp_ipv4 ; 
 int uv_tcp_non_ifs_lsp_ipv6 ; 

__attribute__((used)) static BOOL uv_get_extension_function(SOCKET socket, GUID guid,
    void **target) {
  int result;
  DWORD bytes;

  result = WSAIoctl(socket,
                    SIO_GET_EXTENSION_FUNCTION_POINTER,
                    &guid,
                    sizeof(guid),
                    (void*)target,
                    sizeof(*target),
                    &bytes,
                    NULL,
                    NULL);

  if (result == SOCKET_ERROR) {
    *target = NULL;
    return FALSE;
  } else {
    return TRUE;
  }
}

BOOL uv_get_acceptex_function(SOCKET socket, LPFN_ACCEPTEX* target) {
  const GUID wsaid_acceptex = WSAID_ACCEPTEX;
  return uv_get_extension_function(socket, wsaid_acceptex, (void**)target);
}

BOOL uv_get_connectex_function(SOCKET socket, LPFN_CONNECTEX* target) {
  const GUID wsaid_connectex = WSAID_CONNECTEX;
  return uv_get_extension_function(socket, wsaid_connectex, (void**)target);
}

__attribute__((used)) static int error_means_no_support(DWORD error) {
  return error == WSAEPROTONOSUPPORT || error == WSAESOCKTNOSUPPORT ||
         error == WSAEPFNOSUPPORT || error == WSAEAFNOSUPPORT;
}

void uv_winsock_init(void) {
  WSADATA wsa_data;
  int errorno;
  SOCKET dummy;
  WSAPROTOCOL_INFOW protocol_info;
  int opt_len;

  /* Set implicit binding address used by connectEx */
  if (uv_ip4_addr("0.0.0.0", 0, &uv_addr_ip4_any_)) {
    abort();
  }

  if (uv_ip6_addr("::", 0, &uv_addr_ip6_any_)) {
    abort();
  }

  /* Skip initialization in safe mode without network support */
  if (1 == GetSystemMetrics(SM_CLEANBOOT)) return;

  /* Initialize winsock */
  errorno = WSAStartup(MAKEWORD(2, 2), &wsa_data);
  if (errorno != 0) {
    uv_fatal_error(errorno, "WSAStartup");
  }

  /* Detect non-IFS LSPs */
  dummy = socket(AF_INET, SOCK_STREAM, IPPROTO_IP);

  if (dummy != INVALID_SOCKET) {
    opt_len = (int) sizeof protocol_info;
    if (getsockopt(dummy,
                   SOL_SOCKET,
                   SO_PROTOCOL_INFOW,
                   (char*) &protocol_info,
                   &opt_len) == SOCKET_ERROR)
      uv_fatal_error(WSAGetLastError(), "getsockopt");

    if (!(protocol_info.dwServiceFlags1 & XP1_IFS_HANDLES))
      uv_tcp_non_ifs_lsp_ipv4 = 1;

    if (closesocket(dummy) == SOCKET_ERROR)
      uv_fatal_error(WSAGetLastError(), "closesocket");

  } else if (!error_means_no_support(WSAGetLastError())) {
    /* Any error other than "socket type not supported" is fatal. */
    uv_fatal_error(WSAGetLastError(), "socket");
  }

  /* Detect IPV6 support and non-IFS LSPs */
  dummy = socket(AF_INET6, SOCK_STREAM, IPPROTO_IP);

  if (dummy != INVALID_SOCKET) {
    opt_len = (int) sizeof protocol_info;
    if (getsockopt(dummy,
                   SOL_SOCKET,
                   SO_PROTOCOL_INFOW,
                   (char*) &protocol_info,
                   &opt_len) == SOCKET_ERROR)
      uv_fatal_error(WSAGetLastError(), "getsockopt");

    if (!(protocol_info.dwServiceFlags1 & XP1_IFS_HANDLES))
      uv_tcp_non_ifs_lsp_ipv6 = 1;

    if (closesocket(dummy) == SOCKET_ERROR)
      uv_fatal_error(WSAGetLastError(), "closesocket");

  } else if (!error_means_no_support(WSAGetLastError())) {
    /* Any error other than "socket type not supported" is fatal. */
    uv_fatal_error(WSAGetLastError(), "socket");
  }
}

int uv_ntstatus_to_winsock_error(NTSTATUS status) {
  switch (status) {
    case STATUS_SUCCESS:
      return ERROR_SUCCESS;

    case STATUS_PENDING:
      return ERROR_IO_PENDING;

    case STATUS_INVALID_HANDLE:
    case STATUS_OBJECT_TYPE_MISMATCH:
      return WSAENOTSOCK;

    case STATUS_INSUFFICIENT_RESOURCES:
    case STATUS_PAGEFILE_QUOTA:
    case STATUS_COMMITMENT_LIMIT:
    case STATUS_WORKING_SET_QUOTA:
    case STATUS_NO_MEMORY:
    case STATUS_QUOTA_EXCEEDED:
    case STATUS_TOO_MANY_PAGING_FILES:
    case STATUS_REMOTE_RESOURCES:
      return WSAENOBUFS;

    case STATUS_TOO_MANY_ADDRESSES:
    case STATUS_SHARING_VIOLATION:
    case STATUS_ADDRESS_ALREADY_EXISTS:
      return WSAEADDRINUSE;

    case STATUS_LINK_TIMEOUT:
    case STATUS_IO_TIMEOUT:
    case STATUS_TIMEOUT:
      return WSAETIMEDOUT;

    case STATUS_GRACEFUL_DISCONNECT:
      return WSAEDISCON;

    case STATUS_REMOTE_DISCONNECT:
    case STATUS_CONNECTION_RESET:
    case STATUS_LINK_FAILED:
    case STATUS_CONNECTION_DISCONNECTED:
    case STATUS_PORT_UNREACHABLE:
    case STATUS_HOPLIMIT_EXCEEDED:
      return WSAECONNRESET;

    case STATUS_LOCAL_DISCONNECT:
    case STATUS_TRANSACTION_ABORTED:
    case STATUS_CONNECTION_ABORTED:
      return WSAECONNABORTED;

    case STATUS_BAD_NETWORK_PATH:
    case STATUS_NETWORK_UNREACHABLE:
    case STATUS_PROTOCOL_UNREACHABLE:
      return WSAENETUNREACH;

    case STATUS_HOST_UNREACHABLE:
      return WSAEHOSTUNREACH;

    case STATUS_CANCELLED:
    case STATUS_REQUEST_ABORTED:
      return WSAEINTR;

    case STATUS_BUFFER_OVERFLOW:
    case STATUS_INVALID_BUFFER_SIZE:
      return WSAEMSGSIZE;

    case STATUS_BUFFER_TOO_SMALL:
    case STATUS_ACCESS_VIOLATION:
      return WSAEFAULT;

    case STATUS_DEVICE_NOT_READY:
    case STATUS_REQUEST_NOT_ACCEPTED:
      return WSAEWOULDBLOCK;

    case STATUS_INVALID_NETWORK_RESPONSE:
    case STATUS_NETWORK_BUSY:
    case STATUS_NO_SUCH_DEVICE:
    case STATUS_NO_SUCH_FILE:
    case STATUS_OBJECT_PATH_NOT_FOUND:
    case STATUS_OBJECT_NAME_NOT_FOUND:
    case STATUS_UNEXPECTED_NETWORK_ERROR:
      return WSAENETDOWN;

    case STATUS_INVALID_CONNECTION:
      return WSAENOTCONN;

    case STATUS_REMOTE_NOT_LISTENING:
    case STATUS_CONNECTION_REFUSED:
      return WSAECONNREFUSED;

    case STATUS_PIPE_DISCONNECTED:
      return WSAESHUTDOWN;

    case STATUS_CONFLICTING_ADDRESSES:
    case STATUS_INVALID_ADDRESS:
    case STATUS_INVALID_ADDRESS_COMPONENT:
      return WSAEADDRNOTAVAIL;

    case STATUS_NOT_SUPPORTED:
    case STATUS_NOT_IMPLEMENTED:
      return WSAEOPNOTSUPP;

    case STATUS_ACCESS_DENIED:
      return WSAEACCES;

    default:
      if ((status & (FACILITY_NTWIN32 << 16)) == (FACILITY_NTWIN32 << 16) &&
          (status & (ERROR_SEVERITY_ERROR | ERROR_SEVERITY_WARNING))) {
        /* It's a windows error that has been previously mapped to an ntstatus
         * code. */
        return (DWORD) (status & 0xffff);
      } else {
        /* The default fallback for unmappable ntstatus codes. */
        return WSAEINVAL;
      }
  }
}

