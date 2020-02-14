#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_19__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  str ;
typedef  int /*<<< orphan*/  buf ;
struct TYPE_19__ {int length; char* data; int max; } ;
typedef  TYPE_1__ BUF_MEM ;
typedef  TYPE_1__ BIO ;

/* Variables and functions */
 int /*<<< orphan*/  ADD_TEST (int (*) ()) ; 
 int /*<<< orphan*/  BIO_CLOSE ; 
 int /*<<< orphan*/  BIO_FLAGS_MEM_RDONLY ; 
 int /*<<< orphan*/  BIO_NOCLOSE ; 
 int /*<<< orphan*/  BIO_clear_flags (TYPE_1__*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  BIO_free (TYPE_1__*) ; 
 int /*<<< orphan*/  BIO_get_mem_ptr (TYPE_1__*,TYPE_1__**) ; 
 TYPE_1__* BIO_new (int /*<<< orphan*/ ) ; 
 TYPE_1__* BIO_new_mem_buf (char*,int) ; 
 int /*<<< orphan*/  BIO_puts (TYPE_1__*,char*) ; 
 int /*<<< orphan*/  BIO_read (TYPE_1__*,char*,int) ; 
 int /*<<< orphan*/  BIO_reset (TYPE_1__*) ; 
 int /*<<< orphan*/  BIO_s_mem () ; 
 int /*<<< orphan*/  BIO_set_close (TYPE_1__*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  BIO_set_flags (TYPE_1__*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  BIO_set_mem_buf (TYPE_1__*,TYPE_1__*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  BIO_write (TYPE_1__*,char*,int) ; 
 int /*<<< orphan*/  BUF_MEM_free (TYPE_1__*) ; 
 int /*<<< orphan*/  CRYPTO_MEM_CHECK_ON ; 
 int /*<<< orphan*/  CRYPTO_mem_ctrl (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  CRYPTO_set_mem_debug (int) ; 
 int /*<<< orphan*/  TEST_int_eq (int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  TEST_int_gt (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  TEST_int_lt (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  TEST_mem_eq (char*,int,char const*,int) ; 
 int /*<<< orphan*/  TEST_ptr (TYPE_1__*) ; 

__attribute__((used)) static int test_bio_memleak(void)
{
    int ok = 0;
    BIO *bio;
    BUF_MEM bufmem;
    static const char str[] = "BIO test\n";
    char buf[100];

    bio = BIO_new(BIO_s_mem());
    if (!TEST_ptr(bio))
        goto finish;
    bufmem.length = sizeof(str);
    bufmem.data = (char *) str;
    bufmem.max = bufmem.length;
    BIO_set_mem_buf(bio, &bufmem, BIO_NOCLOSE);
    BIO_set_flags(bio, BIO_FLAGS_MEM_RDONLY);
    if (!TEST_int_eq(BIO_read(bio, buf, sizeof(buf)), sizeof(str)))
        goto finish;
    if (!TEST_mem_eq(buf, sizeof(str), str, sizeof(str)))
        goto finish;
    ok = 1;

finish:
    BIO_free(bio);
    return ok;
}

__attribute__((used)) static int test_bio_get_mem(void)
{
    int ok = 0;
    BIO *bio = NULL;
    BUF_MEM *bufmem = NULL;

    bio = BIO_new(BIO_s_mem());
    if (!TEST_ptr(bio))
        goto finish;
    if (!TEST_int_eq(BIO_puts(bio, "Hello World\n"), 12))
        goto finish;
    BIO_get_mem_ptr(bio, &bufmem);
    if (!TEST_ptr(bufmem))
        goto finish;
    if (!TEST_int_gt(BIO_set_close(bio, BIO_NOCLOSE), 0))
        goto finish;
    BIO_free(bio);
    bio = NULL;
    if (!TEST_mem_eq(bufmem->data, bufmem->length, "Hello World\n", 12))
        goto finish;
    ok = 1;

finish:
    BIO_free(bio);
    BUF_MEM_free(bufmem);
    return ok;
}

__attribute__((used)) static int test_bio_new_mem_buf(void)
{
    int ok = 0;
    BIO *bio;
    BUF_MEM *bufmem;
    char data[16];

    bio = BIO_new_mem_buf("Hello World\n", 12);
    if (!TEST_ptr(bio))
        goto finish;
    if (!TEST_int_eq(BIO_read(bio, data, 5), 5))
        goto finish;
    if (!TEST_mem_eq(data, 5, "Hello", 5))
        goto finish;
    if (!TEST_int_gt(BIO_get_mem_ptr(bio, &bufmem), 0))
        goto finish;
    if (!TEST_int_lt(BIO_write(bio, "test", 4), 0))
        goto finish;
    if (!TEST_int_eq(BIO_read(bio, data, 16), 7))
        goto finish;
    if (!TEST_mem_eq(data, 7, " World\n", 7))
        goto finish;
    if (!TEST_int_gt(BIO_reset(bio), 0))
        goto finish;
    if (!TEST_int_eq(BIO_read(bio, data, 16), 12))
        goto finish;
    if (!TEST_mem_eq(data, 12, "Hello World\n", 12))
        goto finish;
    ok = 1;

finish:
    BIO_free(bio);
    return ok;
}

__attribute__((used)) static int test_bio_rdonly_mem_buf(void)
{
    int ok = 0;
    BIO *bio, *bio2 = NULL;
    BUF_MEM *bufmem;
    char data[16];

    bio = BIO_new_mem_buf("Hello World\n", 12);
    if (!TEST_ptr(bio))
        goto finish;
    if (!TEST_int_eq(BIO_read(bio, data, 5), 5))
        goto finish;
    if (!TEST_mem_eq(data, 5, "Hello", 5))
        goto finish;
    if (!TEST_int_gt(BIO_get_mem_ptr(bio, &bufmem), 0))
        goto finish;
    (void)BIO_set_close(bio, BIO_NOCLOSE);

    bio2 = BIO_new(BIO_s_mem());
    if (!TEST_ptr(bio2))
        goto finish;
    BIO_set_mem_buf(bio2, bufmem, BIO_CLOSE);
    BIO_set_flags(bio2, BIO_FLAGS_MEM_RDONLY);

    if (!TEST_int_eq(BIO_read(bio2, data, 16), 7))
        goto finish;
    if (!TEST_mem_eq(data, 7, " World\n", 7))
        goto finish;
    if (!TEST_int_gt(BIO_reset(bio2), 0))
        goto finish;
    if (!TEST_int_eq(BIO_read(bio2, data, 16), 7))
        goto finish;
    if (!TEST_mem_eq(data, 7, " World\n", 7))
        goto finish;
    ok = 1;

finish:
    BIO_free(bio);
    BIO_free(bio2);
    return ok;
}

__attribute__((used)) static int test_bio_rdwr_rdonly(void)
{
    int ok = 0;
    BIO *bio = NULL;
    char data[16];

    bio = BIO_new(BIO_s_mem());
    if (!TEST_ptr(bio))
        goto finish;
    if (!TEST_int_eq(BIO_puts(bio, "Hello World\n"), 12))
        goto finish;

    BIO_set_flags(bio, BIO_FLAGS_MEM_RDONLY);
    if (!TEST_int_eq(BIO_read(bio, data, 16), 12))
        goto finish;
    if (!TEST_mem_eq(data, 12, "Hello World\n", 12))
        goto finish;
    if (!TEST_int_gt(BIO_reset(bio), 0))
        goto finish;

    BIO_clear_flags(bio, BIO_FLAGS_MEM_RDONLY);
    if (!TEST_int_eq(BIO_puts(bio, "Hi!\n"), 4))
        goto finish;
    if (!TEST_int_eq(BIO_read(bio, data, 16), 16))
        goto finish;

    if (!TEST_mem_eq(data, 16, "Hello World\nHi!\n", 16))
        goto finish;

    ok = 1;

finish:
    BIO_free(bio);
    return ok;
}

int global_init(void)
{
    CRYPTO_set_mem_debug(1);
    CRYPTO_mem_ctrl(CRYPTO_MEM_CHECK_ON);
    return 1;
}

int setup_tests(void)
{
    ADD_TEST(test_bio_memleak);
    ADD_TEST(test_bio_get_mem);
    ADD_TEST(test_bio_new_mem_buf);
    ADD_TEST(test_bio_rdonly_mem_buf);
    ADD_TEST(test_bio_rdwr_rdonly);
    return 1;
}

