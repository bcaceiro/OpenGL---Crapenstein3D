
#ifndef __WALL__
#define __WALL__

#include <stdio.h>
#include "Wall.h"
#include "OpenGLIncludes.h"

//constructor
Wall::Wall(float x,float y,float z,float width,float height,int orientation){

    this->x = x;
    this->y = y;
    this->z = z;
    this->width = width;
    this->height = height;
    this->orientation = orientation;
    if(orientation==0)
        setBounds(x,y,z,width,0.2,height);
    else if(orientation==1)
        setBounds(x-0.2,y,z-0.2,width,height,0.4);
    else if(orientation==2)
        setBounds(x,y,z,0.2,height,width);
}
void Wall::draw() {

    //caso seja chao
    glColor4f(1.0,1.0,1.0,1.0);
    if(orientation==0){
        glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D,texture[1]);
        glPushMatrix();
            glBegin(GL_QUADS);
                    glTexCoord2f(0.0f,0.0f);   glVertex3i( x,        y,  z       );
                    glTexCoord2f(10.0f,0.0f);  glVertex3i( x+width,  y,  z       );
                    glTexCoord2f(10.0f,10.0f); glVertex3i( x+width,  y,  z+height);
                    glTexCoord2f(0.0f,10.0f);  glVertex3i( x,        y,  z+height);
            glEnd();
        glPopMatrix();
        glDisable(GL_TEXTURE_2D);
    }
    //caso seja parede alinhada no x
    else if(orientation==1){
        glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D,texture[2]);
        glPushMatrix();
            glBegin(GL_QUADS);
                    glTexCoord2f(0.0f,0.0f);   glVertex3i( x,        y,         z);
                    glTexCoord2f(10.0f,0.0f);  glVertex3i( x+width,  y,         z);
                    glTexCoord2f(10.0f,1.0f); glVertex3i( x+width,  y+height,  z);
                    glTexCoord2f(0.0f,1.0f);  glVertex3i( x,        y+height,  z);
            glEnd();
        glPopMatrix();
        glDisable(GL_TEXTURE_2D);
    //printf("acabou a merda\n");
    }
    //caso seja parede alinhada em z
    else if(orientation==2){
        glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D,texture[3]);
        glPushMatrix();
            glBegin(GL_QUADS);
                    glTexCoord2f(0.0f,0.0f);   glVertex3i( x,  y,         z);
                    glTexCoord2f(10.0f,0.0f);  glVertex3i( x,  y,         z+width);
                    glTexCoord2f(10.0f,10.0f); glVertex3i( x,  y+height,  z+width);
                    glTexCoord2f(0.0f,10.0f);  glVertex3i( x,  y+height,  z);
            glEnd();
        glPopMatrix();
        glDisable(GL_TEXTURE_2D);
    //printf("acabou a merda\n");
    }
}

bool Wall::isColliding(CollidingObject* obj){

    if(this->orientation!=0)
        //printf("CollisionTestX(%f,%f,%f,%f)\n",this->collide_minX,obj->collide_maxX,this->collide_maxX,obj->collide_minX);
    if(this->collide_minX < obj->collide_maxX && this->collide_maxX > obj->collide_minX){
        if(this->orientation!=0)
            //printf("CollisionTestY((%f,%f,%f,%f)\n",this->collide_minY,obj->collide_maxY,this->collide_maxY,obj->collide_minY);
        if(this->collide_minY < obj->collide_maxY && this->collide_maxY > obj->collide_minY){
            if(this->orientation!=0)
                //printf("CollisionTestZ((%f,%f,%f,%f)\n",this->collide_minZ,obj->collide_maxZ,this->collide_maxZ,obj->collide_minZ);
            if(this->collide_minZ < obj->collide_maxZ && this->collide_maxZ > obj->collide_minZ){
                printf("Colliding(%d)...\n",orientation);
                return true;
            }
        }
    }
    //printf("Not Colliding...\n");
    return false;
}


#endif
