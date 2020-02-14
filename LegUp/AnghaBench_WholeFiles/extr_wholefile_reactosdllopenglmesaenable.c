#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_46__   TYPE_9__ ;
typedef  struct TYPE_45__   TYPE_8__ ;
typedef  struct TYPE_44__   TYPE_7__ ;
typedef  struct TYPE_43__   TYPE_6__ ;
typedef  struct TYPE_42__   TYPE_5__ ;
typedef  struct TYPE_41__   TYPE_4__ ;
typedef  struct TYPE_40__   TYPE_3__ ;
typedef  struct TYPE_39__   TYPE_2__ ;
typedef  struct TYPE_38__   TYPE_1__ ;
typedef  struct TYPE_37__   TYPE_17__ ;
typedef  struct TYPE_36__   TYPE_16__ ;
typedef  struct TYPE_35__   TYPE_15__ ;
typedef  struct TYPE_34__   TYPE_14__ ;
typedef  struct TYPE_33__   TYPE_13__ ;
typedef  struct TYPE_32__   TYPE_12__ ;
typedef  struct TYPE_31__   TYPE_11__ ;
typedef  struct TYPE_30__   TYPE_10__ ;

/* Type definitions */
struct TYPE_46__ {void* AutoNormal; void* Map1Color4; void* Map1Index; void* Map1Normal; void* Map1TextureCoord1; void* Map1TextureCoord2; void* Map1TextureCoord3; void* Map1TextureCoord4; void* Map1Vertex3; void* Map1Vertex4; void* Map2Color4; void* Map2Index; void* Map2Normal; void* Map2TextureCoord1; void* Map2TextureCoord2; void* Map2TextureCoord3; void* Map2TextureCoord4; void* Map2Vertex3; void* Map2Vertex4; } ;
struct TYPE_45__ {void* AlphaEnabled; void* BlendEnabled; void* ColorLogicOpEnabled; void* DitherFlag; void* IndexLogicOpEnabled; } ;
struct TYPE_44__ {void* SmoothFlag; void* StippleFlag; } ;
struct TYPE_43__ {void* ColorMaterialEnabled; void* Enabled; TYPE_5__* Light; int /*<<< orphan*/  ColorMaterialBitmask; } ;
struct TYPE_42__ {void* Enabled; } ;
struct TYPE_41__ {void* Enabled; } ;
struct TYPE_40__ {void* Test; } ;
struct TYPE_39__ {int InvRedScale; int InvGreenScale; int InvBlueScale; int InvAlphaScale; int /*<<< orphan*/  RGBAflag; int /*<<< orphan*/  StencilBits; int /*<<< orphan*/  DepthBits; } ;
struct TYPE_38__ {int* ByteColor; } ;
struct TYPE_36__ {void* VertexEnabled; void* NormalEnabled; void* ColorEnabled; void* IndexEnabled; void* TexCoordEnabled; void* EdgeFlagEnabled; } ;
struct TYPE_35__ {int Enabled; int TexGenEnabled; } ;
struct TYPE_34__ {void* Enabled; } ;
struct TYPE_33__ {void* Enabled; } ;
struct TYPE_32__ {void* CullFlag; void* SmoothFlag; void* StippleFlag; void* OffsetPoint; void* OffsetLine; void* OffsetFill; } ;
struct TYPE_31__ {void* SmoothFlag; } ;
struct TYPE_30__ {void** ClipEnabled; void* Normalize; void* AnyClip; } ;
struct TYPE_37__ {int NewState; TYPE_16__ Array; TYPE_15__ Texture; TYPE_14__ Stencil; TYPE_13__ Scissor; TYPE_12__ Polygon; TYPE_11__ Point; TYPE_10__ Transform; TYPE_9__ Eval; TYPE_8__ Color; TYPE_7__ Line; TYPE_6__ Light; TYPE_4__ Fog; TYPE_3__ Depth; TYPE_2__* Visual; int /*<<< orphan*/  NoDither; TYPE_1__ Current; } ;
typedef  size_t GLuint ;
typedef  int GLfloat ;
typedef  int GLenum ;
typedef  TYPE_17__ GLcontext ;
typedef  void* GLboolean ;

/* Variables and functions */
#define  GL_ALPHA_TEST 193 
#define  GL_AUTO_NORMAL 192 
#define  GL_BLEND 191 
#define  GL_CLIP_PLANE0 190 
#define  GL_CLIP_PLANE1 189 
#define  GL_CLIP_PLANE2 188 
#define  GL_CLIP_PLANE3 187 
#define  GL_CLIP_PLANE4 186 
#define  GL_CLIP_PLANE5 185 
#define  GL_COLOR_ARRAY 184 
#define  GL_COLOR_LOGIC_OP 183 
#define  GL_COLOR_MATERIAL 182 
#define  GL_CULL_FACE 181 
#define  GL_DEPTH_TEST 180 
#define  GL_DITHER 179 
#define  GL_EDGE_FLAG_ARRAY 178 
 void* GL_FALSE ; 
#define  GL_FOG 177 
#define  GL_INDEX_ARRAY 176 
#define  GL_INDEX_LOGIC_OP 175 
 int /*<<< orphan*/  GL_INVALID_ENUM ; 
 int /*<<< orphan*/  GL_INVALID_OPERATION ; 
#define  GL_LIGHT0 174 
#define  GL_LIGHT1 173 
#define  GL_LIGHT2 172 
#define  GL_LIGHT3 171 
#define  GL_LIGHT4 170 
#define  GL_LIGHT5 169 
#define  GL_LIGHT6 168 
#define  GL_LIGHT7 167 
#define  GL_LIGHTING 166 
#define  GL_LINE_SMOOTH 165 
#define  GL_LINE_STIPPLE 164 
#define  GL_MAP1_COLOR_4 163 
#define  GL_MAP1_INDEX 162 
#define  GL_MAP1_NORMAL 161 
#define  GL_MAP1_TEXTURE_COORD_1 160 
#define  GL_MAP1_TEXTURE_COORD_2 159 
#define  GL_MAP1_TEXTURE_COORD_3 158 
#define  GL_MAP1_TEXTURE_COORD_4 157 
#define  GL_MAP1_VERTEX_3 156 
#define  GL_MAP1_VERTEX_4 155 
#define  GL_MAP2_COLOR_4 154 
#define  GL_MAP2_INDEX 153 
#define  GL_MAP2_NORMAL 152 
#define  GL_MAP2_TEXTURE_COORD_1 151 
#define  GL_MAP2_TEXTURE_COORD_2 150 
#define  GL_MAP2_TEXTURE_COORD_3 149 
#define  GL_MAP2_TEXTURE_COORD_4 148 
#define  GL_MAP2_VERTEX_3 147 
#define  GL_MAP2_VERTEX_4 146 
#define  GL_NORMALIZE 145 
#define  GL_NORMAL_ARRAY 144 
#define  GL_POINT_SMOOTH 143 
#define  GL_POLYGON_OFFSET_FILL 142 
#define  GL_POLYGON_OFFSET_LINE 141 
#define  GL_POLYGON_OFFSET_POINT 140 
#define  GL_POLYGON_SMOOTH 139 
#define  GL_POLYGON_STIPPLE 138 
#define  GL_SCISSOR_TEST 137 
#define  GL_STENCIL_TEST 136 
#define  GL_TEXTURE_1D 135 
#define  GL_TEXTURE_2D 134 
#define  GL_TEXTURE_COORD_ARRAY 133 
#define  GL_TEXTURE_GEN_Q 132 
#define  GL_TEXTURE_GEN_R 131 
#define  GL_TEXTURE_GEN_S 130 
#define  GL_TEXTURE_GEN_T 129 
 void* GL_TRUE ; 
#define  GL_VERTEX_ARRAY 128 
 scalar_t__ INSIDE_BEGIN_END (TYPE_17__*) ; 
 size_t MAX_CLIP_PLANES ; 
 int NEW_LIGHTING ; 
 int NEW_POLYGON ; 
 int NEW_RASTER_OPS ; 
 int NEW_TEXTURING ; 
 int Q_BIT ; 
 int R_BIT ; 
 int S_BIT ; 
 int TEXTURE_1D ; 
 int TEXTURE_2D ; 
 int T_BIT ; 
 int /*<<< orphan*/  gl_error (TYPE_17__*,int /*<<< orphan*/ ,char*) ; 
 int /*<<< orphan*/  gl_set_color_function (TYPE_17__*) ; 
 int /*<<< orphan*/  gl_set_material (TYPE_17__*,int /*<<< orphan*/ ,int*) ; 
 int /*<<< orphan*/  gl_warning (TYPE_17__*,char*) ; 

__attribute__((used)) static void gl_enable( GLcontext* ctx, GLenum cap, GLboolean state )
{
   GLuint p;

   if (INSIDE_BEGIN_END(ctx)) {
      if (state) {
	 gl_error( ctx, GL_INVALID_OPERATION, "glEnable" );
      }
      else {
	 gl_error( ctx, GL_INVALID_OPERATION, "glDisable" );
      }
      return;
   }

   switch (cap) {
      case GL_ALPHA_TEST:
         if (ctx->Color.AlphaEnabled!=state) {
            ctx->Color.AlphaEnabled = state;
            ctx->NewState |= NEW_RASTER_OPS;
         }
	 break;
      case GL_AUTO_NORMAL:
	 ctx->Eval.AutoNormal = state;
	 break;
      case GL_BLEND:
         if (ctx->Color.BlendEnabled!=state) {
            ctx->Color.BlendEnabled = state;
            /* The following needed to accomodate 1.0 RGB logic op blending */
            ctx->Color.ColorLogicOpEnabled = GL_FALSE;
            ctx->NewState |= NEW_RASTER_OPS;
         }
	 break;
      case GL_CLIP_PLANE0:
      case GL_CLIP_PLANE1:
      case GL_CLIP_PLANE2:
      case GL_CLIP_PLANE3:
      case GL_CLIP_PLANE4:
      case GL_CLIP_PLANE5:
	 ctx->Transform.ClipEnabled[cap-GL_CLIP_PLANE0] = state;
	 /* Check if any clip planes enabled */
         ctx->Transform.AnyClip = GL_FALSE;
         for (p=0;p<MAX_CLIP_PLANES;p++) {
            if (ctx->Transform.ClipEnabled[p]) {
               ctx->Transform.AnyClip = GL_TRUE;
               break;
            }
         }
	 break;
      case GL_COLOR_MATERIAL:
         if (ctx->Light.ColorMaterialEnabled!=state) {
            ctx->Light.ColorMaterialEnabled = state;
            if (state) {
               GLfloat color[4];
               color[0] = ctx->Current.ByteColor[0] * ctx->Visual->InvRedScale;
               color[1] = ctx->Current.ByteColor[1] * ctx->Visual->InvGreenScale;
               color[2] = ctx->Current.ByteColor[2] * ctx->Visual->InvBlueScale;
               color[3] = ctx->Current.ByteColor[3] * ctx->Visual->InvAlphaScale;
               /* update material with current color */
               gl_set_material( ctx, ctx->Light.ColorMaterialBitmask, color );
            }
            gl_set_color_function(ctx);
            ctx->NewState |= NEW_LIGHTING;
         }
	 break;
      case GL_CULL_FACE:
         if (ctx->Polygon.CullFlag!=state) {
            ctx->Polygon.CullFlag = state;
            ctx->NewState |= NEW_POLYGON;
         }
	 break;
      case GL_DEPTH_TEST:
         if (state && ctx->Visual->DepthBits==0) {
            gl_warning(ctx,"glEnable(GL_DEPTH_TEST) but no depth buffer");
            return;
         }
	 if (ctx->Depth.Test!=state) {
            ctx->Depth.Test = state;
            ctx->NewState |= NEW_RASTER_OPS;
         }
         break;
      case GL_DITHER:
         if (ctx->NoDither) {
            /* MESA_NO_DITHER env var */
            state = GL_FALSE;
         }
         if (ctx->Color.DitherFlag!=state) {
            ctx->Color.DitherFlag = state;
            ctx->NewState |= NEW_RASTER_OPS;
         }
	 break;
      case GL_FOG:
	 if (ctx->Fog.Enabled!=state) {
            ctx->Fog.Enabled = state;
            ctx->NewState |= NEW_RASTER_OPS;
         }
	 break;
      case GL_LIGHT0:
      case GL_LIGHT1:
      case GL_LIGHT2:
      case GL_LIGHT3:
      case GL_LIGHT4:
      case GL_LIGHT5:
      case GL_LIGHT6:
      case GL_LIGHT7:
         ctx->Light.Light[cap-GL_LIGHT0].Enabled = state;
         ctx->NewState |= NEW_LIGHTING;
         break;
      case GL_LIGHTING:
         if (ctx->Light.Enabled!=state) {
            ctx->Light.Enabled = state;
            ctx->NewState |= NEW_LIGHTING;
         }
         break;
      case GL_LINE_SMOOTH:
	 if (ctx->Line.SmoothFlag!=state) {
            ctx->Line.SmoothFlag = state;
            ctx->NewState |= NEW_RASTER_OPS;
         }
	 break;
      case GL_LINE_STIPPLE:
	 if (ctx->Line.StippleFlag!=state) {
            ctx->Line.StippleFlag = state;
            ctx->NewState |= NEW_RASTER_OPS;
         }
	 break;
      case GL_INDEX_LOGIC_OP:
         if (ctx->Color.IndexLogicOpEnabled!=state) {
            ctx->NewState |= NEW_RASTER_OPS;
         }
	 ctx->Color.IndexLogicOpEnabled = state;
	 break;
      case GL_COLOR_LOGIC_OP:
         if (ctx->Color.ColorLogicOpEnabled!=state) {
            ctx->NewState |= NEW_RASTER_OPS;
         }
	 ctx->Color.ColorLogicOpEnabled = state;
	 break;
      case GL_MAP1_COLOR_4:
	 ctx->Eval.Map1Color4 = state;
	 break;
      case GL_MAP1_INDEX:
	 ctx->Eval.Map1Index = state;
	 break;
      case GL_MAP1_NORMAL:
	 ctx->Eval.Map1Normal = state;
	 break;
      case GL_MAP1_TEXTURE_COORD_1:
	 ctx->Eval.Map1TextureCoord1 = state;
	 break;
      case GL_MAP1_TEXTURE_COORD_2:
	 ctx->Eval.Map1TextureCoord2 = state;
	 break;
      case GL_MAP1_TEXTURE_COORD_3:
	 ctx->Eval.Map1TextureCoord3 = state;
	 break;
      case GL_MAP1_TEXTURE_COORD_4:
	 ctx->Eval.Map1TextureCoord4 = state;
	 break;
      case GL_MAP1_VERTEX_3:
	 ctx->Eval.Map1Vertex3 = state;
	 break;
      case GL_MAP1_VERTEX_4:
	 ctx->Eval.Map1Vertex4 = state;
	 break;
      case GL_MAP2_COLOR_4:
	 ctx->Eval.Map2Color4 = state;
	 break;
      case GL_MAP2_INDEX:
	 ctx->Eval.Map2Index = state;
	 break;
      case GL_MAP2_NORMAL:
	 ctx->Eval.Map2Normal = state;
	 break;
      case GL_MAP2_TEXTURE_COORD_1: 
	 ctx->Eval.Map2TextureCoord1 = state;
	 break;
      case GL_MAP2_TEXTURE_COORD_2:
	 ctx->Eval.Map2TextureCoord2 = state;
	 break;
      case GL_MAP2_TEXTURE_COORD_3:
	 ctx->Eval.Map2TextureCoord3 = state;
	 break;
      case GL_MAP2_TEXTURE_COORD_4:
	 ctx->Eval.Map2TextureCoord4 = state;
	 break;
      case GL_MAP2_VERTEX_3:
	 ctx->Eval.Map2Vertex3 = state;
	 break;
      case GL_MAP2_VERTEX_4:
	 ctx->Eval.Map2Vertex4 = state;
	 break;
      case GL_NORMALIZE:
	 ctx->Transform.Normalize = state;
	 break;
      case GL_POINT_SMOOTH:
	 if (ctx->Point.SmoothFlag!=state) {
            ctx->Point.SmoothFlag = state;
            ctx->NewState |= NEW_RASTER_OPS;
         }
	 break;
      case GL_POLYGON_SMOOTH:
	 if (ctx->Polygon.SmoothFlag!=state) {
            ctx->Polygon.SmoothFlag = state;
            ctx->NewState |= NEW_RASTER_OPS;
         }
	 break;
      case GL_POLYGON_STIPPLE:
	 if (ctx->Polygon.StippleFlag!=state) {
            ctx->Polygon.StippleFlag = state;
            ctx->NewState |= NEW_RASTER_OPS;
         }
	 break;
      case GL_POLYGON_OFFSET_POINT:
         if (ctx->Polygon.OffsetPoint!=state) {
            ctx->Polygon.OffsetPoint = state;
            ctx->NewState |= NEW_POLYGON;
         }
         break;
      case GL_POLYGON_OFFSET_LINE:
         if (ctx->Polygon.OffsetLine!=state) {
            ctx->Polygon.OffsetLine = state;
            ctx->NewState |= NEW_POLYGON;
         }
         break;
      case GL_POLYGON_OFFSET_FILL:
      /*case GL_POLYGON_OFFSET_EXT:*/
         if (ctx->Polygon.OffsetFill!=state) {
            ctx->Polygon.OffsetFill = state;
            ctx->NewState |= NEW_POLYGON;
         }
         break;
      case GL_SCISSOR_TEST:
         if (ctx->Scissor.Enabled!=state) {
            ctx->Scissor.Enabled = state;
            ctx->NewState |= NEW_RASTER_OPS;
         }
	 break;
      case GL_STENCIL_TEST:
	 if (state && ctx->Visual->StencilBits==0) {
            gl_warning(ctx, "glEnable(GL_STENCIL_TEST) but no stencil buffer");
            return;
	 }
	 if (ctx->Stencil.Enabled!=state) {
            ctx->Stencil.Enabled = state;
            ctx->NewState |= NEW_RASTER_OPS;
         }
	 break;
      case GL_TEXTURE_1D:
         if (ctx->Visual->RGBAflag) {
            /* texturing only works in RGB mode */
            if (state) {
               ctx->Texture.Enabled |= TEXTURE_1D;
            }
            else {
               ctx->Texture.Enabled &= (~TEXTURE_1D);
            }
            ctx->NewState |= (NEW_RASTER_OPS | NEW_TEXTURING);
         }
	 break;
      case GL_TEXTURE_2D:
         if (ctx->Visual->RGBAflag) {
            /* texturing only works in RGB mode */
            if (state) {
               ctx->Texture.Enabled |= TEXTURE_2D;
            }
            else {
               ctx->Texture.Enabled &= (~TEXTURE_2D);
            }
            ctx->NewState |= (NEW_RASTER_OPS | NEW_TEXTURING);
         }
	 break;
      case GL_TEXTURE_GEN_Q:
         if (state) {
            ctx->Texture.TexGenEnabled |= Q_BIT;
         }
         else {
            ctx->Texture.TexGenEnabled &= ~Q_BIT;
         }
         ctx->NewState |= NEW_TEXTURING;
	 break;
      case GL_TEXTURE_GEN_R:
         if (state) {
            ctx->Texture.TexGenEnabled |= R_BIT;
         }
         else {
            ctx->Texture.TexGenEnabled &= ~R_BIT;
         }
         ctx->NewState |= NEW_TEXTURING;
	 break;
      case GL_TEXTURE_GEN_S:
	 if (state) {
            ctx->Texture.TexGenEnabled |= S_BIT;
         }
         else {
            ctx->Texture.TexGenEnabled &= ~S_BIT;
         }
         ctx->NewState |= NEW_TEXTURING;
	 break;
      case GL_TEXTURE_GEN_T:
         if (state) {
            ctx->Texture.TexGenEnabled |= T_BIT;
         }
         else {
            ctx->Texture.TexGenEnabled &= ~T_BIT;
         }
         ctx->NewState |= NEW_TEXTURING;
	 break;

      /*
       * CLIENT STATE!!!
       */
      case GL_VERTEX_ARRAY:
         ctx->Array.VertexEnabled = state;
         break;
      case GL_NORMAL_ARRAY:
         ctx->Array.NormalEnabled = state;
         break;
      case GL_COLOR_ARRAY:
         ctx->Array.ColorEnabled = state;
         break;
      case GL_INDEX_ARRAY:
         ctx->Array.IndexEnabled = state;
         break;
      case GL_TEXTURE_COORD_ARRAY:
         ctx->Array.TexCoordEnabled = state;
         break;
      case GL_EDGE_FLAG_ARRAY:
         ctx->Array.EdgeFlagEnabled = state;
         break;

      default:
	 if (state) {
	    gl_error( ctx, GL_INVALID_ENUM, "glEnable" );
	 }
	 else {
	    gl_error( ctx, GL_INVALID_ENUM, "glDisable" );
	 }
         break;
   }
}

void gl_Enable( GLcontext* ctx, GLenum cap )
{
   gl_enable( ctx, cap, GL_TRUE );
}

void gl_Disable( GLcontext* ctx, GLenum cap )
{
   gl_enable( ctx, cap, GL_FALSE );
}

GLboolean gl_IsEnabled( GLcontext* ctx, GLenum cap )
{
   switch (cap) {
      case GL_ALPHA_TEST:
         return ctx->Color.AlphaEnabled;
      case GL_AUTO_NORMAL:
	 return ctx->Eval.AutoNormal;
      case GL_BLEND:
         return ctx->Color.BlendEnabled;
      case GL_CLIP_PLANE0:
      case GL_CLIP_PLANE1:
      case GL_CLIP_PLANE2:
      case GL_CLIP_PLANE3:
      case GL_CLIP_PLANE4:
      case GL_CLIP_PLANE5:
	 return ctx->Transform.ClipEnabled[cap-GL_CLIP_PLANE0];
      case GL_COLOR_MATERIAL:
	 return ctx->Light.ColorMaterialEnabled;
      case GL_CULL_FACE:
         return ctx->Polygon.CullFlag;
      case GL_DEPTH_TEST:
         return ctx->Depth.Test;
      case GL_DITHER:
	 return ctx->Color.DitherFlag;
      case GL_FOG:
	 return ctx->Fog.Enabled;
      case GL_LIGHTING:
         return ctx->Light.Enabled;
      case GL_LIGHT0:
      case GL_LIGHT1:
      case GL_LIGHT2:
      case GL_LIGHT3:
      case GL_LIGHT4:
      case GL_LIGHT5:
      case GL_LIGHT6:
      case GL_LIGHT7:
         return ctx->Light.Light[cap-GL_LIGHT0].Enabled;
      case GL_LINE_SMOOTH:
	 return ctx->Line.SmoothFlag;
      case GL_LINE_STIPPLE:
	 return ctx->Line.StippleFlag;
      case GL_INDEX_LOGIC_OP:
	 return ctx->Color.IndexLogicOpEnabled;
      case GL_COLOR_LOGIC_OP:
	 return ctx->Color.ColorLogicOpEnabled;
      case GL_MAP1_COLOR_4:
	 return ctx->Eval.Map1Color4;
      case GL_MAP1_INDEX:
	 return ctx->Eval.Map1Index;
      case GL_MAP1_NORMAL:
	 return ctx->Eval.Map1Normal;
      case GL_MAP1_TEXTURE_COORD_1:
	 return ctx->Eval.Map1TextureCoord1;
      case GL_MAP1_TEXTURE_COORD_2:
	 return ctx->Eval.Map1TextureCoord2;
      case GL_MAP1_TEXTURE_COORD_3:
	 return ctx->Eval.Map1TextureCoord3;
      case GL_MAP1_TEXTURE_COORD_4:
	 return ctx->Eval.Map1TextureCoord4;
      case GL_MAP1_VERTEX_3:
	 return ctx->Eval.Map1Vertex3;
      case GL_MAP1_VERTEX_4:
	 return ctx->Eval.Map1Vertex4;
      case GL_MAP2_COLOR_4:
	 return ctx->Eval.Map2Color4;
      case GL_MAP2_INDEX:
	 return ctx->Eval.Map2Index;
      case GL_MAP2_NORMAL:
	 return ctx->Eval.Map2Normal;
      case GL_MAP2_TEXTURE_COORD_1: 
	 return ctx->Eval.Map2TextureCoord1;
      case GL_MAP2_TEXTURE_COORD_2:
	 return ctx->Eval.Map2TextureCoord2;
      case GL_MAP2_TEXTURE_COORD_3:
	 return ctx->Eval.Map2TextureCoord3;
      case GL_MAP2_TEXTURE_COORD_4:
	 return ctx->Eval.Map2TextureCoord4;
      case GL_MAP2_VERTEX_3:
	 return ctx->Eval.Map2Vertex3;
      case GL_MAP2_VERTEX_4:
	 return ctx->Eval.Map2Vertex4;
      case GL_NORMALIZE:
	 return ctx->Transform.Normalize;
      case GL_POINT_SMOOTH:
	 return ctx->Point.SmoothFlag;
      case GL_POLYGON_SMOOTH:
	 return ctx->Polygon.SmoothFlag;
      case GL_POLYGON_STIPPLE:
	 return ctx->Polygon.StippleFlag;
      case GL_POLYGON_OFFSET_POINT:
	 return ctx->Polygon.OffsetPoint;
      case GL_POLYGON_OFFSET_LINE:
	 return ctx->Polygon.OffsetLine;
      case GL_POLYGON_OFFSET_FILL:
      /*case GL_POLYGON_OFFSET_EXT:*/
	 return ctx->Polygon.OffsetFill;
      case GL_SCISSOR_TEST:
	 return ctx->Scissor.Enabled;
      case GL_STENCIL_TEST:
	 return ctx->Stencil.Enabled;
      case GL_TEXTURE_1D:
	 return (ctx->Texture.Enabled & TEXTURE_1D) ? GL_TRUE : GL_FALSE;
      case GL_TEXTURE_2D:
	 return (ctx->Texture.Enabled & TEXTURE_2D) ? GL_TRUE : GL_FALSE;
      case GL_TEXTURE_GEN_Q:
	 return (ctx->Texture.TexGenEnabled & Q_BIT) ? GL_TRUE : GL_FALSE;
      case GL_TEXTURE_GEN_R:
	 return (ctx->Texture.TexGenEnabled & R_BIT) ? GL_TRUE : GL_FALSE;
      case GL_TEXTURE_GEN_S:
	 return (ctx->Texture.TexGenEnabled & S_BIT) ? GL_TRUE : GL_FALSE;
      case GL_TEXTURE_GEN_T:
	 return (ctx->Texture.TexGenEnabled & T_BIT) ? GL_TRUE : GL_FALSE;

      /*
       * CLIENT STATE!!!
       */
      case GL_VERTEX_ARRAY:
         return ctx->Array.VertexEnabled;
      case GL_NORMAL_ARRAY:
         return ctx->Array.NormalEnabled;
      case GL_COLOR_ARRAY:
         return ctx->Array.ColorEnabled;
      case GL_INDEX_ARRAY:
         return ctx->Array.IndexEnabled;
      case GL_TEXTURE_COORD_ARRAY:
         return ctx->Array.TexCoordEnabled;
      case GL_EDGE_FLAG_ARRAY:
         return ctx->Array.EdgeFlagEnabled;
      default:
	 gl_error( ctx, GL_INVALID_ENUM, "glIsEnabled" );
	 return GL_FALSE;
   }
}

void gl_client_state( GLcontext *ctx, GLenum cap, GLboolean state )
{
   switch (cap) {
      case GL_VERTEX_ARRAY:
         ctx->Array.VertexEnabled = state;
         break;
      case GL_NORMAL_ARRAY:
         ctx->Array.NormalEnabled = state;
         break;
      case GL_COLOR_ARRAY:
         ctx->Array.ColorEnabled = state;
         break;
      case GL_INDEX_ARRAY:
         ctx->Array.IndexEnabled = state;
         break;
      case GL_TEXTURE_COORD_ARRAY:
         ctx->Array.TexCoordEnabled = state;
         break;
      case GL_EDGE_FLAG_ARRAY:
         ctx->Array.EdgeFlagEnabled = state;
         break;
      default:
         gl_error( ctx, GL_INVALID_ENUM, "glEnable/DisableClientState" );
   }
}

void gl_EnableClientState( GLcontext *ctx, GLenum cap )
{
   gl_client_state( ctx, cap, GL_TRUE );
}

void gl_DisableClientState( GLcontext *ctx, GLenum cap )
{
   gl_client_state( ctx, cap, GL_FALSE );
}

