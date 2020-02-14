#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_9__   TYPE_2__ ;
typedef  struct TYPE_8__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  webm ;
typedef  int uint8_t ;
typedef  int /*<<< orphan*/  path ;
typedef  int /*<<< orphan*/  opus ;
typedef  int /*<<< orphan*/  oggs ;
typedef  int /*<<< orphan*/  host ;
typedef  int /*<<< orphan*/  h_url ;
typedef  int /*<<< orphan*/  auth ;
struct TYPE_8__ {TYPE_2__* priv_data; int /*<<< orphan*/  protocol_blacklist; int /*<<< orphan*/  protocol_whitelist; } ;
typedef  TYPE_1__ URLContext ;
struct TYPE_9__ {char* name; char* description; char* url; char* genre; char const* content_type; char const* user_agent; char* pass; int send_started; scalar_t__ hd; scalar_t__ legacy_icecast; scalar_t__ public; } ;
typedef  TYPE_2__ IcecastContext ;
typedef  int /*<<< orphan*/  AVDictionary ;
typedef  int /*<<< orphan*/  AVBPrint ;

/* Variables and functions */
 int AVERROR (int /*<<< orphan*/ ) ; 
 int AVIO_FLAG_READ ; 
 int /*<<< orphan*/  AVIO_FLAG_READ_WRITE ; 
 int /*<<< orphan*/  AV_BPRINT_SIZE_AUTOMATIC ; 
 int /*<<< orphan*/  AV_LOG_ERROR ; 
 int /*<<< orphan*/  AV_LOG_WARNING ; 
 char* DEFAULT_ICE_USER ; 
 int /*<<< orphan*/  EIO ; 
 int /*<<< orphan*/  ENOMEM ; 
 int /*<<< orphan*/  ENOSYS ; 
 scalar_t__ NOT_EMPTY (char const*) ; 
 int /*<<< orphan*/  av_bprint_finalize (int /*<<< orphan*/ *,char**) ; 
 int /*<<< orphan*/  av_bprint_init (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  av_bprint_is_complete (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  av_bprintf (int /*<<< orphan*/ *,char*,char const*,char const*) ; 
 int /*<<< orphan*/  av_dict_free (int /*<<< orphan*/ **) ; 
 int /*<<< orphan*/  av_dict_set (int /*<<< orphan*/ **,char*,char*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  av_free (char*) ; 
 int /*<<< orphan*/  av_freep (char**) ; 
 int /*<<< orphan*/  av_log (TYPE_1__*,int /*<<< orphan*/ ,char*) ; 
 void* av_strdup (char*) ; 
 int /*<<< orphan*/  av_url_split (int /*<<< orphan*/ *,int /*<<< orphan*/ ,char*,int,char*,int,int*,char*,int,char const*) ; 
 int /*<<< orphan*/  ff_url_join (char*,int,char*,char*,char*,int,char*,char*) ; 
 int /*<<< orphan*/  ffurl_close (scalar_t__) ; 
 int ffurl_open_whitelist (scalar_t__*,char*,int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/ **,int /*<<< orphan*/ ,int /*<<< orphan*/ ,TYPE_1__*) ; 
 int ffurl_write (scalar_t__,int const*,int) ; 
 scalar_t__ memcmp (int const*,int const*,int) ; 
 int /*<<< orphan*/  snprintf (char*,int,char*,char*,char*) ; 
 char* strchr (char*,char) ; 
 scalar_t__ strcmp (char*,char*) ; 

__attribute__((used)) static inline int is_dos_path(const char *path)
{
#if HAVE_DOS_PATHS
    if (path[0] && path[1] == ':')
        return 1;
#endif
    return 0;
}

__attribute__((used)) static void cat_header(AVBPrint *bp, const char key[], const char value[])
{
    if (NOT_EMPTY(value))
        av_bprintf(bp, "%s: %s\r\n", key, value);
}

__attribute__((used)) static int icecast_close(URLContext *h)
{
    IcecastContext *s = h->priv_data;
    if (s->hd)
        ffurl_close(s->hd);
    return 0;
}

__attribute__((used)) static int icecast_open(URLContext *h, const char *uri, int flags)
{
    IcecastContext *s = h->priv_data;

    // Dict to set options that we pass to the HTTP protocol
    AVDictionary *opt_dict = NULL;

    // URI part variables
    char h_url[1024], host[1024], auth[1024], path[1024];
    char *headers = NULL, *user = NULL;
    int port, ret;
    AVBPrint bp;

    if (flags & AVIO_FLAG_READ)
        return AVERROR(ENOSYS);

    av_bprint_init(&bp, 0, AV_BPRINT_SIZE_AUTOMATIC);

    // Build header strings
    cat_header(&bp, "Ice-Name", s->name);
    cat_header(&bp, "Ice-Description", s->description);
    cat_header(&bp, "Ice-URL", s->url);
    cat_header(&bp, "Ice-Genre", s->genre);
    cat_header(&bp, "Ice-Public", s->public ? "1" : "0");
    if (!av_bprint_is_complete(&bp)) {
        ret = AVERROR(ENOMEM);
        goto cleanup;
    }
    av_bprint_finalize(&bp, &headers);

    // Set options
    av_dict_set(&opt_dict, "method", s->legacy_icecast ? "SOURCE" : "PUT", 0);
    av_dict_set(&opt_dict, "auth_type", "basic", 0);
    av_dict_set(&opt_dict, "headers", headers, 0);
    av_dict_set(&opt_dict, "chunked_post", "0", 0);
    av_dict_set(&opt_dict, "send_expect_100", s->legacy_icecast ? "-1" : "1", 0);
    if (NOT_EMPTY(s->content_type))
        av_dict_set(&opt_dict, "content_type", s->content_type, 0);
    else
        av_dict_set(&opt_dict, "content_type", "audio/mpeg", 0);
    if (NOT_EMPTY(s->user_agent))
        av_dict_set(&opt_dict, "user_agent", s->user_agent, 0);

    // Parse URI
    av_url_split(NULL, 0, auth, sizeof(auth), host, sizeof(host),
                 &port, path, sizeof(path), uri);

    // Check for auth data in URI
    if (auth[0]) {
        char *sep = strchr(auth, ':');
        if (sep) {
            *sep = 0;
            sep++;
            if (s->pass) {
                av_free(s->pass);
                av_log(h, AV_LOG_WARNING, "Overwriting -password <pass> with URI password!\n");
            }
            if (!(s->pass = av_strdup(sep))) {
                ret = AVERROR(ENOMEM);
                goto cleanup;
            }
        }
        if (!(user = av_strdup(auth))) {
            ret = AVERROR(ENOMEM);
            goto cleanup;
        }
    }

    // Build new authstring
    snprintf(auth, sizeof(auth),
             "%s:%s",
             user ? user : DEFAULT_ICE_USER,
             s->pass ? s->pass : "");

    // Check for mountpoint (path)
    if (!path[0] || strcmp(path, "/") == 0) {
        av_log(h, AV_LOG_ERROR, "No mountpoint (path) specified!\n");
        ret = AVERROR(EIO);
        goto cleanup;
    }

    // Build new URI for passing to http protocol
    ff_url_join(h_url, sizeof(h_url), "http", auth, host, port, "%s", path);
    // Finally open http proto handler
    ret = ffurl_open_whitelist(&s->hd, h_url, AVIO_FLAG_READ_WRITE, NULL,
                               &opt_dict, h->protocol_whitelist, h->protocol_blacklist, h);

cleanup:
    av_freep(&user);
    av_freep(&headers);
    av_dict_free(&opt_dict);

    return ret;
}

__attribute__((used)) static int icecast_write(URLContext *h, const uint8_t *buf, int size)
{
    IcecastContext *s = h->priv_data;
    if (!s->send_started) {
        s->send_started = 1;
        if (!s->content_type && size >= 8) {
            static const uint8_t oggs[4] = { 0x4F, 0x67, 0x67, 0x53 };
            static const uint8_t webm[4] = { 0x1A, 0x45, 0xDF, 0xA3 };
            static const uint8_t opus[8] = { 0x4F, 0x70, 0x75, 0x73, 0x48, 0x65, 0x61, 0x64 };
            if (memcmp(buf, oggs, sizeof(oggs)) == 0) {
                av_log(h, AV_LOG_WARNING, "Streaming Ogg but appropriate content type NOT set!\n");
                av_log(h, AV_LOG_WARNING, "Set it with -content_type application/ogg\n");
            } else if (memcmp(buf, opus, sizeof(opus)) == 0) {
                av_log(h, AV_LOG_WARNING, "Streaming Opus but appropriate content type NOT set!\n");
                av_log(h, AV_LOG_WARNING, "Set it with -content_type audio/ogg\n");
            } else if (memcmp(buf, webm, sizeof(webm)) == 0) {
                av_log(h, AV_LOG_WARNING, "Streaming WebM but appropriate content type NOT set!\n");
                av_log(h, AV_LOG_WARNING, "Set it with -content_type video/webm\n");
            } else {
                av_log(h, AV_LOG_WARNING, "It seems you are streaming an unsupported format.\n");
                av_log(h, AV_LOG_WARNING, "It might work, but is not officially supported in Icecast!\n");
            }
        }
    }
    return ffurl_write(s->hd, buf, size);
}

