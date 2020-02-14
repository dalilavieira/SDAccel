#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_8__   TYPE_2__ ;
typedef  struct TYPE_7__   TYPE_1__ ;

/* Type definitions */
struct flexcop_device {int rev; int /*<<< orphan*/  (* write_ibi_reg ) (struct flexcop_device*,int /*<<< orphan*/ ,TYPE_2__) ;TYPE_2__ (* read_ibi_reg ) (struct flexcop_device*,int /*<<< orphan*/ ) ;} ;
typedef  int /*<<< orphan*/  flexcop_wan_speed_t ;
typedef  int /*<<< orphan*/  flexcop_sram_type_t ;
typedef  scalar_t__ flexcop_sram_dest_target_t ;
typedef  int flexcop_sram_dest_t ;
struct TYPE_7__ {int ctrl_usb_wan; int ctrl_sramdma; int ctrl_maximumfill; scalar_t__ MEDIA_Dest; scalar_t__ CAO_Dest; scalar_t__ CAI_Dest; scalar_t__ NET_Dest; } ;
struct TYPE_8__ {TYPE_1__ sram_dest_reg_714; } ;
typedef  TYPE_2__ flexcop_ibi_value ;

/* Variables and functions */
 int EINVAL ; 
 int /*<<< orphan*/  FC_SRAM_1_32KB ; 
 int /*<<< orphan*/  FC_SRAM_1_48KB ; 
 int FC_SRAM_DEST_CAI ; 
 int FC_SRAM_DEST_CAO ; 
 int FC_SRAM_DEST_MEDIA ; 
 int FC_SRAM_DEST_NET ; 
 scalar_t__ FC_SRAM_DEST_TARGET_FC3_CA ; 
#define  FLEXCOP_II 130 
#define  FLEXCOP_IIB 129 
#define  FLEXCOP_III 128 
 int /*<<< orphan*/  deb_sram (char*,int,scalar_t__) ; 
 int /*<<< orphan*/  err (char*) ; 
 int /*<<< orphan*/  flexcop_set_ibi_value (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  sram_chip ; 
 int /*<<< orphan*/  sram_dest_reg_714 ; 
 TYPE_2__ stub1 (struct flexcop_device*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  stub2 (struct flexcop_device*,int /*<<< orphan*/ ,TYPE_2__) ; 
 TYPE_2__ stub3 (struct flexcop_device*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  stub4 (struct flexcop_device*,int /*<<< orphan*/ ,TYPE_2__) ; 
 int /*<<< orphan*/  udelay (int) ; 
 int /*<<< orphan*/  wan_ctrl_reg_71c ; 
 int /*<<< orphan*/  wan_speed_sig ; 

__attribute__((used)) static void flexcop_sram_set_chip(struct flexcop_device *fc,
		flexcop_sram_type_t type)
{
	flexcop_set_ibi_value(wan_ctrl_reg_71c, sram_chip, type);
}

int flexcop_sram_init(struct flexcop_device *fc)
{
	switch (fc->rev) {
	case FLEXCOP_II:
	case FLEXCOP_IIB:
		flexcop_sram_set_chip(fc, FC_SRAM_1_32KB);
		break;
	case FLEXCOP_III:
		flexcop_sram_set_chip(fc, FC_SRAM_1_48KB);
		break;
	default:
		return -EINVAL;
	}
	return 0;
}

int flexcop_sram_set_dest(struct flexcop_device *fc, flexcop_sram_dest_t dest,
		 flexcop_sram_dest_target_t target)
{
	flexcop_ibi_value v;
	v = fc->read_ibi_reg(fc, sram_dest_reg_714);

	if (fc->rev != FLEXCOP_III && target == FC_SRAM_DEST_TARGET_FC3_CA) {
		err("SRAM destination target to available on FlexCopII(b)\n");
		return -EINVAL;
	}
	deb_sram("sram dest: %x target: %x\n", dest, target);

	if (dest & FC_SRAM_DEST_NET)
		v.sram_dest_reg_714.NET_Dest = target;
	if (dest & FC_SRAM_DEST_CAI)
		v.sram_dest_reg_714.CAI_Dest = target;
	if (dest & FC_SRAM_DEST_CAO)
		v.sram_dest_reg_714.CAO_Dest = target;
	if (dest & FC_SRAM_DEST_MEDIA)
		v.sram_dest_reg_714.MEDIA_Dest = target;

	fc->write_ibi_reg(fc,sram_dest_reg_714,v);
	udelay(1000); /* TODO delay really necessary */

	return 0;
}

void flexcop_wan_set_speed(struct flexcop_device *fc, flexcop_wan_speed_t s)
{
	flexcop_set_ibi_value(wan_ctrl_reg_71c,wan_speed_sig,s);
}

void flexcop_sram_ctrl(struct flexcop_device *fc, int usb_wan, int sramdma, int maximumfill)
{
	flexcop_ibi_value v = fc->read_ibi_reg(fc,sram_dest_reg_714);
	v.sram_dest_reg_714.ctrl_usb_wan = usb_wan;
	v.sram_dest_reg_714.ctrl_sramdma = sramdma;
	v.sram_dest_reg_714.ctrl_maximumfill = maximumfill;
	fc->write_ibi_reg(fc,sram_dest_reg_714,v);
}

