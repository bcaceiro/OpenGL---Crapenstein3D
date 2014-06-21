//
//  Ball.h
//  Crapenstein
//
//  Created by Bruno Caceiro on 21/06/14.
//  Copyright (c) 2014 Bruno Caceiro. All rights reserved.
//

#ifndef Crapenstein_Ball_h
#define Crapenstein_Ball_h

#include <stdio.h>
#include <assert.h>
#include "OpenGLIncludes.h"

class Ball
{
public:
    
    //Constructor
    Ball(GLfloat posX,GLfloat posY,GLfloat posZ, GLfloat ballRadius,GLfloat ballMaximumHeight, GLint ballDirection);
    
    //Destroy
    ~Ball();
    
    //Methods
    void update();
    
private:
    
    GLfloat radius;
    GLfloat maximumHeight;
    GLfloat x;
    GLfloat y;
    GLfloat z;
    GLint direction;
};

inline Ball::~Ball()
    {
    }
#endif // BALL_H



