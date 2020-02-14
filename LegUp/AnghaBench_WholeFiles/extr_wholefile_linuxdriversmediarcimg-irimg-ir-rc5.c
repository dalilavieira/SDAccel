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
struct rc_scancode_filter {int dummy; } ;
struct img_ir_scancode_req {unsigned int scancode; unsigned int toggle; int /*<<< orphan*/  protocol; } ;
struct img_ir_priv_hw {int dummy; } ;
struct img_ir_priv {int dummy; } ;
struct img_ir_filter {int dummy; } ;

/* Variables and functions */
 int EINVAL ; 
 int ENODEV ; 
 int IMG_IR_SCANCODE ; 
 int /*<<< orphan*/  RC_PROTO_RC5 ; 

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

__attribute__((used)) static int img_ir_rc5_scancode(int len, u64 raw, u64 enabled_protocols,
				struct img_ir_scancode_req *request)
{
	unsigned int addr, cmd, tgl, start;

	/* Quirk in the decoder shifts everything by 2 to the left. */
	raw   >>= 2;

	start	=  (raw >> 13)	& 0x01;
	tgl	=  (raw >> 11)	& 0x01;
	addr	=  (raw >>  6)	& 0x1f;
	cmd	=   raw		& 0x3f;
	/*
	 * 12th bit is used to extend the command in extended RC5 and has
	 * no effect on standard RC5.
	 */
	cmd	+= ((raw >> 12) & 0x01) ? 0 : 0x40;

	if (!start)
		return -EINVAL;

	request->protocol = RC_PROTO_RC5;
	request->scancode = addr << 8 | cmd;
	request->toggle   = tgl;
	return IMG_IR_SCANCODE;
}

__attribute__((used)) static int img_ir_rc5_filter(const struct rc_scancode_filter *in,
				 struct img_ir_filter *out, u64 protocols)
{
	/* Not supported by the hw. */
	return -EINVAL;
}

