#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_6__   TYPE_1__ ;

/* Type definitions */
struct TYPE_6__ {int /*<<< orphan*/  refcount; } ;
typedef  TYPE_1__ SDL_Surface ;

/* Variables and functions */
 int /*<<< orphan*/  REPORT_RESULT (int) ; 
 TYPE_1__* SDL_CreateRGBSurface (int /*<<< orphan*/ ,int,int,int,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  SDL_FreeSurface (TYPE_1__*) ; 
 int /*<<< orphan*/  SDL_SWSURFACE ; 
 int emscripten_run_script_int (char*) ; 
 int /*<<< orphan*/  free (char*) ; 
 char* malloc (int) ; 
 int snprintf (char*,int,char const*,TYPE_1__*) ; 

int is_surface_freed(SDL_Surface *surface)
{
    const char *template = "!SDL.surfaces[%d]";
    int length = snprintf(NULL, 0, template, surface) + 1;
    char *script = malloc(length * sizeof(char));
    snprintf(script, length, template, surface);
    int is_freed = emscripten_run_script_int(script);
    free(script);
    return is_freed;
}

int main(int argc, char *argv[])
{
    SDL_Surface *surface = SDL_CreateRGBSurface(SDL_SWSURFACE, 10, 10, 32,
                                                0, 0, 0, 0);
    SDL_Surface *reference = surface;
    reference->refcount++;
    SDL_FreeSurface(surface);
    SDL_FreeSurface(reference);
    int result = is_surface_freed(surface);
    REPORT_RESULT(result);
    return 0;
}

