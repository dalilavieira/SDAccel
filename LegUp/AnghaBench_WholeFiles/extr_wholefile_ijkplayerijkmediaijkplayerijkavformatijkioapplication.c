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
struct TYPE_10__ {int /*<<< orphan*/  (* func_ijkio_on_app_event ) (TYPE_1__*,int /*<<< orphan*/ ,void*,int) ;void* opaque; } ;
typedef  TYPE_1__ IjkIOApplicationContext ;
typedef  int /*<<< orphan*/  IjkIOAppCacheStatistic ;

/* Variables and functions */
 int /*<<< orphan*/  IJKIOAPP_EVENT_CACHE_STATISTIC ; 
 TYPE_1__* calloc (int,int) ; 
 int /*<<< orphan*/  free (TYPE_1__*) ; 
 int /*<<< orphan*/  stub1 (TYPE_1__*,int /*<<< orphan*/ ,void*,int) ; 

int  ijkio_application_alloc(IjkIOApplicationContext **ph, void *opaque) {
    IjkIOApplicationContext *h = NULL;

    h = calloc(1, sizeof(IjkIOApplicationContext));
    if (!h)
        return -1;

    h->opaque = opaque;

    *ph = h;
    return 0;
}

int  ijkio_application_open(IjkIOApplicationContext **ph, void *opaque) {
    int ret = ijkio_application_alloc(ph, opaque);
    if (ret)
        return ret;

    return 0;
}

void ijkio_application_close(IjkIOApplicationContext *h) {
    free(h);
}

void ijkio_application_closep(IjkIOApplicationContext **ph) {
    if (!ph || !*ph)
        return;

    ijkio_application_close(*ph);
    *ph = NULL;
}

void ijkio_application_on_cache_statistic(IjkIOApplicationContext *h, IjkIOAppCacheStatistic *statistic) {
    if (h && h->func_ijkio_on_app_event)
        h->func_ijkio_on_app_event(h, IJKIOAPP_EVENT_CACHE_STATISTIC, (void *)statistic, sizeof(IjkIOAppCacheStatistic));
}

