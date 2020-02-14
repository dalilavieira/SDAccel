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
typedef  int /*<<< orphan*/  BIO_info_cb ;
typedef  int /*<<< orphan*/  const BIO_METHOD ;
typedef  int /*<<< orphan*/  BIO ;

/* Variables and functions */
#define  BIO_CTRL_RESET 128 
 int BIO_TYPE_FILTER ; 
 int BIO_TYPE_START ; 
 long BIO_callback_ctrl (int /*<<< orphan*/ *,int,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  BIO_clear_retry_flags (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  BIO_copy_next_retry (int /*<<< orphan*/ *) ; 
 long BIO_ctrl (int /*<<< orphan*/ *,int,long,void*) ; 
 int /*<<< orphan*/ * BIO_get_data (int /*<<< orphan*/ *) ; 
 int BIO_gets (int /*<<< orphan*/ *,char*,int) ; 
 int /*<<< orphan*/  const* BIO_meth_new (int,char*) ; 
 int /*<<< orphan*/  BIO_meth_set_callback_ctrl (int /*<<< orphan*/  const*,long (*) (int /*<<< orphan*/ *,int,int /*<<< orphan*/ *)) ; 
 int /*<<< orphan*/  BIO_meth_set_create (int /*<<< orphan*/  const*,int (*) (int /*<<< orphan*/ *)) ; 
 int /*<<< orphan*/  BIO_meth_set_ctrl (int /*<<< orphan*/  const*,long (*) (int /*<<< orphan*/ *,int,long,void*)) ; 
 int /*<<< orphan*/  BIO_meth_set_destroy (int /*<<< orphan*/  const*,int (*) (int /*<<< orphan*/ *)) ; 
 int /*<<< orphan*/  BIO_meth_set_gets (int /*<<< orphan*/  const*,int (*) (int /*<<< orphan*/ *,char*,int)) ; 
 int /*<<< orphan*/  BIO_meth_set_puts (int /*<<< orphan*/  const*,int (*) (int /*<<< orphan*/ *,char const*)) ; 
 int /*<<< orphan*/  BIO_meth_set_read_ex (int /*<<< orphan*/  const*,int (*) (int /*<<< orphan*/ *,char*,size_t,size_t*)) ; 
 int /*<<< orphan*/  BIO_meth_set_write_ex (int /*<<< orphan*/  const*,int (*) (int /*<<< orphan*/ *,char const*,size_t,size_t*)) ; 
 int /*<<< orphan*/ * BIO_next (int /*<<< orphan*/ *) ; 
 int BIO_read_ex (int /*<<< orphan*/ *,char*,size_t,size_t*) ; 
 int /*<<< orphan*/  BIO_set_data (int /*<<< orphan*/ *,char*) ; 
 int /*<<< orphan*/  BIO_set_init (int /*<<< orphan*/ *,int) ; 
 scalar_t__ BIO_write_ex (int /*<<< orphan*/ *,char const*,size_t,size_t*) ; 
 size_t strlen (char const*) ; 
 int subtest_level () ; 
static  long tap_callback_ctrl (int /*<<< orphan*/ *,int,int /*<<< orphan*/ *) ; 
static  long tap_ctrl (int /*<<< orphan*/ *,int,long,void*) ; 
static  int tap_free (int /*<<< orphan*/ *) ; 
static  int tap_gets (int /*<<< orphan*/ *,char*,int) ; 
static  int tap_new (int /*<<< orphan*/ *) ; 
static  int tap_puts (int /*<<< orphan*/ *,char const*) ; 
static  int tap_read_ex (int /*<<< orphan*/ *,char*,size_t,size_t*) ; 
static  int tap_write_ex (int /*<<< orphan*/ *,char const*,size_t,size_t*) ; 

const BIO_METHOD *BIO_f_tap(void)
{
    static BIO_METHOD *tap = NULL;

    if (tap == NULL) {
        tap = BIO_meth_new(BIO_TYPE_START | BIO_TYPE_FILTER, "tap");
        if (tap != NULL) {
            BIO_meth_set_write_ex(tap, tap_write_ex);
            BIO_meth_set_read_ex(tap, tap_read_ex);
            BIO_meth_set_puts(tap, tap_puts);
            BIO_meth_set_gets(tap, tap_gets);
            BIO_meth_set_ctrl(tap, tap_ctrl);
            BIO_meth_set_create(tap, tap_new);
            BIO_meth_set_destroy(tap, tap_free);
            BIO_meth_set_callback_ctrl(tap, tap_callback_ctrl);
        }
    }
    return tap;
}

__attribute__((used)) static int tap_new(BIO *b)
{
    BIO_set_data(b, NULL);
    BIO_set_init(b, 1);
    return 1;
}

__attribute__((used)) static int tap_free(BIO *b)
{
    if (b == NULL)
        return 0;
    BIO_set_data(b, NULL);
    BIO_set_init(b, 0);
    return 1;
}

__attribute__((used)) static int tap_read_ex(BIO *b, char *buf, size_t size, size_t *out_size)
{
    BIO *next = BIO_next(b);
    int ret = 0;

    ret = BIO_read_ex(next, buf, size, out_size);
    BIO_clear_retry_flags(b);
    BIO_copy_next_retry(b);
    return ret;
}

__attribute__((used)) static int write_string(BIO *b, const char *buf, size_t n)
{
    size_t m;

    return BIO_write_ex(b, buf, n, &m) != 0 && m == n;
}

__attribute__((used)) static int tap_write_ex(BIO *b, const char *buf, size_t size, size_t *in_size)
{
    static char empty[] = "";
    BIO *next = BIO_next(b);
    size_t i;
    int j;

    for (i = 0; i < size; i++) {
        if (BIO_get_data(b) == NULL) {
            BIO_set_data(b, empty);
            for (j = 0; j < subtest_level(); j++)
                if (!write_string(next, " ", 1))
                    goto err;
            if (!write_string(next, "# ", 2))
                goto err;
        }
        if (!write_string(next, buf + i, 1))
            goto err;
        if (buf[i] == '\n')
            BIO_set_data(b, NULL);
    }
    *in_size = i;
    return 1;

err:
    *in_size = i;
    return 0;
}

__attribute__((used)) static long tap_ctrl(BIO *b, int cmd, long num, void *ptr)
{
    BIO *next = BIO_next(b);

    switch (cmd) {
    case BIO_CTRL_RESET:
        BIO_set_data(b, NULL);
        break;

    default:
        break;
    }
    return BIO_ctrl(next, cmd, num, ptr);
}

__attribute__((used)) static long tap_callback_ctrl(BIO *b, int cmd, BIO_info_cb *fp)
{
    return BIO_callback_ctrl(BIO_next(b), cmd, fp);
}

__attribute__((used)) static int tap_gets(BIO *b, char *buf, int size)
{
    return BIO_gets(BIO_next(b), buf, size);
}

__attribute__((used)) static int tap_puts(BIO *b, const char *str)
{
    size_t m;

    if (!tap_write_ex(b, str, strlen(str), &m))
        return 0;
    return m;
}

