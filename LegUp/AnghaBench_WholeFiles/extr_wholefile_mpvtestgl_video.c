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
struct CMUnitTest {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  assert_float_equal (float,float) ; 
 int cmocka_run_group_tests (struct CMUnitTest const*,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 struct CMUnitTest const cmocka_unit_test (void (*) (void**)) ; 
 float gl_video_scale_ambient_lux (double,double,double,double,double) ; 

__attribute__((used)) static void test_scale_ambient_lux_limits(void **state) {
    float x;
    x = gl_video_scale_ambient_lux(16.0, 64.0, 2.40, 1.961, 16.0);
    assert_float_equal(x, 2.40f);

    x = gl_video_scale_ambient_lux(16.0, 64.0, 2.40, 1.961, 64.0);
    assert_float_equal(x, 1.961f);
}

__attribute__((used)) static void test_scale_ambient_lux_sign(void **state) {
    float x;
    x = gl_video_scale_ambient_lux(16.0, 64.0, 1.961, 2.40, 64.0);
    assert_float_equal(x, 2.40f);
}

__attribute__((used)) static void test_scale_ambient_lux_clamping(void **state) {
    float x;
    x = gl_video_scale_ambient_lux(16.0, 64.0, 2.40, 1.961, 0.0);
    assert_float_equal(x, 2.40f);
}

__attribute__((used)) static void test_scale_ambient_lux_log10_midpoint(void **state) {
    float x;
    // 32 corresponds to the the midpoint after converting lux to the log10 scale
    x = gl_video_scale_ambient_lux(16.0, 64.0, 2.40, 1.961, 32.0);
    float mid_gamma = (2.40 - 1.961) / 2 + 1.961;
    assert_float_equal(x, mid_gamma);
}

int main(void) {
    const struct CMUnitTest tests[] = {
        cmocka_unit_test(test_scale_ambient_lux_limits),
        cmocka_unit_test(test_scale_ambient_lux_sign),
        cmocka_unit_test(test_scale_ambient_lux_clamping),
        cmocka_unit_test(test_scale_ambient_lux_log10_midpoint),
    };
    return cmocka_run_group_tests(tests, NULL, NULL);
}

