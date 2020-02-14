#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_10__   TYPE_4__ ;
typedef  struct TYPE_9__   TYPE_3__ ;
typedef  struct TYPE_8__   TYPE_2__ ;
typedef  struct TYPE_7__   TYPE_1__ ;

/* Type definitions */
struct TYPE_9__ {char* text; } ;
struct TYPE_7__ {int sym; int scancode; } ;
struct TYPE_8__ {TYPE_1__ keysym; } ;
struct TYPE_10__ {int type; TYPE_3__ text; TYPE_2__ key; } ;
typedef  int /*<<< orphan*/  SDL_Window ;
typedef  TYPE_4__ SDL_Event ;

/* Variables and functions */
 int /*<<< orphan*/  REPORT_RESULT (int) ; 
#define  SDLK_DOWN 135 
#define  SDLK_LEFT 134 
#define  SDLK_RIGHT 133 
#define  SDLK_UP 132 
#define  SDLK_a 131 
 int /*<<< orphan*/ * SDL_CreateWindow (char*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  SDL_INIT_VIDEO ; 
 int /*<<< orphan*/  SDL_Init (int /*<<< orphan*/ ) ; 
#define  SDL_KEYDOWN 130 
#define  SDL_KEYUP 129 
 scalar_t__ SDL_PollEvent (TYPE_4__*) ; 
 int SDL_SCANCODE_B ; 
 int /*<<< orphan*/  SDL_StartTextInput () ; 
#define  SDL_TEXTINPUT 128 
 int /*<<< orphan*/  SDL_WINDOWPOS_CENTERED ; 
 int /*<<< orphan*/  emscripten_run_script (char*) ; 
 int /*<<< orphan*/  printf (char*,...) ; 
 int result ; 

int EventHandler(void *userdata, SDL_Event *event) {
  int mod;
  
  switch(event->type) {
    case SDL_KEYUP:
      break;
    case SDL_KEYDOWN:
      switch (event->key.keysym.sym) {
        case SDLK_RIGHT: printf("right\n"); result *= 7; break;
        case SDLK_LEFT: printf("left\n"); result *= 11; break;
        case SDLK_DOWN: printf("down\n"); result *= 13; break;
        case SDLK_UP: printf("up\n"); result *= 17; break;
        case SDLK_a: printf("a\n"); result *= 19; break;
        default: {
          if (event->key.keysym.scancode == SDL_SCANCODE_B) {
            printf("b scancode\n"); result *= 23; break;
          }
          printf("unknown key: sym %d scancode %d\n", event->key.keysym.sym, event->key.keysym.scancode);
          REPORT_RESULT(result);
          emscripten_run_script("throw 'done'"); // comment this out to leave event handling active. Use the following to log DOM keys:
                                                 // addEventListener('keyup', function(event) { console.log(event->keyCode) }, true)
        }
      }
      break;
    case SDL_TEXTINPUT:
      if (event->text.text[0] == 'A') {
        printf("a\n");result *= 5;
      }
      break;
    default: /* Report an unhandled event */
      printf("I don't know what this event is (type=%d)!\n", event->type);
  }
  return 0;
}

void one() {
#ifndef TEST_EMSCRIPTEN_SDL_SETEVENTHANDLER
  SDL_Event event;
  while (SDL_PollEvent(&event)) {
    EventHandler(0, &event);
  }
#endif
}

int main(int argc, char **argv) {
  SDL_Init(SDL_INIT_VIDEO);
  SDL_Window *window;
  window = SDL_CreateWindow("sdl2_key",
                            SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                            640, 480, 0);

#ifdef TEST_EMSCRIPTEN_SDL_SETEVENTHANDLER
  emscripten_SDL_SetEventHandler(EventHandler, 0);
#else
  one();
#endif

  SDL_StartTextInput();

  emscripten_run_script("keydown(38);keyup(38)"); // up
  emscripten_run_script("keydown(40);keyup(40);"); // down
  emscripten_run_script("keydown(37);keyup(37);"); // left
  emscripten_run_script("keydown(39);keyup(39);"); // right
  emscripten_run_script("keydown(65);keyup(65);"); // a
  emscripten_run_script("keydown(66);keyup(66);"); // b
  emscripten_run_script("keydown(100);keyup(100);"); // trigger the end

  return 0;
}

