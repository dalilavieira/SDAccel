#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_22__   TYPE_3__ ;
typedef  struct TYPE_21__   TYPE_2__ ;
typedef  struct TYPE_20__   TYPE_1__ ;

/* Type definitions */
struct TYPE_22__ {int /*<<< orphan*/  format; } ;
struct TYPE_21__ {scalar_t__ type; } ;
struct TYPE_20__ {int member_2; int member_3; int x; int y; int /*<<< orphan*/  member_1; int /*<<< orphan*/  member_0; } ;
typedef  TYPE_1__ SDL_Rect ;
typedef  TYPE_2__ SDL_Event ;

/* Variables and functions */
 TYPE_3__* IMG_Load (char*) ; 
 int /*<<< orphan*/  SDL_BlitSurface (TYPE_3__*,int /*<<< orphan*/ ,TYPE_3__*,TYPE_1__*) ; 
 TYPE_3__* SDL_CreateRGBSurface (int /*<<< orphan*/ ,int,int,int,int,int,int,int) ; 
 int /*<<< orphan*/  SDL_Delay (int) ; 
 int /*<<< orphan*/  SDL_FillRect (TYPE_3__*,TYPE_1__*,int) ; 
 int /*<<< orphan*/  SDL_INIT_VIDEO ; 
 int /*<<< orphan*/  SDL_Init (int /*<<< orphan*/ ) ; 
 int SDL_MapRGBA (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int) ; 
 scalar_t__ SDL_PollEvent (TYPE_2__*) ; 
 scalar_t__ SDL_QUIT ; 
 int /*<<< orphan*/  SDL_Quit () ; 
 int /*<<< orphan*/  SDL_SWSURFACE ; 
 int /*<<< orphan*/  SDL_SaveBMP (TYPE_3__*,char*) ; 
 TYPE_3__* SDL_SetVideoMode (int const,int const,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  SDL_UpdateRect (TYPE_3__*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  SMOOTHING_ON ; 
 int numSprites ; 
 TYPE_3__* rotozoomSurface (TYPE_3__*,int,double,int /*<<< orphan*/ ) ; 
 TYPE_3__* screen ; 
 TYPE_3__** sprite ; 
 TYPE_3__* zoomSurface (TYPE_3__*,double,double,int /*<<< orphan*/ ) ; 

void mainloop() {
    int i;
    int row = 0;
    SDL_Rect rect = { 0, 0, 100, 100 };
    for (i = 0; i < numSprites; i++) {
        rect.x = i & 1 ? 200 : 0;
        rect.y = row * 200;
        row += i & 1;
        SDL_BlitSurface(sprite[i], 0, screen, &rect);
        SDL_UpdateRect(screen, 0, 0, 0, 0);
    }
}

int main(int argc, char **argv) {
    SDL_Init(SDL_INIT_VIDEO);

    const int width = 400;
    const int height = 200 * (numSprites + 1) / 2;
    screen = SDL_SetVideoMode(width, height, 32, SDL_SWSURFACE);
    SDL_Rect rect = { 0, 0, width, height };
    SDL_FillRect(screen, &rect, SDL_MapRGBA(screen->format, 0, 0, 0, 0xff));

    sprite[0] = IMG_Load("screenshot.png");
    sprite[1] = SDL_CreateRGBSurface(SDL_SWSURFACE, 100, 100, 32, 0xFF000000, 0xFF0000, 0xFF00, 0xFF);
    SDL_FillRect(sprite[1], 0, 0xA0A0A0A0);
    sprite[2] = zoomSurface(sprite[0], 0.5, 0.5, SMOOTHING_ON);
    sprite[3] = zoomSurface(sprite[1], 0.5, 0.5, SMOOTHING_ON);
    sprite[4] = rotozoomSurface(sprite[0], -20, 0.3, SMOOTHING_ON);
    sprite[5] = rotozoomSurface(sprite[1], 20, 1, SMOOTHING_ON);
    sprite[6] = zoomSurface(sprite[0], -0.5, 0.5, SMOOTHING_ON);
    sprite[7] = zoomSurface(sprite[0], -0.5, -0.5, SMOOTHING_ON);
    sprite[8] = rotozoomSurface(sprite[1], 0, 0.5, SMOOTHING_ON);

    mainloop();

#ifndef __EMSCRIPTEN__
    SDL_Event evt;
    SDL_SaveBMP(screen, "native_output.bmp");
    while (1) {
       if (SDL_PollEvent(&evt) != 0 && evt.type == SDL_QUIT) break;
       //mainloop();
       SDL_Delay(33);
    }
#endif

    SDL_Quit();

    return 1;
}

