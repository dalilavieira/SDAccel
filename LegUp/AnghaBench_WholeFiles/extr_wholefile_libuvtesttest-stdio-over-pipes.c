#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_12__   TYPE_6__ ;
typedef  struct TYPE_11__   TYPE_1__ ;

/* Type definitions */
typedef  char uv_write_t ;
typedef  int /*<<< orphan*/  uv_stream_t ;
typedef  int /*<<< orphan*/  uv_process_t ;
typedef  int /*<<< orphan*/  uv_loop_t ;
typedef  int /*<<< orphan*/  uv_handle_t ;
typedef  int /*<<< orphan*/  uv_exit_cb ;
struct TYPE_11__ {char* base; size_t len; } ;
typedef  TYPE_1__ uv_buf_t ;
typedef  scalar_t__ ssize_t ;
typedef  scalar_t__ int64_t ;
struct TYPE_12__ {char* file; char** args; int /*<<< orphan*/  exit_cb; } ;

/* Variables and functions */
 unsigned int ARRAY_SIZE (char**) ; 
 int /*<<< orphan*/  ASSERT (int) ; 
 int /*<<< orphan*/  MAKE_VALGRIND_HAPPY () ; 
 size_t OUTPUT_SIZE ; 
 scalar_t__ UV_EOF ; 
 scalar_t__ UV_NAMED_PIPE ; 
 int /*<<< orphan*/  UV_RUN_DEFAULT ; 
 int after_write_called ; 
 int /*<<< orphan*/  after_write_cb_called ; 
 char** args ; 
 int close_cb_called ; 
 char* exepath ; 
 size_t exepath_size ; 
 int /*<<< orphan*/  exit_cb_called ; 
 int /*<<< orphan*/  fprintf (int /*<<< orphan*/ ,char*,char*) ; 
 int /*<<< orphan*/  free (char*) ; 
 int /*<<< orphan*/  in ; 
 void* malloc (size_t) ; 
 scalar_t__ memcmp (char*,char*,scalar_t__) ; 
 int /*<<< orphan*/  notify_parent_process () ; 
 int on_pipe_read_called ; 
 int /*<<< orphan*/  on_read_cb_called ; 
 TYPE_6__ options ; 
 int /*<<< orphan*/  out ; 
 char* output ; 
 int output_used ; 
 int /*<<< orphan*/  printf (char*) ; 
 int /*<<< orphan*/  stderr ; 
 int /*<<< orphan*/  stdin_pipe ; 
 int /*<<< orphan*/  stdout_pipe ; 
 int strlen (char*) ; 
 TYPE_1__ uv_buf_init (char*,int) ; 
 int /*<<< orphan*/  uv_close (int /*<<< orphan*/ *,...) ; 
 int /*<<< orphan*/ * uv_default_loop () ; 
 int uv_exepath (char*,size_t*) ; 
 scalar_t__ uv_guess_handle (int) ; 
 int /*<<< orphan*/  uv_is_closing (int /*<<< orphan*/ *) ; 
 int uv_pipe_init (int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  uv_pipe_open (int /*<<< orphan*/ *,int) ; 
 int uv_read_start (int /*<<< orphan*/ *,void (*) (int /*<<< orphan*/ *,size_t,TYPE_1__*),void (*) (int /*<<< orphan*/ *,scalar_t__,TYPE_1__ const*)) ; 
 int /*<<< orphan*/  uv_ref (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  uv_run (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 char* uv_strerror (int) ; 
 int /*<<< orphan*/  uv_unref (int /*<<< orphan*/ *) ; 
 int uv_write (char*,int /*<<< orphan*/ *,TYPE_1__*,int,void (*) (char*,int)) ; 

__attribute__((used)) static void close_walk_cb(uv_handle_t* handle, void* arg) {
  if (!uv_is_closing(handle))
    uv_close(handle, NULL);
}

__attribute__((used)) static void close_cb(uv_handle_t* handle) {
  close_cb_called++;
}

__attribute__((used)) static void exit_cb(uv_process_t* process,
                    int64_t exit_status,
                    int term_signal) {
  printf("exit_cb\n");
  exit_cb_called++;
  ASSERT(exit_status == 0);
  ASSERT(term_signal == 0);
  uv_close((uv_handle_t*)process, close_cb);
  uv_close((uv_handle_t*)&in, close_cb);
  uv_close((uv_handle_t*)&out, close_cb);
}

__attribute__((used)) static void init_process_options(char* test, uv_exit_cb exit_cb) {
  int r = uv_exepath(exepath, &exepath_size);
  ASSERT(r == 0);
  exepath[exepath_size] = '\0';
  args[0] = exepath;
  args[1] = test;
  args[2] = NULL;
  options.file = exepath;
  options.args = args;
  options.exit_cb = exit_cb;
}

__attribute__((used)) static void on_alloc(uv_handle_t* handle,
                     size_t suggested_size,
                     uv_buf_t* buf) {
  buf->base = output + output_used;
  buf->len = OUTPUT_SIZE - output_used;
}

__attribute__((used)) static void after_write(uv_write_t* req, int status) {
  if (status) {
    fprintf(stderr, "uv_write error: %s\n", uv_strerror(status));
    ASSERT(0);
  }

  /* Free the read/write buffer and the request */
  free(req);

  after_write_cb_called++;
}

__attribute__((used)) static void on_read(uv_stream_t* tcp, ssize_t nread, const uv_buf_t* rdbuf) {
  uv_write_t* req;
  uv_buf_t wrbuf;
  int r;

  ASSERT(nread > 0 || nread == UV_EOF);

  if (nread > 0) {
    output_used += nread;
    if (output_used == 12) {
      ASSERT(memcmp("hello world\n", output, 12) == 0);
      wrbuf = uv_buf_init(output, output_used);
      req = malloc(sizeof(*req));
      r = uv_write(req, (uv_stream_t*)&in, &wrbuf, 1, after_write);
      ASSERT(r == 0);
    }
  }

  on_read_cb_called++;
}

__attribute__((used)) static void on_pipe_read(uv_stream_t* tcp, ssize_t nread, const uv_buf_t* buf) {
  ASSERT(nread > 0);
  ASSERT(memcmp("hello world\n", buf->base, nread) == 0);
  on_pipe_read_called++;

  free(buf->base);

  uv_close((uv_handle_t*)&stdin_pipe, close_cb);
  uv_close((uv_handle_t*)&stdout_pipe, close_cb);
}

__attribute__((used)) static void after_pipe_write(uv_write_t* req, int status) {
  ASSERT(status == 0);
  after_write_called++;
}

__attribute__((used)) static void on_read_alloc(uv_handle_t* handle,
                          size_t suggested_size,
                          uv_buf_t* buf) {
  buf->base = malloc(suggested_size);
  buf->len = suggested_size;
}

int stdio_over_pipes_helper(void) {
  /* Write several buffers to test that the write order is preserved. */
  char* buffers[] = {
    "he",
    "ll",
    "o ",
    "wo",
    "rl",
    "d",
    "\n"
  };

  uv_write_t write_req[ARRAY_SIZE(buffers)];
  uv_buf_t buf[ARRAY_SIZE(buffers)];
  unsigned int i;
  int r;
  uv_loop_t* loop = uv_default_loop();

  ASSERT(UV_NAMED_PIPE == uv_guess_handle(0));
  ASSERT(UV_NAMED_PIPE == uv_guess_handle(1));

  r = uv_pipe_init(loop, &stdin_pipe, 0);
  ASSERT(r == 0);
  r = uv_pipe_init(loop, &stdout_pipe, 0);
  ASSERT(r == 0);

  uv_pipe_open(&stdin_pipe, 0);
  uv_pipe_open(&stdout_pipe, 1);

  /* Unref both stdio handles to make sure that all writes complete. */
  uv_unref((uv_handle_t*)&stdin_pipe);
  uv_unref((uv_handle_t*)&stdout_pipe);

  for (i = 0; i < ARRAY_SIZE(buffers); i++) {
    buf[i] = uv_buf_init((char*)buffers[i], strlen(buffers[i]));
  }

  for (i = 0; i < ARRAY_SIZE(buffers); i++) {
    r = uv_write(&write_req[i], (uv_stream_t*)&stdout_pipe, &buf[i], 1,
      after_pipe_write);
    ASSERT(r == 0);
  }

  notify_parent_process();
  uv_run(loop, UV_RUN_DEFAULT);

  ASSERT(after_write_called == 7);
  ASSERT(on_pipe_read_called == 0);
  ASSERT(close_cb_called == 0);

  uv_ref((uv_handle_t*)&stdout_pipe);
  uv_ref((uv_handle_t*)&stdin_pipe);

  r = uv_read_start((uv_stream_t*)&stdin_pipe, on_read_alloc, on_pipe_read);
  ASSERT(r == 0);

  uv_run(loop, UV_RUN_DEFAULT);

  ASSERT(after_write_called == 7);
  ASSERT(on_pipe_read_called == 1);
  ASSERT(close_cb_called == 2);

  MAKE_VALGRIND_HAPPY();
  return 0;
}

