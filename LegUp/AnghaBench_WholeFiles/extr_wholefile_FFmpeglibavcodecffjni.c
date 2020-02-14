#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_65__   TYPE_29__ ;
typedef  struct TYPE_64__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  uint8_t ;
struct FFJniField {int mandatory; int type; int offset; char* method; char* signature; scalar_t__ name; } ;
typedef  int /*<<< orphan*/ * jthrowable ;
typedef  int /*<<< orphan*/ * jstring ;
typedef  int /*<<< orphan*/ * jmethodID ;
typedef  int /*<<< orphan*/ * jfieldID ;
typedef  int /*<<< orphan*/ * jclass ;
typedef  int /*<<< orphan*/  jboolean ;
typedef  enum FFJniFieldType { ____Placeholder_FFJniFieldType } FFJniFieldType ;
struct TYPE_65__ {int (* GetEnv ) (TYPE_29__**,void**,int /*<<< orphan*/ ) ;int /*<<< orphan*/  (* AttachCurrentThread ) (TYPE_29__**,TYPE_1__***,int /*<<< orphan*/ *) ;int /*<<< orphan*/  (* DetachCurrentThread ) (TYPE_29__**) ;} ;
struct TYPE_64__ {char* (* GetStringUTFChars ) (TYPE_1__**,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ;int /*<<< orphan*/  (* DeleteLocalRef ) (TYPE_1__**,int /*<<< orphan*/ *) ;int /*<<< orphan*/  (* DeleteGlobalRef ) (TYPE_1__**,int /*<<< orphan*/ *) ;int /*<<< orphan*/ * (* GetStaticMethodID ) (TYPE_1__**,int /*<<< orphan*/ *,char*,char*) ;int /*<<< orphan*/ * (* GetMethodID ) (TYPE_1__**,int /*<<< orphan*/ *,char*,char*) ;int /*<<< orphan*/ * (* GetStaticFieldID ) (TYPE_1__**,int /*<<< orphan*/ *,char*,char*) ;int /*<<< orphan*/ * (* GetFieldID ) (TYPE_1__**,int /*<<< orphan*/ *,char*,char*) ;int /*<<< orphan*/ * (* NewGlobalRef ) (TYPE_1__**,int /*<<< orphan*/ *) ;int /*<<< orphan*/ * (* FindClass ) (TYPE_1__**,scalar_t__) ;int /*<<< orphan*/  (* ExceptionClear ) (TYPE_1__**) ;int /*<<< orphan*/ * (* ExceptionOccurred ) (TYPE_1__**) ;scalar_t__ (* ExceptionCheck ) (TYPE_1__**) ;int /*<<< orphan*/ * (* CallObjectMethod ) (TYPE_1__**,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ;int /*<<< orphan*/ * (* GetObjectClass ) (TYPE_1__**,int /*<<< orphan*/ *) ;int /*<<< orphan*/ * (* NewStringUTF ) (TYPE_1__**,char const*) ;int /*<<< orphan*/  (* ReleaseStringUTFChars ) (TYPE_1__**,int /*<<< orphan*/ *,char const*) ;} ;
typedef  TYPE_1__* JNIEnv ;
typedef  int /*<<< orphan*/  AVBPrint ;

/* Variables and functions */
 int AVERROR (int /*<<< orphan*/ ) ; 
 int AVERROR_EXTERNAL ; 
 int /*<<< orphan*/  AV_BPRINT_SIZE_AUTOMATIC ; 
 int /*<<< orphan*/  AV_LOG_ERROR ; 
 int /*<<< orphan*/  AV_LOG_WARNING ; 
 int /*<<< orphan*/  EINVAL ; 
#define  FF_JNI_CLASS 135 
#define  FF_JNI_FIELD 134 
#define  FF_JNI_METHOD 133 
#define  FF_JNI_STATIC_FIELD 132 
#define  FF_JNI_STATIC_METHOD 131 
#define  JNI_EDETACHED 130 
#define  JNI_EVERSION 129 
#define  JNI_OK 128 
 int /*<<< orphan*/  JNI_VERSION_1_6 ; 
 int av_bprint_finalize (int /*<<< orphan*/ *,char**) ; 
 int /*<<< orphan*/  av_bprint_init (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  av_bprintf (int /*<<< orphan*/ *,char*,...) ; 
 int /*<<< orphan*/  av_free (char*) ; 
 TYPE_29__** av_jni_get_java_vm (void*) ; 
 int /*<<< orphan*/  av_log (void*,int /*<<< orphan*/ ,char*,...) ; 
 char* av_strdup (char const*) ; 
 int /*<<< orphan*/  current_env ; 
 int ff_jni_reset_jfields (TYPE_1__**,void*,struct FFJniField const*,int,void*) ; 
 TYPE_29__** java_vm ; 
 int /*<<< orphan*/  lock ; 
 int /*<<< orphan*/  once ; 
 TYPE_1__** pthread_getspecific (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  pthread_key_create (int /*<<< orphan*/ *,void (*) (void*)) ; 
 int /*<<< orphan*/  pthread_mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  pthread_mutex_unlock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  pthread_once (int /*<<< orphan*/ *,void (*) ()) ; 
 int /*<<< orphan*/  pthread_setspecific (int /*<<< orphan*/ ,TYPE_1__**) ; 
 int /*<<< orphan*/  stub1 (TYPE_29__**) ; 
 int /*<<< orphan*/ * stub10 (TYPE_1__**,char const*) ; 
 scalar_t__ stub11 (TYPE_1__**) ; 
 int /*<<< orphan*/  stub12 (TYPE_1__**) ; 
 int /*<<< orphan*/ * stub13 (TYPE_1__**,int /*<<< orphan*/ *) ; 
 scalar_t__ stub14 (TYPE_1__**) ; 
 int /*<<< orphan*/  stub15 (TYPE_1__**) ; 
 int /*<<< orphan*/ * stub16 (TYPE_1__**,int /*<<< orphan*/ *) ; 
 scalar_t__ stub17 (TYPE_1__**) ; 
 int /*<<< orphan*/  stub18 (TYPE_1__**) ; 
 int /*<<< orphan*/ * stub19 (TYPE_1__**,int /*<<< orphan*/ *,char*,char*) ; 
 int stub2 (TYPE_29__**,void**,int /*<<< orphan*/ ) ; 
 scalar_t__ stub20 (TYPE_1__**) ; 
 int /*<<< orphan*/  stub21 (TYPE_1__**) ; 
 int /*<<< orphan*/ * stub22 (TYPE_1__**,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 scalar_t__ stub23 (TYPE_1__**) ; 
 int /*<<< orphan*/  stub24 (TYPE_1__**) ; 
 int /*<<< orphan*/  stub25 (TYPE_1__**,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/ * stub26 (TYPE_1__**,int /*<<< orphan*/ *,char*,char*) ; 
 scalar_t__ stub27 (TYPE_1__**) ; 
 int /*<<< orphan*/  stub28 (TYPE_1__**) ; 
 int /*<<< orphan*/ * stub29 (TYPE_1__**,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  stub3 (TYPE_29__**,TYPE_1__***,int /*<<< orphan*/ *) ; 
 scalar_t__ stub30 (TYPE_1__**) ; 
 int /*<<< orphan*/  stub31 (TYPE_1__**) ; 
 int /*<<< orphan*/  stub32 (TYPE_1__**,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  stub33 (TYPE_1__**,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  stub34 (TYPE_1__**,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  stub35 (TYPE_1__**,int /*<<< orphan*/ *) ; 
 scalar_t__ stub36 (TYPE_1__**) ; 
 int /*<<< orphan*/  stub37 (TYPE_1__**) ; 
 int /*<<< orphan*/ * stub38 (TYPE_1__**) ; 
 int /*<<< orphan*/  stub39 (TYPE_1__**) ; 
 char* stub4 (TYPE_1__**,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  stub40 (TYPE_1__**,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  stub41 (TYPE_1__**,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/ * stub42 (TYPE_1__**,scalar_t__) ; 
 int /*<<< orphan*/ * stub43 (TYPE_1__**,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  stub44 (TYPE_1__**,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/ * stub45 (TYPE_1__**,int /*<<< orphan*/ *,char*,char*) ; 
 int /*<<< orphan*/ * stub46 (TYPE_1__**,int /*<<< orphan*/ *,char*,char*) ; 
 int /*<<< orphan*/ * stub47 (TYPE_1__**,int /*<<< orphan*/ *,char*,char*) ; 
 int /*<<< orphan*/ * stub48 (TYPE_1__**,int /*<<< orphan*/ *,char*,char*) ; 
 int /*<<< orphan*/  stub49 (TYPE_1__**,int /*<<< orphan*/ *) ; 
 scalar_t__ stub5 (TYPE_1__**) ; 
 int /*<<< orphan*/  stub50 (TYPE_1__**,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  stub6 (TYPE_1__**) ; 
 int /*<<< orphan*/  stub7 (TYPE_1__**,int /*<<< orphan*/ *,char const*) ; 
 scalar_t__ stub8 (TYPE_1__**) ; 
 int /*<<< orphan*/  stub9 (TYPE_1__**) ; 

__attribute__((used)) static void jni_detach_env(void *data)
{
    if (java_vm) {
        (*java_vm)->DetachCurrentThread(java_vm);
    }
}

__attribute__((used)) static void jni_create_pthread_key(void)
{
    pthread_key_create(&current_env, jni_detach_env);
}

JNIEnv *ff_jni_get_env(void *log_ctx)
{
    int ret = 0;
    JNIEnv *env = NULL;

    pthread_mutex_lock(&lock);
    if (java_vm == NULL) {
        java_vm = av_jni_get_java_vm(log_ctx);
    }

    if (!java_vm) {
        av_log(log_ctx, AV_LOG_ERROR, "No Java virtual machine has been registered\n");
        goto done;
    }

    pthread_once(&once, jni_create_pthread_key);

    if ((env = pthread_getspecific(current_env)) != NULL) {
        goto done;
    }

    ret = (*java_vm)->GetEnv(java_vm, (void **)&env, JNI_VERSION_1_6);
    switch(ret) {
    case JNI_EDETACHED:
        if ((*java_vm)->AttachCurrentThread(java_vm, &env, NULL) != 0) {
            av_log(log_ctx, AV_LOG_ERROR, "Failed to attach the JNI environment to the current thread\n");
            env = NULL;
        } else {
            pthread_setspecific(current_env, env);
        }
        break;
    case JNI_OK:
        break;
    case JNI_EVERSION:
        av_log(log_ctx, AV_LOG_ERROR, "The specified JNI version is not supported\n");
        break;
    default:
        av_log(log_ctx, AV_LOG_ERROR, "Failed to get the JNI environment attached to this thread\n");
        break;
    }

done:
    pthread_mutex_unlock(&lock);
    return env;
}

char *ff_jni_jstring_to_utf_chars(JNIEnv *env, jstring string, void *log_ctx)
{
    char *ret = NULL;
    const char *utf_chars = NULL;

    jboolean copy = 0;

    if (!string) {
        return NULL;
    }

    utf_chars = (*env)->GetStringUTFChars(env, string, &copy);
    if ((*env)->ExceptionCheck(env)) {
        (*env)->ExceptionClear(env);
        av_log(log_ctx, AV_LOG_ERROR, "String.getStringUTFChars() threw an exception\n");
        return NULL;
    }

    ret = av_strdup(utf_chars);

    (*env)->ReleaseStringUTFChars(env, string, utf_chars);
    if ((*env)->ExceptionCheck(env)) {
        (*env)->ExceptionClear(env);
        av_log(log_ctx, AV_LOG_ERROR, "String.releaseStringUTFChars() threw an exception\n");
        return NULL;
    }

    return ret;
}

jstring ff_jni_utf_chars_to_jstring(JNIEnv *env, const char *utf_chars, void *log_ctx)
{
    jstring ret;

    ret = (*env)->NewStringUTF(env, utf_chars);
    if ((*env)->ExceptionCheck(env)) {
        (*env)->ExceptionClear(env);
        av_log(log_ctx, AV_LOG_ERROR, "NewStringUTF() threw an exception\n");
        return NULL;
    }

    return ret;
}

int ff_jni_exception_get_summary(JNIEnv *env, jthrowable exception, char **error, void *log_ctx)
{
    int ret = 0;

    AVBPrint bp;

    char *name = NULL;
    char *message = NULL;

    jclass class_class = NULL;
    jmethodID get_name_id = NULL;

    jclass exception_class = NULL;
    jmethodID get_message_id = NULL;

    jstring string = NULL;

    av_bprint_init(&bp, 0, AV_BPRINT_SIZE_AUTOMATIC);

    exception_class = (*env)->GetObjectClass(env, exception);
    if ((*env)->ExceptionCheck(env)) {
        (*env)->ExceptionClear(env);
        av_log(log_ctx, AV_LOG_ERROR, "Could not find Throwable class\n");
        ret = AVERROR_EXTERNAL;
        goto done;
    }

    class_class = (*env)->GetObjectClass(env, exception_class);
    if ((*env)->ExceptionCheck(env)) {
        (*env)->ExceptionClear(env);
        av_log(log_ctx, AV_LOG_ERROR, "Could not find Throwable class's class\n");
        ret = AVERROR_EXTERNAL;
        goto done;
    }

    get_name_id = (*env)->GetMethodID(env, class_class, "getName", "()Ljava/lang/String;");
    if ((*env)->ExceptionCheck(env)) {
        (*env)->ExceptionClear(env);
        av_log(log_ctx, AV_LOG_ERROR, "Could not find method Class.getName()\n");
        ret = AVERROR_EXTERNAL;
        goto done;
    }

    string = (*env)->CallObjectMethod(env, exception_class, get_name_id);
    if ((*env)->ExceptionCheck(env)) {
        (*env)->ExceptionClear(env);
        av_log(log_ctx, AV_LOG_ERROR, "Class.getName() threw an exception\n");
        ret = AVERROR_EXTERNAL;
        goto done;
    }

    if (string) {
        name = ff_jni_jstring_to_utf_chars(env, string, log_ctx);
        (*env)->DeleteLocalRef(env, string);
        string = NULL;
    }

    get_message_id = (*env)->GetMethodID(env, exception_class, "getMessage", "()Ljava/lang/String;");
    if ((*env)->ExceptionCheck(env)) {
        (*env)->ExceptionClear(env);
        av_log(log_ctx, AV_LOG_ERROR, "Could not find method java/lang/Throwable.getMessage()\n");
        ret = AVERROR_EXTERNAL;
        goto done;
    }

    string = (*env)->CallObjectMethod(env, exception, get_message_id);
    if ((*env)->ExceptionCheck(env)) {
        (*env)->ExceptionClear(env);
        av_log(log_ctx, AV_LOG_ERROR, "Throwable.getMessage() threw an exception\n");
        ret = AVERROR_EXTERNAL;
        goto done;
    }

    if (string) {
        message = ff_jni_jstring_to_utf_chars(env, string, log_ctx);
        (*env)->DeleteLocalRef(env, string);
        string = NULL;
    }

    if (name && message) {
        av_bprintf(&bp, "%s: %s", name, message);
    } else if (name && !message) {
        av_bprintf(&bp, "%s occurred", name);
    } else if (!name && message) {
        av_bprintf(&bp, "Exception: %s", message);
    } else {
        av_log(log_ctx, AV_LOG_WARNING, "Could not retrieve exception name and message\n");
        av_bprintf(&bp, "Exception occurred");
    }

    ret = av_bprint_finalize(&bp, error);
done:

    av_free(name);
    av_free(message);

    if (class_class) {
        (*env)->DeleteLocalRef(env, class_class);
    }

    if (exception_class) {
        (*env)->DeleteLocalRef(env, exception_class);
    }

    if (string) {
        (*env)->DeleteLocalRef(env, string);
    }

    return ret;
}

int ff_jni_exception_check(JNIEnv *env, int log, void *log_ctx)
{
    int ret;

    jthrowable exception;

    char *message = NULL;

    if (!(*(env))->ExceptionCheck((env))) {
        return 0;
    }

    if (!log) {
        (*(env))->ExceptionClear((env));
        return -1;
    }

    exception = (*env)->ExceptionOccurred(env);
    (*(env))->ExceptionClear((env));

    if ((ret = ff_jni_exception_get_summary(env, exception, &message, log_ctx)) < 0) {
        (*env)->DeleteLocalRef(env, exception);
        return ret;
    }

    (*env)->DeleteLocalRef(env, exception);

    av_log(log_ctx, AV_LOG_ERROR, "%s\n", message);
    av_free(message);

    return -1;
}

int ff_jni_init_jfields(JNIEnv *env, void *jfields, const struct FFJniField *jfields_mapping, int global, void *log_ctx)
{
    int i, ret = 0;
    jclass last_clazz = NULL;

    for (i = 0; jfields_mapping[i].name; i++) {
        int mandatory = jfields_mapping[i].mandatory;
        enum FFJniFieldType type = jfields_mapping[i].type;

        if (type == FF_JNI_CLASS) {
            jclass clazz;

            last_clazz = NULL;

            clazz = (*env)->FindClass(env, jfields_mapping[i].name);
            if ((ret = ff_jni_exception_check(env, mandatory, log_ctx)) < 0 && mandatory) {
                goto done;
            }

            last_clazz = *(jclass*)((uint8_t*)jfields + jfields_mapping[i].offset) =
                    global ? (*env)->NewGlobalRef(env, clazz) : clazz;

            if (global) {
                (*env)->DeleteLocalRef(env, clazz);
            }

        } else {

            if (!last_clazz) {
                ret = AVERROR_EXTERNAL;
                break;
            }

            switch(type) {
            case FF_JNI_FIELD: {
                jfieldID field_id = (*env)->GetFieldID(env, last_clazz, jfields_mapping[i].method, jfields_mapping[i].signature);
                if ((ret = ff_jni_exception_check(env, mandatory, log_ctx)) < 0 && mandatory) {
                    goto done;
                }

                *(jfieldID*)((uint8_t*)jfields + jfields_mapping[i].offset) = field_id;
                break;
            }
            case FF_JNI_STATIC_FIELD: {
                jfieldID field_id = (*env)->GetStaticFieldID(env, last_clazz, jfields_mapping[i].method, jfields_mapping[i].signature);
                if ((ret = ff_jni_exception_check(env, mandatory, log_ctx)) < 0 && mandatory) {
                    goto done;
                }

                *(jfieldID*)((uint8_t*)jfields + jfields_mapping[i].offset) = field_id;
                break;
            }
            case FF_JNI_METHOD: {
                jmethodID method_id = (*env)->GetMethodID(env, last_clazz, jfields_mapping[i].method, jfields_mapping[i].signature);
                if ((ret = ff_jni_exception_check(env, mandatory, log_ctx)) < 0 && mandatory) {
                    goto done;
                }

                *(jmethodID*)((uint8_t*)jfields + jfields_mapping[i].offset) = method_id;
                break;
            }
            case FF_JNI_STATIC_METHOD: {
                jmethodID method_id = (*env)->GetStaticMethodID(env, last_clazz, jfields_mapping[i].method, jfields_mapping[i].signature);
                if ((ret = ff_jni_exception_check(env, mandatory, log_ctx)) < 0 && mandatory) {
                    goto done;
                }

                *(jmethodID*)((uint8_t*)jfields + jfields_mapping[i].offset) = method_id;
                break;
            }
            default:
                av_log(log_ctx, AV_LOG_ERROR, "Unknown JNI field type\n");
                ret = AVERROR(EINVAL);
                goto done;
            }

            ret = 0;
        }
    }

done:
    if (ret < 0) {
        /* reset jfields in case of failure so it does not leak references */
        ff_jni_reset_jfields(env, jfields, jfields_mapping, global, log_ctx);
    }

    return ret;
}

int ff_jni_reset_jfields(JNIEnv *env, void *jfields, const struct FFJniField *jfields_mapping, int global, void *log_ctx)
{
    int i;

    for (i = 0; jfields_mapping[i].name; i++) {
        enum FFJniFieldType type = jfields_mapping[i].type;

        switch(type) {
        case FF_JNI_CLASS: {
            jclass clazz = *(jclass*)((uint8_t*)jfields + jfields_mapping[i].offset);
            if (!clazz)
                continue;

            if (global) {
                (*env)->DeleteGlobalRef(env, clazz);
            } else {
                (*env)->DeleteLocalRef(env, clazz);
            }

            *(jclass*)((uint8_t*)jfields + jfields_mapping[i].offset) = NULL;
            break;
        }
        case FF_JNI_FIELD: {
            *(jfieldID*)((uint8_t*)jfields + jfields_mapping[i].offset) = NULL;
            break;
        }
        case FF_JNI_STATIC_FIELD: {
            *(jfieldID*)((uint8_t*)jfields + jfields_mapping[i].offset) = NULL;
            break;
        }
        case FF_JNI_METHOD: {
            *(jmethodID*)((uint8_t*)jfields + jfields_mapping[i].offset) = NULL;
            break;
        }
        case FF_JNI_STATIC_METHOD: {
            *(jmethodID*)((uint8_t*)jfields + jfields_mapping[i].offset) = NULL;
            break;
        }
        default:
            av_log(log_ctx, AV_LOG_ERROR, "Unknown JNI field type\n");
        }
    }

    return 0;
}

