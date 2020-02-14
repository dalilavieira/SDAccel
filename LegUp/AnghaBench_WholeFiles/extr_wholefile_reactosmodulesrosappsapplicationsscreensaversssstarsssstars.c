#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_13__   TYPE_6__ ;
typedef  struct TYPE_12__   TYPE_5__ ;
typedef  struct TYPE_11__   TYPE_3__ ;
typedef  struct TYPE_10__   TYPE_2__ ;
typedef  struct TYPE_9__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  bi ;
typedef  size_t UINT ;
struct TYPE_13__ {int uiRotation; unsigned int uiNumStars; scalar_t__ uiSpeed; scalar_t__ bFinePerspective; scalar_t__ bEnableFiltering; scalar_t__ bSmoothShading; } ;
struct TYPE_12__ {float x1; float y1; float x2; float y2; float z; } ;
struct TYPE_11__ {int bmWidth; int bmHeight; int /*<<< orphan*/  bmBits; } ;
struct TYPE_9__ {int biSize; int biWidth; int biHeight; int biPlanes; int biBitCount; int /*<<< orphan*/  biCompression; } ;
struct TYPE_10__ {TYPE_1__ bmiHeader; } ;
typedef  scalar_t__ LPBYTE ;
typedef  int /*<<< orphan*/  HWND ;
typedef  scalar_t__ HINSTANCE ;
typedef  scalar_t__ HGDIOBJ ;
typedef  int /*<<< orphan*/  HDC ;
typedef  scalar_t__ HBITMAP ;
typedef  int DWORD ;
typedef  int /*<<< orphan*/  BITMAPINFOHEADER ;
typedef  TYPE_2__ BITMAPINFO ;
typedef  TYPE_3__ BITMAP ;

/* Variables and functions */
 int /*<<< orphan*/  BI_RGB ; 
 int /*<<< orphan*/  BitBlt (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int,int,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  CreateCompatibleDC (int /*<<< orphan*/ ) ; 
 scalar_t__ CreateDIBSection (int /*<<< orphan*/ ,TYPE_2__*,int /*<<< orphan*/ ,void**,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  DIB_RGB_COLORS ; 
 int /*<<< orphan*/  DeleteDC (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  DeleteObject (scalar_t__) ; 
 float FAR_PLANE ; 
 float FIELD_DEPTH ; 
 float FIELD_HEIGHT ; 
 float FIELD_WIDTH ; 
 float GAP ; 
 int /*<<< orphan*/  GL_AMBIENT_AND_DIFFUSE ; 
 int /*<<< orphan*/  GL_BLEND ; 
 int /*<<< orphan*/  GL_COLOR_BUFFER_BIT ; 
 int /*<<< orphan*/  GL_COLOR_MATERIAL ; 
 int /*<<< orphan*/  GL_CONSTANT_ATTENUATION ; 
 int /*<<< orphan*/  GL_DEPTH_TEST ; 
 int /*<<< orphan*/  GL_FASTEST ; 
 int /*<<< orphan*/  GL_FILL ; 
 int /*<<< orphan*/  GL_FLAT ; 
 int /*<<< orphan*/  GL_FRONT ; 
 int /*<<< orphan*/  GL_FRONT_AND_BACK ; 
 int /*<<< orphan*/  GL_LIGHT0 ; 
 int /*<<< orphan*/  GL_LIGHTING ; 
 int /*<<< orphan*/  GL_LINEAR ; 
 int /*<<< orphan*/  GL_LINEAR_ATTENUATION ; 
 int /*<<< orphan*/  GL_NEAREST ; 
 int /*<<< orphan*/  GL_NICEST ; 
 int /*<<< orphan*/  GL_ONE ; 
 int /*<<< orphan*/  GL_PERSPECTIVE_CORRECTION_HINT ; 
 int /*<<< orphan*/  GL_QUADRATIC_ATTENUATION ; 
 int /*<<< orphan*/  GL_QUADS ; 
 int /*<<< orphan*/  GL_RGBA ; 
 int /*<<< orphan*/  GL_SMOOTH ; 
 int /*<<< orphan*/  GL_SRC_ALPHA ; 
 int /*<<< orphan*/  GL_TEXTURE_2D ; 
 int /*<<< orphan*/  GL_TEXTURE_MAG_FILTER ; 
 int /*<<< orphan*/  GL_TEXTURE_MIN_FILTER ; 
 int /*<<< orphan*/  GL_TRUE ; 
 int /*<<< orphan*/  GL_UNSIGNED_BYTE ; 
 int /*<<< orphan*/  GWLP_HINSTANCE ; 
 int /*<<< orphan*/  GetObject (scalar_t__,int,TYPE_3__*) ; 
 scalar_t__ GetWindowLongPtr (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  IDB_STAR ; 
 int /*<<< orphan*/  IMAGE_BITMAP ; 
 int LR_CREATEDIBSECTION ; 
 int LR_DEFAULTSIZE ; 
 scalar_t__ LoadImage (scalar_t__,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  MAKEINTRESOURCE (int /*<<< orphan*/ ) ; 
 unsigned int MAX_STARS ; 
 float NEAR_PLANE ; 
 float RAND_MAX ; 
#define  ROTATION_LINEAR 129 
#define  ROTATION_PERIODIC 128 
 int /*<<< orphan*/  SRCCOPY ; 
 int /*<<< orphan*/  STAR_BLUE ; 
 int /*<<< orphan*/  STAR_GREEN ; 
 int /*<<< orphan*/  STAR_RED ; 
 int /*<<< orphan*/  STAR_TAIL ; 
 scalar_t__ SelectObject (int /*<<< orphan*/ ,scalar_t__) ; 
 TYPE_6__ Settings ; 
 TYPE_5__* Vertex ; 
 int /*<<< orphan*/  ZeroMemory (TYPE_2__*,int) ; 
 int cos (float) ; 
 float fAngle ; 
 int /*<<< orphan*/  glBegin (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  glBindTexture (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  glBlendFunc (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  glClear (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  glClearColor (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  glColor3ub (int,int,int) ; 
 int /*<<< orphan*/  glColorMaterial (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  glDisable (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  glEnable (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  glEnd () ; 
 int /*<<< orphan*/  glGenTextures (int,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  glHint (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  glLightModeli (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  glLightf (int /*<<< orphan*/ ,int /*<<< orphan*/ ,float) ; 
 int /*<<< orphan*/  glPolygonMode (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  glRotatef (float,float,float,float) ; 
 int /*<<< orphan*/  glShadeModel (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  glStarTex ; 
 int /*<<< orphan*/  glTexCoord2f (float,float) ; 
 int /*<<< orphan*/  glTexParameteri (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  glVertex3f (float,float,float) ; 
 int /*<<< orphan*/  gluBuild2DMipmaps (int /*<<< orphan*/ ,int,int,int,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 scalar_t__ rand () ; 
 int /*<<< orphan*/  srand (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  time (int /*<<< orphan*/ *) ; 

__attribute__((used)) static HBITMAP CreateStarBitmap(HWND hWnd, HDC hDC)
{
    BITMAPINFO bi;
    LPBYTE     lpBits;
    LPBYTE    *lppBits;
    HBITMAP    hTextBmp, hFileBmp;
    HDC        hTextDC, hFileDC;
    HGDIOBJ    hOldText, hOldFile;
    UINT       i;
    DWORD     *Ptr32;
    BITMAP     bm;
    HINSTANCE  hInstance;

    // Get instance for loading the texture
    hInstance = (HINSTANCE)GetWindowLongPtr(hWnd, GWLP_HINSTANCE);

    // Load the texture
    hFileBmp = (HBITMAP)
              LoadImage(
                    hInstance,
                    MAKEINTRESOURCE(IDB_STAR),
                    IMAGE_BITMAP,
                    0, 0,
                    LR_CREATEDIBSECTION | LR_DEFAULTSIZE
              );

    // Get texture specs
    GetObject(hFileBmp, sizeof(BITMAP), &bm);

    // Allocate new 32 bit texture
    ZeroMemory(&bi, sizeof(bi));

    bi.bmiHeader.biSize        = sizeof(BITMAPINFOHEADER);
    bi.bmiHeader.biWidth       = bm.bmWidth;
    bi.bmiHeader.biHeight      = -bm.bmHeight;
    bi.bmiHeader.biPlanes      = 1;
    bi.bmiHeader.biBitCount    = 32;
    bi.bmiHeader.biCompression = BI_RGB;

    // Makes GCC happy ;-|
    lppBits = &lpBits;

    hTextBmp = CreateDIBSection(hDC,
                                (BITMAPINFO*)&bi,
                                DIB_RGB_COLORS,
                                (void**)lppBits,
                                NULL,
                                0);

    // Save new texture specs
//    GetObject(hTextBmp, sizeof(BITMAP), &bmStarTex);
//    bmStarTex.bmBits = lpBits;

    // Copy 24 bit texture in 32 texture
    hTextDC = CreateCompatibleDC(hDC);
    hFileDC = CreateCompatibleDC(hDC);

    hOldText = SelectObject(hTextDC, hTextBmp);
    hOldFile = SelectObject(hFileDC, hFileBmp);

    BitBlt(hTextDC, 0, 0, bm.bmWidth, bm.bmHeight, hFileDC, 0, 0, SRCCOPY);

    SelectObject(hTextDC, hOldText);
    SelectObject(hFileDC, hOldFile);

    DeleteDC(hTextDC);
    DeleteDC(hFileDC);

    // Delete 24 bit texture
    DeleteObject(hFileBmp);

    GetObject(hTextBmp, sizeof(BITMAP), &bm);

    // Apply ALPHA channel to new texture
    for (Ptr32=(DWORD *)lpBits, i=0; i < (UINT)(bm.bmWidth * bm.bmHeight); i++)
    {
        DWORD Color = Ptr32[i] & 0x00FFFFFF;
        DWORD Alpha = Color & 0xFF;

        Color |= Alpha << 24;

        Ptr32[i] = Color;
    }

    return hTextBmp;
}

__attribute__((used)) static void InitGL(HBITMAP hStarTex)
{
    BITMAP       bm;
    unsigned int i;
    float        xp, yp, zp;

    // set the GL clear color - use when the color buffer is cleared
    glClearColor(STAR_RED, STAR_GREEN, STAR_BLUE, STAR_TAIL);

    if (Settings.bSmoothShading)
        // set the shading model to 'smooth'
        glShadeModel( GL_SMOOTH );
    else
        // set the shading model to 'flat'
        glShadeModel( GL_FLAT );

    // set GL to render front of polygons
    glPolygonMode( GL_FRONT_AND_BACK, GL_FILL );
    // enable depth test
    glDisable( GL_DEPTH_TEST );

    // enable lighting
    glEnable( GL_LIGHTING );
    // enable lighting for front
    glLightModeli( GL_FRONT, GL_TRUE );
    // material have diffuse and ambient lighting 
    glColorMaterial( GL_FRONT, GL_AMBIENT_AND_DIFFUSE );
    // enable color
    glEnable( GL_COLOR_MATERIAL );
    // enable light 0
    glEnable( GL_LIGHT0 );

    // set light attenuation
    glLightf( GL_LIGHT0, GL_CONSTANT_ATTENUATION,  0.01f); //0.01f );
    glLightf( GL_LIGHT0, GL_LINEAR_ATTENUATION,    0.01f); //0.2f );
    glLightf( GL_LIGHT0, GL_QUADRATIC_ATTENUATION, 0.005f); //0.001f );

    // clear the color buffer once
    glClear( GL_COLOR_BUFFER_BIT );

    // randomly generate
    srand( time( NULL ) );

    // Initialize *ALL* stars vertexes (not just programmed ones).
    for (i = 0; i < MAX_STARS; i++)
    {
        xp = ( (float) rand() / RAND_MAX - .5f ) * FIELD_WIDTH;
        yp = ( (float) rand() / RAND_MAX - .5f ) * FIELD_HEIGHT;
        zp = ( (float) rand() / RAND_MAX       ) * FIELD_DEPTH + FAR_PLANE;

        Vertex[i].x1 = -1.f + xp;
        Vertex[i].y1 = -1.f + yp;
        Vertex[i].x2 =  1.f + xp;
        Vertex[i].y2 =  1.f + yp;
        Vertex[i].z  = zp;
    }

    glGenTextures(1, &glStarTex);           // Create One Texture

    // Create Linear Filtered Texture
    glBindTexture(GL_TEXTURE_2D, glStarTex);

    if (Settings.bEnableFiltering)
    {
        glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
    } else {
        glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_NEAREST);
        glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_NEAREST);
    }

    // Get Texture properties
    GetObject(hStarTex, sizeof(BITMAP), &bm);

    // Create texture as a mipmap
#if 0
    glTexImage2D(GL_TEXTURE_2D, 0, 4, bm.bmWidth, bm.bmHeight, 0, GL_RGBA, GL_UNSIGNED_BYTE, bm.bmBits);
#else
    gluBuild2DMipmaps(GL_TEXTURE_2D, 4, bm.bmWidth, bm.bmHeight, GL_RGBA, GL_UNSIGNED_BYTE, bm.bmBits);
#endif

    // Disable Texture Mapping (background smoothing)
    glDisable(GL_TEXTURE_2D);

    if (Settings.bFinePerspective)
        // Really Fast Perspective Calculations
        glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_FASTEST);
    else
        // Really Nice Perspective Calculations
        glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);

    // enable blending
    glEnable( GL_BLEND );
}

__attribute__((used)) static void
render(void)
{
    unsigned int i;
    float        fSpin;
    float        fSpeed;
    float        xp, yp;

    // Initialize current speed
    fSpeed = (float)Settings.uiSpeed / 100.f;

    glEnable(GL_TEXTURE_2D);                // Enable Texture Mapping

    glBlendFunc(GL_SRC_ALPHA,GL_ONE);           // Set The Blending Function For Translucency

    switch (Settings.uiRotation) {
    case ROTATION_LINEAR:
        fAngle += fSpeed;
        glRotatef( fAngle, 0.0f, 0.0f, 1.0f );
        break;

    case ROTATION_PERIODIC:
        fAngle += fSpeed / 75.f;
        fSpin = (float)(50. * cos(fAngle));
        glRotatef( fSpin, 0.0f, 0.0f, 1.0f );
        break;
    }

    glColor3ub(255, 255, 255);

    glBegin(GL_QUADS);              // Begin Drawing The Textured Quad

    // Draw the stars
    for (i = 0; i < Settings.uiNumStars; i++)
    {
        glTexCoord2f(0.0f, 0.0f); glVertex3f(Vertex[i].x1, Vertex[i].y1, Vertex[i].z);
        glTexCoord2f(1.0f, 0.0f); glVertex3f(Vertex[i].x2, Vertex[i].y1, Vertex[i].z);
        glTexCoord2f(1.0f, 1.0f); glVertex3f(Vertex[i].x2, Vertex[i].y2, Vertex[i].z);
        glTexCoord2f(0.0f, 1.0f); glVertex3f(Vertex[i].x1, Vertex[i].y2, Vertex[i].z);

        // increment z
        Vertex[i].z += fSpeed;

        // check to see if passed view
        if( Vertex[i].z > NEAR_PLANE + GAP ||
            Vertex[i].z < FAR_PLANE )
        {
            xp = ( (float) rand() / RAND_MAX - .5f ) * FIELD_WIDTH;
            yp = ( (float) rand() / RAND_MAX - .5f ) * FIELD_HEIGHT;

            Vertex[i].x1 = -1.f + xp;
            Vertex[i].y1 = -1.f + yp;
            Vertex[i].x2 =  1.f + xp;
            Vertex[i].y2 =  1.f + yp;
            Vertex[i].z  = FAR_PLANE;
        }
    }

    glEnd();                    // Done Drawing The Textured Quad

    glDisable(GL_TEXTURE_2D);               // Enable Texture Mapping
}

