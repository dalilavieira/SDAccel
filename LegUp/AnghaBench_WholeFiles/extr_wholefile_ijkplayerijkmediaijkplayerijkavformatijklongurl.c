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
typedef  int /*<<< orphan*/  int64_t ;
struct TYPE_8__ {TYPE_2__* priv_data; int /*<<< orphan*/  protocol_blacklist; int /*<<< orphan*/  protocol_whitelist; int /*<<< orphan*/  interrupt_callback; } ;
typedef  TYPE_1__ URLContext ;
struct TYPE_9__ {int /*<<< orphan*/  inner; int /*<<< orphan*/ * url; } ;
typedef  TYPE_2__ Context ;
typedef  int /*<<< orphan*/  AVDictionary ;

/* Variables and functions */
 int AVERROR_EXTERNAL ; 
 int ffurl_close (int /*<<< orphan*/ ) ; 
 int ffurl_open_whitelist (int /*<<< orphan*/ *,int /*<<< orphan*/ *,int,int /*<<< orphan*/ *,int /*<<< orphan*/ **,int /*<<< orphan*/ ,int /*<<< orphan*/ ,TYPE_1__*) ; 
 int ffurl_read (int /*<<< orphan*/ ,unsigned char*,int) ; 
 int /*<<< orphan*/  ffurl_seek (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int) ; 

__attribute__((used)) static int ijklongurl_open(URLContext *h, const char *arg, int flags, AVDictionary **options)
{
    Context *c = h->priv_data;

    if (!c->url || !*c->url)
        return AVERROR_EXTERNAL;

    return ffurl_open_whitelist(&c->inner,
                                c->url,
                                flags,
                                &h->interrupt_callback,
                                options,
                                h->protocol_whitelist,
                                h->protocol_blacklist,
                                h);
}

__attribute__((used)) static int ijklongurl_close(URLContext *h)
{
    Context *c = h->priv_data;

    return ffurl_close(c->inner);
}

__attribute__((used)) static int ijklongurl_read(URLContext *h, unsigned char *buf, int size)
{
    Context *c = h->priv_data;

    return ffurl_read(c->inner, buf, size);
}

__attribute__((used)) static int64_t ijklongurl_seek(URLContext *h, int64_t pos, int whence)
{
    Context *c = h->priv_data;

    return ffurl_seek(c->inner, pos, whence);
}

