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
typedef  int /*<<< orphan*/  VOID ;
typedef  int /*<<< orphan*/  SessionInfo ;
typedef  int /*<<< orphan*/  LPOVERLAPPED ;
typedef  int /*<<< orphan*/  DWORD ;

/* Variables and functions */
 int /*<<< orphan*/  DPRINT (char*) ; 

void
CompleteWaveOverlap(
    DWORD error_code,
    DWORD bytes_transferred,
    LPOVERLAPPED overlapped)
{
    DPRINT("Complete partial wave overlap\n");
}

VOID
UpdateWaveLoop(SessionInfo* session_info)
{
}

VOID
PerformWaveIO(
    SessionInfo* session_info)
{

}

