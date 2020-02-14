#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_13__   TYPE_2__ ;
typedef  struct TYPE_12__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  uv_tcp_t ;
struct TYPE_12__ {int /*<<< orphan*/  loop; } ;
typedef  TYPE_1__ uv_stream_t ;
typedef  int /*<<< orphan*/  uv_loop_t ;
typedef  int /*<<< orphan*/  uv_handle_t ;
struct TYPE_13__ {scalar_t__ handle; } ;
typedef  TYPE_2__ uv_connect_t ;
typedef  int /*<<< orphan*/ * uv_close_cb ;
struct sockaddr_in {int dummy; } ;
struct sockaddr {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  AF_INET ; 
 int /*<<< orphan*/  ASSERT (int) ; 
 int /*<<< orphan*/  TEST_PORT ; 
 int UV_EBUSY ; 
 scalar_t__ free ; 
 int /*<<< orphan*/ * malloc (int) ; 
 int uv_accept (TYPE_1__*,TYPE_1__*) ; 
 int /*<<< orphan*/  uv_close (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 scalar_t__ uv_ip4_addr (char*,int /*<<< orphan*/ ,struct sockaddr_in*) ; 
 int /*<<< orphan*/  uv_is_closing (int /*<<< orphan*/ *) ; 
 int uv_listen (TYPE_1__*,int,void (*) (TYPE_1__*,int)) ; 
 int uv_tcp_bind (int /*<<< orphan*/ *,struct sockaddr const*,int /*<<< orphan*/ ) ; 
 int uv_tcp_connect (TYPE_2__*,int /*<<< orphan*/ *,struct sockaddr const*,void (*) (TYPE_2__*,int)) ; 
 int uv_tcp_init (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int uv_tcp_init_ex (int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 

__attribute__((used)) static void close_walk_cb(uv_handle_t* handle, void* arg) {
  if (!uv_is_closing(handle))
    uv_close(handle, NULL);
}

__attribute__((used)) static void on_connect(uv_connect_t* req, int status) {
  ASSERT(status == 0);
  uv_close((uv_handle_t*) req->handle, NULL);
}

__attribute__((used)) static void on_connection(uv_stream_t* server, int status) {
  uv_tcp_t* handle;
  int r;

  ASSERT(status == 0);

  handle = malloc(sizeof(*handle));
  ASSERT(handle != NULL);

  r = uv_tcp_init_ex(server->loop, handle, AF_INET);
  ASSERT(r == 0);

  r = uv_accept(server, (uv_stream_t*)handle);
  ASSERT(r == UV_EBUSY);

  uv_close((uv_handle_t*) server, NULL);
  uv_close((uv_handle_t*) handle, (uv_close_cb)free);
}

__attribute__((used)) static void tcp_listener(uv_loop_t* loop, uv_tcp_t* server) {
  struct sockaddr_in addr;
  int r;

  ASSERT(0 == uv_ip4_addr("0.0.0.0", TEST_PORT, &addr));

  r = uv_tcp_init(loop, server);
  ASSERT(r == 0);

  r = uv_tcp_bind(server, (const struct sockaddr*) &addr, 0);
  ASSERT(r == 0);

  r = uv_listen((uv_stream_t*) server, 128, on_connection);
  ASSERT(r == 0);
}

__attribute__((used)) static void tcp_connector(uv_loop_t* loop, uv_tcp_t* client, uv_connect_t* req) {
  struct sockaddr_in server_addr;
  int r;

  ASSERT(0 == uv_ip4_addr("127.0.0.1", TEST_PORT, &server_addr));

  r = uv_tcp_init(loop, client);
  ASSERT(r == 0);

  r = uv_tcp_connect(req,
                     client,
                     (const struct sockaddr*) &server_addr,
                     on_connect);
  ASSERT(r == 0);
}

