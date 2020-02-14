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
struct TYPE_5__ {int type; } ;
struct TYPE_4__ {int w; int h; } ;
typedef  int /*<<< orphan*/  SDL_Surface ;
typedef  TYPE_1__ SDL_ResizeEvent ;
typedef  TYPE_2__ SDL_Event ;

/* Variables and functions */
 int /*<<< orphan*/  REPORT_RESULT (int) ; 
 int /*<<< orphan*/  SDL_HWSURFACE ; 
 int /*<<< orphan*/  SDL_INIT_VIDEO ; 
 int /*<<< orphan*/  SDL_Init (int /*<<< orphan*/ ) ; 
 scalar_t__ SDL_PollEvent (TYPE_2__*) ; 
 int /*<<< orphan*/ * SDL_SetVideoMode (int,int,int,int /*<<< orphan*/ ) ; 
#define  SDL_VIDEORESIZE 128 
 int /*<<< orphan*/  assert (int) ; 
 int /*<<< orphan*/  emscripten_set_canvas_size (int,int) ; 
 int /*<<< orphan*/  emscripten_set_main_loop (void (*) (),int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  printf (char*,int,int) ; 
 int /*<<< orphan*/  stage ; 

void loop() {
  SDL_Event event;
  while (SDL_PollEvent(&event)) {
    switch(event.type) {
      case SDL_VIDEORESIZE: {
        SDL_ResizeEvent *r = (SDL_ResizeEvent*)&event;
        printf("resize event! %d:%d\n", r->w, r->h);
        switch (stage) {
          case 0:
            assert(r->w == 100);
            assert(r->h == 200);
            emscripten_set_canvas_size(123, 246);
            stage++;
            break;
          case 1:
            assert(r->w == 123);
            assert(r->h == 246);
            REPORT_RESULT(1);
            break;
        }
      }
    }
  }
}

int main() {
  SDL_Init(SDL_INIT_VIDEO);
  SDL_Surface *screen = SDL_SetVideoMode(600, 450, 32, SDL_HWSURFACE);

  emscripten_set_canvas_size(100, 200);

  emscripten_set_main_loop(loop, 0, 0);
}

