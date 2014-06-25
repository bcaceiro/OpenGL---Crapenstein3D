#ifndef LASER_H
#define LASER_H
#include "collidingObject.h"
#include "OpenGLIncludes.h"
class Laser : public CollidingObject
{
public:
    Laser(GLfloat x,GLfloat y,GLfloat z,GLfloat dx,GLfloat dy,GLfloat dz,GLfloat m_yaw,GLfloat m_pitch);
    void update();
    void draw();
    GLfloat dx;
    GLfloat dy;
    GLfloat dz;
    GLfloat x;
    GLfloat y;
    GLfloat z;
    GLfloat m_yaw;
    GLfloat m_pitch;
    bool isColliding();
};

#endif // LASER_H
