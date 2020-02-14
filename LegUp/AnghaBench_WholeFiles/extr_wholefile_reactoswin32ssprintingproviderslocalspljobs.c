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
typedef  scalar_t__* PDWORD ;
typedef  scalar_t__ PCWSTR ;
typedef  int BOOL ;

/* Variables and functions */
 int /*<<< orphan*/  ERR (char*,scalar_t__) ; 
 int FALSE ; 
 int /*<<< orphan*/  GlobalJobList ; 
 int /*<<< orphan*/  IS_VALID_JOB_ID (scalar_t__) ; 
 scalar_t__ LookupElementSkiplist (int /*<<< orphan*/ *,scalar_t__*,int /*<<< orphan*/ *) ; 
 int TRUE ; 
 scalar_t__ _dwLastJobID ; 
 scalar_t__ wcscmp (scalar_t__,scalar_t__) ; 

__attribute__((used)) static __inline BOOL
_EqualStrings(PCWSTR pwszA, PCWSTR pwszB)
{
    if (!pwszA && !pwszB)
        return TRUE;

    if (pwszA && !pwszB)
        return FALSE;

    if (!pwszA && pwszB)
        return FALSE;

    return (wcscmp(pwszA, pwszB) == 0);
}

__attribute__((used)) static BOOL
_GetNextJobID(PDWORD dwJobID)
{
    ++_dwLastJobID;

    while (LookupElementSkiplist(&GlobalJobList, &_dwLastJobID, NULL))
    {
        // This ID is already taken. Try the next one.
        ++_dwLastJobID;
    }

    if (!IS_VALID_JOB_ID(_dwLastJobID))
    {
        ERR("Job ID %lu isn't valid!\n", _dwLastJobID);
        return FALSE;
    }

    *dwJobID = _dwLastJobID;
    return TRUE;
}

