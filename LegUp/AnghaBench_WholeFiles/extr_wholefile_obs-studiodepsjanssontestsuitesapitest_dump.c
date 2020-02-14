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
typedef  int /*<<< orphan*/  json_t ;
typedef  int /*<<< orphan*/  FILE ;

/* Variables and functions */
 int /*<<< orphan*/  JSON_ENCODE_ANY ; 
 int /*<<< orphan*/  JSON_ESCAPE_SLASH ; 
 int /*<<< orphan*/  fail (char*) ; 
 int /*<<< orphan*/  free (char*) ; 
 int /*<<< orphan*/ * json_array () ; 
 int /*<<< orphan*/  json_array_append (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  json_array_append_new (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/ * json_array_get (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  json_array_remove (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  json_decref (int /*<<< orphan*/ *) ; 
 int json_dump_callback (int /*<<< orphan*/ *,int (*) (char const*,size_t,void*),int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int json_dump_file (int /*<<< orphan*/ *,char*,int /*<<< orphan*/ ) ; 
 scalar_t__ json_dumpf (int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 char* json_dumps (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/ * json_integer (int) ; 
 int /*<<< orphan*/ * json_object () ; 
 int /*<<< orphan*/  json_object_del (int /*<<< orphan*/ *,char*) ; 
 int /*<<< orphan*/ * json_object_get (int /*<<< orphan*/ *,char*) ; 
 int /*<<< orphan*/  json_object_set (int /*<<< orphan*/ *,char*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  json_object_set_new (int /*<<< orphan*/ *,char*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/ * json_string (char*) ; 
 int /*<<< orphan*/ * json_stringn (char*,int) ; 
 scalar_t__ memcmp (char*,char*,int) ; 
 int /*<<< orphan*/  remove (char*) ; 
static  void run_tests () ; 
 int /*<<< orphan*/ * stderr ; 
 scalar_t__ strcmp (char*,char*) ; 

int main() {
#ifdef HAVE_SETLOCALE
    setlocale(LC_ALL, "");
#endif
    run_tests();
    return 0;
}

__attribute__((used)) static int encode_null_callback(const char *buffer, size_t size, void *data)
{
    (void)buffer;
    (void)size;
    (void)data;
    return 0;
}

__attribute__((used)) static void encode_null()
{
    if(json_dumps(NULL, JSON_ENCODE_ANY) != NULL)
        fail("json_dumps didn't fail for NULL");

    if(json_dumpf(NULL, stderr, JSON_ENCODE_ANY) != -1)
        fail("json_dumpf didn't fail for NULL");

    /* Don't test json_dump_file to avoid creating a file */

    if(json_dump_callback(NULL, encode_null_callback, NULL, JSON_ENCODE_ANY) != -1)
        fail("json_dump_callback didn't fail for NULL");
}

__attribute__((used)) static void encode_twice()
{
    /* Encode an empty object/array, add an item, encode again */

    json_t *json;
    char *result;

    json = json_object();
    result = json_dumps(json, 0);
    if(!result || strcmp(result, "{}"))
      fail("json_dumps failed");
    free(result);

    json_object_set_new(json, "foo", json_integer(5));
    result = json_dumps(json, 0);
    if(!result || strcmp(result, "{\"foo\": 5}"))
      fail("json_dumps failed");
    free(result);

    json_decref(json);

    json = json_array();
    result = json_dumps(json, 0);
    if(!result || strcmp(result, "[]"))
      fail("json_dumps failed");
    free(result);

    json_array_append_new(json, json_integer(5));
    result = json_dumps(json, 0);
    if(!result || strcmp(result, "[5]"))
      fail("json_dumps failed");
    free(result);

    json_decref(json);
}

__attribute__((used)) static void circular_references()
{
    /* Construct a JSON object/array with a circular reference:

       object: {"a": {"b": {"c": <circular reference to $.a>}}}
       array: [[[<circular reference to the $[0] array>]]]

       Encode it, remove the circular reference and encode again.
    */

    json_t *json;
    char *result;

    json = json_object();
    json_object_set_new(json, "a", json_object());
    json_object_set_new(json_object_get(json, "a"), "b", json_object());
    json_object_set(json_object_get(json_object_get(json, "a"), "b"), "c",
                    json_object_get(json, "a"));

    if(json_dumps(json, 0))
        fail("json_dumps encoded a circular reference!");

    json_object_del(json_object_get(json_object_get(json, "a"), "b"), "c");

    result = json_dumps(json, 0);
    if(!result || strcmp(result, "{\"a\": {\"b\": {}}}"))
        fail("json_dumps failed!");
    free(result);

    json_decref(json);

    json = json_array();
    json_array_append_new(json, json_array());
    json_array_append_new(json_array_get(json, 0), json_array());
    json_array_append(json_array_get(json_array_get(json, 0), 0),
                      json_array_get(json, 0));

    if(json_dumps(json, 0))
        fail("json_dumps encoded a circular reference!");

    json_array_remove(json_array_get(json_array_get(json, 0), 0), 0);

    result = json_dumps(json, 0);
    if(!result || strcmp(result, "[[[]]]"))
        fail("json_dumps failed!");
    free(result);

    json_decref(json);
}

__attribute__((used)) static void encode_other_than_array_or_object()
{
    /* Encoding anything other than array or object should only
     * succeed if the JSON_ENCODE_ANY flag is used */

    json_t *json;
    FILE *fp = NULL;
    char *result;

    json = json_string("foo");
    if(json_dumps(json, 0) != NULL)
        fail("json_dumps encoded a string!");
    if(json_dumpf(json, fp, 0) == 0)
        fail("json_dumpf encoded a string!");

    result = json_dumps(json, JSON_ENCODE_ANY);
    if(!result || strcmp(result, "\"foo\"") != 0)
        fail("json_dumps failed to encode a string with JSON_ENCODE_ANY");

    free(result);
    json_decref(json);

    json = json_integer(42);
    if(json_dumps(json, 0) != NULL)
        fail("json_dumps encoded an integer!");
    if(json_dumpf(json, fp, 0) == 0)
        fail("json_dumpf encoded an integer!");

    result = json_dumps(json, JSON_ENCODE_ANY);
    if(!result || strcmp(result, "42") != 0)
        fail("json_dumps failed to encode an integer with JSON_ENCODE_ANY");

    free(result);
    json_decref(json);


}

__attribute__((used)) static void escape_slashes()
{
    /* Test dump escaping slashes */

    json_t *json;
    char *result;

    json = json_object();
    json_object_set_new(json, "url", json_string("https://github.com/akheron/jansson"));

    result = json_dumps(json, 0);
    if(!result || strcmp(result, "{\"url\": \"https://github.com/akheron/jansson\"}"))
        fail("json_dumps failed to not escape slashes");

    free(result);

    result = json_dumps(json, JSON_ESCAPE_SLASH);
    if(!result || strcmp(result, "{\"url\": \"https:\\/\\/github.com\\/akheron\\/jansson\"}"))
        fail("json_dumps failed to escape slashes");

    free(result);
    json_decref(json);
}

__attribute__((used)) static void encode_nul_byte()
{
    json_t *json;
    char *result;

    json = json_stringn("nul byte \0 in string", 20);
    result = json_dumps(json, JSON_ENCODE_ANY);
    if(!result || memcmp(result, "\"nul byte \\u0000 in string\"", 27))
        fail("json_dumps failed to dump an embedded NUL byte");

    free(result);
    json_decref(json);
}

__attribute__((used)) static void dump_file()
{
    json_t *json;
    int result;

    result = json_dump_file(NULL, "", 0);
    if (result != -1)
        fail("json_dump_file succeeded with invalid args");

    json = json_object();
    result = json_dump_file(json, "json_dump_file.json", 0);
    if (result != 0)
        fail("json_dump_file failed");

    json_decref(json);
    remove("json_dump_file.json");
}

__attribute__((used)) static void run_tests()
{
    encode_null();
    encode_twice();
    circular_references();
    encode_other_than_array_or_object();
    escape_slashes();
    encode_nul_byte();
    dump_file();
}

