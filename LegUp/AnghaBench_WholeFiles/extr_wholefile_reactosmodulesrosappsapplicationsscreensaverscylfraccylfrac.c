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
typedef  int /*<<< orphan*/  PAINTSTRUCT ;
typedef  int /*<<< orphan*/  HWND ;
typedef  int /*<<< orphan*/  HDC ;

/* Variables and functions */
 int /*<<< orphan*/  BeginPaint (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  EndPaint (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int GL_COLOR_BUFFER_BIT ; 
 int GL_DEPTH_BUFFER_BIT ; 
 int /*<<< orphan*/  SwapBuffers (int /*<<< orphan*/ ) ; 
 int angle ; 
 int bval ; 
 int colorh ; 
 int /*<<< orphan*/  cylinder ; 
 int /*<<< orphan*/  cylquality ; 
 int /*<<< orphan*/  glClear (int) ; 
 int /*<<< orphan*/  glColor3f (int,int,int) ; 
 int /*<<< orphan*/  glPopMatrix () ; 
 int /*<<< orphan*/  glPushMatrix () ; 
 int /*<<< orphan*/  glRotatef (int,double,double,double) ; 
 int /*<<< orphan*/  glTranslatef (double,int,double) ; 
 int /*<<< orphan*/  gluCylinder (int /*<<< orphan*/ ,float,float,int,int /*<<< orphan*/ ,int) ; 
 int gval ; 
 int lvls ; 
 float rotfactor ; 
 int rval ; 
 float wfactor ; 

float _RGB(float H, float M1, float M2)
{
    if(H < 0.0) H += 360.0;
        else if(H > 360.0) H -= 360.0;
    if(H < 60) return M1 + (M2 - M1) * H / 60.0;
    if((H >= 60 )&&(H < 180)) return M2;
    if((H >= 180)&&(H < 240)) return M1 + (M2 - M1)*(240 - H) / 60.0;
    return M1;
}

void HLStoRGB(float H, float L, float S,
              float* R, float* G, float* B)
{
    float M1, M2;
    if(S <= 0.5) M2 = S * (1 + L);
        else M2 = S * (1 - L) + L;
    M1 = 2 * S - M2;
    if (L == 0.0)
    {
        *R = S;
        *G = S;
        *B = S;
    } else {
        *R = _RGB(H + 120.0, M1, M2);
        *G = _RGB(H        , M1, M2);
        *B = _RGB(H - 120.0, M1, M2);
    }
}

void DrawCylinder(int n, float rota, float width)
{
    glPushMatrix();
    glColor3f(rval/n, gval/n, bval/n);
    glRotatef(rota, 0.0, 1.0, 0.0);
    gluCylinder(cylinder, width, width * wfactor, n * 0.5, cylquality, 1);
    glTranslatef(0.0, 0.0, -n * 0.5);
    gluCylinder(cylinder, width * wfactor, width, n * 0.5, cylquality, 1);
    if(n > 1)
    {
        float r = rota * rotfactor;
        glRotatef(90.0, 1.0, 0.0, 0.0);
        DrawCylinder(n - 1,  r, width * wfactor);
        glTranslatef(0.0, n, 0.0);
        DrawCylinder(n - 1, -r, width * wfactor);
    }
    glPopMatrix();
}

void DrawScene(HWND hwnd, HDC dc, int ticks)
{
    PAINTSTRUCT ps;
    dc = BeginPaint(hwnd, &ps);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glRotatef(ticks * 0.01, 0.0, 1.0, -0.5);
    angle += ticks * 0.01;
    colorh += ticks * 0.003;
    if (colorh > 360.0) colorh -= 360.0;
    HLStoRGB(colorh, 1.0, 0.7, &rval, &gval, &bval);
    DrawCylinder(lvls, angle, 0.2);
    SwapBuffers(dc);
    EndPaint(hwnd, &ps);
}

