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
struct TYPE_7__ {int flag; } ;
typedef  TYPE_1__ mbfl_identify_filter ;
struct TYPE_8__ {int (* output_function ) (int,int /*<<< orphan*/ ) ;scalar_t__ illegal_mode; int /*<<< orphan*/  data; } ;
typedef  TYPE_2__ mbfl_convert_filter ;

/* Variables and functions */
 int /*<<< orphan*/  CK (int) ; 
 scalar_t__ MBFL_OUTPUTFILTER_ILLEGAL_MODE_NONE ; 
 int mbfl_filt_conv_illegal_output (int,TYPE_2__*) ; 
 int stub1 (int,int /*<<< orphan*/ ) ; 
 int stub2 (int,int /*<<< orphan*/ ) ; 

int mbfl_filt_conv_ascii_wchar(int c, mbfl_convert_filter *filter)
{
	return (*filter->output_function)(c, filter->data);
}

int mbfl_filt_conv_wchar_ascii(int c, mbfl_convert_filter *filter)
{
	if (c >= 0 && c < 0x80) {
		CK((*filter->output_function)(c, filter->data));
	} else {
		if (filter->illegal_mode != MBFL_OUTPUTFILTER_ILLEGAL_MODE_NONE) {
			CK(mbfl_filt_conv_illegal_output(c, filter));
		}
	}

	return c;
}

__attribute__((used)) static int mbfl_filt_ident_ascii(int c, mbfl_identify_filter *filter)
{
	if (c >= 0x20 && c < 0x80) {
		;
	} else if (c == 0x0d || c == 0x0a || c == 0x09 || c == 0) {	/* CR or LF or HTAB or null */
		;
	} else {
		filter->flag = 1;
	}

	return c;
}

