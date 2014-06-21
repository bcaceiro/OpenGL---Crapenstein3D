
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
}
void Wall::draw(){
    //printf("merda\n\n");
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
    else if(orientation==1){
        glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D,texture[2]);
        glPushMatrix();
            glBegin(GL_QUADS);
                    glTexCoord2f(0.0f,0.0f);   glVertex3i( x,        y,         z);
                    glTexCoord2f(1.0f,0.0f);  glVertex3i( x+width,  y,         z);
                    glTexCoord2f(1.0f,1.0f); glVertex3i( x+width,  y+height,  z);
                    glTexCoord2f(0.0f,1.0f);  glVertex3i( x,        y+height,  z);
            glEnd();
        glPopMatrix();
        glDisable(GL_TEXTURE_2D);
    //printf("acabou a merda\n");
    }
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

#endif
