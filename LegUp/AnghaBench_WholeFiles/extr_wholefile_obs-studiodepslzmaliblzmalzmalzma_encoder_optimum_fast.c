#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_15__   TYPE_7__ ;
typedef  struct TYPE_14__   TYPE_3__ ;
typedef  struct TYPE_13__   TYPE_2__ ;
typedef  struct TYPE_12__   TYPE_1__ ;

/* Type definitions */
typedef  scalar_t__ uint8_t ;
typedef  scalar_t__ uint32_t ;
typedef  int /*<<< orphan*/  probability ;
struct TYPE_12__ {scalar_t__ lc; scalar_t__ lp; scalar_t__ pb; } ;
typedef  TYPE_1__ lzma_options_lzma ;
struct TYPE_13__ {scalar_t__ nice_len; int read_ahead; } ;
typedef  TYPE_2__ lzma_mf ;
struct TYPE_14__ {scalar_t__ longest_match_length; scalar_t__ matches_count; scalar_t__ const** reps; TYPE_7__* matches; } ;
typedef  TYPE_3__ lzma_coder ;
struct TYPE_15__ {scalar_t__ dist; int len; } ;

/* Variables and functions */
 scalar_t__ LITERAL_CODER_SIZE ; 
 scalar_t__ LZMA_LCLP_MAX ; 
 scalar_t__ LZMA_PB_MAX ; 
 int /*<<< orphan*/  MATCH_LEN_MAX ; 
 scalar_t__ REP_DISTANCES ; 
 int UINT32_C (int) ; 
 scalar_t__ UINT32_MAX ; 
 int /*<<< orphan*/  assert (int) ; 
 int /*<<< orphan*/  bit_reset (int /*<<< orphan*/ ) ; 
 scalar_t__ change_pair (scalar_t__ const,scalar_t__ const) ; 
 scalar_t__ mf_avail (TYPE_2__*) ; 
 void* mf_find (TYPE_2__*,scalar_t__*,TYPE_7__*) ; 
 scalar_t__* mf_ptr (TYPE_2__*) ; 
 int /*<<< orphan*/  mf_skip (TYPE_2__*,scalar_t__) ; 
 scalar_t__ my_min (scalar_t__,int /*<<< orphan*/ ) ; 
 scalar_t__ not_equal_16 (scalar_t__ const*,scalar_t__ const* const) ; 

__attribute__((used)) static inline bool
is_lclppb_valid(const lzma_options_lzma *options)
{
	return options->lc <= LZMA_LCLP_MAX && options->lp <= LZMA_LCLP_MAX
			&& options->lc + options->lp <= LZMA_LCLP_MAX
			&& options->pb <= LZMA_PB_MAX;
}

__attribute__((used)) static inline void
literal_init(probability (*probs)[LITERAL_CODER_SIZE],
		uint32_t lc, uint32_t lp)
{
	assert(lc + lp <= LZMA_LCLP_MAX);

	const uint32_t coders = 1U << (lc + lp);

	for (uint32_t i = 0; i < coders; ++i)
		for (uint32_t j = 0; j < LITERAL_CODER_SIZE; ++j)
			bit_reset(probs[i][j]);

	return;
}

extern void
lzma_lzma_optimum_fast(lzma_coder *restrict coder, lzma_mf *restrict mf,
		uint32_t *restrict back_res, uint32_t *restrict len_res)
{
	const uint32_t nice_len = mf->nice_len;

	uint32_t len_main;
	uint32_t matches_count;
	if (mf->read_ahead == 0) {
		len_main = mf_find(mf, &matches_count, coder->matches);
	} else {
		assert(mf->read_ahead == 1);
		len_main = coder->longest_match_length;
		matches_count = coder->matches_count;
	}

	const uint8_t *buf = mf_ptr(mf) - 1;
	const uint32_t buf_avail = my_min(mf_avail(mf) + 1, MATCH_LEN_MAX);

	if (buf_avail < 2) {
		// There's not enough input left to encode a match.
		*back_res = UINT32_MAX;
		*len_res = 1;
		return;
	}

	// Look for repeated matches; scan the previous four match distances
	uint32_t rep_len = 0;
	uint32_t rep_index = 0;

	for (uint32_t i = 0; i < REP_DISTANCES; ++i) {
		// Pointer to the beginning of the match candidate
		const uint8_t *const buf_back = buf - coder->reps[i] - 1;

		// If the first two bytes (2 == MATCH_LEN_MIN) do not match,
		// this rep is not useful.
		if (not_equal_16(buf, buf_back))
			continue;

		// The first two bytes matched.
		// Calculate the length of the match.
		uint32_t len;
		for (len = 2; len < buf_avail
				&& buf[len] == buf_back[len]; ++len) ;

		// If we have found a repeated match that is at least
		// nice_len long, return it immediately.
		if (len >= nice_len) {
			*back_res = i;
			*len_res = len;
			mf_skip(mf, len - 1);
			return;
		}

		if (len > rep_len) {
			rep_index = i;
			rep_len = len;
		}
	}

	// We didn't find a long enough repeated match. Encode it as a normal
	// match if the match length is at least nice_len.
	if (len_main >= nice_len) {
		*back_res = coder->matches[matches_count - 1].dist
				+ REP_DISTANCES;
		*len_res = len_main;
		mf_skip(mf, len_main - 1);
		return;
	}

	uint32_t back_main = 0;
	if (len_main >= 2) {
		back_main = coder->matches[matches_count - 1].dist;

		while (matches_count > 1 && len_main ==
				coder->matches[matches_count - 2].len + 1) {
			if (!change_pair(coder->matches[
						matches_count - 2].dist,
					back_main))
				break;

			--matches_count;
			len_main = coder->matches[matches_count - 1].len;
			back_main = coder->matches[matches_count - 1].dist;
		}

		if (len_main == 2 && back_main >= 0x80)
			len_main = 1;
	}

	if (rep_len >= 2) {
		if (rep_len + 1 >= len_main
				|| (rep_len + 2 >= len_main
					&& back_main > (UINT32_C(1) << 9))
				|| (rep_len + 3 >= len_main
					&& back_main > (UINT32_C(1) << 15))) {
			*back_res = rep_index;
			*len_res = rep_len;
			mf_skip(mf, rep_len - 1);
			return;
		}
	}

	if (len_main < 2 || buf_avail <= 2) {
		*back_res = UINT32_MAX;
		*len_res = 1;
		return;
	}

	// Get the matches for the next byte. If we find a better match,
	// the current byte is encoded as a literal.
	coder->longest_match_length = mf_find(mf,
			&coder->matches_count, coder->matches);

	if (coder->longest_match_length >= 2) {
		const uint32_t new_dist = coder->matches[
				coder->matches_count - 1].dist;

		if ((coder->longest_match_length >= len_main
					&& new_dist < back_main)
				|| (coder->longest_match_length == len_main + 1
					&& !change_pair(back_main, new_dist))
				|| (coder->longest_match_length > len_main + 1)
				|| (coder->longest_match_length + 1 >= len_main
					&& len_main >= 3
					&& change_pair(new_dist, back_main))) {
			*back_res = UINT32_MAX;
			*len_res = 1;
			return;
		}
	}

	// In contrast to LZMA SDK, dictionary could not have been moved
	// between mf_find() calls, thus it is safe to just increment
	// the old buf pointer instead of recalculating it with mf_ptr().
	++buf;

	const uint32_t limit = len_main - 1;

	for (uint32_t i = 0; i < REP_DISTANCES; ++i) {
		const uint8_t *const buf_back = buf - coder->reps[i] - 1;

		if (not_equal_16(buf, buf_back))
			continue;

		uint32_t len;
		for (len = 2; len < limit
				&& buf[len] == buf_back[len]; ++len) ;

		if (len >= limit) {
			*back_res = UINT32_MAX;
			*len_res = 1;
			return;
		}
	}

	*back_res = back_main + REP_DISTANCES;
	*len_res = len_main;
	mf_skip(mf, len_main - 2);
	return;
}

