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
 int /*<<< orphan*/  ALIGN_DEST_TO8_DN (unsigned long,unsigned long,long) ; 
 int /*<<< orphan*/  ALIGN_DEST_TO8_UP (unsigned long,unsigned long,long) ; 
 int /*<<< orphan*/  DO_REST_ALIGNED_DN (unsigned long,unsigned long,long) ; 
 int /*<<< orphan*/  DO_REST_ALIGNED_UP (unsigned long,unsigned long,long) ; 
 int /*<<< orphan*/  DO_REST_UP (unsigned long,unsigned long,long) ; 

__attribute__((used)) static inline void __memcpy_unaligned_up (unsigned long d, unsigned long s,
					  long n)
{
	ALIGN_DEST_TO8_UP(d,s,n);
	n -= 8;			/* to avoid compare against 8 in the loop */
	if (n >= 0) {
		unsigned long low_word, high_word;
		__asm__("ldq_u %0,%1":"=r" (low_word):"m" (*(unsigned long *) s));
		do {
			unsigned long tmp;
			__asm__("ldq_u %0,%1":"=r" (high_word):"m" (*(unsigned long *)(s+8)));
			n -= 8;
			__asm__("extql %1,%2,%0"
				:"=r" (low_word)
				:"r" (low_word), "r" (s));
			__asm__("extqh %1,%2,%0"
				:"=r" (tmp)
				:"r" (high_word), "r" (s));
			s += 8;
			*(unsigned long *) d = low_word | tmp;
			d += 8;
			low_word = high_word;
		} while (n >= 0);
	}
	n += 8;
	DO_REST_UP(d,s,n);
}

__attribute__((used)) static inline void __memcpy_unaligned_dn (unsigned long d, unsigned long s,
					  long n)
{
	/* I don't understand AXP assembler well enough for this. -Tim */
	s += n;
	d += n;
	while (n--)
		* (char *) --d = * (char *) --s;
}

__attribute__((used)) static inline void __memcpy_aligned_up (unsigned long d, unsigned long s,
					long n)
{
	ALIGN_DEST_TO8_UP(d,s,n);
	n -= 8;
	while (n >= 0) {
		unsigned long tmp;
		__asm__("ldq %0,%1":"=r" (tmp):"m" (*(unsigned long *) s));
		n -= 8;
		s += 8;
		*(unsigned long *) d = tmp;
		d += 8;
	}
	n += 8;
	DO_REST_ALIGNED_UP(d,s,n);
}

__attribute__((used)) static inline void __memcpy_aligned_dn (unsigned long d, unsigned long s,
					long n)
{
	s += n;
	d += n;
	ALIGN_DEST_TO8_DN(d,s,n);
	n -= 8;
	while (n >= 0) {
		unsigned long tmp;
		s -= 8;
		__asm__("ldq %0,%1":"=r" (tmp):"m" (*(unsigned long *) s));
		n -= 8;
		d -= 8;
		*(unsigned long *) d = tmp;
	}
	n += 8;
	DO_REST_ALIGNED_DN(d,s,n);
}

void * memcpy(void * dest, const void *src, size_t n)
{
	if (!(((unsigned long) dest ^ (unsigned long) src) & 7)) {
		__memcpy_aligned_up ((unsigned long) dest, (unsigned long) src,
				     n);
		return dest;
	}
	__memcpy_unaligned_up ((unsigned long) dest, (unsigned long) src, n);
	return dest;
}

