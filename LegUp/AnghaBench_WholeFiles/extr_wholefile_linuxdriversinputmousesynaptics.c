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
typedef  int u8 ;
struct ps2dev {int dummy; } ;
struct psmouse {char* vendor; char* name; struct ps2dev ps2dev; } ;

/* Variables and functions */
 int ENODEV ; 
 int /*<<< orphan*/  PSMOUSE_CMD_GETINFO ; 
 int /*<<< orphan*/  PSMOUSE_CMD_SETRATE ; 
 int /*<<< orphan*/  PSMOUSE_CMD_SETRES ; 
 int SYN_PS_SET_MODE2 ; 
 int ps2_command (struct ps2dev*,int*,int /*<<< orphan*/ ) ; 
 int ps2_sliced_command (struct ps2dev*,int) ; 

__attribute__((used)) static inline int psmouse_smbus_module_init(void)
{
	return 0;
}

__attribute__((used)) static inline void psmouse_smbus_module_exit(void)
{
}

__attribute__((used)) static inline void psmouse_smbus_cleanup(struct psmouse *psmouse)
{
}

__attribute__((used)) static int synaptics_mode_cmd(struct psmouse *psmouse, u8 mode)
{
	u8 param[1];
	int error;

	error = ps2_sliced_command(&psmouse->ps2dev, mode);
	if (error)
		return error;

	param[0] = SYN_PS_SET_MODE2;
	error = ps2_command(&psmouse->ps2dev, param, PSMOUSE_CMD_SETRATE);
	if (error)
		return error;

	return 0;
}

int synaptics_detect(struct psmouse *psmouse, bool set_properties)
{
	struct ps2dev *ps2dev = &psmouse->ps2dev;
	u8 param[4] = { 0 };

	ps2_command(ps2dev, param, PSMOUSE_CMD_SETRES);
	ps2_command(ps2dev, param, PSMOUSE_CMD_SETRES);
	ps2_command(ps2dev, param, PSMOUSE_CMD_SETRES);
	ps2_command(ps2dev, param, PSMOUSE_CMD_SETRES);
	ps2_command(ps2dev, param, PSMOUSE_CMD_GETINFO);

	if (param[1] != 0x47)
		return -ENODEV;

	if (set_properties) {
		psmouse->vendor = "Synaptics";
		psmouse->name = "TouchPad";
	}

	return 0;
}

void synaptics_reset(struct psmouse *psmouse)
{
	/* reset touchpad back to relative mode, gestures enabled */
	synaptics_mode_cmd(psmouse, 0);
}

