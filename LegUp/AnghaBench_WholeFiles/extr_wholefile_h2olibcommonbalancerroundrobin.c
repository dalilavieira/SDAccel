#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_15__   TYPE_5__ ;
typedef  struct TYPE_14__   TYPE_4__ ;
typedef  struct TYPE_13__   TYPE_3__ ;
typedef  struct TYPE_12__   TYPE_2__ ;
typedef  struct TYPE_11__   TYPE_1__ ;

/* Type definitions */
struct TYPE_14__ {TYPE_5__ const* callbacks; } ;
struct round_robin_t {scalar_t__ pos; scalar_t__ consumed_weight; TYPE_4__ super; int /*<<< orphan*/  mutex; } ;
struct TYPE_13__ {scalar_t__ size; TYPE_2__** entries; } ;
typedef  TYPE_3__ h2o_socketpool_target_vector_t ;
typedef  TYPE_4__ h2o_balancer_t ;
struct TYPE_15__ {size_t (* member_0 ) (TYPE_4__*,TYPE_3__*,char*) ;void (* member_1 ) (TYPE_4__*) ;} ;
typedef  TYPE_5__ h2o_balancer_callbacks_t ;
struct TYPE_11__ {scalar_t__ weight_m1; } ;
struct TYPE_12__ {TYPE_1__ conf; } ;

/* Variables and functions */
 int /*<<< orphan*/  assert (int) ; 
 int /*<<< orphan*/  free (struct round_robin_t*) ; 
 int /*<<< orphan*/  h2o_fatal (char*) ; 
 struct round_robin_t* h2o_mem_alloc (int) ; 
 int /*<<< orphan*/  pthread_mutex_destroy (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  pthread_mutex_init (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  pthread_mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  pthread_mutex_unlock (int /*<<< orphan*/ *) ; 

__attribute__((used)) static inline void select_next(struct round_robin_t *self, h2o_socketpool_target_vector_t *targets)
{
    self->pos += 1;
    if (self->pos == targets->size)
        self->pos = 0;
    self->consumed_weight = 0;
}

__attribute__((used)) static size_t selector(h2o_balancer_t *balancer, h2o_socketpool_target_vector_t *targets, char *tried)
{
    size_t i;
    size_t result = 0;
    struct round_robin_t *self = (void *)balancer;

    pthread_mutex_lock(&self->mutex);

    assert(targets->size != 0);
    for (i = 0; i < targets->size; i++) {
        if (!tried[self->pos]) {
            /* get the result */
            result = self->pos;
            if (++self->consumed_weight > targets->entries[self->pos]->conf.weight_m1)
                select_next(self, targets);
            pthread_mutex_unlock(&self->mutex);
            return result;
        } else {
            select_next(self, targets);
        }
    }
    h2o_fatal("unreachable");
}

__attribute__((used)) static void destroy(h2o_balancer_t *balancer)
{
    struct round_robin_t *self = (void *)balancer;
    pthread_mutex_destroy(&self->mutex);
    free(self);
}

h2o_balancer_t *h2o_balancer_create_rr(void)
{
    static const h2o_balancer_callbacks_t rr_callbacks = {selector, destroy};

    struct round_robin_t *self = h2o_mem_alloc(sizeof(*self));
    pthread_mutex_init(&self->mutex, NULL);
    self->super.callbacks = &rr_callbacks;
    self->pos = 0;
    self->consumed_weight = 0;

    return &self->super;
}

