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
typedef  scalar_t__ Uint8 ;
typedef  int /*<<< orphan*/  SDL_Event ;

/* Variables and functions */
 int /*<<< orphan*/  REPORT_RESULT (int /*<<< orphan*/ ) ; 
 size_t SDLK_LEFT ; 
 size_t SDLK_RIGHT ; 
 size_t SDLK_a ; 
 scalar_t__* SDL_GetKeyState (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  SDL_INIT_EVERYTHING ; 
 int /*<<< orphan*/  SDL_Init (int /*<<< orphan*/ ) ; 
 scalar_t__ SDL_PollEvent (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  SDL_PumpEvents () ; 
 int /*<<< orphan*/  SDL_SWSURFACE ; 
 int /*<<< orphan*/  SDL_SetVideoMode (int,int,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  emscripten_run_script (char*) ; 
 int /*<<< orphan*/  result ; 

int loop1()
{
   unsigned i;
   int r = 0;

   // method 1: SDL_PollEvent loop
   SDL_Event e;
   while (SDL_PollEvent(&e));

   const Uint8 *keys = SDL_GetKeyState(NULL);
   if (keys[SDLK_LEFT])
      r = 1;

   return r;
}

int loop2()
{
   unsigned i;
   int r = 0;
   
   // method 2: SDL_PumpEvents
   SDL_PumpEvents();

   const Uint8 *keys = SDL_GetKeyState(NULL);
   if (keys[SDLK_RIGHT])
      r = 2;

   return r;
}

int alphakey()
{
   unsigned i;
   int r = 0;

   SDL_PumpEvents();

   const Uint8 *keys = SDL_GetKeyState(NULL);
   if (keys[SDLK_a])
      r = 4;

   return r;
}

int main(int argc, char *argv[])
{
   SDL_Init(SDL_INIT_EVERYTHING);
   SDL_SetVideoMode(600, 400, 32, SDL_SWSURFACE);

   emscripten_run_script("keydown(37);"); // left
   result += loop1();
   emscripten_run_script("keydown(39);"); // right
   result += loop2();
   emscripten_run_script("keydown(65);"); // A
   result += alphakey();
   REPORT_RESULT(result);
   return 0;
}

