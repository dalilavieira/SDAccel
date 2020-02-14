#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
typedef  unsigned char ut8 ;
typedef  int /*<<< orphan*/  ut64 ;
struct state {unsigned char const* s_buf; int /*<<< orphan*/ * s_out; int /*<<< orphan*/  s_off; } ;
struct r_asm_op_t {int size; int /*<<< orphan*/  buf_asm; } ;
struct directive {int /*<<< orphan*/  d_asm; } ;
struct TYPE_3__ {int /*<<< orphan*/  pc; } ;
typedef  TYPE_1__ RAsm ;

/* Variables and functions */
 int /*<<< orphan*/  free (struct directive*) ; 
 struct state* get_state () ; 
 int /*<<< orphan*/  memset (struct state*,int /*<<< orphan*/ ,int) ; 
 struct directive* next_inst (struct state*) ; 
 char* r_strbuf_get (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  strcpy (char*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  xap_decode (struct state*,struct directive*) ; 

__attribute__((used)) static int arch_xap_disasm(char *str, const unsigned char *buf, ut64 seek) {
	struct state *s = get_state();
	struct directive *d;
	memset(s, 0, sizeof(*s));
	s->s_buf = buf;
	s->s_off = seek;
	s->s_out = NULL;
	d = next_inst(s);
	if (d != NULL) {
		xap_decode (s, d);
		strcpy (str, d->d_asm);
		free (d);
	} else {
		*str = '\0';
	}
#if 0
	if (s->s_ff_quirk) {
		sprintf(d->d_asm, "DC\t0x%x", i2u16(&d->d_inst));
		s->s_ff_quirk = 0;
	}
#endif
	return 0;
}

__attribute__((used)) static int disassemble(RAsm *a, struct r_asm_op_t *op, const ut8 *buf, int len) {
	char *buf_asm = r_strbuf_get (&op->buf_asm);
	arch_xap_disasm (buf_asm, buf, a->pc);
	return (op->size = 2);
}

