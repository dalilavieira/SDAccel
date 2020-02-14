#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_6__   TYPE_2__ ;
typedef  struct TYPE_5__   TYPE_1__ ;

/* Type definitions */
typedef  scalar_t__ ut64 ;
struct TYPE_6__ {scalar_t__ baddr_shift; } ;
struct TYPE_5__ {int (* get_offset ) (int /*<<< orphan*/ *,int,int) ;char const* (* get_name ) (int /*<<< orphan*/ *,int,int) ;} ;
typedef  TYPE_1__ RBinPlugin ;
typedef  TYPE_2__ RBinObject ;
typedef  int /*<<< orphan*/  RBinFile ;
typedef  int /*<<< orphan*/  RBin ;

/* Variables and functions */
 int /*<<< orphan*/ * r_bin_cur (int /*<<< orphan*/ *) ; 
 TYPE_1__* r_bin_file_cur_plugin (int /*<<< orphan*/ *) ; 
 int stub1 (int /*<<< orphan*/ *,int,int) ; 
 char const* stub2 (int /*<<< orphan*/ *,int,int) ; 

__attribute__((used)) static int getoffset(RBin *bin, int type, int idx) {
	RBinFile *a = r_bin_cur (bin);
	RBinPlugin *plugin = r_bin_file_cur_plugin (a);
	if (plugin && plugin->get_offset) {
		return plugin->get_offset (a, type, idx);
	}
	return -1;
}

__attribute__((used)) static const char *getname(RBin *bin, int type, int idx) {
	RBinFile *a = r_bin_cur (bin);
	RBinPlugin *plugin = r_bin_file_cur_plugin (a);
	if (plugin && plugin->get_name) {
		return plugin->get_name (a, type, idx);
	}
	return NULL;
}

__attribute__((used)) static ut64 binobj_a2b(RBinObject *o, ut64 addr) {
	return o ? addr + o->baddr_shift : addr;
}

