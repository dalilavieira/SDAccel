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
typedef  int /*<<< orphan*/  uv_handle_t ;

/* Variables and functions */
 int /*<<< orphan*/  ASSERT (int) ; 
 int /*<<< orphan*/  close_cb_called ; 
 int /*<<< orphan*/  uv_close (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  uv_is_closing (int /*<<< orphan*/ *) ; 
 scalar_t__ uv_recv_buffer_size (int /*<<< orphan*/ *,int*) ; 

__attribute__((used)) static void close_walk_cb(uv_handle_t* handle, void* arg) {
  if (!uv_is_closing(handle))
    uv_close(handle, NULL);
}

__attribute__((used)) static void close_cb(uv_handle_t* handle) {
  close_cb_called++;
}

__attribute__((used)) static void check_buffer_size(uv_handle_t* handle) {
  int value;

  value = 0;
  ASSERT(0 == uv_recv_buffer_size(handle, &value));
  ASSERT(value > 0);

  value = 10000;
  ASSERT(0 == uv_recv_buffer_size(handle, &value));

  value = 0;
  ASSERT(0 == uv_recv_buffer_size(handle, &value));
  /* linux sets double the value */
  ASSERT(value == 10000 || value == 20000);
}

