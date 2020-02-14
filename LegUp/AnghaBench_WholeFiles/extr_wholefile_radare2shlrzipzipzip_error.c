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
struct zip_source {int dummy; } ;
struct zip_error {int zip_err; int sys_err; int /*<<< orphan*/ * str; } ;

/* Variables and functions */
 void* ZIP_ER_OK ; 
 scalar_t__ ZIP_ET_NONE ; 
 int /*<<< orphan*/  free (int /*<<< orphan*/ *) ; 
 int tolower (unsigned char) ; 
 scalar_t__ zip_error_get_sys_type (int) ; 
 int /*<<< orphan*/  zip_source_error (struct zip_source*,int*,int*) ; 

__attribute__((used)) static inline int __strcasecmp(const char *s1, const char *s2) {
	int c1, c2;
	for(;;) {
		c1 = tolower ( (unsigned char) *s1++ );
		c2 = tolower ( (unsigned char) *s2++ );
		if (c1 == 0 || c1 != c2)
			return c1 - c2;
	}
}

void
_zip_error_clear(struct zip_error *err)
{
    if (err == NULL)
	return;

    err->zip_err = ZIP_ER_OK;
    err->sys_err = 0;
}

void
_zip_error_copy(struct zip_error *dst, const struct zip_error *src)
{
    dst->zip_err = src->zip_err;
    dst->sys_err = src->sys_err;
}

void
_zip_error_fini(struct zip_error *err)
{
    free(err->str);
    err->str = NULL;
}

void
_zip_error_get(const struct zip_error *err, int *zep, int *sep)
{
    if (zep)
	*zep = err->zip_err;
    if (sep) {
	if (zip_error_get_sys_type(err->zip_err) != ZIP_ET_NONE)
	    *sep = err->sys_err;
	else
	    *sep = 0;
    }
}

void
_zip_error_init(struct zip_error *err)
{
    err->zip_err = ZIP_ER_OK;
    err->sys_err = 0;
    err->str = NULL;
}

void
_zip_error_set(struct zip_error *err, int ze, int se)
{
    if (err) {
	err->zip_err = ze;
	err->sys_err = se;
    }
}

void
_zip_error_set_from_source(struct zip_error *err, struct zip_source *src)
{
    int ze, se;
    
    zip_source_error(src, &ze, &se);
    _zip_error_set(err, ze, se);
}

