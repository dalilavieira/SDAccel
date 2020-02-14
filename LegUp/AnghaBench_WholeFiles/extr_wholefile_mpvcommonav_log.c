#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_8__   TYPE_4__ ;
typedef  struct TYPE_7__   TYPE_3__ ;
typedef  struct TYPE_6__   TYPE_2__ ;
typedef  struct TYPE_5__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  va_list ;
struct mpv_global {struct mp_log* log; } ;
struct mp_log {int dummy; } ;
typedef  int /*<<< orphan*/  buffer ;
struct TYPE_8__ {scalar_t__ type; } ;
struct TYPE_7__ {char* (* item_name ) (void*) ;int /*<<< orphan*/  class_name; } ;
struct TYPE_6__ {TYPE_4__* codec; } ;
struct TYPE_5__ {scalar_t__ iformat; } ;
typedef  TYPE_1__ AVFormatContext ;
typedef  TYPE_2__ AVCodecContext ;
typedef  TYPE_3__ AVClass ;

/* Variables and functions */
 scalar_t__ AVMEDIA_TYPE_AUDIO ; 
 scalar_t__ AVMEDIA_TYPE_VIDEO ; 
 int AV_LOG_ERROR ; 
 int AV_LOG_FATAL ; 
 int AV_LOG_INFO ; 
 int AV_LOG_VERBOSE ; 
 int AV_LOG_WARNING ; 
 char* LIB_PREFIX ; 
 int /*<<< orphan*/  MPMAX (int,int /*<<< orphan*/ ) ; 
 int MPMIN (int /*<<< orphan*/ ,int) ; 
 int MSGL_DEBUG ; 
 int MSGL_ERR ; 
 int MSGL_FATAL ; 
 int MSGL_TRACE ; 
 int MSGL_V ; 
 int MSGL_WARN ; 
 scalar_t__ av_codec_is_decoder (TYPE_4__*) ; 
 void av_log_default_callback (void*,int,char const*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  av_log_set_callback (void (*) (void*,int,char const*,int /*<<< orphan*/ )) ; 
 int /*<<< orphan*/  avformat_network_init () ; 
 struct mp_log* log_decaudio ; 
 struct mp_log* log_decvideo ; 
 struct mp_log* log_demuxer ; 
 int /*<<< orphan*/  log_lock ; 
 struct mpv_global* log_mpv_instance ; 
 int log_print_prefix ; 
 struct mp_log* log_root ; 
 struct mp_log* mp_log_new (struct mp_log*,struct mp_log*,char*) ; 
 int /*<<< orphan*/  mp_msg (struct mp_log*,int,char*,char*) ; 
 scalar_t__ mp_msg_test (struct mp_log*,int) ; 
 int /*<<< orphan*/  mp_warn (struct mp_log*,char*) ; 
 int /*<<< orphan*/  pthread_mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  pthread_mutex_unlock (int /*<<< orphan*/ *) ; 
 int snprintf (char*,int,char*,char const*) ; 
 int /*<<< orphan*/  stderr ; 
 int /*<<< orphan*/  strcmp (int /*<<< orphan*/ ,char*) ; 
 int strlen (char const*) ; 
 char* stub1 (void*) ; 
 int /*<<< orphan*/  talloc_free (struct mp_log*) ; 
 int /*<<< orphan*/  vfprintf (int /*<<< orphan*/ ,char const*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  vsnprintf (char*,int,char const*,int /*<<< orphan*/ ) ; 

__attribute__((used)) static int av_log_level_to_mp_level(int av_level)
{
    if (av_level > AV_LOG_VERBOSE)
        return MSGL_TRACE;
    if (av_level > AV_LOG_INFO)
        return MSGL_DEBUG;
    if (av_level > AV_LOG_WARNING)
        return MSGL_V;
    if (av_level > AV_LOG_ERROR)
        return MSGL_WARN;
    if (av_level > AV_LOG_FATAL)
        return MSGL_ERR;
    return MSGL_FATAL;
}

__attribute__((used)) static struct mp_log *get_av_log(void *ptr)
{
    if (!ptr)
        return log_root;

    AVClass *avc = *(AVClass **)ptr;
    if (!avc) {
        mp_warn(log_root,
               "av_log callback called with bad parameters (NULL AVClass).\n"
               "This is a bug in one of Libav/FFmpeg libraries used.\n");
        return log_root;
    }

    if (!strcmp(avc->class_name, "AVCodecContext")) {
        AVCodecContext *s = ptr;
        if (s->codec) {
            if (s->codec->type == AVMEDIA_TYPE_AUDIO) {
                if (av_codec_is_decoder(s->codec))
                    return log_decaudio;
            } else if (s->codec->type == AVMEDIA_TYPE_VIDEO) {
                if (av_codec_is_decoder(s->codec))
                    return log_decvideo;
            }
        }
    }

    if (!strcmp(avc->class_name, "AVFormatContext")) {
        AVFormatContext *s = ptr;
        if (s->iformat)
            return log_demuxer;
    }

    return log_root;
}

__attribute__((used)) static void mp_msg_av_log_callback(void *ptr, int level, const char *fmt,
                                   va_list vl)
{
    AVClass *avc = ptr ? *(AVClass **)ptr : NULL;
    int mp_level = av_log_level_to_mp_level(level);

    // Note: mp_log is thread-safe, but destruction of the log instances is not.
    pthread_mutex_lock(&log_lock);

    if (!log_mpv_instance) {
        pthread_mutex_unlock(&log_lock);
        // Fallback to stderr
        vfprintf(stderr, fmt, vl);
        return;
    }

    struct mp_log *log = get_av_log(ptr);

    if (mp_msg_test(log, mp_level)) {
        char buffer[4096] = "";
        int pos = 0;
        const char *prefix = avc ? avc->item_name(ptr) : NULL;
        if (log_print_prefix && prefix)
            pos = snprintf(buffer, sizeof(buffer), "%s: ", prefix);
        log_print_prefix = fmt[strlen(fmt) - 1] == '\n';

        pos = MPMIN(MPMAX(pos, 0), sizeof(buffer));
        vsnprintf(buffer + pos, sizeof(buffer) - pos, fmt, vl);

        mp_msg(log, mp_level, "%s", buffer);
    }

    pthread_mutex_unlock(&log_lock);
}

void init_libav(struct mpv_global *global)
{
    pthread_mutex_lock(&log_lock);
    if (!log_mpv_instance) {
        log_mpv_instance = global;
        log_root = mp_log_new(NULL, global->log, LIB_PREFIX);
        log_decaudio = mp_log_new(log_root, log_root, "audio");
        log_decvideo = mp_log_new(log_root, log_root, "video");
        log_demuxer = mp_log_new(log_root, log_root, "demuxer");
        av_log_set_callback(mp_msg_av_log_callback);
    }
    pthread_mutex_unlock(&log_lock);

    avformat_network_init();

#if HAVE_LIBAVDEVICE
    avdevice_register_all();
#endif
}

void uninit_libav(struct mpv_global *global)
{
    pthread_mutex_lock(&log_lock);
    if (log_mpv_instance == global) {
        av_log_set_callback(av_log_default_callback);
        log_mpv_instance = NULL;
        talloc_free(log_root);
    }
    pthread_mutex_unlock(&log_lock);
}

