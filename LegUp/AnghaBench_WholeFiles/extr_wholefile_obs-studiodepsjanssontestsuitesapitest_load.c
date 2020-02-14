#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_6__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  json_t ;
struct TYPE_6__ {int line; int position; int /*<<< orphan*/  text; int /*<<< orphan*/  source; } ;
typedef  TYPE_1__ json_error_t ;

/* Variables and functions */
 size_t JSON_ALLOW_NUL ; 
 size_t JSON_DECODE_ANY ; 
 size_t JSON_DECODE_INT_AS_REAL ; 
 size_t JSON_DISABLE_EOF_CHECK ; 
 size_t JSON_REJECT_DUPLICATES ; 
 int /*<<< orphan*/  check_error (char*,char*,int,int,int) ; 
 int /*<<< orphan*/  fail (char*) ; 
 int /*<<< orphan*/  json_decref (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  json_is_integer (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  json_is_null (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  json_is_real (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  json_is_string (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  json_is_true (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/ * json_load_file (char*,int /*<<< orphan*/ ,TYPE_1__*) ; 
 int /*<<< orphan*/ * json_loadb (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ ,TYPE_1__*) ; 
 int /*<<< orphan*/ * json_loadf (int /*<<< orphan*/ *,int /*<<< orphan*/ ,TYPE_1__*) ; 
 int /*<<< orphan*/ * json_loads (char const*,size_t,TYPE_1__*) ; 
 double json_real_value (int /*<<< orphan*/ *) ; 
 size_t json_string_length (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  json_string_value (int /*<<< orphan*/ *) ; 
 scalar_t__ memcmp (int /*<<< orphan*/ ,char const*,size_t) ; 
 int /*<<< orphan*/  memset (char*,int /*<<< orphan*/ ,int) ; 
static  void run_tests () ; 
 char* strchr (int /*<<< orphan*/ ,char) ; 
 scalar_t__ strcmp (int /*<<< orphan*/ ,char*) ; 
 scalar_t__ strncmp (int /*<<< orphan*/ ,char*,int) ; 

int main() {
#ifdef HAVE_SETLOCALE
    setlocale(LC_ALL, "");
#endif
    run_tests();
    return 0;
}

__attribute__((used)) static void file_not_found()
{
    json_t *json;
    json_error_t error;
    char *pos;

    json = json_load_file("/path/to/nonexistent/file.json", 0, &error);
    if(json)
        fail("json_load_file returned non-NULL for a nonexistent file");
    if(error.line != -1)
        fail("json_load_file returned an invalid line number");

    /* The error message is locale specific, only check the beginning
       of the error message. */

    pos = strchr(error.text, ':');
    if(!pos)
        fail("json_load_file returne an invalid error message");

    *pos = '\0';

    if(strcmp(error.text, "unable to open /path/to/nonexistent/file.json") != 0)
        fail("json_load_file returned an invalid error message");
}

__attribute__((used)) static void very_long_file_name() {
    json_t *json;
    json_error_t error;

    json = json_load_file("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa", 0, &error);
    if(json)
        fail("json_load_file returned non-NULL for a nonexistent file");
    if(error.line != -1)
        fail("json_load_file returned an invalid line number");

    if (strncmp(error.source, "...aaa", 6) != 0)
        fail("error source was set incorrectly");
}

__attribute__((used)) static void reject_duplicates()
{
    json_error_t error;

    if(json_loads("{\"foo\": 1, \"foo\": 2}", JSON_REJECT_DUPLICATES, &error))
        fail("json_loads did not detect a duplicate key");
    check_error("duplicate object key near '\"foo\"'", "<string>", 1, 16, 16);
}

__attribute__((used)) static void disable_eof_check()
{
    json_error_t error;
    json_t *json;

    const char *text = "{\"foo\": 1} garbage";

    if(json_loads(text, 0, &error))
        fail("json_loads did not detect garbage after JSON text");
    check_error("end of file expected near 'garbage'", "<string>", 1, 18, 18);

    json = json_loads(text, JSON_DISABLE_EOF_CHECK, &error);
    if(!json)
        fail("json_loads failed with JSON_DISABLE_EOF_CHECK");

    json_decref(json);
}

__attribute__((used)) static void decode_any()
{
    json_t *json;
    json_error_t error;

    json = json_loads("\"foo\"", JSON_DECODE_ANY, &error);
    if (!json || !json_is_string(json))
        fail("json_load decoded any failed - string");
    json_decref(json);

    json = json_loads("42", JSON_DECODE_ANY, &error);
    if (!json || !json_is_integer(json))
        fail("json_load decoded any failed - integer");
    json_decref(json);

    json = json_loads("true", JSON_DECODE_ANY, &error);
    if (!json || !json_is_true(json))
        fail("json_load decoded any failed - boolean");
    json_decref(json);

    json = json_loads("null", JSON_DECODE_ANY, &error);
    if (!json || !json_is_null(json))
        fail("json_load decoded any failed - null");
    json_decref(json);
}

__attribute__((used)) static void decode_int_as_real()
{
    json_t *json;
    json_error_t error;

#if JSON_INTEGER_IS_LONG_LONG
    const char *imprecise;
    json_int_t expected;
#endif

    char big[311];

    json = json_loads("42", JSON_DECODE_INT_AS_REAL | JSON_DECODE_ANY, &error);
    if (!json || !json_is_real(json) || json_real_value(json) != 42.0)
        fail("json_load decode int as real failed - int");
    json_decref(json);

#if JSON_INTEGER_IS_LONG_LONG
    /* This number cannot be represented exactly by a double */
    imprecise = "9007199254740993";
    expected = 9007199254740992ll;

    json = json_loads(imprecise, JSON_DECODE_INT_AS_REAL | JSON_DECODE_ANY,
                      &error);
    if (!json || !json_is_real(json) || expected != (json_int_t)json_real_value(json))
        fail("json_load decode int as real failed - expected imprecision");
    json_decref(json);
#endif

    /* 1E309 overflows. Here we create 1E309 as a decimal number, i.e.
       1000...(309 zeroes)...0. */
    big[0] = '1';
    memset(big + 1, '0', 309);
    big[310] = '\0';

    json = json_loads(big, JSON_DECODE_INT_AS_REAL | JSON_DECODE_ANY, &error);
    if (json || strcmp(error.text, "real number overflow") != 0)
        fail("json_load decode int as real failed - expected overflow");
    json_decref(json);

}

__attribute__((used)) static void allow_nul()
{
    const char *text = "\"nul byte \\u0000 in string\"";
    const char *expected = "nul byte \0 in string";
    size_t len = 20;
    json_t *json;

    json = json_loads(text, JSON_ALLOW_NUL | JSON_DECODE_ANY, NULL);
    if(!json || !json_is_string(json))
        fail("unable to decode embedded NUL byte");

    if(json_string_length(json) != len)
        fail("decoder returned wrong string length");

    if(memcmp(json_string_value(json), expected, len + 1))
        fail("decoder returned wrong string content");

    json_decref(json);
}

__attribute__((used)) static void load_wrong_args()
{
    json_t *json;
    json_error_t error;

    json = json_loads(NULL, 0, &error);
    if (json)
        fail("json_loads should return NULL if the first argument is NULL");

    json = json_loadb(NULL, 0, 0, &error);
    if (json)
        fail("json_loadb should return NULL if the first argument is NULL");

    json = json_loadf(NULL, 0, &error);
    if (json)
        fail("json_loadf should return NULL if the first argument is NULL");

    json = json_load_file(NULL, 0, &error);
    if (json)
        fail("json_loadf should return NULL if the first argument is NULL");
}

__attribute__((used)) static void position()
{
    json_t *json;
    size_t flags = JSON_DISABLE_EOF_CHECK;
    json_error_t error;

    json = json_loads("{\"foo\": \"bar\"}", 0, &error);
    if(error.position != 14)
        fail("json_loads returned a wrong position");
    json_decref(json);

    json = json_loads("{\"foo\": \"bar\"} baz quux", flags, &error);
    if(error.position != 14)
        fail("json_loads returned a wrong position");
    json_decref(json);
}

__attribute__((used)) static void run_tests()
{
    file_not_found();
    very_long_file_name();
    reject_duplicates();
    disable_eof_check();
    decode_any();
    decode_int_as_real();
    allow_nul();
    load_wrong_args();
    position();
}

