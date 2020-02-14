#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_6__   TYPE_2__ ;
typedef  struct TYPE_5__   TYPE_1__ ;

/* Type definitions */
struct TYPE_5__ {char* member_0; scalar_t__ member_1; scalar_t__ code; int /*<<< orphan*/  str; } ;
typedef  TYPE_1__ error_enum ;
typedef  int /*<<< orphan*/  buf ;
struct TYPE_6__ {int /*<<< orphan*/  sname; } ;
typedef  char const BIO ;
typedef  int /*<<< orphan*/  ASN1_VALUE ;
typedef  TYPE_2__ ASN1_ITEM ;

/* Variables and functions */
 int /*<<< orphan*/  ADD_TEST (int (*) ()) ; 
#define  ASN1_BIO 132 
#define  ASN1_COMPARE 131 
#define  ASN1_DECODE 130 
#define  ASN1_ENCODE 129 
 TYPE_2__* ASN1_ITEM_get (size_t) ; 
 int /*<<< orphan*/ * ASN1_ITEM_lookup (char const*) ; 
#define  ASN1_OK 128 
 scalar_t__ ASN1_UNKNOWN ; 
 int /*<<< orphan*/ * ASN1_item_d2i (int /*<<< orphan*/ *,unsigned char const**,int,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  ASN1_item_d2i_bio (int /*<<< orphan*/ *,char const*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  ASN1_item_free (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int ASN1_item_i2d (int /*<<< orphan*/ *,unsigned char**,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  BIO_free (char const*) ; 
 char* BIO_new_file (char const*,char*) ; 
 int BIO_read (char const*,unsigned char*,int) ; 
 scalar_t__ ERR_GET_REASON (int /*<<< orphan*/ ) ; 
 scalar_t__ ERR_R_MALLOC_FAILURE ; 
 int /*<<< orphan*/  ERR_peek_error () ; 
 int /*<<< orphan*/  OPENSSL_free (unsigned char*) ; 
 size_t OSSL_NELEM (TYPE_1__*) ; 
 int /*<<< orphan*/  TEST_error (char*,char const*) ; 
 int /*<<< orphan*/  TEST_false (int) ; 
 scalar_t__ TEST_int_eq (scalar_t__,scalar_t__) ; 
 int /*<<< orphan*/  TEST_int_ge (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  TEST_note (char*,...) ; 
 int /*<<< orphan*/  TEST_ptr (char const*) ; 
 scalar_t__ TEST_ptr_null (int /*<<< orphan*/ ) ; 
 scalar_t__ expected_error ; 
 int /*<<< orphan*/ * item_type ; 
 scalar_t__ memcmp (unsigned char*,unsigned char*,int) ; 
 scalar_t__ strcmp (int /*<<< orphan*/ ,char const*) ; 
 char const* test_file ; 
 char* test_get_argument (int) ; 

__attribute__((used)) static int test_bad_asn1(void)
{
    BIO *bio = NULL;
    ASN1_VALUE *value = NULL;
    int ret = 0;
    unsigned char buf[2048];
    const unsigned char *buf_ptr = buf;
    unsigned char *der = NULL;
    int derlen;
    int len;

    bio = BIO_new_file(test_file, "r");
    if (!TEST_ptr(bio))
        return 0;

    if (expected_error == ASN1_BIO) {
        if (TEST_ptr_null(ASN1_item_d2i_bio(item_type, bio, NULL)))
            ret = 1;
        goto err;
    }

    /*
     * Unless we are testing it we don't use ASN1_item_d2i_bio because it
     * performs sanity checks on the input and can reject it before the
     * decoder is called.
     */
    len = BIO_read(bio, buf, sizeof(buf));
    if (!TEST_int_ge(len, 0))
        goto err;

    value = ASN1_item_d2i(NULL, &buf_ptr, len, item_type);
    if (value == NULL) {
        if (TEST_int_eq(expected_error, ASN1_DECODE))
            ret = 1;
        goto err;
    }

    derlen = ASN1_item_i2d(value, &der, item_type);

    if (der == NULL || derlen < 0) {
        if (TEST_int_eq(expected_error, ASN1_ENCODE))
            ret = 1;
        goto err;
    }

    if (derlen != len || memcmp(der, buf, derlen) != 0) {
        if (TEST_int_eq(expected_error, ASN1_COMPARE))
            ret = 1;
        goto err;
    }

    if (TEST_int_eq(expected_error, ASN1_OK))
        ret = 1;

 err:
    /* Don't indicate success for memory allocation errors */
    if (ret == 1
        && !TEST_false(ERR_GET_REASON(ERR_peek_error()) == ERR_R_MALLOC_FAILURE))
        ret = 0;
    BIO_free(bio);
    OPENSSL_free(der);
    ASN1_item_free(value, item_type);
    return ret;
}

int setup_tests(void)
{
    const char *test_type_name;
    const char *expected_error_string;

    size_t i;

    static error_enum expected_errors[] = {
        {"OK", ASN1_OK},
        {"BIO", ASN1_BIO},
        {"decode", ASN1_DECODE},
        {"encode", ASN1_ENCODE},
        {"compare", ASN1_COMPARE}
    };

    if (!TEST_ptr(test_type_name = test_get_argument(0))
            || !TEST_ptr(expected_error_string = test_get_argument(1))
            || !TEST_ptr(test_file = test_get_argument(2)))
        return 0;

    item_type = ASN1_ITEM_lookup(test_type_name);

    if (item_type == NULL) {
        TEST_error("Unknown type %s", test_type_name);
        TEST_note("Supported types:");
        for (i = 0;; i++) {
            const ASN1_ITEM *it = ASN1_ITEM_get(i);

            if (it == NULL)
                break;
            TEST_note("\t%s", it->sname);
        }
        return 0;
    }

    for (i = 0; i < OSSL_NELEM(expected_errors); i++) {
        if (strcmp(expected_errors[i].str, expected_error_string) == 0) {
            expected_error = expected_errors[i].code;
            break;
        }
    }

    if (expected_error == ASN1_UNKNOWN) {
        TEST_error("Unknown expected error %s\n", expected_error_string);
        return 0;
    }

    ADD_TEST(test_bad_asn1);
    return 1;
}

