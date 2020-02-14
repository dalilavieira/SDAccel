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
 long BUFLEN ; 
 unsigned long COPY_LOOP (char*,char*,unsigned long) ; 
 unsigned long MAX_LEN ; 
 unsigned long MAX_OFFSET ; 
 int MIN_REDZONE ; 
 int /*<<< orphan*/  POISON ; 
 int /*<<< orphan*/  abort () ; 
 int /*<<< orphan*/  exit (int) ; 
 int /*<<< orphan*/  fprintf (int /*<<< orphan*/ ,char*) ; 
 char* malloc (long) ; 
 char* memalign (long,long) ; 
 scalar_t__ memcmp (char*,void*,int) ; 
 int /*<<< orphan*/  memcpy (char*,void*,unsigned long) ; 
 int /*<<< orphan*/  memset (char*,int /*<<< orphan*/ ,long) ; 
 int /*<<< orphan*/  printf (char*,...) ; 
 int /*<<< orphan*/  stderr ; 
 int /*<<< orphan*/  str (unsigned long (*) (char*,char*,unsigned long)) ; 
 int test_harness (int (*) (),int /*<<< orphan*/ ) ; 

__attribute__((used)) static void do_one(char *src, char *dst, unsigned long src_off,
		   unsigned long dst_off, unsigned long len, void *redzone,
		   void *fill)
{
	char *srcp, *dstp;
	unsigned long ret;
	unsigned long i;

	srcp = src + MIN_REDZONE + src_off;
	dstp = dst + MIN_REDZONE + dst_off;

	memset(src, POISON, BUFLEN);
	memset(dst, POISON, BUFLEN);
	memcpy(srcp, fill, len);

	ret = COPY_LOOP(dstp, srcp, len);
	if (ret && ret != (unsigned long)dstp) {
		printf("(%p,%p,%ld) returned %ld\n", dstp, srcp, len, ret);
		abort();
	}

	if (memcmp(dstp, srcp, len)) {
		printf("(%p,%p,%ld) miscompare\n", dstp, srcp, len);
		printf("src: ");
		for (i = 0; i < len; i++)
			printf("%02x ", srcp[i]);
		printf("\ndst: ");
		for (i = 0; i < len; i++)
			printf("%02x ", dstp[i]);
		printf("\n");
		abort();
	}

	if (memcmp(dst, redzone, dstp - dst)) {
		printf("(%p,%p,%ld) redzone before corrupted\n",
		       dstp, srcp, len);
		abort();
	}

	if (memcmp(dstp+len, redzone, dst+BUFLEN-(dstp+len))) {
		printf("(%p,%p,%ld) redzone after corrupted\n",
		       dstp, srcp, len);
		abort();
	}
}

int test_copy_loop(void)
{
	char *src, *dst, *redzone, *fill;
	unsigned long len, src_off, dst_off;
	unsigned long i;

	src = memalign(BUFLEN, BUFLEN);
	dst = memalign(BUFLEN, BUFLEN);
	redzone = malloc(BUFLEN);
	fill = malloc(BUFLEN);

	if (!src || !dst || !redzone || !fill) {
		fprintf(stderr, "malloc failed\n");
		exit(1);
	}

	memset(redzone, POISON, BUFLEN);

	/* Fill with sequential bytes */
	for (i = 0; i < BUFLEN; i++)
		fill[i] = i & 0xff;

	for (len = 1; len < MAX_LEN; len++) {
		for (src_off = 0; src_off < MAX_OFFSET; src_off++) {
			for (dst_off = 0; dst_off < MAX_OFFSET; dst_off++) {
				do_one(src, dst, src_off, dst_off, len,
				       redzone, fill);
			}
		}
	}

	return 0;
}

int main(void)
{
	return test_harness(test_copy_loop, str(COPY_LOOP));
}

