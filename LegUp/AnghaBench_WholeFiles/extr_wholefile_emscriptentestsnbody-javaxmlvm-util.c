#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_10__   TYPE_5__ ;
typedef  struct TYPE_9__   TYPE_4__ ;
typedef  struct TYPE_8__   TYPE_3__ ;
typedef  struct TYPE_7__   TYPE_2__ ;
typedef  struct TYPE_6__   TYPE_1__ ;

/* Type definitions */
struct TYPE_7__ {int length_; scalar_t__ array_; } ;
struct TYPE_8__ {TYPE_2__ org_xmlvm_runtime_XMLVMArray; } ;
struct TYPE_9__ {TYPE_3__ fields; } ;
typedef  TYPE_4__ org_xmlvm_runtime_XMLVMArray ;
struct TYPE_10__ {TYPE_1__* tib; } ;
typedef  TYPE_5__ java_lang_Object ;
struct TYPE_6__ {scalar_t__** itableBegin; } ;
typedef  void* JAVA_OBJECT ;
typedef  int JAVA_INT ;
typedef  int /*<<< orphan*/  JAVA_BOOLEAN ;

/* Variables and functions */
 scalar_t__ JAVA_NULL ; 
 char* XMLVM_ATOMIC_MALLOC (int) ; 
 size_t XMLVM_ITABLE_IDX_java_util_Map_Entry_getKey__ ; 
 size_t XMLVM_ITABLE_IDX_java_util_Map_Entry_getValue__ ; 
 int /*<<< orphan*/  XMLVM_MEMCPY (char*,char*,int) ; 
 void* __NEW_java_util_ArrayList () ; 
 void* __NEW_java_util_HashMap () ; 
 void* __NEW_java_util_HashSet () ; 
 int /*<<< orphan*/  java_util_ArrayList___INIT___ (void*) ; 
 int /*<<< orphan*/  java_util_ArrayList_add___int_java_lang_Object (void*,int,void*) ; 
 int /*<<< orphan*/  java_util_ArrayList_add___java_lang_Object (void*,void*) ; 
 void* java_util_ArrayList_get___int (void*,int) ; 
 int java_util_ArrayList_indexOf___java_lang_Object (void*,void*) ; 
 int /*<<< orphan*/  java_util_ArrayList_remove___java_lang_Object (void*,void*) ; 
 int java_util_ArrayList_size__ (void*) ; 
 int /*<<< orphan*/  java_util_HashMap___INIT___ (void*) ; 
 void* java_util_HashMap_entrySet__ (void*) ; 
 void* java_util_HashMap_get___java_lang_Object (void*,void*) ; 
 void* java_util_HashMap_put___java_lang_Object_java_lang_Object (void*,void*,void*) ; 
 int /*<<< orphan*/  java_util_HashSet___INIT___ (void*) ; 
 int /*<<< orphan*/  java_util_HashSet_add___java_lang_Object (void*,void*) ; 
 int java_util_HashSet_iterator__ (void*) ; 
 scalar_t__ stringPool ; 
 void* stub1 (void*) ; 
 void* stub2 (void*) ; 

JAVA_OBJECT XMLVMUtil_NEW_ArrayList()
{
    JAVA_OBJECT obj = __NEW_java_util_ArrayList();
    java_util_ArrayList___INIT___(obj);
    return obj;
}

JAVA_INT XMLVMUtil_ArrayList_size(JAVA_OBJECT me)
{
#ifdef XMLVM_VTABLE_IDX_java_util_ArrayList_size__
    return (*(JAVA_INT (*)(JAVA_OBJECT)) ((java_util_ArrayList*) me)->
            tib->vtable[XMLVM_VTABLE_IDX_java_util_ArrayList_size__])(me);
#else
    return java_util_ArrayList_size__(me);
#endif
}

JAVA_BOOLEAN XMLVMUtil_ArrayList_add(JAVA_OBJECT me, JAVA_OBJECT obj)
{
#ifdef XMLVM_VTABLE_IDX_java_util_ArrayList_add___java_lang_Object
    return (*(JAVA_BOOLEAN (*)(JAVA_OBJECT, JAVA_OBJECT)) ((java_util_ArrayList*) me)->
            tib->vtable[XMLVM_VTABLE_IDX_java_util_ArrayList_add___java_lang_Object])(me, obj);
#else
    return java_util_ArrayList_add___java_lang_Object(me, obj);
#endif
}

void XMLVMUtil_ArrayList_addAt(JAVA_OBJECT me, JAVA_INT index, JAVA_OBJECT obj)
{
#ifdef XMLVM_VTABLE_IDX_java_util_ArrayList_add___int_java_lang_Object
    (*(JAVA_BOOLEAN (*)(JAVA_OBJECT, JAVA_INT, JAVA_OBJECT)) ((java_util_ArrayList*) me)->
            tib->vtable[XMLVM_VTABLE_IDX_java_util_ArrayList_add___int_java_lang_Object])(me, index, obj);
#else
    java_util_ArrayList_add___int_java_lang_Object(me, index, obj);
#endif
}

JAVA_OBJECT XMLVMUtil_ArrayList_get(JAVA_OBJECT me, JAVA_INT idx)
{
#ifdef XMLVM_VTABLE_IDX_java_util_ArrayList_get___int
    return (*(JAVA_OBJECT (*)(JAVA_OBJECT, JAVA_INT)) ((java_util_ArrayList*) me)->
            tib->vtable[XMLVM_VTABLE_IDX_java_util_ArrayList_get___int])(me, idx);
#else
    return java_util_ArrayList_get___int(me, idx);
#endif
}

JAVA_BOOLEAN XMLVMUtil_ArrayList_remove(JAVA_OBJECT me, JAVA_OBJECT obj)
{
#ifdef XMLVM_VTABLE_IDX_java_util_ArrayList_remove___java_lang_Object
    return (*(JAVA_BOOLEAN (*)(JAVA_OBJECT, JAVA_OBJECT)) ((java_util_ArrayList*) me)->
            tib->vtable[XMLVM_VTABLE_IDX_java_util_ArrayList_remove___java_lang_Object])(me, obj);
#else
    return java_util_ArrayList_remove___java_lang_Object(me, obj);
#endif
}

JAVA_INT XMLVMUtil_ArrayList_indexOf(JAVA_OBJECT me, JAVA_OBJECT obj)
{
#ifdef XMLVM_VTABLE_IDX_java_util_ArrayList_indexOf___java_lang_Object
    return (*(JAVA_INT (*)(JAVA_OBJECT, JAVA_OBJECT)) ((java_util_ArrayList*) me)->
            tib->vtable[XMLVM_VTABLE_IDX_java_util_ArrayList_indexOf___java_lang_Object])(me, obj);
#else
    return java_util_ArrayList_indexOf___java_lang_Object(me, obj);
#endif
}

JAVA_OBJECT XMLVMUtil_NEW_HashSet()
{
    JAVA_OBJECT obj = __NEW_java_util_HashSet();
    java_util_HashSet___INIT___(obj);
    return obj;
}

JAVA_BOOLEAN XMLVMUtil_HashSet_add(JAVA_OBJECT me, JAVA_OBJECT obj)
{
#ifdef XMLVM_VTABLE_IDX_java_util_HashSet_add___java_lang_Object
    return (*(JAVA_BOOLEAN (*)(JAVA_OBJECT, JAVA_OBJECT)) ((java_util_HashSet*) me)->
            tib->vtable[XMLVM_VTABLE_IDX_java_util_HashSet_add___java_lang_Object])(me, obj);
#else
    return java_util_HashSet_add___java_lang_Object(me, obj);
#endif
}

JAVA_INT XMLVMUtil_HashSet_iterator(JAVA_OBJECT me)
{
#ifdef XMLVM_VTABLE_IDX_java_util_HashSet_iterator__
    return (*(JAVA_INT (*)(JAVA_OBJECT)) ((java_util_HashSet*) me)->
            tib->vtable[XMLVM_ITABLE_IDX_java_util_Set_iterator__])(me);
#else
    return java_util_HashSet_iterator__(me);
#endif
}

JAVA_INT XMLVMUtil_Iterator_hasNext(JAVA_OBJECT me)
{
#ifdef XMLVM_VTABLE_IDX_java_util_Iterator_hasNext__
    return (*(JAVA_INT (*)(JAVA_OBJECT)) ((java_util_Iterator*) me)->
            tib->vtable[XMLVM_VTABLE_IDX_java_util_Iterator_hasNext__])(me);
#endif
}

JAVA_INT XMLVMUtil_Iterator_next(JAVA_OBJECT me)
{
#ifdef XMLVM_VTABLE_IDX_java_util_Iterator_next__
    return (*(JAVA_INT (*)(JAVA_OBJECT)) ((java_util_Iterator*) me)->
            tib->vtable[XMLVM_VTABLE_IDX_java_util_Iterator_next__])(me);
#endif
}

JAVA_OBJECT XMLVMUtil_NEW_HashMap()
{
    JAVA_OBJECT obj = __NEW_java_util_HashMap();
    java_util_HashMap___INIT___(obj);
    return obj;
}

JAVA_OBJECT XMLVMUtil_HashMap_put(JAVA_OBJECT me, JAVA_OBJECT key, JAVA_OBJECT value)
{
#ifdef XMLVM_VTABLE_IDX_java_util_HashMap_put___java_lang_Object_java_lang_Object
    return (*(JAVA_OBJECT (*)(JAVA_OBJECT, JAVA_OBJECT, JAVA_OBJECT)) ((java_util_HashMap*) me)->
            tib->vtable[XMLVM_VTABLE_IDX_java_util_HashMap_put___java_lang_Object_java_lang_Object])(me, key, value);
#else
    return java_util_HashMap_put___java_lang_Object_java_lang_Object(me, key, value);
#endif
}

JAVA_OBJECT XMLVMUtil_HashMap_get(JAVA_OBJECT me, JAVA_OBJECT key)
{
#ifdef XMLVM_VTABLE_IDX_java_util_HashMap_get___java_lang_Object
    return (*(JAVA_OBJECT (*)(JAVA_OBJECT, JAVA_OBJECT)) ((java_util_HashMap*) me)->
            tib->vtable[XMLVM_VTABLE_IDX_java_util_HashMap_get___java_lang_Object])(me, key);
#else
    return java_util_HashMap_get___java_lang_Object(me, key);
#endif
}

JAVA_OBJECT XMLVMUtil_HashMap_entrySet(JAVA_OBJECT me)
{
#ifdef XMLVM_VTABLE_IDX_java_util_HashMap_entrySet__
    return (*(JAVA_OBJECT (*)(JAVA_OBJECT)) ((java_util_HashMap*) me)->
            tib->vtable[XMLVM_VTABLE_IDX_java_util_HashMap_entrySet__])(me);
#else
	return java_util_HashMap_entrySet__(me);
#endif
}

JAVA_OBJECT XMLVMUtil_MapEntry_getKey(JAVA_OBJECT me)
{
    return (*(JAVA_OBJECT (*)(JAVA_OBJECT)) *(((java_lang_Object*) me)->
		    tib->itableBegin)[XMLVM_ITABLE_IDX_java_util_Map_Entry_getKey__])(me);
}

JAVA_OBJECT XMLVMUtil_MapEntry_getValue(JAVA_OBJECT me)
{
    return (*(JAVA_OBJECT (*)(JAVA_OBJECT)) *(((java_lang_Object*) me)->
			tib->itableBegin)[XMLVM_ITABLE_IDX_java_util_Map_Entry_getValue__])(me);
}

JAVA_OBJECT XMLVMUtil_getFromStringPool(JAVA_OBJECT str)
{
    if (stringPool == JAVA_NULL) {
        stringPool = XMLVMUtil_NEW_ArrayList();
    }
    JAVA_INT i = XMLVMUtil_ArrayList_indexOf(stringPool, str);
    if (i == -1) {
        XMLVMUtil_ArrayList_add(stringPool, str);
        return str;
    }
    return XMLVMUtil_ArrayList_get(stringPool, i);
}

char* XMLVMUtil_convertFromByteArray(JAVA_OBJECT byteArray) {
    org_xmlvm_runtime_XMLVMArray* a = byteArray;
    char* data = (char*) a->fields.org_xmlvm_runtime_XMLVMArray.array_;
    int length = a->fields.org_xmlvm_runtime_XMLVMArray.length_;
    char* buf = XMLVM_ATOMIC_MALLOC(length + 1);
    XMLVM_MEMCPY(buf, data, length);
    buf[length] = '\0';
    return buf;
}

