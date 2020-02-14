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
struct img_ir_filter {int data; int mask; } ;

/* Variables and functions */
 int EINVAL ; 
 int ENODEV ; 
 int IMG_IR_REPEATCODE ; 
 int IMG_IR_SCANCODE ; 
 int /*<<< orphan*/  RC_PROTO_SANYO ; 

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

__attribute__((used)) static int img_ir_sanyo_scancode(int len, u64 raw, u64 enabled_protocols,
				 struct img_ir_scancode_req *request)
{
	unsigned int addr, addr_inv, data, data_inv;
	/* a repeat code has no data */
	if (!len)
		return IMG_IR_REPEATCODE;
	if (len != 42)
		return -EINVAL;
	addr     = (raw >>  0) & 0x1fff;
	addr_inv = (raw >> 13) & 0x1fff;
	data     = (raw >> 26) & 0xff;
	data_inv = (raw >> 34) & 0xff;
	/* Validate data */
	if ((data_inv ^ data) != 0xff)
		return -EINVAL;
	/* Validate address */
	if ((addr_inv ^ addr) != 0x1fff)
		return -EINVAL;

	/* Normal Sanyo */
	request->protocol = RC_PROTO_SANYO;
	request->scancode = addr << 8 | data;
	return IMG_IR_SCANCODE;
}

__attribute__((used)) static int img_ir_sanyo_filter(const struct rc_scancode_filter *in,
			       struct img_ir_filter *out, u64 protocols)
{
	unsigned int addr, addr_inv, data, data_inv;
	unsigned int addr_m, data_m;

	data = in->data & 0xff;
	data_m = in->mask & 0xff;
	data_inv = data ^ 0xff;

	if (in->data & 0xff700000)
		return -EINVAL;

	addr       = (in->data >> 8) & 0x1fff;
	addr_m     = (in->mask >> 8) & 0x1fff;
	addr_inv   = addr ^ 0x1fff;

	out->data = (u64)data_inv << 34 |
		    (u64)data     << 26 |
			 addr_inv << 13 |
			 addr;
	out->mask = (u64)data_m << 34 |
		    (u64)data_m << 26 |
			 addr_m << 13 |
			 addr_m;
	return 0;
}

