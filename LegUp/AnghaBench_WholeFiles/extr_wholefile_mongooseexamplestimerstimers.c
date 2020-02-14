#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
struct mg_mgr {int dummy; } ;
struct mg_connection {int dummy; } ;
struct http_message {int dummy; } ;
struct TYPE_3__ {char* document_root; } ;

/* Variables and functions */
 int EXIT_FAILURE ; 
 int EXIT_SUCCESS ; 
#define  MG_EV_HTTP_REQUEST 129 
#define  MG_EV_TIMER 128 
 struct mg_connection* mg_bind (struct mg_mgr*,char*,void (*) (struct mg_connection*,int,void*)) ; 
 int /*<<< orphan*/  mg_mgr_free (struct mg_mgr*) ; 
 int /*<<< orphan*/  mg_mgr_init (struct mg_mgr*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mg_mgr_poll (struct mg_mgr*,int) ; 
 int /*<<< orphan*/  mg_serve_http (struct mg_connection*,struct http_message*,TYPE_1__) ; 
 int /*<<< orphan*/  mg_set_protocol_http_websocket (struct mg_connection*) ; 
 int /*<<< orphan*/  mg_set_timer (struct mg_connection*,double) ; 
 double mg_time () ; 
 int /*<<< orphan*/  printf (char*,...) ; 
 char* s_http_port ; 
 TYPE_1__ s_http_server_opts ; 

__attribute__((used)) static void ev_handler(struct mg_connection *c, int ev, void *ev_data) {
  switch (ev) {
    case MG_EV_HTTP_REQUEST:
      mg_serve_http(c, (struct http_message *) ev_data, s_http_server_opts);
      break;
    case MG_EV_TIMER: {
      double now = *(double *) ev_data;
      double next = mg_set_timer(c, 0) + 0.5;
      printf("timer event, current time: %.2lf\n", now);
      mg_set_timer(c, next);  // Send us timer event again after 0.5 seconds
      break;
    }
  }
}

int main(void) {
  struct mg_mgr mgr;
  struct mg_connection *c;

  mg_mgr_init(&mgr, NULL);
  c = mg_bind(&mgr, s_http_port, ev_handler);
  if (c == NULL) {
    printf("Cannot start on port %s\n", s_http_port);
    return EXIT_FAILURE;
  }

  // Set up HTTP server parameters
  mg_set_protocol_http_websocket(c);
  s_http_server_opts.document_root = ".";  // Serve current directory

  // Send us MG_EV_TIMER event after 2.5 seconds
  mg_set_timer(c, mg_time() + 2.5);

  printf("Starting on port %s, time: %.2lf\n", s_http_port, mg_time());
  for (;;) {
    mg_mgr_poll(&mgr, 1000);
  }
  mg_mgr_free(&mgr);

  return EXIT_SUCCESS;
}

