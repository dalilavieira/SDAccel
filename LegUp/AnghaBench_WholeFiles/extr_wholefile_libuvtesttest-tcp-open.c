#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_19__   TYPE_3__ ;
typedef  struct TYPE_18__   TYPE_2__ ;
typedef  struct TYPE_17__   TYPE_1__ ;

/* Type definitions */
struct TYPE_17__ {int /*<<< orphan*/ * handle; } ;
typedef  TYPE_1__ uv_write_t ;
typedef  int /*<<< orphan*/  uv_timer_t ;
typedef  int /*<<< orphan*/  uv_stream_t ;
typedef  int /*<<< orphan*/  uv_shutdown_t ;
typedef  scalar_t__ uv_os_sock_t ;
typedef  int /*<<< orphan*/  uv_handle_t ;
struct TYPE_18__ {int /*<<< orphan*/ * handle; } ;
typedef  TYPE_2__ uv_connect_t ;
struct TYPE_19__ {char* base; int len; } ;
typedef  TYPE_3__ uv_buf_t ;
typedef  int ssize_t ;
typedef  int /*<<< orphan*/  slab ;

/* Variables and functions */
 int /*<<< orphan*/  AF_INET ; 
 int /*<<< orphan*/  ASSERT (int) ; 
 int /*<<< orphan*/  IPPROTO_IP ; 
 int /*<<< orphan*/  SOCK_STREAM ; 
 int /*<<< orphan*/  SOL_SOCKET ; 
 int /*<<< orphan*/  SO_REUSEADDR ; 
 int UV_EOF ; 
 int /*<<< orphan*/  client ; 
 int close (scalar_t__) ; 
 int /*<<< orphan*/  close_cb_called ; 
 int /*<<< orphan*/  connect_cb_called ; 
 TYPE_2__ connect_req ; 
 int /*<<< orphan*/  fprintf (int /*<<< orphan*/ ,char*,char*) ; 
 scalar_t__ memcmp (char*,char*,int) ; 
 int /*<<< orphan*/  printf (char*) ; 
 int setsockopt (scalar_t__,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int*,int) ; 
 int shutdown_cb_called ; 
 int /*<<< orphan*/  shutdown_req ; 
 scalar_t__ shutdown_requested ; 
 scalar_t__ socket (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  stderr ; 
 int /*<<< orphan*/  tm ; 
 TYPE_3__ uv_buf_init (char*,int) ; 
 int /*<<< orphan*/  uv_close (int /*<<< orphan*/ *,...) ; 
 int /*<<< orphan*/  uv_default_loop () ; 
 int /*<<< orphan*/  uv_is_closing (int /*<<< orphan*/ *) ; 
 int uv_read_start (int /*<<< orphan*/ *,void (*) (int /*<<< orphan*/ *,size_t,TYPE_3__*),void (*) (int /*<<< orphan*/ *,int,TYPE_3__ const*)) ; 
 int uv_shutdown (int /*<<< orphan*/ *,int /*<<< orphan*/ *,void (*) (int /*<<< orphan*/ *,int)) ; 
 char* uv_strerror (int) ; 
 int uv_timer_init (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int uv_timer_start (int /*<<< orphan*/ *,void (*) (int /*<<< orphan*/ *),int,int /*<<< orphan*/ ) ; 
 int uv_write (int /*<<< orphan*/ *,int /*<<< orphan*/ *,TYPE_3__*,int,void (*) (TYPE_1__*,int)) ; 
 int /*<<< orphan*/  write_cb_called ; 
 int /*<<< orphan*/  write_req ; 

__attribute__((used)) static void close_walk_cb(uv_handle_t* handle, void* arg) {
  if (!uv_is_closing(handle))
    uv_close(handle, NULL);
}

__attribute__((used)) static void startup(void) {
#ifdef _WIN32
    struct WSAData wsa_data;
    int r = WSAStartup(MAKEWORD(2, 2), &wsa_data);
    ASSERT(r == 0);
#endif
}

__attribute__((used)) static uv_os_sock_t create_tcp_socket(void) {
  uv_os_sock_t sock;

  sock = socket(AF_INET, SOCK_STREAM, IPPROTO_IP);
#ifdef _WIN32
  ASSERT(sock != INVALID_SOCKET);
#else
  ASSERT(sock >= 0);
#endif

#ifndef _WIN32
  {
    /* Allow reuse of the port. */
    int yes = 1;
    int r = setsockopt(sock, SOL_SOCKET, SO_REUSEADDR, &yes, sizeof yes);
    ASSERT(r == 0);
  }
#endif

  return sock;
}

__attribute__((used)) static void close_socket(uv_os_sock_t sock) {
  int r;
#ifdef _WIN32
  r = closesocket(sock);
#else
  r = close(sock);
#endif
  ASSERT(r == 0);
}

__attribute__((used)) static void alloc_cb(uv_handle_t* handle,
                     size_t suggested_size,
                     uv_buf_t* buf) {
  static char slab[65536];
  ASSERT(suggested_size <= sizeof(slab));
  buf->base = slab;
  buf->len = sizeof(slab);
}

__attribute__((used)) static void close_cb(uv_handle_t* handle) {
  ASSERT(handle != NULL);
  close_cb_called++;
}

__attribute__((used)) static void shutdown_cb(uv_shutdown_t* req, int status) {
  ASSERT(req == &shutdown_req);
  ASSERT(status == 0);

  /* Now we wait for the EOF */
  shutdown_cb_called++;
}

__attribute__((used)) static void read_cb(uv_stream_t* tcp, ssize_t nread, const uv_buf_t* buf) {
  ASSERT(tcp != NULL);

  if (nread >= 0) {
    ASSERT(nread == 4);
    ASSERT(memcmp("PING", buf->base, nread) == 0);
  }
  else {
    ASSERT(nread == UV_EOF);
    uv_close((uv_handle_t*)tcp, close_cb);
  }
}

__attribute__((used)) static void read1_cb(uv_stream_t* tcp, ssize_t nread, const uv_buf_t* buf) {
  int i;
  ASSERT(tcp != NULL);

  if (nread >= 0) {
    for (i = 0; i < nread; ++i)
      ASSERT(buf->base[i] == 'P');
  } else {
    ASSERT(nread == UV_EOF);
    printf("GOT EOF\n");
    uv_close((uv_handle_t*)tcp, close_cb);
  }
}

__attribute__((used)) static void write_cb(uv_write_t* req, int status) {
  ASSERT(req != NULL);

  if (status) {
    fprintf(stderr, "uv_write error: %s\n", uv_strerror(status));
    ASSERT(0);
  }

  write_cb_called++;
}

__attribute__((used)) static void write1_cb(uv_write_t* req, int status) {
  uv_buf_t buf;
  int r;

  ASSERT(req != NULL);
  if (status) {
    ASSERT(shutdown_cb_called);
    return;
  }

  if (shutdown_requested)
    return;

  buf = uv_buf_init("P", 1);
  r = uv_write(&write_req, req->handle, &buf, 1, write1_cb);
  ASSERT(r == 0);

  write_cb_called++;
}

__attribute__((used)) static void timer_cb(uv_timer_t* handle) {
  int r;

  /* Shutdown on drain. */
  r = uv_shutdown(&shutdown_req, (uv_stream_t*) &client, shutdown_cb);
  ASSERT(r == 0);
  shutdown_requested++;
}

__attribute__((used)) static void connect_cb(uv_connect_t* req, int status) {
  uv_buf_t buf = uv_buf_init("PING", 4);
  uv_stream_t* stream;
  int r;

  ASSERT(req == &connect_req);
  ASSERT(status == 0);

  stream = req->handle;
  connect_cb_called++;

  r = uv_write(&write_req, stream, &buf, 1, write_cb);
  ASSERT(r == 0);

  /* Shutdown on drain. */
  r = uv_shutdown(&shutdown_req, stream, shutdown_cb);
  ASSERT(r == 0);

  /* Start reading */
  r = uv_read_start(stream, alloc_cb, read_cb);
  ASSERT(r == 0);
}

__attribute__((used)) static void connect1_cb(uv_connect_t* req, int status) {
  uv_buf_t buf;
  uv_stream_t* stream;
  int r;

  ASSERT(req == &connect_req);
  ASSERT(status == 0);

  stream = req->handle;
  connect_cb_called++;

  r = uv_timer_init(uv_default_loop(), &tm);
  ASSERT(r == 0);

  r = uv_timer_start(&tm, timer_cb, 2000, 0);
  ASSERT(r == 0);

  buf = uv_buf_init("P", 1);
  r = uv_write(&write_req, stream, &buf, 1, write1_cb);
  ASSERT(r == 0);

  /* Start reading */
  r = uv_read_start(stream, alloc_cb, read1_cb);
  ASSERT(r == 0);
}

