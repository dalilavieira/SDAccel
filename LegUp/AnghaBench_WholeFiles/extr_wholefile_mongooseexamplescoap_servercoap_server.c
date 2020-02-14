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
typedef  int uint32_t ;
struct mg_mgr {int dummy; } ;
struct mg_connection {int dummy; } ;
struct mg_coap_message {int msg_id; } ;

/* Variables and functions */
#define  MG_EV_COAP_ACK 131 
#define  MG_EV_COAP_CON 130 
#define  MG_EV_COAP_NOC 129 
#define  MG_EV_COAP_RST 128 
 int SIGINT ; 
 int SIGTERM ; 
 struct mg_connection* mg_bind (struct mg_mgr*,char*,void (*) (struct mg_connection*,int,void*)) ; 
 int mg_coap_send_ack (struct mg_connection*,int) ; 
 int /*<<< orphan*/  mg_mgr_free (struct mg_mgr*) ; 
 int /*<<< orphan*/  mg_mgr_init (struct mg_mgr*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mg_mgr_poll (struct mg_mgr*,int) ; 
 int /*<<< orphan*/  mg_set_protocol_coap (struct mg_connection*) ; 
 int /*<<< orphan*/  printf (char*,...) ; 
 char* s_default_address ; 
 int s_sig_received ; 
 int /*<<< orphan*/  signal (int,void (*) (int)) ; 

__attribute__((used)) static void signal_handler(int sig_num) {
  signal(sig_num, signal_handler);
  s_sig_received = sig_num;
}

__attribute__((used)) static void coap_handler(struct mg_connection *nc, int ev, void *p) {
  switch (ev) {
    case MG_EV_COAP_CON: {
      uint32_t res;
      struct mg_coap_message *cm = (struct mg_coap_message *) p;
      printf("CON with msg_id = %d received\n", cm->msg_id);
      res = mg_coap_send_ack(nc, cm->msg_id);
      if (res == 0) {
        printf("Successfully sent ACK for message with msg_id = %d\n",
               cm->msg_id);
      } else {
        printf("Error: %d\n", res);
      }
      break;
    }
    case MG_EV_COAP_NOC:
    case MG_EV_COAP_ACK:
    case MG_EV_COAP_RST: {
      struct mg_coap_message *cm = (struct mg_coap_message *) p;
      printf("ACK/RST/NOC with msg_id = %d received\n", cm->msg_id);
      break;
    }
  }
}

int main(void) {
  struct mg_mgr mgr;
  struct mg_connection *nc;

  signal(SIGTERM, signal_handler);
  signal(SIGINT, signal_handler);

  mg_mgr_init(&mgr, 0);

  nc = mg_bind(&mgr, s_default_address, coap_handler);
  if (nc == NULL) {
    printf("Unable to start listener at %s\n", s_default_address);
    return -1;
  }

  printf("Listening for CoAP messages at %s\n", s_default_address);

  mg_set_protocol_coap(nc);

  while (!s_sig_received) {
    mg_mgr_poll(&mgr, 1000000);
  }

  printf("Exiting on signal %d\n", s_sig_received);

  mg_mgr_free(&mgr);
  return 0;
}

