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
 int /*<<< orphan*/  RC_PROTO_JVC ; 

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

__attribute__((used)) static int img_ir_jvc_scancode(int len, u64 raw, u64 enabled_protocols,
			       struct img_ir_scancode_req *request)
{
	unsigned int cust, data;

	if (len != 16)
		return -EINVAL;

	cust = (raw >> 0) & 0xff;
	data = (raw >> 8) & 0xff;

	request->protocol = RC_PROTO_JVC;
	request->scancode = cust << 8 | data;
	return IMG_IR_SCANCODE;
}

__attribute__((used)) static int img_ir_jvc_filter(const struct rc_scancode_filter *in,
			     struct img_ir_filter *out, u64 protocols)
{
	unsigned int cust, data;
	unsigned int cust_m, data_m;

	cust   = (in->data >> 8) & 0xff;
	cust_m = (in->mask >> 8) & 0xff;
	data   = (in->data >> 0) & 0xff;
	data_m = (in->mask >> 0) & 0xff;

	out->data = cust   | data << 8;
	out->mask = cust_m | data_m << 8;

	return 0;
}

