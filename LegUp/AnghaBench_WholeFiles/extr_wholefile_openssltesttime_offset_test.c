#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_8__   TYPE_2__ ;
typedef  struct TYPE_7__   TYPE_1__ ;

/* Type definitions */
struct TYPE_8__ {unsigned char* data; scalar_t__ flags; int /*<<< orphan*/  type; int /*<<< orphan*/  length; } ;
struct TYPE_7__ {int /*<<< orphan*/  time_result; int /*<<< orphan*/  type; scalar_t__ data; } ;
typedef  TYPE_1__ TESTDATA ;
typedef  TYPE_2__ ASN1_TIME ;

/* Variables and functions */
 int /*<<< orphan*/  ADD_ALL_TESTS (int (*) (int),int /*<<< orphan*/ ) ; 
 int ASN1_TIME_cmp_time_t (TYPE_2__*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ASN1_TIME_diff (int*,int*,int /*<<< orphan*/ *,TYPE_2__*) ; 
 int /*<<< orphan*/  OSSL_NELEM (TYPE_1__*) ; 
 int /*<<< orphan*/  TEST_info (char*,unsigned char*,...) ; 
 int /*<<< orphan*/  TEST_int_eq (int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  TEST_true (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  strlen (scalar_t__) ; 
 TYPE_1__* tests ; 
 int /*<<< orphan*/  the_asn1_time ; 
 int /*<<< orphan*/  the_time ; 

__attribute__((used)) static int test_offset(int idx)
{
    ASN1_TIME at;
    const TESTDATA *testdata = &tests[idx];
    int ret = -2;
    int day, sec;

    at.data = (unsigned char*)testdata->data;
    at.length = strlen(testdata->data);
    at.type = testdata->type;
    at.flags = 0;

    if (!TEST_true(ASN1_TIME_diff(&day, &sec, &the_asn1_time, &at))) {
        TEST_info("ASN1_TIME_diff() failed for %s\n", at.data);
        return 0;
    }
    if (day > 0)
        ret = 1;
    else if (day < 0)
        ret = -1;
    else if (sec > 0)
        ret = 1;
    else if (sec < 0)
        ret = -1;
    else
        ret = 0;

    if (!TEST_int_eq(testdata->time_result, ret)) {
        TEST_info("ASN1_TIME_diff() test failed for %s day=%d sec=%d\n", at.data, day, sec);
        return 0;
    }

    ret = ASN1_TIME_cmp_time_t(&at, the_time);

    if (!TEST_int_eq(testdata->time_result, ret)) {
        TEST_info("ASN1_UTCTIME_cmp_time_t() test failed for %s\n", at.data);
        return 0;
    }

    return 1;
}

int setup_tests(void)
{
    ADD_ALL_TESTS(test_offset, OSSL_NELEM(tests));
    return 1;
}

