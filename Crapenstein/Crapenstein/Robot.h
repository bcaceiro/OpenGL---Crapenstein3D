//
//  Robot.h
//  Crapenstein
//
//  Created by Bruno Caceiro on 20/06/14.
//  Copyright (c) 2014 Bruno Caceiro. All rights reserved.
//

#ifndef ROBOT_H
#define ROBOT_H
#include <stdio.h>
#include <assert.h>
#include "OpenGLIncludes.h"
#include "Camera.h"
#include <vector>
#include "collidingObject.h"

using namespace std;
extern vector<CollidingObject*> collidableObjects;
extern vector<CollidingObject*>::iterator collidableObjectsIterator;


class Robot : public CollidingObject
{
public:
    
    //Constructor
    Robot(GLfloat robotPosX, GLfloat robotPosY,GLfloat robotPosZ, GLfloat torsoRadius, Camera * globalCamera);
    
    //Destroy
    ~Robot();
    
    //Methods
    void drawRobot();
    void drawRobotEyes(GLfloat radius , GLfloat posX, GLfloat posY, GLfloat posZ, GLfloat eyeDistance);
    void drawRobotHead(GLfloat radius , GLfloat posX, GLfloat posY, GLfloat posZ);
    void drawRobotTorso(GLfloat radius,GLfloat height, GLfloat posX, GLfloat posY, GLfloat posZ);
    void drawRobotArms(GLfloat radius, GLfloat length, GLfloat armsDistance, GLfloat posX, GLfloat posY, GLfloat posZ);
    void laserPower(GLfloat posX, GLfloat posY, GLfloat posZ);
    /*void moveLeft();
    void moveRight();
    void moveFront();
    void moveBack();*/
    void RotateYaw(float angle);
    void RotatePitch(float angle);
    void Move(float incr);
    void Strafe(float incr);
    
private:
    GLfloat posX;
    GLfloat posY;
    GLfloat posZ;
    GLfloat torsoRadius;
    Camera * cam;
    float m_x, m_y, m_z;   // Position
    float m_lx, m_ly, m_lz; // Direction vector of where we are looking at
    float m_yaw, m_pitch; // Various rotation angles
    float m_strafe_lx, m_strafe_lz; // Always 90 degree to direction vector
    
};

inline Robot::~Robot()
{
}
#endif // ROBOT_H



