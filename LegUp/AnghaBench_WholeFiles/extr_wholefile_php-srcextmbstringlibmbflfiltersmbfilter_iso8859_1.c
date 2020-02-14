#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_5__   TYPE_1__ ;

/* Type definitions */
struct TYPE_5__ {int (* output_function ) (int,int /*<<< orphan*/ ) ;scalar_t__ illegal_mode; int /*<<< orphan*/  data; } ;
typedef  TYPE_1__ mbfl_convert_filter ;

/* Variables and functions */
 int /*<<< orphan*/  CK (int) ; 
 scalar_t__ MBFL_OUTPUTFILTER_ILLEGAL_MODE_NONE ; 
 int mbfl_filt_conv_illegal_output (int,TYPE_1__*) ; 
 int stub1 (int,int /*<<< orphan*/ ) ; 
 int stub2 (int,int /*<<< orphan*/ ) ; 

int mbfl_filt_conv_8859_1_wchar(int c, mbfl_convert_filter *filter)
{
	return (*filter->output_function)(c, filter->data);
}

int mbfl_filt_conv_wchar_8859_1(int c, mbfl_convert_filter *filter)
{
	if (c >= 0 && c < 0x100) {
		CK((*filter->output_function)(c, filter->data));
	} else {
		if (filter->illegal_mode != MBFL_OUTPUTFILTER_ILLEGAL_MODE_NONE) {
			CK(mbfl_filt_conv_illegal_output(c, filter));
		}
	}

	return c;
}

