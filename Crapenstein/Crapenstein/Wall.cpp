
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
    /*if(orientation==0)
        setBounds(x,y,z,width,0.2,height);
    else*/
    if(orientation==1)
        setBounds(x,y,z,width,height,0.2);
    else if(orientation==2)
        setBounds(x,y,z,0.1,height,width);
}
void Wall::draw() {
    float aux =  width/10;
    float aux2 = height/10;
    //caso seja chao
    glColor4f(1.0,1.0,1.0,1.0);
    if(orientation==0){
        glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D,texture[1]);
        glPushMatrix();
            glNormal3f(0.0f, 1.0f, 0.0f);
            for(int i=0;i<10;++i){
                for(int j=0;j<10;++j){
                    glBegin(GL_QUADS);
                            glTexCoord2f(0.0f,0.0f);  glVertex3f( x+(i*aux),        y,  z+(j*aux2));
                            glTexCoord2f(1.0f,0.0f);  glVertex3f( x+((i+1)*aux),    y,  z+(j*aux2));
                            glTexCoord2f(1.0f,1.0f);  glVertex3f( x+((i+1)*aux),    y,  z+((j+1)*aux2));
                            glTexCoord2f(0.0f,1.0f);  glVertex3f( x+(i*aux),        y,  z+((j+1)*aux2));
                    glEnd();
                }
            }
        glPopMatrix();
        glDisable(GL_TEXTURE_2D);
    }
    //caso seja parede alinhada no x
    else if(orientation==1){
        glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D,texture[2]);
        glPushMatrix();
            glBegin(GL_QUADS);
                    glNormal3f(0.0f, 1.0f, 0.0f);
                    for(int i=0;i<10;++i){
                        for(int j=0;j<10;++j){
                            glBegin(GL_QUADS);
                                    glTexCoord2f(0.0f,0.0f);  glVertex3f( x+(i*aux),        y+(j*aux2),      z+0.1);
                                    glTexCoord2f(1.0f,0.0f);  glVertex3f( x+((i+1)*aux),    y+(j*aux2),      z+0.1);
                                    glTexCoord2f(1.0f,1.0f);  glVertex3f( x+((i+1)*aux),    y+((j+1)*aux2),  z+0.1);
                                    glTexCoord2f(0.0f,1.0f);  glVertex3f( x+(i*aux),        y+((j+1)*aux2),  z+0.1);
                            glEnd();
                        }
                    }
            glEnd();
            glBegin(GL_QUADS);
                    glNormal3f(0.0f, 1.0f, 0.0f);
                    for(int i=0;i<10;++i){
                        for(int j=0;j<10;++j){
                            glBegin(GL_QUADS);
                                    glTexCoord2f(0.0f,0.0f);  glVertex3f( x+(i*aux),        y+(j*aux2),      z-0.1);
                                    glTexCoord2f(1.0f,0.0f);  glVertex3f( x+((i+1)*aux),    y+(j*aux2),      z-0.1);
                                    glTexCoord2f(1.0f,1.0f);  glVertex3f( x+((i+1)*aux),    y+((j+1)*aux2),  z-0.1);
                                    glTexCoord2f(0.0f,1.0f);  glVertex3f( x+(i*aux),        y+((j+1)*aux2),  z-0.1);
                            glEnd();
                        }
                    }
            glEnd();
        glPopMatrix();
        glDisable(GL_TEXTURE_2D);


        glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D,texture[3]);
        glPushMatrix();
            glBegin(GL_QUADS);
                    glNormal3f(0.0f, 1.0f, 0.0f);
                    for(int i=0;i<10;++i){
                            glBegin(GL_QUADS);
                                    glTexCoord2f(0.0f,0.0f);  glVertex3f( x+(i*aux),        y+height,  z-0.1);
                                    glTexCoord2f(1.0f,0.0f);  glVertex3f( x+((i+1)*aux),    y+height,  z-0.1);
                                    glTexCoord2f(1.0f,1.0f);  glVertex3f( x+((i+1)*aux),    y+height,  z+0.1);
                                    glTexCoord2f(0.0f,1.0f);  glVertex3f( x+(i*aux),        y+height,  z+0.1);
                            glEnd();
                    }
            glEnd();
        glPopMatrix();
        glDisable(GL_TEXTURE_2D);
    //printf("acabou a merda\n");
    }
    //caso seja parede alinhada em z
    else if(orientation==2){
        glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D,texture[2]);
        glPushMatrix();
            glBegin(GL_QUADS);
                    glNormal3f(0.0f, 1.0f, 0.0f);
                    for(int i=0;i<10;++i){
                        for(int j=0;j<10;++j){
                            glBegin(GL_QUADS);
                                    glTexCoord2f(0.0f,0.0f);  glVertex3f(x-0.1, y+(i*aux2),        z+(j*aux));
                                    glTexCoord2f(1.0f,0.0f);  glVertex3f(x-0.1, y+((i+1)*aux2),    z+(j*aux));
                                    glTexCoord2f(1.0f,1.0f);  glVertex3f(x-0.1, y+((i+1)*aux2),    z+((j+1)*aux));
                                    glTexCoord2f(0.0f,1.0f);  glVertex3f(x-0.1, y+(i*aux2),        z+((j+1)*aux));
                            glEnd();
                        }
                    }
                    for(int i=0;i<10;++i){
                        for(int j=0;j<10;++j){
                            glBegin(GL_QUADS);
                                    glTexCoord2f(0.0f,0.0f);  glVertex3f(x+0.1, y+(i*aux2),        z+(j*aux));
                                    glTexCoord2f(1.0f,0.0f);  glVertex3f(x+0.1, y+((i+1)*aux2),    z+(j*aux));
                                    glTexCoord2f(1.0f,1.0f);  glVertex3f(x+0.1, y+((i+1)*aux2),    z+((j+1)*aux));
                                    glTexCoord2f(0.0f,1.0f);  glVertex3f(x+0.1, y+(i*aux2),        z+((j+1)*aux));
                            glEnd();
                        }
                    }
            glEnd();
        glPopMatrix();
        glDisable(GL_TEXTURE_2D);
        glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D,texture[3]);
        glPushMatrix();
            glBegin(GL_QUADS);
                    glNormal3f(0.0f, 1.0f, 0.0f);
                    for(int i=0;i<10;++i){
                            glBegin(GL_QUADS);
                            glTexCoord2f(0.0f,0.0f);  glVertex3f( x-0.1,    y+height,  z+(i*aux));
                            glTexCoord2f(1.0f,0.0f);  glVertex3f( x-0.1,    y+height,  z+((i+1)*aux));
                            glTexCoord2f(1.0f,1.0f);  glVertex3f( x+0.1,    y+height,  z+((i+1)*aux));
                            glTexCoord2f(0.0f,1.0f);  glVertex3f( x+0.1,    y+height,  z+(i*aux));
                            glEnd();
                    }
            glEnd();
        glPopMatrix();
        glDisable(GL_TEXTURE_2D);
    //printf("acabou a merda\n");
    }
}

bool Wall::isColliding(CollidingObject* obj){

    printf("Cenas(%d)\n",orientation);
    if(this->collide_minX < obj->collide_maxX && this->collide_maxX > obj->collide_minX){
        if(this->collide_minY < obj->collide_maxY && this->collide_maxY > obj->collide_minY){
           if(this->collide_minZ < obj->collide_maxZ && this->collide_maxZ > obj->collide_minZ){
               return true;
            }
        }
    }
    //printf("Not Colliding...\n");
    return false;
}


#endif
