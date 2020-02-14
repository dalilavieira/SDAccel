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
typedef  int cl_mem ;
typedef  int cl_int ;
typedef  int /*<<< orphan*/  cl_device_id ;
typedef  int /*<<< orphan*/  cl_context ;
typedef  int /*<<< orphan*/  cl_command_queue ;
typedef  int /*<<< orphan*/  args ;
struct TYPE_6__ {int width; int height; void* loaduv_krnl; void* loadys_krnl; } ;
typedef  TYPE_1__ LoadYUVState ;

/* Variables and functions */
 int /*<<< orphan*/  CLU_LOAD_FROM_FILE (int /*<<< orphan*/ ,int /*<<< orphan*/ ,char*,char*) ; 
 int /*<<< orphan*/  assert (int) ; 
 void* clCreateKernel (int /*<<< orphan*/ ,char*,int*) ; 
 int clEnqueueNDRangeKernel (int /*<<< orphan*/ ,void*,int,int /*<<< orphan*/ *,size_t const*,int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int clReleaseKernel (void*) ; 
 int clReleaseProgram (int /*<<< orphan*/ ) ; 
 int clSetKernelArg (void*,int,int,int*) ; 
 char* cl_get_error_string (int) ; 
 int /*<<< orphan*/  exit (int) ; 
 int /*<<< orphan*/  fprintf (int /*<<< orphan*/ ,char*,char*) ; 
 int /*<<< orphan*/  memset (TYPE_1__*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  snprintf (char*,int,char*,int,int) ; 
 int /*<<< orphan*/  stderr ; 

__attribute__((used)) static inline int cl_check_error(int err) {
  if (err != 0) {
    fprintf(stderr, "%s\n", cl_get_error_string(err));
    exit(1);
  }
  return err;
}

void loadyuv_init(LoadYUVState* s, cl_context ctx, cl_device_id device_id, int width, int height) {
  int err = 0;
  memset(s, 0, sizeof(*s));

  s->width = width;
  s->height = height;

  char args[1024];
  snprintf(args, sizeof(args),
           "-cl-fast-relaxed-math -cl-denorms-are-zero "
           "-DTRANSFORMED_WIDTH=%d -DTRANSFORMED_HEIGHT=%d",
           width, height);
  cl_program prg = CLU_LOAD_FROM_FILE(ctx, device_id, "loadyuv.cl", args);

  s->loadys_krnl = clCreateKernel(prg, "loadys", &err);
  assert(err == 0);
  s->loaduv_krnl = clCreateKernel(prg, "loaduv", &err);
  assert(err == 0);

  // done with this
  err = clReleaseProgram(prg);
  assert(err == 0);
}

void loadyuv_destroy(LoadYUVState* s) {
  int err = 0;

  err = clReleaseKernel(s->loadys_krnl);
  assert(err == 0);
  err = clReleaseKernel(s->loaduv_krnl);
  assert(err == 0);
}

void loadyuv_queue(LoadYUVState* s, cl_command_queue q,
                   cl_mem y_cl, cl_mem u_cl, cl_mem v_cl,
                   cl_mem out_cl) {
  int err = 0;

  err = clSetKernelArg(s->loadys_krnl, 0, sizeof(cl_mem), &y_cl);
  assert(err == 0);
  err = clSetKernelArg(s->loadys_krnl, 1, sizeof(cl_mem), &out_cl);
  assert(err == 0);

  const size_t loadys_work_size = (s->width*s->height)/8;
  err = clEnqueueNDRangeKernel(q, s->loadys_krnl, 1, NULL,
                               &loadys_work_size, NULL, 0, 0, NULL);
  assert(err == 0);

  const size_t loaduv_work_size = ((s->width/2)*(s->height/2))/8;
  cl_int loaduv_out_off = (s->width*s->height);

  err = clSetKernelArg(s->loaduv_krnl, 0, sizeof(cl_mem), &u_cl);
  assert(err == 0);
  err = clSetKernelArg(s->loaduv_krnl, 1, sizeof(cl_mem), &out_cl);
  assert(err == 0);
  err = clSetKernelArg(s->loaduv_krnl, 2, sizeof(cl_int), &loaduv_out_off);
  assert(err == 0);

  err = clEnqueueNDRangeKernel(q, s->loaduv_krnl, 1, NULL,
                               &loaduv_work_size, NULL, 0, 0, NULL);
  assert(err == 0);

  loaduv_out_off += (s->width/2)*(s->height/2);

  err = clSetKernelArg(s->loaduv_krnl, 0, sizeof(cl_mem), &v_cl);
  assert(err == 0);
  err = clSetKernelArg(s->loaduv_krnl, 1, sizeof(cl_mem), &out_cl);
  assert(err == 0);
  err = clSetKernelArg(s->loaduv_krnl, 2, sizeof(cl_int), &loaduv_out_off);
  assert(err == 0);

  err = clEnqueueNDRangeKernel(q, s->loaduv_krnl, 1, NULL,
                               &loaduv_work_size, NULL, 0, 0, NULL);
  assert(err == 0);
}

