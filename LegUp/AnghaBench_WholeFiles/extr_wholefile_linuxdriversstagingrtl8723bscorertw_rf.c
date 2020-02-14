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
typedef  size_t u8 ;
typedef  scalar_t__ u32 ;
struct TYPE_3__ {scalar_t__ channel; scalar_t__ frequency; } ;

/* Variables and functions */
 size_t ARRAY_SIZE (TYPE_1__*) ; 
 TYPE_1__* ch_freq_map ; 

u32 rtw_ch2freq(u32 channel)
{
	u8 i;
	u32 freq = 0;

	for (i = 0; i < ARRAY_SIZE(ch_freq_map); i++) {
		if (channel == ch_freq_map[i].channel) {
			freq = ch_freq_map[i].frequency;
				break;
		}
	}
	if (i == ARRAY_SIZE(ch_freq_map))
		freq = 2412;

	return freq;
}

