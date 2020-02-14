#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_9__   TYPE_2__ ;
typedef  struct TYPE_8__   TYPE_1__ ;

/* Type definitions */
struct TYPE_9__ {int width; int height; int /*<<< orphan*/  blueBits; int /*<<< orphan*/  greenBits; int /*<<< orphan*/  redBits; int /*<<< orphan*/  refreshRate; } ;
struct TYPE_8__ {int number; int closeable; int /*<<< orphan*/ * window; } ;
typedef  TYPE_1__ Slot ;
typedef  int /*<<< orphan*/  GLFWwindow ;
typedef  TYPE_2__ GLFWvidmode ;
typedef  int /*<<< orphan*/  GLFWmonitor ;

/* Variables and functions */
 int /*<<< orphan*/  EXIT_FAILURE ; 
 int /*<<< orphan*/  EXIT_SUCCESS ; 
 int /*<<< orphan*/  GLFW_BLUE_BITS ; 
 int GLFW_CONNECTED ; 
 int /*<<< orphan*/  GLFW_GREEN_BITS ; 
#define  GLFW_KEY_0 253 
#define  GLFW_KEY_1 252 
#define  GLFW_KEY_2 251 
#define  GLFW_KEY_3 250 
#define  GLFW_KEY_4 249 
#define  GLFW_KEY_5 248 
#define  GLFW_KEY_6 247 
#define  GLFW_KEY_7 246 
#define  GLFW_KEY_8 245 
#define  GLFW_KEY_9 244 
#define  GLFW_KEY_A 243 
#define  GLFW_KEY_APOSTROPHE 242 
#define  GLFW_KEY_B 241 
#define  GLFW_KEY_BACKSLASH 240 
#define  GLFW_KEY_BACKSPACE 239 
#define  GLFW_KEY_C 238 
#define  GLFW_KEY_CAPS_LOCK 237 
#define  GLFW_KEY_COMMA 236 
#define  GLFW_KEY_D 235 
#define  GLFW_KEY_DELETE 234 
#define  GLFW_KEY_DOWN 233 
#define  GLFW_KEY_E 232 
#define  GLFW_KEY_END 231 
#define  GLFW_KEY_ENTER 230 
#define  GLFW_KEY_EQUAL 229 
#define  GLFW_KEY_ESCAPE 228 
#define  GLFW_KEY_F 227 
#define  GLFW_KEY_F1 226 
#define  GLFW_KEY_F10 225 
#define  GLFW_KEY_F11 224 
#define  GLFW_KEY_F12 223 
#define  GLFW_KEY_F13 222 
#define  GLFW_KEY_F14 221 
#define  GLFW_KEY_F15 220 
#define  GLFW_KEY_F16 219 
#define  GLFW_KEY_F17 218 
#define  GLFW_KEY_F18 217 
#define  GLFW_KEY_F19 216 
#define  GLFW_KEY_F2 215 
#define  GLFW_KEY_F20 214 
#define  GLFW_KEY_F21 213 
#define  GLFW_KEY_F22 212 
#define  GLFW_KEY_F23 211 
#define  GLFW_KEY_F24 210 
#define  GLFW_KEY_F25 209 
#define  GLFW_KEY_F3 208 
#define  GLFW_KEY_F4 207 
#define  GLFW_KEY_F5 206 
#define  GLFW_KEY_F6 205 
#define  GLFW_KEY_F7 204 
#define  GLFW_KEY_F8 203 
#define  GLFW_KEY_F9 202 
#define  GLFW_KEY_G 201 
#define  GLFW_KEY_GRAVE_ACCENT 200 
#define  GLFW_KEY_H 199 
#define  GLFW_KEY_HOME 198 
#define  GLFW_KEY_I 197 
#define  GLFW_KEY_INSERT 196 
#define  GLFW_KEY_J 195 
#define  GLFW_KEY_K 194 
#define  GLFW_KEY_KP_0 193 
#define  GLFW_KEY_KP_1 192 
#define  GLFW_KEY_KP_2 191 
#define  GLFW_KEY_KP_3 190 
#define  GLFW_KEY_KP_4 189 
#define  GLFW_KEY_KP_5 188 
#define  GLFW_KEY_KP_6 187 
#define  GLFW_KEY_KP_7 186 
#define  GLFW_KEY_KP_8 185 
#define  GLFW_KEY_KP_9 184 
#define  GLFW_KEY_KP_ADD 183 
#define  GLFW_KEY_KP_DECIMAL 182 
#define  GLFW_KEY_KP_DIVIDE 181 
#define  GLFW_KEY_KP_ENTER 180 
#define  GLFW_KEY_KP_EQUAL 179 
#define  GLFW_KEY_KP_MULTIPLY 178 
#define  GLFW_KEY_KP_SUBTRACT 177 
#define  GLFW_KEY_L 176 
#define  GLFW_KEY_LEFT 175 
#define  GLFW_KEY_LEFT_ALT 174 
#define  GLFW_KEY_LEFT_BRACKET 173 
#define  GLFW_KEY_LEFT_CONTROL 172 
#define  GLFW_KEY_LEFT_SHIFT 171 
#define  GLFW_KEY_LEFT_SUPER 170 
#define  GLFW_KEY_M 169 
#define  GLFW_KEY_MENU 168 
#define  GLFW_KEY_MINUS 167 
#define  GLFW_KEY_N 166 
#define  GLFW_KEY_NUM_LOCK 165 
#define  GLFW_KEY_O 164 
#define  GLFW_KEY_P 163 
#define  GLFW_KEY_PAGE_DOWN 162 
#define  GLFW_KEY_PAGE_UP 161 
#define  GLFW_KEY_PAUSE 160 
#define  GLFW_KEY_PERIOD 159 
#define  GLFW_KEY_PRINT_SCREEN 158 
#define  GLFW_KEY_Q 157 
#define  GLFW_KEY_R 156 
#define  GLFW_KEY_RIGHT 155 
#define  GLFW_KEY_RIGHT_ALT 154 
#define  GLFW_KEY_RIGHT_BRACKET 153 
#define  GLFW_KEY_RIGHT_CONTROL 152 
#define  GLFW_KEY_RIGHT_SHIFT 151 
#define  GLFW_KEY_RIGHT_SUPER 150 
#define  GLFW_KEY_S 149 
#define  GLFW_KEY_SCROLL_LOCK 148 
#define  GLFW_KEY_SEMICOLON 147 
#define  GLFW_KEY_SLASH 146 
#define  GLFW_KEY_SPACE 145 
#define  GLFW_KEY_T 144 
#define  GLFW_KEY_TAB 143 
#define  GLFW_KEY_U 142 
#define  GLFW_KEY_UP 141 
#define  GLFW_KEY_V 140 
#define  GLFW_KEY_W 139 
#define  GLFW_KEY_WORLD_1 138 
#define  GLFW_KEY_WORLD_2 137 
#define  GLFW_KEY_X 136 
#define  GLFW_KEY_Y 135 
#define  GLFW_KEY_Z 134 
 int GLFW_MOD_ALT ; 
 int GLFW_MOD_CONTROL ; 
 int GLFW_MOD_SHIFT ; 
 int GLFW_MOD_SUPER ; 
#define  GLFW_MOUSE_BUTTON_LEFT 133 
#define  GLFW_MOUSE_BUTTON_MIDDLE 132 
#define  GLFW_MOUSE_BUTTON_RIGHT 131 
#define  GLFW_PRESS 130 
 int /*<<< orphan*/  GLFW_RED_BITS ; 
 int /*<<< orphan*/  GLFW_REFRESH_RATE ; 
#define  GLFW_RELEASE 129 
#define  GLFW_REPEAT 128 
 int /*<<< orphan*/  GL_COLOR_BUFFER_BIT ; 
 int GL_TRUE ; 
 int /*<<< orphan*/  LC_ALL ; 
 TYPE_1__* calloc (int,int) ; 
 int /*<<< orphan*/  counter ; 
 int /*<<< orphan*/  exit (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  fflush (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  fprintf (int /*<<< orphan*/ ,char*,...) ; 
 int /*<<< orphan*/  free (TYPE_1__*) ; 
 int getopt (int,char**,char*) ; 
 int /*<<< orphan*/  glClear (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  glViewport (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int,int) ; 
 int /*<<< orphan*/ * glfwCreateWindow (int,int,char*,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 char* glfwGetMonitorName (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  glfwGetMonitorPhysicalSize (int /*<<< orphan*/ *,int*,int*) ; 
 int /*<<< orphan*/  glfwGetMonitorPos (int /*<<< orphan*/ *,int*,int*) ; 
 int /*<<< orphan*/ * glfwGetPrimaryMonitor () ; 
 double glfwGetTime () ; 
 TYPE_2__* glfwGetVideoMode (int /*<<< orphan*/ *) ; 
 TYPE_1__* glfwGetWindowUserPointer (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  glfwInit () ; 
 int /*<<< orphan*/  glfwMakeContextCurrent (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  glfwSetCharCallback (int /*<<< orphan*/ *,void (*) (int /*<<< orphan*/ *,unsigned int)) ; 
 int /*<<< orphan*/  glfwSetCharModsCallback (int /*<<< orphan*/ *,void (*) (int /*<<< orphan*/ *,unsigned int,int)) ; 
 int /*<<< orphan*/  glfwSetCursorEnterCallback (int /*<<< orphan*/ *,void (*) (int /*<<< orphan*/ *,int)) ; 
 int /*<<< orphan*/  glfwSetCursorPosCallback (int /*<<< orphan*/ *,void (*) (int /*<<< orphan*/ *,double,double)) ; 
 int /*<<< orphan*/  glfwSetDropCallback (int /*<<< orphan*/ *,void (*) (int /*<<< orphan*/ *,int,char const**)) ; 
 int /*<<< orphan*/  glfwSetErrorCallback (void (*) (int,char const*)) ; 
 int /*<<< orphan*/  glfwSetFramebufferSizeCallback (int /*<<< orphan*/ *,void (*) (int /*<<< orphan*/ *,int,int)) ; 
 int /*<<< orphan*/  glfwSetKeyCallback (int /*<<< orphan*/ *,void (*) (int /*<<< orphan*/ *,int,int,int,int)) ; 
 int /*<<< orphan*/  glfwSetMonitorCallback (void (*) (int /*<<< orphan*/ *,int)) ; 
 int /*<<< orphan*/  glfwSetMouseButtonCallback (int /*<<< orphan*/ *,void (*) (int /*<<< orphan*/ *,int,int,int)) ; 
 int /*<<< orphan*/  glfwSetScrollCallback (int /*<<< orphan*/ *,void (*) (int /*<<< orphan*/ *,double,double)) ; 
 int /*<<< orphan*/  glfwSetWindowCloseCallback (int /*<<< orphan*/ *,void (*) (int /*<<< orphan*/ *)) ; 
 int /*<<< orphan*/  glfwSetWindowFocusCallback (int /*<<< orphan*/ *,void (*) (int /*<<< orphan*/ *,int)) ; 
 int /*<<< orphan*/  glfwSetWindowIconifyCallback (int /*<<< orphan*/ *,void (*) (int /*<<< orphan*/ *,int)) ; 
 int /*<<< orphan*/  glfwSetWindowPosCallback (int /*<<< orphan*/ *,void (*) (int /*<<< orphan*/ *,int,int)) ; 
 int /*<<< orphan*/  glfwSetWindowRefreshCallback (int /*<<< orphan*/ *,void (*) (int /*<<< orphan*/ *)) ; 
 int /*<<< orphan*/  glfwSetWindowShouldClose (int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  glfwSetWindowSizeCallback (int /*<<< orphan*/ *,void (*) (int /*<<< orphan*/ *,int,int)) ; 
 int /*<<< orphan*/  glfwSetWindowUserPointer (int /*<<< orphan*/ *,TYPE_1__*) ; 
 int /*<<< orphan*/  glfwSwapBuffers (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  glfwSwapInterval (int) ; 
 int /*<<< orphan*/  glfwTerminate () ; 
 int /*<<< orphan*/  glfwWaitEvents () ; 
 int /*<<< orphan*/  glfwWindowHint (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 scalar_t__ glfwWindowShouldClose (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  optarg ; 
 int /*<<< orphan*/  printf (char*,...) ; 
 int /*<<< orphan*/  setlocale (int /*<<< orphan*/ ,char*) ; 
 int /*<<< orphan*/  sprintf (char*,char*,int) ; 
 int /*<<< orphan*/  stderr ; 
 int /*<<< orphan*/  stdout ; 
 int /*<<< orphan*/  strcat (char*,char*) ; 
 scalar_t__ strtol (int /*<<< orphan*/ ,int /*<<< orphan*/ *,int) ; 
 int wctomb (char*,int) ; 

__attribute__((used)) static void usage(void)
{
    printf("Usage: events [-f] [-h] [-n WINDOWS]\n");
    printf("Options:\n");
    printf("  -f use full screen\n");
    printf("  -h show this help\n");
    printf("  -n the number of windows to create\n");
}

__attribute__((used)) static const char* get_key_name(int key)
{
    switch (key)
    {
        // Printable keys
        case GLFW_KEY_A:            return "A";
        case GLFW_KEY_B:            return "B";
        case GLFW_KEY_C:            return "C";
        case GLFW_KEY_D:            return "D";
        case GLFW_KEY_E:            return "E";
        case GLFW_KEY_F:            return "F";
        case GLFW_KEY_G:            return "G";
        case GLFW_KEY_H:            return "H";
        case GLFW_KEY_I:            return "I";
        case GLFW_KEY_J:            return "J";
        case GLFW_KEY_K:            return "K";
        case GLFW_KEY_L:            return "L";
        case GLFW_KEY_M:            return "M";
        case GLFW_KEY_N:            return "N";
        case GLFW_KEY_O:            return "O";
        case GLFW_KEY_P:            return "P";
        case GLFW_KEY_Q:            return "Q";
        case GLFW_KEY_R:            return "R";
        case GLFW_KEY_S:            return "S";
        case GLFW_KEY_T:            return "T";
        case GLFW_KEY_U:            return "U";
        case GLFW_KEY_V:            return "V";
        case GLFW_KEY_W:            return "W";
        case GLFW_KEY_X:            return "X";
        case GLFW_KEY_Y:            return "Y";
        case GLFW_KEY_Z:            return "Z";
        case GLFW_KEY_1:            return "1";
        case GLFW_KEY_2:            return "2";
        case GLFW_KEY_3:            return "3";
        case GLFW_KEY_4:            return "4";
        case GLFW_KEY_5:            return "5";
        case GLFW_KEY_6:            return "6";
        case GLFW_KEY_7:            return "7";
        case GLFW_KEY_8:            return "8";
        case GLFW_KEY_9:            return "9";
        case GLFW_KEY_0:            return "0";
        case GLFW_KEY_SPACE:        return "SPACE";
        case GLFW_KEY_MINUS:        return "MINUS";
        case GLFW_KEY_EQUAL:        return "EQUAL";
        case GLFW_KEY_LEFT_BRACKET: return "LEFT BRACKET";
        case GLFW_KEY_RIGHT_BRACKET: return "RIGHT BRACKET";
        case GLFW_KEY_BACKSLASH:    return "BACKSLASH";
        case GLFW_KEY_SEMICOLON:    return "SEMICOLON";
        case GLFW_KEY_APOSTROPHE:   return "APOSTROPHE";
        case GLFW_KEY_GRAVE_ACCENT: return "GRAVE ACCENT";
        case GLFW_KEY_COMMA:        return "COMMA";
        case GLFW_KEY_PERIOD:       return "PERIOD";
        case GLFW_KEY_SLASH:        return "SLASH";
        case GLFW_KEY_WORLD_1:      return "WORLD 1";
        case GLFW_KEY_WORLD_2:      return "WORLD 2";

        // Function keys
        case GLFW_KEY_ESCAPE:       return "ESCAPE";
        case GLFW_KEY_F1:           return "F1";
        case GLFW_KEY_F2:           return "F2";
        case GLFW_KEY_F3:           return "F3";
        case GLFW_KEY_F4:           return "F4";
        case GLFW_KEY_F5:           return "F5";
        case GLFW_KEY_F6:           return "F6";
        case GLFW_KEY_F7:           return "F7";
        case GLFW_KEY_F8:           return "F8";
        case GLFW_KEY_F9:           return "F9";
        case GLFW_KEY_F10:          return "F10";
        case GLFW_KEY_F11:          return "F11";
        case GLFW_KEY_F12:          return "F12";
        case GLFW_KEY_F13:          return "F13";
        case GLFW_KEY_F14:          return "F14";
        case GLFW_KEY_F15:          return "F15";
        case GLFW_KEY_F16:          return "F16";
        case GLFW_KEY_F17:          return "F17";
        case GLFW_KEY_F18:          return "F18";
        case GLFW_KEY_F19:          return "F19";
        case GLFW_KEY_F20:          return "F20";
        case GLFW_KEY_F21:          return "F21";
        case GLFW_KEY_F22:          return "F22";
        case GLFW_KEY_F23:          return "F23";
        case GLFW_KEY_F24:          return "F24";
        case GLFW_KEY_F25:          return "F25";
        case GLFW_KEY_UP:           return "UP";
        case GLFW_KEY_DOWN:         return "DOWN";
        case GLFW_KEY_LEFT:         return "LEFT";
        case GLFW_KEY_RIGHT:        return "RIGHT";
        case GLFW_KEY_LEFT_SHIFT:   return "LEFT SHIFT";
        case GLFW_KEY_RIGHT_SHIFT:  return "RIGHT SHIFT";
        case GLFW_KEY_LEFT_CONTROL: return "LEFT CONTROL";
        case GLFW_KEY_RIGHT_CONTROL: return "RIGHT CONTROL";
        case GLFW_KEY_LEFT_ALT:     return "LEFT ALT";
        case GLFW_KEY_RIGHT_ALT:    return "RIGHT ALT";
        case GLFW_KEY_TAB:          return "TAB";
        case GLFW_KEY_ENTER:        return "ENTER";
        case GLFW_KEY_BACKSPACE:    return "BACKSPACE";
        case GLFW_KEY_INSERT:       return "INSERT";
        case GLFW_KEY_DELETE:       return "DELETE";
        case GLFW_KEY_PAGE_UP:      return "PAGE UP";
        case GLFW_KEY_PAGE_DOWN:    return "PAGE DOWN";
        case GLFW_KEY_HOME:         return "HOME";
        case GLFW_KEY_END:          return "END";
        case GLFW_KEY_KP_0:         return "KEYPAD 0";
        case GLFW_KEY_KP_1:         return "KEYPAD 1";
        case GLFW_KEY_KP_2:         return "KEYPAD 2";
        case GLFW_KEY_KP_3:         return "KEYPAD 3";
        case GLFW_KEY_KP_4:         return "KEYPAD 4";
        case GLFW_KEY_KP_5:         return "KEYPAD 5";
        case GLFW_KEY_KP_6:         return "KEYPAD 6";
        case GLFW_KEY_KP_7:         return "KEYPAD 7";
        case GLFW_KEY_KP_8:         return "KEYPAD 8";
        case GLFW_KEY_KP_9:         return "KEYPAD 9";
        case GLFW_KEY_KP_DIVIDE:    return "KEYPAD DIVIDE";
        case GLFW_KEY_KP_MULTIPLY:  return "KEYPAD MULTPLY";
        case GLFW_KEY_KP_SUBTRACT:  return "KEYPAD SUBTRACT";
        case GLFW_KEY_KP_ADD:       return "KEYPAD ADD";
        case GLFW_KEY_KP_DECIMAL:   return "KEYPAD DECIMAL";
        case GLFW_KEY_KP_EQUAL:     return "KEYPAD EQUAL";
        case GLFW_KEY_KP_ENTER:     return "KEYPAD ENTER";
        case GLFW_KEY_PRINT_SCREEN: return "PRINT SCREEN";
        case GLFW_KEY_NUM_LOCK:     return "NUM LOCK";
        case GLFW_KEY_CAPS_LOCK:    return "CAPS LOCK";
        case GLFW_KEY_SCROLL_LOCK:  return "SCROLL LOCK";
        case GLFW_KEY_PAUSE:        return "PAUSE";
        case GLFW_KEY_LEFT_SUPER:   return "LEFT SUPER";
        case GLFW_KEY_RIGHT_SUPER:  return "RIGHT SUPER";
        case GLFW_KEY_MENU:         return "MENU";

        default:                    return "UNKNOWN";
    }
}

__attribute__((used)) static const char* get_action_name(int action)
{
    switch (action)
    {
        case GLFW_PRESS:
            return "pressed";
        case GLFW_RELEASE:
            return "released";
        case GLFW_REPEAT:
            return "repeated";
    }

    return "caused unknown action";
}

__attribute__((used)) static const char* get_button_name(int button)
{
    switch (button)
    {
        case GLFW_MOUSE_BUTTON_LEFT:
            return "left";
        case GLFW_MOUSE_BUTTON_RIGHT:
            return "right";
        case GLFW_MOUSE_BUTTON_MIDDLE:
            return "middle";
        default:
        {
            static char name[16];
            sprintf(name, "%i", button);
            return name;
        }
    }
}

__attribute__((used)) static const char* get_mods_name(int mods)
{
    static char name[512];

    if (mods == 0)
        return " no mods";

    name[0] = '\0';

    if (mods & GLFW_MOD_SHIFT)
        strcat(name, " shift");
    if (mods & GLFW_MOD_CONTROL)
        strcat(name, " control");
    if (mods & GLFW_MOD_ALT)
        strcat(name, " alt");
    if (mods & GLFW_MOD_SUPER)
        strcat(name, " super");

    return name;
}

__attribute__((used)) static const char* get_character_string(int codepoint)
{
    // This assumes UTF-8, which is stupid
    static char result[6 + 1];

    int length = wctomb(result, codepoint);
    if (length == -1)
        length = 0;

    result[length] = '\0';
    return result;
}

__attribute__((used)) static void error_callback(int error, const char* description)
{
    fprintf(stderr, "Error: %s\n", description);
}

__attribute__((used)) static void window_pos_callback(GLFWwindow* window, int x, int y)
{
    Slot* slot = glfwGetWindowUserPointer(window);
    printf("%08x to %i at %0.3f: Window position: %i %i\n",
           counter++, slot->number, glfwGetTime(), x, y);
}

__attribute__((used)) static void window_size_callback(GLFWwindow* window, int width, int height)
{
    Slot* slot = glfwGetWindowUserPointer(window);
    printf("%08x to %i at %0.3f: Window size: %i %i\n",
           counter++, slot->number, glfwGetTime(), width, height);
}

__attribute__((used)) static void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    Slot* slot = glfwGetWindowUserPointer(window);
    printf("%08x to %i at %0.3f: Framebuffer size: %i %i\n",
           counter++, slot->number, glfwGetTime(), width, height);

    glViewport(0, 0, width, height);
}

__attribute__((used)) static void window_close_callback(GLFWwindow* window)
{
    Slot* slot = glfwGetWindowUserPointer(window);
    printf("%08x to %i at %0.3f: Window close\n",
           counter++, slot->number, glfwGetTime());

    glfwSetWindowShouldClose(window, slot->closeable);
}

__attribute__((used)) static void window_refresh_callback(GLFWwindow* window)
{
    Slot* slot = glfwGetWindowUserPointer(window);
    printf("%08x to %i at %0.3f: Window refresh\n",
           counter++, slot->number, glfwGetTime());

    glfwMakeContextCurrent(window);
    glClear(GL_COLOR_BUFFER_BIT);
    glfwSwapBuffers(window);
}

__attribute__((used)) static void window_focus_callback(GLFWwindow* window, int focused)
{
    Slot* slot = glfwGetWindowUserPointer(window);
    printf("%08x to %i at %0.3f: Window %s\n",
           counter++, slot->number, glfwGetTime(),
           focused ? "focused" : "defocused");
}

__attribute__((used)) static void window_iconify_callback(GLFWwindow* window, int iconified)
{
    Slot* slot = glfwGetWindowUserPointer(window);
    printf("%08x to %i at %0.3f: Window was %s\n",
           counter++, slot->number, glfwGetTime(),
           iconified ? "iconified" : "restored");
}

__attribute__((used)) static void mouse_button_callback(GLFWwindow* window, int button, int action, int mods)
{
    Slot* slot = glfwGetWindowUserPointer(window);
    printf("%08x to %i at %0.3f: Mouse button %i (%s) (with%s) was %s\n",
           counter++, slot->number, glfwGetTime(), button,
           get_button_name(button),
           get_mods_name(mods),
           get_action_name(action));
}

__attribute__((used)) static void cursor_position_callback(GLFWwindow* window, double x, double y)
{
    Slot* slot = glfwGetWindowUserPointer(window);
    printf("%08x to %i at %0.3f: Cursor position: %f %f\n",
           counter++, slot->number, glfwGetTime(), x, y);
}

__attribute__((used)) static void cursor_enter_callback(GLFWwindow* window, int entered)
{
    Slot* slot = glfwGetWindowUserPointer(window);
    printf("%08x to %i at %0.3f: Cursor %s window\n",
           counter++, slot->number, glfwGetTime(),
           entered ? "entered" : "left");
}

__attribute__((used)) static void scroll_callback(GLFWwindow* window, double x, double y)
{
    Slot* slot = glfwGetWindowUserPointer(window);
    printf("%08x to %i at %0.3f: Scroll: %0.3f %0.3f\n",
           counter++, slot->number, glfwGetTime(), x, y);
}

__attribute__((used)) static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    Slot* slot = glfwGetWindowUserPointer(window);

    printf("%08x to %i at %0.3f: Key 0x%04x Scancode 0x%04x (%s) (with%s) was %s\n",
           counter++, slot->number, glfwGetTime(), key, scancode,
           get_key_name(key),
           get_mods_name(mods),
           get_action_name(action));

    if (action != GLFW_PRESS)
        return;

    switch (key)
    {
        case GLFW_KEY_C:
        {
            slot->closeable = !slot->closeable;

            printf("(( closing %s ))\n", slot->closeable ? "enabled" : "disabled");
            break;
        }
    }
}

__attribute__((used)) static void char_callback(GLFWwindow* window, unsigned int codepoint)
{
    Slot* slot = glfwGetWindowUserPointer(window);
    printf("%08x to %i at %0.3f: Character 0x%08x (%s) input\n",
           counter++, slot->number, glfwGetTime(), codepoint,
           get_character_string(codepoint));
}

__attribute__((used)) static void char_mods_callback(GLFWwindow* window, unsigned int codepoint, int mods)
{
    Slot* slot = glfwGetWindowUserPointer(window);
    printf("%08x to %i at %0.3f: Character 0x%08x (%s) with modifiers (with%s) input\n",
            counter++, slot->number, glfwGetTime(), codepoint,
            get_character_string(codepoint),
            get_mods_name(mods));
}

__attribute__((used)) static void drop_callback(GLFWwindow* window, int count, const char** paths)
{
    int i;
    Slot* slot = glfwGetWindowUserPointer(window);

    printf("%08x to %i at %0.3f: Drop input\n",
           counter++, slot->number, glfwGetTime());

    for (i = 0;  i < count;  i++)
        printf("  %i: \"%s\"\n", i, paths[i]);
}

__attribute__((used)) static void monitor_callback(GLFWmonitor* monitor, int event)
{
    if (event == GLFW_CONNECTED)
    {
        int x, y, widthMM, heightMM;
        const GLFWvidmode* mode = glfwGetVideoMode(monitor);

        glfwGetMonitorPos(monitor, &x, &y);
        glfwGetMonitorPhysicalSize(monitor, &widthMM, &heightMM);

        printf("%08x at %0.3f: Monitor %s (%ix%i at %ix%i, %ix%i mm) was connected\n",
               counter++,
               glfwGetTime(),
               glfwGetMonitorName(monitor),
               mode->width, mode->height,
               x, y,
               widthMM, heightMM);
    }
    else
    {
        printf("%08x at %0.3f: Monitor %s was disconnected\n",
               counter++,
               glfwGetTime(),
               glfwGetMonitorName(monitor));
    }
}

int main(int argc, char** argv)
{
    Slot* slots;
    GLFWmonitor* monitor = NULL;
    int ch, i, width, height, count = 1;

    setlocale(LC_ALL, "");

    glfwSetErrorCallback(error_callback);

    if (!glfwInit())
        exit(EXIT_FAILURE);

    printf("Library initialized\n");

    glfwSetMonitorCallback(monitor_callback);

    while ((ch = getopt(argc, argv, "hfn:")) != -1)
    {
        switch (ch)
        {
            case 'h':
                usage();
                exit(EXIT_SUCCESS);

            case 'f':
                monitor = glfwGetPrimaryMonitor();
                break;

            case 'n':
                count = (int) strtol(optarg, NULL, 10);
                break;

            default:
                usage();
                exit(EXIT_FAILURE);
        }
    }

    if (monitor)
    {
        const GLFWvidmode* mode = glfwGetVideoMode(monitor);

        glfwWindowHint(GLFW_REFRESH_RATE, mode->refreshRate);
        glfwWindowHint(GLFW_RED_BITS, mode->redBits);
        glfwWindowHint(GLFW_GREEN_BITS, mode->greenBits);
        glfwWindowHint(GLFW_BLUE_BITS, mode->blueBits);

        width = mode->width;
        height = mode->height;
    }
    else
    {
        width  = 640;
        height = 480;
    }

    if (!count)
    {
        fprintf(stderr, "Invalid user\n");
        exit(EXIT_FAILURE);
    }

    slots = calloc(count, sizeof(Slot));

    for (i = 0;  i < count;  i++)
    {
        char title[128];

        slots[i].closeable = GL_TRUE;
        slots[i].number = i + 1;

        sprintf(title, "Event Linter (Window %i)", slots[i].number);

        if (monitor)
        {
            printf("Creating full screen window %i (%ix%i on %s)\n",
                   slots[i].number,
                   width, height,
                   glfwGetMonitorName(monitor));
        }
        else
        {
            printf("Creating windowed mode window %i (%ix%i)\n",
                   slots[i].number,
                   width, height);
        }

        slots[i].window = glfwCreateWindow(width, height, title, monitor, NULL);
        if (!slots[i].window)
        {
            free(slots);
            glfwTerminate();
            exit(EXIT_FAILURE);
        }

        glfwSetWindowUserPointer(slots[i].window, slots + i);

        glfwSetWindowPosCallback(slots[i].window, window_pos_callback);
        glfwSetWindowSizeCallback(slots[i].window, window_size_callback);
        glfwSetFramebufferSizeCallback(slots[i].window, framebuffer_size_callback);
        glfwSetWindowCloseCallback(slots[i].window, window_close_callback);
        glfwSetWindowRefreshCallback(slots[i].window, window_refresh_callback);
        glfwSetWindowFocusCallback(slots[i].window, window_focus_callback);
        glfwSetWindowIconifyCallback(slots[i].window, window_iconify_callback);
        glfwSetMouseButtonCallback(slots[i].window, mouse_button_callback);
        glfwSetCursorPosCallback(slots[i].window, cursor_position_callback);
        glfwSetCursorEnterCallback(slots[i].window, cursor_enter_callback);
        glfwSetScrollCallback(slots[i].window, scroll_callback);
        glfwSetKeyCallback(slots[i].window, key_callback);
        glfwSetCharCallback(slots[i].window, char_callback);
        glfwSetCharModsCallback(slots[i].window, char_mods_callback);
        glfwSetDropCallback(slots[i].window, drop_callback);

        glfwMakeContextCurrent(slots[i].window);
        glfwSwapInterval(1);
    }

    printf("Main loop starting\n");

    for (;;)
    {
        for (i = 0;  i < count;  i++)
        {
            if (glfwWindowShouldClose(slots[i].window))
                break;
        }

        if (i < count)
            break;

        glfwWaitEvents();

        // Workaround for an issue with msvcrt and mintty
        fflush(stdout);
    }

    free(slots);
    glfwTerminate();
    exit(EXIT_SUCCESS);
}

