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
struct strbuf {char* buf; } ;
struct option {int dummy; } ;
struct child_process {char const** argv; int git_cmd; } ;

/* Variables and functions */
 struct child_process CHILD_PROCESS_INIT ; 
 int /*<<< orphan*/  N_ (char*) ; 
 struct option const OPT_BIT (char,char*,unsigned int*,int /*<<< orphan*/ ,unsigned int) ; 
 struct option const OPT_END () ; 
 struct strbuf STRBUF_INIT ; 
 unsigned int VERIFY_PACK_STAT_ONLY ; 
 unsigned int VERIFY_PACK_VERBOSE ; 
 int /*<<< orphan*/  ends_with (char*,char*) ; 
 int /*<<< orphan*/  git_config (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  git_default_config ; 
 int parse_options (int,char const**,char const*,struct option const*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  printf (char*,char*) ; 
 int run_command (struct child_process*) ; 
 int /*<<< orphan*/  strbuf_addstr (struct strbuf*,char const*) ; 
 int /*<<< orphan*/  strbuf_release (struct strbuf*) ; 
 scalar_t__ strbuf_strip_suffix (struct strbuf*,char*) ; 
 int /*<<< orphan*/  usage_with_options (int /*<<< orphan*/ ,struct option const*) ; 
 int /*<<< orphan*/  verify_pack_usage ; 

__attribute__((used)) static int verify_one_pack(const char *path, unsigned int flags)
{
	struct child_process index_pack = CHILD_PROCESS_INIT;
	const char *argv[] = {"index-pack", NULL, NULL, NULL };
	struct strbuf arg = STRBUF_INIT;
	int verbose = flags & VERIFY_PACK_VERBOSE;
	int stat_only = flags & VERIFY_PACK_STAT_ONLY;
	int err;

	if (stat_only)
		argv[1] = "--verify-stat-only";
	else if (verbose)
		argv[1] = "--verify-stat";
	else
		argv[1] = "--verify";

	/*
	 * In addition to "foo.pack" we accept "foo.idx" and "foo";
	 * normalize these forms to "foo.pack" for "index-pack --verify".
	 */
	strbuf_addstr(&arg, path);
	if (strbuf_strip_suffix(&arg, ".idx") ||
	    !ends_with(arg.buf, ".pack"))
		strbuf_addstr(&arg, ".pack");
	argv[2] = arg.buf;

	index_pack.argv = argv;
	index_pack.git_cmd = 1;

	err = run_command(&index_pack);

	if (verbose || stat_only) {
		if (err)
			printf("%s: bad\n", arg.buf);
		else {
			if (!stat_only)
				printf("%s: ok\n", arg.buf);
		}
	}
	strbuf_release(&arg);

	return err;
}

int cmd_verify_pack(int argc, const char **argv, const char *prefix)
{
	int err = 0;
	unsigned int flags = 0;
	int i;
	const struct option verify_pack_options[] = {
		OPT_BIT('v', "verbose", &flags, N_("verbose"),
			VERIFY_PACK_VERBOSE),
		OPT_BIT('s', "stat-only", &flags, N_("show statistics only"),
			VERIFY_PACK_STAT_ONLY),
		OPT_END()
	};

	git_config(git_default_config, NULL);
	argc = parse_options(argc, argv, prefix, verify_pack_options,
			     verify_pack_usage, 0);
	if (argc < 1)
		usage_with_options(verify_pack_usage, verify_pack_options);
	for (i = 0; i < argc; i++) {
		if (verify_one_pack(argv[i], flags))
			err = 1;
	}

	return err;
}

