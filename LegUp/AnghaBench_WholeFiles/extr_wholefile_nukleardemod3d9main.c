#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_5__   TYPE_2__ ;
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
typedef  scalar_t__ wchar_t ;
struct nk_text_edit {int dummy; } ;
typedef  int /*<<< orphan*/  nk_ushort ;
typedef  int /*<<< orphan*/  nk_uint ;
typedef  int /*<<< orphan*/  nk_short ;
typedef  int /*<<< orphan*/  nk_handle ;
typedef  int nk_byte ;
typedef  int /*<<< orphan*/  matrix ;
struct TYPE_5__ {int /*<<< orphan*/  null; int /*<<< orphan*/  texture; int /*<<< orphan*/  atlas; int /*<<< orphan*/  device; } ;
struct TYPE_4__ {int Pitch; scalar_t__ pBits; } ;
typedef  scalar_t__ SIZE_T ;
typedef  int /*<<< orphan*/  LPCWSTR ;
typedef  int /*<<< orphan*/  HRESULT ;
typedef  scalar_t__ HGLOBAL ;
typedef  TYPE_1__ D3DLOCKED_RECT ;

/* Variables and functions */
 int /*<<< orphan*/  CF_UNICODETEXT ; 
 int /*<<< orphan*/  CP_UTF8 ; 
 int /*<<< orphan*/  CloseClipboard () ; 
 int /*<<< orphan*/  D3DFMT_A8R8G8B8 ; 
 int /*<<< orphan*/  D3DPOOL_DEFAULT ; 
 int /*<<< orphan*/  D3DUSAGE_DYNAMIC ; 
 int /*<<< orphan*/  GMEM_MOVEABLE ; 
 scalar_t__ GetClipboardData (int /*<<< orphan*/ ) ; 
 scalar_t__ GlobalAlloc (int /*<<< orphan*/ ,int) ; 
 scalar_t__ GlobalLock (scalar_t__) ; 
 scalar_t__ GlobalSize (scalar_t__) ; 
 int /*<<< orphan*/  GlobalUnlock (scalar_t__) ; 
 int /*<<< orphan*/  IDirect3DDevice9_CreateTexture (int /*<<< orphan*/ ,int,int,int,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  IDirect3DTexture9_LockRect (int /*<<< orphan*/ ,int /*<<< orphan*/ ,TYPE_1__*,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  IDirect3DTexture9_UnlockRect (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  IsClipboardFormatAvailable (int /*<<< orphan*/ ) ; 
 int MultiByteToWideChar (int /*<<< orphan*/ ,int /*<<< orphan*/ ,char const*,int,scalar_t__*,int) ; 
 int /*<<< orphan*/  NK_ASSERT (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  NK_FONT_ATLAS_RGBA32 ; 
 scalar_t__ OpenClipboard (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  SUCCEEDED (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  SetClipboardData (int /*<<< orphan*/ ,scalar_t__) ; 
 int WideCharToMultiByte (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int,char*,int,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 TYPE_2__ d3d9 ; 
 int /*<<< orphan*/  free (char*) ; 
 scalar_t__ malloc (int) ; 
 int /*<<< orphan*/  memcpy (void*,void*,int) ; 
 void* nk_font_atlas_bake (int /*<<< orphan*/ *,int*,int*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  nk_font_atlas_end (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  nk_handle_ptr (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  nk_textedit_paste (struct nk_text_edit*,char*,int) ; 

__attribute__((used)) static nk_ushort nk_ttUSHORT(const nk_byte *p) { return (nk_ushort)(p[0]*256 + p[1]); }

__attribute__((used)) static nk_short nk_ttSHORT(const nk_byte *p)   { return (nk_short)(p[0]*256 + p[1]); }

__attribute__((used)) static nk_uint nk_ttULONG(const nk_byte *p)  { return (nk_uint)((p[0]<<24) + (p[1]<<16) + (p[2]<<8) + p[3]); }

__attribute__((used)) static void
nk_d3d9_get_projection_matrix(int width, int height, float *result)
{
    const float L = 0.5f;
    const float R = (float)width + 0.5f;
    const float T = 0.5f;
    const float B = (float)height + 0.5f;
    float matrix[4][4] = {
        {    2.0f / (R - L),              0.0f, 0.0f, 0.0f },
        {              0.0f,    2.0f / (T - B), 0.0f, 0.0f },
        {              0.0f,              0.0f, 0.0f, 0.0f },
        { (R + L) / (L - R), (T + B) / (B - T), 0.0f, 1.0f },
    };
    memcpy(result, matrix, sizeof(matrix));
}

__attribute__((used)) static void
nk_d3d9_create_font_texture()
{
    int w, h, y;
    const void *image;

    HRESULT hr;
    D3DLOCKED_RECT locked;

    image = nk_font_atlas_bake(&d3d9.atlas, &w, &h, NK_FONT_ATLAS_RGBA32);

    hr = IDirect3DDevice9_CreateTexture(d3d9.device, w, h, 1, D3DUSAGE_DYNAMIC, D3DFMT_A8R8G8B8, D3DPOOL_DEFAULT, &d3d9.texture, NULL);
    NK_ASSERT(SUCCEEDED(hr));

    hr = IDirect3DTexture9_LockRect(d3d9.texture, 0, &locked, NULL, 0);
    NK_ASSERT(SUCCEEDED(hr));

    for (y = 0; y < h; y++) {
        void *src = (char *)image + y * w * 4;
        void *dst = (char *)locked.pBits + y * locked.Pitch;
        memcpy(dst, src, w * 4);
    }

    hr = IDirect3DTexture9_UnlockRect(d3d9.texture, 0);
    NK_ASSERT(SUCCEEDED(hr));

    nk_font_atlas_end(&d3d9.atlas, nk_handle_ptr(d3d9.texture), &d3d9.null);
}

__attribute__((used)) static void
nk_d3d9_clipboard_paste(nk_handle usr, struct nk_text_edit *edit)
{
    (void)usr;
    if (!IsClipboardFormatAvailable(CF_UNICODETEXT) && OpenClipboard(NULL)) {
        return;
    }

    HGLOBAL mem = GetClipboardData(CF_UNICODETEXT);
    if (!mem) {
        CloseClipboard();
        return;
    }

    SIZE_T size = GlobalSize(mem) - 1;
    if (!size) {
        CloseClipboard();
        return;
    }

    LPCWSTR wstr = (LPCWSTR)GlobalLock(mem);
    if (!wstr) {
        CloseClipboard();
        return;
    }

    int utf8size = WideCharToMultiByte(CP_UTF8, 0, wstr, (int)size / sizeof(wchar_t), NULL, 0, NULL, NULL);
    if (utf8size) {
        char *utf8 = (char *)malloc(utf8size);
        if (utf8) {
            WideCharToMultiByte(CP_UTF8, 0, wstr, (int)size / sizeof(wchar_t), utf8, utf8size, NULL, NULL);
            nk_textedit_paste(edit, utf8, utf8size);
            free(utf8);
        }
    }

    GlobalUnlock(mem); 
    CloseClipboard();
}

__attribute__((used)) static void
nk_d3d9_clipboard_copy(nk_handle usr, const char *text, int len)
{
    (void)usr;
    if (!OpenClipboard(NULL)) {
        return;
    }

    int wsize = MultiByteToWideChar(CP_UTF8, 0, text, len, NULL, 0);
    if (wsize) {
        HGLOBAL mem = GlobalAlloc(GMEM_MOVEABLE, (wsize + 1) * sizeof(wchar_t));
        if (mem) {
            wchar_t *wstr = (wchar_t*)GlobalLock(mem);
            if (wstr) {
                MultiByteToWideChar(CP_UTF8, 0, text, len, wstr, wsize);
                wstr[wsize] = 0;
                GlobalUnlock(mem);
                SetClipboardData(CF_UNICODETEXT, mem); 
            }
        }
    }

    CloseClipboard();
}

