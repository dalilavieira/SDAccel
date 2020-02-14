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
struct mg_mgr {char* hexdump_file; } ;
struct mg_dns_resource_record {int rtype; int /*<<< orphan*/  name; } ;
struct mg_dns_reply {int dummy; } ;
struct mg_dns_message {int num_questions; struct mg_dns_resource_record* questions; } ;
struct mg_connection {int /*<<< orphan*/  flags; } ;
struct mbuf {int dummy; } ;
typedef  int /*<<< orphan*/  rname ;

/* Variables and functions */
 int MG_DNS_A_RECORD ; 
#define  MG_DNS_MESSAGE 128 
 int /*<<< orphan*/  MG_F_SEND_AND_CLOSE ; 
 int /*<<< orphan*/  exit (int) ; 
 int /*<<< orphan*/  fprintf (int /*<<< orphan*/ ,char*,...) ; 
 int /*<<< orphan*/  inet_addr (char*) ; 
 int /*<<< orphan*/  mbuf_free (struct mbuf*) ; 
 int /*<<< orphan*/  mbuf_init (struct mbuf*,int) ; 
 struct mg_connection* mg_bind (struct mg_mgr*,char*,void (*) (struct mg_connection*,int,void*)) ; 
 struct mg_dns_reply mg_dns_create_reply (struct mbuf*,struct mg_dns_message*) ; 
 int /*<<< orphan*/  mg_dns_reply_record (struct mg_dns_reply*,struct mg_dns_resource_record*,int /*<<< orphan*/ *,int,int,int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  mg_dns_send_reply (struct mg_connection*,struct mg_dns_reply*) ; 
 int /*<<< orphan*/  mg_dns_uncompress_name (struct mg_dns_message*,int /*<<< orphan*/ *,char*,int) ; 
 int /*<<< orphan*/  mg_mgr_free (struct mg_mgr*) ; 
 int /*<<< orphan*/  mg_mgr_init (struct mg_mgr*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mg_mgr_poll (struct mg_mgr*,int) ; 
 int /*<<< orphan*/  mg_set_protocol_dns (struct mg_connection*) ; 
 scalar_t__ s_exit_flag ; 
 char* s_listening_addr ; 
 int /*<<< orphan*/  s_our_ip_addr ; 
 int /*<<< orphan*/  stderr ; 
 int /*<<< orphan*/  stdout ; 
 scalar_t__ strcmp (char*,char*) ; 

__attribute__((used)) static void ev_handler(struct mg_connection *nc, int ev, void *ev_data) {
  struct mg_dns_message *msg;
  struct mg_dns_resource_record *rr;
  struct mg_dns_reply reply;
  int i;

  switch (ev) {
    case MG_DNS_MESSAGE: {
      struct mbuf reply_buf;
      mbuf_init(&reply_buf, 512);
      msg = (struct mg_dns_message *) ev_data;
      reply = mg_dns_create_reply(&reply_buf, msg);

      for (i = 0; i < msg->num_questions; i++) {
        char rname[256];
        rr = &msg->questions[i];
        mg_dns_uncompress_name(msg, &rr->name, rname, sizeof(rname) - 1);
        fprintf(stdout, "Q type %d name %s\n", rr->rtype, rname);
        if (rr->rtype == MG_DNS_A_RECORD) {
          mg_dns_reply_record(&reply, rr, NULL, rr->rtype, 10, &s_our_ip_addr,
                              4);
        }
      }

      /*
       * We don't set the error flag even if there were no answers
       * matching the MG_DNS_A_RECORD query type.
       * This indicates that we have (synthetic) answers for MG_DNS_A_RECORD.
       * See http://goo.gl/QWvufr for a distinction between NXDOMAIN and NODATA.
       */

      mg_dns_send_reply(nc, &reply);
      nc->flags |= MG_F_SEND_AND_CLOSE;
      mbuf_free(&reply_buf);
      break;
    }
  }
}

int main(int argc, char *argv[]) {
  struct mg_mgr mgr;
  struct mg_connection *nc;
  int i;

  mg_mgr_init(&mgr, NULL);
  s_our_ip_addr = inet_addr("127.0.0.1");

  /* Parse command line arguments */
  for (i = 1; i < argc; i++) {
    if (strcmp(argv[i], "-D") == 0) {
      mgr.hexdump_file = argv[++i];
    } else if (strcmp(argv[i], "-l") == 0 && i + 1 < argc) {
      s_listening_addr = argv[++i];
    } else {
      s_our_ip_addr = inet_addr(argv[i]);
    }
  }

  fprintf(stderr, "Listening on '%s'\n", s_listening_addr);
  if ((nc = mg_bind(&mgr, s_listening_addr, ev_handler)) == NULL) {
    fprintf(stderr, "cannot bind to socket\n");
    exit(1);
  }
  mg_set_protocol_dns(nc);

  while (s_exit_flag == 0) {
    mg_mgr_poll(&mgr, 1000);
  }
  mg_mgr_free(&mgr);

  return 0;
}

