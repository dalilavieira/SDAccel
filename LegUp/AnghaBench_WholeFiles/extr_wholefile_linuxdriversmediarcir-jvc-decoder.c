#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
typedef  int u32 ;
struct rc_dev {int /*<<< orphan*/  dev; TYPE_1__* raw; } ;
struct lirc_scancode {int dummy; } ;
struct jvc_dec {int state; int first; int toggle; int bits; int old_bits; int /*<<< orphan*/  count; } ;
struct ir_raw_event {scalar_t__ pulse; unsigned int duration; scalar_t__ reset; int /*<<< orphan*/  carrier_report; } ;
typedef  enum rc_proto { ____Placeholder_rc_proto } rc_proto ;
struct TYPE_2__ {struct jvc_dec jvc; } ;

/* Variables and functions */
 int EINVAL ; 
 int ENOBUFS ; 
 unsigned int JVC_BIT_0_SPACE ; 
 unsigned int JVC_BIT_1_SPACE ; 
 unsigned int JVC_BIT_PULSE ; 
 unsigned int JVC_HEADER_PULSE ; 
 unsigned int JVC_HEADER_SPACE ; 
 int /*<<< orphan*/  JVC_NBITS ; 
 unsigned int JVC_TRAILER_PULSE ; 
 unsigned int JVC_TRAILER_SPACE ; 
 int JVC_UNIT ; 
 int /*<<< orphan*/  RC_PROTO_JVC ; 
#define  STATE_BIT_PULSE 134 
#define  STATE_BIT_SPACE 133 
#define  STATE_CHECK_REPEAT 132 
#define  STATE_HEADER_SPACE 131 
#define  STATE_INACTIVE 130 
#define  STATE_TRAILER_PULSE 129 
#define  STATE_TRAILER_SPACE 128 
 int /*<<< orphan*/  TO_STR (unsigned int) ; 
 int /*<<< orphan*/  TO_US (unsigned int) ; 
 int bitrev8 (int) ; 
 int /*<<< orphan*/  dev_dbg (int /*<<< orphan*/ *,char*,...) ; 
 int /*<<< orphan*/  init_ir_raw_event (struct ir_raw_event*) ; 
 int /*<<< orphan*/  ir_jvc_timings ; 
 int ir_raw_gen_pd (struct ir_raw_event**,unsigned int,int /*<<< orphan*/ *,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  rc_keydown (struct rc_dev*,int /*<<< orphan*/ ,int,int) ; 
 int /*<<< orphan*/  rc_repeat (struct rc_dev*) ; 

__attribute__((used)) static inline bool geq_margin(unsigned d1, unsigned d2, unsigned margin)
{
	return d1 > (d2 - margin);
}

__attribute__((used)) static inline bool eq_margin(unsigned d1, unsigned d2, unsigned margin)
{
	return ((d1 > (d2 - margin)) && (d1 < (d2 + margin)));
}

__attribute__((used)) static inline bool is_transition(struct ir_raw_event *x, struct ir_raw_event *y)
{
	return x->pulse != y->pulse;
}

__attribute__((used)) static inline void decrease_duration(struct ir_raw_event *ev, unsigned duration)
{
	if (duration > ev->duration)
		ev->duration = 0;
	else
		ev->duration -= duration;
}

__attribute__((used)) static inline bool is_timing_event(struct ir_raw_event ev)
{
	return !ev.carrier_report && !ev.reset;
}

__attribute__((used)) static inline void init_ir_raw_event_duration(struct ir_raw_event *ev,
					      unsigned int pulse,
					      u32 duration)
{
	init_ir_raw_event(ev);
	ev->duration = duration;
	ev->pulse = pulse;
}

__attribute__((used)) static inline int ir_raw_gen_pulse_space(struct ir_raw_event **ev,
					 unsigned int *max,
					 unsigned int pulse_width,
					 unsigned int space_width)
{
	if (!*max)
		return -ENOBUFS;
	init_ir_raw_event_duration((*ev)++, 1, pulse_width);
	if (!--*max)
		return -ENOBUFS;
	init_ir_raw_event_duration((*ev)++, 0, space_width);
	--*max;
	return 0;
}

__attribute__((used)) static inline int lirc_dev_init(void) { return 0; }

__attribute__((used)) static inline void lirc_dev_exit(void) {}

__attribute__((used)) static inline void ir_lirc_raw_event(struct rc_dev *dev,
				     struct ir_raw_event ev) { }

__attribute__((used)) static inline void ir_lirc_scancode_event(struct rc_dev *dev,
					  struct lirc_scancode *lsc) { }

__attribute__((used)) static inline int ir_lirc_register(struct rc_dev *dev) { return 0; }

__attribute__((used)) static inline void ir_lirc_unregister(struct rc_dev *dev) { }

__attribute__((used)) static inline void lirc_bpf_free(struct rc_dev *dev) { }

__attribute__((used)) static inline void lirc_bpf_run(struct rc_dev *dev, u32 sample) { }

__attribute__((used)) static int ir_jvc_decode(struct rc_dev *dev, struct ir_raw_event ev)
{
	struct jvc_dec *data = &dev->raw->jvc;

	if (!is_timing_event(ev)) {
		if (ev.reset)
			data->state = STATE_INACTIVE;
		return 0;
	}

	if (!geq_margin(ev.duration, JVC_UNIT, JVC_UNIT / 2))
		goto out;

	dev_dbg(&dev->dev, "JVC decode started at state %d (%uus %s)\n",
		data->state, TO_US(ev.duration), TO_STR(ev.pulse));

again:
	switch (data->state) {

	case STATE_INACTIVE:
		if (!ev.pulse)
			break;

		if (!eq_margin(ev.duration, JVC_HEADER_PULSE, JVC_UNIT / 2))
			break;

		data->count = 0;
		data->first = true;
		data->toggle = !data->toggle;
		data->state = STATE_HEADER_SPACE;
		return 0;

	case STATE_HEADER_SPACE:
		if (ev.pulse)
			break;

		if (!eq_margin(ev.duration, JVC_HEADER_SPACE, JVC_UNIT / 2))
			break;

		data->state = STATE_BIT_PULSE;
		return 0;

	case STATE_BIT_PULSE:
		if (!ev.pulse)
			break;

		if (!eq_margin(ev.duration, JVC_BIT_PULSE, JVC_UNIT / 2))
			break;

		data->state = STATE_BIT_SPACE;
		return 0;

	case STATE_BIT_SPACE:
		if (ev.pulse)
			break;

		data->bits <<= 1;
		if (eq_margin(ev.duration, JVC_BIT_1_SPACE, JVC_UNIT / 2)) {
			data->bits |= 1;
			decrease_duration(&ev, JVC_BIT_1_SPACE);
		} else if (eq_margin(ev.duration, JVC_BIT_0_SPACE, JVC_UNIT / 2))
			decrease_duration(&ev, JVC_BIT_0_SPACE);
		else
			break;
		data->count++;

		if (data->count == JVC_NBITS)
			data->state = STATE_TRAILER_PULSE;
		else
			data->state = STATE_BIT_PULSE;
		return 0;

	case STATE_TRAILER_PULSE:
		if (!ev.pulse)
			break;

		if (!eq_margin(ev.duration, JVC_TRAILER_PULSE, JVC_UNIT / 2))
			break;

		data->state = STATE_TRAILER_SPACE;
		return 0;

	case STATE_TRAILER_SPACE:
		if (ev.pulse)
			break;

		if (!geq_margin(ev.duration, JVC_TRAILER_SPACE, JVC_UNIT / 2))
			break;

		if (data->first) {
			u32 scancode;
			scancode = (bitrev8((data->bits >> 8) & 0xff) << 8) |
				   (bitrev8((data->bits >> 0) & 0xff) << 0);
			dev_dbg(&dev->dev, "JVC scancode 0x%04x\n", scancode);
			rc_keydown(dev, RC_PROTO_JVC, scancode, data->toggle);
			data->first = false;
			data->old_bits = data->bits;
		} else if (data->bits == data->old_bits) {
			dev_dbg(&dev->dev, "JVC repeat\n");
			rc_repeat(dev);
		} else {
			dev_dbg(&dev->dev, "JVC invalid repeat msg\n");
			break;
		}

		data->count = 0;
		data->state = STATE_CHECK_REPEAT;
		return 0;

	case STATE_CHECK_REPEAT:
		if (!ev.pulse)
			break;

		if (eq_margin(ev.duration, JVC_HEADER_PULSE, JVC_UNIT / 2))
			data->state = STATE_INACTIVE;
  else
			data->state = STATE_BIT_PULSE;
		goto again;
	}

out:
	dev_dbg(&dev->dev, "JVC decode failed at state %d (%uus %s)\n",
		data->state, TO_US(ev.duration), TO_STR(ev.pulse));
	data->state = STATE_INACTIVE;
	return -EINVAL;
}

__attribute__((used)) static int ir_jvc_encode(enum rc_proto protocol, u32 scancode,
			 struct ir_raw_event *events, unsigned int max)
{
	struct ir_raw_event *e = events;
	int ret;
	u32 raw = (bitrev8((scancode >> 8) & 0xff) << 8) |
		  (bitrev8((scancode >> 0) & 0xff) << 0);

	ret = ir_raw_gen_pd(&e, max, &ir_jvc_timings, JVC_NBITS, raw);
	if (ret < 0)
		return ret;

	return e - events;
}

