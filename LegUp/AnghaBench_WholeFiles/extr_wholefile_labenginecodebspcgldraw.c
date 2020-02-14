#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_7__   TYPE_2__ ;
typedef  struct TYPE_6__   TYPE_1__ ;

/* Type definitions */
struct TYPE_7__ {int numpoints; float** p; } ;
typedef  TYPE_2__ winding_t ;
typedef  void* vec_t ;
struct TYPE_6__ {int /*<<< orphan*/  s_addr; } ;
struct sockaddr_in {int /*<<< orphan*/  sin_port; TYPE_1__ sin_addr; int /*<<< orphan*/  sin_family; } ;
struct sockaddr {int dummy; } ;
typedef  int /*<<< orphan*/  byte ;
typedef  int /*<<< orphan*/  address ;
typedef  int /*<<< orphan*/  WSADATA ;
typedef  int /*<<< orphan*/  WORD ;

/* Variables and functions */
 int /*<<< orphan*/  AF_INET ; 
 int AUX_RGB ; 
 int AUX_SINGLE ; 
 int /*<<< orphan*/  Error (char*) ; 
 int /*<<< orphan*/  GLSERV_PORT ; 
 int /*<<< orphan*/  GL_BLEND ; 
 int /*<<< orphan*/  GL_COLOR_BUFFER_BIT ; 
 int /*<<< orphan*/  GL_DEPTH_TEST ; 
 int /*<<< orphan*/  GL_FILL ; 
 int /*<<< orphan*/  GL_FRONT_AND_BACK ; 
 int /*<<< orphan*/  GL_LINE_LOOP ; 
 int /*<<< orphan*/  GL_ONE_MINUS_SRC_ALPHA ; 
 int /*<<< orphan*/  GL_POLYGON ; 
 int /*<<< orphan*/  GL_SRC_ALPHA ; 
 int /*<<< orphan*/  INADDR_LOOPBACK ; 
 int /*<<< orphan*/  IPPROTO_TCP ; 
 int /*<<< orphan*/  MAKEWORD (int,int) ; 
 int /*<<< orphan*/  PF_INET ; 
 int /*<<< orphan*/  SOCK_STREAM ; 
 int /*<<< orphan*/  WIN_SIZE ; 
 int WSAStartup (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  auxInitDisplayMode (int) ; 
 int /*<<< orphan*/  auxInitPosition (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  auxInitWindow (char*) ; 
 int /*<<< orphan*/  closesocket (int) ; 
 int connect (int,struct sockaddr*,int) ; 
 void** draw_maxs ; 
 void** draw_mins ; 
 int draw_socket ; 
 int /*<<< orphan*/  drawflag ; 
 int /*<<< orphan*/  glBegin (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  glBlendFunc (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  glClear (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  glClearColor (int,double,double,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  glColor3f (double,double,double) ; 
 int /*<<< orphan*/  glColor4f (int,int,int /*<<< orphan*/ ,double) ; 
 int /*<<< orphan*/  glDisable (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  glEnable (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  glEnd () ; 
 int /*<<< orphan*/  glFlush () ; 
 int /*<<< orphan*/  glLoadIdentity () ; 
 int /*<<< orphan*/  glPolygonMode (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  glVertex3f (float,float,float) ; 
 int /*<<< orphan*/  gluLookAt (void*,void*,void*,void*,void*,void*,int /*<<< orphan*/ ,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  gluPerspective (int,int,int,int) ; 
 int /*<<< orphan*/  htonl (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  send (int,int /*<<< orphan*/ *,int,int /*<<< orphan*/ ) ; 
 int socket (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int wins_init ; 

void InitWindow (void)
{
    auxInitDisplayMode (AUX_SINGLE | AUX_RGB);
    auxInitPosition (0, 0, WIN_SIZE, WIN_SIZE);
    auxInitWindow ("qcsg");
}

void Draw_ClearWindow (void)
{
	static int	init;
	int		w, h, g;
	vec_t	mx, my;

	if (!drawflag)
		return;

	if (!init)
	{
		init = true;
		InitWindow ();
	}

	glClearColor (1,0.8,0.8,0);
	glClear (GL_COLOR_BUFFER_BIT);

	w = (draw_maxs[0] - draw_mins[0]);
	h = (draw_maxs[1] - draw_mins[1]);

	mx = draw_mins[0] + w/2;
	my = draw_mins[1] + h/2;

	g = w > h ? w : h;

	glLoadIdentity ();
    gluPerspective (90,  1,  2,  16384);
	gluLookAt (mx, my, draw_maxs[2] + g/2, mx , my, draw_maxs[2], 0, 1, 0);

	glColor3f (0,0,0);
//	glPolygonMode (GL_FRONT_AND_BACK, GL_LINE);
	glPolygonMode (GL_FRONT_AND_BACK, GL_FILL);
	glDisable (GL_DEPTH_TEST);
	glEnable (GL_BLEND);
	glBlendFunc (GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

#if 0
	glColor4f (1,0,0,0.5);
	glBegin (GL_POLYGON);

	glVertex3f (0, 500, 0);
	glVertex3f (0, 900, 0);
	glVertex3f (0, 900, 100);
	glVertex3f (0, 500, 100);

	glEnd ();
#endif

	glFlush ();

}

void Draw_SetRed (void)
{
	if (!drawflag)
		return;

	glColor3f (1,0,0);
}

void Draw_SetGrey (void)
{
	if (!drawflag)
		return;

	glColor3f (0.5,0.5,0.5);
}

void Draw_SetBlack (void)
{
	if (!drawflag)
		return;

	glColor3f (0,0,0);
}

void DrawWinding (winding_t *w)
{
	int		i;

	if (!drawflag)
		return;

	glColor4f (0,0,0,0.5);
	glBegin (GL_LINE_LOOP);
	for (i=0 ; i<w->numpoints ; i++)
		glVertex3f (w->p[i][0],w->p[i][1],w->p[i][2] );
	glEnd ();

	glColor4f (0,1,0,0.3);
	glBegin (GL_POLYGON);
	for (i=0 ; i<w->numpoints ; i++)
		glVertex3f (w->p[i][0],w->p[i][1],w->p[i][2] );
	glEnd ();

	glFlush ();
}

void DrawAuxWinding (winding_t *w)
{
	int		i;

	if (!drawflag)
		return;

	glColor4f (0,0,0,0.5);
	glBegin (GL_LINE_LOOP);
	for (i=0 ; i<w->numpoints ; i++)
		glVertex3f (w->p[i][0],w->p[i][1],w->p[i][2] );
	glEnd ();

	glColor4f (1,0,0,0.3);
	glBegin (GL_POLYGON);
	for (i=0 ; i<w->numpoints ; i++)
		glVertex3f (w->p[i][0],w->p[i][1],w->p[i][2] );
	glEnd ();

	glFlush ();
}

void GLS_BeginScene (void)
{
	WSADATA	winsockdata;
	WORD	wVersionRequested; 
	struct sockaddr_in	address;
	int		r;

	if (!wins_init)
	{
		wins_init = true;

		wVersionRequested = MAKEWORD(1, 1); 

		r = WSAStartup (MAKEWORD(1, 1), &winsockdata);

		if (r)
			Error ("Winsock initialization failed.");

	}

	// connect a socket to the server

	draw_socket = socket (PF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (draw_socket == -1)
		Error ("draw_socket failed");

	address.sin_family = AF_INET;
	address.sin_addr.s_addr = htonl(INADDR_LOOPBACK);
	address.sin_port = GLSERV_PORT;
	r = connect (draw_socket, (struct sockaddr *)&address, sizeof(address));
	if (r == -1)
	{
		closesocket (draw_socket);
		draw_socket = 0;
	}
}

void GLS_Winding (winding_t *w, int code)
{
	byte	buf[1024];
	int		i, j;

	if (!draw_socket)
		return;

	((int *)buf)[0] = w->numpoints;
	((int *)buf)[1] = code;
	for (i=0 ; i<w->numpoints ; i++)
		for (j=0 ; j<3 ; j++)
			((float *)buf)[2+i*3+j] = w->p[i][j];

	send (draw_socket, buf, w->numpoints*12+8, 0);
}

void GLS_EndScene (void)
{
	closesocket (draw_socket);
	draw_socket = 0;
}

