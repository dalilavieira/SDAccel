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
struct mg_connection {int /*<<< orphan*/  flags; struct mbuf recv_mbuf; } ;

/* Variables and functions */
#define  MG_EV_RECV 128 
 int /*<<< orphan*/  MG_F_SEND_AND_CLOSE ; 
 int /*<<< orphan*/  mbuf_remove (struct mbuf*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mg_bind (struct mg_mgr*,char const*,void (*) (struct mg_connection*,int,void*)) ; 
 int /*<<< orphan*/  mg_mgr_free (struct mg_mgr*) ; 
 int /*<<< orphan*/  mg_mgr_init (struct mg_mgr*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mg_mgr_poll (struct mg_mgr*,int) ; 
 int /*<<< orphan*/  mg_send (struct mg_connection*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  printf (char*,char const*,char const*) ; 

__attribute__((used)) static void ev_handler(struct mg_connection *nc, int ev, void *p) {
  struct mbuf *io = &nc->recv_mbuf;
  (void) p;
  switch (ev) {
    case MG_EV_RECV:
      mg_send(nc, io->buf, io->len);  // Echo message back
      mbuf_remove(io, io->len);       // Discard message from recv buffer
      // In case of UDP, Mongoose creates new virtual connection for
      // incoming messages
      // We can keep it (and it will be reused for another messages from
      // the same address) or we can close it (this saves some memory, but
      // decreases perfomance, because it forces creation of connection
      // for every incoming dgram)
      nc->flags |= MG_F_SEND_AND_CLOSE;
      break;
    default:
      break;
  }
}

int main(void) {
  struct mg_mgr mgr;
  const char *port1 = "udp://1234", *port2 = "udp://127.0.0.1:17000";

  mg_mgr_init(&mgr, NULL);
  mg_bind(&mgr, port1, ev_handler);
  mg_bind(&mgr, port2, ev_handler);

  printf("Starting echo mgr on ports %s, %s\n", port1, port2);
  for (;;) {
    mg_mgr_poll(&mgr, 1000);
  }
  mg_mgr_free(&mgr);

  return 0;
}

