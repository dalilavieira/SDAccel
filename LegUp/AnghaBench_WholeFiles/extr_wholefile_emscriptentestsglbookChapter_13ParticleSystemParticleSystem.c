#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_12__   TYPE_2__ ;
typedef  struct TYPE_11__   TYPE_1__ ;

/* Type definitions */
struct TYPE_11__ {float time; scalar_t__ textureId; int /*<<< orphan*/  programObject; void* samplerLoc; void* startPositionLoc; void* endPositionLoc; void* lifetimeLoc; int /*<<< orphan*/  vertexObject; void* timeLoc; void* colorLoc; void* centerPositionLoc; int /*<<< orphan*/ * particleData; } ;
typedef  TYPE_1__ UserData ;
struct TYPE_12__ {TYPE_1__* userData; int /*<<< orphan*/  eglSurface; int /*<<< orphan*/  eglDisplay; int /*<<< orphan*/  height; int /*<<< orphan*/  width; } ;
typedef  scalar_t__ GLuint ;
typedef  int /*<<< orphan*/  GLfloat ;
typedef  char GLbyte ;
typedef  TYPE_2__ ESContext ;

/* Variables and functions */
 int /*<<< orphan*/  ES_WINDOW_RGB ; 
 int FALSE ; 
 int /*<<< orphan*/  GL_ARRAY_BUFFER ; 
 int /*<<< orphan*/  GL_BLEND ; 
 int /*<<< orphan*/  GL_CLAMP_TO_EDGE ; 
 int /*<<< orphan*/  GL_COLOR_BUFFER_BIT ; 
 int /*<<< orphan*/  GL_FALSE ; 
 int /*<<< orphan*/  GL_FLOAT ; 
 int /*<<< orphan*/  GL_LINEAR ; 
 int /*<<< orphan*/  GL_ONE ; 
 int /*<<< orphan*/  GL_POINTS ; 
 int /*<<< orphan*/  GL_RGB ; 
 int /*<<< orphan*/  GL_SRC_ALPHA ; 
 int /*<<< orphan*/  GL_STATIC_DRAW ; 
 int /*<<< orphan*/  GL_TEXTURE0 ; 
 int /*<<< orphan*/  GL_TEXTURE_2D ; 
 int /*<<< orphan*/  GL_TEXTURE_MAG_FILTER ; 
 int /*<<< orphan*/  GL_TEXTURE_MIN_FILTER ; 
 int /*<<< orphan*/  GL_TEXTURE_WRAP_S ; 
 int /*<<< orphan*/  GL_TEXTURE_WRAP_T ; 
 int /*<<< orphan*/  GL_UNSIGNED_BYTE ; 
 int NUM_PARTICLES ; 
 int PARTICLE_SIZE ; 
 int TRUE ; 
 int /*<<< orphan*/  eglSwapBuffers (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  esCreateWindow (TYPE_2__*,char*,int,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  esInitContext (TYPE_2__*) ; 
 int /*<<< orphan*/  esLoadProgram (char*,char*) ; 
 char* esLoadTGA (char*,int*,int*) ; 
 int /*<<< orphan*/  esLogMessage (char*,char*) ; 
 int /*<<< orphan*/  esRegisterDrawFunc (TYPE_2__*,void (*) (TYPE_2__*)) ; 
 int /*<<< orphan*/  free (char*) ; 
 int /*<<< orphan*/  glActiveTexture (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  glBindBuffer (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  glBindTexture (int /*<<< orphan*/ ,scalar_t__) ; 
 int /*<<< orphan*/  glBlendFunc (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  glBufferData (int /*<<< orphan*/ ,int,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  glClear (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  glClearColor (float,float,float,float) ; 
 int /*<<< orphan*/  glDeleteProgram (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  glDeleteTextures (int,scalar_t__*) ; 
 int /*<<< orphan*/  glDrawArrays (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  glEnable (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  glEnableVertexAttribArray (void*) ; 
 int /*<<< orphan*/  glGenBuffers (int,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  glGenTextures (int,scalar_t__*) ; 
 void* glGetAttribLocation (int /*<<< orphan*/ ,char*) ; 
 void* glGetUniformLocation (int /*<<< orphan*/ ,char*) ; 
 int /*<<< orphan*/  glTexImage2D (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int,int,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,char*) ; 
 int /*<<< orphan*/  glTexParameteri (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  glUniform1f (void*,float) ; 
 int /*<<< orphan*/  glUniform1i (void*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  glUniform3fv (void*,int,float*) ; 
 int /*<<< orphan*/  glUniform4fv (void*,int,float*) ; 
 int /*<<< orphan*/  glUseProgram (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  glVertexAttribPointer (void*,int,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int,int) ; 
 int /*<<< orphan*/  glViewport (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int randomTemp ; 

float myrandom() {
  int curr = randomTemp;
  randomTemp = (1140671485 * randomTemp + 12820163) % 4294967296;
  return ((float)curr) / 4294967296;
}

GLuint LoadTexture ( char *fileName )
{
   int width,
       height;
   char *buffer = esLoadTGA ( fileName, &width, &height );
   GLuint texId;

   if ( buffer == NULL )
   {
      esLogMessage ( "Error loading (%s) image.\n", fileName );
      return 0;
   }

   glGenTextures ( 1, &texId );
   glBindTexture ( GL_TEXTURE_2D, texId );

   glTexImage2D ( GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, buffer );
   glTexParameteri ( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR );
   glTexParameteri ( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR );
   glTexParameteri ( GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE );
   glTexParameteri ( GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE );

   free ( buffer );

   return texId;
}

int Init ( ESContext *esContext )
{
   UserData *userData = esContext->userData;
   int i;
   
   GLbyte vShaderStr[] =
      "uniform float u_time;		                           \n"
      "uniform vec3 u_centerPosition;                       \n"
      "attribute float a_lifetime;                          \n"
      "attribute vec3 a_startPosition;                      \n"
      "attribute vec3 a_endPosition;                        \n"
      "varying float v_lifetime;                            \n"
      "void main()                                          \n"
      "{                                                    \n"
      "  if ( u_time <= a_lifetime )                        \n"
      "  {                                                  \n"
      "    gl_Position.xyz = a_startPosition +              \n"
      "                      (u_time * a_endPosition);      \n"
      "    gl_Position.xyz += u_centerPosition;             \n"
      "    gl_Position.w = 1.0;                             \n"
      "  }                                                  \n"
      "  else                                               \n"
      "     gl_Position = vec4( -1000, -1000, 0, 0 );       \n"
      "  v_lifetime = 1.0 - ( u_time / a_lifetime );        \n"
      "  v_lifetime = clamp ( v_lifetime, 0.0, 1.0 );       \n"
      "  gl_PointSize = ( v_lifetime * v_lifetime ) * 40.0; \n"
      "}";
      
   GLbyte fShaderStr[] =  
      "precision mediump float;                             \n"
      "uniform vec4 u_color;		                           \n"
      "varying float v_lifetime;                            \n"
      "uniform sampler2D s_texture;                         \n"
      "void main()                                          \n"
      "{                                                    \n"
      "  vec4 texColor;                                     \n"
      "  texColor = texture2D( s_texture, gl_PointCoord );  \n"
      "  gl_FragColor = vec4( u_color ) * texColor;         \n"
      "  gl_FragColor.a *= v_lifetime;                      \n"
      "}                                                    \n";

   // Load the shaders and get a linked program object
   userData->programObject = esLoadProgram ( vShaderStr, fShaderStr );

   // Get the attribute locations
   userData->lifetimeLoc = glGetAttribLocation ( userData->programObject, "a_lifetime" );
   userData->startPositionLoc = glGetAttribLocation ( userData->programObject, "a_startPosition" );
   userData->endPositionLoc = glGetAttribLocation ( userData->programObject, "a_endPosition" );
   
   // Get the uniform locations
   userData->timeLoc = glGetUniformLocation ( userData->programObject, "u_time" );
   userData->centerPositionLoc = glGetUniformLocation ( userData->programObject, "u_centerPosition" );
   userData->colorLoc = glGetUniformLocation ( userData->programObject, "u_color" );
   userData->samplerLoc = glGetUniformLocation ( userData->programObject, "s_texture" );

   glClearColor ( 0.0f, 0.0f, 0.0f, 1.0f );

   // Fill in particle data array
   for ( i = 0; i < NUM_PARTICLES; i++ )
   {
      GLfloat *particleData = &userData->particleData[i * PARTICLE_SIZE];
   
      // Lifetime of particle
      (*particleData++) = myrandom();

      // End position of particle
      (*particleData++) = myrandom() * 2 - 1.0f;
      (*particleData++) = myrandom() * 2 - 1.0f;
      (*particleData++) = myrandom() * 2 - 1.0f;

      // Start position of particle
      (*particleData++) = myrandom() * 0.25 - 0.125f;
      (*particleData++) = myrandom() * 0.25 - 0.125f;
      (*particleData++) = myrandom() * 0.25 - 0.125f;
   }

   glGenBuffers(1, &userData->vertexObject);
   glBindBuffer( GL_ARRAY_BUFFER, userData->vertexObject );
   glBufferData( GL_ARRAY_BUFFER, NUM_PARTICLES * PARTICLE_SIZE * 4, userData->particleData, GL_STATIC_DRAW );

   // Initialize time to cause reset on first update
   userData->time = 1.0f;

   userData->textureId = LoadTexture ( "smoke.tga" );
   if ( userData->textureId <= 0 )
   {
      return FALSE;
   }
   
   return TRUE;
}

void Update ( ESContext *esContext, float deltaTime )
{
//  deltaTime = 0.1;
   UserData *userData = esContext->userData;
  
   userData->time += deltaTime;

   if ( userData->time >= 1.0f )
   {
      float centerPos[3];
      float color[4];

      userData->time = 0.0f;

      // Pick a new start location and color
      centerPos[0] = myrandom() - 0.5f;
      centerPos[1] = myrandom() - 0.5f;
      centerPos[2] = myrandom() - 0.5f;
      
      glUniform3fv ( userData->centerPositionLoc, 1, &centerPos[0] );

      // Random color
      color[0] = myrandom() * 0.5 + 0.5f;
      color[1] = myrandom() * 0.5 + 0.5f;
      color[2] = myrandom() * 0.5 + 0.5f;
      color[3] = 1.0;

      glUniform4fv ( userData->colorLoc, 1, &color[0] );
   }

   // Load uniform time variable
   glUniform1f ( userData->timeLoc, userData->time );
}

void Draw ( ESContext *esContext )
{
   UserData *userData = esContext->userData;
      
   // Set the viewport
   glViewport ( 0, 0, esContext->width, esContext->height );
   
   // Clear the color buffer
   glClear ( GL_COLOR_BUFFER_BIT );

   // Use the program object
   glUseProgram ( userData->programObject );

   // Load the vertex attributes
   glBindBuffer( GL_ARRAY_BUFFER, userData->vertexObject );
   glVertexAttribPointer ( userData->lifetimeLoc, 1, GL_FLOAT, 
                           GL_FALSE, PARTICLE_SIZE * sizeof(GLfloat), 
                           0 );
   
   glVertexAttribPointer ( userData->endPositionLoc, 3, GL_FLOAT,
                           GL_FALSE, PARTICLE_SIZE * sizeof(GLfloat),
                           4 );

   glVertexAttribPointer ( userData->startPositionLoc, 3, GL_FLOAT,
                           GL_FALSE, PARTICLE_SIZE * sizeof(GLfloat),
                           4 * 4 );

   
   glEnableVertexAttribArray ( userData->lifetimeLoc );
   glEnableVertexAttribArray ( userData->endPositionLoc );
   glEnableVertexAttribArray ( userData->startPositionLoc );
   // Blend particles
   glEnable ( GL_BLEND );
   glBlendFunc ( GL_SRC_ALPHA, GL_ONE );

   // Bind the texture
   glActiveTexture ( GL_TEXTURE0 );
   glBindTexture ( GL_TEXTURE_2D, userData->textureId );
   //glEnable ( GL_TEXTURE_2D );

   // Set the sampler texture unit to 0
   glUniform1i ( userData->samplerLoc, 0 );

   Update ( esContext, 133 * 0.001125 );

   glDrawArrays( GL_POINTS, 0, NUM_PARTICLES );
   
   eglSwapBuffers ( esContext->eglDisplay, esContext->eglSurface );
}

void ShutDown ( ESContext *esContext )
{
   UserData *userData = esContext->userData;

   // Delete texture object
   glDeleteTextures ( 1, &userData->textureId );

   // Delete program object
   glDeleteProgram ( userData->programObject );
}

int main ( int argc, char *argv[] )
{
   ESContext esContext;
   UserData  userData;

   esInitContext ( &esContext );
   esContext.userData = &userData;

   esCreateWindow ( &esContext, "ParticleSystem", 320, 240, ES_WINDOW_RGB );
   
   if ( !Init ( &esContext ) )
      return 0;

   esRegisterDrawFunc ( &esContext, Draw );
//   esRegisterUpdateFunc ( &esContext, Update );
   
   Draw (&esContext);
  Draw (&esContext);
  //esMainLoop ( &esContext );

   ShutDown ( &esContext );
}

