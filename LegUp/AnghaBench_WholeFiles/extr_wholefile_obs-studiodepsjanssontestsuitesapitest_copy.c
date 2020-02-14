#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_23__   TYPE_1__ ;

/* Type definitions */
struct TYPE_23__ {int refcount; } ;
typedef  TYPE_1__ json_t ;

/* Variables and functions */
 int /*<<< orphan*/  fail (char*) ; 
 scalar_t__ json_array_get (TYPE_1__*,size_t) ; 
 size_t json_array_size (TYPE_1__*) ; 
 TYPE_1__* json_copy (TYPE_1__*) ; 
 int /*<<< orphan*/  json_decref (TYPE_1__*) ; 
 TYPE_1__* json_deep_copy (TYPE_1__*) ; 
 int /*<<< orphan*/  json_equal (TYPE_1__*,TYPE_1__*) ; 
 TYPE_1__* json_false () ; 
 TYPE_1__* json_integer (int) ; 
 TYPE_1__* json_loads (char const*,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 TYPE_1__* json_null () ; 
 TYPE_1__* json_object_get (TYPE_1__*,char const*) ; 
 void* json_object_iter (TYPE_1__*) ; 
 char* json_object_iter_key (void*) ; 
 void* json_object_iter_next (TYPE_1__*,void*) ; 
 TYPE_1__* json_object_iter_value (void*) ; 
 TYPE_1__* json_real (int) ; 
 TYPE_1__* json_string (char*) ; 
 TYPE_1__* json_true () ; 
static  void run_tests () ; 
 scalar_t__ strcmp (char const*,char const*) ; 

int main() {
#ifdef HAVE_SETLOCALE
    setlocale(LC_ALL, "");
#endif
    run_tests();
    return 0;
}

__attribute__((used)) static void test_copy_simple(void)
{
    json_t *value, *copy;

    if(json_copy(NULL))
        fail("copying NULL doesn't return NULL");

    /* true */
    value = json_true();
    copy = json_copy(value);
    if(value != copy)
        fail("copying true failed");
    json_decref(value);
    json_decref(copy);

    /* false */
    value = json_false();
    copy = json_copy(value);
    if(value != copy)
        fail("copying false failed");
    json_decref(value);
    json_decref(copy);

    /* null */
    value = json_null();
    copy = json_copy(value);
    if(value != copy)
        fail("copying null failed");
    json_decref(value);
    json_decref(copy);

    /* string */
    value = json_string("foo");
    if(!value)
        fail("unable to create a string");
    copy = json_copy(value);
    if(!copy)
        fail("unable to copy a string");
    if(copy == value)
        fail("copying a string doesn't copy");
    if(!json_equal(copy, value))
        fail("copying a string produces an inequal copy");
    if(value->refcount != 1 || copy->refcount != 1)
        fail("invalid refcounts");
    json_decref(value);
    json_decref(copy);

    /* integer */
    value = json_integer(543);
    if(!value)
        fail("unable to create an integer");
    copy = json_copy(value);
    if(!copy)
        fail("unable to copy an integer");
    if(copy == value)
        fail("copying an integer doesn't copy");
    if(!json_equal(copy, value))
        fail("copying an integer produces an inequal copy");
    if(value->refcount != 1 || copy->refcount != 1)
        fail("invalid refcounts");
    json_decref(value);
    json_decref(copy);

    /* real */
    value = json_real(123e9);
    if(!value)
        fail("unable to create a real");
    copy = json_copy(value);
    if(!copy)
        fail("unable to copy a real");
    if(copy == value)
        fail("copying a real doesn't copy");
    if(!json_equal(copy, value))
        fail("copying a real produces an inequal copy");
    if(value->refcount != 1 || copy->refcount != 1)
        fail("invalid refcounts");
    json_decref(value);
    json_decref(copy);
}

__attribute__((used)) static void test_deep_copy_simple(void)
{
    json_t *value, *copy;

    if(json_deep_copy(NULL))
        fail("deep copying NULL doesn't return NULL");

    /* true */
    value = json_true();
    copy = json_deep_copy(value);
    if(value != copy)
        fail("deep copying true failed");
    json_decref(value);
    json_decref(copy);

    /* false */
    value = json_false();
    copy = json_deep_copy(value);
    if(value != copy)
        fail("deep copying false failed");
    json_decref(value);
    json_decref(copy);

    /* null */
    value = json_null();
    copy = json_deep_copy(value);
    if(value != copy)
        fail("deep copying null failed");
    json_decref(value);
    json_decref(copy);

    /* string */
    value = json_string("foo");
    if(!value)
        fail("unable to create a string");
    copy = json_deep_copy(value);
    if(!copy)
        fail("unable to deep copy a string");
    if(copy == value)
        fail("deep copying a string doesn't copy");
    if(!json_equal(copy, value))
        fail("deep copying a string produces an inequal copy");
    if(value->refcount != 1 || copy->refcount != 1)
        fail("invalid refcounts");
    json_decref(value);
    json_decref(copy);

    /* integer */
    value = json_integer(543);
    if(!value)
        fail("unable to create an integer");
    copy = json_deep_copy(value);
    if(!copy)
        fail("unable to deep copy an integer");
    if(copy == value)
        fail("deep copying an integer doesn't copy");
    if(!json_equal(copy, value))
        fail("deep copying an integer produces an inequal copy");
    if(value->refcount != 1 || copy->refcount != 1)
        fail("invalid refcounts");
    json_decref(value);
    json_decref(copy);

    /* real */
    value = json_real(123e9);
    if(!value)
        fail("unable to create a real");
    copy = json_deep_copy(value);
    if(!copy)
        fail("unable to deep copy a real");
    if(copy == value)
        fail("deep copying a real doesn't copy");
    if(!json_equal(copy, value))
        fail("deep copying a real produces an inequal copy");
    if(value->refcount != 1 || copy->refcount != 1)
        fail("invalid refcounts");
    json_decref(value);
    json_decref(copy);
}

__attribute__((used)) static void test_copy_array(void)
{
    const char *json_array_text = "[1, \"foo\", 3.141592, {\"foo\": \"bar\"}]";

    json_t *array, *copy;
    size_t i;

    array = json_loads(json_array_text, 0, NULL);
    if(!array)
        fail("unable to parse an array");

    copy = json_copy(array);
    if(!copy)
        fail("unable to copy an array");
    if(copy == array)
        fail("copying an array doesn't copy");
    if(!json_equal(copy, array))
        fail("copying an array produces an inequal copy");

    for(i = 0; i < json_array_size(copy); i++)
    {
        if(json_array_get(array, i) != json_array_get(copy, i))
            fail("copying an array modifies its elements");
    }

    json_decref(array);
    json_decref(copy);
}

__attribute__((used)) static void test_deep_copy_array(void)
{
    const char *json_array_text = "[1, \"foo\", 3.141592, {\"foo\": \"bar\"}]";

    json_t *array, *copy;
    size_t i;

    array = json_loads(json_array_text, 0, NULL);
    if(!array)
        fail("unable to parse an array");

    copy = json_deep_copy(array);
    if(!copy)
        fail("unable to deep copy an array");
    if(copy == array)
        fail("deep copying an array doesn't copy");
    if(!json_equal(copy, array))
        fail("deep copying an array produces an inequal copy");

    for(i = 0; i < json_array_size(copy); i++)
    {
        if(json_array_get(array, i) == json_array_get(copy, i))
            fail("deep copying an array doesn't copy its elements");
    }

    json_decref(array);
    json_decref(copy);
}

__attribute__((used)) static void test_copy_object(void)
{
    const char *json_object_text =
        "{\"foo\": \"bar\", \"a\": 1, \"b\": 3.141592, \"c\": [1,2,3,4]}";

    const char *keys[] = {"foo", "a", "b", "c"};
    int i;

    json_t *object, *copy;
    void *iter;

    object = json_loads(json_object_text, 0, NULL);
    if(!object)
        fail("unable to parse an object");

    copy = json_copy(object);
    if(!copy)
        fail("unable to copy an object");
    if(copy == object)
        fail("copying an object doesn't copy");
    if(!json_equal(copy, object))
        fail("copying an object produces an inequal copy");

    i = 0;
    iter = json_object_iter(object);
    while(iter)
    {
        const char *key;
        json_t *value1, *value2;

        key = json_object_iter_key(iter);
        value1 = json_object_iter_value(iter);
        value2 = json_object_get(copy, key);

        if(value1 != value2)
            fail("copying an object modifies its items");

        if (strcmp(key, keys[i]) != 0)
            fail("copying an object doesn't preserve key order");

        iter = json_object_iter_next(object, iter);
        i++;
    }

    json_decref(object);
    json_decref(copy);
}

__attribute__((used)) static void test_deep_copy_object(void)
{
    const char *json_object_text =
        "{\"foo\": \"bar\", \"a\": 1, \"b\": 3.141592, \"c\": [1,2,3,4]}";

    const char *keys[] = {"foo", "a", "b", "c"};
    int i;

    json_t *object, *copy;
    void *iter;

    object = json_loads(json_object_text, 0, NULL);
    if(!object)
        fail("unable to parse an object");

    copy = json_deep_copy(object);
    if(!copy)
        fail("unable to deep copy an object");
    if(copy == object)
        fail("deep copying an object doesn't copy");
    if(!json_equal(copy, object))
        fail("deep copying an object produces an inequal copy");

    i = 0;
    iter = json_object_iter(object);
    while(iter)
    {
        const char *key;
        json_t *value1, *value2;

        key = json_object_iter_key(iter);
        value1 = json_object_iter_value(iter);
        value2 = json_object_get(copy, key);

        if(value1 == value2)
            fail("deep copying an object doesn't copy its items");

        if (strcmp(key, keys[i]) != 0)
            fail("deep copying an object doesn't preserve key order");

        iter = json_object_iter_next(object, iter);
        i++;
    }

    json_decref(object);
    json_decref(copy);
}

__attribute__((used)) static void run_tests()
{
    test_copy_simple();
    test_deep_copy_simple();
    test_copy_array();
    test_deep_copy_array();
    test_copy_object();
    test_deep_copy_object();
}

