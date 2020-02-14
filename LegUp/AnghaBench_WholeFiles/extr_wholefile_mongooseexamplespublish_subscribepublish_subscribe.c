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
struct mg_mgr {int dummy; } ;
struct mbuf {int /*<<< orphan*/  len; int /*<<< orphan*/  buf; } ;
struct mg_connection {int flags; struct mg_connection* user_data; struct mbuf recv_mbuf; int /*<<< orphan*/  mgr; } ;
typedef  int /*<<< orphan*/  sock_t ;
typedef  int /*<<< orphan*/  addr ;

/* Variables and functions */
 int EOF ; 
 int EXIT_FAILURE ; 
 int EXIT_SUCCESS ; 
 int MG_EV_ACCEPT ; 
 int MG_EV_CLOSE ; 
 int MG_EV_CONNECT ; 
 int MG_EV_RECV ; 
 int MG_F_CLOSE_IMMEDIATELY ; 
 int MG_F_USER_1 ; 
 int MG_F_USER_2 ; 
 int MG_SOCK_STRINGIFY_IP ; 
 int MG_SOCK_STRINGIFY_PORT ; 
 int /*<<< orphan*/  SOCK_STREAM ; 
 int /*<<< orphan*/  exit (int) ; 
 int /*<<< orphan*/  fprintf (int /*<<< orphan*/ ,char*,...) ; 
 int /*<<< orphan*/  fwrite (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int,int /*<<< orphan*/ ) ; 
 int getchar () ; 
 int /*<<< orphan*/  mbuf_remove (struct mbuf*,int /*<<< orphan*/ ) ; 
 struct mg_connection* mg_add_sock (struct mg_mgr*,int /*<<< orphan*/ ,void (*) (struct mg_connection*,int,void*)) ; 
 int /*<<< orphan*/  mg_bind (struct mg_mgr*,char*,void (*) (struct mg_connection*,int,void*)) ; 
 struct mg_connection* mg_connect (struct mg_mgr*,char*,void (*) (struct mg_connection*,int,void*)) ; 
 int /*<<< orphan*/  mg_mgr_free (struct mg_mgr*) ; 
 int /*<<< orphan*/  mg_mgr_init (struct mg_mgr*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mg_mgr_poll (struct mg_mgr*,int) ; 
 struct mg_connection* mg_next (int /*<<< orphan*/ ,struct mg_connection*) ; 
 int /*<<< orphan*/  mg_send (struct mg_connection*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mg_sock_addr_to_str (void*,char*,int,int) ; 
 int /*<<< orphan*/  mg_socketpair (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mg_start_thread (void* (*) (void*),int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  printf (char*,char*) ; 
 scalar_t__ send (int,char const*,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  stderr ; 
 int /*<<< orphan*/  stdout ; 
 scalar_t__ strcmp (char*,char*) ; 

__attribute__((used)) static void *stdin_thread(void *param) {
  int ch, sock = *(int *) param;
  // Forward all types characters to the socketpair
  while ((ch = getchar()) != EOF) {
    unsigned char c = (unsigned char) ch;
    if (send(sock, (const char *) &c, 1, 0) < 0) {
      fprintf(stderr, "Failed to send byte to the socket");
    }
  }
  return NULL;
}

__attribute__((used)) static void server_handler(struct mg_connection *nc, int ev, void *p) {
  (void) p;
  if (ev == MG_EV_RECV) {
    // Push received message to all ncections
    struct mbuf *io = &nc->recv_mbuf;
    struct mg_connection *c;

    for (c = mg_next(nc->mgr, NULL); c != NULL; c = mg_next(nc->mgr, c)) {
      if (!(c->flags & MG_F_USER_2)) continue;  // Skip non-client connections
      mg_send(c, io->buf, io->len);
    }
    mbuf_remove(io, io->len);
  } else if (ev == MG_EV_ACCEPT) {
    char addr[32];
    mg_sock_addr_to_str(p, addr, sizeof(addr),
                        MG_SOCK_STRINGIFY_IP | MG_SOCK_STRINGIFY_PORT);
    printf("New client connected from %s\n", addr);
  }
}

__attribute__((used)) static void client_handler(struct mg_connection *conn, int ev, void *p) {
  struct mbuf *io = &conn->recv_mbuf;
  (void) p;

  if (ev == MG_EV_CONNECT) {
    if (conn->flags & MG_F_CLOSE_IMMEDIATELY) {
      printf("%s\n", "Error connecting to server!");
      exit(EXIT_FAILURE);
    }
    printf("%s\n", "Connected to server. Type a message and press enter.");
  } else if (ev == MG_EV_RECV) {
    if (conn->flags & MG_F_USER_1) {
      // Received data from the stdin, forward it to the server
      struct mg_connection *c = (struct mg_connection *) conn->user_data;
      mg_send(c, io->buf, io->len);
      mbuf_remove(io, io->len);
    } else {
      // Received data from server connection, print it
      fwrite(io->buf, io->len, 1, stdout);
      mbuf_remove(io, io->len);
    }
  } else if (ev == MG_EV_CLOSE) {
    // Connection has closed, most probably cause server has stopped
    exit(EXIT_SUCCESS);
  }
}

int main(int argc, char *argv[]) {
  struct mg_mgr mgr;

  if (argc != 3) {
    fprintf(stderr, "Usage: %s <port> <client|server>\n", argv[0]);
    exit(EXIT_FAILURE);
  } else if (strcmp(argv[2], "client") == 0) {
    sock_t fds[2];
    struct mg_connection *ioconn, *server_conn;

    mg_mgr_init(&mgr, NULL);

    // Connect to the pubsub server
    server_conn = mg_connect(&mgr, argv[1], client_handler);
    if (server_conn == NULL) {
      fprintf(stderr, "Cannot connect to port %s\n", argv[1]);
      exit(EXIT_FAILURE);
    }
    server_conn->flags |= MG_F_USER_2;  // Mark this as a client connection

    // Create a socketpair and give one end to the thread that reads stdin
    mg_socketpair(fds, SOCK_STREAM);
    mg_start_thread(stdin_thread, &fds[1]);

    // The other end of a pair goes inside the server
    ioconn = mg_add_sock(&mgr, fds[0], client_handler);
    ioconn->flags |= MG_F_USER_1;  // Mark this so we know this is a stdin
    ioconn->user_data = server_conn;

  } else {
    // Server code path
    mg_mgr_init(&mgr, NULL);
    mg_bind(&mgr, argv[1], server_handler);
    printf("Starting pubsub server on port %s\n", argv[1]);
  }

  for (;;) {
    mg_mgr_poll(&mgr, 1000);
  }
  mg_mgr_free(&mgr);

  return EXIT_SUCCESS;
}

