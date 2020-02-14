#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_5__   TYPE_2__ ;
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  wchar_t ;
struct TYPE_4__ {scalar_t__ BuildNumber; } ;
struct TYPE_5__ {TYPE_1__ osContext; } ;
typedef  TYPE_2__* PKUHL_M_SEKURLSA_CONTEXT ;
typedef  int /*<<< orphan*/  NTSTATUS ;
typedef  int /*<<< orphan*/  MSV1_0_PRIMARY_HELPER ;

/* Variables and functions */
 scalar_t__ KULL_M_WIN_BUILD_10_1507 ; 
 scalar_t__ KULL_M_WIN_BUILD_10_1511 ; 
 scalar_t__ KULL_M_WIN_BUILD_10_1607 ; 
 int /*<<< orphan*/  kuhl_m_sekurlsa_getLogonData (int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  kuhl_m_sekurlsa_msv_single_package ; 
 int /*<<< orphan*/ * msv1_0_primaryHelper ; 

NTSTATUS kuhl_m_sekurlsa_msv(int argc, wchar_t * argv[])
{
	return kuhl_m_sekurlsa_getLogonData(kuhl_m_sekurlsa_msv_single_package, 1);
}

const MSV1_0_PRIMARY_HELPER * kuhl_m_sekurlsa_msv_helper(PKUHL_M_SEKURLSA_CONTEXT context)
{
	const MSV1_0_PRIMARY_HELPER * helper;
	if(context->osContext.BuildNumber < KULL_M_WIN_BUILD_10_1507)
		helper = &msv1_0_primaryHelper[0];
	else if(context->osContext.BuildNumber < KULL_M_WIN_BUILD_10_1511)
		helper = &msv1_0_primaryHelper[1];
	else if(context->osContext.BuildNumber < KULL_M_WIN_BUILD_10_1607)
		helper = &msv1_0_primaryHelper[2];
	else
		helper = &msv1_0_primaryHelper[3];
	return helper;
}

