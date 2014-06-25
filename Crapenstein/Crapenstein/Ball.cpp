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
    GLfloat  esmeraldAmb []={ 0.0215 ,0.1745 ,0.0215 };
    GLfloat  esmeraldDif []={   0.07568 ,0.61424 ,0.07568 };
    GLfloat  esmeraldSpec []={ 0.633 ,0.727811 ,0.633 };
    GLint    esmeraldCoef = 0.6 *128;
    glPushMatrix();
        glDisable(GL_COLOR_MATERIAL);
        glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE );
        glMaterialfv(GL_FRONT, GL_AMBIENT, esmeraldAmb);
        glMaterialfv(GL_FRONT, GL_DIFFUSE, esmeraldDif);
        glMaterialfv(GL_BACK, GL_AMBIENT, esmeraldAmb);
        glMaterialfv(GL_BACK, GL_DIFFUSE, esmeraldDif);
        glMaterialfv(GL_FRONT, GL_SPECULAR, esmeraldSpec);
        glMateriali(GL_FRONT, GL_SHININESS, esmeraldCoef);
        glMaterialfv(GL_BACK, GL_SPECULAR, esmeraldSpec);
        glMateriali(GL_BACK, GL_SHININESS, esmeraldCoef);
        GLUquadricObj *quadratic3;
        quadratic3 = gluNewQuadric();
        glColor4f(1.0, 1.0, 1.0, 1.0);

        gluQuadricOrientation(quadratic3,GLU_OUTSIDE);
        glTranslated(x, y, z);
        glutSolidSphere(radius, 30, 30);
    glPopMatrix();
    glEnable(GL_COLOR_MATERIAL);

}

#endif
