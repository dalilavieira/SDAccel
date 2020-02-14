#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_13__   TYPE_3__ ;
typedef  struct TYPE_12__   TYPE_2__ ;
typedef  struct TYPE_11__   TYPE_1__ ;

/* Type definitions */
typedef  int wchar_t ;
typedef  int /*<<< orphan*/  uint32_t ;
typedef  scalar_t__ uint16_t ;
struct mac_font_mapping {scalar_t__ encoding_id; scalar_t__ language_id; unsigned int code_page; } ;
struct font_path_info {char* sizes; char* face_and_style; char* path; } ;
struct dstr {char* array; int len; int /*<<< orphan*/  member_0; } ;
struct TYPE_11__ {char ftLastWriteTime; char* cFileName; int dwFileAttributes; } ;
typedef  TYPE_1__ WIN32_FIND_DATAA ;
struct TYPE_13__ {scalar_t__ num_faces; } ;
struct TYPE_12__ {int string_len; scalar_t__ platform_id; scalar_t__ encoding_id; scalar_t__ language_id; int /*<<< orphan*/ * string; } ;
typedef  scalar_t__ HRESULT ;
typedef  scalar_t__ HANDLE ;
typedef  TYPE_2__ FT_SfntName ;
typedef  scalar_t__ FT_Long ;
typedef  TYPE_3__* FT_Face ;
typedef  scalar_t__ FT_Error ;
typedef  int /*<<< orphan*/  FILETIME ;

/* Variables and functions */
 int /*<<< orphan*/  CP_UTF8 ; 
 int /*<<< orphan*/  CSIDL_FONTS ; 
 int FILE_ATTRIBUTE_DIRECTORY ; 
 int /*<<< orphan*/  FT_Done_Face (TYPE_3__*) ; 
 scalar_t__ FT_New_Face (int /*<<< orphan*/ ,char*,scalar_t__,TYPE_3__**) ; 
 int /*<<< orphan*/  FindClose (scalar_t__) ; 
 scalar_t__ FindFirstFileA (char*,TYPE_1__*) ; 
 scalar_t__ FindNextFileA (scalar_t__,TYPE_1__*) ; 
 scalar_t__ INVALID_HANDLE_VALUE ; 
 int /*<<< orphan*/  LOG_WARNING ; 
 int /*<<< orphan*/  MAX_PATH ; 
 size_t MultiByteToWideChar (unsigned int,int /*<<< orphan*/ ,char*,int,int*,int) ; 
 int /*<<< orphan*/  SHGFP_TYPE_CURRENT ; 
 scalar_t__ SHGetFolderPathA (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/ ,char*) ; 
 scalar_t__ S_OK ; 
 scalar_t__ TT_MAC_LANGID_ANY ; 
#define  TT_PLATFORM_APPLE_UNICODE 131 
#define  TT_PLATFORM_ISO 130 
#define  TT_PLATFORM_MACINTOSH 129 
#define  TT_PLATFORM_MICROSOFT 128 
 scalar_t__ WideCharToMultiByte (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int const*,int,char*,int,int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  bfree (char*) ; 
 int /*<<< orphan*/  blog (int /*<<< orphan*/ ,char*) ; 
 int /*<<< orphan*/  build_font_path_info (TYPE_3__*,int /*<<< orphan*/ ,char*) ; 
 char* bzalloc (size_t) ; 
 int /*<<< orphan*/  calc_crc32 (int /*<<< orphan*/ ,char*,int) ; 
 int /*<<< orphan*/  dstr_cat (struct dstr*,char*) ; 
 int /*<<< orphan*/  dstr_copy_dstr (struct dstr*,struct dstr*) ; 
 int /*<<< orphan*/  dstr_free (struct dstr*) ; 
 int /*<<< orphan*/  dstr_reserve (struct dstr*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  dstr_resize (struct dstr*,int) ; 
 int /*<<< orphan*/  free (int*) ; 
 int /*<<< orphan*/  ft2_lib ; 
 scalar_t__ iso_code_count ; 
 unsigned int* iso_codes ; 
 size_t mac_code_count ; 
 struct mac_font_mapping* mac_codes ; 
 int* malloc (size_t) ; 
 scalar_t__ ms_code_count ; 
 unsigned int* ms_codes ; 
 int /*<<< orphan*/  save_font_list () ; 
 int strlen (char*) ; 

__attribute__((used)) static inline void font_path_info_free(struct font_path_info *info)
{
	bfree(info->sizes);
	bfree(info->face_and_style);
	bfree(info->path);
}

__attribute__((used)) static unsigned int get_mac_code(uint16_t encoding_id, uint16_t language_id)
{
	for (size_t i = 0; i < mac_code_count; i++) {
		const struct mac_font_mapping *mac_code = &mac_codes[i];

		if (mac_code->encoding_id == encoding_id &&
		    mac_code->language_id == language_id)
			return mac_code->code_page;
	}

	return 0;
}

__attribute__((used)) static unsigned int get_code_page_for_font(uint16_t platform_id,
		uint16_t encoding_id, uint16_t language_id)
{
	unsigned int ret;

	switch (platform_id) {
	case TT_PLATFORM_APPLE_UNICODE:
		return 1201;
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

	return 0;
}

__attribute__((used)) static char *wide_to_utf8(const wchar_t *str, size_t len)
{
	size_t utf8_len;
	char   *utf8_str = NULL;

	utf8_len = (size_t)WideCharToMultiByte(CP_UTF8, 0, str, (int)len,
			NULL, 0, NULL, false);
	if (utf8_len) {
		utf8_str = bzalloc(utf8_len + 1);
		utf8_len = (size_t)WideCharToMultiByte(CP_UTF8, 0,
				str, (int)len,
				utf8_str, (int)utf8_len + 1, NULL, false);

		if (!utf8_len) {
			bfree(utf8_str);
			utf8_str = NULL;
		}
	}

	return utf8_str;
}

__attribute__((used)) static char *convert_utf16_be_to_utf8(FT_SfntName *sfnt_name)
{
	size_t  utf16_len  = sfnt_name->string_len / 2;
	wchar_t *utf16_str = malloc((utf16_len + 1) * sizeof(wchar_t));
	char    *utf8_str  = NULL;

	utf16_str[utf16_len] = 0;

	/* convert to little endian */
	for (size_t i = 0; i < utf16_len; i++) {
		size_t  pos = i * 2;
		wchar_t ch  = *(wchar_t *)&sfnt_name->string[pos];

		utf16_str[i] = ((ch >> 8) & 0xFF) | ((ch << 8) & 0xFF00);
	}

	utf8_str = wide_to_utf8(utf16_str, utf16_len);

	free(utf16_str);
	return utf8_str;
}

char *sfnt_name_to_utf8(FT_SfntName *sfnt_name)
{
	unsigned int code_page = get_code_page_for_font(
			sfnt_name->platform_id,
			sfnt_name->encoding_id,
			sfnt_name->language_id);

	char    *utf8_str = NULL;
	wchar_t *utf16_str;
	size_t  utf16_len;

	if (code_page == 1201)
		return convert_utf16_be_to_utf8(sfnt_name);
	else if (code_page == 0)
		return NULL;

	utf16_len = MultiByteToWideChar(code_page, 0,
			(char*)sfnt_name->string, sfnt_name->string_len,
			NULL, 0);
	if (utf16_len) {
		utf16_str = malloc((utf16_len + 1) * sizeof(wchar_t));
		utf16_len = MultiByteToWideChar(code_page, 0,
				(char*)sfnt_name->string, sfnt_name->string_len,
				utf16_str, (int)utf16_len);

		if (utf16_len) {
			utf16_str[utf16_len] = 0;
			utf8_str = wide_to_utf8(utf16_str, utf16_len);
		}

		free(utf16_str);
	}

	return utf8_str;
}

uint32_t get_font_checksum(void)
{
	uint32_t         checksum = 0;
	struct dstr      path = {0};
	HANDLE           handle;
	WIN32_FIND_DATAA wfd;

	dstr_reserve(&path, MAX_PATH);

	HRESULT res = SHGetFolderPathA(NULL, CSIDL_FONTS, NULL,
			SHGFP_TYPE_CURRENT, path.array);
	if (res != S_OK) {
		blog(LOG_WARNING, "Error finding windows font folder");
		return 0;
	}

	path.len = strlen(path.array);
	dstr_cat(&path, "\\*.*");

	handle = FindFirstFileA(path.array, &wfd);
	if (handle == INVALID_HANDLE_VALUE)
		goto free_string;

	dstr_resize(&path, path.len - 4);

	do {
		checksum = calc_crc32(checksum, &wfd.ftLastWriteTime,
				sizeof(FILETIME));
		checksum = calc_crc32(checksum, wfd.cFileName,
				strlen(wfd.cFileName));
	} while (FindNextFileA(handle, &wfd));

	FindClose(handle);

free_string:
	dstr_free(&path);
	return checksum;
}

void load_os_font_list(void)
{
	struct dstr      path = {0};
	HANDLE           handle;
	WIN32_FIND_DATAA wfd;

	dstr_reserve(&path, MAX_PATH);

	HRESULT res = SHGetFolderPathA(NULL, CSIDL_FONTS, NULL,
			SHGFP_TYPE_CURRENT, path.array);
	if (res != S_OK) {
		blog(LOG_WARNING, "Error finding windows font folder");
		return;
	}

	path.len = strlen(path.array);
	dstr_cat(&path, "\\*.*");

	handle = FindFirstFileA(path.array, &wfd);
	if (handle == INVALID_HANDLE_VALUE)
		goto free_string;

	dstr_resize(&path, path.len - 4);

	do {
		struct dstr full_path = {0};
		FT_Face face;
		FT_Long idx = 0;
		FT_Long max_faces = 1;

		if (wfd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)
			continue;

		dstr_copy_dstr(&full_path, &path);
		dstr_cat(&full_path, "\\");
		dstr_cat(&full_path, wfd.cFileName);

		while (idx < max_faces) {
			FT_Error ret = FT_New_Face(ft2_lib, full_path.array,
					idx, &face);
			if (ret != 0)
				break;

			build_font_path_info(face, idx++, full_path.array);
			max_faces = face->num_faces;
			FT_Done_Face(face);
		}

		dstr_free(&full_path);
	} while (FindNextFileA(handle, &wfd));

	FindClose(handle);

	save_font_list();

free_string:
	dstr_free(&path);
}

