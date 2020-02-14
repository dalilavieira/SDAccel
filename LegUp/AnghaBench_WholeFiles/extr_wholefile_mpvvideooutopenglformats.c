#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
struct gl_format {scalar_t__ type; int format; } ;
struct TYPE_3__ {int version; int es; int mpgl_caps; } ;
typedef  int GLenum ;
typedef  TYPE_1__ GL ;

/* Variables and functions */
 int F_APPL ; 
 int F_ES2 ; 
 int F_ES3 ; 
 int F_ES32 ; 
 int F_EXT16 ; 
 int F_EXTF16 ; 
 int F_GL2 ; 
 int F_GL2F ; 
 int F_GL3 ; 
#define  GL_FLOAT 144 
#define  GL_LUMINANCE 143 
#define  GL_LUMINANCE_ALPHA 142 
#define  GL_RED 141 
#define  GL_RED_INTEGER 140 
#define  GL_RG 139 
#define  GL_RGB 138 
#define  GL_RGBA 137 
#define  GL_RGBA_INTEGER 136 
#define  GL_RGB_INTEGER 135 
#define  GL_RG_INTEGER 134 
#define  GL_UNSIGNED_BYTE 133 
#define  GL_UNSIGNED_INT_2_10_10_10_REV 132 
#define  GL_UNSIGNED_SHORT 131 
#define  GL_UNSIGNED_SHORT_5_6_5 130 
#define  GL_UNSIGNED_SHORT_8_8_APPLE 129 
#define  GL_UNSIGNED_SHORT_8_8_REV_APPLE 128 
 int MPGL_CAP_APPLE_RGB_422 ; 
 int MPGL_CAP_ARB_FLOAT ; 
 int MPGL_CAP_EXT16 ; 
 int MPGL_CAP_EXT_CR_HFLOAT ; 
 int MPGL_CAP_FB ; 
 int MPGL_CAP_TEX_RG ; 
 int MPGL_TYPE_FLOAT ; 
 int MPGL_TYPE_UINT ; 
 int MPGL_TYPE_UNORM ; 
 int gl_integer_format_to_base (int) ; 

int gl_format_feature_flags(GL *gl)
{
    return (gl->version == 210 ? F_GL2 : 0)
         | (gl->version >= 300 ? F_GL3 : 0)
         | (gl->es == 200 ? F_ES2 : 0)
         | (gl->es >= 300 ? F_ES3 : 0)
         | (gl->es >= 320 ? F_ES32 : 0)
         | (gl->mpgl_caps & MPGL_CAP_EXT16 ? F_EXT16 : 0)
         | ((gl->es >= 300 &&
            (gl->mpgl_caps & MPGL_CAP_EXT_CR_HFLOAT)) ? F_EXTF16 : 0)
         | ((gl->version == 210 &&
            (gl->mpgl_caps & MPGL_CAP_ARB_FLOAT) &&
            (gl->mpgl_caps & MPGL_CAP_TEX_RG) &&
            (gl->mpgl_caps & MPGL_CAP_FB)) ? F_GL2F : 0)
         | (gl->mpgl_caps & MPGL_CAP_APPLE_RGB_422 ? F_APPL : 0);
}

int gl_format_type(const struct gl_format *format)
{
    if (!format)
        return 0;
    if (format->type == GL_FLOAT)
        return MPGL_TYPE_FLOAT;
    if (gl_integer_format_to_base(format->format))
        return MPGL_TYPE_UINT;
    return MPGL_TYPE_UNORM;
}

GLenum gl_integer_format_to_base(GLenum format)
{
    switch (format) {
    case GL_RED_INTEGER:        return GL_RED;
    case GL_RG_INTEGER:         return GL_RG;
    case GL_RGB_INTEGER:        return GL_RGB;
    case GL_RGBA_INTEGER:       return GL_RGBA;
    }
    return 0;
}

int gl_component_size(GLenum type)
{
    switch (type) {
    case GL_UNSIGNED_BYTE:                      return 1;
    case GL_UNSIGNED_SHORT:                     return 2;
    case GL_FLOAT:                              return 4;
    }
    return 0;
}

int gl_format_components(GLenum format)
{
    switch (format) {
    case GL_RED:
    case GL_RED_INTEGER:
    case GL_LUMINANCE:
        return 1;
    case GL_RG:
    case GL_RG_INTEGER:
    case GL_LUMINANCE_ALPHA:
        return 2;
    case GL_RGB:
    case GL_RGB_INTEGER:
        return 3;
    case GL_RGBA:
    case GL_RGBA_INTEGER:
        return 4;
    }
    return 0;
}

int gl_bytes_per_pixel(GLenum format, GLenum type)
{
    // Formats with merged components are special.
    switch (type) {
    case GL_UNSIGNED_INT_2_10_10_10_REV:        return 4;
    case GL_UNSIGNED_SHORT_5_6_5:               return 2;
    case GL_UNSIGNED_SHORT_8_8_APPLE:           return 2;
    case GL_UNSIGNED_SHORT_8_8_REV_APPLE:       return 2;
    }

    return gl_component_size(type) * gl_format_components(format);
}

