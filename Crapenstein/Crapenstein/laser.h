#ifndef LASER_H
#define LASER_H
#include "collidingObject.h"
#include "OpenGLIncludes.h"
#include <vector>

using namespace std;
extern vector<CollidingObject*> collidableObjects;
class Laser : public CollidingObject
{
public:
    Laser(GLfloat x,GLfloat y,GLfloat z,GLfloat dx,GLfloat dy,GLfloat dz,GLfloat m_yaw,GLfloat m_pitch,GLenum number);
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
    GLenum lightNumber;
    bool isColliding();
};

#endif // LASER_H
