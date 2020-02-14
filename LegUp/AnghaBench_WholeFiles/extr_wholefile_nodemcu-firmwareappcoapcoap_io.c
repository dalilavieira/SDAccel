#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_17__   TYPE_6__ ;
typedef  struct TYPE_16__   TYPE_5__ ;
typedef  struct TYPE_15__   TYPE_4__ ;
typedef  struct TYPE_14__   TYPE_3__ ;
typedef  struct TYPE_13__   TYPE_2__ ;
typedef  struct TYPE_12__   TYPE_1__ ;

/* Type definitions */
typedef  int uint32_t ;
struct TYPE_15__ {TYPE_3__* udp; TYPE_2__* tcp; } ;
struct espconn {scalar_t__ type; TYPE_4__ proto; } ;
typedef  int /*<<< orphan*/  ip ;
typedef  scalar_t__ coap_tid_t ;
typedef  int /*<<< orphan*/  coap_tick_t ;
struct TYPE_16__ {scalar_t__ id; int timeout; int t; TYPE_6__* pdu; struct espconn* pconn; scalar_t__ retransmit_cnt; } ;
typedef  TYPE_5__ coap_queue_t ;
struct TYPE_12__ {int /*<<< orphan*/  len; scalar_t__ p; } ;
struct TYPE_17__ {int /*<<< orphan*/  pkt; TYPE_1__ msg; } ;
typedef  TYPE_6__ coap_pdu_t ;
struct TYPE_14__ {int remote_port; int /*<<< orphan*/  remote_ip; } ;
struct TYPE_13__ {int remote_port; int /*<<< orphan*/  remote_ip; } ;

/* Variables and functions */
 int COAP_DEFAULT_RESPONSE_TIMEOUT ; 
 scalar_t__ COAP_INVALID_TID ; 
 int COAP_TICKS_PER_SECOND ; 
 scalar_t__ ESPCONN_TCP ; 
 int /*<<< orphan*/  NODE_DBG (char*) ; 
 int /*<<< orphan*/  c_memcpy (int*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  coap_free_node (TYPE_5__*) ; 
 int /*<<< orphan*/  coap_insert_node (int /*<<< orphan*/ *,TYPE_5__*) ; 
 TYPE_5__* coap_new_node () ; 
 int /*<<< orphan*/  coap_timer_start (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  coap_timer_stop () ; 
 int /*<<< orphan*/  coap_timer_update (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  coap_transaction_id (int,int,int /*<<< orphan*/ ,scalar_t__*) ; 
 int /*<<< orphan*/  espconn_sent (struct espconn*,unsigned char*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  gQueue ; 
 int rand () ; 

coap_tid_t coap_send(struct espconn *pesp_conn, coap_pdu_t *pdu) {
  coap_tid_t id = COAP_INVALID_TID;
  uint32_t ip = 0, port = 0;
  if ( !pesp_conn || !pdu )
    return id;

  espconn_sent(pesp_conn, (unsigned char *)(pdu->msg.p), pdu->msg.len);

  if(pesp_conn->type == ESPCONN_TCP){
    c_memcpy(&ip, pesp_conn->proto.tcp->remote_ip, sizeof(ip));
    port = pesp_conn->proto.tcp->remote_port;
  }else{
    c_memcpy(&ip, pesp_conn->proto.udp->remote_ip, sizeof(ip));
    port = pesp_conn->proto.udp->remote_port;
  }
  coap_transaction_id(ip, port, pdu->pkt, &id);
  return id;
}

coap_tid_t coap_send_confirmed(struct espconn *pesp_conn, coap_pdu_t *pdu) {
  coap_queue_t *node;
  coap_tick_t diff;
  uint32_t r;

  node = coap_new_node();
  if (!node) {
    NODE_DBG("coap_send_confirmed: insufficient memory\n");
    return COAP_INVALID_TID;
  }

  node->retransmit_cnt = 0;
  node->id = coap_send(pesp_conn, pdu);
  if (COAP_INVALID_TID == node->id) {
    NODE_DBG("coap_send_confirmed: error sending pdu\n");
    coap_free_node(node);
    return COAP_INVALID_TID;
  }
  r = rand();

  /* add randomized RESPONSE_TIMEOUT to determine retransmission timeout */
  node->timeout = COAP_DEFAULT_RESPONSE_TIMEOUT * COAP_TICKS_PER_SECOND +
    (COAP_DEFAULT_RESPONSE_TIMEOUT >> 1) *
    ((COAP_TICKS_PER_SECOND * (r & 0xFF)) >> 8);

  node->pconn = pesp_conn;
  node->pdu = pdu;

  /* Set timer for pdu retransmission. If this is the first element in
   * the retransmission queue, the base time is set to the current
   * time and the retransmission time is node->timeout. If there is
   * already an entry in the sendqueue, we must check if this node is
   * to be retransmitted earlier. Therefore, node->timeout is first
   * normalized to the timeout and then inserted into the queue with
   * an adjusted relative time.
   */
  coap_timer_stop();
  coap_timer_update(&gQueue);
  node->t = node->timeout;
  coap_insert_node(&gQueue, node);
  coap_timer_start(&gQueue);
  return node->id;
}

