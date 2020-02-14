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
typedef  int /*<<< orphan*/  value ;

/* Variables and functions */
 char* MICSYSFSDIR ; 
 int /*<<< orphan*/  O_RDONLY ; 
 int /*<<< orphan*/  O_RDWR ; 
 int PAGE_SIZE ; 
 int PATH_MAX ; 
 int /*<<< orphan*/  close (int) ; 
 int errno ; 
 int /*<<< orphan*/  free (char*) ; 
 char* malloc (scalar_t__) ; 
 int /*<<< orphan*/  mpsslog (char*,char*,int /*<<< orphan*/ ) ; 
 int open (char*,int /*<<< orphan*/ ) ; 
 int read (int,char*,int) ; 
 int /*<<< orphan*/  snprintf (char*,int,char*,char*,char*,...) ; 
 scalar_t__ strcmp (char*,char*) ; 
 int /*<<< orphan*/  strcpy (char*,char*) ; 
 int /*<<< orphan*/  strerror (int) ; 
 scalar_t__ strlen (char*) ; 
 scalar_t__ write (int,char*,scalar_t__) ; 

char *
readsysfs(char *dir, char *entry)
{
	char filename[PATH_MAX];
	char value[PAGE_SIZE];
	char *string = NULL;
	int fd;
	int len;

	if (dir == NULL)
		snprintf(filename, PATH_MAX, "%s/%s", MICSYSFSDIR, entry);
	else
		snprintf(filename, PATH_MAX,
			 "%s/%s/%s", MICSYSFSDIR, dir, entry);

	fd = open(filename, O_RDONLY);
	if (fd < 0) {
		mpsslog("Failed to open sysfs entry '%s': %s\n",
			filename, strerror(errno));
		return NULL;
	}

	len = read(fd, value, sizeof(value));
	if (len < 0) {
		mpsslog("Failed to read sysfs entry '%s': %s\n",
			filename, strerror(errno));
		goto readsys_ret;
	}
	if (len == 0)
		goto readsys_ret;

	value[len - 1] = '\0';

	string = malloc(strlen(value) + 1);
	if (string)
		strcpy(string, value);

readsys_ret:
	close(fd);
	return string;
}

int
setsysfs(char *dir, char *entry, char *value)
{
	char filename[PATH_MAX];
	char *oldvalue;
	int fd, ret = 0;

	if (dir == NULL)
		snprintf(filename, PATH_MAX, "%s/%s", MICSYSFSDIR, entry);
	else
		snprintf(filename, PATH_MAX, "%s/%s/%s",
			 MICSYSFSDIR, dir, entry);

	oldvalue = readsysfs(dir, entry);

	fd = open(filename, O_RDWR);
	if (fd < 0) {
		ret = errno;
		mpsslog("Failed to open sysfs entry '%s': %s\n",
			filename, strerror(errno));
		goto done;
	}

	if (!oldvalue || strcmp(value, oldvalue)) {
		if (write(fd, value, strlen(value)) < 0) {
			ret = errno;
			mpsslog("Failed to write new sysfs entry '%s': %s\n",
				filename, strerror(errno));
		}
	}
	close(fd);
done:
	if (oldvalue)
		free(oldvalue);
	return ret;
}

