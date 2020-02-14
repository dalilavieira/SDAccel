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
typedef  int* uuid_t ;
typedef  char* uuid_string_t ;
typedef  int uint8_t ;
typedef  unsigned long long uint64_t ;
struct timespec {unsigned long long tv_sec; unsigned long long tv_nsec; } ;

/* Variables and functions */
 int* const UUID_NULL ; 
 int memcmp (int* const,int* const,int) ; 
 int /*<<< orphan*/  memcpy (int*,int* const,int) ; 
 int /*<<< orphan*/  memset (int*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  nanotime (struct timespec*) ; 
 int /*<<< orphan*/  read_frandom (int*,int) ; 
 int /*<<< orphan*/  read_random (int*,int) ; 
 int /*<<< orphan*/  snprintf (char*,int,char*,int,int,int,int,int,int,int,int,int,int,int,int,int,int,int,int) ; 
 int /*<<< orphan*/  sscanf (char* const,char*,int*,int*,int*,int*,int*,int*,int*,int*,int*,int*,int*,int*,int*,int*,int*,int*,int*) ; 

__attribute__((used)) static void
read_node(uint8_t *node)
{
#if NETWORKING
	if (uuid_get_ethernet(node) == 0)
		return;
#endif /* NETWORKING */

	read_random(node, 6);
	node[0] |= 0x01;
}

__attribute__((used)) static uint64_t
read_time(void)
{
	struct timespec tv;

	nanotime(&tv);

	return (tv.tv_sec * 10000000ULL) + (tv.tv_nsec / 100ULL) + 0x01B21DD213814000ULL;
}

void
uuid_clear(uuid_t uu)
{
	memset(uu, 0, sizeof(uuid_t));
}

int
uuid_compare(const uuid_t uu1, const uuid_t uu2)
{
	return memcmp(uu1, uu2, sizeof(uuid_t));
}

void
uuid_copy(uuid_t dst, const uuid_t src)
{
	memcpy(dst, src, sizeof(uuid_t));
}

__attribute__((used)) static void
uuid_random_setflags(uuid_t out)
{
	out[6] = (out[6] & 0x0F) | 0x40;
	out[8] = (out[8] & 0x3F) | 0x80;
}

void
uuid_generate_random(uuid_t out)
{
	read_random(out, sizeof(uuid_t));
	uuid_random_setflags(out);
}

void
uuid_generate_early_random(uuid_t out)
{
	read_frandom(out, sizeof(uuid_t));
	uuid_random_setflags(out);
}

void
uuid_generate_time(uuid_t out)
{
	uint64_t time;

	read_node(&out[10]);
	read_random(&out[8], 2);

	time = read_time();
	out[0] = (uint8_t)(time >> 24);
	out[1] = (uint8_t)(time >> 16);
	out[2] = (uint8_t)(time >> 8);
	out[3] = (uint8_t)time;
	out[4] = (uint8_t)(time >> 40);
	out[5] = (uint8_t)(time >> 32);
	out[6] = (uint8_t)(time >> 56);
	out[7] = (uint8_t)(time >> 48);
 
	out[6] = (out[6] & 0x0F) | 0x10;
	out[8] = (out[8] & 0x3F) | 0x80;
}

void
uuid_generate(uuid_t out)
{
	uuid_generate_random(out);
}

int
uuid_is_null(const uuid_t uu)
{
	return !memcmp(uu, UUID_NULL, sizeof(uuid_t));
}

int
uuid_parse(const uuid_string_t in, uuid_t uu)
{
	int n = 0;

	sscanf(in,
		"%2hhx%2hhx%2hhx%2hhx-"
		"%2hhx%2hhx-"
		"%2hhx%2hhx-"
		"%2hhx%2hhx-"
		"%2hhx%2hhx%2hhx%2hhx%2hhx%2hhx%n",
		&uu[0], &uu[1], &uu[2], &uu[3],
		&uu[4], &uu[5],
		&uu[6], &uu[7],
		&uu[8], &uu[9],
		&uu[10], &uu[11], &uu[12], &uu[13], &uu[14], &uu[15], &n);

	return (n != 36 || in[n] != '\0' ? -1 : 0);
}

void
uuid_unparse_lower(const uuid_t uu, uuid_string_t out)
{
	snprintf(out,
		sizeof(uuid_string_t),
		"%02x%02x%02x%02x-"
		"%02x%02x-"
		"%02x%02x-"
		"%02x%02x-"
		"%02x%02x%02x%02x%02x%02x",
		uu[0], uu[1], uu[2], uu[3],
		uu[4], uu[5],
		uu[6], uu[7],
		uu[8], uu[9],
		uu[10], uu[11], uu[12], uu[13], uu[14], uu[15]);
}

void
uuid_unparse_upper(const uuid_t uu, uuid_string_t out)
{
	snprintf(out,
		sizeof(uuid_string_t),
		"%02X%02X%02X%02X-"
		"%02X%02X-"
		"%02X%02X-"
		"%02X%02X-"
		"%02X%02X%02X%02X%02X%02X",
		uu[0], uu[1], uu[2], uu[3],
		uu[4], uu[5],
		uu[6], uu[7],
		uu[8], uu[9],
		uu[10], uu[11], uu[12], uu[13], uu[14], uu[15]);
}

void
uuid_unparse(const uuid_t uu, uuid_string_t out)
{
	uuid_unparse_upper(uu, out);
}

