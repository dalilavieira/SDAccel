#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_6__   TYPE_3__ ;
typedef  struct TYPE_5__   TYPE_2__ ;
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  _u32 ;
typedef  size_t _i8 ;
typedef  int /*<<< orphan*/  (* _SlSpawnEntryFunc_t ) (int /*<<< orphan*/ ) ;
typedef  scalar_t__ _SlNonOsTime_t ;
struct TYPE_4__ {int /*<<< orphan*/ * pValue; int /*<<< orphan*/  (* pEntry ) (int /*<<< orphan*/ ) ;} ;
typedef  TYPE_1__ _SlNonOsSpawnEntry_t ;
typedef  scalar_t__ _SlNonOsSemObj_t ;
typedef  int /*<<< orphan*/  _SlNonOsRetVal_t ;
struct TYPE_6__ {TYPE_1__* SpawnEntries; } ;
struct TYPE_5__ {scalar_t__ RxDoneCnt; } ;

/* Variables and functions */
 size_t NONOS_MAX_SPAWN_ENTRIES ; 
 int /*<<< orphan*/  NONOS_RET_ERR ; 
 int /*<<< orphan*/  NONOS_RET_OK ; 
 scalar_t__ NONOS_WAIT_FOREVER ; 
 scalar_t__ RxIrqCnt ; 
 int /*<<< orphan*/  _SlNonOsMainLoopTask () ; 
 TYPE_3__ g__SlNonOsCB ; 
 TYPE_2__* g_pCB ; 

_SlNonOsRetVal_t _SlNonOsSemSet(_SlNonOsSemObj_t* pSemObj , _SlNonOsSemObj_t Value)
{
    *pSemObj = Value;
    return NONOS_RET_OK;
}

_SlNonOsRetVal_t _SlNonOsSemGet(_SlNonOsSemObj_t* pSyncObj, _SlNonOsSemObj_t WaitValue, _SlNonOsSemObj_t SetValue, _SlNonOsTime_t Timeout)
{
#ifdef _SlSyncWaitLoopCallback
    _SlNonOsTime_t timeOutRequest = Timeout; 
#endif
    while (Timeout>0)
    {
        if (WaitValue == *pSyncObj)
        {
            *pSyncObj = SetValue;
            break;
        }
        if (Timeout != NONOS_WAIT_FOREVER)
        {		
            Timeout--;
        }
        _SlNonOsMainLoopTask();
#ifdef _SlSyncWaitLoopCallback
        if( (__NON_OS_SYNC_OBJ_SIGNAL_VALUE == WaitValue) && (timeOutRequest != NONOS_NO_WAIT) )
        {
            if (WaitValue == *pSyncObj)
            {
                *pSyncObj = SetValue;
                break;
            }
            _SlSyncWaitLoopCallback();
        }
#endif
    }

    if (0 == Timeout)
    {
        return NONOS_RET_ERR;
    }
    else
    {
        return NONOS_RET_OK;
    }
}

_SlNonOsRetVal_t _SlNonOsSpawn(_SlSpawnEntryFunc_t pEntry , void* pValue , _u32 flags)
{
	 _i8 i = 0;
    
#ifndef SL_TINY_EXT 	
	for (i=0 ; i<NONOS_MAX_SPAWN_ENTRIES ; i++)
#endif     
	{
		_SlNonOsSpawnEntry_t* pE = &g__SlNonOsCB.SpawnEntries[i];
	
		if (NULL == pE->pEntry)
		{
			pE->pValue = pValue;
			pE->pEntry = pEntry;
#ifndef SL_TINY_EXT 	                        
			break;
#endif                        
		}
	}
        
        
        return NONOS_RET_OK;
}

_SlNonOsRetVal_t _SlNonOsMainLoopTask(void)
{
	_i8 i=0;


#ifndef SL_TINY_EXT
	for (i=0 ; i<NONOS_MAX_SPAWN_ENTRIES ; i++)
#endif
	{
		_SlNonOsSpawnEntry_t* pE = &g__SlNonOsCB.SpawnEntries[i];
		_SlSpawnEntryFunc_t 		pF = pE->pEntry;
		
		if (NULL != pF)
		{
            if(RxIrqCnt != (g_pCB)->RxDoneCnt)
            {
                pF(0); /* (pValue) */
            }
            
			pE->pEntry = NULL;
			pE->pValue = NULL;
		}
	}
        
        return NONOS_RET_OK;
}

