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
typedef  int /*<<< orphan*/  uint8_t ;
typedef  scalar_t__ uint32_t ;
struct gs_texture {scalar_t__ gl_target; int /*<<< orphan*/  texture; } ;
struct gs_device {scalar_t__ copy_type; } ;
struct fbo_info {int /*<<< orphan*/  fbo; int /*<<< orphan*/  ref; } ;
typedef  struct fbo_info gs_samplerstate_t ;
typedef  enum gs_zstencil_format { ____Placeholder_gs_zstencil_format } gs_zstencil_format ;
typedef  enum gs_stencil_side { ____Placeholder_gs_stencil_side } gs_stencil_side ;
typedef  enum gs_stencil_op_type { ____Placeholder_gs_stencil_op_type } gs_stencil_op_type ;
typedef  enum gs_shader_type { ____Placeholder_gs_shader_type } gs_shader_type ;
typedef  enum gs_sample_filter { ____Placeholder_gs_sample_filter } gs_sample_filter ;
typedef  enum gs_draw_mode { ____Placeholder_gs_draw_mode } gs_draw_mode ;
typedef  enum gs_depth_test { ____Placeholder_gs_depth_test } gs_depth_test ;
typedef  enum gs_color_format { ____Placeholder_gs_color_format } gs_color_format ;
typedef  enum gs_blend_type { ____Placeholder_gs_blend_type } gs_blend_type ;
typedef  enum gs_address_mode { ____Placeholder_gs_address_mode } gs_address_mode ;
typedef  int /*<<< orphan*/  GLvoid ;
typedef  int /*<<< orphan*/  GLuint ;
typedef  int /*<<< orphan*/  GLsizeiptr ;
typedef  int GLsizei ;
typedef  int /*<<< orphan*/  GLint ;
typedef  int /*<<< orphan*/  GLfloat ;
typedef  scalar_t__ GLenum ;

/* Variables and functions */
 scalar_t__ COPY_TYPE_ARB ; 
 scalar_t__ COPY_TYPE_FBO_BLIT ; 
 scalar_t__ COPY_TYPE_NV ; 
 scalar_t__ GL_ALWAYS ; 
 scalar_t__ GL_BACK ; 
 scalar_t__ GL_BGRA ; 
 int /*<<< orphan*/  GL_CLAMP_TO_BORDER ; 
 int /*<<< orphan*/  GL_CLAMP_TO_EDGE ; 
 scalar_t__ GL_COLOR_ATTACHMENT0 ; 
 scalar_t__ GL_COMPRESSED_RGBA_S3TC_DXT1_EXT ; 
 scalar_t__ GL_COMPRESSED_RGBA_S3TC_DXT3_EXT ; 
 scalar_t__ GL_COMPRESSED_RGBA_S3TC_DXT5_EXT ; 
 scalar_t__ GL_DECR ; 
 scalar_t__ GL_DEPTH24_STENCIL8 ; 
 scalar_t__ GL_DEPTH32F_STENCIL8 ; 
 scalar_t__ GL_DEPTH_COMPONENT16 ; 
 scalar_t__ GL_DEPTH_COMPONENT32F ; 
 scalar_t__ GL_DST_ALPHA ; 
 scalar_t__ GL_DST_COLOR ; 
 scalar_t__ GL_EQUAL ; 
 scalar_t__ GL_FLOAT ; 
 scalar_t__ GL_FRAGMENT_SHADER ; 
 scalar_t__ GL_FRONT ; 
 scalar_t__ GL_FRONT_AND_BACK ; 
 scalar_t__ GL_GEQUAL ; 
 scalar_t__ GL_GREATER ; 
 scalar_t__ GL_INCR ; 
 scalar_t__ GL_INVERT ; 
 scalar_t__ GL_KEEP ; 
 scalar_t__ GL_LEQUAL ; 
 scalar_t__ GL_LESS ; 
 int /*<<< orphan*/  GL_LINEAR ; 
 int /*<<< orphan*/  GL_LINEAR_MIPMAP_LINEAR ; 
 int /*<<< orphan*/  GL_LINEAR_MIPMAP_NEAREST ; 
 scalar_t__ GL_LINES ; 
 scalar_t__ GL_LINE_STRIP ; 
 int GL_MAP_INVALIDATE_BUFFER_BIT ; 
 int GL_MAP_WRITE_BIT ; 
 int /*<<< orphan*/  GL_MIRRORED_REPEAT ; 
 int /*<<< orphan*/  GL_MIRROR_CLAMP_EXT ; 
 int /*<<< orphan*/  GL_NEAREST ; 
 int /*<<< orphan*/  GL_NEAREST_MIPMAP_LINEAR ; 
 int /*<<< orphan*/  GL_NEAREST_MIPMAP_NEAREST ; 
 scalar_t__ GL_NEVER ; 
 scalar_t__ GL_NOTEQUAL ; 
 scalar_t__ GL_NO_ERROR ; 
 scalar_t__ GL_ONE ; 
 scalar_t__ GL_ONE_MINUS_DST_ALPHA ; 
 scalar_t__ GL_ONE_MINUS_DST_COLOR ; 
 scalar_t__ GL_ONE_MINUS_SRC_ALPHA ; 
 scalar_t__ GL_ONE_MINUS_SRC_COLOR ; 
 scalar_t__ GL_POINTS ; 
 scalar_t__ GL_R16 ; 
 scalar_t__ GL_R16F ; 
 scalar_t__ GL_R32F ; 
 scalar_t__ GL_R8 ; 
 scalar_t__ GL_READ_FRAMEBUFFER ; 
 scalar_t__ GL_READ_FRAMEBUFFER_BINDING ; 
 scalar_t__ GL_RED ; 
 int /*<<< orphan*/  GL_REPEAT ; 
 scalar_t__ GL_REPLACE ; 
 scalar_t__ GL_RG ; 
 scalar_t__ GL_RG16F ; 
 scalar_t__ GL_RG32F ; 
 scalar_t__ GL_RGB ; 
 scalar_t__ GL_RGB10_A2 ; 
 scalar_t__ GL_RGBA ; 
 scalar_t__ GL_RGBA16 ; 
 scalar_t__ GL_RGBA16F ; 
 scalar_t__ GL_RGBA32F ; 
 scalar_t__ GL_SRC_ALPHA ; 
 scalar_t__ GL_SRC_ALPHA_SATURATE ; 
 scalar_t__ GL_SRC_COLOR ; 
 scalar_t__ GL_TRIANGLES ; 
 scalar_t__ GL_TRIANGLE_STRIP ; 
 scalar_t__ GL_UNSIGNED_BYTE ; 
 scalar_t__ GL_UNSIGNED_INT_10_10_10_2 ; 
 scalar_t__ GL_UNSIGNED_SHORT ; 
 scalar_t__ GL_VERTEX_SHADER ; 
 scalar_t__ GL_ZERO ; 
#define  GS_A8 200 
#define  GS_ADDRESS_BORDER 199 
#define  GS_ADDRESS_CLAMP 198 
#define  GS_ADDRESS_MIRROR 197 
#define  GS_ADDRESS_MIRRORONCE 196 
#define  GS_ADDRESS_WRAP 195 
#define  GS_ALWAYS 194 
#define  GS_BGRA 193 
#define  GS_BGRX 192 
#define  GS_BLEND_DSTALPHA 191 
#define  GS_BLEND_DSTCOLOR 190 
#define  GS_BLEND_INVDSTALPHA 189 
#define  GS_BLEND_INVDSTCOLOR 188 
#define  GS_BLEND_INVSRCALPHA 187 
#define  GS_BLEND_INVSRCCOLOR 186 
#define  GS_BLEND_ONE 185 
#define  GS_BLEND_SRCALPHA 184 
#define  GS_BLEND_SRCALPHASAT 183 
#define  GS_BLEND_SRCCOLOR 182 
#define  GS_BLEND_ZERO 181 
#define  GS_DECR 180 
#define  GS_DXT1 179 
#define  GS_DXT3 178 
#define  GS_DXT5 177 
#define  GS_EQUAL 176 
#define  GS_FILTER_ANISOTROPIC 175 
#define  GS_FILTER_LINEAR 174 
#define  GS_FILTER_MIN_LINEAR_MAG_MIP_POINT 173 
#define  GS_FILTER_MIN_LINEAR_MAG_POINT_MIP_LINEAR 172 
#define  GS_FILTER_MIN_MAG_LINEAR_MIP_POINT 171 
#define  GS_FILTER_MIN_MAG_POINT_MIP_LINEAR 170 
#define  GS_FILTER_MIN_POINT_MAG_LINEAR_MIP_POINT 169 
#define  GS_FILTER_MIN_POINT_MAG_MIP_LINEAR 168 
#define  GS_FILTER_POINT 167 
#define  GS_GEQUAL 166 
#define  GS_GREATER 165 
#define  GS_INCR 164 
#define  GS_INVERT 163 
#define  GS_KEEP 162 
#define  GS_LEQUAL 161 
#define  GS_LESS 160 
#define  GS_LINES 159 
#define  GS_LINESTRIP 158 
#define  GS_NEVER 157 
#define  GS_NOTEQUAL 156 
#define  GS_POINTS 155 
#define  GS_R10G10B10A2 154 
#define  GS_R16 153 
#define  GS_R16F 152 
#define  GS_R32F 151 
#define  GS_R8 150 
#define  GS_R8G8 149 
#define  GS_REPLACE 148 
#define  GS_RG16F 147 
#define  GS_RG32F 146 
#define  GS_RGBA 145 
#define  GS_RGBA16 144 
#define  GS_RGBA16F 143 
#define  GS_RGBA32F 142 
#define  GS_SHADER_PIXEL 141 
#define  GS_SHADER_VERTEX 140 
#define  GS_STENCIL_BACK 139 
#define  GS_STENCIL_BOTH 138 
#define  GS_STENCIL_FRONT 137 
#define  GS_TRIS 136 
#define  GS_TRISTRIP 135 
#define  GS_UNKNOWN 134 
#define  GS_Z16 133 
#define  GS_Z24_S8 132 
#define  GS_Z32F 131 
#define  GS_Z32F_S8X24 130 
#define  GS_ZERO 129 
#define  GS_ZS_NONE 128 
 int /*<<< orphan*/  LOG_ERROR ; 
 int /*<<< orphan*/  bfree (struct fbo_info*) ; 
 int /*<<< orphan*/  blog (int /*<<< orphan*/ ,char*,...) ; 
 struct fbo_info* get_fbo (struct gs_texture*,scalar_t__,scalar_t__) ; 
 int /*<<< orphan*/  glActiveTexture (scalar_t__) ; 
 int /*<<< orphan*/  glBindBuffer (scalar_t__,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  glBindFramebuffer (scalar_t__,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  glBindRenderbuffer (scalar_t__,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  glBindTexture (scalar_t__,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  glBindVertexArray (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  glBufferData (scalar_t__,int /*<<< orphan*/ ,int /*<<< orphan*/  const*,scalar_t__) ; 
 int /*<<< orphan*/  glCompressedTexImage2D (scalar_t__,scalar_t__,int /*<<< orphan*/ ,scalar_t__,scalar_t__,int /*<<< orphan*/ ,scalar_t__,int /*<<< orphan*/  const*) ; 
 int /*<<< orphan*/  glCopyImageSubData (int /*<<< orphan*/ ,scalar_t__,int /*<<< orphan*/ ,scalar_t__,scalar_t__,int /*<<< orphan*/ ,int /*<<< orphan*/ ,scalar_t__,int /*<<< orphan*/ ,scalar_t__,scalar_t__,int /*<<< orphan*/ ,scalar_t__,scalar_t__,int) ; 
 int /*<<< orphan*/  glCopyImageSubDataNV (int /*<<< orphan*/ ,scalar_t__,int /*<<< orphan*/ ,scalar_t__,scalar_t__,int /*<<< orphan*/ ,int /*<<< orphan*/ ,scalar_t__,int /*<<< orphan*/ ,scalar_t__,scalar_t__,int /*<<< orphan*/ ,scalar_t__,scalar_t__,int) ; 
 int /*<<< orphan*/  glCopyTexSubImage2D (scalar_t__,int /*<<< orphan*/ ,scalar_t__,scalar_t__,scalar_t__,scalar_t__,scalar_t__,scalar_t__) ; 
 int /*<<< orphan*/  glCullFace (scalar_t__) ; 
 int /*<<< orphan*/  glDeleteBuffers (int,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  glDeleteFramebuffers (int,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  glDeleteTextures (int,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  glDeleteVertexArrays (int,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  glDisable (scalar_t__) ; 
 int /*<<< orphan*/  glEnable (scalar_t__) ; 
 int /*<<< orphan*/  glFramebufferTexture2D (scalar_t__,scalar_t__,scalar_t__,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  glGenBuffers (int,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  glGenTextures (int,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  glGenVertexArrays (int,int /*<<< orphan*/ *) ; 
 scalar_t__ glGetError () ; 
 int /*<<< orphan*/  glGetIntegerv (scalar_t__,int /*<<< orphan*/ *) ; 
 void* glMapBufferRange (scalar_t__,int /*<<< orphan*/ ,size_t,int) ; 
 int /*<<< orphan*/  glReadBuffer (scalar_t__) ; 
 int /*<<< orphan*/  glTexImage2D (scalar_t__,scalar_t__,int /*<<< orphan*/ ,scalar_t__,scalar_t__,int /*<<< orphan*/ ,scalar_t__,scalar_t__,int /*<<< orphan*/  const*) ; 
 int /*<<< orphan*/  glTexParameterf (scalar_t__,scalar_t__,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  glTexParameteri (scalar_t__,scalar_t__,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  glUnmapBuffer (scalar_t__) ; 
 int /*<<< orphan*/  memcpy (void*,void const*,size_t) ; 
 scalar_t__ os_atomic_dec_long (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  os_atomic_inc_long (int /*<<< orphan*/ *) ; 

__attribute__((used)) static inline bool gl_success(const char *funcname)
{
	GLenum errorcode = glGetError();
	if (errorcode != GL_NO_ERROR) {
		blog(LOG_ERROR, "%s failed, glGetError returned 0x%X",
				funcname, errorcode);
		return false;
	}

	return true;
}

__attribute__((used)) static inline bool gl_gen_textures(GLsizei num_texture, GLuint *textures)
{
	glGenTextures(num_texture, textures);
	return gl_success("glGenTextures");
}

__attribute__((used)) static inline bool gl_bind_texture(GLenum target, GLuint texture)
{
	glBindTexture(target, texture);
	return gl_success("glBindTexture");
}

__attribute__((used)) static inline void gl_delete_textures(GLsizei num_buffers, GLuint *buffers)
{
	glDeleteTextures(num_buffers, buffers);
	gl_success("glDeleteTextures");
}

__attribute__((used)) static inline bool gl_gen_buffers(GLsizei num_buffers, GLuint *buffers)
{
	glGenBuffers(num_buffers, buffers);
	return gl_success("glGenBuffers");
}

__attribute__((used)) static inline bool gl_bind_buffer(GLenum target, GLuint buffer)
{
	glBindBuffer(target, buffer);
	return gl_success("glBindBuffer");
}

__attribute__((used)) static inline void gl_delete_buffers(GLsizei num_buffers, GLuint *buffers)
{
	glDeleteBuffers(num_buffers, buffers);
	gl_success("glDeleteBuffers");
}

__attribute__((used)) static inline bool gl_gen_vertex_arrays(GLsizei num_arrays, GLuint *arrays)
{
	glGenVertexArrays(num_arrays, arrays);
	return gl_success("glGenVertexArrays");
}

__attribute__((used)) static inline bool gl_bind_vertex_array(GLuint array)
{
	glBindVertexArray(array);
	return gl_success("glBindVertexArray");
}

__attribute__((used)) static inline void gl_delete_vertex_arrays(GLsizei num_arrays, GLuint *arrays)
{
	glDeleteVertexArrays(num_arrays, arrays);
	gl_success("glDeleteVertexArrays");
}

__attribute__((used)) static inline bool gl_bind_renderbuffer(GLenum target, GLuint buffer)
{
	glBindRenderbuffer(target, buffer);
	return gl_success("glBindRendebuffer");
}

__attribute__((used)) static inline bool gl_bind_framebuffer(GLenum target, GLuint buffer)
{
	glBindFramebuffer(target, buffer);
	return gl_success("glBindFramebuffer");
}

__attribute__((used)) static inline bool gl_tex_param_f(GLenum target, GLenum param, GLfloat val)
{
	glTexParameterf(target, param, val);
	return gl_success("glTexParameterf");
}

__attribute__((used)) static inline bool gl_tex_param_i(GLenum target, GLenum param, GLint val)
{
	glTexParameteri(target, param, val);
	return gl_success("glTexParameteri");
}

__attribute__((used)) static inline bool gl_active_texture(GLenum texture_id)
{
	glActiveTexture(texture_id);
	return gl_success("glActiveTexture");
}

__attribute__((used)) static inline bool gl_enable(GLenum capability)
{
	glEnable(capability);
	return gl_success("glEnable");
}

__attribute__((used)) static inline bool gl_disable(GLenum capability)
{
	glDisable(capability);
	return gl_success("glDisable");
}

__attribute__((used)) static inline bool gl_cull_face(GLenum faces)
{
	glCullFace(faces);
	return gl_success("glCullFace");
}

__attribute__((used)) static inline bool gl_get_integer_v(GLenum pname, GLint *params)
{
	glGetIntegerv(pname, params);
	return gl_success("glGetIntegerv");
}

__attribute__((used)) static inline GLenum convert_gs_format(enum gs_color_format format)
{
	switch (format) {
	case GS_A8:          return GL_RED;
	case GS_R8:          return GL_RED;
	case GS_RGBA:        return GL_RGBA;
	case GS_BGRX:        return GL_BGRA;
	case GS_BGRA:        return GL_BGRA;
	case GS_R10G10B10A2: return GL_RGBA;
	case GS_RGBA16:      return GL_RGBA;
	case GS_R16:         return GL_RED;
	case GS_RGBA16F:     return GL_RGBA;
	case GS_RGBA32F:     return GL_RGBA;
	case GS_RG16F:       return GL_RG;
	case GS_RG32F:       return GL_RG;
	case GS_R8G8:        return GL_RG;
	case GS_R16F:        return GL_RED;
	case GS_R32F:        return GL_RED;
	case GS_DXT1:        return GL_RGB;
	case GS_DXT3:        return GL_RGBA;
	case GS_DXT5:        return GL_RGBA;
	case GS_UNKNOWN:     return 0;
	}

	return 0;
}

__attribute__((used)) static inline GLenum convert_gs_internal_format(enum gs_color_format format)
{
	switch (format) {
	case GS_A8:          return GL_R8; /* NOTE: use GL_TEXTURE_SWIZZLE_x */
	case GS_R8:          return GL_R8;
	case GS_RGBA:        return GL_RGBA;
	case GS_BGRX:        return GL_RGB;
	case GS_BGRA:        return GL_RGBA;
	case GS_R10G10B10A2: return GL_RGB10_A2;
	case GS_RGBA16:      return GL_RGBA16;
	case GS_R16:         return GL_R16;
	case GS_RGBA16F:     return GL_RGBA16F;
	case GS_RGBA32F:     return GL_RGBA32F;
	case GS_RG16F:       return GL_RG16F;
	case GS_RG32F:       return GL_RG32F;
	case GS_R8G8:        return GL_R16;
	case GS_R16F:        return GL_R16F;
	case GS_R32F:        return GL_R32F;
	case GS_DXT1:        return GL_COMPRESSED_RGBA_S3TC_DXT1_EXT;
	case GS_DXT3:        return GL_COMPRESSED_RGBA_S3TC_DXT3_EXT;
	case GS_DXT5:        return GL_COMPRESSED_RGBA_S3TC_DXT5_EXT;
	case GS_UNKNOWN:     return 0;
	}

	return 0;
}

__attribute__((used)) static inline GLenum get_gl_format_type(enum gs_color_format format)
{
	switch (format) {
	case GS_A8:          return GL_UNSIGNED_BYTE;
	case GS_R8:          return GL_UNSIGNED_BYTE;
	case GS_RGBA:        return GL_UNSIGNED_BYTE;
	case GS_BGRX:        return GL_UNSIGNED_BYTE;
	case GS_BGRA:        return GL_UNSIGNED_BYTE;
	case GS_R10G10B10A2: return GL_UNSIGNED_INT_10_10_10_2;
	case GS_RGBA16:      return GL_UNSIGNED_SHORT;
	case GS_R16:         return GL_UNSIGNED_SHORT;
	case GS_RGBA16F:     return GL_UNSIGNED_SHORT;
	case GS_RGBA32F:     return GL_FLOAT;
	case GS_RG16F:       return GL_UNSIGNED_SHORT;
	case GS_RG32F:       return GL_FLOAT;
	case GS_R8G8:        return GL_UNSIGNED_SHORT;
	case GS_R16F:        return GL_UNSIGNED_SHORT;
	case GS_R32F:        return GL_FLOAT;
	case GS_DXT1:        return GL_UNSIGNED_BYTE;
	case GS_DXT3:        return GL_UNSIGNED_BYTE;
	case GS_DXT5:        return GL_UNSIGNED_BYTE;
	case GS_UNKNOWN:     return 0;
	}

	return GL_UNSIGNED_BYTE;
}

__attribute__((used)) static inline GLenum convert_zstencil_format(enum gs_zstencil_format format)
{
	switch (format) {
	case GS_Z16:         return GL_DEPTH_COMPONENT16;
	case GS_Z24_S8:      return GL_DEPTH24_STENCIL8;
	case GS_Z32F:        return GL_DEPTH_COMPONENT32F;
	case GS_Z32F_S8X24:  return GL_DEPTH32F_STENCIL8;
	case GS_ZS_NONE:     return 0;
	}

	return 0;
}

__attribute__((used)) static inline GLenum convert_gs_depth_test(enum gs_depth_test test)
{
	switch (test) {
	case GS_NEVER:    return GL_NEVER;
	case GS_LESS:     return GL_LESS;
	case GS_LEQUAL:   return GL_LEQUAL;
	case GS_EQUAL:    return GL_EQUAL;
	case GS_GEQUAL:   return GL_GEQUAL;
	case GS_GREATER:  return GL_GREATER;
	case GS_NOTEQUAL: return GL_NOTEQUAL;
	case GS_ALWAYS:   return GL_ALWAYS;
	}

	return GL_NEVER;
}

__attribute__((used)) static inline GLenum convert_gs_stencil_op(enum gs_stencil_op_type op)
{
	switch (op) {
	case GS_KEEP:    return GL_KEEP;
	case GS_ZERO:    return GL_ZERO;
	case GS_REPLACE: return GL_REPLACE;
	case GS_INCR:    return GL_INCR;
	case GS_DECR:    return GL_DECR;
	case GS_INVERT:  return GL_INVERT;
	}

	return GL_KEEP;
}

__attribute__((used)) static inline GLenum convert_gs_stencil_side(enum gs_stencil_side side)
{
	switch (side) {
	case GS_STENCIL_FRONT: return GL_FRONT;
	case GS_STENCIL_BACK:  return GL_BACK;
	case GS_STENCIL_BOTH:  return GL_FRONT_AND_BACK;
	}

	return GL_FRONT;
}

__attribute__((used)) static inline GLenum convert_gs_blend_type(enum gs_blend_type type)
{
	switch (type) {
	case GS_BLEND_ZERO:        return GL_ZERO;
	case GS_BLEND_ONE:         return GL_ONE;
	case GS_BLEND_SRCCOLOR:    return GL_SRC_COLOR;
	case GS_BLEND_INVSRCCOLOR: return GL_ONE_MINUS_SRC_COLOR;
	case GS_BLEND_SRCALPHA:    return GL_SRC_ALPHA;
	case GS_BLEND_INVSRCALPHA: return GL_ONE_MINUS_SRC_ALPHA;
	case GS_BLEND_DSTCOLOR:    return GL_DST_COLOR;
	case GS_BLEND_INVDSTCOLOR: return GL_ONE_MINUS_DST_COLOR;
	case GS_BLEND_DSTALPHA:    return GL_DST_ALPHA;
	case GS_BLEND_INVDSTALPHA: return GL_ONE_MINUS_DST_ALPHA;
	case GS_BLEND_SRCALPHASAT: return GL_SRC_ALPHA_SATURATE;
	}

	return GL_ONE;
}

__attribute__((used)) static inline GLenum convert_shader_type(enum gs_shader_type type)
{
	switch (type) {
	case GS_SHADER_VERTEX: return GL_VERTEX_SHADER;
	case GS_SHADER_PIXEL:  return GL_FRAGMENT_SHADER;
	}

	return GL_VERTEX_SHADER;
}

__attribute__((used)) static inline void convert_filter(enum gs_sample_filter filter,
		GLint *min_filter, GLint *mag_filter)
{
	switch (filter) {
	case GS_FILTER_POINT:
		*min_filter = GL_NEAREST_MIPMAP_NEAREST;
		*mag_filter = GL_NEAREST;
		return;
	case GS_FILTER_LINEAR:
		*min_filter = GL_LINEAR_MIPMAP_LINEAR;
		*mag_filter = GL_LINEAR;
		return;
	case GS_FILTER_MIN_MAG_POINT_MIP_LINEAR:
		*min_filter = GL_NEAREST_MIPMAP_LINEAR;
		*mag_filter = GL_NEAREST;
		return;
	case GS_FILTER_MIN_POINT_MAG_LINEAR_MIP_POINT:
		*min_filter = GL_NEAREST_MIPMAP_NEAREST;
		*mag_filter = GL_LINEAR;
		return;
	case GS_FILTER_MIN_POINT_MAG_MIP_LINEAR:
		*min_filter = GL_NEAREST_MIPMAP_LINEAR;
		*mag_filter = GL_LINEAR;
		return;
	case GS_FILTER_MIN_LINEAR_MAG_MIP_POINT:
		*min_filter = GL_LINEAR_MIPMAP_NEAREST;
		*mag_filter = GL_NEAREST;
		return;
	case GS_FILTER_MIN_LINEAR_MAG_POINT_MIP_LINEAR:
		*min_filter = GL_LINEAR_MIPMAP_LINEAR;
		*mag_filter = GL_NEAREST;
		return;
	case GS_FILTER_MIN_MAG_LINEAR_MIP_POINT:
		*min_filter = GL_LINEAR_MIPMAP_NEAREST;
		*mag_filter = GL_LINEAR;
		return;
	case GS_FILTER_ANISOTROPIC:
		*min_filter = GL_LINEAR_MIPMAP_LINEAR;
		*mag_filter = GL_LINEAR;
		return;
	}

	*min_filter = GL_NEAREST_MIPMAP_NEAREST;
	*mag_filter = GL_NEAREST;
}

__attribute__((used)) static inline GLint convert_address_mode(enum gs_address_mode mode)
{
	switch (mode) {
	case GS_ADDRESS_WRAP:       return GL_REPEAT;
	case GS_ADDRESS_CLAMP:      return GL_CLAMP_TO_EDGE;
	case GS_ADDRESS_MIRROR:     return GL_MIRRORED_REPEAT;
	case GS_ADDRESS_BORDER:     return GL_CLAMP_TO_BORDER;
	case GS_ADDRESS_MIRRORONCE: return GL_MIRROR_CLAMP_EXT;
	}

	return GL_REPEAT;
}

__attribute__((used)) static inline GLenum convert_gs_topology(enum gs_draw_mode mode)
{
	switch (mode) {
	case GS_POINTS:    return GL_POINTS;
	case GS_LINES:     return GL_LINES;
	case GS_LINESTRIP: return GL_LINE_STRIP;
	case GS_TRIS:      return GL_TRIANGLES;
	case GS_TRISTRIP:  return GL_TRIANGLE_STRIP;
	}

	return GL_POINTS;
}

__attribute__((used)) static inline void samplerstate_addref(gs_samplerstate_t *ss)
{
	os_atomic_inc_long(&ss->ref);
}

__attribute__((used)) static inline void samplerstate_release(gs_samplerstate_t *ss)
{
	if (os_atomic_dec_long(&ss->ref) == 0)
		bfree(ss);
}

__attribute__((used)) static inline void fbo_info_destroy(struct fbo_info *fbo)
{
	if (fbo) {
		glDeleteFramebuffers(1, &fbo->fbo);
		gl_success("glDeleteFramebuffers");

		bfree(fbo);
	}
}

bool gl_init_face(GLenum target, GLenum type, uint32_t num_levels,
		GLenum format, GLint internal_format, bool compressed,
		uint32_t width, uint32_t height, uint32_t size,
		const uint8_t ***p_data)
{
	bool success = true;
	const uint8_t **data = p_data ? *p_data : NULL;
	uint32_t i;

	for (i = 0; i < num_levels; i++) {
		if (compressed) {
			glCompressedTexImage2D(target, i, internal_format,
					width, height, 0, size,
					data ? *data : NULL);
			if (!gl_success("glCompressedTexImage2D"))
				success = false;

		} else {
			glTexImage2D(target, i, internal_format, width, height,
					0, format, type, data ? *data : NULL);
			if (!gl_success("glTexImage2D"))
				success = false;
		}

		if (data)
			data++;

		size   /= 4;
		width  /= 2;
		height /= 2;

		if (width  == 0) width  = 1;
		if (height == 0) height = 1;
	}

	if (data)
		*p_data = data;
	return success;
}

__attribute__((used)) static bool gl_copy_fbo(struct gs_texture *dst, uint32_t dst_x, uint32_t dst_y,
		struct gs_texture *src, uint32_t src_x, uint32_t src_y,
		uint32_t width, uint32_t height)
{
	struct fbo_info *fbo = get_fbo(src, width, height);
	GLint last_fbo;
	bool success = false;

	if (!fbo)
		return false;

	if (!gl_get_integer_v(GL_READ_FRAMEBUFFER_BINDING, &last_fbo))
		return false;
	if (!gl_bind_framebuffer(GL_READ_FRAMEBUFFER, fbo->fbo))
		return false;
	if (!gl_bind_texture(dst->gl_target, dst->texture))
		goto fail;

	glFramebufferTexture2D(GL_READ_FRAMEBUFFER, GL_COLOR_ATTACHMENT0 + 0,
			src->gl_target, src->texture, 0);
	if (!gl_success("glFrameBufferTexture2D"))
		goto fail;

	glReadBuffer(GL_COLOR_ATTACHMENT0 + 0);
	if (!gl_success("glReadBuffer"))
		goto fail;

	glCopyTexSubImage2D(dst->gl_target, 0, dst_x, dst_y, src_x, src_y,
			width, height);
	if (!gl_success("glCopyTexSubImage2D"))
		goto fail;

	success = true;

fail:
	if (!gl_bind_texture(dst->gl_target, 0))
		success = false;
	if (!gl_bind_framebuffer(GL_READ_FRAMEBUFFER, last_fbo))
		success = false;

	return success;
}

bool gl_copy_texture(struct gs_device *device, struct gs_texture *dst,
		uint32_t dst_x, uint32_t dst_y, struct gs_texture *src,
		uint32_t src_x, uint32_t src_y, uint32_t width,
		uint32_t height)
{
	bool success = false;

	if (device->copy_type == COPY_TYPE_ARB) {
		glCopyImageSubData(src->texture, src->gl_target, 0, src_x,
				src_y, 0, dst->texture, dst->gl_target, 0,
				dst_x, dst_y, 0, width, height, 1);
		success = gl_success("glCopyImageSubData");

	} else if (device->copy_type == COPY_TYPE_NV) {
		glCopyImageSubDataNV(src->texture, src->gl_target, 0, src_x,
				src_y, 0, dst->texture, dst->gl_target, 0,
				dst_x, dst_y, 0, width, height, 1);
		success = gl_success("glCopyImageSubDataNV");

	} else if (device->copy_type == COPY_TYPE_FBO_BLIT) {
		success = gl_copy_fbo(dst, dst_x, dst_y, src, src_x, src_y,
				width, height);
		if (!success)
			blog(LOG_ERROR, "gl_copy_texture failed");
	}

	return success;
}

bool gl_create_buffer(GLenum target, GLuint *buffer, GLsizeiptr size,
		const GLvoid *data, GLenum usage)
{
	bool success;
	if (!gl_gen_buffers(1, buffer))
		return false;
	if (!gl_bind_buffer(target, *buffer))
		return false;

	glBufferData(target, size, data, usage);
	success = gl_success("glBufferData");

	gl_bind_buffer(target, 0);
	return success;
}

bool update_buffer(GLenum target, GLuint buffer, const void *data, size_t size)
{
	void *ptr;
	bool success = true;

	if (!gl_bind_buffer(target, buffer))
		return false;

	/* glMapBufferRange with these flags will actually give far better
	 * performance than a plain glMapBuffer call */
	ptr = glMapBufferRange(target, 0, size,
			GL_MAP_WRITE_BIT |
			GL_MAP_INVALIDATE_BUFFER_BIT);
	success = gl_success("glMapBufferRange");
	if (success && ptr) {
		memcpy(ptr, data, size);
		glUnmapBuffer(target);
	}

	gl_bind_buffer(target, 0);
	return success;
}

