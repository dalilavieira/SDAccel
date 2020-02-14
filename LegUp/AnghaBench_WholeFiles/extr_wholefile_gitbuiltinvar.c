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
struct git_var {char* (* read ) (int) ;char* name; } ;

/* Variables and functions */
 int IDENT_STRICT ; 
 int /*<<< orphan*/  die (char*) ; 
 int /*<<< orphan*/  git_config (int (*) (char const*,char const*,void*),int /*<<< orphan*/ *) ; 
 int git_default_config (char const*,char const*,void*) ; 
 char* git_editor () ; 
 char* git_pager (int) ; 
 struct git_var* git_vars ; 
 int /*<<< orphan*/  printf (char*,char const*,...) ; 
 scalar_t__ strcmp (char const*,char*) ; 
 char* stub1 (int) ; 
 char* stub2 (int) ; 
 int /*<<< orphan*/  usage (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  var_usage ; 

__attribute__((used)) static const char *editor(int flag)
{
	const char *pgm = git_editor();

	if (!pgm && flag & IDENT_STRICT)
		die("Terminal is dumb, but EDITOR unset");

	return pgm;
}

__attribute__((used)) static const char *pager(int flag)
{
	const char *pgm = git_pager(1);

	if (!pgm)
		pgm = "cat";
	return pgm;
}

__attribute__((used)) static void list_vars(void)
{
	struct git_var *ptr;
	const char *val;

	for (ptr = git_vars; ptr->read; ptr++)
		if ((val = ptr->read(0)))
			printf("%s=%s\n", ptr->name, val);
}

__attribute__((used)) static const char *read_var(const char *var)
{
	struct git_var *ptr;
	const char *val;
	val = NULL;
	for (ptr = git_vars; ptr->read; ptr++) {
		if (strcmp(var, ptr->name) == 0) {
			val = ptr->read(IDENT_STRICT);
			break;
		}
	}
	return val;
}

__attribute__((used)) static int show_config(const char *var, const char *value, void *cb)
{
	if (value)
		printf("%s=%s\n", var, value);
	else
		printf("%s\n", var);
	return git_default_config(var, value, cb);
}

int cmd_var(int argc, const char **argv, const char *prefix)
{
	const char *val = NULL;
	if (argc != 2)
		usage(var_usage);

	if (strcmp(argv[1], "-l") == 0) {
		git_config(show_config, NULL);
		list_vars();
		return 0;
	}
	git_config(git_default_config, NULL);
	val = read_var(argv[1]);
	if (!val)
		usage(var_usage);

	printf("%s\n", val);

	return 0;
}

