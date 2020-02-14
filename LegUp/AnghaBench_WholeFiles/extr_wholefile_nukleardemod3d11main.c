#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
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
typedef  int /*<<< orphan*/  desc ;
struct TYPE_4__ {int /*<<< orphan*/  ViewDimension; int /*<<< orphan*/  Format; } ;
typedef  int SIZE_T ;
typedef  scalar_t__ LPCWSTR ;
typedef  int /*<<< orphan*/  ID3D11Texture2D ;
typedef  int /*<<< orphan*/  ID3D11Resource ;
typedef  scalar_t__ HRESULT ;
typedef  scalar_t__ HGLOBAL ;
typedef  TYPE_1__ D3D11_RENDER_TARGET_VIEW_DESC ;

/* Variables and functions */
 int /*<<< orphan*/  CF_UNICODETEXT ; 
 int /*<<< orphan*/  CP_UTF8 ; 
 int /*<<< orphan*/  CloseClipboard () ; 
 int /*<<< orphan*/  D3D11_RTV_DIMENSION_TEXTURE2D ; 
 scalar_t__ DXGI_ERROR_DEVICE_REMOVED ; 
 scalar_t__ DXGI_ERROR_DEVICE_RESET ; 
 scalar_t__ DXGI_ERROR_DRIVER_INTERNAL_ERROR ; 
 int /*<<< orphan*/  DXGI_FORMAT_R8G8B8A8_UNORM ; 
 int /*<<< orphan*/  DXGI_FORMAT_UNKNOWN ; 
 int /*<<< orphan*/  GMEM_MOVEABLE ; 
 scalar_t__ GetClipboardData (int /*<<< orphan*/ ) ; 
 scalar_t__ GlobalAlloc (int /*<<< orphan*/ ,int) ; 
 scalar_t__ GlobalLock (scalar_t__) ; 
 int GlobalSize (scalar_t__) ; 
 int /*<<< orphan*/  GlobalUnlock (scalar_t__) ; 
 int /*<<< orphan*/  ID3D11DeviceContext_OMSetRenderTargets (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 scalar_t__ ID3D11Device_CreateRenderTargetView (int /*<<< orphan*/ ,int /*<<< orphan*/ *,TYPE_1__*,scalar_t__*) ; 
 int /*<<< orphan*/  ID3D11RenderTargetView_Release (scalar_t__) ; 
 int /*<<< orphan*/  ID3D11Texture2D_Release (int /*<<< orphan*/ *) ; 
 scalar_t__ IDXGISwapChain_GetBuffer (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ *,void**) ; 
 scalar_t__ IDXGISwapChain_ResizeBuffers (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int,int,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  IID_ID3D11Texture2D ; 
 scalar_t__ IsClipboardFormatAvailable (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  MessageBoxW (int /*<<< orphan*/ *,char*,char*,int /*<<< orphan*/ ) ; 
 int MultiByteToWideChar (int /*<<< orphan*/ ,int /*<<< orphan*/ ,char const*,int,scalar_t__*,int) ; 
 scalar_t__ OpenClipboard (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  SUCCEEDED (scalar_t__) ; 
 int /*<<< orphan*/  SetClipboardData (int /*<<< orphan*/ ,scalar_t__) ; 
 int WideCharToMultiByte (int /*<<< orphan*/ ,int /*<<< orphan*/ ,scalar_t__,int,char*,int,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  assert (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  context ; 
 int /*<<< orphan*/  device ; 
 int /*<<< orphan*/  exit (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  free (char*) ; 
 scalar_t__ malloc (int) ; 
 int /*<<< orphan*/  memcpy (float*,float**,int) ; 
 int /*<<< orphan*/  memset (TYPE_1__*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  nk_textedit_paste (struct nk_text_edit*,char*,int) ; 
 scalar_t__ rt_view ; 
 int /*<<< orphan*/  swap_chain ; 

__attribute__((used)) static nk_ushort nk_ttUSHORT(const nk_byte *p) { return (nk_ushort)(p[0]*256 + p[1]); }

__attribute__((used)) static nk_short nk_ttSHORT(const nk_byte *p)   { return (nk_short)(p[0]*256 + p[1]); }

__attribute__((used)) static nk_uint nk_ttULONG(const nk_byte *p)  { return (nk_uint)((p[0]<<24) + (p[1]<<16) + (p[2]<<8) + p[3]); }

__attribute__((used)) static void
nk_d3d11_get_projection_matrix(int width, int height, float *result)
{
    const float L = 0.0f;
    const float R = (float)width;
    const float T = 0.0f;
    const float B = (float)height;
    float matrix[4][4] =
    {
        {    2.0f / (R - L),              0.0f, 0.0f, 0.0f },
        {              0.0f,    2.0f / (T - B), 0.0f, 0.0f },
        {              0.0f,              0.0f, 0.5f, 0.0f },
        { (R + L) / (L - R), (T + B) / (B - T), 0.5f, 1.0f },
    };
    memcpy(result, matrix, sizeof(matrix));
}

__attribute__((used)) static void
nk_d3d11_clipboard_paste(nk_handle usr, struct nk_text_edit *edit)
{
    (void)usr;
    if (IsClipboardFormatAvailable(CF_UNICODETEXT) && OpenClipboard(NULL))
    {
        HGLOBAL mem = GetClipboardData(CF_UNICODETEXT); 
        if (mem)
        {
            SIZE_T size = GlobalSize(mem) - 1;
            if (size)
            {
                LPCWSTR wstr = (LPCWSTR)GlobalLock(mem);
                if (wstr)
                {
                    int utf8size = WideCharToMultiByte(CP_UTF8, 0, wstr, size / sizeof(wchar_t), NULL, 0, NULL, NULL);
                    if (utf8size)
                    {
                        char* utf8 = (char*)malloc(utf8size);
                        if (utf8)
                        {
                            WideCharToMultiByte(CP_UTF8, 0, wstr, size / sizeof(wchar_t), utf8, utf8size, NULL, NULL);
                            nk_textedit_paste(edit, utf8, utf8size);
                            free(utf8);
                        }
                    }
                    GlobalUnlock(mem); 
                }
            }
        }
        CloseClipboard();
    }
}

__attribute__((used)) static void
nk_d3d11_clipboard_copy(nk_handle usr, const char *text, int len)
{
    (void)usr;
    if (OpenClipboard(NULL))
    {
        int wsize = MultiByteToWideChar(CP_UTF8, 0, text, len, NULL, 0);
        if (wsize)
        {
            HGLOBAL mem = GlobalAlloc(GMEM_MOVEABLE, (wsize + 1) * sizeof(wchar_t));
            if (mem)
            {
                wchar_t* wstr = (wchar_t*)GlobalLock(mem);
                if (wstr)
                {
                    MultiByteToWideChar(CP_UTF8, 0, text, len, wstr, wsize);
                    wstr[wsize] = 0;
                    GlobalUnlock(mem);
                    SetClipboardData(CF_UNICODETEXT, mem); 
                }
            }
        }
        CloseClipboard();
    }
}

__attribute__((used)) static void
set_swap_chain_size(int width, int height)
{
    ID3D11Texture2D *back_buffer;
    D3D11_RENDER_TARGET_VIEW_DESC desc;
    HRESULT hr;

    if (rt_view)
        ID3D11RenderTargetView_Release(rt_view);

    ID3D11DeviceContext_OMSetRenderTargets(context, 0, NULL, NULL);

    hr = IDXGISwapChain_ResizeBuffers(swap_chain, 0, width, height, DXGI_FORMAT_UNKNOWN, 0);
    if (hr == DXGI_ERROR_DEVICE_REMOVED || hr == DXGI_ERROR_DEVICE_RESET || hr == DXGI_ERROR_DRIVER_INTERNAL_ERROR)
    {
        /* to recover from this, you'll need to recreate device and all the resources */
        MessageBoxW(NULL, L"DXGI device is removed or reset!", L"Error", 0);
        exit(0);
    }
    assert(SUCCEEDED(hr));

    memset(&desc, 0, sizeof(desc));
    desc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
    desc.ViewDimension = D3D11_RTV_DIMENSION_TEXTURE2D;

    hr = IDXGISwapChain_GetBuffer(swap_chain, 0, &IID_ID3D11Texture2D, (void **)&back_buffer);
    assert(SUCCEEDED(hr));

    hr = ID3D11Device_CreateRenderTargetView(device, (ID3D11Resource *)back_buffer, &desc, &rt_view);
    assert(SUCCEEDED(hr));

    ID3D11Texture2D_Release(back_buffer);
}

