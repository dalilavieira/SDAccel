#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_7__   TYPE_2__ ;
typedef  struct TYPE_6__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  uv_udp_t ;
struct TYPE_6__ {int /*<<< orphan*/ * handle; } ;
typedef  TYPE_1__ uv_udp_send_t ;
typedef  int /*<<< orphan*/  uv_handle_t ;
struct TYPE_7__ {char* base; int len; } ;
typedef  TYPE_2__ uv_buf_t ;
struct sockaddr {int dummy; } ;
typedef  int ssize_t ;
typedef  int /*<<< orphan*/  slab ;

/* Variables and functions */
 int /*<<< orphan*/  ASSERT (int) ; 
 int /*<<< orphan*/  CHECK_HANDLE (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  cl_recv_cb_called ; 
 int /*<<< orphan*/  client ; 
 int /*<<< orphan*/  close_cb_called ; 
 int /*<<< orphan*/  memcmp (char*,char*,int) ; 
 int /*<<< orphan*/  sv_send_cb_called ; 
 int /*<<< orphan*/  uv_close (int /*<<< orphan*/ *,...) ; 
 int /*<<< orphan*/  uv_is_closing (int /*<<< orphan*/ *) ; 

__attribute__((used)) static void close_walk_cb(uv_handle_t* handle, void* arg) {
  if (!uv_is_closing(handle))
    uv_close(handle, NULL);
}

__attribute__((used)) static void alloc_cb(uv_handle_t* handle,
                     size_t suggested_size,
                     uv_buf_t* buf) {
  static char slab[65536];
  CHECK_HANDLE(handle);
  ASSERT(suggested_size <= sizeof(slab));
  buf->base = slab;
  buf->len = sizeof(slab);
}

__attribute__((used)) static void close_cb(uv_handle_t* handle) {
  CHECK_HANDLE(handle);
  close_cb_called++;
}

__attribute__((used)) static void sv_send_cb(uv_udp_send_t* req, int status) {
  ASSERT(req != NULL);
  ASSERT(status == 0);
  CHECK_HANDLE(req->handle);

  sv_send_cb_called++;

  uv_close((uv_handle_t*) req->handle, close_cb);
}

__attribute__((used)) static void cl_recv_cb(uv_udp_t* handle,
                       ssize_t nread,
                       const uv_buf_t* buf,
                       const struct sockaddr* addr,
                       unsigned flags) {
  CHECK_HANDLE(handle);
  ASSERT(flags == 0);

  cl_recv_cb_called++;

  if (nread < 0) {
    ASSERT(0 && "unexpected error");
  }

  if (nread == 0) {
    /* Returning unused buffer. Don't count towards cl_recv_cb_called */
    ASSERT(addr == NULL);
    return;
  }

  ASSERT(addr != NULL);
  ASSERT(nread == 4);
  ASSERT(!memcmp("PING", buf->base, nread));

  /* we are done with the client handle, we can close it */
  uv_close((uv_handle_t*) &client, close_cb);
}

