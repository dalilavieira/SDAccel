#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_5__   TYPE_2__ ;
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
typedef  int uint32_t ;
typedef  int /*<<< orphan*/  uint16_t ;
struct timing_generator {TYPE_1__* funcs; } ;
struct tg_color {int dummy; } ;
struct dc {int dummy; } ;
typedef  enum dc_color_space_type { ____Placeholder_dc_color_space_type } dc_color_space_type ;
typedef  enum dc_color_space { ____Placeholder_dc_color_space } dc_color_space ;
struct TYPE_5__ {int color_space_type; int /*<<< orphan*/ * regval; } ;
struct TYPE_4__ {scalar_t__ (* is_blanked ) (struct timing_generator*) ;} ;

/* Variables and functions */
 size_t BLACK_COLOR_FORMAT_RGB_FULLRANGE ; 
 size_t BLACK_COLOR_FORMAT_RGB_LIMITED ; 
 size_t BLACK_COLOR_FORMAT_YUV_CV ; 
#define  COLOR_SPACE_2020_RGB_FULLRANGE 147 
#define  COLOR_SPACE_2020_RGB_LIMITEDRANGE 146 
#define  COLOR_SPACE_2020_YCBCR 145 
#define  COLOR_SPACE_ADOBERGB 144 
#define  COLOR_SPACE_APPCTRL 143 
#define  COLOR_SPACE_CUSTOMPOINTS 142 
#define  COLOR_SPACE_DCIP3 141 
#define  COLOR_SPACE_DISPLAYNATIVE 140 
#define  COLOR_SPACE_DOLBYVISION 139 
#define  COLOR_SPACE_MSREF_SCRGB 138 
 int COLOR_SPACE_RGB_LIMITED_TYPE ; 
 int COLOR_SPACE_RGB_TYPE ; 
#define  COLOR_SPACE_SRGB 137 
#define  COLOR_SPACE_SRGB_LIMITED 136 
#define  COLOR_SPACE_UNKNOWN 135 
#define  COLOR_SPACE_XR_RGB 134 
#define  COLOR_SPACE_XV_YCC_601 133 
#define  COLOR_SPACE_XV_YCC_709 132 
#define  COLOR_SPACE_YCBCR601 131 
#define  COLOR_SPACE_YCBCR601_LIMITED 130 
 int COLOR_SPACE_YCBCR601_LIMITED_TYPE ; 
 int COLOR_SPACE_YCBCR601_TYPE ; 
#define  COLOR_SPACE_YCBCR709 129 
#define  COLOR_SPACE_YCBCR709_LIMITED 128 
 int COLOR_SPACE_YCBCR709_LIMITED_TYPE ; 
 int COLOR_SPACE_YCBCR709_TYPE ; 
 int NUM_ELEMENTS (TYPE_2__*) ; 
 struct tg_color* black_color_format ; 
 int /*<<< orphan*/  dm_error (char*) ; 
 int /*<<< orphan*/  msleep (int) ; 
 TYPE_2__* output_csc_matrix ; 
 scalar_t__ stub1 (struct timing_generator*) ; 

__attribute__((used)) static bool is_rgb_type(
		enum dc_color_space color_space)
{
	bool ret = false;

	if (color_space == COLOR_SPACE_SRGB			||
		color_space == COLOR_SPACE_XR_RGB		||
		color_space == COLOR_SPACE_MSREF_SCRGB		||
		color_space == COLOR_SPACE_2020_RGB_FULLRANGE	||
		color_space == COLOR_SPACE_ADOBERGB		||
		color_space == COLOR_SPACE_DCIP3	||
		color_space == COLOR_SPACE_DOLBYVISION)
		ret = true;
	return ret;
}

__attribute__((used)) static bool is_rgb_limited_type(
		enum dc_color_space color_space)
{
	bool ret = false;

	if (color_space == COLOR_SPACE_SRGB_LIMITED		||
		color_space == COLOR_SPACE_2020_RGB_LIMITEDRANGE)
		ret = true;
	return ret;
}

__attribute__((used)) static bool is_ycbcr601_type(
		enum dc_color_space color_space)
{
	bool ret = false;

	if (color_space == COLOR_SPACE_YCBCR601	||
		color_space == COLOR_SPACE_XV_YCC_601)
		ret = true;
	return ret;
}

__attribute__((used)) static bool is_ycbcr601_limited_type(
		enum dc_color_space color_space)
{
	bool ret = false;

	if (color_space == COLOR_SPACE_YCBCR601_LIMITED)
		ret = true;
	return ret;
}

__attribute__((used)) static bool is_ycbcr709_type(
		enum dc_color_space color_space)
{
	bool ret = false;

	if (color_space == COLOR_SPACE_YCBCR709	||
		color_space == COLOR_SPACE_XV_YCC_709)
		ret = true;
	return ret;
}

__attribute__((used)) static bool is_ycbcr709_limited_type(
		enum dc_color_space color_space)
{
	bool ret = false;

	if (color_space == COLOR_SPACE_YCBCR709_LIMITED)
		ret = true;
	return ret;
}

enum dc_color_space_type get_color_space_type(enum dc_color_space color_space)
{
	enum dc_color_space_type type = COLOR_SPACE_RGB_TYPE;

	if (is_rgb_type(color_space))
		type = COLOR_SPACE_RGB_TYPE;
	else if (is_rgb_limited_type(color_space))
		type = COLOR_SPACE_RGB_LIMITED_TYPE;
	else if (is_ycbcr601_type(color_space))
		type = COLOR_SPACE_YCBCR601_TYPE;
	else if (is_ycbcr709_type(color_space))
		type = COLOR_SPACE_YCBCR709_TYPE;
	else if (is_ycbcr601_limited_type(color_space))
		type = COLOR_SPACE_YCBCR601_LIMITED_TYPE;
	else if (is_ycbcr709_limited_type(color_space))
		type = COLOR_SPACE_YCBCR709_LIMITED_TYPE;

	return type;
}

const uint16_t *find_color_matrix(enum dc_color_space color_space,
							uint32_t *array_size)
{
	int i;
	enum dc_color_space_type type;
	const uint16_t *val = NULL;
	int arr_size = NUM_ELEMENTS(output_csc_matrix);

	type = get_color_space_type(color_space);
	for (i = 0; i < arr_size; i++)
		if (output_csc_matrix[i].color_space_type == type) {
			val = output_csc_matrix[i].regval;
			*array_size = 12;
			break;
		}

	return val;
}

void color_space_to_black_color(
	const struct dc *dc,
	enum dc_color_space colorspace,
	struct tg_color *black_color)
{
	switch (colorspace) {
	case COLOR_SPACE_YCBCR601:
	case COLOR_SPACE_YCBCR709:
	case COLOR_SPACE_YCBCR601_LIMITED:
	case COLOR_SPACE_YCBCR709_LIMITED:
	case COLOR_SPACE_2020_YCBCR:
		*black_color = black_color_format[BLACK_COLOR_FORMAT_YUV_CV];
		break;

	case COLOR_SPACE_SRGB_LIMITED:
		*black_color =
			black_color_format[BLACK_COLOR_FORMAT_RGB_LIMITED];
		break;

	/**
	 * Remove default and add case for all color space
	 * so when we forget to add new color space
	 * compiler will give a warning
	 */
	case COLOR_SPACE_UNKNOWN:
	case COLOR_SPACE_SRGB:
	case COLOR_SPACE_XR_RGB:
	case COLOR_SPACE_MSREF_SCRGB:
	case COLOR_SPACE_XV_YCC_709:
	case COLOR_SPACE_XV_YCC_601:
	case COLOR_SPACE_2020_RGB_FULLRANGE:
	case COLOR_SPACE_2020_RGB_LIMITEDRANGE:
	case COLOR_SPACE_ADOBERGB:
	case COLOR_SPACE_DCIP3:
	case COLOR_SPACE_DISPLAYNATIVE:
	case COLOR_SPACE_DOLBYVISION:
	case COLOR_SPACE_APPCTRL:
	case COLOR_SPACE_CUSTOMPOINTS:
		/* fefault is sRGB black (full range). */
		*black_color =
			black_color_format[BLACK_COLOR_FORMAT_RGB_FULLRANGE];
		/* default is sRGB black 0. */
		break;
	}
}

bool hwss_wait_for_blank_complete(
		struct timing_generator *tg)
{
	int counter;

	/* Not applicable if the pipe is not primary, save 300ms of boot time */
	if (!tg->funcs->is_blanked)
		return true;
	for (counter = 0; counter < 100; counter++) {
		if (tg->funcs->is_blanked(tg))
			break;

		msleep(1);
	}

	if (counter == 100) {
		dm_error("DC: failed to blank crtc!\n");
		return false;
	}

	return true;
}

