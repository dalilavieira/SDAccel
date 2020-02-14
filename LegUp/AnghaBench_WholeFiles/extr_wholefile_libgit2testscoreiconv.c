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

/* Variables and functions */

void test_core_iconv__initialize(void)
{
#ifdef GIT_USE_ICONV
	cl_git_pass(git_path_iconv_init_precompose(&ic));
#endif
}

void test_core_iconv__cleanup(void)
{
#ifdef GIT_USE_ICONV
	git_path_iconv_clear(&ic);
#endif
}

void test_core_iconv__unchanged(void)
{
#ifdef GIT_USE_ICONV
	const char *data = "Ascii data", *original = data;
	size_t datalen = strlen(data);

	cl_git_pass(git_path_iconv(&ic, &data, &datalen));
	GIT_UNUSED(datalen);

	/* There are no high bits set, so this should leave data untouched */
	cl_assert(data == original);
#endif
}

void test_core_iconv__decomposed_to_precomposed(void)
{
#ifdef GIT_USE_ICONV
	const char *data = nfd;
	size_t datalen, nfdlen = strlen(nfd);

	datalen = nfdlen;
	cl_git_pass(git_path_iconv(&ic, &data, &datalen));
	GIT_UNUSED(datalen);

	/* The decomposed nfd string should be transformed to the nfc form
	 * (on platforms where iconv is enabled, of course).
	 */
	cl_assert_equal_s(nfc, data);

	/* should be able to do it multiple times with the same git_path_iconv_t */
	data = nfd; datalen = nfdlen;
	cl_git_pass(git_path_iconv(&ic, &data, &datalen));
	cl_assert_equal_s(nfc, data);

	data = nfd; datalen = nfdlen;
	cl_git_pass(git_path_iconv(&ic, &data, &datalen));
	cl_assert_equal_s(nfc, data);
#endif
}

void test_core_iconv__precomposed_is_unmodified(void)
{
#ifdef GIT_USE_ICONV
	const char *data = nfc;
	size_t datalen = strlen(nfc);

	cl_git_pass(git_path_iconv(&ic, &data, &datalen));
	GIT_UNUSED(datalen);

	/* data is already in precomposed form, so even though some bytes have
	 * the high-bit set, the iconv transform should result in no change.
	 */
	cl_assert_equal_s(nfc, data);
#endif
}

