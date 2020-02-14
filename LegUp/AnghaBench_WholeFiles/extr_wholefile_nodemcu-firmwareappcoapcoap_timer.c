#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_17__   TYPE_8__ ;
typedef  struct TYPE_16__   TYPE_3__ ;
typedef  struct TYPE_15__   TYPE_2__ ;
typedef  struct TYPE_14__   TYPE_1__ ;

/* Type definitions */
typedef  int uint16_t ;
typedef  int /*<<< orphan*/  os_timer_func_t ;
typedef  scalar_t__ coap_tick_t ;
struct TYPE_16__ {int retransmit_cnt; int t; int timeout; scalar_t__ id; TYPE_8__* pdu; int /*<<< orphan*/  pconn; } ;
typedef  TYPE_3__ coap_queue_t ;
struct TYPE_17__ {TYPE_2__* pkt; } ;
struct TYPE_14__ {scalar_t__* id; } ;
struct TYPE_15__ {TYPE_1__ hdr; } ;

/* Variables and functions */
 int COAP_DEFAULT_MAX_RETRANSMIT ; 
 scalar_t__ COAP_INVALID_TID ; 
 int /*<<< orphan*/  NODE_DBG (char*,...) ; 
 int /*<<< orphan*/  SWTIMER_REG_CB (void (*) (void*),int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  SWTIMER_RESUME ; 
 scalar_t__ SYS_TIME_MAX ; 
 scalar_t__ basetime ; 
 int /*<<< orphan*/  coap_delete_node (TYPE_3__*) ; 
 int /*<<< orphan*/  coap_insert_node (TYPE_3__**,TYPE_3__*) ; 
 TYPE_3__* coap_pop_next (TYPE_3__**) ; 
 scalar_t__ coap_send (int /*<<< orphan*/ ,TYPE_8__*) ; 
 int /*<<< orphan*/  coap_timer ; 
 void coap_timer_start (TYPE_3__**) ; 
 int /*<<< orphan*/  os_timer_arm (int /*<<< orphan*/ *,scalar_t__,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  os_timer_disarm (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  os_timer_setfn (int /*<<< orphan*/ *,int /*<<< orphan*/ *,TYPE_3__**) ; 
 int system_get_time () ; 

void coap_timer_elapsed(coap_tick_t *diff){
  coap_tick_t now = system_get_time() / 1000;   // coap_tick_t is in ms. also sys_timer
  if(now>=basetime){
    *diff = now-basetime;
  } else {
    *diff = now + SYS_TIME_MAX -basetime;
  }
  basetime = now;
}

void coap_timer_tick(void *arg){
  if( !arg )
    return;
  coap_queue_t **queue = (coap_queue_t **)arg;
  if( !(*queue) )
    return;

  coap_queue_t *node = coap_pop_next( queue );
  /* re-initialize timeout when maximum number of retransmissions are not reached yet */
  if (node->retransmit_cnt < COAP_DEFAULT_MAX_RETRANSMIT) {
    node->retransmit_cnt++;
    node->t = node->timeout << node->retransmit_cnt;

    NODE_DBG("** retransmission #%d of transaction %d\n",
        node->retransmit_cnt, (((uint16_t)(node->pdu->pkt->hdr.id[0]))<<8)+node->pdu->pkt->hdr.id[1]);
    node->id = coap_send(node->pconn, node->pdu);
    if (COAP_INVALID_TID == node->id) {
      NODE_DBG("retransmission: error sending pdu\n");
      coap_delete_node(node);
    } else {
      coap_insert_node(queue, node);
    }
  } else {
    /* And finally delete the node */
    coap_delete_node( node );
  }

  coap_timer_start(queue);
}

void coap_timer_setup(coap_queue_t ** queue, coap_tick_t t){
  os_timer_disarm(&coap_timer);
  os_timer_setfn(&coap_timer, (os_timer_func_t *)coap_timer_tick, queue);
  SWTIMER_REG_CB(coap_timer_tick, SWTIMER_RESUME);
    //coap_timer_tick processes a queue, my guess is that it is ok to resume the timer from where it left off
  os_timer_arm(&coap_timer, t, 0);   // no repeat
}

void coap_timer_stop(void){
  os_timer_disarm(&coap_timer);
}

void coap_timer_update(coap_queue_t ** queue){
  if (!queue)
    return;
  coap_tick_t diff = 0;
  coap_queue_t *first = *queue;
  coap_timer_elapsed(&diff); // update: basetime = now, diff = now - oldbase, means time elapsed
  if (first) {
    // diff ms time is elapsed, re-calculate the first node->t
    if (first->t >= diff){
      first->t -= diff;
    } else {
      first->t = 0;  // when timer enabled, time out almost immediately
    }
  }
}

void coap_timer_start(coap_queue_t ** queue){
  if(*queue){ // if there is node in the queue, set timeout to its ->t.
    coap_timer_setup(queue, (*queue)->t);
  }
}

