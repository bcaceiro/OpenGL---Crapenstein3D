//
//  Robot.cpp
//  Crapenstein
//
//  Created by Bruno Caceiro on 20/06/14.
//  Copyright (c) 2014 Bruno Caceiro. All rights reserved.
//


#ifndef __ROBOT__
#define __ROBOT__

#include <stdio.h>
#include "Robot.h"
#include "OpenGLIncludes.h"


//Constructor
Robot::Robot(GLfloat robotPosX,GLfloat robotPosY,GLfloat robotPosZ, GLfloat RobotTorsoRadius) {
    
    //new Robot(8,5,3,1.3);
    
    posX = robotPosX;
    posY = robotPosY;
    posZ = robotPosZ;
    torsoRadius = RobotTorsoRadius;
}



void Robot::drawRobot() {
    
    //drawRobotHead(1.5,5,4.5,3);
    drawRobotHead(1.5,posX + torsoRadius,posY - 0.5,posZ);
    //drawRobotEyes(0.3, 4.3,5,4,1.4);
    drawRobotEyes(0.3, posX + torsoRadius - 0.7,posY,posZ + 1,1.4);
    //drawRobotTorso(1.3, 7.0, 5,5,3);
    drawRobotTorso(torsoRadius, 7.0, posX + torsoRadius, posY, posZ);
    //drawRobotArms(0.5, 3, 2, 4,3,3);
    drawRobotArms(0.5, 3, 2, posX + torsoRadius - 1,posY - 2,posZ);
    
}

void Robot::drawRobotEyes(GLfloat radius , GLfloat posX, GLfloat posY, GLfloat posZ, GLfloat eyeDistance) {
    
    //Eyes color = RED
    glColor4f(1.0, 0.0, 0.0, 1.0);
    
    /* Draw Right Eye */
    glPushMatrix();
        glTranslatef(posX,posY,posZ);
        glutSolidSphere(radius,32,32);
    glPopMatrix();
    
    /* Draw Left Eye */
    glPushMatrix();
        glTranslatef(posX + eyeDistance,posY,posZ);
        glutSolidSphere(radius,32,32);
    glPopMatrix();
    
}

void Robot::drawRobotHead(GLfloat radius , GLfloat posX, GLfloat posY, GLfloat posZ ) {
    // White Color
    glColor4f(1.0, 1.0, 1.0, 1.0);
    
    glPushMatrix();
        glTranslatef(posX,posY,posZ);
        glutSolidSphere(radius,32,32);
    glPopMatrix();
}


void Robot:: drawRobotTorso(GLfloat radius,GLfloat height, GLfloat posX, GLfloat posY, GLfloat posZ ) {

    //Green Color
    glColor4f(0.0, 1.0, 0.0, 1.0);
    
    glPushMatrix();
        glTranslatef(posX,posY,posZ);
        glRotatef(90.0,1.0,0.0,0.0);
        GLUquadricObj *quadratic;
        quadratic = gluNewQuadric();
        gluCylinder(quadratic,radius,radius,height,32,32);
    glPopMatrix();
    
}


void Robot:: drawRobotArms(GLfloat radius, GLfloat length, GLfloat armsDistance, GLfloat posX, GLfloat posY, GLfloat posZ ) {
    //Yellow Color
    glColor4f(1.0, 1.0, 0.0, 1.0);
    
    /* Right Arm */
    glPushMatrix();
        glTranslatef(posX,posY,posZ);
        glRotatef(90.0,0.0,0.0,1.0);
        GLUquadricObj *quadratic2;
        quadratic2 = gluNewQuadric();
        gluCylinder(quadratic2,radius,radius,length,32,32);
    glPopMatrix();
    
    /* Left Arm */
    glPushMatrix();
        glTranslatef(posX + armsDistance,posY,posZ);
        glRotatef(90.0,0.0,0.0,1.0);
        GLUquadricObj *quadratic3;
        quadratic3 = gluNewQuadric();
        gluCylinder(quadratic3,radius,radius,length,32,32);
    glPopMatrix();
}

#endif
