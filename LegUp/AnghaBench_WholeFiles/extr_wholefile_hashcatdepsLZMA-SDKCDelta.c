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
typedef  size_t SizeT ;
typedef  scalar_t__ Byte ;

/* Variables and functions */
 unsigned int DELTA_STATE_SIZE ; 

void Delta_Init(Byte *state)
{
  unsigned i;
  for (i = 0; i < DELTA_STATE_SIZE; i++)
    state[i] = 0;
}

__attribute__((used)) static void MyMemCpy(Byte *dest, const Byte *src, unsigned size)
{
  unsigned i;
  for (i = 0; i < size; i++)
    dest[i] = src[i];
}

void Delta_Encode(Byte *state, unsigned delta, Byte *data, SizeT size)
{
  Byte buf[DELTA_STATE_SIZE];
  unsigned j = 0;
  MyMemCpy(buf, state, delta);
  {
    SizeT i;
    for (i = 0; i < size;)
    {
      for (j = 0; j < delta && i < size; i++, j++)
      {
        Byte b = data[i];
        data[i] = (Byte)(b - buf[j]);
        buf[j] = b;
      }
    }
  }
  if (j == delta)
    j = 0;
  MyMemCpy(state, buf + j, delta - j);
  MyMemCpy(state + delta - j, buf, j);
}

void Delta_Decode(Byte *state, unsigned delta, Byte *data, SizeT size)
{
  Byte buf[DELTA_STATE_SIZE];
  unsigned j = 0;
  MyMemCpy(buf, state, delta);
  {
    SizeT i;
    for (i = 0; i < size;)
    {
      for (j = 0; j < delta && i < size; i++, j++)
      {
        buf[j] = data[i] = (Byte)(buf[j] + data[i]);
      }
    }
  }
  if (j == delta)
    j = 0;
  MyMemCpy(state, buf + j, delta - j);
  MyMemCpy(state + delta - j, buf, j);
}

