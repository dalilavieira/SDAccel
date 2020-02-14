#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_6__   TYPE_1__ ;

/* Type definitions */
struct TYPE_6__ {int /*<<< orphan*/  const* priv_class; int /*<<< orphan*/  name; } ;
typedef  int /*<<< orphan*/  AVClass ;
typedef  TYPE_1__ AVBitStreamFilter ;

/* Variables and functions */
 TYPE_1__** bitstream_filters ; 
 int /*<<< orphan*/  strcmp (int /*<<< orphan*/ ,char const*) ; 

const AVBitStreamFilter *av_bsf_iterate(void **opaque)
{
    uintptr_t i = (uintptr_t)*opaque;
    const AVBitStreamFilter *f = bitstream_filters[i];

    if (f)
        *opaque = (void*)(i + 1);

    return f;
}

const AVBitStreamFilter *av_bsf_next(void **opaque) {
    return av_bsf_iterate(opaque);
}

const AVBitStreamFilter *av_bsf_get_by_name(const char *name)
{
    const AVBitStreamFilter *f = NULL;
    void *i = 0;

    if (!name)
        return NULL;

    while ((f = av_bsf_iterate(&i))) {
        if (!strcmp(f->name, name))
            return f;
    }

    return NULL;
}

const AVClass *ff_bsf_child_class_next(const AVClass *prev)
{
    const AVBitStreamFilter *f = NULL;
    void *i = 0;

    /* find the filter that corresponds to prev */
    while (prev && (f = av_bsf_iterate(&i))) {
        if (f->priv_class == prev) {
            break;
        }
    }

    /* find next filter with priv options */
    while ((f = av_bsf_iterate(&i))) {
        if (f->priv_class)
            return f->priv_class;
    }
    return NULL;
}

