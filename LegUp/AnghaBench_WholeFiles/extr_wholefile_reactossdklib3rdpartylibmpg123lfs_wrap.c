#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
struct wrap_data {scalar_t__ iotype; int my_fd; int fd; int /*<<< orphan*/  (* h_cleanup ) (int /*<<< orphan*/ *) ;int /*<<< orphan*/ * r_h_lseek; int /*<<< orphan*/ * r_h_read; int /*<<< orphan*/ * handle; int /*<<< orphan*/ * r_lseek; int /*<<< orphan*/ * r_read; struct wrap_data* indextable; } ;
struct TYPE_3__ {void (* wrapperclean ) (void*) ;struct wrap_data* wrapperdata; int /*<<< orphan*/  err; } ;
typedef  TYPE_1__ mpg123_handle ;

/* Variables and functions */
 scalar_t__ IO_HANDLE ; 
 int /*<<< orphan*/  MPG123_OUT_OF_MEM ; 
 int /*<<< orphan*/  close (int) ; 
 int /*<<< orphan*/  free (struct wrap_data*) ; 
 struct wrap_data* malloc (int) ; 
 int /*<<< orphan*/  stub1 (int /*<<< orphan*/ *) ; 

__attribute__((used)) static void wrap_io_cleanup(void *handle)
{
	struct wrap_data *ioh = handle;
	if(ioh->iotype == IO_HANDLE)
	{
		if(ioh->h_cleanup != NULL && ioh->handle != NULL)
		ioh->h_cleanup(ioh->handle);

		ioh->handle = NULL;
	}
	if(ioh->my_fd >= 0)
	{
		close(ioh->my_fd);
		ioh->my_fd = -1;
	}
}

__attribute__((used)) static void wrap_destroy(void *handle)
{
	struct wrap_data *wh = handle;
	wrap_io_cleanup(handle);
	if(wh->indextable != NULL)
	free(wh->indextable);

	free(wh);
}

__attribute__((used)) static struct wrap_data* wrap_get(mpg123_handle *mh)
{
	struct wrap_data* whd;
	if(mh == NULL) return NULL;

	/* Access the private storage inside the mpg123 handle.
	   The real callback functions and handles are stored there. */
	if(mh->wrapperdata == NULL)
	{
		/* Create a new one. */
		mh->wrapperdata = malloc(sizeof(struct wrap_data));
		if(mh->wrapperdata == NULL)
		{
			mh->err = MPG123_OUT_OF_MEM;
			return NULL;
		}
	/* When we have wrapper data present, the callback for its proper cleanup is needed. */
		mh->wrapperclean = wrap_destroy;

		whd = mh->wrapperdata;
		whd->indextable = NULL;
		whd->iotype = 0;
		whd->fd = -1;
		whd->my_fd = -1;
		whd->r_read = NULL;
		whd->r_lseek = NULL;
		whd->handle = NULL;
		whd->r_h_read = NULL;
		whd->r_h_lseek = NULL;
		whd->h_cleanup = NULL;
	}
	else whd = mh->wrapperdata;

	return whd;
}

