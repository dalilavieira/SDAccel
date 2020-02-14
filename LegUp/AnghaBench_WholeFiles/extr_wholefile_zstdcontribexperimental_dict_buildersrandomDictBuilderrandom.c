#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_10__   TYPE_3__ ;
typedef  struct TYPE_9__   TYPE_2__ ;
typedef  struct TYPE_8__   TYPE_1__ ;

/* Type definitions */
struct TYPE_8__ {int notificationLevel; } ;
struct TYPE_9__ {size_t k; TYPE_1__ zParams; } ;
typedef  TYPE_2__ ZDICT_random_params_t ;
typedef  size_t U32 ;
struct TYPE_10__ {unsigned int begin; unsigned int end; } ;
typedef  TYPE_3__ RANDOM_segment_t ;
typedef  int /*<<< orphan*/  BYTE ;

/* Variables and functions */
 int /*<<< orphan*/  DISPLAYUPDATE (int,char*,size_t) ; 
 size_t MIN (unsigned int,size_t) ; 
 int /*<<< orphan*/  memcpy (int /*<<< orphan*/ * const,int /*<<< orphan*/  const*,size_t) ; 
 size_t const rand () ; 

__attribute__((used)) static size_t RANDOM_sum(const size_t *samplesSizes, unsigned nbSamples) {
  size_t sum = 0;
  unsigned i;
  for (i = 0; i < nbSamples; ++i) {
    sum += samplesSizes[i];
  }
  return sum;
}

__attribute__((used)) static RANDOM_segment_t RANDOM_selectSegment(const size_t totalSamplesSize,
                                            ZDICT_random_params_t parameters) {
    const U32 k = parameters.k;
    RANDOM_segment_t segment;
    unsigned index;

    /* Randomly generate a number from 0 to sampleSizes - k */
    index = rand()%(totalSamplesSize - k + 1);

    /* inclusive */
    segment.begin = index;
    segment.end = index + k - 1;

    return segment;
}

__attribute__((used)) static int RANDOM_checkParameters(ZDICT_random_params_t parameters,
                                  size_t maxDictSize) {
    /* k is a required parameter */
    if (parameters.k == 0) {
      return 0;
    }
    /* k <= maxDictSize */
    if (parameters.k > maxDictSize) {
      return 0;
    }
    return 1;
}

__attribute__((used)) static size_t RANDOM_buildDictionary(const size_t totalSamplesSize, const BYTE *samples,
                                    void *dictBuffer, size_t dictBufferCapacity,
                                    ZDICT_random_params_t parameters) {
    BYTE *const dict = (BYTE *)dictBuffer;
    size_t tail = dictBufferCapacity;
    const int displayLevel = parameters.zParams.notificationLevel;
    while (tail > 0) {

      /* Select a segment */
      RANDOM_segment_t segment = RANDOM_selectSegment(totalSamplesSize, parameters);

      size_t segmentSize;
      segmentSize = MIN(segment.end - segment.begin + 1, tail);

      tail -= segmentSize;
      memcpy(dict + tail, samples + segment.begin, segmentSize);
      DISPLAYUPDATE(
          2, "\r%u%%       ",
          (U32)(((dictBufferCapacity - tail) * 100) / dictBufferCapacity));
    }

    return tail;
}

