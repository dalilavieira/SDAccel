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
struct request_queue {scalar_t__ head; scalar_t__ tail; struct request** reqs; } ;
struct request {scalar_t__ action; char const* file; } ;
struct file_handler {char* serial; scalar_t__ current_process; int stopped; int /*<<< orphan*/  thread; int /*<<< orphan*/  mutex; int /*<<< orphan*/  event_cond; struct request_queue queue; } ;
typedef  scalar_t__ process_t ;
typedef  scalar_t__ file_handler_action_t ;

/* Variables and functions */
 scalar_t__ ACTION_INSTALL_APK ; 
 int /*<<< orphan*/  DEVICE_SDCARD_PATH ; 
 int /*<<< orphan*/  LOGE (char*,char const*) ; 
 int /*<<< orphan*/  LOGI (char*,char const*) ; 
 int /*<<< orphan*/  LOGW (char*) ; 
 scalar_t__ PROCESS_NONE ; 
 int REQUEST_QUEUE_SIZE ; 
 int /*<<< orphan*/  SDL_DestroyCond (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  SDL_DestroyMutex (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  SDL_WaitThread (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  SDL_assert (int) ; 
 int /*<<< orphan*/  SDL_free (void*) ; 
 struct request* SDL_malloc (int) ; 
 scalar_t__ adb_install (char const*,char const*) ; 
 scalar_t__ adb_push (char const*,char const*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  cmd_simple_wait (scalar_t__,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  cmd_terminate (scalar_t__) ; 
 int /*<<< orphan*/  cond_signal (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  cond_wait (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ ) ; 
 scalar_t__ process_check_success (scalar_t__,char*) ; 

__attribute__((used)) static struct request *
request_new(file_handler_action_t action, const char *file) {
    struct request *req = SDL_malloc(sizeof(*req));
    if (!req) {
        return NULL;
    }
    req->action = action;
    req->file = file;
    return req;
}

__attribute__((used)) static void
request_free(struct request *req) {
    if (!req) {
        return;
    }
    SDL_free((void *) req->file);
    SDL_free((void *) req);
}

__attribute__((used)) static bool
request_queue_is_empty(const struct request_queue *queue) {
    return queue->head == queue->tail;
}

__attribute__((used)) static bool
request_queue_is_full(const struct request_queue *queue) {
    return (queue->head + 1) % REQUEST_QUEUE_SIZE == queue->tail;
}

__attribute__((used)) static bool
request_queue_init(struct request_queue *queue) {
    queue->head = 0;
    queue->tail = 0;
    return true;
}

__attribute__((used)) static void
request_queue_destroy(struct request_queue *queue) {
    int i = queue->tail;
    while (i != queue->head) {
        request_free(queue->reqs[i]);
        i = (i + 1) % REQUEST_QUEUE_SIZE;
    }
}

__attribute__((used)) static bool
request_queue_push(struct request_queue *queue, struct request *req) {
    if (request_queue_is_full(queue)) {
        return false;
    }
    queue->reqs[queue->head] = req;
    queue->head = (queue->head + 1) % REQUEST_QUEUE_SIZE;
    return true;
}

__attribute__((used)) static bool
request_queue_take(struct request_queue *queue, struct request **req) {
    if (request_queue_is_empty(queue)) {
        return false;
    }
    // transfer ownership
    *req = queue->reqs[queue->tail];
    queue->tail = (queue->tail + 1) % REQUEST_QUEUE_SIZE;
    return true;
}

void
file_handler_destroy(struct file_handler *file_handler) {
    SDL_DestroyCond(file_handler->event_cond);
    SDL_DestroyMutex(file_handler->mutex);
    request_queue_destroy(&file_handler->queue);
    SDL_free((void *) file_handler->serial);
}

__attribute__((used)) static process_t
install_apk(const char *serial, const char *file) {
    return adb_install(serial, file);
}

__attribute__((used)) static process_t
push_file(const char *serial, const char *file) {
    return adb_push(serial, file, DEVICE_SDCARD_PATH);
}

__attribute__((used)) static int
run_file_handler(void *data) {
    struct file_handler *file_handler = data;

    for (;;) {
        mutex_lock(file_handler->mutex);
        file_handler->current_process = PROCESS_NONE;
        while (!file_handler->stopped
                && request_queue_is_empty(&file_handler->queue)) {
            cond_wait(file_handler->event_cond, file_handler->mutex);
        }
        if (file_handler->stopped) {
            // stop immediately, do not process further events
            mutex_unlock(file_handler->mutex);
            break;
        }
        struct request *req;
        bool non_empty = request_queue_take(&file_handler->queue, &req);
        SDL_assert(non_empty);

        process_t process;
        if (req->action == ACTION_INSTALL_APK) {
            LOGI("Installing %s...", req->file);
            process = install_apk(file_handler->serial, req->file);
        } else {
            LOGI("Pushing %s...", req->file);
            process = push_file(file_handler->serial, req->file);
        }
        file_handler->current_process = process;
        mutex_unlock(file_handler->mutex);

        if (req->action == ACTION_INSTALL_APK) {
            if (process_check_success(process, "adb install")) {
                LOGI("%s successfully installed", req->file);
            } else {
                LOGE("Failed to install %s", req->file);
            }
        } else {
            if (process_check_success(process, "adb push")) {
                LOGI("%s successfully pushed to /sdcard/", req->file);
            } else {
                LOGE("Failed to push %s to /sdcard/", req->file);
            }
        }

        request_free(req);
    }
    return 0;
}

void
file_handler_stop(struct file_handler *file_handler) {
    mutex_lock(file_handler->mutex);
    file_handler->stopped = true;
    cond_signal(file_handler->event_cond);
    if (file_handler->current_process != PROCESS_NONE) {
        if (!cmd_terminate(file_handler->current_process)) {
            LOGW("Cannot terminate install process");
        }
        cmd_simple_wait(file_handler->current_process, NULL);
        file_handler->current_process = PROCESS_NONE;
    }
    mutex_unlock(file_handler->mutex);
}

void
file_handler_join(struct file_handler *file_handler) {
    SDL_WaitThread(file_handler->thread, NULL);
}

