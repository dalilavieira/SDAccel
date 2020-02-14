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

/* Variables and functions */
 int /*<<< orphan*/  towlower (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  towupper (int /*<<< orphan*/ ) ; 

JAVA_INT java_lang_String_toLowerCaseImpl___int(JAVA_OBJECT me, JAVA_INT n1)
{
    //XMLVM_BEGIN_NATIVE[java_lang_String_toLowerCaseImpl___int]
#ifdef __EMSCRIPTEN__
	return tolower(n1);
#else
    return towlower(n1);
#endif
    //XMLVM_END_NATIVE
}

JAVA_INT java_lang_String_toUpperCaseImpl___int(JAVA_OBJECT me, JAVA_INT n1)
{
    //XMLVM_BEGIN_NATIVE[java_lang_String_toUpperCaseImpl___int]
#ifdef __EMSCRIPTEN__
	return toupper(n1);
#else
	return towupper(n1);
#endif
    //XMLVM_END_NATIVE
}

void xmlvm_init_native_java_lang_String()
{
    //XMLVM_BEGIN_NATIVE_IMPLEMENTATION_INIT
    //XMLVM_END_NATIVE_IMPLEMENTATION_INIT
#ifdef XMLVM_VTABLE_IDX_java_lang_String_toLowerCaseImpl___int
    __TIB_java_lang_String.vtable[XMLVM_VTABLE_IDX_java_lang_String_toLowerCaseImpl___int] = 
        (VTABLE_PTR) java_lang_String_toLowerCaseImpl___int;
#endif
#ifdef XMLVM_VTABLE_IDX_java_lang_String_toUpperCaseImpl___int
    __TIB_java_lang_String.vtable[XMLVM_VTABLE_IDX_java_lang_String_toUpperCaseImpl___int] = 
        (VTABLE_PTR) java_lang_String_toUpperCaseImpl___int;
#endif
}

