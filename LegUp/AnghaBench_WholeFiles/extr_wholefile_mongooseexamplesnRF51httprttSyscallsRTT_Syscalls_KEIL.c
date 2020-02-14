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
typedef  scalar_t__ FILEHANDLE ;

/* Variables and functions */
 unsigned int SEGGER_RTT_Write (int /*<<< orphan*/ ,char const*,unsigned int) ; 
 scalar_t__ STDERR ; 
 scalar_t__ STDOUT ; 
 int /*<<< orphan*/  __stderr_name ; 
 int /*<<< orphan*/  __stdout_name ; 
 int /*<<< orphan*/  fflush (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  fputc (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  stdout ; 
 scalar_t__ strcmp (char const*,int /*<<< orphan*/ ) ; 

void _ttywrch(int c) {
  fputc(c, stdout); // stdout
  fflush(stdout);
}

FILEHANDLE _sys_open(const char * sName, int OpenMode) {
  // Register standard Input Output devices.
  if (strcmp(sName, __stdout_name) == 0) {
    return (STDOUT);
  } else if (strcmp(sName, __stderr_name) == 0) {
    return (STDERR);
  } else
  return (0);  // Not implemented
}

int _sys_close(FILEHANDLE hFile) {
  return 0;  // Not implemented
}

int _sys_write(FILEHANDLE hFile, const unsigned char * pBuffer, unsigned NumBytes, int Mode) {
  int r = 0;

  if (hFile == STDOUT) {
    return NumBytes - SEGGER_RTT_Write(0, (const char*)pBuffer, NumBytes);
  }
  return r;
}

int _sys_read(FILEHANDLE hFile, unsigned char * pBuffer, unsigned NumBytes, int Mode) {
  return (0);  // Not implemented
}

int _sys_istty(FILEHANDLE hFile) {
  if (hFile > 0x8000) {
    return (1);
  }
  return (0);  // Not implemented
}

int _sys_seek(FILEHANDLE hFile, long Pos) {
  return (0);  // Not implemented
}

int _sys_ensure(FILEHANDLE hFile) {
  return (-1);  // Not implemented
}

long _sys_flen(FILEHANDLE hFile) {
  return (0);  // Not implemented
}

int _sys_tmpnam(char * pBuffer, int FileNum, unsigned MaxLen) {
  return (1);  // Not implemented
}

char * _sys_command_string(char * cmd, int len) {
  return cmd;  // Not implemented
}

void _sys_exit(int ReturnCode) {
  while (1);  // Not implemented
}

