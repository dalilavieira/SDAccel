#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_13__   TYPE_4__ ;
typedef  struct TYPE_12__   TYPE_3__ ;
typedef  struct TYPE_11__   TYPE_2__ ;
typedef  struct TYPE_10__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  uv_stream_t ;
struct TYPE_10__ {int /*<<< orphan*/ * stream; } ;
struct TYPE_11__ {int flags; TYPE_1__ data; } ;
typedef  TYPE_2__ uv_stdio_container_t ;
typedef  int /*<<< orphan*/  uv_process_t ;
typedef  int /*<<< orphan*/  uv_handle_t ;
struct TYPE_12__ {scalar_t__ len; scalar_t__ base; } ;
typedef  TYPE_3__ uv_buf_t ;
typedef  scalar_t__ ssize_t ;
typedef  int int64_t ;
struct TYPE_13__ {char** args; void (* exit_cb ) (int /*<<< orphan*/ *,int,int) ;int stdio_count; TYPE_2__* stdio; void* file; } ;

/* Variables and functions */
 int /*<<< orphan*/  ASSERT (int) ; 
 scalar_t__ N ; 
 scalar_t__ OUTPUT_SIZE ; 
 int UV_CREATE_PIPE ; 
 scalar_t__ UV_EOF ; 
 int UV_IGNORE ; 
 int UV_WRITABLE_PIPE ; 
 char** args ; 
 scalar_t__ done ; 
 void* exepath ; 
 int /*<<< orphan*/  loop ; 
 TYPE_4__ options ; 
 int /*<<< orphan*/  out ; 
 scalar_t__ output ; 
 scalar_t__ output_used ; 
 int pipe_open ; 
 int /*<<< orphan*/  process ; 
 int process_open ; 
static  void spawn () ; 
 int /*<<< orphan*/  uv_close (int /*<<< orphan*/ *,...) ; 
 int /*<<< orphan*/  uv_is_closing (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  uv_pipe_init (int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int uv_read_start (int /*<<< orphan*/ *,void (*) (int /*<<< orphan*/ *,size_t,TYPE_3__*),void (*) (int /*<<< orphan*/ *,scalar_t__,TYPE_3__ const*)) ; 
 int uv_spawn (int /*<<< orphan*/ ,int /*<<< orphan*/ *,TYPE_4__*) ; 

__attribute__((used)) static void close_walk_cb(uv_handle_t* handle, void* arg) {
  if (!uv_is_closing(handle))
    uv_close(handle, NULL);
}

__attribute__((used)) static void maybe_spawn(void) {
  if (process_open == 0 && pipe_open == 0) {
    done++;
    if (done < N) {
      spawn();
    }
  }
}

__attribute__((used)) static void process_close_cb(uv_handle_t* handle) {
  ASSERT(process_open == 1);
  process_open = 0;
  maybe_spawn();
}

__attribute__((used)) static void exit_cb(uv_process_t* process,
                    int64_t exit_status,
                    int term_signal) {
  ASSERT(exit_status == 42);
  ASSERT(term_signal == 0);
  uv_close((uv_handle_t*)process, process_close_cb);
}

__attribute__((used)) static void on_alloc(uv_handle_t* handle,
                     size_t suggested_size,
                     uv_buf_t* buf) {
  buf->base = output + output_used;
  buf->len = OUTPUT_SIZE - output_used;
}

__attribute__((used)) static void pipe_close_cb(uv_handle_t* pipe) {
  ASSERT(pipe_open == 1);
  pipe_open = 0;
  maybe_spawn();
}

__attribute__((used)) static void on_read(uv_stream_t* pipe, ssize_t nread, const uv_buf_t* buf) {
  if (nread > 0) {
    ASSERT(pipe_open == 1);
    output_used += nread;
  } else if (nread < 0) {
    if (nread == UV_EOF) {
      uv_close((uv_handle_t*)pipe, pipe_close_cb);
    }
  }
}

__attribute__((used)) static void spawn(void) {
  uv_stdio_container_t stdio[2];
  int r;

  ASSERT(process_open == 0);
  ASSERT(pipe_open == 0);

  args[0] = exepath;
  args[1] = "spawn_helper";
  args[2] = NULL;
  options.file = exepath;
  options.args = args;
  options.exit_cb = exit_cb;

  uv_pipe_init(loop, &out, 0);

  options.stdio = stdio;
  options.stdio_count = 2;
  options.stdio[0].flags = UV_IGNORE;
  options.stdio[1].flags = UV_CREATE_PIPE | UV_WRITABLE_PIPE;
  options.stdio[1].data.stream = (uv_stream_t*)&out;

  r = uv_spawn(loop, &process, &options);
  ASSERT(r == 0);

  process_open = 1;
  pipe_open = 1;
  output_used = 0;

  r = uv_read_start((uv_stream_t*) &out, on_alloc, on_read);
  ASSERT(r == 0);
}

