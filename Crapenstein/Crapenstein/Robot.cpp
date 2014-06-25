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
#include <cmath>
#include "Robot.h"
#include "Camera.h"
#include "OpenGLIncludes.h"
#include "collidingObject.h"
#include "laser.h"

const float limit = 89.0 * M_PI / 180.0;

//Constructor
Robot::Robot(GLfloat robotPosX,GLfloat robotPosY,GLfloat robotPosZ, GLfloat RobotTorsoRadius, Camera * globalCamera) {
    
    //new Robot(8,5,3,1.3);
    this->m_yaw = 0.0;
    this->m_pitch = 0.0;
    posX = robotPosX;
    posY = robotPosY;
    //posY = 20;
    posZ = robotPosZ;
    torsoRadius = RobotTorsoRadius;
    cam = globalCamera;
    //set the camera position
    cam->SetPos(robotPosX-2,robotPosY+5,robotPosZ-2);
    //esta é precisa, para por o robot e a camera a apontar para o mesmo sitio
    cam->SetYaw(0.0);
    //esta é só para se ver logo o robot
    cam->SetPitch(-0.5);
    this->m_pitch = -0.5;
    for(int i =0; i < NUM_LASERS;++i){
        lasers[i] = NULL;
    }
    setRobotBounds();
}



void Robot::drawRobot() {
    
    glPushMatrix();
        glTranslatef(posX,posY,posZ);
        float aux = this->m_yaw-M_PI_2;
        aux = aux*180;
        aux = aux/M_PI;
        glRotatef(-aux,0,1,0);
        glTranslatef(-posX,-posY,-posZ);
        //drawRobotHead(1.5,5,4.5,3);
        drawRobotHead(1.5,posX,posY - 0.5,posZ);
        //laserPower(posX +0.5,posY - 0.1,posZ);
        //drawRobotEyes(0.3, 4.3,5,4,1.4);
        drawRobotEyes(0.3, posX - 0.7,posY,posZ + 1,1.4);
        //drawRobotTorso(1.3, 7.0, 5,5,3);
        drawRobotTorso(torsoRadius, 7.0, posX, posY, posZ);
        //drawRobotArms(0.5, 3, 2, 4,3,3);
        drawRobotArms(0.5, 3, 2, posX - 1,posY - 2,posZ);
    glPopMatrix();
    drawLasers();
    drawFlashLight();
    //drawBoundingBox();
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

void Robot::fireLaser()
{
    m_lx = cos(m_yaw) * cos(m_pitch+M_PI_4/2);
    m_ly = sin(m_pitch+M_PI_4/2);
    m_lz = sin(m_yaw) * cos(m_pitch+M_PI_4/2);
    for(int i=0; i < NUM_LASERS;++i){
        if(lasers[i]==NULL){
            lasers[i] = new Laser(posX,posY,posZ,m_lx,m_ly,m_lz,m_yaw-M_PI_4/4,m_pitch,GL_LIGHT7-i);
            return;
        }
    }
}

void Robot::drawLasers(){
    for(unsigned int i = 0; i < NUM_LASERS; ++i){
        if(lasers[i]!=NULL){
            lasers[i]->draw();
        }
    }
}

void Robot::updateLasers(){
    for(unsigned int i = 0; i < NUM_LASERS; ++i){
        if(lasers[i]!=NULL){
            lasers[i]->update();
            if(lasers[i]->isColliding()){
                delete lasers[i];
                lasers[i] = NULL;
                glDisable(GL_LIGHT7-i);
            }
        }
    }
}

void Robot::RotateYaw(float angle)
{
    m_yaw += angle;
}

void Robot::RotatePitch(float angle)
{
    m_pitch += angle;

    if(m_pitch < -limit)
        m_pitch = -limit;

    if(m_pitch > limit)
        m_pitch = limit;
}

void Robot::Strafe(float incr)
{
    m_strafe_lx = cos(m_yaw - M_PI_2);
    m_strafe_lz = sin(m_yaw - M_PI_2);

    posX = posX + incr*m_strafe_lx;
    posZ = posZ + incr*m_strafe_lz;

    setRobotBounds();
    unsigned int vector_size = collidableObjects.size();
    for(unsigned int i = 0; i < vector_size; ++i){
        if(((CollidingObject*)collidableObjects[i])->isColliding(this)){
            posX-=incr*m_strafe_lx;
            posZ-=incr*m_strafe_lz;
            setRobotBounds();
            return;
        }
    }
    setRobotBounds();
    cam->Strafe(incr);
}

void Robot::Move(float incr)
{
    float lx = cos(m_yaw)*cos(m_pitch);
    float ly = sin(m_pitch);
    float lz = sin(m_yaw)*cos(m_pitch);

    posX = posX + incr*lx;
    //this line is comment because the player can't move the camera vertically?
    //m_y = m_y + incr*ly;
    posZ = posZ + incr*lz;


    setRobotBounds();
    unsigned int vector_size = collidableObjects.size();
    for(unsigned int i = 0; i < vector_size; ++i){
        if(((CollidingObject*)collidableObjects[i])->isColliding(this)){
            //printf("COLIDIU, NÃO MEXER!\n");
            posZ-=incr*lz;
            posX-=incr*lx;
            setRobotBounds();
            return;
        }
    }
    setRobotBounds();
    cam->Move(incr);
}

void Robot::drawFlashLight(){
    glEnable(GL_LIGHT3);
    GLfloat x,y,z;
    cam->GetDirectionVector(x,y,z);


    m_lx = cos(m_yaw) * cos(m_pitch-M_PI_4);
    m_ly = sin(m_pitch-M_PI_4);
    m_lz = sin(m_yaw) * cos(m_pitch-M_PI_4);
   /* m_lx = cos(m_yaw) * cos(m_pitch);
    m_ly = sin(m_pitch);
    m_lz = sin(m_yaw) * cos(m_pitch);*/


    GLfloat lightTarget[3] = {m_lx, m_ly, m_lz};
    //GLfloat lightTarget[4] = {0, -1, 0, 1.0};
    //GLfloat lightPos[4] = {posX, posY, posZ,1.0};
    GLfloat lightPos[4] = {posX, posY, posZ,1.0};
    GLfloat lightColor[4] = {0.4,0.4,0.4,1};
    glLightfv(GL_LIGHT3,GL_AMBIENT, lightColor);
    glLightfv(GL_LIGHT3,GL_DIFFUSE, lightColor);
    glLightfv(GL_LIGHT3,GL_SPECULAR, lightColor);

    glLightf(GL_LIGHT3,GL_CONSTANT_ATTENUATION,		1);
    glLightf(GL_LIGHT3,GL_LINEAR_ATTENUATION,		0.0);
    glLightf(GL_LIGHT3,GL_QUADRATIC_ATTENUATION,	0.0);

    glLightfv(GL_LIGHT3,GL_POSITION, lightPos);
    glLightfv(GL_LIGHT3,GL_SPOT_DIRECTION,lightTarget);
    glLightf(GL_LIGHT3,GL_SPOT_CUTOFF,              15);
    glLightf(GL_LIGHT3,GL_SPOT_EXPONENT,			5);
}

void Robot::setRobotBounds(){
    setBounds(posX-2,posY-2,posZ-2,4,2,4);
}

#endif
