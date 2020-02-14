#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_8__   TYPE_1__ ;

/* Type definitions */
struct TYPE_8__ {struct TYPE_8__* prev; struct TYPE_8__* next; } ;
typedef  TYPE_1__ lwNode ;
typedef  int /*<<< orphan*/  (* ListFreeFunc ) (TYPE_1__*) ;
typedef  scalar_t__ (* ListCompareFunc ) (TYPE_1__*,TYPE_1__*) ;

/* Variables and functions */

void lwListFree( void *list, ListFreeFunc freefunc ){
	lwNode *node, *next;

	node = ( lwNode * ) list;
	while ( node ) {
		next = node->next;
		freefunc( node );
		node = next;
	}
}

void lwListAdd( void **list, void *node ){
	lwNode *head, *tail;

	head = *( ( lwNode ** ) list );
	if ( !head ) {
		*list = node;
		return;
	}
	while ( head ) {
		tail = head;
		head = head->next;
	}
	tail->next = ( lwNode * ) node;
	( ( lwNode * ) node )->prev = tail;
}

void lwListInsert( void **vlist, void *vitem, ListCompareFunc compare ){
	lwNode **list, *item, *node, *prev;

	if ( !*vlist ) {
		*vlist = vitem;
		return;
	}

	list = ( lwNode ** ) vlist;
	item = ( lwNode * ) vitem;
	node = *list;
	prev = NULL;

	while ( node ) {
		if ( 0 < compare( node, item ) ) {
			break;
		}
		prev = node;
		node = node->next;
	}

	if ( !prev ) {
		*list = item;
		node->prev = item;
		item->next = node;
	}
	else if ( !node ) {
		prev->next = item;
		item->prev = prev;
	}
	else {
		item->next = node;
		item->prev = prev;
		prev->next = item;
		node->prev = item;
	}
}

