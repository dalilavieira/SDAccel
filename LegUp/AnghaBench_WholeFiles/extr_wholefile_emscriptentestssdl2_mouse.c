#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_11__   TYPE_4__ ;
typedef  struct TYPE_10__   TYPE_3__ ;
typedef  struct TYPE_9__   TYPE_2__ ;
typedef  struct TYPE_8__   TYPE_1__ ;

/* Type definitions */
struct TYPE_11__ {int type; } ;
struct TYPE_10__ {int button; int state; int x; int y; } ;
struct TYPE_9__ {int x; int y; int xrel; int yrel; int /*<<< orphan*/  state; } ;
struct TYPE_8__ {int member_2; int member_3; int /*<<< orphan*/  member_1; int /*<<< orphan*/  member_0; } ;
typedef  int /*<<< orphan*/  SDL_Window ;
typedef  int /*<<< orphan*/  SDL_Renderer ;
typedef  TYPE_1__ SDL_Rect ;
typedef  TYPE_2__ SDL_MouseMotionEvent ;
typedef  TYPE_3__ SDL_MouseButtonEvent ;
typedef  TYPE_4__ SDL_Event ;

/* Variables and functions */
 int /*<<< orphan*/  REPORT_RESULT (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  SDL_CreateWindowAndRenderer (int,int,int /*<<< orphan*/ ,int /*<<< orphan*/ **,int /*<<< orphan*/ **) ; 
 int /*<<< orphan*/  SDL_GETEVENT ; 
 int /*<<< orphan*/  SDL_INIT_VIDEO ; 
 int /*<<< orphan*/  SDL_Init (int /*<<< orphan*/ ) ; 
#define  SDL_MOUSEBUTTONDOWN 130 
#define  SDL_MOUSEBUTTONUP 129 
#define  SDL_MOUSEMOTION 128 
 int SDL_PeepEvents (TYPE_4__*,int,int /*<<< orphan*/ ,int const,int const) ; 
 scalar_t__ SDL_PollEvent (TYPE_4__*) ; 
 int /*<<< orphan*/  SDL_RenderFillRect (int /*<<< orphan*/ *,TYPE_1__*) ; 
 int /*<<< orphan*/  SDL_SetRenderDrawColor (int /*<<< orphan*/ *,int,int,int,int) ; 
 int /*<<< orphan*/  assert (int) ; 
 int /*<<< orphan*/  emscripten_async_call (void (*) (void*),int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  emscripten_run_script (char*) ; 
 int /*<<< orphan*/  emscripten_set_main_loop (void (*) (),int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  eq (int,int) ; 
 void main_2 (void*) ; 
 int mouse_motions ; 
 int /*<<< orphan*/  printf (char*,int,int,int,int) ; 
 int /*<<< orphan*/  result ; 

void one() {
  SDL_Event event;
  while (SDL_PollEvent(&event)) {
    switch(event.type) {
      case SDL_MOUSEMOTION: {
        SDL_MouseMotionEvent *m = (SDL_MouseMotionEvent*)&event;
        assert(m->state == 0);
        printf("motion : %d,%d  %d,%d\n", m->x, m->y, m->xrel, m->yrel);

        if (mouse_motions == 0) {
          // xrel/yrel will be zero for the first motion
#ifdef TEST_SDL_MOUSE_OFFSETS
          assert(eq(m->x, 5) && eq(m->y, 15) && eq(m->xrel, 0) && eq(m->yrel, 0));
#else
          assert(eq(m->x, 10) && eq(m->y, 20) && eq(m->xrel, 0) && eq(m->yrel, 0));
#endif
        } else if (mouse_motions == 1) {
#ifdef TEST_SDL_MOUSE_OFFSETS
          assert(eq(m->x, 25) && eq(m->y, 65) && eq(m->xrel, 20) && eq(m->yrel, 50));
#else
          assert(eq(m->x, 30) && eq(m->y, 70) && eq(m->xrel, 20) && eq(m->yrel, 50));
#endif
        }

        mouse_motions++;
        break;
      }
      case SDL_MOUSEBUTTONDOWN: {
        SDL_MouseButtonEvent *m = (SDL_MouseButtonEvent*)&event;
        if (m->button == 2) {
          REPORT_RESULT(result);
          emscripten_run_script("throw 'done'");
        }
        printf("button down : %d,%d  %d,%d\n", m->button, m->state, m->x, m->y);
#ifdef TEST_SDL_MOUSE_OFFSETS
        assert(eq(m->button, 1) && eq(m->state, 1) && eq(m->x, 5) && eq(m->y, 15));
#else
        assert(eq(m->button, 1) && eq(m->state, 1) && eq(m->x, 10) && eq(m->y, 20));
#endif
        break;
      }
      case SDL_MOUSEBUTTONUP: {
        SDL_MouseButtonEvent *m = (SDL_MouseButtonEvent*)&event;
        printf("button up : %d,%d  %d,%d\n", m->button, m->state, m->x, m->y);
#ifdef TEST_SDL_MOUSE_OFFSETS
        assert(eq(m->button, 1) && eq(m->state, 0) && eq(m->x, 5) && eq(m->y, 15));
#else
        assert(eq(m->button, 1) && eq(m->state, 0) && eq(m->x, 10) && eq(m->y, 20));
#endif
        // Remove another click we want to ignore
        assert(SDL_PeepEvents(&event, 1, SDL_GETEVENT, SDL_MOUSEBUTTONDOWN, SDL_MOUSEBUTTONDOWN) == 1);
        assert(SDL_PeepEvents(&event, 1, SDL_GETEVENT, SDL_MOUSEBUTTONUP, SDL_MOUSEBUTTONUP) == 1);
        break;
      }
    }
  }
}

int main() {
  SDL_Init(SDL_INIT_VIDEO);
  SDL_Window *window;
  SDL_Renderer *renderer;

  SDL_CreateWindowAndRenderer(600, 450, 0, &window, &renderer);

  SDL_SetRenderDrawColor(renderer, 0xFF, 0x00, 0x00, 0xFF );
  SDL_Rect rect = { 0, 0, 600, 450 };
  SDL_RenderFillRect(renderer, &rect);

  emscripten_async_call(main_2, NULL, 3000); // avoid startup delays and intermittent errors

  return 0;
}

void main_2(void* arg) {
  emscripten_run_script("window.simulateMouseEvent(10, 20, -1)"); // move from 0,0 to 10,20
  emscripten_run_script("window.simulateMouseEvent(10, 20, 0)"); // click
  emscripten_run_script("window.simulateMouseEvent(10, 20, 0)"); // click some more, but this one should be ignored through PeepEvent
  emscripten_run_script("window.simulateMouseEvent(30, 70, -1)"); // move some more
  emscripten_run_script("window.simulateMouseEvent(30, 70, 1)"); // trigger the end

  emscripten_set_main_loop(one, 0, 0);
}

