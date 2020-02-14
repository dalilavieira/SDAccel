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
typedef  int /*<<< orphan*/  uint64_t ;
struct sigaction {void (* sa_handler ) (int) ;scalar_t__ sa_mask; int /*<<< orphan*/  sa_flags; } ;
typedef  int /*<<< orphan*/  pid_t ;
typedef  int mach_vm_size_t ;
typedef  int mach_vm_address_t ;
typedef  int boolean_t ;
struct TYPE_2__ {char* description; int (* fn ) () ;} ;

/* Variables and functions */
 int FALSE ; 
 char* FILENAME ; 
 int FIXED_ADDRESS1 ; 
 int FIXED_ADDRESS2 ; 
 int /*<<< orphan*/  F_NOCACHE ; 
 int MAP_ANON ; 
 scalar_t__ MAP_FAILED ; 
 int MAP_PRIVATE ; 
 int /*<<< orphan*/  O_RDONLY ; 
 int PAGE_SIZE ; 
 int /*<<< orphan*/  PROT_READ ; 
 int /*<<< orphan*/  SA_RESTART ; 
 int /*<<< orphan*/  SEEK_SET ; 
 int /*<<< orphan*/  SIGBUS ; 
 int /*<<< orphan*/  SIGSEGV ; 
 int /*<<< orphan*/  SUPERPAGE_MASK ; 
 int SUPERPAGE_SIZE ; 
 int TESTS ; 
 int TRUE ; 
 int VM_FLAGS_ANYWHERE ; 
 int VM_FLAGS_SUPERPAGE_SIZE_2MB ; 
 int VM_FLAGS_SUPERPAGE_SIZE_ANY ; 
 int VM_PROT_NONE ; 
 int VM_PROT_READ ; 
 int VM_PROT_WRITE ; 
 int atoi (char*) ; 
 int /*<<< orphan*/  close (int) ; 
 char* error ; 
 int /*<<< orphan*/  exit (int) ; 
 int /*<<< orphan*/  fcntl (int,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  fflush (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  fork () ; 
 int /*<<< orphan*/  geteuid () ; 
 int global_addr ; 
 int global_size ; 
 int /*<<< orphan*/  longjmp (int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  lseek (int,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mach_host_self () ; 
 int /*<<< orphan*/  mach_task_self () ; 
 int mach_vm_allocate (int /*<<< orphan*/ ,int*,int,int) ; 
 int mach_vm_deallocate (int /*<<< orphan*/ ,int,int) ; 
 int /*<<< orphan*/  mach_vm_protect (int /*<<< orphan*/ ,int,int,int /*<<< orphan*/ ,int) ; 
 int mach_vm_wire (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int,int,int) ; 
 scalar_t__ memcmp (void*,void*,unsigned int) ; 
 scalar_t__ mmap (void*,int,int /*<<< orphan*/ ,int,int,int /*<<< orphan*/ ) ; 
 int munmap (void*,int) ; 
 int open (char*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  printf (char*,...) ; 
 unsigned int read (int,void*,int) ; 
 int /*<<< orphan*/  resume ; 
 int setjmp (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  sigaction (int /*<<< orphan*/ ,struct sigaction*,int /*<<< orphan*/ *) ; 
 char** signame ; 
 int /*<<< orphan*/  sprintf (char*,char*,...) ; 
 int /*<<< orphan*/  stdout ; 
 int /*<<< orphan*/  strcmp (char*,char*) ; 
 int stub1 () ; 
 TYPE_1__* test ; 
 int /*<<< orphan*/  waitpid (int /*<<< orphan*/ ,int*,int /*<<< orphan*/ ) ; 

void test_signal_handler(int signo)
{       
	longjmp(resume, signo);
}

boolean_t
check_kr(int kr, char *fn) {
	if (kr) {
		sprintf(error, "%s() returned %d", fn, kr);
		return FALSE;
	}
	return TRUE;
}

boolean_t
check_addr0(mach_vm_address_t addr, char *fn) {
	if (!addr) {
		sprintf(error, "%s() returned address 0", fn);
		return FALSE;
	}
	return TRUE;
}

boolean_t
check_addr(mach_vm_address_t addr1, mach_vm_address_t addr2, char *fn) {
	if (addr1 != addr2) {
		sprintf(error, "%s() returned address %llx instead of %llx", fn, addr1, addr2);
		return FALSE;
	}
	return TRUE;
}

boolean_t
check_align(mach_vm_address_t addr) {
	if (addr & !SUPERPAGE_MASK) {
		sprintf(error, "address not aligned properly: 0x%llx", addr);
		return FALSE;
	}
	return TRUE;
}

boolean_t
check_r(mach_vm_address_t addr, mach_vm_size_t size, int *res) {
	volatile char *data = (char*)(uintptr_t)addr;
	int i, sig, test;
	
	if ((sig = setjmp(resume)) != 0) {
		sprintf(error, "%s when reading", signame[sig]);
		return FALSE;
	}
	test = 0;
	for (i=0; i<size; i++)
		test += (data)[i];

	if (res)
		*res = test;
	
	return TRUE;
}

boolean_t
check_nr(mach_vm_address_t addr, mach_vm_size_t size, int *res) {
	int i;
	boolean_t ret;
	for (i=0; i<size/PAGE_SIZE; i++) {
		if ((ret = check_r(addr+i*PAGE_SIZE, PAGE_SIZE, res))) {
			sprintf(error, "page still readable");
			return FALSE;
		}
	}
	return TRUE;
}

boolean_t
check_w(mach_vm_address_t addr, mach_vm_size_t size) {
	char *data = (char*)(uintptr_t)addr;
	int i, sig;

	if ((sig = setjmp(resume)) != 0) {
		sprintf(error, "%s when writing", signame[sig]);
		return FALSE;
	}

	for (i=0; i<size; i++)
		(data)[i] = i & 0xFF;

	return TRUE;
}

boolean_t
check_nw(mach_vm_address_t addr, mach_vm_size_t size) {
	int i;
	boolean_t ret;

	for (i=0; i<size/PAGE_SIZE; i++) {
		if ((ret = check_w(addr+i*PAGE_SIZE, PAGE_SIZE))) {
			sprintf(error, "page still writable");
			return FALSE;
		}
	}
	return TRUE;
}

boolean_t
check_rw(mach_vm_address_t addr, mach_vm_size_t size) {
	int ret;
	int res;
	if (!(ret = check_w(addr, size))) return ret;
	if (!(ret = check_r(addr, size, &res))) return ret;
	if ((size==SUPERPAGE_SIZE) && (res!=0xfff00000)) {
		sprintf(error, "checksum error");
		return FALSE;
	}

	return TRUE;
}

boolean_t
test_allocate() {
	int kr, ret;

	global_addr = 0;
	global_size = SUPERPAGE_SIZE;
	
	kr = mach_vm_allocate(mach_task_self(), &global_addr, global_size, VM_FLAGS_ANYWHERE | VM_FLAGS_SUPERPAGE_SIZE_2MB);
	if (!(ret = check_kr(kr, "mach_vm_allocate"))) return ret;
	if (!(ret = check_addr0(global_addr, "mach_vm_allocate"))) return ret;
	if (!(ret = check_align(global_addr))) return ret;
	if (!(ret = check_rw(global_addr, global_size))) return ret;

	return TRUE;
}

boolean_t
test_deallocate() {
	mach_vm_size_t	size = SUPERPAGE_SIZE;
	int kr, ret;

	if (!global_addr) {
		sprintf(error, "skipped deallocation");
		return FALSE;
	}
	kr = mach_vm_deallocate(mach_task_self(), global_addr, global_size);
	if (!(ret = check_kr(kr, "mach_vm_deallocate"))) return ret;
	if (!(ret = check_nr(global_addr, size, NULL))) return ret;
	return TRUE;
}

boolean_t
test_allocate_size_any() {
	int kr;
	int ret;
	mach_vm_address_t addr = 0;
	mach_vm_size_t	size = 2*PAGE_SIZE; /* will be rounded up to some superpage size */

	kr = mach_vm_allocate(mach_task_self(), &addr, size, VM_FLAGS_ANYWHERE | VM_FLAGS_SUPERPAGE_SIZE_ANY);
	if (!(ret = check_kr(kr, "mach_vm_allocate"))) return ret;
	if (!(ret = check_addr0(addr, "mach_vm_allocate"))) return ret;
	if (!(ret = check_rw(addr, size))) return ret;
	kr = mach_vm_deallocate(mach_task_self(), addr, size);
	if (!(ret = check_kr(kr, "mach_vm_deallocate"))) return ret;
	if (!(ret = check_nr(addr, size, NULL))) return ret;
	return TRUE;
}

boolean_t
test_allocatefixed() {
	int kr;
	int ret;
	mach_vm_address_t addr = FIXED_ADDRESS1;
	mach_vm_size_t	size = SUPERPAGE_SIZE;

	kr = mach_vm_allocate(mach_task_self(), &addr, size, VM_FLAGS_SUPERPAGE_SIZE_2MB);
	if (!(ret = check_kr(kr, "mach_vm_allocate"))) return ret;
	if (!(ret = check_addr(addr, FIXED_ADDRESS1, "mach_vm_allocate"))) return ret;
	if (!(ret = check_rw(addr, size))) return ret;
	kr = mach_vm_deallocate(mach_task_self(), addr, size);
	if (!(ret = check_kr(kr, "mach_vm_deallocate"))) return ret;
	if (!(ret = check_nr(addr, size, NULL))) return ret;
	return TRUE;
}

boolean_t
test_allocateunalignedfixed() {
	int kr;
	int ret;
	mach_vm_address_t addr = FIXED_ADDRESS2;
	mach_vm_size_t	size = SUPERPAGE_SIZE;
	
	kr = mach_vm_allocate(mach_task_self(), &addr, size, VM_FLAGS_SUPERPAGE_SIZE_2MB);
	/* is supposed to fail */
	if ((ret = check_kr(kr, "mach_vm_allocate"))) {
		sprintf(error, "mach_vm_allocate() should have failed");
		return FALSE;
	}
	return TRUE;
}

boolean_t
test_allocateoddsize() {
	int kr;
	int ret;
	mach_vm_address_t addr = FIXED_ADDRESS1;
	mach_vm_size_t	size = PAGE_SIZE; /* != 2 MB */

	kr = mach_vm_allocate(mach_task_self(), &addr, size, VM_FLAGS_SUPERPAGE_SIZE_2MB);
	/* is supposed to fail */
	if ((ret = check_kr(kr, "mach_vm_allocate"))) {
		sprintf(error, "mach_vm_allocate() should have failed");
		return FALSE;
	}
	return TRUE;
}

boolean_t
test_deallocatesubpage() {
	int kr;
	int ret;
	mach_vm_address_t addr = 0;
	mach_vm_size_t	size = SUPERPAGE_SIZE;
	
	kr = mach_vm_allocate(mach_task_self(), &addr, size, VM_FLAGS_ANYWHERE | VM_FLAGS_SUPERPAGE_SIZE_2MB);
	if (!(ret = check_kr(kr, "mach_vm_allocate"))) return ret;
	kr = mach_vm_deallocate(mach_task_self(), addr + PAGE_SIZE, size);
	if (!(ret = check_kr(kr, "mach_vm_deallocate"))) return ret;
	if (!(ret = check_nr(addr, size, NULL))) return ret;
	return TRUE;
}

boolean_t
test_reallocate() {
	mach_vm_address_t addr = 0, addr2;
	mach_vm_size_t	size = SUPERPAGE_SIZE;
	int kr, ret;
	int i;

	kr = mach_vm_allocate(mach_task_self(), &addr, size, VM_FLAGS_ANYWHERE | VM_FLAGS_SUPERPAGE_SIZE_2MB);
	if (!(ret = check_kr(kr, "mach_vm_allocate"))) return ret;

	/* attempt to allocate every sub-page of superpage */
	for (i=0; i<SUPERPAGE_SIZE/PAGE_SIZE; i++) {
		addr2 = addr + i*PAGE_SIZE;
		size = PAGE_SIZE;
		kr = mach_vm_allocate(mach_task_self(), &addr2, size, 0);
		if ((ret = check_kr(kr, "mach_vm_allocate"))) {
			sprintf(error, "could allocate already allocated space, page %d", i);
			mach_vm_deallocate(mach_task_self(), addr, size);
			return FALSE;
		}
	}
	kr = mach_vm_deallocate(mach_task_self(), addr, size);
	if (!(ret = check_kr(kr, "mach_vm_deallocate"))) return ret;
	return TRUE;
}

boolean_t
test_wire() {
	int kr;
	int ret;
	mach_vm_address_t addr = 0;
	mach_vm_size_t	size = SUPERPAGE_SIZE;

	kr = mach_vm_allocate(mach_task_self(), &addr, size, VM_FLAGS_ANYWHERE | VM_FLAGS_SUPERPAGE_SIZE_2MB);
	if (!(ret = check_kr(kr, "mach_vm_allocate"))) return ret;

	kr = mach_vm_wire(mach_host_self(), mach_task_self(), addr, size, VM_PROT_WRITE | VM_PROT_READ);

	if (!geteuid()) /* may fail as user */
		if (!(ret = check_kr(kr, "mach_vm_wire"))) return ret;

	if (!(ret = check_rw(addr, size))) return ret;

	kr = mach_vm_deallocate(mach_task_self(), addr, size);
	if (!(ret = check_kr(kr, "mach_vm_deallocate"))) return ret;

	return TRUE;
}

boolean_t
test_unwire() {
	int kr;
	int ret;
	mach_vm_address_t addr = 0;
	mach_vm_size_t	size = SUPERPAGE_SIZE;

	kr = mach_vm_allocate(mach_task_self(), &addr, size, VM_FLAGS_ANYWHERE | VM_FLAGS_SUPERPAGE_SIZE_2MB);
	if (!(ret = check_kr(kr, "mach_vm_allocate"))) return ret;

	kr = mach_vm_wire(mach_host_self(), mach_task_self(), addr, size, VM_PROT_NONE);
	if ((ret = check_kr(kr, "mach_vm_wire"))) {
		sprintf(error, "could unwire");
		return FALSE;
	}

	if (!(ret = check_rw(addr, size))) return ret;

	kr = mach_vm_deallocate(mach_task_self(), addr, size);
	if (!(ret = check_kr(kr, "mach_vm_deallocate"))) return ret;

	return TRUE;
}

boolean_t
test_readonly() {
	int kr;
	int ret;
	mach_vm_address_t addr = 0;
	mach_vm_size_t	size = SUPERPAGE_SIZE;

	kr = mach_vm_allocate(mach_task_self(), &addr, size, VM_FLAGS_ANYWHERE | VM_FLAGS_SUPERPAGE_SIZE_2MB);
	if (!(ret = check_kr(kr, "mach_vm_allocate"))) return ret;

	mach_vm_protect(mach_task_self(), addr, size, 0, VM_PROT_READ);
	if (!(ret = check_kr(kr, "mach_vm_protect"))) return ret;

	if (!(ret = check_r(addr, size, NULL))) return ret;
	if (!(ret = check_nw(addr, size))) return ret;

	kr = mach_vm_deallocate(mach_task_self(), addr, size);
	if (!(ret = check_kr(kr, "mach_vm_deallocate"))) return ret;

	return TRUE;
}

boolean_t
test_readonlysubpage() {
	int kr;
	int ret;
	mach_vm_address_t addr = 0;
	mach_vm_size_t	size = SUPERPAGE_SIZE;

	kr = mach_vm_allocate(mach_task_self(), &addr, size, VM_FLAGS_ANYWHERE | VM_FLAGS_SUPERPAGE_SIZE_2MB);
	if (!(ret = check_kr(kr, "mach_vm_allocate"))) return ret;

	mach_vm_protect(mach_task_self(), addr+PAGE_SIZE, PAGE_SIZE, 0, VM_PROT_READ);
	if (!(ret = check_kr(kr, "mach_vm_protect"))) return ret;

	if (!(ret = check_r(addr, size, NULL))) return ret;
	if (!(ret = check_nw(addr, size))) return ret;

	kr = mach_vm_deallocate(mach_task_self(), addr, size);
	if (!(ret = check_kr(kr, "mach_vm_deallocate"))) return ret;

	return TRUE;
}

boolean_t
test_fork() {
	mach_vm_address_t addr = 0;
	mach_vm_size_t	size = SUPERPAGE_SIZE;
	int kr, ret;
	pid_t pid;
	
	kr = mach_vm_allocate(mach_task_self(), &addr, size, VM_FLAGS_ANYWHERE | VM_FLAGS_SUPERPAGE_SIZE_2MB);
	if (!(ret = check_kr(kr, "mach_vm_allocate"))) return ret;

	fflush(stdout);
	if ((pid=fork())) { /* parent */
		if (!(ret = check_rw(addr, size))) return ret;
		waitpid(pid, &ret, 0);
		if (!ret) {
			sprintf(error, "child could access superpage");
			return ret;
		}
	} else { /* child */
		if (!(ret = check_nr(addr, size, NULL))) exit(ret);
		exit(TRUE);
	}
	
	kr = mach_vm_deallocate(mach_task_self(), addr, size);
	if (!(ret = check_kr(kr, "mach_vm_deallocate"))) return ret;
	return TRUE;
}

boolean_t
test_fileio() {
	mach_vm_address_t addr1 = 0;
	mach_vm_address_t addr2 = 0;
	mach_vm_size_t	size = SUPERPAGE_SIZE;
	int kr, ret;
	int fd;
	unsigned int bytes;
	
	/* allocate one superpage */
	kr = mach_vm_allocate(mach_task_self(), &addr1, size, VM_FLAGS_ANYWHERE | VM_FLAGS_SUPERPAGE_SIZE_2MB);
	if (!(ret = check_kr(kr, "mach_vm_allocate (1)"))) return ret;

	/* allocate base pages (superpage-sized) */
	kr = mach_vm_allocate(mach_task_self(), &addr2, size, VM_FLAGS_ANYWHERE);
	if (!(ret = check_kr(kr, "mach_vm_allocate (2)"))) return ret;

	if ((fd = open(FILENAME, O_RDONLY))<0) {
		sprintf(error, "couldn't open %s", FILENAME);
		return FALSE;
	}
	fcntl(fd, F_NOCACHE, 1);
	/* read kernel into superpage */
	if ((bytes = read(fd, (void*)(uintptr_t)addr1, SUPERPAGE_SIZE)) < SUPERPAGE_SIZE) {
		sprintf(error, "short read (1)");
		return FALSE;
	}
	lseek(fd, 0, SEEK_SET);
	/* read kernel into base pages */
	if ((bytes = read(fd, (void*)(uintptr_t)addr2, SUPERPAGE_SIZE)) < SUPERPAGE_SIZE) {
		sprintf(error, "short read (2)");
		return FALSE;
	}
	close(fd);
	
	/* compare */
	if (memcmp((void*)(uintptr_t)addr1, (void*)(uintptr_t)addr2, bytes)) {
		sprintf(error, "read data corrupt");
		return FALSE;
	}

	kr = mach_vm_deallocate(mach_task_self(), addr1, size);
	if (!(ret = check_kr(kr, "mach_vm_deallocate (1)"))) return ret;
	kr = mach_vm_deallocate(mach_task_self(), addr2, size);
	if (!(ret = check_kr(kr, "mach_vm_deallocate (2)"))) return ret;
	return TRUE;
}

boolean_t
test_mmap() {
	int kr, ret;
	uintptr_t addr = 0;
	int size = SUPERPAGE_SIZE;
	
	addr = (uintptr_t)mmap((void*)addr, size, PROT_READ, MAP_ANON | MAP_PRIVATE, VM_FLAGS_SUPERPAGE_SIZE_2MB, 0);
	if (addr == (uintptr_t)MAP_FAILED) {
		sprintf(error, "mmap()");
		return FALSE;
	}
	if (!(ret = check_addr0(addr, "mach_vm_allocate"))) return ret;
	if (!(ret = check_align(addr))) return ret;
	if (!(ret = check_r(addr, SUPERPAGE_SIZE, NULL))) return ret;
	if (!(ret = check_nw(addr, SUPERPAGE_SIZE))) return ret;
	kr = munmap((void*)addr, size);
	if (!(ret = check_kr(kr, "munmap"))) return ret;
	if (!(ret = check_nr(addr, size, NULL))) return ret;

	return TRUE;
}

boolean_t
test_alloc_dealloc() {
	mach_vm_address_t addr = 0;
	mach_vm_size_t	size = SUPERPAGE_SIZE;
	int kr, ret;
	
	kr = mach_vm_allocate(mach_task_self(), &addr, size, VM_FLAGS_ANYWHERE | VM_FLAGS_SUPERPAGE_SIZE_2MB);
	if (!(ret = check_kr(kr, "mach_vm_allocate"))) return ret;
	if (!(ret = check_addr0(addr, "mach_vm_allocate"))) return ret;
	if (!(ret = check_align(addr))) return ret;
	if (!(ret = check_rw(addr, size))) return ret;
	kr = mach_vm_deallocate(mach_task_self(), addr, size);
	if (!(ret = check_kr(kr, "mach_vm_deallocate"))) return ret;
	return TRUE;
}

boolean_t
testit(int i) {
	boolean_t ret;

	error[0] = 0;
	printf ("Test #%d \"%s\"...", i+1, test[i].description);
	ret = test[i].fn();
	if (ret)
		printf ("OK\n");
	else {
		printf ("FAILED!");
		if (error[0])
			printf (" (%s)\n", error);
		else
			printf ("\n");
	}
}

int main(int argc, char **argv) {
	int i;
	uint64_t time1, time2;

	int mode = 0;
	if (argc>1) {
		if (!strcmp(argv[1], "-h")) {
			printf("Usage: %s <mode>\n", argv[0]);
			printf("\tmode = 0:  test all cases\n");
			printf("\tmode = -1: allocate/deallocate until failure\n");
			printf("\tmode > 0:  run test <tmode>\n");
			exit(0);
		}
		mode=atoi(argv[1]);
	}
	
	/* install SIGBUS handler */
	struct sigaction my_sigaction;
	my_sigaction.sa_handler = test_signal_handler;
	my_sigaction.sa_flags = SA_RESTART;
	my_sigaction.sa_mask = 0;
	sigaction( SIGBUS, &my_sigaction, NULL );
	sigaction( SIGSEGV, &my_sigaction, NULL );
	
	if (mode>0)		/* one specific test */
		testit(mode-1);

	if (mode==0) {	/* test all cases */
		printf("Running %d tests:\n", TESTS);
		for (i=0; i<TESTS; i++) {
			testit(i);
		}
	}
	if (mode==-1) {	/* alloc/dealloc */
			boolean_t ret;
		do {
			ret = test_alloc_dealloc(TRUE);
			printf(".");
			fflush(stdout);
		} while (ret);
		if (error[0])
			printf (" (%s)\n", error);
	}
	return 0;
}

