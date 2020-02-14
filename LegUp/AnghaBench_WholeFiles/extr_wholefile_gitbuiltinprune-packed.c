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
struct option {int dummy; } ;
struct object_id {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  N_ (char*) ; 
 struct option const OPT_BIT (char,char*,int*,int /*<<< orphan*/ ,int) ; 
 struct option const OPT_END () ; 
 struct option const OPT_NEGBIT (char,char*,int*,int /*<<< orphan*/ ,int) ; 
 int PRUNE_PACKED_DRY_RUN ; 
 int PRUNE_PACKED_VERBOSE ; 
 int /*<<< orphan*/  _ (char*) ; 
 int /*<<< orphan*/  display_progress (int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  for_each_loose_file_in_objdir (int /*<<< orphan*/ ,int (*) (struct object_id const*,char const*,void*),int /*<<< orphan*/ *,int (*) (unsigned int,char const*,void*),int*) ; 
 int /*<<< orphan*/  get_object_directory () ; 
 int /*<<< orphan*/  has_object_pack (struct object_id const*) ; 
 scalar_t__ isatty (int) ; 
 int parse_options (int,char const**,char const*,struct option const*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  printf (char*,char const*) ; 
 int /*<<< orphan*/  progress ; 
 int /*<<< orphan*/  prune_packed_usage ; 
 int /*<<< orphan*/  rmdir (char const*) ; 
 int /*<<< orphan*/  start_delayed_progress (int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  stop_progress (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  unlink_or_warn (char const*) ; 
 int /*<<< orphan*/  usage_msg_opt (int /*<<< orphan*/ ,int /*<<< orphan*/ ,struct option const*) ; 

__attribute__((used)) static int prune_subdir(unsigned int nr, const char *path, void *data)
{
	int *opts = data;
	display_progress(progress, nr + 1);
	if (!(*opts & PRUNE_PACKED_DRY_RUN))
		rmdir(path);
	return 0;
}

__attribute__((used)) static int prune_object(const struct object_id *oid, const char *path,
			 void *data)
{
	int *opts = data;

	if (!has_object_pack(oid))
		return 0;

	if (*opts & PRUNE_PACKED_DRY_RUN)
		printf("rm -f %s\n", path);
	else
		unlink_or_warn(path);
	return 0;
}

void prune_packed_objects(int opts)
{
	if (opts & PRUNE_PACKED_VERBOSE)
		progress = start_delayed_progress(_("Removing duplicate objects"), 256);

	for_each_loose_file_in_objdir(get_object_directory(),
				      prune_object, NULL, prune_subdir, &opts);

	/* Ensure we show 100% before finishing progress */
	display_progress(progress, 256);
	stop_progress(&progress);
}

int cmd_prune_packed(int argc, const char **argv, const char *prefix)
{
	int opts = isatty(2) ? PRUNE_PACKED_VERBOSE : 0;
	const struct option prune_packed_options[] = {
		OPT_BIT('n', "dry-run", &opts, N_("dry run"),
			PRUNE_PACKED_DRY_RUN),
		OPT_NEGBIT('q', "quiet", &opts, N_("be quiet"),
			   PRUNE_PACKED_VERBOSE),
		OPT_END()
	};

	argc = parse_options(argc, argv, prefix, prune_packed_options,
			     prune_packed_usage, 0);

	if (argc > 0)
		usage_msg_opt(_("too many arguments"),
			      prune_packed_usage,
			      prune_packed_options);

	prune_packed_objects(opts);
	return 0;
}

