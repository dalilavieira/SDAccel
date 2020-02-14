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
typedef  scalar_t__ clock_t ;

/* Variables and functions */
 float CLOCKS_PER_SEC ; 
 int alphabet ; 
 scalar_t__ clock () ; 
 int drand48 () ; 
 int /*<<< orphan*/  fprintf (int /*<<< orphan*/ ,char*,float) ; 
 char* kmemmem (char*,int,char*,int,int /*<<< orphan*/ ) ; 
 int lrand48 () ; 
 char* malloc (int) ; 
 int pat_len ; 
 int repeat ; 
 int /*<<< orphan*/  srand48 (int) ; 
 int /*<<< orphan*/  stderr ; 
 int str_len ; 

char *gen_data(int len, int a)
{
	char *data;
	int i;
	long x;
	srand48(11);
	data = malloc(len);
	for (i = 0; i < len; ++i)
		data[i] = (int)(a * drand48()) + '!';
	data[str_len - 1] = 0;
	return data;
}

char *BoyerMoore( unsigned char *data, unsigned int dataLength, unsigned char *string, unsigned int strLength )
{
	unsigned int skipTable[256], i;
	unsigned char *search;
	register unsigned char lastChar;

	if (strLength == 0)
		return NULL;

	for (i = 0; i < 256; i++)
		skipTable[i] = strLength;
	search = string;
	i = --strLength;
	do {
		skipTable[*search++] = i;
	} while (i--);
	lastChar = *--search;
	search = data + strLength;
	dataLength -= strLength+(strLength-1);
	while ((int)dataLength > 0 ) {
		unsigned int skip;
		skip = skipTable[*search];
		search += skip;
		dataLength -= skip;
		skip = skipTable[*search];
		search += skip;
		dataLength -= skip;
		skip = skipTable[*search];
		if (*search != lastChar) {
			search += skip;
			dataLength -= skip;
			continue;
		}
		i = strLength;
		do {
			if (i-- == 0) return search;
		} while (*--search == string[i]);
		search += (strLength - i + 1);
		dataLength--;
	}
	return NULL;
}

int main()
{
	char *data;
	int i;
	clock_t t;
	t = clock();
	data = gen_data(str_len, alphabet);
	fprintf(stderr, "Generate data in %.3f sec\n", (float)(clock() - t) / CLOCKS_PER_SEC);
	{
		t = clock(); srand48(1331);
		for (i = 0; i < repeat; ++i) {
			int y = lrand48() % (str_len - pat_len);
			char *ret;
			ret = kmemmem(data, str_len, data + y, pat_len, 0);
//			printf("%d, %d\n", (int)(ret - data), y);
		}
		fprintf(stderr, "Search patterns in %.3f sec\n", (float)(clock() - t) / CLOCKS_PER_SEC);
	}
	if (1) {
		t = clock(); srand48(1331);
		for (i = 0; i < repeat; ++i) {
			int y = lrand48() % (str_len - pat_len);
			char *ret;
			ret = BoyerMoore(data, str_len, data + y, pat_len);
//			printf("%d, %d\n", (int)(ret - data), y);
		}
		fprintf(stderr, "Search patterns in %.3f sec\n", (float)(clock() - t) / CLOCKS_PER_SEC);
	}
#ifdef HAVE_STRNSTR
	if (1) {
		char *tmp;
		t = clock(); srand48(1331);
		tmp = calloc(pat_len+1, 1);
		for (i = 0; i < repeat; ++i) {
			int y = lrand48() % (str_len - pat_len);
			char *ret;
			memcpy(tmp, data + y, pat_len);
			ret = strnstr(data, tmp, str_len);
		}
		fprintf(stderr, "Search patterns in %.3f sec\n", (float)(clock() - t) / CLOCKS_PER_SEC);		
	}
#endif
#ifdef HAVE_MEMMEM
	if (1) {
		t = clock(); srand48(1331);
		for (i = 0; i < repeat; ++i) {
			int y = lrand48() % (str_len - pat_len);
			char *ret;
			ret = memmem(data, str_len, data + y, pat_len);
//			printf("%d, %d\n", (int)(ret - data), y);
		}
		fprintf(stderr, "Search patterns in %.3f sec\n", (float)(clock() - t) / CLOCKS_PER_SEC);
	}
#endif
	return 0;
}

