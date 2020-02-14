#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_15__   TYPE_2__ ;
typedef  struct TYPE_14__   TYPE_1__ ;

/* Type definitions */
struct stat {size_t st_size; } ;
struct TYPE_14__ {int start; int end; int /*<<< orphan*/  type; } ;
typedef  TYPE_1__ jsmntok_t ;
typedef  scalar_t__ jsmnerr_t ;
struct TYPE_15__ {int toknext; } ;
typedef  TYPE_2__ jsmn_parser ;

/* Variables and functions */
 scalar_t__ JSMN_SUCCESS ; 
 char const* LOOKUP (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 char* MAP_FAILED ; 
 int /*<<< orphan*/  MAP_PRIVATE ; 
 int /*<<< orphan*/  O_RDONLY ; 
 int PROT_READ ; 
 int PROT_WRITE ; 
 int /*<<< orphan*/  _SC_PAGESIZE ; 
 int /*<<< orphan*/  close (int) ; 
 int /*<<< orphan*/  errno ; 
 int /*<<< orphan*/  free (TYPE_1__*) ; 
 int fstat (int,struct stat*) ; 
 int /*<<< orphan*/  jsmn_init (TYPE_2__*) ; 
 scalar_t__ jsmn_parse (TYPE_2__*,char*,size_t,TYPE_1__*,unsigned int) ; 
 int /*<<< orphan*/  jsmn_strerror (scalar_t__) ; 
 int /*<<< orphan*/  jsmn_types ; 
 TYPE_1__* malloc (unsigned int) ; 
 char* mmap (int /*<<< orphan*/ *,unsigned int,int,int /*<<< orphan*/ ,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  munmap (char*,int /*<<< orphan*/ ) ; 
 int open (char const*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  pr_err (char*,char const*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  roundup (size_t,unsigned int) ; 
 int /*<<< orphan*/  strerror (int /*<<< orphan*/ ) ; 
 unsigned int strlen (char const*) ; 
 int /*<<< orphan*/  strncasecmp (char*,char const*,unsigned int) ; 
 unsigned int sysconf (int /*<<< orphan*/ ) ; 
 scalar_t__ verbose ; 

__attribute__((used)) static char *mapfile(const char *fn, size_t *size)
{
	unsigned ps = sysconf(_SC_PAGESIZE);
	struct stat st;
	char *map = NULL;
	int err;
	int fd = open(fn, O_RDONLY);

	if (fd < 0 && verbose > 0 && fn) {
		pr_err("Error opening events file '%s': %s\n", fn,
				strerror(errno));
	}

	if (fd < 0)
		return NULL;
	err = fstat(fd, &st);
	if (err < 0)
		goto out;
	*size = st.st_size;
	map = mmap(NULL,
		   (st.st_size + ps - 1) & ~(ps - 1),
		   PROT_READ|PROT_WRITE, MAP_PRIVATE, fd, 0);
	if (map == MAP_FAILED)
		map = NULL;
out:
	close(fd);
	return map;
}

__attribute__((used)) static void unmapfile(char *map, size_t size)
{
	unsigned ps = sysconf(_SC_PAGESIZE);
	munmap(map, roundup(size, ps));
}

jsmntok_t *parse_json(const char *fn, char **map, size_t *size, int *len)
{
	jsmn_parser parser;
	jsmntok_t *tokens;
	jsmnerr_t res;
	unsigned sz;

	*map = mapfile(fn, size);
	if (!*map)
		return NULL;
	/* Heuristic */
	sz = *size * 16;
	tokens = malloc(sz);
	if (!tokens)
		goto error;
	jsmn_init(&parser);
	res = jsmn_parse(&parser, *map, *size, tokens,
			 sz / sizeof(jsmntok_t));
	if (res != JSMN_SUCCESS) {
		pr_err("%s: json error %s\n", fn, jsmn_strerror(res));
		goto error_free;
	}
	if (len)
		*len = parser.toknext;
	return tokens;
error_free:
	free(tokens);
error:
	unmapfile(*map, *size);
	return NULL;
}

void free_json(char *map, size_t size, jsmntok_t *tokens)
{
	free(tokens);
	unmapfile(map, size);
}

__attribute__((used)) static int countchar(char *map, char c, int end)
{
	int i;
	int count = 0;
	for (i = 0; i < end; i++)
		if (map[i] == c)
			count++;
	return count;
}

int json_line(char *map, jsmntok_t *t)
{
	return countchar(map, '\n', t->start) + 1;
}

const char *json_name(jsmntok_t *t)
{
	return LOOKUP(jsmn_types, t->type);
}

int json_len(jsmntok_t *t)
{
	return t->end - t->start;
}

int json_streq(char *map, jsmntok_t *t, const char *s)
{
	unsigned len = json_len(t);
	return len == strlen(s) && !strncasecmp(map + t->start, s, len);
}

