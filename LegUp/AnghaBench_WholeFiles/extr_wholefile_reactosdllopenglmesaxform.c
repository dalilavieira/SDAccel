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
typedef  size_t GLuint ;
typedef  float GLfloat ;
typedef  int GLdouble ;
typedef  scalar_t__ GLboolean ;

/* Variables and functions */
 int GL_SQRT (int) ; 

void gl_xform_points_4fv( GLuint n, GLfloat q[][4], const GLfloat m[16],
                          GLfloat p[][4] )
{
   /* This function has been carefully crafted to maximize register usage
    * and use loop unrolling with IRIX 5.3's cc.  Hopefully other compilers
    * will like this code too.
    */
   {
      GLuint i;
      GLfloat m0 = m[0],  m4 = m[4],  m8 = m[8],  m12 = m[12];
      GLfloat m1 = m[1],  m5 = m[5],  m9 = m[9],  m13 = m[13];
      if (m12==0.0F && m13==0.0F) {
         /* common case */
         for (i=0;i<n;i++) {
            GLfloat p0 = p[i][0], p1 = p[i][1], p2 = p[i][2];
            q[i][0] = m0 * p0 + m4  * p1 + m8 * p2;
            q[i][1] = m1 * p0 + m5  * p1 + m9 * p2;
         }
      }
      else {
         /* general case */
         for (i=0;i<n;i++) {
            GLfloat p0 = p[i][0], p1 = p[i][1], p2 = p[i][2], p3 = p[i][3];
            q[i][0] = m0 * p0 + m4  * p1 + m8 * p2 + m12 * p3;
            q[i][1] = m1 * p0 + m5  * p1 + m9 * p2 + m13 * p3;
         }
      }
   }
   {
      GLuint i;
      GLfloat m2 = m[2],  m6 = m[6],  m10 = m[10],  m14 = m[14];
      GLfloat m3 = m[3],  m7 = m[7],  m11 = m[11],  m15 = m[15];
      if (m3==0.0F && m7==0.0F && m11==0.0F && m15==1.0F) {
         /* common case */
         for (i=0;i<n;i++) {
            GLfloat p0 = p[i][0], p1 = p[i][1], p2 = p[i][2], p3 = p[i][3];
            q[i][2] = m2 * p0 + m6 * p1 + m10 * p2 + m14 * p3;
            q[i][3] = p3;
         }
      }
      else {
         /* general case */
         for (i=0;i<n;i++) {
            GLfloat p0 = p[i][0], p1 = p[i][1], p2 = p[i][2], p3 = p[i][3];
            q[i][2] = m2 * p0 + m6 * p1 + m10 * p2 + m14 * p3;
            q[i][3] = m3 * p0 + m7 * p1 + m11 * p2 + m15 * p3;
         }
      }
   }
}

void gl_xform_points_3fv( GLuint n, GLfloat q[][4], const GLfloat m[16],
                          GLfloat p[][3] )
{
   /* This function has been carefully crafted to maximize register usage
    * and use loop unrolling with IRIX 5.3's cc.  Hopefully other compilers
    * will like this code too.
    */
   {
      GLuint i;
      GLfloat m0 = m[0],  m4 = m[4],  m8 = m[8],  m12 = m[12];
      GLfloat m1 = m[1],  m5 = m[5],  m9 = m[9],  m13 = m[13];
      for (i=0;i<n;i++) {
         GLfloat p0 = p[i][0], p1 = p[i][1], p2 = p[i][2];
         q[i][0] = m0 * p0 + m4  * p1 + m8 * p2 + m12;
         q[i][1] = m1 * p0 + m5  * p1 + m9 * p2 + m13;
      }
   }
   {
      GLuint i;
      GLfloat m2 = m[2],  m6 = m[6],  m10 = m[10],  m14 = m[14];
      GLfloat m3 = m[3],  m7 = m[7],  m11 = m[11],  m15 = m[15];
      if (m3==0.0F && m7==0.0F && m11==0.0F && m15==1.0F) {
         /* common case */
         for (i=0;i<n;i++) {
            GLfloat p0 = p[i][0], p1 = p[i][1], p2 = p[i][2];
            q[i][2] = m2 * p0 + m6 * p1 + m10 * p2 + m14;
            q[i][3] = 1.0F;
         }
      }
      else {
         /* general case */
         for (i=0;i<n;i++) {
            GLfloat p0 = p[i][0], p1 = p[i][1], p2 = p[i][2];
            q[i][2] = m2 * p0 + m6 * p1 + m10 * p2 + m14;
            q[i][3] = m3 * p0 + m7 * p1 + m11 * p2 + m15;
         }
      }
   }
}

void gl_xform_normals_3fv( GLuint n, GLfloat v[][3], const GLfloat m[16],
                           GLfloat u[][3], GLboolean normalize )
{
   if (normalize) {
      /* Transform normals and scale to unit length */
      GLuint i;
      GLfloat m0 = m[0],  m4 = m[4],  m8 = m[8];
      GLfloat m1 = m[1],  m5 = m[5],  m9 = m[9];
      GLfloat m2 = m[2],  m6 = m[6],  m10 = m[10];
      for (i=0;i<n;i++) {
         GLdouble tx, ty, tz;
         {
            GLfloat ux = u[i][0],  uy = u[i][1],  uz = u[i][2];
            tx = ux * m0 + uy * m1 + uz * m2;
            ty = ux * m4 + uy * m5 + uz * m6;
            tz = ux * m8 + uy * m9 + uz * m10;
         }
         {
            GLdouble len, scale;
            len = GL_SQRT( tx*tx + ty*ty + tz*tz );
            scale = (len>1E-30) ? (1.0 / len) : 1.0;
            v[i][0] = tx * scale;
            v[i][1] = ty * scale;
            v[i][2] = tz * scale;
         }
      }
   }
   else {
      /* Just transform normals, don't scale */
      GLuint i;
      GLfloat m0 = m[0],  m4 = m[4],  m8 = m[8];
      GLfloat m1 = m[1],  m5 = m[5],  m9 = m[9];
      GLfloat m2 = m[2],  m6 = m[6],  m10 = m[10];
      for (i=0;i<n;i++) {
         GLfloat ux = u[i][0],  uy = u[i][1],  uz = u[i][2];
         v[i][0] = ux * m0 + uy * m1 + uz * m2;
         v[i][1] = ux * m4 + uy * m5 + uz * m6;
         v[i][2] = ux * m8 + uy * m9 + uz * m10;
      }
   }
}

void gl_transform_vector( GLfloat u[4], const GLfloat v[4], const GLfloat m[16] )
{
   GLfloat v0=v[0], v1=v[1], v2=v[2], v3=v[3];
#define M(row,col)  m[col*4+row]
   u[0] = v0 * M(0,0) + v1 * M(1,0) + v2 * M(2,0) + v3 * M(3,0);
   u[1] = v0 * M(0,1) + v1 * M(1,1) + v2 * M(2,1) + v3 * M(3,1);
   u[2] = v0 * M(0,2) + v1 * M(1,2) + v2 * M(2,2) + v3 * M(3,2);
   u[3] = v0 * M(0,3) + v1 * M(1,3) + v2 * M(2,3) + v3 * M(3,3);
#undef M
}

