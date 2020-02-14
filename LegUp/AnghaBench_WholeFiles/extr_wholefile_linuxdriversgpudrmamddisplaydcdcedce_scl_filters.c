#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_2__ ;
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  uint16_t ;
struct fixed31_32 {scalar_t__ value; } ;
struct TYPE_4__ {scalar_t__ value; } ;
struct TYPE_3__ {scalar_t__ value; } ;

/* Variables and functions */
 TYPE_2__ dc_fixpt_from_fraction (int,int) ; 
 TYPE_1__ dc_fixpt_one ; 
 int /*<<< orphan*/  const* filter_2tap_16p ; 
 int /*<<< orphan*/  const* filter_2tap_64p ; 
 int /*<<< orphan*/  const* filter_3tap_16p_117 ; 
 int /*<<< orphan*/  const* filter_3tap_16p_150 ; 
 int /*<<< orphan*/  const* filter_3tap_16p_183 ; 
 int /*<<< orphan*/  const* filter_3tap_16p_upscale ; 
 int /*<<< orphan*/  const* filter_3tap_64p_117 ; 
 int /*<<< orphan*/  const* filter_3tap_64p_150 ; 
 int /*<<< orphan*/  const* filter_3tap_64p_183 ; 
 int /*<<< orphan*/  const* filter_3tap_64p_upscale ; 
 int /*<<< orphan*/  const* filter_4tap_16p_117 ; 
 int /*<<< orphan*/  const* filter_4tap_16p_150 ; 
 int /*<<< orphan*/  const* filter_4tap_16p_183 ; 
 int /*<<< orphan*/  const* filter_4tap_16p_upscale ; 
 int /*<<< orphan*/  const* filter_4tap_64p_117 ; 
 int /*<<< orphan*/  const* filter_4tap_64p_150 ; 
 int /*<<< orphan*/  const* filter_4tap_64p_183 ; 
 int /*<<< orphan*/  const* filter_4tap_64p_upscale ; 
 int /*<<< orphan*/  const* filter_5tap_64p_117 ; 
 int /*<<< orphan*/  const* filter_5tap_64p_150 ; 
 int /*<<< orphan*/  const* filter_5tap_64p_183 ; 
 int /*<<< orphan*/  const* filter_5tap_64p_upscale ; 
 int /*<<< orphan*/  const* filter_6tap_64p_117 ; 
 int /*<<< orphan*/  const* filter_6tap_64p_150 ; 
 int /*<<< orphan*/  const* filter_6tap_64p_183 ; 
 int /*<<< orphan*/  const* filter_6tap_64p_upscale ; 
 int /*<<< orphan*/  const* filter_7tap_64p_117 ; 
 int /*<<< orphan*/  const* filter_7tap_64p_150 ; 
 int /*<<< orphan*/  const* filter_7tap_64p_183 ; 
 int /*<<< orphan*/  const* filter_7tap_64p_upscale ; 
 int /*<<< orphan*/  const* filter_8tap_64p_117 ; 
 int /*<<< orphan*/  const* filter_8tap_64p_150 ; 
 int /*<<< orphan*/  const* filter_8tap_64p_183 ; 
 int /*<<< orphan*/  const* filter_8tap_64p_upscale ; 

const uint16_t *get_filter_3tap_16p(struct fixed31_32 ratio)
{
	if (ratio.value < dc_fixpt_one.value)
		return filter_3tap_16p_upscale;
	else if (ratio.value < dc_fixpt_from_fraction(4, 3).value)
		return filter_3tap_16p_117;
	else if (ratio.value < dc_fixpt_from_fraction(5, 3).value)
		return filter_3tap_16p_150;
	else
		return filter_3tap_16p_183;
}

const uint16_t *get_filter_3tap_64p(struct fixed31_32 ratio)
{
	if (ratio.value < dc_fixpt_one.value)
		return filter_3tap_64p_upscale;
	else if (ratio.value < dc_fixpt_from_fraction(4, 3).value)
		return filter_3tap_64p_117;
	else if (ratio.value < dc_fixpt_from_fraction(5, 3).value)
		return filter_3tap_64p_150;
	else
		return filter_3tap_64p_183;
}

const uint16_t *get_filter_4tap_16p(struct fixed31_32 ratio)
{
	if (ratio.value < dc_fixpt_one.value)
		return filter_4tap_16p_upscale;
	else if (ratio.value < dc_fixpt_from_fraction(4, 3).value)
		return filter_4tap_16p_117;
	else if (ratio.value < dc_fixpt_from_fraction(5, 3).value)
		return filter_4tap_16p_150;
	else
		return filter_4tap_16p_183;
}

const uint16_t *get_filter_4tap_64p(struct fixed31_32 ratio)
{
	if (ratio.value < dc_fixpt_one.value)
		return filter_4tap_64p_upscale;
	else if (ratio.value < dc_fixpt_from_fraction(4, 3).value)
		return filter_4tap_64p_117;
	else if (ratio.value < dc_fixpt_from_fraction(5, 3).value)
		return filter_4tap_64p_150;
	else
		return filter_4tap_64p_183;
}

const uint16_t *get_filter_5tap_64p(struct fixed31_32 ratio)
{
	if (ratio.value < dc_fixpt_one.value)
		return filter_5tap_64p_upscale;
	else if (ratio.value < dc_fixpt_from_fraction(4, 3).value)
		return filter_5tap_64p_117;
	else if (ratio.value < dc_fixpt_from_fraction(5, 3).value)
		return filter_5tap_64p_150;
	else
		return filter_5tap_64p_183;
}

const uint16_t *get_filter_6tap_64p(struct fixed31_32 ratio)
{
	if (ratio.value < dc_fixpt_one.value)
		return filter_6tap_64p_upscale;
	else if (ratio.value < dc_fixpt_from_fraction(4, 3).value)
		return filter_6tap_64p_117;
	else if (ratio.value < dc_fixpt_from_fraction(5, 3).value)
		return filter_6tap_64p_150;
	else
		return filter_6tap_64p_183;
}

const uint16_t *get_filter_7tap_64p(struct fixed31_32 ratio)
{
	if (ratio.value < dc_fixpt_one.value)
		return filter_7tap_64p_upscale;
	else if (ratio.value < dc_fixpt_from_fraction(4, 3).value)
		return filter_7tap_64p_117;
	else if (ratio.value < dc_fixpt_from_fraction(5, 3).value)
		return filter_7tap_64p_150;
	else
		return filter_7tap_64p_183;
}

const uint16_t *get_filter_8tap_64p(struct fixed31_32 ratio)
{
	if (ratio.value < dc_fixpt_one.value)
		return filter_8tap_64p_upscale;
	else if (ratio.value < dc_fixpt_from_fraction(4, 3).value)
		return filter_8tap_64p_117;
	else if (ratio.value < dc_fixpt_from_fraction(5, 3).value)
		return filter_8tap_64p_150;
	else
		return filter_8tap_64p_183;
}

const uint16_t *get_filter_2tap_16p(void)
{
	return filter_2tap_16p;
}

const uint16_t *get_filter_2tap_64p(void)
{
	return filter_2tap_64p;
}

