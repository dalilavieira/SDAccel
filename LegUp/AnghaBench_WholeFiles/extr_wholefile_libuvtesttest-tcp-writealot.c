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
typedef  int /*<<< orphan*/  uv_write_t ;
struct TYPE_17__ {scalar_t__ write_queue_size; } ;
typedef  TYPE_1__ uv_tcp_t ;
typedef  int /*<<< orphan*/  uv_stream_t ;
struct TYPE_18__ {scalar_t__ handle; } ;
typedef  TYPE_2__ uv_shutdown_t ;
typedef  int /*<<< orphan*/  uv_handle_t ;
struct TYPE_19__ {int /*<<< orphan*/ * handle; } ;
typedef  TYPE_3__ uv_connect_t ;
struct TYPE_20__ {size_t len; int /*<<< orphan*/  base; } ;
typedef  TYPE_4__ uv_buf_t ;
typedef  scalar_t__ ssize_t ;

/* Variables and functions */
 int /*<<< orphan*/  ASSERT (int) ; 
 int CHUNKS_PER_WRITE ; 
 int CHUNK_SIZE ; 
 scalar_t__ UV_EOF ; 
 int WRITES ; 
 int /*<<< orphan*/  bytes_received_done ; 
 scalar_t__ bytes_sent ; 
 int bytes_sent_done ; 
 int /*<<< orphan*/  close_cb_called ; 
 int /*<<< orphan*/  connect_cb_called ; 
 TYPE_3__ connect_req ; 
 int /*<<< orphan*/  fprintf (int /*<<< orphan*/ ,char*,char*) ; 
 int /*<<< orphan*/  free (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  malloc (size_t) ; 
 int /*<<< orphan*/  printf (char*) ; 
 scalar_t__ send_buffer ; 
 int /*<<< orphan*/  shutdown_cb_called ; 
 TYPE_2__ shutdown_req ; 
 int /*<<< orphan*/  stderr ; 
 TYPE_4__ uv_buf_init (scalar_t__,int) ; 
 int /*<<< orphan*/  uv_close (int /*<<< orphan*/ *,...) ; 
 int /*<<< orphan*/  uv_is_closing (int /*<<< orphan*/ *) ; 
 int uv_read_start (int /*<<< orphan*/ *,void (*) (int /*<<< orphan*/ *,size_t,TYPE_4__*),void (*) (int /*<<< orphan*/ *,scalar_t__,TYPE_4__ const*)) ; 
 int uv_shutdown (TYPE_2__*,int /*<<< orphan*/ *,void (*) (TYPE_2__*,int)) ; 
 char* uv_strerror (int) ; 
 int uv_write (int /*<<< orphan*/ *,int /*<<< orphan*/ *,TYPE_4__*,int,void (*) (int /*<<< orphan*/ *,int)) ; 
 int write_cb_called ; 
 int /*<<< orphan*/ * write_reqs ; 

__attribute__((used)) static void close_walk_cb(uv_handle_t* handle, void* arg) {
  if (!uv_is_closing(handle))
    uv_close(handle, NULL);
}

__attribute__((used)) static void alloc_cb(uv_handle_t* handle, size_t size, uv_buf_t* buf) {
  buf->base = malloc(size);
  buf->len = size;
}

__attribute__((used)) static void close_cb(uv_handle_t* handle) {
  ASSERT(handle != NULL);
  close_cb_called++;
}

__attribute__((used)) static void shutdown_cb(uv_shutdown_t* req, int status) {
  uv_tcp_t* tcp;

  ASSERT(req == &shutdown_req);
  ASSERT(status == 0);

  tcp = (uv_tcp_t*)(req->handle);

  /* The write buffer should be empty by now. */
  ASSERT(tcp->write_queue_size == 0);

  /* Now we wait for the EOF */
  shutdown_cb_called++;

  /* We should have had all the writes called already. */
  ASSERT(write_cb_called == WRITES);
}

__attribute__((used)) static void read_cb(uv_stream_t* tcp, ssize_t nread, const uv_buf_t* buf) {
  ASSERT(tcp != NULL);

  if (nread >= 0) {
    bytes_received_done += nread;
  }
  else {
    ASSERT(nread == UV_EOF);
    printf("GOT EOF\n");
    uv_close((uv_handle_t*)tcp, close_cb);
  }

  free(buf->base);
}

__attribute__((used)) static void write_cb(uv_write_t* req, int status) {
  ASSERT(req != NULL);

  if (status) {
    fprintf(stderr, "uv_write error: %s\n", uv_strerror(status));
    ASSERT(0);
  }

  bytes_sent_done += CHUNKS_PER_WRITE * CHUNK_SIZE;
  write_cb_called++;
}

__attribute__((used)) static void connect_cb(uv_connect_t* req, int status) {
  uv_buf_t send_bufs[CHUNKS_PER_WRITE];
  uv_stream_t* stream;
  int i, j, r;

  ASSERT(req == &connect_req);
  ASSERT(status == 0);

  stream = req->handle;
  connect_cb_called++;

  /* Write a lot of data */
  for (i = 0; i < WRITES; i++) {
    uv_write_t* write_req = write_reqs + i;

    for (j = 0; j < CHUNKS_PER_WRITE; j++) {
      send_bufs[j] = uv_buf_init(send_buffer + bytes_sent, CHUNK_SIZE);
      bytes_sent += CHUNK_SIZE;
    }

    r = uv_write(write_req, stream, send_bufs, CHUNKS_PER_WRITE, write_cb);
    ASSERT(r == 0);
  }

  /* Shutdown on drain. */
  r = uv_shutdown(&shutdown_req, stream, shutdown_cb);
  ASSERT(r == 0);

  /* Start reading */
  r = uv_read_start(stream, alloc_cb, read_cb);
  ASSERT(r == 0);
}

