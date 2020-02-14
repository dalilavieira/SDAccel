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
typedef  int ut32 ;
typedef  scalar_t__ st32 ;

/* Variables and functions */
 scalar_t__ C55PLUS_DEBUG ; 
 int has_failed ; 
 int* ins_buff ; 
 int ins_buff_len ; 
 int /*<<< orphan*/  printf (char*,int,int,int) ; 

ut32 get_ins_len(ut8 opcode) {
	ut32 val = (opcode >> 4) & 0xF;
	ut32 len = 0;

	switch (val) {
	case 0:
	case 1:
		len = 2;
		break;
	case 2:
	case 3:
		len = 1;
		break;
	case 4:
	case 5:
	case 6:
	case 7:
		len = 3;
		break;
	case 8:
	case 9:
	case 10:
		len = 4;
		break;
	case 11:
	case 12:
	case 13:
		len = 5;
		break;
	case 14:
		len = 6;
		break;
	case 15:
		len = 7;
		break;
	}

	return len;
}

ut32 get_ins_part(ut32 pos, ut32 len) {
	ut32 ret = 0;
	has_failed = 0;
	if (C55PLUS_DEBUG) {
		printf ("pos => 0x%x len => %d ins_buff_len => %d\n", pos, len, ins_buff_len);
	}

	if ((st32)pos < 0 || pos >= ins_buff_len) {
		has_failed = 1;
		return ret;
	} 

	for (; len > 0; --len) {
		ret <<= 8;
		if (pos >= ins_buff_len) {
			has_failed = 1;
		} else {
			ret |= ins_buff[pos++];
		}
	}

	return ret;
}

