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
struct priv {int /*<<< orphan*/  in_pin; TYPE_4__* opts; } ;
struct mp_frame {scalar_t__ type; struct mp_aframe* data; } ;
struct mp_filter {int /*<<< orphan*/ * ppins; struct priv* priv; } ;
struct mp_autoconvert {TYPE_3__* f; } ;
struct mp_aframe {int dummy; } ;
struct TYPE_6__ {scalar_t__ num_chmaps; int /*<<< orphan*/ * chmaps; } ;
struct TYPE_5__ {scalar_t__ num_chmaps; int /*<<< orphan*/ * chmaps; } ;
struct TYPE_8__ {TYPE_2__ in_channels; scalar_t__ in_srate; scalar_t__ in_format; scalar_t__ out_srate; TYPE_1__ out_channels; scalar_t__ fail; } ;
struct TYPE_7__ {int /*<<< orphan*/ * pins; } ;

/* Variables and functions */
 int /*<<< orphan*/  MP_ERR (struct mp_filter*,char*) ; 
 scalar_t__ MP_FRAME_AUDIO ; 
 scalar_t__ MP_FRAME_EOF ; 
 int /*<<< orphan*/  MP_PIN_IN ; 
 int /*<<< orphan*/  MP_PIN_OUT ; 
 int /*<<< orphan*/  abort () ; 
 int /*<<< orphan*/  af_format_filter ; 
 int /*<<< orphan*/  mp_aframe_set_chmap (struct mp_aframe*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mp_aframe_set_rate (struct mp_aframe*,scalar_t__) ; 
 int /*<<< orphan*/  mp_autoconvert_add_afmt (struct mp_autoconvert*,scalar_t__) ; 
 int /*<<< orphan*/  mp_autoconvert_add_chmap (struct mp_autoconvert*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mp_autoconvert_add_srate (struct mp_autoconvert*,scalar_t__) ; 
 struct mp_autoconvert* mp_autoconvert_create (struct mp_filter*) ; 
 int /*<<< orphan*/  mp_filter_add_pin (struct mp_filter*,int /*<<< orphan*/ ,char*) ; 
 struct mp_filter* mp_filter_create (struct mp_filter*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mp_filter_internal_mark_failed (struct mp_filter*) ; 
 int /*<<< orphan*/  mp_frame_unref (struct mp_frame*) ; 
 int /*<<< orphan*/  mp_pin_can_transfer_data (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mp_pin_connect (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mp_pin_in_write (int /*<<< orphan*/ ,struct mp_frame) ; 
 struct mp_frame mp_pin_out_read (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  talloc_free (void*) ; 
 TYPE_4__* talloc_steal (struct priv*,void*) ; 

__attribute__((used)) static void process(struct mp_filter *f)
{
    struct priv *p = f->priv;

    if (!mp_pin_can_transfer_data(f->ppins[1], p->in_pin))
        return;

    struct mp_frame frame = mp_pin_out_read(p->in_pin);

    if (p->opts->fail) {
        MP_ERR(f, "Failing on purpose.\n");
        goto error;
    }

    if (frame.type == MP_FRAME_EOF) {
        mp_pin_in_write(f->ppins[1], frame);
        return;
    }

    if (frame.type != MP_FRAME_AUDIO) {
        MP_ERR(f, "audio frame expected\n");
        goto error;
    }

    struct mp_aframe *in = frame.data;

    if (p->opts->out_channels.num_chmaps > 0) {
        if (!mp_aframe_set_chmap(in, &p->opts->out_channels.chmaps[0])) {
            MP_ERR(f, "could not force output channels\n");
            goto error;
        }
    }

    if (p->opts->out_srate)
        mp_aframe_set_rate(in, p->opts->out_srate);

    mp_pin_in_write(f->ppins[1], frame);
    return;

error:
    mp_frame_unref(&frame);
    mp_filter_internal_mark_failed(f);
}

__attribute__((used)) static struct mp_filter *af_format_create(struct mp_filter *parent,
                                              void *options)
{
    struct mp_filter *f = mp_filter_create(parent, &af_format_filter);
    if (!f) {
        talloc_free(options);
        return NULL;
    }

    struct priv *p = f->priv;
    p->opts = talloc_steal(p, options);

    mp_filter_add_pin(f, MP_PIN_IN, "in");
    mp_filter_add_pin(f, MP_PIN_OUT, "out");

    struct mp_autoconvert *conv = mp_autoconvert_create(f);
    if (!conv)
        abort();

    if (p->opts->in_format)
        mp_autoconvert_add_afmt(conv, p->opts->in_format);
    if (p->opts->in_srate)
        mp_autoconvert_add_srate(conv, p->opts->in_srate);
    if (p->opts->in_channels.num_chmaps > 0)
        mp_autoconvert_add_chmap(conv, &p->opts->in_channels.chmaps[0]);

    mp_pin_connect(conv->f->pins[0], f->ppins[0]);
    p->in_pin = conv->f->pins[1];

    return f;
}

