//
//  OpenGLIncludes.h
//  Crapenstein
//
//  Created by Bruno Caceiro on 23/05/14.
//  Copyright (c) 2014 Bruno Caceiro. All rights reserved.
//

#ifndef Crapenstein_OpenGLIncludes_h
#define Crapenstein_OpenGLIncludes_h

#ifdef __APPLE__
#include <GLUT/glut.h>
#include <OpenGL/gl.h>
#else
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/freeglut.h>
#endif

#include <cmath>
#include <vector>
#include <iostream>
//#include "materiais.h"

#define AZUL 0.0, 0.0, 1.0, 1.0
#define BLUE     0.0, 0.0, 1.0, 1.0

#define VERMELHO 1.0, 0.0, 0.0, 1.0
#define RED      1.0, 0.0, 0.0, 1.0

#define VERDE   0.0, 1.0, 0.0, 1.0
#define GREEN    0.0, 1.0, 0.0, 1.0

#define BRANCO 1.0, 1.0, 1.0, 1.0
#define WHITE    1.0, 1.0, 1.0, 1.0

#define YELLOW  1.0, 1.0, 0.0, 1.0
#define ORANGE   1.0, 0.5, 0.1, 1.0
#define BLACK    0.0, 0.0, 0.0, 1.0
#define GRAY     0.9, 0.92, 0.29, 1.0

#define PI		 3.14159

using namespace std;

#endif
