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
typedef  int /*<<< orphan*/  buffer_out ;
typedef  int /*<<< orphan*/  buffer ;

/* Variables and functions */
 int /*<<< orphan*/  GIT_EINVALIDSPEC ; 
 unsigned int GIT_REFERENCE_FORMAT_ALLOW_ONELEVEL ; 
 unsigned int GIT_REFERENCE_FORMAT_NORMAL ; 
 unsigned int GIT_REFERENCE_FORMAT_REFSPEC_PATTERN ; 
 int GIT_REFNAME_MAX ; 
 unsigned int ONE_LEVEL_AND_REFSPEC ; 
 int /*<<< orphan*/  cl_assert_equal_i (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  cl_assert_equal_s (char const*,char*) ; 
 int /*<<< orphan*/  cl_git_fail (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  cl_git_pass (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  git_reference_normalize_name (char*,int,char const*,unsigned int) ; 
 int /*<<< orphan*/  p_snprintf (char*,int,char*,char) ; 

__attribute__((used)) static void ensure_refname_normalized(
	unsigned int flags,
	const char *input_refname,
	const char *expected_refname)
{
	char buffer_out[GIT_REFNAME_MAX];

	cl_git_pass(git_reference_normalize_name(buffer_out, sizeof(buffer_out), input_refname, flags));

	cl_assert_equal_s(expected_refname, buffer_out);
}

__attribute__((used)) static void ensure_refname_invalid(unsigned int flags, const char *input_refname)
{
	char buffer_out[GIT_REFNAME_MAX];

	cl_assert_equal_i(
		GIT_EINVALIDSPEC,
		git_reference_normalize_name(buffer_out, sizeof(buffer_out), input_refname, flags));
}

void test_refs_normalize__can_normalize_a_direct_reference_name(void)
{
	ensure_refname_normalized(
		GIT_REFERENCE_FORMAT_NORMAL, "refs/dummy/a", "refs/dummy/a");
	ensure_refname_normalized(
		GIT_REFERENCE_FORMAT_NORMAL, "refs/stash", "refs/stash");
	ensure_refname_normalized(
		GIT_REFERENCE_FORMAT_NORMAL, "refs/tags/a", "refs/tags/a");
	ensure_refname_normalized(
		GIT_REFERENCE_FORMAT_NORMAL, "refs/heads/a/b", "refs/heads/a/b");
	ensure_refname_normalized(
		GIT_REFERENCE_FORMAT_NORMAL, "refs/heads/a./b", "refs/heads/a./b");
	ensure_refname_normalized(
		GIT_REFERENCE_FORMAT_NORMAL, "refs/heads/v@ation", "refs/heads/v@ation");
	ensure_refname_normalized(
		GIT_REFERENCE_FORMAT_NORMAL, "refs///heads///a", "refs/heads/a");
}

void test_refs_normalize__cannot_normalize_any_direct_reference_name(void)
{
	ensure_refname_invalid(
		GIT_REFERENCE_FORMAT_NORMAL, "a");
	ensure_refname_invalid(
		GIT_REFERENCE_FORMAT_NORMAL, "/a");
	ensure_refname_invalid(
		GIT_REFERENCE_FORMAT_NORMAL, "//a");
	ensure_refname_invalid(
		GIT_REFERENCE_FORMAT_NORMAL, "");
	ensure_refname_invalid(
		GIT_REFERENCE_FORMAT_NORMAL, "/refs/heads/a/");
	ensure_refname_invalid(
		GIT_REFERENCE_FORMAT_NORMAL, "refs/heads/a/");
	ensure_refname_invalid(
		GIT_REFERENCE_FORMAT_NORMAL, "refs/heads/a.");
	ensure_refname_invalid(
		GIT_REFERENCE_FORMAT_NORMAL, "refs/heads/a.lock");
	ensure_refname_invalid(
		GIT_REFERENCE_FORMAT_NORMAL, "refs/heads/foo?bar");
	ensure_refname_invalid(
		GIT_REFERENCE_FORMAT_NORMAL, "refs/heads\foo");
	ensure_refname_normalized(
		GIT_REFERENCE_FORMAT_NORMAL, "refs/heads/v@ation", "refs/heads/v@ation");
	ensure_refname_normalized(
		GIT_REFERENCE_FORMAT_NORMAL, "refs///heads///a", "refs/heads/a");
	ensure_refname_invalid(
		GIT_REFERENCE_FORMAT_NORMAL, "refs/heads/.a/b");
	ensure_refname_invalid(
		GIT_REFERENCE_FORMAT_NORMAL, "refs/heads/foo/../bar");
	ensure_refname_invalid(
		GIT_REFERENCE_FORMAT_NORMAL, "refs/heads/foo..bar");
	ensure_refname_invalid(
		GIT_REFERENCE_FORMAT_NORMAL, "refs/heads/./foo");
	ensure_refname_invalid(
		GIT_REFERENCE_FORMAT_NORMAL, "refs/heads/v@{ation");
}

void test_refs_normalize__symbolic(void)
{
	ensure_refname_invalid(
		GIT_REFERENCE_FORMAT_ALLOW_ONELEVEL, "");
	ensure_refname_invalid(
		GIT_REFERENCE_FORMAT_ALLOW_ONELEVEL, "heads\foo");
	ensure_refname_invalid(
		GIT_REFERENCE_FORMAT_ALLOW_ONELEVEL, "/");
	ensure_refname_invalid(
		GIT_REFERENCE_FORMAT_ALLOW_ONELEVEL, "///");

	ensure_refname_normalized(
		GIT_REFERENCE_FORMAT_ALLOW_ONELEVEL, "ALL_CAPS_AND_UNDERSCORES", "ALL_CAPS_AND_UNDERSCORES");
	ensure_refname_normalized(
		GIT_REFERENCE_FORMAT_ALLOW_ONELEVEL, "refs/MixedCasing", "refs/MixedCasing");
	ensure_refname_normalized(
		GIT_REFERENCE_FORMAT_ALLOW_ONELEVEL, "refs///heads///a", "refs/heads/a");

	ensure_refname_normalized(
		GIT_REFERENCE_FORMAT_ALLOW_ONELEVEL, "HEAD", "HEAD");
	ensure_refname_normalized(
		GIT_REFERENCE_FORMAT_ALLOW_ONELEVEL, "MERGE_HEAD", "MERGE_HEAD");
	ensure_refname_normalized(
		GIT_REFERENCE_FORMAT_ALLOW_ONELEVEL, "FETCH_HEAD", "FETCH_HEAD");
}

void test_refs_normalize__jgit_suite(void)
{
	/* tests borrowed from JGit */

/* EmptyString */
	ensure_refname_invalid(
		GIT_REFERENCE_FORMAT_ALLOW_ONELEVEL, "");
	ensure_refname_invalid(
		GIT_REFERENCE_FORMAT_ALLOW_ONELEVEL, "/");

/* MustHaveTwoComponents */
	ensure_refname_invalid(
		GIT_REFERENCE_FORMAT_NORMAL, "master");
	ensure_refname_normalized(
		GIT_REFERENCE_FORMAT_NORMAL, "heads/master", "heads/master");

/* ValidHead */
	ensure_refname_normalized(
		GIT_REFERENCE_FORMAT_ALLOW_ONELEVEL, "refs/heads/master", "refs/heads/master");
	ensure_refname_normalized(
		GIT_REFERENCE_FORMAT_ALLOW_ONELEVEL, "refs/heads/pu", "refs/heads/pu");
	ensure_refname_normalized(
		GIT_REFERENCE_FORMAT_ALLOW_ONELEVEL, "refs/heads/z", "refs/heads/z");
	ensure_refname_normalized(
		GIT_REFERENCE_FORMAT_ALLOW_ONELEVEL, "refs/heads/FoO", "refs/heads/FoO");

/* ValidTag */
	ensure_refname_normalized(
		GIT_REFERENCE_FORMAT_ALLOW_ONELEVEL, "refs/tags/v1.0", "refs/tags/v1.0");

/* NoLockSuffix */
	ensure_refname_invalid(GIT_REFERENCE_FORMAT_ALLOW_ONELEVEL, "refs/heads/master.lock");

/* NoDirectorySuffix */
	ensure_refname_invalid(
		GIT_REFERENCE_FORMAT_ALLOW_ONELEVEL, "refs/heads/master/");

/* NoSpace */
	ensure_refname_invalid(
		GIT_REFERENCE_FORMAT_ALLOW_ONELEVEL, "refs/heads/i haz space");

/* NoAsciiControlCharacters */
	{
		char c;
		char buffer[GIT_REFNAME_MAX];
		for (c = '\1'; c < ' '; c++) {
			p_snprintf(buffer, sizeof(buffer), "refs/heads/mast%cer", c);
			ensure_refname_invalid(GIT_REFERENCE_FORMAT_ALLOW_ONELEVEL, buffer);
		}
	}

/* NoBareDot */
	ensure_refname_invalid(
		GIT_REFERENCE_FORMAT_ALLOW_ONELEVEL, "refs/heads/.");
	ensure_refname_invalid(
		GIT_REFERENCE_FORMAT_ALLOW_ONELEVEL, "refs/heads/..");
	ensure_refname_invalid(
		GIT_REFERENCE_FORMAT_ALLOW_ONELEVEL, "refs/heads/./master");
	ensure_refname_invalid(
		GIT_REFERENCE_FORMAT_ALLOW_ONELEVEL, "refs/heads/../master");

/* NoLeadingOrTrailingDot */
	ensure_refname_invalid(
		GIT_REFERENCE_FORMAT_ALLOW_ONELEVEL, ".");
	ensure_refname_invalid(
		GIT_REFERENCE_FORMAT_ALLOW_ONELEVEL, "refs/heads/.bar");
	ensure_refname_invalid(
		GIT_REFERENCE_FORMAT_ALLOW_ONELEVEL, "refs/heads/..bar");
	ensure_refname_invalid(
		GIT_REFERENCE_FORMAT_ALLOW_ONELEVEL, "refs/heads/bar.");

/* ContainsDot */
	ensure_refname_normalized(
		GIT_REFERENCE_FORMAT_ALLOW_ONELEVEL, "refs/heads/m.a.s.t.e.r", "refs/heads/m.a.s.t.e.r");
	ensure_refname_invalid(
		GIT_REFERENCE_FORMAT_ALLOW_ONELEVEL, "refs/heads/master..pu");

/* NoMagicRefCharacters */
	ensure_refname_invalid(
		GIT_REFERENCE_FORMAT_ALLOW_ONELEVEL, "refs/heads/master^");
	ensure_refname_invalid(
		GIT_REFERENCE_FORMAT_ALLOW_ONELEVEL, "refs/heads/^master");
	ensure_refname_invalid(
		GIT_REFERENCE_FORMAT_ALLOW_ONELEVEL, "^refs/heads/master");

	ensure_refname_invalid(
		GIT_REFERENCE_FORMAT_ALLOW_ONELEVEL, "refs/heads/master~");
	ensure_refname_invalid(
		GIT_REFERENCE_FORMAT_ALLOW_ONELEVEL, "refs/heads/~master");
	ensure_refname_invalid(
		GIT_REFERENCE_FORMAT_ALLOW_ONELEVEL, "~refs/heads/master");

	ensure_refname_invalid(
		GIT_REFERENCE_FORMAT_ALLOW_ONELEVEL, "refs/heads/master:");
	ensure_refname_invalid(
		GIT_REFERENCE_FORMAT_ALLOW_ONELEVEL, "refs/heads/:master");
	ensure_refname_invalid(
		GIT_REFERENCE_FORMAT_ALLOW_ONELEVEL, ":refs/heads/master");

/* ShellGlob */
	ensure_refname_invalid(
		GIT_REFERENCE_FORMAT_ALLOW_ONELEVEL, "refs/heads/master?");
	ensure_refname_invalid(
		GIT_REFERENCE_FORMAT_ALLOW_ONELEVEL, "refs/heads/?master");
	ensure_refname_invalid(
		GIT_REFERENCE_FORMAT_ALLOW_ONELEVEL, "?refs/heads/master");

	ensure_refname_invalid(
		GIT_REFERENCE_FORMAT_ALLOW_ONELEVEL, "refs/heads/master[");
	ensure_refname_invalid(
		GIT_REFERENCE_FORMAT_ALLOW_ONELEVEL, "refs/heads/[master");
	ensure_refname_invalid(
		GIT_REFERENCE_FORMAT_ALLOW_ONELEVEL, "[refs/heads/master");

	ensure_refname_invalid(
		GIT_REFERENCE_FORMAT_ALLOW_ONELEVEL, "refs/heads/master*");
	ensure_refname_invalid(
		GIT_REFERENCE_FORMAT_ALLOW_ONELEVEL, "refs/heads/*master");
	ensure_refname_invalid(
		GIT_REFERENCE_FORMAT_ALLOW_ONELEVEL, "*refs/heads/master");

/* ValidSpecialCharacters */
	ensure_refname_normalized
		(GIT_REFERENCE_FORMAT_ALLOW_ONELEVEL, "refs/heads/!", "refs/heads/!");
	ensure_refname_normalized(
		GIT_REFERENCE_FORMAT_ALLOW_ONELEVEL, "refs/heads/\"", "refs/heads/\"");
	ensure_refname_normalized(
		GIT_REFERENCE_FORMAT_ALLOW_ONELEVEL, "refs/heads/#", "refs/heads/#");
	ensure_refname_normalized(
		GIT_REFERENCE_FORMAT_ALLOW_ONELEVEL, "refs/heads/$", "refs/heads/$");
	ensure_refname_normalized(
		GIT_REFERENCE_FORMAT_ALLOW_ONELEVEL, "refs/heads/%", "refs/heads/%");
	ensure_refname_normalized(
		GIT_REFERENCE_FORMAT_ALLOW_ONELEVEL, "refs/heads/&", "refs/heads/&");
	ensure_refname_normalized(
		GIT_REFERENCE_FORMAT_ALLOW_ONELEVEL, "refs/heads/'", "refs/heads/'");
	ensure_refname_normalized(
		GIT_REFERENCE_FORMAT_ALLOW_ONELEVEL, "refs/heads/(", "refs/heads/(");
	ensure_refname_normalized(
		GIT_REFERENCE_FORMAT_ALLOW_ONELEVEL, "refs/heads/)", "refs/heads/)");
	ensure_refname_normalized(
		GIT_REFERENCE_FORMAT_ALLOW_ONELEVEL, "refs/heads/+", "refs/heads/+");
	ensure_refname_normalized(
		GIT_REFERENCE_FORMAT_ALLOW_ONELEVEL, "refs/heads/,", "refs/heads/,");
	ensure_refname_normalized(
		GIT_REFERENCE_FORMAT_ALLOW_ONELEVEL, "refs/heads/-", "refs/heads/-");
	ensure_refname_normalized(
		GIT_REFERENCE_FORMAT_ALLOW_ONELEVEL, "refs/heads/;", "refs/heads/;");
	ensure_refname_normalized(
		GIT_REFERENCE_FORMAT_ALLOW_ONELEVEL, "refs/heads/<", "refs/heads/<");
	ensure_refname_normalized(
		GIT_REFERENCE_FORMAT_ALLOW_ONELEVEL, "refs/heads/=", "refs/heads/=");
	ensure_refname_normalized(
		GIT_REFERENCE_FORMAT_ALLOW_ONELEVEL, "refs/heads/>", "refs/heads/>");
	ensure_refname_normalized(
		GIT_REFERENCE_FORMAT_ALLOW_ONELEVEL, "refs/heads/@", "refs/heads/@");
	ensure_refname_normalized(
		GIT_REFERENCE_FORMAT_ALLOW_ONELEVEL, "refs/heads/]", "refs/heads/]");
	ensure_refname_normalized(
		GIT_REFERENCE_FORMAT_ALLOW_ONELEVEL, "refs/heads/_", "refs/heads/_");
	ensure_refname_normalized(
		GIT_REFERENCE_FORMAT_ALLOW_ONELEVEL, "refs/heads/`", "refs/heads/`");
	ensure_refname_normalized(
		GIT_REFERENCE_FORMAT_ALLOW_ONELEVEL, "refs/heads/{", "refs/heads/{");
	ensure_refname_normalized(
		GIT_REFERENCE_FORMAT_ALLOW_ONELEVEL, "refs/heads/|", "refs/heads/|");
	ensure_refname_normalized(
		GIT_REFERENCE_FORMAT_ALLOW_ONELEVEL, "refs/heads/}", "refs/heads/}");

	/*
	 * This is valid on UNIX, but not on Windows
	 * hence we make in invalid due to non-portability
	 */
	ensure_refname_invalid(
		GIT_REFERENCE_FORMAT_ALLOW_ONELEVEL, "refs/heads/\\");

/* UnicodeNames */
	/*
	 * Currently this fails.
	 * ensure_refname_normalized(GIT_REFERENCE_FORMAT_ALLOW_ONELEVEL, "refs/heads/\u00e5ngstr\u00f6m", "refs/heads/\u00e5ngstr\u00f6m");
	 */

/* RefLogQueryIsValidRef */
	ensure_refname_invalid(
		GIT_REFERENCE_FORMAT_ALLOW_ONELEVEL, "refs/heads/master@{1}");
	ensure_refname_invalid(
		GIT_REFERENCE_FORMAT_ALLOW_ONELEVEL, "refs/heads/master@{1.hour.ago}");
}

void test_refs_normalize__buffer_has_to_be_big_enough_to_hold_the_normalized_version(void)
{
	char buffer_out[21];

	cl_git_pass(git_reference_normalize_name(
		buffer_out, 21, "refs//heads///long///name", GIT_REFERENCE_FORMAT_NORMAL));
	cl_git_fail(git_reference_normalize_name(
		buffer_out, 20, "refs//heads///long///name", GIT_REFERENCE_FORMAT_NORMAL));
}

void test_refs_normalize__refspec_pattern(void)
{
	ensure_refname_invalid(
		GIT_REFERENCE_FORMAT_REFSPEC_PATTERN, "heads/*foo/bar");
	ensure_refname_invalid(
		GIT_REFERENCE_FORMAT_REFSPEC_PATTERN, "heads/foo*/bar");
	ensure_refname_invalid(
		GIT_REFERENCE_FORMAT_REFSPEC_PATTERN, "heads/f*o/bar");

	ensure_refname_invalid(
		GIT_REFERENCE_FORMAT_REFSPEC_PATTERN, "foo");
	ensure_refname_normalized(
		ONE_LEVEL_AND_REFSPEC, "FOO", "FOO");

	ensure_refname_normalized(
		GIT_REFERENCE_FORMAT_REFSPEC_PATTERN, "foo/bar", "foo/bar");
	ensure_refname_normalized(
		ONE_LEVEL_AND_REFSPEC, "foo/bar", "foo/bar");

	ensure_refname_normalized(
		GIT_REFERENCE_FORMAT_REFSPEC_PATTERN, "*/foo", "*/foo");
	ensure_refname_normalized(
		ONE_LEVEL_AND_REFSPEC, "*/foo", "*/foo");

	ensure_refname_normalized(
		GIT_REFERENCE_FORMAT_REFSPEC_PATTERN, "foo/*/bar", "foo/*/bar");
	ensure_refname_normalized(
		ONE_LEVEL_AND_REFSPEC, "foo/*/bar", "foo/*/bar");

	ensure_refname_invalid(
		GIT_REFERENCE_FORMAT_REFSPEC_PATTERN, "*");
	ensure_refname_normalized(
		ONE_LEVEL_AND_REFSPEC, "*", "*");

	ensure_refname_invalid(
		GIT_REFERENCE_FORMAT_REFSPEC_PATTERN, "foo/*/*");
	ensure_refname_invalid(
		ONE_LEVEL_AND_REFSPEC, "foo/*/*");

	ensure_refname_invalid(
		GIT_REFERENCE_FORMAT_REFSPEC_PATTERN, "*/foo/*");
	ensure_refname_invalid(
		ONE_LEVEL_AND_REFSPEC, "*/foo/*");

	ensure_refname_invalid(
		GIT_REFERENCE_FORMAT_REFSPEC_PATTERN, "*/*/foo");
	ensure_refname_invalid(
		ONE_LEVEL_AND_REFSPEC, "*/*/foo");
}

