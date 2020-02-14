#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  pass ;
typedef  int /*<<< orphan*/  UI_METHOD ;
typedef  int /*<<< orphan*/  UI ;
struct TYPE_3__ {char* member_0; char* member_1; char* password; } ;
typedef  TYPE_1__ PW_CB_DATA ;

/* Variables and functions */
 int /*<<< orphan*/  ADD_TEST (int (*) ()) ; 
 int /*<<< orphan*/  OPENSSL_strlcpy (char*,char*,size_t) ; 
 int /*<<< orphan*/  TEST_info (char*) ; 
 scalar_t__ TEST_int_gt (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  TEST_ptr (int /*<<< orphan*/ *) ; 
 scalar_t__ TEST_str_eq (char*,char*) ; 
 int /*<<< orphan*/  UI_INPUT_FLAG_DEFAULT_PWD ; 
 int /*<<< orphan*/ * UI_UTIL_wrap_read_pem_callback (int (*) (char*,int,int,void*),int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  UI_add_input_string (int /*<<< orphan*/ *,char*,int /*<<< orphan*/ ,char*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  UI_add_user_data (int /*<<< orphan*/ *,char*) ; 
 int /*<<< orphan*/  UI_destroy_method (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  UI_free (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/ * UI_new_method (int /*<<< orphan*/ *) ; 
 int UI_process (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  destroy_ui_method () ; 
 int /*<<< orphan*/  password_callback (char*,int,int /*<<< orphan*/ ,TYPE_1__*) ; 
 int /*<<< orphan*/  setup_ui_method () ; 
 int strlen (char*) ; 

__attribute__((used)) static int test_pem_password_cb(char *buf, int size, int rwflag, void *userdata)
{
    OPENSSL_strlcpy(buf, (char *)userdata, (size_t)size);
    return strlen(buf);
}

__attribute__((used)) static int test_old(void)
{
    UI_METHOD *ui_method = NULL;
    UI *ui = NULL;
    char defpass[] = "password";
    char pass[16];
    int ok = 0;

    if (!TEST_ptr(ui_method =
                  UI_UTIL_wrap_read_pem_callback( test_pem_password_cb, 0))
            || !TEST_ptr(ui = UI_new_method(ui_method)))
        goto err;

    /* The wrapper passes the UI userdata as the callback userdata param */
    UI_add_user_data(ui, defpass);

    if (!UI_add_input_string(ui, "prompt", UI_INPUT_FLAG_DEFAULT_PWD,
                             pass, 0, sizeof(pass) - 1))
        goto err;

    switch (UI_process(ui)) {
    case -2:
        TEST_info("test_old: UI process interrupted or cancelled");
        /* fall through */
    case -1:
        goto err;
    default:
        break;
    }

    if (TEST_str_eq(pass, defpass))
        ok = 1;

 err:
    UI_free(ui);
    UI_destroy_method(ui_method);

    return ok;
}

__attribute__((used)) static int test_new_ui(void)
{
    PW_CB_DATA cb_data = {
        "password",
        "prompt"
    };
    char pass[16];
    int ok = 0;

    setup_ui_method();
    if (TEST_int_gt(password_callback(pass, sizeof(pass), 0, &cb_data), 0)
            && TEST_str_eq(pass, cb_data.password))
        ok = 1;
    destroy_ui_method();
    return ok;
}

int setup_tests(void)
{
    ADD_TEST(test_old);
    ADD_TEST(test_new_ui);
    return 1;
}

