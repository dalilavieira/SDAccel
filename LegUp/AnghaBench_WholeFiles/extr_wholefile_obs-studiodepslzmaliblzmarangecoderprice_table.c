#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_11__   TYPE_1__ ;

/* Type definitions */
typedef  scalar_t__ uint8_t ;
typedef  scalar_t__ uint64_t ;
typedef  int uint32_t ;
typedef  int probability ;
struct TYPE_11__ {int low; int cache_size; int range; int cache; size_t count; scalar_t__ pos; int* symbols; int** probs; } ;
typedef  TYPE_1__ lzma_range_encoder ;

/* Variables and functions */
#define  RC_BIT_0 132 
#define  RC_BIT_1 131 
 int RC_BIT_MODEL_TOTAL ; 
 int RC_BIT_MODEL_TOTAL_BITS ; 
 int const RC_BIT_PRICE_SHIFT_BITS ; 
#define  RC_DIRECT_0 130 
#define  RC_DIRECT_1 129 
#define  RC_FLUSH 128 
 int RC_MOVE_BITS ; 
 int const RC_MOVE_REDUCING_BITS ; 
 int RC_SHIFT_BITS ; 
 scalar_t__ RC_SYMBOLS_MAX ; 
 int RC_TOP_VALUE ; 
 int const UINT32_C (int) ; 
 void* UINT32_MAX ; 
 int /*<<< orphan*/  assert (int) ; 
 int* lzma_rc_prices ; 

__attribute__((used)) static inline uint32_t
rc_bit_price(const probability prob, const uint32_t bit)
{
	return lzma_rc_prices[(prob ^ ((UINT32_C(0) - bit)
			& (RC_BIT_MODEL_TOTAL - 1))) >> RC_MOVE_REDUCING_BITS];
}

__attribute__((used)) static inline uint32_t
rc_bit_0_price(const probability prob)
{
	return lzma_rc_prices[prob >> RC_MOVE_REDUCING_BITS];
}

__attribute__((used)) static inline uint32_t
rc_bit_1_price(const probability prob)
{
	return lzma_rc_prices[(prob ^ (RC_BIT_MODEL_TOTAL - 1))
			>> RC_MOVE_REDUCING_BITS];
}

__attribute__((used)) static inline uint32_t
rc_bittree_price(const probability *const probs,
		const uint32_t bit_levels, uint32_t symbol)
{
	uint32_t price = 0;
	symbol += UINT32_C(1) << bit_levels;

	do {
		const uint32_t bit = symbol & 1;
		symbol >>= 1;
		price += rc_bit_price(probs[symbol], bit);
	} while (symbol != 1);

	return price;
}

__attribute__((used)) static inline uint32_t
rc_bittree_reverse_price(const probability *const probs,
		uint32_t bit_levels, uint32_t symbol)
{
	uint32_t price = 0;
	uint32_t model_index = 1;

	do {
		const uint32_t bit = symbol & 1;
		symbol >>= 1;
		price += rc_bit_price(probs[model_index], bit);
		model_index = (model_index << 1) + bit;
	} while (--bit_levels != 0);

	return price;
}

__attribute__((used)) static inline uint32_t
rc_direct_price(const uint32_t bits)
{
	 return bits << RC_BIT_PRICE_SHIFT_BITS;
}

__attribute__((used)) static inline void
rc_reset(lzma_range_encoder *rc)
{
	rc->low = 0;
	rc->cache_size = 1;
	rc->range = UINT32_MAX;
	rc->cache = 0;
	rc->count = 0;
	rc->pos = 0;
}

__attribute__((used)) static inline void
rc_bit(lzma_range_encoder *rc, probability *prob, uint32_t bit)
{
	rc->symbols[rc->count] = bit;
	rc->probs[rc->count] = prob;
	++rc->count;
}

__attribute__((used)) static inline void
rc_bittree(lzma_range_encoder *rc, probability *probs,
		uint32_t bit_count, uint32_t symbol)
{
	uint32_t model_index = 1;

	do {
		const uint32_t bit = (symbol >> --bit_count) & 1;
		rc_bit(rc, &probs[model_index], bit);
		model_index = (model_index << 1) + bit;
	} while (bit_count != 0);
}

__attribute__((used)) static inline void
rc_bittree_reverse(lzma_range_encoder *rc, probability *probs,
		uint32_t bit_count, uint32_t symbol)
{
	uint32_t model_index = 1;

	do {
		const uint32_t bit = symbol & 1;
		symbol >>= 1;
		rc_bit(rc, &probs[model_index], bit);
		model_index = (model_index << 1) + bit;
	} while (--bit_count != 0);
}

__attribute__((used)) static inline void
rc_direct(lzma_range_encoder *rc,
		uint32_t value, uint32_t bit_count)
{
	do {
		rc->symbols[rc->count++]
				= RC_DIRECT_0 + ((value >> --bit_count) & 1);
	} while (bit_count != 0);
}

__attribute__((used)) static inline void
rc_flush(lzma_range_encoder *rc)
{
	for (size_t i = 0; i < 5; ++i)
		rc->symbols[rc->count++] = RC_FLUSH;
}

__attribute__((used)) static inline bool
rc_shift_low(lzma_range_encoder *rc,
		uint8_t *out, size_t *out_pos, size_t out_size)
{
	if ((uint32_t)(rc->low) < (uint32_t)(0xFF000000)
			|| (uint32_t)(rc->low >> 32) != 0) {
		do {
			if (*out_pos == out_size)
				return true;

			out[*out_pos] = rc->cache + (uint8_t)(rc->low >> 32);
			++*out_pos;
			rc->cache = 0xFF;

		} while (--rc->cache_size != 0);

		rc->cache = (rc->low >> 24) & 0xFF;
	}

	++rc->cache_size;
	rc->low = (rc->low & 0x00FFFFFF) << RC_SHIFT_BITS;

	return false;
}

__attribute__((used)) static inline bool
rc_encode(lzma_range_encoder *rc,
		uint8_t *out, size_t *out_pos, size_t out_size)
{
	assert(rc->count <= RC_SYMBOLS_MAX);

	while (rc->pos < rc->count) {
		// Normalize
		if (rc->range < RC_TOP_VALUE) {
			if (rc_shift_low(rc, out, out_pos, out_size))
				return true;

			rc->range <<= RC_SHIFT_BITS;
		}

		// Encode a bit
		switch (rc->symbols[rc->pos]) {
		case RC_BIT_0: {
			probability prob = *rc->probs[rc->pos];
			rc->range = (rc->range >> RC_BIT_MODEL_TOTAL_BITS)
					* prob;
			prob += (RC_BIT_MODEL_TOTAL - prob) >> RC_MOVE_BITS;
			*rc->probs[rc->pos] = prob;
			break;
		}

		case RC_BIT_1: {
			probability prob = *rc->probs[rc->pos];
			const uint32_t bound = prob * (rc->range
					>> RC_BIT_MODEL_TOTAL_BITS);
			rc->low += bound;
			rc->range -= bound;
			prob -= prob >> RC_MOVE_BITS;
			*rc->probs[rc->pos] = prob;
			break;
		}

		case RC_DIRECT_0:
			rc->range >>= 1;
			break;

		case RC_DIRECT_1:
			rc->range >>= 1;
			rc->low += rc->range;
			break;

		case RC_FLUSH:
			// Prevent further normalizations.
			rc->range = UINT32_MAX;

			// Flush the last five bytes (see rc_flush()).
			do {
				if (rc_shift_low(rc, out, out_pos, out_size))
					return true;
			} while (++rc->pos < rc->count);

			// Reset the range encoder so we are ready to continue
			// encoding if we weren't finishing the stream.
			rc_reset(rc);
			return false;

		default:
			assert(0);
			break;
		}

		++rc->pos;
	}

	rc->count = 0;
	rc->pos = 0;

	return false;
}

__attribute__((used)) static inline uint64_t
rc_pending(const lzma_range_encoder *rc)
{
	return rc->cache_size + 5 - 1;
}

