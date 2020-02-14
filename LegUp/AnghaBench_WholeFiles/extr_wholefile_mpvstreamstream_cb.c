#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_19__   TYPE_2__ ;
typedef  struct TYPE_18__   TYPE_1__ ;

/* Type definitions */
struct TYPE_19__ {scalar_t__ (* seek_fn ) (int /*<<< orphan*/ ,scalar_t__) ;scalar_t__ (* size_fn ) (int /*<<< orphan*/ ) ;int /*<<< orphan*/  cookie; int /*<<< orphan*/  (* close_fn ) (int /*<<< orphan*/ ) ;scalar_t__ (* read_fn ) (int /*<<< orphan*/ ,char*,size_t) ;int /*<<< orphan*/  member_0; } ;
struct priv {TYPE_2__ info; } ;
struct TYPE_18__ {scalar_t__ buf_pos; scalar_t__ buf_len; int* buffer; int eof; scalar_t__ pos; int (* seek ) (TYPE_1__*,scalar_t__) ;int seekable; int fast_skip; int (* fill_buffer ) (TYPE_1__*,char*,int) ;int (* control ) (TYPE_1__*,int,void*) ;int read_chunk; void (* close ) (TYPE_1__*) ;int /*<<< orphan*/  url; int /*<<< orphan*/  global; struct priv* priv; } ;
typedef  TYPE_1__ stream_t ;
typedef  int (* mpv_stream_cb_open_ro_fn ) (void*,int /*<<< orphan*/ ,TYPE_2__*) ;
typedef  TYPE_2__ mpv_stream_cb_info ;
typedef  scalar_t__ int64_t ;
typedef  int /*<<< orphan*/  bstr ;

/* Variables and functions */
 int MPV_ERROR_LOADING_FAILED ; 
 int /*<<< orphan*/  MP_FATAL (TYPE_1__*,char*) ; 
 int /*<<< orphan*/  MP_WARN (TYPE_1__*,char*) ; 
#define  STREAM_CTRL_GET_SIZE 128 
 int STREAM_ERROR ; 
 int STREAM_OK ; 
 int STREAM_UNSUPPORTED ; 
 int /*<<< orphan*/  bstr0 (int /*<<< orphan*/ ) ; 
 char* bstrto0 (TYPE_1__*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mp_split_proto (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mp_streamcb_lookup (int /*<<< orphan*/ ,char*,void**,int (*) (void*,int /*<<< orphan*/ ,TYPE_2__*)) ; 
 struct priv* p ; 
 scalar_t__ stream_fill_buffer (TYPE_1__*) ; 
 scalar_t__ stub1 (int /*<<< orphan*/ ,char*,size_t) ; 
 scalar_t__ stub2 (int /*<<< orphan*/ ,scalar_t__) ; 
 scalar_t__ stub3 (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  stub4 (int /*<<< orphan*/ ) ; 
 scalar_t__ stub5 (int /*<<< orphan*/ ,scalar_t__) ; 
 struct priv* talloc_ptrtype (TYPE_1__*,int /*<<< orphan*/ ) ; 

__attribute__((used)) inline static int stream_read_char(stream_t *s)
{
    return (s->buf_pos < s->buf_len) ? s->buffer[s->buf_pos++] :
           (stream_fill_buffer(s) ? s->buffer[s->buf_pos++] : -256);
}

__attribute__((used)) inline static int stream_eof(stream_t *s)
{
    return s->eof;
}

__attribute__((used)) inline static int64_t stream_tell(stream_t *s)
{
    return s->pos + s->buf_pos - s->buf_len;
}

__attribute__((used)) static int fill_buffer(stream_t *s, char *buffer, int max_len)
{
    struct priv *p = s->priv;
    return (int)p->info.read_fn(p->info.cookie, buffer, (size_t)max_len);
}

__attribute__((used)) static int seek(stream_t *s, int64_t newpos)
{
    struct priv *p = s->priv;
    return p->info.seek_fn(p->info.cookie, newpos) >= 0;
}

__attribute__((used)) static int control(stream_t *s, int cmd, void *arg)
{
    struct priv *p = s->priv;
    switch (cmd) {
    case STREAM_CTRL_GET_SIZE: {
        if (!p->info.size_fn)
            break;
        int64_t size = p->info.size_fn(p->info.cookie);
        if (size >= 0) {
            *(int64_t *)arg = size;
            return 1;
        }
        break;
    }
    }
    return STREAM_UNSUPPORTED;
}

__attribute__((used)) static void s_close(stream_t *s)
{
    struct priv *p = s->priv;
    p->info.close_fn(p->info.cookie);
}

__attribute__((used)) static int open_cb(stream_t *stream)
{
    struct priv *p = talloc_ptrtype(stream, p);
    stream->priv = p;

    bstr bproto = mp_split_proto(bstr0(stream->url), NULL);
    char *proto = bstrto0(stream, bproto);

    void *user_data;
    mpv_stream_cb_open_ro_fn open_fn;

    if (!mp_streamcb_lookup(stream->global, proto, &user_data, &open_fn))
        return STREAM_UNSUPPORTED;

    mpv_stream_cb_info info = {0};

    int r = open_fn(user_data, stream->url, &info);
    if (r < 0) {
        if (r != MPV_ERROR_LOADING_FAILED)
            MP_WARN(stream, "unknown error from user callback\n");
        return STREAM_ERROR;
    }

    if (!info.read_fn || !info.close_fn) {
        MP_FATAL(stream, "required read_fn or close_fn callbacks not set.\n");
        return STREAM_ERROR;
    }

    p->info = info;

    if (p->info.seek_fn && p->info.seek_fn(p->info.cookie, 0) >= 0) {
        stream->seek = seek;
        stream->seekable = true;
    }
    stream->fast_skip = true;
    stream->fill_buffer = fill_buffer;
    stream->control = control;
    stream->read_chunk = 64 * 1024;
    stream->close = s_close;

    return STREAM_OK;
}

