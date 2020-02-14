#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_18__   TYPE_1__ ;

/* Type definitions */
struct TYPE_18__ {size_t length; void* numChannels; void* bitsPerSample; scalar_t__ sampleFrequency; struct TYPE_18__* data; } ;
typedef  TYPE_1__ BufferData ;
typedef  TYPE_1__ ALvoid ;
typedef  scalar_t__ ALuint ;
typedef  int /*<<< orphan*/  ALsizei ;
typedef  void* ALint ;
typedef  scalar_t__ ALfloat ;
typedef  int /*<<< orphan*/  ALenum ;
typedef  void* ALboolean ;

/* Variables and functions */
 int /*<<< orphan*/  ALUT_ERROR_BUFFER_DATA ; 
 int /*<<< orphan*/  ALUT_ERROR_GEN_BUFFERS ; 
 int /*<<< orphan*/  ALUT_ERROR_UNSUPPORTED_FILE_SUBTYPE ; 
 void* AL_FALSE ; 
 scalar_t__ AL_NONE ; 
 scalar_t__ AL_NO_ERROR ; 
 void* AL_TRUE ; 
 int /*<<< orphan*/  _alutFormatConstruct (void*,void*,int /*<<< orphan*/ *) ; 
 scalar_t__ _alutMalloc (int) ; 
 int /*<<< orphan*/  _alutSetError (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  alBufferData (scalar_t__,int /*<<< orphan*/ ,TYPE_1__*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  alGenBuffers (int,scalar_t__*) ; 
 scalar_t__ alGetError () ; 
 int /*<<< orphan*/  free (TYPE_1__*) ; 

BufferData *_alutBufferDataConstruct(ALvoid * data, size_t length, ALint numChannels, ALint bitsPerSample, ALfloat sampleFrequency)
{
  BufferData *bufferData = (BufferData *) _alutMalloc(sizeof(BufferData));

  if (bufferData == NULL)
  {
    return NULL;
  }

  bufferData->data = data;
  bufferData->length = length;
  bufferData->numChannels = numChannels;
  bufferData->bitsPerSample = bitsPerSample;
  bufferData->sampleFrequency = sampleFrequency;

  return bufferData;
}

ALboolean _alutBufferDataDestroy(BufferData * bufferData)
{
  if (bufferData->data != NULL)
  {
    free(bufferData->data);
  }
  free(bufferData);
  return AL_TRUE;
}

ALvoid *_alutBufferDataGetData(const BufferData * bufferData)
{
  return bufferData->data;
}

void _alutBufferDataDetachData(BufferData * bufferData)
{
  bufferData->data = NULL;
}

size_t _alutBufferDataGetLength(const BufferData * bufferData)
{
  return bufferData->length;
}

__attribute__((used)) static ALint getNumChannels(const BufferData * bufferData)
{
  return bufferData->numChannels;
}

__attribute__((used)) static ALint getBitsPerSample(const BufferData * bufferData)
{
  return bufferData->bitsPerSample;
}

ALfloat _alutBufferDataGetSampleFrequency(const BufferData * bufferData)
{
  return bufferData->sampleFrequency;
}

ALboolean _alutGetFormat(const BufferData * bufferData, ALenum * format)
{
  if (!_alutFormatConstruct(getNumChannels(bufferData), getBitsPerSample(bufferData), format))
  {
    _alutSetError(ALUT_ERROR_UNSUPPORTED_FILE_SUBTYPE);
    return AL_FALSE;
  }
  return AL_TRUE;
}

__attribute__((used)) static ALuint generateBuffer(void)
{
  ALuint buffer;

  alGenBuffers(1, &buffer);
  if (alGetError() != AL_NO_ERROR)
  {
    _alutSetError(ALUT_ERROR_GEN_BUFFERS);
    return AL_NONE;
  }
  return buffer;
}

__attribute__((used)) static ALboolean passBufferData(BufferData * bufferData, ALuint bid)
{
  ALenum format;
  size_t size;
  ALfloat frequency;

  if (!_alutGetFormat(bufferData, &format))
  {
    return AL_FALSE;
  }
  /* GCC is a bit picky about casting function calls, so we do it in two
   * steps... */
  size = _alutBufferDataGetLength(bufferData);
  frequency = _alutBufferDataGetSampleFrequency(bufferData);
  alBufferData(bid, format, _alutBufferDataGetData(bufferData), (ALsizei) size, (ALsizei) frequency);
  if (alGetError() != AL_NO_ERROR)
  {
    _alutSetError(ALUT_ERROR_BUFFER_DATA);
    return AL_FALSE;
  }
  return AL_TRUE;
}

ALuint _alutPassBufferData(BufferData * bufferData)
{
  ALuint buffer = generateBuffer();

  if (buffer == AL_NONE)
  {
    return AL_NONE;
  }

  if (!passBufferData(bufferData, buffer))
  {
    return AL_NONE;
  }

  return buffer;
}

