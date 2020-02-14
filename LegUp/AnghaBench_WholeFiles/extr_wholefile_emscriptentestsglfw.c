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
typedef  float GLfloat ;

/* Variables and functions */
 void Draw () ; 
#define  GLFW_ACCELERATED 240 
#define  GLFW_ACCUM_ALPHA_BITS 239 
#define  GLFW_ACCUM_BLUE_BITS 238 
#define  GLFW_ACCUM_GREEN_BITS 237 
#define  GLFW_ACCUM_RED_BITS 236 
#define  GLFW_ACTIVE 235 
#define  GLFW_ALPHA_BITS 234 
#define  GLFW_ALPHA_MAP_BIT 233 
#define  GLFW_AUTO_POLL_EVENTS 232 
#define  GLFW_AUX_BUFFERS 231 
#define  GLFW_BLUE_BITS 230 
#define  GLFW_BUILD_MIPMAPS_BIT 229 
#define  GLFW_BUTTONS 228 
#define  GLFW_DEPTH_BITS 227 
#define  GLFW_FSAA_SAMPLES 226 
#define  GLFW_FULLSCREEN 225 
#define  GLFW_GREEN_BITS 224 
#define  GLFW_ICONIFIED 223 
#define  GLFW_KEY_BACKSPACE 222 
#define  GLFW_KEY_CAPS_LOCK 221 
#define  GLFW_KEY_DEL 220 
#define  GLFW_KEY_DOWN 219 
#define  GLFW_KEY_END 218 
#define  GLFW_KEY_ENTER 217 
#define  GLFW_KEY_ESC 216 
#define  GLFW_KEY_F1 215 
#define  GLFW_KEY_F10 214 
#define  GLFW_KEY_F11 213 
#define  GLFW_KEY_F12 212 
#define  GLFW_KEY_F13 211 
#define  GLFW_KEY_F14 210 
#define  GLFW_KEY_F15 209 
#define  GLFW_KEY_F16 208 
#define  GLFW_KEY_F17 207 
#define  GLFW_KEY_F18 206 
#define  GLFW_KEY_F19 205 
#define  GLFW_KEY_F2 204 
#define  GLFW_KEY_F20 203 
#define  GLFW_KEY_F21 202 
#define  GLFW_KEY_F22 201 
#define  GLFW_KEY_F23 200 
#define  GLFW_KEY_F24 199 
#define  GLFW_KEY_F25 198 
#define  GLFW_KEY_F3 197 
#define  GLFW_KEY_F4 196 
#define  GLFW_KEY_F5 195 
#define  GLFW_KEY_F6 194 
#define  GLFW_KEY_F7 193 
#define  GLFW_KEY_F8 192 
#define  GLFW_KEY_F9 191 
#define  GLFW_KEY_HOME 190 
#define  GLFW_KEY_INSERT 189 
#define  GLFW_KEY_KP_0 188 
#define  GLFW_KEY_KP_1 187 
#define  GLFW_KEY_KP_2 186 
#define  GLFW_KEY_KP_3 185 
#define  GLFW_KEY_KP_4 184 
#define  GLFW_KEY_KP_5 183 
#define  GLFW_KEY_KP_6 182 
#define  GLFW_KEY_KP_7 181 
#define  GLFW_KEY_KP_8 180 
#define  GLFW_KEY_KP_9 179 
#define  GLFW_KEY_KP_ADD 178 
#define  GLFW_KEY_KP_DECIMAL 177 
#define  GLFW_KEY_KP_DIVIDE 176 
#define  GLFW_KEY_KP_ENTER 175 
#define  GLFW_KEY_KP_EQUAL 174 
#define  GLFW_KEY_KP_MULTIPLY 173 
#define  GLFW_KEY_KP_NUM_LOCK 172 
#define  GLFW_KEY_KP_SUBTRACT 171 
#define  GLFW_KEY_LALT 170 
#define  GLFW_KEY_LCTRL 169 
#define  GLFW_KEY_LEFT 168 
#define  GLFW_KEY_LSHIFT 167 
#define  GLFW_KEY_LSUPER 166 
#define  GLFW_KEY_MENU 165 
#define  GLFW_KEY_PAGEDOWN 164 
#define  GLFW_KEY_PAGEUP 163 
#define  GLFW_KEY_PAUSE 162 
#define  GLFW_KEY_RALT 161 
#define  GLFW_KEY_RCTRL 160 
#define  GLFW_KEY_REPEAT 159 
#define  GLFW_KEY_RIGHT 158 
#define  GLFW_KEY_RSHIFT 157 
#define  GLFW_KEY_RSUPER 156 
#define  GLFW_KEY_SCROLL_LOCK 155 
#define  GLFW_KEY_SPACE 154 
#define  GLFW_KEY_SPECIAL 153 
#define  GLFW_KEY_TAB 152 
#define  GLFW_KEY_UNKNOWN 151 
#define  GLFW_KEY_UP 150 
 int GLFW_MOUSE_BUTTON_1 ; 
 int GLFW_MOUSE_BUTTON_LEFT ; 
#define  GLFW_MOUSE_CURSOR 149 
#define  GLFW_NOWAIT 148 
#define  GLFW_NO_RESCALE_BIT 147 
#define  GLFW_OPENED 146 
#define  GLFW_OPENGL_COMPAT_PROFILE 145 
#define  GLFW_OPENGL_CORE_PROFILE 144 
#define  GLFW_OPENGL_DEBUG_CONTEXT 143 
#define  GLFW_OPENGL_FORWARD_COMPAT 142 
#define  GLFW_OPENGL_PROFILE 141 
#define  GLFW_OPENGL_VERSION_MAJOR 140 
#define  GLFW_OPENGL_VERSION_MINOR 139 
#define  GLFW_ORIGIN_UL_BIT 138 
 int GLFW_PRESS ; 
#define  GLFW_RED_BITS 137 
#define  GLFW_REFRESH_RATE 136 
 int GLFW_RELEASE ; 
#define  GLFW_STENCIL_BITS 135 
#define  GLFW_STEREO 134 
#define  GLFW_STICKY_KEYS 133 
#define  GLFW_STICKY_MOUSE_BUTTONS 132 
#define  GLFW_SYSTEM_KEYS 131 
#define  GLFW_WAIT 130 
#define  GLFW_WINDOW 129 
#define  GLFW_WINDOW_NO_RESIZE 128 
 int GL_COLOR_BUFFER_BIT ; 
 int GL_DEPTH_BUFFER_BIT ; 
 int /*<<< orphan*/  GL_MODELVIEW ; 
 int /*<<< orphan*/  GL_PROJECTION ; 
 int /*<<< orphan*/  GL_TRIANGLES ; 
 scalar_t__ GL_TRUE ; 
 void Init () ; 
 void Iteration () ; 
 void OnCharPressed (int,int) ; 
 int OnClose () ; 
 void OnKeyPressed (int,int) ; 
 void OnMouseClick (int,int) ; 
 void OnMouseMove (int,int) ; 
 void OnMouseWheel (int) ; 
 void OnRefresh () ; 
 void OnResize (int,int) ; 
 void PullInfo () ; 
 void Shut_Down (int) ; 
 int /*<<< orphan*/  assert (int) ; 
 int /*<<< orphan*/  emscripten_set_main_loop (void (*) (),int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  exit (int) ; 
 int /*<<< orphan*/  glBegin (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  glClear (int) ; 
 int /*<<< orphan*/  glClearColor (float,float,float,float) ; 
 int /*<<< orphan*/  glColor3f (float,float,float) ; 
 int /*<<< orphan*/  glEnd () ; 
 int /*<<< orphan*/  glFrustum (double,double,double,double,int,int) ; 
 int /*<<< orphan*/  glLoadIdentity () ; 
 int /*<<< orphan*/  glMatrixMode (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  glRotatef (float,float,float,float) ; 
 int /*<<< orphan*/  glTranslatef (float,float,float) ; 
 int /*<<< orphan*/  glVertex3f (float,float,float) ; 
 int /*<<< orphan*/  glViewport (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int,int) ; 
 int /*<<< orphan*/  glfwEnable (int) ; 
 scalar_t__ glfwExtensionSupported (char const*) ; 
 int /*<<< orphan*/  glfwGetGLVersion (int*,int*,int*) ; 
 int glfwGetKey (int const) ; 
 int glfwGetMouseButton (int) ; 
 int /*<<< orphan*/  glfwGetMousePos (int*,int*) ; 
 int glfwGetMouseWheel () ; 
 int glfwGetNumberOfProcessors () ; 
 void* glfwGetProcAddress (char const*) ; 
 double glfwGetTime () ; 
 int /*<<< orphan*/  glfwGetVersion (int*,int*,int*) ; 
 int glfwGetWindowParam (int) ; 
 int /*<<< orphan*/  glfwGetWindowSize (int*,int*) ; 
 scalar_t__ glfwInit () ; 
 scalar_t__ glfwOpenWindow (int const,int const,int,int,int,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  glfwOpenWindowHint (int,int) ; 
 int /*<<< orphan*/  glfwSetCharCallback (void (*) (int,int)) ; 
 int /*<<< orphan*/  glfwSetKeyCallback (void (*) (int,int)) ; 
 int /*<<< orphan*/  glfwSetMouseButtonCallback (void (*) (int,int)) ; 
 int /*<<< orphan*/  glfwSetMousePosCallback (void (*) (int,int)) ; 
 int /*<<< orphan*/  glfwSetMouseWheelCallback (void (*) (int)) ; 
 int /*<<< orphan*/  glfwSetWindowCloseCallback (int (*) ()) ; 
 int /*<<< orphan*/  glfwSetWindowRefreshCallback (void (*) ()) ; 
 int /*<<< orphan*/  glfwSetWindowSizeCallback (void (*) (int,int)) ; 
 int /*<<< orphan*/  glfwSetWindowTitle (char*) ; 
 int /*<<< orphan*/  glfwSleep (int) ; 
 int /*<<< orphan*/  glfwSwapBuffers () ; 
 int /*<<< orphan*/  glfwSwapInterval (int) ; 
 int /*<<< orphan*/  glfwTerminate () ; 
 int /*<<< orphan*/  gluLookAt (float,float,float,float,float,float,float,float,float) ; 
 int /*<<< orphan*/  gluPerspective (float,float,float,float) ; 
 char* malloc (int) ; 
 unsigned int nb_params ; 
 double old_time ; 
 int on_resize_called ; 
 int* params ; 
 int /*<<< orphan*/  printf (char*,...) ; 
 double rotate_y ; 
 double rotate_z ; 
 double rotations_per_tick ; 

int main(void)
{
  Init();
  old_time = glfwGetTime();
  emscripten_set_main_loop (Iteration, 0, 1);
  Shut_Down(0);
}

void Init()
{
  const int window_width = 800,
           window_height = 600;
 
  if (glfwInit() != GL_TRUE)
    Shut_Down(1);

  glfwEnable(GLFW_KEY_REPEAT); // test for issue #3059

  int red_bits = glfwGetWindowParam(GLFW_RED_BITS);
  glfwOpenWindowHint(GLFW_RED_BITS, 8);
  assert(glfwGetWindowParam(GLFW_RED_BITS) == 8);
  glfwOpenWindowHint(GLFW_RED_BITS, red_bits);

  // 800 x 600, 16 bit color, no depth, alpha or stencil buffers, windowed
  if (glfwOpenWindow(window_width, window_height, 5, 6, 5,
                  0, 0, 0, GLFW_WINDOW) != GL_TRUE)
    Shut_Down(1);
  glfwSetWindowTitle("The GLFW Window");
 
  glfwSetKeyCallback(OnKeyPressed);
  glfwSetCharCallback(OnCharPressed);
  glfwSetWindowCloseCallback(OnClose);
  glfwSetWindowSizeCallback(OnResize);
  if (!on_resize_called)
  {
    Shut_Down(1);
  }

  glfwSetWindowRefreshCallback(OnRefresh);
  glfwSetMouseWheelCallback(OnMouseWheel);
  glfwSetMousePosCallback(OnMouseMove);
  glfwSetMouseButtonCallback(OnMouseClick);
  
  // set the projection matrix to a normal frustum with a max depth of 50
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  float aspect_ratio = ((float)window_height) / window_width;
  glFrustum(.5, -.5, -.5 * aspect_ratio, .5 * aspect_ratio, 1, 50);
  glMatrixMode(GL_MODELVIEW);
  
  PullInfo();
}

void Shut_Down(int return_code)
{
  glfwTerminate();
  exit(return_code);
}

void Iteration()
{
    // calculate time elapsed, and the amount by which stuff rotates
    double current_time = glfwGetTime(),
          delta_rotate = (current_time - old_time) * rotations_per_tick * 360;
    old_time = current_time;
    if (glfwGetKey(GLFW_KEY_LEFT) == GLFW_PRESS)
      rotate_y += delta_rotate;
    if (glfwGetKey(GLFW_KEY_RIGHT) == GLFW_PRESS)
      rotate_y -= delta_rotate;
    // z axis always rotates
    rotate_z += delta_rotate;
 
    // clear the buffer
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    // draw the figure
    Draw();

    // Test that glfwSwapInterval doesn't crash (although we don't test actual timings)
    static int i = 0;
    glfwSwapInterval(i);
    if (i < 2) ++i;

    // swap back and front buffers
    glfwSwapBuffers();
}

void Draw(void)
{
  int width, height, x;
  double t;

  t = glfwGetTime ();
  glfwGetMousePos (&x, NULL);

  // Get window size (may be different than the requested size)
  glfwGetWindowSize (&width, &height);

  // Special case: avoid division by zero below
  height = height > 0 ? height : 1;

  glViewport (0, 0, width, height);
  // Clear color buffer to black
  glClearColor (0.1f, 0.2f, 0.3f, 0.0f);
  glClear (GL_COLOR_BUFFER_BIT);

  // Select and setup the projection matrix
  glMatrixMode (GL_PROJECTION);
  glLoadIdentity ();
  gluPerspective (65.0f, (GLfloat) width / (GLfloat) height, 1.0f, 100.0f);

  // Select and setup the modelview matrix
  glMatrixMode (GL_MODELVIEW);
  glLoadIdentity ();
  gluLookAt (0.0f, 1.0f, 0.0f,	// Eye-position
	     0.0f, 20.0f, 0.0f,	// View-point
	     0.0f, 0.0f, 1.0f);	// Up-vector

  // Draw a rotating colorful triangle
  //glTranslatef (0.0f, 14.0f, 0.0f);
  glTranslatef (0.0f, 1.0f, 0.0f);
  glRotatef (0.3f * (GLfloat) x + (GLfloat) t * 100.0f, 0.0f, 0.0f, 1.0f);
  glBegin (GL_TRIANGLES);
  glColor3f (1.0f, 0.0f, 0.0f);
  glVertex3f (-5.0f, 0.0f, -4.0f);
  glColor3f (0.0f, 1.0f, 0.0f);
  glVertex3f (5.0f, 0.0f, -4.0f);
  glColor3f (0.0f, 0.0f, 1.0f);
  glVertex3f (0.0f, 0.0f, 6.0f);
  glEnd ();

  // Swap buffers
  glfwSwapBuffers ();
}

void OnCharPressed( int character, int action ){
  if(action == GLFW_PRESS)
    printf("'%c' (%i) char is pressed\n", character, character);
  if(action == GLFW_RELEASE)
    printf("'%c' (%i) char is released\n", character, character);
}

char* GetKeyName(int key){
  switch(key){
    case GLFW_KEY_UNKNOWN: return "unknown";
    case GLFW_KEY_SPACE: return "space";
    case GLFW_KEY_SPECIAL: return "special";
    case GLFW_KEY_ESC: return "escape";
    case GLFW_KEY_F1 : return "F1";
    case GLFW_KEY_F2 : return "F2";
    case GLFW_KEY_F3 : return "F3";
    case GLFW_KEY_F4 : return "F4";
    case GLFW_KEY_F5 : return "F5";
    case GLFW_KEY_F6 : return "F6";
    case GLFW_KEY_F7 : return "F7";
    case GLFW_KEY_F8 : return "F8";
    case GLFW_KEY_F9 : return "F9";
    case GLFW_KEY_F10: return "F10";
    case GLFW_KEY_F11: return "F11";
    case GLFW_KEY_F12: return "F12";
    case GLFW_KEY_F13: return "F13";
    case GLFW_KEY_F14: return "F14";
    case GLFW_KEY_F15: return "F15";
    case GLFW_KEY_F16: return "F16";
    case GLFW_KEY_F17: return "F17";
    case GLFW_KEY_F18: return "F18";
    case GLFW_KEY_F19: return "F19";
    case GLFW_KEY_F20: return "F20";
    case GLFW_KEY_F21: return "F21";
    case GLFW_KEY_F22: return "F22";
    case GLFW_KEY_F23: return "F23";
    case GLFW_KEY_F24: return "F24";
    case GLFW_KEY_F25: return "F25";
    case GLFW_KEY_UP : return "up";
    case GLFW_KEY_DOWN: return "down";
    case GLFW_KEY_LEFT: return "left";
    case GLFW_KEY_RIGHT: return "right";
    case GLFW_KEY_LSHIFT: return "left shift";
    case GLFW_KEY_RSHIFT: return "right shift";
    case GLFW_KEY_LCTRL: return "left ctrl";
    case GLFW_KEY_RCTRL: return "right ctrl";
    case GLFW_KEY_LALT: return "left alt";
    case GLFW_KEY_RALT: return "right alt";
    case GLFW_KEY_TAB: return "tab";
    case GLFW_KEY_ENTER: return "enter";
    case GLFW_KEY_BACKSPACE: return "backspace";
    case GLFW_KEY_INSERT: return "insertr";
    case GLFW_KEY_DEL: return "del";
    case GLFW_KEY_PAGEUP: return "page up";
    case GLFW_KEY_PAGEDOWN: return "page down";
    case GLFW_KEY_HOME: return "home";
    case GLFW_KEY_END: return "end";
    case GLFW_KEY_KP_0: return "0";
    case GLFW_KEY_KP_1: return "1";
    case GLFW_KEY_KP_2: return "2";
    case GLFW_KEY_KP_3: return "3";
    case GLFW_KEY_KP_4: return "4";
    case GLFW_KEY_KP_5: return "5";
    case GLFW_KEY_KP_6: return "6";
    case GLFW_KEY_KP_7: return "7";
    case GLFW_KEY_KP_8: return "8";
    case GLFW_KEY_KP_9: return "9";
    case GLFW_KEY_KP_DIVIDE: return "/";
    case GLFW_KEY_KP_MULTIPLY: return "*";
    case GLFW_KEY_KP_SUBTRACT: return "-";
    case GLFW_KEY_KP_ADD: return "+";
    case GLFW_KEY_KP_DECIMAL: return ".";
    case GLFW_KEY_KP_EQUAL: return "=";
    case GLFW_KEY_KP_ENTER: return "enter";
    case GLFW_KEY_KP_NUM_LOCK: return "num lock";
    case GLFW_KEY_CAPS_LOCK: return "caps lock";
    case GLFW_KEY_SCROLL_LOCK: return "scroll lock";
    case GLFW_KEY_PAUSE: return "pause";
    case GLFW_KEY_LSUPER: return "left super";
    case GLFW_KEY_RSUPER: return "right super";
    case GLFW_KEY_MENU: return "menu";
    }
    char* chr = malloc(2*sizeof(char));
    chr[0] = key;
    chr[1] = '\0';
    return chr;
}

char* GetParamName(int param){
  switch(param){
    case GLFW_WINDOW               : return "GLFW_WINDOW";
    case GLFW_FULLSCREEN           : return "GLFW_FULLSCREEN";
    case GLFW_OPENED               : return "GLFW_OPENED";
    case GLFW_ACTIVE               : return "GLFW_ACTIVE";
    case GLFW_ICONIFIED            : return "GLFW_ICONIFIED";
    case GLFW_ACCELERATED          : return "GLFW_ACCELERATED";
    case GLFW_RED_BITS             : return "GLFW_RED_BITS";
    case GLFW_GREEN_BITS           : return "GLFW_GREEN_BITS";
    case GLFW_BLUE_BITS            : return "GLFW_BLUE_BITS";
    case GLFW_ALPHA_BITS           : return "GLFW_ALPHA_BITS";
    case GLFW_DEPTH_BITS           : return "GLFW_DEPTH_BITS";
    case GLFW_STENCIL_BITS         : return "GLFW_STENCIL_BITS";
    case GLFW_REFRESH_RATE         : return "GLFW_REFRESH_RATE";
    case GLFW_ACCUM_RED_BITS       : return "GLFW_ACCUM_RED_BITS";
    case GLFW_ACCUM_GREEN_BITS     : return "GLFW_ACCUM_GREEN_BITS";
    case GLFW_ACCUM_BLUE_BITS      : return "GLFW_BLUE_BITS";
    case GLFW_ACCUM_ALPHA_BITS     : return "GLFW_ALPHA_BITS";
    case GLFW_AUX_BUFFERS          : return "GLFW_AUX_BUFFERS";
    case GLFW_STEREO               : return "GLFW_STEREO";
    case GLFW_WINDOW_NO_RESIZE     : return "GLFW_WINDOW_NO_RESIZE";
    case GLFW_FSAA_SAMPLES         : return "GLFW_FSAA_SAMPLES";
    case GLFW_OPENGL_VERSION_MAJOR : return "GLFW_OPENGL_VERSION_MAJOR";
    case GLFW_OPENGL_VERSION_MINOR : return "GLFW_OPENGL_VERSION_MINOR";
    case GLFW_OPENGL_FORWARD_COMPAT : return "GLFW_OPENGL_FORWARD_COMPAT";
    case GLFW_OPENGL_DEBUG_CONTEXT : return "GLFW_OPENGL_DEBUG_CONTEXT";
    case GLFW_OPENGL_PROFILE       : return "GLFW_OPENGL_PROFILE";
    case GLFW_OPENGL_CORE_PROFILE  : return "GLFW_OPENGL_CORE_PROFILE | GLFW_PRESENT";
    case GLFW_OPENGL_COMPAT_PROFILE : return "GLFW_OPENGL_COMPAT_PROFILE | GLFW_AXES";
    case GLFW_MOUSE_CURSOR         : return "GLFW_MOUSE_CURSOR";
    case GLFW_STICKY_KEYS          : return "GLFW_STICKY_KEYS";
    case GLFW_STICKY_MOUSE_BUTTONS : return "GLFW_STICKY_MOUSE_BUTTONS";
    case GLFW_SYSTEM_KEYS          : return "GLFW_SYSTEM_KEYS";
    case GLFW_KEY_REPEAT           : return "GLFW_KEY_REPEAT";
    case GLFW_AUTO_POLL_EVENTS     : return "GLFW_AUTO_POLL_EVENTS";
    case GLFW_WAIT                 : return "GLFW_WAIT";
    case GLFW_NOWAIT               : return "GLFW_NOWAIT";
    case GLFW_BUTTONS              : return "GLFW_BUTTONS";
    case GLFW_NO_RESCALE_BIT       : return "GLFW_NO_RESCALE_BIT";
    case GLFW_ORIGIN_UL_BIT        : return "GLFW_ORIGIN_UL_BIT";
    case GLFW_BUILD_MIPMAPS_BIT    : return "GLFW_BUILD_MIPMAPS_BIT";
    case GLFW_ALPHA_MAP_BIT        : return "GLFW_ALPHA_MAP_BIT";
    default                        : return "Invalid param";
  }
}

void OnKeyPressed( int key, int action ){
  const char* key_name = GetKeyName(key);
  if(key_name == 0)
    return;
  if(action == GLFW_PRESS)
    printf("'%s' (%i) key is pressed\n", key_name, key);
  if(action == GLFW_RELEASE)
    printf("'%s' (%i) key is released\n", key_name, key);
  if(action == GLFW_RELEASE && key == GLFW_KEY_ENTER)
    PullInfo();
}

int OnClose(){
  printf("Closed\n");
  return 0;
}

void OnRefresh(){
  printf("Refresh\n");
}

void OnResize( int width, int height ){
  on_resize_called = 1;
  printf("Resizing to %i %i\n", width, height);
}

void OnMouseClick( int button, int action ){
  if(action == GLFW_PRESS)
    printf("Mouse button %i has been pressed\n", button);
  if(action == GLFW_RELEASE)
    printf("Mouse button %i has been released\n", button);
}

void OnMouseMove( int x, int y ){
  int lState = glfwGetMouseButton(GLFW_MOUSE_BUTTON_LEFT);

	if (lState == GLFW_PRESS)
    printf("Dragged %i to %i %i\n", GLFW_MOUSE_BUTTON_LEFT, x, y);
  if(lState == GLFW_RELEASE)
    printf("Moved %i to %i %i\n", GLFW_MOUSE_BUTTON_LEFT, x, y);
}

void OnMouseWheel( int pos ){
  printf("Mouse wheel has been moved to %i\n", pos);
}

void PullInfo(){
  printf("================================================================================\n");
  
  int major, minor, rev;
  glfwGetVersion(&major, &minor, &rev);
  printf("GLFW version is %i.%i.%i\n", major, minor, rev);
  
  int width, height;
  glfwGetWindowSize(&width, &height);
  printf("Window size is %i %i\n", width, height);
  
  int status = glfwGetKey(GLFW_KEY_LCTRL);
  if(status == GLFW_PRESS)
    printf("Left control is pressed\n");
  else
    printf("Left control is released\n");
    
  status = glfwGetMouseButton(GLFW_MOUSE_BUTTON_1);
  if(status == GLFW_PRESS)
    printf("Mouse button 1 is pressed\n");
  else
    printf("Mouse button 1 is released\n");
    
  int x, y;
  glfwGetMousePos(&x, &y);
  printf("Mouse position is %i %i\n", x, y);
  
  int wheel = glfwGetMouseWheel();
  printf("Mouse wheel pos is %i\n", wheel);
  
  double time = glfwGetTime();
  printf("Time is %f\n", time);
  
  glfwGetGLVersion(&major, &minor, &rev);
  printf("GL version is %i.%i.%i\n", major, minor, rev);
  
  int proc = glfwGetNumberOfProcessors();
  printf("%i processors are available\n", proc);
  
  unsigned int i;
  for(i = 0; i<nb_params; i++)
    printf(" - %-27s : %i\n", GetParamName(params[i]), glfwGetWindowParam(params[i]));
  
  const char* extension = "WEBGL_compressed_texture_s3tc";
  printf("'%s' extension is %s.\n", extension, glfwExtensionSupported(extension) ? "supported" : "not supported");  
  
  extension = "GL_EXT_framebuffer_object";
  printf("'%s' extension is %s.\n", extension, glfwExtensionSupported(extension) ? "supported" : "not supported");
  
  extension = "glBindBuffer";
  void* proc_addr = glfwGetProcAddress(extension);
  printf("'%s' extension proc address is %p.\n", extension, proc_addr);
  
  printf("Sleeping 1 sec...\n");
  glfwSleep(1);
  printf("...Done.\n");
  
  printf("================================================================================\n");
  
#ifdef REPORT_RESULT  
  REPORT_RESULT(1);
#endif
}

