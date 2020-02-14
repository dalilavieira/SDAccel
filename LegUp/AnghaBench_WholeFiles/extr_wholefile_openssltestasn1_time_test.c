#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_16__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  uint32_t ;
typedef  scalar_t__ time_t ;
struct tm {int dummy; } ;
struct testdata {scalar_t__ type; scalar_t__ check_result; int cmp_result; scalar_t__ expected_type; int convert_result; scalar_t__ result; int /*<<< orphan*/  t2; int /*<<< orphan*/  t1; scalar_t__ t; scalar_t__ data; } ;
struct compare_testdata {scalar_t__ type; scalar_t__ check_result; int cmp_result; scalar_t__ expected_type; int convert_result; scalar_t__ result; int /*<<< orphan*/  t2; int /*<<< orphan*/  t1; scalar_t__ t; scalar_t__ data; } ;
struct TYPE_16__ {unsigned char* data; scalar_t__ type; int /*<<< orphan*/  length; scalar_t__ flags; } ;
typedef  TYPE_1__ ASN1_TIME ;

/* Variables and functions */
 int /*<<< orphan*/  ADD_ALL_TESTS (int (*) (int),int /*<<< orphan*/ ) ; 
 int ASN1_TIME_check (TYPE_1__*) ; 
 int ASN1_TIME_cmp_time_t (TYPE_1__*,scalar_t__) ; 
 int ASN1_TIME_compare (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int ASN1_TIME_diff (int*,int*,TYPE_1__*,TYPE_1__*) ; 
 int /*<<< orphan*/  ASN1_TIME_free (TYPE_1__*) ; 
 TYPE_1__* ASN1_TIME_new () ; 
 int ASN1_TIME_normalize (TYPE_1__*) ; 
 TYPE_1__* ASN1_TIME_set (int /*<<< orphan*/ *,scalar_t__) ; 
 int ASN1_TIME_set_string (TYPE_1__*,scalar_t__) ; 
 TYPE_1__* ASN1_TIME_to_generalizedtime (TYPE_1__*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  OSSL_NELEM (struct testdata*) ; 
 int /*<<< orphan*/  TEST_error (char*,unsigned char*) ; 
 int /*<<< orphan*/  TEST_info (char*,...) ; 
 int TEST_int_eq (int,scalar_t__) ; 
 int /*<<< orphan*/  TEST_ptr (TYPE_1__*) ; 
 int /*<<< orphan*/  TEST_ptr_null (TYPE_1__*) ; 
 scalar_t__ TEST_true (int) ; 
 scalar_t__ V_ASN1_UTCTIME ; 
 TYPE_1__ gtime ; 
 scalar_t__ gtime_t ; 
 struct tm* localtime (scalar_t__*) ; 
 int /*<<< orphan*/  strlen (char*) ; 
 struct testdata* tbl_compare_testdata ; 
 struct testdata* tbl_testdata_neg ; 
 struct testdata* tbl_testdata_neg_64bit ; 
 struct testdata* tbl_testdata_pos ; 
 struct testdata* tbl_testdata_pos_64bit ; 

__attribute__((used)) static int test_table(struct testdata *tbl, int idx)
{
    int error = 0;
    ASN1_TIME atime;
    ASN1_TIME *ptime;
    struct testdata *td = &tbl[idx];
    int day, sec;

    atime.data = (unsigned char*)td->data;
    atime.length = strlen((char*)atime.data);
    atime.type = td->type;
    atime.flags = 0;

    if (!TEST_int_eq(ASN1_TIME_check(&atime), td->check_result)) {
        TEST_info("ASN1_TIME_check(%s) unexpected result", atime.data);
        error = 1;
    }
    if (td->check_result == 0)
        return 1;

    if (!TEST_int_eq(ASN1_TIME_cmp_time_t(&atime, td->t), 0)) {
        TEST_info("ASN1_TIME_cmp_time_t(%s vs %ld) compare failed", atime.data, (long)td->t);
        error = 1;
    }

    if (!TEST_true(ASN1_TIME_diff(&day, &sec, &atime, &atime))) {
        TEST_info("ASN1_TIME_diff(%s) to self failed", atime.data);
        error = 1;
    }
    if (!TEST_int_eq(day, 0) || !TEST_int_eq(sec, 0)) {
        TEST_info("ASN1_TIME_diff(%s) to self not equal", atime.data);
        error = 1;
    }

    if (!TEST_true(ASN1_TIME_diff(&day, &sec, &gtime, &atime))) {
        TEST_info("ASN1_TIME_diff(%s) to baseline failed", atime.data);
        error = 1;
    } else if (!((td->cmp_result == 0 && TEST_true((day == 0 && sec == 0))) ||
                 (td->cmp_result == -1 && TEST_true((day < 0 || sec < 0))) ||
                 (td->cmp_result == 1 && TEST_true((day > 0 || sec > 0))))) {
        TEST_info("ASN1_TIME_diff(%s) to baseline bad comparison", atime.data);
        error = 1;
    }

    if (!TEST_int_eq(ASN1_TIME_cmp_time_t(&atime, gtime_t), td->cmp_result)) {
        TEST_info("ASN1_TIME_cmp_time_t(%s) to baseline bad comparison", atime.data);
        error = 1;
    }

    ptime = ASN1_TIME_set(NULL, td->t);
    if (!TEST_ptr(ptime)) {
        TEST_info("ASN1_TIME_set(%ld) failed", (long)td->t);
        error = 1;
    } else {
        int local_error = 0;
        if (!TEST_int_eq(ASN1_TIME_cmp_time_t(ptime, td->t), 0)) {
            TEST_info("ASN1_TIME_set(%ld) compare failed (%s->%s)",
                    (long)td->t, td->data, ptime->data);
            local_error = error = 1;
        }
        if (!TEST_int_eq(ptime->type, td->expected_type)) {
            TEST_info("ASN1_TIME_set(%ld) unexpected type", (long)td->t);
            local_error = error = 1;
        }
        if (local_error)
            TEST_info("ASN1_TIME_set() = %*s", ptime->length, ptime->data);
        ASN1_TIME_free(ptime);
    }

    ptime = ASN1_TIME_new();
    if (!TEST_ptr(ptime)) {
        TEST_info("ASN1_TIME_new() failed");
        error = 1;
    } else {
        int local_error = 0;
        if (!TEST_int_eq(ASN1_TIME_set_string(ptime, td->data), td->check_result)) {
            TEST_info("ASN1_TIME_set_string_gmt(%s) failed", td->data);
            local_error = error = 1;
        }
        if (!TEST_int_eq(ASN1_TIME_normalize(ptime), td->check_result)) {
            TEST_info("ASN1_TIME_normalize(%s) failed", td->data);
            local_error = error = 1;
        }
        if (!TEST_int_eq(ptime->type, td->expected_type)) {
            TEST_info("ASN1_TIME_set_string_gmt(%s) unexpected type", td->data);
            local_error = error = 1;
        }
        day = sec = 0;
        if (!TEST_true(ASN1_TIME_diff(&day, &sec, ptime, &atime)) || !TEST_int_eq(day, 0) || !TEST_int_eq(sec, 0)) {
            TEST_info("ASN1_TIME_diff(day=%d, sec=%d, %s) after ASN1_TIME_set_string_gmt() failed", day, sec, td->data);
            local_error = error = 1;
        }
        if (!TEST_int_eq(ASN1_TIME_cmp_time_t(ptime, gtime_t), td->cmp_result)) {
            TEST_info("ASN1_TIME_cmp_time_t(%s) after ASN1_TIME_set_string_gnt() to baseline bad comparison", td->data);
            local_error = error = 1;
        }
        if (local_error)
            TEST_info("ASN1_TIME_set_string_gmt() = %*s", ptime->length, ptime->data);
        ASN1_TIME_free(ptime);
    }

    ptime = ASN1_TIME_new();
    if (!TEST_ptr(ptime)) {
        TEST_info("ASN1_TIME_new() failed");
        error = 1;
    } else {
        int local_error = 0;
        if (!TEST_int_eq(ASN1_TIME_set_string(ptime, td->data), td->check_result)) {
            TEST_info("ASN1_TIME_set_string(%s) failed", td->data);
            local_error = error = 1;
        }
        day = sec = 0;
        if (!TEST_true(ASN1_TIME_diff(&day, &sec, ptime, &atime)) || !TEST_int_eq(day, 0) || !TEST_int_eq(sec, 0)) {
            TEST_info("ASN1_TIME_diff(day=%d, sec=%d, %s) after ASN1_TIME_set_string() failed", day, sec, td->data);
            local_error = error = 1;
        }
        if (!TEST_int_eq(ASN1_TIME_cmp_time_t(ptime, gtime_t), td->cmp_result)) {
            TEST_info("ASN1_TIME_cmp_time_t(%s) after ASN1_TIME_set_string() to baseline bad comparison", td->data);
            local_error = error = 1;
        }
        if (local_error)
            TEST_info("ASN1_TIME_set_string() = %*s", ptime->length, ptime->data);
        ASN1_TIME_free(ptime);
    }

    if (td->type == V_ASN1_UTCTIME) {
        ptime = ASN1_TIME_to_generalizedtime(&atime, NULL);
        if (td->convert_result == 1 && !TEST_ptr(ptime)) {
            TEST_info("ASN1_TIME_to_generalizedtime(%s) failed", atime.data);
            error = 1;
        } else if (td->convert_result == 0 && !TEST_ptr_null(ptime)) {
            TEST_info("ASN1_TIME_to_generalizedtime(%s) should have failed", atime.data);
            error = 1;
        }
        if (ptime != NULL && !TEST_int_eq(ASN1_TIME_cmp_time_t(ptime, td->t), 0)) {
            TEST_info("ASN1_TIME_to_generalizedtime(%s->%s) bad result", atime.data, ptime->data);
            error = 1;
        }
        ASN1_TIME_free(ptime);
    }
    /* else cannot simply convert GENERALIZEDTIME to UTCTIME */

    if (error)
        TEST_error("atime=%s", atime.data);

    return !error;
}

__attribute__((used)) static int test_table_pos(int idx)
{
    return test_table(tbl_testdata_pos, idx);
}

__attribute__((used)) static int test_table_neg(int idx)
{
    return test_table(tbl_testdata_neg, idx);
}

__attribute__((used)) static int test_table_pos_64bit(int idx)
{
    return test_table(tbl_testdata_pos_64bit, idx);
}

__attribute__((used)) static int test_table_neg_64bit(int idx)
{
    return test_table(tbl_testdata_neg_64bit, idx);
}

__attribute__((used)) static int test_table_compare(int idx)
{
    struct compare_testdata *td = &tbl_compare_testdata[idx];

    return TEST_int_eq(ASN1_TIME_compare(&td->t1, &td->t2), td->result);
}

int setup_tests(void)
{
    /*
     * On platforms where |time_t| is an unsigned integer, t will be a
     * positive number.
     *
     * We check if we're on a platform with a signed |time_t| with '!(t > 0)'
     * because some compilers are picky if you do 't < 0', or even 't <= 0'
     * if |t| is unsigned.
     */
    time_t t = -1;
    /*
     * On some platforms, |time_t| is signed, but a negative value is an
     * error, and using it with gmtime() or localtime() generates a NULL.
     * If that is the case, we can't perform tests on negative values.
     */
    struct tm *ptm = localtime(&t);

    ADD_ALL_TESTS(test_table_pos, OSSL_NELEM(tbl_testdata_pos));
    if (!(t > 0) && ptm != NULL) {
        TEST_info("Adding negative-sign time_t tests");
        ADD_ALL_TESTS(test_table_neg, OSSL_NELEM(tbl_testdata_neg));
    }
    if (sizeof(time_t) > sizeof(uint32_t)) {
        TEST_info("Adding 64-bit time_t tests");
        ADD_ALL_TESTS(test_table_pos_64bit, OSSL_NELEM(tbl_testdata_pos_64bit));
#ifndef __hpux
        if (!(t > 0) && ptm != NULL) {
            TEST_info("Adding negative-sign 64-bit time_t tests");
            ADD_ALL_TESTS(test_table_neg_64bit, OSSL_NELEM(tbl_testdata_neg_64bit));
        }
#endif
    }
    ADD_ALL_TESTS(test_table_compare, OSSL_NELEM(tbl_compare_testdata));
    return 1;
}

