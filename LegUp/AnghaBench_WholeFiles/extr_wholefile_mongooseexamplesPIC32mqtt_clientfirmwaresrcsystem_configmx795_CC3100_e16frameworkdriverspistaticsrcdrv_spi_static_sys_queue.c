#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_14__   TYPE_5__ ;
typedef  struct TYPE_13__   TYPE_4__ ;
typedef  struct TYPE_12__   TYPE_3__ ;
typedef  struct TYPE_11__   TYPE_2__ ;
typedef  struct TYPE_10__   TYPE_1__ ;

/* Type definitions */
typedef  size_t uint8_t ;
typedef  scalar_t__ uint32_t ;
struct TYPE_14__ {struct TYPE_14__* pNext; } ;
struct TYPE_13__ {scalar_t__ type; int numQueues; int elementSize; size_t bufferLen; TYPE_3__* pBuffer; } ;
struct TYPE_12__ {scalar_t__ numReserved; scalar_t__ maxElements; scalar_t__ numAlloc; int /*<<< orphan*/  (* fptrIntChange ) (scalar_t__,int) ;struct TYPE_12__* pNext; TYPE_2__* pQueueManager; TYPE_5__* pHead; TYPE_5__* pTail; } ;
struct TYPE_11__ {size_t numFreeElements; scalar_t__ numReserveElements; TYPE_5__* pFreeElementTail; TYPE_5__* pFreeElementHead; TYPE_3__* pFreeQueueHead; TYPE_3__* pFreeQueueTail; TYPE_5__* pElementArea; TYPE_3__* pQueueArea; } ;
struct TYPE_10__ {scalar_t__ reserveElements; scalar_t__ maxElements; int /*<<< orphan*/  (* fptrIntChange ) (scalar_t__,int) ;} ;
typedef  int /*<<< orphan*/  DRV_SPI_SYS_QUEUE_STATUS ;
typedef  TYPE_1__ DRV_SPI_SYS_QUEUE_SETUP ;
typedef  scalar_t__ DRV_SPI_SYS_QUEUE_RESULT ;
typedef  TYPE_2__ DRV_SPI_SYS_QUEUE_QUEUE_MANAGER_DATA ;
typedef  TYPE_3__ DRV_SPI_SYS_QUEUE_QUEUE_DATA ;
typedef  int /*<<< orphan*/  DRV_SPI_SYS_QUEUE_MANAGER_STATUS ;
typedef  TYPE_4__ DRV_SPI_SYS_QUEUE_MANAGER_SETUP ;
typedef  scalar_t__ DRV_SPI_SYS_QUEUE_MANAGER_HANDLE ;
typedef  scalar_t__ DRV_SPI_SYS_QUEUE_HANDLE ;
typedef  TYPE_5__ DRV_SPI_SYS_QUEUE_FIFO_ELEMENT_DATA ;

/* Variables and functions */
 scalar_t__ DRV_SPI_SYS_QUEUE_Dequeue (scalar_t__,void**) ; 
 scalar_t__ DRV_SPI_SYS_QUEUE_Fifo ; 
 scalar_t__ DRV_SPI_SYS_QUEUE_FreeElement (scalar_t__,void*) ; 
 scalar_t__ DRV_SPI_SYS_QUEUE_INVALID_PARAMETER ; 
 scalar_t__ DRV_SPI_SYS_QUEUE_MAX_ERROR ; 
 scalar_t__ DRV_SPI_SYS_QUEUE_OUT_OF_MEMORY ; 
 scalar_t__ DRV_SPI_SYS_QUEUE_OUT_OF_QUEUES ; 
 scalar_t__ DRV_SPI_SYS_QUEUE_SUCCESS ; 
 scalar_t__ _DRV_SPI_SYS_QUEUE_LockQueue (scalar_t__,int) ; 
 scalar_t__ _DRV_SPI_SYS_QUEUE_LockQueueManager (scalar_t__) ; 
 scalar_t__ _DRV_SPI_SYS_QUEUE_UnlockQueue (scalar_t__,int) ; 
 scalar_t__ _DRV_SPI_SYS_QUEUE_UnlockQueueManager (scalar_t__) ; 
 int /*<<< orphan*/  memset (TYPE_3__*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  stub1 (scalar_t__,int) ; 
 int /*<<< orphan*/  stub2 (scalar_t__,int) ; 

DRV_SPI_SYS_QUEUE_RESULT DRV_SPI_SYS_QUEUE_Initialize(DRV_SPI_SYS_QUEUE_MANAGER_SETUP * initParams, DRV_SPI_SYS_QUEUE_MANAGER_HANDLE * handle)
{
    if (initParams == NULL || initParams->pBuffer == NULL || handle == NULL)
    {
        return DRV_SPI_SYS_QUEUE_INVALID_PARAMETER;
    }

    if (initParams->type != DRV_SPI_SYS_QUEUE_Fifo)
    {
        return DRV_SPI_SYS_QUEUE_INVALID_PARAMETER;
    }

    size_t sizeNeeded = (sizeof(DRV_SPI_SYS_QUEUE_QUEUE_DATA) *
                        initParams->numQueues) +
                        sizeof(DRV_SPI_SYS_QUEUE_QUEUE_MANAGER_DATA) +
                        (sizeof(DRV_SPI_SYS_QUEUE_FIFO_ELEMENT_DATA) +
                        initParams->elementSize);

    if (initParams->bufferLen < sizeNeeded)
    {
        return DRV_SPI_SYS_QUEUE_OUT_OF_MEMORY;
    }

    // Blank the memory area
    memset(initParams->pBuffer, 0, initParams->bufferLen);

    // Set up the Queue Manager Area
    DRV_SPI_SYS_QUEUE_QUEUE_MANAGER_DATA * pQueueManager = (DRV_SPI_SYS_QUEUE_QUEUE_MANAGER_DATA *)initParams->pBuffer;
    pQueueManager->pQueueArea  = (DRV_SPI_SYS_QUEUE_QUEUE_DATA*)((uint32_t)pQueueManager + sizeof(DRV_SPI_SYS_QUEUE_QUEUE_MANAGER_DATA));
    pQueueManager->pElementArea  = (DRV_SPI_SYS_QUEUE_FIFO_ELEMENT_DATA*)((uint32_t)pQueueManager->pQueueArea + (sizeof(DRV_SPI_SYS_QUEUE_QUEUE_DATA) * initParams->numQueues) );

    //Set up the Queue Handles
    DRV_SPI_SYS_QUEUE_QUEUE_DATA * pQueue = pQueueManager->pQueueArea;
    pQueueManager->pFreeQueueHead = pQueue;
    pQueueManager->pFreeQueueTail = pQueue;
    pQueue->pQueueManager = pQueueManager;
    uint8_t counter;
    for (counter = 1; counter < initParams->numQueues; counter++)
    {
        pQueueManager->pFreeQueueTail->pNext = &(pQueue[counter]);
        pQueueManager->pFreeQueueTail = &(pQueue[counter]);
        pQueue[counter].pQueueManager = pQueueManager;
    }

    // Set up the elements
    size_t spaceRemaining = initParams->bufferLen -
            sizeof(DRV_SPI_SYS_QUEUE_QUEUE_MANAGER_DATA) -
            (sizeof(DRV_SPI_SYS_QUEUE_QUEUE_DATA) * initParams->numQueues);
    size_t numberOfElements = spaceRemaining /
            (sizeof(DRV_SPI_SYS_QUEUE_FIFO_ELEMENT_DATA) + initParams->elementSize );

    DRV_SPI_SYS_QUEUE_FIFO_ELEMENT_DATA * pElement = pQueueManager->pElementArea;
    pQueueManager->pFreeElementHead = pElement;
    pQueueManager->pFreeElementTail = pElement;

    for (counter = 1; counter < numberOfElements; counter ++)
    {
        pElement = (DRV_SPI_SYS_QUEUE_FIFO_ELEMENT_DATA *)
              ((uint32_t)pQueueManager->pElementArea +
               (sizeof(DRV_SPI_SYS_QUEUE_FIFO_ELEMENT_DATA) +
                initParams->elementSize) *
               counter);
        pQueueManager->pFreeElementTail->pNext = pElement;
        pQueueManager->pFreeElementTail = pElement;
    }
    pQueueManager->numFreeElements = numberOfElements;
#if _SPI_DRV_SYS_QUEUE_TRACKING
    pQueueManager->freeElementsLW = numberOfElements;
#endif
    *handle = (DRV_SPI_SYS_QUEUE_MANAGER_HANDLE)pQueueManager;
    return DRV_SPI_SYS_QUEUE_SUCCESS;
}

DRV_SPI_SYS_QUEUE_RESULT DRV_SPI_SYS_QUEUE_Deinitialize(DRV_SPI_SYS_QUEUE_MANAGER_HANDLE queueManager)
{
    if ((queueManager <= 0) && (queueManager >= DRV_SPI_SYS_QUEUE_MAX_ERROR))
    {
        return DRV_SPI_SYS_QUEUE_INVALID_PARAMETER;
    }
    return DRV_SPI_SYS_QUEUE_SUCCESS;
}

DRV_SPI_SYS_QUEUE_RESULT DRV_SPI_SYS_QUEUE_CreateQueue(DRV_SPI_SYS_QUEUE_MANAGER_HANDLE queueManager, DRV_SPI_SYS_QUEUE_SETUP * initParams, DRV_SPI_SYS_QUEUE_HANDLE * handle)
{
    if ((queueManager <= 0) && (queueManager >= DRV_SPI_SYS_QUEUE_MAX_ERROR))
    {
        return DRV_SPI_SYS_QUEUE_INVALID_PARAMETER;
    }
    DRV_SPI_SYS_QUEUE_QUEUE_MANAGER_DATA * pQueueManager = (DRV_SPI_SYS_QUEUE_QUEUE_MANAGER_DATA *)queueManager;
    if (initParams == NULL)
    {
        return DRV_SPI_SYS_QUEUE_INVALID_PARAMETER;
    }
    if (pQueueManager->pFreeQueueHead == NULL)
    {
        return DRV_SPI_SYS_QUEUE_OUT_OF_QUEUES;
    }

    if ((pQueueManager->numReserveElements + initParams->reserveElements) > pQueueManager->numFreeElements)
    {
        return DRV_SPI_SYS_QUEUE_OUT_OF_MEMORY;
    }

    DRV_SPI_SYS_QUEUE_QUEUE_DATA * pQueue = pQueueManager->pFreeQueueHead;
    pQueueManager->pFreeQueueHead = pQueue->pNext;
    if (pQueueManager->pFreeQueueHead == NULL)
    {
        pQueueManager->pFreeQueueTail = NULL;
    }
    memset(pQueue, 0, sizeof(DRV_SPI_SYS_QUEUE_QUEUE_DATA));
    pQueue->pQueueManager = pQueueManager;

    pQueue->fptrIntChange = initParams->fptrIntChange;
    pQueue->numReserved = initParams->reserveElements;
    pQueue->maxElements = initParams->maxElements;

    pQueueManager->numReserveElements += initParams->reserveElements;

#if _SPI_DRV_SYS_QUEUE_TRACKING
    pQueueManager->numQueueCreateOps++;
    pQueueManager->numQueues++;
    pQueueManager->reserveElementsLW += initParams->reserveElements;
    if (pQueueManager->numQueues > pQueueManager->numQueuesHW)
    {
        pQueueManager->numQueuesHW = pQueueManager->numQueues;
    }
#endif

   *handle =  (DRV_SPI_SYS_QUEUE_HANDLE)pQueue;
   return DRV_SPI_SYS_QUEUE_SUCCESS;
}

DRV_SPI_SYS_QUEUE_RESULT DRV_SPI_SYS_QUEUE_DestroyQueue(DRV_SPI_SYS_QUEUE_HANDLE queue)
{
    if ((queue <= 0) && (queue >= DRV_SPI_SYS_QUEUE_MAX_ERROR))
    {
        return DRV_SPI_SYS_QUEUE_INVALID_PARAMETER;
    }

    DRV_SPI_SYS_QUEUE_QUEUE_DATA * pQueue = (DRV_SPI_SYS_QUEUE_QUEUE_DATA *)queue;
    DRV_SPI_SYS_QUEUE_QUEUE_MANAGER_DATA * pQueueManager = pQueue->pQueueManager;

    if (pQueue->pNext != NULL)
    {
        return DRV_SPI_SYS_QUEUE_INVALID_PARAMETER;
    }


    void * pElement = NULL;
    DRV_SPI_SYS_QUEUE_Dequeue(queue, &pElement);
    while (pElement != NULL)
    {
        DRV_SPI_SYS_QUEUE_FreeElement(queue, pElement);
        DRV_SPI_SYS_QUEUE_Dequeue(queue, &pElement);
    }

    pQueueManager->numReserveElements -= pQueue->numReserved;
    if (pQueueManager->pFreeQueueTail == NULL)
    {
        pQueueManager->pFreeQueueTail = pQueue;
        pQueueManager->pFreeQueueHead = pQueue;
    }
    else
    {
        pQueue->pNext = pQueueManager->pFreeQueueHead;
        pQueueManager->pFreeQueueHead = pQueue;
    }

#if _SPI_DRV_SYS_QUEUE_TRACKING
    pQueueManager->numQueueDestroyOps++;
    pQueueManager->numQueues--;
    pQueueManager->reserveElementsLW -= pQueueManager->numReserveElements;
#endif

    return DRV_SPI_SYS_QUEUE_SUCCESS;
}

DRV_SPI_SYS_QUEUE_RESULT DRV_SPI_SYS_QUEUE_AllocElement(DRV_SPI_SYS_QUEUE_HANDLE queue, void ** element)
{
    if (element == NULL)
    {
        return DRV_SPI_SYS_QUEUE_INVALID_PARAMETER;
    }
    if ((queue <= 0) && (queue >= DRV_SPI_SYS_QUEUE_MAX_ERROR))
    {
        return DRV_SPI_SYS_QUEUE_INVALID_PARAMETER;
    }

    DRV_SPI_SYS_QUEUE_QUEUE_DATA * pQueue = (DRV_SPI_SYS_QUEUE_QUEUE_DATA *)queue;
    DRV_SPI_SYS_QUEUE_QUEUE_MANAGER_DATA * pQueueManager = pQueue->pQueueManager;

    if (pQueue->pNext != NULL)
    {
        return DRV_SPI_SYS_QUEUE_INVALID_PARAMETER;
    }

    if (pQueueManager->pFreeElementHead== NULL)
    {
#if _SPI_DRV_SYS_QUEUE_TRACKING
        pQueueManager->outOfMemoryErrors++;
        pQueue->outOfMemoryErrors++;
#endif
        return DRV_SPI_SYS_QUEUE_OUT_OF_MEMORY;
    }

    if (pQueue->numAlloc == pQueue->maxElements)
    {
#if _SPI_DRV_SYS_QUEUE_TRACKING
        pQueueManager->outOfMemoryErrors++;
        pQueue->outOfMemoryErrors++;
#endif
        return DRV_SPI_SYS_QUEUE_OUT_OF_MEMORY;
    }

    if (pQueue->numAlloc < pQueue->numReserved)
    {
        pQueueManager->numReserveElements--;
    }
    else if (pQueueManager->numFreeElements == pQueueManager->numReserveElements)
    {
#if _SPI_DRV_SYS_QUEUE_TRACKING
        pQueueManager->outOfMemoryErrors++;
        pQueue->outOfMemoryErrors++;
#endif
        return DRV_SPI_SYS_QUEUE_OUT_OF_MEMORY;
    }

    DRV_SPI_SYS_QUEUE_FIFO_ELEMENT_DATA * pEntry = pQueueManager->pFreeElementHead;
    pQueueManager->pFreeElementHead = pEntry->pNext;
    if (pQueueManager->pFreeElementHead == NULL)
    {
        pQueueManager->pFreeElementTail = NULL;
    }
    pEntry->pNext = NULL;
    pQueueManager->numFreeElements --;
    pQueue->numAlloc++;

#if _SPI_DRV_SYS_QUEUE_TRACKING
    pQueue->numAllocOps ++;
    pQueueManager->numAllocOps ++;
    if (pQueueManager->numFreeElements < pQueueManager->freeElementsLW)
    {
        pQueueManager->freeElementsLW = pQueueManager->numFreeElements;
    }
    if (pQueueManager->numReserveElements < pQueueManager->reserveElementsLW)
    {
        pQueueManager->reserveElementsLW = pQueueManager->numReserveElements;
    }
    if (pQueue->numAlloc > pQueue->numAllocHW)
    {
        pQueue->numAllocHW = pQueue->numAlloc;
    }
#endif
    *element = (void *)((uint32_t)pEntry + sizeof(DRV_SPI_SYS_QUEUE_FIFO_ELEMENT_DATA));
    return DRV_SPI_SYS_QUEUE_SUCCESS;
}

DRV_SPI_SYS_QUEUE_RESULT DRV_SPI_SYS_QUEUE_FreeElement(DRV_SPI_SYS_QUEUE_HANDLE queue, void * element)
{
    if ((queue <= 0) && (queue >= DRV_SPI_SYS_QUEUE_MAX_ERROR))
    {
        return DRV_SPI_SYS_QUEUE_INVALID_PARAMETER;
    }

    DRV_SPI_SYS_QUEUE_QUEUE_DATA * pQueue = (DRV_SPI_SYS_QUEUE_QUEUE_DATA *)queue;
    DRV_SPI_SYS_QUEUE_QUEUE_MANAGER_DATA * pQueueManager = pQueue->pQueueManager;

    if (pQueue->pNext != NULL)
    {
        return DRV_SPI_SYS_QUEUE_INVALID_PARAMETER;
    }

    DRV_SPI_SYS_QUEUE_FIFO_ELEMENT_DATA * pEntry = (DRV_SPI_SYS_QUEUE_FIFO_ELEMENT_DATA *)((uint32_t)element - sizeof(DRV_SPI_SYS_QUEUE_FIFO_ELEMENT_DATA));

    if (pQueueManager->pFreeElementHead == NULL)
    {
        pQueueManager->pFreeElementHead = pEntry;
    }
    else
    {
        pQueueManager->pFreeElementTail->pNext = pEntry;
    }
    pQueueManager->pFreeElementTail = pEntry;

    pQueueManager->numFreeElements++;
    pQueue->numAlloc--;
    if (pQueue->numAlloc < pQueue->numReserved)
    {
        pQueueManager->numReserveElements++;
    }

#if _SPI_DRV_SYS_QUEUE_TRACKING
    pQueue->numFreeOps ++;
    pQueueManager->numFreeOps ++;
#endif
    return DRV_SPI_SYS_QUEUE_SUCCESS;
}

DRV_SPI_SYS_QUEUE_RESULT DRV_SPI_SYS_QUEUE_Enqueue(DRV_SPI_SYS_QUEUE_HANDLE queue, void * element)
{
    if ((queue <= 0) && (queue >= DRV_SPI_SYS_QUEUE_MAX_ERROR))
    {
        return DRV_SPI_SYS_QUEUE_INVALID_PARAMETER;
    }

    DRV_SPI_SYS_QUEUE_QUEUE_DATA * pQueue = (DRV_SPI_SYS_QUEUE_QUEUE_DATA *)queue;

    if (pQueue->pNext != NULL)
    {
        return DRV_SPI_SYS_QUEUE_INVALID_PARAMETER;
    }

    DRV_SPI_SYS_QUEUE_FIFO_ELEMENT_DATA * pEntry = (DRV_SPI_SYS_QUEUE_FIFO_ELEMENT_DATA *)((uint32_t)element - sizeof(DRV_SPI_SYS_QUEUE_FIFO_ELEMENT_DATA));

    if (pQueue->pHead == NULL)
    {
        pQueue->pHead = pEntry;
        pQueue->pTail = pEntry;
    }
    else
    {
        pQueue->pTail->pNext = pEntry;
        pQueue->pTail = pEntry;
    }

#if _SPI_DRV_SYS_QUEUE_TRACKING
    pQueue->numEnqueued++;
    if (pQueue->numEnqueued > pQueue->numEnqueuedHW)
    {
        pQueue->numEnqueuedHW = pQueue->numEnqueued;
    }
    pQueue->numEnqueueOps++;
#endif
    return DRV_SPI_SYS_QUEUE_SUCCESS;
}

DRV_SPI_SYS_QUEUE_RESULT DRV_SPI_SYS_QUEUE_Dequeue(DRV_SPI_SYS_QUEUE_HANDLE queue, void ** element)
{
    if (element == NULL)
    {
        return DRV_SPI_SYS_QUEUE_INVALID_PARAMETER;
    }
    if ((queue <= 0) && (queue >= DRV_SPI_SYS_QUEUE_MAX_ERROR))
    {
        return DRV_SPI_SYS_QUEUE_INVALID_PARAMETER;
    }

    DRV_SPI_SYS_QUEUE_QUEUE_DATA * pQueue = (DRV_SPI_SYS_QUEUE_QUEUE_DATA *)queue;

    if (pQueue->pNext != NULL)
    {
        return DRV_SPI_SYS_QUEUE_INVALID_PARAMETER;
    }
    if (pQueue->pHead == NULL)
    {
        *element = NULL;
        return DRV_SPI_SYS_QUEUE_SUCCESS;
    }
    DRV_SPI_SYS_QUEUE_FIFO_ELEMENT_DATA * pEntry = pQueue->pHead;
    pQueue->pHead = pEntry->pNext;
    if (pQueue->pHead == NULL)
    {
        pQueue->pTail = NULL;
    }

    pEntry->pNext = NULL;

#if _SPI_DRV_SYS_QUEUE_TRACKING
    pQueue->numEnqueued--;
    pQueue->numDequeueOps++;
#endif
    *element = (void *)((uint32_t)pEntry + sizeof(DRV_SPI_SYS_QUEUE_FIFO_ELEMENT_DATA));
    return DRV_SPI_SYS_QUEUE_SUCCESS;
}

DRV_SPI_SYS_QUEUE_RESULT DRV_SPI_SYS_QUEUE_Peek(DRV_SPI_SYS_QUEUE_HANDLE queue, void ** element)
{
    if (element == NULL)
    {
        return DRV_SPI_SYS_QUEUE_INVALID_PARAMETER;
    }
    if ((queue <= 0) && (queue >= DRV_SPI_SYS_QUEUE_MAX_ERROR))
    {
        return DRV_SPI_SYS_QUEUE_INVALID_PARAMETER;
    }

    DRV_SPI_SYS_QUEUE_QUEUE_DATA * pQueue = (DRV_SPI_SYS_QUEUE_QUEUE_DATA *)queue;

    if (pQueue->pNext != NULL)
    {
        return DRV_SPI_SYS_QUEUE_INVALID_PARAMETER;
    }
    if (pQueue->pHead == NULL)
    {
        *element = NULL;
    }
    DRV_SPI_SYS_QUEUE_FIFO_ELEMENT_DATA * pEntry = pQueue->pHead;
    *element = (void *)((uint32_t)pEntry + sizeof(DRV_SPI_SYS_QUEUE_FIFO_ELEMENT_DATA));
    return DRV_SPI_SYS_QUEUE_SUCCESS;
}

bool DRV_SPI_SYS_QUEUE_IsEmpty(DRV_SPI_SYS_QUEUE_HANDLE queue)
{
    DRV_SPI_SYS_QUEUE_QUEUE_DATA * pQueue = (DRV_SPI_SYS_QUEUE_QUEUE_DATA *)queue;
    return pQueue->pHead == NULL;
}

DRV_SPI_SYS_QUEUE_RESULT DRV_SPI_SYS_QUEUE_Lock(DRV_SPI_SYS_QUEUE_HANDLE queue)
{

    return _DRV_SPI_SYS_QUEUE_LockQueue(queue, false);
}

DRV_SPI_SYS_QUEUE_RESULT DRV_SPI_SYS_QUEUE_Unlock(DRV_SPI_SYS_QUEUE_HANDLE queue)
{
    return _DRV_SPI_SYS_QUEUE_UnlockQueue(queue, false);
}

DRV_SPI_SYS_QUEUE_RESULT _DRV_SPI_SYS_QUEUE_LockQueue(DRV_SPI_SYS_QUEUE_HANDLE queue, bool freeList)
{
    if ((queue <= 0) && (queue >= DRV_SPI_SYS_QUEUE_MAX_ERROR))
    {
        return DRV_SPI_SYS_QUEUE_INVALID_PARAMETER;
    }

    DRV_SPI_SYS_QUEUE_QUEUE_DATA * pQueue = (DRV_SPI_SYS_QUEUE_QUEUE_DATA *)queue;
    DRV_SPI_SYS_QUEUE_QUEUE_MANAGER_DATA * pQueueManager = pQueue->pQueueManager;

    if (pQueue->pNext != NULL)
    {
        return DRV_SPI_SYS_QUEUE_INVALID_PARAMETER;
    }

    if (freeList)
    {
        return _DRV_SPI_SYS_QUEUE_LockQueueManager((DRV_SPI_SYS_QUEUE_MANAGER_HANDLE)pQueueManager);
    }
    else
    {
        if (pQueue->fptrIntChange != NULL)
        {
            (*pQueue->fptrIntChange)(queue, true);
        }
    }

    return DRV_SPI_SYS_QUEUE_SUCCESS;
}

DRV_SPI_SYS_QUEUE_RESULT _DRV_SPI_SYS_QUEUE_UnlockQueue(DRV_SPI_SYS_QUEUE_HANDLE queue, bool freeList)
{
    if ((queue <= 0) && (queue >= DRV_SPI_SYS_QUEUE_MAX_ERROR))
    {
        return DRV_SPI_SYS_QUEUE_INVALID_PARAMETER;
    }

    DRV_SPI_SYS_QUEUE_QUEUE_DATA * pQueue = (DRV_SPI_SYS_QUEUE_QUEUE_DATA *)queue;
    DRV_SPI_SYS_QUEUE_QUEUE_MANAGER_DATA * pQueueManager = pQueue->pQueueManager;

    if (pQueue->pNext != NULL)
    {
        return DRV_SPI_SYS_QUEUE_INVALID_PARAMETER;
    }

    if (freeList)
    {
        return _DRV_SPI_SYS_QUEUE_UnlockQueueManager((DRV_SPI_SYS_QUEUE_MANAGER_HANDLE)pQueueManager);
    }
    else
    {
        if (pQueue->fptrIntChange != NULL)
        {
            (*pQueue->fptrIntChange)(queue, false);
        }
    }

    return DRV_SPI_SYS_QUEUE_SUCCESS;
}

DRV_SPI_SYS_QUEUE_HANDLE DRV_SPI_SYS_QUEUE_CreateQueueLock(DRV_SPI_SYS_QUEUE_MANAGER_HANDLE queueManager, DRV_SPI_SYS_QUEUE_SETUP * initParams, DRV_SPI_SYS_QUEUE_HANDLE * queue)
{
    DRV_SPI_SYS_QUEUE_RESULT ret;
    DRV_SPI_SYS_QUEUE_HANDLE  ret2;
    ret = _DRV_SPI_SYS_QUEUE_LockQueueManager(queueManager);
    if (ret != DRV_SPI_SYS_QUEUE_SUCCESS)
    {
        return ret;
    }

    ret2 = DRV_SPI_SYS_QUEUE_CreateQueue(queueManager, initParams, queue);

    ret = _DRV_SPI_SYS_QUEUE_UnlockQueueManager(queueManager);
    if (ret != DRV_SPI_SYS_QUEUE_SUCCESS)
    {
        return ret;
    }
    return ret2;
}

DRV_SPI_SYS_QUEUE_RESULT DRV_SPI_SYS_QUEUE_DestroyQueueLock(DRV_SPI_SYS_QUEUE_HANDLE queue)
{
    DRV_SPI_SYS_QUEUE_RESULT ret;
    DRV_SPI_SYS_QUEUE_RESULT  ret2;
    ret = _DRV_SPI_SYS_QUEUE_LockQueue(queue, true);// TODO!!! Fix this
    if (ret != DRV_SPI_SYS_QUEUE_SUCCESS)
    {
        return ret;
    }

    ret2 = DRV_SPI_SYS_QUEUE_DestroyQueue(queue);

    ret = _DRV_SPI_SYS_QUEUE_UnlockQueue(queue, true);
    if (ret != DRV_SPI_SYS_QUEUE_SUCCESS)
    {
        return ret;
    }
    return ret2;
}

DRV_SPI_SYS_QUEUE_RESULT DRV_SPI_SYS_QUEUE_AllocElementLock(DRV_SPI_SYS_QUEUE_HANDLE queue, void  ** element)
{
    DRV_SPI_SYS_QUEUE_RESULT ret;
    DRV_SPI_SYS_QUEUE_RESULT ret2;
    ret = _DRV_SPI_SYS_QUEUE_LockQueue(queue, true);
    if (ret != DRV_SPI_SYS_QUEUE_SUCCESS)
    {
        return ret;
    }

    ret2 = DRV_SPI_SYS_QUEUE_AllocElement(queue, element);

    ret = _DRV_SPI_SYS_QUEUE_UnlockQueue(queue, true);
    if (ret != DRV_SPI_SYS_QUEUE_SUCCESS)
    {
        return ret;
    }
    return ret2;
}

DRV_SPI_SYS_QUEUE_RESULT DRV_SPI_SYS_QUEUE_FreeElementLock(DRV_SPI_SYS_QUEUE_HANDLE queue, void * element)
{
    DRV_SPI_SYS_QUEUE_RESULT ret;
    DRV_SPI_SYS_QUEUE_RESULT  ret2;
    ret = _DRV_SPI_SYS_QUEUE_LockQueue(queue, true);
    if (ret != DRV_SPI_SYS_QUEUE_SUCCESS)
    {
        return ret;
    }

    ret2 = DRV_SPI_SYS_QUEUE_FreeElement(queue, element);

    ret = _DRV_SPI_SYS_QUEUE_UnlockQueue(queue, true);
    if (ret != DRV_SPI_SYS_QUEUE_SUCCESS)
    {
        return ret;
    }
    return ret2;
}

DRV_SPI_SYS_QUEUE_RESULT DRV_SPI_SYS_QUEUE_EnqueueLock(DRV_SPI_SYS_QUEUE_HANDLE queue, void * element)
{
    DRV_SPI_SYS_QUEUE_RESULT ret;
    DRV_SPI_SYS_QUEUE_RESULT  ret2;
    ret = _DRV_SPI_SYS_QUEUE_LockQueue(queue, false);
    if (ret != DRV_SPI_SYS_QUEUE_SUCCESS)
    {
        return ret;
    }

    ret2 = DRV_SPI_SYS_QUEUE_Enqueue(queue, element);

    ret = _DRV_SPI_SYS_QUEUE_UnlockQueue(queue, false);
    if (ret != DRV_SPI_SYS_QUEUE_SUCCESS)
    {
        return ret;
    }
    return ret2;
}

DRV_SPI_SYS_QUEUE_RESULT DRV_SPI_SYS_QUEUE_DequeueLock(DRV_SPI_SYS_QUEUE_HANDLE queue, void ** element)
{
    DRV_SPI_SYS_QUEUE_RESULT ret;
    DRV_SPI_SYS_QUEUE_RESULT  ret2;
    ret = _DRV_SPI_SYS_QUEUE_LockQueue(queue, false);
    if (ret != DRV_SPI_SYS_QUEUE_SUCCESS)
    {
        return ret;
    }

    ret2 = DRV_SPI_SYS_QUEUE_Dequeue(queue, element);

    ret = _DRV_SPI_SYS_QUEUE_UnlockQueue(queue, false);
    if (ret != DRV_SPI_SYS_QUEUE_SUCCESS)
    {
        return ret;
    }
    return ret2;
}

DRV_SPI_SYS_QUEUE_RESULT DRV_SPI_SYS_QUEUE_QueueManagerStatus(DRV_SPI_SYS_QUEUE_MANAGER_HANDLE queueManager, DRV_SPI_SYS_QUEUE_MANAGER_STATUS * status)
{
#if _SPI_DRV_SYS_QUEUE_TRACKING
    if ((queueManager <= 0) && (queueManager >= DRV_SPI_SYS_QUEUE_MAX_ERROR))
    {
        return DRV_SPI_SYS_QUEUE_INVALID_PARAMETER;
    }
    DRV_SPI_SYS_QUEUE_QUEUE_MANAGER_DATA * pQueueManager = (DRV_SPI_SYS_QUEUE_QUEUE_MANAGER_DATA *)queueManager;

    status->numAllocOps = pQueueManager->numAllocOps;
    status->numFreeOps = pQueueManager->numFreeOps;
    status->numQueueCreateOps = pQueueManager->numQueueCreateOps;
    status->numQueueDestroyOps = pQueueManager->numQueueDestroyOps;
    status->numReserveElements = pQueueManager->numReserveElements;
    status->numFreeElements = pQueueManager->numFreeElements;
    status->freeElementsLW = pQueueManager->freeElementsLW;
    status->reserveElementsLW = pQueueManager->reserveElementsLW;
    status->outOfMemoryErrors = pQueueManager->outOfMemoryErrors;
    status->numQueues = pQueueManager->numQueues;
    status->numQueuesHW = pQueueManager->numQueuesHW;
    return DRV_SPI_SYS_QUEUE_SUCCESS;
#else
    return DRV_SPI_SYS_QUEUE_INVALID_PARAMETER;
#endif
}

DRV_SPI_SYS_QUEUE_RESULT DRV_SPI_SYS_QUEUE_QueueStatus(DRV_SPI_SYS_QUEUE_HANDLE queue, DRV_SPI_SYS_QUEUE_STATUS * status)
{
#if _SPI_DRV_SYS_QUEUE_TRACKING
    if ((queue <= 0) && (queue >= DRV_SPI_SYS_QUEUE_MAX_ERROR))
    {
        return DRV_SPI_SYS_QUEUE_INVALID_PARAMETER;
    }

    DRV_SPI_SYS_QUEUE_QUEUE_DATA * pQueue = (DRV_SPI_SYS_QUEUE_QUEUE_DATA *)queue;

    if (pQueue->pNext != NULL)
    {
        return DRV_SPI_SYS_QUEUE_INVALID_PARAMETER;
    }
    if (status == NULL)
    {
        return DRV_SPI_SYS_QUEUE_INVALID_PARAMETER;
    }

    status->numAllocOps = pQueue->numAllocOps;
    status->numFreeOps = pQueue->numFreeOps;
    status->numDequeueOps = pQueue->numDequeueOps;
    status->numEnqueueOps = pQueue->numEnqueueOps;
    status->numReserved = pQueue->numReserved;
    status->numAlloc = pQueue->numAlloc;
    status->numEnqueued = pQueue->numEnqueued;
    status->numReserveLW = pQueue->numReserveLW;
    status->numAllocHW = pQueue->numAllocHW;
    status->numEnqueuedHW = pQueue->numEnqueuedHW;
    return DRV_SPI_SYS_QUEUE_SUCCESS;
#else
    return DRV_SPI_SYS_QUEUE_INVALID_PARAMETER;
#endif

}

DRV_SPI_SYS_QUEUE_RESULT _DRV_SPI_SYS_QUEUE_LockQueueManager(DRV_SPI_SYS_QUEUE_MANAGER_HANDLE queueManager)
{
    return DRV_SPI_SYS_QUEUE_SUCCESS;
}

DRV_SPI_SYS_QUEUE_RESULT _DRV_SPI_SYS_QUEUE_UnlockQueueManager(DRV_SPI_SYS_QUEUE_MANAGER_HANDLE queueManager)
{
    return DRV_SPI_SYS_QUEUE_SUCCESS;
}

