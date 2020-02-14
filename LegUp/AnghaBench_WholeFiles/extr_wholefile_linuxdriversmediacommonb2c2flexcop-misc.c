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
struct flexcop_device {size_t rev; size_t dev_type; size_t bus_type; TYPE_2__ (* read_ibi_reg ) (struct flexcop_device*,scalar_t__) ;int /*<<< orphan*/  has_32_hw_pid_filter; } ;
struct TYPE_5__ {int Rev_N_sig_revision_hi; int /*<<< orphan*/  Rev_N_sig_caps; } ;
struct TYPE_6__ {int /*<<< orphan*/  raw; TYPE_1__ misc_204; } ;
typedef  TYPE_2__ flexcop_ibi_value ;
typedef  scalar_t__ flexcop_ibi_register ;

/* Variables and functions */
 size_t FLEXCOP_II ; 
 size_t FLEXCOP_IIB ; 
 size_t FLEXCOP_III ; 
 int /*<<< orphan*/  deb_info (char*) ; 
 int /*<<< orphan*/  deb_rdump (char*,...) ; 
 int /*<<< orphan*/  err (char*,int) ; 
 int /*<<< orphan*/ * flexcop_bus_names ; 
 int /*<<< orphan*/ * flexcop_device_names ; 
 int /*<<< orphan*/ * flexcop_revision_names ; 
 int /*<<< orphan*/  info (char*,char const*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,char const*) ; 
 scalar_t__ misc_204 ; 
 TYPE_2__ stub1 (struct flexcop_device*,scalar_t__) ; 
 TYPE_2__ stub2 (struct flexcop_device*,scalar_t__) ; 

void flexcop_determine_revision(struct flexcop_device *fc)
{
	flexcop_ibi_value v = fc->read_ibi_reg(fc,misc_204);

	switch (v.misc_204.Rev_N_sig_revision_hi) {
	case 0x2:
		deb_info("found a FlexCopII.\n");
		fc->rev = FLEXCOP_II;
		break;
	case 0x3:
		deb_info("found a FlexCopIIb.\n");
		fc->rev = FLEXCOP_IIB;
		break;
	case 0x0:
		deb_info("found a FlexCopIII.\n");
		fc->rev = FLEXCOP_III;
		break;
	default:
		err("unknown FlexCop Revision: %x. Please report this to linux-dvb@linuxtv.org.",
				v.misc_204.Rev_N_sig_revision_hi);
		break;
	}

	if ((fc->has_32_hw_pid_filter = v.misc_204.Rev_N_sig_caps))
		deb_info("this FlexCop has the additional 32 hardware pid filter.\n");
	else
		deb_info("this FlexCop has the 6 basic main hardware pid filter.\n");
	/* bus parts have to decide if hw pid filtering is used or not. */
}

void flexcop_device_name(struct flexcop_device *fc,
		const char *prefix, const char *suffix)
{
	info("%s '%s' at the '%s' bus controlled by a '%s' %s",
			prefix,	flexcop_device_names[fc->dev_type],
			flexcop_bus_names[fc->bus_type],
			flexcop_revision_names[fc->rev], suffix);
}

void flexcop_dump_reg(struct flexcop_device *fc,
		flexcop_ibi_register reg, int num)
{
	flexcop_ibi_value v;
	int i;
	for (i = 0; i < num; i++) {
		v = fc->read_ibi_reg(fc, reg+4*i);
		deb_rdump("0x%03x: %08x, ", reg+4*i, v.raw);
	}
	deb_rdump("\n");
}

