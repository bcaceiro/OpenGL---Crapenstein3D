//
//  Ball.cpp
//  Crapenstein
//
//  Created by Bruno Caceiro on 21/06/14.
//  Copyright (c) 2014 Bruno Caceiro. All rights reserved.
//


#include <stdio.h>
#include "Ball.h"
#include "OpenGLIncludes.h"

#ifndef __ROBOT__
#define __ROBOT__



//Constructor
Ball::Ball(GLfloat posX,GLfloat posY,GLfloat posZ, GLfloat ballRadius,GLfloat ballMaximumHeight, GLint ballDirection ) {
    
    //new Ball(15,5,3,1.3,8,1);
    x = posX;
    y = posY;
    z = posZ;
    radius = ballRadius;
    maximumHeight = ballMaximumHeight;
    direction = ballDirection;
}


/* Bouncing ball effect */
void Ball::update() {
    
    y += direction * 0.1;
    if (y > maximumHeight) {
        y = maximumHeight;
        direction = -1;
    } else if (y < radius) {
        y = radius;
        direction = 1;
    }
    glColor4f(1.0, 0.0, 0.0, 1.0);
    glPushMatrix();
    glTranslated(x, y, z);
    glutSolidSphere(radius, 30, 30);
    glPopMatrix();
    
}

#endif
