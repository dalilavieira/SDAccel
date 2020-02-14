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
typedef  int /*<<< orphan*/  PLSAP_RM_API_MESSAGE ;

/* Variables and functions */
 int /*<<< orphan*/  ERR (char*) ; 

__attribute__((used)) static
VOID
LsapComponentTest(
    PLSAP_RM_API_MESSAGE Message)
{
    ERR("Security: LSA Component Test Command Received\n");
}

__attribute__((used)) static
VOID
LsapAdtWriteLog(
    PLSAP_RM_API_MESSAGE Message)
{
    ERR("LsapAdtWriteLog\n");
}

__attribute__((used)) static
VOID
LsapAsync(
    PLSAP_RM_API_MESSAGE Message)
{
    ERR("LsapAsync\n");
}

