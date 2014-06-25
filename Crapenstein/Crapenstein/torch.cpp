#include "torch.h"
#include <stdio.h>

Torch::Torch(GLenum number,GLfloat x, GLfloat y, GLfloat z)
{
    this->lightNumber = number;
    this->x = x;
    this->y = y;
    this->z = z;
}
void Torch::draw(){
    glEnable(lightNumber);
    GLfloat lightPos[4] = {x, y, z, 1.0};

    glLightfv(lightNumber,GL_POSITION, lightPos);
    GLfloat lightColor[4] = {0,255,0,1};
    glLightfv(lightNumber,GL_DIFFUSE, lightColor);
    glLightfv(lightNumber,GL_SPECULAR, lightColor);

    glLightf(lightNumber,GL_CONSTANT_ATTENUATION,	1);
    glLightf(lightNumber,GL_LINEAR_ATTENUATION,		0.5);
    glLightf(lightNumber,GL_QUADRATIC_ATTENUATION,	0.5);
}

/*void Torch::isColliding(float& x,float& y, float& z){
    printf("FDS, que boss!!!!...\n");
}*/
