#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_90__   TYPE_3__ ;
typedef  struct TYPE_89__   TYPE_1__ ;

/* Type definitions */
typedef  scalar_t__ uint64_t ;
struct TYPE_90__ {char const* name; int type; int (* bread ) (TYPE_1__*,void*,size_t,size_t*) ;int (* bwrite ) (TYPE_1__*,void const*,size_t,size_t*) ;int (* bputs ) (TYPE_1__*,char const*) ;int (* bgets ) (TYPE_1__*,char*,int) ;long (* ctrl ) (TYPE_1__*,int,long,void*) ;long (* callback_ctrl ) (TYPE_1__*,int,int /*<<< orphan*/ *) ;int /*<<< orphan*/  (* destroy ) (TYPE_1__*) ;int /*<<< orphan*/  (* create ) (TYPE_1__*) ;} ;
struct TYPE_89__ {long (* callback_ex ) (TYPE_1__*,int,char const*,size_t,int,long,long,size_t*) ;long (* callback ) (TYPE_1__*,int,char const*,int,long,long) ;int shutdown; int references; int init; void* ptr; int flags; char* cb_arg; int retry_reason; int /*<<< orphan*/  ex_data; scalar_t__ num_write; scalar_t__ num_read; struct TYPE_89__* next_bio; int /*<<< orphan*/  num; TYPE_3__ const* method; struct TYPE_89__* prev_bio; int /*<<< orphan*/ * lock; } ;
typedef  int /*<<< orphan*/  BIO_info_cb ;
typedef  long (* BIO_callback_fn_ex ) (TYPE_1__*,int,char const*,size_t,int,long,long,size_t*) ;
typedef  long (* BIO_callback_fn ) (TYPE_1__*,int,char const*,int,long,long) ;
typedef  TYPE_3__ const BIO_METHOD ;
typedef  TYPE_1__ BIO ;

/* Variables and functions */
 int BIO_CB_CTRL ; 
 int BIO_CB_FREE ; 
 int BIO_CB_GETS ; 
 int BIO_CB_PUTS ; 
 int BIO_CB_READ ; 
 int BIO_CB_RETURN ; 
 int BIO_CB_WRITE ; 
 int BIO_CTRL_PENDING ; 
 int BIO_CTRL_POP ; 
 int BIO_CTRL_PUSH ; 
 int BIO_CTRL_SET_CALLBACK ; 
 int BIO_CTRL_WPENDING ; 
 int /*<<< orphan*/  BIO_F_BIO_CALLBACK_CTRL ; 
 int /*<<< orphan*/  BIO_F_BIO_CTRL ; 
 int /*<<< orphan*/  BIO_F_BIO_GETS ; 
 int /*<<< orphan*/  BIO_F_BIO_NEW ; 
 int /*<<< orphan*/  BIO_F_BIO_PUTS ; 
 int /*<<< orphan*/  BIO_F_BIO_READ_INTERN ; 
 int /*<<< orphan*/  BIO_F_BIO_WRITE_INTERN ; 
 int /*<<< orphan*/  BIO_R_INVALID_ARGUMENT ; 
 int /*<<< orphan*/  BIO_R_LENGTH_TOO_LONG ; 
 int /*<<< orphan*/  BIO_R_UNINITIALIZED ; 
 int /*<<< orphan*/  BIO_R_UNSUPPORTED_METHOD ; 
 long BIO_ctrl (TYPE_1__*,int,long,void*) ; 
 int /*<<< orphan*/  BIO_dup_state (TYPE_1__*,char*) ; 
 int BIO_get_retry_flags (TYPE_1__*) ; 
 int /*<<< orphan*/  BIO_should_retry (TYPE_1__*) ; 
 int /*<<< orphan*/  BIOerr (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 scalar_t__ CRYPTO_DOWN_REF (int*,int*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  CRYPTO_EX_INDEX_BIO ; 
 int /*<<< orphan*/  CRYPTO_THREAD_lock_free (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/ * CRYPTO_THREAD_lock_new () ; 
 scalar_t__ CRYPTO_UP_REF (int*,int*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  CRYPTO_dup_ex_data (int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  CRYPTO_free_ex_data (int /*<<< orphan*/ ,TYPE_1__*,int /*<<< orphan*/ *) ; 
 void* CRYPTO_get_ex_data (int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  CRYPTO_new_ex_data (int /*<<< orphan*/ ,TYPE_1__*,int /*<<< orphan*/ *) ; 
 int CRYPTO_set_ex_data (int /*<<< orphan*/ *,int,void*) ; 
 int /*<<< orphan*/  ERR_R_INIT_FAIL ; 
 int /*<<< orphan*/  ERR_R_INTERNAL_ERROR ; 
 int /*<<< orphan*/  ERR_R_MALLOC_FAILURE ; 
 scalar_t__ HAS_LEN_OPER (int) ; 
 size_t INT_MAX ; 
 int /*<<< orphan*/  OPENSSL_free (TYPE_1__*) ; 
 TYPE_1__* OPENSSL_zalloc (int) ; 
 int /*<<< orphan*/  REF_ASSERT_ISNT (int) ; 
 int /*<<< orphan*/  REF_PRINT_COUNT (char*,TYPE_1__*) ; 
 int /*<<< orphan*/ * bio_lookup_lock ; 
 int /*<<< orphan*/  bio_sock_cleanup_int () ; 
 int /*<<< orphan*/ * bio_type_lock ; 
 long stub1 (TYPE_1__*,int,char const*,size_t,int,long,long,size_t*) ; 
 long stub10 (TYPE_1__*,int,int /*<<< orphan*/ *) ; 
 long stub2 (TYPE_1__*,int,char const*,int,long,long) ; 
 int /*<<< orphan*/  stub3 (TYPE_1__*) ; 
 int /*<<< orphan*/  stub4 (TYPE_1__*) ; 
 int stub5 (TYPE_1__*,void*,size_t,size_t*) ; 
 int stub6 (TYPE_1__*,void const*,size_t,size_t*) ; 
 int stub7 (TYPE_1__*,char const*) ; 
 int stub8 (TYPE_1__*,char*,int) ; 
 long stub9 (TYPE_1__*,int,long,void*) ; 

__attribute__((used)) static long bio_call_callback(BIO *b, int oper, const char *argp, size_t len,
                              int argi, long argl, long inret, size_t *processed)
{
    long ret;
    int bareoper;

    if (b->callback_ex != NULL)
        return b->callback_ex(b, oper, argp, len, argi, argl, inret, processed);

    /* Strip off any BIO_CB_RETURN flag */
    bareoper = oper & ~BIO_CB_RETURN;

    /*
     * We have an old style callback, so we will have to do nasty casts and
     * check for overflows.
     */
    if (HAS_LEN_OPER(bareoper)) {
        /* In this case |len| is set, and should be used instead of |argi| */
        if (len > INT_MAX)
            return -1;

        argi = (int)len;
    }

    if (inret > 0 && (oper & BIO_CB_RETURN) && bareoper != BIO_CB_CTRL) {
        if (*processed > INT_MAX)
            return -1;
        inret = *processed;
    }

    ret = b->callback(b, oper, argp, argi, argl, inret);

    if (ret > 0 && (oper & BIO_CB_RETURN) && bareoper != BIO_CB_CTRL) {
        *processed = (size_t)ret;
        ret = 1;
    }

    return ret;
}

BIO *BIO_new(const BIO_METHOD *method)
{
    BIO *bio = OPENSSL_zalloc(sizeof(*bio));

    if (bio == NULL) {
        BIOerr(BIO_F_BIO_NEW, ERR_R_MALLOC_FAILURE);
        return NULL;
    }

    bio->method = method;
    bio->shutdown = 1;
    bio->references = 1;

    if (!CRYPTO_new_ex_data(CRYPTO_EX_INDEX_BIO, bio, &bio->ex_data))
        goto err;

    bio->lock = CRYPTO_THREAD_lock_new();
    if (bio->lock == NULL) {
        BIOerr(BIO_F_BIO_NEW, ERR_R_MALLOC_FAILURE);
        CRYPTO_free_ex_data(CRYPTO_EX_INDEX_BIO, bio, &bio->ex_data);
        goto err;
    }

    if (method->create != NULL && !method->create(bio)) {
        BIOerr(BIO_F_BIO_NEW, ERR_R_INIT_FAIL);
        CRYPTO_free_ex_data(CRYPTO_EX_INDEX_BIO, bio, &bio->ex_data);
        CRYPTO_THREAD_lock_free(bio->lock);
        goto err;
    }
    if (method->create == NULL)
        bio->init = 1;

    return bio;

err:
    OPENSSL_free(bio);
    return NULL;
}

int BIO_free(BIO *a)
{
    int ret;

    if (a == NULL)
        return 0;

    if (CRYPTO_DOWN_REF(&a->references, &ret, a->lock) <= 0)
        return 0;

    REF_PRINT_COUNT("BIO", a);
    if (ret > 0)
        return 1;
    REF_ASSERT_ISNT(ret < 0);

    if (a->callback != NULL || a->callback_ex != NULL) {
        ret = (int)bio_call_callback(a, BIO_CB_FREE, NULL, 0, 0, 0L, 1L, NULL);
        if (ret <= 0)
            return ret;
    }

    if ((a->method != NULL) && (a->method->destroy != NULL))
        a->method->destroy(a);

    CRYPTO_free_ex_data(CRYPTO_EX_INDEX_BIO, a, &a->ex_data);

    CRYPTO_THREAD_lock_free(a->lock);

    OPENSSL_free(a);

    return 1;
}

void BIO_set_data(BIO *a, void *ptr)
{
    a->ptr = ptr;
}

void *BIO_get_data(BIO *a)
{
    return a->ptr;
}

void BIO_set_init(BIO *a, int init)
{
    a->init = init;
}

int BIO_get_init(BIO *a)
{
    return a->init;
}

void BIO_set_shutdown(BIO *a, int shut)
{
    a->shutdown = shut;
}

int BIO_get_shutdown(BIO *a)
{
    return a->shutdown;
}

void BIO_vfree(BIO *a)
{
    BIO_free(a);
}

int BIO_up_ref(BIO *a)
{
    int i;

    if (CRYPTO_UP_REF(&a->references, &i, a->lock) <= 0)
        return 0;

    REF_PRINT_COUNT("BIO", a);
    REF_ASSERT_ISNT(i < 2);
    return ((i > 1) ? 1 : 0);
}

void BIO_clear_flags(BIO *b, int flags)
{
    b->flags &= ~flags;
}

int BIO_test_flags(const BIO *b, int flags)
{
    return (b->flags & flags);
}

void BIO_set_flags(BIO *b, int flags)
{
    b->flags |= flags;
}

BIO_callback_fn BIO_get_callback(const BIO *b)
{
    return b->callback;
}

void BIO_set_callback(BIO *b, BIO_callback_fn cb)
{
    b->callback = cb;
}

BIO_callback_fn_ex BIO_get_callback_ex(const BIO *b)
{
    return b->callback_ex;
}

void BIO_set_callback_ex(BIO *b, BIO_callback_fn_ex cb)
{
    b->callback_ex = cb;
}

void BIO_set_callback_arg(BIO *b, char *arg)
{
    b->cb_arg = arg;
}

char *BIO_get_callback_arg(const BIO *b)
{
    return b->cb_arg;
}

const char *BIO_method_name(const BIO *b)
{
    return b->method->name;
}

int BIO_method_type(const BIO *b)
{
    return b->method->type;
}

__attribute__((used)) static int bio_read_intern(BIO *b, void *data, size_t dlen, size_t *readbytes)
{
    int ret;

    if ((b == NULL) || (b->method == NULL) || (b->method->bread == NULL)) {
        BIOerr(BIO_F_BIO_READ_INTERN, BIO_R_UNSUPPORTED_METHOD);
        return -2;
    }

    if ((b->callback != NULL || b->callback_ex != NULL) &&
        ((ret = (int)bio_call_callback(b, BIO_CB_READ, data, dlen, 0, 0L, 1L,
                                       NULL)) <= 0))
        return ret;

    if (!b->init) {
        BIOerr(BIO_F_BIO_READ_INTERN, BIO_R_UNINITIALIZED);
        return -2;
    }

    ret = b->method->bread(b, data, dlen, readbytes);

    if (ret > 0)
        b->num_read += (uint64_t)*readbytes;

    if (b->callback != NULL || b->callback_ex != NULL)
        ret = (int)bio_call_callback(b, BIO_CB_READ | BIO_CB_RETURN, data,
                                     dlen, 0, 0L, ret, readbytes);

    /* Shouldn't happen */
    if (ret > 0 && *readbytes > dlen) {
        BIOerr(BIO_F_BIO_READ_INTERN, ERR_R_INTERNAL_ERROR);
        return -1;
    }

    return ret;
}

int BIO_read(BIO *b, void *data, int dlen)
{
    size_t readbytes;
    int ret;

    if (dlen < 0)
        return 0;

    ret = bio_read_intern(b, data, (size_t)dlen, &readbytes);

    if (ret > 0) {
        /* *readbytes should always be <= dlen */
        ret = (int)readbytes;
    }

    return ret;
}

int BIO_read_ex(BIO *b, void *data, size_t dlen, size_t *readbytes)
{
    int ret;

    ret = bio_read_intern(b, data, dlen, readbytes);

    if (ret > 0)
        ret = 1;
    else
        ret = 0;

    return ret;
}

__attribute__((used)) static int bio_write_intern(BIO *b, const void *data, size_t dlen,
                            size_t *written)
{
    int ret;

    if (b == NULL)
        return 0;

    if ((b->method == NULL) || (b->method->bwrite == NULL)) {
        BIOerr(BIO_F_BIO_WRITE_INTERN, BIO_R_UNSUPPORTED_METHOD);
        return -2;
    }

    if ((b->callback != NULL || b->callback_ex != NULL) &&
        ((ret = (int)bio_call_callback(b, BIO_CB_WRITE, data, dlen, 0, 0L, 1L,
                                       NULL)) <= 0))
        return ret;

    if (!b->init) {
        BIOerr(BIO_F_BIO_WRITE_INTERN, BIO_R_UNINITIALIZED);
        return -2;
    }

    ret = b->method->bwrite(b, data, dlen, written);

    if (ret > 0)
        b->num_write += (uint64_t)*written;

    if (b->callback != NULL || b->callback_ex != NULL)
        ret = (int)bio_call_callback(b, BIO_CB_WRITE | BIO_CB_RETURN, data,
                                     dlen, 0, 0L, ret, written);

    return ret;
}

int BIO_write(BIO *b, const void *data, int dlen)
{
    size_t written;
    int ret;

    if (dlen < 0)
        return 0;

    ret = bio_write_intern(b, data, (size_t)dlen, &written);

    if (ret > 0) {
        /* *written should always be <= dlen */
        ret = (int)written;
    }

    return ret;
}

int BIO_write_ex(BIO *b, const void *data, size_t dlen, size_t *written)
{
    int ret;

    ret = bio_write_intern(b, data, dlen, written);

    if (ret > 0)
        ret = 1;
    else
        ret = 0;

    return ret;
}

int BIO_puts(BIO *b, const char *buf)
{
    int ret;
    size_t written = 0;

    if ((b == NULL) || (b->method == NULL) || (b->method->bputs == NULL)) {
        BIOerr(BIO_F_BIO_PUTS, BIO_R_UNSUPPORTED_METHOD);
        return -2;
    }

    if (b->callback != NULL || b->callback_ex != NULL) {
        ret = (int)bio_call_callback(b, BIO_CB_PUTS, buf, 0, 0, 0L, 1L, NULL);
        if (ret <= 0)
            return ret;
    }

    if (!b->init) {
        BIOerr(BIO_F_BIO_PUTS, BIO_R_UNINITIALIZED);
        return -2;
    }

    ret = b->method->bputs(b, buf);

    if (ret > 0) {
        b->num_write += (uint64_t)ret;
        written = ret;
        ret = 1;
    }

    if (b->callback != NULL || b->callback_ex != NULL)
        ret = (int)bio_call_callback(b, BIO_CB_PUTS | BIO_CB_RETURN, buf, 0, 0,
                                     0L, ret, &written);

    if (ret > 0) {
        if (written > INT_MAX) {
            BIOerr(BIO_F_BIO_PUTS, BIO_R_LENGTH_TOO_LONG);
            ret = -1;
        } else {
            ret = (int)written;
        }
    }

    return ret;
}

int BIO_gets(BIO *b, char *buf, int size)
{
    int ret;
    size_t readbytes = 0;

    if ((b == NULL) || (b->method == NULL) || (b->method->bgets == NULL)) {
        BIOerr(BIO_F_BIO_GETS, BIO_R_UNSUPPORTED_METHOD);
        return -2;
    }

    if (size < 0) {
        BIOerr(BIO_F_BIO_GETS, BIO_R_INVALID_ARGUMENT);
        return 0;
    }

    if (b->callback != NULL || b->callback_ex != NULL) {
        ret = (int)bio_call_callback(b, BIO_CB_GETS, buf, size, 0, 0L, 1, NULL);
        if (ret <= 0)
            return ret;
    }

    if (!b->init) {
        BIOerr(BIO_F_BIO_GETS, BIO_R_UNINITIALIZED);
        return -2;
    }

    ret = b->method->bgets(b, buf, size);

    if (ret > 0) {
        readbytes = ret;
        ret = 1;
    }

    if (b->callback != NULL || b->callback_ex != NULL)
        ret = (int)bio_call_callback(b, BIO_CB_GETS | BIO_CB_RETURN, buf, size,
                                     0, 0L, ret, &readbytes);

    if (ret > 0) {
        /* Shouldn't happen */
        if (readbytes > (size_t)size)
            ret = -1;
        else
            ret = (int)readbytes;
    }

    return ret;
}

int BIO_indent(BIO *b, int indent, int max)
{
    if (indent < 0)
        indent = 0;
    if (indent > max)
        indent = max;
    while (indent--)
        if (BIO_puts(b, " ") != 1)
            return 0;
    return 1;
}

long BIO_int_ctrl(BIO *b, int cmd, long larg, int iarg)
{
    int i;

    i = iarg;
    return BIO_ctrl(b, cmd, larg, (char *)&i);
}

void *BIO_ptr_ctrl(BIO *b, int cmd, long larg)
{
    void *p = NULL;

    if (BIO_ctrl(b, cmd, larg, (char *)&p) <= 0)
        return NULL;
    else
        return p;
}

long BIO_ctrl(BIO *b, int cmd, long larg, void *parg)
{
    long ret;

    if (b == NULL)
        return 0;

    if ((b->method == NULL) || (b->method->ctrl == NULL)) {
        BIOerr(BIO_F_BIO_CTRL, BIO_R_UNSUPPORTED_METHOD);
        return -2;
    }

    if (b->callback != NULL || b->callback_ex != NULL) {
        ret = bio_call_callback(b, BIO_CB_CTRL, parg, 0, cmd, larg, 1L, NULL);
        if (ret <= 0)
            return ret;
    }

    ret = b->method->ctrl(b, cmd, larg, parg);

    if (b->callback != NULL || b->callback_ex != NULL)
        ret = bio_call_callback(b, BIO_CB_CTRL | BIO_CB_RETURN, parg, 0, cmd,
                                larg, ret, NULL);

    return ret;
}

long BIO_callback_ctrl(BIO *b, int cmd, BIO_info_cb *fp)
{
    long ret;

    if (b == NULL)
        return 0;

    if ((b->method == NULL) || (b->method->callback_ctrl == NULL)
            || (cmd != BIO_CTRL_SET_CALLBACK)) {
        BIOerr(BIO_F_BIO_CALLBACK_CTRL, BIO_R_UNSUPPORTED_METHOD);
        return -2;
    }

    if (b->callback != NULL || b->callback_ex != NULL) {
        ret = bio_call_callback(b, BIO_CB_CTRL, (void *)&fp, 0, cmd, 0, 1L,
                                NULL);
        if (ret <= 0)
            return ret;
    }

    ret = b->method->callback_ctrl(b, cmd, fp);

    if (b->callback != NULL || b->callback_ex != NULL)
        ret = bio_call_callback(b, BIO_CB_CTRL | BIO_CB_RETURN, (void *)&fp, 0,
                                cmd, 0, ret, NULL);

    return ret;
}

size_t BIO_ctrl_pending(BIO *bio)
{
    return BIO_ctrl(bio, BIO_CTRL_PENDING, 0, NULL);
}

size_t BIO_ctrl_wpending(BIO *bio)
{
    return BIO_ctrl(bio, BIO_CTRL_WPENDING, 0, NULL);
}

BIO *BIO_push(BIO *b, BIO *bio)
{
    BIO *lb;

    if (b == NULL)
        return bio;
    lb = b;
    while (lb->next_bio != NULL)
        lb = lb->next_bio;
    lb->next_bio = bio;
    if (bio != NULL)
        bio->prev_bio = lb;
    /* called to do internal processing */
    BIO_ctrl(b, BIO_CTRL_PUSH, 0, lb);
    return b;
}

BIO *BIO_pop(BIO *b)
{
    BIO *ret;

    if (b == NULL)
        return NULL;
    ret = b->next_bio;

    BIO_ctrl(b, BIO_CTRL_POP, 0, b);

    if (b->prev_bio != NULL)
        b->prev_bio->next_bio = b->next_bio;
    if (b->next_bio != NULL)
        b->next_bio->prev_bio = b->prev_bio;

    b->next_bio = NULL;
    b->prev_bio = NULL;
    return ret;
}

BIO *BIO_get_retry_BIO(BIO *bio, int *reason)
{
    BIO *b, *last;

    b = last = bio;
    for (;;) {
        if (!BIO_should_retry(b))
            break;
        last = b;
        b = b->next_bio;
        if (b == NULL)
            break;
    }
    if (reason != NULL)
        *reason = last->retry_reason;
    return last;
}

int BIO_get_retry_reason(BIO *bio)
{
    return bio->retry_reason;
}

void BIO_set_retry_reason(BIO *bio, int reason)
{
    bio->retry_reason = reason;
}

BIO *BIO_find_type(BIO *bio, int type)
{
    int mt, mask;

    if (bio == NULL)
        return NULL;
    mask = type & 0xff;
    do {
        if (bio->method != NULL) {
            mt = bio->method->type;

            if (!mask) {
                if (mt & type)
                    return bio;
            } else if (mt == type)
                return bio;
        }
        bio = bio->next_bio;
    } while (bio != NULL);
    return NULL;
}

BIO *BIO_next(BIO *b)
{
    if (b == NULL)
        return NULL;
    return b->next_bio;
}

void BIO_set_next(BIO *b, BIO *next)
{
    b->next_bio = next;
}

void BIO_free_all(BIO *bio)
{
    BIO *b;
    int ref;

    while (bio != NULL) {
        b = bio;
        ref = b->references;
        bio = bio->next_bio;
        BIO_free(b);
        /* Since ref count > 1, don't free anyone else. */
        if (ref > 1)
            break;
    }
}

BIO *BIO_dup_chain(BIO *in)
{
    BIO *ret = NULL, *eoc = NULL, *bio, *new_bio;

    for (bio = in; bio != NULL; bio = bio->next_bio) {
        if ((new_bio = BIO_new(bio->method)) == NULL)
            goto err;
        new_bio->callback = bio->callback;
        new_bio->callback_ex = bio->callback_ex;
        new_bio->cb_arg = bio->cb_arg;
        new_bio->init = bio->init;
        new_bio->shutdown = bio->shutdown;
        new_bio->flags = bio->flags;

        /* This will let SSL_s_sock() work with stdin/stdout */
        new_bio->num = bio->num;

        if (!BIO_dup_state(bio, (char *)new_bio)) {
            BIO_free(new_bio);
            goto err;
        }

        /* copy app data */
        if (!CRYPTO_dup_ex_data(CRYPTO_EX_INDEX_BIO, &new_bio->ex_data,
                                &bio->ex_data)) {
            BIO_free(new_bio);
            goto err;
        }

        if (ret == NULL) {
            eoc = new_bio;
            ret = eoc;
        } else {
            BIO_push(eoc, new_bio);
            eoc = new_bio;
        }
    }
    return ret;
 err:
    BIO_free_all(ret);

    return NULL;
}

void BIO_copy_next_retry(BIO *b)
{
    BIO_set_flags(b, BIO_get_retry_flags(b->next_bio));
    b->retry_reason = b->next_bio->retry_reason;
}

int BIO_set_ex_data(BIO *bio, int idx, void *data)
{
    return CRYPTO_set_ex_data(&(bio->ex_data), idx, data);
}

void *BIO_get_ex_data(BIO *bio, int idx)
{
    return CRYPTO_get_ex_data(&(bio->ex_data), idx);
}

uint64_t BIO_number_read(BIO *bio)
{
    if (bio)
        return bio->num_read;
    return 0;
}

uint64_t BIO_number_written(BIO *bio)
{
    if (bio)
        return bio->num_write;
    return 0;
}

void bio_free_ex_data(BIO *bio)
{
    CRYPTO_free_ex_data(CRYPTO_EX_INDEX_BIO, bio, &bio->ex_data);
}

void bio_cleanup(void)
{
#ifndef OPENSSL_NO_SOCK
    bio_sock_cleanup_int();
    CRYPTO_THREAD_lock_free(bio_lookup_lock);
    bio_lookup_lock = NULL;
#endif
    CRYPTO_THREAD_lock_free(bio_type_lock);
    bio_type_lock = NULL;
}

