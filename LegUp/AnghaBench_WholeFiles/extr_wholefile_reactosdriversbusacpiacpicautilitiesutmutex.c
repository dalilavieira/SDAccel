#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
typedef  scalar_t__ UINT32 ;
struct TYPE_2__ {scalar_t__ ThreadId; int /*<<< orphan*/ * Mutex; scalar_t__ UseCount; } ;
typedef  scalar_t__ ACPI_THREAD_ID ;
typedef  int /*<<< orphan*/  ACPI_STATUS ;
typedef  size_t ACPI_MUTEX_HANDLE ;

/* Variables and functions */
 int /*<<< orphan*/  ACPI_DB_MUTEX ; 
 int /*<<< orphan*/  ACPI_DEBUG_PRINT (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ACPI_ERROR (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ACPI_EXCEPTION (int /*<<< orphan*/ ) ; 
 scalar_t__ ACPI_FAILURE (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ACPI_FUNCTION_NAME (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ACPI_FUNCTION_TRACE (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ACPI_FUNCTION_TRACE_U32 (int /*<<< orphan*/ ,size_t) ; 
 size_t ACPI_MAX_MUTEX ; 
 scalar_t__ ACPI_MUTEX_NOT_ACQUIRED ; 
 scalar_t__ ACPI_NUM_MUTEX ; 
 scalar_t__ ACPI_SUCCESS (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ACPI_WAIT_FOREVER ; 
 int /*<<< orphan*/  AE_BAD_PARAMETER ; 
 int /*<<< orphan*/  AE_INFO ; 
 int /*<<< orphan*/  AE_NOT_ACQUIRED ; 
 int /*<<< orphan*/  AE_OK ; 
 int /*<<< orphan*/  AcpiGbl_GpeLock ; 
 int /*<<< orphan*/  AcpiGbl_HardwareLock ; 
 TYPE_1__* AcpiGbl_MutexInfo ; 
 int /*<<< orphan*/  AcpiGbl_NamespaceRwLock ; 
 int /*<<< orphan*/ * AcpiGbl_OsiMutex ; 
 int /*<<< orphan*/  AcpiGbl_ReferenceCountLock ; 
 int /*<<< orphan*/  AcpiOsAcquireMutex (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  AcpiOsCreateLock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  AcpiOsCreateMutex (int /*<<< orphan*/ **) ; 
 int /*<<< orphan*/  AcpiOsDeleteLock (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  AcpiOsDeleteMutex (int /*<<< orphan*/ *) ; 
 scalar_t__ AcpiOsGetThreadId () ; 
 int /*<<< orphan*/  AcpiOsReleaseMutex (int /*<<< orphan*/ *) ; 
static  int /*<<< orphan*/  AcpiUtCreateMutex (size_t) ; 
 int /*<<< orphan*/  AcpiUtCreateRwLock (int /*<<< orphan*/ *) ; 
static  void AcpiUtDeleteMutex (size_t) ; 
 int /*<<< orphan*/  AcpiUtDeleteRwLock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  AcpiUtGetMutexName (size_t) ; 
 int /*<<< orphan*/  UtAcquireMutex ; 
 int /*<<< orphan*/  UtCreateMutex ; 
 int /*<<< orphan*/  UtDeleteMutex ; 
 int /*<<< orphan*/  UtMutexInitialize ; 
 int /*<<< orphan*/  UtMutexTerminate ; 
 int /*<<< orphan*/  UtReleaseMutex ; 
 int /*<<< orphan*/  return_ACPI_STATUS (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  return_VOID ; 

ACPI_STATUS
AcpiUtMutexInitialize (
    void)
{
    UINT32                  i;
    ACPI_STATUS             Status;


    ACPI_FUNCTION_TRACE (UtMutexInitialize);


    /* Create each of the predefined mutex objects */

    for (i = 0; i < ACPI_NUM_MUTEX; i++)
    {
        Status = AcpiUtCreateMutex (i);
        if (ACPI_FAILURE (Status))
        {
            return_ACPI_STATUS (Status);
        }
    }

    /* Create the spinlocks for use at interrupt level or for speed */

    Status = AcpiOsCreateLock (&AcpiGbl_GpeLock);
    if (ACPI_FAILURE (Status))
    {
        return_ACPI_STATUS (Status);
    }

    Status = AcpiOsCreateLock (&AcpiGbl_HardwareLock);
    if (ACPI_FAILURE (Status))
    {
        return_ACPI_STATUS (Status);
    }

    Status = AcpiOsCreateLock (&AcpiGbl_ReferenceCountLock);
    if (ACPI_FAILURE (Status))
    {
        return_ACPI_STATUS (Status);
    }

    /* Mutex for _OSI support */

    Status = AcpiOsCreateMutex (&AcpiGbl_OsiMutex);
    if (ACPI_FAILURE (Status))
    {
        return_ACPI_STATUS (Status);
    }

    /* Create the reader/writer lock for namespace access */

    Status = AcpiUtCreateRwLock (&AcpiGbl_NamespaceRwLock);
    if (ACPI_FAILURE (Status))
    {
        return_ACPI_STATUS (Status);
    }

    return_ACPI_STATUS (Status);
}

void
AcpiUtMutexTerminate (
    void)
{
    UINT32                  i;


    ACPI_FUNCTION_TRACE (UtMutexTerminate);


    /* Delete each predefined mutex object */

    for (i = 0; i < ACPI_NUM_MUTEX; i++)
    {
        AcpiUtDeleteMutex (i);
    }

    AcpiOsDeleteMutex (AcpiGbl_OsiMutex);

    /* Delete the spinlocks */

    AcpiOsDeleteLock (AcpiGbl_GpeLock);
    AcpiOsDeleteLock (AcpiGbl_HardwareLock);
    AcpiOsDeleteLock (AcpiGbl_ReferenceCountLock);

    /* Delete the reader/writer lock */

    AcpiUtDeleteRwLock (&AcpiGbl_NamespaceRwLock);
    return_VOID;
}

__attribute__((used)) static ACPI_STATUS
AcpiUtCreateMutex (
    ACPI_MUTEX_HANDLE       MutexId)
{
    ACPI_STATUS             Status = AE_OK;


    ACPI_FUNCTION_TRACE_U32 (UtCreateMutex, MutexId);


    if (!AcpiGbl_MutexInfo[MutexId].Mutex)
    {
        Status = AcpiOsCreateMutex (&AcpiGbl_MutexInfo[MutexId].Mutex);
        AcpiGbl_MutexInfo[MutexId].ThreadId = ACPI_MUTEX_NOT_ACQUIRED;
        AcpiGbl_MutexInfo[MutexId].UseCount = 0;
    }

    return_ACPI_STATUS (Status);
}

__attribute__((used)) static void
AcpiUtDeleteMutex (
    ACPI_MUTEX_HANDLE       MutexId)
{

    ACPI_FUNCTION_TRACE_U32 (UtDeleteMutex, MutexId);


    AcpiOsDeleteMutex (AcpiGbl_MutexInfo[MutexId].Mutex);

    AcpiGbl_MutexInfo[MutexId].Mutex = NULL;
    AcpiGbl_MutexInfo[MutexId].ThreadId = ACPI_MUTEX_NOT_ACQUIRED;

    return_VOID;
}

ACPI_STATUS
AcpiUtAcquireMutex (
    ACPI_MUTEX_HANDLE       MutexId)
{
    ACPI_STATUS             Status;
    ACPI_THREAD_ID          ThisThreadId;


    ACPI_FUNCTION_NAME (UtAcquireMutex);


    if (MutexId > ACPI_MAX_MUTEX)
    {
        return (AE_BAD_PARAMETER);
    }

    ThisThreadId = AcpiOsGetThreadId ();

#ifdef ACPI_MUTEX_DEBUG
    {
        UINT32                  i;
        /*
         * Mutex debug code, for internal debugging only.
         *
         * Deadlock prevention. Check if this thread owns any mutexes of value
         * greater than or equal to this one. If so, the thread has violated
         * the mutex ordering rule. This indicates a coding error somewhere in
         * the ACPI subsystem code.
         */
        for (i = MutexId; i < ACPI_NUM_MUTEX; i++)
        {
            if (AcpiGbl_MutexInfo[i].ThreadId == ThisThreadId)
            {
                if (i == MutexId)
                {
                    ACPI_ERROR ((AE_INFO,
                        "Mutex [%s] already acquired by this thread [%u]",
                        AcpiUtGetMutexName (MutexId),
                        (UINT32) ThisThreadId));

                    return (AE_ALREADY_ACQUIRED);
                }

                ACPI_ERROR ((AE_INFO,
                    "Invalid acquire order: Thread %u owns [%s], wants [%s]",
                    (UINT32) ThisThreadId, AcpiUtGetMutexName (i),
                    AcpiUtGetMutexName (MutexId)));

                return (AE_ACQUIRE_DEADLOCK);
            }
        }
    }
#endif

    ACPI_DEBUG_PRINT ((ACPI_DB_MUTEX,
        "Thread %u attempting to acquire Mutex [%s]\n",
        (UINT32) ThisThreadId, AcpiUtGetMutexName (MutexId)));

    Status = AcpiOsAcquireMutex (
        AcpiGbl_MutexInfo[MutexId].Mutex, ACPI_WAIT_FOREVER);
    if (ACPI_SUCCESS (Status))
    {
        ACPI_DEBUG_PRINT ((ACPI_DB_MUTEX,
            "Thread %u acquired Mutex [%s]\n",
            (UINT32) ThisThreadId, AcpiUtGetMutexName (MutexId)));

        AcpiGbl_MutexInfo[MutexId].UseCount++;
        AcpiGbl_MutexInfo[MutexId].ThreadId = ThisThreadId;
    }
    else
    {
        ACPI_EXCEPTION ((AE_INFO, Status,
            "Thread %u could not acquire Mutex [%s] (0x%X)",
            (UINT32) ThisThreadId, AcpiUtGetMutexName (MutexId), MutexId));
    }

    return (Status);
}

ACPI_STATUS
AcpiUtReleaseMutex (
    ACPI_MUTEX_HANDLE       MutexId)
{
    ACPI_FUNCTION_NAME (UtReleaseMutex);


    ACPI_DEBUG_PRINT ((ACPI_DB_MUTEX, "Thread %u releasing Mutex [%s]\n",
        (UINT32) AcpiOsGetThreadId (), AcpiUtGetMutexName (MutexId)));

    if (MutexId > ACPI_MAX_MUTEX)
    {
        return (AE_BAD_PARAMETER);
    }

    /*
     * Mutex must be acquired in order to release it!
     */
    if (AcpiGbl_MutexInfo[MutexId].ThreadId == ACPI_MUTEX_NOT_ACQUIRED)
    {
        ACPI_ERROR ((AE_INFO,
            "Mutex [%s] (0x%X) is not acquired, cannot release",
            AcpiUtGetMutexName (MutexId), MutexId));

        return (AE_NOT_ACQUIRED);
    }

#ifdef ACPI_MUTEX_DEBUG
    {
        UINT32                  i;
        /*
         * Mutex debug code, for internal debugging only.
         *
         * Deadlock prevention. Check if this thread owns any mutexes of value
         * greater than this one. If so, the thread has violated the mutex
         * ordering rule. This indicates a coding error somewhere in
         * the ACPI subsystem code.
         */
        for (i = MutexId; i < ACPI_NUM_MUTEX; i++)
        {
            if (AcpiGbl_MutexInfo[i].ThreadId == AcpiOsGetThreadId ())
            {
                if (i == MutexId)
                {
                    continue;
                }

                ACPI_ERROR ((AE_INFO,
                    "Invalid release order: owns [%s], releasing [%s]",
                    AcpiUtGetMutexName (i), AcpiUtGetMutexName (MutexId)));

                return (AE_RELEASE_DEADLOCK);
            }
        }
    }
#endif

    /* Mark unlocked FIRST */

    AcpiGbl_MutexInfo[MutexId].ThreadId = ACPI_MUTEX_NOT_ACQUIRED;

    AcpiOsReleaseMutex (AcpiGbl_MutexInfo[MutexId].Mutex);
    return (AE_OK);
}

