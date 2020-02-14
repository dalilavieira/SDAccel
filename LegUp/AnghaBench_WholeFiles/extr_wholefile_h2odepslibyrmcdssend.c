#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_47__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  yrmcds_error ;
typedef  scalar_t__ yrmcds_command ;
struct TYPE_47__ {scalar_t__ text_mode; int /*<<< orphan*/  lock; int /*<<< orphan*/  sock; int /*<<< orphan*/  serial; } ;
typedef  TYPE_1__ yrmcds ;
typedef  int /*<<< orphan*/  uint64_t ;
typedef  int /*<<< orphan*/  uint32_t ;
typedef  int /*<<< orphan*/  uint16_t ;
struct iovec {char* iov_base; int iov_len; } ;
typedef  int ssize_t ;
typedef  int /*<<< orphan*/  n ;
typedef  int /*<<< orphan*/  key ;
typedef  int /*<<< orphan*/  h ;
typedef  int /*<<< orphan*/  extras ;
typedef  int /*<<< orphan*/  extra ;

/* Variables and functions */
 int BINARY_HEADER_SIZE ; 
 int EINTR ; 
 size_t MAX_DATA_SIZE ; 
 int /*<<< orphan*/  YRMCDS_BAD_ARGUMENT ; 
 scalar_t__ YRMCDS_CMD_ADD ; 
 scalar_t__ YRMCDS_CMD_ADDQ ; 
 scalar_t__ YRMCDS_CMD_APPEND ; 
 scalar_t__ YRMCDS_CMD_APPENDQ ; 
 scalar_t__ YRMCDS_CMD_BOTTOM ; 
 scalar_t__ YRMCDS_CMD_DECREMENT ; 
 scalar_t__ YRMCDS_CMD_DECREMENTQ ; 
 scalar_t__ YRMCDS_CMD_DELETE ; 
 scalar_t__ YRMCDS_CMD_DELETEQ ; 
 scalar_t__ YRMCDS_CMD_FLUSH ; 
 scalar_t__ YRMCDS_CMD_FLUSHQ ; 
 scalar_t__ YRMCDS_CMD_GAT ; 
 scalar_t__ YRMCDS_CMD_GATK ; 
 scalar_t__ YRMCDS_CMD_GATKQ ; 
 scalar_t__ YRMCDS_CMD_GATQ ; 
 scalar_t__ YRMCDS_CMD_GET ; 
 scalar_t__ YRMCDS_CMD_GETK ; 
 scalar_t__ YRMCDS_CMD_GETKQ ; 
 scalar_t__ YRMCDS_CMD_GETQ ; 
 scalar_t__ YRMCDS_CMD_INCREMENT ; 
 scalar_t__ YRMCDS_CMD_INCREMENTQ ; 
 scalar_t__ YRMCDS_CMD_KEYS ; 
 scalar_t__ YRMCDS_CMD_LAG ; 
 scalar_t__ YRMCDS_CMD_LAGK ; 
 scalar_t__ YRMCDS_CMD_LAGKQ ; 
 scalar_t__ YRMCDS_CMD_LAGQ ; 
 scalar_t__ YRMCDS_CMD_LOCK ; 
 scalar_t__ YRMCDS_CMD_LOCKQ ; 
 scalar_t__ YRMCDS_CMD_NOOP ; 
 scalar_t__ YRMCDS_CMD_PREPEND ; 
 scalar_t__ YRMCDS_CMD_PREPENDQ ; 
 scalar_t__ YRMCDS_CMD_QUIT ; 
 scalar_t__ YRMCDS_CMD_QUITQ ; 
 scalar_t__ YRMCDS_CMD_RAU ; 
 scalar_t__ YRMCDS_CMD_RAUQ ; 
 scalar_t__ YRMCDS_CMD_REPLACE ; 
 scalar_t__ YRMCDS_CMD_REPLACEQ ; 
 scalar_t__ YRMCDS_CMD_SET ; 
 scalar_t__ YRMCDS_CMD_SETQ ; 
 scalar_t__ YRMCDS_CMD_STAT ; 
 scalar_t__ YRMCDS_CMD_TOUCH ; 
 scalar_t__ YRMCDS_CMD_UNLOCK ; 
 scalar_t__ YRMCDS_CMD_UNLOCKALL ; 
 scalar_t__ YRMCDS_CMD_UNLOCKALLQ ; 
 scalar_t__ YRMCDS_CMD_UNLOCKQ ; 
 scalar_t__ YRMCDS_CMD_VERSION ; 
 int /*<<< orphan*/  YRMCDS_NOT_IMPLEMENTED ; 
 int /*<<< orphan*/  YRMCDS_OK ; 
 int /*<<< orphan*/  YRMCDS_SYSTEM_ERROR ; 
 int errno ; 
 int /*<<< orphan*/  free (void*) ; 
 int /*<<< orphan*/  htobe16 (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  htobe32 (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  htobe64 (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  memcpy (char*,int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  memset (char*,int /*<<< orphan*/ ,int) ; 
 int pthread_mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  pthread_mutex_unlock (int /*<<< orphan*/ *) ; 
 int writev (int /*<<< orphan*/ ,struct iovec*,int) ; 
 int /*<<< orphan*/  yrmcds_text_add (TYPE_1__*,char const*,size_t,char const*,size_t,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  yrmcds_text_append (TYPE_1__*,char const*,size_t,char const*,size_t,int,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  yrmcds_text_decr (TYPE_1__*,char const*,size_t,int /*<<< orphan*/ ,int,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  yrmcds_text_flush (TYPE_1__*,int /*<<< orphan*/ ,int,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  yrmcds_text_get (TYPE_1__*,char const*,size_t,int,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  yrmcds_text_incr (TYPE_1__*,char const*,size_t,int /*<<< orphan*/ ,int,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  yrmcds_text_prepend (TYPE_1__*,char const*,size_t,char const*,size_t,int,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  yrmcds_text_quit (TYPE_1__*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  yrmcds_text_remove (TYPE_1__*,char const*,size_t,int,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  yrmcds_text_replace (TYPE_1__*,char const*,size_t,char const*,size_t,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  yrmcds_text_set (TYPE_1__*,char const*,size_t,char const*,size_t,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  yrmcds_text_touch (TYPE_1__*,char const*,size_t,int /*<<< orphan*/ ,int,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  yrmcds_text_version (TYPE_1__*,int /*<<< orphan*/ *) ; 

__attribute__((used)) static inline void hton64(uint64_t i, char* p) {
    uint64_t n = htobe64(i);
    memcpy(p, &n, sizeof(n));
}

__attribute__((used)) static inline void hton32(uint32_t i, char* p) {
    uint32_t n = htobe32(i);
    memcpy(p, &n, sizeof(n));
}

__attribute__((used)) static inline void hton16(uint16_t i, char* p) {
    uint16_t n = htobe16(i);
    memcpy(p, &n, sizeof(n));
}

__attribute__((used)) static yrmcds_error send_command(
    yrmcds* c, yrmcds_command cmd, uint64_t cas, uint32_t* serial,
    size_t key_len, const char* key,
    size_t extras_len, const char* extras,
    size_t data_len, const char* data) {
    if( cmd >= YRMCDS_CMD_BOTTOM ||
        key_len > 65535 || extras_len > 127 || data_len > MAX_DATA_SIZE ||
        (key_len != 0 && key == NULL) ||
        (extras_len != 0 && extras == NULL) ||
        (data_len != 0 && data == NULL) )
        return YRMCDS_BAD_ARGUMENT;

    char h[BINARY_HEADER_SIZE];
    memset(h, 0, sizeof(h));
    h[0] = '\x80';
    h[1] = (char)cmd;
    hton16((uint16_t)key_len, &h[2]);
    h[4] = (char)extras_len;
    size_t total_len = (key_len + extras_len + data_len);
    hton32((uint32_t)total_len, &h[8]);
    hton64(cas, &h[16]);

#ifndef LIBYRMCDS_NO_INTERNAL_LOCK
    int e = pthread_mutex_lock(&c->lock);
    if( e != 0 ) {
        errno = e;
        return YRMCDS_SYSTEM_ERROR;
    }
#endif // ! LIBYRMCDS_NO_INTERNAL_LOCK

    yrmcds_error ret = YRMCDS_OK;
    c->serial = c->serial + 1;
    memcpy(&h[12], &c->serial, 4);
    if( serial != NULL )
        *serial = c->serial;

    struct iovec iov[4];
    int iovcnt = 1;
    iov[0].iov_base = h;
    iov[0].iov_len = sizeof(h);

    if( extras_len > 0 ) {
        iov[iovcnt].iov_base = (void*)extras;
        iov[iovcnt].iov_len = extras_len;
        iovcnt++;
    }
    if( key_len > 0 ) {
        iov[iovcnt].iov_base = (void*)key;
        iov[iovcnt].iov_len = key_len;
        iovcnt++;
    }
    if( data_len > 0 ) {
        iov[iovcnt].iov_base = (void*)data;
        iov[iovcnt].iov_len = data_len;
        iovcnt++;
    }

    while( iovcnt > 0 ) {
        ssize_t n = writev(c->sock, iov, iovcnt);
        size_t n2 = (size_t)n;
        if( n == -1 ) {
            if( errno == EINTR ) continue;
            ret = YRMCDS_SYSTEM_ERROR;
            goto OUT;
        }
        while( n2 > 0 ) {
            if( n2 < iov[0].iov_len ) {
                iov[0].iov_base = (char*)iov[0].iov_base + n2;
                iov[0].iov_len -= n2;
                break;
            }
            n2 -= iov[0].iov_len;
            iovcnt --;
            if( iovcnt == 0 )
                break;

            int i;
            for( i = 0; i < iovcnt; ++i )
                iov[i] = iov[i+1];
        }
    }

  OUT:
#ifndef LIBYRMCDS_NO_INTERNAL_LOCK
    pthread_mutex_unlock(&c->lock);
#endif
    return ret;
}

__attribute__((used)) static yrmcds_error send_data(
    yrmcds* c, yrmcds_command cmd, const char* key, size_t key_len,
    const char* data, size_t data_len, uint32_t flags, uint32_t expire,
    uint64_t cas, uint32_t* serial) {
    if( c == NULL || key == NULL || key_len == 0 ||
        data == NULL || data_len == 0 )
        return YRMCDS_BAD_ARGUMENT;

    int compressed = 0;
#ifdef LIBYRMCDS_USE_LZ4
    if( (c->compress_size > 0) && (data_len > c->compress_size) ) {
        if( flags & YRMCDS_FLAG_COMPRESS )
            return YRMCDS_BAD_ARGUMENT;

        size_t bound = (size_t)LZ4_compressBound((int)data_len);
        char* new_data = (char*)malloc(bound + sizeof(uint32_t));
        if( new_data == NULL )
            return YRMCDS_OUT_OF_MEMORY;
        uint32_t new_size =
            (uint32_t)LZ4_compress(data, new_data + sizeof(uint32_t),
                                   (int)data_len);
        if( new_size == 0 ) {
            free(new_data);
            return YRMCDS_COMPRESS_FAILED;
        }
        hton32((uint32_t)data_len, new_data);
        flags |= YRMCDS_FLAG_COMPRESS;
        data_len = sizeof(uint32_t) + new_size;
        data = new_data;
        compressed = 1;
    }
#endif // LIBYRMCDS_USE_LZ4

    char extras[8];
    hton32(flags, extras);
    hton32(expire, &extras[4]);
    yrmcds_error e = send_command(c, cmd, cas, serial, key_len, key,
                                  sizeof(extras), extras, data_len, data);
    if( compressed )
        free((void*)data);
    return e;
}

yrmcds_error yrmcds_noop(yrmcds* c, uint32_t* serial) {
    if( c == NULL )
        return YRMCDS_BAD_ARGUMENT;

    if( c->text_mode )
        return YRMCDS_NOT_IMPLEMENTED;

    return send_command(c, YRMCDS_CMD_NOOP, 0, serial,
                        0, NULL, 0, NULL, 0, NULL);
}

yrmcds_error yrmcds_get(yrmcds* c, const char* key, size_t key_len,
                        int quiet, uint32_t* serial) {
    if( c == NULL || key == NULL || key_len == 0 )
        return YRMCDS_BAD_ARGUMENT;

    if( c->text_mode )
        return yrmcds_text_get(c, key, key_len, quiet, serial);

    return send_command(c, quiet ? YRMCDS_CMD_GETQ : YRMCDS_CMD_GET,
                        0, serial, key_len, key, 0, NULL, 0, NULL);
}

yrmcds_error yrmcds_getk(yrmcds* c, const char* key, size_t key_len,
                         int quiet, uint32_t* serial) {
    if( c == NULL || key == NULL || key_len == 0 )
        return YRMCDS_BAD_ARGUMENT;

    if( c->text_mode )
        return yrmcds_text_get(c, key, key_len, quiet, serial);

    return send_command(c, quiet ? YRMCDS_CMD_GETKQ : YRMCDS_CMD_GETK,
                        0, serial, key_len, key, 0, NULL, 0, NULL);
}

yrmcds_error yrmcds_get_touch(yrmcds* c, const char* key, size_t key_len,
                              uint32_t expire, int quiet, uint32_t* serial) {
    if( c == NULL || key == NULL || key_len == 0 )
        return YRMCDS_BAD_ARGUMENT;

    if( c->text_mode )
        return YRMCDS_NOT_IMPLEMENTED;

    char extras[4];
    hton32(expire, extras);
    return send_command(c, quiet ? YRMCDS_CMD_GATQ : YRMCDS_CMD_GAT,
                        0, serial, key_len, key,
                        sizeof(extras), extras, 0, NULL);
}

yrmcds_error yrmcds_getk_touch(yrmcds* c, const char* key, size_t key_len,
                               uint32_t expire, int quiet, uint32_t* serial) {
    if( c == NULL || key == NULL || key_len == 0 )
        return YRMCDS_BAD_ARGUMENT;

    if( c->text_mode )
        return YRMCDS_NOT_IMPLEMENTED;

    char extras[4];
    hton32(expire, extras);
    return send_command(c, quiet ? YRMCDS_CMD_GATKQ : YRMCDS_CMD_GATK,
                        0, serial, key_len, key,
                        sizeof(extras), extras, 0, NULL);
}

yrmcds_error yrmcds_lock_get(yrmcds* c, const char* key, size_t key_len,
                             int quiet, uint32_t* serial) {
    if( c == NULL || key == NULL || key_len == 0 )
        return YRMCDS_BAD_ARGUMENT;

    if( c->text_mode )
        return YRMCDS_NOT_IMPLEMENTED;

    return send_command(c, quiet ? YRMCDS_CMD_LAGQ : YRMCDS_CMD_LAG,
                        0, serial, key_len, key, 0, NULL, 0, NULL);
}

yrmcds_error yrmcds_lock_getk(yrmcds* c, const char* key, size_t key_len,
                              int quiet, uint32_t* serial) {
    if( c == NULL || key == NULL || key_len == 0 )
        return YRMCDS_BAD_ARGUMENT;

    if( c->text_mode )
        return YRMCDS_NOT_IMPLEMENTED;

    return send_command(c, quiet ? YRMCDS_CMD_LAGKQ : YRMCDS_CMD_LAGK,
                        0, serial, key_len, key, 0, NULL, 0, NULL);
}

yrmcds_error yrmcds_touch(yrmcds* c, const char* key, size_t key_len,
                          uint32_t expire, int quiet, uint32_t* serial) {
    if( c == NULL || key == NULL || key_len == 0 )
        return YRMCDS_BAD_ARGUMENT;

    if( c->text_mode )
        return yrmcds_text_touch(c, key, key_len, expire, quiet, serial);

    char extras[4];
    hton32(expire, extras);
    return send_command(c, YRMCDS_CMD_TOUCH, 0, serial, key_len, key,
                        sizeof(extras), extras, 0, NULL);
}

yrmcds_error yrmcds_set(yrmcds* c, const char* key, size_t key_len,
                        const char* data, size_t data_len,
                        uint32_t flags, uint32_t expire, uint64_t cas,
                        int quiet, uint32_t* serial) {
    if( c && c->text_mode )
        return yrmcds_text_set(c, key, key_len, data, data_len,
                               flags, expire, cas, quiet, serial);

    return send_data(c, quiet ? YRMCDS_CMD_SETQ : YRMCDS_CMD_SET,
                     key, key_len, data, data_len, flags, expire, cas, serial);
}

yrmcds_error yrmcds_replace(yrmcds* c, const char* key, size_t key_len,
                            const char* data, size_t data_len,
                            uint32_t flags, uint32_t expire, uint64_t cas,
                            int quiet, uint32_t* serial) {
    if( c && c->text_mode )
        return yrmcds_text_replace(c, key, key_len, data, data_len,
                                   flags, expire, cas, quiet, serial);

    return send_data(c, quiet ? YRMCDS_CMD_REPLACEQ : YRMCDS_CMD_REPLACE,
                     key, key_len, data, data_len, flags, expire, cas, serial);
}

yrmcds_error yrmcds_add(yrmcds* c, const char* key, size_t key_len,
                        const char* data, size_t data_len,
                        uint32_t flags, uint32_t expire, uint64_t cas,
                        int quiet, uint32_t* serial) {
    if( c && c->text_mode )
        return yrmcds_text_add(c, key, key_len, data, data_len,
                               flags, expire, cas, quiet, serial);

    return send_data(c, quiet ? YRMCDS_CMD_ADDQ : YRMCDS_CMD_ADD,
                     key, key_len, data, data_len, flags, expire, cas, serial);
}

yrmcds_error yrmcds_replace_unlock(yrmcds* c, const char* key, size_t key_len,
                                   const char* data, size_t data_len,
                                   uint32_t flags, uint32_t expire,
                                   int quiet, uint32_t* serial) {
    if( c && c->text_mode )
        return YRMCDS_NOT_IMPLEMENTED;

    return send_data(c, quiet ? YRMCDS_CMD_RAUQ : YRMCDS_CMD_RAU,
                     key, key_len, data, data_len, flags, expire, 0, serial);
}

yrmcds_error yrmcds_incr(yrmcds* c, const char* key, size_t key_len,
                         uint64_t value, int quiet, uint32_t* serial) {
    if( c == NULL || key == NULL || key_len == 0 )
        return YRMCDS_BAD_ARGUMENT;

    if( c->text_mode )
        return yrmcds_text_incr(c, key, key_len, value, quiet, serial);

    char extras[20];
    hton64(value, extras);
    hton64((uint64_t)0, &extras[8]);
    hton32(~(uint32_t)0, &extras[16]);
    return send_command(c, quiet ? YRMCDS_CMD_INCREMENTQ : YRMCDS_CMD_INCREMENT,
                        0, serial, key_len, key,
                        sizeof(extras), extras, 0, NULL);
}

yrmcds_error yrmcds_incr2(yrmcds* c, const char* key, size_t key_len,
                          uint64_t value, uint64_t initial, uint32_t expire,
                          int quiet, uint32_t* serial) {
    if( c == NULL || key == NULL || key_len == 0 )
        return YRMCDS_BAD_ARGUMENT;

    if( c->text_mode )
        return YRMCDS_NOT_IMPLEMENTED;

    char extras[20];
    hton64(value, extras);
    hton64(initial, &extras[8]);
    hton32(expire, &extras[16]);
    return send_command(c, quiet ? YRMCDS_CMD_INCREMENTQ : YRMCDS_CMD_INCREMENT,
                        0, serial, key_len, key,
                        sizeof(extras), extras, 0, NULL);
}

yrmcds_error yrmcds_decr(yrmcds* c, const char* key, size_t key_len,
                         uint64_t value, int quiet, uint32_t* serial) {
    if( c == NULL || key == NULL || key_len == 0 )
        return YRMCDS_BAD_ARGUMENT;

    if( c->text_mode )
        return yrmcds_text_decr(c, key, key_len, value, quiet, serial);

    char extras[20];
    hton64(value, extras);
    hton64((uint64_t)0, &extras[8]);
    hton32(~(uint32_t)0, &extras[16]);
    return send_command(c, quiet ? YRMCDS_CMD_DECREMENTQ : YRMCDS_CMD_DECREMENT,
                        0, serial, key_len, key,
                        sizeof(extras), extras, 0, NULL);
}

yrmcds_error yrmcds_decr2(yrmcds* c, const char* key, size_t key_len,
                          uint64_t value, uint64_t initial, uint32_t expire,
                          int quiet, uint32_t* serial) {
    if( c == NULL || key == NULL || key_len == 0 )
        return YRMCDS_BAD_ARGUMENT;

    if( c->text_mode )
        return YRMCDS_NOT_IMPLEMENTED;

    char extras[20];
    hton64(value, extras);
    hton64(initial, &extras[8]);
    hton32(expire, &extras[16]);
    return send_command(c, quiet ? YRMCDS_CMD_DECREMENTQ : YRMCDS_CMD_DECREMENT,
                        0, serial, key_len, key,
                        sizeof(extras), extras, 0, NULL);
}

yrmcds_error yrmcds_append(yrmcds* c, const char* key, size_t key_len,
                           const char* data, size_t data_len,
                           int quiet, uint32_t* serial) {
    if( c == NULL || key == NULL || key_len == 0 ||
        data == NULL || data_len == 0 )
        return YRMCDS_BAD_ARGUMENT;

    if( c->text_mode )
        return yrmcds_text_append(c, key, key_len, data, data_len,
                                  quiet, serial);

    return send_command(c, quiet ? YRMCDS_CMD_APPENDQ : YRMCDS_CMD_APPEND,
                        0, serial, key_len, key, 0, NULL, data_len, data);
}

yrmcds_error yrmcds_prepend(yrmcds* c, const char* key, size_t key_len,
                            const char* data, size_t data_len,
                            int quiet, uint32_t* serial) {
    if( c == NULL || key == NULL || key_len == 0 ||
        data == NULL || data_len == 0 )
        return YRMCDS_BAD_ARGUMENT;

    if( c->text_mode )
        return yrmcds_text_prepend(c, key, key_len, data, data_len,
                                   quiet, serial);

    return send_command(c, quiet ? YRMCDS_CMD_PREPENDQ : YRMCDS_CMD_PREPEND,
                        0, serial, key_len, key, 0, NULL, data_len, data);
}

yrmcds_error yrmcds_remove(yrmcds* c, const char* key, size_t key_len,
                           int quiet, uint32_t* serial) {
    if( c == NULL || key == NULL || key_len == 0 )
        return YRMCDS_BAD_ARGUMENT;

    if( c->text_mode )
        return yrmcds_text_remove(c, key, key_len, quiet, serial);

    return send_command(c, quiet ? YRMCDS_CMD_DELETEQ : YRMCDS_CMD_DELETE,
                        0, serial, key_len, key, 0, NULL, 0, NULL);
}

yrmcds_error yrmcds_lock(yrmcds* c, const char* key, size_t key_len,
                         int quiet, uint32_t* serial) {
    if( c == NULL || key == NULL || key_len == 0 )
        return YRMCDS_BAD_ARGUMENT;

    if( c->text_mode )
        return YRMCDS_NOT_IMPLEMENTED;

    return send_command(c, quiet ? YRMCDS_CMD_LOCKQ : YRMCDS_CMD_LOCK,
                        0, serial, key_len, key, 0, NULL, 0, NULL);
}

yrmcds_error yrmcds_unlock(yrmcds* c, const char* key, size_t key_len,
                           int quiet, uint32_t* serial) {
    if( c == NULL || key == NULL || key_len == 0 )
        return YRMCDS_BAD_ARGUMENT;

    if( c->text_mode )
        return YRMCDS_NOT_IMPLEMENTED;

    return send_command(c, quiet ? YRMCDS_CMD_UNLOCKQ : YRMCDS_CMD_UNLOCK,
                        0, serial, key_len, key, 0, NULL, 0, NULL);
}

yrmcds_error yrmcds_unlockall(yrmcds* c, int quiet, uint32_t* serial) {
    if( c == NULL )
        return YRMCDS_BAD_ARGUMENT;

    if( c->text_mode )
        return YRMCDS_NOT_IMPLEMENTED;

    return send_command(c, quiet ? YRMCDS_CMD_UNLOCKALLQ : YRMCDS_CMD_UNLOCKALL,
                        0, serial, 0, NULL, 0, NULL, 0, NULL);
}

yrmcds_error yrmcds_flush(yrmcds* c, uint32_t delay,
                          int quiet, uint32_t* serial) {
    if( c == NULL )
        return YRMCDS_BAD_ARGUMENT;

    if( c->text_mode )
        return yrmcds_text_flush(c, delay, quiet, serial);

    if( delay == 0 )
        return send_command(c, quiet ? YRMCDS_CMD_FLUSHQ : YRMCDS_CMD_FLUSH,
                            0, serial, 0, NULL, 0, NULL, 0, NULL);

    char extra[4];
    hton32(delay, extra);
    return send_command(c, quiet ? YRMCDS_CMD_FLUSHQ : YRMCDS_CMD_FLUSH,
                        0, serial, 0, NULL, sizeof(extra), extra, 0, NULL);
}

yrmcds_error yrmcds_stat_general(yrmcds* c, uint32_t* serial) {
    if( c == NULL )
        return YRMCDS_BAD_ARGUMENT;

    if( c->text_mode )
        return YRMCDS_NOT_IMPLEMENTED;

    return send_command(c, YRMCDS_CMD_STAT,
                        0, serial, 0, NULL, 0, NULL, 0, NULL);
}

yrmcds_error yrmcds_stat_settings(yrmcds* c, uint32_t* serial) {
    if( c == NULL )
        return YRMCDS_BAD_ARGUMENT;

    if( c->text_mode )
        return YRMCDS_NOT_IMPLEMENTED;

    const char key[] = "settings";
    return send_command(c, YRMCDS_CMD_STAT,
                        0, serial, sizeof(key) - 1, key, 0, NULL, 0, NULL);
}

yrmcds_error yrmcds_stat_items(yrmcds* c, uint32_t* serial) {
    if( c == NULL )
        return YRMCDS_BAD_ARGUMENT;

    if( c->text_mode )
        return YRMCDS_NOT_IMPLEMENTED;

    const char key[] = "items";
    return send_command(c, YRMCDS_CMD_STAT,
                        0, serial, sizeof(key) - 1, key, 0, NULL, 0, NULL);
}

yrmcds_error yrmcds_stat_sizes(yrmcds* c, uint32_t* serial) {
    if( c == NULL )
        return YRMCDS_BAD_ARGUMENT;

    if( c->text_mode )
        return YRMCDS_NOT_IMPLEMENTED;

    const char key[] = "sizes";
    return send_command(c, YRMCDS_CMD_STAT,
                        0, serial, sizeof(key) - 1, key, 0, NULL, 0, NULL);
}

yrmcds_error yrmcds_keys(yrmcds* c, const char* prefix, size_t prefix_len,
                         uint32_t* serial) {
    if( c == NULL ||
        (prefix == NULL && prefix_len != 0) ||
        (prefix != NULL && prefix_len == 0) )
        return YRMCDS_BAD_ARGUMENT;

    if( c->text_mode )
        return YRMCDS_NOT_IMPLEMENTED;

    return send_command(c, YRMCDS_CMD_KEYS,
                        0, serial, prefix_len, prefix, 0, NULL, 0, NULL);
}

yrmcds_error yrmcds_version(yrmcds* c, uint32_t* serial) {
    if( c == NULL )
        return YRMCDS_BAD_ARGUMENT;

    if( c->text_mode )
        return yrmcds_text_version(c, serial);

    return send_command(c, YRMCDS_CMD_VERSION,
                        0, serial, 0, NULL, 0, NULL, 0, NULL);
}

yrmcds_error yrmcds_quit(yrmcds* c, int quiet, uint32_t* serial) {
    if( c == NULL )
        return YRMCDS_BAD_ARGUMENT;

    if( c->text_mode )
        return yrmcds_text_quit(c, serial);

    return send_command(c, quiet ? YRMCDS_CMD_QUITQ : YRMCDS_CMD_QUIT,
                        0, serial, 0, NULL, 0, NULL, 0, NULL);
}

