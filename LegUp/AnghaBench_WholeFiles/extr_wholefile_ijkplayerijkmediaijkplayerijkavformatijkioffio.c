#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_14__   TYPE_4__ ;
typedef  struct TYPE_13__   TYPE_3__ ;
typedef  struct TYPE_12__   TYPE_2__ ;
typedef  struct TYPE_11__   TYPE_1__ ;

/* Type definitions */
typedef  int int64_t ;
struct TYPE_14__ {int /*<<< orphan*/  value; int /*<<< orphan*/  key; } ;
struct TYPE_13__ {int /*<<< orphan*/  inner; } ;
struct TYPE_12__ {TYPE_3__* priv_data; TYPE_1__* ijkio_app_ctx; } ;
struct TYPE_11__ {scalar_t__ ijkio_interrupt_callback; } ;
typedef  TYPE_2__ IjkURLContext ;
typedef  TYPE_3__ IjkIOFFioContext ;
typedef  TYPE_4__ IjkAVDictionaryEntry ;
typedef  int /*<<< orphan*/  IjkAVDictionary ;
typedef  int /*<<< orphan*/  AVIOInterruptCB ;
typedef  int /*<<< orphan*/  AVDictionary ;

/* Variables and functions */
 int /*<<< orphan*/  IJK_AV_DICT_IGNORE_SUFFIX ; 
 int /*<<< orphan*/  av_dict_free (int /*<<< orphan*/ **) ; 
 int av_dict_set (int /*<<< orphan*/ **,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  av_strstart (char const*,char*,char const**) ; 
 int ffurl_close (int /*<<< orphan*/ ) ; 
 int ffurl_open_whitelist (int /*<<< orphan*/ *,char const*,int,int /*<<< orphan*/ *,int /*<<< orphan*/ **,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int ffurl_read (int /*<<< orphan*/ ,unsigned char*,int) ; 
 int ffurl_seek (int /*<<< orphan*/ ,int,int) ; 
 TYPE_4__* ijk_av_dict_get (int /*<<< orphan*/ *,char*,TYPE_4__*,int /*<<< orphan*/ ) ; 

__attribute__((used)) static int ijkio_copy_options(AVDictionary **dst, IjkAVDictionary *src) {
    IjkAVDictionaryEntry *t = NULL;

    while ((t = ijk_av_dict_get(src, "", t, IJK_AV_DICT_IGNORE_SUFFIX))) {
        int ret = av_dict_set(dst, t->key, t->value, 0);
        if (ret < 0)
            return ret;
    }

    return 0;
}

__attribute__((used)) static int ijkio_ffio_open(IjkURLContext *h, const char *url, int flags, IjkAVDictionary **options) {
    int ret = -1;

    IjkIOFFioContext *c= h->priv_data;
    if (!c)
        return -1;

    AVDictionary *opts = NULL;
    ijkio_copy_options(&opts, *options);

    av_strstart(url, "ffio:", &url);
    if (h->ijkio_app_ctx) {
        ret = ffurl_open_whitelist(&c->inner, url, flags, (AVIOInterruptCB *)h->ijkio_app_ctx->ijkio_interrupt_callback,
                                &opts, NULL, NULL, NULL);
    } else {
        ret = -1;
    }

    av_dict_free(&opts);

    return ret;
}

__attribute__((used)) static int ijkio_ffio_read(IjkURLContext *h, unsigned char *buf, int size) {
    if (!h)
        return -1;

    IjkIOFFioContext *c= h->priv_data;
    if (!c || !c->inner)
        return -1;

    return ffurl_read(c->inner, buf, size);
}

__attribute__((used)) static int64_t ijkio_ffio_seek(IjkURLContext *h, int64_t offset, int whence) {
    if (!h)
        return -1;

    IjkIOFFioContext *c= h->priv_data;

    if (!c || !c->inner)
        return -1;

    return ffurl_seek(c->inner, offset, whence);
}

__attribute__((used)) static int ijkio_ffio_close(IjkURLContext *h) {
    if (!h)
        return -1;

    IjkIOFFioContext *c= h->priv_data;

    if (!c || !c->inner)
        return -1;

    return ffurl_close(c->inner);
}

