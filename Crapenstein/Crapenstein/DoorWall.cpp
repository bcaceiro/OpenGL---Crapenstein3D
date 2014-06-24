//
//  DoorWall.cpp
//  Crapenstein
//
//  Created by Bruno Caceiro on 24/06/14.
//  Copyright (c) 2014 Bruno Caceiro. All rights reserved.
//

#include "DoorWall.h"

#include <stdio.h>
#include "OpenGLIncludes.h"

extern GLuint texture[4];
//constructor
DoorWall::DoorWall(float x,float y,float z,float width,float height,int orientation){
    //fazer cenas, dá jeito!
    //printf("\nCenas= %d\n",cenas);
    this->x = x;
    this->y = y;
    this->z = z;
    this->width = width;
    this->height = height;
    this->orientation = orientation;
    canOpenDoor = false;
    isOpen = false;
    
    aux = 0.1;
    
    
  }
void DoorWall::draw(){
    //printf("merda\n\n");
    //caso seja chao

    //caso seja parede alinhada no x
    /*
    if(orientation==1) {
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
     */
    //caso seja parede alinhada em z
    /*
    if(orientation==2){
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
     */
    
    
    // LEFT SIDE
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,texture[3]);
    glPushMatrix();
    glBegin(GL_QUADS);
    glTexCoord2f(0.0f,0.0f);   glVertex3i( x,  y,         z);
    glTexCoord2f(10.0f,0.0f);  glVertex3i( x,  y,         z+width/2 - 10);
    glTexCoord2f(10.0f,10.0f); glVertex3i( x,  y+height,  z+width/2 - 10);
    glTexCoord2f(0.0f,10.0f);  glVertex3i( x,  y+height,  z);
    glEnd();
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);
    
    
    //RIGHT SIDE
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,texture[3]);
    glPushMatrix();
    glBegin(GL_QUADS);
    glTexCoord2f(0.0f,0.0f);   glVertex3i( x,  y,         z+width/2+10);
    glTexCoord2f(10.0f,0.0f);  glVertex3i( x,  y,         z+width);
    glTexCoord2f(10.0f,10.0f); glVertex3i( x,  y+height,  z+width);
    glTexCoord2f(0.0f,10.0f);  glVertex3i( x,  y+height,  z+width/2+10);
    glEnd();
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);
    
    if(!canOpenDoor) {
        //LEFT DOOR
        glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D,texture[1]);
        glPushMatrix();
        glBegin(GL_QUADS);
        glTexCoord2f(0.0f,0.0f);   glVertex3i( x,  y,         z+width/2-10);
        glTexCoord2f(10.0f,0.0f);  glVertex3i( x,  y,         z+width/2);
        glTexCoord2f(10.0f,10.0f); glVertex3i( x,  y+height,  z+width/2);
        glTexCoord2f(0.0f,10.0f);  glVertex3i( x,  y+height,  z+width/2-10);
        glEnd();
        glPopMatrix();
    glDisable(GL_TEXTURE_2D);
    
    //RIGHT DOOR
    
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,texture[1]);
    glPushMatrix();
    glBegin(GL_QUADS);
    glTexCoord2f(0.0f,0.0f);   glVertex3i( x,  y,         z+width/2+10);
    glTexCoord2f(10.0f,0.0f);  glVertex3i( x,  y,         z+width/2);
    glTexCoord2f(10.0f,10.0f); glVertex3i( x,  y+height,  z+width/2);
    glTexCoord2f(0.0f,10.0f);  glVertex3i( x,  y+height,  z+width/2+10);
    glEnd();
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);
    }
    
    if(canOpenDoor) {
        if(!isOpen) {
        aux +=0.1;
        if(z+width/2-10-aux > z ) {
        //LEFT DOOR
        glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D,texture[1]);
        glPushMatrix();
        glBegin(GL_QUADS);
        glTexCoord2f(0.0f,0.0f);   glVertex3i( x,  y,         z+width/2-10-aux);
        glTexCoord2f(10.0f,0.0f);  glVertex3i( x,  y,         z+width/2-aux);
        glTexCoord2f(10.0f,10.0f); glVertex3i( x,  y+height,  z+width/2-aux);
        glTexCoord2f(0.0f,10.0f);  glVertex3i( x,  y+height,  z+width/2-10-aux);
        glEnd();
        glPopMatrix();
        glDisable(GL_TEXTURE_2D);
            
            
            
            glEnable(GL_TEXTURE_2D);
            glBindTexture(GL_TEXTURE_2D,texture[1]);
            glPushMatrix();
            glBegin(GL_QUADS);
            glTexCoord2f(0.0f,0.0f);   glVertex3i( x,  y,         z+width/2+10+aux);
            glTexCoord2f(10.0f,0.0f);  glVertex3i( x,  y,         z+width/2+aux);
            glTexCoord2f(10.0f,10.0f); glVertex3i( x,  y+height,  z+width/2+aux);
            glTexCoord2f(0.0f,10.0f);  glVertex3i( x,  y+height,  z+width/2+10+aux);
            glEnd();
            glPopMatrix();
            glDisable(GL_TEXTURE_2D);
    
            
            
        
        }
        else
            isOpen = true;
        }
        
        
    }
    

    
    
}

void DoorWall::openDoor(){
    canOpenDoor = true;
}



