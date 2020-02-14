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

/* Variables and functions */
 int /*<<< orphan*/  CRYPTO_free (void*,char const*,int) ; 
 void* CRYPTO_malloc (size_t,char const*,int) ; 
 void* CRYPTO_zalloc (size_t,char const*,int) ; 
 int /*<<< orphan*/  OPENSSL_cleanse (void*,size_t) ; 

int CRYPTO_secure_malloc_init(size_t size, int minsize)
{
#ifdef OPENSSL_SECURE_MEMORY
    int ret = 0;

    if (!secure_mem_initialized) {
        sec_malloc_lock = CRYPTO_THREAD_lock_new();
        if (sec_malloc_lock == NULL)
            return 0;
        if ((ret = sh_init(size, minsize)) != 0) {
            secure_mem_initialized = 1;
        } else {
            CRYPTO_THREAD_lock_free(sec_malloc_lock);
            sec_malloc_lock = NULL;
        }
    }

    return ret;
#else
    return 0;
#endif /* OPENSSL_SECURE_MEMORY */
}

int CRYPTO_secure_malloc_done(void)
{
#ifdef OPENSSL_SECURE_MEMORY
    if (secure_mem_used == 0) {
        sh_done();
        secure_mem_initialized = 0;
        CRYPTO_THREAD_lock_free(sec_malloc_lock);
        sec_malloc_lock = NULL;
        return 1;
    }
#endif /* OPENSSL_SECURE_MEMORY */
    return 0;
}

int CRYPTO_secure_malloc_initialized(void)
{
#ifdef OPENSSL_SECURE_MEMORY
    return secure_mem_initialized;
#else
    return 0;
#endif /* OPENSSL_SECURE_MEMORY */
}

void *CRYPTO_secure_malloc(size_t num, const char *file, int line)
{
#ifdef OPENSSL_SECURE_MEMORY
    void *ret;
    size_t actual_size;

    if (!secure_mem_initialized) {
        return CRYPTO_malloc(num, file, line);
    }
    CRYPTO_THREAD_write_lock(sec_malloc_lock);
    ret = sh_malloc(num);
    actual_size = ret ? sh_actual_size(ret) : 0;
    secure_mem_used += actual_size;
    CRYPTO_THREAD_unlock(sec_malloc_lock);
    return ret;
#else
    return CRYPTO_malloc(num, file, line);
#endif /* OPENSSL_SECURE_MEMORY */
}

void *CRYPTO_secure_zalloc(size_t num, const char *file, int line)
{
#ifdef OPENSSL_SECURE_MEMORY
    if (secure_mem_initialized)
        /* CRYPTO_secure_malloc() zeroes allocations when it is implemented */
        return CRYPTO_secure_malloc(num, file, line);
#endif
    return CRYPTO_zalloc(num, file, line);
}

void CRYPTO_secure_free(void *ptr, const char *file, int line)
{
#ifdef OPENSSL_SECURE_MEMORY
    size_t actual_size;

    if (ptr == NULL)
        return;
    if (!CRYPTO_secure_allocated(ptr)) {
        CRYPTO_free(ptr, file, line);
        return;
    }
    CRYPTO_THREAD_write_lock(sec_malloc_lock);
    actual_size = sh_actual_size(ptr);
    CLEAR(ptr, actual_size);
    secure_mem_used -= actual_size;
    sh_free(ptr);
    CRYPTO_THREAD_unlock(sec_malloc_lock);
#else
    CRYPTO_free(ptr, file, line);
#endif /* OPENSSL_SECURE_MEMORY */
}

void CRYPTO_secure_clear_free(void *ptr, size_t num,
                              const char *file, int line)
{
#ifdef OPENSSL_SECURE_MEMORY
    size_t actual_size;

    if (ptr == NULL)
        return;
    if (!CRYPTO_secure_allocated(ptr)) {
        OPENSSL_cleanse(ptr, num);
        CRYPTO_free(ptr, file, line);
        return;
    }
    CRYPTO_THREAD_write_lock(sec_malloc_lock);
    actual_size = sh_actual_size(ptr);
    CLEAR(ptr, actual_size);
    secure_mem_used -= actual_size;
    sh_free(ptr);
    CRYPTO_THREAD_unlock(sec_malloc_lock);
#else
    if (ptr == NULL)
        return;
    OPENSSL_cleanse(ptr, num);
    CRYPTO_free(ptr, file, line);
#endif /* OPENSSL_SECURE_MEMORY */
}

int CRYPTO_secure_allocated(const void *ptr)
{
#ifdef OPENSSL_SECURE_MEMORY
    int ret;

    if (!secure_mem_initialized)
        return 0;
    CRYPTO_THREAD_write_lock(sec_malloc_lock);
    ret = sh_allocated(ptr);
    CRYPTO_THREAD_unlock(sec_malloc_lock);
    return ret;
#else
    return 0;
#endif /* OPENSSL_SECURE_MEMORY */
}

size_t CRYPTO_secure_used(void)
{
#ifdef OPENSSL_SECURE_MEMORY
    return secure_mem_used;
#else
    return 0;
#endif /* OPENSSL_SECURE_MEMORY */
}

size_t CRYPTO_secure_actual_size(void *ptr)
{
#ifdef OPENSSL_SECURE_MEMORY
    size_t actual_size;

    CRYPTO_THREAD_write_lock(sec_malloc_lock);
    actual_size = sh_actual_size(ptr);
    CRYPTO_THREAD_unlock(sec_malloc_lock);
    return actual_size;
#else
    return 0;
#endif
}

