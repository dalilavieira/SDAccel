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
typedef  scalar_t__ int64_t ;
struct TYPE_10__ {TYPE_2__* priv_data; int /*<<< orphan*/  protocol_blacklist; int /*<<< orphan*/  protocol_whitelist; int /*<<< orphan*/  interrupt_callback; } ;
typedef  TYPE_1__ URLContext ;
struct TYPE_11__ {scalar_t__ pos; scalar_t__ end; scalar_t__ start; int /*<<< orphan*/  h; } ;
typedef  TYPE_2__ SubfileContext ;
typedef  int /*<<< orphan*/  AVDictionary ;

/* Variables and functions */
 scalar_t__ AVERROR (int /*<<< orphan*/ ) ; 
 scalar_t__ AVERROR_BUG ; 
 int AVERROR_EOF ; 
 int AVSEEK_SIZE ; 
 int /*<<< orphan*/  AV_LOG_ERROR ; 
 int /*<<< orphan*/  EINVAL ; 
 int FFMIN (int,scalar_t__) ; 
 scalar_t__ INT64_MAX ; 
#define  SEEK_CUR 130 
#define  SEEK_END 129 
#define  SEEK_SET 128 
 int /*<<< orphan*/  av_err2str (scalar_t__) ; 
 int /*<<< orphan*/  av_log (TYPE_1__*,int /*<<< orphan*/ ,char*,...) ; 
 int /*<<< orphan*/  av_strstart (char const*,char*,char const**) ; 
 int ffurl_close (int /*<<< orphan*/ ) ; 
 int ffurl_open_whitelist (int /*<<< orphan*/ *,char const*,int,int /*<<< orphan*/ *,int /*<<< orphan*/ **,int /*<<< orphan*/ ,int /*<<< orphan*/ ,TYPE_1__*) ; 
 int ffurl_read (int /*<<< orphan*/ ,unsigned char*,int) ; 
 scalar_t__ ffurl_seek (int /*<<< orphan*/ ,scalar_t__,int) ; 

__attribute__((used)) static int slave_seek(URLContext *h)
{
    SubfileContext *c = h->priv_data;
    int64_t ret;

    if ((ret = ffurl_seek(c->h, c->pos, SEEK_SET)) != c->pos) {
        if (ret >= 0)
            ret = AVERROR_BUG;
        av_log(h, AV_LOG_ERROR, "Impossible to seek in file: %s\n",
               av_err2str(ret));
        return ret;
    }
    return 0;
}

__attribute__((used)) static int subfile_open(URLContext *h, const char *filename, int flags,
                        AVDictionary **options)
{
    SubfileContext *c = h->priv_data;
    int ret;

    if (!c->end)
        c->end = INT64_MAX;

    if (c->end <= c->start) {
        av_log(h, AV_LOG_ERROR, "end before start\n");
        return AVERROR(EINVAL);
    }
    av_strstart(filename, "subfile:", &filename);
    ret = ffurl_open_whitelist(&c->h, filename, flags, &h->interrupt_callback,
                               options, h->protocol_whitelist, h->protocol_blacklist, h);
    if (ret < 0)
        return ret;
    c->pos = c->start;
    if ((ret = slave_seek(h)) < 0) {
        ffurl_close(c->h);
        return ret;
    }
    return 0;
}

__attribute__((used)) static int subfile_close(URLContext *h)
{
    SubfileContext *c = h->priv_data;
    return ffurl_close(c->h);
}

__attribute__((used)) static int subfile_read(URLContext *h, unsigned char *buf, int size)
{
    SubfileContext *c = h->priv_data;
    int64_t rest = c->end - c->pos;
    int ret;

    if (rest <= 0)
        return AVERROR_EOF;
    size = FFMIN(size, rest);
    ret = ffurl_read(c->h, buf, size);
    if (ret >= 0)
        c->pos += ret;
    return ret;
}

__attribute__((used)) static int64_t subfile_seek(URLContext *h, int64_t pos, int whence)
{
    SubfileContext *c = h->priv_data;
    int64_t new_pos = -1;
    int ret;

    if (whence == AVSEEK_SIZE)
        return c->end - c->start;
    switch (whence) {
    case SEEK_SET:
        new_pos = c->start + pos;
        break;
    case SEEK_CUR:
        new_pos += pos;
        break;
    case SEEK_END:
        new_pos = c->end + c->pos;
        break;
    }
    if (new_pos < c->start)
        return AVERROR(EINVAL);
    c->pos = new_pos;
    if ((ret = slave_seek(h)) < 0)
        return ret;
    return c->pos - c->start;
}

