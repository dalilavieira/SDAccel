#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_17__   TYPE_2__ ;
typedef  struct TYPE_16__   TYPE_1__ ;

/* Type definitions */
struct TYPE_17__ {char* ptr; int init; int /*<<< orphan*/ * next_bio; scalar_t__ flags; } ;
struct TYPE_16__ {int lrn; int lwn; } ;
typedef  TYPE_1__ NBIO_TEST ;
typedef  int /*<<< orphan*/  BIO_info_cb ;
typedef  int /*<<< orphan*/  BIO_METHOD ;
typedef  TYPE_2__ BIO ;

/* Variables and functions */
#define  BIO_CTRL_DUP 129 
#define  BIO_C_DO_STATE_MACHINE 128 
 int /*<<< orphan*/  BIO_F_NBIOF_NEW ; 
 long BIO_callback_ctrl (int /*<<< orphan*/ *,int,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  BIO_clear_retry_flags (TYPE_2__*) ; 
 int /*<<< orphan*/  BIO_copy_next_retry (TYPE_2__*) ; 
 long BIO_ctrl (int /*<<< orphan*/ *,int,long,void*) ; 
 int BIO_gets (int /*<<< orphan*/ *,char*,int) ; 
 int BIO_puts (int /*<<< orphan*/ *,char const*) ; 
 int BIO_read (int /*<<< orphan*/ *,char*,int) ; 
 int /*<<< orphan*/  BIO_set_retry_read (TYPE_2__*) ; 
 int /*<<< orphan*/  BIO_set_retry_write (TYPE_2__*) ; 
 int BIO_write (int /*<<< orphan*/ *,char const*,int) ; 
 int /*<<< orphan*/  BIOerr (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ERR_R_MALLOC_FAILURE ; 
 int /*<<< orphan*/  OPENSSL_free (char*) ; 
 TYPE_1__* OPENSSL_zalloc (int) ; 
 scalar_t__ RAND_priv_bytes (unsigned char*,int) ; 
 int /*<<< orphan*/  const methods_nbiof ; 

const BIO_METHOD *BIO_f_nbio_test(void)
{
    return &methods_nbiof;
}

__attribute__((used)) static int nbiof_new(BIO *bi)
{
    NBIO_TEST *nt;

    if ((nt = OPENSSL_zalloc(sizeof(*nt))) == NULL) {
        BIOerr(BIO_F_NBIOF_NEW, ERR_R_MALLOC_FAILURE);
        return 0;
    }
    nt->lrn = -1;
    nt->lwn = -1;
    bi->ptr = (char *)nt;
    bi->init = 1;
    return 1;
}

__attribute__((used)) static int nbiof_free(BIO *a)
{
    if (a == NULL)
        return 0;
    OPENSSL_free(a->ptr);
    a->ptr = NULL;
    a->init = 0;
    a->flags = 0;
    return 1;
}

__attribute__((used)) static int nbiof_read(BIO *b, char *out, int outl)
{
    int ret = 0;
    int num;
    unsigned char n;

    if (out == NULL)
        return 0;
    if (b->next_bio == NULL)
        return 0;

    BIO_clear_retry_flags(b);
    if (RAND_priv_bytes(&n, 1) <= 0)
        return -1;
    num = (n & 0x07);

    if (outl > num)
        outl = num;

    if (num == 0) {
        ret = -1;
        BIO_set_retry_read(b);
    } else {
        ret = BIO_read(b->next_bio, out, outl);
        if (ret < 0)
            BIO_copy_next_retry(b);
    }
    return ret;
}

__attribute__((used)) static int nbiof_write(BIO *b, const char *in, int inl)
{
    NBIO_TEST *nt;
    int ret = 0;
    int num;
    unsigned char n;

    if ((in == NULL) || (inl <= 0))
        return 0;
    if (b->next_bio == NULL)
        return 0;
    nt = (NBIO_TEST *)b->ptr;

    BIO_clear_retry_flags(b);

    if (nt->lwn > 0) {
        num = nt->lwn;
        nt->lwn = 0;
    } else {
        if (RAND_priv_bytes(&n, 1) <= 0)
            return -1;
        num = (n & 7);
    }

    if (inl > num)
        inl = num;

    if (num == 0) {
        ret = -1;
        BIO_set_retry_write(b);
    } else {
        ret = BIO_write(b->next_bio, in, inl);
        if (ret < 0) {
            BIO_copy_next_retry(b);
            nt->lwn = inl;
        }
    }
    return ret;
}

__attribute__((used)) static long nbiof_ctrl(BIO *b, int cmd, long num, void *ptr)
{
    long ret;

    if (b->next_bio == NULL)
        return 0;
    switch (cmd) {
    case BIO_C_DO_STATE_MACHINE:
        BIO_clear_retry_flags(b);
        ret = BIO_ctrl(b->next_bio, cmd, num, ptr);
        BIO_copy_next_retry(b);
        break;
    case BIO_CTRL_DUP:
        ret = 0L;
        break;
    default:
        ret = BIO_ctrl(b->next_bio, cmd, num, ptr);
        break;
    }
    return ret;
}

__attribute__((used)) static long nbiof_callback_ctrl(BIO *b, int cmd, BIO_info_cb *fp)
{
    long ret = 1;

    if (b->next_bio == NULL)
        return 0;
    switch (cmd) {
    default:
        ret = BIO_callback_ctrl(b->next_bio, cmd, fp);
        break;
    }
    return ret;
}

__attribute__((used)) static int nbiof_gets(BIO *bp, char *buf, int size)
{
    if (bp->next_bio == NULL)
        return 0;
    return BIO_gets(bp->next_bio, buf, size);
}

__attribute__((used)) static int nbiof_puts(BIO *bp, const char *str)
{
    if (bp->next_bio == NULL)
        return 0;
    return BIO_puts(bp->next_bio, str);
}

