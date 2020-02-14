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
typedef  int zip_uint8_t ;
typedef  size_t zip_uint32_t ;
struct zip_string {int* raw; scalar_t__ encoding; size_t length; } ;
struct zip_error {int dummy; } ;
typedef  enum zip_encoding_type { ____Placeholder_zip_encoding_type } zip_encoding_type ;

/* Variables and functions */
 int const UTF_8_CONTINUE_MASK ; 
 int const UTF_8_CONTINUE_MATCH ; 
 int const UTF_8_LEN_2_MASK ; 
 int const UTF_8_LEN_2_MATCH ; 
 int const UTF_8_LEN_3_MASK ; 
 int const UTF_8_LEN_3_MATCH ; 
 int const UTF_8_LEN_4_MASK ; 
 int const UTF_8_LEN_4_MATCH ; 
 int ZIP_ENCODING_ASCII ; 
 int ZIP_ENCODING_CP437 ; 
 int ZIP_ENCODING_ERROR ; 
 scalar_t__ ZIP_ENCODING_UNKNOWN ; 
 int ZIP_ENCODING_UTF8_GUESSED ; 
 int ZIP_ENCODING_UTF8_KNOWN ; 
 int /*<<< orphan*/  ZIP_ER_MEMORY ; 
 size_t* _cp437_to_unicode ; 
 int /*<<< orphan*/  _zip_error_set (struct zip_error*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 scalar_t__ malloc (size_t) ; 
 int tolower (unsigned char) ; 

__attribute__((used)) static inline int __strcasecmp(const char *s1, const char *s2) {
	int c1, c2;
	for(;;) {
		c1 = tolower ( (unsigned char) *s1++ );
		c2 = tolower ( (unsigned char) *s2++ );
		if (c1 == 0 || c1 != c2)
			return c1 - c2;
	}
}

enum zip_encoding_type
_zip_guess_encoding(struct zip_string *str, enum zip_encoding_type expected_encoding)
{
    enum zip_encoding_type enc;
    const zip_uint8_t *name;
    zip_uint32_t i, j, ulen;

    if (str == NULL)
	return ZIP_ENCODING_ASCII;

    name = str->raw;

    if (str->encoding != ZIP_ENCODING_UNKNOWN)
	enc = str->encoding;
    else {
	enc = ZIP_ENCODING_ASCII;
	for (i=0; i<str->length; i++) {
	    if ((name[i] > 31 && name[i] < 128) || name[i] == '\r' || name[i] == '\n' || name[i] == '\t')
		continue;

	    enc = ZIP_ENCODING_UTF8_GUESSED;
	    if ((name[i] & UTF_8_LEN_2_MASK) == UTF_8_LEN_2_MATCH)
		ulen = 1;
	    else if ((name[i] & UTF_8_LEN_3_MASK) == UTF_8_LEN_3_MATCH)
		ulen = 2;
	    else if ((name[i] & UTF_8_LEN_4_MASK) == UTF_8_LEN_4_MATCH)
		ulen = 3;
	    else {
		enc = ZIP_ENCODING_CP437;
		break;
	    }

	    if (i + ulen >= str->length) {
		enc = ZIP_ENCODING_CP437;
		break;
	    }

	    for (j=1; j<=ulen; j++) {
		if ((name[i+j] & UTF_8_CONTINUE_MASK) != UTF_8_CONTINUE_MATCH) {
		    enc = ZIP_ENCODING_CP437;
		    goto done;
		}
	    }
	    i += ulen;
	}
    }

done:
    str->encoding = enc;

    if (expected_encoding != ZIP_ENCODING_UNKNOWN) {
	if (expected_encoding == ZIP_ENCODING_UTF8_KNOWN && enc == ZIP_ENCODING_UTF8_GUESSED)
	    str->encoding = enc = ZIP_ENCODING_UTF8_KNOWN;

	if (expected_encoding != enc && enc != ZIP_ENCODING_ASCII)
	    return ZIP_ENCODING_ERROR;
    }
    
    return enc;
}

__attribute__((used)) static zip_uint32_t
_zip_unicode_to_utf8_len(zip_uint32_t codepoint)
{
    if (codepoint < 0x0080)
	return 1;
    if (codepoint < 0x0800)
	return 2;
    if (codepoint < 0x10000)
	return 3;
    return 4;
}

__attribute__((used)) static zip_uint32_t
_zip_unicode_to_utf8(zip_uint32_t codepoint, zip_uint8_t *buf, int len)
{
    if (codepoint < 0x0080) {
        if (len < 1) {
          return len;
        }
	buf[0] = codepoint & 0xff;
	return 1;
    }
    if (codepoint < 0x0800) {
        if (len < 2) {
          return len;
        }
	buf[0] = UTF_8_LEN_2_MATCH | ((codepoint >> 6) & 0x1f);
	buf[1] = UTF_8_CONTINUE_MATCH | (codepoint & 0x3f);
	return 2;
    }
    if (codepoint < 0x10000) {
        if (len < 3) {
          return len;
        }
	buf[0] = UTF_8_LEN_3_MATCH | ((codepoint >> 12) & 0x0f);
	buf[1] = UTF_8_CONTINUE_MATCH | ((codepoint >> 6) & 0x3f);
	buf[2] = UTF_8_CONTINUE_MATCH | (codepoint & 0x3f);
	return 3;
    }
    if (len < 4) {
      return len;
    }
    buf[0] = UTF_8_LEN_4_MATCH | ((codepoint >> 18) & 0x07);
    buf[1] = UTF_8_CONTINUE_MATCH | ((codepoint >> 12) & 0x3f);
    buf[2] = UTF_8_CONTINUE_MATCH | ((codepoint >> 6) & 0x3f);
    buf[3] = UTF_8_CONTINUE_MATCH | (codepoint & 0x3f);
    return 4;
}

zip_uint8_t *
_zip_cp437_to_utf8(const zip_uint8_t * const _cp437buf, zip_uint32_t len,
		   zip_uint32_t *utf8_lenp, struct zip_error *error)
{
    zip_uint8_t *cp437buf = (zip_uint8_t *)_cp437buf;
    zip_uint8_t *utf8buf;
    zip_uint32_t buflen, i, offset;

    if (len == 0) {
	if (utf8_lenp)
	    *utf8_lenp = 0;
	return NULL;
    }

    buflen = 1;
    for (i=0; i<len; i++)
	buflen += _zip_unicode_to_utf8_len(_cp437_to_unicode[cp437buf[i]]);

    if ((utf8buf=(zip_uint8_t*)malloc(buflen)) == NULL) {
	_zip_error_set(error, ZIP_ER_MEMORY, 0);
	return NULL;
    }

    offset = 0;
    for (i=0; i<len && offset < buflen; i++) {
	offset += _zip_unicode_to_utf8(_cp437_to_unicode[cp437buf[i]],
				       utf8buf+offset, buflen - offset);
   }

    utf8buf[buflen-1] = 0;
    if (utf8_lenp)
	*utf8_lenp = buflen-1;
    return utf8buf;
}

