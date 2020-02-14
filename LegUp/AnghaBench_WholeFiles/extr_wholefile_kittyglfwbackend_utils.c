#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_23__   TYPE_3__ ;
typedef  struct TYPE_22__   TYPE_2__ ;
typedef  struct TYPE_21__   TYPE_1__ ;

/* Type definitions */
typedef  void (* watch_callback_func ) (int,int,void*) ;
typedef  int /*<<< orphan*/  (* timer_callback_func ) (scalar_t__,void*) ;
struct timespec {long const member_0; long const member_1; scalar_t__ tv_sec; scalar_t__ tv_nsec; } ;
struct pollfd {int fd; int events; int revents; } ;
typedef  scalar_t__ nfds_t ;
typedef  scalar_t__ id_type ;
typedef  int /*<<< orphan*/  drain_buf ;
struct TYPE_21__ {int fd; int enabled; int events; char const* name; void (* callback ) (int,int,void*) ;void* callback_data; scalar_t__ id; int ready; int /*<<< orphan*/ * free; } ;
typedef  TYPE_1__ Watch ;
struct TYPE_22__ {scalar_t__ trigger_at; double interval; char const* name; int repeats; void* callback_data; scalar_t__ id; int /*<<< orphan*/  (* callback ) (scalar_t__,void*) ;int /*<<< orphan*/  (* free ) (scalar_t__,void*) ;} ;
typedef  TYPE_2__ Timer ;
struct TYPE_23__ {scalar_t__ watches_count; int timers_count; TYPE_1__* watches; struct pollfd* fds; TYPE_2__* timers; } ;
typedef  int /*<<< orphan*/  (* GLFWuserdatafreefun ) (scalar_t__,void*) ;
typedef  TYPE_3__ EventLoopData ;

/* Variables and functions */
 int /*<<< orphan*/  CLOCK_MONOTONIC ; 
 double DBL_MAX ; 
 int EAGAIN ; 
 int EINTR ; 
 int /*<<< orphan*/  GLFW_PLATFORM_ERROR ; 
 int POLLIN ; 
 int /*<<< orphan*/  _glfwInputError (int /*<<< orphan*/ ,char*) ; 
 char* calloc (scalar_t__,int) ; 
 int /*<<< orphan*/  clock_gettime (int /*<<< orphan*/ ,struct timespec*) ; 
 int /*<<< orphan*/  close (int) ; 
 int errno ; 
 int poll (struct pollfd*,scalar_t__,int) ; 
 int ppoll (struct pollfd*,scalar_t__,struct timespec*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  qsort (TYPE_2__*,int,int,int (*) (void const*,void const*)) ; 
 scalar_t__ read (int,char*,int) ; 
 char** realloc (char**,int) ; 
 int /*<<< orphan*/  removeX (int /*<<< orphan*/ ,scalar_t__,void (*) (TYPE_3__*)) ; 
 scalar_t__ strlen (char const*) ; 
 scalar_t__ strncmp (char*,char const*,scalar_t__) ; 
 char* strtok (char*,char*) ; 
 char strtol (char const*,int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  stub1 (scalar_t__,void*) ; 
 void stub2 (int,int,void*) ; 
 int /*<<< orphan*/  stub3 (scalar_t__,void*) ; 
 scalar_t__ timer_counter ; 
 int /*<<< orphan*/  timers ; 
 scalar_t__ watch_counter ; 
 int /*<<< orphan*/  watches ; 

__attribute__((used)) static inline double
monotonic() {
    struct timespec ts = {0};
#ifdef CLOCK_HIGHRES
    clock_gettime(CLOCK_HIGHRES, &ts);
#elif CLOCK_MONOTONIC_RAW
    clock_gettime(CLOCK_MONOTONIC_RAW, &ts);
#else
    clock_gettime(CLOCK_MONOTONIC, &ts);
#endif
    return (((double)ts.tv_nsec) / 1e9) + (double)ts.tv_sec;
}

void
update_fds(EventLoopData *eld) {
    for (nfds_t i = 0; i < eld->watches_count; i++) {
        Watch *w = eld->watches + i;
        eld->fds[i].fd = w->fd;
        eld->fds[i].events = w->enabled ? w->events : 0;
    }
}

id_type
addWatch(EventLoopData *eld, const char* name, int fd, int events, int enabled, watch_callback_func cb, void *cb_data) {
    if (eld->watches_count >= sizeof(eld->watches)/sizeof(eld->watches[0])) {
        _glfwInputError(GLFW_PLATFORM_ERROR, "Too many watches added");
        return 0;
    }
    Watch *w = eld->watches + eld->watches_count++;
    w->name = name;
    w->fd = fd; w->events = events; w->enabled = enabled;
    w->callback = cb;
    w->callback_data = cb_data;
    w->free = NULL;
    w->id = ++watch_counter;
    update_fds(eld);
    return w->id;
}

void
removeWatch(EventLoopData *eld, id_type watch_id) {
    removeX(watches, watch_id, update_fds);
}

void
toggleWatch(EventLoopData *eld, id_type watch_id, int enabled) {
    for (nfds_t i = 0; i < eld->watches_count; i++) {
        if (eld->watches[i].id == watch_id) {
            if (eld->watches[i].enabled != enabled) {
                eld->watches[i].enabled = enabled;
                update_fds(eld);
            }
            break;
        }
    }
}

__attribute__((used)) static int
compare_timers(const void *a_, const void *b_) {
    const Timer *a = (const Timer*)a_, *b = (const Timer*)b_;
    return (a->trigger_at > b->trigger_at) ? 1 : (a->trigger_at < b->trigger_at) ? -1 : 0;
}

__attribute__((used)) static inline void
update_timers(EventLoopData *eld) {
    if (eld->timers_count > 1) qsort(eld->timers, eld->timers_count, sizeof(eld->timers[0]), compare_timers);
}

id_type
addTimer(EventLoopData *eld, const char *name, double interval, int enabled, bool repeats, timer_callback_func cb, void *cb_data, GLFWuserdatafreefun free) {
    if (eld->timers_count >= sizeof(eld->timers)/sizeof(eld->timers[0])) {
        _glfwInputError(GLFW_PLATFORM_ERROR, "Too many timers added");
        return 0;
    }
    Timer *t = eld->timers + eld->timers_count++;
    t->interval = interval;
    t->name = name;
    t->trigger_at = enabled ? monotonic() + interval : DBL_MAX;
    t->repeats = repeats;
    t->callback = cb;
    t->callback_data = cb_data;
    t->free = free;
    t->id = ++timer_counter;
    update_timers(eld);
    return timer_counter;
}

void
removeTimer(EventLoopData *eld, id_type timer_id) {
    removeX(timers, timer_id, update_timers);
}

void
removeAllTimers(EventLoopData *eld) {
    for (nfds_t i = 0; i < eld->timers_count; i++) {
        if (eld->timers[i].free && eld->timers[i].callback_data) eld->timers[i].free(eld->timers[i].id, eld->timers[i].callback_data);
    }
    eld->timers_count = 0;
}

void
toggleTimer(EventLoopData *eld, id_type timer_id, int enabled) {
    for (nfds_t i = 0; i < eld->timers_count; i++) {
        if (eld->timers[i].id == timer_id) {
            double trigger_at = enabled ? (monotonic() + eld->timers[i].interval) : DBL_MAX;
            if (trigger_at != eld->timers[i].trigger_at) {
                eld->timers[i].trigger_at = trigger_at;
                update_timers(eld);
            }
            break;
        }
    }
}

void
changeTimerInterval(EventLoopData *eld, id_type timer_id, double interval) {
    for (nfds_t i = 0; i < eld->timers_count; i++) {
        if (eld->timers[i].id == timer_id) {
            eld->timers[i].interval = interval;
            break;
        }
    }
}

double
prepareForPoll(EventLoopData *eld, double timeout) {
    for (nfds_t i = 0; i < eld->watches_count; i++) eld->fds[i].revents = 0;
    if (!eld->timers_count || eld->timers[0].trigger_at == DBL_MAX) return timeout;
    double now = monotonic(), next_repeat_at = eld->timers[0].trigger_at;
    if (timeout < 0 || now + timeout > next_repeat_at) {
        timeout = next_repeat_at <= now ? 0 : next_repeat_at - now;
    }
    return timeout;
}

int
pollWithTimeout(struct pollfd *fds, nfds_t nfds, double timeout) {
    const long seconds = (long) timeout;
    const long nanoseconds = (long) ((timeout - seconds) * 1e9);
    struct timespec tv = { seconds, nanoseconds };
    return ppoll(fds, nfds, &tv, NULL);
}

__attribute__((used)) static void
dispatchEvents(EventLoopData *eld) {
    for (nfds_t i = 0; i < eld->watches_count; i++) {
        Watch *ww = eld->watches + i;
        struct pollfd *pfd = eld->fds + i;
        if (pfd->revents & ww->events) {
            ww->ready = 1;
            if (ww->callback) ww->callback(ww->fd, pfd->revents, ww->callback_data);
        } else ww->ready = 0;
    }
}

unsigned
dispatchTimers(EventLoopData *eld) {
    if (!eld->timers_count || eld->timers[0].trigger_at == DBL_MAX) return 0;
    static struct { timer_callback_func func; id_type id; void* data; bool repeats; } dispatches[sizeof(eld->timers)/sizeof(eld->timers[0])];
    unsigned num_dispatches = 0;
    double now = monotonic();
    for (nfds_t i = 0; i < eld->timers_count && eld->timers[i].trigger_at <= now; i++) {
        eld->timers[i].trigger_at = now + eld->timers[i].interval;
        dispatches[num_dispatches].func = eld->timers[i].callback;
        dispatches[num_dispatches].id = eld->timers[i].id;
        dispatches[num_dispatches].data = eld->timers[i].callback_data;
        dispatches[num_dispatches].repeats = eld->timers[i].repeats;
        num_dispatches++;
    }
    // we dispatch separately so that the callbacks can modify timers
    for (unsigned i = 0; i < num_dispatches; i++) {
        dispatches[i].func(dispatches[i].id, dispatches[i].data);
        if (!dispatches[i].repeats) {
            removeTimer(eld, dispatches[i].id);
        }
    }
    if (num_dispatches) update_timers(eld);
    return num_dispatches;
}

__attribute__((used)) static void
drain_wakeup_fd(int fd, int events, void* data) {
    static char drain_buf[64];
    while(read(fd, drain_buf, sizeof(drain_buf)) < 0 && errno == EINTR);
}

void
initPollData(EventLoopData *eld, int wakeup_fd, int display_fd) {
    addWatch(eld, "display", display_fd, POLLIN, 1, NULL, NULL);
    addWatch(eld, "wakeup", wakeup_fd, POLLIN, 1, drain_wakeup_fd, NULL);
}

int
pollForEvents(EventLoopData *eld, double timeout) {
    int read_ok = 0;
    timeout = prepareForPoll(eld, timeout);
    int result;
    double end_time = monotonic() + timeout;

    while(1) {
        if (timeout >= 0) {
            errno = 0;
            result = pollWithTimeout(eld->fds, eld->watches_count, timeout);
            int saved_errno = errno;
            dispatchTimers(eld);
            if (result > 0) {
                dispatchEvents(eld);
                read_ok = eld->watches[0].ready;
                break;
            }
            timeout = end_time - monotonic();
            if (timeout <= 0) break;
            if (result < 0 && (saved_errno == EINTR || saved_errno == EAGAIN)) continue;
            break;
        } else {
            errno = 0;
            result = poll(eld->fds, eld->watches_count, -1);
            int saved_errno = errno;
            dispatchTimers(eld);
            if (result > 0) {
                dispatchEvents(eld);
                read_ok = eld->watches[0].ready;
            }
            if (result < 0 && (saved_errno == EINTR || saved_errno == EAGAIN)) continue;
            break;
        }
    }
    return read_ok;
}

void
closeFds(int *fds, size_t count) {
    while(count--) {
        if (*fds > 0) {
            close(*fds);
            *fds = -1;
        }
        fds++;
    }
}

char** parseUriList(char* text, int* count)
{
    const char* prefix = "file://";
    char** paths = NULL;
    char* line;

    *count = 0;

    while ((line = strtok(text, "\r\n")))
    {
        text = NULL;

        if (line[0] == '#')
            continue;

        if (strncmp(line, prefix, strlen(prefix)) == 0)
        {
            line += strlen(prefix);
            // TODO: Validate hostname
            while (*line != '/')
                line++;
        }

        (*count)++;

        char* path = calloc(strlen(line) + 1, 1);
        paths = realloc(paths, *count * sizeof(char*));
        paths[*count - 1] = path;

        while (*line)
        {
            if (line[0] == '%' && line[1] && line[2])
            {
                const char digits[3] = { line[1], line[2], '\0' };
                *path = strtol(digits, NULL, 16);
                line += 2;
            }
            else
                *path = *line;

            path++;
            line++;
        }
    }

    return paths;
}

