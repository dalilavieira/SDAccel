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
 int BUF_SIZE ; 
 int /*<<< orphan*/  O_RDONLY ; 
 int atoi (char*) ; 
 int /*<<< orphan*/  close (int) ; 
 int open (char*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  read (int,char*,int) ; 

int main(int argc, char *argv[])
{
	int fd = open("/dev/urandom", O_RDONLY);
	int i;
	char buf[BUF_SIZE];
	int count = 4;

	if (fd < 0)
		return 1;

	if (argc == 2)
		count = atoi(argv[1]);

	for (i = 0; i < count; ++i)
		read(fd, buf, BUF_SIZE);

	close(fd);
	return 0;
}

