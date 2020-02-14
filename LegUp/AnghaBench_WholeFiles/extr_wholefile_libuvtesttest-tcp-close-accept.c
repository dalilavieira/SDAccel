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
typedef  int /*<<< orphan*/  uv_write_t ;
typedef  int /*<<< orphan*/  uv_tcp_t ;
struct TYPE_17__ {int /*<<< orphan*/ * loop; } ;
typedef  TYPE_1__ uv_stream_t ;
typedef  int /*<<< orphan*/  uv_loop_t ;
typedef  int /*<<< orphan*/  uv_handle_t ;
typedef  int /*<<< orphan*/  uv_connect_t ;
struct TYPE_18__ {char* base; int len; } ;
typedef  TYPE_2__ uv_buf_t ;
struct sockaddr {int dummy; } ;
typedef  int ssize_t ;
typedef  int /*<<< orphan*/  slab ;

/* Variables and functions */
 unsigned int ARRAY_SIZE (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  ASSERT (int) ; 
 int /*<<< orphan*/  addr ; 
 int /*<<< orphan*/  close_cb_called ; 
 int /*<<< orphan*/ * connect_reqs ; 
 size_t got_connections ; 
 size_t pending_incoming ; 
 int /*<<< orphan*/  read_cb_called ; 
 int /*<<< orphan*/  tcp_check ; 
 int /*<<< orphan*/  tcp_check_req ; 
 int /*<<< orphan*/ * tcp_incoming ; 
 int /*<<< orphan*/ * tcp_outgoing ; 
 int /*<<< orphan*/  tcp_server ; 
 scalar_t__ uv_accept (TYPE_1__*,TYPE_1__*) ; 
 TYPE_2__ uv_buf_init (char*,int) ; 
 int /*<<< orphan*/  uv_close (int /*<<< orphan*/ *,...) ; 
 int /*<<< orphan*/  uv_is_closing (int /*<<< orphan*/ *) ; 
 scalar_t__ uv_read_start (TYPE_1__*,void (*) (int /*<<< orphan*/ *,size_t,TYPE_2__*),void (*) (TYPE_1__*,int,TYPE_2__ const*)) ; 
 scalar_t__ uv_read_stop (TYPE_1__*) ; 
 scalar_t__ uv_tcp_connect (int /*<<< orphan*/ *,int /*<<< orphan*/ *,struct sockaddr const*,void (*) (int /*<<< orphan*/ *,int)) ; 
 scalar_t__ uv_tcp_init (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 scalar_t__ uv_write (int /*<<< orphan*/ *,TYPE_1__*,TYPE_2__*,int,void (*) (int /*<<< orphan*/ *,int)) ; 
 int /*<<< orphan*/  write_cb_called ; 
 int /*<<< orphan*/ * write_reqs ; 

__attribute__((used)) static void close_walk_cb(uv_handle_t* handle, void* arg) {
  if (!uv_is_closing(handle))
    uv_close(handle, NULL);
}

__attribute__((used)) static void close_cb(uv_handle_t* handle) {
  close_cb_called++;
}

__attribute__((used)) static void write_cb(uv_write_t* req, int status) {
  ASSERT(status == 0);
  write_cb_called++;
}

__attribute__((used)) static void connect_cb(uv_connect_t* req, int status) {
  unsigned int i;
  uv_buf_t buf;
  uv_stream_t* outgoing;

  if (req == &tcp_check_req) {
    ASSERT(status != 0);

    /*
     * Time to finish the test: close both the check and pending incoming
     * connections
     */
    uv_close((uv_handle_t*) &tcp_incoming[pending_incoming], close_cb);
    uv_close((uv_handle_t*) &tcp_check, close_cb);
    return;
  }

  ASSERT(status == 0);
  ASSERT(connect_reqs <= req);
  ASSERT(req <= connect_reqs + ARRAY_SIZE(connect_reqs));
  i = req - connect_reqs;

  buf = uv_buf_init("x", 1);
  outgoing = (uv_stream_t*) &tcp_outgoing[i];
  ASSERT(0 == uv_write(&write_reqs[i], outgoing, &buf, 1, write_cb));
}

__attribute__((used)) static void alloc_cb(uv_handle_t* handle, size_t size, uv_buf_t* buf) {
  static char slab[1];
  buf->base = slab;
  buf->len = sizeof(slab);
}

__attribute__((used)) static void read_cb(uv_stream_t* stream, ssize_t nread, const uv_buf_t* buf) {
  uv_loop_t* loop;
  unsigned int i;

  pending_incoming = (uv_tcp_t*) stream - &tcp_incoming[0];
  ASSERT(pending_incoming < got_connections);
  ASSERT(0 == uv_read_stop(stream));
  ASSERT(1 == nread);

  loop = stream->loop;
  read_cb_called++;

  /* Close all active incomings, except current one */
  for (i = 0; i < got_connections; i++) {
    if (i != pending_incoming)
      uv_close((uv_handle_t*) &tcp_incoming[i], close_cb);
  }

  /* Close server, so no one will connect to it */
  uv_close((uv_handle_t*) &tcp_server, close_cb);

  /* Create new fd that should be one of the closed incomings */
  ASSERT(0 == uv_tcp_init(loop, &tcp_check));
  ASSERT(0 == uv_tcp_connect(&tcp_check_req,
                             &tcp_check,
                             (const struct sockaddr*) &addr,
                             connect_cb));
  ASSERT(0 == uv_read_start((uv_stream_t*) &tcp_check, alloc_cb, read_cb));
}

__attribute__((used)) static void connection_cb(uv_stream_t* server, int status) {
  unsigned int i;
  uv_tcp_t* incoming;

  ASSERT(server == (uv_stream_t*) &tcp_server);

  /* Ignore tcp_check connection */
  if (got_connections == ARRAY_SIZE(tcp_incoming))
    return;

  /* Accept everyone */
  incoming = &tcp_incoming[got_connections++];
  ASSERT(0 == uv_tcp_init(server->loop, incoming));
  ASSERT(0 == uv_accept(server, (uv_stream_t*) incoming));

  if (got_connections != ARRAY_SIZE(tcp_incoming))
    return;

  /* Once all clients are accepted - start reading */
  for (i = 0; i < ARRAY_SIZE(tcp_incoming); i++) {
    incoming = &tcp_incoming[i];
    ASSERT(0 == uv_read_start((uv_stream_t*) incoming, alloc_cb, read_cb));
  }
}

