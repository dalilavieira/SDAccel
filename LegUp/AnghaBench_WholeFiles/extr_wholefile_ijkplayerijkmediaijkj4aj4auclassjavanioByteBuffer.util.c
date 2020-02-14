#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_10__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  uint8_t ;
typedef  int /*<<< orphan*/  jobject ;
struct TYPE_10__ {void* (* GetDirectBufferAddress ) (TYPE_1__**,int /*<<< orphan*/ ) ;} ;
typedef  TYPE_1__* JNIEnv ;

/* Variables and functions */
 int /*<<< orphan*/  J4AC_java_nio_ByteBuffer__limit (TYPE_1__**,int /*<<< orphan*/ ,size_t) ; 
 int /*<<< orphan*/  J4A_DeleteLocalRef__p (TYPE_1__**,int /*<<< orphan*/ *) ; 
 scalar_t__ J4A_ExceptionCheck__catchAll (TYPE_1__**) ; 
 int /*<<< orphan*/  memcpy (int /*<<< orphan*/ *,void*,size_t) ; 
 void* stub1 (TYPE_1__**,int /*<<< orphan*/ ) ; 
 void* stub2 (TYPE_1__**,int /*<<< orphan*/ ) ; 

void *J4AC_java_nio_ByteBuffer__getDirectBufferAddress(JNIEnv *env, jobject thiz)
{
    return (*env)->GetDirectBufferAddress(env, thiz);
}

void *J4AC_java_nio_ByteBuffer__getDirectBufferAddress__catchAll(JNIEnv *env, jobject thiz)
{
    void *ret = (*env)->GetDirectBufferAddress(env, thiz);
    if (J4A_ExceptionCheck__catchAll(env) || !ret)
        return NULL;

    return ret;
}

int J4AC_java_nio_ByteBuffer__assignData__catchAll(JNIEnv *env, jobject thiz, void* data, size_t size)
{
    jobject buffer = J4AC_java_nio_ByteBuffer__limit(env, thiz, size);
    if (J4A_ExceptionCheck__catchAll(env) || !buffer)
        return -1;
    J4A_DeleteLocalRef__p(env, &buffer);

    uint8_t *c_buffer = J4AC_java_nio_ByteBuffer__getDirectBufferAddress__catchAll(env, thiz);
    if (!c_buffer)
        return -1;

    memcpy(c_buffer, data, size);
    return 0;
}

