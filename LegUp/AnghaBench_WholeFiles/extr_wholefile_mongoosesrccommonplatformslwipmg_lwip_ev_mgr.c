#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_10__   TYPE_5__ ;
typedef  struct TYPE_9__   TYPE_4__ ;
typedef  struct TYPE_8__   TYPE_3__ ;
typedef  struct TYPE_7__   TYPE_2__ ;
typedef  struct TYPE_6__   TYPE_1__ ;

/* Type definitions */
typedef  double time_t ;
struct mg_mgr {struct mg_connection* active_connections; TYPE_1__** ifaces; } ;
struct TYPE_9__ {TYPE_5__* tcp; } ;
struct mg_lwip_conn_state {scalar_t__ draining_rx_chain; int /*<<< orphan*/ * rx_chain; TYPE_4__ pcb; int /*<<< orphan*/  recv_pending; int /*<<< orphan*/  err; } ;
struct mg_iface {struct mg_mgr* mgr; int /*<<< orphan*/ * data; } ;
struct mg_ev_mgr_lwip_data {int sig_queue_len; int start_index; TYPE_3__* sig_queue; } ;
struct mg_connection {scalar_t__ sock; int flags; double ev_timer_time; int /*<<< orphan*/  send_mbuf; struct mg_connection* next; TYPE_2__* iface; int /*<<< orphan*/  recv_mbuf; int /*<<< orphan*/ * mgr; } ;
typedef  enum mg_sig_type { ____Placeholder_mg_sig_type } mg_sig_type ;
struct TYPE_10__ {int /*<<< orphan*/ * unsent; } ;
struct TYPE_8__ {int sig; struct mg_connection* nc; } ;
struct TYPE_7__ {scalar_t__ data; } ;
struct TYPE_6__ {scalar_t__ data; } ;

/* Variables and functions */
 scalar_t__ INVALID_SOCKET ; 
 int /*<<< orphan*/  LL_INFO ; 
 int /*<<< orphan*/  LOG (int /*<<< orphan*/ ,char*) ; 
 int /*<<< orphan*/  LWIP_VERSION_MAJOR ; 
 int /*<<< orphan*/  LWIP_VERSION_MINOR ; 
 int /*<<< orphan*/  LWIP_VERSION_REVISION ; 
 int /*<<< orphan*/ * MG_CALLOC (int,int) ; 
 int /*<<< orphan*/  MG_FREE (int /*<<< orphan*/ *) ; 
 int MG_F_LISTENING ; 
 int MG_F_UDP ; 
 size_t MG_MAIN_IFACE ; 
#define  MG_SIG_ACCEPT 132 
#define  MG_SIG_CLOSE_CONN 131 
#define  MG_SIG_CONNECT_RESULT 130 
 int MG_SIG_QUEUE_LEN ; 
#define  MG_SIG_RECV 129 
#define  MG_SIG_TOMBSTONE 128 
 int /*<<< orphan*/  MG_VERSION ; 
 int /*<<< orphan*/  mbuf_trim (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mg_close_conn (struct mg_connection*) ; 
 int /*<<< orphan*/  mg_if_can_recv_cb (struct mg_connection*) ; 
 int /*<<< orphan*/  mg_if_can_send_cb (struct mg_connection*) ; 
 int /*<<< orphan*/  mg_if_connect_cb (struct mg_connection*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mg_if_poll (struct mg_connection*,double) ; 
 int /*<<< orphan*/  mg_lwip_handle_accept (struct mg_connection*) ; 
 scalar_t__ mg_lwip_if_can_send (struct mg_connection*,struct mg_lwip_conn_state*) ; 
 int /*<<< orphan*/  mg_lwip_mgr_schedule_poll (int /*<<< orphan*/ *) ; 
 double mg_time () ; 
 int /*<<< orphan*/  mgos_lock () ; 
 int /*<<< orphan*/  mgos_unlock () ; 
 int /*<<< orphan*/  tcp_output_tcpip ; 
 int /*<<< orphan*/  tcpip_callback (int /*<<< orphan*/ ,TYPE_5__*) ; 

void mg_lwip_post_signal(enum mg_sig_type sig, struct mg_connection *nc) {
  struct mg_ev_mgr_lwip_data *md =
      (struct mg_ev_mgr_lwip_data *) nc->iface->data;
  mgos_lock();
  if (md->sig_queue_len >= MG_SIG_QUEUE_LEN) {
    mgos_unlock();
    return;
  }
  int end_index = (md->start_index + md->sig_queue_len) % MG_SIG_QUEUE_LEN;
  md->sig_queue[end_index].sig = sig;
  md->sig_queue[end_index].nc = nc;
  md->sig_queue_len++;
  mg_lwip_mgr_schedule_poll(nc->mgr);
  mgos_unlock();
}

void mg_ev_mgr_lwip_process_signals(struct mg_mgr *mgr) {
  struct mg_ev_mgr_lwip_data *md =
      (struct mg_ev_mgr_lwip_data *) mgr->ifaces[MG_MAIN_IFACE]->data;
  while (md->sig_queue_len > 0) {
    mgos_lock();
    int i = md->start_index;
    int sig = md->sig_queue[i].sig;
    struct mg_connection *nc = md->sig_queue[i].nc;
    struct mg_lwip_conn_state *cs = (struct mg_lwip_conn_state *) nc->sock;
    md->start_index = (i + 1) % MG_SIG_QUEUE_LEN;
    md->sig_queue_len--;
    mgos_unlock();
    if (nc->iface == NULL || nc->mgr == NULL) continue;
    switch (sig) {
      case MG_SIG_CONNECT_RESULT: {
        mg_if_connect_cb(nc, cs->err);
        break;
      }
      case MG_SIG_CLOSE_CONN: {
        mg_close_conn(nc);
        break;
      }
      case MG_SIG_RECV: {
        cs->recv_pending = 0;
        mg_if_can_recv_cb(nc);
        mbuf_trim(&nc->recv_mbuf);
        break;
      }
      case MG_SIG_TOMBSTONE: {
        break;
      }
      case MG_SIG_ACCEPT: {
        mg_lwip_handle_accept(nc);
        break;
      }
    }
  }
}

void mg_lwip_if_init(struct mg_iface *iface) {
  LOG(LL_INFO, ("Mongoose %s, LwIP %u.%u.%u", MG_VERSION, LWIP_VERSION_MAJOR,
                LWIP_VERSION_MINOR, LWIP_VERSION_REVISION));
  iface->data = MG_CALLOC(1, sizeof(struct mg_ev_mgr_lwip_data));
}

void mg_lwip_if_free(struct mg_iface *iface) {
  MG_FREE(iface->data);
  iface->data = NULL;
}

void mg_lwip_if_add_conn(struct mg_connection *nc) {
  (void) nc;
}

void mg_lwip_if_remove_conn(struct mg_connection *nc) {
  struct mg_ev_mgr_lwip_data *md =
      (struct mg_ev_mgr_lwip_data *) nc->iface->data;
  /* Walk the queue and null-out further signals for this conn. */
  for (int i = 0; i < MG_SIG_QUEUE_LEN; i++) {
    if (md->sig_queue[i].nc == nc) {
      md->sig_queue[i].sig = MG_SIG_TOMBSTONE;
    }
  }
}

time_t mg_lwip_if_poll(struct mg_iface *iface, int timeout_ms) {
  struct mg_mgr *mgr = iface->mgr;
  int n = 0;
  double now = mg_time();
  struct mg_connection *nc, *tmp;
  double min_timer = 0;
  int num_timers = 0;
#if 0
  DBG(("begin poll @%u", (unsigned int) (now * 1000)));
#endif
  mg_ev_mgr_lwip_process_signals(mgr);
  for (nc = mgr->active_connections; nc != NULL; nc = tmp) {
    struct mg_lwip_conn_state *cs = (struct mg_lwip_conn_state *) nc->sock;
    tmp = nc->next;
    n++;
    if (!mg_if_poll(nc, now)) continue;
    if (nc->sock != INVALID_SOCKET &&
        !(nc->flags & (MG_F_UDP | MG_F_LISTENING)) && cs->pcb.tcp != NULL &&
        cs->pcb.tcp->unsent != NULL) {
      tcpip_callback(tcp_output_tcpip, cs->pcb.tcp);
    }
    if (nc->ev_timer_time > 0) {
      if (num_timers == 0 || nc->ev_timer_time < min_timer) {
        min_timer = nc->ev_timer_time;
      }
      num_timers++;
    }

    if (nc->sock != INVALID_SOCKET) {
      if (mg_lwip_if_can_send(nc, cs)) {
        mg_if_can_send_cb(nc);
        mbuf_trim(&nc->send_mbuf);
      }
      if (cs->rx_chain != NULL) {
        mg_if_can_recv_cb(nc);
      } else if (cs->draining_rx_chain) {
        /*
         * If the connection is about to close, and rx_chain is finally empty,
         * send the MG_SIG_CLOSE_CONN signal
         */
        mg_lwip_post_signal(MG_SIG_CLOSE_CONN, nc);
      }
    }
  }
#if 0
  DBG(("end poll @%u, %d conns, %d timers (min %u), next in %d ms",
       (unsigned int) (now * 1000), n, num_timers,
       (unsigned int) (min_timer * 1000), timeout_ms));
#endif
  (void) timeout_ms;
  return now;
}

