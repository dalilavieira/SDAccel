#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_10__   TYPE_1__ ;

/* Type definitions */
struct TYPE_10__ {size_t handle; long size; long max; long node; long freeList; int /*<<< orphan*/ * key; struct TYPE_10__* handles; struct TYPE_10__* nodes; int /*<<< orphan*/  initialized; } ;
typedef  TYPE_1__ PriorityQ ;
typedef  TYPE_1__ PQnode ;
typedef  TYPE_1__ PQhandleElem ;
typedef  size_t PQhandle ;

/* Variables and functions */
 scalar_t__ LEQ (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  TRUE ; 
 int /*<<< orphan*/  assert (int) ; 
 int /*<<< orphan*/  memFree (TYPE_1__*) ; 

void pqDeletePriorityQ( PriorityQ *pq )
{
  memFree( pq->handles );
  memFree( pq->nodes );
  memFree( pq );
}

__attribute__((used)) static void FloatDown( PriorityQ *pq, long curr )
{
  PQnode *n = pq->nodes;
  PQhandleElem *h = pq->handles;
  PQhandle hCurr, hChild;
  long child;

  hCurr = n[curr].handle;
  for( ;; ) {
    child = curr << 1;
    if( child < pq->size && LEQ( h[n[child+1].handle].key,
				 h[n[child].handle].key )) {
      ++child;
    }

    assert(child <= pq->max);

    hChild = n[child].handle;
    if( child > pq->size || LEQ( h[hCurr].key, h[hChild].key )) {
      n[curr].handle = hCurr;
      h[hCurr].node = curr;
      break;
    }
    n[curr].handle = hChild;
    h[hChild].node = curr;
    curr = child;
  }
}

__attribute__((used)) static void FloatUp( PriorityQ *pq, long curr )
{
  PQnode *n = pq->nodes;
  PQhandleElem *h = pq->handles;
  PQhandle hCurr, hParent;
  long parent;

  hCurr = n[curr].handle;
  for( ;; ) {
    parent = curr >> 1;
    hParent = n[parent].handle;
    if( parent == 0 || LEQ( h[hParent].key, h[hCurr].key )) {
      n[curr].handle = hCurr;
      h[hCurr].node = curr;
      break;
    }
    n[curr].handle = hParent;
    h[hParent].node = curr;
    curr = parent;
  }
}

void pqInit( PriorityQ *pq )
{
  long i;

  /* This method of building a heap is O(n), rather than O(n lg n). */

  for( i = pq->size; i >= 1; --i ) {
    FloatDown( pq, i );
  }
  pq->initialized = TRUE;
}

void pqDelete( PriorityQ *pq, PQhandle hCurr )
{
  PQnode *n = pq->nodes;
  PQhandleElem *h = pq->handles;
  long curr;

  assert( hCurr >= 1 && hCurr <= pq->max && h[hCurr].key != NULL );

  curr = h[hCurr].node;
  n[curr].handle = n[pq->size].handle;
  h[n[curr].handle].node = curr;

  if( curr <= -- pq->size ) {
    if( curr <= 1 || LEQ( h[n[curr>>1].handle].key, h[n[curr].handle].key )) {
      FloatDown( pq, curr );
    } else {
      FloatUp( pq, curr );
    }
  }
  h[hCurr].key = NULL;
  h[hCurr].node = pq->freeList;
  pq->freeList = hCurr;
}

