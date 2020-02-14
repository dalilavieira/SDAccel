#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  uv_udp_t ;
typedef  int /*<<< orphan*/  uv_handle_t ;
struct TYPE_4__ {char* base; int len; } ;
typedef  TYPE_1__ uv_buf_t ;
struct sockaddr {int dummy; } ;
typedef  int ssize_t ;
typedef  int /*<<< orphan*/  slab ;

/* Variables and functions */
 int /*<<< orphan*/  ASSERT (int) ; 
 int /*<<< orphan*/  CHECK_HANDLE (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  client ; 
 int /*<<< orphan*/  close_cb_called ; 
 scalar_t__ memcmp (char*,char*,int) ; 
 int /*<<< orphan*/  sv_recv_cb_called ; 
 int /*<<< orphan*/  uv_close (int /*<<< orphan*/ *,...) ; 
 int uv_is_closing (int /*<<< orphan*/ *) ; 

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
  ASSERT(uv_is_closing(handle));
  close_cb_called++;
}

__attribute__((used)) static void sv_recv_cb(uv_udp_t* handle,
                       ssize_t nread,
                       const uv_buf_t* rcvbuf,
                       const struct sockaddr* addr,
                       unsigned flags) {
  ASSERT(nread > 0);

  if (nread == 0) {
    ASSERT(addr == NULL);
    return;
  }

  ASSERT(nread == 4);
  ASSERT(addr != NULL);

  ASSERT(memcmp("EXIT", rcvbuf->base, nread) == 0);
  uv_close((uv_handle_t*) handle, close_cb);
  uv_close((uv_handle_t*) &client, close_cb);

  sv_recv_cb_called++;
}

