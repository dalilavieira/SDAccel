#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_10__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  tvi_handle_t ;
typedef  int /*<<< orphan*/  tv_param_t ;
struct mp_log {int dummy; } ;
struct TYPE_10__ {int width; int height; } ;
typedef  TYPE_1__ priv_t ;

/* Variables and functions */
#define  MP_FOURCC_I420 143 
#define  MP_FOURCC_JPEG 142 
#define  MP_FOURCC_MJPEG 141 
#define  MP_FOURCC_UYVY 140 
#define  MP_FOURCC_YUY2 139 
#define  MP_FOURCC_YV12 138 
 double MP_NOPTS_VALUE ; 
 int TVI_CONTROL_FALSE ; 
#define  TVI_CONTROL_IS_VIDEO 137 
 int TVI_CONTROL_TRUE ; 
#define  TVI_CONTROL_TUN_SET_NORM 136 
 int TVI_CONTROL_UNKNOWN ; 
#define  TVI_CONTROL_VID_CHK_HEIGHT 135 
#define  TVI_CONTROL_VID_CHK_WIDTH 134 
#define  TVI_CONTROL_VID_GET_FORMAT 133 
#define  TVI_CONTROL_VID_GET_HEIGHT 132 
#define  TVI_CONTROL_VID_GET_WIDTH 131 
#define  TVI_CONTROL_VID_SET_FORMAT 130 
#define  TVI_CONTROL_VID_SET_HEIGHT 129 
#define  TVI_CONTROL_VID_SET_WIDTH 128 
 int /*<<< orphan*/  functions ; 
 int /*<<< orphan*/  memset (char*,int,int) ; 
 int /*<<< orphan*/ * tv_new_handle (int,struct mp_log*,int /*<<< orphan*/ *) ; 

__attribute__((used)) static inline void fill_blank_frame(char* buffer,int len,int fmt){
    int i;
    // RGB(0,0,255) <-> YVU(41,110,240)

    switch(fmt){
    case MP_FOURCC_YV12:
        memset(buffer, 41,4*len/6);       //Y
        memset(buffer+4*len/6, 110,len/6);//V
        memset(buffer+5*len/6, 240,len/6);//U
        break;
    case MP_FOURCC_I420:
        memset(buffer, 41,4*len/6);       //Y
        memset(buffer+4*len/6, 240,len/6);//U
        memset(buffer+5*len/6, 110,len/6);//V
        break;
    case MP_FOURCC_UYVY:
        for(i=0;i<len;i+=4){
            buffer[i]=0xFF;
            buffer[i+1]=0;
            buffer[i+2]=0;
            buffer[i+3]=0;
        }
        break;
    case MP_FOURCC_YUY2:
        for(i=0;i<len;i+=4){
            buffer[i]=0;
            buffer[i+1]=0xFF;
            buffer[i+2]=0;
            buffer[i+3]=0;
        }
        break;
    case MP_FOURCC_MJPEG:
    case MP_FOURCC_JPEG:
        /*
        This is compressed format. I don't know yet how to fill such frame with blue color.
        Keeping frame unchanged.
        */
        break;
    default:
        memset(buffer,0xC0,len);
    }
}

__attribute__((used)) static tvi_handle_t *tvi_init_dummy(struct mp_log *log, tv_param_t* tv_param)
{
    return tv_new_handle(sizeof(priv_t), log, &functions);
}

__attribute__((used)) static int init(priv_t *priv)
{
    priv->width = 320;
    priv->height = 200;
    return 1;
}

__attribute__((used)) static int start(priv_t *priv)
{
    return 1;
}

__attribute__((used)) static int uninit(priv_t *priv)
{
    return 1;
}

__attribute__((used)) static int do_control(priv_t *priv, int cmd, void *arg)
{
    switch(cmd)
    {
        case TVI_CONTROL_IS_VIDEO:
            return TVI_CONTROL_TRUE;
        case TVI_CONTROL_VID_GET_FORMAT:
            *(int *)arg = MP_FOURCC_YV12;
            return TVI_CONTROL_TRUE;
        case TVI_CONTROL_VID_SET_FORMAT:
        {
//          int req_fmt = *(int *)arg;
            int req_fmt = *(int *)arg;
            if (req_fmt != MP_FOURCC_YV12)
                return TVI_CONTROL_FALSE;
            return TVI_CONTROL_TRUE;
        }
        case TVI_CONTROL_VID_SET_WIDTH:
            priv->width = *(int *)arg;
            return TVI_CONTROL_TRUE;
        case TVI_CONTROL_VID_GET_WIDTH:
            *(int *)arg = priv->width;
            return TVI_CONTROL_TRUE;
        case TVI_CONTROL_VID_SET_HEIGHT:
            priv->height = *(int *)arg;
            return TVI_CONTROL_TRUE;
        case TVI_CONTROL_VID_GET_HEIGHT:
            *(int *)arg = priv->height;
            return TVI_CONTROL_TRUE;
        case TVI_CONTROL_VID_CHK_WIDTH:
        case TVI_CONTROL_VID_CHK_HEIGHT:
            return TVI_CONTROL_TRUE;
        case TVI_CONTROL_TUN_SET_NORM:
            return TVI_CONTROL_TRUE;
    }
    return TVI_CONTROL_UNKNOWN;
}

__attribute__((used)) static double grab_video_frame(priv_t *priv, char *buffer, int len)
{
    memset(buffer, 0x42, len);
    return MP_NOPTS_VALUE;
}

__attribute__((used)) static int get_video_framesize(priv_t *priv)
{
    /* YV12 */
    return priv->width * priv->height * 12 / 8;
}

__attribute__((used)) static double grab_audio_frame(priv_t *priv, char *buffer, int len)
{
    memset(buffer, 0x42, len);
    return MP_NOPTS_VALUE;
}

__attribute__((used)) static int get_audio_framesize(priv_t *priv)
{
    return 1;
}

