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
struct strbuf {int dummy; } ;
struct line_buffer {scalar_t__ infile; char* line_buffer; } ;
typedef  scalar_t__ off_t ;
typedef  int /*<<< orphan*/  FILE ;

/* Variables and functions */
 int COPY_BUFFER_LEN ; 
 int /*<<< orphan*/  SEEK_SET ; 
 scalar_t__ buffer_skip_bytes (struct line_buffer*,scalar_t__) ; 
 long error_errno (char*) ; 
 int fclose (scalar_t__) ; 
 scalar_t__ fdopen (int,char*) ; 
 scalar_t__ feof (scalar_t__) ; 
 int ferror (scalar_t__) ; 
 int fgetc (scalar_t__) ; 
 int /*<<< orphan*/  fgets (char*,int,scalar_t__) ; 
 scalar_t__ fopen (char const*,char*) ; 
 scalar_t__ fread (char*,int,size_t,scalar_t__) ; 
 scalar_t__ fseek (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 long ftell (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  fwrite (char*,int,size_t,scalar_t__) ; 
 int /*<<< orphan*/  rewind (scalar_t__) ; 
 scalar_t__ stdin ; 
 scalar_t__ stdout ; 
 size_t strbuf_fread (struct strbuf*,size_t,scalar_t__) ; 
 int strlen (char*) ; 
 scalar_t__ tmpfile () ; 

int buffer_init(struct line_buffer *buf, const char *filename)
{
	buf->infile = filename ? fopen(filename, "r") : stdin;
	if (!buf->infile)
		return -1;
	return 0;
}

int buffer_fdinit(struct line_buffer *buf, int fd)
{
	buf->infile = fdopen(fd, "r");
	if (!buf->infile)
		return -1;
	return 0;
}

int buffer_tmpfile_init(struct line_buffer *buf)
{
	buf->infile = tmpfile();
	if (!buf->infile)
		return -1;
	return 0;
}

int buffer_deinit(struct line_buffer *buf)
{
	int err;
	if (buf->infile == stdin)
		return ferror(buf->infile);
	err = ferror(buf->infile);
	err |= fclose(buf->infile);
	return err;
}

FILE *buffer_tmpfile_rewind(struct line_buffer *buf)
{
	rewind(buf->infile);
	return buf->infile;
}

long buffer_tmpfile_prepare_to_read(struct line_buffer *buf)
{
	long pos = ftell(buf->infile);
	if (pos < 0)
		return error_errno("ftell error");
	if (fseek(buf->infile, 0, SEEK_SET))
		return error_errno("seek error");
	return pos;
}

int buffer_ferror(struct line_buffer *buf)
{
	return ferror(buf->infile);
}

int buffer_read_char(struct line_buffer *buf)
{
	return fgetc(buf->infile);
}

char *buffer_read_line(struct line_buffer *buf)
{
	char *end;
	if (!fgets(buf->line_buffer, sizeof(buf->line_buffer), buf->infile))
		/* Error or data exhausted. */
		return NULL;
	end = buf->line_buffer + strlen(buf->line_buffer);
	if (end[-1] == '\n')
		end[-1] = '\0';
	else if (feof(buf->infile))
		; /* No newline at end of file.  That's fine. */
	else
		/*
		 * Line was too long.
		 * There is probably a saner way to deal with this,
		 * but for now let's return an error.
		 */
		return NULL;
	return buf->line_buffer;
}

size_t buffer_read_binary(struct line_buffer *buf,
				struct strbuf *sb, size_t size)
{
	return strbuf_fread(sb, size, buf->infile);
}

off_t buffer_copy_bytes(struct line_buffer *buf, off_t nbytes)
{
	char byte_buffer[COPY_BUFFER_LEN];
	off_t done = 0;
	while (done < nbytes && !feof(buf->infile) && !ferror(buf->infile)) {
		off_t len = nbytes - done;
		size_t in = len < COPY_BUFFER_LEN ? len : COPY_BUFFER_LEN;
		in = fread(byte_buffer, 1, in, buf->infile);
		done += in;
		fwrite(byte_buffer, 1, in, stdout);
		if (ferror(stdout))
			return done + buffer_skip_bytes(buf, nbytes - done);
	}
	return done;
}

off_t buffer_skip_bytes(struct line_buffer *buf, off_t nbytes)
{
	char byte_buffer[COPY_BUFFER_LEN];
	off_t done = 0;
	while (done < nbytes && !feof(buf->infile) && !ferror(buf->infile)) {
		off_t len = nbytes - done;
		size_t in = len < COPY_BUFFER_LEN ? len : COPY_BUFFER_LEN;
		done += fread(byte_buffer, 1, in, buf->infile);
	}
	return done;
}

