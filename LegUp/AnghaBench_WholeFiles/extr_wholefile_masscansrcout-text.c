#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_2__ ;
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
typedef  unsigned int uint32_t ;
typedef  scalar_t__ time_t ;
struct TYPE_4__ {unsigned int tail; unsigned int head; scalar_t__ sc_dequeue; } ;
struct TYPE_3__ {unsigned int mask; unsigned int head; unsigned int watermark; unsigned int tail; scalar_t__ sp_enqueue; } ;
struct rte_ring {void** ring; TYPE_2__ cons; TYPE_1__ prod; } ;
struct Output {int dummy; } ;
typedef  enum rte_ring_queue_behavior { ____Placeholder_rte_ring_queue_behavior } rte_ring_queue_behavior ;
typedef  enum ApplicationProtocol { ____Placeholder_ApplicationProtocol } ApplicationProtocol ;
typedef  int /*<<< orphan*/  banner_buffer ;
typedef  int /*<<< orphan*/  FILE ;

/* Variables and functions */
 int EDQUOT ; 
 int ENOBUFS ; 
 int ENOENT ; 
 int RTE_RING_QUEUE_FIXED ; 
 int RTE_RING_QUEUE_VARIABLE ; 
 unsigned int RTE_RING_QUOT_EXCEED ; 
 int /*<<< orphan*/  UNUSEDPARM (unsigned int) ; 
 int /*<<< orphan*/  __RING_STAT_ADD (struct rte_ring*,int /*<<< orphan*/ ,unsigned int) ; 
 int /*<<< orphan*/  deq_fail ; 
 int /*<<< orphan*/  deq_success ; 
 int /*<<< orphan*/  enq_fail ; 
 int /*<<< orphan*/  enq_quota ; 
 int /*<<< orphan*/  enq_success ; 
 int /*<<< orphan*/  fprintf (int /*<<< orphan*/ *,char*,...) ; 
 scalar_t__ likely (int) ; 
 char* masscan_app_to_string (int) ; 
 char* name_from_ip_proto (unsigned int) ; 
 char* normalize_string (unsigned char const*,unsigned int,char*,int) ; 
 int rte_atomic32_cmpset (unsigned int*,unsigned int,unsigned int) ; 
 int /*<<< orphan*/  rte_pause () ; 
 int /*<<< orphan*/  rte_rmb () ; 
 int /*<<< orphan*/  rte_wmb () ; 
 char* status_string (int) ; 
 scalar_t__ unlikely (int) ; 

__attribute__((used)) static inline int
__rte_ring_mp_do_enqueue(struct rte_ring *r, void * const *obj_table,
             unsigned n, enum rte_ring_queue_behavior behavior)
{
    uint32_t prod_head, prod_next;
    uint32_t free_entries;
    const unsigned max = n;
    int success;
    unsigned i;
    uint32_t mask = r->prod.mask;
    int ret;

    /* move prod.head atomically */
    do {
        uint32_t cons_tail;
        
        /* Reset n to the initial burst count */
        n = max;

        prod_head = r->prod.head;
        cons_tail = r->cons.tail;
        /* The subtraction is done between two unsigned 32bits value
         * (the result is always modulo 32 bits even if we have
         * prod_head > cons_tail). So 'free_entries' is always between 0
         * and size(ring)-1. */
        free_entries = (mask + cons_tail - prod_head);

        /* check that we have enough room in ring */
        if (unlikely(n > free_entries)) {
            if (behavior == RTE_RING_QUEUE_FIXED) {
                __RING_STAT_ADD(r, enq_fail, n);
                return -ENOBUFS;
            }
            else {
                /* No free entry available */
                if (unlikely(free_entries == 0)) {
                    __RING_STAT_ADD(r, enq_fail, n);
                    return 0;
                }

                n = free_entries;
            }
        }

        prod_next = prod_head + n;
        success = rte_atomic32_cmpset(&r->prod.head, prod_head,
                          prod_next);
    } while (unlikely(success == 0));

    /* write entries in ring */
    for (i = 0; likely(i < n); i++)
        r->ring[(prod_head + i) & mask] = obj_table[i];
    rte_wmb();

    /* if we exceed the watermark */
    if (unlikely(((mask + 1) - free_entries + n) > r->prod.watermark)) {
        ret = (behavior == RTE_RING_QUEUE_FIXED) ? -EDQUOT :
                (int)(n | RTE_RING_QUOT_EXCEED);
        __RING_STAT_ADD(r, enq_quota, n);
    }
    else {
        ret = (behavior == RTE_RING_QUEUE_FIXED) ? 0 : n;
        __RING_STAT_ADD(r, enq_success, n);
    }

    /*
     * If there are other enqueues in progress that preceeded us,
     * we need to wait for them to complete
     */
    while (unlikely(r->prod.tail != prod_head))
        rte_pause();

    r->prod.tail = prod_next;
    return ret;
}

__attribute__((used)) static inline int
__rte_ring_sp_do_enqueue(struct rte_ring *r, void * const *obj_table,
             unsigned n, enum rte_ring_queue_behavior behavior)
{
    uint32_t prod_head, cons_tail;
    uint32_t prod_next, free_entries;
    unsigned i;
    uint32_t mask = r->prod.mask;
    int ret;

    prod_head = r->prod.head;
    cons_tail = r->cons.tail;
    /* The subtraction is done between two unsigned 32bits value
     * (the result is always modulo 32 bits even if we have
     * prod_head > cons_tail). So 'free_entries' is always between 0
     * and size(ring)-1. */
    free_entries = mask + cons_tail - prod_head;

    /* check that we have enough room in ring */
    if (unlikely(n > free_entries)) {
        if (behavior == RTE_RING_QUEUE_FIXED) {
            __RING_STAT_ADD(r, enq_fail, n);
            return -ENOBUFS;
        }
        else {
            /* No free entry available */
            if (unlikely(free_entries == 0)) {
                __RING_STAT_ADD(r, enq_fail, n);
                return 0;
            }

            n = free_entries;
        }
    }

    prod_next = prod_head + n;
    r->prod.head = prod_next;

    /* write entries in ring */
    for (i = 0; likely(i < n); i++)
        r->ring[(prod_head + i) & mask] = obj_table[i];
    rte_wmb();

    /* if we exceed the watermark */
    if (unlikely(((mask + 1) - free_entries + n) > r->prod.watermark)) {
        ret = (behavior == RTE_RING_QUEUE_FIXED) ? -EDQUOT :
            (int)(n | RTE_RING_QUOT_EXCEED);
        __RING_STAT_ADD(r, enq_quota, n);
    }
    else {
        ret = (behavior == RTE_RING_QUEUE_FIXED) ? 0 : n;
        __RING_STAT_ADD(r, enq_success, n);
    }

    r->prod.tail = prod_next;
    return ret;
}

__attribute__((used)) static inline int
__rte_ring_mc_do_dequeue(struct rte_ring *r, void **obj_table,
         unsigned n, enum rte_ring_queue_behavior behavior)
{
    uint32_t cons_head;
    uint32_t cons_next;
    const unsigned max = n;
    int success;
    unsigned i;
    uint32_t mask = r->prod.mask;

    /* move cons.head atomically */
    do {
        uint32_t prod_tail;
        uint32_t entries;
        
        /* Restore n as it may change every loop */
        n = max;

        cons_head = r->cons.head;
        prod_tail = r->prod.tail;
        /* The subtraction is done between two unsigned 32bits value
         * (the result is always modulo 32 bits even if we have
         * cons_head > prod_tail). So 'entries' is always between 0
         * and size(ring)-1. */
        entries = (prod_tail - cons_head);

        /* Set the actual entries for dequeue */
        if (unlikely(n > entries)) {
            if (behavior == RTE_RING_QUEUE_FIXED) {
                __RING_STAT_ADD(r, deq_fail, n);
                return -ENOENT;
            }
            else {
                if (unlikely(entries == 0)){
                    __RING_STAT_ADD(r, deq_fail, n);
                    return 0;
                }

                n = entries;
            }
        }

        cons_next = cons_head + n;
        success = rte_atomic32_cmpset(&r->cons.head, cons_head,
                          cons_next);
    } while (unlikely(success == 0));

    /* copy in table */
    rte_rmb();
    for (i = 0; likely(i < n); i++) {
        obj_table[i] = r->ring[(cons_head + i) & mask];
    }

    /*
     * If there are other dequeues in progress that preceded us,
     * we need to wait for them to complete
     */
    while (unlikely(r->cons.tail != cons_head))
        rte_pause();

    __RING_STAT_ADD(r, deq_success, n);
    r->cons.tail = cons_next;

    return behavior == RTE_RING_QUEUE_FIXED ? 0 : n;
}

__attribute__((used)) static inline int
__rte_ring_sc_do_dequeue(struct rte_ring *r, void **obj_table,
         unsigned n, enum rte_ring_queue_behavior behavior)
{
    uint32_t cons_head, prod_tail;
    uint32_t cons_next, entries;
    unsigned i;
    uint32_t mask = r->prod.mask;

    cons_head = r->cons.head;
    prod_tail = r->prod.tail;
    /* The subtraction is done between two unsigned 32bits value
     * (the result is always modulo 32 bits even if we have
     * cons_head > prod_tail). So 'entries' is always between 0
     * and size(ring)-1. */
    entries = prod_tail - cons_head;

    if (unlikely(n > entries)) {
        if (behavior == RTE_RING_QUEUE_FIXED) {
            __RING_STAT_ADD(r, deq_fail, n);
            return -ENOENT;
        }
        else {
            if (unlikely(entries == 0)){
                __RING_STAT_ADD(r, deq_fail, n);
                return 0;
            }

            n = entries;
        }
    }

    cons_next = cons_head + n;
    r->cons.head = cons_next;

    /* copy in table */
    rte_rmb();
    for (i = 0; likely(i < n); i++) {
        /* WTF??? WHY DOES THIS CODE GIVE STRICT-ALIASING WARNINGS
         * ON SOME GCC. THEY ARE FREAKING VOID* !!! */
        obj_table[i] = r->ring[(cons_head + i) & mask];
    }

    __RING_STAT_ADD(r, deq_success, n);
    r->cons.tail = cons_next;
    return behavior == RTE_RING_QUEUE_FIXED ? 0 : n;
}

__attribute__((used)) static inline int
rte_ring_mp_enqueue_bulk(struct rte_ring *r, void * const *obj_table,
             unsigned n)
{
    return __rte_ring_mp_do_enqueue(r, obj_table, n, RTE_RING_QUEUE_FIXED);
}

__attribute__((used)) static inline int
rte_ring_sp_enqueue_bulk(struct rte_ring *r, void * const *obj_table,
             unsigned n)
{
    return __rte_ring_sp_do_enqueue(r, obj_table, n, RTE_RING_QUEUE_FIXED);
}

__attribute__((used)) static inline int
rte_ring_enqueue_bulk(struct rte_ring *r, void * const *obj_table,
              unsigned n)
{
    if (r->prod.sp_enqueue)
        return rte_ring_sp_enqueue_bulk(r, obj_table, n);
    else
        return rte_ring_mp_enqueue_bulk(r, obj_table, n);
}

__attribute__((used)) static inline int
rte_ring_mp_enqueue(struct rte_ring *r, void *obj)
{
    return rte_ring_mp_enqueue_bulk(r, &obj, 1);
}

__attribute__((used)) static inline int
rte_ring_sp_enqueue(struct rte_ring *r, void *obj)
{
    return rte_ring_sp_enqueue_bulk(r, &obj, 1);
}

__attribute__((used)) static inline int
rte_ring_enqueue(struct rte_ring *r, void *obj)
{
    if (r->prod.sp_enqueue)
        return rte_ring_sp_enqueue(r, obj);
    else
        return rte_ring_mp_enqueue(r, obj);
}

__attribute__((used)) static inline int
rte_ring_mc_dequeue_bulk(struct rte_ring *r, void **obj_table, unsigned n)
{
    return __rte_ring_mc_do_dequeue(r, obj_table, n, RTE_RING_QUEUE_FIXED);
}

__attribute__((used)) static inline int
rte_ring_sc_dequeue_bulk(struct rte_ring *r, void **obj_table, unsigned n)
{
    return __rte_ring_sc_do_dequeue(r, obj_table, n, RTE_RING_QUEUE_FIXED);
}

__attribute__((used)) static inline int
rte_ring_dequeue_bulk(struct rte_ring *r, void **obj_table, unsigned n)
{
    if (r->cons.sc_dequeue)
        return rte_ring_sc_dequeue_bulk(r, obj_table, n);
    else
        return rte_ring_mc_dequeue_bulk(r, obj_table, n);
}

__attribute__((used)) static inline int
rte_ring_mc_dequeue(struct rte_ring *r, void **obj_p)
{
    return rte_ring_mc_dequeue_bulk(r, obj_p, 1);
}

__attribute__((used)) static inline int
rte_ring_sc_dequeue(struct rte_ring *r, void **obj_p)
{
    return rte_ring_sc_dequeue_bulk(r, obj_p, 1);
}

__attribute__((used)) static inline int
rte_ring_dequeue(struct rte_ring *r, void **obj_p)
{
    if (r->cons.sc_dequeue)
        return rte_ring_sc_dequeue(r, obj_p);
    else
        return rte_ring_mc_dequeue(r, obj_p);
}

__attribute__((used)) static inline int
rte_ring_full(const struct rte_ring *r)
{
    uint32_t prod_tail = r->prod.tail;
    uint32_t cons_tail = r->cons.tail;
    return (((cons_tail - prod_tail - 1) & r->prod.mask) == 0);
}

__attribute__((used)) static inline int
rte_ring_empty(const struct rte_ring *r)
{
    uint32_t prod_tail = r->prod.tail;
    uint32_t cons_tail = r->cons.tail;
    return !!(cons_tail == prod_tail);
}

__attribute__((used)) static inline unsigned
rte_ring_count(const struct rte_ring *r)
{
    uint32_t prod_tail = r->prod.tail;
    uint32_t cons_tail = r->cons.tail;
    return ((prod_tail - cons_tail) & r->prod.mask);
}

__attribute__((used)) static inline unsigned
rte_ring_free_count(const struct rte_ring *r)
{
    uint32_t prod_tail = r->prod.tail;
    uint32_t cons_tail = r->cons.tail;
    return ((cons_tail - prod_tail - 1) & r->prod.mask);
}

__attribute__((used)) static inline int
rte_ring_mp_enqueue_burst(struct rte_ring *r, void * const *obj_table,
             unsigned n)
{
    return __rte_ring_mp_do_enqueue(r, obj_table, n, RTE_RING_QUEUE_VARIABLE);
}

__attribute__((used)) static inline int
rte_ring_sp_enqueue_burst(struct rte_ring *r, void * const *obj_table,
             unsigned n)
{
    return __rte_ring_sp_do_enqueue(r, obj_table, n, RTE_RING_QUEUE_VARIABLE);
}

__attribute__((used)) static inline int
rte_ring_enqueue_burst(struct rte_ring *r, void * const *obj_table,
              unsigned n)
{
    if (r->prod.sp_enqueue)
        return    rte_ring_sp_enqueue_burst(r, obj_table, n);
    else
        return    rte_ring_mp_enqueue_burst(r, obj_table, n);
}

__attribute__((used)) static inline int
rte_ring_mc_dequeue_burst(struct rte_ring *r, void **obj_table, unsigned n)
{
    return __rte_ring_mc_do_dequeue(r, obj_table, n, RTE_RING_QUEUE_VARIABLE);
}

__attribute__((used)) static inline int
rte_ring_sc_dequeue_burst(struct rte_ring *r, void **obj_table, unsigned n)
{
    return __rte_ring_sc_do_dequeue(r, obj_table, n, RTE_RING_QUEUE_VARIABLE);
}

__attribute__((used)) static inline int
rte_ring_dequeue_burst(struct rte_ring *r, void **obj_table, unsigned n)
{
    if (r->cons.sc_dequeue)
        return rte_ring_sc_dequeue_burst(r, obj_table, n);
    else
        return rte_ring_mc_dequeue_burst(r, obj_table, n);
}

__attribute__((used)) static void
text_out_open(struct Output *out, FILE *fp)
{
    UNUSEDPARM(out);
    fprintf(fp, "#masscan\n");
}

__attribute__((used)) static void
text_out_close(struct Output *out, FILE *fp)
{
    UNUSEDPARM(out);
    fprintf(fp, "# end\n");
}

__attribute__((used)) static void
text_out_status(struct Output *out, FILE *fp, time_t timestamp,
    int status, unsigned ip, unsigned ip_proto, unsigned port, unsigned reason, unsigned ttl)
{
    UNUSEDPARM(ttl);
    UNUSEDPARM(reason);
    UNUSEDPARM(out);


    fprintf(fp, "%s %s %u %u.%u.%u.%u %u\n",
        status_string(status),
        name_from_ip_proto(ip_proto),
        port,
        (ip>>24)&0xFF,
        (ip>>16)&0xFF,
        (ip>> 8)&0xFF,
        (ip>> 0)&0xFF,
        (unsigned)timestamp
        );
}

__attribute__((used)) static void
text_out_banner(struct Output *out, FILE *fp, time_t timestamp,
        unsigned ip, unsigned ip_proto, unsigned port,
        enum ApplicationProtocol proto, unsigned ttl,
        const unsigned char *px, unsigned length)
{
    char banner_buffer[4096];


    UNUSEDPARM(out);
    UNUSEDPARM(ttl);

    fprintf(fp, "%s %s %u %u.%u.%u.%u %u %s %s\n",
        "banner",
        name_from_ip_proto(ip_proto),
        port,
        (ip>>24)&0xFF,
        (ip>>16)&0xFF,
        (ip>> 8)&0xFF,
        (ip>> 0)&0xFF,
        (unsigned)timestamp,
        masscan_app_to_string(proto),
        normalize_string(px, length, banner_buffer, sizeof(banner_buffer))
        );
}

