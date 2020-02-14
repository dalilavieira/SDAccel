#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */

/* Type definitions */
struct controller {int stopped; int /*<<< orphan*/  thread; int /*<<< orphan*/  mutex; int /*<<< orphan*/  event_cond; int /*<<< orphan*/  queue; int /*<<< orphan*/  video_socket; } ;
struct control_event {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  LOGD (char*) ; 
 int /*<<< orphan*/  SDL_DestroyCond (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  SDL_DestroyMutex (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  SDL_WaitThread (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  SDL_assert (int) ; 
 int SERIALIZED_EVENT_MAX_SIZE ; 
 int /*<<< orphan*/  cond_signal (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  cond_wait (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  control_event_destroy (struct control_event*) ; 
 int /*<<< orphan*/  control_event_queue_destroy (int /*<<< orphan*/ *) ; 
 scalar_t__ control_event_queue_is_empty (int /*<<< orphan*/ *) ; 
 int control_event_queue_take (int /*<<< orphan*/ *,struct control_event*) ; 
 int control_event_serialize (struct control_event const*,unsigned char*) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ ) ; 
 int net_send_all (int /*<<< orphan*/ ,unsigned char*,int) ; 

void
controller_destroy(struct controller *controller) {
    SDL_DestroyCond(controller->event_cond);
    SDL_DestroyMutex(controller->mutex);
    control_event_queue_destroy(&controller->queue);
}

__attribute__((used)) static bool
process_event(struct controller *controller,
              const struct control_event *event) {
    unsigned char serialized_event[SERIALIZED_EVENT_MAX_SIZE];
    int length = control_event_serialize(event, serialized_event);
    if (!length) {
        return false;
    }
    int w = net_send_all(controller->video_socket, serialized_event, length);
    return w == length;
}

__attribute__((used)) static int
run_controller(void *data) {
    struct controller *controller = data;

    for (;;) {
        mutex_lock(controller->mutex);
        while (!controller->stopped
                && control_event_queue_is_empty(&controller->queue)) {
            cond_wait(controller->event_cond, controller->mutex);
        }
        if (controller->stopped) {
            // stop immediately, do not process further events
            mutex_unlock(controller->mutex);
            break;
        }
        struct control_event event;
        bool non_empty = control_event_queue_take(&controller->queue,
                                                      &event);
        SDL_assert(non_empty);
        mutex_unlock(controller->mutex);

        bool ok = process_event(controller, &event);
        control_event_destroy(&event);
        if (!ok) {
            LOGD("Cannot write event to socket");
            break;
        }
    }
    return 0;
}

void
controller_stop(struct controller *controller) {
    mutex_lock(controller->mutex);
    controller->stopped = true;
    cond_signal(controller->event_cond);
    mutex_unlock(controller->mutex);
}

void
controller_join(struct controller *controller) {
    SDL_WaitThread(controller->thread, NULL);
}

