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
struct psmouse {char* vendor; char* name; } ;

/* Variables and functions */
 int ENODEV ; 
 int ENOSYS ; 
 int /*<<< orphan*/  focaltech_pnp_ids ; 
 int /*<<< orphan*/  psmouse_matches_pnp_id (struct psmouse*,int /*<<< orphan*/ ) ; 

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

__attribute__((used)) static inline int focaltech_init(struct psmouse *psmouse)
{
	return -ENOSYS;
}

int focaltech_detect(struct psmouse *psmouse, bool set_properties)
{
	if (!psmouse_matches_pnp_id(psmouse, focaltech_pnp_ids))
		return -ENODEV;

	if (set_properties) {
		psmouse->vendor = "FocalTech";
		psmouse->name = "Touchpad";
	}

	return 0;
}

