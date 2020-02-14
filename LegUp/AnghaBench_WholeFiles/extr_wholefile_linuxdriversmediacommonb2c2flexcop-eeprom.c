#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
typedef  scalar_t__ u8 ;
typedef  int u16 ;
struct TYPE_2__ {int /*<<< orphan*/  proposed_mac; } ;
struct flexcop_device {int (* i2c_request ) (int /*<<< orphan*/ *,int /*<<< orphan*/ ,scalar_t__,int,scalar_t__*,int) ;TYPE_1__ dvb_adapter; int /*<<< orphan*/ * fc_i2c_adap; } ;
typedef  int /*<<< orphan*/  flexcop_access_op_t ;

/* Variables and functions */
 int EINVAL ; 
 int /*<<< orphan*/  FC_READ ; 
 int /*<<< orphan*/  err (char*) ; 
 int /*<<< orphan*/  memcpy (int /*<<< orphan*/ ,scalar_t__*,int) ; 
 int stub1 (int /*<<< orphan*/ *,int /*<<< orphan*/ ,scalar_t__,int,scalar_t__*,int) ; 

__attribute__((used)) static u8 calc_lrc(u8 *buf, int len)
{
	int i;
	u8 sum = 0;
	for (i = 0; i < len; i++)
		sum = sum ^ buf[i];
	return sum;
}

__attribute__((used)) static int flexcop_eeprom_request(struct flexcop_device *fc,
	flexcop_access_op_t op, u16 addr, u8 *buf, u16 len, int retries)
{
	int i,ret = 0;
	u8 chipaddr =  0x50 | ((addr >> 8) & 3);
	for (i = 0; i < retries; i++) {
		ret = fc->i2c_request(&fc->fc_i2c_adap[1], op, chipaddr,
			addr & 0xff, buf, len);
		if (ret == 0)
			break;
	}
	return ret;
}

__attribute__((used)) static int flexcop_eeprom_lrc_read(struct flexcop_device *fc, u16 addr,
		u8 *buf, u16 len, int retries)
{
	int ret = flexcop_eeprom_request(fc, FC_READ, addr, buf, len, retries);
	if (ret == 0)
		if (calc_lrc(buf, len - 1) != buf[len - 1])
			ret = -EINVAL;
	return ret;
}

int flexcop_eeprom_check_mac_addr(struct flexcop_device *fc, int extended)
{
	u8 buf[8];
	int ret = 0;

	if ((ret = flexcop_eeprom_lrc_read(fc,0x3f8,buf,8,4)) == 0) {
		if (extended != 0) {
			err("TODO: extended (EUI64) MAC addresses aren't completely supported yet");
			ret = -EINVAL;
		} else
			memcpy(fc->dvb_adapter.proposed_mac,buf,6);
	}
	return ret;
}

