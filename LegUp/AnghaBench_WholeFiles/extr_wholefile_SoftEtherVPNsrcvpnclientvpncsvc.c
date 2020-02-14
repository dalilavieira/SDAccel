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
 int /*<<< orphan*/  CtStartClient () ; 
 int /*<<< orphan*/  CtStopClient () ; 
 int /*<<< orphan*/  FreeCedar () ; 
 int /*<<< orphan*/  InitCedar () ; 
 int /*<<< orphan*/  InitProcessCallOnce () ; 
 int UnixService (int,char**,char*,void (*) (),void (*) ()) ; 

void StartProcess()
{
	// Start the client
	InitCedar();
	CtStartClient();
}

void StopProcess()
{
  	// Stop the client
	CtStopClient();
	FreeCedar();
}

int main(int argc, char *argv[])
{
	InitProcessCallOnce();

#ifdef	OS_WIN32

	return MsService(GC_SVC_NAME_VPNCLIENT, StartProcess, StopProcess, ICO_MACHINE, argv[0]);
#else	// OS_WIN32
	return UnixService(argc, argv, "vpnclient", StartProcess, StopProcess);
#endif	// OS_WIN32
}

