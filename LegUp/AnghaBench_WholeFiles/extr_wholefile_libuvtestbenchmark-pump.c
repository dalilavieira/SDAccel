#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_20__   TYPE_4__ ;
typedef  struct TYPE_19__   TYPE_3__ ;
typedef  struct TYPE_18__   TYPE_2__ ;
typedef  struct TYPE_17__   TYPE_1__ ;

/* Type definitions */
struct TYPE_17__ {scalar_t__ handle; } ;
typedef  TYPE_1__ uv_write_t ;
typedef  int /*<<< orphan*/  uv_timer_t ;
typedef  int /*<<< orphan*/  uv_tcp_t ;
typedef  int /*<<< orphan*/  uv_stream_t ;
typedef  int /*<<< orphan*/  uv_req_t ;
typedef  int /*<<< orphan*/  uv_pipe_t ;
typedef  int /*<<< orphan*/  uv_handle_t ;
typedef  int /*<<< orphan*/  uv_connect_t ;
struct TYPE_18__ {char* base; int len; } ;
typedef  TYPE_2__ uv_buf_t ;
struct sockaddr {int dummy; } ;
typedef  scalar_t__ ssize_t ;
struct TYPE_19__ {struct TYPE_19__* next; } ;
typedef  TYPE_3__ req_list_t ;
typedef  int int64_t ;
struct TYPE_20__ {struct TYPE_20__* next; TYPE_2__ uv_buf_t; } ;
typedef  TYPE_4__ buf_list_t ;

/* Variables and functions */
 int /*<<< orphan*/  ASSERT (int) ; 
 int /*<<< orphan*/  MAKE_VALGRIND_HAPPY () ; 
 int MAX_SIMULTANEOUS_CONNECTS ; 
 int MAX_WRITE_HANDLES ; 
 scalar_t__ PIPE ; 
 scalar_t__ STATS_COUNT ; 
 int /*<<< orphan*/  STATS_INTERVAL ; 
 int TARGET_CONNECTIONS ; 
 scalar_t__ TCP ; 
 int /*<<< orphan*/  TEST_PIPENAME ; 
 int /*<<< orphan*/  TEST_PORT ; 
 int /*<<< orphan*/  UV_RUN_DEFAULT ; 
static  void buf_alloc (int /*<<< orphan*/ *,size_t,TYPE_2__*) ; 
static  void buf_free (TYPE_2__ const*) ; 
 TYPE_4__* buf_freelist ; 
 int /*<<< orphan*/  connect_addr ; 
static  void do_write (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  exit (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  fflush (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  fprintf (int /*<<< orphan*/ ,char*,char*,...) ; 
 int /*<<< orphan*/  free (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  loop ; 
 TYPE_4__* malloc (size_t) ; 
 int max_connect_socket ; 
 int max_read_sockets ; 
static  void maybe_connect_some () ; 
 scalar_t__ nrecv ; 
 scalar_t__ nrecv_total ; 
 scalar_t__ nsent ; 
 int nsent_total ; 
 int /*<<< orphan*/ * pipe_write_handles ; 
 scalar_t__ read_sockets ; 
static  int /*<<< orphan*/ * req_alloc () ; 
static  void req_free (int /*<<< orphan*/ *) ; 
 TYPE_3__* req_freelist ; 
 int /*<<< orphan*/ * server ; 
 int start_time ; 
 scalar_t__ stats_left ; 
 int /*<<< orphan*/  stderr ; 
 int /*<<< orphan*/ * tcp_write_handles ; 
 int /*<<< orphan*/  timer_handle ; 
 scalar_t__ type ; 
 int uv_accept (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  uv_close (int /*<<< orphan*/ *,...) ; 
 int /*<<< orphan*/  uv_default_loop () ; 
 scalar_t__ uv_ip4_addr (char*,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  uv_is_closing (int /*<<< orphan*/ *) ; 
 int uv_now (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  uv_pipe_connect (int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ ,void (*) (int /*<<< orphan*/ *,int)) ; 
 int uv_pipe_init (int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int uv_read_start (int /*<<< orphan*/ *,void (*) (int /*<<< orphan*/ *,size_t,TYPE_2__*),void (*) (int /*<<< orphan*/ *,scalar_t__,TYPE_2__ const*)) ; 
 int /*<<< orphan*/  uv_run (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 char* uv_strerror (int) ; 
 int uv_tcp_connect (int /*<<< orphan*/ *,int /*<<< orphan*/ *,struct sockaddr const*,void (*) (int /*<<< orphan*/ *,int)) ; 
 int uv_tcp_init (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int uv_timer_init (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int uv_timer_start (int /*<<< orphan*/ *,void (*) (int /*<<< orphan*/ *),int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  uv_update_time (int /*<<< orphan*/ ) ; 
 int uv_write (TYPE_1__*,int /*<<< orphan*/ *,TYPE_2__*,int,void (*) (TYPE_1__*,int)) ; 
 int /*<<< orphan*/  write_buffer ; 
 int write_sockets ; 

__attribute__((used)) static void close_walk_cb(uv_handle_t* handle, void* arg) {
  if (!uv_is_closing(handle))
    uv_close(handle, NULL);
}

__attribute__((used)) static double gbit(int64_t bytes, int64_t passed_ms) {
  double gbits = ((double)bytes / (1024 * 1024 * 1024)) * 8;
  return gbits / ((double)passed_ms / 1000);
}

__attribute__((used)) static void show_stats(uv_timer_t* handle) {
  int64_t diff;
  int i;

#if PRINT_STATS
  fprintf(stderr, "connections: %d, write: %.1f gbit/s\n",
          write_sockets,
          gbit(nsent, STATS_INTERVAL));
  fflush(stderr);
#endif

  /* Exit if the show is over */
  if (!--stats_left) {

    uv_update_time(loop);
    diff = uv_now(loop) - start_time;

    fprintf(stderr, "%s_pump%d_client: %.1f gbit/s\n",
            type == TCP ? "tcp" : "pipe",
            write_sockets,
            gbit(nsent_total, diff));
    fflush(stderr);

    for (i = 0; i < write_sockets; i++) {
      if (type == TCP)
        uv_close((uv_handle_t*) &tcp_write_handles[i], NULL);
      else
        uv_close((uv_handle_t*) &pipe_write_handles[i], NULL);
    }

    exit(0);
  }

  /* Reset read and write counters */
  nrecv = 0;
  nsent = 0;
}

__attribute__((used)) static void read_show_stats(void) {
  int64_t diff;

  uv_update_time(loop);
  diff = uv_now(loop) - start_time;

  fprintf(stderr, "%s_pump%d_server: %.1f gbit/s\n",
          type == TCP ? "tcp" : "pipe",
          max_read_sockets,
          gbit(nrecv_total, diff));
  fflush(stderr);
}

__attribute__((used)) static void read_sockets_close_cb(uv_handle_t* handle) {
  free(handle);
  read_sockets--;

  /* If it's past the first second and everyone has closed their connection
   * Then print stats.
   */
  if (uv_now(loop) - start_time > 1000 && read_sockets == 0) {
    read_show_stats();
    uv_close((uv_handle_t*)server, NULL);
  }
}

__attribute__((used)) static void start_stats_collection(void) {
  int r;

  /* Show-stats timer */
  stats_left = STATS_COUNT;
  r = uv_timer_init(loop, &timer_handle);
  ASSERT(r == 0);
  r = uv_timer_start(&timer_handle, show_stats, STATS_INTERVAL, STATS_INTERVAL);
  ASSERT(r == 0);

  uv_update_time(loop);
  start_time = uv_now(loop);
}

__attribute__((used)) static void read_cb(uv_stream_t* stream, ssize_t bytes, const uv_buf_t* buf) {
  if (nrecv_total == 0) {
    ASSERT(start_time == 0);
    uv_update_time(loop);
    start_time = uv_now(loop);
  }

  if (bytes < 0) {
    uv_close((uv_handle_t*)stream, read_sockets_close_cb);
    return;
  }

  buf_free(buf);

  nrecv += bytes;
  nrecv_total += bytes;
}

__attribute__((used)) static void write_cb(uv_write_t* req, int status) {
  ASSERT(status == 0);

  req_free((uv_req_t*) req);

  nsent += sizeof write_buffer;
  nsent_total += sizeof write_buffer;

  do_write((uv_stream_t*) req->handle);
}

__attribute__((used)) static void do_write(uv_stream_t* stream) {
  uv_write_t* req;
  uv_buf_t buf;
  int r;

  buf.base = (char*) &write_buffer;
  buf.len = sizeof write_buffer;

  req = (uv_write_t*) req_alloc();
  r = uv_write(req, stream, &buf, 1, write_cb);
  ASSERT(r == 0);
}

__attribute__((used)) static void connect_cb(uv_connect_t* req, int status) {
  int i;

  if (status) {
    fprintf(stderr, "%s", uv_strerror(status));
    fflush(stderr);
  }
  ASSERT(status == 0);

  write_sockets++;
  req_free((uv_req_t*) req);

  maybe_connect_some();

  if (write_sockets == TARGET_CONNECTIONS) {
    start_stats_collection();

    /* Yay! start writing */
    for (i = 0; i < write_sockets; i++) {
      if (type == TCP)
        do_write((uv_stream_t*) &tcp_write_handles[i]);
      else
        do_write((uv_stream_t*) &pipe_write_handles[i]);
    }
  }
}

__attribute__((used)) static void maybe_connect_some(void) {
  uv_connect_t* req;
  uv_tcp_t* tcp;
  uv_pipe_t* pipe;
  int r;

  while (max_connect_socket < TARGET_CONNECTIONS &&
         max_connect_socket < write_sockets + MAX_SIMULTANEOUS_CONNECTS) {
    if (type == TCP) {
      tcp = &tcp_write_handles[max_connect_socket++];

      r = uv_tcp_init(loop, tcp);
      ASSERT(r == 0);

      req = (uv_connect_t*) req_alloc();
      r = uv_tcp_connect(req,
                         tcp,
                         (const struct sockaddr*) &connect_addr,
                         connect_cb);
      ASSERT(r == 0);
    } else {
      pipe = &pipe_write_handles[max_connect_socket++];

      r = uv_pipe_init(loop, pipe, 0);
      ASSERT(r == 0);

      req = (uv_connect_t*) req_alloc();
      uv_pipe_connect(req, pipe, TEST_PIPENAME, connect_cb);
    }
  }
}

__attribute__((used)) static void connection_cb(uv_stream_t* s, int status) {
  uv_stream_t* stream;
  int r;

  ASSERT(server == s);
  ASSERT(status == 0);

  if (type == TCP) {
    stream = (uv_stream_t*)malloc(sizeof(uv_tcp_t));
    r = uv_tcp_init(loop, (uv_tcp_t*)stream);
    ASSERT(r == 0);
  } else {
    stream = (uv_stream_t*)malloc(sizeof(uv_pipe_t));
    r = uv_pipe_init(loop, (uv_pipe_t*)stream, 0);
    ASSERT(r == 0);
  }

  r = uv_accept(s, stream);
  ASSERT(r == 0);

  r = uv_read_start(stream, buf_alloc, read_cb);
  ASSERT(r == 0);

  read_sockets++;
  max_read_sockets++;
}

__attribute__((used)) static uv_req_t* req_alloc(void) {
  req_list_t* req;

  req = req_freelist;
  if (req != NULL) {
    req_freelist = req->next;
    return (uv_req_t*) req;
  }

  req = (req_list_t*) malloc(sizeof *req);
  return (uv_req_t*) req;
}

__attribute__((used)) static void req_free(uv_req_t* uv_req) {
  req_list_t* req = (req_list_t*) uv_req;

  req->next = req_freelist;
  req_freelist = req;
}

__attribute__((used)) static void buf_alloc(uv_handle_t* handle, size_t size, uv_buf_t* buf) {
  buf_list_t* ab;

  ab = buf_freelist;
  if (ab != NULL)
    buf_freelist = ab->next;
  else {
    ab = malloc(size + sizeof(*ab));
    ab->uv_buf_t.len = size;
    ab->uv_buf_t.base = (char*) (ab + 1);
  }

  *buf = ab->uv_buf_t;
}

__attribute__((used)) static void buf_free(const uv_buf_t* buf) {
  buf_list_t* ab = (buf_list_t*) buf->base - 1;
  ab->next = buf_freelist;
  buf_freelist = ab;
}

__attribute__((used)) static void tcp_pump(int n) {
  ASSERT(n <= MAX_WRITE_HANDLES);
  TARGET_CONNECTIONS = n;
  type = TCP;

  loop = uv_default_loop();

  ASSERT(0 == uv_ip4_addr("127.0.0.1", TEST_PORT, &connect_addr));

  /* Start making connections */
  maybe_connect_some();

  uv_run(loop, UV_RUN_DEFAULT);

  MAKE_VALGRIND_HAPPY();
}

__attribute__((used)) static void pipe_pump(int n) {
  ASSERT(n <= MAX_WRITE_HANDLES);
  TARGET_CONNECTIONS = n;
  type = PIPE;

  loop = uv_default_loop();

  /* Start making connections */
  maybe_connect_some();

  uv_run(loop, UV_RUN_DEFAULT);

  MAKE_VALGRIND_HAPPY();
}

