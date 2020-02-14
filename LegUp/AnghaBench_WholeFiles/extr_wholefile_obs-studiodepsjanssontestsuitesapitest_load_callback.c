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
struct my_source {size_t cap; size_t off; size_t buf; } ;
typedef  int /*<<< orphan*/  json_t ;
struct TYPE_3__ {int /*<<< orphan*/  text; int /*<<< orphan*/  source; } ;
typedef  TYPE_1__ json_error_t ;

/* Variables and functions */
 int /*<<< orphan*/  fail (char*) ; 
 int /*<<< orphan*/  json_decref (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/ * json_load_callback (size_t (*) (void*,size_t,void*),struct my_source*,int /*<<< orphan*/ ,TYPE_1__*) ; 
 int /*<<< orphan*/  memcpy (void*,size_t,size_t) ; 
 void* my_str ; 
static  void run_tests () ; 
 scalar_t__ strcmp (int /*<<< orphan*/ ,char*) ; 
 void* strlen (void*) ; 

int main() {
#ifdef HAVE_SETLOCALE
    setlocale(LC_ALL, "");
#endif
    run_tests();
    return 0;
}

__attribute__((used)) static size_t greedy_reader(void *buf, size_t buflen, void *arg)
{
    struct my_source *s = arg;
    if (buflen > s->cap - s->off)
        buflen = s->cap - s->off;
    if (buflen > 0) {
        memcpy(buf, s->buf + s->off, buflen);
        s->off += buflen;
        return buflen;
    } else {
        return 0;
    }
}

__attribute__((used)) static void run_tests()
{
    struct my_source s;
    json_t *json;
    json_error_t error;

    s.off = 0;
    s.cap = strlen(my_str);
    s.buf = my_str;

    json = json_load_callback(greedy_reader, &s, 0, &error);

    if (!json)
        fail("json_load_callback failed on a valid callback");
    json_decref(json);

    s.off = 0;
    s.cap = strlen(my_str) - 1;
    s.buf = my_str;

    json = json_load_callback(greedy_reader, &s, 0, &error);
    if (json) {
        json_decref(json);
        fail("json_load_callback should have failed on an incomplete stream, but it didn't");
    }
    if (strcmp(error.source, "<callback>") != 0) {
        fail("json_load_callback returned an invalid error source");
    }
    if (strcmp(error.text, "']' expected near end of file") != 0) {
        fail("json_load_callback returned an invalid error message for an unclosed top-level array");
    }

    json = json_load_callback(NULL, NULL, 0, &error);
    if (json) {
        json_decref(json);
        fail("json_load_callback should have failed on NULL load callback, but it didn't");
    }
    if (strcmp(error.text, "wrong arguments") != 0) {
        fail("json_load_callback returned an invalid error message for a NULL load callback");
    }
}

