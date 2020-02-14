#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_29__   TYPE_3__ ;
typedef  struct TYPE_28__   TYPE_2__ ;
typedef  struct TYPE_27__   TYPE_1__ ;

/* Type definitions */
struct TYPE_29__ {size_t renegotiate_count; size_t byte_count; long num_renegotiates; unsigned long renegotiate_timeout; unsigned long last_time; TYPE_2__* ssl; } ;
struct TYPE_28__ {void* rbio; void* wbio; TYPE_1__* method; int /*<<< orphan*/  handshake_func; } ;
struct TYPE_27__ {int /*<<< orphan*/  ssl_accept; int /*<<< orphan*/  ssl_connect; } ;
typedef  int /*<<< orphan*/  SSL_CTX ;
typedef  TYPE_2__ SSL ;
typedef  int /*<<< orphan*/  BIO_info_cb ;
typedef  TYPE_3__ BIO_SSL ;
typedef  int /*<<< orphan*/  BIO_METHOD ;
typedef  void BIO ;

/* Variables and functions */
 int /*<<< orphan*/  BIO_CLOSE ; 
#define  BIO_CTRL_DUP 155 
#define  BIO_CTRL_FLUSH 154 
#define  BIO_CTRL_GET_CLOSE 153 
#define  BIO_CTRL_INFO 152 
#define  BIO_CTRL_PENDING 151 
#define  BIO_CTRL_POP 150 
#define  BIO_CTRL_PUSH 149 
#define  BIO_CTRL_RESET 148 
#define  BIO_CTRL_SET_CALLBACK 147 
#define  BIO_CTRL_SET_CLOSE 146 
#define  BIO_CTRL_WPENDING 145 
#define  BIO_C_DO_STATE_MACHINE 144 
#define  BIO_C_GET_FD 143 
#define  BIO_C_GET_SSL 142 
#define  BIO_C_GET_SSL_NUM_RENEGOTIATES 141 
#define  BIO_C_SET_SSL 140 
#define  BIO_C_SET_SSL_RENEGOTIATE_BYTES 139 
#define  BIO_C_SET_SSL_RENEGOTIATE_TIMEOUT 138 
#define  BIO_C_SSL_MODE 137 
 int BIO_FLAGS_IO_SPECIAL ; 
 int BIO_FLAGS_READ ; 
 int BIO_FLAGS_SHOULD_RETRY ; 
 int BIO_FLAGS_WRITE ; 
 int /*<<< orphan*/  BIO_F_SSL_NEW ; 
 int BIO_RR_ACCEPT ; 
 int BIO_RR_CONNECT ; 
 int BIO_RR_SSL_X509_LOOKUP ; 
 scalar_t__ BIO_TYPE_SSL ; 
 long BIO_callback_ctrl (void*,int,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  BIO_clear_flags (void*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  BIO_clear_retry_flags (void*) ; 
 int /*<<< orphan*/  BIO_copy_next_retry (void*) ; 
 long BIO_ctrl (void*,int,long,void*) ; 
 int /*<<< orphan*/  const* BIO_f_buffer () ; 
 void* BIO_find_type (void*,scalar_t__) ; 
 int /*<<< orphan*/  BIO_free (void*) ; 
 TYPE_3__* BIO_get_data (void*) ; 
 scalar_t__ BIO_get_init (void*) ; 
 int BIO_get_retry_reason (void*) ; 
 long BIO_get_shutdown (void*) ; 
 scalar_t__ BIO_method_type (void*) ; 
 void* BIO_new (int /*<<< orphan*/  const*) ; 
 void* BIO_new_ssl (int /*<<< orphan*/ *,int) ; 
 void* BIO_new_ssl_connect (int /*<<< orphan*/ *) ; 
 void* BIO_next (void*) ; 
 long BIO_pending (void*) ; 
 void* BIO_push (void*,void*) ; 
 int /*<<< orphan*/  const* BIO_s_connect () ; 
 int /*<<< orphan*/  BIO_set_data (void*,TYPE_3__*) ; 
 int /*<<< orphan*/  BIO_set_flags (void*,int) ; 
 int /*<<< orphan*/  BIO_set_init (void*,int) ; 
 int /*<<< orphan*/  BIO_set_next (void*,void*) ; 
 int /*<<< orphan*/  BIO_set_retry_read (void*) ; 
 int /*<<< orphan*/  BIO_set_retry_reason (void*,int) ; 
 int /*<<< orphan*/  BIO_set_retry_special (void*) ; 
 int /*<<< orphan*/  BIO_set_retry_write (void*) ; 
 int /*<<< orphan*/  BIO_set_shutdown (void*,int) ; 
 int /*<<< orphan*/  BIO_set_ssl (void*,TYPE_2__*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  BIO_up_ref (void*) ; 
 int BIO_write (void*,char const*,int) ; 
 int /*<<< orphan*/  BIOerr (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ERR_R_MALLOC_FAILURE ; 
 int /*<<< orphan*/  OPENSSL_free (TYPE_3__*) ; 
 TYPE_3__* OPENSSL_zalloc (int) ; 
#define  SSL_ERROR_NONE 136 
#define  SSL_ERROR_SSL 135 
#define  SSL_ERROR_SYSCALL 134 
#define  SSL_ERROR_WANT_ACCEPT 133 
#define  SSL_ERROR_WANT_CONNECT 132 
#define  SSL_ERROR_WANT_READ 131 
#define  SSL_ERROR_WANT_WRITE 130 
#define  SSL_ERROR_WANT_X509_LOOKUP 129 
#define  SSL_ERROR_ZERO_RETURN 128 
 int /*<<< orphan*/  SSL_clear (TYPE_2__*) ; 
 int /*<<< orphan*/  SSL_copy_session_id (TYPE_2__*,TYPE_2__*) ; 
 scalar_t__ SSL_do_handshake (TYPE_2__*) ; 
 TYPE_2__* SSL_dup (TYPE_2__*) ; 
 int /*<<< orphan*/  SSL_free (TYPE_2__*) ; 
 int SSL_get_error (TYPE_2__*,int) ; 
 void* SSL_get_rbio (TYPE_2__*) ; 
 TYPE_2__* SSL_new (int /*<<< orphan*/ *) ; 
 long SSL_pending (TYPE_2__*) ; 
 int /*<<< orphan*/  SSL_renegotiate (TYPE_2__*) ; 
 int /*<<< orphan*/  SSL_set_accept_state (TYPE_2__*) ; 
 int /*<<< orphan*/  SSL_set_bio (TYPE_2__*,void*,void*) ; 
 int /*<<< orphan*/  SSL_set_connect_state (TYPE_2__*) ; 
 int /*<<< orphan*/  SSL_shutdown (TYPE_2__*) ; 
 int /*<<< orphan*/  const methods_sslp ; 
 int ssl_read_internal (TYPE_2__*,char*,size_t,size_t*) ; 
 int ssl_write_internal (TYPE_2__*,char const*,size_t,size_t*) ; 
 int strlen (char const*) ; 
 scalar_t__ time (int /*<<< orphan*/ *) ; 

const BIO_METHOD *BIO_f_ssl(void)
{
    return &methods_sslp;
}

__attribute__((used)) static int ssl_new(BIO *bi)
{
    BIO_SSL *bs = OPENSSL_zalloc(sizeof(*bs));

    if (bs == NULL) {
        BIOerr(BIO_F_SSL_NEW, ERR_R_MALLOC_FAILURE);
        return 0;
    }
    BIO_set_init(bi, 0);
    BIO_set_data(bi, bs);
    /* Clear all flags */
    BIO_clear_flags(bi, ~0);

    return 1;
}

__attribute__((used)) static int ssl_free(BIO *a)
{
    BIO_SSL *bs;

    if (a == NULL)
        return 0;
    bs = BIO_get_data(a);
    if (bs->ssl != NULL)
        SSL_shutdown(bs->ssl);
    if (BIO_get_shutdown(a)) {
        if (BIO_get_init(a))
            SSL_free(bs->ssl);
        /* Clear all flags */
        BIO_clear_flags(a, ~0);
        BIO_set_init(a, 0);
    }
    OPENSSL_free(bs);
    return 1;
}

__attribute__((used)) static int ssl_read(BIO *b, char *buf, size_t size, size_t *readbytes)
{
    int ret = 1;
    BIO_SSL *sb;
    SSL *ssl;
    int retry_reason = 0;
    int r = 0;

    if (buf == NULL)
        return 0;
    sb = BIO_get_data(b);
    ssl = sb->ssl;

    BIO_clear_retry_flags(b);

    ret = ssl_read_internal(ssl, buf, size, readbytes);

    switch (SSL_get_error(ssl, ret)) {
    case SSL_ERROR_NONE:
        if (sb->renegotiate_count > 0) {
            sb->byte_count += *readbytes;
            if (sb->byte_count > sb->renegotiate_count) {
                sb->byte_count = 0;
                sb->num_renegotiates++;
                SSL_renegotiate(ssl);
                r = 1;
            }
        }
        if ((sb->renegotiate_timeout > 0) && (!r)) {
            unsigned long tm;

            tm = (unsigned long)time(NULL);
            if (tm > sb->last_time + sb->renegotiate_timeout) {
                sb->last_time = tm;
                sb->num_renegotiates++;
                SSL_renegotiate(ssl);
            }
        }

        break;
    case SSL_ERROR_WANT_READ:
        BIO_set_retry_read(b);
        break;
    case SSL_ERROR_WANT_WRITE:
        BIO_set_retry_write(b);
        break;
    case SSL_ERROR_WANT_X509_LOOKUP:
        BIO_set_retry_special(b);
        retry_reason = BIO_RR_SSL_X509_LOOKUP;
        break;
    case SSL_ERROR_WANT_ACCEPT:
        BIO_set_retry_special(b);
        retry_reason = BIO_RR_ACCEPT;
        break;
    case SSL_ERROR_WANT_CONNECT:
        BIO_set_retry_special(b);
        retry_reason = BIO_RR_CONNECT;
        break;
    case SSL_ERROR_SYSCALL:
    case SSL_ERROR_SSL:
    case SSL_ERROR_ZERO_RETURN:
    default:
        break;
    }

    BIO_set_retry_reason(b, retry_reason);

    return ret;
}

__attribute__((used)) static int ssl_write(BIO *b, const char *buf, size_t size, size_t *written)
{
    int ret, r = 0;
    int retry_reason = 0;
    SSL *ssl;
    BIO_SSL *bs;

    if (buf == NULL)
        return 0;
    bs = BIO_get_data(b);
    ssl = bs->ssl;

    BIO_clear_retry_flags(b);

    ret = ssl_write_internal(ssl, buf, size, written);

    switch (SSL_get_error(ssl, ret)) {
    case SSL_ERROR_NONE:
        if (bs->renegotiate_count > 0) {
            bs->byte_count += *written;
            if (bs->byte_count > bs->renegotiate_count) {
                bs->byte_count = 0;
                bs->num_renegotiates++;
                SSL_renegotiate(ssl);
                r = 1;
            }
        }
        if ((bs->renegotiate_timeout > 0) && (!r)) {
            unsigned long tm;

            tm = (unsigned long)time(NULL);
            if (tm > bs->last_time + bs->renegotiate_timeout) {
                bs->last_time = tm;
                bs->num_renegotiates++;
                SSL_renegotiate(ssl);
            }
        }
        break;
    case SSL_ERROR_WANT_WRITE:
        BIO_set_retry_write(b);
        break;
    case SSL_ERROR_WANT_READ:
        BIO_set_retry_read(b);
        break;
    case SSL_ERROR_WANT_X509_LOOKUP:
        BIO_set_retry_special(b);
        retry_reason = BIO_RR_SSL_X509_LOOKUP;
        break;
    case SSL_ERROR_WANT_CONNECT:
        BIO_set_retry_special(b);
        retry_reason = BIO_RR_CONNECT;
    case SSL_ERROR_SYSCALL:
    case SSL_ERROR_SSL:
    default:
        break;
    }

    BIO_set_retry_reason(b, retry_reason);

    return ret;
}

__attribute__((used)) static long ssl_ctrl(BIO *b, int cmd, long num, void *ptr)
{
    SSL **sslp, *ssl;
    BIO_SSL *bs, *dbs;
    BIO *dbio, *bio;
    long ret = 1;
    BIO *next;

    bs = BIO_get_data(b);
    next = BIO_next(b);
    ssl = bs->ssl;
    if ((ssl == NULL) && (cmd != BIO_C_SET_SSL))
        return 0;
    switch (cmd) {
    case BIO_CTRL_RESET:
        SSL_shutdown(ssl);

        if (ssl->handshake_func == ssl->method->ssl_connect)
            SSL_set_connect_state(ssl);
        else if (ssl->handshake_func == ssl->method->ssl_accept)
            SSL_set_accept_state(ssl);

        if (!SSL_clear(ssl)) {
            ret = 0;
            break;
        }

        if (next != NULL)
            ret = BIO_ctrl(next, cmd, num, ptr);
        else if (ssl->rbio != NULL)
            ret = BIO_ctrl(ssl->rbio, cmd, num, ptr);
        else
            ret = 1;
        break;
    case BIO_CTRL_INFO:
        ret = 0;
        break;
    case BIO_C_SSL_MODE:
        if (num)                /* client mode */
            SSL_set_connect_state(ssl);
        else
            SSL_set_accept_state(ssl);
        break;
    case BIO_C_SET_SSL_RENEGOTIATE_TIMEOUT:
        ret = bs->renegotiate_timeout;
        if (num < 60)
            num = 5;
        bs->renegotiate_timeout = (unsigned long)num;
        bs->last_time = (unsigned long)time(NULL);
        break;
    case BIO_C_SET_SSL_RENEGOTIATE_BYTES:
        ret = bs->renegotiate_count;
        if ((long)num >= 512)
            bs->renegotiate_count = (unsigned long)num;
        break;
    case BIO_C_GET_SSL_NUM_RENEGOTIATES:
        ret = bs->num_renegotiates;
        break;
    case BIO_C_SET_SSL:
        if (ssl != NULL) {
            ssl_free(b);
            if (!ssl_new(b))
                return 0;
        }
        BIO_set_shutdown(b, num);
        ssl = (SSL *)ptr;
        bs->ssl = ssl;
        bio = SSL_get_rbio(ssl);
        if (bio != NULL) {
            if (next != NULL)
                BIO_push(bio, next);
            BIO_set_next(b, bio);
            BIO_up_ref(bio);
        }
        BIO_set_init(b, 1);
        break;
    case BIO_C_GET_SSL:
        if (ptr != NULL) {
            sslp = (SSL **)ptr;
            *sslp = ssl;
        } else
            ret = 0;
        break;
    case BIO_CTRL_GET_CLOSE:
        ret = BIO_get_shutdown(b);
        break;
    case BIO_CTRL_SET_CLOSE:
        BIO_set_shutdown(b, (int)num);
        break;
    case BIO_CTRL_WPENDING:
        ret = BIO_ctrl(ssl->wbio, cmd, num, ptr);
        break;
    case BIO_CTRL_PENDING:
        ret = SSL_pending(ssl);
        if (ret == 0)
            ret = BIO_pending(ssl->rbio);
        break;
    case BIO_CTRL_FLUSH:
        BIO_clear_retry_flags(b);
        ret = BIO_ctrl(ssl->wbio, cmd, num, ptr);
        BIO_copy_next_retry(b);
        break;
    case BIO_CTRL_PUSH:
        if ((next != NULL) && (next != ssl->rbio)) {
            /*
             * We are going to pass ownership of next to the SSL object...but
             * we don't own a reference to pass yet - so up ref
             */
            BIO_up_ref(next);
            SSL_set_bio(ssl, next, next);
        }
        break;
    case BIO_CTRL_POP:
        /* Only detach if we are the BIO explicitly being popped */
        if (b == ptr) {
            /* This will clear the reference we obtained during push */
            SSL_set_bio(ssl, NULL, NULL);
        }
        break;
    case BIO_C_DO_STATE_MACHINE:
        BIO_clear_retry_flags(b);

        BIO_set_retry_reason(b, 0);
        ret = (int)SSL_do_handshake(ssl);

        switch (SSL_get_error(ssl, (int)ret)) {
        case SSL_ERROR_WANT_READ:
            BIO_set_flags(b, BIO_FLAGS_READ | BIO_FLAGS_SHOULD_RETRY);
            break;
        case SSL_ERROR_WANT_WRITE:
            BIO_set_flags(b, BIO_FLAGS_WRITE | BIO_FLAGS_SHOULD_RETRY);
            break;
        case SSL_ERROR_WANT_CONNECT:
            BIO_set_flags(b, BIO_FLAGS_IO_SPECIAL | BIO_FLAGS_SHOULD_RETRY);
            BIO_set_retry_reason(b, BIO_get_retry_reason(next));
            break;
        case SSL_ERROR_WANT_X509_LOOKUP:
            BIO_set_retry_special(b);
            BIO_set_retry_reason(b, BIO_RR_SSL_X509_LOOKUP);
            break;
        default:
            break;
        }
        break;
    case BIO_CTRL_DUP:
        dbio = (BIO *)ptr;
        dbs = BIO_get_data(dbio);
        SSL_free(dbs->ssl);
        dbs->ssl = SSL_dup(ssl);
        dbs->num_renegotiates = bs->num_renegotiates;
        dbs->renegotiate_count = bs->renegotiate_count;
        dbs->byte_count = bs->byte_count;
        dbs->renegotiate_timeout = bs->renegotiate_timeout;
        dbs->last_time = bs->last_time;
        ret = (dbs->ssl != NULL);
        break;
    case BIO_C_GET_FD:
        ret = BIO_ctrl(ssl->rbio, cmd, num, ptr);
        break;
    case BIO_CTRL_SET_CALLBACK:
        ret = 0; /* use callback ctrl */
        break;
    default:
        ret = BIO_ctrl(ssl->rbio, cmd, num, ptr);
        break;
    }
    return ret;
}

__attribute__((used)) static long ssl_callback_ctrl(BIO *b, int cmd, BIO_info_cb *fp)
{
    SSL *ssl;
    BIO_SSL *bs;
    long ret = 1;

    bs = BIO_get_data(b);
    ssl = bs->ssl;
    switch (cmd) {
    case BIO_CTRL_SET_CALLBACK:
        ret = BIO_callback_ctrl(ssl->rbio, cmd, fp);
        break;
    default:
        ret = 0;
        break;
    }
    return ret;
}

__attribute__((used)) static int ssl_puts(BIO *bp, const char *str)
{
    int n, ret;

    n = strlen(str);
    ret = BIO_write(bp, str, n);
    return ret;
}

BIO *BIO_new_buffer_ssl_connect(SSL_CTX *ctx)
{
#ifndef OPENSSL_NO_SOCK
    BIO *ret = NULL, *buf = NULL, *ssl = NULL;

    if ((buf = BIO_new(BIO_f_buffer())) == NULL)
        return NULL;
    if ((ssl = BIO_new_ssl_connect(ctx)) == NULL)
        goto err;
    if ((ret = BIO_push(buf, ssl)) == NULL)
        goto err;
    return ret;
 err:
    BIO_free(buf);
    BIO_free(ssl);
#endif
    return NULL;
}

BIO *BIO_new_ssl_connect(SSL_CTX *ctx)
{
#ifndef OPENSSL_NO_SOCK
    BIO *ret = NULL, *con = NULL, *ssl = NULL;

    if ((con = BIO_new(BIO_s_connect())) == NULL)
        return NULL;
    if ((ssl = BIO_new_ssl(ctx, 1)) == NULL)
        goto err;
    if ((ret = BIO_push(ssl, con)) == NULL)
        goto err;
    return ret;
 err:
    BIO_free(con);
#endif
    return NULL;
}

BIO *BIO_new_ssl(SSL_CTX *ctx, int client)
{
    BIO *ret;
    SSL *ssl;

    if ((ret = BIO_new(BIO_f_ssl())) == NULL)
        return NULL;
    if ((ssl = SSL_new(ctx)) == NULL) {
        BIO_free(ret);
        return NULL;
    }
    if (client)
        SSL_set_connect_state(ssl);
    else
        SSL_set_accept_state(ssl);

    BIO_set_ssl(ret, ssl, BIO_CLOSE);
    return ret;
}

int BIO_ssl_copy_session_id(BIO *t, BIO *f)
{
    BIO_SSL *tdata, *fdata;
    t = BIO_find_type(t, BIO_TYPE_SSL);
    f = BIO_find_type(f, BIO_TYPE_SSL);
    if ((t == NULL) || (f == NULL))
        return 0;
    tdata = BIO_get_data(t);
    fdata = BIO_get_data(f);
    if ((tdata->ssl == NULL) || (fdata->ssl == NULL))
        return 0;
    if (!SSL_copy_session_id(tdata->ssl, (fdata->ssl)))
        return 0;
    return 1;
}

void BIO_ssl_shutdown(BIO *b)
{
    BIO_SSL *bdata;

    for (; b != NULL; b = BIO_next(b)) {
        if (BIO_method_type(b) != BIO_TYPE_SSL)
            continue;
        bdata = BIO_get_data(b);
        if (bdata != NULL && bdata->ssl != NULL)
            SSL_shutdown(bdata->ssl);
    }
}

