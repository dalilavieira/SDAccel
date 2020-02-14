#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_11__   TYPE_2__ ;
typedef  struct TYPE_10__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  va_list ;
typedef  int /*<<< orphan*/  uint8_t ;
typedef  int int64_t ;
struct TYPE_10__ {char* filename; int is_streamed; TYPE_2__* priv_data; } ;
typedef  TYPE_1__ URLContext ;
struct TYPE_11__ {char* temp_filename; char* app; char* tcurl; char* pageurl; char* flashver; char* conn; char* playpath; char* subscribe; char* client_buffer_time; char* swfurl; char* swfverify; int /*<<< orphan*/  rtmp; scalar_t__ live; } ;
typedef  int /*<<< orphan*/  RTMP ;
typedef  TYPE_2__ LibRTMPContext ;

/* Variables and functions */
 int AVERROR (int /*<<< orphan*/ ) ; 
 int AVERROR_EOF ; 
 int AVERROR_UNKNOWN ; 
 int AVIO_FLAG_WRITE ; 
 int AVSEEK_FLAG_BACKWARD ; 
 int AVSEEK_FLAG_BYTE ; 
#define  AV_LOG_DEBUG 139 
#define  AV_LOG_ERROR 138 
#define  AV_LOG_FATAL 137 
#define  AV_LOG_INFO 136 
#define  AV_LOG_VERBOSE 135 
#define  AV_LOG_WARNING 134 
 int /*<<< orphan*/  AV_ROUND_DOWN ; 
 int /*<<< orphan*/  AV_ROUND_UP ; 
 int /*<<< orphan*/  AV_TIME_BASE ; 
 int /*<<< orphan*/  ENOMEM ; 
 int /*<<< orphan*/  ENOSYS ; 
 int /*<<< orphan*/  RTMP_Close (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  RTMP_Connect (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  RTMP_ConnectStream (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  RTMP_EnableWrite (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  RTMP_Init (int /*<<< orphan*/ *) ; 
#define  RTMP_LOGCRIT 133 
#define  RTMP_LOGDEBUG 132 
#define  RTMP_LOGDEBUG2 131 
#define  RTMP_LOGERROR 130 
#define  RTMP_LOGINFO 129 
#define  RTMP_LOGWARNING 128 
 int /*<<< orphan*/  RTMP_LogSetCallback (void (*) (int,char const*,int /*<<< orphan*/ )) ; 
 int /*<<< orphan*/  RTMP_LogSetLevel (int) ; 
 int /*<<< orphan*/  RTMP_Pause (int /*<<< orphan*/ *,int) ; 
 int RTMP_Read (int /*<<< orphan*/ *,int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  RTMP_SendSeek (int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  RTMP_SetupURL (int /*<<< orphan*/ *,char*) ; 
 int RTMP_Socket (int /*<<< orphan*/ *) ; 
 int RTMP_Write (int /*<<< orphan*/ *,int /*<<< orphan*/  const*,int) ; 
 int /*<<< orphan*/  av_freep (char**) ; 
 int /*<<< orphan*/  av_log (int /*<<< orphan*/ *,int,char*) ; 
 int av_log_get_level () ; 
 char* av_malloc (int) ; 
 int av_rescale_rnd (int,int,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  av_strlcat (char*,char*,int) ; 
 int /*<<< orphan*/  av_strlcpy (char*,char*,int) ; 
 int /*<<< orphan*/  av_vlog (int /*<<< orphan*/ *,int,char const*,int /*<<< orphan*/ ) ; 
 char* strchr (char*,char) ; 
 int strlen (char*) ; 
 int /*<<< orphan*/  strspn (char*,char*) ; 

__attribute__((used)) static void rtmp_log(int level, const char *fmt, va_list args)
{
    switch (level) {
    default:
    case RTMP_LOGCRIT:    level = AV_LOG_FATAL;   break;
    case RTMP_LOGERROR:   level = AV_LOG_ERROR;   break;
    case RTMP_LOGWARNING: level = AV_LOG_WARNING; break;
    case RTMP_LOGINFO:    level = AV_LOG_INFO;    break;
    case RTMP_LOGDEBUG:   level = AV_LOG_VERBOSE; break;
    case RTMP_LOGDEBUG2:  level = AV_LOG_DEBUG;   break;
    }

    av_vlog(NULL, level, fmt, args);
    av_log(NULL, level, "\n");
}

__attribute__((used)) static int rtmp_close(URLContext *s)
{
    LibRTMPContext *ctx = s->priv_data;
    RTMP *r = &ctx->rtmp;

    RTMP_Close(r);
    av_freep(&ctx->temp_filename);
    return 0;
}

__attribute__((used)) static int rtmp_open(URLContext *s, const char *uri, int flags)
{
    LibRTMPContext *ctx = s->priv_data;
    RTMP *r = &ctx->rtmp;
    int rc = 0, level;
    char *filename = s->filename;
    int len = strlen(s->filename) + 1;

    switch (av_log_get_level()) {
    default:
    case AV_LOG_FATAL:   level = RTMP_LOGCRIT;    break;
    case AV_LOG_ERROR:   level = RTMP_LOGERROR;   break;
    case AV_LOG_WARNING: level = RTMP_LOGWARNING; break;
    case AV_LOG_INFO:    level = RTMP_LOGINFO;    break;
    case AV_LOG_VERBOSE: level = RTMP_LOGDEBUG;   break;
    case AV_LOG_DEBUG:   level = RTMP_LOGDEBUG2;  break;
    }
    RTMP_LogSetLevel(level);
    RTMP_LogSetCallback(rtmp_log);

    if (ctx->app)      len += strlen(ctx->app)      + sizeof(" app=");
    if (ctx->tcurl)    len += strlen(ctx->tcurl)    + sizeof(" tcUrl=");
    if (ctx->pageurl)  len += strlen(ctx->pageurl)  + sizeof(" pageUrl=");
    if (ctx->flashver) len += strlen(ctx->flashver) + sizeof(" flashver=");

    if (ctx->conn) {
        char *sep, *p = ctx->conn;
        int options = 0;

        while (p) {
            options++;
            p += strspn(p, " ");
            if (!*p)
                break;
            sep = strchr(p, ' ');
            if (sep)
                p = sep + 1;
            else
                break;
        }
        len += options * sizeof(" conn=");
        len += strlen(ctx->conn);
    }

    if (ctx->playpath)
        len += strlen(ctx->playpath) + sizeof(" playpath=");
    if (ctx->live)
        len += sizeof(" live=1");
    if (ctx->subscribe)
        len += strlen(ctx->subscribe) + sizeof(" subscribe=");

    if (ctx->client_buffer_time)
        len += strlen(ctx->client_buffer_time) + sizeof(" buffer=");

    if (ctx->swfurl || ctx->swfverify) {
        len += sizeof(" swfUrl=");

        if (ctx->swfverify)
            len += strlen(ctx->swfverify) + sizeof(" swfVfy=1");
        else
            len += strlen(ctx->swfurl);
    }

    if (!(ctx->temp_filename = filename = av_malloc(len)))
        return AVERROR(ENOMEM);

    av_strlcpy(filename, s->filename, len);
    if (ctx->app) {
        av_strlcat(filename, " app=", len);
        av_strlcat(filename, ctx->app, len);
    }
    if (ctx->tcurl) {
        av_strlcat(filename, " tcUrl=", len);
        av_strlcat(filename, ctx->tcurl, len);
    }
    if (ctx->pageurl) {
        av_strlcat(filename, " pageUrl=", len);
        av_strlcat(filename, ctx->pageurl, len);
    }
    if (ctx->swfurl) {
        av_strlcat(filename, " swfUrl=", len);
        av_strlcat(filename, ctx->swfurl, len);
    }
    if (ctx->flashver) {
        av_strlcat(filename, " flashVer=", len);
        av_strlcat(filename, ctx->flashver, len);
    }
    if (ctx->conn) {
        char *sep, *p = ctx->conn;
        while (p) {
            av_strlcat(filename, " conn=", len);
            p += strspn(p, " ");
            if (!*p)
                break;
            sep = strchr(p, ' ');
            if (sep)
                *sep = '\0';
            av_strlcat(filename, p, len);

            if (sep)
                p = sep + 1;
            else
                break;
        }
    }
    if (ctx->playpath) {
        av_strlcat(filename, " playpath=", len);
        av_strlcat(filename, ctx->playpath, len);
    }
    if (ctx->live)
        av_strlcat(filename, " live=1", len);
    if (ctx->subscribe) {
        av_strlcat(filename, " subscribe=", len);
        av_strlcat(filename, ctx->subscribe, len);
    }
    if (ctx->client_buffer_time) {
        av_strlcat(filename, " buffer=", len);
        av_strlcat(filename, ctx->client_buffer_time, len);
    }
    if (ctx->swfurl || ctx->swfverify) {
        av_strlcat(filename, " swfUrl=", len);

        if (ctx->swfverify) {
            av_strlcat(filename, ctx->swfverify, len);
            av_strlcat(filename, " swfVfy=1", len);
        } else {
            av_strlcat(filename, ctx->swfurl, len);
        }
    }

    RTMP_Init(r);
    if (!RTMP_SetupURL(r, filename)) {
        rc = AVERROR_UNKNOWN;
        goto fail;
    }

    if (flags & AVIO_FLAG_WRITE)
        RTMP_EnableWrite(r);

    if (!RTMP_Connect(r, NULL) || !RTMP_ConnectStream(r, 0)) {
        rc = AVERROR_UNKNOWN;
        goto fail;
    }

#if CONFIG_NETWORK
    if (ctx->buffer_size >= 0 && (flags & AVIO_FLAG_WRITE)) {
        int tmp = ctx->buffer_size;
        if (setsockopt(r->m_sb.sb_socket, SOL_SOCKET, SO_SNDBUF, &tmp, sizeof(tmp))) {
            rc = AVERROR_EXTERNAL;
            goto fail;
        }
    }
#endif

    s->is_streamed = 1;
    return 0;
fail:
    av_freep(&ctx->temp_filename);
    if (rc)
        RTMP_Close(r);

    return rc;
}

__attribute__((used)) static int rtmp_write(URLContext *s, const uint8_t *buf, int size)
{
    LibRTMPContext *ctx = s->priv_data;
    RTMP *r = &ctx->rtmp;

    int ret = RTMP_Write(r, buf, size);
    if (!ret)
        return AVERROR_EOF;
    return ret;
}

__attribute__((used)) static int rtmp_read(URLContext *s, uint8_t *buf, int size)
{
    LibRTMPContext *ctx = s->priv_data;
    RTMP *r = &ctx->rtmp;

    int ret = RTMP_Read(r, buf, size);
    if (!ret)
        return AVERROR_EOF;
    return ret;
}

__attribute__((used)) static int rtmp_read_pause(URLContext *s, int pause)
{
    LibRTMPContext *ctx = s->priv_data;
    RTMP *r = &ctx->rtmp;

    if (!RTMP_Pause(r, pause))
        return AVERROR_UNKNOWN;
    return 0;
}

__attribute__((used)) static int64_t rtmp_read_seek(URLContext *s, int stream_index,
                              int64_t timestamp, int flags)
{
    LibRTMPContext *ctx = s->priv_data;
    RTMP *r = &ctx->rtmp;

    if (flags & AVSEEK_FLAG_BYTE)
        return AVERROR(ENOSYS);

    /* seeks are in milliseconds */
    if (stream_index < 0)
        timestamp = av_rescale_rnd(timestamp, 1000, AV_TIME_BASE,
            flags & AVSEEK_FLAG_BACKWARD ? AV_ROUND_DOWN : AV_ROUND_UP);

    if (!RTMP_SendSeek(r, timestamp))
        return AVERROR_UNKNOWN;
    return timestamp;
}

__attribute__((used)) static int rtmp_get_file_handle(URLContext *s)
{
    LibRTMPContext *ctx = s->priv_data;
    RTMP *r = &ctx->rtmp;

    return RTMP_Socket(r);
}

