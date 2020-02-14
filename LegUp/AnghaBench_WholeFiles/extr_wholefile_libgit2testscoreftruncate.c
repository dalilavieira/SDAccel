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
struct stat {scalar_t__ st_size; } ;
typedef  scalar_t__ git_off_t ;

/* Variables and functions */
 int O_CREAT ; 
 int O_RDWR ; 
 int /*<<< orphan*/  cl_assert (int) ; 
 int /*<<< orphan*/  cl_is_env_set (char*) ; 
 int /*<<< orphan*/  cl_must_pass (scalar_t__) ; 
 int /*<<< orphan*/  cl_skip () ; 
 scalar_t__ fd ; 
 int /*<<< orphan*/  filename ; 
 int /*<<< orphan*/  p_close (scalar_t__) ; 
 int p_fstat (scalar_t__,struct stat*) ; 
 int p_ftruncate (scalar_t__,scalar_t__) ; 
 scalar_t__ p_open (int /*<<< orphan*/ ,int,int) ; 
 int /*<<< orphan*/  p_unlink (int /*<<< orphan*/ ) ; 

void test_core_ftruncate__initialize(void)
{
	if (!cl_is_env_set("GITTEST_INVASIVE_FS_SIZE"))
		cl_skip();

	cl_must_pass((fd = p_open(filename, O_CREAT | O_RDWR, 0644)));
}

void test_core_ftruncate__cleanup(void)
{
	if (fd < 0)
		return;

	p_close(fd);
	fd = 0;

	p_unlink(filename);
}

__attribute__((used)) static void _extend(git_off_t i64len)
{
	struct stat st;
	int error;

	cl_assert((error = p_ftruncate(fd, i64len)) == 0);
	cl_assert((error = p_fstat(fd, &st)) == 0);
	cl_assert(st.st_size == i64len);
}

void test_core_ftruncate__2gb(void)
{
	_extend(0x80000001);
}

void test_core_ftruncate__4gb(void)
{
	_extend(0x100000001);
}

