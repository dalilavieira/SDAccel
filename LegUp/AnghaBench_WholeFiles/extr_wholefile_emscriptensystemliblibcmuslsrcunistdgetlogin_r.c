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

/* Variables and functions */
 int ENXIO ; 
 int ERANGE ; 
 char* getlogin () ; 
 int /*<<< orphan*/  strcpy (char*,char*) ; 
 size_t strlen (char*) ; 

int getlogin_r(char *name, size_t size)
{
	char *logname = getlogin();
	if (!logname) return ENXIO; /* or...? */
	if (strlen(logname) >= size) return ERANGE;
	strcpy(name, logname);
	return 0;
}

