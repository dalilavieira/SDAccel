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
 unsigned int UV_VERSION_HEX ; 
 char const* UV_VERSION_STRING ; 

unsigned int uv_version(void) {
  return UV_VERSION_HEX;
}

const char* uv_version_string(void) {
  return UV_VERSION_STRING;
}

