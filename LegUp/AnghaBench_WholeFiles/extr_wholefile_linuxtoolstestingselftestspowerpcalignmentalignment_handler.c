#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_6__   TYPE_3__ ;
typedef  struct TYPE_5__   TYPE_2__ ;
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
struct TYPE_5__ {TYPE_1__* uc_regs; } ;
struct TYPE_6__ {TYPE_2__ uc_mcontext; } ;
typedef  TYPE_3__ ucontext_t ;
struct sigaction {void (* sa_sigaction ) (int,int /*<<< orphan*/ *,void*) ;int /*<<< orphan*/  sa_flags; int /*<<< orphan*/  sa_mask; } ;
typedef  int /*<<< orphan*/  siginfo_t ;
struct TYPE_4__ {int* gregs; } ;

/* Variables and functions */
 int /*<<< orphan*/  LOAD_DFORM_TEST (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  LOAD_FLOAT_DFORM_TEST (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  LOAD_FLOAT_XFORM_TEST (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  LOAD_VMX_DFORM_TEST (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  LOAD_VMX_XFORM_TEST (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  LOAD_VSX_DFORM_TEST (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  LOAD_VSX_XFORM_TEST (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  LOAD_XFORM_TEST (int /*<<< orphan*/ ) ; 
 void* MAP_FAILED ; 
 int /*<<< orphan*/  MAP_SHARED ; 
 int /*<<< orphan*/  O_RDWR ; 
 int /*<<< orphan*/  PPC_FEATURE2_ARCH_2_07 ; 
 int /*<<< orphan*/  PPC_FEATURE2_ARCH_3_00 ; 
 int /*<<< orphan*/  PPC_FEATURE_ARCH_2_05 ; 
 int /*<<< orphan*/  PPC_FEATURE_ARCH_2_06 ; 
 int /*<<< orphan*/  PPC_FEATURE_HAS_ALTIVEC ; 
 int /*<<< orphan*/  PROT_WRITE ; 
 size_t PT_NIP ; 
 int /*<<< orphan*/  SA_SIGINFO ; 
 int /*<<< orphan*/  SIGBUS ; 
 int /*<<< orphan*/  SIGILL ; 
 int /*<<< orphan*/  SIGSEGV ; 
 int /*<<< orphan*/  SIG_DFL ; 
 int /*<<< orphan*/  SKIP_IF (int) ; 
 int /*<<< orphan*/  STORE_DFORM_TEST (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  STORE_FLOAT_DFORM_TEST (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  STORE_FLOAT_XFORM_TEST (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  STORE_VMX_DFORM_TEST (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  STORE_VMX_XFORM_TEST (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  STORE_VSX_DFORM_TEST (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  STORE_VSX_XFORM_TEST (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  STORE_XFORM_TEST (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  assert (int) ; 
 int bufsize ; 
 int /*<<< orphan*/  close (int) ; 
 scalar_t__ debug ; 
 int /*<<< orphan*/  exit (int) ; 
 int /*<<< orphan*/  free (void*) ; 
 int getopt (int,char**,char*) ; 
 int getpagesize () ; 
 int gotsig ; 
 int /*<<< orphan*/  have_hwcap (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  have_hwcap2 (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  kill (int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  lbz ; 
 int /*<<< orphan*/  lbzu ; 
 int /*<<< orphan*/  lbzux ; 
 int /*<<< orphan*/  lbzx ; 
 int /*<<< orphan*/  ld ; 
 int /*<<< orphan*/  ldbrx ; 
 int /*<<< orphan*/  ldu ; 
 int /*<<< orphan*/  ldux ; 
 int /*<<< orphan*/  ldx ; 
 int /*<<< orphan*/  lfd ; 
 int /*<<< orphan*/  lfdp ; 
 int /*<<< orphan*/  lfdpx ; 
 int /*<<< orphan*/  lfdu ; 
 int /*<<< orphan*/  lfdux ; 
 int /*<<< orphan*/  lfdx ; 
 int /*<<< orphan*/  lfiwax ; 
 int /*<<< orphan*/  lfiwzx ; 
 int /*<<< orphan*/  lfs ; 
 int /*<<< orphan*/  lfsu ; 
 int /*<<< orphan*/  lfsux ; 
 int /*<<< orphan*/  lfsx ; 
 int /*<<< orphan*/  lha ; 
 int /*<<< orphan*/  lhau ; 
 int /*<<< orphan*/  lhaux ; 
 int /*<<< orphan*/  lhax ; 
 int /*<<< orphan*/  lhbrx ; 
 int /*<<< orphan*/  lhz ; 
 int /*<<< orphan*/  lhzu ; 
 int /*<<< orphan*/  lhzux ; 
 int /*<<< orphan*/  lhzx ; 
 int /*<<< orphan*/  lmw ; 
 int /*<<< orphan*/  lvx ; 
 int /*<<< orphan*/  lwa ; 
 int /*<<< orphan*/  lwaux ; 
 int /*<<< orphan*/  lwax ; 
 int /*<<< orphan*/  lwbrx ; 
 int /*<<< orphan*/  lwz ; 
 int /*<<< orphan*/  lwzu ; 
 int /*<<< orphan*/  lwzux ; 
 int /*<<< orphan*/  lwzx ; 
 int /*<<< orphan*/  lxsd ; 
 int /*<<< orphan*/  lxsdx ; 
 int /*<<< orphan*/  lxsibzx ; 
 int /*<<< orphan*/  lxsihzx ; 
 int /*<<< orphan*/  lxsiwax ; 
 int /*<<< orphan*/  lxsiwzx ; 
 int /*<<< orphan*/  lxssp ; 
 int /*<<< orphan*/  lxsspx ; 
 int /*<<< orphan*/  lxv ; 
 int /*<<< orphan*/  lxvb16x ; 
 int /*<<< orphan*/  lxvd2x ; 
 int /*<<< orphan*/  lxvdsx ; 
 int /*<<< orphan*/  lxvh8x ; 
 int /*<<< orphan*/  lxvl ; 
 int /*<<< orphan*/  lxvll ; 
 int /*<<< orphan*/  lxvw4x ; 
 int /*<<< orphan*/  lxvwsx ; 
 int /*<<< orphan*/  lxvx ; 
 scalar_t__ memcmp (char*,char*,int) ; 
 int /*<<< orphan*/  memcpy (void*,void*,int) ; 
 void* mmap (int /*<<< orphan*/ *,int,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int,int) ; 
 int /*<<< orphan*/  munmap (void*,int) ; 
 int open (char*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  perror (char*) ; 
 int posix_memalign (void**,int,int) ; 
 int /*<<< orphan*/  printf (char*,...) ; 
 int sigaction (int /*<<< orphan*/ ,struct sigaction*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  sigemptyset (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  signal (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  stb ; 
 int /*<<< orphan*/  stbu ; 
 int /*<<< orphan*/  stbux ; 
 int /*<<< orphan*/  stbx ; 
 int /*<<< orphan*/  std ; 
 int /*<<< orphan*/  stdbrx ; 
 int /*<<< orphan*/  stdu ; 
 int /*<<< orphan*/  stdux ; 
 int /*<<< orphan*/  stdx ; 
 int /*<<< orphan*/  stfd ; 
 int /*<<< orphan*/  stfdp ; 
 int /*<<< orphan*/  stfdpx ; 
 int /*<<< orphan*/  stfdu ; 
 int /*<<< orphan*/  stfdux ; 
 int /*<<< orphan*/  stfdx ; 
 int /*<<< orphan*/  stfiwx ; 
 int /*<<< orphan*/  stfs ; 
 int /*<<< orphan*/  stfsu ; 
 int /*<<< orphan*/  stfsux ; 
 int /*<<< orphan*/  stfsx ; 
 int /*<<< orphan*/  sth ; 
 int /*<<< orphan*/  sthbrx ; 
 int /*<<< orphan*/  sthu ; 
 int /*<<< orphan*/  sthux ; 
 int /*<<< orphan*/  sthx ; 
 int /*<<< orphan*/  stmw ; 
 int /*<<< orphan*/  stvebx ; 
 int /*<<< orphan*/  stvehx ; 
 int /*<<< orphan*/  stvewx ; 
 int /*<<< orphan*/  stvx ; 
 int /*<<< orphan*/  stvxl ; 
 int /*<<< orphan*/  stw ; 
 int /*<<< orphan*/  stwbrx ; 
 int /*<<< orphan*/  stwu ; 
 int /*<<< orphan*/  stwux ; 
 int /*<<< orphan*/  stwx ; 
 int /*<<< orphan*/  stxsd ; 
 int /*<<< orphan*/  stxsdx ; 
 int /*<<< orphan*/  stxsibx ; 
 int /*<<< orphan*/  stxsihx ; 
 int /*<<< orphan*/  stxsiwx ; 
 int /*<<< orphan*/  stxssp ; 
 int /*<<< orphan*/  stxsspx ; 
 int /*<<< orphan*/  stxv ; 
 int /*<<< orphan*/  stxvb16x ; 
 int /*<<< orphan*/  stxvd2x ; 
 int /*<<< orphan*/  stxvh8x ; 
 int /*<<< orphan*/  stxvl ; 
 int /*<<< orphan*/  stxvll ; 
 int /*<<< orphan*/  stxvw4x ; 
 int /*<<< orphan*/  stxvx ; 
 int test_harness (int (*) (),char*) ; 
 int testing ; 

void sighandler(int sig, siginfo_t *info, void *ctx)
{
	ucontext_t *ucp = ctx;

	if (!testing) {
		signal(sig, SIG_DFL);
		kill(0, sig);
	}
	gotsig = sig;
#ifdef __powerpc64__
	ucp->uc_mcontext.gp_regs[PT_NIP] += 4;
#else
	ucp->uc_mcontext.uc_regs->gregs[PT_NIP] += 4;
#endif
}

void preload_data(void *dst, int offset, int width)
{
	char *c = dst;
	int i;

	c += offset;

	for (i = 0 ; i < width ; i++)
		c[i] = i;
}

int test_memcpy(void *dst, void *src, int size, int offset,
		void (*test_func)(char *, char *))
{
	char *s, *d;

	s = src;
	s += offset;
	d = dst;
	d += offset;

	assert(size == 16);
	gotsig = 0;
	testing = 1;

	test_func(s, d); /* run the actual test */

	testing = 0;
	if (gotsig) {
		if (debug)
			printf("  Got signal %i\n", gotsig);
		return 1;
	}
	return 0;
}

void dumpdata(char *s1, char *s2, int n, char *test_name)
{
	int i;

	printf("  %s: unexpected result:\n", test_name);
	printf("    mem:");
	for (i = 0; i < n; i++)
		printf(" %02x", s1[i]);
	printf("\n");
	printf("    ci: ");
	for (i = 0; i < n; i++)
		printf(" %02x", s2[i]);
	printf("\n");
}

int test_memcmp(void *s1, void *s2, int n, int offset, char *test_name)
{
	char *s1c, *s2c;

	s1c = s1;
	s1c += offset;
	s2c = s2;
	s2c += offset;

	if (memcmp(s1c, s2c, n)) {
		if (debug) {
			printf("\n  Compare failed. Offset:%i length:%i\n",
			       offset, n);
			dumpdata(s1c, s2c, n, test_name);
		}
		return 1;
	}
	return 0;
}

int do_test(char *test_name, void (*test_func)(char *, char *))
{
	int offset, width, fd, rc, r;
	void *mem0, *mem1, *ci0, *ci1;

	printf("\tDoing %s:\t", test_name);

	fd = open("/dev/fb0", O_RDWR);
	if (fd < 0) {
		printf("\n");
		perror("Can't open /dev/fb0 now?");
		return 1;
	}

	ci0 = mmap(NULL, bufsize, PROT_WRITE, MAP_SHARED,
		   fd, 0x0);
	ci1 = mmap(NULL, bufsize, PROT_WRITE, MAP_SHARED,
		   fd, bufsize);
	if ((ci0 == MAP_FAILED) || (ci1 == MAP_FAILED)) {
		printf("\n");
		perror("mmap failed");
		SKIP_IF(1);
	}

	rc = posix_memalign(&mem0, bufsize, bufsize);
	if (rc) {
		printf("\n");
		return rc;
	}

	rc = posix_memalign(&mem1, bufsize, bufsize);
	if (rc) {
		printf("\n");
		free(mem0);
		return rc;
	}

	rc = 0;
	/* offset = 0 no alignment fault, so skip */
	for (offset = 1; offset < 16; offset++) {
		width = 16; /* vsx == 16 bytes */
		r = 0;

		/* load pattern into memory byte by byte */
		preload_data(ci0, offset, width);
		preload_data(mem0, offset, width); // FIXME: remove??
		memcpy(ci0, mem0, bufsize);
		memcpy(ci1, mem1, bufsize); /* initialise output to the same */

		/* sanity check */
		test_memcmp(mem0, ci0, width, offset, test_name);

		r |= test_memcpy(ci1,  ci0,  width, offset, test_func);
		r |= test_memcpy(mem1, mem0, width, offset, test_func);
		if (r && !debug) {
			printf("FAILED: Got signal");
			rc = 1;
			break;
		}

		r |= test_memcmp(mem1, ci1, width, offset, test_name);
		if (r && !debug) {
			printf("FAILED: Wrong Data");
			rc = 1;
			break;
		}
	}

	if (rc == 0)
		printf("PASSED");

	printf("\n");

	munmap(ci0, bufsize);
	munmap(ci1, bufsize);
	free(mem0);
	free(mem1);
	close(fd);

	return rc;
}

__attribute__((used)) static bool can_open_fb0(void)
{
	int fd;

	fd = open("/dev/fb0", O_RDWR);
	if (fd < 0)
		return false;

	close(fd);
	return true;
}

int test_alignment_handler_vsx_206(void)
{
	int rc = 0;

	SKIP_IF(!can_open_fb0());
	SKIP_IF(!have_hwcap(PPC_FEATURE_ARCH_2_06));

	printf("VSX: 2.06B\n");
	LOAD_VSX_XFORM_TEST(lxvd2x);
	LOAD_VSX_XFORM_TEST(lxvw4x);
	LOAD_VSX_XFORM_TEST(lxsdx);
	LOAD_VSX_XFORM_TEST(lxvdsx);
	STORE_VSX_XFORM_TEST(stxvd2x);
	STORE_VSX_XFORM_TEST(stxvw4x);
	STORE_VSX_XFORM_TEST(stxsdx);
	return rc;
}

int test_alignment_handler_vsx_207(void)
{
	int rc = 0;

	SKIP_IF(!can_open_fb0());
	SKIP_IF(!have_hwcap2(PPC_FEATURE2_ARCH_2_07));

	printf("VSX: 2.07B\n");
	LOAD_VSX_XFORM_TEST(lxsspx);
	LOAD_VSX_XFORM_TEST(lxsiwax);
	LOAD_VSX_XFORM_TEST(lxsiwzx);
	STORE_VSX_XFORM_TEST(stxsspx);
	STORE_VSX_XFORM_TEST(stxsiwx);
	return rc;
}

int test_alignment_handler_vsx_300(void)
{
	int rc = 0;

	SKIP_IF(!can_open_fb0());

	SKIP_IF(!have_hwcap2(PPC_FEATURE2_ARCH_3_00));
	printf("VSX: 3.00B\n");
	LOAD_VMX_DFORM_TEST(lxsd);
	LOAD_VSX_XFORM_TEST(lxsibzx);
	LOAD_VSX_XFORM_TEST(lxsihzx);
	LOAD_VMX_DFORM_TEST(lxssp);
	LOAD_VSX_DFORM_TEST(lxv);
	LOAD_VSX_XFORM_TEST(lxvb16x);
	LOAD_VSX_XFORM_TEST(lxvh8x);
	LOAD_VSX_XFORM_TEST(lxvx);
	LOAD_VSX_XFORM_TEST(lxvwsx);
	LOAD_VSX_XFORM_TEST(lxvl);
	LOAD_VSX_XFORM_TEST(lxvll);
	STORE_VMX_DFORM_TEST(stxsd);
	STORE_VSX_XFORM_TEST(stxsibx);
	STORE_VSX_XFORM_TEST(stxsihx);
	STORE_VMX_DFORM_TEST(stxssp);
	STORE_VSX_DFORM_TEST(stxv);
	STORE_VSX_XFORM_TEST(stxvb16x);
	STORE_VSX_XFORM_TEST(stxvh8x);
	STORE_VSX_XFORM_TEST(stxvx);
	STORE_VSX_XFORM_TEST(stxvl);
	STORE_VSX_XFORM_TEST(stxvll);
	return rc;
}

int test_alignment_handler_integer(void)
{
	int rc = 0;

	SKIP_IF(!can_open_fb0());

	printf("Integer\n");
	LOAD_DFORM_TEST(lbz);
	LOAD_DFORM_TEST(lbzu);
	LOAD_XFORM_TEST(lbzx);
	LOAD_XFORM_TEST(lbzux);
	LOAD_DFORM_TEST(lhz);
	LOAD_DFORM_TEST(lhzu);
	LOAD_XFORM_TEST(lhzx);
	LOAD_XFORM_TEST(lhzux);
	LOAD_DFORM_TEST(lha);
	LOAD_DFORM_TEST(lhau);
	LOAD_XFORM_TEST(lhax);
	LOAD_XFORM_TEST(lhaux);
	LOAD_XFORM_TEST(lhbrx);
	LOAD_DFORM_TEST(lwz);
	LOAD_DFORM_TEST(lwzu);
	LOAD_XFORM_TEST(lwzx);
	LOAD_XFORM_TEST(lwzux);
	LOAD_DFORM_TEST(lwa);
	LOAD_XFORM_TEST(lwax);
	LOAD_XFORM_TEST(lwaux);
	LOAD_XFORM_TEST(lwbrx);
	LOAD_DFORM_TEST(ld);
	LOAD_DFORM_TEST(ldu);
	LOAD_XFORM_TEST(ldx);
	LOAD_XFORM_TEST(ldux);
	LOAD_DFORM_TEST(lmw);
	STORE_DFORM_TEST(stb);
	STORE_XFORM_TEST(stbx);
	STORE_DFORM_TEST(stbu);
	STORE_XFORM_TEST(stbux);
	STORE_DFORM_TEST(sth);
	STORE_XFORM_TEST(sthx);
	STORE_DFORM_TEST(sthu);
	STORE_XFORM_TEST(sthux);
	STORE_XFORM_TEST(sthbrx);
	STORE_DFORM_TEST(stw);
	STORE_XFORM_TEST(stwx);
	STORE_DFORM_TEST(stwu);
	STORE_XFORM_TEST(stwux);
	STORE_XFORM_TEST(stwbrx);
	STORE_DFORM_TEST(std);
	STORE_XFORM_TEST(stdx);
	STORE_DFORM_TEST(stdu);
	STORE_XFORM_TEST(stdux);
	STORE_DFORM_TEST(stmw);

	return rc;
}

int test_alignment_handler_integer_206(void)
{
	int rc = 0;

	SKIP_IF(!can_open_fb0());
	SKIP_IF(!have_hwcap(PPC_FEATURE_ARCH_2_06));

	printf("Integer: 2.06\n");

	LOAD_XFORM_TEST(ldbrx);
	STORE_XFORM_TEST(stdbrx);

	return rc;
}

int test_alignment_handler_vmx(void)
{
	int rc = 0;

	SKIP_IF(!can_open_fb0());
	SKIP_IF(!have_hwcap(PPC_FEATURE_HAS_ALTIVEC));

	printf("VMX\n");
	LOAD_VMX_XFORM_TEST(lvx);

	/*
	 * FIXME: These loads only load part of the register, so our
	 * testing method doesn't work. Also they don't take alignment
	 * faults, so it's kinda pointless anyway
	 *
	 LOAD_VMX_XFORM_TEST(lvebx)
	 LOAD_VMX_XFORM_TEST(lvehx)
	 LOAD_VMX_XFORM_TEST(lvewx)
	 LOAD_VMX_XFORM_TEST(lvxl)
	*/
	STORE_VMX_XFORM_TEST(stvx);
	STORE_VMX_XFORM_TEST(stvebx);
	STORE_VMX_XFORM_TEST(stvehx);
	STORE_VMX_XFORM_TEST(stvewx);
	STORE_VMX_XFORM_TEST(stvxl);
	return rc;
}

int test_alignment_handler_fp(void)
{
	int rc = 0;

	SKIP_IF(!can_open_fb0());

	printf("Floating point\n");
	LOAD_FLOAT_DFORM_TEST(lfd);
	LOAD_FLOAT_XFORM_TEST(lfdx);
	LOAD_FLOAT_DFORM_TEST(lfdu);
	LOAD_FLOAT_XFORM_TEST(lfdux);
	LOAD_FLOAT_DFORM_TEST(lfs);
	LOAD_FLOAT_XFORM_TEST(lfsx);
	LOAD_FLOAT_DFORM_TEST(lfsu);
	LOAD_FLOAT_XFORM_TEST(lfsux);
	STORE_FLOAT_DFORM_TEST(stfd);
	STORE_FLOAT_XFORM_TEST(stfdx);
	STORE_FLOAT_DFORM_TEST(stfdu);
	STORE_FLOAT_XFORM_TEST(stfdux);
	STORE_FLOAT_DFORM_TEST(stfs);
	STORE_FLOAT_XFORM_TEST(stfsx);
	STORE_FLOAT_DFORM_TEST(stfsu);
	STORE_FLOAT_XFORM_TEST(stfsux);
	STORE_FLOAT_XFORM_TEST(stfiwx);

	return rc;
}

int test_alignment_handler_fp_205(void)
{
	int rc = 0;

	SKIP_IF(!can_open_fb0());
	SKIP_IF(!have_hwcap(PPC_FEATURE_ARCH_2_05));

	printf("Floating point: 2.05\n");

	LOAD_FLOAT_DFORM_TEST(lfdp);
	LOAD_FLOAT_XFORM_TEST(lfdpx);
	LOAD_FLOAT_XFORM_TEST(lfiwax);
	STORE_FLOAT_DFORM_TEST(stfdp);
	STORE_FLOAT_XFORM_TEST(stfdpx);

	return rc;
}

int test_alignment_handler_fp_206(void)
{
	int rc = 0;

	SKIP_IF(!can_open_fb0());
	SKIP_IF(!have_hwcap(PPC_FEATURE_ARCH_2_06));

	printf("Floating point: 2.06\n");

	LOAD_FLOAT_XFORM_TEST(lfiwzx);

	return rc;
}

void usage(char *prog)
{
	printf("Usage: %s [options]\n", prog);
	printf("  -d	Enable debug error output\n");
	printf("\n");
	printf("This test requires a POWER8 or POWER9 CPU and a usable ");
	printf("framebuffer at /dev/fb0.\n");
}

int main(int argc, char *argv[])
{

	struct sigaction sa;
	int rc = 0;
	int option = 0;

	while ((option = getopt(argc, argv, "d")) != -1) {
		switch (option) {
		case 'd':
			debug++;
			break;
		default:
			usage(argv[0]);
			exit(1);
		}
	}

	bufsize = getpagesize();

	sa.sa_sigaction = sighandler;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_SIGINFO;
	if (sigaction(SIGSEGV, &sa, NULL) == -1
	    || sigaction(SIGBUS, &sa, NULL) == -1
	    || sigaction(SIGILL, &sa, NULL) == -1) {
		perror("sigaction");
		exit(1);
	}

	rc |= test_harness(test_alignment_handler_vsx_206,
			   "test_alignment_handler_vsx_206");
	rc |= test_harness(test_alignment_handler_vsx_207,
			   "test_alignment_handler_vsx_207");
	rc |= test_harness(test_alignment_handler_vsx_300,
			   "test_alignment_handler_vsx_300");
	rc |= test_harness(test_alignment_handler_integer,
			   "test_alignment_handler_integer");
	rc |= test_harness(test_alignment_handler_integer_206,
			   "test_alignment_handler_integer_206");
	rc |= test_harness(test_alignment_handler_vmx,
			   "test_alignment_handler_vmx");
	rc |= test_harness(test_alignment_handler_fp,
			   "test_alignment_handler_fp");
	rc |= test_harness(test_alignment_handler_fp_205,
			   "test_alignment_handler_fp_205");
	rc |= test_harness(test_alignment_handler_fp_206,
			   "test_alignment_handler_fp_206");
	return rc;
}

