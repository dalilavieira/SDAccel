#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
struct TYPE_2__ {char const* buf; } ;
struct json_writer {TYPE_1__ json; } ;
typedef  int intmax_t ;

/* Variables and functions */
 scalar_t__ ERANGE ; 
 struct json_writer JSON_WRITER_INIT ; 
 int MAX_LINE_LENGTH ; 
 struct json_writer arr1 ; 
 struct json_writer arr2 ; 
 struct json_writer arr3 ; 
 struct json_writer arr4 ; 
 int /*<<< orphan*/  die (char*,...) ; 
 scalar_t__ errno ; 
 int /*<<< orphan*/  exit (int) ; 
 int /*<<< orphan*/  fgets (char*,int,int /*<<< orphan*/ ) ; 
 struct json_writer inline1 ; 
 struct json_writer inline2 ; 
 int /*<<< orphan*/  jw_array_begin (struct json_writer*,int) ; 
 int /*<<< orphan*/  jw_array_double (struct json_writer*,int,double) ; 
 int /*<<< orphan*/  jw_array_false (struct json_writer*) ; 
 int /*<<< orphan*/  jw_array_inline_begin_array (struct json_writer*) ; 
 int /*<<< orphan*/  jw_array_inline_begin_object (struct json_writer*) ; 
 int /*<<< orphan*/  jw_array_intmax (struct json_writer*,int) ; 
 int /*<<< orphan*/  jw_array_null (struct json_writer*) ; 
 int /*<<< orphan*/  jw_array_string (struct json_writer*,char*) ; 
 int /*<<< orphan*/  jw_array_true (struct json_writer*) ; 
 int /*<<< orphan*/  jw_end (struct json_writer*) ; 
 int /*<<< orphan*/  jw_init (struct json_writer*) ; 
 int /*<<< orphan*/  jw_is_terminated (struct json_writer*) ; 
 int /*<<< orphan*/  jw_object_begin (struct json_writer*,int) ; 
 int /*<<< orphan*/  jw_object_double (struct json_writer*,char*,int,double) ; 
 int /*<<< orphan*/  jw_object_false (struct json_writer*,char*) ; 
 int /*<<< orphan*/  jw_object_inline_begin_array (struct json_writer*,char*) ; 
 int /*<<< orphan*/  jw_object_inline_begin_object (struct json_writer*,char*) ; 
 int /*<<< orphan*/  jw_object_intmax (struct json_writer*,char*,int) ; 
 int /*<<< orphan*/  jw_object_null (struct json_writer*,char*) ; 
 int /*<<< orphan*/  jw_object_string (struct json_writer*,char*,char*) ; 
 int /*<<< orphan*/  jw_object_sub_jw (struct json_writer*,char*,struct json_writer*) ; 
 int /*<<< orphan*/  jw_object_true (struct json_writer*,char*) ; 
 struct json_writer mixed1 ; 
 struct json_writer nest1 ; 
 struct json_writer obj1 ; 
 struct json_writer obj2 ; 
 struct json_writer obj3 ; 
 struct json_writer obj4 ; 
 struct json_writer obj5 ; 
 struct json_writer obj6 ; 
 int /*<<< orphan*/  p (struct json_writer) ; 
 int pretty ; 
 int /*<<< orphan*/  printf (char*,char const*,...) ; 
 int /*<<< orphan*/  stdin ; 
 int /*<<< orphan*/  strbuf_release (TYPE_1__*) ; 
 int /*<<< orphan*/  strcmp (char const*,char const*) ; 
 int strlen (char*) ; 
 double strtod (char*,char**) ; 
 char* strtok (char*,char*) ; 
 int strtol (char*,char**,int) ; 
 int /*<<< orphan*/  t (struct json_writer) ; 

__attribute__((used)) static void make_obj1(int pretty)
{
	jw_object_begin(&obj1, pretty);
	{
		jw_object_string(&obj1, "a", "abc");
		jw_object_intmax(&obj1, "b", 42);
		jw_object_true(&obj1, "c");
	}
	jw_end(&obj1);
}

__attribute__((used)) static void make_obj2(int pretty)
{
	jw_object_begin(&obj2, pretty);
	{
		jw_object_intmax(&obj2, "a", -1);
		jw_object_intmax(&obj2, "b", 0x7fffffff);
		jw_object_intmax(&obj2, "c", 0);
	}
	jw_end(&obj2);
}

__attribute__((used)) static void make_obj3(int pretty)
{
	jw_object_begin(&obj3, pretty);
	{
		jw_object_intmax(&obj3, "a", 0);
		jw_object_intmax(&obj3, "b", 0xffffffff);
		jw_object_intmax(&obj3, "c", 0x7fffffffffffffffULL);
	}
	jw_end(&obj3);
}

__attribute__((used)) static void make_obj4(int pretty)
{
	jw_object_begin(&obj4, pretty);
	{
		jw_object_true(&obj4, "t");
		jw_object_false(&obj4, "f");
		jw_object_null(&obj4, "n");
	}
	jw_end(&obj4);
}

__attribute__((used)) static void make_obj5(int pretty)
{
	jw_object_begin(&obj5, pretty);
	{
		jw_object_string(&obj5, "abc" "\x09" "def", "abc" "\\" "def");
	}
	jw_end(&obj5);
}

__attribute__((used)) static void make_obj6(int pretty)
{
	jw_object_begin(&obj6, pretty);
	{
		jw_object_double(&obj6, "a", 2, 3.14159);
	}
	jw_end(&obj6);
}

__attribute__((used)) static void make_arr1(int pretty)
{
	jw_array_begin(&arr1, pretty);
	{
		jw_array_string(&arr1, "abc");
		jw_array_intmax(&arr1, 42);
		jw_array_true(&arr1);
	}
	jw_end(&arr1);
}

__attribute__((used)) static void make_arr2(int pretty)
{
	jw_array_begin(&arr2, pretty);
	{
		jw_array_intmax(&arr2, -1);
		jw_array_intmax(&arr2, 0x7fffffff);
		jw_array_intmax(&arr2, 0);
	}
	jw_end(&arr2);
}

__attribute__((used)) static void make_arr3(int pretty)
{
	jw_array_begin(&arr3, pretty);
	{
		jw_array_intmax(&arr3, 0);
		jw_array_intmax(&arr3, 0xffffffff);
		jw_array_intmax(&arr3, 0x7fffffffffffffffULL);
	}
	jw_end(&arr3);
}

__attribute__((used)) static void make_arr4(int pretty)
{
	jw_array_begin(&arr4, pretty);
	{
		jw_array_true(&arr4);
		jw_array_false(&arr4);
		jw_array_null(&arr4);
	}
	jw_end(&arr4);
}

__attribute__((used)) static void make_nest1(int pretty)
{
	jw_object_begin(&nest1, pretty);
	{
		jw_object_sub_jw(&nest1, "obj1", &obj1);
		jw_object_sub_jw(&nest1, "arr1", &arr1);
	}
	jw_end(&nest1);
}

__attribute__((used)) static void make_inline1(int pretty)
{
	jw_object_begin(&inline1, pretty);
	{
		jw_object_inline_begin_object(&inline1, "obj1");
		{
			jw_object_string(&inline1, "a", "abc");
			jw_object_intmax(&inline1, "b", 42);
			jw_object_true(&inline1, "c");
		}
		jw_end(&inline1);
		jw_object_inline_begin_array(&inline1, "arr1");
		{
			jw_array_string(&inline1, "abc");
			jw_array_intmax(&inline1, 42);
			jw_array_true(&inline1);
		}
		jw_end(&inline1);
	}
	jw_end(&inline1);
}

__attribute__((used)) static void make_inline2(int pretty)
{
	jw_array_begin(&inline2, pretty);
	{
		jw_array_inline_begin_array(&inline2);
		{
			jw_array_intmax(&inline2, 1);
			jw_array_intmax(&inline2, 2);
		}
		jw_end(&inline2);
		jw_array_inline_begin_array(&inline2);
		{
			jw_array_intmax(&inline2, 3);
			jw_array_intmax(&inline2, 4);
		}
		jw_end(&inline2);
		jw_array_inline_begin_object(&inline2);
		{
			jw_object_string(&inline2, "a", "abc");
		}
		jw_end(&inline2);
	}
	jw_end(&inline2);
}

__attribute__((used)) static void make_mixed1(int pretty)
{
	jw_init(&obj1);
	jw_init(&arr1);

	make_obj1(0); /* obj1 is compact */
	make_arr1(1); /* arr1 is pretty */

	jw_object_begin(&mixed1, pretty);
	{
		jw_object_sub_jw(&mixed1, "obj1", &obj1);
		jw_object_sub_jw(&mixed1, "arr1", &arr1);
	}
	jw_end(&mixed1);
}

__attribute__((used)) static void cmp(const char *test, const struct json_writer *jw, const char *exp)
{
	if (!strcmp(jw->json.buf, exp))
		return;

	printf("error[%s]: observed '%s' expected '%s'\n",
	       test, jw->json.buf, exp);
	exit(1);
}

__attribute__((used)) static int unit_tests(void)
{
	/* comptact (canonical) forms */
	t(obj1);
	t(obj2);
	t(obj3);
	t(obj4);
	t(obj5);
	t(obj6);

	t(arr1);
	t(arr2);
	t(arr3);
	t(arr4);

	t(nest1);

	t(inline1);
	t(inline2);

	jw_init(&obj1);
	jw_init(&obj2);
	jw_init(&obj3);
	jw_init(&obj4);

	jw_init(&arr1);
	jw_init(&arr2);
	jw_init(&arr3);
	jw_init(&arr4);

	jw_init(&inline1);
	jw_init(&inline2);

	/* pretty forms */
	p(obj1);
	p(obj2);
	p(obj3);
	p(obj4);

	p(arr1);
	p(arr2);
	p(arr3);
	p(arr4);

	p(inline1);
	p(inline2);

	/* mixed forms */
	t(mixed1);
	jw_init(&mixed1);
	p(mixed1);

	return 0;
}

__attribute__((used)) static void get_s(int line_nr, char **s_in)
{
	*s_in = strtok(NULL, " ");
	if (!*s_in)
		die("line[%d]: expected: <s>", line_nr);
}

__attribute__((used)) static void get_i(int line_nr, intmax_t *s_in)
{
	char *s;
	char *endptr;

	get_s(line_nr, &s);

	*s_in = strtol(s, &endptr, 10);
	if (*endptr || errno == ERANGE)
		die("line[%d]: invalid integer value", line_nr);
}

__attribute__((used)) static void get_d(int line_nr, double *s_in)
{
	char *s;
	char *endptr;

	get_s(line_nr, &s);

	*s_in = strtod(s, &endptr);
	if (*endptr || errno == ERANGE)
		die("line[%d]: invalid float value", line_nr);
}

__attribute__((used)) static char *get_trimmed_line(char *buf, int buf_size)
{
	int len;

	if (!fgets(buf, buf_size, stdin))
		return NULL;

	len = strlen(buf);
	while (len > 0) {
		char c = buf[len - 1];
		if (c == '\n' || c == '\r' || c == ' ' || c == '\t')
			buf[--len] = 0;
		else
			break;
	}

	while (*buf == ' ' || *buf == '\t')
		buf++;

	return buf;
}

__attribute__((used)) static int scripted(void)
{
	struct json_writer jw = JSON_WRITER_INIT;
	char buf[MAX_LINE_LENGTH];
	char *line;
	int line_nr = 0;

	line = get_trimmed_line(buf, MAX_LINE_LENGTH);
	if (!line)
		return 0;

	if (!strcmp(line, "object"))
		jw_object_begin(&jw, pretty);
	else if (!strcmp(line, "array"))
		jw_array_begin(&jw, pretty);
	else
		die("expected first line to be 'object' or 'array'");

	while ((line = get_trimmed_line(buf, MAX_LINE_LENGTH)) != NULL) {
		char *verb;
		char *key;
		char *s_value;
		intmax_t i_value;
		double d_value;

		line_nr++;

		verb = strtok(line, " ");

		if (!strcmp(verb, "end")) {
			jw_end(&jw);
		}
		else if (!strcmp(verb, "object-string")) {
			get_s(line_nr, &key);
			get_s(line_nr, &s_value);
			jw_object_string(&jw, key, s_value);
		}
		else if (!strcmp(verb, "object-int")) {
			get_s(line_nr, &key);
			get_i(line_nr, &i_value);
			jw_object_intmax(&jw, key, i_value);
		}
		else if (!strcmp(verb, "object-double")) {
			get_s(line_nr, &key);
			get_i(line_nr, &i_value);
			get_d(line_nr, &d_value);
			jw_object_double(&jw, key, i_value, d_value);
		}
		else if (!strcmp(verb, "object-true")) {
			get_s(line_nr, &key);
			jw_object_true(&jw, key);
		}
		else if (!strcmp(verb, "object-false")) {
			get_s(line_nr, &key);
			jw_object_false(&jw, key);
		}
		else if (!strcmp(verb, "object-null")) {
			get_s(line_nr, &key);
			jw_object_null(&jw, key);
		}
		else if (!strcmp(verb, "object-object")) {
			get_s(line_nr, &key);
			jw_object_inline_begin_object(&jw, key);
		}
		else if (!strcmp(verb, "object-array")) {
			get_s(line_nr, &key);
			jw_object_inline_begin_array(&jw, key);
		}
		else if (!strcmp(verb, "array-string")) {
			get_s(line_nr, &s_value);
			jw_array_string(&jw, s_value);
		}
		else if (!strcmp(verb, "array-int")) {
			get_i(line_nr, &i_value);
			jw_array_intmax(&jw, i_value);
		}
		else if (!strcmp(verb, "array-double")) {
			get_i(line_nr, &i_value);
			get_d(line_nr, &d_value);
			jw_array_double(&jw, i_value, d_value);
		}
		else if (!strcmp(verb, "array-true"))
			jw_array_true(&jw);
		else if (!strcmp(verb, "array-false"))
			jw_array_false(&jw);
		else if (!strcmp(verb, "array-null"))
			jw_array_null(&jw);
		else if (!strcmp(verb, "array-object"))
			jw_array_inline_begin_object(&jw);
		else if (!strcmp(verb, "array-array"))
			jw_array_inline_begin_array(&jw);
		else
			die("unrecognized token: '%s'", verb);
	}

	if (!jw_is_terminated(&jw))
		die("json not terminated: '%s'", jw.json.buf);

	printf("%s\n", jw.json.buf);

	strbuf_release(&jw.json);
	return 0;
}

int cmd__json_writer(int argc, const char **argv)
{
	argc--; /* skip over "json-writer" arg */
	argv++;

	if (argc > 0 && argv[0][0] == '-') {
		if (!strcmp(argv[0], "-u") || !strcmp(argv[0], "--unit"))
			return unit_tests();

		if (!strcmp(argv[0], "-p") || !strcmp(argv[0], "--pretty"))
			pretty = 1;
	}

	return scripted();
}

