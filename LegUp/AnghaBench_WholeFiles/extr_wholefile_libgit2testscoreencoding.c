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
 int /*<<< orphan*/  cl_assert (int) ; 
 unsigned long long git_decode_varint (unsigned char const*,size_t*) ; 
 int git_encode_varint (unsigned char*,int,unsigned long long) ; 
 int /*<<< orphan*/  memcmp (unsigned char*,char*,int) ; 

void test_core_encoding__decode(void)
{
	const unsigned char *buf = (unsigned char *)"AB";
	size_t size;

	cl_assert(git_decode_varint(buf, &size) == 65);
	cl_assert(size == 1);

	buf = (unsigned char *)"\xfe\xdc\xbaXY";
	cl_assert(git_decode_varint(buf, &size) == 267869656);
	cl_assert(size == 4);

	buf = (unsigned char *)"\xaa\xaa\xfe\xdc\xbaXY";
	cl_assert(git_decode_varint(buf, &size) == 1489279344088ULL);
	cl_assert(size == 6);

	buf = (unsigned char *)"\xaa\xaa\xaa\xaa\xaa\xaa\xaa\xfe\xdc\xbaXY";
	cl_assert(git_decode_varint(buf, &size) == 0);
	cl_assert(size == 0);

}

void test_core_encoding__encode(void)
{
	unsigned char buf[100];
	cl_assert(git_encode_varint(buf, 100, 65) == 1);
	cl_assert(buf[0] == 'A');

	cl_assert(git_encode_varint(buf, 1, 1) == 1);
	cl_assert(!memcmp(buf, "\x01", 1));

	cl_assert(git_encode_varint(buf, 100, 267869656) == 4);
	cl_assert(!memcmp(buf, "\xfe\xdc\xbaX", 4));

	cl_assert(git_encode_varint(buf, 100, 1489279344088ULL) == 6);
	cl_assert(!memcmp(buf, "\xaa\xaa\xfe\xdc\xbaX", 6));

	cl_assert(git_encode_varint(buf, 1, 1489279344088ULL) == -1);
}

