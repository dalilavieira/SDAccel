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
typedef  int /*<<< orphan*/  JAVA_OBJECT ;

/* Variables and functions */
 int /*<<< orphan*/  JAVA_NULL ; 
 int /*<<< orphan*/  XMLVM_UNIMPLEMENTED_NATIVE_METHOD () ; 
 int /*<<< orphan*/  printf (char*) ; 

JAVA_OBJECT java_lang_Throwable_fillInStackTrace__(JAVA_OBJECT me)
{
    //XMLVM_BEGIN_NATIVE[java_lang_Throwable_fillInStackTrace__]
#ifdef XMLVM_ENABLE_STACK_TRACES

    XMLVM_STACK_TRACE_CURRENT* threadStack = getCurrentStackTrace();
    int size = threadStack->stackSize;

    if (!__TIB_java_lang_StackTraceElement.classInitialized) __INIT_java_lang_StackTraceElement();
    JAVA_OBJECT array = XMLVMArray_createSingleDimension(__CLASS_java_lang_StackTraceElement, size);

    // Put the currentLocation at the beginning of the array
    ((JAVA_ARRAY_OBJECT*) (((org_xmlvm_runtime_XMLVMArray*) array)->fields.org_xmlvm_runtime_XMLVMArray.array_))[0] = createStackTraceElement(threadStack->topOfStack->currentLocation);

    XMLVM_STACK_TRACE_LINK* curLink = threadStack->topOfStack;
    for (int index = 1; index < size; index++) {
        java_lang_StackTraceElement* ste = createStackTraceElement(curLink->element);
        ((JAVA_ARRAY_OBJECT*) (((org_xmlvm_runtime_XMLVMArray*) array)->fields.org_xmlvm_runtime_XMLVMArray.array_))[index] = ste;
        curLink = curLink->nextLink;
    }

    ((java_lang_Throwable*) me)->fields.java_lang_Throwable.stackTrace_ = array;

    return me;
#else
    return JAVA_NULL;
#endif
    //XMLVM_END_NATIVE
}

JAVA_OBJECT java_lang_Throwable_getStackTraceImpl__(JAVA_OBJECT me)
{
    //XMLVM_BEGIN_NATIVE[java_lang_Throwable_getStackTraceImpl__]
#ifdef XMLVM_ENABLE_STACK_TRACES

    return ((java_lang_Throwable*) me)->fields.java_lang_Throwable.stackTrace_;

#else

// TODO throw RuntimeException with the following message instead of printf
    printf("Stack traces are not enabled natively! To enable stack traces, define XMLVM_ENABLE_STACK_TRACES. Keep in mind this will decrease performance!\n");
    XMLVM_UNIMPLEMENTED_NATIVE_METHOD();

#endif
    //XMLVM_END_NATIVE
}

void xmlvm_init_native_java_lang_Throwable()
{
    //XMLVM_BEGIN_NATIVE_IMPLEMENTATION_INIT
    //XMLVM_END_NATIVE_IMPLEMENTATION_INIT
#ifdef XMLVM_VTABLE_IDX_java_lang_Throwable_fillInStackTrace__
    __TIB_java_lang_Throwable.vtable[XMLVM_VTABLE_IDX_java_lang_Throwable_fillInStackTrace__] = 
        (VTABLE_PTR) java_lang_Throwable_fillInStackTrace__;
#endif
}

