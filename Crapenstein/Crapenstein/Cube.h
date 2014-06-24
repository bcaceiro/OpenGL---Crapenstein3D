//
//  Cube.h
//  Crapenstein
//
//  Created by Bruno Caceiro on 24/06/14.
//  Copyright (c) 2014 Bruno Caceiro. All rights reserved.
//

#ifndef __Crapenstein__Cube__
#define __Crapenstein__Cube__

#include <iostream>

#include <stdio.h>
#include <assert.h>
#include "OpenGLIncludes.h"
#include "Wall.h"

class Cube
{
public:
    
    //Constructor
    Cube(GLfloat cubePosX, GLfloat cubePosY, GLfloat cubePosZ, GLfloat cubeSize, GLfloat alphaCube, GLfloat red,GLfloat green,GLfloat blue);
    
    //Destroy
    ~Cube();
    
    //Methods
    void draw();

    
private:
    

    GLfloat alpha;
    GLfloat posX;
    GLfloat posY;
    GLfloat posZ;
    GLfloat size;
    
    GLfloat r;
    GLfloat g;
    GLfloat b;
    

    
};

inline Cube::~Cube()
{
}

#endif

