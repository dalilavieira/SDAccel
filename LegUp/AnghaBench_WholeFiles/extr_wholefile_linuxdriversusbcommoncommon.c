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
struct device {int dummy; } ;
typedef  enum usb_otg_state { ____Placeholder_usb_otg_state } usb_otg_state ;
typedef  enum usb_dr_mode { ____Placeholder_usb_dr_mode } usb_dr_mode ;
typedef  enum usb_device_state { ____Placeholder_usb_device_state } usb_device_state ;
typedef  enum usb_device_speed { ____Placeholder_usb_device_speed } usb_device_speed ;

/* Variables and functions */
 int ARRAY_SIZE (char const* const*) ; 
#define  OTG_STATE_A_HOST 149 
#define  OTG_STATE_A_IDLE 148 
#define  OTG_STATE_A_PERIPHERAL 147 
#define  OTG_STATE_A_SUSPEND 146 
#define  OTG_STATE_A_VBUS_ERR 145 
#define  OTG_STATE_A_WAIT_BCON 144 
#define  OTG_STATE_A_WAIT_VFALL 143 
#define  OTG_STATE_A_WAIT_VRISE 142 
#define  OTG_STATE_B_HOST 141 
#define  OTG_STATE_B_IDLE 140 
#define  OTG_STATE_B_PERIPHERAL 139 
#define  OTG_STATE_B_SRP_INIT 138 
#define  OTG_STATE_B_WAIT_ACON 137 
 int USB_DR_MODE_UNKNOWN ; 
 int USB_SPEED_UNKNOWN ; 
#define  USB_STATE_ADDRESS 136 
#define  USB_STATE_ATTACHED 135 
#define  USB_STATE_CONFIGURED 134 
#define  USB_STATE_DEFAULT 133 
#define  USB_STATE_NOTATTACHED 132 
#define  USB_STATE_POWERED 131 
#define  USB_STATE_RECONNECTING 130 
#define  USB_STATE_SUSPENDED 129 
#define  USB_STATE_UNAUTHENTICATED 128 
 int device_property_read_string (struct device*,char*,char const**) ; 
 int match_string (char const* const*,int,char const*) ; 
 char const** speed_names ; 
 char const* const* usb_dr_modes ; 

const char *usb_otg_state_string(enum usb_otg_state state)
{
	static const char *const names[] = {
		[OTG_STATE_A_IDLE] = "a_idle",
		[OTG_STATE_A_WAIT_VRISE] = "a_wait_vrise",
		[OTG_STATE_A_WAIT_BCON] = "a_wait_bcon",
		[OTG_STATE_A_HOST] = "a_host",
		[OTG_STATE_A_SUSPEND] = "a_suspend",
		[OTG_STATE_A_PERIPHERAL] = "a_peripheral",
		[OTG_STATE_A_WAIT_VFALL] = "a_wait_vfall",
		[OTG_STATE_A_VBUS_ERR] = "a_vbus_err",
		[OTG_STATE_B_IDLE] = "b_idle",
		[OTG_STATE_B_SRP_INIT] = "b_srp_init",
		[OTG_STATE_B_PERIPHERAL] = "b_peripheral",
		[OTG_STATE_B_WAIT_ACON] = "b_wait_acon",
		[OTG_STATE_B_HOST] = "b_host",
	};

	if (state < 0 || state >= ARRAY_SIZE(names))
		return "UNDEFINED";

	return names[state];
}

const char *usb_speed_string(enum usb_device_speed speed)
{
	if (speed < 0 || speed >= ARRAY_SIZE(speed_names))
		speed = USB_SPEED_UNKNOWN;
	return speed_names[speed];
}

enum usb_device_speed usb_get_maximum_speed(struct device *dev)
{
	const char *maximum_speed;
	int ret;

	ret = device_property_read_string(dev, "maximum-speed", &maximum_speed);
	if (ret < 0)
		return USB_SPEED_UNKNOWN;

	ret = match_string(speed_names, ARRAY_SIZE(speed_names), maximum_speed);

	return (ret < 0) ? USB_SPEED_UNKNOWN : ret;
}

const char *usb_state_string(enum usb_device_state state)
{
	static const char *const names[] = {
		[USB_STATE_NOTATTACHED] = "not attached",
		[USB_STATE_ATTACHED] = "attached",
		[USB_STATE_POWERED] = "powered",
		[USB_STATE_RECONNECTING] = "reconnecting",
		[USB_STATE_UNAUTHENTICATED] = "unauthenticated",
		[USB_STATE_DEFAULT] = "default",
		[USB_STATE_ADDRESS] = "addressed",
		[USB_STATE_CONFIGURED] = "configured",
		[USB_STATE_SUSPENDED] = "suspended",
	};

	if (state < 0 || state >= ARRAY_SIZE(names))
		return "UNKNOWN";

	return names[state];
}

__attribute__((used)) static enum usb_dr_mode usb_get_dr_mode_from_string(const char *str)
{
	int ret;

	ret = match_string(usb_dr_modes, ARRAY_SIZE(usb_dr_modes), str);
	return (ret < 0) ? USB_DR_MODE_UNKNOWN : ret;
}

enum usb_dr_mode usb_get_dr_mode(struct device *dev)
{
	const char *dr_mode;
	int err;

	err = device_property_read_string(dev, "dr_mode", &dr_mode);
	if (err < 0)
		return USB_DR_MODE_UNKNOWN;

	return usb_get_dr_mode_from_string(dr_mode);
}

