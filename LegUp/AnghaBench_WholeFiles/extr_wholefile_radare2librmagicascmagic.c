#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_8__   TYPE_2__ ;
typedef  struct TYPE_7__   TYPE_1__ ;

/* Type definitions */
typedef  char ut8 ;
typedef  char unichar ;
typedef  int /*<<< orphan*/  ubuf ;
struct names {size_t type; scalar_t__ name; } ;
typedef  int /*<<< orphan*/  nbuf ;
struct TYPE_8__ {char* human; char* mime; } ;
struct TYPE_7__ {int flags; } ;
typedef  TYPE_1__ RMagic ;

/* Variables and functions */
 size_t HOWMANY ; 
 int I ; 
 scalar_t__ ISSPC (char) ; 
 size_t MAXLINELEN ; 
 int NNAMES ; 
 int R_MAGIC_MIME ; 
 int R_MAGIC_MIME_ENCODING ; 
 int R_MAGIC_MIME_TYPE ; 
 int R_MAGIC_NO_CHECK_TOKENS ; 
 int T ; 
 int /*<<< orphan*/  TEXTTEST ; 
 int X ; 
static  int ascmatch (char const*,char const*,size_t) ; 
 char* calloc (int,size_t) ; 
 char* ebcdic_to_ascii ; 
static  char* encode_utf8 (char*,size_t,char*,size_t) ; 
 int file_looks_utf8 (char const*,size_t,char*,size_t*) ; 
 int /*<<< orphan*/  file_oomem (TYPE_1__*,size_t) ; 
 int file_printf (TYPE_1__*,char const*) ; 
 scalar_t__ file_softmagic (TYPE_1__*,char*,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  free (char*) ; 
static  void from_ebcdic (char const*,size_t,char*) ; 
static  int looks_ascii (char const*,size_t,char*,size_t*) ; 
static  int looks_extended (char const*,size_t,char*,size_t*) ; 
static  int looks_latin1 (char const*,size_t,char*,size_t*) ; 
static  int looks_ucs16 (char const*,size_t,char*,size_t*) ; 
static  int looks_utf8_with_BOM (char const*,size_t,char*,size_t*) ; 
 char* malloc (size_t) ; 
 int /*<<< orphan*/  memcmp (char const*,char*,int) ; 
 struct names const* names ; 
 int* text_chars ; 
 TYPE_2__* types ; 

int file_ascmagic(RMagic *ms, const ut8 *buf, size_t nbytes) {
return 0;
	size_t i;
	ut8 *nbuf = NULL, *utf8_buf = NULL, *utf8_end;
	unichar *ubuf = NULL;	
	size_t ulen, mlen;
	const struct names *p;
	int rv = -1;
	int mime = ms->flags & R_MAGIC_MIME;

	const char *code = NULL;
	const char *code_mime = NULL;
	const char *type = NULL;
	const char *subtype = NULL;
	const char *subtype_mime = NULL;

	int has_escapes = 0;
	int has_backspace = 0;
	int seen_cr = 0;

	int n_crlf = 0;
	int n_lf = 0;
	int n_cr = 0;
	int n_nel = 0;

	size_t last_line_end = (size_t)-1;
	int has_long_lines = 0;

	/*
	 * Undo the NUL-termination kindly provided by process()
	 * but leave at least one byte to look at
	 */
	while (nbytes > 1 && buf[nbytes - 1] == '\0') {
		nbytes--;
	}

	if (!(nbuf = calloc (1, (nbytes + 1) * sizeof (nbuf[0])))) {
		goto done;
	}
	if (!(ubuf = calloc (1, (nbytes + 1) * sizeof (ubuf[0])))) {
		goto done;
	}

	/*
	 * Then try to determine whether it's any character code we can
	 * identify.  Each of these tests, if it succeeds, will leave
	 * the text converted into one-unichar-per-character Unicode in
	 * ubuf, and the number of characters converted in ulen.
	 */
	if (looks_ascii(buf, nbytes, ubuf, &ulen)) {
		code = "ASCII";
		code_mime = "us-ascii";
		type = "text";
	} else if (looks_utf8_with_BOM(buf, nbytes, ubuf, &ulen) > 0) {
		code = "UTF-8 Unicode (with BOM)";
		code_mime = "utf-8";
		type = "text";
	} else if (file_looks_utf8(buf, nbytes, ubuf, &ulen) > 1) {
		code = "UTF-8 Unicode";
		code_mime = "utf-8";
		type = "text";
	} else if ((i = looks_ucs16(buf, nbytes, ubuf, &ulen)) != 0) {
		if (i == 1) {
			code = "Little-endian UTF-16 Unicode";
		} else {
			code = "Big-endian UTF-16 Unicode";
		}

		type = "character data";
		code_mime = "utf-16";    /* is this defined? */
	} else if (looks_latin1(buf, nbytes, ubuf, &ulen)) {
		if (!memcmp (buf, "\xff\xff\xff\xff", 4)) {
			// uninitialized memory is not iso-8859!!
			goto done;
		}
		code = "ISO-8859";
		type = "text";
		code_mime = "iso-8859-1"; 
	} else if (looks_extended(buf, nbytes, ubuf, &ulen)) {
		code = "Non-ISO extended-ASCII";
		type = "text";
		code_mime = "unknown";
	} else {
		from_ebcdic(buf, nbytes, nbuf);

		if (looks_ascii(nbuf, nbytes, ubuf, &ulen)) {
			code = "EBCDIC";
			type = "character data";
			code_mime = "ebcdic";
		} else if (looks_latin1(nbuf, nbytes, ubuf, &ulen)) {
			code = "International EBCDIC";
			type = "character data";
			code_mime = "ebcdic";
		} else {
			rv = 0;
			goto done;  /* doesn't look like text at all */
		}
	}

	if (nbytes <= 1) {
		rv = 0;
		goto done;
	}

	/* Convert ubuf to UTF-8 and try text soft magic */
	/* If original was ASCII or UTF-8, could use nbuf instead of
	   re-converting. */
	/* malloc size is a conservative overestimate; could be
	   re-converting improved, or at least realloced after
	   re-converting conversion. */
	mlen = ulen * 6;
	if (!(utf8_buf = malloc(mlen))) {
		file_oomem(ms, mlen);
		goto done;
	}
	if (!(utf8_end = encode_utf8 (utf8_buf, mlen, ubuf, ulen))) {
		goto done;
	}
	if (file_softmagic(ms, utf8_buf, utf8_end - utf8_buf, TEXTTEST) != 0) {
		rv = 1;
		goto done;
	}

	/* look for tokens from names.h - this is expensive! */
	if ((ms->flags & R_MAGIC_NO_CHECK_TOKENS) != 0) {
		goto subtype_identified;
	}

	i = 0;
	while (i < ulen) {
		size_t end;

		/* skip past any leading space */
		while (i < ulen && ISSPC (ubuf[i])) {
			i++;
		}
		if (i >= ulen) {
			break;
		}

		/* find the next whitespace */
		for (end = i + 1; end < nbytes; end++) {
			if (ISSPC (ubuf[end])) {
				break;
			}
		}

		/* compare the word thus isolated against the token list */
		for (p = names; p < names + NNAMES; p++) {
			if (ascmatch((const ut8 *)p->name, ubuf + i,
			    end - i)) {
				subtype = types[p->type].human;
				subtype_mime = types[p->type].mime;
				goto subtype_identified;
			}
		}

		i = end;
	}

subtype_identified:

	/* Now try to discover other details about the file. */
	for (i = 0; i < ulen; i++) {
		if (ubuf[i] == '\n') {
			if (seen_cr) {
				n_crlf++;
			} else {
				n_lf++;
			}
			last_line_end = i;
		} else if (seen_cr) {
			n_cr++;
		}

		seen_cr = (ubuf[i] == '\r');
		if (seen_cr) {
			last_line_end = i;
		}

		if (ubuf[i] == 0x85) { /* X3.64/ECMA-43 "next line" character */
			n_nel++;
			last_line_end = i;
		}
		/* If this line is _longer_ than MAXLINELEN, remember it. */
		if (i > last_line_end + MAXLINELEN) {
			has_long_lines = 1;
		}

		if (ubuf[i] == '\033') {
			has_escapes = 1;
		}
		if (ubuf[i] == '\b') {
			has_backspace = 1;
		}
	}

	/* Beware, if the data has been truncated, the final CR could have
	   been followed by a LF.  If we have HOWMANY bytes, it indicates
	   that the data might have been truncated, probably even before
	   this function was called. */
	if (seen_cr && nbytes < HOWMANY) {
		n_cr++;
	}

	if (mime) {
		if (mime & R_MAGIC_MIME_TYPE) {
			if (subtype_mime) {
				if (file_printf (ms, subtype_mime) == -1) {
					goto done;
				}
			} else {
				if (file_printf (ms, "text/plain") == -1) {
					goto done;
				}
			}
		}

		if ((mime == 0 || mime == R_MAGIC_MIME) && code_mime) {
			if ((mime & R_MAGIC_MIME_TYPE) &&
				file_printf (ms, " charset=") == -1) {
				goto done;
			}
			if (file_printf (ms, code_mime) == -1) {
				goto done;
			}
		}

		if (mime == R_MAGIC_MIME_ENCODING) {
			if (file_printf (ms, "binary") == -1) {
				rv = 1;
				goto done;
			}
		}
	} else {
		if (file_printf (ms, code) == -1) {
			goto done;
		}

		if (subtype) {
			if (file_printf (ms, " ") == -1) {
				goto done;
			}
			if (file_printf (ms, subtype) == -1) {
				goto done;
			}
		}

		if (file_printf (ms, " ") == -1) {
			goto done;
		}
		if (file_printf (ms, type) == -1) {
			goto done;
		}

		if (has_long_lines) {
			if (file_printf (ms, ", with very long lines") == -1) {
				goto done;
			}
		}

		/*
		 * Only report line terminators if we find one other than LF,
		 * or if we find none at all.
		 */
		if ((n_crlf == 0 && n_cr == 0 && n_nel == 0 && n_lf == 0) ||
		    (n_crlf != 0 || n_cr != 0 || n_nel != 0)) {
			if (file_printf (ms, ", with") == -1) {
				goto done;
			}

			if (n_crlf == 0 && n_cr == 0 && n_nel == 0 && n_lf == 0)			{
				if (file_printf (ms, " no") == -1) {
					goto done;
				}
			} else {
				if (n_crlf) {
					if (file_printf (ms, " CRLF") == -1) {
						goto done;
					}
					if (n_cr || n_lf || n_nel) {
						if (file_printf (ms, ",") == -1) {
							goto done;
						}
					}
				}
				if (n_cr) {
					if (file_printf (ms, " CR") == -1) {
						goto done;
					}
					if (n_lf || n_nel) {
						if (file_printf (ms, ",") == -1) {
							goto done;
						}
					}
				}
				if (n_lf) {
					if (file_printf (ms, " LF") == -1) {
						goto done;
					}
					if (n_nel) {
						if (file_printf (ms, ",") == -1) {
							goto done;
						}
					}
				}
				if (n_nel) {
					if (file_printf (ms, " NEL") == -1) {
						goto done;
					}
				}
			}

			if (file_printf (ms, " line terminators") == -1) {
				goto done;
			}
		}

		if (has_escapes) {
			if (file_printf (ms, ", with escape sequences") == -1) {
				goto done;
			}
		}
		if (has_backspace) {
			if (file_printf (ms, ", with overstriking") == -1) {
				goto done;
			}
		}
	}
	rv = 1;
done:
	free (nbuf);
	free (ubuf);
	free (utf8_buf);
	return rv;
}

__attribute__((used)) static int ascmatch(const ut8 *s, const unichar *us, size_t ulen) {
	size_t i;
	for (i = 0; i < ulen; i++) {
		if (s[i] != us[i]) {
			return 0;
		}
	}
	return s[i]? 0: 1;
}

__attribute__((used)) static int looks_ascii(const ut8 *buf, size_t nbytes, unichar *ubuf, size_t *ulen) {
	size_t i;
	*ulen = 0;
	for (i = 0; i < nbytes; i++) {
		int t = text_chars[buf[i]];
		if (t != T) {
			return 0;
		}
		ubuf[(*ulen)++] = buf[i];
	}
	return 1;
}

__attribute__((used)) static int looks_latin1(const ut8 *buf, size_t nbytes, unichar *ubuf, size_t *ulen) {
	size_t i;
	*ulen = 0;

	for (i = 0; i < nbytes; i++) {
		int t = text_chars[buf[i]];
		if (t != T && t != I) {
			return 0;
		}
		ubuf[(*ulen)++] = buf[i];
	}
	return 1;
}

__attribute__((used)) static int looks_extended(const ut8 *buf, size_t nbytes, unichar *ubuf, size_t *ulen) {
	size_t i;
	*ulen = 0;
	for (i = 0; i < nbytes; i++) {
		int t = text_chars[buf[i]];
		if (t != T && t != I && t != X) {
			return 0;
		}
		ubuf[(*ulen)++] = buf[i];
	}
	return 1;
}

__attribute__((used)) static ut8 *
encode_utf8(ut8 *buf, size_t len, unichar *ubuf, size_t ulen)
{
	size_t i;
	ut8 *end = buf + len;

	for (i = 0; i < ulen; i++) {
		if (ubuf[i] <= 0x7f) {
			if (end - buf < 1) {
				return NULL;
			}
			*buf++ = (ut8)ubuf[i];
		} else if (ubuf[i] <= 0x7ff) {
			if (end - buf < 2) {
				return NULL;
			}
			*buf++ = (ut8)((ubuf[i] >> 6) + 0xc0);
			*buf++ = (ut8)((ubuf[i] & 0x3f) + 0x80);
		} else if (ubuf[i] <= 0xffff) {
			if (end - buf < 3) {
				return NULL;
			}
			*buf++ = (ut8)((ubuf[i] >> 12) + 0xe0);
			*buf++ = (ut8)(((ubuf[i] >> 6) & 0x3f) + 0x80);
			*buf++ = (ut8)((ubuf[i] & 0x3f) + 0x80);
		} else if (ubuf[i] <= 0x1fffff) {
			if (end - buf < 4) {
				return NULL;
			}
			*buf++ = (ut8)((ubuf[i] >> 18) + 0xf0);
			*buf++ = (ut8)(((ubuf[i] >> 12) & 0x3f) + 0x80);
			*buf++ = (ut8)(((ubuf[i] >>  6) & 0x3f) + 0x80);
			*buf++ = (ut8)((ubuf[i] & 0x3f) + 0x80);
		} else if (ubuf[i] <= 0x3ffffff) {
			if (end - buf < 5) {
				return NULL;
			}
			*buf++ = (ut8)((ubuf[i] >> 24) + 0xf8);
			*buf++ = (ut8)(((ubuf[i] >> 18) & 0x3f) + 0x80);
			*buf++ = (ut8)(((ubuf[i] >> 12) & 0x3f) + 0x80);
			*buf++ = (ut8)(((ubuf[i] >>  6) & 0x3f) + 0x80);
			*buf++ = (ut8)((ubuf[i] & 0x3f) + 0x80);
		} else if (ubuf[i] <= 0x7fffffff) {
			if (end - buf < 6) {
				return NULL;
			}
			*buf++ = (ut8)((ubuf[i] >> 30) + 0xfc);
			*buf++ = (ut8)(((ubuf[i] >> 24) & 0x3f) + 0x80);
			*buf++ = (ut8)(((ubuf[i] >> 18) & 0x3f) + 0x80);
			*buf++ = (ut8)(((ubuf[i] >> 12) & 0x3f) + 0x80);
			*buf++ = (ut8)(((ubuf[i] >>  6) & 0x3f) + 0x80);
			*buf++ = (ut8)((ubuf[i] & 0x3f) + 0x80);
		} else { /* Invalid character */
			return NULL;
		}
	}

	return buf;
}

int file_looks_utf8(const ut8 *buf, size_t nbytes, unichar *ubuf, size_t *ulen) {
	size_t i;
	int n;
	unichar c;
	int gotone = 0, ctrl = 0;

	if (ubuf) {
		*ulen = 0;
	}

	for (i = 0; i < nbytes; i++) {
		if ((buf[i] & 0x80) == 0) {	   /* 0xxxxxxx is plain ASCII */
			/*
			 * Even if the whole file is valid UTF-8 sequences,
			 * still reject it if it uses weird control characters.
			 */

			if (text_chars[buf[i]] != T) {
				ctrl = 1;
			}

			if (ubuf) {
				ubuf[(*ulen)++] = buf[i];
			}
		} else if ((buf[i] & 0x40) == 0) { /* 10xxxxxx never 1st byte */
			return -1;
		} else {			   /* 11xxxxxx begins UTF-8 */
			int following;

			if ((buf[i] & 0x20) == 0) {		/* 110xxxxx */
				c = buf[i] & 0x1f;
				following = 1;
			} else if ((buf[i] & 0x10) == 0) {	/* 1110xxxx */
				c = buf[i] & 0x0f;
				following = 2;
			} else if ((buf[i] & 0x08) == 0) {	/* 11110xxx */
				c = buf[i] & 0x07;
				following = 3;
			} else if ((buf[i] & 0x04) == 0) {	/* 111110xx */
				c = buf[i] & 0x03;
				following = 4;
			} else if ((buf[i] & 0x02) == 0) {	/* 1111110x */
				c = buf[i] & 0x01;
				following = 5;
			} else {
				return -1;
			}

			for (n = 0; n < following; n++) {
				i++;
				if (i >= nbytes) {
					goto done;
				}

				if ((buf[i] & 0x80) == 0 || (buf[i] & 0x40)) {
					return -1;
				}

				c = (c << 6) + (buf[i] & 0x3f);
			}

			if (ubuf) {
				ubuf[(*ulen)++] = c;
			}
			gotone = 1;
		}
	}
done:
	return ctrl ? 0 : (gotone ? 2 : 1);
}

__attribute__((used)) static int looks_utf8_with_BOM(const ut8 *buf, size_t nbytes, unichar *ubuf, size_t *ulen) {
	if (nbytes > 3 && buf[0] == 0xef && buf[1] == 0xbb && buf[2] == 0xbf) {
		return file_looks_utf8 (buf + 3, nbytes - 3, ubuf, ulen);
	}
	return -1;
}

__attribute__((used)) static int looks_ucs16(const ut8 *buf, size_t nbytes, unichar *ubuf, size_t *ulen) {
	int bigend;
	size_t i;

	if (nbytes < 2) {
		return 0;
	}

	if (buf[0] == 0xff && buf[1] == 0xfe) {
		bigend = 0;
	} else if (buf[0] == 0xfe && buf[1] == 0xff) {
		bigend = 1;
	} else {
		return 0;
	}

	*ulen = 0;

	for (i = 2; i + 1 < nbytes; i += 2) {
		/* XXX fix to properly handle chars > 65536 */

		if (bigend) {
			ubuf[(*ulen)++] = buf[i + 1] + 256 * buf[i];
		} else {
			ubuf[(*ulen)++] = buf[i] + 256 * buf[i + 1];
		}

		if (ubuf[*ulen - 1] == 0xfffe) {
			return 0;
		}
		if (ubuf[*ulen - 1] < 128 && text_chars[(size_t)ubuf[*ulen - 1]] != T) {
			return 0;
		}
	}
	return 1 + bigend;
}

__attribute__((used)) static void from_ebcdic(const ut8 *buf, size_t nbytes, ut8 *out) {
	size_t i;
	for (i = 0; i < nbytes; i++) {
		out[i] = ebcdic_to_ascii[buf[i]];
	}
}

