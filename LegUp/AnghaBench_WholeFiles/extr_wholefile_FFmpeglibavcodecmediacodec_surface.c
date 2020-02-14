#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_5__   TYPE_1__ ;

/* Type definitions */
struct TYPE_5__ {int /*<<< orphan*/  (* DeleteGlobalRef ) (TYPE_1__**,void*) ;void* (* NewGlobalRef ) (TYPE_1__**,void*) ;} ;
typedef  TYPE_1__* JNIEnv ;

/* Variables and functions */
 int AVERROR_EXTERNAL ; 
 TYPE_1__** ff_jni_get_env (void*) ; 
 void* stub1 (TYPE_1__**,void*) ; 
 int /*<<< orphan*/  stub2 (TYPE_1__**,void*) ; 

void *ff_mediacodec_surface_ref(void *surface, void *log_ctx)
{
    JNIEnv *env = NULL;

    void *reference = NULL;

    env = ff_jni_get_env(log_ctx);
    if (!env) {
        return NULL;
    }

    reference = (*env)->NewGlobalRef(env, surface);

    return reference;
}

int ff_mediacodec_surface_unref(void *surface, void *log_ctx)
{
    JNIEnv *env = NULL;

    env = ff_jni_get_env(log_ctx);
    if (!env) {
        return AVERROR_EXTERNAL;
    }

    (*env)->DeleteGlobalRef(env, surface);

    return 0;
}

