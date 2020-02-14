#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_16__   TYPE_1__ ;

/* Type definitions */
typedef  scalar_t__ coap_tid_t ;
struct TYPE_16__ {scalar_t__ t; scalar_t__ const id; struct TYPE_16__* next; int /*<<< orphan*/  pdu; } ;
typedef  TYPE_1__ coap_queue_t ;

/* Variables and functions */
 int /*<<< orphan*/  c_free (TYPE_1__*) ; 
 int /*<<< orphan*/  c_memset (TYPE_1__*,int /*<<< orphan*/ ,int) ; 
 scalar_t__ c_zalloc (int) ; 
 int /*<<< orphan*/  coap_delete_pdu (int /*<<< orphan*/ ) ; 

__attribute__((used)) static inline coap_queue_t *
coap_malloc_node(void) {
  return (coap_queue_t *)c_zalloc(sizeof(coap_queue_t));
}

void coap_free_node(coap_queue_t *node) {
  c_free(node);
}

int coap_insert_node(coap_queue_t **queue, coap_queue_t *node) {
  coap_queue_t *p, *q;
  if ( !queue || !node )
    return 0;

  /* set queue head if empty */
  if ( !*queue ) {
    *queue = node;
    return 1;
  }

  /* replace queue head if PDU's time is less than head's time */
  q = *queue;
  if (node->t < q->t) {
    node->next = q;
    *queue = node;
    q->t -= node->t;		/* make q->t relative to node->t */
    return 1;
  }

  /* search for right place to insert */
  do {
    node->t -= q->t;		/* make node-> relative to q->t */
    p = q;
    q = q->next;
  } while (q && q->t <= node->t);

  /* insert new item */
  if (q) {
    q->t -= node->t;		/* make q->t relative to node->t */
  }
  node->next = q;
  p->next = node;
  return 1;
}

int coap_delete_node(coap_queue_t *node) {
  if ( !node )
    return 0;

  coap_delete_pdu(node->pdu);
  coap_free_node(node);

  return 1;
}

void coap_delete_all(coap_queue_t *queue) {
  if ( !queue )
    return;

  coap_delete_all( queue->next );
  coap_delete_node( queue );
}

coap_queue_t * coap_new_node(void) {
  coap_queue_t *node;
  node = coap_malloc_node();

  if ( ! node ) {
    return NULL;
  }

  c_memset(node, 0, sizeof(*node));
  return node;
}

coap_queue_t * coap_peek_next( coap_queue_t *queue ) {
  if ( !queue )
    return NULL;

  return queue;
}

coap_queue_t * coap_pop_next( coap_queue_t **queue ) {		// this function is called inside timeout callback only.
  coap_queue_t *next;

  if ( !(*queue) )
    return NULL;

  next = *queue;
  *queue = (*queue)->next;
  // if (queue) {
  //   queue->t += next->t;
  // }
  next->next = NULL;
  return next;
}

int coap_remove_node( coap_queue_t **queue, const coap_tid_t id){
  coap_queue_t *p, *q, *node;
  if ( !queue )
    return 0;
  if ( !*queue )  // if empty
    return 0;

  q = *queue;
  if (q->id == id) {
    node = q;
    *queue = q->next;
    node->next = NULL;
    if(*queue){
      (*queue)->t += node->t;
    }
    coap_delete_node(node);
    return 1;
  }

  /* search for right node to remove */
  while (q && q->id != id) {
    p = q;
    q = q->next;
  }

  /* find the node */
  if (q) {
    node = q; /* save the node */
    p->next = q->next;  /* remove the node */
    q = q->next;
    node->next = NULL;
    if (q)   // add node->t to the node after.
    {
      q->t += node->t;
    }
    coap_delete_node(node);
    return 1;
  }
  return 0;
}

