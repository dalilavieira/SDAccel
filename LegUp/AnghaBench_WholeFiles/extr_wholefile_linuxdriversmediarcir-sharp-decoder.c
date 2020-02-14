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
struct sharp_dec {int state; int count; unsigned int pulse_len; int bits; } ;
struct rc_dev {int /*<<< orphan*/  dev; TYPE_1__* raw; } ;
struct lirc_scancode {int dummy; } ;
struct ir_raw_event {scalar_t__ pulse; unsigned int duration; scalar_t__ reset; int /*<<< orphan*/  carrier_report; } ;
typedef  enum rc_proto { ____Placeholder_rc_proto } rc_proto ;
struct TYPE_2__ {struct sharp_dec sharp; } ;

/* Variables and functions */
 int EINVAL ; 
 int ENOBUFS ; 
 int /*<<< orphan*/  RC_PROTO_SHARP ; 
 unsigned int SHARP_BIT_0_PERIOD ; 
 unsigned int SHARP_BIT_1_PERIOD ; 
 int SHARP_BIT_PULSE ; 
 int SHARP_ECHO_SPACE ; 
 int SHARP_NBITS ; 
 unsigned int SHARP_TRAILER_SPACE ; 
#define  STATE_BIT_PULSE 133 
#define  STATE_BIT_SPACE 132 
#define  STATE_ECHO_SPACE 131 
#define  STATE_INACTIVE 130 
#define  STATE_TRAILER_PULSE 129 
#define  STATE_TRAILER_SPACE 128 
 int /*<<< orphan*/  TO_STR (unsigned int) ; 
 int /*<<< orphan*/  TO_US (int) ; 
 int bitrev8 (int) ; 
 int /*<<< orphan*/  dev_dbg (int /*<<< orphan*/ *,char*,int,...) ; 
 int /*<<< orphan*/  init_ir_raw_event (struct ir_raw_event*) ; 
 int ir_raw_gen_pd (struct ir_raw_event**,unsigned int,int /*<<< orphan*/ *,int,int) ; 
 int /*<<< orphan*/  ir_sharp_timings ; 
 int /*<<< orphan*/  rc_keydown (struct rc_dev*,int /*<<< orphan*/ ,int,int /*<<< orphan*/ ) ; 

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

__attribute__((used)) static int ir_sharp_decode(struct rc_dev *dev, struct ir_raw_event ev)
{
	struct sharp_dec *data = &dev->raw->sharp;
	u32 msg, echo, address, command, scancode;

	if (!is_timing_event(ev)) {
		if (ev.reset)
			data->state = STATE_INACTIVE;
		return 0;
	}

	dev_dbg(&dev->dev, "Sharp decode started at state %d (%uus %s)\n",
		data->state, TO_US(ev.duration), TO_STR(ev.pulse));

	switch (data->state) {

	case STATE_INACTIVE:
		if (!ev.pulse)
			break;

		if (!eq_margin(ev.duration, SHARP_BIT_PULSE,
			       SHARP_BIT_PULSE / 2))
			break;

		data->count = 0;
		data->pulse_len = ev.duration;
		data->state = STATE_BIT_SPACE;
		return 0;

	case STATE_BIT_PULSE:
		if (!ev.pulse)
			break;

		if (!eq_margin(ev.duration, SHARP_BIT_PULSE,
			       SHARP_BIT_PULSE / 2))
			break;

		data->pulse_len = ev.duration;
		data->state = STATE_BIT_SPACE;
		return 0;

	case STATE_BIT_SPACE:
		if (ev.pulse)
			break;

		data->bits <<= 1;
		if (eq_margin(data->pulse_len + ev.duration, SHARP_BIT_1_PERIOD,
			      SHARP_BIT_PULSE * 2))
			data->bits |= 1;
		else if (!eq_margin(data->pulse_len + ev.duration,
				    SHARP_BIT_0_PERIOD, SHARP_BIT_PULSE * 2))
			break;
		data->count++;

		if (data->count == SHARP_NBITS ||
		    data->count == SHARP_NBITS * 2)
			data->state = STATE_TRAILER_PULSE;
		else
			data->state = STATE_BIT_PULSE;

		return 0;

	case STATE_TRAILER_PULSE:
		if (!ev.pulse)
			break;

		if (!eq_margin(ev.duration, SHARP_BIT_PULSE,
			       SHARP_BIT_PULSE / 2))
			break;

		if (data->count == SHARP_NBITS) {
			/* exp,chk bits should be 1,0 */
			if ((data->bits & 0x3) != 0x2 &&
			/* DENON variant, both chk bits 0 */
			    (data->bits & 0x3) != 0x0)
				break;
			data->state = STATE_ECHO_SPACE;
		} else {
			data->state = STATE_TRAILER_SPACE;
		}
		return 0;

	case STATE_ECHO_SPACE:
		if (ev.pulse)
			break;

		if (!eq_margin(ev.duration, SHARP_ECHO_SPACE,
			       SHARP_ECHO_SPACE / 4))
			break;

		data->state = STATE_BIT_PULSE;

		return 0;

	case STATE_TRAILER_SPACE:
		if (ev.pulse)
			break;

		if (!geq_margin(ev.duration, SHARP_TRAILER_SPACE,
				SHARP_BIT_PULSE / 2))
			break;

		/* Validate - command, ext, chk should be inverted in 2nd */
		msg = (data->bits >> 15) & 0x7fff;
		echo = data->bits & 0x7fff;
		if ((msg ^ echo) != 0x3ff) {
			dev_dbg(&dev->dev,
				"Sharp checksum error: received 0x%04x, 0x%04x\n",
				msg, echo);
			break;
		}

		address = bitrev8((msg >> 7) & 0xf8);
		command = bitrev8((msg >> 2) & 0xff);

		scancode = address << 8 | command;
		dev_dbg(&dev->dev, "Sharp scancode 0x%04x\n", scancode);

		rc_keydown(dev, RC_PROTO_SHARP, scancode, 0);
		data->state = STATE_INACTIVE;
		return 0;
	}

	dev_dbg(&dev->dev, "Sharp decode failed at count %d state %d (%uus %s)\n",
		data->count, data->state, TO_US(ev.duration), TO_STR(ev.pulse));
	data->state = STATE_INACTIVE;
	return -EINVAL;
}

__attribute__((used)) static int ir_sharp_encode(enum rc_proto protocol, u32 scancode,
			   struct ir_raw_event *events, unsigned int max)
{
	struct ir_raw_event *e = events;
	int ret;
	u32 raw;

	raw = (((bitrev8(scancode >> 8) >> 3) << 8) & 0x1f00) |
		bitrev8(scancode);
	ret = ir_raw_gen_pd(&e, max, &ir_sharp_timings, SHARP_NBITS,
			    (raw << 2) | 2);
	if (ret < 0)
		return ret;

	max -= ret;

	raw = (((bitrev8(scancode >> 8) >> 3) << 8) & 0x1f00) |
		bitrev8(~scancode);
	ret = ir_raw_gen_pd(&e, max, &ir_sharp_timings, SHARP_NBITS,
			    (raw << 2) | 1);
	if (ret < 0)
		return ret;

	return e - events;
}

