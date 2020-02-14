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
typedef  int u8 ;
typedef  int u32 ;
struct rc_dev {char* device_name; TYPE_1__* raw; int /*<<< orphan*/  input_phys; int /*<<< orphan*/  dev; } ;
struct lirc_scancode {int scancode; int /*<<< orphan*/  rc_proto; } ;
struct ir_raw_event {scalar_t__ pulse; unsigned int duration; scalar_t__ reset; int /*<<< orphan*/  carrier_report; } ;
struct input_dev {int /*<<< orphan*/  mscbit; int /*<<< orphan*/  evbit; int /*<<< orphan*/  keybit; int /*<<< orphan*/  relbit; int /*<<< orphan*/  phys; int /*<<< orphan*/  name; } ;
struct imon_dec {int bits; int stick_keyboard; int state; int count; unsigned int last_chk; struct input_dev* idev; int /*<<< orphan*/  name; } ;
typedef  enum rc_proto { ____Placeholder_rc_proto } rc_proto ;
struct TYPE_2__ {struct imon_dec imon; } ;

/* Variables and functions */
 int BIT (int) ; 
 int /*<<< orphan*/  BTN_LEFT ; 
 int /*<<< orphan*/  BTN_RIGHT ; 
 int EINVAL ; 
 int EIO ; 
 int ENOBUFS ; 
 int ENOMEM ; 
 int /*<<< orphan*/  EV_KEY ; 
 int /*<<< orphan*/  EV_MSC ; 
 int /*<<< orphan*/  EV_REL ; 
 void* IMON_BITS ; 
 int IMON_CHKBITS ; 
 int IMON_UNIT ; 
 int /*<<< orphan*/  MSC_SCAN ; 
 scalar_t__ MS_TO_NS (int) ; 
 int /*<<< orphan*/  RC_PROTO_IMON ; 
 int /*<<< orphan*/  REL_X ; 
 int /*<<< orphan*/  REL_Y ; 
#define  STATE_BIT_CHK 131 
#define  STATE_BIT_START 130 
 int STATE_ERROR ; 
#define  STATE_FINISHED 129 
#define  STATE_INACTIVE 128 
 int /*<<< orphan*/  TO_STR (unsigned int) ; 
 int /*<<< orphan*/  TO_US (int) ; 
 scalar_t__ abs (int) ; 
 int /*<<< orphan*/  dev_dbg (int /*<<< orphan*/ *,char*,int,int,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  init_ir_raw_event (struct ir_raw_event*) ; 
 struct input_dev* input_allocate_device () ; 
 int /*<<< orphan*/  input_event (struct input_dev*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  input_free_device (struct input_dev*) ; 
 int input_register_device (struct input_dev*) ; 
 int /*<<< orphan*/  input_report_key (struct input_dev*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  input_report_rel (struct input_dev*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  input_set_drvdata (struct input_dev*,struct imon_dec*) ; 
 int /*<<< orphan*/  input_sync (struct input_dev*) ; 
 int /*<<< orphan*/  input_unregister_device (struct input_dev*) ; 
 int /*<<< orphan*/  rc_keydown (struct rc_dev*,int /*<<< orphan*/ ,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  set_bit (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  snprintf (int /*<<< orphan*/ ,int,char*,char*) ; 

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

__attribute__((used)) static void ir_imon_decode_scancode(struct rc_dev *dev)
{
	struct imon_dec *imon = &dev->raw->imon;

	/* Keyboard/Mouse toggle */
	if (imon->bits == 0x299115b7)
		imon->stick_keyboard = !imon->stick_keyboard;

	if ((imon->bits & 0xfc0000ff) == 0x680000b7) {
		int rel_x, rel_y;
		u8 buf;

		buf = imon->bits >> 16;
		rel_x = (buf & 0x08) | (buf & 0x10) >> 2 |
			(buf & 0x20) >> 4 | (buf & 0x40) >> 6;
		if (imon->bits & 0x02000000)
			rel_x |= ~0x0f;
		buf = imon->bits >> 8;
		rel_y = (buf & 0x08) | (buf & 0x10) >> 2 |
			(buf & 0x20) >> 4 | (buf & 0x40) >> 6;
		if (imon->bits & 0x01000000)
			rel_y |= ~0x0f;

		if (rel_x && rel_y && imon->stick_keyboard) {
			if (abs(rel_y) > abs(rel_x))
				imon->bits = rel_y > 0 ?
					0x289515b7 : /* KEY_DOWN */
					0x2aa515b7;  /* KEY_UP */
			else
				imon->bits = rel_x > 0 ?
					0x2ba515b7 : /* KEY_RIGHT */
					0x29a515b7;  /* KEY_LEFT */
		}

		if (!imon->stick_keyboard) {
			struct lirc_scancode lsc = {
				.scancode = imon->bits,
				.rc_proto = RC_PROTO_IMON,
			};

			ir_lirc_scancode_event(dev, &lsc);

			input_event(imon->idev, EV_MSC, MSC_SCAN, imon->bits);

			input_report_rel(imon->idev, REL_X, rel_x);
			input_report_rel(imon->idev, REL_Y, rel_y);

			input_report_key(imon->idev, BTN_LEFT,
					 (imon->bits & 0x00010000) != 0);
			input_report_key(imon->idev, BTN_RIGHT,
					 (imon->bits & 0x00040000) != 0);
			input_sync(imon->idev);
			return;
		}
	}

	rc_keydown(dev, RC_PROTO_IMON, imon->bits, 0);
}

__attribute__((used)) static int ir_imon_decode(struct rc_dev *dev, struct ir_raw_event ev)
{
	struct imon_dec *data = &dev->raw->imon;

	if (!is_timing_event(ev)) {
		if (ev.reset)
			data->state = STATE_INACTIVE;
		return 0;
	}

	dev_dbg(&dev->dev,
		"iMON decode started at state %d bitno %d (%uus %s)\n",
		data->state, data->count, TO_US(ev.duration),
		TO_STR(ev.pulse));

	/*
	 * Since iMON protocol is a series of bits, if at any point
	 * we encounter an error, make sure that any remaining bits
	 * aren't parsed as a scancode made up of less bits.
	 *
	 * Note that if the stick is held, then the remote repeats
	 * the scancode with about 12ms between them. So, make sure
	 * we have at least 10ms of space after an error. That way,
	 * we're at a new scancode.
	 */
	if (data->state == STATE_ERROR) {
		if (!ev.pulse && ev.duration > MS_TO_NS(10))
			data->state = STATE_INACTIVE;
		return 0;
	}

	for (;;) {
		if (!geq_margin(ev.duration, IMON_UNIT, IMON_UNIT / 2))
			return 0;

		decrease_duration(&ev, IMON_UNIT);

		switch (data->state) {
		case STATE_INACTIVE:
			if (ev.pulse) {
				data->state = STATE_BIT_CHK;
				data->bits = 0;
				data->count = IMON_BITS;
			}
			break;
		case STATE_BIT_CHK:
			if (IMON_CHKBITS & BIT(data->count))
				data->last_chk = ev.pulse;
			else if (ev.pulse)
				goto err_out;
			data->state = STATE_BIT_START;
			break;
		case STATE_BIT_START:
			data->bits <<= 1;
			if (!ev.pulse)
				data->bits |= 1;

			if (IMON_CHKBITS & BIT(data->count)) {
				if (data->last_chk != !(data->bits & 3))
					goto err_out;
			}

			if (!data->count--)
				data->state = STATE_FINISHED;
			else
				data->state = STATE_BIT_CHK;
			break;
		case STATE_FINISHED:
			if (ev.pulse)
				goto err_out;
			ir_imon_decode_scancode(dev);
			data->state = STATE_INACTIVE;
			break;
		}
	}

err_out:
	dev_dbg(&dev->dev,
		"iMON decode failed at state %d bitno %d (%uus %s)\n",
		data->state, data->count, TO_US(ev.duration),
		TO_STR(ev.pulse));

	data->state = STATE_ERROR;

	return -EINVAL;
}

__attribute__((used)) static int ir_imon_encode(enum rc_proto protocol, u32 scancode,
			  struct ir_raw_event *events, unsigned int max)
{
	struct ir_raw_event *e = events;
	int i, pulse;

	if (!max--)
		return -ENOBUFS;
	init_ir_raw_event_duration(e, 1, IMON_UNIT);

	for (i = IMON_BITS; i >= 0; i--) {
		if (BIT(i) & IMON_CHKBITS)
			pulse = !(scancode & (BIT(i) | BIT(i + 1)));
		else
			pulse = 0;

		if (pulse == e->pulse) {
			e->duration += IMON_UNIT;
		} else {
			if (!max--)
				return -ENOBUFS;
			init_ir_raw_event_duration(++e, pulse, IMON_UNIT);
		}

		pulse = !(scancode & BIT(i));

		if (pulse == e->pulse) {
			e->duration += IMON_UNIT;
		} else {
			if (!max--)
				return -ENOBUFS;
			init_ir_raw_event_duration(++e, pulse, IMON_UNIT);
		}
	}

	if (e->pulse)
		e++;

	return e - events;
}

__attribute__((used)) static int ir_imon_register(struct rc_dev *dev)
{
	struct input_dev *idev;
	struct imon_dec *imon = &dev->raw->imon;
	int ret;

	idev = input_allocate_device();
	if (!idev)
		return -ENOMEM;

	snprintf(imon->name, sizeof(imon->name),
		 "iMON PAD Stick (%s)", dev->device_name);
	idev->name = imon->name;
	idev->phys = dev->input_phys;

	/* Mouse bits */
	set_bit(EV_REL, idev->evbit);
	set_bit(EV_KEY, idev->evbit);
	set_bit(REL_X, idev->relbit);
	set_bit(REL_Y, idev->relbit);
	set_bit(BTN_LEFT, idev->keybit);
	set_bit(BTN_RIGHT, idev->keybit);

	/* Report scancodes too */
	set_bit(EV_MSC, idev->evbit);
	set_bit(MSC_SCAN, idev->mscbit);

	input_set_drvdata(idev, imon);

	ret = input_register_device(idev);
	if (ret < 0) {
		input_free_device(idev);
		return -EIO;
	}

	imon->idev = idev;
	imon->stick_keyboard = false;

	return 0;
}

__attribute__((used)) static int ir_imon_unregister(struct rc_dev *dev)
{
	struct imon_dec *imon = &dev->raw->imon;

	input_unregister_device(imon->idev);
	imon->idev = NULL;

	return 0;
}

