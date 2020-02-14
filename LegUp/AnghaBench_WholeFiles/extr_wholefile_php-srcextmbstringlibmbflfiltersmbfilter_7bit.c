#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
struct TYPE_4__ {int (* output_function ) (int,int /*<<< orphan*/ ) ;int /*<<< orphan*/  data; } ;
typedef  TYPE_1__ mbfl_convert_filter ;

/* Variables and functions */
 int /*<<< orphan*/  CK (int) ; 
 int stub1 (int,int /*<<< orphan*/ ) ; 
 int stub2 (int,int /*<<< orphan*/ ) ; 

int mbfl_filt_conv_7bit_any(int c, mbfl_convert_filter *filter)
{
	return (*filter->output_function)(c, filter->data);
}

int mbfl_filt_conv_any_7bit(int c, mbfl_convert_filter *filter)
{
	if (c >= 0 && c < 0x80) {
		CK((*filter->output_function)(c, filter->data));
	}
	return c;
}

