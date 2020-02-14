#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
struct work_result {unsigned long conn_id; int member_1; int /*<<< orphan*/  member_0; int /*<<< orphan*/  sleep_time; } ;
struct work_request {unsigned long member_0; int /*<<< orphan*/  conn_id; } ;
struct mg_mgr {int dummy; } ;
struct mg_connection {int /*<<< orphan*/ * user_data; int /*<<< orphan*/  mgr; } ;
typedef  int /*<<< orphan*/  res ;
typedef  int /*<<< orphan*/  req ;
struct TYPE_2__ {char* document_root; char* enable_directory_listing; } ;

/* Variables and functions */
#define  MG_EV_ACCEPT 130 
#define  MG_EV_CLOSE 129 
#define  MG_EV_HTTP_REQUEST 128 
 int SIGINT ; 
 int SIGTERM ; 
 int /*<<< orphan*/  SOCK_STREAM ; 
 int /*<<< orphan*/  closesocket (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  exit (int) ; 
 struct mg_connection* mg_bind (struct mg_mgr*,char*,void (*) (struct mg_connection*,int,void*)) ; 
 int /*<<< orphan*/  mg_broadcast (struct mg_mgr*,void (*) (struct mg_connection*,int,void*),void*,int) ; 
 int /*<<< orphan*/  mg_mgr_free (struct mg_mgr*) ; 
 int /*<<< orphan*/  mg_mgr_init (struct mg_mgr*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mg_mgr_poll (struct mg_mgr*,int) ; 
 struct mg_connection* mg_next (int /*<<< orphan*/ ,struct mg_connection*) ; 
 int /*<<< orphan*/  mg_printf (struct mg_connection*,char*,char*) ; 
 int /*<<< orphan*/  mg_send_head (struct mg_connection*,int,int /*<<< orphan*/ ,char*) ; 
 int /*<<< orphan*/  mg_set_protocol_http_websocket (struct mg_connection*) ; 
 scalar_t__ mg_socketpair (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mg_start_thread (void* (*) (void*),struct mg_mgr*) ; 
 int /*<<< orphan*/  perror (char*) ; 
 int /*<<< orphan*/  printf (char*,...) ; 
 int rand () ; 
 scalar_t__ read (int /*<<< orphan*/ ,struct work_request*,int) ; 
 char* s_http_port ; 
 TYPE_1__ s_http_server_opts ; 
 scalar_t__ s_next_id ; 
 int s_num_worker_threads ; 
 int s_received_signal ; 
 int /*<<< orphan*/  signal (int,void (*) (int)) ; 
 int /*<<< orphan*/  sleep (int) ; 
 int /*<<< orphan*/ * sock ; 
 int /*<<< orphan*/  sprintf (char*,char*,unsigned long,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  strlen (char*) ; 
 int /*<<< orphan*/  write (int /*<<< orphan*/ ,struct work_request*,int) ; 

__attribute__((used)) static void signal_handler(int sig_num) {
  signal(sig_num, signal_handler);
  s_received_signal = sig_num;
}

__attribute__((used)) static void on_work_complete(struct mg_connection *nc, int ev, void *ev_data) {
  (void) ev;
  char s[32];
  struct mg_connection *c;
  for (c = mg_next(nc->mgr, NULL); c != NULL; c = mg_next(nc->mgr, c)) {
    if (c->user_data != NULL) {
      struct work_result *res = (struct work_result *)ev_data;
      if ((unsigned long)c->user_data == res->conn_id) {
        sprintf(s, "conn_id:%lu sleep:%d", res->conn_id, res->sleep_time);
        mg_send_head(c, 200, strlen(s), "Content-Type: text/plain");
        mg_printf(c, "%s", s);
      }
    }
  }
}

void *worker_thread_proc(void *param) {
  struct mg_mgr *mgr = (struct mg_mgr *) param;
  struct work_request req = {0};
  
  while (s_received_signal == 0) {
    if (read(sock[1], &req, sizeof(req)) < 0)
      perror("Reading worker sock");
    int r = rand() % 10;
    sleep(r);
    struct work_result res = {req.conn_id, r};
    mg_broadcast(mgr, on_work_complete, (void *)&res, sizeof(res));
  }
  return NULL;
}

__attribute__((used)) static void ev_handler(struct mg_connection *nc, int ev, void *ev_data) {
  (void) nc;
  (void) ev_data;
  
  switch (ev) {
    case MG_EV_ACCEPT:
      nc->user_data = (void *)++s_next_id;
      break;
    case MG_EV_HTTP_REQUEST: {
      struct work_request req = {(unsigned long)nc->user_data};

      if (write(sock[0], &req, sizeof(req)) < 0)
        perror("Writing worker sock");
      break;
    }
    case MG_EV_CLOSE: {
      if (nc->user_data) nc->user_data = NULL;
    }
  }
}

int main(void) {
  struct mg_mgr mgr;
  struct mg_connection *nc;
  int i;

  if (mg_socketpair(sock, SOCK_STREAM) == 0) {
    perror("Opening socket pair");
    exit(1);
  }

  signal(SIGTERM, signal_handler);
  signal(SIGINT, signal_handler);

  mg_mgr_init(&mgr, NULL);

  nc = mg_bind(&mgr, s_http_port, ev_handler);
  if (nc == NULL) {
    printf("Failed to create listener\n");
    return 1;
  }

  mg_set_protocol_http_websocket(nc);
  s_http_server_opts.document_root = ".";  // Serve current directory
  s_http_server_opts.enable_directory_listing = "no";

  for (i = 0; i < s_num_worker_threads; i++) {
    mg_start_thread(worker_thread_proc, &mgr);
  }

  printf("Started on port %s\n", s_http_port);
  while (s_received_signal == 0) {
    mg_mgr_poll(&mgr, 200);
  }

  mg_mgr_free(&mgr);

  closesocket(sock[0]);
  closesocket(sock[1]);

  return 0;
}

