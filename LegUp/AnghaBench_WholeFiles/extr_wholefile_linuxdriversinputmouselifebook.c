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
struct psmouse {int dummy; } ;
struct dmi_system_id {int dummy; } ;

/* Variables and functions */
 int ENOSYS ; 
 char* desired_serio_phys ; 
 int lifebook_use_6byte_proto ; 

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

__attribute__((used)) static inline void lifebook_module_init(void)
{
}

__attribute__((used)) static inline int lifebook_detect(struct psmouse *psmouse, bool set_properties)
{
	return -ENOSYS;
}

__attribute__((used)) static inline int lifebook_init(struct psmouse *psmouse)
{
	return -ENOSYS;
}

__attribute__((used)) static int lifebook_limit_serio3(const struct dmi_system_id *d)
{
	desired_serio_phys = "isa0060/serio3";
	return 1;
}

__attribute__((used)) static int lifebook_set_6byte_proto(const struct dmi_system_id *d)
{
	lifebook_use_6byte_proto = true;
	return 1;
}

