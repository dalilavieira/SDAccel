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
typedef  int /*<<< orphan*/  uintmax_t ;
typedef  void* uint32_t ;
struct strbuf {int /*<<< orphan*/  len; int /*<<< orphan*/  buf; } ;
struct line_buffer {int dummy; } ;

/* Variables and functions */
 struct line_buffer LINE_BUFFER_INIT ; 
 struct strbuf STRBUF_INIT ; 
 int /*<<< orphan*/  buffer_copy_bytes (struct line_buffer*,void*) ; 
 scalar_t__ buffer_deinit (struct line_buffer*) ; 
 scalar_t__ buffer_fdinit (struct line_buffer*,void*) ; 
 scalar_t__ buffer_init (struct line_buffer*,char const*) ; 
 int /*<<< orphan*/  buffer_read_binary (struct line_buffer*,struct strbuf*,void*) ; 
 char* buffer_read_line (struct line_buffer*) ; 
 int /*<<< orphan*/  buffer_skip_bytes (struct line_buffer*,void*) ; 
 int /*<<< orphan*/  die (char*,...) ; 
 int /*<<< orphan*/  die_errno (char*,...) ; 
 scalar_t__ ferror (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  fwrite (int /*<<< orphan*/ ,int,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 scalar_t__ starts_with (char const*,char*) ; 
 int /*<<< orphan*/  stdout ; 
 int /*<<< orphan*/  strbuf_addch (struct strbuf*,char) ; 
 int /*<<< orphan*/  strbuf_release (struct strbuf*) ; 
 char* strchr (char const*,char) ; 
 int /*<<< orphan*/  strtoumax (char const*,char**,int) ; 
 int /*<<< orphan*/  usage (char*) ; 

__attribute__((used)) static uint32_t strtouint32(const char *s)
{
	char *end;
	uintmax_t n = strtoumax(s, &end, 10);
	if (*s == '\0' || *end != '\0')
		die("invalid count: %s", s);
	return (uint32_t) n;
}

__attribute__((used)) static void handle_command(const char *command, const char *arg, struct line_buffer *buf)
{
	if (starts_with(command, "binary ")) {
		struct strbuf sb = STRBUF_INIT;
		strbuf_addch(&sb, '>');
		buffer_read_binary(buf, &sb, strtouint32(arg));
		fwrite(sb.buf, 1, sb.len, stdout);
		strbuf_release(&sb);
	} else if (starts_with(command, "copy ")) {
		buffer_copy_bytes(buf, strtouint32(arg));
	} else if (starts_with(command, "skip ")) {
		buffer_skip_bytes(buf, strtouint32(arg));
	} else {
		die("unrecognized command: %s", command);
	}
}

__attribute__((used)) static void handle_line(const char *line, struct line_buffer *stdin_buf)
{
	const char *arg = strchr(line, ' ');
	if (!arg)
		die("no argument in line: %s", line);
	handle_command(line, arg + 1, stdin_buf);
}

int cmd_main(int argc, const char **argv)
{
	struct line_buffer stdin_buf = LINE_BUFFER_INIT;
	struct line_buffer file_buf = LINE_BUFFER_INIT;
	struct line_buffer *input = &stdin_buf;
	const char *filename;
	char *s;

	if (argc == 1)
		filename = NULL;
	else if (argc == 2)
		filename = argv[1];
	else
		usage("test-line-buffer [file | &fd] < script");

	if (buffer_init(&stdin_buf, NULL))
		die_errno("open error");
	if (filename) {
		if (*filename == '&') {
			if (buffer_fdinit(&file_buf, strtouint32(filename + 1)))
				die_errno("error opening fd %s", filename + 1);
		} else {
			if (buffer_init(&file_buf, filename))
				die_errno("error opening %s", filename);
		}
		input = &file_buf;
	}

	while ((s = buffer_read_line(&stdin_buf)))
		handle_line(s, input);

	if (filename && buffer_deinit(&file_buf))
		die("error reading from %s", filename);
	if (buffer_deinit(&stdin_buf))
		die("input error");
	if (ferror(stdout))
		die("output error");
	return 0;
}

