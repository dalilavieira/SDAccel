#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_39__   TYPE_5__ ;
typedef  struct TYPE_38__   TYPE_4__ ;
typedef  struct TYPE_37__   TYPE_2__ ;
typedef  struct TYPE_36__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  uv_udp_t ;
typedef  int /*<<< orphan*/  uv_udp_send_t ;
struct TYPE_36__ {int /*<<< orphan*/ * data; } ;
typedef  TYPE_1__ uv_tcp_t ;
typedef  int /*<<< orphan*/  uv_stream_t ;
struct TYPE_37__ {scalar_t__ handle; } ;
typedef  TYPE_2__ uv_shutdown_t ;
typedef  TYPE_2__ uv_handle_t ;
struct TYPE_38__ {scalar_t__ handle; } ;
typedef  TYPE_4__ uv_connect_t ;
struct TYPE_39__ {size_t len; TYPE_2__* base; } ;
typedef  TYPE_5__ uv_buf_t ;
struct sockaddr_in {scalar_t__ sin_family; scalar_t__ sin_port; int /*<<< orphan*/  sin_addr; } ;
struct sockaddr {scalar_t__ sa_family; } ;
typedef  scalar_t__ ssize_t ;
typedef  int /*<<< orphan*/  sockname ;

/* Variables and functions */
 scalar_t__ AF_INET ; 
 int /*<<< orphan*/  ASSERT (int) ; 
 int UV_ENOTCONN ; 
 int connect_port ; 
 int /*<<< orphan*/  connect_req ; 
 int /*<<< orphan*/  fprintf (int /*<<< orphan*/ ,char*,...) ; 
 int /*<<< orphan*/  free (TYPE_2__*) ; 
 int /*<<< orphan*/  getpeernamecount ; 
 int /*<<< orphan*/  getsocknamecount ; 
 int /*<<< orphan*/  loop ; 
 void* malloc (int) ; 
 scalar_t__ memcmp (int /*<<< orphan*/ *,int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  memset (struct sockaddr*,int,int) ; 
 int ntohs (scalar_t__) ; 
 int /*<<< orphan*/  printf (char*,char const*,char*,int) ; 
 int /*<<< orphan*/  send_req ; 
 int server_port ; 
 int /*<<< orphan*/  stderr ; 
 TYPE_1__ tcp ; 
 TYPE_1__ tcpServer ; 
 int /*<<< orphan*/  udp ; 
 int /*<<< orphan*/  udpServer ; 
 int uv_accept (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 TYPE_5__ uv_buf_init (char*,int) ; 
 int /*<<< orphan*/  uv_close (TYPE_2__*,void (*) (TYPE_2__*)) ; 
 char* uv_err_name (int) ; 
 scalar_t__ uv_ip4_addr (char const*,int,struct sockaddr_in*) ; 
 int uv_ip4_name (struct sockaddr_in*,char*,int) ; 
 int /*<<< orphan*/  uv_is_closing (TYPE_2__*) ; 
 int uv_listen (int /*<<< orphan*/ *,int,void (*) (int /*<<< orphan*/ *,int)) ; 
 int uv_read_start (int /*<<< orphan*/ *,void (*) (TYPE_2__*,size_t,TYPE_5__*),void (*) (int /*<<< orphan*/ *,scalar_t__,TYPE_5__ const*)) ; 
 int uv_shutdown (TYPE_2__*,int /*<<< orphan*/ *,void (*) (TYPE_2__*,int)) ; 
 int uv_tcp_bind (TYPE_1__*,struct sockaddr const*,int /*<<< orphan*/ ) ; 
 int uv_tcp_connect (int /*<<< orphan*/ *,TYPE_1__*,struct sockaddr const*,void (*) (TYPE_4__*,int)) ; 
 int uv_tcp_getpeername (TYPE_1__*,struct sockaddr*,int*) ; 
 int uv_tcp_getsockname (TYPE_1__*,struct sockaddr*,int*) ; 
 int uv_tcp_init (int /*<<< orphan*/ ,TYPE_1__*) ; 
 int uv_udp_bind (int /*<<< orphan*/ *,struct sockaddr const*,int /*<<< orphan*/ ) ; 
 int uv_udp_getsockname (int /*<<< orphan*/ *,struct sockaddr*,int*) ; 
 int uv_udp_init (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int uv_udp_recv_start (int /*<<< orphan*/ *,void (*) (TYPE_2__*,size_t,TYPE_5__*),void (*) (int /*<<< orphan*/ *,scalar_t__,TYPE_5__ const*,struct sockaddr const*,unsigned int)) ; 
 int uv_udp_send (int /*<<< orphan*/ *,int /*<<< orphan*/ *,TYPE_5__*,int,struct sockaddr const*,void (*) (int /*<<< orphan*/ *,int)) ; 

__attribute__((used)) static void close_walk_cb(uv_handle_t* handle, void* arg) {
  if (!uv_is_closing(handle))
    uv_close(handle, NULL);
}

__attribute__((used)) static void alloc(uv_handle_t* handle, size_t suggested_size, uv_buf_t* buf) {
  buf->base = malloc(suggested_size);
  buf->len = suggested_size;
}

__attribute__((used)) static void on_close(uv_handle_t* peer) {
  free(peer);
  uv_close((uv_handle_t*)&tcpServer, NULL);
}

__attribute__((used)) static void after_shutdown(uv_shutdown_t* req, int status) {
  uv_close((uv_handle_t*) req->handle, on_close);
  free(req);
}

__attribute__((used)) static void after_read(uv_stream_t* handle,
                       ssize_t nread,
                       const uv_buf_t* buf) {
  uv_shutdown_t* req;
  int r;

  if (buf->base) {
    free(buf->base);
  }

  req = (uv_shutdown_t*) malloc(sizeof *req);
  r = uv_shutdown(req, handle, after_shutdown);
  ASSERT(r == 0);
}

__attribute__((used)) static void check_sockname(struct sockaddr* addr, const char* compare_ip,
  int compare_port, const char* context) {
  struct sockaddr_in check_addr = *(struct sockaddr_in*) addr;
  struct sockaddr_in compare_addr;
  char check_ip[17];
  int r;

  ASSERT(0 == uv_ip4_addr(compare_ip, compare_port, &compare_addr));

  /* Both addresses should be ipv4 */
  ASSERT(check_addr.sin_family == AF_INET);
  ASSERT(compare_addr.sin_family == AF_INET);

  /* Check if the ip matches */
  ASSERT(memcmp(&check_addr.sin_addr,
         &compare_addr.sin_addr,
         sizeof compare_addr.sin_addr) == 0);

  /* Check if the port matches. If port == 0 anything goes. */
  ASSERT(compare_port == 0 || check_addr.sin_port == compare_addr.sin_port);

  r = uv_ip4_name(&check_addr, (char*) check_ip, sizeof check_ip);
  ASSERT(r == 0);

  printf("%s: %s:%d\n", context, check_ip, ntohs(check_addr.sin_port));
}

__attribute__((used)) static void on_connection(uv_stream_t* server, int status) {
  struct sockaddr sockname, peername;
  int namelen;
  uv_tcp_t* handle;
  int r;

  if (status != 0) {
    fprintf(stderr, "Connect error %s\n", uv_err_name(status));
  }
  ASSERT(status == 0);

  handle = malloc(sizeof(*handle));
  ASSERT(handle != NULL);

  r = uv_tcp_init(loop, handle);
  ASSERT(r == 0);

  /* associate server with stream */
  handle->data = server;

  r = uv_accept(server, (uv_stream_t*)handle);
  ASSERT(r == 0);

  namelen = sizeof sockname;
  r = uv_tcp_getsockname(handle, &sockname, &namelen);
  ASSERT(r == 0);
  check_sockname(&sockname, "127.0.0.1", server_port, "accepted socket");
  getsocknamecount++;

  namelen = sizeof peername;
  r = uv_tcp_getpeername(handle, &peername, &namelen);
  ASSERT(r == 0);
  check_sockname(&peername, "127.0.0.1", connect_port, "accepted socket peer");
  getpeernamecount++;

  r = uv_read_start((uv_stream_t*)handle, alloc, after_read);
  ASSERT(r == 0);
}

__attribute__((used)) static void on_connect(uv_connect_t* req, int status) {
  struct sockaddr sockname, peername;
  int r, namelen;

  ASSERT(status == 0);

  namelen = sizeof sockname;
  r = uv_tcp_getsockname((uv_tcp_t*) req->handle, &sockname, &namelen);
  ASSERT(r == 0);
  check_sockname(&sockname, "127.0.0.1", 0, "connected socket");
  getsocknamecount++;

  namelen = sizeof peername;
  r = uv_tcp_getpeername((uv_tcp_t*) req->handle, &peername, &namelen);
  ASSERT(r == 0);
  check_sockname(&peername, "127.0.0.1", server_port, "connected socket peer");
  getpeernamecount++;

  uv_close((uv_handle_t*)&tcp, NULL);
}

__attribute__((used)) static int tcp_listener(void) {
  struct sockaddr_in addr;
  struct sockaddr sockname, peername;
  int namelen;
  int r;

  ASSERT(0 == uv_ip4_addr("0.0.0.0", server_port, &addr));

  r = uv_tcp_init(loop, &tcpServer);
  if (r) {
    fprintf(stderr, "Socket creation error\n");
    return 1;
  }

  r = uv_tcp_bind(&tcpServer, (const struct sockaddr*) &addr, 0);
  if (r) {
    fprintf(stderr, "Bind error\n");
    return 1;
  }

  r = uv_listen((uv_stream_t*)&tcpServer, 128, on_connection);
  if (r) {
    fprintf(stderr, "Listen error\n");
    return 1;
  }

  memset(&sockname, -1, sizeof sockname);
  namelen = sizeof sockname;
  r = uv_tcp_getsockname(&tcpServer, &sockname, &namelen);
  ASSERT(r == 0);
  check_sockname(&sockname, "0.0.0.0", server_port, "server socket");
  getsocknamecount++;

  namelen = sizeof sockname;
  r = uv_tcp_getpeername(&tcpServer, &peername, &namelen);
  ASSERT(r == UV_ENOTCONN);
  getpeernamecount++;

  return 0;
}

__attribute__((used)) static void tcp_connector(void) {
  struct sockaddr_in server_addr;
  struct sockaddr sockname;
  int r, namelen;

  ASSERT(0 == uv_ip4_addr("127.0.0.1", server_port, &server_addr));

  r = uv_tcp_init(loop, &tcp);
  tcp.data = &connect_req;
  ASSERT(!r);

  r = uv_tcp_connect(&connect_req,
                     &tcp,
                     (const struct sockaddr*) &server_addr,
                     on_connect);
  ASSERT(!r);

  /* Fetch the actual port used by the connecting socket. */
  namelen = sizeof sockname;
  r = uv_tcp_getsockname(&tcp, &sockname, &namelen);
  ASSERT(!r);
  ASSERT(sockname.sa_family == AF_INET);
  connect_port = ntohs(((struct sockaddr_in*) &sockname)->sin_port);
  ASSERT(connect_port > 0);
}

__attribute__((used)) static void udp_recv(uv_udp_t* handle,
                     ssize_t nread,
                     const uv_buf_t* buf,
                     const struct sockaddr* addr,
                     unsigned flags) {
  struct sockaddr sockname;
  int namelen;
  int r;

  ASSERT(nread >= 0);
  free(buf->base);

  if (nread == 0) {
    return;
  }

  memset(&sockname, -1, sizeof sockname);
  namelen = sizeof(sockname);
  r = uv_udp_getsockname(&udp, &sockname, &namelen);
  ASSERT(r == 0);
  check_sockname(&sockname, "0.0.0.0", 0, "udp receiving socket");
  getsocknamecount++;

  uv_close((uv_handle_t*) &udp, NULL);
  uv_close((uv_handle_t*) handle, NULL);
}

__attribute__((used)) static void udp_send(uv_udp_send_t* req, int status) {

}

__attribute__((used)) static int udp_listener(void) {
  struct sockaddr_in addr;
  struct sockaddr sockname;
  int namelen;
  int r;

  ASSERT(0 == uv_ip4_addr("0.0.0.0", server_port, &addr));

  r = uv_udp_init(loop, &udpServer);
  if (r) {
    fprintf(stderr, "Socket creation error\n");
    return 1;
  }

  r = uv_udp_bind(&udpServer, (const struct sockaddr*) &addr, 0);
  if (r) {
    fprintf(stderr, "Bind error\n");
    return 1;
  }

  memset(&sockname, -1, sizeof sockname);
  namelen = sizeof sockname;
  r = uv_udp_getsockname(&udpServer, &sockname, &namelen);
  ASSERT(r == 0);
  check_sockname(&sockname, "0.0.0.0", server_port, "udp listener socket");
  getsocknamecount++;

  r = uv_udp_recv_start(&udpServer, alloc, udp_recv);
  ASSERT(r == 0);

  return 0;
}

__attribute__((used)) static void udp_sender(void) {
  struct sockaddr_in server_addr;
  uv_buf_t buf;
  int r;

  r = uv_udp_init(loop, &udp);
  ASSERT(!r);

  buf = uv_buf_init("PING", 4);
  ASSERT(0 == uv_ip4_addr("127.0.0.1", server_port, &server_addr));

  r = uv_udp_send(&send_req,
                  &udp,
                  &buf,
                  1,
                  (const struct sockaddr*) &server_addr,
                  udp_send);
  ASSERT(!r);
}

