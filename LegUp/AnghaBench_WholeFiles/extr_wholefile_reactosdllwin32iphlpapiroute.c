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
typedef  int /*<<< orphan*/  PMIB_IPFORWARDROW ;
typedef  int /*<<< orphan*/  DWORD ;

/* Variables and functions */
 int /*<<< orphan*/  FIXME (char*) ; 
 int /*<<< orphan*/  TRACE (char*,int /*<<< orphan*/ ) ; 

DWORD createIpForwardEntry( PMIB_IPFORWARDROW pRoute ) {
    TRACE("pRoute %p\n", pRoute);
  /* could use SIOCADDRT, not sure I want to */
  FIXME(":stub\n");
  return (DWORD) 0;
}

DWORD setIpForwardEntry( PMIB_IPFORWARDROW pRoute ) {
  FIXME(":stub\n");
  return (DWORD) 0;
}

DWORD deleteIpForwardEntry( PMIB_IPFORWARDROW pRoute ) {
  TRACE("pRoute %p\n", pRoute);
  /* could use SIOCDELRT, not sure I want to */
  FIXME(":stub\n");
  return (DWORD) 0;
}

