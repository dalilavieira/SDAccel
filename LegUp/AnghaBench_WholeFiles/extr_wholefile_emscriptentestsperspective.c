#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_13__   TYPE_5__ ;
typedef  struct TYPE_12__   TYPE_4__ ;
typedef  struct TYPE_11__   TYPE_3__ ;
typedef  struct TYPE_10__   TYPE_2__ ;
typedef  struct TYPE_9__   TYPE_1__ ;

/* Type definitions */
struct TYPE_11__ {int sym; } ;
struct TYPE_9__ {TYPE_3__ keysym; } ;
struct TYPE_13__ {int type; TYPE_1__ key; } ;
struct TYPE_12__ {TYPE_2__* vfmt; } ;
struct TYPE_10__ {int BitsPerPixel; } ;
typedef  TYPE_3__ SDL_keysym ;
typedef  TYPE_4__ SDL_VideoInfo ;
typedef  TYPE_5__ SDL_Event ;
typedef  int GLubyte ;
typedef  float GLfloat ;

/* Variables and functions */
 int /*<<< orphan*/  GL_BACK ; 
 int /*<<< orphan*/  GL_CCW ; 
 int GL_COLOR_BUFFER_BIT ; 
 int /*<<< orphan*/  GL_CULL_FACE ; 
 int GL_DEPTH_BUFFER_BIT ; 
 int /*<<< orphan*/  GL_MODELVIEW ; 
 int /*<<< orphan*/  GL_PROJECTION ; 
 int /*<<< orphan*/  GL_SMOOTH ; 
 int /*<<< orphan*/  GL_TRIANGLES ; 
#define  SDLK_ESCAPE 131 
#define  SDLK_SPACE 130 
 int /*<<< orphan*/  SDL_Delay (int) ; 
 int /*<<< orphan*/  SDL_GL_SwapBuffers () ; 
 char* SDL_GetError () ; 
 TYPE_4__* SDL_GetVideoInfo () ; 
 int /*<<< orphan*/  SDL_INIT_VIDEO ; 
 scalar_t__ SDL_Init (int /*<<< orphan*/ ) ; 
#define  SDL_KEYDOWN 129 
 int SDL_OPENGL ; 
 scalar_t__ SDL_PollEvent (TYPE_5__*) ; 
#define  SDL_QUIT 128 
 int /*<<< orphan*/  SDL_Quit () ; 
 scalar_t__ SDL_SetVideoMode (int,int,int,int) ; 
 int /*<<< orphan*/  emColor4ubv (int*) ; 
 int /*<<< orphan*/  exit (int) ; 
 int /*<<< orphan*/  fprintf (int /*<<< orphan*/ ,char*,char*) ; 
 int /*<<< orphan*/  glBegin (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  glClear (int) ; 
 int /*<<< orphan*/  glClearColor (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  glCullFace (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  glEnable (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  glEnd () ; 
 int /*<<< orphan*/  glFrontFace (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  glLoadIdentity () ; 
 int /*<<< orphan*/  glMatrixMode (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  glRotatef (float,double,double,double) ; 
 int /*<<< orphan*/  glShadeModel (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  glTranslatef (double,double,double) ; 
 int /*<<< orphan*/  glVertex3fv (float*) ; 
 int /*<<< orphan*/  glViewport (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int,int) ; 
 int /*<<< orphan*/  gluPerspective (double,float,double,double) ; 
 int should_rotate ; 
 int /*<<< orphan*/  stderr ; 

__attribute__((used)) static void quit_tutorial( int code )
{
    /*
     * Quit SDL so we can release the fullscreen
     * mode and restore the previous video settings,
     * etc.
     */
    SDL_Quit( );
    
    /* Exit program. */
    exit( code );
}

__attribute__((used)) static void handle_key_down( SDL_keysym* keysym )
{
    
    /*
     * We're only interested if 'Esc' has
     * been presssed.
     *
     * EXERCISE:
     * Handle the arrow keys and have that change the
     * viewing position/angle.
     */
    switch( keysym->sym ) {
        case SDLK_ESCAPE:
            quit_tutorial( 0 );
            break;
        case SDLK_SPACE:
            should_rotate = !should_rotate;
            break;
        default:
            break;
    }
    
}

__attribute__((used)) static void process_events( void )
{
    /* Our SDL event placeholder. */
    SDL_Event event;
    
    /* Grab all the events off the queue. */
    while( SDL_PollEvent( &event ) ) {
        
        switch( event.type ) {
            case SDL_KEYDOWN:
                /* Handle key presses. */
                handle_key_down( &event.key.keysym );
                break;
            case SDL_QUIT:
                /* Handle quit requests (like Ctrl-c). */
                quit_tutorial( 0 );
                break;
        }
        
    }
    
}

__attribute__((used)) static void draw_screen( void )
{
    /* Our angle of rotation. */
    static float angle = 0.0f;
    
    /*
     * EXERCISE:
     * Replace this awful mess with vertex
     * arrays and a call to glDrawElements.
     *
     * EXERCISE:
     * After completing the above, change
     * it to use compiled vertex arrays.
     *
     * EXERCISE:
     * Verify my windings are correct here ;).
     */
    static GLfloat v0[] = { -1.0f, -1.0f,  1.0f };
    static GLfloat v1[] = {  1.0f, -1.0f,  1.0f };
    static GLfloat v2[] = {  1.0f,  1.0f,  1.0f };
    static GLfloat v3[] = { -1.0f,  1.0f,  1.0f };
    static GLfloat v4[] = { -1.0f, -1.0f, -1.0f };
    static GLfloat v5[] = {  1.0f, -1.0f, -1.0f };
    static GLfloat v6[] = {  1.0f,  1.0f, -1.0f };
    static GLfloat v7[] = { -1.0f,  1.0f, -1.0f };
    static GLubyte red[]    = { 255,   0,   0, 255 };
    static GLubyte green[]  = {   0, 255,   0, 255 };
    static GLubyte blue[]   = {   0,   0, 255, 255 };
    static GLubyte white[]  = { 255, 255, 255, 255 };
    static GLubyte yellow[] = {   0, 255, 255, 255 };
    static GLubyte black[]  = {   0,   0,   0, 255 };
    static GLubyte orange[] = { 255, 255,   0, 255 };
    static GLubyte purple[] = { 255,   0, 255,   0 };
    
    /* Clear the color and depth buffers. */
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
    
    /* We don't want to modify the projection matrix. */
    glMatrixMode( GL_MODELVIEW );
    glLoadIdentity( );
    
    /* Move down the z-axis. */
    glTranslatef( 0.0, 0.0, -5.0 );
    
    /* Rotate. */
    glRotatef( angle, 0.0, 1.0, 0.0 );
    
    if( should_rotate ) {
        
        if( ++angle > 360.0f ) {
            angle = 0.0f;
        }
        
    }
    
    /* Send our triangle data to the pipeline. */
    glBegin( GL_TRIANGLES );
    
    emColor4ubv( red );
    glVertex3fv( v0 );
    emColor4ubv( green );
    glVertex3fv( v1 );
    emColor4ubv( blue );
    glVertex3fv( v2 );
    
    emColor4ubv( red );
    glVertex3fv( v0 );
    emColor4ubv( blue );
    glVertex3fv( v2 );
    emColor4ubv( white );
    glVertex3fv( v3 );
    
    emColor4ubv( green );
    glVertex3fv( v1 );
    emColor4ubv( black );
    glVertex3fv( v5 );
    emColor4ubv( orange );
    glVertex3fv( v6 );
    
    emColor4ubv( green );
    glVertex3fv( v1 );
    emColor4ubv( orange );
    glVertex3fv( v6 );
    emColor4ubv( blue );
    glVertex3fv( v2 );
    
    emColor4ubv( black );
    glVertex3fv( v5 );
    emColor4ubv( yellow );
    glVertex3fv( v4 );
    emColor4ubv( purple );
    glVertex3fv( v7 );
    
    emColor4ubv( black );
    glVertex3fv( v5 );
    emColor4ubv( purple );
    glVertex3fv( v7 );
    emColor4ubv( orange );
    glVertex3fv( v6 );
    
    emColor4ubv( yellow );
    glVertex3fv( v4 );
    emColor4ubv( red );
    glVertex3fv( v0 );
    emColor4ubv( white );
    glVertex3fv( v3 );
    
    emColor4ubv( yellow );
    glVertex3fv( v4 );
    emColor4ubv( white );
    glVertex3fv( v3 );
    emColor4ubv( purple );
    glVertex3fv( v7 );
    
    emColor4ubv( white );
    glVertex3fv( v3 );
    emColor4ubv( blue );
    glVertex3fv( v2 );
    emColor4ubv( orange );
    glVertex3fv( v6 );
    
    emColor4ubv( white );
    glVertex3fv( v3 );
    emColor4ubv( orange );
    glVertex3fv( v6 );
    emColor4ubv( purple );
    glVertex3fv( v7 );
    
    emColor4ubv( green );
    glVertex3fv( v1 );
    emColor4ubv( red );
    glVertex3fv( v0 );
    emColor4ubv( yellow );
    glVertex3fv( v4 );
    
    emColor4ubv( green );
    glVertex3fv( v1 );
    emColor4ubv( yellow );
    glVertex3fv( v4 );
    emColor4ubv( black );
    glVertex3fv( v5 );
    
    glEnd( );
    
    /*
     * EXERCISE:
     * Draw text telling the user that 'Spc'
     * pauses the rotation and 'Esc' quits.
     * Do it using vetors and textured quads.
     */
    
    /*
     * Swap the buffers. This this tells the driver to
     * render the next frame from the contents of the
     * back-buffer, and to set all rendering operations
     * to occur on what was the front-buffer.
     *
     * Double buffering prevents nasty visual tearing
     * from the application drawing on areas of the
     * screen that are being updated at the same time.
     */
    SDL_GL_SwapBuffers( );
}

__attribute__((used)) static void setup_opengl( int width, int height )
{
    float ratio = (float) width / (float) height;
    
    /* Our shading model--Gouraud (smooth). */
    glShadeModel( GL_SMOOTH );
    
    /* Culling. */
    glCullFace( GL_BACK );
    glFrontFace( GL_CCW );
    glEnable( GL_CULL_FACE );
    
    /* Set the clear color. */
    glClearColor( 0, 0, 0, 0 );
    
    /* Setup our viewport. */
    glViewport( 0, 0, width, height );
    
    /*
     * Change to the projection matrix and set
     * our viewing volume.
     */
    glMatrixMode( GL_PROJECTION );
    glLoadIdentity( );
    /*
     * EXERCISE:
     * Replace this with a call to glFrustum.
     */
    gluPerspective( 60.0, ratio, 1.0, 1024.0 );
}

void one_iter() {
    process_events( );
    /* Draw the screen. */
    draw_screen( );
}

int main( int argc, char* argv[] )
{
    /* Information about the current video settings. */
    const SDL_VideoInfo* info = NULL;
    /* Dimensions of our window. */
    int width = 0;
    int height = 0;
    /* Color depth in bits of our window. */
    int bpp = 0;
    /* Flags we will pass into SDL_SetVideoMode. */
    int flags = 0;
    
    /* First, initialize SDL's video subsystem. */
    if( SDL_Init( SDL_INIT_VIDEO ) < 0 ) {
        /* Failed, exit. */
        fprintf( stderr, "Video initialization failed: %s\n",
                SDL_GetError( ) );
        quit_tutorial( 1 );
    }
    
    /* Let's get some video information. */
    info = SDL_GetVideoInfo( );
    
    if( !info ) {
        /* This should probably never happen. */
        fprintf( stderr, "Video query failed: %s\n",
                SDL_GetError( ) );
        quit_tutorial( 1 );
    }
    
    /*
     * Set our width/height to 640/480 (you would
     * of course let the user decide this in a normal
     * app). We get the bpp we will request from
     * the display. On X11, VidMode can't change
     * resolution, so this is probably being overly
     * safe. Under Win32, ChangeDisplaySettings
     * can change the bpp.
     */
    width = 640;
    height = 480;
    bpp = info->vfmt->BitsPerPixel;
    
    /*
     * Now, we want to setup our requested
     * window attributes for our OpenGL window.
     * We want *at least* 5 bits of red, green
     * and blue. We also want at least a 16-bit
     * depth buffer.
     *
     * The last thing we do is request a double
     * buffered window. '1' turns on double
     * buffering, '0' turns it off.
     *
     * Note that we do not use SDL_DOUBLEBUF in
     * the flags to SDL_SetVideoMode. That does
     * not affect the GL attribute state, only
     * the standard 2D blitting setup.
     */
//    SDL_GL_SetAttribute( SDL_GL_RED_SIZE, 5 );
//    SDL_GL_SetAttribute( SDL_GL_GREEN_SIZE, 5 );
//    SDL_GL_SetAttribute( SDL_GL_BLUE_SIZE, 5 );
//    SDL_GL_SetAttribute( SDL_GL_DEPTH_SIZE, 16 );
//    SDL_GL_SetAttribute( SDL_GL_DOUBLEBUFFER, 1 );
    
    /*
     * We want to request that SDL provide us
     * with an OpenGL window, in a fullscreen
     * video mode.
     *
     * EXERCISE:
     * Make starting windowed an option, and
     * handle the resize events properly with
     * glViewport.
     */
    flags = SDL_OPENGL;// | SDL_FULLSCREEN;
    
    /*
     * Set the video mode
     */
    if( SDL_SetVideoMode( width, height, bpp, flags ) == 0 ) {
        /*
         * This could happen for a variety of reasons,
         * including DISPLAY not being set, the specified
         * resolution not being available, etc.
         */
        fprintf( stderr, "Video mode set failed: %s\n",
                SDL_GetError( ) );
        quit_tutorial( 1 );
    }
    
    /*
     * At this point, we should have a properly setup
     * double-buffered window for use with OpenGL.
     */
    setup_opengl( width, height );
    
    /*
     * Now we want to begin our normal app process--
     * an event loop with a lot of redrawing.
     */
    one_iter(); // just one for testing purposes

#ifndef __EMSCRIPTEN__
    SDL_Delay(2000);
#endif    
    
    /*
     * EXERCISE:
     * Record timings using SDL_GetTicks() and
     * and print out frames per second at program
     * end.
     */
    
    /* Never reached. */
    return 0;
}

