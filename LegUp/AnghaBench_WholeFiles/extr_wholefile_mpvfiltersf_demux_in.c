#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */

/* Type definitions */
struct sh_stream {int dummy; } ;
struct priv {int eof_returned; struct sh_stream* src; } ;
struct mp_frame {int /*<<< orphan*/  type; struct demux_packet* member_1; int /*<<< orphan*/  member_0; } ;
struct mp_filter {struct priv* priv; int /*<<< orphan*/ * ppins; } ;
struct demux_packet {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  MP_FRAME_EOF ; 
 int /*<<< orphan*/  MP_FRAME_PACKET ; 
 int /*<<< orphan*/  MP_PIN_OUT ; 
 int /*<<< orphan*/  demux_filter ; 
 scalar_t__ demux_read_packet_async (struct sh_stream*,struct demux_packet**) ; 
 int /*<<< orphan*/  demux_set_stream_wakeup_cb (struct sh_stream*,...) ; 
 int /*<<< orphan*/  mp_filter_add_pin (struct mp_filter*,int /*<<< orphan*/ ,char*) ; 
 struct mp_filter* mp_filter_create (struct mp_filter*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mp_filter_wakeup (struct mp_filter*) ; 
 int /*<<< orphan*/  mp_pin_in_needs_data (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mp_pin_in_write (int /*<<< orphan*/ ,struct mp_frame) ; 

__attribute__((used)) static void wakeup(void *ctx)
{
    struct mp_filter *f = ctx;

    mp_filter_wakeup(f);
}

__attribute__((used)) static void process(struct mp_filter *f)
{
    struct priv *p = f->priv;

    if (!mp_pin_in_needs_data(f->ppins[0]))
        return;

    struct demux_packet *pkt = NULL;
    if (demux_read_packet_async(p->src, &pkt) == 0)
        return; // wait

    struct mp_frame frame = {MP_FRAME_PACKET, pkt};
    if (pkt) {
        p->eof_returned = false;
    } else {
        frame.type = MP_FRAME_EOF;

        // While the demuxer will repeat EOFs, filters never do that.
        if (p->eof_returned)
            return;
        p->eof_returned = true;
    }

    mp_pin_in_write(f->ppins[0], frame);
}

__attribute__((used)) static void reset(struct mp_filter *f)
{
    struct priv *p = f->priv;

    p->eof_returned = false;
}

__attribute__((used)) static void destroy(struct mp_filter *f)
{
    struct priv *p = f->priv;

    demux_set_stream_wakeup_cb(p->src, NULL, NULL);
}

struct mp_filter *mp_demux_in_create(struct mp_filter *parent,
                                     struct sh_stream *src)
{
    struct mp_filter *f = mp_filter_create(parent, &demux_filter);
    if (!f)
        return NULL;

    struct priv *p = f->priv;
    p->src = src;

    mp_filter_add_pin(f, MP_PIN_OUT, "out");

    demux_set_stream_wakeup_cb(p->src, wakeup, f);

    return f;
}

