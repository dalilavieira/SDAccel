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
typedef  int /*<<< orphan*/  swirr ;
struct gpiohandle_data {int* values; } ;

/* Variables and functions */
 int GPIOHANDLES_MAX ; 
 int /*<<< orphan*/  GPIOHANDLE_REQUEST_OUTPUT ; 
 int /*<<< orphan*/  fflush (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  fprintf (int /*<<< orphan*/ ,char*,...) ; 
 int getopt (int,char**,char*) ; 
 int gpiotools_get_values (int,struct gpiohandle_data*) ; 
 int /*<<< orphan*/  gpiotools_release_linehandle (int) ; 
 int gpiotools_request_linehandle (char const*,unsigned int*,int,int /*<<< orphan*/ ,struct gpiohandle_data*,char*) ; 
 int gpiotools_set_values (int,struct gpiohandle_data*) ; 
 int /*<<< orphan*/  memset (int**,int /*<<< orphan*/ ,int) ; 
 char* optarg ; 
 int /*<<< orphan*/  sleep (int) ; 
 int /*<<< orphan*/  stderr ; 
 int /*<<< orphan*/  stdout ; 
 scalar_t__ strlen (char const*) ; 
 scalar_t__ strncmp (char const*,char const*,scalar_t__) ; 
 unsigned int strtoul (char*,int /*<<< orphan*/ *,int) ; 

__attribute__((used)) static inline int check_prefix(const char *str, const char *prefix)
{
	return strlen(str) > strlen(prefix) &&
		strncmp(str, prefix, strlen(prefix)) == 0;
}

int hammer_device(const char *device_name, unsigned int *lines, int nlines,
		  unsigned int loops)
{
	struct gpiohandle_data data;
	char swirr[] = "-\\|/";
	int fd;
	int ret;
	int i, j;
	unsigned int iteration = 0;

	memset(&data.values, 0, sizeof(data.values));
	ret = gpiotools_request_linehandle(device_name, lines, nlines,
					   GPIOHANDLE_REQUEST_OUTPUT, &data,
					   "gpio-hammer");
	if (ret < 0)
		goto exit_error;
	else
		fd = ret;

	ret = gpiotools_get_values(fd, &data);
	if (ret < 0)
		goto exit_close_error;

	fprintf(stdout, "Hammer lines [");
	for (i = 0; i < nlines; i++) {
		fprintf(stdout, "%d", lines[i]);
		if (i != (nlines - 1))
			fprintf(stdout, ", ");
	}
	fprintf(stdout, "] on %s, initial states: [", device_name);
	for (i = 0; i < nlines; i++) {
		fprintf(stdout, "%d", data.values[i]);
		if (i != (nlines - 1))
			fprintf(stdout, ", ");
	}
	fprintf(stdout, "]\n");

	/* Hammertime! */
	j = 0;
	while (1) {
		/* Invert all lines so we blink */
		for (i = 0; i < nlines; i++)
			data.values[i] = !data.values[i];

		ret = gpiotools_set_values(fd, &data);
		if (ret < 0)
			goto exit_close_error;

		/* Re-read values to get status */
		ret = gpiotools_get_values(fd, &data);
		if (ret < 0)
			goto exit_close_error;

		fprintf(stdout, "[%c] ", swirr[j]);
		j++;
		if (j == sizeof(swirr)-1)
			j = 0;

		fprintf(stdout, "[");
		for (i = 0; i < nlines; i++) {
			fprintf(stdout, "%d: %d", lines[i], data.values[i]);
			if (i != (nlines - 1))
				fprintf(stdout, ", ");
		}
		fprintf(stdout, "]\r");
		fflush(stdout);
		sleep(1);
		iteration++;
		if (loops && iteration == loops)
			break;
	}
	fprintf(stdout, "\n");
	ret = 0;

exit_close_error:
	gpiotools_release_linehandle(fd);
exit_error:
	return ret;
}

void print_usage(void)
{
	fprintf(stderr, "Usage: gpio-hammer [options]...\n"
		"Hammer GPIO lines, 0->1->0->1...\n"
		"  -n <name>  Hammer GPIOs on a named device (must be stated)\n"
		"  -o <n>     Offset[s] to hammer, at least one, several can be stated\n"
		" [-c <n>]    Do <n> loops (optional, infinite loop if not stated)\n"
		"  -?         This helptext\n"
		"\n"
		"Example:\n"
		"gpio-hammer -n gpiochip0 -o 4\n"
	);
}

int main(int argc, char **argv)
{
	const char *device_name = NULL;
	unsigned int lines[GPIOHANDLES_MAX];
	unsigned int loops = 0;
	int nlines;
	int c;
	int i;

	i = 0;
	while ((c = getopt(argc, argv, "c:n:o:?")) != -1) {
		switch (c) {
		case 'c':
			loops = strtoul(optarg, NULL, 10);
			break;
		case 'n':
			device_name = optarg;
			break;
		case 'o':
			lines[i] = strtoul(optarg, NULL, 10);
			i++;
			break;
		case '?':
			print_usage();
			return -1;
		}
	}
	nlines = i;

	if (!device_name || !nlines) {
		print_usage();
		return -1;
	}
	return hammer_device(device_name, lines, nlines, loops);
}

