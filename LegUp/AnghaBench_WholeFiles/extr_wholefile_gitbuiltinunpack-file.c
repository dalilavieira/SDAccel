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
struct object_id {int dummy; } ;
typedef  int /*<<< orphan*/  path ;
typedef  enum object_type { ____Placeholder_object_type } object_type ;

/* Variables and functions */
 int OBJ_BLOB ; 
 int /*<<< orphan*/  close (int) ; 
 int /*<<< orphan*/  die (char*,char const*) ; 
 int /*<<< orphan*/  die_errno (char*) ; 
 scalar_t__ get_oid (char const*,struct object_id*) ; 
 int /*<<< orphan*/  git_config (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  git_default_config ; 
 char const* oid_to_hex (struct object_id*) ; 
 int /*<<< orphan*/  puts (char*) ; 
 void* read_object_file (struct object_id*,int*,unsigned long*) ; 
 int /*<<< orphan*/  strcmp (char const*,char*) ; 
 int /*<<< orphan*/  usage (char*) ; 
 scalar_t__ write_in_full (int,void*,unsigned long) ; 
 int xmkstemp (char*) ; 
 int /*<<< orphan*/  xsnprintf (char*,int,char*) ; 

__attribute__((used)) static char *create_temp_file(struct object_id *oid)
{
	static char path[50];
	void *buf;
	enum object_type type;
	unsigned long size;
	int fd;

	buf = read_object_file(oid, &type, &size);
	if (!buf || type != OBJ_BLOB)
		die("unable to read blob object %s", oid_to_hex(oid));

	xsnprintf(path, sizeof(path), ".merge_file_XXXXXX");
	fd = xmkstemp(path);
	if (write_in_full(fd, buf, size) < 0)
		die_errno("unable to write temp-file");
	close(fd);
	return path;
}

int cmd_unpack_file(int argc, const char **argv, const char *prefix)
{
	struct object_id oid;

	if (argc != 2 || !strcmp(argv[1], "-h"))
		usage("git unpack-file <sha1>");
	if (get_oid(argv[1], &oid))
		die("Not a valid object name %s", argv[1]);

	git_config(git_default_config, NULL);

	puts(create_temp_file(&oid));
	return 0;
}

