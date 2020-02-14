#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_25__   TYPE_1__ ;

/* Type definitions */
struct TYPE_25__ {unsigned char* priority; struct TYPE_25__* next; struct TYPE_25__* items; void* data; } ;
typedef  TYPE_1__ pqueue ;
typedef  TYPE_1__* piterator ;
typedef  TYPE_1__ pitem ;

/* Variables and functions */
 int /*<<< orphan*/  ERR_R_MALLOC_FAILURE ; 
 int /*<<< orphan*/  OPENSSL_free (TYPE_1__*) ; 
 TYPE_1__* OPENSSL_malloc (int) ; 
 TYPE_1__* OPENSSL_zalloc (int) ; 
 int /*<<< orphan*/  SSL_F_PITEM_NEW ; 
 int /*<<< orphan*/  SSL_F_PQUEUE_NEW ; 
 int /*<<< orphan*/  SSLerr (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 scalar_t__ memcmp (unsigned char*,unsigned char*,int) ; 
 int /*<<< orphan*/  memcpy (unsigned char*,unsigned char*,int) ; 

pitem *pitem_new(unsigned char *prio64be, void *data)
{
    pitem *item = OPENSSL_malloc(sizeof(*item));

    if (item == NULL) {
        SSLerr(SSL_F_PITEM_NEW, ERR_R_MALLOC_FAILURE);
        return NULL;
    }

    memcpy(item->priority, prio64be, sizeof(item->priority));
    item->data = data;
    item->next = NULL;
    return item;
}

void pitem_free(pitem *item)
{
    OPENSSL_free(item);
}

pqueue *pqueue_new(void)
{
    pqueue *pq = OPENSSL_zalloc(sizeof(*pq));

    if (pq == NULL)
        SSLerr(SSL_F_PQUEUE_NEW, ERR_R_MALLOC_FAILURE);

    return pq;
}

void pqueue_free(pqueue *pq)
{
    OPENSSL_free(pq);
}

pitem *pqueue_insert(pqueue *pq, pitem *item)
{
    pitem *curr, *next;

    if (pq->items == NULL) {
        pq->items = item;
        return item;
    }

    for (curr = NULL, next = pq->items;
         next != NULL; curr = next, next = next->next) {
        /*
         * we can compare 64-bit value in big-endian encoding with memcmp:-)
         */
        int cmp = memcmp(next->priority, item->priority, 8);
        if (cmp > 0) {          /* next > item */
            item->next = next;

            if (curr == NULL)
                pq->items = item;
            else
                curr->next = item;

            return item;
        }

        else if (cmp == 0)      /* duplicates not allowed */
            return NULL;
    }

    item->next = NULL;
    curr->next = item;

    return item;
}

pitem *pqueue_peek(pqueue *pq)
{
    return pq->items;
}

pitem *pqueue_pop(pqueue *pq)
{
    pitem *item = pq->items;

    if (pq->items != NULL)
        pq->items = pq->items->next;

    return item;
}

pitem *pqueue_find(pqueue *pq, unsigned char *prio64be)
{
    pitem *next;
    pitem *found = NULL;

    if (pq->items == NULL)
        return NULL;

    for (next = pq->items; next->next != NULL; next = next->next) {
        if (memcmp(next->priority, prio64be, 8) == 0) {
            found = next;
            break;
        }
    }

    /* check the one last node */
    if (memcmp(next->priority, prio64be, 8) == 0)
        found = next;

    if (!found)
        return NULL;

    return found;
}

pitem *pqueue_iterator(pqueue *pq)
{
    return pqueue_peek(pq);
}

pitem *pqueue_next(piterator *item)
{
    pitem *ret;

    if (item == NULL || *item == NULL)
        return NULL;

    /* *item != NULL */
    ret = *item;
    *item = (*item)->next;

    return ret;
}

size_t pqueue_size(pqueue *pq)
{
    pitem *item = pq->items;
    size_t count = 0;

    while (item != NULL) {
        count++;
        item = item->next;
    }
    return count;
}

