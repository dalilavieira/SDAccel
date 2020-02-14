#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_9__   TYPE_1__ ;

/* Type definitions */
typedef  int uint8_t ;
struct MD5Context {int /*<<< orphan*/  md5; } ;
typedef  int /*<<< orphan*/  md5 ;
struct TYPE_9__ {char* filename; int /*<<< orphan*/  protocol_blacklist; int /*<<< orphan*/  protocol_whitelist; int /*<<< orphan*/  interrupt_callback; struct MD5Context* priv_data; } ;
typedef  TYPE_1__ URLContext ;

/* Variables and functions */
 int AVERROR (int /*<<< orphan*/ ) ; 
 int AVIO_FLAG_WRITE ; 
 int /*<<< orphan*/  EINVAL ; 
 int /*<<< orphan*/  ENOMEM ; 
 int /*<<< orphan*/  av_freep (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  av_md5_alloc () ; 
 int /*<<< orphan*/  av_md5_final (int /*<<< orphan*/ ,int*) ; 
 int /*<<< orphan*/  av_md5_init (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  av_md5_update (int /*<<< orphan*/ ,unsigned char const*,int) ; 
 int /*<<< orphan*/  av_strstart (char const*,char*,char const**) ; 
 int /*<<< orphan*/  errno ; 
 int /*<<< orphan*/  ffurl_close (TYPE_1__*) ; 
 int ffurl_open_whitelist (TYPE_1__**,char const*,int,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ ,TYPE_1__*) ; 
 int ffurl_write (TYPE_1__*,int*,int) ; 
 int fwrite (int*,int,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  snprintf (int*,int,char*,int) ; 
 int /*<<< orphan*/  stdout ; 

__attribute__((used)) static int md5_open(URLContext *h, const char *filename, int flags)
{
    struct MD5Context *c = h->priv_data;

    if (!(flags & AVIO_FLAG_WRITE))
        return AVERROR(EINVAL);

    c->md5 = av_md5_alloc();
    if (!c->md5)
        return AVERROR(ENOMEM);
    av_md5_init(c->md5);

    return 0;
}

__attribute__((used)) static int md5_write(URLContext *h, const unsigned char *buf, int size)
{
    struct MD5Context *c = h->priv_data;
    av_md5_update(c->md5, buf, size);
    return size;
}

__attribute__((used)) static int md5_close(URLContext *h)
{
    struct MD5Context *c = h->priv_data;
    const char *filename = h->filename;
    uint8_t md5[16], buf[64];
    URLContext *out;
    int i, err = 0;

    av_md5_final(c->md5, md5);
    for (i = 0; i < sizeof(md5); i++)
        snprintf(buf + i*2, 3, "%02x", md5[i]);
    buf[i*2] = '\n';

    av_strstart(filename, "md5:", &filename);

    if (*filename) {
        err = ffurl_open_whitelist(&out, filename, AVIO_FLAG_WRITE,
                                   &h->interrupt_callback, NULL,
                                   h->protocol_whitelist, h->protocol_blacklist, h);
        if (err)
            return err;
        err = ffurl_write(out, buf, i*2+1);
        ffurl_close(out);
    } else {
        if (fwrite(buf, 1, i*2+1, stdout) < i*2+1)
            err = AVERROR(errno);
    }

    av_freep(&c->md5);

    return err;
}

