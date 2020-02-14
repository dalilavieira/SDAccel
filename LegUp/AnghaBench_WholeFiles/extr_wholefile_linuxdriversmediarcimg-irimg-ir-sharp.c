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
struct img_ir_filter {unsigned int data; unsigned int mask; } ;

/* Variables and functions */
 int EINVAL ; 
 int ENODEV ; 
 int IMG_IR_SCANCODE ; 
 int /*<<< orphan*/  RC_PROTO_SHARP ; 

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

__attribute__((used)) static int img_ir_sharp_scancode(int len, u64 raw, u64 enabled_protocols,
				 struct img_ir_scancode_req *request)
{
	unsigned int addr, cmd, exp, chk;

	if (len != 15)
		return -EINVAL;

	addr = (raw >>   0) & 0x1f;
	cmd  = (raw >>   5) & 0xff;
	exp  = (raw >>  13) &  0x1;
	chk  = (raw >>  14) &  0x1;

	/* validate data */
	if (!exp)
		return -EINVAL;
	if (chk)
		/* probably the second half of the message */
		return -EINVAL;

	request->protocol = RC_PROTO_SHARP;
	request->scancode = addr << 8 | cmd;
	return IMG_IR_SCANCODE;
}

__attribute__((used)) static int img_ir_sharp_filter(const struct rc_scancode_filter *in,
			       struct img_ir_filter *out, u64 protocols)
{
	unsigned int addr, cmd, exp = 0, chk = 0;
	unsigned int addr_m, cmd_m, exp_m = 0, chk_m = 0;

	addr   = (in->data >> 8) & 0x1f;
	addr_m = (in->mask >> 8) & 0x1f;
	cmd    = (in->data >> 0) & 0xff;
	cmd_m  = (in->mask >> 0) & 0xff;
	if (cmd_m) {
		/* if filtering commands, we can only match the first part */
		exp   = 1;
		exp_m = 1;
		chk   = 0;
		chk_m = 1;
	}

	out->data = addr        |
		    cmd   <<  5 |
		    exp   << 13 |
		    chk   << 14;
	out->mask = addr_m      |
		    cmd_m <<  5 |
		    exp_m << 13 |
		    chk_m << 14;

	return 0;
}

