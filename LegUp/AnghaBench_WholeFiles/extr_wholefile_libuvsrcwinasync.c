#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_18__   TYPE_2__ ;
typedef  struct TYPE_17__   TYPE_1__ ;

/* Type definitions */
struct TYPE_17__ {scalar_t__ type; TYPE_2__* data; } ;
typedef  TYPE_1__ uv_req_t ;
typedef  int /*<<< orphan*/  uv_loop_t ;
typedef  int /*<<< orphan*/  uv_handle_t ;
struct TYPE_18__ {int flags; char async_sent; scalar_t__ type; int /*<<< orphan*/  (* async_cb ) (TYPE_2__*) ;TYPE_1__ async_req; int /*<<< orphan*/ * loop; } ;
typedef  TYPE_2__ uv_async_t ;
typedef  int /*<<< orphan*/  (* uv_async_cb ) (TYPE_2__*) ;

/* Variables and functions */
 int /*<<< orphan*/  POST_COMPLETION_FOR_REQ (int /*<<< orphan*/ *,TYPE_1__*) ; 
 scalar_t__ UV_ASYNC ; 
 int UV_HANDLE_CLOSED ; 
 int UV_HANDLE_CLOSING ; 
 int /*<<< orphan*/  UV_REQ_INIT (TYPE_1__*,scalar_t__) ; 
 scalar_t__ UV_WAKEUP ; 
 int /*<<< orphan*/  assert (int) ; 
 int /*<<< orphan*/  stub1 (TYPE_2__*) ; 
 int /*<<< orphan*/  uv__handle_close (TYPE_2__*) ; 
 int /*<<< orphan*/  uv__handle_closing (TYPE_2__*) ; 
 int /*<<< orphan*/  uv__handle_init (int /*<<< orphan*/ *,int /*<<< orphan*/ *,scalar_t__) ; 
 int /*<<< orphan*/  uv__handle_start (TYPE_2__*) ; 
 int /*<<< orphan*/  uv_want_endgame (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 

__attribute__((used)) static inline char uv__atomic_exchange_set(char volatile* target) {
  const char one = 1;
  char old_value;
  __asm__ __volatile__ ("lock xchgb %0, %1\n\t"
                        : "=r"(old_value), "=m"(*target)
                        : "0"(one), "m"(*target)
                        : "memory");
  return old_value;
}

void uv_async_endgame(uv_loop_t* loop, uv_async_t* handle) {
  if (handle->flags & UV_HANDLE_CLOSING &&
      !handle->async_sent) {
    assert(!(handle->flags & UV_HANDLE_CLOSED));
    uv__handle_close(handle);
  }
}

int uv_async_init(uv_loop_t* loop, uv_async_t* handle, uv_async_cb async_cb) {
  uv_req_t* req;

  uv__handle_init(loop, (uv_handle_t*) handle, UV_ASYNC);
  handle->async_sent = 0;
  handle->async_cb = async_cb;

  req = &handle->async_req;
  UV_REQ_INIT(req, UV_WAKEUP);
  req->data = handle;

  uv__handle_start(handle);

  return 0;
}

void uv_async_close(uv_loop_t* loop, uv_async_t* handle) {
  if (!((uv_async_t*)handle)->async_sent) {
    uv_want_endgame(loop, (uv_handle_t*) handle);
  }

  uv__handle_closing(handle);
}

int uv_async_send(uv_async_t* handle) {
  uv_loop_t* loop = handle->loop;

  if (handle->type != UV_ASYNC) {
    /* Can't set errno because that's not thread-safe. */
    return -1;
  }

  /* The user should make sure never to call uv_async_send to a closing or
   * closed handle. */
  assert(!(handle->flags & UV_HANDLE_CLOSING));

  if (!uv__atomic_exchange_set(&handle->async_sent)) {
    POST_COMPLETION_FOR_REQ(loop, &handle->async_req);
  }

  return 0;
}

void uv_process_async_wakeup_req(uv_loop_t* loop, uv_async_t* handle,
    uv_req_t* req) {
  assert(handle->type == UV_ASYNC);
  assert(req->type == UV_WAKEUP);

  handle->async_sent = 0;

  if (handle->flags & UV_HANDLE_CLOSING) {
    uv_want_endgame(loop, (uv_handle_t*)handle);
  } else if (handle->async_cb != NULL) {
    handle->async_cb(handle);
  }
}

