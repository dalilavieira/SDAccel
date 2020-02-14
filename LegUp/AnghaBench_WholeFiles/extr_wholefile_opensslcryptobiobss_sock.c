#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_20__   TYPE_1__ ;

/* Type definitions */
struct tls12_crypto_info_aes_gcm_128 {int dummy; } ;
struct TYPE_20__ {int init; int num; int shutdown; int /*<<< orphan*/ * ptr; scalar_t__ flags; } ;
typedef  int /*<<< orphan*/  BIO_METHOD ;
typedef  TYPE_1__ BIO ;

/* Variables and functions */
#define  BIO_CTRL_CLEAR_KTLS_TX_CTRL_MSG 138 
#define  BIO_CTRL_DUP 137 
#define  BIO_CTRL_FLUSH 136 
#define  BIO_CTRL_GET_CLOSE 135 
#define  BIO_CTRL_GET_KTLS_RECV 134 
#define  BIO_CTRL_GET_KTLS_SEND 133 
#define  BIO_CTRL_SET_CLOSE 132 
#define  BIO_CTRL_SET_KTLS 131 
#define  BIO_CTRL_SET_KTLS_TX_SEND_CTRL_MSG 130 
#define  BIO_C_GET_FD 129 
#define  BIO_C_SET_FD 128 
 int /*<<< orphan*/  BIO_clear_ktls_ctrl_msg_flag (TYPE_1__*) ; 
 int /*<<< orphan*/  BIO_clear_retry_flags (TYPE_1__*) ; 
 int /*<<< orphan*/  BIO_closesocket (int) ; 
 scalar_t__ BIO_get_ktls_recv (TYPE_1__*) ; 
 TYPE_1__* BIO_new (int /*<<< orphan*/  const*) ; 
 int /*<<< orphan*/  BIO_set_fd (TYPE_1__*,int,int) ; 
 int /*<<< orphan*/  BIO_set_ktls_ctrl_msg_flag (TYPE_1__*) ; 
 int /*<<< orphan*/  BIO_set_ktls_flag (TYPE_1__*,long) ; 
 int /*<<< orphan*/  BIO_set_retry_read (TYPE_1__*) ; 
 int /*<<< orphan*/  BIO_set_retry_write (TYPE_1__*) ; 
 scalar_t__ BIO_should_ktls_ctrl_msg_flag (TYPE_1__*) ; 
 long BIO_should_ktls_flag (TYPE_1__*,int) ; 
 int BIO_sock_non_fatal_error (int) ; 
 int BIO_sock_should_retry (int) ; 
 int /*<<< orphan*/  clear_socket_error () ; 
 int get_last_socket_error () ; 
 int /*<<< orphan*/  ktls_enable (int) ; 
 int ktls_read_record (int,char*,int) ; 
 int ktls_send_ctrl_message (int,unsigned char,char const*,int) ; 
 long ktls_start (long,struct tls12_crypto_info_aes_gcm_128*,int,long) ; 
 int /*<<< orphan*/  const methods_sockp ; 
 int readsocket (int,char*,int) ; 
 int strlen (char const*) ; 
 int writesocket (int,char const*,int) ; 

const BIO_METHOD *BIO_s_socket(void)
{
    return &methods_sockp;
}

BIO *BIO_new_socket(int fd, int close_flag)
{
    BIO *ret;

    ret = BIO_new(BIO_s_socket());
    if (ret == NULL)
        return NULL;
    BIO_set_fd(ret, fd, close_flag);
# ifndef OPENSSL_NO_KTLS
    {
        /*
         * The new socket is created successfully regardless of ktls_enable.
         * ktls_enable doesn't change any functionality of the socket, except
         * changing the setsockopt to enable the processing of ktls_start.
         * Thus, it is not a problem to call it for non-TLS sockets.
         */
        ktls_enable(fd);
    }
# endif
    return ret;
}

__attribute__((used)) static int sock_new(BIO *bi)
{
    bi->init = 0;
    bi->num = 0;
    bi->ptr = NULL;
    bi->flags = 0;
    return 1;
}

__attribute__((used)) static int sock_free(BIO *a)
{
    if (a == NULL)
        return 0;
    if (a->shutdown) {
        if (a->init) {
            BIO_closesocket(a->num);
        }
        a->init = 0;
        a->flags = 0;
    }
    return 1;
}

__attribute__((used)) static int sock_read(BIO *b, char *out, int outl)
{
    int ret = 0;

    if (out != NULL) {
        clear_socket_error();
# ifndef OPENSSL_NO_KTLS
        if (BIO_get_ktls_recv(b))
            ret = ktls_read_record(b->num, out, outl);
        else
# endif
            ret = readsocket(b->num, out, outl);
        BIO_clear_retry_flags(b);
        if (ret <= 0) {
            if (BIO_sock_should_retry(ret))
                BIO_set_retry_read(b);
        }
    }
    return ret;
}

__attribute__((used)) static int sock_write(BIO *b, const char *in, int inl)
{
    int ret = 0;

    clear_socket_error();
# ifndef OPENSSL_NO_KTLS
    if (BIO_should_ktls_ctrl_msg_flag(b)) {
        unsigned char record_type = (intptr_t)b->ptr;
        ret = ktls_send_ctrl_message(b->num, record_type, in, inl);
        if (ret >= 0) {
            ret = inl;
            BIO_clear_ktls_ctrl_msg_flag(b);
        }
    } else
# endif
        ret = writesocket(b->num, in, inl);
    BIO_clear_retry_flags(b);
    if (ret <= 0) {
        if (BIO_sock_should_retry(ret))
            BIO_set_retry_write(b);
    }
    return ret;
}

__attribute__((used)) static long sock_ctrl(BIO *b, int cmd, long num, void *ptr)
{
    long ret = 1;
    int *ip;
# ifndef OPENSSL_NO_KTLS
    struct tls12_crypto_info_aes_gcm_128 *crypto_info;
# endif

    switch (cmd) {
    case BIO_C_SET_FD:
        sock_free(b);
        b->num = *((int *)ptr);
        b->shutdown = (int)num;
        b->init = 1;
        break;
    case BIO_C_GET_FD:
        if (b->init) {
            ip = (int *)ptr;
            if (ip != NULL)
                *ip = b->num;
            ret = b->num;
        } else
            ret = -1;
        break;
    case BIO_CTRL_GET_CLOSE:
        ret = b->shutdown;
        break;
    case BIO_CTRL_SET_CLOSE:
        b->shutdown = (int)num;
        break;
    case BIO_CTRL_DUP:
    case BIO_CTRL_FLUSH:
        ret = 1;
        break;
# ifndef OPENSSL_NO_KTLS
    case BIO_CTRL_SET_KTLS:
        crypto_info = (struct tls12_crypto_info_aes_gcm_128 *)ptr;
        ret = ktls_start(b->num, crypto_info, sizeof(*crypto_info), num);
        if (ret)
            BIO_set_ktls_flag(b, num);
        break;
    case BIO_CTRL_GET_KTLS_SEND:
        return BIO_should_ktls_flag(b, 1);
    case BIO_CTRL_GET_KTLS_RECV:
        return BIO_should_ktls_flag(b, 0);
    case BIO_CTRL_SET_KTLS_TX_SEND_CTRL_MSG:
        BIO_set_ktls_ctrl_msg_flag(b);
        b->ptr = (void *)num;
        ret = 0;
        break;
    case BIO_CTRL_CLEAR_KTLS_TX_CTRL_MSG:
        BIO_clear_ktls_ctrl_msg_flag(b);
        ret = 0;
        break;
# endif
    default:
        ret = 0;
        break;
    }
    return ret;
}

__attribute__((used)) static int sock_puts(BIO *bp, const char *str)
{
    int n, ret;

    n = strlen(str);
    ret = sock_write(bp, str, n);
    return ret;
}

int BIO_sock_should_retry(int i)
{
    int err;

    if ((i == 0) || (i == -1)) {
        err = get_last_socket_error();

        return BIO_sock_non_fatal_error(err);
    }
    return 0;
}

int BIO_sock_non_fatal_error(int err)
{
    switch (err) {
# if defined(OPENSSL_SYS_WINDOWS)
#  if defined(WSAEWOULDBLOCK)
    case WSAEWOULDBLOCK:
#  endif
# endif

# ifdef EWOULDBLOCK
#  ifdef WSAEWOULDBLOCK
#   if WSAEWOULDBLOCK != EWOULDBLOCK
    case EWOULDBLOCK:
#   endif
#  else
    case EWOULDBLOCK:
#  endif
# endif

# if defined(ENOTCONN)
    case ENOTCONN:
# endif

# ifdef EINTR
    case EINTR:
# endif

# ifdef EAGAIN
#  if EWOULDBLOCK != EAGAIN
    case EAGAIN:
#  endif
# endif

# ifdef EPROTO
    case EPROTO:
# endif

# ifdef EINPROGRESS
    case EINPROGRESS:
# endif

# ifdef EALREADY
    case EALREADY:
# endif
        return 1;
    default:
        break;
    }
    return 0;
}

