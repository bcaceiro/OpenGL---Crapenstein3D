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
    
    if(orientation == 1)
        setBounds(x-0.5,y,z-0.5,width,height,2.5);
    else if(orientation==2)
        setBounds(x,y,z,1.0,height,width);
    
    
    playerColliding = false;
    
    
  }
void DoorWall::updateWalls() {

    // X oriented Wall

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

    }

    // Z oriented Wall
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
    //Door Still
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
    if(playerColliding) {

        if(doorState == 1) {
            doorState = 2;
        }
        else if(doorState == 0) {
            doorState = 1;
            aux = 0.3;
        }
    }
}


bool DoorWall::isColliding(CollidingObject* obj) {

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
                playerColliding = true;
                if(doorState == 1 || doorState == 2)
                    return false;
                return true;
            }
        }
    }
    //printf("Not Colliding...\n");
    return false;
}







