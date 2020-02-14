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
 unsigned long _lrotr (unsigned long,int) ; 
 unsigned int _rotr (unsigned int,int) ; 

unsigned int _rotl( unsigned int value, int shift )
{
	int max_bits = sizeof(unsigned int)<<3;
	if ( shift < 0 )
		return _rotr(value,-shift);

	if ( shift > max_bits )
		shift = shift % max_bits;
	return (value << shift) | (value >> (max_bits-shift));
}

unsigned int _rotr( unsigned int value, int shift )
{
	int max_bits = sizeof(unsigned int)<<3;
	if ( shift < 0 )
		return _rotl(value,-shift);

	if ( shift > max_bits )
		shift = shift % max_bits;
	return (value >> shift) | (value <<  (max_bits-shift));
}

unsigned long _lrotl( unsigned long value, int shift )
{
	int max_bits = sizeof(unsigned long)<<3;
	if ( shift < 0 )
		return _lrotr(value,-shift);

	if ( shift > max_bits )
		shift = shift % max_bits;
	return (value << shift) | (value >> (max_bits-shift));
}

unsigned long _lrotr( unsigned long value, int shift )
{
	int max_bits = sizeof(unsigned long)<<3;
	if ( shift < 0 )
		return _lrotl(value,-shift);

	if ( shift > max_bits )
		shift = shift % max_bits;
	return (value >> shift) | (value << (max_bits-shift));
}

