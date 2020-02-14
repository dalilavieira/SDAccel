#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_28__   TYPE_9__ ;
typedef  struct TYPE_27__   TYPE_8__ ;
typedef  struct TYPE_26__   TYPE_7__ ;
typedef  struct TYPE_25__   TYPE_6__ ;
typedef  struct TYPE_24__   TYPE_5__ ;
typedef  struct TYPE_23__   TYPE_4__ ;
typedef  struct TYPE_22__   TYPE_3__ ;
typedef  struct TYPE_21__   TYPE_2__ ;
typedef  struct TYPE_20__   TYPE_1__ ;
typedef  struct TYPE_19__   TYPE_12__ ;
typedef  struct TYPE_18__   TYPE_11__ ;
typedef  struct TYPE_17__   TYPE_10__ ;

/* Type definitions */
struct TYPE_28__ {char* member_0; int /*<<< orphan*/  member_2; int /*<<< orphan*/  member_1; } ;
typedef  TYPE_9__ VRLayerInit ;
struct TYPE_25__ {double x; double y; double z; } ;
struct TYPE_24__ {double x; double y; double z; } ;
struct TYPE_23__ {double x; double y; double z; double w; } ;
struct TYPE_22__ {double x; double y; double z; } ;
struct TYPE_21__ {double x; double y; double z; } ;
struct TYPE_20__ {double x; double y; double z; } ;
struct TYPE_26__ {int poseFlags; TYPE_6__ angularAcceleration; TYPE_5__ angularVelocity; TYPE_4__ orientation; TYPE_3__ linearAcceleration; TYPE_2__ linearVelocity; TYPE_1__ position; } ;
struct TYPE_17__ {float* leftProjectionMatrix; float* rightProjectionMatrix; float* leftViewMatrix; float* rightViewMatrix; TYPE_7__ pose; } ;
typedef  TYPE_10__ VRFrameData ;
struct TYPE_27__ {double x; double y; double z; } ;
struct TYPE_18__ {TYPE_8__ offset; int /*<<< orphan*/  renderHeight; int /*<<< orphan*/  renderWidth; } ;
typedef  TYPE_11__ VREyeParameters ;
typedef  int VRDisplayHandle ;
struct TYPE_19__ {int hasPosition; int hasExternalDisplay; int canPresent; int /*<<< orphan*/  maxLayers; } ;
typedef  TYPE_12__ VRDisplayCapabilities ;

/* Variables and functions */
 int /*<<< orphan*/  VREyeLeft ; 
 int /*<<< orphan*/  VREyeRight ; 
 int /*<<< orphan*/  VR_LAYER_DEFAULT_LEFT_BOUNDS ; 
 int /*<<< orphan*/  VR_LAYER_DEFAULT_RIGHT_BOUNDS ; 
 int VR_POSE_ANGULAR_ACCELERATION ; 
 int VR_POSE_ANGULAR_VELOCITY ; 
 int VR_POSE_LINEAR_ACCELERATION ; 
 int VR_POSE_LINEAR_VELOCITY ; 
 int VR_POSE_ORIENTATION ; 
 int VR_POSE_POSITION ; 
 int /*<<< orphan*/  emscripten_cancel_main_loop () ; 
 int /*<<< orphan*/  emscripten_set_main_loop (void (*) (),int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  emscripten_vr_cancel_display_render_loop (int) ; 
 int emscripten_vr_count_displays () ; 
 int /*<<< orphan*/  emscripten_vr_display_connected (int) ; 
 scalar_t__ emscripten_vr_display_presenting (int) ; 
 int /*<<< orphan*/  emscripten_vr_exit_present (int) ; 
 int /*<<< orphan*/  emscripten_vr_get_display_capabilities (int,TYPE_12__*) ; 
 int emscripten_vr_get_display_handle (int) ; 
 char* emscripten_vr_get_display_name (int) ; 
 int /*<<< orphan*/  emscripten_vr_get_eye_parameters (int,int /*<<< orphan*/ ,TYPE_11__*) ; 
 int /*<<< orphan*/  emscripten_vr_get_frame_data (int,TYPE_10__*) ; 
 int /*<<< orphan*/  emscripten_vr_init () ; 
 int /*<<< orphan*/  emscripten_vr_ready () ; 
 int /*<<< orphan*/  emscripten_vr_request_present (int,TYPE_9__*,int,void (*) (void*),int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  emscripten_vr_set_display_render_loop (int,void (*) ()) ; 
 int /*<<< orphan*/  emscripten_vr_set_display_render_loop_arg (int,void (*) (void*),void*) ; 
 int /*<<< orphan*/  emscripten_vr_submit_frame (int) ; 
 int emscripten_vr_version_major () ; 
 int emscripten_vr_version_minor () ; 
 int gDisplay ; 
 int /*<<< orphan*/  printf (char*,...) ; 
 void* renderLoopArgArg ; 
 int renderLoopArgCalled ; 
 int renderLoopCalled ; 

void report_result(int result) {
    emscripten_cancel_main_loop();
    if (result == 0) {
        printf("Test successful!\n");
    } else {
        printf("Test failed!\n");
    }
#ifdef REPORT_RESULT
    REPORT_RESULT(result);
#endif
}

__attribute__((used)) static void printMatrix(float* m) {
    printf("{%f, %f, %f, %f,\n"
           " %f, %f, %f, %f,\n"
           " %f, %f, %f, %f,\n"
           " %f, %f, %f, %f}\n",
           m[0],  m[1],  m[2],  m[3],
           m[4],  m[5],  m[6],  m[7],
           m[8],  m[9],  m[10], m[11],
           m[12], m[13], m[14], m[15]);
}

__attribute__((used)) static void renderLoopArg(void* arg) {
    emscripten_vr_cancel_display_render_loop(gDisplay);

    renderLoopArgCalled = true;
    renderLoopArgArg = arg;

    emscripten_vr_exit_present(gDisplay);

    printf("Render loop with argument was called.\n");

    return;
}

__attribute__((used)) static void requestPresentCallback(void* userData) {
    // Will likely never happen as the callback is not called
    // from a user-gesture in this test.
    printf("Request present callback called.\n");
}

__attribute__((used)) static void renderLoop() {
    renderLoopCalled++;
    if(renderLoopCalled == 1) {
        /* First iteration */
        VRLayerInit init = {
            "#canvas",
            VR_LAYER_DEFAULT_LEFT_BOUNDS,
            VR_LAYER_DEFAULT_RIGHT_BOUNDS
        };
        if (!emscripten_vr_request_present(gDisplay, &init, 1, requestPresentCallback, NULL)) {
            printf("Request present with default canvas failed.\n");
            report_result(1);
            return;
        }

        if(emscripten_vr_display_presenting(gDisplay)) {
            /* request present needs to be called from a user gesture callback and
             * should have failed to make the display present. */
            printf("Error: Expected display not to be presenting.\n");
            report_result(1);
            return;
        }

        VRFrameData data;
        if (!emscripten_vr_get_frame_data(gDisplay, &data)) {
            printf("Could not get frame data. (first iteration)\n");
            report_result(1);
            return;
        }
        if(!emscripten_vr_submit_frame(gDisplay)) {
            printf("Error: Failed to submit frame to VR display %d (first iteration)\n", gDisplay);
            report_result(1);
            return;
        }
        return;
    } else if (renderLoopCalled > 2) {
        printf("Error: Unexpected render loop iteration\n");
        report_result(1);
        return; // only two iterations should run code
    }

    /* Second iteration */

    emscripten_vr_cancel_display_render_loop(gDisplay);

    VRFrameData data;
    if (!emscripten_vr_get_frame_data(gDisplay, &data)) {
        printf("Could not get frame data.\n");
        report_result(1);
    }

    /* Print list of properties which are reported as valid */
    printf("The following properties are valid:\n[");
    if(data.pose.poseFlags & VR_POSE_POSITION) {
        printf("position, ");
    }
    if(data.pose.poseFlags & VR_POSE_LINEAR_VELOCITY) {
        printf("linear vel, ");
    }
    if(data.pose.poseFlags & VR_POSE_LINEAR_ACCELERATION) {
        printf("linear accel, ");
    }
    if(data.pose.poseFlags & VR_POSE_ORIENTATION) {
        printf("orientation, ");
    }
    if(data.pose.poseFlags & VR_POSE_ANGULAR_VELOCITY) {
        printf("angular vel, ");
    }
    if(data.pose.poseFlags & VR_POSE_ANGULAR_ACCELERATION) {
        printf("angular accel");
    }
    printf("]\n");

    /* Print all values (independent of validity) */
    printf("Position: \t\t%f %f %f\n",
            data.pose.position.x,
            data.pose.position.y,
            data.pose.position.z);

    printf("Linear Velocity: \t%f %f %f\n",
            data.pose.linearVelocity.x,
            data.pose.linearVelocity.y,
            data.pose.linearVelocity.z);

    printf("Linear Acceleration: \t%f %f %f\n",
            data.pose.linearAcceleration.x,
            data.pose.linearAcceleration.y,
            data.pose.linearAcceleration.z);

    printf("Orientation: \t\t%f %f %f %f\n",
            data.pose.orientation.x,
            data.pose.orientation.y,
            data.pose.orientation.z,
            data.pose.orientation.w);

    printf("Angular Velocity: \t%f %f %f\n",
            data.pose.angularVelocity.x,
            data.pose.angularVelocity.y,
            data.pose.angularVelocity.z);

    printf("Angular Acceleration: \t%f %f %f\n",
            data.pose.angularAcceleration.x,
            data.pose.angularAcceleration.y,
            data.pose.angularAcceleration.z);

    printf("Left Projection Matrix:\n");
    printMatrix(data.leftProjectionMatrix);

    printf("Right Projection Matrix:\n");
    printMatrix(data.rightProjectionMatrix);

    printf("Left View Matrix:\n");
    printMatrix(data.leftViewMatrix);

    printf("Right View Matrix:\n");
    printMatrix(data.rightViewMatrix);

    if(!emscripten_vr_submit_frame(gDisplay)) {
        printf("Error: Failed to submit frame to VR display %d (second iteration)\n", gDisplay);
        report_result(1);
    }

    printf("Submitted frame.\n");

    if (!emscripten_vr_set_display_render_loop_arg(gDisplay, renderLoopArg, (void*) 42)) {
        printf("Error: Failed to dereference handle while settings display render loop of device %d\n", gDisplay);
        report_result(1);
    }

    printf("Set main loop with argument to be called next.\n");
}

__attribute__((used)) static void mainloop() {
    static int loopcount = 0;

    if (!emscripten_vr_ready()) {
        printf("VR not ready\n");
        return;
    }

    if(gDisplay == -1) {
        int numDisplays = emscripten_vr_count_displays();
        if (numDisplays == 0) {
            printf("No VR displays found!\n");
            report_result(0);
            return;
        }

        printf("%d VR displays found\n", numDisplays);

        int id = -1;
        char *devName;
        for (int i = 0; i < numDisplays; ++i) {
            VRDisplayHandle handle = emscripten_vr_get_display_handle(i);
            if (gDisplay == -1) {
                /* Save first found display for more testing */
                gDisplay = handle;
                devName = emscripten_vr_get_display_name(handle);
                printf("Using VRDisplay '%s' (displayId '%d')\n", devName, gDisplay);

                VRDisplayCapabilities caps;
                if(!emscripten_vr_get_display_capabilities(handle, &caps)) {
                    printf("Error: failed to get display capabilities.\n");
                    report_result(1);
                    return;
                }
                if(!emscripten_vr_display_connected(gDisplay)) {
                    printf("Error: expected display to be connected.\n");
                    report_result(1);
                    return;
                }
                printf("Display Capabilities:\n"
                       "{hasPosition: %d, hasExternalDisplay: %d, canPresent: %d, maxLayers: %lu}\n",
                       caps.hasPosition, caps.hasExternalDisplay, caps.canPresent, caps.maxLayers);
            }
        }

        if (gDisplay == -1) {
            printf("Couln't find a VR display even though at least one was found.\n");
            report_result(1);
            return;
        }

        VREyeParameters leftParams, rightParams;
        emscripten_vr_get_eye_parameters(gDisplay, VREyeLeft, &leftParams);
        emscripten_vr_get_eye_parameters(gDisplay, VREyeRight, &rightParams);

        VREyeParameters* p = &leftParams;
        printf("Left eye params: {offset: [%f, %f, %f], renderWidth: %lu, renderHeight: %lu}\n", p->offset.x, p->offset.y, p->offset.z, p->renderWidth, p->renderHeight);

        p = &rightParams;
        printf("Right eye params: {offset: [%f, %f, %f], renderWidth: %lu, renderHeight: %lu}\n", p->offset.x, p->offset.y, p->offset.z, p->renderWidth, p->renderHeight);

        if (!emscripten_vr_set_display_render_loop(gDisplay, renderLoop)) {
            printf("Error: Failed to dereference handle while settings display render loop of device %d\n", gDisplay);
            report_result(1);
        }
    }

    if (loopcount++ > 10) {
        if (renderLoopCalled != 2) {
            printf("Render loop was not called twice (expected 2, was %d)\n", renderLoopCalled);
            report_result(1);
        }
        if (!renderLoopArgCalled) {
            printf("Render loop with argument was never called\n");
            report_result(1);
        }
        if ((int)renderLoopArgArg != 42) {
            printf("Argument to emscripten_vr_set_display_render_loop_arg was not passed on correctly\n");
            report_result(1);
        }
        report_result(0);
    }
}

int main(int argc, char **argv) {
    if (!emscripten_vr_init()) {
        printf("Skipping: Browser does not support WebVR\n");
        return 0;
    }

    printf("Browser is running WebVR version %d.%d\n",
           emscripten_vr_version_major(),
           emscripten_vr_version_minor());

    /* 2fps -- no rAF */
    emscripten_set_main_loop(mainloop, 2, 0);
}

