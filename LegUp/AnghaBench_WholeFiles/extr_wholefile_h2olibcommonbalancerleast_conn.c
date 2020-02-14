#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_16__   TYPE_6__ ;
typedef  struct TYPE_15__   TYPE_5__ ;
typedef  struct TYPE_14__   TYPE_4__ ;
typedef  struct TYPE_13__   TYPE_3__ ;
typedef  struct TYPE_12__   TYPE_2__ ;
typedef  struct TYPE_11__   TYPE_1__ ;

/* Type definitions */
typedef  size_t uint64_t ;
struct TYPE_15__ {TYPE_6__ const* callbacks; } ;
struct least_conn_t {TYPE_5__ super; int /*<<< orphan*/  mutex; } ;
struct TYPE_14__ {size_t size; TYPE_3__** entries; } ;
typedef  TYPE_4__ h2o_socketpool_target_vector_t ;
typedef  TYPE_5__ h2o_balancer_t ;
struct TYPE_16__ {size_t (* member_0 ) (TYPE_5__*,TYPE_4__*,char*) ;void (* member_1 ) (TYPE_5__*) ;} ;
typedef  TYPE_6__ h2o_balancer_callbacks_t ;
struct TYPE_12__ {scalar_t__ weight_m1; } ;
struct TYPE_11__ {size_t leased_count; } ;
struct TYPE_13__ {TYPE_2__ conf; TYPE_1__ _shared; } ;

/* Variables and functions */
 int /*<<< orphan*/  assert (int) ; 
 int /*<<< orphan*/  free (struct least_conn_t*) ; 
 struct least_conn_t* h2o_mem_alloc (int) ; 
 int /*<<< orphan*/  pthread_mutex_destroy (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  pthread_mutex_init (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  pthread_mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  pthread_mutex_unlock (int /*<<< orphan*/ *) ; 

__attribute__((used)) static size_t selector(h2o_balancer_t *_self, h2o_socketpool_target_vector_t *targets, char *tried)
{
    struct least_conn_t *self = (void *)_self;
    size_t i;
    size_t result_index = -1;
    size_t result_weight = 0;
    size_t result_leased = 1;
    uint64_t leftprod, rightprod;

    assert(targets->size != 0);
    pthread_mutex_lock(&self->mutex);
    for (i = 0; i < targets->size; i++) {
        leftprod = targets->entries[i]->_shared.leased_count;
        leftprod *= result_weight;
        rightprod = result_leased;
        rightprod *= ((unsigned)targets->entries[i]->conf.weight_m1) + 1;
        if (!tried[i] && leftprod < rightprod) {
            result_index = i;
            result_leased = targets->entries[i]->_shared.leased_count;
            result_weight = ((unsigned)targets->entries[i]->conf.weight_m1) + 1;
        }
    }
    pthread_mutex_unlock(&self->mutex);

    assert(result_index < targets->size);
    return result_index;
}

__attribute__((used)) static void destroy(h2o_balancer_t *_self)
{
    struct least_conn_t *self = (void *)_self;
    pthread_mutex_destroy(&self->mutex);
    free(self);
}

h2o_balancer_t *h2o_balancer_create_lc(void)
{
    static const h2o_balancer_callbacks_t lc_callbacks = {selector, destroy};
    struct least_conn_t *self = h2o_mem_alloc(sizeof(*self));
    self->super.callbacks = &lc_callbacks;
    pthread_mutex_init(&self->mutex, NULL);
    return &self->super;
}

