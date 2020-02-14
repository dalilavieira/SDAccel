#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
typedef  scalar_t__ uint16_t ;
struct mac_font_mapping {scalar_t__ encoding_id; scalar_t__ language_id; char const* code_page; } ;
struct font_path_info {int /*<<< orphan*/  path; int /*<<< orphan*/  face_and_style; int /*<<< orphan*/  sizes; } ;
typedef  scalar_t__ iconv_t ;
struct TYPE_3__ {scalar_t__ platform_id; scalar_t__ encoding_id; scalar_t__ language_id; size_t string_len; scalar_t__ string; } ;
typedef  TYPE_1__ FT_SfntName ;

/* Variables and functions */
 int /*<<< orphan*/  LOG_DEBUG ; 
 int /*<<< orphan*/  LOG_WARNING ; 
 scalar_t__ TT_MAC_LANGID_ANY ; 
#define  TT_PLATFORM_APPLE_UNICODE 131 
#define  TT_PLATFORM_ISO 130 
#define  TT_PLATFORM_MACINTOSH 129 
#define  TT_PLATFORM_MICROSOFT 128 
 int /*<<< orphan*/  bfree (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  blog (int /*<<< orphan*/ ,char*,...) ; 
 char* bstrdup (char*) ; 
 scalar_t__ errno ; 
 size_t iconv (scalar_t__,char**,size_t*,char**,size_t*) ; 
 int /*<<< orphan*/  iconv_close (scalar_t__) ; 
 scalar_t__ iconv_open (char*,char const*) ; 
 scalar_t__ iso_code_count ; 
 char const** iso_codes ; 
 size_t mac_code_count ; 
 struct mac_font_mapping* mac_codes ; 
 scalar_t__ ms_code_count ; 
 char const** ms_codes ; 

__attribute__((used)) static inline void font_path_info_free(struct font_path_info *info)
{
	bfree(info->sizes);
	bfree(info->face_and_style);
	bfree(info->path);
}

__attribute__((used)) static const char *get_mac_code(uint16_t encoding_id, uint16_t language_id)
{
	for (size_t i = 0; i < mac_code_count; i++) {
		const struct mac_font_mapping *mac_code = &mac_codes[i];

		if (mac_code->encoding_id == encoding_id &&
		    mac_code->language_id == language_id)
			return mac_code->code_page;
	}

	return NULL;
}

__attribute__((used)) static const char *get_code_page_for_font(uint16_t platform_id,
		uint16_t encoding_id, uint16_t language_id)
{
	const char *ret;

	switch (platform_id) {
	case TT_PLATFORM_APPLE_UNICODE:
		return "UTF-16BE";
	case TT_PLATFORM_MACINTOSH:
		ret = get_mac_code(encoding_id, language_id);
		if (!ret)
			ret = get_mac_code(encoding_id, TT_MAC_LANGID_ANY);
		return ret;
	case TT_PLATFORM_ISO:
		if (encoding_id < iso_code_count)
			return iso_codes[encoding_id];
		break;
	case TT_PLATFORM_MICROSOFT:
		if (encoding_id < ms_code_count)
			return ms_codes[encoding_id];
		break;
	}

	return NULL;
}

char *sfnt_name_to_utf8(FT_SfntName *sfnt_name)
{
	const char *charset = get_code_page_for_font(sfnt_name->platform_id,
			sfnt_name->encoding_id, sfnt_name->language_id);
	char utf8[256];
	char *conv_in, *conv_out;
	size_t in_len, out_len;

	if (!charset) {
		blog(LOG_DEBUG, "invalid character set found, "
		                "platform_id: %d, encoding_id: %d, "
		                "language_id: %d",
		                sfnt_name->platform_id,
		                sfnt_name->encoding_id,
		                sfnt_name->language_id);
		return NULL;
	}

	iconv_t ic = iconv_open("UTF-8", charset);
	if (ic == (iconv_t)-1) {
		blog(LOG_DEBUG, "couldn't intialize font code page "
				  "conversion:  '%s' to 'utf-8': errno = %d",
				  charset, (int)errno);
		return NULL;
	}

	conv_in  = (char*)sfnt_name->string;
	conv_out = utf8;
	in_len   = sfnt_name->string_len;
	out_len  = 256;

	size_t n = iconv(ic, &conv_in, &in_len, &conv_out, &out_len);
	if (n == (size_t)-1) {
		blog(LOG_WARNING, "couldn't convert font name text: errno = %d",
				(int)errno);
		iconv_close(ic);
		return NULL;
	}

	iconv_close(ic);
	*conv_out = 0;
	return bstrdup(utf8);
}

