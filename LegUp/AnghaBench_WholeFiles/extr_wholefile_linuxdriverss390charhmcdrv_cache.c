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
typedef  struct hmcdrv_ftp_cmdspec {scalar_t__ id; scalar_t__ ofs; int len; int /*<<< orphan*/  fname; int /*<<< orphan*/ * buf; } const hmcdrv_ftp_cmdspec ;
typedef  int ssize_t ;
typedef  scalar_t__ loff_t ;
typedef  int (* hmcdrv_cache_ftpfunc ) (struct hmcdrv_ftp_cmdspec const*,int*) ;
struct TYPE_2__ {scalar_t__ id; scalar_t__ fsize; scalar_t__ ofs; scalar_t__ len; int /*<<< orphan*/ * content; int /*<<< orphan*/  fname; scalar_t__ timeout; } ;

/* Variables and functions */
 int ENOMEM ; 
 int GFP_DMA ; 
 int GFP_KERNEL ; 
 int HMCDRV_CACHE_TIMEOUT ; 
 scalar_t__ HMCDRV_FTP_DIR ; 
 int /*<<< orphan*/  HMCDRV_FTP_FIDENT_MAX ; 
 scalar_t__ HMCDRV_FTP_GET ; 
 scalar_t__ HMCDRV_FTP_NLIST ; 
 void* HMCDRV_FTP_NOOP ; 
 int HZ ; 
 void* LLONG_MAX ; 
 scalar_t__ __get_free_pages (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  free_pages (unsigned long,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  get_order (size_t) ; 
 TYPE_1__ hmcdrv_cache_file ; 
 int /*<<< orphan*/  hmcdrv_cache_order ; 
 scalar_t__ jiffies ; 
 int /*<<< orphan*/  memcpy (int /*<<< orphan*/ *,int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  pr_debug (char*,size_t,...) ; 
 int /*<<< orphan*/  pr_err (char*,size_t) ; 
 scalar_t__ strcmp (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  strlcpy (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 scalar_t__ time_after (scalar_t__,scalar_t__) ; 

__attribute__((used)) static ssize_t hmcdrv_cache_get(const struct hmcdrv_ftp_cmdspec *ftp)
{
	loff_t pos; /* position in cache (signed) */
	ssize_t len;

	if ((ftp->id != hmcdrv_cache_file.id) ||
	    strcmp(hmcdrv_cache_file.fname, ftp->fname))
		return -1;

	if (ftp->ofs >= hmcdrv_cache_file.fsize) /* EOF ? */
		return 0;

	if ((hmcdrv_cache_file.ofs < 0) || /* has content? */
	    time_after(jiffies, hmcdrv_cache_file.timeout))
		return -1;

	/* there seems to be cached content - calculate the maximum number
	 * of bytes that can be returned (regarding file size and offset)
	 */
	len = hmcdrv_cache_file.fsize - ftp->ofs;

	if (len > ftp->len)
		len = ftp->len;

	/* check if the requested chunk falls into our cache (which starts
	 * at offset 'hmcdrv_cache_file.ofs' in the file of interest)
	 */
	pos = ftp->ofs - hmcdrv_cache_file.ofs;

	if ((pos >= 0) &&
	    ((pos + len) <= hmcdrv_cache_file.len)) {

		memcpy(ftp->buf,
		       hmcdrv_cache_file.content + pos,
		       len);
		pr_debug("using cached content of '%s', returning %zd/%zd bytes\n",
			 hmcdrv_cache_file.fname, len,
			 hmcdrv_cache_file.fsize);

		return len;
	}

	return -1;
}

__attribute__((used)) static ssize_t hmcdrv_cache_do(const struct hmcdrv_ftp_cmdspec *ftp,
			       hmcdrv_cache_ftpfunc func)
{
	ssize_t len;

	/* only cache content if the read/dir cache really exists
	 * (hmcdrv_cache_file.len > 0), is large enough to handle the
	 * request (hmcdrv_cache_file.len >= ftp->len) and there is a need
	 * to do so (ftp->len > 0)
	 */
	if ((ftp->len > 0) && (hmcdrv_cache_file.len >= ftp->len)) {

		/* because the cache is not located at ftp->buf, we have to
		 * assemble a new HMC drive FTP cmd specification (pointing
		 * to our cache, and using the increased size)
		 */
		struct hmcdrv_ftp_cmdspec cftp = *ftp; /* make a copy */
		cftp.buf = hmcdrv_cache_file.content;  /* and update */
		cftp.len = hmcdrv_cache_file.len;      /* buffer data */

		len = func(&cftp, &hmcdrv_cache_file.fsize); /* now do */

		if (len > 0) {
			pr_debug("caching %zd bytes content for '%s'\n",
				 len, ftp->fname);

			if (len > ftp->len)
				len = ftp->len;

			hmcdrv_cache_file.ofs = ftp->ofs;
			hmcdrv_cache_file.timeout = jiffies +
				HMCDRV_CACHE_TIMEOUT * HZ;
			memcpy(ftp->buf, hmcdrv_cache_file.content, len);
		}
	} else {
		len = func(ftp, &hmcdrv_cache_file.fsize);
		hmcdrv_cache_file.ofs = -1; /* invalidate content */
	}

	if (len > 0) {
		/* cache some file info (FTP command, file name and file
		 * size) unconditionally
		 */
		strlcpy(hmcdrv_cache_file.fname, ftp->fname,
			HMCDRV_FTP_FIDENT_MAX);
		hmcdrv_cache_file.id = ftp->id;
		pr_debug("caching cmd %d, file size %zu for '%s'\n",
			 ftp->id, hmcdrv_cache_file.fsize, ftp->fname);
	}

	return len;
}

ssize_t hmcdrv_cache_cmd(const struct hmcdrv_ftp_cmdspec *ftp,
			 hmcdrv_cache_ftpfunc func)
{
	ssize_t len;

	if ((ftp->id == HMCDRV_FTP_DIR) || /* read cache */
	    (ftp->id == HMCDRV_FTP_NLIST) ||
	    (ftp->id == HMCDRV_FTP_GET)) {

		len = hmcdrv_cache_get(ftp);

		if (len >= 0) /* got it from cache ? */
			return len; /* yes */

		len = hmcdrv_cache_do(ftp, func);

		if (len >= 0)
			return len;

	} else {
		len = func(ftp, NULL); /* simply do original command */
	}

	/* invalidate the (read) cache in case there was a write operation
	 * or an error on read/dir
	 */
	hmcdrv_cache_file.id = HMCDRV_FTP_NOOP;
	hmcdrv_cache_file.fsize = LLONG_MAX;
	hmcdrv_cache_file.ofs = -1;

	return len;
}

int hmcdrv_cache_startup(size_t cachesize)
{
	if (cachesize > 0) { /* perform caching ? */
		hmcdrv_cache_order = get_order(cachesize);
		hmcdrv_cache_file.content =
			(void *) __get_free_pages(GFP_KERNEL | GFP_DMA,
						  hmcdrv_cache_order);

		if (!hmcdrv_cache_file.content) {
			pr_err("Allocating the requested cache size of %zu bytes failed\n",
			       cachesize);
			return -ENOMEM;
		}

		pr_debug("content cache enabled, size is %zu bytes\n",
			 cachesize);
	}

	hmcdrv_cache_file.len = cachesize;
	return 0;
}

void hmcdrv_cache_shutdown(void)
{
	if (hmcdrv_cache_file.content) {
		free_pages((unsigned long) hmcdrv_cache_file.content,
			   hmcdrv_cache_order);
		hmcdrv_cache_file.content = NULL;
	}

	hmcdrv_cache_file.id = HMCDRV_FTP_NOOP;
	hmcdrv_cache_file.fsize = LLONG_MAX;
	hmcdrv_cache_file.ofs = -1;
	hmcdrv_cache_file.len = 0; /* no cache */
}

