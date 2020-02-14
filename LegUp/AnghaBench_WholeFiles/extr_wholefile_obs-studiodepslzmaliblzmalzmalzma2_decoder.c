#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_24__   TYPE_6__ ;
typedef  struct TYPE_23__   TYPE_5__ ;
typedef  struct TYPE_22__   TYPE_4__ ;
typedef  struct TYPE_21__   TYPE_3__ ;
typedef  struct TYPE_20__   TYPE_2__ ;
typedef  struct TYPE_19__   TYPE_1__ ;

/* Type definitions */
typedef  int uint8_t ;
typedef  scalar_t__ uint64_t ;
typedef  int uint32_t ;
typedef  int /*<<< orphan*/  const lzma_ret ;
struct TYPE_21__ {scalar_t__ preset_dict_size; int dict_size; int /*<<< orphan*/ * preset_dict; } ;
typedef  TYPE_3__ lzma_options_lzma ;
typedef  int /*<<< orphan*/  lzma_next_coder ;
typedef  int /*<<< orphan*/  lzma_lz_options ;
struct TYPE_22__ {void (* end ) (TYPE_6__*,int /*<<< orphan*/ *) ;TYPE_2__* coder; int /*<<< orphan*/  const (* code ) (TYPE_6__*,int /*<<< orphan*/ *,int const*,size_t*,size_t) ;} ;
typedef  TYPE_4__ lzma_lz_decoder ;
struct TYPE_23__ {int /*<<< orphan*/ * init; } ;
typedef  TYPE_5__ lzma_filter_info ;
typedef  int /*<<< orphan*/  lzma_dict ;
struct TYPE_19__ {TYPE_6__* coder; int /*<<< orphan*/ * end; int /*<<< orphan*/  const (* code ) (TYPE_6__*,int /*<<< orphan*/ *,int const*,size_t*,size_t) ;int /*<<< orphan*/  (* reset ) (TYPE_6__*,int /*<<< orphan*/ *) ;int /*<<< orphan*/  (* set_uncompressed ) (TYPE_6__*,int) ;} ;
struct TYPE_24__ {int sequence; int need_properties; int need_dictionary_reset; int uncompressed_size; int next_sequence; int compressed_size; TYPE_1__ lzma; int /*<<< orphan*/  options; } ;
typedef  TYPE_6__ lzma_coder ;
typedef  int /*<<< orphan*/  lzma_allocator ;
struct TYPE_20__ {int sequence; int need_properties; int need_dictionary_reset; int /*<<< orphan*/  lzma; } ;

/* Variables and functions */
 int /*<<< orphan*/  const LZMA_DATA_ERROR ; 
 int /*<<< orphan*/  LZMA_LZ_DECODER_INIT ; 
 int /*<<< orphan*/  const LZMA_MEM_ERROR ; 
 int /*<<< orphan*/  const LZMA_OK ; 
 int /*<<< orphan*/  const LZMA_OPTIONS_ERROR ; 
 int /*<<< orphan*/  const LZMA_PROG_ERROR ; 
 int /*<<< orphan*/  const LZMA_STREAM_END ; 
#define  SEQ_COMPRESSED_0 135 
#define  SEQ_COMPRESSED_1 134 
#define  SEQ_CONTROL 133 
#define  SEQ_COPY 132 
#define  SEQ_LZMA 131 
#define  SEQ_PROPERTIES 130 
#define  SEQ_UNCOMPRESSED_1 129 
#define  SEQ_UNCOMPRESSED_2 128 
 int UINT32_MAX ; 
 int /*<<< orphan*/  assert (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  dict_reset (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  dict_write (int /*<<< orphan*/ *,int const*,size_t*,size_t,size_t const*) ; 
 void* lzma_alloc (int,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  lzma_free (TYPE_6__*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  const lzma_lz_decoder_init (int /*<<< orphan*/ *,int /*<<< orphan*/ *,TYPE_5__ const*,int /*<<< orphan*/  const (*) (TYPE_4__*,int /*<<< orphan*/ *,void const*,int /*<<< orphan*/ *)) ; 
 int /*<<< orphan*/  const lzma_lzma_decoder_create (int /*<<< orphan*/ *,int /*<<< orphan*/ *,TYPE_3__ const*,int /*<<< orphan*/ *) ; 
 scalar_t__ lzma_lzma_decoder_memusage_nocheck (void const*) ; 
 int /*<<< orphan*/  lzma_lzma_lclppb_decode (int /*<<< orphan*/ *,int const) ; 
 int /*<<< orphan*/  stub1 (TYPE_6__*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  stub2 (TYPE_6__*,int) ; 
 int /*<<< orphan*/  stub3 (TYPE_6__*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  const stub4 (TYPE_6__*,int /*<<< orphan*/ *,int const*,size_t*,size_t) ; 

__attribute__((used)) static lzma_ret
lzma2_decode(lzma_coder *restrict coder, lzma_dict *restrict dict,
		const uint8_t *restrict in, size_t *restrict in_pos,
		size_t in_size)
{
	// With SEQ_LZMA it is possible that no new input is needed to do
	// some progress. The rest of the sequences assume that there is
	// at least one byte of input.
	while (*in_pos < in_size || coder->sequence == SEQ_LZMA)
	switch (coder->sequence) {
	case SEQ_CONTROL: {
		const uint32_t control = in[*in_pos];
		++*in_pos;

		// End marker
		if (control == 0x00)
			return LZMA_STREAM_END;

		if (control >= 0xE0 || control == 1) {
			// Dictionary reset implies that next LZMA chunk has
			// to set new properties.
			coder->need_properties = true;
			coder->need_dictionary_reset = true;
		} else if (coder->need_dictionary_reset) {
			return LZMA_DATA_ERROR;
		}

		if (control >= 0x80) {
			// LZMA chunk. The highest five bits of the
			// uncompressed size are taken from the control byte.
			coder->uncompressed_size = (control & 0x1F) << 16;
			coder->sequence = SEQ_UNCOMPRESSED_1;

			// See if there are new properties or if we need to
			// reset the state.
			if (control >= 0xC0) {
				// When there are new properties, state reset
				// is done at SEQ_PROPERTIES.
				coder->need_properties = false;
				coder->next_sequence = SEQ_PROPERTIES;

			} else if (coder->need_properties) {
				return LZMA_DATA_ERROR;

			} else {
				coder->next_sequence = SEQ_LZMA;

				// If only state reset is wanted with old
				// properties, do the resetting here for
				// simplicity.
				if (control >= 0xA0)
					coder->lzma.reset(coder->lzma.coder,
							&coder->options);
			}
		} else {
			// Invalid control values
			if (control > 2)
				return LZMA_DATA_ERROR;

			// It's uncompressed chunk
			coder->sequence = SEQ_COMPRESSED_0;
			coder->next_sequence = SEQ_COPY;
		}

		if (coder->need_dictionary_reset) {
			// Finish the dictionary reset and let the caller
			// flush the dictionary to the actual output buffer.
			coder->need_dictionary_reset = false;
			dict_reset(dict);
			return LZMA_OK;
		}

		break;
	}

	case SEQ_UNCOMPRESSED_1:
		coder->uncompressed_size += (uint32_t)(in[(*in_pos)++]) << 8;
		coder->sequence = SEQ_UNCOMPRESSED_2;
		break;

	case SEQ_UNCOMPRESSED_2:
		coder->uncompressed_size += in[(*in_pos)++] + 1;
		coder->sequence = SEQ_COMPRESSED_0;
		coder->lzma.set_uncompressed(coder->lzma.coder,
				coder->uncompressed_size);
		break;

	case SEQ_COMPRESSED_0:
		coder->compressed_size = (uint32_t)(in[(*in_pos)++]) << 8;
		coder->sequence = SEQ_COMPRESSED_1;
		break;

	case SEQ_COMPRESSED_1:
		coder->compressed_size += in[(*in_pos)++] + 1;
		coder->sequence = coder->next_sequence;
		break;

	case SEQ_PROPERTIES:
		if (lzma_lzma_lclppb_decode(&coder->options, in[(*in_pos)++]))
			return LZMA_DATA_ERROR;

		coder->lzma.reset(coder->lzma.coder, &coder->options);

		coder->sequence = SEQ_LZMA;
		break;

	case SEQ_LZMA: {
		// Store the start offset so that we can update
		// coder->compressed_size later.
		const size_t in_start = *in_pos;

		// Decode from in[] to *dict.
		const lzma_ret ret = coder->lzma.code(coder->lzma.coder,
				dict, in, in_pos, in_size);

		// Validate and update coder->compressed_size.
		const size_t in_used = *in_pos - in_start;
		if (in_used > coder->compressed_size)
			return LZMA_DATA_ERROR;

		coder->compressed_size -= in_used;

		// Return if we didn't finish the chunk, or an error occurred.
		if (ret != LZMA_STREAM_END)
			return ret;

		// The LZMA decoder must have consumed the whole chunk now.
		// We don't need to worry about uncompressed size since it
		// is checked by the LZMA decoder.
		if (coder->compressed_size != 0)
			return LZMA_DATA_ERROR;

		coder->sequence = SEQ_CONTROL;
		break;
	}

	case SEQ_COPY: {
		// Copy from input to the dictionary as is.
		dict_write(dict, in, in_pos, in_size, &coder->compressed_size);
		if (coder->compressed_size != 0)
			return LZMA_OK;

		coder->sequence = SEQ_CONTROL;
		break;
	}

	default:
		assert(0);
		return LZMA_PROG_ERROR;
	}

	return LZMA_OK;
}

__attribute__((used)) static void
lzma2_decoder_end(lzma_coder *coder, lzma_allocator *allocator)
{
	assert(coder->lzma.end == NULL);
	lzma_free(coder->lzma.coder, allocator);

	lzma_free(coder, allocator);

	return;
}

__attribute__((used)) static lzma_ret
lzma2_decoder_init(lzma_lz_decoder *lz, lzma_allocator *allocator,
		const void *opt, lzma_lz_options *lz_options)
{
	if (lz->coder == NULL) {
		lz->coder = lzma_alloc(sizeof(lzma_coder), allocator);
		if (lz->coder == NULL)
			return LZMA_MEM_ERROR;

		lz->code = &lzma2_decode;
		lz->end = &lzma2_decoder_end;

		lz->coder->lzma = LZMA_LZ_DECODER_INIT;
	}

	const lzma_options_lzma *options = opt;

	lz->coder->sequence = SEQ_CONTROL;
	lz->coder->need_properties = true;
	lz->coder->need_dictionary_reset = options->preset_dict == NULL
			|| options->preset_dict_size == 0;

	return lzma_lzma_decoder_create(&lz->coder->lzma,
			allocator, options, lz_options);
}

extern lzma_ret
lzma_lzma2_decoder_init(lzma_next_coder *next, lzma_allocator *allocator,
		const lzma_filter_info *filters)
{
	// LZMA2 can only be the last filter in the chain. This is enforced
	// by the raw_decoder initialization.
	assert(filters[1].init == NULL);

	return lzma_lz_decoder_init(next, allocator, filters,
			&lzma2_decoder_init);
}

extern uint64_t
lzma_lzma2_decoder_memusage(const void *options)
{
	return sizeof(lzma_coder)
			+ lzma_lzma_decoder_memusage_nocheck(options);
}

extern lzma_ret
lzma_lzma2_props_decode(void **options, lzma_allocator *allocator,
		const uint8_t *props, size_t props_size)
{
	if (props_size != 1)
		return LZMA_OPTIONS_ERROR;

	// Check that reserved bits are unset.
	if (props[0] & 0xC0)
		return LZMA_OPTIONS_ERROR;

	// Decode the dictionary size.
	if (props[0] > 40)
		return LZMA_OPTIONS_ERROR;

	lzma_options_lzma *opt = lzma_alloc(
			sizeof(lzma_options_lzma), allocator);
	if (opt == NULL)
		return LZMA_MEM_ERROR;

	if (props[0] == 40) {
		opt->dict_size = UINT32_MAX;
	} else {
		opt->dict_size = 2 | (props[0] & 1);
		opt->dict_size <<= props[0] / 2 + 11;
	}

	opt->preset_dict = NULL;
	opt->preset_dict_size = 0;

	*options = opt;

	return LZMA_OK;
}

