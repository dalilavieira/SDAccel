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
struct mpv_node {int dummy; } ;
struct entry {char* src; int expect_fail; int /*<<< orphan*/  out_data; int /*<<< orphan*/  out_txt; } ;
struct CMUnitTest {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  MAX_DEPTH ; 
 int MP_ARRAY_SIZE (struct entry*) ; 
 int /*<<< orphan*/  assert_string_equal (int /*<<< orphan*/ ,char*) ; 
 int /*<<< orphan*/  assert_true (int) ; 
 int cmocka_run_group_tests (struct CMUnitTest const*,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 struct CMUnitTest const cmocka_unit_test (void (*) (void**)) ; 
 struct entry* entries ; 
 int equal_mpv_node (int /*<<< orphan*/ *,struct mpv_node*) ; 
 scalar_t__ json_parse (void*,struct mpv_node*,char**,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  json_skip_whitespace (char**) ; 
 scalar_t__ json_write (char**,struct mpv_node*) ; 
 int /*<<< orphan*/  print_message (char*,int,char*) ; 
 int /*<<< orphan*/  talloc_free (void*) ; 
 void* talloc_new (int /*<<< orphan*/ *) ; 
 char* talloc_strdup (void*,char*) ; 

__attribute__((used)) static void test_json(void **state)
{
    for (int n = 0; n < MP_ARRAY_SIZE(entries); n++) {
        const struct entry *e = &entries[n];
        print_message("%d: %s\n", n, e->src);
        void *tmp = talloc_new(NULL);
        char *s = talloc_strdup(tmp, e->src);
        json_skip_whitespace(&s);
        struct mpv_node res;
        bool ok = json_parse(tmp, &res, &s, MAX_DEPTH) >= 0;
        assert_true(ok != e->expect_fail);
        if (!ok)
            continue;
        char *d = talloc_strdup(tmp, "");
        assert_true(json_write(&d, &res) >= 0);
        assert_string_equal(e->out_txt, d);
        assert_true(equal_mpv_node(&e->out_data, &res));
        talloc_free(tmp);
    }
}

int main(void) {
    const struct CMUnitTest tests[] = {
        cmocka_unit_test(test_json),
    };
    return cmocka_run_group_tests(tests, NULL, NULL);
}

