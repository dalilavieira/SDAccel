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
typedef  int /*<<< orphan*/  pthread_mutex_t ;
struct TYPE_4__ {int /*<<< orphan*/ * nativeMutex_; } ;
struct TYPE_5__ {TYPE_1__ org_xmlvm_runtime_Mutex; } ;
struct TYPE_6__ {TYPE_2__ fields; } ;
typedef  TYPE_3__ org_xmlvm_runtime_Mutex ;
typedef  int /*<<< orphan*/ * JAVA_OBJECT ;

/* Variables and functions */
 int /*<<< orphan*/  XMLVM_FINALIZE (int /*<<< orphan*/ *,void (*) (void*,void*)) ; 
 int /*<<< orphan*/  free (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/ * malloc (int) ; 
 int /*<<< orphan*/  org_xmlvm_runtime_Mutex_addNativeMutexToFinalizerQueue___java_lang_Object (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  printf (char*,int) ; 
 int /*<<< orphan*/  pthread_mutex_destroy (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  pthread_mutex_init (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int pthread_mutex_lock (int /*<<< orphan*/ *) ; 
 int pthread_mutex_unlock (int /*<<< orphan*/ *) ; 

void nativeCleanup(void* me, void* client_data)
{
    JAVA_OBJECT m = ((org_xmlvm_runtime_Mutex*) me)->fields.org_xmlvm_runtime_Mutex.nativeMutex_;
    org_xmlvm_runtime_Mutex_addNativeMutexToFinalizerQueue___java_lang_Object(m);
}

void org_xmlvm_runtime_Mutex_destroyNativeMutex___java_lang_Object(JAVA_OBJECT n1)
{
    //XMLVM_BEGIN_NATIVE[org_xmlvm_runtime_Mutex_destroyNativeMutex___java_lang_Object]
    pthread_mutex_destroy(n1);
    free(n1);
    //XMLVM_END_NATIVE
}

void org_xmlvm_runtime_Mutex_initNativeInstance__(JAVA_OBJECT me)
{
    //XMLVM_BEGIN_NATIVE[org_xmlvm_runtime_Mutex_initNativeInstance__]
    pthread_mutex_t* m = malloc(sizeof(pthread_mutex_t));
    pthread_mutex_init(m, NULL);
    ((org_xmlvm_runtime_Mutex*) me)->fields.org_xmlvm_runtime_Mutex.nativeMutex_ = m;
    // Register a finalizer for native cleanup
    XMLVM_FINALIZE(me, nativeCleanup);
    //XMLVM_END_NATIVE
}

void org_xmlvm_runtime_Mutex_lock__(JAVA_OBJECT me)
{
    //XMLVM_BEGIN_NATIVE[org_xmlvm_runtime_Mutex_lock__]
    JAVA_OBJECT m = ((org_xmlvm_runtime_Mutex*) me)->fields.org_xmlvm_runtime_Mutex.nativeMutex_;
    int result = pthread_mutex_lock(m);
    if (result != 0) {
        printf("Error locking mutex! %i\n", result);
    }
    //XMLVM_END_NATIVE
}

void org_xmlvm_runtime_Mutex_unlock__(JAVA_OBJECT me)
{
    //XMLVM_BEGIN_NATIVE[org_xmlvm_runtime_Mutex_unlock__]
    JAVA_OBJECT m = ((org_xmlvm_runtime_Mutex*) me)->fields.org_xmlvm_runtime_Mutex.nativeMutex_;
    int result = pthread_mutex_unlock(m);
    if (result != 0) {
        printf("Error unlocking mutex! %i\n", result);
    }
    //XMLVM_END_NATIVE
}

void xmlvm_init_native_org_xmlvm_runtime_Mutex()
{
    //XMLVM_BEGIN_NATIVE_IMPLEMENTATION_INIT
    //XMLVM_END_NATIVE_IMPLEMENTATION_INIT
#ifdef XMLVM_VTABLE_IDX_org_xmlvm_runtime_Mutex_lock__
    __TIB_org_xmlvm_runtime_Mutex.vtable[XMLVM_VTABLE_IDX_org_xmlvm_runtime_Mutex_lock__] = 
        (VTABLE_PTR) org_xmlvm_runtime_Mutex_lock__;
#endif
#ifdef XMLVM_VTABLE_IDX_org_xmlvm_runtime_Mutex_unlock__
    __TIB_org_xmlvm_runtime_Mutex.vtable[XMLVM_VTABLE_IDX_org_xmlvm_runtime_Mutex_unlock__] = 
        (VTABLE_PTR) org_xmlvm_runtime_Mutex_unlock__;
#endif
}

