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
struct cpu_hist {long max; long* data; } ;
typedef  int /*<<< orphan*/  filename ;

/* Variables and functions */
 int MAX_CPU ; 
 int MAX_ENTRIES ; 
 int MAX_STARS ; 
 char* bpf_log_buf ; 
 int /*<<< orphan*/  bpf_map_lookup_elem (int,long*,long*) ; 
 struct cpu_hist* cpu_hist ; 
 scalar_t__ load_bpf_file (char*) ; 
 int* map_fd ; 
 int /*<<< orphan*/  printf (char*,...) ; 
 int /*<<< orphan*/  sleep (int) ; 
 int /*<<< orphan*/  snprintf (char*,int,char*,char*) ; 

__attribute__((used)) static void stars(char *str, long val, long max, int width)
{
	int i;

	for (i = 0; i < (width * val / max) - 1 && i < width - 1; i++)
		str[i] = '*';
	if (val > max)
		str[i - 1] = '+';
	str[i] = '\0';
}

__attribute__((used)) static void print_hist(void)
{
	char starstr[MAX_STARS];
	struct cpu_hist *hist;
	int i, j;

	/* clear screen */
	printf("\033[2J");

	for (j = 0; j < MAX_CPU; j++) {
		hist = &cpu_hist[j];

		/* ignore CPUs without data (maybe offline?) */
		if (hist->max == 0)
			continue;

		printf("CPU %d\n", j);
		printf("      latency        : count     distribution\n");
		for (i = 1; i <= MAX_ENTRIES; i++) {
			stars(starstr, hist->data[i - 1], hist->max, MAX_STARS);
			printf("%8ld -> %-8ld : %-8ld |%-*s|\n",
				(1l << i) >> 1, (1l << i) - 1,
				hist->data[i - 1], MAX_STARS, starstr);
		}
	}
}

__attribute__((used)) static void get_data(int fd)
{
	long key, value;
	int c, i;

	for (i = 0; i < MAX_CPU; i++)
		cpu_hist[i].max = 0;

	for (c = 0; c < MAX_CPU; c++) {
		for (i = 0; i < MAX_ENTRIES; i++) {
			key = c * MAX_ENTRIES + i;
			bpf_map_lookup_elem(fd, &key, &value);

			cpu_hist[c].data[i] = value;
			if (value > cpu_hist[c].max)
				cpu_hist[c].max = value;
		}
	}
}

int main(int argc, char **argv)
{
	char filename[256];

	snprintf(filename, sizeof(filename), "%s_kern.o", argv[0]);

	if (load_bpf_file(filename)) {
		printf("%s", bpf_log_buf);
		return 1;
	}

	while (1) {
		get_data(map_fd[1]);
		print_hist();
		sleep(5);
	}

	return 0;
}

