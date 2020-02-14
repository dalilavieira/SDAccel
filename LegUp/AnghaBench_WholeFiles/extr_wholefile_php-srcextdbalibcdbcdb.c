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
typedef  unsigned int uint32 ;
struct cdb {unsigned int loop; unsigned int hslots; unsigned int hpos; unsigned int khash; unsigned int kpos; unsigned int dlen; unsigned int dpos; int /*<<< orphan*/ * fp; } ;
typedef  int /*<<< orphan*/  php_stream ;
typedef  int /*<<< orphan*/  buf ;

/* Variables and functions */
 unsigned int CDB_HASHSTART ; 
 scalar_t__ EINTR ; 
 scalar_t__ EPROTO ; 
 int /*<<< orphan*/  SEEK_SET ; 
 int cdb_read (struct cdb*,char*,unsigned int,unsigned int) ; 
 scalar_t__ errno ; 
 scalar_t__ memcmp (char*,char*,unsigned int) ; 
 int php_stream_read (int /*<<< orphan*/ *,char*,unsigned int) ; 
 int php_stream_seek (int /*<<< orphan*/ *,unsigned int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  uint32_unpack (char*,unsigned int*) ; 

__attribute__((used)) static int cdb_match(struct cdb *c, char *key, unsigned int len, uint32 pos)
{
	char buf[32];
	unsigned int n;

	while (len > 0) {
		n = sizeof(buf);
		if (n > len)
			n = len;
		if (cdb_read(c, buf, n, pos) == -1)
			return -1;
		if (memcmp(buf, key, n))
			return 0;
		pos += n;
		key += n;
		len -= n;
	}
	return 1;
}

uint32 cdb_hash(char *buf, unsigned int len)
{
	uint32 h;
	const unsigned char * b = (unsigned char *)buf;

	h = CDB_HASHSTART;
	while (len--) {
		h = ( h + (h << 5)) ^ (*b++);
	}
	return h;
}

void cdb_free(struct cdb *c)
{
}

void cdb_findstart(struct cdb *c)
{
	c->loop = 0;
}

void cdb_init(struct cdb *c, php_stream *fp)
{
	cdb_free(c);
	cdb_findstart(c);
	c->fp = fp;
}

int cdb_read(struct cdb *c, char *buf, unsigned int len, uint32 pos)
{
	if (php_stream_seek(c->fp, pos, SEEK_SET) == -1) {
		errno = EPROTO;
		return -1;
	}
	while (len > 0) {
		int r;
		do {
			r = php_stream_read(c->fp, buf, len);
		} while ((r == -1) && (errno == EINTR));
		if (r == -1)
			return -1;
		if (r == 0) {
			errno = EPROTO;
			return -1;
		}
		buf += r;
		len -= r;
	}
	return 0;
}

int cdb_findnext(struct cdb *c, char *key, unsigned int len)
{
	char buf[8];
	uint32 pos;
	uint32 u;

	if (!c->loop) {
		u = cdb_hash(key, len);
		if (cdb_read(c, buf, 8, (u << 3) & 2047) == -1)
			return -1;
		uint32_unpack(buf + 4,&c->hslots);
		if (!c->hslots)
			return 0;
		uint32_unpack(buf, &c->hpos);
		c->khash = u;
		u >>= 8;
		u %= c->hslots;
		u <<= 3;
		c->kpos = c->hpos + u;
	}

	while (c->loop < c->hslots) {
		if (cdb_read(c, buf, 8, c->kpos) == -1)
			return -1;
		uint32_unpack(buf + 4, &pos);
		if (!pos)
			return 0;
		c->loop += 1;
		c->kpos += 8;
		if (c->kpos == c->hpos + (c->hslots << 3))
			c->kpos = c->hpos;
		uint32_unpack(buf, &u);
		if (u == c->khash) {
			if (cdb_read(c, buf, 8, pos) == -1)
				return -1;
			uint32_unpack(buf, &u);
			if (u == len)
			switch(cdb_match(c, key, len, pos + 8)) {
			case -1:
				return -1;
			case 1:
				uint32_unpack(buf + 4, &c->dlen);
				c->dpos = pos + 8 + len;
				return 1;
			}
		}
	}

	return 0;
}

int cdb_find(struct cdb *c, char *key, unsigned int len)
{
	cdb_findstart(c);
	return cdb_findnext(c, key, len);
}

char *cdb_version()
{
	return "0.75, $Id$";
}

