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
typedef  scalar_t__ (* binary__fprintf_t ) (int /*<<< orphan*/ ,int,void*,int /*<<< orphan*/ *) ;
typedef  int /*<<< orphan*/  FILE ;

/* Variables and functions */
 int /*<<< orphan*/  BINARY_PRINT_ADDR ; 
 int /*<<< orphan*/  BINARY_PRINT_CHAR_DATA ; 
 int /*<<< orphan*/  BINARY_PRINT_CHAR_PAD ; 
 int /*<<< orphan*/  BINARY_PRINT_DATA_BEGIN ; 
 int /*<<< orphan*/  BINARY_PRINT_DATA_END ; 
 int /*<<< orphan*/  BINARY_PRINT_LINE_BEGIN ; 
 int /*<<< orphan*/  BINARY_PRINT_LINE_END ; 
 int /*<<< orphan*/  BINARY_PRINT_NUM_DATA ; 
 int /*<<< orphan*/  BINARY_PRINT_NUM_PAD ; 
 int /*<<< orphan*/  BINARY_PRINT_SEP ; 
 int /*<<< orphan*/  GIT_ALPHA ; 
 int binary__fprintf (unsigned char*,size_t,size_t,scalar_t__ (*) (int /*<<< orphan*/ ,int,void*,int /*<<< orphan*/ *),void*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  isprint (char) ; 
 int /*<<< orphan*/  isspace (char) ; 
 size_t roundup_pow_of_two (size_t) ; 
 scalar_t__ sane_istest (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/ * stdout ; 

__attribute__((used)) static inline void print_binary(unsigned char *data, size_t len,
				size_t bytes_per_line, binary__fprintf_t printer,
				void *extra)
{
	binary__fprintf(data, len, bytes_per_line, printer, extra, stdout);
}

__attribute__((used)) static inline int sane_case(int x, int high)
{
	if (sane_istest(x, GIT_ALPHA))
		x = (x & ~0x20) | high;
	return x;
}

int binary__fprintf(unsigned char *data, size_t len,
		    size_t bytes_per_line, binary__fprintf_t printer,
		    void *extra, FILE *fp)
{
	size_t i, j, mask;
	int printed = 0;

	if (!printer)
		return 0;

	bytes_per_line = roundup_pow_of_two(bytes_per_line);
	mask = bytes_per_line - 1;

	printed += printer(BINARY_PRINT_DATA_BEGIN, 0, extra, fp);
	for (i = 0; i < len; i++) {
		if ((i & mask) == 0) {
			printed += printer(BINARY_PRINT_LINE_BEGIN, -1, extra, fp);
			printed += printer(BINARY_PRINT_ADDR, i, extra, fp);
		}

		printed += printer(BINARY_PRINT_NUM_DATA, data[i], extra, fp);

		if (((i & mask) == mask) || i == len - 1) {
			for (j = 0; j < mask-(i & mask); j++)
				printed += printer(BINARY_PRINT_NUM_PAD, -1, extra, fp);

			printer(BINARY_PRINT_SEP, i, extra, fp);
			for (j = i & ~mask; j <= i; j++)
				printed += printer(BINARY_PRINT_CHAR_DATA, data[j], extra, fp);
			for (j = 0; j < mask-(i & mask); j++)
				printed += printer(BINARY_PRINT_CHAR_PAD, i, extra, fp);
			printed += printer(BINARY_PRINT_LINE_END, -1, extra, fp);
		}
	}
	printed += printer(BINARY_PRINT_DATA_END, -1, extra, fp);
	return printed;
}

int is_printable_array(char *p, unsigned int len)
{
	unsigned int i;

	if (!p || !len || p[len - 1] != 0)
		return 0;

	len--;

	for (i = 0; i < len; i++) {
		if (!isprint(p[i]) && !isspace(p[i]))
			return 0;
	}
	return 1;
}

