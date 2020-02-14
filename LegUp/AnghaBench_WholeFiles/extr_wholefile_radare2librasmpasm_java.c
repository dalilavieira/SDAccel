#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_18__   TYPE_7__ ;
typedef  struct TYPE_17__   TYPE_6__ ;
typedef  struct TYPE_16__   TYPE_5__ ;
typedef  struct TYPE_15__   TYPE_4__ ;
typedef  struct TYPE_14__   TYPE_3__ ;
typedef  struct TYPE_13__   TYPE_2__ ;
typedef  struct TYPE_12__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  ut8 ;
typedef  int /*<<< orphan*/  buf_asm ;
struct TYPE_12__ {TYPE_5__* bin; } ;
struct TYPE_18__ {int /*<<< orphan*/  pc; TYPE_1__ binb; } ;
struct TYPE_17__ {int size; int /*<<< orphan*/  buf; int /*<<< orphan*/  buf_asm; } ;
struct TYPE_16__ {TYPE_3__* cur; } ;
struct TYPE_15__ {int /*<<< orphan*/  name; } ;
struct TYPE_14__ {TYPE_2__* o; } ;
struct TYPE_13__ {int /*<<< orphan*/ * bin_obj; TYPE_4__* plugin; } ;
typedef  TYPE_4__ RBinPlugin ;
typedef  int /*<<< orphan*/  RBinJavaObj ;
typedef  TYPE_5__ RBin ;
typedef  TYPE_6__ RAsmOp ;
typedef  TYPE_7__ RAsm ;

/* Variables and functions */
 int r_java_assemble (int /*<<< orphan*/ ,int /*<<< orphan*/ *,char const*) ; 
 int r_java_disasm (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/  const*,int,char*,int) ; 
 scalar_t__ r_strbuf_get (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  r_strbuf_set (int /*<<< orphan*/ *,char*) ; 
 int /*<<< orphan*/  strcmp (int /*<<< orphan*/ ,char*) ; 

__attribute__((used)) static int disassemble(RAsm *a, RAsmOp *op, const ut8 *buf, int len) {
	RBinJavaObj *obj = NULL;
	RBin *bin = a->binb.bin;
	RBinPlugin *plugin = bin && bin->cur && bin->cur->o ?
		bin->cur->o->plugin : NULL;
	if (plugin) {
		if (!strcmp (plugin->name, "java")) { // XXX slow
			obj = bin->cur->o->bin_obj; //o;
			//eprintf("Handling: %s disasm.\n", b->cur.file);
		}
	}
	char buf_asm[256];
	op->size = r_java_disasm (obj, a->pc, buf, len, buf_asm, sizeof (buf_asm));
	r_strbuf_set (&op->buf_asm, buf_asm);
	return op->size;
}

__attribute__((used)) static int assemble(RAsm *a, RAsmOp *op, const char *input) {
	// TODO: get class info from bin if possible
	// XXX wrong usage of strbuf_get here
	return op->size = r_java_assemble (a->pc, (ut8*)r_strbuf_get (&op->buf), input);
}

