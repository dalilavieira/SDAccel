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
struct TYPE_7__ {int pitch; int w; TYPE_1__* format; } ;
struct TYPE_6__ {int BitsPerPixel; int BytesPerPixel; } ;
typedef  TYPE_2__ SDL_Surface ;
typedef  int /*<<< orphan*/  FILE ;

/* Variables and functions */
 char* IMG_GetError () ; 
 TYPE_2__* IMG_Load_RW (int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  SDL_BlitSurface (TYPE_2__*,int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  SDL_Flip (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  SDL_FreeSurface (TYPE_2__*) ; 
 int /*<<< orphan*/  SDL_INIT_VIDEO ; 
 int /*<<< orphan*/  SDL_Init (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  SDL_RWFromMem (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  SDL_SWSURFACE ; 
 int /*<<< orphan*/  SDL_SetVideoMode (int,int,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  SIZE ; 
 int /*<<< orphan*/  assert (int) ; 
 int /*<<< orphan*/  buffer ; 
 int /*<<< orphan*/  fclose (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/ * fopen (char*,char*) ; 
 int /*<<< orphan*/  fread (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  malloc (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  printf (char*,...) ; 
 int /*<<< orphan*/  screen ; 

int testImage() {
  SDL_Surface *image = IMG_Load_RW(SDL_RWFromMem(buffer, SIZE), 1);
  if (!image)
  {
     printf("IMG_Load: %s\n", IMG_GetError());
     return 0;
  }

  printf("load succeeded\n");

  assert(image->format->BitsPerPixel == 32);
  assert(image->format->BytesPerPixel == 4);
  assert(image->pitch == 4*image->w);
  int result = image->w;

  SDL_BlitSurface (image, NULL, screen, NULL);
  SDL_FreeSurface (image);

  return result;
}

void ready() {
  testImage();

  SDL_Flip(screen);
}

int main() {
  SDL_Init(SDL_INIT_VIDEO);
  screen = SDL_SetVideoMode(600, 450, 32, SDL_SWSURFACE);

  printf("prepare..\n");

  FILE *f = fopen("screenshot.not", "rb");
  buffer = malloc(SIZE);
  fread(buffer, SIZE, 1, f);
  fclose(f);

  ready();

  return 0;
}

