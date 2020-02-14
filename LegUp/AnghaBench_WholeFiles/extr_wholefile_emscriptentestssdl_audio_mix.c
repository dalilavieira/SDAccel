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

/* Variables and functions */
 int /*<<< orphan*/  MIX_INIT_OGG ; 
 int MIX_MAX_VOLUME ; 
 int /*<<< orphan*/  Mix_CloseAudio () ; 
 int /*<<< orphan*/  Mix_HaltChannel (int) ; 
 int /*<<< orphan*/  Mix_HaltMusic () ; 
 scalar_t__ Mix_Init (int /*<<< orphan*/ ) ; 
 int Mix_LoadMUS (char*) ; 
 int Mix_LoadWAV (char*) ; 
 int Mix_OpenAudio (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  Mix_Pause (int) ; 
 int /*<<< orphan*/  Mix_PauseMusic () ; 
 int Mix_Paused (int) ; 
 int Mix_PausedMusic () ; 
 int Mix_PlayChannel (int,int,int) ; 
 int /*<<< orphan*/  Mix_PlayMusic (int,int) ; 
 int Mix_Playing (int) ; 
 int Mix_PlayingMusic () ; 
 int /*<<< orphan*/  Mix_Quit () ; 
 int /*<<< orphan*/  Mix_ReserveChannels (int) ; 
 int /*<<< orphan*/  Mix_Resume (int) ; 
 int /*<<< orphan*/  Mix_ResumeMusic () ; 
 int /*<<< orphan*/  Mix_Volume (int,int) ; 
 int /*<<< orphan*/  SDL_INIT_AUDIO ; 
 int /*<<< orphan*/  SDL_Init (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  assert (int) ; 
 int /*<<< orphan*/  emscripten_set_main_loop (void (*) (),int,int /*<<< orphan*/ ) ; 
 int music ; 
 int noiseLoop ; 
 int noiseLoopChannel ; 
 int /*<<< orphan*/  printf (char*,int,...) ; 
 int sound ; 
 int soundChannel ; 

void one_iter() {
  static int frames = 0;
  frames++;
  
  switch( frames ) {
    case 1:
      soundChannel = Mix_PlayChannel(-1, sound, 0);
      printf("channel = %d", soundChannel);
      assert(soundChannel != -1 && soundChannel != 0);

      noiseLoopChannel = Mix_PlayChannel(-1, noiseLoop, -1);
      printf("noiseLoopChannel = %d", noiseLoopChannel);
      assert(noiseLoopChannel != -1 && noiseLoopChannel != 0);
      // set noiseLoopChannel to half volume
      Mix_Volume(noiseLoopChannel,MIX_MAX_VOLUME/10);
      break;
    case 2:
      printf("channel %d is playing = %d", soundChannel, Mix_Playing(soundChannel));
      assert(Mix_Playing(soundChannel));
      break;
    case 30:
      Mix_Pause(soundChannel);
      Mix_PlayMusic(music, 1);
      break;
    case 31:
      assert(Mix_Paused(soundChannel));
      assert(Mix_PlayingMusic());
      break;
    case 60:
      Mix_Resume(soundChannel);
      Mix_PauseMusic();
      break;
    case 61:
      assert(Mix_Playing(soundChannel));
      assert(Mix_PausedMusic());
      break;
    case 90:
      Mix_ResumeMusic();
      break;
    case 91:
      assert(Mix_PlayingMusic());
      break;
    case 120:
      Mix_HaltChannel(soundChannel);
      Mix_HaltMusic();
#ifdef REPORT_RESULT
      REPORT_RESULT(1);
#endif
      break;
  };
}

int main(int argc, char **argv) {
  SDL_Init(SDL_INIT_AUDIO);
  Mix_Init(MIX_INIT_OGG);
  
  // This reserves channel 0 for other purposes.
  // We are just going to verify that we are not
  // allocated channel 0 when we call Mix_PlayChannel(-1, ...)
  Mix_ReserveChannels(1);
  
  int ret = Mix_OpenAudio(0, 0, 0, 0); // we ignore all these..
  assert(ret == 0);

  sound = Mix_LoadWAV("sound.ogg");
  assert(sound);
  noiseLoop = Mix_LoadWAV("noise.ogg");
  assert(noiseLoop);

  music = Mix_LoadMUS("music.ogg");
  assert(music);
  emscripten_set_main_loop(one_iter, 30, 0);

  // force a quit
  while(Mix_Init(0))
    Mix_Quit();
  Mix_CloseAudio();

  return 0;
}

