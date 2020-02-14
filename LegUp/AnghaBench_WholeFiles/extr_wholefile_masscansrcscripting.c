#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_6__   TYPE_3__ ;
typedef  struct TYPE_5__   TYPE_2__ ;
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
typedef  unsigned int uint32_t ;
struct TYPE_5__ {unsigned int tail; unsigned int head; scalar_t__ sc_dequeue; } ;
struct TYPE_4__ {unsigned int mask; unsigned int head; unsigned int watermark; unsigned int tail; scalar_t__ sp_enqueue; } ;
struct rte_ring {void** ring; TYPE_2__ cons; TYPE_1__ prod; } ;
struct lua_State {int dummy; } ;
struct TYPE_6__ {char* name; struct lua_State* L; } ;
struct Masscan {TYPE_3__ scripting; } ;
typedef  enum rte_ring_queue_behavior { ____Placeholder_rte_ring_queue_behavior } rte_ring_queue_behavior ;

/* Variables and functions */
 int EDQUOT ; 
 int ENOBUFS ; 
 int ENOENT ; 
 int /*<<< orphan*/  LOG (int,char*,...) ; 
 int LUA_OK ; 
 int RTE_RING_QUEUE_FIXED ; 
 int RTE_RING_QUEUE_VARIABLE ; 
 unsigned int RTE_RING_QUOT_EXCEED ; 
 int /*<<< orphan*/  __RING_STAT_ADD (struct rte_ring*,int /*<<< orphan*/ ,unsigned int) ; 
 int /*<<< orphan*/  deq_fail ; 
 int /*<<< orphan*/  deq_success ; 
 int /*<<< orphan*/  enq_fail ; 
 int /*<<< orphan*/  enq_quota ; 
 int /*<<< orphan*/  enq_success ; 
 int /*<<< orphan*/  exit (int) ; 
 scalar_t__ likely (int) ; 
 int luaL_loadfile (struct lua_State*,char const*) ; 
 struct lua_State* luaL_newstate () ; 
 int /*<<< orphan*/  luaL_openlibs (struct lua_State*) ; 
 int /*<<< orphan*/  lua_close (struct lua_State*) ; 
 int lua_pcall (struct lua_State*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  lua_tostring (struct lua_State*,int) ; 
 scalar_t__* lua_version (int /*<<< orphan*/ ) ; 
 int rte_atomic32_cmpset (unsigned int*,unsigned int,unsigned int) ; 
 int /*<<< orphan*/  rte_pause () ; 
 int /*<<< orphan*/  rte_rmb () ; 
 int /*<<< orphan*/  rte_wmb () ; 
 int /*<<< orphan*/  scripting_masscan_init (struct Masscan*) ; 
 int /*<<< orphan*/  stublua_init () ; 
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

void
scripting_init(struct Masscan *masscan)
{
    int version;
    struct lua_State *L;
    const char *filename = masscan->scripting.name;
    int x;

    
    if (filename == 0 || filename[0] == '\0') {
        LOG(0, "%s: no script specified, use --script option\n", "SCRIPTING");
        exit(1);
    }
    
    /* Dynamically link the library */
    stublua_init();
    
    /* Test to see if the loading was successful */
    version = (int)*lua_version(0);
    LOG(1, "Lua version = %d\n", version);
    if (version != 503 && version != 502) {
        LOG(0, "Unable to load Lua library\n");
        exit(1);
    }
    
    /*
     * Create a Lua VM
     */
    L = luaL_newstate();
    luaL_openlibs(L);
    masscan->scripting.L = L;
    
    /*
     * TODO: Sanbox stuff
     */
    /* We need to do a bunch of sandboxing here to prevent hostile or badly
     * written scripts from disrupting the system */
    
    /*
     * Create the Masscan object
     */
    scripting_masscan_init(masscan);
    
    /*
     * Load the script. This will verify the syntax.
     */
    x = luaL_loadfile(L, filename);
    if (x != LUA_OK) {
        LOG(0, "%s error loading: %s: %s\n", "SCRIPTING:", filename, lua_tostring(L, -1));
        lua_close(L);
        exit(1);
    }
    
    /*
     * Lua: Start running the script. At this stage, the "onConnection()" function doesn't
     * run. Instead, it's registered as a global function to be called later.
     */
    LOG(1, "%s running script: %s\n", "SCRIPTING:", filename);
    x = lua_pcall(L, 0, 0, 0);
    if (x != LUA_OK) {
        LOG(0, "%s error running: %s: %s\n", "SCRIPTING:", filename, lua_tostring(L, -1));
        lua_close(L);
        exit(1);
    }

}

