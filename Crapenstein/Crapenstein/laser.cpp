#include "laser.h"
#include <stdio.h>

Laser::Laser(GLfloat x,GLfloat y,GLfloat z,GLfloat dx,GLfloat dy,GLfloat dz,GLfloat m_yaw,GLfloat m_pitch)
{
    printf("NEW LASER!!!(%f,%f,%f,%f,%f,%f)\n",x,y,z,dx,dy,dz);
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
    printf("Cenas:(%f,%f)(%f,%f)\n",m_yaw,m_pitch,this->m_yaw,this->m_pitch);

}
void Laser::update(){
    this->x += this->dx;
    this->y += this->dy;
    this->z += this->dz;
}
void Laser::draw(){
    glPushMatrix();
        glTranslatef(x,y,z);
        glRotatef(-m_yaw,0,1,0);
        glRotatef(m_pitch,0,0,1);
        glutSolidTeapot(1);
    glPopMatrix();
}

bool Laser::isColliding()
{
    if(this->x<0)
        return true;
    if(this->y<0)
        return true;
    if(this->y>20)
        return true;

    //FIXME finnish this shit

    return false;

}

