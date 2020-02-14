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
typedef  int /*<<< orphan*/  JAVA_INT ;
typedef  int /*<<< orphan*/  JAVA_BOOLEAN ;

/* Variables and functions */
 int /*<<< orphan*/  XMLVM_UNIMPLEMENTED_NATIVE_METHOD () ; 

void java_lang_reflect_AccessibleObject_initializeClass___java_lang_Class(JAVA_OBJECT n1)
{
    //XMLVM_BEGIN_NATIVE[java_lang_reflect_AccessibleObject_initializeClass___java_lang_Class]
    XMLVM_UNIMPLEMENTED_NATIVE_METHOD();
    //XMLVM_END_NATIVE
}

JAVA_OBJECT java_lang_reflect_AccessibleObject_getStackClass___int(JAVA_INT n1)
{
    //XMLVM_BEGIN_NATIVE[java_lang_reflect_AccessibleObject_getStackClass___int]
    XMLVM_UNIMPLEMENTED_NATIVE_METHOD();
    //XMLVM_END_NATIVE
}

JAVA_OBJECT java_lang_reflect_AccessibleObject_getParameterTypesImpl__(JAVA_OBJECT me)
{
    //XMLVM_BEGIN_NATIVE[java_lang_reflect_AccessibleObject_getParameterTypesImpl__]
    XMLVM_UNIMPLEMENTED_NATIVE_METHOD();
    //XMLVM_END_NATIVE
}

JAVA_INT java_lang_reflect_AccessibleObject_getModifiers__(JAVA_OBJECT me)
{
    //XMLVM_BEGIN_NATIVE[java_lang_reflect_AccessibleObject_getModifiers__]
    XMLVM_UNIMPLEMENTED_NATIVE_METHOD();
    //XMLVM_END_NATIVE
}

JAVA_OBJECT java_lang_reflect_AccessibleObject_getExceptionTypesImpl__(JAVA_OBJECT me)
{
    //XMLVM_BEGIN_NATIVE[java_lang_reflect_AccessibleObject_getExceptionTypesImpl__]
    XMLVM_UNIMPLEMENTED_NATIVE_METHOD();
    //XMLVM_END_NATIVE
}

JAVA_OBJECT java_lang_reflect_AccessibleObject_getSignature__(JAVA_OBJECT me)
{
    //XMLVM_BEGIN_NATIVE[java_lang_reflect_AccessibleObject_getSignature__]
    XMLVM_UNIMPLEMENTED_NATIVE_METHOD();
    //XMLVM_END_NATIVE
}

JAVA_BOOLEAN java_lang_reflect_AccessibleObject_checkAccessibility___java_lang_Class_java_lang_Object(JAVA_OBJECT me, JAVA_OBJECT n1, JAVA_OBJECT n2)
{
    //XMLVM_BEGIN_NATIVE[java_lang_reflect_AccessibleObject_checkAccessibility___java_lang_Class_java_lang_Object]
    XMLVM_UNIMPLEMENTED_NATIVE_METHOD();
    //XMLVM_END_NATIVE
}

void xmlvm_init_native_java_lang_reflect_AccessibleObject()
{
    //XMLVM_BEGIN_NATIVE_IMPLEMENTATION_INIT
    //XMLVM_END_NATIVE_IMPLEMENTATION_INIT
#ifdef XMLVM_VTABLE_IDX_java_lang_reflect_AccessibleObject_getParameterTypesImpl__
    __TIB_java_lang_reflect_AccessibleObject.vtable[XMLVM_VTABLE_IDX_java_lang_reflect_AccessibleObject_getParameterTypesImpl__] = 
        (VTABLE_PTR) java_lang_reflect_AccessibleObject_getParameterTypesImpl__;
#endif
#ifdef XMLVM_VTABLE_IDX_java_lang_reflect_AccessibleObject_getModifiers__
    __TIB_java_lang_reflect_AccessibleObject.vtable[XMLVM_VTABLE_IDX_java_lang_reflect_AccessibleObject_getModifiers__] = 
        (VTABLE_PTR) java_lang_reflect_AccessibleObject_getModifiers__;
#endif
#ifdef XMLVM_VTABLE_IDX_java_lang_reflect_AccessibleObject_getExceptionTypesImpl__
    __TIB_java_lang_reflect_AccessibleObject.vtable[XMLVM_VTABLE_IDX_java_lang_reflect_AccessibleObject_getExceptionTypesImpl__] = 
        (VTABLE_PTR) java_lang_reflect_AccessibleObject_getExceptionTypesImpl__;
#endif
#ifdef XMLVM_VTABLE_IDX_java_lang_reflect_AccessibleObject_getSignature__
    __TIB_java_lang_reflect_AccessibleObject.vtable[XMLVM_VTABLE_IDX_java_lang_reflect_AccessibleObject_getSignature__] = 
        (VTABLE_PTR) java_lang_reflect_AccessibleObject_getSignature__;
#endif
#ifdef XMLVM_VTABLE_IDX_java_lang_reflect_AccessibleObject_checkAccessibility___java_lang_Class_java_lang_Object
    __TIB_java_lang_reflect_AccessibleObject.vtable[XMLVM_VTABLE_IDX_java_lang_reflect_AccessibleObject_checkAccessibility___java_lang_Class_java_lang_Object] = 
        (VTABLE_PTR) java_lang_reflect_AccessibleObject_checkAccessibility___java_lang_Class_java_lang_Object;
#endif
}

