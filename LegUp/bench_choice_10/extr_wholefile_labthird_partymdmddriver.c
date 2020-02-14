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
typedef  long time_t ;
typedef  int /*<<< orphan*/  MD_CTX ;
typedef  int /*<<< orphan*/  FILE ;

/* Variables and functions */
 int MD ; 
static  void MDFile (char*) ; 
static  void MDFilter () ; 
 int /*<<< orphan*/  MDFinal (unsigned char*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  MDInit (int /*<<< orphan*/ *) ; 
static  void MDPrint (unsigned char*) ; 
static  void MDString (char*) ; 
static  void MDTestSuite () ; 
static  void MDTimeTrial () ; 
 int /*<<< orphan*/  MDUpdate (int /*<<< orphan*/ *,unsigned char*,int) ; 
 int TEST_BLOCK_COUNT ; 
 int TEST_BLOCK_LEN ; 
 int /*<<< orphan*/  fclose (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/ * fopen (char*,char*) ; 
 int fread (unsigned char*,int,int,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  printf (char*,...) ; 
 int /*<<< orphan*/ * stdin ; 
 scalar_t__ strcmp (char*,char*) ; 
 unsigned int strlen (char*) ; 
 int /*<<< orphan*/  time (long*) ; 

int main(int argc, char *argv[])
{
  int i;

  if (argc > 1) {
    for (i = 1; i < argc; i++) {
      if (argv[i][0] == '-' && argv[i][1] == 's')
        MDString(argv[i] + 2);
      else if (strcmp(argv[i], "-t") == 0)
        MDTimeTrial();
      else if (strcmp(argv[i], "-x") == 0)
        MDTestSuite();
      else
        MDFile(argv[i]);
    }
  } else {
    MDFilter();
  }

  return (0);
}

__attribute__((used)) static void MDString (char *string)
{
  MD_CTX context;
  unsigned char digest[16];
  unsigned int len = strlen(string);

  MDInit(&context);
  MDUpdate(&context, (unsigned char*)string, len);
  MDFinal(digest, &context);

  printf("MD%d (\"%s\") = ", MD, string);
  MDPrint(digest);
  printf("\n");
}

__attribute__((used)) static void MDTimeTrial(void)
{
  MD_CTX context;
  time_t endTime, startTime;
  unsigned char block[TEST_BLOCK_LEN], digest[16];
  unsigned int i;

  printf("MD%d time trial. Digesting %d %d-byte blocks ...",
         MD, TEST_BLOCK_LEN, TEST_BLOCK_COUNT);

  /* Initialize block */
  for (i = 0; i < TEST_BLOCK_LEN; i++)
    block[i] = (unsigned char)(i & 0xff);

  /* Start timer */
  time(&startTime);

  /* Digest blocks */
  MDInit(&context);
  for (i = 0; i < TEST_BLOCK_COUNT; i++)
    MDUpdate(&context, block, TEST_BLOCK_LEN);
  MDFinal(digest, &context);

  /* Stop timer */
  time(&endTime);

  printf(" done\n");
  printf("Digest = ");
  MDPrint(digest);
  printf("\nTime = %ld seconds\n", (long)(endTime-startTime));
  printf("Speed = %ld bytes/second\n",
         (long)TEST_BLOCK_LEN * (long)TEST_BLOCK_COUNT/(endTime-startTime));
}

__attribute__((used)) static void MDTestSuite(void)
{
  printf ("MD%d test suite:\n", MD);

  MDString("");
  MDString("a");
  MDString("abc");
  MDString("message digest");
  MDString("abcdefghijklmnopqrstuvwxyz");
  MDString("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789");
  MDString("12345678901234567890123456789012345678901234567890123456789012345678901234567890");
}

__attribute__((used)) static void MDFile(char *filename)
{
  FILE *file;
  MD_CTX context;
  int len;
  unsigned char buffer[1024], digest[16];

  if ((file = fopen (filename, "rb")) == NULL) {
    printf("%s can't be opened\n", filename);
  } else {
    MDInit(&context);
    while ((len = fread (buffer, 1, 1024, file)))
      MDUpdate(&context, buffer, len);
    MDFinal(digest, &context);

    fclose(file);

    printf("MD%d (%s) = ", MD, filename);
    MDPrint(digest);
    printf("\n");
  }
}

__attribute__((used)) static void MDFilter(void)
{
  MD_CTX context;
  int len;
  unsigned char buffer[16], digest[16];

  MDInit (&context);
  while ((len = fread (buffer, 1, 16, stdin)))
    MDUpdate(&context, buffer, len);
  MDFinal(digest, &context);

  MDPrint(digest);
  printf("\n");
}

__attribute__((used)) static void MDPrint(unsigned char digest[16])
{
  unsigned int i;

  for (i = 0; i < 16; i++)
    printf ("%02x", digest[i]);
}

