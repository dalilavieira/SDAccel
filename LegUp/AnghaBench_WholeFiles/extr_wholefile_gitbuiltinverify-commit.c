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
struct signature_check {int dummy; } ;
struct option {int dummy; } ;
struct object_id {int dummy; } ;
typedef  int /*<<< orphan*/  signature_check ;
typedef  enum object_type { ____Placeholder_object_type } object_type ;

/* Variables and functions */
 int /*<<< orphan*/  GPG_VERIFY_RAW ; 
 unsigned int GPG_VERIFY_VERBOSE ; 
 int /*<<< orphan*/  N_ (char*) ; 
 int OBJ_COMMIT ; 
 struct option const OPT_BIT (int /*<<< orphan*/ ,char*,unsigned int*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 struct option const OPT_END () ; 
 struct option const OPT__VERBOSE (int*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  PARSE_OPT_KEEP_ARGV0 ; 
 int /*<<< orphan*/  SIGPIPE ; 
 int /*<<< orphan*/  SIG_IGN ; 
 int check_commit_signature (int /*<<< orphan*/ ,struct signature_check*) ; 
 int error (char*,char const*,...) ; 
 int /*<<< orphan*/  free (char*) ; 
 scalar_t__ get_oid (char const*,struct object_id*) ; 
 int /*<<< orphan*/  git_config (int (*) (char const*,char const*,void*),int /*<<< orphan*/ *) ; 
 int git_default_config (char const*,char const*,void*) ; 
 int git_gpg_config (char const*,char const*,void*) ; 
 int /*<<< orphan*/  lookup_commit (int /*<<< orphan*/ ,struct object_id const*) ; 
 int /*<<< orphan*/  memset (struct signature_check*,int /*<<< orphan*/ ,int) ; 
 int parse_options (int,char const**,char const*,struct option const*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  print_signature_buffer (struct signature_check*,unsigned int) ; 
 char* read_object_file (struct object_id*,int*,unsigned long*) ; 
 int /*<<< orphan*/  signal (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  signature_check_clear (struct signature_check*) ; 
 int /*<<< orphan*/  the_repository ; 
 char* type_name (int) ; 
 int /*<<< orphan*/  usage_with_options (int /*<<< orphan*/ ,struct option const*) ; 
 int /*<<< orphan*/  verify_commit_usage ; 

__attribute__((used)) static int run_gpg_verify(const struct object_id *oid, const char *buf, unsigned long size, unsigned flags)
{
	struct signature_check signature_check;
	int ret;

	memset(&signature_check, 0, sizeof(signature_check));

	ret = check_commit_signature(lookup_commit(the_repository, oid),
				     &signature_check);
	print_signature_buffer(&signature_check, flags);

	signature_check_clear(&signature_check);
	return ret;
}

__attribute__((used)) static int verify_commit(const char *name, unsigned flags)
{
	enum object_type type;
	struct object_id oid;
	char *buf;
	unsigned long size;
	int ret;

	if (get_oid(name, &oid))
		return error("commit '%s' not found.", name);

	buf = read_object_file(&oid, &type, &size);
	if (!buf)
		return error("%s: unable to read file.", name);
	if (type != OBJ_COMMIT)
		return error("%s: cannot verify a non-commit object of type %s.",
				name, type_name(type));

	ret = run_gpg_verify(&oid, buf, size, flags);

	free(buf);
	return ret;
}

__attribute__((used)) static int git_verify_commit_config(const char *var, const char *value, void *cb)
{
	int status = git_gpg_config(var, value, cb);
	if (status)
		return status;
	return git_default_config(var, value, cb);
}

int cmd_verify_commit(int argc, const char **argv, const char *prefix)
{
	int i = 1, verbose = 0, had_error = 0;
	unsigned flags = 0;
	const struct option verify_commit_options[] = {
		OPT__VERBOSE(&verbose, N_("print commit contents")),
		OPT_BIT(0, "raw", &flags, N_("print raw gpg status output"), GPG_VERIFY_RAW),
		OPT_END()
	};

	git_config(git_verify_commit_config, NULL);

	argc = parse_options(argc, argv, prefix, verify_commit_options,
			     verify_commit_usage, PARSE_OPT_KEEP_ARGV0);
	if (argc <= i)
		usage_with_options(verify_commit_usage, verify_commit_options);

	if (verbose)
		flags |= GPG_VERIFY_VERBOSE;

	/* sometimes the program was terminated because this signal
	 * was received in the process of writing the gpg input: */
	signal(SIGPIPE, SIG_IGN);
	while (i < argc)
		if (verify_commit(argv[i++], flags))
			had_error = 1;
	return had_error;
}

