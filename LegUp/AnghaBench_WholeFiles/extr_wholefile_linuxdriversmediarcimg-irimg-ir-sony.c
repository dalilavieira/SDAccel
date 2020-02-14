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
typedef  int u64 ;
typedef  int /*<<< orphan*/  u32 ;
struct rc_scancode_filter {int data; int mask; } ;
struct img_ir_scancode_req {unsigned int scancode; int /*<<< orphan*/  protocol; } ;
struct img_ir_priv_hw {int dummy; } ;
struct img_ir_priv {int dummy; } ;
struct img_ir_filter {unsigned int data; unsigned int mask; unsigned int minlen; unsigned int maxlen; } ;

/* Variables and functions */
 int EINVAL ; 
 int ENODEV ; 
 int IMG_IR_SCANCODE ; 
 int RC_PROTO_BIT_SONY12 ; 
 int RC_PROTO_BIT_SONY15 ; 
 int RC_PROTO_BIT_SONY20 ; 
 int /*<<< orphan*/  RC_PROTO_SONY12 ; 
 int /*<<< orphan*/  RC_PROTO_SONY15 ; 
 int /*<<< orphan*/  RC_PROTO_SONY20 ; 
 int /*<<< orphan*/  is_power_of_2 (int) ; 

__attribute__((used)) static inline bool img_ir_hw_enabled(struct img_ir_priv_hw *hw)
{
	return false;
}

__attribute__((used)) static inline void img_ir_isr_hw(struct img_ir_priv *priv, u32 irq_status)
{
}

__attribute__((used)) static inline void img_ir_setup_hw(struct img_ir_priv *priv)
{
}

__attribute__((used)) static inline int img_ir_probe_hw(struct img_ir_priv *priv)
{
	return -ENODEV;
}

__attribute__((used)) static inline void img_ir_remove_hw(struct img_ir_priv *priv)
{
}

__attribute__((used)) static int img_ir_sony_scancode(int len, u64 raw, u64 enabled_protocols,
				struct img_ir_scancode_req *request)
{
	unsigned int dev, subdev, func;

	switch (len) {
	case 12:
		if (!(enabled_protocols & RC_PROTO_BIT_SONY12))
			return -EINVAL;
		func   = raw & 0x7f;	/* first 7 bits */
		raw    >>= 7;
		dev    = raw & 0x1f;	/* next 5 bits */
		subdev = 0;
		request->protocol = RC_PROTO_SONY12;
		break;
	case 15:
		if (!(enabled_protocols & RC_PROTO_BIT_SONY15))
			return -EINVAL;
		func   = raw & 0x7f;	/* first 7 bits */
		raw    >>= 7;
		dev    = raw & 0xff;	/* next 8 bits */
		subdev = 0;
		request->protocol = RC_PROTO_SONY15;
		break;
	case 20:
		if (!(enabled_protocols & RC_PROTO_BIT_SONY20))
			return -EINVAL;
		func   = raw & 0x7f;	/* first 7 bits */
		raw    >>= 7;
		dev    = raw & 0x1f;	/* next 5 bits */
		raw    >>= 5;
		subdev = raw & 0xff;	/* next 8 bits */
		request->protocol = RC_PROTO_SONY20;
		break;
	default:
		return -EINVAL;
	}
	request->scancode = dev << 16 | subdev << 8 | func;
	return IMG_IR_SCANCODE;
}

__attribute__((used)) static int img_ir_sony_filter(const struct rc_scancode_filter *in,
			      struct img_ir_filter *out, u64 protocols)
{
	unsigned int dev, subdev, func;
	unsigned int dev_m, subdev_m, func_m;
	unsigned int len = 0;

	dev      = (in->data >> 16) & 0xff;
	dev_m    = (in->mask >> 16) & 0xff;
	subdev   = (in->data >> 8)  & 0xff;
	subdev_m = (in->mask >> 8)  & 0xff;
	func     = (in->data >> 0)  & 0x7f;
	func_m   = (in->mask >> 0)  & 0x7f;

	protocols &= RC_PROTO_BIT_SONY12 | RC_PROTO_BIT_SONY15 |
							RC_PROTO_BIT_SONY20;

	/*
	 * If only one bit is set, we were requested to do an exact
	 * protocol. This should be the case for wakeup filters; for
	 * normal filters, guess the protocol from the scancode.
	 */
	if (!is_power_of_2(protocols)) {
		if (subdev & subdev_m)
			protocols = RC_PROTO_BIT_SONY20;
		else if (dev & dev_m & 0xe0)
			protocols = RC_PROTO_BIT_SONY15;
		else
			protocols = RC_PROTO_BIT_SONY12;
	}

	if (protocols == RC_PROTO_BIT_SONY20) {
		/* can't encode subdev and higher device bits */
		if (dev & dev_m & 0xe0)
			return -EINVAL;
		len = 20;
		dev_m &= 0x1f;
	} else if (protocols == RC_PROTO_BIT_SONY15) {
		len = 15;
		subdev_m = 0;
	} else {
		/*
		 * The hardware mask cannot distinguish high device bits and low
		 * extended bits, so logically AND those bits of the masks
		 * together.
		 */
		subdev_m &= (dev_m >> 5) | 0xf8;
		dev_m &= 0x1f;
	}

	/* ensure there aren't any bits straying between fields */
	dev &= dev_m;
	subdev &= subdev_m;

	/* write the hardware filter */
	out->data = func          |
		    dev      << 7 |
		    subdev   << 15;
	out->mask = func_m        |
		    dev_m    << 7 |
		    subdev_m << 15;

	if (len) {
		out->minlen = len;
		out->maxlen = len;
	}
	return 0;
}

