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
typedef  int JAVA_INT ;
typedef  void* JAVA_FLOAT ;

/* Variables and functions */
 scalar_t__ isnan (void*) ; 

JAVA_INT java_lang_Float_floatToIntBits___float(JAVA_FLOAT n1)
{
    //XMLVM_BEGIN_NATIVE[java_lang_Float_floatToIntBits___float]
    union {
        JAVA_FLOAT f;
        JAVA_INT   i;
    } u;
    
    if (isnan(n1)) {
        return 0x7fc00000;
    } else {
        u.f = n1;
        return u.i;
    }
    //XMLVM_END_NATIVE
}

JAVA_INT java_lang_Float_floatToRawIntBits___float(JAVA_FLOAT n1)
{
    //XMLVM_BEGIN_NATIVE[java_lang_Float_floatToRawIntBits___float]
    union {
        JAVA_FLOAT f;
        JAVA_INT   i;
    } u;
    
    u.f = n1;
    return u.i;
    //XMLVM_END_NATIVE
}

JAVA_FLOAT java_lang_Float_intBitsToFloat___int(JAVA_INT n1)
{
    //XMLVM_BEGIN_NATIVE[java_lang_Float_intBitsToFloat___int]
    union {
        JAVA_FLOAT f;
        JAVA_INT   i;
    } u;
    
    u.i = n1;
    return u.f;
    //XMLVM_END_NATIVE
}

