#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_11__   TYPE_5__ ;
typedef  struct TYPE_10__   TYPE_4__ ;
typedef  struct TYPE_9__   TYPE_3__ ;
typedef  struct TYPE_8__   TYPE_2__ ;
typedef  struct TYPE_7__   TYPE_1__ ;

/* Type definitions */
struct mg_str {int /*<<< orphan*/  p; scalar_t__ len; } ;
struct mg_mgr {char* hexdump_file; } ;
struct mg_connection {int /*<<< orphan*/  flags; } ;
struct TYPE_9__ {int /*<<< orphan*/  p; scalar_t__ len; } ;
struct TYPE_8__ {int /*<<< orphan*/  p; scalar_t__ len; } ;
struct TYPE_7__ {int /*<<< orphan*/  p; scalar_t__ len; } ;
struct http_message {struct mg_str* header_values; struct mg_str* header_names; TYPE_3__ body; TYPE_2__ method; TYPE_1__ uri; } ;
struct TYPE_11__ {char* document_root; } ;
struct TYPE_10__ {char* document_root; char* url_rewrites; } ;

/* Variables and functions */
#define  MG_EV_HTTP_REQUEST 128 
 int /*<<< orphan*/  MG_F_SEND_AND_CLOSE ; 
 int MG_MAX_HTTP_HEADERS ; 
 struct mg_connection* mg_bind (struct mg_mgr*,char*,void (*) (struct mg_connection*,int,void*)) ; 
 int /*<<< orphan*/  mg_mgr_init (struct mg_mgr*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mg_mgr_poll (struct mg_mgr*,int) ; 
 int /*<<< orphan*/  mg_printf (struct mg_connection*,char*,...) ; 
 int /*<<< orphan*/  mg_send_response_line (struct mg_connection*,int,char*) ; 
 int /*<<< orphan*/  mg_serve_http (struct mg_connection*,struct http_message*,TYPE_4__) ; 
 int /*<<< orphan*/  mg_set_protocol_http_websocket (struct mg_connection*) ; 
 int /*<<< orphan*/  printf (char*,char*) ; 
 char* s_backend_port ; 
 TYPE_5__ s_backend_server_opts ; 
 char* s_frontend_port ; 
 TYPE_4__ s_frontend_server_opts ; 
 scalar_t__ strcmp (char*,char*) ; 

__attribute__((used)) static void frontend_handler(struct mg_connection *nc, int ev, void *ev_data) {
  struct http_message *hm = (struct http_message *) ev_data;
  switch (ev) {
    case MG_EV_HTTP_REQUEST:
      mg_serve_http(nc, hm, s_frontend_server_opts); /* Serve static content */
      break;
    default:
      break;
  }
}

__attribute__((used)) static void backend_handler(struct mg_connection *nc, int ev, void *ev_data) {
  struct http_message *hm = (struct http_message *) ev_data;
  int i;

  switch (ev) {
    case MG_EV_HTTP_REQUEST:
      mg_send_response_line(nc, 200,
                            "Content-Type: text/html\r\n"
                            "Connection: close\r\n");
      mg_printf(nc,
                "{\"uri\": \"%.*s\", \"method\": \"%.*s\", \"body\": \"%.*s\", "
                "\"headers\": {",
                (int) hm->uri.len, hm->uri.p, (int) hm->method.len,
                hm->method.p, (int) hm->body.len, hm->body.p);

      for (i = 0; i < MG_MAX_HTTP_HEADERS && hm->header_names[i].len > 0; i++) {
        struct mg_str hn = hm->header_names[i];
        struct mg_str hv = hm->header_values[i];
        mg_printf(nc, "%s\"%.*s\": \"%.*s\"", (i != 0 ? "," : ""), (int) hn.len,
                  hn.p, (int) hv.len, hv.p);
      }

      mg_printf(nc, "}}");

      nc->flags |= MG_F_SEND_AND_CLOSE;
      break;
    default:
      break;
  }
}

int main(int argc, char *argv[]) {
  struct mg_mgr mgr;
  struct mg_connection *nc;
  int i;

  /* Open listening socket */
  mg_mgr_init(&mgr, NULL);

  /* configure frontend web server */
  nc = mg_bind(&mgr, s_frontend_port, frontend_handler);
  mg_set_protocol_http_websocket(nc);

  s_frontend_server_opts.document_root = "frontend";
  s_frontend_server_opts.url_rewrites =
      "/api=http://localhost:8001,/=frontend/hello.html";

  /* configure backend web server */
  nc = mg_bind(&mgr, s_backend_port, backend_handler);
  mg_set_protocol_http_websocket(nc);

  s_backend_server_opts.document_root = "backend";

  /* Parse command line arguments */
  for (i = 1; i < argc; i++) {
    if (strcmp(argv[i], "-D") == 0) {
      mgr.hexdump_file = argv[++i];
    } else if (strcmp(argv[i], "-r") == 0) {
      s_frontend_server_opts.document_root = argv[++i];
    }
  }

  printf("Starting web server on port %s\n", s_frontend_port);
  for (;;) {
    mg_mgr_poll(&mgr, 1000);
  }
}

