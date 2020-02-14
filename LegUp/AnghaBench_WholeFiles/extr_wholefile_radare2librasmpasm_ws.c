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
typedef  int ut8 ;
typedef  int st32 ;
typedef  int /*<<< orphan*/  RAsmOp ;
typedef  int /*<<< orphan*/  RAsm ;

/* Variables and functions */
 int WS_OP_ARITH ; 
 int WS_OP_FLOW ; 
 int WS_OP_HEAP ; 
 int WS_OP_IO ; 
 int WS_OP_NOP ; 
 int WS_OP_PREF ; 
 int WS_OP_STACK ; 
 int WS_OP_UNK ; 
 int* get_ws_next_token (int const*,int) ; 
 int wsdis (int /*<<< orphan*/ *,int const*,int) ; 

__attribute__((used)) static int get_ws_pref_optype(const ut8 *buf, int len) {
	if (len < 1) {
		return WS_OP_UNK;
	}
	switch (buf[0]) {
	case ' ': return WS_OP_STACK;
	case '\t': return WS_OP_PREF;
	case 10: return WS_OP_FLOW;
	default: return WS_OP_NOP;
	}
}

__attribute__((used)) static int get_ws_suf_optype(const ut8 *buf, int len) {
	if (len < 1) {
		return WS_OP_UNK;
	}
	switch (buf[0]) {
	case ' ': return WS_OP_ARITH;
	case '\t': return WS_OP_HEAP;
	case 10: return WS_OP_IO;
	default: return WS_OP_NOP;
	}
}

__attribute__((used)) static st32 get_ws_val(const ut8 *buf, int len) {
	ut8 sig;
	int i, ret = 0;
	const ut8 *tok = get_ws_next_token (buf, len);
	sig = (*tok == '\t');
	len -= (tok - buf) + 1;
	for (i = 0; i < 30; i++) { // XXX : conceptually wrong
		tok++;
		tok = get_ws_next_token (tok, len);
		if (!tok || *tok == 10) {
			if (sig) {
				return ret * (-1);
			}
			return ret;
		}
		ret = (ret << 1);
		ret = ret + (*tok == '\t');
		len = len - (tok - buf) - 1;
	}
	return sig? ret * (-1): ret;
}

__attribute__((used)) static int disassemble(RAsm *a, RAsmOp *op, const ut8 *buf, int len) {
	return wsdis (op, buf, len);
}

