#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_6__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  cl_program ;
typedef  int /*<<< orphan*/  cl_mem ;
typedef  int /*<<< orphan*/  cl_event ;
typedef  int /*<<< orphan*/  cl_device_id ;
typedef  int /*<<< orphan*/  cl_context ;
typedef  int /*<<< orphan*/  cl_command_queue ;
typedef  int /*<<< orphan*/  args ;
struct TYPE_6__ {int width; int height; int /*<<< orphan*/  rgb_to_yuv_krnl; } ;
typedef  TYPE_1__ RGBToYUVState ;

/* Variables and functions */
 int /*<<< orphan*/  CLU_LOAD_FROM_FILE (int /*<<< orphan*/ ,int /*<<< orphan*/ ,char*,char*) ; 
 int /*<<< orphan*/  assert (int) ; 
 int /*<<< orphan*/  clCreateKernel (int /*<<< orphan*/ ,char*,int*) ; 
 int clEnqueueNDRangeKernel (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int,int /*<<< orphan*/ *,size_t const*,int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  clReleaseEvent (int /*<<< orphan*/ ) ; 
 int clReleaseKernel (int /*<<< orphan*/ ) ; 
 int clReleaseProgram (int /*<<< orphan*/ ) ; 
 int clSetKernelArg (int /*<<< orphan*/ ,int,int,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  clWaitForEvents (int,int /*<<< orphan*/ *) ; 
 char* cl_get_error_string (int) ; 
 int /*<<< orphan*/  exit (int) ; 
 int /*<<< orphan*/  fprintf (int /*<<< orphan*/ ,char*,char*) ; 
 int /*<<< orphan*/  memset (TYPE_1__*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  snprintf (char*,int,char*,int,int,int,int,int,int) ; 
 int /*<<< orphan*/  stderr ; 

__attribute__((used)) static inline int cl_check_error(int err) {
  if (err != 0) {
    fprintf(stderr, "%s\n", cl_get_error_string(err));
    exit(1);
  }
  return err;
}

void rgb_to_yuv_init(RGBToYUVState* s, cl_context ctx, cl_device_id device_id, int width, int height, int rgb_stride) {
  int err = 0;
  memset(s, 0, sizeof(*s));
  assert(width % 2 == 0);
  assert(height % 2 == 0);
  s->width = width;
  s->height = height;
  char args[1024];
  snprintf(args, sizeof(args),
           "-cl-fast-relaxed-math -cl-denorms-are-zero "
#ifdef CL_DEBUG
           "-DCL_DEBUG "
#endif
           "-DWIDTH=%d -DHEIGHT=%d -DUV_WIDTH=%d -DUV_HEIGHT=%d -DRGB_STRIDE=%d -DRGB_SIZE=%d",
           width, height, width/ 2, height / 2, rgb_stride, width * height);
  cl_program prg = CLU_LOAD_FROM_FILE(ctx, device_id, "rgb_to_yuv.cl", args);

  s->rgb_to_yuv_krnl = clCreateKernel(prg, "rgb_to_yuv", &err);
  assert(err == 0);
  // done with this
  err = clReleaseProgram(prg);
  assert(err == 0);
}

void rgb_to_yuv_destroy(RGBToYUVState* s) {
  int err = 0;
  err = clReleaseKernel(s->rgb_to_yuv_krnl);
  assert(err == 0);
}

void rgb_to_yuv_queue(RGBToYUVState* s, cl_command_queue q, cl_mem rgb_cl, cl_mem yuv_cl) {
  int err = 0;
  err = clSetKernelArg(s->rgb_to_yuv_krnl, 0, sizeof(cl_mem), &rgb_cl);
  assert(err == 0);
  err = clSetKernelArg(s->rgb_to_yuv_krnl, 1, sizeof(cl_mem), &yuv_cl);
  assert(err == 0);
  const size_t work_size[2] = {
    (size_t)(s->width + (s->width % 4 == 0 ? 0 : (4 - s->width % 4))) / 4, 
    (size_t)(s->height + (s->height % 4 == 0 ? 0 : (4 - s->height % 4))) / 4
  };
  cl_event event;
  err = clEnqueueNDRangeKernel(q, s->rgb_to_yuv_krnl, 2, NULL, &work_size[0], NULL, 0, 0, &event);
  assert(err == 0);
  clWaitForEvents(1, &event);
  clReleaseEvent(event);
}

