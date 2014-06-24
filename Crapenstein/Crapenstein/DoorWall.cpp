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

//Constructor
DoorWall::DoorWall(float x,float y,float z,float width,float height,int orientation){


    this->x = x;
    this->y = y;
    this->z = z;
    this->width = width;
    this->height = height;
    this->orientation = orientation;
    canOpenDoor = false;
    isOpen = false;
    doorState = 0;
    aux = 0;
    
    
  }
void DoorWall::updateWalls() {

    //caso seja parede alinhada no x

    if(orientation == 1) {
        glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D,texture[2]);
        glPushMatrix();
            glBegin(GL_QUADS);
                glTexCoord2f(0.0f,0.0f);   glVertex3i( x,        y,         z);
                glTexCoord2f(10.0f,0.0f);  glVertex3i( x+width/2-10,  y,         z);
                glTexCoord2f(10.0f,1.0f); glVertex3i( x+width/2-10,  y+height,  z);
                glTexCoord2f(0.0f,1.0f);  glVertex3i( x,        y+height,  z);
            glEnd();
        glPopMatrix();
        glDisable(GL_TEXTURE_2D);
        
        glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D,texture[2]);
        glPushMatrix();
            glBegin(GL_QUADS);
                glTexCoord2f(0.0f,0.0f);   glVertex3i( x+width / 2 + 10,        y,         z);
                glTexCoord2f(10.0f,0.0f);  glVertex3i( x + width,  y,         z);
                glTexCoord2f(10.0f,1.0f); glVertex3i( x+width,  y+height,  z);
                glTexCoord2f(0.0f,1.0f);  glVertex3i( x +width/2 + 10,        y+height,  z);
            glEnd();
        glPopMatrix();
        glDisable(GL_TEXTURE_2D);
        //printf("acabou a merda\n");
    }

    
    if(orientation == 2) {
        // Left Side Wall
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
    
        //Right Side Wall
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
    }
    
   }




void DoorWall:: updateDoors() {

    if( doorState == 0)
        aux = 0;
    
    //Open Door
    else if (doorState == 1) {
        if(z + width / 2 - 10 - aux > z )
            aux+=0.3;
    }
    
    // Close the Door
    else if (doorState == 2) {
        
        if(z + width / 2 - 10 - aux < z + width / 2 -10 )
            aux-=0.3;

        if(z + width / 2 - 10 - aux == z + width / 2 - 10 )
            doorState = 0;
    }
    
    if(orientation == 1) {
        // Left Door
        glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D,texture[0]);
        glPushMatrix();
            glBegin(GL_QUADS);
                glTexCoord2f(0.0f,0.0f);  glVertex3i( x + width/2-10-aux ,  y,         z);
                glTexCoord2f(1.0f,0.0f);  glVertex3i( x + width/2-aux,  y,         z);
                glTexCoord2f(1.0f,1.0f);  glVertex3i( x + width/2-aux,  y+height,  z);
                glTexCoord2f(0.0f,1.0f);  glVertex3i( x+width/2-10-aux,  y+height,  z);
            glEnd();
            glPopMatrix();
        glDisable(GL_TEXTURE_2D);
        
        
        // Right Door
        glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D,texture[0]);
        glPushMatrix();
            glBegin(GL_QUADS);
                glTexCoord2f(0.0f,0.0f);  glVertex3i( x +width/2+10+aux,  y,         z);
                glTexCoord2f(1.0f,0.0f);  glVertex3i( x +width/2+aux,  y,         z);
                glTexCoord2f(1.0f,1.0f);  glVertex3i( x +width/2+aux,  y+height,  z);
                glTexCoord2f(0.0f,1.0f);  glVertex3i( x+width/2+10+aux,  y+height,  z);
            glEnd();
        glPopMatrix();
        glDisable(GL_TEXTURE_2D);
    }
    
    

    if(orientation == 2) {
    // Left Door
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,texture[0]);
    glPushMatrix();
        glBegin(GL_QUADS);
            glTexCoord2f(0.0f,0.0f);  glVertex3i( x,  y,          z + width / 2 - 10 - aux);
            glTexCoord2f(1.0f,0.0f);  glVertex3i( x,  y,          z + width / 2 - aux);
            glTexCoord2f(1.0f,1.0f);  glVertex3i( x,  y + height, z + width / 2 - aux);
            glTexCoord2f(0.0f,1.0f);  glVertex3i( x,  y + height, z + width / 2 - 10 - aux);
        glEnd();
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);
    
    
    // Right Door
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,texture[0]);
    glPushMatrix();
        glBegin(GL_QUADS);
            glTexCoord2f(0.0f,0.0f);   glVertex3i( x,  y,         z+width/2+10+aux);
            glTexCoord2f(1.0f,0.0f);  glVertex3i( x,  y,         z+width/2+aux);
            glTexCoord2f(1.0f,1.0f); glVertex3i( x,  y+height,  z+width/2+aux);
            glTexCoord2f(0.0f,1.0f);  glVertex3i( x,  y+height,  z+width/2+10+aux);
        glEnd();
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);
    }
    
    
}

void DoorWall::update() {
    
    updateWalls();
    updateDoors();
    
    
}

void DoorWall::openDoor() {

    if(doorState == 1) {
        doorState = 2;
    }
    else if(doorState == 0) {
        doorState = 1;
        aux = 0.3;
    }

}



