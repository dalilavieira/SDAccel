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
typedef  int /*<<< orphan*/  GLfloat ;

/* Variables and functions */
 int /*<<< orphan*/  const* g_bt601 ; 
 int /*<<< orphan*/  const* g_bt709 ; 

const GLfloat *IJK_GLES2_getColorMatrix_bt709()
{
    return g_bt709;
}

const GLfloat *IJK_GLES2_getColorMatrix_bt601()
{
    return g_bt601;
}

