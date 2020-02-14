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
typedef  int uint8_t ;
struct strbuf {int /*<<< orphan*/  buf; } ;
struct dirent_prec_psx {int max_name_len; scalar_t__ ic_precompose; char* d_name; struct dirent_prec_psx* dirent_nfc; int /*<<< orphan*/  dirp; int /*<<< orphan*/  d_type; int /*<<< orphan*/  d_ino; } ;
struct dirent {char* d_name; int /*<<< orphan*/  d_type; int /*<<< orphan*/  d_ino; } ;
typedef  scalar_t__ iconv_t ;
typedef  int /*<<< orphan*/  iconv_ibp ;
typedef  int /*<<< orphan*/  dirent_prec_psx ;
typedef  struct dirent_prec_psx PREC_DIR ;

/* Variables and functions */
 int O_CREAT ; 
 int O_EXCL ; 
 int O_RDWR ; 
 int /*<<< orphan*/  R_OK ; 
 struct strbuf STRBUF_INIT ; 
 int /*<<< orphan*/  _ (char*) ; 
 scalar_t__ access (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  close (int) ; 
 int closedir (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  die (char*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  die_errno (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int errno ; 
 int /*<<< orphan*/  free (struct dirent_prec_psx*) ; 
 int /*<<< orphan*/  git_config_set (char*,char*) ; 
 int /*<<< orphan*/  git_path_buf (struct strbuf*,char*,char const*) ; 
 int /*<<< orphan*/  iconv (scalar_t__,int /*<<< orphan*/ *,size_t*,char**,size_t*) ; 
 int /*<<< orphan*/  iconv_close (scalar_t__) ; 
 void* iconv_open (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int open (int /*<<< orphan*/ ,int,int) ; 
 int /*<<< orphan*/  opendir (char const*) ; 
 int /*<<< orphan*/  path_encoding ; 
 int precomposed_unicode ; 
 struct dirent* readdir (int /*<<< orphan*/ ) ; 
 char* reencode_string_iconv (char const*,size_t,scalar_t__,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  repo_encoding ; 
 int /*<<< orphan*/  strbuf_release (struct strbuf*) ; 
 int /*<<< orphan*/  strlcpy (char*,char*,size_t) ; 
 int strlen (char*) ; 
 scalar_t__ unlink (int /*<<< orphan*/ ) ; 
 void* xmalloc (int) ; 
 struct dirent_prec_psx* xrealloc (struct dirent_prec_psx*,size_t) ; 

__attribute__((used)) static size_t has_non_ascii(const char *s, size_t maxlen, size_t *strlen_c)
{
	const uint8_t *ptr = (const uint8_t *)s;
	size_t strlen_chars = 0;
	size_t ret = 0;

	if (!ptr || !*ptr)
		return 0;

	while (*ptr && maxlen) {
		if (*ptr & 0x80)
			ret++;
		strlen_chars++;
		ptr++;
		maxlen--;
	}
	if (strlen_c)
		*strlen_c = strlen_chars;

	return ret;
}

void probe_utf8_pathname_composition(void)
{
	struct strbuf path = STRBUF_INIT;
	static const char *auml_nfc = "\xc3\xa4";
	static const char *auml_nfd = "\x61\xcc\x88";
	int output_fd;
	if (precomposed_unicode != -1)
		return; /* We found it defined in the global config, respect it */
	git_path_buf(&path, "%s", auml_nfc);
	output_fd = open(path.buf, O_CREAT|O_EXCL|O_RDWR, 0600);
	if (output_fd >= 0) {
		close(output_fd);
		git_path_buf(&path, "%s", auml_nfd);
		precomposed_unicode = access(path.buf, R_OK) ? 0 : 1;
		git_config_set("core.precomposeunicode",
			       precomposed_unicode ? "true" : "false");
		git_path_buf(&path, "%s", auml_nfc);
		if (unlink(path.buf))
			die_errno(_("failed to unlink '%s'"), path.buf);
	}
	strbuf_release(&path);
}

void precompose_argv(int argc, const char **argv)
{
	int i = 0;
	const char *oldarg;
	char *newarg;
	iconv_t ic_precompose;

	if (precomposed_unicode != 1)
		return;

	ic_precompose = iconv_open(repo_encoding, path_encoding);
	if (ic_precompose == (iconv_t) -1)
		return;

	while (i < argc) {
		size_t namelen;
		oldarg = argv[i];
		if (has_non_ascii(oldarg, (size_t)-1, &namelen)) {
			newarg = reencode_string_iconv(oldarg, namelen, ic_precompose, 0, NULL);
			if (newarg)
				argv[i] = newarg;
		}
		i++;
	}
	iconv_close(ic_precompose);
}

PREC_DIR *precompose_utf8_opendir(const char *dirname)
{
	PREC_DIR *prec_dir = xmalloc(sizeof(PREC_DIR));
	prec_dir->dirent_nfc = xmalloc(sizeof(dirent_prec_psx));
	prec_dir->dirent_nfc->max_name_len = sizeof(prec_dir->dirent_nfc->d_name);

	prec_dir->dirp = opendir(dirname);
	if (!prec_dir->dirp) {
		free(prec_dir->dirent_nfc);
		free(prec_dir);
		return NULL;
	} else {
		int ret_errno = errno;
		prec_dir->ic_precompose = iconv_open(repo_encoding, path_encoding);
		/* if iconv_open() fails, die() in readdir() if needed */
		errno = ret_errno;
	}

	return prec_dir;
}

struct dirent_prec_psx *precompose_utf8_readdir(PREC_DIR *prec_dir)
{
	struct dirent *res;
	res = readdir(prec_dir->dirp);
	if (res) {
		size_t namelenz = strlen(res->d_name) + 1; /* \0 */
		size_t new_maxlen = namelenz;

		int ret_errno = errno;

		if (new_maxlen > prec_dir->dirent_nfc->max_name_len) {
			size_t new_len = sizeof(dirent_prec_psx) + new_maxlen -
				sizeof(prec_dir->dirent_nfc->d_name);

			prec_dir->dirent_nfc = xrealloc(prec_dir->dirent_nfc, new_len);
			prec_dir->dirent_nfc->max_name_len = new_maxlen;
		}

		prec_dir->dirent_nfc->d_ino  = res->d_ino;
		prec_dir->dirent_nfc->d_type = res->d_type;

		if ((precomposed_unicode == 1) && has_non_ascii(res->d_name, (size_t)-1, NULL)) {
			if (prec_dir->ic_precompose == (iconv_t)-1) {
				die("iconv_open(%s,%s) failed, but needed:\n"
						"    precomposed unicode is not supported.\n"
						"    If you want to use decomposed unicode, run\n"
						"    \"git config core.precomposeunicode false\"\n",
						repo_encoding, path_encoding);
			} else {
				iconv_ibp	cp = (iconv_ibp)res->d_name;
				size_t inleft = namelenz;
				char *outpos = &prec_dir->dirent_nfc->d_name[0];
				size_t outsz = prec_dir->dirent_nfc->max_name_len;
				errno = 0;
				iconv(prec_dir->ic_precompose, &cp, &inleft, &outpos, &outsz);
				if (errno || inleft) {
					/*
					 * iconv() failed and errno could be E2BIG, EILSEQ, EINVAL, EBADF
					 * MacOS X avoids illegal byte sequences.
					 * If they occur on a mounted drive (e.g. NFS) it is not worth to
					 * die() for that, but rather let the user see the original name
					*/
					namelenz = 0; /* trigger strlcpy */
				}
			}
		} else
			namelenz = 0;

		if (!namelenz)
			strlcpy(prec_dir->dirent_nfc->d_name, res->d_name,
							prec_dir->dirent_nfc->max_name_len);

		errno = ret_errno;
		return prec_dir->dirent_nfc;
	}
	return NULL;
}

int precompose_utf8_closedir(PREC_DIR *prec_dir)
{
	int ret_value;
	int ret_errno;
	ret_value = closedir(prec_dir->dirp);
	ret_errno = errno;
	if (prec_dir->ic_precompose != (iconv_t)-1)
		iconv_close(prec_dir->ic_precompose);
	free(prec_dir->dirent_nfc);
	free(prec_dir);
	errno = ret_errno;
	return ret_value;
}

