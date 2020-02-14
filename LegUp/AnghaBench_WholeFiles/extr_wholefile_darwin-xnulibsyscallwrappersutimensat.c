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
typedef  int /*<<< orphan*/  times_in ;
struct timeval {int dummy; } ;
struct timespec {scalar_t__ tv_nsec; } ;
struct attrlist {int commonattr; int /*<<< orphan*/  bitmapcount; } ;

/* Variables and functions */
 int /*<<< orphan*/  ATTR_BIT_MAP_COUNT ; 
 int ATTR_CMN_ACCTIME ; 
 int ATTR_CMN_MODTIME ; 
 int AT_SYMLINK_NOFOLLOW ; 
 int FSOPT_NOFOLLOW ; 
 int /*<<< orphan*/  TIMEVAL_TO_TIMESPEC (struct timeval*,struct timespec*) ; 
 scalar_t__ UTIME_NOW ; 
 scalar_t__ UTIME_OMIT ; 
 scalar_t__ __commpage_gettimeofday (struct timeval*) ; 
 int /*<<< orphan*/  __gettimeofday (struct timeval*,int /*<<< orphan*/ *) ; 
 int fsetattrlist (int,struct attrlist*,struct timespec**,size_t,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  memcpy (struct timespec**,struct timespec const*,int) ; 
 int setattrlistat (int,char const*,struct attrlist*,struct timespec**,size_t,int) ; 
 struct timespec const* times_now ; 

__attribute__((used)) static int
prepare_times_array_and_attrs(struct timespec times_in[2],
		struct timespec times_out[2], size_t *times_out_size)
{
	if (times_in[0].tv_nsec == UTIME_OMIT &&
			times_in[1].tv_nsec == UTIME_OMIT) {
		return 0;
	}

	if (times_in[0].tv_nsec == UTIME_NOW ||
			times_in[1].tv_nsec == UTIME_NOW) {
		struct timespec now = {};
		{
			/*
			 * TODO: Replace with nanosecond time when available
			 */
			struct timeval tv;
			if (__commpage_gettimeofday(&tv) != 0) {
				__gettimeofday(&tv, NULL);
			}
			TIMEVAL_TO_TIMESPEC(&tv, &now);
		}

		if (times_in[0].tv_nsec == UTIME_NOW) {
			times_in[0] = now;
		}
		if (times_in[1].tv_nsec == UTIME_NOW) {
			times_in[1] = now;
		}
	}

	int attrs = 0;
	*times_out_size = 0;
	struct timespec *times_cursor = times_out;
	if (times_in[1].tv_nsec != UTIME_OMIT) {
		attrs |= ATTR_CMN_MODTIME;
		*times_cursor++ = times_in[1];
		*times_out_size += sizeof(struct timespec);
	}
	if (times_in[0].tv_nsec != UTIME_OMIT) {
		attrs |= ATTR_CMN_ACCTIME;
		*times_cursor = times_in[0];
		*times_out_size += sizeof(struct timespec);
	}
	return attrs;
}

int
futimens(int fd, const struct timespec _times_in[2])
{
	struct timespec times_in[2];
	if (_times_in != NULL) {
		memcpy(&times_in, _times_in, sizeof(times_in));
	} else {
		memcpy(&times_in, times_now, sizeof(times_in));
	}

	size_t attrbuf_size = 0;
	struct timespec times_out[2] = {};
	struct attrlist a = {
		.bitmapcount = ATTR_BIT_MAP_COUNT
	};
	a.commonattr = prepare_times_array_and_attrs(times_in, times_out, &attrbuf_size);

	return fsetattrlist(fd, &a, &times_out, attrbuf_size, 0);
}

int
utimensat(int fd, const char *path, const struct timespec _times_in[2], int flags)
{
	struct timespec times_in[2];
	if (_times_in != NULL) {
		memcpy(&times_in, _times_in, sizeof(times_in));
	} else {
		memcpy(&times_in, times_now, sizeof(times_in));
	}

	size_t attrbuf_size = 0;
	struct timespec times_out[2] = {};
	struct attrlist a = {
		.bitmapcount = ATTR_BIT_MAP_COUNT
	};
	a.commonattr = prepare_times_array_and_attrs(times_in, times_out, &attrbuf_size);

	int flags_out = 0;
	if (flags & AT_SYMLINK_NOFOLLOW) {
		flags_out |= FSOPT_NOFOLLOW;
	}

	return setattrlistat(fd, path, &a, &times_out, attrbuf_size, flags_out);
}

