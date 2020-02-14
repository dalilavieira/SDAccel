#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_18__   TYPE_4__ ;
typedef  struct TYPE_17__   TYPE_3__ ;
typedef  struct TYPE_16__   TYPE_2__ ;
typedef  struct TYPE_15__   TYPE_1__ ;

/* Type definitions */
typedef  int int64_t ;
struct TYPE_15__ {TYPE_3__* priv_data; int /*<<< orphan*/  interrupt_callback; } ;
typedef  TYPE_1__ URLContext ;
struct TYPE_18__ {int /*<<< orphan*/  value; int /*<<< orphan*/  key; } ;
struct TYPE_17__ {scalar_t__ io_manager_ctx; } ;
struct TYPE_16__ {TYPE_3__* cur_ffmpeg_ctx; int /*<<< orphan*/ * ijkio_interrupt_callback; } ;
typedef  TYPE_2__ IjkIOManagerContext ;
typedef  int /*<<< orphan*/  IjkAVIOInterruptCB ;
typedef  int /*<<< orphan*/  IjkAVDictionary ;
typedef  TYPE_3__ Context ;
typedef  TYPE_4__ AVDictionaryEntry ;
typedef  int /*<<< orphan*/  AVDictionary ;

/* Variables and functions */
 int /*<<< orphan*/  AV_DICT_IGNORE_SUFFIX ; 
 TYPE_4__* av_dict_get (int /*<<< orphan*/ *,char*,TYPE_4__*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  av_strstart (char const*,char*,char const**) ; 
 int /*<<< orphan*/  ijk_av_dict_free (int /*<<< orphan*/ **) ; 
 int ijk_av_dict_set (int /*<<< orphan*/ **,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int ijkio_manager_io_close (TYPE_2__*) ; 
 int ijkio_manager_io_open (TYPE_2__*,char const*,int,int /*<<< orphan*/ **) ; 
 int ijkio_manager_io_read (TYPE_2__*,unsigned char*,int) ; 
 int ijkio_manager_io_seek (TYPE_2__*,int,int) ; 

__attribute__((used)) static int ijkio_copy_options(IjkAVDictionary **dst, AVDictionary *src) {
    AVDictionaryEntry *t = NULL;

    while ((t = av_dict_get(src, "", t, AV_DICT_IGNORE_SUFFIX))) {
        int ret = ijk_av_dict_set(dst, t->key, t->value, 0);
        if (ret < 0)
            return ret;
    }

    return 0;
}

__attribute__((used)) static int ijkio_open(URLContext *h, const char *arg, int flags, AVDictionary **options)
{
    Context *c = h->priv_data;
    int ret = -1;

    if (!c || !c->io_manager_ctx)
        return -1;

    IjkIOManagerContext *manager_ctx = (IjkIOManagerContext *)(c->io_manager_ctx);
    manager_ctx->ijkio_interrupt_callback = (IjkAVIOInterruptCB *)&(h->interrupt_callback);

    av_strstart(arg, "ijkio:", &arg);
    IjkAVDictionary *opts = NULL;
    ijkio_copy_options(&opts, *options);

    manager_ctx->cur_ffmpeg_ctx = c;

    ret = ijkio_manager_io_open(manager_ctx, arg, flags, &opts);
    ijk_av_dict_free(&opts);

    if (ret != 0) {
        ijkio_manager_io_close(manager_ctx);
    }

    return ret;
}

__attribute__((used)) static int ijkio_read(URLContext *h, unsigned char *buf, int size)
{
    Context *c = h->priv_data;

    if (!c || !c->io_manager_ctx)
        return -1;

    ((IjkIOManagerContext *)(c->io_manager_ctx))->cur_ffmpeg_ctx  = c;
    return ijkio_manager_io_read((IjkIOManagerContext *)(c->io_manager_ctx), buf, size);
}

__attribute__((used)) static int64_t ijkio_seek(URLContext *h, int64_t offset, int whence)
{
    Context *c = h->priv_data;

    if (!c || !c->io_manager_ctx)
        return -1;

    ((IjkIOManagerContext *)(c->io_manager_ctx))->cur_ffmpeg_ctx  = c;
    return ijkio_manager_io_seek((IjkIOManagerContext *)(c->io_manager_ctx), offset, whence);
}

__attribute__((used)) static int ijkio_close(URLContext *h)
{
    Context *c = h->priv_data;

    if (!c || !c->io_manager_ctx)
        return -1;

    ((IjkIOManagerContext *)(c->io_manager_ctx))->cur_ffmpeg_ctx  = c;
    return ijkio_manager_io_close((IjkIOManagerContext *)(c->io_manager_ctx));
}

