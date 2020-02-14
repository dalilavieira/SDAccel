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
typedef  int /*<<< orphan*/  ALuint ;
typedef  int /*<<< orphan*/  ALenum ;

/* Variables and functions */
 int /*<<< orphan*/  ALUT_WAVEFORM_IMPULSE ; 
 int /*<<< orphan*/  ALUT_WAVEFORM_SAWTOOTH ; 
 int /*<<< orphan*/  ALUT_WAVEFORM_SINE ; 
 int /*<<< orphan*/  ALUT_WAVEFORM_SQUARE ; 
 int /*<<< orphan*/  ALUT_WAVEFORM_WHITENOISE ; 
 int /*<<< orphan*/  AL_BUFFER ; 
 int EXIT_SUCCESS ; 
 int /*<<< orphan*/  alGenSources (int,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  alSourcePlay (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  alSourcei (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  alutCreateBufferWaveform (int /*<<< orphan*/ ,int,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  alutExit () ; 
 int /*<<< orphan*/  alutInit (int*,char**) ; 
 int /*<<< orphan*/  alutSleep (int) ; 

__attribute__((used)) static void playTone(ALenum waveshape)
{
  ALuint buffer, source;

  buffer = alutCreateBufferWaveform(waveshape, 440, 0, 1);
  alGenSources(1, &source);
  alSourcei(source, AL_BUFFER, buffer);
  alSourcePlay(source);
  alutSleep(1);
}

int main(int argc, char **argv)
{
  alutInit(&argc, argv);

  playTone(ALUT_WAVEFORM_SINE);
  playTone(ALUT_WAVEFORM_SQUARE);
  playTone(ALUT_WAVEFORM_SAWTOOTH);
  playTone(ALUT_WAVEFORM_WHITENOISE);
  playTone(ALUT_WAVEFORM_IMPULSE);

  alutExit();
  return EXIT_SUCCESS;
}

