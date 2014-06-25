#ifndef TORCH_H
#define TORCH_H
#include "collidingObject.h"
#include "OpenGLIncludes.h"

class Torch : public CollidingObject
{
public:
    Torch(GLenum number,GLfloat x, GLfloat y, GLfloat z);
    GLenum lightNumber;
    GLfloat x,y,z;
    void draw();
    //void isColliding(float& x,float& y, float& z);
};

#endif // TORCH_H
