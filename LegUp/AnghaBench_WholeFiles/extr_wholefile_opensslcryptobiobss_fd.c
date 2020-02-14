#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_15__   TYPE_1__ ;

/* Type definitions */
struct TYPE_15__ {int init; int num; int shutdown; void* flags; int /*<<< orphan*/ * ptr; } ;
typedef  int /*<<< orphan*/  BIO_METHOD ;
typedef  TYPE_1__ BIO ;

/* Variables and functions */
#define  BIO_CTRL_DUP 139 
#define  BIO_CTRL_FLUSH 138 
#define  BIO_CTRL_GET_CLOSE 137 
#define  BIO_CTRL_INFO 136 
#define  BIO_CTRL_PENDING 135 
#define  BIO_CTRL_RESET 134 
#define  BIO_CTRL_SET_CLOSE 133 
#define  BIO_CTRL_WPENDING 132 
#define  BIO_C_FILE_SEEK 131 
#define  BIO_C_FILE_TELL 130 
#define  BIO_C_GET_FD 129 
#define  BIO_C_SET_FD 128 
 void* BIO_FLAGS_UPLINK ; 
 int /*<<< orphan*/  BIO_clear_retry_flags (TYPE_1__*) ; 
 int BIO_fd_non_fatal_error (int) ; 
 int BIO_fd_should_retry (int) ; 
 TYPE_1__* BIO_new (int /*<<< orphan*/  const*) ; 
 int /*<<< orphan*/  BIO_set_fd (TYPE_1__*,int,int) ; 
 int /*<<< orphan*/  BIO_set_retry_read (TYPE_1__*) ; 
 int /*<<< orphan*/  BIO_set_retry_write (TYPE_1__*) ; 
 int /*<<< orphan*/  UP_close (int) ; 
 scalar_t__ UP_lseek (int,long,int) ; 
 int UP_read (int,char*,int) ; 
 int UP_write (int,char const*,int) ; 
 int /*<<< orphan*/  clear_sys_error () ; 
 int get_last_sys_error () ; 
 int /*<<< orphan*/  const methods_fdp ; 
 int strlen (char const*) ; 

const BIO_METHOD *BIO_s_fd(void)
{
    return &methods_fdp;
}

BIO *BIO_new_fd(int fd, int close_flag)
{
    BIO *ret;
    ret = BIO_new(BIO_s_fd());
    if (ret == NULL)
        return NULL;
    BIO_set_fd(ret, fd, close_flag);
    return ret;
}

__attribute__((used)) static int fd_new(BIO *bi)
{
    bi->init = 0;
    bi->num = -1;
    bi->ptr = NULL;
    bi->flags = BIO_FLAGS_UPLINK; /* essentially redundant */
    return 1;
}

__attribute__((used)) static int fd_free(BIO *a)
{
    if (a == NULL)
        return 0;
    if (a->shutdown) {
        if (a->init) {
            UP_close(a->num);
        }
        a->init = 0;
        a->flags = BIO_FLAGS_UPLINK;
    }
    return 1;
}

__attribute__((used)) static int fd_read(BIO *b, char *out, int outl)
{
    int ret = 0;

    if (out != NULL) {
        clear_sys_error();
        ret = UP_read(b->num, out, outl);
        BIO_clear_retry_flags(b);
        if (ret <= 0) {
            if (BIO_fd_should_retry(ret))
                BIO_set_retry_read(b);
        }
    }
    return ret;
}

__attribute__((used)) static int fd_write(BIO *b, const char *in, int inl)
{
    int ret;
    clear_sys_error();
    ret = UP_write(b->num, in, inl);
    BIO_clear_retry_flags(b);
    if (ret <= 0) {
        if (BIO_fd_should_retry(ret))
            BIO_set_retry_write(b);
    }
    return ret;
}

__attribute__((used)) static long fd_ctrl(BIO *b, int cmd, long num, void *ptr)
{
    long ret = 1;
    int *ip;

    switch (cmd) {
    case BIO_CTRL_RESET:
        num = 0;
        /* fall thru */
    case BIO_C_FILE_SEEK:
        ret = (long)UP_lseek(b->num, num, 0);
        break;
    case BIO_C_FILE_TELL:
    case BIO_CTRL_INFO:
        ret = (long)UP_lseek(b->num, 0, 1);
        break;
    case BIO_C_SET_FD:
        fd_free(b);
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
    case BIO_CTRL_PENDING:
    case BIO_CTRL_WPENDING:
        ret = 0;
        break;
    case BIO_CTRL_DUP:
    case BIO_CTRL_FLUSH:
        ret = 1;
        break;
    default:
        ret = 0;
        break;
    }
    return ret;
}

__attribute__((used)) static int fd_puts(BIO *bp, const char *str)
{
    int n, ret;

    n = strlen(str);
    ret = fd_write(bp, str, n);
    return ret;
}

__attribute__((used)) static int fd_gets(BIO *bp, char *buf, int size)
{
    int ret = 0;
    char *ptr = buf;
    char *end = buf + size - 1;

    while (ptr < end && fd_read(bp, ptr, 1) > 0) {
        if (*ptr++ == '\n')
           break;
    }

    ptr[0] = '\0';

    if (buf[0] != '\0')
        ret = strlen(buf);
    return ret;
}

int BIO_fd_should_retry(int i)
{
    int err;

    if ((i == 0) || (i == -1)) {
        err = get_last_sys_error();

        return BIO_fd_non_fatal_error(err);
    }
    return 0;
}

int BIO_fd_non_fatal_error(int err)
{
    switch (err) {

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

