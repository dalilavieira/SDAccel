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
typedef  int /*<<< orphan*/  ALboolean ;
typedef  int /*<<< orphan*/  ALCdevice ;
typedef  int /*<<< orphan*/  ALCcontext ;

/* Variables and functions */
 scalar_t__ ALC_NO_ERROR ; 
 scalar_t__ ALUTDeviceAndContext ; 
 int /*<<< orphan*/  ALUT_ERROR_ALC_ERROR_ON_ENTRY ; 
 int /*<<< orphan*/  ALUT_ERROR_AL_ERROR_ON_ENTRY ; 
 int /*<<< orphan*/  ALUT_ERROR_CLOSE_DEVICE ; 
 int /*<<< orphan*/  ALUT_ERROR_CREATE_CONTEXT ; 
 int /*<<< orphan*/  ALUT_ERROR_DESTROY_CONTEXT ; 
 int /*<<< orphan*/  ALUT_ERROR_INVALID_OPERATION ; 
 int /*<<< orphan*/  ALUT_ERROR_INVALID_VALUE ; 
 int /*<<< orphan*/  ALUT_ERROR_MAKE_CONTEXT_CURRENT ; 
 int /*<<< orphan*/  ALUT_ERROR_NO_CURRENT_CONTEXT ; 
 int /*<<< orphan*/  ALUT_ERROR_OPEN_DEVICE ; 
 int /*<<< orphan*/  AL_FALSE ; 
 scalar_t__ AL_NO_ERROR ; 
 int /*<<< orphan*/  AL_TRUE ; 
 scalar_t__ ExternalDeviceAndContext ; 
 scalar_t__ Unintialized ; 
 int /*<<< orphan*/  _alutSetError (int /*<<< orphan*/ ) ; 
 scalar_t__ alGetError () ; 
 int /*<<< orphan*/  alcCloseDevice (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/ * alcCreateContext (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  alcDestroyContext (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/ * alcGetContextsDevice (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/ * alcGetCurrentContext () ; 
 scalar_t__ alcGetError (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  alcMakeContextCurrent (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/ * alcOpenDevice (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/ * alutContext ; 
 scalar_t__ initialisationState ; 

ALboolean _alutSanityCheck(void)
{
  ALCcontext *context;

  if (initialisationState == Unintialized)
  {
    _alutSetError(ALUT_ERROR_INVALID_OPERATION);
    return AL_FALSE;
  }

  context = alcGetCurrentContext();
  if (context == NULL)
  {
    _alutSetError(ALUT_ERROR_NO_CURRENT_CONTEXT);
    return AL_FALSE;
  }

  if (alGetError() != AL_NO_ERROR)
  {
    _alutSetError(ALUT_ERROR_AL_ERROR_ON_ENTRY);
    return AL_FALSE;
  }

  if (alcGetError(alcGetContextsDevice(context)) != ALC_NO_ERROR)
  {
    _alutSetError(ALUT_ERROR_ALC_ERROR_ON_ENTRY);
    return AL_FALSE;
  }

  return AL_TRUE;
}

ALboolean alutInit(int *argcp, char **argv)
{
  ALCdevice *device;
  ALCcontext *context;

  if (initialisationState != Unintialized)
  {
    _alutSetError(ALUT_ERROR_INVALID_OPERATION);
    return AL_FALSE;
  }

  if ((argcp == NULL) != (argv == NULL))
  {
    _alutSetError(ALUT_ERROR_INVALID_VALUE);
    return AL_FALSE;
  }

  device = alcOpenDevice(NULL);
  if (device == NULL)
  {
    _alutSetError(ALUT_ERROR_OPEN_DEVICE);
    return AL_FALSE;
  }

  context = alcCreateContext(device, NULL);
  if (context == NULL)
  {
    alcCloseDevice(device);
    _alutSetError(ALUT_ERROR_CREATE_CONTEXT);
    return AL_FALSE;
  }

  if (!alcMakeContextCurrent(context))
  {
    alcDestroyContext(context);
    alcCloseDevice(device);
    _alutSetError(ALUT_ERROR_MAKE_CONTEXT_CURRENT);
    return AL_FALSE;
  }

  initialisationState = ALUTDeviceAndContext;
  alutContext = context;
  return AL_TRUE;
}

ALboolean alutInitWithoutContext(int *argcp, char **argv)
{
  if (initialisationState != Unintialized)
  {
    _alutSetError(ALUT_ERROR_INVALID_OPERATION);
    return AL_FALSE;
  }

  if ((argcp == NULL) != (argv == NULL))
  {
    _alutSetError(ALUT_ERROR_INVALID_VALUE);
    return AL_FALSE;
  }

  initialisationState = ExternalDeviceAndContext;
  return AL_TRUE;
}

ALboolean alutExit(void)
{
  ALCdevice *device;

  if (initialisationState == Unintialized)
  {
    _alutSetError(ALUT_ERROR_INVALID_OPERATION);
    return AL_FALSE;
  }

  if (initialisationState == ExternalDeviceAndContext)
  {
    initialisationState = Unintialized;
    return AL_TRUE;
  }

  if (!_alutSanityCheck())
  {
    return AL_FALSE;
  }

  if (!alcMakeContextCurrent(NULL))
  {
    _alutSetError(ALUT_ERROR_MAKE_CONTEXT_CURRENT);
    return AL_FALSE;
  }

  device = alcGetContextsDevice(alutContext);
  alcDestroyContext(alutContext);
  if (alcGetError(device) != ALC_NO_ERROR)
  {
    _alutSetError(ALUT_ERROR_DESTROY_CONTEXT);
    return AL_FALSE;
  }

  if (!alcCloseDevice(device))
  {
    _alutSetError(ALUT_ERROR_CLOSE_DEVICE);
    return AL_FALSE;
  }

  initialisationState = Unintialized;
  return AL_TRUE;
}

