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
typedef  int /*<<< orphan*/  wchar_t ;
typedef  int /*<<< orphan*/  NTSTATUS ;

/* Variables and functions */
 int /*<<< orphan*/  STATUS_SUCCESS ; 
 int /*<<< orphan*/  kuhl_m_sekurlsa_enum (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  kuhl_m_sekurlsa_enum_callback_dpapi ; 

NTSTATUS kuhl_m_sekurlsa_dpapi(int argc, wchar_t * argv[])
{
	kuhl_m_sekurlsa_enum(kuhl_m_sekurlsa_enum_callback_dpapi, NULL);
	return STATUS_SUCCESS;
}

