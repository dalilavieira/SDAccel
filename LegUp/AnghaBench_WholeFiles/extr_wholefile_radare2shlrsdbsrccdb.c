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
typedef  int ut8 ;
typedef  int ut32 ;
struct cdb {int loop; int fd; int hslots; int hpos; int size; int khash; int kpos; int dpos; int /*<<< orphan*/  dlen; int /*<<< orphan*/ * map; } ;
typedef  scalar_t__ off_t ;
typedef  int /*<<< orphan*/  buf ;

/* Variables and functions */
 int KVLSZ ; 
 int /*<<< orphan*/  SEEK_SET ; 
 int /*<<< orphan*/  cdb_getkvlen (struct cdb*,int*,int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  cdb_read (struct cdb*,char*,int const,int) ; 
 int /*<<< orphan*/  free (int /*<<< orphan*/ *) ; 
 int lseek (int,scalar_t__,int /*<<< orphan*/ ) ; 
 scalar_t__ memcmp (char*,char const*,int) ; 

__attribute__((used)) static inline int seek_set(int fd, off_t pos) {
	return ((fd == -1) || (lseek (fd, (off_t) pos, SEEK_SET) == -1))? 0:1;
}

__attribute__((used)) static inline void ut32_pack(char s[4], ut32 u) {
	s[0] = u & 255;
	u >>= 8;
	s[1] = u & 255;
	u >>= 8;
	s[2] = u & 255;
	s[3] = u >> 8;
}

__attribute__((used)) static inline void ut32_pack_big(char s[4], ut32 u) {
	s[3] = u & 255;
	u >>= 8;
	s[2] = u & 255;
	u >>= 8;
	s[1] = u & 255;
	s[0] = u >> 8;
}

__attribute__((used)) static inline void ut32_unpack(char s[4], ut32 *u) {
	ut32 result = 0;
	result = (ut8) s[3];
	result <<= 8;
	result += (ut8) s[2];
	result <<= 8;
	result += (ut8) s[1];
	result <<= 8;
	result += (ut8) s[0];
	*u = result;
}

void cdb_free(struct cdb *c) {
	if (!c->map) {
		return;
	}
#if USE_MMAN
	(void)munmap (c->map, c->size);
#else
	free (c->map);
#endif
	c->map = NULL;
}

void cdb_findstart(struct cdb *c) {
	c->loop = 0;
#if !USE_MMAN
	if (c->fd != -1) {
		lseek (c->fd, 0, SEEK_SET);
	}
#endif
}

__attribute__((used)) static int match(struct cdb *c, const char *key, ut32 len, ut32 pos) {
	char buf[32];
	const size_t szb = sizeof buf;
	while (len > 0) {
		int n = (szb > len)? len: szb;
		if (!cdb_read (c, buf, n, pos)) {
			return -1;
		}
		if (memcmp (buf, key, n)) {
			return 0;
		}
		pos += n;
		key += n;
		len -= n;
	}
	return 1;
}

int cdb_findnext(struct cdb *c, ut32 u, const char *key, ut32 len) {
	char buf[8];
	ut32 pos;
	int m;
	len++;
	if (c->fd == -1) {
		return -1;
	}
	c->hslots = 0;
	if (!c->loop) {
		const int bufsz = ((u + 1) & 0xFF) ? sizeof (buf) : sizeof (buf) / 2;
		if (!cdb_read (c, buf, bufsz, (u << 2) & 1023)) {
			return -1;
		}
		/* hslots = (hpos_next - hpos) / 8 */
		ut32_unpack (buf, &c->hpos);
		if (bufsz == sizeof (buf)) {
			ut32_unpack (buf + 4, &pos);
		} else {
			pos = c->size;
		}
		if (pos < c->hpos) {
			return -1;
		}
		c->hslots = (pos - c->hpos) / (2 * sizeof (ut32));
		if (!c->hslots) {
			return 0;
		}
		c->khash = u;
		u = ((u >> 8) % c->hslots) << 3;
		c->kpos = c->hpos + u;
	}
	while (c->loop < c->hslots) {
		if (!cdb_read (c, buf, sizeof (buf), c->kpos)) {
			return 0;
		}
		ut32_unpack (buf + 4, &pos);
		if (!pos) {
			return 0;
		}
		c->loop++;
		c->kpos += sizeof (buf);
		if (c->kpos == c->hpos + (c->hslots << 3)) {
			c->kpos = c->hpos;
		}
		ut32_unpack (buf, &u);
		if (u == c->khash) {
			if (!cdb_getkvlen (c, &u, &c->dlen, pos) || !u) {
				return -1;
			}
			if (u == len) {
				if ((m = match (c, key, len, pos + KVLSZ)) == -1) {
					return 0;
				}
				if (m == 1) {
					c->dpos = pos + KVLSZ + len;
					return 1;
				}
			}
		}
	}
	return 0;
}

