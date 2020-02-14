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
typedef  void* GLuint ;
typedef  float GLfloat ;
typedef  int /*<<< orphan*/  GLchar ;

/* Variables and functions */
 int /*<<< orphan*/  BUFFER_OFFSET (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  EM_ASM (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  GLFW_FSAA_SAMPLES ; 
 int /*<<< orphan*/  GLFW_WINDOW ; 
 int /*<<< orphan*/  GL_ARRAY_BUFFER ; 
 int GL_COLOR_BUFFER_BIT ; 
 int GL_DEPTH_BUFFER_BIT ; 
 int /*<<< orphan*/  GL_DEPTH_TEST ; 
 int /*<<< orphan*/  GL_FALSE ; 
 int /*<<< orphan*/  GL_FLOAT ; 
 int GL_FRAGMENT_SHADER ; 
 int /*<<< orphan*/  GL_KEEP ; 
 int /*<<< orphan*/  GL_LEQUAL ; 
 int /*<<< orphan*/  GL_REPLACE ; 
 int /*<<< orphan*/  GL_RGBA ; 
 int /*<<< orphan*/  GL_STATIC_DRAW ; 
 int GL_STENCIL_BUFFER_BIT ; 
 int /*<<< orphan*/  GL_STENCIL_TEST ; 
 int /*<<< orphan*/  GL_TRIANGLES ; 
 int /*<<< orphan*/  GL_UNSIGNED_BYTE ; 
 int GL_VERTEX_SHADER ; 
 int /*<<< orphan*/  REPORT_RESULT (int) ; 
 int WINDOWS_SIZE ; 
 int alphaActivated ; 
 int antiAliasingActivated ; 
 int /*<<< orphan*/  assert (int) ; 
 float* backgroundColor ; 
 int depthActivated ; 
 char* fragmentShaderSrc ; 
 int /*<<< orphan*/  glAttachShader (void*,void*) ; 
 int /*<<< orphan*/  glBindBuffer (int /*<<< orphan*/ ,void*) ; 
 int /*<<< orphan*/  glBufferData (int /*<<< orphan*/ ,int,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  glClear (int) ; 
 int /*<<< orphan*/  glClearColor (float,float,float,double) ; 
 int /*<<< orphan*/  glClearStencil (int) ; 
 int /*<<< orphan*/  glCompileShader (void*) ; 
 void* glCreateProgram () ; 
 void* glCreateShader (int) ; 
 int /*<<< orphan*/  glDepthFunc (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  glDisable (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  glDrawArrays (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  glEnable (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  glEnableVertexAttribArray (void*) ; 
 int /*<<< orphan*/  glFinish () ; 
 int /*<<< orphan*/  glGenBuffers (int,void**) ; 
 void* glGetAttribLocation (void*,char*) ; 
 void* glGetUniformLocation (void*,char*) ; 
 int /*<<< orphan*/  glLinkProgram (void*) ; 
 int /*<<< orphan*/  glReadPixels (int,int,int,int,int /*<<< orphan*/ ,int /*<<< orphan*/ ,unsigned char*) ; 
 int /*<<< orphan*/  glShaderSource (void*,int,int /*<<< orphan*/  const**,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  glStencilFunc (int /*<<< orphan*/ ,int,int) ; 
 int /*<<< orphan*/  glStencilOp (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  glUniform4f (void*,unsigned char,unsigned char,unsigned char,unsigned char) ; 
 int /*<<< orphan*/  glUniformMatrix4fv (void*,int,int /*<<< orphan*/ ,float*) ; 
 int /*<<< orphan*/  glUseProgram (void*) ; 
 int /*<<< orphan*/  glVertexAttribPointer (void*,int,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  glViewport (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int,int) ; 
 int /*<<< orphan*/  glewInit () ; 
 int /*<<< orphan*/  glfwInit () ; 
 int /*<<< orphan*/  glfwOpenWindow (int,int,int,int,int,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  glfwOpenWindowHint (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  glfwTerminate () ; 
 int /*<<< orphan*/  memset (float*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  nbAlphaBits ; 
 int /*<<< orphan*/  nbDepthBits ; 
 int /*<<< orphan*/  nbSamples ; 
 int /*<<< orphan*/  nbStencilBits ; 
 int /*<<< orphan*/  out (char) ; 
 int result ; 
 int resultAA ; 
 int resultAlpha ; 
 int resultDepth ; 
 int resultStencil ; 
 void* shaderProgram ; 
 int stencilActivated ; 
 unsigned char* triangleColor ; 
 unsigned char* triangleColor2 ; 
 char* vertexShaderSrc ; 
 int /*<<< orphan*/  vertices ; 
 int /*<<< orphan*/  vertices2 ; 
 void* verticesVBO ; 
 void* verticesVBO2 ; 
 int /*<<< orphan*/  webglAlphaSupported () ; 
 int /*<<< orphan*/  webglAntialiasSupported () ; 
 int /*<<< orphan*/  webglDepthSupported () ; 
 int /*<<< orphan*/  webglStencilSupported () ; 

__attribute__((used)) static GLuint createShader(const char *source, int type) {
    GLuint shader = glCreateShader(type);
    glShaderSource(shader, 1, (const GLchar**)(&source), NULL);
    glCompileShader(shader);
    return shader;
}

__attribute__((used)) static GLuint createShaderProgram(const char *vertexShaderSrc, const char *fragmentShaderSrc) {
    GLuint program = glCreateProgram();
    glAttachShader(program, createShader(vertexShaderSrc, GL_VERTEX_SHADER));
    glAttachShader(program, createShader(fragmentShaderSrc, GL_FRAGMENT_SHADER));
    glLinkProgram(program);
    return program;
}

void ortho(float  left,  float  right,  float  bottom,  float  top,  float  nearVal,  float  farVal, GLfloat *projMatrix) {
    float tx = -(right+left)/(right-left);
    float ty = -(top+bottom)/(top-bottom);
    float tz = -(farVal+nearVal)/(farVal-nearVal);
    memset(projMatrix, 0, 16 * sizeof(GLfloat));
    projMatrix[0] = 2.0f / (right-left);
    projMatrix[3] = tx;
    projMatrix[1*4+1] = 2.0f / (top-bottom);
    projMatrix[1*4+3] = ty;
    projMatrix[2*4+2] = -2.0f / (farVal-nearVal);
    projMatrix[2*4+3] = tz;
    projMatrix[3*4+3] = 1.0f;
}

__attribute__((used)) static void initGlObjects() {
    glGenBuffers(1, &verticesVBO);
    glBindBuffer(GL_ARRAY_BUFFER, verticesVBO);
    glBufferData(GL_ARRAY_BUFFER, 9*sizeof(float), vertices, GL_STATIC_DRAW);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    
    glGenBuffers(1, &verticesVBO2);
    glBindBuffer(GL_ARRAY_BUFFER, verticesVBO2);
    glBufferData(GL_ARRAY_BUFFER, 9*sizeof(float), vertices2, GL_STATIC_DRAW);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    
    shaderProgram = createShaderProgram(vertexShaderSrc, fragmentShaderSrc);
}

__attribute__((used)) static void drawTriangle(GLuint verticesVBO, unsigned char r, unsigned char g, unsigned char b, unsigned char a) {
    glUseProgram(shaderProgram);
    GLuint posLoc = glGetAttribLocation(shaderProgram, "a_position");
    GLuint mvpLoc = glGetUniformLocation(shaderProgram, "u_mvpMatrix");
    GLuint colorLoc = glGetUniformLocation(shaderProgram, "u_color");
    
    GLfloat mvpMat[16];
    ortho(-WINDOWS_SIZE/2, WINDOWS_SIZE/2, -WINDOWS_SIZE/2, WINDOWS_SIZE/2, -100, 100, mvpMat);
    
    glUniformMatrix4fv(mvpLoc, 1, GL_FALSE, mvpMat);
    glUniform4f(colorLoc, r/255.f, g/255.f, b/255.f, a/255.f);
    
    glBindBuffer(GL_ARRAY_BUFFER, verticesVBO);  
    glEnableVertexAttribArray(posLoc);
    glVertexAttribPointer(posLoc, 3, GL_FLOAT, GL_FALSE, 3*sizeof(float), BUFFER_OFFSET(0));
    
    glDrawArrays(GL_TRIANGLES, 0, 3);
    
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glUseProgram(0);
}

__attribute__((used)) static bool testAntiAliasing(bool activated) {
    glViewport(0, 0, WINDOWS_SIZE, WINDOWS_SIZE);
    glClearColor(backgroundColor[0]/255.f, backgroundColor[1]/255.f, backgroundColor[2]/255.f, backgroundColor[3]/255.f);
    glClear(GL_COLOR_BUFFER_BIT);
    
    drawTriangle(verticesVBO, triangleColor[0], triangleColor[1], triangleColor[2], triangleColor[3]);
    
    bool antialiased = false;
    
    unsigned char buffer[(WINDOWS_SIZE*WINDOWS_SIZE)*4];
    glReadPixels(0, 0, WINDOWS_SIZE, WINDOWS_SIZE, GL_RGBA, GL_UNSIGNED_BYTE, &buffer[0]);
    glFinish();
    for (unsigned int i = 0 ; i < WINDOWS_SIZE ; ++i) {
      for (unsigned int j = 0 ; j < WINDOWS_SIZE ; ++j) {
        unsigned char r = buffer[4*(i*WINDOWS_SIZE+j)];
        unsigned char g = buffer[4*(i*WINDOWS_SIZE+j)+1];
        unsigned char b = buffer[4*(i*WINDOWS_SIZE+j)+2];
        unsigned char a = buffer[4*(i*WINDOWS_SIZE+j)+3];
        if ((r == backgroundColor[0] && g == backgroundColor[1] && b == backgroundColor[2] && a == backgroundColor[3]) || 
            (r == triangleColor[0] && g == triangleColor[1] && b == triangleColor[2] && a == triangleColor[3])) {
          continue;
        } else {
          antialiased = true;
          break;
        }
      }
    }
    
    return (activated && antialiased) || (!activated && !antialiased);
}

__attribute__((used)) static bool testDepth(bool activated) {
    glViewport(0, 0, WINDOWS_SIZE, WINDOWS_SIZE);
    glClearColor(backgroundColor[0]/255.f, backgroundColor[1]/255.f, backgroundColor[2]/255.f, backgroundColor[3]/255.f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);
    
    drawTriangle(verticesVBO, triangleColor[0], triangleColor[1], triangleColor[2], triangleColor[3]);
    drawTriangle(verticesVBO2, triangleColor2[0], triangleColor2[1], triangleColor2[2], triangleColor2[3]);
    
    glDisable(GL_DEPTH_TEST);
    
    // read the pixel at the center of the resulting image.
    unsigned char buffer[4];
    glReadPixels(WINDOWS_SIZE/2, WINDOWS_SIZE/2, 1, 1, GL_RGBA, GL_UNSIGNED_BYTE, &buffer[0]);
    
    bool frontTriangleColor = (buffer[0] == triangleColor[0] && buffer[1] == triangleColor[1] &&
                               buffer[2] == triangleColor[2] && buffer[3] == triangleColor[3]);
    
    bool backTriangleColor = (buffer[0] == triangleColor2[0] && buffer[1] == triangleColor2[1] &&
                              buffer[2] == triangleColor2[2] && buffer[3] == triangleColor2[3]);
    
    return (activated && frontTriangleColor) || (!activated && backTriangleColor);
}

__attribute__((used)) static bool testStencil(bool activated) {
    glViewport(0, 0, WINDOWS_SIZE, WINDOWS_SIZE);
    glClearColor(backgroundColor[0]/255.f, backgroundColor[1]/255.f, backgroundColor[2]/255.f, backgroundColor[3]/255.f);
    glClearStencil(0xFF);
    glStencilOp(GL_KEEP,GL_KEEP,GL_REPLACE);
    glClear(GL_COLOR_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);
    
    glEnable(GL_STENCIL_TEST);
    
    glStencilFunc(GL_LEQUAL, 0x1, 0xFF);
    drawTriangle(verticesVBO, triangleColor[0], triangleColor[1], triangleColor[2], triangleColor[3]);
    
    glStencilFunc(GL_LEQUAL, 0xFF, 0xFF);
    drawTriangle(verticesVBO, triangleColor2[0], triangleColor2[1], triangleColor2[2], triangleColor2[3]);
    
    glDisable(GL_STENCIL_TEST);
    
    unsigned char buffer[4];
    glReadPixels(WINDOWS_SIZE/2, WINDOWS_SIZE/2, 1, 1, GL_RGBA, GL_UNSIGNED_BYTE, &buffer[0]);
    
    bool firstTriangleColor = (buffer[0] == triangleColor[0] && buffer[1] == triangleColor[1] &&
                               buffer[2] == triangleColor[2] && buffer[3] == triangleColor[3]);
    
    bool secondTriangleColor = (buffer[0] == triangleColor2[0] && buffer[1] == triangleColor2[1] &&
                                buffer[2] == triangleColor2[2] && buffer[3] == triangleColor2[3]);
    
    return (activated && firstTriangleColor) || (!activated && secondTriangleColor);
}

__attribute__((used)) static bool testAlpha(bool activated) {
    glViewport(0, 0, WINDOWS_SIZE, WINDOWS_SIZE);
    glClearColor(backgroundColor[0]/255.f, backgroundColor[1]/255.f, backgroundColor[2]/255.f, 0.0);
    glClear(GL_COLOR_BUFFER_BIT);
    
    bool hasAlpha = true;
    
    unsigned char buffer[(WINDOWS_SIZE*WINDOWS_SIZE)*4];
    glReadPixels(0, 0, WINDOWS_SIZE, WINDOWS_SIZE, GL_RGBA, GL_UNSIGNED_BYTE, &buffer[0]);
    glFinish();
    for (unsigned int i = 0 ; i < WINDOWS_SIZE ; ++i) {
      for (unsigned int j = 0 ; j < WINDOWS_SIZE ; ++j) {
        unsigned char r = buffer[4*(i*WINDOWS_SIZE+j)];
        unsigned char g = buffer[4*(i*WINDOWS_SIZE+j)+1];
        unsigned char b = buffer[4*(i*WINDOWS_SIZE+j)+2];
        unsigned char a = buffer[4*(i*WINDOWS_SIZE+j)+3];
        if (r == backgroundColor[0] && g == backgroundColor[1] && b == backgroundColor[2] && a == 0) {
          continue;
        } else {
          hasAlpha = false;
          break;
        }
      }
    }
    
    return (activated && hasAlpha) || (!activated && !hasAlpha);
}

__attribute__((used)) static void draw() {
  if (!resultAA) resultAA = testAntiAliasing(antiAliasingActivated);
  assert(resultAA);
   
  if (!resultDepth) resultDepth = testDepth(depthActivated);
  assert(resultDepth);
  
  if (!resultStencil) resultStencil = testStencil(stencilActivated);
  assert(resultStencil);
  
  if (!resultAlpha) resultAlpha = testAlpha(alphaActivated);
  assert(resultAlpha);
  
  result = resultAA && resultDepth && resultStencil && resultAlpha;
}

__attribute__((used)) static void checkContextAttributesSupport() {
  if (!webglAntialiasSupported()) {
    resultAA = true;
    EM_ASM(out('warning: no antialiasing\n'));
  }
  if (!webglDepthSupported()) {
    resultDepth = true;
    EM_ASM(out('warning: no depth\n'));
  }
  if (!webglStencilSupported()) {
    resultStencil = true;
    EM_ASM(out('warning: no stencil\n'));
  }
  if (!webglAlphaSupported()) {
    resultAlpha = true;
    EM_ASM(out('warning: no alpha\n'));
  }
}

int main() {
  
    checkContextAttributesSupport();
  
    glfwInit();
  
#ifdef AA_ACTIVATED
    antiAliasingActivated = true;
    nbSamples = 4;
#endif
  
#ifdef DEPTH_ACTIVATED
    depthActivated = true;
    nbDepthBits = 16;
#endif  
  
#ifdef STENCIL_ACTIVATED
    stencilActivated = true;  
    nbStencilBits = 8;
#endif
  
#ifdef ALPHA_ACTIVATED
    alphaActivated = true;  
    nbAlphaBits = 8;
#endif

    glfwOpenWindowHint(GLFW_FSAA_SAMPLES, nbSamples);
    glfwOpenWindow(WINDOWS_SIZE, WINDOWS_SIZE, 8, 8, 8, nbAlphaBits, nbDepthBits, nbStencilBits, GLFW_WINDOW);
  
    glewInit();
    initGlObjects();

    draw();
  
    glfwTerminate();
  
    REPORT_RESULT(result);
  
    return 0;

}

