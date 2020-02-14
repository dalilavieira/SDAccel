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
 int /*<<< orphan*/  assert (int) ; 
 int /*<<< orphan*/  compress (unsigned char*,unsigned long*,unsigned char*,int) ; 
 unsigned long compressBound (int) ; 
 scalar_t__ malloc (int) ; 
 int /*<<< orphan*/  printf (char*,...) ; 
 scalar_t__ strcmp (char*,char*) ; 
 int /*<<< orphan*/  uncompress (unsigned char*,unsigned long*,unsigned char*,int) ; 

void __attribute__ ((noinline)) doit(unsigned char *buffer, int size, int i) {
  static unsigned char *buffer2 = NULL;
  static unsigned char *buffer3 = NULL;

  unsigned long maxCompressedSize = compressBound(size);

  if (!buffer2) buffer2 = (unsigned char*)malloc(maxCompressedSize);
  if (!buffer3) buffer3 = (unsigned char*)malloc(size);

  unsigned long compressedSize = maxCompressedSize;
  compress(buffer2, &compressedSize, buffer, size);
  if (i == 0) printf("sizes: %d,%d\n", size, (int)compressedSize);

  unsigned long decompressedSize = size;
  uncompress(buffer3, &decompressedSize, buffer2, (int)compressedSize);
  assert(decompressedSize == size);
  if (i == 0) assert(strcmp((char*)buffer, (char*)buffer3) == 0);
}

int main(int argc, char **argv) {
  int size, iters;
  int arg = argc > 1 ? argv[1][0] - '0' : 3;
  switch(arg) {
    case 0: return 0; break;
    case 1: size = 100000; iters = 60; break;
    case 2: size = 100000; iters = 250; break;
    case 3: size = 100000; iters = 500; break;
    case 4: size = 100000; iters = 5*500; break;
    case 5: size = 100000; iters = 10*500; break;
    default: printf("error: %d\\n", arg); return -1;
  }

  unsigned char *buffer = (unsigned char*)malloc(size);

  int i = 0;
  int run = 0;
  char runChar = 17;
  while (i < size) {
    if (run > 0) {
      run--;
    } else {
      if ((i & 7) == 0) {
        runChar = i & 7;
        run = i & 31;
      } else {
        runChar = (i*i) % 6714;
      }
    }
    buffer[i] = runChar;
    i++;
  }

  for (i = 0; i < iters; i++) {
    doit(buffer, size, i);
  }

  printf("ok.\n");

  return 0;
}

