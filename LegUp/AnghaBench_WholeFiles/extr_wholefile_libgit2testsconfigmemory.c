#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_5__   TYPE_1__ ;

/* Type definitions */
struct expected_entry {int seen; char* member_0; char* member_1; int /*<<< orphan*/  member_2; scalar_t__ name; scalar_t__ value; } ;
struct TYPE_5__ {int /*<<< orphan*/  value; int /*<<< orphan*/  name; } ;
typedef  TYPE_1__ git_config_entry ;
typedef  int /*<<< orphan*/  git_config_backend ;

/* Variables and functions */
 int /*<<< orphan*/ * backend ; 
 int /*<<< orphan*/  cl_assert (int) ; 
 int /*<<< orphan*/  cl_assert_equal_s (int /*<<< orphan*/ ,char const*) ; 
 int /*<<< orphan*/  cl_fail (char*) ; 
 int /*<<< orphan*/  cl_git_fail (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  cl_git_pass (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  git_config_backend_delete (int /*<<< orphan*/ *,char*) ; 
 int /*<<< orphan*/  git_config_backend_foreach (int /*<<< orphan*/ *,int (*) (TYPE_1__ const*,void*),struct expected_entry*) ; 
 int /*<<< orphan*/  git_config_backend_free (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  git_config_backend_from_string (int /*<<< orphan*/ **,char const*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  git_config_backend_get_string (TYPE_1__**,int /*<<< orphan*/ *,char const*) ; 
 int /*<<< orphan*/  git_config_backend_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  git_config_backend_open (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  git_config_backend_set_string (int /*<<< orphan*/ *,char*,char*) ; 
 int /*<<< orphan*/  git_config_backend_unlock (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 scalar_t__ strcmp (scalar_t__,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  strlen (char const*) ; 

void test_config_memory__initialize(void)
{
	backend = NULL;
}

void test_config_memory__cleanup(void)
{
	git_config_backend_free(backend);
}

__attribute__((used)) static void assert_config_contains(git_config_backend *backend,
	const char *name, const char *value)
{
	git_config_entry *entry;
	cl_git_pass(git_config_backend_get_string(&entry, backend, name));
	cl_assert_equal_s(entry->value, value);
}

__attribute__((used)) static int contains_all_cb(const git_config_entry *entry, void *payload)
{
	struct expected_entry *entries = (struct expected_entry *) payload;
	int i;

	for (i = 0; entries[i].name; i++) {
		if (strcmp(entries[i].name, entry->name) ||
		    strcmp(entries[i].value , entry->value))
			continue;

		if (entries[i].seen)
			cl_fail("Entry seen more than once");
		entries[i].seen = 1;
		return 0;
	}

	cl_fail("Unexpected entry");
	return -1;
}

__attribute__((used)) static void assert_config_contains_all(git_config_backend *backend,
	struct expected_entry *entries)
{
	int i;

	cl_git_pass(git_config_backend_foreach(backend, contains_all_cb, entries));

	for (i = 0; entries[i].name; i++)
		cl_assert(entries[i].seen);
}

__attribute__((used)) static void setup_backend(const char *cfg)
{
	cl_git_pass(git_config_backend_from_string(&backend, cfg, strlen(cfg)));
	cl_git_pass(git_config_backend_open(backend, 0, NULL));
}

void test_config_memory__write_operations_fail(void)
{
	setup_backend("");
	cl_git_fail(git_config_backend_set_string(backend, "general.foo", "var"));
	cl_git_fail(git_config_backend_delete(backend, "general.foo"));
	cl_git_fail(git_config_backend_lock(backend));
	cl_git_fail(git_config_backend_unlock(backend, 0));
}

void test_config_memory__simple(void)
{
	setup_backend(
		"[general]\n"
		"foo=bar\n");

	assert_config_contains(backend, "general.foo", "bar");
}

void test_config_memory__malformed_fails_to_open(void)
{
	const char *cfg =
		"[general\n"
		"foo=bar\n";
	cl_git_pass(git_config_backend_from_string(&backend, cfg, strlen(cfg)));
	cl_git_fail(git_config_backend_open(backend, 0, NULL));
}

void test_config_memory__multiple_vars(void)
{
	setup_backend(
		"[general]\n"
		"foo=bar\n"
		"key=value\n");
	assert_config_contains(backend, "general.foo", "bar");
	assert_config_contains(backend, "general.key", "value");
}

void test_config_memory__multiple_sections(void)
{
	setup_backend(
		"[general]\n"
		"foo=bar\n"
		"\n"
		"[other]\n"
		"key=value\n");
	assert_config_contains(backend, "general.foo", "bar");
	assert_config_contains(backend, "other.key", "value");
}

void test_config_memory__multivar_gets_correct_string(void)
{
	setup_backend(
		"[general]\n"
		"foo=bar1\n"
		"foo=bar2\n");
	assert_config_contains(backend, "general.foo", "bar2");
}

void test_config_memory__foreach_sees_multivar(void)
{
	struct expected_entry entries[] = {
		{ "general.foo", "bar1", 0 },
		{ "general.foo", "bar2", 0 },
		{ NULL, NULL, 0 },
	};

	setup_backend(
		"[general]\n"
		"foo=bar1\n"
		"foo=bar2\n");
	assert_config_contains_all(backend, entries);
}

