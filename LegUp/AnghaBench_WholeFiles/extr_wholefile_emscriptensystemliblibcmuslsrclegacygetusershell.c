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
typedef  int ssize_t ;

/* Variables and functions */
 scalar_t__ defshells ; 
 scalar_t__ f ; 
 int /*<<< orphan*/  fclose (scalar_t__) ; 
 scalar_t__ fmemopen (void*,int,char*) ; 
 scalar_t__ fopen (char*,char*) ; 
 int getline (char**,int /*<<< orphan*/ *,scalar_t__) ; 
 char* line ; 
 int /*<<< orphan*/  linesize ; 

void endusershell(void)
{
	if (f) fclose(f);
	f = 0;
}

void setusershell(void)
{
	if (!f) f = fopen("/etc/shells", "rbe");
	if (!f) f = fmemopen((void *)defshells, sizeof defshells - 1, "rb");
}

char *getusershell(void)
{
	ssize_t l;
	if (!f) setusershell();
	if (!f) return 0;
	l = getline(&line, &linesize, f);
	if (l <= 0) return 0;
	if (line[l-1]=='\n') line[l-1]=0;
	return line;
}

