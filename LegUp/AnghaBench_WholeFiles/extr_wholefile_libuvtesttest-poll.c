#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_30__   TYPE_6__ ;
typedef  struct TYPE_29__   TYPE_4__ ;
typedef  struct TYPE_28__   TYPE_3__ ;
typedef  struct TYPE_27__   TYPE_2__ ;
typedef  struct TYPE_26__   TYPE_1__ ;

/* Type definitions */
struct TYPE_26__ {scalar_t__ data; } ;
typedef  TYPE_1__ uv_timer_t ;
struct TYPE_27__ {TYPE_4__* data; } ;
typedef  TYPE_2__ uv_poll_t ;
typedef  scalar_t__ uv_os_sock_t ;
struct TYPE_28__ {scalar_t__ data; } ;
typedef  TYPE_3__ uv_handle_t ;
struct sockaddr_in {int dummy; } ;
struct sockaddr {int dummy; } ;
typedef  int socklen_t ;
struct TYPE_30__ {TYPE_4__* data; } ;
struct TYPE_29__ {scalar_t__ sock; int is_server_connection; scalar_t__ read; scalar_t__ sent; scalar_t__ open_handles; int events; int delayed_events; int got_fin; int sent_fin; int got_disconnect; int connections; TYPE_2__ poll_handle; TYPE_6__ timer_handle; } ;
typedef  TYPE_4__ server_context_t ;
typedef  TYPE_4__ connection_context_t ;

/* Variables and functions */
 int /*<<< orphan*/  AF_INET ; 
 int /*<<< orphan*/  ASSERT (int) ; 
 scalar_t__ DUPLEX ; 
 scalar_t__ EAGAIN ; 
 scalar_t__ ECONNRESET ; 
 scalar_t__ EINPROGRESS ; 
 int /*<<< orphan*/  IPPROTO_IP ; 
 int /*<<< orphan*/  MAKE_VALGRIND_HAPPY () ; 
 int MIN (scalar_t__,int) ; 
 int NUM_CLIENTS ; 
 int /*<<< orphan*/  SHUT_WR ; 
 int /*<<< orphan*/  SOCK_STREAM ; 
 int /*<<< orphan*/  SOL_SOCKET ; 
 int /*<<< orphan*/  SO_REUSEADDR ; 
 int /*<<< orphan*/  TEST_PORT ; 
 scalar_t__ TRANSFER_BYTES ; 
 scalar_t__ UNIDIRECTIONAL ; 
 int UV_DISCONNECT ; 
 int UV_READABLE ; 
 int /*<<< orphan*/  UV_RUN_DEFAULT ; 
 int UV_WRITABLE ; 
 scalar_t__ accept (scalar_t__,struct sockaddr*,int*) ; 
 int bind (scalar_t__,struct sockaddr const*,int) ; 
 int close (scalar_t__) ; 
 int closed_connections ; 
 int connect (scalar_t__,struct sockaddr*,int) ; 
static  void delay_timer_cb (TYPE_1__*) ; 
 int disconnects ; 
 scalar_t__ errno ; 
 int /*<<< orphan*/  free (TYPE_4__*) ; 
 int listen (scalar_t__,int) ; 
 scalar_t__ malloc (int) ; 
 int rand () ; 
 int recv (scalar_t__,char*,int,int /*<<< orphan*/ ) ; 
 int send (scalar_t__,char*,int,int /*<<< orphan*/ ) ; 
 int setsockopt (scalar_t__,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int*,int) ; 
 int shutdown (scalar_t__,int /*<<< orphan*/ ) ; 
 scalar_t__ socket (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int spurious_writable_wakeups ; 
 scalar_t__ test_mode ; 
 int /*<<< orphan*/  uv_close (TYPE_3__*,...) ; 
 int /*<<< orphan*/  uv_default_loop () ; 
 scalar_t__ uv_ip4_addr (char*,int /*<<< orphan*/ ,struct sockaddr_in*) ; 
 scalar_t__ uv_is_active (TYPE_3__*) ; 
 int /*<<< orphan*/  uv_is_closing (TYPE_3__*) ; 
 int uv_poll_init_socket (int /*<<< orphan*/ ,TYPE_2__*,scalar_t__) ; 
 int uv_poll_start (TYPE_2__*,int,void (*) (TYPE_2__*,int,int)) ; 
 int uv_run (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int uv_timer_init (int /*<<< orphan*/ ,TYPE_6__*) ; 
 int /*<<< orphan*/  uv_timer_start (TYPE_6__*,void (*) (TYPE_1__*),int,int /*<<< orphan*/ ) ; 
 int valid_writable_wakeups ; 

__attribute__((used)) static void close_walk_cb(uv_handle_t* handle, void* arg) {
  if (!uv_is_closing(handle))
    uv_close(handle, NULL);
}

__attribute__((used)) static int got_eagain(void) {
#ifdef _WIN32
  return WSAGetLastError() == WSAEWOULDBLOCK;
#else
  return errno == EAGAIN
      || errno == EINPROGRESS
#ifdef EWOULDBLOCK
      || errno == EWOULDBLOCK;
#endif
      ;
#endif
}

__attribute__((used)) static uv_os_sock_t create_bound_socket (struct sockaddr_in bind_addr) {
  uv_os_sock_t sock;
  int r;

  sock = socket(AF_INET, SOCK_STREAM, IPPROTO_IP);
#ifdef _WIN32
  ASSERT(sock != INVALID_SOCKET);
#else
  ASSERT(sock >= 0);
#endif

#ifndef _WIN32
  {
    /* Allow reuse of the port. */
    int yes = 1;
    r = setsockopt(sock, SOL_SOCKET, SO_REUSEADDR, &yes, sizeof yes);
    ASSERT(r == 0);
  }
#endif

  r = bind(sock, (const struct sockaddr*) &bind_addr, sizeof bind_addr);
  ASSERT(r == 0);

  return sock;
}

__attribute__((used)) static void close_socket(uv_os_sock_t sock) {
  int r;
#ifdef _WIN32
  r = closesocket(sock);
#else
  r = close(sock);
#endif
  /* On FreeBSD close() can fail with ECONNRESET if the socket was shutdown by
   * the peer before all pending data was delivered.
   */
  ASSERT(r == 0 || errno == ECONNRESET);
}

__attribute__((used)) static connection_context_t* create_connection_context(
    uv_os_sock_t sock, int is_server_connection) {
  int r;
  connection_context_t* context;

  context = (connection_context_t*) malloc(sizeof *context);
  ASSERT(context != NULL);

  context->sock = sock;
  context->is_server_connection = is_server_connection;
  context->read = 0;
  context->sent = 0;
  context->open_handles = 0;
  context->events = 0;
  context->delayed_events = 0;
  context->got_fin = 0;
  context->sent_fin = 0;
  context->got_disconnect = 0;

  r = uv_poll_init_socket(uv_default_loop(), &context->poll_handle, sock);
  context->open_handles++;
  context->poll_handle.data = context;
  ASSERT(r == 0);

  r = uv_timer_init(uv_default_loop(), &context->timer_handle);
  context->open_handles++;
  context->timer_handle.data = context;
  ASSERT(r == 0);

  return context;
}

__attribute__((used)) static void connection_close_cb(uv_handle_t* handle) {
  connection_context_t* context = (connection_context_t*) handle->data;

  if (--context->open_handles == 0) {
    if (test_mode == DUPLEX || context->is_server_connection) {
      ASSERT(context->read == TRANSFER_BYTES);
    } else {
      ASSERT(context->read == 0);
    }

    if (test_mode == DUPLEX || !context->is_server_connection) {
      ASSERT(context->sent == TRANSFER_BYTES);
    } else {
      ASSERT(context->sent == 0);
    }

    closed_connections++;

    free(context);
  }
}

__attribute__((used)) static void destroy_connection_context(connection_context_t* context) {
  uv_close((uv_handle_t*) &context->poll_handle, connection_close_cb);
  uv_close((uv_handle_t*) &context->timer_handle, connection_close_cb);
}

__attribute__((used)) static void connection_poll_cb(uv_poll_t* handle, int status, int events) {
  connection_context_t* context = (connection_context_t*) handle->data;
  unsigned int new_events;
  int r;

  ASSERT(status == 0);
  ASSERT(events & context->events);
  ASSERT(!(events & ~context->events));

  new_events = context->events;

  if (events & UV_READABLE) {
    int action = rand() % 7;

    switch (action) {
      case 0:
      case 1: {
        /* Read a couple of bytes. */
        static char buffer[74];
        r = recv(context->sock, buffer, sizeof buffer, 0);
        ASSERT(r >= 0);

        if (r > 0) {
          context->read += r;
        } else {
          /* Got FIN. */
          context->got_fin = 1;
          new_events &= ~UV_READABLE;
        }

        break;
      }

      case 2:
      case 3: {
        /* Read until EAGAIN. */
        static char buffer[931];
        r = recv(context->sock, buffer, sizeof buffer, 0);
        ASSERT(r >= 0);

        while (r > 0) {
          context->read += r;
          r = recv(context->sock, buffer, sizeof buffer, 0);
        }

        if (r == 0) {
          /* Got FIN. */
          context->got_fin = 1;
          new_events &= ~UV_READABLE;
        } else {
          ASSERT(got_eagain());
        }

        break;
      }

      case 4:
        /* Ignore. */
        break;

      case 5:
        /* Stop reading for a while. Restart in timer callback. */
        new_events &= ~UV_READABLE;
        if (!uv_is_active((uv_handle_t*) &context->timer_handle)) {
          context->delayed_events = UV_READABLE;
          uv_timer_start(&context->timer_handle, delay_timer_cb, 10, 0);
        } else {
          context->delayed_events |= UV_READABLE;
        }
        break;

      case 6:
        /* Fudge with the event mask. */
        uv_poll_start(&context->poll_handle, UV_WRITABLE, connection_poll_cb);
        uv_poll_start(&context->poll_handle, UV_READABLE, connection_poll_cb);
        context->events = UV_READABLE;
        break;

      default:
        ASSERT(0);
    }
  }

  if (events & UV_WRITABLE) {
    if (context->sent < TRANSFER_BYTES &&
        !(test_mode == UNIDIRECTIONAL && context->is_server_connection)) {
      /* We have to send more bytes. */
      int action = rand() % 7;

      switch (action) {
        case 0:
        case 1: {
          /* Send a couple of bytes. */
          static char buffer[103];

          int send_bytes = MIN(TRANSFER_BYTES - context->sent, sizeof buffer);
          ASSERT(send_bytes > 0);

          r = send(context->sock, buffer, send_bytes, 0);

          if (r < 0) {
            ASSERT(got_eagain());
            spurious_writable_wakeups++;
            break;
          }

          ASSERT(r > 0);
          context->sent += r;
          valid_writable_wakeups++;
          break;
        }

        case 2:
        case 3: {
          /* Send until EAGAIN. */
          static char buffer[1234];

          int send_bytes = MIN(TRANSFER_BYTES - context->sent, sizeof buffer);
          ASSERT(send_bytes > 0);

          r = send(context->sock, buffer, send_bytes, 0);

          if (r < 0) {
            ASSERT(got_eagain());
            spurious_writable_wakeups++;
            break;
          }

          ASSERT(r > 0);
          valid_writable_wakeups++;
          context->sent += r;

          while (context->sent < TRANSFER_BYTES) {
            send_bytes = MIN(TRANSFER_BYTES - context->sent, sizeof buffer);
            ASSERT(send_bytes > 0);

            r = send(context->sock, buffer, send_bytes, 0);

            if (r <= 0) break;
            context->sent += r;
          }
          ASSERT(r > 0 || got_eagain());
          break;
        }

        case 4:
          /* Ignore. */
         break;

        case 5:
          /* Stop sending for a while. Restart in timer callback. */
          new_events &= ~UV_WRITABLE;
          if (!uv_is_active((uv_handle_t*) &context->timer_handle)) {
            context->delayed_events = UV_WRITABLE;
            uv_timer_start(&context->timer_handle, delay_timer_cb, 100, 0);
          } else {
            context->delayed_events |= UV_WRITABLE;
          }
          break;

        case 6:
          /* Fudge with the event mask. */
          uv_poll_start(&context->poll_handle,
                        UV_READABLE,
                        connection_poll_cb);
          uv_poll_start(&context->poll_handle,
                        UV_WRITABLE,
                        connection_poll_cb);
          context->events = UV_WRITABLE;
          break;

        default:
          ASSERT(0);
      }

    } else {
      /* Nothing more to write. Send FIN. */
      int r;
#ifdef _WIN32
      r = shutdown(context->sock, SD_SEND);
#else
      r = shutdown(context->sock, SHUT_WR);
#endif
      ASSERT(r == 0);
      context->sent_fin = 1;
      new_events &= ~UV_WRITABLE;
    }
  }
#if !defined(__sun) && !defined(_AIX) && !defined(__MVS__)
  if (events & UV_DISCONNECT) {
    context->got_disconnect = 1;
    ++disconnects;
    new_events &= ~UV_DISCONNECT;
  }

  if (context->got_fin && context->sent_fin && context->got_disconnect) {
#else /* __sun && _AIX  && __MVS__ */
  if (context->got_fin && context->sent_fin) {
#endif /* !__sun && !_AIX && !__MVS__  */
    /* Sent and received FIN. Close and destroy context. */
    close_socket(context->sock);
    destroy_connection_context(context);
    context->events = 0;

  } else if (new_events != context->events) {
    /* Poll mask changed. Call uv_poll_start again. */
    context->events = new_events;
    uv_poll_start(handle, new_events, connection_poll_cb);
  }

  /* Assert that uv_is_active works correctly for poll handles. */
  if (context->events != 0) {
    ASSERT(1 == uv_is_active((uv_handle_t*) handle));
  } else {
    ASSERT(0 == uv_is_active((uv_handle_t*) handle));
  }
}

__attribute__((used)) static void delay_timer_cb(uv_timer_t* timer) {
  connection_context_t* context = (connection_context_t*) timer->data;
  int r;

  /* Timer should auto stop. */
  ASSERT(0 == uv_is_active((uv_handle_t*) timer));

  /* Add the requested events to the poll mask. */
  ASSERT(context->delayed_events != 0);
  context->events |= context->delayed_events;
  context->delayed_events = 0;

  r = uv_poll_start(&context->poll_handle,
                    context->events,
                    connection_poll_cb);
  ASSERT(r == 0);
}

__attribute__((used)) static server_context_t* create_server_context(
    uv_os_sock_t sock) {
  int r;
  server_context_t* context;

  context = (server_context_t*) malloc(sizeof *context);
  ASSERT(context != NULL);

  context->sock = sock;
  context->connections = 0;

  r = uv_poll_init_socket(uv_default_loop(), &context->poll_handle, sock);
  context->poll_handle.data = context;
  ASSERT(r == 0);

  return context;
}

__attribute__((used)) static void server_close_cb(uv_handle_t* handle) {
  server_context_t* context = (server_context_t*) handle->data;
  free(context);
}

__attribute__((used)) static void destroy_server_context(server_context_t* context) {
  uv_close((uv_handle_t*) &context->poll_handle, server_close_cb);
}

__attribute__((used)) static void server_poll_cb(uv_poll_t* handle, int status, int events) {
  server_context_t* server_context = (server_context_t*)
                                          handle->data;
  connection_context_t* connection_context;
  struct sockaddr_in addr;
  socklen_t addr_len;
  uv_os_sock_t sock;
  int r;

  addr_len = sizeof addr;
  sock = accept(server_context->sock, (struct sockaddr*) &addr, &addr_len);
#ifdef _WIN32
  ASSERT(sock != INVALID_SOCKET);
#else
  ASSERT(sock >= 0);
#endif

  connection_context = create_connection_context(sock, 1);
  connection_context->events = UV_READABLE | UV_WRITABLE | UV_DISCONNECT;
  r = uv_poll_start(&connection_context->poll_handle,
                    UV_READABLE | UV_WRITABLE | UV_DISCONNECT,
                    connection_poll_cb);
  ASSERT(r == 0);

  if (++server_context->connections == NUM_CLIENTS) {
    close_socket(server_context->sock);
    destroy_server_context(server_context);
  }
}

__attribute__((used)) static void start_server(void) {
  server_context_t* context;
  struct sockaddr_in addr;
  uv_os_sock_t sock;
  int r;

  ASSERT(0 == uv_ip4_addr("127.0.0.1", TEST_PORT, &addr));
  sock = create_bound_socket(addr);
  context = create_server_context(sock);

  r = listen(sock, 100);
  ASSERT(r == 0);

  r = uv_poll_start(&context->poll_handle, UV_READABLE, server_poll_cb);
  ASSERT(r == 0);
}

__attribute__((used)) static void start_client(void) {
  uv_os_sock_t sock;
  connection_context_t* context;
  struct sockaddr_in server_addr;
  struct sockaddr_in addr;
  int r;

  ASSERT(0 == uv_ip4_addr("127.0.0.1", TEST_PORT, &server_addr));
  ASSERT(0 == uv_ip4_addr("0.0.0.0", 0, &addr));

  sock = create_bound_socket(addr);
  context = create_connection_context(sock, 0);

  context->events = UV_READABLE | UV_WRITABLE | UV_DISCONNECT;
  r = uv_poll_start(&context->poll_handle,
                    UV_READABLE | UV_WRITABLE | UV_DISCONNECT,
                    connection_poll_cb);
  ASSERT(r == 0);

  r = connect(sock, (struct sockaddr*) &server_addr, sizeof server_addr);
  ASSERT(r == 0 || got_eagain());
}

__attribute__((used)) static void start_poll_test(void) {
  int i, r;

#ifdef _WIN32
  {
    struct WSAData wsa_data;
    int r = WSAStartup(MAKEWORD(2, 2), &wsa_data);
    ASSERT(r == 0);
  }
#endif

  start_server();

  for (i = 0; i < NUM_CLIENTS; i++)
    start_client();

  r = uv_run(uv_default_loop(), UV_RUN_DEFAULT);
  ASSERT(r == 0);

  /* Assert that at most five percent of the writable wakeups was spurious. */
  ASSERT(spurious_writable_wakeups == 0 ||
         (valid_writable_wakeups + spurious_writable_wakeups) /
         spurious_writable_wakeups > 20);

  ASSERT(closed_connections == NUM_CLIENTS * 2);
#if !defined(__sun) && !defined(_AIX) && !defined(__MVS__)
  ASSERT(disconnects == NUM_CLIENTS * 2);
#endif
  MAKE_VALGRIND_HAPPY();
}

