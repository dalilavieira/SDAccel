#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_6__   TYPE_2__ ;
typedef  struct TYPE_5__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  ut8 ;
struct TYPE_5__ {char* chksum; int /*<<< orphan*/  magic; } ;
union record {char* charptr; TYPE_1__ header; } ;
struct TYPE_6__ {int flags; } ;
typedef  TYPE_2__ RMagic ;

/* Variables and functions */
 int /*<<< orphan*/  GNUTMAGIC ; 
 int R_MAGIC_MIME ; 
 int R_MAGIC_MIME_ENCODING ; 
 int /*<<< orphan*/  TMAGIC ; 
 int file_printf (TYPE_2__*,char*) ; 
 scalar_t__ isodigit (char const) ; 
 scalar_t__ isspace (int /*<<< orphan*/ ) ; 
 scalar_t__ strcmp (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 char** tartype ; 

__attribute__((used)) static int from_oct(int digs, const char *where) {
	int value = 0;
	while (isspace ((ut8)*where)) {	/* Skip spaces */
		where++;
		if (--digs <= 0) {
			return -1; /* All blank field */
		}
	}
	while (digs > 0 && isodigit(*where)) {	/* Scan til nonoctal */
		value = (value << 3) | (*where++ - '0');
		--digs;
	}
	if (digs > 0 && *where && !isspace ((ut8)*where)) {
		return -1; /* Ended on non-space/nul */
	}
	return value;
}

__attribute__((used)) static int is_tar(const ut8 *buf, size_t nbytes) {
	const union record *header = (const union record *)(const void *)buf;
	int i, sum, recsum;
	const char *p;

	if (nbytes < sizeof (union record)) {
		return 0;
	}

	recsum = from_oct (8, header->header.chksum);

	sum = 0;
	p = header->charptr;
	for (i = sizeof(union record); --i >= 0;) {
		/*
		 * We cannot use ut8 here because of old compilers,
		 * e.g. V7.
		 */
		sum += 0xFF & *p++;
	}

	/* Adjust checksum to count the "chksum" field as blanks. */
	for (i = sizeof header->header.chksum; --i >= 0;) {
		sum -= 0xFF & header->header.chksum[i];
	}
	sum += ' ' * sizeof header->header.chksum;
	if (sum != recsum) {
		return 0; /* Not a tar archive */
	}
	if (strcmp (header->header.magic, GNUTMAGIC) == 0) {
		return 3; /* GNU Unix Standard tar archive */
	}
	if (strcmp (header->header.magic, TMAGIC) == 0) {
		return 2; /* Unix Standard tar archive */
	}
	return 1;			/* Old fashioned tar archive */
}

int file_is_tar(RMagic *ms, const ut8 *buf, size_t nbytes) {
	/*
	 * Do the tar test first, because if the first file in the tar
	 * archive starts with a dot, we can confuse it with an nroff file.
	 */
	int tar = is_tar(buf, nbytes);
	int mime = ms->flags & R_MAGIC_MIME;

	if (tar < 1 || tar > 3) {
		return 0;
	}
	if (mime == R_MAGIC_MIME_ENCODING) {
		return 0;
	}
	if (file_printf (ms, mime ? "application/x-tar" : tartype[tar - 1]) == -1) {
		return -1;
	}
	return 1;
}

