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
typedef  int uint8_t ;
typedef  scalar_t__ int8_t ;
typedef  int int16_t ;
typedef  int ALvoid ;
typedef  int /*<<< orphan*/  ALint ;
typedef  int /*<<< orphan*/  ALfloat ;

/* Variables and functions */
 int QUANT_MASK ; 
 int SEG_MASK ; 
 int SEG_SHIFT ; 
 int SIGN_BIT ; 
 int* _alutBufferDataConstruct (int*,size_t,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 scalar_t__ _alutMalloc (size_t) ; 
 int /*<<< orphan*/  free (int*) ; 

ALvoid *_alutCodecLinear(ALvoid * data, size_t length, ALint numChannels, ALint bitsPerSample, ALfloat sampleFrequency)
{
  return _alutBufferDataConstruct(data, length, numChannels, bitsPerSample, sampleFrequency);
}

ALvoid *_alutCodecPCM8s(ALvoid * data, size_t length, ALint numChannels, ALint bitsPerSample, ALfloat sampleFrequency)
{
  int8_t *d = (int8_t *) data;
  size_t i;

  for (i = 0; i < length; i++)
  {
    d[i] += (int8_t) 128;
  }
  return _alutBufferDataConstruct(data, length, numChannels, bitsPerSample, sampleFrequency);
}

ALvoid *_alutCodecPCM16(ALvoid * data, size_t length, ALint numChannels, ALint bitsPerSample, ALfloat sampleFrequency)
{
  int16_t *d = (int16_t *) data;
  size_t i, l = length / 2;

  for (i = 0; i < l; i++)
  {
    int16_t x = d[i];

    d[i] = ((x << 8) & 0xFF00) | ((x >> 8) & 0x00FF);
  }
  return _alutBufferDataConstruct(data, length, numChannels, bitsPerSample, sampleFrequency);
}

__attribute__((used)) static int16_t mulaw2linear(uint8_t mulawbyte)
{
  static const int16_t exp_lut[8] = {
    0, 132, 396, 924, 1980, 4092, 8316, 16764
  };
  int16_t sign, exponent, mantissa, sample;

  mulawbyte = ~mulawbyte;
  sign = (mulawbyte & 0x80);
  exponent = (mulawbyte >> 4) & 0x07;
  mantissa = mulawbyte & 0x0F;
  sample = exp_lut[exponent] + (mantissa << (exponent + 3));
  if (sign != 0)
  {
    sample = -sample;
  }
  return sample;
}

ALvoid *_alutCodecULaw(ALvoid * data, size_t length, ALint numChannels, ALint bitsPerSample, ALfloat sampleFrequency)
{
  uint8_t *d = (uint8_t *) data;
  int16_t *buf = (int16_t *) _alutMalloc(length * 2);
  size_t i;

  if (buf == NULL)
  {
    return NULL;
  }
  for (i = 0; i < length; i++)
  {
    buf[i] = mulaw2linear(d[i]);
  }
  free(data);
  return _alutBufferDataConstruct(buf, length * 2, numChannels, bitsPerSample, sampleFrequency);
}

__attribute__((used)) static int16_t alaw2linear(uint8_t a_val)
{
  int16_t t, seg;

  a_val ^= 0x55;
  t = (a_val & QUANT_MASK) << 4;
  seg = ((int16_t) a_val & SEG_MASK) >> SEG_SHIFT;
  switch (seg)
  {
  case 0:
    t += 8;
    break;
  case 1:
    t += 0x108;
    break;
  default:
    t += 0x108;
    t <<= seg - 1;
  }
  return (a_val & SIGN_BIT) ? t : -t;
}

ALvoid *_alutCodecALaw(ALvoid * data, size_t length, ALint numChannels, ALint bitsPerSample, ALfloat sampleFrequency)
{
  uint8_t *d = (uint8_t *) data;
  int16_t *buf = (int16_t *) _alutMalloc(length * 2);
  size_t i;

  if (buf == NULL)
  {
    return NULL;
  }
  for (i = 0; i < length; i++)
  {
    buf[i] = alaw2linear(d[i]);
  }
  free(data);
  return _alutBufferDataConstruct(buf, length * 2, numChannels, bitsPerSample, sampleFrequency);
}

