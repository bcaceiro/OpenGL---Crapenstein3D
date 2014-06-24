#include <stdio.h>
#include <cmath>
#include "OpenGLIncludes.h"
#include "Camera.h"
#include "mapLimits.h"
#include <vector>
#include "collidingObject.h"

const float limit = 89.0 * M_PI / 180.0;

/*fixme*/
using namespace std;
extern vector<CollidingObject*> collidableObjects;


void Camera::Init()
{
    m_yaw = 0.0;
    m_pitch = 0.0;
    SetPos(15, 8, 15);
}

void Camera::Refresh()
{
    // Camera parameter according to Riegl's co-ordinate system
    // x/y for flat, z for height
    m_lx = cos(m_yaw) * cos(m_pitch);
    m_ly = sin(m_pitch);
    m_lz = sin(m_yaw) * cos(m_pitch);

    m_strafe_lx = cos(m_yaw - M_PI_2);
    m_strafe_lz = sin(m_yaw - M_PI_2);



    /*unsigned int vector_size = collidableObjects.size();
    for(unsigned int i = 0; i < vector_size; ++i){
        ((CollidingObject*)collidableObjects[i])->isColliding(m_x,m_y,m_z);
    }*/

    /*if(m_x<0.1)
        m_x = 0.2;
    if(m_x+0.1>MAP_WIDTH)
        m_x = MAP_WIDTH-0.2;
    if(m_z<0.1)
        m_z = 0.2;
    if(m_z+0.1>MAP_HEIGHT)
        m_z = MAP_HEIGHT-0.2;*/

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(m_x, m_y, m_z, m_x + m_lx, m_y + m_ly, m_z + m_lz, 0.0,1.0,0.0);

    //printf("Camera: %f %f %f Direction vector: %f %f %f\n", m_x, m_y, m_z, m_lx, m_ly, m_lz);
}

void Camera::SetPos(float x, float y, float z)
{
    m_x = x;
    m_y = y;
    m_z =z;
    Refresh();
}

void Camera::GetPos(float &x, float &y, float &z)
{
    x = m_x;
    y = m_y;
    z = m_z;
}

void Camera::GetDirectionVector(float &x, float &y, float &z)
{
    x = m_lx;
    y = m_ly;
    z = m_lz;
}

void Camera::Move(float incr)
{
    float lx = cos(m_yaw)*cos(m_pitch);
    float ly = sin(m_pitch);
    float lz = sin(m_yaw)*cos(m_pitch);

    m_x = m_x + incr*lx;
    //this line is comment because the player can't move the camera vertically?
    //m_y = m_y + incr*ly;
    unsigned int vector_size = collidableObjects.size();
    for(unsigned int i = 0; i < vector_size; ++i){
        if(((CollidingObject*)collidableObjects[i])->isColliding(m_x,m_y,m_z)==true){
            m_x = m_x - incr*lx;
            break;
        }
    }
    m_z = m_z + incr*lz;
    for(unsigned int i = 0; i < vector_size; ++i){
        if(((CollidingObject*)collidableObjects[i])->isColliding(m_x,m_y,m_z)){
            m_z = m_z - incr*lx;
            break;
        }
    }
    Refresh();
}

void Camera::Strafe(float incr)
{
    m_x = m_x + incr*m_strafe_lx;
    unsigned int vector_size = collidableObjects.size();
    for(unsigned int i = 0; i < vector_size; ++i){
        if(((CollidingObject*)collidableObjects[i])->isColliding(m_x,m_y,m_z)){
            m_x = m_x - incr*m_strafe_lx;
            break;
        }
    }
    m_z = m_z + incr*m_strafe_lz;
    for(unsigned int i = 0; i < vector_size; ++i){
        if(((CollidingObject*)collidableObjects[i])->isColliding(m_x,m_y,m_z)){
             m_z = m_z - incr*m_strafe_lz;
            break;
        }
    }

    Refresh();
}

void Camera::Fly(float incr)
{
    m_y = m_y + incr;

    Refresh();
}

void Camera::RotateYaw(float angle)
{
    m_yaw += angle;

    Refresh();
}

void Camera::RotatePitch(float angle)
{
    m_pitch += angle;

    if(m_pitch < -limit)
        m_pitch = -limit;

    if(m_pitch > limit)
        m_pitch = limit;

    Refresh();
}

void Camera::SetYaw(float angle)
{
    m_yaw = angle;

    Refresh();
}

void Camera::SetPitch(float angle)
{
    m_pitch = angle;

    Refresh();
}
