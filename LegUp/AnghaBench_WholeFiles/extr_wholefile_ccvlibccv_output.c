#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_23__   TYPE_7__ ;
typedef  struct TYPE_22__   TYPE_6__ ;
typedef  struct TYPE_21__   TYPE_5__ ;
typedef  struct TYPE_20__   TYPE_4__ ;
typedef  struct TYPE_19__   TYPE_3__ ;
typedef  struct TYPE_18__   TYPE_2__ ;
typedef  struct TYPE_17__   TYPE_1__ ;

/* Type definitions */
typedef  unsigned int uint32_t ;
struct TYPE_17__ {int width; int height; } ;
typedef  TYPE_1__ ccv_size_t ;
struct TYPE_18__ {int x; int y; int width; int height; } ;
typedef  TYPE_2__ ccv_rect_t ;
struct TYPE_19__ {int x; int y; } ;
typedef  TYPE_3__ ccv_point_t ;
struct TYPE_20__ {int left; int top; int right; int bottom; } ;
typedef  TYPE_4__ ccv_margin_t ;
typedef  int /*<<< orphan*/  ccv_file_info_t ;
typedef  int /*<<< orphan*/  ccv_dense_matrix_t ;
struct TYPE_21__ {float x; float y; float a; float b; float roll; float pitch; float yaw; } ;
typedef  TYPE_5__ ccv_decimal_pose_t ;
struct TYPE_22__ {float x; float y; } ;
typedef  TYPE_6__ ccv_decimal_point_t ;
struct TYPE_23__ {int c; int /*<<< orphan*/  file; int /*<<< orphan*/  type; int /*<<< orphan*/ * matrix; } ;
typedef  TYPE_7__ ccv_categorized_t ;

/* Variables and functions */
 int /*<<< orphan*/  CCV_CATEGORIZED_DENSE_MATRIX ; 
 int /*<<< orphan*/  CCV_CATEGORIZED_FILE ; 
 int CCV_CLI_NONE ; 
 int /*<<< orphan*/  assert (int) ; 
 int cli_output_levels ; 

__attribute__((used)) inline static ccv_margin_t ccv_margin(int left, int top, int right, int bottom)
{
	ccv_margin_t margin;
	margin.left = left;
	margin.top = top;
	margin.right = right;
	margin.bottom = bottom;
	return margin;
}

__attribute__((used)) inline static ccv_size_t ccv_size(int width, int height)
{
	ccv_size_t size;
	size.width = width;
	size.height = height;
	return size;
}

__attribute__((used)) inline static int ccv_size_is_zero(ccv_size_t size)
{
	return size.width == 0 && size.height == 0;
}

__attribute__((used)) inline static ccv_rect_t ccv_rect(int x, int y, int width, int height)
{
	ccv_rect_t rect;
	rect.x = x;
	rect.y = y;
	rect.width = width;
	rect.height = height;
	return rect;
}

__attribute__((used)) inline static int ccv_rect_is_zero(ccv_rect_t rect)
{
	return rect.x == 0 && rect.y == 0 && rect.width == 0 && rect.height == 0;
}

__attribute__((used)) inline static ccv_point_t ccv_point(int x, int y)
{
	ccv_point_t point;
	point.x = x;
	point.y = y;
	return point;
}

__attribute__((used)) inline static ccv_decimal_point_t ccv_decimal_point(float x, float y)
{
	ccv_decimal_point_t point;
	point.x = x;
	point.y = y;
	return point;
}

__attribute__((used)) inline static ccv_decimal_pose_t ccv_decimal_pose(float x, float y, float a, float b, float roll, float pitch, float yaw)
{
	ccv_decimal_pose_t pose;
	pose.x = x;
	pose.y = y;
	pose.a = a;
	pose.b = b;
	pose.roll = roll;
	pose.pitch = pitch;
	pose.yaw = yaw;
	return pose;
}

__attribute__((used)) inline static ccv_categorized_t ccv_categorized(int c, ccv_dense_matrix_t* matrix, ccv_file_info_t* file)
{
	assert((matrix && !file) || (!matrix && file));
	ccv_categorized_t categorized;
	categorized.c = c;
	if (matrix)
		categorized.type = CCV_CATEGORIZED_DENSE_MATRIX, categorized.matrix = matrix;
	else
		categorized.type = CCV_CATEGORIZED_FILE, categorized.file = *file;
	return categorized;
}

int ccv_cli_output_level_and_above(int level)
{
	if (level == CCV_CLI_NONE)
		return CCV_CLI_NONE;
	int i;
	uint32_t levels = 0;
	for (i = 0; i < 32; i++)
		if (level <= (1u << i))
			levels |= 1u << i;
	return (int)levels;
}

void ccv_cli_set_output_levels(int levels)
{
	cli_output_levels = levels;
}

int ccv_cli_get_output_levels(void)
{
	return cli_output_levels;
}

