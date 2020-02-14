#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_12__   TYPE_4__ ;
typedef  struct TYPE_11__   TYPE_3__ ;
typedef  struct TYPE_10__   TYPE_2__ ;
typedef  struct TYPE_9__   TYPE_1__ ;

/* Type definitions */
typedef  int uint8_t ;
typedef  int uint32_t ;
typedef  int /*<<< orphan*/  s ;
struct TYPE_10__ {int* state; int size; } ;
struct TYPE_11__ {TYPE_2__ sha256; } ;
struct TYPE_9__ {int* u8; int /*<<< orphan*/ * u32; int /*<<< orphan*/ * u64; } ;
struct TYPE_12__ {TYPE_3__ state; TYPE_1__ buffer; } ;
typedef  TYPE_4__ lzma_check_state ;
typedef  int /*<<< orphan*/  T ;

/* Variables and functions */
 int /*<<< orphan*/  R (int) ; 
 scalar_t__ a (int /*<<< orphan*/ ) ; 
 scalar_t__ b (int /*<<< orphan*/ ) ; 
 int bswap32 (int /*<<< orphan*/ ) ; 
 scalar_t__ c (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  conv32be (int) ; 
 int /*<<< orphan*/  conv64be (int) ; 
 scalar_t__ d (int /*<<< orphan*/ ) ; 
 scalar_t__ e (int /*<<< orphan*/ ) ; 
 scalar_t__ f (int /*<<< orphan*/ ) ; 
 scalar_t__ g (int /*<<< orphan*/ ) ; 
 scalar_t__ h (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  memcpy (int*,int const*,size_t) ; 

__attribute__((used)) static void
transform(uint32_t state[8], const uint32_t data[16])
{
	uint32_t W[16];
	uint32_t T[8];

	// Copy state[] to working vars.
	memcpy(T, state, sizeof(T));

	// 64 operations, partially loop unrolled
	for (unsigned int j = 0; j < 64; j += 16) {
		R( 0); R( 1); R( 2); R( 3);
		R( 4); R( 5); R( 6); R( 7);
		R( 8); R( 9); R(10); R(11);
		R(12); R(13); R(14); R(15);
	}

	// Add the working vars back into state[].
	state[0] += a(0);
	state[1] += b(0);
	state[2] += c(0);
	state[3] += d(0);
	state[4] += e(0);
	state[5] += f(0);
	state[6] += g(0);
	state[7] += h(0);
}

__attribute__((used)) static void
process(lzma_check_state *check)
{
#ifdef WORDS_BIGENDIAN
	transform(check->state.sha256.state, check->buffer.u32);

#else
	uint32_t data[16];

	for (size_t i = 0; i < 16; ++i)
		data[i] = bswap32(check->buffer.u32[i]);

	transform(check->state.sha256.state, data);
#endif

	return;
}

extern void
lzma_sha256_init(lzma_check_state *check)
{
	static const uint32_t s[8] = {
		0x6A09E667, 0xBB67AE85, 0x3C6EF372, 0xA54FF53A,
		0x510E527F, 0x9B05688C, 0x1F83D9AB, 0x5BE0CD19,
	};

	memcpy(check->state.sha256.state, s, sizeof(s));
	check->state.sha256.size = 0;

	return;
}

extern void
lzma_sha256_update(const uint8_t *buf, size_t size, lzma_check_state *check)
{
	// Copy the input data into a properly aligned temporary buffer.
	// This way we can be called with arbitrarily sized buffers
	// (no need to be multiple of 64 bytes), and the code works also
	// on architectures that don't allow unaligned memory access.
	while (size > 0) {
		const size_t copy_start = check->state.sha256.size & 0x3F;
		size_t copy_size = 64 - copy_start;
		if (copy_size > size)
			copy_size = size;

		memcpy(check->buffer.u8 + copy_start, buf, copy_size);

		buf += copy_size;
		size -= copy_size;
		check->state.sha256.size += copy_size;

		if ((check->state.sha256.size & 0x3F) == 0)
			process(check);
	}

	return;
}

extern void
lzma_sha256_finish(lzma_check_state *check)
{
	// Add padding as described in RFC 3174 (it describes SHA-1 but
	// the same padding style is used for SHA-256 too).
	size_t pos = check->state.sha256.size & 0x3F;
	check->buffer.u8[pos++] = 0x80;

	while (pos != 64 - 8) {
		if (pos == 64) {
			process(check);
			pos = 0;
		}

		check->buffer.u8[pos++] = 0x00;
	}

	// Convert the message size from bytes to bits.
	check->state.sha256.size *= 8;

	check->buffer.u64[(64 - 8) / 8] = conv64be(check->state.sha256.size);

	process(check);

	for (size_t i = 0; i < 8; ++i)
		check->buffer.u32[i] = conv32be(check->state.sha256.state[i]);

	return;
}

