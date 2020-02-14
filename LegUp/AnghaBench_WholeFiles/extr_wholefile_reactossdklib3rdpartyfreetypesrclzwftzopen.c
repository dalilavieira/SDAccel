#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_6__   TYPE_1__ ;

/* Type definitions */
struct TYPE_6__ {unsigned long* buf_tab; scalar_t__ num_bits; unsigned long buf_size; unsigned long buf_offset; scalar_t__ free_ent; scalar_t__ free_bits; scalar_t__ max_bits; unsigned long max_free; scalar_t__ stack_top; scalar_t__ stack_size; unsigned long prefix_size; unsigned long* suffix; scalar_t__ prefix; int /*<<< orphan*/  memory; int /*<<< orphan*/ * stack; int /*<<< orphan*/ * stack_0; scalar_t__ buf_clear; int /*<<< orphan*/  in_eof; int /*<<< orphan*/  buf_total; int /*<<< orphan*/  source; } ;
typedef  int /*<<< orphan*/  FT_UShort ;
typedef  scalar_t__ FT_ULong ;
typedef  unsigned long FT_UInt ;
typedef  int FT_Offset ;
typedef  int /*<<< orphan*/  FT_Memory ;
typedef  TYPE_1__* FT_LzwState ;
typedef  int FT_Int32 ;
typedef  unsigned long FT_Int ;
typedef  int /*<<< orphan*/  FT_Error ;
typedef  unsigned long FT_Byte ;

/* Variables and functions */
 int /*<<< orphan*/  FT_BOOL (int) ; 
 int /*<<< orphan*/  FT_MEM_MOVE (unsigned long*,scalar_t__,unsigned long) ; 
 scalar_t__ FT_REALLOC_MULT (scalar_t__,unsigned long,unsigned long,int) ; 
 scalar_t__ FT_RENEW_ARRAY (int /*<<< orphan*/ *,int,int) ; 
 scalar_t__ FT_Stream_TryRead (int /*<<< orphan*/ ,unsigned long*,scalar_t__) ; 
 unsigned long LZW_INIT_BITS ; 
 unsigned long LZW_MASK (unsigned long) ; 
 unsigned long LZW_MAX_BITS ; 

__attribute__((used)) static int
  ft_lzwstate_refill( FT_LzwState  state )
  {
    FT_ULong  count;


    if ( state->in_eof )
      return -1;

    count = FT_Stream_TryRead( state->source,
                               state->buf_tab,
                               state->num_bits );  /* WHY? */

    state->buf_size   = (FT_UInt)count;
    state->buf_total += count;
    state->in_eof     = FT_BOOL( count < state->num_bits );
    state->buf_offset = 0;

    state->buf_size <<= 3;
    if ( state->buf_size > state->num_bits )
      state->buf_size -= state->num_bits - 1;
    else
      return -1; /* not enough data */

    if ( count == 0 )  /* end of file */
      return -1;

    return 0;
  }

__attribute__((used)) static FT_Int32
  ft_lzwstate_get_code( FT_LzwState  state )
  {
    FT_UInt   num_bits = state->num_bits;
    FT_UInt   offset   = state->buf_offset;
    FT_Byte*  p;
    FT_Int    result;


    if ( state->buf_clear                    ||
         offset >= state->buf_size           ||
         state->free_ent >= state->free_bits )
    {
      if ( state->free_ent >= state->free_bits )
      {
        state->num_bits = ++num_bits;
        if ( num_bits > LZW_MAX_BITS )
          return -1;

        state->free_bits = state->num_bits < state->max_bits
                           ? (FT_UInt)( ( 1UL << num_bits ) - 256 )
                           : state->max_free + 1;
      }

      if ( state->buf_clear )
      {
        state->num_bits  = num_bits = LZW_INIT_BITS;
        state->free_bits = (FT_UInt)( ( 1UL << num_bits ) - 256 );
        state->buf_clear = 0;
      }

      if ( ft_lzwstate_refill( state ) < 0 )
        return -1;

      offset = 0;
    }

    state->buf_offset = offset + num_bits;

    p         = &state->buf_tab[offset >> 3];
    offset   &= 7;
    result    = *p++ >> offset;
    offset    = 8 - offset;
    num_bits -= offset;

    if ( num_bits >= 8 )
    {
      result   |= *p++ << offset;
      offset   += 8;
      num_bits -= 8;
    }
    if ( num_bits > 0 )
      result |= ( *p & LZW_MASK( num_bits ) ) << offset;

    return result;
  }

__attribute__((used)) static int
  ft_lzwstate_stack_grow( FT_LzwState  state )
  {
    if ( state->stack_top >= state->stack_size )
    {
      FT_Memory  memory = state->memory;
      FT_Error   error;
      FT_Offset  old_size = state->stack_size;
      FT_Offset  new_size = old_size;

      new_size = new_size + ( new_size >> 1 ) + 4;

      if ( state->stack == state->stack_0 )
      {
        state->stack = NULL;
        old_size     = 0;
      }

      /* requirement of the character stack larger than 1<<LZW_MAX_BITS */
      /* implies bug in the decompression code                          */
      if ( new_size > ( 1 << LZW_MAX_BITS ) )
      {
        new_size = 1 << LZW_MAX_BITS;
        if ( new_size == old_size )
          return -1;
      }

      if ( FT_RENEW_ARRAY( state->stack, old_size, new_size ) )
        return -1;

      state->stack_size = new_size;
    }
    return 0;
  }

__attribute__((used)) static int
  ft_lzwstate_prefix_grow( FT_LzwState  state )
  {
    FT_UInt    old_size = state->prefix_size;
    FT_UInt    new_size = old_size;
    FT_Memory  memory   = state->memory;
    FT_Error   error;


    if ( new_size == 0 )  /* first allocation -> 9 bits */
      new_size = 512;
    else
      new_size += new_size >> 2;  /* don't grow too fast */

    /*
     *  Note that the `suffix' array is located in the same memory block
     *  pointed to by `prefix'.
     *
     *  I know that sizeof(FT_Byte) == 1 by definition, but it is clearer
     *  to write it literally.
     *
     */
    if ( FT_REALLOC_MULT( state->prefix, old_size, new_size,
                          sizeof ( FT_UShort ) + sizeof ( FT_Byte ) ) )
      return -1;

    /* now adjust `suffix' and move the data accordingly */
    state->suffix = (FT_Byte*)( state->prefix + new_size );

    FT_MEM_MOVE( state->suffix,
                 state->prefix + old_size,
                 old_size * sizeof ( FT_Byte ) );

    state->prefix_size = new_size;
    return 0;
  }

