#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */

/* Type definitions */
typedef  int /*<<< orphan*/  uv_write_t ;
typedef  int /*<<< orphan*/  uv_timer_t ;
typedef  int /*<<< orphan*/  uv_stream_t ;
typedef  int /*<<< orphan*/  uv_read_cb ;
typedef  int /*<<< orphan*/  uv_handle_t ;
typedef  int /*<<< orphan*/  uv_connect_t ;
typedef  int /*<<< orphan*/  uv_buf_t ;
typedef  int /*<<< orphan*/  uv_alloc_cb ;

/* Variables and functions */
 int /*<<< orphan*/  ASSERT (int) ; 
 int /*<<< orphan*/  tcp_handle ; 
 int /*<<< orphan*/  timer_handle ; 
 int /*<<< orphan*/  uv_buf_init (char*,int) ; 
 int /*<<< orphan*/  uv_close (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  uv_is_closing (int /*<<< orphan*/ *) ; 
 scalar_t__ uv_read_start (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 scalar_t__ uv_read_stop (int /*<<< orphan*/ *) ; 
 scalar_t__ uv_timer_start (int /*<<< orphan*/ *,void (*) (int /*<<< orphan*/ *),int,int /*<<< orphan*/ ) ; 
 scalar_t__ uv_write (int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int,void (*) (int /*<<< orphan*/ *,int)) ; 
 int /*<<< orphan*/  write_req ; 

__attribute__((used)) static void close_walk_cb(uv_handle_t* handle, void* arg) {
  if (!uv_is_closing(handle))
    uv_close(handle, NULL);
}

__attribute__((used)) static void fail_cb(void) {
  ASSERT(0 && "fail_cb called");
}

__attribute__((used)) static void write_cb(uv_write_t* req, int status) {
  uv_close((uv_handle_t*) &timer_handle, NULL);
  uv_close((uv_handle_t*) &tcp_handle, NULL);
}

__attribute__((used)) static void timer_cb(uv_timer_t* handle) {
  uv_buf_t buf = uv_buf_init("PING", 4);
  ASSERT(0 == uv_write(&write_req,
                       (uv_stream_t*) &tcp_handle,
                       &buf,
                       1,
                       write_cb));
  ASSERT(0 == uv_read_stop((uv_stream_t*) &tcp_handle));
}

__attribute__((used)) static void connect_cb(uv_connect_t* req, int status) {
  ASSERT(0 == status);
  ASSERT(0 == uv_timer_start(&timer_handle, timer_cb, 50, 0));
  ASSERT(0 == uv_read_start((uv_stream_t*) &tcp_handle,
                            (uv_alloc_cb) fail_cb,
                            (uv_read_cb) fail_cb));
}

