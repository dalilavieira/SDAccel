#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_19__   TYPE_6__ ;
typedef  struct TYPE_18__   TYPE_5__ ;
typedef  struct TYPE_17__   TYPE_4__ ;
typedef  struct TYPE_16__   TYPE_2__ ;
typedef  struct TYPE_15__   TYPE_1__ ;

/* Type definitions */
struct TYPE_16__ {int ctxlen; scalar_t__ flags; } ;
typedef  TYPE_2__ xpparam_t ;
typedef  int /*<<< orphan*/  xpp ;
typedef  int /*<<< orphan*/  xecfg ;
typedef  TYPE_2__ xdemitconf_t ;
struct TYPE_17__ {int (* out_line ) (void*,TYPE_6__*,int) ;int /*<<< orphan*/ * out_hunk; } ;
typedef  TYPE_4__ xdemitcb_t ;
struct string_list {int nr; TYPE_1__* items; } ;
struct rerere_id {int dummy; } ;
struct pathspec {int dummy; } ;
struct option {int dummy; } ;
struct TYPE_18__ {int /*<<< orphan*/  ptr; } ;
typedef  TYPE_5__ mmfile_t ;
struct TYPE_19__ {int /*<<< orphan*/  size; int /*<<< orphan*/  ptr; } ;
typedef  TYPE_6__ mmbuffer_t ;
struct TYPE_15__ {char* string; struct rerere_id* util; } ;

/* Variables and functions */
 int /*<<< orphan*/  N_ (char*) ; 
 struct option OPT_END () ; 
 struct option OPT_SET_INT (int /*<<< orphan*/ ,char*,int*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  PATHSPEC_PREFER_CWD ; 
 int RERERE_AUTOUPDATE ; 
 int RERERE_NOAUTOUPDATE ; 
 int RERERE_READONLY ; 
 struct rerere_id* RERERE_RESOLVED ; 
 struct string_list STRING_LIST_INIT_DUP ; 
 int /*<<< orphan*/  _ (char*) ; 
 int /*<<< orphan*/  die (int /*<<< orphan*/ ,char*) ; 
 int /*<<< orphan*/  fflush (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  free (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  git_config (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  git_xmerge_config ; 
 int /*<<< orphan*/  memset (TYPE_2__*,int /*<<< orphan*/ ,int) ; 
 int parse_options (int,char const**,char const*,struct option*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  parse_pathspec (struct pathspec*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,char const*,char const**) ; 
 int /*<<< orphan*/  printf (char*,char const*,...) ; 
 scalar_t__ read_mmfile (TYPE_5__*,char const*) ; 
 int repo_rerere (int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  rerere_clear (int /*<<< orphan*/ ,struct string_list*) ; 
 int rerere_forget (int /*<<< orphan*/ ,struct pathspec*) ; 
 int /*<<< orphan*/  rerere_gc (int /*<<< orphan*/ ,struct string_list*) ; 
 char* rerere_path (struct rerere_id const*,char*) ; 
 int /*<<< orphan*/  rerere_remaining (int /*<<< orphan*/ ,struct string_list*) ; 
 int /*<<< orphan*/  rerere_usage ; 
 scalar_t__ setup_rerere (int /*<<< orphan*/ ,struct string_list*,int) ; 
 int /*<<< orphan*/  stdout ; 
 int /*<<< orphan*/  strcmp (char const*,char*) ; 
 int /*<<< orphan*/  string_list_clear (struct string_list*,int) ; 
 int /*<<< orphan*/  the_repository ; 
 int /*<<< orphan*/  usage_with_options (int /*<<< orphan*/ ,struct option*) ; 
 int /*<<< orphan*/  warning (int /*<<< orphan*/ ) ; 
 scalar_t__ write_in_full (int,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int xdi_diff (TYPE_5__*,TYPE_5__*,TYPE_2__*,TYPE_2__*,TYPE_4__*) ; 

__attribute__((used)) static int outf(void *dummy, mmbuffer_t *ptr, int nbuf)
{
	int i;
	for (i = 0; i < nbuf; i++)
		if (write_in_full(1, ptr[i].ptr, ptr[i].size) < 0)
			return -1;
	return 0;
}

__attribute__((used)) static int diff_two(const char *file1, const char *label1,
		const char *file2, const char *label2)
{
	xpparam_t xpp;
	xdemitconf_t xecfg;
	xdemitcb_t ecb;
	mmfile_t minus, plus;
	int ret;

	if (read_mmfile(&minus, file1) || read_mmfile(&plus, file2))
		return -1;

	printf("--- a/%s\n+++ b/%s\n", label1, label2);
	fflush(stdout);
	memset(&xpp, 0, sizeof(xpp));
	xpp.flags = 0;
	memset(&xecfg, 0, sizeof(xecfg));
	xecfg.ctxlen = 3;
	ecb.out_hunk = NULL;
	ecb.out_line = outf;
	ret = xdi_diff(&minus, &plus, &xpp, &xecfg, &ecb);

	free(minus.ptr);
	free(plus.ptr);
	return ret;
}

int cmd_rerere(int argc, const char **argv, const char *prefix)
{
	struct string_list merge_rr = STRING_LIST_INIT_DUP;
	int i, autoupdate = -1, flags = 0;

	struct option options[] = {
		OPT_SET_INT(0, "rerere-autoupdate", &autoupdate,
			N_("register clean resolutions in index"), 1),
		OPT_END(),
	};

	argc = parse_options(argc, argv, prefix, options, rerere_usage, 0);

	git_config(git_xmerge_config, NULL);

	if (autoupdate == 1)
		flags = RERERE_AUTOUPDATE;
	if (autoupdate == 0)
		flags = RERERE_NOAUTOUPDATE;

	if (argc < 1)
		return repo_rerere(the_repository, flags);

	if (!strcmp(argv[0], "forget")) {
		struct pathspec pathspec;
		if (argc < 2)
			warning(_("'git rerere forget' without paths is deprecated"));
		parse_pathspec(&pathspec, 0, PATHSPEC_PREFER_CWD,
			       prefix, argv + 1);
		return rerere_forget(the_repository, &pathspec);
	}

	if (!strcmp(argv[0], "clear")) {
		rerere_clear(the_repository, &merge_rr);
	} else if (!strcmp(argv[0], "gc"))
		rerere_gc(the_repository, &merge_rr);
	else if (!strcmp(argv[0], "status")) {
		if (setup_rerere(the_repository, &merge_rr,
				 flags | RERERE_READONLY) < 0)
			return 0;
		for (i = 0; i < merge_rr.nr; i++)
			printf("%s\n", merge_rr.items[i].string);
	} else if (!strcmp(argv[0], "remaining")) {
		rerere_remaining(the_repository, &merge_rr);
		for (i = 0; i < merge_rr.nr; i++) {
			if (merge_rr.items[i].util != RERERE_RESOLVED)
				printf("%s\n", merge_rr.items[i].string);
			else
				/* prepare for later call to
				 * string_list_clear() */
				merge_rr.items[i].util = NULL;
		}
	} else if (!strcmp(argv[0], "diff")) {
		if (setup_rerere(the_repository, &merge_rr,
				 flags | RERERE_READONLY) < 0)
			return 0;
		for (i = 0; i < merge_rr.nr; i++) {
			const char *path = merge_rr.items[i].string;
			const struct rerere_id *id = merge_rr.items[i].util;
			if (diff_two(rerere_path(id, "preimage"), path, path, path))
				die(_("unable to generate diff for '%s'"), rerere_path(id, NULL));
		}
	} else
		usage_with_options(rerere_usage, options);

	string_list_clear(&merge_rr, 1);
	return 0;
}

