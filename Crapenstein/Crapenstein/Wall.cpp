
#ifndef __WALL__
#define __WALL__

#include <stdio.h>
#include "Wall.h"
#include "OpenGLIncludes.h"

extern GLuint texture[4];
//constructor
Wall::Wall(float x,float y,float z,float width,float height,int orientation){
    //fazer cenas, dá jeito!
    //printf("\nCenas= %d\n",cenas);
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
void Wall::draw(){
    //printf("merda\n\n");
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
    //chão
    //não testar nada
    /*if(orientation==0)
        return false;
    //parede orientada em x
    //testar apenas z e caso passe, testar x;
    else if(orientation==1){
        if( z >= this->collide_minZ && z <= this->collide_maxZ){
            printf("X=%f\nZ=%f\nY=%f\n",x,z,y);
            printf("MINX(%f)\nMAXX(%f)\n",this->collide_minX,this->collide_maxX);
            printf("MINZ(%f)\nMAXZ(%f)\n",this->collide_minZ,this->collide_maxZ);
            if( x >= this->collide_minX && x <= this->collide_maxX){
                return true;
            }
        }
        */
        /*if( ){
            printf("X=%f\nZ=%f\n",x,z);
            if( z > this->collide_minZ && z < this->collide_maxZ){
                printf("MINZ(%f)\nMAXZ(%f)\n",this->collide_minZ,this->collide_maxZ);
                printf("MAXX(%f)!!\n",this->collide_maxX);
                x = this->collide_maxX-0.3;
            }
        }*/
    //}
    //parede orientada em z
    //testar apenas z, e caso passe, testar x
    /*else if(orientation==2)
        return false;

    return false;
*/
    /*printf("X=%f\n",x);
    if( x < this->collide_minX){
        printf("MINX(%f)!!\n",this->collide_minX);
        x = this->collide_minX+0.2;
    }
    if(x > this->collide_maxX ){
        printf("MAXX(%f)!!\n",this->collide_maxX);
        x = this->collide_maxX-0.2;
    }*/
    /*if(m_z<0.1)
        m_z = 0.2;
    if(m_z+0.1>MAP_HEIGHT)
        m_z = MAP_HEIGHT-0.2;*/
    if(this->orientation!=0)
        printf("CollisionTestX(%f,%f,%f,%f)\n",this->collide_minX,obj->collide_maxX,this->collide_maxX,obj->collide_minX);
    if(this->collide_minX < obj->collide_maxX && this->collide_maxX > obj->collide_minX){
        if(this->orientation!=0)
            printf("CollisionTestY((%f,%f,%f,%f)\n",this->collide_minY,obj->collide_maxY,this->collide_maxY,obj->collide_minY);
        if(this->collide_minY < obj->collide_maxY && this->collide_maxY > obj->collide_minY){
            if(this->orientation!=0)
                printf("CollisionTestZ((%f,%f,%f,%f)\n",this->collide_minZ,obj->collide_maxZ,this->collide_maxZ,obj->collide_minZ);
            if(this->collide_minZ < obj->collide_maxZ && this->collide_maxZ > obj->collide_minZ){
                printf("Colliding(%d)...\n",orientation);
                return true;
            }
        }
    }
    printf("Not Colliding...\n");
    return false;
}


#endif
