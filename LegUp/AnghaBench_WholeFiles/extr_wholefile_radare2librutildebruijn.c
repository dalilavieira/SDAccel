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
 void* calloc (int,int) ; 
 int /*<<< orphan*/  free (int*) ; 
 int strlen (char const*) ; 

__attribute__((used)) static void de_bruijn_seq(int prenecklace_len_t, int lyndon_prefix_len_p, int order,
		int maxlen, int size, int* prenecklace_a, char* sequence, const char* charset) {
	int j;
	if (!charset || !sequence || strlen (sequence) == maxlen) {
		return;
	}
	if (prenecklace_len_t > order) {
		if (order % lyndon_prefix_len_p == 0) {
			for (j = 1; j <= lyndon_prefix_len_p; ++j) {
				sequence[strlen(sequence)] = charset[prenecklace_a[j]];
				if (strlen (sequence) == maxlen) {
					return;
				}
			}
		}
	} else {
		prenecklace_a[prenecklace_len_t] =
			prenecklace_a[prenecklace_len_t - lyndon_prefix_len_p];
		de_bruijn_seq(prenecklace_len_t + 1, lyndon_prefix_len_p, order, maxlen,
				size, prenecklace_a, sequence, charset);
		for (j = prenecklace_a[prenecklace_len_t - lyndon_prefix_len_p] + 1;
				j < size; ++j) {
			prenecklace_a[prenecklace_len_t] = j;
			de_bruijn_seq (prenecklace_len_t + 1, prenecklace_len_t, order, maxlen,
					size, prenecklace_a, sequence, charset);
		}
	}
}

__attribute__((used)) static char* de_bruijn(const char* charset, int order, int maxlen) {
	if (!charset) {
		return NULL;
	}
	int size = strlen (charset);
	int* prenecklace_a = calloc (size * order, sizeof (int));
	if (!prenecklace_a) {
		return NULL;
	}
	char* sequence = calloc (maxlen + 1, sizeof (char));
	if (!sequence) {
		free (prenecklace_a);
		return NULL;
	}
	de_bruijn_seq (1, 1, order, maxlen, size, prenecklace_a, sequence, charset);
	free (prenecklace_a);
	return sequence;
}

