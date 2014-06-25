#include "laser.h"
#include <stdio.h>

Laser::Laser(GLfloat x,GLfloat y,GLfloat z,GLfloat dx,GLfloat dy,GLfloat dz,GLfloat m_yaw,GLfloat m_pitch,GLenum number)
{
    //printf("NEW LASER!!!(%f,%f,%f,%f,%f,%f)\n",x,y,z,dx,dy,dz);
    this->x = x;
    this->y = y;
    this->z = z;
    this->dx = dx;
    this->dy = dy;
    this->dz = dz;
    float aux;
    aux = m_yaw*180;
    aux = aux/M_PI;
    this->m_yaw = aux;
    aux = m_pitch*180;
    aux = aux/M_PI;
    this->m_pitch = aux;
    this->lightNumber = number;
    this->setBounds(x-0.7,y-1,z-0.7,2.5,2,2.5);


    //Props JN + JJAM
    int rng = rand() % 9;

    if(rng < 3)
    {
        lightColor[0] = 255;
        lightColor[1] = 0;
        lightColor[2] = 0;
        lightColor[3] = 1;
    }
    else if(rng >= 3 && rng < 6)
    {
        lightColor[0] = 0;
        lightColor[1] = 255;
        lightColor[2] = 0;
        lightColor[3] = 1;
    }
    else
    {
        lightColor[0] = 0;
        lightColor[1] = 0;
        lightColor[2] = 255;
        lightColor[3] = 1;
    }
    //printf("Cenas:(%f,%f)(%f,%f)\n",m_yaw,m_pitch,this->m_yaw,this->m_pitch);

}
void Laser::update(){
    this->x += this->dx;
    this->y += this->dy;
    this->z += this->dz;
    this->setBounds(x-0.7,y-1,z-0.7,2.5,2,2.5);
}
void Laser::draw(){

    glEnable(lightNumber);
    GLfloat lightPos[4] = {x,y,z,1};
    glLightfv(lightNumber,GL_POSITION, lightPos);

    glLightfv(lightNumber,GL_DIFFUSE, lightColor);
    glLightfv(lightNumber,GL_SPECULAR, lightColor);

    glLightf(lightNumber,GL_CONSTANT_ATTENUATION,	0);
    glLightf(lightNumber,GL_LINEAR_ATTENUATION,		10);
    glLightf(lightNumber,GL_QUADRATIC_ATTENUATION,	0);

    glPushMatrix();
        glTranslatef(x,y,z);
        glRotatef(-m_yaw,0,1,0);
        glRotatef(m_pitch,0,0,1);
        glutSolidTeapot(1);
    glPopMatrix();

}
bool Laser::isColliding()
{
    if(this->y<0)
        return true;
    if(this->y>20)
        return true;

    unsigned int vector_size = collidableObjects.size();
    for(unsigned int i = 0; i < vector_size; ++i){
        if(((CollidingObject*)collidableObjects[i])->isColliding(this)){
            return true;
        }
    }
    //FIXME finnish this shit

    return false;

}

