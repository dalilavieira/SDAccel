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
struct TYPE_3__ {int /*<<< orphan*/ * header_output; int /*<<< orphan*/ * header; int /*<<< orphan*/ * data; } ;
struct web_client {int ifd; int ofd; struct web_client* prev; struct web_client* next; int /*<<< orphan*/  client_port; int /*<<< orphan*/  client_ip; int /*<<< orphan*/  id; int /*<<< orphan*/  mode; TYPE_1__ response; struct web_client* user_agent; } ;
struct TYPE_4__ {int used_count; int avail_count; int allocated; int reused; struct web_client* avail; struct web_client* used; } ;
typedef  int /*<<< orphan*/  BUFFER ;

/* Variables and functions */
 int /*<<< orphan*/  D_WEB_CLIENT_ACCESS ; 
 int /*<<< orphan*/  NETDATA_WEB_RESPONSE_HEADER_SIZE ; 
 int /*<<< orphan*/  NETDATA_WEB_RESPONSE_INITIAL_SIZE ; 
 int /*<<< orphan*/  WEB_CLIENT_MODE_NORMAL ; 
 scalar_t__ WEB_SERVER_MODE_STATIC_THREADED ; 
 void* buffer_create (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  buffer_flush (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  buffer_free (int /*<<< orphan*/ *) ; 
 struct web_client* callocz (int,int) ; 
 int /*<<< orphan*/  close (int) ; 
 int /*<<< orphan*/  debug (int /*<<< orphan*/ ,char*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  freez (struct web_client*) ; 
 int /*<<< orphan*/  info (char*,int,int,int,int,int) ; 
 int /*<<< orphan*/  memset (struct web_client*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  netdata_thread_disable_cancelability () ; 
 int /*<<< orphan*/  netdata_thread_enable_cancelability () ; 
 scalar_t__ unlikely (int) ; 
 int /*<<< orphan*/  web_client_connected () ; 
 int /*<<< orphan*/  web_client_disconnected () ; 
 int /*<<< orphan*/  web_client_request_done (struct web_client*) ; 
 TYPE_2__ web_clients_cache ; 
 int /*<<< orphan*/  web_server_log_connection (struct web_client*,char*) ; 
 scalar_t__ web_server_mode ; 

__attribute__((used)) static void web_client_zero(struct web_client *w) {
    // zero everything about it - but keep the buffers

    // remember the pointers to the buffers
    BUFFER *b1 = w->response.data;
    BUFFER *b2 = w->response.header;
    BUFFER *b3 = w->response.header_output;

    // empty the buffers
    buffer_flush(b1);
    buffer_flush(b2);
    buffer_flush(b3);

    freez(w->user_agent);

    // zero everything
    memset(w, 0, sizeof(struct web_client));

    // restore the pointers of the buffers
    w->response.data = b1;
    w->response.header = b2;
    w->response.header_output = b3;
}

__attribute__((used)) static void web_client_free(struct web_client *w) {
    buffer_free(w->response.header_output);
    buffer_free(w->response.header);
    buffer_free(w->response.data);
    freez(w->user_agent);
    freez(w);
}

__attribute__((used)) static struct web_client *web_client_alloc(void) {
    struct web_client *w = callocz(1, sizeof(struct web_client));
    w->response.data = buffer_create(NETDATA_WEB_RESPONSE_INITIAL_SIZE);
    w->response.header = buffer_create(NETDATA_WEB_RESPONSE_HEADER_SIZE);
    w->response.header_output = buffer_create(NETDATA_WEB_RESPONSE_HEADER_SIZE);
    return w;
}

inline void web_client_cache_verify(int force) {
#ifdef NETDATA_INTERNAL_CHECKS
    static __thread size_t count = 0;
    count++;

    if(unlikely(force || count > 1000)) {
        count = 0;

        struct web_client *w;
        size_t used = 0, avail = 0;
        for(w = web_clients_cache.used; w ; w = w->next) used++;
        for(w = web_clients_cache.avail; w ; w = w->next) avail++;

        info("web_client_cache has %zu (%zu) used and %zu (%zu) available clients, allocated %zu, reused %zu (hit %zu%%)."
             , used, web_clients_cache.used_count
             , avail, web_clients_cache.avail_count
             , web_clients_cache.allocated
             , web_clients_cache.reused
             , (web_clients_cache.allocated + web_clients_cache.reused)?(web_clients_cache.reused * 100 / (web_clients_cache.allocated + web_clients_cache.reused)):0
        );
    }
#else
    if(unlikely(force)) {
        info("web_client_cache has %zu used and %zu available clients, allocated %zu, reused %zu (hit %zu%%)."
             , web_clients_cache.used_count
             , web_clients_cache.avail_count
             , web_clients_cache.allocated
             , web_clients_cache.reused
             , (web_clients_cache.allocated + web_clients_cache.reused)?(web_clients_cache.reused * 100 / (web_clients_cache.allocated + web_clients_cache.reused)):0
            );
    }
#endif
}

void web_client_cache_destroy(void) {
#ifdef NETDATA_INTERNAL_CHECKS
    if(unlikely(web_clients_cache.pid != 0 && web_clients_cache.pid != gettid()))
        error("Oops! wrong thread accessing the cache. Expected %d, found %d", (int)web_clients_cache.pid, (int)gettid());

    web_client_cache_verify(1);
#endif

    netdata_thread_disable_cancelability();

    struct web_client *w, *t;

    w = web_clients_cache.used;
    while(w) {
        t = w;
        w = w->next;
        web_client_free(t);
    }
    web_clients_cache.used = NULL;
    web_clients_cache.used_count = 0;

    w = web_clients_cache.avail;
    while(w) {
        t = w;
        w = w->next;
        web_client_free(t);
    }
    web_clients_cache.avail = NULL;
    web_clients_cache.avail_count = 0;

    netdata_thread_enable_cancelability();
}

struct web_client *web_client_get_from_cache_or_allocate() {

#ifdef NETDATA_INTERNAL_CHECKS
    if(unlikely(web_clients_cache.pid == 0))
        web_clients_cache.pid = gettid();

    if(unlikely(web_clients_cache.pid != 0 && web_clients_cache.pid != gettid()))
        error("Oops! wrong thread accessing the cache. Expected %d, found %d", (int)web_clients_cache.pid, (int)gettid());
#endif

    netdata_thread_disable_cancelability();

    struct web_client *w = web_clients_cache.avail;

    if(w) {
        // get it from avail
        if (w == web_clients_cache.avail) web_clients_cache.avail = w->next;
        if(w->prev) w->prev->next = w->next;
        if(w->next) w->next->prev = w->prev;
        web_clients_cache.avail_count--;
        web_client_zero(w);
        web_clients_cache.reused++;
    }
    else {
        // allocate it
        w = web_client_alloc();
        web_clients_cache.allocated++;
    }

    // link it to used web clients
    if (web_clients_cache.used) web_clients_cache.used->prev = w;
    w->next = web_clients_cache.used;
    w->prev = NULL;
    web_clients_cache.used = w;
    web_clients_cache.used_count++;

    // initialize it
    w->id = web_client_connected();
    w->mode = WEB_CLIENT_MODE_NORMAL;

    netdata_thread_enable_cancelability();

    return w;
}

void web_client_release(struct web_client *w) {
#ifdef NETDATA_INTERNAL_CHECKS
    if(unlikely(web_clients_cache.pid != 0 && web_clients_cache.pid != gettid()))
        error("Oops! wrong thread accessing the cache. Expected %d, found %d", (int)web_clients_cache.pid, (int)gettid());

    if(unlikely(w->running))
        error("%llu: releasing web client from %s port %s, but it still running.", w->id, w->client_ip, w->client_port);
#endif

    debug(D_WEB_CLIENT_ACCESS, "%llu: Closing web client from %s port %s.", w->id, w->client_ip, w->client_port);

    web_server_log_connection(w, "DISCONNECTED");
    web_client_request_done(w);
    web_client_disconnected();

    netdata_thread_disable_cancelability();

    if(web_server_mode != WEB_SERVER_MODE_STATIC_THREADED) {
        if (w->ifd != -1) close(w->ifd);
        if (w->ofd != -1 && w->ofd != w->ifd) close(w->ofd);
        w->ifd = w->ofd = -1;
    }

    // unlink it from the used
    if (w == web_clients_cache.used) web_clients_cache.used = w->next;
    if(w->prev) w->prev->next = w->next;
    if(w->next) w->next->prev = w->prev;
    web_clients_cache.used_count--;

    if(web_clients_cache.avail_count >= 2 * web_clients_cache.used_count) {
        // we have too many of them - free it
        web_client_free(w);
    }
    else {
        // link it to the avail
        if (web_clients_cache.avail) web_clients_cache.avail->prev = w;
        w->next = web_clients_cache.avail;
        w->prev = NULL;
        web_clients_cache.avail = w;
        web_clients_cache.avail_count++;
    }

    netdata_thread_enable_cancelability();
}

