#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_19__   TYPE_5__ ;
typedef  struct TYPE_18__   TYPE_4__ ;
typedef  struct TYPE_17__   TYPE_3__ ;
typedef  struct TYPE_16__   TYPE_2__ ;
typedef  struct TYPE_15__   TYPE_1__ ;

/* Type definitions */
typedef  int uint32_t ;
typedef  void* uint16_t ;
typedef  void (* brotli_free_func ) (void*,void*) ;
typedef  void* (* brotli_alloc_func ) (void*,size_t) ;
struct TYPE_17__ {int /*<<< orphan*/ * htrees; int /*<<< orphan*/ * codes; } ;
struct TYPE_16__ {int /*<<< orphan*/ * htrees; int /*<<< orphan*/ * codes; } ;
struct TYPE_15__ {int /*<<< orphan*/ * htrees; int /*<<< orphan*/ * codes; } ;
struct TYPE_19__ {void* (* alloc_func ) (void*,size_t) ;void (* free_func ) (void*,void*) ;int canny_ringbuffer_allocation; int* dist_rb; int mtf_upper_bound; unsigned int* block_length; int* num_block_types; int* block_type_rb; int /*<<< orphan*/ * block_type_trees; int /*<<< orphan*/ * ringbuffer; TYPE_3__ distance_hgroup; TYPE_2__ insert_copy_hgroup; TYPE_1__ literal_hgroup; int /*<<< orphan*/ * dist_context_map; int /*<<< orphan*/ * context_map; int /*<<< orphan*/ * context_modes; int /*<<< orphan*/ * context_lookup2; int /*<<< orphan*/ * context_lookup1; scalar_t__ dist_htree_index; int /*<<< orphan*/ * dist_context_map_slice; int /*<<< orphan*/ * literal_htree; int /*<<< orphan*/ * context_map_slice; scalar_t__ meta_block_remaining_len; int /*<<< orphan*/ * symbols_lists_array; int /*<<< orphan*/ * symbol_lists; int /*<<< orphan*/ * block_len_trees; scalar_t__ dist_rb_idx; scalar_t__ max_distance; scalar_t__ window_bits; scalar_t__ should_wrap_ringbuffer; scalar_t__ is_metadata; scalar_t__ is_uncompressed; scalar_t__ is_last_metablock; scalar_t__ sub_loop_counter; scalar_t__ ringbuffer_mask; scalar_t__ new_ringbuffer_size; scalar_t__ ringbuffer_size; scalar_t__ partial_pos_out; scalar_t__ rb_roundtrips; scalar_t__ pos; scalar_t__ loop_counter; scalar_t__ buffer_length; int /*<<< orphan*/  dictionary; int /*<<< orphan*/  substate_read_block_length; int /*<<< orphan*/  substate_decode_uint8; int /*<<< orphan*/  substate_huffman; int /*<<< orphan*/  substate_uncompressed; int /*<<< orphan*/  substate_context_map; int /*<<< orphan*/  substate_tree_group; int /*<<< orphan*/  substate_metablock_header; int /*<<< orphan*/  state; int /*<<< orphan*/  br; scalar_t__ error_code; void* memory_manager_opaque; } ;
struct TYPE_18__ {int /*<<< orphan*/ * codes; int /*<<< orphan*/ ** htrees; void* num_htrees; void* alphabet_size; } ;
typedef  TYPE_4__ HuffmanTreeGroup ;
typedef  int /*<<< orphan*/  HuffmanCode ;
typedef  TYPE_5__ BrotliDecoderState ;
typedef  int BROTLI_BOOL ;

/* Variables and functions */
 scalar_t__ BROTLI_ALLOC (TYPE_5__*,size_t const) ; 
 int /*<<< orphan*/  BROTLI_FREE (TYPE_5__*,int /*<<< orphan*/ *) ; 
 int BROTLI_HUFFMAN_MAX_CODE_LENGTH ; 
 int /*<<< orphan*/  BROTLI_STATE_CONTEXT_MAP_NONE ; 
 int /*<<< orphan*/  BROTLI_STATE_DECODE_UINT8_NONE ; 
 int /*<<< orphan*/  BROTLI_STATE_HUFFMAN_NONE ; 
 int /*<<< orphan*/  BROTLI_STATE_METABLOCK_HEADER_NONE ; 
 int /*<<< orphan*/  BROTLI_STATE_READ_BLOCK_LENGTH_NONE ; 
 int /*<<< orphan*/  BROTLI_STATE_TREE_GROUP_NONE ; 
 int /*<<< orphan*/  BROTLI_STATE_UNCOMPRESSED_NONE ; 
 int /*<<< orphan*/  BROTLI_STATE_UNINITED ; 
 int /*<<< orphan*/  BROTLI_UNUSED (void*) ; 
 void BrotliDecoderStateInitWithCustomAllocators (TYPE_5__*,void* (*) (void*,size_t),void (*) (void*,void*),void*) ; 
 int /*<<< orphan*/  BrotliGetDictionary () ; 
 int /*<<< orphan*/  BrotliInitBitReader (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  free (void*) ; 
 size_t* kMaxHuffmanTableSize ; 
 void* malloc (size_t) ; 

__attribute__((used)) static void* DefaultAllocFunc(void* opaque, size_t size) {
  BROTLI_UNUSED(opaque);
  return malloc(size);
}

__attribute__((used)) static void DefaultFreeFunc(void* opaque, void* address) {
  BROTLI_UNUSED(opaque);
  free(address);
}

void BrotliDecoderStateInit(BrotliDecoderState* s) {
  BrotliDecoderStateInitWithCustomAllocators(s, 0, 0, 0);
}

void BrotliDecoderStateInitWithCustomAllocators(BrotliDecoderState* s,
    brotli_alloc_func alloc_func, brotli_free_func free_func, void* opaque) {
  if (!alloc_func) {
    s->alloc_func = DefaultAllocFunc;
    s->free_func = DefaultFreeFunc;
    s->memory_manager_opaque = 0;
  } else {
    s->alloc_func = alloc_func;
    s->free_func = free_func;
    s->memory_manager_opaque = opaque;
  }

  s->error_code = 0; /* BROTLI_DECODER_NO_ERROR */

  BrotliInitBitReader(&s->br);
  s->state = BROTLI_STATE_UNINITED;
  s->substate_metablock_header = BROTLI_STATE_METABLOCK_HEADER_NONE;
  s->substate_tree_group = BROTLI_STATE_TREE_GROUP_NONE;
  s->substate_context_map = BROTLI_STATE_CONTEXT_MAP_NONE;
  s->substate_uncompressed = BROTLI_STATE_UNCOMPRESSED_NONE;
  s->substate_huffman = BROTLI_STATE_HUFFMAN_NONE;
  s->substate_decode_uint8 = BROTLI_STATE_DECODE_UINT8_NONE;
  s->substate_read_block_length = BROTLI_STATE_READ_BLOCK_LENGTH_NONE;

  s->dictionary = BrotliGetDictionary();

  s->buffer_length = 0;
  s->loop_counter = 0;
  s->pos = 0;
  s->rb_roundtrips = 0;
  s->partial_pos_out = 0;

  s->block_type_trees = NULL;
  s->block_len_trees = NULL;
  s->ringbuffer = NULL;
  s->ringbuffer_size = 0;
  s->new_ringbuffer_size = 0;
  s->ringbuffer_mask = 0;

  s->context_map = NULL;
  s->context_modes = NULL;
  s->dist_context_map = NULL;
  s->context_map_slice = NULL;
  s->dist_context_map_slice = NULL;

  s->sub_loop_counter = 0;

  s->literal_hgroup.codes = NULL;
  s->literal_hgroup.htrees = NULL;
  s->insert_copy_hgroup.codes = NULL;
  s->insert_copy_hgroup.htrees = NULL;
  s->distance_hgroup.codes = NULL;
  s->distance_hgroup.htrees = NULL;

  s->is_last_metablock = 0;
  s->is_uncompressed = 0;
  s->is_metadata = 0;
  s->should_wrap_ringbuffer = 0;
  s->canny_ringbuffer_allocation = 1;

  s->window_bits = 0;
  s->max_distance = 0;
  s->dist_rb[0] = 16;
  s->dist_rb[1] = 15;
  s->dist_rb[2] = 11;
  s->dist_rb[3] = 4;
  s->dist_rb_idx = 0;
  s->block_type_trees = NULL;
  s->block_len_trees = NULL;

  /* Make small negative indexes addressable. */
  s->symbol_lists = &s->symbols_lists_array[BROTLI_HUFFMAN_MAX_CODE_LENGTH + 1];

  s->mtf_upper_bound = 63;
}

void BrotliDecoderStateMetablockBegin(BrotliDecoderState* s) {
  s->meta_block_remaining_len = 0;
  s->block_length[0] = 1U << 28;
  s->block_length[1] = 1U << 28;
  s->block_length[2] = 1U << 28;
  s->num_block_types[0] = 1;
  s->num_block_types[1] = 1;
  s->num_block_types[2] = 1;
  s->block_type_rb[0] = 1;
  s->block_type_rb[1] = 0;
  s->block_type_rb[2] = 1;
  s->block_type_rb[3] = 0;
  s->block_type_rb[4] = 1;
  s->block_type_rb[5] = 0;
  s->context_map = NULL;
  s->context_modes = NULL;
  s->dist_context_map = NULL;
  s->context_map_slice = NULL;
  s->literal_htree = NULL;
  s->dist_context_map_slice = NULL;
  s->dist_htree_index = 0;
  s->context_lookup1 = NULL;
  s->context_lookup2 = NULL;
  s->literal_hgroup.codes = NULL;
  s->literal_hgroup.htrees = NULL;
  s->insert_copy_hgroup.codes = NULL;
  s->insert_copy_hgroup.htrees = NULL;
  s->distance_hgroup.codes = NULL;
  s->distance_hgroup.htrees = NULL;
}

void BrotliDecoderStateCleanupAfterMetablock(BrotliDecoderState* s) {
  BROTLI_FREE(s, s->context_modes);
  BROTLI_FREE(s, s->context_map);
  BROTLI_FREE(s, s->dist_context_map);
  BROTLI_FREE(s, s->literal_hgroup.htrees);
  BROTLI_FREE(s, s->insert_copy_hgroup.htrees);
  BROTLI_FREE(s, s->distance_hgroup.htrees);
}

void BrotliDecoderStateCleanup(BrotliDecoderState* s) {
  BrotliDecoderStateCleanupAfterMetablock(s);

  BROTLI_FREE(s, s->ringbuffer);
  BROTLI_FREE(s, s->block_type_trees);
}

BROTLI_BOOL BrotliDecoderHuffmanTreeGroupInit(BrotliDecoderState* s,
    HuffmanTreeGroup* group, uint32_t alphabet_size, uint32_t ntrees) {
  /* Pack two allocations into one */
  const size_t max_table_size = kMaxHuffmanTableSize[(alphabet_size + 31) >> 5];
  const size_t code_size = sizeof(HuffmanCode) * ntrees * max_table_size;
  const size_t htree_size = sizeof(HuffmanCode*) * ntrees;
  /* Pointer alignment is, hopefully, wider than sizeof(HuffmanCode). */
  HuffmanCode** p = (HuffmanCode**)BROTLI_ALLOC(s, code_size + htree_size);
  group->alphabet_size = (uint16_t)alphabet_size;
  group->num_htrees = (uint16_t)ntrees;
  group->htrees = p;
  group->codes = (HuffmanCode*)(&p[ntrees]);
  return !!p;
}

