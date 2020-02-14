#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_13__   TYPE_4__ ;
typedef  struct TYPE_12__   TYPE_3__ ;
typedef  struct TYPE_11__   TYPE_2__ ;
typedef  struct TYPE_10__   TYPE_1__ ;

/* Type definitions */
typedef  scalar_t__ uint8_t ;
typedef  int /*<<< orphan*/  const lzma_ret ;
struct TYPE_11__ {scalar_t__ dist; int /*<<< orphan*/  type; } ;
typedef  TYPE_2__ lzma_options_delta ;
struct TYPE_12__ {int /*<<< orphan*/  const (* code ) (TYPE_4__*,int /*<<< orphan*/ *,scalar_t__ const*,size_t*,size_t,scalar_t__*,size_t*,size_t,int /*<<< orphan*/ ) ;} ;
typedef  TYPE_3__ lzma_next_coder ;
typedef  int /*<<< orphan*/  lzma_filter_info ;
struct TYPE_10__ {int /*<<< orphan*/  coder; int /*<<< orphan*/  const (* code ) (int /*<<< orphan*/ ,int /*<<< orphan*/ *,scalar_t__ const*,size_t*,size_t,scalar_t__*,size_t*,size_t,int /*<<< orphan*/ ) ;} ;
struct TYPE_13__ {size_t distance; int pos; TYPE_1__ next; scalar_t__* history; } ;
typedef  TYPE_4__ lzma_coder ;
typedef  int /*<<< orphan*/  lzma_allocator ;
typedef  int /*<<< orphan*/  lzma_action ;

/* Variables and functions */
 int /*<<< orphan*/  LZMA_DELTA_TYPE_BYTE ; 
 int /*<<< orphan*/  const LZMA_MEM_ERROR ; 
 int /*<<< orphan*/  const LZMA_OK ; 
 int /*<<< orphan*/  const LZMA_OPTIONS_ERROR ; 
 int /*<<< orphan*/  assert (int /*<<< orphan*/ ) ; 
 TYPE_2__* lzma_alloc (int,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  const lzma_delta_coder_init (TYPE_3__*,int /*<<< orphan*/ *,int /*<<< orphan*/  const*) ; 
 int /*<<< orphan*/  const stub1 (int /*<<< orphan*/ ,int /*<<< orphan*/ *,scalar_t__ const*,size_t*,size_t,scalar_t__*,size_t*,size_t,int /*<<< orphan*/ ) ; 

__attribute__((used)) static void
decode_buffer(lzma_coder *coder, uint8_t *buffer, size_t size)
{
	const size_t distance = coder->distance;

	for (size_t i = 0; i < size; ++i) {
		buffer[i] += coder->history[(distance + coder->pos) & 0xFF];
		coder->history[coder->pos-- & 0xFF] = buffer[i];
	}
}

__attribute__((used)) static lzma_ret
delta_decode(lzma_coder *coder, lzma_allocator *allocator,
		const uint8_t *restrict in, size_t *restrict in_pos,
		size_t in_size, uint8_t *restrict out,
		size_t *restrict out_pos, size_t out_size, lzma_action action)
{
	assert(coder->next.code != NULL);

	const size_t out_start = *out_pos;

	const lzma_ret ret = coder->next.code(coder->next.coder, allocator,
			in, in_pos, in_size, out, out_pos, out_size,
			action);

	decode_buffer(coder, out + out_start, *out_pos - out_start);

	return ret;
}

extern lzma_ret
lzma_delta_decoder_init(lzma_next_coder *next, lzma_allocator *allocator,
		const lzma_filter_info *filters)
{
	next->code = &delta_decode;
	return lzma_delta_coder_init(next, allocator, filters);
}

extern lzma_ret
lzma_delta_props_decode(void **options, lzma_allocator *allocator,
		const uint8_t *props, size_t props_size)
{
	if (props_size != 1)
		return LZMA_OPTIONS_ERROR;

	lzma_options_delta *opt
			= lzma_alloc(sizeof(lzma_options_delta), allocator);
	if (opt == NULL)
		return LZMA_MEM_ERROR;

	opt->type = LZMA_DELTA_TYPE_BYTE;
	opt->dist = props[0] + 1;

	*options = opt;

	return LZMA_OK;
}

