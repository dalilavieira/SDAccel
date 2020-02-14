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
typedef  int /*<<< orphan*/  WCHAR ;
typedef  int /*<<< orphan*/  DWORD ;

/* Variables and functions */
 int /*<<< orphan*/  wcstoul (int /*<<< orphan*/  const*,int /*<<< orphan*/ **,int) ; 

__attribute__((used)) static inline DWORD
DWORDfromString(const WCHAR *pszString)
{
    WCHAR *pszEnd;

    return wcstoul(pszString, &pszEnd, 16);
}

