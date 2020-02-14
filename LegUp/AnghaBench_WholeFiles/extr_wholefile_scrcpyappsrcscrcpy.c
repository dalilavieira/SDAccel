#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_13__   TYPE_4__ ;
typedef  struct TYPE_12__   TYPE_3__ ;
typedef  struct TYPE_11__   TYPE_2__ ;
typedef  struct TYPE_10__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  va_list ;
typedef  int /*<<< orphan*/  uint32_t ;
typedef  int /*<<< orphan*/  process_t ;
typedef  int /*<<< orphan*/  file_handler_action_t ;
typedef  enum event_result { ____Placeholder_event_result } event_result ;
struct TYPE_13__ {int has_frame; } ;
struct TYPE_11__ {char* file; } ;
struct TYPE_10__ {int /*<<< orphan*/  event; } ;
struct TYPE_12__ {int type; TYPE_2__ drop; int /*<<< orphan*/  button; int /*<<< orphan*/  wheel; int /*<<< orphan*/  motion; int /*<<< orphan*/  key; int /*<<< orphan*/  text; TYPE_1__ window; } ;
typedef  scalar_t__ SDL_LogPriority ;
typedef  TYPE_3__ SDL_Event ;

/* Variables and functions */
 int /*<<< orphan*/  ACTION_INSTALL_APK ; 
 int /*<<< orphan*/  ACTION_PUSH_FILE ; 
 int /*<<< orphan*/  ARRAY_LEN (char const* const*) ; 
#define  AV_LOG_ERROR 149 
#define  AV_LOG_FATAL 148 
#define  AV_LOG_INFO 147 
#define  AV_LOG_PANIC 146 
#define  AV_LOG_WARNING 145 
#define  EVENT_NEW_FRAME 144 
#define  EVENT_RESULT_CONTINUE 143 
#define  EVENT_RESULT_STOPPED_BY_EOS 142 
#define  EVENT_RESULT_STOPPED_BY_USER 141 
#define  EVENT_STREAM_STOPPED 140 
 int /*<<< orphan*/  LOGC (char*,...) ; 
 int /*<<< orphan*/  LOGD (char*) ; 
 int /*<<< orphan*/  LOGW (char*) ; 
#define  SDL_DROPFILE 139 
 int /*<<< orphan*/  SDL_EnableScreenSaver () ; 
 int /*<<< orphan*/  SDL_GetError () ; 
 int /*<<< orphan*/  SDL_HINT_RENDER_SCALE_QUALITY ; 
 int /*<<< orphan*/  SDL_INIT_EVENTS ; 
 int /*<<< orphan*/  SDL_INIT_VIDEO ; 
 scalar_t__ SDL_Init (int /*<<< orphan*/ ) ; 
#define  SDL_KEYDOWN 138 
#define  SDL_KEYUP 137 
 int /*<<< orphan*/  SDL_LOG_CATEGORY_VIDEO ; 
 scalar_t__ SDL_LOG_PRIORITY_CRITICAL ; 
 scalar_t__ SDL_LOG_PRIORITY_ERROR ; 
 scalar_t__ SDL_LOG_PRIORITY_INFO ; 
 scalar_t__ SDL_LOG_PRIORITY_WARN ; 
 int /*<<< orphan*/  SDL_LogMessageV (int /*<<< orphan*/ ,scalar_t__,char*,int /*<<< orphan*/ ) ; 
#define  SDL_MOUSEBUTTONDOWN 136 
#define  SDL_MOUSEBUTTONUP 135 
#define  SDL_MOUSEMOTION 134 
#define  SDL_MOUSEWHEEL 133 
#define  SDL_QUIT 132 
 int /*<<< orphan*/  SDL_Quit ; 
 int /*<<< orphan*/  SDL_SetHint (int /*<<< orphan*/ ,char*) ; 
#define  SDL_TEXTINPUT 131 
#define  SDL_WINDOWEVENT 130 
#define  SDL_WINDOWEVENT_EXPOSED 129 
#define  SDL_WINDOWEVENT_SIZE_CHANGED 128 
 scalar_t__ SDL_WaitEvent (TYPE_3__*) ; 
 int /*<<< orphan*/  SDL_free (char*) ; 
 char* SDL_malloc (scalar_t__) ; 
 int /*<<< orphan*/  adb_execute (char const*,char const* const*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  atexit (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  file_handler ; 
 int /*<<< orphan*/  file_handler_request (int /*<<< orphan*/ *,int /*<<< orphan*/ ,char*) ; 
 int /*<<< orphan*/  input_manager ; 
 int /*<<< orphan*/  input_manager_process_key (int /*<<< orphan*/ *,int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  input_manager_process_mouse_button (int /*<<< orphan*/ *,int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  input_manager_process_mouse_motion (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  input_manager_process_mouse_wheel (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  input_manager_process_text_input (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  process_check_success (int /*<<< orphan*/ ,char*) ; 
 TYPE_4__ screen ; 
 int /*<<< orphan*/  screen_render (TYPE_4__*) ; 
 int /*<<< orphan*/  screen_show_window (TYPE_4__*) ; 
 int /*<<< orphan*/  screen_update_frame (TYPE_4__*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  strcmp (char const*,char*) ; 
 int /*<<< orphan*/  strcpy (char*,char const*) ; 
 scalar_t__ strlen (char const*) ; 
 char* strrchr (char const*,char) ; 
 int /*<<< orphan*/  video_buffer ; 

__attribute__((used)) static bool
sdl_init_and_configure(bool display) {
    uint32_t flags = display ? SDL_INIT_VIDEO : SDL_INIT_EVENTS;
    if (SDL_Init(flags)) {
        LOGC("Could not initialize SDL: %s", SDL_GetError());
        return false;
    }

    atexit(SDL_Quit);

    if (!display) {
        return true;
    }

    // Use the best available scale quality
    if (!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "2")) {
        LOGW("Could not enable bilinear filtering");
    }

#ifdef SCRCPY_SDL_HAS_HINT_MOUSE_FOCUS_CLICKTHROUGH
    // Handle a click to gain focus as any other click
    if (!SDL_SetHint(SDL_HINT_MOUSE_FOCUS_CLICKTHROUGH, "1")) {
        LOGW("Could not enable mouse focus clickthrough");
    }
#endif

    // Do not disable the screensaver when scrcpy is running
    SDL_EnableScreenSaver();

    return true;
}

__attribute__((used)) static bool
is_apk(const char *file) {
    const char *ext = strrchr(file, '.');
    return ext && !strcmp(ext, ".apk");
}

__attribute__((used)) static enum event_result
handle_event(SDL_Event *event, bool control) {
    switch (event->type) {
        case EVENT_STREAM_STOPPED:
            LOGD("Video stream stopped");
            return EVENT_RESULT_STOPPED_BY_EOS;
        case SDL_QUIT:
            LOGD("User requested to quit");
            return EVENT_RESULT_STOPPED_BY_USER;
        case EVENT_NEW_FRAME:
            if (!screen.has_frame) {
                screen.has_frame = true;
                // this is the very first frame, show the window
                screen_show_window(&screen);
            }
            if (!screen_update_frame(&screen, &video_buffer)) {
                return false;
            }
            break;
        case SDL_WINDOWEVENT:
            switch (event->window.event) {
                case SDL_WINDOWEVENT_EXPOSED:
                case SDL_WINDOWEVENT_SIZE_CHANGED:
                    screen_render(&screen);
                    break;
            }
            break;
        case SDL_TEXTINPUT:
            if (!control) {
                break;
            }
            input_manager_process_text_input(&input_manager, &event->text);
            break;
        case SDL_KEYDOWN:
        case SDL_KEYUP:
            // some key events do not interact with the device, so process the
            // event even if control is disabled
            input_manager_process_key(&input_manager, &event->key, control);
            break;
        case SDL_MOUSEMOTION:
            if (!control) {
                break;
            }
            input_manager_process_mouse_motion(&input_manager, &event->motion);
            break;
        case SDL_MOUSEWHEEL:
            if (!control) {
                break;
            }
            input_manager_process_mouse_wheel(&input_manager, &event->wheel);
            break;
        case SDL_MOUSEBUTTONDOWN:
        case SDL_MOUSEBUTTONUP:
            // some mouse events do not interact with the device, so process
            // the event even if control is disabled
            input_manager_process_mouse_button(&input_manager, &event->button,
                                               control);
            break;
        case SDL_DROPFILE: {
            if (!control) {
                break;
            }
            file_handler_action_t action;
            if (is_apk(event->drop.file)) {
                action = ACTION_INSTALL_APK;
            } else {
                action = ACTION_PUSH_FILE;
            }
            file_handler_request(&file_handler, action, event->drop.file);
            break;
        }
    }
    return EVENT_RESULT_CONTINUE;
}

__attribute__((used)) static bool
event_loop(bool display, bool control) {
#ifdef CONTINUOUS_RESIZING_WORKAROUND
    if (display) {
        SDL_AddEventWatch(event_watcher, NULL);
    }
#endif
    SDL_Event event;
    while (SDL_WaitEvent(&event)) {
        enum event_result result = handle_event(&event, control);
        switch (result) {
            case EVENT_RESULT_STOPPED_BY_USER:
                return true;
            case EVENT_RESULT_STOPPED_BY_EOS:
                return false;
            case EVENT_RESULT_CONTINUE:
                break;
        }
    }
    return false;
}

__attribute__((used)) static process_t
set_show_touches_enabled(const char *serial, bool enabled) {
    const char *value = enabled ? "1" : "0";
    const char *const adb_cmd[] = {
        "shell", "settings", "put", "system", "show_touches", value
    };
    return adb_execute(serial, adb_cmd, ARRAY_LEN(adb_cmd));
}

__attribute__((used)) static void
wait_show_touches(process_t process) {
    // reap the process, ignore the result
    process_check_success(process, "show_touches");
}

__attribute__((used)) static SDL_LogPriority
sdl_priority_from_av_level(int level) {
    switch (level) {
        case AV_LOG_PANIC:
        case AV_LOG_FATAL:
            return SDL_LOG_PRIORITY_CRITICAL;
        case AV_LOG_ERROR:
            return SDL_LOG_PRIORITY_ERROR;
        case AV_LOG_WARNING:
            return SDL_LOG_PRIORITY_WARN;
        case AV_LOG_INFO:
            return SDL_LOG_PRIORITY_INFO;
    }
    // do not forward others, which are too verbose
    return 0;
}

__attribute__((used)) static void
av_log_callback(void *avcl, int level, const char *fmt, va_list vl) {
    SDL_LogPriority priority = sdl_priority_from_av_level(level);
    if (priority == 0) {
        return;
    }
    char *local_fmt = SDL_malloc(strlen(fmt) + 10);
    if (!local_fmt) {
        LOGC("Cannot allocate string");
        return;
    }
    // strcpy is safe here, the destination is large enough
    strcpy(local_fmt, "[FFmpeg] ");
    strcpy(local_fmt + 9, fmt);
    SDL_LogMessageV(SDL_LOG_CATEGORY_VIDEO, priority, local_fmt, vl);
    SDL_free(local_fmt);
}

